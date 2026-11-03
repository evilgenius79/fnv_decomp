
// src/fallout/magic/magicboltprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicboltprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct RefH
{
    bool IsDeleted() const;
};

struct FUN_00811930_shell : RefH
{
    bool IsNotDeleted() const;
};

// @fnv 0x00811930
bool FUN_00811930_shell::IsNotDeleted() const
{
    return !IsDeleted();
}

extern int DAT_011ae61c;

// @fnv 0x00811e00
void FUN_00811e00(int value)
{
    DAT_011ae61c = value;
}

struct FUN_008133d0_shell
{
    void FUN_008133d0(int value);
};

// @fnv 0x008133d0
void FUN_008133d0_shell::FUN_008133d0(int value)
{
    *(int*)((char*)this + 0xac) = value;
}

void __cdecl Deallocate(void* p);
struct FUN_00811950_shell
{
    void FUN_00811e10();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_00811e10, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00811950
void* FUN_00811950_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00811e10();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0081e830_shell
{
    unsigned short GetSaveRecordSize(unsigned int flags);
};
struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct SinglyLinkedListNode
{
    SinglyLinkedListNode* pNext;
};
struct FUN_00814590_shell
{
    SinglyLinkedListNode* m_pListNode;
    unsigned short GetSaveSize(unsigned int flags);
};
// @fnv 0x00814590
unsigned short FUN_00814590_shell::GetSaveSize(unsigned int flags)
{
    unsigned short size = 0;
    size += ((FUN_0081e830_shell*)this)->GetSaveRecordSize(flags);
    size += 4;
    size += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x30)
    {
        size += 0xc;
        size += 0x10;
        size += 4;
    }
    size += 4;
    size += 2;
    SinglyLinkedListNode* bolt = *(SinglyLinkedListNode**)((char*)this + 0xb0);
    while (bolt)
    {
        size += 4;
        bolt = *(SinglyLinkedListNode**)((char*)bolt + 0x1c);
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
        size += 4;
    return size;
}

struct H006815c0
{
    void _ref_006815c0();
};
struct FUN_00814aa0
{
    H006815c0 m0;
    char pad0[11];
    H006815c0 m1;
    char pad1[19];
    int f20;
    FUN_00814aa0();
};
// Calls _ref_006815c0 on m0 and m1 and sets f20 to 0.
// @fnv 0x00814aa0
FUN_00814aa0::FUN_00814aa0()
{
    m0._ref_006815c0();
    m1._ref_006815c0();
    f20 = 0;
}

class Sub4_b4201
{
  public:
    unsigned int m_00;
    ~Sub4_b4201();
};

class Sub16_b4201
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub16_b4201();
};

class FUN_008121a0_cls
{
  public:
    Sub4_b4201 m_00;
    Sub16_b4201 m_04;
    Sub4_b4201 m_14;
    Sub4_b4201 m_18;
    ~FUN_008121a0_cls();
};

// @fnv 0x008121a0
FUN_008121a0_cls::~FUN_008121a0_cls()
{}

struct NiPoint3
{
    float x, y, z;
};
struct Quat16
{
    float a, b, c, d;
    Quat16();
};
struct Node3D
{
    NiPoint3& GetPos();
    void GetRot(Quat16* out);
};
struct PathReq
{
    float GetSmoothingRandomness();
};
struct PathPtr
{
    operator PathReq*() const;
};
struct Form
{
    unsigned int GetRefID();
};
struct NameStr
{
    operator const char*() const;
};
Form* LookupByName(const char* name);
struct AreaBoltNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NameStr name;
    AreaBoltNode* next;
};
struct SaveGame
{
    void WriteRaw(void* p, int size);
    unsigned short* ReserveCount();
};
struct SaveBaseObj
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
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
    PathPtr pathing;
    int unkAC;
    AreaBoltNode* m_pListNode;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    Form* pForm;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    void SaveBase(int arg);
    void WriteData(void* p, int size);
    void WriteRefID(void* p, int size);
};
struct ThisObj : SaveBaseObj
{
    virtual Node3D* GetNode3D();
    void SaveAreaBoltData(int arg);
};

// Saves the object's base data, position/rotation and smoothing when version >= 0x30, its form refID, and each linked bolt node's refID with a count.
// @fnv 0x00814670
void ThisObj::SaveAreaBoltData(int arg)
{
    SaveBase(arg);
    ((SaveGame*)g_TESSaveLoadGame)->WriteRaw(&unkAC, 4);
    WriteData(&unk88, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x30)
    {
        NiPoint3 pos4 = GetNode3D()->GetPos();
        WriteData(&pos4, 12);
        Quat16 rot;
        GetNode3D()->GetRot(&rot);
        ((SaveGame*)g_TESSaveLoadGame)->WriteRaw(&rot, 16);
        float smooth5 = 0.0f;
        if (pathing)
            smooth5 = ((PathReq*)pathing)->GetSmoothingRandomness();
        WriteData(&smooth5, 4);
    }
    unsigned int formIDA = 0;
    if (pForm)
        formIDA = pForm->GetRefID();
    WriteRefID(&formIDA, 4);
    unsigned short count = 0;
    unsigned short* aPCount = ((SaveGame*)g_TESSaveLoadGame)->ReserveCount();
    WriteData(&count, 2);
    AreaBoltNode* node7 = m_pListNode;
    while (node7)
    {
        unsigned int boltID = 0;
        if ((const char*)node7->name)
        {
            Form* f5 = LookupByName(node7->name);
            if (f5)
                boltID = f5->GetRefID();
        }
        WriteRefID(&boltID, 4);
        count++;
        node7 = node7->next;
    }
    *aPCount = count;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
        WriteData(&unkD4, 4);
}

struct HUDNode;

struct HUDParent
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void InsertChild(HUDNode* apChild);
};

struct HUDNode
{
    HUDParent* GetParent();
};

template <class T> struct HUDPointer
{
    T* m_pObject;

    ~HUDPointer();
    HUDPointer& operator=(T* apObject);
    operator T*() const;
};

struct HUDSoundHandle
{
    unsigned int uiID;
    unsigned int uiState;
    unsigned int uiFlags;

    ~HUDSoundHandle();
    bool IsValid();
    void Stop();
    void FUN_00ad8d10();
};

struct HUDEntry
{
    HUDPointer<HUDNode> m_pController;
    HUDPointer<HUDNode> m_pRootNode;
    int unk08;
    int unk0C;
    int unk10;
    HUDPointer<HUDNode> sp14;
    HUDPointer<HUDNode> sp18;
    HUDEntry* pNext;

    ~HUDEntry();
};

void __cdecl FUN_00bc1470(HUDNode* apRoot, HUDNode* apNode);
void __cdecl FUN_0080fc90(float afValue);

struct HUDSetting
{
    float* Float();
};

struct HUDMagicTarget
{
    virtual void v00();
};

struct HUDPlayerBase
{
    virtual void v00();
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
};

struct HUDPlayer : HUDPlayerBase, HUDMagicTarget
{
};

struct HUDBaseA
{
    virtual ~HUDBaseA();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
};

struct HUDBaseB
{
    virtual void v00();
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
};

struct HUDBase : HUDBaseA, HUDBaseB
{
    ~HUDBase();
};

struct FUN_00811e10;

struct HUDList
{
    void Remove(FUN_00811e10* const& arItem);
};

struct HUDProcessLists
{
    HUDList* GetOffset70Ptr();
};

extern HUDPlayer* g_pHUDPlayer;
extern HUDSetting g_kHUDSetting;
extern HUDProcessLists g_kHUDProcessLists;

struct FUN_00811e10 : HUDBase
{
    HUDPointer<HUDNode> spA8;
    int unkAC;
    HUDEntry* pEntries;
    HUDPointer<HUDNode> spB4;
    HUDPointer<HUDNode> spB8;
    HUDPointer<HUDNode> spBC;
    HUDPointer<HUDNode> spC0;
    int unkC4;
    HUDSoundHandle kSound;

    HUDMagicTarget* GetTarget();
    virtual ~FUN_00811e10();
};

// @fnv 0x00811e10
FUN_00811e10::~FUN_00811e10()
{
    if (GetTarget() != g_pHUDPlayer)
        FUN_0080fc90(*g_kHUDSetting.Float());

    HUDList* pList = g_kHUDProcessLists.GetOffset70Ptr();
    if (pList)
        pList->Remove(this);

    FUN_00bc1470(spB4, spA8);
    spA8 = 0;
    if (spB4)
    {
        HUDParent* pParent = ((HUDNode*)spB4)->GetParent();
        if (pParent)
            pParent->InsertChild(spB4);
    }
    spC0 = 0;
    spB4 = 0;
    spB8 = 0;
    spBC = 0;

    while (pEntries)
    {
        HUDEntry* pNext = pEntries->pNext;
        FUN_00bc1470(pEntries->m_pRootNode, pEntries->m_pController);
        pEntries->m_pController = 0;
        if (pEntries->m_pRootNode)
        {
            HUDParent* pEntryParent = ((HUDNode*)pEntries->m_pRootNode)->GetParent();
            if (pEntryParent)
                pEntryParent->InsertChild(pEntries->m_pRootNode);
        }
        pEntries->m_pRootNode = 0;
        pEntries->sp14 = 0;
        pEntries->sp18 = 0;
        delete pEntries;
        pEntries = pNext;
    }

    if (kSound.IsValid())
    {
        kSound.Stop();
        kSound.FUN_00ad8d10();
    }
}

struct BoltPoint
{
    float x, y, z;
};
struct BoltMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    BoltMatrix();
    void FUN_00a59660(float, float, float);
};
struct BoltColor
{
    float r, g, b, a;
    BoltColor(float, float, float, float);
};
void* FUN_00aa13e0(unsigned int);
void FUN_00aa13f0(void*);
struct BoltProperty
{
    int unk00, unk04, unk08, unk0c;
    BoltProperty();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void FUN_00519230(bool, bool);
};
struct BoltNode
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
    BoltNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void FUN_004f00e0(const BoltPoint&);
    void FUN_00440460(const BoltPoint&);
    BoltProperty* FUN_00a5bdd0(const char*);
    void FUN_00a5bc40(const char*, BoltProperty*);
    void FUN_0043fa80(const BoltMatrix&);
};
__forceinline void* BoltNode::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void BoltNode::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
__forceinline void* BoltProperty::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void BoltProperty::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct BoltFx
{
    void FUN_00803a70(int);
    void FUN_00821620(float);
    void FUN_00507780(float);
    void SetBoltSmallWidth(float);
    void SetBoltGrowWidth(float);
    void SetArg(BoltColor);
    void SetData(BoltColor);
    void FUN_00803b30(float);
    void SetWhich(int);
    void FUN_005077a0(float);
    void FUN_00803b50(float);
    void FUN_00803a50(bool);
    void FUN_00bc2360();
};
struct BoltNodePtr
{
    BoltNode* ptr;
    void FUN_0066b0d0(BoltNode*);
    BoltNode* FUN_00559450();
};
struct BoltFxPtr
{
    BoltFx* ptr;
    void FUN_0066b0d0(BoltFx*);
    BoltFx* FUN_00559450();
};
struct BoltSetting
{
    int* FUN_0043d4d0();
    float* FUN_00403e20();
};
extern BoltSetting DAT_011d186c, DAT_011d1628, DAT_011d1bec, DAT_011d1610, DAT_011d1b2c, DAT_011d18f0, DAT_011d1908,
    DAT_011d1be0, DAT_011d1cdc, DAT_011d19d8, DAT_011d1c4c, DAT_011d174c, DAT_011d1800, DAT_011d16c8, DAT_011d17c4;
const char* FUN_00448a80();
BoltFx* FUN_00bc18d0(BoltNode*, bool);
struct Bolt
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
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual const BoltPoint& Position();
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    BoltFxPtr effect;
    int unkac, unkb0;
    BoltNodePtr emitter;
    int unkb8, unkbc;
    BoltNodePtr root;
    const BoltPoint& FUN_00430830();
    void InitEffect();
};
// Creates root and emitter nodes at Position(), sets up an emitter property, applies a rotation matrix, and configures the spawned effect from settings.
// @fnv 0x00812220
void Bolt::InitEffect()
{
    root.FUN_0066b0d0(new BoltNode(0));
    root.FUN_00559450()->FUN_004f00e0(Position());
    emitter.FUN_0066b0d0(new BoltNode(0));
    emitter.FUN_00559450()->FUN_00440460(Position());
    BoltProperty* property = emitter.FUN_00559450()->FUN_00a5bdd0(FUN_00448a80());
    if (!property)
    {
        property = new BoltProperty;
        emitter.FUN_00559450()->FUN_00a5bc40(FUN_00448a80(), property);
    }
    property->FUN_00519230(true, true);
    effect.FUN_0066b0d0(0);
    BoltPoint rotation = FUN_00430830();
    BoltMatrix matrix2;
    matrix2.FUN_00a59660(rotation.z, rotation.x, rotation.y);
    emitter.FUN_00559450()->FUN_0043fa80(matrix2);
    effect.FUN_0066b0d0(FUN_00bc18d0(emitter.FUN_00559450(), true));
    if (effect.FUN_00559450())
    {
        effect.FUN_00559450()->FUN_00803a70(*DAT_011d186c.FUN_0043d4d0());
        effect.FUN_00559450()->FUN_00821620(*DAT_011d1628.FUN_00403e20());
        effect.FUN_00559450()->FUN_00507780(*DAT_011d1bec.FUN_00403e20());
        effect.FUN_00559450()->SetBoltSmallWidth(*DAT_011d1610.FUN_00403e20());
        effect.FUN_00559450()->SetBoltGrowWidth(*DAT_011d1b2c.FUN_00403e20());
        effect.FUN_00559450()->SetArg(
            BoltColor(*DAT_011d1be0.FUN_00403e20(), *DAT_011d1908.FUN_00403e20(), *DAT_011d18f0.FUN_00403e20(), 1.0f));
        effect.FUN_00559450()->SetData(
            BoltColor(*DAT_011d1c4c.FUN_00403e20(), *DAT_011d19d8.FUN_00403e20(), *DAT_011d1cdc.FUN_00403e20(), 1.0f));
        effect.FUN_00559450()->FUN_00803b30(*DAT_011d174c.FUN_00403e20());
        effect.FUN_00559450()->SetWhich(*DAT_011d1800.FUN_0043d4d0());
        effect.FUN_00559450()->FUN_005077a0(*DAT_011d16c8.FUN_00403e20());
        effect.FUN_00559450()->FUN_00803b50(*DAT_011d17c4.FUN_00403e20());
        effect.FUN_00559450()->FUN_00803a50(true);
        effect.FUN_00559450()->FUN_00bc2360();
    }
}

struct AimPoint3
{
    float x;
    float y;
    float z;

    AimPoint3();
    AimPoint3 operator-(const AimPoint3& arOther) const;
    float Length();
};

struct AimMatrix3
{
    float m[9];

    AimMatrix3();
    void SetRotationFromEulerXYZ(float afX, float afY, float afZ);
};

struct AimUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int unk08;

    AimUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};

struct AimNode
{
    AimPoint3* GetWorldTranslate();
    void SetLocalTranslate(const AimPoint3& arTranslate);
    void SetLocalRotate(const AimMatrix3& arRotate);
    void Update(AimUpdateData& arData);
};

struct AimNodePtr
{
    AimNode* pObject;

    operator AimNode*() const;
};

struct AimSource
{
    AimPoint3* GetWorldTranslate();
};

struct AimTarget
{
    void GetAimPoint(AimPoint3& arOut);
};

struct AimMagicTarget
{
    int unk00;
};

struct AimRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual bool IsActor();
};

struct AimActor : AimRef
{
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
};

struct AimSecondBase
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual AimSource* GetSource();
};

struct AimFullActor : AimActor, AimSecondBase
{
};

struct AimPlayer : AimFullActor
{
    bool FUN_004eaf60();
};

struct AimOwner
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual AimRef* GetRef();
};

float __cdecl AimAtan2(float afY, float afX);

extern AimPlayer* g_pAimPlayer;
extern double g_dAimZero;

struct AimProjectile
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
    AimNodePtr m_pController;

    AimOwner* FUN_009185e0();
    AimTarget* FUN_009306d0();
    float GetField90Float();
    bool UpdateProjectileAimNode();
};

// Aligns the projectile's aim node to the source or target position and rotation, updates it, and returns false when a source, target and node exist.
// @fnv 0x00812890
bool AimProjectile::UpdateProjectileAimNode()
{
    AimOwner* pOwnerB = FUN_009185e0();
    AimRef* pRef4 = pOwnerB ? pOwnerB->GetRef() : 0;
    AimFullActor* pActor2 = (pRef4 && pRef4->IsActor()) ? (AimFullActor*)pRef4 : 0;
    AimSource* pSource = pActor2 ? pActor2->GetSource() : 0;
    AimTarget* aPTarget = FUN_009306d0();

    if (pSource && aPTarget && (AimNode*)m_pController)
    {
        if (GetField90Float() < 0.5 && pActor2 == g_pAimPlayer && !g_pAimPlayer->FUN_004eaf60())
        {
            AimPoint3 kPos = *pSource->GetWorldTranslate();
            ((AimNode*)m_pController)->SetLocalTranslate(kPos);
        }
        if (GetField90Float() > g_dAimZero)
        {
            AimPoint3 kNodePosB = *((AimNode*)m_pController)->GetWorldTranslate();
            AimPoint3 kTargetPos3;
            aPTarget->GetAimPoint(kTargetPos3);
            AimPoint3 kKDir = kTargetPos3 - kNodePosB;
            AimMatrix3 kRotate_2;
            float fZ8 = kKDir.z;
            kKDir.z = 0.0f;
            float aFLength = kKDir.Length();
            kRotate_2.SetRotationFromEulerXYZ(AimAtan2(kKDir.x, kKDir.y), 0.0f, -AimAtan2(fZ8, aFLength));
            ((AimNode*)m_pController)->SetLocalRotate(kRotate_2);
        }
        AimUpdateData kDataX(0.0f, false, false);
        ((AimNode*)m_pController)->Update(kDataX);
        return false;
    }
    return true;
}

void* __cdecl operator new(unsigned int);
struct Helper009f8770
{
    void FUN_00484d00(void*, int);
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
struct NiQuaternion
{
    static const Quat16 IDENTITY;
};
struct PlayerCharacter : SaveBaseObj
{
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual NiPoint3* GetPosition();
};
extern PlayerCharacter* pPlayer;
struct LoadObject : ThisObj
{
    void FUN_0081e980(int, int);
    void LoadObjectData(int, int);
};
// @fnv 0x00814870
void LoadObject::LoadObjectData(int arg1, int arg2)
{
    v71();
    FUN_0081e980(arg1, arg2);
    reinterpret_cast<FUN_008579e0_shell*>(g_TESSaveLoadGame)->FUN_008579e0(&unkAC, 4);
    reinterpret_cast<Helper009f8770*>(this)->FUN_00484d00(&unk88, 4);
    FUN_00814aa0* formID = new FUN_00814aa0;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x30)
    {
        reinterpret_cast<Helper009f8770*>(this)->FUN_00484d00(&formID->m0, 12);
        reinterpret_cast<FUN_008579e0_shell*>(g_TESSaveLoadGame)->FUN_008579e0(&formID->m1, 16);
        reinterpret_cast<Helper009f8770*>(this)->FUN_00484d00(reinterpret_cast<Quat16*>(&formID->m1) + 1, 4);
    }
    if (g_TESSaveLoadGame->FUN_008df040() < 0x30)
    {
        reinterpret_cast<NiPoint3&>(formID->m0) = *pPlayer->GetPosition();
        reinterpret_cast<Quat16&>(formID->m1) = NiQuaternion::IDENTITY;
    }
    unsigned int count;
    reinterpret_cast<FUN_00484d40_Host*>(this)->FUN_00484d40(&count, 4);
    pForm = reinterpret_cast<Form*>(count);
    unsigned short state;
    reinterpret_cast<Helper009f8770*>(this)->FUN_00484d00(&state, 2);
    if (state)
    {
        formID->f20 = reinterpret_cast<int>(new unsigned int[state + 1]);
        *reinterpret_cast<unsigned int*>(formID->f20) = state;
        reinterpret_cast<FUN_00484d40_Host*>(this)->FUN_00484d40(reinterpret_cast<unsigned int*>(formID->f20) + 1,
                                                                 state * 4);
    }
    m_pListNode = reinterpret_cast<AreaBoltNode*>(formID);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
        reinterpret_cast<Helper009f8770*>(this)->FUN_00484d00(&unkD4, 4);
}

class TESForm
{
  public:
    virtual void v00();
};
class NiFixedString
{
  public:
    const char* text;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct SceneNode
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual SceneNode* FindNode(const NiFixedString& name);
};
class TESObjectREFR : public TESForm
{
  public:
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual SceneNode* GetNode3D();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const NiPoint3& GetPosition();
};
struct NodePointer
{
    SceneNode* value;
    operator SceneNode*() const;
    NodePointer& operator=(SceneNode*);
};
struct AudioPlaybackHandle
{
    unsigned int soundID;
    unsigned int state;
    unsigned int flags;
    ~AudioPlaybackHandle();
    AudioPlaybackHandle& operator=(const AudioPlaybackHandle&);
    bool FUN_00ad8ce0();
    void FUN_00ad8d10();
    bool SetPos(float x, float y, float z);
    void SetNiNode(SceneNode*);
    bool Play(bool);
};
struct SoundForm
{
    unsigned int GetFormID();
};
struct ProjectileEffect
{
    SoundForm* GetBoltSound();
};
struct ProjectileCell
{
    void AddReference(TESObjectREFR*, bool);
};
struct AudioManager
{
    static AudioManager* GetSingleton();
    AudioPlaybackHandle FUN_00ad73b0(unsigned int id, unsigned int flags);
};
TESForm* LookupFormByID(unsigned int id);
class MagicProjectile : public TESObjectREFR
{
  public:
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
    NodePointer nodeB4;
    int unkB8;
    NodePointer spineNode;
    NodePointer soundNode;
    TESObjectREFR* sourceReference;
    AudioPlaybackHandle sound;
    void ResolveMagicReferences(int arg1, int arg2);
    void InitEffect();
    void FUN_00570f70(SceneNode*);
    ProjectileCell* GetParentCell();
    ProjectileEffect* FUN_004fd400();
    void InitializeProjectile(int arg1, int arg2);
};
// @fnv 0x00814ad0
void MagicProjectile::InitializeProjectile(int arg1, int arg2)
{
    ResolveMagicReferences(arg1, arg2);
    unsigned int referenceID = reinterpret_cast<unsigned int>(sourceReference);
    if (referenceID)
    {
        sourceReference = dynamic_cast<TESObjectREFR*>(LookupFormByID(referenceID));
        if (sourceReference)
        {
            SceneNode* node = sourceReference->GetNode3D();
            if (node)
            {
                spineNode = node->FindNode(NiFixedString("Bip01 Spine2"));
            }
        }
    }
    InitEffect();
    FUN_00570f70(nodeB4);
    GetParentCell()->AddReference(this, false);
    if (FUN_004fd400()->GetBoltSound())
    {
        unsigned int soundID = FUN_004fd400()->GetBoltSound()->GetFormID();
        if (sound.FUN_00ad8ce0())
            sound.FUN_00ad8d10();
        if (GetNode3D())
        {
            sound = AudioManager::GetSingleton()->FUN_00ad73b0(soundID, 0x102);
            NiPoint3 position = GetPosition();
            sound.SetPos(position.x, position.y, position.z);
            sound.SetNiNode(soundNode);
            sound.Play(true);
        }
    }
}

struct Vec3
{
    float x, y, z;
    float FUN_00457990();
};

struct OutHandle
{
    int value;
    OutHandle(const OutHandle&);
    int FUN_004a3a20();
};

struct GameObject
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

    virtual GameObject* child();

    virtual void slot12();

    virtual void slot13();

    virtual void slot14();

    virtual void slot15();

    virtual void slot16();

    virtual void slot17();

    virtual void slot18();

    virtual void slot19();

    virtual void slot20();

    virtual void slot21();

    virtual void slot22();

    virtual void slot23();

    virtual void slot24();

    virtual void slot25();

    virtual void slot26();

    virtual void slot27();

    virtual void slot28();

    virtual void slot29();

    virtual void slot30();

    virtual void slot31();

    virtual void slot32();

    virtual void slot33();

    virtual void slot34();

    virtual void slot35();

    virtual void slot36();

    virtual void slot37();

    virtual void slot38();

    virtual void slot39();

    virtual void slot40();

    virtual void slot41();

    virtual void slot42();

    virtual void slot43();

    virtual void slot44();

    virtual void slot45();

    virtual void slot46();

    virtual void slot47();

    virtual void slot48();

    virtual void slot49();

    virtual void slot50();

    virtual void slot51();

    virtual void slot52();

    virtual void slot53();

    virtual void slot54();

    virtual void slot55();

    virtual void slot56();

    virtual void slot57();

    virtual void slot58();

    virtual void slot59();

    virtual void slot60();

    virtual void slot61();

    virtual void slot62();

    virtual void slot63();

    virtual bool isSpecial();

    virtual void slot65();

    virtual void slot66();

    virtual void slot67();

    virtual void slot68();

    virtual void slot69();

    virtual void slot70();

    virtual void slot71();

    virtual void slot72();

    virtual void slot73();

    virtual void slot74();

    virtual void slot75();

    virtual void slot76();

    virtual void slot77();

    virtual void slot78();

    virtual void slot79();

    virtual void slot80();

    virtual void slot81();

    virtual void slot82();

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void slot89();

    virtual void slot90();

    virtual void slot91();

    virtual void slot92();

    virtual void slot93();

    virtual void slot94();

    virtual void slot95();

    virtual void slot96();

    virtual void slot97();

    virtual void slot98();

    virtual void slot99();

    virtual void slot100();

    virtual void slot101();

    virtual void slot102();

    virtual void slot103();

    virtual void slot104();

    virtual void slot105();

    virtual void slot106();

    virtual void slot107();

    virtual void slot108();

    virtual void slot109();

    virtual void slot110();

    virtual void slot111();

    virtual void slot112();

    virtual void slot113();

    virtual void slot114();

    virtual void slot115();

    virtual int formID();

    virtual void slot117();

    virtual void slot118();

    virtual void slot119();

    virtual void slot120();

    virtual void slot121();

    virtual void slot122();

    virtual void slot123();

    virtual void slot124();

    virtual Vec3* position();

    virtual void slot126();

    virtual void slot127();

    virtual void slot128();

    virtual void slot129();

    virtual void slot130();

    virtual void slot131();

    virtual void slot132();

    virtual void slot133();

    virtual void slot134();

    virtual void slot135();

    virtual void slot136();

    virtual void slot137();

    virtual void slot138();

    virtual void slot139();

    virtual void slot140();

    virtual void slot141();

    virtual void slot142();

    virtual void slot143();

    virtual void slot144();

    virtual void slot145();

    virtual void slot146();

    virtual void slot147();

    virtual void slot148();

    virtual void slot149();

    virtual void slot150();

    virtual void slot151();

    virtual void slot152();

    virtual void slot153();

    virtual void slot154();

    virtual void slot155();

    virtual void slot156();

    virtual void slot157();

    virtual void slot158();

    virtual void slot159();

    virtual void slot160();

    virtual void slot161();

    virtual void slot162();

    virtual void slot163();

    virtual void slot164();

    virtual void slot165();

    virtual void slot166();

    virtual void slot167();

    virtual void slot168();

    virtual void slot169();

    virtual void slot170();

    virtual void slot171();

    virtual void slot172();

    virtual void slot173();

    virtual void slot174();

    virtual void slot175();

    virtual void slot176();

    virtual void slot177();

    virtual void slot178();

    virtual void slot179();

    virtual void slot180();

    virtual void slot181();

    virtual void slot182();

    virtual void slot183();

    virtual void slot184();

    virtual void slot185();

    virtual void slot186();

    virtual void slot187();

    virtual void slot188();

    virtual void slot189();

    virtual void slot190();

    virtual void slot191();

    virtual void slot192();

    virtual void slot193();

    virtual void visitReference(GameObject*, int);

    OutHandle FUN_00931ed0();

    OutHandle FUN_0043b4f0();

    GameObject* FUN_006fa820();

    int FUN_004a3a20();

    float FUN_00457990();

    GameObject* FUN_0045bb80(Vec3*, void*);

    GameObject* FUN_00439ef0();

    void FUN_00440460(void*);

    void FUN_004f0160(void*);

    void FUN_0043fa80(void*);

    void DispatchFloatPair(float, float, float, bool);

    bool FUN_00ee8990();
};

struct Holder
{
    GameObject* FUN_00559450();
};

struct Pending
{

    Vec3 FUN_00439ef0(Vec3*);

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;

    float value1c;

    struct RefList* refs20;
};

struct RefList
{
    unsigned short count;
    unsigned short reserved;
    int entries[1];
};

struct LocalStore
{

    void* value;

    void FUN_004a39f0(int);

    void FUN_0059ce80(int);

    void SetFlag4000(int);
};

struct Control
{

    void FUN_0070c440(LocalStore*);

    void FUN_00810ff0(void*);
};

struct Matrix
{

    float a, b, c, d, e, f, g, h, i;

    void FUN_006815c0();

    void FUN_00a59780(float, float, float);
};

struct Clock
{
    float* FUN_00403e20();
};

extern Clock DAT_011d1758;

extern GameObject* DAT_011dea3c;

extern GameObject* __cdecl FUN_004b5260(int);

extern int __cdecl FUN_005dbe10();

extern void __cdecl FUN_0080fae0(float);

extern GameObject* __cdecl FUN_00825550(int);

extern void __cdecl Deallocate(void*);

extern float __cdecl FUN_004b5550(float, float);

struct Root : GameObject
{

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

    float f088;

    int unk08c;

    int unk090;

    int unk094;

    int unk098;

    int unk09c;

    int unk0a0;

    int unk0a4;

    Holder m0a8;

    int state0ac;

    Pending* active0b0;

    Holder m0b4;

    int unk0b8;

    Holder m0bc;

    void UpdateFlags(int, int);

    Control* FUN_009306d0();

    GameObject* FUN_009185e0();

    void FUN_008133d0(int);

    void UpdatePending(int, int);
};

// Applies the pending entry to the active holders, updates the control and rotation, then visits its references and deletes it.
// @fnv 0x00814d40
void Root::UpdatePending(int arg1, int arg2)

{

    UpdateFlags(arg1, arg2);

    Control* a = FUN_009306d0();
    LocalStore handle;

    if (a)
    {

        int selected;

        if (FUN_009185e0() && FUN_009185e0()->child())
        {

            GameObject* special = FUN_009185e0()->child();

            GameObject* current = special->isSpecial() ? special : 0;

            if (current)
            {

                selected = current->FUN_00931ed0().FUN_004a3a20();
            }
            else
            {

                GameObject* form = FUN_004b5260(special->formID());

                GameObject* item = form ? form->FUN_006fa820() : 0;

                selected = item ? item->FUN_0043b4f0().FUN_004a3a20() : FUN_005dbe10();
            }
        }
        else
        {

            GameObject* form = FUN_004b5260(formID());

            GameObject* item = form ? form->FUN_006fa820() : 0;

            selected = item ? item->FUN_0043b4f0().FUN_004a3a20() : FUN_005dbe10();
        }

        a->FUN_0070c440(&handle);

        handle.FUN_004a39f0(7);

        handle.FUN_0059ce80(selected);

        a->FUN_00810ff0(handle.value);
    }

    GameObject* candidate = FUN_009185e0() ? FUN_009185e0()->child() : 0;

    if (candidate != DAT_011dea3c)
    {

        FUN_0080fae0(*DAT_011d1758.FUN_00403e20());
    }

    Pending* pending = active0b0;

    if (pending)
    {

        if (m0b4.FUN_00559450())
        {

            m0b4.FUN_00559450()->FUN_00440460(pending);

            m0b4.FUN_00559450()->FUN_004f0160(&pending->unk0c);

            bool force = state0ac != 0;

            if (m0bc.FUN_00559450())
            {

                Vec3 position3d;

                m0bc.FUN_00559450()->FUN_0045bb80(&position3d, pending)->FUN_00439ef0();

                m0a8.FUN_00559450()->DispatchFloatPair(pending->value1c, position3d.FUN_00457990(), f088, force);

                Matrix rot;

                rot.FUN_006815c0();

                float angle = position3d.z;

                position3d.z = 0.0f;

                float azimuth = position3d.FUN_00457990();

                rot.FUN_00a59780(FUN_004b5550(position3d.x, position3d.y), 0.0f, -FUN_004b5550(angle, azimuth));

                m0b4.FUN_00559450()->FUN_0043fa80(&rot);
            }
            else
            {

                Vec3 position3d = *this->position();

                float direction = pending->FUN_00439ef0(&position3d).FUN_00457990();

                m0a8.FUN_00559450()->DispatchFloatPair(pending->value1c, direction, f088, force);

                if (m0a8.FUN_00559450()->FUN_00ee8990() || state0ac == 2)
                {

                    FUN_008133d0(2);

                    LocalStore handle;

                    FUN_009306d0()->FUN_0070c440(&handle);

                    handle.SetFlag4000(1);

                    FUN_009306d0()->FUN_00810ff0(handle.value);
                }
            }
        }

        active0b0 = 0;

        if (pending->refs20)
        {

            unsigned short count = pending->refs20->count;

            for (unsigned int i = 0; i < count; ++i)
            {

                GameObject* ref;
                {
                    int id = pending->refs20->entries[i];
                    ref = FUN_00825550(id);
                }

                if (ref)
                    visitReference(ref, 0);
            }
        }

        delete pending;
    }
}

struct AEPoint3
{
    float x, y, z;
    AEPoint3 FUN_00439ef0(const AEPoint3& kOther) const;  // operator-
    float FUN_00457990() const;                           // Length
};

struct AEPointResult
{
    float a, b, c;
    const AEPoint3& FUN_004b4500();
};

class AENode
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
    virtual AENode* FindNode(const NiFixedString& kName);

    const AEPoint3& FUN_0043c490();  // world translate
    AEPointResult FUN_00461130(const AEPoint3& kPoint, int iIndex);
    AEPointResult FUN_006a9540(const AEPoint3& kPoint);
};

struct AENodePtr
{
    AENode* m_pObject;
    AENodePtr& FUN_0066b0d0(AENode* pkNode);  // operator=
};

class AEController
{
  public:
    void DispatchFloatPair(float fA, float fB, float fC, bool bD);
};

struct AEControllerPtr
{
    AEController* m_pObject;
    AEController* FUN_00559450() const;  // operator T*
};

class AERefr
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
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();  // +0x100
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual AENode* GetNode3D();  // +0x1d0
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const AEPoint3& GetPosition();  // +0x1f4
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();  // +0x310
};

class AEActor : public AERefr
{
  public:
    bool FUN_008ace90();
};

class AEPlayer : public AEActor
{
  public:
    bool FUN_004eaf60();
};

extern AEPlayer* g_thePlayer;

struct AEFlags
{
    int FUN_00621270(int iMask);
};

struct AEHandle
{
    void* m_pIntegerData;
    void SetFlag4000(bool bValue);
};

class AEProcess
{
  public:
    char pad000[0x410];
    AEFlags m_kFlags;
    void FUN_0070c440(AEHandle* pkOut);
    void FUN_00810ff0(void* pvValue);
};

struct AEArea
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int GetValue();  // +0x14
};

struct AESound
{
    unsigned int FUN_0084e3a0();
};

class AEEffect
{
  public:
    char pad00[0x18];
    AEArea m_kArea;
    AESound* FUN_008ce390();
};

struct AEEffectItem
{
    int FUN_00404420();
};

struct AESetting
{
    float* FUN_00403e20();
};
extern AESetting DAT_011d1bbc;
extern AESetting DAT_011d1acc;
extern AESetting DAT_011d15a4;

extern const AEPoint3 DAT_011a9478;

class AEExplosion
{
  public:
    void ApplySpellEffects(void* pvCell, AEPoint3 kPos, AERefr* pkSource, AERefr* pkTarget, int iFlags, float fA,
                           float fB);
};

class AEIdle
{
  public:
    void FUN_00689920(const char* pcName);
};
AEIdle* FUN_006890b0(void* pvCell, float fRadius, int iAreaType, AEPoint3 akStart, AEPoint3 kTo, float fScale,
                     int iType, int iFlags);

class BSSoundHandleEx
{
  public:
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~BSSoundHandleEx();
    bool SetPos(float fX, float fY, float fZ);
    bool Play(bool bLoop);
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx FUN_00ad73b0(unsigned int auiFormId, unsigned int uiFlags);
};

class AEProjectile : public AERefr
{
  public:
    char pad004[0x84];
    float m_f88;
    char pad08c[0x1c];
    AEControllerPtr m_spController;  // +0xa8
    char pad0ac[0x10];
    AENodePtr m_spSpine;  // +0xbc
    int unk0c0;
    AERefr* m_pkSource;  // +0xc4
    char pad0c8[0xc];
    float m_fd4;

    float GetUnka4();
    AEProcess* FUN_009306d0();
    void FUN_008133d0(int iValue);
    void FUN_0081f000(AEPoint3 akStart, AEPoint3 kTo);
    void* FUN_008d6f30();  // GetParentCell
    int FUN_00810fd0();
    AEExplosion* FUN_009185e0(int iType);
    AEEffectItem* FUN_00586150();
    AEEffect* FUN_004fd400();

    void Impact(AEPoint3 kPos, int iIndex, AERefr* pkTarget, bool bSilent);
};

// Handles projectile impact at kPos: updates source/target, controller distance, spawns explosion and area-effect idle, and plays impact sound unless silent.
// @fnv 0x008133f0
void AEProjectile::Impact(AEPoint3 kPos, int iIndex, AERefr* pkTarget, bool bSilent)
{
    AEActor* pkHitActor = (pkTarget && pkTarget->IsActor()) ? (AEActor*)pkTarget : 0;
    if (pkHitActor && pkHitActor->FUN_008ace90())
        return;

    m_fd4 = GetUnka4();
    if (FUN_009306d0())
    {
        if (FUN_009306d0()->m_kFlags.FUN_00621270(0x8000))
            v196();
        AEHandle kHandle;
        FUN_009306d0()->FUN_0070c440(&kHandle);
        kHandle.SetFlag4000(true);
        FUN_009306d0()->FUN_00810ff0(kHandle.m_pIntegerData);
    }
    FUN_008133d0(1);

    AENode* pkNode = GetNode3D();
    if (pkNode)
        FUN_0081f000(kPos, pkNode->FUN_00461130(DAT_011a9478, iIndex).FUN_004b4500());

    if (pkTarget)
    {
        if (pkTarget != g_thePlayer || g_thePlayer->FUN_004eaf60())
        {
            m_pkSource = pkTarget;
            AENode* pkTargetNode = m_pkSource->GetNode3D();
            if (pkTargetNode)
                m_spSpine.FUN_0066b0d0(pkTargetNode->FindNode(NiFixedString("Bip01 Spine2")));
        }
    }

    {
        AEPoint3 kWorldPos = GetNode3D()->FUN_0043c490();
        float fDist = kWorldPos.FUN_00439ef0(kPos).FUN_00457990();
        m_spController.FUN_00559450()->DispatchFloatPair(0.01f, fDist, m_f88, false);
    }

    if (!bSilent)
        FUN_009185e0(FUN_00810fd0())->ApplySpellEffects(FUN_008d6f30(), GetPosition(), this, pkTarget, 0, 1.0f, 1.0f);

    m_pkSource = 0;
    if (FUN_004fd400()->m_kArea.GetValue())
    {
        float fScale = FUN_00586150()->FUN_00404420() * *DAT_011d1bbc.FUN_00403e20();
        if (fScale > *DAT_011d1acc.FUN_00403e20())
            fScale = *DAT_011d1acc.FUN_00403e20();
        else if (fScale < *DAT_011d15a4.FUN_00403e20())
            fScale = *DAT_011d15a4.FUN_00403e20();
        int iAreaType = FUN_004fd400()->m_kArea.GetValue();
        AEPoint3 akStart = GetNode3D() ? GetNode3D()->FUN_006a9540(DAT_011a9478).FUN_004b4500() : DAT_011a9478;
        AEIdle* pkAreaIdle = FUN_006890b0(FUN_008d6f30(), 5.0f, iAreaType, akStart, kPos, 1.0f, 7, 0);
        pkAreaIdle->FUN_00689920("SpecialIdle_AreaEffect");
    }

    if (FUN_004fd400()->FUN_008ce390() && !bSilent)
    {
        unsigned int auiFormId = FUN_004fd400()->FUN_008ce390()->FUN_0084e3a0();
        BSSoundHandleEx kSound = BSAudio::GetSingleton()->FUN_00ad73b0(auiFormId, 0x102);
        AEPoint3 kSoundLoc = GetPosition();
        kSound.SetPos(kSoundLoc.x, kSoundLoc.y, kSoundLoc.z);
        kSound.Play(false);
    }
}

struct F139Node;
struct F139Ref;
struct F139Owner
{
    virtual void v0();
    virtual F139Ref* v1();
};
struct F139Node
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
    virtual F139Node* find(const NiFixedString&);
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
    virtual void attach(F139Node*, bool);
};
struct F139Ref
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
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual F139Node* node();
};
struct F139Vec
{
    float x, y, z;
    void FUN_006815c0();
};
struct F139Cell
{
    F139Node* FUN_005497a0();
};
struct F139Result
{
    void FUN_00812b00(F139Vec*);
};
struct F139Color
{
    float r, g, b, a;
    F139Color(float, float, float, float);
};
struct F139Fx
{
    void FUN_00803a70(int);
    void FUN_00821620(float);
    void FUN_00507780(float);
    void SetBoltSmallWidth(float);
    void SetBoltGrowWidth(float);
    void SetArg(F139Color);
    void SetData(F139Color);
    void FUN_00803b30(float);
    void SetWhich(int);
    void FUN_005077a0(float);
    void FUN_00803b50(float);
    void FUN_00803a50(bool);
    void FUN_00bc2360();
};
struct F139Setting
{
    int* FUN_0043d4d0();
    float* FUN_00403e20();
};
extern "C" char DAT_011d1a48, DAT_011d168c, DAT_011d17a0, DAT_011d16b0, DAT_011d1b50, DAT_011d18c0, DAT_011d1974;
struct F139Ptr
{
    void* p;
    void FUN_0066b0d0(void*);
};
struct F139Entry
{
    F139Ptr fx, node;
    F139Vec pos;
    F139Ptr source, target;
    F139Entry* next;
    F139Entry();
};
struct F139NewNode : F139Node
{
    char data[0xa8];
    F139NewNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
__forceinline void* F139NewNode::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void F139NewNode::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
F139Fx* __cdecl FUN_00bc18d0(F139NewNode*, int);
struct F139Arg
{
    F139Ref* FUN_0084e3a0();
};
struct F139This
{
    char pad[0xb0];
    F139Entry* entries;
    char pad2[0x10];
    F139Ref* ref;
    F139Ref* FUN_00586150();
    F139Cell* FUN_008d6f30();
    F139Result* FUN_009306d0();
    void FUN_00812700(float, F139Entry*);
    void AttachEffectToSpine(F139Owner*, F139Arg*);
};
// @fnv 0x008139f0
void F139This::AttachEffectToSpine(F139Owner* owner, F139Arg* arg)
{
    if (arg && (arg->FUN_0084e3a0() != FUN_00586150() || ref == owner->v1()))
        return;
    F139NewNode* s = new F139NewNode(0);
    F139Node* a = FUN_008d6f30()->FUN_005497a0();
    a->attach(s, true);
    F139Fx* h = FUN_00bc18d0(s, 0);
    if (h)
    {
        h->FUN_00803a70(*((F139Setting*)&DAT_011d1a48)->FUN_0043d4d0());
        h->FUN_00821620(*((F139Setting*)&DAT_011d168c)->FUN_00403e20());
        h->FUN_00507780(*((F139Setting*)&DAT_011d17a0)->FUN_00403e20());
        h->SetBoltSmallWidth(*((F139Setting*)&DAT_011d1610)->FUN_00403e20());
        h->SetBoltGrowWidth(*((F139Setting*)&DAT_011d1b2c)->FUN_00403e20());
        h->SetArg(F139Color(*((F139Setting*)&DAT_011d1be0)->FUN_00403e20(),
                            *((F139Setting*)&DAT_011d1908)->FUN_00403e20(),
                            *((F139Setting*)&DAT_011d18f0)->FUN_00403e20(), 1.0f));
        h->SetData(F139Color(*((F139Setting*)&DAT_011d1c4c)->FUN_00403e20(),
                             *((F139Setting*)&DAT_011d19d8)->FUN_00403e20(),
                             *((F139Setting*)&DAT_011d1cdc)->FUN_00403e20(), 1.0f));
        h->FUN_00803b30(*((F139Setting*)&DAT_011d16b0)->FUN_00403e20());
        h->SetWhich(*((F139Setting*)&DAT_011d1b50)->FUN_0043d4d0());
        h->FUN_005077a0(*((F139Setting*)&DAT_011d18c0)->FUN_00403e20());
        h->FUN_00803b50(*((F139Setting*)&DAT_011d1974)->FUN_00403e20());
        h->FUN_00803a50(false);
        h->FUN_00bc2360();
    }
    F139Vec i;
    i.FUN_006815c0();
    FUN_009306d0()->FUN_00812b00(&i);
    F139Node* p = 0;
    F139Node* f = ref ? ref->node() : 0;
    if (f)
        p = f->find(NiFixedString("Bip01 Spine2"));
    F139Node* eb = 0;
    f = owner->v1()->node();
    if (f)
    {
        eb = f->find(NiFixedString("Bip01 Spine2"));
        if (!eb)
            eb = f;
    }
    else
        return;
    F139Entry* cf = new F139Entry;
    cf->fx.FUN_0066b0d0(h);
    cf->node.FUN_0066b0d0(s);
    cf->source.FUN_0066b0d0(p);
    cf->target.FUN_0066b0d0(eb);
    cf->pos = i;
    cf->next = entries;
    FUN_00812700(0.0f, cf);
    entries = cf;
}

struct FUN_00812170
{
    virtual ~FUN_00812170();
};
// @fnv 0x00812170
FUN_00812170::~FUN_00812170()
{}
