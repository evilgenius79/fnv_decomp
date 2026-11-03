// bsmenu/menu.cpp: Menu (27 functions)

#include <string.h>

class Tile;
class TileMenu;
class Tile__TileTemplate;

class Tile
{
  public:
    void Set(int aiTrait, float afValue, bool abClearActions);
};

class TileMenu : public Tile
{
};

class Interface
{
  public:
    static void ClearInterfaceState(Tile* apTile);
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList() : m_item(0), m_pkNext(0)
    {}
    void AddHead(T& item);
};

template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    bool Set(const T* apText, unsigned int auLength);
};

class MenuClassArray
{
  public:
    void SetAt(unsigned int auIndex, Tile*& apTile);
};

extern BSStringT<char> g_menuParsedXML;
extern MenuClassArray g_menuByClassArray;
extern unsigned short g_menuByClassCount;

class Menu
{
  public:
    virtual ~Menu();
    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    unsigned char layoutPadding1E[2];
    int m_iMenuId;
    int m_eFadeState;
    Menu();
    static const char* GetMenuPath(const char* apPath);
    void SetMenuVisibility(bool abVisible);
    void UnloadMenuData();
    static float GetMenuScale();
    void ParseMenuXML(const char* apXML);
    static void SetMenuRootTile(int aiClass, Tile* apTile);
};

// @fnv 0x00a1c4a0
Menu::Menu()
{
    pMenu = 0;
    m_pMenuTile = 0;
    m_iModalMenuId = 0;
    m_eFadeState = 4;
    m_bVisible = true;
    m_iSecondaryValue = 0;
    m_bIsSpecial = false;
}

// Returns the file name portion of apPath after the last backslash, or apPath itself if there is none.
// @fnv 0x00a1c970
const char* Menu::GetMenuPath(const char* apPath)
{
    const char* pRequestedMenuPath = apPath;
    const char* pBaseName = pRequestedMenuPath;
    const char* pLastSlash = strrchr(pRequestedMenuPath, '\\');
    if (pLastSlash)
        pBaseName = pLastSlash + 1;
    return pBaseName;
}

// @fnv 0x00483080
void Menu::ParseMenuXML(const char* apXML)
{
    g_menuParsedXML.Set(apXML, 0);
}

// Stores apTile in g_menuByClassArray at index aiClass - 0x3E9 when that index is within g_menuByClassCount.
// @fnv 0x00a1e130
void Menu::SetMenuRootTile(int aiClass, Tile* apTile)
{
    int iIndex = aiClass - 0x3E9;
    if (iIndex >= 0 && iIndex < g_menuByClassCount)
        g_menuByClassArray.SetAt(iIndex, apTile);
}

// @fnv 0x00a1dc20
void Menu::SetMenuVisibility(bool abVisible)
{
    TileMenu* pTileMenu = pMenu;
    pTileMenu->Set(0xFA3, 0.0f, true);
    if (!abVisible)
        UnloadMenuData();
    Interface::ClearInterfaceState(0);
    (void)GetMenuScale();
}

class NiGlobalStringTable
{
  public:
    static char* __cdecl AddString(const char*);
};

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
    void Deallocate(void*);
};

extern MemoryManager g_memoryManager;

class NiFixedString;
extern NiFixedString EmptyFS;

class NiFixedString
{
  public:
    char* m_kHandle;

    void* operator new(unsigned int stSize)
    {
        return g_memoryManager.Allocate(stSize);
    }

    void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }

    NiFixedString(const char* pcString)
    {
        if (pcString == 0)
        {
            m_kHandle = EmptyFS.m_kHandle;
        }
        else
        {
            m_kHandle = NiGlobalStringTable::AddString(pcString);
        }
    }
};

extern NiFixedString* DAT_011f34cc;

// Allocates a NiFixedString from the literal "Tileptr" and stores it in DAT_011f34cc.
// @fnv 0x00a1c6f0
void __cdecl FUN_00a1c6f0()
{
    DAT_011f34cc = new NiFixedString("Tileptr");
}

struct MenuValueDescriptor
{
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiValueId;
    char* m_pName;
};
typedef char _sizecheck_XMLStorage[sizeof(MenuValueDescriptor) == 8 ? 1 : -1];

class ScrapHeapBuffer;
struct EmptyStruct
{
};
template <class K, class V> class BSMapBase
{
  public:
    bool GetAt(K, V&);
};

extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f34e0;
MenuValueDescriptor* __cdecl LoadCompressedXML(const char*, int);
void __fastcall FUN_00a0c900(void*, const char*, MenuValueDescriptor*);

// Looks up an XML file by name in DAT_011f34e0; if missing, loads it via LoadCompressedXML and optionally inserts it into the map.
// @fnv 0x00a1c9b0
MenuValueDescriptor* __cdecl GetOrLoadXML(const char* apFilename, bool abAdd)
{
    const char* pfilename = Menu::GetMenuPath(apFilename);
    MenuValueDescriptor* foundXML = 0;
    int pad[12];
    DAT_011f34e0.GetAt((unsigned long)pfilename, (ScrapHeapBuffer*&)foundXML);
    if (foundXML == 0)
    {
        foundXML = LoadCompressedXML(apFilename, 0);
        if (abAdd)
        {
            ((void(__thiscall*)(void*, const char*, MenuValueDescriptor*)) & FUN_00a0c900)(&DAT_011f34e0, pfilename,
                                                                                           foundXML);
        }
    }
    return foundXML;
}

struct FUN_00a1d910_shell : public Menu
{
    void FUN_00a1d910();
};

struct TileQ
{
    bool ContainsTrait(int aiTrait);
    float GetFloat(int aiTrait);
};
extern double _gModifierZero;
void __cdecl FUN_00706f50(Menu* m, float f);
void __cdecl FUN_00706fd0(int a, int b);
void __cdecl FUN_00706f70();
// @fnv 0x00a1d910
void FUN_00a1d910_shell::FUN_00a1d910()
{
    TileQ* t = (TileQ*)pMenu;
    float ffade;
    if (!t->ContainsTrait(0xfa3))
        return;
    ffade = ((TileQ*)pMenu)->GetFloat(0xfc1);
    if (ffade == _gModifierZero)
        ffade = ((TileQ*)pMenu)->GetFloat(0xfc2);
    FUN_00706f50(this, ffade);
    m_eFadeState = 2;
    if (m_iModalMenuId)
    {
        TileQ* t2 = (TileQ*)pMenu;
        if (t2->ContainsTrait(0x1772))
        {
            FUN_00706fd0(m_iModalMenuId, 0);
            Interface::ClearInterfaceState(0);
        }
    }
    FUN_00706f70();
}

struct FUN_00a1db20_shell : public Menu
{
    void FUN_00a1db20();
};

class TileEx : public Tile
{
  public:
    float GetFloat(int aiTrait);
};

void __cdecl FUN_00706f50(Menu* apMenu, float afFade);
void __cdecl FUN_00706f70();

// @fnv 0x00a1db20
void FUN_00a1db20_shell::FUN_00a1db20()
{
    float ffade = pMenu ? reinterpret_cast<TileEx*>(pMenu)->GetFloat(0xfc1) : 0.25f;
    if (ffade == 0.0)
        ffade = reinterpret_cast<TileEx*>(pMenu)->GetFloat(0xfc2);
    FUN_00706f50(this, ffade);
    m_eFadeState = 8;
    FUN_00706f70();
}

struct FUN_00a0c7c0_Helper
{
    void AddToHead(Tile__TileTemplate** pItem);
};

class FUN_00a1dd80_Class : public Menu
{
  public:
    void FUN_00a1dd80(Tile__TileTemplate* apTemplate);
};

// @fnv 0x00a1dd80
void FUN_00a1dd80_Class::FUN_00a1dd80(Tile__TileTemplate* apTemplate)
{
    int u1;
    int u2;
    int u3;
    if (apTemplate != 0)
    {
        reinterpret_cast<FUN_00a0c7c0_Helper*>(&this->m_kTileTemplateList)->AddToHead(&apTemplate);
    }
}

namespace fnv_00a1ca20 {
namespace fnv_00a0be10 {
struct MenuValueDescriptor;
struct XMLStorageX
{
    MenuValueDescriptor* FUN_00a0be10(unsigned int);
};
}
struct MapX_00a1e240
{
    void FUN_00a1e240(const char*);
};
class ScrapHeapBuffer;
template <class K, class V> class BSMapBase
{
  public:
    bool GetAt(K key, V& value);
};
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f34e0;
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f34f4;
class MemoryManager
{
  public:
    void Deallocate(void* pointer);
};
extern MemoryManager g_memoryManager;
struct BuildStorageX
{
    char pad[0x10];
    bool bFlag;
    void FUN_00a0ad40();
    void* DeleteThis(unsigned int flags)
    {
        FUN_00a0ad40();
        if (flags & 1)
            g_memoryManager.Deallocate(this);
        return this;
    }
};
// @fnv 0x00a1ca20
void RemoveMenuEntries(const char* apFilename, Menu* apMenu)
{
    ScrapHeapBuffer* pXmlStorage;
    {
        ScrapHeapBuffer* pBuildStorage;
        {
            const char* pFilename;
            pFilename = Menu::GetMenuPath(apFilename);
            pXmlStorage = 0;
            DAT_011f34e0.GetAt((unsigned long)pFilename, pXmlStorage);
            if (pXmlStorage)
            {
                fnv_00a0be10::XMLStorageX* t2;
                {
                    fnv_00a0be10::XMLStorageX* t1;
                    t1 = (fnv_00a0be10::XMLStorageX*)pXmlStorage;
                    t2 = t1;
                    t2 ? t2->FUN_00a0be10(1) : 0;
                }
                pXmlStorage = 0;
            }
            ((MapX_00a1e240*)&DAT_011f34e0)->FUN_00a1e240(pFilename);
            pBuildStorage = 0;
            DAT_011f34f4.GetAt((unsigned long)pFilename, pBuildStorage);
            if (pBuildStorage)
            {
                if (apMenu && ((BuildStorageX*)pBuildStorage)->bFlag)
                {
                    ((BuildStorageX*)pBuildStorage)->bFlag = false;
                    apMenu->m_bVisible = true;
                }
                BuildStorageX* t4;
                {
                    BuildStorageX* t3;
                    t3 = (BuildStorageX*)pBuildStorage;
                    t4 = t3;
                    {
                        int pad[13];
                        t4 ? t4->DeleteThis(1) : 0;
                    }
                }
                pBuildStorage = 0;
            }
            ((MapX_00a1e240*)&DAT_011f34f4)->FUN_00a1e240(pFilename);
        }
    }
}
}  // namespace fnv_00a1ca20

struct FUN_00a1dc70_shell : public Menu
{
    void FUN_00a1dc70(TileMenu*, bool);
};

void FUN_00706fb0(int, int);
Tile* FUN_00707040();
void FUN_00707050(Tile*);
Menu* GetFieldD0();
void FUN_00707080(Menu*);
struct TileGF
{
    float GetFloat(int);
};
struct MenuVt13
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
};
// @fnv 0x00a1dc70
void FUN_00a1dc70_shell::FUN_00a1dc70(TileMenu* apMenu, bool abDontAddToStack)
{
    pMenu = apMenu;
    if (apMenu)
    {
        if (((TileGF*)apMenu)->GetFloat(0xfa7) == 102.0 || ((TileGF*)apMenu)->GetFloat(0xfa7) == 6006.0 ||
            ((TileGF*)apMenu)->GetFloat(0xfa7) == 103.0 || ((TileGF*)apMenu)->GetFloat(0xfa7) == 6007.0)
        {
            m_iModalMenuId = ((MenuVt13*)this)->v13();
            if (!abDontAddToStack)
                FUN_00706fb0(((MenuVt13*)this)->v13(), 0);
            if (GetFieldD0() != this)
            {
                if (FUN_00707040())
                {
                    Tile* pTile = FUN_00707040();
                    pTile->Set(0xfc3, 0.0f, true);
                }
                FUN_00707050(0);
                FUN_00707080(0);
            }
        }
    }
}

struct BSFile;
struct NiBinaryStream;
struct NiFile;
struct SaveContentDescriptor;
struct _iobuf;
struct blob16
{
    char b[16];
};
struct blob308
{
    char b[308];
};

class MemoryManager;
extern MemoryManager g_memoryManager;
struct P03MM
{
    void* Allocate(unsigned int auSize);
    void _DeallocateAlias(void* apMem);
};
inline void* operator new(size_t auSize)
{
    return ((P03MM*)&g_memoryManager)->Allocate(auSize);
}
inline void* operator new[](size_t auSize)
{
    return ((P03MM*)&g_memoryManager)->Allocate(auSize);
}
inline void operator delete(void* apMem)
{
    ((P03MM*)&g_memoryManager)->_DeallocateAlias(apMem);
}
inline void operator delete[](void* apMem)
{
    ((P03MM*)&g_memoryManager)->_DeallocateAlias(apMem);
}
struct FileFinder
{
    static NiFile* __cdecl GetFile(const char* apName, int aeMode, unsigned int auiBufferSize, unsigned int auiUnk);
};
struct BSFile
{
    virtual ~BSFile();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int GetSize();
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(BSFile* apThis, void* apBuffer, unsigned int auiBytes, unsigned int* apuiSizes,
                              unsigned int auiNum);
    char pad0C[0x20];
    bool m_bGood;
    bool IsGood()
    {
        return m_bGood;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 1;
        unsigned int uiBytesRead = BinaryRead(pvBuffer, uiBytes, &uiSize, 1);
        return uiBytesRead;
    }
};
struct CompressedXML
{
    int iSize;
    char* pData;
    CompressedXML(int aiSize, char* apData) : iSize(aiSize), pData(apData)
    {}
};
// @fnv 0x00a1ce70
CompressedXML* LoadCompressedXML(const char* apFilename, const char* apFileData)
{
    char* pbuf = 0;
    char* pfileData = 0;
    bool bdeletefiledata = false;
    unsigned int ifileSize = 0;
    if (!apFileData)
    {
        BSFile* pfile = (BSFile*)FileFinder::GetFile(apFilename, 0, 0x4000, 0x100);
        if (!pfile || !pfile->IsGood())
        {
            delete pfile;
            return 0;
        }
        ifileSize = pfile->GetSize();
        pfileData = new char[ifileSize];
        bdeletefiledata = true;
        pfile->Read(pfileData, ifileSize);
        delete pfile;
    }
    else
    {
        pfileData = (char*)apFileData;
        ifileSize = strlen(pfileData);
    }
    pbuf = new char[ifileSize];
    unsigned int ilinelen = 0;
    bool bnewline = false;
    bool bnewline_now = false;
    bool bcomment = false;
    int ipos = 0;
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    for (unsigned int a = 0; a < ifileSize && pfileData[a]; a++)
    {
        if (pfileData[a] == '\t' || pfileData[a] == '\n' || pfileData[a] == '\r')
            continue;
        if (bcomment)
        {
            if (c2 == '-' && c1 == '-' && pfileData[a] == '>')
                bcomment = false;
            c3 = c2;
            c2 = c1;
            c1 = pfileData[a];
            continue;
        }
        if (pfileData[a] == ' ')
        {
            if (c1 == ' ' || c1 == '>')
                continue;
        }
        else if (c1 == ' ' && (pfileData[a] == '<' || pfileData[a] == '>'))
        {
            ipos--;
        }
        else if (c2 == ' ' && c1 == '/' && pfileData[a] == '>')
        {
            ipos--;
            pbuf[ipos - 1] = '/';
        }
        else if (c3 == '<' && c2 == '!' && c1 == '-' && pfileData[a] == '-')
        {
            c3 = c2 = c1 = 0;
            ipos -= 3;
            bcomment = true;
            continue;
        }
        if (ilinelen > 100000)
        {
            if (bnewline && pfileData[a] == '>')
                bnewline_now = true;
            else if (c1 == '<' && pfileData[a] == '/')
                bnewline = true;
        }
        pbuf[ipos] = pfileData[a];
        ipos++;
        c3 = c2;
        c2 = c1;
        c1 = pfileData[a];
        ilinelen++;
        if (bnewline_now)
        {
            bnewline = false;
            bnewline_now = false;
            pbuf[ipos] = '\n';
            ipos++;
            ilinelen = 0;
        }
    }
    pbuf[ipos] = 0;
    if (bdeletefiledata)
        delete[] pfileData;
    return new CompressedXML(ipos, pbuf);
}

struct FUN_00a0c900_shell
{
    void __thiscall FUN_00a0c900(const char*, int);
};

extern int DAT_011f34f4;

// @fnv 0x00a1cb60
void __cdecl FUN_00a1cb60(char const* a1, int aiValue)
{
    int v4[10];
    ((FUN_00a0c900_shell*)&DAT_011f34f4)->FUN_00a0c900(a1, aiValue);
}

namespace fnv_00a1d9e0 {
void FUN_00706f90(Menu* apMenu);
void FUN_00707010(void* apTile, float a, float b);
void __cdecl FUN_00706fd0(int a, int b);
struct TileQ
{
    bool ContainsTrait(int aiTrait);
};
struct FUN_00a1d9e0_shell : Menu
{
    void FUN_00a1d9e0();
};
// @fnv 0x00a1d9e0
void FUN_00a1d9e0_shell::FUN_00a1d9e0()
{
    if (m_eFadeState != 4)
    {
        TileMenu* pTile_d;
        TileMenu* pTile_a;
        TileMenu* pTile_b;
        TileMenu* pTile_c;
        pTile_c = pMenu;
        pTile_c->Set(0xfa3, 0.0f, true);
        pTile_b = pMenu;
        pTile_a = (TileMenu*)*(void**)((char*)pTile_b + 0x2c);
        FUN_00707010(pTile_a, 1.0f, 0.0f);
        m_eFadeState = 2;
        if (m_iModalMenuId)
        {
            pTile_d = pMenu;
            if (((TileQ*)pTile_d)->ContainsTrait(0x1772))
            {
                FUN_00706fd0(m_iModalMenuId, 0);
                Interface::ClearInterfaceState(0);
            }
        }
        FUN_00706f90(this);
    }
}
}  // namespace fnv_00a1d9e0

void FUN_00706f90(Menu* apMenu);
void FUN_00707010(void* apTile_c, float a, float b);
struct FUN_00a1daa0_shell : Menu
{
    void FUN_00a1daa0();
};
// @fnv 0x00a1daa0
void FUN_00a1daa0_shell::FUN_00a1daa0()
{
    if (m_eFadeState == 2)
    {
        void* pTile_a;
        TileMenu* pTile_b;
        TileMenu* pTile_c;
        pTile_c = pMenu;
        pTile_c->Set(0xfa3, 1.0f, true);
        pTile_b = pMenu;
        pTile_a = *(void**)((char*)pTile_b + 0x2c);
        FUN_00707010(pTile_a, 1.0f, 0.0f);
        m_eFadeState = 1;
        FUN_00706f90(this);
    }
}

void FUN_00706f90(Menu* apMenu);
void FUN_00707010(void* apTile_c, float a, float b);
struct FUN_00a1dba0_shell : Menu
{
    void FUN_00a1dba0();
};
// @fnv 0x00a1dba0
void FUN_00a1dba0_shell::FUN_00a1dba0()
{
    if (m_eFadeState == 8)
    {
        void* pTile_a;
        TileMenu* pTile_b;
        TileMenu* pTile_c;
        pTile_c = pMenu;
        pTile_c->Set(0xfa3, 0.0f, true);
        pTile_b = pMenu;
        pTile_a = *(void**)((char*)pTile_b + 0x2c);
        FUN_00707010(pTile_a, 1.0f, 0.0f);
        m_eFadeState = 4;
        FUN_00706f90(this);
    }
}

namespace fnv_00a1e170 {
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
class MemoryManager
{
  public:
    void _DeallocateAlias(void* apMem);
};
extern MemoryManager g_memoryManager;
struct FUN_00a1e170_shell : Menu_007a8b10
{
    void* FUN_00a1e170(unsigned int flags);
};
// Destructs the Menu_007a8b10 base and, if flags has bit 0 set, deallocates this object via g_memoryManager, then returns this.
// @fnv 0x00a1e170
void* FUN_00a1e170_shell::FUN_00a1e170(unsigned int flags)
{
    this->Menu_007a8b10::~Menu_007a8b10();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00a1e170

struct FUN_00a1e4d0_shell
{
    unsigned char pad[8];
    unsigned short m_usMaxSize;
    unsigned char pad2[4];
    unsigned short m_usGrowBy;
    void Resize(unsigned int);
    unsigned int FUN_00a1e4d0(unsigned int uiIndex, Tile*& element);
};
// Grows the array if uiIndex is beyond m_usMaxSize, stores element at uiIndex via SetAt, and returns uiIndex.
// @fnv 0x00a1e4d0
unsigned int FUN_00a1e4d0_shell::FUN_00a1e4d0(unsigned int uiIndex, Tile*& element)
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    if (uiIndex >= m_usMaxSize)
        Resize(m_usGrowBy + uiIndex);
    ((MenuClassArray*)this)->SetAt(uiIndex, element);
    return uiIndex;
}

namespace fnv_00a1cb30 {
class ScrapHeapBuffer;
template <class K, class V> class BSMapBase
{
  public:
    bool GetAt(K a, V& b);
};
extern int DAT_011f34f4;
// Looks up auKey in the map at DAT_011f34f4 and returns the stored pointer, or null if not found.
// @fnv 0x00a1cb30
ScrapHeapBuffer* LookupByKey(unsigned long auKey)
{
    int iPad1;
    int iPad2;
    ScrapHeapBuffer* pkHeap = 0;
    ((BSMapBase<unsigned long, ScrapHeapBuffer*>*)&DAT_011f34f4)->GetAt(auKey, pkHeap);
    return pkHeap;
}
}  // namespace fnv_00a1cb30

namespace fnv_00a1d280 {
struct MemoryManager
{
    void* Allocate(unsigned int auSize);
    void Deallocate(void* apMem);
};
extern MemoryManager g_memoryManager;
inline void* operator new[](size_t stSize)
{
    return g_memoryManager.Allocate(stSize);
}
inline void operator delete[](void* pvMem)
{
    g_memoryManager.Deallocate(pvMem);
}
class NiBinaryStream
{
  public:
    virtual ~NiBinaryStream();
    virtual operator bool() const;
    virtual void Seek(int iNumBytes);
    virtual unsigned int GetPosition() const;
    virtual void SetEndianSwap(bool bDoSwap);
    virtual unsigned int ReadIntoBuffer(void* pvBuffer, unsigned int uiBytes);
    virtual unsigned int WriteFromBuffer(const void* pvBuffer, unsigned int uiBytes);
    virtual unsigned int GetFileSize() const;
};
class BSFile : public NiBinaryStream
{
  public:
    virtual void SeekFrom(int iOffset, int iWhence);
    unsigned int Read(void* apBuffer, unsigned int auSize);
};
struct XMLHeader
{
    unsigned int uiVersion;
    unsigned int ItemUpdateArray;
    unsigned int uiSize;
};
struct XMLEntry
{
    char acName[128];
    unsigned int uiLength;
    char acData[1];
    unsigned int GetLength() const
    {
        return uiLength;
    }
};
BSFile* __cdecl FUN_00afdf00(const char* apPath, int a, int b);
int __cdecl FUN_00a01e20(const char* apName, const char* apData, unsigned int auLength);
void __cdecl FUN_00a1cb60(const char* apName, int aiValue);
void __cdecl FUN_00a0ba50();

// @fnv 0x00a1d280
bool FUN_00a1d280()
{
    bool bSuccess = false;
    BSFile* pkFile = FUN_00afdf00("DATA\\FINAL_MASTER_XML.DAT", 0, 0);
    if (pkFile)
    {
        pkFile->SeekFrom(0, 0);
        unsigned int uiBytesRead;
        XMLHeader kHeader;
        uiBytesRead = pkFile->Read(&kHeader, sizeof(kHeader));
        if (uiBytesRead == sizeof(kHeader) && kHeader.uiVersion == 100)
        {
            char* pBuffer = new char[kHeader.uiSize];
            uiBytesRead = pkFile->Read(pBuffer, kHeader.uiSize);
            if (uiBytesRead == kHeader.uiSize)
            {
                bSuccess = true;
                char* pCurrent = pBuffer;
                for (unsigned int i = 0; i < kHeader.ItemUpdateArray; i++)
                {
                    XMLEntry* pEntry = (XMLEntry*)pCurrent;
                    int iTemplate = FUN_00a01e20(pEntry->acName, pEntry->acData, pEntry->GetLength());
                    FUN_00a1cb60(pEntry->acName, iTemplate);
                    pCurrent += pEntry->GetLength() + 0x84;
                }
                FUN_00a0ba50();
                delete[] pBuffer;
            }
            else
            {
                delete[] pBuffer;
                pBuffer = 0;
            }
        }
        delete pkFile;
    }
    return bSuccess;
}
}  // namespace fnv_00a1d280

struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

struct TileListItem
{
    TileListItem* m_pkNext;
    TileListItem* m_pkPrev;
    Tile* m_element;
};
struct TileChildList
{
    TileListItem* m_pkHead;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    Tile*& GetNext(void*& kPos) const
    {
        Tile*& element = ((TileListItem*)kPos)->m_element;
        kPos = ((TileListItem*)kPos)->m_pkNext;
        return element;
    }
};
struct NiNode;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
};
struct InterfaceRoot
{
    static Tile* __cdecl GetPrimaryInterfaceTile();
};
struct TileH
{
    Menu* GetMenu();
};
struct TGF
{
    float GetFloat(int);
};
struct MenuInfo : public Menu
{
    int GetMenuThickness() const
    {
        return m_iSecondaryValue;
    }
};
Tile* __cdecl GetNextTile();
inline float NiMaxF(float a, float b)
{
    return a > b ? a : b;
}
extern double g_d100;
extern double DAT_0106f290;

// @fnv 0x00a1dfb0
float FUN_00a1dfb0()
{
    void* xelem;
    float fmaxdepth = 0.0f;
    float z;
    Tile* proot = InterfaceRoot::GetPrimaryInterfaceTile();

    xelem = ((TileChildList*)((char*)proot + 4))->GetHeadPos();
    while (xelem)
    {
        Tile* ptile = ((TileChildList*)((char*)proot + 4))->GetNext(xelem);
        if (ptile && ((TileH*)ptile)->GetMenu())
        {
            float fdepth =
                static_cast<MenuInfo*>(((TileH*)ptile)->GetMenu())->GetMenuThickness() + ((TGF*)ptile)->GetFloat(4013);
            fmaxdepth = (fmaxdepth > fdepth) ? fmaxdepth : fdepth;
        }
    }
    z = NiMaxF(10.0f, (float)(int)fmaxdepth) + g_d100;
    if (GetNextTile())
    {
        GetNextTile()->Set(4013, z, true);
        NiPoint3 xyz;
        Tile* pcursor = GetNextTile();
        xyz = *(NiPoint3*)((char*)((NiPointer<NiNode>*)((char*)pcursor + 0x2c))->operator->() + 0x58);
        xyz.y = z * DAT_0106f290;
        *(NiPoint3*)((char*)((NiPointer<NiNode>*)((char*)pcursor + 0x2c))->operator->() + 0x58) = xyz;
    }
    return fmaxdepth + 2.0;
}

namespace fnv_00a1ddb0 {
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
struct FUN_00a1ddb0_shell : public Menu
{
    Tile* AddTileFromTemplate(Tile*, char*, Tile*);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

int __cdecl FUN_00ec6da0(char const*, char const*);
extern char* _EmptyFS;

struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const*);
    static char* GetRealBufferStart(char* const& kHandle)
    {
        return kHandle - 8;
    }
    static long NiAtomicSubtract(long& value)
    {
        return InterlockedDecrement(&value);
    }
    static void DecRefCount(char*& kHandle)
    {
        if (kHandle == _EmptyFS)
            return;
        NiAtomicSubtract(((long*)GetRealBufferStart(kHandle))[0]);
    }
};

struct P03MM
{
    void* Allocate(unsigned int);
    void _DeallocateAlias(void*);
};
extern P03MM _g_memoryManager;

struct NiFixedStringL
{
    char* m_kHandle;
    NiFixedStringL(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = _EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(pcString);
    }
    ~NiFixedStringL()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    bool Equals(char* p)
    {
        if (m_kHandle == p)
            return true;
        if (!p || !m_kHandle)
            return false;
        return !FUN_00ec6da0(m_kHandle, p);
    }
};

class Tile__TileTemplate
{
  public:
    char* name;
};

struct Tile__BuildStorage
{
    void SetTileTemplate(Tile__TileTemplate*);
};

struct FUN_00a0ad40
{
    Tile__TileTemplate* pTemplate;
    int data[4];
    ~FUN_00a0ad40();
};

struct FUN_00a0ac80 : public FUN_00a0ad40
{
    void Init(int*, int);
    FUN_00a0ac80()
    {
        int* pkItem = data;
        int iIndex = 0;
        int iCount = 4;
        int* pkEnd = data + 4;
        pTemplate = 0;
        while (pkItem != pkEnd && iIndex < iCount)
        {
            Init(pkItem, iIndex);
            ++pkItem;
            ++iIndex;
        }
    }
    static void* operator new(unsigned int auSize)
    {
        return _g_memoryManager.Allocate(auSize);
    }
    static void operator delete(void* apMem)
    {
        _g_memoryManager._DeallocateAlias(apMem);
    }
};

extern FUN_00a0ac80* DAT_011f32d0;

struct TmplNode_00a1ddb0
{
    Tile__TileTemplate* m_item;
    TmplNode_00a1ddb0* m_pkNext;
};

struct FUN_00a031b0_shell
{
    Tile* CreateMenuTiles(void*);
};

struct FUN_00a033b0_shell
{
    void FUN_00a033b0(Tile__TileTemplate*);
};

// Looks up a tile template by name in a linked list, builds a tile from it under apParent, and returns the new tile or null.
// @fnv 0x00a1ddb0
Tile* FUN_00a1ddb0_shell::AddTileFromTemplate(Tile* apParent, char* axName, Tile* apLast)
{
    Tile* preturn_val = 0;
    if (apLast)
        m_pMenuTile = apLast;
    Tile__TileTemplate* ptemplate = 0;
    TmplNode_00a1ddb0* pCurrentElementNext = (TmplNode_00a1ddb0*)&m_kTileTemplateList;
    NiFixedStringL nm(axName);
    while (pCurrentElementNext)
    {
        ptemplate = pCurrentElementNext->m_item;
        if (ptemplate && nm.Equals(ptemplate->name))
            break;
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    if (ptemplate)
    {
        FUN_00a0ac80* pbuild = DAT_011f32d0;
        DAT_011f32d0 = new FUN_00a0ac80;
        ((Tile__BuildStorage*)DAT_011f32d0)->SetTileTemplate(ptemplate);
        preturn_val = ((FUN_00a031b0_shell*)apParent)->CreateMenuTiles(ptemplate);
        ((FUN_00a033b0_shell*)preturn_val)->FUN_00a033b0(ptemplate);
        DAT_011f32d0->pTemplate = 0;
        delete DAT_011f32d0;
        DAT_011f32d0 = pbuild;
    }
    return preturn_val;
}
}  // namespace fnv_00a1ddb0

class Tile;

void* g_pTileItemFreeList;

void LockTileItemPool();
void UnlockTileItemPool();

template <class T> class NiTPointerAllocator
{
  public:
    void Deallocate(void* apMem)
    {
        void* pFree = apMem;
        LockTileItemPool();
        void* pOld = g_pTileItemFreeList;
        ((void**)pFree)[1] = 0;
        ((void**)pFree)[0] = pOld;
        g_pTileItemFreeList = pFree;
        UnlockTileItemPool();
    }
};

class TileElement
{
  public:
    TileElement* m_pkNext;
    TileElement* m_pkPrev;
    Tile* m_pkElement;
};

template <class TAlloc, class T, class TItem> class NiTPointerListBase
{
  public:
    TItem* m_pkHead;
    TItem* m_pkTail;
    TAlloc m_kItemCount;

    void RemoveAll()
    {
        TItem* pItem = m_pkHead;
        while (pItem)
        {
            TItem* pNext = pItem->m_pkNext;
            TItem* pDelete = pItem;
            pDelete->m_pkElement = 0;
            m_kItemCount.Deallocate(pDelete);
            pItem = pNext;
        }
        m_pkHead = 0;
        m_pkTail = 0;
    }
};

struct TileItemListBase_00a1bbd0
{
    ~TileItemListBase_00a1bbd0()
    {}
};

struct FUN_00a1bbd0 : TileItemListBase_00a1bbd0,
                      NiTPointerListBase<NiTPointerAllocator<unsigned int>, Tile*, TileElement>
{
    ~FUN_00a1bbd0();
};

// Destructor that removes all items from the tile pointer list by calling RemoveAll().
// @fnv 0x00a1bbd0
FUN_00a1bbd0::~FUN_00a1bbd0()
{
    RemoveAll();
}

namespace fnv_00a1cb80 {
extern "C" void* __cdecl fnv_zlib_memset(void* dst, int val, unsigned int size);

struct IMemoryHeap
{
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Deallocate(void*, bool);
};
struct MemoryPool
{
    int unk00;
    unsigned int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned int unk50;
    void Free(void*);
};
extern MemoryPool* DAT_011f63b8[256];

struct MemoryManager
{
    void* Allocate(unsigned int uiSize);
    bool unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    IMemoryHeap* unk110;
    void FreePointer(void*, int);
    IMemoryHeap* GetHeapForPointer(const void*);
    void Deallocate(void* pvBuffer)
    {
        if (!pvBuffer)
            return;
        if (!unk00)
        {
            FreePointer(pvBuffer, 0);
            return;
        }
        IMemoryHeap* heap = unk110;
        if (!heap)
        {
            FreePointer(pvBuffer, 0);
            return;
        }
        MemoryPool* pool = DAT_011f63b8[(unsigned int)pvBuffer >> 24];
        if (pool && (unsigned int)pvBuffer >= pool->unk04 && (unsigned int)pvBuffer < pool->unk04 + pool->unk50)
        {
            pool->Free(pvBuffer);
            return;
        }
        IMemoryHeap* owner = GetHeapForPointer(pvBuffer);
        if (owner)
            owner->Deallocate(pvBuffer, false);
        else
            FreePointer(pvBuffer, 0);
    }
};
extern MemoryManager _g_memoryManager;

class BSFile
{
  public:
    virtual ~BSFile();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual unsigned int GetFileSize();

    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(BSFile* pThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                              unsigned int uiNumComponents);
    unsigned int (*m_pfnWrite)(BSFile* pThis, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    bool m_bGood;

    inline bool Good() const
    {
        return m_bGood;
    }

    inline unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                                   unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }

    inline unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = 1;
        unsigned int uiBytesRead = BinaryRead(pvBuffer, uiBytes, &uiComponentSize, 1);
        return uiBytesRead;
    }
};

class FileFinder
{
  public:
    static BSFile* GetFile(const char* apPath, int aiMode, unsigned int auiBufferSize, unsigned int auiAccess);
};

struct CompressedXML;
CompressedXML* LoadCompressedXML(const char* apPath, const char* apXML);

struct WeightedMapNode
{
    WeightedMapNode* unk00;
    const char* unk04;
    int unk08;
};
struct MapAllocator
{
    WeightedMapNode* FUN_0043a010();
};
struct FUN_00a0c900_shell
{
    virtual void Unk00();
    virtual unsigned int Hash(const char*);
    virtual bool Equal(const char*, const char*);
    virtual void Set(WeightedMapNode*, const char*, int);
    unsigned int unk04;
    WeightedMapNode** unk08;
    unsigned int unk0C;
    bool unk10;
    void FUN_00a0c900(const char* apPath, int apXML)
    {
        unsigned int bucket = Hash(apPath);
        WeightedMapNode* node = unk08[bucket];
        unsigned int count = 0;
        while (node)
        {
            ++count;
            if (Equal(apPath, node->unk04))
            {
                if (!unk10)
                    node->unk04 = apPath;
                node->unk08 = apXML;
                return;
            }
            node = node->unk00;
        }
        node = ((MapAllocator*)&unk0C)->FUN_0043a010();
        Set(node, apPath, apXML);
        node->unk00 = unk08[bucket];
        unk08[bucket] = node;
        ++unk0C;
    }
};
extern FUN_00a0c900_shell DAT_011f34e0;

// Reads Data\Menus\master_menu_file.txt, parses each @#$%-separated entry into a path and XML, registers them in DAT_011f34e0, and returns the entry count.
// @fnv 0x00a1cb80
int LoadMasterMenuFiles()
{
    BSFile* pFile7 = FileFinder::GetFile("Data\\Menus\\master_menu_file.txt", 0, 0x4000, 4);
    if (!pFile7 || !pFile7->Good())
    {
        return 0;
    }

    char pathBuffer6[256];
    char* _cur_ptr;
    int kBufSize;
    char* found9;
    int size3;
    char* buffer3;
    int count7;
    const char* stripped2;
    int lengthX;
    char* endPtr;
    char* xml2;
    CompressedXML* pXML2;

    size3 = pFile7->GetFileSize() + 1;
    buffer3 = (char*)_g_memoryManager.Allocate(size3);
    count7 = 0;

    size3 = pFile7->Read(buffer3, size3);

    delete pFile7;

    _cur_ptr = buffer3;
    found9 = strstr(_cur_ptr, "@#$%");
    kBufSize = 256;

    while (found9)
    {
        fnv_zlib_memset(pathBuffer6, 0, kBufSize);

        xml2 = strstr(_cur_ptr, ".xml");
        endPtr = xml2 + 4;
        do
        {
            xml2--;
        } while (*xml2 != ' ' && *xml2 != '-');
        xml2++;

        lengthX = endPtr - xml2;
        memcpy(pathBuffer6, xml2, lengthX);
        *found9 = 0;

        pXML2 = LoadCompressedXML(pathBuffer6, _cur_ptr);
        stripped2 = Menu::GetMenuPath(pathBuffer6);
        DAT_011f34e0.FUN_00a0c900(stripped2, (int)pXML2);

        count7++;
        _cur_ptr = found9 + 4;
        found9 = 0;
        if (_cur_ptr - buffer3 < size3)
        {
            found9 = strstr(_cur_ptr, "@#$%");
        }
    }

    _g_memoryManager.Deallocate(buffer3);
    return count7;
}
}  // namespace fnv_00a1cb80

namespace fnv_00a1d410 {
// Writes every registered compressed entry to "final_master_xml.dat": a 12-byte header, then for each
// entry a 128-byte name, the 4-byte length and the payload. Returns false if any write came up short.
struct CompressedEntry
{
    unsigned int m_uiCharacterCount;
    unsigned char* m_pCompressedData;
};
extern int DAT_01095574;
extern int DAT_01095524;
extern int DAT_0103d420;
extern int DAT_0103d418;
extern const char DAT_01095548[];
extern const char DAT_01095528[];
void __cdecl FUN_00a02d40(CompressedEntry* apEntry);
void __cdecl FUN_00406d00(char* apBuffer, unsigned int auiSize, const char* apFormat, const char* apName,
                          unsigned int auiLength);
void __cdecl FUN_0040fbe0(const char* apText);
void __cdecl FUN_00aa10f0(void* apMem);
void* __cdecl FUN_00ec61c0(void* apDst, int aiValue, unsigned int auiSize);
int __cdecl FUN_00ec65a6(char* apDst, unsigned int auiSize, const char* apSrc);

struct MapItem
{
    MapItem* m_pkNext;
    const char* m_pcKey;
    CompressedEntry* m_pkVal;
};
struct EntryMap
{
    unsigned int m_uiHashSize;
    unsigned int* m_ppkHashTable;
    unsigned int GetFirstPos()
    {
        for (unsigned int i = 0; i < m_uiHashSize; ++i)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey);
    void GetNext(unsigned int& kPos, const char*& pcName, CompressedEntry*& pkEntry)
    {
        MapItem* pkItem = (MapItem*)kPos;
        pcName = pkItem->m_pcKey;
        pkEntry = pkItem->m_pkVal;
        if (pkItem->m_pkNext)
        {
            kPos = (unsigned int)pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_pcKey);
        unsigned int nextBucket = i + 1;
        for (; nextBucket < m_uiHashSize; ++nextBucket)
        {
            pkItem = (MapItem*)m_ppkHashTable[nextBucket];
            if (pkItem)
            {
                kPos = (unsigned int)pkItem;
                return;
            }
        }
        kPos = 0;
    }
};
extern EntryMap DAT_011f34e0;

struct MemoryManager
{
    void* Allocate(unsigned int auiSize);
};
extern MemoryManager DAT_011f6238;

struct EntryArray
{
    int* m_vtbl;
    CompressedEntry** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int m_uiGrowBy;
    void FUN_00a1e450(unsigned int auiMax, unsigned int auiGrowBy);
    unsigned int SetAtGrow(unsigned int auiIndex, CompressedEntry*& apEntry);
    CompressedEntry* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    static void Deallocate(void* apMem)
    {
        FUN_00aa10f0(apMem);
    }
    EntryArray()
    {
        FUN_00a1e450(0, 1);
        m_vtbl = &DAT_01095574;
    }
    ~EntryArray()
    {
        m_vtbl = &DAT_01095524;
        Deallocate(m_pBase);
    }
};
struct NameArray
{
    int* m_vtbl;
    const char** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    void FUN_005e0a30(unsigned int auiMax, unsigned int auiGrowBy);
    void Add(const char*& apName);
    const char* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    static void Deallocate(void* apMem)
    {
        FUN_00aa10f0(apMem);
    }
    NameArray()
    {
        FUN_005e0a30(0, 1);
        m_vtbl = &DAT_0103d420;
    }
    ~NameArray()
    {
        m_vtbl = &DAT_0103d418;
        Deallocate(m_pBase);
    }
};

struct BSFileX
{
    virtual ~BSFileX();
    unsigned int m_uiStreamFlags;
    int m_iUnk08;
    unsigned int(__cdecl* m_pfnWrite)(BSFileX* apThis, const void* apBuffer, unsigned int auiBytes,
                                      unsigned int* apuiComponentSizes, unsigned int auiNumComponents);
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    unsigned int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    unsigned int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    unsigned int unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c;
    unsigned int unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    unsigned int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154;
    BSFileX(const char* apName, int aiMode, unsigned int auiBufferSize, bool abFlag);
    static void* operator new(unsigned int auiSize)
    {
        return DAT_011f6238.Allocate(auiSize);
    }
    static void operator delete(void* apMem);
    unsigned int BinaryWrite(const void* apBuffer, unsigned int auiTotalBytes, unsigned int* apuiComponentSizes,
                             unsigned int auiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, apBuffer, auiTotalBytes, apuiComponentSizes, auiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    unsigned int Write(const void* apBuffer, unsigned int auiBytes)
    {
        unsigned int uiSize = 1;
        unsigned int uiBytesWritten = BinaryWrite(apBuffer, auiBytes, &uiSize, 1);
        return uiBytesWritten;
    }
};

struct FileHeader
{
    unsigned int m_uiFormatVersion;
    unsigned int m_uiCount;
    unsigned int m_uiTotal;
};

// @fnv 0x00a1d410
bool WriteCompressedEntryArchive()
{
    unsigned int a;
    {
        bool f = true;
        {
            FileHeader g;
            g.m_uiFormatVersion = 100;
            g.m_uiTotal = 0;
            g.m_uiCount = 0;
            {
                BSFileX* b;
                {
                    EntryArray records;
                    NameArray names;
                    unsigned int e = DAT_011f34e0.GetFirstPos();
                    while (e != 0)
                    {
                        char debug[260];
                        {
                            CompressedEntry* entry;
                            {
                                const char* index;
                                DAT_011f34e0.GetNext(e, index, entry);
                                FUN_00a02d40(entry);
                                records.SetAtGrow(records.m_usSize, entry);
                                names.Add(index);
                                FUN_00406d00(debug, 0x104, DAT_01095548, index, entry->m_uiCharacterCount);
                                FUN_0040fbe0(debug);
                                g.m_uiTotal += 0x84 + entry->m_uiCharacterCount;
                                ++g.m_uiCount;
                            }
                        }
                    }
                    b = new BSFileX(DAT_01095528, 1, 0x4000, false);
                    a = b->Write(&g, 12);
                    if (a == 12)
                    {
                        for (unsigned int i = 0; i < g.m_uiCount; ++i)
                        {
                            CompressedEntry* element = records.GetAt(i);
                            {
                                char filename[128];
                                {
                                    const char* name = names.GetAt(i);
                                    FUN_00ec61c0(filename, 0, 128);
                                    FUN_00ec65a6(filename, 128, name);
                                    a = b->Write(filename, 128);
                                    if (a != 128)
                                        f = false;
                                    a = b->Write(element, 4);
                                    if (a != 4)
                                        f = false;
                                    a = b->Write(element->m_pCompressedData, element->m_uiCharacterCount);
                                    if (a != element->m_uiCharacterCount)
                                        f = false;
                                    if (!f)
                                        break;
                                }
                            }
                        }
                    }
                    else
                    {
                        f = false;
                    }
                    delete b;
                    return f;
                }
            }
        }
    }
}
}  // namespace fnv_00a1d410

namespace fnv_00a1c520 {
extern bool DAT_011f308f[];
int FUN_00706fd0(int, bool);
void FUN_00a1e130(int, Tile*);
int FUN_007023c0();
class MemoryManager
{
  public:
    void* Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
class InputManager
{
  public:
    int FUN_00a24660(int, int);
    void SetFlag(unsigned short flag)
    {
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x1b92) |= flag;
    }
};
class OSGlobals
{
  public:
    InputManager* FUN_00877720();
};
extern OSGlobals* g_osGlobals;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern const char* g_nullFixedString;
struct TemplateName
{
    const char* m_kHandle;
    ~TemplateName()
    {
        if (m_kHandle == g_nullFixedString)
            return;
        long* p = (long*)(m_kHandle - 8);
        InterlockedDecrement(p);
    }
};
struct TemplateItemNode
{
    void* m_item;
    TemplateItemNode* m_pkNext;
    ~TemplateItemNode()
    {}
};
struct TemplateItemList : TemplateItemNode
{
    void RemoveAll();
    ~TemplateItemList()
    {
        RemoveAll();
    }
};
class TileCollection
{
  public:
    TemplateName kName;
    int unk04;
    TemplateItemList kItems;
    void Destroy();
    ~TileCollection()
    {
        Destroy();
    }
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
class MenuOwner;
struct TileOwner
{
    virtual ~TileOwner();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    MenuOwner* pMenu;
    void SetMenu(MenuOwner* menu)
    {
        pMenu = menu;
    }
};
struct TemplateList
{
    TileCollection* m_item;
    TemplateList* m_pkNext;
    void RemoveAll()
    {
        while (m_pkNext)
        {
            TemplateList* next = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = next;
        }
        m_item = 0;
    }
    ~TemplateList()
    {
        RemoveAll();
    }
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
class FUN_00a1c520
{
  public:
    virtual ~FUN_00a1c520();
    TileOwner* pMenu;
    TemplateList m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    int m_iMenuId;
    int m_eFadeState;
};
inline void ClearMenuClass(int menuClass)
{
    if (menuClass >= 1001 && menuClass <= 1084)
        DAT_011f308f[menuClass] = false;
}
// Clears the menu class, conditionally calls FUN_00706fd0, deletes the menu owner and visible tile collections, and removes template-list nodes.
// @fnv 0x00a1c520
FUN_00a1c520::~FUN_00a1c520()
{
    ClearMenuClass(m_iMenuId);
    if (m_iModalMenuId)
        FUN_00706fd0(m_iModalMenuId, 1);
    FUN_00a1e130(m_iMenuId, 0);
    if (pMenu)
    {
        pMenu->SetMenu(0);
        delete pMenu;
    }
    pMenu = 0;
    if (m_bVisible)
    {
        TemplateList* item = &m_kTileTemplateList;
        while (item)
        {
            TileCollection* value = item->m_item;
            if (value)
                delete value;
            item = item->m_pkNext;
        }
    }
    m_kTileTemplateList.RemoveAll();
    if (!FUN_007023c0() && g_osGlobals->FUN_00877720()->FUN_00a24660(14, 0))
        g_osGlobals->FUN_00877720()->SetFlag(8);
}
}  // namespace fnv_00a1c520
