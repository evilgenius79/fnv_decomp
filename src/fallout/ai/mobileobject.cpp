// fallout/ai/mobileobject.cpp: MobileObject, Actor, TESObjectREFR, VTableHelper and more (95 functions)

class ExtraDismemberedLimbs;
class bhkCharacterController;
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "mobileobject_private/mobileobject_types_TESPackage.h"
#include "mobileobject_private/mobileobject_interface.h"

// @fnv 0x00931d30
void MobileObject::AdvanceMovement(float delta)
{
    SetFurnitureHeading(GetCurrentTargetDistance(false) + delta);
}

// @fnv 0x00931d70
float MobileObject::GetLooking() const
{
    return GetAngleOnReference().x;
}

// Returns true if the interface is in dialogue and the stored object pointer is non-null and its check returns true.
// @fnv 0x00933840
bool MobileObject::IsInDialogueWithPlayer() const
{
    if (Interface::IsInDialog() && m_pBaseProcess && m_pBaseProcess->IsDetectionEnabled())
        return true;
    return false;
}

// @fnv 0x009316c0
void MobileObject::ProcessAnimation()
{
    RelocateTo(GetParentWorldSpace(), GetParentCell(), *GetPos(), GetAngleOnReference().z);
}

// Returns true if the current package exists and its pack type is IN_GAME_DIALOGUE, otherwise false.
// @fnv 0x009336c0
bool MobileObject::IsCombatStateActive() const
{
    TESPackage* package = GetCurrentPackage();
    if (package && package->GetPackType() == _PackageType::IN_GAME_DIALOGUE)
        return true;
    else
        return false;
}

// Returns false when flags contains any bit that is also set in the masked-out bits, otherwise true.
// @fnv 0x008b0190
bool Actor::IsVisible(int flags)
{
    return (flags & ~(m_iActorStateValue & flags)) ? false : true;
}

// @fnv 0x0087d810
void Actor::SetActorEssentialState(int value)
{
    ActorProjectileState = value;
}

// Calls TESObjectREFR::Revert, reverts the stored reference if present, then resets the object's state flags and values to defaults.
// @fnv 0x00932f60
void MobileObject::Revert(BGSLoadFormBuffer* buffer)
{
    TESObjectREFR::Revert(buffer);
    if (m_pBaseProcess)
        m_pBaseProcess->Revert(buffer);
    SetChaseMode(false);
    m_cCharacterValue = -1;
    m_bNinthFlag = false;
    m_bFirstFlag = true;
    m_bFourthBooleanValue = true;
    m_bFifthFlag = true;
    m_bSecondBooleanValue = false;
    m_bThirdFlag = false;
    m_bTenthFlag = true;
    ProcessReferenceState = 0.0f;
    ReferenceMobileState = 0.0f;
    m_bEighthFlag = false;
}

#include "../../../include/BSAudio.h"
#include "../../../include/SoundPlaybackHandle.h"
extern TESDataHandler* g_dataHandler;

// Looks up a sound form by editor name, gets a sound handle by form ID, optionally positions and attaches it to the node, sets volume to 1.0 and plays it.
// @fnv 0x00933270
SoundPlaybackHandle MobileObject::PlaySoundByEditorName(const char* editorName, bool loop, unsigned int flags, bool)
{
    SoundPlaybackHandle soundHandle;
    if (GetNiNode())
    {
        // TESSound's evidenced primary TESForm base is at offset zero.
        TESForm* sound = reinterpret_cast<TESForm*>(g_dataHandler->GetSoundByEditorID(editorName));
        if (sound)
        {
            soundHandle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound->GetFormID(), flags);
            if (flags & 2)
            {
                NiPoint3 position = *GetPos();
                soundHandle.SetPosition(position.x, position.y, position.z);
                soundHandle.SetObjectToFollow(reinterpret_cast<NiAVObject*>(GetNiNode()));
            }
            soundHandle.SetVolume(1.0f);
            soundHandle.Play(loop);
        }
    }
    return soundHandle;
}

#include "mobileobject_private/mobileobject_packet.h"
// @fnv 0x004b9930
bool MobileObject::GetCharControllerFlag() const
{
    return !reinterpret_cast<const unsigned char*>(this)[4];
}
// @fnv 0x00920fb0
void Actor::SetCurrentSitSleepState(SIT_SLEEP_STATE state)
{
    m_eSitSleepState = state;
}
// Checks the reference's ExtraDismemberedLimbs extra data and returns whether the given limb is dismembered.
// @fnv 0x00573090
bool TESObjectREFR::IsLimbMissing(int limb)
{
    ExtraDismemberedLimbs* extra = GetExtraData()->GetDismemberedLimbs();
    if (!extra)
        return false;
    return extra->IsBitSet(limb);
}
// @fnv 0x009307d0
bool MobileObject::IsActorDead()
{
    MobileObjectRemovalState state;
    state.removed = false;
    state.controller = GetPhysicsCharacterController();
    if (state.controller)
    {
        state.controller->SetInactive();
        state.controller->FUN_00c70c90(0);
        state.removed = true;
    }
    return state.removed;
}
// Copies the x, y and z components of point into the first three elements of output and sets the fourth element to 0.0f, then returns output.
// @fnv 0x00553fc0
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController* output, const NiPoint3& point)
{
    output->GetVectorElement(0) = point.x;
    output->GetVectorElement(1) = point.y;
    output->GetVectorElement(2) = point.z;
    output->GetVectorElement(3) = 0.0f;
    return output;
}

struct NiAVObject;
struct FourComponentNumericValue;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
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
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_004a3eb0_shell : public BhkPickData
{
    void FUN_004a3eb0(void*);
};

struct __declspec(align(16)) hkVector4
{
    char m_vComponents[16];
    hkVector4();
};

hkVector4& __cdecl FUN_004a3e00(hkVector4&, const NiPoint3&);

struct FUN_004a3f40_helper
{
    void FUN_004a3f40(const hkVector4&);
};

// @fnv 0x004a3eb0
void FUN_004a3eb0_shell::FUN_004a3eb0(void* arTo)
{
    hkVector4 hkv;
    ((FUN_004a3f40_helper*)this)->FUN_004a3f40(FUN_004a3e00(hkv, *(const NiPoint3*)arTo));
}

extern int DAT_0108a490;
extern int DAT_0108a49c;

// @fnv 0x0092eb50
void* __fastcall FUN_0092eb50(char* this_ptr)
{
    ((TESObjectREFR*)this_ptr)->TESObjectREFR::TESObjectREFR();
    *(int**)(this_ptr + 0x00) = &DAT_0108a49c;
    *(int**)(this_ptr + 0x18) = &DAT_0108a490;
    *(int*)(this_ptr + 0x6c) = 0;
    *(int*)(this_ptr + 0x68) = 0;
    *(int*)(this_ptr + 0x70) = 0;
    *(char*)(this_ptr + 0x7c) = 1;
    *(char*)(this_ptr + 0x7d) = 0;
    *(char*)(this_ptr + 0x7e) = 0;
    *(char*)(this_ptr + 0x84) = -1;
    *(char*)(this_ptr + 0x85) = 0;
    *(char*)(this_ptr + 0x7f) = 1;
    *(char*)(this_ptr + 0x80) = 1;
    *(char*)(this_ptr + 0x86) = 1;
    *(char*)(this_ptr + 0x81) = 0;
    *(char*)(this_ptr + 0x82) = 0;
    *(char*)(this_ptr + 0x87) = 0;
    *(float*)(this_ptr + 0x78) = 0.0f;
    *(char*)(this_ptr + 0x83) = 0;
    return this_ptr;
}

float __cdecl WrapAngle(float);
extern double DAT_0101ff58;

struct VTableHelper
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool v100();
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
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual int v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual bool v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void* v4c8();
    bool FUN_0087eeb0();
    void FUN_005757a0(float);
    void FUN_005757d0(float);
    void FUN_00931b60(float fAngleDifference);
};

// @fnv 0x00931b60
void VTableHelper::FUN_00931b60(float afAngle)
{
    if (((Actor*)this)->m_pBaseProcess)
    {
        if (this->v230())
            return;

        switch (this->v214())
        {
        case 4:
        case 5:
        case 9:
        case 10:
            if (((VTableHelper*)((Actor*)this)->m_pBaseProcess)->v4c8() && this->v100())
                return;
            break;
        }
    }

    afAngle = WrapAngle(afAngle);
    if (this->v100() && this->FUN_0087eeb0())
    {
        afAngle = afAngle - *(float*)((char*)this + 0x2c);
        while (afAngle < DAT_0101ff58)
            afAngle = afAngle + 6.2831854820251465;
        while (afAngle >= 3.1415927410125732)
            afAngle = afAngle - 6.2831854820251465;
        this->FUN_005757a0(afAngle);
    }
    else
    {
        this->FUN_005757d0(afAngle);
    }
}

struct FUN_00931d90_shell : public MobileObject
{
    void ClampLookAngle(float);
};

struct SettingT_GameSettingCollection_
{
    SETTING_VALUE* Float();
};
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting231;
extern const float DAT_0108a7f8;
extern const double DAT_0108a7f0;
extern const float DAT_0108a7ec;
extern const double DAT_01023128;
struct ST_00931d90
{
    void FUN_00575770(float);
};
// Clamps afAngle between a lower limit and a per-actor-type maximum derived from a game setting, then applies it via FUN_00575770.
// @fnv 0x00931d90
void FUN_00931d90_shell::ClampLookAngle(float afAngle)
{
    float fMaxAngle = DAT_0108a7f8;
    if (IsActor())
    {
        TESObjectREFR* pactor = this;
        switch ((int)pactor->Unk_85())
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            fMaxAngle = *(float*)originalRuntimeFloatSetting231.Float() * DAT_01023128;
            break;
        }
    }
    if (afAngle < DAT_0108a7f0)
        ((ST_00931d90*)this)->FUN_00575770(DAT_0108a7ec);
    else if (afAngle > fMaxAngle)
        ((ST_00931d90*)this)->FUN_00575770(fMaxAngle);
    else
        ((ST_00931d90*)this)->FUN_00575770(afAngle);
}

struct FUN_00931e50_shell : public MobileObject
{
    void AddModAngle(float);
};

struct ST_00931e50
{
    void ClampLookAngle(float);
};
// Adds afModAngle to the object's looking angle and passes the result to ClampLookAngle.
// @fnv 0x00931e50
void FUN_00931e50_shell::AddModAngle(float afModAngle)
{
    ((ST_00931e50*)this)->ClampLookAngle(GetLooking() + afModAngle);
}

struct FUN_00931e80_shell : public MobileObject
{
    void DeleteAndClear();
};

// @fnv 0x00931e80
void FUN_00931e80_shell::DeleteAndClear()
{
    delete m_pBaseProcess;
    m_pBaseProcess = 0;
}

struct FUN_00931fb0_shell : public MobileObject
{
    void FUN_00931fb0(bool);
};

struct Helper_00629670
{
    void FUN_00629670(int, bool);
};

// @fnv 0x00931fb0
void FUN_00931fb0_shell::FUN_00931fb0(bool abTF)
{
    bhkCharacterController* pcon = GetPhysicsCharacterController();
    if (pcon)
    {
        reinterpret_cast<Helper_00629670*>(reinterpret_cast<char*>(pcon) + 0x410)->FUN_00629670(0x800, abTF);
    }
}

namespace fnv_00932d60 {
struct ActorCause;
struct AlchemyItem;
struct BGSProjectile;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct CombatController;
struct EnchantmentItem;
struct InventoryStackRecord;
struct NiAVObject;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct Projectile;
struct ProjectileAuxiliaryData;
struct ProjectileSupportData;
struct TESBoundObject;
struct TESFaction;
struct TESFile;
struct TESObjectWEAP;
struct BhkPickData;
struct bhkRigidBody;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_00932d60_shell : public MobileObject
{
    void FUN_00932d60(BGSLoadFormBuffer*);
};

class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock(void);
};

class BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10(void);
};

class Calendar
{
  public:
    float GetGameTime(void);
};

class ProcessLists
{
  public:
    void AddMobileObjectToList(MobileObject*);
    void RemoveMobileObjectFromList(MobileObject*);
};

class ActorDeletionQueue
{
  public:
    void FUN_0096d470(MobileObject*, int);
};

class TESResponse
{
  public:
    TESResponse* GetNext(void);
};

class ActiveEffect
{
  public:
    void FUN_00693d50(float);
};

struct Actor_Accessor : public Actor
{
    bool FUN_00437b90(void);
};

struct TESObjectREFR_Accessor : public TESObjectREFR
{
    int GetReferenceType(void);
    void FUN_005627c0(BGSLoadFormBuffer*);
    void FUN_009319c0(int);
};

int __fastcall FUN_0042ede0(const void* this_ptr);
void __cdecl FUN_00936ac0(unsigned int formID, int a2);

extern RecursiveSpinLock DAT_011f11a0;
extern ProcessLists DAT_011e0e80;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern Calendar g_calendar;
extern PlayerCharacter* pPlayer;

// @fnv 0x00932d60
void FUN_00932d60_shell::FUN_00932d60(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((TESObjectREFR_Accessor*)this)->FUN_005627c0(apLoadGameBuffer);
    if (m_pBaseProcess != 0)
    {
        m_pBaseProcess->ApplyLoadBuffer(reinterpret_cast< ::BGSLoadFormBuffer*>(apLoadGameBuffer));
        if (((Actor_Accessor*)this)->FUN_00437b90())
        {
            DAT_011f11a0.Lock(0);
            ((ActorDeletionQueue*)&DAT_011e0e80)->FUN_0096d470(this, (int)((TESResponse*)m_pBaseProcess)->GetNext());
            delete m_pBaseProcess;
            DAT_011f11a0.Unlock();
            m_pBaseProcess = 0;
        }
        else if (((TESObjectREFR_Accessor*)this)->GetReferenceType() == 0 && (PlayerCharacter*)this != pPlayer &&
                 (((TESResponse*)m_pBaseProcess)->GetNext() == 0 ||
                  (int)((TESResponse*)m_pBaseProcess)->GetNext() == 1))
        {
            PROCESS_TYPE edesiredProcessLevel = GetProcessTier();
            if (edesiredProcessLevel == PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW ||
                edesiredProcessLevel == PROCESS_TYPE_PROCESS_TYPE_LOW)
            {
                if (g_BGSSaveLoadGame->FUN_0042ce10())
                {
                    if (edesiredProcessLevel == PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW)
                        Unk_92();
                    else
                        Unk_91();
                    ((ActiveEffect*)m_pBaseProcess)->FUN_00693d50(g_calendar.GetGameTime() - 0.5);
                    DAT_011e0e80.RemoveMobileObjectFromList(this);
                }
                else
                {
                    DAT_011e0e80.AddMobileObjectToList(this);
                }
            }
        }
    }
    if (!*((unsigned char*)this + 0x80) && !FUN_0042ede0(GetExtraData()))
    {
        FUN_00936ac0(GetFormID(), 1);
    }
    if (g_BGSSaveLoadGame->FUN_0042ce10() && !((Actor_Accessor*)this)->FUN_00437b90())
    {
        ((TESObjectREFR_Accessor*)this)->FUN_009319c0(GetProcessTier());
    }
}
}  // namespace fnv_00932d60

struct FUN_009333e0_shell : public MobileObject
{
    void FUN_009333e0(bool);
};

class MagicCaster;
struct ProcessLists
{
    void AddMobileObjectToList(MobileObject*);
};
extern ProcessLists DAT_011e0e80;
struct ST_009333e0
{
    void FUN_00564930(bool);
    void FUN_0092ed60(bool);
};
bool __cdecl FUN_00933480(MobileObject*);
// @fnv 0x009333e0
void FUN_009333e0_shell::FUN_009333e0(bool abDeleted)
{
    ((ST_009333e0*)this)->FUN_00564930(abDeleted);
    DAT_011e0e80.AddMobileObjectToList(this);
    if (abDeleted)
    {
        bool bcaster = dynamic_cast<MagicCaster*>((MobileObject*)this) || FUN_00933480(this);
        ((ST_009333e0*)this)->FUN_0092ed60(bcaster);
        (*(void(__thiscall**)(void*))(*(int*)this + 0x2fc))(this);
    }
}

TESForm* __cdecl _ref_004839c0(unsigned int);

struct MobileObject_Helper : public MobileObject
{
    void SetAccumulate(int);
    void FUN_00936aa0(bool);
};

void __fastcall SetAccumulate(MobileObject_Helper*, int, int);
void __fastcall FUN_00936aa0(MobileObject_Helper*, int, bool);

// Looks up the form for the given id; if it is a mobile object, either clears its flag or calls SetAccumulate and FUN_00936aa0 with abSucceeded.
// @fnv 0x00936a20
void __cdecl HandleMobileObjectResult(void* apContext, bool abSucceeded)
{
    MobileObject* pactor;
    unsigned int iactorid = (unsigned int)apContext;
    TESForm* pform = _ref_004839c0(iactorid);
    if (pform && pform->IsMobileObject())
    {
        pactor = (MobileObject*)pform;
        if (!pactor)
        {
            return;
        }
        if (!*((bool*)pactor + 0x83))
        {
            ((void(__thiscall*)(MobileObject*, int))SetAccumulate)(pactor, 0);
            ((void(__thiscall*)(MobileObject*, bool))FUN_00936aa0)(pactor, abSucceeded);
        }
        else
        {
            *((bool*)pactor + 0x83) = false;
        }
    }
}

struct FUN_00931620_shell : public MobileObject
{
    void FUN_00931620(NiPoint3*);
};

struct FUN_00440460_S
{
    void FUN_00440460(const NiPoint3*);
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_0087cee0_shell
{
    bool FUN_0087cee0();
};
struct SetLoc_S
{
    void SetLocationOnReference(const NiPoint3&);
};
struct CharCtl_S
{
    void FUN_005620e0(void*);
    void FUN_0080fb00(void*);
    void ResetState();
};
void* __cdecl FUN_00458b20();
float __fastcall FUN_005d10f0(const char*);

// Sets the reference location from arVel, then forwards arVel to the character controller and to the object at offset 0x64 when its float at 0x14 is non-zero.
// @fnv 0x00931620
void FUN_00931620_shell::FUN_00931620(NiPoint3* arVel)
{
    reinterpret_cast<SetLoc_S*>(this)->SetLocationOnReference(*arVel);
    bhkCharacterController* pcon = GetPhysicsCharacterController();
    if (pcon)
    {
        reinterpret_cast<CharCtl_S*>(pcon)->FUN_005620e0(arVel);
        reinterpret_cast<CharCtl_S*>(pcon)->FUN_0080fb00(FUN_00458b20());
        FUN_005d10f0(reinterpret_cast<const char*>(pcon));
        reinterpret_cast<FUN_0087cee0_shell*>(pcon)->FUN_0087cee0();
        reinterpret_cast<CharCtl_S*>(pcon)->ResetState();
    }
    if (*(int*)((char*)this + 0x64) && (unsigned int)*(Flt*)(*(char**)((char*)this + 0x64) + 0x14))
    {
        reinterpret_cast<FUN_00440460_S*>((unsigned int)*(Flt*)(*(char**)((char*)this + 0x64) + 0x14))
            ->FUN_00440460(arVel);
    }
}

namespace fnv_009334b0 {
struct FUN_009334b0_shell : public MobileObject
{
    int GetCellLoadState();
};

struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct TESSaveLoadGame
{
    bool GetLoading();
};
struct PlayerCharacter
{
    bool IsSleepingOrResting();
};
struct TES
{
    bool IsCellBuffered(TESObjectCELL*, bool);
};
struct ModelLoader
{
    bool FUN_00445750(void*);
};
struct MobileStandIn
{
    unsigned int GetCurrentProcessLevel();
    TESObjectCELL* GetTarget();
    int GetReferenceType();
};
struct CellStandIn
{
    bool HasCellExtraData();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern ModelLoader* g_modelLoader;
// Returns a state code based on save-loading, sleeping/resting, the target cell, model loading and cell checks.
// @fnv 0x009334b0
int FUN_009334b0_shell::GetCellLoadState()
{
    TESObjectCELL* pTargetCell;
    if (!g_TESSaveLoadGame->GetLoading() && g_thePlayer->IsSleepingOrResting())
        return ((MobileStandIn*)this)->GetCurrentProcessLevel();
    pTargetCell = ((MobileStandIn*)this)->GetTarget();
    if (g_BGSSaveLoadGame->FUN_0042ce10() || ((MobileStandIn*)this)->GetReferenceType() ||
        g_modelLoader->FUN_00445750(this))
    {
        if (g_TES->IsCellBuffered(pTargetCell, true))
            return 0;
        else if (g_TES->IsCellBuffered(pTargetCell, false))
            return 1;
    }
    if ((pTargetCell && ((CellStandIn*)pTargetCell)->HasCellExtraData()) || g_TES->IsCellBuffered(pTargetCell, false))
        return 2;
    return 3;
}
}  // namespace fnv_009334b0

class FUN_0092f140_shell
{
    unsigned int m_field_0xd2c;

  public:
    unsigned int __thiscall GetFieldD2C();
};

// @fnv 0x0092f140
unsigned int __thiscall FUN_0092f140_shell::GetFieldD2C()
{
    return *(unsigned int*)((unsigned char*)this + 0xd2c);
}

extern int DAT_011a2fe0;

// @fnv 0x009304a0
int __cdecl FUN_009304a0()
{
    return DAT_011a2fe0;
}

struct DummyFlags
{
    int __thiscall FUN_00621270(int);
};

// @fnv 0x00930570
int __fastcall HasFlag40000(DummyFlags* this_)
{
    return ((DummyFlags*)((char*)this_ + 0x410))->FUN_00621270(0x40000) != 0;
}

// @fnv 0x00930600
void __fastcall SetField558(void* thisPtr, float value)
{
    *(float*)((char*)thisPtr + 0x558) = value;
}

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
char* __cdecl FUN_0040ab30(char*, int);

// @fnv 0x004d5ad0
bool BuildLipPath(BSStringT<char>& path)
{
    char fileName[260];
    TaskQueueInterface::CopyStringToBuffer(fileName, 260, path.String());
    {
        char* dot = FUN_0040ab30(fileName, '.');
        if (!dot)
            return false;
        *dot = 0;
    }
    path.PrintfString("%s.lip", fileName);
    return true;
}

struct FUN_00810f90_shell
{
    void SetFlag4000(bool flag);
};

// Sets or clears bit 0x4000 in the first int of this object based on flag.
// @fnv 0x00810f90
void FUN_00810f90_shell::SetFlag4000(bool abSet)
{
    if (abSet)
        ((int*)this)[0] |= 0x4000;
    else
        ((int*)this)[0] &= ~0x4000;
}

struct FUN_0092ec10_shell
{
    void* __thiscall FUN_0092ec40();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

void* __cdecl Deallocate(void* p);

// Calls FUN_0092ec40, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0092ec10
void* __thiscall FUN_0092ec10_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0092ec40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C"
{
    extern float DAT_011b014c;
}

struct FUN_00930620_shell
{
    void __thiscall FUN_00930620();
};

// @fnv 0x00930620
void __thiscall FUN_00930620_shell::FUN_00930620()
{
    *(float*)((char*)this + 0x530) = DAT_011b014c;
}

struct FUN_0083b9a0_shell
{
    void FUN_0083b9a0();
};
struct FUN_009edd80;
extern PlayerCharacter* g_thePlayer;
struct FUN_00967730_shell
{
    void FUN_00967730(Actor* apActor, Actor* apTarget, FUN_009edd80* apPackage);
};

struct FUN_009edd80 : public TESPackage
{
    SoundPlaybackHandle kSound;
    int iUnk8C;
    float m_fPackageValue;
    int iUnk94;
    bool bUnk98;
    int iUnk9C;
    bool bUnkA0;
    FUN_0083b9a0_shell* pTopic;
    int iUnkA8;
    int iUnkAC;
    Actor* m_pDialogueSpeaker;
    Actor* pTarget;
    int iUnkB8;
    bool bUnkBC;
    bool bUnkBD;
    bool bUnkBE;
    bool bUnkBF;
    bool bUnkC0;
    bool bUnkC1;
    bool bUnkC2;
    int iUnkC4;
    int iUnkC8;
    bool bUnkCC;
    FUN_009edd80(FUN_0083b9a0_shell* apTopic, Actor* apSpeaker, Actor* apTarget, int aiUnk, bool abUnkBD, bool abUnkA0);
    virtual ~FUN_009edd80();
};

// @fnv 0x009edd80
FUN_009edd80::FUN_009edd80(FUN_0083b9a0_shell* apTopic, Actor* apSpeaker, Actor* apTarget, int aiUnk, bool abUnkBD,
                           bool abUnkA0)
{
    pTopic = apTopic;
    if (apTopic)
        pTopic->FUN_0083b9a0();
    iUnkA8 = 0;
    iUnkAC = 0;
    m_fPackageValue = 0.0f;
    m_pDialogueSpeaker = apSpeaker;
    pTarget = apTarget;
    m_pDialogueSpeaker->Unk_80(0);
    iUnk8C = 0;
    iUnk94 = 0;
    bUnkBD = abUnkBD;
    bUnk98 = false;
    bUnkBE = false;
    bUnkBF = false;
    bUnkC0 = false;
    bUnkBC = true;
    bUnkC1 = false;
    iUnk9C = 0;
    ((FUN_00967730_shell*)g_thePlayer)->FUN_00967730(apSpeaker, apTarget, this);
    iUnkC4 = 0;
    iUnkC8 = 50;
    iUnkB8 = aiUnk;
    bUnkA0 = abUnkA0;
    bUnkC2 = false;
    bUnkCC = true;
}

struct FUN_00672850_shell : TESPackage
{
    float GetPackageFloatValue();
};

// Returns 1.0f unless the pack type is 0xf or 0x1c, in which case it returns the float at offset 4 of the package stored at this+0x28.
// @fnv 0x00672850
float FUN_00672850_shell::GetPackageFloatValue()
{
    float result = 1.0f;
    if (GetPackType() == 0xf || GetPackType() == 0x1c)
    {
        TESPackage* pkg = *(TESPackage**)((char*)this + 0x28);
        if (pkg)
            result = *(float*)((char*)pkg + 4);
    }
    return result;
}

namespace fnv_009304b0 {
struct DummyFlags
{
    int FUN_00621270(int);
    int HasFlag20();
};

// @fnv 0x009304b0
int DummyFlags::HasFlag20()
{
    return FUN_00621270(0x20) != 0;
}
}  // namespace fnv_009304b0

struct TESObject
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
    virtual bool AtA0();
    TESObject* GetNext();
};
struct FUN_0056f6b0_t
{
    bool HasNextWithAtA0();
};
// Returns true if GetNext() is non-null and the next object's AtA0() is also true.
// @fnv 0x0056f6b0
bool FUN_0056f6b0_t::HasNextWithAtA0()
{
    return ((TESObject*)this)->GetNext() && ((TESObject*)this)->GetNext()->AtA0();
}

struct StandIn_00672760 : public TESPackage
{
    TESPackage* FUN_00672760();
};
// If the package type is 0xF or 0x1C, returns the TESPackage stored at offset 8 of the object at this+0x28; otherwise returns null.
// @fnv 0x00672760
TESPackage* StandIn_00672760::FUN_00672760()
{
    TESPackage* result = 0;
    if (GetPackType() == 0xF || GetPackType() == 0x1C)
    {
        void* tmp = *(void**)((char*)this + 0x28);
        if (tmp)
        {
            result = *(TESPackage**)((char*)tmp + 8);
        }
    }
    return result;
}

struct Unk80f760
{
    NiPoint3* GetZeroPoint(NiPoint3* p);
};
// Writes NiPoint3::ZERO into the output NiPoint3 and returns it.
// @fnv 0x0080f760
NiPoint3* Unk80f760::GetZeroPoint(NiPoint3* apPoint)
{
    *apPoint = NiPoint3::ZERO;
    return apPoint;
}

namespace fnv_00810ff0 {
struct Flt
{
    operator unsigned int() const;
};
struct Unk626
{
    void FUN_00626cb0(int);
};
struct Ths810
{
    char pad[0x594];
    Flt f;
    void FUN_00810ff0(int);
};
// If the stored Flt value is non-zero, treats it as an Unk626 and calls FUN_00626cb0 with a.
// @fnv 0x00810ff0
void Ths810::FUN_00810ff0(int a)
{
    if ((unsigned int)f)
        ((Unk626*)(unsigned int)f)->FUN_00626cb0(a);
}
}  // namespace fnv_00810ff0

struct Holder_00884aa0
{
    int UpdateControllerScale();
    int FUN_00884aa0();
};
void __cdecl FUN_00838780(Holder_00884aa0*, int);
// Calls UpdateControllerScale; if it returns nonzero, calls FUN_00838780 with this and 0, then returns that result.
// @fnv 0x00884aa0
int Holder_00884aa0::FUN_00884aa0()
{
    int result = 0;
    result = UpdateControllerScale();
    if (result)
    {
        FUN_00838780(this, 0);
    }
    return result;
}

namespace fnv_008a0270 {
struct PC7d;
extern PC7d* g_thePlayer;
struct FUN_008a0270_t
{
    bool FUN_008a0270(bool);
};
// Returns false for the player; otherwise returns the flag at offset 0x104 when offset 0x68 is nonzero, unless 0x104, abFlag and 0x127 are all set.
// @fnv 0x008a0270
bool FUN_008a0270_t::FUN_008a0270(bool abFlag)
{
    if ((PC7d*)this == g_thePlayer)
        return false;
    if (*(int*)((char*)this + 0x68) != 0)
    {
        if (*(bool*)((char*)this + 0x104) && abFlag && *(bool*)((char*)this + 0x127))
            return false;
        return *(bool*)((char*)this + 0x104);
    }
    return false;
}
}  // namespace fnv_008a0270

namespace fnv_0092f1c0 {
struct Process_Shell_0x10
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void VirtualMethod_10(void*);
};

struct TESChallenge
{
    TESObjectREFR* GetProgressValue();
};

struct ExtraDataList_Shell
{
    void FUN_0042e130();
};

struct ActorDeletionQueue
{
    void FUN_0096d470(MobileObject*, int);
};

struct ProcessLists
{
    void AddMobileObjectToList(MobileObject*);
};

extern int DAT_011e0e80;

struct FUN_0092f1c0_shell : MobileObject
{
    void FUN_0092f1c0(bool m_bChangeDetected);
};

// @fnv 0x0092f1c0
void FUN_0092f1c0_shell::FUN_0092f1c0(bool abUnused)
{
    Unk_50();

    if (m_pBaseProcess)
    {
        ((Process_Shell_0x10*)m_pBaseProcess)->VirtualMethod_10(this);
    }

    if (IsTalkingActivator() && !IsCombatStateActive())
    {
        TESObjectREFR* refr = ((TESChallenge*)this)->GetProgressValue();
        if (refr)
        {
            ((ExtraDataList_Shell*)refr->GetExtraData())->FUN_0042e130();
        }

        ((ActorDeletionQueue*)&DAT_011e0e80)->FUN_0096d470(this, 0);
        ((ProcessLists*)&DAT_011e0e80)->AddMobileObjectToList(this);
    }
}
}  // namespace fnv_0092f1c0

namespace fnv_009305a0 {
struct DummyFlags
{
    int FUN_00621270(int);
};
struct FUN_009305a0_Holder
{
    char _pad[0x410];
    DummyFlags m410;
    bool FUN_009305a0();
};
// @fnv 0x009305a0
bool FUN_009305a0_Holder::FUN_009305a0()
{
    return m410.FUN_00621270(0x2000000) != 0;
}
}  // namespace fnv_009305a0

namespace fnv_00934f90 {
struct TESObject
{
    unsigned int GetNext();
};
struct TESObjectREFR;
struct BGSTalkingActivator
{
    TESObjectREFR* GetTempRef() const;
};
struct FUN_00934f90_shell
{
    char _pad[0x6c];
    TESObject* _ptr;
    void* GetTempRefOrSelf(unsigned int, void**);
};
// Stores this into out, then returns the temp ref of the next TESObject if it has one, otherwise returns this.
// @fnv 0x00934f90
void* FUN_00934f90_shell::GetTempRefOrSelf(unsigned int, void** out)
{
    *out = this;
    BGSTalkingActivator* tmp = (BGSTalkingActivator*)_ptr->GetNext();
    if (tmp->GetTempRef())
    {
        return tmp->GetTempRef();
        goto done;
    }
    return this;
done:;
}
}  // namespace fnv_00934f90

struct FUN_009bc8c0_shell
{
    bool FUN_009bc8c0();
};
// @fnv 0x009bc8c0
bool FUN_009bc8c0_shell::FUN_009bc8c0()
{
    if (g_dataHandler->FormIDExists(reinterpret_cast<TESForm*>(this)->GetFormID()))
        return true;
    else
        return false;
}

struct FUN_0080f790_shell : public TESObjectREFR
{
    float __thiscall GetAngleZOnReference(int dummy);
};

// @fnv 0x0080f790
float __thiscall FUN_0080f790_shell::GetAngleZOnReference(int dummy)
{
    return GetAngleOnReference().z;
}

struct S0092f160;
struct P0092f160
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
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual void f267();
    virtual void f268();
    virtual void f269();
    virtual void f270();
    virtual void f271();
    virtual void f272();
    virtual void f273();
    virtual void f274();
    virtual void f275();
    virtual void f276();
    virtual void f277();
    virtual void f278();
    virtual void f279();
    virtual void f280();
    virtual void f281();
    virtual void f282();
    virtual void f283();
    virtual void f284();
    virtual void f285();
    virtual void f286();
    virtual void f287();
    virtual void f288();
    virtual void f289();
    virtual void f290();
    virtual void f291();
    virtual void f292();
    virtual void f293();
    virtual void f294();
    virtual void f295();
    virtual void f296();
    virtual void f297();
    virtual void f298();
    virtual void f299();
    virtual void f300();
    virtual void f301();
    virtual bool Talk(S0092f160*);
};
struct S0092f160
{
    char _pad[0x68];
    P0092f160* proc;
    bool FUN_0092f160();
};
// Calls Talk on the proc object, passing this, and returns its result.
// @fnv 0x0092f160
bool S0092f160::FUN_0092f160()
{
    return proc->Talk(this);
}

struct Unk68
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
};
struct FUN_0092f190_shell
{
    char pad[0x68];
    Unk68* ptr;
    void FUN_0092f190();
};
// If ptr is non-null, calls its v10 method.
// @fnv 0x0092f190
void FUN_0092f190_shell::FUN_0092f190()
{
    if (ptr != 0)
        ptr->v10();
}

struct FUN_00629670_T
{
    void __thiscall FUN_00629670(unsigned int, unsigned char);
};

struct FUN_00930540_shell
{
    char pad[0x410];
    FUN_00629670_T m_410;
    void __thiscall FUN_00930540(unsigned char param);
};

// Forwards the given byte and the constant 0x100 to the member's FUN_00629670.
// @fnv 0x00930540
void __thiscall FUN_00930540_shell::FUN_00930540(unsigned char abValue)
{
    m_410.FUN_00629670(0x100, abValue);
}

namespace fnv_009305d0 {
class DummyFlags
{
  public:
    int FUN_00621270(int);
};

class FUN_009305d0_shell
{
    char pad[0x410];
    DummyFlags m_flags;

  public:
    bool FUN_009305d0();
};

// @fnv 0x009305d0
bool FUN_009305d0_shell::FUN_009305d0()
{
    return m_flags.FUN_00621270(0x4000000) != 0;
}
}  // namespace fnv_009305d0

struct TESObjectCELL;

struct TES
{
    bool IsCellBuffered(TESObjectCELL*, bool);
};
extern TES* g_TES;

struct LowProcess
{
    TESObjectCELL* GetTarget();
};

struct TESResponse
{
    int GetNext();
};

struct Vtable_Shell
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    // Slot 116 = 0x1d0
    virtual int VirtualMethod_1d0();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    // Slot 144 = 0x240
    virtual void VirtualMethod_240();
};

struct FUN_00931880_shell : MobileObject
{
    bool FUN_00931880();
};

// @fnv 0x00931880
bool FUN_00931880_shell::FUN_00931880()
{
    bool result = true;

    if (((Vtable_Shell*)this)->VirtualMethod_1d0())
    {
        if (g_TES->IsCellBuffered(((LowProcess*)this)->GetTarget(), true))
        {
            if (((TESResponse*)m_pBaseProcess)->GetNext())
            {
                ((Vtable_Shell*)this)->VirtualMethod_240();
            }
            else
            {
                delete this;
                result = false;
            }
        }
    }

    return result;
}

namespace fnv_00931920 {
struct TESObjectCELL;

struct TES
{
    bool IsCellBuffered(TESObjectCELL*, bool);
};
extern TES* g_TES;

struct LowProcess
{
    TESObjectCELL* GetTarget();
};

struct TESResponse
{
    int GetNext();
};

struct Vtable_Shell
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    // Slot 116 = 0x1d0
    virtual int VirtualMethod_1d0();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    // Slot 144 = 0x240
    virtual void VirtualMethod_240();
};

struct FUN_00931920_shell : MobileObject
{
    bool CheckTargetAndDelete(bool bCheck);
};

// @fnv 0x00931920
bool FUN_00931920_shell::CheckTargetAndDelete(bool bCheck)
{
    bool result = true;

    if (((Vtable_Shell*)this)->VirtualMethod_1d0())
    {
        if (g_TES->IsCellBuffered(((LowProcess*)this)->GetTarget(), bCheck))
        {
            if (((TESResponse*)m_pBaseProcess)->GetNext())
            {
                ((Vtable_Shell*)this)->VirtualMethod_240();
            }
            else
            {
                delete this;
                result = false;
            }
        }
    }

    return result;
}
}  // namespace fnv_00931920

struct Process_Shell
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
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
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
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
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
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
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
    virtual void v14a();
    virtual void v14b();
    virtual void v14c();
    virtual void v14d();
    virtual void v14e();
    virtual void v14f();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    // Slot 344 = 0x560
    virtual void VirtualMethod_560(unsigned int, unsigned int, void*);
};

struct Refr_Vtable_Shell
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    // Slot 115 = 0x1cc
    virtual void VirtualMethod_1cc(int, int);
};

struct FUN_00932490_shell : MobileObject
{
    void FUN_0055f5f0(unsigned int, unsigned int);
    void SetProcessFlags(unsigned int aiFlags, unsigned int aiOldFlags);
};

// @fnv 0x00932490
void FUN_00932490_shell::SetProcessFlags(unsigned int aiFlags, unsigned int aiOldFlags)
{
    FUN_0055f5f0(aiFlags, aiOldFlags);

    if (m_pBaseProcess)
    {
        ((Process_Shell*)m_pBaseProcess)->VirtualMethod_560(aiFlags, aiOldFlags, this);
    }

    if ((aiFlags & 0) || (aiOldFlags & 0))
    {
        if (GetDisabled() || IsDeleted())
        {
            ((Refr_Vtable_Shell*)this)->VirtualMethod_1cc(0, 1);
        }
    }
}

struct Vt_009358f0
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
    virtual void Target();
};
struct FUN_009358f0_Host
{
    char _pad[0x68];
    Vt_009358f0* p;
    void InvokeTarget();
};
// Calls the Target virtual method on the object pointed to by p.
// @fnv 0x009358f0
void FUN_009358f0_Host::InvokeTarget()
{
    p->Target();
}

namespace fnv_009319c0 {
struct FUN_009319c0_shell : public MobileObject
{
    bool FUN_009319c0(int);
};

struct RecursiveSpinLock
{
    void Lock(const char* name);
    void Unlock();
};
extern RecursiveSpinLock DAT_011f11a0;
struct ActorDeletionQueue
{
    void FUN_0096d470(MobileObject* obj, int a);
};
extern ActorDeletionQueue DAT_011e0e80;
struct TESResponse
{
    int GetNext();
};
struct Base_0092c950
{
    Base_0092c950();
    virtual ~Base_0092c950();
    char pad[0xb0];
};
struct FUN_009319c0_vt
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
    virtual bool StartHigh();
    virtual bool StartLow();
    virtual bool StartMiddleLow();
    virtual bool StartMiddleHigh();
};

// Locks, deletes the queued object at offset 0x68 and enqueues its response when level is -1; otherwise allocates it and dispatches a start method by level.
// @fnv 0x009319c0
bool FUN_009319c0_shell::FUN_009319c0(int aeProcessLevel)
{
    bool bresult = false;
    if (aeProcessLevel == -1)
    {
        DAT_011f11a0.Lock(0);
        if (*(Base_0092c950**)((char*)this + 0x68))
        {
            bresult = true;
            DAT_011e0e80.FUN_0096d470(this, ((TESResponse*)*(Base_0092c950**)((char*)this + 0x68))->GetNext());
            delete *(Base_0092c950**)((char*)this + 0x68);
            *(Base_0092c950**)((char*)this + 0x68) = 0;
        }
        DAT_011f11a0.Unlock();
    }
    else
    {
        if (!*(Base_0092c950**)((char*)this + 0x68))
            *(Base_0092c950**)((char*)this + 0x68) = new Base_0092c950();
        if (GetCurrentProcessLevel() != aeProcessLevel)
        {
            switch (aeProcessLevel)
            {
            case 0:
                bresult = ((FUN_009319c0_vt*)this)->StartHigh();
                break;
            case 1:
                bresult = ((FUN_009319c0_vt*)this)->StartMiddleHigh();
                break;
            case 2:
                bresult = ((FUN_009319c0_vt*)this)->StartMiddleLow();
                break;
            case 3:
                bresult = ((FUN_009319c0_vt*)this)->StartLow();
                break;
            }
        }
    }
    return bresult;
}
}  // namespace fnv_009319c0

namespace fnv_00932520 {
class TESSound;
class TESObjectCELL;
class bhkWorld;

struct FUN_0055f780_cls
{
    void FUN_0055f780(unsigned int, unsigned int);
};
int __fastcall FUN_004f8960(void*);
struct LowProcess
{
    TESSound* GetTarget();
};
bhkWorld* __fastcall FUN_004543c0(TESObjectCELL*);
struct FUN_005c0860Class
{
    bool FUN_005c0860();
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct CharCtl_S
{
    void FUN_005620e0(void*);
};
struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
struct TESResponse
{
    int GetNext();
};
struct ActiveEffect
{
    void FUN_00693d50(float);
};
struct Calendar
{
    float GetGameTime();
};
struct ActorDeletionQueue
{
    void FUN_0096d470(MobileObject*, int);
};
struct ProcessLists
{
    void RemoveMobileObjectFromList(MobileObject*);
};
struct FUN_00577330_cls
{
    int GetReferenceType();
};
extern RecursiveSpinLock DAT_011f11a0;
extern ProcessLists DAT_011e0e80;
extern Calendar g_calendar;
extern MobileObject* g_thePlayer;

struct Proc_00932520
{
    virtual ~Proc_00932520();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* obj);
};

struct FUN_00932520_shell : MobileObject
{
    void UpdateFlags(unsigned int aiFlags, unsigned int aiOldFlags);
};

// Calls the base flag update, then updates the character controller or actor deletion queue depending on the actor state and flags.
// @fnv 0x00932520
void FUN_00932520_shell::UpdateFlags(unsigned int aiFlags, unsigned int aiOldFlags)
{
    ((FUN_0055f780_cls*)this)->FUN_0055f780(aiFlags, aiOldFlags);
    Actor* pactor = dynamic_cast<Actor*>(static_cast<MobileObject*>(this));
    if (pactor && (FUN_004f8960(pactor) == 2 || FUN_004f8960(pactor) == 1))
    {
        Unk_A8();
    }
    else if (aiFlags & 6)
    {
        bhkCharacterController* pcon = GetPhysicsCharacterController();
        if (pcon && ((LowProcess*)this)->GetTarget())
            pcon->FUN_00c70c90((int)FUN_004543c0((TESObjectCELL*)((LowProcess*)this)->GetTarget()));
        if (pcon && !((FUN_005c0860Class*)pcon)->FUN_005c0860())
        {
            NiPoint3 pos = *((TopicH*)this)->GetAddTopicList();
            ((CharCtl_S*)pcon)->FUN_005620e0(&pos);
        }
    }
    if (*(Proc_00932520**)((char*)this + 0x68))
    {
        DAT_011f11a0.Lock(0);
        if (IsDeleted() || GetDisabled())
        {
            ((ActorDeletionQueue*)&DAT_011e0e80)
                ->FUN_0096d470(this, ((TESResponse*)*(Proc_00932520**)((char*)this + 0x68))->GetNext());
            delete *(Proc_00932520**)((char*)this + 0x68);
            *(Proc_00932520**)((char*)this + 0x68) = 0;
        }
        else if (!((FUN_00577330_cls*)this)->GetReferenceType() && this != g_thePlayer &&
                 (!((TESResponse*)*(Proc_00932520**)((char*)this + 0x68))->GetNext() ||
                  ((TESResponse*)*(Proc_00932520**)((char*)this + 0x68))->GetNext() == 1))
        {
            Unk_92();
            ((ActiveEffect*)*(Proc_00932520**)((char*)this + 0x68))->FUN_00693d50(g_calendar.GetGameTime() - 0.5);
            DAT_011e0e80.RemoveMobileObjectFromList(this);
        }
        DAT_011f11a0.Unlock();
        if (*(Proc_00932520**)((char*)this + 0x68))
            (*(Proc_00932520**)((char*)this + 0x68))->v564(aiFlags, aiOldFlags, this);
    }
}
}  // namespace fnv_00932520

namespace fnv_00932a00 {
struct AlchemyItem;
struct SaveLoadFile;
struct EnchantmentItem;
struct NiAVObject;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct TESBoundObject;
struct bhkRigidBody;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_00932a00_shell : public MobileObject
{
    void FUN_00932a00(BGSLoadFormBuffer*);
};

struct ProcLoad_00932a00
{
    virtual void pv000();
    virtual void pv001();
    virtual void pv002();
    virtual void pv003();
    virtual void pv004();
    virtual void pv005();
    virtual void pv006();
    virtual void pv007();
    virtual void pv008();
    virtual void pv009();
    virtual void pv010();
    virtual void pv011();
    virtual void pv012();
    virtual void pv013();
    virtual void pv014();
    virtual void pv015();
    virtual void pv016();
    virtual void pv017();
    virtual void pv018();
    virtual void pv019();
    virtual void pv020();
    virtual void pv021();
    virtual void pv022();
    virtual void pv023();
    virtual void pv024();
    virtual void pv025();
    virtual void pv026();
    virtual void pv027();
    virtual void pv028();
    virtual void pv029();
    virtual void pv030();
    virtual void pv031();
    virtual void pv032();
    virtual void pv033();
    virtual void pv034();
    virtual void pv035();
    virtual void pv036();
    virtual void pv037();
    virtual void pv038();
    virtual void pv039();
    virtual void pv040();
    virtual void pv041();
    virtual void pv042();
    virtual void pv043();
    virtual void pv044();
    virtual void pv045();
    virtual void pv046();
    virtual void pv047();
    virtual void pv048();
    virtual void pv049();
    virtual void pv050();
    virtual void pv051();
    virtual void pv052();
    virtual void pv053();
    virtual void pv054();
    virtual void pv055();
    virtual void pv056();
    virtual void pv057();
    virtual void pv058();
    virtual void pv059();
    virtual void pv060();
    virtual void pv061();
    virtual void pv062();
    virtual void pv063();
    virtual void pv064();
    virtual void pv065();
    virtual void pv066();
    virtual void pv067();
    virtual void pv068();
    virtual void pv069();
    virtual void pv070();
    virtual void pv071();
    virtual void pv072();
    virtual void pv073();
    virtual void pv074();
    virtual void pv075();
    virtual void pv076();
    virtual void pv077();
    virtual void pv078();
    virtual void pv079();
    virtual void pv080();
    virtual void pv081();
    virtual void pv082();
    virtual void pv083();
    virtual void pv084();
    virtual void pv085();
    virtual void pv086();
    virtual void pv087();
    virtual void pv088();
    virtual void pv089();
    virtual void pv090();
    virtual void pv091();
    virtual void pv092();
    virtual void pv093();
    virtual void pv094();
    virtual void pv095();
    virtual void pv096();
    virtual void pv097();
    virtual void pv098();
    virtual void pv099();
    virtual void pv100();
    virtual void pv101();
    virtual void pv102();
    virtual void pv103();
    virtual void pv104();
    virtual void pv105();
    virtual void pv106();
    virtual void pv107();
    virtual void pv108();
    virtual void pv109();
    virtual void pv110();
    virtual void pv111();
    virtual void pv112();
    virtual void pv113();
    virtual void pv114();
    virtual void pv115();
    virtual void pv116();
    virtual void pv117();
    virtual void pv118();
    virtual void pv119();
    virtual void pv120();
    virtual void pv121();
    virtual void pv122();
    virtual void pv123();
    virtual void pv124();
    virtual void pv125();
    virtual void pv126();
    virtual void pv127();
    virtual void pv128();
    virtual void pv129();
    virtual void pv130();
    virtual void pv131();
    virtual void pv132();
    virtual void pv133();
    virtual void pv134();
    virtual void pv135();
    virtual void pv136();
    virtual void pv137();
    virtual void pv138();
    virtual void pv139();
    virtual void pv140();
    virtual void pv141();
    virtual void pv142();
    virtual void pv143();
    virtual void pv144();
    virtual void pv145();
    virtual void pv146();
    virtual void pv147();
    virtual void pv148();
    virtual void pv149();
    virtual void pv150();
    virtual void pv151();
    virtual void pv152();
    virtual void pv153();
    virtual void pv154();
    virtual void pv155();
    virtual void pv156();
    virtual void pv157();
    virtual void pv158();
    virtual void pv159();
    virtual void pv160();
    virtual void pv161();
    virtual void pv162();
    virtual void pv163();
    virtual void pv164();
    virtual void pv165();
    virtual void pv166();
    virtual void pv167();
    virtual void pv168();
    virtual void pv169();
    virtual void pv170();
    virtual void pv171();
    virtual void pv172();
    virtual void pv173();
    virtual void pv174();
    virtual void pv175();
    virtual void pv176();
    virtual void pv177();
    virtual void pv178();
    virtual void pv179();
    virtual void pv180();
    virtual void pv181();
    virtual void pv182();
    virtual void pv183();
    virtual void pv184();
    virtual void pv185();
    virtual void pv186();
    virtual void pv187();
    virtual void pv188();
    virtual void pv189();
    virtual void pv190();
    virtual void pv191();
    virtual void pv192();
    virtual void pv193();
    virtual void pv194();
    virtual void pv195();
    virtual void pv196();
    virtual void pv197();
    virtual void pv198();
    virtual void pv199();
    virtual void pv200();
    virtual void pv201();
    virtual void pv202();
    virtual void pv203();
    virtual void pv204();
    virtual void pv205();
    virtual void pv206();
    virtual void pv207();
    virtual void pv208();
    virtual void pv209();
    virtual void pv210();
    virtual void pv211();
    virtual void pv212();
    virtual void pv213();
    virtual void pv214();
    virtual void pv215();
    virtual void pv216();
    virtual void pv217();
    virtual void pv218();
    virtual void pv219();
    virtual void pv220();
    virtual void pv221();
    virtual void pv222();
    virtual void pv223();
    virtual void pv224();
    virtual void pv225();
    virtual void pv226();
    virtual void pv227();
    virtual void pv228();
    virtual void pv229();
    virtual void pv230();
    virtual void pv231();
    virtual void pv232();
    virtual void pv233();
    virtual void pv234();
    virtual void pv235();
    virtual void pv236();
    virtual void pv237();
    virtual void pv238();
    virtual void pv239();
    virtual void pv240();
    virtual void pv241();
    virtual void pv242();
    virtual void pv243();
    virtual void pv244();
    virtual void pv245();
    virtual void pv246();
    virtual void pv247();
    virtual void pv248();
    virtual void pv249();
    virtual void pv250();
    virtual void pv251();
    virtual void pv252();
    virtual void pv253();
    virtual void pv254();
    virtual void pv255();
    virtual void pv256();
    virtual void pv257();
    virtual void pv258();
    virtual void pv259();
    virtual void pv260();
    virtual void pv261();
    virtual void pv262();
    virtual void pv263();
    virtual void pv264();
    virtual void pv265();
    virtual void pv266();
    virtual void pv267();
    virtual void pv268();
    virtual void pv269();
    virtual void pv270();
    virtual void pv271();
    virtual void pv272();
    virtual void pv273();
    virtual void pv274();
    virtual void pv275();
    virtual void pv276();
    virtual void pv277();
    virtual void pv278();
    virtual void pv279();
    virtual void pv280();
    virtual void pv281();
    virtual void pv282();
    virtual void pv283();
    virtual void pv284();
    virtual void pv285();
    virtual void pv286();
    virtual void pv287();
    virtual void pv288();
    virtual void pv289();
    virtual void pv290();
    virtual void pv291();
    virtual void pv292();
    virtual void pv293();
    virtual void pv294();
    virtual void pv295();
    virtual void pv296();
    virtual void pv297();
    virtual void pv298();
    virtual void pv299();
    virtual void pv300();
    virtual void pv301();
    virtual void pv302();
    virtual void pv303();
    virtual void pv304();
    virtual void pv305();
    virtual void pv306();
    virtual void pv307();
    virtual void pv308();
    virtual void pv309();
    virtual void pv310();
    virtual void pv311();
    virtual void pv312();
    virtual void pv313();
    virtual void pv314();
    virtual void pv315();
    virtual void pv316();
    virtual void pv317();
    virtual void pv318();
    virtual void pv319();
    virtual void pv320();
    virtual void pv321();
    virtual void pv322();
    virtual void pv323();
    virtual void pv324();
    virtual void pv325();
    virtual void pv326();
    virtual void pv327();
    virtual void pv328();
    virtual void pv329();
    virtual void pv330();
    virtual void pv331();
    virtual void pv332();
    virtual void pv333();
    virtual void pv334();
    virtual void pv335();
    virtual void pv336();
    virtual void pv337();
    virtual void pv338();
    virtual void pv339();
    virtual void pv340();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_00932a00_t : public MobileObject
{
    void FUN_009319c0(int);
    void ApplyChanges(BGSLoadFormBuffer*);
    void FUN_00932a00(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x00932a00
void FUN_00932a00_t::FUN_00932a00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    char cprocessLevel = -1;
    apLoadGameBuffer->ReadTypedData((void*)&cprocessLevel, 1);
    FUN_009319c0(cprocessLevel);
    ApplyChanges(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x84), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x85), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x7c), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x7f), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x80), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x7d), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x7e), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x86), 1);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x74), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x78), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x81), 1);
    if (apLoadGameBuffer->GetVersion() >= 8)
        apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x83), 1);
    apLoadGameBuffer->ReadFormIdentifier((unsigned int*)((char*)this + 0x6c));
    apLoadGameBuffer->ReadFormIdentifier((unsigned int*)((char*)this + 0x70));
    if (*(ProcLoad_00932a00**)((char*)this + 0x68))
        (*(ProcLoad_00932a00**)((char*)this + 0x68))->LoadGame(apLoadGameBuffer);
}
}  // namespace fnv_00932a00

namespace fnv_00932b70 {
struct AlchemyItem;
struct SaveLoadFile;
struct EnchantmentItem;
struct NiAVObject;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct TESBoundObject;
struct bhkRigidBody;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_00932b70_shell : public MobileObject
{
    void FUN_00932b70(BGSLoadFormBuffer*);
};

struct S_00562660
{
    void FUN_00562660(BGSLoadFormBuffer*);
};
struct S_009319c0
{
    void FUN_009319c0(int);
};
struct RefX
{
    bool FUN_00437b90();
};
struct RefA
{
    NiAVObject* GetReferenceType();
};
struct TESResponse
{
    int GetNext();
};
struct Base_0092c950
{
    Base_0092c950();
    char pad[0xb4];
};
TESForm* GetFormByID(unsigned int);
struct Proc_00932b70
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
    virtual void InitLoadGame(BGSLoadFormBuffer*);
};
struct Ref_00932b70
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void r88();
    virtual void r89();
    virtual void r90();
    virtual void r91();
    virtual void r92();
    virtual void r93();
    virtual void r94();
    virtual void r95();
    virtual void r96();
    virtual void r97();
    virtual void r98();
    virtual void r99();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void AnimateNiNode();
    virtual void r114();
    virtual void Set3D(NiNode*, bool);
    virtual NiNode* GetNiNode();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual void r125();
    virtual void r126();
    virtual void r127();
    virtual void r128();
    virtual void r129();
    virtual void r130();
    virtual void r131();
    virtual void r132();
    virtual void r133();
    virtual void r134();
    virtual void r135();
    virtual void r136();
    virtual bool Unk_89();
};

// @fnv 0x00932b70
void FUN_00932b70_shell::FUN_00932b70(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((S_00562660*)this)->FUN_00562660(apLoadGameBuffer);
    *(TESObjectREFR**)((char*)this + 0x6c) =
        *(TESObjectREFR**)((char*)this + 0x6c)
            ? dynamic_cast<TESObjectREFR*>(GetFormByID(*(unsigned int*)((char*)this + 0x6c)))
            : 0;
    *(MobileObject**)((char*)this + 0x70) =
        *(MobileObject**)((char*)this + 0x70)
            ? dynamic_cast<MobileObject*>(GetFormByID(*(unsigned int*)((char*)this + 0x70)))
            : 0;
    if (*(Proc_00932b70**)((char*)this + 0x68))
        (*(Proc_00932b70**)((char*)this + 0x68))->InitLoadGame(apLoadGameBuffer);
    if (((Ref_00932b70*)this)->GetNiNode() && !((Ref_00932b70*)this)->Unk_89() && !GetPhysicsCharacterController())
        ((Ref_00932b70*)this)->AnimateNiNode();
    if (!*(void**)((char*)this + 0x68) && !((RefX*)this)->FUN_00437b90())
    {
        *(Base_0092c950**)((char*)this + 0x68) = new Base_0092c950;
        ((S_009319c0*)this)->FUN_009319c0(GetProcessTier());
    }
    if (((RefA*)this)->GetReferenceType())
    {
        if (!*(void**)((char*)this + 0x68) || (*(TESResponse**)((char*)this + 0x68))->GetNext() == 3 ||
            (*(TESResponse**)((char*)this + 0x68))->GetNext() == 2)
            ((Ref_00932b70*)this)->Set3D(0, true);
    }
}
}  // namespace fnv_00932b70

struct FUN_00933150_shell : TESObjectREFR
{
    int GetReferenceType();
    SoundPlaybackHandle PlaySoundByFormID(unsigned int formID, bool loop, unsigned int flags, bool follow);
};

// Looks up a sound handle by form ID, positions it at this reference's position when flags has bit 2 and a node exists, then plays it and returns the handle.
// @fnv 0x00933150
SoundPlaybackHandle FUN_00933150_shell::PlaySoundByFormID(unsigned int formID, bool loop, unsigned int flags, bool follow)
{
    SoundPlaybackHandle sound;
    sound = BSAudio::GetSingleton()->GetSoundHandleByFormID(formID, flags);
    if (GetReferenceType() && (flags & 2))
    {
        NiPoint3 position = *GetPos();
        sound.SetPosition(position.x, position.y, position.z);
        sound.SetObjectToFollow(reinterpret_cast<NiAVObject*>(GetReferenceType()));
    }
    sound.Play(loop);
    return sound;
}

struct ActorValueInfo;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct FormRecordHeader;
struct TESFileGroup;
struct TESResponseList;
struct TESActorBase;
struct TESTopicInfoData;
struct TESFile;
struct TESQuest;
struct TopicInfoData;
struct TESTopicInfo : public TESForm
{
    virtual void __vslot_10();
    virtual void Save();
    virtual bool Load(TESFile*);
    virtual void Copy(TESForm*);
    virtual void InitItem();
    virtual void ResetFormData();
    virtual void ClearData();
    void SetOwnerTopic(TESTopic*);
    virtual void SetAltered(bool);
    virtual bool CopyTopicData(FormRecordHeader*);
    virtual bool CopyTopicData(TESForm*);
    virtual bool LoadTopicInfoData(FormRecordHeader*, bool, bool);
    virtual void CreateGroupData(FormRecordHeader*, TESFileGroup*);
    virtual void SerializeTopicInfoData(void*);
    int GetTopicType();
    int GetNextSpeaker();
    void SetNextSpeaker(int);
    unsigned short GetInfoIndex();
    void SetInfoIndex(unsigned short);
    PerkEntryConditionSet* GetInfoConditions();
    void SetConditionList(PerkEntryConditionSet*);
    void* GetAddTopicList();
    bool InAddTopicList(TESTopic*);
    void FormatDebugInfo(void*, bool);
    TESQuest* GetParentQuest();
    void SetOwnerQuest(TESQuest*);
    bool IsGoodbye();
    void SetGoodbye(bool);
    bool IsRandom();
    void SetRandom(bool);
    bool IsRandomEnd();
    void SetRandomEnd(bool);
    bool IsSayOnce();
    void SetSayOnce(bool);
    bool IsInfoRefusal();
    void SetInfoRefusal(bool);
    bool IsRunImmediately();
    void SetRunImmediately(bool);
    bool IsRunRumorResults();
    void SetRunRumorResults(bool);
    bool IsSpeechChallenge();
    void SetSpeechChallenge(bool);
    bool IsSayOnceADay();
    void SetSayOnceADay(bool);
    bool IsAlwaysDarkened();
    void SetAlwaysDarkened(bool);
    int GetDummyNodeState();
    void SetDummyNodeState(int);
    TESTopicInfoData* GetConversationData();
    void SetTopicInfoData(TESTopicInfoData*);
    void* GetPrompt();
    void SetPrompt(char*);
    bool HasPrompt();
    void SetActorValue(ActorValueInfo*);
    void SetPerk(BGSPerk*);
    ActorValueInfo* GetActorValue();
    BGSPerk* GetPerk();
    TESForm* GetPerkSkillStat();
    int GetDifficultyLevel();
    void SetDifficultyLevel(int);
    int GetNextSpeakerType();
    TESActorBase* GetSpeaker();
    void SetSpeaker(TESActorBase*);
    void CloneResponseList(TESResponseList*);
    Script* GetResultScript(int);
    unsigned int GetTempDataOffset();
    void SetTempDataOffset(unsigned int);
    bool IsInfoValidForDialogue(bool*, TESQuest*, TESObjectREFR*, TESObjectREFR*);
    bool IsInfoValidForDialogue(TESQuest*, TESObjectREFR*, TESObjectREFR*);
    void HyperLinkCompile(char*);
    void RemoveHyperLinks();
    void AppendTopicInfo(int, TESObjectREFR*);
    void AddTopicList();
    bool SaidOnce();
    void SetSaidOnce();
    void ResetSaidOnceFlags();
    bool IsValidSaveID(bool);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void Revert(BGSLoadFormBuffer*);
    virtual void Revert(unsigned int);
    TESResponseList* DuplicateResponseList(TESResponseList*);
    void ClearResponses();
    void ResetResponseList();
    TopicInfoData* GetData();
    static void AddTopicInfoToSortedList(TESTopicInfo*, void*);
    static bool CompareTopicInfos(TESTopicInfo*, TESTopicInfo*);
    PerkEntryConditionSet m_kInfoConditions;
    unsigned short m_uiInfoIndex;
    bool m_bGoodbye;
    char m_Data[4];
    char _pad_27[1];
    char m_kPrompt[8];
    char m_kAddTopicList[8];
    TESTopicInfoData* m_pResponseData;
    TESActorBase* m_pDialogueSpeaker;
    TESForm* m_pPerkSkillStat;
    int m_eDifficultyLevel;
    TESQuest* m_pOwnerQuest;
    unsigned long m_ulTopicFlags;
};
typedef char _sizecheck_TESTopicInfo[sizeof(TESTopicInfo) == 80 ? 1 : -1];
struct FUN_00934250_shell : public MobileObject
{
    void FUN_00934250();
};

struct FUN_0042edb0_shell
{
    void FUN_0042edb0();
};
struct FUN_0057bd40_shell
{
    TESTopic* FUN_0057bd40();
};
struct SC_008c48d0
{
    static bool __cdecl GetLocalData(void*, ExtraDataList*, unsigned int);
};
struct FUN_008a5530_shell
{
    void FUN_008a5530();
};
struct XActor
{
    TESTopicInfo* FUN_00934430();
};
struct Character;
struct RunResultScript_helper
{
    void RunResultScript(int, Character*);
};
struct SetSayToTopic_helper
{
    void SetDialogueTopic(TESTopic*);
};
class PlayerCharacter
{
  public:
    void UpdatePlayerState();
};
extern PlayerCharacter* _g_thePlayer;
bool __fastcall FUN_00579200(char const*);
// @fnv 0x00934250
void FUN_00934250_shell::FUN_00934250()
{
    BaseProcess* pProcess = ((Actor*)this)->GetProcess();
    if (pProcess && pProcess->GetActorSoundHandle(0).IsSoundPlaying())
    {
        TESTopicInfo* pTopicInfo = ((XActor*)this)->FUN_00934430();
        TESTopic* pMenuTopicEntry = ((FUN_0057bd40_shell*)this)->FUN_0057bd40();
        ((SetSayToTopic_helper*)this)->SetDialogueTopic(0);
        ((FUN_0042edb0_shell*)GetExtraData())->FUN_0042edb0();
        if (pTopicInfo)
        {
            if (!FUN_00579200((char const*)pTopicInfo))
                ((RunResultScript_helper*)pTopicInfo)->RunResultScript(1, (Character*)this);
            SC_008c48d0::GetLocalData(pMenuTopicEntry, GetExtraData(), 0x40000);
            *((unsigned char*)this + 0x83) = 1;
            ((Actor*)this)->GetProcess()->SetCombatEnabled(false);
        }
        *((unsigned char*)this + 0x84) = 0xff;
        pProcess->StopActorSound(0);
        pProcess->SetCombatAlerted(false);
        _g_thePlayer->UpdatePlayerState();
    }
    *((unsigned char*)this + 0x80) = 1;
    *((unsigned char*)this + 0x7f) = 1;
    if (!IsTalkingActivator() && GetNiNode())
    {
        Actor* pactor = (Actor*)this;
        ((FUN_008a5530_shell*)pactor)->FUN_008a5530();
    }
}

namespace fnv_009c45d0 {
struct RecursiveSpinLock
{
    void Lock(char const*);
    void Unlock();
};
struct TES
{
    bool IsCellBuffered(TESObjectCELL*, bool);
};
struct TESResponse
{
    int GetNext();
};
struct LowProcess
{
    TESSound* GetTarget();
};
struct ActorDeletionQueue
{
    void FUN_0096d470(MobileObject*, int);
};
struct Loader_S
{
    bool FUN_00445750(void*);
};
struct BGSSaveLoadGame_S
{
    void FUN_00849730(void*, int);
};
struct ProcessDel
{
    virtual ~ProcessDel();
};
extern Loader_S* g_modelLoader;
extern BGSSaveLoadGame_S* g_BGSSaveLoadGame;
extern TES* g_TES;
extern ActorDeletionQueue DAT_011e0e80;
extern RecursiveSpinLock DAT_011f11a0;
struct FUN_009c45d0_t : public MobileObject
{
    bool FUN_009c45d0();
};
struct MobileVtbl
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void MarkForDeletion(bool);
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual int V1D0();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void V240();
    virtual void p145();
    virtual void p146();
    virtual void V24C();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void V2A0();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void V2FC();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p200();
    virtual bool V324();
};

// Compares the current level with a level derived from cell load state and switches, queues for deletion, or resets the object accordingly.
// @fnv 0x009c45d0
bool FUN_009c45d0_t::FUN_009c45d0()
{
    bool result2 = true;
    int curLevel3 = *(TESResponse**)((char*)this + 0x68) ? (*(TESResponse**)((char*)this + 0x68))->GetNext() : 3;
    int iNewLevel = 3;
    bool bLoadedTmp = ((MobileVtbl*)this)->V324();
    TESObjectCELL* cellVal = (TESObjectCELL*)((LowProcess*)this)->GetTarget();
    if (((MobileVtbl*)this)->V1D0() || g_modelLoader->FUN_00445750(this))
    {
        if (g_TES->IsCellBuffered(cellVal, true))
        {
            iNewLevel = 0;
        }
        else if (bLoadedTmp && g_TES->IsCellBuffered(cellVal, false))
        {
            iNewLevel = 1;
        }
    }
    if (curLevel3 != iNewLevel)
    {
        if (iNewLevel == 0)
        {
            ((MobileVtbl*)this)->V240();
        }
        else if (iNewLevel == 1)
        {
            ((MobileVtbl*)this)->V24C();
        }
        else if (g_dataHandler->FormIDExists(GetFormID()))
        {
            if (bLoadedTmp)
            {
                g_BGSSaveLoadGame->FUN_00849730(this, 0);
            }
            ((MobileVtbl*)this)->MarkForDeletion(true);
            result2 = false;
        }
        else
        {
            int lvl = (*(TESResponse**)((char*)this + 0x68))->GetNext();
            DAT_011f11a0.Lock(0);
            DAT_011e0e80.FUN_0096d470(this, lvl);
            delete *(ProcessDel**)((char*)this + 0x68);
            *(ProcessDel**)((char*)this + 0x68) = 0;
            DAT_011f11a0.Unlock();
            ((MobileVtbl*)this)->V2A0();
            ((MobileVtbl*)this)->V2FC();
        }
    }
    return result2;
}
}  // namespace fnv_009c45d0

namespace fnv_0092f260 {
struct AlchemyItem;
struct EnchantmentItem;
struct NiAVObject;
struct NiStream;
struct TESBoundObject;
struct bhkRigidBody;
struct blob12
{
    char b[12];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];
struct FUN_0092f260_shell : public MobileObject
{
    bhkCharacterController* FUN_0092f260(float, NiPoint3*, unsigned int);
};

class PlayerCharacter;
class TES;
extern TES* g_TES;
void* __cdecl FUN_00458b20();
struct FUN_00440460_S
{
    void FUN_00440460(const NiPoint3*);
};
struct SetLoc_S
{
    void SetLocationOnReference(const NiPoint3&);
};
extern PlayerCharacter* g_thePlayer;
int _FNV_IsNaN(double);
int _FNV_Finite(double);
int _FNV_Warning(const char*, ...);
extern double _DAT_010231b0;
extern double _DAT_010241b0;
extern double DAT_0108a7a0;
extern double DAT_0101db88;
extern unsigned int DAT_011e054c;
extern bool DAT_011e0550;

struct Setting_S
{
    float* Float();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern Setting_S DAT_01267bd4;
extern Setting_S g_011e0574;
extern GlobalObject2_0040c150 g_011e05b4;
extern Twin_0084d030 g_timeGlobal;

struct hkpCharacterContext
{
    static float GetReferenceTimeStep();
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct LowProcess
{
    TESObjectCELL* GetTarget();
    TESObjectCELL* GetCurrentBoundObject();
};
struct MobileObject_Helper
{
    float GetRelevantWaterHeight() const;
};
struct TESWaterHelper
{
    float UpdateTESState(const NiPoint3&, unsigned int);
    void GetLandHeightAt(NiPoint3*, float*);
};
struct FUN_0080f790_S
{
    float GetAngleZOnReference(bool);
};
struct FUN_008846e0_shell
{
    unsigned int GetVtbl20Result();
};
struct Act_009e3520
{
    float GetCurrentMovementSpeed();
};
struct FUN_008b8f90_S
{
    void ProcessTargets();
};

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float, float, float);
    NiPoint3 operator+(const NiPoint3&) const;
};
class NiPoint3_ext : public NiPoint3
{
  public:
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3_ext& operator+=(const NiPoint3&);
};
float __fastcall FUN_004a7290(const NiPoint3&);
struct TESAngleHelper
{
    void SetReferencePosition(NiPoint3Ex);
};

struct NiMatrix3PC
{
    float m_afEntries[3][3];
    void FUN_004a0c90(float);
    void FUN_00524ac0(float);
    NiPoint3 operator*(const NiPoint3&) const;
    NiMatrix3PC FUN_004b45b0() const;
};
void* __fastcall FUN_006815c0(void*);
void* __fastcall FUN_006240d0(void*);

class BSFadeNode;
struct NiAVObjectVT
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual BSFadeNode* vfn_10();
    NiPoint3& FUN_0043c490();
};
struct FUN_00b4e030_S
{
    bool IsWithinFadeDistance(void*, float);
};
void* __cdecl FUN_00524c90();
const NiPoint3& __fastcall FUN_0045bb80(void*);
struct FUN_00561730_S
{
    int FUN_00561730(void*, float);
};
FUN_00561730_S* __fastcall FUN_0089d600(bhkCharacterController*);
bool __fastcall FUN_00437bd0(Actor*);
bool __fastcall FUN_0087f390(MobileObject*);
int __fastcall FUN_005c0880(bhkCharacterController*);
float __fastcall GetSettingFloat(bhkCharacterController*);
float __cdecl FUN_004587d0(float);
unsigned int __cdecl FUN_009304a0();
bool __cdecl FUN_006d97b0(NiPoint3*, TESObjectCELL*, TESWorldSpace*, float*);

struct PathingLocation
{
    char data[0x28];
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
};
void __cdecl GetPathingLocationNormal(PathingLocation*, NiPoint3*);

struct __declspec(align(16)) hkQuaternion
{
    float m_vec[4];
    void FUN_00cb2450(void*, float);
};
struct __declspec(align(16)) hkVector4
{
    float m_vComponents[4];
};

struct MovementPose
{
    float fMoveElapsedTime;
    NiPoint3 Angle;
    NiPoint3 DeltaMove;
    unsigned int iMoveDir;
    float fSpeed;
    bool bFlag;
};
void* __fastcall FUN_009304d0(MovementPose*);
hkVector4& __cdecl FUN_004a3e00(hkVector4&, const NiPoint3&);

struct FUN_0088b0a0_c
{
    void set(int);
};
struct CharFlags
{
    bool HasFlag20();
    void FUN_00629650(int);
    void FUN_00629670(int, bool);
};
bool __fastcall FUN_008a5170(CharFlags*);
struct bhkCharControllerVT
{
    virtual void vt00();
    virtual void vt01();
    virtual void vt02();
    virtual void vt03();
    virtual void vt04();
    virtual void vt05();
    virtual void vt06();
    virtual void vt07();
    virtual void vt08();
    virtual void vt09();
    virtual void vt10();
    virtual void vt11();
    virtual void vt12();
    virtual void vt13();
    virtual void vt14();
    virtual void vt15();
    virtual void vt16();
    virtual void vt17();
    virtual void vt18();
    virtual void vt19();
    virtual void vt20();
    virtual void vt21();
    virtual void vt22();
    virtual void vt23();
    virtual void vt24();
    virtual void vt25();
    virtual void vt26();
    virtual void vt27();
    virtual void vt28();
    virtual void vt29();
    virtual void vt30();
    virtual void vt31();
    virtual void vt32();
    virtual void vt33();
    virtual void vt34();
    virtual void vt35();
    virtual void vt36();
    virtual void vt37();
    virtual void vt38();
    virtual void vt39();
    virtual void vt40();
    virtual void vt41();
    virtual void vt42();
    virtual void vt43();
    virtual void vt44();
    virtual void vt45();
    virtual void vt46();
    virtual void vt47();
    virtual void vt48();
    virtual void vt49();
    virtual void vfn_C8(MovementPose* apMoveData);
    bool FUN_0088b0c0();
    int FUN_00621ad0();
    bool HasFlag40000();
    bool FUN_009305a0();
    bool FUN_009305d0();
    bool FUN_00621240();
    void ForwardToMember(void*);
    void FUN_00930620();
    void FUN_00c6e820();
    void FUN_00c70060();
    void FUN_00c6e420(hkQuaternion*);
    void FUN_00812b00(NiPoint3*);
    void SetField558(float);
    void FUN_00c70b60(MovementPose*, bool);
    void FUN_00930540(bool);
    void FUN_008e2680(bool);
};
struct MobileObjectVT
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
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual bool vfn_224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void vfn_2A8(NiPoint3* apPos);
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual float vfn_2BC(bool abFlag);
    virtual void v2C0();
    virtual void vfn_2C4(float afValue);
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual bool vfn_2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual bool vfn_38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46C();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47C();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48C();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49C();
    virtual void v4A0();
    virtual void v4A4();
    virtual void v4A8();
    virtual void v4AC();
    virtual void v4B0();
    virtual bool vfn_4B4();
};

// @fnv 0x0092f260
bhkCharacterController* FUN_0092f260_shell::FUN_0092f260(float afDeltaTime, NiPoint3* arDeltaMove,
                                                         unsigned int aiMoveDir)
{
    Actor* pactor = ((MobileObject*)this)->IsActor() ? (Actor*)this : 0;
    bhkCharacterController* pcon = ((MobileObject*)this)->GetPhysicsCharacterController();
    bool bisProjectile = ((MobileObjectVT*)this)->vfn_224();
    if (pactor && pactor->GetActorValue((ActorValue::Index)0x33) > 0)
        afDeltaTime /= hkpCharacterContext::GetReferenceTimeStep();

    NiPoint3 pos = *((TopicH*)this)->GetAddTopicList();
    !_FNV_IsNaN(arDeltaMove->x) && !_FNV_IsNaN(arDeltaMove->y) && !_FNV_IsNaN(arDeltaMove->z);

    float fanglex = ((MobileObject*)this)->GetAngleOnReference().x;
    float fangley = ((MobileObject*)this)->GetAngleOnReference().y;
    float fanglez = ((MobileObject*)this)->GetAngleOnReference().z;
    if (fanglex == _DAT_010231b0 || _FNV_IsNaN(fanglex) || !_FNV_Finite(fanglex) || fangley == _DAT_010231b0 ||
        _FNV_IsNaN(fangley) || !_FNV_Finite(fangley) || fanglez == _DAT_010231b0 || _FNV_IsNaN(fanglez) ||
        !_FNV_Finite(fanglez))
    {
        _FNV_Warning("AI: MobileObject::Move called on '%s' (%08X) with invalid angle.",
                     ((MobileObject*)this)->GetName(), ((MobileObject*)this)->GetFormID());
        ((TESAngleHelper*)this)->SetReferencePosition(NiPoint3Ex(0, 0, 0));
    }

    if (*g_011e05b4.Int())
    {
        unsigned int iFrameCounter = FUN_009304a0();
        if (DAT_011e054c != iFrameCounter)
        {
            if (iFrameCounter % (*g_011e05b4.Int() + 1))
                DAT_011e0550 = true;
            else
                DAT_011e0550 = false;
            DAT_011e054c = iFrameCounter;
        }
        if (DAT_011e0550 && ((bhkCharControllerVT*)pcon)->FUN_0088b0c0())
        {
            NiMatrix3PC rot;
            FUN_006815c0(&rot);
            if ((MobileObject*)this == (MobileObject*)g_thePlayer)
                rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
            else
                rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
            *arDeltaMove = rot * *arDeltaMove;
            pos = (const NiPoint3Ex&)((NiAVObjectVT*)((MobileObject*)this)->GetNiNode())->FUN_0043c490() + *arDeltaMove;
            ((FUN_00440460_S*)((MobileObject*)this)->GetNiNode())->FUN_00440460(&pos);
            return pcon;
        }
        else
        {
            NiPoint3 largeDelta =
                (const NiPoint3_ext&)((NiAVObjectVT*)((MobileObject*)this)->GetNiNode())->FUN_0043c490() -
                *((MobileObject*)this)->GetPos();
            NiMatrix3PC rot;
            FUN_006815c0(&rot);
            if ((MobileObject*)this == (MobileObject*)g_thePlayer)
                rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
            else
                rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
            *(NiPoint3_ext*)arDeltaMove += rot.FUN_004b45b0() * largeDelta;
        }
    }

    bool bdynamicMotionActor = pactor ? ((MobileObjectVT*)pactor)->vfn_4B4() : false;
    unsigned int uiSitState = ((MobileObject*)this)->Unk_85();
    bool bsittingCheckSupport = uiSitState && pcon && FUN_0089d600(pcon)->FUN_00561730(FUN_00458b20(), 0.001f);
    bool bshouldSitStateUpdate = !uiSitState || bsittingCheckSupport;
    NiPoint3 diff = (const NiPoint3_ext&)*((MobileObject*)this)->GetPos() - FUN_0045bb80(FUN_00524c90());
    float flengthSqr = FUN_004a7290(diff);
    bool bisImmobile = pactor ? (FUN_00437bd0(pactor) || pactor->Unk_8B(false) ||
                                 ((MobileObjectVT*)pactor)->vfn_2E8() || pactor->Unk_8C())
                              : false;

    if (flengthSqr > *DAT_01267bd4.Float() && !((MobileObjectVT*)this)->vfn_224() && !bdynamicMotionActor &&
        !bisImmobile && (MobileObject*)this != (MobileObject*)g_thePlayer)
    {
        NiPoint3 tmpLoc = pos;
        NiPoint3 tmpMove = *arDeltaMove;
        NiMatrix3PC rot;
        FUN_006815c0(&rot);
        if ((MobileObject*)this == (MobileObject*)g_thePlayer)
            rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
        else
            rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
        tmpMove = rot * tmpMove;
        (NiPoint3_ext&)tmpLoc += tmpMove;
        TESWorldSpace* pws = ((MobileObject*)this)->GetParentWorldSpace();
        TESObjectCELL* pCell = ((LowProcess*)this)->GetTarget();
        float fheightNavMesh;
        if (FUN_006d97b0(&tmpLoc, pCell, pws, &fheightNavMesh))
        {
            if (pcon && FUN_005c0880(pcon) == 5)
            {
                if (*(float*)(*(char**)((char*)this + 0x64) + 8) == _DAT_010241b0)
                    *(float*)(*(char**)((char*)this + 0x64) + 8) =
                        ((TESWaterHelper*)g_TES)->UpdateTESState(*((MobileObject*)this)->GetPos(), 0);
                float fheightWater = ((MobileObject_Helper*)this)->GetRelevantWaterHeight();
                if (fheightWater == _DAT_010241b0)
                {
                    if (pcon)
                    {
                        if (FUN_0087f390((MobileObject*)this))
                            ((FUN_0088b0a0_c*)pcon)->set(2);
                        else
                            ((FUN_0088b0a0_c*)pcon)->set(0);
                        tmpLoc.z = fheightNavMesh;
                    }
                }
                else if (tmpLoc.z > fheightWater)
                {
                    tmpLoc.z = fheightWater;
                }
                else if (tmpLoc.z < fheightNavMesh && fheightNavMesh < fheightWater)
                {
                    tmpLoc.z = fheightNavMesh;
                }
            }
            else if (!uiSitState && !bsittingCheckSupport)
            {
                tmpLoc.z = fheightNavMesh;
            }
            if (pcon && ((bhkCharControllerVT*)pcon)->FUN_00621ad0() && !((bhkCharControllerVT*)pcon)->HasFlag40000() &&
                (((bhkCharControllerVT*)pcon)->FUN_009305a0() || ((bhkCharControllerVT*)pcon)->FUN_009305a0() ||
                 FUN_008a5170((CharFlags*)((char*)pcon + 0x410))))
            {
                NiPoint3 hitNormal;
                FUN_006815c0(&hitNormal);
                PathingLocation kPathingLocation((TESObjectREFR*)this);
                GetPathingLocationNormal(&kPathingLocation, &hitNormal);
                hkVector4 kSupportNormal;
                FUN_006815c0(&kSupportNormal);
                FUN_004a3e00(kSupportNormal, hitNormal);
                ((bhkCharControllerVT*)pcon)->ForwardToMember(&kSupportNormal);
                ((bhkCharControllerVT*)pcon)->FUN_00930620();
                ((bhkCharControllerVT*)pcon)->FUN_00c6e820();
                ((bhkCharControllerVT*)pcon)->FUN_00c70060();
                float fzAngle = ((MobileObject*)this)->GetAngleOnReference().z;
                hkQuaternion kQuat;
                FUN_006240d0(&kQuat);
                kQuat.FUN_00cb2450((char*)pcon + 0x4c0, -fzAngle);
                ((bhkCharControllerVT*)pcon)->FUN_00c6e420(&kQuat);
            }
            ((MobileObjectVT*)this)->vfn_2A8(&tmpLoc);
            if (pcon && FUN_005c0880(pcon) == 2)
                ((bhkCharControllerVT*)pcon)->FUN_008e2680(false);
            return pcon;
        }
    }

    if (bshouldSitStateUpdate)
    {
        if ((MobileObject*)this == (MobileObject*)g_thePlayer)
            ((CharFlags*)((char*)pcon + 0x410))->FUN_00629670(0x8000000, bdynamicMotionActor);
        if (pcon && !((MobileObject*)this)->Unk_8B(true))
        {
            MovementPose kMoveData;
            FUN_009304d0(&kMoveData);
            kMoveData.fMoveElapsedTime = afDeltaTime;
            kMoveData.Angle = ((MobileObject*)this)->GetAngleOnReference();
            kMoveData.DeltaMove = *arDeltaMove;
            kMoveData.iMoveDir = aiMoveDir;
            kMoveData.bFlag = true;
            if ((MobileObject*)this != (MobileObject*)g_thePlayer && pactor)
            {
                NiAVObject* pNode = (NiAVObject*)((MobileObject*)this)->GetNiNode();
                BSFadeNode* pfadeNode = pNode ? ((NiAVObjectVT*)pNode)->vfn_10() : 0;
                kMoveData.bFlag =
                    pfadeNode ? ((FUN_00b4e030_S*)pfadeNode)->IsWithinFadeDistance(FUN_00524c90(), 0.8f) : true;
            }
            if (((bhkCharControllerVT*)pcon)->FUN_00621240() && !bsittingCheckSupport)
            {
                NiPoint3 oldPos;
                FUN_006815c0(&oldPos);
                NiMatrix3PC rot;
                FUN_006815c0(&rot);
                if ((MobileObject*)this == (MobileObject*)g_thePlayer)
                    rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
                else
                    rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
                *arDeltaMove = rot * *arDeltaMove;
                (NiPoint3_ext&)pos += *arDeltaMove;
                ((bhkCharControllerVT*)pcon)->FUN_00812b00(&oldPos);
                *arDeltaMove = (const NiPoint3_ext&)pos - oldPos;
                kMoveData.DeltaMove = rot.FUN_004b45b0() * *arDeltaMove;
            }
            if (((bhkCharControllerVT*)pcon)->FUN_009305a0() || ((bhkCharControllerVT*)pcon)->FUN_009305d0())
            {
                ((CharFlags*)((char*)pcon + 0x410))->FUN_00629650(0);
                ((bhkCharControllerVT*)pcon)->SetField558(*g_011e0574.Float() * g_timeGlobal.GetStoredFloatValue());
            }
            if (pactor && (((FUN_008846e0_shell*)pactor)->GetVtbl20Result() & 0x3f))
                kMoveData.fSpeed = ((Act_009e3520*)pactor)->GetCurrentMovementSpeed();
            else
                kMoveData.fSpeed = 0;
            if (bdynamicMotionActor &&
                ((MobileObject*)this == (MobileObject*)g_thePlayer || !((MobileObjectVT*)pactor)->vfn_38C()))
                ((bhkCharControllerVT*)pcon)
                    ->FUN_00c70b60(&kMoveData, (MobileObject*)this == (MobileObject*)g_thePlayer);
            else
                ((bhkCharControllerVT*)pcon)->vfn_C8(&kMoveData);
            if (((CharFlags*)((char*)pcon + 0x410))->HasFlag20())
            {
                NiPoint3 newPos;
                FUN_006815c0(&newPos);
                ((bhkCharControllerVT*)pcon)->FUN_00812b00(&newPos);
                float flift = FUN_004587d0(GetSettingFloat(pcon)) * 2.0f;
                newPos.z += flift;
                ((MobileObjectVT*)this)->vfn_2A8(&newPos);
            }
            if (!((bhkCharControllerVT*)pcon)->FUN_00621240())
            {
                ((bhkCharControllerVT*)pcon)->FUN_00812b00(&pos);
                if (FUN_008a5170((CharFlags*)((char*)pcon + 0x410)) && !bdynamicMotionActor)
                    ((MobileObjectVT*)this)->vfn_2C4(kMoveData.Angle.z);
                if (FUN_004a7290((const NiPoint3_ext&)pos - *((MobileObject*)this)->GetPos()) > DAT_0108a7a0)
                {
                    pos = *((MobileObject*)this)->GetPos();
                    ((MobileObjectVT*)this)->vfn_2A8(&pos);
                }
                float fheight = 0;
                if (!((LowProcess*)g_TES)->GetCurrentBoundObject())
                {
                    ((TESWaterHelper*)g_TES)->GetLandHeightAt(&pos, &fheight);
                    if (fheight - pos.z > DAT_0101db88)
                    {
                        pos.z = fheight;
                        ((MobileObjectVT*)this)->vfn_2A8(&pos);
                    }
                }
            }
            if (pactor)
                ((FUN_008b8f90_S*)pactor)->ProcessTargets();
        }
        else
        {
            NiMatrix3PC rot;
            FUN_006815c0(&rot);
            if (((MobileObjectVT*)this)->vfn_224())
            {
                rot.FUN_00524ac0(((MobileObject*)this)->GetLooking());
                *arDeltaMove = rot * *arDeltaMove;
            }
            if ((MobileObject*)this == (MobileObject*)g_thePlayer)
                rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
            else
                rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
            *arDeltaMove = rot * *arDeltaMove;
            (NiPoint3_ext&)pos += *arDeltaMove;
        }
    }
    else if (((MobileObject*)this)->Unk_8B(false) && !bdynamicMotionActor)
    {
        NiMatrix3PC rot;
        FUN_006815c0(&rot);
        if ((MobileObject*)this == (MobileObject*)g_thePlayer)
            rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
        else
            rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
        *arDeltaMove = rot * *arDeltaMove;
        (NiPoint3_ext&)pos += *arDeltaMove;
    }

    if (uiSitState || bsittingCheckSupport)
    {
        MovementPose kMoveData;
        FUN_009304d0(&kMoveData);
        kMoveData.fMoveElapsedTime = afDeltaTime;
        kMoveData.Angle = ((MobileObject*)this)->GetAngleOnReference();
        kMoveData.DeltaMove = *arDeltaMove;
        kMoveData.iMoveDir = aiMoveDir;
        kMoveData.bFlag = true;
        if (!bsittingCheckSupport)
            ((bhkCharControllerVT*)pcon)->FUN_00c70b60(&kMoveData, false);
        if (bsittingCheckSupport)
        {
            ((bhkCharControllerVT*)pcon)->FUN_00930540(true);
            ((bhkCharControllerVT*)pcon)->FUN_008e2680(false);
        }
        NiMatrix3PC rot;
        FUN_006815c0(&rot);
        if ((MobileObject*)this == (MobileObject*)g_thePlayer)
            rot.FUN_004a0c90(((FUN_0080f790_S*)this)->GetAngleZOnReference(false));
        else
            rot.FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
        *arDeltaMove = rot * *arDeltaMove;
        (NiPoint3_ext&)pos += *arDeltaMove;
    }

    ((SetLoc_S*)this)->SetLocationOnReference(pos);
    return pcon;
}
}  // namespace fnv_0092f260

struct TopicInfoVisitRecord
{
    TESTopicInfo* pInfo;
    int iDate;
    float fHour;
};
class BSExtraData
{
  public:
    virtual ~BSExtraData();
    unsigned char m_ucExtraDataType;
    BSExtraData* pNext;
};
union UTSO_SettingValue
{
    bool b;
    char c;
    int i;
    unsigned int u;
    float f;
    char* s;
};
template <class Collection> class UTSO_SettingT
{
  public:
    UTSO_SettingValue* Float();
};
struct ExtraSayTopicInfoOnceADay : public BSExtraData
{
    BSSimpleList<TopicInfoVisitRecord*>* pList;
};
struct DialogueItem
{
    TESObjectREFR* SelectDefaultResponseList();
};
ExtraSayTopicInfoOnceADay* __fastcall FUN_0042efe0(const ExtraDataList* apList);
extern UTSO_SettingT<GameSettingCollection> originalRuntimeFloatSetting1061;
extern unsigned int DAT_011a39c4;
extern float DAT_011e0358;
extern unsigned int DAT_011e035c;
extern signed char DAT_011e0360;

struct FUN_00935ae0_t : public MobileObject
{
    void FUN_00935ae0();
};

// Removes and deletes each stored say-once topic info whose date and hour have already passed relative to the current game date and time.
// @fnv 0x00935ae0
void FUN_00935ae0_t::FUN_00935ae0()
{
    ExtraSayTopicInfoOnceADay* pextra9 = 0;
    BSSimpleList<TopicInfoVisitRecord*>* pList;

    if (IsTalkingActivator())
        pextra9 = FUN_0042efe0(((DialogueItem*)this)->SelectDefaultResponseList()->GetExtraData());
    else
        pextra9 = FUN_0042efe0(GetExtraData());
    if (pextra9)
    {
        pList = pextra9->pList;
        while (pList && pList->GetItem())
        {
            int icurrentyear;
            float fhour2;
            TopicInfoVisitRecord* psayonceinfo6 = pList->GetItem();
            int icurrentmonth3;
            int iday_;
            float fcurrenthourB;
            int imonth2;
            int iyear7;
            bool aBremove = false;
            int icurrentday5;
            fhour2 = psayonceinfo6->fHour + originalRuntimeFloatSetting1061.Float()->f;
            iday_ = psayonceinfo6->iDate & 0x1ff;
            imonth2 = (psayonceinfo6->iDate & 0x1e00) >> 9;
            iyear7 = (psayonceinfo6->iDate & 0x7ffe000) >> 13;
            icurrentmonth3 = DAT_011a39c4;
            icurrentday5 = DAT_011e0360;
            icurrentyear = DAT_011e035c;
            fcurrenthourB = DAT_011e0358;
            if (fhour2 > 23.0 || icurrentday5 > iday_ || icurrentmonth3 > imonth2 || icurrentyear > iyear7)
            {
                if (fhour2 > 23.0)
                {
                    fhour2 = fhour2 - 23.0;
                    if (fcurrenthourB >= fhour2 &&
                        (icurrentday5 > iday_ || icurrentmonth3 > imonth2 || icurrentyear > iyear7))
                        aBremove = true;
                }
                else
                {
                    if (fcurrenthourB <= fhour2)
                        aBremove = true;
                }
            }
            else
            {
                if (fcurrenthourB >= fhour2)
                    aBremove = true;
            }
            if (aBremove)
            {
                pList->Remove(psayonceinfo6);
                delete psayonceinfo6;
                pList = pextra9->pList;
            }
            else
            {
                pList = pList->GetNext();
            }
        }
    }
}

class ActorCause
{
  public:
    void IncRefCount();
    unsigned int DecRefCount();
};

struct TESCombatStyle;

struct FUN_009b3490_shell
{
    ~FUN_009b3490_shell();
};

struct BSSimpleList_standin
{
    bool _ref_008256d0();
    FUN_009b3490_shell** _ref_006815c0();
    void _ref_0063f7b0();
};

struct FUN_008d8b80Class
{
    TESObjectREFR* FUN_008d8b80();
};

namespace p07 {
struct DelStandIn
{
    ~DelStandIn();
};
}

struct TESCreature
{
    void SetCombatStyle(TESCombatStyle*);
};

struct FUN_009c4da0_shell
{
    void ClearCombatStyleAndActorCause();
};

// @fnv 0x009c4da0
void FUN_009c4da0_shell::ClearCombatStyleAndActorCause()
{
    while (!((BSSimpleList_standin*)((char*)this + 0x88))->_ref_008256d0())
    {
        delete *((BSSimpleList_standin*)((char*)this + 0x88))->_ref_006815c0();
        ((BSSimpleList_standin*)((char*)this + 0x88))->_ref_0063f7b0();
    }

    ((NiPointer<ActorCause>*)((char*)this + 0x120))->operator=(0);

    if (((FUN_008d8b80Class*)this)->FUN_008d8b80())
    {
        delete (p07::DelStandIn*)((FUN_008d8b80Class*)this)->FUN_008d8b80();
        ((TESCreature*)this)->SetCombatStyle(0);
    }
}

struct FUN_0055e730_shell
{
    unsigned short __thiscall FUN_0055e730(unsigned int aiFlags);
};

struct FUN_00931ff0_shell : public MobileObject
{
    unsigned short __thiscall FUN_00931ff0(unsigned int aiFlags);
};

// @fnv 0x00931ff0
unsigned short __thiscall FUN_00931ff0_shell::FUN_00931ff0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += 1;
    isize += ((FUN_0055e730_shell*)this)->FUN_0055e730(aiFlags);
    if (m_pBaseProcess)
        isize += m_pBaseProcess->GetSaveSize(aiFlags, this);
    return isize;
}

namespace fnv_00932880 {
class BGSSaveFormBuffer;

class TESResponse
{
  public:
    int GetNext();
};

class SaveFormIDHelper
{
  public:
    void SerializeFormData(void*, int);
};

class BGSSaveFormBuffer : public SaveFormIDHelper
{
  public:
    void SaveData(void*, int, int);
};

struct V0
{
    virtual void m0()
    {}
    virtual void m1()
    {}
    virtual void m2()
    {}
    virtual void m3()
    {}
    virtual void m4()
    {}
    virtual void m5()
    {}
    virtual void m6()
    {}
    virtual void m7()
    {}
    virtual void m8()
    {}
    virtual void m9()
    {}
};

struct V1 : public V0
{
    virtual void m10()
    {}
    virtual void m11()
    {}
    virtual void m12()
    {}
    virtual void m13()
    {}
    virtual void m14()
    {}
    virtual void m15()
    {}
    virtual void m16()
    {}
    virtual void m17()
    {}
    virtual void m18()
    {}
    virtual void m19()
    {}
};

struct V2 : public V1
{
    virtual void m20()
    {}
    virtual void m21()
    {}
    virtual void m22()
    {}
    virtual void m23()
    {}
    virtual void m24()
    {}
    virtual void m25()
    {}
    virtual void m26()
    {}
    virtual void m27()
    {}
    virtual void m28()
    {}
    virtual void m29()
    {}
};

struct V3 : public V2
{
    virtual void m30()
    {}
    virtual void m31()
    {}
    virtual void m32()
    {}
    virtual void m33()
    {}
    virtual void m34()
    {}
    virtual void m35()
    {}
    virtual void m36()
    {}
    virtual void m37()
    {}
    virtual void m38()
    {}
    virtual void m39()
    {}
};

struct V4 : public V3
{
    virtual void m40()
    {}
    virtual void m41()
    {}
    virtual void m42()
    {}
    virtual void m43()
    {}
    virtual void m44()
    {}
    virtual void m45()
    {}
    virtual void m46()
    {}
    virtual void m47()
    {}
    virtual void m48()
    {}
    virtual void m49()
    {}
};

struct V5 : public V4
{
    virtual void m50()
    {}
    virtual void m51()
    {}
    virtual void m52()
    {}
    virtual void m53()
    {}
    virtual void m54()
    {}
    virtual void m55()
    {}
    virtual void m56()
    {}
    virtual void m57()
    {}
    virtual void m58()
    {}
    virtual void m59()
    {}
};

struct V6 : public V5
{
    virtual void m60()
    {}
    virtual void m61()
    {}
    virtual void m62()
    {}
    virtual void m63()
    {}
    virtual void m64()
    {}
    virtual void m65()
    {}
    virtual void m66()
    {}
    virtual void m67()
    {}
    virtual void m68()
    {}
    virtual void m69()
    {}
};

struct V7 : public V6
{
    virtual void m70()
    {}
    virtual void m71()
    {}
    virtual void m72()
    {}
    virtual void m73()
    {}
    virtual void m74()
    {}
    virtual void m75()
    {}
    virtual void m76()
    {}
    virtual void m77()
    {}
    virtual void m78()
    {}
    virtual void m79()
    {}
};

struct V8 : public V7
{
    virtual void m80()
    {}
    virtual void m81()
    {}
    virtual void m82()
    {}
    virtual void m83()
    {}
    virtual void m84()
    {}
    virtual void m85()
    {}
    virtual void m86()
    {}
    virtual void m87()
    {}
    virtual void m88()
    {}
    virtual void m89()
    {}
};

struct V9 : public V8
{
    virtual void m90()
    {}
    virtual void m91()
    {}
    virtual void m92()
    {}
    virtual void m93()
    {}
    virtual void m94()
    {}
    virtual void m95()
    {}
    virtual void m96()
    {}
    virtual void m97()
    {}
    virtual void m98()
    {}
    virtual void m99()
    {}
};

struct V10 : public V9
{
    virtual void m100()
    {}
    virtual void m101()
    {}
    virtual void m102()
    {}
    virtual void m103()
    {}
    virtual void m104()
    {}
    virtual void m105()
    {}
    virtual void m106()
    {}
    virtual void m107()
    {}
    virtual void m108()
    {}
    virtual void m109()
    {}
};

struct V11 : public V10
{
    virtual void m110()
    {}
    virtual void m111()
    {}
    virtual void m112()
    {}
    virtual void m113()
    {}
    virtual void m114()
    {}
    virtual void m115()
    {}
    virtual void m116()
    {}
    virtual void m117()
    {}
    virtual void m118()
    {}
    virtual void m119()
    {}
};

struct V12 : public V11
{
    virtual void m120()
    {}
    virtual void m121()
    {}
    virtual void m122()
    {}
    virtual void m123()
    {}
    virtual void m124()
    {}
    virtual void m125()
    {}
    virtual void m126()
    {}
    virtual void m127()
    {}
    virtual void m128()
    {}
    virtual void m129()
    {}
};

struct V13 : public V12
{
    virtual void m130()
    {}
    virtual void m131()
    {}
    virtual void m132()
    {}
    virtual void m133()
    {}
    virtual void m134()
    {}
    virtual void m135()
    {}
    virtual void m136()
    {}
    virtual void m137()
    {}
    virtual void m138()
    {}
    virtual void m139()
    {}
};

struct V14 : public V13
{
    virtual void m140()
    {}
    virtual void m141()
    {}
    virtual void m142()
    {}
    virtual void m143()
    {}
    virtual void m144()
    {}
    virtual void m145()
    {}
    virtual void m146()
    {}
    virtual void m147()
    {}
    virtual void m148()
    {}
    virtual void m149()
    {}
};

struct V15 : public V14
{
    virtual void m150()
    {}
    virtual void m151()
    {}
    virtual void m152()
    {}
    virtual void m153()
    {}
    virtual void m154()
    {}
    virtual void m155()
    {}
    virtual void m156()
    {}
    virtual void m157()
    {}
    virtual void m158()
    {}
    virtual void m159()
    {}
};

struct V16 : public V15
{
    virtual void m160()
    {}
    virtual void m161()
    {}
    virtual void m162()
    {}
    virtual void m163()
    {}
    virtual void m164()
    {}
    virtual void m165()
    {}
    virtual void m166()
    {}
    virtual void m167()
    {}
    virtual void m168()
    {}
    virtual void m169()
    {}
};

struct V17 : public V16
{
    virtual void m170()
    {}
    virtual void m171()
    {}
    virtual void m172()
    {}
    virtual void m173()
    {}
    virtual void m174()
    {}
    virtual void m175()
    {}
    virtual void m176()
    {}
    virtual void m177()
    {}
    virtual void m178()
    {}
    virtual void m179()
    {}
};

struct V18 : public V17
{
    virtual void m180()
    {}
    virtual void m181()
    {}
    virtual void m182()
    {}
    virtual void m183()
    {}
    virtual void m184()
    {}
    virtual void m185()
    {}
    virtual void m186()
    {}
    virtual void m187()
    {}
    virtual void m188()
    {}
    virtual void m189()
    {}
};

struct V19 : public V18
{
    virtual void m190()
    {}
    virtual void m191()
    {}
    virtual void m192()
    {}
    virtual void m193()
    {}
    virtual void m194()
    {}
    virtual void m195()
    {}
    virtual void m196()
    {}
    virtual void m197()
    {}
    virtual void m198()
    {}
    virtual void m199()
    {}
};

struct V20 : public V19
{
    virtual void m200()
    {}
    virtual void m201()
    {}
    virtual void m202()
    {}
    virtual void m203()
    {}
    virtual void m204()
    {}
    virtual void m205()
    {}
    virtual void m206()
    {}
    virtual void m207()
    {}
    virtual void m208()
    {}
    virtual void m209()
    {}
};

struct V21 : public V20
{
    virtual void m210()
    {}
    virtual void m211()
    {}
    virtual void m212()
    {}
    virtual void m213()
    {}
    virtual void m214()
    {}
    virtual void m215()
    {}
    virtual void m216()
    {}
    virtual void m217()
    {}
    virtual void m218()
    {}
    virtual void m219()
    {}
};

struct V22 : public V21
{
    virtual void m220()
    {}
    virtual void m221()
    {}
    virtual void m222()
    {}
    virtual void m223()
    {}
    virtual void m224()
    {}
    virtual void m225()
    {}
    virtual void m226()
    {}
    virtual void m227()
    {}
    virtual void m228()
    {}
    virtual void m229()
    {}
};

struct V23 : public V22
{
    virtual void m230()
    {}
    virtual void m231()
    {}
    virtual void m232()
    {}
    virtual void m233()
    {}
    virtual void m234()
    {}
    virtual void m235()
    {}
    virtual void m236()
    {}
    virtual void m237()
    {}
    virtual void m238()
    {}
    virtual void m239()
    {}
};

struct V24 : public V23
{
    virtual void m240()
    {}
    virtual void m241()
    {}
    virtual void m242()
    {}
    virtual void m243()
    {}
    virtual void m244()
    {}
    virtual void m245()
    {}
    virtual void m246()
    {}
    virtual void m247()
    {}
    virtual void m248()
    {}
    virtual void m249()
    {}
};

struct V25 : public V24
{
    virtual void m250()
    {}
    virtual void m251()
    {}
    virtual void m252()
    {}
    virtual void m253()
    {}
    virtual void m254()
    {}
    virtual void m255()
    {}
    virtual void m256()
    {}
    virtual void m257()
    {}
    virtual void m258()
    {}
    virtual void m259()
    {}
};

struct V26 : public V25
{
    virtual void m260()
    {}
    virtual void m261()
    {}
    virtual void m262()
    {}
    virtual void m263()
    {}
    virtual void m264()
    {}
    virtual void m265()
    {}
    virtual void m266()
    {}
    virtual void m267()
    {}
    virtual void m268()
    {}
    virtual void m269()
    {}
};

struct V27 : public V26
{
    virtual void m270()
    {}
    virtual void m271()
    {}
    virtual void m272()
    {}
    virtual void m273()
    {}
    virtual void m274()
    {}
    virtual void m275()
    {}
    virtual void m276()
    {}
    virtual void m277()
    {}
    virtual void m278()
    {}
    virtual void m279()
    {}
};

struct V28 : public V27
{
    virtual void m280()
    {}
    virtual void m281()
    {}
    virtual void m282()
    {}
    virtual void m283()
    {}
    virtual void m284()
    {}
    virtual void m285()
    {}
    virtual void m286()
    {}
    virtual void m287()
    {}
    virtual void m288()
    {}
    virtual void m289()
    {}
};

struct V29 : public V28
{
    virtual void m290()
    {}
    virtual void m291()
    {}
    virtual void m292()
    {}
    virtual void m293()
    {}
    virtual void m294()
    {}
    virtual void m295()
    {}
    virtual void m296()
    {}
    virtual void m297()
    {}
    virtual void m298()
    {}
    virtual void m299()
    {}
};

struct V30 : public V29
{
    virtual void m300()
    {}
    virtual void m301()
    {}
    virtual void m302()
    {}
    virtual void m303()
    {}
    virtual void m304()
    {}
    virtual void m305()
    {}
    virtual void m306()
    {}
    virtual void m307()
    {}
    virtual void m308()
    {}
    virtual void m309()
    {}
};

struct V31 : public V30
{
    virtual void m310()
    {}
    virtual void m311()
    {}
    virtual void m312()
    {}
    virtual void m313()
    {}
    virtual void m314()
    {}
    virtual void m315()
    {}
    virtual void m316()
    {}
    virtual void m317()
    {}
    virtual void m318()
    {}
    virtual void m319()
    {}
};

struct V32 : public V31
{
    virtual void m320()
    {}
    virtual void m321()
    {}
    virtual void m322()
    {}
    virtual void m323()
    {}
    virtual void m324()
    {}
    virtual void m325()
    {}
    virtual void m326()
    {}
    virtual void m327()
    {}
    virtual void m328()
    {}
    virtual void m329()
    {}
};

struct V330 : public V32
{
    virtual void m330()
    {}
    virtual void m331()
    {}
    virtual void m332()
    {}
    virtual void m333()
    {}
    virtual void m334()
    {}
    virtual void m335()
    {}
    virtual void m336()
    {}
    virtual void m337()
    {}
    virtual void m338()
    {}
    virtual void SaveGame(BGSSaveFormBuffer*);
};

struct FUN_00932880_shell
{
    unsigned char pad00[0x68];
    TESResponse* m_pBaseProcess;
    void* m_pLinkedReference;
    void* m_pMobileObject;
    int field74;
    int field78;
    unsigned char field7c;
    unsigned char field7d;
    unsigned char field7e;
    unsigned char field7f;
    unsigned char field80;
    unsigned char field81;
    unsigned char pad82;
    unsigned char field83;
    unsigned char field84;
    unsigned char field85;
    unsigned char field86;

    void FUN_00562230(BGSSaveFormBuffer*);
    void FUN_00932880(BGSSaveFormBuffer*);
};

// @fnv 0x00932880
void FUN_00932880_shell::FUN_00932880(BGSSaveFormBuffer* pSaveGameBuffer)
{
    char cprocessLevel = -1;

    if (m_pBaseProcess)
        cprocessLevel = m_pBaseProcess->GetNext();

    pSaveGameBuffer->SaveData(&cprocessLevel, 1, 0);
    this->FUN_00562230(pSaveGameBuffer);
    pSaveGameBuffer->SaveData(&field84, 1, 0);
    pSaveGameBuffer->SaveData(&field85, 1, 0);
    pSaveGameBuffer->SaveData(&field7c, 1, 0);
    pSaveGameBuffer->SaveData(&field7f, 1, 0);
    pSaveGameBuffer->SaveData(&field80, 1, 0);
    pSaveGameBuffer->SaveData(&field7d, 1, 0);
    pSaveGameBuffer->SaveData(&field7e, 1, 0);
    pSaveGameBuffer->SaveData(&field86, 1, 0);
    pSaveGameBuffer->SaveData(&field74, 4, 0);
    pSaveGameBuffer->SaveData(&field78, 4, 0);
    pSaveGameBuffer->SaveData(&field81, 1, 0);
    pSaveGameBuffer->SaveData(&field83, 1, 0);
    pSaveGameBuffer->SerializeFormData(m_pLinkedReference, 0);
    pSaveGameBuffer->SerializeFormData(m_pMobileObject, 0);

    if (m_pBaseProcess)
        reinterpret_cast<V330*>(m_pBaseProcess)->SaveGame(pSaveGameBuffer);
}
}  // namespace fnv_00932880

class B5725B0Form
{
  public:
    int GetFormType();

    bool FUN_005725b0();
};

// Returns true when GetFormType() is one of 0x3d, 0x3e, 0x3f, 0x40 or 0x69, otherwise false.
// @fnv 0x005725b0
bool B5725B0Form::FUN_005725b0()
{
    switch (GetFormType())
    {
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x69:
        return true;
    }
    return false;
}

struct Gen_vec3_local
{
    float x;
    float y;
    float z;
};

struct Gen_probe_target
{
    bool FUN_005547c0(Gen_vec3_local* v, float* f);
};

class FUN_00576470_cls
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual Gen_vec3_local* v1f4();
    Gen_probe_target* FUN_008d6f30();
    void FUN_00575830(Gen_vec3_local* v);
    bool ProbeAndApplyHeight();
};

// Gets a probe target, tests the object's position against it, and if it hits, stores the returned height in z and applies the position.
// @fnv 0x00576470
bool FUN_00576470_cls::ProbeAndApplyHeight()
{
    bool result2 = false;
    Gen_probe_target* pProbeTarget = this->FUN_008d6f30();
    if (pProbeTarget != 0)
    {
        Gen_vec3_local v2 = *this->v1f4();
        float f;
        if (pProbeTarget->FUN_005547c0(&v2, &f))
        {
            v2.z = f;
            this->FUN_00575830(&v2);
            result2 = true;
        }
    }
    return result2;
}

class E6C0Node
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void SetVisible(int iValue);

    void* GetData();
    void FUN_00c6ffc0();
};

void __cdecl CopyBlock48(void* pvData, const void* pvValue);

class E6C0Owner
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void Refresh();

    E6C0Node* GetNode();
    void Hide();
    void SetShown(bool bShow);
};

// Gets the node; if showing, makes it visible, sets its data to 1 and refreshes, otherwise calls FUN_00c6ffc0 on it and hides.
// @fnv 0x0081e6c0
void E6C0Owner::SetShown(bool bShow)
{
    E6C0Node* pkNode = GetNode();
    if (pkNode)
    {
        if (bShow)
        {
            pkNode->SetVisible(0);
            CopyBlock48(pkNode->GetData(), (const void*)1);
            Refresh();
        }
        else
        {
            pkNode->FUN_00c6ffc0();
            Hide();
        }
    }
}

struct SpinLockStub
{
    void Lock(const char* name);
    void Unlock();
};
extern SpinLockStub g_refLock;

struct ProcessStub
{
    virtual ~ProcessStub();
    int GetProcessValue();
};

struct RefStub;
struct ProcessListsStub
{
    void RemoveRef(RefStub* ref);
    void QueueRemoval(RefStub* ref, int value);
};
extern ProcessListsStub g_processLists;

struct DataHandlerStub
{
    bool IsClearing();
};
extern DataHandlerStub* g_dataHandlerStub;

struct FormStub
{
    virtual ~FormStub();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    bool IsTemporary();
};

struct ChildCellStub
{
    virtual void* GetPersistentCell();
};

struct RefStub : FormStub, ChildCellStub
{
    virtual ~RefStub();
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    void* m_pOwningCell;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    void ClearRef();
};

struct FUN_0092ec40 : RefStub
{
    ProcessStub* m_pBaseProcess;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    bool m_bFirstFlag;
    bool m_bSecondBooleanValue;
    bool m_bThirdFlag;
    bool m_bFourthBooleanValue;
    bool m_bFifthFlag;
    bool m_bSixthFlag;
    bool m_bSeventhFlag;
    bool m_bEighthFlag;
    char m_cCharacterValue;
    bool m_bNinthFlag;
    bool m_bTenthFlag;
    bool m_bThirdActorFlag;
    virtual ~FUN_0092ec40();
};

// @fnv 0x0092ec40
FUN_0092ec40::~FUN_0092ec40()
{
    g_refLock.Lock(0);
    if (!IsTemporary())
    {
        g_processLists.RemoveRef(this);
        if (!g_dataHandlerStub->IsClearing())
        {
            ClearRef();
        }
        if (m_pBaseProcess)
        {
            g_processLists.QueueRemoval(this, m_pBaseProcess->GetProcessValue());
        }
    }
    delete m_pBaseProcess;
    g_refLock.Unlock();
    if (m_bSixthFlag)
    {
        m_pOwningCell = 0;
    }
}

extern NiPoint3 DAT_011f426c;

struct FUN_009304d0_shell
{
    float unk00;
    NiPoint3 unk04;
    NiPoint3 unk10;
    unsigned int unk1c;
    float unk20;
    bool unk24;

    void* __thiscall FUN_009304d0();
};

// Initialises the object's fields: zeroes unk00 and unk20, copies DAT_011f426c into unk04 and unk10, sets unk24 to true, and returns this.
// @fnv 0x009304d0
void* __thiscall FUN_009304d0_shell::FUN_009304d0()
{
    unk00 = 0.0f;
    unk04 = DAT_011f426c;
    unk10 = DAT_011f426c;
    unk20 = 0.0f;
    unk24 = true;
    return this;
}

struct FUN_00931cc0_obj
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
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual NiPoint3* v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4(float f);
    void FUN_00931cc0(FUN_00931cc0_obj* other);
};
float __cdecl GetDirectionAngle(const NiPoint3* p);

// Computes the distance between this object's and other's v1F4 points and passes it to v2C4.
// @fnv 0x00931cc0
void FUN_00931cc0_obj::FUN_00931cc0(FUN_00931cc0_obj* other)
{
    NiPoint3 offset = *other->v1F4() - *v1F4();
    float dist = GetDirectionAngle(&offset);
    v2C4(dist);
}

struct CastType;
struct CastObject;
struct BaseCast;
struct World;
struct NodeList;
struct FieldData
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
    float angle;
};
struct CastObject
{
    World* FUN_006fa820();
    FieldData* GetReferenceFlags();
};
struct PointerView
{
    BaseCast* FUN_00559450();
};
struct NodeList
{
    PointerView* FUN_006815c0();
    NodeList* FUN_00726070();
};
struct World
{
    NodeList* FUN_007d6bb0();
};
CastObject* FUN_00653270(const CastType*, BaseCast*);
extern CastType DAT_01267e64;
extern CastType DAT_012683ec;
struct SubObject
{
    BaseCast* FUN_006838b0();
};
NiFixedString* FUN_0087e9a0();
struct ParentView
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
    virtual SubObject* f39(NiFixedString*);
};
struct AngleView
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
    virtual bool f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual ParentView* f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual float f175(int);

    bool FUN_0087eeb0();
    float GetAdjustedAngle();
};
float WrapAngle(float);
// @fnv 0x00936da0
float AngleView::GetAdjustedAngle()
{
    float angle = f175(0);
    if (f64() && FUN_0087eeb0())
    {
        ParentView* parent = f116();
        if (parent)
        {
            SubObject* sub = parent->f39(FUN_0087e9a0());
            if (sub)
            {
                CastObject* base;
                BaseCast* collision = sub->FUN_006838b0();
                base = FUN_00653270(&DAT_01267e64, collision);
                if (base)
                {
                    World* list = base->FUN_006fa820();
                    NodeList* world = list->FUN_007d6bb0();
                    while (world && world->FUN_006815c0()->FUN_00559450())
                    {
                        CastObject* body = FUN_00653270(&DAT_012683ec, world->FUN_006815c0()->FUN_00559450());
                        world = world->FUN_00726070();
                        if (body)
                        {
                            angle -= body->GetReferenceFlags()->angle;
                            angle = WrapAngle(angle);
                            break;
                        }
                    }
                }
            }
        }
    }
    return angle;
}

struct VoiceString
{
    const char* FUN_00559450();
};
struct VoiceResponse
{
    VoiceString* FUN_00460140();
    VoiceString* FUN_006815c0();
};
struct VoiceInfo
{
    void RunResultScript(int, void*);
    void FUN_0061f150();
};
struct VoiceItem
{
    VoiceInfo* FUN_0084e3a0();
    void FUN_0083c7b0();
    VoiceResponse* FUN_0083c820();
};
struct VoiceTopic
{
    VoiceItem* FUN_0061b320(void*, void*, void*, void*, bool);
};
struct VoiceForm
{
    int FUN_00401170();
};
struct VoiceNode
{
    const NiPoint3& FUN_0045bb80();
};
struct VoiceFile
{
    unsigned int FUN_00559450();
    ~VoiceFile();
};
struct VoiceAudio
{
    SoundPlaybackHandle FUN_00ad7480(const char*, unsigned int, void*);
};
VoiceAudio* __cdecl FUN_00453a70();
int __cdecl strcpy_s(char*, unsigned int, const char*);
VoiceFile* __cdecl FUN_004d52d0(BSStringT<char>&);
void __cdecl FUN_005790f0(void*, unsigned int);
float __cdecl FUN_005790b0();
float __cdecl FUN_005790d0();
void __cdecl FUN_00705210(const char*, SoundPlaybackHandle, NiPoint3, void*, bool);
struct VoiceSetting
{
    bool* FUN_00408d60();
};
extern VoiceSetting DAT_011d8928;
struct VoiceSoundMethods
{
    void FUN_00ad8be0(float, float);
    void FUN_00ad8e60(void(__cdecl*)(void*, unsigned int), void*);
};
struct VoiceHost
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
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
    virtual void slot42();
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
    virtual bool IsActor();
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
    virtual VoiceNode* GetNode();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const NiPoint3& GetPosition();
    void FUN_0057ad20(VoiceTopic*);
    void FUN_0057ace0(VoiceInfo*);
    VoiceForm* FUN_007af430();
    void* FUN_0084e3a0();
    bool FUN_008c1bc0();
    SoundPlaybackHandle PlayVoiceTopic(VoiceTopic*, void*, bool, bool, bool, void*, bool);
};
// @fnv 0x00578a80
SoundPlaybackHandle VoiceHost::PlayVoiceTopic(VoiceTopic* topic, void* listener, bool force, bool bUseAlternateFlags,
                                        bool bComputeDuration, void* unused, bool finalFlag)
{
    SoundPlaybackHandle pItem;
    float extra = 0.0f;
    VoiceItem* time = topic->FUN_0061b320(this, listener, 0, 0, false);
    float flags = 0.0f;
    FUN_0057ad20(topic);
    unsigned int kSound = 0;
    VoiceForm* pForm;
    if (FUN_007af430() && FUN_007af430()->FUN_00401170() == 0x16)
        pForm = FUN_007af430();
    if (time)
    {
        VoiceInfo* pInfo = time->FUN_0084e3a0();
        FUN_0057ace0(pInfo);
        if (pInfo)
        {
            pInfo->RunResultScript(0, this);
            pInfo->FUN_0061f150();
        }
        time->FUN_0083c7b0();
        VoiceResponse* pResponse = time->FUN_0083c820();
        if (pResponse)
        {
            if (pResponse->FUN_00460140()->FUN_00559450())
            {
                char path[512];
                strcpy_s(path, 512, pResponse->FUN_00460140()->FUN_00559450());
                if (bComputeDuration)
                {
                    VoiceFile* file = 0;
                    BSStringT<char> name;
                    name.Set(path, 512);
                    if (BuildLipPath(name))
                    {
                        file = FUN_004d52d0(name);
                        if (file)
                        {
                            flags = file->FUN_00559450() / 30.0;
                            delete file;
                        }
                    }
                }
                if (force || !GetNode())
                {
                    if (bUseAlternateFlags)
                        pItem = FUN_00453a70()->FUN_00ad7480(path, kSound | 0x101, 0);
                    else
                        pItem = FUN_00453a70()->FUN_00ad7480(path, kSound | 0x105, 0);
                }
                else
                {
                    if (bUseAlternateFlags)
                        pItem = FUN_00453a70()->FUN_00ad7480(path, kSound | 0x102, 0);
                    else
                        pItem = FUN_00453a70()->FUN_00ad7480(path, kSound | 0x106, 0);
                }
                if (!force && GetNode())
                {
                    NiPoint3 position = GetNode()->FUN_0045bb80();
                    pItem.SetPosition(position.x, position.y, position.z);
                    ((VoiceSoundMethods*)&pItem)->FUN_00ad8be0(FUN_005790b0(), FUN_005790d0());
                    pItem.SetObjectToFollow((NiAVObject*)GetNode());
                }
                pItem.Play(false);
                ((VoiceSoundMethods*)&pItem)->FUN_00ad8e60(FUN_005790f0, FUN_0084e3a0());
            }
            else if (pInfo)
                FUN_005790f0(FUN_0084e3a0(), 0);
            if (*DAT_011d8928.FUN_00408d60() || (IsActor() && FUN_008c1bc0()))
            {
                if (flags <= 0.0)
                    flags = 2.0f;
                FUN_00705210(pResponse->FUN_006815c0()->FUN_00559450(), pItem, GetPosition(), listener, finalFlag);
            }
        }
    }
    if (flags <= 0.0)
        flags = 2.0f;
    return pItem;
}

struct TESObjectCELL;

struct ProcessStandIn
{
    int GetProcessLevel();
};

struct LoaderStandIn
{
    bool IsQueued(void* ref);
};

struct TESStandIn
{
    bool IsCellBuffered(TESObjectCELL* cell, bool kCellSearchPosition);
};

struct RefStandIn;

struct LinkStandIn
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
    RefStandIn* unk28;
};

struct RefStandIn
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual ~RefStandIn();
    TESObjectCELL* GetParentCell();
};

extern LoaderStandIn* g_modelLoader;

struct ActorStandIn : RefStandIn
{
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int IsPersistentStandIn();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void MoveToHighStandIn();
    virtual void v244();
    virtual void v248();
    virtual void MoveToLowStandIn();

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
    ProcessStandIn* unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    LinkStandIn* unk88;
    int unk8C;

    bool UpdateProcessLevel();
};

// Compares the actor's current process level with a desired level derived from its cell and moves it high/low, or deletes it when the level is not applicable.
// @fnv 0x008cdbf0
bool ActorStandIn::UpdateProcessLevel()
{
    bool bResult = true;
    bool bLowOnly5 = false;
    int iCurLevel4 = unk68->GetProcessLevel();
    int iWantLevel = 3;
    TESObjectCELL* pCell4 = GetParentCell();
    if (unk8C == 2 && unk88 && unk88->unk28)
    {
        if (unk88->unk28 == (RefStandIn*)g_thePlayer)
        {
            if (iCurLevel4)
                MoveToHighStandIn();
            return true;
        }
        else
        {
            pCell4 = unk88->unk28->GetParentCell();
        }
    }
    if (IsPersistentStandIn() || g_modelLoader->IsQueued(this))
    {
        if (((TESStandIn*)g_TES)->IsCellBuffered(pCell4, true))
            iWantLevel = 0;
        else if (((TESStandIn*)g_TES)->IsCellBuffered(pCell4, false))
            iWantLevel = 1;
    }
    if (unk8C == 0)
        bLowOnly5 = true;
    if (iCurLevel4 == iWantLevel)
        return true;
    switch (iWantLevel)
    {
    case 0:
        MoveToHighStandIn();
        break;
    case 1:
        if (!bLowOnly5)
        {
            MoveToLowStandIn();
            break;
        }
    default:
        delete this;
        bResult = false;
    }
    return bResult;
}

void* __cdecl operator new(unsigned int);
struct ProcessShim
{
    virtual ~ProcessShim();
    virtual void v1(BaseProcess* previous);
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
    int unknown_004;
    int unknown_008;
    int unknown_00c;
    int unknown_010;
    int unknown_014;
    int unknown_018;
    int unknown_01c;
    int unknown_020;
    int unknown_024;
    int unknown_028;
    int unknown_02c;
    int unknown_030;
    int unknown_034;
    int unknown_038;
    int unknown_03c;
    int unknown_040;
    int unknown_044;
    int unknown_048;
    int unknown_04c;
    int unknown_050;
    int unknown_054;
    int unknown_058;
    int unknown_05c;
    int unknown_060;
    int unknown_064;
    int unknown_068;
    int unknown_06c;
    int unknown_070;
    int unknown_074;
    int unknown_078;
    int unknown_07c;
    int unknown_080;
    int unknown_084;
    int unknown_088;
    int unknown_08c;
    int unknown_090;
    int unknown_094;
    int unknown_098;
    int unknown_09c;
    int unknown_0a0;
    int unknown_0a4;
    int unknown_0a8;
    int unknown_0ac;
    int unknown_0b0;
    int unknown_0b4;
    int unknown_0b8;
    int unknown_0bc;
    int unknown_0c0;
    int unknown_0c4;
    int unknown_0c8;
    int unknown_0cc;
    int unknown_0d0;
    int unknown_0d4;
    int unknown_0d8;
    int unknown_0dc;
    int unknown_0e0;
    int unknown_0e4;
    int unknown_0e8;
    int unknown_0ec;
    int unknown_0f0;
    int unknown_0f4;
    int unknown_0f8;
    int unknown_0fc;
    int unknown_100;
    int unknown_104;
    int unknown_108;
    int unknown_10c;
    int unknown_110;
    int unknown_114;
    int unknown_118;
    int unknown_11c;
    int unknown_120;
    int unknown_124;
    int unknown_128;
    int unknown_12c;
    int unknown_130;
    int unknown_134;
    int unknown_138;
    int unknown_13c;
    int unknown_140;
    int unknown_144;
    int unknown_148;
    int unknown_14c;
    int unknown_150;
    int unknown_154;
    int unknown_158;
    int unknown_15c;
    int unknown_160;
    int unknown_164;
    int unknown_168;
    int unknown_16c;
    int unknown_170;
    int unknown_174;
    int unknown_178;
    int unknown_17c;
    int unknown_180;
    int unknown_184;
    int unknown_188;
    int unknown_18c;
    int unknown_190;
    int unknown_194;
    int unknown_198;
    int unknown_19c;
    int unknown_1a0;
    int unknown_1a4;
    int unknown_1a8;
    int unknown_1ac;
    int unknown_1b0;
    int unknown_1b4;
    int unknown_1b8;
    int unknown_1bc;
    int unknown_1c0;
    int unknown_1c4;
    int unknown_1c8;
    int unknown_1cc;
    int unknown_1d0;
    int unknown_1d4;
    int unknown_1d8;
    int unknown_1dc;
    int unknown_1e0;
    int unknown_1e4;
    int unknown_1e8;
    int unknown_1ec;
    int unknown_1f0;
    int unknown_1f4;
    int unknown_1f8;
    int unknown_1fc;
    int unknown_200;
    int unknown_204;
    int unknown_208;
    int unknown_20c;
    int unknown_210;
    int unknown_214;
    int unknown_218;
    int unknown_21c;
    int unknown_220;
    int unknown_224;
    int unknown_228;
    int unknown_22c;
    int unknown_230;
    int unknown_234;
    int unknown_238;
    int unknown_23c;
    int unknown_240;
    int unknown_244;
    int unknown_248;
    int unknown_24c;
    int unknown_250;
    int unknown_254;
    int unknown_258;
    int FUN_0045cd60();
};
struct FUN_00913fe0 : ProcessShim
{
    FUN_00913fe0();
};
struct ProcessListsExtra
{
    void FUN_0096d470(MobileObject* object, int type);
    void FUN_0096d450(MobileObject* object, int enabled, int a, int b, int c);
};
struct MobileObjectVT
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
    virtual void v127(int value);
};
struct FUN_008cf8f0_shell : MobileObject
{
    bool SwitchProcess();
};
// @fnv 0x008cf8f0
bool FUN_008cf8f0_shell::SwitchProcess()
{
    if (m_pBaseProcess && ((ProcessShim*)m_pBaseProcess)->FUN_0045cd60() == 1)
        return true;
    int type = ((ProcessShim*)m_pBaseProcess)->FUN_0045cd60();
    ((ProcessListsExtra*)&DAT_011e0e80)->FUN_0096d470(this, type);
    FUN_00913fe0* process = new FUN_00913fe0();
    process->v1(m_pBaseProcess);
    delete ((ProcessShim*)m_pBaseProcess);
    m_pBaseProcess = (BaseProcess*)process;
    ((ProcessListsExtra*)&DAT_011e0e80)->FUN_0096d450(this, 1, 0, 0, 0);
    ((MobileObjectVT*)this)->v127(0);
    ((ProcessShim*)m_pBaseProcess)->v18();
    return true;
}

float& __fastcall FUN_00403e20(float* pThis);
struct Obj930A
{
    bhkCharacterController* FUN_009306d0();
};
struct ActorV_S
{
    float GetScale();
};
struct FUN_00c6d4b0_Class
{
    void FUN_00c6d4b0(float);
};
bool __fastcall FUN_009306b0(bhkCharacterController* pController);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting847;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting848;
// @fnv 0x00930640
int Holder_00884aa0::UpdateControllerScale()
{
    bhkCharacterController* controller = reinterpret_cast<Obj930A*>(this)->FUN_009306d0();
    if (controller)
    {
        float scale =
            FUN_00403e20((float*)&originalRuntimeFloatSetting847) * reinterpret_cast<ActorV_S*>(this)->GetScale();
        if (FUN_009306b0(controller))
        {
            scale = scale * FUN_00403e20((float*)&originalRuntimeFloatSetting848);
        }
        reinterpret_cast<FUN_00c6d4b0_Class*>(controller)->FUN_00c6d4b0(scale);
    }
    return (int)controller;
}

struct WorkerSaveLoad
{
    bool FUN_0055f5b0();
    bool FUN_0047c850();
};
extern WorkerSaveLoad* DAT_011de45c;
struct WorkerSpinLock
{
    void Lock(const char*);
    void Unlock();
};
extern WorkerSpinLock DAT_011f11a0;
struct WorkerDeleteQueue
{
    void FUN_0096d470(MobileObject*, int);
};

struct WorkerMobile : MobileObject
{
    void FUN_00571b50();
    void FUN_00483710();
    void FUN_004534f0(unsigned int);
    void FUN_0055f240(unsigned int);
    bool FUN_00440da0();
    bool FUN_00440d80();
    int FUN_00931850();
    void FUN_00932750(unsigned int);
};
// @fnv 0x00932750
void WorkerMobile::FUN_00932750(unsigned int flags)
{
    if (flags & 0x20)
    {
        FUN_00571b50();
        FUN_00483710();
        FUN_004534f0(0);
        FUN_00483710();
    }
    FUN_0055f240(flags);
    if (m_pBaseProcess)
        m_pBaseProcess->Revert(flags, this);
    if (DAT_011de45c->FUN_0055f5b0() && DAT_011de45c->FUN_0047c850() && m_pBaseProcess &&
        (FUN_00440da0() || FUN_00440d80()))
    {
        DAT_011f11a0.Lock(0);
        ((WorkerDeleteQueue*)&DAT_011e0e80)->FUN_0096d470(this, FUN_00931850());
        delete m_pBaseProcess;
        m_pBaseProcess = 0;
        DAT_011f11a0.Unlock();
    }
}

class Conversation
{
  public:
    Character* conversation;
    PlayerCharacter* listener;
    TESTopic* topic;
    Conversation(Character*, PlayerCharacter*, TESTopic*);
    bool FUN_0083b9a0();
};
struct FUN_00670b30
{
    int type;
    TESObjectREFR* reference;
    float radius;
    FUN_00670b30();
    ~FUN_00670b30();
    void FUN_0067f3c0(TESObjectREFR*);
};
struct PackageTargetObj
{
    int type;
    TESObjectREFR* reference;
    int count;
    float radius;
    PackageTargetObj();
    ~PackageTargetObj();
    void FUN_006800b0(int);
    void FUN_00680110(TESObjectREFR*);
    void FUN_00403550(unsigned int);
};
struct PackageMethods
{
    void FUN_0067a1b0(TESPackage*);
    void SetPackageType(int);
    void FUN_00826b40(bool);
    void FUN_00826b90(bool);
    void FUN_00671d30(FUN_00670b30*);
    void FUN_00672fc0(PackageTargetObj*);
    void FUN_00984f60(int);
    PackageTargetObj* FUN_00671d10();
};
struct DialogueHost : TESObjectREFR
{
    BaseProcess* process;
    virtual void slot_90();
    virtual void slot_91();
    virtual void slot_92();
    virtual void slot_93();
    virtual void slot_94();
    virtual void slot_95();
    virtual void slot_96();
    virtual void slot_97();
    virtual void slot_98();
    virtual void slot_99();
    virtual void slot_9a();
    virtual void slot_9b();
    virtual void slot_9c();
    virtual void slot_9d();
    virtual void slot_9e();
    virtual void slot_9f();
    virtual void slot_a0();
    virtual void slot_a1();
    virtual void slot_a2();
    virtual void slot_a3();
    virtual void slot_a4();
    virtual void slot_a5();
    virtual void slot_a6();
    virtual void slot_a7();
    virtual void slot_a8();
    virtual void slot_a9();
    virtual void slot_aa();
    virtual void slot_ab();
    virtual void slot_ac();
    virtual void slot_ad();
    virtual void slot_ae();
    virtual void slot_af();
    virtual void slot_b0();
    virtual void slot_b1();
    virtual void slot_b2();
    virtual void slot_b3();
    virtual void slot_b4();
    virtual void slot_b5();
    virtual void slot_b6();
    virtual void slot_b7();
    virtual void slot_b8();
    virtual void slot_b9();
    virtual void slot_ba();
    virtual void slot_bb();
    virtual void slot_bc();
    virtual void SetDialoguePackage(FUN_009edd80*, bool, bool);
    virtual void slot_be();
    virtual void slot_bf();
    virtual MobileObject* GetDialogueSpeaker(MobileObject*, int*);
    int FUN_00931850();
    void FUN_00934250();
    bool FUN_00934fd0(MobileObject* target, int p2, int p3, int p4, int p5, bool refresh, TESTopic* topic, int p8,
                      int p9);
};
struct DialogueLocation : FUN_00670b30
{
};
struct FUN_0067f030
{
    int type;
    TESObjectREFR* reference;
    float radius;
    FUN_0067f030();
};
// @fnv 0x00934fd0
bool DialogueHost::FUN_00934fd0(MobileObject* target, int aiUnused2, int aiUnused3, int aiUnused4, int aiUnused5,
                                bool refresh, TESTopic* topic, int aiUnused8, int aiUnused9)
{
    if (FUN_00931850() || ((DialogueHost*)target)->FUN_00931850())
        return false;
    TESPackage* context = ((MobileObject*)this)->GetCurrentAIProcess()->GetCurrentPackage();
    Conversation* speaker = 0;
    if (!target || (target->Unk_85() != 0 && target->Unk_85() != 4 && target->Unk_85() != 9))
        return false;
    MobileObject* conversation = (MobileObject*)this;
    int previous = 0;
    if (((MobileObject*)this)->IsTalkingActivator())
        conversation = GetDialogueSpeaker(target, &previous);
    if (target != (MobileObject*)g_thePlayer)
        speaker = new Conversation((Character*)conversation, (PlayerCharacter*)target, topic);
    FUN_00934250();
    process->StopRunOncePackage();
    if (target == (MobileObject*)g_thePlayer || speaker->FUN_0083b9a0())
    {
        ((MobileObject*)this)->GetCurrentAIProcess()->SetProcessReference((MobileObject*)this);
        ((MobileObject*)this)->GetCurrentAIProcess()->ClearCachedTargetReferences(true);
        ((MobileObject*)this)->GetCurrentAIProcess()->ClearHighProcessState(target);
        target->GetCurrentAIProcess()->ClearCachedTargetReferences(true);
        target->GetCurrentAIProcess()->ClearHighProcessState(this);
        FUN_009edd80* location =
            new FUN_009edd80((FUN_0083b9a0_shell*)speaker, (Actor*)this, (Actor*)target, previous, true, true);
        location->iUnk8C = (int)topic;
        if (context)
            ((PackageMethods*)location)->FUN_0067a1b0(context);
        ((PackageMethods*)location)->SetPackageType(28);
        ((PackageMethods*)location)->FUN_00826b40(true);
        ((PackageMethods*)location)->FUN_00826b90(true);
        FUN_00670b30* package = (FUN_00670b30*)new FUN_0067f030;
        package->FUN_0067f3c0(target);
        ((PackageMethods*)location)->FUN_00671d30(package);
        delete package;
        PackageTargetObj* destination = new PackageTargetObj;
        ((PackageMethods*)location)->FUN_00672fc0(destination);
        delete destination;
        ((PackageMethods*)location)->FUN_00984f60(10);
        ((PackageMethods*)location)->FUN_00671d10()->FUN_006800b0(0);
        ((PackageMethods*)location)->FUN_00671d10()->FUN_00680110(target);
        if (Unk_85() == 4)
            ((PackageMethods*)location)->FUN_00671d10()->FUN_00403550(200);
        else
            ((PackageMethods*)location)->FUN_00671d10()->FUN_00403550(90);
        ((MobileObject*)this)->GetCurrentAIProcess()->ResetPackageState();
        SetDialoguePackage(location, false, true);
        if (refresh)
            ((MobileObject*)this)->GetCurrentAIProcess()->SetProcessTarget((MobileObject*)this, 1);
        return true;
    }
    return false;
}

struct B9B1450ModelLoader
{
    bool FUN_00445750(TESObjectREFR* pkRef);
};
extern B9B1450ModelLoader* g_pModelLoader;

class FUN_009b1450_Mobile : public MobileObject
{
  public:
    bool FUN_009b1450();
};

// @fnv 0x009b1450
bool FUN_009b1450_Mobile::FUN_009b1450()
{
    bool bResult = true;
    int eCurrent = m_pBaseProcess->GetProcessLevel();
    int eDesired2 = 3;
    TESObjectCELL* pkCell = GetParentCell();
    if ((GetNiNode() || g_pModelLoader->FUN_00445750(this)) && g_TES->IsCellBuffered(pkCell, true))
        eDesired2 = 0;
    if (eCurrent != eDesired2)
    {
        if (eDesired2 == 0)
        {
        }
        else
        {
            delete this;
            bResult = false;
        }
    }
    return bResult;
}

void* __cdecl operator new(unsigned int);
class MiddleHighProcess : public BaseProcess
{
  public:
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
    MiddleHighProcess();
};
struct ProcessLock
{
    void __thiscall Lock(const char*);
    void __thiscall Unlock();
};
extern ProcessLock g_011f11a0;
struct QueueReplacement
{
    void __thiscall FUN_0096d470(MobileObject*, PROCESS_TYPE);
    void __thiscall FUN_0096d450(MobileObject*, int, bool, bool, int);
};
struct FUN_009c4920_shell : public MobileObject
{
    bool __thiscall ReplaceProcessWithMiddleHigh();
};
// @fnv 0x009c4920
bool FUN_009c4920_shell::ReplaceProcessWithMiddleHigh()
{
    g_011f11a0.Lock(0);
    if (m_pBaseProcess)
    {
        PROCESS_TYPE level = m_pBaseProcess->GetProcessLevel();
        ((QueueReplacement*)&DAT_011e0e80)->FUN_0096d470(this, level);
    }
    BaseProcess* process = new MiddleHighProcess;
    process->Copy(m_pBaseProcess);
    delete m_pBaseProcess;
    m_pBaseProcess = process;
    ((QueueReplacement*)&DAT_011e0e80)->FUN_0096d450(this, 1, false, false, 0);
    g_011f11a0.Unlock();
    return true;
}

struct AnimPoint
{
    float x, y, z;
};
struct Audio277
{
    static Audio277* FUN_00453a70();
    SoundPlaybackHandle FUN_00ad7480(int, unsigned int, int);
};
struct Owner277
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
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual NiAVObject* v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual AnimPoint* GetPosition();
    SoundPlaybackHandle PlaySoundAtOwner(int aiID, bool abFlag, unsigned int auiFlags);
};

// @fnv 0x00933010
SoundPlaybackHandle Owner277::PlaySoundAtOwner(int aiID, bool abFlag, unsigned int auiFlags)
{
    SoundPlaybackHandle kHandle;
    kHandle = Audio277::FUN_00453a70()->FUN_00ad7480(aiID, auiFlags, 0);
    if (v1D0() && (auiFlags & 2))
    {
        AnimPoint kPos = *GetPosition();
        kHandle.SetPosition(kPos.x, kPos.y, kPos.z);
        kHandle.SetObjectToFollow(v1D0());
    }
    kHandle.Play(abFlag);
    return kHandle;
}

namespace fnv_009320e0 {
class HighProcess : public BaseProcess
{
  public:
    HighProcess();
    int unk_hp_000;
    int unk_hp_001;
    int unk_hp_002;
    int unk_hp_003;
    int unk_hp_004;
    int unk_hp_005;
    int unk_hp_006;
    int unk_hp_007;
    int unk_hp_008;
    int unk_hp_009;
    int unk_hp_010;
    int unk_hp_011;
    int unk_hp_012;
    int unk_hp_013;
    int unk_hp_014;
    int unk_hp_015;
    int unk_hp_016;
    int unk_hp_017;
    int unk_hp_018;
    int unk_hp_019;
    int unk_hp_020;
    int unk_hp_021;
    int unk_hp_022;
    int unk_hp_023;
    int unk_hp_024;
    int unk_hp_025;
    int unk_hp_026;
    int unk_hp_027;
    int unk_hp_028;
    int unk_hp_029;
    int unk_hp_030;
    int unk_hp_031;
    int unk_hp_032;
    int unk_hp_033;
    int unk_hp_034;
    int unk_hp_035;
    int unk_hp_036;
    int unk_hp_037;
    int unk_hp_038;
    int unk_hp_039;
    int unk_hp_040;
    int unk_hp_041;
    int unk_hp_042;
    int unk_hp_043;
    int unk_hp_044;
    int unk_hp_045;
    int unk_hp_046;
    int unk_hp_047;
    int unk_hp_048;
    int unk_hp_049;
    int unk_hp_050;
    int unk_hp_051;
    int unk_hp_052;
    int unk_hp_053;
    int unk_hp_054;
    int unk_hp_055;
    int unk_hp_056;
    int unk_hp_057;
    int unk_hp_058;
    int unk_hp_059;
    int unk_hp_060;
    int unk_hp_061;
    int unk_hp_062;
    int unk_hp_063;
    int unk_hp_064;
    int unk_hp_065;
    int unk_hp_066;
    int unk_hp_067;
    int unk_hp_068;
    int unk_hp_069;
    int unk_hp_070;
    int unk_hp_071;
    int unk_hp_072;
    int unk_hp_073;
    int unk_hp_074;
    int unk_hp_075;
    int unk_hp_076;
    int unk_hp_077;
    int unk_hp_078;
    int unk_hp_079;
    int unk_hp_080;
    int unk_hp_081;
    int unk_hp_082;
    int unk_hp_083;
    int unk_hp_084;
    int unk_hp_085;
    int unk_hp_086;
    int unk_hp_087;
    int unk_hp_088;
    int unk_hp_089;
    int unk_hp_090;
    int unk_hp_091;
    int unk_hp_092;
    int unk_hp_093;
    int unk_hp_094;
    int unk_hp_095;
    int unk_hp_096;
    int unk_hp_097;
    int unk_hp_098;
    int unk_hp_099;
    int unk_hp_100;
    int unk_hp_101;
    int unk_hp_102;
    int unk_hp_103;
    int unk_hp_104;
    int unk_hp_105;
    int unk_hp_106;
    int unk_hp_107;
    int unk_hp_108;
    int unk_hp_109;
    int unk_hp_110;
    int unk_hp_111;
    int unk_hp_112;
    int unk_hp_113;
    int unk_hp_114;
    int unk_hp_115;
    int unk_hp_116;
    int unk_hp_117;
    int unk_hp_118;
    int unk_hp_119;
    int unk_hp_120;
    int unk_hp_121;
    int unk_hp_122;
    int unk_hp_123;
    int unk_hp_124;
    int unk_hp_125;
    int unk_hp_126;
    int unk_hp_127;
    int unk_hp_128;
    int unk_hp_129;
    int unk_hp_130;
    int unk_hp_131;
    int unk_hp_132;
    int unk_hp_133;
    int unk_hp_134;
    int unk_hp_135;
    int unk_hp_136;
    int unk_hp_137;
    int unk_hp_138;
    int unk_hp_139;
    int unk_hp_140;
    int unk_hp_141;
    int unk_hp_142;
    int unk_hp_143;
    int unk_hp_144;
    int unk_hp_145;
    int unk_hp_146;
    int unk_hp_147;
    int unk_hp_148;
    int unk_hp_149;
    int unk_hp_150;
    int unk_hp_151;
    int unk_hp_152;
    int unk_hp_153;
    int unk_hp_154;
    int unk_hp_155;
    int unk_hp_156;
    int unk_hp_157;
    int unk_hp_158;
    int unk_hp_159;
    int unk_hp_160;
    int unk_hp_161;
    int unk_hp_162;
    int unk_hp_163;
    int unk_hp_164;
    int unk_hp_165;
    int unk_hp_166;
    int unk_hp_167;
    int unk_hp_168;
    int unk_hp_169;
    int unk_hp_170;
    int unk_hp_171;
    int unk_hp_172;
    int unk_hp_173;
    int unk_hp_174;
    int unk_hp_175;
    int unk_hp_176;
    int unk_hp_177;
    int unk_hp_178;
    int unk_hp_179;
    int unk_hp_180;
    int unk_hp_181;
    int unk_hp_182;
    int unk_hp_183;
    int unk_hp_184;
    int unk_hp_185;
    int unk_hp_186;
    int unk_hp_187;
    int unk_hp_188;
    int unk_hp_189;
    int unk_hp_190;
    int unk_hp_191;
    int unk_hp_192;
    int unk_hp_193;
    int unk_hp_194;
    int unk_hp_195;
    int unk_hp_196;
    int unk_hp_197;
    int unk_hp_198;
    int unk_hp_199;
    int unk_hp_200;
    int unk_hp_201;
    int unk_hp_202;
    int unk_hp_203;
    int unk_hp_204;
    int unk_hp_205;
    int unk_hp_206;
    int unk_hp_207;
    int unk_hp_208;
    int unk_hp_209;
    int unk_hp_210;
    int unk_hp_211;
    int unk_hp_212;
    int unk_hp_213;
    int unk_hp_214;
    int unk_hp_215;
    int unk_hp_216;
    int unk_hp_217;
    int unk_hp_218;
    int unk_hp_219;
    int unk_hp_220;
    int unk_hp_221;
    int unk_hp_222;
    int unk_hp_223;
    int unk_hp_224;
    int unk_hp_225;
    int unk_hp_226;
    int unk_hp_227;
    int unk_hp_228;
    int unk_hp_229;
    int unk_hp_230;
    int unk_hp_231;
    int unk_hp_232;
    int unk_hp_233;
    int unk_hp_234;
    int unk_hp_235;
    int unk_hp_236;
    int unk_hp_237;
    int unk_hp_238;
    int unk_hp_239;
    int unk_hp_240;
    int unk_hp_241;
    int unk_hp_242;
    int unk_hp_243;
    int unk_hp_244;
    int unk_hp_245;
    int unk_hp_246;
    int unk_hp_247;
    int unk_hp_248;
    int unk_hp_249;
    int unk_hp_250;
    int unk_hp_251;
    int unk_hp_252;
    int unk_hp_253;
    int unk_hp_254;
    int unk_hp_255;
    int unk_hp_256;
    int unk_hp_257;
    int unk_hp_258;
    int unk_hp_259;
    int unk_hp_260;
    int unk_hp_261;
    int unk_hp_262;
    int unk_hp_263;
    int unk_hp_264;
    int unk_hp_265;
    int unk_hp_266;
    int unk_hp_267;
    int unk_hp_268;
    int unk_hp_269;
    int unk_hp_270;
};
FNV_STATIC_ASSERT(sizeof(HighProcess) == 0x46c);

class MiddleHighProcess : public BaseProcess
{
  public:
    MiddleHighProcess();
    int unk_mhp_000;
    int unk_mhp_001;
    int unk_mhp_002;
    int unk_mhp_003;
    int unk_mhp_004;
    int unk_mhp_005;
    int unk_mhp_006;
    int unk_mhp_007;
    int unk_mhp_008;
    int unk_mhp_009;
    int unk_mhp_010;
    int unk_mhp_011;
    int unk_mhp_012;
    int unk_mhp_013;
    int unk_mhp_014;
    int unk_mhp_015;
    int unk_mhp_016;
    int unk_mhp_017;
    int unk_mhp_018;
    int unk_mhp_019;
    int unk_mhp_020;
    int unk_mhp_021;
    int unk_mhp_022;
    int unk_mhp_023;
    int unk_mhp_024;
    int unk_mhp_025;
    int unk_mhp_026;
    int unk_mhp_027;
    int unk_mhp_028;
    int unk_mhp_029;
    int unk_mhp_030;
    int unk_mhp_031;
    int unk_mhp_032;
    int unk_mhp_033;
    int unk_mhp_034;
    int unk_mhp_035;
    int unk_mhp_036;
    int unk_mhp_037;
    int unk_mhp_038;
    int unk_mhp_039;
    int unk_mhp_040;
    int unk_mhp_041;
    int unk_mhp_042;
    int unk_mhp_043;
    int unk_mhp_044;
    int unk_mhp_045;
    int unk_mhp_046;
    int unk_mhp_047;
    int unk_mhp_048;
    int unk_mhp_049;
    int unk_mhp_050;
    int unk_mhp_051;
    int unk_mhp_052;
    int unk_mhp_053;
    int unk_mhp_054;
    int unk_mhp_055;
    int unk_mhp_056;
    int unk_mhp_057;
    int unk_mhp_058;
    int unk_mhp_059;
    int unk_mhp_060;
    int unk_mhp_061;
    int unk_mhp_062;
    int unk_mhp_063;
    int unk_mhp_064;
    int unk_mhp_065;
    int unk_mhp_066;
    int unk_mhp_067;
    int unk_mhp_068;
    int unk_mhp_069;
    int unk_mhp_070;
    int unk_mhp_071;
    int unk_mhp_072;
    int unk_mhp_073;
    int unk_mhp_074;
    int unk_mhp_075;
    int unk_mhp_076;
    int unk_mhp_077;
    int unk_mhp_078;
    int unk_mhp_079;
    int unk_mhp_080;
    int unk_mhp_081;
    int unk_mhp_082;
    int unk_mhp_083;
    int unk_mhp_084;
    int unk_mhp_085;
    int unk_mhp_086;
    int unk_mhp_087;
    int unk_mhp_088;
    int unk_mhp_089;
    int unk_mhp_090;
    int unk_mhp_091;
    int unk_mhp_092;
    int unk_mhp_093;
    int unk_mhp_094;
    int unk_mhp_095;
    int unk_mhp_096;
    int unk_mhp_097;
    int unk_mhp_098;
    int unk_mhp_099;
    int unk_mhp_100;
    int unk_mhp_101;
    int unk_mhp_102;
    int unk_mhp_103;
    int unk_mhp_104;
    int unk_mhp_105;
    int unk_mhp_106;
    int unk_mhp_107;
    int unk_mhp_108;
    int unk_mhp_109;
    int unk_mhp_110;
    int unk_mhp_111;
    int unk_mhp_112;
    int unk_mhp_113;
    int unk_mhp_114;
    int unk_mhp_115;
    int unk_mhp_116;
    int unk_mhp_117;
    int unk_mhp_118;
    int unk_mhp_119;
    int unk_mhp_120;
    int unk_mhp_121;
    int unk_mhp_122;
    int unk_mhp_123;
    int unk_mhp_124;
    int unk_mhp_125;
    int unk_mhp_126;
    int unk_mhp_127;
    int unk_mhp_128;
    int unk_mhp_129;
    int unk_mhp_130;
    int unk_mhp_131;
    int unk_mhp_132;
    int unk_mhp_133;
    int unk_mhp_134;
    int unk_mhp_135;
    int unk_mhp_136;
    int unk_mhp_137;
    int unk_mhp_138;
};
FNV_STATIC_ASSERT(sizeof(MiddleHighProcess) == 0x25c);

class FUN_0092c950 : public BaseProcess
{
  public:
    FUN_0092c950();
    int unk_mlp_000;
    int unk_mlp_001;
    int unk_mlp_002;
    int unk_mlp_003;
    int unk_mlp_004;
    int unk_mlp_005;
    int unk_mlp_006;
    int unk_mlp_007;
    int unk_mlp_008;
    int unk_mlp_009;
    int unk_mlp_010;
    int unk_mlp_011;
    int unk_mlp_012;
    int unk_mlp_013;
    int unk_mlp_014;
    int unk_mlp_015;
    int unk_mlp_016;
    int unk_mlp_017;
    int unk_mlp_018;
    int unk_mlp_019;
    int unk_mlp_020;
    int unk_mlp_021;
    int unk_mlp_022;
    int unk_mlp_023;
    int unk_mlp_024;
    int unk_mlp_025;
    int unk_mlp_026;
    int unk_mlp_027;
    int unk_mlp_028;
    int unk_mlp_029;
    int unk_mlp_030;
    int unk_mlp_031;
    int unk_mlp_032;
    int unk_mlp_033;
    int unk_mlp_034;
    int unk_mlp_035;
    int unk_mlp_036;
    int unk_mlp_037;
};
FNV_STATIC_ASSERT(sizeof(FUN_0092c950) == 0xc8);

class FUN_00906dc0 : public BaseProcess
{
  public:
    FUN_00906dc0();
    int unk_lp_000;
    int unk_lp_001;
    int unk_lp_002;
    int unk_lp_003;
    int unk_lp_004;
    int unk_lp_005;
    int unk_lp_006;
    int unk_lp_007;
    int unk_lp_008;
    int unk_lp_009;
    int unk_lp_010;
    int unk_lp_011;
    int unk_lp_012;
    int unk_lp_013;
    int unk_lp_014;
    int unk_lp_015;
    int unk_lp_016;
    int unk_lp_017;
    int unk_lp_018;
    int unk_lp_019;
    int unk_lp_020;
    int unk_lp_021;
    int unk_lp_022;
    int unk_lp_023;
    int unk_lp_024;
    int unk_lp_025;
    int unk_lp_026;
    int unk_lp_027;
    int unk_lp_028;
    int unk_lp_029;
    int unk_lp_030;
    int unk_lp_031;
    int unk_lp_032;
};
FNV_STATIC_ASSERT(sizeof(FUN_00906dc0) == 0xb4);

class ProcessVTableFix
{
  public:
    virtual void v_000();
    virtual void v_001();
    virtual void v_002();
    virtual void v_003();
    virtual void v_004();
    virtual void v_005();
    virtual void v_006();
    virtual void v_007();
    virtual void v_008();
    virtual void v_009();
    virtual void v_010();
    virtual void v_011();
    virtual void v_012();
    virtual void v_013();
    virtual void v_014();
    virtual void v_015();
    virtual void v_016();
    virtual void v_017();
    virtual void v_018();
    virtual void v_019();
    virtual void v_020();
    virtual void v_021();
    virtual void v_022();
    virtual void v_023();
    virtual void v_024();
    virtual void v_025();
    virtual void v_026();
    virtual void v_027();
    virtual void v_028();
    virtual void v_029();
    virtual void v_030();
    virtual void v_031();
    virtual void v_032();
    virtual void v_033();
    virtual void v_034();
    virtual void v_035();
    virtual void v_036();
    virtual void v_037();
    virtual void v_038();
    virtual void v_039();
    virtual void v_040();
    virtual void v_041();
    virtual void v_042();
    virtual void v_043();
    virtual void v_044();
    virtual void v_045();
    virtual void v_046();
    virtual void v_047();
    virtual void v_048();
    virtual void v_049();
    virtual void v_050();
    virtual void v_051();
    virtual void v_052();
    virtual void v_053();
    virtual void v_054();
    virtual void v_055();
    virtual void v_056();
    virtual void v_057();
    virtual void v_058();
    virtual void v_059();
    virtual void v_060();
    virtual void v_061();
    virtual void v_062();
    virtual void v_063();
    virtual void v_064();
    virtual void v_065();
    virtual void v_066();
    virtual void v_067();
    virtual void v_068();
    virtual void v_069();
    virtual void v_070();
    virtual void v_071();
    virtual void v_072();
    virtual void v_073();
    virtual void v_074();
    virtual void v_075();
    virtual void v_076();
    virtual void v_077();
    virtual void v_078();
    virtual void v_079();
    virtual void v_080();
    virtual void v_081();
    virtual void v_082();
    virtual void v_083();
    virtual void v_084();
    virtual void v_085();
    virtual void v_086();
    virtual void v_087();
    virtual void v_088();
    virtual void v_089();
    virtual void v_090();
    virtual void v_091();
    virtual void v_092();
    virtual void v_093();
    virtual void v_094();
    virtual void v_095();
    virtual void v_096();
    virtual void v_097();
    virtual void v_098();
    virtual void v_099();
    virtual void v_100();
    virtual void v_101();
    virtual void v_102();
    virtual void v_103();
    virtual void v_104();
    virtual void v_105();
    virtual void v_106();
    virtual void v_107();
    virtual void v_108();
    virtual void v_109();
    virtual void v_110();
    virtual void v_111();
    virtual void v_112();
    virtual void v_113();
    virtual void v_114();
    virtual void v_115();
    virtual void v_116();
    virtual void v_117();
    virtual void v_118();
    virtual void v_119();
    virtual void v_120();
    virtual void v_121();
    virtual void v_122();
    virtual void v_123();
    virtual void v_124();
    virtual void v_125();
    virtual void v_126();
    virtual void v_127();
    virtual void v_128();
    virtual void v_129();
    virtual void v_130();
    virtual void v_131();
    virtual void v_132();
    virtual void v_133();
    virtual void v_134();
    virtual void v_135();
    virtual void v_136();
    virtual void v_137();
    virtual void v_138();
    virtual void v_139();
    virtual void v_140();
    virtual void v_141();
    virtual void v_142();
    virtual void v_143();
    virtual void v_144();
    virtual void v_145();
    virtual void v_146();
    virtual void v_147();
    virtual void v_148();
    virtual void v_149();
    virtual void v_150();
    virtual void v_151();
    virtual void v_152();
    virtual void v_153();
    virtual void v_154();
    virtual void v_155();
    virtual void v_156();
    virtual void v_157();
    virtual void v_158();
    virtual void v_159();
    virtual void v_160();
    virtual void v_161();
    virtual void v_162();
    virtual void v_163();
    virtual void v_164();
    virtual void v_165();
    virtual void v_166();
    virtual void v_167();
    virtual void v_168();
    virtual void v_169();
    virtual void v_170();
    virtual void v_171();
    virtual void v_172();
    virtual void v_173();
    virtual void v_174();
    virtual void v_175();
    virtual void v_176();
    virtual void v_177();
    virtual void v_178();
    virtual void v_179();
    virtual void v_180();
    virtual void v_181();
    virtual void v_182();
    virtual void v_183();
    virtual void v_184();
    virtual void v_185();
    virtual void v_186();
    virtual void v_187();
    virtual void v_188();
    virtual void v_189();
    virtual void v_190();
    virtual void v_191();
    virtual void v_192();
    virtual void v_193();
    virtual void v_194();
    virtual void v_195();
    virtual void v_196();
    virtual void v_197();
    virtual void v_198();
    virtual void v_199();
    virtual void v_200();
    virtual void v_201();
    virtual void v_202();
    virtual void v_203();
    virtual void v_204();
    virtual void v_205();
    virtual void v_206();
    virtual void v_207();
    virtual void v_208();
    virtual void v_209();
    virtual void v_210();
    virtual void v_211();
    virtual void v_212();
    virtual void v_213();
    virtual void v_214();
    virtual void v_215();
    virtual void v_216();
    virtual void v_217();
    virtual void v_218();
    virtual void v_219();
    virtual void v_220();
    virtual void v_221();
    virtual void v_222();
    virtual void v_223();
    virtual void v_224();
    virtual void v_225();
    virtual void v_226();
    virtual void v_227();
    virtual void v_228();
    virtual void v_229();
    virtual void v_230();
    virtual void v_231();
    virtual void v_232();
    virtual void v_233();
    virtual void v_234();
    virtual void v_235();
    virtual void v_236();
    virtual void v_237();
    virtual void v_238();
    virtual void v_239();
    virtual void v_240();
    virtual void v_241();
    virtual void v_242();
    virtual void v_243();
    virtual void v_244();
    virtual void v_245();
    virtual void v_246();
    virtual void v_247();
    virtual void v_248();
    virtual void v_249();
    virtual void v_250();
    virtual void v_251();
    virtual void v_252();
    virtual void v_253();
    virtual void v_254();
    virtual void v_255();
    virtual void v_256();
    virtual void v_257();
    virtual void v_258();
    virtual void v_259();
    virtual void v_260();
    virtual void v_261();
    virtual void v_262();
    virtual void v_263();
    virtual void v_264();
    virtual void v_265();
    virtual void v_266();
    virtual void v_267();
    virtual void v_268();
    virtual void v_269();
    virtual void v_270();
    virtual void v_271();
    virtual void v_272();
    virtual void v_273();
    virtual void v_274();
    virtual void v_275();
    virtual void v_276();
    virtual void v_277();
    virtual void v_278();
    virtual void v_279();
    virtual void v_280();
    virtual void v_281();
    virtual void v_282();
    virtual void v_283();
    virtual void v_284();
    virtual void v_285();
    virtual void v_286();
    virtual void v_287();
    virtual void v_288();
    virtual void v_289();
    virtual void v_290();
    virtual void v_291();
    virtual void v_292();
    virtual void v_293();
    virtual void v_294();
    virtual void v_295();
    virtual void v_296();
    virtual void v_297();
    virtual void v_298();
    virtual void v_299();
    virtual void v_300();
    virtual void v_301();
    virtual void v_302();
    virtual void v_303();
    virtual void v_304();
    virtual void v_305();
    virtual void v_306();
    virtual void v_307();
    virtual void v_308();
    virtual void v_309();
    virtual void v_310();
    virtual void v_311();
    virtual void v_312();
    virtual void v_313();
    virtual void v_314();
    virtual void v_315();
    virtual void v_316();
    virtual void v_317();
    virtual void v_318();
    virtual void v_319();
    virtual void v_320();
    virtual void v_321();
    virtual void v_322();
    virtual void v_323();
    virtual void v_324();
    virtual void v_325();
    virtual void v_326();
    virtual void v_327();
    virtual void v_328();
    virtual void v_329();
    virtual void v_330();
    virtual void v_331();
    virtual void v_332();
    virtual void v_333();
    virtual void v_334();
    virtual void v_335();
    virtual void v_336();
    virtual void v_337();
    virtual void v_338();
    virtual void v_339();
    virtual void v_340();
    virtual void v_341();
    virtual void Method_0x558(void* arg1, void* arg2, MobileObject* actor);
};

class Host096d450
{
  public:
    void FUN_0096d450(MobileObject* actor, int level, bool b1, bool b2, bool b3);
};

class ActorDeletionQueue
{
  public:
    void FUN_0096d470(MobileObject* actor, int level);
};

struct GlobalLock_011f11a0
{
    void Lock(const char*);
    void Unlock();
};

extern "C" GlobalLock_011f11a0 DAT_011f11a0;
extern "C" void* DAT_011e0e80;

class TES
{
  public:
    bool FUN_004511e0(TESObjectCELL* cell, int unk);
};
extern TES* g_TES;

class FUN_009320e0_class : public Actor
{
  public:
    void FUN_00484d00(void* pData, int size);
    void FUN_0055ec40(void* arg1, void* arg2);
    void SetProcessLevel(void* arg1, void* arg2);
};

// @fnv 0x009320e0
void FUN_009320e0_class::SetProcessLevel(void* arg1, void* arg2)
{
    char processType;
    FUN_00484d00(&processType, 1);
    switch (processType)
    {
    case PROCESS_TYPE_PROCESS_TYPE_NONE:
        if (m_pBaseProcess)
        {
            DAT_011f11a0.Lock(0);
            ((ActorDeletionQueue*)&DAT_011e0e80)->FUN_0096d470(this, m_pBaseProcess->GetProcessLevel());
            delete m_pBaseProcess;
            DAT_011f11a0.Unlock();
            m_pBaseProcess = 0;
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_HIGH:
        if (m_pBaseProcess)
        {
            if (m_pBaseProcess->GetProcessLevel() != PROCESS_TYPE_PROCESS_TYPE_HIGH)
            {
                StartHighProcess();
            }
        }
        else
        {
            m_pBaseProcess = new HighProcess();
            ((Host096d450*)&DAT_011e0e80)->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_HIGH, false, false, false);
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH:
        if (m_pBaseProcess)
        {
            if (m_pBaseProcess->GetProcessLevel() != PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH)
            {
                Unk_93();
            }
        }
        else
        {
            m_pBaseProcess = new MiddleHighProcess();
            ((Host096d450*)&DAT_011e0e80)
                ->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH, false, false, false);
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW:
        if (m_pBaseProcess)
        {
            if (m_pBaseProcess->GetProcessLevel() != PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW)
            {
                Unk_92();
            }
        }
        else
        {
            m_pBaseProcess = new FUN_0092c950();
            ((Host096d450*)&DAT_011e0e80)
                ->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW, false, false, false);
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_LOW:
        if (m_pBaseProcess)
        {
            if (m_pBaseProcess->GetProcessLevel() != PROCESS_TYPE_PROCESS_TYPE_LOW)
            {
                Unk_91();
            }
        }
        else
        {
            m_pBaseProcess = new FUN_00906dc0();
            ((Host096d450*)&DAT_011e0e80)->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_LOW, false, false, false);
        }
        break;
    }

    if (GetNiNode())
    {
        if (!g_TES->FUN_004511e0(GetParentCell(), 0) || processType != 0)
        {
            Set3D(0, true);
        }
    }

    FUN_0055ec40(arg1, arg2);

    if (m_pBaseProcess)
    {
        ((ProcessVTableFix*)m_pBaseProcess)->Method_0x558(arg1, arg2, this);
    }
}
}  // namespace fnv_009320e0

namespace fnv_009339a0 {
struct GlobalObject_0041a250
{
    int unk00, unk04, unk08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    void FUN_00418900(const GlobalObject_0041a250&);
    bool Play(bool);
    void* FUN_00559450(void*, unsigned);
};
struct Audio
{
    GlobalObject_0041a250 FUN_00ad73b0(unsigned, unsigned);
    void FUN_00adbfd0(void*);
};
Audio* FUN_00453a70();
Audio* FUN_00ad9060();
void FUN_00935cc0();
void FUN_00935d90();
struct Obj;
extern Obj* DAT_011e0548;
extern Obj* DAT_011dea3c;
struct Obj
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual Obj* v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual Obj* v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268(float);
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual float v284(void*);
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8(float);
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318(float);
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
    unsigned char unk7C;
    unsigned char unk7D;
    unsigned char unk7E;
    unsigned char unk7F;
    unsigned char unk80;
    unsigned char unk81;
    unsigned char unk82;
    unsigned char unk83;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    Obj* FUN_008d8520();
    int FUN_0041ca90();
    Obj* FUN_007af430();
    unsigned FUN_0084e3a0();
    int FUN_005e3fa0();
    GlobalObject_0041a250 PlaySoundByFormID(unsigned, int, unsigned, int);
    int FUN_00441110(Obj*);
    int FUN_009611e0();
    Obj* FUN_006815c0();
    int FUN_004048e0();
    int FUN_0044ddc0();
    Obj* FUN_00460140();
    void* FUN_00559450(GlobalObject_0041a250*, int, int, int, int, int, int, int, int, int, int);
    Obj* FUN_008d6f30();
    void FUN_0054baf0();
    void FUN_009339a0(float, Obj*, bool);
};
// @fnv 0x009339a0
void Obj::FUN_009339a0(float delta, Obj* target, bool skip)
{
    Obj* data7 = v1e4();
    Obj* actor_ = 0;
    Obj* form4 = FUN_008d8520()->v22c();
    if (form4 && form4->FUN_0041ca90() == 28)
        actor_ = form4;
    bool aUnused4 = false;
    bool changedVal = false;
    if (target && FUN_008d8520() && unk7C)
    {
        GlobalObject_0041a250 sound;
        changedVal = true;
        DAT_011e0548 = this;
        unk7D = 1;
        bool pending = true;
        if (target->FUN_007af430())
        {
            unsigned id2 = target->FUN_007af430()->FUN_0084e3a0();
            GlobalObject_0041a250 _other;
            if (FUN_005e3fa0())
            {
                int progressA = FUN_005e3fa0();
                _other.FUN_00418900(FUN_00453a70()->FUN_00ad73b0(id2, 0x105));
                _other.Play(false);
            }
            else
            {
                _other.FUN_00418900(PlaySoundByFormID(id2, 0, 0x40000102, 1));
            }
            Audio* manager4 = FUN_00ad9060();
            manager4->FUN_00adbfd0(_other.FUN_00559450((void*)FUN_00935cc0, FUN_0084e3a0()));
            pending = false;
            unk7F = 0;
            unk7C = 0;
        }
        if (pending & unk7F)
        {
            float volumeA = v284(target->FUN_00460140()->FUN_00559450(
                &sound, target->FUN_0044ddc0(), target->FUN_0084e3a0(), target->FUN_006815c0()->FUN_004048e0(),
                target->FUN_009611e0(), target->FUN_00441110(DAT_011dea3c), 1, 1, 0, 1, 1));
            Audio* manager3 = FUN_00ad9060();
            manager3->FUN_00adbfd0(sound.FUN_00559450((void*)FUN_00935d90, FUN_0084e3a0()));
            unk80 = 0;
            FUN_008d8520()->v318(volumeA);
        }
    }
    if (!skip)
        v268(delta);
    v140();
    if (!skip)
        v2f8(delta);
    if (changedVal && actor_)
        actor_->unk94 = (int)this;
    Obj* item_ = FUN_008d6f30();
    if (item_)
        item_->FUN_0054baf0();
    v178();
}
}  // namespace fnv_009339a0

class TESObjectCELL;

class GlobalE3D0
{
  public:
    bool FUN_004511e0(TESObjectCELL* pkCell, int iFlag);
};

namespace GlobalsE3D0 {
extern GlobalE3D0* DAT_011dea10;
}
using GlobalsE3D0::DAT_011dea10;

class FUN_0081e3d0_C
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual ~FUN_0081e3d0_C();

    TESObjectCELL* FUN_008d6f30();
    bool FUN_0081e3d0();
};

// @fnv 0x0081e3d0
bool FUN_0081e3d0_C::FUN_0081e3d0()
{
    bool bResult = true;
    if (!DAT_011dea10->FUN_004511e0(FUN_008d6f30(), 1))
    {
        delete this;
        bResult = false;
    }
    return bResult;
}

template <> NiPointer<bhkCharacterController>::NiPointer(bhkCharacterController*);
template <> NiPointer<bhkCharacterController>::NiPointer(const NiPointer<bhkCharacterController>&);
template <> NiPointer<bhkCharacterController>::~NiPointer();
struct OwnerBase
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual bool v2a0();
};
struct Owner : OwnerBase
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
    BaseProcess* m_pBaseProcess;
    bool ReleaseCharacterController();
};
// Calls v2a0, then if m_pBaseProcess is set, assigns a null bhkCharacterController to it and returns the result of v2a0.
// @fnv 0x00930810
bool Owner::ReleaseCharacterController()
{
    bool result = v2a0();
    if (m_pBaseProcess)
        m_pBaseProcess->AssignCharacterController(NiPointer<bhkCharacterController>(0));
    return result;
}

class xProc
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
    virtual void Reset();
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
    virtual class xActorD* GetTarget();
    virtual void SetTarget(class xActorD* p);
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
    virtual void Refresh();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual int GetStateX();
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
    virtual void SetDialogue(class xActorD* p, int i);
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
    virtual void SetPartner(class xActorD* p);
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void SetTalking(int i);
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
    virtual void ClearPartner(class xActorD* p);
    void Update();
};
struct xInfo
{
    bool IsSilent();
    int GetPrevPath();
    bool MustReach();
    bool MustComplete();
    void* GetLocationPointer();
    void* GetLoc2();
    void* GetTarget();
};
class xConv
{
  public:
    int m_ai[3];
    xConv(class xActorD* pA, class xActorD* pB, void* pTopic);
    bool Start();
};
class xPkg
{
  public:
    int m_ai[0x34];
    xPkg(xConv* pConv, class xActorD* pA, class xActorD* pB, int i, bool b1, bool b2);
    void CopyFrom(xInfo* pInfo);
    void SetFlag(int i);
    void SetMustReach(bool b);
    void SetMustComplete(bool b);
    void SetLoc(void* p);
    void SetLoc2(void* p);
    void SetTarget(void* p);
    void SetProcType(int i);
};
class xActorD
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
    virtual bool IsBusyX(int i);
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
    virtual void AddPackage(class xPkg* p, int a, int b);
    int m_aiPad[0x19];
    xProc* m_pkProc;
    xProc* GetProcess();
    void StopTalk();
    void SetSpeaker(xActorD* p);
    xPkg* GetCurrentPackage();
    bool StartConversation(xInfo* pInfo);
};
extern xActorD* xThePlayer;

// On success, builds a package from pInfo, updates process state, and adds packages for the actors when applicable.
// @fnv 0x00935480
bool xActorD::StartConversation(xInfo* pInfo)
{
    int qrEZrs = GetProcess()->GetStateX();
    xConv* qsSDDgz = 0;
    xActorD* qfTOqo = m_pkProc->GetTarget();
    if (qfTOqo != xThePlayer)
        qsSDDgz = new xConv(this, qfTOqo, 0);
    StopTalk();
    m_pkProc->Refresh();
    if (qfTOqo == xThePlayer || qsSDDgz->Start())
    {
        if (!pInfo->IsSilent())
        {
            GetProcess()->SetTalking(1);
            GetProcess()->SetPartner(qfTOqo);
            qfTOqo->GetProcess()->SetTalking(1);
            qfTOqo->GetProcess()->SetPartner(this);
        }
        xPkg* qxQHW = new xPkg(qsSDDgz, this, qfTOqo, 0, 0, pInfo->GetPrevPath() == 0);
        if (pInfo)
            qxQHW->CopyFrom(pInfo);
        qxQHW->SetFlag(0x1c);
        qxQHW->SetMustReach(pInfo->MustReach());
        qxQHW->SetMustComplete(pInfo->MustComplete());
        qxQHW->SetLoc(pInfo->GetLocationPointer());
        qxQHW->SetLoc2(pInfo->GetLoc2());
        qxQHW->SetTarget(pInfo->GetTarget());
        qxQHW->SetProcType(10);
        GetProcess()->Reset();
        AddPackage(qxQHW, 0, 1);
        SetSpeaker(qfTOqo);
        m_pkProc->SetTarget(qfTOqo);
        m_pkProc->Update();
        m_pkProc->Update();
        if (qfTOqo != xThePlayer && qfTOqo != this)
        {
            qfTOqo->GetProcess()->ClearPartner(qfTOqo);
            qfTOqo->AddPackage(GetCurrentPackage(), 0, 1);
            qfTOqo->GetProcess()->SetTarget(qfTOqo);
            qfTOqo->SetSpeaker(this);
        }
        else if (!qfTOqo->IsBusyX(0))
            GetProcess()->SetDialogue(this, 3);
        return true;
    }
    return false;
}

class FUN_00932070_MobileObject : public MobileObject
{
  public:
    void FUN_00484ce0(char* data, unsigned int size);
    void FUN_0055e940(unsigned int saveID);
    void SaveProcess(unsigned int saveID);
};

// Saves the base process level and calls SaveGame on m_pBaseProcess with the given saveID.
// @fnv 0x00932070
void FUN_00932070_MobileObject::SaveProcess(unsigned int saveID)
{
    char level = -1;
    if (m_pBaseProcess)
    {
        level = m_pBaseProcess->GetProcessLevel();
    }
    FUN_00484ce0(&level, 1);
    FUN_0055e940(saveID);
    if (m_pBaseProcess)
    {
        m_pBaseProcess->SaveGame(saveID, this);
    }
}

extern NiPoint3 DAT_011e05d0;

class MagicProjectileTarget
{
  public:
    void __thiscall FUN_0050ea10(NiPoint3& point) const;
};

class MagicProjectileRef
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual void vf428();
    virtual void vf42c();
    virtual void vf430();
    virtual void vf434();
    virtual void vf438();
    virtual void vf43c();
    virtual void vf440();
    virtual void vf444();
    virtual void vf448();
    virtual void vf44c();
    virtual void vf450();
    virtual void vf454();
    virtual void vf458();
    virtual void vf45c();
    virtual void vf460();
    virtual void vf464();
    virtual void vf468();
    virtual void vf46c();
    virtual void vf470();
    virtual void vf474();
    virtual void vf478();
    virtual void vf47c();
    virtual void vf480();
    virtual void vf484();
    virtual void vf488();
    virtual void vf48c();
    virtual void vf490();
    virtual void vf494();
    virtual void vf498();
    virtual void vf49c();
    virtual void vf4a0();
    virtual void vf4a4();
    virtual void vf4a8();
    virtual void vf4ac();
    virtual void vf4b0();
    virtual void vf4b4();
    virtual void vf4b8();
    virtual void vf4bc();
    virtual void vf4c0();
    virtual void vf4c4();
    virtual void vf4c8();
    virtual void vf4cc();
    virtual void vf4d0();
    virtual void vf4d4();
    virtual void vf4d8();
    virtual void vf4dc();
    virtual void vf4e0();
    virtual void vf4e4();
    virtual void vf4e8();
    virtual void vf4ec();
    virtual void vf4f0();
    virtual void vf4f4();
    virtual void vf4f8();
    virtual void vf4fc();
    virtual void vf500();
    virtual void vf504();
    virtual void vf508();
    virtual void vf50c();
    virtual void vf510();
    virtual void vf514();
    virtual void vf518();
    virtual void vf51c();
    virtual void vf520();
    virtual void vf524();
    virtual void vf528();
    virtual void vf52c();
    virtual void vf530();
    virtual void vf534();
    virtual void vf538();
    virtual void vf53c();
    virtual void vf540();
    virtual void vf544();
    virtual void vf548();
    virtual void vf54c();
    virtual void vf550();
    virtual void vf554();
    virtual void vf558();
    virtual void vf55c();
    virtual void vf560();
    virtual void vf564();
    virtual void vf568();
    virtual void vf56c();
    virtual void vf570();
    virtual void vf574();
    virtual void vf578();
    virtual void vf57c();
    virtual void vf580();
    virtual void vf584();
    virtual void vf588();
    virtual void vf58c();
    virtual void vf590();
    virtual void vf594();
    virtual void vf598();
    virtual void vf59c();
    virtual void vf5a0();
    virtual void vf5a4();
    virtual void vf5a8();
    virtual void vf5ac();
    virtual void vf5b0();
    virtual void vf5b4();
    virtual void vf5b8();
    virtual void vf5bc();
    virtual void vf5c0();
    virtual void vf5c4();
    virtual void vf5c8();
    virtual void vf5cc();
    virtual void vf5d0();
    virtual void vf5d4();
    virtual void vf5d8();
    virtual void vf5dc();
    virtual void vf5e0();
    virtual void vf5e4();
    virtual void vf5e8();
    virtual void vf5ec();
    virtual MagicProjectileTarget* vf5f0();
};

class MagicProjectileObject
{
  public:
    void* vtbl00;
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
    MagicProjectileRef* unk68;

    NiPoint3 __thiscall FUN_0056fb10();
    NiPoint3 __thiscall FUN_00933630();
};

// @fnv 0x00933630
NiPoint3 __thiscall MagicProjectileObject::FUN_00933630()
{
    if (unk68 && unk68->vf5f0())
    {
        MagicProjectileTarget* target = unk68->vf5f0();
        target->FUN_0050ea10(DAT_011e05d0);
        return DAT_011e05d0;
    }
    return FUN_0056fb10();
}

struct Mid83b9a0
{
    int _pad[2];
    Mid83b9a0* _p8;
    int* _ref_006815c0();
    bool FUN_0083b9a0();
};
// Sets _p8 to this, then returns whether the value pointed to by _ref_006815c0() is non-zero.
// @fnv 0x0083b9a0
bool Mid83b9a0::FUN_0083b9a0()
{
    _p8 = this;
    return _p8 && *_p8->_ref_006815c0() ? 1 : 0;
}

namespace fnv_009344d0 {
// Based on the earlier contributor's candidate; call contracts reconstructed from the target.
struct SoundRef
{
    unsigned int id;
    int unk04;
    int unk08;
    SoundRef(const SoundRef&);
    ~SoundRef();
    SoundRef& operator=(const SoundRef&);
    SoundRef& FUN_00418900(const SoundRef&);
    unsigned int FUN_00559450();
    void FUN_00ad8be0(float, float);
    bool SetPos(float, float, float);
    void SetNiNode(void*);
    bool SetStaticAttenuation(int);
    void FUN_00ad8870(int, int);
    int FUN_00ad8b30();
};
struct FUN_0040c0e0
{
    char* data;
    unsigned short length;
    unsigned short capacity;
    FUN_0040c0e0(const char*);
    ~FUN_0040c0e0();
    const char* FUN_00559450();
};
struct Package
{
    int FUN_005f36f0();
};
struct Item
{
    ~Item();
    unsigned int FUN_00559450();
    void FUN_004d5930(void*, float);
    double GetNegativeMagnitude();
    int FUN_004d5850(int);
};
struct ActorObject;
struct Process
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
    virtual void v17(ActorObject*, int, int, int, int, int);
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
    virtual void v85(int);
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
    virtual void v187(unsigned int);
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
    virtual void v220(int);
    virtual void v221(int);
    virtual unsigned char v222();
    virtual Item* v223();
    virtual void v224(int);
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
    virtual void v292(int, SoundRef);
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
    virtual void v459();
    virtual void v460();
    virtual void v461();
    virtual void v462();
    virtual void v463();
    virtual void v464();
    virtual void v465(Item*);
    virtual Item* v466();
    virtual void v467(int);
};
struct ActorObject
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
    virtual unsigned char v63();
    virtual unsigned char v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73(void*);
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
    virtual ActorObject* v110(int);
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual int v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const struct Point* v125();
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
    virtual void v181(unsigned int);
    virtual void v182();
    virtual void v183(unsigned int);
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
    Process* process;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    unsigned char flag7c;
    unsigned char flag7d;
    unsigned char FUN_00574900();
    __forceinline Process* GetProcess()
    {
        return (Process*)((MobileObject*)this)->GetCurrentAIProcess();
    }
    void FUN_00934250();
    double FUN_005723b0(void*, int, int);
    unsigned int FUN_0084e3a0();
    Package* FUN_009344a0();
    void* FUN_005e3fa0();
    float FUN_009344d0(const char*, SoundRef*, unsigned int, unsigned int, int, int, int, ActorObject*, unsigned char,
                       unsigned char, unsigned char, unsigned char, unsigned char);
};
struct Point
{
    float x, y, z;
};
struct Node
{
    void* FUN_007af430();
};
struct Setting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
};
struct EventManager
{
    void StartLipSyncTask(ActorObject*, const char*);
};
struct Audio
{
    SoundRef FUN_00ad7480(const char*, unsigned int, int);
};
typedef void(__cdecl* SoundCallback)(void*, unsigned int);
struct AudioManager
{
    void FUN_00adc050(unsigned int, SoundCallback, unsigned int);
};
struct Clock
{
    int FUN_00825c00();
};
struct PlayerCharacter_ext : public PlayerCharacter
{
    bool FUN_004eaf60();
};
extern float DAT_011d951c;
extern Setting g_011cd378, originalRuntimeFloatSetting1221, g_011e060c, originalRuntimeFloatSetting184;
extern EventManager g_011f11e0;
extern Clock g_timeGlobal;
extern double DAT_0101db88, DAT_01017b70, DAT_01012060, DAT_01017a40;
extern float g_011c56fc_arg1;
extern char str_01084d70;
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
bool __cdecl BuildLipPath(FUN_0040c0e0&);
Item* __cdecl FUN_004d52d0(const FUN_0040c0e0&);
void __cdecl SetFormAccumulate(void*, unsigned int);
Audio* __cdecl FUN_00453a70();
AudioManager* __cdecl FUN_00ad9060();
float __cdecl FUN_005790d0();
float __cdecl FUN_005790b0();
double __cdecl FUN_008a2d20();
// Creates and queues a named sound, configures playback parameters, and returns a computed float.
// @fnv 0x009344d0
float ActorObject::FUN_009344d0(const char* apSoundName, SoundRef* apSoundRef, unsigned int arg3, unsigned int arg4,
                                int duration, int target, int otherTarget, ActorObject* other, unsigned char update,
                                unsigned char playerSound, unsigned char arg11, unsigned char arg12,
                                unsigned char force)
{
    AudioManager* mgr;
    int activeVal;
    unsigned char playFlag;
    {
        Item* curItem;

        if (!FUN_00574900())
            return 0.0f;
        {
            char text[512];
            float elapsed = 0.0f;
            FUN_0040c0e0 callState2(apSoundName);
            curItem = GetProcess()->v223();
            ActorObject* isPlayer = 0;
            v181(arg3);
            v183(arg4);
            if (apSoundName == 0)
                return 0.0f;
            FUN_00406d30(text, 512, apSoundName);
            FUN_00934250();
            unsigned char child = (unsigned char)(int)(this == (void*)_g_thePlayer);
            float active = 0.0f;
            float timeMs;
            playFlag = child ? (unsigned char)1 : playerSound;
            if (FUN_005723b0(_g_thePlayer, 0, 0) < *g_011cd378.FUN_0043d4d0() &&
                (!child || (child && ((PlayerCharacter_ext*)_g_thePlayer)->FUN_004eaf60())))
                isPlayer = v110(0);
            if (!curItem)
            {
                if (arg12 && !GetProcess()->v222())
                {
                    if (BuildLipPath(callState2))
                    {
                        if (arg11)
                        {
                            GetProcess()->v220(1);
                            GetProcess()->v85(1);
                            g_011f11e0.StartLipSyncTask(this, callState2.FUN_00559450());
                            return 0.0f;
                        }
                        else
                        {
                            curItem = FUN_004d52d0(callState2);
                            if (!curItem)
                                DAT_011d951c = *originalRuntimeFloatSetting1221.FUN_00403e20();
                            GetProcess()->v220(0);
                        }
                    }
                }
                else
                {
                    ActorObject* found;
                    found = v110(0);
                    if (found)
                        found->v73(&str_01084d70);
                    if (GetProcess()->v222())
                    {
                        SetFormAccumulate((void*)FUN_0084e3a0(), 0);
                        GetProcess()->v221(0);
                    }
                }
            }
            activeVal = v121();
            if (activeVal)
            {
                if (activeVal)
                {
                    unsigned int a = target;
                    if (target || force)
                        process->v17(this, a, (!!target) + 2, 0, 1, 1);
                }
                if (other && other != this && (other->v63() || other->v64()))
                {
                    ActorObject* tmp = other;
                    unsigned char next = 1;
                    if (tmp->v64())
                    {
                        ActorObject* c = tmp;
                        Package* kIter = c->FUN_009344a0();
                        if (kIter && kIter->FUN_005f36f0())
                            next = 0;
                    }
                    if (otherTarget || next)
                        tmp->GetProcess()->v17(tmp, otherTarget, (otherTarget != 0) + 2, 0, 1, 1);
                }
            }
            if (curItem)
            {
                active = (float)((double)curItem->FUN_00559450() / DAT_0101db88);
                curItem->FUN_004d5930(isPlayer, g_011c56fc_arg1);
            }
            if (update && GetProcess())
                GetProcess()->v187(arg3);
            unsigned int flagsZ = 0x104;
            Node* node2 = (Node*)FUN_005e3fa0();
            if (node2 && node2->FUN_007af430())
            {
                void* space1 = node2->FUN_007af430();
            }
            if (!playFlag)
                flagsZ |= 2;
            else
                flagsZ |= 1;
            *apSoundRef = FUN_00453a70()->FUN_00ad7480(text, flagsZ, 0);
            mgr = FUN_00ad9060();
            ActorObject* kSource;
            kSource = this;
            if (other && other->v64())
                kSource = other;
            mgr->FUN_00adc050(apSoundRef->FUN_00559450(), SetFormAccumulate, kSource->FUN_0084e3a0());
            if (!playFlag)
            {
                Point pos = *v125();
                apSoundRef->FUN_00ad8be0(FUN_005790b0(), FUN_005790d0());
                apSoundRef->SetPos(pos.x, pos.y, pos.z);
                apSoundRef->SetNiNode(v116());
            }
            else
                apSoundRef->SetStaticAttenuation((int)(*g_011e060c.FUN_00403e20() * DAT_01017a40));
            if (curItem)
            {
                timeMs = (float)((curItem->GetNegativeMagnitude() + FUN_008a2d20()) * DAT_01017b70);
                apSoundRef->FUN_00ad8870((int)timeMs, 0);
                elapsed = (float)(curItem->GetNegativeMagnitude() + FUN_008a2d20());
                if (active > DAT_01012060)
                    elapsed += active;
                else if (apSoundRef->FUN_00ad8b30())
                    elapsed = (float)(apSoundRef->FUN_00ad8b30() / DAT_01017b70 + elapsed);
                else
                    elapsed = (float)((double)duration * *originalRuntimeFloatSetting184.FUN_00403e20() + elapsed);
                GetProcess()->v467(g_timeGlobal.FUN_00825c00() + (int)timeMs);
                GetProcess()->v465(curItem);
            }
            else
            {
                apSoundRef->FUN_00ad8870(1, 0);
                elapsed = (float)((double)duration * *originalRuntimeFloatSetting184.FUN_00403e20());
            }
            if (flag7d)
                flag7c = 0;
            GetProcess()->v292(0, *apSoundRef);
            if (curItem)
            {
                if (curItem != GetProcess()->v466())
                {
                    delete curItem;
                }
                GetProcess()->v224(0);
                GetProcess()->v220(0);
            }
            return elapsed;
        }
    }
}
}  // namespace fnv_009344d0

namespace fnv_0092ed60 {
extern int DAT_01184920;
extern int DAT_011a0e88;
extern "C" void* __cdecl FNV_DynamicCast(void*, long, void*, void*, int);

class FNVPoly
{
  public:
    virtual void unk_000();
    virtual void unk_001();
    virtual void unk_002();
    virtual void unk_003();
    virtual void unk_004();
    virtual void unk_005();
    virtual void unk_006();
    virtual void unk_007();
    virtual void unk_008();
    virtual void unk_009();
    virtual void unk_00a();
    virtual void unk_00b();
    virtual void unk_00c();
    virtual void unk_00d();
    virtual void unk_00e();
    virtual void unk_00f();
    virtual void unk_010();
    virtual void unk_011();
    virtual void unk_012();
    virtual void unk_013();
    virtual void unk_014();
    virtual void unk_015();
    virtual void unk_016();
    virtual void unk_017();
    virtual void unk_018();
    virtual void unk_019();
    virtual void unk_01a();
    virtual void unk_01b();
    virtual void unk_01c();
    virtual void unk_01d();
    virtual void unk_01e();
    virtual void unk_01f();
    virtual void unk_020();
    virtual void unk_021();
    virtual void unk_022();
    virtual void unk_023();
    virtual void unk_024();
    virtual void unk_025();
    virtual void unk_026();
    virtual void unk_027();
    virtual void unk_028();
    virtual void unk_029();
    virtual void unk_02a();
    virtual void unk_02b();
    virtual void unk_02c();
    virtual void unk_02d();
    virtual void unk_02e();
    virtual void unk_02f();
    virtual void unk_030();
    virtual void unk_031();
    virtual void unk_032();
    virtual void unk_033();
    virtual void unk_034();
    virtual void unk_035();
    virtual void unk_036();
    virtual void unk_037();
    virtual void unk_038();
    virtual void unk_039();
    virtual void unk_03a();
    virtual void unk_03b();
    virtual void unk_03c();
    virtual void unk_03d();
    virtual void unk_03e();
    virtual void unk_03f();
    virtual bool vIsActor();
    virtual void unk_041();
    virtual void unk_042();
    virtual void unk_043();
    virtual void unk_044();
    virtual void unk_045();
    virtual void unk_046();
    virtual void unk_047();
    virtual void unk_048();
    virtual void unk_049();
    virtual void unk_04a();
    virtual void unk_04b();
    virtual void unk_04c();
    virtual void unk_04d();
    virtual void unk_04e();
    virtual void unk_04f();
    virtual void unk_050();
    virtual void unk_051();
    virtual void unk_052();
    virtual void unk_053();
    virtual void unk_054();
    virtual void unk_055();
    virtual void unk_056();
    virtual void unk_057();
    virtual void unk_058();
    virtual void unk_059();
    virtual void unk_05a();
    virtual void unk_05b();
    virtual void unk_05c();
    virtual void unk_05d();
    virtual void unk_05e();
    virtual void unk_05f();
    virtual void unk_060();
    virtual void unk_061();
    virtual void unk_062();
    virtual void unk_063();
    virtual void unk_064();
    virtual void unk_065();
    virtual void* v198();
    virtual unsigned int v19c();
    virtual void unk_068();
    virtual void unk_069();
    virtual void unk_06a();
    virtual void unk_06b();
    virtual void unk_06c();
    virtual void unk_06d();
    virtual void unk_06e();
    virtual void unk_06f();
    virtual void unk_070();
    virtual void unk_071();
    virtual void unk_072();
    virtual void unk_073();
    virtual void unk_074();
    virtual void unk_075();
    virtual void unk_076();
    virtual void unk_077();
    virtual void unk_078();
    virtual void unk_079();
    virtual void unk_07a();
    virtual void unk_07b();
    virtual void unk_07c();
    virtual void unk_07d();
    virtual void unk_07e();
    virtual void unk_07f();
    virtual void unk_080();
    virtual void unk_081();
    virtual void unk_082();
    virtual void unk_083();
    virtual void unk_084();
    virtual void unk_085();
    virtual void unk_086();
    virtual void unk_087();
    virtual bool v220();
    virtual bool v224();
    virtual void unk_08a();
    virtual void unk_08b();
    virtual void unk_08c();
    virtual void unk_08d();
    virtual void unk_08e();
    virtual void unk_08f();
    virtual void unk_090();
    virtual void unk_091();
    virtual void unk_092();
    virtual void unk_093();
    virtual void unk_094();
    virtual void unk_095();
    virtual void unk_096();
    virtual void unk_097();
    virtual void unk_098();
    virtual void unk_099();
    virtual void unk_09a();
    virtual void unk_09b();
    virtual void unk_09c();
    virtual void unk_09d();
    virtual void unk_09e();
    virtual void unk_09f();
    virtual void unk_0a0();
    virtual void unk_0a1();
    virtual void unk_0a2();
    virtual void unk_0a3();
    virtual void unk_0a4();
    virtual void unk_0a5();
    virtual void unk_0a6();
    virtual void unk_0a7();
    virtual void unk_0a8();
    virtual void unk_0a9();
    virtual void unk_0aa();
    virtual void unk_0ab();
    virtual void unk_0ac();
    virtual void unk_0ad();
    virtual void unk_0ae();
    virtual void unk_0af();
    virtual void unk_0b0();
    virtual void unk_0b1();
    virtual void unk_0b2();
    virtual void unk_0b3();
    virtual void unk_0b4();
    virtual void unk_0b5();
    virtual void unk_0b6();
    virtual void unk_0b7();
    virtual void unk_0b8();
    virtual void unk_0b9();
    virtual void unk_0ba();
    virtual void unk_0bb();
    virtual void unk_0bc();
    virtual void unk_0bd();
    virtual void unk_0be();
    virtual void unk_0bf();
    virtual void unk_0c0();
    virtual void unk_0c1();
    virtual void unk_0c2();
    virtual void unk_0c3();
    virtual void unk_0c4();
    virtual void v314(void*);
    virtual void unk_0c6();
    virtual void unk_0c7();
    virtual void unk_0c8();
    virtual void unk_0c9();
    virtual void unk_0ca();
    virtual void unk_0cb();
    virtual void unk_0cc();
    virtual void unk_0cd();
    virtual void unk_0ce();
    virtual void unk_0cf();
    virtual void unk_0d0();
    virtual void unk_0d1();
    virtual void unk_0d2();
    virtual void unk_0d3();
    virtual void unk_0d4();
    virtual void unk_0d5();
    virtual void unk_0d6();
    virtual void unk_0d7();
    virtual void unk_0d8();
    virtual void unk_0d9();
    virtual void unk_0da();
    virtual void unk_0db();
    virtual void unk_0dc();
    virtual void unk_0dd();
    virtual void unk_0de();
    virtual void unk_0df();
    virtual void unk_0e0();
    virtual void unk_0e1();
    virtual void unk_0e2();
    virtual void unk_0e3();
    virtual void unk_0e4();
    virtual void unk_0e5();
    virtual void unk_0e6();
    virtual void unk_0e7();
    virtual void unk_0e8();
    virtual void unk_0e9();
    virtual void unk_0ea();
    virtual void unk_0eb();
    virtual void unk_0ec();
    virtual void unk_0ed();
    virtual void unk_0ee();
    virtual void unk_0ef();
    virtual void unk_0f0();
    virtual void unk_0f1();
    virtual void unk_0f2();
    virtual void unk_0f3();
    virtual unsigned int v3d0();
    virtual void v3d4(unsigned int);
    virtual void unk_0f6();
    virtual void unk_0f7();
    virtual void unk_0f8();
    virtual void unk_0f9();
    virtual void unk_0fa();
    virtual void unk_0fb();
    virtual void unk_0fc();
    virtual void unk_0fd();
    virtual void unk_0fe();
    virtual void unk_0ff();
    virtual void unk_100();
    virtual void unk_101();
    virtual void unk_102();
    virtual void unk_103();
    virtual void unk_104();
    virtual void unk_105();
    virtual void unk_106();
    virtual void unk_107();
    virtual void unk_108();
    virtual void unk_109();
    virtual void unk_10a();
    virtual void unk_10b();
    virtual void unk_10c();
    virtual void unk_10d();
    virtual void unk_10e();
    virtual void unk_10f();
    virtual void unk_110();
    virtual void unk_111();
    virtual void unk_112();
    virtual void unk_113();
    virtual void unk_114();
    virtual void unk_115();
    virtual void unk_116();
    virtual void unk_117();
    virtual void unk_118();
    virtual void unk_119();
    virtual void unk_11a();
    virtual void unk_11b();
    virtual void unk_11c();
    virtual void unk_11d();
    virtual void unk_11e();
    virtual void unk_11f();
    virtual void unk_120();
    virtual void unk_121();
    virtual void unk_122();
    virtual void unk_123();
    virtual void unk_124();
    virtual void unk_125();
    virtual void unk_126();
    virtual void unk_127();
    virtual void unk_128();
    virtual void unk_129();
    virtual void unk_12a();
    virtual void unk_12b();
    virtual void unk_12c();
    virtual void unk_12d();
    virtual void unk_12e();
    virtual void unk_12f();
    virtual void unk_130();
    virtual void unk_131();
    virtual void unk_132();
    virtual void unk_133();
    virtual void unk_134();
    virtual void unk_135();
    virtual void unk_136();
    virtual void unk_137();
    virtual void unk_138();
    virtual void unk_139();
    virtual void unk_13a();
    virtual void unk_13b();
    virtual void unk_13c();
    virtual void unk_13d();
    virtual void unk_13e();
    virtual void unk_13f();
    virtual void unk_140();
    virtual void unk_141();
    virtual void unk_142();
    virtual void unk_143();
    virtual void unk_144();
    virtual void unk_145();
    virtual void unk_146();
    virtual void unk_147();
    virtual void unk_148();
    virtual void unk_149();
    virtual void unk_14a();
    virtual void unk_14b();
    virtual void unk_14c();
    virtual void unk_14d();
    virtual void unk_14e();
    virtual void unk_14f();
    virtual void unk_150();
    virtual void unk_151();
    virtual void unk_152();
    virtual void unk_153();
    virtual void unk_154();
    virtual void unk_155();
    virtual void unk_156();
    virtual void unk_157();
    virtual void unk_158();
    virtual void unk_159();
    virtual void unk_15a();
    virtual void unk_15b();
    virtual void unk_15c();
    virtual void unk_15d();
    virtual void unk_15e();
    virtual void unk_15f();
    virtual void unk_160();
    virtual void unk_161();
    virtual void unk_162();
    virtual void unk_163();
    virtual void unk_164();
    virtual void unk_165();
    virtual void unk_166();
    virtual void unk_167();
    virtual void unk_168();
    virtual void unk_169();
    virtual void unk_16a();
    virtual void unk_16b();
    virtual void unk_16c();
    virtual void unk_16d();
    virtual void unk_16e();
    virtual void unk_16f();
    virtual void unk_170();
    virtual void unk_171();
    virtual void unk_172();
    virtual void unk_173();
    virtual void unk_174();
    virtual void unk_175();
    virtual void unk_176();
    virtual void unk_177();
    virtual void unk_178();
    virtual void unk_179();
    virtual void unk_17a();
    virtual void unk_17b();
    virtual void unk_17c();
    virtual void unk_17d();
    virtual void unk_17e();
    virtual void unk_17f();
    virtual void unk_180();
    virtual void unk_181();
    virtual void unk_182();
    virtual void unk_183();
    virtual void unk_184();
    virtual void unk_185();
    virtual void unk_186();
    virtual void unk_187();
    virtual void unk_188();
    virtual void unk_189();
    virtual void unk_18a();
    virtual void unk_18b();
    virtual void unk_18c();
    virtual void unk_18d();
    virtual void unk_18e();
    virtual void unk_18f();
    virtual void unk_190();
    virtual void unk_191();
    virtual void unk_192();
    virtual void unk_193();
    virtual void unk_194();
    virtual void unk_195();
    virtual void unk_196();
    virtual void unk_197();
    virtual void unk_198();
    virtual void v664(void*);
};
class BSShaderNoLightingProperty
{
  public:
    FNVPoly* FUN_008d8520();
};
class FNVTreeRoot;
class FUN_005be5c0_shell
{
  public:
    unsigned int FUN_005be5c0(unsigned int);
};
class TopicInfoArray : public FUN_005be5c0_shell
{
  public:
    TESObjectREFR* FUN_00968670(unsigned int);
    unsigned int FUN_005de0f0(unsigned int);
};
class FNVTreeRoot
{
  public:
    TopicInfoArray* FUN_00717e50();
};
extern int DAT_011e0e80;
extern Actor* _g_thePlayer;

class FNVReferenceActions
{
  public:
    void FUN_008c4f10(void*);
    void FUN_009c4c80(void*);
};
class FUN_009b28a0_t
{
  public:
    void FUN_009b28a0(void*);
};
class FUN_0092f140_shell
{
  public:
    void* GetFieldD2C();
    void FUN_00524d70();
};
class FNVCurrent : public TESObjectREFR
{
  public:
    void FUN_0092ed60(bool);
};
// Iterates topic arrays and the player, calling refresh actions and clearing matching flags on other references.
// @fnv 0x0092ed60
void FNVCurrent::FUN_0092ed60(bool refresh)
{
    TopicInfoArray* topicInfoArray = reinterpret_cast<FNVTreeRoot*>(&DAT_011e0e80)->FUN_00717e50();
    TESObjectREFR* index = 0;
    unsigned int array = 0;
    for (; array < topicInfoArray->FUN_005be5c0(0); ++array)
    {
        index = topicInfoArray->FUN_00968670(array);
        if (index != this)
        {
            if (index->IsActor())
            {
                TESObjectREFR* first = index;

                reinterpret_cast<BSShaderNoLightingProperty*>(first)->FUN_008d8520()->v664(this);
                if (refresh)
                {
                    reinterpret_cast<FNVReferenceActions*>(first)->FUN_008c4f10(
                        reinterpret_cast<FNVPoly*>(this)->v198());
                }

                if (reinterpret_cast<BSShaderNoLightingProperty*>(first)->FUN_008d8520()->v3d0() ==
                    reinterpret_cast<FNVPoly*>(this)->v19c())
                {

                    reinterpret_cast<BSShaderNoLightingProperty*>(first)->FUN_008d8520()->v3d4(0);
                }
            }
            else if (reinterpret_cast<FNVPoly*>(index)->v224())
            {
                TESObjectREFR* other = index;
                reinterpret_cast<FNVReferenceActions*>(other)->FUN_009c4c80(this);
            }
            else if (reinterpret_cast<FNVPoly*>(index)->v220())
            {
                TESObjectREFR* other = index;
                reinterpret_cast<FUN_009b28a0_t*>(other)->FUN_009b28a0(this);
            }
            else if (refresh)
            {
                void* mobile = FNV_DynamicCast(index, 0, &DAT_01184920, &DAT_011a0e88, 0);
                if (mobile)
                {

                    reinterpret_cast<FNVPoly*>(mobile)->v314(reinterpret_cast<FNVPoly*>(this)->v198());
                }
            }
        }
    }
    {
        unsigned int offset = topicInfoArray->FUN_005de0f0(1);
        for (; offset < topicInfoArray->FUN_005be5c0(1); ++offset)
        {
            index = topicInfoArray->FUN_00968670(offset);
            if (index != this)
            {
                Actor* target = dynamic_cast<Actor*>(reinterpret_cast<MobileObject*>(index));
                if (target)
                {
                    if (refresh)
                    {

                        reinterpret_cast<FNVReferenceActions*>(target)->FUN_008c4f10(
                            reinterpret_cast<FNVPoly*>(this)->v198());
                    }

                    if (reinterpret_cast<BSShaderNoLightingProperty*>(target)->FUN_008d8520()->v3d0() ==
                        reinterpret_cast<FNVPoly*>(this)->v19c())
                    {

                        reinterpret_cast<BSShaderNoLightingProperty*>(target)->FUN_008d8520()->v3d4(0);
                    }
                }
                else if (refresh)
                {
                    void* mobile2 = FNV_DynamicCast(index, 0, &DAT_01184920, &DAT_011a0e88, 0);
                    if (mobile2)
                    {

                        reinterpret_cast<FNVPoly*>(mobile2)->v314(reinterpret_cast<FNVPoly*>(this)->v198());
                    }
                }
            }
        }
    }
    if (_g_thePlayer)
    {
        if (reinterpret_cast<BSShaderNoLightingProperty*>(_g_thePlayer)->FUN_008d8520())
        {

            reinterpret_cast<BSShaderNoLightingProperty*>(_g_thePlayer)->FUN_008d8520()->v664(this);
        }
        if (refresh)
        {

            reinterpret_cast<FNVReferenceActions*>(_g_thePlayer)
                ->FUN_008c4f10(reinterpret_cast<FNVPoly*>(this)->v198());
        }
        if (reinterpret_cast<BSShaderNoLightingProperty*>(_g_thePlayer)->FUN_008d8520())
        {

            if (reinterpret_cast<BSShaderNoLightingProperty*>(_g_thePlayer)->FUN_008d8520()->v3d0() ==
                reinterpret_cast<FNVPoly*>(this)->v19c())
            {

                reinterpret_cast<BSShaderNoLightingProperty*>(_g_thePlayer)->FUN_008d8520()->v3d4(0);
            }
        }
        if (_g_thePlayer && reinterpret_cast<FUN_0092f140_shell*>(_g_thePlayer)->GetFieldD2C() == this)
        {
            reinterpret_cast<FUN_0092f140_shell*>(_g_thePlayer)->FUN_00524d70();
        }
    }
}
}  // namespace fnv_0092ed60

extern int DAT_0118a690;
extern int _DAT_01183028;
void* __cdecl FNV_DynamicCast(void*, int, void*, void*, int);
// @fnv 0x00933480
int FUN_00933480(void* apObject)
{
    return FNV_DynamicCast(apObject, 0, &_DAT_01183028, &DAT_0118a690, 0) != 0;
}
