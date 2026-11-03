// bsaudio/bssoundhandle.cpp: BSAudio, SystemColorManager, HUDMainMenu, SoundHandleX (37 functions)

#include "bssoundhandle_decls.h"

// @fnv 0x00ad8e60
void SoundPlaybackHandle::SetCompletionCallback(BSSoundCompletionCallback callback, void* context)
{
    if (!BSAudio::GetRandomGenerator()->IsAudioEnabled() && callback)
    {
        callback(context, false);
    }
    if (m_uiSoundResourceID != 0xffffffff)
    {
        BSAudioManager::GetRandomGenerator().FUN_00adbfd0(m_uiSoundResourceID, callback, context);
    }
}

// Returns false when the sound handle is invalid, otherwise checks the cached state or queries BSAudioManager::IsPlaying for the handle.
// @fnv 0x00ad8930
bool SoundPlaybackHandle::IsPlaying() const
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    if (m_bLooping)
    {
        return eState == ASSUMED_STATE_PLAYING;
    }
    else
    {
        return BSAudioManager::GetRandomGenerator().IsPlaying(m_uiSoundResourceID);
    }
}

// If the stored sound handle is valid, sets the state to playing and forwards the handle, delay and start time to BSAudioManager.
// @fnv 0x00ad8870
bool SoundPlaybackHandle::SchedulePlayback(unsigned int delay, int startTime)
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::GetRandomGenerator().FUN_00adb4e0(m_uiSoundResourceID, delay, startTime);
}

// If a sound handle is set, passes it with fadeTime and 0x26 to BSAudioManager, clears the handle, and returns true; otherwise returns false.
// @fnv 0x00ad8da0
bool SoundPlaybackHandle::StopWithFade(unsigned int fadeTime)
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    BSAudioManager::GetRandomGenerator().SetPlaybackTime(m_uiSoundResourceID, fadeTime, 0x26);
    m_uiSoundResourceID = 0xffffffff;
    return true;
}

// @fnv 0x00719060
bool SystemColorManager::GetColor(int id, NiColor& color)
{
    SystemColor* systemColor = Find(id);
    if (systemColor)
    {
        systemColor->FUN_007193b0(color);
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x00ad8a90
bool SoundPlaybackHandle::SetPlaybackFrequency(float frequency)
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    return BSAudioManager::GetRandomGenerator().SetPlaybackFrequency(m_uiSoundResourceID, frequency);
}

// @fnv 0x00ad8ce0
bool SoundPlaybackHandle::IsValid() const
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    return BSAudioManager::GetRandomGenerator().IsSoundPlaying(m_uiSoundResourceID);
}

// The covered PC function refreshes the HUD prompt through its singleton.
// @fnv 0x00778b10
void HUDMainMenu::RefreshTargetDisplay()
{
    if (g_pHudMainMenuInstance)
    {
        UpdateTargetReference(g_pHudMainMenuInstance->m_pCrosshairReference, false, true);
    }
}

void __cdecl FUN_0072fa80(int);

// @fnv 0x0072fa60
void __cdecl FUN_0072fa60(int param_1)
{
    FUN_0072fa80(param_1);
}

struct FUN_00ad8830_shell : public SoundPlaybackHandle
{
    bool Play(bool);
};

struct M8830 : public BSAudioManager
{
    bool FUN_00adb3e0(unsigned, bool);
};
// @fnv 0x00ad8830
bool FUN_00ad8830_shell::Play(bool v)
{
    if (*(unsigned*)this == 0xffffffff)
        return false;
    ((unsigned*)this)[2] = 1;
    return ((M8830&)BSAudioManager::GetRandomGenerator()).FUN_00adb3e0(*(unsigned*)this, v);
}

struct FUN_00ad89b0_shell : public SoundPlaybackHandle
{
    bool SetStaticAttenuation(unsigned short);
};

struct BSAudioManagerCall
{
    bool FUN_00adb720(unsigned int, unsigned short);
};

// @fnv 0x00ad89b0
bool FUN_00ad89b0_shell::SetStaticAttenuation(unsigned short aiStaticAttenutation)
{
    if (*reinterpret_cast<unsigned int*>(this) == -1)
        return false;
    return reinterpret_cast<BSAudioManagerCall&>(BSAudioManager::GetRandomGenerator())
        .FUN_00adb720(*reinterpret_cast<unsigned int*>(this), aiStaticAttenutation);
}

struct FUN_00ad89e0_shell : public SoundPlaybackHandle
{
    bool FUN_00ad89e0(float);
};

bool __fastcall FUN_00adc0d0(BSAudioManager*, int, unsigned int, float);

// @fnv 0x00ad89e0
bool FUN_00ad89e0_shell::FUN_00ad89e0(float aiNewVolume)
{
    if (*(int*)this == -1)
        return false;
    return ((bool(__thiscall*)(BSAudioManager*, unsigned int, float))FUN_00adc0d0)(&BSAudioManager::GetRandomGenerator(),
                                                                                   *(unsigned int*)this, aiNewVolume);
}

struct M8ad0 : public BSAudioManager
{
    bool FUN_00adb8e0(unsigned, bool);
};
struct FUN_00ad8ad0_s
{
    unsigned id;
    bool FUN_00ad8ad0(bool v);
};
// If id is valid, forwards id and v to BSAudioManager's FUN_00adb8e0 and returns its result; otherwise returns false.
// @fnv 0x00ad8ad0
bool FUN_00ad8ad0_s::FUN_00ad8ad0(bool v)
{
    if (id == 0xffffffff)
        return false;
    return ((M8ad0&)BSAudioManager::GetRandomGenerator()).FUN_00adb8e0(id, v);
}

struct FUN_00adb970_stub
{
    bool FUN_00adb970(unsigned int, float, float, float);
};
struct FUN_00ad8b60_h
{
    unsigned int id;
    bool SetPos(float x, float y, float z);
};
// @fnv 0x00ad8b60
bool FUN_00ad8b60_h::SetPos(float x, float y, float z)
{
    if (id == 0xFFFFFFFF)
        return false;
    return ((FUN_00adb970_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00adb970(id, x, y, z);
}

struct FUN_00ad8be0_shell : public SoundPlaybackHandle
{
    void FUN_00ad8be0(float, float);
};

struct BSAudioManager_ext
{
    void FUN_00adba70(unsigned int, float, float);
};

// @fnv 0x00ad8be0
void FUN_00ad8be0_shell::FUN_00ad8be0(float afMin, float afMax)
{
    if (*(unsigned int*)this == 0xFFFFFFFF)
        return;

    ((BSAudioManager_ext*)&BSAudioManager::GetRandomGenerator())->FUN_00adba70(*(unsigned int*)this, afMin, afMax);
}

struct FUN_00adbb30_stub
{
    void FUN_00adbb30(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
};
struct FUN_00ad8c20_h
{
    unsigned int id;
    void FUN_00ad8c20(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e);
};
// @fnv 0x00ad8c20
void FUN_00ad8c20_h::FUN_00ad8c20(unsigned short ausArg1, unsigned short ausArg2, unsigned short ausArg3,
                                  unsigned short ausArg4, unsigned short ausArg5)
{
    if (id == 0xFFFFFFFF)
        return;
    ((FUN_00adbb30_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00adbb30(id, ausArg1, ausArg2, ausArg3, ausArg4, ausArg5);
}

struct BSAudioManagerHelper
{
    void FUN_00adbec0(int, int);
};

struct FUN_00ad8c70_Class
{
    int id;
    void FUN_00ad8c70(unsigned short param);
};

// @fnv 0x00ad8c70
void FUN_00ad8c70_Class::FUN_00ad8c70(unsigned short param)
{
    if (id == -1)
        return;
    reinterpret_cast<BSAudioManagerHelper*>(&BSAudioManager::GetRandomGenerator())->FUN_00adbec0(id, param);
}

struct NiAVObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00ad8f20_shell : public SoundPlaybackHandle
{
    void SetNiNode(NiAVObject*);
};

extern void(__cdecl* DAT_011f6e08)(NiAVObject*);
struct FUN_00adc1e0_stub
{
    void FUN_00adc1e0(unsigned int, NiAVObject*);
};
// If the stored id is valid and apObj is non-null, calls DAT_011f6e08 on apObj and then FUN_00adc1e0 with the stored id and apObj.
// @fnv 0x00ad8f20
void FUN_00ad8f20_shell::SetNiNode(NiAVObject* apObj)
{
    if (*(unsigned int*)this == 0xFFFFFFFF || !apObj)
        return;
    if (DAT_011f6e08)
        DAT_011f6e08(apObj);
    ((FUN_00adc1e0_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00adc1e0(*(unsigned int*)this, apObj);
}

struct FUN_00ad9030_shell : public SoundPlaybackHandle
{
    void FUN_00ad9030(unsigned int);
};

struct M9030 : public BSAudioManager
{
    void FUN_00adc460(unsigned, unsigned);
};
// @fnv 0x00ad9030
void FUN_00ad9030_shell::FUN_00ad9030(unsigned v)
{
    if (*(unsigned*)this == 0xffffffff)
        return;
    ((M9030&)BSAudioManager::GetRandomGenerator()).FUN_00adc460(*(unsigned*)this, v);
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting104;

struct FUN_008bc240_h
{
    char pad[0x150];
    unsigned int f150;
    float f154;
    void FUN_008bc240(unsigned int v);
};

// Stores v into f150 and copies the float from originalRuntimeFloatSetting104 into f154.
// @fnv 0x008bc240
void FUN_008bc240_h::FUN_008bc240(unsigned int auiValue)
{
    f150 = auiValue;
    f154 = *originalRuntimeFloatSetting104.Float();
}

struct SndX
{
    bool IsValid();
    void Stop();
    void PausePlayback();
};
struct Owner009b11c0
{
    void FUN_009b11c0();
};

// @fnv 0x009b11c0
void Owner009b11c0::FUN_009b11c0()
{
    if (((SndX*)((char*)this + 0xac))->IsValid())
    {
        ((SndX*)((char*)this + 0xac))->Stop();
        if (((SndX*)((char*)this + 0xac))->IsValid())
        {
            ((SndX*)((char*)this + 0xac))->PausePlayback();
        }
    }
    if (((SndX*)((char*)this + 0xb8))->IsValid())
    {
        ((SndX*)((char*)this + 0xb8))->Stop();
        if (((SndX*)((char*)this + 0xb8))->IsValid())
        {
            ((SndX*)((char*)this + 0xb8))->PausePlayback();
        }
    }
}

struct AudioMgrStub : BSAudioManager
{
    bool FUN_00adb590(unsigned int);
};

struct FUN_00ad88b0_h
{
    unsigned int id;
    int unk4;
    int state;
    bool FUN_00ad88b0();
};

// @fnv 0x00ad88b0
bool FUN_00ad88b0_h::FUN_00ad88b0()
{
    if (id == (unsigned int)-1)
        return false;
    state = 3;
    return ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adb590(id);
}

namespace fnv_00ad88f0 {
struct AudioMgrStub : BSAudioManager
{
    bool FUN_00adb610(unsigned int);
};

struct FUN_00ad88f0_h
{
    unsigned int id;
    int unk4;
    int state;
    bool FUN_00ad88f0();
};

// @fnv 0x00ad88f0
bool FUN_00ad88f0_h::FUN_00ad88f0()
{
    if (id == (unsigned int)-1)
        return false;
    state = 2;
    return ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adb610(id);
}
}  // namespace fnv_00ad88f0

struct Helper_00adc9a0
{
    int FUN_00adc9a0(unsigned int id);
};
struct FUN_00ad8980
{
    unsigned int uiID;
    int Op();
};
// @fnv 0x00ad8980
int FUN_00ad8980::Op()
{
    if (uiID == 0xFFFFFFFF)
        return 0;
    return ((Helper_00adc9a0&)BSAudioManager::GetRandomGenerator()).FUN_00adc9a0(uiID);
}

struct Helper_00adc8b0
{
    float FUN_00adc8b0(unsigned int id);
};
struct FUN_00ad8a20
{
    unsigned int uiID;
    float Op();
};
// @fnv 0x00ad8a20
float FUN_00ad8a20::Op()
{
    if (uiID == 0xFFFFFFFF)
        return 0.0f;
    return ((Helper_00adc8b0&)BSAudioManager::GetRandomGenerator()).FUN_00adc8b0(uiID);
}

namespace fnv_00ad8a50 {
struct AudioMgrStub : BSAudioManager
{
    bool FUN_00adb7c0(unsigned int, float);
};

struct FUN_00ad8a50_h
{
    unsigned int id;
    bool FUN_00ad8a50(float arg);
};

// If the stored id is not -1, forwards the id and arg to BSAudioManager's FUN_00adb7c0 and returns its result; otherwise returns false.
// @fnv 0x00ad8a50
bool FUN_00ad8a50_h::FUN_00ad8a50(float afValue)
{
    if (id == (unsigned int)-1)
        return false;
    return ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adb7c0(id, afValue);
}
}  // namespace fnv_00ad8a50

namespace fnv_00ad8b00 {
struct AudioMgrStub : BSAudioManager
{
    bool FUN_00adb960(unsigned int, unsigned int);
};

struct FUN_00ad8b00_h
{
    unsigned int id;
    bool FUN_00ad8b00(unsigned int arg);
};

// Returns false if id is -1, otherwise forwards id and arg to FUN_00adb960 on the BSAudioManager singleton.
// @fnv 0x00ad8b00
bool FUN_00ad8b00_h::FUN_00ad8b00(unsigned int arg)
{
    if (id == (unsigned int)-1)
        return false;
    return ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adb960(id, arg);
}
}  // namespace fnv_00ad8b00

struct FakeMgr
{
    int FUN_00adc830(unsigned int);
};
// Returns 0 if the value pointed to by a1 is -1, otherwise forwards it to FUN_00adc830 on the BSAudioManager instance.
// @fnv 0x00ad8b30
int __fastcall FUN_00ad8b30(unsigned int* a1)
{
    if (*a1 == -1)
        return 0;
    return ((FakeMgr&)BSAudioManager::GetRandomGenerator()).FUN_00adc830(*a1);
}

namespace fnv_00ad8ba0 {
struct AudioMgrStub : BSAudioManager
{
    bool FUN_00adb9f0(unsigned int, float, float, float);
};

struct FUN_00ad8ba0_h
{
    unsigned int id;
    bool FUN_00ad8ba0(float a, float b, float c);
};

// Returns false if id is -1, otherwise forwards id and the three floats to the audio manager's FUN_00adb9f0 and returns its result.
// @fnv 0x00ad8ba0
bool FUN_00ad8ba0_h::FUN_00ad8ba0(float a, float b, float c)
{
    if (id == (unsigned int)-1)
        return false;
    return ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adb9f0(id, a, b, c);
}
}  // namespace fnv_00ad8ba0

namespace fnv_00ad8ca0 {
struct AudioMgrStub : BSAudioManager
{
    bool FUN_00adbf40(unsigned int, float, float, float);
};

struct FUN_00ad8ca0_h
{
    unsigned int id;
    bool FUN_00ad8ca0(float a, float b, float c);
};

// If id is not -1, forwards id and the three floats to the audio manager's FUN_00adbf40 and returns its result; otherwise returns false.
// @fnv 0x00ad8ca0
bool FUN_00ad8ca0_h::FUN_00ad8ca0(float a, float b, float c)
{
    if (id == (unsigned int)-1)
        return false;
    return ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adbf40(id, a, b, c);
}
}  // namespace fnv_00ad8ca0

struct FUN_00ad8de0_h
{
    unsigned int id;
    int unk4;
    int state;
    bool FUN_00ad8de0(unsigned int arg);
};

// @fnv 0x00ad8de0
bool FUN_00ad8de0_h::FUN_00ad8de0(unsigned int arg)
{
    if (id == (unsigned int)-1)
        return false;
    state = 2;
    BSAudioManager::GetRandomGenerator().SetPlaybackTime(id, arg, 0);
    return true;
}

namespace fnv_00ad8e20 {
struct AudioMgrStub : BSAudioManager
{
    void FUN_00adc4e0(unsigned int, unsigned char, unsigned char);
};

struct FUN_00ad8e20_h
{
    unsigned int id;
    void FUN_00ad8e20(unsigned char a, unsigned char b);
};

// If id is not -1, forwards id and the two byte arguments to FUN_00adc4e0 on the BSAudioManager singleton.
// @fnv 0x00ad8e20
void FUN_00ad8e20_h::FUN_00ad8e20(unsigned char aucArg1, unsigned char aucArg2)
{
    if (id == (unsigned int)-1)
        return;
    ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adc4e0(id, aucArg1, aucArg2);
}
}  // namespace fnv_00ad8e20

typedef void(__cdecl* LocalCb)(void*, unsigned int);
struct BSAudioManagerX
{
    void FUN_00adc050(unsigned int, LocalCb, void*);
};
struct SoundHandleX
{
    unsigned int id;
    void FUN_00ad8ec0(LocalCb cb, void* arg);
};

// @fnv 0x00ad8ec0
void SoundHandleX::FUN_00ad8ec0(LocalCb apCallback, void* arg)
{
    BSAudio* audio = DAT_011f6d98;
    bool flag = *((bool*)audio + 4);
    if (!flag && apCallback)
    {
        apCallback(arg, 5000);
    }
    if (id != 0xFFFFFFFF)
    {
        ((BSAudioManagerX&)BSAudioManager::GetRandomGenerator()).FUN_00adc050(id, apCallback, arg);
    }
}

namespace fnv_00ad8f70 {
struct AudioMgrStub : BSAudioManager
{
    void FUN_00adc260(unsigned int, unsigned int);
};

struct FUN_00ad8f70_h
{
    unsigned int id;
    void DispatchToAudioManager(unsigned int arg);
};

// If id is not -1, forwards id and arg to FUN_00adc260 on the BSAudioManager instance.
// @fnv 0x00ad8f70
void FUN_00ad8f70_h::DispatchToAudioManager(unsigned int uiValue)
{
    if (id == (unsigned int)-1)
        return;
    ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adc260(id, uiValue);
}
}  // namespace fnv_00ad8f70

namespace fnv_00ad8fa0 {
struct AudioMgrStub : BSAudioManager
{
    void FUN_00adc2e0(unsigned int, unsigned char);
};

struct FUN_00ad8fa0_h
{
    unsigned int id;
    void FUN_00ad8fa0(unsigned char arg);
};

// If the stored id is not -1, forwards it and arg to BSAudioManager's FUN_00adc2e0.
// @fnv 0x00ad8fa0
void FUN_00ad8fa0_h::FUN_00ad8fa0(unsigned char arg)
{
    if (id == (unsigned int)-1)
        return;
    ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adc2e0(id, arg);
}
}  // namespace fnv_00ad8fa0

namespace fnv_00ad8fd0 {
struct AudioMgrStub : BSAudioManager
{
    void FUN_00adc360(unsigned int, unsigned int);
};

struct FUN_00ad8fd0_h
{
    unsigned int id;
    void FUN_00ad8fd0(unsigned int arg);
};

// If the stored id is not -1, forwards it and arg to BSAudioManager::FUN_00adc360.
// @fnv 0x00ad8fd0
void FUN_00ad8fd0_h::FUN_00ad8fd0(unsigned int arg)
{
    if (id == (unsigned int)-1)
        return;
    ((AudioMgrStub&)BSAudioManager::GetRandomGenerator()).FUN_00adc360(id, arg);
}
}  // namespace fnv_00ad8fd0

struct Helper_00adc3e0
{
    void FUN_00adc3e0(unsigned int id);
};
struct FUN_00ad9000
{
    unsigned int uiID;
    void Op();
};
// @fnv 0x00ad9000
void FUN_00ad9000::Op()
{
    if (uiID == 0xFFFFFFFF)
        return;
    ((Helper_00adc3e0&)BSAudioManager::GetRandomGenerator()).FUN_00adc3e0(uiID);
}
