// fallout/interface/menuconsole.cpp: ConsoleManager, ListHead, ConsoleDisplay, DumpConsole (13 functions)

#include "menuconsole_idle.h"
#include "menuconsole_decls.h"

ConsoleManager* ConsoleManager::pInstance = 0;

// @fnv 0x0071b0e0
void ConsoleManager::Init()
{
    m_pScriptCompiler = new ScriptCompiler;
}

// Returns the singleton instance, creating and initialising it first when bCreate is true and it does not yet exist.
// @fnv 0x0071b160
ConsoleManager* ConsoleManager::Instance(bool bCreate)
{
    if (!pInstance && bCreate)
    {
        pInstance = new ConsoleManager;
        pInstance->Init();
        return pInstance;
    }
    else
        return pInstance;
}

// @fnv 0x0071b210
bool ConsoleManager::Idle(int aiKeyCode)
{
    if (cVisible <= 0 || !FUN_004b7210()->FUN_007023a0())
        return false;

    struct InputState
    {
        int length;
        int key;
    } state;
    state.key = aiKeyCode;
    if (state.key)
    {
        char text[2048];
        int cursor;
        char rawText[2048];
        DebugText::Instance(true)->FUN_00a103e0(rawText, (float)m_iConsoleX, (float)m_iConsoleY, 1);
        FUN_005cbd90(text, rawText, 2046);
        state.length = 0;
        while (text[state.length])
            state.length++;
        if (text[state.length - 1] == '|')
        {
            state.length--;
            text[state.length] = 0;
        }
        for (cursor = 0; cursor < state.length; cursor++)
        {
            if (text[cursor] == '|')
                break;
        }
        if (cursor == state.length)
        {
            text[cursor] = '|';
            state.length++;
        }
        if (state.key == (int)0x80000008)
        {
            for (int i = 0; i < state.length + 1; i++)
            {
                if (text[i] == '|')
                {
                    text[i] = text[i + 1];
                    text[i + 1] = '|';
                }
            }
            for (int i = 0; i < state.length + 1; i++)
            {
                if (text[i] == '\n')
                {
                    if (text[i - 1] == '-')
                    {
                        for (int j = i - 1; j < state.length + 1; j++)
                            text[j] = text[j + 2];
                    }
                    else
                        text[i] = ' ';
                }
                if (text[i] == '\n')
                    text[i] = ' ';
            }
            if (text[0])
            {
                DAT_011d8ce4 = true;
                InterfaceManager* manager = FUN_004b7210();
                reinterpret_cast<InterfaceManager*>(this)->SetNamedMenuOption(
                    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kOutputLines)->GetSize());
                FUN_0071d030(this, text);
                BSStringT<char> line(text);
                m_kCommandHistory.AssignString(line);
                m_iCommandHistoryPosition = 0;
                DebugText::Instance(true)->Print("|", (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                                 DAT_011d8d38.Int()->i);
                if (!FUN_0071cff0(text, "dof", 3))
                {
                    float distance = 0.0f;
                    sscanf(text, "dof %f", &distance);
                    NiFrustum frustum =
                        reinterpret_cast<NiCamera*>(
                            reinterpret_cast<BSFaceGenNiNode*>(reinterpret_cast<SkyObject*>(manager)->GetRoot())
                                ->GetAnimationData())
                            ->GetViewFrustum();
                    frustum.m_fFarPlane = distance;
                    reinterpret_cast<NiCamera*>(
                        reinterpret_cast<BSFaceGenNiNode*>(reinterpret_cast<SkyObject*>(manager)->GetRoot())
                            ->GetAnimationData())
                        ->UpdateViewFrustum(frustum);
                }
                else if (!FUN_0071cff0(text, "usz", 3))
                {
                    struct ConsoleSize
                    {
                        int y;
                        int x;
                    } size;
                    size.x = 0;
                    size.y = 0;
                    sscanf(text, "usz %i %i", &size.x, &size.y);
                    FUN_007030c0(size.x, size.y);
                }
                else if (!_mbsicmp((const unsigned char*)text, (const unsigned char*)"clr") ||
                         !_mbscmp((const unsigned char*)text, (const unsigned char*)"cls"))
                {
                    m_kOutputLines.RemoveAll();
                    m_iOutputLineCount = 0;
                    ResetOutputState();
                }
                else if (!_mbsicmp((const unsigned char*)text, (const unsigned char*)"tag"))
                {
                    TESObjectREFR* reference = manager->FUN_007031c0();
                    if (reference)
                    {
                        BSStringT<char> label;
                        label.PrintfString("\"%s\" (%08x)", reference->GetFullName(), reference->GetFormID());
                        void* node = DynamicCastByRTTI(&DAT_011f4428, reference->GetNiNode_v());
                        if (!node)
                            node = DynamicCastByRTTI(&DAT_011f4428, reference->GetNiNode_v()->GetParent());
                        DebugText::FUN_00a10c00(node, label.String(), 0, -1.0f);
                    }
                }
                else if (!FUN_0071cff0(text, "reload strings", 14))
                {
                    delete manager->FUN_004fd400();
                    Menu::ReadMenuDefinition("Data\\Menus\\globals.xml", 0);
                    Tile* tile = manager->FUN_00586150()->ReadFile("Data\\Menus\\globals.xml");
                    tile->SetParent(0, 0);
                    manager->FUN_00500a20(tile);
                }
                else if (!FUN_0071cff0(text, "reload HUDReticle", 17))
                    DebugText::ClearDebugText();
                else if (!FUN_0071cff0(text, "reload HUDSafeZone", 18))
                {
                    DebugText::ClearDebugText();
                    FUN_007038e0(3);
                }
                else if (!_mbsicmp((const unsigned char*)text, (const unsigned char*)"reload mainmenu"))
                {
                    DebugText::ClearDebugText();
                    delete FindMenuById(FUN_0070ede0());
                    StartMenu::Create(false, false);
                }
                else if (!FUN_0071cff0(text, "reload ", 7))
                {
                    DebugText::ClearDebugText();
                    char menuName[1024];
                    sscanf(text, "reload %s", menuName);
                    if (menuName[0] != '&')
                    {
                        int i = 0;
                        while (menuName[i])
                            i++;
                        menuName[i + 2] = 0;
                        menuName[i + 1] = ';';
                        while (i > 0)
                        {
                            menuName[i] = menuName[i - 1];
                            i--;
                        }
                        menuName[0] = '&';
                    }
                    MenuSystem::Instance(true)->TileReloadContext(Tile::GetTraitID(menuName));
                }
                else if (!FUN_0071cff0(text, "delete ", 7))
                {
                    char menuName[1024];
                    sscanf(text, "delete %s", menuName);
                    MenuSystem::Instance(true)->DeleteMenu(Tile::GetTraitID(menuName));
                }
                else if (!FUN_0071cfd0(text, "front", 5))
                    FUN_0071d030(this, "Frontmost: %s",
                                 reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(
                                                             MenuSystem::Instance(true)->GetFrontmostMenu())
                                                             ->GetNext())
                                     ->FUN_00700300());
                else if (!FUN_0071cfd0(text, "stack", 5))
                {
                    int i = 0;
                    while (manager->GetMenuStackEntry(i++))
                        FUN_0071d030(this, "%i: %i", i, manager->GetMenuStackEntry(i));
                }
                else if (!FUN_0071cfd0(text, "visible", 7))
                {
                    int menu = 0;
                    sscanf(text, "visible %i", &menu);
                    FUN_0071d030(this, "Is Visible: %i", MenuSystem::Instance(true)->IsMenuClassVisible(menu));
                }
                else if (!FUN_0071cfd0(text, "exit menus", 10))
                {
                    int menu = manager->GetTopEnterStackEntry();
                    while (menu)
                    {
                        manager->AddMenuStackEntry(menu, false);
                        menu = manager->GetTopEnterStackEntry();
                    }
                }
                else if (!FUN_0071cfd0(text, "emergency texture release", 25))
                {
                    FUN_00703920();
                    FUN_0071d030(this, "First change release of hidden textures activated.");
                }
                else if (!FUN_0071cfd0(text, "set trait", 9))
                {
                    struct TileTraitEdit
                    {
                        int trait;
                        float value;
                        Tile* tile;
                    } edit;
                    edit.value = 0.0f;
                    {
                        char traitName[128];
                        char tileName[128];
                        sscanf(text, "set trait %s %s %f", tileName, traitName, &edit.value);
                        edit.tile = FindNamedTile(0, tileName);
                        edit.trait = Tile::GetTraitID(traitName);
                        if (edit.tile && edit.trait > 0)
                        {
                            FUN_0071d030(this, "Trait set.");
                            edit.tile->Set(edit.trait, edit.value, true);
                        }
                        else if (edit.tile)
                            Print("Unknown trait '%s'", traitName);
                        else
                            Print("Can't find tile '%s'", tileName);
                    }
                }
                else if (!FUN_0071cfd0(text, "depth", 5))
                {
                    FUN_0071d030(this, "Max Depth: %i", (int)Tile::GetInterfaceScale());
                    FUN_0071d030(this, "Cursor Depth: %i",
                                 (int)reinterpret_cast<TileListBoxCalls*>(
                                     reinterpret_cast<TESResponse*>(FUN_004b7210())->GetNext())
                                     ->GetFloat(4013));
                }
                else if (!FUN_0071cfd0(text, "new fonts", 9))
                    FontManager::GetFontManager(true)->SetByteAtOffset20();
                else if (!FUN_0071cfd0(text, "old fonts", 9))
                    FontManager::GetFontManager(false)->SetByteAtOffset20();
                else if (!FUN_0071cfd0(text, "iso", 3))
                {
                    bool first = false;
                    bool second = false;
                    if (text[3] == '1')
                        first = true;
                    if (text[4] == '1')
                        second = true;
                    FUN_00702c80(first, second);
                }
                else if (!FUN_0071cfd0(text, "restore menus", 13))
                    UpdateMenuTileVisibility();
                else if (!FUN_0071cfd0(text, "use workbook", 12))
                {
                    TileMenu* tileMenu = dynamic_cast<TileMenu*>(reinterpret_cast<Tile*>(FindMenuById(1026)));
                    if (tileMenu)
                    {
                        BookMenu* book = dynamic_cast<BookMenu*>(
                            reinterpret_cast<Menu*>(reinterpret_cast<TESTopicInfo*>(tileMenu)->GetSpeaker()));
                        if (book)
                            book->ReadBook();
                    }
                    else
                        FUN_0071d030(this, "You must open a book (or scroll) before using the workbook.");
                }
                else if (!FUN_0071cfd0(text, "dump textures", 13))
                    DumpTextureList();
                else if (!FUN_0071cfd0(text, "bat", 3))
                {
                    char filename[128];
                    filename[0] = ""[0];
                    fnv_zlib_memset(filename + 1, 0, 127);
                    sscanf(text, "bat %s", filename);
                    if (!strlen(filename))
                        DebugLog("You must enter a filename.");
                    else
                    {
                        char primaryName[260];
                        primaryName[0] = ""[0];
                        fnv_zlib_memset(primaryName + 1, 0, 259);
                        {
                            struct BatchFileState
                            {
                                BSFile* file;
                                unsigned int filenameLength;
                            } batch;
                            {
                                char alternateName[260];
                                alternateName[0] = ""[0];
                                fnv_zlib_memset(alternateName + 1, 0, 259);
                                strcat_s(primaryName, 260, filename);
                                batch.file = new BSFile(primaryName, NiFile::READ_ONLY, 16384, false);
                                batch.filenameLength = BSStringLength(filename);
                                if (!batch.file || !batch.file->vfn_20(false, false))
                                {
                                    if (batch.filenameLength <= 4 ||
                                        _mbsnicmp((const unsigned char*)(filename + batch.filenameLength - 4),
                                                  (const unsigned char*)".txt", 4))
                                    {
                                        delete batch.file;
                                        TaskQueueInterface::CopyStringToBuffer(alternateName, 260, primaryName);
                                        strcat_s(alternateName, 260, ".txt");
                                        batch.file = new BSFile(alternateName, NiFile::READ_ONLY, 16384, false);
                                    }
                                }
                                if (!batch.file || !batch.file->vfn_20(false, false))
                                {
                                    if (BSStringLength(alternateName))
                                        DebugLog("Neither file '%s' or '%s' could be opened.", primaryName,
                                                 alternateName);
                                    else
                                        DebugLog("The file '%s' could not be opened.", primaryName);
                                }
                                else
                                {
                                    char batchLine[2600];
                                    while (batch.file->vfn_34(batchLine, 2600, '\r'))
                                    {
                                        for (int i = 0; i < strlen(batchLine); i++)
                                            if (batchLine[i] == '\n')
                                                batchLine[i] = ' ';
                                        if (strlen(batchLine) > 1)
                                        {
                                            DebugLog("> %s", batchLine);
                                            Script script;
                                            script.NotifySaveLoadGameOfFormChange();
                                            script.SetText(batchLine);
                                            script.CompileScriptText(m_pScriptCompiler, COMPILER_NAME_CONSOLE,
                                                                     FUN_004b7210()->FUN_007031c0());
                                        }
                                    }
                                }
                                if (batch.file)
                                    delete batch.file;
                            }
                        }
                    }
                }
                else if (!FUN_0071cfd0(text, "rbat", 3))
                {
                    if (!m_bRecordingBatch)
                    {
                        DebugLog("Batch Recording Started.");
                        DebugLog("Use rbat {filename} to save batch file or rbat with no filename to cancel.");
                        m_bRecordingBatch = true;
                        m_iBatchCommandCount = 0;
                        for (int i = 0; i < 20; i++)
                            __insecure_strcpy(m_aacCommandHistory[i], "");
                    }
                    else
                    {
                        char filename[128];
                        filename[0] = ""[0];
                        fnv_zlib_memset(filename + 1, 0, 127);
                        sscanf(text, "rbat %s", filename);
                        if (!strlen(filename))
                            DebugLog("No filename specified; recording cancelled.");
                        else if (m_iBatchCommandCount <= 0)
                            DebugLog("No commands recorded; recording cancelled.");
                        else
                        {
                            BSFile* file = new BSFile(filename, NiFile::WRITE_ONLY, 4096, true);
                            if (!file || !file->vfn_20(false, false))
                                DebugLog("The file '%s' could not be opened.", filename);
                            else
                            {
                                for (int i = 0; i < m_iBatchCommandCount; i++)
                                {
                                    char batchLine[100];
                                    sprintf_s(batchLine, 100, "%s\r\n", m_aacCommandHistory[i]);
                                    file->FUN_00473180(batchLine, BSStringLength(batchLine));
                                }
                                file->Close();
                                DebugLog("Batch file '%s' created.", filename);
                            }
                            if (file)
                                delete file;
                        }
                        m_bRecordingBatch = false;
                        m_iBatchCommandCount = 0;
                    }
                }
                else
                {
                    if (m_bRecordingBatch)
                    {
                        if (m_iBatchCommandCount < 20)
                        {
                            __insecure_strcpy(m_aacCommandHistory[m_iBatchCommandCount++], text);
                            DebugLog("Recorded.");
                        }
                        else
                            DebugLog("Recording full; command ignored. Use rbat to cancel or rbat {filename} to save.");
                    }
                    for (int i = 0; i < strlen(text); i++)
                        if (text[i] == '\n')
                            text[i] = ' ';
                    Script script;
                    script.NotifySaveLoadGameOfFormChange();
                    script.SetText(text);
                    script.CompileScriptText(m_pScriptCompiler, COMPILER_NAME_CONSOLE, FUN_004b7210()->FUN_007031c0());
                }
            }
        }
        else
        {
            {
                int i;
                {
                    bool found;
                    if (state.key == (int)0x80000000)
                    {
                        if (state.length && cursor)
                        {
                            state.length--;
                            int i = cursor;
                            while (i < state.length)
                            {
                                text[i] = text[i + 1];
                                i++;
                            }
                            text[state.length] = 0;
                            text[cursor - 1] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000007)
                    {
                        if (cursor < state.length)
                        {
                            state.length--;
                            int i = cursor;
                            while (i < state.length)
                            {
                                text[i] = text[i + 1];
                                i++;
                            }
                            text[state.length] = 0;
                            text[cursor] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000009)
                    {
                        reinterpret_cast<InterfaceManager*>(this)->SetNamedMenuOption(-DAT_011d8cfc.Int()->i + 1);
                        ResetOutputState();
                    }
                    else if (state.key == (int)0x8000000a)
                    {
                        reinterpret_cast<InterfaceManager*>(this)->SetNamedMenuOption(DAT_011d8cfc.Int()->i - 1);
                        ResetOutputState();
                    }
                    else if (state.key == (int)0x8000000a)
                    {
                        reinterpret_cast<InterfaceManager*>(this)->SetNamedMenuOption(DAT_011d8cfc.Int()->i - 1);
                        ResetOutputState();
                    }
                    else if (state.key == (int)0x80000003)
                    {
                        if (reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)->GetSize())
                        {
                            m_iCommandHistoryPosition++;
                            m_iCommandHistoryPosition = MinInt(
                                m_iCommandHistoryPosition,
                                reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)->GetSize() -
                                    1);
                            void* position =
                                reinterpret_cast<
                                    const NiTListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                                    &m_kCommandHistory)
                                    ->GetHeadPos();
                            for (int i = 0; i < m_iCommandHistoryPosition; i++)
                                position = m_kCommandHistory.DereferenceIfNotNull(position);
                            sprintf(text, "%s", m_kCommandHistory.AddEight(position).String());
                        }
                    }
                    else if (state.key == (int)0x80000004)
                    {
                        if (reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)->GetSize())
                        {
                            m_iCommandHistoryPosition--;
                            m_iCommandHistoryPosition = FUN_00647b70(m_iCommandHistoryPosition, 0);
                            BSStringT<char> line;
                            {
                                void* position = 0;
                                if (m_iCommandHistoryPosition)
                                {
                                    position =
                                        reinterpret_cast<const NiTListBase<NiTPointerAllocator<unsigned int>,
                                                                           NiPointer<NiProperty> >*>(&m_kCommandHistory)
                                            ->GetHeadPos();
                                    for (int i = 0; i < m_iCommandHistoryPosition; i++)
                                        position = m_kCommandHistory.DereferenceIfNotNull(position);
                                }
                                if (position)
                                    line = m_kCommandHistory.AddEight(position);
                                else
                                    line = "";
                                sprintf(text, "%s", line.Length() ? line.String() : "");
                            }
                        }
                    }
                    else if (state.key == (int)0x80000001)
                    {
                        if (state.length && cursor)
                        {
                            text[cursor] = text[cursor - 1];
                            text[cursor - 1] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000002)
                    {
                        if (state.length && cursor + 1 < state.length)
                        {
                            text[cursor] = text[cursor + 1];
                            text[cursor + 1] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000005)
                    {
                        if (state.length && cursor)
                        {
                            for (int i = cursor; i > 0; i--)
                                text[i] = text[i - 1];
                            text[0] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000006)
                    {
                        if (state.length && cursor + 1 < state.length)
                        {
                            for (int i = cursor; i < state.length - 1; i++)
                                text[i] = text[i + 1];
                            text[state.length - 1] = '|';
                        }
                    }
                    else
                    {
                        text[cursor] = (char)state.key;
                        state.length++;
                        int i = state.length;
                        while (i > cursor)
                        {
                            text[i + 1] = text[i];
                            i--;
                        }
                        text[state.length + 1] = 0;
                        text[cursor + 1] = '|';
                    }
                    found = false;
                    i = 0;
                    while (text[i])
                    {
                        if (text[i] == '|')
                        {
                            found = true;
                            break;
                        }
                        i++;
                    }
                    if (!found)
                    {
                        text[i] = '|';
                        text[i + 1] = 0;
                    }
                }
            }
            BSStringT<char> line(text);
            if (!reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)->GetSize())
                m_kCommandHistory.AssignString(line);
            else
            {
                m_kCommandHistory.PopFront();
                m_kCommandHistory.AssignString(line);
            }
            DebugText::Instance(true)->Print(text, (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                             DAT_011d8d38.Int()->i);
        }
    }
    return true;
}

void* __cdecl memset(void*, int, unsigned int);
extern SettingT_GameSettingCollection_ g_011d8d44;
extern SettingT_GameSettingCollection_ g_011d8d08;

class GlobalObject_0048f200
{
  public:
    char pad[12];
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
};

struct DummyFont
{
    float FUN_005bd580();
};

struct DummyFontManager
{
    DummyFont* FUN_005bd5c0(int);
};

DummyFontManager* __cdecl FUN_005bd5b0();

struct GlobalObject_0048f200_d0071b020 : GlobalObject_0048f200
{
    ~GlobalObject_0048f200_d0071b020();
};
struct FUN_0071af10
{
    int f00;
    GlobalObject_0048f200_d0071b020 f04;
    GlobalObject_0048f200_d0071b020 f10;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    char f38;
    char f39;
    char f3a;
    char f3b;
    int f3c;
    char pad40[0x7d0];
    char f810[0x104];

    FUN_0071af10();
};

// @fnv 0x0071af10
FUN_0071af10::FUN_0071af10()
{
    f39 = 0;
    f00 = 0;
    f24 = 0;
    f38 = 0;
    f1c = 0;
    f2c = (int)FUN_005bd5b0()->FUN_005bd5c0(DAT_011d8d38.Int()->i - 1)->FUN_005bd580() + 3;
    f30 = g_011d8d44.Int()->i;
    f34 = g_011d8d08.Int()->i;
    f3a = 0;
    f3c = 0;
    memset(f810, 0, 0x104);
}

struct FUN_0071d750_shell
{
    void ClearField();
};

// @fnv 0x0071d750
void FUN_0071d750_shell::ClearField()
{
    ((int*)this)[0x3c] = 0;
}

struct ListNode
{
    ListNode* next;
};
struct ListHead
{
    ListNode* head;
    ListNode* tail;
    int count;
    void Clear();
    void FUN_0071e0f0(ListNode*);
};
// @fnv 0x0071e070
void ListHead::Clear()
{
    ListNode* pkNode = head;
    while (pkNode != 0)
    {
        ListNode* pkTemp = pkNode;
        pkNode = pkNode->next;
        FUN_0071e0f0(pkTemp);
    }
    count = 0;
    head = 0;
    tail = 0;
}

struct FUN_0071b020_shell
{
    void __thiscall FUN_0071dec0();
    void __thiscall FUN_0071b020();
};

// @fnv 0x0071b020
void __thiscall FUN_0071b020_shell::FUN_0071b020()
{
    FUN_0071dec0();
}

void FUN_00703310(int);
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_0071d770_shell : public ConsoleManager
{
    void FUN_0071d770();
};
// @fnv 0x0071d770
void FUN_0071d770_shell::FUN_0071d770()
{
    if (cVisible > 0)
    {
        DebugText::Instance(true)->Print("|", (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                         DAT_011d8d38.Int()->i, 0);
        ((InterfaceManager*)this)->SetNamedMenuOption(((ArrSI*)((char*)this + 4))->GetFlags());
        ResetOutputState();
        FUN_00703310(0);
    }
}

namespace fnv_0071d620 {
struct Interface
{
    static void __cdecl PrintDebugMessage();
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00a0de80_shell
{
    void FUN_00a0de80();
};

struct FUN_0071d750_shell
{
    void ClearField();
};

extern const char $SG3295[];

InterfaceManager* __cdecl _FUN_004b7210();

struct FUN_0071d620_shell : public InterfaceManager
{
    unsigned char layoutPadding[0x30];
    int m_iConsoleX;
    int m_iConsoleY;
    char cVisible;

    void FUN_0071d620(char acState);
};

// @fnv 0x0071d620
void FUN_0071d620_shell::FUN_0071d620(char acState)
{
    char cold_state;
    cold_state = cVisible;
    cVisible = acState;

    if ((acState > 0) != (cold_state > 0))
    {
        if (acState > 0)
        {
            Interface::PrintDebugMessage();

            if (_FUN_004b7210()->FUN_007023a0())
            {
                DebugText::Instance(true)->Print("|", (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                                 DAT_011d8d38.Int()->i, 0);

                SetNamedMenuOption(reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 4)->GetFlags());
            }
            else
            {
                DebugText::Instance(true)->Print($SG3295, (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f, 0, 0);
            }

            reinterpret_cast<ConsoleManager*>(this)->ResetOutputState();
        }
        else
        {
            Interface::PrintDebugMessage();
            reinterpret_cast<FUN_00a0de80_shell*>(DebugText::Instance(true))->FUN_00a0de80();
            reinterpret_cast<FUN_0071d750_shell*>(_FUN_004b7210())->ClearField();
        }
    }
}
}  // namespace fnv_0071d620

// Destructor: free the owned decal data; the two lists are destroyed afterwards.

class B040DecalData
{
  public:
    ~B040DecalData();
    int unk00;
};

class B040List
{
  public:
    ~B040List();
    int unk00;
    int unk04;
    int unk08;
};

class FUN_0071b040
{
  public:
    ~FUN_0071b040();

    B040DecalData* m_pkDecalData;
    B040List m_kFirst;
    B040List m_kSecond;
};

// Destructor that deletes m_pkDecalData if it is non-null.
// @fnv 0x0071b040
FUN_0071b040::~FUN_0071b040()
{
    if (m_pkDecalData)
        delete m_pkDecalData;
}

struct ConsoleLine
{
    const char* FUN_00559450();
};
struct ConsoleLines
{
    void* head;
    void* tail;
    int count;
    void* FUN_00559450();
    void* DereferenceIfNotNull(void* node);
    ConsoleLine* AddEight(void* node);
};
struct ConsoleTextRenderer
{
    void CreateLine(const char* text, float x, float y, int color, int state, float opacity, int alignment,
                      int style);
};
ConsoleTextRenderer* __cdecl FUN_00a0d9e0(int mode);
extern float _DAT_01012054;
struct ConsoleDisplay
{
    void* compiler;
    ConsoleLines strings, inputs;
    int m_iCommandHistoryPosition, m_iScrollPosition, m_iOutputLineCount, menuMode, iConsoleLineSpacing, m_iConsoleX,
        m_iConsoleY;
    void DrawConsoleLines();
};
// Draws the visible console string lines, padding with blank lines when the first visible index is negative, then advancing through the list.
// @fnv 0x0071d410
void ConsoleDisplay::DrawConsoleLines()
{
    void* node = strings.FUN_00559450();
    int lineY = m_iConsoleY - DAT_011d8cfc.Int()->i * iConsoleLineSpacing;
    int lastLine = m_iOutputLineCount;
    int lineIndex = lastLine - DAT_011d8cfc.Int()->i;
    while (lineIndex < 0)
    {
        FUN_00a0d9e0(1)->CreateLine(0, (float)m_iConsoleX, (float)lineY, 1, -1, _DAT_01012054, 0, 0);
        ++lineIndex;
        lineY += iConsoleLineSpacing;
    }
    for (int skipped = 0; skipped < lineIndex; ++skipped)
        node = strings.DereferenceIfNotNull(node);
    while (lineIndex < lastLine)
    {
        FUN_00a0d9e0(1)->CreateLine(strings.AddEight(node)->FUN_00559450(), (float)m_iConsoleX, (float)lineY, 1, -1,
                                      _DAT_01012054, DAT_011d8d38.Int()->i, 0);
        node = strings.DereferenceIfNotNull(node);
        ++lineIndex;
        lineY += iConsoleLineSpacing;
    }
}

void ToggleGlobalFlag();

class FUN_0071d580_probe
{
  public:
    bool Probe_0070ecf0();
    int Probe_00714f70(int);
};

class FUN_0071d580_cls
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
    signed char m_38;

    void Call_0071d620(int);
    bool FUN_0071d580();
};

// @fnv 0x0071d580
bool FUN_0071d580_cls::FUN_0071d580()
{
    ToggleGlobalFlag();
    if (m_38 == 0)
    {
        Call_0071d620(1);
        return true;
    }
    else
    {
        if (m_38 == 1 && ((FUN_0071d580_probe*)FUN_004b7210())->Probe_0070ecf0())
        {
            if (((FUN_0071d580_probe*)FUN_004b7210())->Probe_00714f70(0) == 3 &&
                ((FUN_0071d580_probe*)FUN_004b7210())->Probe_00714f70(1) == 0)
            {
                Call_0071d620(2);
            }
            else
            {
                Call_0071d620(0);
            }
        }
        else
        {
            Call_0071d620(0);
        }
    }
    return false;
}

struct DumpName
{
    const char* FUN_0043b1b0();
};
struct DumpTexture
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual DumpName* v9c();
    unsigned int FUN_0059bb30();
    DumpTexture* FUN_0055b980();
};
DumpTexture* FUN_00456510();
struct DumpRTTI
{
};
extern DumpRTTI DAT_011f444c;
bool FUN_0043b300(const DumpRTTI*, DumpTexture*);
struct DumpSetting
{
    bool* FUN_00408d60();
};
extern DumpSetting g_011dec98;
struct DumpFullName
{
    const char* FUN_00408da0();
};
struct DumpWorld
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DumpFullName name;
};
struct DumpCell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DumpFullName name;
    DumpWorld* FUN_0054ddd0();
};
struct DumpTES
{
    DumpCell* FUN_00457070();
    int FUN_0059bb30();
    int FUN_0045cd60();
};
extern DumpTES* g_TES;
struct DumpConsole
{
    bool HasMenusPath(DumpTexture*);
    void DumpLoadedTextures();
};
// @fnv 0x0071d800
void DumpConsole::DumpLoadedTextures()
{
    DumpTexture* a0[200];
    {
        DumpTexture* a1;
        int a2;
        unsigned int a3;
        int a4, a5, a6;
        unsigned int a7;
        BSFile* a8;
        DumpTexture* a9;
        memset(a0, 0, sizeof(a0));
        a1 = FUN_00456510();
        while (a1)
        {
            if (FUN_0043b300(&DAT_011f444c, a1))
            {
                a9 = a1;
                a7 = a9->FUN_0059bb30();
                if (a7 && (*g_011dec98.FUN_00408d60() || !HasMenusPath(a9)))
                {
                    a5 = -1;
                    for (a4 = 0; a4 < 200 && a5 == -1; a4++)
                    {
                        if (!a0[a4])
                            a5 = a4;
                        else
                        {
                            a3 = a0[a4]->FUN_0059bb30();
                        }
                    }
                    if (a5 != -1)
                    {
                        for (a2 = 199; a2 > a5; a2--)
                            a0[a2] = a0[a2 - 1];
                        a0[a5] = a9;
                    }
                }
            }
            a1 = a1->FUN_0055b980();
        }
        a8 = new BSFile("textures.txt", NiFile::WRITE_ONLY, 0x1000, true);
        if (!a8 || !a8->vfn_20(false, false))
        {
            DebugLog("The file textures.txt could not be opened.");
            return;
        }
        a6 = 0;
        {
            char buffer[1024];
            sprintf_s(
                buffer, 1024,
                "Texture dump for cell: %s grid: (%d, %d) worldspace: %s \n---------------------------------------\n",
                g_TES->FUN_00457070() ? g_TES->FUN_00457070()->name.FUN_00408da0() : "{unknown}", g_TES->FUN_0059bb30(),
                g_TES->FUN_0045cd60(),
                g_TES->FUN_00457070() ? (g_TES->FUN_00457070()->FUN_0054ddd0()
                                             ? g_TES->FUN_00457070()->FUN_0054ddd0()->name.FUN_00408da0()
                                             : "{unknown}")
                                      : "{unknown}");
            a8->FUN_00473180(buffer, BSStringLength(buffer));
            {
                for (int k = 0; k < 200 && a0[k]; k++)
                {
                    const char* a7;
                    unsigned int name;
                    name = a0[k]->FUN_0059bb30();
                    a7 = a0[k]->v9c()->FUN_0043b1b0();
                    a8->FUN_00473180(buffer, BSStringLength(buffer));
                }
            }
            sprintf_s(buffer, 1024, "---------------------------------------\nTotal memory: %dkb", a6);
            a8->FUN_00473180(buffer, BSStringLength(buffer));
            a8->Close();
            DebugLog("200 largest loaded textures dumped to the file textures.txt.");
        }
    }
}
