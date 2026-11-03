
// src/fallout_shared/modelloader_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/modelloader.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "modelloader_verified_packet.h"
NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

void __cdecl ReportAssertionViolation(const char*, unsigned int);

struct Fg_aaed70_Vec
{
    void* unk00;
    void* unk04;
    void* unk08;
    float* _Myfirst;
    float* _Mylast;
    float* _Myend;
    Fg_aaed70_Vec();
    ~Fg_aaed70_Vec();
    void resize(unsigned int, float);
    struct Fg_aaed70_CIter end() const;
};

struct Fg_aaed70_CIter
{
    float* m_ptr;
    const void* m_pOwnerObject;
    Fg_aaed70_CIter(float*, const void*);
    void FUN_00659190();
    bool FUN_0065dfd0(const Fg_aaed70_CIter&) const;
    const float& FUN_0064dda0() const;
    Fg_aaed70_CIter operator++(int)
    {
        Fg_aaed70_CIter tmp = *this;
        FUN_00659190();
        return tmp;
    }
};

inline Fg_aaed70_CIter Fg_aaed70_Vec::end() const
{
    return Fg_aaed70_CIter(_Mylast, this);
}

struct Fg_aaed70_Iter : Fg_aaed70_CIter
{
    Fg_aaed70_Iter(float* p, const void* o) : Fg_aaed70_CIter(p, o)
    {}
    float& operator*() const
    {
        int w1;
        int w2;
        int w3;
        int w4;
        return (float&)FUN_0064dda0();
    }
    Fg_aaed70_Iter operator++(int)
    {
        Fg_aaed70_Iter tmp = *this;
        FUN_00659190();
        return tmp;
    }
};

struct Fg_aaed70_Mat
{
    Fg_aaed70_Vec data;
    unsigned int m18;
    unsigned int m1c;

    Fg_aaed70_Mat(const Fg_aaed70_Mat&);
    ~Fg_aaed70_Mat()
    {
        int v1;
        int v2;
        int v3;
        int v4;
        int v5;
        int v6;
        int v7;
        int v8;
        int v9;
        int v10;
        int v11;
        int v12;
        int v13;
        int v14;
    }

    Fg_aaed70_Mat(unsigned int r, unsigned int c) : data(), m18(r), m1c(c)
    {
        unsigned int n = m1c * m18;
        data.resize(n, 0.0f);
    }
    Fg_aaed70_Mat FUN_00aaed70(const Fg_aaed70_Mat& other) const;
};

// @fnv 0x00aaed70
Fg_aaed70_Mat Fg_aaed70_Mat::FUN_00aaed70(const Fg_aaed70_Mat& other) const
{
    if (m18 == other.m18 && m1c == other.m1c)
    {
    }
    else
    {
        ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x1ca);
    }
    Fg_aaed70_Mat ret(m18, m1c);
    Fg_aaed70_Iter it3(ret.data._Myfirst, &ret.data);
    Fg_aaed70_CIter it9(data._Myfirst, &data);
    Fg_aaed70_CIter it2(other.data._Myfirst, &other.data);
    for (; it9.FUN_0065dfd0(data.end()); it9++, it2++, it3++)
    {
        *it3 = it9.FUN_0064dda0() - it2.FUN_0064dda0();
    }
    return ret;
}

struct RttiX
{
    const char* m_pcName;
    const RttiX* m_pkBase;
};
extern RttiX DAT_011f4280;
extern RttiX DAT_011f49a4;
struct ObjX;
struct MapX
{
    bool GetAt(void* pkKey, void** ppVal);
    void AddOrUpdate(void* pkKey, ObjX* pkObj);
    void RemoveKey(void* pkKey);
};
struct ObjX
{
    virtual void v0();
    virtual void v1();
    virtual const RttiX* GetRTTI();
    virtual ObjX* GetChildHolder();
    int m4;
    void* m8;
    void* GetM8()
    {
        void* p = m8;
        int aiPad[10];
        return p;
    }
    bool FUN_006532c0(const RttiX* pk);
    bool IsKindOfX(const RttiX* pk)
    {
        const RttiX* r = GetRTTI();
        while (r)
        {
            if (r == pk)
                return true;
            r = r->m_pkBase;
        }
        return false;
    }
};
struct PtrX
{
    ObjX* m_pObject;
    operator ObjX*() const
    {
        ObjX* p = m_pObject;
        return p;
    }
};
struct ArrHolderX
{
    char pad[0xa0];
    PtrX* m_pBase;
    unsigned short m_usA4;
    unsigned short m_usSize;
    PtrX& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct LNodeX
{
    LNodeX* m_pkNext;
    LNodeX* m_pkPrev;
    ObjX* m_element;
};
struct NodeX : ObjX
{
    char pad[0x24 - 0xc];
    LNodeX* m_pkHead;
    LNodeX* GetHeadPos()
    {
        LNodeX* p = m_pkHead;
        return p;
    }
    ObjX* GetNext(LNodeX*& pos)
    {
        ObjX** pp = &pos->m_element;
        pos = pos->m_pkNext;
        return *pp;
    }
};
struct ExtraNodeX
{
    int m0, m4;
    ObjX* m8;
};
struct ExtraX : ObjX
{
    char pad[0x20 - 0xc];
    ExtraNodeX** m_ppkArr;
    ObjX* GetFirst(unsigned int i)
    {
        ExtraNodeX* n = m_ppkArr[i];
        if (n)
        {
            ObjX* p = n->m8;
            return p;
        }
        else
        {
            return 0;
        }
    }
};
class WalkX
{
  public:
    char pad[0x5c4];
    MapX* m_pTaskMap;
    void FUN_00c3a9c0(ObjX* pkObj, unsigned int uiFlags);
};
// @fnv 0x00c3a9c0
void WalkX::FUN_00c3a9c0(ObjX* pkObj, unsigned int uiFlags)
{
    if (m_pTaskMap)
    {
        void* pkKey = pkObj->GetM8();
        if (pkKey)
        {
            if (uiFlags & 0x80)
            {
                void* pkVal;
                if (!m_pTaskMap->GetAt(pkKey, &pkVal))
                    m_pTaskMap->AddOrUpdate(pkKey, pkObj);
            }
            else
            {
                m_pTaskMap->RemoveKey(pkKey);
            }
        }
        if (uiFlags & 0x1f)
        {
            NodeX* pkNode;
            if (!pkObj)
                pkNode = 0;
            else
                pkNode = (NodeX*)(pkObj->FUN_006532c0(&DAT_011f4280) ? pkObj : 0);
            if (pkNode)
            {
                if (uiFlags & 4)
                {
                    LNodeX* pos = pkNode->GetHeadPos();
                    while (pos)
                    {
                        ObjX* pkChild = pkNode->GetNext(pos);
                        if (pkChild)
                            FUN_00c3a9c0(pkChild, uiFlags);
                    }
                }
                ArrHolderX* pkHolder = (ArrHolderX*)pkObj->GetChildHolder();
                if (pkHolder && (uiFlags & 1))
                {
                    unsigned int i = pkHolder->m_usSize;
                    while (i--)
                    {
                        ObjX* pkChild = pkHolder->GetAt(i);
                        if (pkChild)
                        {
                            if (!(uiFlags & 3) || pkChild->GetChildHolder())
                                FUN_00c3a9c0(pkChild, uiFlags);
                        }
                    }
                }
            }
            else if (uiFlags & 0x10)
            {
                ExtraX* pkExtra;
                if (!pkObj)
                    pkExtra = 0;
                else
                    pkExtra = (ExtraX*)(pkObj->IsKindOfX(&DAT_011f49a4) ? pkObj : 0);
                if (pkExtra)
                {
                    ObjX* pkChild = pkExtra->GetFirst(0);
                    if (pkChild)
                        FUN_00c3a9c0(pkChild, uiFlags);
                }
            }
        }
    }
}

extern unsigned char DAT_011f4304[];
struct StreamRTTI
{
    const char* name;
    StreamRTTI* base;
    StreamRTTI* GetBaseRTTI() const
    {
        return base;
    }
};

unsigned int __cdecl FUN_00a63630(const char*);
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};
struct StreamObject
{
    virtual void slot0();
    virtual void slot1();
    virtual StreamRTTI* GetRTTI();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void pass19(class TargetStream*);
    virtual void pass20(class TargetStream*);
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void pass27(class TargetStream*);
    int refCount;
    unsigned int name;
    bool IsKindOfType(const StreamRTTI* target)
    {
        StreamRTTI* type = GetRTTI();
        while (type)
        {
            if (type == target)
                return true;
            type = type->GetBaseRTTI();
        }
        return false;
    }
};
struct TargetStream
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual bool begin();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void finishLoad();
    virtual void slot19();
    virtual bool loadObject();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int version;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    StreamObject** objects;
    unsigned int objectCount;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    int state;
    unsigned int unk290;
    unsigned int loadIndex;
    unsigned int linkIndex;
    unsigned int postIndex;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    DummyPointerMap* map;
    void FUN_00a644f0();
    bool LoadRTTIAndObjects();
    void LoadGroups();
    void FUN_00a63d10();
    void Clear();
    bool FUN_00a65c60();
    StreamObject* ObjectAt(unsigned int index)
    {
        StreamObject*& entry = objects[index];
        return entry;
    }
    unsigned int LookupMapped(StreamObject* object)
    {
        unsigned int aVal = object->name;
        unsigned int aItem = 0;
        unsigned int idx;
        void* item;
        if (map && aVal)
            map->GetAt(aVal, aItem);
        return aItem;
    }
    bool FUN_00c3ac10();
};
// @fnv 0x00c3ac10
bool TargetStream::FUN_00c3ac10()
{
    if (map)
    {
        if (!begin())
            return false;
        postIndex = 0;
        linkIndex = 0;
        loadIndex = 0;
        FUN_00a644f0();
        bool groupB;
        unsigned int count;
        StreamObject* objectTmp;
        StreamObject* specialObject9;
        StreamObject* specialObject6;
        {
            unsigned int aVersion = version;
            groupB = aVersion >= FUN_00a63630("5.0.0.1");
        }
        if (groupB && !LoadRTTIAndObjects())
            return false;
        {
            unsigned int aVersion = version;
            if (aVersion >= FUN_00a63630("5.0.0.6"))
                LoadGroups();
        }
        count = objectCount;
        for (; loadIndex < count; ++loadIndex)
        {
            if (state == 2)
                return false;
            if (groupB)
            {
                objectTmp = ObjectAt(loadIndex);
                objectTmp->pass19(this);
            }
            else
            {
                if (!loadObject())
                    return false;
            }
        }
        finishLoad();
        for (; linkIndex < count; ++linkIndex)
        {
            if (state == 2)
                return false;
            objectTmp = ObjectAt(linkIndex);
            if (!objectTmp)
                specialObject9 = 0;
            else
                specialObject9 = objectTmp->IsKindOfType((StreamRTTI*)DAT_011f4304) ? objectTmp : 0;
            if (specialObject9 && LookupMapped(specialObject9))
            {
            }
            else
            {
                objectTmp->pass20(this);
            }
        }
        for (; postIndex < count; ++postIndex)
        {
            if (state == 2)
                return false;
            objectTmp = ObjectAt(postIndex);
            if (!objectTmp)
                specialObject6 = 0;
            else
                specialObject6 = objectTmp->IsKindOfType((StreamRTTI*)DAT_011f4304) ? objectTmp : 0;
            if (specialObject6 && LookupMapped(specialObject6))
            {
            }
            else
            {
                objectTmp->pass27(this);
            }
        }
        FUN_00a63d10();
        Clear();
    }
    else
    {
        return FUN_00a65c60();
    }
    return true;
}

namespace fnv_00c3afc0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RttiY;
extern RttiY DAT_011f4304;
struct RefY
{
    virtual void v0();
    virtual void DeleteThis();
    long m_lRef;
    void AcquireReference()
    {
        InterlockedIncrement(&m_lRef);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_lRef) == 0)
            DeleteThis();
    }
};
struct SpY
{
    RefY* m_p;
    SpY(RefY* p = 0)
    {
        int aiD0;
        int aiD1;
        m_p = p;
        if (m_p)
            m_p->AcquireReference();
    }
    ~SpY()
    {
        if (m_p)
            m_p->DecRef();
    }
    SpY& FUN_00c3b970(RefY* p);
};
struct ObjY : RefY
{
    void* m8;
    bool FUN_006532c0(const RttiY* pk);
};
struct FUN_00a5d3a0 : RefY
{
    FUN_00a5d3a0();
    ~FUN_00a5d3a0();
};
struct Z : FUN_00a5d3a0
{
    void* operator new(unsigned int n);
    void* m8;
    Z(void* p)
    {
        m8 = 0;
        FUN_00c64780(p);
    }
    virtual void v0();
    void FUN_00c64780(void* p);
};
struct MapY
{
    bool GetAt(void* k, void** pv);
};
struct Map274
{
    int m0;
    bool FUN_00a53c30(ObjY* k, unsigned int* pv);
    void InsertOrUpdate(ObjY* k, unsigned int v);
};
struct ArrY
{
    int m0, m4;
    unsigned int m_uiCap;
    unsigned int m_uiSize;
    int m10;
    unsigned int m_uiGrow;
    void FUN_00a64fe0(unsigned int n);
    void FUN_00cc1a10(unsigned int i, const SpY* p);
    unsigned int GetSize()
    {
        unsigned int n = m_uiSize;
        int iD;
        return n;
    }
    void Add(const SpY& sp)
    {
        unsigned int i = m_uiSize;
        if (i >= m_uiCap)
            FUN_00a64fe0(i + m_uiGrow);
        FUN_00cc1a10(i, &sp);
    }
};
class WalkY;
struct HelperY
{
    void FUN_00c64c40(WalkY* p, ObjY* o);
    void Do(WalkY* p, ObjY* o)
    {
        int aiD0;
        int aiD1;
        FUN_00c64c40(p, o);
    }
};
class WalkY
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
    ArrY m_kArr;
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
    Map274 m_kFormatEntries;
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
    MapY* m_pTaskMap;
    HelperY* m_pkHelper;
    bool AddObject(ObjY* p);
    void* Lookup(ObjY* object)
    {
        void* aVal = object->m8;
        void* aItem = 0;
        if (m_pTaskMap && aVal)
            m_pTaskMap->GetAt(aVal, &aItem);
        return aItem;
    }
    bool FUN_00c3afc0(ObjY* pkObj);
};

// @fnv 0x00c3afc0
bool WalkY::FUN_00c3afc0(ObjY* pkObj)
{
    if (m_pTaskMap)
    {
        RefY* pkCur = pkObj;
        unsigned int uiIndexVal;
        if (m_kFormatEntries.FUN_00a53c30(pkObj, &uiIndexVal))
            return false;
        SpY spNew9;
        ObjY* pkNode2;
        if (!pkObj)
            pkNode2 = 0;
        else
            pkNode2 = (ObjY*)(pkObj->FUN_006532c0(&DAT_011f4304) ? pkObj : 0);
        if (pkNode2 && Lookup(pkNode2))
        {
            spNew9.FUN_00c3b970(new Z(pkNode2->m8));
            pkCur = spNew9.m_p;
        }
        else
        {
            m_pkHelper->Do(this, pkObj);
        }
        uiIndexVal = m_kArr.GetSize();
        m_kFormatEntries.InsertOrUpdate(pkObj, uiIndexVal);
        m_kArr.Add(pkCur);
        return true;
    }
    else
    {
        return AddObject(pkObj);
    }
}
}  // namespace fnv_00c3afc0

__declspec(dllimport) long __stdcall InterlockedIncrement(long*);
class Task
{
  public:
    unsigned int unk00, unk04;
    long unk08;
    unsigned int unk0c;
    __int64 unk10;
    inline void SetState(unsigned int state)
    {
        unk0c = state;
    }
    inline __int64 GetKey() const
    {
        return unk10;
    }
    void FUN_0044dd60();
    inline void AcquireReference()
    {
        InterlockedIncrement(&unk08);
    }
};
class TaskPtr
{
  public:
    Task* value;
    inline TaskPtr(Task* p) : value(p)
    {
        if (value)
            value->AcquireReference();
    }
    inline ~TaskPtr()
    {
        if (value)
            value->FUN_0044dd60();
    }
};
class Queue
{
  public:
    void FUN_00442600();
};
class Target
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool Remove(__int64, const TaskPtr&, bool);
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual unsigned int Bucket(__int64);
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
    virtual unsigned int Priority(Task*);
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
    Queue** unk50;
    long* unk54;
    long unk58;
    inline void IncrementBucket(unsigned int bucket)
    {
        long* count = &unk54[bucket];
        unsigned int v;
        unsigned int w;
        unsigned int u3;
        unsigned int u4;
        unsigned int x;
        InterlockedIncrement(count);
    }
    bool FUN_00c3fb50(Task* task);
};
// @fnv 0x00c3fb50
bool Target::FUN_00c3fb50(Task* task)
{
    task->SetState(1);
    unsigned int bucket = Bucket(task->GetKey());
    unsigned int priority = Priority(task);
    bool removed;
    {
        TaskPtr hold(task);
        removed = Remove(task->GetKey(), hold, false);
    }
    if (removed)
    {
        IncrementBucket(bucket);
        InterlockedIncrement(&unk58);
        unk50[priority]->FUN_00442600();
        return true;
    }
    return false;
}

extern int DAT_010c1670;
extern int DAT_010c1664;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct S00c3fce0_Iter
{
    int* table;
    int unk04;
    int index;
    int unk0C;
    void* current;
    void* tail;
    unsigned char flags;
    int unk1C;
    __forceinline S00c3fce0_Iter()
    {
        table = &DAT_010c1670;
        index = 0;
        current = 0;
        tail = 0;
        flags = 0;
        table = &DAT_010c1664;
    }
    __forceinline ~S00c3fce0_Iter()
    {
        table = &DAT_010c1670;
    }
    __forceinline bool atEnd() const
    {
        return flags & 2;
    }
};
struct S00c3fce0_Obj
{
    int unk00, unk04;
    long references;
    void FUN_0044dd60();
};
struct S00c3fce0_Key
{
    int first, second, third;
};
struct S00c3fce0_Ptr
{
    S00c3fce0_Obj* object;
};
struct S00c3fce0_Args
{
    S00c3fce0_Key key;
    S00c3fce0_Ptr item;
    __forceinline S00c3fce0_Args()
    {
        key.first = 0;
        key.second = 0;
        item.object = 0;
        if (item.object)
        {
            S00c3fce0_Obj* ref = item.object;
            InterlockedIncrement(&ref->references);
        }
    }

    __forceinline ~S00c3fce0_Args()
    {
        int t1;
        int t2;
        int t3;
        int t4;
        int t5;
        int t6;
        int t7;
        int t8;
        int t9;
        int t10;
        int t11;
        int t12;
        int t13;
        int t14;
        int t15;
        if (item.object)
            item.object->FUN_0044dd60();
    }
};
struct S00c3fce0_Tmp
{
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;
    int t6;
    int t7;
    int t8;
    int t9;
    int t10;
    int t11;
    int t12;
    int t13;
    int t14;
    int t15;
};
struct S00c3fce0_cls
{
    bool FUN_00c40e70(S00c3fce0_Iter*, S00c3fce0_Key*, S00c3fce0_Ptr*, bool);
    void FUN_0044ac40(S00c3fce0_Obj*, int);
    void FUN_00c3fce0();
};
// @fnv 0x00c3fce0
void S00c3fce0_cls::FUN_00c3fce0()
{
    bool changed = true;
    int x1;
    while (changed)
    {
        changed = false;
        S00c3fce0_Iter iterator;
        while (!iterator.atEnd())
        {
            S00c3fce0_Args a;

            if (FUN_00c40e70(&iterator, &a.key, &a.item, true))
            {
                FUN_0044ac40(a.item.object, 0);
                changed = true;
            }
        }
    }
}

__declspec(dllimport) long __stdcall InterlockedDecrement(long*);
void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_010c13f4;
extern int DAT_01069d84;
class FUN_00a5d3a0
{
  public:
    virtual void vf00();
    int m_04;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_04);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_04) == 0)
            DeleteThis();
    }
    virtual void DeleteThis();
    FUN_00a5d3a0();
    ~FUN_00a5d3a0();
};
extern int DAT_01069d7c;
void* FUN_0096afc0(unsigned int);
class C3B270_SubBase
{
  public:
    void* table;
    void** data;
    unsigned short capacity, size, live, grow;
    void FUN_0068ac40(unsigned int a, unsigned int b)
    {
        table = &DAT_01069d7c;
        capacity = (unsigned short)a;
        grow = (unsigned short)b;
        size = 0;
        live = 0;
        unsigned int count = capacity;
        if (count > 0)
            data = (void**)FUN_0096afc0(count);
        else
            data = 0;
    }
};
class C3B270_Sub : public C3B270_SubBase
{
  public:
    __forceinline C3B270_Sub()
    {
        FUN_0068ac40(0, 1);
        table = &DAT_01069d84;
    }
};
class C3B270_Object : public FUN_00a5d3a0
{
  public:
    C3B270_Sub m_08;
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    virtual void vf00();
    __forceinline C3B270_Object()
    {}
};
struct C3B270_Ref
{
    C3B270_Object* m_pObject;
    C3B270_Ref& FUN_00c3b970(C3B270_Object* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    __forceinline operator C3B270_Object*() const
    {
        return m_pObject;
    }
};
struct C3B270_Owner
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
    int m_5C4;
    C3B270_Ref m_5C8;
    void FUN_00a66370(C3B270_Object* object);
    bool FUN_00a66850();
    bool FUN_00c3b270();
};
// @fnv 0x00c3b270
bool C3B270_Owner::FUN_00c3b270()
{
    if (m_5C4)
    {
        m_5C8.FUN_00c3b970(new C3B270_Object);
        FUN_00a66370(m_5C8);
    }
    bool result = FUN_00a66850();
    m_5C8.FUN_00c3b970(0);
    return result;
}

extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
void __cdecl operator delete(void*);
struct Aade20SecureCopy
{
};
template <class T>
inline T* Aade20CopyCharacters(T* out, unsigned int capacity, const T* in, unsigned int count, Aade20SecureCopy)
{
    memcpy_s(out, capacity * sizeof(T), in, count * sizeof(T));
    return out;
}
template <class T> inline T* Aade20CopyCharacters(T* out, unsigned int capacity, const T* in, unsigned int count)
{
    Aade20SecureCopy secure;
    return Aade20CopyCharacters(out, capacity, in, count, secure);
}
namespace std {
template <class T> struct char_traits
{
    static void assign(T& out, const T& in)
    {
        out = in;
    }
};
template <class T> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    void deallocate(T* pointer, unsigned int)
    {
        operator delete(pointer);
    }
};
template <class T, class Alloc> class Aade20StringAllocator
{
  protected:
    Alloc allocation;
    Aade20StringAllocator(Alloc value = Alloc()) : allocation(value)
    {}
};
template <class T, class Traits, class Alloc> class basic_string : public Aade20StringAllocator<T, Alloc>
{
    union Storage
    {
        T buffer[16];
        T* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

  protected:
    T* data()
    {
        return capacity >= 16 ? storage.pointer : storage.buffer;
    }
    void setLength(unsigned int count)
    {
        Traits::assign(data()[length = count], T());
    }
    void _Tidy(bool built = false, unsigned int remaining = 0)
    {
        if (!built)
        {
        }
        else if (capacity >= 16)
        {
            T* old = storage.pointer;
            if (remaining > 0)
                Aade20CopyCharacters(storage.buffer, 16, old, remaining);
            this->allocation.deallocate(old, capacity + 1);
        }
        capacity = 15;
        setLength(remaining);
    }

  public:
    basic_string() : Aade20StringAllocator<T, Alloc>()
    {
        _Tidy();
    }
    ~basic_string()
    {
        _Tidy(true);
    }
};
}

extern "C" void __cdecl _invalid_parameter_noinfo();
struct Aade20ConstIterator;
struct Aade20Iterator;
namespace std {
template <class T, class Alloc = allocator<T> > class vector;
template <> class vector<float, allocator<float> >
{
  public:
    void* auxiliary;
    unsigned int allocatorAuxiliary;
    unsigned int allocatorElements;
    float* first;
    float* last;
    float* end;
    vector();
    ~vector();
    Aade20Iterator begin();
    Aade20Iterator finish();
    Aade20Iterator makeIterator(Aade20ConstIterator) const;
    Aade20Iterator erase(Aade20ConstIterator, Aade20ConstIterator);
    void clear();
};
}
typedef std::vector<float> Aade20FloatVector;
struct Aade20ConstIterator
{
    const void* owner;
    float* value;
    Aade20ConstIterator(float* p, const Aade20FloatVector* vector)
    {
        owner = 0;
        if (!vector || p < vector->first || vector->last < p)
            _invalid_parameter_noinfo();
        owner = vector->auxiliary;
        value = p;
    }
    bool operator!=(const Aade20ConstIterator&) const;
};
struct Aade20Iterator : Aade20ConstIterator
{
    Aade20Iterator(float* p, const Aade20FloatVector* vector) : Aade20ConstIterator(p, vector)
    {}
};
__declspec(noinline) bool Aade20ConstIterator::operator!=(const Aade20ConstIterator & other) const
{
    if (owner != other.owner)
        _invalid_parameter_noinfo();
    return value != other.value;
}
inline Aade20Iterator Aade20FloatVector::begin()
{
    return Aade20Iterator(first, this);
}
inline Aade20Iterator Aade20FloatVector::finish()
{
    return Aade20Iterator(last, this);
}
inline Aade20Iterator Aade20FloatVector::makeIterator(Aade20ConstIterator p) const
{
    return Aade20Iterator(p.value, this);
}
__declspec(noinline) float* Aade20Copy(float* from, float* stop, float* out)
{
    while (from != stop)
    {
        *out = *from;
        ++out;
        ++from;
    }
    return out;
}
inline Aade20Iterator Aade20FloatVector::erase(Aade20ConstIterator from, Aade20ConstIterator to)
{
    Aade20Iterator start = makeIterator(from);
    Aade20Iterator stop = makeIterator(to);
    if (start != stop)
    {
        float* newEnd = Aade20Copy(stop.value, last, start.value);
        last = newEnd;
    }
    return start;
}
inline void Aade20FloatVector::clear()
{
    erase(begin(), finish());
}
struct Aade20Matrix : Aade20FloatVector
{
    unsigned int columns, rows;
    Aade20Matrix()
    {
        columns = 0;
        rows = 0;
        clear();
    }
};
struct FUN_00aade20 : Aade20Matrix
{
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;
    FUN_00aade20();
};
// @fnv 0x00aade20
FUN_00aade20::FUN_00aade20()
{}
