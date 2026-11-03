// fallout/interface/menus/messagemenu.cpp: DelStandIn, MessageMenu, MessageMenuHandler, KeyMenu and more (28 functions)

#include "MessageMenu.h"

static const int kGetClassValue = 1001;

// @fnv 0x007a8aa0
int MessageMenu::GetClass()
{
    return kGetClassValue;
}

void __cdecl FUN_007aa6b0(bool);

// @fnv 0x00703fe0
void __cdecl FUN_00703fe0(bool abDisable)
{
    FUN_007aa6b0(abDisable);
}

struct Menu_007a8b10
{
    char pad[0x3c];
    virtual ~Menu_007a8b10();
};
struct Member_007a8b10
{
    char pad[4];
    ~Member_007a8b10();
};
struct FUN_007a8b10 : public Menu_007a8b10
{
    Member_007a8b10 m40;
    virtual ~FUN_007a8b10();
};
extern bool DAT_0119f348;
extern bool DAT_011da4ed;
extern bool DAT_011da4ee;
extern int DAT_011da4f0;
// Destructor that sets DAT_0119f348 to true, clears DAT_011da4f0, and if DAT_011da4ed is set, sets DAT_011da4ee to true.
// @fnv 0x007a8b10
FUN_007a8b10::~FUN_007a8b10()
{
    DAT_0119f348 = true;
    DAT_011da4f0 = 0;
    if (DAT_011da4ed)
        DAT_011da4ee = true;
}

namespace fnv_007a8df0 {
class Tile
{
  public:
    void Set(int, int);
};

class Interface
{
  public:
    static bool __cdecl IsInDialog(void);
};

class PlayerCharacter
{
  public:
    static bool __cdecl UpdatePlayerStatus(void);
};

extern void* DAT_011da4f0;
Tile* __fastcall _ref_00726070(void*);
int __cdecl FUN_00707ad0();
void __fastcall FUN_00a1d9e0(void*);
void __fastcall FUN_00a1d910(void*);
void __cdecl SetDialogMenuActive(int);

// @fnv 0x007a8df0
void __cdecl FUN_007a8df0()
{
    if (DAT_011da4f0)
    {
        _ref_00726070(DAT_011da4f0)->Set(0x1772, 1);
        if (FUN_00707ad0())
            FUN_00a1d9e0(DAT_011da4f0);
        else
            FUN_00a1d910(DAT_011da4f0);

        if (Interface::IsInDialog() && !PlayerCharacter::UpdatePlayerStatus())
            SetDialogMenuActive(0);
    }
}
}  // namespace fnv_007a8df0

// @fnv 0x007a9280
char __fastcall GetByteAtOffset56(char* pThis)
{
    return pThis[0x38];
}

class TESObjectREFR
{
  public:
    unsigned int GetFlags();
};

template <> class BSSimpleArray<unsigned int, 1024>
{
  public:
    unsigned int& GetAt(unsigned int);
};

extern unsigned int DAT_011da4f4;
extern BSSimpleArray<unsigned int, 1024> g_011da53c;

// Returns the element at index DAT_011da4f4 from g_011da53c if that index is below the object's flags, otherwise 0.
// @fnv 0x007a92a0
unsigned int __cdecl GetCurrentArrayElement()
{
    unsigned int uiResult = 0;
    if (DAT_011da4f4 < reinterpret_cast<TESObjectREFR*>(&g_011da53c)->GetFlags())
    {
        uiResult = g_011da53c.GetAt(DAT_011da4f4);
    }
    return uiResult;
}

namespace fnv_007aa070 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_007aa070_shell : public MessageMenu
{
    void HandleTileSelection(int, Tile*);
};

void* __cdecl FUN_004b7210(void);
void* __cdecl GetCurrentArrayElement(void);
void __cdecl CleanupGlobalObject(void);
extern bool DAT_011da4ed;
extern bool DAT_011da4ee;

class PerkForm;
template <class T> class ListBox
{
  public:
    T GetSelectedData(Tile*);
};

// Resolves a tile by ID when none is given, and for ID 7 stores the list-box result into a global and runs the selection callbacks.
// @fnv 0x007aa070
void FUN_007aa070_shell::HandleTileSelection(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 6)
    {
        apTarget = ((Tile**)((char*)this + 0x28))[aiID];
    }
    if (aiID == 7 && apTarget)
    {
        *(unsigned char*)((char*)FUN_004b7210() + 0xe4) =
            (unsigned char)(int)((ListBox<PerkForm*>*)((char*)this + 0x40))->GetSelectedData(apTarget);
        DAT_011da4ed = true;
        if (GetCurrentArrayElement() && *(void(__cdecl**)())((char*)GetCurrentArrayElement() + 0x28))
        {
            (*(void(__cdecl**)())((char*)GetCurrentArrayElement() + 0x28))();
        }
        DAT_011da4ed = false;
        if (DAT_011da4ee)
        {
            DAT_011da4ee = false;
        }
        else
        {
            CleanupGlobalObject();
        }
    }
}
}  // namespace fnv_007aa070

namespace fnv_007aa480 {
struct Elem_007aa480
{
    int Destroy(bool);
};
struct GlobalObject_007ab590
{
    unsigned int GetFlags();
    unsigned int& GetAt(int);
    void Clear(bool);
};
extern GlobalObject_007ab590 g_011da53c;
extern int DAT_011da4f4;
// Iterates the global object's elements, calls Destroy(true) on each non-null one, then clears the object and resets DAT_011da4f4 to 0.
// @fnv 0x007aa480
void ClearAllElements()
{
    for (unsigned int i = 0; i < g_011da53c.GetFlags(); i++)
    {
        Elem_007aa480* p;
        unsigned int v = g_011da53c.GetAt(i);
        p = reinterpret_cast<Elem_007aa480*>(v);
        p ? p->Destroy(true) : 0;
    }
    g_011da53c.Clear(true);
    DAT_011da4f4 = 0;
}
}  // namespace fnv_007aa480

namespace fnv_007aa530 {
struct Elem_007aa530
{
    int Destroy(bool);
};
struct Obj_007aa530
{
    void PopulateFromMessageData();
};
struct GlobalObject_007ab590
{
    unsigned int& GetAt(int);
    void Remove(unsigned int, bool);
};
extern GlobalObject_007ab590 g_011da53c;
extern int DAT_011da4f4;
extern Obj_007aa530* DAT_011da4f0;
int __cdecl GetCurrentArrayElement();
void __cdecl FUN_007a8df0();
// @fnv 0x007aa530
void CleanupGlobalObject()
{
    unsigned int u;
    if (GetCurrentArrayElement())
    {
        u = g_011da53c.GetAt(DAT_011da4f4);
        Elem_007aa530* p;
        unsigned int v = u;
        p = reinterpret_cast<Elem_007aa530*>(v);
        p ? p->Destroy(true) : 0;
        g_011da53c.Remove(DAT_011da4f4, true);
    }
    if (!GetCurrentArrayElement())
        FUN_007a8df0();
    else if (DAT_011da4f0)
        DAT_011da4f0->PopulateFromMessageData();
}
}  // namespace fnv_007aa530

namespace fnv_007aa6b0 {
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c3ea4;
extern bool DAT_011da4ec;
extern int DAT_011da4f0;
void __cdecl FUN_007a8df0();
void __cdecl FUN_007a8ba0();
int __cdecl GetCurrentArrayElement();
void __cdecl FUN_00709470(int, int, int, int, int, int);
// Stores the flag in DAT_011da4ec and calls FUN_007a8df0 or FUN_007a8ba0/FUN_00709470 depending on DAT_011da4f0 and GetCurrentArrayElement.
// @fnv 0x007aa6b0
void FUN_007aa6b0(bool a)
{
    DAT_011da4ec = a;
    if (DAT_011da4f0 && DAT_011da4ec)
        FUN_007a8df0();
    if (!DAT_011da4f0 && !DAT_011da4ec && GetCurrentArrayElement())
    {
        if (*g_011c3ea4.Int() > 1)
            FUN_00709470(7, 0, 0, 0, 1, 0);
        else
            FUN_007a8ba0();
    }
}
}  // namespace fnv_007aa6b0

struct Al_007ab000
{
    char c;
};
struct Str_007ab000
{
    char data[0x1c];
    ~Str_007ab000();
    Str_007ab000(const Str_007ab000&, unsigned int, unsigned int, const Al_007ab000&);
    Al_007ab000 FUN_007ab230() const;
    Str_007ab000 Substr(unsigned int _Off, unsigned int _Count) const;
};
// Returns a copy of the string constructed from this, _Off, _Count and the result of FUN_007ab230().
// @fnv 0x007ab000
Str_007ab000 Str_007ab000::Substr(unsigned int _Off, unsigned int _Count) const
{
    return Str_007ab000(*this, _Off, _Count, FUN_007ab230());
}

struct FUN_007abdb0_shell : public MessageMenu
{
    bool FUN_007abdb0();
};

// Checks the six int entries at offset 0x28 and returns true only if none of them is zero.
// @fnv 0x007abdb0
bool FUN_007abdb0_shell::FUN_007abdb0()
{
    for (int i = 0; i < 6; ++i)
    {
        if (*((int*)((char*)this + 0x28) + i) == 0)
            return false;
    }
    return true;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_007a8ae0(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007a8ae0
void* DelStandIn::FUN_007a8ae0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_007aa500 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007aa500
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_007aa500

struct StrMem
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    StrMem();
    ~StrMem();
};
class Tile
{
  public:
    float GetFloat(int aiTrait);
};
struct InterfaceManager
{
    Tile* FUN_004fd400();
};
InterfaceManager* __cdecl FUN_004b7210();
int __cdecl TraitNameToID(const char* apTraitName);
struct FUN_007a8850
{
    StrMem strMessage;
    int iIcon;
    StrMem m_kTitle;
    StrMem strButtonText;
    bool bHasButtons;
    StrMem m_kSecondaryButtonText;
    int iButtonCount;
    int iType;
    StrMem strSound;
    bool bPauseGame;
    int iTileID;
    int iCallbackID;
    float fDisplayTime;
    float fBackgroundAlpha;
    int iFlags;
    FUN_007a8850();
};
// @fnv 0x007a8850
FUN_007a8850::FUN_007a8850()
{
    iIcon = 0;
    bHasButtons = false;
    iButtonCount = 0;
    iType = 0;
    bPauseGame = true;
    iTileID = -1;
    iCallbackID = -1;
    fDisplayTime = 0.0f;
    fBackgroundAlpha = FUN_004b7210()->FUN_004fd400()->GetFloat(TraitNameToID("_background_fill_alpha"));
    iFlags = 0;
}

// @fnv 0x007a8de0
int FUN_007a8de0()
{
    return 1001;
}

extern char DAT_01202d54;

// @fnv 0x007aa6a0
void FUN_007aa6a0(unsigned char value)
{
    DAT_01202d54 = value;
}

namespace fnv_007aaf20 {
struct ArrSI
{
    unsigned int __thiscall GetFlags(void);
};

extern unsigned int DAT_011da4f4;
extern unsigned char DAT_011da4ec;
extern unsigned char DAT_011da594;
extern void __cdecl FUN_007a8df0(void);
extern void __cdecl FUN_007aa6b0(unsigned char);
extern ArrSI g_011da53c;

// @fnv 0x007aaf20
void __cdecl FUN_007aaf20(bool abFlag)
{
    if (abFlag)
    {
        DAT_011da4f4 = g_011da53c.GetFlags();
        FUN_007a8df0();
        DAT_011da594 = DAT_011da4ec;
        FUN_007aa6b0(0);
    }
    else
    {
        DAT_011da4f4 = 0;
        FUN_007aa6b0(DAT_011da594);
    }
}
}  // namespace fnv_007aaf20

struct Arr
{
    unsigned int* GetAt(int);
};

struct FUN_006f2270
{
    int m0;
    int m1;
    int m2;
    unsigned int* GetLast();
};

// @fnv 0x006f2270
unsigned int* FUN_006f2270::GetLast()
{
    return ((Arr*)this)->GetAt(m2 - 1);
}

struct FUN_007aafe0_Class
{
    void FUN_007aafe0(void* ap1, void* ap2);
    void FindSubstring(void* p, void* q, int n);
};

// @fnv 0x007aafe0
void FUN_007aafe0_Class::FUN_007aafe0(void* pFirst, void* pSecond)
{
    FindSubstring(&pFirst, pSecond, 1);
}

struct MessageMenuHandler
{
    void FUN_007ab0a0(void* first, void* second, void* third, unsigned int derivedValue);
    void FUN_007aaf80(void* first, void* second, void* third);
};

unsigned int __cdecl FUN_0044a670(void* value);

// Calls FUN_007ab0a0 with the three arguments and the value returned by FUN_0044a670(third).
// @fnv 0x007aaf80
void MessageMenuHandler::FUN_007aaf80(void* first, void* second, void* third)
{
    FUN_007ab0a0(first, second, third, FUN_0044a670(third));
}

void __cdecl FUN_00ec7c56(void);

struct FUN_007aafb0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int __thiscall FUN_0044a970();
    int __thiscall FUN_007aafb0(unsigned int arg);
};

// If arg exceeds unk14, calls FUN_00ec7c56; then returns the result of FUN_0044a970() plus arg.
// @fnv 0x007aafb0
int __thiscall FUN_007aafb0_Class::FUN_007aafb0(unsigned int arg)
{
    if (arg > unk14)
    {
        FUN_00ec7c56();
    }

    do
    {
    } while (0);

    return this->FUN_0044a970() + arg;
}

namespace MessageCreation {
struct String
{
    char* data;
    unsigned short length, capacity;
    String(const char*);
    ~String();
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
    unsigned int FUN_004048e0();
    const char* FUN_00559450();
};
struct Text
{
    unsigned int allocator;
    char buffer[16];
    unsigned int length, capacity;
    Text(const char*);
    ~Text();
    unsigned int FUN_007aafe0(char, unsigned int);
    Text Substr(unsigned int, unsigned int);
    const char* FUN_0044a560();
    void FUN_007aaf80(unsigned int, unsigned int, const char*);
};
struct Message
{
    String message;
    char* icon;
    String title;
    String buttons;
    bool hasButtons;
    String hotkeys;
    int buttonCount, type;
    String sound;
    bool pause;
    int tileID, callback;
    float displayTime, alpha;
    unsigned int flags;
    Message();
    bool GetByteAtOffset56();
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* FormHeap_Allocate(unsigned int);
int FUN_0044a670(const char*);
void FUN_00406d30(char*, unsigned int, const char*);
int FUN_00408b20(const char*, const char*);
extern const char DAT_01011584[], DAT_01020770[], DAT_01063d7c[];
extern const double DAT_01017b70, DAT_01012060, DAT_0101e568;
extern unsigned int DAT_010173f0;
struct Messages
{
    unsigned int FUN_0044ddc0();
    Message** FUN_00877a30(unsigned int);
    Message** FUN_006f2270();
    void FUN_006f23d0(unsigned int, Message* const&);
    void FUN_007cb2e0(Message* const&);
};
extern Messages DAT_011da53c;
extern int DAT_011da4f0;
extern bool DAT_011da4ec, DAT_011da4ef;
struct Setting
{
    int* FUN_0043d4d0();
};
extern Setting DAT_011c3ea4;
bool FUN_007050d0();
void FUN_00709470(int, int, int, int, int, bool);
void FUN_007a8ba0();
// Builds a Message from the given title, text, icon, sound and buttons, inserts it into the message queue, and triggers the display update.
// @fnv 0x007a8e60
bool QueueMessage(const char* title, const char* message, const char* icon, const char* sound, int buttonCount,
                  bool hasButtons, int type, const char* firstButton, const char*** arguments, bool pause, int tileID,
                  int callback, float time, float alpha, float flags)
{
    Message* info = new Message;
    String buttonSlot11(firstButton);
    info->buttonCount = buttonCount;
    info->hasButtons = hasButtons;
    info->type = type;
    info->message.FUN_00438390(message);
    info->hotkeys.FUN_00438390(DAT_01011584);
    info->title.FUN_00438390(title);
    info->sound.FUN_00438390(sound);
    info->pause = pause;
    info->tileID = tileID;
    info->callback = callback;
    info->displayTime = time * DAT_01017b70;
    if (alpha > DAT_01012060)
        info->alpha = alpha * DAT_0101e568;
    info->flags = (unsigned int)flags;
    int iconLengthSlot11 = icon ? FUN_0044a670(icon) : 0;
    if (iconLengthSlot11 > 0)
    {
        info->icon = new char[iconLengthSlot11 + 1];
        FUN_00406d30(info->icon, iconLengthSlot11 + 1, icon);
    }
    else
        info->icon = 0;
    while (buttonSlot11.FUN_004048e0() > 0)
    {
        Text text(buttonSlot11.FUN_00559450());
        unsigned int hotkeySlot0 = text.FUN_007aafe0('&', 0);
        if (hotkeySlot0 != DAT_010173f0)
        {
            info->hotkeys.FUN_00404820(text.Substr(hotkeySlot0 + 1, 1).FUN_0044a560());
            text.FUN_007aaf80(hotkeySlot0, 1, DAT_01011584);
        }
        if (FUN_00408b20(text.FUN_0044a560(), DAT_01020770))
            info->buttons.FUN_00404820(text.FUN_0044a560());
        info->buttons.FUN_00404820(DAT_01063d7c);
        buttonSlot11.FUN_00438390((*arguments += 1)[-1]);
    }
    if (DAT_011da53c.FUN_0044ddc0())
    {
        for (unsigned int index = 0; index < DAT_011da53c.FUN_0044ddc0(); index++)
        {
            if (!(*DAT_011da53c.FUN_00877a30(index))->GetByteAtOffset56() && info->GetByteAtOffset56())
            {
                DAT_011da53c.FUN_006f23d0(index, info);
                break;
            }
            else if (*DAT_011da53c.FUN_00877a30(index) == *DAT_011da53c.FUN_006f2270())
            {
                DAT_011da53c.FUN_007cb2e0(info);
                break;
            }
        }
    }
    else
        DAT_011da53c.FUN_007cb2e0(info);
    if (!DAT_011da4f0 && !DAT_011da4ec && (!FUN_007050d0() || pause))
    {
        if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
            FUN_00709470(7, 0, 0, 0, 1, !info->GetByteAtOffset56());
        else
            FUN_007a8ba0();
    }
    else
        DAT_011da4ef = true;
    return true;
}
}

struct KeyText
{
    unsigned int FUN_004048e0();
    const char* FUN_00559450();
    int unk00, unk04, unk08;
};
struct KeyBinding
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    KeyText text;
    int type;
};
struct KeyString
{
    int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    KeyString(const char*);
    ~KeyString();
    unsigned int FUN_00825c00();
    char& FUN_007aafb0(unsigned int);
};
extern "C" int __cdecl toupper(int);
struct KeyedList
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void* At(unsigned int, bool);
    unsigned int GetRaceCount();
    void* CallVirtualZero();
};
struct KeyMenu
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Select(int, void*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    KeyedList buttons;
    bool HandleKeyInput(int);
};
// @fnv 0x007aa110
bool KeyMenu::HandleKeyInput(int key)
{
    bool handled = false;
    if (GetCurrentArrayElement())
    {
        if (key == 1 && ((KeyBinding*)GetCurrentArrayElement())->type != 23)
        {
            Select(7, buttons.At(buttons.GetRaceCount() - 1, false));
            handled = true;
        }
        else if (key == 32)
        {
            Select(-1, buttons.CallVirtualZero());
            handled = true;
        }
        else if (((KeyBinding*)GetCurrentArrayElement())->text.FUN_004048e0() > 0)
        {
            KeyString text(((KeyBinding*)GetCurrentArrayElement())->text.FUN_00559450());
            for (unsigned int index = 0; index < text.FUN_00825c00(); index++)
            {
                if (toupper(text.FUN_007aafb0(index)) == toupper(key))
                {
                    Select(7, buttons.At(index, false));
                    handled = true;
                    break;
                }
            }
        }
    }
    return handled;
}

struct FUN_007aa2a0_shell : MessageMenu
{
    void UpdateMenuAction();
    int FUN_0059bb30();
    void FUN_00a1db20();
    void FUN_00a1d910();
    void* FUN_00726070(int, int);
};
struct TimerCalls
{
    void FUN_00771520();
    unsigned int FUN_00825c00();
};
struct TileCalls
{
    bool IsTraitNonZero(int);
};
struct MenuActionCalls
{
    void FUN_00700320();
};
void __cdecl CleanupGlobalObject();
extern double DAT_01012060;
// @fnv 0x007aa2a0
void FUN_007aa2a0_shell::UpdateMenuAction()
{
    reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00771520();
    static unsigned int lastCheckTime = reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00();
    if (reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00() - lastCheckTime < 200)
        return;
    {
        lastCheckTime = reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00();
        if (GetCurrentArrayElement())
        {
            if (static_cast<unsigned char>(GetByteAtOffset56(reinterpret_cast<char*>(GetCurrentArrayElement()))) == 0)
            {
                if (reinterpret_cast<TileCalls*>(m_pTiles[0])->IsTraitNonZero(0xfa3))
                {
                    if (FUN_0059bb30() == 4)
                    {
                        if (m_uiMessageCount == 0)
                        {
                            FUN_00a1db20();
                        }
                        else
                        {
                            CleanupGlobalObject();
                            m_uiMessageCount = 0;
                        }
                    }
                    else
                    {
                        if (FUN_0059bb30() == 1)
                        {
                            unsigned int message = GetCurrentArrayElement();
                            if (!m_uiMessageCount)
                                m_uiMessageCount = reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00();
                            if (*reinterpret_cast<float*>(message + 0x44) > DAT_01012060)
                            {
                                if (*reinterpret_cast<float*>(message + 0x44) <=
                                    (unsigned int)(reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00() -
                                                   m_uiMessageCount))
                                {
                                    if (message == *reinterpret_cast<FUN_006f2270*>(&g_011da53c)->GetLast())
                                    {
                                        reinterpret_cast<MenuActionCalls*>(FUN_00726070(0x1772, 1))->FUN_00700320();
                                        CleanupGlobalObject();
                                    }
                                    else
                                    {
                                        FUN_00a1d910();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct ActionMenuReference;
struct ActionMenuStoredString
{
    char* data;
    unsigned short size, capacity;
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
};
struct ActionMenuText
{
    char* data;
    unsigned unk04, unk08, unk0C, unk10, size, capacity;
    ActionMenuText(const char*);
    ~ActionMenuText();
    unsigned FUN_007aafe0(char, unsigned);
    ActionMenuText Substr(unsigned, unsigned);
    const char* FUN_0044a560();
    void FUN_007aaf80(unsigned, unsigned, const char*);
};
struct ActionMenuInfo
{
    ActionMenuStoredString message;
    int icon;
    ActionMenuStoredString title, buttons;
    bool hasButtons;
    ActionMenuStoredString hotkeys;
    void (*callback)();
    int type;
    ActionMenuStoredString sound;
    int pause, tile, callbackId;
    float displayTime, backgroundAlpha;
    int flags;
    ActionMenuInfo();
};
struct ActionMenuSetting
{
    const char* FUN_00403df0();
};
struct ActionMenuCountSetting
{
    int* FUN_0043d4d0();
};
struct ActionMenuBase
{
    unsigned FUN_00401170();
};
struct ActionMenuOwner
{
    bool FUN_005021a0();
};
struct ActionMenuReference
{
    int FUN_00579280();
    ActionMenuBase* FUN_007af430();
    ActionMenuOwner* FUN_00569160();
    bool FUN_00579690();
    bool FUN_005785e0(ActionMenuReference*, bool);
};
struct ActionMenuAction
{
    virtual void Slot0();
    virtual int GetKind();
    const char* FUN_00726070();
    int FUN_00413f40();
};
struct ActionMenuList
{
    bool FUN_008256d0();
    ActionMenuAction** FUN_006815c0();
    ActionMenuList* FUN_00726070();
};
struct ActionMenuEntry
{
    const char* label;
    int action;
    ActionMenuReference* reference;
};
template <class T> struct ActionMenuQueue
{
    void FUN_007cb2e0(T const&);
};
extern ActionMenuQueue<ActionMenuEntry*> DAT_011da524;
extern ActionMenuQueue<ActionMenuInfo*> DAT_011da53c;
extern int DAT_011da4f0;
extern bool DAT_011da4ec;
extern ActionMenuCountSetting DAT_011c3ea4;
extern ActionMenuSetting DAT_011d2280, DAT_011d3708, DAT_011d4f48, DAT_011d38dc, DAT_011d45a0, DAT_011d22b0,
    DAT_011d29f4;
extern ActionMenuSetting* DAT_011d5160[];
extern ActionMenuReference* DAT_011dea3c;
extern const char DAT_01011584[], DAT_01020770[], DAT_01063d7c[];
extern const unsigned DAT_010173f0;
void FUN_007aae70();
void FUN_007a8ba0();
void FUN_00709470(int, int, int, int, int, int);
void FUN_00406d30(char*, unsigned, const char*);
unsigned FUN_0044a670(const char*);
int FUN_00408b20(const char*, const char*);
int FUN_0047b250(ActionMenuReference*);
bool FUN_00518f00(ActionMenuReference*, ActionMenuReference*, int, int);
// Builds an ActionMenuInfo with title, hotkeys and buttons from the list's actions and the reference's action type, queues entries and the menu, and opens it.
// @fnv 0x007aa720
bool BuildActionMenu(ActionMenuList* list, ActionMenuReference* reference)
{
    ActionMenuInfo* menu4 = new ActionMenuInfo;
    menu4->callback = FUN_007aae70;
    menu4->hasButtons = false;
    menu4->type = 0;
    menu4->message.FUN_00438390(0);
    menu4->hotkeys.FUN_00438390(DAT_01011584);
    menu4->title.FUN_00438390(DAT_011d2280.FUN_00403df0());
    char label58[260];
    while (list && !list->FUN_008256d0())
    {
        FUN_00406d30(label58, 260, (*list->FUN_006815c0())->FUN_00726070());
        if ((*list->FUN_006815c0())->GetKind() == 4)
        {
            if (!(*list->FUN_006815c0())->FUN_00726070() || !(*list->FUN_006815c0())->FUN_00413f40())
            {
                list = list->FUN_00726070();
                continue;
            }
            ActionMenuEntry* entry29 = new ActionMenuEntry;
            entry29->label = (*list->FUN_006815c0())->FUN_00726070();
            entry29->action = (*list->FUN_006815c0())->FUN_00413f40();
            entry29->reference = reference;
            DAT_011da524.FUN_007cb2e0(entry29);
            if (FUN_0044a670(label58) > 0)
            {
                ActionMenuText text6(label58);
                unsigned hotkey5 = text6.FUN_007aafe0('&', 0);
                if (hotkey5 != DAT_010173f0)
                {
                    menu4->hotkeys.FUN_00404820(text6.Substr(hotkey5 + 1, 1).FUN_0044a560());
                    text6.FUN_007aaf80(hotkey5, 1, DAT_01011584);
                }
                if (FUN_00408b20(text6.FUN_0044a560(), DAT_01020770))
                {
                    menu4->buttons.FUN_00404820(text6.FUN_0044a560());
                    menu4->buttons.FUN_00404820(DAT_01063d7c);
                }
            }
        }
        list = list->FUN_00726070();
    }
    int action3 = reference->FUN_00579280();
    unsigned type22 = reference->FUN_007af430()->FUN_00401170();
    ActionMenuOwner* owner15 = reference->FUN_00569160();
    ActionMenuBase* base7 = reference->FUN_007af430();
    if (action3 == 1 && reference->FUN_00579690())
    {
        FUN_00406d30(label58, 260, type22 == 42 ? DAT_011d3708.FUN_00403df0() : DAT_011d4f48.FUN_00403df0());
    }
    else if (action3 == 2 && (type22 == 42 || type22 == 43))
    {
        FUN_00406d30(label58, 260, DAT_011d38dc.FUN_00403df0());
    }
    else if (action3 == 8 && type22 == 28)
    {
        bool isChair = FUN_0047b250(reference) == 1 || FUN_0047b250(reference) == 2;
        if (owner15 && owner15->FUN_005021a0() && !reference->FUN_005785e0(DAT_011dea3c, true) &&
            (!base7 || !FUN_00518f00(reference, DAT_011dea3c, 0, 1)))
        {
            FUN_00406d30(label58, 260, DAT_011d45a0.FUN_00403df0());
        }
        else
        {
            FUN_00406d30(label58, 260, isChair ? DAT_011d22b0.FUN_00403df0() : DAT_011d5160[action3]->FUN_00403df0());
        }
    }
    else if (action3 && action3 < 20)
    {
        FUN_00406d30(label58, 260, DAT_011d5160[action3]->FUN_00403df0());
    }
    else if (action3 == 0)
    {
        FUN_00406d30(label58, 260, DAT_011d29f4.FUN_00403df0());
    }
    if (FUN_0044a670(label58) > 0)
    {
        ActionMenuText text6(label58);
        unsigned hotkey5 = text6.FUN_007aafe0('&', 0);
        if (hotkey5 != DAT_010173f0)
        {
            menu4->hotkeys.FUN_00404820(text6.Substr(hotkey5 + 1, 1).FUN_0044a560());
            text6.FUN_007aaf80(hotkey5, 1, DAT_01011584);
        }
        if (FUN_00408b20(text6.FUN_0044a560(), DAT_01020770))
        {
            menu4->buttons.FUN_00404820(text6.FUN_0044a560());
            menu4->buttons.FUN_00404820(DAT_01063d7c);
        }
    }
    ActionMenuEntry* entry29 = new ActionMenuEntry;
    entry29->label = label58;
    entry29->action = 0;
    entry29->reference = reference;
    DAT_011da524.FUN_007cb2e0(entry29);
    DAT_011da53c.FUN_007cb2e0(menu4);
    if (!DAT_011da4f0 && !DAT_011da4ec)
    {
        if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
            FUN_00709470(7, 0, 0, 0, 1, 0);
        else
            FUN_007a8ba0();
    }
    return true;
}

namespace MessageMenuSetup {

struct MsgTile
{
    void FUN_00a01350(int aiID, const char* apText, bool abPropagate);
    void FUN_00700320(int aiID, int aiValue);
    float FUN_00a011b0(int aiID);
    const char* FUN_00a011f0(int aiID);
    void FUN_00a012d0(int aiID, float afValue, bool abPropagate);
    MsgTile* FUN_00a03da0(const char* apName);
    bool IsTraitNonZero(int aiID);
};

struct MsgSize
{
    float x, y, z;
};

struct MsgFont
{
    MsgSize GetStringDimensions(const char* apText, int aiFont, float afWidth, int aiFlags);
};

struct MsgSound
{
    unsigned int unk0, unk4, unk8;
    ~MsgSound();
    bool IsNotEqual(int aiFlags);
    void Play(int aiFlags);
};

struct MsgAudio
{
    MsgSound FUN_00ad7550(const char* apEditorID, int aiFlags);
};

struct MsgText
{
    char* pString;
    unsigned short usLength;
    unsigned short usCapacity;
    unsigned int FUN_004048e0();
    const char* FUN_00559450();
};

struct MsgString
{
    char acData[0x1c];
    MsgString(const char* apText);
    ~MsgString();
    unsigned int FUN_00825c00();
    unsigned int FUN_005103a0(const char* apDelimiter, unsigned int auiStart);
    MsgString Substr(unsigned int auiStart, unsigned int auiLength);
    const char* FUN_0044a560();
};

struct MsgData
{
    MsgText kTitle;
    const char* pIcon;
    MsgText kText;
    MsgText kButtons;
    char cButtonBase;
    char pad1d[0xf];
    int iType;
    MsgText kSound;
    char pad38[4];
    int iX;
    int iY;
    char pad44[4];
    float fAlpha;
    unsigned int uiWidth;
    bool GetByteAtOffset56();
};

struct MsgList
{
    virtual void l000();
    virtual void l001();
    virtual void l002();
    virtual void l003();
    virtual void l004();
    virtual void l005();
    virtual void l006();
    virtual void Clear();
    MsgTile* FUN_00764430(int aiIndex, const char* apText, int a3, int a4);
    void RebuildVisibleTiles();
};

struct MsgInterface
{
    bool FUN_00714f90(int aiMenuID);
};

struct MsgMenu
{
    virtual void m000();
    virtual void m001();
    virtual void m002();
    virtual void m003();
    virtual void m004();
    virtual void m005();
    virtual void m006();
    virtual void m007();
    virtual void m008();
    virtual void m009();
    virtual void m00a();
    virtual void m00b();
    virtual void m00c();
    virtual int GetID();
    char pad04[0x24];
    MsgTile* m_pTiles[6];
    MsgList kButtons;
    MsgTile* FUN_00726070();
    void PopulateFromMessageData();
};

extern MsgMenu* DAT_011da4f0;
extern bool DAT_0119f348;
extern const char DAT_01063d7c[];
extern const float DAT_01016970;
MsgData* GetCurrentArrayElement();
MsgAudio* FUN_00453a70();
MsgFont* FUN_005bd5b0();
MsgInterface* FUN_004b7210();
int __cdecl TraitNameToID(const char* apTrait);
int __cdecl FUN_00647b70(int a, int b);
float __cdecl FUN_0040ebd0(float a, float b);
float __cdecl FUN_00404010(float a, float b);
float __cdecl FUN_00715d40();
float __cdecl FUN_00715da0();
float __cdecl FUN_00706e50();
float __cdecl FUN_00706e20();
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();
void __cdecl FUN_00706fd0(int aiMenuID, int aiFlag);
void __cdecl FUN_00706fb0(int aiMenuID, int aiFlag);

static const char s_szHorBuf[] = "_horbuf";
static const char s_szPopUp[] = "UIPopUpMessageWindow";
static const char s_szListItemText[] = "ListItemText";
static const char s_szMaxMenuWidth[] = "_MaxMenuWidth";
static const char s_szMinMenuWidth[] = "_MinMenuWidth";

// Populates message menu tiles and buttons, computes layout dimensions, and sets menu position and alpha from the current message data.
// @fnv 0x007a92e0
void MsgMenu::PopulateFromMessageData()
{
    if (!GetCurrentArrayElement())
        return;
    MsgData* pMessagePtr = GetCurrentArrayElement();
    float fIconHeightIn = 0.0f;
    float fTheTextHeight = 0.0f;
    float fButtonsWidth = 0.0f;
    float fWidths = 0.0f;
    float fHorBuf = FUN_00726070()->FUN_00a011b0(TraitNameToID(s_szHorBuf));
    if (pMessagePtr->kSound.FUN_004048e0() > 0 &&
        FUN_00453a70()->FUN_00ad7550(pMessagePtr->kSound.FUN_00559450(), 0x121).IsNotEqual(-1))
        FUN_00453a70()->FUN_00ad7550(pMessagePtr->kSound.FUN_00559450(), 0x121).Play(0);
    else
        FUN_00453a70()->FUN_00ad7550(s_szPopUp, 0x121).Play(0);
    DAT_011da4f0->m_pTiles[3]->FUN_00a01350(0xfc4, pMessagePtr->kText.FUN_00559450(), true);
    if (pMessagePtr->pIcon)
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00a01350(0xfc4, pMessagePtr->pIcon, true);
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfa3, 1);
        float fIconWidth =
            pMessagePtr->uiWidth > 0 ? (float)pMessagePtr->uiWidth : DAT_011da4f0->m_pTiles[1]->FUN_00a011b0(0xfba);
        fIconHeightIn =
            FUN_005bd5b0()->GetStringDimensions(pMessagePtr->pIcon, 6, fIconWidth != 0.0 ? fIconWidth : DAT_01016970, 0).x;
        fIconHeightIn = fIconHeightIn + (pMessagePtr->uiWidth > 0 ? 0.0f : 100.0f);
    }
    else
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfa3, 0);
    }
    MsgTile* pItemNew = 0;
    unsigned int uiPosNum = 0;
    int iMaxWidthCur = 0;
    float fListHeightTmp = 0.0f;
    int iIndex = 0;
    kButtons.Clear();
    if (pMessagePtr->kButtons.FUN_00559450())
    {
        MsgString kButtonText(pMessagePtr->kButtons.FUN_00559450());
        for (iIndex = 0; uiPosNum < kButtonText.FUN_00825c00() - 1; iIndex++)
        {
            MsgString kPart = kButtonText.Substr(uiPosNum, kButtonText.FUN_005103a0(DAT_01063d7c, uiPosNum) - uiPosNum);
            if (kPart.FUN_00825c00() > 0)
            {
                MsgTile* pText = 0;
                pItemNew = DAT_011da4f0->kButtons.FUN_00764430(
                    pMessagePtr->cButtonBase + iIndex,
                    kButtonText.Substr(uiPosNum, kButtonText.FUN_005103a0(DAT_01063d7c, uiPosNum) - uiPosNum)
                        .FUN_0044a560(),
                    0, 0);
                pText = pItemNew->FUN_00a03da0(s_szListItemText);
                pItemNew->FUN_00700320(0xfaa, 7);
                if (pText)
                {
                    float fItemWidth =
                        pMessagePtr->uiWidth > 0 ? (float)pMessagePtr->uiWidth : pText->FUN_00a011b0(0xfba);
                    fItemWidth = fItemWidth != 0.0 ? fItemWidth : DAT_01016970;
                    iMaxWidthCur =
                        FUN_00647b70(iMaxWidthCur,
                                     (int)FUN_005bd5b0()->GetStringDimensions(pText->FUN_00a011f0(0xfc4), 2, fItemWidth, 0).x);
                }
                fListHeightTmp = pItemNew->FUN_00a011b0(0xfb0) + fListHeightTmp;
            }
            uiPosNum = kButtonText.FUN_005103a0(DAT_01063d7c, uiPosNum);
            if (uiPosNum < kButtonText.FUN_00825c00() - 1)
                uiPosNum = uiPosNum + 1;
        }
    }
    if (pMessagePtr->kTitle.FUN_004048e0() > 0)
    {
        DAT_011da4f0->m_pTiles[2]->FUN_00a01350(0xfcc, pMessagePtr->kTitle.FUN_00559450(), true);
        DAT_011da4f0->m_pTiles[2]->FUN_00700320(0xfa3, 1);
        if (pMessagePtr->uiWidth > 0)
            fTheTextHeight = FUN_0040ebd0(fTheTextHeight + 120.0, (float)pMessagePtr->uiWidth);
        else
            fTheTextHeight = fTheTextHeight + 120.0;
    }
    else
    {
        DAT_011da4f0->m_pTiles[2]->FUN_00700320(0xfa3, 0);
    }
    if (pMessagePtr->uiWidth > 0)
        fButtonsWidth = FUN_0040ebd0(iMaxWidthCur + 80.0, (float)pMessagePtr->uiWidth);
    else
        fButtonsWidth = iMaxWidthCur + 80.0;
    DAT_011da4f0->m_pTiles[4]->FUN_00a012d0(0xfb0, fListHeightTmp, false);
    DAT_011da4f0->m_pTiles[4]->FUN_00a012d0(0xfb1, fButtonsWidth, false);
    DAT_011da4f0->kButtons.RebuildVisibleTiles();
    if (pMessagePtr->uiWidth > 0)
        fButtonsWidth = FUN_0040ebd0(fHorBuf * 2 + fButtonsWidth, (float)pMessagePtr->uiWidth);
    else
        fButtonsWidth = fHorBuf * 2 + fButtonsWidth;
    float fMaxWidthCur = DAT_01016970;
    if (pMessagePtr->uiWidth > 0)
        fMaxWidthCur = FUN_00715d40() * (pMessagePtr->uiWidth / FUN_00706e50());
    else
        fMaxWidthCur = DAT_011da4f0->FUN_00726070()->FUN_00a011b0(TraitNameToID(s_szMaxMenuWidth));
    fMaxWidthCur = fMaxWidthCur - fHorBuf * 2;
    if (DAT_011da4f0->m_pTiles[2]->IsTraitNonZero(0xfa3))
        fMaxWidthCur = fMaxWidthCur - 120.0;
    DAT_011da4f0->m_pTiles[3]->FUN_00a012d0(0xfba, fMaxWidthCur, true);
    MsgSize kSizeFinal = FUN_005bd5b0()->GetStringDimensions(pMessagePtr->kText.FUN_00559450(), 2,
                                                      DAT_011da4f0->m_pTiles[3]->FUN_00a011b0(0xfba), 0);
    fTheTextHeight = fHorBuf * 2 + kSizeFinal.x + fTheTextHeight;
    if (kSizeFinal.z > 1.0)
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfb7, 1);
        DAT_011da4f0->m_pTiles[3]->FUN_00700320(0xfb7, 1);
    }
    else
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfb7, 2);
        DAT_011da4f0->m_pTiles[3]->FUN_00700320(0xfb7, 2);
    }
    if (pMessagePtr->uiWidth == 0)
    {
        fWidths = FUN_00404010(fIconHeightIn, fTheTextHeight);
        fWidths = FUN_00404010(fWidths, fButtonsWidth);
        fWidths = FUN_0040ebd0(fWidths, FUN_00726070()->FUN_00a011b0(TraitNameToID(s_szMaxMenuWidth)));
        fWidths = FUN_00404010(fWidths, FUN_00726070()->FUN_00a011b0(TraitNameToID(s_szMinMenuWidth)));
    }
    else
    {
        fWidths = FUN_00715d40() * (pMessagePtr->uiWidth / FUN_00706e50());
        fWidths = FUN_0040ebd0(fWidths, FUN_00715d40() - FUN_007177c0() * 2);
    }
    DAT_011da4f0->m_pTiles[0]->FUN_00a012d0(0xfb1, fWidths, true);
    DAT_0119f348 = pMessagePtr->iType == 0x17;
    FUN_00726070()->FUN_00700320(0x1772, 0);
    FUN_00726070()->FUN_00700320(0xfa3, 1);
    if (!pMessagePtr->GetByteAtOffset56())
    {
        DAT_011da4f0->m_pTiles[0]->FUN_00a012d0(0xfa9, 0.0f, true);
        if (FUN_004b7210()->FUN_00714f90(GetID()))
            FUN_00706fd0(GetID(), 1);
        float fScreenWidth = FUN_00715d40();
        float fMenuWidth = DAT_011da4f0->m_pTiles[0]->FUN_00a011b0(0xfb1);
        float fScreenHeight = FUN_00715da0();
        float fMenuHeightNew = DAT_011da4f0->m_pTiles[0]->FUN_00a011b0(0xfb0);
        float fXNew = (fScreenWidth - fMenuWidth) / 2.0;
        float fY = (fScreenHeight - fMenuHeightNew) / 2.0;
        if (pMessagePtr->iX > -1)
        {
            float fLeft = pMessagePtr->iX / FUN_00706e50() * fScreenWidth;
            fXNew = FUN_00404010(fLeft, FUN_007177c0());
            fXNew = FUN_0040ebd0(fXNew, fScreenWidth - fMenuWidth - FUN_007177c0());
        }
        if (pMessagePtr->iY > -1)
        {
            float fTop = pMessagePtr->iY / FUN_00706e20() * fScreenHeight;
            fY = FUN_00404010(fTop, FUN_00717820());
            fY = FUN_0040ebd0(fY, fScreenHeight - fMenuHeightNew - FUN_00717820());
        }
        DAT_011da4f0->m_pTiles[0]->FUN_00a012d0(0xfa1, fXNew, true);
        DAT_011da4f0->m_pTiles[0]->FUN_00a012d0(0xfa2, fY, true);
    }
    else
    {
        DAT_011da4f0->m_pTiles[0]->FUN_00a012d0(0xfa9, 1.0f, true);
        if (!FUN_004b7210()->FUN_00714f90(GetID()))
            FUN_00706fb0(GetID(), 0);
    }
    DAT_011da4f0->m_pTiles[5]->FUN_00a012d0(0xfa9, pMessagePtr->fAlpha, true);
}

}

namespace fnv_007a8ba0 {
int __cdecl FUN_007a8de0();
void* __cdecl FUN_00a09030(int);
int __cdecl FUN_007023c0();
unsigned int __cdecl GetCurrentArrayElement();
unsigned char __cdecl FUN_007050d0();
void __cdecl SetDialogMenuActive(int);
void __cdecl FUN_00709c40(int);
float __cdecl FUN_00a01530();
void __cdecl FUN_0040fbe0(const char*);

struct VDel
{
    virtual ~VDel();
};
struct Helper
{
    void* FUN_00586150(const char* s);
    Tile* ReadXML();
    int FUN_00a03c90();
    void FUN_00a1dc70(Tile* tile, int zero);
    double FUN_00a011b0(int);
    void FUN_00a012d0(int, float, unsigned char);
    void FUN_0075a0d0(void* arg1, const char* arg2);
    void PopulateFromMessageData();
    void FUN_00a1dc20(int);
    void* FUN_00403e20();
    void* FUN_00726070();
    Tile* FUN_00a03da0(const char* name);
};

extern int DAT_011da4f0;
extern char DAT_011d3bc8;
extern double DAT_010704f0;
extern double DAT_010704e8;
extern double DAT_0101e568;

// Initializes the message menu interface from Data\Menus\message_menu.xml, configures its buttons and background, and returns success.
// @fnv 0x007a8ba0
bool __cdecl FUN_007a8ba0()
{
    InterfaceManager* B = FUN_004b7210();
    unsigned char flag = 0;
    VDel* pVDel = (VDel*)FUN_00a09030(FUN_007a8de0());
    if (pVDel != 0)
    {
        delete pVDel;
    }
    if (FUN_007023c0())
        flag = 1;
    Tile* pTile = ((Helper*)((Helper*)B)->FUN_00586150("Data\\Menus\\message_menu.xml"))->ReadXML();
    DAT_011da4f0 = ((Helper*)pTile)->FUN_00a03c90();
    if (DAT_011da4f0 != 0 &&
        ((int(__thiscall*)(void*))((*(void***)DAT_011da4f0)[13]))((void*)DAT_011da4f0) == FUN_007a8de0())
    {
        ((Helper*)DAT_011da4f0)->FUN_00a1dc70(pTile, 0);
        if (!((FUN_007abdb0_shell*)DAT_011da4f0)->FUN_007abdb0())
        {
            FUN_0040fbe0("Message Menu Creation Failed... Are your menu and art resources up to date?");
            return false;
        }
        if (((Helper*)pTile)->FUN_00a011b0(0xfa7) == DAT_010704f0 ||
            ((Helper*)pTile)->FUN_00a011b0(0xfa7) == DAT_010704e8)
        {
            ((Helper*)pTile)->FUN_00a012d0(0xfad, FUN_00a01530(), 1);
        }
        ((Helper*)((char*)DAT_011da4f0 + 0x40))
            ->FUN_0075a0d0(*(void**)((char*)DAT_011da4f0 + 0x38), "MM_ButtonTemplate");
        if (GetCurrentArrayElement() != 0)
        {
            ((Helper*)DAT_011da4f0)->PopulateFromMessageData();
        }
        if (flag)
        {
            ((Helper*)(((Helper*)(((Helper*)DAT_011da4f0)->FUN_00726070()))->FUN_00a03da0((char*)"MM_Background")))
                ->FUN_00a012d0(0xfa9, *(float*)(((Helper*)&DAT_011d3bc8)->FUN_00403e20()) * DAT_0101e568, 1);
        }
        if (FUN_007050d0())
        {
            SetDialogMenuActive(1);
        }
        ((Helper*)DAT_011da4f0)->FUN_00a1dc20(0);
        FUN_00709c40(0);
        return true;
    }
    else
    {
        if (DAT_011da4f0 != 0 && ((Helper*)DAT_011da4f0)->FUN_00726070() != 0)
        {
            delete (VDel*)DAT_011da4f0;
        }
    }
    return false;
}
}  // namespace fnv_007a8ba0
