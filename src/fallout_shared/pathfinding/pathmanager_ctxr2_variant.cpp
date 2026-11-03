// fallout_shared/pathfinding/pathmanager_ctxr2_variant.cpp: free functions (1 function)

#include "pathmanager_decls.h"
class BSSpinLock_r006eb6b0
{
  public:
    void Lock(const char*);
    void Unlock();
};

class PathingActorData;

struct PathSlot
{
    int unk00;
    int unk04;
};

struct PathingRequest
{
    PathingActorData* FUN_006c9900();
};

struct PathWorkList
{
    int unk00[4];
    PathWorkList();
    ~PathWorkList();
    bool FUN_006ebde0();
};

struct PathIndex
{
    bool TryGetNextEntry(PathWorkList* list, PathingRequest** ref, int* out, bool flag);
};

struct FUN_006eb6b0_cls : public PathManagerImpl
{
    void CancelCurrentPathsAndPause(int id);
};

// @fnv 0x006eb6b0
void FUN_006eb6b0_cls::CancelCurrentPathsAndPause(int id)
{
    reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)
        ->Lock("PathManagerImpl::CancelCurrentPathsAndPause");
    PathingRequest* ref;
    int outA2;
    PathWorkList list3;
    while (!list3.FUN_006ebde0())
    {
        if (reinterpret_cast<PathIndex*>(reinterpret_cast<char*>(this) + 0x1480)
                ->TryGetNextEntry(&list3, &ref, &outA2, true))
        {
            if (reinterpret_cast<PathSlot*>(ref->FUN_006c9900())->unk04 == id)
            {
                reinterpret_cast<PathSlot*>(ref->FUN_006c9900())->unk04 = 0;
                reinterpret_cast<PathSlot*>(ref->FUN_006c9900())->unk00 = 0;
            }
        }
    }
    reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)->Unlock();
}
