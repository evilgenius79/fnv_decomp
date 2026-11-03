
// src/fallout/ai/combat/muzzleflash.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/muzzleflash.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSProjectile
{
    bool GetFlag(unsigned int) const;
};

struct FUN_009baf30_shell : BGSProjectile
{
    bool HasFlag8() const;
};

// @fnv 0x009baf30
bool FUN_009baf30_shell::HasFlag8() const
{
    return GetFlag(8);
}

void __cdecl Deallocate(void*);
struct FUN_009badc0_shell
{
    void FUN_009badc0();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009badc0, then if flags has bit 1 set calls Deallocate on this, and returns this.
// @fnv 0x008d9f70
void* FUN_009badc0_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_009badc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct BSMultiBoundRoom
{
    void* FUN_006ab360();
};
struct FUN_009baee0_owner
{
    char _pad[0x14];
    FUN_009baf30_shell* pItem;
    void* FUN_009baee0();
};
// @fnv 0x009baee0
void* FUN_009baee0_owner::FUN_009baee0()
{
    return (pItem && pItem->HasFlag8()) ? reinterpret_cast<BSMultiBoundRoom*>(pItem)->FUN_006ab360() : 0;
}

struct PathingRequest
{
    float FUN_00507e10();
};
extern double _gModifierZero;
struct FUN_009bb690_shell
{
    unsigned char unk0;
    char pad1;
    unsigned char unk2;
    char pad3;
    float unk4;
    float unk8;
    char padC[8];
    PathingRequest* ptr14;
    void FUN_009bb690();
};
// If unk4 is at or below _gModifierZero, sets unk0 and unk2 to 1 and stores ptr14->FUN_00507e10() into unk8.
// @fnv 0x009bb690
void FUN_009bb690_shell::FUN_009bb690()
{
    if (unk4 <= _gModifierZero)
    {
        unk0 = 1;
        unk2 = 1;
        unk8 = ptr14->FUN_00507e10();
    }
}

class NiNode;
template <class T> struct NiPointer
{
    T* pointer;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
};
struct ProjectileData
{
    float FUN_00507e10();
};
struct Projectile
{
    ProjectileData* FUN_004181e0();
    unsigned int FUN_00476c90();
};
struct FUN_009bacb0
{
    unsigned char flagsA, flagsB, flagsC, state;
    float elapsed, total;
    NiPointer<NiNode> first, second;
    ProjectileData* data;
    unsigned int handle;
    void* context;
    FUN_009bacb0(Projectile*, void*);
    void UpdateNodePosition(void*);
};
// @fnv 0x009bacb0
FUN_009bacb0::FUN_009bacb0(Projectile* projectile, void* pContext) : first(0), second(0)
{
    first = 0;
    second = 0;
    data = projectile ? projectile->FUN_004181e0() : 0;
    handle = projectile ? projectile->FUN_00476c90() : 0;
    context = pContext;
    flagsA = 0;
    flagsB = 0;
    flagsC = 0;
    elapsed = 0.0f;
    total = data->FUN_00507e10();
    UpdateNodePosition(pContext);
}

struct S_009baf50_Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5();
    int FUN_0048cee0();
};
struct S_009baf50_Obj
{
    NiNode* FUN_00a5d680();
};
struct S_009baf50_Mgr
{
    S_009baf50_Obj* LoadModel(unsigned int, int, int, int, int, int);
};
extern S_009baf50_Mgr* DAT_011c3b3c;
struct S_009baf50_Vec
{
    float x, y, z;
    S_009baf50_Vec(float, int, int);
};
struct S_009baf50_Node
{
    void FUN_00a5a040();
    void FUN_00a59c60(const S_009baf50_Vec&);
};
struct S_009baf50_Ptr
{
    NiNode* raw;
    S_009baf50_Node* FUN_00559450();
};
extern float DAT_011c3c08;
extern double DAT_01090008;
void __cdecl FUN_0062bc10(S_009baf50_Node*);
void __cdecl FUN_00a6d2d0(S_009baf50_Node*);
struct S_009baf50_Self : FUN_009bacb0
{
    void* FUN_009baee0();
    void UpdateMuzzleFlash(void*);
    void UpdateLightFromChallenge();
};

// @fnv 0x009baf50
void FUN_009bacb0::UpdateNodePosition(void* arg)
{
    S_009baf50_Item* item = (S_009baf50_Item*)static_cast<S_009baf50_Self*>(this)->FUN_009baee0();
    if (item)
    {
        if (item->FUN_0048cee0())
        {
            S_009baf50_Obj* obj = DAT_011c3b3c->LoadModel(item->v5(), 0, 1, 0, 0, 0);
            if (obj)
            {
                first = obj->FUN_00a5d680();
            }
        }
    }
    if (!((S_009baf50_Ptr*)&first)->FUN_00559450())
        return;
    FUN_0062bc10(((S_009baf50_Ptr*)&first)->FUN_00559450());
    static_cast<S_009baf50_Self*>(this)->UpdateMuzzleFlash(arg);
    static_cast<S_009baf50_Self*>(this)->UpdateLightFromChallenge();
    FUN_00a6d2d0(((S_009baf50_Ptr*)&first)->FUN_00559450());
    ((S_009baf50_Ptr*)&first)->FUN_00559450()->FUN_00a5a040();
    S_009baf50_Vec pos((float)(DAT_011c3c08 - DAT_01090008), 1, 0);
    ((S_009baf50_Ptr*)&first)->FUN_00559450()->FUN_00a59c60(pos);
    pos.x = DAT_011c3c08;
    ((S_009baf50_Ptr*)&first)->FUN_00559450()->FUN_00a59c60(pos);
}

struct S_009bb080_Sub
{
    virtual void vfn0();
    virtual void vfn4();
    virtual int FUN_vfn8(int);
};
struct S_009bb080_Base0
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4c();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5c();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6c();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7c();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8c();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9c();
    virtual void vfna0();
    virtual void vfna4();
    virtual void vfna8();
    virtual void vfnac();
    virtual void vfnb0();
    virtual void vfnb4();
    virtual void vfnb8();
    virtual void vfnbc();
    virtual void vfnc0();
    virtual void vfnc4();
    virtual void vfnc8();
    virtual void vfncc();
    virtual void vfnd0();
    virtual void vfnd4();
    virtual void vfnd8();
    virtual void vfndc();
    virtual void vfne0();
    virtual void vfne4();
    virtual void vfne8();
    virtual void vfnec();
    virtual void vfnf0();
    virtual void vfnf4();
    virtual void vfnf8();
    virtual void vfnfc();
    virtual unsigned char FUN_vfn100();
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
    S_009bb080_Sub sub;
};
struct S_009bb080_Node
{
    virtual void vfn0();
    virtual void vfn4();
    virtual void vfn8();
    virtual void* FUN_vfnc();
    void FUN_00450f90(bool);
};
struct S_009bb080_Ptr
{
    S_009bb080_Node* node;
    S_009bb080_Node* FUN_00559450();
};
struct S_009bb080_Global
{
    int FUN_0044ddc0();
};
struct S_009bb080_Path
{
    float FUN_00507e10();
};
extern S_009bb080_Global DAT_011f2250;
extern double DAT_01012060;
extern float DAT_0101e2bc;
float FUN_00716440();
void __cdecl FUN_00578060(void*);
void __cdecl FUN_00578170(void*);
struct S_009bb080
{
    unsigned char unk0, unk1, unk2, unk3;
    float unk4, unk8;
    S_009bb080_Ptr unkc;
    int unk10;
    S_009bb080_Path* unk14;
    void UpdateMuzzleFlash(S_009bb080_Base0*);
    void UpdateLightVisibility();
    void FUN_009bb080(float dt, S_009bb080_Base0* proj);
};
// @fnv 0x009bb080
void S_009bb080::FUN_009bb080(float afDeltaTime, S_009bb080_Base0* proj)
{
    S_009bb080_Base0* q;
    if (!unkc.FUN_00559450())
        return;
    UpdateMuzzleFlash(proj);
    unkc.FUN_00559450()->FUN_00450f90(unk0 == 0);
    if (unk0 && !unk1)
    {
        FUN_00578060(unkc.FUN_00559450()->FUN_vfnc());
        unk1 = 1;
    }
    if (!unk0 && unk1)
    {
        FUN_00578170(unkc.FUN_00559450()->FUN_vfnc());
        unk1 = 0;
    }
    if (unk2)
        UpdateLightVisibility();
    if (DAT_011f2250.FUN_0044ddc0() == 4 && FUN_00716440() > DAT_01012060)
    {
        afDeltaTime = afDeltaTime / FUN_00716440();
    }
    else if (proj->FUN_vfn100())
    {
        q = proj;
        if (q->sub.FUN_vfn8(0x33) > 0)
            afDeltaTime = afDeltaTime / FUN_00716440();
    }
    unk4 = unk4 - afDeltaTime;
    if (unk0)
    {
        unk8 = unk8 - afDeltaTime;
        if (unk8 <= DAT_01012060)
        {
            unk8 = unk14->FUN_00507e10();
            unk4 = DAT_0101e2bc;
            unk0 = 0;
            unk2 = 1;
        }
    }
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3 FUN_004a0bd0();
    NiPoint3& FUN_00439180(float);
};
struct ThreeByThreeMatrix
{
    float m[9];
};
struct NiTransform
{
    ThreeByThreeMatrix m_rot;
    NiPoint3 m_trans;
    float m_vScale;
    NiTransform();
    ThreeByThreeMatrix FUN_004768c0();
    NiPoint3 FUN_004b4500(NiPoint3*);
    NiTransform FUN_0062c250(NiTransform*);
};
struct NiUpdateData
{
    float m_00;
    bool m_04;
    bool m_05;
    int m_08;
    NiUpdateData(float, bool, bool);
};
struct AnimCls
{
    float FUN_00453700();
};
struct FUN_009611e0_shell
{
    int FUN_009611e0();
};
struct ObjCls
{
    NiTransform* FUN_00461130();
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
    virtual void v55(void*, int);
};
struct NodeCls
{
    NiTransform* FUN_00461130();
};
struct ParamCls
{
    void* FUN_008d6f30();
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
    virtual bool v64();
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
    virtual void* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void* v131();
};
struct PlayerCls
{
    bool FUN_00524d10();
    void* FUN_00950bb0(bool);
    AnimCls* FUN_00950a60(bool);
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
    virtual void* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void* v121();
};
struct NiAVObject
{
    void FUN_00440460(NiPoint3*);
    void FUN_0043fa80(NiTransform*);
    void FUN_00440490(float);
    void FUN_00a59c60(NiUpdateData&);
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void* v3();
};
struct NiPtrC
{
    NiAVObject* FUN_00559450();
};
struct NodeSrc
{
    NodeCls* FUN_00525700(void*);
};
struct HolderCls
{
    ObjCls* FUN_005497a0();
};
struct TaskQ
{
    void QueueTaskWithTwoObjects(NiAVObject*, ObjCls*, int, int);
};
bool FUN_008c7aa0();
TaskQ* FUN_004537b0();
void FUN_00b6bb30(void*, float);
void FUN_005b5e40(const char*);
extern PlayerCls* DAT_011dea3c;
extern unsigned char DAT_011a59bc;
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    NiPtrC m_0c;
    void UpdateMuzzleFlash(ParamCls*);
};
// @fnv 0x009bb240
void ThisCls::UpdateMuzzleFlash(ParamCls* apParam)
{
    if (!(m_0c.FUN_00559450() && apParam && apParam->FUN_008d6f30() && apParam->v116()))
        return;
    NodeCls* node2 =
        apParam->v64()
            ? (NodeCls*)apParam->v131()
            : (((FUN_009611e0_shell*)this)->FUN_009611e0()
                   ? (NodeCls*)((NodeSrc*)((FUN_009611e0_shell*)this)->FUN_009611e0())->FUN_00525700(apParam->v116())
                   : (NodeCls*)0);
    bool _flag = false;
    float fResultTmp = 0.0f;
    if (node2)
    {
        NiTransform A_2;
        ObjCls* target2;
        if (apParam == (ParamCls*)DAT_011dea3c)
        {
            if (!DAT_011dea3c->FUN_00524d10())
            {
                target2 = (ObjCls*)DAT_011dea3c->FUN_00950bb0(true);
            }
            else
            {
                target2 = (ObjCls*)DAT_011dea3c->v116();
            }
            NiTransform B;
            if (target2)
            {
                B.m_rot = target2->FUN_00461130()->FUN_004768c0();
                B.m_vScale = 1.0f / target2->FUN_00461130()->m_vScale;
                B.m_trans = target2->FUN_00461130()->m_trans.FUN_004a0bd0();
                B.m_trans = B.FUN_004b4500(&B.m_trans);
                B.m_trans.FUN_00439180(B.m_vScale);
            }
            A_2 = B.FUN_0062c250(node2->FUN_00461130());
            _flag = true;
            if (!DAT_011dea3c->FUN_00524d10())
            {
                fResultTmp = DAT_011dea3c->FUN_00950a60(true) ? DAT_011dea3c->FUN_00950a60(true)->FUN_00453700() : 0.0f;
            }
            else
            {
                fResultTmp = DAT_011dea3c->v121() ? ((AnimCls*)DAT_011dea3c->v121())->FUN_00453700() : 0.0f;
            }
        }
        else
        {
            A_2 = *node2->FUN_00461130();
            HolderCls* holder6 = (HolderCls*)apParam->FUN_008d6f30();
            target2 = holder6->FUN_005497a0();
        }
        if (target2)
        {
            if (target2 != (void*)((FUN_009611e0_shell*)m_0c.FUN_00559450())->FUN_009611e0())
            {
                if (!FUN_008c7aa0())
                {
                    target2->v55(m_0c.FUN_00559450(), 1);
                }
                else
                {
                    FUN_004537b0()->QueueTaskWithTwoObjects(m_0c.FUN_00559450(), target2, 1, 0);
                }
                FUN_00b6bb30(m_0c.FUN_00559450()->v3(), 1.0f);
            }
        }
        m_0c.FUN_00559450()->FUN_00440460(&A_2.m_trans);
        m_0c.FUN_00559450()->FUN_0043fa80(&A_2);
        m_0c.FUN_00559450()->FUN_00440490(A_2.m_vScale);
        if (_flag)
        {
            if (!FUN_008c7aa0())
            {
                NiUpdateData aUpd(fResultTmp, false, false);
                m_0c.FUN_00559450()->FUN_00a59c60(aUpd);
            }
            else
            {
                if (DAT_011a59bc)
                {
                    FUN_005b5e40("Trying to update a Muzzle Flash when not in the main thread");
                    DAT_011a59bc = 0;
                }
            }
        }
    }
}

struct SpawnedItem;
struct ProjTarget
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool v100();
    SpawnedItem* FUN_008d8520();
};
struct SpawnedItem
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4(Projectile* p, ProjTarget* q);
    virtual void* v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
};
struct FUN_00825c00_cls
{
    void* FUN_00825c00();
};
struct FUN_009611e0_cls
{
    unsigned int FUN_009611e0();
};
struct FUN_00978740_cls
{
    void ActivateMuzzleFlash(Projectile* p, ProjTarget* q);
};
extern FUN_00978740_cls DAT_011e0e80;

// @fnv 0x009bb6d0
void __cdecl FUN_009bb6d0(ProjTarget* pTarget, Projectile* pProjectile)
{
    if (pTarget != 0 && pProjectile != 0)
    {
        if (pTarget->v100())
        {
            SpawnedItem* item;
            ProjTarget* node = pTarget;
            item = node->FUN_008d8520();
            if (item != 0)
            {
                if (!(item->v6b8() != 0 &&
                      ((FUN_00825c00_cls*)item->v6b8())->FUN_00825c00() == pProjectile->FUN_004181e0() &&
                      ((FUN_009611e0_cls*)item->v6b8())->FUN_009611e0() == pProjectile->FUN_00476c90()))
                {
                    item->v6c4();
                    item->v6b4(pProjectile, pTarget);
                }
                if (item->v6b8() != 0)
                    ((FUN_009bb690_shell*)item->v6b8())->FUN_009bb690();
            }
        }
        else
        {
            DAT_011e0e80.ActivateMuzzleFlash(pProjectile, pTarget);
        }
    }
}

struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
    void FUN_0087ac60(unsigned int);
};
struct ModelLoader
{
    void FUN_0045a5e0(const char*);
};
struct Loader_S;
extern Loader_S* g_modelLoader;
bool __cdecl IsConditionMet();
struct Calendar
{
    unsigned int GetDaysPassed();
};
struct Flt
{
    operator unsigned int();
};
struct GO
{
    void* p;
    ~GO();
    void operator=(void*);
};
struct TESModel
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* GetModelFilePath();
    unsigned int GetModelLength() const;
};
struct NodeX
{
    virtual void w00();
    virtual void w01();
    virtual void w02();
    virtual void w03();
    virtual void w04();
    virtual void w05();
    virtual void w06();
    virtual void w07();
    virtual void w08();
    virtual void w09();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void Release3D(unsigned int);
};

struct FUN_009badc0
{
    bool bEnabled;
    unsigned char unk01;
    bool bUpdateLight;
    unsigned char unk03;
    float m_fDurationTimer;
    float fFlashDuration;
    GO m_pController;
    GO spOther;
    ~FUN_009badc0();
    void FUN_009bb850();
};

// For nonzero model length, passes its path to the loader; conditionally calls Release3D or FUN_0087ac60, then clears m_pController.
// @fnv 0x009badc0
FUN_009badc0::~FUN_009badc0()
{
    TESModel* m_kModelObjectsItem = (TESModel*)((FUN_009baee0_owner*)this)->FUN_009baee0();
    if (m_kModelObjectsItem->GetModelLength())
        ((ModelLoader*)g_modelLoader)->FUN_0045a5e0(m_kModelObjectsItem->GetModelFilePath());
    if (*(Flt*)&m_pController && ((Calendar*)(unsigned int)*(Flt*)&m_pController)->GetDaysPassed())
    {
        if (!IsConditionMet())
            ((NodeX*)((Calendar*)(unsigned int)*(Flt*)&m_pController)->GetDaysPassed())
                ->Release3D(*(Flt*)&m_pController);
        else
            TaskQueueInterface::GetInstance()->FUN_0087ac60(*(Flt*)&m_pController);
    }
    m_pController = 0;
    FUN_009bb850();
}
