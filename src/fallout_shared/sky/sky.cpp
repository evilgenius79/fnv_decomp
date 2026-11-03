// fallout_shared/sky/sky.cpp: Sky, ThisCls, TESObjectCELL, Host and more (61 functions)

#include "sky_packet.h"
namespace fnv_00454b10 {
class TESObjectCELL
{
  public:
    unsigned char pad[0x24];
    unsigned char flags;
    unsigned char GetFakeExterior();
};

// @fnv 0x00454b10
unsigned char TESObjectCELL::GetFakeExterior()
{
    return (flags & 0x80) != 0;
}
}  // namespace fnv_00454b10

// Updates sky colors, calls FUN_0063bce0, updates the two optional sky objects with time, and sets the renderer background color.
// @fnv 0x0063b0a0
void Sky::UpdateWeatherTransition(float time)
{
    UpdateColors();
    FUN_0063bce0();
    if (m_pAtmosphere)
        m_pAtmosphere->Update(this, time);
    if (m_pSun)
        m_pSun->Update(this, time);
    Renderer::SetBackgroundColor(m_kSkyColors[1]);
}

// @fnv 0x0063c8f0
void Sky::SetCurrentClimate(TESClimate* climate, bool force)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp", 1464);
    if (!climate && (!m_pCurrentClimate || force))
        climate = dynamic_cast<TESClimate*>(TESForm_SkyExt::GetFormByID(0x15f));
    if (!climate)
        return;
    if (m_pCurrentClimate != climate || force)
    {
        m_pCurrentClimate = climate;
        FUN_0063c9f0();
        ResetWeather();
        flags |= 0x40;
    }
}

// @fnv 0x0063ecb0
void Sky::LoadGame(BGSLoadGameBuffer* buffer)
{
    if (g_BGSSaveLoadGame->FUN_0063ef00())
        return;
    if (m_pPrecipitation)
        m_pPrecipitation->FlushAll();
    if (m_pClouds)
    {
        m_pClouds->ClearCloudLayers();
        m_pClouds->FUN_0063a610();
    }
    m_pRegionWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    m_pPreviousWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    m_pQueuedWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    m_pOverrideWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    buffer->ReadDataBlock(&m_fFogFarDistance, 4);
    buffer->ReadDataBlock(&fWeatherChance, 4);
    buffer->ReadDataBlock(&m_fWeatherBlend, 4);
    unsigned int loadedFlags = 0;
    buffer->ReadDataBlock(&loadedFlags, 4);
    flags = (flags & ~8) | (loadedFlags & 8);
    buffer->ReadDataBlock(&field110, 4);
    if (buffer->GetVersion() >= 18)
    {
        buffer->ReadDataBlock(&m_kSunlightColor.x, 4);
        buffer->ReadDataBlock(&m_kSunlightColor.y, 4);
        buffer->ReadDataBlock(&m_kSunlightColor.z, 4);
    }
    else
        buffer->ReadDataBlock(&m_kSunlightColor, 12);
    buffer->ReadDataBlock(&m_fFogNearDistance, 4);
    buffer->ReadDataBlock(&m_fFogPower, 4);
    buffer->ReadDataBlock(&eMode, 4);
    Update(0.0f);
    UpdateHDRValues();
}

// @fnv 0x00639d40
Sky::Sky() : m_pRootNode(0), m_pSkyNode(0), m_kSunlightColor(0.0f, 0.0f, 0.0f), m_kSkyColor(0.0f, 0.0f, 0.0f)
{
    m_pAtmosphere = 0;
    m_pStars = 0;
    m_pClouds = 0;
    m_pSun = 0;
    m_pPrimaryMoon = 0;
    m_pSecondaryMoon = 0;
    m_pPrecipitation = 0;
    m_pRootNode = 0;
    m_pSkyNode = 0;
    m_fFogFarDistance = 10.0f;
    eMode = 4;
    m_pCurrentClimate = 0;
    m_pOverrideWeather = 0;
    m_pQueuedWeather = 0;
    m_pPreviousWeather = 0;
    m_pRegionWeather = 0;
    fWeatherChance = 0.0f;
    field11c = 0;
    field124 = 0;
    field120 = 0;
    field128 = 0;
    for (int i = 0; i < 10; i++)
        m_kSkyColors[i] = DAT_011a9b7c;
    *(NiColor*)&m_kSkyColor = DAT_011a9b7c;
    m_fCurrentWeatherBlend = 0.0f;
    m_fTargetWeatherBlend = 1.0f;
    m_fWeatherBlend = 1.0f;
    field110 = 0.0f;
    m_pSkySounds = new BSSimpleList<SkySound*>;
    m_fWeatherFade = 0.0f;
    field108 = 0;
    field10c = originalRuntimeFloatSetting76.Float()->f;
    flags = 0;
    FUN_0063a030(true);
    field12c = 12.0f;
    field130 = 23.99f;
    field134 = 0.0f;
}

struct FUN_0063a030_shell : public Sky
{
    void FUN_0063a030(bool);
};

// @fnv 0x0063a030
void FUN_0063a030_shell::FUN_0063a030(bool abUpdate)
{
    if (abUpdate)
        *(unsigned int*)((char*)this + 0x118) |= 0x20;
    else
        *(unsigned int*)((char*)this + 0x118) &= ~0x20;
}

struct FUN_0063a610_shell : public Clouds
{
    void FUN_0063a610();
};

// @fnv 0x0063a610
void FUN_0063a610_shell::FUN_0063a610()
{
    *((unsigned char*)this + 0x5a) = 1;
}

struct FUN_0063b600_shell : public Clouds
{
    void FUN_0063b600(int, NiColor*);
};

// Copies the NiColor pointed to by the second argument into the layer slot at offset 0x28 indexed by aiLayer.
// @fnv 0x0063b600
void FUN_0063b600_shell::FUN_0063b600(int aiLayer, NiColor* apColor)
{
    ((NiColor*)((char*)this + 0x28))[aiLayer] = *apColor;
}

struct FUN_0063b9b0_shell : public Sky
{
    float FUN_0063b9b0();
};

float __cdecl FUN_00404010(float, float);
float __fastcall FUN_00595ea0(void*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;
extern float DAT_011cccfc;

// @fnv 0x0063b9b0
float FUN_0063b9b0_shell::FUN_0063b9b0()
{
    if (*(unsigned int*)((char*)this + 0x118) & 0x1000)
    {
        DAT_011cccfc = FUN_00404010(0.0f, FUN_00595ea0(this) - originalRuntimeFloatSetting78.Float()->f);
        *(unsigned int*)((char*)this + 0x118) &= ~0x1000u;
    }
    return DAT_011cccfc;
}

struct FUN_0063ba30_shell : public Sky
{
    float FUN_0063ba30();
};

float __cdecl FUN_0040ebd0(float, float);
float __fastcall FUN_00596030(void*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;
extern float DAT_011ccd00;

// If the 0x2000 flag is set, clears it and recomputes DAT_011ccd00 from a setting plus FUN_00596030(this); returns DAT_011ccd00.
// @fnv 0x0063ba30
float FUN_0063ba30_shell::FUN_0063ba30()
{
    if (*(unsigned int*)((char*)this + 0x118) & 0x2000)
    {
        DAT_011ccd00 = FUN_0040ebd0(23.989999771118164f, FUN_00596030(this) + originalRuntimeFloatSetting78.Float()->f);
        *(unsigned int*)((char*)this + 0x118) &= ~0x2000;
    }
    return DAT_011ccd00;
}

struct FUN_0063bb40_stand
{
    char pad[0x108];
    int tbl[4][6];
    int FUN_0063bb40(int a, int b);
};
// Returns the int stored at tbl[a][b].
// @fnv 0x0063bb40
int FUN_0063bb40_stand::FUN_0063bb40(int aiRow, int aiColumn)
{
    return tbl[aiRow][aiColumn];
}

struct NiStream;
struct blob8
{
    char b[8];
};
struct NiPoint2
{
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];
struct FUN_0063c490_shell : public Sky
{
    void FUN_0063c490();
};

float __cdecl FUN_00452e70(bool);
float __cdecl FUN_0057e960(float);
float __cdecl FUN_0063c600(float);
void __cdecl FUN_0063c640(int, int);
void __cdecl FUN_0063c660(float);
void __cdecl FUN_0063c670(NiPoint2);
void __fastcall _ref_006815c0(NiPoint2*);

extern double _DAT_01012640;
extern double _DAT_0104eea0;
extern double DAT_0104ee98;
extern int DAT_011a9b50;
extern int DAT_011a9b54;

struct TESWeatherEx : public TESWeather
{
    float GetWeatherData(int, float, float);
};

// @fnv 0x0063c490
void FUN_0063c490_shell::FUN_0063c490()
{
    float fperiod;
    float fscale;
    float fUpdatePeriod;
    NiPoint2 windPerturb;

    if (*reinterpret_cast<TESWeatherEx**>(reinterpret_cast<char*>(this) + 0x10) != 0 &&
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xf8) == 3 ||
         *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xf8) == 2))
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) =
            (*reinterpret_cast<TESWeatherEx**>(reinterpret_cast<char*>(this) + 0x10))->GetWeatherData(0, 1.0f, 0.0f);
        if (*reinterpret_cast<TESWeatherEx**>(reinterpret_cast<char*>(this) + 0x14) != 0)
        {
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) =
                *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) *
                *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf4);
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) =
                (1.0f - *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf4)) *
                    (*reinterpret_cast<TESWeatherEx**>(reinterpret_cast<char*>(this) + 0x14))
                        ->GetWeatherData(0, 1.0f, 0.0f) +
                *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc);
        }
        FUN_0063c640(DAT_011a9b50, DAT_011a9b54);
        FUN_0063c660(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc));
        _ref_006815c0(&windPerturb);
        fperiod = 15.0f;
        fscale = 15.0f;
        fUpdatePeriod = (FUN_00452e70(false) / _DAT_01012640) * _DAT_0104eea0 * fperiod;
        windPerturb.x = FUN_0063c600(fUpdatePeriod) * fscale;
        windPerturb.y = FUN_0057e960(fUpdatePeriod * DAT_0104ee98) * fscale;
        FUN_0063c670(windPerturb);
    }
}

extern float runtimeInitializationFloat2719;
extern float DAT_011f52e0[512];

// Scales arg by 512.0 divided by runtimeInitializationFloat2719, masks the index to 0x1ff, and returns DAT_011f52e0[idx].
// @fnv 0x0063c600
float __cdecl FUN_0063c600(float afValue)
{
    int idx = (int)((512.0 / runtimeInitializationFloat2719) * afValue) & 0x1ff;
    return DAT_011f52e0[idx];
    return 0.0f;
}

struct FUN_0063c8a0_shell : public NiPoint3
{
    NiPoint3* FUN_0063c8a0(void*);
};

struct NiPoint3Fields
{
    float x;
    float y;
    float z;
};

// Adds the x, y and z components of pt to this NiPoint3 and returns this.
// @fnv 0x0063c8a0
NiPoint3* FUN_0063c8a0_shell::FUN_0063c8a0(void* apPoint)
{
    reinterpret_cast<NiPoint3Fields*>(this)->x += reinterpret_cast<const NiPoint3Fields*>(apPoint)->x;
    reinterpret_cast<NiPoint3Fields*>(this)->y += reinterpret_cast<const NiPoint3Fields*>(apPoint)->y;
    reinterpret_cast<NiPoint3Fields*>(this)->z += reinterpret_cast<const NiPoint3Fields*>(apPoint)->z;
    return this;
}

struct FUN_0063c9f0_shell : public Sky
{
    void FUN_0063c9f0();
};

// @fnv 0x0063c9f0
void FUN_0063c9f0_shell::FUN_0063c9f0()
{
    *(unsigned int*)((char*)this + 0x118) |= 0x3f00;
}

struct FUN_0063d000_shell : public TESClimate
{
    bool FUN_0063d000();
};

// @fnv 0x0063d000
bool FUN_0063d000_shell::FUN_0063d000()
{
    return (*((unsigned char*)this + 0x55) & 0x80) != 0;
}

struct FUN_0063d020_shell : public TESClimate
{
    bool FUN_0063d020();
};

// @fnv 0x0063d020
bool FUN_0063d020_shell::FUN_0063d020()
{
    return (*((unsigned char*)this + 0x55) & 0x40) != 0;
}

struct FUN_0063d060_shell : public Sky
{
    void FUN_0063d060();
};

struct Sky_Helper : public Sky
{
    void FUN_0063e860(int);
};

// @fnv 0x0063d060
void FUN_0063d060_shell::FUN_0063d060()
{
    flags |= 1;
    m_pOverrideWeather = 0;
    m_pPreviousWeather = 0;
    m_pRegionWeather = 0;
    ((Sky_Helper*)this)->FUN_0063e860(0);
    if (m_pClouds != 0)
    {
        m_pClouds->ClearCloudLayers();
    }
    if (m_pPrecipitation != 0)
    {
        m_pPrecipitation->FlushAll();
    }
    UpdateHDRValues();
}

void __fastcall FUN_005827d0(char*);

// @fnv 0x0063d5c0
void __fastcall FUN_0063d5c0(char* p)
{
    FUN_005827d0(p + 0x30);
}

struct FUN_0063dd50_shell
{
    unsigned char pad[0xe0];
    unsigned char data[4];
    unsigned char FUN_0063dd50(int index);
};

// @fnv 0x0063dd50
unsigned char FUN_0063dd50_shell::FUN_0063dd50(int index)
{
    return data[index];
}

namespace fnv_0063e010 {
class SoundPlaybackHandle
{
  public:
    void Stop(void);
};

SoundPlaybackHandle* const& __fastcall _ref_006815c0(void* pNode);
void* __fastcall _ref_00726070(void* pNode);

// Iterates the linked list at pThis+0xfc and calls Stop on each node's referenced object.
// @fnv 0x0063e010
void __fastcall FUN_0063e010(char* pThis)
{
    for (void* pNode = *reinterpret_cast<void**>(pThis + 0xfc); pNode && _ref_006815c0(pNode);
         pNode = _ref_00726070(pNode))
    {
        _ref_006815c0(pNode)->Stop();
    }
}
}  // namespace fnv_0063e010

struct FUN_0063e210_shell : public Sky
{
    void FUN_0063e210();
};

void __fastcall FUN_006349e0(void*);
void __fastcall FUN_006369a0(void*);
void __fastcall FUN_00642940(void*);
void __fastcall FUN_0063e290(void*);

// @fnv 0x0063e210
void FUN_0063e210_shell::FUN_0063e210()
{
    if (*reinterpret_cast<Clouds**>(reinterpret_cast<char*>(this) + 0x2c))
    {
        FUN_006349e0(*reinterpret_cast<Clouds**>(reinterpret_cast<char*>(this) + 0x2c));
        (*reinterpret_cast<Clouds**>(reinterpret_cast<char*>(this) + 0x2c))->ClearCloudLayers();
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30))
    {
        FUN_006369a0(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30));
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x34))
    {
        FUN_006369a0(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x34));
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28))
    {
        FUN_00642940(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28));
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24))
    {
        FUN_0063e290(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24));
    }
}

namespace fnv_0063e290 {
template <class T> class BSStringT
{
  public:
    operator const char*() const;
};

class NiNode
{
  public:
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
    virtual void InsertChild(const char*);
};

// @fnv 0x0063e290
void __fastcall FUN_0063e290(void* pThis)
{
    if ((const char*)*(BSStringT<char>*)((char*)pThis + 4) != 0)
    {
        ((NiNode*)(const char*)*(BSStringT<char>*)((char*)pThis + 4))
            ->InsertChild((const char*)*(BSStringT<char>*)((char*)pThis + 8));
    }
    *(NiPointer<NiNode>*)((char*)pThis + 8) = 0;
}
}  // namespace fnv_0063e290

struct FUN_0063e860_stand
{
    char pad0[0x14];
    int f14;
    char pad1[0xf4 - 0x18];
    float fF4;
    char pad2[0x110 - 0xf8];
    float f110;
    int pad3;
    unsigned int flags;
    void FUN_0063e860(bool on);
};
// Toggles flag bit 8 based on on and f14, and sets f110 to fF4 when enabling or 0.0f when disabling.
// @fnv 0x0063e860
void FUN_0063e860_stand::FUN_0063e860(bool abEnabled)
{
    if (abEnabled && f14 && !(flags & 8))
    {
        flags |= 8;
        f110 = fF4;
    }
    else if (!abEnabled || !f14)
    {
        flags &= ~8;
        f110 = 0.0f;
    }
}

namespace fnv_0063bab0 {
struct FUN_0063bab0_shell : public Sky
{
    void FUN_0063bab0(void*, TESWeather*, TESWeather*, int, int*, int*);
};

struct FUN_0063bb40_stand
{
    int FUN_0063bb40(int, int);
};
// Fills a four-int blend from the current and last weather's color lookup at two times, zeroing the last-weather entries when there is no last weather.
// @fnv 0x0063bab0
void FUN_0063bab0_shell::FUN_0063bab0(void* aColorBlend, TESWeather* apCurrentWeather, TESWeather* apLastWeather,
                                      int aeColorType, int* aeTime1, int* aeTime2)
{
    if (!apCurrentWeather)
        return;
    ((int*)aColorBlend)[0] = ((FUN_0063bb40_stand*)apCurrentWeather)->FUN_0063bb40(aeColorType, *aeTime1);
    ((int*)aColorBlend)[1] = ((FUN_0063bb40_stand*)apCurrentWeather)->FUN_0063bb40(aeColorType, *aeTime2);
    if (apLastWeather)
    {
        ((int*)aColorBlend)[2] = ((FUN_0063bb40_stand*)apLastWeather)->FUN_0063bb40(aeColorType, *aeTime1);
        ((int*)aColorBlend)[3] = ((FUN_0063bb40_stand*)apLastWeather)->FUN_0063bb40(aeColorType, *aeTime2);
    }
    else
    {
        ((int*)aColorBlend)[3] = 0;
        ((int*)aColorBlend)[2] = 0;
    }
}
}  // namespace fnv_0063bab0

struct FUN_0063c420_shell
{
    unsigned char pad[0xf0];
    float arr[0x100];
    float __thiscall FUN_0063c420(int index);
};

// @fnv 0x0063c420
float __thiscall FUN_0063c420_shell::FUN_0063c420(int index)
{
    return arr[index];
}

struct Flt
{
    operator unsigned int(void) const;
};

struct FUN_0063c440_shell
{
    unsigned char pad[8];
    Flt m_flt;
    int FUN_0063c440(int index);
};

// @fnv 0x0063c440
int FUN_0063c440_shell::FUN_0063c440(int index)
{
    return ((Flt*)((char*)this + 8 + index * 4))->operator unsigned int();
}

extern unsigned char DAT_0119f188;

// @fnv 0x0063c460
unsigned char FUN_0063c460()
{
    return DAT_0119f188;
}

extern int DAT_011c7a3c;

// @fnv 0x0063c470
int __cdecl FUN_0063c470()
{
    return DAT_011c7a3c;
}

extern "C"
{
    extern float DAT_011c7a5c;
}

// @fnv 0x0063c480
float FUN_0063c480()
{
    return DAT_011c7a5c;
}

extern int DAT_011f95dc;
extern int DAT_011f95e0;

// @fnv 0x0063c640
void __cdecl FUN_0063c640(int aiFirst, int aiSecond)
{
    DAT_011f95dc = aiFirst;
    DAT_011f95e0 = aiSecond;
}

extern float DAT_011ad824;

// @fnv 0x0063c660
void FUN_0063c660(float value)
{
    DAT_011ad824 = value;
}

extern "C" float DAT_011fd884;
extern "C" float DAT_011fd888;

// @fnv 0x0063c670
void FUN_0063c670(float afValue1, float afValue2)
{
    DAT_011fd884 = afValue1;
    DAT_011fd888 = afValue2;
}

struct FUN_0063dd90_shell
{
    unsigned char pad[0x18];
    unsigned int m_flags;
    void FUN_0063dd90();
};

// @fnv 0x0063dd90
void FUN_0063dd90_shell::FUN_0063dd90()
{
    m_flags = m_flags | 0x80000000;
}

struct FUN_0063dff0_shell
{
    void* FUN_0063dff0();
};

// @fnv 0x0063dff0
void* FUN_0063dff0_shell::FUN_0063dff0()
{
    return reinterpret_cast<char*>(this) + 0x1F8;
}

struct FUN_0063e8f0_shell
{
    unsigned char pad[0x118];
    unsigned int flags;
    void FUN_0063e8f0(bool set);
};

// Sets or clears bit 0x10 in flags; when setting, also zeroes the dword at offset 0x1c.
// @fnv 0x0063e8f0
void FUN_0063e8f0_shell::FUN_0063e8f0(bool set)
{
    if (set)
    {
        *(unsigned int*)((char*)this + 0x1c) = 0;
        flags |= 0x10;
    }
    else
    {
        flags &= ~0x10;
    }
}

namespace fnv_0063b120 {
struct FUN_0063b120_shell : public Sky
{
    void FUN_0063b120();
};

extern const float runtimeFloatSettingDefault40;
extern const float g_011cc6cc_arg1;
extern const float g_011c7200_arg1;
extern const float runtimeFloatSettingDefault538;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting75;
extern SettingT_GameSettingCollection_ g_011ccccc;
extern NiColor DAT_011f4998;

struct FUN_00544890_shell
{
    void FUN_00544890(NiColor*);
    void FUN_005447b0(NiColor*);
    void FUN_00544a30(NiColor*);
};
struct CP_008c48d0
{
    FUN_00544890_shell* GetPrevPath();
};
extern CP_008c48d0* g_TES;

struct FUN_0063b600_shell
{
    void FUN_0063b600(int, void*);
};
struct FUN_00634830_shell
{
    int GetOffset58();
};

struct FUN_0063b630_shell
{
    void FUN_0063b630(void* cb, void* weather, float f, int* t1, int* t2);
    void FUN_0063bab0(void* cb, void* w1, void* w2, int i, int* t1, int* t2);
    void QueryTwoSources(void* cb, void* w1, void* w2, int i, int* t1, int* t2);
    void FUN_0063c690(void* out, void* cb, float flash);
};

struct Sky_COLOR_BLEND
{
    int data[8];
};

// Initialises or blends the sky's colour fields based on the mode at offset 0xf8, copying defaults, path colours, or per-slot blended colours.
// @fnv 0x0063b120
void FUN_0063b120_shell::FUN_0063b120()
{
    if (*(int*)((char*)this + 0xf8) == 0)
    {
        *(NiPoint3*)((char*)this + 0x6c) =
            NiPoint3(g_011cc6cc_arg1, runtimeFloatSettingDefault40, runtimeFloatSettingDefault40);
        *(NiPoint3*)((char*)this + 0x60) = NiPoint3(g_011c7200_arg1, g_011c7200_arg1, runtimeFloatSettingDefault538);
        if (*(void**)((char*)this + 0x2c))
        {
            for (int i = 0; i < (*(FUN_00634830_shell**)((char*)this + 0x2c))->GetOffset58(); i++)
            {
                NiPoint3 Color(0.1f, 0.1f, 0.1f);
                (*(FUN_0063b600_shell**)((char*)this + 0x2c))->FUN_0063b600(i, &Color);
            }
        }
        *(NiColor*)((char*)this + 0x90) = *(NiColor*)((char*)this + 0x48) = *(NiColor*)((char*)this + 0x3c) =
            *(NiColor*)((char*)this + 0x78) = *(NiColor*)((char*)this + 0x9c) = *(NiColor*)((char*)this + 0xc0) =
                DAT_011f4998;
    }
    else if (*(int*)((char*)this + 0xf8) == 1 && g_TES && g_TES->GetPrevPath())
    {
        g_TES->GetPrevPath()->FUN_00544890((NiColor*)((char*)this + 0x6c));
        g_TES->GetPrevPath()->FUN_005447b0((NiColor*)((char*)this + 0x60));
        g_TES->GetPrevPath()->FUN_00544a30((NiColor*)((char*)this + 0x48));
        *(NiColor*)((char*)this + 0x90) = *(NiColor*)((char*)this + 0x3c) = *(NiColor*)((char*)this + 0x78) =
            *(NiColor*)((char*)this + 0x9c) = *(NiColor*)((char*)this + 0xc0) = *(NiColor*)((char*)this + 0x48);
        if (*(void**)((char*)this + 0x2c))
        {
            for (int i = 0; i < (*(FUN_00634830_shell**)((char*)this + 0x2c))->GetOffset58(); i++)
            {
                (*(FUN_0063b600_shell**)((char*)this + 0x2c))->FUN_0063b600(i, (NiColor*)((char*)this + 0x48));
            }
        }
    }
    else
    {
        Sky_COLOR_BLEND cb;
        int aeTime2;
        int aeTime1;
        ((FUN_0063b630_shell*)this)
            ->FUN_0063b630(&cb, *(void**)((char*)this + 0x10), *(float*)((char*)this + 0xf4), &aeTime1, &aeTime2);
        for (int i = 0; i < 10; i++)
        {
            ((FUN_0063b630_shell*)this)
                ->FUN_0063bab0(&cb, *(void**)((char*)this + 0x10), *(void**)((char*)this + 0x14), i, &aeTime1,
                               &aeTime2);
            float fCurrentFlash = 0;
            if (*(void**)((char*)this + 0x14) == 0)
            {
                if (i == 4)
                    fCurrentFlash = *(float*)((char*)this + 0x100) * g_011ccccc.Float()->f;
                else if (i == 3)
                    fCurrentFlash = *(float*)((char*)this + 0x100) * originalRuntimeFloatSetting75.Float()->f;
            }
            ((FUN_0063b630_shell*)this)->FUN_0063c690((NiColor*)((char*)this + 0x3c) + i, &cb, fCurrentFlash);
        }
        if (*(void**)((char*)this + 0x2c))
        {
            for (int i = 0; i < (*(FUN_00634830_shell**)((char*)this + 0x2c))->GetOffset58(); i++)
            {
                ((FUN_0063b630_shell*)this)
                    ->QueryTwoSources(&cb, *(void**)((char*)this + 0x10), *(void**)((char*)this + 0x14), i, &aeTime1,
                                      &aeTime2);
                float fCurrentFlash = 0;
                if (*(void**)((char*)this + 0x14) == 0 && i == 0)
                    fCurrentFlash = *(float*)((char*)this + 0x100);
                NiPoint3 kcolor(0, 0, 0);
                ((FUN_0063b630_shell*)this)->FUN_0063c690(&kcolor, &cb, fCurrentFlash);
                (*(FUN_0063b600_shell**)((char*)this + 0x2c))->FUN_0063b600(i, &kcolor);
            }
        }
        *(NiColor*)((char*)this + 0xc0) = *(NiColor*)((char*)this + 0x6c);
    }
}
}  // namespace fnv_0063b120

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl gm_GetTickCount(void);
struct Host
{
    unsigned int FUN_00639ce0();
    void FUN_00639d00(unsigned int);
    bool FUN_00639c90(unsigned int);
};
// @fnv 0x00639c90
bool Host::FUN_00639c90(unsigned int auiDuration)
{
    unsigned int curTick;
    curTick = gm_GetTickCount();
    {
        unsigned int last;
        last = FUN_00639ce0();
        if (curTick > FUN_0042f5a0(0x80000000, last))
        {
            FUN_00639d00(curTick + auiDuration);
            return true;
        }
        else
        {
            return false;
        }
    }
}

void __cdecl _Deallocate(void*);
struct Cls_0063a080
{
    void FUN_0063a0b0();
    void* FUN_0063a080(unsigned int);
};
// Calls FUN_0063a0b0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0063a080
void* Cls_0063a080::FUN_0063a080(unsigned int flags)
{
    FUN_0063a0b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0063d0e0 {
extern "C" void* __cdecl _alloca(unsigned int);
struct Sky_Helper
{
    void FUN_0063e860(int);
};
struct PC7d
{
    void FUN_0093a7a0(int);
};
extern PC7d* g_thePlayer;
struct FUN_0063d0e0_shell : public Sky
{
    void FUN_0063d0e0(TESWeather* w, bool b);
};
// @fnv 0x0063d0e0
void FUN_0063d0e0_shell::FUN_0063d0e0(TESWeather* apWeather, bool b)
{
    if (b)
    {
        m_pOverrideWeather = apWeather;
        m_pRegionWeather = apWeather;
        m_pQueuedWeather = 0;
    }
    else
    {
        m_pQueuedWeather = apWeather;
        m_pRegionWeather = apWeather;
        m_pOverrideWeather = 0;
    }
    m_pPreviousWeather = 0;
    ((Sky_Helper*)this)->FUN_0063e860(0);
    *(float*)((char*)this + 0xf4) = 1.0f;
    *(float*)((char*)this + 0xf0) = *(float*)((char*)this + 0xec);
    g_thePlayer->FUN_0093a7a0(0);
    flags |= 2;
    flags &= ~1;
    UpdateHDRValues();
    if (m_pClouds)
        m_pClouds->ClearCloudLayers();
    if (m_pPrecipitation)
        m_pPrecipitation->FlushAll();
}
}  // namespace fnv_0063d0e0

struct FUN_0063dd70_shell
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    bool FUN_0063dd70();
};
// @fnv 0x0063dd70
bool FUN_0063dd70_shell::FUN_0063dd70()
{
    return 0 < (m18 & 0x80000000);
}

struct S63cfa0
{
    char _pad[0x38];
    char _items[2][12];
    void* FUN_0063cfa0(int);
};
// Returns a pointer to the item at index a1 if a1 is less than 2, otherwise returns null.
// @fnv 0x0063cfa0
void* S63cfa0::FUN_0063cfa0(int aiIndex)
{
    return aiIndex < 2 ? (void*)_items[aiIndex] : 0;
}

namespace fnv_0063ac70 {
struct FUN_0063ac70_shell : public Sky
{
    void FUN_0063ac70(float);
};

struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct MobileObject
{
    float GetRelevantWaterHeight() const;
};
struct PC7d : public BSOcclusionPlane
{
};
struct Calendar
{
    float GetGameTime();
    unsigned int GetGameDaysPassed();
};
struct AnimIdle
{
    int GetSection();
};
struct NiNode_00558310;
class NiAVObject;
NiNode_00558310* __cdecl FUN_0045c670();
NiAVObject* __fastcall FUN_00558310(NiNode_00558310*);
const NiPoint3& __fastcall FUN_0045bb80(NiAVObject*);
bool __cdecl FUN_006368f0(const Sky*);
struct BGSSaveLoadGame_FUN_0042ce10
{
    bool FUN_0042ce10();
};
struct Precipitation_FUN_00636ed0
{
    void FUN_00636ed0(float);
};
struct FUN_0063ca20_t
{
    void FUN_0063ca20();
};
struct FUN_0063d1d0_t
{
    void FUN_0063d1d0();
};
struct FUN_0063c490_shell
{
    void FUN_0063c490();
};
struct FUN_0063d5e0_t
{
    void FUN_0063d5e0();
};
extern PC7d* g_thePlayer;
extern Calendar g_calendar;
extern AnimIdle g_timeGlobal;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting74;

// @fnv 0x0063ac70
void FUN_0063ac70_shell::FUN_0063ac70(float afSecondsPassed)
{
    AutoMemHelper tempMemContext(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp",
                                 0x1d8);
    bool bnewPhase;

    if (!g_thePlayer->GetCullResult())
        return;

    m_fFogFarDistance = g_calendar.GetGameTime();

    if (g_thePlayer && g_thePlayer->GetCullResult() &&
        FUN_0045bb80(FUN_00558310(FUN_0045c670())).z < ((MobileObject*)g_thePlayer)->GetRelevantWaterHeight())
        flags |= 4;
    else
        flags &= ~4;

    if (eMode == 1 && !((BGSSaveLoadGame_FUN_0042ce10*)g_BGSSaveLoadGame)->FUN_0042ce10())
    {
        UpdateWeatherTransition(afSecondsPassed);
        return;
    }

    ((FUN_0063ca20_t*)this)->FUN_0063ca20();
    if (((BGSSaveLoadGame_FUN_0042ce10*)g_BGSSaveLoadGame)->FUN_0042ce10())
        flags |= 1;
    ((FUN_0063d1d0_t*)this)->FUN_0063d1d0();
    UpdateColors();
    FUN_0063bce0();
    ((FUN_0063c490_shell*)this)->FUN_0063c490();
    ((FUN_0063d5e0_t*)this)->FUN_0063d5e0();

    if (m_pAtmosphere)
        m_pAtmosphere->Update(this, afSecondsPassed);
    if (m_pStars)
        m_pStars->Update(this, afSecondsPassed);
    if (m_pClouds)
        ((SkyObject*)m_pClouds)->Update(this, afSecondsPassed);
    if (m_pSun)
        m_pSun->Update(this, afSecondsPassed);

    if ((flags & 0x20) && field108 < g_calendar.GetGameDaysPassed() ||
        ((BGSSaveLoadGame_FUN_0042ce10*)g_BGSSaveLoadGame)->FUN_0042ce10())
    {
        bnewPhase = FUN_006368f0(this);
        if (m_pPrimaryMoon && bnewPhase && *(unsigned int*)((char*)m_pPrimaryMoon + 0x70) == 0)
            *(unsigned int*)((char*)m_pPrimaryMoon + 0x70) =
                (((BGSSaveLoadGame_FUN_0042ce10*)g_BGSSaveLoadGame)->FUN_0042ce10() != 0) + 1;
        if (m_pSecondaryMoon && bnewPhase && *(unsigned int*)((char*)m_pSecondaryMoon + 0x70) == 0)
            *(unsigned int*)((char*)m_pSecondaryMoon + 0x70) =
                (((BGSSaveLoadGame_FUN_0042ce10*)g_BGSSaveLoadGame)->FUN_0042ce10() != 0) + 1;
        field108 = g_calendar.GetGameDaysPassed();
    }

    if (m_pPrimaryMoon)
        m_pPrimaryMoon->Update(this, afSecondsPassed);
    if (m_pSecondaryMoon)
        m_pSecondaryMoon->Update(this, afSecondsPassed);
    if (m_pPrecipitation)
        ((Precipitation_FUN_00636ed0*)m_pPrecipitation)->FUN_00636ed0(afSecondsPassed);

    if (m_fWeatherFade > 0.0)
        m_fWeatherFade =
            1.0 - (g_timeGlobal.GetSection() - field104) / (originalRuntimeFloatSetting74.Float()->f * 1000.0);
    if (m_fWeatherFade < 0.0)
        m_fWeatherFade = 0.0f;

    Renderer::SetBackgroundColor(m_kSkyColors[1]);
    flags &= ~3;
}
}  // namespace fnv_0063ac70

namespace fnv_0063d5e0 {
struct SkySound
{
    bool HandleCheckTime(int);
    bool IsFlaggedToBeKilled();
    unsigned int GetNextCheck();
    void FlagToKill();
    void SetNextCheck(unsigned int);
    void Play(float);
    void* __vecDelDtor(unsigned int);
    char IdentifierState[12];
    void* m_pWeatherObject;
    int m_iSoundType;
    unsigned int auiFormId;
    unsigned int uiData;
};
typedef char _sizecheck_SkySound[sizeof(SkySound) == 28 ? 1 : -1];
struct FUN_0063d5e0_shell : public Sky
{
    void FUN_0063d5e0();
};

struct SndX
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int uiState;
    bool IsValid();
    bool IsPlaying();
    void Stop();
    void PausePlayback();
};
struct TESWeatherEx
{
    float GetWeatherData(int, float, float);
    unsigned char GetWeatherDataRaw(int);
};
struct SkySoundObj
{
    SndX hSound;
    TESWeatherEx* m_pWeatherObject;
    unsigned int eType;
    unsigned int iSoundFormID;
    ~SkySoundObj();
    bool FUN_0063dd70();
    bool FUN_00639c90(int);
    void FUN_0063dd90();
    void FUN_0063e0d0(float);
};
struct SL
{
    SkySoundObj* m_item;
    SL* m_pkNext;
    SL();
    ~SL();
    SkySoundObj** FUN_006815c0();
    SL* FUN_00726070();
    void AddHead(SkySoundObj**);
    void RemoveAll();
};
struct SkyEx
{
    bool FUN_00634870();
    void FUN_0063ddb0(TESWeather*);
    bool FUN_0063e060(unsigned int, TESWeather*);
};
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
extern unsigned char DAT_011ccb74;
extern bool DAT_011ccd04;
unsigned int DialogueRandom();

// @fnv 0x0063d5e0
void FUN_0063d5e0_shell::FUN_0063d5e0()
{
    SkySoundObj* m_pkActiveSoundList;
    SL* pCurrentNode = (SL*)m_pSkySounds;
    if (DAT_011ccd04)
    {
        SL* pSaveList = new SL;
        SkySoundObj* oldHandle;
        SL* poldHandleNode;
        SL oldHandleList;
        while (pCurrentNode && (m_pkActiveSoundList = *pCurrentNode->FUN_006815c0()))
        {
            if (m_pkActiveSoundList->FUN_0063dd70())
            {
                if (m_pkActiveSoundList->eType == 3)
                    --DAT_011ccb74;
                m_pkActiveSoundList->hSound.PausePlayback();
                delete m_pkActiveSoundList;
            }
            else
            {
                pSaveList->AddHead(&m_pkActiveSoundList);
            }
            pCurrentNode = pCurrentNode->FUN_00726070();
        }
        poldHandleNode = &oldHandleList;
        while (poldHandleNode && (oldHandle = *poldHandleNode->FUN_006815c0()))
        {
            poldHandleNode = poldHandleNode->FUN_00726070();
            if (oldHandle->hSound.IsValid())
            {
                bool bstillInUse = false;
                pCurrentNode = pSaveList;
                while (!bstillInUse && pCurrentNode && (m_pkActiveSoundList = *pCurrentNode->FUN_006815c0()))
                {
                    if (m_pkActiveSoundList->iSoundFormID == oldHandle->iSoundFormID)
                        bstillInUse = true;
                    pCurrentNode = pCurrentNode->FUN_00726070();
                }
                if (!bstillInUse)
                {
                    oldHandle->hSound.PausePlayback();
                    delete oldHandle;
                }
            }
            else
            {
                delete oldHandle;
            }
        }
        oldHandleList.RemoveAll();
        ((SL*)m_pSkySounds)->RemoveAll();
        delete (SL*)m_pSkySounds;
        *(SL**)&m_pSkySounds = pSaveList;
        pCurrentNode = pSaveList;
        DAT_011ccd04 = false;
    }
    if (((SkyEx*)this)->FUN_00634870())
        ((SkyEx*)this)->FUN_0063ddb0(m_pRegionWeather);
    while (pCurrentNode && (m_pkActiveSoundList = *pCurrentNode->FUN_006815c0()))
    {
        if (!m_pkActiveSoundList->hSound.IsValid())
        {
            pCurrentNode = pCurrentNode->FUN_00726070();
            continue;
        }
        if ((eMode == 3 || eMode == 2) && ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather ||
                                           (TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pPreviousWeather))
        {
            float fWeight;
            if (m_pkActiveSoundList->eType == 3)
            {
                if (!m_pkActiveSoundList->hSound.IsPlaying() && m_pkActiveSoundList->FUN_00639c90(30) &&
                    DialogueRandom() % (m_pkActiveSoundList->m_pWeatherObject->GetWeatherDataRaw(10) * DAT_011ccb74) == 0)
                {
                    if ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather)
                    {
                        float fBeginPct = ((TESWeatherEx*)m_pRegionWeather)->GetWeatherData(8, 0.999f, 0.0f);
                        fWeight = m_fWeatherBlend < fBeginPct ? 0.0 : (m_fWeatherBlend - fBeginPct) / (1.0 - fBeginPct);
                    }
                    else
                    {
                        float fEndPct = ((TESWeatherEx*)m_pPreviousWeather)->GetWeatherData(9, 1.0f, 0.001f);
                        fWeight = m_fWeatherBlend < fEndPct ? 1.0 - m_fWeatherBlend / fEndPct : 0.0;
                    }
                    if (fWeight != 0.0)
                    {
                        m_pkActiveSoundList->FUN_0063e0d0(fWeight);
                        m_fWeatherFade = fWeight;
                        field104 = g_timeGlobal.GetSection();
                    }
                }
            }
            else if (1)
            {
                float faltWeight;
                if (m_pkActiveSoundList->eType == 1)
                {
                    float fBeginPct = ((TESWeatherEx*)m_pRegionWeather)->GetWeatherData(6, 0.999f, 0.0f);
                    float fEndPct = m_pPreviousWeather
                                        ? ((TESWeatherEx*)m_pPreviousWeather)->GetWeatherData(7, 1.0f, 0.001f)
                                        : 0.0f;
                    if ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather)
                    {
                        fWeight = m_fWeatherBlend < fBeginPct ? 0.0 : (m_fWeatherBlend - fBeginPct) / (1.0 - fBeginPct);
                        faltWeight = m_fWeatherBlend < fEndPct ? 1.0 - m_fWeatherBlend / fEndPct : 0.0;
                    }
                    else
                    {
                        fWeight = m_fWeatherBlend < fEndPct ? 1.0 - m_fWeatherBlend / fEndPct : 0.0;
                        faltWeight =
                            m_fWeatherBlend < fBeginPct ? 0.0 : (m_fWeatherBlend - fBeginPct) / (1.0 - fBeginPct);
                    }
                }
                else
                {
                    if ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather)
                    {
                        fWeight = m_fWeatherBlend;
                        faltWeight = 1.0f - m_fWeatherBlend;
                    }
                    else
                    {
                        fWeight = 1.0f - m_fWeatherBlend;
                        faltWeight = m_fWeatherBlend;
                    }
                }
                if (!((SkyEx*)this)
                         ->FUN_0063e060(m_pkActiveSoundList->iSoundFormID,
                                        (TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather
                                            ? m_pPreviousWeather
                                            : m_pRegionWeather) ||
                    fWeight >= faltWeight)
                    m_pkActiveSoundList->FUN_0063e0d0(fWeight);
            }
        }
        else
        {
            if (m_pkActiveSoundList->hSound.IsPlaying() &&
                !((SkyEx*)this)
                     ->FUN_0063e060(m_pkActiveSoundList->iSoundFormID,
                                    (TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather ? m_pPreviousWeather
                                                                                                   : m_pRegionWeather))
                m_pkActiveSoundList->hSound.Stop();
            m_pkActiveSoundList->FUN_0063dd90();
            DAT_011ccd04 = true;
        }
        pCurrentNode = pCurrentNode->FUN_00726070();
    }
}
}  // namespace fnv_0063d5e0

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0063e940_shell
{
    unsigned short FUN_0063e940();
};

// @fnv 0x0063e940
unsigned short FUN_0063e940_shell::FUN_0063e940()
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    v += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x5d)
        v += 4;
    v += 4;
    v += 4;
    v += 4;
    v += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x69)
    {
        v += 4;
        v += 4;
    }
    return v;
}

struct FUN_0063bc60_shell
{
    int FUN_0063bc60(int b, int a);
};

// @fnv 0x0063bc60
int FUN_0063bc60_shell::FUN_0063bc60(int iIndex, int a)
{
    int color;
    if (a == 1)
        color = 0x9b9b9b;
    else if (a == 3)
        color = 0x1c140f;
    else if (a == 0)
        color = 0x5b4b46;
    else
        color = 0x6c5953;
    if (*(int*)((char*)this + 0x368) > 0)
    {
        if (iIndex >= *(int*)((char*)this + 0x368))
            iIndex = 0;
        color = *(int*)((char*)this + 0x68 + iIndex * 0x18 + a * 4);
    }
    return color;
}

namespace fnv_0063e9f0 {
class TESSaveLoadGame
{
  public:
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int*, int);
};

class SaveManager : public TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;

struct FUN_0063e9f0_shell
{
    unsigned char pad_00[0x10];
    TESForm* form_10;
    TESForm* form_14;
    TESForm* form_18;
    TESForm* form_1c;
    unsigned char pad_20[0xcc];
    int value_ec;
    int value_f0;
    int value_f4;
    int value_f8;
    unsigned char pad_fc[0x14];
    int value_110;
    unsigned char pad_114[4];
    int value_118;

    void FUN_0063e9f0();
};

// @fnv 0x0063e9f0
void FUN_0063e9f0_shell::FUN_0063e9f0()
{
    int formID = 0;
    if (form_10)
        formID = form_10->GetFormID();
    DAT_011de45c->FUN_00857a10(&formID, 4);

    int formID2 = 0;
    if (form_14)
        formID2 = form_14->GetFormID();
    DAT_011de45c->FUN_00857a10(&formID2, 4);

    int formID3 = 0;
    if (form_18)
        formID3 = form_18->GetFormID();
    DAT_011de45c->FUN_00857a10(&formID3, 4);

    if (DAT_011de45c->FUN_008df040() >= 0x5d)
    {
        int formID4 = 0;
        if (form_1c)
            formID4 = form_1c->GetFormID();
        DAT_011de45c->FUN_00857a10(&formID4, 4);
    }

    DAT_011de45c->FUN_008579b0(&value_ec, 4);
    DAT_011de45c->FUN_008579b0(&value_f0, 4);
    DAT_011de45c->FUN_008579b0(&value_f4, 4);
    DAT_011de45c->FUN_008579b0(&value_f8, 4);

    if (DAT_011de45c->FUN_008df040() >= 0x69)
    {
        DAT_011de45c->FUN_008579b0(&value_118, 4);
        DAT_011de45c->FUN_008579b0(&value_110, 4);
    }
}
}  // namespace fnv_0063e9f0

struct SaveFormIDHelper
{
    void SerializeFormData(void* data, int value);
};

struct BGSSaveFormBuffer : SaveFormIDHelper
{
    void SaveData(void* data, int size, int value);
};

struct FUN_0063eb70_shell
{
    unsigned char pad000[0x10];
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    unsigned char pad020[0x94];
    int mB4;
    int mB8;
    int mBC;
    unsigned char pad0C0[0x24];
    int mE4;
    int mE8;
    int mEC;
    int mF0;
    int mF4;
    int mF8;
    unsigned char pad0FC[0x14];
    int m110;
    unsigned char pad114[4];
    int m118;

    void FUN_0063eb70(BGSSaveFormBuffer* buffer);
};

// @fnv 0x0063eb70
void FUN_0063eb70_shell::FUN_0063eb70(BGSSaveFormBuffer* buffer)
{
    buffer->SerializeFormData(m10, 0);
    buffer->SerializeFormData(m14, 0);
    buffer->SerializeFormData(m18, 0);
    buffer->SerializeFormData(m1c, 0);

    buffer->SaveData(&mEC, 4, 0);
    buffer->SaveData(&mF0, 4, 0);
    buffer->SaveData(&mF4, 4, 0);
    buffer->SaveData(&m118, 4, 0);
    buffer->SaveData(&m110, 4, 0);
    buffer->SaveData(&mB4, 4, 0);
    buffer->SaveData(&mB8, 4, 0);
    buffer->SaveData(&mBC, 4, 0);
    buffer->SaveData(&mE4, 4, 0);
    buffer->SaveData(&mE8, 4, 0);
    buffer->SaveData(&mF8, 4, 0);
}

class ElemC_b9476
{
  public:
    int unk00;
};
class ElemB_b9476
{
  public:
    ElemC_b9476* Resolve();
};
class ElemA_b9476
{
  public:
    int unk00;
    int Test();
    void Clear(int);
    ElemB_b9476* Get(int);
};
class ResultX_b9476
{
  public:
    void SetFlag(int);
    void Scale(float);
};

void* LookupB9476(void*, void*);
extern char DAT_012005b8;

class FUN_00634930_cls
{
  public:
    int CountItems();
    int unk00;
    int unk04;
    ElemA_b9476 m_08[4];
    ElemA_b9476 m_18[4];
    void FUN_00634930();
};

// For each item, clears m_18[i], and if m_08[i] passes Test, looks up its resolved element and resets the result's flag and scale.
// @fnv 0x00634930
void FUN_00634930_cls::FUN_00634930()
{
    for (int i = 0; i < CountItems(); i++)
    {
        m_18[i].Clear(0);
        if (m_08[i].Test())
        {
            ElemC_b9476* c = m_08[i].Get(3)->Resolve();
            ResultX_b9476* r = (ResultX_b9476*)LookupB9476((void*)&DAT_012005b8, c);
            if (r)
            {
                r->SetFlag(0);
                r->Scale(0.0f);
            }
        }
    }
}

class SkySound
{
  public:
    void* field00;
    void* field04;
    void* field08;
    unsigned int field0c;
    void* field10;
    void* field14;
};

SkySound** __fastcall FUN_006815c0(void* node);
void* __fastcall FUN_00726070(void* node);

struct FUN_0063e060_shell
{
    unsigned char pad0[0xfc];
    void* m_pSkySounds;
    bool FUN_0063e060(void* m_pWeatherObject, unsigned int uiType);
};

// @fnv 0x0063e060
bool FUN_0063e060_shell::FUN_0063e060(void* m_pWeatherObject, unsigned int uiType)
{
    for (void* node = m_pSkySounds; node != 0 && *FUN_006815c0(node) != 0; node = FUN_00726070(node))
    {
        if ((*FUN_006815c0(node))->field14 == m_pWeatherObject && (*FUN_006815c0(node))->field0c == uiType)
            return true;
    }
    return false;
}

struct FogVector
{
    float x, y, z;
};
struct FogNode
{
    void FUN_00450f90(bool);
    const FogVector& FUN_0045bb80();
};
struct FogRoot
{
    FogNode* FUN_00559450();
};
struct FogCelestial
{
    FogNode* FUN_005585e0();
    FogNode* FUN_0043b230();
};
struct FogClouds
{
    int GetOffset58();
    FogNode* FUN_0063c440(int);
};
struct FogWeather
{
    float FUN_0063c420(int);
};
struct FogWater
{
    float FUN_004e3d00();
    float FUN_00507b20();
    int FUN_004f9bf0();
    int FUN_009ee040();
};
struct FogCell
{
    float FUN_005471e0();
    float FUN_00544b10();
    float FUN_00544ab0();
    float FUN_00544b70();
};
struct FogPlayer
{
    FogCell* FUN_008d6f30();
};
struct FogEnvironment
{
    FogCell* FUN_005f36f0();
};
struct FogSetting
{
    float* FUN_00403e20();
};
struct FogCamera
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
    virtual float GetFarPlane();
    FogNode* FUN_00558310();
};
struct FogBlend
{
    int colors[4];
    float weights[4];
};
struct FogSky
{
    void* table;
    FogRoot root;
    int unk08, unk0c;
    FogWeather* currentWeather;
    FogWeather* lastWeather;
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
    FogVector waterColor;
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
    float nearDistance, farDistance, unkdc, unke0, unke4, power, hour, unkf0, transition;
    unsigned int mode;
    FogClouds* FUN_0055b980();
    FogCelestial* FUN_007af430();
    FogCelestial* FUN_0045cd60();
    float FUN_0063b9b0();
    float FUN_00595f50();
    float FUN_00595fc0();
    float FUN_0063ba30();
    void FUN_0063c690(FogVector*, FogBlend*, float);
    void FUN_0063bce0();
};
int FUN_0063c470();
bool FUN_004e2180();
bool FUN_004e3c40();
FogCamera* FUN_0045c670();
float FUN_0063c480();
unsigned char FUN_0063c460();
float FUN_0040ebd0(float, float);
extern FogPlayer* DAT_011dea3c;
extern FogEnvironment* DAT_011dea10;
extern float DAT_011ccc60;
extern FogSetting DAT_01203144;
extern const double DAT_01012070, DAT_01011588, DAT_01012060, DAT_0103a480, DAT_0104ee90;
extern const float DAT_010317c4;
// @fnv 0x0063bce0
void FogSky::FUN_0063bce0()
{
    FogWater* water = (FogWater*)FUN_0063c470();
    if (FUN_004e2180() || FUN_004e3c40())
    {
        float height = FUN_0045c670()->FUN_00558310()->FUN_0045bb80().z;
        if (water && (FUN_004e3c40() || height < DAT_011dea3c->FUN_008d6f30()->FUN_005471e0()))
        {
            nearDistance = water->FUN_004e3d00();
            farDistance = water->FUN_00507b20();
            power = 1.0f;
            float level8 = FUN_0063c480();
            if (height < DAT_011dea3c->FUN_008d6f30()->FUN_005471e0())
                level8 = DAT_011dea3c->FUN_008d6f30()->FUN_005471e0();
            float blend8 = (level8 - height) * DAT_011ccc60;
            if (blend8 > DAT_01012070)
                blend8 = 1.0f;
            FogBlend colors4;
            colors4.colors[0] = water->FUN_004f9bf0();
            colors4.colors[1] = water->FUN_009ee040();
            colors4.colors[2] = 0;
            colors4.colors[3] = 0;
            colors4.weights[0] = 1.0f - blend8;
            colors4.weights[1] = blend8;
            colors4.weights[2] = 0.0f;
            colors4.weights[3] = 0.0f;
            FUN_0063c690(&waterColor, &colors4, 0.0f);
            if (mode == 3 || mode == 2)
            {
                bool hidden = blend8 > DAT_01011588;
                for (int i = 0; i < FUN_0055b980()->GetOffset58(); ++i)
                    FUN_0055b980()->FUN_0063c440(i)->FUN_00450f90(hidden);
                FUN_007af430()->FUN_005585e0()->FUN_00450f90(hidden);
                FUN_0045cd60()->FUN_005585e0()->FUN_00450f90(hidden);
                FUN_0045cd60()->FUN_0043b230()->FUN_00450f90(hidden);
                root.FUN_00559450()->FUN_00450f90(hidden);
            }
            return;
        }
    }
    if (currentWeather && (mode == 3 || mode == 2))
    {
        float sunriseStart1411 = FUN_0063b9b0();
        float sunriseEnd119 = FUN_00595f50();
        float sunsetStart2312 = FUN_00595fc0();
        float sunsetEnd544 = FUN_0063ba30();
        float day1270;
        if (hour > sunriseStart1411 && hour < sunriseEnd119)
            day1270 = (hour - sunriseStart1411) / (sunriseEnd119 - sunriseStart1411);
        else if (hour >= sunriseEnd119 && hour <= sunsetStart2312)
            day1270 = 1.0f;
        else if (hour > sunsetStart2312 && hour < sunsetEnd544)
            day1270 = (sunsetEnd544 - hour) / (sunsetEnd544 - sunsetStart2312);
        else
            day1270 = 0.0f;
        float night12 = 1.0f - day1270;
        nearDistance = currentWeather->FUN_0063c420(0) * day1270 + currentWeather->FUN_0063c420(2) * night12;
        farDistance = currentWeather->FUN_0063c420(1) * day1270 + currentWeather->FUN_0063c420(3) * night12;
        power = currentWeather->FUN_0063c420(4) * day1270 + currentWeather->FUN_0063c420(5) * night12;
        if (lastWeather)
        {
            nearDistance *= transition;
            nearDistance +=
                (1.0f - transition) * (lastWeather->FUN_0063c420(0) * day1270 + lastWeather->FUN_0063c420(2) * night12);
            farDistance *= transition;
            farDistance +=
                (1.0f - transition) * (lastWeather->FUN_0063c420(1) * day1270 + lastWeather->FUN_0063c420(3) * night12);
            power *= transition;
            power +=
                (1.0f - transition) * (lastWeather->FUN_0063c420(4) * day1270 + lastWeather->FUN_0063c420(5) * night12);
        }
    }
    else if (mode == 1 && DAT_011dea10 && DAT_011dea10->FUN_005f36f0())
    {
        float farValue4 = DAT_011dea10->FUN_005f36f0()->FUN_00544b10();
        if (farValue4 <= DAT_01012060 || farValue4 > DAT_0103a480)
            farValue4 = DAT_010317c4;
        float nearValue3 = DAT_011dea10->FUN_005f36f0()->FUN_00544ab0();
        if (nearValue3 <= DAT_01012060 || nearValue3 > farValue4)
            nearValue3 = farValue4 * DAT_0104ee90;
        nearDistance = nearValue3;
        farDistance = farValue4;
        power = DAT_011dea10->FUN_005f36f0()->FUN_00544b70();
    }
    else
    {
        nearDistance = DAT_010317c4;
        farDistance = DAT_010317c4;
        power = 1.0f;
    }
    if (!FUN_0063c460())
    {
        float farPlane20 = FUN_0045c670()->GetFarPlane();
        float minimum3 = *DAT_01203144.FUN_00403e20();
        float ratio2 = (farDistance - farPlane20) / (farDistance - minimum3);
        nearDistance = nearDistance - (nearDistance - minimum3) * ratio2;
        farDistance = farPlane20;
        nearDistance = FUN_0040ebd0(farPlane20, nearDistance);
    }
}

namespace SkyAssets {
struct Object;
struct Scene;
struct Texture;
struct Model;
struct String
{
    unsigned int unk0, unk4;
    String();
    ~String();
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
    const char* FUN_00559450();
};
struct Pointer
{
    Object* object;
    Pointer(int);
    ~Pointer();
    Object* FUN_00559450();
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Object
{
    void FUN_00a5a040();
    void FUN_00a59c60(Update*);
};
struct ScenePointer
{
    Object* object;
    Object* FUN_00559450();
};
struct Texture
{
    void FUN_006348e0(Object*);
};
struct Property
{
    Texture* FUN_00a59d30();
};
struct Visible
{
    void FUN_00635fe0(bool);
};
struct Cloud
{
    Property* FUN_006fa820(int);
    Property* FUN_0063d040(int);
    Visible* FUN_005585e0();
    Visible* FUN_0043b230();
};
struct Model
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual const char* Prefix();
    unsigned int FUN_0048cee0();
    const char* FUN_00408da0();
};
struct Weather
{
    void* FUN_0063cfe0();
    Model* FUN_0063cfa0(int);
    bool FUN_0063d000();
    bool FUN_0063d020();
};
struct Atmosphere
{
    void FUN_0063fdb0(void*);
};
struct Particle
{
    virtual ~Particle();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void Attach(Object*, const char*);
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    Particle(const char*, float, float, float, float, float, int);
};
struct Setting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
};
extern Setting DAT_011ccc18;
extern Setting DAT_011ccc54;
extern Setting DAT_011ccbfc;
extern Setting DAT_011ccba4;
extern Setting DAT_011ccc94;
extern Setting DAT_011cccb8;
extern Setting DAT_011cccec;
extern Setting DAT_011ccc7c;
extern Setting DAT_011ccbcc;
extern Setting DAT_011ccc64;
extern Setting DAT_011ccbe8;
extern Setting DAT_011ccb98;
extern bool DAT_011f941e;
extern char DAT_0102d7c4, DAT_0104eeb8, DAT_0104eeb0, DAT_0104eea8;
int FUN_00404dc0(const char*, const char*);
void FUN_00b55840(const char*, int, Pointer*, int, int);
struct Sky
{
    unsigned int unk0;
    ScenePointer scene, root;
    Weather* weather;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Atmosphere* atmosphere;
    Cloud* cloud;
    unsigned int unk2c;
    Particle* rain;
    Particle* snow;
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
    unsigned int unka4;
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
    int mode;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int flags;
    void FUN_0063ca20();
};
// @fnv 0x0063ca20
void Sky::FUN_0063ca20()
{
    if (flags & 0x40)
    {
        if (atmosphere && (mode == 3 || mode == 2))
            atmosphere->FUN_0063fdb0(weather->FUN_0063cfe0());
        if (cloud && (mode == 3 || mode == 2))
        {
            String name;
            Texture* texture = cloud->FUN_006fa820(3)->FUN_00a59d30();
            Object* objectSlot0 = 0;
            Model* modelSlot14 = weather->FUN_0063cfa0(0);
            if (modelSlot14 && modelSlot14->FUN_0048cee0())
            {
                Pointer pointer(0);
                name.FUN_00438390(modelSlot14->Prefix());
                name.FUN_00404820(modelSlot14->FUN_00408da0());
                FUN_00b55840(name.FUN_00559450(), 1, &pointer, 1, 0);
                objectSlot0 = pointer.FUN_00559450();
                if (objectSlot0)
                    texture->FUN_006348e0(objectSlot0);
            }
            cloud->FUN_005585e0()->FUN_00635fe0(objectSlot0 != 0);
            texture = cloud->FUN_0063d040(3)->FUN_00a59d30();
            modelSlot14 = weather->FUN_0063cfa0(1);
            if (modelSlot14 && modelSlot14->FUN_0048cee0())
            {
                if (!DAT_011f941e && !FUN_00404dc0(modelSlot14->FUN_00408da0(), &DAT_0102d7c4))
                    name.FUN_00438390(&DAT_0104eeb8);
                else
                {
                    name.FUN_00438390(modelSlot14->Prefix());
                    name.FUN_00404820(modelSlot14->FUN_00408da0());
                }
                Pointer pointer2(0);
                FUN_00b55840(name.FUN_00559450(), 1, &pointer2, 1, 0);
                objectSlot0 = pointer2.FUN_00559450();
                if (objectSlot0)
                    texture->FUN_006348e0(objectSlot0);
            }
            cloud->FUN_0043b230()->FUN_00635fe0(objectSlot0 != 0);
        }
        if (weather->FUN_0063d000() && !rain)
        {
            rain = new Particle(&DAT_0104eeb0, *DAT_011cccb8.FUN_00403e20(), *DAT_011ccc94.FUN_00403e20(),
                                *DAT_011ccba4.FUN_00403e20(), *DAT_011ccbfc.FUN_00403e20(),
                                *DAT_011ccc54.FUN_00403e20(), *DAT_011ccc18.FUN_0043d4d0());
            rain->Attach(root.FUN_00559450(), &DAT_0104eeb0);
        }
        else if (!weather->FUN_0063d000())
        {
            delete rain;
            rain = 0;
        }
        if (weather->FUN_0063d020() && !snow)
        {
            snow = new Particle(&DAT_0104eea8, *DAT_011ccb98.FUN_00403e20(), *DAT_011ccbe8.FUN_00403e20(),
                                *DAT_011ccc64.FUN_00403e20(), *DAT_011ccbcc.FUN_00403e20(),
                                *DAT_011ccc7c.FUN_00403e20(), *DAT_011cccec.FUN_0043d4d0());
            snow->Attach(root.FUN_00559450(), &DAT_0104eea8);
        }
        else if (!weather->FUN_0063d020())
        {
            delete snow;
            snow = 0;
        }
        scene.FUN_00559450()->FUN_00a5a040();
        Update update(0.0f, 0, 0);
        scene.FUN_00559450()->FUN_00a59c60(&update);
        flags &= ~0x40;
    }
}
}

bool FUN_00702360();
bool FUN_00705ea0();
struct BSAudio;
BSAudio* FUN_00453a70();
struct BSSoundHandleEx
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    ~BSSoundHandleEx();
};
struct FUN_00ad73b0_t
{
    BSSoundHandleEx FUN_00ad73b0(const char* apName, unsigned int auiFlags);
};
struct BSStr
{
    operator const char*() const;
};
struct SndX
{
    bool IsValid();
};
struct SH_00418890
{
    void FUN_copy(const void* apHandle);
};
struct FUN_00ad8830_shell
{
    bool Play(bool abFlag);
};
struct FUN_00ad8a20
{
    float Op();
};
struct FUN_00ad89e0_shell
{
    bool FUN_00ad89e0(float afVolume);
};
struct std
{
    static float __cdecl abs(float afValue);
};
struct FUN_0063e0d0_shell
{
    char pad[0x10];
    int iState;
    bool FUN_00ad8930();
    void FUN_0063e0d0(float afVolume);
};
// @fnv 0x0063e0d0
void FUN_0063e0d0_shell::FUN_0063e0d0(float afVolume)
{
    if (!FUN_00702360() && !FUN_00705ea0())
    {
        if (!((SndX*)this)->IsValid())
        {
            const char* pName = *(BSStr*)this;
            BSSoundHandleEx kSound = ((FUN_00ad73b0_t*)FUN_00453a70())->FUN_00ad73b0(pName, 0x20);
            ((SH_00418890*)this)->FUN_copy(&kSound);
        }
        if (iState == 3)
        {
            if (!FUN_00ad8930())
                ((FUN_00ad8830_shell*)this)->Play(false);
        }
        else if (((Host*)this)->FUN_00639c90(1000))
        {
            if (!FUN_00ad8930())
                ((FUN_00ad8830_shell*)this)->Play(true);
        }
        if (std::abs(((FUN_00ad8a20*)this)->Op() - afVolume) > (double)0.01f)
            ((FUN_00ad89e0_shell*)this)->FUN_00ad89e0(afVolume);
    }
}

class Texture139;
class Property139
{
  public:
    void FUN_006348e0(Texture139*);
};
class Node139
{
  public:
    Property139* FUN_00a59d30(unsigned int);
    void FUN_00635fe0(bool);
};
class Model139
{
  public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual const char* Path();
    int FUN_0048cee0();
    const char* FUN_00408da0();
};
class Weather139
{
  public:
    Model139* FUN_006347a0(int);
};
class Clouds139
{
  public:
    int GetOffset58();
    Node139* FUN_0063c440(int);
};
class Moon139
{
  public:
    int unk00, unk04, unk08, unk0c, unk10;
    NiPointer<Node139> node;
    int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54,
        unk58, unk5c, unk60, unk64, unk68, unk6c;
    int phase;
};
class Sun139
{
  public:
    Node139* FUN_006fa820();
    Node139* FUN_005585e0();
    Node139* FUN_0063d040();
    Node139* FUN_0043b230();
};
class Climate139
{
  public:
    Model139* FUN_0063cfa0(int);
    int FUN_0063cfe0();
};
class Stars139
{
  public:
    void FUN_0063fdb0(int);
};
class Save139
{
  public:
    bool FUN_0042ce10();
};
class Append139
{
  public:
    void FUN_00404820(const char*);
};
int __cdecl FUN_00406f60(BSStringT<char>*, const char*, ...);
int __cdecl FUN_00456a20(const char*, char*, unsigned int, unsigned int);
void __cdecl FUN_00b55840(const char*, bool, NiPointer<Texture139>&, bool, bool);
int __cdecl FUN_00404dc0(const char*, const char*);
extern unsigned char DAT_011f941e;
struct FUN_0063e2f0_shell : Sky
{
    void FUN_0063e2f0();
};
// @fnv 0x0063e2f0
void FUN_0063e2f0_shell::FUN_0063e2f0()
{
    AutoMemContext mem(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp", 2268);
    if (m_pClouds && m_pRegionWeather && !((Save139*)g_BGSSaveLoadGame)->FUN_0042ce10())
    {
        for (int i = 0; i < ((Clouds139*)m_pClouds)->GetOffset58(); i++)
        {
            if (((Weather139*)m_pRegionWeather)->FUN_006347a0(i) &&
                ((Weather139*)m_pRegionWeather)->FUN_006347a0(i)->FUN_0048cee0())
            {
                BSStringT<char> path;
                FUN_00406f60(&path, "%s%s", ((Weather139*)m_pRegionWeather)->FUN_006347a0(i)->Path(),
                             ((Weather139*)m_pRegionWeather)->FUN_006347a0(i)->FUN_00408da0());
                if (FUN_00456a20(path.String(), 0, 0, -1) && ((Clouds139*)m_pClouds)->FUN_0063c440(i)->FUN_00a59d30(5))
                {
                    NiPointer<Texture139> texture(0);
                    FUN_00b55840(path.String(), true, texture, true, false);
                    ((Clouds139*)m_pClouds)->FUN_0063c440(i)->FUN_00a59d30(3)->FUN_006348e0(texture);
                }
            }
        }
    }
    if (m_pPrimaryMoon)
    {
        Property139* ptr = ((Moon139*)m_pPrimaryMoon)->node->FUN_00a59d30(3);
        NiPointer<Texture139> prop(0);
        FUN_00b55840("Textures\\Sky\\MoonShadow.dds", true, prop, true, false);
        Texture139* tex = prop;
        if (tex)
            ptr->FUN_006348e0(tex);
        ((Moon139*)m_pPrimaryMoon)->node->FUN_00635fe0(tex != 0);
        ((Moon139*)m_pPrimaryMoon)->phase = 2;
    }
    if (m_pSecondaryMoon)
    {
        Property139* ptr = ((Moon139*)m_pSecondaryMoon)->node->FUN_00a59d30(3);
        NiPointer<Texture139> prop(0);
        FUN_00b55840("Textures\\Sky\\MoonShadow.dds", true, prop, true, false);
        Texture139* tex = prop;
        if (tex)
            ptr->FUN_006348e0(tex);
        ((Moon139*)m_pSecondaryMoon)->node->FUN_00635fe0(tex != 0);
        ((Moon139*)m_pSecondaryMoon)->phase = 2;
    }
    if (m_pSun && m_pCurrentClimate)
    {
        BSStringT<char> path;
        Property139* ptr = ((Sun139*)m_pSun)->FUN_006fa820()->FUN_00a59d30(3);
        Texture139* tex = 0;
        NiPointer<Texture139> prop(0);
        Model139* model = ((Climate139*)m_pCurrentClimate)->FUN_0063cfa0(0);
        if (model && model->FUN_0048cee0())
        {
            path = model->Path();
            ((Append139*)&path)->FUN_00404820(model->FUN_00408da0());
            FUN_00b55840(path.String(), true, prop, true, false);
            tex = prop;
            if (tex)
                ptr->FUN_006348e0(tex);
        }
        ((Sun139*)m_pSun)->FUN_005585e0()->FUN_00635fe0(tex != 0);
        ptr = ((Sun139*)m_pSun)->FUN_0063d040()->FUN_00a59d30(3);
        model = ((Climate139*)m_pCurrentClimate)->FUN_0063cfa0(0);
        if (model && model->FUN_0048cee0())
        {
            if (!DAT_011f941e && !FUN_00404dc0(model->FUN_00408da0(), "Sky\\SunGlare.dds"))
                path = "Textures\\Sky\\SunGlareNonHDR.dds";
            else
            {
                path = model->Path();
                ((Append139*)&path)->FUN_00404820(model->FUN_00408da0());
            }
            NiPointer<Texture139> glare(0);
            FUN_00b55840(path.String(), true, glare, true, false);
            tex = glare;
            if (tex)
                ptr->FUN_006348e0(tex);
        }
        ((Sun139*)m_pSun)->FUN_0043b230()->FUN_00635fe0(tex != 0);
    }
    if (m_pStars && m_pCurrentClimate)
        ((Stars139*)m_pStars)->FUN_0063fdb0(((Climate139*)m_pCurrentClimate)->FUN_0063cfe0());
}

namespace fnv_0063ef20 {
struct TESObjectDoorController
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct ImageSpaceModifierInstanceDOF : public TESObjectDoorController
{
    int f00;
    int f04;
    unsigned char f08;
    unsigned char f09;
    unsigned char f0a;
    unsigned char f0b;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    ImageSpaceModifierInstanceDOF();
    void FUN_005bbd60(bool);
    void FUN_0063f790(float);
    void FUN_0050f9a0(void*);
};

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
};

struct ListX
{
    void FUN_00631540(const GlobalObject_00633c90&);
};
struct TESX
{
    ListX* FUN_0043b5d0();
};
extern TESX* DAT_011dea10;

struct WeatherSub
{
    void* FUN_005822a0(int);
};
struct WeatherX
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    WeatherSub sub18;
};

void* __cdecl FUN_00532ff0();
float __fastcall FUN_00595f50(Sky*);
float __fastcall FUN_00595fc0(Sky*);
void __cdecl FNV_Warning(const char*, ...);
extern char DAT_0104ee38;

struct FUN_0063ef20_shell : public Sky
{
    void FUN_0063ef20();
};
// @fnv 0x0063ef20
void FUN_0063ef20_shell::FUN_0063ef20()
{
    float tmp;
    float y;
    unsigned long which5;
    float val;
    float tB;
    {
        float pct3;
        void* _res;
        int dVal;
        {
            float s;
            bool p;
            float idx;
            float q;
            float d3_2;
            float mid3;
            float pForm;
            if (field11c == 0)
            {
                field11c = new ImageSpaceModifierInstanceDOF;
                field124 = new ImageSpaceModifierInstanceDOF;
                DAT_011dea10->FUN_0043b5d0()->FUN_00631540((int)field124);
                DAT_011dea10->FUN_0043b5d0()->FUN_00631540((int)field11c);
                field120 = new ImageSpaceModifierInstanceDOF;
                field128 = new ImageSpaceModifierInstanceDOF;
                DAT_011dea10->FUN_0043b5d0()->FUN_00631540((int)field128);
                DAT_011dea10->FUN_0043b5d0()->FUN_00631540((int)field120);
                ((ImageSpaceModifierInstanceDOF*)field11c)->FUN_005bbd60(true);
                ((ImageSpaceModifierInstanceDOF*)field124)->FUN_005bbd60(true);
                ((ImageSpaceModifierInstanceDOF*)field120)->FUN_005bbd60(true);
                ((ImageSpaceModifierInstanceDOF*)field128)->FUN_005bbd60(true);
                ((ImageSpaceModifierInstanceDOF*)field11c)->f08 = 1;
                ((ImageSpaceModifierInstanceDOF*)field124)->f08 = 1;
                ((ImageSpaceModifierInstanceDOF*)field120)->f08 = 1;
                ((ImageSpaceModifierInstanceDOF*)field128)->f08 = 1;
            }
            if (eMode == 1 || eMode == 0)
            {
                ((ImageSpaceModifierInstanceDOF*)field11c)->FUN_0063f790(0.0f);
                ((ImageSpaceModifierInstanceDOF*)field120)->FUN_0063f790(0.0f);
                ((ImageSpaceModifierInstanceDOF*)field124)->FUN_0063f790(0.0f);
                ((ImageSpaceModifierInstanceDOF*)field128)->FUN_0063f790(0.0f);
            }
            else
            {
                which5 = 0;
                p = false;
                tmp = 1.0f;
                val = ((FUN_0063b9b0_shell*)this)->FUN_0063b9b0();
                tB = FUN_00595f50(this);
                y = FUN_00595fc0(this);
                pct3 = ((FUN_0063ba30_shell*)this)->FUN_0063ba30();
                if (m_fFogFarDistance > val && m_fFogFarDistance < tB)
                {
                    p = true;
                    dVal = 0;
                    idx = (tB - val) * 0.5;
                    s = val + idx;
                    if (m_fFogFarDistance < s)
                    {
                        tmp = 1.0f - (s - m_fFogFarDistance) / idx;
                        which5 = 3;
                    }
                    else
                    {
                        tmp = 1.0f - (m_fFogFarDistance - s) / idx;
                        which5 = 1;
                    }
                }
                else if (m_fFogFarDistance > tB && m_fFogFarDistance < field12c)
                {
                    p = true;
                    dVal = 1;
                    which5 = 4;
                    q = field12c - tB;
                    tmp = 1.0f - (field12c - m_fFogFarDistance) / q;
                }
                else if (field12c < m_fFogFarDistance && m_fFogFarDistance < y)
                {
                    p = true;
                    dVal = 4;
                    which5 = 1;
                    pForm = y - field12c;
                    tmp = 1.0f - (y - m_fFogFarDistance) / pForm;
                }
                else if (m_fFogFarDistance > y && m_fFogFarDistance < pct3)
                {
                    p = true;
                    dVal = 2;
                    d3_2 = (pct3 - y) * 0.5;
                    mid3 = y + d3_2;
                    if (m_fFogFarDistance < mid3)
                    {
                        tmp = 1.0f - (mid3 - m_fFogFarDistance) / d3_2;
                        which5 = 1;
                    }
                    else
                    {
                        tmp = 1.0f - (m_fFogFarDistance - mid3) / d3_2;
                        which5 = 3;
                    }
                }
                else
                {
                    if (m_fFogFarDistance >= pct3 || m_fFogFarDistance <= val)
                    {
                        dVal = 3;
                    }
                    else
                    {
                        FNV_Warning(
                            "MASTERFILE: Data error detected--Transition times stored in climate data are invalid.");
                        dVal = 1;
                    }
                }
                _res = 0;
                if (0 != m_pRegionWeather)
                {
                    _res = ((WeatherX*)m_pRegionWeather)->sub18.FUN_005822a0(dVal);
                }
                if (!_res)
                {
                    _res = FUN_00532ff0();
                }
                if (!!_res)
                {
                    ((ImageSpaceModifierInstanceDOF*)field11c)->FUN_0063f790(m_fWeatherBlend * tmp);
                    ((ImageSpaceModifierInstanceDOF*)field11c)->FUN_0050f9a0(_res);
                }
                if (p)
                {
                    _res = 0;
                    if (0 != m_pRegionWeather)
                    {
                        _res = ((WeatherX*)m_pRegionWeather)->sub18.FUN_005822a0(which5);
                    }
                    if (_res == 0)
                    {
                        _res = FUN_00532ff0();
                    }
                    if (0 != _res)
                    {
                        ((ImageSpaceModifierInstanceDOF*)field120)->FUN_0063f790((1.0f - tmp) * m_fWeatherBlend);
                        ((ImageSpaceModifierInstanceDOF*)field120)->FUN_0050f9a0(_res);
                    }
                }
                else
                {
                    ((ImageSpaceModifierInstanceDOF*)field120)->FUN_0063f790(0.0f);
                }
                if (m_pPreviousWeather != 0 && m_fWeatherBlend < 1.0)
                {
                    _res = 0;
                    _res = ((WeatherX*)m_pPreviousWeather)->sub18.FUN_005822a0(dVal);
                    if (0 == _res)
                    {
                        _res = FUN_00532ff0();
                    }
                    if (0 != _res)
                    {
                        ((ImageSpaceModifierInstanceDOF*)field124)->FUN_0063f790((1.0f - m_fWeatherBlend) * tmp);
                        ((ImageSpaceModifierInstanceDOF*)field124)->FUN_0050f9a0(_res);
                    }
                    if (p)
                    {
                        _res = 0;
                        _res = ((WeatherX*)m_pPreviousWeather)->sub18.FUN_005822a0(which5);
                        if (_res == 0)
                        {
                            _res = FUN_00532ff0();
                        }
                        if (!!_res)
                        {
                            ((ImageSpaceModifierInstanceDOF*)field128)
                                ->FUN_0063f790((1.0f - m_fWeatherBlend) * (1.0f - tmp));
                            ((ImageSpaceModifierInstanceDOF*)field128)->FUN_0050f9a0(_res);
                        }
                    }
                    else
                    {
                        ((ImageSpaceModifierInstanceDOF*)field128)->FUN_0063f790(0.0f);
                    }
                }
                else
                {
                    ((ImageSpaceModifierInstanceDOF*)field124)->FUN_0063f790(0.0f);
                    ((ImageSpaceModifierInstanceDOF*)field128)->FUN_0063f790(0.0f);
                }
            }
        }
    }
}
}  // namespace fnv_0063ef20

struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011ccb8c;
extern unsigned char DAT_011ccb74;

struct GlobalObject_0041a250
{
    int m00;
    unsigned char m04;
    int m08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    GlobalObject_0041a250(const GlobalObject_0041a250&);
    void FUN_copy(const void*);
    bool FUN_00ad8d10();
};

struct BSAudio
{
    GlobalObject_0041a250 FUN_00ad73b0(int, int);
};
BSAudio* __cdecl FUN_00453a70();

struct Entry
{
    int m00;
    int m04;
};

struct ParamObj
{
    BSSimpleList<Entry*>* FUN_0063dff0();
};

struct NodeObj
{
    GlobalObject_0041a250 m_handle;
    ParamObj* m0c;
    int m10;
    int m14;
    int m18;
    NodeObj(GlobalObject_0041a250, ParamObj*, int, int);
};

struct NodeList
{
    NodeObj*& GetItem();
    NodeList* GetNext();
    void AddHead(NodeObj* const& item);
};

struct ThisCls
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    int mac;
    int mb0;
    int mb4;
    int mb8;
    int mbc;
    int mc0;
    int mc4;
    int mc8;
    int mcc;
    int md0;
    int md4;
    int md8;
    int mdc;
    int me0;
    int me4;
    int me8;
    int mec;
    int mf0;
    int mf4;
    int mf8;
    NodeList* m_fc;
    void FUN_0063ddb0(ParamObj* arg);
};

// @fnv 0x0063ddb0
void ThisCls::FUN_0063ddb0(ParamObj* pParamObj)
{
    if (!pParamObj)
        return;

    Entry* pItem_2;
    BSSimpleList<Entry*>* iter1 = pParamObj->FUN_0063dff0();
    while (iter1 && (pItem_2 = iter1->GetItem()))
    {
        GlobalObject_0041a250 sound;
        int flags7;
        if (g_011ccb8c.Bool()->b || pItem_2->m04 != 1)
        {
            flags7 = 0x21;
            if (pItem_2->m04 != 3)
                flags7 |= 0x10;
            sound.FUN_copy(&FUN_00453a70()->FUN_00ad73b0(pItem_2->m00, flags7));
        }

        bool found2 = false;
        NodeObj* node6;
        for (NodeList* iter7 = m_fc; !found2 && iter7 && (node6 = iter7->GetItem()); iter7 = iter7->GetNext())
        {
            found2 = (node6->m14 == pItem_2->m00 && node6->m0c == pParamObj && node6->m10 == pItem_2->m04);
        }
        if (!found2)
        {
            m_fc->AddHead(new NodeObj(sound, pParamObj, pItem_2->m04, pItem_2->m00));
            if (pItem_2->m04 == 3)
                DAT_011ccb74++;
        }
        else
        {
            sound.FUN_00ad8d10();
        }
        iter1 = iter1->GetNext();
    }
}

namespace fnv_0063b630 {
struct SkyInterpolationData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float weight1;
    float weight2;
    float weight3;
    float weight4;
};

struct FUN_0063b9b0_shell
{
    float FUN_0063b9b0();
};

struct FUN_0063ba30_shell
{
    float FUN_0063ba30();
};

void FNV_Warning(const char*);

class SkyHelper : public Sky
{
  public:
    float FUN_00595f50();
    float FUN_00595fc0();
    void FUN_0063b630(SkyInterpolationData* pData, TESWeather* m_pWeatherObject, float fPct, int* pPhase, int* pNextPhase);
};

// @fnv 0x0063b630
void SkyHelper::FUN_0063b630(SkyInterpolationData* pData, TESWeather* m_pWeatherObject, float fPct, int* pPhase,
                             int* pNextPhase)
{
    if (!m_pWeatherObject)
        return;

    float _fSunset;
    float fDayX;
    float fSunrise4;
    float fNight3;
    float midSunriseDay8;
    float halfSunriseDay2;
    float spanDayMid_2;
    float spanMidSunset3;
    float midSunsetNight4;
    float halfSunsetNight5;

    fSunrise4 = reinterpret_cast<FUN_0063b9b0_shell*>(this)->FUN_0063b9b0();
    fDayX = FUN_00595f50();
    _fSunset = FUN_00595fc0();
    fNight3 = reinterpret_cast<FUN_0063ba30_shell*>(this)->FUN_0063ba30();

    if (m_fFogFarDistance > fSunrise4 && m_fFogFarDistance < fDayX)
    {
        *pPhase = 0;
        halfSunriseDay2 = (fDayX - fSunrise4) * 0.5;
        midSunriseDay8 = fSunrise4 + halfSunriseDay2;
        if (m_fFogFarDistance < midSunriseDay8)
        {
            pData->weight1 = 1.0f - (midSunriseDay8 - m_fFogFarDistance) / halfSunriseDay2;
            *pNextPhase = 3;
        }
        else
        {
            pData->weight1 = 1.0f - (m_fFogFarDistance - midSunriseDay8) / halfSunriseDay2;
            *pNextPhase = 1;
        }
    }
    else if (m_fFogFarDistance >= fDayX && m_fFogFarDistance <= field12c)
    {
        *pNextPhase = 1;
        *pPhase = 4;
        spanDayMid_2 = field12c - fDayX;
        pData->weight1 = 1.0f - (field12c - m_fFogFarDistance) / spanDayMid_2;
    }
    else if (field12c <= m_fFogFarDistance && m_fFogFarDistance <= _fSunset)
    {
        *pNextPhase = 4;
        *pPhase = 1;
        spanMidSunset3 = _fSunset - field12c;
        pData->weight1 = 1.0f - (_fSunset - m_fFogFarDistance) / spanMidSunset3;
    }
    else if (m_fFogFarDistance > _fSunset && m_fFogFarDistance < fNight3)
    {
        *pPhase = 2;
        halfSunsetNight5 = (fNight3 - _fSunset) * 0.5;
        midSunsetNight4 = _fSunset + halfSunsetNight5;
        if (m_fFogFarDistance < midSunsetNight4)
        {
            pData->weight1 = 1.0f - (midSunsetNight4 - m_fFogFarDistance) / halfSunsetNight5;
            *pNextPhase = 1;
        }
        else
        {
            pData->weight1 = 1.0f - (m_fFogFarDistance - midSunsetNight4) / halfSunsetNight5;
            *pNextPhase = 3;
        }
    }
    else if (m_fFogFarDistance >= fNight3 || m_fFogFarDistance <= fSunrise4)
    {
        *pNextPhase = 3;
        *pPhase = 3;
        pData->weight1 = 1.0f;
    }
    else
    {
        FNV_Warning("MASTERFILE: Data error detected--Transition times stored in climate data are invalid.");
        *pNextPhase = 1;
        *pPhase = 1;
        pData->weight1 = 1.0f;
    }

    pData->weight2 = 1.0f - pData->weight1;
    pData->weight3 = pData->weight1;
    pData->weight4 = pData->weight2;
    pData->weight1 = pData->weight1 * m_fWeatherBlend;
    pData->weight2 = pData->weight2 * m_fWeatherBlend;
    pData->weight3 = (1.0f - m_fWeatherBlend) * pData->weight3;
    pData->weight4 = (1.0f - m_fWeatherBlend) * pData->weight4;
}
}  // namespace fnv_0063b630

struct SetHelper
{
    float x, y, z;
    NiPoint3* Set(float a, float b, float c);
};

union CU
{
    unsigned int u;
    unsigned short w;
};

struct SkyColors
{
    CU c[4];
    float f[4];
};

struct Wx
{
    float GetWeatherData(int idx, float a, float b);
};

struct Sh63c8a0
{
    void* FUN_0063c8a0(NiPoint3* p);
};

struct ShA69690
{
    void FUN_00a69690();
};

float __cdecl FUN_0040ebd0(float a, float b);
void __cdecl FUN_005330e0(float* p, float lo, float hi);

struct FUN_0063c690_shell
{
    char pad[0x10];
    Wx* m_pWeatherObject;
    void FUN_0063c690(float* out, SkyColors* sc, float t);
};

// @fnv 0x0063c690
void FUN_0063c690_shell::FUN_0063c690(float* afOutRgb, SkyColors* pSkyColors, float t)
{
    float r = 0.0f;
    for (int i = 0; i < 4; i++)
        r += (float)(unsigned char)(pSkyColors->c[i].u & 0xff) * pSkyColors->f[i];
    afOutRgb[0] = r * (1.0f / 255.0f);
    r = 0.0f;
    for (int i = 0; i < 4; i++)
        r += (float)(unsigned char)((pSkyColors->c[i].w >> 8) & 0xff) * pSkyColors->f[i];
    afOutRgb[1] = r * (1.0f / 255.0f);
    r = 0.0f;
    for (int i = 0; i < 4; i++)
        r += (float)(unsigned char)((pSkyColors->c[i].u >> 16) & 0xff) * pSkyColors->f[i];
    afOutRgb[2] = r * (1.0f / 255.0f);
    t = FUN_0040ebd0(1.0f, t);
    if (t > 0.0)
    {
        SetHelper sh;
        ((Sh63c8a0*)afOutRgb)->FUN_0063c8a0(sh.Set(t, t, t));
        if (this->m_pWeatherObject)
        {
            FUN_005330e0(afOutRgb, 0.0f, this->m_pWeatherObject->GetWeatherData(0xc, 1.0f, 0.0f));
            FUN_005330e0(afOutRgb + 1, 0.0f, this->m_pWeatherObject->GetWeatherData(0xd, 1.0f, 0.0f));
            FUN_005330e0(afOutRgb + 2, 0.0f, this->m_pWeatherObject->GetWeatherData(0xe, 1.0f, 0.0f));
            return;
        }
    }
    ((ShA69690*)afOutRgb)->FUN_00a69690();
}

class ClimateWeather : public TESClimate
{
  public:
    unsigned char FUN_00451cd0();
    TESWeather* FUN_0063d5c0();
};
class WeatherValues : public TESWeather
{
  public:
    float GetWeatherData(int, float, float);
};
class WeatherRegion
{
  public:
    void FUN_004f1050();
};
class TESRegionList : public BSSimpleList<WeatherRegion*>
{
  public:
    virtual ~TESRegionList();
};
class WeatherDataHandler : public TESDataHandler
{
  public:
    TESRegionList* FUN_004169d0();
};
extern WeatherDataHandler* g_dataHandler;
class WeatherCell
{
  public:
    TESWeather* FUN_0059bb30();
};
class PlayerCharacter
{
  public:
    WeatherCell* FUN_005454d0();
};
extern PlayerCharacter* g_thePlayer;
class SaveWeatherState : public BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting71;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting72;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting73;
TESForm* LookupFormByID(unsigned int);
class SkyWeatherUpdate : public Sky
{
  public:
    void FUN_0063d1d0();
    void FUN_0063e860(bool);
};

// Selects the current weather from the climate, cell or override, updates transition state and fade, and refreshes HDR values.
// @fnv 0x0063d1d0
void SkyWeatherUpdate::FUN_0063d1d0()
{
    if (!m_pCurrentClimate)
        return;
    if ((flags & 1) || !m_pQueuedWeather ||
        ((m_fFogFarDistance + (m_fFogFarDistance < fWeatherChance ? 24 : 0) - fWeatherChance) >
             1.0 + (255 - static_cast<ClimateWeather*>(m_pCurrentClimate)->FUN_00451cd0()) * 22 * (1.0f / 255.0f) &&
         !m_pPreviousWeather))
    {
        m_pQueuedWeather = static_cast<ClimateWeather*>(m_pCurrentClimate)->FUN_0063d5c0();
        if (!m_pQueuedWeather)
            m_pQueuedWeather = dynamic_cast<TESWeather*>(LookupFormByID(0x15e));
        BSSimpleList<WeatherRegion*>* region = g_dataHandler->FUN_004169d0();
        while (region && region->GetItem())
        {
            region->GetItem()->FUN_004f1050();
            region = region->GetNext();
        }
    }
    bool useDefault = m_pOverrideWeather == 0;
    if (m_pRegionWeather && static_cast<SaveWeatherState*>(g_BGSSaveLoadGame)->FUN_0042ce10())
        useDefault = false;
    TESWeather* p = 0;
    if (useDefault)
    {
        p = m_pQueuedWeather;
        WeatherCell* cell = g_thePlayer->FUN_005454d0();
        if (cell && cell->FUN_0059bb30() && eMode != 2)
            p = cell->FUN_0059bb30();
    }
    else
    {
        p = m_pOverrideWeather;
    }
    if (p && (!m_pPreviousWeather || (flags & 0x10)) && p != m_pRegionWeather)
    {
        if ((flags & 0x10) || eMode == 1)
        {
            m_pPreviousWeather = 0;
            if (m_pPrecipitation)
                m_pPrecipitation->FlushAll();
        }
        else
        {
            m_pPreviousWeather = m_pRegionWeather;
        }
        m_pRegionWeather = p;
        if (!static_cast<SaveWeatherState*>(g_BGSSaveLoadGame)->FUN_0042ce10())
            fWeatherChance = m_fFogFarDistance;
        flags |= 1;
    }
    else
    {
        flags &= ~1;
    }
    if (!m_pRegionWeather)
    {
        m_fWeatherBlend = 0.0f;
    }
    else if (!m_pPreviousWeather)
    {
        m_fWeatherBlend = 1.0f;
    }
    else
    {
        m_fWeatherBlend =
            (m_fFogFarDistance + (m_fFogFarDistance < fWeatherChance ? 24 : 0) - fWeatherChance) /
            static_cast<WeatherValues*>(m_pRegionWeather)
                ->GetWeatherData(3, originalRuntimeFloatSetting71.Float()->f, originalRuntimeFloatSetting72.Float()->f);
    }
    if (flags & 8)
        m_fWeatherBlend = (m_fWeatherBlend - field110) * (1.0 + originalRuntimeFloatSetting73.Float()->f) + field110;
    if (m_fWeatherBlend > 1.0)
    {
        m_pPreviousWeather = 0;
        m_fWeatherBlend = 1.0f;
        FUN_0063e860(false);
    }
    UpdateHDRValues();
}

namespace fnv_0063a630 {
struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011ccb8c;
extern unsigned char DAT_011f426c;
extern bool DAT_011F941E;
extern float DAT_011ad87c, DAT_011ad880;
class NiAlphaProperty;
class NiNode
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual void vfn_94();
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
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AttachChildInAvailableSlot(NiNode*, bool);
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void InsertChild(NiNode*);
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiNode(unsigned short);
    NiNode* FUN_009611e0();
    void FUN_005468d0(bool);
    void FUN_004902f0(bool);
    void FUN_00440460(const void*);
    void FUN_00439410(NiAlphaProperty*);
    void FUN_00a5a040();
};
class FUN_00c46970 : public NiNode
{
  public:
    int mac, mb0;
    FUN_00c46970();
};
class AtmosphereObj
{
  public:
    virtual ~AtmosphereObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    virtual void vfn0c();
    virtual void Init2(NiNode*, int);
    int m04, m08, m0c, m10, m14, m18;
};
class FUN_00633080 : public AtmosphereObj
{
  public:
    FUN_00633080();
};
class StarsObj
{
  public:
    virtual ~StarsObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c;
};
class FUN_0063fc70 : public StarsObj
{
  public:
    FUN_0063fc70();
};
class Sun
{
  public:
    virtual ~Sun();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28;
    Sun();
};
class PrecipObj
{
  public:
    virtual ~PrecipObj();
    int m04, m08, m0c, m10, m14;
    void FUN_00636bb0();
};
class FUN_00636a40 : public PrecipObj
{
  public:
    FUN_00636a40();
};
class CloudsObj
{
  public:
    virtual ~CloudsObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c, m50, m54, m58;
};
class FUN_00633cc0 : public CloudsObj
{
  public:
    FUN_00633cc0();
};
class NiAlphaProperty
{
  public:
    int m00, m04, m08, m0c, m10, m14, m18;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiAlphaProperty();
    void FUN_00439340(int);
    void FUN_00439390(int);
    void FUN_0049ed90(bool);
    void FUN_00636000(bool);
};
struct RootPointer
{
    NiNode* p;
    bool FUN_0052aa80(int) const;
    NiNode* operator->() const;
    operator NiNode*() const;
    RootPointer& operator=(NiNode*);
};
struct ThisCls
{
    int m00;
    NiPointer<NiNode> m04, m08;
    int m0c, m10, m14, m18, m1c;
    AtmosphereObj* m20;
    StarsObj* m24;
    Sun* m28;
    CloudsObj* m2c;
    int m30, m34;
    PrecipObj* m38;
    void FUN_0063a630(NiNode*, int);
};
// @fnv 0x0063a630
void ThisCls::FUN_0063a630(NiNode* apRootNode, int arg)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp", 0x152);
    if (((const RootPointer&)m04).FUN_0052aa80(0))
    {
        if (m04->FUN_009611e0())
            m04->FUN_009611e0()->InsertChild(m04);
        m04 = 0;
    }
    if (apRootNode)
        m04 = apRootNode;
    else
    {
        m04 = new FUN_00c46970;
        m04->FUN_005468d0(true);
        m04->FUN_004902f0(true);
    }
    m04->FUN_00440460(&DAT_011f426c);
    if (m20)
        delete m20;
    m20 = new FUN_00633080;
    m20->Init2(m04, arg);
    if (m24)
        delete m24;
    m24 = new FUN_0063fc70;
    m24->Init(m04);
    if (m28)
        delete m28;
    m28 = new Sun;
    m28->Init(m04);
    m08 = new NiNode(0);
    m04->AttachChildInAvailableSlot(m08, true);
    if (m38)
        delete m38;
    if (g_011ccb8c.Bool()->b)
    {
        (m38 = new FUN_00636a40)->FUN_00636bb0();
    }
    else
        m38 = 0;
    if (m2c)
        delete m2c;
    m2c = new FUN_00633cc0;
    m2c->Init(m04);
    {
        NiPointer<NiAlphaProperty> alpha = new NiAlphaProperty;
        alpha->FUN_00439340(6);
        alpha->FUN_00439390(7);
        alpha->FUN_0049ed90(true);
        alpha->FUN_00636000(true);
        m04->FUN_00439410(alpha);
        alpha = 0;
    }
    if (DAT_011F941E)
    {
        DAT_011ad87c = 1.0f;
        DAT_011ad880 = 1.0f;
    }
    m04->FUN_00a5a040();
}
}  // namespace fnv_0063a630

struct FUN_0063bb70_value
{
    int value;
};

struct FUN_0063bb70_result
{
    int value0;
    int value1;
    int value2;
    int value3;
};

struct FUN_0063bb70_shell
{
    void QueryTwoSources(FUN_0063bb70_result* result, FUN_0063bc60_shell* first, FUN_0063bc60_shell* second, int value,
                         FUN_0063bb70_value* source1, FUN_0063bb70_value* source2);
};

// Calls the first object with both source values and optionally the second, then fills zero results from corresponding second-object results.
// @fnv 0x0063bb70
void FUN_0063bb70_shell::QueryTwoSources(FUN_0063bb70_result* result, FUN_0063bc60_shell* first,
                                         FUN_0063bc60_shell* second, int value, FUN_0063bb70_value* source1,
                                         FUN_0063bb70_value* source2)
{
    if (first == 0)
        return;

    result->value0 = first->FUN_0063bc60(value, source1->value);
    result->value1 = first->FUN_0063bc60(value, source2->value);

    if (second != 0)
    {
        result->value2 = second->FUN_0063bc60(value, source1->value);
        result->value3 = second->FUN_0063bc60(value, source2->value);

        if (result->value0 == 0)
            result->value0 = result->value2;

        if (result->value1 == 0)
            result->value1 = result->value3;

        if (result->value2 == 0)
            result->value2 = result->value0;

        if (result->value3 == 0)
            result->value3 = result->value1;
    }
    else
    {
        result->value3 = 0;
        result->value2 = 0;
    }
}
