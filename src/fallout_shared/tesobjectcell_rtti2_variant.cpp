// src/fallout_shared/tesobjectcell_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectREFR). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesobjectcell_packet_rtti2_tesobjectcell.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();

class TESFormB54
{
  public:
    int FUN_00401170();
    bool FUN_00452440();
};
extern TESFormB54* DAT_011ca238;
extern TESFormB54* DAT_011ca230;

class TESObjectREFRB54
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsVf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual int IsVf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual bool IsVf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void Vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void Vf260();
    TESFormB54* FUN_007af430();
    void* FUN_005d43c0();
    bool FUN_00440da0();
    bool FUN_00440d80();
};
class Actor : public TESObjectREFRB54
{
};

struct NiPoint3B54
{
    NiPoint3B54(float fX, int iY, int iZ);
    float x, y, z;
};
struct ControllerB54
{
    void FUN_00a59c60(NiPoint3B54* pPoint);
};
struct NodeB54
{
    TESObjectREFRB54** FUN_006815c0();
    NodeB54* FUN_00726070();
};
class SceneB54;
struct ManagerB54
{
    bool FUN_00453490(SceneB54* pScene);
    void* FUN_00458be0(SceneB54* pScene, int i);
};
extern ManagerB54* DAT_011dea10;
struct SettingsB54
{
    bool FUN_0042ce10();
};
extern SettingsB54* g_BGSSaveLoadGame;
struct ModeB54
{
    bool FUN_0047c850();
};
extern ModeB54* DAT_011de45c;
struct ProcessListB54
{
    void FUN_0096f400(Actor* pActor);
};
extern ProcessListB54 DAT_011e0e80;
struct LoaderB54
{
    void QueueReference(TESObjectREFRB54* pRef, void* p, int i);
};
extern LoaderB54* DAT_011c3b3c;
void __cdecl FUN_005ac190(TESObjectREFRB54* pRef, void* p);
void __cdecl FUN_005ac750(TESObjectREFRB54* pRef, void* p, int iFlags);

class SceneB54
{
  public:
    ControllerB54* GetOrCreateWidget();
    void FUN_0054c740(int a, int b);
    bool FUN_0054df30();
    void RecalcLeveledActorBases(bool b);
    void ProcessCellReferences();
    void FUN_00541ac0();
    void CellRefLockLeave();
    NodeB54* FUN_009604f0();
    void FUN_00548880(TESObjectREFRB54* pRef, int i);
    void FUN_005535f0();
    void SetState(int i);
    void FUN_0054bcf0(bool bArg);
};

// @fnv 0x0054bcf0
void SceneB54::FUN_0054bcf0(bool bArg)
{
    ControllerB54* pController2 = GetOrCreateWidget();
    FUN_0054c740(0, 0);
    bool bState5 = FUN_0054df30();
    RecalcLeveledActorBases(bState5);
    if (((ManagerB54*)DAT_011dea10)->FUN_00453490(this))
    {
        if (pController2)
        {
            NiPoint3B54 kPoint_(0.0f, 0, 0);
            pController2->FUN_00a59c60(&kPoint_);
        }
        ProcessCellReferences();
    }
    else
    {
        FUN_00541ac0();
        int iPass4;
        void* pCell9 = ((ManagerB54*)DAT_011dea10)->FUN_00458be0(this, 0);
        NodeB54* pNode5 = FUN_009604f0();
        int iCountA = 0;
        iPass4 = 0;
        while (iPass4 < 2 && pNode5)
        {
            TESObjectREFRB54* pRef = *pNode5->FUN_006815c0();
            pNode5 = pNode5->FUN_00726070();
            if (!pNode5)
            {
                iPass4++;
                if (iPass4 < 2)
                    pNode5 = FUN_009604f0();
            }
            if (pRef)
            {
                bool bSpecial_2 = pRef->FUN_007af430() &&
                                  (pRef->FUN_007af430() == DAT_011ca238 || pRef->FUN_007af430() == DAT_011ca230);
                if (iPass4 == 0 && !bSpecial_2)
                    continue;
                if (iPass4 == 1 && bSpecial_2)
                    continue;
                iCountA++;
                if (!g_BGSSaveLoadGame->FUN_0042ce10())
                {
                    FUN_005ac190(pRef, pRef->FUN_005d43c0());
                    FUN_005ac750(pRef, pRef->FUN_005d43c0(), 0x1000);
                }
                bool bDisabled4 = false;
                bDisabled4 = pRef->FUN_00440da0();
                if (!bDisabled4 && !pRef->FUN_00440d80())
                {
                    if (pRef->IsVf100() && (!DAT_011de45c->FUN_0047c850() || DAT_011de45c->FUN_0047c850()))
                    {
                        Actor* pActor7 = dynamic_cast<Actor*>(reinterpret_cast< ::TESObjectREFR*>(pRef));
                        if (pActor7)
                        {
                            pActor7->Vf240();
                            ((ProcessListB54*)&DAT_011e0e80)->FUN_0096f400(pActor7);
                        }
                    }
                    else if (pRef->IsVf224())
                    {
                        TESObjectREFRB54* pTarget = pRef;
                        pTarget->Vf260();
                    }
                    ((LoaderB54*)DAT_011c3b3c)->QueueReference(pRef, pCell9, 0);
                    if (pRef->IsVf1d0())
                    {
                        bool bProcess3 = true;
                        if (pRef->FUN_007af430()->FUN_00401170() == 0x23)
                        {
                            TESFormB54* pBase2 = pRef->FUN_007af430();
                            if (pBase2->FUN_00452440())
                                bProcess3 = false;
                        }
                        if (bProcess3)
                            FUN_00548880(pRef, 0);
                    }
                }
            }
        }
        CellRefLockLeave();
    }
    if (bArg)
        FUN_005535f0();
    SetState(6);
}
