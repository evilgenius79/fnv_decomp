
// src/fallout_shared/bgsconstructibleobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsconstructibleobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_004f9bf0_shell
{
    unsigned int FUN_004f9bf0();
};

// @fnv 0x004f9bf0
unsigned int FUN_004f9bf0_shell::FUN_004f9bf0()
{
    return ((unsigned int*)this)[0x2b];
}

void* __cdecl _Deallocate(void*);

struct BGSConstructibleObject
{
    void* __thiscall FUN_004f94b0();
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_004f94b0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004f9480
void* BGSConstructibleObject::Destroy(unsigned int flags)
{
    FUN_004f94b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004855a0
{
    void __thiscall M();
};
struct S_00487010
{
    void __thiscall FUN_00487010();
};
struct S_0048a520
{
    void __thiscall ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_0048e370_obj
{
    void __thiscall FUN_0048e370(unsigned int);
};
struct FUN_0047a240_shell
{
    void __thiscall FUN_0047a240(unsigned int);
};
struct S_0048cca0
{
    void __thiscall FUN_0048cca0();
};
struct S_00477f20
{
    void __thiscall FUN_00477f20();
};
struct FUN_00485e00_shell
{
    void __thiscall FUN_00485e00();
};
struct FUN_00485680
{
    void __thiscall M();
};
struct SoundH
{
    unsigned int __thiscall Deallocate();
};
void __cdecl FUN_00485910(unsigned int, unsigned int);

struct FUN_004f9a90_shell : BGSConstructibleObject
{
    void __thiscall FUN_004f9a90();
};

// @fnv 0x004f9a90
void __thiscall FUN_004f9a90_shell::FUN_004f9a90()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->FUN_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4C444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_obj*)((char*)this + 0x5c))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x8c))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x68))->FUN_0048cca0();
    ((S_00477f20*)((char*)this + 0x84))->FUN_00477f20();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    if (*(void**)((char*)this + 0xac))
    {
        unsigned int itempint = ((SoundH*)*(void**)((char*)this + 0xac))->Deallocate();
        FUN_00485910(0x4d414e52, itempint);
    }
    if (*(void**)((char*)this + 0xb0))
    {
        unsigned int itempint2 = ((SoundH*)*(void**)((char*)this + 0xb0))->Deallocate();
        FUN_00485910(0x4d414e43, itempint2);
    }
    ((FUN_00485680*)this)->M();
}

namespace fnv_004f9570 {
struct BGSConstructibleObject
{
    char pad[0xac];
    void* m_pCreatedObject;
    void* m_pWorkbenchKeyword;
    void FUN_004f9570();
};

// Sets the two pointer fields at offsets 0xac and 0xb0 to null.
// @fnv 0x004f9570
void BGSConstructibleObject::FUN_004f9570()
{
    m_pCreatedObject = 0;
    m_pWorkbenchKeyword = 0;
}
}  // namespace fnv_004f9570

typedef int CHUNK_ID;
class TESFile
{
  public:
    unsigned int GetChunkSize();
    unsigned short GetFormVersion();
    int GetChunkID();
    bool NextChunk();
    bool GetChunkData(unsigned int*);
    bool GetChunkData(void*, unsigned int);
};
extern "C" void* __cdecl _alloca(unsigned int);
class BGSListForm;
class TESBoundObject;
class TESForm
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void LoadBoundObject(TESFile*);
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void SetEditorID(const char*);
    void LoadRecordHeader(TESFile*);
    void SetInitializationState(bool);
    void ReadTypedData(TESFile*, void*, unsigned short);
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    void* pSourceFilesHead;
    void* pSourceFilesNext;
};
class TESBoundObjectBase : public TESForm
{
  public:
    void* pListHead;
    void* pPrev;
    void* pNext;
    short sBoundMinX;
    short sBoundMinY;
    short sBoundMinZ;
    short sBoundMaxX;
    short sBoundMaxY;
    short sBoundMaxZ;
};
class TESFullName
{
  public:
    void* pVtbl;
    char* pFullName;
    unsigned short sLen;
    unsigned short sMax;
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESModel
{
  public:
    static void LoadModelData(TESModel*, TESFile*);
    void* pVtbl;
    char* m_kModelObjectsItem;
    unsigned short sLen;
    unsigned short sMax;
    float m_fFadeDelta;
    void* pTextureList;
    unsigned char cFacegenFlags;
};
class TESModelTextureSwap : public TESModel
{
  public:
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
    void* pSwapListHead;
    void* pSwapListNext;
};
class TESTexture
{
  public:
    static void __cdecl ReadTextureData(TESTexture*, TESFile*);
    void* pVtbl;
    char* pTexture;
    unsigned short sLen;
    unsigned short sMax;
};
class TESScriptableForm
{
  public:
    void FUN_006ecd40(unsigned int);
    void InitItem(TESForm*);
    void* pVtbl;
    void* m_pFormScript;
    bool bResolved;
};
class TESValueForm
{
  public:
    void* pVtbl;
    int iValue;
};
class TESWeightForm
{
  public:
    void* pVtbl;
    float fWeight;
};
class BGSDestructibleObjectForm
{
  public:
    static void __cdecl LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    void* pVtbl;
    void* pData;
};
class BGSMessageIcon
{
  public:
    static void __cdecl LoadMessageIconChunk(BGSMessageIcon*, TESFile*);
    void* pVtbl;
    void* pIconVtbl;
    char* pIcon;
    unsigned int iIconLen;
};
class BGSPickupPutdownSounds
{
  public:
    void* pVtbl;
    void* pPickUpSound;
    void* pPutDownSound;
    void* pUnkSound;
};
struct FUN_004f96f0_cobj : public TESBoundObjectBase,
                           public TESFullName,
                           public TESModelTextureSwap,
                           public TESTexture,
                           public TESScriptableForm,
                           public TESValueForm,
                           public TESWeightForm,
                           public BGSDestructibleObjectForm,
                           public BGSMessageIcon,
                           public BGSPickupPutdownSounds
{
    BGSListForm* m_pCreatedObject;
    TESBoundObject* m_pWorkbenchKeyword;
    bool FUN_004f96f0(TESFile* apFile);
};
// Loads a bound object record from the file, dispatching each chunk to the matching loader and returning true.
// @fnv 0x004f96f0
bool FUN_004f96f0_cobj::FUN_004f96f0(TESFile* apFile)
{
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    CHUNK_ID chunkid;
    while ((chunkid = apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorId, 0x200);
            SetEditorID(pEditorId);
            break;
        }
        case 0x444e424f:
            LoadBoundObject(apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, apFile);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x53444f4d: {
            unsigned int uiChunkSize = apFile->GetChunkSize();
            void* pChunkData = _alloca(uiChunkSize);
            apFile->GetChunkData(pChunkData, uiChunkSize);
            TESModelTextureSwap::ParseTextureSwapData(pChunkData, uiChunkSize, apFile->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, apFile);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, apFile);
            break;
        case 0x49524353: {
            unsigned int tempint = 0;
            apFile->GetChunkData(&tempint);
            TESScriptableForm::FUN_006ecd40(tempint);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, apFile);
            break;
        case 0x41544144:
            ReadTypedData(apFile, 0, 0);
            break;
        case 0x4d414e52: {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            m_pCreatedObject = (BGSListForm*)itempint;
            break;
        }
        case 0x4d414e43: {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            m_pWorkbenchKeyword = (TESBoundObject*)itempint;
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

extern char DAT_01183028;
extern char DAT_01189c78;

void* __cdecl FUN_00ec43fb(unsigned int, unsigned int, void*, void*, unsigned int);

struct FUN_0051af50_cls
{
    void __thiscall FUN_0051af50(void* p);
};

struct FUN_009ee040_cls
{
    unsigned int __thiscall FUN_009ee040();
};

struct FUN_004f9b80_cls
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
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int m_ac;
    unsigned int m_b0;

    void __thiscall FUN_004f9b80(unsigned int a1);
};

// @fnv 0x004f9b80
void FUN_004f9b80_cls::FUN_004f9b80(unsigned int a1)
{
    void* r = FUN_00ec43fb(a1, 0, &DAT_01183028, &DAT_01189c78, 0);
    if (r == 0)
    {
    }
    else
    {
        reinterpret_cast<FUN_0051af50_cls*>(this)->FUN_0051af50(r);
        m_ac = reinterpret_cast<FUN_004f9bf0_shell*>(r)->FUN_004f9bf0();
        m_b0 = reinterpret_cast<FUN_009ee040_cls*>(r)->FUN_009ee040();
    }
}

class BGSListForm : public TESForm
{
  public:
    virtual ~BGSListForm();
};
class TESBoundObject : public TESForm
{
  public:
    virtual ~TESBoundObject();
};

TESForm* __cdecl LookupFormByID(unsigned int id);
void __cdecl ResolveFormID(unsigned int* id, void* file);
int __cdecl FUN_005b5e40(const char* fmt, ...);

struct S_004f95a0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
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
    BGSListForm* unkac;
    TESBoundObject* unkb0;
    bool FUN_004013e0();
    void FUN_0051a9a0();
    void* FUN_00484e60(int index);
    void FUN_00484ab0(bool flag);
    unsigned int FUN_0084e3a0();
    virtual const char* v130();
    void LoadFormReferences();
};

// @fnv 0x004f95a0
void S_004f95a0::LoadFormReferences()
{
    if (FUN_004013e0())
        return;
    FUN_0051a9a0();
    unsigned int id = (unsigned int)unkac;
    if (id)
    {
        ResolveFormID(&id, FUN_00484e60(-1));
        unkac = dynamic_cast<BGSListForm*>(LookupFormByID(id));
        if (!unkac)
            FUN_005b5e40("MASTERFILE: Could not find item list (%08X) on constructible object '%s' (%08X).", id, v130(),
                         FUN_0084e3a0());
    }
    id = (unsigned int)unkb0;
    if (id)
    {
        ResolveFormID(&id, FUN_00484e60(-1));
        unkb0 = dynamic_cast<TESBoundObject*>(LookupFormByID(id));
        if (!unkb0)
            FUN_005b5e40("MASTERFILE: Could not find created item (%08X) on constructible object '%s' (%08X).", id,
                         v130(), FUN_0084e3a0());
    }
    FUN_00484ab0(true);
}

struct BoundObjectComparison
{
    bool FUN_0051afb0(void*);
};

struct ConstructibleComparison : FUN_004f96f0_cobj
{
    bool FUN_004f9c10(void* apCompare);
};

// Returns true when FUN_00ec43fb returns null, the bound-object comparison succeeds, or either stored pointer differs.
// @fnv 0x004f9c10
bool ConstructibleComparison::FUN_004f9c10(void* apCompare)
{
    void* pcomp = FUN_00ec43fb((unsigned int)apCompare, 0, &DAT_01183028, &DAT_01189c78, 0);
    if (!pcomp)
        return true;
    if (((BoundObjectComparison*)this)->FUN_0051afb0(pcomp))
        return true;
    if (m_pCreatedObject != (BGSListForm*)((FUN_004f9bf0_shell*)pcomp)->FUN_004f9bf0())
        return true;
    if (m_pWorkbenchKeyword != (TESBoundObject*)((FUN_009ee040_cls*)pcomp)->FUN_009ee040())
        return true;
    return false;
}

// FUN_004f94b0 -- BGSConstructibleObject::~BGSConstructibleObject()
//
// The original is the destructor of BGSConstructibleObject.  Its class inherits
// one direct base (TESObjectMISCQ) which itself carries the whole primary chain
// plus nine secondary bases, so the derived class owns TEN vftable pointers:
// its own at +0 and the per-base vftables of the nine secondary bases at
// +0x30, +0x3c, +0x5c, +0x68, +0x74, +0x7c, +0x84, +0x8c and +0x9c.  The
// destructor stores all ten, calls TESForm::ClearData() and then lets the
// primary base finish the job (the nine secondary bases are destroyed inside
// TESObjectMISCQ's own destructor).

struct TESBoundObjectQ
{
    virtual void v00()
    {}
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void FUN_00483710();
};

struct TESFullNameQ
{
    virtual void v01()
    {}
    int unk04, unk08;
};

struct TESModelTextureSwapQ
{
    virtual void v02()
    {}
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};

struct TESIconQ
{
    virtual void v03()
    {}
    int unk04, unk08;
};

struct TESScriptableFormQ
{
    virtual void v04()
    {}
    int unk04, unk08;
};

struct TESValueFormQ
{
    virtual void v05()
    {}
    int unk04;
};

struct TESWeightFormQ
{
    virtual void v06()
    {}
    int unk04;
};

struct BGSDestructibleObjectFormQ
{
    virtual void v07()
    {}
    int unk04;
};

struct BGSMessageIconQ
{
    virtual void v08()
    {}
    int unk04, unk08, unk0c;
};

struct BGSPickupPutdownSoundsQ
{
    virtual void v09()
    {}
};

struct TESObjectMISCQ : TESBoundObjectQ,
                        TESFullNameQ,
                        TESModelTextureSwapQ,
                        TESIconQ,
                        TESScriptableFormQ,
                        TESValueFormQ,
                        TESWeightFormQ,
                        BGSDestructibleObjectFormQ,
                        BGSMessageIconQ,
                        BGSPickupPutdownSoundsQ
{
    ~TESObjectMISCQ();
};

struct FUN_004f94b0_BGSConstructibleObject : TESObjectMISCQ
{
    ~FUN_004f94b0_BGSConstructibleObject();
};

// @fnv 0x004f94b0
FUN_004f94b0_BGSConstructibleObject::~FUN_004f94b0_BGSConstructibleObject()
{
    FUN_00483710();
}
