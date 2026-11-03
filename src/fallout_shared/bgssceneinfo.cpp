
// src/fallout_shared/bgssceneinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgssceneinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_004a7cf0_shell
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;

    int GetValueAt(int index);
};

// @fnv 0x004a7cf0
int FUN_004a7cf0_shell::GetValueAt(int index)
{
    if (index >= 0 && index < 16)
    {
        return *(reinterpret_cast<int*>(this) + index + 1);
    }
    return 0;
}

struct Flt
{
    operator unsigned int() const;
};

struct Script
{
    int GetText();
};

struct FUN_004a8070_shell
{
    int GetScriptText();
};

// Calls GetText on the Script pointer stored at offset 0xb8 of this object and returns the result.
// @fnv 0x004a8070
int FUN_004a8070_shell::GetScriptText()
{
    return ((Script*)((unsigned int)(*(Flt*)((char*)this + 0xb8))))->GetText();
}

extern unsigned char DAT_0118868c;

// @fnv 0x004a82c0
unsigned char __cdecl FUN_004a82c0()
{
    return DAT_0118868c;
}

// Returns the smaller of the two integer arguments.
// @fnv 0x004a8f20
int __cdecl MinInt(int iA, int iB)
{
    int result;
    if (iA < iB)
        result = iA;
    else
        result = iB;
    return result;
}

struct FUN_004a8f50_shell
{
    void FUN_004a95d0(int a);
    void* FUN_004a8f50();
};

// @fnv 0x004a8f50
void* __thiscall FUN_004a8f50_shell::FUN_004a8f50()
{
    ((FUN_004a8f50_shell*)((char*)this + 4))->FUN_004a95d0(0x25);
    return this;
}

struct GlobalObject2_0040c150
{
    int* Int();
};

struct GlobalObject2_0045cfe0
{
    int* Int();
};

GlobalObject2_0045cfe0 g_011c59e0;

// @fnv 0x004a9100
int FUN_004a9100()
{
    return *g_011c59e0.Int();
}

struct DummyArr
{
    int GetBufferElementAddress(unsigned int);
    int FUN_004a95b0(unsigned int);
};

// @fnv 0x004a95b0
int DummyArr::FUN_004a95b0(unsigned int a)
{
    return GetBufferElementAddress(a);
}

struct FUN_004a9630_shell
{
    void* FUN_004a9630(unsigned int flags);
};

struct FUN_004a9850_shell
{
    void FUN_004a9850();
};

void __cdecl _Deallocate(void* p);

// @fnv 0x004a9630
void* FUN_004a9630_shell::FUN_004a9630(unsigned int flags)
{
    ((FUN_004a9850_shell*)this)->FUN_004a9850();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0101ec68;
void* __cdecl memset(void*, int, unsigned int);

struct FUN_004a7c40_shell
{
    void* FUN_004a7c40();
    void ClearToZero();
};

// @fnv 0x004a7c40
void* FUN_004a7c40_shell::FUN_004a7c40()
{
    *(int*)this = (int)&DAT_0101ec68;
    ((FUN_004a7c40_shell*)((char*)this + 4))->ClearToZero();
    memset((char*)this + 4, 0, 0x40);
    *(int*)((char*)this + 0x44) = 0;
    return this;
}

void* __cdecl memset(void* dest, int c, unsigned int n);

struct FUN_004a7c80_shell
{
    void* ClearToZero();
};

// @fnv 0x004a7c80
void* FUN_004a7c80_shell::ClearToZero()
{
    memset(this, 0, 0x40);
    return this;
}

struct BGSSceneInfo_shell
{
    void* Destroy(unsigned int flags);
    void FUN_004a7cd0();
};
// Calls FUN_004a7cd0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004a7ca0
void* BGSSceneInfo_shell::Destroy(unsigned int flags)
{
    FUN_004a7cd0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0101ec68;

struct FUN_004a7cd0_shell
{
    int* m_0000;
    void FUN_004a7cd0();
};

// @fnv 0x004a7cd0
void FUN_004a7cd0_shell::FUN_004a7cd0()
{
    m_0000 = &DAT_0101ec68;
}

struct BSThread
{
    unsigned int GetThreadID();
};
struct FUN_004a8030_shell
{
    unsigned int FUN_004a8030();
};
// Returns the thread ID of the BSThread stored at offset 0xb8 of this object.
// @fnv 0x004a8030
unsigned int FUN_004a8030_shell::FUN_004a8030()
{
    return ((BSThread*)((Flt*)((char*)this + 0xb8))->operator unsigned int())->GetThreadID();
}

struct Proc_S
{
    void* GetNext();
};
struct This_004a8050
{
    void* GetNextProc();
};
// Returns the result of GetNext() on the Proc_S pointer stored at offset 0xB8 of this object.
// @fnv 0x004a8050
void* This_004a8050::GetNextProc()
{
    return ((Proc_S*)(unsigned int)*(Flt*)((char*)this + 0xB8))->GetNext();
}

extern int DAT_0101ecec;
struct FUN_004a95d0_shell
{
    void* FUN_004a95d0(int a);
    void FUN_004a97e0(int a);
};

// Calls FUN_004a97e0(a), stores the address of DAT_0101ecec into this, and returns this.
// @fnv 0x004a95d0
void* FUN_004a95d0_shell::FUN_004a95d0(int a)
{
    FUN_004a97e0(a);
    *(int*)this = (int)&DAT_0101ecec;
    return this;
}

extern int DAT_0101ed0c;

struct FUN_004a9600_shell
{
    int m_0000;
    void* FUN_004a9600(void* arg);
    void __thiscall FUN_004a98e0(void* arg);
};

// Calls FUN_004a98e0 on arg, stores the address of DAT_0101ed0c in m_0000, and returns this.
// @fnv 0x004a9600
void* FUN_004a9600_shell::FUN_004a9600(void* arg)
{
    FUN_004a98e0(arg);
    m_0000 = (int)&DAT_0101ed0c;
    return this;
}

struct FUN_004a9970_shell
{
    void FUN_004a9970();
    void* FUN_004a9660(unsigned int flags);
};

// Calls FUN_004a9970, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x004a9660
void* FUN_004a9970_shell::FUN_004a9660(unsigned int flags)
{
    FUN_004a9970();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Target
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
};
struct FUN_004a8090_shell
{
    char _pad[0xB8];
    Flt m_kHandle;
    int CallTargetV36();
};
// @fnv 0x004a8090
int FUN_004a8090_shell::CallTargetV36()
{
    return ((Target*)(unsigned int)m_kHandle)->v36();
}

struct INISettingCollection
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05(unsigned int a);
};
struct SettingT
{
    static INISettingCollection* __cdecl GetCollection();
};

// @fnv 0x004a8fe0
void __cdecl FUN_004a8fe0()
{
    int i;
    for (i = 0; i < 0x10; ++i)
    {
        SettingT::GetCollection()->v05(*(unsigned int*)(0x01188694 + i * 0x14));
        SettingT::GetCollection()->v05(*(unsigned int*)(0x01188698 + i * 0x14));
    }
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
struct TESWorldSpace
{
    TESWorldSpace* GetParentWorld(int);
};
struct CP_008c48d0
{
    int GetPrevPath();
};
struct TESSaveLoadGame
{
    TESWorldSpace* GetHitSound();
};
struct _ref_0084e3a0
{
    int FUN_0084e3a0();
};
extern GlobalObject_0045cfe0 g_011c5b20;
extern GlobalObject_0045cfe0 g_011c5ae0;
extern GlobalObject2_0045cfe0 g_011c5c04;
extern int g_TES;
// @fnv 0x004a9050
int FUN_004a9050()
{
    int iValue = *g_011c5b20.Int();
    if (!((CP_008c48d0*)g_TES)->GetPrevPath())
    {
        TESWorldSpace* pworld = ((TESSaveLoadGame*)g_TES)->GetHitSound();
        TESWorldSpace* pLODworld;
        pLODworld = pworld;
        while (pLODworld && pLODworld->GetParentWorld(1))
            pLODworld = pLODworld->GetParentWorld(1);
        if (pLODworld)
        {
            int iadjust = 0;
            if (((_ref_0084e3a0*)pLODworld)->FUN_0084e3a0() == 0x3c)
                iadjust = *g_011c5ae0.Int();
            else
                iadjust = *g_011c5c04.Int();
            iValue -= iadjust;
        }
    }
    return iValue;
}

struct NiNode;

struct GlobalObject_004a9e90
{
    void RemoveAll();
};

struct GlobalObject_004aa1b0
{
    void RemoveAll();
};

struct GlobalObject_004a9d80
{
    unsigned int GetFlags();
};

struct GlobalObject_004a9bf0
{
    void RemoveAll();
};

extern GlobalObject_004a9e90 g_011c5be8;
extern GlobalObject_004aa1b0 g_011c5ad0;
extern GlobalObject_004a9d80 g_011c5ab4;
extern GlobalObject_004a9bf0 g_011c5c40;
extern unsigned char DAT_0118868d;

struct FUN_004a8230_shell
{
    void LoadSceneModels();
    void AccumulateSceneStatistics(NiNode* node, void* data, bool trackActors, bool extra);
    void ResetAndProcessNode(NiNode* node, bool includeAddonNodes, bool trackActors);
};

// @fnv 0x004a8230
void FUN_004a8230_shell::ResetAndProcessNode(NiNode* node, bool includeAddonNodes, bool trackActors)
{
    g_011c5be8.RemoveAll();
    g_011c5ad0.RemoveAll();

    if (includeAddonNodes && DAT_0118868d && g_011c5ab4.GetFlags() == 0)
        this->LoadSceneModels();

    memset((char*)this + 4, 0, 0x40);

    this->AccumulateSceneStatistics(node, (char*)this + 4, trackActors, 0);

    if (FUN_004a82c0())
        g_011c5c40.RemoveAll();
}

struct SceneDescription
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* Name();
    const char* FUN_0048cee0();
};
struct SceneRecord
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
    SceneDescription description;
};
struct SceneInfo
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
    void ClearToZero();
};
struct SceneSource
{
    unsigned int FUN_0045a120();
    SceneRecord* FUN_004617e0(unsigned int);
};
struct SceneCache
{
    void InsertAt(unsigned int, SceneInfo*);
    void* FUN_004a95b0(unsigned int);
};
struct SceneLoader
{
    void* LoadModel(const char*, int, int, int, int, int);
    void FUN_0045a5e0(const char*);
};
extern SceneSource* DAT_011c3f2c;
extern SceneLoader* DAT_011c3b3c;
extern SceneCache DAT_011c5ab4;
extern char DAT_01016fac;
extern int DAT_011f4428;
void __cdecl FUN_00406d30(char*, unsigned int, const char*);
void __cdecl FUN_00406d50(char*, unsigned int, const char*);
void* __cdecl FUN_00653270(const void*, void*);
bool __cdecl FUN_00c511f0(void*);
struct LoadScenes
{
    void AccumulateSceneStatistics(void*, void*, int, int);
    void LoadSceneModels();
};
// Iterates all scenes, fills a SceneInfo per index, builds a model path from the scene description name, loads it, and registers it unless already loaded.
// @fnv 0x004a80c0
void LoadScenes::LoadSceneModels()
{
    unsigned int count = DAT_011c3f2c->FUN_0045a120();
    for (unsigned int uiSceneIndex = 0; uiSceneIndex < count; ++uiSceneIndex)
    {
        SceneInfo sceneInfo;
        sceneInfo.ClearToZero();
        DAT_011c5ab4.InsertAt(uiSceneIndex, &sceneInfo);
        SceneRecord* pSceneRecord = DAT_011c3f2c->FUN_004617e0(uiSceneIndex);
        if (pSceneRecord)
        {
            bool loaded = false;
            if (pSceneRecord->description.FUN_0048cee0())
            {
                char cPath[260];
                FUN_00406d30(cPath, 260, &DAT_01016fac);
                FUN_00406d50(cPath, 260, pSceneRecord->description.Name());
                void* model = DAT_011c3b3c->LoadModel(cPath, 0, 1, 0, 0, 0);
                if (model)
                {
                    if (!FUN_00c511f0(model))
                        AccumulateSceneStatistics(FUN_00653270(&DAT_011f4428, model),
                                                  DAT_011c5ab4.FUN_004a95b0(uiSceneIndex), 0, 0);
                    DAT_011c3b3c->FUN_0045a5e0(cPath);
                }
            }
        }
    }
}

struct SearchRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct S5460
{
    bool FUN_00438b90();
    unsigned int FUN_009a3910();
};
struct NavMeshSearchLOSArray
{
    virtual void v0();
    virtual SearchRecord* Allocate(unsigned int);
    SearchRecord* data;
    unsigned int count, capacity;
    void AddEntry(const SearchRecord&);
    void CopyBlocks(SearchRecord*, SearchRecord*, unsigned int);
    void ConstructScanItems(SearchRecord*, unsigned int);
    void FUN_006a8500();
    void InsertAt(unsigned int, const SearchRecord&);
};
// @fnv 0x004a9690
void NavMeshSearchLOSArray::InsertAt(unsigned int index, const SearchRecord& value)
{
    if (index == count)
    {
        AddEntry(value);
        return;
    }
    if (((S5460*)this)->FUN_00438b90())
    {
        unsigned int fresh = ((S5460*)this)->FUN_009a3910();
        SearchRecord* newCapacity = Allocate(fresh);
        CopyBlocks(newCapacity, data, index);
        ConstructScanItems(newCapacity + index, 1);
        CopyBlocks(newCapacity + index + 1, data + index, count - index);
        FUN_006a8500();
        data = newCapacity;
        capacity = fresh;
    }
    else
    {
        CopyBlocks(data + index + 1, data + index, count - index);
        ConstructScanItems(data + index, 1);
    }
    count = count + 1;
    data[index] = value;
}

struct SceneOwner;
struct SceneItem
{
    SceneOwner* FUN_008d6f30();
};
struct ItemList
{
    void* FUN_00559450();
    void* DereferenceIfNotNull(void*);
    SceneItem** AddEight(void*);
};
struct OuterRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ItemList items;
};
struct OuterList
{
    void* FUN_00559450();
    void* DereferenceIfNotNull(void*);
    OuterRecord** AddEight(void*);
};
struct SceneManager
{
    OuterList* FUN_005a8080();
};
struct SceneGlobal
{
    SceneManager* FUN_0070ec90();
};
extern SceneGlobal* DAT_011dea10;
struct FUN_004a9600
{
    int unk00, unk04, unk08, unk0c;
    FUN_004a9600(unsigned int);
    ~FUN_004a9600();
    bool FUN_0057c850(SceneOwner*, bool*);
    void FUN_0084d310(SceneOwner*, int);
    void FUN_00438af0();
};
struct FUN_0042f4e0
{
    int unk00, unk04, unk08, unk0c;
    FUN_0042f4e0(unsigned int);
    ~FUN_0042f4e0();
    bool FUN_0057c850(SceneItem*, bool*);
    void FUN_0084d310(SceneItem*, int);
    void FUN_00438af0();
};
struct ScriptProgram
{
    unsigned short CallTargetV36();
    int FUN_0049ec60();
    int GetNextProc();
    int FUN_004a8030();
    int GetScriptText();
};
struct MeshPart
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual ScriptProgram* v7();
};
struct MeshGroup
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    MeshPart* FUN_0043b4a0(int);
};
struct MeshObject
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
    virtual MeshGroup* v116();
};
struct MeshNode
{
    MeshObject** FUN_006815c0();
    MeshNode* FUN_00726070();
};
struct SceneOwner
{
    MeshNode* FUN_00545710();
};
struct SceneCounter
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int count;
    int unk28, unk2c;
    int bytes;
    void AccumulateSceneStats(SceneOwner* owner);
};
// Walks the scene's outer and item lists counting items owned by owner, then walks the owner's mesh nodes summing per-part byte sizes into bytes.
// @fnv 0x004a7d20
void SceneCounter::AccumulateSceneStats(SceneOwner* owner)
{
    OuterList* j = DAT_011dea10->FUN_0070ec90()->FUN_005a8080();
    FUN_004a9600 e(0x25);
    FUN_0042f4e0 k(0x25);
    void* ba = j->FUN_00559450();
    void* l = 0;
    while (ba)
    {
        l = j->DereferenceIfNotNull(ba);
        if (ba)
        {
            OuterRecord* q = *j->AddEight(ba);
            if (q)
            {
                int eb = 0;
                void* s = q->items.FUN_00559450();
                void* cf = 0;
                bool f = false;
                while (s)
                {
                    cf = q->items.DereferenceIfNotNull(s);
                    SceneItem* i = *q->items.AddEight(s);
                    if (!e.FUN_0057c850(i->FUN_008d6f30(), &f))
                        ++eb;
                    if (!k.FUN_0057c850(i, &f) && i->FUN_008d6f30() == owner)
                    {
                        ++this->count;
                        k.FUN_0084d310(i, 1);
                    }
                    e.FUN_0084d310(i->FUN_008d6f30(), 1);
                    s = cf;
                }
                if (e.FUN_0057c850(owner, &f))
                {
                    int a = 0;
                }
            }
        }
        e.FUN_00438af0();
        ba = l;
    }
    MeshNode* c = owner->FUN_00545710();
    while (c && *c->FUN_006815c0())
    {
        MeshObject* h = *c->FUN_006815c0();
        MeshGroup* p = h->v116();
        if (p && p->v4())
        {
            MeshPart* h2 = p->FUN_0043b4a0(0);
            ScriptProgram* b = h2->v7();
            if (b)
            {
                int e2 = 0;
                unsigned int j2 = b->CallTargetV36();
                if (b->FUN_0049ec60())
                    e2 += j2 * 12;
                if (b->GetNextProc())
                    e2 += j2 * 16;
                if (b->FUN_004a8030())
                    e2 += j2 * 12;
                if (b->GetScriptText())
                    e2 += j2 * 8;
                this->bytes += e2;
            }
        }
        c = c->FUN_00726070();
    }
    k.FUN_00438af0();
}

namespace fnv_004a82d0 {
struct StatsBase;
struct SceneName
{
    const char* FUN_0043b1b0();
};
struct StatObject;
struct StatForm
{
    int FUN_00401170();
    int FUN_0084e3a0();
};
struct StatLink
{
    StatForm* FUN_0041f050();
};
struct StatNodeLink
{
    int* FUN_006815c0();
    StatNodeLink* FUN_00726070();
};
struct StatKey
{
    StatForm* FUN_00559450();
};
struct StatKeyHolder
{
    StatKey* GetSourceFilesFromObject();
};
struct StatRef
{
    bool FUN_00444ed0();
    StatForm* FUN_007af430();
    StatLink* FUN_005d43c0();
};
struct StatActor
{
    StatKeyHolder* FUN_006fa820();
};
struct StatExtra
{
    int FUN_009ee040();
};
struct StatMap
{
    int FUN_0044ddc0();
    int* FUN_004a95b0(int);
};
struct StatUnique
{
    bool FUN_005f65d0(const int&);
    void FUN_00905820(const int&);
};
struct StatTextureSet
{
    void GetAt(void*, int*);
    void FUN_00844700(void*, int);
};
struct StatTextureCount
{
    int* FUN_0043d4d0();
};
struct StatGeom
{
    unsigned short FUN_00b70790();
    void* FUN_00b70590(void**);
    void* FUN_00b70680(void**);
};
struct ScriptExecutionContext
{
    unsigned short FUN_004a1ff0();
    unsigned short CallTargetV36();
    void* FUN_0049ec60();
    void* GetNextProc();
    void* FUN_004a8030();
    void* GetScriptText();
};
struct StatBlocks
{
    unsigned int FUN_00a727b0();
    void GetItemData(unsigned int, unsigned int*);
};
struct StatSkin
{
    StatBlocks* FUN_004a8a90();
};
struct StatProperty;
struct StatObject
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual StatObject* AsNode();
    virtual void* AsFade();
    virtual void Slot05();
    virtual StatObject* AsGeometry();
    virtual ScriptExecutionContext* GetData();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Visit(void(__cdecl*)(void*, void*), int**);
    SceneName* FUN_00413f40();
    StatRef* FUN_009ad610();
    unsigned int FUN_0043b480();
    StatObject* FUN_0043b4a0(unsigned int);
    void* FUN_00a59d30(int);
    int FUN_00441110();
    bool FUN_004a2020(int);
    StatSkin* FUN_005495f0();
    int FUN_00b5b4a0(void*);
    unsigned short GetActorBaseFatigue();
};
struct StatDetector
{
    void ClearQueuedFile();
};
extern StatDetector* DAT_011dea10;

extern StatUnique DAT_011c5b30;

extern StatTextureCount DAT_011c5a90;
extern char DAT_01202de8, DAT_011c7d34, DAT_011f4a28, DAT_012024e0;
bool __cdecl FUN_0043b300(const void*, const void*);
void* __cdecl FUN_00653270(const void*, const void*);
bool __cdecl FUN_00565580(StatObject*);
StatActor* __cdecl FUN_004a8b00(StatObject*);
int __cdecl FUN_004a9240(StatForm*);
StatObject* __cdecl FUN_00450b80(int);
void __cdecl AddToRefCountIfNotFlagged(void*, void*);
int __cdecl strncmp(const char*, const char*, unsigned int);
struct SceneStatistics
{
    int unk00;
    int counters[16];
    void AccumulateSceneStatistics(StatObject* object, int* output, bool trackActors, StatObject* parent);
};
// Walks the scene object tree and accumulates per-category counts into output or counters, then calls DAT_011dea10->ClearQueuedFile().
// @fnv 0x004a82d0
void SceneStatistics::AccumulateSceneStatistics(StatObject* object, int* output, bool trackActors, StatObject* parent)
{
    int* counts;
    if (output)
        counts = output;
    else
        counts = counters;
    if (object)
    {
        bool addon = false;
        bool actorNode = false;
        StatObject* node3 = object->AsNode();
        if (node3)
        {
            if (node3->FUN_00413f40()->FUN_0043b1b0() &&
                !strncmp(node3->FUN_00413f40()->FUN_0043b1b0(), "FurnitureMarker", 15))
                return;
            if (FUN_0043b300(&DAT_01202de8, node3))
            {
                StatExtra* extra = (StatExtra*)FUN_00653270(&DAT_01202de8, node3);
                int index = extra->FUN_009ee040();
                if (index >= 0 && index < (int)DAT_011c3f2c->FUN_0045a120() &&
                    index < ((StatMap*)&g_011c5ab4)->FUN_0044ddc0())
                {
                    for (int i = 0; i < 16; i++)
                    {
                        switch (i)
                        {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            break;
                        default:
                            counts[i] += ((StatMap*)&g_011c5ab4)->FUN_004a95b0(index)[i];
                            break;
                        }
                    }
                }
            }
            bool isActor2 = false;
            StatRef* reference = 0;
            StatObject* fade = 0;
            if (node3->AsFade())
                fade = node3;
            if (fade && (reference = fade->FUN_009ad610()) && !reference->FUN_00444ed0() && (!actorNode || !addon))
            {
                counts[0]++;
                if (FUN_00565580(object))
                {
                    counts[2]++;
                    if (!DAT_011c5b30.FUN_005f65d0(reference->FUN_007af430()->FUN_0084e3a0()))
                    {
                        counts[3]++;
                        DAT_011c5b30.FUN_00905820(reference->FUN_007af430()->FUN_0084e3a0());
                    }
                }
                StatNodeLink* link = (StatNodeLink*)reference->FUN_005d43c0()->FUN_0041f050();
                while (link && *link->FUN_006815c0())
                {
                    counts[14]++;
                    link = link->FUN_00726070();
                }
                switch (reference->FUN_007af430()->FUN_00401170())
                {
                case 42:
                case 43:
                case 44:
                case 45:
                    counts[1]++;
                    isActor2 = true;
                    break;
                }
                StatActor* actor = FUN_004a8b00(object);
                if (actor)
                {
                    StatKeyHolder* holder = actor->FUN_006fa820();
                    StatKey* key = holder ? holder->GetSourceFilesFromObject() : 0;
                    StatForm* form1 = key ? key->FUN_00559450() : 0;
                    if (form1)
                        counts[15] += FUN_004a9240(form1);
                }
            }
            if (isActor2 && !trackActors)
                return;
            if (!actorNode || !addon)
            {
                unsigned int childCount = node3->FUN_0043b480();
                for (unsigned int child = 0; child < childCount; child++)
                {
                    StatObject* next = node3->FUN_0043b4a0(child);
                    AccumulateSceneStatistics(next, output, false, node3);
                }
            }
        }
        else
        {
            StatObject* geometry = object->AsGeometry();
            if (geometry)
            {
                bool addonGeometry = false;
                bool actorGeometry = false;
                if (!actorGeometry || !addonGeometry)
                {
                    counts[6]++;
                    StatObject* property = (StatObject*)geometry->FUN_00a59d30(3);
                    StatObject* textureProperty1 = !property ? 0 : property->FUN_00441110() != -1 ? property : 0;
                    if (textureProperty1)
                    {
                        int* textureCount = &counts[10];
                        textureProperty1->Visit(AddToRefCountIfNotFlagged, &textureCount);
                        if ((parent && FUN_0043b300(&DAT_011c7d34, parent)) || textureProperty1->FUN_004a2020(26) ||
                            textureProperty1->FUN_004a2020(27))
                            counts[14]++;
                    }
                    StatGeom* shader1 =
                        (StatGeom*)((!property
                                         ? 0
                                         : (property->FUN_00441110() >= 8 && property->FUN_00441110() <= 12 ? 1 : 0))
                                        ? property
                                        : 0);
                    if (shader1)
                    {
                        int textureSlots = shader1->FUN_00b70790();
                        void* position1;
                        void* texture1 = shader1->FUN_00b70590(&position1);
                        while (texture1)
                        {
                            int uses = 0;
                            ((StatTextureSet*)&g_011c5ad0)->GetAt(texture1, &uses);
                            uses++;
                            ((StatTextureSet*)&g_011c5ad0)->FUN_00844700(texture1, uses);
                            if (uses == *DAT_011c5a90.FUN_0043d4d0())
                                counts[13]++;
                            texture1 = shader1->FUN_00b70680(&position1);
                        }
                    }
                    ScriptExecutionContext* data = geometry->GetData();
                    if (data)
                    {
                        counts[7] += data->FUN_004a1ff0();
                        int bytes = 0;
                        int vertices = data->CallTargetV36();
                        if (data->FUN_0049ec60())
                            bytes += vertices * 12;
                        if (data->GetNextProc())
                            bytes += vertices * 16;
                        if (data->FUN_004a8030())
                            bytes += vertices * 12;
                        if (data->GetScriptText())
                            bytes += vertices * 8;
                        counts[9] += bytes;
                    }
                    if (geometry->FUN_005495f0())
                    {
                        StatBlocks* blocks = geometry->FUN_005495f0()->FUN_004a8a90();
                        for (unsigned int block = 0; blocks && block < blocks->FUN_00a727b0(); block++)
                        {
                            unsigned int blockBytes = 0;
                            blocks->GetItemData(block, &blockBytes);
                            counts[9] += blockBytes;
                        }
                    }
                }
            }
            else
            {
                StatObject* particle = (StatObject*)FUN_00653270(&DAT_011f4a28, object);
                if (particle)
                {
                    StatObject* manager = FUN_00450b80(0);
                    if (manager && manager->FUN_00b5b4a0(particle))
                        counts[12]++;
                }
            }
            StatObject* lines1 = (StatObject*)FUN_00653270(&DAT_012024e0, object);
            if (lines1)
            {
                counts[5]++;
                counts[4] += lines1->GetActorBaseFatigue();
            }
        }
    }
    DAT_011dea10->ClearQueuedFile();
}
}  // namespace fnv_004a82d0

namespace fnv_004a8bb0 {
struct Cell245
{
    NiNode* FUN_00545cb0();
};
struct FUN_004a7c40
{
    virtual ~FUN_004a7c40();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44;
    FUN_004a7c40();
    void SetDifficultyLevel(Cell245*);
    void ResetAndProcessNode(NiNode*, bool, bool);
    void AccumulateSceneStats(Cell245*);
    unsigned int GetValueAt(int);
    float GetScaledSlotValue(int);
};
struct FUN_004aa340
{
    int unk00, unk04, unk08, unk0c, unk10;
    FUN_004aa340();
    ~FUN_004aa340();
    void SetValueAndCall(NiNode*, Cell245*, int);
    unsigned int FUN_004aa890();
};
struct GlobalObject2_0096a2d0
{
    FUN_004a7c40* data;
    void* next;
    GlobalObject2_0096a2d0();
    ~GlobalObject2_0096a2d0();
    void FUN_005ae3d0(FUN_004a7c40*&);
    bool _ref_008256d0();
    FUN_004a7c40*& _ref_006815c0();
    void FUN_0063f7b0();
};
struct TES245
{
    Cell245* GetInteriorCell();
    Cell245** FUN_00457050(unsigned int, unsigned int);
};
extern TES245* DAT_011dea10;
extern GlobalObject2_0045cfe0 DAT_011c63cc;
struct Cost245
{
    bool disabled;
    int unk04, unk08, unk0c, unk10;
};
extern Cost245 DAT_011886a0[16];
struct Clear245
{
    void FUN_00438af0();
};
extern Clear245 DAT_011c5c40;
void* __cdecl operator new(unsigned int);
// Accumulates cost and count over the interior cell or nearby exterior cells, adding the list total when include is set, then calls FUN_00438af0.
// @fnv 0x004a8bb0
void __cdecl FUN_004a8bb0(float* cost, float* count, bool include, bool addons)
{
    *cost = 0.0f;
    *count = 0.0f;
    FUN_004a8fe0();
    FUN_004aa340 list;
    GlobalObject2_0096a2d0 map;
    if (DAT_011dea10->GetInteriorCell())
    {
        Cell245* cell = DAT_011dea10->GetInteriorCell();
        FUN_004a7c40* scene = new FUN_004a7c40;
        scene->SetDifficultyLevel(cell);
        scene->ResetAndProcessNode(cell->FUN_00545cb0(), addons, false);
        scene->AccumulateSceneStats(cell);
        list.SetValueAndCall(cell->FUN_00545cb0(), cell, 0);
        map.FUN_005ae3d0(scene);
    }
    else
    {
        unsigned int last = *(unsigned int*)DAT_011c63cc.Int() >> 1;
        unsigned int center = last - MinInt(last, 2);
        unsigned int first = last + MinInt(last, 2);
        for (unsigned int x = center; x <= first; x++)
        {
            for (unsigned int y = center; y <= first; y++)
            {
                Cell245** entry = DAT_011dea10->FUN_00457050(x, y);
                if (*entry)
                {
                    Cell245* scene2 = *entry;
                    FUN_004a7c40* cell2 = new FUN_004a7c40;
                    cell2->SetDifficultyLevel(scene2);
                    cell2->ResetAndProcessNode(scene2->FUN_00545cb0(), addons, false);
                    list.SetValueAndCall(scene2->FUN_00545cb0(), scene2, 0);
                    cell2->AccumulateSceneStats(scene2);
                    map.FUN_005ae3d0(cell2);
                }
            }
        }
    }
    while (!map._ref_008256d0())
    {
        FUN_004a7c40* current = map._ref_006815c0();
        map.FUN_0063f7b0();
        *count += current->GetValueAt(9);
        for (int i = 0; i < 16; i++)
        {
            if (!DAT_011886a0[i].disabled)
                *cost += current->GetScaledSlotValue(i);
        }
        delete current;
    }
    if (include)
        *count += list.FUN_004aa890();
    DAT_011c5c40.FUN_00438af0();
}
}  // namespace fnv_004a8bb0

// Return the skill-scaled value for a slot: the slot's integer value times its game-setting multiplier.

class A8F70Setting
{
  public:
    float* GetFloat();
};

struct A8F70SlotInfo
{
    A8F70Setting* m_pkMultiplier;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

extern A8F70SlotInfo g_akA8F70Slots[];

class A8F70Owner
{
  public:
    unsigned int GetSlotValue(int iSlot);
    float GetScaledSlotValue(int iSlot);
};

// Returns the slot value multiplied by the slot's multiplier float, or 0.0f if the slot index is out of range or has no multiplier.
// @fnv 0x004a8f70
float A8F70Owner::GetScaledSlotValue(int iSlot)
{
    if (iSlot >= 0 && iSlot < 16 && g_akA8F70Slots[iSlot].m_pkMultiplier)
        return (float)((double)GetSlotValue(iSlot) * *g_akA8F70Slots[iSlot].m_pkMultiplier->GetFloat());
    return 0.0f;
}

int FUN_004a9100();
int FUN_004a9050();
int __cdecl FormatString(char* buffer, const char* format, ...);

// @fnv 0x004a9120
void __cdecl FUN_004a9120(float fUsed, char* buffer, bool abUseFirstTotal)
{
    float fTotal = abUseFirstTotal ? (float)(unsigned int)FUN_004a9100() : (float)(unsigned int)FUN_004a9050();
    float fPercent2 = fUsed * 100.0 / fTotal;
    fTotal = fTotal / 1048576.0;
    if (fUsed > 1048576.0)
    {
        fUsed = fUsed / 1048576.0;
        FormatString(buffer, "%.2f%% (%.2f MB / %.2f MB)", fPercent2, fUsed, fTotal);
    }
    else if (fUsed > 1024.0)
    {
        fUsed = fUsed / 1024.0;
        FormatString(buffer, "%.2f%% (%.2f KB / %.2f MB)", fPercent2, fUsed, fTotal);
    }
    else
    {
        FormatString(buffer, "%.2f%% (%.0f bytes / %.2f MB)", fPercent2, fUsed, fTotal);
    }
}

template <class A, class B> struct NiTPointerMap
{
    virtual ~NiTPointerMap();
    void RemoveAll();
};
struct FUN_004a99d0 : NiTPointerMap<unsigned int, unsigned int>
{
    ~FUN_004a99d0();
};
struct FUN_004a9970 : FUN_004a99d0
{
    ~FUN_004a9970();
};
// Destructor that calls RemoveAll to clear all entries in the pointer map.
// @fnv 0x004a9970
FUN_004a9970::~FUN_004a9970()
{
    RemoveAll();
}
