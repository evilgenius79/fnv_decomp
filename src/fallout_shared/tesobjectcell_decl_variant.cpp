
// src/fallout_shared/tesobjectcell_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005571a0: the skeleton of src/fallout_shared/tesobjectcell.cpp
// with declarations corrected to what the original code does (tesobjectcell_packet.h: class TESForm; class NiNode; -> class TESForm { public: virtual void TESFormV00();; tesobjectcell_packet.h: class TESObjectREFR { public: static BGSEncounterZ -> class TESObjectREFR : public TESForm { public: sta; tesobjectcell_packet.h: T& GetItem(); BSSimpleList* GetNext();). Move the function to its real unit once
// that unit declares it this way.

#include "tesobjectcell_packet_decl_tesobjectcell.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();

class TES
{
  public:
    void* FUN_00458be0(TESObjectCELL*, int);
};
extern TES* g_TES;
struct ModelLoader
{
    void QueueReference(TESObjectREFR*, void*, int);
};
extern ModelLoader* g_pModelLoader;
class TESBoundObject : public TESForm
{
};
class TESObjectSTAT : public TESBoundObject
{
};
extern TESObjectSTAT* DAT_011ca238;
extern TESObjectSTAT* DAT_011ca230;
// @fnv 0x005571a0
void TESObjectCELL::FUN_005571a0(bool active)
{
    CellRefLockEnter();
    void* list = g_TES->FUN_00458be0(this, 0);
    BSSimpleList<TESObjectREFR*>* terrain = FUN_009604f0();
    while (terrain)
    {
        TESObjectREFR* reference = terrain->FUN_006815c0();
        if (reference && (reference->FUN_007af430() == DAT_011ca238 || reference->FUN_007af430() == DAT_011ca230))
        {
            if (!reference->GetNiNode() || reference->FUN_005651e0())
            {
                if (!reference->FUN_00440da0() && !reference->IsDeleted() && (!active || reference->FUN_0056b250()))
                    g_pModelLoader->QueueReference(reference, list, 1);
            }
            else
            {
                if (reference->FUN_00440da0() || reference->IsDeleted())
                    reference->Set3D(0, true);
            }
        }
        terrain = terrain->FUN_00726070();
    }
    terrain = FUN_009604f0();
    while (terrain)
    {
        TESObjectREFR* other = terrain->FUN_006815c0();
        if (other && other->FUN_007af430() != DAT_011ca238 && other->FUN_007af430() != DAT_011ca230)
        {
            if (!other->GetNiNode() || other->FUN_005651e0())
            {
                if (!other->FUN_00440da0() && !other->IsDeleted() && (!active || other->FUN_0056b250()))
                    g_pModelLoader->QueueReference(other, list, 1);
            }
            else
            {
                if (other->FUN_00440da0() || other->IsDeleted())
                    other->Set3D(0, false);
            }
        }
        terrain = terrain->FUN_00726070();
    }
    CellRefLockLeave();
}
