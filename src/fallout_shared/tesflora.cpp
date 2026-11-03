
// src/fallout_shared/tesflora.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesflora.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00477f20
{
    void FUN_00477f20();
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
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
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0048b5c0_shell
{
    void FUN_0048b5c0();
};

struct FUN_00508920_obj
{
    void FUN_00508920();
};

// @fnv 0x00508920
void FUN_00508920_obj::FUN_00508920()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00487010();
    reinterpret_cast<S_0048a520*>(reinterpret_cast<char*>(this) + 0x3c)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<S_0048cca0*>(reinterpret_cast<char*>(this) + 0x5c)->FUN_0048cca0();
    reinterpret_cast<S_00477f20*>(reinterpret_cast<char*>(this) + 0x68)->FUN_00477f20();
    reinterpret_cast<FUN_0048b5c0_shell*>(reinterpret_cast<char*>(this) - 0xc)->FUN_0048b5c0();
    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct TESForm
{
    virtual void f00();
};
struct FUN_005e78f0_t : TESForm
{
    void FUN_004851b0(TESForm*);
};
struct TESFlora : FUN_005e78f0_t
{
    void FUN_00508990(TESForm*);
};
// @fnv 0x00508990
void TESFlora::FUN_00508990(TESForm* apCopy)
{
    TESFlora* pcopy = dynamic_cast<TESFlora*>(apCopy);
    if (!pcopy)
        return;
    FUN_004851b0(apCopy);
}

void __cdecl Deallocate(void*);
struct FUN_00508510_shell
{
    void __thiscall FUN_00508510();
};
struct FUN_00508dc0_shell
{
    void* __thiscall FUN_00508dc0(unsigned int flags);
};
// Calls FUN_00508510 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00508dc0
void* __thiscall FUN_00508dc0_shell::FUN_00508dc0(unsigned int flags)
{
    ((FUN_00508510_shell*)this)->FUN_00508510();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct S_005085b0_Sec;
struct S_005085b0_Prim
{
    virtual void vf00();
    int unk04;
    int unk08;
    void ResolveIngredient(S_005085b0_Sec* s);
};
struct S_005085b0_Sec
{
    int unk00;
    unsigned char FUN_004013e0();
    void FUN_00510770();
    void FUN_00484ab0(int flag);
    void FUN_005085b0();
};
struct S_005085b0_D : S_005085b0_Prim, S_005085b0_Sec
{
};
// If FUN_004013e0 returns 0, calls FUN_00510770, invokes ResolveIngredient on the containing object, then FUN_00484ab0(1).
// @fnv 0x005085b0
void S_005085b0_Sec::FUN_005085b0()
{
    if (FUN_004013e0() != 0)
    {
        return;
    }
    FUN_00510770();
    ((S_005085b0_D*)((char*)this - 0xc))->ResolveIngredient((S_005085b0_D*)((char*)this - 0xc));
    FUN_00484ab0(1);
}

extern "C" void* __cdecl _alloca(unsigned int uiSize);

struct FloraFile
{
    unsigned int GetField25C();
    int FUN_004726b0();
    bool FUN_004726f0();
    void GetChunkData(void* pvBuffer, unsigned int uiSize);
    void ReadChunkInt(unsigned int* puiFormID);
    unsigned short FUN_00403570();
};

struct FloraProduce
{
    virtual void p00();
    int unk04, unk08;
    void FUN_006ecd40(unsigned int auiFormId);
    void CopyFromSource(void* pvData);
};

struct FloraFormBase;
struct FloraFullName
{
    int unk00, unk04, unk08;
};
struct FloraModel
{
    int unk00[8];
    void LoadTextureSwapList(char* pcData, unsigned int uiSize, unsigned short usVersion);
};
struct FloraScript
{
    int unk00, unk04, unk08;
    void FUN_006ecd40(unsigned int auiFormId);
    void FUN_0048cd90(FloraFormBase* pkOwner);
};
struct FloraDestructible
{
    int unk00;
};

void __cdecl ReadFullName(FloraFullName* pkFullName, FloraFile* pkFile);
void __cdecl FUN_004892d0(FloraModel* pkModel, FloraFile* pkFile);
void __cdecl FUN_004781e0(FloraDestructible* pkDestructible, FloraFile* pkFile);

struct FloraFormBase
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();

    virtual void LoadBounds(FloraFile* pkFile);
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void SetEditorID(const char* pcEditorID);
    int unk04[0x2c / 4];

    void CallWithThis(FloraFile* pkFile);
    void FUN_00484ab0(int i);
    virtual bool FUN_00508610(FloraFile* pkFile) = 0;
};

struct FloraFull : FloraProduce, FloraFormBase, FloraFullName, FloraModel, FloraScript, FloraDestructible
{
    virtual bool FUN_00508610(FloraFile* pkFile);
};

// Reads chunk records from pkFile, dispatching each chunk tag to the matching loader and returning true.
// @fnv 0x00508610
bool FloraFull::FUN_00508610(FloraFile* pkFile)
{
    FloraFormBase::CallWithThis(pkFile);
    FloraFormBase::FUN_00484ab0(0);
    int iChunk;
    while ((iChunk = pkFile->FUN_004726b0()) != 0)
    {
        switch (iChunk)
        {
        case 0x44494445: {
            char* pcEditorID = (char*)_alloca(pkFile->GetField25C());
            pkFile->GetChunkData(pcEditorID, 0x200);
            SetEditorID(pcEditorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(pkFile);
            break;
        case 0x4c4c5546:
            ReadFullName(this, pkFile);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            FUN_004892d0(this, pkFile);
            break;
        case 0x53444f4d: {
            unsigned int uiSizeX = pkFile->GetField25C();
            char* pcDataZ = (char*)_alloca(uiSizeX);
            pkFile->GetChunkData(pcDataZ, uiSizeX);
            FloraModel::LoadTextureSwapList(pcDataZ, uiSizeX, pkFile->FUN_00403570());
            break;
        }
        case 0x49524353: {
            unsigned int uiScript = 0;
            pkFile->ReadChunkInt(&uiScript);
            FloraScript::FUN_006ecd40(uiScript);
            FloraScript::FUN_0048cd90(this);
            break;
        }
        case 0x47494650: {
            unsigned int uiIngredient = 0;
            pkFile->ReadChunkInt(&uiIngredient);
            FloraProduce::FUN_006ecd40(uiIngredient);
            break;
        }
        case 0x43504650: {
            int m_ucSortOrder;
            pkFile->GetChunkData(&m_ucSortOrder, 4);
            FloraProduce::CopyFromSource(&m_ucSortOrder);
            break;
        }
        case 0x44545344:
        case 0x54534544:
            FUN_004781e0(this, pkFile);
            break;
        }
        if (!pkFile->FUN_004726f0())
            break;
    }
    return true;
}

extern int DAT_01183028;
extern int DAT_01189f7c;

void* __cdecl FUN_00ec43fb(void* apObject, long alDelta, void* apSourceType, void* apTargetType, long abFlag);

struct FUN_005089d0_cls
{
    bool FUN_00485270(void* apChild);
    bool FUN_005089d0(void* apObject);
};

// @fnv 0x005089d0
bool FUN_005089d0_cls::FUN_005089d0(void* apObject)
{
    void* pFound;
    pFound = FUN_00ec43fb(apObject, 0, &DAT_01183028, &DAT_01189f7c, 0);
    if (pFound == 0)
    {
        return true;
    }
    if (FUN_00485270(pFound != 0 ? (char*)pFound + 0xc : 0))
    {
        return true;
    }
    return false;
}
