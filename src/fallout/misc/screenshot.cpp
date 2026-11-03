// src/fallout/misc/screenshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/screenshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include <d3d9.h>
#include <wingdi.h>

struct S_00878f60_AutoMem
{
    int unk00;
    S_00878f60_AutoMem(int context, bool push, const char* file, int line);
    ~S_00878f60_AutoMem();
};

struct S_00878f60_FixedString
{
    const char* m_kHandle;
    S_00878f60_FixedString(const char* s);
    ~S_00878f60_FixedString();
};

struct S_00878f60_FormatPrefs
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
    S_00878f60_FormatPrefs();
};

struct S_00878f60_PixelFormat
{
    int unk00;
};

struct S_00878f60_TexData;

struct S_00878f60_RendererData
{
    S_00878f60_TexData* FUN_0059bb30();
};

struct S_00878f60_Texture
{
    S_00878f60_RendererData* FUN_004bc320(int i);
};

struct S_00878f60_TexPtr
{
    S_00878f60_Texture* m_pObject;
    S_00878f60_TexPtr(S_00878f60_Texture* p);
    ~S_00878f60_TexPtr();
    operator S_00878f60_Texture*() const;
    S_00878f60_Texture* operator->() const;
    S_00878f60_TexPtr& operator=(S_00878f60_Texture* p);
};

struct S_00878f60_RenderedTexture;

struct S_00878f60_MTRender
{
    void FUN_00ba2f30();
    void FUN_00ba30f0(int a, int b);
    void FUN_00ba3130(int a, int b);
    void FUN_00ba2fa0();
};

struct S_00878f60_ImageSpaceManager
{
    static S_00878f60_ImageSpaceManager* FUN_004e3270();
    void FUN_00879860(float a, float b, float c, float d);
    void FUN_008798a0();
};

struct S_00878f60_Player
{
    void UpdateCamera(bool a, bool b);
    void FUN_009466d0(float f, int b);
};

struct S_00878f60_Mgr
{
    void FUN_008706b0(S_00878f60_Texture* tex, int a, int b);
    bool FUN_005bb4d0();
};

S_00878f60_Texture* FUN_00b6b610(const S_00878f60_FixedString& name, unsigned int w, unsigned int h,
                                 S_00878f60_FormatPrefs* prefs, int a, int b, int c, int d, int e);
S_00878f60_MTRender* FUN_004ea970();
int FUN_004dc200();
int FUN_004dc1f0();
void FUN_005b5e40(const char* fmt, ...);
unsigned int FUN_0044a670(const char* s);
int FUN_00aff0b0(const char* path);

extern S_00878f60_Player* DAT_011dea3c;
extern S_00878f60_Mgr* DAT_011dea0c;
extern S_00878f60_PixelFormat DAT_011aa2e8;

struct S_00878f60_Cam
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
};

struct S_00878f60_RendererObj
{
    S_00878f60_Cam* FUN_00878f20();
};

struct S_00878f60_Renderer
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
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual S_00878f60_RendererObj* vfD4();
    IDirect3DDevice9* FUN_004dc020();
};

struct S_00878f60_TexData
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
    virtual IDirect3DTexture9* vf9C();
    virtual void vfA0();
    virtual S_00878f60_TexData* vfA4();
};

struct S_00878f60_File
{
    virtual ~S_00878f60_File();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual bool vf20(int a, int b);
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
    S_00878f60_File(const char* name, int mode, unsigned int bufSize, bool b);
    void FUN_00473180(const void* data, unsigned int size);
};

struct S_00878f60_PixelData
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
    S_00878f60_PixelData(unsigned int w, unsigned int h, const S_00878f60_PixelFormat& fmt, unsigned int mips,
                         unsigned int faces);
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    unsigned char* FUN_0064dac0(int mip, int face);
    int FUN_0070ec90();
};

S_00878f60_Renderer* FUN_004bc3f0();

// Captures the current render target to a pixel buffer, optionally writes a BMP file, and returns the pixel data.
// @fnv 0x00878f60
S_00878f60_PixelData* FUN_00878f60(int* pWidth, int* pHeight, const char* filename)
{
    S_00878f60_AutoMem theMemContext(0x11, true,
                                     "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\ScreenShot.cpp", 0x139);
    S_00878f60_Renderer* r = FUN_004bc3f0();
    FUN_004ea970()->FUN_00ba2f30();
    IDirect3DDevice9* pDevice = r->FUN_004dc020();
    S_00878f60_Cam frustum = *r->vfD4()->FUN_00878f20();
    S_00878f60_FormatPrefs prefs2;
    prefs2.m_eMipFlag = 0;
    prefs2.m_eAlphaFormat = 0;
    S_00878f60_TexPtr eTex(
        FUN_00b6b610(S_00878f60_FixedString("Screenshot RT"), *pWidth, *pHeight, &prefs2, 0, 1, 0, 0, 0));
    if (!eTex)
    {
        FUN_005b5e40("DEFAULT: (ScreenShot) Unable to create render texture.");
        return 0;
    }

    float aspect = (double)FUN_004dc200() / FUN_004dc1f0();
    int outHeight = (int)(*pHeight * aspect);
    DAT_011dea3c->UpdateCamera(false, false);
    S_00878f60_ImageSpaceManager::FUN_004e3270()->FUN_00879860(0.0f, 1.0f, 1.0f, 1.0f - aspect);
    DAT_011dea0c->FUN_008706b0(eTex, 0, 0);
    S_00878f60_ImageSpaceManager::FUN_004e3270()->FUN_008798a0();
    if (DAT_011dea0c->FUN_005bb4d0())
        DAT_011dea3c->FUN_009466d0(0.0f, 1);
    FUN_004ea970()->FUN_00ba30f0(0, 0x17);
    FUN_004ea970()->FUN_00ba3130(1, 0x17);
    FUN_004ea970()->FUN_00ba2fa0();

    S_00878f60_TexData* localTexData = eTex->FUN_004bc320(0)->FUN_0059bb30();
    localTexData = localTexData->vfA4();
    IDirect3DTexture9* d3dTexture = localTexData->vf9C();
    D3DSURFACE_DESC d3dDesc;
    d3dTexture->GetLevelDesc(0, &d3dDesc);
    IDirect3DSurface9* rtSurface;
    d3dTexture->GetSurfaceLevel(0, &rtSurface);
    IDirect3DSurface9* destSurface;
    if (pDevice->CreateOffscreenPlainSurface(*pHeight, *pWidth, d3dDesc.Format, D3DPOOL_SYSTEMMEM, &destSurface, 0))
    {
        FUN_005b5e40("DEFAULT: (ScreenShot) Unable to create image surface.");
        return 0;
    }
    pDevice->GetRenderTargetData(rtSurface, destSurface);
    rtSurface->Release();
    D3DLOCKED_RECT locked;
    destSurface->LockRect(&locked, 0, D3DLOCK_NOSYSLOCK);
    const S_00878f60_PixelFormat* pFormat = &DAT_011aa2e8;
    *pHeight = outHeight;
    S_00878f60_PixelData* thePixelData = new S_00878f60_PixelData(*pWidth, *pHeight, *pFormat, 1, 1);
    unsigned char* in = (unsigned char*)locked.pBits;
    unsigned char* dst_ = thePixelData->FUN_0064dac0(0, 0);
    int jVal = 0;
    for (int i = 0; i < *pWidth * *pHeight * 4; i += 4)
    {
        dst_[jVal] = in[i + 2];
        jVal++;
        dst_[jVal] = in[i + 1];
        jVal++;
        dst_[jVal] = in[i];
        jVal++;
    }
    destSurface->UnlockRect();
    destSurface->Release();
    eTex = 0;

    if (filename && FUN_0044a670(filename))
    {
        FUN_00aff0b0(filename);
        S_00878f60_File* file = new S_00878f60_File(filename, 1, 0x4000, false);
        if (file->vf20(0, 0))
        {
            unsigned int width = *pWidth;
            unsigned int height = *pHeight;
            int bpp = thePixelData->FUN_0070ec90();
            unsigned char* pix = thePixelData->FUN_0064dac0(0, 0);
            unsigned char* buffer = (unsigned char*)operator new(width * height * 3);
            int idx = 0;
            for (int y = height - 1; y >= 0; y--)
            {
                for (unsigned int x = 0; x < width; x++)
                {
                    int offset = width * bpp * y + x * bpp;
                    buffer[idx] = pix[offset + 2];
                    buffer[idx + 1] = pix[offset + 1];
                    buffer[idx + 2] = pix[offset];
                    idx += 3;
                }
            }
            bpp = 3;
            // BITMAPFILEHEADER immediately followed by BITMAPINFOHEADER (54 bytes, packed)
            unsigned int bmpHeader[14];
            ((BITMAPFILEHEADER*)bmpHeader)->bfType = 0x4d42;
            ((BITMAPFILEHEADER*)bmpHeader)->bfSize = width * height * bpp + 0x36;
            ((BITMAPFILEHEADER*)bmpHeader)->bfReserved1 = 0;
            ((BITMAPFILEHEADER*)bmpHeader)->bfReserved2 = 0;
            ((BITMAPFILEHEADER*)bmpHeader)->bfOffBits = 0x36;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biSize = 0x28;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biWidth = width;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biHeight = height;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biPlanes = 1;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biBitCount = bpp * 8;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biCompression = 0;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biSizeImage = width * height * bpp;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biXPelsPerMeter = 0;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biYPelsPerMeter = 0;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biClrUsed = 0;
            ((BITMAPINFOHEADER*)((char*)bmpHeader + sizeof(BITMAPFILEHEADER)))->biClrImportant = 0;
            file->FUN_00473180(bmpHeader, 0x36);
            file->FUN_00473180(buffer, width * height * bpp);
            operator delete(buffer);
        }
        else
        {
            FUN_005b5e40("SAVELOAD: (ScreenShot) Unable to create file '%s'.", filename);
        }
        delete file;
    }
    return thePixelData;
}
