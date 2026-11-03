
// src/fallout/interface/listbox_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout/interface/listbox.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/listbox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/listbox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct G2
{
    void AddHead(int**);
};
extern G2 g_011d8b54;
void AddToHeadList(int* arg);
struct GlobalObject_00869f00
{
    void Clear(bool bClear);
};
extern int DAT_010703b4;
struct FUN_00723f30_shell : GlobalObject_00869f00
{
    void FUN_00723f30();
};
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
extern int DAT_010703c8;
struct FUN_00723f50_shell : AX
{
    int* vtable;
    AX* FUN_00723f50();
};
void __cdecl _Deallocate(void*);
struct FUN_00724140_shell
{
    void __thiscall FUN_00722880();
    void* __thiscall Destroy(unsigned int flags);
};
struct FUN_007a51c0_shell
{
    void FUN_007a51c0();
};
void _Deallocate(void* p);
struct FUN_007a61f0_shell
{
    void* FUN_007a61f0(unsigned int flags);
};
struct FUN_007a62e0_shell
{
    int a;
    int b;
    char c;
    FUN_007a62e0_shell* __thiscall FUN_007a62e0(int param2, int* param3);
};
struct RecursiveLock;
struct Menu;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct BGSSaveLoadFileEntry;
struct ListBox
{
    bool SetSelection(Tile* apItem, int apSelect);
    bool FUN_007d8d80(Tile* apSelectItem);
};
struct FUN_007d8e80_shell
{
    void* FUN_007d8e80(unsigned int flags);
};
void __fastcall FUN_007d6f80(void*);
void __cdecl _Deallocate(void*);
struct FUN_007d8eb0_shell
{
    void __thiscall FUN_007d7d30();
    void* __thiscall FUN_007d8eb0(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct BSSimpleList
{
    void __thiscall Sort(int(__cdecl* cmp)(void*, void*));
};
struct FUN_00721410_class
{
    BSSimpleList list;
    void __thiscall FUN_00724360();
    void __thiscall FUN_00721410(void* param);
};
extern "C" char str_010703dc[];
struct FUN_00723fa0_shell : AX
{
    int* vtable;
    FUN_00723fa0_shell* __thiscall FUN_00723fa0();
};
struct FUN_00723ff0_shell : AX
{
    int* vtable;
    FUN_00723ff0_shell* Constructor();
};
extern int DAT_01070404;
struct FUN_00724070_shell : GlobalObject_00869f00
{
    void FUN_00724070();
};
struct FUN_007241d0_shell : FUN_00723f30_shell
{
    void* __thiscall FUN_007241d0(unsigned int flags);
};
struct FUN_00724290_shell
{
    void __thiscall FUN_00724070();
    void* __thiscall FUN_00724290(unsigned int flags);
};
struct FUN_007242c0_shell
{
    bool __thiscall FUN_007242c0(unsigned int flags);
};
struct VATSMenu
{
    int GetSelectedTargetIndex();
};
struct TGF
{
    float GetFloat(int);
};
int GetTileValueID(const char*, int);
extern int DAT_011d8cd8;
extern int DAT_011d8cdc;
struct FUN_0071ae60_shell : VATSMenu
{
    TGF* tile;
    unsigned int __thiscall FUN_0071ae60();
};
void __cdecl FUN_00724930();
struct FUN_00721bc0_shell
{
    int x;
    void __thiscall FUN_00721bc0(int(__cdecl* param)(void*, void*));
    void __thiscall FUN_00724930();
};
struct Tile
{
    Menu* GetMenu();
};
struct FUN_00723030_Holder
{
    int _p0;
    int _p1;
    int _p2;
    Tile* _t;
    bool IsTileMenu(Menu* p);
};
struct FUN_00725aa0_shell
{
    void __thiscall ProcessSlots();
};
struct FUN_00723310_shell
{
    BSSimpleList list;
    void __thiscall FUN_00723310(int(__cdecl* cmp)(void*, void*));
};
struct FUN_00723ac0_shell
{
    void __thiscall FUN_00726090();
    void __thiscall FUN_00723ac0(void* param);
};
struct FUN_00723f00_shell : AX
{
    int* vtable;
    FUN_00723f00_shell* __thiscall FUN_00723f00();
};
struct FUN_00723fd0_shell : GlobalObject_00869f00
{
    void __thiscall FUN_00723fd0();
};
struct FUN_00724090_shell
{
    void __thiscall FUN_00721150();
    void* __thiscall FUN_00724090(unsigned int flags);
};
struct FUN_00721920_shell
{
    void __thiscall FUN_00721920();
};
struct FUN_007240e0_shell
{
    void* __thiscall FUN_007240e0(unsigned int flags);
};
struct FUN_00724110_This
{
    void __thiscall FUN_007220d0();
    void* __thiscall FUN_00724110(unsigned int flags);
};
struct S_00724170
{
    void __thiscall FUN_00723070();
    void* __thiscall FUN_00724170(unsigned int flags);
};
struct FUN_007241a0_shell
{
    void __thiscall FUN_00723820();
    void* __thiscall FUN_007241a0(unsigned int flags);
};
struct Helper_00723fd0
{
    void __thiscall FUN_00723fd0();
};
struct FUN_00724230_shell
{
    void* __thiscall FUN_00724230(unsigned int flags);
};
struct FUN_00724260_shell
{
    void __thiscall FUN_00724020();
    void* __thiscall FUN_00724260(unsigned int flags);
};
struct Member_007a8b10
{
    ~Member_007a8b10();
};
struct FUN_007643c0_p07 : Member_007a8b10
{
    Member_007a8b10* __thiscall DestroySelf(unsigned int flags);
};
struct BSSimpleList;
struct FUN_007a6480_shell
{
    void __thiscall FUN_007a6480();
};
struct FUN_007a22a0_shell
{
    void __thiscall FUN_007a22a0(int(__cdecl* cmp)(void*, void*));
};
struct FUN_007a30a0_Holder
{
    int* __thiscall FindNodeValue(int, unsigned char);
    int __thiscall FUN_007a30a0(int, unsigned char);
};
struct FUN_007a80e0_shell
{
    int* __thiscall InitSceneNodes();
};
struct FUN_007a5700_shell
{
    int* __thiscall FUN_007a5700(int(__cdecl* cmp)(void*, void*));
};
struct FUN_007a1aa0_shell
{
    void FUN_007a1aa0();
};
struct FUN_007a6100_shell : FUN_007a1aa0_shell
{
    void* __thiscall FUN_007a6100(unsigned int flags);
};
struct FUN_007a6130_This
{
    void __thiscall FUN_007a1d60();
    void* __thiscall FUN_007a6130(unsigned int flags);
};
struct FUN_007a6190Owner
{
    void __thiscall FUN_007a37b0();
    void* __thiscall FUN_007a6190(unsigned int flags);
};
struct FUN_007a86b0_Item
{
    int a;
    int b;
    void __thiscall FUN_007a86b0(int);
};
struct FUN_007a63b0_holder
{
    void __thiscall FUN_007a63b0(FUN_007a86b0_Item*, unsigned int);
};
struct FUN_007a63f0_shell
{
    void __thiscall FUN_007a63f0(unsigned int requested, unsigned int savedSize);
    void __thiscall ConstructElements(int, unsigned int);
};
struct FUN_007d9000_shell
{
    void __thiscall ApplySelectionAction(int a, int b);
};
struct FUN_007d7a80_shell
{
    void __thiscall FUN_007d7a80(int a);
};
void __cdecl UpdateSaveLoadList();
struct FUN_007d8420_shell
{
    BSSimpleList list;
    void __thiscall SortList(int(__cdecl* cmp)(void*, void*));
    void __thiscall UpdateSaveLoadList();
};
struct FUN_007a6fa0_shell
{
    int* __thiscall FindNodeValue(int* a, unsigned char b);
};
struct FUN_007d86c0_shell
{
    int* __thiscall FUN_007d86c0(int* apItem, unsigned char apSelect);
};
struct NavMeshSearchLOSArray
{
    int _00;
    void* data;
    int size;
    int capacity;
    void FUN_006a8500();
    void FUN_007d9e80(void*, int);
    void FUN_007d8e20(bool);
};
float __cdecl FUN_004e4430(float);
int __cdecl FUN_00647b70(int, int);
int TraitNameToID(const char*);
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TileF
{
    void Set(int, float, bool);
};
struct ListBoxBase
{
    virtual ~ListBoxBase();
};
struct ListBox_71ad30 : ListBoxBase
{
    void* pListItem;
    void* pListNext;
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void UpdateScrollPages();
};
struct TileSet
{
    void Set(int, int);
};
struct FUN_007d8810_shell
{
    void* m0;
    void* m4;
    void* m8;
    TileSet* mC;
    void __thiscall FUN_007d8810(bool abVal);
};
extern int DAT_011d95ac;
extern int DAT_011d95b0;
struct FUN_00765340_shell : VATSMenu
{
    int pad[3];
    TGF* tile;
    unsigned int __thiscall GetUnfilteredCount();
};
extern int DAT_011dac94;
extern int DAT_011dac98;
struct FUN_007d8700_shell : VATSMenu
{
    int pad0;
    int pad1;
    int pad2;
    TGF* tile;
    unsigned int GetFilteredItemCount();
};
struct FUN_007240c0
{
    int* vptr;
    FUN_007240c0();
};
struct SL
{
    int a;
    int b;
    SL();
    ~SL();
};
struct ListBox_SetSelectedTile_shell
{
    void __thiscall SetSelectedTile(Tile* apItem, bool apSelect);
};
extern int DAT_01070220;
extern unsigned int _data_011c16bc;
struct FUN_00721060 : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    FUN_00721060();
};
struct TileValue;
struct Tile_GetValue_helper
{
    TileValue* __thiscall GetValue(int index);
};
struct Tile_GetChildByName_helper
{
    Tile* __thiscall GetNamedChild(const char* name);
};
struct Tile_FUN_0071aa60_helper
{
    void __thiscall FUN_0071aa60(bool value);
};
struct Tile_GetSpeechChallengeFailure_helper
{
    bool __thiscall GetSpeechChallengeFailure();
};
struct Tile_Set_helper
{
    void __thiscall Set(int trait, int value);
};
struct TAN
{
    void __thiscall SetImageFlags(int flags);
};
struct FUN_00a09130_shell
{
    void __thiscall FUN_00a09130(int index, Tile* tile, int value);
};
struct FUN_00a09410_shell
{
    void __thiscall Refresh(int value);
};
Tile* __cdecl FindNamedTile(Tile* tile, const char* name);
extern "C" char str_0106f87c[];
extern "C" char str_0106f884[];
extern "C" char str_0106f88c[];
extern "C" char str_0106f894[];
extern "C" char str_0106f898[];
extern "C" char str_0106f8ac[];
extern "C" char str_0106f8c0[];
struct FUN_00725c20_shell
{
    char padding_000[0x0c];
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTiles();
};
struct Tile_IsTrue_helper
{
    bool __thiscall ContainsTrait(int);
};
struct FUN_007a6bd0_shell
{
    char _base[0x0c];
    Tile* m_pListTile;
    bool __thiscall FUN_007a6bd0();
};
struct FUN_007a79b0_shell
{
    char _pad[12];
    Tile* m_pListTile;
    bool __thiscall FUN_007a79b0();
};
struct Tile_IsTrue_shell : Tile
{
    bool __thiscall ContainsTrait(int);
};
struct EntryProperty
{
    int FUN_0044ddc0();
};
struct Entry
{
    int id;
    EntryProperty* property;
};
struct ListNode
{
    Entry* item;
    ListNode* next;
    Entry** FUN_006815c0();
    ListNode* FUN_00726070();
};
struct TemporaryList : ListNode
{
    TemporaryList();
    ~TemporaryList();
    void FUN_005ae3d0(Entry** item);
    void FUN_00470470();
};
struct FunctionOwner
{
    int unk00;
    ListNode entries;
    void RemoveTile(int id);
    void FUN_0071a200(int entryType);
};
void __cdecl FUN_007211c0(void* p);
struct SubObject_00721150
{
    ~SubObject_00721150();
};
struct FUN_00721150_cls
{
    virtual ~FUN_00721150_cls();
    SubObject_00721150 m_04;

    void __thiscall FUN_007211e0();
};
extern "C" char str_01070244[];
int __cdecl TraitNameToIDAdd(const char*, int);
struct SelectedObject
{
    bool __thiscall IsTraitNonZero(int);
};
struct FUN_00721440_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SelectedObject* selected;

    bool __thiscall FUN_00724430();
    bool __thiscall ContainsKey(SelectedObject* object);
    void __thiscall FUN_007244e0();
    bool __thiscall SelectObject(SelectedObject* object);
};
extern int DAT_010702ec;
struct FUN_00721850_shell
{
    void __thiscall FUN_007a1950(int a, int b);
};
struct FUN_00721850_cls : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    FUN_00721850_cls();
};
struct CleanupMember_00721920
{
    ~CleanupMember_00721920();
};
struct FUN_00721920
{
    virtual ~FUN_00721920();
    CleanupMember_00721920 cleanup;
    void __thiscall FUN_00721990();
};
void __cdecl FUN_007211c0(void* object);
void __cdecl FUN_007211c0(void* p);
struct SubObj_007220d0
{
    int unk00;
    ~SubObj_007220d0();
};
class FUN_007220d0_cls
{
  public:
    SubObj_007220d0 m_sub04;

    void Cleanup();
    virtual ~FUN_007220d0_cls();
};
extern bool DAT_011d8909;
struct LBTileObj
{
    virtual ~LBTileObj();
};
struct LBExtraObj
{
    ~LBExtraObj();
};
struct LBItem
{
    LBTileObj* tile;
    LBExtraObj* extra;
};
struct LBNode
{
    LBItem** GetItem();
    void FUN_006ecd40(unsigned int flags);
    ~LBNode();
};
LBNode* __fastcall FUN_00726070(LBNode* node);
struct LBTile
{
    void Set(int trait, float value, bool propagate);
};
struct LBListBox
{
    void* vtbl;
    LBItem* pItem;
    LBNode* pNext;
    LBTile* m_pListTile;
    int unk10;
    void FUN_00722140();
    bool FUN_007242c0(unsigned int flags);
    void FUN_007253a0();
    void FUN_00725080();
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;
};
extern "C" char _DAT_01070244[];
int __cdecl TraitNameToIDAdd(const char*, int);
struct Tile_7223a0
{
    bool IsTraitNonZero(int);
};
struct ListBox_7223a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Tile_7223a0* m_pSelected;
    bool FUN_00724fd0();
    bool ContainsKey(Tile_7223a0*);
    void FUN_00725080();
    bool FUN_007223a0(Tile_7223a0* apTile);
};
// FUN_007227b0: constructor of a object with a base (vptr), a member sub-object
// with its own ctor/dtor (state -1..0 EH frame), a few int/word/float fields and
// a post-init call on this followed by a cdecl call with this.
struct FUN_007227b0_sub
{
    int unk00;
    int unk04;
    FUN_007227b0_sub();
    ~FUN_007227b0_sub();
};
struct FUN_007227b0_target
{
    void __thiscall FUN_007a1950(int, int);
};
struct FUN_007227b0_cls : FUN_007240c0
{
    FUN_007227b0_sub sub;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short w1c;
    float f20;
    float f24;
    float f28;
    unsigned short w2c;

    FUN_007227b0_cls();
};
struct Member_00722880
{
    ~Member_00722880();
};
Member_00722880::~Member_00722880()
{}
struct Helper_007228f0
{
    void __thiscall Call();
};
void Helper_007228f0::Call()
{}
void __cdecl FUN_007211c0(void*);
struct FUN_00722880
{
    virtual ~FUN_00722880();
    Member_00722880 member4;
};
struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};
struct FUN_00723070
{
    virtual ~FUN_00723070();
    FUN_0046ffb0 cleanupMember;
    void FUN_007230e0();
};
void __cdecl FUN_007211c0(FUN_00723070* self);
extern char DAT_0107038c;
struct FUN_00723750 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_00723750();
    void FUN_007a1950(int a, int b);
};
void __cdecl FUN_007211c0(void* p);
class Member_00723820
{
  public:
    ~Member_00723820();
};
class FUN_00723820_cls
{
  public:
    virtual ~FUN_00723820_cls();
    void Reset();
    Member_00723820 m_04;
};
extern "C" const char kListBoxEnabled[];
int __cdecl TraitNameToIDAdd(const char* pcTrait, int iIndex);
class B23AF0Tile
{
  public:
    bool GetBool(int m_iValueId);
};
class B23AF0ListBox
{
  public:
    bool IsEnabled();
    bool Contains(B23AF0Tile* pkTile);
    void Refresh();
    bool FUN_00723af0(B23AF0Tile* pkTile);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    B23AF0Tile* m_pkSelected;
};
struct ListItem
{
    int key;
};
struct ListLink
{
    ListItem* item;
    ListLink* next;
    ListItem** FUN_006815c0();
    ListLink* FUN_00726070();
};
struct ListOwner
{
    int unknown00;
    ListLink head;
    bool ContainsKey(int key);
};
struct FUN_00724360_Item
{
    int** FUN_006815c0();
    void* FUN_00726070();
};
struct FUN_00724360_Obj
{
    void FUN_00700320(unsigned int a, unsigned int b);
};
struct FUN_00724360_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;
    void FUN_00724360();
    void AccumulateTileHeight(int v);
    void FUN_00724800();
    void FUN_007244e0();
};
extern "C" char str_01070244[];
int __cdecl TraitNameToIDAdd(const char* name, int value);
struct Item_00724430
{
    bool __thiscall IsTraitNonZero(int value);
};
struct Owner_00724430
{
    int unk00;
    int unk04;
    int unk08;
    Item_00724430* item;
    bool __thiscall FUN_00724430();
};
struct Obj00724930
{
    void __thiscall FUN_00700320(unsigned int a, int b);
};
struct Item00724930
{
    Obj00724930* unk00;
    int unk04;
    unsigned char flag08;
};
struct Node00724930
{
    Item00724930** __thiscall FUN_006815c0();
    Node00724930* __thiscall FUN_00726070();
};
struct FUN_00724930_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void __thiscall AccumulateTileHeight(Obj00724930* p);
    void __thiscall FUN_00724dd0();
    void __thiscall UpdateTraitDisplay();
    void FUN_00724930();
};
float __cdecl FUN_004e4430(float);
int __cdecl FUN_00647b70(int, int);
int TraitNameToID(const char*);
struct TileFloatGet
{
    float GetFloat(int);
};
struct TileFloatSet
{
    void Set(int, float, bool);
};
struct TileI
{
    void Set(int, int);
};
struct VATSMenuView
{
    int unk00;
    int unk04;
    int unk08;
    TileFloatGet* pScrollTile;
    int unk10;
    TileI* pCountTile;
    int unk18;
    int unk1C;
    float fTotal;
    unsigned int FUN_00726710();
    void FUN_00724dd0();
};
struct TileProxy
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
};
struct OwnerProxy
{
    int unk00, unk04, unk08;
    TileProxy* tile0c;
    int unk10;
    TileProxy* tile14;
    int unk18, unk1c;
    float range;
    unsigned int FUN_007267c0();
    void FUN_007253a0();
};
struct FUN_00a01230_cls
{
    bool __thiscall IsTraitNonZero(int value);
};
struct FUN_007255a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_cls* m_0c;
    unsigned char FUN_007255a0();
};
int __cdecl TraitNameToIDAdd(const char* name, int len);
extern "C" char str_0106f90c[];
extern "C" char str_0106f8f8[];
struct TileA
{
    float GetFloat(int);
    void SetF(int, float, bool);
    void SetI(int, int);
};
struct S725970
{
    int unk00;
    int unk04;
    int unk08;
    TileA* tileA;
    int unk10;
    TileA* tileB;
    int unk18;
    int unk1C;
    float fVal;
    unsigned int FUN_00726870();
    void FUN_00725970();
};
extern "C" const char kListBoxEnabled[];
int __cdecl TraitNameToIDAdd(const char* pcTrait, int iIndex);
class B726160Tile
{
  public:
    bool GetBool(int m_iValueId);
};
class B726160Menu
{
  public:
    int unk00;
    int unk04;
    int unk08;
    B726160Tile* m_pkTile;
    bool FUN_00726160();
};
struct Parent
{
    void* vptr;
    Parent();
};
struct Section
{
    unsigned int count;
    unsigned int capacity;
    Section();
    ~Section();
};
struct FUN_00730810 : Parent
{
    Section section;
    void* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short nextIndex;
    float totalHeight;
    float lastSelection;
    float lastScrollbar;
    unsigned short flags;
    FUN_00730810();
    void __thiscall FUN_007a1950(int, int);
};
extern void* DAT_01070890;
void __cdecl AddToHeadList(FUN_00730810*);
struct FUN_00730e20_inner
{
    bool IsTraitNonZero(void* apKey);
};
struct FUN_00730e20_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00730e20_inner* m_0c;
    bool FUN_00730e20();
};
int __cdecl TraitNameToIDAdd(const char* s, int n);
extern "C" char _DAT_01070244[];
int __cdecl TraitNameToIDAdd(const char*, int);
struct Tile_764e40
{
    bool IsTraitNonZero(int);
};
struct Cls_764e40
{
    int unk00;
    int unk04;
    int unk08;
    Tile_764e40* m_pTile0c;
    bool FUN_00764e40();
};
struct Item
{
    int* data;
    int key;
};
struct Node
{
    Item** __thiscall FUN_006815c0();
    Node* __thiscall FUN_00726070();
};
struct Owner
{
    int unk00;
    Node head;
    int* __thiscall FindItemData(int* key);
};
extern "C" char str_01070244[];
struct FUN_007a23e0_arg
{
    int unk00;
    bool IsTraitNonZero(int v);
};
struct FUN_007a23e0_cls
{
    int unk00[4];
    FUN_007a23e0_arg* m_10;
    bool FUN_007a6550();
    bool __thiscall ContainsKey(FUN_007a23e0_arg* arg);
    void FUN_007a6600();
    bool FUN_007a23e0(FUN_007a23e0_arg* arg);
};
int __cdecl TraitNameToIDAdd(const char* name, int len);
class B7A27F0Tile;
class B7A27F0Base
{
  public:
    B7A27F0Base();
    virtual void VFunc00();
};
class B7A27F0List
{
  public:
    B7A27F0List();
    ~B7A27F0List();

    void* m_pvItem;
    B7A27F0List* m_pkNext;
};
void __cdecl AddToHeadList(void* pvListBox);
class FUN_007a27f0_cls : public B7A27F0Base, public B7A27F0List
{
  public:
    FUN_007a27f0_cls();
    virtual void VFunc00();

    void SetSelectedTile(B7A27F0Tile* pkTile, bool bFlag);

    void* m_pkParentTile;
    void* m_pkScrollBar;
    void* m_pkSelected;
    void* m_pkTemplate;
    short m_sItemCount;
    short unk1E;
    float m_fScrollPos;
    float m_fScrollMax;
    float m_fItemHeight;
    short m_sFlags;
};
extern int DAT_01075594;
struct FUN_007a36e0_m4
{
    int m_00;
    FUN_007a36e0_m4();
    ~FUN_007a36e0_m4();
};
struct FUN_007a36e0_cls : FUN_007240c0
{
    FUN_007a36e0_m4 m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    unsigned short m_1c;
    float m_20;
    float m_24;
    float m_28;
    unsigned short m_2c;

    void FUN_007a1950(int a, int b);

    FUN_007a36e0_cls();
};
struct FUN_007a6310_Elem8
{
    int a;
    int b;
    FUN_007a6310_Elem8();
};
void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void* p, void* where);
struct FUN_007a6310_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void __thiscall ConstructElements(int arr, unsigned int count);
};
extern "C" char str_01070244[];
int __cdecl TraitNameToIDAdd(const char*, int);
struct FUN_00a01230_shell
{
    bool __thiscall IsTraitNonZero(int);
};
struct FUN_007a6550_shell
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_shell* target;

    bool __thiscall FUN_007a6550();
};
struct FUN_00a01230_Target
{
    bool IsTraitNonZero(int handle);
};
int TraitNameToIDAdd(const char* name, int len);
struct FUN_007a7330_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_Target* m_0c;

    unsigned char FUN_007a7330();
};
struct FUN_007a81b0_target
{
    bool IsTraitNonZero(void* apKey);
};
struct FUN_007a81b0_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_007a81b0_target* m_0c;
    bool FUN_007a81b0();
};
int __cdecl TraitNameToIDAdd(const char* s, int n);
extern int DAT_01077094;
struct FUN_007240c0_Base
{
    const void* vtbl00;
    FUN_007240c0_Base();
};
struct FUN_0096a2d0_List
{
    int unk00;
    int unk04;
    FUN_0096a2d0_List();
    ~FUN_0096a2d0_List()
    {}
};
void __cdecl AddToHeadList(void* p);
struct FUN_007d7c60 : FUN_007240c0_Base
{
    FUN_0096a2d0_List list04;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    float unk20;
    float unk24;
    float unk28;
    short unk2C;
    FUN_007d7c60();
    void FUN_007a1950(void* tile, bool flag);
};
struct Member_0046ffb0
{
    ~Member_0046ffb0();
};
Member_0046ffb0::~Member_0046ffb0()
{}
void __cdecl FUN_007211c0(void*);
struct FUN_007d7d30
{
    Member_0046ffb0 m;
    void FUN_007d81f0();
    virtual ~FUN_007d7d30();
};
void** __fastcall FUN_006815c0(void* node);
void* __fastcall FUN_00726070(void* node);
struct FUN_007d8da0_cls
{
    void FUN_007d8da0(bool bFlag);
};
int __cdecl TraitNameToIDAdd(const char*, int);
struct SelectionTile
{
    bool IsTraitNonZero(int);
    void Set(int, int);
};
struct SelectionList
{
    bool FUN_007d7580();
    bool ContainsKey(SelectionTile*);
    bool ApplySelectionAction(SelectionTile* item, int action);
};
struct TileHeight
{
    float __thiscall FUN_00a011b0(int);
};
extern "C" char str_0106f90c[];
extern "C" char str_0106f8f8[];
struct HeightList
{
    int unk00;
    int unk04;
    int unk08;
    TileHeight* container;
    int unk10;
    Tile_Set_Helper* scrollbar;
    int unk18;
    int unk1c;
    float totalHeight;
    unsigned int __thiscall FUN_007d9ee0();
    void __thiscall FUN_007d9460();
};
float __cdecl FUN_004e4430(float);
int __cdecl FUN_00647b70(int, int);
int TraitNameToID(const char*);
struct TileX
{
    float GetFloat(int trait);
    void Set(int trait, float value, bool propagate);
    void Set(int trait, int value);
};
struct ListBoxScrollBase
{
    virtual ~ListBoxScrollBase();
};
struct ListBoxScroll : ListBoxScrollBase
{
    void* pListItem;
    void* pListNext;
    TileX* m_pListTile;
    TileX* pSelected;
    TileX* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;

    unsigned int GetFilteredItemCount();
    void FUN_007d9d50();
};
struct OwnedRecord
{
    ~OwnedRecord();
};
struct OwnedRecordList
{
    OwnedRecord** FUN_006815c0();
    OwnedRecordList* FUN_00726070();
    void FUN_00470470();
    ~OwnedRecordList();
};
struct RecordList
{
    OwnedRecordList* head;
    unsigned int count;
    void FUN_00851540();
};
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
class TESFullName
{
  public:
    virtual ~TESFullName();
    const char* GetFullName();
};
unsigned int __cdecl BSStringLength(const char*);
struct InventoryEntry
{
    TESBoundObject* object;
    int count;
    void* extra;
    InventoryEntry();
    int FUN_00726070();
    TESBoundObject* GetObject();
    bool FUN_004bd820();
    void FUN_004bc810(InventoryEntry*);
    void FUN_006ecd40(int);
};
struct InventoryList
{
    ~InventoryList();
};
struct InventoryChanges
{
    InventoryEntry* GetNextInventoryEntry(InventoryList*);
};
struct InventoryOwner
{
    void FUN_00575510(bool, InventoryList**, InventoryChanges**);
};
struct InventoryListBox
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void ClearItems();
    void* item;
    void* next;
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    void FUN_007a1950(int, bool);
    bool FUN_007242c0(unsigned int);
    Tile* FUN_0071a320(InventoryEntry*, const char*, int, int);
    void UpdateItems();
    void PopulateInventoryList(InventoryOwner*, bool(__cdecl*)(InventoryEntry*), int,
                               void(__cdecl*)(Tile*, InventoryEntry*), bool, bool);
};
struct RemovalItem
{
    LBTileObj* tile;
    LBExtraObj* extra;
    bool counted;
};
struct RemovalNode
{
    RemovalItem* item;
    RemovalNode* next;
    RemovalItem** GetItem();
    RemovalNode* FUN_00726070();
    void FUN_006ecd40(RemovalNode* next);
    ~RemovalNode();
};
struct RemovalHeader
{
    int vtable;
};
struct RemovalList : RemovalHeader, RemovalNode
{
    TileProxy* container;
    LBTileObj* selected;
    bool FUN_007242c0(unsigned int);
    void UpdateItems();
    bool RemoveNode(RemovalNode* node, RemovalNode* previous);
};
struct RemovalInterface
{
    void FUN_00715860(LBTileObj*, int, int);
};
RemovalInterface* FUN_004b7210();
extern "C" char str_0106f8d0[];
struct MenuBase_71f700
{
    virtual ~MenuBase_71f700();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct Elem_71f700
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Elem_71f700();
};
struct List68_71f700
{
    int unk00;
    int unk04;
    int unk08;
    ~List68_71f700();
};
struct Owned_71f700
{
    int unk00;
    ~Owned_71f700();
};
struct Effects_71f700
{
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
    ~Effects_71f700();
};
struct ListBoxA_71f700
{
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
    ~ListBoxA_71f700();
};
struct ListBoxB_71f700
{
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
    ~ListBoxB_71f700();
};
struct ListBoxC_71f700
{
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
    ~ListBoxC_71f700();
};
struct ListBoxD_71f700
{
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
    ~ListBoxD_71f700();
};
struct ListBoxE_71f700
{
    ~ListBoxE_71f700();
};
extern int DAT_011dace0;
void FUN_0071f8c0();
struct FUN_0071f700 : MenuBase_71f700
{
    Elem_71f700 elems[4];
    List68_71f700 list68;
    Owned_71f700* p74;
    Owned_71f700* p78;
    Owned_71f700* p7c;
    Owned_71f700* p80;
    Effects_71f700 effects;
    ListBoxA_71f700 list180;
    ListBoxA_71f700 list1b0;
    ListBoxB_71f700 list1e0;
    ListBoxC_71f700 list210;
    ListBoxD_71f700 list240;
    ListBoxE_71f700 list270;
    virtual ~FUN_0071f700();
};
struct TileObjV
{
    virtual void* Del(unsigned int flags);
};
struct ExtraObj
{
    void* FUN_004459e0(unsigned int flags);
};
struct ItemS
{
    TileObjV* curNode;
    ExtraObj* extra;
};
struct TileS
{
    void FUN_00a012d0(int trait, float value, bool propagate);
};
struct NodeS
{
    ItemS** FUN_006815c0();
    NodeS* FUN_00726070();
    void FUN_006ecd40(unsigned int flags);
    void* FUN_004702f0(unsigned int flags);
};
struct OwnerS
{
    void* vptr00;
    ItemS* pSingle;
    NodeS* pHead;
    TileS* pTile;
    int m10;
    int m14;
    int m18;
    unsigned short m_usPassCountLocal;
    unsigned short us1e;
    float m_fGlyphExtent;
    bool FUN_007242c0(unsigned int flags);
    void FUN_00724800();
    void FUN_007244e0();
    void FUN_007211e0();
};
struct NavigationTile
{
    float FUN_00a011b0(int trait);
    bool IsTraitNonZero(int trait);
};
struct NavigationItem
{
    NavigationTile* tile;
};
struct NavigationNode
{
    NavigationItem* item;
    NavigationNode* next;
    NavigationItem** FUN_006815c0();
    NavigationNode* FUN_00726070();
};
struct NavigationBase
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual NavigationTile* GetAt(int current, bool select);
};
struct NavigationList : NavigationBase, NavigationNode
{
    NavigationTile* container;
    NavigationTile* selected;
    NavigationTile* scrollbar;
    const char* templateName;
    unsigned short count;
    bool FUN_00724430();
    NavigationTile* FUN_007214b0(unsigned int action);
};
float __cdecl FUN_004bd510(float value, float step);
int __cdecl LBGetTraitID(const char* apName);
struct LBClearList : LBListBox
{
    void FUN_00724dd0();
    void UpdateTraitDisplay();
    void FUN_00721990();
};
float __cdecl FUN_004bd510(float a, float b);
struct Tile_721c60
{
    float FUN_00a011b0(int trait);
    bool IsTraitNonZero(int trait);
};
struct Item_721c60
{
    Tile_721c60* tile;
};
struct Node_721c60
{
    Item_721c60* item;
    Node_721c60* next;
    Item_721c60** FUN_006815c0();
    Node_721c60* FUN_00726070();
};
struct Base_721c60
{
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual Tile_721c60* VFunc14(int index, bool flag);
};
struct Class_721c60 : Base_721c60, Node_721c60
{
    Tile_721c60* m_pScrollBar;
    Tile_721c60* m_pSelected;
    int unk14;
    int unk18;
    unsigned short m_usItemCount;

    bool IsScrollBarTraitEnabled();
    Tile_721c60* FUN_00721c60(int action);
};
extern int DAT_01070314;
struct FUN_00722000 : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    void FUN_007a1950(int, int);

    FUN_00722000();
};
struct ListBox_007228f0 : LBListBox
{
    void FUN_00725970();
    void UpdateSpeechChallengeTrait();
    void FUN_007228f0();
};
struct ListBoxClear
{
    void* vtable;
    LBItem* pItem;
    LBNode* pNext;
    TileF* m_pListTile;
    LBTileObj* m_pSelectedTile;
    void* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;

    bool FUN_007242c0(unsigned int flags);
    void FUN_00725f40();
    void UpdateHighlightTiles();
    void FUN_007230e0();
};
float __cdecl FUN_004bd510(float afValue, float afMin);
struct LBKTile
{
    float GetFloat(int aiID);
    bool GetBool(int aiID);
};
struct LBKItem
{
    LBKTile* pTile;
};
struct LBKNode
{
    LBKItem* pItem;
    LBKNode* pNext;
    LBKItem** GetItem();
    LBKNode* GetNext();
};
struct LBKBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual LBKTile* GetTileByIndex(int aiIndex, int aiUnk);
};
struct LBKListBox : LBKBase, LBKNode
{
    LBKTile* pParentTile;
    LBKTile* pSelected;
    LBKTile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    bool FUN_00725b70();
    LBKTile* GetTileByKey(int aiKey);
};
float __cdecl FUN_004bd510(float value, float one);
struct ListBoxHelper
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual TileHeight* GetItemAt(int index, int flag);
    ListNode head;
    TileHeight* m_0c;
    TileHeight* m_10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    bool FUN_00726160();
    TileHeight* FUN_00723b60(int code);
};
int __cdecl TraitNameToIDAdd(const char*, int);
extern "C" char str_0106f87c[], str_0106f884[], str_0106f88c[], str_0106f894[], str_0106f898[], str_0106f8ac[],
    str_0106f8c0[];
struct HighlightValue
{
    void FUN_00a09130(int, void*, int);
    void Refresh(int);
};
struct HighlightTile
{
    HighlightValue* GetValue(int);
    bool GetSpeechChallengeFailure();
    HighlightTile* GetNamedChild(const char*);
    void FUN_0071aa60(bool);
    void SetImageFlags(int);
    void Set(int, int);
};
HighlightTile* __cdecl FindNamedTile(HighlightTile*, const char*);
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* container;
    HighlightTile* selected;
    void FUN_007244e0();
};
class Tile724
{
  public:
    void SetInt(int m_iValueId, int iValue);
};
struct Item724
{
    Tile724* m_pkTile;
    int unk04;
    bool m_bHidden;
};
class ItemList724
{
  public:
    Item724** GetItem();
    ItemList724* GetNext();

    Item724* m_pkItem;
    ItemList724* m_pkNext;
};
class MenuBase724
{
  public:
    virtual void vfn00();
};
class ListBox724 : public MenuBase724, public ItemList724
{
  public:
    void AddTile(Tile724* pkTile);
    void SortTiles();
    void UpdateScroll();
    void RefreshTiles();

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usElementCount;
    unsigned short unk1E;
    float m_fScroll;
};
// Whether the list box tile is enabled (trait id resolved once and cached).
int __cdecl C4FD0TraitNameToID(const char* pcName, int iDefault);
class C4FD0Tile
{
  public:
    bool GetBoolValue(int m_iValueId);
};
class C4FD0ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    C4FD0Tile* m_pkTile;

    bool FUN_00724fd0();
};
struct FUN_00a00f30_shell
{
    void* FUN_00a00f30(int);
};
struct FUN_00a07530_shell
{
    void FUN_00a07530(int);
};
struct FUN_007254d0_t
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;
    void UpdateSpeechChallengeTrait();
};
struct FUN_00725b70_inner
{
    bool IsTraitNonZero(void* apKey);
};
struct FUN_00725b70_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00725b70_inner* m_0c;
    bool FUN_00725b70();
};
int __cdecl TraitNameToIDAdd(const char* s, int n);
struct VLPoint3
{
    float x;
    float y;
    float z;
};
struct VLTile;
struct VLListNode;
struct VLTileList
{
    VLListNode* GetHeadPos();
    VLTile*& GetNext(VLListNode*& arpPos);
};
struct VLTile
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int GetType();

    VLTileList kChildren;

    void SetFloat(int aiTrait, float afValue, bool abPropagate);
    float GetFloat(int aiTrait);
    const char* GetString(int aiTrait);
};
struct VLFontManager
{
    static VLFontManager* __cdecl Instance();
    VLPoint3 GetStringDimensions(const char* apText, int aiFont, float afWrapWidth, int aiFlags);
};
int __cdecl VLTraitNameToID(const char* apName, int aiDefault);
int __cdecl VLTraitNameToIDSimple(const char* apName);
struct VLList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float fTotalHeight;

    void AccumulateTileHeight(VLTile* apTile);
};
struct Tile050;
struct Value050
{
    void RemoveFromReactions();
    void FUN_00a09130(int, Tile050*, int);
    void AppendFloatAction(int, float);
    void Refresh(int);
};
struct Menu050
{
    Tile050* AddTileFromTemplate(Tile050*, const char*, int);
};
struct Tile050
{
    Menu050* GetMenu();
    void* FUN_00a00f30(int);
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
    float FUN_00a011b0(int);
    Value050* FindTraitValue(int);
};
struct FUN_007a62e0
{
    Tile050* tile;
    int data;
    bool flag;
    FUN_007a62e0(Tile050*, int*);
};
struct List050
{
    FUN_007a62e0* item;
    List050* next;
    void FUN_007a7eb0(FUN_007a62e0*, int);
    void FUN_00905820(FUN_007a62e0* const&);
};
struct Owner050
{
    int unk00;
    List050 entries;
    Tile050* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short count;
    bool FUN_007242c0(unsigned int);
    void FUN_00724360();
    void AccumulateTileHeight(Tile050*);
    void FUN_00724800();
    unsigned int GetRaceCount();
    Tile050* AddListEntry(int, const char*, int, const char*);
};
extern "C" char kListBoxNumFiltered[];
struct ItemTile;
struct ItemValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int, ItemTile*, int);
    void AppendFloatAction(int, float);
    void Refresh(int);
};
struct ItemMenu
{
    ItemTile* Create(ItemTile*, const char*, int);
};
struct ItemTile
{
    ItemMenu* GetMenu();
    void* GetValue(int);
    void Set(int, int);
    void Set(int, const char*, bool);
    float FUN_00a011b0(int);
    ItemValue* FindTraitValue(int);
};
struct BoxItem
{
    ItemTile* tile;
    int data;
    char flag;
    BoxItem(ItemTile*, int*);
};
struct ItemList
{
    BoxItem* item;
    ItemList* next;
    void InsertSorted(BoxItem*, int(__cdecl*)(BoxItem*, BoxItem*));
    void AppendItem(BoxItem* const&);
};
extern "C" char str_0106f860[];
int TraitNameToIDAdd(const char*, int);
struct IntListBox
{
    int unk00;
    ItemList items;
    ItemTile* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short nextIndex;
    bool FUN_007242c0(unsigned int);
    void Synchronize();
    void AccumulateTileHeight(ItemTile*);
    void Update();
    int __thiscall Count();
    ItemTile* FUN_00764430(int, const char*, int(__cdecl*)(BoxItem*, BoxItem*), const char*);
};
extern bool DAT_011d8909;
extern "C" char str_0106f8d0[];
int TraitNameToID(const char*);
struct ClearTile
{
    virtual ~ClearTile();
};
struct ClearExtra
{
    ~ClearExtra();
};
struct ClearTileExtraPair
{
    ClearTile* tile;
    ClearExtra* extra;
};
struct ClearNode
{
    ClearTileExtraPair** FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(unsigned int);
    ~ClearNode();
};
struct ClearContainer
{
    void Set(int, float, bool);
};
struct ClearOwner
{
    int unk00;
    ClearTileExtraPair* item;
    ClearNode* next;
    ClearContainer* container;
    int selection;
    int unk14;
    int unk18;
    unsigned short count;
    float height;
    bool FUN_007242c0(unsigned int);
    void ResetScroll();
    void Refresh();
    void FUN_007646d0();
};
class C764930Tile
{
  public:
    void SetInt(int m_uiSoundID, int iValue);
};
struct C764930Item
{
    C764930Tile* m_pkTile;
    int unk04;
    bool m_bHidden;
};
class C764930ListNode
{
  public:
    C764930Item*& GetItem();
    C764930ListNode* GetNext();

    C764930Item* m_pkItem;
    C764930ListNode* m_pkNext;
};
class C764930MenuBase
{
  public:
    virtual ~C764930MenuBase();
};
class C764930ListMenu : public C764930MenuBase, public C764930ListNode
{
  public:
    void AddTile(C764930Tile* pkTile);
    void UpdateScrollBar();
    void UpdateSelection();

    void RebuildVisibleTiles();

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usNumVisible;
    unsigned short unk1E;
    float m_fScroll;
};
struct Cls_764ef0
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTile();
};
struct ScrollTile
{
    float FUN_00a011b0(int);
    void Set(int, float, bool);
    void FUN_00700320(int, int);
};
struct ScrollList
{
    int unk00;
    int unk04;
    int unk08;
    ScrollTile* container;
    int unk10;
    ScrollTile* scrollbar;
    int unk18;
    int unk1c;
    float total;
    unsigned int GetUnfilteredCount();
    void FUN_00765210();
};
class FUN_007a3ac0_ListBox
{
  public:
    void* vtbl;
    LBItem* pItem;
    LBNode* pNext;
    LBTile* m_pListTile;
    int unk10;
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;

    bool FUN_007242c0(unsigned int flags);
    void FUN_007a7700();
    void FUN_007a73e0();
    void FUN_007a3ac0();
};
struct NavTile
{
    float GetValue(int);
    bool Enabled(int);
};
struct NavItem
{
    NavTile* tile;
};
struct NavNode
{
    NavItem* item;
    NavNode* next;
    NavItem** GetItem();
    NavNode* Next();
};
float RoundStep(float, float step = 1.0f);
int Trait(const char*);
int UserTrait(const char*, int);
struct Navigation
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual NavTile* At(int, bool);
    NavNode items;
    NavTile* container;
    NavTile* selected;
    int unk14;
    int unk18;
    unsigned short count;
    bool Active();
    NavTile* FUN_007a4000(int key);
};
struct ListBox_7a6600
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall FUN_007a6600();
};
// Whether the list box tile is enabled (trait id resolved once and cached).
int __cdecl D7580TraitNameToID(const char* pcName, int iDefault);
class D7580Tile
{
  public:
    bool GetBoolValue(int m_iValueId);
};
class D7580ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    D7580Tile* m_pkTile;

    bool FUN_007d7580();
};
extern "C" char str_0106f8d0[];
struct P240Tile
{
    float FUN_00a011b0(int);
    void FUN_00700320(int, int);
    void FUN_00715c60(int, int);
};
struct P240Item
{
    P240Tile* tile;
    void* data;
    bool hidden;
};
struct P240List
{
    P240Item* item;
    P240List* next;
    P240Item** FUN_006815c0();
    P240List* FUN_00726070();
};
struct P240Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual P240Tile* v5(int, bool);
};
struct P240Owner : P240Base, P240List
{
    P240Tile* container;
    P240Tile* selected;
    P240Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    float height;
    void AccumulateTileHeight(P240Tile*);
    void FUN_007d9d50();
    P240Tile* SelectLast();
    void FUN_007d97a0();
    void ApplyFilter(bool(__cdecl* predicate)(void*));
};
// Selects a tile in the list box when the box is active and the tile is null or an enabled member of the list.
int __cdecl C7D8950TraitNameToID(const char* pcName, int iDefault);
class C7D8950Tile
{
  public:
    bool GetBoolValue(int m_iValueId);
};
class C7D8950ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C7D8950Tile* m_pkSelected;

    bool IsActive();
    bool Contains(C7D8950Tile* pkTile);
    void UpdateSelection();
    bool FUN_007d8950(C7D8950Tile* pkTile);
};
struct TileValue
{
    void FUN_00a09130(int index, Tile* tile, int value);
    void Refresh(int value);
};
struct TileExt : Tile
{
    TileValue* GetValue(int index);
    TileExt* GetNamedChild(const char* name);
    void FUN_0071aa60(bool value);
    bool GetSpeechChallengeFailure();
    void Set(int trait, int value);
    void SetImageFlags(int flags);
};
struct ListBoxExt
{
    int unk00;
    int unk04;
    int unk08;
    TileExt* tile0c;
    TileExt* tile10;

    void UpdateHighlightBox();
};
struct TileX2
{
    void FUN_00a07530(int);
};
struct ListBoxX
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void FUN_007d97a0();
};
struct ContNode;
bool __fastcall FUN_008256d0(ContNode*);
struct N6815c0
{
    RemovalItem** FUN_006815c0();
};
struct RList71a5 : RemovalList
{
    bool RemoveTile(LBTileObj* tile);
};
struct Tile118
{
    float FUN_00a011b0(int);
    bool IsTraitNonZero(int);
};
struct Item118
{
    Tile118* tile;
};
struct Node118
{
    Item118* item;
    Node118* next;
    Item118*& FUN_006815c0();
    Node118* FUN_00726070();
};
float FUN_004bd510(float, float);
int TraitNameToID(const char*);
struct Box118
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Tile118* GetTile(int, int);
    Node118 head;
    Tile118* scroll;
    Tile118* selected;
    int unk14, unk18;
    unsigned short count, flags;
    bool FUN_00724fd0();
    Tile118* FUN_00722410(unsigned int action);
};

struct TileValue_00a0a270;
struct TileValueOwner_00a01000
{
    TileValue_00a0a270* GetOrCreateTraitValue(int index);
};

class AGMemoryManager
{
  public:
    void* FUN_00aa3e40(unsigned int uiSize);
};
extern AGMemoryManager DAT_011f6238;
class AGListItem
{
  public:
    virtual ~AGListItem();
    int m_iIndex;
    AGListItem* m_pNext;
    AGListItem() : m_iIndex(2000), m_pNext(0)
    {}
    static void* operator new(unsigned int uiSize)
    {
        return DAT_011f6238.FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* p);
};
class AGValueItem : public AGListItem
{
  public:
    virtual ~AGValueItem();
    TileValue* m_pIntegerData;
    AGValueItem()
    {}
};
void __cdecl FUN_00a0a130(TileValue* pValue, void* pOwner);
class AGOwner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AGValueItem* m_pHead;
    void FUN_00a09130(int iIndex, Tile* pTile, int iValue);
};

// @fnv 0x00a09130
void AGOwner::FUN_00a09130(int iIndex, Tile* pTile, int iValue)
{
    AGValueItem* pLast = m_pHead;
    AGValueItem* pItem = new AGValueItem;
    pItem->m_iIndex = iIndex;
    pItem->m_pIntegerData = (TileValue*)((TileValueOwner_00a01000*)pTile)->GetOrCreateTraitValue(iValue);
    if (pLast)
    {
        while (pLast->m_pNext)
            pLast = (AGValueItem*)pLast->m_pNext;
        pLast->m_pNext = pItem;
    }
    else
    {
        m_pHead = pItem;
    }
    FUN_00a0a130(pItem->m_pIntegerData, this);
}
