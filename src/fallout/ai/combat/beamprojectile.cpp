
// src/fallout/ai/combat/beamprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/beamprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ActorCause
{
};
struct NiPointer
{
    NiPointer& operator=(ActorCause* apCause);
};
struct Projectile
{
    NiPointer m_actorCause;  // +0x120
    void FUN_00978ed0(ActorCause* apCause);
};

// @fnv 0x00978ed0
void Projectile::FUN_00978ed0(ActorCause* apCause)
{
    ((NiPointer*)((char*)this + 0x120))->operator=(apCause);
}

namespace fnv_00979260 {
struct Projectile
{
    float m_fFirstLightParameter;
    float GetFirstLightParameter();
};

// @fnv 0x00979260
float Projectile::GetFirstLightParameter()
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xd4);
}
}  // namespace fnv_00979260

struct FUN_009795c0_shell
{
    void FUN_009795c0(float value);
};

// @fnv 0x009795c0
void FUN_009795c0_shell::FUN_009795c0(float value)
{
    *(float*)((char*)this + 0xd4) = value;
}

namespace fnv_009abf10 {
struct BGSLoadFormBuffer;
struct Projectile
{
    void FUN_009c58e0(BGSLoadFormBuffer*);
};
struct BeamProjectile : Projectile
{
    void FUN_009abf10(BGSLoadFormBuffer*);
};

// @fnv 0x009abf10
void BeamProjectile::FUN_009abf10(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Projectile::FUN_009c58e0(apLoadGameBuffer);
}
}  // namespace fnv_009abf10

struct BGSLoadFormBuffer;
struct BeamProjectile
{
    void FUN_009b4cf0(BGSLoadFormBuffer* apLoadGameBuffer);
    void LoadProjectile(BGSLoadFormBuffer* apLoadGameBuffer);
};

void BeamProjectile::LoadProjectile(BGSLoadFormBuffer* apLoadGameBuffer)
{}

// @fnv 0x009b4cf0
void BeamProjectile::FUN_009b4cf0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    LoadProjectile(apLoadGameBuffer);
}

namespace fnv_009bab00 {
struct BGSLoadFormBuffer;

struct Projectile
{
    virtual void InitLoadGame(BGSLoadFormBuffer*);
};

struct BeamProjectile : Projectile
{
    void FUN_009bab00(BGSLoadFormBuffer*);
};

// @fnv 0x009bab00
void BeamProjectile::FUN_009bab00(BGSLoadFormBuffer* apBuffer)
{
    Projectile::InitLoadGame(apBuffer);
}
}  // namespace fnv_009bab00

struct BGSSaveFormBuffer;
struct FUN_00979bb0_shell : BeamProjectile
{
    void SaveProjectile(BGSSaveFormBuffer* apSaveGameBuffer);
    void FUN_00979bb0(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x00979bb0
void FUN_00979bb0_shell::FUN_00979bb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    SaveProjectile(apSaveGameBuffer);
}

struct S5870_Buf;
struct S5870_Holder
{
    void FUN_009c5870(S5870_Buf*);
};
struct FUN_009abef0_shell
{
    void FUN_009abef0(S5870_Buf* apLoadGameBuffer);
};
// @fnv 0x009abef0
void FUN_009abef0_shell::FUN_009abef0(S5870_Buf* apLoadGameBuffer)
{
    ((S5870_Holder*)this)->FUN_009c5870(apLoadGameBuffer);
}

struct NiRTTI;
struct NiAVObject;
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3& operator*=(float s);
};
struct NiBound
{
    NiPoint3 center;
    float radius;
};
struct NiTriShape
{
    NiBound* GetSourceFilesFromForm();
};
struct NiGeometryData;
struct NiGeometry
{
    NiGeometryData* FUN_005495f0();
};
bool __cdecl FUN_0043b300(NiRTTI const*, NiAVObject*);
extern const NiRTTI g_01202680_arg1;
extern const NiRTTI g_01202538_arg1;
extern const NiRTTI g_01202508;
extern NiPoint3 NiPoint3_ZERO;
struct FUN_004d7d50_StandIn
{
    unsigned int FUN_004d7d50();
    NiAVObject* GetByIndex(unsigned int i);
};
struct TESGrass
{
    float GetLowestAllowedSlope();
};
struct EffectSetting
{
    void FUN_004ee4b0(float);
};
struct BeamCtl
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
    virtual bool v23();
};
struct CtlV
{
    CtlV* GetNext() const;
};
struct GeometryVertexBuffer
{
    int a, b, c;
    GeometryVertexBuffer();
    void FUN_00534570(unsigned int, NiPoint3&);
    void SetVertex(unsigned int, NiPoint3 const&);
};
struct FUN_0047d370_shell
{
    unsigned short FUN_0047d370();
};
struct FUN_005f8f10_shell
{
    unsigned short GetFatigue();
};
struct NiGeometryData
{
    bool IsGeometryDataStreamable(bool);
    void FUN_00a67410(GeometryVertexBuffer&);
};
struct FUN_00a673d0_shell
{
    void FUN_00a673d0();
};
struct N_008c48d0
{
    void* GetNext();
};
struct Script
{
    char* GetText();
};
struct BeamPair
{
    float a, b;
};
struct BeamScale_shell
{
    void FUN_009795e0(NiAVObject* obj, float scale);
};
// Scales a NiAVObject's bound radius and center by scale, then scales child effect or geometry vertex data depending on the object's type.
// @fnv 0x009795e0
void BeamScale_shell::FUN_009795e0(NiAVObject* apObject, float scale)
{
    if (apObject)
    {
        ((NiTriShape*)apObject)->GetSourceFilesFromForm()->radius *= scale;
        ((NiTriShape*)apObject)->GetSourceFilesFromForm()->center *= scale;
        NiGeometryData* data = ((NiGeometry*)apObject)->FUN_005495f0();
        if (data)
        {
            if (FUN_0043b300(&g_01202680_arg1, (NiAVObject*)data))
            {
                if (FUN_0043b300(&g_01202538_arg1, apObject))
                {
                    FUN_004d7d50_StandIn* node = (FUN_004d7d50_StandIn*)apObject;
                    for (unsigned int i = 0; i < node->FUN_004d7d50(); i++)
                    {
                        NiAVObject* child = node->GetByIndex(i);
                        if (FUN_0043b300(&g_01202508, child))
                        {
                            TESGrass* effect = (TESGrass*)child;
                            ((EffectSetting*)effect)->FUN_004ee4b0(effect->GetLowestAllowedSlope() * scale);
                        }
                    }
                }
            }
            else if (((CtlV*)data)->GetNext() && ((BeamCtl*)((CtlV*)data)->GetNext())->v23())
            {
                GeometryVertexBuffer vertexMap;
                {
                    FUN_0047d370_shell* ctl = (FUN_0047d370_shell*)((CtlV*)data)->GetNext();
                    if (data->IsGeometryDataStreamable(true))
                    {
                        data->FUN_00a67410(vertexMap);
                        for (int iVertex = 0; iVertex < ctl->FUN_0047d370(); iVertex++)
                        {
                            NiPoint3 vertex = NiPoint3_ZERO;
                            vertexMap.FUN_00534570(iVertex, vertex);
                            vertex.y *= scale;
                            vertexMap.SetVertex(iVertex, vertex);
                        }
                        ((FUN_00a673d0_shell*)data)->FUN_00a673d0();
                    }
                }
            }
            else if (((N_008c48d0*)data)->GetNext())
            {
                for (int k = 0; k < ((FUN_005f8f10_shell*)data)->GetFatigue(); k++)
                {
                    ((NiPoint3*)((N_008c48d0*)data)->GetNext())[k].y *= scale;
                    ((BeamPair*)((Script*)data)->GetText())[k].b *= scale;
                }
            }
        }
    }
}

struct FUN_005de0a0_shell
{
    void FUN_005de0a0(int, int);
};
struct FUN_009bda10_shell : FUN_005de0a0_shell
{
    void FUN_009bda10();
};
struct FUN_005bfbd0_Class
{
    void FUN_005bfbd0(float);
};
struct TargetObject : FUN_005bfbd0_Class
{
};
struct HandleField
{
    operator TargetObject*();
};
struct FUN_00979280_shell : FUN_009bda10_shell
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
    float unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    HandleField target;
    void __thiscall FUN_00979280();
    float __thiscall GetFirstLightParameter();
};
// @fnv 0x00979280
void __thiscall FUN_00979280_shell::FUN_00979280()
{
    FUN_005de0a0(0x10, 0);
    FUN_005de0a0(1, 1);
    FUN_005de0a0(2, 0);
    FUN_005de0a0(8, 1);
    FUN_005de0a0(0x20, 1);
    FUN_005de0a0(0x100, 1);
    FUN_005de0a0(0x80, 1);
    FUN_005de0a0(0x2000, 1);
    FUN_009bda10();
    if (target)
    {
        ((TargetObject*)target)->FUN_005bfbd0(GetFirstLightParameter());
    }
}

struct Descriptor
{
};
struct Scene
{
};
struct Form
{
    int FUN_00401170();
};
struct Reference
{
    Descriptor* FUN_00511840(int);
};
struct Base
{
    bool FUN_004fdf20();
    Reference* FUN_00586150();
};
struct SoundPlaybackHandle
{
    int soundID, flags, unk08;
    ~SoundPlaybackHandle();
    void SetPositionFromArray(Scene*);
    void Play(int);
};
struct SoundManager
{
    SoundPlaybackHandle FUN_00ad7480(Descriptor*, Reference*);
};
SoundManager* FUN_00453a70();
struct Actor
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual bool IsActor();
};
struct Controller
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual void method125();
    virtual void method126();
    virtual void method127();
    virtual void method128();
    virtual void method129();
    virtual void method130();
    virtual void method131();
    virtual void method132();
    virtual void method133();
    virtual void method134();
    virtual void method135();
    virtual void method136();
    virtual void method137();
    virtual void method138();
    virtual void method139();
    virtual void method140();
    virtual void method141();
    virtual void method142();
    virtual void method143();
    virtual void method144();
    virtual void method145();
    virtual void method146();
    virtual void method147();
    virtual void method148();
    virtual void method149();
    virtual void method150();
    virtual void method151();
    virtual void method152();
    virtual void method153();
    virtual void method154();
    virtual void method155();
    virtual void method156();
    virtual void method157();
    virtual void method158();
    virtual void method159();
    virtual void method160();
    virtual void method161();
    virtual void method162();
    virtual void method163();
    virtual void method164();
    virtual void method165();
    virtual void method166();
    virtual void method167();
    virtual void method168();
    virtual void method169();
    virtual void method170();
    virtual void method171();
    virtual void method172();
    virtual void method173();
    virtual void method174();
    virtual void method175();
    virtual void method176();
    virtual void method177();
    virtual void method178();
    virtual void method179();
    virtual void method180();
    virtual void method181();
    virtual void method182();
    virtual void method183();
    virtual void method184();
    virtual void method185();
    virtual void method186();
    virtual void method187();
    virtual void method188();
    virtual void method189();
    virtual void method190();
    virtual void method191();
    virtual void method192();
    virtual void method193();
    virtual void method194();
    virtual void method195();
    virtual void method196();
    virtual void method197();
    virtual void method198();
    virtual void method199();
    virtual void method200();
    virtual void method201();
    virtual void method202();
    virtual void method203();
    virtual void method204();
    virtual void method205();
    virtual void method206();
    virtual void method207();
    virtual void method208();
    virtual void method209();
    virtual void method210();
    virtual void method211();
    virtual void method212();
    virtual void method213();
    virtual void method214();
    virtual void method215();
    virtual void method216();
    virtual void method217();
    virtual void method218();
    virtual void method219();
    virtual void method220();
    virtual void method221();
    virtual void method222();
    virtual void method223();
    virtual void method224();
    virtual void method225();
    virtual void method226();
    virtual void method227();
    virtual void method228();
    virtual void method229();
    virtual void method230();
    virtual void method231();
    virtual void method232();
    virtual void method233();
    virtual void method234();
    virtual void method235();
    virtual void method236();
    virtual void method237();
    virtual void method238();
    virtual void method239();
    virtual void method240();
    virtual void method241();
    virtual void method242();
    virtual void method243();
    virtual void method244();
    virtual void method245();
    virtual void method246();
    virtual void method247();
    virtual void method248();
    virtual void method249();
    virtual void method250();
    virtual void method251();
    virtual void method252();
    virtual void method253();
    virtual void method254();
    virtual void method255();
    virtual void method256();
    virtual void method257();
    virtual void method258();
    virtual void method259();
    virtual void method260();
    virtual void method261();
    virtual void method262();
    virtual void method263();
    virtual void method264();
    virtual void method265();
    virtual void method266();
    virtual void method267();
    virtual void method268();
    virtual void method269();
    virtual void method270();
    virtual void method271();
    virtual void method272();
    virtual void method273();
    virtual void method274();
    virtual void method275();
    virtual void method276();
    virtual void method277();
    virtual void method278();
    virtual void method279();
    virtual void method280();
    virtual void method281();
    virtual void method282();
    virtual void method283();
    virtual void method284();
    virtual void method285();
    virtual void method286();
    virtual void method287();
    virtual void method288();
    virtual void method289();
    virtual void Action(int);
};
extern Controller* DAT_011dea3c;
struct Setting
{
    int* FUN_0043d4d0();
};
extern Setting DAT_011cecdc;
void FUN_004d5c60(int);
struct BeamEffect
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual Scene* GetScene();
    int unk4;
    int unk8;
    int unkC;
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
    float lifetime;
    int unkE8, unkEC, unkF0, unkF4, unkF8;
    Actor* actor;
    Base* FUN_004181e0();
    bool FUN_00444d00(int);
    void StopSound();
    void FUN_005de0a0(int, bool);
    Form* FUN_00567790();
    bool IsFightReactionAllowed(int, Actor*, Form*);
    bool FUN_009c43e0(int, bool);
};
// @fnv 0x009c43e0
bool BeamEffect::FUN_009c43e0(int value, bool silent)
{
    bool result = false;
    if (FUN_004181e0()->FUN_004fdf20() && !FUN_00444d00(0x200))
    {
        StopSound();
        if (!silent)
        {
            Reference* owner = FUN_004181e0()->FUN_00586150();
            if (owner)
            {
                SoundPlaybackHandle sound = FUN_00453a70()->FUN_00ad7480(owner->FUN_00511840(0x4102), owner);
                sound.SetPositionFromArray(GetScene());
                sound.Play(0);
            }
        }
        FUN_005de0a0(0x200, true);
        {
            Form* container;
            {
                Actor* shooter = 0;
                container = 0;
                if (actor && actor->IsActor())
                    shooter = actor;
                else
                {
                    Form* parent = FUN_00567790();
                    if (parent)
                    {
                        int iParentType = parent->FUN_00401170();
                        if (iParentType == 8)
                            container = parent;
                    }
                }
                if (!silent &&
                    (lifetime != 3.4028234663852886e+38 || IsFightReactionAllowed(value, shooter, container)))
                {
                    FUN_004d5c60(11);
                    if (*DAT_011cecdc.FUN_0043d4d0() > 0)
                        DAT_011dea3c->Action(*DAT_011cecdc.FUN_0043d4d0());
                }
            }
        }
        result = true;
    }
    return result;
}

struct S_00979140_Mat3
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    S_00979140_Mat3 FUN_004b45b0() const;
    S_00979140_Mat3 FUN_0043f8d0(const S_00979140_Mat3& other) const;
};

struct S_00979140_UpdateData
{
    float unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    S_00979140_UpdateData(float time, bool a, bool b);
};

struct S_00979140_Node
{
    virtual ~S_00979140_Node();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vfb8(S_00979140_UpdateData* data);
    const S_00979140_Mat3& FUN_00461130() const;
};

struct S_00979140_Holder
{
    virtual ~S_00979140_Holder();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
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
    virtual S_00979140_Node* vf20c();
};

struct S_00979140_Proj
{
    virtual ~S_00979140_Proj();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
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
    virtual S_00979140_Node* vf1d0();
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
    S_00979140_Mat3 unk94;
    S_00979140_Holder* FUN_00874480();
    float GetFirstLightParameter();
    void ScaleNode(S_00979140_Node* node, float a, float b);
    void FUN_00979140();
};

// @fnv 0x00979140
void S_00979140_Proj::FUN_00979140()
{
    S_00979140_Node* node2 = vf1d0();
    if (node2)
    {
        S_00979140_Node* other = FUN_00874480() ? FUN_00874480()->vf20c() : 0;
        if (other)
        {
            S_00979140_UpdateData data(0.0f, false, false);
            node2->vfb8(&data);
            unk94 = vf1d0()->FUN_00461130().FUN_0043f8d0(other->FUN_00461130().FUN_004b45b0());
        }
        float t2 = GetFirstLightParameter();
        if (t2 < 1.0)
            t2 = 1.0f;
        ScaleNode(node2, t2, 0.0f);
    }
}

struct FUN_00979510_cls
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* v125();
    unsigned char ProcessHit(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
    void* FUN_004181e0();
    unsigned char FUN_00979510(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
};

struct FUN_00979510_sub88
{
    unsigned char FUN_008256d0();
};
struct FUN_00979510_obj
{
    void* FUN_00439ef0(float* out, void* x);
};
struct FUN_00979510_res
{
    float FUN_00457990();
};
unsigned char CanProjectileHit(void* a1, void* a4, void* self, void* r);

// @fnv 0x00979510
unsigned char FUN_00979510_cls::FUN_00979510(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6)
{
    unsigned int unk04;
    unsigned int unk08;
    float fOut;
    if (((FUN_00979510_sub88*)((char*)this + 0x88))->FUN_008256d0())
    {
        if (CanProjectileHit(a1, a4, this, this->FUN_004181e0()))
        {
            if (this->ProcessHit(a1, a2, a3, a4, a5, a6))
            {
                ((FUN_009795c0_shell*)this)
                    ->FUN_009795c0(((FUN_00979510_res*)((FUN_00979510_obj*)a2)->FUN_00439ef0(&fOut, this->v125()))
                                       ->FUN_00457990());
                return 1;
            }
        }
    }
    return 0;
}

struct Vec3
{
    float x;
    float y;
    float z;
};

struct Cursor
{
    float m_00;
    float m_04;
    float m_08;
    void FUN_00534550();
    void FUN_00534570(int index, Vec3* out);
};

struct Item
{
    float FUN_00639b20();
};

struct Holder
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
    virtual bool v35();
    unsigned short FUN_0047d370();
};

struct Obj
{
    Holder* FUN_004a8a90();
    bool FUN_00a67360(int flag);
    void FUN_00a67410(Cursor* c);
    void FUN_00a673d0();
    Vec3* FUN_007af430();
    unsigned short FUN_004a8ae0();
};

struct ArgRef
{
    Obj* FUN_005495f0();
    unsigned int FUN_004d7d50();
    Item* GetByIndex(unsigned int index);
};

extern char DAT_01202558;
extern char DAT_012024e0;
extern char DAT_01202508;
extern Vec3 DAT_011f426c;

unsigned char __cdecl FUN_0043b300(const void* typeDesc, const void* obj);

struct FUN_00979840_cls
{
    float FUN_00979840(ArgRef* arg);
};

// @fnv 0x00979840
float FUN_00979840_cls::FUN_00979840(ArgRef* arg)
{
    Obj* actor = arg->FUN_005495f0();
    float best = 0.0f;
    if (actor != 0)
    {
        if (FUN_0043b300(&DAT_01202558, actor))
        {
            if (FUN_0043b300(&DAT_012024e0, arg))
            {
                ArgRef* owner = arg;
                for (unsigned int i = 0; best == 0.0f && i < owner->FUN_004d7d50(); ++i)
                {
                    Item* item = owner->GetByIndex(i);
                    if (FUN_0043b300(&DAT_01202508, item))
                    {
                        Item* p = item;
                        best = p->FUN_00639b20();
                    }
                }
            }
        }
        else
        {
            if (actor->FUN_004a8a90() != 0 && actor->FUN_004a8a90()->v35())
            {
                {
                    Cursor c;
                    c.FUN_00534550();
                    Holder* bag = actor->FUN_004a8a90();
                    if (actor->FUN_00a67360(1))
                    {
                        for (int i = 0; i < bag->FUN_0047d370(); ++i)
                        {
                            Vec3 vecTmp = DAT_011f426c;
                            actor->FUN_00a67410(&c);
                            c.FUN_00534570(i, &vecTmp);
                            if (best < vecTmp.y)
                            {
                                best = vecTmp.y;
                            }
                        }
                        actor->FUN_00a673d0();
                    }
                }
            }
            else if (actor->FUN_007af430() != 0)
            {
                for (int k = 0; k < actor->FUN_004a8ae0(); ++k)
                {
                    Vec3 vecEntry = DAT_011f426c;
                    vecEntry = actor->FUN_007af430()[k];
                    if (best < vecEntry.y)
                    {
                        best = vecEntry.y;
                    }
                }
            }
        }
    }
done:
    return best;
}

struct S_00979a70_Vec3
{
    float x, y, z;
    void FUN_00439180(float s);
};

struct S_00979a70_Obj;

struct S_00979a70_Group
{
    unsigned int FUN_0043b480();
    S_00979a70_Obj* FUN_0043b4a0(unsigned int index);
};

struct S_00979a70_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00979a70_Group* v3();
    S_00979a70_Vec3* FUN_0043c490();
    void FUN_00440460(S_00979a70_Vec3* v);
};

extern int DAT_011f4acc;
extern const double DAT_01012060;
bool __cdecl FUN_0043b300(const void* rtti, S_00979a70_Obj* obj);

struct S_00979a70
{
    float FUN_00979840(S_00979a70_Obj* obj);
    void FUN_009795e0(S_00979a70_Obj* obj, float scale);
    void ScaleNode(S_00979a70_Obj* node, float a, float b);
};

// Scales node's vector by a/b when b exceeds DAT_01012060, then scales the node or recurses into its children.
// @fnv 0x00979a70
void S_00979a70::ScaleNode(S_00979a70_Obj* node, float fScale, float fDivisor)
{
    if (node)
    {
        if (fDivisor > DAT_01012060)
        {
            float s = fScale / fDivisor;
            S_00979a70_Vec3 v = *node->FUN_0043c490();
            v.FUN_00439180(s);
            node->FUN_00440460(&v);
        }
        if (FUN_0043b300(&DAT_011f4acc, node))
        {
            S_00979a70_Obj* p = node;
            float den = (fDivisor > DAT_01012060) ? fDivisor : FUN_00979840(p);
            if (den != DAT_01012060)
            {
                float r = fScale / den;
                FUN_009795e0(p, r);
            }
        }
        else
        {
            S_00979a70_Group* n = node->v3();
            if (n)
            {
                for (unsigned int i = 0; i < n->FUN_0043b480(); i++)
                {
                    S_00979a70_Obj* child = n->FUN_0043b4a0(i);
                    ScaleNode(child, fScale, fDivisor);
                }
            }
        }
    }
}

extern const double DAT_0108fdd0;

namespace std {
double abs(float);
}

struct S9b8b10_Sub88
{
    unsigned char FUN_008256d0();
};

struct S9b8b10_Manager
{
    void* FUN_00441110();
    void* FUN_007af430();
    void FUN_009c8b90(int);
    void SetValue(int);
};
extern S9b8b10_Manager DAT_011f2250;

struct FUN_009b8b10_cls
{
    unsigned char unk00[0x88];
    S9b8b10_Sub88 m_k88;
    unsigned char unk89[0x90 - 0x89];
    bool m_b90;
    unsigned char unk91[0x150 - 0x91];
    int m_i150;

    bool FUN_009b8b10();
    bool FUN_00444d00(int);
    float GetFirstLightParameter();
    double FUN_009669c0();
    double GetE0();
    float FUN_00508070();
    bool ProcessHits();
    void FUN_009bc8f0();
    void HandleContactResponse();
    void FUN_009b90b0();
    void HandleMissileImpact();
};

// @fnv 0x009b8b10
bool FUN_009b8b10_cls::FUN_009b8b10()
{
    bool bResult = false;
    if (!m_b90 && !m_k88.FUN_008256d0())
    {
        bool bConditionMet = true;
        if (FUN_00444d00(1))
        {
            float fDiff = GetFirstLightParameter() - std::abs(FUN_009669c0() * DAT_0108fdd0);
            bConditionMet = GetE0() <= DAT_01012060 || fDiff < FUN_00508070();
        }
        if (bConditionMet)
            bResult = ProcessHits();
    }
    if (bResult)
    {
        if (DAT_011f2250.FUN_00441110() == this)
            DAT_011f2250.FUN_009c8b90(0);
        if (DAT_011f2250.FUN_007af430() == this)
            DAT_011f2250.SetValue(0);
        switch (m_i150)
        {
        case 1:
            FUN_009bc8f0();
            break;
        case 2:
            HandleContactResponse();
            break;
        case 3:
            FUN_009b90b0();
            break;
        case 4:
            HandleMissileImpact();
            break;
        }
    }
    return bResult;
}
