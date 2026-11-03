// fallout/audio/falloutaudiomedia.cpp: FalloutAudioMedia, FAMThread (30 functions)

#include "falloutaudiomedia_decls.h"

// @fnv 0x008304a0
void FalloutAudioMedia::BeginMediaUpdate()
{
    GetCurrentThreadId();
    StartMenu::UpdateMedia();
    FUN_00830490();
}

// @fnv 0x008304c0
void FalloutAudioMedia::EndMediaUpdate()
{
    GetCurrentThreadId();
    DAT_011dd310 &= ~2;
    DAT_011dd311 &= ~2;
    FUN_00830490();
}

// @fnv 0x00830010
void FalloutAudioMedia::PlayMedia(BGSMusicType* musicType)
{
    if (musicType)
        PlayMedia(kMediaType_Music, musicType->GetRandomEntry(), 1000, musicType->FUN_00830050(), false,
                  musicType->FUN_00830080(), 0);
}

// @fnv 0x00830680
void FalloutAudioMedia::FadeOutMedia(int fadeTime, MEDIATYPE mediaType)
{
    GetCurrentThreadId();
    unsigned int currentTime = ((FORenderedMenu*)TESLandTexture::GetSoundSystem())->GetCurrentTimeMilliseconds();
    if (DAT_011dd314 == mediaType || mediaType == 0)
    {
        if ((DAT_011dd310 & 8) == 0)
        {
            DAT_011dd310 |= 0x18;
            DAT_011dd304 = DAT_011dd300;
            DAT_011dd308 = 0.0f;
            DAT_011dd328 = fadeTime;
            DAT_011dd32c = currentTime + DAT_011dd328;
        }
    }
    if (DAT_011dd348 == mediaType || mediaType == 0)
    {
        if ((DAT_011dd311 & 8) == 0)
        {
            DAT_011dd311 |= 0x18;
            DAT_011dd33c = DAT_011dd338;
            DAT_011dd340 = 0.0f;
            DAT_011dd35c = fadeTime;
            DAT_011dd360 = currentTime + DAT_011dd35c;
        }
    }
    FUN_00830490();
}

namespace fnv_anon_falloutaudiomedia {}
using namespace fnv_anon_falloutaudiomedia;
namespace fnv_anon_falloutaudiomedia {
// @fnv 0x0082f7b0
unsigned int FAMThread::ThreadProc()
{
    state |= 2;
    while (state & 1)
    {
        WaitForThread();
        EnsureArenaAllocated(&event);
        if (state & 1)
            RunAudioChannel(&threadID);
    }
    state &= ~2;
    FUN_00c80240(&event);
    return 0;
}
}

// Checks whether either radio state is active or a flag is set, stores the result in state.result, calls FUN_00830490 and returns it.
// @fnv 0x00830ad0
char FalloutAudioMedia::IsRadioPlaying()
{
    struct RadioState
    {
        int isRadio;
        char padding0;
        char padding1;
        char padding2;
        char result;
    } state;

    GetCurrentThreadId();
    if (!((DAT_011dd334 != 0 && DAT_011dd314 == 7) || (DAT_011dd368 != 0 && DAT_011dd348 == 7) || DAT_011dd313 != 0))
        state.isRadio = 0;
    else
        state.isRadio = 1;
    state.result = (char)state.isRadio;
    FUN_00830490();
    return state.result;
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);

namespace fnv_anon_falloutaudiomedia {}
using namespace fnv_anon_falloutaudiomedia;
namespace fnv_anon_falloutaudiomedia {
// @fnv 0x0082f790
void FAMThread::WaitForThread()
{
    WaitForSingleObject(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30), 0xFFFFFFFF);
}
}

// @fnv 0x0082f7b0
unsigned int __fastcall FUN_0082f7b0(FAMThread* pThis)
{
    pThis->state |= 2;
    while (pThis->state & 1)
    {
        pThis->WaitForThread();
        EnsureArenaAllocated(&pThis->event);
        if (pThis->state & 1)
            RunAudioChannel(&pThis->threadID);
    }
    pThis->state &= ~2;
    FUN_00c80240(&pThis->event);
    return 0;
}

struct SETTING_VALUE
{
    float f;
};

class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};

class BSAudio
{
  public:
    float GetMusicVolume();
    float FUN_00ad7ab0();
    float GetMasterVolume();
};

extern SettingT_GameSettingCollection_ g_011dd084;
extern double DAT_01073490;
extern double g_d100;
extern float DAT_0107cc20;
extern double _gModifierZero;
extern double DAT_01032980;
extern float const g_011c5aa8_arg1;

float __cdecl FUN_0082ffd0(float);
float __cdecl FUN_004dd130(float, float);

// Computes a volume from the media type's setting or BSAudio value, applies attenuation and dB clamping, then scales by the BSAudio factor and clamps the result.
// @fnv 0x0082fec0
float __cdecl ComputeAttenuatedVolume(int aeMediaType, float attenuation)
{
    float vol = 0.0f;
    float fVolumeDb;

    if (aeMediaType == 8)
    {
        vol = g_011dd084.Float()->f;
    }
    else if (aeMediaType == 7)
    {
        vol = ((BSAudio*)TESLandTexture::GetSoundSystem())->GetMusicVolume();
    }
    else
    {
        vol = ((BSAudio*)TESLandTexture::GetSoundSystem())->FUN_00ad7ab0();
    }

    fVolumeDb = (float)(FUN_0082ffd0(vol) * DAT_01073490 + attenuation * g_d100);
    if (fVolumeDb < -10000.0)
        fVolumeDb = DAT_0107cc20;
    else if (fVolumeDb > _gModifierZero)
        fVolumeDb = 0.0f;

    vol = FUN_004dd130(10.0f, (float)(fVolumeDb / DAT_01073490));
    vol = ((BSAudio*)TESLandTexture::GetSoundSystem())->GetMasterVolume() * vol;

    if (vol < DAT_01032980)
        vol = g_011c5aa8_arg1;
    else if (vol > g_d100)
        vol = 100.0f;

    return vol;
}

float __cdecl FUN_0082fff0(float);

// @fnv 0x0082ffd0
float FUN_0082ffd0(float _X)
{
    return FUN_0082fff0(_X);
}

double __cdecl FUN_00ecbc80(double);

// @fnv 0x0082fff0
float __cdecl FUN_0082fff0(float value)
{
    return static_cast<float>(FUN_00ecbc80(value));
}

// If aiMusicType is non-null, plays it as music media using its random entry, FUN_00830050 and FUN_00830080 values.
// @fnv 0x00830010
void __cdecl PlayMusicType(BGSMusicType* aiMusicType)
{
    if (aiMusicType)
        FalloutAudioMedia::PlayMedia(kMediaType_Music, aiMusicType->GetRandomEntry(), 1000, aiMusicType->FUN_00830050(),
                                     false, aiMusicType->FUN_00830080(), 0);
}

struct FUN_00830050_shell : public BGSMusicType
{
    bool FUN_00830050();
};

// Returns true if the float at offset 0x24 is greater than zero.
// @fnv 0x00830050
bool FUN_00830050_shell::FUN_00830050()
{
    return *(float*)((char*)this + 0x24) > 0.0f ? true : false;
}

struct FUN_00830080_shell : public BGSMusicType
{
    float FUN_00830080();
};

// Returns the float at offset 0x24 negated when it is greater than zero, otherwise returns it unchanged.
// @fnv 0x00830080
float FUN_00830080_shell::FUN_00830080()
{
    return (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x24) > 0.0)
               ? -*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x24)
               : *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x24);
}

class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
};

extern ActorTaskManager g_011dd3d8;

// @fnv 0x00830470
void FUN_00830470()
{
    g_011dd3d8.QueryPerformanceCounter(0);
}

extern char DAT_011dd312;

// @fnv 0x00830660
void FUN_00830660()
{
    GetCurrentThreadId();
    DAT_011dd312 = 0;
    FUN_00830490();
}

// @fnv 0x00830680
void __cdecl StartFade(int aiFadeTime, int aeType)
{
    GetCurrentThreadId();
    unsigned int ticks =
        reinterpret_cast<FORenderedMenu*>(TESLandTexture::GetSoundSystem())->GetCurrentTimeMilliseconds();
    if ((DAT_011dd314 == aeType || aeType == 0) && !(DAT_011dd310 & 8))
    {
        DAT_011dd310 |= 0x18;
        DAT_011dd304 = DAT_011dd300;
        DAT_011dd308 = 0.0f;
        DAT_011dd328 = aiFadeTime;
        DAT_011dd32c = ticks + DAT_011dd328;
    }
    if ((DAT_011dd348 == aeType || aeType == 0) && !(DAT_011dd311 & 8))
    {
        DAT_011dd311 |= 0x18;
        DAT_011dd33c = DAT_011dd338;
        DAT_011dd340 = 0.0f;
        DAT_011dd35c = aiFadeTime;
        DAT_011dd360 = ticks + DAT_011dd35c;
    }
    FUN_00830490();
}

// @fnv 0x00830750
bool __cdecl FUN_00830750(unsigned long aeType, bool abIncludeFading)
{
    GetCurrentThreadId();
    bool ret = false;
    if (abIncludeFading)
    {
        if (aeType == 0)
        {
            ret = (DAT_011dd334 != 0 && (DAT_011dd310 & 2) == 0) || (DAT_011dd368 != 0 && (DAT_011dd311 & 2) == 0);
        }
        else
        {
            ret = (DAT_011dd334 != 0 && DAT_011dd314 == aeType && (DAT_011dd310 & 2) == 0) ||
                  (DAT_011dd368 != 0 && DAT_011dd348 == aeType && (DAT_011dd311 & 2) == 0);
        }
    }
    else
    {
        if (aeType == 0)
        {
            ret = (DAT_011dd334 != 0 && (DAT_011dd310 & 8) == 0) || (DAT_011dd368 != 0 && (DAT_011dd311 & 8) == 0);
        }
        else
        {
            ret = (DAT_011dd334 != 0 && DAT_011dd314 == aeType && (DAT_011dd310 & 8) == 0) ||
                  (DAT_011dd368 != 0 && DAT_011dd348 == aeType && (DAT_011dd311 & 8) == 0);
        }
    }
    FUN_00830490();
    return ret;
}

extern int DAT_011dd324;
extern int DAT_011dd358;
extern int DAT_011dd36c;

// @fnv 0x00830970
int __cdecl FUN_00830970(int auiThreadId)
{
    GetCurrentThreadId();
    int result = 0;
    if (auiThreadId == 0)
    {
        if (DAT_011dd36c == 1 && DAT_011dd334 != 0)
            result = DAT_011dd324;
        else if (DAT_011dd36c == 0 && DAT_011dd368 != 0)
            result = DAT_011dd358;
    }
    if (DAT_011dd36c == 1 && DAT_011dd334 != 0 && DAT_011dd314 == (unsigned long)auiThreadId)
        result = DAT_011dd324;
    else if (DAT_011dd36c == 0 && DAT_011dd368 != 0 && DAT_011dd348 == (unsigned long)auiThreadId)
        result = DAT_011dd358;
    FUN_00830490();
    return result;
}

namespace fnv_00830a20 {
extern unsigned long DAT_011dd31c;
extern unsigned long DAT_011dd350;
extern unsigned long DAT_011dd36c;

// @fnv 0x00830a20
unsigned long __cdecl FUN_00830a20(unsigned long param_1)
{
    GetCurrentThreadId();
    unsigned long result = 0;
    if (param_1 == 0)
    {
        if (DAT_011dd36c == 1 && DAT_011dd334 != 0)
        {
            result = DAT_011dd31c;
        }
        else if (DAT_011dd36c == 0 && DAT_011dd368 != 0)
        {
            result = DAT_011dd350;
        }
    }
    if (DAT_011dd36c == 1 && DAT_011dd334 != 0 && DAT_011dd314 == param_1)
    {
        result = DAT_011dd31c;
    }
    else if (DAT_011dd36c == 0 && DAT_011dd368 != 0 && DAT_011dd348 == param_1)
    {
        result = DAT_011dd350;
    }
    FUN_00830490();
    return result;
}
}  // namespace fnv_00830a20

namespace fnv_00830490 {
struct ATM
{
    void __thiscall WaitForTasksDuringRendering();
};

extern ATM g_011dd3d8;

// @fnv 0x00830490
void __cdecl FUN_00830490()
{
    g_011dd3d8.WaitForTasksDuringRendering();
}
}  // namespace fnv_00830490

float __cdecl ComputeAttenuatedVolume(int, float);
extern float DAT_011dd30c;
extern int DAT_011dd318;
extern float DAT_011dd344;
extern int DAT_011dd34c;
extern int DAT_011dd350;
extern int DAT_011dd36c;
extern unsigned long DAT_011dd31c;

// @fnv 0x008304f0
void FUN_008304f0()
{
    GetCurrentThreadId();
    if (DAT_011dd36c == 0)
    {
        DAT_011dd311 |= 2;
        DAT_011dd338 = ComputeAttenuatedVolume(DAT_011dd348, DAT_011dd344);
        DAT_011dd34c = 0;
        DAT_011dd35c = 0;
        DAT_011dd360 = 0;
        DAT_011dd350 = 0;
        DAT_011dd310 |= 1;
    }
    else
    {
        DAT_011dd310 |= 2;
        DAT_011dd300 = ComputeAttenuatedVolume(DAT_011dd314, DAT_011dd30c);
        DAT_011dd318 = 0;
        DAT_011dd328 = 0;
        DAT_011dd32c = 0;
        DAT_011dd31c = 0;
        DAT_011dd311 |= 1;
    }
    FUN_00830490();
}

// @fnv 0x008305e0
void FUN_008305e0()
{
    GetCurrentThreadId();
    DAT_011dd310 |= 4;
    DAT_011dd311 |= 4;
    FUN_00830490();
}

// @fnv 0x00830610
void ResetThreadFlags()
{
    GetCurrentThreadId();
    DAT_011dd310 &= -5;
    DAT_011dd311 &= -5;
    FUN_00830490();
}

extern char DAT_011dd312;

// @fnv 0x00830640
void __cdecl FUN_00830640()
{
    GetCurrentThreadId();
    DAT_011dd312 = 1;
    FUN_00830490();
}

extern int DAT_011dd36c;
extern int DAT_011dd320;
extern int DAT_011dd354;

// @fnv 0x008308c0
unsigned int FUN_008308c0(unsigned long aeType)
{
    GetCurrentThreadId();
    unsigned int ret = 0;
    if (!aeType)
    {
        if (DAT_011dd36c == 1 && DAT_011dd334)
            ret = DAT_011dd320;
        else if (DAT_011dd36c == 0 && DAT_011dd368)
            ret = DAT_011dd354;
    }
    if (DAT_011dd36c == 1 && DAT_011dd334 && DAT_011dd314 == aeType)
        ret = DAT_011dd320;
    else if (DAT_011dd36c == 0 && DAT_011dd368 && DAT_011dd348 == aeType)
        ret = DAT_011dd354;
    FUN_00830490();
    return ret;
}

struct FUN_0082f950_shell
{
    void FUN_0082f6c0();
    void* ScalarDeletingDestructor(unsigned int flags);
};

extern void __stdcall FUN_00ec5fce(void*, unsigned int, unsigned int, void (FUN_0082f950_shell::*)());
extern void __cdecl FormHeap_Free(void*);

// Destructor that runs cleanup, optionally frees the object (and its 4-byte header when flags bit 2 is set), and returns the object pointer.
// @fnv 0x0082f950
void* FUN_0082f950_shell::ScalarDeletingDestructor(unsigned int flags)
{
    if ((flags & 2) != 0)
    {
        FUN_00ec5fce(this, 0x4c, ((unsigned int*)this)[-1], &FUN_0082f950_shell::FUN_0082f6c0);
        if ((flags & 1) != 0)
            FormHeap_Free((char*)this - 4);
        return (char*)this - 4;
    }

    FUN_0082f6c0();
    if ((flags & 1) != 0)
        FormHeap_Free(this);
    return this;
}

extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
extern void* DAT_011dd3b0;
class AudioClock
{
  public:
    unsigned int GetSynchTime();
};
AudioClock* FUN_00453a70();
class MediaLocationController
{
  public:
    bool Update(bool);
};
class MediaSet
{
  public:
    bool Update(unsigned int, bool, MediaLocationController*);
    void Reset();
};
class WorldSpace
{
  public:
    bool UpdateCombatMusic();
};
extern WorldSpace* BGSSaveLoadGlobalDataWorldlocationPtr;
class MediaLocationRecord
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0a();
    virtual void Unk0b();
    virtual MediaSet* GetExploreSet();
    virtual MediaSet* GetCombatSet();
};
class AcousticEntry
{
  public:
    MediaLocationRecord* FUN_004f35b0();
};
class AcousticSpace
{
  public:
    AcousticEntry* FUN_009611e0(int);
};
class AcousticSpaceOwner
{
  public:
    AcousticSpace* FUN_006733e0();
};
extern AcousticSpaceOwner* DAT_011dcfb4;
class PlayerMedia
{
  public:
    virtual void Unk000();
    virtual void Unk001();
    virtual void Unk002();
    virtual void Unk003();
    virtual void Unk004();
    virtual void Unk005();
    virtual void Unk006();
    virtual void Unk007();
    virtual void Unk008();
    virtual void Unk009();
    virtual void Unk00a();
    virtual void Unk00b();
    virtual void Unk00c();
    virtual void Unk00d();
    virtual void Unk00e();
    virtual void Unk00f();
    virtual void Unk010();
    virtual void Unk011();
    virtual void Unk012();
    virtual void Unk013();
    virtual void Unk014();
    virtual void Unk015();
    virtual void Unk016();
    virtual void Unk017();
    virtual void Unk018();
    virtual void Unk019();
    virtual void Unk01a();
    virtual void Unk01b();
    virtual void Unk01c();
    virtual void Unk01d();
    virtual void Unk01e();
    virtual void Unk01f();
    virtual void Unk020();
    virtual void Unk021();
    virtual void Unk022();
    virtual void Unk023();
    virtual void Unk024();
    virtual void Unk025();
    virtual void Unk026();
    virtual void Unk027();
    virtual void Unk028();
    virtual void Unk029();
    virtual void Unk02a();
    virtual void Unk02b();
    virtual void Unk02c();
    virtual void Unk02d();
    virtual void Unk02e();
    virtual void Unk02f();
    virtual void Unk030();
    virtual void Unk031();
    virtual void Unk032();
    virtual void Unk033();
    virtual void Unk034();
    virtual void Unk035();
    virtual void Unk036();
    virtual void Unk037();
    virtual void Unk038();
    virtual void Unk039();
    virtual void Unk03a();
    virtual void Unk03b();
    virtual void Unk03c();
    virtual void Unk03d();
    virtual void Unk03e();
    virtual void Unk03f();
    virtual void Unk040();
    virtual void Unk041();
    virtual void Unk042();
    virtual void Unk043();
    virtual void Unk044();
    virtual void Unk045();
    virtual void Unk046();
    virtual void Unk047();
    virtual void Unk048();
    virtual void Unk049();
    virtual void Unk04a();
    virtual void Unk04b();
    virtual void Unk04c();
    virtual void Unk04d();
    virtual void Unk04e();
    virtual void Unk04f();
    virtual void Unk050();
    virtual void Unk051();
    virtual void Unk052();
    virtual void Unk053();
    virtual void Unk054();
    virtual void Unk055();
    virtual void Unk056();
    virtual void Unk057();
    virtual void Unk058();
    virtual void Unk059();
    virtual void Unk05a();
    virtual void Unk05b();
    virtual void Unk05c();
    virtual void Unk05d();
    virtual void Unk05e();
    virtual void Unk05f();
    virtual void Unk060();
    virtual void Unk061();
    virtual void Unk062();
    virtual void Unk063();
    virtual void Unk064();
    virtual void Unk065();
    virtual void Unk066();
    virtual void Unk067();
    virtual void Unk068();
    virtual void Unk069();
    virtual void Unk06a();
    virtual void Unk06b();
    virtual void Unk06c();
    virtual void Unk06d();
    virtual void Unk06e();
    virtual void Unk06f();
    virtual void Unk070();
    virtual void Unk071();
    virtual void Unk072();
    virtual void Unk073();
    virtual void Unk074();
    virtual void Unk075();
    virtual void Unk076();
    virtual void Unk077();
    virtual void Unk078();
    virtual void Unk079();
    virtual void Unk07a();
    virtual void Unk07b();
    virtual void Unk07c();
    virtual void Unk07d();
    virtual void Unk07e();
    virtual void Unk07f();
    virtual void Unk080();
    virtual void Unk081();
    virtual void Unk082();
    virtual void Unk083();
    virtual void Unk084();
    virtual void Unk085();
    virtual void Unk086();
    virtual void Unk087();
    virtual void Unk088();
    virtual void Unk089();
    virtual void Unk08a();
    virtual bool IsInCombat(bool);
    MediaLocationController* GetMediaLocationController();
};
extern PlayerMedia* g_thePlayer;
extern MediaLocationController* DAT_011dd374;
extern MediaSet* DAT_011dd378;
extern MediaLocationRecord* DAT_011dd380;
bool FUN_007027b0(int);
bool FUN_00830ad0();
// @fnv 0x0082fb70
void UpdateMediaLocation()
{
    SetEvent(DAT_011dd3b0);
    if (DAT_011dd313)
        return;
    if (FUN_00830750(6, true) || FUN_00830750(8, true))
    {
        if (DAT_011dd374)
            DAT_011dd374 = 0;
        return;
    }
    // Saved media category; mediaType below is the audio synchronization clock.
    unsigned long time;
    if (DAT_011dd36c == 0)
        time = DAT_011dd348;
    else
        time = DAT_011dd314;
    unsigned int mediaType = FUN_00453a70()->GetSynchTime();
    bool combat =
        BGSSaveLoadGlobalDataWorldlocationPtr ? BGSSaveLoadGlobalDataWorldlocationPtr->UpdateCombatMusic() : false;
    if (FUN_007027b0(1007))
        return;
    if (!DAT_011dd378 || (DAT_011dd378 && !DAT_011dd378->Update(mediaType, combat, 0)))
    {
        if (DAT_011dd378)
            DAT_011dd378 = 0;
        if (g_thePlayer &&
            (!g_thePlayer->GetMediaLocationController() || !g_thePlayer->GetMediaLocationController()->Update(combat)))
        {
            DAT_011dd374 = 0;
            if (DAT_011dcfb4 && DAT_011dcfb4->FUN_006733e0())
            {
                if (FUN_00830750(2, true))
                    StartFade(1000, 2);
                if (FUN_00830750(3, true))
                    StartFade(1000, 3);
                AcousticSpace* location = DAT_011dcfb4->FUN_006733e0();
                MediaLocationRecord* space = DAT_011dd380 ? DAT_011dd380 : location->FUN_009611e0(7)->FUN_004f35b0();
                if (space)
                {
                    if (combat && !DAT_011dd378)
                    {
                        DAT_011dd378 = space->GetCombatSet();
                        if (DAT_011dd378)
                            DAT_011dd378->Reset();
                    }
                    if (!DAT_011dd378 || (DAT_011dd378 && !DAT_011dd378->Update(mediaType, combat, 0)))
                    {
                        DAT_011dd378 = 0;
                        if (space->GetExploreSet() && time == 0)
                            space->GetExploreSet()->Update(mediaType, false, 0);
                    }
                }
            }
        }
        else if (g_thePlayer)
        {
            if (g_thePlayer->IsInCombat(false))
                StartFade(1000, 0);
            else if (FUN_00830750(0, true) && !FUN_00830ad0() && !DAT_011dd374)
            {
                StartFade(5000, 4);
                StartFade(5000, 5);
                StartFade(5000, 2);
                StartFade(5000, 3);
            }
        }
    }
}

struct BSThread
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
    void Initialize(int stackSize, const char* name, bool suspended);
    void SetThreadPriority(int priority);
    void FUN_00aa6550(int value);
};

struct FAMThread : BSThread
{
    FAMThread();
    ~FAMThread();
};

extern const char DAT_0107cc08[];
extern const char DAT_0107cbf0[];
extern BSThread* DAT_011dd1f4;

// Allocates two FAMThread objects, initializes each with a 0x4000 stack and name, sets priority 1, and calls FUN_00aa6550 with 0.
// @fnv 0x0082f830
void __cdecl FUN_0082f830()
{
    DAT_011dd1f4 = new ::FAMThread[2];
    DAT_011dd1f4->Initialize(0x4000, DAT_0107cc08, false);
    DAT_011dd1f4->SetThreadPriority(1);
    (DAT_011dd1f4 + 1)->Initialize(0x4000, DAT_0107cbf0, false);
    (DAT_011dd1f4 + 1)->SetThreadPriority(1);
    int zero = 0;
    DAT_011dd1f4->FUN_00aa6550(zero);
    (DAT_011dd1f4 + 1)->FUN_00aa6550(zero);
}

namespace fnv_008300c0 {
struct EmptyType
{
};

struct BSFile
{
    virtual ~BSFile();
    BSFile(char const*, int, unsigned int, bool);

    unsigned char padding[0x154];

    bool Write();
};

struct S2f760
{
    unsigned char padding[0x4c];

    void CopyAndSleep(void const*);
};

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

struct GlobalObject_0096a2d0
{
    int value;
};

void _FNV_Warning(char const*, ...);
float __cdecl ComputeAttenuatedVolume(int, float);

extern int DAT_011a163c;
extern unsigned char DAT_011dcfa5;
extern char DAT_011dd0f0[260];
extern char DAT_011dd1f8[260];
extern S2f760* DAT_011dd1f4;
extern float DAT_011dd30c;
extern int DAT_011dd318;
extern float DAT_011dd344;
extern int DAT_011dd330;
extern int DAT_011dd34c;
extern int DAT_011dd364;
extern int DAT_011dd36c;
extern int DAT_011dd3c8;
extern GlobalObject_0096a2d0 g_011dd3c4;

// Validates and queues an audio media file for playback, storing fade, loop, and attenuation settings into the active or standby media slot.
// @fnv 0x008300c0
void __cdecl PlayAudioMedia(int aeMediaType, char const* apFileName, unsigned int auiFadeTime, bool abLoop,
                            bool abForce, float afAttenuation, unsigned int auiSynchTime)
{
    char const* pRealFilename;
    EmptyType* pTask;

    GetCurrentThreadId();

    if (aeMediaType == 9)
    {
        StartMenu::UpdateMedia();
        FUN_00830490();
        return;
    }

    if (aeMediaType != 8 && DAT_011dcfa5)
    {
        FUN_00830490();
        return;
    }

    if (!apFileName || !apFileName[0])
    {
        FUN_00830490();
        return;
    }

    if (!abForce && ((aeMediaType < static_cast<int>(DAT_011dd314) && DAT_011dd36c == 1) ||
                     (aeMediaType < static_cast<int>(DAT_011dd348) && DAT_011dd36c == 0)))
    {
        _FNV_Warning("FalloutAudioMedia: Trying to open media out of priority");
        FUN_00830490();
        return;
    }

    pRealFilename = apFileName;
    {
        BSFile fileCheck(pRealFilename, 0, 0x4000, false);
        if (!fileCheck.Write())
        {
            _FNV_Warning("FalloutAudioMedia: File '%s' does not exist!", apFileName);
            FUN_00830490();
            return;
        }
    }

    pTask = reinterpret_cast<EmptyType*>(
        static_cast<FORenderedMenu*>(TESLandTexture::GetSoundSystem())->GetCurrentTimeMilliseconds());

    if (DAT_011dd36c == 0)
    {
        DAT_011dd300 = 0.0f;
        DAT_011dd304 = 0.0f;
        DAT_011dd308 = ComputeAttenuatedVolume(aeMediaType, afAttenuation);
        DAT_011dd30c = afAttenuation;
        DAT_011dd310 = static_cast<char>((abLoop ? 0x20 : 0) | 0x10);

        TaskQueueInterface::CopyStringToBuffer(DAT_011dd0f0, 0x104, apFileName);

        DAT_011dd314 = static_cast<unsigned long>(aeMediaType);
        DAT_011dd318 = static_cast<int>(auiSynchTime);
        DAT_011dd328 = auiFadeTime;
        DAT_011dd32c = reinterpret_cast<unsigned int>(pTask) + DAT_011dd328;
        DAT_011dd330 = 0;
        DAT_011dd334 = DAT_011a163c;
        g_011dd3c4.value = DAT_011a163c;
        ++DAT_011a163c;
        DAT_011dd3c8 = DAT_011dd36c;
        DAT_011dd1f4[DAT_011dd36c].CopyAndSleep(&g_011dd3c4);
        DAT_011dd36c = 1;
        DAT_011dd311 = static_cast<char>(DAT_011dd311 | 0x18);
        DAT_011dd33c = DAT_011dd338;
        DAT_011dd340 = 0.0f;
        DAT_011dd35c = DAT_011dd328;
        DAT_011dd360 = DAT_011dd32c;
    }
    else
    {
        DAT_011dd338 = 0.0f;
        DAT_011dd33c = 0.0f;
        DAT_011dd340 = ComputeAttenuatedVolume(aeMediaType, afAttenuation);
        DAT_011dd344 = afAttenuation;
        DAT_011dd311 = static_cast<char>((abLoop ? 0x20 : 0) | 0x10);

        TaskQueueInterface::CopyStringToBuffer(DAT_011dd1f8, 0x104, apFileName);

        DAT_011dd348 = static_cast<unsigned long>(aeMediaType);
        DAT_011dd34c = static_cast<int>(auiSynchTime);
        DAT_011dd35c = auiFadeTime;
        DAT_011dd360 = reinterpret_cast<unsigned int>(pTask) + DAT_011dd35c;
        DAT_011dd364 = 0;
        DAT_011dd368 = DAT_011a163c;
        g_011dd3c4.value = DAT_011a163c;
        ++DAT_011a163c;
        DAT_011dd3c8 = DAT_011dd36c;
        DAT_011dd1f4[DAT_011dd36c].CopyAndSleep(&g_011dd3c4);
        DAT_011dd36c = 0;
        DAT_011dd310 = static_cast<char>(DAT_011dd310 | 0x18);
        DAT_011dd304 = DAT_011dd300;
        DAT_011dd308 = 0.0f;
        DAT_011dd328 = DAT_011dd35c;
        DAT_011dd32c = DAT_011dd360;
    }

    FUN_00830490();
}
}  // namespace fnv_008300c0
