
// src/bsmenu/xuserinterface.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/xuserinterface.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption,
                                                           unsigned int uType);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

struct SettingBool
{
    unsigned char* Bool();
};

struct LockObj
{
    void Lock();
    void Unlock();
};

struct SettingStr
{
    const char* String();
};

struct Controls
{
    int FUN_00711e00();
    void RecreateDevice(int v);
};

struct OSGlobals
{
    unsigned int GetThreadId();
    Controls* GetInputControls();
};

extern SettingBool DAT_011deb3c;
extern LockObj DAT_011f6394;
extern SettingStr DAT_011d12b4;
extern SettingStr DAT_011d0cb4;
extern SettingStr DAT_011d06f4;
extern OSGlobals* DAT_011dea0c;
extern unsigned char DAT_011a3015;

unsigned char __cdecl FUN_00446e10();
int __cdecl FUN_004dc1e0();
void __cdecl FUN_0086a530();
int __cdecl FUN_0086a820();
unsigned char __cdecl ShowMessageBox(const char* a1, int a2, int a3, void* a4, int a5, int a6, float a7, float a8,
                                   const char* a9, const char* a10, const char* a11, int a12);

// @fnv 0x0086a580
int FUN_0086a580(const char* text, const char* caption, unsigned int flags)
{
    int result = 6;
    {
        signed char mode;

        if (*DAT_011deb3c.Bool())
        {
            signed char type = flags & 0xf;
            signed char ret;
            switch (type)
            {
            case 2:
                ret = 5;
                break;
            default:
                ret = 6;
                break;
            }
            return ret;
        }

        DAT_011f6394.Lock();
        mode = flags & 0xf;
        if (DAT_011a3015 && DAT_011dea0c && DAT_011dea0c->GetInputControls())
        {
            DAT_011a3015 = 0;
            {
                signed char kind = (signed char)0xff;
            }
            int a = 0;
            const char* c = 0;
            const char* d = 0;
            const char* b = 0;

            switch (mode)
            {
            case 3:
                b = DAT_011d12b4.String();
            case 4:
                c = DAT_011d0cb4.String();
                d = DAT_011d06f4.String();
                break;
            }

            if (mode == 2 || mode == 0 ||
                !ShowMessageBox(text, 0, 0, (void*)FUN_0086a530, a, FUN_0086a820(), 0.0f, 0.0f, c, d, b, 0))
            {
                if (!FUN_00446e10() || !FUN_004dc1e0())
                {
                    if (DAT_011dea0c && GetCurrentThreadId() != DAT_011dea0c->GetThreadId() &&
                        DAT_011dea0c->GetInputControls() && !DAT_011dea0c->GetInputControls()->FUN_00711e00())
                    {
                        DAT_011dea0c->GetInputControls()->RecreateDevice(1);
                    }
                    result = MessageBoxA(0, text, caption, flags);
                }
                else
                {
                    switch (mode)
                    {
                    case 2:
                        result = 5;
                        break;
                    case 3:
                    case 4:
                        result = 6;
                        break;
                    }
                }
            }
            DAT_011a3015 = 1;
        }
        else
        {
            if (!FUN_00446e10() || !FUN_004dc1e0())
            {
                if (DAT_011dea0c && GetCurrentThreadId() != DAT_011dea0c->GetThreadId() &&
                    DAT_011dea0c->GetInputControls() && !DAT_011dea0c->GetInputControls()->FUN_00711e00())
                {
                    DAT_011dea0c->GetInputControls()->RecreateDevice(1);
                }
                result = MessageBoxA(0, text, caption, flags);
            }
        }
    }

    DAT_011f6394.Unlock();
    return result;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct GameTimerRecord
{
    unsigned char m_ucFirstTimerByte;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;

    void FUN_00aa50a0();
};

// When m_ucFirstTimerByte is zero before incrementing, subtracts both stored values from GetTickCount() and stores the results.
// @fnv 0x00aa50a0
void GameTimerRecord::FUN_00aa50a0()
{
    if (m_ucFirstTimerByte++ == 0)
    {
        unsigned int uiTickCount = GetTickCount();
        m_uiFirstTimerValue = uiTickCount - m_uiFirstTimerValue;
        m_uiSecondTimerValue = uiTickCount - m_uiSecondTimerValue;
    }
}
