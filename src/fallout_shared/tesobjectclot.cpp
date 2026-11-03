
// src/fallout_shared/tesobjectclot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesobjectclot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MagicItem;
struct MagicCaster
{
    void SetSelectedMagicItem(int);
};
struct TESObjectCLOT
{
    void FUN_005156b0();
};

// @fnv 0x005156b0
void TESObjectCLOT::FUN_005156b0()
{
    ((MagicCaster*)((char*)this + 0x48))->SetSelectedMagicItem(3);
}

namespace fnv_00515f40 {
struct S_00477f20
{
    void FUN_00477f20();
};
struct S_00487010
{
    void FUN_00487010();
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_00480610_shell
{
    void InitBipedModel();
};
struct FUN_00479350_shell
{
    void FUN_00479350();
};

struct TESObjectCLOT
{
    void FUN_00515f40();
};

// @fnv 0x00515f40
void TESObjectCLOT::FUN_00515f40()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00487010();
    reinterpret_cast<S_0048cca0*>(reinterpret_cast<char*>(this) + 0x3c)->FUN_0048cca0();
    reinterpret_cast<FUN_0047bd70_shell*>(reinterpret_cast<char*>(this) + 0x48)->FUN_0047bd70();
    reinterpret_cast<FUN_00480610_shell*>(reinterpret_cast<char*>(this) + 0x68)->InitBipedModel();
    reinterpret_cast<S_00477f20*>(reinterpret_cast<char*>(this) + 0x144)->FUN_00477f20();
    reinterpret_cast<FUN_00479350_shell*>(reinterpret_cast<char*>(this) + 0x14c)->FUN_00479350();
    reinterpret_cast<FUN_00485e00_shell*>(this)->FUN_00485e00();
    reinterpret_cast<FUN_00485680*>(this)->M();
}
}  // namespace fnv_00515f40

struct FUN_005155b0_shell
{
    void FUN_005155b0();
};

void __cdecl operator delete(void*);

struct FUN_00515580_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls the object's destructor and, when bit 0 of flags is set, frees the object, then returns this.
// @fnv 0x00515580
void* FUN_00515580_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<FUN_005155b0_shell*>(this)->FUN_005155b0();
    if (flags & 1)
        operator delete(reinterpret_cast<FUN_005155b0_shell*>(this));
    return this;
}

extern unsigned int _data_011c16bc;

extern int DAT_0102ab5c[1];
extern int DAT_0102ab70[1];
extern int DAT_0102ab84[1];
extern int DAT_0102ab98[1];
extern int DAT_0102abac[1];
extern int DAT_0102abcc[1];
extern int DAT_0102abe4[1];
extern int DAT_0102abf8[1];
extern int DAT_0102ac0c[1];

struct B1_4fe
{
    int* vtable;
    unsigned char padding[0x2c];
    B1_4fe();
    ~B1_4fe()
    {}
};

struct TESFullName
{
    int* vtable;
    unsigned char padding[8];
    TESFullName();
    ~TESFullName()
    {}
};

struct TESScriptableForm
{
    int* vtable;
    unsigned char padding[8];
    TESScriptableForm();
};

struct TESEnchantableForm
{
    int* vtable;
    unsigned char padding[0xc];
    TESEnchantableForm();
};

struct TESValueForm
{
    int* vtable;
    unsigned char padding[4];
    TESValueForm();
    ~TESValueForm()
    {}
};

struct TESWeightForm
{
    int* vtable;
    unsigned char padding[4];
    TESWeightForm();
    ~TESWeightForm()
    {}
};

struct TESBipedModelForm
{
    int* vtable;
    unsigned char padding[0xd8];
    TESBipedModelForm();
    ~TESBipedModelForm()
    {}
};

struct BGSDestructibleObjectForm
{
    int* vtable;
    unsigned char padding[4];
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm()
    {}
};

struct BGSEquipType
{
    int* vtable;
    unsigned char padding[4];
    BGSEquipType();
};

struct SFTX
{
    void SetFormType(int);
};

struct FUN_00515440 : B1_4fe,
                      TESFullName,
                      TESScriptableForm,
                      TESEnchantableForm,
                      TESValueForm,
                      TESWeightForm,
                      TESBipedModelForm,
                      BGSDestructibleObjectForm,
                      BGSEquipType
{
    FUN_00515440();
};

// Initializes the vtable pointers of all base classes, sets the form type to 0x1a, and calls FUN_005156b0 on the object.
// @fnv 0x00515440
FUN_00515440::FUN_00515440()
{
    this->B1_4fe::vtable = DAT_0102ac0c;
    this->TESFullName::vtable = DAT_0102abf8;
    this->TESScriptableForm::vtable = DAT_0102abe4;
    this->TESEnchantableForm::vtable = DAT_0102abcc;
    this->TESValueForm::vtable = DAT_0102abac;
    this->TESWeightForm::vtable = DAT_0102ab98;
    this->TESBipedModelForm::vtable = DAT_0102ab84;
    this->BGSDestructibleObjectForm::vtable = DAT_0102ab70;
    this->BGSEquipType::vtable = DAT_0102ab5c;

    reinterpret_cast<SFTX*>(this)->SetFormType(0x1a);
    reinterpret_cast<TESObjectCLOT*>(this)->FUN_005156b0();
}

namespace fnv_005156d0 {
struct TESForm
{
    bool GetInitialized();
    void SetInitializationState(bool);
};

struct TESScriptableForm
{
    void InitItem(TESForm*);
};

struct TESEnchantableForm
{
    void InitItem(TESForm*);
};

struct BGSDestructibleObjectForm
{
    void InitItem(TESForm*);
};

struct TESBipedModelForm
{
    void InitItem(TESForm*);
};

void _FNV_Warning(const char*, const char*);

struct FUN_005156d0_shell
{
    void FUN_005156d0();
};

// @fnv 0x005156d0
void FUN_005156d0_shell::FUN_005156d0()
{
    if (((TESForm*)this)->GetInitialized())
        return;

    if (*(int*)((char*)this + 0x6c) == 0)
    {
        _FNV_Warning("MASTERFILE: Clothing '%s' needs to have biped slots selected in the editor.",
                     ((const char*(__thiscall*)(void*))(*(void***)this)[0x4c])((void*)this));
    }

    ((TESScriptableForm*)((char*)this + 0x3c))->InitItem((TESForm*)this);
    ((TESEnchantableForm*)((char*)this + 0x48))->InitItem((TESForm*)this);
    ((BGSDestructibleObjectForm*)((char*)this + 0x144))->InitItem((TESForm*)this);
    ((TESBipedModelForm*)((char*)this + 0x68))->InitItem((TESForm*)this);

    ((TESForm*)this)->SetInitializationState(true);
}
}  // namespace fnv_005156d0

struct FUN_005155b0_Primary
{
    virtual ~FUN_005155b0_Primary();
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
};

struct FUN_005155b0_Base30
{
    virtual ~FUN_005155b0_Base30();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_005155b0_Base3c
{
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_005155b0_Base48
{
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_005155b0_Base58
{
    virtual ~FUN_005155b0_Base58();
    unsigned int unk04;
};

struct FUN_005155b0_Base60
{
    virtual ~FUN_005155b0_Base60();
    unsigned int unk04;
};

struct FUN_005155b0_Base68
{
    virtual ~FUN_005155b0_Base68();
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
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
};

struct FUN_005155b0_Base144
{
    virtual ~FUN_005155b0_Base144();
    unsigned int unk04;
};

struct FUN_005155b0_Base14c
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_005155b0_cls : FUN_005155b0_Primary,
                          FUN_005155b0_Base30,
                          FUN_005155b0_Base3c,
                          FUN_005155b0_Base48,
                          FUN_005155b0_Base58,
                          FUN_005155b0_Base60,
                          FUN_005155b0_Base68,
                          FUN_005155b0_Base144,
                          FUN_005155b0_Base14c
{
    virtual ~FUN_005155b0_cls();
};

// Destructor of the class; the body is empty, so it only runs the implicit destructors of its base classes.
// @fnv 0x005155b0
FUN_005155b0_cls::~FUN_005155b0_cls()
{}

extern "C" void* __cdecl _alloca(unsigned int);

struct RecordReader
{
    unsigned char FUN_00472660();
    int FUN_004726b0();
    bool FUN_004726f0();
    unsigned int GetField25C();
    void ReadChunkInt(unsigned int*);
    void ReadChunkData(unsigned short*);
    void GetChunkData(void*, unsigned int);
    unsigned short FUN_00403570();
    bool FUN_00401680();
};
struct BipedFlags
{
    void FUN_00512810();
    void FUN_00503210();
};
struct ScriptView
{
    void FUN_006ecd40(unsigned int);
    void FUN_0048cd90(void*);
};
struct EnchantmentView
{
    void FUN_006ecd40(unsigned int);
    void FUN_00483170(unsigned short);
};
struct EquipView
{
    void FUN_006ecd40(unsigned int);
};
struct ModelSegment
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void ReadModel(char*);
    unsigned int textureSet;
    unsigned int modelPath;
    unsigned int modelFileSize;
    unsigned int textureHash;
    unsigned int meshFlags;
    unsigned int reservedData;
    unsigned int modelVersion;
};
struct SmallModelSegment
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void ReadModel(char*);
    unsigned int textureSet;
    unsigned int modelPath;
    unsigned int modelFlags;
    unsigned int meshFlags;
    unsigned int modelVersion;
};
struct IconSegment
{
    int description;
    int flags;
    int lastUpdate;
    void FUN_00489100(char*);
};
struct TextureSegment
{
    int description;
    int flags;
    int lastUpdate;
    int size;
    void FUN_0047a380(char*);
};
struct BipedView
{
    void* vtable;
    unsigned int bipedMask;
    unsigned char bipedType;
    unsigned char humanoidFlags;
    unsigned short wornSlots;
    ModelSegment male;
    ModelSegment female;
    ModelSegment male4;
    ModelSegment female4;
    IconSegment firstIcon;
    IconSegment secondIcon;
    TextureSegment firstTexture;
    TextureSegment secondTexture;
    SmallModelSegment fifth;
};
struct ClothingVirtual
{
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
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
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void ReadBounds(RecordReader*);
    virtual void Unknown57();
    virtual void Unknown58();
    virtual void Unknown59();
    virtual void Unknown60();
    virtual void Unknown61();
    virtual void Unknown62();
    virtual void Unknown63();
    virtual void Unknown64();
    virtual void Unknown65();
    virtual void Unknown66();
    virtual void Unknown67();
    virtual void Unknown68();
    virtual void Unknown69();
    virtual void Unknown70();
    virtual void Unknown71();
    virtual void Unknown72();
    virtual void Unknown73();
    virtual void Unknown74();
    virtual void Unknown75();
    virtual void Unknown76();
    virtual void ReadEditorID(char*);
};
void __cdecl ReadFullName(TESFullName*, RecordReader*);
void __cdecl FUN_004781e0(BGSDestructibleObjectForm*, RecordReader*);
void __cdecl FUN_004892d0(ModelSegment*, RecordReader*);
void __cdecl FUN_004893e0(ModelSegment*, RecordReader*);
void __cdecl FUN_0048a990(ModelSegment*, RecordReader*);
struct ClothingLoader
{
    B1_4fe base;
    TESFullName fullName;
    TESScriptableForm scriptForm;
    TESEnchantableForm enchantment;
    TESValueForm value;
    TESWeightForm weight;
    BipedView biped;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equip;

    void CallWithThis(RecordReader*);
    void FUN_00484ab0(int);
    void FUN_004861f0(RecordReader*, int, int);
    bool ReadFromStream(RecordReader*);
};
// @fnv 0x00515760
bool ClothingLoader::ReadFromStream(RecordReader* reader)
{
    unsigned char marker = reader->FUN_00472660();
    if (marker != 0x1a)
        return false;
    CallWithThis(reader);
    FUN_00484ab0(0);
    int chunk;
    while ((chunk = reader->FUN_004726b0()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(pEditorId, 0x200);
            reinterpret_cast<ClothingVirtual*>(this)->ReadEditorID(pEditorId);
            break;
        }
        case 0x444e424f: {
            reinterpret_cast<ClothingVirtual*>(this)->ReadBounds(reader);
            break;
        }
        case 0x4c4c5546: {
            ReadFullName(this ? &this->fullName : 0, reader);
            break;
        }
        case 0x49524353: {
            unsigned int formID = 0;
            reader->ReadChunkInt(&formID);
            reinterpret_cast<ScriptView*>(&this->scriptForm)->FUN_006ecd40(formID);
            reinterpret_cast<ScriptView*>(&this->scriptForm)->FUN_0048cd90(this);
            break;
        }
        case 0x4d544945:
        case 0x4d414e45: {
            unsigned int formID = 0;
            reader->ReadChunkInt(&formID);
            reinterpret_cast<EnchantmentView*>(&this->enchantment)->FUN_006ecd40(formID);
            break;
        }
        case 0x4d414e41:
        case 0x544d4145: {
            unsigned short amount = 0;
            reader->ReadChunkData(&amount);
            reinterpret_cast<EnchantmentView*>(&this->enchantment)->FUN_00483170(amount);
            break;
        }
        case 0x54444d42: {
            if (reader->FUN_00403570() < 11)
            {
                unsigned int bipedData;
                reader->GetChunkData(&bipedData, 4);
                if (reader->FUN_00401680())
                    reinterpret_cast<BipedFlags*>(&bipedData)->FUN_00512810();
                (&this->biped)->bipedType = ((unsigned char*)&bipedData)[2];
                (&this->biped)->bipedMask = *(unsigned short*)&bipedData;
            }
            else
            {
                reader->GetChunkData(&(&this->biped)->bipedMask, 8);
                if (reader->FUN_00401680())
                    reinterpret_cast<BipedFlags*>(&(&this->biped)->bipedMask)->FUN_00503210();
            }
            (&this->biped)->bipedType &= ~0x10;
            break;
        }
        case 0x54434d42: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->fifth.ReadModel(buffer);
            break;
        }
        case 0x4c444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->male.ReadModel(buffer);
            break;
        }
        case 0x54444f4d: {
            FUN_004893e0(&(&this->biped)->male, reader);
            break;
        }
        case 0x53444f4d: {
            FUN_0048a990(&(&this->biped)->male, reader);
            break;
        }
        case 0x44444f4d: {
            FUN_004892d0(&(&this->biped)->male, reader);
            break;
        }
        case 0x44534f4d: {
            FUN_004892d0(&(&this->biped)->female, reader);
            break;
        }
        case 0x32444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->male4.ReadModel(buffer);
            break;
        }
        case 0x54324f4d: {
            FUN_004893e0(&(&this->biped)->male4, reader);
            break;
        }
        case 0x53324f4d: {
            FUN_0048a990(&(&this->biped)->male4, reader);
            break;
        }
        case 0x4e4f4349: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->firstIcon.FUN_00489100(buffer);
            break;
        }
        case 0x4f43494d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->firstTexture.FUN_0047a380(buffer);
            break;
        }
        case 0x3243494d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->secondTexture.FUN_0047a380(buffer);
            break;
        }
        case 0x33444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->female.ReadModel(buffer);
            break;
        }
        case 0x54334f4d: {
            FUN_004893e0(&(&this->biped)->female, reader);
            break;
        }
        case 0x53334f4d: {
            FUN_0048a990(&(&this->biped)->female, reader);
            break;
        }
        case 0x34444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->female4.ReadModel(buffer);
            break;
        }
        case 0x54344f4d: {
            FUN_004893e0(&(&this->biped)->female4, reader);
            break;
        }
        case 0x53344f4d: {
            FUN_0048a990(&(&this->biped)->female4, reader);
            break;
        }
        case 0x324f4349: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->GetChunkData(buffer, 0);
            (&this->biped)->secondIcon.FUN_00489100(buffer);
            break;
        }
        case 0x44545344:
        case 0x54534544: {
            FUN_004781e0(this ? &this->destructible : 0, reader);
            break;
        }
        case 0x50595445: {
            unsigned int equipID = 0;
            reader->ReadChunkInt(&equipID);
            reinterpret_cast<EquipView*>(&this->equip)->FUN_006ecd40(equipID);
            break;
        }
        case 0x41544144: {
            FUN_004861f0(reader, 0, 0);
            break;
        }
        default:
            break;
        }
        if (!reader->FUN_004726f0())
            break;
    }
    return true;
}

struct TESForm
{
    virtual ~TESForm();
};
struct FUN_005092f0_obj
{
    void FUN_004851b0(TESForm* apCopy);
};

struct ClothingCopyView : TESObjectCLOT
{
    void FUN_00515fb0(TESForm* apCopy);
};

// Dynamic-casts apCopy to TESObjectCLOT and, if valid, forwards the copy to the base class via FUN_004851b0.
// @fnv 0x00515fb0
void ClothingCopyView::FUN_00515fb0(TESForm* apCopy)
{
    TESObjectCLOT* pSourceClothing = dynamic_cast<TESObjectCLOT*>(apCopy);
    if (!pSourceClothing)
        return;
    ((FUN_005092f0_obj*)this)->FUN_004851b0(apCopy);
}

struct ClothingComparison
{
    bool FUN_00485270(TESForm*);
    bool FUN_00515ff0(TESForm*);
};
// Returns true if the given form is not a clothing item or if it passes the FUN_00485270 check.
// @fnv 0x00515ff0
bool ClothingComparison::FUN_00515ff0(TESForm* apForm)
{
    TESObjectCLOT* clothing = dynamic_cast<TESObjectCLOT*>(apForm);
    if (!clothing)
        return true;
    if (FUN_00485270(reinterpret_cast<TESForm*>(clothing)))
        return true;
    return false;
}
