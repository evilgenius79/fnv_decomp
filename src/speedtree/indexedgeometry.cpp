
// src/speedtree/indexedgeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/indexedgeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b30060_shell
{
    int FUN_00b30060(float* p);
};
// @fnv 0x00b30060
int FUN_00b30060_shell::FUN_00b30060(float* p)
{
    return (int)(p[0] * 255.0) + ((int)(p[1] * 255.0) << 8) + ((int)(p[2] * 255.0) << 16) - 0x1000000;
}

struct FloatVec
{
    void PushBack(const float&);
};

struct FUN_00b30190_shell
{
    char m_ucUnknownByte[0xb8];
    void FUN_00b30190(const float* p);
};

// Passes the first three floats of p to PushBack on the FloatVec at this+0xb8.
// @fnv 0x00b30190
void FUN_00b30190_shell::FUN_00b30190(const float* afValues)
{
    char stack[0x130];
    ((FloatVec*)((char*)this + 0xb8))->PushBack(afValues[0]);
    ((FloatVec*)((char*)this + 0xb8))->PushBack(afValues[1]);
    ((FloatVec*)((char*)this + 0xb8))->PushBack(afValues[2]);
}

unsigned int __cdecl FUN_00ec7c56(void);
struct Vec28
{
    char _pad[12];
    unsigned int* _first;
    unsigned int* _last;
};
struct Cls
{
    char _pad[36];
    unsigned short m1;
    unsigned short m2;
    Vec28 mVec;
    void FUN_00b306d0(unsigned short);
};
// Stores val into m1, clears m2, and zeroes the mVec element at index val, calling FUN_00ec7c56 if the index is out of range.
// @fnv 0x00b306d0
void Cls::FUN_00b306d0(unsigned short ausValue)
{
    m1 = ausValue;
    m2 = 0;
    unsigned int idx = ausValue;
    Vec28* vec = &mVec;
    if (idx >= (unsigned int)(vec->_last - vec->_first))
        FUN_00ec7c56();
    vec->_first[idx] = 0;
}

struct SubA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    SubA();
    ~SubA();
};

struct SubB
{
    int unk00;
    int unk04;
    int unk08;

    SubB();
};

struct FUN_00b10dc0
{
    int unk00;
    float unk04;
    SubA unk08;
    int unk20;
    int unk24;
    unsigned short unk28;
    int unk2c;
    float unk30;
    float unk34;
    SubB unk38;

    FUN_00b10dc0(int param);
};

// @fnv 0x00b10dc0
FUN_00b10dc0::FUN_00b10dc0(int aiValue)
    : unk00(aiValue), unk04(0.0f), unk08(), unk20(0), unk24(-1), unk28(0), unk2c(-1), unk30(0.0f), unk34(0.0f), unk38()
{
    unsigned int scratch[0x3c];
}

struct FUN_00b300c0_cls
{
    char m_pad00[8];
    unsigned char m_flag08;
    char m_pad09[0xb];
    int m_14;
    char m_pad18[0x70];
    FloatVec m_vec88;
    char m_pad89[0x17];
    FloatVec m_veca0;

    void FUN_00b300c0(const float* p);
};

struct FrameBuf
{
    unsigned char unk00[0x1d0];
};

// @fnv 0x00b300c0
void FUN_00b300c0_cls::FUN_00b300c0(const float* p)
{
    float v[3];
    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];
    FrameBuf buf;
    unsigned int unk4;
    m_vec88.PushBack(v[0]);
    m_vec88.PushBack(v[1]);
    m_vec88.PushBack(v[2]);
    if (m_flag08 != 0 && m_14 == 1)
    {
        m_veca0.PushBack(v[0]);
        m_veca0.PushBack(v[1]);
        m_veca0.PushBack(v[2]);
    }
}

struct FUN_00b304f0_cls
{
    int unk00;
    float m_04;
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
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    FloatVec m_148;

    void FUN_00b304f0(const float& v);
};

bool __cdecl FUN_00b0d7a0(void);

// @fnv 0x00b304f0
void FUN_00b304f0_cls::FUN_00b304f0(const float& afValue)
{
    float f;
    unsigned int buf[75];
    unsigned char c;
    m_148.PushBack(afValue);
    if (FUN_00b0d7a0())
    {
        f = -(&afValue)[1];
        m_148.PushBack(f);
    }
    else
    {
        m_148.PushBack((&afValue)[1]);
    }
}

namespace fnv_00b305f0 {
struct FUN_00b305f0_cls
{
    char m_pad00[0xe8];
    FloatVec m_vec;

    void FUN_00b305f0(const float* p);
};

struct FrameBuf
{
    unsigned char unk00[0x130];
};

// @fnv 0x00b305f0
void FUN_00b305f0_cls::FUN_00b305f0(const float* apComponents)
{
    float v[3];
    v[0] = apComponents[0];
    v[1] = apComponents[1];
    v[2] = apComponents[2];
    FrameBuf buf;
    unsigned int unk4;
    m_vec.PushBack(v[0]);
    m_vec.PushBack(v[1]);
    m_vec.PushBack(v[2]);
}
}  // namespace fnv_00b305f0

void __cdecl FreeBlock(void* p);

class FUN_00b32c60_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_pHeadNode;
    int m_last;
    int m_kRayEnd;
    void DestroyRange(int first, int last);
    void FUN_00b32c60();
};

// @fnv 0x00b32c60
void FUN_00b32c60_cls::FUN_00b32c60()
{
    unsigned int unkPad[12];
    if (m_pHeadNode != 0)
    {
        DestroyRange(m_pHeadNode, m_last);
        int count = (m_kRayEnd - m_pHeadNode) / 0x18;
        int* p = (int*)m_pHeadNode;
        FreeBlock(p);
    }
    m_pHeadNode = 0;
    m_last = 0;
    m_kRayEnd = 0;
}

struct K
{
    char pad0[12];
    int fC;
    int f10;
    int f14;
    int __thiscall FUN_00b33110(int, int);
    void __thiscall FUN_00b331c0();
};

void __cdecl FormHeap_Free(void*);

// @fnv 0x00b331c0
void __thiscall K::FUN_00b331c0()
{
    int u[12];
    int t2;
    int t1;

    if (fC != 0)
    {
        FUN_00b33110(fC, f10);
        t1 = (f14 - fC) / 24;
        t2 = fC;
        FormHeap_Free((void*)t2);
    }
    fC = 0;
    f10 = 0;
    f14 = 0;
}

unsigned int __cdecl FUN_00ec7c56(void);
void __cdecl FormHeap_Free(void*);

struct InnerVec
{
    int unk00;
    int unk04;
    int unk08;
    void** _first;
    void** _last;
    void** _end;
};

struct OuterVec
{
    int unk00;
    int unk04;
    int unk08;
    InnerVec* _first;
    InnerVec* _last;
    InnerVec* _end;
};

struct FUN_00b32350_shell
{
    void FUN_00b32350();
};
struct FUN_00b32120_shell
{
    void FUN_00b32120();
};

struct ScratchFrame
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
};

struct TargetClass
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
    OuterVec m_outer;
    void ClearOuter();
};

// @fnv 0x00b30da0
void TargetClass::ClearOuter()
{
    unsigned int i;
    unsigned int jL;
    void* _v;
    OuterVec* a7;
    OuterVec* B;
    InnerVec* PG;
    OuterVec* C4;
    InnerVec* cQ;
    OuterVec* D5;
    InnerVec* bS;
    OuterVec* r;
    ScratchFrame buf5;
    for (i = 0; (a7 = &m_outer, i < (unsigned int)(a7->_last - a7->_first)); ++i)
    {
        for (jL = 0; (B = &m_outer, (void)(i < (unsigned int)(B->_last - B->_first) || FUN_00ec7c56()),
                     jL < (unsigned int)((PG = B->_first + i)->_last - PG->_first));
             ++jL)
        {
            C4 = &m_outer;
            if (i >= (unsigned int)(C4->_last - C4->_first))
                FUN_00ec7c56();
            cQ = C4->_first + i;
            if (jL >= (unsigned int)(cQ->_last - cQ->_first))
                FUN_00ec7c56();
            _v = cQ->_first[jL];
            FormHeap_Free(_v);
            D5 = &m_outer;
            if (i >= (unsigned int)(D5->_last - D5->_first))
                FUN_00ec7c56();
            bS = D5->_first + i;
            if (jL >= (unsigned int)(bS->_last - bS->_first))
                FUN_00ec7c56();
            bS->_first[jL] = 0;
        }
        r = &m_outer;
        if (i >= (unsigned int)(r->_last - r->_first))
            FUN_00ec7c56();
        ((FUN_00b32350_shell*)(r->_first + i))->FUN_00b32350();
    }
    ((FUN_00b32120_shell*)&m_outer)->FUN_00b32120();
}

struct FUN_00b32210_Class
{
    void __thiscall FUN_00b32210(void* p);
};
struct FUN_00b30020_Class
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
    FUN_00b32210_Class sub;
    int __thiscall FUN_00b30060(float* p);
    void __thiscall FUN_00b30020(float* a);
};
// Calls FUN_00b30060 with a, then passes the address of the result to sub.FUN_00b32210.
// @fnv 0x00b30020
void __thiscall FUN_00b30020_Class::FUN_00b30020(float* a)
{
    int iResult;
    int CNVal;
    int CN_;
    int Diff_;
    int LeftB;
    int PNA;
    int _Dest_;
    int _Dir;
    int _DirZ_;
    int _KindB;
    int _LastZ;
    int _TIdA;
    int _TId_;
    int _ValZB;
    int _ValZ_;
    int _ZDir;
    int _ZDirB;
    int _ZVal;
    int _ab;
    int _alarm;
    int _all;
    int _angle;
    int _bHit;
    int _bVis;
    int _cR;
    int _cellA;
    int _cellY;
    int _cost;
    int _depth;
    int _dirZ;
    int _draw;
    int _eb;
    int _equip;
    iResult = FUN_00b30060(a);
    sub.FUN_00b32210((void*)&iResult);
}

struct FUN_00b30560_data
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
    unsigned int unk28;
    unsigned int unk2c;
};

struct FUN_00b0dae0_cls
{
    void FUN_00b0dae0(unsigned char& value);
};

class FUN_00b30560_cls
{
  public:
    int unk00;
    FUN_00b30560_data* m_04;
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
    FloatVec m_160;
    char unk161;
    char unk162;
    char unk163;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    FUN_00b0dae0_cls m_178;

    void FUN_00b30560(float value, unsigned char index);
};

// Pushes 1.0f - value onto m_160, maps index to unk28 + index % unk2c from m_04, and passes it to m_178.FUN_00b0dae0.
// @fnv 0x00b30560
void FUN_00b30560_cls::FUN_00b30560(float value, unsigned char index)
{
    int CNVal;
    int Diff2;
    int EntryLoc;
    int EntryLocA;
    int EntryLocTmp;
    int LeftB;
    int PN4;
    int PNA;
    int StartLoc2;
    int StartLoc7;
    int a1c5;
    int a1c9;
    int a1cA;
    int a1cTmp7;
    int aA190;
    int aAC;
    int aARes;
    int aAcName;
    int aActor;
    int aActor2;
    int aActorHolder;
    int aActorMarkers;
    int aActorPt;
    int aActorStatus;
    int aAdjustX;
    int aAfter7e;
    int aAllowEquip;
    int aAlternate;
    int aAngVel;
    int aAnglePitch5;
    int aAnglePitch9;
    int aAnglePitchA;
    int aAnglePitchY;
    int aAngleStep;
    int aAngleYaw5;
    int aAngleYawB;
    int aAnimation;
    int aArc;
    int aArg;
    int aArgument5;
    int aArr2;
    int aAttached8;
    int aAvailable;
    int aAvoided;
    int aB1;
    int aB6;
    int aBAdded;
    int aBArmor;
    int aBDD;
    int aBDeleted;
    int aBGood5;
    int aBHandled;
    int aBShowMsg;
    int aBSwap5;
    int aBTeammate;
    int aBTemp;
    unsigned int aa;
    FUN_00b30560_data* bb;
    unsigned int cc;

    value = 1.0f - value;
    cc = 0;
    aa = 1;
    bb = m_04;
    cc = bb->unk28;
    aa = bb->unk2c;
    index = (unsigned char)((unsigned int)index % aa + cc);

    m_160.PushBack(value);
    m_178.FUN_00b0dae0(index);
}
