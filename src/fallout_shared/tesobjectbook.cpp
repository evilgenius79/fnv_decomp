// fallout_shared/tesobjectbook.cpp: TESObjectBOOK, TESObjectMISC, TESObjectBOOK_GetSaveSize, Actor and more (16 functions)

#include "tesobjectbook_decls.h"

// Zeroes the two bytes at offset 0xc0, sets the byte at 0xc1 to 0xff, and calls the MagicCaster at offset 0x74 with 0.
// @fnv 0x00514830
void TESObjectBOOK::ResetFormData()
{
    memset(reinterpret_cast<char*>(this) + 0xc0, 0, 2);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xc1) = 0xff;
    reinterpret_cast<MagicCaster*>(reinterpret_cast<char*>(this) + 0x74)->SetSelectedMagicItem(0);
}

// @fnv 0x00514870
void TESObjectBOOK::InitItem()
{
    if (reinterpret_cast<TESFormInitFlag*>(this)->IsFormInitialized())
        return;
    reinterpret_cast<TESScriptableForm*>(reinterpret_cast<char*>(this) + 0x68)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<TESEnchantableForm*>(reinterpret_cast<char*>(this) + 0x74)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<BGSDestructibleObjectForm*>(reinterpret_cast<char*>(this) + 0x9c)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<char*>(this) + 0x3c)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<BGSPickupPutdownSounds*>(reinterpret_cast<char*>(this) + 0xb4)
        ->InitItem(reinterpret_cast<TESForm*>(this));

    if (static_cast<signed char>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xc1)) != -1)
    {
        int actorValue = static_cast<int>(ActorValue::GetActorValueForSectionIndex(
            ActorValue::kSectionBook, *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xc1)));
        if (actorValue < 0x20 || actorValue > 0x2e)
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xc1) = 0xff;
    }
    reinterpret_cast<TESForm*>(this)->SetInitializationState(true);
}

// @fnv 0x00514930
bool TESObjectBOOK::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x19)
        return false;

    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            LoadEditorID(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x54444f4d:  // MODT
        case 0x44444f4d:  // MODD
        case 0x44534f4d:  // MOSD
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d:  // MODS
        {
            unsigned int chunkSize = file->GetChunkSize();
            void* swaps = _alloca(chunkSize);
            file->GetChunkData(swaps, chunkSize);
            ParseTextureSwapData(swaps, chunkSize, reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case 0x4f43494d:  // MICO
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353:  // SCRI
        {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d544945:  // EITM
        case 0x4d414e45:  // ENAM
        {
            unsigned int enchantmentID = 0;
            file->GetChunkData(&enchantmentID);
            SetFormEnchanting(reinterpret_cast<EnchantmentItem*>(enchantmentID));
            break;
        }
        case 0x544d4145:  // EAMT
        case 0x4d414e41:  // ANAM
        {
            unsigned short enchantmentAmount = 0;
            reinterpret_cast<TESFileChunkData16*>(file)->GetChunkData(&enchantmentAmount);
            SetFormEnchantmentAmount(enchantmentAmount);
            break;
        }
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x54534544:  // DEST
        case 0x44545344:  // DSTD
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e59:  // YNAM
        {
            unsigned int pickupID = 0;
            file->GetChunkData(&pickupID);
            SetPickupSound(reinterpret_cast<TESSound*>(pickupID));
            break;
        }
        case 0x4d414e5a:  // ZNAM
        {
            unsigned int putdownID = 0;
            file->GetChunkData(&putdownID);
            SetPutdownSound(reinterpret_cast<TESSound*>(putdownID));
            break;
        }
        case 0x41544144:  // DATA
            ReadTypedData(file, &Data, 2);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0051a6a0
TESObjectMISC::TESObjectMISC()
{
    SetFormType(FORM_MISC);
    ResetFormData();
    SetInitializationState(true);
}

extern int DAT_0102a8b8;
extern int DAT_0102a8cc;
extern int DAT_0102a8e0;
extern int DAT_0102a8f4;
extern int DAT_0102a90c;
extern int DAT_0102a920;
extern int DAT_0102a940;
extern int DAT_0102a958;
extern int DAT_0102a96c;
extern int DAT_0102a98c;
extern int DAT_0102a9b0;
extern int DAT_0102a9c4;

struct FUN_00514500
{
    TESBoundObject m0;
    TESFullName m1;
    TESModelTextureSwap m2;
    TESIcon m3;
    TESScriptableForm m4;
    TESEnchantableForm m5;
    TESValueForm m6;
    TESWeightForm m7;
    TESDescription m8;
    BGSDestructibleObjectForm m9;
    BGSMessageIcon m10;
    BGSPickupPutdownSounds m11;

    FUN_00514500();
};

// @fnv 0x00514500
FUN_00514500::FUN_00514500()
{
    *reinterpret_cast<void**>(this) = &DAT_0102a9c4;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x30) = &DAT_0102a9b0;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x3C) = &DAT_0102a98c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x5C) = &DAT_0102a96c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x68) = &DAT_0102a958;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x74) = &DAT_0102a940;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x84) = &DAT_0102a920;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x8C) = &DAT_0102a90c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x94) = &DAT_0102a8f4;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x9C) = &DAT_0102a8e0;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xA4) = &DAT_0102a8cc;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xB4) = &DAT_0102a8b8;
    reinterpret_cast<TESObjectBOOK*>(this)->SetFormType((ENUM_FORM_ID)0x19);
    reinterpret_cast<TESObjectBOOK*>(this)->ResetFormData();
}

struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int flags);
};
struct FUN_0048e9b0
{
    unsigned short __thiscall GetSaveSize(unsigned int flags);
};

struct TESObjectBOOK_GetSaveSize
{
    unsigned short __thiscall FUN_00515220(unsigned int aiFlags);
};

// Sums the save sizes of the base and the sub-object at offset 0x84, adding 1 when flags bit 0x20 is set, and returns the total.
// @fnv 0x00515220
unsigned short __thiscall TESObjectBOOK_GetSaveSize::FUN_00515220(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0*)this)->GetSaveSize(aiFlags);
    isize += ((FUN_0048e9b0*)((char*)this + 0x84))->GetSaveSize(aiFlags);
    if (aiFlags & 0x20)
        isize += 1;
    return isize;
}

struct FormChangeMask
{
    unsigned int m_flags;
    FormChangeMask(unsigned int flags) : m_flags(flags)
    {}
    FormChangeMask() : m_flags(0)
    {}
    operator bool() const
    {
        return m_flags != 0;
    }
};

struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct FUN_00484d60_holder
{
    void SaveIfChanged(BGSSaveFormBuffer*);
};

struct FUN_0048ea40_holder
{
    void FUN_0048ea40(BGSSaveFormBuffer*);
};

struct FUN_00515340_shell
{
    void FUN_00515340(BGSSaveFormBuffer* buffer);
};

// @fnv 0x00515340
void FUN_00515340_shell::FUN_00515340(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(buffer);
    reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x84)->FUN_0048ea40(buffer);
    if (reinterpret_cast<BGSLoadFormBuffer*>(buffer)->GetChangeFlags(0x20))
        buffer->SaveData(reinterpret_cast<char*>(this) + 0xc1, 1, 0);
}

void _Deallocate(void*);
struct FUN_005146a0_shell
{
    void FUN_005146d0();
    void* Release(unsigned int);
};
// Calls FUN_005146d0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005146a0
void* FUN_005146a0_shell::Release(unsigned int flags)
{
    FUN_005146d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0051b070_shell
{
    void FUN_00484c20(unsigned int);
    void FUN_0048e9e0(unsigned int);
};
struct TESSaveLoadGame
{
    void FUN_008579b0(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_00515290_shell
{
    FUN_0051b070_shell base;
    char _pad0[0x83];
    FUN_0051b070_shell m84;
    char _pad1[0x3C];
    char bC1;
    void FUN_00515290(unsigned int);
};
// @fnv 0x00515290
void FUN_00515290_shell::FUN_00515290(unsigned int aiFlags)
{
    base.FUN_00484c20(aiFlags);
    m84.FUN_0048e9e0(aiFlags);
    if (aiFlags & 0x20)
        g_TESSaveLoadGame->FUN_008579b0(&bC1, 1);
}

namespace fnv_005152e0 {
struct TESFormStub
{
    void FUN_00484c50(unsigned int, unsigned int);
};
struct TESValueFormStub
{
    void FUN_0048ea10(unsigned int, unsigned int);
};
struct TESSaveLoadGame
{
    void ReadTypedData(void*, unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_005152e0_shell : TESFormStub
{
    char _pad0[0x84];
    TESValueFormStub val;
    char _pad1[0x3C];
    char byteC1;
    void FUN_005152e0(unsigned int, unsigned int);
};
// @fnv 0x005152e0
void FUN_005152e0_shell::FUN_005152e0(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    TESFormStub::FUN_00484c50(aiFlags, aiCurrentFlags);
    val.FUN_0048ea10(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x20)
        g_TESSaveLoadGame->ReadTypedData(&byteC1, 1);
}
}  // namespace fnv_005152e0

struct FUN_004855a0
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};
struct FUN_00482cb0_shell
{
    void FUN_00482cb0();
};
struct S_00477f20
{
    void FUN_00477f20();
};
struct FUN_0047b560_holder
{
    void LogFormIDs();
};
struct Date
{
    ~Date();
};
struct FUN_00485e00_shell
{
    void FUN_00485e20(Date*, int);
};
struct FUN_00485680
{
    void M();
};
bool __cdecl FUN_00401500();
struct FUN_00514de0_shell
{
    void Destroy();
};

// @fnv 0x00514de0
void FUN_00514de0_shell::Destroy()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->FUN_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_obj*)((char*)this + 0x5c))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0xa4))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x68))->FUN_0048cca0();
    ((FUN_0047bd70_shell*)((char*)this + 0x74))->FUN_0047bd70();
    ((FUN_00482cb0_shell*)((char*)this + 0x94))->FUN_00482cb0();
    ((S_00477f20*)((char*)this + 0x9c))->FUN_00477f20();
    ((FUN_0047b560_holder*)((char*)this + 0xb4))->LogFormIDs();
    if (FUN_00401500())
        ((Date*)((char*)this + 0xc0))->Date::~Date();
    ((FUN_00485e00_shell*)this)->FUN_00485e20((Date*)((char*)this + 0xc0), 2);
    if (FUN_00401500())
        ((Date*)((char*)this + 0xc0))->Date::~Date();
    ((FUN_00485680*)this)->M();
}

class FUN_005146d0 : public TESBoundObject,
                     public TESFullName,
                     public TESModelTextureSwap,
                     public TESIcon,
                     public TESScriptableForm,
                     public TESEnchantableForm,
                     public TESValueForm,
                     public TESWeightForm,
                     public TESDescription,
                     public BGSDestructibleObjectForm,
                     public BGSMessageIcon,
                     public BGSPickupPutdownSounds
{
  public:
    BookData Data;
    ~FUN_005146d0();
};

// Destructor of the object; the body is empty.
// @fnv 0x005146d0
FUN_005146d0::~FUN_005146d0()
{}

struct FUN_005153a0_arg;
struct FUN_005153a0_ret
{
    bool FUN_004280f0();
};
struct FUN_005153a0_arg
{
    FUN_005153a0_ret* FUN_00428110(unsigned int* out, int size);
    void FUN_00864980(void* p, int n);
};
struct FUN_005153a0_holder
{
    void FUN_0048ea80(FUN_005153a0_arg* a);
};
class FUN_005153a0_cls
{
  public:
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
    FUN_005153a0_holder m_84;
    unsigned char unk85;
    unsigned char unk86;
    unsigned char unk87;
    unsigned char unk88;
    unsigned char unk89;
    unsigned char unk8A;
    unsigned char unk8B;
    unsigned char unk8C;
    unsigned char unk8D;
    unsigned char unk8E;
    unsigned char unk8F;
    unsigned char unk90;
    unsigned char unk91;
    unsigned char unk92;
    unsigned char unk93;
    unsigned char unk94;
    unsigned char unk95;
    unsigned char unk96;
    unsigned char unk97;
    unsigned char unk98;
    unsigned char unk99;
    unsigned char unk9A;
    unsigned char unk9B;
    unsigned char unk9C;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char unkA2;
    unsigned char unkA3;
    unsigned char unkA4;
    unsigned char unkA5;
    unsigned char unkA6;
    unsigned char unkA7;
    unsigned char unkA8;
    unsigned char unkA9;
    unsigned char unkAA;
    unsigned char unkAB;
    unsigned char unkAC;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    unsigned char unkB0;
    unsigned char unkB1;
    unsigned char unkB2;
    unsigned char unkB3;
    unsigned char unkB4;
    unsigned char unkB5;
    unsigned char unkB6;
    unsigned char unkB7;
    unsigned char unkB8;
    unsigned char unkB9;
    unsigned char unkBA;
    unsigned char unkBB;
    unsigned char unkBC;
    unsigned char unkBD;
    unsigned char unkBE;
    unsigned char unkBF;
    unsigned char unkC0;
    unsigned char bC1;
    void FUN_00484da0(FUN_005153a0_arg* a);
    void FUN_005153a0(FUN_005153a0_arg* a1);
};
// @fnv 0x005153a0
void FUN_005153a0_cls::FUN_005153a0(FUN_005153a0_arg* a1)
{
    unsigned int local;
    FUN_00484da0(a1);
    m_84.FUN_0048ea80(a1);
    if (a1->FUN_00428110(&local, 0x20)->FUN_004280f0())
    {
        a1->FUN_00864980(&bC1, 1);
    }
}

// The source header omits the external data accessor and base copy declarations.
struct BookDataAccessor307
{
    BookData* FUN_00514f30();
};
struct Book307 : TESObjectBOOK
{
    void FUN_004851b0(TESForm* source);
    void CopyBookData(TESForm* source);
};
// @fnv 0x00514ed0
void Book307::CopyBookData(TESForm* source)
{
    TESObjectBOOK* book = dynamic_cast<TESObjectBOOK*>(source);
    if (!book)
        return;
    FUN_004851b0(source);
    Data = *reinterpret_cast<BookDataAccessor307*>(book)->FUN_00514f30();
}

#include <stdio.h>
class TESFullName_ext : public TESFullName
{
  public:
    const char* GetFullName();
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    TESFullName_ext fullName;
    int GetUnk15C();
};
struct InventoryItem
{
    TESBoundObject* GetObject();
    void* FUN_004bdcc0();
};
class BaseProcess
{
  public:
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual InventoryItem* FindEntryForObject();
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting g_011d2748;
extern InventoryMenuSetting g_011d2814;
extern InventoryMenuSetting g_011d38b8;
extern InventoryMenuSetting g_011d4e94;
extern InventoryMenuSetting g_011d34f8;
extern InventoryMenuSetting g_011d3684;
extern const char DAT_0108b3b4[];
void __cdecl FUN_0095e900();
void __cdecl ShowMessageBox(const char*, int, int, void(__cdecl*)(), int, int, float, float, ...);
class Actor
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    int selectedAction;
    BaseProcess* GetProcess();
    void FUN_0095e6f0(int action);
};
// Checks the inventory item and weapon type, displays messages on failure, and stores action before formatting the final prompt.
// @fnv 0x0095e6f0
void Actor::FUN_0095e6f0(int action)
{
    if (!action)
        return;
    InventoryItem* item = GetProcess()->FindEntryForObject();
    {
        TESObjectWEAP* weapon = item ? dynamic_cast<TESObjectWEAP*>(item->GetObject()) : 0;
        if (!weapon)
        {
            ShowMessageBox(g_011d2748.FUN_00403df0(), 0, 0, FUN_0095e900, 1, 23, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                         0);
            return;
        }
        if (weapon->GetUnk15C() != 45 && weapon->GetUnk15C() != 38)
        {
            ShowMessageBox(g_011d2748.FUN_00403df0(), 0, 0, FUN_0095e900, 1, 23, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                         0);
            return;
        }
        if (item->FUN_004bdcc0())
        {
            ShowMessageBox(g_011d2814.FUN_00403df0(), 0, 0, FUN_0095e900, 1, 23, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                         0);
            return;
        }
        selectedAction = action;
        char szPrompt[256];
        sprintf(szPrompt, DAT_0108b3b4, g_011d4e94.FUN_00403df0(), weapon->fullName.GetFullName());
        ShowMessageBox(szPrompt, 0, 0, FUN_0095e900, 2, 23, 0.0f, 0.0f, g_011d34f8.FUN_00403df0(),
                     g_011d3684.FUN_00403df0(), 0);
    }
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);
class BookComparison : public TESObjectBOOK
{
  public:
    bool FUN_00514f50(TESForm* other);
    bool FUN_00485270(TESForm* other);
    BookData* FUN_00514f30();
};

// Returns true if other is not a TESObjectBOOK or if FUN_00485270 or the BookData comparison is nonzero.
// @fnv 0x00514f50
bool BookComparison::FUN_00514f50(TESForm* other)
{
    TESObjectBOOK* book = dynamic_cast<TESObjectBOOK*>(other);
    if (!book)
        return true;
    if (FUN_00485270(book))
        return true;
    if (_memcmp(&Data, static_cast<BookComparison*>(book)->FUN_00514f30(), sizeof(BookData)))
        return true;
    return false;
}
