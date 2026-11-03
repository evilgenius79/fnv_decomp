// bsmenu/font.cpp: Font, FontManager, OwnQ, SBox and more (57 functions)

#include "font_types.h"

void Font::MapCharacter(unsigned char& character)
{
    switch (character)
    {
    case 0x91:
    case 0x92:
        character = '\'';
        break;
    case 0x93:
    case 0x94:
        character = '"';
        break;
    }
}

float FontManager::GetFontPadding(int font)
{
    float padding = 0.0f;
    switch (font)
    {
    case 3:
        padding = 6.0f;
        break;
    case 7:
        padding = 2.0f;
        break;
    case 2:
    case 6:
        padding = 4.0f;
        break;
    }
    return padding;
}

// @fnv 0x005bd5b0
FontManager* FontManager::Instance()
{
    return pInstance;
}

#include "font_geometry_types.h"

// Complete compiled WIP for Font::AddCharacterToShape at 00a142d0; see NOTES.md.
// Coordinate records contain genuine glyph coordinates, never frame storage.
void Font::AddCharacterToShape(FontCharacterInfo* letter, int index, NiTriShape* shape,
                   NiPoint3& position, const RgbaColor* color)
{
    position.x += letter->m_fHorizontalAdvance;
    int baseVertex = index * 4;
    NiGeometryData* vertexData = shape->m_spGeometryData.m_pObject;
    NiPoint3* vertexArray = vertexData->m_pkVertex;
    NiPoint3* vertices = vertexArray + baseVertex;

    struct GlyphCornerCoordinates { float x; float y; float z; };
    GlyphCornerCoordinates topLeftCoordinates;
    topLeftCoordinates.x = position.x;
    topLeftCoordinates.y = position.y;
    topLeftCoordinates.z = letter->m_fVerticalOffset + position.z;
    NiPoint3 topLeft;
    topLeft.x = topLeftCoordinates.x;
    topLeft.y = topLeftCoordinates.y;
    topLeft.z = topLeftCoordinates.z;
    vertices[0] = topLeft;

    GlyphCornerCoordinates bottomLeftCoordinates;
    bottomLeftCoordinates.x = position.x;
    bottomLeftCoordinates.y = position.y;
    bottomLeftCoordinates.z = (letter->m_fVerticalOffset + position.z) - letter->m_fGlyphExtent;
    NiPoint3 bottomLeft;
    bottomLeft.x = bottomLeftCoordinates.x;
    bottomLeft.y = bottomLeftCoordinates.y;
    bottomLeft.z = bottomLeftCoordinates.z;
    vertices[1] = bottomLeft;

    GlyphCornerCoordinates topRightCoordinates;
    topRightCoordinates.x = letter->m_fGlyphWidthInPixels + position.x;
    topRightCoordinates.y = position.y;
    topRightCoordinates.z = letter->m_fVerticalOffset + position.z;
    NiPoint3 topRight;
    topRight.x = topRightCoordinates.x;
    topRight.y = topRightCoordinates.y;
    topRight.z = topRightCoordinates.z;
    vertices[2] = topRight;

    GlyphCornerCoordinates bottomRightCoordinates;
    bottomRightCoordinates.x = letter->m_fGlyphWidthInPixels + position.x;
    bottomRightCoordinates.y = position.y;
    bottomRightCoordinates.z = (letter->m_fVerticalOffset + position.z) - letter->m_fGlyphExtent;
    NiPoint3 bottomRight;
    bottomRight.x = bottomRightCoordinates.x;
    bottomRight.y = bottomRightCoordinates.y;
    bottomRight.z = bottomRightCoordinates.z;
    vertices[3] = bottomRight;

    NiGeometryData* textureData = shape->m_spGeometryData.m_pObject;
    NiPoint2* textureArray = textureData->m_pkTexture;
    NiPoint2* textureCoordinates = textureArray + baseVertex;

    struct GlyphTextureCoordinates { float u; float v; };
    GlyphTextureCoordinates topLeftUV;
    topLeftUV.u = letter->pMapping[0].fTextureCoordinateU;
    topLeftUV.v = letter->pMapping[0].fV;
    NiPoint2 topLeftTexture;
    topLeftTexture.x = topLeftUV.u;
    topLeftTexture.y = topLeftUV.v;
    textureCoordinates[0] = topLeftTexture;

    GlyphTextureCoordinates bottomLeftUV;
    bottomLeftUV.u = letter->pMapping[2].fTextureCoordinateU;
    bottomLeftUV.v = letter->pMapping[2].fV;
    NiPoint2 bottomLeftTexture;
    bottomLeftTexture.x = bottomLeftUV.u;
    bottomLeftTexture.y = bottomLeftUV.v;
    textureCoordinates[1] = bottomLeftTexture;

    GlyphTextureCoordinates topRightUV;
    topRightUV.u = letter->pMapping[1].fTextureCoordinateU;
    topRightUV.v = letter->pMapping[1].fV;
    NiPoint2 topRightTexture;
    topRightTexture.x = topRightUV.u;
    topRightTexture.y = topRightUV.v;
    textureCoordinates[2] = topRightTexture;

    GlyphTextureCoordinates bottomRightUV;
    bottomRightUV.u = letter->pMapping[3].fTextureCoordinateU;
    bottomRightUV.v = letter->pMapping[3].fV;
    NiPoint2 bottomRightTexture;
    bottomRightTexture.x = bottomRightUV.u;
    bottomRightTexture.y = bottomRightUV.v;
    textureCoordinates[3] = bottomRightTexture;

    NiTriShapeData* triangleData =
        static_cast<NiTriShapeData*>(shape->m_spGeometryData.m_pObject);
    unsigned short* triangles = triangleData->GetTriangleList() + index * 6;
    triangles[0] = static_cast<unsigned short>(baseVertex);
    triangles[1] = static_cast<unsigned short>(baseVertex + 1);
    triangles[2] = static_cast<unsigned short>(baseVertex + 2);
    triangles[3] = static_cast<unsigned short>(baseVertex + 2);
    triangles[4] = static_cast<unsigned short>(baseVertex + 1);
    triangles[5] = static_cast<unsigned short>(baseVertex + 3);

    position.x += letter->m_fGlyphWidthInPixels + (letter->m_fGlyphWidthInPixels > 0.0 ? letter->m_fHorizontalSpacing : 0.0f);
}

// Replaces smart single and double quote bytes with plain apostrophe and double quote characters in place.
// @fnv 0x00a122b0
void __cdecl NormalizeSmartQuotes(unsigned char* acChar)
{
    switch (*acChar)
    {
    case 0x91:
    case 0x92:
        *acChar = '\'';
        break;
    case 0x93:
    case 0x94:
        *acChar = '"';
        break;
    }
}

struct FUN_00a1b3a0_shell : public FontManager {
    float FUN_00a1b3a0(int);
};

// Returns a line padding value based on the font index: 6.0 for 3, 2.0 for 7, 4.0 for 2 or 6, otherwise 0.0.
// @fnv 0x00a1b3a0
float FUN_00a1b3a0_shell::FUN_00a1b3a0(int aiFont)
{
    float flinePadding = 0.0f;
    switch (aiFont)
    {
    case 3:
        flinePadding = 6.0f;
        break;
    case 7:
        flinePadding = 2.0f;
        break;
    case 2:
    case 6:
        flinePadding = 4.0f;
        break;
    }
    return flinePadding;
}

extern char str_010a435c[];

unsigned int __cdecl strlen(const char*);
int __cdecl _stricmp(const char*, const char*);
int __cdecl _strnicmp(const char*, const char*, unsigned int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);

// Builds dst from src: prefixes "Trees" when src ends in "spt", prefixes str_010a435c unless src starts with "meshes\", else copies src.
// @fnv 0x00af4250
void __cdecl BuildAssetPath(const char* pcSourcePath, char* pcDestPath, unsigned int uiDestSize)
{
    unsigned int len = strlen(pcSourcePath);
    if (len > 3 && _stricmp(pcSourcePath + len - 3, "spt") == 0) {
        strcpy_s(pcDestPath, uiDestSize, "Trees");
        strcat_s(pcDestPath, uiDestSize, pcSourcePath);
    } else if (_strnicmp(pcSourcePath, "meshes\\", 7) != 0) {
        strcpy_s(pcDestPath, uiDestSize, str_010a435c);
        strcat_s(pcDestPath, uiDestSize, pcSourcePath);
    } else {
        strcpy_s(pcDestPath, uiDestSize, pcSourcePath);
    }
}

void __cdecl BuildAssetPath(int, char*, int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
struct FUN_00c3d090_shell2 {
    char pad[0x28];
    char* p;
    void FUN_00c3d090(int flag, char* dst);
};
// @fnv 0x00c3d090
void FUN_00c3d090_shell2::FUN_00c3d090(int flag, char* dst)
{
    if (flag == 0) {
        BuildAssetPath((int)p, dst, 0x104);
    } else {
        char* src = p;
        strcpy_s(dst, 0x104, src);
    }
}

struct MemoryManager { void* Allocate(unsigned int); };
extern MemoryManager g_memoryManager;
struct fnv_00a168b0 {
    char data[0x24];
    fnv_00a168b0();
    static __forceinline void* operator new(unsigned int s) { return g_memoryManager.Allocate(s); }
    static __forceinline void operator delete(void*) {}
};

// Allocates a new FontManager instance and stores it in FontManager::pInstance if none exists.
// @fnv 0x00a167c0
void CreateFontManager()
{
    if (!FontManager::pInstance)
        FontManager::pInstance = (FontManager*)new fnv_00a168b0;
}

struct FUN_00a152d0_shell {
    unsigned short count;
    unsigned short Get() { return count; }
    unsigned short Dec() { --count; return count; }
    void ClearArray();
    void FUN_00a152d0();
};
// Decrements count when non-zero and calls ClearArray once the count reaches zero.
// @fnv 0x00a152d0
void FUN_00a152d0_shell::FUN_00a152d0()
{
    if (Get()) {
        if (!Dec())
            ClearArray();
    }
}

namespace fnv_00a16850 {
struct MemoryManager { void Deallocate(void* p); };
extern MemoryManager g_memoryManager;
struct FUN_00a16850_shell {
    void FUN_00a16d20();
// Calls FUN_00a16d20, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a16850
    FUN_00a16850_shell* Destroy(unsigned int flags)
    {
        FUN_00a16d20();
        if (flags & 1)
            g_memoryManager.Deallocate(this);
        return this;
    }
};
void FUN_00a16850()
{
    if (FontManager::pInstance) {
        FontManager* fm = FontManager::pInstance;
        FUN_00a16850_shell* p = reinterpret_cast<FUN_00a16850_shell*>(fm);
        p ? p->Destroy(1) : 0;
        FontManager::pInstance = 0;
    }
}
}  // namespace fnv_00a16850

namespace fnv_00a16d20 {
struct MemoryManager { void Deallocate(void* p); };
extern MemoryManager g_memoryManager;
struct FUN_00a16d20_font {
    void FUN_00a121e0();
// Calls FUN_00a121e0, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a16d20
    FUN_00a16d20_font* Destroy(unsigned int flags)
    {
        FUN_00a121e0();
        if (flags & 1)
            g_memoryManager.Deallocate(this);
        return this;
    }
};
struct FUN_00a16d20_shell {
    FUN_00a16d20_font* pFont[8];
    void FUN_00a16d20();
};
void FUN_00a16d20_shell::FUN_00a16d20()
{
    for (int i = 0; i < 8; ++i) {
        FUN_00a16d20_font* f = pFont[i];
        FUN_00a16d20_font* p = f;
        p ? p->Destroy(1) : 0;
        pFont[i] = 0;
    }
}
}  // namespace fnv_00a16d20

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_00a1b410_shell { char* p; void ClearPointer(); };
// Sets p to null, then if p is non-null increments the counter at p+4 via InterlockedIncrement.
// @fnv 0x00a1b410
void FUN_00a1b410_shell::ClearPointer()
{
    p = 0;
    if (p) {
        char* q = p;
        InterlockedIncrement((long*)(q + 4));
    }
}

struct FUN_00a1b940 {
    int a;
    int b;
    int c;
    FUN_00a1b940();
};
// Initializes the three integer members a, b and c to zero.
// @fnv 0x00a1b940
FUN_00a1b940::FUN_00a1b940()
{
    c = 0;
    a = 0;
    b = 0;
}

struct BSStr { bool Set(const char*, unsigned int); };
struct FUN_00a1b970_t {
    char pad[0x1c];
    BSStr str;
    void ClearString();
};
// @fnv 0x00a1b970
void FUN_00a1b970_t::ClearString()
{
    double d0, d1, d2, d3;
    str.Set(0, 0);
}

inline void* operator new(unsigned int, void* p) { return p; }
struct FUN_00a1c1f0_vec { float a, b, c, d; FUN_00a1c1f0_vec() { a = 0.0f; b = 0.0f; c = 0.0f; d = 0.0f; } };
struct FUN_00a1c1f0_elem { int pad[4]; FUN_00a1c1f0_vec v; };
struct FUN_00a1c1f0_shell {
    void ConstructElements(FUN_00a1c1f0_elem* apFirstAddr, unsigned int aiCount);
};
// Default-constructs aiCount FUN_00a1c1f0_elem objects in place starting at apFirstAddr.
// @fnv 0x00a1c1f0
void FUN_00a1c1f0_shell::ConstructElements(FUN_00a1c1f0_elem* apFirstAddr, unsigned int aiCount)
{
    unsigned int i;
    FUN_00a1c1f0_elem* item;
    for (i = 0; i < aiCount; ++i)
        item = new (&apFirstAddr[i]) FUN_00a1c1f0_elem;
}

struct FUN_00a1c270_node {
    FUN_00a1c270_node* next;
    FUN_00a1c270_node* prev;
};
struct FUN_00a1c270_shell {
    FUN_00a1c270_node* head;
    FUN_00a1c270_node* tail;
    int count;
    void FUN_00a1c270(FUN_00a1c270_node* node);
};
// Inserts node at the head of the doubly linked list, fixing up prev/next links, tail when empty, and incrementing count.
// @fnv 0x00a1c270
void FUN_00a1c270_shell::FUN_00a1c270(FUN_00a1c270_node* node)
{
    node->prev = 0;
    node->next = head;
    if (head)
        head->prev = node;
    else
        tail = node;
    head = node;
    count = count + 1;
}

namespace fnv_00a1c2d0 {
struct MemoryManager { void Deallocate(void* p); };
extern MemoryManager g_memoryManager;
struct FUN_00a1c2d0_node {
    FUN_00a1c2d0_node* next;
    int pad;
    int data;
};
struct FUN_00a1c2d0_shell {
    FUN_00a1c2d0_node* head;
    FUN_00a1c2d0_node* tail;
    int count;
    void FUN_00a1c2d0();
};
// Walks the linked list from head, zeroes each node's data, deallocates every node, then resets count, head and tail.
// @fnv 0x00a1c2d0
void FUN_00a1c2d0_shell::FUN_00a1c2d0()
{
    FUN_00a1c2d0_node* cur = head;
    while (cur) {
        FUN_00a1c2d0_node* pNode = cur;
        cur = cur->next;
        pNode->data = 0;
        {
            void* p = pNode;
            g_memoryManager.Deallocate(p);
        }
    }
    count = 0;
    head = 0;
    tail = 0;
}
}  // namespace fnv_00a1c2d0

void* __cdecl FUN_00ec7230(void*, const void*, unsigned int);
struct FUN_00a1c400_elem { char b[32]; };
struct FUN_00a1c400_shell {
    void CopyElements(FUN_00a1c400_elem* apDestAddr, FUN_00a1c400_elem* apSrcAddr, unsigned int aiCount);
};
// Copies aiCount elements from apSrcAddr to apDestAddr, iterating forward or backward depending on their relative order.
// @fnv 0x00a1c400
void FUN_00a1c400_shell::CopyElements(FUN_00a1c400_elem* apDestAddr, FUN_00a1c400_elem* apSrcAddr, unsigned int aiCount)
{
    if (aiCount <= 0)
        return;
    if (apDestAddr < apSrcAddr) {
        for (unsigned int i = 0; i < aiCount; ++i)
            FUN_00ec7230(&apDestAddr[i], &apSrcAddr[i], sizeof(FUN_00a1c400_elem));
    } else if (apDestAddr > apSrcAddr) {
        for (int i = aiCount - 1; i >= 0; --i)
            FUN_00ec7230(&apDestAddr[i], &apSrcAddr[i], sizeof(FUN_00a1c400_elem));
    }
}

template <class T> class NiTPointerList {
public:
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    NiTPointerList() { m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    ~NiTPointerList();
};

struct TextItem;

struct FUN_00a19f70_t {
    void WrapLine(void* apSource, unsigned int auiStart);
};

struct FUN_00a1bd40 {
    NiTPointerList<TextItem*> kItemList;
    unsigned int uiNumItems;
    unsigned int uiStart;
    unsigned int uiEnd;
    unsigned int uiLength;
    unsigned int uiFlags;
    unsigned int uiFontNum;
    unsigned int uiMaxWidth;
    unsigned int uiLineNum;
    void* pOwner;
    FUN_00a1bd40(void* apOwner, void* apSource, unsigned int auiFlags, unsigned int auiMaxWidth);
};

// @fnv 0x00a1bd40
FUN_00a1bd40::FUN_00a1bd40(void* apOwner, void* apSource, unsigned int auiFlags, unsigned int auiMaxWidth) {
    uiNumItems = 0;
    uiFontNum = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(apSource) + 0x18);
    uiMaxWidth = auiMaxWidth;
    pOwner = apOwner;
    uiStart = 0;
    uiEnd = 0;
    uiLength = 0;
    uiFlags = auiFlags;
    reinterpret_cast<FUN_00a19f70_t*>(this)->WrapLine(apSource, 0);
}

namespace fnv_00a1c340 {
struct FUN_00a1c400_elem;
struct FUN_00a1c400_shell {
    void CopyElements(FUN_00a1c400_elem*, FUN_00a1c400_elem*, unsigned int);
};

struct FUN_00a1c340_shell {
    virtual void v0() = 0;
    virtual void* Allocate(unsigned int size) = 0;
    virtual void Free(void* p) = 0;
    virtual void* Reallocate(void* p, unsigned int size) = 0;

    void* pBuffer; // +0x04
    unsigned int iSize; // +0x08
    unsigned int SimpleArrayStorage; // +0x0c

    void ResizeBuffer(unsigned int aiNewSize, unsigned int aiCopyCount);
};

// @fnv 0x00a1c340
void FUN_00a1c340_shell::ResizeBuffer(unsigned int aiNewSize, unsigned int aiCopyCount)
{
    void* pnewBuffer;
    void* pUnused1;
    void* p2;

    if (pBuffer)
    {
        if (aiCopyCount == SimpleArrayStorage)
        {
            pBuffer = Reallocate(pBuffer, aiNewSize);
        }
        else
        {
            pnewBuffer = Allocate(aiNewSize);
            ((FUN_00a1c400_shell*)this)->CopyElements((FUN_00a1c400_elem*)pnewBuffer, (FUN_00a1c400_elem*)pBuffer, aiCopyCount);
            Free(pBuffer);
            pBuffer = 0;
            pBuffer = pnewBuffer;
        }
    }
    else
    {
        pBuffer = Allocate(aiNewSize);
        SimpleArrayStorage = aiNewSize;
    }
}
}  // namespace fnv_00a1c340

namespace fnv_00a121e0 {
struct BSStr {
    char pad[8];
    bool Set(char const*, unsigned int);
    ~BSStr() {
        Set(0, 0);
    }
};

struct MM {
    void _DeallocateAlias(void*);
};
extern MM _g_memoryManager;

extern void* DAT_011f33fc;
extern int DAT_011f3400;

struct FUN_00a152d0_shell {
    void ClearArray();
};

struct GO {
    void* p;
    ~GO();
};

struct Member_44 {
    void Reset();
    ~Member_44() {
        Reset();
    }
};

struct FUN_00a121e0 {
    void* field_0;
    void* field_4;
    void* field_8;
    GO field_C[8];
    char pad_2C[0x10];
    BSStr field_3C;
    Member_44 field_44;

    FUN_00a121e0();
    ~FUN_00a121e0();
};

// @fnv 0x00a121e0
FUN_00a121e0::~FUN_00a121e0()
{
    void* pBuffer;
    void* pData = DAT_011f33fc;
    void* apFonts[8];
    _g_memoryManager._DeallocateAlias(pData);
    DAT_011f3400 = 0;
    DAT_011f33fc = 0;
    ((FUN_00a152d0_shell*)this)->ClearArray();
    pBuffer = field_4;
    _g_memoryManager._DeallocateAlias(pBuffer);
}
}  // namespace fnv_00a121e0

namespace fnv_00a14a20 {
struct BSShaderAccumulator;
struct BSShaderProperty;
struct CloningProcess;
struct NiProperty;
struct NiShadeProperty;
struct NiStream;
struct NiTexture;
struct NiUpdateData;
struct TileShaderProperty;
struct blob16 { char b[16]; };
struct FUN_00a14a20_shell : public Font {
    NiTriShape* CreateTextShape(int, void*, bool);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct P03MM { void* Allocate(unsigned int); };
extern P03MM g_memoryManager;
extern char* EmptyFS;
void* NiMalloc(unsigned int);
void __cdecl AttachFaceGenAnimationData(NiAVObject*);
struct BSFadeNode { static void* __cdecl operator new(unsigned int); };
struct NiGlobalStringTable {
    static char* __cdecl AddString(const char*);
    static void DecRef(long* p) { InterlockedDecrement(p); }
};
struct BSShaderManager { static void __cdecl UpdateObjectTypeRecurse(NiAVObject*, bool, bool); };
struct NiAVObject_Attach { void AttachProperty(NiObject*); };
struct AttachWrap {
    void AttachProperty(NiObject* p) {
        int a, b, c, d, e;
        ((NiAVObject_Attach*)this)->AttachProperty(p);
    }
};
struct NiGeometryData_SetConsistency_View { void SetDataConsistency(int); };
struct TileShaderProperty : BSFadeNode {
    char pad[0xb0];
    TileShaderProperty(bool);
    void SetTextureImage(NiTexture*);
};
namespace L {
struct NiFixedString : ::NiFixedString {
    NiFixedString(const char* s) { if (s == 0) m_kHandle = EmptyFS; else m_kHandle = NiGlobalStringTable::AddString(s); }
    ~NiFixedString() {
        if (m_kHandle == EmptyFS) return;
        NiGlobalStringTable::DecRef((long*)(m_kHandle - 8));
    }
};
struct NiGeometryData {
    char pad[0x38];
    unsigned char m_ucKeepFlags;
    unsigned char m_ucCompressFlags;
};
struct GeomPtr { NiGeometryData* m_pObject; operator NiGeometryData*() const { return m_pObject; } NiGeometryData* operator->() const { return m_pObject; } };
struct NiAVObject : BSFadeNode {
    void SetName(const ::NiFixedString&);
    void UpdateSceneObject();
};
struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    static void* operator new[](unsigned int n) { return g_memoryManager.Allocate(n); }
};
struct NiPoint2 {
    float x, y;
    NiPoint2() {}
    static void* operator new[](unsigned int n) { return g_memoryManager.Allocate(n); }
};
struct TexMap { char pad[8]; NiTexture* m_pkTexture; NiTexture* GetTexture() { return m_pkTexture; } };
struct TexProp {
    char pad[0x20];
    TexMap** m_pBase;
    TexMap* GetAt(unsigned int i) const { return m_pBase[i]; }
    NiTexture* GetBaseTexture() {
        TexMap* pMap = GetAt(0);
        if (pMap) return pMap->GetTexture();
        else return 0;
    }
};
struct TexPtr { TexProp* m_pObject; operator TexProp*() const { return m_pObject; } };
struct FUN_00c5cf30 : NiAVObject {
    char pad[0xb8];
    GeomPtr m_spGeometryData;
    NiGeometryData* GetModelData() const { return m_spGeometryData; }
    char pad2[0x18];
    FUN_00c5cf30(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short, int,
        unsigned short, unsigned short*, int, int, int, int);
};
}

// Builds a NiTriShape with vertex, texture and index buffers, attaches a TileShaderProperty, copies the color, and optionally prepares the object.
// @fnv 0x00a14a20
NiTriShape* FUN_00a14a20_shell::CreateTextShape(int aiChars, void* axColor, bool abPrepareObject)
{
    unsigned short* pvert_order;
    TileShaderProperty* ptsp;
    L::NiPoint3* pvertices;
    L::FUN_00c5cf30* pshape;
    int iverts;
    L::NiPoint2* ptextures;
    L::NiGeometryData* pd;

    iverts = aiChars * 4;
    pvertices = new L::NiPoint3[iverts];
    ptextures = new L::NiPoint2[iverts];
    pvert_order = (unsigned short*)NiMalloc(aiChars * 6 * sizeof(unsigned short));
    pshape = new L::FUN_00c5cf30(iverts, pvertices, 0, 0, ptextures, 1, 0, aiChars * 2, pvert_order, 0, 0, 0, 0);
    pd = pshape->GetModelData();
    pd->m_ucKeepFlags = 0;
    pd->m_ucCompressFlags = 1;
    pshape->SetName(L::NiFixedString("Interface: Text"));
    ((NiGeometryData_SetConsistency_View*)pshape->GetModelData())->SetDataConsistency(0x4000);
    ptsp = new TileShaderProperty(false);
    ((AttachWrap*)pshape)->AttachProperty((NiObject*)ptsp);
    *(RgbaColor*)((char*)ptsp + 0x68) = *(const RgbaColor*)axColor;
    if (abPrepareObject)
        BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject*)pshape, false, false);
    ptsp->SetTextureImage(((L::TexProp*)((L::TexPtr*)((char*)this + 0xc))[0])->GetBaseTexture());
    pshape->UpdateSceneObject();
    AttachFaceGenAnimationData((::NiAVObject*)pshape);
    return (NiTriShape*)pshape;
}
}  // namespace fnv_00a14a20

struct FUN_00a16da0_shell {
    int GetCharClassFlags(char c);
};

// Maps a character to a flag value: 0x20 for NUL, 1 for '<'/'{', 2 for '>'/'}', 8 for quotes, 0x10 for '=', 4 for chars <= 0x20, else 0.
// @fnv 0x00a16da0
int FUN_00a16da0_shell::GetCharClassFlags(char acChar)
{
    switch (acChar)
    {
    case 0:
        return 0x20;
    case '<':
    case '{':
        return 1;
    case '>':
    case '}':
        return 2;
    case '\"':
    case '\'':
        return 8;
    case '=':
        return 0x10;
    default:
        if (acChar <= 0x20)
            return 4;
        return 0;
    }
}

namespace fnv_00a19c00 {
struct P03MM { void* Allocate(unsigned int); };
extern P03MM _g_memoryManager;

struct FUN_00a1bd40 {
    char m_data[0x30];
    FUN_00a1bd40(void*, void*, unsigned int, unsigned int);
    static __forceinline void* operator new(unsigned int s) { return _g_memoryManager.Allocate(s); }
    static void operator delete(void*);
};
struct FUN_00a1be10 {
    char m_data[0x44];
    FUN_00a1be10(void*, void*, unsigned int, unsigned int);
    static __forceinline void* operator new(unsigned int s) { return _g_memoryManager.Allocate(s); }
    static void operator delete(void*);
};
struct FUN_00a19f70_t { void* WrapLine(void*, unsigned int); };
struct FUN_00ae8bf0_t {
    void* m_pFirstNode;
    void* m_pTail;
    void AddItem(const void* item)
    {
        void* pNode = m_pFirstNode;
        void* pPrev = m_pTail;
        void* pItem = (void*)item;
        void* pNext = 0;
        if (pNode) pNode = pPrev;
        if (pItem) pNext = pNode;
        m_pTail = pNext;
        if (pNext == item) AddItem(pPrev);
    }
};

struct SStr {
    char* pString;
    __forceinline char* Get() { return pString; }
    __forceinline const char& At(unsigned int i) { return pString[pString ? i : 0]; }
};
struct SItem {
    int m_iType;
    unsigned char cChar;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    SStr kText;
    __forceinline bool TextEmpty() { return !(kText.Get() && kText.At(0)); }
};
struct FontTextureInfo { unsigned int uiTextureID; char acFileName[32]; };
struct SFontDataView {

    float m_fFontSize;
    unsigned int uiNumTextures;
    FontTextureInfo kTextures[8];
    FontCharacterInfo kLetters[256];
};
struct SFontMgr {
    Font* pFont[8];
    __forceinline Font* GetFont(int i) { return pFont[i]; }
};
__forceinline SFontMgr* FontMgrInstance() { return (SFontMgr*)FontManager::pInstance; }

struct SNode {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    int m_14;
    unsigned int unk18;
    int m_1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    void* m_2c;
};
struct SHolder {
    int m_iWordAt00; int m_iWordAt04; void* m_8;
    __forceinline void*& GetP8() { return m_8; }
};
struct SBox {
    void* vtbl;
    SHolder* m_iWordAt04;
    void* m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_counts[8];
    void* m_40;
    __forceinline void* GetM8() { return m_8; }
    SBox* FUN_00a19c00(SItem* pItem, int aiIndex);
};

// @fnv 0x00a19c00
SBox* SBox::FUN_00a19c00(SItem* pItem, int aiIndex)
{
    int iOffset;
    {
    SNode* pNew = 0;
    iOffset = 0;
    while (aiIndex > 1) {
        iOffset += m_1c;
        --aiIndex;
    }
    if (GetM8() && aiIndex == 0) {
        pNew = (SNode*)((FUN_00a19f70_t*)m_iWordAt04->GetP8())->WrapLine(pItem, 0);
    } else {
        pNew = (SNode*)new FUN_00a1bd40(this, pItem, iOffset, m_14);
        aiIndex = 0;
    }
    if (pItem && pItem->TextEmpty()) {
        FontCharacterInfo* pLetter = &((SFontDataView*)FontMgrInstance()->GetFont(pItem->m_iType)->m_pFontData)->kLetters[pItem->cChar];
        m_1c = (int)((SFontDataView*)FontMgrInstance()->GetFont(pItem->m_iType)->m_pFontData)->m_fFontSize + (int)(pLetter->m_fGlyphExtent - pLetter->m_fVerticalOffset);
    }
    if (pNew) {
        SBox* pRet = this;
        if (m_10 + pNew->m_14 + pNew->m_1c > m_18) {
            pNew->m_1c = 0;
            pRet = (SBox*)new FUN_00a1be10(m_40, pNew, m_14, m_18);
            pRet->m_10 = pNew->m_14;
            pNew->m_2c = pRet;
        } else {
            ((FUN_00ae8bf0_t*)this)->AddItem(&pNew);
            m_10 += pNew->m_14 + pNew->m_1c;
        }
        if (pItem->TextEmpty())
            pRet->m_counts[pItem->m_iType]++;
        if (pRet != this)
            return pRet;
    } else if (pItem && pItem->TextEmpty()) {
        m_counts[pItem->m_iType]++;
    }
    return 0;
    }
}
}  // namespace fnv_00a19c00

namespace fnv_00a1b020 {
extern "C" double __cdecl fmod(double, double);

void __cdecl NormalizeSmartQuotes(unsigned char*);
struct FUN_00a1b3a0_shell { float FUN_00a1b3a0(int); };
unsigned int __cdecl _strlen(const char*);
extern double gModifierZero;
extern double DAT_010731a8;
extern NiPoint3 NiPoint3_ZERO;

const float TAB_WIDTH = 75.0f;

struct FUN_00a1b020_t : public FontManager {
    NiPoint3 GetStringDimensions(const char* strText, int aiFont, float afWrapwidth, int aiStartIndex);
};

// Measures wrapped text for a font: accumulates per-glyph widths, breaks lines at wrap points, and returns max line width, total height and line count.
// @fnv 0x00a1b020
NiPoint3 FUN_00a1b020_t::GetStringDimensions(const char* strText, int aiFont, float afWrapwidth, int aiStartIndex)
{
    float fprevLetterWidth;
    int inumLines;
    bool bsoftHyphen;
    NiPoint3 returnDims;
    float fwrapPointWidth;
    float fcurrLineWidth;
    int uistrLength;
    FontCharacterInfo* plettersA;
    float flinePadding;

    if (aiFont < 1 || aiFont > 8 || strText == 0)
        return NiPoint3_ZERO;

    returnDims = NiPoint3_ZERO;
    uistrLength = _strlen(strText);
    plettersA = (FontCharacterInfo*)(*(char**)((char*)pFont[aiFont - 1] + 0x38) + 0x128);
    fwrapPointWidth = 0;
    fcurrLineWidth = 0;
    flinePadding = ((FUN_00a1b3a0_shell*)this)->FUN_00a1b3a0(aiFont);
    fprevLetterWidth = 0;
    bsoftHyphen = false;
    inumLines = 1;
    returnDims.y = *(float*)((char*)plettersA + 0x728);
    for (int iletterCt = aiStartIndex; iletterCt < uistrLength; iletterCt++) {
        unsigned char cletter = strText[iletterCt];
        float fcurrLetterWidth = 0;
        NormalizeSmartQuotes(&cletter);
        fcurrLetterWidth = plettersA[cletter].m_fHorizontalAdvance + plettersA[cletter].m_fGlyphWidthInPixels + plettersA[cletter].m_fHorizontalSpacing;
        switch (cletter) {
        case '\n':
        case ' ':
            fwrapPointWidth = fcurrLineWidth;
            bsoftHyphen = false;
            break;
        case '~':
            fwrapPointWidth = fcurrLineWidth + plettersA['-'].m_fHorizontalAdvance + plettersA['-'].m_fGlyphWidthInPixels + plettersA['-'].m_fHorizontalSpacing;
            bsoftHyphen = true;
            break;
        case '\t':
            fcurrLetterWidth = DAT_010731a8 - (float)fmod((double)fcurrLineWidth, (double)TAB_WIDTH);
            break;
        }
        if (cletter != '~' || cletter == '\n')
            fcurrLineWidth += fcurrLetterWidth;
        if (fcurrLineWidth > afWrapwidth || cletter == '\n') {
            if (fwrapPointWidth > gModifierZero) {
                fcurrLineWidth -= fwrapPointWidth;
                if (!bsoftHyphen) {
                    if (cletter == '\n')
                        fcurrLineWidth = 0;
                    else
                        fcurrLineWidth -= plettersA[' '].m_fHorizontalAdvance + plettersA[' '].m_fGlyphWidthInPixels + plettersA[' '].m_fHorizontalSpacing;
                }
            } else {
                fwrapPointWidth = fcurrLineWidth - fcurrLetterWidth - fprevLetterWidth + plettersA['-'].m_fHorizontalAdvance + plettersA['-'].m_fGlyphWidthInPixels + plettersA['-'].m_fHorizontalSpacing;
                fcurrLineWidth = fcurrLetterWidth + fprevLetterWidth;
            }
            returnDims.x = returnDims.x > fwrapPointWidth ? returnDims.x : fwrapPointWidth;
            returnDims.y = flinePadding + **(float**)((char*)pFont[aiFont - 1] + 0x38) + returnDims.y;
            fwrapPointWidth = 0;
            inumLines++;
        }
        fprevLetterWidth = fcurrLetterWidth;
    }
    returnDims.x = returnDims.x > fcurrLineWidth ? returnDims.x : fcurrLineWidth;
    returnDims.z = (float)inumLines;
    return returnDims;
}
}  // namespace fnv_00a1b020

struct FUN_00a14170_out {
    float fX;
    float fY;
    float fZ;
    float fW;
};

struct FUN_00a14170_shell {
    int unk00;
    int unk04;
    int iType;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    float fValue2C;
    void FUN_00a14170(FUN_00a14170_out* apOut, const char* apName);
};

// @fnv 0x00a14170
void FUN_00a14170_shell::FUN_00a14170(FUN_00a14170_out* apOut, const char* apName) {
    apOut->fX = 60.0f;
    apOut->fZ = fValue2C;
    if (apName[0] == 'a' || apName[0] == 'b' || apName[0] == 'x' || apName[0] == 'y') {
        apOut->fY = -15.0f;
        apOut->fW = -30.0f;
    } else if ((apName[0] == 'l' || apName[0] == 'r') && (apName[1] == 's' || apName[1] == 't')) {
        apOut->fY = -12.5f;
        apOut->fW = -25.0f;
    } else {
        apOut->fY = -10.0f;
        apOut->fW = -20.0f;
    }
    switch (iType) {
    case 1:
        apOut->fY -= 2.5;
        apOut->fZ -= 3.0;
        apOut->fW -= 5.0;
        break;
    case 7:
        apOut->fY += 2.5;
        apOut->fZ -= 10.0;
        apOut->fW -= 5.0;
        break;
    }
}

struct FUN_004037f0_target {
    void FUN_004037f0(char* text, int flag);
};

struct FUN_00a16700_cls {
    int unk00;
    void SplitAndProcessToken(char* text, FUN_004037f0_target* target, int maxCount, char delim);
};

// @fnv 0x00a16700
void FUN_00a16700_cls::SplitAndProcessToken(char* text, FUN_004037f0_target* target, int maxCount, char delim) {
    unsigned int pad[8];
    char* last = text;
    int count = 0;
    int i6 = 0;
    while (text[i6] != 0 && count != maxCount) {
        if (text[i6] == delim) {
            last = text + i6;
            count = count + 1;
        }
        i6 = i6 + 1;
    }
    while (text[i6] != 0 && text[i6] != delim) {
        i6 = i6 + 1;
    }
    text[i6] = 0;
    target->FUN_004037f0(last, 0);
    text[i6] = delim;
}

struct FUN_00a18ff0_node {
    FUN_00a18ff0_node* next;
    int unk04;
    int value;
};

struct FUN_00a18ff0_cls {
    FUN_00a18ff0_node* head;
    int unk04;
    void* m_08;
    int unk0c;
    int unk10;
    unsigned int m_14;
    int GetValueAtCount();
};

// Walks the linked list from head for m_14 steps and returns the node's value, or 0 if m_08 is null or the list ends early.
// @fnv 0x00a18ff0
int FUN_00a18ff0_cls::GetValueAtCount() {
    unsigned int count;
    FUN_00a18ff0_node* cur;
    void* first4;
    FUN_00a18ff0_node* h4;
    first4 = m_08;
    if (first4 != 0) {
        count = m_14;
        h4 = head;
        cur = h4;
        while (cur != 0 && count-- != 0) {
            int* p3 = &cur->value;
            cur = cur->next;
        }
        if (cur != 0) {
            return cur->value;
        }
    }
    return 0;
}

extern float DAT_01095268;
extern float DAT_01095264;
extern float DAT_01095260;

struct FUN_00a1b770_vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct FUN_00a1b770_sub
{
    unsigned int unk00;
    void Init(int a, int b);
};

struct FUN_00a1b770_scratch
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

struct FUN_00a1b770_scratch2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
};

struct FUN_00a1b770_cls
{
    unsigned int m_u00;
    unsigned int unk04;
    FUN_00a1b770_vec4 m_v08;
    unsigned int m_u18;
    FUN_00a1b770_sub m_s1c;

    void FUN_00a1b7f0(int size);
    void FUN_00a1b770();
};

// Initialises the object: zeroes m_u00, sets m_v08 from three globals with w=1, sets m_u18 to 1, inits m_s1c and calls FUN_00a1b7f0(0x20).
// @fnv 0x00a1b770
void FUN_00a1b770_cls::FUN_00a1b770()
{
    FUN_00a1b770_vec4 vec;
    FUN_00a1b770_scratch scratch;
    FUN_00a1b770_scratch2 scratch2;
    m_u00 = 0;
    vec.x = DAT_01095268;
    vec.y = DAT_01095264;
    vec.z = DAT_01095260;
    vec.w = 1.0f;
    m_v08 = vec;
    m_u18 = 1;
    FUN_00a1b770_sub* sub = &m_s1c;
    sub->Init(0, 0);
    FUN_00a1b7f0(0x20);
}

unsigned int __cdecl strlen(const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
extern MemoryManager g_memoryManager;
extern __declspec(thread) int g_tlsMode;

inline void CopyFont(char* dst, unsigned int size, const char* file) { strcpy_s(dst, size, file); }
struct FontTexSlot {
    int* p;
    FontTexSlot();
    ~FontTexSlot();
};
struct FontStr {
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    static unsigned short Clamp(unsigned int n) { return n <= 0xffff ? (unsigned short)n : 0xffff; }
    FontStr() {
        pString = 0;
        sLen = Clamp(0);
        sMaxLen = Clamp(0);
    }
    ~FontStr();
};
struct FontIconArray {
    virtual ~FontIconArray();
    virtual void* Allocate(unsigned int);
    void* buffer;
    unsigned int size;
    unsigned int capacity;
    FontIconArray() { unsigned int count = 0; buffer = 0; size = 0; capacity = 0; if (count < size) count = size; if (count > capacity) { buffer = Allocate(count); capacity = count; } }
};
struct TlsModeGuard {
    int saved;
    static int GetMode() { return g_tlsMode; }
    static void SetMode(int mode) { g_tlsMode = mode; }
    TlsModeGuard() {
        saved = GetMode();
        SetMode(12);
    }
    ~TlsModeGuard() {
        SetMode(saved);
    }
};

struct FUN_00a12020 {
    unsigned short BackgroundTask;
    char* m_pFile;
    int m_iFontNumber;
    FontTexSlot m_kTextureSlots[8];
    float m_fLineHeight;
    float m_fDrop;
    int m_iOverlap;
    int m_pFontData;
    FontStr iconName;
    FontIconArray icons;
    FUN_00a12020(int fontNum, const char* file, bool load);
    void Load();
};

// @fnv 0x00a12020
FUN_00a12020::FUN_00a12020(int fontNum, const char* file, bool load)
{
    TlsModeGuard guard;
    m_pFile = 0;
    BackgroundTask = 0;
    m_pFontData = 0;
    if (file) {
        unsigned int len = strlen(file);
        if (len) {
            char* pBuffer = (char*)g_memoryManager.Allocate(len + 1);
            m_pFile = pBuffer;
            CopyFont(m_pFile, len + 1, file);
        }
        m_iFontNumber = fontNum;
        if (load)
            Load();
    }
}

struct GQPoint3 {
    float x;
    float y;
    float z;

    GQPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

struct GQPoint2 {
    float x;
    float y;

    GQPoint2(float fX, float fY) { x = fX; y = fY; }
};

struct GQGeometryData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    GQPoint3* m_pkVertex;
    int unk24;
    int unk28;
    GQPoint2* m_pkTexture;

    GQPoint3* GetVertices() { return m_pkVertex; }
    GQPoint2* GetTextures() { return m_pkTexture; }
    unsigned short* GetTriangleList();
    unsigned short* GetTriangle(unsigned int uiIndex) { return GetTriangleList() + uiIndex; }
};

struct GQGeometry {
    int unk00;
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
    GQGeometryData* m_spGeometryData;

    GQGeometryData* GetModelData() { return m_spGeometryData; }
};

struct GQGlyph {
    int unk00;
    float fU0;
    float fV0;
    float fU1;
    float fV1;
    float fU2;
    float fV2;
    float fU3;
    float fV3;
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    float m_fGlyphMetric;
    float m_fHorizontalSpacing;
    float fTop;
};

struct GQFont {
    void BuildGlyphQuad(GQGlyph* apGlyph, unsigned int auiIndex, GQGeometry* apGeom, GQPoint3* apPos, int aiUnused);
};

// @fnv 0x00a142d0
void GQFont::BuildGlyphQuad(GQGlyph* apGlyph, unsigned int auiIndex, GQGeometry* apGeom, GQPoint3* apPos, int aiUnused)
{
    apPos->x += apGlyph->m_fGlyphMetric;
    unsigned int uiVert = auiIndex * 4;

    GQPoint3* pVerts3 = apGeom->GetModelData()->GetVertices() + uiVert;
    pVerts3[0] = GQPoint3(apPos->x, apPos->y, apPos->z + apGlyph->fTop);
    pVerts3[1] = GQPoint3(apPos->x, apPos->y, apPos->z + apGlyph->fTop - apGlyph->m_fGlyphExtent);
    pVerts3[2] = GQPoint3(apPos->x + apGlyph->m_fGlyphWidthInPixels, apPos->y, apPos->z + apGlyph->fTop);
    pVerts3[3] = GQPoint3(apPos->x + apGlyph->m_fGlyphWidthInPixels, apPos->y, apPos->z + apGlyph->fTop - apGlyph->m_fGlyphExtent);

    GQPoint2* pUVsA = apGeom->GetModelData()->GetTextures() + uiVert;
    pUVsA[0] = GQPoint2(apGlyph->fU0, apGlyph->fV0);
    pUVsA[1] = GQPoint2(apGlyph->fU2, apGlyph->fV2);
    pUVsA[2] = GQPoint2(apGlyph->fU1, apGlyph->fV1);
    pUVsA[3] = GQPoint2(apGlyph->fU3, apGlyph->fV3);

    unsigned short* pTris = apGeom->GetModelData()->GetTriangle(auiIndex * 6);
    pTris[0] = uiVert;
    pTris[1] = uiVert + 1;
    pTris[2] = uiVert + 2;
    pTris[3] = uiVert + 2;
    pTris[4] = uiVert + 1;
    pTris[5] = uiVert + 3;

    apPos->x += apGlyph->m_fGlyphWidthInPixels + ((apGlyph->m_fGlyphWidthInPixels > 0.0) ? apGlyph->m_fHorizontalSpacing : 0.0f);
}

struct NiMemObjectAllocation { static void* operator new(unsigned);static void operator delete(void*); };
struct AtlasVertex { float x,y,z;AtlasVertex() {} static void* operator new[](unsigned n) { return g_memoryManager.Allocate(n); } };
struct AtlasUV { float u,v;AtlasUV() {} static void* operator new[](unsigned n) { return g_memoryManager.Allocate(n); } };
extern char* DAT_0109b220;
char* FUN_00a5b690(const char*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct AtlasString {
 char* text;
 AtlasString(const char* value) { if(!value) text=DAT_0109b220; else text=FUN_00a5b690(value); }
 ~AtlasString() { if(text==DAT_0109b220) {} else { char* header=text-8;InterlockedDecrement((long*)header); } }
};
struct AtlasData {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 bool keep;bool dynamic;
 void FUN_00a67050(unsigned);
};
struct AtlasColor { float r,g,b,a; };
extern AtlasColor DAT_011a9be0;
struct AtlasShader : NiMemObjectAllocation {
 virtual void Unknown0();
 virtual void Unknown1();
 virtual void Unknown2();
 virtual void Unknown3();
 virtual void Unknown4();
 virtual void Unknown5();
 virtual void Unknown6();
 virtual void Unknown7();
 virtual void Unknown8();
 virtual void Unknown9();
 virtual void Unknown10();
 virtual void Unknown11();
 virtual void Unknown12();
 virtual void Unknown13();
 virtual void Unknown14();
 virtual void Unknown15();
 virtual void Unknown16();
 virtual void Unknown17();
 virtual void Unknown18();
 virtual void Unknown19();
 virtual void Unknown20();
 virtual void Unknown21();
 virtual void Unknown22();
 virtual void Unknown23();
 virtual void Unknown24();
 virtual void Unknown25();
 virtual void Unknown26();
 virtual void Unknown27();
 virtual void Unknown28();
 virtual void Unknown29();
 virtual void Unknown30();
 virtual void Unknown31();
 virtual void Unknown32();
 virtual void Unknown33();
 virtual void Unknown34();
 virtual int GetPropertyType();
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 AtlasColor color;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 unsigned unkac;
 AtlasShader(bool);void FUN_00bb7a10(void*);
};
struct AtlasPropertyPointer { AtlasShader* pointer;AtlasPropertyPointer(AtlasShader*);~AtlasPropertyPointer();AtlasPropertyPointer& FUN_006e5cc0(const AtlasPropertyPointer&); };
struct AtlasPropertyNode { AtlasPropertyNode* next;AtlasPropertyNode* previous;AtlasPropertyPointer value; };
struct AtlasPoolLock {void Lock(bool);void Unlock();};
extern AtlasPoolLock DAT_011c5f80;
extern AtlasPropertyNode* DAT_011c5f58;
void FUN_0043a080();
struct AtlasNodeAllocator { unsigned count;AtlasPropertyNode* Allocate() { DAT_011c5f80.Lock(false);if(!DAT_011c5f58)FUN_0043a080();AtlasPropertyNode* node=DAT_011c5f58;DAT_011c5f58=DAT_011c5f58->next;node->value.pointer=0;node->next=0;node->previous=0;DAT_011c5f80.Unlock();return node;} };
struct AtlasPropertyList { AtlasPropertyNode* head;AtlasPropertyNode* tail;AtlasNodeAllocator allocator;
 AtlasPropertyNode* NewNode(){return allocator.Allocate();}
 void FUN_0049fa20(AtlasPropertyNode*);
 void FUN_00439fd0(const AtlasPropertyPointer& property) {AtlasPropertyNode* node=NewNode();node->value.FUN_006e5cc0(property);FUN_0049fa20(node);}
};
struct AtlasGeometry : NiMemObjectAllocation {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 AtlasPropertyList properties;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 unsigned unkac;
 unsigned unkb0;
 unsigned unkb4;
 AtlasData* data;
 unsigned unkbc;
 unsigned unkc0;
 unsigned unkc4;
 unsigned unkc8;
 unsigned unkcc;
 unsigned unkd0;
 AtlasGeometry(unsigned short,AtlasVertex*,unsigned,void*,AtlasUV*,unsigned,unsigned,unsigned short,unsigned short*,void*,void*,void*,void*);
 AtlasData* GetData() { AtlasData* result=data;return result; }
 void AssignFixedString(const AtlasString&);
 void FUN_00439410(AtlasShader* shader) { if(shader->GetPropertyType()<7) { AtlasPropertyPointer property(shader);properties.FUN_00439fd0(property); } }
 void FUN_00a5a040();
};
void* FUN_00aa1070(unsigned);
void FUN_00b57e30(AtlasGeometry*,unsigned,unsigned);
void FUN_00ec8d5f(char*,unsigned,const char*,unsigned);
int FUN_00406d00(char*,unsigned,const char*,...);
extern char sheetGeometryName[];
extern unsigned DAT_011a9598;
void* FUN_00a5fd70(const AtlasString&,unsigned&,bool,bool);
void AttachFaceGenAnimationData(AtlasGeometry*);
inline void CopyAtlasPath(char* dest,const char* source,unsigned limit) { FUN_00ec8d5f(dest,limit+1,source,limit); }
struct FontAtlasFactory {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 AtlasPropertyList properties;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 const char* textureName;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned glyphCount;
 unsigned GetCount() { return glyphCount; }
 const char* GetTextureResourceName() { return textureName; }
 AtlasGeometry* FUN_00a14da0();
};
// @fnv 0x00a14da0
AtlasGeometry* FontAtlasFactory::FUN_00a14da0() {
 unsigned vertices7=GetCount()*4;
 AtlasVertex* positions=new AtlasVertex[vertices7];
 AtlasUV* uvs5=new AtlasUV[vertices7];
 unsigned short* indicesVal=(unsigned short*)FUN_00aa1070(GetCount()*6*sizeof(unsigned short));
 AtlasGeometry* geometry_=new AtlasGeometry((unsigned short)vertices7,positions,0,0,uvs5,1,0,(unsigned short)(GetCount()*2), indicesVal,0,0,0,0);
 AtlasData* dataB=geometry_->GetData();
 dataB->keep=false;
 dataB->dynamic=true;
 geometry_->AssignFixedString(AtlasString(sheetGeometryName));
 geometry_->GetData()->FUN_00a67050(0x4000);
 AtlasShader* shader3=new AtlasShader(false);
 geometry_->FUN_00439410(shader3);
 shader3->color=DAT_011a9be0;
 FUN_00b57e30(geometry_,0,0);
 char sourceName7[260];
 CopyAtlasPath(sourceName7,GetTextureResourceName(),259);
 char texturePath[260];
 FUN_00406d00(texturePath,260,"Data\\Textures\\%s",sourceName7);
 shader3->FUN_00bb7a10(FUN_00a5fd70(AtlasString(texturePath),DAT_011a9598,true,false));
 geometry_->FUN_00a5a040();
 AttachFaceGenAnimationData(geometry_);
 return geometry_;}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct ThreadState {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
int unk12c;
int unk130;
int unk134;
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
int unk260;
int unk264;
int unk268;
int unk26c;
int unk270;
int unk274;
int unk278;
int unk27c;
int unk280;
int unk284;
int unk288;
int unk28c;
int unk290;
int unk294;
int unk298;
int unk29c;
int unk2a0;
int unk2a4;
int unk2a8;
int unk2ac;
int unk2b0;
unsigned int context; };
extern __declspec(thread) ThreadState gThread;
inline unsigned int GetContext() { return gThread.context; }
inline void SetContext(unsigned int v) { gThread.context=v; }
struct ContextScope { unsigned int old; ContextScope(unsigned int v) { old=GetContext(); SetContext(v); } ~ContextScope() { SetContext(old); } };
struct LoaderFile {
virtual ~LoaderFile();
virtual void V04()=0; virtual void V08()=0; virtual void V0c()=0; virtual void V10()=0; virtual void V14()=0; virtual void V18()=0; virtual void V1c()=0; virtual void V20()=0; virtual void V24()=0;
virtual unsigned int Size()=0;
unsigned int position;
unsigned int (__cdecl *reader)(LoaderFile*,void*,unsigned int,unsigned int*,unsigned int);
int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; bool good;
bool IsGood() { return good; }
unsigned int Read(void* dst,unsigned int size) { unsigned int one3=1; unsigned int count3=reader(this,dst,size,&one3,1); position+=count3; unsigned int result3=count3; return result3; }
};
struct FileFinder { static LoaderFile* GetFile(const char*,int,unsigned int,unsigned int); };
inline void Close(LoaderFile* f) { delete f; }
extern void __cdecl FNV_Warning(const char*,...);
extern int __cdecl _sprintf_s(char*,unsigned int,const char*,...);

struct Glyph { int texture; float u0,v0,u1,v1,u2,v2,u3,v3; float width,height,leading,spacing,top; };
struct GlyphData {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
Glyph letters[256]; };
struct FontData {
static __forceinline void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
float f0000;
int f0004; float f0008; float f000c; float f0010; float f0014; float f0018; float f001c; float f0020; float f0024; float f0028; float f002c; float f0030; float f0034; float f0038; float f003c; float f0040; float f0044; float f0048; float f004c; float f0050; float f0054; float f0058; float f005c; float f0060; float f0064; float f0068; float f006c; float f0070; float f0074; float f0078; float f007c; float f0080; float f0084; float f0088; float f008c; float f0090; float f0094; float f0098; float f009c; float f00a0; float f00a4; float f00a8; float f00ac; float f00b0; float f00b4; float f00b8; float f00bc; float f00c0; float f00c4; float f00c8; float f00cc; float f00d0; float f00d4; float f00d8; float f00dc; float f00e0; float f00e4; float f00e8; float f00ec; float f00f0; float f00f4; float f00f8; float f00fc; float f0100; float f0104; float f0108; float f010c; float f0110; float f0114; float f0118; float f011c; float f0120; float f0124; float f0128; float f012c; float f0130; float f0134; float f0138; float f013c; float f0140; float f0144; float f0148; float f014c; float f0150; float f0154; float f0158; float f015c; float f0160; float f0164; float f0168; float f016c; float f0170; float f0174; float f0178; float f017c; float f0180; float f0184; float f0188; float f018c; float f0190; float f0194; float f0198; float f019c; float f01a0; float f01a4; float f01a8; float f01ac; float f01b0; float f01b4; float f01b8; float f01bc; float f01c0; float f01c4; float f01c8; float f01cc; float f01d0; float f01d4; float f01d8; float f01dc; float f01e0; float f01e4; float f01e8; float f01ec; float f01f0; float f01f4; float f01f8; float f01fc; float f0200; float f0204; float f0208; float f020c; float f0210; float f0214; float f0218; float f021c; float f0220; float f0224; float f0228; float f022c; float f0230; float f0234; float f0238; float f023c; float f0240; float f0244; float f0248; float f024c; float f0250; float f0254; float f0258; float f025c; float f0260; float f0264; float f0268; float f026c; float f0270; float f0274; float f0278; float f027c; float f0280; float f0284; float f0288; float f028c; float f0290; float f0294; float f0298; float f029c; float f02a0; float f02a4; float f02a8; float f02ac; float f02b0; float f02b4; float f02b8; float f02bc; float f02c0; float f02c4; float f02c8; float f02cc; float f02d0; float f02d4; float f02d8; float f02dc; float f02e0; float f02e4; float f02e8; float f02ec; float f02f0; float f02f4; float f02f8; float f02fc; float f0300; float f0304; float f0308; float f030c; float f0310; float f0314; float f0318; float f031c; float f0320; float f0324; float f0328; float f032c; float f0330; float f0334; float f0338; float f033c; float f0340; float f0344; float f0348; float f034c; float f0350; float f0354; float f0358; float f035c; float f0360; float f0364; float f0368; float f036c; float f0370; float f0374; float f0378; float f037c; float f0380; float f0384; float f0388; float f038c; float f0390; float f0394; float f0398; float f039c; float f03a0; float f03a4; float f03a8; float f03ac; float f03b0; float f03b4; float f03b8; float f03bc; float f03c0; float f03c4; float f03c8; float f03cc; float f03d0; float f03d4; float f03d8; float f03dc; float f03e0; float f03e4; float f03e8; float f03ec; float f03f0; float f03f4; float f03f8; float f03fc; float f0400; float f0404; float f0408; float f040c; float f0410; float f0414; float f0418; float f041c; float f0420; float f0424; float f0428; float f042c; float f0430; float f0434; float f0438; float f043c; float f0440; float f0444; float f0448; float f044c; float f0450; float f0454; float f0458; float f045c; float f0460; float f0464; float f0468; float f046c; float f0470; float f0474; float f0478; float f047c; float f0480; float f0484; float f0488; float f048c; float f0490; float f0494; float f0498; float f049c; float f04a0; float f04a4; float f04a8; float f04ac; float f04b0; float f04b4; float f04b8; float f04bc; float f04c0; float f04c4; float f04c8; float f04cc; float f04d0; float f04d4; float f04d8; float f04dc; float f04e0; float f04e4; float f04e8; float f04ec; float f04f0; float f04f4; float f04f8; float f04fc; float f0500; float f0504; float f0508; float f050c; float f0510; float f0514; float f0518; float f051c; float f0520; float f0524; float f0528; float f052c; float f0530; float f0534; float f0538; float f053c; float f0540; float f0544; float f0548; float f054c; float f0550; float f0554; float f0558; float f055c; float f0560; float f0564; float f0568; float f056c; float f0570; float f0574; float f0578; float f057c; float f0580; float f0584; float f0588; float f058c; float f0590; float f0594; float f0598; float f059c; float f05a0; float f05a4; float f05a8; float f05ac; float f05b0; float f05b4; float f05b8; float f05bc; float f05c0; float f05c4; float f05c8; float f05cc; float f05d0; float f05d4; float f05d8; float f05dc; float f05e0; float f05e4; float f05e8; float f05ec; float f05f0; float f05f4; float f05f8; float f05fc; float f0600; float f0604; float f0608; float f060c; float f0610; float f0614; float f0618; float f061c; float f0620; float f0624; float f0628; float f062c; float f0630; float f0634; float f0638; float f063c; float f0640; float f0644; float f0648; float f064c; float f0650; float f0654; float f0658; float f065c; float f0660; float f0664; float f0668; float f066c; float f0670; float f0674; float f0678; float f067c; float f0680; float f0684; float f0688; float f068c; float f0690; float f0694; float f0698; float f069c; float f06a0; float f06a4; float f06a8; float f06ac; float f06b0; float f06b4; float f06b8; float f06bc; float f06c0; float f06c4; float f06c8; float f06cc; float f06d0; float f06d4; float f06d8; float f06dc; float f06e0; float f06e4; float f06e8; float f06ec; float f06f0; float f06f4; float f06f8; float f06fc; float f0700; float f0704; float f0708; float f070c; float f0710; float f0714; float f0718; float f071c; float f0720; float f0724; float f0728; float f072c; float f0730; float f0734; float f0738; float f073c; float f0740; float f0744; float f0748; float f074c; float f0750; float f0754; float f0758; float f075c; float f0760; float f0764; float f0768; float f076c; float f0770; float f0774; float f0778; float f077c; float f0780; float f0784; float f0788; float f078c; float f0790; float f0794; float f0798; float f079c; float f07a0; float f07a4; float f07a8; float f07ac; float f07b0; float f07b4; float f07b8; float f07bc; float f07c0; float f07c4; float f07c8; float f07cc; float f07d0; float f07d4; float f07d8; float f07dc; float f07e0; float f07e4; float f07e8; float f07ec; float f07f0; float f07f4; float f07f8; float f07fc; float f0800; float f0804; float f0808; float f080c; float f0810; float f0814; float f0818; float f081c; float f0820; float f0824; float f0828; float f082c; float f0830; float f0834; float f0838; float f083c; float f0840; float f0844; float f0848; float f084c; float f0850; float f0854; float f0858; float f085c; float f0860; float f0864; float f0868; float f086c; float f0870; float f0874; float f0878; float f087c; float f0880; float f0884; float f0888; float f088c; float f0890; float f0894; float f0898; float f089c; float f08a0; float f08a4; float f08a8; float f08ac; float f08b0; float f08b4; float f08b8; float f08bc; float f08c0; float f08c4; float f08c8; float f08cc; float f08d0; float f08d4; float f08d8; float f08dc; float f08e0; float f08e4; float f08e8; float f08ec; float f08f0; float f08f4; float f08f8; float f08fc; float f0900; float f0904; float f0908; float f090c; float f0910; float f0914; float f0918; float f091c; float f0920; float f0924; float f0928; float f092c; float f0930; float f0934; float f0938; float f093c; float f0940; float f0944; float f0948; float f094c; float f0950; float f0954; float f0958; float f095c; float f0960; float f0964; float f0968; float f096c; float f0970; float f0974; float f0978; float f097c; float f0980; float f0984; float f0988; float f098c; float f0990; float f0994; float f0998; float f099c; float f09a0; float f09a4; float f09a8; float f09ac; float f09b0; float f09b4; float f09b8; float f09bc; float f09c0; float f09c4; float f09c8; float f09cc; float f09d0; float f09d4; float f09d8; float f09dc; float f09e0; float f09e4; float f09e8; float f09ec; float f09f0; float f09f4; float f09f8; float f09fc; float f0a00; float f0a04; float f0a08; float f0a0c; float f0a10; float f0a14; float f0a18; float f0a1c; float f0a20; float f0a24; float f0a28; float f0a2c; float f0a30; float f0a34; float f0a38; float f0a3c; float f0a40; float f0a44; float f0a48; float f0a4c; float f0a50; float f0a54; float f0a58; float f0a5c; float f0a60; float f0a64; float f0a68; float f0a6c; float f0a70; float f0a74; float f0a78; float f0a7c; float f0a80; float f0a84; float f0a88; float f0a8c; float f0a90; float f0a94; float f0a98; float f0a9c; float f0aa0; float f0aa4; float f0aa8; float f0aac; float f0ab0; float f0ab4; float f0ab8; float f0abc; float f0ac0; float f0ac4; float f0ac8; float f0acc; float f0ad0; float f0ad4; float f0ad8; float f0adc; float f0ae0; float f0ae4; float f0ae8; float f0aec; float f0af0; float f0af4; float f0af8; float f0afc; float f0b00; float f0b04; float f0b08; float f0b0c; float f0b10; float f0b14; float f0b18; float f0b1c; float f0b20; float f0b24; float f0b28; float f0b2c; float f0b30; float f0b34; float f0b38; float f0b3c; float f0b40; float f0b44; float f0b48; float f0b4c; float f0b50; float f0b54; float f0b58; float f0b5c; float f0b60; float f0b64; float f0b68; float f0b6c; float f0b70; float f0b74; float f0b78; float f0b7c; float f0b80; float f0b84; float f0b88; float f0b8c; float f0b90; float f0b94; float f0b98; float f0b9c; float f0ba0; float f0ba4; float f0ba8; float f0bac; float f0bb0; float f0bb4; float f0bb8; float f0bbc; float f0bc0; float f0bc4; float f0bc8; float f0bcc; float f0bd0; float f0bd4; float f0bd8; float f0bdc; float f0be0; float f0be4; float f0be8; float f0bec; float f0bf0; float f0bf4; float f0bf8; float f0bfc; float f0c00; float f0c04; float f0c08; float f0c0c; float f0c10; float f0c14; float f0c18; float f0c1c; float f0c20; float f0c24; float f0c28; float f0c2c; float f0c30; float f0c34; float f0c38; float f0c3c; float f0c40; float f0c44; float f0c48; float f0c4c; float f0c50; float f0c54; float f0c58; float f0c5c; float f0c60; float f0c64; float f0c68; float f0c6c; float f0c70; float f0c74; float f0c78; float f0c7c; float f0c80; float f0c84; float f0c88; float f0c8c; float f0c90; float f0c94; float f0c98; float f0c9c; float f0ca0; float f0ca4; float f0ca8; float f0cac; float f0cb0; float f0cb4; float f0cb8; float f0cbc; float f0cc0; float f0cc4; float f0cc8; float f0ccc; float f0cd0; float f0cd4; float f0cd8; float f0cdc; float f0ce0; float f0ce4; float f0ce8; float f0cec; float f0cf0; float f0cf4; float f0cf8; float f0cfc; float f0d00; float f0d04; float f0d08; float f0d0c; float f0d10; float f0d14; float f0d18; float f0d1c; float f0d20; float f0d24; float f0d28; float f0d2c; float f0d30; float f0d34; float f0d38; float f0d3c; float f0d40; float f0d44; float f0d48; float f0d4c; float f0d50; float f0d54; float f0d58; float f0d5c; float f0d60; float f0d64; float f0d68; float f0d6c; float f0d70; float f0d74; float f0d78; float f0d7c; float f0d80; float f0d84; float f0d88; float f0d8c; float f0d90; float f0d94; float f0d98; float f0d9c; float f0da0; float f0da4; float f0da8; float f0dac; float f0db0; float f0db4; float f0db8; float f0dbc; float f0dc0; float f0dc4; float f0dc8; float f0dcc; float f0dd0; float f0dd4; float f0dd8; float f0ddc; float f0de0; float f0de4; float f0de8; float f0dec; float f0df0; float f0df4; float f0df8; float f0dfc; float f0e00; float f0e04; float f0e08; float f0e0c; float f0e10; float f0e14; float f0e18; float f0e1c; float f0e20; float f0e24; float f0e28; float f0e2c; float f0e30; float f0e34; float f0e38; float f0e3c; float f0e40; float f0e44; float f0e48; float f0e4c; float f0e50; float f0e54; float f0e58; float f0e5c; float f0e60; float f0e64; float f0e68; float f0e6c; float f0e70; float f0e74; float f0e78; float f0e7c; float f0e80; float f0e84; float f0e88; float f0e8c; float f0e90; float f0e94; float f0e98; float f0e9c; float f0ea0; float f0ea4; float f0ea8; float f0eac; float f0eb0; float f0eb4; float f0eb8; float f0ebc; float f0ec0; float f0ec4; float f0ec8; float f0ecc; float f0ed0; float f0ed4; float f0ed8; float f0edc; float f0ee0; float f0ee4; float f0ee8; float f0eec; float f0ef0; float f0ef4; float f0ef8; float f0efc; float f0f00; float f0f04; float f0f08; float f0f0c; float f0f10; float f0f14; float f0f18; float f0f1c; float f0f20; float f0f24; float f0f28; float f0f2c; float f0f30; float f0f34; float f0f38; float f0f3c; float f0f40; float f0f44; float f0f48; float f0f4c; float f0f50; float f0f54; float f0f58; float f0f5c; float f0f60; float f0f64; float f0f68; float f0f6c; float f0f70; float f0f74; float f0f78; float f0f7c; float f0f80; float f0f84; float f0f88; float f0f8c; float f0f90; float f0f94; float f0f98; float f0f9c; float f0fa0; float f0fa4; float f0fa8; float f0fac; float f0fb0; float f0fb4; float f0fb8; float f0fbc; float f0fc0; float f0fc4; float f0fc8; float f0fcc; float f0fd0; float f0fd4; float f0fd8; float f0fdc; float f0fe0; float f0fe4; float f0fe8; float f0fec; float f0ff0; float f0ff4; float f0ff8; float f0ffc; float f1000; float f1004; float f1008; float f100c; float f1010; float f1014; float f1018; float f101c; float f1020; float f1024; float f1028; float f102c; float f1030; float f1034; float f1038; float f103c; float f1040; float f1044; float f1048; float f104c; float f1050; float f1054; float f1058; float f105c; float f1060; float f1064; float f1068; float f106c; float f1070; float f1074; float f1078; float f107c; float f1080; float f1084; float f1088; float f108c; float f1090; float f1094; float f1098; float f109c; float f10a0; float f10a4; float f10a8; float f10ac; float f10b0; float f10b4; float f10b8; float f10bc; float f10c0; float f10c4; float f10c8; float f10cc; float f10d0; float f10d4; float f10d8; float f10dc; float f10e0; float f10e4; float f10e8; float f10ec; float f10f0; float f10f4; float f10f8; float f10fc; float f1100; float f1104; float f1108; float f110c; float f1110; float f1114; float f1118; float f111c; float f1120; float f1124; float f1128; float f112c; float f1130; float f1134; float f1138; float f113c; float f1140; float f1144; float f1148; float f114c; float f1150; float f1154; float f1158; float f115c; float f1160; float f1164; float f1168; float f116c; float f1170; float f1174; float f1178; float f117c; float f1180; float f1184; float f1188; float f118c; float f1190; float f1194; float f1198; float f119c; float f11a0; float f11a4; float f11a8; float f11ac; float f11b0; float f11b4; float f11b8; float f11bc; float f11c0; float f11c4; float f11c8; float f11cc; float f11d0; float f11d4; float f11d8; float f11dc; float f11e0; float f11e4; float f11e8; float f11ec; float f11f0; float f11f4; float f11f8; float f11fc; float f1200; float f1204; float f1208; float f120c; float f1210; float f1214; float f1218; float f121c; float f1220; float f1224; float f1228; float f122c; float f1230; float f1234; float f1238; float f123c; float f1240; float f1244; float f1248; float f124c; float f1250; float f1254; float f1258; float f125c; float f1260; float f1264; float f1268; float f126c; float f1270; float f1274; float f1278; float f127c; float f1280; float f1284; float f1288; float f128c; float f1290; float f1294; float f1298; float f129c; float f12a0; float f12a4; float f12a8; float f12ac; float f12b0; float f12b4; float f12b8; float f12bc; float f12c0; float f12c4; float f12c8; float f12cc; float f12d0; float f12d4; float f12d8; float f12dc; float f12e0; float f12e4; float f12e8; float f12ec; float f12f0; float f12f4; float f12f8; float f12fc; float f1300; float f1304; float f1308; float f130c; float f1310; float f1314; float f1318; float f131c; float f1320; float f1324; float f1328; float f132c; float f1330; float f1334; float f1338; float f133c; float f1340; float f1344; float f1348; float f134c; float f1350; float f1354; float f1358; float f135c; float f1360; float f1364; float f1368; float f136c; float f1370; float f1374; float f1378; float f137c; float f1380; float f1384; float f1388; float f138c; float f1390; float f1394; float f1398; float f139c; float f13a0; float f13a4; float f13a8; float f13ac; float f13b0; float f13b4; float f13b8; float f13bc; float f13c0; float f13c4; float f13c8; float f13cc; float f13d0; float f13d4; float f13d8; float f13dc; float f13e0; float f13e4; float f13e8; float f13ec; float f13f0; float f13f4; float f13f8; float f13fc; float f1400; float f1404; float f1408; float f140c; float f1410; float f1414; float f1418; float f141c; float f1420; float f1424; float f1428; float f142c; float f1430; float f1434; float f1438; float f143c; float f1440; float f1444; float f1448; float f144c; float f1450; float f1454; float f1458; float f145c; float f1460; float f1464; float f1468; float f146c; float f1470; float f1474; float f1478; float f147c; float f1480; float f1484; float f1488; float f148c; float f1490; float f1494; float f1498; float f149c; float f14a0; float f14a4; float f14a8; float f14ac; float f14b0; float f14b4; float f14b8; float f14bc; float f14c0; float f14c4; float f14c8; float f14cc; float f14d0; float f14d4; float f14d8; float f14dc; float f14e0; float f14e4; float f14e8; float f14ec; float f14f0; float f14f4; float f14f8; float f14fc; float f1500; float f1504; float f1508; float f150c; float f1510; float f1514; float f1518; float f151c; float f1520; float f1524; float f1528; float f152c; float f1530; float f1534; float f1538; float f153c; float f1540; float f1544; float f1548; float f154c; float f1550; float f1554; float f1558; float f155c; float f1560; float f1564; float f1568; float f156c; float f1570; float f1574; float f1578; float f157c; float f1580; float f1584; float f1588; float f158c; float f1590; float f1594; float f1598; float f159c; float f15a0; float f15a4; float f15a8; float f15ac; float f15b0; float f15b4; float f15b8; float f15bc; float f15c0; float f15c4; float f15c8; float f15cc; float f15d0; float f15d4; float f15d8; float f15dc; float f15e0; float f15e4; float f15e8; float f15ec; float f15f0; float f15f4; float f15f8; float f15fc; float f1600; float f1604; float f1608; float f160c; float f1610; float f1614; float f1618; float f161c; float f1620; float f1624; float f1628; float f162c; float f1630; float f1634; float f1638; float f163c; float f1640; float f1644; float f1648; float f164c; float f1650; float f1654; float f1658; float f165c; float f1660; float f1664; float f1668; float f166c; float f1670; float f1674; float f1678; float f167c; float f1680; float f1684; float f1688; float f168c; float f1690; float f1694; float f1698; float f169c; float f16a0; float f16a4; float f16a8; float f16ac; float f16b0; float f16b4; float f16b8; float f16bc; float f16c0; float f16c4; float f16c8; float f16cc; float f16d0; float f16d4; float f16d8; float f16dc; float f16e0; float f16e4; float f16e8; float f16ec; float f16f0; float f16f4; float f16f8; float f16fc; float f1700; float f1704; float f1708; float f170c; float f1710; float f1714; float f1718; float f171c; float f1720; float f1724; float f1728; float f172c; float f1730; float f1734; float f1738; float f173c; float f1740; float f1744; float f1748; float f174c; float f1750; float f1754; float f1758; float f175c; float f1760; float f1764; float f1768; float f176c; float f1770; float f1774; float f1778; float f177c; float f1780; float f1784; float f1788; float f178c; float f1790; float f1794; float f1798; float f179c; float f17a0; float f17a4; float f17a8; float f17ac; float f17b0; float f17b4; float f17b8; float f17bc; float f17c0; float f17c4; float f17c8; float f17cc; float f17d0; float f17d4; float f17d8; float f17dc; float f17e0; float f17e4; float f17e8; float f17ec; float f17f0; float f17f4; float f17f8; float f17fc; float f1800; float f1804; float f1808; float f180c; float f1810; float f1814; float f1818; float f181c; float f1820; float f1824; float f1828; float f182c; float f1830; float f1834; float f1838; float f183c; float f1840; float f1844; float f1848; float f184c; float f1850; float f1854; float f1858; float f185c; float f1860; float f1864; float f1868; float f186c; float f1870; float f1874; float f1878; float f187c; float f1880; float f1884; float f1888; float f188c; float f1890; float f1894; float f1898; float f189c; float f18a0; float f18a4; float f18a8; float f18ac; float f18b0; float f18b4; float f18b8; float f18bc; float f18c0; float f18c4; float f18c8; float f18cc; float f18d0; float f18d4; float f18d8; float f18dc; float f18e0; float f18e4; float f18e8; float f18ec; float f18f0; float f18f4; float f18f8; float f18fc; float f1900; float f1904; float f1908; float f190c; float f1910; float f1914; float f1918; float f191c; float f1920; float f1924; float f1928; float f192c; float f1930; float f1934; float f1938; float f193c; float f1940; float f1944; float f1948; float f194c; float f1950; float f1954; float f1958; float f195c; float f1960; float f1964; float f1968; float f196c; float f1970; float f1974; float f1978; float f197c; float f1980; float f1984; float f1988; float f198c; float f1990; float f1994; float f1998; float f199c; float f19a0; float f19a4; float f19a8; float f19ac; float f19b0; float f19b4; float f19b8; float f19bc; float f19c0; float f19c4; float f19c8; float f19cc; float f19d0; float f19d4; float f19d8; float f19dc; float f19e0; float f19e4; float f19e8; float f19ec; float f19f0; float f19f4; float f19f8; float f19fc; float f1a00; float f1a04; float f1a08; float f1a0c; float f1a10; float f1a14; float f1a18; float f1a1c; float f1a20; float f1a24; float f1a28; float f1a2c; float f1a30; float f1a34; float f1a38; float f1a3c; float f1a40; float f1a44; float f1a48; float f1a4c; float f1a50; float f1a54; float f1a58; float f1a5c; float f1a60; float f1a64; float f1a68; float f1a6c; float f1a70; float f1a74; float f1a78; float f1a7c; float f1a80; float f1a84; float f1a88; float f1a8c; float f1a90; float f1a94; float f1a98; float f1a9c; float f1aa0; float f1aa4; float f1aa8; float f1aac; float f1ab0; float f1ab4; float f1ab8; float f1abc; float f1ac0; float f1ac4; float f1ac8; float f1acc; float f1ad0; float f1ad4; float f1ad8; float f1adc; float f1ae0; float f1ae4; float f1ae8; float f1aec; float f1af0; float f1af4; float f1af8; float f1afc; float f1b00; float f1b04; float f1b08; float f1b0c; float f1b10; float f1b14; float f1b18; float f1b1c; float f1b20; float f1b24; float f1b28; float f1b2c; float f1b30; float f1b34; float f1b38; float f1b3c; float f1b40; float f1b44; float f1b48; float f1b4c; float f1b50; float f1b54; float f1b58; float f1b5c; float f1b60; float f1b64; float f1b68; float f1b6c; float f1b70; float f1b74; float f1b78; float f1b7c; float f1b80; float f1b84; float f1b88; float f1b8c; float f1b90; float f1b94; float f1b98; float f1b9c; float f1ba0; float f1ba4; float f1ba8; float f1bac; float f1bb0; float f1bb4; float f1bb8; float f1bbc; float f1bc0; float f1bc4; float f1bc8; float f1bcc; float f1bd0; float f1bd4; float f1bd8; float f1bdc; float f1be0; float f1be4; float f1be8; float f1bec; float f1bf0; float f1bf4; float f1bf8; float f1bfc; float f1c00; float f1c04; float f1c08; float f1c0c; float f1c10; float f1c14; float f1c18; float f1c1c; float f1c20; float f1c24; float f1c28; float f1c2c; float f1c30; float f1c34; float f1c38; float f1c3c; float f1c40; float f1c44; float f1c48; float f1c4c; float f1c50; float f1c54; float f1c58; float f1c5c; float f1c60; float f1c64; float f1c68; float f1c6c; float f1c70; float f1c74; float f1c78; float f1c7c; float f1c80; float f1c84; float f1c88; float f1c8c; float f1c90; float f1c94; float f1c98; float f1c9c; float f1ca0; float f1ca4; float f1ca8; float f1cac; float f1cb0; float f1cb4; float f1cb8; float f1cbc; float f1cc0; float f1cc4; float f1cc8; float f1ccc; float f1cd0; float f1cd4; float f1cd8; float f1cdc; float f1ce0; float f1ce4; float f1ce8; float f1cec; float f1cf0; float f1cf4; float f1cf8; float f1cfc; float f1d00; float f1d04; float f1d08; float f1d0c; float f1d10; float f1d14; float f1d18; float f1d1c; float f1d20; float f1d24; float f1d28; float f1d2c; float f1d30; float f1d34; float f1d38; float f1d3c; float f1d40; float f1d44; float f1d48; float f1d4c; float f1d50; float f1d54; float f1d58; float f1d5c; float f1d60; float f1d64; float f1d68; float f1d6c; float f1d70; float f1d74; float f1d78; float f1d7c; float f1d80; float f1d84; float f1d88; float f1d8c; float f1d90; float f1d94; float f1d98; float f1d9c; float f1da0; float f1da4; float f1da8; float f1dac; float f1db0; float f1db4; float f1db8; float f1dbc; float f1dc0; float f1dc4; float f1dc8; float f1dcc; float f1dd0; float f1dd4; float f1dd8; float f1ddc; float f1de0; float f1de4; float f1de8; float f1dec; float f1df0; float f1df4; float f1df8; float f1dfc; float f1e00; float f1e04; float f1e08; float f1e0c; float f1e10; float f1e14; float f1e18; float f1e1c; float f1e20; float f1e24; float f1e28; float f1e2c; float f1e30; float f1e34; float f1e38; float f1e3c; float f1e40; float f1e44; float f1e48; float f1e4c; float f1e50; float f1e54; float f1e58; float f1e5c; float f1e60; float f1e64; float f1e68; float f1e6c; float f1e70; float f1e74; float f1e78; float f1e7c; float f1e80; float f1e84; float f1e88; float f1e8c; float f1e90; float f1e94; float f1e98; float f1e9c; float f1ea0; float f1ea4; float f1ea8; float f1eac; float f1eb0; float f1eb4; float f1eb8; float f1ebc; float f1ec0; float f1ec4; float f1ec8; float f1ecc; float f1ed0; float f1ed4; float f1ed8; float f1edc; float f1ee0; float f1ee4; float f1ee8; float f1eec; float f1ef0; float f1ef4; float f1ef8; float f1efc; float f1f00; float f1f04; float f1f08; float f1f0c; float f1f10; float f1f14; float f1f18; float f1f1c; float f1f20; float f1f24; float f1f28; float f1f2c; float f1f30; float f1f34; float f1f38; float f1f3c; float f1f40; float f1f44; float f1f48; float f1f4c; float f1f50; float f1f54; float f1f58; float f1f5c; float f1f60; float f1f64; float f1f68; float f1f6c; float f1f70; float f1f74; float f1f78; float f1f7c; float f1f80; float f1f84; float f1f88; float f1f8c; float f1f90; float f1f94; float f1f98; float f1f9c; float f1fa0; float f1fa4; float f1fa8; float f1fac; float f1fb0; float f1fb4; float f1fb8; float f1fbc; float f1fc0; float f1fc4; float f1fc8; float f1fcc; float f1fd0; float f1fd4; float f1fd8; float f1fdc; float f1fe0; float f1fe4; float f1fe8; float f1fec; float f1ff0; float f1ff4; float f1ff8; float f1ffc; float f2000; float f2004; float f2008; float f200c; float f2010; float f2014; float f2018; float f201c; float f2020; float f2024; float f2028; float f202c; float f2030; float f2034; float f2038; float f203c; float f2040; float f2044; float f2048; float f204c; float f2050; float f2054; float f2058; float f205c; float f2060; float f2064; float f2068; float f206c; float f2070; float f2074; float f2078; float f207c; float f2080; float f2084; float f2088; float f208c; float f2090; float f2094; float f2098; float f209c; float f20a0; float f20a4; float f20a8; float f20ac; float f20b0; float f20b4; float f20b8; float f20bc; float f20c0; float f20c4; float f20c8; float f20cc; float f20d0; float f20d4; float f20d8; float f20dc; float f20e0; float f20e4; float f20e8; float f20ec; float f20f0; float f20f4; float f20f8; float f20fc; float f2100; float f2104; float f2108; float f210c; float f2110; float f2114; float f2118; float f211c; float f2120; float f2124; float f2128; float f212c; float f2130; float f2134; float f2138; float f213c; float f2140; float f2144; float f2148; float f214c; float f2150; float f2154; float f2158; float f215c; float f2160; float f2164; float f2168; float f216c; float f2170; float f2174; float f2178; float f217c; float f2180; float f2184; float f2188; float f218c; float f2190; float f2194; float f2198; float f219c; float f21a0; float f21a4; float f21a8; float f21ac; float f21b0; float f21b4; float f21b8; float f21bc; float f21c0; float f21c4; float f21c8; float f21cc; float f21d0; float f21d4; float f21d8; float f21dc; float f21e0; float f21e4; float f21e8; float f21ec; float f21f0; float f21f4; float f21f8; float f21fc; float f2200; float f2204; float f2208; float f220c; float f2210; float f2214; float f2218; float f221c; float f2220; float f2224; float f2228; float f222c; float f2230; float f2234; float f2238; float f223c; float f2240; float f2244; float f2248; float f224c; float f2250; float f2254; float f2258; float f225c; float f2260; float f2264; float f2268; float f226c; float f2270; float f2274; float f2278; float f227c; float f2280; float f2284; float f2288; float f228c; float f2290; float f2294; float f2298; float f229c; float f22a0; float f22a4; float f22a8; float f22ac; float f22b0; float f22b4; float f22b8; float f22bc; float f22c0; float f22c4; float f22c8; float f22cc; float f22d0; float f22d4; float f22d8; float f22dc; float f22e0; float f22e4; float f22e8; float f22ec; float f22f0; float f22f4; float f22f8; float f22fc; float f2300; float f2304; float f2308; float f230c; float f2310; float f2314; float f2318; float f231c; float f2320; float f2324; float f2328; float f232c; float f2330; float f2334; float f2338; float f233c; float f2340; float f2344; float f2348; float f234c; float f2350; float f2354; float f2358; float f235c; float f2360; float f2364; float f2368; float f236c; float f2370; float f2374; float f2378; float f237c; float f2380; float f2384; float f2388; float f238c; float f2390; float f2394; float f2398; float f239c; float f23a0; float f23a4; float f23a8; float f23ac; float f23b0; float f23b4; float f23b8; float f23bc; float f23c0; float f23c4; float f23c8; float f23cc; float f23d0; float f23d4; float f23d8; float f23dc; float f23e0; float f23e4; float f23e8; float f23ec; float f23f0; float f23f4; float f23f8; float f23fc; float f2400; float f2404; float f2408; float f240c; float f2410; float f2414; float f2418; float f241c; float f2420; float f2424; float f2428; float f242c; float f2430; float f2434; float f2438; float f243c; float f2440; float f2444; float f2448; float f244c; float f2450; float f2454; float f2458; float f245c; float f2460; float f2464; float f2468; float f246c; float f2470; float f2474; float f2478; float f247c; float f2480; float f2484; float f2488; float f248c; float f2490; float f2494; float f2498; float f249c; float f24a0; float f24a4; float f24a8; float f24ac; float f24b0; float f24b4; float f24b8; float f24bc; float f24c0; float f24c4; float f24c8; float f24cc; float f24d0; float f24d4; float f24d8; float f24dc; float f24e0; float f24e4; float f24e8; float f24ec; float f24f0; float f24f4; float f24f8; float f24fc; float f2500; float f2504; float f2508; float f250c; float f2510; float f2514; float f2518; float f251c; float f2520; float f2524; float f2528; float f252c; float f2530; float f2534; float f2538; float f253c; float f2540; float f2544; float f2548; float f254c; float f2550; float f2554; float f2558; float f255c; float f2560; float f2564; float f2568; float f256c; float f2570; float f2574; float f2578; float f257c; float f2580; float f2584; float f2588; float f258c; float f2590; float f2594; float f2598; float f259c; float f25a0; float f25a4; float f25a8; float f25ac; float f25b0; float f25b4; float f25b8; float f25bc; float f25c0; float f25c4; float f25c8; float f25cc; float f25d0; float f25d4; float f25d8; float f25dc; float f25e0; float f25e4; float f25e8; float f25ec; float f25f0; float f25f4; float f25f8; float f25fc; float f2600; float f2604; float f2608; float f260c; float f2610; float f2614; float f2618; float f261c; float f2620; float f2624; float f2628; float f262c; float f2630; float f2634; float f2638; float f263c; float f2640; float f2644; float f2648; float f264c; float f2650; float f2654; float f2658; float f265c; float f2660; float f2664; float f2668; float f266c; float f2670; float f2674; float f2678; float f267c; float f2680; float f2684; float f2688; float f268c; float f2690; float f2694; float f2698; float f269c; float f26a0; float f26a4; float f26a8; float f26ac; float f26b0; float f26b4; float f26b8; float f26bc; float f26c0; float f26c4; float f26c8; float f26cc; float f26d0; float f26d4; float f26d8; float f26dc; float f26e0; float f26e4; float f26e8; float f26ec; float f26f0; float f26f4; float f26f8; float f26fc; float f2700; float f2704; float f2708; float f270c; float f2710; float f2714; float f2718; float f271c; float f2720; float f2724; float f2728; float f272c; float f2730; float f2734; float f2738; float f273c; float f2740; float f2744; float f2748; float f274c; float f2750; float f2754; float f2758; float f275c; float f2760; float f2764; float f2768; float f276c; float f2770; float f2774; float f2778; float f277c; float f2780; float f2784; float f2788; float f278c; float f2790; float f2794; float f2798; float f279c; float f27a0; float f27a4; float f27a8; float f27ac; float f27b0; float f27b4; float f27b8; float f27bc; float f27c0; float f27c4; float f27c8; float f27cc; float f27d0; float f27d4; float f27d8; float f27dc; float f27e0; float f27e4; float f27e8; float f27ec; float f27f0; float f27f4; float f27f8; float f27fc; float f2800; float f2804; float f2808; float f280c; float f2810; float f2814; float f2818; float f281c; float f2820; float f2824; float f2828; float f282c; float f2830; float f2834; float f2838; float f283c; float f2840; float f2844; float f2848; float f284c; float f2850; float f2854; float f2858; float f285c; float f2860; float f2864; float f2868; float f286c; float f2870; float f2874; float f2878; float f287c; float f2880; float f2884; float f2888; float f288c; float f2890; float f2894; float f2898; float f289c; float f28a0; float f28a4; float f28a8; float f28ac; float f28b0; float f28b4; float f28b8; float f28bc; float f28c0; float f28c4; float f28c8; float f28cc; float f28d0; float f28d4; float f28d8; float f28dc; float f28e0; float f28e4; float f28e8; float f28ec; float f28f0; float f28f4; float f28f8; float f28fc; float f2900; float f2904; float f2908; float f290c; float f2910; float f2914; float f2918; float f291c; float f2920; float f2924; float f2928; float f292c; float f2930; float f2934; float f2938; float f293c; float f2940; float f2944; float f2948; float f294c; float f2950; float f2954; float f2958; float f295c; float f2960; float f2964; float f2968; float f296c; float f2970; float f2974; float f2978; float f297c; float f2980; float f2984; float f2988; float f298c; float f2990; float f2994; float f2998; float f299c; float f29a0; float f29a4; float f29a8; float f29ac; float f29b0; float f29b4; float f29b8; float f29bc; float f29c0; float f29c4; float f29c8; float f29cc; float f29d0; float f29d4; float f29d8; float f29dc; float f29e0; float f29e4; float f29e8; float f29ec; float f29f0; float f29f4; float f29f8; float f29fc; float f2a00; float f2a04; float f2a08; float f2a0c; float f2a10; float f2a14; float f2a18; float f2a1c; float f2a20; float f2a24; float f2a28; float f2a2c; float f2a30; float f2a34; float f2a38; float f2a3c; float f2a40; float f2a44; float f2a48; float f2a4c; float f2a50; float f2a54; float f2a58; float f2a5c; float f2a60; float f2a64; float f2a68; float f2a6c; float f2a70; float f2a74; float f2a78; float f2a7c; float f2a80; float f2a84; float f2a88; float f2a8c; float f2a90; float f2a94; float f2a98; float f2a9c; float f2aa0; float f2aa4; float f2aa8; float f2aac; float f2ab0; float f2ab4; float f2ab8; float f2abc; float f2ac0; float f2ac4; float f2ac8; float f2acc; float f2ad0; float f2ad4; float f2ad8; float f2adc; float f2ae0; float f2ae4; float f2ae8; float f2aec; float f2af0; float f2af4; float f2af8; float f2afc; float f2b00; float f2b04; float f2b08; float f2b0c; float f2b10; float f2b14; float f2b18; float f2b1c; float f2b20; float f2b24; float f2b28; float f2b2c; float f2b30; float f2b34; float f2b38; float f2b3c; float f2b40; float f2b44; float f2b48; float f2b4c; float f2b50; float f2b54; float f2b58; float f2b5c; float f2b60; float f2b64; float f2b68; float f2b6c; float f2b70; float f2b74; float f2b78; float f2b7c; float f2b80; float f2b84; float f2b88; float f2b8c; float f2b90; float f2b94; float f2b98; float f2b9c; float f2ba0; float f2ba4; float f2ba8; float f2bac; float f2bb0; float f2bb4; float f2bb8; float f2bbc; float f2bc0; float f2bc4; float f2bc8; float f2bcc; float f2bd0; float f2bd4; float f2bd8; float f2bdc; float f2be0; float f2be4; float f2be8; float f2bec; float f2bf0; float f2bf4; float f2bf8; float f2bfc; float f2c00; float f2c04; float f2c08; float f2c0c; float f2c10; float f2c14; float f2c18; float f2c1c; float f2c20; float f2c24; float f2c28; float f2c2c; float f2c30; float f2c34; float f2c38; float f2c3c; float f2c40; float f2c44; float f2c48; float f2c4c; float f2c50; float f2c54; float f2c58; float f2c5c; float f2c60; float f2c64; float f2c68; float f2c6c; float f2c70; float f2c74; float f2c78; float f2c7c; float f2c80; float f2c84; float f2c88; float f2c8c; float f2c90; float f2c94; float f2c98; float f2c9c; float f2ca0; float f2ca4; float f2ca8; float f2cac; float f2cb0; float f2cb4; float f2cb8; float f2cbc; float f2cc0; float f2cc4; float f2cc8; float f2ccc; float f2cd0; float f2cd4; float f2cd8; float f2cdc; float f2ce0; float f2ce4; float f2ce8; float f2cec; float f2cf0; float f2cf4; float f2cf8; float f2cfc; float f2d00; float f2d04; float f2d08; float f2d0c; float f2d10; float f2d14; float f2d18; float f2d1c; float f2d20; float f2d24; float f2d28; float f2d2c; float f2d30; float f2d34; float f2d38; float f2d3c; float f2d40; float f2d44; float f2d48; float f2d4c; float f2d50; float f2d54; float f2d58; float f2d5c; float f2d60; float f2d64; float f2d68; float f2d6c; float f2d70; float f2d74; float f2d78; float f2d7c; float f2d80; float f2d84; float f2d88; float f2d8c; float f2d90; float f2d94; float f2d98; float f2d9c; float f2da0; float f2da4; float f2da8; float f2dac; float f2db0; float f2db4; float f2db8; float f2dbc; float f2dc0; float f2dc4; float f2dc8; float f2dcc; float f2dd0; float f2dd4; float f2dd8; float f2ddc; float f2de0; float f2de4; float f2de8; float f2dec; float f2df0; float f2df4; float f2df8; float f2dfc; float f2e00; float f2e04; float f2e08; float f2e0c; float f2e10; float f2e14; float f2e18; float f2e1c; float f2e20; float f2e24; float f2e28; float f2e2c; float f2e30; float f2e34; float f2e38; float f2e3c; float f2e40; float f2e44; float f2e48; float f2e4c; float f2e50; float f2e54; float f2e58; float f2e5c; float f2e60; float f2e64; float f2e68; float f2e6c; float f2e70; float f2e74; float f2e78; float f2e7c; float f2e80; float f2e84; float f2e88; float f2e8c; float f2e90; float f2e94; float f2e98; float f2e9c; float f2ea0; float f2ea4; float f2ea8; float f2eac; float f2eb0; float f2eb4; float f2eb8; float f2ebc; float f2ec0; float f2ec4; float f2ec8; float f2ecc; float f2ed0; float f2ed4; float f2ed8; float f2edc; float f2ee0; float f2ee4; float f2ee8; float f2eec; float f2ef0; float f2ef4; float f2ef8; float f2efc; float f2f00; float f2f04; float f2f08; float f2f0c; float f2f10; float f2f14; float f2f18; float f2f1c; float f2f20; float f2f24; float f2f28; float f2f2c; float f2f30; float f2f34; float f2f38; float f2f3c; float f2f40; float f2f44; float f2f48; float f2f4c; float f2f50; float f2f54; float f2f58; float f2f5c; float f2f60; float f2f64; float f2f68; float f2f6c; float f2f70; float f2f74; float f2f78; float f2f7c; float f2f80; float f2f84; float f2f88; float f2f8c; float f2f90; float f2f94; float f2f98; float f2f9c; float f2fa0; float f2fa4; float f2fa8; float f2fac; float f2fb0; float f2fb4; float f2fb8; float f2fbc; float f2fc0; float f2fc4; float f2fc8; float f2fcc; float f2fd0; float f2fd4; float f2fd8; float f2fdc; float f2fe0; float f2fe4; float f2fe8; float f2fec; float f2ff0; float f2ff4; float f2ff8; float f2ffc; float f3000; float f3004; float f3008; float f300c; float f3010; float f3014; float f3018; float f301c; float f3020; float f3024; float f3028; float f302c; float f3030; float f3034; float f3038; float f303c; float f3040; float f3044; float f3048; float f304c; float f3050; float f3054; float f3058; float f305c; float f3060; float f3064; float f3068; float f306c; float f3070; float f3074; float f3078; float f307c; float f3080; float f3084; float f3088; float f308c; float f3090; float f3094; float f3098; float f309c; float f30a0; float f30a4; float f30a8; float f30ac; float f30b0; float f30b4; float f30b8; float f30bc; float f30c0; float f30c4; float f30c8; float f30cc; float f30d0; float f30d4; float f30d8; float f30dc; float f30e0; float f30e4; float f30e8; float f30ec; float f30f0; float f30f4; float f30f8; float f30fc; float f3100; float f3104; float f3108; float f310c; float f3110; float f3114; float f3118; float f311c; float f3120; float f3124; float f3128; float f312c; float f3130; float f3134; float f3138; float f313c; float f3140; float f3144; float f3148; float f314c; float f3150; float f3154; float f3158; float f315c; float f3160; float f3164; float f3168; float f316c; float f3170; float f3174; float f3178; float f317c; float f3180; float f3184; float f3188; float f318c; float f3190; float f3194; float f3198; float f319c; float f31a0; float f31a4; float f31a8; float f31ac; float f31b0; float f31b4; float f31b8; float f31bc; float f31c0; float f31c4; float f31c8; float f31cc; float f31d0; float f31d4; float f31d8; float f31dc; float f31e0; float f31e4; float f31e8; float f31ec; float f31f0; float f31f4; float f31f8; float f31fc; float f3200; float f3204; float f3208; float f320c; float f3210; float f3214; float f3218; float f321c; float f3220; float f3224; float f3228; float f322c; float f3230; float f3234; float f3238; float f323c; float f3240; float f3244; float f3248; float f324c; float f3250; float f3254; float f3258; float f325c; float f3260; float f3264; float f3268; float f326c; float f3270; float f3274; float f3278; float f327c; float f3280; float f3284; float f3288; float f328c; float f3290; float f3294; float f3298; float f329c; float f32a0; float f32a4; float f32a8; float f32ac; float f32b0; float f32b4; float f32b8; float f32bc; float f32c0; float f32c4; float f32c8; float f32cc; float f32d0; float f32d4; float f32d8; float f32dc; float f32e0; float f32e4; float f32e8; float f32ec; float f32f0; float f32f4; float f32f8; float f32fc; float f3300; float f3304; float f3308; float f330c; float f3310; float f3314; float f3318; float f331c; float f3320; float f3324; float f3328; float f332c; float f3330; float f3334; float f3338; float f333c; float f3340; float f3344; float f3348; float f334c; float f3350; float f3354; float f3358; float f335c; float f3360; float f3364; float f3368; float f336c; float f3370; float f3374; float f3378; float f337c; float f3380; float f3384; float f3388; float f338c; float f3390; float f3394; float f3398; float f339c; float f33a0; float f33a4; float f33a8; float f33ac; float f33b0; float f33b4; float f33b8; float f33bc; float f33c0; float f33c4; float f33c8; float f33cc; float f33d0; float f33d4; float f33d8; float f33dc; float f33e0; float f33e4; float f33e8; float f33ec; float f33f0; float f33f4; float f33f8; float f33fc; float f3400; float f3404; float f3408; float f340c; float f3410; float f3414; float f3418; float f341c; float f3420; float f3424; float f3428; float f342c; float f3430; float f3434; float f3438; float f343c; float f3440; float f3444; float f3448; float f344c; float f3450; float f3454; float f3458; float f345c; float f3460; float f3464; float f3468; float f346c; float f3470; float f3474; float f3478; float f347c; float f3480; float f3484; float f3488; float f348c; float f3490; float f3494; float f3498; float f349c; float f34a0; float f34a4; float f34a8; float f34ac; float f34b0; float f34b4; float f34b8; float f34bc; float f34c0; float f34c4; float f34c8; float f34cc; float f34d0; float f34d4; float f34d8; float f34dc; float f34e0; float f34e4; float f34e8; float f34ec; float f34f0; float f34f4; float f34f8; float f34fc; float f3500; float f3504; float f3508; float f350c; float f3510; float f3514; float f3518; float f351c; float f3520; float f3524; float f3528; float f352c; float f3530; float f3534; float f3538; float f353c; float f3540; float f3544; float f3548; float f354c; float f3550; float f3554; float f3558; float f355c; float f3560; float f3564; float f3568; float f356c; float f3570; float f3574; float f3578; float f357c; float f3580; float f3584; float f3588; float f358c; float f3590; float f3594; float f3598; float f359c; float f35a0; float f35a4; float f35a8; float f35ac; float f35b0; float f35b4; float f35b8; float f35bc; float f35c0; float f35c4; float f35c8; float f35cc; float f35d0; float f35d4; float f35d8; float f35dc; float f35e0; float f35e4; float f35e8; float f35ec; float f35f0; float f35f4; float f35f8; float f35fc; float f3600; float f3604; float f3608; float f360c; float f3610; float f3614; float f3618; float f361c; float f3620; float f3624; float f3628; float f362c; float f3630; float f3634; float f3638; float f363c; float f3640; float f3644; float f3648; float f364c; float f3650; float f3654; float f3658; float f365c; float f3660; float f3664; float f3668; float f366c; float f3670; float f3674; float f3678; float f367c; float f3680; float f3684; float f3688; float f368c; float f3690; float f3694; float f3698; float f369c; float f36a0; float f36a4; float f36a8; float f36ac; float f36b0; float f36b4; float f36b8; float f36bc; float f36c0; float f36c4; float f36c8; float f36cc; float f36d0; float f36d4; float f36d8; float f36dc; float f36e0; float f36e4; float f36e8; float f36ec; float f36f0; float f36f4; float f36f8; float f36fc; float f3700; float f3704; float f3708; float f370c; float f3710; float f3714; float f3718; float f371c; float f3720; float f3724; float f3728; float f372c; float f3730; float f3734; float f3738; float f373c; float f3740; float f3744; float f3748; float f374c; float f3750; float f3754; float f3758; float f375c; float f3760; float f3764; float f3768; float f376c; float f3770; float f3774; float f3778; float f377c; float f3780; float f3784; float f3788; float f378c; float f3790; float f3794; float f3798; float f379c; float f37a0; float f37a4; float f37a8; float f37ac; float f37b0; float f37b4; float f37b8; float f37bc; float f37c0; float f37c4; float f37c8; float f37cc; float f37d0; float f37d4; float f37d8; float f37dc; float f37e0; float f37e4; float f37e8; float f37ec; float f37f0; float f37f4; float f37f8; float f37fc; float f3800; float f3804; float f3808; float f380c; float f3810; float f3814; float f3818; float f381c; float f3820; float f3824; float f3828; float f382c; float f3830; float f3834; float f3838; float f383c; float f3840; float f3844; float f3848; float f384c; float f3850; float f3854; float f3858; float f385c; float f3860; float f3864; float f3868; float f386c; float f3870; float f3874; float f3878; float f387c; float f3880; float f3884; float f3888; float f388c; float f3890; float f3894; float f3898; float f389c; float f38a0; float f38a4; float f38a8; float f38ac; float f38b0; float f38b4; float f38b8; float f38bc; float f38c0; float f38c4; float f38c8; float f38cc; float f38d0; float f38d4; float f38d8; float f38dc; float f38e0; float f38e4; float f38e8; float f38ec; float f38f0; float f38f4; float f38f8; float f38fc; float f3900; float f3904; float f3908; float f390c; float f3910; float f3914; float f3918; float f391c; float f3920; float f3924;
};
struct TexName { int id; char name[32]; };
struct Names { int unk00; int count; TexName textures[8]; };
extern char* DAT_0109b220;
struct StringHeader { long refs; int length; };
extern char* __cdecl FUN_00a5b690(const char*);
struct FixedString { char* handle; FixedString(const char* text) { if(!text) handle=DAT_0109b220; else handle=FUN_00a5b690(text); } ~FixedString() { if(handle==DAT_0109b220) return; StringHeader* header=(StringHeader*)handle-1; InterlockedDecrement(&header->refs); } };
struct PixelFormat { int value; }; extern PixelFormat DAT_011aa2a0;
struct PixelData {
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
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
unsigned char* pixels; int unk54; int unk58; unsigned int* offsets; unsigned int levels; int unk64; int unk68; int unk6c; bool changed;
PixelData(unsigned int,unsigned int,const PixelFormat&,unsigned int,unsigned int);
static void* __cdecl operator new(unsigned int);
static void __cdecl operator delete(void*);
__forceinline unsigned char* GetPixels(unsigned int level=0,unsigned int face=0) { return pixels+face*offsets[levels]+offsets[level]; }
};
struct Preferences { int layout; int alpha; int mip; };
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
inline long DecrementRef(long volatile* value) { return InterlockedDecrement(value); }
inline long IncrementRef(long volatile* value) { return InterlockedIncrement(value); }
struct TextureMap { int unk00; int unk04; int unk08; int unk0c; TextureMap(); void SetFilter(int); };
struct TextureMaps { int unk00; int unk04; int unk08; int unk0c; int unk10; TextureMap*& At(unsigned int); void SetAt(unsigned int,TextureMap*&); };
struct Texture { virtual void V00(); virtual void Destroy(); long unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; TextureMaps maps;
Texture(PixelData*,const FixedString&,const Preferences&);
static void* __cdecl operator new(unsigned int); static void __cdecl operator delete(void*);
void FUN_0060aeb0(int mode) { TextureMap* map=maps.At(0); if(!map) { TextureMap* created=new TextureMap; map=created; maps.SetAt(0,map); } map->SetFilter(mode); } void Release() { if(DecrementRef(&unk04)==0) Destroy(); } long Retain() { return IncrementRef(&unk04); }
};
struct TexturePtr { Texture* value; TexturePtr& operator=(Texture* incoming) { if(value!=incoming) { if(value) value->Release(); value=incoming; if(value) value->Retain(); } return *this; } };
inline float FontMax(float a,float b) { return b>a?b:a; }
inline float FontMin(float a,float b) { return a<b?a:b; }
struct FontLoader { unsigned short refs; char* path; int font; TexturePtr textures[8]; float height; float drop; int overlap; FontData* data;
unsigned short RefCount() { return refs; } const char* Path() { return path; }
void LoadFont(); };
// Loads the font file and its textures, computes glyph height/drop metrics, fills FontData, and increments the loader's ref count.
// @fnv 0x00a15320
void FontLoader::LoadFont() {
ContextScope scope(12);
float maxHeight;
    { LoaderFile* file; float swap;
    { char filename[256];
    {
int letter5;
float extent;
int index3;
PixelData* pixels5;
Texture* texture5;
LoaderFile* kTextureFile;
Preferences prefs4;
unsigned int dimensions2[2];
if(RefCount()==0 && path) {
file=FileFinder::GetFile(path,0,0x4000,2);
if(!file || !file->IsGood()) { FNV_Warning("DEFAULT: Font file not found: %s. \n",Path()); if(file) delete file; return; }
data=new FontData;
file->Read(data,file->Size()); delete file; file=0;
height=0.0f; maxHeight=0.0f; drop=0.0f;
for(letter5=0;letter5<256;letter5++) {
extent=data->f0000-((GlyphData*)data)->letters[letter5].spacing;
extent+=((GlyphData*)data)->letters[letter5].width;
height=FontMax(extent,height);
maxHeight=FontMax(((GlyphData*)data)->letters[letter5].width,maxHeight);
drop=FontMin(drop,((GlyphData*)data)->letters[letter5].spacing-((GlyphData*)data)->letters[letter5].width);
}
swap=data->f084c; data->f084c=data->f0858; data->f0858=swap;
data->f0850=maxHeight; data->f085c=drop+maxHeight;
data->f244c=data->f084c; data->f2458=data->f0858; data->f2450=data->f0850; data->f245c=data->f085c;
data->f1d14=data->f1c6c; data->f1d1c=data->f1c74; data->f1d20=data->f1c78; data->f1d18=data->f1c70; data->f1d24=data->f1c7c;
data->f014c=0.0f; data->f0158=0.0f; data->f0150=maxHeight; data->f015c=drop+maxHeight;
data->f012c=0.0f; data->f0134=0.0f; data->f013c=0.0f; data->f0144=0.0f;
data->f0130=0.0f; data->f0138=0.0f; data->f0140=0.0f; data->f0148=0.0f;
if(data->f0004>8) { FNV_Warning("TEXTURES: Too many font textures for %s.\nMax textures is %d yours has %d.\n",Path(),8,data->f0004); return; }
for(index3=0;index3<data->f0004;index3++) {
_sprintf_s(filename,256,"TEXTURES\\FONTS\\%s.TEX",((Names*)data)->textures[index3].name);
kTextureFile=FileFinder::GetFile(filename,0,0x4000,2);
if(!kTextureFile || !kTextureFile->IsGood()) { FNV_Warning("DEFAULT: Font file not found: %S. \n",filename); if(kTextureFile) delete kTextureFile; return; }
kTextureFile->Read(dimensions2,8);
prefs4.layout=6; prefs4.alpha=3; prefs4.mip=2;
pixels5=new PixelData(dimensions2[0],dimensions2[1],DAT_011aa2a0,1,1);
kTextureFile->Read(pixels5->GetPixels(),dimensions2[0]*dimensions2[1]*4);
pixels5->changed=true;
texture5=new Texture(pixels5,FixedString(Path()),prefs4);
delete kTextureFile; kTextureFile=0; texture5->FUN_0060aeb0(1); textures[index3]=texture5;
}
}
    }
    }
    }
++refs;}

namespace fnv_00a19f70 {
struct LayoutMemory { void Deallocate(void*); };
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
void* LayoutCopy(void*,const void*,unsigned int);
struct LayoutString {
    char* text; unsigned short length, capacity;
    LayoutString() { text=0; SetLength(0); SetMaxLength(0); }
    LayoutString& operator=(const char* source) { Set(source,0); return *this; }
    ~LayoutString() { Set(0,0); }
    unsigned int MaxLength() const { return capacity; }
    void SetMaxLength(unsigned int n) { capacity=n<=0xffff?(unsigned short)n:0xffff; }
    void SetLength(unsigned int n) { length=n<=0xffff?(unsigned short)n:0xffff; }
    bool Set(const char* source, unsigned int minimum) {
        unsigned int size=source?LayoutLength(source):0;
        unsigned int maximum=LayoutCapacity(size,minimum);
        if(maximum<=MaxLength()) {
            if(maximum) { if(source) LayoutCopy(text,source,size+1); else text[0]=0; }
            else {
                if(text) { char* old=text; operator delete(old); }
                text=0; maximum=0; SetMaxLength(maximum);
            }
        } else {
            char* old=text;
            void* allocated=operator new(maximum+1);
            text=(char*)allocated;
            if(source) LayoutCopy(text,source,size+1); else text[0]=0;
            if(old) { char* discarded=old; operator delete(discarded); }
            SetMaxLength(maximum);
        }
        SetLength(size);
        return size!=0;
    }
    char& operator[](unsigned int index) const { return text[text ? index : 0]; }
    char* Get() const { return text; }
    bool Empty() const { return !Get() || !(*this)[0]; }
};
struct LayoutColor { float r,g,b,a; LayoutColor() : r(0),g(0),b(0),a(0) {} LayoutColor(const float& x,const float& y,const float& z,float w) : r(x),g(y),b(z),a(w) {} };
struct GlyphData { float height; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124; FontCharacterInfo glyphs[256]; };
struct LayoutItem {
    int font; unsigned char character; unsigned char unk05; unsigned short unk06;
    LayoutColor color; int unk18;
    LayoutString string;
    int width,height,depth,offset,position;
    LayoutItem(int fontIndex, int value, LayoutColor newColor, int flags) {
        int limited=fontIndex<8?fontIndex:8;
        font=limited<0?0:limited;
        character=(unsigned char)value;
        color=newColor;
        unk18=flags;
        string=0;
        FontManager* manager=FontManager::pInstance;
        Font* selected=manager->pFont[font];
        FontCharacterInfo* letter=&((GlyphData*)selected->m_pFontData)->glyphs[character];
        width=(int)(letter->m_fGlyphWidthInPixels+letter->m_fGlyphWidthInPixels>0.0?letter->m_fHorizontalAdvance+letter->m_fHorizontalSpacing:0.0);
        FontManager* manager2=FontManager::pInstance;
        Font* selected2=manager2->pFont[font];
        height=(int)((GlyphData*)selected2->m_pFontData)->height;
        depth=(int)(letter->m_fGlyphExtent-letter->m_fVerticalOffset);
        offset=0;
        position=0;
    }
    void FUN_00a1b7f0(unsigned char value) {
        character=value;
        if(!string.Get() || !string[0]) {
            FontManager* manager=FontManager::pInstance;
            Font* selected=manager->pFont[font];

            FontCharacterInfo* letter=&((GlyphData*)selected->m_pFontData)->glyphs[character];
            width=(int)(letter->m_fGlyphWidthInPixels+(letter->m_fGlyphWidthInPixels>0.0?letter->m_fHorizontalSpacing+letter->m_fHorizontalAdvance:0.0));
            FontManager* manager2=FontManager::pInstance; Font* selected2=manager2->pFont[font];
            height=(int)((GlyphData*)selected2->m_pFontData)->height;
            FontManager* manager3=FontManager::pInstance; Font* selected3=manager3->pFont[font];
            float drop=selected3->m_fDrop; depth=(int)-drop;
            offset=0;
        }
        position=0;
    }
    bool Empty() const { return !string.Get() || !string[0]; }
    ~LayoutItem() {}
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
};
struct LayoutNode { LayoutNode* next; LayoutNode* prev; LayoutItem* item; };
unsigned int LayoutCurrentThread();
long LayoutCompareExchange(volatile long*,long,long);
void LayoutYield(unsigned long);
void LayoutMemoryBarrier();
struct LayoutPoolLock {
    unsigned int owner, recursion;
    void Lock(const char*) {
        unsigned int thread=LayoutCurrentThread();
        if(owner==thread) ++recursion;
        else {
            unsigned int spins=0;
            while(LayoutCompareExchange((volatile long*)&owner,thread,0)) {
                ++spins;
                if(spins>10000) LayoutYield(1); else LayoutYield(0);
            }
            LayoutMemoryBarrier();
            recursion=1;
        }
    }
    void Unlock();
};
extern LayoutPoolLock LayoutNodeLock;
extern LayoutNode* LayoutNodeFreeList;
void LayoutRefillNodes();
struct LayoutOwner { int unk00,unk04,unk08,width; };
extern int LayoutFontHeights[];
struct LayoutLine {
    LayoutNode* head; LayoutNode* tail; int count,width,unk10,height,depth,unk1c,unk20,maxWidth,unk28;
    LayoutOwner* owner;
    LayoutLine(LayoutOwner*,LayoutItem*,int,int);
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
    LayoutItem* RemoveTail() {
        LayoutItem* value=0;
        LayoutNode* node=tail;
        if(node) {
            value=node->item;
            tail=node->prev;
            if(tail) tail->next=0; else head=0;
            --count;
            ((LayoutMemory*)&g_memoryManager)->Deallocate(node);
        }
        return value;
    }
    int Count() const { return count; }
    LayoutNode* Tail() const { return tail; }
    LayoutNode* Head() const { return head; }
    LayoutItem*& Previous(LayoutNode*& node) const { LayoutItem** item=&node->item; node=node->prev; return *item; }
    LayoutItem*& Next(LayoutNode*& node) const { LayoutItem** item=&node->item; node=node->next; return *item; }
    LayoutItem* First() const { LayoutItem* item=0; if(Count()) item=head->item; return item; }
    LayoutItem* Last() const { LayoutItem* item=0; if(Count()) item=tail->item; return item; }
    LayoutNode* AllocateNode() {
        LayoutNodeLock.Lock(0);
        if(!LayoutNodeFreeList) LayoutRefillNodes();
        LayoutNode* node=LayoutNodeFreeList;
        LayoutNodeFreeList=LayoutNodeFreeList->next;
        node->item=0; node->next=0; node->prev=0;
        LayoutNodeLock.Unlock();
        return node;
    }
    void FUN_00a0c9f0(LayoutItem* const& value) {
        LayoutNode* node=AllocateNode(); node->item=value; node->prev=0; node->next=head;
        if(head) head->prev=node; else tail=node;
        head=node; ++count;
    }
    void LinkTail(LayoutNode* node) {
        node->next=0; node->prev=tail;
        if(tail) tail->next=node; else head=node;
        tail=node; ++count;
    }
    void AddItem(LayoutItem* const& value) { LayoutNode* node=AllocateNode(); node->item=value; LinkTail(node); }
    LayoutLine* WrapLine(LayoutItem* source, bool start);
};
inline int LayoutMax(int a,int b) { return a>b?a:b; }
// @fnv 0x00a19f70
LayoutLine* LayoutLine::WrapLine(LayoutItem* apItem, bool start) {
    LayoutLine* first6=0;
    if(width+apItem->width>maxWidth) {
        if(apItem->character!=0x20) {
            LayoutNode* b=Tail();
            while(b && b->item->character!=0x20) Previous(b);
            if(b) {
                first6=new LayoutLine(owner,apItem,0,maxWidth);
                first6->height=LayoutFontHeights[apItem->font];
                LayoutItem* last4=RemoveTail();
                while(Count() && last4->character!=0x20) {
                    first6->WrapLine(last4,true);
                    last4=RemoveTail();
                    width-=last4->width;
                }
                if(last4) delete last4;
            } else {
                first6=new LayoutLine(owner,apItem,0,maxWidth);
                first6->height=LayoutFontHeights[apItem->font];
                LayoutItem* result2=new LayoutItem(0,0x2d,LayoutColor(DAT_01095268,DAT_01095264,DAT_01095260,1.0f),1);
                long c=0;
                LayoutItem* last4=0;
                while(Count() && width-c+result2->width>maxWidth) {
                    last4=RemoveTail();
                    first6->WrapLine(last4,true);
                    c+=last4->width;
                }
                width-=c;
                WrapLine(result2,false);
            }
        } else {
            apItem->FUN_00a1b7f0(0);
            first6=new LayoutLine(owner,apItem,0,maxWidth);
            first6->height=LayoutFontHeights[apItem->font];
        }
    } else {
        if(apItem->Empty()) {
            bool node=false;
            if(!Count()) height=LayoutFontHeights[apItem->font];
            if(start) {
                LayoutItem* changed2=0;
                if(Count()) changed2=head->item;
                if(changed2 && apItem->font!=changed2->font) node=true;
                apItem->position=apItem->offset;
                width=apItem->width;
                LayoutNode* b;
                b = Head();
                while(b) {
                    LayoutItem* last4=Next(b);
                    last4->position=width+last4->offset;
                    width+=last4->width;
                }
            } else {
                LayoutItem* removed=0;
                if(Count()) removed=tail->item;
                if(removed && apItem->font!=removed->font) node=true;
                apItem->position=width+apItem->offset;
                width+=apItem->width;
            }
            if(node) height=LayoutMax(height,apItem->height);
            depth=LayoutMax(depth,apItem->depth);
        } else {
            if(start) {
                apItem->position=0;
                width=apItem->width;
                LayoutNode* b;
                b = Head();
                while(b) {
                    LayoutItem* last4=Next(b);
                    last4->position=width+last4->offset;
                    width+=last4->width;
                }
            } else {
                apItem->position=width;
                width+=apItem->width;
            }
            height=LayoutMax(height,apItem->height);
            depth=LayoutMax(depth,apItem->depth);
        }
        if(start) FUN_00a0c9f0(apItem); else AddItem(apItem);
        owner->width=LayoutMax(owner->width,width);
    }
    return first6;
}
}  // namespace fnv_00a19f70

namespace fnv_00a1aee0 {
struct IconRect {
    float left, right, top, bottom;
    IconRect() { left = 0.0f; right = 0.0f; top = 0.0f; bottom = 0.0f; }
};
struct IconData {
    float width, m_fVerticalExtent, zOffset, spacing;
    IconRect uv;
};
struct IconSetting {
    void* vtable;
    const char* value;
    const char* Get() { return this ? value : 0; }
};
extern IconSetting g_011f3368;
void __cdecl FUN_00a06dd0(const char*, const char*, BSStringT<char>*, IconRect*);
void* operator new(unsigned int, void* address) { return address; }
struct IconArray {
    void** vtable;
    IconData* data;
    unsigned int size, capacity;
    unsigned int FUN_00a1c130();
    void ConstructElements(IconData* first, unsigned int count) {
        for (unsigned int i = 0; i < count; ++i) { IconData* element = new (first + i) IconData; }
    }
    void Append(const IconData& icon) {
        unsigned int index = FUN_00a1c130();
        ConstructElements(data + index, 1);
        data[index] = icon;
    }
};
struct FUN_00a1aee0_shell : Font {
    void FUN_00a14170(IconData*, const char*);
    void LoadIconFromPath(const char* path);
};
// Parses the icon suffix from the path after the last underscore, builds an IconData via FUN_00a06dd0 and FUN_00a14170, then appends it to the icon array.
// @fnv 0x00a1aee0
void FUN_00a1aee0_shell::LoadIconFromPath(const char* path) {
    IconData icon6;
    FUN_00a06dd0(g_011f3368.Get(), path, &m_kIconTexturePath, &icon6.uv);
    int offset = strlen(path) - 1;
    int count7 = 0;
    while (path[offset] != '_') --offset;
    char suffix[4];
    for (count7 = 0; count7 < 3 && path[offset + count7 + 1] != '.'; ++count7) {
        suffix[count7] = path[offset + count7 + 1];
    }
    suffix[count7] = 0;
    FUN_00a14170(&icon6, suffix);
    reinterpret_cast<IconArray*>(&m_kButtonIcons)->Append(icon6);
}
}  // namespace fnv_00a1aee0

struct FontTextVec4
{
    float x;
    float y;
    float z;
    float w;
    FontTextVec4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
};

inline unsigned short FontTextClampLength(unsigned int auiLength)
{
    return auiLength <= 0xFFFF ? (unsigned short)auiLength : 0xFFFF;
}

struct FontTextString
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    FontTextString()
    {
        pString = 0;
        sLen = FontTextClampLength(0);
        sMaxLen = FontTextClampLength(0);
    }
    ~FontTextString();
    bool Set(const char* apString, unsigned int auiLength);
    bool Set(const FontTextString& src);
    FontTextString& operator=(const FontTextString& src) { Set(src); return *this; }
    FontTextString& Clear() { Set(0, 0); return *this; }
};

template <class T> inline T FontTextMin(T a, T b) { return a < b ? a : b; }
template <class T> inline T FontTextMax(T a, T b) { return a < b ? b : a; }

struct FontTextData
{
    float m_fFontSize;
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020;
    int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040;
    int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060;
    int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080;
    int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0;
    int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0;
    int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0;
    int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100;
    int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120;
    int unk124;
    FontCharacterInfo kLetters[256];
};

struct FontTextFont
{
    int unk00;
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
    FontTextData* m_pFontData;
};

struct FontTextManager
{
    FontTextFont* pFont[8];
    static FontTextManager* pInstance;
    static FontTextManager* Instance()
    {
        FontTextManager* manager = pInstance;
        return manager;
    }
    FontTextFont* GetFont(int i) { return pFont[i]; }
};

struct FontTextParams
{
    int m_iType;
    bool bFlag;
    FontTextVec4 kColor;
    int iAlignment;
    FontTextString kText;
    int iLineHeight;
    int iHeight;
    int m_iDrop;
    int unk30;
    int unk34;

    FontTextParams(int aiFont, bool abFlag, FontTextVec4 akColor, int aiAlignment)
    {
        m_iType = FontTextMax(FontTextMin(aiFont, 8), 0);
        bFlag = abFlag;
        kColor = akColor;
        iAlignment = aiAlignment;
        kText.Clear();
        FontCharacterInfo* pLetter = &FontTextManager::Instance()->GetFont(m_iType)->m_pFontData->kLetters[bFlag];
        float width = pLetter->m_fGlyphWidthInPixels;
        float doubledWidth = width + width;
        float leading = pLetter->m_fHorizontalAdvance;
        float spacing = pLetter->m_fHorizontalSpacing;
        iLineHeight = (int)(doubledWidth != 0.0 ? leading + spacing : 0.0);
        FontTextManager* heightManager = FontTextManager::Instance();
        FontTextFont* heightFont = heightManager->GetFont(m_iType);
        FontTextData* heightData = heightFont->m_pFontData;
        float lineHeight = heightData->m_fFontSize;
        iHeight = (int)lineHeight;
        float glyphHeight = pLetter->m_fGlyphExtent;
        float topEdge = pLetter->m_fVerticalOffset;
        float drop = glyphHeight - topEdge;
        m_iDrop = (int)drop;
        unk30 = 0;
        unk34 = 0;
    }
    // end ctor
    static __forceinline void* operator new(unsigned int s) { return g_memoryManager.Allocate(s); }
    static __forceinline void operator delete(void*) {}

    FontTextParams* Clone();
};

// Allocates a copy of this FontTextParams, copies the text and metrics, resets unk30 to 0 and returns the new object.
// @fnv 0x00a1b660
FontTextParams* FontTextParams::Clone()
{
    FontTextParams* pCopy = new FontTextParams(m_iType, bFlag, kColor, iAlignment);
    pCopy->kText = kText;
    pCopy->iLineHeight = iLineHeight;
    pCopy->iHeight = iHeight;
    pCopy->m_iDrop = m_iDrop;
    pCopy->unk34 = unk34;
    pCopy->unk30 = 0;
    return pCopy;
}

struct S_00a12300_Arr {
    int unk00;
    int count;
};

struct S_00a12300_Elem {
    int unk00;
    void FUN_0066b0d0(int a);
};

struct S_00a12300_Glob {
    int unk00;
    void FUN_00aa4060(S_00a12300_Arr* p);
};

extern S_00a12300_Glob DAT_011f6238;

struct S_00a12300_Obj {
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
    S_00a12300_Arr* m_aiIndexedValues;
    void ClearArray();
};

// @fnv 0x00a12300
void S_00a12300_Obj::ClearArray() {
    int unusedOne;
    int unusedTwo;
    int index;
    int array;

    for (unusedOne = 0; m_aiIndexedValues != 0 && unusedOne < m_aiIndexedValues->count; unusedOne++) {
        ((S_00a12300_Elem*)((char*)this + 0xc + unusedOne * 4))->FUN_0066b0d0(0);
    }

    index = (int)m_aiIndexedValues;
    DAT_011f6238.FUN_00aa4060((S_00a12300_Arr*)index);
    m_aiIndexedValues = 0;
}

namespace fnv_00a16ea0 {
extern "C" char DAT_011f6238;

struct SStr {
    char* pString;
    unsigned short iLen;
    unsigned short sMaxLen;
    SStr(unsigned int n = 0) {
        pString = 0;
        iLen = (unsigned short)(n <= 0xFFFF ? (unsigned short)n : 0xFFFF);
        sMaxLen = (unsigned short)(n <= 0xFFFF ? (unsigned short)n : 0xFFFF);
    }
    SStr(const SStr&);
    SStr& operator+=(const char*);
    void AssignFromString(const SStr&);
    bool Set(const char*, unsigned int);
    ~SStr() { Set(0, 0); }
};

struct Hole { int a[42]; };
inline void Pad168() { Hole hole; (void)&hole; }

struct MM { void* FUN_00aa3e40(unsigned int); void FUN_00aa4060(void*); };

struct TexNode { void LoadIconFromPath(char*); };

struct FontC {
    TexNode* m_apNode[8];
    int GetCharClassFlags(char);
    TexNode* GetNode(unsigned i) { return m_apNode[i]; }
    SStr FUN_00a16ea0(const char* text, int* pos, unsigned mask, unsigned mask2,
                      int* value, char* pch, bool flag);
};

void __cdecl FUN_005b5e40(int, const char*, int);
void __cdecl FUN_00ec8d5f(char*, int, const char*, int);
void __cdecl FUN_007070c0(char*, char*, int, int);
void __cdecl FUN_00ec61c0(void*, int, unsigned int);
void __cdecl FUN_00ec7c66(char*, int, const char*, int);

inline void CopyName(char* d, int sz, const char* s, int n) { FUN_00ec8d5f(d, sz, s, n); }

// Scans text from *pos until a stop character or mask match, expanding '&...;' settings into _buf, and returns the accumulated SStr.
// @fnv 0x00a16ea0
SStr FontC::FUN_00a16ea0(const char* text, int* apiPos, unsigned mask, unsigned mask2,
                         int* apiValue, char* apCh, bool abExpandSettings)
{
    SStr str3;
    char _buf[0x800];
    int count2 = 0;
    int other7 = 0;
    FUN_00ec61c0(_buf, 0, 0x800);
    while (true) {
        *apCh = text[*apiPos];
        int r6 = this->GetCharClassFlags((unsigned char)*apCh);
        if (r6 & 0x20) {
            *apiValue = 0x20;
            break;
        } else if (r6 & mask) {
            *apiValue = r6;
            (*apiPos)++;
            break;
        } else if (mask2 != 0 && (r6 & mask2) == 0) {
            *apCh = text[*apiPos];
            *apiValue = this->GetCharClassFlags((unsigned char)*apCh);
            break;
        } else if (*apCh == '\n' || *apCh == '\r') {
            (*apiPos)++;
            continue;
        } else if (abExpandSettings) {
            if (text[*apiPos] == '&') {
                int n5 = 1;
                while (!this->GetCharClassFlags((unsigned char)text[*apiPos + n5]) &&
                       text[*apiPos + n5 - 1] != ';')
                    n5++;
                if (text[*apiPos + n5 - 1] != ';') {
                    FUN_005b5e40(0x12, "Font::CollectTo() -- Found GameSetting w/o ending ; in HTML text.", 0);
                } else {
                    int iLen;
                    void* lenB = ((MM*)&DAT_011f6238)->FUN_00aa3e40(n5 + 1);
                    char* p2 = (char*)lenB;
                    CopyName(p2, n5 + 1, &text[*apiPos], n5);
                    p2[n5] = 0;
                    char kNamebuf[0x104];
                    kNamebuf[0] = 0;
                    FUN_007070c0(p2, kNamebuf, 0x104, 0);
                    if (kNamebuf[0] == '\\') {
                        kNamebuf[strlen(kNamebuf) - 1] = 0;
                        GetNode(0)->LoadIconFromPath(&kNamebuf[1]);
                        _buf[count2] = 1;
                        count2++;
                    } else if (kNamebuf[0] != 0) {
                        iLen = (int)strlen(kNamebuf);
                        FUN_00ec7c66(&_buf[count2], iLen, kNamebuf, iLen);
                        count2 += iLen;
                    } else if (n5 != 0) {
                        FUN_00ec7c66(&_buf[count2], n5, p2, n5);
                        count2 += n5;
                    }
                    *apiPos = n5 + *apiPos - 1;
                    void* aTmp = p2;
                    ((MM*)&DAT_011f6238)->FUN_00aa4060(aTmp);
                }
            } else {
                _buf[count2] = text[*apiPos];
                count2++;
                if (count2 > 0x7d0) {
                    str3 += _buf;
                    count2 = 0;
                }
            }
        }
        (*apiPos)++;
    }
    Pad168();
    str3 += _buf;
    return str3;
}
}  // namespace fnv_00a16ea0

namespace fnv_00a18a30 {
extern "C" char DAT_011f6238;
extern "C" float DAT_01095260, DAT_01095264, DAT_01095268;

void __cdecl NormalizeSmartQuotes(unsigned char& character);

struct SStr {
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    char* GetString() { return pString; }
    unsigned int GetLen() { return sLen == 0xffff ? (unsigned int)strlen(GetString()) : (unsigned int)sLen; }
    bool Set(const char*, unsigned int);
    bool Set(const SStr&);
};

struct Pool { void* FUN_00aa3e40(unsigned int); };

struct Info_ {
    int m_iType;
    int iHeight;
    RgbaColor color;
    char cBreak;
    int iStart;
    int iEnd;
    int iLeading;
    int iUnused;
    int oFirst;
    int oLast;
    char bFlag;
    SStr str;
    int GetFont() { return m_iType; }
    int GetHeight() { return iHeight; }
    RgbaColor GetColor() { return color; }
    int GetStart() { return iStart; }
    int GetEnd() { return iEnd; }
    int GetLeading() { return iLeading; }
};

inline void SetName(Info_* info, SStr* src) {
    SStr* p = &info->str;
    p->Set(*src);
}

__forceinline RgbaColor& MakeColor() {
    RgbaColor c;
    c.r = DAT_01095268;
    c.g = DAT_01095264;
    c.b = DAT_01095260;
    c.a = 1.0f;
    return c;
}

struct ColA {
    float r, g, b, a;
    ColA() { r = DAT_01095268; g = DAT_01095264; b = DAT_01095260; a = 1.0f; }
};

inline int Max(int a, int b) { return a > b ? a : b; }

struct Hole38 { int a[14]; };
struct Hole20 { int a[8]; };
inline void Pad38() { Hole38 h; }
inline void Pad20() { Hole20 h; }

struct Entry {
    int v00, v04, v08, v0c, v10, v14, v18, v1c, v20;
    int GetV0c() { return v0c; }
};
struct ListNode { ListNode* next; ListNode* prev; Entry* item; };
struct ListObj {
    ListNode* head;
    int f4;
    void* f8;
    int fC, f10, f14, f18, f1c;
    Entry* GetHead() { return (Entry*)head; }
    void* GetX8() { return f8; }
};

__forceinline Entry* TakeNext(ListNode*& node) {
    Entry** pp = &node->item;
    node = node->next;
    return *pp;
}

struct TextRun {
    int m_iType;
    unsigned char cChar;
    RgbaColor color;
    int iExtra;
    SStr str;
    int a24, a28, a2c, a30, a34;
    TextRun(int, unsigned char, ColA, int);
    void FUN_00a1b770();
    void FUN_00a1b7f0(unsigned char);
    TextRun* Clone(int, int);
    ~TextRun() { str.Set(0, 0); }
};

struct RunNodeBase { void* b0; void* b4; void* b8; RunNodeBase(); };
struct RunNode : RunNodeBase {
    int c, d, e;
    RunNode(int a, int b, int cc) : RunNodeBase() { this->c = a; this->d = b; this->e = cc; }
    static void* operator new(unsigned int n) { return ((Pool*)&DAT_011f6238)->FUN_00aa3e40(n); }
    ListObj* GetList();
    void FUN_00a19a10(TextRun*);
    void* GetB8() { return b8; }
};

struct FontData {
    RunNode* ParseLayout(SStr*, Info_*);
    RunNode* CreateTextRunNode(SStr* text, Info_* info);
};

// Builds a RunNode for the given text and Info_, splitting text into TextRuns by break char and updating the Info_ start/end/first/last fields.
// @fnv 0x00a18a30
RunNode* FontData::CreateTextRunNode(SStr* text, Info_* info) {
    if (text->GetString() == 0) return 0;
    if (info->GetStart() < 2) info->iStart = 0x7fffffff;
    if (info->GetEnd() < 2) info->iEnd = 0x7fffffff;
    RunNode* pNode = 0;
    pNode = ParseLayout(text, info);
    if (pNode) return pNode;
    pNode = new RunNode(info->GetStart(), info->GetEnd(), info->GetLeading());
    Pad38();
    TextRun textRun(0, ' ', ColA(), 1);
    textRun.FUN_00a1b770();
    textRun.m_iType = info->GetFont();
    textRun.color = info->GetColor();
    textRun.iExtra = info->GetHeight();
    if (text->GetLen() <= 0) text->Set(" ", 0);
    SetName(info, text);
    int w = 0;
    for (unsigned int i = 0; i < text->GetLen(); i++) {
        unsigned char c = *(text->pString + (text->pString ? i : 0));
        NormalizeSmartQuotes(c);
        if (c == info->cBreak) w++;
        else if (c == 9 || c >= 0x20) {
            textRun.FUN_00a1b7f0(c);
            pNode->FUN_00a19a10(textRun.Clone(w, 0));
            w = 0;
        }
    }
    Pad38();
    info->bFlag = 0;
    info->oFirst = 0;
    info->iStart = 0;
    info->iEnd = 0;
    info->oLast = 0;
    if (pNode) {
        info->oFirst = (int)pNode->GetB8();
        ListObj* list = pNode->GetList();
        if (list) {
            info->iEnd = 0;
            info->iStart = 0;
            ListNode* node = (ListNode*)list->GetHead();
            while (node) {
                Entry* e = TakeNext(node);
                info->iEnd += e->v14 + e->v1c;
                info->iStart = Max(info->iStart, e->v0c);
            }
            info->oLast = (int)list->GetX8();
        }
    }
    Pad20();
    return pNode;
}
}  // namespace fnv_00a18a30

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

namespace fnv_00a12880 {
void __cdecl NormalizeSmartQuotes(unsigned char*);
extern float DAT_0102f0f8;
extern double DAT_010731a8;
double __cdecl FUN_00ec9130(double, double);
extern char DAT_01011584[];
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
inline void* LayoutCopy(void* destination,const void* source,unsigned int size) { return memcpy(destination,source,size); }
struct LayoutText {
    char* data; unsigned short length,capacity;
    void Init();
    unsigned int MaxLength() const { return capacity; }
    void SetLength(unsigned int n) { length=n<=0xffff?(unsigned short)n:0xffff; }
    void SetMaxLength(unsigned int n) { capacity=n<=0xffff?(unsigned short)n:0xffff; }
    bool Set(const char* source,unsigned int minimum) {
        unsigned int size=source?LayoutLength(source):0;
        unsigned int maximum=LayoutCapacity(size,minimum);
        if(maximum<=MaxLength()) {
            if(maximum) {
                if(source) LayoutCopy(data,source,size+1);
                else data[0]=0;
            } else {
                if(data) delete data;
                data=0; maximum=0; SetMaxLength(maximum);
            }
        } else {
            char* old=data;
            data=new char[maximum+1];
            if(source) LayoutCopy(data,source,size+1);
            else data[0]=0;
            if(old) delete old;
            SetMaxLength(maximum);
        }
        SetLength(size);
        return size!=0;
    }
    LayoutText() { Init(); }
    ~LayoutText() { Set(0,0); }
    LayoutText& operator=(const char* source) { Set(source,0); return *this; }
};
struct CharacterPosition {
    int offset; CharacterPosition* next;
    CharacterPosition() { offset=0; next=0; }
    void RemoveAll() {
        while(next) {
            CharacterPosition* following=next->next;
            next->next=0;
            delete next;
            next=following;
        }
        offset=0;
    }
    ~CharacterPosition() { RemoveAll(); }
};
struct FUN_00759330 {
    LayoutText text; int width; int height;
    int startOffset; int layoutVersion; int geometryKey; int layoutFlags;
    CharacterPosition firstPosition;
    FUN_00759330(int newWidth,int newHeight,int newCount,int newLimit,unsigned char separator) {
        text=DAT_01011584;
        width=newWidth; height=newHeight; startOffset=newCount; layoutVersion=newLimit;
        geometryKey=0; layoutFlags=separator;
    }
    ~FUN_00759330() { firstPosition.RemoveAll(); }
    int GetCharacterOffset(int index) {
        CharacterPosition* node = &firstPosition;
        int current=0;
        while(current<index && node) { node=node->next; ++current; }
        if(node) return node->offset;
        else return -1;
    }
    char& operator[](unsigned int index) { return text.data[text.data ? index : 0]; }
    int GetWidth() { return width; }
    int GetHeight() { return height; }
    int GetGeometryKey() { return geometryKey; }
};
struct GlyphData { int texture; TextureCoordinate mapping[4]; float width,height,leading,spacing,top; };
struct FontDataView {
    float height;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    GlyphData letters[256];
};
struct BoundView { void ComputeBoundingSphere(unsigned short, int); int a,b,c,d; };
struct GeometryView {
    int unk00,unk04; unsigned short vertices,id; int unk0c;
    BoundView bound; int active;
    unsigned short GetVertices() { return vertices; }
    int GetActive() { int result=active; return result; }
    void FUN_00a67050(int);
};
struct ShapeView {
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    NiPoint3 position6;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryView* geometry;
    void SetPosition(const NiPoint3& point) { position6=point; }
    GeometryView* GetGeometry() { return geometry; }
};
struct FinalizerView {
    virtual void* Allocate(unsigned int);
    virtual void* Reallocate(void*,unsigned int);
    virtual void Free(void*);
    ButtonIcon* buffer; unsigned int count,capacity;
    void FUN_00a1bfa0(bool release) {
        if(buffer) {
            for(unsigned int index=0; index<count; ++index) {}
            if(release) { Free(buffer); buffer=0; buffer=0; capacity=0; }
            count=0;
        }
    }
};
struct FontRenderer {
    unsigned short refs; char* file; int number;
    NiPointer<NiTexturingProperty> textures[8];
    float fontHeight,maxDrop; int overlap; FontDataView* data;
    BSStringT<char> atlas; FinalizerView finalizer;
    bool HasNoIcons() { return finalizer.count==0; }
    unsigned int GetIconCount() { return finalizer.count; }
    void FUN_00a12880(int*,int*,int*,int,int,int,char,int,ShapeView**,ShapeView**);
    void FUN_00a12fb0(int,FUN_00759330*);
    ShapeView* CreateTextShape(int,int,int);
    ShapeView* FUN_00a14da0();
    void UpdateIconGeometry(int,ShapeView*,NiPoint3&);
    void BuildGlyphQuad(GlyphData*,int,ShapeView*,NiPoint3&,int);
};
__forceinline int Maximum(int advance,int oldWidth) { return advance>oldWidth ? advance : oldWidth; }
__forceinline int SourceValue(int* source) { return *source; }
__forceinline void MarkGeometry(ShapeView* shape) { GeometryView* geometry=shape->GetGeometry(); geometry->FUN_00a67050(0x4000); }
struct InlineManager : FontManager {
    __declspec(noinline) float LinePadding(int font) {
        float padding=0.0f;
        switch(font) {
        case 3: padding=6.0f; break;
        case 7: padding=2.0f; break;
        case 2: case 6: padding=4.0f; break;
        }
        return padding;
    }
};
inline InlineManager* Manager() { return (InlineManager*)FontManager::pInstance; }
__forceinline double TabMod(const float& value) { return (float)FUN_00ec9130((double)value,(double)DAT_0102f0f8); }
__forceinline void TabAdvance(float& value) { float tabPosition=value; float tabMultiple=(float)TabMod(tabPosition); value=DAT_010731a8-tabMultiple+value; }
// @fnv 0x00a12880
void FontRenderer::FUN_00a12880(int* source,int* width,int* height,int count,int limit,int mode,char separator,int flags,ShapeView** primary,ShapeView** secondary) {
    if(*height==0) *height=0x7fffffff;
    if(!limit) limit=0x7fffffff;
    unsigned char letter9;
    int letterCode7;
    GlyphData* glyph;
    int secondaryActive_2;
    float lineB=Manager()->LinePadding(number);
    FUN_00759330 layoutX(*width,*height,count,limit,separator);
    FUN_00a12fb0(SourceValue(source),&layoutX);
    *width=layoutX.GetWidth();
    *height=layoutX.GetHeight();
    int linePosition_2=0;
    int linePositionTmp=0;
    if(mode==4) linePositionTmp=-layoutX.GetCharacterOffset(linePosition_2);
    else if(mode==2) linePositionTmp=-(layoutX.GetCharacterOffset(linePosition_2)/2);
    NiPoint3 position6;
    position6.x=(float)linePositionTmp;
    position6.z=(data->height-fontHeight)*2.0f;
    position6.y=0.0f;
    *primary=CreateTextShape(layoutX.GetGeometryKey(),flags,1);
    NiPoint3 kIter;
    kIter.x=0.0f; kIter.y=position6.y; kIter.z=position6.z;
    (*primary)->SetPosition(kIter);
    if(!HasNoIcons()) {
        *secondary=FUN_00a14da0();
        (*secondary)->SetPosition(kIter);
        MarkGeometry(*secondary);
    }
    float originXVal;
    originXVal = position6.x;
    int drawnCount=0;
    int specialCount_2;
    specialCount_2 = 0;
    unsigned int cur5=0;
    while(layoutX[cur5]) {
        if(layoutX[cur5]==separator) {
            ++linePosition_2;
            position6.x=0.0f;
            if(4 == mode) position6.x=(float)-layoutX.GetCharacterOffset(linePosition_2);
            else if(mode == 2) position6.x=(float)-(layoutX.GetCharacterOffset(linePosition_2)/2);
            position6.z-=data->height+lineB;
        } else if(layoutX[cur5]=='\t') {
            TabAdvance(position6.x);
        }
        letter9=layoutX[cur5];
        NormalizeSmartQuotes(&letter9);
        letterCode7=letter9;
        if(letterCode7>256) letter9=0;
        if(letter9==1) {
            if(GetIconCount()>0) {
                UpdateIconGeometry(specialCount_2++,*secondary,position6);
            }
        } else {
            glyph=&data->letters[letter9];
            BuildGlyphQuad(glyph,drawnCount,*primary,position6,flags);
            ++drawnCount;
        }
        *width=Maximum((int)(position6.x-originXVal),*width);
        ++cur5;
    }
    int res=(*primary)->GetGeometry()->GetActive();
    (*primary)->GetGeometry()->bound.ComputeBoundingSphere((*primary)->GetGeometry()->GetVertices(),res);
    if(*secondary) {
        secondaryActive_2=(*secondary)->GetGeometry()->GetActive();
        (*secondary)->GetGeometry()->bound.ComputeBoundingSphere((*secondary)->GetGeometry()->GetVertices(),secondaryActive_2);
    }
    finalizer.FUN_00a1bfa0(1);
}
}  // namespace fnv_00a12880

struct Pt3_a14650 {
    float x;
    float y;
    float z;
    Pt3_a14650(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

struct Pt2_a14650 {
    float x;
    float y;
    Pt2_a14650(float fX, float fY) { x = fX; y = fY; }
};

inline NiGeometryData* Geo_a14650(NiTriShape* shape) { return shape->m_spGeometryData.m_pObject; }
inline NiPoint3* Verts_a14650(NiGeometryData* data) { return data->m_pkVertex; }
inline NiPoint2* Tex_a14650(NiGeometryData* data) { return data->m_pkTexture; }
inline unsigned short* Tris_a14650(NiGeometryData* data) { return static_cast<NiTriShapeData*>(data)->GetTriangleList(); }

struct FontIcons_a14650 : public Font {
    ButtonIcon& Icon(int index) { return m_kButtonIcons.pBuffer[index]; }
    void UpdateIconGeometry(int index, NiTriShape* shape, NiPoint3& position);
};

// Writes vertex positions, texture coordinates, and triangle indices for a button icon into the shape's geometry data, then advances position.x.
// @fnv 0x00a14650
void FontIcons_a14650::UpdateIconGeometry(int aiIconIndex, NiTriShape* shape, NiPoint3& position)
{
    int baseVertex3 = aiIconIndex * 4;
    float width6 = m_kButtonIcons.pBuffer[aiIconIndex].m_fGlyphWidthInPixels;
    float zPos7 = position.z + m_kButtonIcons.pBuffer[aiIconIndex].m_fGlyphVerticalOffset;
    float xPos = position.x + m_kButtonIcons.pBuffer[aiIconIndex].m_fHorizontalOffset;

    Pt3_a14650* vertices5 = (Pt3_a14650*)(Verts_a14650(Geo_a14650(shape)) + baseVertex3);
    vertices5[0] = Pt3_a14650(xPos, position.y, zPos7);
    vertices5[1] = Pt3_a14650(xPos, position.y, zPos7 - width6);
    vertices5[2] = Pt3_a14650(xPos + width6, position.y, zPos7);
    vertices5[3] = Pt3_a14650(xPos + width6, position.y, zPos7 - width6);

    Pt2_a14650* texCoords2 = (Pt2_a14650*)(Tex_a14650(Geo_a14650(shape)) + baseVertex3);
    texCoords2[0] = Pt2_a14650(Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumV);
    texCoords2[1] = Pt2_a14650(Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumV);
    texCoords2[2] = Pt2_a14650(Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumV);
    texCoords2[3] = Pt2_a14650(Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumV);

    unsigned short* triangles = Tris_a14650(Geo_a14650(shape)) + aiIconIndex * 6;
    triangles[0] = (unsigned short)baseVertex3;
    triangles[1] = (unsigned short)(baseVertex3 + 1);
    triangles[2] = (unsigned short)(baseVertex3 + 2);
    triangles[3] = (unsigned short)(baseVertex3 + 2);
    triangles[4] = (unsigned short)(baseVertex3 + 1);
    triangles[5] = (unsigned short)(baseVertex3 + 3);

    position.x += width6 + m_kButtonIcons.pBuffer[aiIconIndex].m_fHorizontalSpacing;
}

namespace fnv_00a15ee0 {
inline void DeadQ1(){int a[1];}
inline void DeadQ2(){int a[2];}
inline void DeadQ3(){int a[3];}
inline void DeadQ4(){int a[4];}
inline void DeadQ5(){int a[5];}
inline void DeadQ6(){int a[6];}
inline void DeadQ7(){int a[7];}
inline void DeadQ8(){int a[8];}
inline void DeadQ9(){int a[9];}
inline void DeadQ10(){int a[10];}
inline void DeadQ11(){int a[11];}
inline void DeadQ12(){int a[12];}
inline void DeadQ13(){int a[13];}
inline void DeadQ14(){int a[14];}
inline void DeadQ15(){int a[15];}
inline void DeadQ16(){int a[16];}
inline void DeadQ17(){int a[17];}
unsigned int __cdecl strlen(const char*);
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct MemoryManager { void* Allocate(unsigned int); void Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct BSStr {
    char* m_data; unsigned short m_len; unsigned short m_kMaximumCorner;
    bool Set(const char* s, unsigned int n);
    unsigned int Length() { return m_len == 0xffff ? StrLenQ(m_data) : m_len; }
    static unsigned int StrLenQ(const char* s) { return strlen(s); }
    char& At(unsigned int i) { return m_data[m_data ? i : 0]; }
};
__forceinline char* AllocZ(unsigned int count) { unsigned int sz = 1; sz = count * sz; char* p = (char*)g_memoryManager.Allocate(sz); fnv_zlib_memset(p, 0, sz); return p; }
inline void FreeQ(char* p) { g_memoryManager.Deallocate(p); }
struct TxtQ {
    void ExtractLine(BSStr* str, int line);
};
// Copies the text of the given 1-based line from a BSStr into a new buffer, replacing the original string with that line's content.
// @fnv 0x00a15ee0
void TxtQ::ExtractLine(BSStr* str, int line)
{
    int cur = 1;
    int start3 = -1;
    int _end = -1;
    unsigned int len = str->Length();
    unsigned int i;
    for (i = 0; i < len; i++) {
        if (!str->At(i)) break;
        if (cur == line && start3 == -1) start3 = i;
        if (str->At(i) == '\n') cur++;
        if (cur == line + 1 && _end == -1) { _end = i; break; }
    }
    if (start3 == 0 && _end == -1) return;
    if (start3 == -1) { str->Set(" ", 0); return; }
    if (_end == -1) _end = len;
    unsigned int cnt4 = _end - start3;
    char* buf3 = AllocZ(cnt4 + 1);
 DeadQ16();     for (i = 0; i < cnt4; i++) buf3[i] = str->At(i + start3);
    buf3[i] = 0;
    str->Set(" ", 0);
    str->Set(buf3, 0);
    char* del = buf3; g_memoryManager.Deallocate(del);
}
}  // namespace fnv_00a15ee0

namespace fnv_00a17390 {
struct MemoryManager { void* Allocate(unsigned int); };
extern MemoryManager g_memoryManager;
struct LayoutMemory { void Deallocate(void*); };
extern float DAT_01095268;
extern float DAT_01095264;
extern float DAT_01095260;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
inline void* LayoutCopy(void* destination,const void* source,unsigned int size) { return memcpy(destination,source,size); }
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*,const char*);
extern "C" int __cdecl toupper(int);
extern "C" int __cdecl _stricmp(const char*,const char*);
int __cdecl FUN_00408b20(const char*,const char*);
long __cdecl FUN_00eca6d3(const char*);
extern "C" int __cdecl sscanf(const char*,const char*,...);
extern "C" void* __cdecl fnv_zlib_memset(void*,int,unsigned int);
struct LayoutString {
    char* text; unsigned short length, capacity;
    LayoutString() { text=0; SetLength(0); SetMaxLength(0); }
    LayoutString& operator=(const char* source) { Set(source,0); return *this; }
    LayoutString& operator=(const LayoutString& other) { Set(other); return *this; }
    ~LayoutString() { Set(0,0); }
    LayoutString& Clear() { Set(0,0); return *this; }
    unsigned int MaxLength() const { return capacity; }
    void SetMaxLength(unsigned int n) { capacity=n<=0xffff?(unsigned short)n:0xffff; }
    void SetLength(unsigned int n) { length=n<=0xffff?(unsigned short)n:0xffff; }
    bool Set(const char* source, unsigned int minimum) {
        unsigned int size=source?LayoutLength(source):0;
        unsigned int maximum=LayoutCapacity(size,minimum);
        if(maximum<=MaxLength()) {
            if(maximum) { if(source) LayoutCopy(text,source,size+1); else text[0]=0; }
            else {
                if(text) delete text;
                text=0; maximum=0; SetMaxLength(maximum);
            }
        } else {
            char* old=text;
            text=new char[maximum+1];
            if(source) LayoutCopy(text,source,size+1); else text[0]=0;
            if(old) delete old;
            SetMaxLength(maximum);
        }
        SetLength(size);
        return size!=0;
    }
    bool Set(const LayoutString& other) {
        unsigned int size=other.Length();
        if(size<=MaxLength()) {
            if(size) LayoutCopy(text,other.Get(),size+1);
            else {
                if(text) delete text;
                text=0; size=0; SetMaxLength(size);
            }
        } else {
            char* old=text;
            text=new char[size+1];
            LayoutCopy(text,other.Get(),size+1);
            if(old) delete old;
            SetMaxLength(size);
        }
        SetLength(size);
        return size!=0;
    }
    char& operator[](unsigned int index) const { return text[text ? index : 0]; }
    char* Get() const { return text; }
    bool Empty() const { return !Get() || !(*this)[0]; }
    unsigned int Length() const { return length==0xffff ? strlen(Get()) : length; }
    unsigned int Size() const { return Length()+1; }
    int StrCmp(const char* other, bool ignoreCase) const {
        int result;
        if(other && Get()) result=ignoreCase ? _stricmp(Get(),other) : FUN_00408b20(Get(),other);
        else if(!other && !Get()) result=0;
        else result=(other==0)*2-1;
        return result;
    }
    bool operator==(const char* other) const { return !StrCmp(other,true); }
    LayoutString& operator+=(const LayoutString& other) {
        if(other.Get()) {
            if(Get()) {
                unsigned int total=Length()+other.Length();
                if(total>MaxLength()) Set(Get(),total);
                LayoutCopy(text+Length(),other.Get(),other.Size());
                SetLength(total);
            } else Set(other);
        }
        return *this;
    }
};
struct LayoutColor { float r,g,b,a; LayoutColor() : r(0),g(0),b(0),a(0) {} LayoutColor(const float& x,const float& y,const float& z,float w) : r(x),g(y),b(z),a(w) {} LayoutColor(int red,int green,int blue) : r(red/255.0),g(green/255.0),b(blue/255.0),a(1.0f) {} };
struct GlyphData { float height; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124; FontCharacterInfo glyphs[256]; };
struct LayoutFont : Font {
    float GetDrop() { return m_fDrop; }
};
struct LayoutFonts : FontManager {
    static LayoutFonts* Instance() { return (LayoutFonts*)pInstance; }
    LayoutFont* GetFont(int index) { return (LayoutFont*)pFont[index]; }
};
template<class T> inline T LayoutLower(T a,T b) { return a<b?a:b; }
template<class T> inline T LayoutUpper(T a,T b) { return a<b?b:a; }
struct LayoutItem {
    int font; unsigned char character; unsigned char unk05; unsigned short unk06;
    LayoutColor color; int unk18;
    LayoutString string;
    int width,height,depth,offset,position;
    LayoutItem(int fontIndex, unsigned char value, LayoutColor newColor, int flags) {
        font=LayoutUpper(LayoutLower(fontIndex,8),0);
        character=value;
        color=newColor;
        unk18=flags;
        string.Set(0,0);
        FontCharacterInfo* letter=&((GlyphData*)LayoutFonts::Instance()->GetFont(font)->m_pFontData)->glyphs[character];
        width=(int)(letter->m_fGlyphWidthInPixels+letter->m_fGlyphWidthInPixels!=0.0?letter->m_fHorizontalAdvance+letter->m_fHorizontalSpacing:0.0);
        height=(int)((GlyphData*)LayoutFonts::Instance()->GetFont(font)->m_pFontData)->height;
        depth=(int)(letter->m_fGlyphExtent-letter->m_fVerticalOffset);
        offset=0;
        position=0;
    }
    void FUN_00a1b7f0(unsigned char value) {
        character=value;
        if(Empty()) {
            FontCharacterInfo* letter=&((GlyphData*)LayoutFonts::Instance()->GetFont(font)->m_pFontData)->glyphs[character];
            width=(int)(letter->m_fGlyphWidthInPixels+(letter->m_fGlyphWidthInPixels!=0.0?letter->m_fHorizontalSpacing+letter->m_fHorizontalAdvance:0.0));
            height=(int)((GlyphData*)LayoutFonts::Instance()->GetFont(font)->m_pFontData)->height;
            depth=(int)-LayoutFonts::Instance()->GetFont(font)->GetDrop();
            offset=0;
        }
        position=0;
    }
    void SetFont(int index) { font=index; FUN_00a1b7f0(character); }
    LayoutItem* Clone() {
        LayoutItem* item=new LayoutItem(font,character,color,unk18);
        item->string=string;
        item->width=width;
        item->height=height;
        item->depth=depth;
        item->position=position;
        item->offset=0;
        return item;
    }
    void FUN_00a1b770() {
        font=0;
        color=LayoutColor(DAT_01095268,DAT_01095264,DAT_01095260,1.0f);
        unk18=1;
        string.Clear();
        FUN_00a1b7f0(0x20);
    }
    bool Empty() const { return !string.Get() || !string[0]; }
    ~LayoutItem() {}
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
};
struct LayoutLine { void* head; void* tail; int count,width,unk10,height,depth,unk1c; };
struct LayoutLineNode { LayoutLineNode* next; LayoutLineNode* prev; LayoutLine* line; };
struct LayoutPage {
    LayoutLineNode* head; LayoutLineNode* tail; int count;
    int Count() const { return count; }
    LayoutLineNode* Head() const { return head; }
    LayoutLine*& Next(LayoutLineNode*& node) const { LayoutLine** line=&node->line; node=node->next; return *line; }
};
struct FUN_00a1b940 {
    void* head; void* tail; int count;
    FUN_00a1b940();
    int Count() const { return count; }
};
struct LayoutBlock : FUN_00a1b940 {
    int width,height,unk14;
    LayoutBlock(int newWidth,int newHeight,int newUnk14) { width=newWidth; height=newHeight; unk14=newUnk14; }
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
    void FUN_00a19a10(LayoutItem*,int,bool);
    LayoutPage* GetValueAtCount();
};
struct LayoutResult {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
    int width,height,unk24,unk28,pages,lines;
    bool hasLayout;
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    int GetUnk24() const { return unk24; }
};
inline int LayoutMax(int a,int b) { return a>b?a:b; }
inline int LayoutMin(int a,int b) { return a<b?a:b; }
__forceinline char* AllocateText(unsigned int count) {
    unsigned int size=1;
    size*=count;
    char* text=(char*)g_memoryManager.Allocate(size);
    fnv_zlib_memset(text,0,size);
    return text;
}
struct FUN_00a16da0_shell : FontManager { int GetCharClassFlags(char); };
struct FUN_00a17390_shell : FUN_00a16da0_shell {
    Font* GetFont(unsigned int number) { return pFont[number]; }
    const char* GetFontFile(unsigned int number) { return GetFont(number)->m_pFile; }
    LayoutString FUN_00a16ea0(const char* input, int* index, unsigned int stopMask, unsigned int allowedMask, unsigned int* outFlags, char* currentChar, bool parseEntities);
    LayoutBlock* ParseLayout(LayoutString& source, LayoutResult* result);
};
inline ButtonIcon& GetIcon(Font* font, unsigned int index) { return font->m_kButtonIcons.pBuffer[index]; }
// Parses HTML-like markup from source into a LayoutBlock, tracking font, color, alignment, and image attributes, then updates result dimensions.
// @fnv 0x00a17390
LayoutBlock* FUN_00a17390_shell::ParseLayout(LayoutString& source, LayoutResult* result) {
    bool layout=false;
    char* input=AllocateText(source.Length()+1);
    strcpy(input,source.Get());
    int parsePos=0;
    unsigned int mask=0;
    char character=0;
    LayoutString word;
    LayoutString tagText;
    LayoutString paramName;
    LayoutString attributeValue;
    LayoutString output;
    LayoutItem format(0,' ',LayoutColor(DAT_01095268,DAT_01095264,DAT_01095260,1.0f),1);
    bool img=false;
    int lines=0;
    bool lineRule=false;
    LayoutBlock* block=0;
    unsigned int iconNum=0;
    FUN_00a16ea0(input,&parsePos,0,4,&mask,&character,false);
    if(mask==1) {
        block=new LayoutBlock(result->GetWidth(),result->GetHeight(),result->GetUnk24());
        layout=true;
        parsePos=0;
        while(true) {
            word=FUN_00a16ea0(input,&parsePos,1,0,&mask,&character,true);
            if(word.Get()) {
                if(img) {
                    img=false;
                    format.character=0;
                    block->FUN_00a19a10(format.Clone(),lines,lineRule);
                    lines=0;
                    lineRule=false;
                    format.string="";
                }
                output+=word;
                for(unsigned int i=0;i<word.Length();++i) {
                    format.FUN_00a1b7f0(word[i]);
                    if(format.character==1) {
                        format.width=(int)(GetIcon(GetFont(0),iconNum).m_fGlyphWidthInPixels+GetFont(0)->m_kButtonIcons.pBuffer[iconNum].m_fHorizontalSpacing);
                        ++iconNum;
                    }
                    block->FUN_00a19a10(format.Clone(),lines,lineRule);
                    lines=0;
                    lineRule=false;
                }
            }
            if(mask&0x20) break;
            tagText=FUN_00a16ea0(input,&parsePos,6,0,&mask,&character,true);
            for(unsigned int i=0;i<tagText.Length();++i) tagText[i]=toupper(tagText[i]);
            if(mask&0x20) break;
            if(mask&4) {
                while(true) {
                    FUN_00a16ea0(input,&parsePos,0,4,&mask,&character,false);
                    if(mask&0x20 || mask&2) break;
                    paramName=FUN_00a16ea0(input,&parsePos,0x16,0,&mask,&character,true);
                    for(unsigned int i=0;i<paramName.Length();++i) paramName[i]=toupper(paramName[i]);
                    if(mask&0x20 || mask&2) break;
                    if(mask&4) attributeValue="true";
                    else {
                        FUN_00a16ea0(input,&parsePos,0,4,&mask,&character,false);
                        if(mask&0x20 || mask&2) break;
                        if(mask==8) {
                            ++parsePos;
                            attributeValue=FUN_00a16ea0(input,&parsePos,0xa,0,&mask,&character,true);
                            character=input[parsePos];
                            ++parsePos;
                            mask=GetCharClassFlags(character);
                        } else {
                            attributeValue=FUN_00a16ea0(input,&parsePos,6,0,&mask,&character,true);
                            for(unsigned int i=0;i<attributeValue.Length();++i) attributeValue[i]=toupper(attributeValue[i]);
                        }
                    }
                    if(tagText=="IMG") {
                        img=true;
                        if(paramName=="SRC") format.string=attributeValue;
                        else if(paramName=="WIDTH") sscanf(attributeValue.Get(),"%i",&format.width);
                        else if(paramName=="HEIGHT") { sscanf(attributeValue.Get(),"%i",&format.height); format.depth=0; }
                    } else if(img) {
                        img=false;
                        format.character=0;
                        block->FUN_00a19a10(format.Clone(),lines,lineRule);
                        lines=0;
                        lineRule=false;
                        format.string="";
                    }
                    if(tagText=="DIV") {
                        ++lines;
                        if(paramName=="ALIGN") {
                            if(attributeValue=="LEFT") format.unk18=1;
                            else if(attributeValue=="CENTER") format.unk18=2;
                            else if(attributeValue=="RIGHT") format.unk18=4;
                        }
                    } else if(tagText=="FONT") {
                        if(paramName=="FACE") {
                            for(int number=0;number<8;++number) {
                                bool found=false;
                                if(!_stricmp(attributeValue.Get(),GetFontFile(number))) found=true;
                                else if(number+1==FUN_00eca6d3(attributeValue.Get())) found=true;
                                if(found) {
                                    format.SetFont(number);
                                    break;
                                }
                            }
                        }
                        if(paramName=="COLOR" && attributeValue.Length()==6) {
                            LayoutColor color;
                            int r=(toupper(attributeValue[0])>='A'?toupper(attributeValue[0])-('A'-10):toupper(attributeValue[0])-'0')<<4;
                            r+=toupper(attributeValue[1])>='A'?toupper(attributeValue[1])-('A'-10):toupper(attributeValue[1])-'0';
                            r=LayoutMin(LayoutMax(r,0),255);
                            int g=(toupper(attributeValue[2])>='A'?toupper(attributeValue[2])-('A'-10):toupper(attributeValue[2])-'0')<<4;
                            g+=toupper(attributeValue[3])>='A'?toupper(attributeValue[3])-('A'-10):toupper(attributeValue[3])-'0';
                            g=LayoutMin(LayoutMax(g,0),255);
                            int b=(toupper(attributeValue[4])>='A'?toupper(attributeValue[4])-('A'-10):toupper(attributeValue[4])-'0')<<4;
                            b+=toupper(attributeValue[5])>='A'?toupper(attributeValue[5])-('A'-10):toupper(attributeValue[5])-'0';
                            b=LayoutMin(LayoutMax(b,0),255);
                            color=LayoutColor(r,g,b);
                            format.color=color;
                        }
                    }
                    if(mask&0x20 || mask&2) break;
                }
            }
            if(tagText=="BR") ++lines;
            else if(tagText=="P") lines+=2;
            else if(tagText=="HR") {
                if(result->height==0x7fffffff) lines+=2;
                else { lineRule=true; lines=0; }
            } else if(tagText=="/FONT") format.FUN_00a1b770();
        }
        source=output;
    }
    ((LayoutMemory*)&g_memoryManager)->Deallocate(input);
    if(block) {
        result->hasLayout=true;
        result->pages=block->Count();
        LayoutPage* page=block->GetValueAtCount();
        if(page) {
            result->height=0;
            result->width=0;
            LayoutLineNode* node=page->Head();
            while(node) {
                LayoutLine* line=page->Next(node);
                result->height+=line->height+line->unk1c;
                result->width=LayoutMax(result->width,line->width);
            }
            result->lines=page->Count();
        }
    }
    return block;
}
}  // namespace fnv_00a17390

namespace fnv_00a18f00 {
struct PoolQ { void FUN_00aa4060(void* p); };
extern PoolQ DAT_011f6238;
struct StrQ {
  char* p; unsigned short l, m;
  StrQ(const StrQ& o) { AssignFromString(o); }
  void AssignFromString(const StrQ& o);
  void FUN_004037f0(const char* s, unsigned short n);
  ~StrQ() { FUN_004037f0(0, 0); }
};
struct FUN_00a1b990 {
  ~FUN_00a1b990();
  void BuildPage(int a, int b);
  void operator delete(void* p) { int aiD[21]; DAT_011f6238.FUN_00aa4060(p); }
};
struct OwnQ {
  FUN_00a1b990* CreateTextRunNode(StrQ* s, int a);
  bool CreateTextRun(StrQ s, int a, int b);
};
// Creates a text run node from the string s and parameter a, applies b and a via BuildPage, then deletes the node and returns true.
// @fnv 0x00a18f00
bool OwnQ::CreateTextRun(StrQ asText, int a, int b) {
  FUN_00a1b990* pNode;
  StrQ kName_ydzun(asText);
  pNode = CreateTextRunNode(&kName_ydzun, a);
  if (pNode) pNode->BuildPage(b, a);
  delete pNode;
  return true;
}
}  // namespace fnv_00a18f00

namespace fnv_00a19a10 {
struct PoolQ { void* FUN_00aa3e40(unsigned int n); };
extern PoolQ DAT_011f6238;
struct OwnQ;
struct EntQ {
  int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
  EntQ* FUN_00a19c00(int a, int b);
  void* operator new(unsigned int n) { int aiD[9]; return DAT_011f6238.FUN_00aa3e40(n); }
  void operator delete(void* p);
};
struct FUN_00a1bc70 : EntQ { FUN_00a1bc70(OwnQ* pOwner, int a, int c, int d); };
struct HeadQ { int unk00, unk04; EntQ* pEnt; };
struct OwnQ {
  int unk00; HeadQ* pHead; unsigned int ItemUpdateArray; int unk0c, unk10;
  unsigned int GetCount() { return ItemUpdateArray; }
  EntQ*& First() { return pHead->pEnt; }
  void AddItem(EntQ** ppEnt);
  void FUN_00a19a10(int a, int b, bool bForce);
};
// Calls FUN_00a19c00 on First() when the count is nonzero and bForce is false; otherwise allocates FUN_00a1bc70, then passes a non-null result to AddItem.
// @fnv 0x00a19a10
void OwnQ::FUN_00a19a10(int aiParam1, int aiParam2, bool bForce) {
  EntQ* pEnt = 0;
  if (GetCount() && !bForce)
    pEnt = First()->FUN_00a19c00(aiParam1, aiParam2);
  else
    pEnt = new FUN_00a1bc70(this, aiParam1, unk0c, unk10);
  if (pEnt) AddItem(&pEnt);
}
}  // namespace fnv_00a19a10

struct StrQ {
  char* m_p;
  char* Get() { return m_p; }
  char& At(unsigned int i) { return m_p[m_p ? i : 0]; }
};
struct ObjQ { int iKey; int unk04, unk08, unk0c, unk10, unk14, unk18; StrQ kName;
  bool NameEmpty() { return !kName.Get() || !kName.At(0); } };
template <class T> struct NodQ { NodQ* pNext; int unk04; T kData; };
template <class T> struct LstQ {
  NodQ<T>* pHead;
  NodQ<T>* Head() { return pHead; }
};
template <class T> inline T& NextQ(NodQ<T>*& pNode) { T& r = pNode->kData; pNode = pNode->pNext; return r; }
struct BktQ { LstQ<ObjQ*> kList; };
struct MapQ {
  LstQ<BktQ*> kBuckets;
  int CountEmptyNameEntries(int iKey);
};
// Counts ObjQ entries with empty names and matching iKey across all buckets in kBuckets.
// @fnv 0x00a19b00
int MapQ::CountEmptyNameEntries(int iKey) {
  int iCount_sia = 0;
  NodQ<BktQ*>* pOuter_bk = kBuckets.Head();
  while (pOuter_bk) {
    BktQ* pBkt = NextQ(pOuter_bk);
    if (pBkt) {
      NodQ<ObjQ*>* pInner = pBkt->kList.Head();
      while (pInner) {
        ObjQ* pObj = NextQ(pInner);
        if (pObj && pObj->NameEmpty() && pObj->iKey == iKey)
          iCount_sia++;
      }
    }
  }
  return iCount_sia;
}

// 0x00a1b450  /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1
// thiscall, 7 stack args (ret 0x1c): constructor.
extern "C" void** DAT_011f33f8;

struct Rec00a1b450 {
    int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
};

struct Blob00a1b450 {
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
    char* p38;
};

struct Vec400a1b450 {
    float x, y, z, w;
    Vec400a1b450() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
    void Set(float a, float b, float c, float d) { x=a; y=b; z=c; w=d; }
};

struct StrMem {
    unsigned int m0;
    unsigned short m4;
    unsigned short m6;
    StrMem(unsigned int v = 0) {
        m0 = 0;
        m4 = (v <= 0xffff ? (unsigned short)v : 0xffff);
        m6 = (v <= 0xffff ? (unsigned short)v : 0xffff);
    }
    void Clear() { Set(0,0); }
    ~StrMem();
    bool Set(const char* s, unsigned int n);
};

inline bool Empty00a1b450(StrMem* target) { StrMem* text = target; return text->Set(0,0); }
inline Blob00a1b450* GetFont00a1b450(int index) { void** mgr = DAT_011f33f8; Blob00a1b450* blob = (Blob00a1b450*)mgr[index]; return blob; }
inline int GetHeight00a1b450(int index) { void** mgr = DAT_011f33f8; Blob00a1b450* blob = (Blob00a1b450*)mgr[index]; return (int)*(float*)blob->p38; }

inline int LowerBound00a1b450(int t, int lower) { return t < lower ? lower : t; }

struct FUN_00a1b450 {
    int m0;
    unsigned char m4;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    Vec400a1b450 m8;
    int m18;
    StrMem m1c;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;

    FUN_00a1b450(int a, unsigned char flag, Vec400a1b450 value, int extra);
};

// Initialises a glyph record from a font index and flag, computing advance, height and offset from the font blob data.
// @fnv 0x00a1b450
FUN_00a1b450::FUN_00a1b450(int aiFontIndex, unsigned char flag, Vec400a1b450 av4Value, int extra)
    : m8(), m1c() {
    m0 = LowerBound00a1b450(aiFontIndex < 8 ? aiFontIndex : 8, 0);

    m4 = flag;

    m8 = av4Value;
    m18 = extra;

    Empty00a1b450(&m1c);

    Rec00a1b450* pGlyphRecord = (Rec00a1b450*)(GetFont00a1b450(m0)->p38 + 0x128) + m4;

    m24 = (int)(((pGlyphRecord->f24 + pGlyphRecord->f24) != 0.0) ? (double)(pGlyphRecord->f2c + pGlyphRecord->f30) : 0.0);

    m28 = (int)GetHeight00a1b450(m0);

    m2c = (int)(pGlyphRecord->f28 - pGlyphRecord->f34);

    m30 = 0;
    m34 = 0;
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
inline void* LayoutCopy(void* destination,const void* source,unsigned int size) {return memcpy(destination,source,size);}
namespace TextLayout {
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*,const char*);
extern "C" int __cdecl FUN_00ec65a6(char*,unsigned int,const char*);
extern "C" int __cdecl sprintf(char*,const char*,...);
extern "C" void* __cdecl FUN_00ec61c0(void*,int,unsigned int);
extern "C" void* __cdecl FUN_00ec7230(void*,const void*,unsigned int);
bool __cdecl FUN_007070c0(const char*,char*,unsigned int,bool);
bool __cdecl ResolveSettingString(const char*,char*);
void __cdecl FUN_00406d00(char*,unsigned int,const char*,...);
void __cdecl NormalizeSmartQuotes(unsigned char*);
extern char DAT_01019f08[],DAT_010950a8[];
struct Memory {
 void* FUN_00aa3e40(unsigned int);
 void* FUN_00aa4150(void*,unsigned int);
 void FUN_00aa4060(void*);
};
extern Memory DAT_011f6238;
__forceinline char* AllocateText(unsigned int count) {
 unsigned int size=1;
 size*=count;
 char* text=(char*)DAT_011f6238.FUN_00aa3e40(size);
 FUN_00ec61c0(text,0,size);
 return text;
}
struct Manager { float FUN_00a1b3a0(int); };
extern Manager* DAT_011f33f8;
inline Manager* GetDebrisManager() { return DAT_011f33f8; }
struct Glyph {
 int texture;
 float uv[4][2];
 float width,height,leading,spacing,top;
};
struct FontData {
 float lineHeight;
 int unk004;
 int unk008;
 int unk00c;
 int unk010;
 int unk014;
 int unk018;
 int unk01c;
 int unk020;
 int unk024;
 int unk028;
 int unk02c;
 int unk030;
 int unk034;
 int unk038;
 int unk03c;
 int unk040;
 int unk044;
 int unk048;
 int unk04c;
 int unk050;
 int unk054;
 int unk058;
 int unk05c;
 int unk060;
 int unk064;
 int unk068;
 int unk06c;
 int unk070;
 int unk074;
 int unk078;
 int unk07c;
 int unk080;
 int unk084;
 int unk088;
 int unk08c;
 int unk090;
 int unk094;
 int unk098;
 int unk09c;
 int unk0a0;
 int unk0a4;
 int unk0a8;
 int unk0ac;
 int unk0b0;
 int unk0b4;
 int unk0b8;
 int unk0bc;
 int unk0c0;
 int unk0c4;
 int unk0c8;
 int unk0cc;
 int unk0d0;
 int unk0d4;
 int unk0d8;
 int unk0dc;
 int unk0e0;
 int unk0e4;
 int unk0e8;
 int unk0ec;
 int unk0f0;
 int unk0f4;
 int unk0f8;
 int unk0fc;
 int unk100;
 int unk104;
 int unk108;
 int unk10c;
 int unk110;
 int unk114;
 int unk118;
 int unk11c;
 int unk120;
 int unk124;
 Glyph glyphs[256];
};
struct Rect {
 float left,right,top,bottom;
 Rect(){left=0.0f;right=0.0f;top=0.0f;bottom=0.0f;}
};
struct Icon { float width,m_fVerticalExtent,zOffset,spacing; Rect uv; };
struct ListNode {
 int value;
 ListNode* next;
 ListNode(const int& item) : value(item), next(0) {}
 static void* operator new(unsigned int size) { return DAT_011f6238.FUN_00aa3e40(size); }
 void FUN_00af25b0(int* item) {
  if (!*item) return;
  ListNode* tail = this;
  while (tail->next) tail = tail->next;
  if (tail->value) {
   tail->next = new ListNode(*item);
  } else tail->value = *item;
 }
};
struct Layout {
 char* text;
 unsigned short length,capacity;
 int width,height;
 unsigned int firstLine;
 int maxLines;
 unsigned int characters;
 char newline;
 ListNode lines;
 unsigned int MaxLength() const {return capacity;}
 void SetMaxLength(unsigned int n) {capacity=n<=0xffff?(unsigned short)n:0xffff;}
 void SetLength(unsigned int n) {length=n<=0xffff?(unsigned short)n:0xffff;}
 bool FUN_004037f0(const char* source,unsigned int minimum) {
  unsigned int size=source?LayoutLength(source):0;
  unsigned int maximum=LayoutCapacity(size,minimum);
  if(maximum<=MaxLength()) {
   if(maximum) {if(source) LayoutCopy(text,source,size+1);else text[0]=0;}
   else {if(text) delete text; text=0;maximum=0;SetMaxLength(maximum);}
  } else {
   char* old=text;
   text=new char[maximum+1];
   if(source) LayoutCopy(text,source,size+1); else text[0]=0;
   if(old) delete old;
   SetMaxLength(maximum);
  }
  SetLength(size);
  return size!=0;
 }
};
struct Font {
 unsigned short refs;
 char* file;
 int number;
 void* textures[8];
 float height,drop;
 int overlap;
 FontData* data;
 char* atlas;
 unsigned short sheetLength,sheetCapacity;
 void** iconVtable;
 Icon* icons;
 unsigned int iconCount,iconCapacity;
 inline unsigned int GetIconCount() { return iconCount; }
 void LoadIconFromPath(const char*);
 void FUN_00a12fb0(const char*,Layout*);
};
// @fnv 0x00a12fb0
void Font::FUN_00a12fb0(const char* input,Layout* layout) {
 if(!input) return;
 if(layout->width<=0) layout->width=0x7fffffff;
 if(layout->height<=0) layout->height=0x7fffffff;
 if(layout->maxLines<=0) layout->maxLines=0x7fffffff;
 float paddingSlot16=GetDebrisManager()->FUN_00a1b3a0(number);
 int breakOffsetSlot0=0;
 int breakWidthSlot43=0;
 int wordWidthSlot2=0;
 int widthSlot1=0;
 int maxWidthSlot29=0;
 float heightSlot31=data->glyphs[32].height;
 int lineCountSlot0=1;
 unsigned int length=strlen(input);
 int maxLinesSlot10=layout->maxLines;
 char* workSlot77=AllocateText(length+4);
 char* outputSlot60=AllocateText(length+4);
 sprintf(workSlot77,DAT_01019f08,input);
 unsigned int outputLengthSlot0=0;
 unsigned int capacity=length+4;
 int insertedSlot12=0;
 bool hyphenSlot42=false;
 char replacementSlot0[1024];replacementSlot0[0]=0;
 bool replacedSlot17=false;
 for(unsigned int scan=0;scan<length;++scan) {
  if(workSlot77[scan]=='&') {
   char entitySlot1[128];
   int countSlot0=0;
   int prefixSlot10=1;
   bool positiveSlot0=true;
   if(workSlot77[scan+1]=='-') { positiveSlot0=false;prefixSlot10=2; }
   while(workSlot77[scan+countSlot0+prefixSlot10] && countSlot0<127 && workSlot77[scan+countSlot0]!=';' && workSlot77[scan+countSlot0]!='\n' && workSlot77[scan+countSlot0]!=layout->newline) {
    entitySlot1[countSlot0]=workSlot77[scan+countSlot0+prefixSlot10];++countSlot0;
   }
   entitySlot1[countSlot0?countSlot0-prefixSlot10:countSlot0]=0;
   unsigned int consumed=strlen(entitySlot1)+1;
   if(workSlot77[scan+countSlot0]==';') consumed+=prefixSlot10;
   if(FUN_007070c0(entitySlot1,replacementSlot0,1024,positiveSlot0) || ResolveSettingString(entitySlot1,replacementSlot0)) {
    unsigned int replacementLengthSlot18=strlen(replacementSlot0);
    int deltaSlot0=replacementLengthSlot18-consumed;
    if(replacementSlot0[replacementLengthSlot18-1]=='\\') {
     Icon rectSlot1;
     int slashSlot0=0;
     while(replacementSlot0[slashSlot0]!='\\') ++slashSlot0;
     char pathSlot13[260];pathSlot13[0]=0;
     strcpy(pathSlot13,&replacementSlot0[slashSlot0+1]);
     pathSlot13[strlen(pathSlot13)-1]=0;
     if(number==7) {
      char originalPath[260];
      FUN_00ec65a6(originalPath,260,pathSlot13);
      FUN_00406d00(pathSlot13,260,DAT_010950a8,originalPath);
     }
     LoadIconFromPath(pathSlot13);
     replacementSlot0[slashSlot0]=1;replacementSlot0[slashSlot0+1]=0;
     replacementLengthSlot18=strlen(replacementSlot0);
     deltaSlot0=replacementLengthSlot18-consumed;
    }
    if(deltaSlot0>0) {capacity+=deltaSlot0;outputSlot60=(char*)DAT_011f6238.FUN_00aa4150(outputSlot60,capacity);}
    for(unsigned int copyIndex=0;copyIndex<replacementLengthSlot18;++copyIndex) {
     outputSlot60[outputLengthSlot0]=replacementSlot0[copyIndex];++outputLengthSlot0;
    }
    scan=scan+consumed-1;
   } else { outputSlot60[outputLengthSlot0]=workSlot77[scan];++outputLengthSlot0; }
   replacedSlot17=true;
  } else { outputSlot60[outputLengthSlot0]=workSlot77[scan];++outputLengthSlot0; }
 }
 outputSlot60[outputLengthSlot0]=0;
 if(replacedSlot17) {
  length=outputLengthSlot0;
  workSlot77=(char*)DAT_011f6238.FUN_00aa4150(workSlot77,length+4);
  strcpy(workSlot77,outputSlot60);
 }
 outputSlot60[0]=0;outputLengthSlot0=0;
 unsigned int imageIndexSlot13=0;
 for(unsigned int index=0;index<length;++index) {
  if(!workSlot77[index]) { break; }
  else if(workSlot77[index]==layout->newline) {
   outputSlot60[outputLengthSlot0]=layout->newline;++outputLengthSlot0;
   if(outputLengthSlot0>=capacity) {outputSlot60=(char*)DAT_011f6238.FUN_00aa4150(outputSlot60,outputLengthSlot0+4);capacity=outputLengthSlot0+4;}
   heightSlot31=data->lineHeight+paddingSlot16+heightSlot31;
   layout->lines.FUN_00af25b0(&widthSlot1);
   maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
   widthSlot1=0;breakOffsetSlot0=0;++lineCountSlot0;
  } else if(workSlot77[index]=='\t') {
   widthSlot1+=75-widthSlot1%75;continue;
  } else {
   unsigned char characterSlot0=workSlot77[index];
   NormalizeSmartQuotes(&characterSlot0);
   Glyph* glyphSlot1=&data->glyphs[characterSlot0];
   if(characterSlot0==1) {
    if(imageIndexSlot13<GetIconCount()) {
     glyphSlot1->width=icons[imageIndexSlot13].width;
     glyphSlot1->spacing=icons[imageIndexSlot13].spacing;
    }
    ++imageIndexSlot13;
   }
   widthSlot1+=(int)(glyphSlot1->width+glyphSlot1->spacing);
   if(characterSlot0==' ') {
    breakOffsetSlot0=outputLengthSlot0;
    breakWidthSlot43=widthSlot1-(int)(glyphSlot1->width+glyphSlot1->spacing);
    wordWidthSlot2=widthSlot1;hyphenSlot42=false;
   } else if(characterSlot0=='~') {
    breakOffsetSlot0=outputLengthSlot0;breakWidthSlot43=widthSlot1;wordWidthSlot2=widthSlot1;hyphenSlot42=true;
    widthSlot1-=(int)(glyphSlot1->width+glyphSlot1->spacing);
   }
   if(widthSlot1>layout->width) {
    if(breakOffsetSlot0) {
     if(hyphenSlot42) {
      hyphenSlot42=false;
      capacity+=4;outputSlot60=(char*)DAT_011f6238.FUN_00aa4150(outputSlot60,capacity);
      FUN_00ec7230(&outputSlot60[breakOffsetSlot0+2],&outputSlot60[breakOffsetSlot0],outputLengthSlot0-breakOffsetSlot0);
      outputSlot60[breakOffsetSlot0+1]='\n';outputSlot60[breakOffsetSlot0]='-';
      outputLengthSlot0+=2;insertedSlot12+=2;
      glyphSlot1=&data->glyphs[45];
      heightSlot31=data->lineHeight+paddingSlot16+heightSlot31;
      widthSlot1-=(int)(glyphSlot1->width+glyphSlot1->spacing);
      layout->lines.FUN_00af25b0(&widthSlot1);
      maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
      breakOffsetSlot0=0;++lineCountSlot0;
      glyphSlot1=&data->glyphs[outputSlot60[breakOffsetSlot0-1]];
      widthSlot1=(int)(glyphSlot1->width+glyphSlot1->spacing);
      glyphSlot1=&data->glyphs[characterSlot0];
      widthSlot1+=(int)(glyphSlot1->width+glyphSlot1->spacing);
     } else {
      if(breakOffsetSlot0==outputLengthSlot0) characterSlot0=layout->newline;
      else outputSlot60[breakOffsetSlot0]=layout->newline;
      heightSlot31=data->lineHeight+paddingSlot16+heightSlot31;
      layout->lines.FUN_00af25b0(&breakWidthSlot43);
      maxWidthSlot29=maxWidthSlot29>breakWidthSlot43?maxWidthSlot29:breakWidthSlot43;
      breakOffsetSlot0=0;++lineCountSlot0;widthSlot1-=wordWidthSlot2;
     }
    } else {
     if(outputLengthSlot0+3>=capacity) {outputSlot60=(char*)DAT_011f6238.FUN_00aa4150(outputSlot60,outputLengthSlot0+6);capacity=outputLengthSlot0+6;}
     outputSlot60[outputLengthSlot0+2]=outputSlot60[outputLengthSlot0];
     outputSlot60[outputLengthSlot0+1]=outputSlot60[outputLengthSlot0-1];
     outputSlot60[outputLengthSlot0]='\n';outputSlot60[outputLengthSlot0-1]='-';
     outputLengthSlot0+=2;insertedSlot12+=2;
     glyphSlot1=&data->glyphs[45];
     heightSlot31=data->lineHeight+paddingSlot16+heightSlot31;
     widthSlot1-=(int)(glyphSlot1->width+glyphSlot1->spacing);
     layout->lines.FUN_00af25b0(&widthSlot1);
     maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
     breakOffsetSlot0=0;++lineCountSlot0;
     glyphSlot1=&data->glyphs[outputSlot60[outputLengthSlot0-1]];
     widthSlot1=(int)(glyphSlot1->width+glyphSlot1->spacing);
     glyphSlot1=&data->glyphs[characterSlot0];
     widthSlot1+=(int)(glyphSlot1->width+glyphSlot1->spacing);
    }
   }
   if(characterSlot0!='~') {outputSlot60[outputLengthSlot0]=characterSlot0;++outputLengthSlot0;}
   if(outputLengthSlot0>=capacity) {outputSlot60=(char*)DAT_011f6238.FUN_00aa4150(outputSlot60,outputLengthSlot0+4);capacity=outputLengthSlot0+4;}
  }
  if(maxLinesSlot10>0 && lineCountSlot0>maxLinesSlot10 && outputLengthSlot0>0) {
   while(outputSlot60[outputLengthSlot0]!=layout->newline) --outputLengthSlot0;
   outputSlot60[outputLengthSlot0]=0;
   heightSlot31-=data->lineHeight+paddingSlot16;break;
  }
 }
 if(outputSlot60[0] && layout->firstLine) {
  unsigned int copiedSlot1=0;
  unsigned int index=0;
  unsigned int lineSlot0=0;
  for(index=0;index<outputLengthSlot0;++index) {
   if(lineSlot0>=layout->firstLine && lineSlot0<(unsigned int)layout->maxLines) {
    outputSlot60[copiedSlot1]=outputSlot60[index];++copiedSlot1;
   }
   if(outputSlot60[index]=='\n')++lineSlot0;
  }
  outputSlot60[copiedSlot1]=0;outputLengthSlot0=copiedSlot1;
 }
 if(!outputSlot60[0]) {
  outputSlot60[0]=' ';outputSlot60[1]=0;outputLengthSlot0=1;lineCountSlot0=1;
  heightSlot31=data->glyphs[32].height;
  widthSlot1=(int)data->glyphs[32].width;
 }
 layout->lines.FUN_00af25b0(&widthSlot1);
 maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
 outputSlot60[outputLengthSlot0]=0;
 layout->FUN_004037f0(outputSlot60,0);
 layout->width=maxWidthSlot29;
 layout->height=fnv_FloatToInt(heightSlot31);
 layout->firstLine=0;
 layout->maxLines=lineCountSlot0;
 layout->characters=outputLengthSlot0;
 DAT_011f6238.FUN_00aa4060(workSlot77);
 DAT_011f6238.FUN_00aa4060(outputSlot60);
}
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
namespace PageMeshes {

struct Vec {float x,y,z;};struct Color {float r,g,b,a;Color(float R,float G,float B,float A){r=R;g=G;b=B;a=A;}};extern Vec DAT_011f426c;extern float DAT_01095274,DAT_01095270,DAT_0109526c;

struct Update {float time;bool controllers,multithreaded,unk6,unk7,unk8;Update(){time=0.0f;controllers=false;multithreaded=false;unk6=false;unk7=false;unk8=false;}};

struct Bound {void ComputeBoundingSphere(unsigned short,Vec*);};

struct GeometryData {int unk0,unk4;unsigned short count,unkA;int unkC;Bound bound;int unk14,unk18,unk1C;Vec* vertices;Vec* GetVertices(){Vec* result=vertices;return result;}unsigned short GetCount(){return count;}Bound& GetBound(){return bound;}};

struct Shape {virtual void Destroy();unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3c;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4c;unsigned int unk50;unsigned int unk54;Vec position;unsigned int unk64;unsigned int unk68;unsigned int unk6c;unsigned int unk70;unsigned int unk74;unsigned int unk78;unsigned int unk7c;unsigned int unk80;unsigned int unk84;unsigned int unk88;unsigned int unk8c;unsigned int unk90;unsigned int unk94;unsigned int unk98;unsigned int unk9c;unsigned int unka0;unsigned int unka4;unsigned int unka8;unsigned int unkac;unsigned int unkb0;unsigned int unkb4;GeometryData* data;void SetPosition(const Vec& v){position=v;}void SetPositionThroughShape(const Vec& v){Shape* current=this;current->position=v;}GeometryData* GetData(){return data;}void FUN_00a5a040();void FUN_00a59c60(const Update&);};

struct Node {virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void v60();virtual void v64();virtual void v68();virtual void v6c();virtual void v70();virtual void v74();virtual void v78();virtual void v7c();virtual void v80();virtual void v84();virtual void v88();virtual void v8c();virtual void v90();virtual void v94();virtual void v98();virtual void v9c();virtual void va0();virtual void va4();virtual void va8();virtual void vac();virtual void vb0();virtual void vb4();virtual void vb8();virtual void vbc();virtual void vc0();virtual void vc4();virtual void vc8();virtual void vcc();virtual void vd0();virtual void vd4();virtual void vd8();virtual void Attach(Shape*,bool);};

struct Heap {void* FUN_00aa3e40(unsigned int);void FUN_00aa4060(void*);};extern Heap DAT_011f6238;

template<class T> struct Link {Link* next;Link* previous;T value;};

template<class T> struct ListBase {Link<T>* head;Link<T>* tail;unsigned int count;~ListBase(){}Link<T>* Head(){return head;}T& Next(Link<T>*& p){T& value=p->value;p=p->next;return value;}unsigned int Count(){return count;}void FUN_00a1c270(Link<T>*);void FUN_00a1c2d0(){Link<T>* pNode=head;while(pNode){Link<T>* pDelete=pNode;pNode=pNode->next;pDelete->value=0;Link<T>* pFree=pDelete;DAT_011f6238.FUN_00aa4060(pFree);}count=0;head=0;tail=0;}T PopFront(){Link<T>* pNode=head;head=head->next;if(head)head->previous=0;else tail=0;T element=pNode->value;pNode->value=0;Link<T>* pFree=pNode;DAT_011f6238.FUN_00aa4060(pFree);--count;return element;}void FUN_00a11db0(Link<T>* item){item->next=0;item->previous=tail;if(tail)tail->next=item;else head=item;tail=item;++count;}void FUN_00a11c00(const T& value){Link<T>* item=NewNode();item->value=value;FUN_00a11db0(item);}Link<T>* NewNode(){Link<T>* node=(Link<T>*)DAT_011f6238.FUN_00aa3e40(sizeof(Link<T>));return node;}void Add(T value){Link<T>* p=NewNode();p->value=value;FUN_00a1c270(p);}};
template<class T> struct PointerListBase : ListBase<T> {~PointerListBase(){this->FUN_00a1c2d0();}};
template<class T> struct List : PointerListBase<T> {List(){this->count=0;this->head=0;this->tail=0;} ~List(){}};


unsigned int TextLength(const char*);unsigned int TextCapacity(unsigned int,unsigned int);void* TextCopy(void*,const void*,unsigned int);
struct Text {char* p;unsigned short length,capacity;Text(const Text& value){Init();Set(value.Get(),0);}~Text();void Init(){p=0;SetLength(0);SetMaxLength(0);}unsigned int MaxLength() const {return capacity;}
void SetLength(unsigned int n){length=n<=0xffff?(unsigned short)n:0xffff;}
void SetMaxLength(unsigned int n){capacity=n<=0xffff?(unsigned short)n:0xffff;}
bool Set(const char* source,unsigned int minimum){unsigned int size=source?TextLength(source):0;unsigned int maximum=TextCapacity(size,minimum);if(maximum<=MaxLength()){if(maximum){if(source)TextCopy(p,source,size+1);else p[0]=0;}else{if(p)delete p;p=0;maximum=0;SetMaxLength(maximum);}}else{char* old=p;p=new char[maximum+1];if(source)TextCopy(p,source,size+1);else p[0]=0;if(old)delete old;SetMaxLength(maximum);}SetLength(size);return size!=0;}
char* Get() const {return p;}char& operator[](unsigned int i) const {return p[p?i:0];}};

struct Run {int font;unsigned char letter,unk5,unk6,unk7;Color color;int unk18;Text text;int width,height,padding,unk30,offset;};

struct Line {List<Run*> runs;int width,unk10,height,unk18,padding,align;};

struct Page {List<Line*> lines;int CountEmptyNameEntries(unsigned int);};

struct Letter {float leading,top,width,height;unsigned int unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34;};

struct FontData {unsigned int unk0;unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3c;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4c;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5c;unsigned int unk60;unsigned int unk64;unsigned int unk68;unsigned int unk6c;unsigned int unk70;unsigned int unk74;unsigned int unk78;unsigned int unk7c;unsigned int unk80;unsigned int unk84;unsigned int unk88;unsigned int unk8c;unsigned int unk90;unsigned int unk94;unsigned int unk98;unsigned int unk9c;unsigned int unka0;unsigned int unka4;unsigned int unka8;unsigned int unkac;unsigned int unkb0;unsigned int unkb4;unsigned int unkb8;unsigned int unkbc;unsigned int unkc0;unsigned int unkc4;unsigned int unkc8;unsigned int unkcc;unsigned int unkd0;unsigned int unkd4;unsigned int unkd8;unsigned int unkdc;unsigned int unke0;unsigned int unke4;unsigned int unke8;unsigned int unkec;unsigned int unkf0;unsigned int unkf4;unsigned int unkf8;unsigned int unkfc;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10c;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11c;unsigned int unk120;unsigned int unk124;Letter letters[256];};

struct Icons {virtual void v0();virtual void v4();virtual void Free(void*);int unk4,count,unkC;bool Empty(){return count==0;}void FUN_00a1bfa0(bool abFree){if(unk4){for(unsigned int i=0;i<(unsigned int)count;++i){}if(abFree){Free((void*)unk4);unk4=0;unk4=0;unkC=0;}count=0;}}};

struct Font {unsigned int unk0;unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34;FontData* data;unsigned int unk3c;unsigned int unk40;Icons icons;Shape* CreateTextShape(int,const Color*,bool);Shape* FUN_00a14da0();void UpdateIconGeometry(int,Shape*,Vec&);void BuildGlyphQuad(Letter*,int,Shape*,Vec&,const Color*);};

struct Manager {Font* fonts[8];Font* GetFont(unsigned int i){return fonts[i];}Shape* FUN_00a1a800(Text,Vec,int,int);};extern Manager* DAT_011f33f8;inline Manager* GetDebrisManager(){return DAT_011f33f8;}

struct Layout {unsigned int unk0;unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;int height;unsigned int unk2c;unsigned int unk30;bool useWidth;unsigned char unk35,unk36,unk37;int Height(){return height;}bool UseWidth(){return useWidth;}};

struct Builder {List<Page*> pages;int width;int unk10;int index;void BuildPage(Node*,Layout*);};

// Builds text and image shapes for a page, computes their bounds, and attaches them to a node.
// @fnv 0x00a19060
void Builder::BuildPage(Node* node,Layout* layout){

Page* pageSlot35=0;int remainingSlot28=index;int iconIndexSlot11=0;Shape* shapesSlot32[8];int indices[8];Link<Page*>* cursorSlot10=pages.Head();while(cursorSlot10&&remainingSlot28--)pages.Next(cursorSlot10);if(cursorSlot10)pageSlot35=cursorSlot10->value;else return;

for(unsigned int fontIndex=0;fontIndex<8;fontIndex++){indices[fontIndex]=0;shapesSlot32[fontIndex]=0;int count=pageSlot35->CountEmptyNameEntries(fontIndex);if(count>0){shapesSlot32[fontIndex]=GetDebrisManager()->GetFont(fontIndex)->CreateTextShape(count,&Color(117.0f/255.0f,59.0f/255.0f,33.0f/255.0f,1.0f),true);shapesSlot32[fontIndex]->SetPosition(DAT_011f426c);}}

List<Shape*> imagesSlot52;Shape* iconsSlot17=0;if(!GetDebrisManager()->GetFont(0)->icons.Empty()){iconsSlot17=GetDebrisManager()->GetFont(0)->FUN_00a14da0();iconsSlot17->SetPositionThroughShape(DAT_011f426c);imagesSlot52.Add(iconsSlot17);}

if(pageSlot35){int lineIndexSlot43=0;Vec position=DAT_011f426c;Link<Line*>* lineCursorSlot0=pageSlot35->lines.Head();while(lineCursorSlot0&&lineIndexSlot43<layout->Height()){Line* lineSlot0=pageSlot35->lines.Next(lineCursorSlot0);position.x=0.0f;int lineWidthSlot23=0;if(layout->UseWidth())lineWidthSlot23=width;if(lineSlot0->align==4)position.x=float(lineWidthSlot23-lineSlot0->width);if(lineSlot0->align==2)position.x=float((lineWidthSlot23-lineSlot0->width)/2);position.y=0.0f;position.z-=lineSlot0->height+lineSlot0->padding;

Link<Run*>* runCursorSlot19=lineSlot0->runs.Head();while(runCursorSlot19){Run* runSlot0=lineSlot0->runs.Next(runCursorSlot19);Font* fontSlot0=GetDebrisManager()->GetFont(runSlot0->font);if((unsigned char)((!runSlot0->text.Get()||!runSlot0->text[0])?1:0)){

Vec glyphPosition=position;glyphPosition.x+=runSlot0->offset;if(runSlot0->letter==1){GetDebrisManager()->GetFont(0)->UpdateIconGeometry(iconIndexSlot11++,iconsSlot17,glyphPosition);}else fontSlot0->BuildGlyphQuad(&fontSlot0->data->letters[runSlot0->letter],indices[runSlot0->font]++,shapesSlot32[runSlot0->font],glyphPosition,&runSlot0->color);

}else{Vec imagePosition=position;imagePosition.x+=runSlot0->offset;Shape* image=GetDebrisManager()->FUN_00a1a800(runSlot0->text,imagePosition,runSlot0->width,runSlot0->height+runSlot0->padding);if(image)imagesSlot52.FUN_00a11c00(image);}}

}

bool attachedSlot0=false;for(unsigned int finishIndex=0;finishIndex<8;finishIndex++){if(shapesSlot32[finishIndex]){Vec* vertices=shapesSlot32[finishIndex]->GetData()->GetVertices();shapesSlot32[finishIndex]->GetData()->GetBound().ComputeBoundingSphere(shapesSlot32[finishIndex]->GetData()->GetCount(),vertices);shapesSlot32[finishIndex]->SetPosition(DAT_011f426c);shapesSlot32[finishIndex]->FUN_00a5a040();Update update;shapesSlot32[finishIndex]->FUN_00a59c60(update);node->Attach(shapesSlot32[finishIndex],true);attachedSlot0=true;}}

while(imagesSlot52.Count()){Shape* finishedImageSlot0=imagesSlot52.PopFront();Vec* imageVerticesSlot0=finishedImageSlot0->GetData()->GetVertices();finishedImageSlot0->GetData()->GetBound().ComputeBoundingSphere(finishedImageSlot0->GetData()->GetCount(),imageVerticesSlot0);finishedImageSlot0->position=DAT_011f426c;finishedImageSlot0->FUN_00a5a040();Update imageUpdateSlot0;finishedImageSlot0->FUN_00a59c60(imageUpdateSlot0);node->Attach(finishedImageSlot0,true);}}

GetDebrisManager()->GetFont(0)->icons.FUN_00a1bfa0(true);

}}

struct ButtonIconArray {
    virtual ~ButtonIconArray();
    virtual ButtonIcon* Allocate(unsigned int auiCount);
    virtual void Deallocate(ButtonIcon* apBuffer);
    virtual ButtonIcon* Reallocate(ButtonIcon* apBuffer, unsigned int auiCount);
    ButtonIcon* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void CopyElements(ButtonIcon* apDestAddr, ButtonIcon* apSrcAddr, unsigned int aiCount) {
        if (aiCount <= 0) {
            return;
        }
        if (apDestAddr < apSrcAddr) {
            for (unsigned int i = 0; i < aiCount; ++i) {
                memcpy(&apDestAddr[i], &apSrcAddr[i], sizeof(ButtonIcon));
            }
        } else if (apDestAddr > apSrcAddr) {
            for (int i = aiCount - 1; i >= 0; --i) {
                memcpy(&apDestAddr[i], &apSrcAddr[i], sizeof(ButtonIcon));
            }
        }
    }
    bool IsFull() const {
        if (iSize == SimpleArrayStorage) {
            return true;
        }
        return false;
    }
    void ResizeBuffer(unsigned int aiNewSize, unsigned int aiCopyCount) {
        if (pBuffer) {
            if (aiCopyCount == SimpleArrayStorage) {
                pBuffer = Reallocate(pBuffer, aiNewSize);
            } else {
                ButtonIcon* pnewBuffer = Allocate(aiNewSize);
                CopyElements(pnewBuffer, pBuffer, aiCopyCount);
                Deallocate(pBuffer);
                pBuffer = 0;
                pBuffer = pnewBuffer;
            }
        } else {
            pBuffer = Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    unsigned int FUN_00a1c130();
};

// Grows the buffer when full, increments iSize, and returns the index of the newly added slot.
// @fnv 0x00a1c130
unsigned int ButtonIconArray::FUN_00a1c130() {
    if (IsFull()) {
        if (SimpleArrayStorage == 0) {
            unsigned int inewSize = 4;
            pBuffer = Allocate(inewSize);
            SimpleArrayStorage = inewSize;
        } else {
            unsigned int inewSize = SimpleArrayStorage > 1024 ? SimpleArrayStorage + 1024 : SimpleArrayStorage * 2;
            ResizeBuffer(inewSize, iSize);
            SimpleArrayStorage = inewSize;
        }
    }
    iSize++;
    return iSize - 1;
}

namespace fnv_00a1b990 {
class MemoryManager {
public:
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;

unsigned long GetCurrentThreadIdWrapper();
long InterlockedCompareExchangeWrapper(volatile long* plDest, long lExchange, long lComparand);
void SleepWrapper(int iMS);

class NiCriticalSection {
public:
    volatile long m_ulThreadOwner;
    unsigned int m_uiLockCount;

    void Lock(const char* pcFile = 0)
    {
        unsigned long ulThreadID = GetCurrentThreadIdWrapper();
        if (m_ulThreadOwner == (long)ulThreadID)
        {
            m_uiLockCount++;
            return;
        }
        unsigned int uiSpin = 0;
        while (InterlockedCompareExchangeWrapper(&m_ulThreadOwner, ulThreadID, 0))
        {
            uiSpin++;
            if (uiSpin > 10000)
                SleepWrapper(1);
            else
                SleepWrapper(0);
        }
        m_uiLockCount = 1;
    }
    void Unlock();
};

template<class T> struct NiTListItem {
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    T m_element;
};

template<class T> class PoolAllocatorBase {
public:
    struct LinkedListEntry {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pAllocationList;
    static NiCriticalSection ms_kPoolLock;
};

template<class T> class NiTPointerAllocator : public PoolAllocatorBase<T> {
public:
    void Deallocate(void* p)
    {
        PoolAllocatorBase<T>::ms_kPoolLock.Lock();
        typename PoolAllocatorBase<T>::LinkedListEntry* pDel =
            (typename PoolAllocatorBase<T>::LinkedListEntry*)p;
        pDel->m_pUserData = 0;
        pDel->m_pkNext = PoolAllocatorBase<T>::ms_pAllocationList;
        PoolAllocatorBase<T>::ms_pAllocationList = pDel;
        PoolAllocatorBase<T>::ms_kPoolLock.Unlock();
    }
};

template<class TheAllocator, class T> class NiTListBase {
public:
    struct MapEntryCount : public TheAllocator {
        unsigned int m_uiCount;
    };

    ~NiTListBase() { }
    unsigned int GetSize() const { return m_kItemCount.m_uiCount; }

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    MapEntryCount m_kItemCount;
};

template<class TheAllocator, class T> class NiTPointerListBase : public NiTListBase<TheAllocator, T> {
public:
    ~NiTPointerListBase() { RemoveAll(); }

    void DeleteItem(NiTListItem<T>* pkItem)
    {
        pkItem->m_element = 0;
        this->m_kItemCount.Deallocate(pkItem);
    }

    void RemoveAll()
    {
        NiTListItem<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }

    T RemoveHead()
    {
        NiTListItem<T>* pkNode = this->m_pkHead;
        this->m_pkHead = this->m_pkHead->m_pkNext;
        if (this->m_pkHead)
            this->m_pkHead->m_pkPrev = 0;
        else
            this->m_pkTail = 0;
        T element = pkNode->m_element;
        DeleteItem(pkNode);
        this->m_kItemCount.m_uiCount--;
        return element;
    }
};

template<class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T> {
};

class TileValue {
public:
    ~TileValue();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};

class TileElement {
public:
    ~TileElement()
    {
        while (m_kValues.GetSize())
            delete m_kValues.RemoveHead();
    }
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    NiTPointerList<TileValue*> m_kValues;
};

class TileCollection {
public:
    ~TileCollection();
    NiTPointerList<TileElement*> m_kUnsortedGeometryList;
};

// Deletes each TileElement* in m_kUnsortedGeometryList by removing the head until the list is empty.
// @fnv 0x00a1b990
TileCollection::~TileCollection()
{
    while (m_kUnsortedGeometryList.GetSize())
        delete m_kUnsortedGeometryList.RemoveHead();
}
}  // namespace fnv_00a1b990

namespace fnv_00a1ba50 {
class MemoryManager {
public:
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;

unsigned long GetCurrentThreadIdWrapper();
long InterlockedCompareExchangeWrapper(volatile long* plDest, long lExchange, long lComparand);
void SleepWrapper(int iMS);

class NiCriticalSection {
public:
    volatile long m_ulThreadOwner;
    unsigned int m_uiLockCount;

    void Lock(const char* pcFile = 0)
    {
        unsigned long ulThreadID = GetCurrentThreadIdWrapper();
        if (m_ulThreadOwner == (long)ulThreadID)
        {
            m_uiLockCount++;
            return;
        }
        unsigned int uiSpin = 0;
        while (InterlockedCompareExchangeWrapper(&m_ulThreadOwner, ulThreadID, 0))
        {
            uiSpin++;
            if (uiSpin > 10000)
                SleepWrapper(1);
            else
                SleepWrapper(0);
        }
        m_uiLockCount = 1;
    }
    void Unlock();
};

template<class T> struct NiTListItem {
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    T m_element;
};

template<class T> class PoolAllocatorBase {
public:
    struct LinkedListEntry {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pAllocationList;
    static NiCriticalSection ms_kPoolLock;
};

template<class T> class NiTPointerAllocator : public PoolAllocatorBase<T> {
public:
    void Deallocate(void* p)
    {
        PoolAllocatorBase<T>::ms_kPoolLock.Lock();
        typename PoolAllocatorBase<T>::LinkedListEntry* pDel =
            (typename PoolAllocatorBase<T>::LinkedListEntry*)p;
        pDel->m_pUserData = 0;
        pDel->m_pkNext = PoolAllocatorBase<T>::ms_pAllocationList;
        PoolAllocatorBase<T>::ms_pAllocationList = pDel;
        PoolAllocatorBase<T>::ms_kPoolLock.Unlock();
    }
};

template<class TheAllocator, class T> class NiTListBase {
public:
    struct MapEntryCount : public TheAllocator {
        unsigned int m_uiCount;
    };

    ~NiTListBase() { }
    unsigned int GetSize() const { return m_kItemCount.m_uiCount; }

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    MapEntryCount m_kItemCount;
};

template<class TheAllocator, class T> class NiTPointerListBase : public NiTListBase<TheAllocator, T> {
public:
    ~NiTPointerListBase() { RemoveAll(); }

    void DeleteItem(NiTListItem<T>* pkItem)
    {
        pkItem->m_element = 0;
        this->m_kItemCount.Deallocate(pkItem);
    }

    void RemoveAll()
    {
        NiTListItem<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }

    T RemoveHead()
    {
        NiTListItem<T>* pkNode = this->m_pkHead;
        this->m_pkHead = this->m_pkHead->m_pkNext;
        if (this->m_pkHead)
            this->m_pkHead->m_pkPrev = 0;
        else
            this->m_pkTail = 0;
        T element = pkNode->m_element;
        DeleteItem(pkNode);
        this->m_kItemCount.m_uiCount--;
        return element;
    }
};

template<class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T> {
};

class BSStr {
public:
    ~BSStr() { Set(0, 0); }
    bool Set(const char* pcString, unsigned int uiLength);

    char* m_pString;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class TileValueAction {
public:
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    BSStr m_kString;
};

class TileValue {
public:
    ~TileValue()
    {
        while (m_kActions.GetSize())
            delete m_kActions.RemoveHead();
    }
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    NiTPointerList<TileValueAction*> m_kActions;
};

class TileElement {
public:
    ~TileElement();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    NiTPointerList<TileValue*> m_kValues;
};

// Deletes all TileValue* elements in m_kValues by repeatedly removing and deleting the head of the list until it is empty.
// @fnv 0x00a1ba50
TileElement::~TileElement()
{
    while (m_kValues.GetSize())
        delete m_kValues.RemoveHead();
}
}  // namespace fnv_00a1ba50

namespace fnv_00a1bb10 {
class MemoryManager {
public:
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;

unsigned long GetCurrentThreadIdWrapper();
long InterlockedCompareExchangeWrapper(volatile long* plDest, long lExchange, long lComparand);
void SleepWrapper(int iMS);

class NiCriticalSection {
public:
    volatile long m_ulThreadOwner;
    unsigned int m_uiLockCount;

    void Lock(const char* pcFile = 0)
    {
        unsigned long ulThreadID = GetCurrentThreadIdWrapper();
        if (m_ulThreadOwner == (long)ulThreadID)
        {
            m_uiLockCount++;
            return;
        }
        unsigned int uiSpin = 0;
        while (InterlockedCompareExchangeWrapper(&m_ulThreadOwner, ulThreadID, 0))
        {
            uiSpin++;
            if (uiSpin > 10000)
                SleepWrapper(1);
            else
                SleepWrapper(0);
        }
        m_uiLockCount = 1;
    }
    void Unlock();
};

template<class T> struct NiTListItem {
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    T m_element;
};

template<class T> class PoolAllocatorBase {
public:
    struct LinkedListEntry {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pAllocationList;
    static NiCriticalSection ms_kPoolLock;
};

template<class T> class NiTPointerAllocator : public PoolAllocatorBase<T> {
public:
    void Deallocate(void* p)
    {
        PoolAllocatorBase<T>::ms_kPoolLock.Lock();
        typename PoolAllocatorBase<T>::LinkedListEntry* pDel =
            (typename PoolAllocatorBase<T>::LinkedListEntry*)p;
        pDel->m_pUserData = 0;
        pDel->m_pkNext = PoolAllocatorBase<T>::ms_pAllocationList;
        PoolAllocatorBase<T>::ms_pAllocationList = pDel;
        PoolAllocatorBase<T>::ms_kPoolLock.Unlock();
    }
};

template<class TheAllocator, class T> class NiTListBase {
public:
    struct MapEntryCount : public TheAllocator {
        unsigned int m_uiCount;
    };

    ~NiTListBase() { }
    unsigned int GetSize() const { return m_kItemCount.m_uiCount; }

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    MapEntryCount m_kItemCount;
};

template<class TheAllocator, class T> class NiTPointerListBase : public NiTListBase<TheAllocator, T> {
public:
    ~NiTPointerListBase() { RemoveAll(); }

    void DeleteItem(NiTListItem<T>* pkItem)
    {
        pkItem->m_element = 0;
        this->m_kItemCount.Deallocate(pkItem);
    }

    void RemoveAll()
    {
        NiTListItem<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }

    T RemoveHead()
    {
        NiTListItem<T>* pkNode = this->m_pkHead;
        this->m_pkHead = this->m_pkHead->m_pkNext;
        if (this->m_pkHead)
            this->m_pkHead->m_pkPrev = 0;
        else
            this->m_pkTail = 0;
        T element = pkNode->m_element;
        DeleteItem(pkNode);
        this->m_kItemCount.m_uiCount--;
        return element;
    }
};

template<class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T> {
};

class String {
public:
    ~String() { Set(0, 0); }
    bool Set(const char* pcSrc, unsigned int uiLen);

    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
};

class StringItem {
public:
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    String m_kString;
};

class StringItemList {
public:
    ~StringItemList();
    NiTPointerList<StringItem*> m_kUnsortedGeometryList;
};

// Deletes all StringItem elements from m_kUnsortedGeometryList by repeatedly removing and deleting the head node until the list is empty.
// @fnv 0x00a1bb10
StringItemList::~StringItemList()
{
    while (m_kUnsortedGeometryList.GetSize())
        delete m_kUnsortedGeometryList.RemoveHead();
}
}  // namespace fnv_00a1bb10

double __cdecl FUN_00ec9130(double, double);
extern "C" float DAT_0102f0f8;

struct SStr {
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    char* GetString() { return pString; }
    unsigned int GetLen() { return sLen == 0xffff ? (unsigned int)strlen(GetString()) : (unsigned int)sLen; }
};

class TextGeometryGlyphData {
public:
    float m_fGlyphExtent;                       // 0x000
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    FontCharacterInfo letters[256];
};

class XBound {
public:
    void ComputeBoundingSphere(unsigned short nVerts, NiPoint3* pVerts3);
};

inline NiGeometryData* GetData(NiTriShape* s) { return s->m_spGeometryData.m_pObject; }
inline NiPoint3* GetVerts(NiGeometryData* d) { NiPoint3* p = d->m_pkVertex; return p; }
inline unsigned short GetCount(NiGeometryData* d) { return d->m_usVertices; }

inline int Max(int a, int b) { return a > b ? a : b; }
extern "C" double DAT_010731a8;
__forceinline double FMod75(const float& f) { return (float)FUN_00ec9130(f, DAT_0102f0f8); }
__forceinline void TabAdvance(float& x) { float remainder = x; float input = (float)FMod75(remainder); x = DAT_010731a8 - input + x; }

struct FontX : public Font {
    NiTriShape* FUN_00a12460(float fX, float fY, float fZ, SStr* text, int* piX,
                             int iFlags, void* pUnk, bool bShift, bool bSkip);
    void FUN_00a12370(char* str, float* pSize, float* pOut, int iFlags, int iStart);
    NiTriShape* CreateTextShape(int count, void* p, bool b);
};

// Builds a NiTriShape for a text string by mapping each character to glyph geometry, handling newlines and tabs, and updating the output x-offset.
// @fnv 0x00a12460
NiTriShape* FontX::FUN_00a12460(float fX, float fY, float fZ, SStr* text, int* piX,
                                int iFlags, void* pUnk, bool bShift, bool bSkip)
{
    if (text->GetLen() == 0 || this->m_pFontData == 0)
        return 0;

    float kPos2 = (float)*piX;
    float fOut1;
    this->FUN_00a12370(text->GetString(), &kPos2, &fOut1, iFlags, 0);

    NiPoint3 kVertexPositionLocal;
    kVertexPositionLocal.x = fX + kPos2;
    kVertexPositionLocal.z = fY;
    kVertexPositionLocal.y = fZ;

    if (bShift)
        kVertexPositionLocal.z = kVertexPositionLocal.z - (((TextGeometryGlyphData*)this->m_pFontData)->letters[32].m_fGlyphExtent - ((TextGeometryGlyphData*)this->m_pFontData)->m_fGlyphExtent) * 2.0f;

    unsigned int kColor = 0;
    while (kColor < text->GetLen() &&
           *(text->pString + (text->pString ? kColor : 0)) != 0)
        kColor++;
    if (kColor == 0)
        return 0;

    NiTriShape* kPos = this->CreateTextShape((int)kColor, pUnk, bSkip);

    NiPoint3 kOrigin2;
    kOrigin2.x = fX;
    kOrigin2.y = kVertexPositionLocal.y;
    kOrigin2.z = kVertexPositionLocal.z;
    kPos->m_kLocalTransform.m_kTranslation = kOrigin2;

    RgbaColor* fSize = 0;
    RgbaColor iCount2;
    iCount2.r = 0.0f;
    iCount2.g = 0.0f;
    iCount2.b = 1.0f;
    iCount2.a = 1.0f;

    *piX = 0;

    float fStartX3 = kVertexPositionLocal.x;
    int iIndex6 = 0;
    int i6 = 0;
    while (*(text->pString + (text->pString ? i6 : 0)) != 0)
    {
        if (*(text->pString + (text->pString ? i6 : 0)) == 3)
            fSize = 0;

        switch (*(text->pString + (text->pString ? i6 : 0)))
        {
        case '\n':
            {
                float fNewSize = (float)*piX;
                float fOut2;
                this->FUN_00a12370(text->GetString(), &fNewSize, &fOut2, iFlags, i6 + 1);
                kVertexPositionLocal.x = fNewSize;
                kVertexPositionLocal.z = kVertexPositionLocal.z - ((TextGeometryGlyphData*)this->m_pFontData)->m_fGlyphExtent;
            }
            break;
        case '\t':
            {
                TabAdvance(kVertexPositionLocal.x);
            }
            break;
        }

        unsigned char cChar = *(text->pString + (text->pString ? i6 : 0));
        MapCharacter(cChar);
        int iLetter = cChar;
        if (iLetter > 0x100)
            cChar = 0;
        FontCharacterInfo* kLetter = &((TextGeometryGlyphData*)this->m_pFontData)->letters[cChar];
        AddCharacterToShape(kLetter, iIndex6, kPos, kVertexPositionLocal, fSize);
        iIndex6++;
        *piX = Max((int)(kVertexPositionLocal.x - fStartX3), *piX);
        if (*(text->pString + (text->pString ? i6 : 0)) == 2)
            fSize = &iCount2;
        i6++;
    }

    NiPoint3* pVerts3 = GetVerts(GetData(kPos));
    ((XBound*)&GetData(kPos)->m_kBound)->ComputeBoundingSphere(GetCount(GetData(kPos)), pVerts3);
    return kPos;
}

void __cdecl NormalizeSmartQuotes(unsigned char*);

class TextWrapFontData {
public:
    float lineSpacing;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    FontCharacterInfo letters[256];
};

unsigned int LayoutLength(const char*);

struct BSStringT_char {
    char* data;
    unsigned short length;
    unsigned short capacity;

    bool Set(const char*, unsigned int);
    unsigned int MaxLength() const { return capacity; }
    void SetLength(unsigned int n) { length = n <= 0xffff ? (unsigned short)n : 0xffff; }

    BSStringT_char& operator+=(const char* str) {
        if (str) {
            if (GetString()) {
                unsigned int appendLength = str ? LayoutLength(str) : 0;
                unsigned int totalLength = Length() + appendLength;
                if (totalLength > MaxLength()) Set(GetString(), totalLength);
                memcpy((char*)GetString() + Length(), str, appendLength + 1);
                SetLength(totalLength);
            } else Set(str, 0);
        }
        return *this;
    }

    __forceinline const char* GetString() const {
        return data;
    }

    __forceinline unsigned int Length() const {
        return (length == 0xffff) ? (unsigned int)strlen(GetString()) : (unsigned int)length;
    }

    __forceinline char& operator[](unsigned int index) {
        return data[data ? index : 0];
    }
};

inline int max_val(int a, int b) {
    return a > b ? a : b;
}

struct TextWrapper : Font {
    int FUN_00a160c0(BSStringT_char* text, int* maxWidth, int* totalHeight, int lineLimit, char separator);
};

// Wraps text to fit maxWidth by inserting separators, returns line count and updates totalHeight.
// @fnv 0x00a160c0
int TextWrapper::FUN_00a160c0(BSStringT_char* text, int* piMaxWidth, int* piTotalHeight, int lineLimit, char separator)
{
    int p; // maxLines (bucket 15) -> -0x4
    unsigned int h; // index (bucket 14) -> -0x8
    int a; // lineCount (bucket 13) -> -0xc
    int i; // totalPixels (bucket 12) -> -0x10
    int s; // trailingSpaceWidth (bucket 11) -> -0x14
    int f; // longestWidth (bucket 10) -> -0x18
    int eb; // spaceWidth (bucket 9) -> -0x1c
    int cf; // currentWidth (bucket 8) -> -0x20
    unsigned int q; // length (bucket 7) -> -0x24
    FontCharacterInfo* b; // glyph (bucket 6) -> -0x28
    unsigned char ba; // mapped (bucket 5) -> -0x29
    unsigned int k; // cursor (bucket 4) -> -0x30
    char* l; // textData (bucket 3) -> -0x34

    l = text->data;
    if (!l || !m_pFontData) return 0;
    eb = 0;
    s = 0;
    cf = 0;
    f = 0;
    i = (int)((TextWrapFontData*)m_pFontData)->letters[32].m_fGlyphExtent;
    a = 0;
    q = text->Length();
    p = *piTotalHeight;
    if (*piMaxWidth == 0) *piMaxWidth = 999999;
    h = 0;
    for (; h < q; ++h) {
        if (!(*text)[h]) break;
        switch ((*text)[h]) {
        case '\n':
            (*text)[h] = separator;
            i += (int)((TextWrapFontData*)m_pFontData)->lineSpacing;
            f = f > cf ? f : cf;
            cf = 0;
            eb = 0;
            ++a;
            break;
        case '\t':
            cf += 75 - cf % 75;
            break;
        case ' ':
            eb = h;
        default:
            ba = (unsigned char)(*text)[h];
            NormalizeSmartQuotes(&ba);
            b = &((TextWrapFontData*)m_pFontData)->letters[ba];
            cf += (int)(b->m_fGlyphWidthInPixels + b->m_fHorizontalSpacing);
            if (eb == h) s = cf;
            if (cf > *piMaxWidth) {
                if (eb) {
                    (*text)[eb] = separator;
                    i += (int)((TextWrapFontData*)m_pFontData)->lineSpacing;
                    f = f > s ? f : s;
                    eb = 0;
                    ++a;
                    cf -= s;
                } else {
                    if (text->Length() >= text->capacity) {
                        if (text->Length() + 1 >= text->capacity) {
                            *text += "\n\n";
                            (*text)[text->Length() - 1] = 0;
                            (*text)[text->Length() - 2] = 0;
                        } else {
                            *text += "\n";
                            (*text)[text->Length() - 1] = 0;
                        }
                    }
                    for (k = q + 2; k > h; --k)
                        (*text)[k] = (*text)[k - 2];
                    (*text)[h - 1] = '-';
                    (*text)[h] = separator;
                    i += (int)((TextWrapFontData*)m_pFontData)->lineSpacing;
                    f = max_val(f, cf - (int)(b->m_fGlyphWidthInPixels + b->m_fHorizontalSpacing));
                    eb = 0;
                    ++a;
                    cf = 0;
                }
            }
        }
        if (p > 0 && a >= p) {
            while ((*text)[h] != separator) --h;
            (*text)[h] = 0;
            i -= (int)((TextWrapFontData*)m_pFontData)->lineSpacing;
            break;
        }
    }
    if ((*text)[0] && h >= q) ++a;
    f = f > cf ? f : cf;
    *piMaxWidth = f;
    *piTotalHeight = i;
    return a;
}

class Setting_01017720_011f96a0
{ public:
    unsigned int metadata;
    const char* filename;
    unsigned int options;
    __forceinline const char* c_str() const {
        const char* result; if (this != 0) result = filename; else result = 0; return result;
    }
};
extern Setting_01017720_011f96a0 g_011f3414;
extern Setting_01017720_011f96a0 g_011f3420;
extern Setting_01017720_011f96a0 g_011f342c;
extern Setting_01017720_011f96a0 g_011f3438;
extern Setting_01017720_011f96a0 g_011f3444;
extern Setting_01017720_011f96a0 g_011f3450;
extern Setting_01017720_011f96a0 g_011f345c;
extern Setting_01017720_011f96a0 g_011f3468;
extern __declspec(thread) int g_tlsMemContext;
extern char DAT_0109518c;
void __cdecl FUN_0040fbe0(const char*);
namespace FontManagerInitialization {
struct Memory { void* FUN_00aa3e40(unsigned int); };
extern Memory DAT_011f6238;
struct FUN_00a12020 : public Font {
    FUN_00a12020(int index, const char* name, int enabled);
    static __forceinline void* operator new(unsigned int n) {return DAT_011f6238.FUN_00aa3e40(n);}
    static __forceinline void operator delete(void*) {}
};
}
struct AllocatorScope { int previous; inline AllocatorScope(int value) { int saved = g_tlsMemContext; previous = saved; g_tlsMemContext = value; } inline ~AllocatorScope() { int saved = previous; g_tlsMemContext = saved; } };
struct FUN_00a168b0 : public FontManager {
    FUN_00a168b0();
};
// @fnv 0x00a168b0
FUN_00a168b0::FUN_00a168b0() {
    AllocatorScope scope(12);
    pFont[0] = new FontManagerInitialization::FUN_00a12020(1, g_011f3414.c_str(), 1);
    pFont[1] = new FontManagerInitialization::FUN_00a12020(2, g_011f3420.c_str(), 1);
    pFont[2] = new FontManagerInitialization::FUN_00a12020(3, g_011f342c.c_str(), 1);
    pFont[3] = new FontManagerInitialization::FUN_00a12020(4, g_011f3438.c_str(), 1);
    pFont[4] = new FontManagerInitialization::FUN_00a12020(5, g_011f3444.c_str(), 1);
    pFont[5] = new FontManagerInitialization::FUN_00a12020(6, g_011f3450.c_str(), 1);
    pFont[6] = new FontManagerInitialization::FUN_00a12020(7, g_011f345c.c_str(), 1);
    pFont[7] = new FontManagerInitialization::FUN_00a12020(8, g_011f3468.c_str(), 1);
    m_bUseNewFonts = false;
    bool loaded = false;
    for (int i=0;i<8;i++) {
      if (pFont[i]->m_pFontData != 0) {
        loaded = true;
        break;
      }
    }
    if (!loaded) FUN_0040fbe0(&DAT_0109518c);

}

namespace fnv_00a1a800 {
extern "C" unsigned int __cdecl strlen(const char*);
unsigned int __cdecl BSStringLength(const char*);
unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct TQMemoryAllocator {
    void* FUN_00aa3e40(unsigned int);
    void FUN_00aa4060(void*);
};
extern TQMemoryAllocator DAT_011f6238;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* __cdecl NiMalloc(unsigned int uiSize);

struct TQPoint3 {
    float x;
    float y;
    float z;

    TQPoint3() {}
    TQPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
    static void* operator new[](unsigned int uiSize) { return DAT_011f6238.FUN_00aa3e40(uiSize); }
};

struct TQPoint2 {
    float x;
    float y;

    TQPoint2() {}
    TQPoint2(float fX, float fY) { x = fX; y = fY; }
    static void* operator new[](unsigned int uiSize) { return DAT_011f6238.FUN_00aa3e40(uiSize); }
};

struct TQStr {
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMaxLen;

    TQStr(const TQStr& arOther);
    ~TQStr() { Set(0, 0); }
    unsigned int MaxLength() const { return m_usMaxLen; }
    void SetLength(unsigned int length) { m_usLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF; }
    void SetMaxLength(unsigned int length) { m_usMaxLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF; }
    bool Set(const char* apString, unsigned int auiLength) {
        unsigned int length = apString ? BSStringLength(apString) : 0;
        unsigned int capacity = BSStringCapacityMaximum(length, auiLength);
        if (capacity <= MaxLength()) {
            if (capacity) {
                if (apString) __memcpy(m_pString, apString, length + 1);
                else m_pString[0] = 0;
            } else {
                if (m_pString) delete[] m_pString;
                m_pString = 0;
                capacity = 0;
                SetMaxLength(capacity);
            }
        } else {
            char* oldString = m_pString;
            m_pString = new char[capacity + 1];
            if (apString) __memcpy(m_pString, apString, length + 1);
            else m_pString[0] = 0;
            if (oldString) delete[] oldString;
            SetMaxLength(capacity);
        }
        SetLength(length);
        return length != 0;
    }
    const char* CStr() const { return m_pString; }
    unsigned int Length() const { return (m_usLen == 0xFFFF) ? strlen(CStr()) : m_usLen; }
    char& operator[](unsigned int i) { return m_pString[m_pString ? i : 0]; }
};

class TQTexture {
public:
    unsigned int m_uiRefCount;

    virtual ~TQTexture();
    virtual void DeleteThis();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();

    void IncRefCount() { InterlockedIncrement((long*)&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement((long*)&m_uiRefCount) == 0) DeleteThis(); }
};

class TQExtra {
public:
    unsigned int m_uiRefCount;

    virtual ~TQExtra();
    virtual void DeleteThis();

    void IncRefCount() { InterlockedIncrement((long*)&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement((long*)&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T> class TQPtr {
public:
    T* m_pObject;

    TQPtr(T* apObject = 0) { m_pObject = apObject; if (m_pObject) m_pObject->IncRefCount(); }
    ~TQPtr() { if (m_pObject) m_pObject->DecRefCount(); }
    operator T*() const { return m_pObject; }
    TQPtr& operator=(T* object) {
        if (m_pObject != object) {
            if (m_pObject) m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject) m_pObject->IncRefCount();
        }
        return *this;
    }
};

bool __cdecl TQLoadTexture(const char* apPath, float* apfScale, TQPtr<TQTexture>& arspTexture, float afUnk,
                           TQPtr<TQExtra> aspExtra);

struct TQProperty;
struct TQPropertyList {
    void* head;
    void* tail;
    unsigned int count;
    void AddHead(const TQPtr<TQProperty>&);
};
struct TQZBuffer;
TQZBuffer* __cdecl TQCreateZBuffer(int aiFlags);

struct TQPropertyState {
    TQPtr<TQProperty> properties[7];
    TQPropertyState();
    ~TQPropertyState();
    static void* operator new(unsigned int size) { return DAT_011f6238.FUN_00aa3e40(size); }
    static void operator delete(void* memory) { DAT_011f6238.FUN_00aa4060(memory); }
};
struct TQPropertyLock {
    unsigned int owner;
    unsigned int count;
    void Lock(const char*);
    void Unlock() { if (--count == 0) owner = 0; }
};
extern TQPropertyLock DAT_011f42a0;

class TQShape {
public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void UpdatePropertiesDownwardPass(TQPropertyState*);
int unk004;
int unk008;
int unk00C;
int unk010;
int unk014;
TQShape* m_pParentNode;
int unk01C;
int unk020;
TQPropertyList SceneGraphObject;
int unk030;
int unk034;
int unk038;
int unk03C;
int unk040;
int unk044;
int unk048;
int unk04C;
int unk050;
int unk054;
int unk058;
int unk05C;
int unk060;
int unk064;
int unk068;
int unk06C;
int unk070;
int unk074;
int unk078;
int unk07C;
int unk080;
int unk084;
int unk088;
int unk08C;
int unk090;
int unk094;
int unk098;
int unk09C;
int unk0A0;
int unk0A4;
int unk0A8;
int unk0AC;
int unk0B0;
int unk0B4;
int unk0B8;
int unk0BC;
    TQZBuffer* m_pkZBuffer;
    int unk0C4;
int unk0C8;
int unk0CC;
int unk0D0;

    static void* __cdecl operator new(unsigned int uiSize);
    TQShape(unsigned short usVertices, TQPoint3* pkVertex, TQPoint3* pkNormal, void* pkColor, TQPoint2* pkTexture,
            unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles, unsigned short* pusTriList,
            int iUnk1, int iUnk2, int iUnk3, int iUnk4);
    void AttachProperty(TQProperty* apProperty);
    void SetZBuffer(TQZBuffer* apZBuffer) { m_pkZBuffer = apZBuffer; }
    void GetPropertyState(TQPropertyState*& state);
    void UpdateSceneObject() {
        TQPropertyState* state = 0;
        DAT_011f42a0.Lock(0);
        if (m_pParentNode) m_pParentNode->GetPropertyState(state);
        else state = new TQPropertyState;
        UpdatePropertiesDownwardPass(state);
        delete state;
        DAT_011f42a0.Unlock();
    }
};

struct TQProperty : TQExtra {
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual int GetType();
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
TQTexture* m_pkTexture;
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

    static void* __cdecl operator new(unsigned int uiSize);
    TQProperty(bool abFlag);
    void SetTexture(TQTexture* apTexture);
};

inline void TQShape::AttachProperty(TQProperty* apProperty) {
    if (apProperty->GetType() < 7)
        SceneGraphObject.AddHead(apProperty);
}

struct TQOwner {
    TQShape* FUN_00a1a800(TQStr kPath, float fX, float fY, float fZ, int iWidth, int iHeight);
};

// Builds a textured quad TQShape from a path and dimensions, attaches a texture property, and assigns a new z-buffer.
// @fnv 0x00a1a800
TQShape* TQOwner::FUN_00a1a800(TQStr kPath, float fX, float fY, float fZ, int iWidth, int iHeight)
{
    TQPoint3* pkVerts = new TQPoint3[4];
    TQPoint2* pkUVs5 = new TQPoint2[4];
    unsigned short* pusTris = (unsigned short*)NiMalloc(6 * sizeof(unsigned short));

    pkVerts[0] = TQPoint3(fX, fY, fZ + iHeight);
    pkVerts[1] = TQPoint3(fX, fY, fZ);
    pkVerts[2] = TQPoint3(fX + iWidth, fY, fZ + iHeight);
    pkVerts[3] = TQPoint3(fX + iWidth, fY, fZ);

    pkUVs5[0] = TQPoint2(0.0f, 0.0f);
    pkUVs5[1] = TQPoint2(0.0f, 1.0f);
    pkUVs5[2] = TQPoint2(1.0f, 0.0f);
    pkUVs5[3] = TQPoint2(1.0f, 1.0f);

    for (unsigned int i4 = 0; i4 < kPath.Length(); i4++) {
        if (kPath[i4] == '/')
            kPath[i4] = '\\';
    }

    float fScale = 1.0f;
    TQTexture* pkTexture3 = 0;
    if (kPath.m_pString && kPath[0]) {
        TQPtr<TQTexture> spTexture4 = 0;
        TQLoadTexture(kPath.CStr(), &fScale, spTexture4, 0.0f, 0);
        pkTexture3 = spTexture4;
    }

    if (pkTexture3) {
        pkUVs5[0] = TQPoint2(0.0f, 0.0f);
        pkUVs5[1] = TQPoint2(0.0f, (iHeight * fScale) / pkTexture3->GetHeight());
        pkUVs5[2] = TQPoint2((iWidth * fScale) / pkTexture3->GetWidth(), 0.0f);
        pkUVs5[3] = TQPoint2((iWidth * fScale) / pkTexture3->GetWidth(), (iHeight * fScale) / pkTexture3->GetHeight());
    }

    pusTris[0] = 0;
    pusTris[1] = 1;
    pusTris[2] = 2;
    pusTris[3] = 2;
    pusTris[4] = 1;
    pusTris[5] = 3;

    TQShape* pkShape = new TQShape(4, pkVerts, 0, 0, pkUVs5, 1, 0, 2, pusTris, 0, 0, 0, 0);
    TQProperty* pkProperty3 = new TQProperty(false);
    pkProperty3->SetTexture(pkTexture3);
    pkShape->AttachProperty(pkProperty3);
    TQZBuffer* pkNewZBuffer2 = TQCreateZBuffer(0x20);
    TQZBuffer* pkZBuffer9 = pkNewZBuffer2;
    pkShape->m_pkZBuffer = pkZBuffer9;
    pkShape->UpdateSceneObject();
    return pkShape;
}
}  // namespace fnv_00a1a800

extern double _gModifierZero;

struct FontManagerHelper {
    NiPoint3 GetStringDimensions(const char*, int, float, unsigned int);
};

struct FontAlignmentManager : FontManager {
    static FontManager* Instance() { return pInstance; }
};

struct FUN_00a12370_shell : Font {
    void FUN_00a12370(const char* apTextString, float& afX, float& afY, int aiFlags, unsigned int aiStart);
};

// For flag values 2 and 4, calls GetStringDimensions and sets afX to negative half or full returned x; otherwise sets afX to zero.
// @fnv 0x00a12370
void FUN_00a12370_shell::FUN_00a12370(const char* apTextString, float& afX, float& afY, int aiFlags, unsigned int aiStart)
{
    NiPoint3 stringDims;
    float fwrapWidth = (afX > _gModifierZero) ? afX : 3.4028234663852886e+38f;

    switch (aiFlags & 0xf)
    {
    case 2:
        stringDims = ((FontManagerHelper*)FontAlignmentManager::Instance())->GetStringDimensions(apTextString, m_iFontNumber, fwrapWidth, aiStart);
        afX = -stringDims.x / 2.0;
        break;
    case 4:
        stringDims = ((FontManagerHelper*)FontAlignmentManager::Instance())->GetStringDimensions(apTextString, m_iFontNumber, fwrapWidth, aiStart);
        afX = -stringDims.x;
        break;
    default:
        afX = 0.0f;
        break;
    }
}

class S00a1b7f0_FontData {

public:

 float height;

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

 int unk38;

 int unk3c;

 int unk40;

 int unk44;

 int unk48;

 int unk4c;

 int unk50;

 int unk54;

 int unk58;

 int unk5c;

 int unk60;

 int unk64;

 int unk68;

 int unk6c;

 int unk70;

 int unk74;

 int unk78;

 int unk7c;

 int unk80;

 int unk84;

 int unk88;

 int unk8c;

 int unk90;

 int unk94;

 int unk98;

 int unk9c;

 int unka0;

 int unka4;

 int unka8;

 int unkac;

 int unkb0;

 int unkb4;

 int unkb8;

 int unkbc;

 int unkc0;

 int unkc4;

 int unkc8;

 int unkcc;

 int unkd0;

 int unkd4;

 int unkd8;

 int unkdc;

 int unke0;

 int unke4;

 int unke8;

 int unkec;

 int unkf0;

 int unkf4;

 int unkf8;

 int unkfc;

 int unk100;

 int unk104;

 int unk108;

 int unk10c;

 int unk110;

 int unk114;

 int unk118;

 int unk11c;

 int unk120;

 int unk124;

 FontCharacterInfo letters[256];

};

inline Font* S00a1b7f0_MetricFont(unsigned int index) {

 FontManager* manager = FontManager::pInstance;

 Font* font = manager->pFont[index];

 return font;

}

inline float S00a1b7f0_MetricDrop(unsigned int index) {

 FontManager* manager = FontManager::pInstance;

 Font* selectedFont = manager->pFont[index];

 float c = selectedFont->m_fDrop;

 return c;

}

struct S00a1b7f0_MetricString {

 char* data; unsigned short length; unsigned short capacity;

 char& operator[](unsigned int index) { return data[data ? index : 0]; }

 bool Empty() {

  char* text = data;

  return !text || !(*this)[0];

 }

};

struct S00a1b7f0_GlyphMetric {

 unsigned int font;

 unsigned char character; unsigned char unk05; unsigned char unk06; unsigned char unk07;

 int unk08; int unk0c; int unk10; int unk14; int unk18;

 S00a1b7f0_MetricString icon;

 int width,height,drop,unk30,unk34;

 void FUN_00a1b7f0(unsigned char);

};

// Stores the character, conditionally computes width, height, and drop when the icon is empty, and resets fields.
// @fnv 0x00a1b7f0
void S00a1b7f0_GlyphMetric::FUN_00a1b7f0(unsigned char auiCharacter) {

 character = auiCharacter;

 FontCharacterInfo* letter5;

 char* text = icon.data;

 if ((unsigned char)(int)(!text || !icon[0])) {

  letter5 = &((S00a1b7f0_FontData*)S00a1b7f0_MetricFont(font)->m_pFontData)->letters[character];

  width = (int)(letter5->m_fGlyphWidthInPixels + (letter5->m_fGlyphWidthInPixels != 0.0 ? letter5->m_fHorizontalSpacing + letter5->m_fHorizontalAdvance : 0.0));

  height = (int)((S00a1b7f0_FontData*)S00a1b7f0_MetricFont(font)->m_pFontData)->height;

  drop = (int)-S00a1b7f0_MetricDrop(font);

  unk30 = 0;

 }

 unk34 = 0;

}
