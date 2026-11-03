
// package_ctx_variant.cpp: context variant of src/fallout_shared/package.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "package_decls.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class PackageInit;
class FUN_00670b30
{
  public:
    ~FUN_00670b30();
};
class FUN_0067f030 : public FUN_00670b30
{
  public:
    unsigned int type, value;
    float radius;
    FUN_0067f030();
    ~FUN_0067f030();
    void FUN_0067f760(PackageInit*);
    void FUN_0067f140(int);
};
class FUN_0067ff70
{
  public:
    unsigned int type, target, count, unknown;
    FUN_0067ff70();
    ~FUN_0067ff70();
    void FUN_006803b0(PackageInit*);
    void FUN_006800b0(int);
};
struct ConditionInit
{
    void FUN_00680a20(PackageInit*);
};
struct IdleInit
{
    void FUN_00479b00(PackageInit*);
};
struct ProcedureInit
{
    unsigned int unk00, unk04, unk08, unk0c;
    void FUN_0041fd00(int);
    void FUN_0067e190(PackageInit*);
};
struct PackageDataInit
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Init(PackageInit*);
    unsigned char unk04, flag05;
};
int __cdecl FUN_0046e8a0();
void __cdecl ResolveFormID(unsigned int*, void*);
class TESForm
{
  public:
    virtual void unused();
};
class TESCombatStyle : public TESForm
{
};
TESForm* __cdecl LookupFormByID(unsigned int);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern int DAT_0118627c, DAT_01183028;
void __cdecl FNV_Warning(const char*, ...);
class PackageInit
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
    virtual const char* GetDebugName();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int flags18, packageFlags;
    unsigned char type, unk21;
    unsigned short unk22;
    unsigned int unk24;
    PackageDataInit* data;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    ProcedureInit begin, end, change;
    bool FUN_004013e0();
    FUN_0067f030* FUN_0055b980();
    FUN_0067f030* FUN_00672dd0();
    FUN_0067ff70* FUN_00671d10();
    ConditionInit* FUN_0087eaa0();
    IdleInit* FUN_005f36f0();
    unsigned int FUN_006733e0();
    void FUN_00673400(void*);
    void* FUN_00484e60(int);
    unsigned int FUN_0084e3a0();
    int GetPackType();
    bool FUN_00674d20();
    bool FUN_00673890();
    void FUN_00672fc0(FUN_0067ff70*);
    void FUN_00671d30(FUN_0067f030*);
    void FUN_00484ab0(int);
    void FUN_00674930();
};
// @fnv 0x00674930
void PackageInit::FUN_00674930()
{
    if (FUN_004013e0())
        return;
    int warningsA = FUN_0046e8a0();
    if (FUN_0055b980())
        FUN_0055b980()->FUN_0067f760(this);
    if (FUN_00672dd0())
        FUN_00672dd0()->FUN_0067f760(this);
    if (FUN_00671d10())
        FUN_00671d10()->FUN_006803b0(this);
    if (FUN_0087eaa0())
        FUN_0087eaa0()->FUN_00680a20(this);
    if (FUN_005f36f0())
        FUN_005f36f0()->FUN_00479b00(this);
    if (data)
        data->Init(this);
    unsigned int kCombatStyle = FUN_006733e0();
    if (kCombatStyle)
    {
        ResolveFormID(&kCombatStyle, FUN_00484e60(-1));
        FUN_00673400(dynamic_cast<TESCombatStyle*>(LookupFormByID(kCombatStyle)));
        if (!FUN_006733e0())
            FNV_Warning("FORMS: Could not find combat style (%08X) on package '%s' (%08X).", kCombatStyle,
                        GetDebugName(), FUN_0084e3a0());
    }
    begin.FUN_0041fd00(0);
    end.FUN_0041fd00(1);
    change.FUN_0041fd00(2);
    begin.FUN_0067e190(this);
    end.FUN_0067e190(this);
    change.FUN_0067e190(this);
    if (warningsA != FUN_0046e8a0())
    {
        FNV_Warning(
            "MASTERFILE: Warnings were generated for package '%s' (%08). This package will be disabled in game.",
            GetDebugName(), FUN_0084e3a0());
        packageFlags |= 0x8000;
    }
    switch (GetPackType())
    {
    case 9:
        if (FUN_00674d20())
            FUN_0055b980()->FUN_0067f140(6);
        break;
    case 14:
        if (FUN_00674d20())
        {
            if (!FUN_00671d10())
                FUN_00672fc0(new FUN_0067ff70);
            FUN_00671d10()->FUN_006800b0(3);
        }
        break;
    case 13: {
        PackageDataInit* packageData_2 = data;
        if (packageData_2->flag05)
            FUN_0055b980()->FUN_0067f140(6);
        if (!FUN_0055b980())
        {
            FUN_0067f030* location = new FUN_0067f030;
            location->FUN_0067f140(6);
            FUN_00671d30(location);
            delete static_cast<FUN_00670b30*>(location);
        }
        break;
    }
    case 12:
        if (FUN_00673890())
            FUN_0055b980()->FUN_0067f140(6);
        break;
    }
    FUN_00484ab0(1);
}
