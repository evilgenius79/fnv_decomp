// fallout_shared/mediaset.cpp: MediaSet, MediaSetLoad, MediaSetBattle, MediaSetCopy and more (22 functions)

#include "mediaset_decls.h"

// @fnv 0x00598a70
void MediaSet::InitItem()
{
    unsigned int formID;
    if (GetInitialized())
        return;

    formID = 0;
    formID = reinterpret_cast<unsigned int>(m_pSound1);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSound1 = dynamic_cast<TESSound*>(TESFormInitFlag::GetFormByID(formID));
        if (!m_pSound1)
            Warning("MASTERFILE: Could not find open sound (%08X) for MediaSet '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    formID = reinterpret_cast<unsigned int>(m_pSound2);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSound2 = dynamic_cast<TESSound*>(TESFormInitFlag::GetFormByID(formID));
        if (!m_pSound2)
            Warning("MASTERFILE: Could not find open sound (%08X) for MediaSet '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    SetInitializationState(true);
}

// Calls FUN_00597850 on six members, then zeroes two members.
// @fnv 0x00599bd0
void MediaSet::ClearData()
{
    m_kMediaSetEntry1.FUN_00597850();
    m_kMediaSetEntry2.FUN_00597850();
    m_kMediaSetEntry3.FUN_00597850();
    m_kMediaSetEntry4.FUN_00597850();
    m_kMediaSetEntry5.FUN_00597850();
    m_kMediaSetEntry6.FUN_00597850();
    m_pSound1 = 0;
    m_pSound2 = 0;
}

// @fnv 0x00599b30
void MediaSet::ResetFormData()
{
    m_kMediaSetEntry1.FUN_00597850();
    m_kMediaSetEntry2.FUN_00597850();
    m_kMediaSetEntry3.FUN_00597850();
    m_kMediaSetEntry4.FUN_00597850();
    m_kMediaSetEntry5.FUN_00597850();
    m_kMediaSetEntry6.FUN_00597850();
    m_fMediaParameter1 = 0.0f;
    fSkillValueBonus = 0.0f;
    m_fMediaParameter3 = 0.0f;
    m_fMediaValue = 0.0f;
    m_pSound1 = 0;
    m_pSound2 = 0;
}

// @fnv 0x00597990
bool MediaSet::Update(unsigned int time, bool force, MediaLocationController* controller)
{
    if (controller)
    {
        switch (Type)
        {
        case LAYER_LOCATION:
            return UpdateLayerLocation(time, force, controller);
            break;
        case LAYER_DUNGEON:
            return PointLocation(time, force, controller);
            break;
        case BATTLE:
            return UpdateBattleState(force, time, 4);
        }
    }
    else if (!controller && Type == INCIDENTAL)
    {
        if (DAT_011ca9fc > time)
            return true;
        UpdateIncidental(time);
    }
    else if (!controller && Type == BATTLE)
    {
        return UpdateBattleState(force, time, 4);
    }
    return false;
}

// @fnv 0x00597610
MediaSet::MediaSet()
{
    SetFormType(ENUM_FORM_ID_MSET_ID);
    Type = static_cast<MEDIASETTYPE>(-1);
    m_kMediaSetEntry1.FUN_00597850();
    m_kMediaSetEntry2.FUN_00597850();
    m_kMediaSetEntry3.FUN_00597850();
    m_kMediaSetEntry4.FUN_00597850();
    m_kMediaSetEntry5.FUN_00597850();
    m_kMediaSetEntry6.FUN_00597850();
    m_fMediaParameter1 = 0.0f;
    fSkillValueBonus = 0.0f;
    m_fMediaParameter3 = 0.0f;
    m_fMediaValue = 0.0f;
    m_pSound1 = 0;
    m_pSound2 = 0;
    DAT_011ca9fc = 0;
    m_uiMediaValue3 = 0;
    m_uiMediaValue2 = 0;
    bEffectFlag = false;
    m_bActorStateFlag = false;
    m_bConditionWasTrue = false;
    m_cMediaState = 0;
}

// Selects an incidental media layer for the controller based on scale and layer percentages, then starts or stops playback and updates cached state.
// @fnv 0x00597a60
bool MediaSet::UpdateLayerLocation(unsigned int time, bool force, MediaLocationController* controller)
{
    bool bReturn;
    bool bPlaying = FalloutAudioMedia::IsMediaPlaying(MEDIA_INCIDENTAL, false);
    bReturn = true;
    char cLayer = 0;
    if (force)
    {
        return false;
    }
    else
    {
        bool a;  // Restart after the previous incidental reaches its fade window.
        unsigned int fMinPercent = FUN_00830970(MEDIA_INCIDENTAL);
        a = false;
        if (m_uiMediaValue3 && fMinPercent && time > m_uiMediaValue3 + fMinPercent - m_fMediaParameter3 * 1000.0)
        {
            FalloutAudioMedia::FadeOutMedia(static_cast<int>(m_fMediaParameter3 * 1000.0), MEDIA_INCIDENTAL);
            m_uiMediaValue3 = time;
            if (!controller->FUN_00598000())
                a = true;
            else
                return false;
        }
        float fNormalizedPosition = reinterpret_cast<TESObjectREFR*>(controller)->GetScale() * 100.0;
        float m_uiPlaybackFlags = 1000.0f;  // Lowest eligible layer percentage.
        if (controller->GetByteAtOffset55())
        {
            if ((m_cMediaFlag & 1) && m_kMediaSetEntry1.Percent > fNormalizedPosition &&
                m_kMediaSetEntry1.Percent < m_uiPlaybackFlags)
            {
                cLayer = 1;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry1.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry1.Percent;
            }
            if ((m_cMediaFlag & 2) && m_kMediaSetEntry2.Percent > fNormalizedPosition &&
                m_kMediaSetEntry2.Percent < m_uiPlaybackFlags)
            {
                cLayer = 2;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry2.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry2.Percent;
            }
            if ((m_cMediaFlag & 4) && m_kMediaSetEntry3.Percent > fNormalizedPosition &&
                m_kMediaSetEntry3.Percent < m_uiPlaybackFlags)
            {
                cLayer = 3;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry3.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry3.Percent;
            }
        }
        else
        {
            if ((m_cMediaFlag & 8) && m_kMediaSetEntry4.Percent > fNormalizedPosition &&
                m_kMediaSetEntry4.Percent < m_uiPlaybackFlags)
            {
                cLayer = 1;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry4.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry4.Percent;
            }
            if ((m_cMediaFlag & 16) && m_kMediaSetEntry5.Percent > fNormalizedPosition &&
                m_kMediaSetEntry5.Percent < m_uiPlaybackFlags)
            {
                cLayer = 2;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry5.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry5.Percent;
            }
            if ((m_cMediaFlag & 32) && m_kMediaSetEntry6.Percent > fNormalizedPosition &&
                m_kMediaSetEntry6.Percent < m_uiPlaybackFlags)
            {
                cLayer = 3;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry6.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry6.Percent;
            }
        }
        if (!(bPlaying && m_bActorStateFlag == force && m_bConditionWasTrue == controller->GetByteAtOffset55() &&
              m_cMediaState == cLayer) &&
                DAT_011dd37c < time ||
            a)
        {
            MediaSetEntry* pLayer = 0;
            if (controller->GetByteAtOffset55())
            {
                switch (cLayer)
                {
                case 1:
                    pLayer = &m_kMediaSetEntry1;
                    break;
                case 2:
                    pLayer = &m_kMediaSetEntry2;
                    break;
                case 3:
                    pLayer = &m_kMediaSetEntry3;
                }
            }
            else
            {
                switch (cLayer)
                {
                case 1:
                    pLayer = &m_kMediaSetEntry4;
                    break;
                case 2:
                    pLayer = &m_kMediaSetEntry5;
                    break;
                case 3:
                    pLayer = &m_kMediaSetEntry6;
                }
            }
            if (pLayer)
            {
                DAT_011dd37c = static_cast<unsigned int>(time + m_fMediaParameter1 * 1000.0);
                unsigned int uiElapsedMilliseconds = 0;
                if (FUN_00830a20(MEDIA_INCIDENTAL) && !a)
                    uiElapsedMilliseconds = time - FUN_00830a20(MEDIA_INCIDENTAL);
                FalloutAudioMedia::PlayMedia(
                    MEDIA_INCIDENTAL,
                    reinterpret_cast<const char*>(reinterpret_cast<const NiPointer<NiNode>*>(pLayer)->operator->()),
                    static_cast<unsigned int>(m_fMediaParameter3 * 1000.0), !controller->FUN_00598000(), true,
                    pLayer->Attenuation, uiElapsedMilliseconds);
                FalloutAudioMedia::EndMediaUpdate();
                m_uiMediaValue3 = time;
            }
            else
            {
                if (bPlaying)
                    FalloutAudioMedia::FadeOutMedia(static_cast<int>(m_fMediaParameter3 * 1000.0), MEDIA_INCIDENTAL);
                bReturn = false;
            }
            m_bActorStateFlag = force;
            m_bConditionWasTrue = controller->GetByteAtOffset55();
            m_cMediaState = cLayer;
        }
    }
    return bReturn;
}

extern float const runtimeFloatSettingDefault313;

struct FUN_00597850_Class
{
    BSStringT<char> m_str;
    float m_f08;
    float m_f0c;
};

// Clears the string, then sets m_f08 to runtimeFloatSettingDefault313 and m_f0c to 100.0f.
// @fnv 0x00597850
void __fastcall FUN_00597850(FUN_00597850_Class* pThis)
{
    pThis->m_str.Set(0, 0);
    pThis->m_f08 = runtimeFloatSettingDefault313;
    pThis->m_f0c = 100.0f;
}

// @fnv 0x007d9ec0
void __fastcall FUN_007d9ec0(BSStringT<char>* apString)
{
    apString->BSStringT<char>::~BSStringT<char>();
}

extern "C" void* __cdecl _alloca(unsigned int);

struct BSStringTChar
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringTChar(const char* apText);
    ~BSStringTChar();
    BSStringTChar& operator+=(const char* apText);
    bool Set(const BSStringTChar& arString);
};

struct TESFormLoadDataHelper
{
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);
};

struct MediaSetLoad : public MediaSet
{
    bool FUN_00598bc0(TESFile* apFile);
};

// Reads a MediaSet record from the file, handling EDID, OBND, FULL, type, name, attenuation, percent, sound and float chunks, then returns true.
// @fnv 0x00598bc0
bool MediaSetLoad::FUN_00598bc0(TESFile* apFile)
{
    unsigned int itempint = 0;
    int chunkid;

    LoadRecordHeader(apFile);
    SetInitializationState(false);

    while ((chunkid = (int)apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 'DIDE': {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(apFile);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this, apFile);
            break;
        case '1MAN':
            apFile->GetChunkData(&itempint);
            Type = (MEDIASETTYPE)itempint;
            break;
        case '2MAN':
        case '3MAN':
        case '4MAN':
        case '5MAN':
        case '6MAN':
        case '7MAN': {
            char* pMessage = 0;
            float tF = 0.0f;
            unsigned int cSize = apFile->GetChunkSize();
            if (cSize)
            {
                pMessage = (char*)_alloca(apFile->GetChunkSize());
                apFile->GetChunkData(pMessage, 0);
                BSStringTChar stemp("Data\\Music\\");
                stemp += pMessage;
                switch (chunkid)
                {
                case '2MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry1.Name)->Set(stemp);
                    break;
                case '3MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry2.Name)->Set(stemp);
                    break;
                case '4MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry3.Name)->Set(stemp);
                    break;
                case '5MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry4.Name)->Set(stemp);
                    break;
                case '6MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry5.Name)->Set(stemp);
                    break;
                case '7MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry6.Name)->Set(stemp);
                    break;
                }
            }
            break;
        }
        case '8MAN':
        case '9MAN':
        case '0MAN':
        case 'MANA':
        case 'MANB':
        case 'MANC': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case '8MAN':
                m_kMediaSetEntry1.Attenuation = tF;
                break;
            case '9MAN':
                m_kMediaSetEntry2.Attenuation = tF;
                break;
            case '0MAN':
                m_kMediaSetEntry3.Attenuation = tF;
                break;
            case 'MANA':
                m_kMediaSetEntry4.Attenuation = tF;
                break;
            case 'MANB':
                m_kMediaSetEntry5.Attenuation = tF;
                break;
            case 'MANC':
                m_kMediaSetEntry6.Attenuation = tF;
                break;
            }
            break;
        }
        case 'MANJ':
        case 'MANK':
        case 'MANL':
        case 'MANM':
        case 'MANN':
        case 'MANO': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case 'MANJ':
                m_kMediaSetEntry1.Percent = tF;
                break;
            case 'MANK':
                m_kMediaSetEntry2.Percent = tF;
                break;
            case 'MANL':
                m_kMediaSetEntry3.Percent = tF;
                break;
            case 'MANM':
                m_kMediaSetEntry4.Percent = tF;
                break;
            case 'MANN':
                m_kMediaSetEntry5.Percent = tF;
                break;
            case 'MANO':
                m_kMediaSetEntry6.Percent = tF;
                break;
            }
            break;
        }
        case 'MANP':
            ((TESFormLoadDataHelper*)this)->ReadTypedData(apFile, &m_cMediaFlag, 1);
            break;
        case 'MAND':
        case 'MANE':
        case 'MANF':
        case 'MANG': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case 'MAND':
                m_fMediaParameter1 = tF;
                break;
            case 'MANE':
                fSkillValueBonus = tF;
                break;
            case 'MANF':
                m_fMediaParameter3 = tF;
                break;
            case 'MANG':
                m_fMediaValue = tF;
                break;
            }
            break;
        }
        case 'MANH':
        case 'MANI': {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            switch (chunkid)
            {
            case 'MANH':
                m_pSound1 = (TESSound*)itempint;
                break;
            case 'MANI':
                m_pSound2 = (TESSound*)itempint;
                break;
            }
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

struct FUN_00598000_shell
{
    int __thiscall FUN_00598000();
};

// @fnv 0x00598000
int __thiscall FUN_00598000_shell::FUN_00598000()
{
    return (*(int*)((char*)this + 0x6c) >> 4) & 3;
}

struct FUN_00597880_shell
{
    void FUN_005978b0();
    void* FUN_00597880(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_005978b0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00597880
void* FUN_00597880_shell::FUN_00597880(unsigned int flags)
{
    this->FUN_005978b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct UnnamedStr
{
    int _00;
    int _04;
    void __thiscall AssignFromString(const UnnamedStr&);
};
struct FUN_00599780
{
    UnnamedStr _00;
    float _08;
    float _0c;
    FUN_00599780(const FUN_00599780&);
};
// Copy-constructs from that: copies the embedded UnnamedStr via AssignFromString and copies the two floats _08 and _0c.
// @fnv 0x00599780
FUN_00599780::FUN_00599780(const FUN_00599780& that)
{
    _00.AssignFromString(that._00);
    _08 = that._08;
    _0c = that._0c;
}

struct GO
{
    operator unsigned int() const;
};

struct S7010 : GO
{
    unsigned int Length();
};

struct DoorPart30
{
    void FUN_00487010();
};

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct FUN_00485e00_shell
{
    void FUN_00485e00();
};

struct FUN_005991b0_shell
{
    void FUN_005991b0();
};

void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl _FUN_00485910(unsigned int, unsigned int);
void __cdecl _FUN_00485910(unsigned int, float);

// @fnv 0x005991b0
void FUN_005991b0_shell::FUN_005991b0()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x18)->FUN_00487010();

    _FUN_00485910(0x314d414e, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x44));

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)->Length() > 0)
    {
        FUN_004856f0(0x324d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)->Length() > 0)
    {
        FUN_004856f0(0x334d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)->Length() > 0)
    {
        FUN_004856f0(0x344d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)->Length() > 0)
    {
        FUN_004856f0(0x354d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)->Length() > 0)
    {
        FUN_004856f0(0x364d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)->Length() > 0)
    {
        FUN_004856f0(0x374d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)->Length() + 1);
    }

    _FUN_00485910(0x384d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x50));
    _FUN_00485910(0x394d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x60));
    _FUN_00485910(0x304d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x70));
    _FUN_00485910(0x4d414e41, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x80));
    _FUN_00485910(0x4d414e42, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x90));
    _FUN_00485910(0x4d414e43, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xa0));
    _FUN_00485910(0x4d414e4a, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x54));
    _FUN_00485910(0x4d414e4b, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64));
    _FUN_00485910(0x4d414e4c, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x74));
    _FUN_00485910(0x4d414e4d, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x84));
    _FUN_00485910(0x4d414e4e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94));
    _FUN_00485910(0x4d414e4f, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xa4));

    FUN_004858f0(0x4d414e50, *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xa8));

    _FUN_00485910(0x4d414e44, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xac));
    _FUN_00485910(0x4d414e45, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb0));
    _FUN_00485910(0x4d414e46, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb4));
    _FUN_00485910(0x4d414e47, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb8));

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xbc))
    {
        _FUN_00485910(0x4d414e48,
                      reinterpret_cast<TESSound*>(*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xbc))
                          ->GetFormID());
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xc0))
    {
        _FUN_00485910(0x4d414e49,
                      reinterpret_cast<TESSound*>(*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xc0))
                          ->GetFormID());
    }

    reinterpret_cast<FUN_00485e00_shell*>(this)->FUN_00485e00();
    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct S_5978b0_Form
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    virtual ~S_5978b0_Form();
};

struct FUN_005978b0 : public S_5978b0_Form, public TESFullName
{
    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    int Type;
    MediaSet::MediaSetEntry m_kMediaSetEntry1;
    MediaSet::MediaSetEntry m_kMediaSetEntry2;
    MediaSet::MediaSetEntry m_kMediaSetEntry3;
    MediaSet::MediaSetEntry m_kMediaSetEntry4;
    MediaSet::MediaSetEntry m_kMediaSetEntry5;
    MediaSet::MediaSetEntry m_kMediaSetEntry6;
    ~FUN_005978b0();
};

// @fnv 0x005978b0
FUN_005978b0::~FUN_005978b0()
{}

class Sky
{
  public:
    float GetFieldEC();
};
float __fastcall FUN_00595ea0(void* apSky);
float __fastcall FUN_00596030(void* apSky);

class TES
{
  public:
    Sky* GetSky();
};
extern TES* g_TES;

struct SoundPlaybackHandle
{
    unsigned int uiSoundID;
    unsigned int unk04;
    unsigned int unk08;
    ~SoundPlaybackHandle();
    bool Play();
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int auiFormID, unsigned int auiFlags, unsigned int auiUnk);
};

unsigned int GetRandomNumberInRange(int aiMin, int aiMax);

struct MediaSetBattle : public MediaSet
{
    bool UpdateBattleMusic(unsigned int auiTime);
};

// @fnv 0x00598890
bool MediaSetBattle::UpdateBattleMusic(unsigned int auiTime)
{
    if (auiTime <= DAT_011ca9fc)
    {
        return true;
    }
    Sky* pWeatherSky = g_TES->GetSky();
    bool m_bConditionWasTrue = pWeatherSky ? (FUN_00595ea0(pWeatherSky) <= pWeatherSky->GetFieldEC() &&
                                              pWeatherSky->GetFieldEC() <= FUN_00596030(pWeatherSky))
                                           : true;
    if (m_bConditionWasTrue)
    {
        BSAudio::GetSingleton()->GetSoundHandleByFormID(m_pSound1->GetFormID(), 0x901, 0).Play();
        DAT_011ca9fc =
            GetRandomNumberInRange((int)(m_fMediaParameter1 * 1000.0), (int)(m_fMediaParameter3 * 1000.0)) + auiTime;
    }
    else
    {
        BSAudio::GetSingleton()->GetSoundHandleByFormID(m_pSound2->GetFormID(), 0x901, 0).Play();
        DAT_011ca9fc =
            GetRandomNumberInRange((int)(fSkillValueBonus * 1000.0), (int)(m_fMediaValue * 1000.0)) + auiTime;
    }
    return true;
}

struct MediaLayerData
{
    BSStringT<char> Name;
    float Attenuation;
    float Percent;
    MediaLayerData(const MediaLayerData& arOther);
    ~MediaLayerData();
    void SetLayer(MediaLayerData arLayer);
};

struct MediaSetBaseCopy
{
    void CopyBase(TESForm* apForm);
};

struct MediaSetCopy : public MediaSet
{
    void FUN_00599550(TESForm* apForm);
};

// Copies Type, six layer entries and several scalar fields from another MediaSet, then calls CopyBase.
// @fnv 0x00599550
void MediaSetCopy::FUN_00599550(TESForm* apForm)
{
    MediaSet* pOther = dynamic_cast<MediaSet*>(apForm);
    if (!pOther)
        return;
    Type = pOther->Type;
    ((MediaLayerData*)&m_kMediaSetEntry1)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry1);
    ((MediaLayerData*)&m_kMediaSetEntry2)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry2);
    ((MediaLayerData*)&m_kMediaSetEntry3)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry3);
    ((MediaLayerData*)&m_kMediaSetEntry4)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry4);
    ((MediaLayerData*)&m_kMediaSetEntry5)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry5);
    ((MediaLayerData*)&m_kMediaSetEntry6)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry6);
    m_cMediaFlag = pOther->m_cMediaFlag;
    m_fMediaParameter1 = pOther->m_fMediaParameter1;
    fSkillValueBonus = pOther->fSkillValueBonus;
    m_fMediaParameter3 = pOther->m_fMediaParameter3;
    m_fMediaValue = pOther->m_fMediaValue;
    m_pSound1 = pOther->m_pSound1;
    m_pSound2 = pOther->m_pSound2;
    ((MediaSetBaseCopy*)this)->CopyBase(pOther);
}

struct TextValue
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    TextValue* FUN_00559450(int flag);
    ~TextValue();
};
struct StringRecord
{
    TextValue name;
    float first;
    float second;
    void FUN_004037f0(TextValue*);
    void SetValues(TextValue value, float firstValue, float secondValue);
};
// @fnv 0x00599700
void StringRecord::SetValues(TextValue aTextValue, float afFirst, float afSecond)
{
    FUN_004037f0(aTextValue.FUN_00559450(0));
    first = afFirst;
    second = afSecond;
}

struct LayerInfo
{
    BSStringT<char> Name;
    float Attenuation;
    float Percent;

    const char* __thiscall FUN_00559450(unsigned int index);
    int __thiscall FUN_00408a80(const char* text);
    bool __thiscall FUN_00599a50(LayerInfo other);
};
// @fnv 0x00599a50
bool LayerInfo::FUN_00599a50(LayerInfo other)
{
    if (Attenuation != other.Attenuation)
        return true;
    if (Percent != other.Percent)
        return true;
    if (FUN_00408a80(other.FUN_00559450(0)))
        return false;
    return true;
}

struct FUN_00483630_holder
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    virtual ~FUN_00483630_holder();
};

struct FUN_00599d00 : public FUN_00483630_holder, public TESFullName
{
    virtual ~FUN_00599d00();
};

// Destructor for a TESFullName-derived holder object; the body is empty.
// @fnv 0x00599d00
FUN_00599d00::~FUN_00599d00()
{}

struct Ctrl598060
{
    int FUN_00598000();
    bool FUN_0071aa80();
    float FUN_00598040();
};
struct SoundForm598060
{
    unsigned int FUN_0084e3a0();
};
struct BSSoundHandleEx
{
    int v0;
    int v1;
    int v2;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct BSAudio598060
{
    BSSoundHandleEx FUN_00ad73b0(int, int);
};
BSAudio598060* __cdecl FUN_00453a70();
bool __cdecl FUN_00830750(unsigned long, bool);
unsigned int __cdecl FUN_008308c0(unsigned long);
void __cdecl StartFade(int, int);
void __cdecl PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
void __cdecl FUN_008304c0();
extern unsigned int DAT_011ca9fc;

struct This598060
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
    int m_2c;
    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char unk33;
    char m_34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    FUN_00597850_Class m_48;
    FUN_00597850_Class m_58;
    FUN_00597850_Class m_68;
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
    float m_ac;
    int unkb0;
    float m_b4;
    int unkb8;
    SoundForm598060* m_bc;
    SoundForm598060* m_c0;
    bool UpdateSoundState(unsigned int, bool, Ctrl598060*);
};

// @fnv 0x00598060
bool This598060::UpdateSoundState(unsigned int auiTime, bool abEnabled, Ctrl598060* apCtrl)
{
    bool flagDTmp;
    bool retVal;
    unsigned int local7;
    bool b2;
    bool b4;
    FUN_00597850_Class* ptrLocal;
    int local4;
    b2 = FUN_00830750(3, true);
    retVal = true;
    b4 = apCtrl->FUN_00598040() < 100.0;
    if (this->m_31 == 0 && abEnabled)
    {
        DAT_011dd37c = 0;
    }
    local7 = FUN_008308c0(2);
    flagDTmp = false;
    if (this->m_2c != 0 && local7 != 0)
    {
        if ((double)auiTime > (double)(unsigned int)(this->m_2c + local7) - this->m_b4 * 1000.0)
        {
            StartFade((int)(this->m_b4 * 1000.0), 2);
            this->m_2c = auiTime;
            if (apCtrl->FUN_00598000() == 0)
            {
                flagDTmp = true;
            }
            else
            {
                return false;
            }
        }
    }
    if (!((b2 && this->m_31 == abEnabled && this->m_32 == apCtrl->FUN_0071aa80() &&
           ((char)this->m_34 == (char)b4 || (char)this->m_34 != 0)) ||
          DAT_011dd37c >= auiTime) ||
        flagDTmp)
    {
    body:
        ptrLocal = 0;
        if (abEnabled)
        {
            if (this->m_bc != 0 && !this->m_30)
            {
                FUN_00453a70()->FUN_00ad73b0((int)this->m_bc->FUN_0084e3a0(), 0x901).Play(false);
            }
            ptrLocal = &this->m_48;
            this->m_30 = 1;
        }
        else if (apCtrl->FUN_0071aa80())
        {
            if (this->m_30 && this->m_c0 != 0)
            {
                FUN_00453a70()->FUN_00ad73b0((int)this->m_c0->FUN_0084e3a0(), 0x901).Play(false);
            }
            ptrLocal = &this->m_68;
            this->m_30 = 0;
        }
        else
        {
            if (this->m_30 && this->m_c0 != 0)
            {
                FUN_00453a70()->FUN_00ad73b0((int)this->m_c0->FUN_0084e3a0(), 0x901).Play(false);
            }
            ptrLocal = &this->m_58;
            this->m_30 = 0;
        }
        if (ptrLocal != 0)
        {
            DAT_011dd37c = auiTime;
            if (!abEnabled)
            {
                DAT_011dd37c = (unsigned int)(this->m_ac * 1000.0 + (double)DAT_011dd37c);
            }
            local4 = 0;
            if (FUN_00830a20((MEDIATYPE)3) != 0 && !flagDTmp)
            {
                local4 = auiTime - FUN_00830a20((MEDIATYPE)3);
            }
            if (ptrLocal == &this->m_48)
            {
                PlayAudioMedia(3, ptrLocal->m_str.String(), 1000, true, true, ptrLocal->m_f08, (unsigned int)local4);
            }
            else
            {
                PlayAudioMedia(3, ptrLocal->m_str.String(), (unsigned int)(this->m_b4 * 1000.0), true, true,
                               ptrLocal->m_f08, (unsigned int)local4);
            }
            FUN_008304c0();
        }
        else
        {
            StartFade((int)(this->m_b4 * 1000.0), 3);
            retVal = false;
        }
        this->m_31 = abEnabled;
        this->m_32 = apCtrl->FUN_0071aa80();
        this->m_34 = b4;
    }
    else
    {
        if ((char)b4 == 0)
        {
            if (auiTime > DAT_011ca9fc)
            {
                if (this->m_30 == 0)
                {
                    if (b2)
                    {
                        StartFade((int)(this->m_b4 * 1000.0), 3);
                    }
                    retVal = false;
                }
            }
        }
    }
    return retVal;
}

namespace fnv_00598550 {
struct BSSoundHandleEx
{
    unsigned int uiSoundID;
    unsigned int uiState;
    unsigned int uiFlags;
    ~BSSoundHandleEx();
    bool Play();
};
struct DungeonAudio
{
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int, unsigned int);
};
struct DungeonController
{
    void FUN_007037c0(unsigned int);
};
extern DungeonController* DAT_011dd374;
bool FUN_00830750(unsigned long, bool);
unsigned int FUN_008308c0(unsigned long);
void FUN_008305e0();
void ResetThreadFlags();
void StartFade(int, int);
struct DungeonMediaSet : MediaSet
{
    bool UpdatePlayback(bool active, unsigned int time, int mediaType);
};
// Starts, refreshes or fades the media set's audio based on active, time and mediaType, updating DAT_011ca9fc and the playing flag.
// @fnv 0x00598550
bool DungeonMediaSet::UpdatePlayback(bool active, unsigned int time, int mediaType)
{
    bool changed;
    if (active)
    {
        changed = false;
        bool playing = FUN_00830750(mediaType, false);
        if (!playing && !bEffectFlag)
        {
            if (m_pSound1 && !bEffectFlag)
                ((DungeonAudio*)BSAudio::GetSingleton())->FUN_00ad73b0(m_pSound1->GetFormID(), 0x901, 0).Play();
            DAT_011ca9fc = time - 1;
            bEffectFlag = true;
            FalloutAudioMedia::PlayMedia((MEDIATYPE)mediaType, m_kMediaSetEntry1.Name.String(),
                                         (unsigned int)(fSkillValueBonus * 1000.0), true, true,
                                         m_kMediaSetEntry1.Attenuation, 0);
            FalloutAudioMedia::EndMediaUpdate();
            FUN_008305e0();
        }
        if (time > DAT_011ca9fc + m_fMediaParameter1)
        {
            ResetThreadFlags();
            bEffectFlag = true;
        }
        unsigned int length = FUN_008308c0(mediaType);
        if (length && time > DAT_011ca9fc + length - 1000)
        {
            FalloutAudioMedia::PlayMedia((MEDIATYPE)mediaType, m_kMediaSetEntry1.Name.String(),
                                         (unsigned int)(fSkillValueBonus * 1000.0), true, true,
                                         m_kMediaSetEntry1.Attenuation, 0);
            FalloutAudioMedia::EndMediaUpdate();
            DAT_011ca9fc = time;
        }
    }
    else
    {
        bool fading = false;
        if (FUN_00830750(mediaType, false) && bEffectFlag)
        {
            fading = true;
            StartFade((int)(fSkillValueBonus * 1000.0), mediaType);
        }
        if (fading)
        {
            if (m_pSound2)
                ((DungeonAudio*)BSAudio::GetSingleton())->FUN_00ad73b0(m_pSound2->GetFormID(), 0x901, 0).Play();
            DAT_011ca9fc = time + m_fMediaParameter3 * 1000.0;
            if (DAT_011dd374)
                DAT_011dd374->FUN_007037c0(DAT_011ca9fc);
            bEffectFlag = false;
        }
    }
    return active;
}
}  // namespace fnv_00598550

struct MediaLayerCompare
{
    bool FUN_00599a50(MediaLayerData other);
};
struct MediaFormCompare
{
    bool FUN_00485270(TESForm* other);
};
struct MediaSetCompare : MediaSet
{
    bool IsDifferentFrom(TESForm* form);
};

// Compares this MediaSet with form cast to MediaSet: returns true if any layer, scalar field or base comparison differs.
// @fnv 0x005997c0
bool MediaSetCompare::IsDifferentFrom(TESForm* form)
{
    MediaSet* other = dynamic_cast<MediaSet*>(form);
    if (!other)
        return true;
    if (other->Type != Type)
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry1)
            ->FUN_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry1)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry2)
            ->FUN_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry2)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry3)
            ->FUN_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry3)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry4)
            ->FUN_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry4)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry5)
            ->FUN_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry5)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry6)
            ->FUN_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry6)))
        return true;
    if (m_cMediaFlag != other->m_cMediaFlag)
        return true;
    if (m_fMediaParameter1 != other->m_fMediaParameter1)
        return true;
    if (fSkillValueBonus != other->fSkillValueBonus)
        return true;
    if (m_fMediaParameter3 != other->m_fMediaParameter3)
        return true;
    if (m_fMediaValue != other->m_fMediaValue)
        return true;
    if (m_pSound1 != other->m_pSound1)
        return true;
    if (m_pSound2 != other->m_pSound2)
        return true;
    if (reinterpret_cast<MediaFormCompare*>(this)->FUN_00485270(other))
        return true;
    return false;
}
