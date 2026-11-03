
// src/fallout_shared/tesproduceform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesproduceform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl memset(void* p, int c, unsigned int n);

struct FUN_0048b590_shell
{
    void ClearFields();
};

// Sets the int at offset 4 to 0 and zeroes the 4 bytes at offset 8 of this object.
// @fnv 0x0048b590
void FUN_0048b590_shell::ClearFields()
{
    *(reinterpret_cast<int*>(this) + 1) = 0;
    memset(reinterpret_cast<char*>(this) + 8, 0, 4);
}

extern "C" void* __cdecl __memcpy(void* dst, const void* src, unsigned int count);

struct FUN_0048b670_shell
{
    void CopyFromSource(void* src);
};

// Copies 4 bytes from src into this object at offset 8 when src is non-null.
// @fnv 0x0048b670
void FUN_0048b670_shell::CopyFromSource(void* pSource)
{
    if (pSource)
        __memcpy((char*)this + 8, pSource, 4);
}

void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
void __cdecl _FUN_00485910(unsigned int, unsigned int);
struct RefObj0084e3a0
{
    unsigned int _ref_0084e3a0();
};
struct FUN_0048b5c0_shell
{
    int unk0;
    RefObj0084e3a0* unk4;
    int unk8;
    void FUN_0048b5c0();
};
// @fnv 0x0048b5c0
void FUN_0048b5c0_shell::FUN_0048b5c0()
{
    unsigned int tmp;
    if (unk4 != 0)
    {
        tmp = unk4->_ref_0084e3a0();
        _FUN_00485910(0x47494650, tmp);
    }
    FUN_004856f0(0x43504650, &unk8, 4);
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct TESProduceForm : BaseFormComponent
{
    void FUN_0048b610(BaseFormComponent* apCopyFC);
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct CombatNode
{
    unsigned int FUN_00726070();
};
// Casts apCopyFC to TESProduceForm, initializes this from its combat node value, then copies the data at offset 8.
// @fnv 0x0048b610
void TESProduceForm::FUN_0048b610(BaseFormComponent* apCopyFC)
{
    TESProduceForm* pCopy = dynamic_cast<TESProduceForm*>(apCopyFC);
    if (!pCopy)
        return;
    ((TESRaceForm*)this)->Initialize(((CombatNode*)pCopy)->FUN_00726070());
    ((FUN_0048b670_shell*)this)->CopyFromSource((void*)((char*)pCopy + 8));
}

extern "C" int __cdecl memcmp(const void* a, const void* b, unsigned int n);
struct ProduceFormData : BaseFormComponent
{
    void* pIngredient;
    unsigned char cProdChance[4];
    bool FUN_0048b6a0(BaseFormComponent* apOther);
};

// Compares production chance bytes and a value from FUN_00726070 against another component, returning true when they differ or the other is not a TESProduceForm.
// @fnv 0x0048b6a0
bool ProduceFormData::FUN_0048b6a0(BaseFormComponent* apOther)
{
    ProduceFormData* pOther = (ProduceFormData*)dynamic_cast<TESProduceForm*>(apOther);
    if (!pOther)
        return true;
    if (((CombatNode*)this)->FUN_00726070() != ((CombatNode*)pOther)->FUN_00726070())
        return true;
    if (memcmp(cProdChance, pOther->cProdChance, 4))
        return true;
    return false;
}

struct TESFile;

struct FUN_00485b60_Cls
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
    TESFile* GetFile(int aIndex);
    int HasNameForWarning();
    unsigned int Deallocate();
};

void ResolveFormID(unsigned int* apFormID, TESFile* apFile);
struct TESForm;
TESForm* LookupFormByID(unsigned int aFormID);
void FNV_Warning(const char* apMsg, ...);

extern const char DAT_0101d2b4[];
extern const char DAT_0101d2f8[];
extern const char DAT_0101d340[];

struct TESForm
{
    virtual ~TESForm();
};

struct IngredientItem : TESForm
{
    int m_04;
};

struct FUN_0048b720_Cls : ProduceFormData
{
    void ResolveIngredient(FUN_00485b60_Cls* apArg);
};

// Resolves pIngredient's form ID through the file, re-looks it up as an IngredientItem, and warns if the lookup fails.
// @fnv 0x0048b720
void FUN_0048b720_Cls::ResolveIngredient(FUN_00485b60_Cls* apArg)
{
    if (pIngredient != 0)
    {
        unsigned int formID = (unsigned int)pIngredient;
        ResolveFormID(&formID, apArg->GetFile(-1));
        pIngredient = dynamic_cast<IngredientItem*>(LookupFormByID(formID));
        if (pIngredient == 0)
        {
            if (apArg != 0)
            {
                if (apArg->HasNameForWarning())
                {
                    FNV_Warning(DAT_0101d340, formID, apArg->v76());
                }
                else
                {
                    FNV_Warning(DAT_0101d2f8, formID, apArg->Deallocate());
                }
            }
            else
            {
                FNV_Warning(DAT_0101d2b4, formID);
            }
        }
    }
}
