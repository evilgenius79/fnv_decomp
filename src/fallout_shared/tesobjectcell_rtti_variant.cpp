
// src/fallout_shared/tesobjectcell_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectCELL, TESObjectREFR, TESWorldSpace). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesobjectcell_packet_rtti_variant.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();

class CellView;

struct BSExtraData
{
    virtual ~BSExtraData();
    unsigned char type;
    unsigned char unknown05, unknown06, unknown07;
    BSExtraData* next;
};
struct FUN_0040f410 : BSExtraData
{
    unsigned int references;
    FUN_0040f410();
};
struct ExtraListAccess548 : ExtraDataList
{
    BSExtraData* AddExtra(BSExtraData*);
    bool RemoveExtra(BSExtraData*, bool);
};
class BaseProcess;
class MobileObject : public TESObjectREFR
{
  public:
    bool FUN_00440da0();
    BaseProcess* FUN_008d8520();
    int FUN_00931850();
};
struct RefList548
{
    TESObjectREFR* item;
    RefList548* next;
    TESObjectREFR*& FUN_006815c0();
    RefList548* FUN_00726070();
};
class GlobalObject_0096d020
{
  public:
    void FUN_0096e870(MobileObject*);
};
struct Cell548 : TESObjectCELL
{
    RefList548* FUN_009604f0();
    void FUN_00541ae0();
    void FUN_00551480(bool RetainReference);
};

class RefView : public TESObjectREFR
{
  public:
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void Unk_1c4();  // +0x1c4
    virtual void v072();
    virtual void Unk_1cc(int iA, int iB);  // +0x1cc
    virtual void* GetNode3D();             // +0x1d0
    virtual void v0x75();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void SetParentCell(CellView* pkCell);  // +0x228
    virtual void v0x8b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void Unk_240();  // +0x240
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();  // +0x24c

    void* FUN_007af430();
    bool FUN_00564e60();
    bool FUN_00440da0();  // GetDisabled
    class RefExtra* FUN_005d43c0();
    CellView* FUN_008d6f30();  // GetParentCell
    bool FUN_005656d0();
    bool FUN_0056a250();
    bool FUN_00437b90();
    void FUN_005728c0(int iValue);
    bool FUN_00548700();
    bool IsFlag20000000Set();
};

class RefExtra
{
  public:
    void FUN_0041d390(CellView* pkCell);
};

struct RefList
{
    void FUN_005ae3d0(RefView*& rpkRef);  // AddHead
    bool FUN_005f65d0(RefView*& rpkRef);  // IsInList
};
extern RefList DAT_011ca13c;
extern RefList DAT_011ca144;

class CellNavHandler
{
  public:
    void FUN_00587d10(RefView* pkRef);
};
class CellDataHandler
{
  public:
    bool FUN_004516b0();
};
extern CellDataHandler* DAT_011c3f2c;
class CellTES
{
  public:
    bool FUN_004511e0(CellView* pkCell, int iValue);
    int FUN_00458be0(CellView* pkCell, int iA, int iB);
};
extern CellTES* DAT_011dea10;
class CellPlayer
{
  public:
    bool FUN_0094df60();
};  // IsSleepingOrResting
extern CellPlayer* DAT_011dea3c;
class CellSaveLoad
{
  public:
    bool FUN_0047c850();
};
extern CellSaveLoad* DAT_011de45c;
class CellModelLoader
{
  public:
    void FUN_00444850(RefView* pkRef, int iCell);
};
extern CellModelLoader* DAT_011c3b3c;
class CellProcessLists
{
  public:
    void FUN_0096e870(RefView* pkRef);
};
extern CellProcessLists DAT_011e0e80;
class CellNodeMap
{
  public:
    bool RemoveKey(void* pvNode);
};
extern CellNodeMap DAT_011ca0f4;
class CellTaskQueue
{
  public:
    void FUN_0087b400(RefView* pkRef);
};
CellTaskQueue* FUN_004537b0();
bool FUN_008c7aa0();
class CellView
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void Unk_0c8(int iValue);  // +0xc8
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
    unsigned short m_usPersistentCount;  // +0xa8
    unsigned short unkaa;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    void* m_pkNavMeshes;  // +0xc4

    bool FUN_005516c0();
    void FUN_00541ac0();  // CellRefLockEnter
    void FUN_00541ae0();  // CellRefLockLeave
    RefList* FUN_009604f0();
    CellNavHandler* FUN_0054ddd0();
    void FUN_0054ca90(RefView* pkRef);  // RemoveReference
    bool FUN_00450ff0();
    bool FUN_004523c0();
    void FUN_00545560(RefView* pkRef);
    void FUN_005455c0(RefView* pkRef);
    void FUN_00548880(RefView* pkRef, bool bArg);
    bool FUN_00548720();
    bool FUN_00425fd0();  // IsInterior
    void FUN_00548230(RefView* pkRef, bool bArg);
};

// @fnv 0x00548230
void CellView::FUN_00548230(RefView* pkRef, bool bArg)
{
    if (!pkRef || !pkRef->FUN_007af430())
        return;
    if (pkRef->FUN_00564e60() && !pkRef->FUN_00440da0())
        m_usPersistentCount++;
    if (FUN_005516c0())
    {
        FUN_00541ac0();
        FUN_009604f0()->FUN_005ae3d0(pkRef);
        FUN_00541ae0();
        pkRef->FUN_005d43c0()->FUN_0041d390(this);
        CellNavHandler* pkHandler = FUN_0054ddd0();
        if (pkHandler)
            pkHandler->FUN_00587d10(pkRef);
        if (!DAT_011c3f2c->FUN_004516b0())
            Unk_0c8(1);
        return;
    }
    CellView* pkOldCell = pkRef->FUN_008d6f30();
    if (pkOldCell)
        pkOldCell->FUN_0054ca90(pkRef);
    FUN_00541ac0();
    FUN_009604f0()->FUN_005ae3d0(pkRef);
    pkRef->SetParentCell(this);
    FUN_00541ae0();
    if (FUN_00450ff0())
        DAT_011c95c8->FUN_00526f20((BGSPerkEntry*)pkRef);
    if (m_pkNavMeshes)
    {
        if ((!pkRef->IsActor() || pkRef->FUN_00440da0()) && pkRef->FUN_005656d0())
            FUN_00545560(pkRef);
        if (pkRef->FUN_0056a250())
            FUN_005455c0(pkRef);
    }
    if (!pkRef->FUN_00440da0() && pkRef->GetNode3D())
    {
        MobileObject* pkMobile = dynamic_cast<MobileObject*>(static_cast<TESObjectREFR*>(pkRef));
        if (!pkMobile)
            pkRef->Unk_1c4();
    }
    bool bHandled = false;
    if (!DAT_011c3f2c->FUN_004516b0() && !bHandled && !pkRef->FUN_00437b90())
    {
        void* pvNode = pkRef->GetNode3D();
        if (DAT_011dea10->FUN_004511e0(this, 0))
        {
            bool bQueue = false;
            if (pvNode)
                FUN_00548880(pkRef, bArg);
            else
            {
                if (!pkRef->IsActor())
                    bQueue = true;
                else if (!DAT_011dea3c->FUN_0094df60() && !FUN_00548720())
                    bQueue = true;
                if (bQueue)
                {
                    if (pkRef->IsActor() && (!DAT_011de45c->FUN_0047c850() || DAT_011de45c->FUN_0047c850()))
                    {
                        if (FUN_00450ff0() || FUN_004523c0())
                            pkRef->Unk_240();
                        else
                            pkRef->Unk_24c();
                    }
                    DAT_011c3b3c->FUN_00444850(pkRef, DAT_011dea10->FUN_00458be0(this, 0, 0));
                }
            }
            if (!bQueue && pkRef->IsActor())
                DAT_011e0e80.FUN_0096e870(pkRef);
        }
        else
        {
            DAT_011ca0f4.RemoveKey(pkRef->GetNode3D());
            if (pkRef->IsActor() && !DAT_011dea3c->FUN_0094df60() && !DAT_011de45c->FUN_0047c850())
            {
                if (!FUN_008c7aa0())
                    pkRef->Unk_1cc(0, 0);
                else
                    FUN_004537b0()->FUN_0087b400(pkRef);
            }
        }
    }
    pkRef->FUN_005728c0(0);
    if (!pkRef->FUN_008d6f30()->FUN_00425fd0())
    {
        if (pkRef->FUN_00548700() && !DAT_011ca13c.FUN_005f65d0(pkRef))
            DAT_011ca13c.FUN_005ae3d0(pkRef);
        if (pkRef->IsFlag20000000Set() && !DAT_011ca144.FUN_005f65d0(pkRef))
            DAT_011ca144.FUN_005ae3d0(pkRef);
    }
}

class TESForm
{
  public:
    virtual ~TESForm();
    int GetFormType();
};
class TESObject : public TESForm
{
};
class TESBoundObject : public TESObject
{
};
class TESObjectDOOR : public TESBoundObject
{
  public:
    bool FUN_005194d0();
    bool HasEntry(TESForm* destination);
};
class ReferenceList
{
  public:
    TESObjectREFR* item;
    ReferenceList* next;
    ReferenceList();
    ~ReferenceList();
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    ReferenceList* GetNext();
    void Append(TESObjectREFR*& reference);
    void RemoveAll();
};
// Verified native methods use only their typed receiver in ECX.
ReferenceList* __fastcall FUN_009604f0(TESObjectCELL* cell);
TESObjectCELL* __fastcall FUN_005f36f0(TESWorldSpace* world);
TESBoundObject* __fastcall FUN_007af430(TESObjectREFR* reference);
bool __fastcall FUN_00440d80(const TESObjectREFR* reference);
bool __fastcall FUN_00440da0(TESObjectREFR* reference);
bool __fastcall FUN_00477ba0(TESObjectREFR* reference);
void* __fastcall FUN_00568e50(TESObjectREFR* reference);
void __fastcall FUN_00541ae0(TESObjectCELL* cell);
unsigned int __cdecl GetRandomNumberInRange(int low, int high);
// @fnv 0x0054afb0
TESObjectREFR* __cdecl FUN_0054afb0(TESForm* source, TESForm* destination, void* context)
{
    TESObjectREFR* result = 0;
    if (source && destination && context && source != destination)
    {
        unsigned int countB = 0;
        ReferenceList candidatesVal;
        ReferenceList* cursor4 = 0;
        TESWorldSpace* world = 0;
        TESObjectCELL* cellVal = dynamic_cast<TESObjectCELL*>(source);
        TESObjectCELL* lockedCellVal = 0;
        if (cellVal)
        {
            cursor4 = FUN_009604f0(cellVal);
            lockedCellVal = cellVal;
        }
        else
        {
            world = dynamic_cast<TESWorldSpace*>(source);
            if (world && FUN_005f36f0(world))
            {
                cursor4 = FUN_009604f0(FUN_005f36f0(world));
                lockedCellVal = FUN_005f36f0(world);
            }
        }
        lockedCellVal->CellRefLockEnter();
        while (cursor4 && !cursor4->IsEmpty())
        {
            TESObjectREFR* reference = cursor4->GetItem();
            if (FUN_007af430(reference)->GetFormType() == 28 && !FUN_00440d80(reference) && !FUN_00440da0(reference) &&
                !FUN_00477ba0(reference))
            {
                TESObjectDOOR* door = dynamic_cast<TESObjectDOOR*>(FUN_007af430(reference));
                if (door && door->FUN_005194d0() && door->HasEntry(destination) && !FUN_00568e50(reference))
                {
                    candidatesVal.Append(reference);
                    ++countB;
                }
            }
            cursor4 = cursor4->GetNext();
        }
        FUN_00541ae0(lockedCellVal);
        if (countB > 0 && !candidatesVal.IsEmpty())
        {
            unsigned int selectedX = GetRandomNumberInRange(0, countB);
            unsigned int index2 = 0;
            cursor4 = &candidatesVal;
            while (cursor4 && !cursor4->IsEmpty())
            {
                if (index2 == selectedX)
                {
                    result = cursor4->GetItem();
                    break;
                }
                else
                {
                    ++index2;
                    cursor4 = cursor4->GetNext();
                }
            }
            candidatesVal.RemoveAll();
        }
    }
    return result;
}

class Actor : public MobileObject
{
  public:
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148();
    virtual void slot_14c();
    virtual void slot_150();
    virtual void slot_154();
    virtual void slot_158();
    virtual void slot_15c();
    virtual void slot_160();
    virtual void slot_164();
    virtual void slot_168();
    virtual void slot_16c();
    virtual void slot_170();
    virtual void slot_174();
    virtual void slot_178();
    virtual void slot_17c();
    virtual void slot_180();
    virtual void slot_184();
    virtual void slot_188();
    virtual void slot_18c();
    virtual void slot_190();
    virtual void slot_194();
    virtual void slot_198();
    virtual void slot_19c();
    virtual void slot_1a0();
    virtual void slot_1a4();
    virtual void slot_1a8();
    virtual void slot_1ac();
    virtual void slot_1b0();
    virtual void slot_1b4();
    virtual void slot_1b8();
    virtual void slot_1bc();
    virtual void slot_1c0();
    virtual void slot_1c4();
    virtual void slot_1c8();
    virtual void slot_1cc();
    virtual void slot_1d0();
    virtual void slot_1d4();
    virtual void slot_1d8();
    virtual void slot_1dc();
    virtual void slot_1e0();
    virtual void slot_1e4();
    virtual void slot_1e8();
    virtual void slot_1ec();
    virtual void slot_1f0();
    virtual void slot_1f4();
    virtual void slot_1f8();
    virtual void slot_1fc();
    virtual void slot_200();
    virtual void slot_204();
    virtual void slot_208();
    virtual void slot_20c();
    virtual void slot_210();
    virtual void slot_214();
    virtual void slot_218();
    virtual void slot_21c();
    virtual void slot_220();
    virtual void slot_224();
    virtual void slot_228();
    virtual bool FUN_virtual22c(int);
    virtual void slot_230();
    virtual void slot_234();
    virtual void slot_238();
    virtual void slot_23c();
    virtual void slot_240();
    virtual void slot_244();
    virtual void slot_248();
    virtual void slot_24c();
    virtual void slot_250();
    virtual void slot_254();
    virtual void slot_258();
    virtual void slot_25c();
    virtual void slot_260();
    virtual void slot_264();
    virtual void slot_268();
    virtual void slot_26c();
    virtual void slot_270();
    virtual void slot_274();
    virtual void slot_278();
    virtual void slot_27c();
    virtual void slot_280();
    virtual void slot_284();
    virtual void slot_288();
    virtual void slot_28c();
    virtual void slot_290();
    virtual void slot_294();
    virtual void slot_298();
    virtual void slot_29c();
    virtual void slot_2a0();
    virtual void slot_2a4();
    virtual void slot_2a8();
    virtual void slot_2ac();
    virtual void slot_2b0();
    virtual void slot_2b4();
    virtual void slot_2b8();
    virtual void slot_2bc();
    virtual void slot_2c0();
    virtual void slot_2c4();
    virtual void slot_2c8();
    virtual void slot_2cc();
    virtual void slot_2d0();
    virtual void slot_2d4();
    virtual void slot_2d8();
    virtual void slot_2dc();
    virtual void slot_2e0();
    virtual void slot_2e4();
    virtual void slot_2e8();
    virtual void slot_2ec();
    virtual void slot_2f0();
    virtual void slot_2f4();
    virtual void slot_2f8();
    virtual void slot_2fc();
    virtual void slot_300();
    virtual void slot_304();
    virtual void slot_308();
    virtual void slot_30c();
    virtual void slot_310();
    virtual void slot_314();
    virtual void slot_318();
    virtual void slot_31c();
    virtual void slot_320();
    virtual void slot_324();
    virtual void slot_328();
    virtual void slot_32c();
    virtual void slot_330();
    virtual void slot_334();
    virtual void slot_338();
    virtual void slot_33c();
    virtual void slot_340();
    virtual void slot_344();
    virtual void slot_348();
    virtual void slot_34c();
    virtual void slot_350();
    virtual void slot_354();
    virtual void slot_358();
    virtual void slot_35c();
    virtual void slot_360();
    virtual void slot_364();
    virtual void slot_368();
    virtual void slot_36c();
    virtual void slot_370();
    virtual void slot_374();
    virtual void slot_378();
    virtual void slot_37c();
    virtual void slot_380();
    virtual void slot_384();
    virtual void slot_388();
    virtual void slot_38c();
    virtual void slot_390();
    virtual void slot_394();
    virtual void slot_398();
    virtual void slot_39c();
    virtual void slot_3a0();
    virtual void slot_3a4();
    virtual void slot_3a8();
    virtual void slot_3ac();
    virtual void slot_3b0();
    virtual void slot_3b4();
    virtual void slot_3b8();
    virtual void slot_3bc();
    virtual void slot_3c0();
    virtual void slot_3c4();
    virtual void slot_3c8();
    virtual void slot_3cc();
    virtual void slot_3d0();
    virtual void slot_3d4();
    virtual void slot_3d8();
    virtual void slot_3dc();
    virtual void slot_3e0();
    virtual void slot_3e4();
    virtual void slot_3e8();
    virtual void slot_3ec();
    virtual void slot_3f0();
    virtual void slot_3f4();
    virtual void slot_3f8();
    virtual void slot_3fc();
    virtual void slot_400();
    virtual void slot_404();
    virtual void slot_408();
    virtual void slot_40c();
    virtual void slot_410();
    virtual void slot_414();
    virtual void slot_418();
    virtual void slot_41c();
    virtual void slot_420();
    virtual void FUN_virtual424(TESObjectREFR*, int, int, int, int, int, int, int);
    virtual void slot_428();
    virtual void slot_42c();
    virtual void slot_430();
    virtual void slot_434();
    virtual void slot_438();
    virtual void slot_43c();
    virtual void slot_440();
    virtual void slot_444();
    virtual void slot_448();
    virtual void slot_44c();
    virtual void slot_450();
    virtual void slot_454();
    virtual void slot_458();
    virtual void slot_45c();
    virtual void FUN_virtual460(TESObjectREFR*, float);
    bool FUN_00440da0();
    bool FUN_00440d80();
    bool FUN_0087f3d0();
    void FUN_0089d900(Actor*, float);
};
struct ContainerChanges550
{
    float FUN_004ce380(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, int);
};
struct ExtraListAccess550 : ExtraDataList
{
    ContainerChanges550* FUN_00418520();
};
struct ReferenceAccess550 : TESObjectREFR
{
    ExtraDataList* FUN_005d43c0();
    void* FUN_00569160();
    void FUN_005692a0();
};
struct RefList550
{
    TESObjectREFR* item;
    RefList550* next;
    TESObjectREFR*& FUN_006815c0();
    RefList550* FUN_00726070();
};
extern TESObjectREFR* g_thePlayer;
void FUN_00555c20();
struct Cell550 : TESObjectCELL
{
    RefList550* FUN_009604f0();
    void FUN_00541ae0();
    void FUN_0054b5b0();
};
// @fnv 0x0054b5b0
void Cell550::FUN_0054b5b0()
{
    CellRefLockEnter();
    RefList550* position = FUN_009604f0();
    while (position)
    {
        TESObjectREFR* reference = position->FUN_006815c0();
        if (reference && reference != g_thePlayer)
        {
            Actor* actor = dynamic_cast<Actor*>(reference);
            ContainerChanges550* changes =
                static_cast<ExtraListAccess550*>(static_cast<ReferenceAccess550*>(reference)->FUN_005d43c0())
                    ->FUN_00418520();
            if (changes)
                changes->FUN_004ce380(reference, g_thePlayer, false, false, true, false, -1, 0);
            if (actor && !actor->FUN_00440da0() && !actor->FUN_00440d80())
                actor->FUN_virtual460(g_thePlayer, 10.0f);
            if (actor && !actor->FUN_0087f3d0() && !actor->FUN_00440da0() && !actor->FUN_00440d80() &&
                !actor->FUN_virtual22c(0))
            {
                actor->FUN_virtual424(g_thePlayer, 0, 0, 0, 0, 0, 1, 0);
                actor->FUN_0089d900(0, 0.0f);
            }
            if (static_cast<ReferenceAccess550*>(reference)->FUN_00569160())
                static_cast<ReferenceAccess550*>(reference)->FUN_005692a0();
            FUN_00555c20();
        }
        position = position->FUN_00726070();
    }
    FUN_00541ae0();
}

void* __cdecl operator new(unsigned int);

// ExtraCell3D owns the reference count associated with the cell's loaded 3D.

extern GlobalObject_0096d020 g_011e0e80;

// @fnv 0x00551480
void Cell548::FUN_00551480(bool RetainReference)
{
    FUN_0040f410* extra = static_cast<FUN_0040f410*>(extraDataList.GetExtraData(9));
    if (!extra && RetainReference)
    {
        extra = new FUN_0040f410;
        static_cast<ExtraListAccess548*>(&extraDataList)->AddExtra(extra);
        CellRefLockEnter();
        RefList548* position = FUN_009604f0();
        while (position && position->FUN_006815c0())
        {
            MobileObject* mobile = dynamic_cast<MobileObject*>(position->FUN_006815c0());
            position = position->FUN_00726070();
            if (mobile && !mobile->FUN_00440da0() && mobile->FUN_008d8520() && mobile->FUN_00931850() == 3)
                g_011e0e80.FUN_0096e870(mobile);
        }
        FUN_00541ae0();
    }
    if (extra)
    {
        if (RetainReference)
            extra->references++;
        else
            extra->references--;
        if (!extra->references)
            static_cast<ExtraListAccess548*>(&extraDataList)->RemoveExtra(extra, true);
    }
}

class TESWeather : public TESForm
{
};
TESForm* FUN_004839c0(unsigned int auiFormId);

class NiUpdateData
{
  public:
    float m_fTime;
    unsigned short unk04;
    bool m_bQueueShadow;
    bool m_bQueueAnim;
    bool m_bUpdateShadow;
    unsigned char unk09;
    unsigned short unk0a;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bThreaded);
};

class NodeView
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void UpdateDownwardPass(NiUpdateData& kData, unsigned int uiFlags);  // +0xa8
    NodeView* FUN_009611e0();
};

class SceneRoot
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void Unk_0c4();  // +0xc4
};

class RefNodeView
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NodeView* GetNode3D();  // +0x1d0
};

struct RefNodeList
{
    RefNodeView* m_pkItem;
    RefNodeList* m_pkNext;
    bool FUN_008256d0();           // IsEmpty
    RefNodeView** FUN_006815c0();  // GetItem
    RefNodeList* FUN_00726070();   // GetNext
};

class FormTypeView
{
  public:
    int FUN_00401170();
};  // GetFormType
class KeyRefView
{
  public:
    FormTypeView* FUN_007af430();
};

struct NiColor
{
    float r, g, b;
};
extern NiColor DAT_011a9b7c;

class LightForm
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual NiColor* GetColor();  // +0xc0
    int FUN_00401170();           // GetFormType
    unsigned int FUN_005e3fc0();  // packed RGB
    TESWeather* FUN_0059bb30();
};

class BaseLight
{
  public:
    int FUN_00401170();
    unsigned int FUN_005e3fc0();
};

struct SkyColorData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

class Sky
{
  public:
    void FUN_0063b630(SkyColorData* pkData, TESWeather* pkWeather, float fBlendRes, float* pfOut, int* piOut);
    void FUN_0063bab0(SkyColorData* pkData, TESWeather* pkWeather, int iA, int iB, float* pfOut, int* piOut);
    float FUN_00644950();
    void FUN_0063c690(NiColor* pkColorPos, SkyColorData* pkData, float fValue);
};
Sky* FUN_0046dd00();

class PointLightNode
{
  public:
    void SetEffectColor(NiColor& kColor);
};
class PointLightPtr
{
  public:
    PointLightNode* FUN_00559450();
};

class MapRefView
{
  public:
    LightForm* FUN_00569580();
    BaseLight* FUN_007af430();
    PointLightPtr* FUN_005725f0();
};

class PlayerLightView
{
  public:
    LightForm* FUN_005454d0();
};

template <class K, class V> struct CellRefMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* FUN_004b9ba0();                                    // GetFirstPos
    void FUN_006b7f20(void*& rpvPos, K& rkKey, V& rkValue);  // GetNext
};

struct CellLoadedData
{
    int unk00;
    RefNodeList kRefs;                              // +0x04
    CellRefMap<KeyRefView*, NodeView*> kActors;     // +0x0c
    CellRefMap<LightForm*, NiColor*> kColors;       // +0x1c
    CellRefMap<MapRefView*, void*> kMapReferences;  // +0x2c
};

struct CellIntSetting
{
    int* FUN_0043d4d0();
};
extern CellIntSetting DAT_011c3ea4;
struct CellFloatSetting
{
    float* FUN_00403e20();
};
extern CellFloatSetting DAT_011ccccc;
struct CellTimer
{
    float FUN_0084d030();
};
extern CellTimer DAT_011f6394;
extern float DAT_0118b698;
extern float DAT_0118b694;
extern float DAT_0102f0e4;

class ManagedTaskQueue : public CellTaskQueue
{
  public:
    void FUN_0087aad0(NodeView* pkNode);
    void FUN_0087abb0(NodeView* pkNode);
};
void RunWithLock(NodeView* pkNode);
class CellShadowScene
{
  public:
    void FUN_00b5d9f0(NodeView* pkNode, int iValue);
};
CellShadowScene* FUN_00450b80(int iValue);
unsigned int FUN_00552380();
bool FUN_004b5fc0(NodeView* pkNode, unsigned int uiCamera);
bool FUN_008c7aa0();

class CellWaterView
{
  public:
    void FUN_00929260(int iValue);
};
class CellWaterOwner
{
  public:
    CellWaterView* FUN_00586170();
};

class CellUpdateView
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
    short unka8;
    short m_sRefCount;  // +0xaa
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    CellLoadedData* m_pkLoaded;  // +0xc4
    float m_fWaterTimer;         // +0xc8
    unsigned short unkcc;
    bool m_bWaterCE;  // +0xce
    bool m_bWaterCF;  // +0xcf
    bool m_bWaterD0;  // +0xd0
    bool unkd1;
    bool m_bWaterD2;  // +0xd2

    bool FUN_00425fd0();
    bool FUN_00450ff0();
    SceneRoot* FUN_004543c0();
    NodeView* FUN_005497a0();
    bool FUN_005495a0();
    bool FUN_00557d10();
    void FUN_00557aa0();
    CellWaterOwner* FUN_0054ddd0();
    int GetByteAtOffset38();
    void FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded);
};
// @fnv 0x00551890
void CellUpdateView::FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded)
{
    if (FUN_00425fd0() && FUN_00450ff0())
    {
        SceneRoot* pkRoot = FUN_004543c0();
        if (pkRoot)
            pkRoot->Unk_0c4();
    }
    bool bThreaded = false;
    if (FUN_008c7aa0())
        bThreaded = true;
    NodeView* pkDynamic = FUN_005497a0();
    if (pkDynamic && !bSkipLoaded)
    {
        NiUpdateData kData(fTimeSinceScaleStart, false, bThreaded);
        pkDynamic->UpdateDownwardPass(kData, 0);
        if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
        {
            ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087aad0(pkDynamic);
            if (bThreaded && kData.m_bQueueShadow)
                RunWithLock(pkDynamic);
            if (bThreaded && kData.m_bQueueAnim)
                ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087abb0(pkDynamic);
        }
    }
    if (m_sRefCount > 0 && FUN_005495a0() && FUN_00557d10())
        FUN_00557aa0();
    if (m_bWaterD2 && FUN_0054ddd0() && GetByteAtOffset38() == 6)
    {
        m_bWaterD0 = true;
        m_bWaterCE = false;
        m_bWaterCF = false;
        if (FUN_0054ddd0())
            FUN_0054ddd0()->FUN_00586170()->FUN_00929260(1);
        m_bWaterD2 = false;
    }
    if (m_bWaterCE)
    {
        if (DAT_0118b698 * DAT_0118b694 <= m_fWaterTimer)
        {
            if (FUN_0054ddd0() && !m_bWaterD0)
                FUN_0054ddd0()->FUN_00586170()->FUN_00929260(1);
            m_bWaterD0 = true;
            m_bWaterCE = false;
            m_bWaterCF = false;
        }
        m_fWaterTimer += DAT_011f6394.FUN_0084d030();
    }
    if (m_pkLoaded)
    {
        if (bSkipLoaded)
        {
            RefNodeList* pkIter = &m_pkLoaded->kRefs;
            while (pkIter && !pkIter->FUN_008256d0())
            {
                RefNodeView* pkRef = *pkIter->FUN_006815c0();
                NodeView* pkNode = pkRef->GetNode3D();
                pkIter = pkIter->FUN_00726070();
                if (pkNode)
                {
                    NiUpdateData kNodeData(fTimeSinceScaleStart, false, bThreaded);
                    pkNode->UpdateDownwardPass(kNodeData, 0);
                    if (kNodeData.m_bUpdateShadow)
                        FUN_00450b80(0)->FUN_00b5d9f0(pkNode, 1);
                    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
                    {
                        ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087aad0(pkNode);
                        if (bThreaded && kNodeData.m_bQueueShadow)
                            RunWithLock(pkNode);
                        if (bThreaded && kNodeData.m_bQueueAnim)
                            ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087abb0(pkNode);
                    }
                }
            }
        }
        else
        {
            void* pvPos = m_pkLoaded->kActors.FUN_004b9ba0();
            while (pvPos)
            {
                KeyRefView* pkKeyNew = 0;
                NodeView* pkActorNode = 0;
                m_pkLoaded->kActors.FUN_006b7f20(pvPos, pkKeyNew, pkActorNode);
                if (pkActorNode && pkActorNode->FUN_009611e0() != pkDynamic)
                {
                    if (pkKeyNew->FUN_007af430()->FUN_00401170() == 0x25 && !FUN_004b5fc0(pkActorNode, FUN_00552380()))
                        continue;
                    NiUpdateData kActorData(fTimeSinceScaleStart, false, bThreaded);
                    pkActorNode->UpdateDownwardPass(kActorData, 0);
                    if (kActorData.m_bUpdateShadow)
                        FUN_00450b80(0)->FUN_00b5d9f0(pkActorNode, 1);
                    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
                    {
                        ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087aad0(pkActorNode);
                        if (bThreaded && kActorData.m_bQueueShadow)
                            RunWithLock(pkActorNode);
                        if (bThreaded && kActorData.m_bQueueAnim)
                            ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087abb0(pkActorNode);
                    }
                }
            }
            pvPos = m_pkLoaded->kColors.FUN_004b9ba0();
            while (pvPos)
            {
                LightForm* pkForm = 0;
                NiColor* pkUnused = 0;
                m_pkLoaded->kColors.FUN_006b7f20(pvPos, pkForm, pkUnused);
                if (pkForm)
                {
                    NiColor* pkColorPos = pkForm->GetColor();
                    switch (pkForm->FUN_00401170())
                    {
                    case 0x1e: {
                        LightForm* pkLightTmp = pkForm;
                        unsigned int uiColor = pkLightTmp->FUN_005e3fc0();
                        float fScale = DAT_0102f0e4;
                        pkColorPos->r = (unsigned char)(uiColor & 0xff) * fScale;
                        pkColorPos->g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                        pkColorPos->b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                        break;
                    }
                    case 0x37: {
                        LightForm* pkRegion = pkForm;
                        TESWeather* pkWeather = pkRegion->FUN_0059bb30();
                        if (!pkWeather)
                            pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                        if (pkWeather)
                        {
                            Sky* pkSky = FUN_0046dd00();
                            SkyColorData kSkyDataOut;
                            float fBlendRes;
                            int iIndexNew;
                            pkSky->FUN_0063b630(&kSkyDataOut, pkWeather, 1.0f, &fBlendRes, &iIndexNew);
                            pkSky->FUN_0063bab0(&kSkyDataOut, pkWeather, 0, 4, &fBlendRes, &iIndexNew);
                            float fValue = pkSky->FUN_00644950() * *DAT_011ccccc.FUN_00403e20();
                            pkSky->FUN_0063c690(pkColorPos, &kSkyDataOut, fValue);
                        }
                        break;
                    }
                    }
                }
            }
            pvPos = m_pkLoaded->kMapReferences.FUN_004b9ba0();
            while (pvPos)
            {
                MapRefView* pkLightRefTmp = 0;
                void* pvLightData = 0;
                m_pkLoaded->kMapReferences.FUN_006b7f20(pvPos, pkLightRefTmp, pvLightData);
                if (pvLightData)
                {
                    NiColor kColor = DAT_011a9b7c;
                    LightForm* pkSource = pkLightRefTmp->FUN_00569580();
                    if (!pkSource)
                        pkSource = ((PlayerLightView*)DAT_011dea3c)->FUN_005454d0();
                    if (pkSource)
                    {
                        switch (pkSource->FUN_00401170())
                        {
                        case 0x1e: {
                            LightForm* pkLightTmp = pkSource;
                            unsigned int uiColor = pkLightTmp->FUN_005e3fc0();
                            float fScale = DAT_0102f0e4;
                            kColor.r = (unsigned char)(uiColor & 0xff) * fScale;
                            kColor.g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                            kColor.b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                            break;
                        }
                        case 0x37: {
                            LightForm* pkRegion = pkSource;
                            TESWeather* pkWeather = pkRegion->FUN_0059bb30();
                            if (!pkWeather)
                                pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                            if (pkWeather)
                            {
                                Sky* pkSky = FUN_0046dd00();
                                SkyColorData kSkyDataOut;
                                float fBlendRes;
                                int iIndexNew;
                                pkSky->FUN_0063b630(&kSkyDataOut, pkWeather, 1.0f, &fBlendRes, &iIndexNew);
                                pkSky->FUN_0063bab0(&kSkyDataOut, pkWeather, 0, 4, &fBlendRes, &iIndexNew);
                                float fValue = pkSky->FUN_00644950() * *DAT_011ccccc.FUN_00403e20();
                                pkSky->FUN_0063c690(&kColor, &kSkyDataOut, fValue);
                            }
                            break;
                        }
                        }
                    }
                    if (pkLightRefTmp->FUN_007af430()->FUN_00401170() == 0x1e)
                    {
                        BaseLight* pkBaseRes = pkLightRefTmp->FUN_007af430();
                        unsigned int uiBaseColor = pkBaseRes->FUN_005e3fc0();
                        float m_fThirdCreatureStatCur = DAT_0102f0e4;
                        kColor.r *= (unsigned char)(uiBaseColor & 0xff) * m_fThirdCreatureStatCur;
                        kColor.g *=
                            (unsigned char)(((unsigned short)uiBaseColor >> 8) & 0xff) * m_fThirdCreatureStatCur;
                        kColor.b *= (unsigned char)((uiBaseColor >> 16) & 0xff) * m_fThirdCreatureStatCur;
                        PointLightPtr* pkLightPtrCur = pkLightRefTmp->FUN_005725f0();
                        if (pkLightPtrCur && pkLightPtrCur->FUN_00559450())
                            pkLightPtrCur->FUN_00559450()->SetEffectColor(kColor);
                    }
                }
            }
        }
    }
}
