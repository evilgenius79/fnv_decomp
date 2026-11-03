// src/staging/blk_00e60000_o2_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e60000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/staging/blk_00e60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FUN_00a77980_shell
{
    unsigned char FUN_00a77980(int);
};
struct FUN_00e7cdf0_shell
{
    unsigned char FUN_00e7cdf0();
    int _p1;
    int _p2;
    int _p3;
    int _p4;
    int _p5;
    int _p6;
};
void __cdecl FUN_00e7d1b0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00e7d230_cls
{
    FUN_00e7d230_cls* __thiscall DestroyIfFlagged(int);
};
struct MM
{
    void Deallocate(void*);
};
extern MM g_memoryManager;
void __cdecl DestroyArrayElements(void*);
struct FUN_00e7f790_Class
{
    void __thiscall DestroyList();
};
int __cdecl FUN_00e60c70(int a);
struct FUN_00e67fd0_cls
{
    void __thiscall ClearEntries();
};
typedef void*(__stdcall* DepthDevice)(unsigned int);
typedef int(__stdcall* CreateExFn)(unsigned int, DepthDevice**);
extern void* DAT_0126f0d4;
extern DepthDevice DAT_0126f0dc;
extern CreateExFn DAT_0126f0e0;
extern void*(__stdcall* DAT_00fdf0ac)(void*, const char*);
extern void*(__stdcall* DAT_00fdf0b0)(const char*);
unsigned char __cdecl InitD3D9CreateFunctions();
extern void __cdecl NiFree(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern int DAT_010eec74;
struct FUN_00e7b200_Class
{
    int vtbl;
    int m_p;
    FUN_00e7b200_Class* __thiscall FUN_00e7b200(int);
};
struct FUN_00e7d490_Class
{
    void* _00;
    void* _04;
    void* _08;
    void* _0c;
    void* _10;
    void* _14;
    void* _18;
    void* _1c;
    void* _20;
    void __thiscall FUN_00e7d490();
};
struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
struct StagePool
{
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
};
extern StagePool* DAT_0126f6cc;
void __cdecl CreateStagePool();
struct FUN_00e7efc0_Node
{
    int _a;
    int _b;
    FUN_00e7efc0_Node* next;
    FUN_00e7efc0_Node* prev;
};
struct FUN_00e7efc0_List
{
    int _x;
    int _y;
    int _z;
    int count;
    FUN_00e7efc0_Node* head;
    FUN_00e7efc0_Node* __thiscall FUN_00e7efc0(FUN_00e7efc0_Node* node);
};
enum DX9Format_00e68530
{
    DX9FMT_A8P8 = 40,
    DX9FMT_P8 = 41
};
enum DX9ResourceType_00e68530
{
    DX9RTYPE_TEXTURE = 3,
    DX9RTYPE_VOLUMETEXTURE = 4,
    DX9RTYPE_CUBETEXTURE = 5
};
struct DX9SurfaceDesc_00e68530
{
    DX9Format_00e68530 Format;
    DX9ResourceType_00e68530 Type;
    unsigned long Usage;
    int Pool;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    unsigned int Width;
    unsigned int Height;
};
struct DX9VolumeDesc_00e68530
{
    DX9Format_00e68530 Format;
    DX9ResourceType_00e68530 Type;
    unsigned long Usage;
    int Pool;
    unsigned int Width;
    unsigned int Height;
    unsigned int Depth;
};
struct DX9BaseTexture_00e68530
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void** ppDevice) = 0;
    virtual long __stdcall SetPrivateData(const void* refguid, const void* pData, unsigned long SizeOfData,
                                          unsigned long Flags) = 0;
    virtual long __stdcall GetPrivateData(const void* refguid, void* pData, unsigned long* pSizeOfData) = 0;
    virtual long __stdcall FreePrivateData(const void* refguid) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long PriorityNew) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual DX9ResourceType_00e68530 __stdcall GetType() = 0;
    virtual unsigned long __stdcall SetLOD(unsigned long LODNew) = 0;
    virtual unsigned long __stdcall GetLOD() = 0;
    virtual unsigned long __stdcall GetLevelCount() = 0;
    virtual long __stdcall SetAutoGenFilterType(int FilterType) = 0;
    virtual int __stdcall GetAutoGenFilterType() = 0;
    virtual void __stdcall GenerateMipSubLevels() = 0;
};
struct DX9Texture_00e68530 : DX9BaseTexture_00e68530
{
    virtual long __stdcall GetLevelDesc(unsigned int Level, DX9SurfaceDesc_00e68530* pDesc) = 0;
};
struct DX9CubeTexture_00e68530 : DX9BaseTexture_00e68530
{
    virtual long __stdcall GetLevelDesc(unsigned int Level, DX9SurfaceDesc_00e68530* pDesc) = 0;
};
struct DX9VolumeTexture_00e68530 : DX9BaseTexture_00e68530
{
    virtual long __stdcall GetLevelDesc(unsigned int Level, DX9VolumeDesc_00e68530* pDesc) = 0;
};
struct NiComponentSpec
{
    int m_eComponent;
    int m_eRepresentation;
    unsigned char m_ucBPC;
    bool m_bSigned;
};
struct NiPixelFormat
{
    unsigned char m_ucFlags;
    unsigned char m_ucBitsPerPixel;
    int m_eFormat;
    int m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    NiComponentSpec m_akComponents[4];
    NiPixelFormat();
};
bool __cdecl GetPixelTemplateForFormat(DX9Format_00e68530 eFormat, NiPixelFormat& kFormat);
struct NiDX9SourceCubeMapData_S
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    NiPixelFormat m_kPixelFormat;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    DX9BaseTexture_00e68530* m_pkCubeMapTexture;
    unsigned int m_uiTextureFormat;
    bool m_b6c;
    bool m_bHasTexture;
    unsigned int m_uiSize;
    bool FUN_00e68530(DX9BaseTexture_00e68530* pkD3DTexture);
};
struct FUN_00e7d560_Class
{
    void* _00;
    void* _04;
    void* _08;
    void* _0c;
    void* _10;
    void* _14;
    void* _18;
    void* _1c;
    void* _20;
    void* _24;
    void* _28;
    void* _2c;
    void* _30;
    void* _34;
    void* _38;
    void* _3c;
    void* _40;
    void* _44;
    void* _48;
    void* _4c;
    void* _50;
    void* _54;
    void* _58;
    void __thiscall FUN_00e7d560();
};
struct FUN_00e673f0_shell
{
    int __thiscall GetPrimitiveCount();
};
struct FUN_00e613f0
{
    int _00;
    int _04;
    int _08;
    FUN_00e673f0_shell** _0c;
    int _10;
    int __thiscall Sum();
};
int __cdecl CompareStringsCaseInsensitive(int, int);
struct FUN_00e63ec0_Class
{
    int _00;
    int _04;
    int* _08;
    int _0c;
    int __thiscall FUN_00e63ec0(int a, int* out);
};
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern MM g_memoryManager;
extern int DAT_010eec54;
struct FUN_00e7afc0_Class : NiTMapBaseStub
{
    int vtbl;
    int _04;
    int _08;
    FUN_00e7afc0_Class* __thiscall FUN_00e7afc0(int);
};
void* __cdecl _NiFree(void*);
extern int DAT_010eec4c;
extern MemoryManager _g_memoryManager;
struct FUN_00e7b230_Class
{
    void* vtbl;
    void* m_p;
    void* __thiscall FUN_00e7b230(unsigned char flags);
};
extern void* const DAT_010eecac[];
void NiFree(void*);
struct NiD3DShader
{
    void* const* vtbl;
    unsigned char _padding[0x4c];
    void* m_p;
    void __thiscall FUN_00e806c0();
    void __thiscall FUN_00e7c540();
};
extern int DAT_0126f590;
unsigned char __cdecl FUN_00e7cca0(int* pObject);
struct NiRefObject
{
    void* vtbl;
};
extern NiRefObject vftable_NiRefObject;
extern int DAT_010eeed4;
extern int DAT_010eefbc;
extern long volatile DAT_011f4400;
extern MemoryManager _g_memoryManager;
extern void*(__stdcall* DAT_00fdf1c4)(void*);
struct FUN_00e7d1b0_Class
{
    void* _00;
    void* _04;
    void* _08;
    void* _0c;
    void* _10;
    void* _14;
    void* _18;
    void* _1c;
    void* _20;
    void __thiscall FUN_00e7d1b0();
};
struct FUN_00e7d690_Class
{
    void __thiscall FUN_00e7d4e0();
    FUN_00e7d690_Class* __thiscall FUN_00e7d690(int flags);
};
struct FUN_00e7ef80_Node
{
    int _a;
    int _b;
    FUN_00e7ef80_Node* next;
    FUN_00e7ef80_Node* prev;
};
struct FUN_00e7ef80_List
{
    int _x;
    int count;
    FUN_00e7ef80_Node* head;
    FUN_00e7ef80_Node* __thiscall FUN_00e7ef80(FUN_00e7ef80_Node* node);
};
class D3DRenderStateGroup
{
  public:
    ~D3DRenderStateGroup();
};
void __cdecl _FUN_00aa1490(void* p, int size);
void __cdecl DestroyArrayElements(void* p);
struct FUN_00e611d0_Object
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    int unk18;
};
struct FUN_00c85750_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
FUN_00c85750_Result* __cdecl FUN_00c85750();
void __cdecl AppendIndexSequence(int, int, int, int, int);
void __cdecl AppendIndices(int, int, int, int, int);
void __cdecl FUN_00e611d0(FUN_00e611d0_Object* object, int value);
struct FUN_00e61230_Buffer
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
};
struct FUN_00e61230_Receiver
{
    virtual void unknown0() = 0;
    virtual void unknown1() = 0;
    virtual void unknown2() = 0;
    virtual void unknown3() = 0;
    virtual void begin(void* value, unsigned int mode, FUN_00e61230_Buffer* buffer) = 0;
    virtual void end(FUN_00e61230_Buffer* buffer) = 0;
};
extern "C" void __cdecl FUN_00e611d0(FUN_00e61230_Buffer* buffer, unsigned int stage);
void __cdecl RunReceiverStage(FUN_00e61230_Receiver* receiver, void* value, unsigned int stage);
struct E65000Entry
{
    float m_fValue;
    int m_iData;
};
static float FUN_00e65000(E65000Entry* pkEntries, int iIndex, float fValue);
float E65000Swap(E65000Entry* pkEntries, int iIndex, float fValue);
class E673F0Geometry
{
  public:
    int unk00;
    int unk04;
    char m_cPrimitiveType;
    char unk09;
    char unk0A;
    char unk0B;
    int unk0C;
    int m_iIndexCount;
    int unk14;
    int unk18;
    int m_iVertexCount;

    int GetPrimitiveCount();
};
struct IndexSource_e67420
{
    int unk00;
    int unk04;
    char m_cType;
    char unk09;
    char unk0a;
    char unk0b;
    unsigned short* m_pusIndices;
    int m_iShortCount;
    int unk14;
    unsigned int* m_puiIndices;
    int m_iIntCount;

    bool FUN_00e67420(unsigned int iIndex, unsigned int* p0, unsigned int* p1, unsigned int* p2);
};
class FUN_00e67660_cls;
class FnvEnt67;
class FnvNode67;
class FnvOwner67;
class FnvOwner67
{
  public:
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
    FnvEnt67* m_30;
};
class FnvEnt67
{
  public:
    FnvOwner67* m_00;
    int unk04;
    int unk08;
    FnvNode67* m_0c;
};
class FnvNode67
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FnvEnt67* m_18;
    int unk1c;
    int unk20;
    int unk24;
    FnvEnt67* m_28;
    int unk2c;
    int unk30;
    int unk34;
    FnvEnt67* m_38;
    int unk3c;
    float m_40;
    int m_44;
    int Callee00e63af0(int a2, FUN_00e67660_cls* t, int* out);
};
class FUN_00e67660_cls
{
  public:
    int unk00;
    int m_04;
    int unk08;
    int m_0c;
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
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    FnvNode67* m_de0[100];
    int FUN_00e67660(FnvNode67* a1, int a2, int* a3, FnvEnt67** a4);
};
extern float DAT_0104da48;
void* __cdecl _memmove(void*, const void*, unsigned);
struct CopyDesc
{
    int format, type;
    unsigned usage;
    int pool, multisample;
    unsigned quality, width, height;
};
struct CopyLock
{
    unsigned pitch;
    void* bits;
};
struct CopySurface
{
    virtual void __stdcall vf0() = 0;
    virtual void __stdcall vf1() = 0;
    virtual void __stdcall vf2() = 0;
    virtual void __stdcall vf3() = 0;
    virtual void __stdcall vf4() = 0;
    virtual void __stdcall vf5() = 0;
    virtual void __stdcall vf6() = 0;
    virtual void __stdcall vf7() = 0;
    virtual void __stdcall vf8() = 0;
    virtual void __stdcall vf9() = 0;
    virtual void __stdcall vf10() = 0;
    virtual void __stdcall vf11() = 0;
    virtual long __stdcall GetDesc(CopyDesc*) = 0;
    virtual long __stdcall LockRect(CopyLock*, void*, unsigned) = 0;
    virtual long __stdcall UnlockRect() = 0;
};
struct CopyPixels
{
    int unk00;
    int unk04;
    int unk08;
    int format;
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
    unsigned char* pixels;
    unsigned* widths;
    unsigned* heights;
    unsigned* offsets;
    unsigned levels;
    unsigned bytesPerPixel;
};
const char* __cdecl GetHResultName(long);
void __cdecl FUN_00a29680(const char*, ...);
void __cdecl FUN_00e68150(CopyPixels* pSourcePixels, unsigned level, CopySurface* surface, unsigned face);
struct TexDevice
{
    virtual void __stdcall vf0() = 0;
    virtual void __stdcall vf1() = 0;
    virtual void __stdcall vf2() = 0;
    virtual void __stdcall vf3() = 0;
    virtual void __stdcall vf4() = 0;
    virtual void __stdcall vf5() = 0;
    virtual void __stdcall vf6() = 0;
    virtual void __stdcall vf7() = 0;
    virtual void __stdcall vf8() = 0;
    virtual void __stdcall vf9() = 0;
    virtual void __stdcall vf10() = 0;
    virtual void __stdcall vf11() = 0;
    virtual void __stdcall vf12() = 0;
    virtual void __stdcall vf13() = 0;
    virtual void __stdcall vf14() = 0;
    virtual void __stdcall vf15() = 0;
    virtual void __stdcall vf16() = 0;
    virtual void __stdcall vf17() = 0;
    virtual void __stdcall vf18() = 0;
    virtual void __stdcall vf19() = 0;
    virtual void __stdcall vf20() = 0;
    virtual void __stdcall vf21() = 0;
    virtual void __stdcall vf22() = 0;
    virtual long __stdcall CreateTexture(unsigned, unsigned, unsigned, unsigned, int, int, void**, void*) = 0;
};
struct TexRenderer
{
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void vf33() = 0;
    virtual void vf34() = 0;
    virtual void vf35() = 0;
    virtual void vf36() = 0;
    virtual void vf37() = 0;
    virtual void vf38() = 0;
    virtual void vf39() = 0;
    virtual unsigned Flags() = 0;
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
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    TexDevice* device;
};
struct TextureInput
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
    unsigned levels;
};
struct TextureOwner
{
    int unk00;
    int unk04;
    int unk08;
    unsigned width, height;
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
    TexRenderer* renderer;
    void* texture;
    unsigned levels;
    bool unk6c, mipmap;
    unsigned unk70, unk74, skip;
    bool CreateTextureFromInput(TextureInput*, int);
};
extern int DAT_0126efc0;
extern bool DAT_0126f0d0;
const char* __cdecl GetHResultName(long);
void __cdecl FUN_00a29680(const char*, ...);
inline bool IsPowerOfTwo(unsigned n)
{
    if (!n)
        return false;
    return (n & (n - 1)) == 0;
}
struct E68760Program
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiID;
};
template <class T> class E68760Pointer
{
  public:
    T* m_pObject;

    bool operator!=(const T* pObject) const
    {
        return m_pObject != pObject;
    }
    E68760Pointer& operator=(T* pObject);
};
class E68760Pass
{
  public:
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
    E68760Pointer<E68760Program> m_spShaderProgram;
    int unk78;
    int unk7C;
    unsigned int m_uiProgramID;

    bool SetProgram(E68760Program* pkProgram);
};
// SetValue: thiscall setter, one stack dword stored to this+0x64.
struct FUN_00e687e0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int m_i64;
    void __thiscall SetValue(unsigned int value);
};
class E68830RefObject
{
  public:
    virtual ~E68830RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
class E68830Base
{
  public:
    virtual ~E68830Base();
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
};
class FUN_00e68830 : public E68830Base
{
  public:
    NiPointer<E68830RefObject> m_spTransformData;

    virtual ~FUN_00e68830() throw();
};
struct CubeMapSource
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
    virtual int __stdcall v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual int __stdcall GetSurfaceLevel(unsigned int i, int* out);
};
struct CubeMapSurface
{
    virtual void v00();
    virtual void v01();
    virtual void __stdcall Release();
};
extern "C" void __cdecl FUN_00e68150(int a, unsigned int b, int c, int d);
extern "C" void* __cdecl GetHResultName(int r);
extern "C" void __cdecl FUN_00a29680(const char* fmt, unsigned int i, void* s);
struct FUN_00e68870_arg
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
    unsigned int m_60;
};
struct FUN_00e68870_cls
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
    CubeMapSource* m_64;
    unsigned int m_68;
    int unk6C;
    int unk70;
    int unk74;
    unsigned int m_78;
    void __thiscall FUN_00e68870(FUN_00e68870_arg* a1);
};
extern "C" char DAT_010ed37c[];
void __cdecl FUN_00aa1460(void* pObject, unsigned int value);
struct FUN_00e68ea0_held
{
    virtual void v00();
    virtual void v04();
    long m_iRefCount;
};
struct FUN_00e68ea0_cls
{
    void* m_vptr;
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
    FUN_00e68ea0_held* m_74;
    int unk78;
    int unk7c;
    int unk80;

    void BaseCleanup();

    FUN_00e68ea0_cls* FUN_00e68ea0(unsigned char acFlags);
};
void __cdecl NiFree(void* pvMem);
void __cdecl BE7B040SizedFree(void* pvMem, unsigned int uiSize);
struct BE7B040Value
{
    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        BE7B040SizedFree(pvMem, uiSize);
    }

    int m_aiData00;
    int m_aiData04;
    int m_aiData08;
    int m_aiData0C;
    int m_aiData10;
    int m_aiData14;
    int m_aiData18;
    int m_aiData1C;
    int m_aiData20;
    int m_aiData24;
    int m_aiData28;
    int m_aiData2C;
    int m_aiData30;
    int m_aiData34;
    int m_aiData38;
    int m_aiData3C;
    int m_aiData40;
    int m_aiData44;
};
template <class TKEY, class TVAL> struct BE7B040MapItem
{
    BE7B040MapItem* m_pkNext;
    TKEY m_key;
    TVAL m_val;
};
template <class TKEY, class TVAL> class BE7B040MapBase
{
  public:
    typedef BE7B040MapItem<TKEY, TVAL> Item;

    __forceinline virtual ~BE7B040MapBase()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(TKEY key) const;

    void RemoveAll();

    Item* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void GetNext(Item*& pkPos, TKEY& key, TVAL& val) const
    {
        Item* pkItem = pkPos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pkPos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkPos = m_ppkHashTable[i];
            if (pkPos)
                return;
        }
        pkPos = 0;
    }

    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    unsigned int m_uiCount;
};
template <class TKEY, class TVAL> class BE7B040Map : public BE7B040MapBase<TKEY, TVAL>
{
  public:
    __forceinline virtual ~BE7B040Map()
    {
        this->RemoveAll();
    }
};
class FUN_00e7b040_cls
{
  public:
    ~FUN_00e7b040_cls() throw();

    int unk00;
    int unk04;
    BE7B040Map<unsigned int, BE7B040Value*> m_kValues;
};
struct Entry
{
    unsigned int identifier;
    unsigned int subIdentifier;
    unsigned int properties;
    unsigned int group;
    unsigned int FUN_00e7af60(unsigned int accumulated);
};
struct EntryArray
{
    void* vtable;
    Entry** items;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growBy;
};
struct Owner
{
    EntryArray& entries()
    {
        return *reinterpret_cast<EntryArray*>(reinterpret_cast<char*>(this) + 0x450);
    }
    Entry* FUN_00e7b190(unsigned int group, unsigned int identifier, unsigned int subIdentifier,
                        unsigned int* accumulated);
};
struct FUN_00e7b550_cls
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
    int unkD4;
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
    void FUN_00e7b040();
    void FUN_00b71300();
    void DeleteAllItems();
};
struct ListNode_b9541
{
    ListNode_b9541* next;
    int unk04;
    FUN_00e7b550_cls* item;
};
class BE7BBF0Source
{
  public:
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetDesc(void* pDesc);
    virtual unsigned int __stdcall GetCount();
};
class BE7BBF0Item
{
  public:
    static void* operator new(unsigned int uiSize);

    BE7BBF0Item(BE7BBF0Source* pkSource, unsigned int uiIndex, void* pvContext) throw();

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
};
template <class T> class BE7BBF0Array
{
  public:
    virtual ~BE7BBF0Array();
    void SetSize(unsigned int uiMaxSize);

    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class FUN_00e7bbf0_cls
{
  public:
    void BuildItemsFromSource(BE7BBF0Source* pkSource, void* pvContext);

    unsigned int m_uiCount;
    BE7BBF0Array<BE7BBF0Item*> m_kUnsortedGeometryList;
};
extern int DAT_010eeca4;
struct NiArr_e7bc90
{
    void* m_ppVirtualMethodTable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    NiArr_e7bc90(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_ppVirtualMethodTable = (void*)&DAT_010eeca4;
    }
};
struct Base_e7bc90
{
    unsigned int m_uiCount;
    void BuildItemsFromSource(int a, int b) throw();
};
struct FUN_00e7bc90 : Base_e7bc90
{
    NiArr_e7bc90 m_aiIndexedValues;
    FUN_00e7bc90(int a, int b) throw();
};
struct FUN_00e7bcd0_Item
{
    void FUN_00e7bb50();
};
void __cdecl FUN_00aa1460(void* p, int size);
void __cdecl FUN_00aa10f0(void* p);
struct FUN_00e7bcd0_cls
{
    int unk00;
    int unk04;
    FUN_00e7bcd0_Item** m_items;
    unsigned short unk0C;
    unsigned short m_uiItemCount;
    void DestroyItems();
};
struct S_00e88fc0_Callee
{
    void __thiscall SetStageValue(int, int, int);
};
struct S_00e7c610_Object
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S_00e88fc0_Callee* unk10;
    void* unk14;
    void* unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f;
};
void __stdcall FUN_00e7c610(float* afMatrix, S_00e7c610_Object* pObject);
class FUN_00e7cc90_cls
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
    bool FUN_00e7cc90();
};
struct E7CCD0Device
{
    virtual long __stdcall vfunc00();
    virtual long __stdcall vfunc01();
    virtual long __stdcall vfunc02();
    virtual long __stdcall vfunc03();
    virtual long __stdcall vfunc04();
    virtual long __stdcall vfunc05();
    virtual long __stdcall vfunc06();
    virtual long __stdcall vfunc07();
    virtual long __stdcall vfunc08();
    virtual long __stdcall vfunc09();
    virtual long __stdcall vfunc0A();
    virtual long __stdcall vfunc0B();
    virtual long __stdcall vfunc0C();
    virtual long __stdcall vfunc0D();
    virtual long __stdcall vfunc0E();
    virtual long __stdcall vfunc0F();
    virtual long __stdcall vfunc10();
    virtual long __stdcall Present(const void* pSourceRect, const void* pDestRect, void* hDestWindowOverride,
                                   const void* pDirtyRegion);
};
class E7CCD0Renderer
{
  public:
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
    E7CCD0Device* m_pD3DDevice;

    bool PresentFrame();
};
// Candidate reconstruction of FUN_00e7cdb0 (0x00e7cdb0, 59 bytes).
//
// The original is a __thiscall member of a NiDX9*BufferData-like object:
//   * a 32-bit id member lives at offset +0x14 of the object,
//   * a global int caches the last id that was accepted,
//   * the id is validated through a renderer interface object passed as the
//     single stack argument; the interface's vtable slot 0x9c is entered with
//     the interface pointer as an explicit argument plus the id.
//
// The interface stand-in below is a plain polymorphic class with 39 filler
// virtuals so that the interesting one lands on vtable offset 0x9c.
struct FnvRendererData
{
    virtual int Fnv_v00();
    virtual int Fnv_v01();
    virtual int Fnv_v02();
    virtual int Fnv_v03();
    virtual int Fnv_v04();
    virtual int Fnv_v05();
    virtual int Fnv_v06();
    virtual int Fnv_v07();
    virtual int Fnv_v08();
    virtual int Fnv_v09();
    virtual int Fnv_v10();
    virtual int Fnv_v11();
    virtual int Fnv_v12();
    virtual int Fnv_v13();
    virtual int Fnv_v14();
    virtual int Fnv_v15();
    virtual int Fnv_v16();
    virtual int Fnv_v17();
    virtual int Fnv_v18();
    virtual int Fnv_v19();
    virtual int Fnv_v20();
    virtual int Fnv_v21();
    virtual int Fnv_v22();
    virtual int Fnv_v23();
    virtual int Fnv_v24();
    virtual int Fnv_v25();
    virtual int Fnv_v26();
    virtual int Fnv_v27();
    virtual int Fnv_v28();
    virtual int Fnv_v29();
    virtual int Fnv_v30();
    virtual int Fnv_v31();
    virtual int Fnv_v32();
    virtual int Fnv_v33();
    virtual int Fnv_v34();
    virtual int Fnv_v35();
    virtual int Fnv_v36();
    virtual int Fnv_v37();
    virtual int Fnv_v38();
    virtual int Fnv_v39(FnvRendererData* pSelf, int nId);
};
struct FnvBufferData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_nId;
    unsigned char FUN_00e7cdb0(FnvRendererData* pRenderer);
};
extern int g_nLastId;
typedef int(__stdcall* FNV_PFN_2)(void* obj, void* arg);
typedef void(__stdcall* FNV_PFN_1)(void* obj);
int __cdecl CreatePixelFormat(void* p);
struct FUN_00a8f080_shell
{
    void __thiscall SetValues(int a, int b);
};
class FUN_00e7ce30_cls
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
    void* m_04;
    void* m_08;
    void* m_0c;
    int m_10;
    void* m_14;
    unsigned char FUN_00e7ce30(void* a1);
};
struct FNV_Frame
{
    void* out;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
// FUN_00e7d180 : releases the callback object held at +0x14 and the
// memory block held at +0x0c.
class Handler
{
  public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
};
extern MemoryManager DAT_011f6238;
class FUN_00e7d180_cls
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_0c;
    int unk10;
    Handler* m_14;

    void FUN_00e7d180();
};
struct CpuOpaque;
extern CpuOpaque DAT_0126f5a4;
CpuOpaque* __cdecl FUN_00e7d220();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
struct D3DSurfaceDesc_e7d250
{
    int Format;
    int Type;
    unsigned long Usage;
    int Pool;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    unsigned int Width;
    unsigned int Height;
};
struct D3DSurface_e7d250
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void** ppDevice) = 0;
    virtual long __stdcall SetPrivateData(const void* refguid, const void* pData, unsigned long SizeOfData,
                                          unsigned long Flags) = 0;
    virtual long __stdcall GetPrivateData(const void* refguid, void* pData, unsigned long* pSizeOfData) = 0;
    virtual long __stdcall FreePrivateData(const void* refguid) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long PriorityNew) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual int __stdcall GetType() = 0;
    virtual long __stdcall GetContainer(const void* riid, void** ppContainer) = 0;
    virtual long __stdcall GetDesc(D3DSurfaceDesc_e7d250* pDesc) = 0;
};
struct D3DTexture_e7d250
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void** ppDevice) = 0;
    virtual long __stdcall SetPrivateData(const void* refguid, const void* pData, unsigned long SizeOfData,
                                          unsigned long Flags) = 0;
    virtual long __stdcall GetPrivateData(const void* refguid, void* pData, unsigned long* pSizeOfData) = 0;
    virtual long __stdcall FreePrivateData(const void* refguid) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long PriorityNew) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual int __stdcall GetType() = 0;
    virtual unsigned long __stdcall SetLOD(unsigned long LODNew) = 0;
    virtual unsigned long __stdcall GetLOD() = 0;
    virtual unsigned long __stdcall GetLevelCount() = 0;
    virtual long __stdcall SetAutoGenFilterType(int FilterType) = 0;
    virtual int __stdcall GetAutoGenFilterType() = 0;
    virtual void __stdcall GenerateMipSubLevels() = 0;
    virtual long __stdcall GetLevelDesc(unsigned int Level, D3DSurfaceDesc_e7d250* pDesc) = 0;
    virtual long __stdcall GetSurfaceLevel(unsigned int Level, D3DSurface_e7d250** ppSurfaceLevel) = 0;
};
struct NiPixelFormat;
NiPixelFormat* __cdecl CreatePixelFormat(unsigned int eD3DFormat);
const char* __cdecl NiDX9ErrorString(long hr);
void __cdecl NiDX9Warning(const char* pcFormat, ...);
class Ni2DBufferStub;
class NiRefObjectStub
{
  public:
    static void* operator new(unsigned int uiSize);
    NiRefObjectStub() throw()
    {
        m_uiRefCount = 0;
        InterlockedIncrement(&ms_lObjectCount);
    }
    virtual ~NiRefObjectStub();
    unsigned int m_uiRefCount;
    static volatile long ms_lObjectCount;
};
class RendererDataStub : public NiRefObjectStub
{
  public:
    RendererDataStub() throw() : m_pCacheEntry(0), m_pkRenderPixelFormat(0)
    {}
    virtual ~RendererDataStub();
    Ni2DBufferStub* m_pCacheEntry;
    NiPixelFormat* m_pkRenderPixelFormat;
};
class NiDX92DBufferDataStub : public RendererDataStub
{
  public:
    NiDX92DBufferDataStub() throw() : m_pkSurface(0)
    {}
    virtual ~NiDX92DBufferDataStub();
    int m_iDepthFormat;
    D3DSurface_e7d250* m_pkSurface;
    int m_iUnk18;
    int m_iSamples;
};
class NiDX9TextureBufferData : public NiDX92DBufferDataStub
{
  public:
    NiDX9TextureBufferData() throw()
    {
        m_pkCubeMapTexture = 0;
    }
    virtual ~NiDX9TextureBufferData();
    D3DTexture_e7d250* m_pkCubeMapTexture;

    static NiDX9TextureBufferData* __cdecl FUN_00e7d250(D3DTexture_e7d250* pkD3DTexture, Ni2DBufferStub*& pkBuffer,
                                                        int eMSAAPref, int iUnk18);
};
class Ni2DBufferStub
{
  public:
    static Ni2DBufferStub* __cdecl Create(unsigned int uiWidth, unsigned int uiHeight, RendererDataStub* pkData);
    void AttachRendererData(RendererDataStub* pkData);
};
extern int DAT_0126f5e0;
int* __cdecl FUN_00e7d550();
extern int DAT_0126f5b4;
void* __cdecl FUN_00e7d680(void);
class BE7F610Heap
{
  public:
    void Deallocate(void* pvMem);
};
extern BE7F610Heap g_kE7F610Heap;
void __cdecl FUN_00aa10f0(void* pvMem);
void __cdecl FUN_00aa1490(void* pvMem, unsigned int uiAlignment);
class BE7F610Object
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kE7F610Heap.Deallocate(pvMem);
    }
};
class BE7F610Worker : public BE7F610Object
{
  public:
    ~BE7F610Worker();
};
class BE7F610Leaf : public BE7F610Object
{
  public:
    void* FUN_00e7f050(unsigned int uiFlags);
};
class BE7F610Buffer : public BE7F610Object
{
  public:
    __forceinline ~BE7F610Buffer()
    {
        FUN_00aa1490(m_pResource, 0x10);
        if (m_pkLeaf)
            m_pkLeaf->FUN_00e7f050(1);
    }

    void* m_pResource;
    int unk04;
    BE7F610Leaf* m_pkLeaf;
};
template <class T> class BE7F610Queue : public BE7F610Object
{
  public:
    __forceinline ~BE7F610Queue()
    {
        m_iArrayLength = 0;
        delete m_pkOwned;
        FUN_00aa10f0(m_pvItems);
    }

    void* m_pvItems;
    int unk04;
    int m_iArrayLength;
    T* m_pkOwned;
};
extern BE7F610Queue<BE7F610Worker>* g_pkE7F610WorkerQueue;
extern BE7F610Queue<BE7F610Buffer>* g_pkE7F610BufferQueue;
void __cdecl DestroyGlobalQueues();
extern int DAT_0126f728;
int __cdecl FUN_00e7f7c0();
struct Q74
{
    unsigned int a, b, c, d;
    Q74() : a(0), b(0), c(0), d(0)
    {}
};
struct FUN_00e8a260
{
    virtual void V0();
    void* unk04[0x1a];
    FUN_00e8a260(int, int);
};
struct Mid_00e687a0 : FUN_00e8a260
{
    unsigned char unk6c;
    unsigned char unk6d;
    unsigned int unk70;
    Mid_00e687a0(int p1, int p2) : FUN_00e8a260(p1, p2)
    {
        unk6c = 0;
        unk6d = 0;
        unk70 = 0;
    }
};
struct FUN_00e687a0 : Mid_00e687a0
{
    Q74 q74;
    virtual void V1();
    FUN_00e687a0(int p1, int p2);
};
extern long(__stdcall* DAT_00fdf1c0)(void*);
struct E74RefShader
{
    virtual void v00();
    virtual void DeleteThis();
    long m_lRefCount;
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (!DAT_00fdf1c4(&m_lRefCount))
            DeleteThis();
    }
};
struct E74GeomData
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
    virtual unsigned short GetActiveCount();
    char pad04[0x30];
    unsigned int m_uiTriangles;
};
struct E74Partition
{
    char pad00[0x28];
    unsigned int m_uiTriangles;
};
struct E74SkinPartition
{
    char pad00[8];
    unsigned int m_uiPartitionCount;
    E74Partition* m_pPartitions;
};
struct E74SkinInstance
{
    char pad00[0xc];
    E74SkinPartition* m_pkSkinMeshPartition;
};
struct E74Geometry
{
    char pad00[8];
    const char* m_pcName;
    char pad0c[0xac];
    E74GeomData* m_spGeometryData;
    E74SkinInstance* m_spSkinningInstance;
    E74RefShader* m_pGeometryShader;
};
class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int uiSize);
};
struct E74ShaderPtr
{
    E74RefShader* m_pObject;
    operator E74RefShader*() const
    {
        return m_pObject;
    }
    E74RefShader* operator->() const
    {
        return m_pObject;
    }
    E74ShaderPtr& operator=(E74RefShader* pObject)
    {
        E74RefShader* pOld = m_pObject;
        if (pOld != pObject)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = pObject;
            if (pObject)
                pObject->IncRefCount();
        }
        return *this;
    }
};
struct E74Node
{
    E74Geometry* m_pkGeom;
    E74Partition* m_pkGeometryPartition;
    unsigned int m_uiTriangles;
    E74Node* m_pkNext;
};
struct E74GroupMgr
{
    bool ProcessCollector(void* pkGroup, E74GeomData* pkData, E74SkinInstance* pkSkin, bool bHasAnimation,
                          unsigned int a, unsigned int b);
};
extern int DAT_0126f0ec;
inline E74Node* E74NewNode()
{
    E74Node* pkNode = (E74Node*)DAT_0126f0ec;
    if (!pkNode)
        return (E74Node*)BSFaceGenMorphData::operator new(sizeof(E74Node));
    DAT_0126f0ec = (int)pkNode->m_pkNext;
    pkNode->m_pkNext = 0;
    return pkNode;
}
struct E74Accumulator
{
    char pad000[0x620];
    E74Node* m_pkHead;
    E74Node* m_pkTail;
    char pad628[8];
    E74ShaderPtr m_pGeometryShader;
    char pad634[0x278];
    E74GroupMgr* m_pkGroupMgr;
    void* m_pkActorGroup;
    bool FUN_00e72c20(E74Geometry* pkGeom, E74RefShader* pkShader);
    void AddTail(E74Node* pkNode)
    {
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_pkTail = pkNode;
    }
};
struct FUN_00e74a40_shell : E74Accumulator
{
    void AddGeometryToBatch(E74Geometry* pkGeom);
};
struct FUN_00e74c00_cls
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
    void* m_p288;
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
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    unsigned char m_bRestoreBusy;
    unsigned char unk6FD;
    unsigned char unk6FE;
    unsigned char unk6FF;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    void** m_ppCallbacks;
    unsigned char unkAFC;
    unsigned char unkAFD;
    unsigned short m_usCallbackCount;
    int unkB00;
    int unkB04;
    void** m_ppCallbackData;

    bool FUN_00e736b0();
    bool HandleDeviceLost();
};
typedef int(__stdcall* FNVSlot3Fn)(void*);
typedef int(__stdcall* FNVSlot80Fn)(void*, int);
typedef bool(__cdecl* FNVCallbackFn)(void*);
struct Item
{
    int m_key;
    unsigned char m_flag4;
    unsigned char m_flag5;
    unsigned char m_unk06;
    unsigned char m_unk07;
};
struct Node
{
    Node* m_next;
    int m_unk04;
    Item* m_item;
};
__declspec(noinline) int __cdecl FUN_00e7acb0(int key)
{
    switch (key)
    {
    case 0x3154454d:
        return 0x10;
    case 0x34545844:
        return 0x18;
    case 0x31545844:
        return 0x20;
    case 0x32545844:
        return 0x40;
    case 0x33545844:
        return 0x80;
    case 0x35545844:
        return 0x8;
    case 0x32595559:
        return 0x10;
    case 0x59565955:
        return 0x10;
    case 0x47424752:
        return 0x10;
    case 0x42475247:
        return 0x10;
    case 0x75:
        return 0x8;
    case 0x76:
        return 0x10;
    default:
        return 0;
    }
}
int __cdecl MapCodeToIndex(int key);
class TexFormatList
{
  public:
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00c;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01c;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02c;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03c;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04c;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05c;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06c;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07c;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08c;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09c;
    int m_unk0a0;
    int m_unk0a4;
    int m_unk0a8;
    int m_unk0ac;
    int m_unk0b0;
    int m_unk0b4;
    int m_unk0b8;
    int m_unk0bc;
    int m_unk0c0;
    int m_unk0c4;
    int m_unk0c8;
    int m_unk0cc;
    int m_unk0d0;
    int m_unk0d4;
    int m_unk0d8;
    int m_unk0dc;
    int m_unk0e0;
    int m_unk0e4;
    int m_unk0e8;
    int m_unk0ec;
    int m_unk0f0;
    int m_unk0f4;
    int m_unk0f8;
    int m_unk0fc;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10c;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11c;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12c;
    int m_unk130;
    Node* m_pFirstNode;
    int __thiscall FindFormatValue(unsigned char flag, int key);
};
struct PixelTemplate
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
};
extern const PixelTemplate DAT_011aa210;
extern const PixelTemplate DAT_011aa2a0;
extern const PixelTemplate DAT_011aa408;
extern const PixelTemplate DAT_011aa498;
extern const PixelTemplate DAT_011aa4e0;
extern const PixelTemplate DAT_011aa528;
extern const PixelTemplate DAT_011aa570;
extern const PixelTemplate DAT_011aa5b8;
extern const PixelTemplate DAT_011aa600;
extern const PixelTemplate DAT_011aa648;
extern const PixelTemplate DAT_011aa690;
extern const PixelTemplate DAT_011aa6d8;
extern const PixelTemplate DAT_011aa768;
extern const PixelTemplate DAT_011aa7b0;
extern const PixelTemplate DAT_011aa7f8;
extern const PixelTemplate DAT_011aa8d0;
extern const PixelTemplate DAT_011aa960;
extern const PixelTemplate DAT_011aa9a8;
extern const PixelTemplate DAT_011aa9f0;
extern const PixelTemplate DAT_011aaa38;
extern const PixelTemplate DAT_011aaa80;
extern const PixelTemplate DAT_011aaac8;
extern const PixelTemplate DAT_011aab58;
extern const PixelTemplate DAT_011aaba0;
extern const PixelTemplate DAT_011aabe8;
extern const PixelTemplate DAT_011aac30;
extern const PixelTemplate DAT_011aacc0;
extern const PixelTemplate DAT_011aad08;
extern const PixelTemplate DAT_011aad50;
extern const PixelTemplate DAT_011aad98;
extern const PixelTemplate DAT_011aade0;
extern const PixelTemplate DAT_011aae28;
extern const PixelTemplate DAT_011aae70;
extern const PixelTemplate DAT_011aaeb8;
extern const PixelTemplate DAT_011aaf00;
extern const PixelTemplate DAT_011aaf48;
extern const PixelTemplate DAT_011aaf90;
extern const PixelTemplate DAT_011ab020;
extern const PixelTemplate DAT_011ab068;
extern const PixelTemplate DAT_011ab0b0;
extern const PixelTemplate DAT_011ab0f8;
extern const PixelTemplate DAT_011ab140;
extern const PixelTemplate DAT_011ab188;
extern const PixelTemplate DAT_011ab1d0;
extern const PixelTemplate DAT_011ab218;
extern const PixelTemplate DAT_011ab2a8;
extern const PixelTemplate DAT_011ab2f0;
PixelTemplate& __cdecl GetPixelTemplateForFormat(int format, PixelTemplate& output);
class CE7C500Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern CE7C500Heap g_kE7C500Heap;
class CE7C500PixelFormat
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kE7C500Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    CE7C500PixelFormat() throw();

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
};
void __cdecl CE7C500ConvertFormat(int eFormat, CE7C500PixelFormat* pkFormat);
CE7C500PixelFormat* __cdecl CreatePixelFormat(int eFormat);
struct DepthSurfaceDescription
{
    unsigned int format;
    unsigned int type;
    unsigned int usage;
    unsigned int pool;
    unsigned int multisampleType;
    unsigned int multisampleQuality;
    unsigned int width;
    unsigned int height;
};
struct AdditionalDepthDevice
{
    void** vtable;
};
typedef unsigned long(__stdcall* DepthAddRef)(void*);
typedef long(__stdcall* DepthAcquireSurface)(void*, void*, int, D3DSurface_e7d250**);
typedef long(__stdcall* DepthGetDescription)(void*, DepthSurfaceDescription*);
class AdditionalDepthData : public NiDX92DBufferDataStub
{
  public:
    AdditionalDepthDevice* device;
    AdditionalDepthData() throw() : device(0)
    {}
    virtual ~AdditionalDepthData()
    {}
};
extern char DAT_010ef028;
AdditionalDepthData* __cdecl CreateDepthBufferData(AdditionalDepthDevice* device, void* surfaceSource, int, int,
                                                   Ni2DBufferStub** buffer);
struct IndexAllocator
{
    int unk00;
};
struct IndexArray;
void __cdecl FUN_00c908c0(IndexAllocator* alloc, IndexArray* arr, int newCap, int elemSize);
void* __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int n);
struct IndexArray
{
    unsigned short* data;
    int size;
    unsigned int capacity;
};
void __cdecl AppendIndices(int primType, const unsigned short* src, int count, int offset, IndexArray* out);
struct HeapAlloc
{
    virtual void* v00();
    virtual void v04();
    virtual void* v08(int* size);
    virtual void v0c(void* p, int size);
    virtual void ReturnMemory(void* p, int size);
};
struct MemRouter
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    HeapAlloc* heap;
};
inline MemRouter* getRouter() throw()
{
    return (MemRouter*)FUN_00c85750();
}
void __cdecl ResizeAudioStream(HeapAlloc* alloc, void* arr, int elemSize);
template <class T> inline void construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct IntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const int& e)
    {
        MemRouter* rr = getRouter();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(rr->heap, this, 4);
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};
struct U16Array
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_pStackAllocation;

    __forceinline void ClearAndRelease(HeapAlloc* alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * 2);
    }
};
struct IndexSource
{
    unsigned char type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int count;
    int unk0c;
    int unk10;
    unsigned char mode;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    int unk18;
};
inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline bool isTri(int t)
{
    switch (t)
    {
    case 3:
    case 4:
        return true;
    }
    return false;
}
void __cdecl FUN_00e60e40(int type, int count, int data, IntArray* out);
void __cdecl FUN_00e60f50(int type, int data, int count, int base, IntArray* out);
void __cdecl AppendIndices(int type, int data, int count, int base, U16Array* out);
void __cdecl BuildIndexArray(IndexSource* src, IntArray* out);
enum hkResultE63E
{
    HK_SUCCESS_E63E = 0,
    HK_FAILURE_E63E = 1
};
struct hkPairE63E
{
    void* m_key;
    unsigned int m_uiFilterValue;
};
class hkMapE63E
{
  public:
    int unk00;
    int unk04;
    hkPairE63E* m_pairs;
    int m_numPairs;

    hkResultE63E FindValue(void* key, unsigned int* out) const;
};
struct FnvCpu_FUN_00e687f0_CpuObject
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
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    int value;
    int FUN_00e687f0();
};
struct FnvCpu_FUN_00e68800_CpuObject
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
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    int value;
    int FUN_00e68800();
};
struct FUN_00e76620_cls
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
    unsigned char unk34;
    unsigned char __thiscall FUN_00e76620();
};
void __cdecl FUN_00c908c0(void*, IndexArray*, int, int);
void __cdecl AppendIndexSequence(int type, int count, int start, IndexArray* output, void* allocator);
class AllocatorE60F;
struct RouterE60F
{
    int unk00, unk04, unk08, unk0C;
    AllocatorE60F* m_pStreamAllocator;

    AllocatorE60F& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterE60F {
extern "C" RouterE60F& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(AllocatorE60F& kAlloc, void* pArray, int iNumElements, int iSizeElem);
void* __cdecl FUN_00cb1260(void* pDst, const void* pSrc, int iNumBytes);
template <class T> class hkArrayE60F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline T* expandBy(int n)
    {
        AllocatorE60F& kAlloc = hkRouterE60F::FUN_00c85750().heap();
        int iOldSize = m_iElementCount;
        int iNewSize = iOldSize + n;
        if (getCapacity() < iNewSize)
        {
            int iCap2 = 2 * getCapacity();
            int iNewCap = (iNewSize < iCap2) ? iCap2 : iNewSize;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
        m_iElementCount += n;
        return m_data + iOldSize;
    }
};
void __cdecl FUN_00e60f50(int iType, const int* piIndices, int iNumIndices, int iOffset, hkArrayE60F<int>& kOut);
extern "C" double DAT_010229b8;
static float FUN_00e62ac0(unsigned seed);
volatile unsigned g_e62ac0_seed = 12345u;
volatile float g_e62ac0_sink;
void e62ac0_probe_caller(void);
// SetVec3FromHelper - 36 bytes at 0x00e62af0 (/MT /O2 /GS /EHsc /Gy)
// void body: out receives the same float three times, and out arrives in
// EDX: this function only exists under a compiler-chosen custom calling
// convention (static callee, caller built the stack args and cleans them,
// hence the plain `ret`).  The convention register is steered by the exact
// clobber set of the in-TU callee: helper() visibly clobbers EAX and ECX
// (imul / shl with a variable count), so `out`, which must live across the
// call, gets the only remaining volatile register: EDX.
//   call 0xe62ac0            ; helper, result in st(0)
//   fld  [esp+4] / fld st(0) / faddp st(2) / fsubr [esp+8] / fmulp st(1)
//   fstp [esp+4] / fld [esp+4]
//   fst [edx] / fst [edx+4] / fstp [edx+8]
//   ret
struct Vec3
{
    float x;
    float y;
    float z;
};
int g_cn = 5;
int g_c2 = 7;
extern float __declspec(noinline) helper()
{
    g_cn = (g_cn * 3) << (g_c2 & 31);
    return 1.0f;
}
static void SetVec3FromHelper(Vec3* out, float a, float b);
void FUN_dummycaller();
static void SwapFloatPair(float* base, int i, float* outB, float a, float b, unsigned __int64 outA);
float* volatile g_e64_base;
int volatile g_e64_i;
float* volatile g_e64_outB;
float volatile g_e64_a;
float volatile g_e64_b;
float* volatile g_e64_outA;
void dummy_call_e64fe0(void);
struct E65020Entry
{
    int unk00;
    float m_fValue;
};
static float FUN_00e65020(E65020Entry* pkEntries, int iIndex, float fValue);
float E65020Swap(E65020Entry* pkEntries, int iIndex, float fValue);
void __cdecl FUN_00e67560();
struct FUN_00e68820_cls
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
    int FUN_00e68820();
};
struct FUN_00e69620_Target
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0(int a);
};
struct FUN_00e69620_cls
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
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    FUN_00e69620_Target* unk884;
    void FUN_00e69620();
};
typedef int D3DFORMAT;
typedef int D3DDEVTYPE;
struct S00e7b590_Mode
{
    unsigned int Width;
    unsigned int Height;
    unsigned int RefreshRate;
    D3DFORMAT Format;
};
struct S00e7b590_Caps
{
    D3DDEVTYPE DeviceType;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    int ca0;
    int ca4;
    int ca8;
    int cac;
    int cb0;
    int cb4;
    int cb8;
    int cbc;
    int cc0;
    int cc4;
    int cc8;
    int ccc;
    int cd0;
    int cd4;
    int cd8;
    int cdc;
    int ce0;
    int ce4;
    int ce8;
    int cec;
    int cf0;
    int cf4;
    int cf8;
    int cfc;
    int c100;
    int c104;
    int c108;
    int c10c;
    int c110;
    int c114;
    int c118;
    int c11c;
    int c120;
    int c124;
    int c128;
    int c12c;
};
struct S00e7b590_D3D
{
    virtual int v_a();
    virtual int v_b();
    virtual int v_c();
    virtual int v_d();
    virtual int v_e();
    virtual int v_f();
    virtual unsigned int __stdcall GetAdapterModeCount(unsigned int a, D3DFORMAT f);
    virtual int __stdcall EnumAdapterModes(unsigned int a, D3DFORMAT f, unsigned int i, S00e7b590_Mode* m);
    virtual int v_g();
    virtual int __stdcall CheckDeviceType(unsigned int a, D3DDEVTYPE t, D3DFORMAT d, D3DFORMAT b, int w);
    virtual int v_h();
    virtual int v_i();
    virtual int v_j();
    virtual int v_k();
    virtual int __stdcall GetDeviceCaps(unsigned int a, D3DDEVTYPE t, S00e7b590_Caps* c);
};
struct OuterNode
{

    OuterNode* next;

    int unk04;

    D3DFORMAT format;
};
__forceinline D3DFORMAT const& GetOuterNext168(OuterNode*& position)
{

    D3DFORMAT const* value = &position->format;

    position = position->next;

    return *value;
}
typedef S00e7b590_Mode Desc;
struct ModeMap404
{
    virtual ~ModeMap404();
    unsigned int bucketCount;
    void* buckets;
    unsigned int count;
};
struct ModeItem404
{
    D3DFORMAT key;
    bool b4;
    bool fullscreenSupported;
    ModeMap404 modes;
};
struct ListNode
{

    ListNode* next;

    ListNode* prev;

    ModeItem404* item;
};
__forceinline ModeItem404* const& GetNext(ListNode*& pos)
{

    ModeItem404* const* p = &pos->item;

    pos = pos->next;

    return *p;
}
struct FUN_00e7b260 : ModeItem404
{

    static void* operator new(unsigned int size) throw();

    FUN_00e7b260(S00e7b590_D3D* dev, int ctx, D3DDEVTYPE id, D3DFORMAT key, bool fullscreen, bool windowed) throw();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
class GlobalObject_0096a2d0
{

  public:
    unsigned int state;

    void Lock(const char*);
};
extern ListNode* DAT_011c5f58;
extern GlobalObject_0096a2d0 g_011c5f80;
extern unsigned int DAT_011c5f84;
void __cdecl FUN_0043a080();
struct ItemList168
{

    ListNode* head;
    ListNode* tail;
    unsigned int count;

    ItemList168()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
};
struct FUN_00e7b590
{

    D3DDEVTYPE m_iOwnerObjectOffset;

    S00e7b590_Caps caps;

    ItemList168 items;

    unsigned char m_flag140;

    FUN_00e7b590(S00e7b590_D3D* dev, int ctx, D3DDEVTYPE id, D3DFORMAT a4, OuterNode** ppList);
};
struct FUN_00e7ce10_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a77980_shell* m_0c;
    int unk10;
    int m_14;

    unsigned char FUN_00e7ce10();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
class ItemE7CF
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58(void* pArg);
};
template <class T> struct NiTListItemE7CF
{
    NiTListItemE7CF* m_pkNext;
    NiTListItemE7CF* m_pkPrev;
    T m_element;
};
typedef void* NiTListIterator;
template <class T> class NiTListE7CF
{
  public:
    void* m_vtbl;
    NiTListItemE7CF<T>* m_pkHead;
    NiTListItemE7CF<T>* m_pkTail;

    NiTListIterator GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListIterator& kPos) const
    {
        const T& element = ((NiTListItemE7CF<T>*)kPos)->m_element;
        kPos = ((NiTListItemE7CF<T>*)kPos)->m_pkNext;
        return element;
    }
};
struct CriticalSectionE7CF
{
    int unk00[6];
};
extern CriticalSectionE7CF DAT_0126f600;
extern NiTListE7CF<ItemE7CF*> DAT_0126f5c8;
void __cdecl FUN_00e7cf00(void* pArg);
struct SurfDesc
{
    int Format;
    int Type;
    unsigned Usage;
    int Pool;
    int MS;
    unsigned MSQ;
    unsigned Width;
    unsigned Height;
};
struct Surf
{
    virtual long QI();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual long __stdcall GetDesc(SurfDesc*);
};
struct Swap
{
    virtual long QI();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
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
    virtual long __stdcall GetSurf(unsigned, Surf**);
};
struct Tex
{
    void SetValues(unsigned, unsigned);
};
const char* FUN_00e7a9a0(int);
void FUN_00a29680(const char*, ...);
extern int DAT_0126f580;
extern int DAT_0126f590;
class RT
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
    virtual void ReleaseSurf();
    int m4;
    Tex* m_pkTex;
    CE7C500PixelFormat* m_iFmt;
    int m10;
    Surf* m_pkSurf;
    char pad[0x58 - 0x18];
    Swap* m_pkSwap;
    bool FUN_00e7d0a0(Swap* pkSwap);
};
int ApplyOperator(int op, int val);
struct RouterX
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    HeapAlloc* m_pStreamAllocator;
    __forceinline HeapAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct IntArrayX
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(HeapAlloc& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0((IndexAllocator*)&alloc, (IndexArray*)this, newSize, sizeof(int));
        }
    }
    __forceinline int* expandBy(int n)
    {
        HeapAlloc& alloc = ((RouterX*)FUN_00c85750())->heap();
        int oldSize = m_iElementCount;
        GrowArrayCapacity(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }
};
void __cdecl FUN_00e60e40(int type, int count, int data, IntArray* out);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } lanes;
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" void _mm_store_ss(float*, __m128);
__forceinline float dot3(__m128 p)
{
    float value;
    _mm_store_ss(&value, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p)));
    return value;
}
__forceinline void dotOut(__m128 p, float& value)
{
    _mm_store_ss(&value, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p)));
}
__forceinline void lengths(__m128 a, __m128 b, float& aa, float& cc, float& cross)
{
    aa = dot3(_mm_mul_ps(a, a));
    dotOut(_mm_mul_ps(b, b), cc);
    cross = dot3(_mm_mul_ps(b, a));
}
struct BarycentricResult
{
    float u, v, w;
};
void __cdecl FUN_00e61a10(const __m128* point, const __m128* a, const __m128* b, const __m128* c,
                          BarycentricResult* result);
void __cdecl FUN_00e67550();
bool __cdecl SetModeFlags(int mode, int* outValue, unsigned int* flags);
namespace se695c0 {

struct Block;
int SelectFormatTileValue(int iArg, Block* pkBlock);

struct Block
{
    int unk00;
};

struct Owner
{
    int unk000;
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
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    Block m_kBlock;

    int FUN_00e695c0(int iArg);
};

// @fnv 0x00e695c0
int Owner::FUN_00e695c0(int iArg)
{
    return SelectFormatTileValue(iArg, &m_kBlock);
}

}
struct NiDX9DepthStencilEntry
{
    unsigned char m_bStreamFlag;
    unsigned char m_ucQuality;
    unsigned short m_usMultiSampleMask;
};
struct NiDX9RenderTargetInfo
{
    NiDX9DepthStencilEntry m_akWindowed[9];
    NiDX9DepthStencilEntry m_akFullscreen[9];
};
struct SearchIndex
{
    __declspec(noalias) bool Lookup(unsigned int key, NiDX9RenderTargetInfo** out);
};
extern "C" int __cdecl abs(int v);
extern unsigned int DAT_011bf140[];
int __cdecl FUN_00e7a8b0(unsigned int tbl, int* a, unsigned int* b);
class DepthStencilSearch
{
  public:
    int unk00;
    int unk04;
    SearchIndex m_08;
    int FindBestFullscreenFormat(unsigned int p1, int p2, int p3);
};
struct ClosestList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiTListItem<int>* m_pkHead;
    static int GetNext(NiTListItem<int>*& pos)
    {
        int* elem = &pos->m_element;
        pos = pos->m_pkNext;
        return *elem;
    }
    int FUN_00e7af60(int target);
};
int FUN_00e7ccf0(unsigned int index);
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f59c;
GlobalObjectO2_00a7b610* FUN_00e7cd30();
class FUN_00e7a5e0_Object
{
  public:
    virtual ~FUN_00e7a5e0_Object()
    {
        NiFree(m_pResource);
    }

    void* m_pResource;

    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }

    FUN_00e7a5e0_Object* FUN_00e7a5e0(unsigned int uiFlags);
};
struct NiFilenameQ
{
    char m_acFolderPath[256];
    char m_acDriveLetter[3];
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acPlatformSubDir[256];
    void FUN_00aa27d0(const char* pcFullPath);
};
struct NiFileQ
{
    virtual void Release(int bDelete);
    virtual bool IsValid();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual unsigned int GetFileSize();
    unsigned int ReadBytes(void* pvBuffer, unsigned int uiBytes);
};
struct D3DXImageInfoQ
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Depth;
    unsigned int MipLevels;
    int Format;
    int ResourceType;
    int m_iImageFileFormat;
};
struct D3DBaseTextureQ
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct DDSFileHeaderQ
{
    unsigned int dwMagic;
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int m_uiPitchOrLinearSize;
    unsigned int dwDepth;
    unsigned int dwMipMapCount;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    unsigned int dwReserved2;
    unsigned int dwReserved3;
    unsigned int dwReserved4;
    unsigned int dwReserved5;
    unsigned int dwReserved6;
    unsigned int dwReserved7;
    unsigned int dwReserved8;
    unsigned int dwReserved9;
    unsigned int dwReserved10;
    unsigned int dwPFSize;
    unsigned int dwPFFlags;
    unsigned int dwFourCC;
};
struct NiDX9RendererQ
{
    int unk000;
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
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    void* m_pDirect3DDevice;
    void* GetD3DDevice() const
    {
        return m_pDirect3DDevice;
    }
};
struct FormatPrefsQ
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};
struct MemoryManagerQ : MemoryManager
{
    void* FUN_00aa3e40(unsigned int uiSize);
};
template <class T> __forceinline T NiMaxQ(T a, T b)
{
    return (a > b) ? a : b;
}
template <class T> __forceinline T NiMinQ(T a, T b)
{
    return (a < b) ? a : b;
}
__forceinline bool IsBumpFormatQ(int eFormat)
{
    return eFormat == 0x3c || eFormat == 0x3f || eFormat == 0x40 || eFormat == 0x6e || eFormat == 0x75 ||
           eFormat == 0x3d || eFormat == 0x3e || eFormat == 0x43;
}
int __cdecl FUN_00ec65a6(char* pcDest, unsigned int uiDestSize, const char* pcSrc);
void __cdecl FUN_00aa2a00(char* pcPath);
int __cdecl FUN_00aa1360(const char* s1, const char* s2);
NiFileQ* __cdecl FUN_00aa1a20(const char* pcName, int eMode, unsigned int uiBufferSize);
void* __cdecl FUN_00aa1070(unsigned int uiSize);
void __cdecl FUN_00aa10f0(void* pvMem);
void* __cdecl FUN_00ec44d0(void* pvDest, const void* pvSrc, unsigned int uiSize);
long __stdcall FUN_00ee6e22(const void* pvSrc, unsigned int uiSize, D3DXImageInfoQ* pkInfo);
__declspec(noalias) long __stdcall FUN_00ee6e1c(void* pkDevice, const void* pvSrc, unsigned int uiSize,
                                                D3DBaseTextureQ** ppkTexture);
long __stdcall FUN_00ee6e16(void* pkDevice, const void* pvSrc, unsigned int uiSize, D3DBaseTextureQ** ppkTexture);
long __stdcall FUN_00ee6e10(void* pkDevice, const void* pvSrc, unsigned int uiSize, D3DBaseTextureQ** ppkTexture);
extern unsigned int DAT_0126efc4;
extern unsigned int DAT_0126efc8;
struct LocalGroup2
{
    unsigned int mipCount;
    void* device;
};
struct LocalGroup3
{
    unsigned char* data;
    D3DBaseTextureQ* texture;
    unsigned int divisor;
};
struct NiDX9SourceTextureDataQ
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual bool SetD3DTexture(D3DBaseTextureQ* pkD3DTexture);

    int unk04;
    int unk08;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;

    bool LoadFromFilename(const char* pcFilename, NiDX9RendererQ* pkRenderer, const FormatPrefsQ& kPrefs,
                          NiFileQ* pkFile);
};
extern int DAT_010eec9c;
void* __cdecl NiMalloc(unsigned int size);
struct DisplayMode
{
    unsigned int width;
    unsigned int height;
    unsigned int refresh;
    int format;
};
struct CurrentMode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct AdapterApi
{
    virtual long __stdcall f00() throw() = 0;
    virtual long __stdcall f04() throw() = 0;
    virtual long __stdcall f08() throw() = 0;
    virtual long __stdcall f0C() throw() = 0;
    virtual long __stdcall f10() throw() = 0;
    virtual long __stdcall GetDesc(int handle, int flags, void* out) throw() = 0;
    virtual unsigned int __stdcall GetCount(int handle, int name) throw() = 0;
    virtual long __stdcall GetParam(int handle, int name, unsigned int index, DisplayMode* out) throw() = 0;
    virtual long __stdcall GetTech(int handle, CurrentMode* out) throw() = 0;
};
struct SpinLk
{
    int owner;
    unsigned int count;
    void Lock(const char* name = 0) throw();
    void Unlock() throw()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern SpinLk DAT_011c5f80;
struct ListItem
{
    ListItem* next;
    ListItem* prev;
    unsigned int data;
};
struct NiTAbstractPoolAllocator_unsigned_int
{
    ListItem* head;
};
extern NiTAbstractPoolAllocator_unsigned_int NiTAbstractPoolAllocator_unsigned_int_instance;
struct PoolAlloc
{
    static ListItem* Allocate() throw()
    {
        DAT_011c5f80.Lock();
        if (!NiTAbstractPoolAllocator_unsigned_int_instance.head)
            FUN_0043a080();
        ListItem* p = NiTAbstractPoolAllocator_unsigned_int_instance.head;
        ListItem*& next = ((NiTAbstractPoolAllocator_unsigned_int_instance.head)->next);
        NiTAbstractPoolAllocator_unsigned_int_instance.head = next;
        p->data = 0;
        p->next = 0;
        p->prev = 0;
        DAT_011c5f80.Unlock();
        return p;
    }
};
struct PtrList
{
    ListItem* head;
    ListItem* tail;
    unsigned int count;
    PtrList() throw()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    void AddTail(const unsigned int& v) throw()
    {
        ListItem* n = PoolAlloc::Allocate();
        n->data = v;
        n->next = 0;
        n->prev = tail;
        if (tail)
            tail->next = n;
        else
            head = n;
        count++;
        tail = n;
    }
    void AddHead(const unsigned int& v) throw()
    {
        ListItem* n = PoolAlloc::Allocate();
        n->data = v;
        n->prev = 0;
        n->next = head;
        if (head)
            head->prev = n;
        else
            tail = n;
        count++;
        head = n;
    }
};
int __cdecl FUN_00e7acb0(int name) throw();
struct DisplayModeInfo
{
    unsigned int width;
    unsigned int height;
    int unk08;
    int format;
    PtrList list;
    DisplayModeInfo(const DisplayMode& d) throw() : width(d.width), height(d.height), format(d.format)
    {
        list.AddHead(d.refresh);
        unk08 = FUN_00e7acb0(d.format);
    }
    void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};
struct FormatNode
{
    FormatNode* next;
    FormatNode* prev;
    unsigned int data;
};
struct FormatList
{
    FormatNode* head;
};
template <class T> class ModeStorage
{
  public:
    static T* Allocate(unsigned int n) throw()
    {
        return (T*)NiMalloc(sizeof(T) * n);
    }
};
template <class T, class TAlloc> class ModeArrayBase
{
  public:
    void* m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    ModeArrayBase(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
    {
        m_ppVirtualMethodTable = &DAT_010eec74;
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    void FUN_00a90180(unsigned int size) throw();
    void SetAt(unsigned int uiIndex, const T& element) throw()
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element) throw()
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00a90180(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element) throw()
    {
        return SetAtGrow(m_usSize, element);
    }
};
template <class T> class ModeArray : public ModeArrayBase<T, ModeStorage<T> >
{
  public:
    ModeArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : ModeArrayBase<T, ModeStorage<T> >(uiMaxSize, uiGrowBy)
    {
        this->m_ppVirtualMethodTable = &DAT_010eec9c;
    }
};
struct FUN_00e7b7d0
{
    int m_handle;
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
    ModeArray<DisplayModeInfo*> m_entries;
    FUN_00e7b590* m_stage1;
    FUN_00e7b590* m_stage2;
    FUN_00e7b7d0(AdapterApi* fx, int handle, FormatList& names);
};
struct S00e60650
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int value;
    int FUN_00e60650();
};
// FUN_00e60660: __thiscall accessor, returns this ? &this->field_14 : 0
struct FUN_00e60660_Cls;
struct FUN_00e60660_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int* __thiscall FUN_00e60660();
};
extern const char DAT_010ed328[];
extern const char DAT_010ed2d0[];
struct TextureAccessor
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int format;
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
    unsigned char* data;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int unk70;
    unsigned int mipCount;
    unsigned int pixelSize;
};
void __cdecl FUN_00e683d0(TextureAccessor* source, unsigned int level, CopySurface* surface, unsigned int face);
extern int DAT_010eec54;
extern int DAT_010eec7c;
void* __cdecl FUN_00ec61c0(void* p, int c, unsigned int n);
int __cdecl MapIndexToValue(unsigned int eFormat);
struct RTInfoZ : NiDX9RenderTargetInfo
{
    RTInfoZ()
    {
        unsigned int* puiData = reinterpret_cast<unsigned int*>(this);
        for (unsigned int n = 0; n < sizeof(*this) / sizeof(unsigned int); n++)
            puiData[n] = 0;
    }
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct D3DProbe
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1c();
    virtual int v20();
    virtual int v24();
    virtual int __stdcall CheckDeviceFormat(unsigned int a, int t, int af, unsigned int u, int rt, int cf);
    virtual int __stdcall CheckDeviceMultiSampleType(unsigned int a, int t, int sf, int w, int mt, unsigned int* q);
    virtual int __stdcall CheckDepthStencilMatch(unsigned int a, int t, int af, int rf, int df);
};
struct MapSetAt
{
    void InsertOrUpdate(unsigned int key, void* val);
};
struct ModeItemInit
{
    FUN_00e7b260* FUN_00e7b260(S00e7b590_D3D* dev, int ctx, D3DDEVTYPE eDeviceType, D3DFORMAT eAdapterFormat,
                               bool bFullscreen, bool bWindowed);
};
void __cdecl FUN_00e7cec0();
struct RendererE7D6B0
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
    virtual int GetA();
    virtual bool GetB();
};
extern RendererE7D6B0* g_rendererE7D6B0;
extern int g_dsAE7D6B0;
extern bool g_dsBE7D6B0;
struct PresentParamsE7D6B0
{
    unsigned int BackBufferWidth;
    unsigned int BackBufferHeight;
    int BackBufferFormat;
    unsigned int BackBufferCount;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    int SwapEffect;
    void* hDeviceWindow;
    int Windowed;
    int EnableAutoDepthStencil;
    int AutoDepthStencilFormat;
    unsigned long Flags;
    unsigned int FullScreen_RefreshRateInHz;
    unsigned int PresentationInterval;
};
struct DeviceE7D6B0
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall v03() = 0;
    virtual void __stdcall v04() = 0;
    virtual void __stdcall v05() = 0;
    virtual void __stdcall v06() = 0;
    virtual void __stdcall v07() = 0;
    virtual void __stdcall v08() = 0;
    virtual void __stdcall v09() = 0;
    virtual void __stdcall v10() = 0;
    virtual void __stdcall v11() = 0;
    virtual void __stdcall v12() = 0;
    virtual void __stdcall v13() = 0;
    virtual void __stdcall v14() = 0;
    virtual void __stdcall v15() = 0;
    virtual void __stdcall v16() = 0;
    virtual void __stdcall v17() = 0;
    virtual void __stdcall v18() = 0;
    virtual void __stdcall v19() = 0;
    virtual void __stdcall v20() = 0;
    virtual void __stdcall v21() = 0;
    virtual void __stdcall v22() = 0;
    virtual void __stdcall v23() = 0;
    virtual void __stdcall v24() = 0;
    virtual void __stdcall v25() = 0;
    virtual void __stdcall v26() = 0;
    virtual void __stdcall v27() = 0;
    virtual void __stdcall v28() = 0;
    virtual void __stdcall v29() = 0;
    virtual void __stdcall v30() = 0;
    virtual void __stdcall v31() = 0;
    virtual void __stdcall v32() = 0;
    virtual void __stdcall v33() = 0;
    virtual void __stdcall v34() = 0;
    virtual void __stdcall v35() = 0;
    virtual void __stdcall v36() = 0;
    virtual void __stdcall v37() = 0;
    virtual long __stdcall GetRenderTarget(unsigned long RenderTargetIndex, D3DSurface_e7d250** ppRenderTarget) = 0;
};
class SwapChainBufferData : public NiDX92DBufferDataStub
{
  public:
    SwapChainBufferData() throw()
    {
        m_pkDevice = 0;
    }
    virtual ~SwapChainBufferData();
    PresentParamsE7D6B0 m_kParams;
    DeviceE7D6B0* m_pkDevice;
};
SwapChainBufferData* __cdecl FUN_00e7d6b0(DeviceE7D6B0* pkDevice, PresentParamsE7D6B0* pkParams,
                                          Ni2DBufferStub** ppkBuffer);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern __m128 DAT_010c44d0;
class XfCallee
{
  public:
    virtual void v0();
    virtual void v1(void* a, void* b);
};
__declspec(align(16)) struct XfVecBuf
{
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};
class XfTransformBlock
{
  public:
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;
    __m128 m_row3;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    XfCallee* m_pCalleeA;
    XfCallee* m_pCalleeB;
    void FUN_00e62b20(__m128* in, __m128* out);
};
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);
struct __declspec(align(16)) Vector
{
    __m128 value;
    __forceinline __m128 get() const
    {
        return value;
    }
    __forceinline void set(__m128 v)
    {
        value = v;
    }
};
struct Id
{
    unsigned int v;
};
union IdUnion
{
    unsigned int v;
};
struct IdCtor
{
    unsigned int v;
    IdCtor(unsigned int x) : v(x)
    {}
};
struct SupportResult
{
    Vector position;
    Vector field10;
    Vector field20;
    unsigned int field30;
    __forceinline void assign(const SupportResult& b, __m128 p)
    {
        __m128 a = b.field10.get();
        field10.set(a);
        __m128 c = b.field20.get();
        position.set(p);
        field20.set(c);
        field30 = b.field30;
    }
};
template <class T> struct Arg
{
    T* p;
    Arg(T* value) : p(value)
    {}
};
struct PodDir
{
    const Vector* p;
};
union UnionDir
{
    const Vector* p;
};
struct PodDst
{
    SupportResult* p;
};
struct SupportOwner
{
    void FUN_00e62b20(const Vector* direction, SupportResult* result);
    __m128* FUN_00e62c60(Arg<__m128> out, const Vector* direction, Arg<const __m128> point, Arg<SupportResult> result);
};
extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, __m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    void _ReadWriteBarrier();
    void _WriteBarrier();
}
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
struct PlaneVector
{
    __m128 m_vComponents;
    __forceinline void difference(const PlaneVector& a, const PlaneVector& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void cross(const PlaneVector& a, const PlaneVector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                  _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(first, second);
    }
    __forceinline __m128 dot(const PlaneVector& a) const
    {
        __m128 products = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), xy);
    }
    __forceinline __m128 inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 squareSum = dot(*this);
        __m128 mask = _mm_cmpeq_ss(squareSum, zero);
        __m128 estimate = _mm_rsqrt_ss(squareSum);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squareSum, estimate), estimate));
        return _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, estimate), correction));
    }
    __forceinline void normalize()
    {
        __m128 factor = inverseLength();
        factor = _mm_shuffle_ps(factor, factor, 0);
        m_vComponents = _mm_mul_ps(factor, m_vComponents);
    }
    __forceinline float dotFloat(const PlaneVector& a) const
    {
        float value;
        _mm_store_ss(&value, dot(a));
        return value;
    }
};
struct TrianglePlane
{
    PlaneVector m_00;
    PlaneVector* m_10;
    int m_14;
    int m_18;
    int m_1c;
    PlaneVector* m_20;
    int m_24;
    int m_28;
    int m_2c;
    PlaneVector* m_30;
    int m_34;
    int m_38;
    int m_3c;
    float m_40;

    void FUN_00e67570();
};
extern "C" __m128 _mm_sqrt_ss(__m128);
struct S00e61d30_TriVerts
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
};
static inline __m128 Sum3(__m128 a, __m128 b)
{
    __m128 m = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
}
void FUN_00e61d30(const S00e61d30_TriVerts* tri, float* out);
extern "C"
{
    double __cdecl fabs(double x);
}
struct S00e67ae0_HullFace;
struct S00e67ae0_HullEdge
{
    __m128* m_kRayStart;
    __m128** m_kRayEnd;
    S00e67ae0_HullEdge* m_twin;
    S00e67ae0_HullFace* m_face;
};
struct S00e67ae0_HullFace
{
    __m128 m_vHitNormal;
    S00e67ae0_HullEdge m_kEdges[3];
    float m_fClosestPointDistanceSquared;
    int m_uiContentCount;
};
struct S00e67ae0_HullWalker
{
    void ClearEntries();
    S00e67ae0_HullFace* FUN_00e67ae0(S00e67ae0_HullFace* start);
};
extern "C" Ni2DBufferStub* __cdecl FUN_00a9ff60(unsigned int width, unsigned int height, RendererDataStub* data);
NiPixelFormat* __cdecl CreatePixelFormat(unsigned int eD3DFormat);
struct D3DDevice_e7d850
{
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf0A() = 0;
    virtual void vf0B() = 0;
    virtual void vf0C() = 0;
    virtual void vf0D() = 0;
    virtual void vf0E() = 0;
    virtual void vf0F() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf1A() = 0;
    virtual void vf1B() = 0;
    virtual void vf1C() = 0;
    virtual void vf1D() = 0;
    virtual void vf1E() = 0;
    virtual void vf1F() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual long __stdcall GetDepthStencilSurface(D3DSurface_e7d250** ppZStencilSurface) = 0;
};
class NiDX9AdditionalDepthStencilBufferData : public NiDX92DBufferDataStub
{
  public:
    NiDX9AdditionalDepthStencilBufferData() throw()
    {}
    virtual ~NiDX9AdditionalDepthStencilBufferData();
};
NiDX9AdditionalDepthStencilBufferData* __cdecl FUN_00e7d850(D3DDevice_e7d850* pkD3DDevice, Ni2DBufferStub*& pkBuffer);

extern "C" void _ReadBarrier();
static __forceinline void CopySupport_e63770(::__m128*& out, int index, const ::__m128& source)
{
    ::__m128 value = source;
    _ReadBarrier();
    out[index] = value;
}

namespace PenetrationIntrinsics {
extern "C"
{
    ::__m128(_mm_load_ss)(const float* p);
    ::__m128(_mm_load_ps)(const float* p);
    ::__m128(_mm_sub_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_mul_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_add_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_xor_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_cmplt_ps)(::__m128 a, ::__m128 b);
    int(_mm_movemask_ps)(::__m128 a);
    ::__m128(_mm_unpacklo_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_unpackhi_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_movelh_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_movehl_ps)(::__m128 a, ::__m128 b);
    ::__m128(_mm_shuffle_ps)(::__m128 a, ::__m128 b, int imm8);
}
}
extern "C" double DAT_010229b8;
extern double DAT_010dbb40;
extern double DAT_01032980;
extern float DAT_0104da48;

extern ::__m128 DAT_01267e30;
static __declspec(noinline) float FUN_00e62ac0(int seed)
{
    int v = (12345 - seed * 1043968403) & 0x7fffffff;
    return (float)((double)v * DAT_010229b8);
}
struct E63Vert
{
    ::__m128 m_00;
    ::__m128 m_10;
    ::__m128 m_20;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
};
class E63Edge;
class E63Face
{
  public:
    ::__m128 m_vHitNormal;
    E63Vert* m_v0;
    int unk14;
    E63Edge* m_18;
    int unk1c;
    E63Vert* m_v1;
    int unk24;
    E63Edge* m_28;
    int unk2c;
    E63Vert* m_v2;
    int unk34;
    E63Edge* m_38;
    int unk3c;
    float m_40;
    int m_44;
    int unk48;
    int unk4c;
    int Callee00e63af0(E63Vert* v, float* pMin, float* pMax);
};
template <class T> struct E63Quad
{
    T a, b, c, d;
};
template <class T> struct E63Oct
{
    E63Quad<T> a, b;
};
class E63Hull
{
  public:
    float m_00;
    float m_04;
    int m_uiVertexCount;
    int m_0c;
    int m_10;
    int unk14;
    int unk18;
    int unk1c;
    E63Vert m_vert0;
    E63Vert m_vert1;
    E63Vert m_vert2;
    E63Quad<E63Vert> m_verts3_6;
    E63Oct<E63Vert> m_verts7_14;
    E63Oct<E63Vert> m_verts15_22;
    E63Oct<E63Vert> m_verts23_30;
    E63Oct<E63Vert> m_verts31_38;
    E63Oct<E63Vert> m_verts39_46;
    E63Oct<E63Vert> m_verts47_54;
    E63Quad<E63Face*> m_ptrs0_3;
    E63Oct<E63Quad<E63Face*> > m_ptrs4_35;
    E63Oct<E63Quad<E63Face*> > m_ptrs36_67;
    E63Oct<E63Quad<E63Face*> > m_ptrs68_99;
    E63Quad<E63Face> m_faces0_3;
    E63Oct<E63Quad<E63Face> > m_faces4_35;
    E63Oct<E63Quad<E63Face> > m_faces36_67;
    E63Oct<E63Quad<E63Face> > m_faces68_99;
    void FUN_00e63ba0(::__m128* a, ::__m128* b, ::__m128* c);
    E63Face* GetNearestEntry();
    int FUN_00e67660(E63Face* a1, E63Vert* a2, int* a3, E63Edge** a4);
    int FUN_00e67740(int numNew, E63Edge* edge, E63Vert* vert);
    E63Face* FUN_00e67ae0(E63Face* face);
};
struct E63Out
{
    union
    {
        ::__m128 m_00;
        struct
        {
            float m_00x;
            float m_00y;
            float m_00z;
            float m_0c;
        };
    };
    ::__m128 m_10;
};
struct Solver
{
    ::__m128 unk00;
    ::__m128 unk10;
    ::__m128 unk20;
    ::__m128 m_30;
    ::__m128 m_40;
    int unk50;
    int unk54;
    int unk58;
    int m_5c;
    ::__m128* m_60;
    ::__m128* m_64;
    ::__m128* m_68;
    int m_6c;
    int FUN_00e62d30(E63Out* out, int* status);
    void FUN_00e62b20(E63Face* face, E63Vert* vert);
    int FUN_00e63770(E63Out* out);
};
static __forceinline void transposeThree(::__m128& a, ::__m128& b, ::__m128& c)
{
    ::__m128 lo = (PenetrationIntrinsics::_mm_unpacklo_ps)(a, b);
    ::__m128 hi = (PenetrationIntrinsics::_mm_unpackhi_ps)(a, b);
    a = (PenetrationIntrinsics::_mm_movelh_ps)(lo, c);
    b = (PenetrationIntrinsics::_mm_shuffle_ps)((PenetrationIntrinsics::_mm_movehl_ps)(a, lo), c, 0xd4);
    c = (PenetrationIntrinsics::_mm_shuffle_ps)(hi, c, 0xe4);
}
static __forceinline int expand(Solver* self, E63Hull& hull, E63Face* face, E63Vert* vert, int& status,
                                E63Edge*& outEdge)
{
    ::__m128 v = vert->m_00;
    ::__m128 d0 = (PenetrationIntrinsics::_mm_sub_ps)(v, face->m_v0->m_00);
    ::__m128 d1 = (PenetrationIntrinsics::_mm_sub_ps)(v, face->m_v1->m_00);
    ::__m128 d2 = (PenetrationIntrinsics::_mm_sub_ps)(v, face->m_v2->m_00);
    transposeThree(d0, d1, d2);
    ::__m128 r2 = d2;
    ::__m128 r1 = d1;
    ::__m128 r0 = d0;
    ::__m128 n = face->m_vHitNormal;
    ::__m128 s01 = (PenetrationIntrinsics::_mm_add_ps)(
        (PenetrationIntrinsics::_mm_mul_ps)(r1, (PenetrationIntrinsics::_mm_shuffle_ps)(n, n, 0x55)),
        (PenetrationIntrinsics::_mm_mul_ps)((PenetrationIntrinsics::_mm_shuffle_ps)(n, n, 0x00), r0));
    ::__m128 dots = (PenetrationIntrinsics::_mm_add_ps)(
        s01, (PenetrationIntrinsics::_mm_mul_ps)(r2, (PenetrationIntrinsics::_mm_shuffle_ps)(n, n, 0xaa)));
    if (((PenetrationIntrinsics::_mm_movemask_ps)((PenetrationIntrinsics::_mm_cmplt_ps)(dots, self->m_40)) & 7) != 0)
    {
        status = 0;
        return 1;
    }
    hull.m_00 = 1e-07f;
    hull.m_04 = DAT_0104da48;
    outEdge = 0;
    status = 0;
    int vis = face->Callee00e63af0(vert, &hull.m_00, &hull.m_04);
    face->m_44 = vis;
    if (vis != 1)
    {
        status = 5;
        return 1;
    }
    if (hull.FUN_00e67660(face, vert, &status, &outEdge) != 0)
    {
        status = 5;
        return 1;
    }
    if (hull.m_0c - hull.m_10 + 100 < status)
    {
        status = 2;
        return 1;
    }
    if (hull.FUN_00e67740(status, outEdge, vert) != 0)
    {
        status = 5;
        return 1;
    }
    return 0;
}
// @fnv 0x00e63770
int Solver::FUN_00e63770(E63Out* out)
{
    int status;
    E63Edge* outEdge;
    ::__m128 bary;
    E63Face* face;
    for (;;)
    {
        status = 0;
        if (FUN_00e62d30(out, &status) == 1)
        {
            if (status != 5)
                return status;
            goto retry_step;
        }
        {
            E63Hull hull;
            hull.FUN_00e63ba0(m_60, m_64, m_68);
            for (;;)
            {
                face = hull.GetNearestEntry();
                int idx = hull.m_uiVertexCount;
                E63Vert* vert = (&hull.m_vert0) + idx;
                hull.m_uiVertexCount = idx + 1;
                vert->m_30 = 0;
                FUN_00e62b20(face, vert);
                int expanded = expand(this, hull, face, vert, status, outEdge);
                if (expanded == 1)
                    break;
                if (hull.m_uiVertexCount >= 0x37)
                {
                    status = 2;
                    break;
                }
            }
            if (status != 5)
            {
                for (int i = 0; i < 10; ++i)
                {
                    m_68[0] = face->m_v0->m_00;
                    m_68[1] = face->m_v1->m_00;
                    m_68[2] = face->m_v2->m_00;
                    FUN_00e61a10(&DAT_01267e30, &m_68[0], &m_68[1], &m_68[2],
                                 reinterpret_cast<BarycentricResult*>(&bary));
                    if (!(bary.lanes.x < 0.0f) && !(bary.lanes.y < 0.0f) && !(bary.lanes.z < 0.0f))
                        goto found_face;
                    face = hull.FUN_00e67ae0(face);
                }
            found_face:
                E63Vert* v0 = face->m_v0;
                CopySupport_e63770(m_60, 0, v0->m_10);
                CopySupport_e63770(m_64, 0, v0->m_20);
                E63Vert* v1 = face->m_v1;
                CopySupport_e63770(m_60, 1, v1->m_10);
                CopySupport_e63770(m_64, 1, v1->m_20);
                E63Vert* v2 = face->m_v2;
                CopySupport_e63770(m_60, 2, v2->m_10);
                CopySupport_e63770(m_64, 2, v2->m_20);

                _ReadBarrier();

                m_6c = 3;
                *(float*)&outEdge = (float)(double)bary.lanes.x;
                ::__m128 bx = (PenetrationIntrinsics::_mm_load_ss)((float*)&outEdge);
                *(float*)&outEdge = (float)(double)bary.lanes.y;
                ::__m128 by = (PenetrationIntrinsics::_mm_load_ss)((float*)&outEdge);
                *(float*)&outEdge = (float)(double)bary.lanes.z;
                ::__m128 bz = (PenetrationIntrinsics::_mm_load_ss)((float*)&outEdge);
                ::__m128* p60 = m_60;
                out->m_10 = (PenetrationIntrinsics::_mm_add_ps)(
                    (PenetrationIntrinsics::_mm_add_ps)(
                        (PenetrationIntrinsics::_mm_mul_ps)((PenetrationIntrinsics::_mm_shuffle_ps)(by, by, 0), p60[1]),
                        (PenetrationIntrinsics::_mm_mul_ps)((PenetrationIntrinsics::_mm_shuffle_ps)(bx, bx, 0),
                                                            p60[0])),
                    (PenetrationIntrinsics::_mm_mul_ps)((PenetrationIntrinsics::_mm_shuffle_ps)(bz, bz, 0), p60[2]));
                out->m_00 = (PenetrationIntrinsics::_mm_xor_ps)(face->m_vHitNormal, DAT_010c44d0);
                out->m_0c = -face->m_40;
                return status;
            }
        }
    retry_step:
        m_5c += 1;
        if (m_5c == 1)
        {
            m_6c = 1;
            continue;
        }
        if (m_5c < 20)
        {
            m_6c = 0;
            *(float*)&outEdge = (float)((FUN_00e62ac0(m_5c) - DAT_01032980) * DAT_010dbb40);
            bary.lanes.x = *(float*)&outEdge;
            bary.lanes.y = *(float*)&outEdge;
            bary.lanes.z = *(float*)&outEdge;
            bary = (PenetrationIntrinsics::_mm_add_ps)(bary, m_30);
            m_30 = bary;
            continue;
        }
        else
        {
            return status;
        }
    }
}
