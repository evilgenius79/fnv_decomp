// fallout_shared/bgstalkingactivator.cpp: BGSTalkingActivator, Pathing, TalkingActivatorComparison, TESObjectACTI and more (23 functions)

#include "bgstalkingactivator.h"
#include <malloc.h>

static const char s_kTalkingVoiceTypeWarning[] =
    "MASTERFILE: Could not find voice type (%08X) for activator '%s' (%08X).";

// @fnv 0x004fe7a0
void BGSTalkingActivator::ResetFormData()
{
    m_kFactionList = 0;
    TESObjectACTI::ResetFormData();
}

// @fnv 0x004fe7c0
void BGSTalkingActivator::InitItem()
{
    unsigned int voiceTypeID;
    if (GetInitialized())
        return;
    TESObjectACTI::InitItem();
    m_pTempRef = 0;
    voiceTypeID = reinterpret_cast<unsigned int>(m_kFactionList);
    if (voiceTypeID)
    {
        RemapFormIDForFile(voiceTypeID, GetFile(-1));
        m_kFactionList = dynamic_cast<BGSVoiceType*>(TESFormInitFlag::GetFormByID(voiceTypeID));
        if (!m_kFactionList)
            Warning(s_kTalkingVoiceTypeWarning, voiceTypeID, GetName(), GetFormID());
    }
    SetInitializationState(true);
}

#include "bgstalkingactivator_radio.h"

// @fnv 0x004ff1a0
void BGSTalkingActivator::FindRadioStations(TESObjectREFR* ref, BSSimpleList<TESObjectREFR*>* stations,
                                            BSSimpleList<float>* distances)
{
    if (!stations || !ref || !ref->GetParentCell())
        return;
    TESWorldSpace* m_pContainingWorldspace = ref->GetParentWorldSpace();
    TESObjectCELL* m_pReferenceCell = 0;
    if (!m_pContainingWorldspace)
        m_pReferenceCell = ref->GetParentCell();
    float fDistance = FLT_MAX;
    bool bReferencePresent = false;
    BSSimpleList<TESObjectREFR*>* pCurrent = &ms_kRadioStations;
    while (pCurrent && !pCurrent->IsEmpty())
    {
        TESObjectREFR* pCurrentRadioStation = pCurrent->GetItem();
        bReferencePresent = false;
        fDistance = FLT_MAX;
        if (!pCurrentRadioStation->GetDisabled() || !m_pContainingWorldspace)
        {
            switch (pCurrentRadioStation->GetRadioRangeType())
            {
            case RADIO_RADIUS: {
                TESObjectREFR* pExteriorRef = pCurrentRadioStation->GetExteriorRadioReference();
                if (!pExteriorRef)
                    pExteriorRef = pCurrentRadioStation;
                TESWorldSpace* pStationWorldSpace = pExteriorRef->GetParentWorldSpace();
                if (!pStationWorldSpace)
                    Warning("DEFAULT: Radio station exterior position ref '%s' (%08X) is not placed in an exterior.",
                            pExteriorRef->GetName(), pExteriorRef->GetFormID());
                else
                {
                    if (m_pContainingWorldspace && m_pContainingWorldspace == pStationWorldSpace)
                        fDistance = ref->GetLightLevelAtPoint(*pExteriorRef->GetPos());
                    else if (!m_pContainingWorldspace)
                        fDistance = Pathing::FindPathDistance(
                            PathingLocation(pCurrentRadioStation), PathingLocation(ref),
                            pCurrentRadioStation->GetRadioStationRange(), 0, Pathing::RADIO_LOCKS);
                    if (fDistance < pCurrentRadioStation->GetRadioStationRange())
                        bReferencePresent = true;
                }
            }
            break;
            case RADIO_EVERYWHERE:
                bReferencePresent = true;
                fDistance = -1.0f;
                break;
            case RADIO_WORLDSPACE: {
                TESWorldSpace* pStationWorldSpace = pCurrentRadioStation->GetParentWorldSpace();
                if (!pStationWorldSpace)
                    Warning(
                        "DEFAULT: Radio station ref '%s' (%08X) is set to worldspace and connected interiors but is not placed in an exterior.",
                        pCurrentRadioStation->GetName(), pCurrentRadioStation->GetFormID());
                else if (m_pContainingWorldspace)
                {
                    if (m_pContainingWorldspace == pStationWorldSpace)
                    {
                        bReferencePresent = true;
                        fDistance = -1.0f;
                    }
                }
                else
                {
                    PathingPath path;
                    if (Pathing::FindRouteBetweenLocations(PathingLocation(pCurrentRadioStation), PathingLocation(ref),
                                                           &path, Pathing::ONE_WORLDSPACE, 0.0f, 0,
                                                           Pathing::IGNORE_LOCKS))
                    {
                        bReferencePresent = true;
                        fDistance = -1.0f;
                        unsigned int count = path.Spaces.GetSize();
                        for (unsigned int i = 0; i < count; ++i)
                        {
                            TESWorldSpace* pathWorld = path.Spaces.GetAt(i).m_pContainingWorldspace;
                            if (pathWorld && pathWorld != pStationWorldSpace)
                            {
                                bReferencePresent = false;
                                break;
                            }
                        }
                    }
                }
            }
            break;
            case RADIO_INTERIORS:
                if (m_pReferenceCell)
                {
                    PathingPath path;
                    if ((ref->GetParentCell() && pCurrentRadioStation->GetParentCell() &&
                         ref->GetParentCell() == pCurrentRadioStation->GetParentCell()) ||
                        Pathing::FindRouteBetweenLocations(PathingLocation(pCurrentRadioStation), PathingLocation(ref),
                                                           &path, Pathing::INTERIOR_ONLY, 0.0f, 0,
                                                           Pathing::IGNORE_LOCKS))
                    {
                        bReferencePresent = true;
                        fDistance = -1.0f;
                        unsigned int count = path.Spaces.GetSize();
                        for (unsigned int i = 0; i < count; ++i)
                        {
                            if (path.Spaces.GetAt(i).m_pContainingWorldspace)
                            {
                                bReferencePresent = false;
                                break;
                            }
                        }
                    }
                }
                break;
            case RADIO_CELL:
                if (ref->GetParentCell() && pCurrentRadioStation->GetParentCell() &&
                    ref->GetParentCell() == pCurrentRadioStation->GetParentCell())
                {
                    bReferencePresent = true;
                    fDistance = -1.0f;
                }
                break;
            }
            if (bReferencePresent)
            {
                stations->AddHead(pCurrentRadioStation);
                if (distances)
                    distances->AddHead(fDistance);
            }
        }
        pCurrent = pCurrent->GetNext();
    }
}

#include "bgstalkingactivator_load.h"

// Reads the record header and iterates chunks, dispatching each to the matching sub-record loader until no chunks remain, then returns true.
// @fnv 0x004fe890
bool BGSTalkingActivator::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 'LDOM':
        case 'TDOM':
        case 'DDOM':
        case 'DSOM':
            TESModel::LoadModelData(this, file);
            break;
        case 'SDOM': {
            unsigned int size = file->GetChunkSize();
            void* pChunkData = _alloca(size);
            file->GetChunkData(pChunkData, size);
            ParseTextureSwapData(pChunkData, size, static_cast<TESFileFormVersion*>(file)->GetFormVersion());
        }
        break;
        case 'IRCS': {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
        }
        break;
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 'MANS': {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            SetLoopingSound(reinterpret_cast<TESSound*>(soundID));
        }
        break;
        case 'MANI': {
            unsigned int templateID = 0;
            file->GetChunkData(&templateID);
            // Radio-template setter is folded with this canonical +0x7C setter.
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(
                reinterpret_cast<TESEffectShader*>(templateID));
        }
        break;
        case 'MANV': {
            unsigned int voiceID = 0;
            file->GetChunkData(&voiceID);
            SetVoiceType(reinterpret_cast<BGSVoiceType*>(voiceID));
        }
        break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Returns true if form is a talking activator (form type 0x16) whose IsRadioStation check succeeds.
// @fnv 0x004fede0
bool BGSTalkingActivator::IsRadioStation(TESForm* form, unsigned int data)
{
    bool result = false;
    if (form && form->GetFormType() == 0x16)
    {
        BGSTalkingActivator* activator = static_cast<BGSTalkingActivator*>(form);
        if (activator->IsRadioStation())
            result = true;
    }
    return result;
}

// If ref is non-null and its object reference is a radio station, adds ref to the head of the list.
// @fnv 0x004ff150
void BGSTalkingActivator::AddRadioStation(TESObjectREFR* ref)
{
    if (ref && IsRadioStation(ref->GetObjectReference(), 0))
        ms_kRadioStations.AddHead(ref);
}

// @fnv 0x004febf0
void BGSTalkingActivator::SetVoiceType(BGSVoiceType* apVoiceType)
{
    m_kFactionList = apVoiceType;
}

// @fnv 0x004febb0
void TESObjectACTI::SetLoopingSound(TESSound* sound)
{
    m_pSoundEffect = sound;
}

// @fnv 0x004febd0
void EffectSetting::SetEnchantEffectShader(TESEffectShader* shader)
{
    pEnchantEffectShader = shader;
}

// @fnv 0x004fedc0
bool BGSTalkingActivator::IsRadioStation()
{
    return IsRadioStationObject();
}

struct Actor;
struct FUN_00516bf0_shell : public BGSTalkingActivator
{
    Actor* FUN_00516bf0();
};

// @fnv 0x00516bf0
Actor* FUN_00516bf0_shell::FUN_00516bf0()
{
    return *(Actor**)((char*)this + 0x90);
}

struct Elem12
{
    int data[3];
};

struct ArrayObj
{
    int unk0;
    Elem12* m_pBase;
};

struct StackIdx
{
    unsigned int i;
};

// @fnv 0x006a1440
Elem12& __fastcall FUN_006a1440(ArrayObj* pThis, StackIdx aiIndex)
{
    return pThis->m_pBase[aiIndex.i];
}

// @fnv 0x004ff190
void FUN_004ff190()
{
    BGSTalkingActivator::ms_kRadioStations.RemoveAll();
}

void _Deallocate(void*);
struct FUN_004fe6e0_Class
{
    void __thiscall FUN_004fe710();
    void* __thiscall FUN_004fe6e0(unsigned int);
};
// Calls FUN_004fe710, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004fe6e0
void* __thiscall FUN_004fe6e0_Class::FUN_004fe6e0(unsigned int flags)
{
    FUN_004fe710();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct PlayerMover
{
    unsigned int GetActorStateFlags();
};
struct Proxy00511120
{
    void FUN_00511120(TESForm*);
};
struct FUN_004fecf0_ : BGSTalkingActivator
{
    void CopyVoiceTypeFromActivator(TESForm*);
};
// @fnv 0x004fecf0
void FUN_004fecf0_::CopyVoiceTypeFromActivator(TESForm* apCopy)
{
    BGSTalkingActivator* acti = dynamic_cast<BGSTalkingActivator*>(apCopy);
    if (!acti)
        return;
    ((Proxy00511120*)this)->FUN_00511120(apCopy);
    SetVoiceType((BGSVoiceType*)((PlayerMover*)acti)->GetActorStateFlags());
}

struct FormChangeMask
{
    int flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
};
struct BGSSaveFormBuffer : public BGSLoadFormBuffer
{
    void SerializeFormData(void*, int);
};
struct FUN_00511860_shell
{
    void FUN_00511860(void*);
};
struct FUN_004ff800_shell : public FUN_00511860_shell
{
    void FUN_004ff800(BGSSaveFormBuffer*);
};
// @fnv 0x004ff800
void FUN_004ff800_shell::FUN_004ff800(BGSSaveFormBuffer* apSaveGameBuffer)
{
    FUN_00511860_shell::FUN_00511860(apSaveGameBuffer);
    if (apSaveGameBuffer->GetChangeFlags(0x800000))
        apSaveGameBuffer->SerializeFormData(((void**)this)[36], 0);
}

namespace fnv_004ff850 {
struct FormChangeMask
{
    int m_uiFileCount;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
    bool ReadFormIdentifier(void*);
};
struct Base005118c0
{
    void FUN_005118c0(BGSLoadFormBuffer*);
};
struct FUN_004ff850_shell
{
    char _pad[0x90];
    int _90;
    void LoadForm(BGSLoadFormBuffer*);
};
// @fnv 0x004ff850
void FUN_004ff850_shell::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((Base005118c0*)this)->FUN_005118c0(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x800000))
    {
        apLoadGameBuffer->ReadFormIdentifier(&_90);
    }
}
}  // namespace fnv_004ff850

namespace fnv_004ff930 {
struct FormChangeMask
{
    unsigned int m_flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int);
};
struct FUN_004ff930_shell : TESForm
{
    void RevertAndClearField(BGSLoadFormBuffer*);
};
// @fnv 0x004ff930
void FUN_004ff930_shell::RevertAndClearField(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (apLoadGameBuffer->GetOldChangeFlags(0x800000))
        *(int*)((char*)this + 0x90) = 0;
}
}  // namespace fnv_004ff930

struct S_00477f20
{
    void FUN_00477f20();
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
void FUN_00485910(unsigned int, unsigned int);
struct FUN_004fec10_shell
{
    void FUN_004fec10();
};
// @fnv 0x004fec10
void FUN_004fec10_shell::FUN_004fec10()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00487010();
    reinterpret_cast<S_0048a520*>(reinterpret_cast<char*>(this) + 0x3c)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<S_0048cca0*>(reinterpret_cast<char*>(this) + 0x5c)->FUN_0048cca0();
    reinterpret_cast<S_00477f20*>(reinterpret_cast<char*>(this) + 0x68)->FUN_00477f20();
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x74))
    {
        unsigned int id =
            reinterpret_cast<TESForm*>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x74))
                ->GetFormID();
        FUN_00485910(0x4d414e53, id);
    }
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x94))
    {
        unsigned int id =
            reinterpret_cast<TESForm*>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x94))
                ->GetFormID();
        FUN_00485910(0x4d414e56, id);
    }
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x7c))
    {
        unsigned int id =
            reinterpret_cast<TESForm*>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x7c))
                ->GetFormID();
        FUN_00485910(0x4d414e49, id);
    }
    reinterpret_cast<FUN_00485680*>(this)->M();
}

extern void* DAT_01025520;

struct FUN_004fe640 : public TESObjectACTI
{
    FUN_004fe640();
    virtual ~FUN_004fe640();
};

// @fnv 0x004fe640
FUN_004fe640::FUN_004fe640()
{
    *(void**)((char*)this + 0x70) = &DAT_01025520;
    SetFormType((ENUM_FORM_ID)0x16);
    reinterpret_cast<BGSTalkingActivator*>(this)->BGSTalkingActivator::ResetFormData();
}

class C4FE710BoundAnimObject
{
  public:
    virtual ~C4FE710BoundAnimObject();
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
};

class C4FE710FullName
{
  public:
    virtual ~C4FE710FullName();
    int unk04;
    int unk08;
};

class C4FE710ModelTextureSwap
{
  public:
    virtual ~C4FE710ModelTextureSwap();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class C4FE710ScriptableForm
{
  public:
    virtual ~C4FE710ScriptableForm();
    int unk04;
    int unk08;
};

class C4FE710DestructibleObjectForm
{
  public:
    virtual ~C4FE710DestructibleObjectForm();
    int unk04;
};

class C4FE710SoundForm
{
  public:
    virtual ~C4FE710SoundForm();
};

class C4FE710Activator : public C4FE710BoundAnimObject,
                         public C4FE710FullName,
                         public C4FE710ModelTextureSwap,
                         public C4FE710ScriptableForm,
                         public C4FE710DestructibleObjectForm,
                         public C4FE710SoundForm
{
  public:
    virtual ~C4FE710Activator();

    void ClearData();
};

class FUN_004fe710 : public C4FE710Activator
{
  public:
    virtual ~FUN_004fe710();
};

// @fnv 0x004fe710
FUN_004fe710::~FUN_004fe710()
{
    ClearData();
}

class Actor : public TESObjectREFR
{
  public:
    virtual ~Actor();
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(void* a);
};
struct FUN_004280f0_shell
{
    bool FUN_004280f0();
};
struct FUN_00428110_shell
{
    FUN_004280f0_shell* FUN_00428110(unsigned int* a1, unsigned int a2);
};
TESForm* __cdecl LookupFormByID(unsigned int a);
struct FUN_004ff8a0_shell : public BGSTalkingActivator
{
    void FUN_004ff8a0(void* arg);
};
// Calls FUN_004534f0, then conditionally replaces m_pTempRef with an Actor cast of the form returned by LookupFormByID.
// @fnv 0x004ff8a0
void FUN_004ff8a0_shell::FUN_004ff8a0(void* arg)
{
    ((FUN_004534f0_shell*)this)->FUN_004534f0(arg);
    unsigned int local;
    if (((FUN_00428110_shell*)arg)->FUN_00428110(&local, 0x800000)->FUN_004280f0())
    {
        m_pTempRef =
            (TESObjectREFR*)(m_pTempRef != 0 ? dynamic_cast<Actor*>(LookupFormByID((unsigned int)m_pTempRef)) : 0);
    }
}

struct ActivatorComparison
{
    bool __thiscall FUN_005111e0(TESForm* form);
};

struct TalkingActivatorComparison : BGSTalkingActivator
{
    BGSVoiceType* __thiscall FUN_009185e0();
    bool __thiscall FUN_004fed50(TESForm* form);
};

BGSVoiceType* __thiscall TalkingActivatorComparison::FUN_009185e0()
{
    return m_kFactionList;
}

// Returns true if form is not a BGSTalkingActivator, FUN_005111e0 returns true, or the two FUN_009185e0 results differ.
// @fnv 0x004fed50
bool __thiscall TalkingActivatorComparison::FUN_004fed50(TESForm* form)
{
    BGSTalkingActivator* activator = dynamic_cast<BGSTalkingActivator*>(form);
    if (!activator)
        return true;
    if (reinterpret_cast<ActivatorComparison*>(this)->FUN_005111e0(form))
        return true;
    if (FUN_009185e0() != static_cast<TalkingActivatorComparison*>(activator)->FUN_009185e0())
        return true;
    return false;
}
