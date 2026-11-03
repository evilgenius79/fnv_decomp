// src/fallout_shared/tesland_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesland.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "tesland_decls.h"
int TruncateFloatToInt(float value);

struct CacheLookup
{
    bool FUN_00a53c30(const char*, void*&);
};

struct CacheEntry
{
    int unk00;
    const char* name;
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
    CacheLookup lookup;
};

CacheLookup* GetArrayHolder();

// @fnv 0x00b61940
bool FUN_00b61940(void* entry, const char* key)
{
    const char* groupName = static_cast<CacheEntry*>(entry)->name;
    entry = 0;
    if (!GetArrayHolder()->FUN_00a53c30(groupName, entry))
        return false;
    return static_cast<CacheEntry*>(entry)->lookup.FUN_00a53c30(key, entry);
}

struct LandscapeSpecularView
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c;
    unsigned int unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c;
    unsigned int unka0;
    void* textureSet;
    unsigned short textureCount;
    unsigned short unkaa;
    void* textureAc;
    void* textureB0;
    void* textureB4;
    void* textureB8;
    void* textureBc;
    void* textureC0;
    unsigned char* specularExponents;
    void FUN_00b66640(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e,
                      unsigned char f, unsigned char g, unsigned char h, unsigned char i, unsigned char j);
};
// @fnv 0x00b66640
void LandscapeSpecularView::FUN_00b66640(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
                                         unsigned char e, unsigned char f, unsigned char g, unsigned char h,
                                         unsigned char i, unsigned char j)
{
    if (textureCount == 9)
    {
        specularExponents[0] = a;
        specularExponents[1] = b;
        specularExponents[2] = c;
        specularExponents[3] = d;
        specularExponents[4] = e;
        specularExponents[5] = f;
        specularExponents[6] = g;
        specularExponents[7] = h;
        specularExponents[8] = i;
    }
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);
extern bool DAT_0126f0d0;

void __cdecl FUN_00aa1460(void* p, unsigned int s);

struct UploadBatchHeader
{
    enum
    {
        KindMask = 0x7000,
        OwnedKind = 0x4000,
        RetainedFlags = 0xf000
    };
    int unk00;
    int unk04;
    int unk08;
    short unk0c;
    unsigned short flags;

    __forceinline void ClearOwnership()
    {
        flags &= RetainedFlags;
    }

    __forceinline bool OwnsHeader(unsigned int partIndex) const
    {
        return (short)(flags & KindMask) == (short)OwnedKind && partIndex == 0;
    }
};

struct UploadBatchPart
{
    int unk00;
    int unk04;
    void* buffer;
    unsigned int firstByte;
    int allocationFlags;
    unsigned int byteCount;
};

struct UploadBatchArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
    char unk15;
    short unk16;
    int unk18;
    int unk1c;
    unsigned int m_iElementCount;
    int unk24;
    UploadBatchPart** m_data;
    int unk2c;
    int unk30;
    unsigned int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    unsigned short* unk4c;
    void* unk50;

    __forceinline UploadBatchPart* GetPart(unsigned int index) const
    {
        return index < m_iElementCount ? m_data[index] : 0;
    }
};

class UploadBatchDispatch
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual int FUN_00e74288(void* p1, void* p2, void* p3, int p4, UploadBatchPart* p5, unsigned int p6,
                             unsigned int p7, int p8, int p9);
};

struct UploadBatchItem
{
    UploadBatchHeader* unk00;
    void* unk04;
    void* unk08;
    UploadBatchDispatch* unk0c;
    int unk10;
    int unk14;
    UploadBatchArray* unk18;
    unsigned int unk1c;
    UploadBatchItem* next;
};

struct Mgr_e74120_CS
{
    int f00, f04, f08, f0c, f10, f14;
};

struct Mgr_e74120_MapItem
{
    Mgr_e74120_MapItem* m_pkNext;
    void* m_key;
    UploadBatchItem* m_val;
};

class Mgr_e74120_Map
{
  public:
    virtual void dummy_vfunc0();
    virtual unsigned int KeyToHashIndex(void* key) const;

    unsigned int m_uiHashSize;
    Mgr_e74120_MapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    void RemoveAll();

    __forceinline void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    __forceinline void GetNext(void*& pos, void*& key, UploadBatchItem*& val) const
    {
        Mgr_e74120_MapItem* pkItem = (Mgr_e74120_MapItem*)pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }
};

class S_00e8c0d0
{
  public:
    unsigned int FUN_00e8bff0(void* p1, unsigned int p2, unsigned int p3, int p4);
    bool FUN_00e8c820(void* p1, void* p2, void* p3, int p4, UploadBatchPart* p5, unsigned int p6);
    bool FUN_00e8c1e0(void* p1, void* p2, int p3, UploadBatchPart* p4, unsigned int p5);
    bool FUN_00e8c0d0(void* p1);
};

class Helper_00e8f200
{
  public:
    unsigned int FUN_00e8f200(void* p1, int p2, int p3, unsigned int p4, int* p5, int p6, int p7);
};

class Mgr_e74120
{
  public:
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
    Mgr_e74120_CS cs80;
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
    Mgr_e74120_CS cs100;
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
    Mgr_e74120_Map map;
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
    S_00e8c0d0* helper8bc;
    Helper_00e8f200* helper8c0;

    void FUN_00e6d780(void* p1, void* p2, void* p3, void* p4, void* p5, int p6);
    void FUN_00e71fe0(void* p1, void* p2, void* p3, void* p4, int p5);
    void FUN_00e6fa90(UploadBatchHeader* p1, void* p2, void* p3);

    void FUN_00e74120();
};

// @fnv 0x00e74120
void Mgr_e74120::FUN_00e74120()
{
    EnterCriticalSection(&cs80);
    EnterCriticalSection(&cs100);

    void* pos = map.GetFirstPos();
    UploadBatchItem* delList = 0;
    while (pos)
    {
        void* key;
        UploadBatchItem* val;
        map.GetNext(pos, key, val);
        if (!val)
            continue;
        if (key)
        {
            unsigned int lo = 0xffffffff;
            unsigned int hi = 0;
            UploadBatchPart* sub;
            UploadBatchItem* cur = val;
            do
            {
                unsigned int index = cur->unk1c;
                UploadBatchItem* nx = cur->next;
                UploadBatchArray* arr = cur->unk18;
                sub = arr->GetPart(index);
                if (sub->firstByte < lo)
                    lo = sub->firstByte;
                if (sub->firstByte + sub->byteCount > hi)
                    hi = sub->firstByte + sub->byteCount;
                cur = nx;
            } while (cur);

            if (hi > lo)
            {
                unsigned int fl = sub->allocationFlags;
                void* vb = sub->buffer;
                unsigned int base = helper8bc->FUN_00e8bff0(vb, lo, hi - lo, fl);
                UploadBatchItem* it = val;
                do
                {
                    UploadBatchArray* arr = it->unk18;
                    unsigned int index = it->unk1c;
                    UploadBatchItem* nx = it->next;
                    sub = arr->GetPart(index);
                    unsigned int offset = sub->firstByte + base;
                    if (!it->unk0c ||
                        !it->unk0c->FUN_00e74288(it->unk00, it->unk04, it->unk08, 0xfff, sub, index, offset, 0, 0))
                    {
                        if (it->unk08)
                            helper8bc->FUN_00e8c820(it->unk00, it->unk04, it->unk08, 0xfff, sub, offset);
                        else
                            helper8bc->FUN_00e8c1e0(it->unk00, it->unk04, 0xfff, sub, offset);
                    }
                    if (it->unk1c == 0)
                    {
                        void* data = arr->unk50;
                        if (data)
                        {
                            unsigned short* lens = arr->unk4c;
                            int a = 0;
                            int b = 0;
                            if (lens)
                            {
                                int n = arr->unk48;
                                while (n)
                                {
                                    n--;
                                    a += lens[n];
                                }
                                b = a;
                            }
                            else if (arr->unk3c == 4)
                            {
                                a = arr->unk40 * 3;
                                b = arr->unk44 * 3;
                            }
                            else if (arr->unk3c == 5)
                            {
                                a = arr->unk40 + 2;
                                b = arr->unk44 + 2;
                            }
                            int tmp = arr->unk30;
                            bool fl2 = arr->unk14;
                            unsigned int prev = arr->unk34;
                            arr->unk34 =
                                helper8c0->FUN_00e8f200(data, a, b, prev, &tmp, DAT_0126f0d0 == 0, fl2 ? 0x10 : 0);
                            arr->unk2c = a;
                            arr->unk30 = tmp;
                        }
                    }
                    it->next = delList;
                    delList = it;
                    it = nx;
                } while (it);
                helper8bc->FUN_00e8c0d0(sub->buffer);
            }
        }
        else
        {
            UploadBatchItem* cur = val;
            do
            {
                UploadBatchItem* nx = cur->next;
                if (cur->unk1c == 0)
                {
                    if (cur->unk08)
                        FUN_00e6d780(cur->unk18, cur->unk00, cur->unk04, cur->unk08, cur->unk0c, 1);
                    else
                        FUN_00e71fe0(cur->unk18, cur->unk00, cur->unk04, cur->unk0c, 1);
                }
                cur->next = delList;
                delList = cur;
                cur = nx;
            } while (cur);
        }
    }

    map.RemoveAll();

    while (delList)
    {
        UploadBatchItem* nx = delList->next;
        UploadBatchHeader* h = delList->unk00;
        if (h->OwnsHeader(delList->unk1c))
        {
            UploadBatchHeader* h2 = delList->unk00;
            h2->ClearOwnership();
            FUN_00e6fa90(h, delList->unk04, delList->unk08);
        }
        FUN_00aa1460(delList, sizeof(UploadBatchItem));
        delList = nx;
    }

    LeaveCriticalSection(&cs100);
    LeaveCriticalSection(&cs80);
}

namespace fnv_00b61370 {
extern __declspec(thread) int g_iC8AD40AllocTag;
struct CacheAllocationScope
{
    int savedTag;
    CacheAllocationScope(int tag) : savedTag(g_iC8AD40AllocTag)
    {
        g_iC8AD40AllocTag = tag;
    }
    ~CacheAllocationScope()
    {
        g_iC8AD40AllocTag = savedTag;
    }
};
struct CacheItem
{
    int FUN_00bd8670(const char*);
    void FUN_00bd8f90();
};
struct CacheListNode
{
    CacheListNode* next;
    CacheListNode* previous;
    CacheItem* item;
};
struct CacheLock
{
    int state;
    unsigned int live;
    void Lock(const char*);
};
extern CacheLock DAT_011c5f80;
extern CacheListNode* DAT_011c5f58;
extern unsigned int DAT_011f9ef4;
struct CacheMemory
{
    void FUN_00aa4060(void*);
};
extern CacheMemory DAT_011f6238;
struct CacheList
{
    CacheListNode* head;
    CacheListNode* tail;
    unsigned int count;
    CacheItem* FUN_00b602d0();
    CacheItem* FUN_00e7d5b0();
    CacheItem*& GetNext(CacheListNode*& position)
    {
        CacheItem*& ref = position->item;
        position = position->next;
        return ref;
    }
    __forceinline CacheItem* Remove(CacheListNode* node, CacheItem*& slot)
    {
        if (node == head)
        {
            return FUN_00b602d0();
        }
        else if (node == tail)
        {
            return FUN_00e7d5b0();
        }
        else
        {
            CacheItem* item = slot;
            CacheListNode* previous = node->previous;
            CacheListNode* next = node->next;
            if (previous)
                previous->next = next;
            if (next)
                next->previous = previous;
            slot = 0;
            DAT_011c5f80.Lock(0);
            node->previous = 0;
            node->next = DAT_011c5f58;
            DAT_011c5f80.live--;
            DAT_011c5f58 = node;
            if (!DAT_011c5f80.live)
                DAT_011c5f80.state = 0;
            count--;
            return item;
        }
    }
};
struct CacheLookup
{
    bool FUN_00a53c30(const char*, void*&);
    bool FUN_00e91fd0(const char*);
};
struct CacheBucket
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    CacheList entries;
    int unk2c;
    CacheLookup lookup;
};
struct CacheMapNode
{
    CacheMapNode* next;
    unsigned key;
    CacheBucket* value;
};
struct CacheMap
{
    virtual ~CacheMap();
    virtual unsigned Hash(unsigned key);
    unsigned int size;
    CacheMapNode** buckets;
    unsigned int count;
    void* First()
    {
        for (unsigned int index = 0; index < size; index++)
        {
            if (buckets[index])
                return buckets[index];
        }
        return 0;
    }
    void FUN_00b57f20(void*&, unsigned int&, CacheBucket*&);
};
CacheMap* GetArrayHolder();
// @fnv 0x00b61370
void FUN_00b61370(const char* key)
{
    CacheAllocationScope scope(0x1c);
    void* position = GetArrayHolder()->First();
    CacheBucket* removed = 0;
    if (GetArrayHolder()->count > 0 && position)
    {
        do
        {
            struct
            {
                unsigned int key;
                void* value;
            } kv;
            GetArrayHolder()->FUN_00b57f20(position, kv.key, removed);
            CacheLookup* lookup = removed ? &removed->lookup : 0;
            if (removed && lookup->FUN_00a53c30(key, kv.value))
            {
                CacheList* entries;
                entries = &removed->entries;
                CacheListNode* node = entries->head;
                while (node)
                {
                    CacheListNode* bucket = node;
                    CacheItem*& slot = entries->GetNext(node);
                    CacheItem* item = slot;
                    if (item && !item->FUN_00bd8670(key))
                    {
                        entries->Remove(bucket, slot);
                        item->FUN_00bd8f90();
                        DAT_011f6238.FUN_00aa4060(item);
                        DAT_011f9ef4--;
                    }
                }
                lookup->FUN_00e91fd0(key);
            }
        } while (position);
    }
}

void CacheMap::FUN_00b57f20(void*& position, unsigned& key, CacheBucket*& value)
{
    CacheMapNode* node = (CacheMapNode*)position;
    key = node->key;
    value = node->value;
    if (node->next)
    {
        position = node->next;
        return;
    }
    unsigned index = Hash(node->key) + 1;
    for (; index < size; ++index)
    {
        if (buckets[index])
        {
            position = buckets[index];
            return;
        }
    }
    position = 0;
}
}  // namespace fnv_00b61370
