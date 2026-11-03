
// src/tesregiondatasound_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/tesregiondatasound.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include "tesregiondatasound_decls.h"

struct FUN_004f4f90_node : BSSimpleList<unsigned int>
{
    unsigned int* FUN_006815c0();
    FUN_004f4f90_node* FUN_00726070();
    void FUN_00905330(unsigned int* out);
    void FUN_005ae3d0(unsigned int* out);
};

int __cdecl FUN_00944460(int, int);
int __cdecl LookupFormByID(unsigned int);

struct FUN_004f4f90_shell : TESRegionDataSound
{
    int FUN_004f4f90();
};

// @fnv 0x004f4f90
int FUN_004f4f90_shell::FUN_004f4f90()
{
    unsigned int found;
    FUN_004f4f90_node* node7 = (FUN_004f4f90_node*)&Battle;
    found = 0;
    if (node7 != 0 && *node7->FUN_006815c0() != 0)
    {
        while (node7 != 0 && *node7->FUN_006815c0() != 0)
        {
            if (FUN_00944460(0, 3) == 0 || found == 0)
            {
                found = *node7->FUN_006815c0();
            }
            node7 = node7->FUN_00726070();
        }
    }
    else
    {
        return 0;
    }
    if (found != 0)
    {
        ((FUN_004f4f90_node*)&Battle)->FUN_00905330(&found);
        ((FUN_004f4f90_node*)&Battle)->FUN_005ae3d0(&found);
        return LookupFormByID(found);
    }
    return 0;
}
