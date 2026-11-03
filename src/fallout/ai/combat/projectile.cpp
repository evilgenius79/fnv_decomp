// fallout/ai/combat/projectile.cpp: Projectile, BGSProjectile, Holder, PlayerCharacter and more (71 functions)

#include "projectile_decls.h"

// @fnv 0x0094df60
bool PlayerCharacter::IsSleepingOrResting()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x654) > 0)
        return true;
    return false;
}

// Loads the projectile from a TESFile by delegating to the TESObjectREFR load proxy and returns the result.
// @fnv 0x009bd830
bool Projectile::Load(TESFile* file)
{
    bool result = reinterpret_cast<TESObjectREFR_LoadProxy*>(this)->Load(file);
    return result;
}

// Returns true if the projectile's proximity trigger fires or the base Projectile check returns true.
// @fnv 0x009b4d40
bool FlameProjectile::IsProximityDetonationTriggered()
{
    typedef bool(__thiscall * IsProximityTriggeredFn)(FlameProjectile*);
    return ((IsProximityTriggeredFn)(*reinterpret_cast<void***>(this))[198])(this) ||
           reinterpret_cast<Projectile*>(this)->Projectile::IsProximityDetonationTriggered();
}

// @fnv 0x009bbc70
Projectile::Projectile(bool) : visualA(0), visualB(0), cause(0)
{
    word68 = 0;
    wordC8 = 0;
    floatCC = 1.0f;
    floatD0 = 1.0f;
    floatD4 = 0.0f;
    floatD8 = 0.0f;
    floatDC = 0.0f;
    floatE0 = 1.0f;
    float110 = 0.0f;
    floatEC = 0.0f;
    floatF0 = 0.0f;
    *reinterpret_cast<NiPoint3*>(&position) = NiPoint3::ZERO;
    wordF8 = 0;
    wordFC = 0;
    word100 = 0;
    visualA = 0;
    visualB = 0;
    cause = 0;
    byte118 = 0;
    float124 = 0.0f;
    floatE4 = DAT_01016970;
    floatE8 = 0.0f;
    byte90 = 0;
    transform.ResetToIdentity();
    word140 = 0;
    word144 = 0;
    floatF4 = 1.0f;
    byte148 = 0;
    float14C = DAT_01022958;
    SetInitializationState(false);
}

struct FUN_00453700_shell : public Projectile
{
    float FUN_00453700();
};

// @fnv 0x00453700
float FUN_00453700_shell::FUN_00453700()
{
    return *(float*)((char*)this + 0xd0);
}

struct blob1
{
    char b[1];
};
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct FUN_009c1a70_shell : public WorldRayCastOutput
{
    WorldRayCastOutput* FUN_009c1a70(void*);
};

struct Dummy_009c1aa0
{
    void FUN_009c1aa0(void*);
};

// @fnv 0x009c1a70
WorldRayCastOutput* FUN_009c1a70_shell::FUN_009c1a70(void* apSource)
{
    reinterpret_cast<Dummy_009c1aa0*>(this)->FUN_009c1aa0(apSource);
    m_pRootCollidable = static_cast<WorldRayCastOutput*>(apSource)->m_pRootCollidable;
    return this;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Calls FUN_0083dec0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x009bc890
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_0080f7b0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiAVObject;
struct NiNode;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct PhysicsSimulationContext;
struct hkStatisticsCollector;
struct hkVector4;
struct CharacterProxyConfiguration;
struct Vector4Data;
struct hkpCharacterProxy;
struct hkpRigidBody;
struct CharacterPhysicsController;
struct blob1
{
    char b[1];
};
struct blob12
{
    char b[12];
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_0080f7b0_shell : public MobileObject
{
    void FUN_0080f7b0(bool);
};

// @fnv 0x0080f7b0
void FUN_0080f7b0_shell::FUN_0080f7b0(bool bVal)
{
    ((char*)this)[0x87] = (char)bVal;
}
}  // namespace fnv_0080f7b0

struct FUN_00978f10_shell
{
    void __thiscall FUN_0077eac0();
    void __thiscall FUN_00978f10();
};

// @fnv 0x00978f10
void __thiscall FUN_00978f10_shell::FUN_00978f10()
{
    FUN_0077eac0();
}

struct hkReferencedObject
{
    void removeReference();
};

struct FUN_009bb940
{
    char _pad[0x1c];
    hkReferencedObject* ref;
    ~FUN_009bb940();
};

// Releases the referenced object if present and clears the pointer.
// @fnv 0x009bb940
FUN_009bb940::~FUN_009bb940()
{
    if (this->ref)
        this->ref->removeReference();
    this->ref = 0;
}

struct FUN_009c19e0_shell
{
    int mFlags;
    bool __thiscall IsFlagSet();
};

// @fnv 0x009c19e0
bool __thiscall FUN_009c19e0_shell::IsFlagSet()
{
    return (mFlags & 0x4000) != 0;
}

struct hkVector4;
NiPoint3& __cdecl SetNiPoint3FromHkVector4(NiPoint3&, hkVector4 const&);
struct Proxy
{
    hkVector4 const& _ref_006815c0();
    NiPoint3& FUN_004585f0(NiPoint3&);
};
// @fnv 0x004585f0
NiPoint3& Proxy::FUN_004585f0(NiPoint3& aPoint)
{
    return SetNiPoint3FromHkVector4(aPoint, _ref_006815c0());
}

struct hkVector4;

NiPoint3& __cdecl SetNiPoint3FromHkVector4(NiPoint3&, hkVector4 const&);

struct FUN_004587f0_shell
{
    hkVector4& FUN_00458820();
    NiPoint3& FUN_004587f0(NiPoint3& a);
};

// @fnv 0x004587f0
NiPoint3& FUN_004587f0_shell::FUN_004587f0(NiPoint3& aPoint)
{
    return SetNiPoint3FromHkVector4(aPoint, FUN_00458820());
}

struct FUN_00458820_shell
{
    void FUN_00458840();
    void* FUN_00458820();
};

// @fnv 0x00458820
void* FUN_00458820_shell::FUN_00458820()
{
    FUN_00458840();
    return (void*)((char*)this + 0x10);
}

struct PathingRequest
{
    float GetTargetRadius();
    bool IsRandomBelowRadiusThreshold();
};

extern unsigned int DialogueRandom();
extern double g_d100;

// Computes a threshold from GetTargetRadius() times g_d100 and returns true if DialogueRandom() % 100 is below it.
// @fnv 0x004fdf60
bool PathingRequest::IsRandomBelowRadiusThreshold()
{
    unsigned int threshold = (unsigned int)(int)(GetTargetRadius() * g_d100);
    unsigned int random = DialogueRandom() % 100;
    if (random < threshold)
        return true;
    return false;
}

void __cdecl _Deallocate(void*);
struct DtorHelper
{
    void FUN_009bb940();
};
struct FUN_009b3490_shell
{
    void* FUN_009b3490(unsigned int);
};
// Runs the object's destructor helper, then frees the object when the low flag bit is set, and returns the object pointer.
// @fnv 0x009b3490
void* FUN_009b3490_shell::FUN_009b3490(unsigned int flags)
{
    ((DtorHelper*)this)->FUN_009bb940();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BGSProjectile
{
    bool GetFlag(unsigned int) const;
    bool FUN_009bc870();
};

// @fnv 0x009bc870
bool BGSProjectile::FUN_009bc870()
{
    return this->GetFlag(0x80);
}

namespace fnv_009c2e60 {
struct BGSProjectile
{
    bool GetFlag(unsigned int) const;
    bool IsFlag200Set() const;
};
// @fnv 0x009c2e60
bool BGSProjectile::IsFlag200Set() const
{
    return GetFlag(0x200);
}
}  // namespace fnv_009c2e60

struct ShadowSceneNode;
struct NiAVObject;
struct Flt
{
    operator unsigned int() const;
};
struct NP
{
    NP& operator=(void*);
};
struct ExtraDataList
{
    void Set3DObject(NiAVObject*);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct Holder
{
    char _pad[0x114];
    Flt m;
    void FUN_009c3e10();
};
// @fnv 0x009c3e10
void Holder::FUN_009c3e10()
{
    if ((unsigned int)m)
    {
        ((ExtraDataList*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
            ->Set3DObject((NiAVObject*)(unsigned int)m);
        ((NP*)&m)->operator=(0);
    }
}

namespace fnv_009c3e60 {
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
struct Flt
{
    operator unsigned int() const;
};
struct NiPointLight
{
    void FUN_0050dd20(float);
};
struct Holder
{
    char _a[0xE0];
    float f0;
    char _b[0x114 - 0xE0 - 4];
    Flt f1;
    bool FUN_00444d00(int);
    void FUN_009c3e60();
};
// @fnv 0x009c3e60
void Holder::FUN_009c3e60()
{
    if ((unsigned int)f1)
    {
        if (FUN_00444d00(0x20))
        {
            ((NiPointLight*)(unsigned int)f1)->FUN_0050dd20(FUN_00404010(0.0f, FUN_0040ebd0(1.0f, f0)));
        }
    }
}
}  // namespace fnv_009c3e60

struct ListNode9c
{
    bool _ref_008256d0();
    void* _ref_006815c0();
    ListNode9c* _ref_00726070();
};
struct Item9c
{
    void* item;
};
struct FUN_009c3ee0_shell
{
    Item9c* FindItemByKey(void* key);
};
// Walks the linked list starting at this+0x88 and returns the first record whose item equals key, or null.
// @fnv 0x009c3ee0
Item9c* FUN_009c3ee0_shell::FindItemByKey(void* key)
{
    Item9c* result = 0;
    ListNode9c* node = (ListNode9c*)((char*)this + 0x88);
    while (result == 0 && node != 0 && !node->_ref_008256d0())
    {
        Item9c* record = *(Item9c**)node->_ref_006815c0();
        node = node->_ref_00726070();
        if (record->item == key)
        {
            result = record;
        }
    }
    return result;
}

struct Setting_S
{
    float* __thiscall Float();
};
extern Setting_S originalRuntimeFloatSetting657;

// Returns (a * b + (1.0 - b) * *originalRuntimeFloatSetting657.Float()) * c, blending a with the runtime float setting and scaling by c.
// @fnv 0x009c3f50
float __cdecl BlendWithSetting(float afValue, float afBlend, float afScale)
{
    return (afValue * afBlend + (1.0 - afBlend) * *originalRuntimeFloatSetting657.Float()) * afScale;
}

struct NiPoint3Helper
{
    float GetLengthSquared();
    void ComputeMagnitude();
};
struct Dummy009c4e60
{
    void FUN_009c4e60(NiPoint3 a, bool b);
};
// Stores a NiPoint3 at offset 0x104; if b is set, adds the helper's value at 0x104 to the float at 0x110, otherwise calls the helper's other method.
// @fnv 0x009c4e60
void Dummy009c4e60::FUN_009c4e60(NiPoint3 a, bool b)
{
    *(NiPoint3*)((char*)this + 0x104) = a;
    if (b)
    {
        *(float*)((char*)this + 0x110) += ((NiPoint3Helper*)((char*)this + 0x104))->GetLengthSquared();
    }
    else
    {
        ((NiPoint3Helper*)((char*)this + 0x104))->ComputeMagnitude();
    }
}

struct SndX
{
    bool IsValid();
    void Stop();
    void PausePlayback();
};
struct FUN_009c4f90_This
{
    void StopSound();
};
// @fnv 0x009c4f90
void FUN_009c4f90_This::StopSound()
{
    if (reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x134)->IsValid())
    {
        reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x134)->Stop();
        if (reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x134)->IsValid())
            reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x134)->PausePlayback();
    }
}

struct S5870_Buf
{
    virtual unsigned char V0();
};
struct S5870_Impact
{
    void ValidateWorldObjectCount(S5870_Buf*);
};
struct S5870_Base
{
    void FUN_00932d60(S5870_Buf*);
};
struct S5870_List
{
    struct S5870_Impact** _ref_006815c0();
    S5870_List* _ref_00726070();
};
struct S5870_Holder
{
    void FUN_009c5870(S5870_Buf*);
};
// @fnv 0x009c5870
void S5870_Holder::FUN_009c5870(S5870_Buf* pBuffer)
{
    S5870_List* pCurrentElementNext;
    ((S5870_Base*)this)->FUN_00932d60(pBuffer);
    if (pBuffer->V0() >= 14)
    {
        pCurrentElementNext = (S5870_List*)((char*)this + 0x88);
        while (pCurrentElementNext)
        {
            S5870_Impact* pimpact;
            pimpact = *pCurrentElementNext->_ref_006815c0();
            if (pimpact)
                pimpact->ValidateWorldObjectCount(pBuffer);
            pCurrentElementNext = pCurrentElementNext->_ref_00726070();
        }
    }
}

struct ST_00a59400
{
    void FUN_00a59400(float*, float*, float*);
};
struct ST_00931e50
{
    virtual void v0(float);
    virtual void v1(float);
    virtual void v2(float);
    virtual void v3(float);
    virtual void v4(float);
    virtual void v5(float);
    virtual void v6(float);
    virtual void v7(float);
    virtual void v8(float);
    virtual void v9(float);
    virtual void v10(float);
    virtual void v11(float);
    virtual void v12(float);
    virtual void v13(float);
    virtual void v14(float);
    virtual void v15(float);
    virtual void v16(float);
    virtual void v17(float);
    virtual void v18(float);
    virtual void v19(float);
    virtual void v20(float);
    virtual void v21(float);
    virtual void v22(float);
    virtual void v23(float);
    virtual void v24(float);
    virtual void v25(float);
    virtual void v26(float);
    virtual void v27(float);
    virtual void v28(float);
    virtual void v29(float);
    virtual void v30(float);
    virtual void v31(float);
    virtual void v32(float);
    virtual void v33(float);
    virtual void v34(float);
    virtual void v35(float);
    virtual void v36(float);
    virtual void v37(float);
    virtual void v38(float);
    virtual void v39(float);
    virtual void v40(float);
    virtual void v41(float);
    virtual void v42(float);
    virtual void v43(float);
    virtual void v44(float);
    virtual void v45(float);
    virtual void v46(float);
    virtual void v47(float);
    virtual void v48(float);
    virtual void v49(float);
    virtual void v50(float);
    virtual void v51(float);
    virtual void v52(float);
    virtual void v53(float);
    virtual void v54(float);
    virtual void v55(float);
    virtual void v56(float);
    virtual void v57(float);
    virtual void v58(float);
    virtual void v59(float);
    virtual void v60(float);
    virtual void v61(float);
    virtual void v62(float);
    virtual void v63(float);
    virtual void v64(float);
    virtual void v65(float);
    virtual void v66(float);
    virtual void v67(float);
    virtual void v68(float);
    virtual void v69(float);
    virtual void v70(float);
    virtual void v71(float);
    virtual void v72(float);
    virtual void v73(float);
    virtual void v74(float);
    virtual void v75(float);
    virtual void v76(float);
    virtual void v77(float);
    virtual void v78(float);
    virtual void v79(float);
    virtual void v80(float);
    virtual void v81(float);
    virtual void v82(float);
    virtual void v83(float);
    virtual void v84(float);
    virtual void v85(float);
    virtual void v86(float);
    virtual void v87(float);
    virtual void v88(float);
    virtual void v89(float);
    virtual void v90(float);
    virtual void v91(float);
    virtual void v92(float);
    virtual void v93(float);
    virtual void v94(float);
    virtual void v95(float);
    virtual void v96(float);
    virtual void v97(float);
    virtual void v98(float);
    virtual void v99(float);
    virtual void v100(float);
    virtual void v101(float);
    virtual void v102(float);
    virtual void v103(float);
    virtual void v104(float);
    virtual void v105(float);
    virtual void v106(float);
    virtual void v107(float);
    virtual void v108(float);
    virtual void v109(float);
    virtual void v110(float);
    virtual void v111(float);
    virtual void v112(float);
    virtual void v113(float);
    virtual void v114(float);
    virtual void v115(float);
    virtual void v116(float);
    virtual void v117(float);
    virtual void v118(float);
    virtual void v119(float);
    virtual void v120(float);
    virtual void v121(float);
    virtual void v122(float);
    virtual void v123(float);
    virtual void v124(float);
    virtual void v125(float);
    virtual void v126(float);
    virtual void v127(float);
    virtual void v128(float);
    virtual void v129(float);
    virtual void v130(float);
    virtual void v131(float);
    virtual void v132(float);
    virtual void v133(float);
    virtual void v134(float);
    virtual void v135(float);
    virtual void v136(float);
    virtual void v137(float);
    virtual void v138(float);
    virtual void v139(float);
    virtual void v140(float);
    virtual void v141(float);
    virtual void v142(float);
    virtual void v143(float);
    virtual void v144(float);
    virtual void v145(float);
    virtual void v146(float);
    virtual void v147(float);
    virtual void v148(float);
    virtual void v149(float);
    virtual void v150(float);
    virtual void v151(float);
    virtual void v152(float);
    virtual void v153(float);
    virtual void v154(float);
    virtual void v155(float);
    virtual void v156(float);
    virtual void v157(float);
    virtual void v158(float);
    virtual void v159(float);
    virtual void v160(float);
    virtual void v161(float);
    virtual void v162(float);
    virtual void v163(float);
    virtual void v164(float);
    virtual void v165(float);
    virtual void v166(float);
    virtual void v167(float);
    virtual void v168(float);
    virtual void v169(float);
    virtual void v170(float);
    virtual void v171(float);
    virtual void v172(float);
    virtual void v173(float);
    virtual void v174(float);
    virtual void v175(float);
    virtual void v176(float);
    virtual void vm(float);
    void ClampLookAngle(float);
    void FUN_009c6330(ST_00a59400*);
};
// @fnv 0x009c6330
void ST_00931e50::FUN_009c6330(ST_00a59400* p)
{
    float c;
    float b;
    float a;
    p->FUN_00a59400(&b, &a, &c);
    vm(b);
    ClampLookAngle(a);
}

struct FUN_00563200_Struct
{
    int pad[4];
    int field10;
    int MaskWithField(int);
};
// @fnv 0x00563200
int FUN_00563200_Struct::MaskWithField(int a)
{
    return field10 & a;
}

struct FUN_00644660_holder
{
    char _pad[0xE0];
    float _e0;
    float GetE0();
};
// @fnv 0x00644660
float FUN_00644660_holder::GetE0()
{
    return _e0;
}

struct FUN_009b4440_shell
{
    char _pad[256];
    unsigned int _val100;
    unsigned int FUN_009b4440();
};
// @fnv 0x009b4440
unsigned int FUN_009b4440_shell::FUN_009b4440()
{
    return _val100;
}

struct FUN_009baba0_shell
{
    char pad[0x150];
    unsigned int val;
    bool FUN_009baba0();
};
// @fnv 0x009baba0
bool FUN_009baba0_shell::FUN_009baba0()
{
    return val == 4 || ((Projectile*)this)->IsProximityDetonationTriggered();
}

struct FUN_009c0050_shell
{
    char _pad[0x154];
    int _field;
    void SetField(int value);
};

// @fnv 0x009c0050
void FUN_009c0050_shell::SetField(int value)
{
    _field = value;
}

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
};

struct FUN_009bba90_shell
{
    int m_00;
    char m_04[12];
    char m_10[12];
    int m_1c;
    int m_20;
    int m_24;
    char m_28;
    char m_29;
    short m_2a;
    short m_2c;

    void FUN_009bba90(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x009bba90
void FUN_009bba90_shell::FUN_009bba90(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(&m_04, 12);
    apLoadGameBuffer->ReadTypedData(&m_10, 12);
    apLoadGameBuffer->ReadTypedData(&m_20, 4);
    apLoadGameBuffer->ReadTypedData(&m_24, 4);
    apLoadGameBuffer->ReadTypedData(&m_28, 1);
    if (apLoadGameBuffer->GetVersion() >= 0x11)
    {
        apLoadGameBuffer->ReadTypedData(&m_2a, 2);
        apLoadGameBuffer->ReadTypedData(&m_2c, 2);
    }
    apLoadGameBuffer->ReadFormIdentifier(this);
}

namespace fnv_009bbb40 {
struct NiAVObject;

struct TESObjectREFR
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
    virtual const char* GetName();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual NiAVObject* Get3D();

    unsigned int _ref_0084e3a0();
};

struct hkReferencedObject
{
    void RetainReference();
};

int __cdecl FUN_004b6ae0(NiAVObject*);
hkReferencedObject* __cdecl FindCollisionObjectByIndex(NiAVObject*, int);
void __cdecl _fnv_call_845cc0(const char*, ...);

struct FUN_009bbb40_shell
{
    TESObjectREFR* m_00;
    char m_04[12];
    char m_10[12];
    hkReferencedObject* m_1c;
    int m_20;
    int m_24;
    char m_28;
    char m_29;
    short m_2a;
    short m_2c;

    void ValidateWorldObjectCount(void* apLoadGameBuffer);
};

// @fnv 0x009bbb40
void FUN_009bbb40_shell::ValidateWorldObjectCount(void* apLoadGameBuffer)
{
    if (m_2a && m_2c != -1 && m_00)
    {
        short count = FUN_004b6ae0(m_00->Get3D());
        if (m_2a != count)
        {
            _fnv_call_845cc0("AI: World object count has changed on object %s %08 from %i to %i", m_00->GetName(),
                             m_00->_ref_0084e3a0(), m_2a, count);
        }
        else if (m_2c != -1)
        {
            m_1c = FindCollisionObjectByIndex(m_00->Get3D(), m_2c);
            if (m_1c)
                m_1c->RetainReference();
        }
    }
}
}  // namespace fnv_009bbb40

namespace fnv_009bdff0 {
struct NiNode;
struct TESObjectREFR;
struct NiObjectNET;

struct NiAVObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* vfn_0c();
    void FUN_00440490(float);
};

struct NiTimeController
{
    static void __cdecl UpdateControllersForTarget(NiObjectNET*);
};

void __cdecl FUN_00578060(TESObjectREFR*);
bool __cdecl FUN_005784b0(NiNode*);

struct FUN_009bdff0_shell
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void vfn_1c8(int);
    virtual void v115();
    virtual NiAVObject* vfn_1d0();

    void UpdateNodeTransform(int, int);
    void FUN_009bdff0();
};

// @fnv 0x009bdff0
void FUN_009bdff0_shell::FUN_009bdff0()
{
    vfn_1c8(0);
    NiAVObject* pn = vfn_1d0();
    if (pn)
    {
        pn->FUN_00440490(1.0f);
        UpdateNodeTransform(1, 0);
        if (pn->vfn_0c() && FUN_005784b0(pn->vfn_0c()))
            FUN_00578060((TESObjectREFR*)pn->vfn_0c());
        NiTimeController::UpdateControllersForTarget((NiObjectNET*)pn);
    }
}
}  // namespace fnv_009bdff0

namespace fnv_009bf370 {
struct NiPoint3Ex
{
    NiPoint3 operator-(const NiPoint3&) const;
};

struct hkpCharacterContext
{
    static float __cdecl GetReferenceTimeStep();
};

struct ActorSubObj
{
    virtual void v0();
    virtual void v1();
    virtual int GetAv(int);
};

struct Actor
{
    char pad_00[0xa4];
    ActorSubObj m_a4;
};

struct TESObjectREFR
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
    virtual bool IsActor();
};

struct Dummy009c4e60
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3* GetPos();

    void FUN_009c4e60(NiPoint3, bool);
};

struct FUN_009bf370_shell : Dummy009c4e60
{
    char pad_04[248];
    TESObjectREFR* m_fc;

    void FUN_0092f260(float, const NiPoint3&, int);
    void ApplySpeedAndVector(float afSpeed, NiPoint3 arVector);
};

// @fnv 0x009bf370
void FUN_009bf370_shell::ApplySpeedAndVector(float afSpeed, NiPoint3 arVector)
{
    NiPoint3 vecStartPos = *GetPos();
    if (m_fc && m_fc->IsActor())
    {
        Actor* actor = (Actor*)m_fc;
        if (actor->m_a4.GetAv(0x33) > 0)
        {
            afSpeed *= 1.0f / hkpCharacterContext::GetReferenceTimeStep();
        }
    }
    FUN_0092f260(afSpeed, arVector, 0xf);
    NiPoint3 vecEndPos = *GetPos();
    FUN_009c4e60(((NiPoint3Ex*)&vecEndPos)->operator-(vecStartPos), true);
}
}  // namespace fnv_009bf370

struct _ref_006815c0
{
    _ref_006815c0();
    char pad[12];
};

struct NiPlane
{
    bool FUN_004390c0(NiPoint3 const&);
};

struct FUN_009bffb0
{
    int m_00;
    _ref_006815c0 m_04;
    _ref_006815c0 m_10;
    int m_1c;
    int m_20;
    int m_24;
    char m_28;
    char m_29;
    short m_2a;
    short m_2c;

    FUN_009bffb0();
};

// Initializes the object: zeroes m_00, sets m_04 to NiPoint3::ZERO, initializes the plane at m_10, and sets m_1c, m_20, m_24, m_28, m_29, m_2a and m_2c.
// @fnv 0x009bffb0
FUN_009bffb0::FUN_009bffb0() : m_29(1)
{
    m_00 = 0;
    *(NiPoint3*)&m_04 = NiPoint3::ZERO;
    ((NiPlane*)&m_10)->FUN_004390c0(NiPoint3::ZERO);
    m_1c = 0;
    m_20 = 0x24;
    m_24 = 0xffffffff;
    m_28 = 0;
    m_2a = 0;
    m_2c = 0;
}

struct XActor
{
    void* GetActorBase();
};

struct FUN_009baf30_shell
{
    bool HasFlag8() const;
};

struct BSMultiBoundRoom
{
    void* FUN_006ab360();
};

struct TESModel
{
    unsigned int GetModelLength();
};

int __fastcall FUN_00874480(char*);

struct Actor
{
    bool FUN_008a8870();
};

void __cdecl FUN_009bb6d0(void*, void*);

struct TESObjectREFR
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
    virtual bool IsActor();
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool vfn_22c(bool);
    virtual bool vfn_230();
};

struct FUN_009c2ff0_shell
{
    void FUN_009c2ff0();
};

// @fnv 0x009c2ff0
void FUN_009c2ff0_shell::FUN_009c2ff0()
{
    if (((FUN_009baf30_shell*)((XActor*)this)->GetActorBase())->HasFlag8() &&
        ((TESModel*)((BSMultiBoundRoom*)((XActor*)this)->GetActorBase())->FUN_006ab360())->GetModelLength())
    {
        TESObjectREFR* ref = (TESObjectREFR*)FUN_00874480((char*)this);
        Actor* actor = (ref && ref->IsActor()) ? (Actor*)ref : 0;

        if (ref && !ref->vfn_22c(false) && !ref->vfn_230())
        {
            if (!actor || !actor->FUN_008a8870())
            {
                FUN_009bb6d0(ref, this);
            }
        }
    }
}

namespace fnv_009c30d0 {
struct S9b46c0
{
    bool FUN_00444d00(int);
};

struct TESObjectREFR
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
    virtual bool IsActor();
};

struct Actor
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool vfn_360();

    bool IsCombatTargetHostile(Actor*);
    void SpawnProjectile(Actor*, bool, void*, int);
};

struct FUN_009c30d0_shell
{
    char pad_00[0xfc];
    TESObjectREFR* m_fc;

    void NotifyActorIfEligible(Actor* apTarget, bool abFlag);
};

// If m_fc is an actor, checks a flag and target condition, then calls SpawnProjectile on the actor when the check passes.
// @fnv 0x009c30d0
void FUN_009c30d0_shell::NotifyActorIfEligible(Actor* apTarget, bool abFlag)
{
    if (m_fc && m_fc->IsActor())
    {
        bool bResult = true;
        Actor* pActor = (Actor*)m_fc;
        if (!pActor->vfn_360() && ((S9b46c0*)this)->FUN_00444d00(0x80000) && !pActor->IsCombatTargetHostile(apTarget))
            bResult = false;
        if (bResult)
            pActor->SpawnProjectile(apTarget, abFlag, this, 0);
    }
}
}  // namespace fnv_009c30d0

namespace fnv_009c3930 {
typedef int FIGHT_REACTION;

struct TESFaction;

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011cee48;

int __fastcall FUN_00874480(char*);

struct FUN_008b8290_shell
{
    int FUN_008b8290(TESFaction*, bool);
};

struct ActorH
{
    int GetReactionToActor(void*, bool*);
};

struct Actor
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool vfn_22c(bool);
};

struct FUN_009c3930_shell
{
    bool IsFightReactionAllowed(Actor* apTarget, Actor* apShooterActor, TESFaction* apOwnerFaction);
};

// @fnv 0x009c3930
bool FUN_009c3930_shell::IsFightReactionAllowed(Actor* apTarget, Actor* apShooterActor, TESFaction* apOwnerFaction)
{
    bool bcrimeCaused;
    bool bresult = false;
    bool bconsiderShooter = *g_011cee48.Int() > 0;
    FIGHT_REACTION eFightReaction;

    bcrimeCaused = false;

    if (bconsiderShooter || apTarget != (Actor*)FUN_00874480((char*)this))
    {
        if (!apTarget->vfn_22c(false))
        {
            if (!apOwnerFaction || ((FUN_008b8290_shell*)apTarget)->FUN_008b8290(apOwnerFaction, true) == -1)
            {
                eFightReaction =
                    apShooterActor
                        ? (FIGHT_REACTION)((ActorH*)apShooterActor)->GetReactionToActor(apTarget, &bcrimeCaused)
                        : (FIGHT_REACTION)0;
                if (eFightReaction == 0 || eFightReaction == 1)
                    bresult = true;
            }
        }
    }

    return bresult;
}
}  // namespace fnv_009c3930

namespace fnv_009c4ec0 {
struct SndX
{
    bool IsValid();
};

struct XActor
{
    void* GetActorBase();
};

struct SoundH
{
    unsigned int _ref_0084e3a0();
};

struct S3c60
{
    int GetArchetype();
};

struct Date
{
    int m1, m2, m3;
    ~Date();
};

struct SH_00418890
{
    void FUN_copy(const Date&);
};

struct FUN_00933150_shell
{
    Date PlaySoundByFormID(unsigned int, bool, unsigned int, bool);
};

struct FUN_009c4ec0_shell
{
    void InitSoundFromArchetype();
};

// If the sound at offset 0x134 is invalid, copies a sound built from the actor base archetype's sound file ID into it.
// @fnv 0x009c4ec0
void FUN_009c4ec0_shell::InitSoundFromArchetype()
{
    if (!((SndX*)((char*)this + 0x134))->IsValid())
    {
        if (((S3c60*)((XActor*)this)->GetActorBase())->GetArchetype())
        {
            unsigned int isoundFileID =
                ((SoundH*)((S3c60*)((XActor*)this)->GetActorBase())->GetArchetype())->_ref_0084e3a0();
            ((SH_00418890*)((char*)this + 0x134))
                ->FUN_copy(((FUN_00933150_shell*)this)->PlaySoundByFormID(isoundFileID, false, 0x40000102, true));
        }
    }
}
}  // namespace fnv_009c4ec0

namespace fnv_009c5af0 {
struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};

float __fastcall FUN_005471e0(void*);

struct _ref_006815c0
{
    _ref_006815c0();
    float x, y, z;
};

struct Proxy
{
    NiPoint3& FUN_004585f0(NiPoint3&);
};

struct FUN_004587f0_shell
{
    NiPoint3& FUN_004587f0(NiPoint3&);
};

struct NiPoint3Ex
{
    NiPoint3 operator-(const NiPoint3&) const;
};

struct FUN_009c5af0_shell : BSOcclusionPlane
{
    bool GetWaterPlaneIntersection(Proxy* apProxy, float* apWaterHeight);
};

// @fnv 0x009c5af0
bool FUN_009c5af0_shell::GetWaterPlaneIntersection(Proxy* apProxy, float* apWaterHeight)
{
    void* cell5 = (void*)GetCullResult();
    if (cell5 && ((MobileObjectCellAccess*)cell5)->FUN_004518e0())
    {
        float fRate = FUN_005471e0(cell5);
        _ref_006815c0 kPos9;
        apProxy->FUN_004585f0(*(NiPoint3*)&kPos9);
        _ref_006815c0 kPos2;
        ((FUN_004587f0_shell*)apProxy)->FUN_004587f0(*(NiPoint3*)&kPos2);

        if (kPos9.z > fRate && kPos2.z <= fRate)
        {
            NiPoint3 kDiff2 = ((NiPoint3Ex*)&kPos2)->operator-(*(NiPoint3*)&kPos9);
            float fDist = fRate - kPos9.z;
            *apWaterHeight = fDist / ((_ref_006815c0*)&kDiff2)->z;
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009c5af0

namespace fnv_009c3d90 {
struct TESObjectLIGH
{
    void* CreateLight(void*, void*, bool);
};

struct EffectSetting
{
    TESObjectLIGH* GetLight();
};

struct GO
{
    void operator=(void*);
};

struct RefH
{
    bool IsDeleted() const;
};

struct XActor
{
    virtual void* V000() = 0;
    virtual void* V001() = 0;
    virtual void* V002() = 0;
    virtual void* V003() = 0;
    virtual void* V004() = 0;
    virtual void* V005() = 0;
    virtual void* V006() = 0;
    virtual void* V007() = 0;
    virtual void* V008() = 0;
    virtual void* V009() = 0;
    virtual void* V010() = 0;
    virtual void* V011() = 0;
    virtual void* V012() = 0;
    virtual void* V013() = 0;
    virtual void* V014() = 0;
    virtual void* V015() = 0;
    virtual void* V016() = 0;
    virtual void* V017() = 0;
    virtual void* V018() = 0;
    virtual void* V019() = 0;
    virtual void* V020() = 0;
    virtual void* V021() = 0;
    virtual void* V022() = 0;
    virtual void* V023() = 0;
    virtual void* V024() = 0;
    virtual void* V025() = 0;
    virtual void* V026() = 0;
    virtual void* V027() = 0;
    virtual void* V028() = 0;
    virtual void* V029() = 0;
    virtual void* V030() = 0;
    virtual void* V031() = 0;
    virtual void* V032() = 0;
    virtual void* V033() = 0;
    virtual void* V034() = 0;
    virtual void* V035() = 0;
    virtual void* V036() = 0;
    virtual void* V037() = 0;
    virtual void* V038() = 0;
    virtual void* V039() = 0;
    virtual void* V040() = 0;
    virtual void* V041() = 0;
    virtual void* V042() = 0;
    virtual void* V043() = 0;
    virtual void* V044() = 0;
    virtual void* V045() = 0;
    virtual void* V046() = 0;
    virtual void* V047() = 0;
    virtual void* V048() = 0;
    virtual void* V049() = 0;
    virtual void* V050() = 0;
    virtual void* V051() = 0;
    virtual void* V052() = 0;
    virtual void* V053() = 0;
    virtual void* V054() = 0;
    virtual void* V055() = 0;
    virtual void* V056() = 0;
    virtual void* V057() = 0;
    virtual void* V058() = 0;
    virtual void* V059() = 0;
    virtual void* V060() = 0;
    virtual void* V061() = 0;
    virtual void* V062() = 0;
    virtual void* V063() = 0;
    virtual void* V064() = 0;
    virtual void* V065() = 0;
    virtual void* V066() = 0;
    virtual void* V067() = 0;
    virtual void* V068() = 0;
    virtual void* V069() = 0;
    virtual void* V070() = 0;
    virtual void* V071() = 0;
    virtual void* V072() = 0;
    virtual void* V073() = 0;
    virtual void* V074() = 0;
    virtual void* V075() = 0;
    virtual void* V076() = 0;
    virtual void* V077() = 0;
    virtual void* V078() = 0;
    virtual void* V079() = 0;
    virtual void* V080() = 0;
    virtual void* V081() = 0;
    virtual void* V082() = 0;
    virtual void* V083() = 0;
    virtual void* V084() = 0;
    virtual void* V085() = 0;
    virtual void* V086() = 0;
    virtual void* V087() = 0;
    virtual void* V088() = 0;
    virtual void* V089() = 0;
    virtual void* V090() = 0;
    virtual void* V091() = 0;
    virtual void* V092() = 0;
    virtual void* V093() = 0;
    virtual void* V094() = 0;
    virtual void* V095() = 0;
    virtual void* V096() = 0;
    virtual void* V097() = 0;
    virtual void* V098() = 0;
    virtual void* V099() = 0;
    virtual void* V100() = 0;
    virtual void* V101() = 0;
    virtual void* V102() = 0;
    virtual void* V103() = 0;
    virtual void* V104() = 0;
    virtual void* V105() = 0;
    virtual void* V106() = 0;
    virtual void* V107() = 0;
    virtual void* V108() = 0;
    virtual void* V109() = 0;
    virtual void* V110() = 0;
    virtual void* V111() = 0;
    virtual void* V112() = 0;
    virtual void* V113() = 0;
    virtual void* V114() = 0;
    virtual void* V115() = 0;

    virtual void* VirtualResult() = 0;

    void* GetActorBase();
    void FUN_009c3d90();
};

// @fnv 0x009c3d90
void XActor::FUN_009c3d90()
{
    if (this->VirtualResult())
    {
        if (reinterpret_cast<EffectSetting*>(this->GetActorBase())->GetLight() &&
            !reinterpret_cast<RefH*>(this)->IsDeleted())
        {
            reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x114)
                ->
                operator=(reinterpret_cast<EffectSetting*>(this->GetActorBase())
                              ->GetLight()
                              ->CreateLight(this, this->VirtualResult(), false));
        }
    }
}
}  // namespace fnv_009c3d90

namespace fnv_009bb970 {
struct NiAVObject;

struct NiAVObject
{
    virtual NiAVObject* m0()
    {
        return 0;
    }
    virtual NiAVObject* m1()
    {
        return 0;
    }
    virtual NiAVObject* m2()
    {
        return 0;
    }
    virtual NiAVObject* m3()
    {
        return 0;
    }
    virtual NiAVObject* m4()
    {
        return 0;
    }
    virtual NiAVObject* m5()
    {
        return 0;
    }
    virtual NiAVObject* m6()
    {
        return 0;
    }
    virtual NiAVObject* m7()
    {
        return 0;
    }
    virtual NiAVObject* m8()
    {
        return 0;
    }
    virtual NiAVObject* m9()
    {
        return 0;
    }
    virtual NiAVObject* m10()
    {
        return 0;
    }
    virtual NiAVObject* m11()
    {
        return 0;
    }
    virtual NiAVObject* m12()
    {
        return 0;
    }
    virtual NiAVObject* m13()
    {
        return 0;
    }
    virtual NiAVObject* m14()
    {
        return 0;
    }
    virtual NiAVObject* m15()
    {
        return 0;
    }
    virtual NiAVObject* m16()
    {
        return 0;
    }
    virtual NiAVObject* m17()
    {
        return 0;
    }
    virtual NiAVObject* m18()
    {
        return 0;
    }
    virtual NiAVObject* m19()
    {
        return 0;
    }
    virtual NiAVObject* m20()
    {
        return 0;
    }
    virtual NiAVObject* m21()
    {
        return 0;
    }
    virtual NiAVObject* m22()
    {
        return 0;
    }
    virtual NiAVObject* m23()
    {
        return 0;
    }
    virtual NiAVObject* m24()
    {
        return 0;
    }
    virtual NiAVObject* m25()
    {
        return 0;
    }
    virtual NiAVObject* m26()
    {
        return 0;
    }
    virtual NiAVObject* m27()
    {
        return 0;
    }
    virtual NiAVObject* m28()
    {
        return 0;
    }
    virtual NiAVObject* m29()
    {
        return 0;
    }
    virtual NiAVObject* m30()
    {
        return 0;
    }
    virtual NiAVObject* m31()
    {
        return 0;
    }
    virtual NiAVObject* m32()
    {
        return 0;
    }
    virtual NiAVObject* m33()
    {
        return 0;
    }
    virtual NiAVObject* m34()
    {
        return 0;
    }
    virtual NiAVObject* m35()
    {
        return 0;
    }
    virtual NiAVObject* m36()
    {
        return 0;
    }
    virtual NiAVObject* m37()
    {
        return 0;
    }
    virtual NiAVObject* m38()
    {
        return 0;
    }
    virtual NiAVObject* m39()
    {
        return 0;
    }
    virtual NiAVObject* m40()
    {
        return 0;
    }
    virtual NiAVObject* m41()
    {
        return 0;
    }
    virtual NiAVObject* m42()
    {
        return 0;
    }
    virtual NiAVObject* m43()
    {
        return 0;
    }
    virtual NiAVObject* m44()
    {
        return 0;
    }
    virtual NiAVObject* m45()
    {
        return 0;
    }
    virtual NiAVObject* m46()
    {
        return 0;
    }
    virtual NiAVObject* m47()
    {
        return 0;
    }
    virtual NiAVObject* m48()
    {
        return 0;
    }
    virtual NiAVObject* m49()
    {
        return 0;
    }
    virtual NiAVObject* m50()
    {
        return 0;
    }
    virtual NiAVObject* m51()
    {
        return 0;
    }
    virtual NiAVObject* m52()
    {
        return 0;
    }
    virtual NiAVObject* m53()
    {
        return 0;
    }
    virtual NiAVObject* m54()
    {
        return 0;
    }
    virtual NiAVObject* m55()
    {
        return 0;
    }
    virtual NiAVObject* m56()
    {
        return 0;
    }
    virtual NiAVObject* m57()
    {
        return 0;
    }
    virtual NiAVObject* m58()
    {
        return 0;
    }
    virtual NiAVObject* m59()
    {
        return 0;
    }
    virtual NiAVObject* m60()
    {
        return 0;
    }
    virtual NiAVObject* m61()
    {
        return 0;
    }
    virtual NiAVObject* m62()
    {
        return 0;
    }
    virtual NiAVObject* m63()
    {
        return 0;
    }
    virtual NiAVObject* m64()
    {
        return 0;
    }
    virtual NiAVObject* m65()
    {
        return 0;
    }
    virtual NiAVObject* m66()
    {
        return 0;
    }
    virtual NiAVObject* m67()
    {
        return 0;
    }
    virtual NiAVObject* m68()
    {
        return 0;
    }
    virtual NiAVObject* m69()
    {
        return 0;
    }
    virtual NiAVObject* m70()
    {
        return 0;
    }
    virtual NiAVObject* m71()
    {
        return 0;
    }
    virtual NiAVObject* m72()
    {
        return 0;
    }
    virtual NiAVObject* m73()
    {
        return 0;
    }
    virtual NiAVObject* m74()
    {
        return 0;
    }
    virtual NiAVObject* m75()
    {
        return 0;
    }
    virtual NiAVObject* m76()
    {
        return 0;
    }
    virtual NiAVObject* m77()
    {
        return 0;
    }
    virtual NiAVObject* m78()
    {
        return 0;
    }
    virtual NiAVObject* m79()
    {
        return 0;
    }
    virtual NiAVObject* m80()
    {
        return 0;
    }
    virtual NiAVObject* m81()
    {
        return 0;
    }
    virtual NiAVObject* m82()
    {
        return 0;
    }
    virtual NiAVObject* m83()
    {
        return 0;
    }
    virtual NiAVObject* m84()
    {
        return 0;
    }
    virtual NiAVObject* m85()
    {
        return 0;
    }
    virtual NiAVObject* m86()
    {
        return 0;
    }
    virtual NiAVObject* m87()
    {
        return 0;
    }
    virtual NiAVObject* m88()
    {
        return 0;
    }
    virtual NiAVObject* m89()
    {
        return 0;
    }
    virtual NiAVObject* m90()
    {
        return 0;
    }
    virtual NiAVObject* m91()
    {
        return 0;
    }
    virtual NiAVObject* m92()
    {
        return 0;
    }
    virtual NiAVObject* m93()
    {
        return 0;
    }
    virtual NiAVObject* m94()
    {
        return 0;
    }
    virtual NiAVObject* m95()
    {
        return 0;
    }
    virtual NiAVObject* m96()
    {
        return 0;
    }
    virtual NiAVObject* m97()
    {
        return 0;
    }
    virtual NiAVObject* m98()
    {
        return 0;
    }
    virtual NiAVObject* m99()
    {
        return 0;
    }
    virtual NiAVObject* m100()
    {
        return 0;
    }
    virtual NiAVObject* m101()
    {
        return 0;
    }
    virtual NiAVObject* m102()
    {
        return 0;
    }
    virtual NiAVObject* m103()
    {
        return 0;
    }
    virtual NiAVObject* m104()
    {
        return 0;
    }
    virtual NiAVObject* m105()
    {
        return 0;
    }
    virtual NiAVObject* m106()
    {
        return 0;
    }
    virtual NiAVObject* m107()
    {
        return 0;
    }
    virtual NiAVObject* m108()
    {
        return 0;
    }
    virtual NiAVObject* m109()
    {
        return 0;
    }
    virtual NiAVObject* m110()
    {
        return 0;
    }
    virtual NiAVObject* m111()
    {
        return 0;
    }
    virtual NiAVObject* m112()
    {
        return 0;
    }
    virtual NiAVObject* m113()
    {
        return 0;
    }
    virtual NiAVObject* m114()
    {
        return 0;
    }
    virtual NiAVObject* m115()
    {
        return 0;
    }
    virtual NiAVObject* m116()
    {
        return 0;
    }
};

int __cdecl FUN_004b6ae0(NiAVObject*);
int __cdecl FUN_004b6b60(NiAVObject*, void*);

struct SaveFormIDHelper
{
    void SerializeFormData(void*, int);
};

struct BGSSaveFormBuffer : public SaveFormIDHelper
{
    void SaveData(void*, int, int);
};

struct FUN_009bb970_shell
{
    NiAVObject* m_object;
    unsigned char m_data4[12];
    unsigned char m_data10[12];
    void* m_field1c;
    unsigned int m_field20;
    unsigned int m_field24;
    unsigned char m_field28;
    unsigned char m_field29;
    unsigned short m_field2a;
    unsigned short m_field2c;

    void SaveToBuffer(BGSSaveFormBuffer*);
};

// Writes m_data4, m_data10, m_field20/24/28 to the buffer, computes m_field2a/m_field2c from m_object and m_field1c, saves them, then saves m_object's form ID.
// @fnv 0x009bb970
void FUN_009bb970_shell::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(&m_data4, 12, 0);
    buffer->SaveData(&m_data10, 12, 0);
    buffer->SaveData(&m_field20, 4, 0);
    buffer->SaveData(&m_field24, 4, 0);
    buffer->SaveData(&m_field28, 1, 0);

    m_field2a = 0;
    m_field2c = 0;

    if (m_object && m_field1c)
    {
        m_field2a = FUN_004b6ae0(m_object->m116());
        m_field2c = FUN_004b6b60(m_object->m116(), m_field1c);
    }

    buffer->SaveData(&m_field2a, 2, 0);
    buffer->SaveData(&m_field2c, 2, 0);
    buffer->SerializeFormData(m_object, 0);
}
}  // namespace fnv_009bb970

struct Point
{
    float x, y, z;
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix FUN_0043f8d0(const Matrix&);
};
struct SceneNode
{
    void FUN_0043fa80(const Matrix&);
    void FUN_00440460(const Point&);
    void FUN_00450f90(bool);
    const Matrix& FUN_00461130();
    const Point& FUN_0045bb80();
};
struct VirtualObject
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual SceneNode* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual SceneNode* v131();
};
struct Owner : VirtualObject
{
};
struct BaseData
{
    float GetField90Float();
};
struct Path
{
    void FUN_0051b840(float);
};
struct PathHolder
{
    Path* value;
    Path* FUN_00559450();
};
extern Owner* g_thePlayer;
struct ProjectileView : VirtualObject
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    unsigned char flag90;
    Matrix rotation;
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
    PathHolder path;
    bool FUN_00440d80();
    float FUN_00885bd0();
    void UpdateDetonation(float);
    Owner* FUN_00874480();
    void FUN_009c6330(const Matrix&);
    void FUN_00575830(const Point&);
    float GetE0();
    void FUN_009bc8f0();
    BaseData* FUN_004181e0();
    void FUN_00979330(float);
};
// @fnv 0x00979330
void ProjectileView::FUN_00979330(float delta)
{
    if (FUN_00440d80())
        return;
    if (FUN_00885bd0() == 0.0)
        UpdateDetonation(delta);
    SceneNode* node = FUN_00874480() ? FUN_00874480()->v131() : 0;
    SceneNode* parent = v116();
    if (node && parent)
    {
        if (FUN_00874480() == g_thePlayer)
        {
            parent->FUN_0043fa80(rotation.FUN_0043f8d0(node->FUN_00461130()));
            FUN_009c6330(rotation.FUN_0043f8d0(node->FUN_00461130()));
        }
        parent->FUN_00440460(node->FUN_0045bb80());
        FUN_00575830(node->FUN_0045bb80());
    }
    if (path.FUN_00559450())
        path.FUN_00559450()->FUN_0051b840(GetE0());
    if (FUN_00885bd0() > 5.0)
        FUN_009bc8f0();
    if (flag90 && FUN_00885bd0() >= FUN_004181e0()->GetField90Float())
    {
        if (v116())
            v116()->FUN_00450f90(true);
        FUN_009bc8f0();
    }
}

namespace fnv_009bd860 {
struct ObjX;
struct Player965
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual ObjX* GetTarget();
    void UpdateAim(void* proj, ObjX* target, float* a, float* b, float* c, float d, float e);
};
extern Player965* g_thePlayer;

struct ListEntryX
{
    int unk00;
    unsigned char byte4;
};
struct GlobalMgrX
{
    unsigned int CallGetFlags();
    ListEntryX* FUN_009c71c0();
};
extern GlobalMgrX DAT_011f2250;

struct ObjX9c5
{
    ObjX9c5();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct PtrX
{
    operator void*() const;
    void* p;
};

struct ProjX
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual ObjX* GetDefTarget();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float f24;
    int unk28;
    float f2c;
    float f30;
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
    PtrX visual;
    bool FUN_00444d00(int);
    void SetObj(ObjX9c5*);
    void Finish(int, int);
    void FUN_009bd860();
};

// Chooses a target (player target or default), optionally sets a new object, spawns the visual via g_thePlayer when absent, then calls Finish(1, 0).
// @fnv 0x009bd860
void ProjX::FUN_009bd860()
{
    bool bShouldUpdate = true;
    if (FUN_00444d00(4) && !FUN_00444d00(8) && DAT_011f2250.CallGetFlags() != 4)
        bShouldUpdate = false;
    if (bShouldUpdate)
    {
        ObjX* target = g_thePlayer->GetTarget();
        if (!target)
            target = GetDefTarget();
        if ((FUN_00444d00(0x40000) || !FUN_00444d00(4)) && DAT_011f2250.CallGetFlags() == 4 &&
            DAT_011f2250.FUN_009c71c0() && DAT_011f2250.FUN_009c71c0()->byte4)
        {
            SetObj(new ObjX9c5());
        }
        if (!visual)
            g_thePlayer->UpdateAim(this, target, &f2c, &f24, &f30, 1.175494351e-38F, 1.175494351e-38F);
        Finish(1, 0);
    }
}
}  // namespace fnv_009bd860

namespace fnv_009c2c80 {
struct NiRTTI_S
{
    int unk00;
};
struct NiAVObj_S;
struct NiNode_S;

struct ColFilter
{
    int filter;
    ColFilter(int f);
    int GetLayer();
    bool IsFlagSet();
};

struct FlagHolder
{
    bool IsFlagSet();
};

struct WorldObj
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
    virtual int vfn94();
};

struct WorldObjF : WorldObj
{
    ColFilter GetFilter();
};

struct FlagWorld
{
    FlagHolder GetFilterF();
};

struct ColObj
{
    WorldObjF* GetWorldObject();
};

struct CdBody
{
    int GetCollisionFilterInfo();
};

struct RefObj
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual NiNode_S* Get3D();
};

struct PlayerChar : RefObj
{
    NiNode_S* GetNode(bool firstPerson);
};

struct ProjData
{
    int GetType();
    bool IsFlagA() const;
    bool IsFlagB();
};

extern PlayerChar* g_thePlayer;
extern NiRTTI_S g_01268444;

void* GetEntity(CdBody* body);
WorldObjF* GetUserData(void* entity);
bool IsKindOfRTTI(const NiRTTI_S* rtti, WorldObjF* obj);
ColObj* FindCollisionObject(NiNode_S* node);

// @fnv 0x009c2c80
bool __cdecl CanProjectileHit(RefObj* ref, CdBody* body, int unused, ProjData* data)
{
    void* entityTmp = body ? GetEntity(body) : 0;
    WorldObjF* worldObj4 = entityTmp ? GetUserData(entityTmp) : 0;
    if (worldObj4)
    {
        if (IsKindOfRTTI(&g_01268444, worldObj4))
        {
            return false;
        }
        else if (worldObj4->GetFilter().GetLayer() == 0x1e)
        {
            NiNode_S* node2 = ref ? ref->Get3D() : 0;
            if (ref == g_thePlayer)
            {
                node2 = g_thePlayer->GetNode(false);
            }
            ColObj* colObj = FindCollisionObject(node2);
            WorldObjF* refWorldVal = colObj ? colObj->GetWorldObject() : 0;
            if (refWorldVal)
            {
                if (!refWorldVal->GetFilter().IsFlagSet() && refWorldVal->vfn94())
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    if (data && body)
    {
        if (ColFilter(body->GetCollisionFilterInfo()).GetLayer() == 0x1a ||
            ColFilter(body->GetCollisionFilterInfo()).GetLayer() == 0x1c)
        {
            int type = data->GetType();
            if (type != 0x20000 && (type != 0x10000 || data->IsFlagA() || data->IsFlagB()))
            {
                return false;
            }
        }
    }
    return true;
}
}  // namespace fnv_009c2c80

float FUN_004e44b0(float);
float cos(float);
class NiPoint3Ex
{
  public:
    float x, y, z;
    NiPoint3Ex(float, float, float);
    NiPoint3Ex operator*(float) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
};
// Fills count output points around center using yaw, pitch, spread, radius and offset to vary the spherical direction per index.
// @fnv 0x009c3f90
void GenerateSpherePoints(NiPoint3Ex* output, int count, NiPoint3Ex center, float yaw, float pitch, float spread,
                          float radius, float offset)
{
    for (int p = 0; p < count; ++p)
    {
        float h = (float)p / count * 6.2831854820251465 + offset;
        float s = FUN_004e44b0(h) * spread + pitch;
        float q = cos(h) * spread + yaw;
        float i = cos(s);
        float eb = FUN_004e44b0(s);
        float cf = cos(q);
        float a = FUN_004e44b0(q);
        NiPoint3Ex f(a * i, cf * i, -eb);
        output[p] = center + f * radius;
    }
}

struct BaseProcess9c
{
    virtual ~BaseProcess9c();
    virtual void CopyFrom(BaseProcess9c* other);
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void Activate18();
    int GetProcessLevel();
};
struct HighProcess : public BaseProcess9c
{
    HighProcess();
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
};
struct GlobalLock9c
{
    void Lock(const char* name);
    void Unlock();
};
extern GlobalLock9c g_lock9c;
struct Mob9c;
struct ProcessLists9c
{
    void RemoveActor(Mob9c* actor, int level);
    void AddActor(Mob9c* actor, int a, bool b, bool c, bool d);
};
extern ProcessLists9c g_processLists9c;
struct Mob9c
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void SetProcessFlag(int);
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
    BaseProcess9c* process;
    bool FUN_009c47d0();
};

// @fnv 0x009c47d0
bool Mob9c::FUN_009c47d0()
{
    g_lock9c.Lock(0);
    if (process)
    {
        int level = process->GetProcessLevel();
        g_processLists9c.RemoveActor(this, level);
    }
    HighProcess* pHighProcess = new HighProcess;
    pHighProcess->CopyFrom(process);
    delete process;
    process = pHighProcess;
    g_processLists9c.AddActor(this, 0, 0, 0, 0);
    g_lock9c.Unlock();
    SetProcessFlag(0);
    process->Activate18();
    return true;
}

struct LockObj_9c4a40
{
    void Lock(const char* name);
    void Unlock();
};
extern LockObj_9c4a40 g_projectileLock_9c4a40;

struct Process_9c4a40
{
    int GetProcessLevel();
};

struct ProcessLists
{
    void FUN_0096d470(MobileObject* obj, int level);
    void FUN_0096d450(MobileObject* obj, int a, bool b, bool c, bool d);
};
extern ProcessLists DAT_011e0e80;

struct BaseProcess_9c4a40
{
    virtual ~BaseProcess_9c4a40();
    virtual void CopyFrom(BaseProcess_9c4a40* other);
    int GetProcessLevel();
};

struct FUN_0092c950 : BaseProcess_9c4a40
{
    FUN_0092c950();
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
};

struct Owner_9c4a40
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
    BaseProcess_9c4a40* process;
    bool FUN_009c4a40();
};

// @fnv 0x009c4a40
bool Owner_9c4a40::FUN_009c4a40()
{
    g_projectileLock_9c4a40.Lock(0);
    if (process)
    {
        int level = process->GetProcessLevel();
        DAT_011e0e80.FUN_0096d470((MobileObject*)this, level);
    }
    BaseProcess_9c4a40* newProcess = new FUN_0092c950;
    newProcess->CopyFrom(process);
    delete process;
    process = newProcess;
    DAT_011e0e80.FUN_0096d450((MobileObject*)this, 2, 0, 0, 0);
    g_projectileLock_9c4a40.Unlock();
    return true;
}

struct ExplosionSource
{
    float FUN_00477900();
    float FUN_006a78f0();
};
struct ProjectileBaseCalls
{
    ExplosionSource* FUN_004fd3c0();
    bool FUN_004fd360();
    bool FUN_00975300();
};
struct ProjectileCalls
{
    bool FUN_00444d00(int);
    ProjectileBaseCalls* FUN_004181e0();
    float GetFieldE4Float();
};
extern Setting_S setting11cf3f0, setting11cea74, setting11ceabc, setting11cf764;
float ComputeExplosionDamageFalloff(float, float, float);
extern float DAT_0108e2b0;
struct FUN_009a52f0_shell
{
    void AddOrUpdateItem(ProjectileCalls*, float, float, float, float);
    void UpdateExplosion(ProjectileCalls*);
};
// Checks the projectile's explosion source and, when its radius and length pass the settings thresholds, computes elapsed/duration and calls AddOrUpdateItem.
// @fnv 0x009a52f0
void FUN_009a52f0_shell::UpdateExplosion(ProjectileCalls* projectile)
{
    if (projectile->FUN_00444d00(1))
        return;
    ProjectileBaseCalls* base = projectile->FUN_004181e0();
    ExplosionSource* source = base->FUN_004fd3c0();
    if (base->FUN_004fd360() && source)
    {
        float length = source->FUN_00477900();
        float radius = source->FUN_006a78f0();
        if (radius >= *setting11cf3f0.Float())
        {
            length = ComputeExplosionDamageFalloff(length, radius, *setting11cf3f0.Float());
            if (length >= *setting11cea74.Float())
            {
                float elapsed = 0.0f;
                float duration = DAT_0108e2b0;
                if (base->FUN_00975300())
                {
                    if (projectile->GetFieldE4Float() != 3.4028234663852886e+38)
                    {
                        duration = projectile->GetFieldE4Float() + 1.0;
                        if (duration > *setting11ceabc.Float())
                            elapsed = duration - *setting11ceabc.Float();
                    }
                    else
                        duration = *setting11cf764.Float();
                }
                if (duration > 0.0)
                    AddOrUpdateItem(projectile, length, elapsed, duration, radius);
            }
        }
    }
}

struct PrjPoint3
{
    float x;
    float y;
    float z;

    PrjPoint3();
};

struct PrjTransform
{
    float m_afRotate[9];
    PrjPoint3 m_kTranslate;
    float m_fScale;

    PrjTransform();
    void ResetToIdentity();
};

struct PrjList
{
    void* pItem;
    PrjList* pNext;

    PrjList();
    ~PrjList();
};

struct PrjNode;
struct PrjNodePtr
{
    PrjNode* p;

    PrjNodePtr(PrjNode* apObject = 0);
    ~PrjNodePtr();
    PrjNodePtr& operator=(PrjNode* apObject);
};

struct PrjCause;
struct PrjCausePtr
{
    PrjCause* p;

    PrjCausePtr(PrjCause* apObject = 0);
    ~PrjCausePtr();
    PrjCausePtr& operator=(PrjCause* apObject);
};

struct PrjSoundHandle
{
    unsigned int uiID;
    unsigned int uiState;
    unsigned int uiFlags;

    PrjSoundHandle();
    ~PrjSoundHandle();
};

struct PrjSetting
{
    float* Float();
};

struct PrjItemForm;

struct PrjItemEntry
{
    double GetValue(int aiUnk);
    PrjItemForm* GetType();
    float GetSpread(struct PrjAVOwner* apOwner, float afScale, bool abFlag);
    bool HasMod(int aiMod);
};

struct PrjProcess
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual PrjItemEntry* GetWeaponInfo();
};

struct PrjRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual bool IsActor();
    PrjProcess* GetCurrentProcess();
};

struct PrjAVOwner
{
    int unk00;
};

struct PrjActor : PrjRef
{
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
    PrjAVOwner kAVOwner;

    bool IsPlayerTeammate();
};

struct PrjPlayer : PrjActor
{
    PrjItemEntry* GetAmmoInfo();
    bool IsAiming();
};

struct PrjWeaponClip
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual unsigned short GetClipSize();
};

struct PrjWeaponFlags
{
    bool IsAutomatic();
};

struct PrjWeapon
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
    PrjWeaponClip kClip;
    int unk0A0;
    PrjWeaponFlags kFlags;

    unsigned char GetDamageForActor(bool abHasMod, int aiUnk, PrjActor* apShooter);
};

struct PrjFormBase
{
    virtual void Fv00();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
};

struct PrjChildCell
{
    virtual void Cv00();
};

struct PrjMobile : PrjFormBase, PrjChildCell
{
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
    int iUnk68;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;

    PrjMobile();
    virtual ~PrjMobile();
    void SetLocationOnReference(const PrjPoint3& arPos);
    void SetAngleX(float afAngle);
    void SetAngleZ(float afAngle);
    void SetAngleY(float afAngle);
    void SetBaseForm(void* apForm);
    PrjActor* GetShooter();
    PrjWeapon* GetLoadedForm();
    void SetAmmo(PrjItemEntry* apAmmo);
    void SetFlag(int aiFlag, int aiValue);
    void SetMobileType(int aiUnk);
};

extern float g_fPrjMaxDistance;
extern float g_fPrjDefault14C;
extern const PrjPoint3 g_kPrjZero;
extern PrjPlayer* g_pPrjPlayer;
extern PrjSetting g_kPrjSpreadScale;
extern PrjSetting g_kPrjSpreadBase;
unsigned int __cdecl PrjGetItemCount(PrjItemForm* apForm);
float __cdecl PrjGetAmmoSpread(PrjItemForm* apForm, bool abAiming);
float __cdecl PrjMax(float afA, float afB);

struct FUN_009bbef0 : PrjMobile
{
    PrjList kList88;
    bool bUnk90;
    PrjTransform kTransform94;
    int iUnkC8;
    float fUnkCC;
    float fUnkD0;
    float fUnkD4;
    float fUnkD8;
    float fBodyPartChance;
    float fUnkE0;
    float fImpulseRadiusSquared;
    float fUnkE8;
    int unkEC;
    int unkF0;
    float fRateScale;
    void* pWeaponEntry;
    PrjRef* pSource;
    int iUnk100;
    PrjPoint3 kPoint104;
    float fUnk110;
    PrjNodePtr spNode114;
    int unk118;
    PrjNodePtr spNode11C;
    PrjCausePtr spCause120;
    float fUnk124;
    PrjSoundHandle kSound128;
    PrjSoundHandle kSound134;
    int iUnk140;
    int iUnk144;
    bool bUnk148;
    float fUnk14C;

    FUN_009bbef0(void* apBaseForm, PrjRef* apSource, void* apWeaponEntry, PrjPoint3 akPos, float afAngleX,
                 float afAngleZ);
    virtual ~FUN_009bbef0();
};

// Initialises a projectile: sets its position and angles, base form, weapon entry, spread and rate scale, ammo, and clears its runtime state.
// @fnv 0x009bbef0
FUN_009bbef0::FUN_009bbef0(void* apBaseForm, PrjRef* apSource, void* apWeaponEntry, PrjPoint3 akPos, float afAngleX,
                           float afAngleZ)
{
    iUnk68 = 0;
    SetLocationOnReference(akPos);
    SetAngleX(afAngleX);
    SetAngleZ(afAngleZ);
    SetAngleY(0.0f);
    pSource = apSource;
    iUnk100 = 0;
    pWeaponEntry = 0;
    fUnkCC = 1.0f;
    fUnkD0 = 1.0f;
    fBodyPartChance = 0.0f;
    fUnkD4 = 0.0f;
    fUnkE0 = 1.0f;
    fImpulseRadiusSquared = g_fPrjMaxDistance;
    fUnkE8 = 0.0f;
    spNode11C = 0;
    spCause120 = 0;
    bUnk90 = false;
    iUnk140 = 0;
    iUnk144 = 0;
    fRateScale = 1.0f;
    bUnk148 = false;
    fUnk14C = g_fPrjDefault14C;
    SetBaseForm(apBaseForm);

    if (apWeaponEntry)
    {
        PrjItemEntry* pWeaponInfo = 0;
        bool bHasMod = false;
        pWeaponEntry = apWeaponEntry;
        fBodyPartChance = GetLoadedForm()->kClip.GetClipSize();
        PrjActor* pShooter2 = 0;
        if (GetShooter() && GetShooter()->IsActor())
        {
            pShooter2 = GetShooter();
            if (pShooter2->GetCurrentProcess())
            {
                pWeaponInfo = pShooter2->GetCurrentProcess()->GetWeaponInfo();
                if (pWeaponInfo)
                {
                    fRateScale = pWeaponInfo->GetValue(0) / PrjGetItemCount(pWeaponInfo->GetType());
                    fBodyPartChance = pWeaponInfo->GetSpread(pShooter2 ? &pShooter2->kAVOwner : 0, 1.0f, true);
                    bHasMod = pWeaponInfo->HasMod(0xc);
                }
            }
        }
        fBodyPartChance = fBodyPartChance / GetLoadedForm()->GetDamageForActor(bHasMod, 0, pShooter2);
        if (bHasMod)
            fBodyPartChance = fBodyPartChance * 1.3;
    }

    if (GetShooter() == g_pPrjPlayer && GetLoadedForm() && GetLoadedForm()->kFlags.IsAutomatic())
    {
        PrjItemEntry* pAmmoInfo = g_pPrjPlayer->GetAmmoInfo();
        if (pAmmoInfo)
        {
            SetAmmo(pAmmoInfo);
            if (pAmmoInfo->GetType())
            {
                float fAmmoSpread =
                    *g_kPrjSpreadScale.Float() *
                    PrjMax(*g_kPrjSpreadBase.Float(), PrjGetAmmoSpread(pAmmoInfo->GetType(), g_pPrjPlayer->IsAiming()));
                fBodyPartChance += PrjMax(0.0f, fAmmoSpread);
            }
        }
    }

    iUnkC8 = 0;
    fUnkD8 = 0.0f;
    fUnk110 = 0.0f;
    kPoint104 = g_kPrjZero;
    spNode114 = 0;
    fUnk124 = 0.0f;
    kTransform94.ResetToIdentity();
    if (pSource && pSource->IsActor())
    {
        PrjActor* pSourceActor = (PrjActor*)pSource;
        if (pSourceActor->IsPlayerTeammate())
            SetFlag(0x80000, 1);
    }
    SetMobileType(0);
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct P062Object;
struct P062Ammo;
struct P062Scene;
struct P062Cause;
struct FUN_00416870
{
    float x, y, z;
    FUN_00416870(float, float, float);
    FUN_00416870 operator+(const FUN_00416870&) const;
};
struct FUN_006815c0
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    FUN_006815c0();
    void FUN_004a0c90(float);
    FUN_00416870 FUN_004b4500(const FUN_00416870&);
};
struct FUN_00414430
{
    float r, g, b, a;
    FUN_00414430(float, float, float, float);
};
struct P062Scene
{
    void FUN_00a5a040();
    const FUN_00416870& FUN_0045bb80();
    void FUN_00440460(const FUN_00416870&);
};
struct P062Values
{
    virtual void v0();
    virtual void v1();
    virtual int value(int);
};
struct P062Sound
{
    unsigned int id;
    unsigned int flags;
    unsigned int state;
    void FUN_00418900(const P062Sound&);
    void SetPositionFromArray(void*);
    void SetNiNode(P062Scene*);
    void Play(bool);
};
struct P062Object
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
    virtual bool IsActor();
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual P062Object* equipment();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void SetCause(P062Cause*);
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual P062Scene* scene();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* soundContext();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void SetExtra(void*);
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float scale(bool);
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void Initialize();
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
    P062Values values;
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
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    P062Sound sound;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned char soundReady;
    float soundPercent;
    void ClearList();
    float FUN_00453700();
    void FUN_00966a00(float);
    bool HasEffect(int);
    float GetEffectValue(int, int);
    int FUN_00446390();
    int GetField19C();
    P062Object* FUN_008d8520();
    void FUN_009bd580(float);
    void FUN_009bd5a0(float);
    void FUN_005de0a0(int, bool);
    void SetObject(void*);
    void FUN_00567ad0(void*);
    bool FUN_004c0bf0();
    float FUN_009bd540();
    void FUN_00586130(float);
    void FUN_0097f720(P062Object*);
    bool FUN_00444d00(int);
};
struct P062Ammo
{
    int FUN_004fd4f0();
    P062Ammo* FUN_004fd3e0();
    bool FUN_009bc870();
    bool FUN_00975300();
    float FUN_0045cd80();
    int FUN_00511840();
    unsigned char GetField45();
};
struct FUN_009b7af0 : P062Object
{
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    FUN_009b7af0(P062Ammo*, P062Object*, P062Object*, NiPoint3, float, float);
};
struct FUN_009b4020 : P062Object
{
    unsigned int unk150;
    FUN_009b4020(P062Ammo*, P062Object*, P062Object*, NiPoint3, float, float);
};
struct FUN_00979070 : P062Object
{
    unsigned int unk150;
    FUN_00979070(P062Ammo*, P062Object*, P062Object*, NiPoint3, float, float);
};
struct FUN_009ab090 : P062Object
{
    unsigned int unk150;
    unsigned int unk154;
    FUN_009ab090(P062Ammo*, P062Object*, P062Object*, NiPoint3, float, float);
};
struct FUN_009b31f0 : P062Object
{
    unsigned int unk150;
    unsigned int unk154;
    FUN_009b31f0(P062Ammo*, P062Object*, P062Object*, NiPoint3, float, float);
};
struct FUN_0066e010
{
    unsigned int referenceCount;
    P062Object* owner;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    FUN_0066e010(P062Object*);
};
struct BSSoundHandleEx : P062Sound
{
    ~BSSoundHandleEx();
};
struct P062Audio
{
    BSSoundHandleEx FUN_00ad7480(int, int, P062Ammo*);
};
P062Audio* __cdecl FUN_00453a70();
P062Object* __cdecl FindProjectObject(P062Object*, P062Ammo*);
void __cdecl FUN_005e58f0(int, P062Object*, P062Object*, float*);
float __cdecl FUN_00716440();
void* __cdecl FUN_0058db10(int);
float __cdecl FUN_0040ebd0(float, float);
struct P062Setting
{
    float* FUN_00403e20();
};
extern P062Setting DAT_011cf9c8;
extern P062Setting DAT_011cf32c;
extern P062Setting DAT_011cee00;
extern P062Setting DAT_011f210c;
extern P062Object* DAT_011dea3c;
extern bool DAT_011f20a4;
struct P062World
{
    void FUN_00458e20(P062Scene*, float);
};
extern P062World* DAT_011dea10;
P062Scene* __cdecl CreateOctahedron(float, const FUN_00414430&, bool);
P062Scene* __cdecl FUN_004b3890(const FUN_00416870&, const FUN_00414430&, const FUN_00416870&, const FUN_00414430&,
                                bool);
struct P062Queue
{
    P062Object* FUN_00825c00(P062Object*);
};
extern P062Queue* DAT_011f1958;
struct P062Queued
{
    void UpdateExplosion();
};

// @fnv 0x009bca60
P062Object* __cdecl CreateProjectile(P062Ammo* ammo, P062Object* owner, P062Object* parent, P062Object* weapon,
                                     NiPoint3 position, float yaw, float pitch, void* source, int word100,
                                     bool flag1000, bool flag20000, float range, float speed, void* extra)
{
    P062Object* projectile = 0;
    bool initialize = true;
    if (ammo)
    {
        switch (ammo->FUN_004fd4f0())
        {
        case 0x10000:
            projectile = new FUN_009b7af0(ammo, owner, weapon, position, yaw, pitch);
            break;
        case 0x20000:
            projectile = new FUN_009b4020(ammo, owner, weapon, position, yaw, pitch);
            break;
        case 0x40000:
            projectile = new FUN_00979070(ammo, owner, weapon, position, yaw, pitch);
            break;
        case 0x100000:
            projectile = new FUN_009ab090(ammo, owner, weapon, position, yaw, pitch);
            break;
        case 0x80000:
            projectile = FindProjectObject(owner, ammo);
            if (projectile)
            {
                P062Object* reused = projectile;
                reused->ClearList();
                initialize = false;
            }
            else
            {
                projectile = new FUN_009b31f0(ammo, owner, weapon, position, yaw, pitch);
            }
            break;
        }
    }
    if (owner == DAT_011dea3c && weapon)
    {
        P062Object* equipped = DAT_011dea3c->FUN_008d8520()->equipment();
        if (equipped && equipped->HasEffect(9))
            projectile->FUN_00966a00(projectile->FUN_00453700() * weapon->GetEffectValue(9, 0));
        if (weapon->FUN_00446390() == 13)
        {
            int required = weapon->GetField19C();
            int skill = DAT_011dea3c->values.value(5);
            float multiplier = 1.0f + (skill - required) * *DAT_011cf9c8.FUN_00403e20();
            projectile->FUN_00966a00(projectile->FUN_00453700() * multiplier);
        }
    }
    if (projectile && owner && owner->IsActor())
    {
        P062Object* multiplier = owner;
        float actor = 1.0f;
        FUN_005e58f0(0x3b, owner, weapon, &actor);
        if (actor != 1.0)
            projectile->FUN_00966a00(projectile->FUN_00453700() * actor);
        if (multiplier->values.value(0x33) > 0)
            projectile->FUN_00966a00(projectile->FUN_00453700() * (1.0f / FUN_00716440()));
    }
    if (projectile)
    {
        projectile->FUN_009bd580(range);
        projectile->FUN_009bd5a0(speed);
    }
    if (projectile)
        projectile->FUN_005de0a0(0x20000, flag20000);
    if (projectile && initialize)
    {
        if (owner && owner->IsActor())
            projectile->SetCause((P062Cause*)new FUN_0066e010(owner));
        projectile->SetObject(source);
        if (owner == DAT_011dea3c)
        {
            void* effect = FUN_0058db10(6);
            if (effect)
                projectile->FUN_00567ad0(effect);
            if (weapon->FUN_004c0bf0())
                projectile->FUN_00586130(FUN_0040ebd0(
                    1.0f, *DAT_011cf32c.FUN_00403e20() + *DAT_011cee00.FUN_00403e20() * DAT_011dea3c->FUN_009bd540()));
        }
        if (parent)
            parent->FUN_0097f720(projectile);
        if (word100)
            projectile->unk100 = word100;
        if (flag1000)
            projectile->FUN_005de0a0(0x1000, true);
        if (extra)
            projectile->SetExtra(extra);
        projectile->Initialize();
    }
    if (projectile && ammo && ammo->FUN_004fd3e0())
    {
        if (!ammo->FUN_009bc870() && !(ammo->FUN_00975300() && !(ammo->FUN_0045cd80() <= 0.0)))
        {
            projectile->sound.FUN_00418900(
                FUN_00453a70()->FUN_00ad7480(ammo->FUN_004fd3e0()->FUN_00511840(), 0x40000012, ammo->FUN_004fd3e0()));
            projectile->sound.SetPositionFromArray(owner->soundContext());
            projectile->sound.SetNiNode(projectile->scene());
            projectile->soundPercent = ammo->FUN_004fd3e0()->GetField45() * 100;
        }
        if (projectile->FUN_00444d00(1))
        {
            projectile->sound.Play(true);
            projectile->soundReady = true;
        }
    }
    else if (projectile && projectile->FUN_00444d00(1))
    {
        projectile->soundReady = true;
    }
    if (DAT_011f20a4 && projectile && projectile->scene())
    {
        FUN_00414430 color(1.0f, 0.0f, 0.0f, 0.6f);
        P062Scene* geometry = CreateOctahedron(4.0f, color, true);
        geometry->FUN_00a5a040();
        geometry->FUN_00440460(projectile->scene()->FUN_0045bb80());
        DAT_011dea10->FUN_00458e20(geometry, *DAT_011f210c.FUN_00403e20());
        FUN_006815c0 rotation;
        rotation.FUN_004a0c90(projectile->scale(false));
        color = FUN_00414430(1.0f, 1.0f, 0.0f, 0.6f);
        geometry =
            FUN_004b3890(projectile->scene()->FUN_0045bb80(), color,
                         projectile->scene()->FUN_0045bb80() + rotation.FUN_004b4500(FUN_00416870(0.0f, 1000.0f, 0.0f)),
                         color, true);
        DAT_011dea10->FUN_00458e20(geometry, *DAT_011f210c.FUN_00403e20());
    }
    if (projectile)
        ((P062Queued*)DAT_011f1958->FUN_00825c00(projectile))->UpdateExplosion();
    return projectile;
}

namespace fnv_009bda10 {
struct SystemSettings
{
    bool FUN_0042ce10();
};
extern SystemSettings* DAT_011ddf38;
struct TimingState
{
    void* FUN_004fd400();
    float FUN_009a7c40();
    float FUN_00644790();
};
struct StateFlags
{
    int FUN_004fd4f0();
};
struct SpawnedResource
{
    SpawnedResource();
    unsigned int field000;
    unsigned int field004;
    unsigned int field008;
    unsigned int field00C;
    unsigned int field010;
    unsigned int field014;
    unsigned int field018;
    unsigned int field01C;
    unsigned int field020;
    unsigned int field024;
    unsigned int field028;
    unsigned int field02C;
    unsigned int field030;
    unsigned int field034;
    unsigned int field038;
    unsigned int field03C;
    unsigned int field040;
    unsigned int field044;
    unsigned int field048;
    unsigned int field04C;
    unsigned int field050;
    unsigned int field054;
    unsigned int field058;
    unsigned int field05C;
    unsigned int field060;
    unsigned int field064;
    unsigned int field068;
    unsigned int field06C;
    unsigned int field070;
    unsigned int field074;
    unsigned int field078;
    unsigned int field07C;
    unsigned int field080;
    unsigned int field084;
    unsigned int field088;
    unsigned int field08C;
    unsigned int field090;
    unsigned int field094;
    unsigned int field098;
    unsigned int field09C;
    unsigned int field0A0;
    unsigned int field0A4;
    unsigned int field0A8;
    unsigned int field0AC;
    unsigned int field0B0;
    unsigned int field0B4;
    unsigned int field0B8;
    unsigned int field0BC;
    unsigned int field0C0;
    unsigned int field0C4;
    unsigned int field0C8;
    unsigned int field0CC;
    unsigned int field0D0;
    unsigned int field0D4;
    unsigned int field0D8;
    unsigned int field0DC;
    unsigned int field0E0;
    unsigned int field0E4;
    unsigned int field0E8;
    unsigned int field0EC;
    unsigned int field0F0;
    unsigned int field0F4;
    unsigned int field0F8;
    unsigned int field0FC;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10C;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11C;
    unsigned int field120;
    unsigned int field124;
    unsigned int field128;
    unsigned int field12C;
    unsigned int field130;
    unsigned int field134;
    unsigned int field138;
    unsigned int field13C;
    unsigned int field140;
    unsigned int field144;
    unsigned int field148;
    unsigned int field14C;
    unsigned int field150;
    unsigned int field154;
    unsigned int field158;
    unsigned int field15C;
    unsigned int field160;
    unsigned int field164;
    unsigned int field168;
    unsigned int field16C;
    unsigned int field170;
    unsigned int field174;
    unsigned int field178;
    unsigned int field17C;
    unsigned int field180;
    unsigned int field184;
    unsigned int field188;
    unsigned int field18C;
    unsigned int field190;
    unsigned int field194;
    unsigned int field198;
    unsigned int field19C;
    unsigned int field1A0;
    unsigned int field1A4;
    unsigned int field1A8;
    unsigned int field1AC;
    unsigned int field1B0;
    unsigned int field1B4;
    unsigned int field1B8;
    unsigned int field1BC;
    unsigned int field1C0;
    unsigned int field1C4;
    unsigned int field1C8;
    unsigned int field1CC;
    unsigned int field1D0;
    unsigned int field1D4;
    unsigned int field1D8;
    unsigned int field1DC;
    unsigned int field1E0;
    unsigned int field1E4;
    unsigned int field1E8;
    unsigned int field1EC;
    unsigned int field1F0;
    unsigned int field1F4;
    unsigned int field1F8;
    unsigned int field1FC;
    unsigned int field200;
    unsigned int field204;
    unsigned int field208;
    unsigned int field20C;
    unsigned int field210;
    unsigned int field214;
    unsigned int field218;
    unsigned int field21C;
    unsigned int field220;
    unsigned int field224;
    unsigned int field228;
    unsigned int field22C;
    unsigned int field230;
    unsigned int field234;
    unsigned int field238;
    unsigned int field23C;
    unsigned int field240;
    unsigned int field244;
    unsigned int field248;
    unsigned int field24C;
    unsigned int field250;
    unsigned int field254;
    unsigned int field258;
    unsigned int field25C;
    unsigned int field260;
    unsigned int field264;
    unsigned int field268;
    unsigned int field26C;
    unsigned int field270;
    unsigned int field274;
    unsigned int field278;
    unsigned int field27C;
    unsigned int field280;
    unsigned int field284;
    unsigned int field288;
    unsigned int field28C;
    unsigned int field290;
    unsigned int field294;
    unsigned int field298;
    unsigned int field29C;
    unsigned int field2A0;
    unsigned int field2A4;
    unsigned int field2A8;
    unsigned int field2AC;
    unsigned int field2B0;
    unsigned int field2B4;
    unsigned int field2B8;
    unsigned int field2BC;
    unsigned int field2C0;
    unsigned int field2C4;
    unsigned int field2C8;
    unsigned int field2CC;
    unsigned int field2D0;
    unsigned int field2D4;
    unsigned int field2D8;
    unsigned int field2DC;
    unsigned int field2E0;
    unsigned int field2E4;
    unsigned int field2E8;
    unsigned int field2EC;
    unsigned int field2F0;
    unsigned int field2F4;
    unsigned int field2F8;
    unsigned int field2FC;
    unsigned int field300;
    unsigned int field304;
    unsigned int field308;
    unsigned int field30C;
    unsigned int field310;
    unsigned int field314;
    unsigned int field318;
    unsigned int field31C;
    unsigned int field320;
    unsigned int field324;
    unsigned int field328;
    unsigned int field32C;
    unsigned int field330;
    unsigned int field334;
    unsigned int field338;
    unsigned int field33C;
    unsigned int field340;
    unsigned int field344;
    unsigned int field348;
    unsigned int field34C;
    unsigned int field350;
    unsigned int field354;
    unsigned int field358;
    unsigned int field35C;
    unsigned int field360;
    unsigned int field364;
    unsigned int field368;
    unsigned int field36C;
    unsigned int field370;
    unsigned int field374;
    unsigned int field378;
    unsigned int field37C;
    unsigned int field380;
    unsigned int field384;
    unsigned int field388;
    unsigned int field38C;
    unsigned int field390;
    unsigned int field394;
    unsigned int field398;
    unsigned int field39C;
    unsigned int field3A0;
    unsigned int field3A4;
    unsigned int field3A8;
    unsigned int field3AC;
    unsigned int field3B0;
    unsigned int field3B4;
    unsigned int field3B8;
    unsigned int field3BC;
    unsigned int field3C0;
    unsigned int field3C4;
    unsigned int field3C8;
    unsigned int field3CC;
    unsigned int field3D0;
    unsigned int field3D4;
    unsigned int field3D8;
    unsigned int field3DC;
    unsigned int field3E0;
    unsigned int field3E4;
    unsigned int field3E8;
    unsigned int field3EC;
    unsigned int field3F0;
    unsigned int field3F4;
    unsigned int field3F8;
    unsigned int field3FC;
    unsigned int field400;
    unsigned int field404;
    unsigned int field408;
    unsigned int field40C;
    unsigned int field410;
    unsigned int field414;
    unsigned int field418;
    unsigned int field41C;
    unsigned int field420;
    unsigned int field424;
    unsigned int field428;
    unsigned int field42C;
    unsigned int field430;
    unsigned int field434;
    unsigned int field438;
    unsigned int field43C;
    unsigned int field440;
    unsigned int field444;
    unsigned int field448;
    unsigned int field44C;
    unsigned int field450;
    unsigned int field454;
    unsigned int field458;
    unsigned int field45C;
    unsigned int field460;
    unsigned int field464;
    unsigned int field468;
    int FUN_0045cd60();
};
struct ActionTarget
{
    void FUN_00476ab0();
};
struct CameraObject
{
    void FUN_00548230(void*, int);
};
struct GameVector;
struct ActionObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned int GetAmount();
    virtual ActionTarget* GetTarget();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void ApplyVector(GameVector*, int);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsEnabled();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual bool IsType();
    bool FUN_008bbc10();
};
struct ModifierSource
{
    bool IsFlag4Set();
};
struct RuntimeSettings
{
    float* FUN_00403e20();
};
extern RuntimeSettings DAT_011ce5f4;
struct RuntimeQueue
{
    void FUN_0096d450(void*, int, int, int, int);
    void* GetOffset70Ptr();
};

struct ProjectileRuntime;
struct RuntimeObserver
{
    void FUN_005ae3d0(ProjectileRuntime* const&);
};
struct GameVector
{
    GameVector(float, int, int);
    float x, y, z;
};
extern float DAT_011c3c08;
extern int DAT_011dea3c;
extern bool __cdecl FUN_004753d0(void*);
extern void __cdecl FUN_00b6bb30(unsigned int, float);

extern void* __cdecl operator new(unsigned int);
struct ActionConsumer
{
    void MarkGeometryDataMutable(ActionObject*);
};
struct ProjectileRuntime : Projectile
{
    void FUN_009bda10();
    bool FUN_00576d30();
    bool FUN_00444d00(unsigned int);
    int FUN_00476c90();
    TimingState* FUN_004181e0();
    void FUN_009bdf60(void*);
    StateFlags* FUN_007af430();
    void FUN_004846a0(int);
    void FUN_00484ab0(int);
    void FUN_005de0a0(int, int);
    void* FUN_008d6f30();
    void FUN_009bdff0();
    void FUN_009c3d90();
    void FUN_009c2ff0();
    bool FUN_009c40c0();
    bool FUN_009bdf80();
    void FUN_009c0090();
    void FUN_009bd860();
    void UpdateNodePlacement();
    void FUN_009bec90();

    virtual void projSlot1();
    virtual void projSlot2();
    virtual void projSlot3();
    virtual void projSlot4();
    virtual void projSlot5();
    virtual void projSlot6();
    virtual void projSlot7();
    virtual void projSlot8();
    virtual void projSlot9();
    virtual void projSlot10();
    virtual void projSlot11();
    virtual void projSlot12();
    virtual void projSlot13();
    virtual void projSlot14();
    virtual void projSlot15();
    virtual void projSlot16();
    virtual void projSlot17();
    virtual void projSlot18();
    virtual void projSlot19();
    virtual void projSlot20();
    virtual void projSlot21();
    virtual void projSlot22();
    virtual void projSlot23();
    virtual void projSlot24();
    virtual void projSlot25();
    virtual void projSlot26();
    virtual void projSlot27();
    virtual void projSlot28();
    virtual void projSlot29();
    virtual void projSlot30();
    virtual void projSlot31();
    virtual void projSlot32();
    virtual void projSlot33();
    virtual void projSlot34();
    virtual void projSlot35();
    virtual void projSlot36();
    virtual void projSlot37();
    virtual void projSlot38();
    virtual void projSlot39();
    virtual void projSlot40();
    virtual void projSlot41();
    virtual void projSlot42();
    virtual void projSlot43();
    virtual void projSlot44();
    virtual void projSlot45();
    virtual void projSlot46();
    virtual void projSlot47();
    virtual void projSlot48();
    virtual void projSlot49();
    virtual void projSlot50();
    virtual void projSlot51();
    virtual void projSlot52();
    virtual void projSlot53();
    virtual void projSlot54();
    virtual void projSlot55();
    virtual void projSlot56();
    virtual void projSlot57();
    virtual void projSlot58();
    virtual void projSlot59();
    virtual void projSlot60();
    virtual void projSlot61();
    virtual void projSlot62();
    virtual void projSlot63();
    virtual void projSlot64();
    virtual void projSlot65();
    virtual void projSlot66();
    virtual void projSlot67();
    virtual void projSlot68();
    virtual void projSlot69();
    virtual void projSlot70();
    virtual void projSlot71();
    virtual void projSlot72();
    virtual void projSlot73();
    virtual void projSlot74();
    virtual void projSlot75();
    virtual void projSlot76();
    virtual void projSlot77();
    virtual void projSlot78();
    virtual void projSlot79();
    virtual void projSlot80();
    virtual void projSlot81();
    virtual void projSlot82();
    virtual void projSlot83();
    virtual void projSlot84();
    virtual void projSlot85();
    virtual void projSlot86();
    virtual void projSlot87();
    virtual void projSlot88();
    virtual void projSlot89();
    virtual void projSlot90();
    virtual void projSlot91();
    virtual void projSlot92();
    virtual void projSlot93();
    virtual void projSlot94();
    virtual void projSlot95();
    virtual void projSlot96();
    virtual void projSlot97();
    virtual void projSlot98();
    virtual void projSlot99();
    virtual void projSlot100();
    virtual void projSlot101();
    virtual void projSlot102();
    virtual void projSlot103();
    virtual void projSlot104();
    virtual void projSlot105();
    virtual void projSlot106();
    virtual void projSlot107();
    virtual void projSlot108();
    virtual void projSlot109();
    virtual void projSlot110();
    virtual void projSlot111();
    virtual void projSlot112();
    virtual void UpdateAction();
    virtual void projSlot114();
    virtual void projSlot115();
    virtual ActionObject* GetAction();
    virtual void projSlot117();
    virtual void projSlot118();
    virtual void projSlot119();
    virtual void projSlot120();
    virtual void projSlot121();
    virtual void projSlot122();
    virtual void projSlot123();
    virtual void projSlot124();
    virtual void projSlot125();
    virtual void projSlot126();
    virtual void projSlot127();
    virtual void projSlot128();
    virtual void projSlot129();
    virtual void projSlot130();
    virtual void projSlot131();
    virtual void projSlot132();
    virtual void projSlot133();
    virtual void projSlot134();
    virtual void projSlot135();
    virtual void projSlot136();
    virtual void projSlot137();
    virtual void SetTarget(int);
    virtual void projSlot139();
    virtual void projSlot140();
    virtual void projSlot141();
    virtual void projSlot142();
    virtual void projSlot143();
    virtual void projSlot144();
    virtual void projSlot145();
    virtual void projSlot146();
    virtual void projSlot147();
    virtual void projSlot148();
    virtual void projSlot149();
    virtual void projSlot150();
    virtual void projSlot151();
    virtual void projSlot152();
    virtual void projSlot153();
    virtual void projSlot154();
    virtual void projSlot155();
    virtual void projSlot156();
    virtual void projSlot157();
    virtual void projSlot158();
    virtual void projSlot159();
    virtual void projSlot160();
    virtual void projSlot161();
    virtual void projSlot162();
    virtual void projSlot163();
    virtual void projSlot164();
    virtual void projSlot165();
    virtual void projSlot166();
    virtual void projSlot167();
    virtual void projSlot168();
    virtual void projSlot169();
    virtual void projSlot170();
    virtual void projSlot171();
    virtual void projSlot172();
    virtual void projSlot173();
    virtual void projSlot174();
    virtual void projSlot175();
    virtual void projSlot176();
    virtual void projSlot177();
    virtual void projSlot178();
    virtual void projSlot179();
    virtual void projSlot180();
    virtual void projSlot181();
    virtual void projSlot182();
    virtual void projSlot183();
    virtual void projSlot184();
    virtual void projSlot185();
    virtual void projSlot186();
    virtual void projSlot187();
    virtual void projSlot188();
    virtual void projSlot189();
    virtual void projSlot190();
    virtual void projSlot191();
    virtual void projSlot192();
    virtual void projSlot193();
    virtual void projSlot194();
    virtual void FinalizeAction();
};

// @fnv 0x009bda10
void ProjectileRuntime::FUN_009bda10()
{
    bool inactive = DAT_011ddf38->FUN_0042ce10() || FUN_00576d30() || FUN_00444d00(0x10000);
    if (!FUN_00476c90())
    {
        FUN_009bdf60(FUN_004181e0()->FUN_004fd400());
    }
    if (FUN_004753d0(FUN_007af430()))
    {
        FUN_004846a0(1);
    }
    FUN_00484ab0(1);
    FUN_005de0a0(0x10000, 1);
    if (FUN_00874480(reinterpret_cast<char*>(this)) && !inactive)
    {
        SetTarget(reinterpret_cast<int>(
            reinterpret_cast<ProjectileRuntime*>(FUN_00874480(reinterpret_cast<char*>(this)))->FUN_008d6f30()));
    }
    byte118 = 0;
    unsigned char newlyCreated = word68 == 0;
    if (newlyCreated)
    {
        word68 = reinterpret_cast<unsigned int>(new SpawnedResource);
    }
    if (!FUN_00444d00(2) && word68 != 0)
    {
        if (reinterpret_cast<SpawnedResource*>(word68)->FUN_0045cd60() <= 1)
        {
            if (!GetAction())
                FUN_009bdff0();
            UpdateAction();
            if (GetAction())
            {
                if (GetAction()->GetTarget())
                {
                    GetAction()->GetTarget()->FUN_00476ab0();
                }
                else
                {
                    FUN_00b6bb30(GetAction()->GetAmount(), 1.0f);
                }
            }
        }
    }
    if (FUN_008d6f30())
    {
        reinterpret_cast<CameraObject*>(FUN_008d6f30())->FUN_00548230(this, 0);
    }
    FUN_009c3d90();
    if (!inactive)
        FUN_009c2ff0();
    if (newlyCreated)
        DAT_011e0e80.FUN_0096d450(this, 0, 0, 0, 0);
    if (FUN_00444d00(0x80))
    {
        RuntimeObserver* observer =
            static_cast<RuntimeObserver*>(reinterpret_cast<RuntimeQueue*>(&DAT_011e0e80)->GetOffset70Ptr());
        if (observer)
        {
            observer->FUN_005ae3d0(this);
        }
    }
    floatD4 = FUN_004181e0()->FUN_009a7c40();
    if (!inactive && wordFC && reinterpret_cast<ActionObject*>(wordFC)->IsEnabled())
    {
        ActionObject* current = reinterpret_cast<ActionObject*>(wordFC);
        if (current->IsType() && current->FUN_008bbc10() && wordF8 &&
            reinterpret_cast<ModifierSource*>(wordF8)->IsFlag4Set())
        {
            floatD4 *= *DAT_011ce5f4.FUN_00403e20();
        }
    }
    bool skipUpdateB = false;
    if (!inactive && FUN_00444d00(0x100))
    {
        skipUpdateB = FUN_009c40c0();
    }
    if (!FUN_009bdf80())
    {
        floatE4 = FUN_004181e0()->FUN_00644790();
    }
    if (!skipUpdateB && !inactive)
    {
        FUN_009c0090();
        if (FUN_00874480(reinterpret_cast<char*>(this)) == DAT_011dea3c)
            FUN_009bd860();
        UpdateNodePlacement();
        if (FUN_00444d00(1))
            FUN_009bec90();
    }
    StateFlags* flags5 = FUN_007af430();
    if (flags5->FUN_004fd4f0() == 0x40000)
    {
        ActionConsumer* firstOwner = reinterpret_cast<ActionConsumer*>(this);
        firstOwner->MarkGeometryDataMutable(GetAction());
    }
    else if (flags5->FUN_004fd4f0() == 0x100000)
    {
        ActionConsumer* secondOwner = reinterpret_cast<ActionConsumer*>(this);
        secondOwner->MarkGeometryDataMutable(GetAction());
    }
    FinalizeAction();
    if (GetAction())
    {
        GameVector parameters(DAT_011c3c08, 1, 0);
        GetAction()->ApplyVector(&parameters, 0);
    }
    visualB = static_cast<NiAVObject*>(0);
}
}  // namespace fnv_009bda10

namespace fnv_009bf190 {
struct ActionState
{
    bool FUN_004fd420();
};
struct UIManager
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void AdvanceFade();
    virtual void Unused4();
    virtual void Unused5();
    virtual void Unused6();
    virtual void Unused7();
    virtual void Unused8();
    virtual void Unused9();
    virtual void Unused10();
    virtual void Unused11();
    virtual void Unused12();
    virtual void Unused13();
    virtual void Unused14();
    virtual void Unused15();
    virtual void Unused16();
    virtual void ShowMenu(void* owner, int, int, int, int, int);
    virtual void Unused18();
    virtual void Unused19();
    virtual void Unused20();
    virtual void Unused21();
    virtual void Unused22();
    virtual void Unused23();
    virtual void Unused24();
    virtual void Unused25();
    virtual void Unused26();
    virtual void Unused27();
    virtual void Unused28();
    virtual void Unused29();
    virtual void Unused30();
    virtual void Unused31();
    virtual void Unused32();
    virtual void Unused33();
    virtual void Unused34();
    virtual void Unused35();
    virtual void Unused36();
    virtual void Unused37();
    virtual void Unused38();
    virtual void Unused39();
    virtual void Unused40();
    virtual void Unused41();
    virtual void Unused42();
    virtual void Unused43();
    virtual void Unused44();
    virtual void Unused45();
    virtual void Unused46();
    virtual void Unused47();
    virtual void Unused48();
    virtual void Unused49();
    virtual void Unused50();
    virtual void Unused51();
    virtual void Unused52();
    virtual void Unused53();
    virtual void Unused54();
    virtual void Unused55();
    virtual void Unused56();
    virtual void Unused57();
    virtual void Unused58();
    virtual void Unused59();
    virtual void Unused60();
    virtual void Unused61();
    virtual void Unused62();
    virtual void Unused63();
    virtual void Unused64();
    virtual void Unused65();
    virtual void Unused66();
    virtual void Unused67();
    virtual void Unused68();
    virtual void Unused69();
    virtual void Unused70();
    virtual void Unused71();
    virtual void Unused72();
    virtual void Unused73();
    virtual void Unused74();
    virtual void Unused75();
    virtual void Unused76();
    virtual void Unused77();
    virtual void Unused78();
    virtual void Unused79();
    virtual void Unused80();
    virtual void Unused81();
    virtual void Unused82();
    virtual void Unused83();
    virtual void Unused84();
    virtual void Unused85();
    virtual void Unused86();
    virtual void Unused87();
    virtual void Unused88();
    virtual void Unused89();
    virtual void Unused90();
    virtual void Unused91();
    virtual void Unused92();
    virtual void Unused93();
    virtual void Unused94();
    virtual void Unused95();
    virtual void Unused96();
    virtual void Unused97();
    virtual void Unused98();
    virtual void Unused99();
    virtual void Unused100();
    virtual void Unused101();
    virtual void Unused102();
    virtual void Unused103();
    virtual void Unused104();
    virtual void Unused105();
    virtual void Unused106();
    virtual void Unused107();
    virtual void Unused108();
    virtual void Unused109();
    virtual void Unused110();
    virtual void Unused111();
    virtual void Unused112();
    virtual void Unused113();
    virtual void Unused114();
    virtual void Unused115();
    virtual void Unused116();
    virtual void Unused117();
    virtual void Unused118();
    virtual void Unused119();
    virtual void Unused120();
    virtual void Unused121();
    virtual void Unused122();
    virtual void Unused123();
    virtual void Unused124();
    virtual void Unused125();
    virtual void Unused126();
    virtual void Unused127();
    virtual void Unused128();
    virtual void Unused129();
    virtual void Unused130();
    virtual void Unused131();
    virtual void Unused132();
    virtual void Unused133();
    virtual void Unused134();
    virtual void Unused135();
    virtual void Unused136();
    virtual void Unused137();
    virtual void Unused138();
    virtual void Unused139();
    virtual void Unused140();
    virtual void Unused141();
    virtual void Unused142();
    virtual void Unused143();
    virtual void Unused144();
    virtual void Unused145();
    virtual void Unused146();
    virtual void Unused147();
    virtual void Unused148();
    virtual void Unused149();
    virtual void Unused150();
    virtual void Unused151();
    virtual void Unused152();
    virtual void Unused153();
    virtual void Unused154();
    virtual void Unused155();
    virtual void Unused156();
    virtual void Unused157();
    virtual void Unused158();
    virtual void Unused159();
    virtual void Unused160();
    virtual void Unused161();
    virtual void Unused162();
    virtual void Unused163();
    virtual void Unused164();
    virtual void Unused165();
    virtual void Unused166();
    virtual void Unused167();
    virtual void Unused168();
    virtual void SetMenuData(void* owner, int mode, int, int, int, int);
    virtual void Unused170();
    virtual void Unused171();
    virtual void Unused172();
    virtual void Unused173();
    virtual void Unused174();
    virtual void Unused175();
    virtual void Unused176();
    virtual void Unused177();
    virtual void Unused178();
    virtual void Unused179();
    virtual void Unused180();
    virtual void Unused181();
    virtual void Unused182();
    virtual void Unused183();
    virtual void Unused184();
    virtual void Unused185();
    virtual void Unused186();
    virtual void Unused187();
    virtual void Unused188();
    virtual void Unused189();
    virtual void Unused190();
    virtual void Unused191();
    virtual void Unused192();
    virtual void Unused193();
    virtual void Unused194();
    virtual void Unused195();
    virtual void Unused196();
    virtual void Unused197();
    virtual void Unused198();
    virtual void Unused199();
    virtual void Unused200();
    virtual void Unused201();
    virtual void Unused202();
    virtual void Unused203();
    virtual void Unused204();
    virtual void Unused205();
    virtual void Unused206();
    virtual void Unused207();
    virtual void Unused208();
    virtual void Unused209();
    virtual void Unused210();
    virtual void Unused211();
    virtual void Unused212();
    virtual void Unused213();
    virtual void Unused214();
    virtual void Unused215();
    virtual void Unused216();
    virtual void Unused217();
    virtual void Unused218();
    virtual void Unused219();
    virtual void Unused220();
    virtual void Unused221();
    virtual void Unused222();
    virtual void Unused223();
    virtual void Unused224();
    virtual void SetEnabled(int);
};
struct MenuObject
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void AdvanceFade();
    virtual void Unused4();
    virtual void Unused5();
    virtual void Unused6();
    virtual void Unused7();
    virtual void Unused8();
    virtual void Unused9();
    virtual void Unused10();
    virtual void Unused11();
    virtual void Unused12();
    virtual void Unused13();
    virtual void Unused14();
    virtual void Unused15();
    virtual void Unused16();
    virtual void Unused17();
    virtual void Unused18();
    virtual void Unused19();
    virtual void Unused20();
    virtual void Unused21();
    virtual void Unused22();
    virtual void Unused23();
    virtual void Unused24();
    virtual void Unused25();
    virtual void Unused26();
    virtual void Unused27();
    virtual void Unused28();
    virtual void Unused29();
    virtual void Unused30();
    virtual void Unused31();
    virtual void Unused32();
    virtual void Unused33();
    virtual void Unused34();
    virtual void Unused35();
    virtual void Unused36();
    virtual void Unused37();
    virtual void Unused38();
    virtual void Unused39();
    virtual void Unused40();
    virtual void Unused41();
    virtual void Unused42();
    virtual void Unused43();
    virtual void Unused44();
    virtual void Unused45();
    virtual void Unused46();
    virtual void Unused47();
    virtual void Unused48();
    virtual void Unused49();
    virtual void Unused50();
    virtual void Unused51();
    virtual void Unused52();
    virtual void Unused53();
    virtual void Unused54();
    virtual void Unused55();
    virtual void Unused56();
    virtual void Unused57();
    virtual void Unused58();
    virtual void Unused59();
    virtual void Unused60();
    virtual void Unused61();
    virtual void Unused62();
    virtual void Unused63();
    virtual bool CanShow();
    UIManager* FUN_008d8520();
};
struct GameScreen
{
    bool FUN_00444d00(unsigned int);
    ActionState* FUN_004181e0(unsigned int);
    double FUN_00885bd0();
    void FUN_005de0a0(unsigned int, int);
    MenuObject* FUN_009b4440();
    void FUN_009bf190();
};
extern Setting_S DAT_011ced88;
struct UIController
{
    UIController* FUN_00825c00(GameScreen*);
    void UpdateExplosion();
};
extern UIController* DAT_011f1958;
int __cdecl GetTopicSubTypeName(int, int);

// @fnv 0x009bf190
void GameScreen::FUN_009bf190()
{
    int menuData;
    MenuObject* currentMenu;
    if (FUN_00444d00(0x400))
    {
        if (!FUN_004181e0(0x400)->FUN_004fd420())
        {
            if (FUN_00885bd0() > *DAT_011ced88.Float())
            {
                if (!FUN_00444d00(0x800))
                {
                    FUN_005de0a0(0x800, 1);
                    DAT_011f1958->FUN_00825c00(this)->UpdateExplosion();
                    if (FUN_009b4440())
                    {
                        if (FUN_009b4440()->CanShow())
                        {
                            currentMenu = FUN_009b4440();
                            if (currentMenu->FUN_008d8520())
                            {
                                currentMenu->FUN_008d8520()->SetEnabled(1);
                                menuData = GetTopicSubTypeName(2, 5);
                                currentMenu->FUN_008d8520()->SetMenuData(currentMenu, menuData, 0, 0, 0, 0);
                                currentMenu->FUN_008d8520()->ShowMenu(currentMenu, 0, 2, 1, 1, 1);
                            }
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_009bf190

struct Vec
{
    float x, y, z;
    Vec FUN_004a0bd0() const;
    void FUN_004a0c10();
    Vec operator-(Vec const&) const;
    Vec operator+(Vec const&) const;
    Vec operator*(float) const;
};
struct WorldObject
{
    void* GetReferenceFlags();
    void FUN_00c90510();
};
struct Collision
{
    WorldObject* FUN_006fa820();
};
struct BodyPart
{
    Collision* FUN_006838b0();
};
struct NodeName
{
    const char* FUN_0043b1b0();
};
struct Node
{
    NodeName& FUN_00413f40();
    void FUN_00a5a040();
    void FUN_00440460(Vec const&);
};
struct Obj
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
    virtual bool IsActor();
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
    virtual const char* GetName();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec& GetPosition();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void Mark(bool);
    BodyPart* FUN_008b3d70(Vec, Vec);
    int FUN_008b3ef0(BodyPart*);
    void FUN_00564db0(bool);
    int FUN_00474cb0();
    const char* FUN_0055d520();
    unsigned FUN_0084e3a0();
    int GetNextListItem();
};
struct CF845
{
    CF845(int);
    bool FUN_00624070();
    int FUN_004a3a20();
    int FUN_0043b4d0();
    int value;
};
struct Shape
{
    int FUN_00c84f10(int);
};
struct Buffer
{
    int FUN_0043b540();
    void* FUN_004b59d0();
    int FUN_004b5980();
    void* FUN_00559450();
};
struct Body
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual BodyPart* v3();
};
Body* __cdecl FUN_004b5820(Buffer*);
struct Wrapper
{
    void* FUN_00559450();
    int value;
};
struct Ref
{
    Node* FUN_0044ddc0();
};
Ref* __cdecl FUN_004b5260(void*);
Shape* __cdecl FUN_004a3a40(void*);
struct Hit
{
    Obj* ref;
    Vec point, normal;
    void* collision;
    int material, part;
    bool unk28, unk29;
    short unk2a, unk2c;
    Hit();
};
struct DebugSetting
{
    unsigned char* FUN_00408d60();
};
extern DebugSetting g_011f20b8, g_011f20ec;
struct FloatSetting
{
    float* FUN_00403e20();
};
extern FloatSetting g_011f210c;
struct Impact
{
    void SpawnGroupNodeNearPlayer();
};
struct TESProxy
{
    int FUN_00457880(Vec const&);
    Impact* FUN_0070ec90(Vec, float);
    void FUN_00458e20(Node*, float);
};
extern TESProxy* g_TES;
struct Queue
{
    void FUN_0087b760(float, Vec const*);
};
Queue* __cdecl FUN_004537b0();
bool __cdecl FUN_008c7aa0();
void __cdecl FUN_0040fbe0(const char*, ...);
struct RefPair
{
    Obj* ref;
    Wrapper node;
};
struct Creature
{
    float FUN_00821640();
};
struct HitList
{
    void FUN_005ae3d0(Hit*&);
    int head, next;
};
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float r, g, b, a;
};
Node* __cdecl CreateOctahedron(float, ImageSpaceEffectParam const&, bool);
Node* __cdecl FUN_004b3890(Vec const&, ImageSpaceEffectParam const&, Vec const&, ImageSpaceEffectParam const&, bool);
struct ProjectileHit
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual int Kind();
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
    HitList hits;
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
    Obj* target;
    Vec position;
    bool FUN_00444d00(int);
    RefPair* FUN_008d8b80();
    int FUN_009c0070();
    void SetField(int);
    float FUN_00885bd0();
    Creature* FUN_00476c90();
    Obj* FUN_00874480();
    void FUN_009ab9a0(Obj*);
    bool ProcessHit(Obj*, Vec const&, Vec const&, Buffer*, int, int);
};
// @fnv 0x009bf5a0
bool ProjectileHit::ProcessHit(Obj* object, Vec const& point, Vec const& normal, Buffer* buffer, int index,
                               int material)
{
    Hit* hit = (Hit*)new FUN_009bffb0;
    if (FUN_00444d00(0x1000) && target && hit->ref != target)
    {
        hit->ref = target;
        hit->collision = 0;
        hit->point = target->GetPosition();
        hit->normal = position.FUN_004a0bd0();
        hit->normal.FUN_004a0c10();
        hit->part = 0;
        hit->material = 0;
        if (target->IsActor())
        {
            hit->material = 6;
            Obj* actor = target;
            BodyPart* body = actor->FUN_008b3d70(hit->point - position, hit->point);
            if (body)
            {
                hit->part = actor->FUN_008b3ef0(body);
                Collision* collision = body->FUN_006838b0();
                hit->collision = collision->FUN_006fa820() ? collision->FUN_006fa820()->GetReferenceFlags() : 0;
            }
            if (hit->collision)
                ((WorldObject*)hit->collision)->FUN_00c90510();
        }
    }
    else
    {
        hit->ref = object;
        hit->point = point;
        hit->normal = normal;
        hit->collision = buffer ? buffer->FUN_004b59d0() : 0;
        if (hit->collision)
        {
            ((WorldObject*)hit->collision)->FUN_00c90510();
            if (object && object->IsActor() && buffer->FUN_004b5980() == 1 &&
                CF845(buffer->FUN_0043b540()).FUN_00624070())
            {
                Body* body = FUN_004b5820(buffer);
                Obj* actor = object;
                hit->part = actor->FUN_008b3ef0(body->v3());
            }
        }
        int hitMaterial = material;
        if (buffer && material == 0x24)
        {
            bool special = CF845(buffer->FUN_0043b540()).FUN_004a3a20() == 1;
            if (special)
                hitMaterial = g_TES->FUN_00457880(point);
            else
            {
                Shape* shape = FUN_004a3a40(buffer->FUN_00559450());
                if (shape)
                    hitMaterial = shape->FUN_00c84f10(index);
            }
            if (CF845(buffer->FUN_0043b540()).FUN_0043b4d0() == 11)
                hitMaterial = 8;
        }
        hit->material = hitMaterial;
        if (hitMaterial == 8)
        {
            if (!FUN_008c7aa0())
                g_TES->FUN_0070ec90(point, 0.01f)->SpawnGroupNodeNearPlayer();
            else
                FUN_004537b0()->FUN_0087b760(0.01f, &point);
        }
    }
    bool valid = true;
    if (*g_011f20b8.FUN_00408d60() && FUN_008d8b80())
    {
        Body* expectedObject = FUN_004b5820(buffer);
        Ref* ref = FUN_004b5260(FUN_008d8b80()->node.FUN_00559450());
        Node* expected = ref ? ref->FUN_0044ddc0() : 0;
        Obj* actual = FUN_008d8b80()->ref;
        valid = object == actual && (void*)expectedObject == (void*)expected;
        FUN_0040fbe0("Targetted VATS Projectile Result: %s", valid ? "SUCCESS" : "FAILURE");
        FUN_0040fbe0("Target Ref ID:\t%s %08X", actual->FUN_00474cb0() ? actual->GetName() : actual->FUN_0055d520(),
                     actual->FUN_0084e3a0());
        FUN_0040fbe0("Target Part:\t%s", expected ? expected->FUN_00413f40().FUN_0043b1b0() : "");
        FUN_0040fbe0("Hit Ref ID:\t\t%s %08X",
                     object ? (object->FUN_00474cb0() ? object->GetName() : object->FUN_0055d520()) : "Land",
                     object ? object->FUN_0084e3a0() : 0);
        FUN_0040fbe0("Hit Part:\t\t%s\n", expectedObject ? ((Node*)expectedObject)->FUN_00413f40().FUN_0043b1b0() : "");
    }
    if (hit->ref)
        hit->ref->FUN_00564db0(true);
    if (Kind() == 5)
    {
        ProjectileHit* projectile = this;
        if (projectile)
        {
            int count = projectile->FUN_009c0070();
            if (FUN_00885bd0() > count / FUN_00476c90()->FUN_00821640())
            {
                Obj* actor = FUN_00874480();
                if (actor)
                    actor->Mark(true);
                projectile->SetField(count + 1);
                if (hit->ref && hit->ref->IsActor())
                    hit->unk29 = true;
                else
                    hit->unk29 = false;
                if (actor->GetNextListItem() < 1)
                    projectile->FUN_009ab9a0(actor);
            }
            else
                hit->unk29 = false;
        }
    }
    if (*g_011f20ec.FUN_00408d60() || *g_011f20b8.FUN_00408d60())
    {
        ImageSpaceEffectParam color(0, 0, 1, 0.1f);
        if (hit->ref && hit->ref->IsActor())
            color = ImageSpaceEffectParam(0, 1, 0, 0.1f);
        if (!valid)
            color = ImageSpaceEffectParam(1, 0, 0, 0.65f);
        if (hit->unk29)
            color = ImageSpaceEffectParam(0.5f, 0, 0, 0.65f);
        Node* node = CreateOctahedron(5.0f, color, true);
        node->FUN_00a5a040();
        node->FUN_00440460(hit->point);
        g_TES->FUN_00458e20(node, *g_011f210c.FUN_00403e20());
        node = FUN_004b3890(hit->point, color, hit->point + hit->normal * 24.0f, color, true);
        g_TES->FUN_00458e20(node, *g_011f210c.FUN_00403e20());
    }
    hits.FUN_005ae3d0(hit);
    return true;
}

struct ZPoint
{
    float x, y, z;
    ZPoint();
    void FUN_004a0c90(float);
};
struct ZMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ZMatrix();
    void FUN_004a0c90(float);
};
struct ZHit
{
    int unk00;
    ZPoint position;
    ZPoint normal;
};
struct ZList
{
    ZHit** _ref_006815c0();
    bool _ref_008256d0();
    int unk00, unk04;
};
struct ZScene
{
    bool FUN_00456610();
    ZMatrix* _ref_00461130();
};
struct ZExplosion
{
    float FUN_006a78f0();
    void* FUN_004fb810();
};
struct ZBase
{
    bool FUN_004fd360();
    ZExplosion* FUN_004fd3c0();
    bool GetHasExplosionAltTrigger() const;
    float GetExplosionProximity() const;
    bool GetHasExplosionDetonates() const;
    int FUN_004fd4f0();
};
struct ZSetting
{
    float* Float();
};
extern ZSetting originalRuntimeFloatSetting686, originalRuntimeFloatSetting687, originalRuntimeFloatSetting688;
struct ZIntSetting
{
    int* Int();
};
extern ZIntSetting g_011d0fe4;
struct ZMode
{
    unsigned int FUN_0044ddc0();
};
extern ZMode DAT_011f2250;
extern ZMatrix DAT_011a9448;
extern int DAT_01030e48;
struct ZObject;
struct ZProcess
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
    virtual void event(ZObject*, ZPoint, void*, int, ZObject*);
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void v453();
    virtual void v454();
    virtual void v455();
    virtual void v456();
    virtual void v457();
    virtual void v458();
    virtual void hit(ZObject*, float);
};
struct ZObject
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
    virtual bool IsActor();
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual ZScene* GetScene();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual ZPoint* GetPosition();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void Release();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool IsPlayer();
    ZProcess* FUN_008d8520();
    void Kill(ZObject*, float);
};
extern ZObject* _g_thePlayer;
struct ZResult
{
    void FUN_0089d640(ZPoint);
    void FUN_00476c70(unsigned int);
};
struct ZProjectile : ZObject
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    ZList impacts;
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
    float timere4;
    float timere8;
    ZBase* FUN_004181e0();
    bool FUN_00444d00(int);
    bool FUN_009c39e0();
    void FUN_005726e0(ZScene*, bool);
    void InitSoundFromArchetype();
    void StopSound();
    void FUN_009c6380(ZScene*, ZPoint*);
    void* FUN_008d6f30();
    ZObject* FUN_00874480();
    unsigned int FUN_00476c90();
    void FUN_009bc8f0();
    ZObject* FUN_009b4440();
    void UpdateDetonation(float elapsed);
};
ZScene* FUN_004aae30(ZScene*, int*);
float FUN_004a4240();
ZMatrix FUN_00c4b8a0(ZPoint);
ZResult* CreateProjectileRef(ZExplosion*, ZObject*, int, void*, ZPoint, ZMatrix);
void FUN_004d5c60(int);
// @fnv 0x009c3190
void ZProjectile::UpdateDetonation(float elapsed)
{
    if (FUN_004181e0()->FUN_004fd360() && FUN_004181e0()->FUN_004fd3c0() && !FUN_00444d00(0x200))
    {
        bool detonate2 = false;
        if (FUN_004181e0()->GetHasExplosionAltTrigger())
        {
            if (timere4 != 3.4028234663852886e38 || FUN_004181e0()->GetExplosionProximity() == 0.0 || FUN_009c39e0())
            {
                timere4 -= elapsed;
                if (timere4 <= 0.0)
                    detonate2 = true;
                else
                {
                    timere8 -= elapsed;
                    if (timere8 <= 0.0)
                    {
                        ZScene* marker = FUN_004aae30(GetScene(), &DAT_01030e48);
                        if (marker)
                            FUN_005726e0(GetScene(), marker->FUN_00456610());
                        if (timere4 > *originalRuntimeFloatSetting686.Float())
                            timere8 = *originalRuntimeFloatSetting687.Float();
                        else
                            timere8 =
                                *originalRuntimeFloatSetting688.Float() +
                                (timere4 / *originalRuntimeFloatSetting686.Float()) *
                                    (*originalRuntimeFloatSetting687.Float() - *originalRuntimeFloatSetting688.Float());
                        InitSoundFromArchetype();
                    }
                }
            }
            else
                StopSound();
        }
        else if (FUN_00444d00(0x100000))
            detonate2 = true;
        else if (!FUN_004181e0()->GetHasExplosionDetonates() && !impacts._ref_008256d0())
            detonate2 = true;
        if (detonate2)
        {
            ZPoint position8;
            ZMatrix rotationX;
            if ((*g_011d0fe4.Int() > 0 || FUN_00444d00(0x2000)) && !impacts._ref_008256d0())
            {
                ZHit* impact8 = *impacts._ref_006815c0();
                float angle = FUN_004a4240();
                ZMatrix temp;
                temp.FUN_004a0c90(angle);
                rotationX = FUN_00c4b8a0(impact8->normal);
                position8 = impact8->position;
            }
            else
            {
                position8 = *GetPosition();
                rotationX = GetScene() ? *GetScene()->_ref_00461130() : DAT_011a9448;
                FUN_009c6380(GetScene(), &position8);
            }
            void* cell6 = FUN_008d6f30();
            ZResult* result3 =
                CreateProjectileRef(FUN_004181e0()->FUN_004fd3c0(), !FUN_00444d00(0x400) ? FUN_00874480() : 0, 0, cell6,
                                    position8, rotationX);
            if (result3 && !impacts._ref_008256d0() && FUN_004181e0()->FUN_004fd4f0() == 0x10000)
                result3->FUN_0089d640((*impacts._ref_006815c0())->normal);
            if (result3 && FUN_00476c90())
                result3->FUN_00476c70(FUN_00476c90());
            if (FUN_00444d00(0x8000))
            {
                if (DAT_011f2250.FUN_0044ddc0() == 4)
                    Release();
                FUN_009bc8f0();
            }
            if (FUN_004181e0()->FUN_004fd3c0()->FUN_006a78f0() > 0.0 && FUN_00444d00(0x400) && FUN_009b4440() &&
                FUN_009b4440()->IsActor())
            {
                ZObject* victim = FUN_009b4440();
                ZObject* killer3 = FUN_00874480() && FUN_00874480()->IsActor() ? FUN_00874480() : 0;
                if (killer3->IsPlayer())
                {
                    FUN_004d5c60(14);
                    if (victim->FUN_008d8520())
                        victim->FUN_008d8520()->hit(_g_thePlayer, DAT_01022958);
                }
                victim->Kill(killer3, 0.0f);
                _g_thePlayer->FUN_008d8520()->event(_g_thePlayer, *victim->GetPosition(),
                                                    FUN_004181e0()->FUN_004fd3c0()->FUN_004fb810(), 2, victim);
            }
        }
    }
}

namespace fnv_009c4b60 {
class RecursiveSpinLock
{
};
struct GlobalObject_0096a2d0
{
    void Lock(const char*);
};
struct BSSpinLockUnlock
{
    void Unlock();
};
class ActorDeletionQueue
{
  public:
    void FUN_0096d470(MobileObject*, int);
};
struct Host096d450
{
    void FUN_0096d450(MobileObject*, int, bool, bool, bool);
};
enum PROCESS_TYPE
{
    PROCESS_TYPE_Default = 0
};
struct BaseProcess
{
    PROCESS_TYPE GetProcessLevel();
};
class Base_0092c950
{
  public:
    virtual ~Base_0092c950();
    virtual void FUN_0092c950(Base_0092c950*);
    Base_0092c950();

  private:
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
};
extern RecursiveSpinLock DAT_011f11a0;
extern ActorDeletionQueue DAT_011e0e80;
struct FUN_009c4b60_shell : public MobileObject
{
    bool FUN_009c4b60();
};

// @fnv 0x009c4b60
bool FUN_009c4b60_shell::FUN_009c4b60()
{
    ((GlobalObject_0096a2d0*)&DAT_011f11a0)->Lock(0);
    if (this->word68 != 0)
    {
        PROCESS_TYPE level = ((BaseProcess*)this->word68)->GetProcessLevel();
        DAT_011e0e80.FUN_0096d470(this, level);
    }
    Base_0092c950* newProcess = new Base_0092c950();
    newProcess->FUN_0092c950((Base_0092c950*)this->word68);

    delete (Base_0092c950*)this->word68;
    this->word68 = (unsigned int)newProcess;
    ((Host096d450*)&DAT_011e0e80)->FUN_0096d450(this, 3, 0, 0, 0);
    ((BSSpinLockUnlock*)&DAT_011f11a0)->Unlock();
    return true;
}
}  // namespace fnv_009c4b60

struct RemForm;

struct RemEntry
{
    RemForm* pForm;
};

struct RemListNode
{
    RemEntry* pItem;
    RemListNode* pNext;

    bool IsEmpty();
    RemEntry** GetItem();
    RemListNode* GetNext();
};

struct RemPending
{
    RemForm* pForm;

    ~RemPending();
};

struct RemOwner
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
    RemListNode kList;

    RemForm* FUN_009b4440();
    void FUN_00420ba0(int aiValue);
    bool FUN_00444d00(int aiFlag);
    void FUN_009bc8f0();
    RemForm* FUN_00874480();
    RemPending* FUN_008d8b80();
    void SetWhich(RemPending* apPending);
    void FUN_009c4c80(RemForm* apForm);
};

// @fnv 0x009c4c80
void RemOwner::FUN_009c4c80(RemForm* apForm)
{
    if (FUN_009b4440() == apForm)
    {
        FUN_00420ba0(0);
        if (FUN_00444d00(0x400))
            FUN_009bc8f0();
    }

    if (!kList.IsEmpty())
    {
        bool bFound4 = false;
        RemListNode* pIter6 = &kList;
        while (!bFound4 && pIter6 && !pIter6->IsEmpty())
        {
            RemEntry* pEntry = *pIter6->GetItem();
            pIter6 = pIter6->GetNext();
            if (pEntry->pForm == apForm)
            {
                FUN_009bc8f0();
                bFound4 = true;
            }
        }
    }

    if (FUN_00874480() == apForm)
        FUN_009bc8f0();

    if (FUN_008d8b80() && FUN_008d8b80()->pForm == apForm)
    {
        delete FUN_008d8b80();
        SetWhich(0);
    }
}

class TESObjectWEAP : public TESForm
{
};
TESForm* __cdecl LookupFormByID(unsigned int);
ActorCause* __cdecl FindStateByValue(unsigned int);
struct LoadBuf52 : BGSLoadFormBuffer
{
    unsigned int FUN_008648a0();
    void FUN_00864a20(void*, unsigned int);
    unsigned int FUN_00864a60();
};
struct FUN_0076b630
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0076b630();
    ~FUN_0076b630();
    void FUN_004bee00(LoadBuf52*);
    unsigned int FUN_0044ddc0();
    void ClearExtraDataList();
    void* FUN_004459e0(unsigned int);
};
struct List52
{
    void FUN_00905820(FUN_009bffb0*&);
};
struct LoadProjectile52 : Projectile
{
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual int v116();
    void FUN_00932a00(LoadBuf52*);
    void LoadProjectile(LoadBuf52*);
};
// Loads projectile fields from a save buffer, including weapon, position, transform, cause, an optional extra object and a list of items, gated by version.
// @fnv 0x009c52f0
void LoadProjectile52::LoadProjectile(LoadBuf52* buffer)
{
    FUN_00932a00(buffer);
    buffer->ReadTypedData(&wordC8, 4);
    buffer->ReadTypedData(&floatCC, 4);
    buffer->ReadTypedData(&floatD4, 4);
    buffer->ReadTypedData(&floatD0, 4);
    buffer->ReadTypedData(&floatD8, 4);
    buffer->ReadTypedData(&floatDC, 4);
    buffer->ReadTypedData(&floatE0, 4);
    buffer->ReadTypedData(&floatE4, 4);
    buffer->ReadTypedData(&floatE8, 4);
    wordF8 = (unsigned int)dynamic_cast<TESObjectWEAP*>(LookupFormByID(buffer->FUN_008648a0()));
    buffer->ReadFormIdentifier(&wordFC);
    buffer->ReadFormIdentifier(&word100);
    buffer->ReadTypedData(&position, 12);
    buffer->ReadTypedData(&float110, 4);
    buffer->ReadTypedData(&byte118, 1);
    buffer->ReadTypedData(&float124, 4);
    buffer->FUN_00864a20(&transform, 36);
    if (buffer->GetVersion() >= 13)
    {
        buffer->ReadTypedData(&transform.storage[36], 12);
        buffer->ReadTypedData(&transform.storage[48], 4);
    }
    if (buffer->GetVersion() >= 8)
    {
        buffer->ReadTypedData(&floatEC, 4);
        buffer->ReadTypedData(&floatF0, 4);
    }
    if (buffer->GetVersion() >= 14)
        buffer->ReadTypedData(&floatF4, 4);
    unsigned int causeId = -1;
    buffer->ReadTypedData(&causeId, 4);
    cause = FindStateByValue(causeId);
    if (buffer->GetVersion() >= 3)
    {
        bool hasExtra = false;
        buffer->ReadTypedData(&hasExtra, 1);
        if (hasExtra)
        {
            word144 = (unsigned int)new FUN_0076b630;
            ((FUN_0076b630*)word144)->FUN_004bee00(buffer);
            if (!((FUN_0076b630*)word144)->FUN_0044ddc0())
            {
                ((FUN_0076b630*)word144)->ClearExtraDataList();
                delete (FUN_0076b630*)word144;
                word144 = 0;
            }
        }
    }
    if (buffer->GetVersion() >= 14)
    {
        unsigned int count = buffer->FUN_00864a60();
        for (unsigned int index = 0; index < count; ++index)
        {
            FUN_009bffb0* item = new FUN_009bffb0;
            ((FUN_009bba90_shell*)item)->FUN_009bba90(buffer);
            if (!v116())
                item->m_28 = 0;
            ((List52*)&list)->FUN_00905820(item);
        }
    }
    if (buffer->GetVersion() >= 16)
        buffer->ReadTypedData(&byte90, 1);
}

TESForm* __cdecl LookupFormByID(unsigned int auiFormId);

struct LoadItem9c5
{
    void FUN_009a4f40(BGSLoadFormBuffer* pkBuffer);
};

struct LoadNode9c5
{
    LoadItem9c5* m_item;
    LoadNode9c5* m_pkNext;

    LoadItem9c5*& FUN_006815c0();
};

LoadNode9c5* __fastcall FUN_00726070(LoadNode9c5* pkNode);

struct LoadExtra9c5
{
    void FUN_004bef60(BGSLoadFormBuffer* pkBuffer);
};

struct FUN_009c5740_shell
{
    char pad000[0x88];
    LoadNode9c5 m_kList;
    char pad090[0xfc - 0x90];
    TESObjectREFR* m_pkRef0;
    TESObjectREFR* m_pkRef1;
    char pad104[0x144 - 0x104];
    LoadExtra9c5* m_pkExtra;

    void FUN_00932b70(BGSLoadFormBuffer* pkBuffer);
    void LoadForm(BGSLoadFormBuffer* pkBuffer);
};

// Loads the form via FUN_00932b70, resolves m_pkRef0/m_pkRef1, loads m_pkExtra, and for version >= 0xe iterates m_kList loading each item.
// @fnv 0x009c5740
void FUN_009c5740_shell::LoadForm(BGSLoadFormBuffer* pkBuffer)
{
    FUN_00932b70(pkBuffer);
    m_pkRef0 = m_pkRef0 ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)m_pkRef0)) : 0;
    m_pkRef1 = m_pkRef1 ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)m_pkRef1)) : 0;
    if (m_pkExtra)
        m_pkExtra->FUN_004bef60(pkBuffer);
    if (pkBuffer->GetVersion() >= 0xe)
    {
        LoadNode9c5* pkNode = &m_kList;
        while (pkNode)
        {
            LoadItem9c5* pkItem = pkNode->FUN_006815c0();
            if (pkItem)
                pkItem->FUN_009a4f40(pkBuffer);
            pkNode = FUN_00726070(pkNode);
        }
    }
}

namespace fnv_009bf470 {
struct V3;
struct Pt9bf
{
    float x, y, z;
};
class NiAVObject;
struct FUN_00440460_S
{
    void FUN_00440460(const V3*);
};
class TESObjectREFR
{
  public:
    const NiPoint3& GetAngleOnReference() const;
};
class B006815c0
{
  public:
    B006815c0();
    float m[9];
    void FUN_00a59660(float, float, float);
};
struct ST_00a59400
{
    void FUN_00a59400(float*, float*, float*);
};
struct FUN_00444d00_Class
{
    bool FUN_00444d00(int);
};
struct FUN_009b7010_shell
{
    NiPoint3& FUN_009b7010(NiPoint3&);
};
void* __fastcall FUN_006a9540(char*);
float __cdecl FUN_004b54c0(float);
class NiAVObject
{
  public:
    void FUN_0043fa80(const void*);
};

class Ref9bf
{
  public:
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
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual NiAVObject* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual V3* GetPos();
    void UpdateNodeTransform(bool bRotate, bool bAlign);
};

// Updates the 3D node position from GetPos, optionally applies rotation from GetAngleOnReference, and optionally aligns the node when flag 0x40 is set.
// @fnv 0x009bf470
void Ref9bf::UpdateNodeTransform(bool bRotate, bool bAlign)
{
    NiAVObject* pkNodeX = Get3D();
    if (pkNodeX)
    {
        ((FUN_00440460_S*)pkNodeX)->FUN_00440460(GetPos());
        if (bRotate)
        {
            Pt9bf kAngleValue = (const Pt9bf&)((TESObjectREFR*)this)->GetAngleOnReference();
            B006815c0 kRotX;
            kRotX.FUN_00a59660(kAngleValue.z, kAngleValue.x, kAngleValue.y);
            pkNodeX->FUN_0043fa80(&kRotX);
        }
        if (bAlign && ((FUN_00444d00_Class*)this)->FUN_00444d00(0x40))
        {
            B006815c0 kAlign_ = *(B006815c0*)FUN_006a9540((char*)pkNodeX);
            float fX, fNewY, fZ;
            ((ST_00a59400*)&kAlign_)->FUN_00a59400(&fX, &fNewY, &fZ);
            NiPoint3 kNewPos;
            fNewY = -FUN_004b54c0(((Pt9bf&)((FUN_009b7010_shell*)this)->FUN_009b7010(kNewPos)).z);
            kAlign_.FUN_00a59660(fX, fNewY, fZ);
            pkNodeX->FUN_0043fa80(&kAlign_);
        }
    }
}
}  // namespace fnv_009bf470

namespace fnv_009ab390 {
struct PVPoint
{
    float x, y, z;
    PVPoint FUN_00439ef0(const PVPoint& kOther) const;  // operator-
    void FUN_004a0c10();                                // Unitize
};

class FUN_00416870_Offset
{
  public:
    float x, y, z;
    FUN_00416870_Offset(float fX, float fY, float fZ);
};

struct PVCamResult
{
    int unk00;
    int unk04;
    int unk08;
    const PVPoint* FUN_00524c40();
};
class PVCamera
{
  public:
    PVCamResult FUN_00461130(const FUN_00416870_Offset& kIntersectionOffset);
};
PVCamera* FUN_00524c90();

class PVAimNode
{
  public:
    void FUN_00a59400(float* pfYaw, float* pfPitch, float* pfRoll);
};
class PVNode
{
  public:
    PVAimNode* FUN_00461130();
    const PVPoint* FUN_0045bb80();
};

class PVWeapon
{
  public:
    bool HasEffect(int iFlag);
};

class PVProcess
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual PVWeapon* GetLoadedForm();  // +0x148
    virtual void v0x53();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v10a();
    virtual float GetSpread();  // +0x42c
};

class PVPackageData
{
  public:
    bool FUN_00424940();
};
class PVPackage
{
  public:
    PVPackageData* FUN_006758f0();
};

class PVOwner
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual PVNode* GetAimNode();  // +0x20c
    virtual void v0x84();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual float GetCurrentTargetDistance(int iValue);  // +0x2bc
    float FUN_00931d70();
    PVPackage* FUN_009344a0();
    PVProcess* FUN_008d8520();
    float GetCachedSpeed(int iValue);
    bool FUN_008bbc10();
    PVPoint FUN_009ab970();
};
extern PVOwner* DAT_011dea3c;

struct PVWeaponStats
{
    float FUN_00524b80(bool bFlag);
    float FUN_00524be0(bool bFlag);
    bool IsFlag4Set();
};
struct PVFloatSetting
{
    float* FUN_00403e20();
};
extern PVFloatSetting DAT_011ce23c;
float GetDirectionAngle(const PVPoint* pkDir);
float FUN_004b5530(float fValue);
float FUN_00476b70(float fMin, float fScaledValue);
float FUN_004e44b0(float fAngleDifference);
float FUN_004e4470(float fAngleDifference);

class PVModel
{
  public:
    void FUN_0051b840(float fValue);
    void FUN_005bfbd0(float fValue);
};
struct PVModelPtr
{
    PVModel* m_pObject;
    PVModel* FUN_00559450();
};

class PVProjectile
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void* GetNode3D();  // +0x1d0
    virtual void v0x75();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void Unk_30c();  // +0x30c
    virtual void v0xc4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void Unk_328();  // +0x328
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
    PVPoint m_kPos;  // +0x30
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
    PVModelPtr m_spModel;  // +0x150

    bool FUN_00440d80();
    void UpdateDetonation(float fTimeSinceScaleStart);
    PVOwner* FUN_00874480();
    bool FUN_00444d00(int iFlag);
    float GetE0();
    void FUN_009bc8f0();
    PVWeaponStats* FUN_00476c90();
    void FUN_005757d0(float fValue);
    void FUN_00575770(float fValue);
    void FUN_005757a0(float fValue);
    void FUN_00575830(const PVPoint* pkPos);
    void UpdateNodeTransform(int iA, int iB);
    void FUN_009795c0(float fValue);
    float GetFirstLightParameter();
    void FUN_009ab390(float fTimeSinceScaleStart);
};

// @fnv 0x009ab390
void PVProjectile::FUN_009ab390(float fTimeSinceScaleStart)
{
    if (FUN_00440d80())
        return;
    UpdateDetonation(fTimeSinceScaleStart);
    PVOwner* pkActor = FUN_00874480()->IsActor() ? FUN_00874480() : 0;
    PVNode* pkAimNode = FUN_00874480() ? FUN_00874480()->GetAimNode() : 0;
    if (FUN_00444d00(0x20) && GetE0() < 0.01)
        FUN_009bc8f0();
    if (pkActor)
    {
        float fCurrentSpeed = pkActor->FUN_00931d70();
        float fYaw = pkActor->GetCurrentTargetDistance(0);
        if (pkActor == DAT_011dea3c)
        {
            PVPoint kWorldPosition = DAT_011dea3c->FUN_009ab970().FUN_00439ef0(m_kPos);
            kWorldPosition.FUN_004a0c10();
            fYaw = GetDirectionAngle(&kWorldPosition);
            fCurrentSpeed = -FUN_004b5530(kWorldPosition.z);
        }
        else
        {
            float fRoll;
            pkAimNode->FUN_00461130()->FUN_00a59400(&fYaw, &fCurrentSpeed, &fRoll);
        }
        {
            bool bNoSpread = false;
            PVPackage* pkPackageTmp = pkActor ? pkActor->FUN_009344a0() : 0;
            if (pkPackageTmp)
            {
                PVPackageData* pkData = pkPackageTmp->FUN_006758f0();
                if (pkData)
                    bNoSpread = pkData->FUN_00424940();
            }
            else
                bNoSpread = FUN_00444d00(0x1000);
            if (!bNoSpread)
            {
                PVProcess* pkProcess = pkActor ? pkActor->FUN_008d8520() : 0;
                PVWeapon* pkWeaponCur = pkProcess ? pkProcess->GetLoadedForm() : 0;
                float fSkill = pkActor ? pkActor->GetCachedSpeed(1) : *DAT_011ce23c.FUN_00403e20();
                bool bScopedVal = false;
                if (pkActor && pkActor->FUN_008d8520() && pkWeaponCur && pkWeaponCur->HasEffect(3))
                    bScopedVal = true;
                float fBodyPartChance =
                    (FUN_00476c90()->FUN_00524b80(bScopedVal) + FUN_00476c90()->FUN_00524be0(bScopedVal) * fSkill) *
                    0.017453292f;
                float fUnusedTmp = pkActor->GetCachedSpeed(2);
                float fExtraOut = pkActor->FUN_008d8520()->GetSpread();
                fBodyPartChance += fExtraOut;
                float fRadiusBase = FUN_00476b70(0.0f, fBodyPartChance);
                float fAngleDifference = FUN_00476b70(0.0f, 6.2831855f);
                fCurrentSpeed += FUN_004e44b0(fAngleDifference) * fRadiusBase;
                fYaw += FUN_004e4470(fAngleDifference) * fRadiusBase;
            }
        }
        FUN_005757d0(fYaw);
        FUN_00575770(fCurrentSpeed);
        FUN_005757a0(0.0f);
    }
    void* pvNode3D = GetNode3D();
    if (pkAimNode && pvNode3D)
    {
        bool bFirstPerson = false;
        if (FUN_00476c90()->IsFlag4Set() && pkActor->FUN_008bbc10() && pkActor == DAT_011dea3c)
            bFirstPerson = true;
        PVCamera* pkCameraTmp = FUN_00524c90();
        if (bFirstPerson && pkCameraTmp)
        {
            static FUN_00416870_Offset s_kOffset(0.0f, -15.0f, 0.0f);
            FUN_00575830(pkCameraTmp->FUN_00461130(s_kOffset).FUN_00524c40());
        }
        else
            FUN_00575830(((PVNode*)pkAimNode)->FUN_0045bb80());
    }
    UpdateNodeTransform(1, 0);
    FUN_009795c0(10000.0f);
    Unk_328();
    Unk_30c();
    if (m_spModel.FUN_00559450())
    {
        m_spModel.FUN_00559450()->FUN_0051b840(GetE0());
        m_spModel.FUN_00559450()->FUN_005bfbd0(GetFirstLightParameter());
    }
}
}  // namespace fnv_009ab390

extern double DAT_010290d0;

struct Matrix9b34
{
    float m_afEntry[9];
    Matrix9b34 FUN_0043f8d0(const Matrix9b34& kOther) const;
};

struct AVObject9b34
{
    const Matrix9b34& FUN_00461130();
    const NiPoint3& FUN_0045bb80();
};

struct Node9b34
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void* GetUserData();
    void FUN_0043fa80(const Matrix9b34& kRotate);
    void FUN_00440460(const NiPoint3& kTranslate);
    void FUN_00450f90(bool bCulled);
};

void __cdecl FUN_00578060(void* pkObject);
void __cdecl FUN_00578170(void* pkObject);

struct Parent9b34
{
    virtual void P000();
    virtual void P001();
    virtual void P002();
    virtual void P003();
    virtual void P004();
    virtual void P005();
    virtual void P006();
    virtual void P007();
    virtual void P008();
    virtual void P009();
    virtual void P010();
    virtual void P011();
    virtual void P012();
    virtual void P013();
    virtual void P014();
    virtual void P015();
    virtual void P016();
    virtual void P017();
    virtual void P018();
    virtual void P019();
    virtual void P020();
    virtual void P021();
    virtual void P022();
    virtual void P023();
    virtual void P024();
    virtual void P025();
    virtual void P026();
    virtual void P027();
    virtual void P028();
    virtual void P029();
    virtual void P030();
    virtual void P031();
    virtual void P032();
    virtual void P033();
    virtual void P034();
    virtual void P035();
    virtual void P036();
    virtual void P037();
    virtual void P038();
    virtual void P039();
    virtual void P040();
    virtual void P041();
    virtual void P042();
    virtual void P043();
    virtual void P044();
    virtual void P045();
    virtual void P046();
    virtual void P047();
    virtual void P048();
    virtual void P049();
    virtual void P050();
    virtual void P051();
    virtual void P052();
    virtual void P053();
    virtual void P054();
    virtual void P055();
    virtual void P056();
    virtual void P057();
    virtual void P058();
    virtual void P059();
    virtual void P060();
    virtual void P061();
    virtual void P062();
    virtual void P063();
    virtual void P064();
    virtual void P065();
    virtual void P066();
    virtual void P067();
    virtual void P068();
    virtual void P069();
    virtual void P070();
    virtual void P071();
    virtual void P072();
    virtual void P073();
    virtual void P074();
    virtual void P075();
    virtual void P076();
    virtual void P077();
    virtual void P078();
    virtual void P079();
    virtual void P080();
    virtual void P081();
    virtual void P082();
    virtual void P083();
    virtual void P084();
    virtual void P085();
    virtual void P086();
    virtual void P087();
    virtual void P088();
    virtual void P089();
    virtual void P090();
    virtual void P091();
    virtual void P092();
    virtual void P093();
    virtual void P094();
    virtual void P095();
    virtual void P096();
    virtual void P097();
    virtual void P098();
    virtual void P099();
    virtual void P100();
    virtual void P101();
    virtual void P102();
    virtual void P103();
    virtual void P104();
    virtual void P105();
    virtual void P106();
    virtual void P107();
    virtual void P108();
    virtual void P109();
    virtual void P110();
    virtual void P111();
    virtual void P112();
    virtual void P113();
    virtual void P114();
    virtual void P115();
    virtual void P116();
    virtual void P117();
    virtual void P118();
    virtual void P119();
    virtual void P120();
    virtual void P121();
    virtual void P122();
    virtual void P123();
    virtual void P124();
    virtual void P125();
    virtual void P126();
    virtual void P127();
    virtual void P128();
    virtual void P129();
    virtual void P130();
    virtual AVObject9b34* GetAttachNode();
};

struct List9b34
{
    bool FUN_008256d0();
    void* m_pkItem;
    void* m_pkNext;
};

struct Projectile9b34
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual Node9b34* Get3D();
    virtual void W117();
    virtual void W118();
    virtual void W119();
    virtual void W120();
    virtual void W121();
    virtual void W122();
    virtual void W123();
    virtual void W124();
    virtual void W125();
    virtual void W126();
    virtual void W127();
    virtual void W128();
    virtual void W129();
    virtual void W130();
    virtual void W131();
    virtual void W132();
    virtual void W133();
    virtual void W134();
    virtual void W135();
    virtual void W136();
    virtual void W137();
    virtual void W138();
    virtual void W139();
    virtual void W140();
    virtual void W141();
    virtual void W142();
    virtual void W143();
    virtual void W144();
    virtual void W145();
    virtual void W146();
    virtual void W147();
    virtual void W148();
    virtual void W149();
    virtual void W150();
    virtual void W151();
    virtual void W152();
    virtual void W153();
    virtual void W154();
    virtual void W155();
    virtual void W156();
    virtual void W157();
    virtual void W158();
    virtual void W159();
    virtual void W160();
    virtual void W161();
    virtual void W162();
    virtual void W163();
    virtual void W164();
    virtual void W165();
    virtual void W166();
    virtual void W167();
    virtual void W168();
    virtual void W169();
    virtual void W170();
    virtual void W171();
    virtual void W172();
    virtual void W173();
    virtual void W174();
    virtual void W175();
    virtual void W176();
    virtual void W177();
    virtual void W178();
    virtual void W179();
    virtual void W180();
    virtual void W181();
    virtual void W182();
    virtual void W183();
    virtual void W184();
    virtual void W185();
    virtual void W186();
    virtual void W187();
    virtual void W188();
    virtual void W189();
    virtual void W190();
    virtual void W191();
    virtual void W192();
    virtual void W193();
    virtual void W194();
    virtual void W195();
    virtual void W196();
    virtual void W197();
    virtual void W198();
    virtual void W199();
    virtual void W200();
    virtual void W201();
    virtual void UpdateMovement();
    char m_acForm[0x84];
    List9b34 m_kImpacts;
    unsigned char m_bHit;
    char m_acPad91[3];
    Matrix9b34 m_kRotate;
    char m_acPadB8[0x98];
    float m_fXValue;
    bool FUN_00440d80();
    Parent9b34* FUN_00874480();
    void FUN_009c6330(const Matrix9b34& kRotate);
    void FUN_00575830(const NiPoint3& kPosition);
    void UpdateDetonation(float fTimeDelta);
    void FUN_009bc8f0();
    void UpdateProjectile(float fTimeDelta);
};

// @fnv 0x009b34c0
void Projectile9b34::UpdateProjectile(float fTimeDelta)
{
    if (FUN_00440d80())
        return;
    AVObject9b34* pkRoot = FUN_00874480() ? FUN_00874480()->GetAttachNode() : 0;
    Node9b34* pkNode = Get3D();
    if (pkRoot && pkNode)
    {
        pkNode->FUN_0043fa80(m_kRotate.FUN_0043f8d0(pkRoot->FUN_00461130()));
        FUN_009c6330(m_kRotate.FUN_0043f8d0(pkRoot->FUN_00461130()));
        pkNode->FUN_00440460(pkRoot->FUN_0045bb80());
        FUN_00575830(pkRoot->FUN_0045bb80());
    }
    if (m_fXValue == 0.0)
    {
        UpdateMovement();
        UpdateDetonation(fTimeDelta);
    }
    if (m_fXValue == 0.0)
    {
        FUN_00578060(Get3D()->GetUserData());
        Get3D()->FUN_00450f90(false);
    }
    else if (m_fXValue > DAT_010290d0)
    {
        Get3D()->FUN_00450f90(true);
        FUN_00578170(Get3D()->GetUserData());
    }
    m_fXValue += fTimeDelta;
    if (m_fXValue > 1.0)
    {
        if (m_kImpacts.FUN_008256d0() || m_bHit)
            FUN_009bc8f0();
    }
}

class FUN_00865df0_buf
{
  public:
    void FUN_00865df0(void* ref, int unk = 0);
};

class BGSSaveFormBuffer : public FUN_00865df0_buf
{
  public:
    void FUN_00865e50(void* data, unsigned int size, int unk = 0);
    void SaveQuaternion(void* data, unsigned int size, int unk = 0);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int count, unsigned int pos);
};

class ActorCauseHelper
{
  public:
    unsigned int FUN_00825c00();
};

class NiPointerCauseHelper
{
  public:
    ActorCauseHelper* FUN_00559450();
};

class Unk144Helper
{
  public:
    void SavePerkList(BGSSaveFormBuffer* buf);
};

class ItemChangeHelper
{
  public:
    void SaveToBuffer(BGSSaveFormBuffer* buf);
};

class ListNodeHelper
{
  public:
    ListNodeHelper* FUN_006815c0();
    ListNodeHelper* FUN_00726070();
    ItemChangeHelper* item;
};

class ProjectileHelper : public Projectile
{
  public:
    void FUN_00932880(BGSSaveFormBuffer* buf);
    void SaveProjectile(BGSSaveFormBuffer* buf);
};

// Serializes projectile fields, cause reference, optional extra data and item-change list into the save buffer.
// @fnv 0x009c4ff0
void ProjectileHelper::SaveProjectile(BGSSaveFormBuffer* buf)
{
    this->FUN_00932880(buf);
    buf->FUN_00865e50(&this->wordC8, 4, 0);
    buf->FUN_00865e50(&this->floatCC, 4, 0);
    buf->FUN_00865e50(&this->floatD4, 4, 0);
    buf->FUN_00865e50(&this->floatD0, 4, 0);
    buf->FUN_00865e50(&this->floatD8, 4, 0);
    buf->FUN_00865e50(&this->floatDC, 4, 0);
    buf->FUN_00865e50(&this->floatE0, 4, 0);
    buf->FUN_00865e50(&this->floatE4, 4, 0);
    buf->FUN_00865e50(&this->floatE8, 4, 0);
    buf->FUN_00865df0((void*)this->wordF8, 0);
    buf->FUN_00865df0((void*)this->wordFC, 0);
    buf->FUN_00865df0((void*)this->word100, 0);
    buf->FUN_00865e50(&this->position, 0xc, 0);
    buf->FUN_00865e50(&this->float110, 4, 0);
    buf->FUN_00865e50(&this->byte118, 1, 0);
    buf->FUN_00865e50(&this->float124, 4, 0);
    buf->SaveQuaternion(&this->transform, 0x24, 0);
    buf->FUN_00865e50(&this->transform.storage[0x24], 0xc, 0);
    buf->FUN_00865e50(&this->transform.storage[0x30], 4, 0);
    buf->FUN_00865e50(&this->floatEC, 4, 0);
    buf->FUN_00865e50(&this->floatF0, 4, 0);
    buf->FUN_00865e50(&this->floatF4, 4, 0);

    unsigned int causeRef5 = ((NiPointerCauseHelper*)&this->cause)->FUN_00559450()
                                 ? ((NiPointerCauseHelper*)&this->cause)->FUN_00559450()->FUN_00825c00()
                                 : 0xFFFFFFFF;
    buf->FUN_00865e50(&causeRef5, 4, 0);

    bool hasUnkA = (bool)this->word144;
    buf->FUN_00865e50(&hasUnkA, 1, 0);
    if (hasUnkA)
    {
        ((Unk144Helper*)this->word144)->SavePerkList(buf);
    }

    unsigned int count2 = 0;
    unsigned int pos5 = buf->FUN_00865f20();
    ListNodeHelper* curr = (ListNodeHelper*)&this->list;
    while (curr)
    {
        ItemChangeHelper* item = curr->FUN_006815c0()->item;
        if (item)
        {
            item->SaveToBuffer(buf);
            count2++;
        }
        curr = curr->FUN_00726070();
    }
    buf->FUN_00865ff0(count2, pos5);
    buf->FUN_00865e50(&this->byte90, 1, 0);
}

struct LoadBuffer9c58
{
    bool FUN_00562d00();
};

struct ListItem9c58
{
    ~ListItem9c58();
    int m_kNextStreamField[4];
};

struct ItemList9c58
{
    ListItem9c58** FUN_006815c0();
    void FUN_0063f7b0();
    ListItem9c58* m_pkItem;
    ItemList9c58* m_pkNext;
};

bool __fastcall FUN_008256d0(ItemList9c58* pkList);

struct Owned9c58
{
    ~Owned9c58();
    int m_kNextStreamField[4];
};

struct Projectile9c58
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void ResetState();
    char m_acForm[0x84];
    ItemList9c58 m_kChanges;
    unsigned char m_ucFlags90;
    char m_acPad91[3];
    NiTransform m_kTransform;
    unsigned int m_uiStateC8;
    float m_fScaleCC;
    float m_fScaleD0;
    float m_fD4;
    float m_fD8;
    float m_fDC;
    float m_fScaleE0;
    float m_fRangeE4;
    float m_fE8;
    float m_fEC;
    float m_fF0;
    float m_fScaleF4;
    unsigned int m_uiF8;
    unsigned int m_uiFC;
    unsigned int m_ui100;
    NiPoint3 m_kPoint104;
    float m_f110;
    NiPointer<NiAVObject> m_spVisualA;
    unsigned char m_ucFlag118;
    char m_acPad119[3];
    NiPointer<NiAVObject> m_spVisualB;
    NiPointer<ActorCause> m_spCause;
    float m_f124;
    int m_aiSounds[6];
    unsigned int m_ui140;
    Owned9c58* m_pkOwned144;
    void FUN_00932f60(LoadBuffer9c58* pkBuffer);
    void FUN_009c58e0(LoadBuffer9c58* pkBuffer);
};

// Calls FUN_00932f60, clears the change list, resets projectile fields to defaults, deletes m_pkOwned144, and calls ResetState if the buffer check passes.
// @fnv 0x009c58e0
void Projectile9c58::FUN_009c58e0(LoadBuffer9c58* pkBuffer)
{
    FUN_00932f60(pkBuffer);
    while (!FUN_008256d0(&m_kChanges))
    {
        delete *m_kChanges.FUN_006815c0();
        m_kChanges.FUN_0063f7b0();
    }
    m_uiStateC8 = 0;
    m_fScaleCC = 1.0f;
    m_fScaleD0 = 1.0f;
    m_fD4 = 0.0f;
    m_fD8 = 0.0f;
    m_fDC = 0.0f;
    m_fScaleE0 = 1.0f;
    m_f110 = 0.0f;
    m_kPoint104 = NiPoint3::ZERO;
    m_uiF8 = 0;
    m_uiFC = 0;
    m_ui100 = 0;
    m_spVisualA = 0;
    m_spVisualB = 0;
    m_spCause = 0;
    m_ucFlag118 = 0;
    m_f124 = 0.0f;
    m_fRangeE4 = DAT_01016970;
    m_fE8 = 0.0f;
    m_fScaleF4 = 1.0f;
    m_ucFlags90 = 0;
    m_kTransform.ResetToIdentity();
    m_ui140 = 0;
    delete m_pkOwned144;
    m_pkOwned144 = 0;
    if (pkBuffer->FUN_00562d00())
        ResetState();
}

namespace fnv_009b41b0 {
struct SoundDataDummy
{
    int v0;
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    int v9;
    int v10;
    int v11;
};

struct SoundObj
{
    SoundDataDummy CopyBig();
    char* FUN_00511840();
};

struct BGSProjectile
{
    SoundObj* FUN_004fd3e0();
    bool FUN_00975300();
    float FUN_0045cd80();
    bool FUN_005de080();
};

struct BSSndHStruct
{
    unsigned int m0;
    bool m4;
    unsigned char m0b;
    int m8;
    BSSndHStruct();
    ~BSSndHStruct();
    bool SetPositionFromArray(NiPoint3*);
    bool Play(bool);
};

struct BSAudio
{
    BSSndHStruct FUN_00ad7480(const char*, unsigned int, SoundObj*);
};
struct BSAudioS
{
    static BSAudio* GetSingleton();
};

struct FloatSetting
{
    float* Float();
};
struct DataHandler
{
    bool FUN_00469860(unsigned int);
};

extern "C" char DAT_011cee0c;
extern "C" char DAT_011cf534;
extern "C" void* DAT_011c3f2c;

unsigned int FUN_005dbe10();
void FUN_00c6a3d0(void*, unsigned int, int, int);
int GetFlagMask(int);

struct S9b41b0
{
    char pad0[0x14c];
    bool b150;
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
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* v1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* v1f4();
    bool FUN_00440d80();
    float FUN_00885bd0();
    unsigned FUN_0084e3a0();
    S9b41b0* FUN_009b4440();
    void FUN_009bc8f0();
    void FUN_009bf190();
    bool FUN_00444d00(int);
    void FUN_00575830(NiPoint3 const&);
    void UpdateDetonation(float);
    BGSProjectile* FUN_004181e0();
    void Update(float t);
};

// Updates state, may play a sound once, selects f from state and settings, then calls UpdateDetonation(t).
// @fnv 0x009b41b0
void S9b41b0::Update(float afTime)
{
    if (FUN_00440d80())
        return;
    if (!b150 && FUN_00885bd0() > 1.0)
    {
        FUN_00c6a3d0(v1d0(), FUN_005dbe10(), 1, 0);
        b150 = 1;
        if (FUN_004181e0() && FUN_004181e0()->FUN_004fd3e0() &&
            !GetFlagMask(FUN_004181e0()->FUN_004fd3e0()->CopyBig().v4))
        {
            BSSndHStruct h = BSAudioS::GetSingleton()->FUN_00ad7480(FUN_004181e0()->FUN_004fd3e0()->FUN_00511840(),
                                                                    0x102, FUN_004181e0()->FUN_004fd3e0());
            h.SetPositionFromArray(v1f4());
            h.Play(false);
        }
    }
    float f;
    f = 0.0f;
    if (FUN_004181e0()->FUN_00975300() && FUN_004181e0()->FUN_0045cd80() > 0.0)
        f = *((FloatSetting*)&DAT_011cee0c)->Float();
    else if (FUN_004181e0()->FUN_005de080())
        f = *((FloatSetting*)&DAT_011cee0c)->Float();
    else
        f = *((FloatSetting*)&DAT_011cf534)->Float();
    if (f != 0.0 && f < FUN_00885bd0() && ((DataHandler*)DAT_011c3f2c)->FUN_00469860(FUN_0084e3a0()))
        FUN_009bc8f0();
    if (FUN_00444d00(0x400) && FUN_009b4440())
    {
        FUN_009bf190();
        FUN_00575830(*FUN_009b4440()->v1f4());
    }
    UpdateDetonation(afTime);
}
}  // namespace fnv_009b41b0

class NiPoint3B300
{
  public:
    float x;
    float y;
    float z;

    NiPoint3B300* FUN_00416870(float fX, float fY, float fZ);
};

class ObjB300
{
  public:
    float FUN_009669c0();
    void ApplySpeedAndVector(float fScale, NiPoint3B300 kVec);
    void ApplyScale(float fScale);
};

// Scales the object's speed by fScale along the Y axis and applies the resulting vector via ApplySpeedAndVector.
// @fnv 0x009bf300
void ObjB300::ApplyScale(float fScale)
{
    float fA = fScale;
    NiPoint3B300 kVec;
    kVec.FUN_00416870(0.0f, FUN_009669c0() * fA, 0.0f);
    ApplySpeedAndVector(fA, kVec);
}

namespace fnv_009c39e0 {
struct Vector3
{
    float unk00, unk04, unk08;
    Vector3 FUN_00439ef0(const Vector3&) const;
    float FUN_004a7290() const;
};
struct Virtuals
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00C();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01C();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02C();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03C();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04C();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05C();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06C();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07C();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08C();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09C();
    virtual void unk0A0();
    virtual void unk0A4();
    virtual void unk0A8();
    virtual void unk0AC();
    virtual void unk0B0();
    virtual void unk0B4();
    virtual void unk0B8();
    virtual void unk0BC();
    virtual void unk0C0();
    virtual void unk0C4();
    virtual void unk0C8();
    virtual void unk0CC();
    virtual void unk0D0();
    virtual void unk0D4();
    virtual void unk0D8();
    virtual void unk0DC();
    virtual void unk0E0();
    virtual void unk0E4();
    virtual void unk0E8();
    virtual void unk0EC();
    virtual void unk0F0();
    virtual void unk0F4();
    virtual void unk0F8();
    virtual void unk0FC();
    virtual bool IsActor();
    virtual void unk104();
    virtual void unk108();
    virtual void unk10C();
    virtual void unk110();
    virtual void unk114();
    virtual void unk118();
    virtual void unk11C();
    virtual void unk120();
    virtual void unk124();
    virtual void unk128();
    virtual void unk12C();
    virtual void unk130();
    virtual void unk134();
    virtual void unk138();
    virtual void unk13C();
    virtual void unk140();
    virtual void unk144();
    virtual void unk148();
    virtual void unk14C();
    virtual void unk150();
    virtual void unk154();
    virtual void unk158();
    virtual void unk15C();
    virtual void unk160();
    virtual void unk164();
    virtual void unk168();
    virtual void unk16C();
    virtual void unk170();
    virtual void unk174();
    virtual void unk178();
    virtual void unk17C();
    virtual void unk180();
    virtual void unk184();
    virtual void unk188();
    virtual void unk18C();
    virtual void unk190();
    virtual void unk194();
    virtual void unk198();
    virtual void unk19C();
    virtual bool IsDead(int);
    virtual void unk1A4();
    virtual void unk1A8();
    virtual void unk1AC();
    virtual void unk1B0();
    virtual void unk1B4();
    virtual void unk1B8();
    virtual void unk1BC();
    virtual void unk1C0();
    virtual void unk1C4();
    virtual void unk1C8();
    virtual void unk1CC();
    virtual void unk1D0();
    virtual void unk1D4();
    virtual void unk1D8();
    virtual void unk1DC();
    virtual void unk1E0();
    virtual void unk1E4();
    virtual void unk1E8();
    virtual void unk1EC();
    virtual void unk1F0();
    virtual const Vector3& Position();
    virtual void unk1F8();
    virtual void unk1FC();
    virtual void unk200();
    virtual void unk204();
    virtual void unk208();
    virtual void unk20C();
    virtual void unk210();
    virtual void unk214();
    virtual bool IsCreature();
};
struct ActorValues
{
    int FUN_0066ef20(int);
};
struct Actor : Virtuals
{
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
    ActorValues unkA4;
    bool FUN_0087f390();
    bool FUN_008ace90();
};
struct ActorBase
{
    float FUN_0045cd80();
    float FUN_00644790();
};
struct Cell
{
    bool FUN_00425fd0();
};
struct Form
{
    int FUN_00401170();
};
union SettingValue
{
    float value;
    int integer;
};
struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011cf7e0, DAT_011cf7ac;
extern Actor* DAT_011dea3c;
struct Actors
{
    unsigned int FUN_005be5c0(int);
    Actor* FUN_00968670(unsigned int);
};
struct Manager
{
    Actors* FUN_00717e50();
};
extern Manager DAT_011e0e80;
void __cdecl FUN_005e58f0(int, Actor*, ActorBase*, float*);
unsigned int __cdecl FUN_00487f50();
struct Proj : Virtuals
{
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
    float unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    Actor* unkFC;
    ActorBase* FUN_004181e0();
    Cell* FUN_008d6f30();
    Form* FUN_00567790();
    bool FUN_00444d00(unsigned int);
    void FUN_005de0a0(unsigned int, bool);
    bool IsFightReactionAllowed(Actor*, Actor*, Form*);
    bool FUN_009c39e0();
};
// Checks for an eligible actor within radius; if none is found, checks the player with a chance roll.
// @fnv 0x009c39e0
bool Proj::FUN_009c39e0()
{
    float radius1 = FUN_004181e0()->FUN_0045cd80();
    if (FUN_008d6f30() && !FUN_008d6f30()->FUN_00425fd0())
        radius1 *= *DAT_011cf7e0.FUN_00403e20();
    float radiusSq2 = radius1 * radius1;
    Actor* candidate1 = 0;
    bool found = false;
    Actor* ownerActor53 = 0;
    Form* ownerForm4 = 0;
    if (unkFC && unkFC->IsActor())
        ownerActor53 = unkFC;
    else
    {
        Form* owner = FUN_00567790();
        if (owner)
        {
            int type = owner->FUN_00401170();
            if (type == 8)
                ownerForm4 = owner;
        }
    }
    for (unsigned int i = 0; i < DAT_011e0e80.FUN_00717e50()->FUN_005be5c0(0); ++i)
    {
        candidate1 = DAT_011e0e80.FUN_00717e50()->FUN_00968670(i);
        Actor* actor = (candidate1 && candidate1->IsActor()) ? candidate1 : 0;
        if (!actor)
            continue;
        if (actor->FUN_0087f390())
            continue;
        if (actor->IsDead(0))
            continue;
        if (actor->FUN_008ace90())
            continue;
        float distance = candidate1->Position().FUN_00439ef0(Position()).FUN_004a7290();
        if (distance < radiusSq2 && IsFightReactionAllowed(actor, ownerActor53, ownerForm4))
        {
            found = true;
            break;
        }
    }
    if (!FUN_00444d00(0x4000) && !found)
    {
        candidate1 = DAT_011dea3c;
        float distancePlayer = candidate1->Position().FUN_00439ef0(Position()).FUN_004a7290();
        if (distancePlayer < radiusSq2 && IsFightReactionAllowed(DAT_011dea3c, ownerActor53, ownerForm4))
        {
            float chance = 100.0f;
            FUN_005e58f0(4, DAT_011dea3c, FUN_004181e0(), &chance);
            if (FUN_00487f50() % 100 < (unsigned int)chance)
                found = true;
            else
                FUN_005de0a0(0x4000, true);
        }
    }
    if (found && candidate1)
    {
        if (candidate1->IsCreature() || candidate1 == DAT_011dea3c)
            unkE4 = *DAT_011cf7ac.FUN_00403e20() +
                    FUN_004181e0()->FUN_00644790() * candidate1->unkA4.FUN_0066ef20(35) / 100.0f;
        else
            unkE4 = *DAT_011cf7ac.FUN_00403e20();
    }
    return found;
}
}  // namespace fnv_009c39e0

struct FUN_009bbc40 : Projectile
{
    virtual ~FUN_009bbc40();
};

// @fnv 0x009bbc40
FUN_009bbc40::~FUN_009bbc40()
{}

namespace fnv_009bc470 {
struct NiNode;
class NiAVObject
{
  public:
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual NiNode* GetNiNode();
};

bool FUN_005784b0(NiNode*);
void FUN_00578170(NiNode*);

class TESActorBase;
class Actor;
class TESObjectREFR
{
  public:
    NiAVObject* Get3DSimple();
    virtual void Set3D(NiNode*, bool);
};

class FUN_009c4f90_This
{
  public:
    void StopSound();
};

class BGSProjectile
{
  public:
    bool FUN_009bc870();
};

class BSSoundHandleEx : public SoundPlaybackHandle
{
  public:
    bool FUN_00ad8da0(int);
};

class VATS
{
  public:
    void* FUN_00441110();
    void FUN_009c8b90(int);
    void* FUN_007af430();
    void SetValue(int);
};
extern VATS DAT_011f2250;

class FUN_00444d00_Class
{
  public:
    bool FUN_00444d00(int);
};

class FUN_009bc470;

template <class T> class BSSimpleListEx : public BSSimpleList<T>
{
  public:
    void Remove(const T&);
    bool FUN_008256d0();
    struct Node
    {
        T data;
    };
    Node* FUN_006815c0();
    void FUN_0063f7b0();
};

class FUN_004610f0_Class
{
  public:
    BSSimpleListEx<FUN_009bc470*>* GetOffset70Ptr();
};
extern FUN_004610f0_Class DAT_011e0e80;

class BaseProcess
{
  public:
    virtual void p0(), p1(), p2(), p3(), p4(), p5(), p6(), p7(), p8(), p9();
    virtual void p10(), p11(), p12(), p13(), p14(), p15(), p16(), p17(), p18(), p19();
    virtual void p20(), p21(), p22(), p23(), p24(), p25(), p26(), p27(), p28(), p29();
    virtual void p30(), p31(), p32(), p33(), p34(), p35(), p36(), p37(), p38(), p39();
    virtual void p40(), p41(), p42(), p43(), p44(), p45(), p46(), p47(), p48(), p49();
    virtual void p50(), p51(), p52(), p53(), p54(), p55(), p56(), p57(), p58(), p59();
    virtual void p60(), p61(), p62(), p63(), p64(), p65(), p66(), p67(), p68(), p69();
    virtual void p70(), p71(), p72(), p73(), p74(), p75(), p76(), p77(), p78(), p79();
    virtual void p80(), p81(), p82(), p83(), p84(), p85(), p86(), p87(), p88(), p89();
    virtual void p90(), p91(), p92(), p93(), p94(), p95(), p96(), p97(), p98(), p99();
    virtual void p100(), p101(), p102(), p103(), p104(), p105(), p106(), p107(), p108(), p109();
    virtual void p110(), p111(), p112(), p113(), p114(), p115(), p116(), p117(), p118(), p119();
    virtual void p120(), p121(), p122(), p123(), p124(), p125(), p126(), p127(), p128(), p129();
    virtual void p130(), p131(), p132(), p133(), p134(), p135(), p136(), p137(), p138(), p139();
    virtual void p140(), p141(), p142(), p143(), p144(), p145(), p146(), p147(), p148(), p149();
    virtual void p150(), p151(), p152(), p153(), p154(), p155(), p156(), p157(), p158(), p159();
    virtual void p160(), p161(), p162(), p163(), p164(), p165(), p166(), p167(), p168(), p169();
    virtual void p170(), p171(), p172(), p173(), p174(), p175(), p176(), p177(), p178(), p179();
    virtual void p180(), p181(), p182(), p183(), p184(), p185(), p186(), p187(), p188(), p189();
    virtual void p190(), p191(), p192(), p193(), p194(), p195(), p196(), p197(), p198(), p199();
    virtual void p200(), p201(), p202(), p203(), p204(), p205(), p206(), p207(), p208(), p209();
    virtual void p210(), p211(), p212(), p213(), p214(), p215(), p216(), p217(), p218(), p219();
    virtual void p220(), p221(), p222(), p223(), p224();
    virtual void Virtual384(int);
};

class Actor
{
  public:
    virtual void a0(), a1(), a2(), a3(), a4(), a5(), a6(), a7(), a8(), a9();
    virtual void a10(), a11(), a12(), a13(), a14(), a15(), a16(), a17(), a18(), a19();
    virtual void a20(), a21(), a22(), a23(), a24(), a25(), a26(), a27(), a28(), a29();
    virtual void a30(), a31(), a32(), a33(), a34(), a35(), a36(), a37(), a38(), a39();
    virtual void a40(), a41(), a42(), a43(), a44(), a45(), a46(), a47(), a48(), a49();
    virtual void a50(), a51(), a52(), a53(), a54(), a55(), a56(), a57(), a58(), a59();
    virtual void a60(), a61(), a62(), a63();
    virtual bool Virtual100();
    virtual void b65(), b66(), b67(), b68(), b69();
    virtual void b70(), b71(), b72(), b73(), b74(), b75(), b76(), b77(), b78(), b79();
    virtual void b80(), b81(), b82(), b83(), b84(), b85(), b86(), b87(), b88(), b89();
    virtual void b90(), b91(), b92(), b93(), b94();
    virtual void Virtual17c(TESActorBase*, int, int, int, int, int, int, int, int, int);

    BaseProcess* GetCurrentAIProcess();
    TESActorBase* GetActorBase();
};

class FUN_009b4440_shell
{
  public:
    Actor* FUN_009b4440();
};

class Holder
{
  public:
    void FUN_009c3e10();
};

class InventoryStackRecord
{
  public:
    ~InventoryStackRecord();
};

class DH
{
  public:
    bool FUN_004226e0();
};
extern DH* g_dataHandler;

class ST_009333e0
{
  public:
    void FUN_0092ed60(bool);
};

class WorldSpaceTarget
{
  public:
    void RemoveEntryForRef(FUN_009bc470*);
};

class TESWorldSpace
{
  public:
    WorldSpaceTarget* FUN_00825c00();
};
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

class Class140
{
  public:
    ~Class140();
};

class Class144
{
  public:
    ~Class144();
};

class FUN_009bc470 : public MobileObject
{
  public:
    virtual ~FUN_009bc470();
    BSSimpleListEx<InventoryStackRecord*> list;
    unsigned char byte90;
    char pad91, pad92, pad93;
    NiTransform transform;
    unsigned int wordC8;
    float floatCC, floatD0, floatD4, floatD8, floatDC, floatE0;
    float floatE4, floatE8, floatEC, floatF0, floatF4;
    unsigned int wordF8, wordFC, word100;
    NiPoint2 position;
    float positionZ;
    float float110;
    NiPointer<NiAVObject> visualA;
    unsigned char byte118;
    char pad119, pad11A, pad11B;
    NiPointer<NiAVObject> visualB;
    NiPointer<ActorCause> cause;
    float float124;
    SoundPlaybackHandle soundA, soundB;
    Class140* word140;
    Class144* word144;
    unsigned char byte148;
    char pad149, pad14A, pad14B;
    float float14C;
};

// Deletes word144, list entries, and word140; clears 3D and cause pointers and conditionally calls actor methods.
// @fnv 0x009bc470
FUN_009bc470::~FUN_009bc470()
{
    if (word144)
    {
        delete word144;
    }
    word144 = 0;

    if (reinterpret_cast<TESObjectREFR*>(this)->Get3DSimple() &&
        reinterpret_cast<TESObjectREFR*>(this)->Get3DSimple()->GetNiNode() &&
        FUN_005784b0(reinterpret_cast<TESObjectREFR*>(this)->Get3DSimple()->GetNiNode()))
    {
        FUN_00578170(reinterpret_cast<TESObjectREFR*>(this)->Get3DSimple()->GetNiNode());
    }
    reinterpret_cast<TESObjectREFR*>(this)->TESObjectREFR::Set3D(0, 1);

    reinterpret_cast<FUN_009c4f90_This*>(this)->StopSound();

    if (reinterpret_cast<Actor*>(this)->GetActorBase() &&
        !reinterpret_cast<BGSProjectile*>(reinterpret_cast<Actor*>(this)->GetActorBase())->FUN_009bc870())
    {
        reinterpret_cast<BSSoundHandleEx*>(&soundA)->FUN_00ad8da0(1000);
    }

    if (DAT_011f2250.FUN_00441110() == this)
    {
        DAT_011f2250.FUN_009c8b90(0);
    }
    if (DAT_011f2250.FUN_007af430() == this)
    {
        DAT_011f2250.SetValue(0);
    }

    if (reinterpret_cast<FUN_00444d00_Class*>(this)->FUN_00444d00(0x80))
    {
        BSSimpleListEx<FUN_009bc470*>* pList = DAT_011e0e80.GetOffset70Ptr();
        if (pList)
        {
            pList->Remove(this);
        }
    }

    if (reinterpret_cast<FUN_00444d00_Class*>(this)->FUN_00444d00(0x400) &&
        reinterpret_cast<FUN_009b4440_shell*>(this)->FUN_009b4440())
    {
        if (reinterpret_cast<FUN_009b4440_shell*>(this)->FUN_009b4440()->Virtual100())
        {
            Actor* shooter = reinterpret_cast<FUN_009b4440_shell*>(this)->FUN_009b4440();
            if (shooter->GetCurrentAIProcess())
            {
                shooter->GetCurrentAIProcess()->Virtual384(0);
            }
        }
        reinterpret_cast<FUN_009b4440_shell*>(this)->FUN_009b4440()->Virtual17c(
            reinterpret_cast<Actor*>(this)->GetActorBase(), 0, 1, 0, 0, 0, 0, 0, 1, 0);
    }

    reinterpret_cast<Holder*>(this)->FUN_009c3e10();

    while (!list.FUN_008256d0())
    {
        InventoryStackRecord* item = list.FUN_006815c0()->data;
        delete item;
        list.FUN_0063f7b0();
    }

    if (!g_dataHandler->FUN_004226e0())
    {
        reinterpret_cast<ST_009333e0*>(this)->FUN_0092ed60(0);
        BGSSaveLoadGlobalDataWorldspacePtr->FUN_00825c00()->RemoveEntryForRef(this);
    }

    if (word140)
    {
        delete word140;
        word140 = 0;
    }

    visualB = 0;
    cause = 0;
}
}  // namespace fnv_009bc470

struct NiRTTI;
extern NiRTTI const _g_01202e7c;

bool __cdecl FUN_0043b300(NiRTTI const*, NiAVObject*);
int __fastcall FUN_0045bb80(int);

struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};

class NiAVObject
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* vfn_0c();
};

struct ProjectileBlastSearch
{
    bool FUN_009c6380(NiAVObject* apRoot, NiPoint3& aBlastPosition);
};

// Recursively searches apRoot and its children for a node matching _g_01202e7c, copying its position into aBlastPosition when found.
// @fnv 0x009c6380
bool ProjectileBlastSearch::FUN_009c6380(NiAVObject* apRoot, NiPoint3& aBlastPosition)
{
    if (!apRoot)
        return false;

    NiNode* pnode;
    bool bblastNodeFound = false;

    if (FUN_0043b300(&_g_01202e7c, apRoot))
    {
        bblastNodeFound = true;
        *(NiPoint3*)&aBlastPosition = *(NiPoint3*)FUN_0045bb80((int)apRoot);
    }

    pnode = apRoot->vfn_0c();
    if (pnode)
    {
        for (unsigned int i = 0; !bblastNodeFound && i < pnode->GetNumChildren(); ++i)
        {
            bblastNodeFound |= FUN_009c6380(pnode->GetAt(i), aBlastPosition);
        }
    }

    return bblastNodeFound;
}
