
// src/fallout_shared/tesobjectcell_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005434d0: the skeleton of src/fallout_shared/tesobjectcell_rtti_variant.cpp
// with declarations corrected to what the original code does (tesobjectcell_packet_rtti_variant.h: public: virtual ~TESObjectCELL(); -> public: virtual ~TESObjectCELL(); virtual void Vir; tesobjectcell_packet_rtti_variant.h: TESObjectCELL += bool FUN_005434d0(struct FormGroupQuery* group); bool IsFormTypeBelowThreshold(struct FormGroupQuery* group); unsigned int FUN_00544). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesobjectcell_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectCELL, TESObjectREFR, TESWorldSpace). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "tesobjectcell_packet_rtti_variant_decl_tesobjectcell_rtti_variant.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();
class CellView;
class MobileObject : public TESObjectREFR
{
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
};
// IsSleepingOrResting
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
    void QueueReference(RefView* pkRef, int iCell);
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
    void CellRefLockLeave();  // CellRefLockLeave
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
void __fastcall CellRefLockLeave(TESObjectCELL* cell);
unsigned int __cdecl GetRandomNumberInRange(int low, int high);
TESObjectREFR* __cdecl FUN_0054afb0(TESForm* source, TESForm* destination, void* context);

struct FormGroupQuery
{
    unsigned int tag, unk04, value, kind;
};
extern unsigned int DAT_01187020;
TESForm* LookupFormByID(unsigned int);
// @fnv 0x005434d0
bool TESObjectCELL::FUN_005434d0(FormGroupQuery* group)
{

    bool matched = false;

    if (group && group->tag == DAT_01187020)
    {

        switch (group->kind)
        {

        case 0:
            matched = IsFormTypeBelowThreshold(group);
            break;

        case 2:

            if (IsCellInterior() && FUN_005441b0() < group->value)

                matched = true;

            break;

        case 3:

            if (IsCellInterior() && FUN_00544210() < group->value)

                matched = true;

            break;

        case 6:
        case 8:
        case 9: {

            TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(LookupFormByID(group->value));

            if (cell)

                matched = MatchForm(cell);

            break;
        }

        case 4:

            if (!IsCellInterior())
            {

                if (FUN_005516c0())
                    matched = true;

                else if (FUN_005441b0() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 5:

            if (!IsCellInterior())
            {

                if (FUN_005516c0())
                    matched = true;

                else if (FUN_00544210() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 1:

            if (!IsCellInterior())
            {

                TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(LookupFormByID(group->value));

                if (world)

                    matched = MatchForm(world);
            }
            else
                matched = true;

            break;

        case 7:
            matched = true;
            break;
        }
    }

    return matched;
}
