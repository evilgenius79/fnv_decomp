
// src/fallout/misc/appmemory.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/appmemory.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

unsigned int gm_GetCurrentThreadId();
void FUN_0040fca0(unsigned long);
struct OSGlobals
{
    unsigned int FUN_0044edb0();
};
extern OSGlobals* g_osGlobals;
struct TES
{
    void FUN_00452490(int);
    bool FUN_00453a80();
    void FUN_004539a0(int, int);
};
extern TES* g_TES;
extern unsigned int DAT_011de70c;
struct ScrapHeapManager
{
    static ScrapHeapManager& Instance();
    void FreeAllBuffers();
};
struct Worker
{
    bool FUN_00529ea0();
    void PurgeUnusedModels(int);
};
Worker* FUN_00652110();
bool FUN_00652160();
int FUN_00652130();
void FUN_00652190();
void SetTlsFlag(int);
void FUN_00868d70(int);
void FUN_00c459d0(int);
void FUN_00aa7030();
struct RecursiveSpinLock
{
    bool FUN_0078d200();
    void FUN_0040fba0();
};
extern RecursiveSpinLock DAT_011f11a0;
struct IOManager
{
    unsigned int CallSlotMethod(int);
    void FUN_00866dc0(int);
    void CallElementAt(int);
};
extern IOManager* DAT_01202d98;
struct StateMachine
{
    int unknown000;
    int unknown004;
    int unknown008;
    int unknown00c;
    int unknown010;
    int unknown014;
    int unknown018;
    int unknown01c;
    int unknown020;
    int unknown024;
    int unknown028;
    int unknown02c;
    int unknown030;
    int unknown034;
    int unknown038;
    int unknown03c;
    int unknown040;
    int unknown044;
    int unknown048;
    int unknown04c;
    int unknown050;
    int unknown054;
    int unknown058;
    int unknown05c;
    int unknown060;
    int unknown064;
    int unknown068;
    int unknown06c;
    int unknown070;
    int unknown074;
    int unknown078;
    int unknown07c;
    int unknown080;
    int unknown084;
    int unknown088;
    int unknown08c;
    int unknown090;
    int unknown094;
    int unknown098;
    int unknown09c;
    int unknown0a0;
    int unknown0a4;
    int unknown0a8;
    int unknown0ac;
    int unknown0b0;
    int unknown0b4;
    int unknown0b8;
    int unknown0bc;
    int unknown0c0;
    int unknown0c4;
    int unknown0c8;
    int unknown0cc;
    int unknown0d0;
    int unknown0d4;
    int unknown0d8;
    int unknown0dc;
    int unknown0e0;
    int unknown0e4;
    int unknown0e8;
    int unknown0ec;
    int unknown0f0;
    int unknown0f4;
    int unknown0f8;
    int unknown0fc;
    int unknown100;
    int unknown104;
    int unknown108;
    int unknown10c;
    int unknown110;
    int unknown114;
    int unknown118;
    int unknown11c;
    int unknown120;
    int unknown124;
    int unknown128;
    int unknown12c;
    int unknown130;
    int state;
    int RunStep(void*, unsigned int, bool*);
};
// Runs one step of the state machine by index, setting *finished and returning the next step index.
// @fnv 0x00866a90
int StateMachine::RunStep(void* context, unsigned int step, bool* finished)
{
    *finished = true;
    bool mainThread = gm_GetCurrentThreadId() == g_osGlobals->FUN_0044edb0();
    switch (step)
    {
    case 0:
        DAT_011de70c = 0;
        if (mainThread)
            g_TES->FUN_00452490(0);
        break;
    case 1:
        ScrapHeapManager::Instance().FreeAllBuffers();
        break;
    case 2:
        if (FUN_00652110() && FUN_00652110()->FUN_00529ea0() && FUN_00652160())
        {
            if (FUN_00652130() == 1)
                FUN_00652110()->PurgeUnusedModels(0);
            FUN_00652190();
        }
        break;
    case 5:
        if (mainThread)
        {
            SetTlsFlag(0);
            if (g_TES->FUN_00453a80())
                step = step - 1;
            else
                g_TES->FUN_004539a0(1, 0);
            g_TES->FUN_00452490(0);
            SetTlsFlag(1);
            FUN_00868d70(1);
        }
        else
            break;
    case 4:
        if (DAT_011f11a0.FUN_0078d200())
        {
            FUN_00868d70(1);
            DAT_011f11a0.FUN_0040fba0();
        }
    case 3:
        FUN_00c459d0(1);
        break;
    case 6:
        if (mainThread)
            FUN_00aa7030();
        break;
    case 7:
        if (!*finished && mainThread)
        {
            *finished = true;
            break;
        }
    case 8:
        if (!mainThread)
        {
            state = 6;
            if (DAT_011de70c < 15000)
            {
                if (DAT_01202d98->CallSlotMethod(0) == gm_GetCurrentThreadId())
                {
                    DAT_01202d98->FUN_00866dc0(0);
                    DAT_01202d98->CallElementAt(0);
                }
                if (DAT_01202d98->CallSlotMethod(1) == gm_GetCurrentThreadId())
                {
                    DAT_01202d98->FUN_00866dc0(1);
                    DAT_01202d98->CallElementAt(1);
                }
                FUN_0040fca0(1);
                DAT_011de70c = DAT_011de70c + 1;
                step = step - 1;
                break;
            }
            else if (!*finished)
                *finished = true;
        }
        break;
    }
    return step + 1;
}

struct MemoryManager
{
    void CreateMemoryPool(unsigned int, unsigned int, const char*);
    void FUN_00866770();
};

// Calls CreateMemoryPool repeatedly with fixed numeric values and matching "Pool N" names.
// @fnv 0x00866770
void MemoryManager::FUN_00866770()
{
    CreateMemoryPool(8, 0x600000, "Pool 8");
    CreateMemoryPool(12, 0x500000, "Pool 12");
    CreateMemoryPool(16, 0x400000, "Pool 16");
    CreateMemoryPool(20, 0x400000, "Pool 20");
    CreateMemoryPool(24, 0x800000, "Pool 24");
    CreateMemoryPool(28, 0x400000, "Pool 28");
    CreateMemoryPool(32, 0x800000, "Pool 32");
    CreateMemoryPool(36, 0x300000, "Pool 36");
    CreateMemoryPool(40, 0x200000, "Pool 40");
    CreateMemoryPool(44, 0x400000, "Pool 44");
    CreateMemoryPool(48, 0x200000, "Pool 48");
    CreateMemoryPool(52, 0x300000, "Pool 52");
    CreateMemoryPool(56, 0x100000, "Pool 56");
    CreateMemoryPool(64, 0x200000, "Pool 64");
    CreateMemoryPool(72, 0xd00000, "Pool 72");
    CreateMemoryPool(76, 0x100000, "Pool 76");
    CreateMemoryPool(80, 0x300000, "Pool 80");
    CreateMemoryPool(92, 0x200000, "Pool 92");
    CreateMemoryPool(96, 0xf00000, "Pool 96");
    CreateMemoryPool(100, 0x100000, "Pool 100");
    CreateMemoryPool(104, 0x400000, "Pool 104");
    CreateMemoryPool(120, 0x400000, "Pool 120");
    CreateMemoryPool(128, 0x100000, "Pool 128");
    CreateMemoryPool(160, 0x200000, "Pool 160");
    CreateMemoryPool(192, 0x200000, "Pool 192");
    CreateMemoryPool(200, 0x300000, "Pool 200");
    CreateMemoryPool(208, 0x300000, "Pool 208");
    CreateMemoryPool(240, 0x300000, "Pool 240");
    CreateMemoryPool(256, 0x100000, "Pool 256");
    CreateMemoryPool(272, 0x200000, "Pool 272");
    CreateMemoryPool(288, 0x300000, "Pool 288");
    CreateMemoryPool(400, 0x100000, "Pool 400");
    CreateMemoryPool(448, 0x100000, "Pool 448");
    CreateMemoryPool(480, 0x400000, "Pool 480");
    CreateMemoryPool(508, 0x400000, "Pool 508");
    CreateMemoryPool(576, 0x200000, "Pool 576");
    CreateMemoryPool(596, 0x100000, "Pool 596");
}
