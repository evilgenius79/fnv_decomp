
// tesobjectcell_ctx4_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();

class TESForm
{
  public:
    virtual ~TESForm();
};
class BGSLightingTemplate : public TESForm
{
  public:
    virtual ~BGSLightingTemplate();
};
namespace CellLoading {

struct Cell;
struct Reference;
struct Node;
struct Pointer;

struct Name
{
    const char* FUN_00408da0();
    void FUN_00489100(int);
    unsigned int unk0, unk4;
};
struct Extra
{
    void FUN_00416be0(Cell*);
};

struct Vector
{
    float x, y, z;
};
struct Extras
{
    void FUN_00421a70(float);
};

struct Reference
{

    virtual void slot0();

    virtual void slot4();

    virtual void slot8();

    virtual void slotc();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void slot40();

    virtual void slot44();

    virtual void slot48();

    virtual void slot4c();

    virtual void slot50();

    virtual void slot54();

    virtual void slot58();

    virtual void slot5c();

    virtual void slot60();

    virtual void slot64();

    virtual void slot68();

    virtual void slot6c();

    virtual void slot70();

    virtual void slot74();

    virtual void slot78();

    virtual void slot7c();

    virtual void slot80();

    virtual void slot84();

    virtual void Load();

    virtual void slot8c();

    virtual void slot90();

    virtual void slot94();

    virtual void slot98();

    virtual void slot9c();

    virtual void slota0();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void slote4();

    virtual void slote8();

    virtual void slotec();

    virtual void slotf0();

    virtual void slotf4();

    virtual void slotf8();

    virtual void slotfc();

    virtual void slot100();

    virtual void slot104();

    virtual void slot108();

    virtual void slot10c();

    virtual void slot110();

    virtual void slot114();

    virtual void slot118();

    virtual void slot11c();

    virtual void slot120();

    virtual void slot124();

    virtual void slot128();

    virtual void slot12c();

    virtual const char* Name();

    bool FUN_004013e0();
    unsigned int FUN_0084e3a0();
    void* FUN_007af430();
    Vector* FUN_00430830();
    Cell* FUN_008d6f30();
};

struct Node
{
    bool FUN_008256d0();
    Reference** FUN_006815c0();
    Node* FUN_00726070();
};

struct Pointer
{
    Reference* object;
    Reference* FUN_00559450();
    Reference* FUN_00458b50();
    ~Pointer();
};
struct Collection
{
    unsigned int GetReferenceFlags();
    Pointer FUN_00464f60(unsigned int);
};

struct World
{
    bool FUN_004623f0(bool);
    void ApplyUnloadedChanges(Reference*);
};
extern World* DAT_011ddf38;

struct Manager
{
    void FUN_00858730(Reference*);
    bool FUN_0047c850();
    void FUN_00859690(Cell*);
    bool FUN_008727b0();
    void FUN_004534f0(bool);
    void FUN_00858af0(int, int, int);
    void FUN_0085f850(int);
};
extern Manager* DAT_011de45c;
extern void* DAT_011ca254;

extern char DAT_0102ece8, DAT_0102ec58, DAT_0102ebd0, DAT_0102eb60, DAT_0102eb10, DAT_01183028, DAT_0118a8d0;
extern double DAT_0101a6b0;

int FUN_0046e8a0();
void FUN_0043b2b0(int);
void FUN_004fffe0(int);
unsigned int FUN_00ec6130(const char*);
void FUN_005b5e40(const char*, ...);
void ResolveFormID(unsigned int*, int);
TESForm* LookupFormByID(unsigned int);
extern "C" void* __cdecl __RTDynamicCast(void*, int, void*, void*, int);

struct Cell : Reference
{

    unsigned int unk4, unk8, unkc, unk10, unk14;
    CellLoading::Name editorName;
    unsigned int unk20, unk24;
    Extra extra;

    bool FUN_00425fd0();
    void FUN_00484ab0(int);
    Cell* FUN_0054ddd0();
    int FUN_00544c60();
    int FUN_00544c30();
    unsigned int GetLightingTemplate();
    int FUN_00484e60(int);
    void FUN_00558b60(void*);
    Node* FUN_009604f0();
    Extras* GetExtraDataList();
    bool FUN_005516c0();
    Collection* FUN_0070ec90();
    void FUN_00542d40();
};

// @fnv 0x00542d40
void Cell::FUN_00542d40()
{

    if (!FUN_004013e0())
    {

        int saved = FUN_0046e8a0();
        FUN_0043b2b0(1);
        FUN_004fffe0(0);
        extra.FUN_00416be0(this);
        if (!FUN_00425fd0())
            editorName.FUN_00489100(0);
        FUN_00484ab0(1);

        if (editorName.FUN_00408da0() && FUN_00ec6130(editorName.FUN_00408da0()) > 33)
            FUN_005b5e40(&DAT_0102ece8, editorName.FUN_00408da0(), Name(), FUN_0084e3a0());

        FUN_0043b2b0(0);
        int errors = FUN_0046e8a0();
        FUN_004fffe0(saved);

        if (errors)
        {
            Cell* other = FUN_0054ddd0();
            if (!FUN_00425fd0())
            {
                if (other)
                    FUN_005b5e40(&DAT_0102ec58, Name(), FUN_0084e3a0(), FUN_00544c30(), FUN_00544c60(), other->Name(),
                                 other->FUN_0084e3a0());
                else
                    FUN_005b5e40(&DAT_0102ebd0, Name(), FUN_0084e3a0(), FUN_00544c30(), FUN_00544c60());
            }
            else
                FUN_005b5e40(&DAT_0102eb60, Name(), FUN_0084e3a0());
        }

        if (GetLightingTemplate())
        {
            unsigned int handle = GetLightingTemplate();
            ResolveFormID(&handle, FUN_00484e60(-1));
            BGSLightingTemplate* resolved = dynamic_cast<BGSLightingTemplate*>(LookupFormByID(handle));
            FUN_00558b60(resolved);
            if (!resolved && handle)
                FUN_005b5e40(&DAT_0102eb10, handle, Name(), FUN_0084e3a0());
        }
    }

    bool oldState = DAT_011ddf38->FUN_004623f0(false);
    Node* node = FUN_009604f0();
    Node* previous = 0;

    while (node && !node->FUN_008256d0())
    {
        Reference* reference = *node->FUN_006815c0();
        if (!reference->FUN_004013e0())
        {
            reference->Load();
            DAT_011de45c->FUN_00858730(reference);
            DAT_011ddf38->ApplyUnloadedChanges(reference);
        }

        if (FUN_00425fd0() && reference->FUN_007af430() == DAT_011ca254)
            GetExtraDataList()->FUN_00421a70(reference->FUN_00430830()->z * DAT_0101a6b0);

        if (!FUN_005516c0() && reference->FUN_008d6f30() != this)
        {
            if (previous)
                node = previous->FUN_00726070();
            else
                node = FUN_009604f0();
        }
        else
        {
            previous = node;
            node = node->FUN_00726070();
        }
    }

    if (FUN_0070ec90())
    {
        for (unsigned int i = 0; i < FUN_0070ec90()->GetReferenceFlags(); i++)
        {
            Pointer item = FUN_0070ec90()->FUN_00464f60(i);
            item.FUN_00559450()->Load();
            DAT_011ddf38->ApplyUnloadedChanges(item.FUN_00458b50());
        }
    }

    DAT_011ddf38->FUN_004623f0(oldState);

    if (DAT_011de45c->FUN_0047c850())
    {
        DAT_011de45c->FUN_00859690(this);
        if (!DAT_011de45c->FUN_0047c850() && DAT_011de45c->FUN_008727b0())
        {
            bool state = DAT_011de45c->FUN_0047c850();
            DAT_011de45c->FUN_004534f0(true);
            DAT_011de45c->FUN_00858af0(0, 0, 0);
            DAT_011de45c->FUN_0085f850(0);
            DAT_011de45c->FUN_004534f0(state);
        }
    }
}

}
