// fallout/magic/magicshaderhiteffect.cpp: MagicShaderHitEffect, Effect, ThisHolder, Outer and more (45 functions)

#include "magicshaderhiteffect_decls.h"

// @fnv 0x0081FC70
bool MagicShaderHitEffect::Init()
{
    if (GetEffect())
    {
        m_fFirstFloatValue = GetEffect()->GetAge();
        bWasPlaying = !GetEffect()->GetEffectSetting()->FUN_00403e60(0x400);
        if (GetEffect()->HasFlag(0x10))
            m_fEffectShaderScale = 100.0f;
    }
    struct ScenegraphData
    {
        float extent;
        NiAVObject* particles;
        NiAVObject* shaders;
    } scenegraph;
    bool bWeapon = false;
    bool bTargetIsActor = false;
    scenegraph.extent = 0.0f;
    bool bResetParticles = false;
    if (pTarget == g_thePlayer && g_thePlayer->GetNode(false))
    {
        bool bThirdPerson = !g_thePlayer->GetNode(false)->FUN_00456610();
        bResetParticles = m_fFirstFloatValue > 0.0 && bThirdPerson != b3rdPerson;
        b3rdPerson = bThirdPerson;
    }
    scenegraph.shaders = 0;
    scenegraph.particles = 0;
    GetSceneGraphData(bTargetIsActor, bWeapon, scenegraph.extent, scenegraph.shaders, scenegraph.particles);
    if (scenegraph.shaders && scenegraph.particles && m_pEffectShader)
    {
        if (m_pEffectShader->GetFormID() == 0x852fe || m_pEffectShader->GetFormID() == 0x84a51)
        {
            SoundPlaybackHandle sound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("AMBFireMediumLP", 0x12);
            NiPoint3 position = pTarget->GetPos();
            sound.SetPosition(position.x, position.y, position.z);
            sound.SetVolume(1.0f);
            sound.Play(true);
            sound.SetObjectToFollow(pTarget->GetNiNode_v());
        }
        bool bParticles = true;
        if (m_bUseActorParticleEffects && pTarget->IsActor() && ((Actor*)pTarget)->GetProcess())
        {
            if (((Actor*)pTarget)->GetProcess()->vfn_1b0())
                bParticles = false;
            if (!((Actor*)pTarget)->GetProcess()->vfn_454() && g_thePlayer->GetField6A4() != this)
                bParticles = false;
        }
        if (bParticles && !m_pEffectShader->FUN_00507040(8))
        {
            if (m_pParticleShaderNode == (NiNode*)0)
            {
                m_pParticleShaderNode = new NiNode(0);
                m_pParticleShaderNode->SetName(NiFixedString("ParticleShader Geometry"));
                m_pParticleShaderNode->FUN_0043fa80(&DAT_011a9448);
            }
            if (!m_kParticleShaderProperties.GetSize())
            {
                NiPointer<NiSourceTexture> texture(0);
                if (m_pEffectShader->GetFieldAt158()->GetModelLength() > 0)
                {
                    char path[260];
                    sprintf_s(path, 260, "%s\\%s", "Textures",
                              m_pEffectShader->GetFieldAt158()->GetTextureResourceName());
                    g_TES->CreateTextureImage(path, texture, false, false);
                    struct ParticleCounts
                    {
                        int total;
                        int perShader;
                    } counts;
                    counts.total = (int)FUN_00404010(m_pEffectShader->FUN_00644930(), m_pEffectShader->FUN_008d01e0());
                    counts.perShader = ParticleShader::GetShaderParticleCount();
                    for (int i = 0; i * counts.perShader < counts.total; ++i)
                    {
                        NiPointer<ParticleShaderProperty> particleProperty =
                            m_pEffectShader->CreateParticleShaderProperty(m_pParticleShaderNode, scenegraph.particles,
                                                                          texture, m_fEffectShaderScale);
                        m_kParticleShaderProperties.FUN_006c61b0(particleProperty);
                    }
                }
            }
            for (unsigned int i = 0; i < m_kParticleShaderProperties.GetSize(); ++i)
            {
                ParticleShaderProperty* property = m_kParticleShaderProperties.GetAt(i);
                if (bWeapon)
                    property->FUN_00820b70(scenegraph.extent);
                if (m_bUseActorParticleEffects)
                    property->SetByteAtOffset6C(0);
                if (pTarget)
                {
                    TESObjectACTI* activator = dynamic_cast<TESObjectACTI*>(pTarget->GetObjectReference());
                    if (bTargetIsActor || activator)
                    {
                        if (pTarget == g_thePlayer && !b3rdPerson)
                            property->ClearField64();
                        else
                            property->FUN_00820b90();
                    }
                }
                property->DispatchRefOp(scenegraph.particles);
                if (bResetParticles)
                {
                    property->SetParticleTime(0.0f);
                    property->UpdateParticlesAtTime((float)(m_fEffectShaderScale - 0.16599999368190765), false, true);
                    property->UpdateParticlesAtTime(m_fEffectShaderScale, false, true);
                }
            }
            vfn_cc();
        }
        else if (m_kParticleShaderProperties.GetSize() && (NiNode*)m_pParticleShaderNode)
        {
            for (unsigned int i = 0; i < m_kParticleShaderProperties.GetSize(); ++i)
                m_pEffectShader->FUN_00507810(m_pParticleShaderNode, m_kParticleShaderProperties.GetAt(i));
            m_kParticleShaderProperties.RemoveAll(true);
            if ((NiNode*)m_pParticleShaderNode)
                m_pParticleShaderNode->AssignParent(0);
            m_pParticleShaderNode = (NiNode*)0;
        }
        if (!m_pEffectShader->FUN_00507040(1))
        {
            if (spTexEffectData == (BSShaderPPLightingProperty::TextureEffectData*)0)
            {
                NiPointer<NiSourceTexture> fillTexture(0);
                if (m_pEffectShader->GetFieldAt14C()->GetModelLength() > 0)
                {
                    char path[260];
                    sprintf_s(path, 260, "%s\\%s", "Textures",
                              m_pEffectShader->GetFieldAt14C()->GetTextureResourceName());
                    g_TES->CreateTextureImage(path, fillTexture, false, false);
                }
                NiPointer<NiSourceTexture> holesTexture(0);
                if (m_pEffectShader->GetFieldAt164()->GetModelLength() > 0)
                {
                    char path[260];
                    sprintf_s(path, 260, "%s\\%s", "Textures",
                              m_pEffectShader->GetFieldAt164()->GetTextureResourceName());
                    g_TES->CreateTextureImage(path, holesTexture, false, false);
                }
                spTexEffectData = m_pEffectShader->CreateEffectData(scenegraph.shaders, fillTexture, holesTexture);
                if ((BSShaderPPLightingProperty::TextureEffectData*)spTexEffectData &&
                    (NiSourceTexture*)spTexEffectData->spTexture && pTarget && pTarget->IsActor() &&
                    ((Actor*)pTarget)->FUN_008c4850() > 0.9900000095367432)
                {
                    ((Actor*)pTarget)->GetLightIntensity(0.99f);
                    ((Actor*)pTarget)->UpdateActorPresentation();
                }
            }
            m_pEffectShader->ApplyShaderToTree(scenegraph.shaders, spTexEffectData);
        }
        if (!bResetParticles && !m_kAddonModelObjects.GetSize() && m_pEffectShader &&
            m_pEffectShader->GetAddonModels() && m_kParticleShaderProperties.GetSize() > 0 &&
            (ParticleShaderProperty*)m_kParticleShaderProperties.GetAt(0) &&
            m_kParticleShaderProperties.GetAt(0)->GetFieldAt11C().GetSize() > 0)
        {
            ParticleShaderProperty* property;
            BSSimpleList<DebrisModelEntry*>* entry;
            {
                WeightedResultList<const char*> weightedModels;
                entry = m_pEffectShader->GetAddonModels()->GetData();
                while (entry && !entry->IsEmpty())
                {
                    g_modelLoader->LoadFile(entry->GetItem()->filename, 0, true, false, false, false);
                    weightedModels.AddWeightedItem(entry->GetItem()->filename, entry->GetItem()->chance);
                    entry = entry->GetNext();
                }
                property = m_kParticleShaderProperties.GetAt(0);
                for (unsigned int i = 0; i < property->GetFieldAt11C().GetSize(); ++i)
                {
                    NiAVObject* object = property->GetFieldAt11C().GetAt(i);
                    if (object->IsSceneNode())
                    {
                        NiPointer<Model> model(0);
                        g_modelLoader->LoadModel(weightedModels.FindFirstItemExceedingRemaining(), model);
                        if ((Model*)model && model->GetControllers())
                        {
                            CloningProcess cloneProcess(1.0f);
                            NiAVObject* clone = model->GetControllers()->CloneObject(cloneProcess);
                            if (IsConditionMet())
                                TaskQueueInterface::GetSingleton()->QueueTaskWithTwoObjects(
                                    clone, object->IsSceneNode(), true, false);
                            else
                                object->IsSceneNode()->AddObject(clone, true);
                            m_fAddonModelTimer = 0.0f;
                            m_fAddonModelScale = FUN_00404010(0.01f, m_pEffectShader->FUN_00567470());
                            clone->FUN_00440490(m_fAddonModelScale);
                            NiTimeController::UpdateControllersForTarget(clone);
                            m_kAddonModelObjects.FUN_006c61b0(clone);
                        }
                    }
                }
            }
        }
        if (m_kParticleShaderProperties.GetSize() <= 0 &&
            !(BSShaderPPLightingProperty::TextureEffectData*)spTexEffectData)
            return false;
        else
            return true;
    }
    return false;
}

// @fnv 0x00820C10
void MagicShaderHitEffect::GetSceneGraphData(bool& isActor, bool& isWeapon, float& extent, NiAVObject*& shaderObject,
                                             NiAVObject*& particleObject)
{
    bool bParticles = false;
    bool bArmor = false;
    NiAVObject* pObject = 0;
    bool bWeapon = false;
    Actor* pTargetActor = dynamic_cast<Actor*>(pTarget);
    BipedAnim* pBiped = 0;
    if (pTargetActor)
    {
        if (pTargetActor != g_thePlayer)
            pBiped = pTargetActor->GetBipedAnim();
        else if (g_thePlayer->FUN_00490f80() && g_thePlayer->GetField6A4() == this)
            bWeapon = true;
        else
            pBiped = g_thePlayer->GetBipedAnimation(!b3rdPerson);
    }
    if (m_bUseActorParticleEffects || bParticles)
    {
        if (pTarget && pTarget->IsActor())
        {
            Actor* targetActor = (Actor*)pTarget;
            BaseProcess* process = targetActor->GetProcess();
            if (process)
                process->vfn_148();
        }
    }
    else if (bArmor)
    {
        DisintegrateArmorEffect* effect = dynamic_cast<DisintegrateArmorEffect*>(GetEffect());
        if (effect)
        {
            InventoryItem* item = effect->GetItem();
            if (item)
                m_pAffectedArmorObject = item->GetObject();
        }
        if (pTarget && pTarget->IsActor() && m_pAffectedArmorObject && pBiped)
        {
            BipedObject* worn = pBiped->FindEntry(m_pAffectedArmorObject);
            if (worn)
                pObject = worn->object;
        }
    }
    else if (pTarget)
    {
        pObject = pTarget->GetNiNode_v();
        if (pTarget->IsActor())
        {
            if (pTarget == g_thePlayer)
                pObject = g_thePlayer->GetNode(!b3rdPerson);
            isActor = true;
        }
        else
        {
            TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(pTarget->GetObjectReference());
            if (weapon && pObject)
            {
                isWeapon = true;
                if (pObject->GetBoundingVolume().FUN_0084d030() <= 0.0)
                {
                    NiUpdateData update(0.0f, false, false);
                    pObject->Update(update);
                }
                NiPoint3 offset = pObject->GetBoundingVolume().GetNavMeshData() - pObject->FUN_0045bb80();
                extent = offset.ComputeMagnitude() + pObject->GetBoundingVolume().FUN_0084d030();
            }
        }
    }
    shaderObject = pObject;
    particleObject = pObject;
}

struct DummyClass_006a8500
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2(void*);
    void* pBuffer;
};

// Calls the object's vfunc2 with pBuffer, then clears pBuffer to null.
// @fnv 0x006a8500
void __fastcall FUN_006a8500(DummyClass_006a8500* pThis)
{
    pThis->vfunc2(pThis->pBuffer);
    pThis->pBuffer = 0;
}

struct NavMeshPtr
{
    void* p;
    NavMeshPtr& operator=(const NavMeshPtr&);
};
struct S2f850
{
    int pad0;
    NavMeshPtr* data;
    unsigned int FUN_00761540();
    void FUN_0042fa60(NavMeshPtr*, int);
    unsigned int FUN_006c61b0(const NavMeshPtr& aValue);
};
// @fnv 0x006c61b0
unsigned int S2f850::FUN_006c61b0(const NavMeshPtr& aValue)
{
    unsigned int uiIndex = FUN_00761540();
    FUN_0042fa60(&data[uiIndex], 1);
    data[uiIndex] = aValue;
    return uiIndex;
}

struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
};
struct Elem4;
struct FUN_006c6200_cls : public NavMeshSearchLOSArray
{
    int vt;
    Elem4* data;
    unsigned int count;
    int extra;
    void FUN_00822820(Elem4* p, unsigned int n);
    void FUN_006c6200(bool flag);
};
// @fnv 0x006c6200
void FUN_006c6200_cls::FUN_006c6200(bool abFreeStorage)
{
    if (data)
    {
        FUN_00822820(data, count);
        if (abFreeStorage)
        {
            FUN_006a8500();
            data = 0;
            extra = 0;
        }
        count = 0;
    }
}

void __fastcall FUN_0081f770(void* pThis);

struct FUN_0081f320_helper
{
    void* FUN_0081f320(unsigned int flags);
};

// Calls FUN_0081f770 on this, then deletes this with NiMemObject::operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0081f320
void* FUN_0081f320_helper::FUN_0081f320(unsigned int flags)
{
    FUN_0081f770(this);
    if (flags & 1)
    {
        reinterpret_cast<void(__cdecl*)(void*, unsigned int)>(&NiMemObject::operator delete)(this, 0x6c);
    }
    return this;
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x00822580
void* __fastcall FUN_00822580(int** ppObject)
{
    *ppObject = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(ppObject)->FUN_0042fcb0(0, 0);
    return ppObject;
}

struct Elem4
{
    int v;
    void FUN_008228f0(int a);
};
struct FUN_00822820_cls
{
    void FUN_00822820(Elem4* p, unsigned int n);
};
// Calls FUN_008228f0(0) on each of the n Elem4 elements starting at p.
// @fnv 0x00822820
void FUN_00822820_cls::FUN_00822820(Elem4* apElems, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
        apElems[i].FUN_008228f0(0);
}

namespace fnv_00822860 {
struct NavMeshInfo;
struct S2f850
{
    void FUN_0042fa60(NavMeshInfo**, unsigned int);
};
struct UW
{
    unsigned int v;
};
struct AX
{
    virtual void* v0(unsigned int);
    virtual NavMeshInfo** Allocate(unsigned int);
    NavMeshInfo** data;
    unsigned int size;
    unsigned int alloc;
};
// @fnv 0x00822860
void __fastcall FUN_00822860(AX* self, UW uiMaxSize, UW uiSize)
{
    self->data = 0;
    self->size = 0;
    self->alloc = 0;
    if (uiSize.v > uiMaxSize.v)
        uiMaxSize.v = uiSize.v;
    if (uiMaxSize.v > 0)
    {
        self->data = self->Allocate(uiMaxSize.v);
        self->alloc = uiMaxSize.v;
    }
    if (uiSize.v > 0)
    {
        ((S2f850*)self)->FUN_0042fa60(self->data, uiSize.v);
        self->size = uiSize.v;
    }
}
}  // namespace fnv_00822860

extern int g_011dc804;

// @fnv 0x0081f310
int* __fastcall GetGlobalIntPtr(int* thisPtr)
{
    return &g_011dc804;
}

struct FUN_00820b70_shell
{
    char m_auiShapeKeys[0x64];
    int m_0x64;
    float m_0x68;

    void FUN_00820b70(float a);
};

// Sets m_0x64 to 2 and stores the float argument in m_0x68.
// @fnv 0x00820b70
void FUN_00820b70_shell::FUN_00820b70(float afValue)
{
    m_0x64 = 2;
    m_0x68 = afValue;
}

// @fnv 0x00820b90
void __fastcall FUN_00820b90(int pObject)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(pObject) + 0x64) = 1;
}

// @fnv 0x00820bb0
void __fastcall ClearField64(void* apObject)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(apObject) + 0x64) = 0;
}

struct Arr3520
{
    void RemoveAll(bool);
};

extern int DAT_0107b824;

// @fnv 0x00822560
void __fastcall FUN_00822560(Arr3520* pArray)
{
    *(int*)pArray = (int)&DAT_0107b824;
    pArray->RemoveAll(true);
}

struct FUN_00820b50_shell
{
    void* GetFieldAt11C();
};

// @fnv 0x00820b50
void* FUN_00820b50_shell::GetFieldAt11C()
{
    return reinterpret_cast<char*>(this) + 0x11C;
}

struct FUN_00820bf0_shell
{
    int __thiscall GetField6A4();
};

// @fnv 0x00820bf0
int __thiscall FUN_00820bf0_shell::GetField6A4()
{
    return *(int*)((char*)this + 0x6a4);
}

struct FUN_0081bd30_s
{
    unsigned short GetSaveSize(ActiveEffect*, TESObjectREFR*);
};

struct TESSaveLoadGame
{
    void ReadTypedData(void* data, unsigned int size);
    unsigned char FUN_008df040();
    void FUN_00857aa0(unsigned int* data, int size);
};
class ShaderLoadView : public MagicShaderHitEffect
{
  public:
    void SaveLoad(ActiveEffect* effect, TESObjectREFR* target);
    void FUN_00821ed0(ActiveEffect* effect, TESObjectREFR* target);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00821dd0_shell
{
    unsigned short GetEffectSaveSize(ActiveEffect*, TESObjectREFR*);
};

// Computes the save size for an active effect: base size from GetSaveSize plus 4, and if the save version is at least 0x37, adds 1 and 4 more.
// @fnv 0x00821dd0
unsigned short FUN_00821dd0_shell::GetEffectSaveSize(ActiveEffect* aEffect, TESObjectREFR* aRefr)
{
    unsigned short isize = 0;
    isize += ((FUN_0081bd30_s*)this)->GetSaveSize(aEffect, aRefr);
    isize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x37)
    {
        isize += 1;
        isize += 4;
    }
    return isize;
}

namespace fnv_008225b0 {
struct Arr3520
{
    void* m_data;
    void RemoveAll(bool);
};
extern int DAT_010159d4;

struct FUN_008225b0_shell : Arr3520
{
    void FUN_008225b0();
};

// @fnv 0x008225b0
void FUN_008225b0_shell::FUN_008225b0()
{
    m_data = &DAT_010159d4;
    RemoveAll(true);
}
}  // namespace fnv_008225b0

struct FUN_008225d0_shell
{
    void* __thiscall FUN_008225d0(unsigned int param_1);
};

// Allocates a block of param_1 * 4 bytes via operator new and returns the pointer.
// @fnv 0x008225d0
void* __thiscall FUN_008225d0_shell::FUN_008225d0(unsigned int param_1)
{
    void* result = operator new(param_1 * 4);
    return result;
}

struct AX
{
    unsigned int vtable;
    void __thiscall FUN_006b3eb0(unsigned int, unsigned int);
};

void __thiscall AX::FUN_006b3eb0(unsigned int, unsigned int)
{}

extern unsigned int DAT_0107b84c;

struct FUN_00822600_shell : AX
{
    AX* __thiscall InitVtable();
};

// Sets the object's vtable to DAT_0107b84c, calls FUN_006b3eb0 with 0, 0, and returns this as an AX pointer.
// @fnv 0x00822600
AX* __thiscall FUN_00822600_shell::InitVtable()
{
    vtable = (unsigned int)&DAT_0107b84c;
    FUN_006b3eb0(0, 0);
    return (AX*)this;
}

namespace fnv_00822630 {
struct GlobalObject_00869f00
{
    int* m_data;
    void Clear(bool);
    void FUN_00822630();
};

extern int DAT_0107b84c;

// @fnv 0x00822630
void GlobalObject_00869f00::FUN_00822630()
{
    m_data = &DAT_0107b84c;
    Clear(true);
}
}  // namespace fnv_00822630

TESEffectShader* __cdecl FUN_0080d0d0(void);
struct FUN_00822010_S
{
    char _p0[24];
    int _m18;
    int _m1c;
    char _p1[8];
    bool _b28;
    char _p2[7];
    TESEffectShader* _p30;
    bool FUN_00822010();
};
// @fnv 0x00822010
bool FUN_00822010_S::FUN_00822010()
{
    if (_m18 != 0)
        return false;
    if (_m1c == 0 || _p30 == 0 || _b28 || _p30 == FUN_0080d0d0())
        return false;
    return true;
}

extern int DAT_0107b824;
struct Caller00822860
{
    void FUN_00822860(unsigned int, bool);
};
struct FUN_00822530_shell
{
    void* vtable;
    FUN_00822530_shell* FUN_00822530();
};
// Sets the object's vtable to DAT_0107b824, calls FUN_00822860 with 0 and false, and returns this.
// @fnv 0x00822530
FUN_00822530_shell* FUN_00822530_shell::FUN_00822530()
{
    vtable = &DAT_0107b824;
    reinterpret_cast<Caller00822860*>(this)->FUN_00822860(0, false);
    return this;
}

void __fastcall FUN_00822560(void*);
void __cdecl _Deallocate(void*);
struct S008226F0
{
    void* FUN_008226f0(unsigned int);
};
// @fnv 0x008226f0
void* S008226F0::FUN_008226f0(unsigned int flags)
{
    FUN_00822560(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct ThisHolder
{
    void FUN_008225b0();
    void* FUN_00822720(unsigned int);
};
// Calls FUN_008225b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00822720
void* ThisHolder::FUN_00822720(unsigned int flags)
{
    FUN_008225b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Struct00822750
{
    void FUN_00822630();
    void* FUN_00822750(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00822630, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00822750
void* Struct00822750::FUN_00822750(unsigned int flags)
{
    FUN_00822630();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0087d230 {
struct Arr3520
{
    virtual ~Arr3520();
    void RemoveAll(bool);
};
struct FUN_008225b0 : Arr3520
{
    virtual ~FUN_008225b0();
};
struct FUN_0087d230 : FUN_008225b0
{
    virtual ~FUN_0087d230();
};
// @fnv 0x0087d230
FUN_0087d230::~FUN_0087d230()
{
    Arr3520::RemoveAll(true);
}
}  // namespace fnv_0087d230

struct FUN_00820bd0_shell
{
    void SetByteAtOffset6C(unsigned char a);
};

// @fnv 0x00820bd0
void FUN_00820bd0_shell::SetByteAtOffset6C(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x6c) = aucValue;
}

struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
};
struct FUN_0081be80_s
{
    void FUN_0081be80(BGSSaveFormBuffer*);
};
struct FUN_00822250_shell
{
    void FUN_00822250(BGSSaveFormBuffer*);
};
// @fnv 0x00822250
void FUN_00822250_shell::FUN_00822250(BGSSaveFormBuffer* pBuffer)
{
    reinterpret_cast<FUN_0081be80_s*>(this)->FUN_0081be80(pBuffer);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x28, 1, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x34, 4, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x60, 4, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x64, 4, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x4c, 1, 0);
    pBuffer->SerializeFormData(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0x2c / 4]), 0);
    pBuffer->SerializeFormData(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0x30 / 4]), 0);
}

struct Shell00822060
{
    int _p[6];
    int _f;
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
    virtual unsigned short v52(int, int);
    unsigned short FUN_00822060();
};
// Computes a size: starts at 0, adds 4 twice, then adds the result of v52(0, _f), and returns it.
// @fnv 0x00822060
unsigned short Shell00822060::FUN_00822060()
{
    unsigned short isize;
    isize = 0;
    isize += 4;
    isize += 4;
    isize += v52(0, _f);
    return isize;
}

struct Inner
{
    virtual float d0();
    virtual float d1();
    virtual float d2();
    virtual float d3();
    virtual float d4();
    virtual float d5();
    virtual float d6();
    virtual float d7();
    virtual float d8();
    virtual float d9();
    virtual float d10();
    virtual float d11();
    virtual float d12();
    virtual float d13();
    virtual float d14();
    virtual float d15();
    virtual float d16();
    virtual float d17();
    virtual float d18();
    virtual float d19();
    virtual float d20();
    virtual float d21();
    virtual float d22();
    virtual float d23();
    virtual float d24();
    virtual float d25();
    virtual float d26();
    virtual float d27();
    virtual float d28();
    virtual float d29();
    virtual float d30();
    virtual float d31();
    virtual float d32();
    virtual float d33();
    virtual float d34();
    virtual float d35();
    virtual float d36();
    virtual float d37();
    virtual float d38();
    virtual float d39();
    virtual float d40();
    virtual float d41();
    virtual float d42();
    virtual float d43();
    virtual float d44();
    virtual float d45();
    virtual float d46();
    virtual float d47();
    virtual float d48();
    virtual float d49();
    virtual float d50();
    virtual float d51();
    virtual float d52();
    virtual float d53();
    virtual float d54();
    virtual float d55();
    virtual float d56();
    virtual float d57();
    virtual float d58();
    virtual float d59();
    virtual float d60();
    virtual float d61();
    virtual float d62();
    virtual float d63();
    virtual float d64();
    virtual float d65();
    virtual float d66();
    virtual float d67();
    virtual float d68();
    virtual float d69();
    virtual float d70();
    virtual float d71();
    virtual float d72();
    virtual float d73();
    virtual float d74();
    virtual float d75();
    virtual float d76();
    virtual float d77();
    virtual float d78();
    virtual float d79();
    virtual float d80();
    virtual float d81();
    virtual float d82();
    virtual float d83();
    virtual float d84();
    virtual float d85();
    virtual float d86();
    virtual float d87();
    virtual float d88();
    virtual float d89();
    virtual float d90();
    virtual float d91();
    virtual float d92();
    virtual float d93();
    virtual float d94();
    virtual float d95();
    virtual float d96();
    virtual float d97();
    virtual float d98();
    virtual float d99();
    virtual float d100();
    virtual float d101();
    virtual float d102();
    virtual float d103();
    virtual float d104();
    virtual float d105();
    virtual float d106();
    virtual float d107();
    virtual float d108();
    virtual float d109();
    virtual float d110();
    virtual float d111();
    virtual float d112();
    virtual float d113();
    virtual float d114();
    virtual float d115();
    virtual float d116();
    virtual float d117();
    virtual float d118();
    virtual float d119();
    virtual float d120();
    virtual float d121();
    virtual float d122();
    virtual float d123();
    virtual float d124();
    virtual float d125();
    virtual float d126();
    virtual float d127();
    virtual float d128();
    virtual float d129();
    virtual float d130();
    virtual float d131();
    virtual float d132();
    virtual float d133();
    virtual float d134();
    virtual float d135();
    virtual float d136();
    virtual float d137();
    virtual float d138();
    virtual float d139();
    virtual float d140();
    virtual float d141();
    virtual float d142();
    virtual float d143();
    virtual float d144();
    virtual float d145();
    virtual float d146();
    virtual float d147();
    virtual float d148();
    virtual float d149();
    virtual float d150();
    virtual float d151();
    virtual float d152();
    virtual float d153();
    virtual float d154();
    virtual float d155();
    virtual float d156();
    virtual float d157();
    virtual float d158();
    virtual float d159();
    virtual float d160();
    virtual float d161();
    virtual float d162();
    virtual float d163();
    virtual float d164();
    virtual float d165();
    virtual float d166();
    virtual float d167();
    virtual float d168();
    virtual float d169();
    virtual float d170();
    virtual float d171();
    virtual float d172();
    virtual float d173();
    virtual float d174();
    virtual float d175();
    virtual float d176();
    virtual float d177();
    virtual float d178();
    virtual float d179();
    virtual float d180();
    virtual float d181();
    virtual float d182();
    virtual float d183();
    virtual float d184();
    virtual float d185();
    virtual float d186();
    virtual float d187();
    virtual float d188();
    virtual float d189();
    virtual float d190();
    virtual float d191();
    virtual float d192();
    virtual float d193();
    virtual float d194();
    virtual float d195();
    virtual float d196();
    virtual float d197();
    virtual float d198();
    virtual float d199();
    virtual float d200();
    virtual float d201();
    virtual float d202();
    virtual float d203();
    virtual float d204();
    virtual float d205();
    virtual float d206();
    virtual float d207();
    virtual float d208();
    virtual float d209();
    virtual float d210();
    virtual float d211();
    virtual float d212();
    virtual float d213();
    virtual float d214();
    virtual float d215();
    virtual float d216();
    virtual float d217();
    virtual float d218();
    virtual float d219();
    virtual float d220();
    virtual float d221();
    virtual float d222();
    virtual float d223();
    virtual float d224();
    virtual float d225();
    virtual float d226();
    virtual float d227();
    virtual float d228();
    virtual float d229();
    virtual float d230();
    virtual float d231();
    virtual float d232();
    virtual float d233();
    virtual float d234();
    virtual float d235();
    virtual float d236();
    virtual float d237();
    virtual float d238();
    virtual float d239();
    virtual float d240();
    virtual float d241();
    virtual float d242();
    virtual float d243();
    virtual float d244();
    virtual float d245();
    virtual float d246();
    virtual float d247();
    virtual float d248();
    virtual float d249();
    virtual float d250();
    virtual float d251();
    virtual float d252();
    virtual float d253();
    virtual float d254();
    virtual float d255();
    virtual float d256();
    virtual float d257();
    virtual float d258();
    virtual float d259();
    virtual float d260();
    virtual float d261();
    virtual float d262();
    virtual float d263();
    virtual float d264();
    virtual float d265();
    virtual float d266();
    virtual float d267();
    virtual float d268();
    virtual float d269();
    virtual float d270();
    virtual float d271();
    virtual float d272();
    virtual float d273();
    virtual float d274();
    virtual float d275();
    virtual float d276();
    virtual float d277();
    virtual float d278();
    virtual float d279();
    virtual float d280();
    virtual float d281();
    virtual float d282();
    virtual float d283();
    virtual float d284();
    virtual float d285();
    virtual float d286();
    virtual float d287();
    virtual float d288();
    virtual float d289();
    virtual float d290();
    virtual float d291();
    virtual float d292();
    virtual float d293();
    virtual float d294();
    virtual float d295();
    virtual float d296();
    virtual float d297();
    virtual float d298();
    virtual float d299();
    virtual float d300();
    virtual float d301();
    virtual float d302();
    virtual float d303();
    virtual float d304();
    virtual float d305();
    virtual float d306();
    virtual float d307();
    virtual float d308();
    virtual float d309();
    virtual float d310();
    virtual float d311();
    virtual float d312();
    virtual float d313();
    virtual float d314();
    virtual float d315();
    virtual float d316();
    virtual float d317();
    virtual float d318();
    virtual float d319();
    virtual float d320();
    virtual float d321();
    virtual float d322();
    virtual float d323();
    virtual float d324();
    virtual float d325();
    virtual float d326();
    virtual float d327();
    virtual float d328();
    virtual float d329();
    virtual float d330();
    virtual float d331();
    virtual float d332();
    virtual float d333();
    virtual float d334();
    virtual float d335();
    virtual float d336();
    virtual float d337();
    virtual float d338();
    virtual float d339();
    virtual float d340();
    virtual float d341();
    virtual float d342();
    virtual float d343();
    virtual float d344();
    virtual float d345();
    virtual float d346();
    virtual float d347();
    virtual float d348();
    virtual float d349();
    virtual float d350();
    virtual float d351();
    virtual float d352();
    virtual float d353();
    virtual float d354();
    virtual float d355();
    virtual float d356();
    virtual float d357();
    virtual float d358();
    virtual float d359();
    virtual float d360();
    virtual float d361();
    virtual float d362();
    virtual float Target();
};
struct Outer
{
    char _pad[0x68];
    Inner* p;
    float FUN_008c4850();
};
// Returns p->Target() when p is set, otherwise returns 1.0f.
// @fnv 0x008c4850
float Outer::FUN_008c4850()
{
    return p ? p->Target() : 1.0f;
}

namespace fnv_00821e40 {
struct TESSaveLoadGame
{
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int*, int);
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00821e40_shell
{
    char base[0x2c];
    TESForm* m_pAffectedArmorObject;
    void FUN_0081bd80(ActiveEffect*, TESObjectREFR*);
    void FUN_00821e40(ActiveEffect* a1, TESObjectREFR* a2);
};

// @fnv 0x00821e40
void FUN_00821e40_shell::FUN_00821e40(ActiveEffect* pEffect, TESObjectREFR* a2)
{
    FUN_0081bd80(pEffect, a2);
    g_TESSaveLoadGame->FUN_008579b0((char*)this + 0x34, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x37)
    {
        g_TESSaveLoadGame->FUN_008579b0((char*)this + 0x28, 1);
        int v = 0;
        if (m_pAffectedArmorObject)
            v = m_pAffectedArmorObject->GetFormID();
        g_TESSaveLoadGame->FUN_00857a10(&v, 4);
    }
}
}  // namespace fnv_00821e40

struct BGSLoadGameBuffer
{
    unsigned int ReadFormIdentifier();
    virtual unsigned char GetVersion();
};
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct FUN_0081bed0_s
{
    void LoadFormData(BGSLoadFormBuffer*);
};
struct FUN_008222f0_s : public FUN_0081bed0_s
{
    void FUN_008222f0(BGSLoadGameBuffer*);
};
struct TESBoundObject;
struct TESEffectShader;
TESForm* GetFormByID(unsigned int);
// Loads the base form data, then reads several fields from the buffer and resolves two form IDs into a TESBoundObject and a TESEffectShader.
// @fnv 0x008222f0
void FUN_008222f0_s::FUN_008222f0(BGSLoadGameBuffer* buffer)
{
    LoadFormData((BGSLoadFormBuffer*)buffer);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData(this + 0x28, 1);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData(this + 0x34, 4);
    if (buffer->GetVersion() >= 8)
    {
        ((BGSLoadFormBuffer*)buffer)->ReadTypedData(this + 0x60, 4);
        ((BGSLoadFormBuffer*)buffer)->ReadTypedData(this + 0x64, 4);
    }
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData(this + 0x4c, 1);
    *(TESBoundObject**)((char*)this + 0x2c) =
        dynamic_cast<TESBoundObject*>(GetFormByID(buffer->ReadFormIdentifier()));
    *(TESEffectShader**)((char*)this + 0x30) =
        dynamic_cast<TESEffectShader*>(GetFormByID(buffer->ReadFormIdentifier()));
}

extern unsigned int __cdecl FUN_005a00a0(void*);

struct FUN_00822650_shell : InventoryItem
{
    unsigned int FindFirstItemExceedingRemaining();
};

// @fnv 0x00822650
unsigned int FUN_00822650_shell::FindFirstItemExceedingRemaining()
{
    unsigned int result = 0;
    bool found = false;
    unsigned int remaining = FUN_005a00a0(*(void**)((char*)this + 0x20));
    for (unsigned int i = 0; i < (unsigned int)GetObject() && !found; ++i)
    {
        if (remaining < ((BSSimpleArray<unsigned int>*)((char*)this + 0x10))->GetAt(i))
        {
            result = ((BSSimpleArray<unsigned int>*)this)->GetAt(i);
            found = true;
        }
        remaining -= ((BSSimpleArray<unsigned int>*)((char*)this + 0x10))->GetAt(i);
    }
    return result;
}

namespace fnv_00695230 {
typedef void* NavMeshPtr;

struct Elem4
{
    unsigned int value;
};

struct Arr3520
{
    void RemoveAll(bool);
};

struct S2f850
{
    void FUN_0042fa60(NavMeshPtr*, int);
};

struct FUN_0042fc00_shell
{
    void FUN_0042fc00(void*, unsigned int);
};

struct FUN_006c6200_cls
{
    void FUN_00822820(Elem4*, unsigned int);
};

struct FUN_00695230_shell
{
    virtual void unused()
    {}
    virtual void* allocate(unsigned int)
    {
        return 0;
    }

    void* data;
    unsigned int count;
    unsigned int capacity;

    void FUN_00695230(unsigned int, bool);
};

// Resizes the container to index elements: clears when index is 0, grows or shrinks the buffer and adjusts count and capacity.
// @fnv 0x00695230
void FUN_00695230_shell::FUN_00695230(unsigned int uiNewSize, bool flag)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<Arr3520*>(this)->RemoveAll(flag);
        return;
    }

    if (uiNewSize > capacity)
    {
        if (capacity == 0)
        {
            data = reinterpret_cast<Elem4*>(allocate(uiNewSize));
            capacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(uiNewSize), count);
            capacity = uiNewSize;
        }

        reinterpret_cast<S2f850*>(this)->FUN_0042fa60(
            reinterpret_cast<NavMeshPtr*>(static_cast<unsigned char*>(data) + count * sizeof(Elem4)),
            uiNewSize - count);
        count = uiNewSize;
    }
    else if (uiNewSize < count)
    {
        reinterpret_cast<FUN_006c6200_cls*>(this)->FUN_00822820(
            reinterpret_cast<Elem4*>(static_cast<unsigned char*>(data) + uiNewSize * sizeof(Elem4)), count - uiNewSize);
        count = uiNewSize;

        if (flag && uiNewSize <= capacity / 4)
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(uiNewSize), uiNewSize);
            capacity = uiNewSize;
        }
    }
    else
    {
        reinterpret_cast<S2f850*>(this)->FUN_0042fa60(
            reinterpret_cast<NavMeshPtr*>(static_cast<unsigned char*>(data) + count * sizeof(Elem4)),
            uiNewSize - count);
        count = uiNewSize;
    }
}
}  // namespace fnv_00695230

struct TESChallenge
{
    void* GetFormTwo();
};

struct ES_0081c630 : public TESChallenge
{
};

struct MI_0081c630
{
    ES_0081c630* GetEffectSettingForRange(int);
};

namespace FUN_00821f70_shell {
struct MagicShaderHitEffect
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
    virtual void v37(float)
    {}
    virtual void v38()
    {}
    virtual void v39()
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

    unsigned char padding0[0x1c];
    float fDuration;
    bool bWasPlaying;
    unsigned char padding1[0xb];
    void* m_pEffectShader;

    void FUN_008d05e0(ActiveEffect*, TESObjectREFR*, void*);
    void InitHitEffect(ActiveEffect*, TESObjectREFR*, void*);
};

// @fnv 0x00821f70
void MagicShaderHitEffect::InitHitEffect(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData)
{
    bool btempFinished;
    float ftempAge;

    FUN_008d05e0(apEffect, apTarget, 0);

    if (apEffect != 0)
    {
        m_pEffectShader = reinterpret_cast<MI_0081c630*>(reinterpret_cast<InventoryItem*>(apEffect)->GetObject())
                              ->GetEffectSettingForRange(0)
                              ->GetFormTwo();
    }
    else
    {
        m_pEffectShader = apData;
    }

    ftempAge = fDuration;
    btempFinished = bWasPlaying;

    v49();

    fDuration = ftempAge;
    bWasPlaying = btempFinished;

    v37(0.0f);
}
}

class MagicHitEffect
{
  public:
    MagicHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    virtual ~MagicHitEffect();
    unsigned int refCount;
    float m_fParticleParameter5;
    void* pCell;
    float tempAge;
    bool bInitialized;
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    float m_fFirstFloatValue;
    bool bWasPlaying;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    bool m_bUseActorParticleEffects;
    TESBoundObject* m_pAffectedArmorObject;
};

struct ShaderPropArray
{
    ShaderPropArray();
    ~ShaderPropArray();
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;
};

struct AddOnArray
{
    AddOnArray();
    ~AddOnArray();
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;
};

class FUN_0081f580 : public MagicHitEffect
{
  public:
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    ShaderPropArray m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    AddOnArray m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;

    FUN_0081f580(TESObjectREFR* apTarget, TESEffectShader* apShader, float afDuration);
    virtual ~FUN_0081f580();
};

// Initializes an effect-shader hit effect: stores the shader and duration, sets up third-person state for the player, and loads the shader's addon models.
// @fnv 0x0081f580
FUN_0081f580::FUN_0081f580(TESObjectREFR* apTarget, TESEffectShader* apShader, float afDuration)
    : MagicHitEffect(apTarget, 0), m_pParticleShaderNode(0), spTexEffectData(0)
{
    m_pEffectShader = apShader;
    m_fEffectShaderScale = 0.0f;
    spTexEffectData = 0;
    m_pParticleShaderNode = 0;
    m_bUseActorParticleEffects = false;
    m_pAffectedArmorObject = 0;
    m_fAddonModelTimer = 1.0f;
    m_fAddonModelScale = 1.0f;
    if (pTarget == g_thePlayer)
    {
        b3rdPerson = g_thePlayer->GetNode(false) && !g_thePlayer->GetNode(false)->FUN_00456610();
    }
    else
    {
        b3rdPerson = false;
    }
    if (afDuration < 0.0)
    {
        m_fParticleParameter5 = 3.402823466e+38f;
    }
    else
    {
        m_fParticleParameter5 = afDuration;
    }
    if (m_pEffectShader && m_pEffectShader->GetAddonModels())
    {
        BSSimpleList<DebrisModelEntry*>* pIter = m_pEffectShader->GetAddonModels()->GetData();
        while (pIter && !pIter->IsEmpty())
        {
            g_modelLoader->LoadFile(pIter->GetItem()->filename, 0, true, false, false, false);
            pIter = pIter->GetNext();
        }
    }
}

struct FUN_008220c0_cls;
struct FUN_008220c0_mgr
{
    void FUN_00857a10(unsigned int* p, int n);
};
extern FUN_008220c0_mgr* DAT_011de45c;
unsigned int __fastcall FUN_0084e3a0(void* p);

struct FUN_008220c0_cls
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
    virtual void v53(unsigned int a, void* b);
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    void* m_1c;
    unsigned int unk20, unk24, unk28, unk2c;
    void* m_30;
    void FUN_008220c0();
};

// Writes the values returned by FUN_0084e3a0 for m_1c and m_30 to DAT_011de45c, then calls v53(0, m_1c).
// @fnv 0x008220c0
void FUN_008220c0_cls::FUN_008220c0()
{
    unsigned int a = (unsigned int)FUN_0084e3a0(m_1c);
    DAT_011de45c->FUN_00857a10(&a, 4);
    unsigned int b = (unsigned int)FUN_0084e3a0(m_30);
    DAT_011de45c->FUN_00857a10(&b, 4);
    v53(0, m_1c);
}

struct FUN_008223d0_cls
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94(float);
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float m_20;
    unsigned char m_24;
    void FUN_009dace0(void*);
    void FUN_008223d0(unsigned int a1);
};

// Calls FUN_009dace0 with a1, saves m_20 and m_24, calls vfn_c4, restores both fields, then calls vfn_94(0.0f).
// @fnv 0x008223d0
void FUN_008223d0_cls::FUN_008223d0(unsigned int a1)
{
    float saved;
    unsigned char savedFlag;
    this->FUN_009dace0((void*)a1);
    saved = m_20;
    savedFlag = m_24;
    vfn_c4();
    m_20 = saved;
    m_24 = savedFlag;
    vfn_94(0.0f);
}

struct HitEffShaderSource
{
    TESEffectShader* GetEffectShader();
};

struct HitEffEffectSetting : EffectSetting
{
    HitEffShaderSource* GetShaderSource(int aiIndex);
};

struct HitEffActiveEffect : ActiveEffect
{
    HitEffEffectSetting* GetHitEffectSetting();
};

struct HitEffParticleArray
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;

    HitEffParticleArray();
    ~HitEffParticleArray();
};

struct HitEffAddOnArray
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;

    HitEffAddOnArray();
    ~HitEffAddOnArray();
};

class FUN_0081f350 : public MagicHitEffect
{
  public:
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    HitEffParticleArray m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    HitEffAddOnArray m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;

    FUN_0081f350(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    virtual ~FUN_0081f350();
    ActiveEffect* GetEffect();
};

// @fnv 0x0081f350
FUN_0081f350::FUN_0081f350(TESObjectREFR* apTarget, ActiveEffect* apEffect)
    : MagicHitEffect(apTarget, apEffect), m_pParticleShaderNode(0), spTexEffectData(0)
{
    m_pEffectShader = 0;
    m_pEffectShader =
        static_cast<HitEffActiveEffect*>(apEffect)->GetHitEffectSetting()->GetShaderSource(0)->GetEffectShader();
    m_fEffectShaderScale = 0.0f;
    spTexEffectData = 0;
    m_pParticleShaderNode = 0;
    m_bUseActorParticleEffects = false;
    m_pAffectedArmorObject = 0;
    m_fAddonModelTimer = 1.0f;
    m_fAddonModelScale = 1.0f;
    if (pTarget == (TESObjectREFR*)g_thePlayer)
        b3rdPerson = g_thePlayer->GetNode(false) && !g_thePlayer->GetNode(false)->FUN_00456610();
    else
        b3rdPerson = false;

    if (false)
    {
        DisintegrateArmorEffect* pDisintegrate = dynamic_cast<DisintegrateArmorEffect*>(GetEffect());
        if (pDisintegrate)
        {
            InventoryItem* pItem = pDisintegrate->GetItem();
            if (pItem)
                m_pAffectedArmorObject = pItem->GetObject();
        }
    }

    if (m_pEffectShader && m_pEffectShader->GetAddonModels())
    {
        BSSimpleList<DebrisModelEntry*>* pIter = m_pEffectShader->GetAddonModels()->GetData();
        while (pIter && !pIter->IsEmpty())
        {
            g_modelLoader->LoadFile(pIter->GetItem()->filename, 0, true, false, false, false);
            pIter = pIter->GetNext();
        }
    }
}

struct xNiNode
{
    void Detach(int a);
};

struct xDays
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
    virtual void Detach(struct xProc* p);
};

struct xProc
{
    xDays* GetDays();
};

template <class T> struct xPtr
{
    T* m_pObject;
    operator T*() const;
    bool operator!=(T* p) const;
    void operator=(T* p);
    ~xPtr();
};

template <class T> struct xArr
{
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    unsigned int m_uiGrow;
    unsigned int GetSize();
    T& GetAt(int i);
    void RemoveAll(bool b);
    ~xArr();
};

template <class T> struct xArr2
{
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    unsigned int m_uiGrow;
    int m_iPad[2];
    unsigned int GetSize();
    T& GetAt(int i);
    ~xArr2();
};

struct xEntry
{
    int m_iWordAt00;
    const char* m_pPath;
};

struct xCond
{
    bool IsDone();
    xEntry** GetEntry();
    xCond* GetNext();
};

struct xAddon
{
    xCond* GetFirst();
};

struct xModel
{
    const char* GetPath();
    unsigned int GetLength();
};

struct xForm
{
    int GetID();
    void Attach(xNiNode* a, xNiNode* b);
    void AttachChildInAvailableSlot(xNiNode* a, xNiNode* b);
    xModel* GetModelA();
    xModel* GetModelB();
    xAddon* GetAddon();
};

struct xAudio
{
    static xAudio* Get();
    void Play(xNiNode* n, float f, int i);
};

struct xTES
{
    void Precache(const char* p, int i);
};

struct xLoader
{
    void Queue(const char* p);
};

struct xRef
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
    virtual xNiNode* Get3D();
    xNiNode* GetNode(bool b);
};

struct xEffectBase
{
    virtual void v000();
    char _pad04[0x18];
    xRef* m_pReference;
    char _pad20[0x10];
    xForm* m_pForm;
    int m_34;
    int GetID();
    ~xEffectBase();
};

struct FUN_0081f770 : xEffectBase
{
    xArr<xPtr<xNiNode> > m_kNodeArray;
    xPtr<xNiNode> m_spNode;
    int m_4c;
    xArr2<xPtr<xProc> > m_kProcs;
    xPtr<xNiNode> m_spRootNode;
    ~FUN_0081f770();
};

extern xRef* xg_pPlayer;
extern xTES* xg_pTES;
extern xLoader* xg_pLoader;
extern "C" int __cdecl sprintf_s(char* buf, unsigned int size, const char* fmt, ...);

// @fnv 0x0081f770
FUN_0081f770::~FUN_0081f770()
{
    if (!GetID() & (m_pReference != xg_pPlayer))
        m_pReference = 0;
    if (m_spRootNode)
    {
        if (m_pReference == xg_pPlayer)
        {
            xNiNode* pkNode = xg_pPlayer->GetNode(1);
            if (pkNode)
                m_pForm->Attach(pkNode, m_spRootNode);
            pkNode = xg_pPlayer->GetNode(0);
            if (pkNode)
                m_pForm->Attach(pkNode, m_spRootNode);
        }
        else if (m_pReference)
        {
            xNiNode* pk3D = m_pReference->Get3D();
            if (pk3D)
                m_pForm->Attach(pk3D, m_spRootNode);
        }
    }
    if (m_spNode != 0)
    {
        for (unsigned int i = 0; i < m_kNodeArray.GetSize(); i++)
            m_pForm->AttachChildInAvailableSlot(m_spNode, m_kNodeArray.GetAt(i));
    }
    if (m_kProcs.GetSize() > 0)
    {
        for (unsigned int j = 0; j < m_kProcs.GetSize(); j++)
        {
            xProc* pkProc = m_kProcs.GetAt(j);
            if (pkProc->GetDays())
                pkProc->GetDays()->Detach(pkProc);
        }
    }
    m_kNodeArray.RemoveAll(true);
    if (m_spNode != 0)
        ((xNiNode*)m_spNode)->Detach(0);
    m_spNode = 0;
    m_spRootNode = 0;
    if (m_pForm)
    {
        if (m_pReference && (m_pForm->GetID() == 0x852fe || m_pForm->GetID() == 0x84a51))
            xAudio::Get()->Play(m_pReference->Get3D(), 1.0f, 0);
        char acPath[260];
        if (m_pForm->GetModelA()->GetPath())
        {
            sprintf_s(acPath, 0x104, "%s\\%s", "Textures", m_pForm->GetModelA()->GetPath());
            xg_pTES->Precache(acPath, 0);
        }
        if (m_pForm->GetModelB()->GetLength() > 0)
        {
            sprintf_s(acPath, 0x104, "%s\\%s", "Textures", m_pForm->GetModelB()->GetPath());
            xg_pTES->Precache(acPath, 0);
        }
        if (m_pForm && m_pForm->GetAddon())
        {
            xCond* pkCond = m_pForm->GetAddon()->GetFirst();
            while (pkCond && !pkCond->IsDone())
            {
                xg_pLoader->Queue((*pkCond->GetEntry())->m_pPath);
                pkCond = pkCond->GetNext();
            }
        }
    }
}

namespace ParticleUpdate {
struct Scene
{
    float GetFieldB4Float();
};
struct Actor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual bool IsActor();
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
    virtual Scene* SceneGraph();
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
    virtual float Scale();
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
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void Finish(bool, bool, bool);
    float FUN_008c4850();
    void SetProcessValue(float);
    void FUN_008c4640();
    Actor* FUN_008d8520();
};
struct Texture;
template <class T> struct Ref
{
    T* value;
    T* FUN_00559450();
};
struct Texture
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    float alpha;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    float scale;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    float first;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    float second;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    Ref<void> source;
};
struct Property
{
    float FUN_006a78f0();
    void FUN_00821600(float);
    void FUN_00821620(float);
    void FUN_00ba7b60(float, bool, bool);
    int FUN_004fd380();
};
struct Node
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual Node* AsNode();
    void FUN_00440490(float);
};
template <class T> struct Array
{
    unsigned int unk0;
    T* data;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    T& FUN_006a7ad0(unsigned int);
};
struct TestRef
{
    void* value;
    unsigned int unk4;
    bool FUN_0052aa80(int);
};
struct Data
{
    float FUN_00507da0(float, float, float, bool);
    float FUN_00821640();
    float FUN_00821660();
    float GetFloatAt144();
    float GetValue();
    float FUN_00567470();
    float FUN_00821680();
    void UpdateShaderState(Texture*, float, float, float, bool);
};
Data* FUN_0080d0d0();
bool FUN_0043b300(void*, Scene*);
extern unsigned int DAT_011f9140;
extern double DAT_0106d508, DAT_01012060, DAT_0101a6b0;
extern float DAT_0106682c, DAT_01013ea4;
unsigned int FUN_00ba52d0();
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
void FUN_00b6bb30(Node*, float);
struct Effect
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void Finish();
    virtual void Refresh();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Actor* target;
    float age;
    bool finished;
    unsigned char unk25, unk26, unk27;
    unsigned int unk28;
    unsigned int unk2c;
    Data* data;
    float timer;
    Array<Ref<Property> > properties;
    TestRef node;
    Array<Ref<Node> > addons;
    float alpha;
    float scale;
    Ref<Texture> texture;
    bool UpdateMagicHitEffect(float);
    bool FUN_00820f30(float);
};
// Advances the effect timer, updates properties, addons and texture, and finishes the effect when all parts are done.
// @fnv 0x00820f30
bool Effect::FUN_00820f30(float afDeltaTime)
{
    if (!UpdateMagicHitEffect(afDeltaTime) || !target || !target->SceneGraph())
    {
        Finish();
        return false;
    }
    timer += afDeltaTime;
    bool done = finished;
    Refresh();
    float multiplier = 1.0f;
    if (target->IsActor() && data != FUN_0080d0d0())
    {
        if (texture.FUN_00559450() && texture.FUN_00559450()->source.FUN_00559450() && target->IsActor() &&
            target->FUN_008c4850() > DAT_0106d508)
        {
            target->SetProcessValue(DAT_0106682c);
            target->FUN_008c4640();
        }
        Scene* scene = target->SceneGraph();
        if (FUN_0043b300(&DAT_011f9140, scene))
        {
            Scene* castScene = scene;
            multiplier = castScene->GetFieldB4Float();
        }
        else
            multiplier = target->Scale();
        float actorScale = target->FUN_008c4850();
        if (actorScale > DAT_01012060)
            multiplier /= actorScale;
    }
    if (properties.FUN_0044ddc0() > 0 && node.FUN_0052aa80(0))
    {
        float total = 0.0f;
        for (unsigned int index = 0; index < properties.FUN_0044ddc0(); index++)
            total += properties.FUN_006a7ad0(index).FUN_00559450()->FUN_006a78f0() * FUN_00ba52d0();
        float available = data->FUN_00507da0(total, afDeltaTime, timer, finished);
        if (available > DAT_01012060)
            done = false;
        for (unsigned int index2 = 0; index2 < properties.FUN_0044ddc0(); index2++)
        {
            float amount = FUN_0040ebd0(available, float(FUN_00ba52d0()));
            available -= amount;
            Property* propertySlot1 = properties.FUN_006a7ad0(index2).FUN_00559450();
            propertySlot1->FUN_00821600(amount / FUN_00ba52d0());
            propertySlot1->FUN_00821620(multiplier);
            propertySlot1->FUN_00ba7b60(timer, false, true);
            if (propertySlot1->FUN_004fd380() > 0)
                done = false;
        }
        if (addons.FUN_0044ddc0() > 0)
        {
            float delta = afDeltaTime / (!finished ? data->FUN_00821640() : data->FUN_00821660() * DAT_0101a6b0);
            alpha = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, alpha + delta));
            if (alpha > DAT_01012060)
                done = false;
            delta = afDeltaTime / (!finished ? data->GetFloatAt144() : data->GetValue() * DAT_0101a6b0);
            scale = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, scale + delta));
            float maximumSlot16 = 1.0f;
            float minimum = !finished ? FUN_00404010(DAT_01013ea4, data->FUN_00567470())
                                      : FUN_00404010(DAT_01013ea4, data->FUN_00821680());
            float factorSlot13 = minimum + (maximumSlot16 - minimum) * scale;
            for (unsigned int index3 = 0; index3 < addons.FUN_0044ddc0(); index3++)
            {
                FUN_00b6bb30(addons.FUN_006a7ad0(index3).FUN_00559450()->AsNode(), alpha);
                addons.FUN_006a7ad0(index3).FUN_00559450()->FUN_00440490(factorSlot13);
            }
        }
    }
    if (texture.FUN_00559450())
    {
        data->UpdateShaderState(texture.FUN_00559450(), afDeltaTime, timer, age, finished);
        texture.FUN_00559450()->alpha *= multiplier;
        texture.FUN_00559450()->scale *= multiplier;
        if (texture.FUN_00559450()->second > DAT_01012060 || texture.FUN_00559450()->first > DAT_01012060)
            done = false;
    }
    if (finished && done)
    {
        if (target->IsActor() && target->FUN_008d8520())
            target->FUN_008d8520()->Finish(true, true, false);
        Finish();
        return false;
    }
    return true;
}
}

template <class T> struct PtrX_821bd0
{
    T* object;
    operator T*() const;
    PtrX_821bd0& operator=(T*);
    bool operator!=(int) const;
};
struct NodeX_821bd0
{
    void SetParent(NiNode* apParent);
};
struct TexEffX_821bd0;
struct EffShaderX_821bd0
{
    void ClearItemRef(NiNode*, TexEffX_821bd0*);
    void FUN_00507810(NodeX_821bd0*, ParticleShaderProperty*);
};
struct BSAudioX_821bd0
{
    void FUN_00ad8570(NiNode*, float, bool);
};

struct MagicShaderHitEffect_821bd0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    TESObjectREFR* pTarget;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    EffShaderX_821bd0* m_pEffectShader;
    float m_fEffectShaderScale;
    BSSimpleArray<NiPointer<ParticleShaderProperty> > m_kParticleShaderProperties;
    PtrX_821bd0<NodeX_821bd0> m_pParticleShaderNode;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    PtrX_821bd0<TexEffX_821bd0> spTexEffectData;
    void ApplyAndCleanup();
};

// Applies the shader effect to the target's nodes, plays a sound for certain shader types, then clears the effect data and target.
// @fnv 0x00821bd0
void MagicShaderHitEffect_821bd0::ApplyAndCleanup()
{
    if (pTarget && m_pEffectShader &&
        (FUN_0084e3a0(m_pEffectShader) == 0x852fe || FUN_0084e3a0(m_pEffectShader) == 0x84a51))
        ((BSAudioX_821bd0*)BSAudio::GetSingleton())->FUN_00ad8570(pTarget->GetNiNode_v(), 1.0f, false);

    if (spTexEffectData)
    {
        if (pTarget == g_thePlayer)
        {
            NiNode* pNode = g_thePlayer->GetNode(true);
            if (pNode)
                m_pEffectShader->ClearItemRef(pNode, spTexEffectData);
            pNode = g_thePlayer->GetNode(false);
            if (pNode)
                m_pEffectShader->ClearItemRef(pNode, spTexEffectData);
        }
        else if (pTarget)
        {
            NiNode* pRoot = pTarget->GetNiNode_v();
            if (pRoot)
                m_pEffectShader->ClearItemRef(pRoot, spTexEffectData);
        }
    }

    if (m_pParticleShaderNode != 0)
    {
        for (unsigned int i = 0; i < m_kParticleShaderProperties.GetSize(); i++)
            m_pEffectShader->FUN_00507810(m_pParticleShaderNode, m_kParticleShaderProperties.GetAt(i));
    }
    m_kParticleShaderProperties.RemoveAll(true);
    if (m_pParticleShaderNode != 0)
        ((NodeX_821bd0*)m_pParticleShaderNode)->SetParent(0);
    m_pParticleShaderNode = 0;
    spTexEffectData = 0;
    pTarget = 0;
}

extern unsigned char DAT_011f4428;
extern "C" NiNode* __cdecl FUN_00653270(const void*, NiAVObject*);

struct ThreeByThreeMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ThreeByThreeMatrix Transpose() const;
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix& rhs) const;
    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct MyAVObject : NiAVObject
{
    const ThreeByThreeMatrix& GetWorldRotate();
    void GetTransformScale(const NiPoint3&);
};

struct PtrCheck
{
    bool operator!=(int) const;
};

struct Target3DHelper
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v30();
    virtual void* v31();
    virtual void* v32();
    virtual void* v33();
    virtual void* v34();
    virtual void* v35();
    virtual void* v36();
    virtual void* v37();
    virtual void* v38();
    virtual void* v39();
    virtual void* v40();
    virtual void* v41();
    virtual void* v42();
    virtual void* v43();
    virtual void* v44();
    virtual void* v45();
    virtual void* v46();
    virtual void* v47();
    virtual void* v48();
    virtual void* v49();
    virtual void* v50();
    virtual void* v51();
    virtual void* v52();
    virtual void* v53();
    virtual void* v54();
    virtual void* v55();
    virtual void* v56();
    virtual void* v57();
    virtual void* v58();
    virtual void* v59();
    virtual void* v60();
    virtual void* v61();
    virtual void* v62();
    virtual void* v63();
    virtual void* v64();
    virtual void* v65();
    virtual void* v66();
    virtual void* v67();
    virtual void* v68();
    virtual void* v69();
    virtual void* v70();
    virtual void* v71();
    virtual void* v72();
    virtual void* v73();
    virtual void* v74();
    virtual void* v75();
    virtual void* v76();
    virtual void* v77();
    virtual void* v78();
    virtual void* v79();
    virtual void* v80();
    virtual void* v81();
    virtual void* v82();
    virtual void* v83();
    virtual void* v84();
    virtual void* v85();
    virtual void* v86();
    virtual void* v87();
    virtual void* v88();
    virtual void* v89();
    virtual void* v90();
    virtual void* v91();
    virtual void* v92();
    virtual void* v93();
    virtual void* v94();
    virtual void* v95();
    virtual void* v96();
    virtual void* v97();
    virtual void* v98();
    virtual void* v99();
    virtual void* v100();
    virtual void* v101();
    virtual void* v102();
    virtual void* v103();
    virtual void* v104();
    virtual void* v105();
    virtual void* v106();
    virtual void* v107();
    virtual void* v108();
    virtual void* v109();
    virtual void* v110();
    virtual void* v111();
    virtual void* v112();
    virtual void* v113();
    virtual void* v114();
    virtual void* v115();
    virtual NiAVObject* v116();
};

class EffView : public MagicShaderHitEffect
{
  public:
    TESObjectREFR* GetTarget();
    void FUN_0081bc70(NiAVObject*);
};

// @fnv 0x008217e0
void __fastcall UpdateEffectNode(EffView* pEffectView)
{
    bool bInitTmp = (pEffectView->GetTarget() == g_thePlayer);
    bool pTargetObj5 = (bInitTmp && g_thePlayer != 0 && g_thePlayer->GetField6A4() == pEffectView) ? 1 : 0;
    bool pActor1 = (bInitTmp && g_thePlayer != 0 && g_thePlayer->GetNode(false) != 0 &&
                    g_thePlayer->GetNode(false)->FUN_00456610())
                       ? 1
                       : 0;
    NiAVObject* pRef4 = 0;
    if (!pEffectView->m_bUseActorParticleEffects)
    {
        if (bInitTmp)
        {
            pRef4 = g_thePlayer->GetNode(false);
        }
        else
        {
            pRef4 = ((Target3DHelper*)pEffectView->pTarget)->v116();
        }
    }
    else
    {
        float f_j;
        bool b_k;
        NiAVObject* p1_j;
        NiAVObject* p2_c;
        pEffectView->GetSceneGraphData(b_k, b_k, f_j, p1_j, p2_c);
        pRef4 = p2_c;
    }

    if (((PtrCheck*)&pEffectView->m_pParticleShaderNode)->operator!=(0) && pRef4 != 0)
    {
        ThreeByThreeMatrix mat = pEffectView->m_bUseActorParticleEffects ? ((MyAVObject*)pRef4)->GetWorldRotate()
                                                                : *(const ThreeByThreeMatrix*)&DAT_011a9448;
        if (pTargetObj5)
        {
        }
        else
        {
            if (pActor1 && g_thePlayer->GetNode(true) != 0)
            {
                NiNode* pCastNode = FUN_00653270(&DAT_011f4428, g_thePlayer->GetNode(true));
                if (pCastNode != 0 && pCastNode != pEffectView->m_pParticleShaderNode->GetParent())
                {
                    pCastNode->AddObject(pEffectView->m_pParticleShaderNode, true);
                }
                if (pActor1)
                {
                    pEffectView->m_pParticleShaderNode->FUN_0043fa80(
                        &(((MyAVObject*)pEffectView->m_pParticleShaderNode->GetParent())->GetWorldRotate().Transpose() *
                          mat));
                    ((MyAVObject*)(NiAVObject*)pEffectView->m_pParticleShaderNode)
                        ->GetTransformScale(
                            ((MyAVObject*)pEffectView->m_pParticleShaderNode->GetParent())
                                ->GetWorldRotate()
                                .Transpose() *
                            (pRef4->FUN_0045bb80() - pEffectView->m_pParticleShaderNode->GetParent()->FUN_0045bb80()));
                    NiUpdateData updateData(0.0f, false, false);
                    pEffectView->m_pParticleShaderNode->Update(updateData);
                }
                else
                {
                    pEffectView->m_pParticleShaderNode->FUN_0043fa80(&mat);
                    ((MyAVObject*)(NiAVObject*)pEffectView->m_pParticleShaderNode)
                        ->GetTransformScale(pRef4->FUN_0045bb80());
                }
            }
            else
            {
                ((MyAVObject*)(NiAVObject*)pEffectView->m_pParticleShaderNode)
                    ->GetTransformScale(pRef4->FUN_0045bb80());
                pEffectView->m_pParticleShaderNode->FUN_0043fa80(&mat);
            }
        }
    }

    if (pActor1 || pTargetObj5)
    {
        pEffectView->FUN_0081bc70(0);
    }
    else
    {
        pEffectView->FUN_0081bc70(pEffectView->m_pParticleShaderNode);
    }
}

namespace fnv_00822130 {
struct Node
{
    bool FUN_00450ff0();
};
struct Ref
{
    Node* FUN_008d6f30();
};
struct Manager
{
    void FUN_00857aa0(void**, int);
};
extern Manager* DAT_011de45c;
extern char DAT_011841cc, DAT_01183918, DAT_01183028;
TESForm* __cdecl LookupFormByID(void*);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
class Effect
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4c();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5c();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6c();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7c();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8c();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9c();
    virtual void vfna0();
    virtual void vfna4();
    virtual void vfna8();
    virtual void vfnac();
    virtual void vfnb0();
    virtual void vfnb4();
    virtual void vfnb8();
    virtual void vfnbc();
    virtual void vfnc0();
    virtual void vfnc4();
    virtual void vfnc8();
    virtual void vfncc();
    virtual void vfnd0();
    virtual void vfnd4();
    virtual void vfnd8(int, Ref*);
    virtual void vfndc(int, Ref*);
    virtual void vfne0(int, Ref*, TESEffectShader*);
    int unk04;
    float unk08;
    void* unk0c;
    float unk10;
    bool unk14;
    void* unk18;
    Ref* unk1c;
    bool FUN_00822130();
};
// Reads two 4-byte values, resolves reference and shader forms, calls vfnd8, and calls vfndc and vfne0 when both resolve.
// @fnv 0x00822130
bool Effect::FUN_00822130()
{
    bool result2 = true;
    void* firstB;
    DAT_011de45c->FUN_00857aa0(&firstB, 4);
    unk1c = reinterpret_cast<Ref*>(dynamic_cast<TESObjectREFR*>(LookupFormByID(firstB)));
    if (!unk1c || !unk1c->FUN_008d6f30() || !unk1c->FUN_008d6f30()->FUN_00450ff0())
        result2 = false;
    void* second;
    DAT_011de45c->FUN_00857aa0(&second, 4);
    TESEffectShader* other7 = dynamic_cast<TESEffectShader*>(LookupFormByID(second));
    if (!other7)
        result2 = false;
    vfnd8(0, unk1c);
    if (result2)
    {
        vfndc(0, unk1c);
        vfne0(0, unk1c, other7);
    }
    return result2;
}
}  // namespace fnv_00822130

struct FUN_006e6da0
{
    int a;
};
void* __cdecl operator new(unsigned int uiSize, FUN_006e6da0* pPlace);
inline void __cdecl operator delete(void*, FUN_006e6da0*)
{}
class FUN_00633c90
{
  public:
    FUN_00633c90(int iArg);
    int unk0;
};
class ArrX
{
  public:
    void ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray);
};
// @fnv 0x00822780
void ArrX::ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        new (&pData[i]) FUN_00633c90(0);
    }
}

TESForm* GetFormByID(int);

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Reads effect shader scale, particle effects flag, and affected armor object ID from the save stream.
// @fnv 0x00821ed0
void ShaderLoadView::FUN_00821ed0(ActiveEffect* effect, TESObjectREFR* target)
{
    SaveLoad(effect, target);
    g_TESSaveLoadGame->ReadTypedData(&m_fEffectShaderScale, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x37)
    {
        g_TESSaveLoadGame->ReadTypedData(&m_bUseActorParticleEffects, 1);
        unsigned int objectID;
        g_TESSaveLoadGame->FUN_00857aa0(&objectID, 4);
        if (objectID)
            m_pAffectedArmorObject = dynamic_cast<TESBoundObject*>(GetFormByID(objectID));
    }
}
