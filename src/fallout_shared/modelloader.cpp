// fallout_shared/modelloader.cpp: DelStandIn, QueuedTreeModel, ModelLoader, QueuedHelmet and more (493 functions)

#include "modelloader_verified_packet.h"

// @fnv 0x00441800
void QueuedCharacter::Attach()
{
    QueuedReference::Attach();
}

// @fnv 0x00441c30
void QueuedPlayer::Attach()
{
    QueuedCharacter::Attach();
}

// Returns the archive's file index plus 4 when the queued texture's archive is found, otherwise 0.
// @fnv 0x0043bfe0
unsigned char QueuedTexture::GetFileIndex()
{
    if (SetLocRef())
    {
        Archive* archive = ArchiveManager::FindArchiveForFileEntry(SetLocRef(), static_cast<ARCHIVE_TYPE>(2));
        if (archive)
            return archive->FindArchiveForFileEntry() + 4;
    }
    return 0;
}

// Returns the archive's file index plus 4 when the archive is found, otherwise returns 1.
// @fnv 0x006fc440
unsigned char BGSTerrainChunkLoadTask::GetFileIndex()
{
    if (SetLocRef())
    {
        Archive* archive = ArchiveManager::FindArchiveForFileEntry(SetLocRef(), static_cast<ARCHIVE_TYPE>(1));
        if (archive)
            return archive->FindArchiveForFileEntry() + 4;
    }
    return 1;
}

// @fnv 0x00446500
void ModelLoader::QueueFileList(BSSimpleList<const char*>* pFileList, IO_TASK_PRIORITY priority, QueuedFile* queuedFile,
                                const char* prefix)
{
    BSSimpleList<const char*>* current = pFileList;
    while (current)
    {
        const char* fileName = current->GetItem();
        if (fileName)
        {
            QueueKFListLocals locals;
            locals.pathToQueue = fileName;
            if (prefix)
            {
                TaskQueueInterface::CopyStringToBuffer(locals.path, sizeof(locals.path), prefix);
                strcat_s(locals.path, sizeof(locals.path), fileName);
                locals.pathToQueue = locals.path;
            }
            EnqueueFile(locals.pathToQueue, priority, queuedFile);
            locals.deletePointer = const_cast<char*>(fileName);
            operator delete(locals.deletePointer);
            current->RemoveHead();
        }
        else
        {
            current = reinterpret_cast<BSSimpleList<const char*>*>(
                reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current)->GetNext());
        }
    }
}

// If the NiPointer<QueuedFile> at offset 0xC is null, calls Signal on the object at that offset.
// @fnv 0x00442600
void ModelLoader::ProcessQueuedFile()
{
    if (!reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0xC)->operator QueuedFile*())
        reinterpret_cast<CountingSemaphore*>(reinterpret_cast<char*>(this) + 0xC)->Signal();
}

// @fnv 0x0043aaf0
Model::Model(const char* fileName, BSStream* stream, bool firstFlag, bool secondFlag) : node(0)
{
    node = 0;
    LoadModelFromStream(fileName, stream, firstFlag, secondFlag);
}

// Clears node, then deletes the owned data pointer and leaves owned unchanged.
// @fnv 0x0043ab70
Model::~Model()
{
    node = 0;
    void* pOwnedData = owned;
    operator delete(pOwnedData);
}

// @fnv 0x00446e30
void ModelLoader::UpdateLoadingStatusCallback()
{
    g_modelLoader->UpdateLoadingStatus();
}

// @fnv 0x0043ca10
void QueuedModel::GenerateKey()
{
    FUN_00c3d440();
}

// Calls virtual method vfn_48 on DAT_01202d98, passing this.
// @fnv 0x00441e10
void QueuedKF::DispatchToManager()
{
    DAT_01202d98->vfn_48(this);
}

// @fnv 0x0043e770
void QueuedAnimIdle::OnChildCompletion()
{
    if (FUN_00449110() && FUN_0043caa0())
        AddToPostProcessQueue();
}

// @fnv 0x0043ec20
void QueuedHead::DispatchToManager()
{
    BSFaceGenManager::QueueHeadModelLoad(*reinterpret_cast<TESNPC**>(reinterpret_cast<char*>(this) + 0x28),
                                         FUN_0043cc60(), this);
    vfn_28();
}

// Retrieves the spell list from the TESSpellList at offset 0x34 and passes it to vfn_30.
// @fnv 0x0043cb10
void QueuedModel::DispatchToManager()
{
    BSSimpleList<InventoryStackRecord*>* list = 0;
    if (*reinterpret_cast<TESSpellList**>(reinterpret_cast<char*>(this) + 0x34))
        list = (*reinterpret_cast<TESSpellList**>(reinterpret_cast<char*>(this) + 0x34))->GetOffsetC();
    vfn_30(list);
}

// @fnv 0x0043ec60
void QueuedHead::OnChildCompletion()
{
    if (FUN_0043caa0())
    {
        if (reinterpret_cast<NiTPointerMap<unsigned int, SoundPlaybackHandle*>*>(this)->IsEmpty())
            DAT_01202d98->vfn_48(this);
        else
            NotifyParents();
    }
}

// @fnv 0x0043e7b0
void QueuedAnimIdle::ProcessLoadedAnimIdle()
{
    if (reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x30)->operator QueuedFile*() &&
        !FUN_00449130())
        reinterpret_cast<AnimIdle*>(
            reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x3c)->operator QueuedFile*())
            ->Loaded(reinterpret_cast<KFModel*>(
                reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x30)
                    ->
                    operator QueuedFile*()));
    g_modelLoader->DispatchAnimIdle(
        reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x3c)->operator QueuedFile*());
}

// @fnv 0x004489b0
void ModelLoader::UpdateReferenceNode(TESObjectREFR* reference, NiNode* node)
{
    if (node)
    {
        NiExtraData* extra = node->GetExtraData(FUN_00448a80());
        if (extra && reference)
        {
            NiExtraData* addon = extra;
            if (addon->FUN_00448a40() && !reference->FUN_00448a20())
                UpdateModelNode(node);
        }
    }
}

// @fnv 0x0043ca30
void QueuedModel::OnChildCompletion()
{
    if (!FUN_0043caf0())
        NotifyParents();
    else if (FUN_0043caa0())
    {
        if (reinterpret_cast<NiTPointerMap<unsigned int, SoundPlaybackHandle*>*>(this)->IsEmpty())
            DAT_01202d98->vfn_48(this);
        else
            NotifyParents();
    }
}

// @fnv 0x0043c4b0
NiRenderer* FUN_0043c4b0()
{
    return NiRenderer::ms_pRenderer;
}

// @fnv 0x00448a80
const NiFixedString& FUN_00448a80()
{
    return *DAT_01202ddc;
}

// @fnv 0x0043c490
NiPoint3& NiAVObject::FUN_0043c490()
{
    return *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x58);
}

// @fnv 0x0043c470
int NiAVObject::FUN_0043c470()
{
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3);
}

// @fnv 0x00441b80
void QueuedReference::FUN_00441b80()
{
    FUN_004414f0();
}

// @fnv 0x004431d0
void ModelLoader::FUN_004431d0()
{
    FUN_00449940();
}

// @fnv 0x00443220
void ModelLoader::FUN_00443220()
{
    FUN_004499a0();
}

// @fnv 0x004491f0
NiNode* NiAVObject::GetParentNode()
{
    return GetParent();
}

// @fnv 0x0043cca0
unsigned char IOTask::GetPriorityFromKey(__int64& key)
{
    return static_cast<unsigned char>(key >> 16);
}

// @fnv 0x00448a40
bool BSXFlags::GetAddon() const
{
    return GetFlags(0x10) != 0;
}

// @fnv 0x00444d20
bool BGSSaveLoadGame::GetInitingForms() const
{
    return (m_uiInitializationFlags & 8) ? true : false;
}

// Returns the TESBipedModelForm for an ARMO, ARMA or CLOT form, or null for other or null forms.
// @fnv 0x00480db0
TESBipedModelForm* TESBipedModelForm::GetFormAsBipedModel(const TESForm* form)
{
    TESBipedModelForm* biped = 0;
    if (form)
    {
        switch (form->GetFormType())
        {
        case ENUM_FORM_ID_ARMO_ID: {
            TESObjectARMO* armor = static_cast<TESObjectARMO*>(const_cast<TESForm*>(form));
            biped = armor ? &armor->bipedModel : 0;
            break;
        }
        case ENUM_FORM_ID_ARMA_ID: {
            TESObjectARMA* addon = static_cast<TESObjectARMA*>(const_cast<TESForm*>(form));
            biped = addon ? &addon->bipedModelForm : 0;
            break;
        }
        case ENUM_FORM_ID_CLOT_ID: {
            TESObjectCLOT* clothing = static_cast<TESObjectCLOT*>(const_cast<TESForm*>(form));
            biped = clothing ? &clothing->bipedModel : 0;
            break;
        }
        }
    }
    return biped;
}

// @fnv 0x00448bf0
bool BGSAddonNode::IsMasterParticleSystem() const
{
    // Character-type inspection of the real one-byte bitfield object.
    return (*reinterpret_cast<const unsigned char*>(&kData.m_ucEntryType) & _AddonNodeFlags::IS_MASTER_PARTICLE_SYSTEM)
               ? true
               : false;
}

// @fnv 0x00441b00
bool TESPackage::GetForceUnequipWeapon() const
{
    return (packageFlags & kPackageFlag_WeaponsUnequipped) ? true : false;
}

// @fnv 0x00446390
WEAPON_TYPE TESObjectWEAP::GetWeaponType() const
{
    return static_cast<WEAPON_TYPE>(static_cast<signed char>(eWeaponType));
}

// @fnv 0x00442a80
void TESObjectACTI::SetActivateSound(TESSound* sound)
{
    activationSound = sound;
}

template <typename T> class BSStringT
{
  public:
    bool Set(const char*, unsigned int);
};

int __cdecl FUN_00407000(char*, const char*, char*);

struct FUN_00406f90_this : public BSStringT<char>
{
    int FUN_00406f90(const char* fmt, char* args);
};

// Formats fmt with args into a 1024-byte buffer via FUN_00407000, stores the result in the string, and returns the formatting result.
// @fnv 0x00406f90
int FUN_00406f90_this::FUN_00406f90(const char* pcFormat, char* args)
{
    int res = 0;
    char buf[1024];

    res = FUN_00407000(buf, pcFormat, args);
    Set(buf, 0);
    return res;
}

struct FUN_0043acb0_shell : public Model
{
    void ReleaseScriptRunLock();
};

void __cdecl FinishScriptRunLock(void*);

// If the reference count at offset 8 is positive, calls FinishScriptRunLock with that field's address.
// @fnv 0x0043acb0
void FUN_0043acb0_shell::ReleaseScriptRunLock()
{
    if (*(int*)((char*)this + 8) > 0)
        FinishScriptRunLock((char*)this + 8);
}

namespace fnv_0043b1b0 {
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
struct FUN_0043b1b0_shell : public NiFixedString
{
    void FUN_0043b1b0();
};

void __cdecl FUN_0043b1d0(void*);

// @fnv 0x0043b1b0
void FUN_0043b1b0_shell::FUN_0043b1b0()
{
    FUN_0043b1d0(this);
}
}  // namespace fnv_0043b1b0

int __fastcall _ref_0084e3a0(const void*);

// @fnv 0x0043b1e0
int __fastcall GetRefAt21C(const char* pThis)
{
    return _ref_0084e3a0(pThis + 0x21c);
}

struct BSStringT_char
{
    operator const char*() const;
};
struct BSSimpleArray_uint_1024
{
    BSStringT_char& GetAt(unsigned int);
};
struct MLx
{
    char pad[0x21c];
    BSSimpleArray_uint_1024 arr;
    const char* GetStringAt(unsigned int i);
};
// Returns the string stored at index i in the arr array.
// @fnv 0x0043b200
const char* MLx::GetStringAt(unsigned int auiIndex)
{
    return arr.GetAt(auiIndex);
}

namespace fnv_0043b230 {
template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x0043b230
const char* __fastcall FUN_0043b230(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x0c);
}
}  // namespace fnv_0043b230

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_0043b4d0_shell : public CFilter
{
    int FUN_0043b4d0();
};

// @fnv 0x0043b4d0
int FUN_0043b4d0_shell::FUN_0043b4d0()
{
    return iFilter & 0x7f;
}

struct FormChangeMask
{
    int v;
    FormChangeMask(int);
};
struct Col_0043b4f0
{
    int FUN_0043b540();
};
struct W_0043b4f0
{
    Col_0043b4f0* GetSourceFilesFromObject();
    FormChangeMask FUN_0043b4f0();
};
// @fnv 0x0043b4f0
FormChangeMask W_0043b4f0::FUN_0043b4f0()
{
    Col_0043b4f0* pc = GetSourceFilesFromObject();
    return FormChangeMask(pc ? pc->FUN_0043b540() : 0);
}

struct hkpTypedBroadPhaseHandle
{
    unsigned int FUN_0044ddc0();
};

// @fnv 0x0043b540
unsigned int __fastcall FUN_0043b540(char* pThis)
{
    return ((hkpTypedBroadPhaseHandle*)(pThis + 0x14))->FUN_0044ddc0();
}

struct BSFile;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
typedef char _sizecheck_LoadedFile[sizeof(LoadedFile) == 16 ? 1 : -1];
struct FUN_0043bb80_shell : public LoadedFile
{
    void DestroyLoadedFile();
};

struct BSFile
{
    virtual ~BSFile();
};

struct _ModelLoaderStub00448370
{
    void FUN_00448370(char*);
};

struct _LogStub0043bd00
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int, const char*, int, int, int);
};

void __cdecl _FNV_Warning(const char*, ...);
int __cdecl _sprintf(char*, const char*, ...);
bool __cdecl IsHeapLoggerPresent();
_LogStub0043bd00* __cdecl FUN_0043bd00();

// @fnv 0x0043bb80
void FUN_0043bb80_shell::DestroyLoadedFile()
{
    if (!m_bFileFlagAtOffsetD && m_bFirstFlag)
    {
        _FNV_Warning("LoadedFile %s was loaded at %i and added to the map, but is being thrown away without being used",
                     pFileName, this);
    }
    if (m_bFirstFlag)
    {
        reinterpret_cast<_ModelLoaderStub00448370*>(g_modelLoader)->FUN_00448370(pFileName);
    }
    if (*reinterpret_cast<int*>(this) != 0)
    {
        char szMessage[260];
        _sprintf(szMessage, "%s ref object at mem %i being destroyed with %i references\r\n", pFileName, this,
                 *reinterpret_cast<int*>(this));
        if (IsHeapLoggerPresent())
        {
            FUN_0043bd00()->vfn_14(4, szMessage, 0, 0, 0);
        }
    }
    delete pFileName;
    delete pFile;
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0043be10
int __fastcall FUN_0043be10(char* pThis)
{
    return InitScriptRunLock(pThis + 0x10);
}

struct GO
{
    GO(int);
    ~GO();
    int v;
};
struct QBase
{
    QBase(int);
    virtual ~QBase();
    char pad[0x2c];
};
struct FUN_0043bef0 : QBase
{
    GO g;
    char flag;
    FUN_0043bef0(NiNode* n, int a);
    virtual ~FUN_0043bef0();
    void SetFieldCToFive();
};
// @fnv 0x0043bef0
FUN_0043bef0::FUN_0043bef0(NiNode* apNode, int aiArg) : QBase(aiArg), g(0)
{
    flag = 0;
    ((NiPointer<NiNode>*)&g)->operator=(apNode);
    SetFieldCToFive();
}

struct IOV_0043c050
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void Slot(void*);
};
struct ML_0043c050
{
    bool InsertQueuedTexture(BSFileEntry*, void*);
    bool IsLoadTexturesDegraded();
};
struct Q_0043c050 : public QueuedTexture
{
    bool ForwardByteToMember(bool);
    void FUN_0043c100(bool);
    void FUN_0043c050();
};
// @fnv 0x0043c050
void Q_0043c050::FUN_0043c050()
{
    if (SetLocRef())
    {
        bool bresult = reinterpret_cast<ML_0043c050*>(g_modelLoader)->InsertQueuedTexture(SetLocRef(), this);
        FUN_0043c100(bresult);
    }
    if (reinterpret_cast<ML_0043c050*>(g_modelLoader)->IsLoadTexturesDegraded())
        ForwardByteToMember(true);
    reinterpret_cast<IOV_0043c050*>(DAT_01202d98)->Slot(this);
}

struct FUN_0043c100_shell : public QueuedTexture
{
    void FUN_0043c100(bool);
};

void __cdecl FUN_0044aea0(bool, void*);

// Forwards abValue and the object's field at offset 0x34 to FUN_0044aea0.
// @fnv 0x0043c100
void FUN_0043c100_shell::FUN_0043c100(bool abValue)
{
    FUN_0044aea0(abValue, reinterpret_cast<char*>(this) + 0x34);
}

struct FUN_0043c130_shell : public ModelLoader
{
    bool IsLoadTexturesDegraded();
};

struct TLSData
{
    char _pad[0x25c];
    bool bLoadTexturesDegraded;
};

__declspec(thread) TLSData g_tlsData;

// Returns the thread-local flag that indicates whether textures are being loaded in degraded mode.
// @fnv 0x0043c130
bool FUN_0043c130_shell::IsLoadTexturesDegraded()
{
    return g_tlsData.bLoadTexturesDegraded;
}

struct FUN_0043c3d0_shell : public QueuedTexture
{
    bool FUN_0043c3d0();
};

bool __cdecl FUN_0044ae50(unsigned char);

// @fnv 0x0043c3d0
bool FUN_0043c3d0_shell::FUN_0043c3d0()
{
    return FUN_0044ae50(*(unsigned char*)((char*)this + 0x34));
}

struct _TLS_0043c3f0
{
    char _pad[0x29c];
    unsigned int val;
};
extern __declspec(thread) _TLS_0043c3f0 _tls_0043c3f0;

// @fnv 0x0043c3f0
void __cdecl FUN_0043c3f0(unsigned int aiLoadMethod)
{
    _tls_0043c3f0.val = aiLoadMethod;
}

// @fnv 0x0043c410
int FUN_0043c410()
{
    static __declspec(thread) int tls_data[0x29c / 4 + 1];
    return tls_data[0x29c / 4];
}

class BSFileEntryMap
{
  public:
    void FUN_0043c4f0(NiNode*, NiPointer<NiNode>&);
};
BSFileEntryMap* DAT_011f4468;

// @fnv 0x0043c4c0
void GetNodePointer(NiNode* apNode, NiPointer<NiNode>& apNodePtr)
{
    apNodePtr = 0;
    DAT_011f4468->FUN_0043c4f0(apNode, apNodePtr);
}

int __cdecl FUN_0043c530(int);

struct FUN_0043c4f0_shell
{
    void GetByKey(int, int, int);
    void FUN_0043c4f0(int a1, int a2);
};

// Computes a value from a1 via FUN_0043c530, then calls GetByKey with that value, a1 and a2.
// @fnv 0x0043c4f0
void FUN_0043c4f0_shell::FUN_0043c4f0(int a1, int aiArg)
{
    int v = FUN_0043c530(a1);
    GetByKey(v, a1, aiArg);
}

// @fnv 0x0043c530
unsigned int __cdecl FUN_0043c530(unsigned int uiValue)
{
    return (uiValue >> 4) % 1001;
}

struct FUN_0043c610_shell : public QueuedFile
{
    void RunVirtualMethod28();
};

// @fnv 0x0043c610
void FUN_0043c610_shell::RunVirtualMethod28()
{
    (*(void(__thiscall**)(QueuedFile*))(*(int*)this + 0x28))(this);
}

struct FUN_0043c630_shell : public QueuedTexture
{
    bool FUN_0043c630();
};

bool __cdecl FUN_0044ae90(unsigned char);

// @fnv 0x0043c630
bool FUN_0043c630_shell::FUN_0043c630()
{
    return FUN_0044ae90(*((unsigned char*)this + 0x34));
}

void __cdecl SetFlagBit0(unsigned char, void*);

struct FUN_0043c7a0_arg
{
    unsigned char val;
};

// Passes arg.val and the address pThis+0x3c to SetFlagBit0.
// @fnv 0x0043c7a0
void __fastcall FUN_0043c7a0(char* pThis, FUN_0043c7a0_arg aByteArg)
{
    SetFlagBit0(aByteArg.val, pThis + 0x3c);
}

void __cdecl FUN_0044ae60(unsigned char, void*);

struct FUN_0043c7d0_shell
{
    void FUN_0043c7d0(unsigned char param_1);
};

// @fnv 0x0043c7d0
void FUN_0043c7d0_shell::FUN_0043c7d0(unsigned char aByte)
{
    FUN_0044ae60(aByte, (char*)this + 0x3c);
}

void __fastcall FUN_0044b160(void*);
void __fastcall FUN_00c3cea0(void*);

struct _Base_00441d20
{
    char _pad[0x30];
    ~_Base_00441d20()
    {
        FUN_00c3cea0(this);
    }
};

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        FUN_0044b160(this);
    }
};

struct FUN_0043c830 : _Base_00441d20
{
    _Mem_00441d20 m;
    int b;
    ~FUN_0043c830();
};

// Destructor for FUN_0043c830; destroys its _Mem_00441d20 member and _Base_00441d20 base.
// @fnv 0x0043c830
FUN_0043c830::~FUN_0043c830()
{}

struct FUN_0043caa0_shell : public QueuedFile
{
    bool FUN_0043caa0();
};

unsigned int __fastcall FUN_0044ddc0(void*);
unsigned int __fastcall FUN_0044edb0(void*);

// @fnv 0x0043caa0
bool FUN_0043caa0_shell::FUN_0043caa0()
{
    return *(void**)((char*)this + 0x20)
               ? FUN_0044ddc0(*(void**)((char*)this + 0x20)) == FUN_0044edb0(*(void**)((char*)this + 0x20))
               : true;
}

struct FUN_0043caf0_shell : public QueuedModel
{
    bool FUN_0043caf0();
};

bool __cdecl FUN_0044ae90(unsigned char);

// @fnv 0x0043caf0
bool FUN_0043caf0_shell::FUN_0043caf0()
{
    return FUN_0044ae90(*((unsigned char*)this + 0x3c));
}

struct FUN_0043cc60_shell : public IOTask
{
    int FUN_0043cc60();
};

unsigned char __fastcall FUN_0043cc80(void*);

// @fnv 0x0043cc60
int FUN_0043cc60_shell::FUN_0043cc60()
{
    return FUN_0043cc80(this);
}

struct FUN_0043cc80_shell : public IOTask
{
    unsigned char FUN_0043cc80();
};

// @fnv 0x0043cc80
unsigned char FUN_0043cc80_shell::FUN_0043cc80()
{
    return GetPriorityFromKey(*(__int64*)((char*)this + 0x10));
}

struct FUN_0043ccc0_shell : public QueuedModel
{
    void FUN_0043ccc0(bool);
};

void __cdecl FUN_0044aea0(bool, void*);

// Passes abValue and the address of the object's 0x3c offset to FUN_0044aea0.
// @fnv 0x0043ccc0
void FUN_0043ccc0_shell::FUN_0043ccc0(bool abValue)
{
    FUN_0044aea0(abValue, (char*)this + 0x3c);
}

struct FUN_0043cf40_shell : public QueuedModel
{
    bool FUN_0043cf40();
};

bool __cdecl FUN_0044ae10(unsigned char);

// @fnv 0x0043cf40
bool FUN_0043cf40_shell::FUN_0043cf40()
{
    return FUN_0044ae10(*((unsigned char*)this + 0x3c));
}

struct FUN_0043cf60_shell : public QueuedModel
{
    void FUN_0043cf60(bool);
};

void __cdecl SetFlag8(bool, void*);

// @fnv 0x0043cf60
void FUN_0043cf60_shell::FUN_0043cf60(bool abValue)
{
    SetFlag8(abValue, (char*)this + 0x3c);
}

struct FUN_0043cf90_shell : public QueuedModel
{
    bool FUN_0043cf90();
};

bool __cdecl FUN_0044af60(unsigned char);

// @fnv 0x0043cf90
bool FUN_0043cf90_shell::FUN_0043cf90()
{
    return FUN_0044af60(*((unsigned char*)this + 0x3c));
}

struct FUN_0043cfb0_shell : public QueuedModel
{
    bool FUN_0043cfb0();
};

bool __cdecl FUN_0044afa0(unsigned char);

// @fnv 0x0043cfb0
bool FUN_0043cfb0_shell::FUN_0043cfb0()
{
    return FUN_0044afa0(*((unsigned char*)this + 0x3c));
}

struct FUN_0043d490_shell : public QueuedModel
{
    bool FUN_0043d490();
};

bool __cdecl FUN_0044ae50(unsigned char);

// @fnv 0x0043d490
bool FUN_0043d490_shell::FUN_0043d490()
{
    return FUN_0044ae50(*((unsigned char*)this + 0x3c));
}

struct FUN_0043d4b0_shell : public QueuedModel
{
    bool FUN_0043d4b0();
};

bool __cdecl FUN_0044af20(unsigned char);

// @fnv 0x0043d4b0
bool FUN_0043d4b0_shell::FUN_0043d4b0()
{
    return FUN_0044af20(*((unsigned char*)this + 0x3c));
}

struct FUN_0043dbb0_shell : public IOTask
{
    void SetRequestParams(char, unsigned int, unsigned char, unsigned short);
};

// Packs file index, offset, priority and counter into a 64-bit value stored at offset 0x10 of this object.
// @fnv 0x0043dbb0
void FUN_0043dbb0_shell::SetRequestParams(char acFileIndex, unsigned int aiOffset, unsigned char acPriority,
                                          unsigned short asCounter)
{
    *reinterpret_cast<__int64*>(reinterpret_cast<char*>(this) + 0x10) =
        (static_cast<__int64>(acFileIndex) << 56) | (static_cast<unsigned __int64>(aiOffset) << 24) |
        (static_cast<__int64>(acPriority) << 16) | static_cast<__int64>(asCounter);
}

namespace fnv_0043dc10 {
struct FUN_0043dc10_shell : public IOTask
{
    unsigned short FUN_0043dc10();
};

unsigned short __cdecl InitScriptRunLock(void*);
extern int DAT_01202d9c;

// @fnv 0x0043dc10
unsigned short FUN_0043dc10_shell::FUN_0043dc10()
{
    return InitScriptRunLock(&DAT_01202d9c);
}
}  // namespace fnv_0043dc10

struct FUN_0043dc30_shell : public IOTask
{
    unsigned int InitScriptRunLockTask();
};

extern int DAT_01202da0;
int __cdecl InitScriptRunLock(void*);

// @fnv 0x0043dc30
unsigned int FUN_0043dc30_shell::InitScriptRunLockTask()
{
    return InitScriptRunLock(&DAT_01202da0);
}

struct EffectSetting;
struct MagicItem;
struct QueuedMagicItem : public QueuedFile
{
    virtual void __vslot_0();
    virtual void DispatchToManager();
    virtual void OnChildCompletion();
    char _pad_4[36];
    MagicItem* pMagicItem;
    EffectSetting* m_pEffectSetting;
};
typedef char _sizecheck_QueuedMagicItem[sizeof(QueuedMagicItem) == 48 ? 1 : -1];
struct FUN_0043e080_shell : public QueuedMagicItem
{
    void ProcessQueuedMagicItem();
};

void __fastcall PreloadModels(MagicItem*);
unsigned int __fastcall FUN_0044ddc0(void*);

struct FUN_0043e080_vdtor
{
    virtual ~FUN_0043e080_vdtor();
};

// @fnv 0x0043e080
void FUN_0043e080_shell::ProcessQueuedMagicItem()
{
    if (reinterpret_cast<IOTask*>(this)->FUN_00449110() && reinterpret_cast<IOTask*>(this)->FUN_0043caa0())
    {
        PreloadModels(pMagicItem);
        if (FUN_0044ddc0(this) == 0)
        {
            delete reinterpret_cast<FUN_0043e080_vdtor*>(this);
        }
    }
}

namespace fnv_0043e1b0 {
void __fastcall FUN_0044b160(void*);
void __fastcall FUN_00c3cea0(void*);

struct _Base_00441d20
{
    char _pad[0x30];
    ~_Base_00441d20()
    {
        FUN_00c3cea0(this);
    }
};

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        FUN_0044b160(this);
    }
};

struct FUN_0043e1b0 : _Base_00441d20
{
    _Mem_00441d20 m;
    int b;
    ~FUN_0043e1b0();
};

// @fnv 0x0043e1b0
FUN_0043e1b0::~FUN_0043e1b0()
{}
}  // namespace fnv_0043e1b0

struct FUN_0043e480_shell : public QueuedKF
{
    void FUN_0043e480(bool);
};

void __cdecl SetFlagBit0(bool, void*);

// @fnv 0x0043e480
void FUN_0043e480_shell::FUN_0043e480(bool abValue)
{
    SetFlagBit0(abValue, (char*)this + 0x34);
}

namespace fnv_0043e4b0 {
struct KFModelLookup
{
    KFModel* Lookup(const char*);
};
struct Tile
{
    Tile* GetParent() const;
};
template <class T> struct BSStringT
{
    operator const T*() const;
};
struct LoaderStandIn : KFModelLookup
{
    unsigned char CallVirtWithLocal(Tile*, const char*);
};
struct QK_0043e4b0 : Tile
{
    char pad[0x30];
    BSStringT<char> name;
    unsigned char FUN_0043e530();
    void RunVirtualMethod28();
    void FUN_0043e4b0();
};
// @fnv 0x0043e4b0
void QK_0043e4b0::FUN_0043e4b0()
{
    if (name && !FUN_0043e530() &&
        !reinterpret_cast<LoaderStandIn*>(g_modelLoader)->CallVirtWithLocal(GetParent(), name))
    {
        reinterpret_cast<NiPointer<KFModel>*>(&name)->operator=(
            reinterpret_cast<LoaderStandIn*>(g_modelLoader)->Lookup(reinterpret_cast<const char*>(GetParent())));
    }
    RunVirtualMethod28();
}
}  // namespace fnv_0043e4b0

struct FUN_0043e530_shell : public QueuedTexture
{
    bool FUN_0043e530();
};

bool __cdecl FUN_0044ae10(unsigned char);

// @fnv 0x0043e530
bool FUN_0043e530_shell::FUN_0043e530()
{
    return FUN_0044ae10(*((unsigned char*)this + 0x34));
}

struct TESObjectANIO;
struct FUN_0043e750_shell : public AnimIdle
{
    TESObjectANIO* GetObjectANIO(int);
};

// @fnv 0x0043e750
TESObjectANIO* FUN_0043e750_shell::GetObjectANIO(int aiIndex)
{
    return ((TESObjectANIO**)((char*)this + 0x1c))[aiIndex];
}

struct FUN_0043e810_shell : public ModelLoader
{
    void DispatchAnimIdle(AnimIdle*);
};

struct Vtbl0043e810
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(AnimIdle*);
};

// Forwards apAnimIdle to the virtual v5 method of the object stored at this+0x10.
// @fnv 0x0043e810
void FUN_0043e810_shell::DispatchAnimIdle(AnimIdle* apAnimIdle)
{
    (*reinterpret_cast<Vtbl0043e810**>(reinterpret_cast<char*>(this) + 0x10))->v5(apAnimIdle);
}

namespace fnv_0043fad0 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x0043fad0
const char* __fastcall FUN_0043fad0(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0xbc);
}
}  // namespace fnv_0043fad0

struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
extern ProcessLists g_011d5a44;

// @fnv 0x0043faf0
unsigned char FUN_0043faf0()
{
    return *g_011d5a44.GetLifeStateControlFlag();
}

struct FUN_00440490_shell : public NiAVObject
{
    void FUN_00440490(float);
};

float __cdecl FUN_00408820(float);

// Stores the result of FUN_00408820(fScale) into the float at offset 0x64 of this object.
// @fnv 0x00440490
void FUN_00440490_shell::FUN_00440490(float fScale)
{
    *(float*)((char*)this + 0x64) = FUN_00408820(fScale);
}

struct FUN_004405b0_S
{
    void FUN_004405d0(unsigned char);
    void FUN_004405b0(unsigned char p);
};
// @fnv 0x004405b0
void FUN_004405b0_S::FUN_004405b0(unsigned char p)
{
    FUN_004405d0(p);
}

struct QR2;
struct BCT
{
    void FUN_00442580(QR2*);
};
struct FUN_004408d0_S
{
    char pad[0x28];
    BCT* t;
    void ForwardToBCT(QR2* q);
};
// @fnv 0x004408d0
void FUN_004408d0_S::ForwardToBCT(QR2* q)
{
    t->FUN_00442580(q);
}

void __cdecl FinishScriptRunLock(void*);

// @fnv 0x00440a10
void __fastcall FinishScriptRunLockAndReset(char* pThis)
{
    FinishScriptRunLock(pThis + 0xa4);
    if (*reinterpret_cast<int*>(pThis + 0xa4) < 0)
        *reinterpret_cast<int*>(pThis + 0xa4) = 0;
}

void __cdecl FinishScriptRunLock(void*);

// Calls FinishScriptRunLock on pThis+0xa0, then clamps the int at pThis+0xa0 to 0 if it is negative.
// @fnv 0x00440a50
void __fastcall FinishScriptRun(char* pThis)
{
    FinishScriptRunLock(pThis + 0xa0);
    if (*(int*)(pThis + 0xa0) < 0)
    {
        *(int*)(pThis + 0xa0) = 0;
    }
}

extern int DAT_01016ca4;
struct S4411
{
    void FUN_0043fd40(int, int);
    S4411* FUN_004411d0(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, sets the object's first field to point at DAT_01016ca4, and returns this.
// @fnv 0x004411d0
S4411* S4411::FUN_004411d0(int aiArg1, int aiArg2)
{
    FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016ca4;
    return this;
}

__declspec(thread) char _tls_pad_00441290[0x25c];
__declspec(thread) bool _tls_var_00441290;

struct _FUN_00441290_shell
{
    bool SetTlsFlag(bool bVal);
};

// Stores bVal into the thread-local flag and returns its previous value.
// @fnv 0x00441290
bool _FUN_00441290_shell::SetTlsFlag(bool abValue)
{
    bool bOld = _tls_var_00441290;
    _tls_var_00441290 = abValue;
    return bOld;
}

extern int DAT_01016cec;

struct FUN_004411d0
{
    FUN_004411d0(int, int);
    ~FUN_004411d0();
};

struct GlobalObject_00528cb0
{
    int m_val;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};

struct FUN_00441440 : public FUN_004411d0
{
    void* vftable;
    char pad[0x3c];
    GlobalObject_00528cb0 m_40;
    GlobalObject_00528cb0 m_44;

    FUN_00441440(int a, int b);
};

// Constructs the object: calls the base constructor, sets the vftable to DAT_01016cec, and initializes m_40 and m_44 to 0.
// @fnv 0x00441440
FUN_00441440::FUN_00441440(int a, int b) : FUN_004411d0(a, b), vftable(&DAT_01016cec), m_40(0), m_44(0)
{}

extern __declspec(thread) void* DAT_00441780_264;
extern __declspec(thread) void* DAT_00441780_260;

// Stores apRef and ap3D into the thread-local pointers DAT_00441780_264 and DAT_00441780_260.
// @fnv 0x00441780
void __cdecl FUN_00441780(void* apRef, void* ap3D)
{
    DAT_00441780_264 = apRef;
    DAT_00441780_260 = ap3D;
}

struct _TLS_Pad_004417c0
{
    char pad[0x260];
    int v260;
    int v264;
};

__declspec(thread) _TLS_Pad_004417c0 tls_004417c0;

// Clears the two int fields at offsets 0x260 and 0x264 in the thread-local block.
// @fnv 0x004417c0
void FUN_004417c0()
{
    tls_004417c0.v264 = 0;
    tls_004417c0.v260 = 0;
}

enum MEM_CONTEXT
{
};
struct LightTarget;
struct VATS
{
    LightTarget* FUN_005d8710(void);
};

struct AutoMemContext_1
{
    AutoMemContext_1(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext_1(void);
    int a;
};

struct TESAttackDamageForm_1
{
    virtual void Free(void);
};

void __fastcall AttachHeadAndFaceParts(void* pThis);

// Frees the object under a memory context, then calls AttachHeadAndFaceParts if FUN_005d8710 returns null.
// @fnv 0x00441820
void __fastcall FUN_00441820(char* apObject)
{
    AutoMemContext_1 tempMemContext(*(MEM_CONTEXT*)(apObject + 0x18), true,
                                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8ff);
    ((TESAttackDamageForm_1*)apObject)->TESAttackDamageForm_1::Free();
    if (!((VATS*)apObject)->FUN_005d8710())
    {
        AttachHeadAndFaceParts(apObject);
    }
}

namespace fnv_004418b0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnimObject;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFaceGenModel;
struct BSShaderPPLightingProperty;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiPoint3;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESIdleForm;
struct TESNPC;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectLIGH;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_004418b0_shell : public QueuedCharacter
{
    void AttachHeadAndFaceParts();
};

struct Biped;

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

struct TESObjectREFR_Helper
{
    Biped* GetBipedComponent();
};

struct HeadPart_Helper
{
    void Attach(TESObjectREFR* pRefr, Biped* pBiped);
};

struct FacePart_Helper
{
    void Attach();
};

void __fastcall FUN_0043ed90(const char* pHead, int unused, TESObjectREFR* pRefr, Biped* pBiped);
void __fastcall ApplyQueuedModels(const char* pFace);

// @fnv 0x004418b0
void FUN_004418b0_shell::AttachHeadAndFaceParts()
{
    TESObjectREFR* pcharacter = *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x28);
    Biped* pbiped = reinterpret_cast<TESObjectREFR_Helper*>(pcharacter)->GetBipedComponent();

    if (static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x40)))
    {
        reinterpret_cast<HeadPart_Helper*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x40))))
            ->Attach(*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x28), pbiped);
    }

    if (static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x44)))
    {
        reinterpret_cast<FacePart_Helper*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x44))))
            ->Attach();
    }
}
}  // namespace fnv_004418b0

extern int DAT_01016d7c;
struct PlayerCharacter;
extern PlayerCharacter* pPlayer;
struct S1b20
{
    void FUN_00441440(PlayerCharacter*, int);
    S1b20* InitWithPlayer(int a);
};
// Calls FUN_00441440 with pPlayer and a, sets the first field of this to point at DAT_01016d7c, and returns this.
// @fnv 0x00441b20
S1b20* S1b20::InitWithPlayer(int a)
{
    FUN_00441440(pPlayer, a);
    *reinterpret_cast<int**>(this) = &DAT_01016d7c;
    return this;
}

namespace fnv_00441d20 {
void __fastcall FUN_0044b160(void*);
void __fastcall FUN_00c3cea0(void*);

struct _Base_00441d20
{
    char _pad[0x30];
    ~_Base_00441d20()
    {
        FUN_00c3cea0(this);
    }
};

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        FUN_0044b160(this);
    }
};

struct FUN_00441d20 : _Base_00441d20
{
    _Mem_00441d20 m;
    int b;
    ~FUN_00441d20();
};

// Destructor: destroys the embedded member and then the base subobject.
// @fnv 0x00441d20
FUN_00441d20::~FUN_00441d20()
{}
}  // namespace fnv_00441d20

struct BSSemaphore_
{
    void Wait();
};

// @fnv 0x004424c0
void __fastcall FUN_004424c0(char* this_ptr)
{
    ((BSSemaphore_*)(this_ptr + 0xc))->Wait();
}

struct FUN_00442510_Cl
{
    char pad[0x18];
    CountingSemaphore sem;
    void Wait();
};

// @fnv 0x00442510
void __fastcall FUN_00442510(FUN_00442510_Cl* pThis)
{
    reinterpret_cast<void (CountingSemaphore::*)()>(&FUN_00442510_Cl::Wait);
    ((FUN_00442510_Cl*)((char*)pThis + 0x18))->Wait();
}

// @fnv 0x00442530
void __fastcall SignalAtOffset18(char* this_ptr)
{
    ((CountingSemaphore*)(this_ptr + 0x18))->Signal();
}

struct FUN_00442550_shell : public CountingSemaphore
{
    int ReleaseAndInitScriptRunLock();
};

int __cdecl InitScriptRunLock(void*);
__declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount, long* lpPreviousCount);

// Releases the semaphore stored at this+4 by one count, then calls InitScriptRunLock with this and returns its result.
// @fnv 0x00442550
int FUN_00442550_shell::ReleaseAndInitScriptRunLock()
{
    ReleaseSemaphore(*(void**)((char*)this + 4), 1, 0);
    return InitScriptRunLock(this);
}

namespace fnv_00442580 {
struct GlobalObject_00528cb0
{
    int v;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};
struct Sub
{
    void FUN_00449240(GlobalObject_00528cb0*);
};
struct ML2
{
    char pad[0x38];
    Sub* p;
    void ProcessQueuedFile();
    void FUN_00442580(int a);
};
// @fnv 0x00442580
void ML2::FUN_00442580(int a)
{
    {
        GlobalObject_00528cb0 g(a);
        p->FUN_00449240(&g);
    }
    ProcessQueuedFile();
}
}  // namespace fnv_00442580

struct FUN_00443190_shell : public Model
{
    int GetCombinedValue();
};

// @fnv 0x00443190
int FUN_00443190_shell::GetCombinedValue()
{
    return *(int*)((char*)this + 4) + *(int*)((char*)this + 8);
}

// @fnv 0x004431b0
int __fastcall FUN_004431b0(int* p)
{
    return p[3] + p[4];
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00444cc0
void __fastcall InitScriptRunLockForObject(char* pThis)
{
    InitScriptRunLock(pThis + 0xa4);
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00444ce0
void __fastcall FUN_00444ce0(char* pThis)
{
    InitScriptRunLock(pThis + 0xa0);
}

struct FUN_00444ed0_shell : public TESObjectREFR
{
    bool FUN_00444ed0();
};

struct TESFile
{
    const char* GetName();
};

// Reads a TESObject pointer from the file name and, if non-null, calls its virtual function at offset 0x154, returning the result or false.
// @fnv 0x00444ed0
bool FUN_00444ed0_shell::FUN_00444ed0()
{
    TESObject* pObject = *reinterpret_cast<TESObject* const*>(reinterpret_cast<TESFile*>(this)->GetName());
    return pObject ? (reinterpret_cast<bool(__thiscall**)(TESObject*)>(*reinterpret_cast<void***>(pObject))[0x154 / 4])(
                         pObject)
                   : false;
}

struct FUN_00445300_shell : public ModelLoader
{
    void FUN_00445300(char*, bool, unsigned int);
};

struct ModelStub
{
    void ReleaseScriptRunLock();
    void AtomicAdd(int);
};
struct LoaderStub
{
    void FUN_00448920(ModelStub*, const char*);
};
struct ModelMapStub
{
    virtual void a();
    virtual void b();
    virtual bool Lookup(const char*, ModelStub**);
};
struct ModelMapHolder
{
    ModelMapStub* m_pLoadedModelMap;
};
// @fnv 0x00445300
void FUN_00445300_shell::FUN_00445300(char* apModelFileName, bool abDeleteIfUnreferenced, unsigned int aiNumDecrements)
{
    ModelStub* pmodel = 0;
    if (((ModelMapHolder*)this)->m_pLoadedModelMap->Lookup(apModelFileName, &pmodel))
    {
        if (aiNumDecrements == 1)
            pmodel->ReleaseScriptRunLock();
        else
            pmodel->AtomicAdd(-(short)aiNumDecrements);
        if (abDeleteIfUnreferenced)
            ((LoaderStub*)this)->FUN_00448920(pmodel, apModelFileName);
    }
}

void __cdecl FUN_0044af70(unsigned char, void*);

struct FUN_00447190_dummy
{
    void FUN_00447190(unsigned char arg1);
};

// Calls FUN_0044af70 with arg1 and a pointer to this object at offset 0x3c.
// @fnv 0x00447190
void FUN_00447190_dummy::FUN_00447190(unsigned char aByte)
{
    FUN_0044af70(aByte, (char*)this + 0x3c);
}

struct FUN_004472a0_shell : public ModelLoader
{
    bool FUN_004472a0(char*, void*);
};

struct VHelper
{
    virtual ~VHelper()
    {}
    virtual void _v1()
    {}
    virtual bool Get(char*, void**)
    {
        return 0;
    }
};

struct ModelLoaderAccess
{
    VHelper* m_pLoadedModelMap;
};

struct SetterHelper
{
    void FUN_0044aed0(void* value);
};

// Clears output, asks the loader for the model named by filename, and stores it in output if found; returns whether it succeeded.
// @fnv 0x004472a0
bool FUN_004472a0_shell::FUN_004472a0(char* filename, void* output)
{
    ((SetterHelper*)output)->FUN_0044aed0(0);
    void* pmodel = 0;
    if (((ModelLoaderAccess*)this)->m_pLoadedModelMap->Get(filename, &pmodel))
    {
        ((SetterHelper*)output)->FUN_0044aed0(pmodel);
        return true;
    }
    return false;
}

struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiCamera;
struct NiColor;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESClimate;
struct TESFile;
struct TESGlobal;
struct TESImageSpace;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
struct FUN_00447950_shell : public ModelLoader
{
    bool FUN_00447950(TESObjectCELL*);
};

class Tile;
class InterfaceManager
{
  public:
    Tile* FUN_004fd400(void);
};

// Returns true if apCell is non-null and its InterfaceManager FUN_004fd400 result is greater than zero.
// @fnv 0x00447950
bool FUN_00447950_shell::FUN_00447950(TESObjectCELL* apCell)
{
    if (apCell && reinterpret_cast<int>(reinterpret_cast<InterfaceManager*>(apCell)->FUN_004fd400()) > 0)
        return true;
    return false;
}

namespace fnv_00448920 {
struct FUN_00448920_shell : public ModelLoader
{
    void FUN_00448920(Model*, char*);
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

int __fastcall GetCombinedValue(Model*);

struct ModelDeleteStub
{
    void* FUN_004431f0(unsigned int);
};

struct ModelMapStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Remove(char*);
};

struct BGSSaveLoadGameAccess : public BGSSaveLoadGame
{
    bool FUN_0042ce10();
};

// @fnv 0x00448920
void FUN_00448920_shell::FUN_00448920(Model* apModel, char* apModelFileName)
{
    if (GetCombinedValue(apModel) == 0)
    {
        bool bremoveFromMap = true;
        if (g_BGSSaveLoadGame && ((BGSSaveLoadGameAccess*)g_BGSSaveLoadGame)->FUN_0042ce10())
        {
            bremoveFromMap = false;
            *((bool*)((char*)this + 0x2c)) = true;
        }
        if (bremoveFromMap)
        {
            (*(ModelMapStub**)this)->Remove(apModelFileName);
            ModelDeleteStub* tmp1 = (ModelDeleteStub*)apModel;
            ModelDeleteStub* tmp2 = tmp1;
            tmp2 ? tmp2->FUN_004431f0(1) : 0;
        }
    }
}
}  // namespace fnv_00448920

struct FUN_00448a60_struct
{
    unsigned int pad[3];
    unsigned int val;
    unsigned int GetMaskedValue(unsigned int mask);
};

// @fnv 0x00448a60
unsigned int FUN_00448a60_struct::GetMaskedValue(unsigned int mask)
{
    return val & mask;
}

// @fnv 0x00448de0
bool __fastcall IsNotStateSix(int param_1)
{
    return *(int*)(param_1 + 0x68) != 6;
}

// Sets both 64-bit elements of the given array to zero and returns the array pointer.
// @fnv 0x00448e00
__int64* __fastcall ClearPair(__int64* param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    return param_1;
}

__int64 __cdecl FUN_00aa4d80();
extern float DAT_011ac39c;

struct FUN_00448e30_this
{
    __int64 a;
    __int64 b;
    void init(float f);
};

// Stores the result of FUN_00aa4d80 in a and f multiplied by DAT_011ac39c in b.
// @fnv 0x00448e30
void FUN_00448e30_this::init(float afValue)
{
    a = FUN_00aa4d80();
    b = (__int64)(afValue * DAT_011ac39c);
}

__int64 __cdecl FUN_00aa4d80();

// @fnv 0x00448e70
bool __fastcall FUN_00448e70(__int64* pThis)
{
    return (FUN_00aa4d80() - pThis[0]) > pThis[1];
}

namespace fnv_00448f50 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_00448f50_shell : public ModelLoader
{
    void ForwardToVTableSlot(BSFileEntry*);
};

struct _DummyVTable_00448f50
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(BSFileEntry*);
};

// Calls the virtual method at vtable slot 5 on the object stored at this+0x20, passing apFileEntry.
// @fnv 0x00448f50
void FUN_00448f50_shell::ForwardToVTableSlot(BSFileEntry* apFileEntry)
{
    (*reinterpret_cast<_DummyVTable_00448f50**>(reinterpret_cast<char*>(this) + 0x20))->v5(apFileEntry);
}
}  // namespace fnv_00448f50

// @fnv 0x00449050
int __cdecl FUN_00449050(int aeIOFileIndex)
{
    switch (aeIOFileIndex)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    default:
        return 8;
    }
}

extern int DAT_01017138;
extern int DAT_011c3b38;
int __cdecl InitScriptRunLock(void*);

// @fnv 0x00449090
void* __fastcall FUN_00449090(void* apObject)
{
    *((void**)apObject) = &DAT_01017138;
    *((int*)((char*)apObject + 8)) = 0;
    *((int*)((char*)apObject + 0xc)) = 0;
    *((__int64*)((char*)apObject + 0x10)) = 0;
    InitScriptRunLock(&DAT_011c3b38);
    return apObject;
}

// @fnv 0x00449110
bool __fastcall FUN_00449110(int* piValues)
{
    return piValues[3] >= 4;
}

// @fnv 0x00449130
bool __fastcall FUN_00449130(int* pThis)
{
    return pThis[3] == 6;
}

// @fnv 0x00449150
void __fastcall SetFieldCToFive(char* pObject)
{
    *reinterpret_cast<int*>(pObject + 0xc) = 5;
}

bool __cdecl FUN_004491c0(void*, int, int);

struct FUN_00449190_cls
{
    bool SetState(int eCurrentState, int eNewState);
};

// Calls FUN_004491c0 with a pointer to this object's field at offset 0xc, passing the new state and current state.
// @fnv 0x00449190
bool FUN_00449190_cls::SetState(int eCurrentState, int eNewState)
{
    return FUN_004491c0((char*)this + 0xc, eNewState, eCurrentState);
}

int __cdecl FUN_0043b460(long volatile*, long, long);

class Interface
{
  public:
    static void __cdecl PrintDebugMessage();
};

// @fnv 0x004491c0
bool __cdecl FUN_004491c0(long volatile* pVolatile, long param_2, long param_3)
{
    bool res = FUN_0043b460(pVolatile, param_3, param_2) == param_3;
    Interface::PrintDebugMessage();
    return res;
}

struct E_00449210
{
    void FUN_00449240(int);
};
struct C_00449210
{
    virtual void v0();
    virtual void v1();
    E_00449210** arr;
    void FUN_00449210(int idx, int val);
};
// Calls FUN_00449240 on the element at idx with val, then calls v1().
// @fnv 0x00449210
void C_00449210::FUN_00449210(int aiIndex, int val)
{
    arr[aiIndex]->FUN_00449240(val);
    v1();
}

struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
struct R449
{
    bool Pop();
};
struct Q449
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449* FUN_00449f80(void*);
    bool FUN_00449280(void*);
};
// Locks the object, calls Pop on the result of FUN_00449f80(arData), unlocks, and returns that bool.
// @fnv 0x00449280
bool Q449::FUN_00449280(void* arData)
{
    lock.Lock(0);
    bool bResult = FUN_00449f80(arData)->Pop();
    lock.Unlock();
    return bResult;
}

extern int DAT_0101732c;

struct FUN_004492c0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004492c0_shell* FUN_004492c0(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004492c0
FUN_004492c0_shell* FUN_004492c0_shell::FUN_004492c0(int a, int b, int c)
{
    FUN_0044c270(a, b, c);
    vtbl = (int)&DAT_0101732c;
    return this;
}

struct FUN_00449500_shell
{
    void FUN_00449500(const char* param_1, char** param_2);
};

// @fnv 0x00449500
void FUN_00449500_shell::FUN_00449500(const char* param_1, char** param_2)
{
    TaskQueueInterface::CopyStringToBuffer(*param_2, 0x100, param_1);
}

namespace fnv_00449530 {
struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
struct R530
{
    bool InvokeWithArgs();
};
struct FUN_00449530_S
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R530* FUN_00449f80(int, int);
    bool FUN_00449530(int a, int b);
};
// @fnv 0x00449530
bool FUN_00449530_S::FUN_00449530(int a, int b)
{
    lock.Lock(0);
    bool r = FUN_00449f80(a, b)->InvokeWithArgs();
    lock.Unlock();
    return r;
}
}  // namespace fnv_00449530

namespace fnv_00449580 {
struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
struct R449b
{
    bool FUN_0044a130();
};
struct Q449b
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449b* FUN_00449f80(void*, void*, bool);
    bool FUN_00449580(void*, void*, bool);
};
// @fnv 0x00449580
bool Q449b::FUN_00449580(void* a, void* b, bool c)
{
    lock.Lock(0);
    bool bResult = FUN_00449f80(a, b, c)->FUN_0044a130();
    lock.Unlock();
    return bResult;
}
}  // namespace fnv_00449580

namespace fnv_004495d0 {
struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
struct R449
{
    bool Pop();
};
struct Q449
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449* FUN_00449f80(void*);
    bool FUN_004495d0(void*);
};
// @fnv 0x004495d0
bool Q449::FUN_004495d0(void* arData)
{
    lock.Lock(0);
    bool bResult = FUN_00449f80(arData)->Pop();
    lock.Unlock();
    return bResult;
}
}  // namespace fnv_004495d0

void __fastcall FUN_0044a040(void*);

// @fnv 0x00449680
void __fastcall FUN_00449680(void* p)
{
    FUN_0044a040(p);
}

namespace fnv_004496a0 {
extern int DAT_0101732c;

struct FUN_004496a0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004496a0_shell* FUN_004496a0(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004496a0
FUN_004496a0_shell* FUN_004496a0_shell::FUN_004496a0(int a, int b, int c)
{
    FUN_0044c270(a, b, c);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_004496a0

int __cdecl FUN_00ec6da0(const char*, const char*);

struct FUN_004496d0_shell
{
    bool IsGreaterOrEqual(const char* a, const char* b);
};

// Returns whether the result of FUN_00ec6da0(a, b) is greater than or equal to zero.
// @fnv 0x004496d0
bool FUN_004496d0_shell::IsGreaterOrEqual(const char* pcLeft, const char* pcRight)
{
    return FUN_00ec6da0(pcLeft, pcRight) >= 0;
}

namespace fnv_004497c0 {
extern int DAT_0101732c;

struct FUN_004497c0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004497c0_shell* FUN_004497c0(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004497c0
FUN_004497c0_shell* FUN_004497c0_shell::FUN_004497c0(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_004497c0

int __cdecl FUN_00ec6da0(const char* a, const char* b);

struct FUN_00449880_Class
{
    bool FUN_00449880(const char* a, const char* b);
};

// Returns true when the comparison of the two strings via FUN_00ec6da0 yields zero.
// @fnv 0x00449880
bool FUN_00449880_Class::FUN_00449880(const char* pcStringA, const char* pcStringB)
{
    return FUN_00ec6da0(pcStringA, pcStringB) == 0;
}

extern int DAT_01017288;
void __fastcall FUN_0044cb70(void*);

// @fnv 0x004498e0
void* __fastcall FUN_004498e0(void* apObject)
{
    FUN_0044cb70(apObject);
    *reinterpret_cast<void**>(apObject) = &DAT_01017288;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(apObject) + 8) =
        reinterpret_cast<void*>(reinterpret_cast<char*>(apObject) + 0x10);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(apObject) + 0x10) = 0;
    return apObject;
}

extern int DAT_01017294;

// @fnv 0x00449940
void __fastcall FUN_00449940(void** apOut)
{
    *apOut = &DAT_01017294;
}

void __fastcall FUN_0044cbb0(void* pThis);
extern int DAT_010172a0;

// @fnv 0x00449960
void* __fastcall FUN_00449960(char* pThis)
{
    FUN_0044cbb0(pThis);
    *reinterpret_cast<int**>(pThis) = &DAT_010172a0;
    *reinterpret_cast<char**>(pThis + 8) = pThis + 0x10;
    pThis[0x10] = 0;
    return pThis;
}

extern int DAT_010172ac;

// @fnv 0x004499a0
void __fastcall FUN_004499a0(int** ppTarget)
{
    *ppTarget = &DAT_010172ac;
}

extern int DAT_010172b8;

// @fnv 0x004499c0
void __fastcall FUN_004499c0(void* pThis)
{
    *(int**)pThis = &DAT_010172b8;
}

extern int DAT_010172c4;

// @fnv 0x004499e0
void __fastcall FUN_004499e0(void* pThis)
{
    *(int**)pThis = &DAT_010172c4;
}

extern int DAT_010172d0;

// @fnv 0x00449a00
void __fastcall FUN_00449a00(int** appTarget)
{
    *appTarget = &DAT_010172d0;
}

namespace fnv_00449f50 {
extern int DAT_0101732c;

struct FUN_00449f50_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_00449f50_shell* FUN_00449f50(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x00449f50
FUN_00449f50_shell* FUN_00449f50_shell::FUN_00449f50(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_00449f50

void __fastcall FUN_0044d5c0(int pThis, int edx, void* pArg);

// @fnv 0x00449f80
void __fastcall FUN_00449f80(int* pThis)
{
    reinterpret_cast<void(__thiscall*)(int, void*)>(&FUN_0044d5c0)(pThis[5], pThis);
}

namespace fnv_00449fa0 {
extern int DAT_0101732c;

struct FUN_00449fa0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_00449fa0_shell* ConstructWithVtbl(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x00449fa0
FUN_00449fa0_shell* FUN_00449fa0_shell::ConstructWithVtbl(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_00449fa0

namespace fnv_0044a100 {
extern int DAT_0101732c;

struct FUN_0044a100_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_0044a100_shell* FUN_0044a100(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x0044a100
FUN_0044a100_shell* FUN_0044a100_shell::FUN_0044a100(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_0044a100

struct V130
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
    virtual int v9(int, int, int, unsigned char);
};
struct S130
{
    V130* p;
    void InsertOrReplaceNode(int);
    void FUN_0044a130(int a, int b, unsigned char c);
};
// Calls the virtual method v9 on p with a, a, b and c, then passes the result to InsertOrReplaceNode.
// @fnv 0x0044a130
void S130::FUN_0044a130(int a, int aiArg, unsigned char c)
{
    InsertOrReplaceNode(p->v9(a, a, aiArg, c));
}

struct _Out_0044a170
{
    void FUN_0065e000(int d, void* self);
};

struct _Dummy_0044a170
{
    int a, b, c, d;
    _Out_0044a170* FUN_0044a170(_Out_0044a170* out);
};

// @fnv 0x0044a170
_Out_0044a170* _Dummy_0044a170::FUN_0044a170(_Out_0044a170* out)
{
    out->FUN_0065e000(this->d, this);
    return out;
}

class MiddleHighProcess
{
  public:
    NiAVObject* GetAnimationObject();
};

void __cdecl CallWithScaledArg(NiAVObject*, int, int);

// @fnv 0x0044adf0
void __cdecl FUN_0044adf0(MiddleHighProcess* pProcess, int a2)
{
    CallWithScaledArg(pProcess->GetAnimationObject(), a2, 1);
}

struct WaitableObject
{
    void FUN_0040f6e0();
    void FUN_0040c130();
};
struct NP_0044aed0
{
    WaitableObject* m_pObject;
    NP_0044aed0& FUN_0044aed0(WaitableObject* pObject);
};
// @fnv 0x0044aed0
NP_0044aed0& NP_0044aed0::FUN_0044aed0(WaitableObject* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            m_pObject->FUN_0040c130();
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->FUN_0040f6e0();
    }
    return *this;
}

namespace fnv_0044b010 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_0044b010_shell : public KFModel
{
    void FUN_0044b010();
};

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0044b010
void FUN_0044b010_shell::FUN_0044b010()
{
    InitScriptRunLock(&pListSequence);
}
}  // namespace fnv_0044b010

namespace fnv_0044b050 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_0044b050_shell : public KFModel
{
    void FUN_0044b050();
};

void __cdecl FinishScriptRunLock(void*);

// @fnv 0x0044b050
void FUN_0044b050_shell::FUN_0044b050()
{
    FinishScriptRunLock(&this->pListSequence);
}
}  // namespace fnv_0044b050

struct FUN_0044b0c0_holder
{
    LoadedFile* m_pObject;
    FUN_0044b0c0_holder* SetObject(LoadedFile* pObject);
};

// Stores pObject in m_pObject and increments its reference count when non-null, then returns this.
// @fnv 0x0044b0c0
FUN_0044b0c0_holder* FUN_0044b0c0_holder::SetObject(LoadedFile* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
    return this;
}

namespace fnv_0044b0f0 {
struct BSFile;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
typedef char _sizecheck_LoadedFile[sizeof(LoadedFile) == 16 ? 1 : -1];
struct FUN_0044b0f0_shell : public LoadedFile
{
    void FUN_0044b0f0();
};

struct RecursiveLock
{
    void Leave();
};
extern RecursiveLock g_011c3b6c;
bool __fastcall FUN_0044b130(RecursiveLock*);
int __cdecl InitScriptRunLock(void*);

// @fnv 0x0044b0f0
void FUN_0044b0f0_shell::FUN_0044b0f0()
{
    while (!FUN_0044b130(&g_011c3b6c))
    {
    }
    InitScriptRunLock(this);
    g_011c3b6c.Leave();
}
}  // namespace fnv_0044b0f0

struct FUN_0044b160_obj
{
    void FUN_0040c130();
};
void __fastcall FUN_0040c130(void*);

struct FUN_0044b160_ptr
{
    struct Target
    {
        void Release();
    }* m_pObject;
};

void __fastcall FUN_0040c130(FUN_0044b160_ptr::Target*);

// @fnv 0x0044b160
void __fastcall FUN_0044b160(FUN_0044b160_ptr* _this)
{
    if (_this->m_pObject)
        FUN_0040c130(_this->m_pObject);
}

namespace fnv_0044b180 {
struct BSFile;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
typedef char _sizecheck_LoadedFile[sizeof(LoadedFile) == 16 ? 1 : -1];
struct FUN_0044b180_shell : public LoadedFile
{
    void FUN_0044b180();
};

struct GlobalObject_0044fae0
{
    bool FUN_0044b130();
    void Leave();
};
extern GlobalObject_0044fae0 g_011c3b6c;
void __cdecl FinishScriptRunLock(void*);
struct Del44b
{
    int FUN_0044b1f0(int);
};
// @fnv 0x0044b180
void FUN_0044b180_shell::FUN_0044b180()
{
    while (!g_011c3b6c.FUN_0044b130())
    {
    }
    FinishScriptRunLock(this);
    g_011c3b6c.Leave();
    if (*(int*)this == 0)
    {
        struct D
        {
            Del44b* doomed;
            Del44b* object;
        } d;
        d.doomed = (Del44b*)this;
        d.object = d.doomed;
        d.object ? d.object->FUN_0044b1f0(1) : 0;
    }
}
}  // namespace fnv_0044b180

void __fastcall FUN_0044b2e0(void* pThis);

// @fnv 0x0044b2c0
void __fastcall FUN_0044b2c0(void** pThis)
{
    if (*pThis)
    {
        FUN_0044b2e0(*pThis);
    }
}

void __fastcall FUN_0044dd60(void* pThis);

// @fnv 0x0044cbf0
void __fastcall FUN_0044cbf0(void** apObject)
{
    if (*apObject)
    {
        FUN_0044dd60(*apObject);
    }
}

namespace fnv_0044dd60 {
int __cdecl FinishScriptRunLock(void*);

struct VirtualDeletable
{
    virtual ~VirtualDeletable();
};

// Calls FinishScriptRunLock on the object at offset 8 and deletes the object if the returned count is zero.
// @fnv 0x0044dd60
void __fastcall FUN_0044dd60(VirtualDeletable* apObject)
{
    int count = FinishScriptRunLock((char*)apObject + 8);
    if (count == 0)
    {
        delete apObject;
    }
}
}  // namespace fnv_0044dd60

// @fnv 0x0044faa0
void* __fastcall FUN_0044faa0(char* this_ptr)
{
    return this_ptr + 0x10C;
}

struct RefT
{
    void _ref_00726070();
};
struct FUN_0044fac0_S
{
    void FUN_0044fac0(RefT* p);
};
// @fnv 0x0044fac0
void FUN_0044fac0_S::FUN_0044fac0(RefT* apRef)
{
    apRef->_ref_00726070();
}

__declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

// @fnv 0x0044fae0
void* __fastcall FUN_0044fae0(void* apCriticalSection)
{
    InitializeCriticalSection(apCriticalSection);
    return apCriticalSection;
}

namespace fnv_0045bad0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiRTTI
{
    char* GetName();
    void* GetBaseRTTI();
    char* m_pcName;
    void* m_pBaseRTTI;
};
typedef char _sizecheck_NiRTTI[sizeof(NiRTTI) == 8 ? 1 : -1];

class NiObject;
struct FUN_0045baf0_helper
{
    bool IsEqual(const NiRTTI*) const;
};

// @fnv 0x0045bad0
bool __cdecl FUN_0045bad0(const NiRTTI* pkRTTI, const NiObject* pkObject)
{
    if (!pkObject)
        return false;
    return ((const FUN_0045baf0_helper*)pkObject)->IsEqual(pkRTTI);
}
}  // namespace fnv_0045bad0

struct Item
{
    bool IsFieldEqual(void* a);
};
struct LNode
{
    Item** _ref_006815c0();
    LNode* _ref_00726070();
};
struct TESDataHandler
{
    LNode* GetTESObjectANIOList();
    Item* FindNthMatchingItem(void* a, int n);
};
// Walks the TESObjectANIO list and returns the item matching a, skipping the first n matches; returns 0 if none found.
// @fnv 0x0046fd50
Item* TESDataHandler::FindNthMatchingItem(void* a, int aiSkipCount)
{
    Item* item = 0;
    LNode* node = GetTESObjectANIOList();
    while (node && (item = *node->_ref_006815c0()))
    {
        if (item->IsFieldEqual(a))
        {
            if (aiSkipCount == 0)
                return item;
            else
                aiSkipCount = aiSkipCount - 1;
        }
        node = node->_ref_00726070();
    }
    return 0;
}

struct S_004a0e10
{
    char pad[0x208];
    unsigned char f208;
    bool FUN_004a0e50();
    bool FUN_004a0e10(int a, unsigned char b);
};
// Returns false if FUN_004a0e50 fails; otherwise returns whether f208 equals b.
// @fnv 0x004a0e10
bool S_004a0e10::FUN_004a0e10(int aiUnused, unsigned char b)
{
    if (!FUN_004a0e50())
        return false;
    if (f208 == b)
        return true;
    return false;
}

namespace fnv_004a8a90 {
template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x004a8a90
const char* __fastcall FUN_004a8a90(char* apObject)
{
    return *(const BSStringT<char>*)(apObject + 0x30);
}
}  // namespace fnv_004a8a90

struct AC_0042f730
{
    void FUN_0044bbc0();
};
struct S_0042f730
{
    AC_0042f730* m_pObject;
    S_0042f730* FUN_00528cb0(AC_0042f730* pObject);
};
// Stores pObject in m_pObject and, if it is non-null, calls FUN_0044bbc0 on it; returns this.
// @fnv 0x00528cb0
S_0042f730* S_0042f730::FUN_00528cb0(AC_0042f730* pObject)
{
    m_pObject = pObject;
    if (m_pObject)
        m_pObject->FUN_0044bbc0();
    return this;
}

namespace fnv_00537bd0 {
template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x00537bd0
const char* __fastcall GetStringAtOffset(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x78);
}
}  // namespace fnv_00537bd0

namespace fnv_005495f0 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x005495f0
const char* __fastcall FUN_005495f0(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0xb8);
}
}  // namespace fnv_005495f0

// @fnv 0x00559450
int __fastcall FUN_00559450(int* pThis)
{
    return *pThis;
}

struct FUN_005d8710_shell : public QueuedReference
{
    NiAVObject* FUN_005d8710();
};

// @fnv 0x005d8710
NiAVObject* FUN_005d8710_shell::FUN_005d8710()
{
    return *(NiPointer<NiAVObject>*)((char*)this + 0x34);
}

namespace fnv_0062a100 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_0062a100_shell : public BSFileEntry
{
    unsigned int GetSizeMasked();
};

// @fnv 0x0062a100
unsigned int FUN_0062a100_shell::GetSizeMasked()
{
    return iSize & 0x3fffffff;
}
}  // namespace fnv_0062a100

struct NiRTTI_b;
NiRTTI_b* __fastcall _ref_00726070(NiRTTI_b*);
struct NiObject_b
{
    virtual void v0();
    virtual void v1();
    virtual NiRTTI_b* GetRTTI();
    bool FUN_006532c0(const NiRTTI_b* pkRTTI);
};
// Walks the RTTI chain from GetRTTI() and returns true if pkRTTI is found, otherwise false.
// @fnv 0x006532c0
bool NiObject_b::FUN_006532c0(const NiRTTI_b* pkRTTI)
{
    const NiRTTI_b* pkThis = GetRTTI();
    while (pkThis)
    {
        if (pkThis == pkRTTI)
            return true;
        pkThis = _ref_00726070(const_cast<NiRTTI_b*>(pkThis));
    }
    return false;
}

namespace fnv_006838b0 {
struct NiCollisionObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_006838b0_shell : public NiAVObject
{
    NiCollisionObject* FUN_006838b0();
};

template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x006838b0
NiCollisionObject* FUN_006838b0_shell::FUN_006838b0()
{
    return (NiCollisionObject*)((const BSStringT<char>*)((const char*)this + 0x1c))->operator const char*();
}
}  // namespace fnv_006838b0

struct Dummy_0069b080
{
    int pad0;
    int pad1;
    int pad2;
    int field_c;
    bool IsFieldCZero();
};

// @fnv 0x0069b080
bool __fastcall IsFieldCZero(Dummy_0069b080* pThis)
{
    return pThis->field_c == 0;
}

namespace fnv_006fa820 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x006fa820
const char* __fastcall FUN_006fa820(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x10);
}
}  // namespace fnv_006fa820

struct QH_0092c820
{
    void FUN_0044dd60();
    void FUN_0092c870();
};
struct NP_0092c820
{
    QH_0092c820* m_pObject;
    NP_0092c820& FUN_0092c820(const NP_0092c820& ptr);
};
// @fnv 0x0092c820
NP_0092c820& NP_0092c820::FUN_0092c820(const NP_0092c820& aOther)
{
    if (m_pObject != aOther.m_pObject)
    {
        if (m_pObject)
            m_pObject->FUN_0044dd60();
        m_pObject = aOther.m_pObject;
        if (m_pObject)
            m_pObject->FUN_0092c870();
    }
    return *this;
}

struct FUN_0092c870_shell : public Model
{
    void FUN_0092c870();
};

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0092c870
void FUN_0092c870_shell::FUN_0092c870()
{
    InitScriptRunLock((char*)this + 8);
}

struct BSAudioManager
{
    static BSAudioManager* __cdecl GetRandomGenerator();
    void FUN_00adb690(int, float, int);
};
struct FUN_00ad8570_S
{
    void FUN_00ad8570(int a, float b, int c);
};
// @fnv 0x00ad8570
void FUN_00ad8570_S::FUN_00ad8570(int a, float b, int c)
{
    BSAudioManager::GetRandomGenerator()->FUN_00adb690(a, b, c);
}

void __cdecl FUN_00af4070(void*, int);
int __cdecl WildcardMatch(void*, void*);

// @fnv 0x00af3bd0
int FUN_00af3bd0(int param1, int param2)
{
    char buf1[0x108];
    char buf2[0x108];
    FUN_00af4070(buf2, param1);
    FUN_00af4070(buf1, param2);
    return WildcardMatch(buf2, buf1) == 1;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// @fnv 0x00c3f8a0
long __fastcall FUN_00c3f8a0(char* pObject)
{
    return InterlockedDecrement((volatile long*)(pObject + 0x18));
}

namespace fnv_0043c550 {
struct FUN_0043c550_shell : public QueuedTexture
{
    void ApplyQueuedTexture();
};

struct Tile
{
    Tile* GetParent() const;
};
struct BSStringT
{
    operator const char*() const;
};
struct TextureFileEntrySetter
{
    static void SetTexture(const char*, const BSFileEntry*);
};
struct H0 : public LocationDescriptor
{
    bool FUN_0043e530();
    bool FUN_0043c630();
    void FUN_0043c100(int);
    void RunVirtualMethod28();
};
struct HM
{
    void ForwardToVTableSlot(BSFileEntry*);
};
// @fnv 0x0043c550
void FUN_0043c550_shell::ApplyQueuedTexture()
{
    if (!((H0*)this)->FUN_0043e530() && (const char*)(*(BSStringT*)((char*)this + 0x30)))
    {
        if (((H0*)this)->SetLocRef())
            TextureFileEntrySetter::SetTexture((const char*)(*(BSStringT*)((char*)this + 0x30)),
                                               ((H0*)this)->SetLocRef());
        else if (((Tile*)this)->GetParent())
            TextureFileEntrySetter::SetTexture((const char*)(*(BSStringT*)((char*)this + 0x30)), 0);
    }
    if (((H0*)this)->SetLocRef() && ((H0*)this)->FUN_0043c630())
    {
        ((H0*)this)->FUN_0043c100(0);
        ((HM*)g_modelLoader)->ForwardToVTableSlot(((H0*)this)->SetLocRef());
    }
    ((H0*)this)->RunVirtualMethod28();
}
}  // namespace fnv_0043c550

struct UW
{
    unsigned int v;
};
struct BW
{
    bool v;
};
// Sets or clears bit f.v in the bit array at self+0x20 and resets the value at self+0x38 when the bit changes.
// @fnv 0x00441130
void __fastcall FUN_00441130(char* self, UW auiFlag, BW abSet)
{
    unsigned int uiindex = auiFlag.v >> 5;
    unsigned int uibit = auiFlag.v % 32;
    unsigned int uimask = 1 << uibit;
    if (abSet.v)
    {
        if (!(((unsigned int*)(self + 0x20))[uiindex] & uimask))
            *(unsigned int*)(self + 0x38) = 0;
        ((unsigned int*)(self + 0x20))[uiindex] |= uimask;
    }
    else
    {
        if (((unsigned int*)(self + 0x20))[uiindex] & uimask)
            *(unsigned int*)(self + 0x38) = 0;
        ((unsigned int*)(self + 0x20))[uiindex] &= ~uimask;
    }
}

struct Struct_008b7b70;
bool __fastcall FUN_008b7b70(Struct_008b7b70*);
struct PC7d;
extern PC7d* g_thePlayer;
struct A9
{
    int FUN_00936ef0();
    void FUN_008b7360(int, void*);
};
struct Hx
{
    void FUN_0043fed0();
};
struct MLa
{
    bool IsLoadTexturesDegraded();
    bool SetTlsFlag(bool);
};
// @fnv 0x00441200
void __fastcall FUN_00441200(char* self)
{
    void** a = *(void***)(self + 0x28);
    bool b;
    ((void(__thiscall*)(void*))(*(void***)a)[0x260 / 4])(a);
    b = ((MLa*)g_modelLoader)->IsLoadTexturesDegraded();
    if ((void*)a != g_thePlayer && !((A9*)a)->FUN_00936ef0())
        ((MLa*)g_modelLoader)->SetTlsFlag(true);
    if (FUN_008b7b70((Struct_008b7b70*)a))
        ((A9*)a)->FUN_008b7360(1, self);
    ((Hx*)self)->FUN_0043fed0();
    ((MLa*)g_modelLoader)->SetTlsFlag(b);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043be30(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x0043be30
void* DelStandIn::FUN_0043be30(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct NP
{
    ~NP();
};
namespace p07 {
struct _Base_00441d20
{
    virtual ~_Base_00441d20();
    char pad[0x2c];
};
struct FUN_0043bf80 : _Base_00441d20
{
    NP np;
    virtual ~FUN_0043bf80();
};
// Destructor for the object; destroys the embedded NP member and the base subobject.
// @fnv 0x0043bf80
FUN_0043bf80::~FUN_0043bf80()
{}
}

namespace fnv_0043c800 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043c800(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0043c800
void* DelStandIn::FUN_0043c800(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043c800

namespace fnv_0043d090 {
struct NP
{
    void* m_pObject;
    ~NP();
};
struct _NiStreamDtorAlias
{
    char pad[0x5c4];
    virtual ~_NiStreamDtorAlias();
};
namespace FUN_0043d090 {
struct BSStream : public _NiStreamDtorAlias
{
    NP pSceneObject;
    virtual ~BSStream();
    void DestroyObject();
};
}

// Destructor that calls DestroyObject before destroying the stream object.
// @fnv 0x0043d090
FUN_0043d090::BSStream::~BSStream()
{
    DestroyObject();
}
}  // namespace fnv_0043d090

namespace fnv_0043e180 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043e180(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0043e180
void* DelStandIn::FUN_0043e180(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043e180

namespace fnv_0043e600 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043e600(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0043e600
void* DelStandIn::FUN_0043e600(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043e600

namespace fnv_0043e630 {
struct NP
{
    ~NP();
};
namespace p07 {
struct FUN_0043e1b0
{
    char pad[0x3c];
    ~FUN_0043e1b0();
};
struct FUN_0043e630 : FUN_0043e1b0
{
    NP np;
    ~FUN_0043e630();
};
// @fnv 0x0043e630
FUN_0043e630::~FUN_0043e630()
{}
}
}  // namespace fnv_0043e630

namespace fnv_0043eb80 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043eb80(unsigned int flags);
};
// Calls the destructor on this, then frees this when bit 0 of flags is set, and returns this.
// @fnv 0x0043eb80
void* DelStandIn::FUN_0043eb80(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043eb80

namespace fnv_004414c0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_004414c0(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x004414c0
void* DelStandIn::FUN_004414c0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_004414c0

namespace fnv_004414f0 {
struct GlobalObject_00528cb0
{
    ~GlobalObject_00528cb0();
    void* p;
};
struct FUN_00440eb0
{
    ~FUN_00440eb0();
    char pad[0x40];
};
struct FUN_004414f0 : public FUN_00440eb0
{
    GlobalObject_00528cb0 a;
    GlobalObject_00528cb0 b;
    ~FUN_004414f0();
};

// @fnv 0x004414f0
FUN_004414f0::~FUN_004414f0()
{}
}  // namespace fnv_004414f0

namespace fnv_00441b50 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00441b50(unsigned int flags);
};
// Runs the destructor on this object, then frees it via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00441b50
void* DelStandIn::FUN_00441b50(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00441b50

namespace fnv_00442010 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00442010(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00442010
void* DelStandIn::FUN_00442010(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00442010

namespace fnv_00442040 {
struct NiPtrNode_S
{
    ~NiPtrNode_S();
    void* m_pObject;
};
struct FUN_0044b2c0
{
    ~FUN_0044b2c0();
    void* p;
};
struct FUN_00441d20
{
    ~FUN_00441d20();
    char pad[0x38];
};
struct FUN_00442040 : public FUN_00441d20
{
    NiPtrNode_S a;
    FUN_0044b2c0 b;
    ~FUN_00442040();
};

// Destructor for the object; the compiler-generated member destructors run for the embedded NiPtrNode_S and FUN_0044b2c0 members.
// @fnv 0x00442040
FUN_00442040::~FUN_00442040()
{}
}  // namespace fnv_00442040

namespace fnv_004431f0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_004431f0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x004431f0
void* DelStandIn::FUN_004431f0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_004431f0

namespace fnv_00443240 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00443240(unsigned int flags);
};
// Runs the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00443240
void* DelStandIn::FUN_00443240(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00443240

struct FUN_00449fd0
{
    FUN_00449fd0();
    ~FUN_00449fd0();
    char pad[0x18];
};
struct FUN_00449610 : public FUN_00449fd0
{
    void* p18;
    void* p1c;
    FUN_00449610();
    void FUN_0044a0a0();
};

// Initializes p18 and p1c to null, then calls FUN_0044a0a0.
// @fnv 0x00449610
FUN_00449610::FUN_00449610()
{
    p18 = 0;
    p1c = 0;
    FUN_0044a0a0();
}

namespace fnv_00449fd0 {
struct _ref_006815c0
{
    void* p;
    _ref_006815c0();
    _ref_006815c0(const _ref_006815c0&);
};
struct FUN_0065d3a0
{
    void* data[4];
    FUN_0065d3a0(_ref_006815c0 arg);
    ~FUN_0065d3a0();
};
struct FUN_00449fd0 : public FUN_0065d3a0
{
    FUN_00449fd0();
    void FUN_0044a240(int);
};

// Constructs the base with a default reference and initializes the object by calling FUN_0044a240 with 0.
// @fnv 0x00449fd0
FUN_00449fd0::FUN_00449fd0() : FUN_0065d3a0(_ref_006815c0())
{
    FUN_0044a240(0);
}
}  // namespace fnv_00449fd0

struct ConstIterStandIn
{
    int a;
    int b;
};
struct FaceGenImageView : ConstIterStandIn
{
};
struct FaceGenImage
{
    FaceGenImageView _Doraise();
};
struct VecStandIn
{
    FaceGenImageView CallWithSelf();
    FaceGenImageView FUN_0044a1a0(ConstIterStandIn, ConstIterStandIn);
    void FUN_0044a0a0();
};
// Calls FUN_0044a1a0 with the results of _Doraise and CallWithSelf, discarding the returned iterator.
// @fnv 0x0044a0a0
void VecStandIn::FUN_0044a0a0()
{
    FUN_0044a1a0(((FaceGenImage*)this)->_Doraise(), CallWithSelf());
}

struct PairStandIn
{
    int first;
    int second;
    bool FUN_0065dfd0(const PairStandIn&);
};
int __cdecl FUN_0044d600(int, int, int);
struct ModelLoaderStandIn
{
    char pad[0x10];
    int field10;
    PairStandIn FUN_0065ded0(int, int);
    void FUN_0065f2b0(int, int);
    PairStandIn FUN_0044a1a0(int, int, int, int);
};
// @fnv 0x0044a1a0
PairStandIn ModelLoaderStandIn::FUN_0044a1a0(int aiFirstA, int aiFirstB, int aiSecondA, int aiSecondB)
{
    PairStandIn r1 = FUN_0065ded0(aiFirstA, aiFirstB);
    PairStandIn r2 = FUN_0065ded0(aiSecondA, aiSecondB);
    if (r1.FUN_0065dfd0(r2))
    {
        int tmp = FUN_0044d600(r2.second, field10, r1.second);
        FUN_0065f2b0(tmp, field10);
        field10 = tmp;
    }
    return r1;
}

namespace fnv_0043abf0 {
void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(char const*);

struct GO
{
    GO(int);
    ~GO();
};

struct NP_0081c630 : GO
{
    NP_0081c630(int x) : GO(x)
    {}
    NP_0081c630& operator=(void*);
};

struct FUN_0043abf0
{
    char* m_str;
    int m_iWordAt04;
    int m_8;
    NP_0081c630 m_ptr;

    FUN_0043abf0(const char* apStr, void* apPtr);
};

// @fnv 0x0043abf0
FUN_0043abf0::FUN_0043abf0(const char* apStr, void* apPtr) : m_ptr(0)
{
    unsigned int len = BSStringLength(apStr) + 1;
    m_str = new char[len];
    TaskQueueInterface::CopyStringToBuffer(m_str, len, apStr);
    m_ptr = apPtr;
    m_iWordAt04 = 0;
    m_8 = 0;
}
}  // namespace fnv_0043abf0

namespace fnv_0043baf0 {
void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(const char*);
struct FUN_0043baf0;
struct ModelLoaderStandIn
{
    bool DispatchVirtualCall(char*, FUN_0043baf0*);
};
struct FUN_0043baf0
{
    int field0;
    char* pName;
    int arg;
    char flag;
    char flag2;
    FUN_0043baf0(const char*, int);
};
// @fnv 0x0043baf0
FUN_0043baf0::FUN_0043baf0(const char* name, int aiArg)
{
    unsigned int len;
    char* buf;
    arg = aiArg;
    len = BSStringLength(name) + 1;
    buf = (char*)operator new(len);
    pName = buf;
    TaskQueueInterface::CopyStringToBuffer(pName, len, name);
    flag = ((ModelLoaderStandIn*)g_modelLoader)->DispatchVirtualCall(pName, this);
    flag2 = 0;
    field0 = 0;
}
}  // namespace fnv_0043baf0

namespace fnv_0043bd10 {
bool __cdecl CleanPath(const char*, char*, unsigned int);
struct FUN_0063fa10
{
    void FUN_00c3cee0(const char*);
    void LookupFileEntryByArchive(int);
};
struct QBase
{
    QBase(int);
    virtual ~QBase();
    char pad[0x2c];
};
struct GO
{
    GO(int);
    ~GO();
    char pad[4];
};
struct FUN_0043bd10 : public QBase
{
    GO go;
    bool flag;
    FUN_0043bd10(const char* apFileName, int aePriority);
    virtual ~FUN_0043bd10();
};
// @fnv 0x0043bd10
FUN_0043bd10::FUN_0043bd10(const char* apFileName, int aePriority) : QBase(aePriority), go(0)
{
    char szStandardPath[260];
    flag = false;
    CleanPath(apFileName, szStandardPath, 260);
    ((FUN_0063fa10*)this)->FUN_00c3cee0(szStandardPath);
    ((FUN_0063fa10*)this)->LookupFileEntryByArchive(1);
}
}  // namespace fnv_0043bd10

namespace fnv_0043be60 {
struct GeometryRelatedType;
struct Twin_00c3cf40
{
    void SetD3DPixelShader(GeometryRelatedType* const);
};
struct QBase
{
    char pad[0x2c];
    QBase(int);
    ~QBase();
    virtual void vf();
};
struct GO
{
    int p;
    GO(int);
    ~GO();
};
struct FUN_0043be60 : public QBase
{
    GO go;
    char flag;
    FUN_0043be60(GeometryRelatedType*, int);
};
// @fnv 0x0043be60
FUN_0043be60::FUN_0043be60(GeometryRelatedType* shader, int arg) : QBase(arg), go(0)
{
    flag = 0;
    ((Twin_00c3cf40*)this)->SetD3DPixelShader(shader);
}
}  // namespace fnv_0043be60

namespace fnv_0043c6e0 {
extern int DAT_01016890;

struct QBase
{
    QBase(int);
    virtual ~QBase();
};

struct GO
{
    GO(int);
    ~GO();
};

struct FUN_0063fa10
{
    void FUN_00c3cee0(char const*);
    void LookupFileEntryByArchive(int);
};

struct FUN_0043c7d0_shell
{
    void FUN_0043c7d0(unsigned char);
};

struct FUN_0043c7a0_arg
{
    unsigned char b;
};

void __fastcall FUN_0043c7a0(char*, FUN_0043c7a0_arg);

struct FUN_0043c6e0 : QBase
{
    char pad[0x30 - sizeof(QBase)];
    GO m_go;
    int m_34;
    int m_38;
    char m_3c;
    float m_40;

    FUN_0043c6e0(const char* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5);
    virtual ~FUN_0043c6e0();
};

// @fnv 0x0043c6e0
FUN_0043c6e0::FUN_0043c6e0(const char* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5) : QBase(a2), m_go(0)
{
    m_34 = 0;
    m_38 = a3;
    m_3c = 0;
    ((FUN_0063fa10*)this)->FUN_00c3cee0(a1);
    ((FUN_0063fa10*)this)->LookupFileEntryByArchive(0);
    FUN_0043c7a0((char*)this, a4);
    ((FUN_0043c7d0_shell*)this)->FUN_0043c7d0(a5);
    m_40 = 0.0f;
}
}  // namespace fnv_0043c6e0

namespace fnv_0043c890 {
extern int DAT_01016890;

struct QBase
{
    QBase(int);
    virtual ~QBase();
};

struct GO
{
    GO(int);
    ~GO();
};

struct FUN_0063fa10
{
    void FUN_00c3cee0(char const*);
    void LookupFileEntryByArchive(int);
};

struct FUN_0043c7d0_shell
{
    void FUN_0043c7d0(unsigned char);
};

struct FUN_0043c7a0_arg
{
    unsigned char b;
};

void __fastcall FUN_0043c7a0(char*, FUN_0043c7a0_arg);

struct QueuedModelParam
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual const char* vfn5();
};

struct FUN_0043c890 : QBase
{
    char pad[0x30 - sizeof(QBase)];
    GO m_go;
    QueuedModelParam* m_34;
    int m_38;
    char m_3c;
    float m_40;

    FUN_0043c890(QueuedModelParam* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5);
    virtual ~FUN_0043c890();
};

// @fnv 0x0043c890
FUN_0043c890::FUN_0043c890(QueuedModelParam* apModelParam, int aiBaseArg, int a3, FUN_0043c7a0_arg aByteArg,
                           unsigned char a5)
    : QBase(aiBaseArg), m_go(0)
{
    m_34 = apModelParam;
    m_38 = a3;
    m_3c = 0;
    ((FUN_0063fa10*)this)->FUN_00c3cee0(apModelParam->vfn5());
    ((FUN_0063fa10*)this)->LookupFileEntryByArchive(0);
    FUN_0043c7a0((char*)this, aByteArg);
    ((FUN_0043c7d0_shell*)this)->FUN_0043c7d0(a5);
    m_40 = 0.0f;
}
}  // namespace fnv_0043c890

namespace fnv_0043e0f0 {
extern int _data_011c16bc;
struct QBase
{
    virtual void vf();
    ~QBase();
    int base[11];
    QBase(int);
};
struct FUN_0044afe0
{
    int v;
    FUN_0044afe0(int);
    ~FUN_0044afe0();
};
struct FUN_0063fa10
{
    void FUN_00c3cee0(const char*);
    void LookupFileEntryByArchive(int);
};

struct FUN_0043e0f0 : public QBase
{
    FUN_0044afe0 m;
    bool flag;
    FUN_0043e0f0(const char* apFileName, int aePriority);
};

// @fnv 0x0043e0f0
FUN_0043e0f0::FUN_0043e0f0(const char* apFileName, int aePriority) : QBase(aePriority), m(0)
{
    flag = false;
    ((FUN_0063fa10*)this)->FUN_00c3cee0(apFileName);
    ((FUN_0063fa10*)this)->LookupFileEntryByArchive(0);
}
}  // namespace fnv_0043e0f0

namespace fnv_0043e210 {
extern int _data_011c16bc;
void __fastcall SetFieldCToFive(char*);
struct QBase
{
    virtual void vf();
    ~QBase();
    int base[11];
    QBase(int);
};
struct FUN_0044afe0
{
    int v;
    FUN_0044afe0(int);
    ~FUN_0044afe0();
};

struct FUN_0043e210 : public QBase
{
    FUN_0044afe0 m;
    bool flag;
    FUN_0043e210(KFModel* apKF, int aePriority);
};

// Initializes the base with aePriority, clears m and flag, stores apKF into m, then calls SetFieldCToFive on this.
// @fnv 0x0043e210
FUN_0043e210::FUN_0043e210(KFModel* apKF, int aePriority) : QBase(aePriority), m(0)
{
    flag = false;
    ((NiPointer<KFModel>*)&m)->operator=(apKF);
    SetFieldCToFive((char*)this);
}
}  // namespace fnv_0043e210

namespace fnv_0043eaf0 {
struct QueuedFileBase
{
    char pad[0x24];
    QueuedFileBase(int);
    ~QueuedFileBase();
    virtual void vf();
};
struct GO
{
    int p;
    GO(int);
    ~GO();
};
struct FUN_0043eaf0 : public QueuedFileBase
{
    int owner;
    GO spA;
    GO spB;
    FUN_0043eaf0(int, int);
};
// Constructs a QueuedFileBase from b, stores a in owner, and default-constructs spA and spB with 0.
// @fnv 0x0043eaf0
FUN_0043eaf0::FUN_0043eaf0(int aiOwner, int aiBaseArg) : QueuedFileBase(aiBaseArg), owner(aiOwner), spA(0), spB(0)
{}
}  // namespace fnv_0043eaf0

namespace fnv_0043ecb0 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct IncompleteStruct;
struct ReactionInfo;
struct CloningProcess;
struct NiCullingProcess;
struct NiObject;
struct NiUpdateData;
struct TESDescription;
struct TESFile;
struct blob48
{
    char b[48];
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_0043ecb0_shell : public QueuedHead
{
    void FUN_0043ecb0();
};

int __fastcall FUN_0084e3a0(const void*);
void* __fastcall FUN_00726070(void*);
void __cdecl FUN_00652140();
void __cdecl FUN_00652190();
struct MemCtx
{
    MemCtx(int, bool, const char*, int);
    ~MemCtx();
    int pad[1];
};
struct TESNPC
{
    void GetFaceGenNodes(unsigned int*, unsigned int*);
};
struct TESRace
{
    void ClearFaceGenUndo();
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
    int p;
};
struct HeadLayout
{
    char pad[0x28];
    TESNPC* npc;
    NP_0081c630 skinned;
    NP_0081c630 biped;
};
// @fnv 0x0043ecb0
void FUN_0043ecb0_shell::FUN_0043ecb0()
{
    FUN_00652140();
    MemCtx tempMemContext(0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x5f9);
    unsigned int pbipedNode3;
    unsigned int pskinnedNode;
    pskinnedNode = 0;
    pbipedNode3 = 0;
    ((HeadLayout*)this)->npc->GetFaceGenNodes(&pskinnedNode, &pbipedNode3);
    ((HeadLayout*)this)->skinned = (void*)pskinnedNode;
    ((HeadLayout*)this)->biped = (void*)pbipedNode3;
    if (FUN_0084e3a0(((HeadLayout*)this)->npc) == 7)
    {
        TESRace* prace = (TESRace*)FUN_00726070((char*)((HeadLayout*)this)->npc + 0x10c);
        prace->ClearFaceGenUndo();
    }
    FUN_00652190();
}
}  // namespace fnv_0043ecb0

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00441ba0_shell : public QueuedPlayer
{
    void FUN_00441ba0();
};

struct PC7d
{
    void LoadIdleAnimations(IO_TASK_PRIORITY, FUN_00441ba0_shell*);
};
extern PC7d* g_thePlayer;
extern int _data_011c16bc;
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct Q441560
{
    void LoadBipedModel();
};

// @fnv 0x00441ba0
void FUN_00441ba0_shell::FUN_00441ba0()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x94e);
    g_thePlayer->LoadIdleAnimations(((IOTask*)this)->FUN_0043cc60(), this);
    ((Q441560*)this)->LoadBipedModel();
}

namespace fnv_00441d80 {
extern int _data_011c16bc;
void __fastcall SetFieldCToFive(char*);
struct QBase
{
    virtual void vf();
    ~QBase();
    int base[11];
    QBase(int);
};

struct FUN_00441d80 : public QBase
{
    NiPointer<LoadedFile> m_pLoadedFile;
    int m_iLoadPriority;
    FUN_00441d80(LoadedFile* apFile, int aePriority);
};

// @fnv 0x00441d80
FUN_00441d80::FUN_00441d80(LoadedFile* apFile, int aePriority) : QBase(aePriority), m_pLoadedFile(0)
{
    m_iLoadPriority = 3;
    m_pLoadedFile = apFile;
    SetFieldCToFive((char*)this);
}
}  // namespace fnv_00441d80

namespace fnv_00441f80 {
struct QueuedFileLoadBase
{
    char pad[0x34];
    QueuedFileLoadBase(int, int, int);
    ~QueuedFileLoadBase();
    virtual void vf();
};
struct GO
{
    int p;
    GO(int);
    ~GO();
};
struct MeshPtr
{
    int p;
    MeshPtr(int);
};
struct FUN_00441f80 : public QueuedFileLoadBase
{
    GO m_kObject;
    MeshPtr m_pMesh;
    FUN_00441f80(int, int, int);
};
// Constructs a QueuedFileLoadBase with the given arguments and initialises its two member objects to zero.
// @fnv 0x00441f80
FUN_00441f80::FUN_00441f80(int a, int b, int c) : QueuedFileLoadBase(a, b, c), m_kObject(0), m_pMesh(0)
{}
}  // namespace fnv_00441f80

extern int DAT_01016e50;

void* __cdecl operator new(unsigned int);

template <typename T> struct LockFreeQueue
{
    char pad[0x40];
    LockFreeQueue(unsigned int, unsigned int);
};

struct BSTaskManagerThread
{
    BSTaskManagerThread(unsigned int, const char*);
    virtual ~BSTaskManagerThread();
};

struct FUN_004421d0 : BSTaskManagerThread
{
    char pad[0x30 - sizeof(BSTaskManagerThread)];
    char m_30;
    int m_34;
    LockFreeQueue<NiPointer<QueuedReference> >* m_pQueue;

    FUN_004421d0(unsigned int aiMaxThreads);
    virtual ~FUN_004421d0();
};

// Constructs a BackgroundCloneThread task manager thread, initializing its state and allocating a lock-free queue sized by aiMaxThreads.
// @fnv 0x004421d0
FUN_004421d0::FUN_004421d0(unsigned int aiMaxThreads) : BSTaskManagerThread(3, "BackgroundCloneThread")
{
    m_34 = 0;
    m_30 = 0;
    m_pQueue = new LockFreeQueue<NiPointer<QueuedReference> >(aiMaxThreads, 8);
}

extern int _data_011c16bc;
struct QueueObj
{
    int state;
    QueueObj(int);
    ~QueueObj();
};
struct QueueModelHolder
{
    void FUN_00443dc0(int, QueueObj*, int, int, int, bool, bool, bool, float);
    void FUN_00443d30(int apModel, int a, int b, int c, bool d, bool e, bool f);
};

// Constructs a QueueObj with state 0 and forwards it with the model and flags to FUN_00443dc0 using a zero float.
// @fnv 0x00443d30
void QueueModelHolder::FUN_00443d30(int apModel, int aiArg1, int aiArg2, int aiArg3, bool abFlag1, bool abFlag2,
                                    bool abFlag3)
{
    QueueObj spqueuedModel(0);
    FUN_00443dc0(apModel, &spqueuedModel, aiArg1, aiArg2, aiArg3, abFlag1, abFlag2, abFlag3, 0.0f);
}

namespace fnv_00444f10 {
struct MagicItem;
struct TESEffectShader;
struct TESFile;
struct TESObjectLIGH;
struct TESSound;
struct blob8
{
    char b[8];
};
struct TESDescription : public BaseFormComponent
{
    virtual char* GetDescription(TESForm*, int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    static void LoadDescriptionAtOffset(TESDescription*, int);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetDescriptionLength(TESForm*);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm*);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long);
    void LoadDescriptionForForm(TESForm*, int);
    void UnLoadDescription();
    void SetDescription(char*);
    unsigned long m_uiDescriptionFileOffset;
};
typedef char _sizecheck_TESDescription[sizeof(TESDescription) == 8 ? 1 : -1];
struct EffectSetting : public TESForm, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
    virtual void __vslot_10();
    virtual void Save();
    virtual bool Load(TESFile*);
    virtual void InitItem();
    virtual void Copy(TESForm*);
    virtual bool Compare(TESForm*);
    bool IsFlagSet(int);
    bool IsFlagSetAll(unsigned int);
    bool IsFlagSetAny(unsigned int);
    void SetFlag(int, bool);
    void Disable();
    void Enable();
    bool IsDisabled();
    int IsRangeAll();
    int GetRangeFlags();
    bool ShouldNegateMagnitude(int);
    bool IsAssociatedFormUsed();
    bool IsAssociatedActorValueUsed();
    bool IsAssociatedActorValueFixed();
    bool IsScriptEffect();
    int GetProjectileType();
    void SetProjectileType(int);
    struct blob8 GetEffectName();
    void UpdateEffectName(char*);
    float GetBaseCost();
    void SetBaseCost(float);
    TESForm* GetAssociatedForm();
    void SetAssociatedForm(TESForm*);
    int GetAssociatedActorValue();
    void SetAssociatedActorValue(int);
    int GetEffectID();
    void SetAssociatedSkill(int);
    void* GetCounterEffects();
    int GetNumCounterEffects();
    void SetCounterEffects(void*);
    int GetResistanceVariable();
    void SetResistanceVariable(int);
    static EffectSetting* CreateFilter();
    bool FilterCompare(EffectSetting*, bool, unsigned int);
    TESSound* GetCastSound();
    void SetCastSound(TESSound*);
    TESSound* GetBoltSound();
    void SetBoltSound(TESSound*);
    TESSound* GetHitSound();
    void SetHitSound(TESSound*);
    TESSound* GetAreaSound();
    void SetAreaSound(TESSound*);
    TESObjectLIGH* GetLight();
    void SetLight(TESObjectLIGH*);
    TESEffectShader* GetEffectShader();
    void SetEffectShader(TESEffectShader*);
    TESEffectShader* GetEnchantEffectShader();
    void SetEnchantEffectShader(TESEffectShader*);
    void SetProjectileSpeed(float);
    float GetProjectileSpeed();
    void SetConstantEffectEnchantmentFactor(float);
    float GetConstantEffectEnchantmentFactor();
    void SetConstantEffectBarterFactor(float);
    float GetConstantEffectBarterFactor();
    int GetEffectArchetype();
    void SetEffectArchetype(int);
    virtual char* GetObjectDisplayName();
    bool HasEffectID();
    bool UsesAssociatedActorValue();
    int IncAssociatedItemLoadedCount();
    int DecAssociatedItemLoadedCount();
    int QueueAssociatedItem();
    int QueueAssociatedItemFinished();
    bool IsModelLoaded();
    bool HasNoAssociatedActorValue();
    int IncEffectLoadedCount();
    int DecEffectLoadedCount();
    int QueueEffect();
    int QueueEffectFinished();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetNumCounterEffects(short);
    void __local_vftable_ctor_closure();
    int* m_pEffectSettingCallback;
    void* m_pPredicateData;
    char data[72];
    char counterEffects[8];
    int m_iActorValue;
    int m_iEffectID;
};
typedef char _sizecheck_EffectSetting[sizeof(EffectSetting) == 176 ? 1 : -1];
struct FUN_00444f10_shell : public ModelLoader
{
    void FUN_00444f10(MagicItem*, EffectSetting*, int);
};

class QueuedMagicItem
{
  public:
    QueuedMagicItem(MagicItem*, EffectSetting*, IO_TASK_PRIORITY);
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void DispatchToManager();
    char data[0x2c];
};
struct GlobalObject_00528cb0Ptr
{
    GlobalObject_00528cb0Ptr(QueuedMagicItem*);
    ~GlobalObject_00528cb0Ptr();
    operator QueuedMagicItem*() const;
    QueuedMagicItem* p;
};

// @fnv 0x00444f10
void FUN_00444f10_shell::FUN_00444f10(MagicItem* apMagicItem, EffectSetting* apAVEffectSetting, int aePriority)
{
    if (!apMagicItem || !apAVEffectSetting)
        return;
    GlobalObject_00528cb0Ptr spqueuedMagicItem(
        new QueuedMagicItem(apMagicItem, apAVEffectSetting, (IO_TASK_PRIORITY)aePriority));
    ((QueuedMagicItem*)spqueuedMagicItem)->DispatchToManager();
}
}  // namespace fnv_00444f10

struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct InventoryChanges;
struct MagicItemForm;
struct PackageList;
struct TESActorBase;
struct TESAmmo;
struct TESFaction;
struct TESFile;
struct TESLevItem;
struct TESNPC;
struct TESRace;
struct TESActorBaseData : public BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    void SetTemplateUseFlag(int, bool);
    bool GetTemplateUseFlag(int);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm*);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short);
    bool GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void SetTemplateReference(TESObjectREFR*);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    int* GetFlags();
    void SetFlags(int);
    bool GetFlagBit(int);
    void UpdateFlagBit(int, bool, bool);
    bool IsEssentialActor();
    void SetEssential(bool);
    bool GetRespawn();
    void SetRespawn(bool);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool, bool);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool);
    bool GetNotPushable();
    void SetNotPushable(bool);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    bool GetSummonable();
    void SetSummonable(bool);
    bool GetNoRumors();
    void SetNoRumors(bool);
    void SetNoVATSMelee(bool);
    void SetAllowPCDialogue(bool);
    void SetAllowPickPocket(bool);
    void SetIsGhost(bool);
    void SetInvulnerable(bool);
    void SetCantOpenDoors(bool);
    void SetCanBeAllRaces(bool);
    void SetAutoCalcServiceFlags(bool);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem*);
    void SetFatigue(unsigned short);
    static int ConvertToInteger(float);
    static char* GetActorDisplayName(Actor*);
    void SetKarmaValue(float);
    void ModKarma(float);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    void SetSpeedMult(unsigned short);
    void SetVoiceType(BGSVoiceType*);
    void AddFormChange(int);
    void RemoveFormChange(int);
    void AddFormChangeFlags(int);
    void ClearChangeFlags(int);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int);
    bool HasFaction(TESFaction*);
    void RemoveAllFactions();
    void CopyFactionList(TESActorBaseData*);
    void* __vecDelDtor(unsigned int);
    char actorData[24];
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    char m_pVoiceType[8];
};
typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];
struct TESContainer : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges*);
    InventoryItemEntry* AddObject(TESObject*, int, ContainerItemExtra*);
    void AddDuplicateObject(InventoryItemEntry*);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry*);
    void ReplaceObject(TESObject*, TESObject*);
    bool HasObjectOfType(TESObject*);
    float GetContainerWeight(bool);
    int GetObjectCount(TESObject*);
    char Compare(InventoryItemEntry*, InventoryItemEntry*);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char);
    static bool IsValidContainerObject(TESObject*);
    void MergeContainer(TESContainer*);
    void MultiplyContainerCounts(int);
    void SetClothingModifier(float);
    void AddContentsFromReference(TESObjectREFR*, bool);
    void AddInventoryChangesToContainer(int, InventoryChanges*);
    TESAmmo* GetBestAmmoForActor(TESActorBase*);
    TESObjectWEAP* GetBestWeapon(TESActorBase*);
    TESObjectARMO* FindBestArmor(TESActorBase*, int);
    TESObjectCLOT* GetBestClothing(TESActorBase*, int);
    TESBoundObject* GetInventoryEntryData(int);
    void* GetObjectList();
    void* GetObjectListEnd();
    void* __vecDelDtor(unsigned int);
    char objectList[8];
};
typedef char _sizecheck_TESContainer[sizeof(TESContainer) == 12 ? 1 : -1];
struct BGSTouchSpellForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static MagicItemForm* GetFormTouchSpell(TESForm*);
    MagicItemForm* GetFormTouchSpell();
    void SetFormTouchSpell(MagicItemForm*);
    static unsigned short GetFormTouchSpellAnimation(TESForm*);
    unsigned short GetFormTouchSpellAnimation();
    void SetFormTouchSpellAnimation(unsigned short);
    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
    char _pad_a[2];
};
typedef char _sizecheck_BGSTouchSpellForm[sizeof(BGSTouchSpellForm) == 12 ? 1 : -1];
struct TESAIForm : public BaseFormComponent
{
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(TESAIForm*);
    unsigned char GetAggression();
    void SetAggression(unsigned char, bool);
    unsigned char GetAssistance();
    void SetAssistance(unsigned char);
    static float GetConfidenceLevel(unsigned char);
    float GetConfidenceLevel();
    unsigned char GetConfidence();
    void SetConfidence(unsigned char, bool);
    unsigned char GetEnergy();
    void SetEnergy(unsigned char, bool);
    unsigned char GetResponsibility();
    void SetResponsibility(unsigned char, bool);
    unsigned char GetMood();
    void SetAIMood(unsigned char);
    unsigned int GetServiceFlags();
    void SetServiceFlags(unsigned int, bool);
    bool GetOffersService(unsigned int);
    void SetOffersService(unsigned int, bool);
    int GetTrainingSkill();
    void SetTrainingSkill(int);
    unsigned char GetTrainingSkillLevel();
    void SetTrainingSkillLevel(unsigned char);
    void SetAIData(PackedRecordData*);
    bool IsObjectUsable(TESObject*);
    bool HasAnAggroRadius();
    void SetHasAggroRadius(bool);
    unsigned int GetAggroRadius();
    void SetAggroRadius(unsigned int);
    bool HasPackage(TESPackage*);
    void AddPackage(TESPackage*);
    bool MovePackage(TESPackage*, bool);
    void InsertPackageAt(TESPackage*, TESPackage*, bool);
    void DeletePackage(TESPackage*);
    static TESPackage* GetCurrentPackage(Actor*);
    static void FindAvailablePackages(Actor*, void*, float, float);
    void AddFormChange(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    PackageList* GetPackageList();
    void* __vecDelDtor(unsigned int);
    char m_kAIData[20];
    char m_kPackageList[8];
};
typedef char _sizecheck_TESAIForm[sizeof(TESAIForm) == 32 ? 1 : -1];
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
struct TESAnimation : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    bool IsKFFileInList(char*);
    void AddKFFile(char*);
    bool HasSpecialAnimations();
    void* GetKFFileList();
    void Save(int);
    void LoadAnimationChunk(TESAnimation*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void* __vecDelDtor(unsigned int);
    char m_kKFFileList[8];
};
typedef char _sizecheck_TESAnimation[sizeof(TESAnimation) == 12 ? 1 : -1];
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct TESRaceForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESRace* GetFormRace(TESForm*);
    TESRace* GetFormRace();
    static char* GetFormRaceEditorID(TESForm*);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace*);
    TESRace* m_pRace;
};
typedef char _sizecheck_TESRaceForm[sizeof(TESRaceForm) == 8 ? 1 : -1];
struct FUN_00444fe0_shell : public ModelLoader
{
    void FUN_00444fe0(TESNPC*, void*, int, QueuedFile*);
};

struct QHeadLocal
{
    QHeadLocal(TESNPC*, int);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    void SetParent(QueuedFile*);
    int pad[13];
};
struct QHeadPtr
{
    QHeadPtr(QHeadLocal*);
    ~QHeadPtr();
    operator QHeadLocal*() const;
    int p;
};
struct QHeadPtrDest
{
    QHeadPtrDest& Assign(const QHeadPtr&);
};
// Creates a QHeadLocal for apNPC at aePriority, sets its parent to apParent, runs its vfn_20, and assigns it into aspQueuedHead.
// @fnv 0x00444fe0
void FUN_00444fe0_shell::FUN_00444fe0(TESNPC* apNPC, void* aspQueuedHead, int aePriority, QueuedFile* apParent)
{
    QHeadPtr spqueuedHead(new QHeadLocal(apNPC, aePriority));
    ((QHeadLocal*)spqueuedHead)->SetParent(apParent);
    ((QHeadLocal*)spqueuedHead)->vfn_20();
    ((QHeadPtrDest*)aspQueuedHead)->Assign(spqueuedHead);
}

void* __cdecl operator new(unsigned int);
struct QIdle
{
    QIdle(void*, int, void*, void*);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    int pad[15];
};
struct QIdlePtr
{
    QIdlePtr(QIdle*);
    ~QIdlePtr();
    operator QIdle*() const;
    QIdlePtr& operator=(QIdle*);
    int p;
};
struct IdleMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(void*, QIdlePtr*, int);
};
struct FUN_00445200_holder : public ModelLoader
{
    void* a;
    void* b;
    void* c;
    void* d;
    IdleMap* m_pQueuedAnimIdleMap;
    void* InsertIdle(void* apIdle, void* apKey, int aePriority, void* apParent);
};
// Allocates a QIdle from the given arguments, inserts it into the idle map by key, and calls its virtual slot 20 on success.
// @fnv 0x00445200
void* FUN_00445200_holder::InsertIdle(void* apIdle, void* apKey, int aePriority, void* apParent)
{
    QIdlePtr spqueuedIdle(new QIdle(apIdle, aePriority, apKey, apParent));
    if (m_pQueuedAnimIdleMap->Insert(apKey, &spqueuedIdle, 0))
        ((QIdle*)spqueuedIdle)->vfn_20();
    else
        spqueuedIdle = 0;
    return 0;
}

namespace fnv_004471c0 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_004471c0_shell : public ModelLoader
{
    KFModel* LoadKFModel(char*);
};

void __cdecl _FNV_Warning(const char*, ...);
struct QueuedChildren
{
    void AddFinishedChild();
};
struct Flt
{
    operator unsigned int() const;
    int pad[3];
};
struct QueuedKFLocal
{
    QueuedKFLocal(const char*, int);
    ~QueuedKFLocal();
    void FUN_0043e2a0();
    void FUN_0043e4b0();
    int pad[12];
};
struct KFMap
{
    virtual void Slot0();
    virtual void Slot1();
    virtual bool Get(const char*, KFModel**);
};
int __fastcall FUN_004431b0(KFModel*);
// @fnv 0x004471c0
KFModel* FUN_004471c0_shell::LoadKFModel(char* apFilename)
{
    Flt autoEvent3;
    KFModel* pkfModel2 = 0;
    if (!((KFMap**)this)[1]->Get(apFilename, &pkfModel2))
    {
        QueuedKFLocal queuedKF(apFilename, 0);
        queuedKF.FUN_0043e2a0();
        queuedKF.FUN_0043e4b0();
        pkfModel2 = (KFModel*)(unsigned int)autoEvent3;
    }
    else
    {
        if (!FUN_004431b0(pkfModel2))
            _FNV_Warning("MODELS: LoadKF retrieved animation %s with a zero ref count", apFilename);
    }
    if (pkfModel2)
        ((QueuedChildren*)pkfModel2)->AddFinishedChild();
    return pkfModel2;
}
}  // namespace fnv_004471c0

struct FUN_00447850_shell : public ModelLoader
{
    void* FUN_00447850(void*, void*);
};

void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(const char*);
struct StrList
{
    StrList();
    void AddHead(char**);
    const char** FUN_006815c0();
    StrList* FUN_00726070();
    int pad[2];
};
// @fnv 0x00447850
void* FUN_00447850_shell::FUN_00447850(void* apList, void* apDestList)
{
    StrList* pList = (StrList*)apList;
    StrList* pBaseList = (StrList*)apDestList;
    if (!pBaseList)
        pBaseList = new StrList;
    while (pList)
    {
        const char* pfilename = *pList->FUN_006815c0();
        int ifilenameLen = BSStringLength(pfilename) + 1;
        char* ptmpFilename = new char[ifilenameLen];
        TaskQueueInterface::CopyStringToBuffer(ptmpFilename, ifilenameLen, pfilename);
        pBaseList->AddHead(&ptmpFilename);
        pList = pList->FUN_00726070();
    }
    return pBaseList;
}

namespace fnv_00448c10 {
struct Flt
{
    operator unsigned int() const;
};
struct GlobalObject_00528cb0 : public Flt
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    void* pObj;
};
struct Q449
{
    bool FUN_00449280(void*);
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release();
};

// Iterates the container at self+0x1c via FUN_00449280, calling Release on each object until the iterator is empty, then returns true.
// @fnv 0x00448c10
bool __fastcall ReleaseAllObjects(char* self)
{
    GlobalObject_00528cb0 iter(0);
    ((Q449*)*(void**)(self + 0x1c))->FUN_00449280(&iter);
    while (iter)
    {
        ((Obj*)(unsigned int)iter)->Release();
        ((Q449*)*(void**)(self + 0x1c))->FUN_00449280(&iter);
    }
    return true;
}
}  // namespace fnv_00448c10

namespace fnv_00448ed0 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_00448ed0_shell : public ModelLoader
{
    bool InsertQueuedTexture(BSFileEntry*, QueuedTexture*);
};

struct GlobalObject_00528cb0
{
    int value;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};
struct QueuedTextureMapStandIn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(BSFileEntry*, GlobalObject_00528cb0*, int);
};
// Wraps apQueuedTexture in a GlobalObject_00528cb0 and inserts apFileEntry with it into the map at this+0x20, returning the insert result.
// @fnv 0x00448ed0
bool FUN_00448ed0_shell::InsertQueuedTexture(BSFileEntry* apFileEntry, QueuedTexture* apQueuedTexture)
{
    bool bresult;
    {
        GlobalObject_00528cb0 obj((int)apQueuedTexture);
        bresult = (*(QueuedTextureMapStandIn**)((char*)this + 0x20))->Insert(apFileEntry, &obj, 0);
    }
    return bresult;
}
}  // namespace fnv_00448ed0

namespace fnv_00448f80 {
struct Flt
{
    operator unsigned int() const;
};
struct GlobalObject_00528cb0 : public Flt
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    void* pObj;
};
struct Target
{
    virtual void v0();
    virtual void v1();
    virtual bool Test(void*, void*);
};
struct Holder
{
    unsigned int FUN_00448f80(void* arg);
    char pad[0x20];
    Target* pTarget;
};

// @fnv 0x00448f80
unsigned int Holder::FUN_00448f80(void* arg)
{
    GlobalObject_00528cb0 iter(0);
    if (pTarget->Test(arg, &iter))
    {
        return iter;
    }
    return 0;
}
}  // namespace fnv_00448f80

struct VecAllocBase
{
    int* FUN_0044abd0(unsigned int);
};
void __cdecl ThrowVectorTooLong();
struct VecAlloc
{
    char pad[0xc];
    int* pBegin;
    int* pCur;
    int* pEnd;
    unsigned int FUN_0044a2c0();
    bool FUN_0044a240(unsigned int);
};
// Resets the vector to empty, then allocates space for n elements if n is nonzero and the capacity allows; returns true on success.
// @fnv 0x0044a240
bool VecAlloc::FUN_0044a240(unsigned int n)
{
    pBegin = 0;
    pCur = 0;
    pEnd = 0;
    if (n == 0)
    {
        return false;
    }
    else
    {
        if (FUN_0044a2c0() < n)
        {
            ThrowVectorTooLong();
        }
        else
        {
            pBegin = ((VecAllocBase*)((char*)this + 8))->FUN_0044abd0(n);
            pCur = pBegin;
            pEnd = pBegin + n;
        }
    }
    return true;
}

namespace fnv_006502f0 {
struct NP
{
    NP(int);
    ~NP();
    void* pData;
};
struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void*);
};
struct Map62d0
{
    bool FUN_006c62d0(unsigned int, NP&);
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int GetFlags();
};
struct FlagSink
{
    void FUN_0044b300(unsigned int);
};
void __cdecl FUN_00652140();
void __cdecl FUN_00652190();
struct GetAtArgs
{
    const char* apcKey;
    Helper62d0* aspModel;
    FlagSink* out;
};

// Looks up args.apcKey in the map at self+4, stores the found entry's model pointer and passes its flags to args.out, returning whether the lookup succeeded.
// @fnv 0x006502f0
bool __fastcall LookupModelAndGetFlags(Map62d0* self, GetAtArgs aLookupArgs)
{
    FUN_00652140();
    NP entry(0);
    bool bFound = false;
    if (((Map62d0*)((char*)self + 4))->FUN_006c62d0((unsigned int)aLookupArgs.apcKey, entry))
    {
        *aLookupArgs.aspModel = (void*)((unsigned int)*(Flt*)&entry + 8);
        aLookupArgs.out->FUN_0044b300(
            ((TESObjectREFR_GetFlags_Helper*)(unsigned int)*(Flt*)aLookupArgs.aspModel)->GetFlags());
        bFound = true;
    }
    FUN_00652190();
    return bFound;
}
}  // namespace fnv_006502f0

// @fnv 0x0043b1d0
int __cdecl FUN_0043b1d0(int* param_1)
{
    return *param_1;
}

struct AbstractHeapLogger;
extern AbstractHeapLogger* DAT_011f6388;

// @fnv 0x0043bce0
bool IsHeapLoggerPresent()
{
    return DAT_011f6388 != 0;
}

namespace fnv_0043bd00 {
struct AbstractHeapLogger;
extern AbstractHeapLogger* DAT_011f6388;

// @fnv 0x0043bd00
AbstractHeapLogger* FUN_0043bd00()
{
    return DAT_011f6388;
}
}  // namespace fnv_0043bd00

void _Deallocate(void*);

struct FUN_0051d400_shell
{
    void FUN_0051d400();
    void* DeleteIfFlagged(unsigned int flags);
};

// @fnv 0x0043d640
void* FUN_0051d400_shell::DeleteIfFlagged(unsigned int flags)
{
    FUN_0051d400();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct QueuedTreeBillboard : IOTask
{
    void ApplyQueuedTexture();
    void QueueForPostProcess();
};

void QueuedTreeBillboard::ApplyQueuedTexture()
{}

// @fnv 0x0043d670
void QueuedTreeBillboard::QueueForPostProcess()
{
    ApplyQueuedTexture();
    AddToPostProcessQueue();
}

namespace fnv_0043d820 {
struct QueuedTreeBillboard
{
    virtual ~QueuedTreeBillboard();
    bool FUN_0043d820(char* apDescription, unsigned int aiBufferSize);
    bool FUN_00c3d0e0(char* apDescription, unsigned int aiBufferSize, const char* apStr);
};

// @fnv 0x0043d820
bool QueuedTreeBillboard::FUN_0043d820(char* apDescription, unsigned int aiBufferSize)
{
    return FUN_00c3d0e0(apDescription, aiBufferSize, "Tree Billboard");
}
}  // namespace fnv_0043d820

struct FaceGenPaletteBase
{
    ~FaceGenPaletteBase();
    void FUN_0043dc50();
};

// @fnv 0x0043dc50
void FaceGenPaletteBase::FUN_0043dc50()
{
    FaceGenPaletteBase::~FaceGenPaletteBase();
}

struct QueuedHelmet
{
    void FUN_0043eff0();
    void ApplyQueuedModels();
};

// @fnv 0x0043eff0
void QueuedHelmet::FUN_0043eff0()
{
    ApplyQueuedModels();
}

struct FUN_0043f010
{
    char m_auiShapeKeys[0x2b0];
    NiRenderer* m_field;
    NiRenderer* Get();
};

// @fnv 0x0043f010
NiRenderer* FUN_0043f010::Get()
{
    return m_field;
}

namespace fnv_0043f1f0 {
extern "C"
{
    void __cdecl SetFlagBit0(unsigned char, void*);
}

struct FUN_0043f1f0_class
{
    void __thiscall FUN_0043f1f0(unsigned char arg);
};

// @fnv 0x0043f1f0
void __thiscall FUN_0043f1f0_class::FUN_0043f1f0(unsigned char arg)
{
    SetFlagBit0(arg, (void*)((char*)this + 0x120));
}
}  // namespace fnv_0043f1f0

struct AttachDistant3DTask
{
    virtual ~AttachDistant3DTask()
    {}
    void* FUN_00440680(unsigned int flags);
    void FUN_004406b0();
};
void __cdecl _Deallocate(void*);

// Calls FUN_004406b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00440680
void* AttachDistant3DTask::FUN_00440680(unsigned int flags)
{
    FUN_004406b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00441980_Class
{
    void FUN_00440eb0();
    void FUN_00441980();
};

// @fnv 0x00441980
void FUN_00441980_Class::FUN_00441980()
{
    FUN_00440eb0();
}

struct BackgroundCloneThread
{
    void __thiscall FUN_004422c0();
    void* __thiscall FUN_00442290(unsigned int flags);
};

// Calls FUN_004422c0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00442290
void* BackgroundCloneThread::FUN_00442290(unsigned int flags)
{
    this->FUN_004422c0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00442630Class
{
    char m_auiShapeKeys[0x30];
    char m_flag;
    void FUN_00442630();
};
// @fnv 0x00442630
void FUN_00442630Class::FUN_00442630()
{
    m_flag = 1;
}

struct QueuedReplacementKFList : IOTask
{
    void FUN_00446a40();
};

// @fnv 0x00446a40
void QueuedReplacementKFList::FUN_00446a40()
{
    IOTask::NotifyParents();
}

struct FUN_00449170_Class
{
    void FUN_00449170();
};

// @fnv 0x00449170
void FUN_00449170_Class::FUN_00449170()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xC) = 6;
}

struct FUN_00449a20_cls
{
    void FUN_004490e0();
    void* FUN_00449a20(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_004490e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00449a20
void* FUN_00449a20_cls::FUN_00449a20(unsigned int flags)
{
    FUN_004490e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
void __fastcall FUN_004499c0(void*);

struct FUN_00449ba0Class
{
    void* FUN_00449ba0(unsigned int flags);
};

// @fnv 0x00449ba0
void* FUN_00449ba0Class::FUN_00449ba0(unsigned int flags)
{
    FUN_004499c0(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __fastcall FUN_004499e0(void*);
void __cdecl _Deallocate(void*);

struct FUN_00449bd0_Class
{
    void* FUN_00449bd0(unsigned int flags);
};

// Calls FUN_004499e0 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00449bd0
void* FUN_00449bd0_Class::FUN_00449bd0(unsigned int flags)
{
    FUN_004499e0(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __fastcall FUN_00449a00(int**);
void __cdecl _Deallocate(void*);

struct FUN_00449c00_class
{
    void* FUN_00449c00(unsigned int flags);
};

// @fnv 0x00449c00
void* FUN_00449c00_class::FUN_00449c00(unsigned int flags)
{
    FUN_00449a00((int**)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

struct FUN_00449d40_class
{
    void __thiscall FUN_00449d60();
    void __thiscall FUN_00449d40();
};

// @fnv 0x00449d40
void __thiscall FUN_00449d40_class::FUN_00449d40()
{
    FUN_00449d60();
}

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

struct FUN_00449ea0_cls
{
    void FUN_00449ec0();
    void FUN_00449ea0();
};

// @fnv 0x00449ea0
void FUN_00449ea0_cls::FUN_00449ea0()
{
    FUN_00449ec0();
}

extern unsigned char DAT_01202df0;

// @fnv 0x0044ada0
void FUN_0044ada0(unsigned char value)
{
    DAT_01202df0 = value;
}

namespace fnv_0044ae10 {
// @fnv 0x0044ae10
unsigned char FUN_0044ae10(unsigned char a)
{
    return (a & 1) != 0;
}
}  // namespace fnv_0044ae10

// Sets or clears bit 0 of the byte pointed to by p according to flag.
// @fnv 0x0044ae20
void SetFlagBit0(bool abSet, unsigned char* p)
{
    if (abSet)
        *p |= 1;
    else
        *p &= 0xfffffffe;
}

namespace fnv_0044ae50 {
// @fnv 0x0044ae50
unsigned char __cdecl FUN_0044ae50(unsigned char a)
{
    return (a & 2) != 0;
}
}  // namespace fnv_0044ae50

// @fnv 0x0044ae60
void FUN_0044ae60(bool bSet, unsigned char* pFlags)
{
    if (bSet)
        *pFlags |= 2;
    else
        *pFlags &= 0xfffffffd;
}

namespace fnv_0044ae90 {
// @fnv 0x0044ae90
char FUN_0044ae90(unsigned char param_1)
{
    return (param_1 & 4) != 0;
}
}  // namespace fnv_0044ae90

// @fnv 0x0044aea0
void FUN_0044aea0(bool abSet, unsigned char* flags)
{
    if (abSet)
        *flags = *flags | 4;
    else
        *flags = *flags & 0xfffffffb;
}

namespace fnv_0044af20 {
// @fnv 0x0044af20
char FUN_0044af20(unsigned char a)
{
    return (a & 8) != 0;
}
}  // namespace fnv_0044af20

// Sets or clears bit 3 (0x8) in the byte pointed to by param2 according to param1.
// @fnv 0x0044af30
void SetFlag8(unsigned char param1, unsigned char* param2)
{
    if (param1)
        *param2 |= 8;
    else
        *param2 &= 0xfffffff7;
}

namespace fnv_0044af60 {
// @fnv 0x0044af60
char FUN_0044af60(unsigned char a)
{
    return (a & 0x10) != 0;
}
}  // namespace fnv_0044af60

// Sets or clears bit 0x10 in the byte pointed to by pByte according to bFlag.
// @fnv 0x0044af70
void FUN_0044af70(bool bFlag, unsigned char* pByte)
{
    if (bFlag)
        *pByte = *pByte | 0x10;
    else
        *pByte = *pByte & 0xFFFFFFEF;
}

// Sets or clears bit 0x20 in the byte pointed to by param2 according to param1.
// @fnv 0x0044afb0
void SetFlag20(unsigned char abSet, unsigned char* pFlags)
{
    if (abSet)
        *pFlags |= 0x20;
    else
        *pFlags &= 0xFFFFFFDF;
}

namespace fnv_0044b030 {
struct KFModel
{
    KFModel* vtable;
    void FUN_0044b030();
    void FUN_0044b050();
};

// @fnv 0x0044b030
void KFModel::FUN_0044b030()
{
    if (vtable)
        vtable->FUN_0044b050();
}
}  // namespace fnv_0044b030

int __cdecl InitScriptRunLock(void*);

struct FUN_0044b2a0_Class
{
    void __thiscall FUN_0044b2a0();
};

// @fnv 0x0044b2a0
void __thiscall FUN_0044b2a0_Class::FUN_0044b2a0()
{
    InitScriptRunLock((char*)this + 0x20);
}

void __cdecl FinishScriptRunLock(void*);

struct FUN_0044b2e0
{
    void Method(void);
};

// @fnv 0x0044b2e0
void __thiscall FUN_0044b2e0::Method(void)
{
    FinishScriptRunLock((char*)this + 0x20);
}

// @fnv 0x0044dff0
bool __fastcall FUN_0044dff0(int* piValue)
{
    return (*piValue & 1) ? true : false;
}

extern unsigned char DAT_011dea2a;

// @fnv 0x00525420
unsigned char FUN_00525420()
{
    return DAT_011dea2a;
}

void __cdecl FUN_0040fca0(unsigned long);
int __cdecl FUN_0043b460(long volatile*, long, long);
struct FUN_0043b410_class
{
    void AtomicAdd(int a);
};
// Atomically adds a to the pointer stored at this+8, retrying with FUN_0040fca0(0) until the compare-and-swap succeeds.
// @fnv 0x0043b410
void FUN_0043b410_class::AtomicAdd(int aiDelta)
{
    long volatile* p = *(long volatile**)((char*)this + 8);
    while (FUN_0043b460((long volatile*)((char*)this + 8), (long)p, (long)p + aiDelta) != (long)p)
    {
        FUN_0040fca0(0);
        p = *(long volatile**)((char*)this + 8);
    }
}

struct FUN_0043c3b0_This
{
    int FUN_0043c3b0();
};

// @fnv 0x0043c3b0
int FUN_0043c3b0_This::FUN_0043c3b0()
{
    return ((int*)this)[3] & 0x7fffffff;
}

namespace fnv_0043d580 {
struct QueuedTreeBillboard
{
    void __thiscall FUN_0043d5b0();
    void* __thiscall FUN_0043d580(unsigned int flags);
};

// Calls FUN_0043d5b0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0043d580
void* __thiscall QueuedTreeBillboard::FUN_0043d580(unsigned int flags)
{
    FUN_0043d5b0();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_0043d580

struct QueuedTreeModel
{
    bool FUN_00c3d0e0(char* apDescription, unsigned int aiBufferSize, const char* apName);
    bool GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043db00
bool QueuedTreeModel::GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize)
{
    return FUN_00c3d0e0(apDescription, aiBufferSize, "tree model");
}

class Flt
{
  public:
    operator unsigned int();
};

class IOTask;

class QueuedReplacementKF
{
  public:
    void FUN_0043e4b0();
    void IncrementCounter();
    bool FUN_00449130();
    void FUN_0043e940();
};

// @fnv 0x0043e940
void QueuedReplacementKF::FUN_0043e940()
{
    FUN_0043e4b0();
    if (((Flt*)((char*)this + 0x30))->operator unsigned int())
    {
        if (!FUN_00449130())
        {
            if (*(QueuedReplacementKF**)((char*)this + 0x3c))
            {
                (*(QueuedReplacementKF**)((char*)this + 0x3c))->IncrementCounter();
            }
            ((IOTask*)this)->AddToPostProcessQueue();
        }
    }
}

namespace fnv_0043ea00 {
struct FUN_00c3d0e0_stub
{
    bool FUN_00c3d0e0(char* apDescription, unsigned int aiBufferSize, const char* apName);
};

struct QueuedReplacementKF
{
    bool FUN_0043ea00(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043ea00
bool __thiscall QueuedReplacementKF::FUN_0043ea00(char* apDescription, unsigned int aiBufferSize)
{
    return ((FUN_00c3d0e0_stub*)this)->FUN_00c3d0e0(apDescription, aiBufferSize, "Replacement KF");
}
}  // namespace fnv_0043ea00

struct FUN_00440640_shell
{
    void FUN_00440640();
    void* FUN_00440610(unsigned int flags);
};

void _Deallocate(void*);

// Calls FUN_00440640, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00440610
void* FUN_00440640_shell::FUN_00440610(unsigned int flags)
{
    FUN_00440640();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00440e30_This
{
    NiNode* FUN_00440e30();
};

extern unsigned char DAT_1187004[];

// @fnv 0x00440e30
NiNode* FUN_00440e30_This::FUN_00440e30()
{
    return *(NiNode**)(DAT_1187004 + (*(unsigned char*)((char*)this + 4)) * 0xc);
}

namespace fnv_00440e80 {
struct FUN_00441980_Class
{
    void FUN_00440eb0(void);
    void* FUN_00440e80(unsigned int flags);
};
void _Deallocate(void* p);
// Calls FUN_00440eb0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00440e80
void* FUN_00441980_Class::FUN_00440e80(unsigned int flags)
{
    FUN_00440eb0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00440e80

namespace fnv_00441950 {
struct FUN_00441980_Class
{
    void FUN_00441980(void);
    void* FUN_00441950(unsigned int flags);
};

void FUN_00441980_Class::FUN_00441980(void)
{}

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00441980, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00441950
void* FUN_00441980_Class::FUN_00441950(unsigned int flags)
{
    FUN_00441980();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00441950

void __cdecl SetFlag20(unsigned char, unsigned char*);

struct FUN_00443ff0Class
{
    void __thiscall FUN_00443ff0(unsigned char arg);
};

// Calls SetFlag20 with arg and the byte pointer at offset 0x3c of this object.
// @fnv 0x00443ff0
void __thiscall FUN_00443ff0Class::FUN_00443ff0(unsigned char aucValue)
{
    SetFlag20(aucValue, (unsigned char*)this + 0x3c);
}

namespace fnv_00446a10 {
struct FaceGenPaletteBase
{
    void FUN_0043dc50(void);
    void* FUN_00446a10(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_0043dc50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00446a10
void* FaceGenPaletteBase::FUN_00446a10(unsigned int flags)
{
    FUN_0043dc50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00446a10

struct FUN_00449920Class
{
    void FUN_00449920();
};

// @fnv 0x00449920
void FUN_00449920Class::FUN_00449920()
{
    ((char*)this)[0x10] = 0;
}

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

extern void _Deallocate(void*);

struct FUN_00449a50_StandIn
{
    void CallBaseMethod();
    void* FUN_00449a50(unsigned int flags);
};

// Calls CallBaseMethod, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449a50
void* FUN_00449a50_StandIn::FUN_00449a50(unsigned int flags)
{
    CallBaseMethod();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00449a80 {
struct FUN_00449d40_class
{
    void FUN_00449d40();
    void* FUN_00449a80(unsigned int flags);
};
void _Deallocate(void*);

// Calls FUN_00449d40, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449a80
void* FUN_00449d40_class::FUN_00449a80(unsigned int flags)
{
    FUN_00449d40();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449a80

namespace fnv_00449ae0 {
extern void* __cdecl _Deallocate(void*);

struct FUN_00449ae0_Class
{
    void* __thiscall DestroyModelLoader(unsigned int flags);
};

// @fnv 0x00449ae0
void* __thiscall FUN_00449ae0_Class::DestroyModelLoader(unsigned int flags)
{
    ((ModelLoader*)this)->FUN_004431d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449ae0

void __fastcall FUN_00449940(void**);

struct FUN_00449b10_Class
{
    void* __thiscall FUN_00449b10(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x00449b10
void* __thiscall FUN_00449b10_Class::FUN_00449b10(unsigned int flags)
{
    FUN_00449940((void**)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00449c50_class
{
    int __thiscall FUN_00449c50();
};

struct FUN_00449c30_class : FUN_00449c50_class
{
    int __thiscall CallBaseMethod();
};

// @fnv 0x00449c30
int __thiscall FUN_00449c30_class::CallBaseMethod()
{
    return FUN_00449c50();
}

namespace fnv_00449f20 {
struct FUN_00449ea0_cls
{
    void FUN_00449ec0();
    void* __thiscall FUN_00449f20(unsigned int flags);
};

extern "C" void* __cdecl _Deallocate(void*);

// @fnv 0x00449f20
void* __thiscall FUN_00449ea0_cls::FUN_00449f20(unsigned int flags)
{
    FUN_00449ea0_cls::FUN_00449ec0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449f20

namespace fnv_0044afa0 {
// @fnv 0x0044afa0
char FUN_0044afa0(unsigned char param_1)
{
    return (param_1 & 0x20) != 0;
}
}  // namespace fnv_0044afa0

namespace fnv_0044b270 {
struct FUN_0044b2a0_Class
{
    void FUN_0044b2a0(void);
};

class FUN_0044b270_Class
{
  public:
    FUN_0044b2a0_Class* m_pData;
    FUN_0044b270_Class* FUN_0044b270(FUN_0044b2a0_Class* a);
};

// Stores the given object in m_pData and, if it is non-null, calls its FUN_0044b2a0 method; returns this.
// @fnv 0x0044b270
FUN_0044b270_Class* FUN_0044b270_Class::FUN_0044b270(FUN_0044b2a0_Class* apData)
{
    m_pData = apData;
    if (m_pData != 0)
    {
        m_pData->FUN_0044b2a0();
    }
    return this;
}
}  // namespace fnv_0044b270

extern int DAT_010172b8;

struct FUN_0044cc10
{
    int* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    char m_iThirdValue;
    FUN_0044cc10();
};

// @fnv 0x0044cc10
FUN_0044cc10::FUN_0044cc10()
{
    m_iWordAt00 = &DAT_010172b8;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

// @fnv 0x0044dec0
int __fastcall ClearLowBit(int* piValue)
{
    return *piValue & 0xfffffffe;
}

struct FUN_0044df00Class
{
    void __thiscall ClearLowBit();
    void __thiscall FUN_0044df00();
};

// @fnv 0x0044df00
void __thiscall FUN_0044df00Class::FUN_0044df00()
{
    ClearLowBit();
}

void __cdecl FUN_0044ae60(unsigned char, void*);
struct FUN_0043c0d0_class
{
    void __thiscall ForwardByteToMember(unsigned char);
};
// Passes a to FUN_0044ae60 together with the pointer at this+0x34.
// @fnv 0x0043c0d0
void __thiscall FUN_0043c0d0_class::ForwardByteToMember(unsigned char aByte)
{
    FUN_0044ae60(aByte, reinterpret_cast<char*>(this) + 0x34);
}

namespace fnv_0043c6b0 {
struct QueuedTreeModel
{
    bool FUN_00c3d0e0(char*, unsigned int, const char*);
    bool FUN_0043c6b0(char* apDescription, unsigned int aiBufferSize);
};
// @fnv 0x0043c6b0
bool QueuedTreeModel::FUN_0043c6b0(char* apDescription, unsigned int aiBufferSize)
{
    return FUN_00c3d0e0(apDescription, aiBufferSize, "texture");
}
}  // namespace fnv_0043c6b0

namespace fnv_0043c960 {
struct SetterHelper
{
    void FUN_0044aed0(void*);
};

struct GO : SetterHelper
{
    GO(int);
    ~GO();
};

struct QBase
{
    virtual ~QBase();
    char pad[0x2c];
    QBase(int);
};

void __fastcall SetFieldCToFive(char*);

struct FUN_0043c960 : QBase
{
    GO m_go;
    int m_field34;
    int m_field38;
    char m_field3c;
    float m_field40;

    FUN_0043c960(void* param1, int param2);
    virtual ~FUN_0043c960();
};

// @fnv 0x0043c960
FUN_0043c960::FUN_0043c960(void* param1, int param2) : QBase(param2), m_go(0), m_field34(0), m_field38(0), m_field3c(0)
{
    m_go.FUN_0044aed0(param1);
    SetFieldCToFive((char*)this);
    m_field40 = 0.0f;
}
}  // namespace fnv_0043c960

namespace fnv_0043d510 {
struct QueuedTreeModel
{
    bool FUN_00c3d0e0(char*, unsigned int, const char*);
    bool FUN_0043d510(char*, unsigned int);
};

// @fnv 0x0043d510
bool QueuedTreeModel::FUN_0043d510(char* apDescription, unsigned int aiBufferSize)
{
    return FUN_00c3d0e0(apDescription, aiBufferSize, "model");
}
}  // namespace fnv_0043d510

namespace fnv_0043e550 {
struct QueuedTreeModel
{
    bool FUN_00c3d0e0(char*, unsigned int, const char*);
    bool FUN_0043e550(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043e550
bool QueuedTreeModel::FUN_0043e550(char* apDescription, unsigned int aiBufferSize)
{
    return FUN_00c3d0e0(apDescription, aiBufferSize, "KF");
}
}  // namespace fnv_0043e550

namespace fnv_0043e880 {
struct QueuedTreeModel
{
    bool FUN_00c3d0e0(char*, unsigned int, const char*);
};

struct FUN_0043e880_Class
{
    bool FUN_0043e880(char* apDescription, unsigned int aiBufferSize);
};

// Forwards the description and buffer size to FUN_00c3d0e0 with the "AnimIdle" tag and returns its result.
// @fnv 0x0043e880
bool FUN_0043e880_Class::FUN_0043e880(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<QueuedTreeModel*>(this)->FUN_00c3d0e0(apDescription, aiBufferSize, "AnimIdle");
}
}  // namespace fnv_0043e880

struct FUN_0043e920_class
{
    void FUN_0043e1b0();
    void FUN_0043e920();
};

// @fnv 0x0043e920
void FUN_0043e920_class::FUN_0043e920()
{
    FUN_0043e1b0();
}

struct FUN_0043e990_Class
{
    void IncrementCounter();
};

// @fnv 0x0043e990
void FUN_0043e990_Class::IncrementCounter()
{
    *(int*)((char*)this + 0x2c) = *(int*)((char*)this + 0x2c) + 1;
}

namespace fnv_0043fc10 {
struct QueuedHelmet
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    bool FormatQueuedHelmetDescription(char* apDescription, unsigned int aiBufferSize);
};

extern "C" int __cdecl _sprintf_s(char* apDest, unsigned int aiSize, const char* apFormat, ...);

// Writes a formatted "Queued helmet for biped anim %08X" string using m_28 into apDescription and returns true.
// @fnv 0x0043fc10
bool QueuedHelmet::FormatQueuedHelmetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Queued helmet for biped anim %08X", m_28);
    return true;
}
}  // namespace fnv_0043fc10

namespace fnv_00440e50 {
extern int DAT_01016c5c;
struct S4411
{
    void FUN_0043fd40(int a, int b);
    void* InitWithGlobal(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, stores the address of DAT_01016c5c at the start of this, and returns this.
// @fnv 0x00440e50
void* S4411::InitWithGlobal(int aiArg1, int aiArg2)
{
    FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016c5c;
    return this;
}
}  // namespace fnv_00440e50

struct FUN_00440eb0_class
{
    void FUN_0043fe40();
    void FUN_00440eb0();
};

// @fnv 0x00440eb0
void FUN_00440eb0_class::FUN_00440eb0()
{
    FUN_0043fe40();
}

namespace fnv_00441920 {
extern int DAT_01016d34;
struct FUN_004411d0
{
    int* m_vft;
    int m_kPointA;
    int m_kPointB;
    FUN_004411d0(int a, int b);
};
struct FUN_00441920 : FUN_004411d0
{
    FUN_00441920(int a, int b);
};
// Constructs the object by forwarding a and b to the base constructor and setting m_vft to DAT_01016d34.
// @fnv 0x00441920
FUN_00441920::FUN_00441920(int a, int b) : FUN_004411d0(a, b)
{
    m_vft = &DAT_01016d34;
}
}  // namespace fnv_00441920

namespace fnv_00441c50 {
struct BSFile;
struct BSFileEntry;
struct LoadedFile;
struct QueuedFileEntry : public QueuedFile
{
    virtual void __vslot_0();
    virtual unsigned char GetFileIndex();
    virtual void GenerateKey();
    char* GetFileName();
    void SetFileName(char*);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry*);
    void LookupFileEntry(int);
    BSFile* GetFile(int, int);
    void GetLookupFileName(int, char*);
    bool GetDescription(char*, unsigned int, char*);
    char _pad_4[36];
    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
typedef char _sizecheck_QueuedFileEntry[sizeof(QueuedFileEntry) == 48 ? 1 : -1];
struct QueuedFileLoad : public QueuedFileEntry
{
    virtual void __vslot_0();
    virtual void DispatchToManager();
    virtual void Run();
    virtual void Finish();
    LoadedFile* GetLoadedFile();
    virtual unsigned char GetFileIndex();
    char m_pLoadedFile[4];
    int m_iLoadPriority;
};
typedef char _sizecheck_QueuedFileLoad[sizeof(QueuedFileLoad) == 56 ? 1 : -1];

int __cdecl FUN_00449050(int);
extern int DAT_01016dc4;
struct QBase
{
    char pad[48];
    QBase(int);
    ~QBase();
};
struct FUN_0063fa10
{
    void FUN_00c3cee0(char const*);
    void LookupFileEntryByArchive(int);
};
template <> class NiPointer<LoadedFile>
{
  public:
    NiPointer(LoadedFile*);
    ~NiPointer();
    void* p;
};
struct FUN_00441c50 : QBase
{
    NiPointer<LoadedFile> sp;
    int m_iLoadPriority;
    FUN_00441c50(char const*, int, int);
};
// @fnv 0x00441c50
FUN_00441c50::FUN_00441c50(char const* a, int b, int c)
    : QBase(b), sp(((*(void**)this = (void*)&DAT_01016dc4), (LoadedFile*)0)), m_iLoadPriority(c)
{
    ((FUN_0063fa10*)this)->FUN_00c3cee0(a);
    ((FUN_0063fa10*)this)->LookupFileEntryByArchive(FUN_00449050(m_iLoadPriority));
}
}  // namespace fnv_00441c50

namespace fnv_00442130 {
struct FUN_00441d80
{
    FUN_00441d80(int, int);
    ~FUN_00441d80();
    virtual void vfunc();
    char pad[0x34];
};

struct GO
{
    int pad;
    GO(int);
    ~GO();
    GO& operator=(void*);
};

struct FUN_0044b270
{
    FUN_0044b270(int);
    ~FUN_0044b270();
    void FUN_0044b300(void*);
};

struct FUN_00442130 : FUN_00441d80
{
    GO m_model;
    FUN_0044b270 m_meshData;

    FUN_00442130(void* apModel, void* apMeshData);
    virtual ~FUN_00442130();
};

// Constructs the object with base parameters 0 and 5, assigns apModel to m_model and passes apMeshData to m_meshData.FUN_0044b300.
// @fnv 0x00442130
FUN_00442130::FUN_00442130(void* apModel, void* apMeshData) : FUN_00441d80(0, 5), m_model(0), m_meshData(0)
{
    m_model = apModel;
    m_meshData.FUN_0044b300(apMeshData);
}
}  // namespace fnv_00442130

struct FUN_00444d00_Class
{
    bool __thiscall FUN_00444d00(int mask);
};

// @fnv 0x00444d00
bool __thiscall FUN_00444d00_Class::FUN_00444d00(int mask)
{
    return (*(int*)((char*)this + 0xC8) & mask) ? true : false;
}

namespace fnv_00446f70 {
struct FUN_00442510_Cl
{
    void FUN_00442510();
};

struct FUN_00446f70_Cl : ModelLoader
{
    void FUN_00446f70();
};

// @fnv 0x00446f70
void FUN_00446f70_Cl::FUN_00446f70()
{
    ProcessQueuedFile();
    ((FUN_00442510_Cl*)this)->FUN_00442510();
}
}  // namespace fnv_00446f70

void __fastcall SignalAtOffset18(char*);

struct FUN_00446ff0 : ModelLoader
{
    void FUN_00446ff0_();
};

// @fnv 0x00446ff0
void FUN_00446ff0::FUN_00446ff0_()
{
    ProcessQueuedFile();
    SignalAtOffset18(reinterpret_cast<char*>(this));
}

struct FUN_00448a20_class
{
    int a;
    int b;
    int c;
    bool FUN_00448a20() const;
};
// @fnv 0x00448a20
bool FUN_00448a20_class::FUN_00448a20() const
{
    return (c & 0x80) ? true : false;
}

namespace fnv_00449030 {
struct FUN_00442630Class
{
    void FUN_00442630(void);
};

struct FUN_00449030Class
{
    char pad[0x28];
    FUN_00442630Class* m_p;
    void CallMemberFunction(void);
};

// @fnv 0x00449030
void FUN_00449030Class::CallMemberFunction(void)
{
    m_p->FUN_00442630();
}
}  // namespace fnv_00449030

namespace fnv_004490e0 {
extern int DAT_01017138;
extern int DAT_011c3b38;
int __cdecl FinishScriptRunLock(void*);

struct FUN_004490e0_Class
{
    void* m_p;
    void FUN_004490e0();
};

// Points m_p at DAT_01017138 and calls FinishScriptRunLock on DAT_011c3b38.
// @fnv 0x004490e0
void FUN_004490e0_Class::FUN_004490e0()
{
    m_p = &DAT_01017138;
    FinishScriptRunLock(&DAT_011c3b38);
}
}  // namespace fnv_004490e0

struct FUN_0044ee20_class
{
    int GetElementAddress(int index);
};

// @fnv 0x0044ee20
int FUN_0044ee20_class::GetElementAddress(int index)
{
    return *(int*)((char*)this + 0xc) + index * 4;
}

struct FUN_00905330
{
    void __thiscall Remove(void*);
};
struct FUN_0044f870
{
    void __thiscall FUN_0044f870_0044f870(void* ap);
};
// @fnv 0x0044f870
void __thiscall FUN_0044f870::FUN_0044f870_0044f870(void* ap)
{
    ((FUN_00905330*)((char*)this + 0x10c))->Remove(&ap);
}

struct FUN_006ecba0_class
{
    void* m_p;
    void FUN_0044e010(bool);
    void* FUN_006ecba0(bool b, void* p);
};

// Stores p in m_p, calls FUN_0044e010 with b, and returns this.
// @fnv 0x006ecba0
void* FUN_006ecba0_class::FUN_006ecba0(bool abFlag, void* apValue)
{
    m_p = apValue;
    FUN_0044e010(abFlag);
    return this;
}

namespace fnv_0043b640 {
struct GO
{
    GO(int);
    ~GO();
    void operator=(void*);
    void* m_pObject;
};
struct Flt
{
    operator unsigned int();
};
unsigned int __cdecl _BSStringLength(const char*);
void __cdecl _FNV_Warning(const char*, ...);
void __cdecl AssignNewObjectFromValue(void*, int, GO*);

struct FUN_0043b640
{
    char* pFilename;
    GO pListSequence;
    GO m_spAnimGroup;
    int BackgroundTask;
    int m_iActualRefCount;
    FUN_0043b640(const char* apFilename, void* apStream);
    void FUN_0043b7e0(const char*);
};

// @fnv 0x0043b640
FUN_0043b640::FUN_0043b640(const char* apFilename, void* apStream)
    : pListSequence(0), m_spAnimGroup(0), BackgroundTask(0), m_iActualRefCount(0)
{
    m_spAnimGroup = 0;
    unsigned int uiLength = _BSStringLength(apFilename);
    pFilename = new char[uiLength + 1];
    TaskQueueInterface::CopyStringToBuffer(pFilename, uiLength + 1, apFilename);
    AssignNewObjectFromValue(apStream, 0, &pListSequence);
    if (*(Flt*)&pListSequence)
    {
        FUN_0043b7e0(apFilename);
    }
    else
    {
        _FNV_Warning("ANIMATION: Could not create ControllerManager Sequence for \"%s\".\r\n", pFilename);
    }
}
}  // namespace fnv_0043b640

namespace fnv_0043cb50 {
struct BGSTextureSet;
struct FileFormCollection;
struct TESFile;
struct FileEntryList
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Copy(FileEntryList*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};
typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct DistantTreeTextureInfo
{
    BGSTextureSet* m_pTextureSet;
    int m_iTextureSetIndex;
    char m_cTexturePath[128];
};
typedef char _sizecheck_TEX_SWAP[sizeof(DistantTreeTextureInfo) == 136 ? 1 : -1];
struct FUN_0043cb50_shell : public QueuedModel
{
    void QueueTextureFiles(FileEntryList*);
};

struct FUN_00978890_m
{
    unsigned char GetKey();
    BSFileEntry** _ref_00726070();
};
struct Loader_S
{
    void QueueTextureFile(BSFileEntry*, int, QueuedFile*);
};
struct BGSTextureSet
{
    void LoadTextures(int, QueuedFile*, bool);
};
struct SwapNode_0043cb50
{
    DistantTreeTextureInfo** _ref_006815c0();
    SwapNode_0043cb50* _ref_00726070();
};
struct ScriptS
{
    SwapNode_0043cb50* GetHeader();
};
struct ModelV_0043cb50
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual ScriptS* GetTextureSwap();
};
struct FUN_0043ccc0_shell
{
    void FUN_0043ccc0(bool);
};

// @fnv 0x0043cb50
void FUN_0043cb50_shell::QueueTextureFiles(FileEntryList* apTextureList)
{
    if (apTextureList)
    {
        unsigned int itextureCount = ((FUN_00978890_m*)apTextureList)->GetKey();
        if (itextureCount)
        {
            BSFileEntry** papFileEntries = ((FUN_00978890_m*)apTextureList)->_ref_00726070();
            for (unsigned int i = 0; i < itextureCount; i++)
            {
                if (papFileEntries[i])
                    ((Loader_S*)g_modelLoader)->QueueTextureFile(papFileEntries[i], FUN_0043cc60(), this);
            }
        }
    }
    if (*(ModelV_0043cb50**)((char*)this + 0x34))
    {
        ScriptS* ptextureSwap = (*(ModelV_0043cb50**)((char*)this + 0x34))->GetTextureSwap();
        if (ptextureSwap)
        {
            SwapNode_0043cb50* pSwapNode = ptextureSwap->GetHeader();
            while (pSwapNode)
            {
                DistantTreeTextureInfo* pswap = *pSwapNode->_ref_006815c0();
                if (pswap && pswap->m_pTextureSet)
                    pswap->m_pTextureSet->LoadTextures(FUN_0043cc60(), this, false);
                pSwapNode = pSwapNode->_ref_00726070();
            }
        }
    }
    ((FUN_0043ccc0_shell*)this)->FUN_0043ccc0(true);
    vfn_28();
}
}  // namespace fnv_0043cb50

namespace fnv_0043e2a0 {
struct BSFile;
struct NiBinaryStream;
struct NiFile;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiObjectNET;
struct NiPoint2;
struct NiPoint3;
struct NiSearchPath;
struct NiTexture;
struct NiThread;
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
struct FUN_0043e2a0_shell : public QueuedKF
{
    void FUN_0043e2a0();
};

struct AutoMemHelper
{
    int iSaved;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct Proc_S
{
    void* GetNext();
};
struct Flt
{
    operator unsigned int();
};
struct KFModelLookup
{
    KFModel* Lookup(const char*);
};
struct FUN_0043e480_shell
{
    void FUN_0043e480(bool);
};
struct FUN_00c3cff0_t
{
    BSFile* FUN_00c3cff0(int, int);
};
struct BSStream
{
    BSStream();
    virtual ~BSStream();
    unsigned int data[0x171];
    char name[8];
};
struct NiStream
{
    bool FUN_00c3a8a0(const char*, BSFile*);
};
struct FUN_0043b640
{
    char data[0x14];
    FUN_0043b640(void*, BSStream*);
};
void _FNV_Warning(const char*, ...);

// Looks up a KFModel by name; if not found, opens the file and loads it into a new KFModel, warning on failure.
// @fnv 0x0043e2a0
void FUN_0043e2a0_shell::FUN_0043e2a0()
{
    AutoMemHelper tempMemContext(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                                 0x529);
    *(NiPointer<KFModel>*)((char*)this + 0x30) =
        ((KFModelLookup*)g_modelLoader)->Lookup((const char*)((Proc_S*)this)->GetNext());
    if (*(Flt*)((char*)this + 0x30))
    {
        ((FUN_0043e480_shell*)this)->FUN_0043e480(true);
        return;
    }
    BSFile* pfile = ((FUN_00c3cff0_t*)this)->FUN_00c3cff0(0, 1);
    BSStream kstream;
    if (pfile && ((NiStream*)&kstream)->FUN_00c3a8a0((const char*)((Proc_S*)this)->GetNext(), pfile))
        *(NiPointer<KFModel>*)((char*)this + 0x30) = (KFModel*)new FUN_0043b640(((Proc_S*)this)->GetNext(), &kstream);
    else
        _FNV_Warning("MODEL ERROR: Could not %s file '%s'.", pfile ? "load" : "find", ((Proc_S*)this)->GetNext());
}
}  // namespace fnv_0043e2a0

struct Inner5
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Holder14
{
    char _pad[0x14];
    Inner5* p;
    void ForwardToInner(int);
};
// Calls f5 on the Inner5 object stored in p, passing a through.
// @fnv 0x0043ea90
void Holder14::ForwardToInner(int aiValue)
{
    p->f5(aiValue);
}

struct VirtObj0043fb50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Standin0043fb50
{
    char _pad[0x18];
    VirtObj0043fb50* m_18;
    void DispatchToVirtual(int);
};
// Forwards the integer argument to the virtual method f5 of the object stored at m_18.
// @fnv 0x0043fb50
void Standin0043fb50::DispatchToVirtual(int aiValue)
{
    m_18->f5(aiValue);
}

namespace fnv_0043fed0 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct ReferenceIntersectionData
{
    void Endian();
    TESObjectREFR* m_pHitReference;
    char Intersect[12];
    char Normal[12];
};
typedef char _sizecheck_REF_DECAL_DATA[sizeof(ReferenceIntersectionData) == 28 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_0043fed0_shell : public QueuedReference
{
    void FUN_0043fed0();
};

struct RefV
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual int v116();
    bool FUN_00564e60();
    void* FUN_005d43c0();
};
struct QRV
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
};
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct DecalList
{
    bool FUN_008256d0();
    ReferenceIntersectionData** FUN_006815c0();
    DecalList* FUN_00726070();
};
struct FUN_0041f050_shell
{
    DecalList* FUN_0041f050();
};
struct FUN_00475120_shell
{
    int GetFormType();
};
struct ScriptS
{
    FUN_00475120_shell* GetNext();
};
struct BGSTextureSet
{
    void LoadTextures(int, void*, bool);
};
struct FUN_0043cc80_shell
{
    unsigned char FUN_0043cc80();
};
struct Dummy_0069b080;
bool __fastcall IsFieldCZero(Dummy_0069b080*);
void __fastcall SetFieldCToFive(char*);

// @fnv 0x0043fed0
void FUN_0043fed0_shell::FUN_0043fed0()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x72a);
    DecalList* pdecallist;
    if ((*(RefV**)((char*)this + 0x28)) && (*(RefV**)((char*)this + 0x28))->FUN_00564e60() &&
        !(*(RefV**)((char*)this + 0x28))->v116())
        ((QRV*)this)->v12();
    if ((*(RefV**)((char*)this + 0x28)))
    {
        pdecallist = ((FUN_0041f050_shell*)(*(RefV**)((char*)this + 0x28))->FUN_005d43c0())->FUN_0041f050();
        while (pdecallist && !pdecallist->FUN_008256d0())
        {
            ReferenceIntersectionData* pdata = *pdecallist->FUN_006815c0();
            pdecallist = pdecallist->FUN_00726070();
            if (pdata->m_pHitReference && ((ScriptS*)pdata->m_pHitReference)->GetNext()->GetFormType() == 4)
            {
                BGSTextureSet* ptexset = (BGSTextureSet*)((ScriptS*)pdata->m_pHitReference)->GetNext();
                ptexset->LoadTextures(((FUN_0043cc80_shell*)this)->FUN_0043cc80(), this, false);
            }
        }
    }
    ((QRV*)this)->v11();
    if (IsFieldCZero((Dummy_0069b080*)this))
        SetFieldCToFive((char*)this);
    ((QRV*)this)->v10();
}
}  // namespace fnv_0043fed0

namespace fnv_00440050 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00440050_shell : public QueuedReference
{
    void FUN_00440050();
};

class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
    int iOld;
};

struct Flt
{
    operator unsigned int();
};

struct TESModelV
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual char* GetModelFileName();
};

struct FUN_00571630_shell
{
    TESModelV* FUN_00571630();
};
struct FUN_007af430_shell
{
    void* FUN_007af430();
};
struct FUN_00444dc0_shell
{
    void QueueModelForObject(void*, void*, int, void*, void*);
};
struct FUN_004472a0_shell
{
    bool FUN_004472a0(char*, void*);
};
struct FUN_00477640_shell
{
    void FUN_00477640(void*, int, void*);
};
FUN_00477640_shell* FUN_00475400(void*);

// Loads the model via g_modelLoader, resolves the model file name, and runs the destructor task if present.
// @fnv 0x00440050
void FUN_00440050_shell::FUN_00440050()
{
    TESModelV* ptesModel;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x752);
    void* pobj = ((FUN_007af430_shell*)*(void**)((char*)this + 0x28))->FUN_007af430();
    ptesModel = ((FUN_00571630_shell*)*(void**)((char*)this + 0x28))->FUN_00571630();
    if (!ptesModel || !*ptesModel->GetModelFileName())
        return;
    ((FUN_00444dc0_shell*)g_modelLoader)
        ->QueueModelForObject(pobj, (char*)this + 0x2c, ((IOTask*)this)->FUN_0043cc60(), this,
                              *(void**)((char*)this + 0x28));
    if (!*(Flt*)((char*)this + 0x2c))
        ((FUN_004472a0_shell*)g_modelLoader)->FUN_004472a0(ptesModel->GetModelFileName(), (char*)this + 0x30);
    FUN_00477640_shell* pdestruct = FUN_00475400(pobj);
    if (pdestruct)
        pdestruct->FUN_00477640(pobj, ((IOTask*)this)->FUN_0043cc60(), this);
}
}  // namespace fnv_00440050

struct IOManagerHack
{
    void __thiscall FUN_00c3df40(void* a1, int a2);
};
struct IOTaskHack
{
    void FUN_00440660(int a1);
};
// Forwards this task and a1 to the IOManager at DAT_01202d98 via FUN_00c3df40.
// @fnv 0x00440660
void IOTaskHack::FUN_00440660(int a1)
{
    ((IOManagerHack*)DAT_01202d98)->FUN_00c3df40(this, a1);
}

namespace fnv_00440780 {
struct FUN_00440780_shell : public QueuedReference
{
    void FUN_00440780();
};

struct TESObjectCELL;
struct TES
{
    bool IsCellBuffered(TESObjectCELL*, bool);
    bool IsRefUsable(TESObjectREFR*);
};
extern TES* g_TES;
extern TESObjectREFR* g_thePlayer;
struct Flt
{
    operator unsigned int();
};
struct CtlV
{
    CtlV* GetNext() const;
};
struct SetterHelper
{
    void FUN_0044aed0(void*);
};
struct ActorS
{
    TESObjectCELL* GetParentCell();
};
struct NiAVObject;
struct RefA
{
    NiAVObject* GetReferenceType();
};
struct FUN_004408d0_S
{
    void ForwardToBCT(void*);
};
bool __fastcall FUN_00449110(int*);
bool __fastcall FUN_00449130(int*);
struct VRef_00440780
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual bool v136();
    virtual bool v137();
};
// @fnv 0x00440780
void FUN_00440780_shell::FUN_00440780()
{
    if (FUN_00449110((int*)this) && ((IOTask*)this)->FUN_0043caa0() && !FUN_00449130((int*)this))
    {
        if (*(Flt*)((char*)this + 0x2c) && !*(Flt*)((char*)this + 0x30))
            ((SetterHelper*)((char*)this + 0x30))
                ->FUN_0044aed0(((CtlV*)(unsigned int)*(Flt*)((char*)this + 0x2c))->GetNext());
        bool bbackgroundClone = false;
        if (*(Flt*)((char*)this + 0x30) && *(TESObjectREFR**)((char*)this + 0x28) != g_thePlayer &&
            g_TES->IsCellBuffered(((ActorS*)*(TESObjectREFR**)((char*)this + 0x28))->GetParentCell(), false) &&
            g_TES->IsRefUsable(*(TESObjectREFR**)((char*)this + 0x28)) &&
            !((RefA*)*(TESObjectREFR**)((char*)this + 0x28))->GetReferenceType())
            bbackgroundClone = true;
        if ((*(VRef_00440780**)((char*)this + 0x28))->v137() || (*(VRef_00440780**)((char*)this + 0x28))->v136())
            bbackgroundClone = false;
        if (bbackgroundClone)
            ((FUN_004408d0_S*)g_modelLoader)->ForwardToBCT(this);
        else
            ((IOTask*)this)->AddToPostProcessQueue();
    }
}
}  // namespace fnv_00440780

namespace fnv_00440a90 {
struct FUN_00440a90_shell : public QueuedReference
{
    bool FUN_00440a90();
};

class TESObjectCELL;
class NiAVObject;
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct TES
{
    bool IsCellBuffered(TESObjectCELL*, bool);
    bool IsRefUsable(TESObjectREFR*);
};
extern TES* g_TES;
struct ActorS
{
    TESObjectCELL* GetParentCell();
};
struct RefA
{
    NiAVObject* GetReferenceType();
};
struct SeqObj
{
    void FUN_00401970();
};
struct Flt
{
    operator unsigned int();
};
struct GO
{
    void* p;
    void operator=(void*);
};
struct VRef
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void* Get3DObject(bool);
};
struct QRView
{
    char pad[0x18];
    int iMemCtx;
    char pad2[0xc];
    TESObjectREFR* pRef;
    char pad3[8];
    GO spClone;
};
// @fnv 0x00440a90
bool FUN_00440a90_shell::FUN_00440a90()
{
    bool bresult = false;
    AutoMemHelper tempMemContext(((QRView*)this)->iMemCtx, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x7ea);
    if (g_TES->IsCellBuffered(((ActorS*)((QRView*)this)->pRef)->GetParentCell(), false))
    {
        if (g_TES->IsRefUsable(((QRView*)this)->pRef))
        {
            if (!((RefA*)((QRView*)this)->pRef)->GetReferenceType())
            {
                ((QRView*)this)->spClone = ((VRef*)((QRView*)this)->pRef)->Get3DObject(true);
                if (*(Flt*)&((QRView*)this)->spClone)
                    ((SeqObj*)(unsigned int)*(Flt*)&((QRView*)this)->spClone)->FUN_00401970();
            }
        }
        bresult = true;
    }
    return bresult;
}
}  // namespace fnv_00440a90

namespace fnv_00440ba0 {
struct FUN_00440ba0_shell : public QueuedReference
{
    void FUN_00440ba0();
};

struct AutoMemHelper
{
    int m;
    AutoMemHelper(int id, bool b, const char* file, int line);
    ~AutoMemHelper();
};
struct RefH
{
    bool IsDeleted() const;
    bool GetDisabled();
};
struct TESObjectCELL
{
    void CellRefLockEnter();
    void CellRefLockLeave();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct TES
{
    bool IsCellBuffered(TESObjectCELL* cell, bool b);
    void FUN_00451ef0(TESObjectREFR* ref, TESObjectCELL* cell, void* q, bool b);
};
extern TES* g_TES;
struct Flt
{
    operator unsigned int();
};
class BSFaceGenModel;
class BSFaceGenModelExtraData
{
  public:
    BSFaceGenModel* GetModelFilePath();
};
struct FUN_004409e0_shell
{
    void FUN_004409e0(TESObjectREFR* ref);
};
struct FUN_00572350_shell
{
    bool FUN_00572350();
};
void __fastcall FinishScriptRunLockAndReset(char* p);
void __fastcall FinishScriptRun(char* p);
bool __fastcall FUN_00449130(int* p);

// Processes a queued reference: skips deleted/disabled refs, updates the model loader and cell reference lock, then releases the cell lock.
// @fnv 0x00440ba0
void FUN_00440ba0_shell::FUN_00440ba0()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x804);
    if (FUN_00449130((int*)this))
        return;
    bool bdisabled = false;
    bdisabled = ((RefH*)*(TESObjectREFR**)((char*)this + 0x28))->GetDisabled() ||
                ((RefH*)*(TESObjectREFR**)((char*)this + 0x28))->IsDeleted();
    if (((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
        ((TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
            ->CellRefLockEnter();
    if (!bdisabled &&
        g_TES->IsCellBuffered(
            (TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult(), false))
    {
        if ((unsigned int)*(Flt*)((char*)this + 0x30))
            g_modelLoader->UpdateReferenceNode(
                *(TESObjectREFR**)((char*)this + 0x28),
                (NiNode*)((BSFaceGenModelExtraData*)(unsigned int)*(Flt*)((char*)this + 0x30))->GetModelFilePath());
        g_TES->FUN_00451ef0(
            *(TESObjectREFR**)((char*)this + 0x28),
            (TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult(), this, false);
    }
    ((FUN_004409e0_shell*)g_modelLoader)->FUN_004409e0(*(TESObjectREFR**)((char*)this + 0x28));
    if (((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
    {
        FinishScriptRunLockAndReset(
            (char*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult());
        if (((FUN_00572350_shell*)*(TESObjectREFR**)((char*)this + 0x28))->FUN_00572350())
            FinishScriptRun((char*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult());
        ((TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
            ->CellRefLockLeave();
    }
}
}  // namespace fnv_00440ba0

namespace fnv_004412e0 {
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct FUN_006a7ad0_shell
{
    unsigned int& FUN_006a7ad0(int);
};
struct DismembermentPart
{
    int unk0;
    BSSimpleArray<unsigned int, 1024> parts;
};
struct ExtraDismemberedLimbs
{
    char pad[0x20];
    BSSimpleArray<unsigned int, 1024> limbs;
    DismembermentPart* GetInfoAt(unsigned int);
};
struct ExtraDataList
{
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
struct Actor
{
    void AddDefaultSpells();
};
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR*);
struct QueuedActor;
struct FUN_00444d40_shell
{
    void FUN_00444d40(unsigned int, IO_TASK_PRIORITY, QueuedActor*, Actor*);
};
struct QueuedActor
{
    void FUN_00440050();
    void QueueDismemberedLimbLoads();
};

// Queues model-loader tasks for each dismembered limb part of the actor's extra data, then calls FUN_00440050.
// @fnv 0x004412e0
void QueuedActor::QueueDismemberedLimbLoads()
{
    ExtraDismemberedLimbs* pextraLimbs;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8a2);
    Actor* pactor = *(Actor**)((char*)this + 0x28);
    pactor->AddDefaultSpells();
    pextraLimbs = FUN_005d43c0((TESObjectREFR*)pactor)->GetDismemberedLimbs();
    if (pextraLimbs)
    {
        IO_TASK_PRIORITY epriority = ((IOTask*)this)->FUN_0043cc60();
        for (unsigned int i = 0; i < ((TESObjectREFR_GetFlags_Helper*)&pextraLimbs->limbs)->CallGetFlags(); i++)
        {
            DismembermentPart* pdismemberedLimb = pextraLimbs->GetInfoAt(i);
            for (unsigned int j = 0; j < ((TESObjectREFR_GetFlags_Helper*)&pdismemberedLimb->parts)->CallGetFlags();
                 j++)
            {
                unsigned int uiBoundObject = ((FUN_006a7ad0_shell*)&pdismemberedLimb->parts)->FUN_006a7ad0(j);
                ((FUN_00444d40_shell*)g_modelLoader)
                    ->FUN_00444d40(uiBoundObject, epriority, this, *(Actor**)((char*)this + 0x28));
            }
        }
    }
    FUN_00440050();
}
}  // namespace fnv_004412e0

namespace fnv_00441560 {
struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnimObject;
struct BSFaceGenModel;
struct BSShaderPPLightingProperty;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct InventoryChanges;
struct MagicItemForm;
struct PackageList;
struct TESActorBase;
struct TESAmmo;
struct TESFaction;
struct TESFile;
struct TESLevItem;
struct TESNPC;
struct TESObjectLIGH;
struct TESRace;
struct BipedAnim
{
    void InitRoot(NiNode*);
    NiNode* GetRoot();
    void RemoveClothingAndArmor();
    void CompleteModelLoadTask();
    static void SetNodeTranslation(NiAVObject*);
    void RemovePart(TESForm*);
    void RemovePart(int, bool, int);
    void RemovePart(BipedAnimObject*, bool, int);
    void RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(NiAVObject*);
    NiNode* GetBoneNode(int);
    TESForm* GetParent(int);
    TESForm* FindPart(NiAVObject*);
    bool FindObject(TESForm*);
    BipedAnimObject* FindBipObject(TESForm*);
    BipedAnimObject* GetBipObject(int);
    void UpdateRaceSex(TESRace*, int);
    void SetBipedObject(TESForm*, TESModel*, int);
    void SetBipedVisibility(bool);
    void ProcessQueuedHelmet(int, void*, QueuedFile*);
    void QueueBipedObjectLoads(unsigned int, int, QueuedFile*);
    void LoadBipedObject(TESNPC*, int, int, QueuedFile*);
    BipedAnimObject* QBufferedObjects();
    void AddBipedWeapon(TESObjectWEAP*, unsigned char);
    void UpdateBipedWeapon(TESObjectWEAP*, unsigned char);
    void RemoveBipedWeapon();
    TESObjectWEAP* GetBipedWeapon();
    void AddWeaponOffset(float);
    static void RecursiveWeaponOffset(NiNode*, float);
    void SetBipedAmmo(TESAmmo*);
    void AttachBipedAmmo(TESAmmo*);
    void RemoveBipedAmmo();
    void AttachBipedShield(TESObjectARMO*);
    void RemoveBipedShield();
    void AttachBipedRing(TESObjectCLOT*, bool);
    void RemoveBipedRing(bool);
    void AttachBipedAmulet(TESObjectCLOT*);
    void RemoveBipedAmulet();
    void SetBipedTorch(TESObjectLIGH*);
    void AttachBipedTorch(TESObjectLIGH*);
    void RemoveBipedTorch();
    TESObjectLIGH* GetBipedTorch();
    NiNode* GetBipedTorchClone();
    BSFaceGenModel* GetFaceGenModelForSlot(int);
    void CanLoadHiddenBipedObjects(int, QueuedFile*, void*, int);
    void CanLoadHiddenBipedObjects(int, QueuedFile*, int);
    NiNode* GetFaceGenNode(BSFaceGenModel*, NiNode*, int);
    void SetFaceGenNode(BSFaceGenModel*, NiNode*, int);
    static void AttachObjectToNode(NiNode*, NiAVObject*, NiNode*, bool);
    static void AttachFaceGenNode(NiNode*, NiNode*, NiNode*, BipedAnim*, int, BSFaceGenModel*);
    static NiAVObject* LoadFormModel(TESForm*, TESModel*, int, TESObjectREFR*, NiAVObject*);
    static void ApplyReferenceExtraData(NiNode*, NiNode*, int, TESObjectREFR*);
    TESObjectREFR* GetRequester();
    bool IsSlotHidden(int);
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject*);
    static int GetBipedObjectFromShaderProperty(NiAVObject*, BSShaderPPLightingProperty*);
    static unsigned int GetSkinModelFlags(NiAVObject*);
    NiAVObject* PrepareBipedModel(NiNode*, int, bool, bool, BSFaceGenModel*);
    NiAVObject* AttachBipedModel(NiNode*, NiNode*, int, bool, bool, BSFaceGenModel*);
    void UpdateSkinInstance(NiAVObject*, bool);
    bool GetSlotHidden(int);
    bool IsModelPathMatch(TESModel*, char*);
    TESModel* Store1stPersonModel(int, char*);
    TESModel* GetModelForSlot(int, TESModel*);
    void* __vecDelDtor(unsigned int);
    NiNode* root;
    char bone[40];
    char object[320];
    char m_kPreviousObjects[320];
    float m_fFadeAlpha;
    TESObjectREFR* m_pActor;
};
typedef char _sizecheck_BipedAnim[sizeof(BipedAnim) == 692 ? 1 : -1];
struct TESActorBaseData : public BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    void SetTemplateUseFlag(int, bool);
    bool GetTemplateUseFlag(int);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm*);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short);
    bool GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void SetTemplateReference(TESObjectREFR*);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    int* GetFlags();
    void SetFlags(int);
    bool GetFlagBit(int);
    void UpdateFlagBit(int, bool, bool);
    bool IsEssentialActor();
    void SetEssential(bool);
    bool GetRespawn();
    void SetRespawn(bool);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool, bool);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool);
    bool GetNotPushable();
    void SetNotPushable(bool);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    bool GetSummonable();
    void SetSummonable(bool);
    bool GetNoRumors();
    void SetNoRumors(bool);
    void SetNoVATSMelee(bool);
    void SetAllowPCDialogue(bool);
    void SetAllowPickPocket(bool);
    void SetIsGhost(bool);
    void SetInvulnerable(bool);
    void SetCantOpenDoors(bool);
    void SetCanBeAllRaces(bool);
    void SetAutoCalcServiceFlags(bool);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem*);
    void SetFatigue(unsigned short);
    static int ConvertToInteger(float);
    static char* GetActorDisplayName(Actor*);
    void SetKarmaValue(float);
    void ModKarma(float);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    void SetSpeedMult(unsigned short);
    void SetVoiceType(BGSVoiceType*);
    void AddFormChange(int);
    void RemoveFormChange(int);
    void AddFormChangeFlags(int);
    void ClearChangeFlags(int);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int);
    bool HasFaction(TESFaction*);
    void RemoveAllFactions();
    void CopyFactionList(TESActorBaseData*);
    void* __vecDelDtor(unsigned int);
    char actorData[24];
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    char m_pVoiceType[8];
};
typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];
struct TESContainer : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges*);
    InventoryItemEntry* AddObject(TESObject*, int, ContainerItemExtra*);
    void AddDuplicateObject(InventoryItemEntry*);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry*);
    void ReplaceObject(TESObject*, TESObject*);
    bool HasObjectOfType(TESObject*);
    float GetContainerWeight(bool);
    int GetObjectCount(TESObject*);
    char Compare(InventoryItemEntry*, InventoryItemEntry*);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char);
    static bool IsValidContainerObject(TESObject*);
    void MergeContainer(TESContainer*);
    void MultiplyContainerCounts(int);
    void SetClothingModifier(float);
    void AddContentsFromReference(TESObjectREFR*, bool);
    void AddInventoryChangesToContainer(int, InventoryChanges*);
    TESAmmo* GetBestAmmoForActor(TESActorBase*);
    TESObjectWEAP* GetBestWeapon(TESActorBase*);
    TESObjectARMO* FindBestArmor(TESActorBase*, int);
    TESObjectCLOT* GetBestClothing(TESActorBase*, int);
    TESBoundObject* GetInventoryEntryData(int);
    void* GetObjectList();
    void* GetObjectListEnd();
    void* __vecDelDtor(unsigned int);
    char objectList[8];
};
typedef char _sizecheck_TESContainer[sizeof(TESContainer) == 12 ? 1 : -1];
struct BGSTouchSpellForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static MagicItemForm* GetFormTouchSpell(TESForm*);
    MagicItemForm* GetFormTouchSpell();
    void SetFormTouchSpell(MagicItemForm*);
    static unsigned short GetFormTouchSpellAnimation(TESForm*);
    unsigned short GetFormTouchSpellAnimation();
    void SetFormTouchSpellAnimation(unsigned short);
    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
    char _pad_a[2];
};
typedef char _sizecheck_BGSTouchSpellForm[sizeof(BGSTouchSpellForm) == 12 ? 1 : -1];
struct TESAIForm : public BaseFormComponent
{
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(TESAIForm*);
    unsigned char GetAggression();
    void SetAggression(unsigned char, bool);
    unsigned char GetAssistance();
    void SetAssistance(unsigned char);
    static float GetConfidenceLevel(unsigned char);
    float GetConfidenceLevel();
    unsigned char GetConfidence();
    void SetConfidence(unsigned char, bool);
    unsigned char GetEnergy();
    void SetEnergy(unsigned char, bool);
    unsigned char GetResponsibility();
    void SetResponsibility(unsigned char, bool);
    unsigned char GetMood();
    void SetAIMood(unsigned char);
    unsigned int GetServiceFlags();
    void SetServiceFlags(unsigned int, bool);
    bool GetOffersService(unsigned int);
    void SetOffersService(unsigned int, bool);
    int GetTrainingSkill();
    void SetTrainingSkill(int);
    unsigned char GetTrainingSkillLevel();
    void SetTrainingSkillLevel(unsigned char);
    void SetAIData(PackedRecordData*);
    bool IsObjectUsable(TESObject*);
    bool HasAnAggroRadius();
    void SetHasAggroRadius(bool);
    unsigned int GetAggroRadius();
    void SetAggroRadius(unsigned int);
    bool HasPackage(TESPackage*);
    void AddPackage(TESPackage*);
    bool MovePackage(TESPackage*, bool);
    void InsertPackageAt(TESPackage*, TESPackage*, bool);
    void DeletePackage(TESPackage*);
    static TESPackage* GetCurrentPackage(Actor*);
    static void FindAvailablePackages(Actor*, void*, float, float);
    void AddFormChange(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    PackageList* GetPackageList();
    void* __vecDelDtor(unsigned int);
    char m_kAIData[20];
    char m_kPackageList[8];
};
typedef char _sizecheck_TESAIForm[sizeof(TESAIForm) == 32 ? 1 : -1];
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
struct TESAnimation : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    bool IsKFFileInList(char*);
    void AddKFFile(char*);
    bool HasSpecialAnimations();
    void* GetKFFileList();
    void Save(int);
    void LoadAnimationChunk(TESAnimation*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void* __vecDelDtor(unsigned int);
    char m_kKFFileList[8];
};
typedef char _sizecheck_TESAnimation[sizeof(TESAnimation) == 12 ? 1 : -1];
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct TESRaceForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESRace* GetFormRace(TESForm*);
    TESRace* GetFormRace();
    static char* GetFormRaceEditorID(TESForm*);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace*);
    TESRace* m_pRace;
};
typedef char _sizecheck_TESRaceForm[sizeof(TESRaceForm) == 8 ? 1 : -1];
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00441560_shell : public QueuedCharacter
{
    void LoadBipedModel();
};

struct AutoMemHelper
{
    int iData;
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};
struct TESNPC
{
    void RebuildHeadModel(TESObjectREFR*, void*, int);
};
struct TESModel;
struct N_008c48d0
{
    void* GetNext();
};
struct FUN_006055f0_shell
{
    BipedAnim* GetOrCreateBipedAnim(TESObjectREFR*);
};
struct FUN_004abd30_shell
{
    void FUN_004abd30(int, void*, void*);
};
struct FUN_00444fe0_shell
{
    void FUN_00444fe0(TESNPC*, void*, int, QueuedFile*);
};
struct FUN_00445a10_shell
{
    void QueueModelAnimations(TESModel*, int, void*, TESObjectREFR*, int, int);
};
struct FUN_004412e0_shell
{
    void QueueDismemberedLimbLoads();
};
struct RefVtbl
{

    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual BipedAnim* GetBipedAnim();
};

// Loads the queued character's biped anim and NPC model via the model loader, then finishes the task.
// @fnv 0x00441560
void FUN_00441560_shell::LoadBipedModel()
{
    BipedAnim* pbipedAnim;
    TESNPC* pnpc;
    TESModel* pmodel;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8ca);
    pnpc = (TESNPC*)(*(N_008c48d0**)((char*)this + 0x28))->GetNext();
    pbipedAnim = (*(RefVtbl**)((char*)this + 0x28))->GetBipedAnim();
    if (!pbipedAnim)
    {
        pbipedAnim = ((FUN_006055f0_shell*)pnpc)->GetOrCreateBipedAnim(*(TESObjectREFR**)((char*)this + 0x28));
    }
    if (pbipedAnim)
    {
        pnpc->RebuildHeadModel(*(TESObjectREFR**)((char*)this + 0x28), pbipedAnim, 0);
        ((FUN_004abd30_shell*)pbipedAnim)->FUN_004abd30(((IOTask*)this)->FUN_0043cc60(), (char*)this + 0x44, this);
        ((FUN_00444fe0_shell*)g_modelLoader)
            ->FUN_00444fe0(pnpc, (char*)this + 0x40, ((IOTask*)this)->FUN_0043cc60(), (QueuedFile*)this);
    }
    pmodel = pnpc ? (TESModel*)((char*)pnpc + 0xdc) : 0;
    ((FUN_00445a10_shell*)g_modelLoader)
        ->QueueModelAnimations(pmodel, ((IOTask*)this)->FUN_0043cc60(), this, *(TESObjectREFR**)((char*)this + 0x28), 0,
                               0);
    ((FUN_004412e0_shell*)this)->QueueDismemberedLimbLoads();
}
}  // namespace fnv_00441560

namespace fnv_00441e40 {
struct BSFile;
struct BSFileEntry;
struct LoadedFile;
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
struct QueuedFileEntry : public QueuedFile
{
    virtual void __vslot_0();
    virtual unsigned char GetFileIndex();
    virtual void GenerateKey();
    char* GetFileName();
    void SetFileName(char*);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry*);
    void LookupFileEntry(int);
    BSFile* GetFile(int, int);
    void GetLookupFileName(int, char*);
    bool GetDescription(char*, unsigned int, char*);
    char _pad_4[36];
    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
typedef char _sizecheck_QueuedFileEntry[sizeof(QueuedFileEntry) == 48 ? 1 : -1];
struct QueuedFileLoad : public QueuedFileEntry
{
    virtual void __vslot_0();
    virtual void DispatchToManager();
    virtual void Run();
    virtual void Finish();
    LoadedFile* GetLoadedFile();
    virtual unsigned char GetFileIndex();
    char m_pLoadedFile[4];
    int m_iLoadPriority;
};
typedef char _sizecheck_QueuedFileLoad[sizeof(QueuedFileLoad) == 56 ? 1 : -1];
struct QueuedFaceGenFile : public QueuedFileLoad
{
    virtual void __vslot_0();
    char m_kObject[4];
    char m_pMesh[4];
};
typedef char _sizecheck_QueuedFaceGenFile[sizeof(QueuedFaceGenFile) == 64 ? 1 : -1];
struct FUN_00441e40_shell : public QueuedFileLoad
{
    void FUN_00441e40();
};

struct AutoMemHelper
{
    int iSaved;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct Proc_S
{
    void* GetNext();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_004483a0_t
{
    LoadedFile* GetHolderValue(void*);
};
struct FUN_00c3cff0_t
{
    BSFile* FUN_00c3cff0(int, int);
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_0043baf0 : BSFadeNode
{
    char data[0x10];
    FUN_0043baf0(void*, BSFile*);
};
int FUN_00449050(int);
void _FNV_Warning(const char*, ...);

// Loads the next queued file via the model loader; if none, opens the file by index and creates a FUN_0043baf0, otherwise warns.
// @fnv 0x00441e40
void FUN_00441e40_shell::FUN_00441e40()
{
    BSFile* pfile;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x976);
    *(NiPointer<LoadedFile>*)m_pLoadedFile =
        ((FUN_004483a0_t*)g_modelLoader)->GetHolderValue(((Proc_S*)this)->GetNext());
    if (*(Flt*)m_pLoadedFile)
        return;
    pfile = ((FUN_00c3cff0_t*)this)->FUN_00c3cff0(FUN_00449050(m_iLoadPriority), 0xffff);
    if (pfile)
        *(NiPointer<LoadedFile>*)m_pLoadedFile = (LoadedFile*)new FUN_0043baf0(((Proc_S*)this)->GetNext(), pfile);
    else
        _FNV_Warning("MODELS: Could not get file for %s.", ((Proc_S*)this)->GetNext());
}
}  // namespace fnv_00441e40

namespace fnv_00442350 {
int __cdecl InitScriptRunLock(void*);
int __cdecl FinishScriptRunLock(void*);
struct Interface
{
    static void __cdecl PrintDebugMessage();
};
void __fastcall FUN_004424c0(char*);
struct FUN_00442510_Cl;
void __fastcall FUN_00442510(FUN_00442510_Cl*);
void __fastcall SignalAtOffset18(char*);
bool __fastcall FUN_00449130(int*);
int __fastcall _ref_0084e3a0(void*);
struct FUN_00449190_cls
{
    bool SetState(int, int);
};
struct QHeadPtr
{
    void* p;
    QHeadPtr(int);
    ~QHeadPtr();
};
struct Q449
{
    bool FUN_00449280(void*);
};
struct Flt
{
    operator unsigned int();
};
struct VTask
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
    virtual void v13();
    virtual bool NeedsPostProcess();
};
struct BackgroundCloneThread
{
    char pad[0x30];
    bool m_bThirdThreadFlag;
    char pad2[7];
    Q449* m_pCloneQueue;
    void RunBackgroundClone();
};
// @fnv 0x00442350
void BackgroundCloneThread::RunBackgroundClone()
{
    while (m_bThirdThreadFlag != true)
    {
        FUN_004424c0((char*)this);
        InitScriptRunLock((char*)this + 0x34);
        QHeadPtr spqueuedReference(0);
        m_pCloneQueue->FUN_00449280(&spqueuedReference);
        if (*(Flt*)&spqueuedReference)
        {
            while (*(Flt*)&spqueuedReference)
            {
                FUN_00442510((FUN_00442510_Cl*)this);
                Interface::PrintDebugMessage();
                QueuedReference* pqueuedRef = (QueuedReference*)(unsigned int)*(Flt*)&spqueuedReference;
                int estate = _ref_0084e3a0(pqueuedRef);
                if (!FUN_00449130((int*)pqueuedRef) && ((FUN_00449190_cls*)pqueuedRef)->SetState(estate, 3))
                {
                    if (((VTask*)pqueuedRef)->NeedsPostProcess())
                        ((IOTask*)pqueuedRef)->AddToPostProcessQueue();
                    ((FUN_00449190_cls*)pqueuedRef)->SetState(3, 5);
                }
                m_pCloneQueue->FUN_00449280(&spqueuedReference);
                Interface::PrintDebugMessage();
                SignalAtOffset18((char*)this);
            }
        }
        else
        {
            FUN_00442510((FUN_00442510_Cl*)this);
            SignalAtOffset18((char*)this);
        }
        FinishScriptRunLock((char*)this + 0x34);
    }
}
}  // namespace fnv_00442350

namespace fnv_00443540 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_00443540_shell : public ModelLoader
{
    bool FUN_00443540(BSFileEntry*, int, QueuedFile*);
};

struct QHeadPtr
{
    ~QHeadPtr();
    void* m_pObject;
};
struct Flt : QHeadPtr
{
    operator unsigned int();
};
struct QueueObj : Flt
{
    QueueObj(int);
};
struct S_00448f80
{
    int FUN_00448f80(BSFileEntry*);
};
struct S_0084e3a0
{
    int _ref_0084e3a0();
};
struct FUN_00449190_cls
{
    bool SetState(int, int);
};
struct FUN_0043c3d0_shell
{
    bool FUN_0043c3d0();
};
struct MLa
{
    bool IsLoadTexturesDegraded();
};
struct Q_0043c050
{
    bool ForwardByteToMember(bool);
};
struct S_00c3c7e0
{
    void FUN_00c3c7e0(QueuedFile*);
};
struct S_0044adb0
{
    void FUN_0044adb0();
};
struct V_00443540
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetPriority(int);
};

// @fnv 0x00443540
bool FUN_00443540_shell::FUN_00443540(BSFileEntry* apTextureFileEntry, int aePriority, QueuedFile* apParent)
{
    QueueObj spexistingQueuedTexture(((S_00448f80*)this)->FUN_00448f80(apTextureFileEntry));
    if (spexistingQueuedTexture)
    {
        int estate = ((S_0084e3a0*)(unsigned int)spexistingQueuedTexture)->_ref_0084e3a0();
        if (estate < 3 && ((FUN_00449190_cls*)(unsigned int)spexistingQueuedTexture)->SetState(estate, 2))
        {
            if (((FUN_0043c3d0_shell*)(unsigned int)spexistingQueuedTexture)->FUN_0043c3d0() &&
                !((MLa*)this)->IsLoadTexturesDegraded())
                ((Q_0043c050*)(unsigned int)spexistingQueuedTexture)->ForwardByteToMember(false);
            if (apParent)
                ((S_00c3c7e0*)(unsigned int)spexistingQueuedTexture)->FUN_00c3c7e0(apParent);
            if (((FUN_00449190_cls*)(unsigned int)spexistingQueuedTexture)->SetState(2, estate))
            {
                if (((IOTask*)(unsigned int)spexistingQueuedTexture)->FUN_0043cc60() > aePriority)
                    ((V_00443540*)(unsigned int)spexistingQueuedTexture)->SetPriority(aePriority);
                else
                    ((S_0044adb0*)DAT_01202d98)->FUN_0044adb0();
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_00443540

namespace fnv_004446a0 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_004446a0_shell : public ModelLoader
{
    bool QueueKFModelLoad(char*, int, QueuedFile*);
};

struct Flt
{
    operator unsigned int();
};
struct QHeadLocal
{
    void SetParent(QueuedFile*);
};
namespace FUN_00528cb0 {
struct FUN_0044cbf0
{
    void* p;
    FUN_0044cbf0(void*);
    ~FUN_0044cbf0();
};
}
struct FUN_0043e210
{
    unsigned int pad[14];
    FUN_0043e210(KFModel*, int);
};
struct FUN_0043e0f0
{
    unsigned int pad[14];
    FUN_0043e0f0(char*, int);
};
struct KFMapStand
{
    virtual void v0();
    virtual void v1();
    virtual bool Get(char*, KFModel**);
};
// @fnv 0x004446a0
bool FUN_004446a0_shell::QueueKFModelLoad(char* apKFFileName, int aePriority, QueuedFile* apParent)
{
    KFModel* pkfModel = 0;
    if (((KFMapStand**)this)[1]->Get(apKFFileName, &pkfModel))
    {
        if (apParent)
        {
            FUN_00528cb0::FUN_0044cbf0 spqueuedKF(new FUN_0043e210(pkfModel, aePriority));
            ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedKF)->SetParent(apParent);
            ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedKF)->vfn_28();
            return true;
        }
        return false;
    }
    FUN_00528cb0::FUN_0044cbf0 spqueuedKF(new FUN_0043e0f0(apKFFileName, aePriority));
    ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedKF)->SetParent(apParent);
    ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedKF)->vfn_20();
    return true;
}
}  // namespace fnv_004446a0

namespace fnv_00444dc0 {
struct TESObject;
struct TES
{
    static int __cdecl GetModelResourceType(TESObject*);
};
struct QHeadPtr
{
    void* p;
    ~QHeadPtr();
};
struct QueueObj : QHeadPtr
{
    QueueObj(int);
};
struct QHeadPtrDest
{
    QHeadPtrDest& Assign(const QHeadPtr&);
};
struct QueueModelHolder
{
    void FUN_00443dc0(int, QueueObj*, int, int, int, bool, bool, bool, float);
};
struct FUN_00444dc0_ref
{
    bool FUN_00564e60();
    bool FUN_00444ed0();
    bool FUN_00564f00();
};
struct FUN_00444dc0_t
{
    int FUN_00446a60(TESObject*, FUN_00444dc0_ref*);
    void QueueModelForObject(TESObject* apObject, QHeadPtrDest* apDest, int a3, int a4, FUN_00444dc0_ref* apRef);
};
// Computes a handle and LOD for apObject, queues a model load with fade distance, and assigns the queued handle to apDest.
// @fnv 0x00444dc0
void FUN_00444dc0_t::QueueModelForObject(TESObject* apObject, QHeadPtrDest* apDest, int a3, int a4,
                                         FUN_00444dc0_ref* apRef)
{
    int iHandle = FUN_00446a60(apObject, apRef);
    int iLOD = TES::GetModelResourceType(apObject);
    if (apRef && (apRef->FUN_00564e60() || apRef->FUN_00444ed0()))
        iLOD = 6;
    QueueObj kQueued(0);
    float fFadeDist = 0.0f;
    if (apRef && apRef->FUN_00564f00())
        fFadeDist = 3.402823466e+38F;
    ((QueueModelHolder*)g_modelLoader)->FUN_00443dc0(iHandle, &kQueued, a3, a4, iLOD, true, false, false, fFadeDist);
    apDest->Assign(kQueued);
}
}  // namespace fnv_00444dc0

namespace fnv_00447080 {
struct FUN_00447080_shell : public ModelLoader
{
    NiNode* LoadModel(char*, int, bool, bool, bool, bool);
};

struct Flt
{
    operator unsigned int();
};
namespace FUN_0043c6e0 {
struct FUN_0043c830
{
    unsigned int pad[0xc];
    Flt model;
    unsigned int pad2[5];
    FUN_0043c830(char*, int, int, bool, int);
    ~FUN_0043c830();
};
}
struct FUN_00443ff0Class
{
    void FUN_00443ff0(unsigned char);
};
struct FUN_00447190_dummy
{
    void FUN_00447190(unsigned char);
};
struct FUN_0043ccf0_s
{
    void FUN_0043ccf0();
};
struct FUN_0043d180_s
{
    void FUN_0043d180();
};
struct FUN_00443190_s
{
    int GetCombinedValue();
};
struct ObjA
{
    void FUN_0092c870();
};
struct FUN_0043b230_s
{
    NiNode* FUN_0043b230();
};
void FUN_005b5e40(const char*, ...);
struct ModelMapStand
{
    virtual void v0();
    virtual void v1();
    virtual bool Get(char*, Model**);
};
// @fnv 0x00447080
NiNode* FUN_00447080_shell::LoadModel(char* apFilename, int aeLODFadeMult, bool abPrepareObject,
                                         bool abSuppressWarning, bool abFaceGenModel, bool abDontIncrementRefCount)
{
    Model* pmodel = 0;
    if (!(*(ModelMapStand**)this)->Get(apFilename, &pmodel))
    {
        FUN_0043c6e0::FUN_0043c830 queuedModel(apFilename, 0, aeLODFadeMult, abPrepareObject, 0);
        reinterpret_cast<FUN_00443ff0Class*>(&queuedModel)->FUN_00443ff0(abFaceGenModel);
        reinterpret_cast<FUN_00447190_dummy*>(&queuedModel)->FUN_00447190(1);
        reinterpret_cast<FUN_0043ccf0_s*>(&queuedModel)->FUN_0043ccf0();
        reinterpret_cast<FUN_0043d180_s*>(&queuedModel)->FUN_0043d180();
        pmodel = (Model*)(unsigned int)queuedModel.model;
    }
    else if (!reinterpret_cast<FUN_00443190_s*>(pmodel)->GetCombinedValue())
    {
        FUN_005b5e40("MODELS: LoadFile retrieved model %s with a zero ref count", apFilename);
    }
    if (pmodel)
    {
        if (!abDontIncrementRefCount)
            reinterpret_cast<ObjA*>(pmodel)->FUN_0092c870();
        return reinterpret_cast<FUN_0043b230_s*>(pmodel)->FUN_0043b230();
    }
    return 0;
}
}  // namespace fnv_00447080

namespace fnv_00447a40 {
struct FUN_00447a40_shell : public ModelLoader
{
    void FUN_00447a40(char*, int, QueuedFile*, int);
};

struct LoadedFile;
template <> class NiPointer<LoadedFile>
{
  public:
    NiPointer(LoadedFile* pObject);
    LoadedFile* m_pObject;
};
struct FUN_0044b160 : public NiPointer<LoadedFile>
{
    FUN_0044b160(LoadedFile* pObject) : NiPointer<LoadedFile>(pObject)
    {}
    ~FUN_0044b160();
};
struct QueueObj
{
    QueueObj(int);
    void* m_pObject;
};
struct QHeadPtr : public QueueObj
{
    QHeadPtr(int pObject) : QueueObj(pObject)
    {}
    ~QHeadPtr();
};
struct Flt
{
    operator unsigned int();
};
struct QHeadLocal
{
    void SetParent(QueuedFile*);
};
struct FUN_004483a0_S
{
    LoadedFile* GetHolderValue(const char*);
};
struct FUN_004420b0
{
    FUN_004420b0(unsigned int, int);
    char pad[0x40];
};
struct FUN_00441f80
{
    FUN_00441f80(const char*, int, int);
    char pad[0x40];
};

// Loads the file via GetHolderValue; if loaded, queues a FUN_004420b0 task with the parent, otherwise queues a FUN_00441f80 task and sets its parent.
// @fnv 0x00447a40
void FUN_00447a40_shell::FUN_00447a40(char* apFileName, int aePriority, QueuedFile* apParent, int aeFileIndex)
{
    FUN_0044b160 m_pLoadedFile(((FUN_004483a0_S*)this)->GetHolderValue(apFileName));
    if (*(Flt*)&m_pLoadedFile)
    {
        if (apParent)
        {
            QHeadPtr spqueuedFaceGenFile((int)new FUN_004420b0(*(Flt*)&m_pLoadedFile, aePriority));
            ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->SetParent(apParent);
            ((IOTask*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->vfn_28();
        }
        return;
    }
    QHeadPtr spqueuedFaceGenFile((int)new FUN_00441f80(apFileName, aePriority, aeFileIndex));
    ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->SetParent(apParent);
    ((IOTask*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->vfn_20();
}
}  // namespace fnv_00447a40

struct Virt00448370
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Stand00448370
{
    char _pad[0x24];
    Virt00448370* field24;
    void __thiscall FUN_00448370(int);
};
// Calls the virtual method f5 on field24, passing a through.
// @fnv 0x00448370
void __thiscall Stand00448370::FUN_00448370(int aiValue)
{
    field24->f5(aiValue);
}

namespace fnv_00448cc0 {
struct GlobalObject_00448e00
{
    GlobalObject_00448e00();
    __int64 iStart;
    __int64 iEnd;
};
struct FUN_00448e30_this
{
    void init(float);
};
bool __fastcall IsNotStateSix(int);
bool __fastcall FUN_00448e70(__int64*);
extern float DAT_01017130;
struct FUN_004499c0
{
    ~FUN_004499c0();
    void* p0;
    void* p1;
    void* p2;
    void* p3;
};
struct FUN_0044cc10 : public FUN_004499c0
{
    FUN_0044cc10();
};
struct FUN_006ebde0_shell
{
    bool FUN_006ebde0();
};
struct QHeadPtr
{
    ~QHeadPtr();
    void* p;
};
struct QueueObj : public QHeadPtr
{
    QueueObj(int);
};
struct Flt
{
    operator unsigned int();
};
struct QueuedTask_00448cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Run();
};
struct Queue_00448cc0
{
    bool ProcessIteration(FUN_0044cc10*, int*, QueueObj*, bool);
};
struct ModelLoaderStand_00448cc0
{
    char pad[0xc];
    Queue_00448cc0* m_pPrimaryTaskProcessor;
    bool ProcessQueuedTasks();
};

// Initializes a timer, then repeatedly dequeues tasks and runs them until the queue is empty or the timer expires; returns whether the queue is empty.
// @fnv 0x00448cc0
bool ModelLoaderStand_00448cc0::ProcessQueuedTasks()
{
    GlobalObject_00448e00 kTimer;
    if (IsNotStateSix((int)DAT_01202d98))
        ((FUN_00448e30_this*)&kTimer)->init(DAT_01017130);
    else
        ((FUN_00448e30_this*)&kTimer)->init(5.0f);
    {
        FUN_0044cc10 kTaskList;
        while (!((FUN_006ebde0_shell*)&kTaskList)->FUN_006ebde0() && !FUN_00448e70((__int64*)&kTimer))
        {
            int iCount = 0;
            QueueObj kTask(0);
            if (m_pPrimaryTaskProcessor->ProcessIteration(&kTaskList, &iCount, &kTask, true))
                ((QueuedTask_00448cc0*)(unsigned int)*(Flt*)&kTask)->Run();
        }
        return ((FUN_006ebde0_shell*)&kTaskList)->FUN_006ebde0();
    }
}
}  // namespace fnv_00448cc0

namespace fnv_0044afe0 {
struct KFModel
{
    void FUN_0044b010(void);
};
struct S0044afe0
{
    KFModel* p;
    S0044afe0* FUN_0044afe0(KFModel* a);
};
// Stores the given KFModel pointer in p and, if it is non-null, calls its FUN_0044b010 method; returns this.
// @fnv 0x0044afe0
S0044afe0* S0044afe0::FUN_0044afe0(KFModel* apModel)
{
    p = apModel;
    if (p != 0)
        p->FUN_0044b010();
    return this;
}
}  // namespace fnv_0044afe0

namespace fnv_00528ce0 {
bool __cdecl FUN_004491c0(void*, int, int);
int __fastcall ClearLowBit(int*);
struct FUN_0044df00Class
{
    char* FUN_0044df00();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_006ecba0_class
{
    void* FUN_006ecba0(bool, void*);
    int iValue;
};
struct V40
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
};
struct FUN_00528ce0_shell
{
    V40* pObject;
    bool FUN_00528ce0(void* apA, void* apB);
    bool ProcessNode(void* apA, void* apB);
    void FUN_005292a0(int);
    void FUN_00529000();
};

// @fnv 0x00528ce0
bool FUN_00528ce0_shell::FUN_00528ce0(void* apA, void* apB)
{
    bool bResult = false;
    while (1)
    {
        FUN_006ecba0_class kCur;
        if (!ProcessNode(apA, apB))
        {
            bResult = false;
            break;
        }
        {
            FUN_006ecba0_class kOld;
            FUN_006ecba0_class kNew;
            kOld.FUN_006ecba0(false, (void*)ClearLowBit((int*)((char*)this + 0x18)));
            kNew.FUN_006ecba0(true, (void*)ClearLowBit((int*)((char*)this + 0x18)));
            if (!FUN_004491c0(((FUN_0044df00Class*)((char*)this + 0x14))->FUN_0044df00() + 8,
                              (unsigned int)*(Flt*)&kNew, (unsigned int)*(Flt*)&kOld))
                continue;
            kCur.FUN_006ecba0(false, (void*)ClearLowBit((int*)((char*)this + 0x14)));
            if (FUN_004491c0(*(void**)((char*)this + 0x10), (unsigned int)*(Flt*)&kOld, (unsigned int)*(Flt*)&kCur))
                FUN_005292a0(ClearLowBit((int*)((char*)this + 0x14)));
            else
                ProcessNode(apA, apB);
            pObject->f10();
            bResult = true;
            break;
        }
    }
    FUN_00529000();
    return bResult;
}
}  // namespace fnv_00528ce0

namespace fnv_00443270 {
struct FUN_006ebde0_shell
{
    bool FUN_006ebde0();
};
struct FUN_00443190_shell
{
    int GetCombinedValue();
};
int __fastcall FUN_004431b0(int*);
int __fastcall _ref_0084e3a0(void*);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl _FNV_Warning(const char*, ...);
unsigned int __cdecl _strlen(const char*);
struct GridArray
{
    int GetCenterX() const;
    int m_fCenterY() const;
};
struct BSAudio
{
    void* GetAudioBackendData();
};
struct Flt
{
    operator unsigned int();
};
template <class T> struct BSStringT
{
    T* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(char const*, ...);
};
struct FUN_004431d0
{
    char m_buf[0x10c];
    ~FUN_004431d0();
};
struct FUN_004498e0 : FUN_004431d0
{
    FUN_004498e0();
};
struct FUN_00443220
{
    char m_buf[0x110];
    ~FUN_00443220();
};
struct FUN_00449960 : FUN_00443220
{
    FUN_00449960();
};
struct Map_443270
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
    virtual int GetCount();
    bool TryGetNextEntry(void* pIter, const char** ppKey, void** ppVal, int a);
};
struct File_443270
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
    virtual void WriteString(BSStringT<char>*, int);
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void Write(const char*, unsigned int);
};
struct FUN_00443270_shell
{
    Map_443270* m_pModels;
    Map_443270* m_pAnims;
    void FUN_00443270(File_443270* pFile, bool bAll);
};
// Iterates the model and animation maps, formats each entry's counts into a line, logs it via _FNV_Warning and optionally writes it to pFile.
// @fnv 0x00443270
void FUN_00443270_shell::FUN_00443270(File_443270* pFile, bool bAll)
{
    if (m_pModels->GetCount())
    {
        FUN_004498e0 kIter;
        while (!((FUN_006ebde0_shell*)&kIter)->FUN_006ebde0())
        {
            const char* pKey = 0;
            void* pVal = 0;
            if (m_pModels->TryGetNextEntry(&kIter, &pKey, &pVal, 1))
            {
                if (((FUN_00443190_shell*)pVal)->GetCombinedValue() > 0 || bAll)
                {
                    char acBuf[1024];
                    _sprintf_s(acBuf, 1024, "MODELS:\t%3d\t%3d\t%3d\t%s\r\n",
                               ((FUN_00443190_shell*)pVal)->GetCombinedValue(), ((GridArray*)pVal)->GetCenterX(),
                               ((GridArray*)pVal)->m_fCenterY(), pKey);
                    _FNV_Warning(acBuf);
                    if (pFile)
                        pFile->Write(acBuf, _strlen(acBuf) + 1);
                }
            }
        }
    }
    if (m_pAnims->GetCount())
    {
        FUN_00449960 kIter2;
        while (!((FUN_006ebde0_shell*)&kIter2)->FUN_006ebde0())
        {
            const char* pKey2 = 0;
            void* pVal2 = 0;
            if (m_pAnims->TryGetNextEntry(&kIter2, &pKey2, &pVal2, 1))
            {
                if (FUN_004431b0((int*)pVal2) > 0)
                {
                    BSStringT<char> kStr;
                    kStr.PrintfString("ANIMATION:\t%3d\t%3d\t%3d\t%s\r\n", FUN_004431b0((int*)pVal2), _ref_0084e3a0(pVal2),
                                 ((BSAudio*)pVal2)->GetAudioBackendData(), pKey2);
                    _FNV_Warning((const char*)(unsigned int)*(Flt*)&kStr);
                    if (pFile)
                        pFile->WriteString(&kStr, 1);
                }
            }
        }
    }
}
}  // namespace fnv_00443270

struct NiFile;
struct FileFinder
{
    static NiFile* GetFile(char const*, int, unsigned int, unsigned int);
};
struct FUN_00c3d090_shell2
{
    void FUN_00c3d090(int, char*);
};
NiFile* __cdecl FUN_00af6340(int, int, int, int);
struct FUN_00c3cff0_shell
{
    NiFile* FUN_00c3cff0(int, int);
};
// @fnv 0x00c3cff0
NiFile* FUN_00c3cff0_shell::FUN_00c3cff0(int aeArchiveTypeIndex, int aeArchiveType)
{
    NiFile* pFile = 0;
    if (*(int*)((char*)this + 0x2c))
    {
        pFile = FUN_00af6340(aeArchiveTypeIndex, *(int*)((char*)this + 0x2c), -1, 0);
    }
    if (*(int*)((char*)this + 0x28) && !pFile)
    {
        char plookupFileName[260];
        ((FUN_00c3d090_shell2*)this)->FUN_00c3d090(aeArchiveTypeIndex, plookupFileName);
        pFile = FileFinder::GetFile(plookupFileName, 0, -1, aeArchiveType);
    }
    return pFile;
}

namespace fnv_0043c650 {
struct FUN_006fbcd0_shell
{
    void FUN_00c3cb70(int, int);
};
struct FUN_0043c630_shell
{
    bool FUN_0043c630();
};
struct Q_0043c050
{
    void FUN_0043c100(bool);
};
struct ModelLoader_00448f50
{
    void ForwardToVTableSlot(BSFileEntry*);
};

struct QueuedTexture_0043c650
{
    void FUN_00c3cb70(int, int);
    bool FUN_0043c630();
    void FUN_0043c100(bool);
    BSFileEntry* SetLocRef();
    void FUN_0043c650(int aePreviousState, void* apTaskOwner);
};

// @fnv 0x0043c650
void QueuedTexture_0043c650::FUN_0043c650(int aePreviousState, void* apTaskOwner)
{
    FUN_00c3cb70(aePreviousState, (int)apTaskOwner);
    if (SetLocRef())
    {
        if (FUN_0043c630())
        {
            FUN_0043c100(false);
            ((ModelLoader_00448f50*)g_modelLoader)->ForwardToVTableSlot(SetLocRef());
        }
    }
}
}  // namespace fnv_0043c650

struct FUN_00449130_s
{
    bool __fastcall FUN_00449130();
};
struct Flt_s
{
    operator unsigned int();
};
struct FUN_0043ea30_s
{
    void FUN_0043ea30();
};
struct FUN_00490fa0_s
{
    void FUN_00490fa0(unsigned int);
};
struct FUN_0043e9b0_s
{
    void FUN_0043e9b0();
};
// @fnv 0x0043e9b0
void FUN_0043e9b0_s::FUN_0043e9b0()
{
    if (!((FUN_00449130_s*)this)->FUN_00449130())
    {
        ((FUN_00490fa0_s*)*(void**)((char*)this + 0x38))->FUN_00490fa0((unsigned int)*(Flt_s*)((char*)this + 0x30));
        if (*(void**)((char*)this + 0x3c))
            ((FUN_0043ea30_s*)*(void**)((char*)this + 0x3c))->FUN_0043ea30();
    }
}

namespace fnv_0043ea30 {
struct Holder14
{
    void ForwardToInner(int);
};
struct FUN_0043ea30_shell : IOTask
{
    void FUN_0043ea30();
};
// @fnv 0x0043ea30
void FUN_0043ea30_shell::FUN_0043ea30()
{
    ((int*)this)[12]++;
    if (FUN_00449110() && FUN_0043caa0() && ((int*)this)[11] == ((int*)this)[12])
        ((Holder14*)g_modelLoader)->ForwardToInner(((int*)this)[10]);
}
}  // namespace fnv_0043ea30

namespace fnv_0043f240 {
struct BSFaceGenModel;
struct BipedAnim
{
    bool IsSlotHidden(int);
    BSFaceGenModel* GetFaceGenModelForSlot(int);
};
struct GO
{
    void operator=(void*);
};
struct QueuedHelmet
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    BipedAnim* pExistingBipedAnim;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    GO m_kQueuedModels[80];
    void UpdateFaceGenModels();
};
bool __fastcall FUN_00449130(int*);
// @fnv 0x0043f240
void QueuedHelmet::UpdateFaceGenModels()
{
    for (int i = 0; i < 20; i++)
    {
        if (pExistingBipedAnim->IsSlotHidden(i) && !FUN_00449130((int*)this))
            *(GO*)((char*)this + 0x7c + i * 4) = (void*)pExistingBipedAnim->GetFaceGenModelForSlot(i);
    }
}
}  // namespace fnv_0043f240

namespace fnv_00440710 {
extern int _data_011c16bc;
struct QueueObj
{
    int x;
    QueueObj(int);
    ~QueueObj();
};
struct E_00449210
{
    void FUN_00449240(QueueObj*);
};
struct FUN_00440710_t
{
    int p0, p1, p2, p3, p4, p5, p6;
    E_00449210* q;
    void DispatchToQueue(int a);
};
// Constructs a QueueObj from a and passes its address to q->FUN_00449240.
// @fnv 0x00440710
void FUN_00440710_t::DispatchToQueue(int aiValue)
{
    QueueObj o(aiValue);
    q->FUN_00449240(&o);
}
}  // namespace fnv_00440710

struct Loader_S
{
    unsigned char ReleaseAllObjects();
    unsigned char ProcessQueuedTasks();
};
// Calls ReleaseAllObjects and ProcessQueuedTasks on g_modelLoader and returns 1 only if both return nonzero.
// @fnv 0x00446e40
char FUN_00446e40()
{
    unsigned char a = 1;
    unsigned char b = 1;
    a = ((Loader_S*)g_modelLoader)->ReleaseAllObjects();
    b = ((Loader_S*)g_modelLoader)->ProcessQueuedTasks();
    return (a && b) ? 1 : 0;
}

struct S_0044dbc0
{
    virtual ~S_0044dbc0();
};
struct FUN_00449c50 : S_0044dbc0
{
    void FUN_0044c480(int);
    virtual ~FUN_00449c50();
};
// Destructor that calls FUN_0044c480 with argument 1.
// @fnv 0x00449c50
FUN_00449c50::~FUN_00449c50()
{
    FUN_0044c480(1);
}

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

struct FUN_00449cb0_Helper
{
    unsigned int ComputeNameHash(char* name);
};

// Hashes the null-terminated name with a 33x multiplier and returns the hash modulo the object's flags value.
// @fnv 0x00449cb0
unsigned int FUN_00449cb0_Helper::ComputeNameHash(char* name)
{
    unsigned int hash = 0;
    while (*name)
    {
        hash = hash * 32 + hash + (signed char)*name;
        name++;
    }
    return hash % ((TESObjectREFR_GetFlags_Helper*)((TESObjectREFR*)this))->CallGetFlags();
}

struct FUN_0044c480
{
    virtual ~FUN_0044c480();
    void FUN_0044c3f0(int);
};

struct FUN_00449d60 : FUN_0044c480
{
    virtual ~FUN_00449d60();
};

// Destructor that calls FUN_0044c3f0 with 1.
// @fnv 0x00449d60
FUN_00449d60::~FUN_00449d60()
{
    FUN_0044c3f0(1);
}

namespace fnv_00449ec0 {
extern int DAT_0101737c;
struct FUN_0044c480
{
    virtual ~FUN_0044c480();
    void M(bool);
};
struct FUN_00449ec0 : FUN_0044c480
{
    virtual ~FUN_00449ec0();
};
// Destructor that calls M(true) on the base class.
// @fnv 0x00449ec0
FUN_00449ec0::~FUN_00449ec0()
{
    M(true);
}
}  // namespace fnv_00449ec0

namespace fnv_0044b300 {
struct FUN_0044b2a0_Class
{
    void FUN_0044b2a0();
};
void __fastcall FUN_0044b2e0(void*);
struct FUN_0044b300_Class
{
    FUN_0044b2a0_Class* m_pObject;
    FUN_0044b300_Class* FUN_0044b300(FUN_0044b2a0_Class* value);
};
// @fnv 0x0044b300
FUN_0044b300_Class* FUN_0044b300_Class::FUN_0044b300(FUN_0044b2a0_Class* apObject)
{
    if (m_pObject != apObject)
    {
        if (m_pObject)
            FUN_0044b2e0(m_pObject);
        m_pObject = apObject;
        if (m_pObject)
            m_pObject->FUN_0044b2a0();
    }
    return this;
}
}  // namespace fnv_0044b300

namespace fnv_005292a0 {
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct BSAudio
{
    int GetAudioBackendData();
};
struct DeletedNodeScanner
{
    void ScanForDeletedNodes();
};
struct FUN_005292a0 : public BSAudio
{
    unsigned int f0, f4, f8, fc, f10, f14, f18, f1c;
    unsigned int f20;
    void SetRace(unsigned int race);
};
// @fnv 0x005292a0
void FUN_005292a0::SetRace(unsigned int race)
{
    ((QIdlePtr*)(race + 4))->operator=(0);
    ((TESRaceForm*)race)->Initialize(f1c);
    f1c = race;
    f20++;
    if (f20 == ((BSAudio*)*(unsigned int*)this)->GetAudioBackendData())
        ((DeletedNodeScanner*)this)->ScanForDeletedNodes();
}
}  // namespace fnv_005292a0

namespace fnv_00666510 {
struct BSAudio
{
    int GetAudioBackendData();
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct FUN_0044f200_Class
{
    void FilterListByQueueData();
};
struct FUN_00666510_Class
{
    void AddRace(TESRaceForm* pRace);
};
// @fnv 0x00666510
void FUN_00666510_Class::AddRace(TESRaceForm* pRace)
{
    *(unsigned int*)((char*)pRace + 4) = 0;
    pRace->Initialize(*(unsigned int*)((char*)this + 0x1c));
    *(TESRaceForm**)((char*)this + 0x1c) = pRace;
    *(unsigned int*)((char*)this + 0x20) += 1;
    if (*(unsigned int*)((char*)this + 0x20) == (*(BSAudio**)((char*)this))->GetAudioBackendData())
        ((FUN_0044f200_Class*)this)->FilterListByQueueData();
}
}  // namespace fnv_00666510

namespace fnv_009052e0 {
struct KFModel
{
    void FUN_0044b010();
    void FUN_0044b050();
};
struct KFModelPtr
{
    KFModel* p;
    KFModel* FUN_009052e0(const KFModelPtr& other);
};
// @fnv 0x009052e0
KFModel* KFModelPtr::FUN_009052e0(const KFModelPtr& other)
{
    if (p != other.p)
    {
        if (p)
            p->FUN_0044b050();
        p = other.p;
        if (p)
            p->FUN_0044b010();
    }
    return (KFModel*)this;
}
}  // namespace fnv_009052e0

struct NiFile
{
    static NiFile* __cdecl GetFile(const char*, int, unsigned int);
    virtual ~NiFile();
};

struct NiStream
{
    bool Save(NiFile* apFile);
};

struct FUN_00c3a950 : NiStream
{
    bool SaveFile(const char* apPath);
};

// Opens the file at apPath with NiFile::GetFile, saves the stream to it, deletes the file object and returns whether the save succeeded.
// @fnv 0x00c3a950
bool FUN_00c3a950::SaveFile(const char* apPath)
{
    NiFile* pFile = NiFile::GetFile(apPath, 1, 0x2800);
    bool bResult = false;
    if (pFile)
    {
        bResult = Save(pFile);
        delete pFile;
    }
    return bResult;
}

class BSStream
{
  public:
    ~BSStream();
    void* FUN_0043d150(unsigned int flags);
};

void __cdecl _Deallocate(void*);

BSStream::~BSStream()
{}

// Destroys the BSStream, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0043d150
void* BSStream::FUN_0043d150(unsigned int flags)
{
    this->BSStream::~BSStream();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0043d8c0 {
struct QueuedTreeModel
{
    void FUN_0043d8f0();
    void* FUN_0043d8c0(unsigned int flags);
};

void _Deallocate(void*);

// @fnv 0x0043d8c0
void* QueuedTreeModel::FUN_0043d8c0(unsigned int flags)
{
    this->FUN_0043d8f0();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_0043d8c0

namespace fnv_0043d910 {
struct FNStub
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual char* vfn_18();
    char* GetFullName();
};

struct TESObjectTREE
{
    unsigned char padding[0x48];
    FNStub stub;
};

struct QueuedTreeModel : QueuedModel
{
    unsigned char padding[0x44];
    TESObjectREFR* pRef;
    TESObjectTREE* pTree;

    void QueueTreeModelLoad();
};

struct ModelLoaderQueueTexture : ModelLoader
{
    void QueueModelFilePath(const char*, int, QueuedFile*);
};

bool __cdecl CleanPath(const char*, char*, unsigned int);

// @fnv 0x0043d910
void QueuedTreeModel::QueueTreeModelLoad()
{
    if (pTree->stub.GetFullName()[0] != 0)
    {
        char pfilename[260];

        TaskQueueInterface::CopyStringToBuffer(pfilename, 0x104, pTree->stub.vfn_18());

        strcat_s(pfilename, 0x104, pTree->stub.GetFullName());

        {
            char pbasefilename[260];

            CleanPath(pfilename, pbasefilename, 0x104);

            reinterpret_cast<ModelLoaderQueueTexture*>(g_modelLoader)
                ->QueueModelFilePath(pbasefilename, this->FUN_0043cc60(), static_cast<QueuedFile*>(this));
        }
    }

    this->DispatchToManager();
}
}  // namespace fnv_0043d910

namespace fnv_0043da00 {
struct I2_665b80
{
};

typedef I2_665b80 BSTreeNode;

struct C665b80
{
    void FUN_00665b80(int, I2_665b80*);
};

struct BSTreeManager : public C665b80
{
    BSTreeNode* CreateTreeInstance(int, int);
};

struct AutoMemHelper
{
    int m_data;

    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};

typedef AutoMemHelper AutoMemContext;

struct QueuedTreeModel
{
    unsigned char padding[0x48];
    int pRef;
    int pTree;

    void FUN_0043da00();
};

BSTreeManager* DAT_011d5c48;

// Looks up a BSTreeNode by pRef and pTree via DAT_011d5c48 and passes it to FUN_00665b80 with pRef, inside an AutoMemContext scope.
// @fnv 0x0043da00
void QueuedTreeModel::FUN_0043da00()
{
    BSTreeNode* ptreeNode;
    AutoMemContext tempMemContext(0x1e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                                  0x476);

    ptreeNode = DAT_011d5c48->CreateTreeInstance(pRef, pTree);
    DAT_011d5c48->FUN_00665b80(pRef, ptreeNode);
}
}  // namespace fnv_0043da00

namespace fnv_0043e8f0 {
void __cdecl _Deallocate(void* ptr);

class FUN_0043e920_class
{
  public:
    void FUN_0043e920();
    void* FUN_0043e8f0(unsigned int flags);
};

void FUN_0043e920_class::FUN_0043e920()
{}

// Calls FUN_0043e920, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0043e8f0
void* FUN_0043e920_class::FUN_0043e8f0(unsigned int flags)
{
    FUN_0043e920();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0043e8f0

struct FNStub
{
    char* GetFullName();
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct QueuedHeadStandIn
{
    bool GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize);
};

// Formats "Queued head for NPC %s" into apDescription using the full name of the object at this+0x28, and returns true.
// @fnv 0x0043eed0
bool QueuedHeadStandIn::GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Queued head for NPC %s",
               reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(
                                             *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x28)) +
                                         0xd0)
                   ->GetFullName());
    return true;
}

namespace fnv_0043f030 {
struct QueuedHelmet
{
    void FUN_0043f080();
    void* FUN_0043f030(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// @fnv 0x0043f030
void* QueuedHelmet::FUN_0043f030(unsigned int flags)
{
    FUN_0043f080();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_0043f030

namespace fnv_0043f2b0 {
class GO
{
  public:
    operator unsigned int() const;
};

class FUN_0043c610_shell
{
  public:
    void RunVirtualMethod28();
};

bool __fastcall FUN_00449130(int*);

class QueuedHelmet
{
  public:
    void FUN_0043f2b0();
};

// If the object at offset 0x1c is zero and FUN_00449130 returns false, adds this to the post-process queue, then calls RunVirtualMethod28.
// @fnv 0x0043f2b0
void QueuedHelmet::FUN_0043f2b0()
{
    if (!reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x1c)->operator unsigned int() &&
        !FUN_00449130(reinterpret_cast<int*>(this)))
    {
        reinterpret_cast<IOTask*>(this)->AddToPostProcessQueue();
    }

    reinterpret_cast<FUN_0043c610_shell*>(this)->RunVirtualMethod28();
}
}  // namespace fnv_0043f2b0

namespace fnv_0043fb80 {
struct BSFaceGenModel
{
    int unused;
};

struct GO
{
    void* p;
    operator unsigned int() const;
};

enum BIPED_OBJECT
{
    BIPED_OBJECT_VALUE
};

struct FUN_004aeb20_holder
{
    void AttachFaceGenModel(BSFaceGenModel*, NiNode*, BIPED_OBJECT);
};

struct BipedAnim : public FUN_004aeb20_holder
{
};

struct Standin0043fb50
{
    void DispatchToVirtual(int);
};

struct QueuedHelmet
{
    unsigned char unused[0x28];
    BipedAnim* pExistingBipedAnim;
    unsigned char unused2[0x50];
    GO m_kQueuedModels[20];
    GO m_kQueuedModelsSecondary[20];
    int pRef;

    void ApplyQueuedModels();
};

// @fnv 0x0043fb80
void QueuedHelmet::ApplyQueuedModels()
{
    int n;
    for (n = 0; n < 0x14; ++n)
    {
        if (m_kQueuedModelsSecondary[n].operator unsigned int() != 0)
        {
            pExistingBipedAnim->AttachFaceGenModel(
                reinterpret_cast<BSFaceGenModel*>(m_kQueuedModels[n].operator unsigned int()),
                reinterpret_cast<NiNode*>(m_kQueuedModelsSecondary[n].operator unsigned int()),
                static_cast<BIPED_OBJECT>(n));
        }
    }

    reinterpret_cast<Standin0043fb50*>(g_modelLoader)->DispatchToVirtual(pRef);
}
}  // namespace fnv_0043fb80

namespace fnv_0043fe10 {
void _Deallocate(void*);

struct FUN_00440eb0_class
{
    void FUN_0043fe40(void);
    void* FUN_0043fe10(unsigned int flags);
};

// @fnv 0x0043fe10
void* FUN_00440eb0_class::FUN_0043fe10(unsigned int flags)
{
    FUN_0043fe40();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_0043fe10

void __cdecl _Deallocate(void*);

struct QueuedFileLoad
{
    void FUN_00441d20();
    void* FUN_00441cf0(unsigned int flags);
};

// @fnv 0x00441cf0
void* QueuedFileLoad::FUN_00441cf0(unsigned int flags)
{
    FUN_00441d20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00446990 {
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

struct FUN_00446990_StandIn
{
    unsigned int m_iFadeNodeMode[8];
    TESObjectREFR* m_pObject;

    unsigned int GetObjectFlags();
};

// Returns the flags of m_pObject via CallGetFlags, or 0 when m_pObject is null.
// @fnv 0x00446990
unsigned int FUN_00446990_StandIn::GetObjectFlags()
{
    return m_pObject ? reinterpret_cast<TESObjectREFR_GetFlags_Helper*>(m_pObject)->CallGetFlags() : 0;
}
}  // namespace fnv_00446990

namespace fnv_00449ab0 {
struct FUN_00449ea0_cls
{
    void FUN_00449ea0(void);
    void* FUN_00449ab0(unsigned int flags);
};

void _Deallocate(void* p);

// @fnv 0x00449ab0
void* FUN_00449ea0_cls::FUN_00449ab0(unsigned int flags)
{
    FUN_00449ea0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449ab0

void __fastcall FUN_004499a0(int**);
void __cdecl _Deallocate(void*);

struct FUN_00449b70_Class
{
    void* FUN_00449b70(unsigned int flags);
};

// @fnv 0x00449b70
void* FUN_00449b70_Class::FUN_00449b70(unsigned int flags)
{
    FUN_004499a0((int**)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00449d10 {
struct FUN_00449c50
{
    virtual ~FUN_00449c50();
    FUN_00449c50* FUN_00449d10(unsigned int flags);
};

void _Deallocate(void* ptr);

FUN_00449c50::~FUN_00449c50()
{}

// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x00449d10
FUN_00449c50* FUN_00449c50::FUN_00449d10(unsigned int flags)
{
    FUN_00449c50::~FUN_00449c50();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_00449d10

namespace fnv_00449e70 {
struct FUN_00449d60
{
    virtual ~FUN_00449d60();
    void* FUN_00449e70(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449e70
void* FUN_00449d60::FUN_00449e70(unsigned int flags)
{
    this->FUN_00449d60::~FUN_00449d60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449e70

struct FUN_0044adb0_class
{
    unsigned char pad[0x4c];
    unsigned int count;
    ModelLoader** entries;

    void FUN_0044adb0();
};

// @fnv 0x0044adb0
void FUN_0044adb0_class::FUN_0044adb0()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        entries[i]->ProcessQueuedFile();
    }
}

struct FUN_0044b4b0_Class
{
    void FUN_0044b4b0(void);
};

extern void __cdecl _Deallocate(void*);

struct InterfacedClass
{
    void FUN_0044b4b0(void);
    void* FUN_0044b4d0(unsigned int flags);
};

// @fnv 0x0044b4d0
void* InterfacedClass::FUN_0044b4d0(unsigned int flags)
{
    ((FUN_0044b4b0_Class*)this)->FUN_0044b4b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00906320 {
class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock();
};

class QHeadPtr
{
  public:
    ~QHeadPtr();
};

class FUN_009066d0_Class
{
  public:
    bool FUN_009066d0();
};

struct FUN_00906320_Class
{
    unsigned char _padding[0x20];
    RecursiveSpinLock _spinLock;

    FUN_009066d0_Class* FUN_00449f80(int*, QHeadPtr*);
    bool FUN_00906320(int*, QHeadPtr);
};

// Locks the spin lock, calls FUN_009066d0 on the object returned by FUN_00449f80, unlocks, and returns the result.
// @fnv 0x00906320
bool FUN_00906320_Class::FUN_00906320(int* a, QHeadPtr q)
{
    _spinLock.Lock(0);
    bool result = FUN_00449f80(a, &q)->FUN_009066d0();
    _spinLock.Unlock();
    return result;
}
}  // namespace fnv_00906320

struct FUN_009157c0
{
    void Method(void);
};

void _Deallocate(void* p);

struct FUN_00915790
{
    void* DeleteThis(unsigned int flags);
};

// Calls Method on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00915790
void* FUN_00915790::DeleteThis(unsigned int flags)
{
    ((FUN_009157c0*)this)->Method();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00449dc0 {
class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();

  private:
    void* member;
};

unsigned int _BSStringLength(char const*);

struct FUN_00449dc0_Class
{
    char* FUN_00449dc0(char const*);
};

// @fnv 0x00449dc0
char* FUN_00449dc0_Class::FUN_00449dc0(char const* apString)
{
    AutoMemHelper helper(6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h", 0x1d7);

    unsigned int length = _BSStringLength(apString) + 1;
    char* result2 = new char[length];

    TaskQueueInterface::CopyStringToBuffer(result2, length, apString);
    return result2;
}
}  // namespace fnv_00449dc0

namespace fnv_009066d0 {
struct FUN_0044df00Class
{
    int FUN_0044df00();
};

struct FUN_006ecba0_class
{
    int value;
    void* FUN_006ecba0(bool, void*);
};

struct GO : public FUN_006ecba0_class
{
    operator unsigned int();
};

struct FUN_00529000_Class
{
    void FUN_00529000();
};

int __fastcall ClearLowBit(int*);
bool __cdecl FUN_004491c0(void*, int, int);

struct FUN_009066d0_Class : public FUN_00529000_Class
{
    char pad[0x0F];
    void* member10;
    FUN_0044df00Class member14;
    int* member18;

    bool FUN_009066d0(int, int);
    bool FUN_00906820(int, int);
    void FUN_005292a0(int);
};

// @fnv 0x009066d0
bool FUN_009066d0_Class::FUN_009066d0(int arg1, int arg2)
{
    bool result = false;

    while (true)
    {
        if (!FUN_00906820(arg1, arg2))
        {
            result = false;
            break;
        }

        GO go3;
        GO go2;
        GO go1;

        go3.FUN_006ecba0(false, (void*)ClearLowBit((int*)&member18));
        go2.FUN_006ecba0(true, (void*)ClearLowBit((int*)&member18));

        if (!FUN_004491c0((void*)(member14.FUN_0044df00() + 8), go2.operator unsigned int(),
                          go3.operator unsigned int()))
        {
            continue;
        }

        go1.FUN_006ecba0(false, (void*)ClearLowBit((int*)&member14));

        if (FUN_004491c0(member10, go3.operator unsigned int(), go1.operator unsigned int()))
        {
            FUN_005292a0(ClearLowBit((int*)&member14));
        }
        else
        {
            FUN_00906820(arg1, arg2);
        }

        result = true;
        break;
    }

    FUN_00529000();
    return result;
}
}  // namespace fnv_009066d0

class B43D100Object
{
  public:
    virtual ~B43D100Object();
};

class B43D100Owner
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    B43D100Object* m_pPointer;

    void DestroyObject();
};

// Deletes the owned B43D100Object and clears the pointer to null.
// @fnv 0x0043d100
void B43D100Owner::DestroyObject()
{
    delete m_pPointer;
    m_pPointer = 0;
}

// Constructor-like thiscall with 3 stack args: calls a base routine with two
// args, stores the class vtable pointer, stores the third arg at +0x38, returns this.

extern char DAT_0101698c[];

struct FUN_0043bd10_base
{
    void FUN_0043bd10(int a1, int a2);
};

struct FUN_0043d540_cls : FUN_0043bd10_base
{
    void* m_pVTable;
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
    int m_iValue38;

    FUN_0043d540_cls* FUN_0043d540(int a1, int a2, int a3);
};

// Calls the base constructor with a1 and a2, sets the vtable pointer to DAT_0101698c, stores a3 in m_iValue38, and returns this.
// @fnv 0x0043d540
FUN_0043d540_cls* FUN_0043d540_cls::FUN_0043d540(int a1, int a2, int aiValue)
{
    FUN_0043bd10(a1, a2);
    m_pVTable = (void*)DAT_0101698c;
    m_iValue38 = aiValue;
    return this;
}

class Sub_0043d5b0
{
  public:
    unsigned int m_00;
    int Release(unsigned int flags);
};

class Base_0043d5b0
{
  public:
    virtual ~Base_0043d5b0();
};

class FUN_0043d5b0_cls : public Base_0043d5b0
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    Sub_0043d5b0* m_38;
    virtual ~FUN_0043d5b0_cls();
};

// Destructor that releases the Sub_0043d5b0 stored in m_38 with flag 1 if it is non-null.
// @fnv 0x0043d5b0
FUN_0043d5b0_cls::~FUN_0043d5b0_cls()
{
    Sub_0043d5b0* copy;
    Sub_0043d5b0* tmp;
    copy = m_38;
    tmp = copy;
    tmp != 0 ? tmp->Release(1) : 0;
}

class Obj43D730
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void Update();

    void FUN_0043d730();
};

// @fnv 0x0043d730
void Obj43D730::FUN_0043d730()
{
    Update();
}

// Create a temporary object from the owner, run the batch with it described by a stack packet,
// then delete the object.

class D750Object
{
  public:
    virtual ~D750Object();
};

class D750Owner
{
  public:
    D750Object* Create(int iFlags);
    void* GetTarget();
};

struct D750Packet
{
    int m_iFlags;
    D750Object* m_pPointer;
    void* m_pkTarget;
    D750Packet();
};

struct D750Data
{
    D750Owner* m_pkOwnerManager;
    void* m_pvArg1;
    void* m_pvArg2;
    void* m_pvArg3;
    unsigned short m_usElementCount;
    void* m_pvArg5;
    void* m_pvArg6;
};

void __cdecl D750Process(void* pvArg1, void* pvArg2, void* pvArg3, D750Packet* pkPacket, void* pvArg5, void* pvArg6,
                         unsigned int ItemUpdateArray);

class D750Batch
{
  public:
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
    D750Data* m_pUserData;

    void CreateAndProcessObject();
};

// @fnv 0x0043d750
void D750Batch::CreateAndProcessObject()
{
    D750Object* pkObject = m_pUserData->m_pkOwnerManager->Create(1);
    if (pkObject)
    {
        D750Packet kPacket;
        kPacket.m_pkTarget = m_pUserData->m_pkOwnerManager->GetTarget();
        kPacket.m_pPointer = pkObject;
        kPacket.m_iFlags = 0;
        D750Process(m_pUserData->m_pvArg1, m_pUserData->m_pvArg2, m_pUserData->m_pvArg3, &kPacket, m_pUserData->m_pvArg5,
                    m_pUserData->m_pvArg6, m_pUserData->m_usElementCount);
        delete kPacket.m_pPointer;
    }
}

extern int DAT_010169d4;

class FUN_0043d850_cls
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
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
    unsigned int m_48;
    void* m_4c;

    void FUN_0043c890(void* tmp, unsigned int a3, unsigned int a4, int one, int zero);
    FUN_0043d850_cls* FUN_0043d850(unsigned int a1, void* a2, unsigned int a3, unsigned int a4);
};

// @fnv 0x0043d850
FUN_0043d850_cls* FUN_0043d850_cls::FUN_0043d850(unsigned int a1, void* a2, unsigned int auiArg3, unsigned int auiArg4)
{
    FUN_0043c890((a2 != 0) ? (void*)((char*)a2 + 0x30) : 0, auiArg3, auiArg4, 1, 0);
    m_ppVirtualMethodTable = (void*)&DAT_010169d4;
    m_48 = a1;
    m_4c = a2;
    m_18 = 0x1e;
    return this;
}

// UpdateStateAndNotify : save-game state update helper.
//
// The object keeps a pointer to the pending change record at +0x48.
// The method first hands the two arguments to the internal state updater
// and then, once the update counter reaches 4, notifies the global
// listener (DAT_011d5c48) about the pending record.

class SaveGameChange;  // opaque record type

class SaveGameListener
{
  public:
    void Notify(SaveGameChange* pChange);
};

// Global listener instance (defined elsewhere in the game).
extern SaveGameListener* DAT_011d5c48;

struct FUN_0043dac0_cls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    SaveGameChange* m_48;

    void UpdateState(int aIndex, int aFlags);

    void UpdateStateAndNotify(int aIndex, int aFlags);
};

// Calls UpdateState with aIndex and aFlags, then notifies DAT_011d5c48 with m_48 when aIndex is at least 4.
// @fnv 0x0043dac0
void FUN_0043dac0_cls::UpdateStateAndNotify(int aIndex, int aFlags)
{
    UpdateState(aIndex, aFlags);

    if (aIndex >= 4)
    {
        DAT_011d5c48->Notify(m_48);
    }
}

class B43E8B0Base
{
  public:
    B43E8B0Base(int iArg1, int iArg2);
    virtual ~B43E8B0Base();

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
};

class FUN_0043e8b0_cls : public B43E8B0Base
{
  public:
    FUN_0043e8b0_cls(int iArg1, int iArg2, int iValue38, int iValue3C);
    virtual ~FUN_0043e8b0_cls();

    int m_iValue38;
    int m_iValue3C;
};

// Base constructor runs with iArg1 and iArg2, then stores iValue38 and iValue3C into m_iValue38 and m_iValue3C.
// @fnv 0x0043e8b0
FUN_0043e8b0_cls::FUN_0043e8b0_cls(int iArg1, int iArg2, int iValue38, int iValue3C) : B43E8B0Base(iArg1, iArg2)
{
    m_iValue38 = iValue38;
    m_iValue3C = iValue3C;
}

struct SaveLoadBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    SaveLoadBase(unsigned int flags);
    virtual ~SaveLoadBase();
};

struct SaveLoadTarget
{
    unsigned int Compute();
};

struct SaveLoadElemA
{
    int unk00;

    SaveLoadElemA();
    ~SaveLoadElemA();
};

struct SaveLoadElemB
{
    int unk00;

    SaveLoadElemB();
    ~SaveLoadElemB();
};

class FUN_0043ef10 : public SaveLoadBase
{
  public:
    SaveLoadTarget* m_pFlagTarget;
    SaveLoadElemA m_arrA[20];
    SaveLoadElemB m_arrB[20];
    SaveLoadElemB m_arrC[20];
    unsigned int m_11c;
    unsigned char m_120;

    FUN_0043ef10(SaveLoadTarget* target, unsigned int flags, unsigned int unused);
    virtual ~FUN_0043ef10();
};

// Initializes the base with flags, stores the target pointer, clears m_120, and sets m_11c to the target's Compute() result.
// @fnv 0x0043ef10
FUN_0043ef10::FUN_0043ef10(SaveLoadTarget* target, unsigned int flags, unsigned int unused)
    : SaveLoadBase(flags), m_pFlagTarget(target)
{
    m_120 = 0;
    m_11c = m_pFlagTarget->Compute();
}

struct SpawnedCallee
{
    void FUN_00528cb0(void* pObject);
};

struct FUN_0043f060_cls : public SpawnedCallee
{
    void FUN_0043f060();
};

// @fnv 0x0043f060
void FUN_0043f060_cls::FUN_0043f060()
{
    FUN_00528cb0(0);
}

class FUN_0043f220_cls
{
  public:
    int unk00;
    void* GetEntryAt(int a1);
};

// @fnv 0x0043f220
void* FUN_0043f220_cls::GetEntryAt(int aiIndex)
{
    return (char*)this + aiIndex * 16 + 0x2c;
}

namespace fnv_0043fb10 {
struct VirtObj0043fb50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct Standin0043fb50
{
    char _pad[0x18];
    VirtObj0043fb50* m_18;
    void DispatchToVirtual(int);
};

struct Host0043fb10
{
    char _pad[0x11c];
    Standin0043fb50* m_11c;
    void FUN_00c3cb70(int, int);
    void CallWithArgsAndForwardMember(int a, int b);
};

extern Standin0043fb50* g_11c3b3c;

// Calls FUN_00c3cb70 with a and b, then calls DispatchToVirtual on g_11c3b3c passing m_11c.
// @fnv 0x0043fb10
void Host0043fb10::CallWithArgsAndForwardMember(int aiArg1, int aiArg2)
{
    FUN_00c3cb70(aiArg1, aiArg2);
    g_11c3b3c->DispatchToVirtual((int)m_11c);
}
}  // namespace fnv_0043fb10

struct SpawnedBase
{
    virtual ~SpawnedBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    SpawnedBase(int a1);
};

struct SubObjA
{
    int unk00;
    SubObjA(int v);
    ~SubObjA();
};

struct SubObjB
{
    int unk00;
    SubObjB(int v);
    ~SubObjB();
};

struct FUN_0043fd40 : SpawnedBase
{
    int m_28;
    SubObjA m_2c;
    SubObjB m_30;
    SubObjB m_34;
    SubObjA m_38;

    FUN_0043fd40(int a1, int a2);
    virtual ~FUN_0043fd40();
};

// Constructs a SpawnedBase-derived object, storing a1 in m_28 and initializing the four sub-objects to 0.
// @fnv 0x0043fd40
FUN_0043fd40::FUN_0043fd40(int a1, int a2) : SpawnedBase(a2), m_28(a1), m_2c(0), m_30(0), m_34(0), m_38(0)
{}

class Base_b4619
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    ~Base_b4619();
};

class Sub4_b4619
{
  public:
    unsigned int m_00;
    ~Sub4_b4619();
};

class SubB_b4619
{
  public:
    unsigned int m_00;
    ~SubB_b4619();
};

class SubC_b4619
{
  public:
    unsigned int m_00;
    ~SubC_b4619();
};

class FUN_0043fe40_cls : public Base_b4619
{
  public:
    Sub4_b4619 m_2c;
    SubB_b4619 m_30;
    SubC_b4619 m_34;
    Sub4_b4619 m_38;
    ~FUN_0043fe40_cls();
};

// Destructor for FUN_0043fe40_cls; destroys its Base_b4619 base and the Sub4_b4619, SubB_b4619 and SubC_b4619 members.
// @fnv 0x0043fe40
FUN_0043fe40_cls::~FUN_0043fe40_cls()
{}

struct NiObjectStub;
struct NiNodeStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int IsVisible();
    void FUN_00b4dec0(int);
};
struct NiObjectStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNodeStub* IsSceneNode();
    NiObjectStub* Clone();
};
struct MdlStub
{
    NiObjectStub* GetObject3D();
};
template <class T> struct NiPtr
{
    T* m_pObject;
    NiPtr(T* p);
    ~NiPtr();
    operator T*() const;
    T* operator->() const;
};
struct ModelLoaderStub
{
    bool FUN_004472a0(char*, NiPtr<MdlStub>&);
};

struct ModelSourceStub
{
    const char* GetModelFilePath();
};
void __cdecl FUN_00489190(char*, const char*);

struct AttachTaskStub
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
    virtual void Attach(NiNodeStub*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    ModelSourceStub* pSource;
    void AttachModelFromSource();
};

// @fnv 0x00440190
void AttachTaskStub::AttachModelFromSource()
{
    NiNodeStub* pNode = 0;
    char acPath[264];
    FUN_00489190(acPath, pSource->GetModelFilePath());
    NiPtr<MdlStub> spLoaded(0);
    ((ModelLoaderStub*)g_modelLoader)->FUN_004472a0(acPath, spLoaded);
    if (spLoaded && spLoaded->GetObject3D())
    {
        NiObjectStub* pClonedObject = spLoaded->GetObject3D()->Clone();
        if (pClonedObject)
        {
            pNode = pClonedObject->IsSceneNode();
            if (!pNode)
            {
                (NiPtr<NiObjectStub>(pClonedObject));
            }
            else if (pNode->IsVisible())
            {
                pNode->FUN_00b4dec0(6);
            }
        }
    }
    if (pNode)
    {
        Attach(pNode);
    }
}

enum B4404C0Priority
{
    B4404C0_PRIORITY_CRITICAL = 0
};

class B4404C0Task
{
  public:
    B4404C0Task(B4404C0Priority ePriority);
    virtual ~B4404C0Task();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct B4404C0Handle
{
    int m_iValue;

    void Set(int iValue);
};

class FUN_004404c0 : public B4404C0Task
{
  public:
    void* m_pvTarget;
    B4404C0Handle m_kHandle;

    FUN_004404c0(void* pvTarget, int iHandle);
    virtual ~FUN_004404c0();
};

// Constructs a critical-priority task storing the target pointer and setting the handle to the given value.
// @fnv 0x004404c0
FUN_004404c0::FUN_004404c0(void* pvTarget, int iHandle) : B4404C0Task(B4404C0_PRIORITY_CRITICAL)
{
    m_pvTarget = pvTarget;
    m_kHandle.Set(iHandle);
}

struct PriorityKey
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned __int64 key;
    void __thiscall FUN_004405d0(unsigned char priority);
};

// Replaces the priority byte stored in bits 16-23 of key, preserving all other bits.
// @fnv 0x004405d0
void PriorityKey::FUN_004405d0(unsigned char priority)
{
    key = (key & 0xffffffffff00ffffui64) + ((__int64)priority << 16);
}

class SaveBase_b3799
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    ~SaveBase_b3799();
};

class SaveSub_b3799
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ~SaveSub_b3799();
};

class FUN_004406b0 : public SaveBase_b3799
{
  public:
    SaveSub_b3799 m_1c;
    ~FUN_004406b0();
};

// @fnv 0x004406b0
FUN_004406b0::~FUN_004406b0()
{}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

class B40DC0Base
{
  public:
    const char* GetTypeName();
};

class B40DC0Ref
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual const char* GetEditorID();

    unsigned int GetFormID();
    B40DC0Base* GetBaseObject();
};

class B40DC0Task
{
  public:
    bool IsComplete();
    bool FormatQueuedRefDescription(char* pcBuffer, unsigned int uiSize);

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
    B40DC0Ref* m_pkRef;
};

// If the task is not complete, formats the queued ref's editor ID, form ID and base object type name into pcBuffer and returns true; otherwise returns false.
// @fnv 0x00440dc0
bool B40DC0Task::FormatQueuedRefDescription(char* pcBuffer, unsigned int uiSize)
{
    if (IsComplete())
        return false;
    _sprintf_s(pcBuffer, uiSize, "Queued ref '%s' (%08X) of type %s", m_pkRef->GetEditorID(), m_pkRef->GetFormID(),
               m_pkRef->GetBaseObject()->GetTypeName());
    return true;
}

struct Node1;
struct Node2;
struct Node3;
struct Node4;
struct Node5;
struct Node0
{
    Node1* FUN_007af430();
};
struct Node1
{
    Node2* CreateBillboardSceneObject(int);
};
struct Node2
{
    Node3* FUN_0043b4a0(int);
};
struct Node3
{
    Node4* FUN_005495f0();
    Node5* FUN_00a59d30(int);
};
struct Node4
{
    void FUN_00a67050(int);
    void SetByteAtOffset38(int);
    void FUN_004410f0(int);
};
struct Node5
{
    int FUN_00441110();
    void FUN_00441130(int, int);
};
void __cdecl FUN_00b57e30(Node3*, int, int);
struct Owner
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34(Node2*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Node0* unk28;
    void FUN_00440fd0();
};
// @fnv 0x00440fd0
void Owner::FUN_00440fd0()
{
    Node1* node1 = unk28->FUN_007af430();
    Node2* node2 = node1->CreateBillboardSceneObject(0);
    if (node2)
    {
        Node3* node3 = node2->FUN_0043b4a0(0);
        Node4* status = node3->FUN_005495f0();
        status->FUN_00a67050(0x4000);
        status->SetByteAtOffset38(0x11);
        status->FUN_004410f0(1);
        FUN_00b57e30(node3, 0, 0);
        Node5* action = (node3->FUN_00a59d30(3) == 0 ? false : node3->FUN_00a59d30(3)->FUN_00441110() == 0xb)
                            ? node3->FUN_00a59d30(3)
                            : 0;
        if (action)
        {
            action->FUN_00441130(13, 1);
            action->FUN_00441130(22, 1);
        }
        vfn_34(node2);
    }
}

namespace fnv_004420b0 {
struct SpawnedBase
{
    virtual ~SpawnedBase();
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

    SpawnedBase(int a1, int a2);
};

struct SubObjA
{
    int unk00;
    SubObjA(int v);
    ~SubObjA();
};

struct SubObjB
{
    int unk00;
    SubObjB(int v);
    ~SubObjB();
};

struct FUN_004420b0 : SpawnedBase
{
    SubObjA m_kPointA;
    SubObjB m_kPointB;

    FUN_004420b0(int a1, int a2);
    virtual ~FUN_004420b0();
};

// @fnv 0x004420b0
FUN_004420b0::FUN_004420b0(int a1, int a2) : SpawnedBase(a1, a2), m_kPointA(0), m_kPointB(0)
{}
}  // namespace fnv_004420b0

class C4422C0Object
{
  public:
    virtual ~C4422C0Object();
};

class C4422C0Base
{
  public:
    virtual ~C4422C0Base();

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
};

class FUN_004422c0 : public C4422C0Base
{
  public:
    virtual ~FUN_004422c0();

    C4422C0Object* m_pPointer;
};

// @fnv 0x004422c0
FUN_004422c0::~FUN_004422c0()
{
    delete m_pPointer;
}

struct FUN_00444540_Scope
{
    unsigned int m_00;
    FUN_00444540_Scope(int mode);
    ~FUN_00444540_Scope();
};

class FUN_00444540_cls
{
  public:
    unsigned int m_00;
    void DispatchWithScope(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
    void Dispatch(unsigned int a, unsigned int b, FUN_00444540_Scope& scope, unsigned int c, unsigned int d,
                  unsigned int e);
};

// Creates a scope object with mode 0 and forwards all arguments to Dispatch.
// @fnv 0x00444540
void FUN_00444540_cls::DispatchWithScope(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e)
{
    FUN_00444540_Scope scope(0);
    Dispatch(a, b, scope, c, d, e);
}

struct S_004445c0_Obj
{
    S_004445c0_Obj(int a, int b, int c, int d);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    void FUN_00443aa0(int a);
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
};
struct S_004445c0_Ptr
{
    S_004445c0_Obj* m_pObject;
    S_004445c0_Ptr(S_004445c0_Obj* p);
    ~S_004445c0_Ptr();
    S_004445c0_Obj* operator->() const;
};
struct S_004445c0_Dest
{
    S_004445c0_Ptr& FUN_0092c820(const S_004445c0_Ptr& p);
};
struct S_004445c0_This
{
    void FUN_004445c0(int a1, int a2, S_004445c0_Dest* a3, int a4, int a5, int a6);
};
// Allocates an object from the given arguments, calls FUN_00443aa0 and v8 on it, then passes it to FUN_0092c820 on the destination.
// @fnv 0x004445c0
void S_004445c0_This::FUN_004445c0(int aiArg1, int aiArg2, S_004445c0_Dest* pDest, int aiArg4, int aiArg5, int aiArg6)
{
    S_004445c0_Ptr sp(new S_004445c0_Obj(aiArg1, aiArg2, aiArg4, aiArg6));
    sp->FUN_00443aa0(aiArg5);
    sp->v8();
    pDest->FUN_0092c820(sp);
}

struct MemCtx
{
    int m;
    MemCtx(int a, int b, const char* file, int line);
    ~MemCtx();
};
struct Obj3D
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void SetX(int);  // 0x1c
    virtual void Y();        // 0x20
    int FUN_0043cc60();
};
struct RefPtr
{
    void* m;
    RefPtr(void*);
    ~RefPtr();
    Obj3D* FUN_00559450();
    void FUN_006f74f0(void*);
};
struct Base3D
{
    int FUN_00401170();
};
struct Proc
{
    void InitScriptRunLockForObject();
    void FUN_00444ce0();
};
struct Ref
{
    char pad[0x224];
    bool FUN_00444d00(int);
    Base3D* FUN_007af430();
    Proc* FUN_008d6f30();
    bool FUN_00572350();
};
struct RefV
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w80();
    virtual void w81();
    virtual void w82();
    virtual void w83();
    virtual void w84();
    virtual void w85();
    virtual void w86();
    virtual void w87();
    virtual void w88();
    virtual void w89();
    virtual void w90();
    virtual void w91();
    virtual void w92();
    virtual void w93();
    virtual void w94();
    virtual void w95();
    virtual void w96();
    virtual void w97();
    virtual void w98();
    virtual void w99();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual bool IsX();
};
struct Queue
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(Ref*, RefPtr*);  // 0x8
    virtual void v3();
    virtual bool Add(Ref*, RefPtr*, bool);  // 0x10
};
struct Mgr
{
    bool FUN_0042ce10();
    bool FUN_00444d20();
};
struct G1
{
    int FUN_0044edb0();
};
struct TaskA
{
    char d[72];
    TaskA(int);
    void* operator new(unsigned int);
};
struct TaskB
{
    char d[64];
    TaskB(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskC
{
    char d[72];
    TaskC(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskD
{
    char d[64];
    TaskD(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskE
{
    char d[64];
    TaskE(Ref*, int);
    void* operator new(unsigned int);
};

int FUN_0040fc90();
bool FUN_00702360();
extern Mgr* DAT_011ddf38;
extern Ref* DAT_011dea3c;
extern G1* DAT_011dea0c;

struct ML
{
    int unk0, unk4;
    Queue* q8;
    Queue* qc;
    void QueueReference(Ref* ref, int a2, bool a3);
};

// Checks manager and ref state, updates or creates a queued load task for ref, then adds it to q8 and optionally qc.
// @fnv 0x00444850
void ML::QueueReference(Ref* ref, int aiValue, bool a3)
{
    if (DAT_011ddf38->FUN_0042ce10() && !DAT_011ddf38->FUN_00444d20())
        return;
    if (ref->FUN_007af430()->FUN_00401170() == 0xd)
        return;
    if (((RefV*)ref)->IsX())
    {
        Ref* r = ref;
        if (r->FUN_00444d00(2))
            return;
    }
    RefPtr p(0);
    if (q8->Lookup(ref, &p))
    {
        int v = p.FUN_00559450()->FUN_0043cc60();
        if (v != aiValue)
            p.FUN_00559450()->SetX(aiValue);
        return;
    }
    MemCtx memCtx(0x31, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc4e);
    if (ref == DAT_011dea3c)
    {
        MemCtx c2(0x34, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc53);
        p.FUN_006f74f0(new TaskA(aiValue));
    }
    else
    {
        switch (ref->FUN_007af430()->FUN_00401170())
        {
        case 0x25: {
            p.FUN_006f74f0(new TaskB(ref, aiValue));
            break;
        }
        case 0x2a: {
            MemCtx memCtx3(0x32, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc6b);
            p.FUN_006f74f0(new TaskC(ref, aiValue));
            break;
        }
        case 0x2b: {
            MemCtx memCtx4(0x32, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc72);
            p.FUN_006f74f0(new TaskD(ref, aiValue));
            break;
        }
        default: {
            p.FUN_006f74f0(new TaskE(ref, aiValue));
            break;
        }
        }
    }
    if (q8->Add(ref, &p, false))
    {
        bool b = false;
        if (a3 && FUN_0040fc90() == DAT_011dea0c->FUN_0044edb0() && !FUN_00702360())
            b = true;
        if (b)
            qc->Add(ref, &p, true);
        else
            p.FUN_00559450()->Y();
        if (ref->FUN_008d6f30())
        {
            ref->FUN_008d6f30()->InitScriptRunLockForObject();
            if (ref->FUN_00572350())
                ref->FUN_008d6f30()->FUN_00444ce0();
        }
    }
    else
    {
        p.FUN_006f74f0(0);
    }
}

namespace fnv_00445370 {
class TargetObj
{
  public:
    virtual void v00();
    virtual void v04();
    virtual bool v08(unsigned int a, TargetObj** out);
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int a);
    void FinishScriptRunLockIfActive();
    bool FUN_0042ce10();
    int FUN_004431b0();
    int FUN_00443240(int a);
};

extern TargetObj* DAT_011ddf38;

class FUN_00445370_cls
{
  public:
    void* m_00;
    TargetObj* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    unsigned char m_2c;
    void FUN_00445370(unsigned int a1, bool flag);
};

// @fnv 0x00445370
void FUN_00445370_cls::FUN_00445370(unsigned int a1, bool flag)
{
    TargetObj* p = 0;
    if (this->m_04->v08(a1, &p))
    {
        p->FinishScriptRunLockIfActive();
        if (DAT_011ddf38 != 0 && DAT_011ddf38->FUN_0042ce10())
        {
            flag = false;
            this->m_2c = 1;
        }
        if (flag)
        {
            if (p->FUN_004431b0() == 0)
            {
                this->m_04->v14(a1);
                TargetObj* a = p;
                TargetObj* aQ = a;
                (aQ != 0) ? aQ->FUN_00443240(1) : 0;
            }
        }
    }
}
}  // namespace fnv_00445370

struct AC_0042f730;
extern IOManager* DAT_01202d98;

class SaveTmp_b9539
{
  public:
    AC_0042f730* m_pObject;
    SaveTmp_b9539(AC_0042f730* pObject);
    ~SaveTmp_b9539();
    int Get(int n);
};

struct IOCall_b9539
{
    void FUN_0044ac40(int v);
};

class SaveCaller_b9539
{
  public:
    virtual void v0();
    virtual void v1();
    virtual bool v2(int a, SaveTmp_b9539* pTmp);
};

class SaveOwner_b9539
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    SaveCaller_b9539* m_10;
    void FUN_004454d0(int a);
};

// @fnv 0x004454d0
void SaveOwner_b9539::FUN_004454d0(int a)
{
    SaveTmp_b9539 tmp(0);
    if (this->m_10->v2(a, &tmp))
    {
        reinterpret_cast<IOCall_b9539*>(DAT_01202d98)->FUN_0044ac40(tmp.Get(0));
    }
}

class B445670Cell;

class B445670Ref
{
  public:
    B445670Cell* GetParentCell();
};

class B445670Cell
{
  public:
    void* GetLoadedData();
};

class B445670Iterator
{
  public:
    B445670Iterator();
    ~B445670Iterator();
    bool IsDone();

    int m_iIndex;
    int m_iArrayLength;
    int m_iBucket;
    void* m_pvCurrent;
};

class B445670Handle
{
  public:
    B445670Handle(void* pvObject);
    ~B445670Handle();

    void* m_pvObject;
};

class B445670Table
{
  public:
    bool AdvanceRequest(B445670Iterator* pkIter, B445670Ref** ppkRef, B445670Handle* pkHandle, int iFlag);
};

class B445670Loader
{
  public:
    void FUN_00445570(B445670Ref* pkRef);
    void FUN_00445670(B445670Cell* pkCell);

    int unk00;
    int unk04;
    B445670Table* m_pkTable;
};

// Iterates the table and calls FUN_00445570 on each ref whose parent cell is pkCell, after checking the cell has loaded data.
// @fnv 0x00445670
void B445670Loader::FUN_00445670(B445670Cell* pkCell)
{
    if (!pkCell || !pkCell->GetLoadedData())
        return;

    B445670Iterator kIter;
    while (!kIter.IsDone())
    {
        B445670Ref* pkRef = 0;
        B445670Handle kHandle2(0);
        if (m_pkTable->AdvanceRequest(&kIter, &pkRef, &kHandle2, 1))
        {
            if (pkRef->GetParentCell() == pkCell)
                FUN_00445570(pkRef);
        }
    }
}

int FUN_00406d30(char* dst, unsigned int size, const char* src);
char* FUN_0040ab30(char* str, int ch);

struct CreatureData114
{
    int FUN_00717e50();
    int GetOffsetC();
};

class TESCreature : public TESModel
{
  public:
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
    int unk110;
    CreatureData114 data114;
};

struct ItemEntry
{
    ~ItemEntry();
    int FUN_0044ddc0(int a, int b, void* ref);
    int unk00;
};

struct InventoryChanges
{
    static InventoryChanges* GetOrAddInventoryChanges(void* ref);
    ItemEntry* SelectBestWeapon(TESCreature* form, int* count, int type, int flag);
    ItemEntry* FindBestAmmoChange(TESCreature* form, int flag);
};

struct ModelLoaderHelper445
{
    void QueueKFPathsFromList(int a, int b, int c, int d, char* path);
    void FUN_00444d40(int v);
    void FUN_004457d0(TESModel* model, int a, int b, void* ref);
};

// @fnv 0x004457d0
void ModelLoaderHelper445::FUN_004457d0(TESModel* model, int aiArg1, int aiArg2, void* ref)
{
    TESCreature* creature = dynamic_cast<TESCreature*>(model);
    char path[0x104];
    if (creature)
    {
        int node = creature->data114.FUN_00717e50();
        FUN_00406d30(path, 0x104, model->GetModelPath());
        char* slash = FUN_0040ab30(path, '\\');
        if (slash)
        {
            slash[1] = 0;
        }
        QueueKFPathsFromList(node, creature->data114.GetOffsetC(), aiArg1, aiArg2, path);
        if (ref)
        {
            InventoryChanges* changes = InventoryChanges::GetOrAddInventoryChanges(ref);
            int count;
            ItemEntry* entry = changes->SelectBestWeapon(creature, &count, 6, 0);
            if (entry)
            {
                FUN_00444d40(entry->FUN_0044ddc0(aiArg1, aiArg2, ref));
                delete entry;
            }
            entry = changes->FindBestAmmoChange(creature, 0);
            if (entry)
            {
                FUN_00444d40(entry->FUN_0044ddc0(aiArg1, aiArg2, ref));
                delete entry;
            }
        }
    }
}

int strcpy_s(char* dst, unsigned int size, const char* src);
int strcat_s(char* dst, unsigned int size, const char* src);

struct KFQueueOwner
{
    void* MakeTask(int index);
};

struct ModelLoaderKFList : public ModelLoader
{
    void QueueKFPath(const char* path, void* task, int priority, void* queued, int a, int b, int c, int d);
    void QueueKFPathDirect(const char* path, int priority, void* queued, int a, bool b, bool c, bool d);
    void QueueKFPathsFromList(BSSimpleList<const char*>* list, KFQueueOwner* owner, int priority, void* queued,
                              const char* prefix);
};

// Walks a list of names, optionally prefixes each into a path buffer, and queues each KF path either via owner tasks or directly.
// @fnv 0x004463b0
void ModelLoaderKFList::QueueKFPathsFromList(BSSimpleList<const char*>* apNames, KFQueueOwner* owner, int priority,
                                             void* queued, const char* prefix)
{
    BSSimpleList<const char*>* iter = apNames;
    int index = 0;
    while (iter)
    {
        const char* name = iter->GetItem();
        if (name)
        {
            char path[260];
            if (prefix)
            {
                strcpy_s(path, 260, prefix);
                strcat_s(path, 260, name);
                name = path;
            }
            if (owner)
            {
                QueueKFPath(name, owner->MakeTask(index), priority, queued, 0, 1, 0, 0);
            }
            else
            {
                QueueKFPathDirect(name, priority, queued, 0, 1, 0, 0);
            }
        }
        index++;
        iter = iter->GetNext();
    }
}

struct IndexedValueTable
{
    unsigned int count;
    unsigned int* values;
    unsigned int GetValueAt(unsigned int index);
};

// Returns values[index] when index is below count, otherwise returns 0.
// @fnv 0x004464c0
unsigned int IndexedValueTable::GetValueAt(unsigned int index)
{
    return index < count ? values[index] : 0;
}

class FUN_004469c0_base
{
  public:
    FUN_004469c0_base(unsigned int);
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    unsigned int unk04[9];
};

class FUN_004469c0 : public FUN_004469c0_base
{
  public:
    FUN_004469c0(unsigned int a, unsigned int b);
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
};

// Constructs the object, forwarding b to the base constructor and initializing m_28 with a while zeroing m_2c and m_30.
// @fnv 0x004469c0
FUN_004469c0::FUN_004469c0(unsigned int auiValue, unsigned int auiBaseArg) : FUN_004469c0_base(auiBaseArg)
{
    m_28 = auiValue;
    m_2c = 0;
    m_30 = 0;
}

class FUN_00448330_Target
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual unsigned char vfn_10(unsigned int a1, unsigned int* pa2, bool flag);
};

class FUN_00448330_cls
{
  public:
    unsigned int unk00[9];
    FUN_00448330_Target* m_pFlagTarget;
    unsigned char DispatchVirtualCall(unsigned int a1, unsigned int a2);
};

// @fnv 0x00448330
unsigned char FUN_00448330_cls::DispatchVirtualCall(unsigned int auiArg, unsigned int a2)
{
    unsigned char r = m_pFlagTarget->vfn_10(auiArg, &a2, false);
    return r;
}

class FUN_004483a0_holder
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool vfn_08(unsigned int arg, unsigned int* out);
};

class FUN_004483a0_cls
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
    FUN_004483a0_holder* m_pHolder;
    unsigned int GetHolderValue(unsigned int arg);
};

// Calls m_pHolder->vfn_08 with arg and an output slot, returning the output value if it succeeds, otherwise 0.
// @fnv 0x004483a0
unsigned int FUN_004483a0_cls::GetHolderValue(unsigned int arg)
{
    unsigned int out = 0;
    if (m_pHolder->vfn_08(arg, &out))
    {
        return out;
    }
    return 0;
}

struct B449Entry
{
    bool InvokeWithArgs();
};

class B449Map
{
  public:
    B449Entry* FUN_00449f80(void* pKey, int iIndex);
    bool FUN_004498b0(void* pKey, int iIndex);
};

// Looks up the entry for pKey and iIndex and returns the result of its InvokeWithArgs check.
// @fnv 0x004498b0
bool B449Map::FUN_004498b0(void* pKey, int iIndex)
{
    bool bResult = FUN_00449f80(pKey, iIndex)->InvokeWithArgs();
    return bResult;
}

void FUN_0044ada0(unsigned char value);
void __cdecl FUN_0040fca0(unsigned long);

struct QueuedTask
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Run(int eState, int arg);
    int unk04;
    int unk08;
    int eState;
    bool SetState(int eCurrentState, int eNewState);
    void FUN_0092c870();
    void FUN_0044dd60();
};

struct TaskProcessor
{
    void FUN_0044e050(void* pTask);
    void FUN_0044ac40(QueuedTask* pTask, int arg);
};

// @fnv 0x0044ac40
void TaskProcessor::FUN_0044ac40(QueuedTask* pTask, int arg)
{
    FUN_0044ada0(0);
    while (true)
    {
        int eState = pTask->eState;
        switch (eState)
        {
        case 0:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, arg);
                return;
            }
            break;
        case 1:
            if (pTask->SetState(eState, 6))
            {
                pTask->FUN_0092c870();
                FUN_0044e050(pTask);
                pTask->Run(eState, arg);
                pTask->FUN_0044dd60();
                return;
            }
            break;
        case 2:
            while (pTask->eState == 3)
            {
                FUN_0040fca0(0);
            }
            break;
        case 3:
            while (pTask->eState == 3)
            {
                FUN_0040fca0(0);
            }
            break;
        case 4:
            while (pTask->eState == 4)
            {
                FUN_0040fca0(0);
            }
            break;
        case 5:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, arg);
                return;
            }
            break;
            return;
        default:
            return;
        }
    }
}

struct Entry44
{
    int unk00;
    int unk04;
    long unk08;
};

struct Slot44
{
    int m_val;
    int GetHead();
    Entry44* GetEntry();
};

struct TP44
{
    int m_p;
    TP44(bool b, int p);
    operator long() const;
};

bool __cdecl FUN_004491c0(long volatile* param_1, long param_2, long param_3);

struct Obj44
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    long volatile* unk10;
    Slot44 unk14;
    Slot44 unk18;
    bool TryInsert(int a, int b);
    void Finish(int p);
    void Release();
    bool TryInsertAndFinish(int a, int b);
};

// Loops calling TryInsert, compares entries via FUN_004491c0, calls Finish or TryInsert again, then Release and returns whether it succeeded.
// @fnv 0x0044d3f0
bool Obj44::TryInsertAndFinish(int aiFirst, int aiSecond)
{
    bool result2 = false;
    while (1)
    {
        if (!TryInsert(aiFirst, aiSecond))
        {
            result2 = false;
            break;
        }
        TP44 first2(false, unk18.GetHead());
        TP44 second(true, unk18.GetHead());
        if (!FUN_004491c0(&unk14.GetEntry()->unk08, second, first2))
            continue;
        TP44 third(false, unk14.GetHead());
        if (FUN_004491c0(unk10, first2, third))
            Finish(unk14.GetHead());
        else
            TryInsert(aiFirst, aiSecond);
        result2 = true;
        break;
    }
    Release();
    return result2;
}

class FUN_0044df40_PtrHolder
{
  public:
    unsigned int m_00;
    FUN_0044df40_PtrHolder(unsigned int init);
    ~FUN_0044df40_PtrHolder();
    void Assign(const void* p);
};

class FUN_0044df40_Plain
{
  public:
    FUN_0044df40_Plain();
};

class FUN_0044df40_cls
{
  public:
    unsigned int m_00;
    FUN_0044df40_PtrHolder m_04;
    FUN_0044df40_Plain m_08;
    FUN_0044df40_cls(unsigned int a1, const void* a2);
};

// @fnv 0x0044df40
FUN_0044df40_cls::FUN_0044df40_cls(unsigned int uiValue, const void* pPointer) : m_04(0), m_08()
{
    m_00 = uiValue;
    m_04.Assign(pPointer);
}

class LoaderNode;
class LoaderEntryA;
class LoaderEntryB;

extern unsigned char DAT_011f36bc;
extern unsigned char DAT_011f36e4;

void* __cdecl FUN_00653270(void* key, LoaderNode* node);

class LoaderEntryA
{
  public:
    void Method(unsigned int flags);
};

class LoaderEntryB
{
  public:
    void Method(unsigned int flags);
};

class LoaderNode
{
  public:
    LoaderNode* Next();
};

class FUN_004f05c0_cls
{
  public:
    LoaderNode* First();
    void ApplyFlagsToEntries(unsigned int flags);
};

// Iterates the node list from First(), looks up two entries per node via FUN_00653270 and calls Method(flags) on each non-null entry.
// @fnv 0x004f05c0
void FUN_004f05c0_cls::ApplyFlagsToEntries(unsigned int flags)
{
    for (LoaderNode* node = First(); node != 0; node = node->Next())
    {
        LoaderEntryA* a = (LoaderEntryA*)FUN_00653270(&DAT_011f36bc, node);
        LoaderEntryB* b = (LoaderEntryB*)FUN_00653270(&DAT_011f36e4, node);
        if (a != 0)
        {
            a->Method(flags);
        }
        if (b != 0)
        {
            b->Method(flags);
        }
    }
}

class QueueCursor
{
  public:
    QueueCursor();
    ~QueueCursor();
    bool AtEnd();
    void* m_pCurrent;
};

class QueueSlot
{
  public:
    QueueSlot(int flag);
    ~QueueSlot();
    void* Take(int which);
    void* m_pInventoryEntryData;
};

class QueueSubmitter
{
  public:
    void Submit(void* item);
};

class FUN_00527fc0_cls
{
  public:
    bool Step(QueueCursor* cursor, int* index, QueueSlot* slot, int mode);
    void SubmitQueuedItems();
};

// Iterates the cursor until it reaches the end, calling Step on each slot and submitting the taken item through the submitter at DAT_01202d98 when Step succeeds.
// @fnv 0x00527fc0
void FUN_00527fc0_cls::SubmitQueuedItems()
{
    unsigned int pad[3];
    {
        QueueCursor cursor;
        while (!cursor.AtEnd())
        {
            int index = 0;
            QueueSlot slot7(0);
            if (this->Step(&cursor, &index, &slot7, 1))
            {
                reinterpret_cast<QueueSubmitter*>(DAT_01202d98)->Submit(slot7.Take(0));
            }
        }
    }
}

class AC_00528080_obj;

unsigned int __cdecl PackShortPair(unsigned short, unsigned short);

class SaveLoadCallLocal
{
  public:
    AC_00528080_obj* m_pObject;
    SaveLoadCallLocal(AC_00528080_obj* pObject);
    ~SaveLoadCallLocal();
};

class SaveLoadCallerShell
{
  public:
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int handle, SaveLoadCallLocal* pLocal);
    bool CallSaveLoadWithHandle(unsigned short a, unsigned short b);
};

// Computes a handle from two 16-bit values, wraps a null object in a local, and passes both to the virtual v2 call.
// @fnv 0x00528080
bool SaveLoadCallerShell::CallSaveLoadWithHandle(unsigned short ausValue1, unsigned short ausValue2)
{
    unsigned int handle = PackShortPair(ausValue1, ausValue2);
    SaveLoadCallLocal local(0);
    return this->v2(handle, &local);
}

class FUN_00529000_cls
{
  public:
    void* unk00;
    unsigned int* m_04;
    unsigned int* m_08;
    unsigned int* m_0C;
    void FUN_00529000();
};

// Sets the three unsigned int values pointed to by m_04, m_08 and m_0C to zero.
// @fnv 0x00529000
void FUN_00529000_cls::FUN_00529000()
{
    *m_04 = 0;
    *m_08 = 0;
    *m_0C = 0;
}

struct Z_00626c50
{
    void FUN_0043b4f0();
};

struct Y_00626c50
{
    void FUN_00626cb0();
};

struct Mgr_00626c50
{
    unsigned int unk00;
    unsigned int unk04;
    void* FUN_00559450(unsigned int key);
};

struct Local_00626c50
{
    unsigned int v;
    void FUN_0059ce80(unsigned int a);
};

struct FUN_00626c50_cls
{
    unsigned int unk000;
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
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    Mgr_00626c50 m_3a0;
    unsigned int m_3a8;
    void FUN_00626c50(unsigned int a1);
};

// Stores a1 in m_3a8, passes it to local.FUN_0059ce80, and calls FUN_0043b4f0/FUN_00626cb0 on objects obtained from m_3a0.FUN_00559450.
// @fnv 0x00626c50
void FUN_00626c50_cls::FUN_00626c50(unsigned int auiValue)
{
    Local_00626c50 local;
    reinterpret_cast<Z_00626c50*>(m_3a0.FUN_00559450((unsigned int)&local))->FUN_0043b4f0();
    local.FUN_0059ce80(auiValue);
    m_3a8 = auiValue;
    reinterpret_cast<Y_00626c50*>(m_3a0.FUN_00559450(local.v))->FUN_00626cb0();
}

class C1C50Filter
{
  public:
    C1C50Filter();

    void SetLayer(unsigned int uiLayer);

    unsigned int m_uiFilterInfo;
};

class C1C50HkObject
{
  public:
    C1C50Filter GetFilter();
    void SetFilter(C1C50Filter kFilter);
};

class C1C50WorldObject
{
  public:
    C1C50HkObject* GetHkObject();
    void FUN_00631c50(unsigned int uiLayer);

    int unk00;
    int unk04;
    unsigned int m_uiLayer;
};

// Sets the layer on the filter obtained from GetHkObject, stores it in m_uiLayer, and writes the filter back.
// @fnv 0x00631c50
void C1C50WorldObject::FUN_00631c50(unsigned int uiLayer)
{
    C1C50Filter kFilter = GetHkObject()->GetFilter();
    kFilter.SetLayer(uiLayer);
    m_uiLayer = uiLayer;
    GetHkObject()->SetFilter(kFilter);
}

struct QueryResult
{
    void __thiscall FUN_006147e0();
    void __thiscall BuildBodyModTexturePath();
};
struct QueryObject
{
    QueryResult* __thiscall FUN_004ac110(QueryObject*, char*);
    QueryResult* __thiscall FUN_004ac110(QueryObject*, char*, char*);
};
extern "C" void __cdecl FUN_00a61fb0(char*);
// @fnv 0x006570e0
void __cdecl FUN_006570e0(QueryObject* apQueryObject)
{
    char firstPath[264];
    char secondPath[264];
    apQueryObject->FUN_004ac110(apQueryObject, secondPath)->FUN_006147e0();
    apQueryObject->FUN_004ac110(apQueryObject, secondPath, firstPath)->BuildBodyModTexturePath();
    FUN_00a61fb0(firstPath);
}

struct SyncNode
{
    int unk00;
    int unk04;
    int state;
};
struct NodeLink
{
    SyncNode* value;
    SyncNode* ClearLowBit();
    SyncNode* FUN_0044df00();
};
struct StateValue
{
    int value;
    void FUN_006ecba0(bool, SyncNode*);
    int FUN_00559450();
};
struct Controller
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void Update();
};
struct Worker
{
    Controller* controller;
    int unk04;
    int unk08;
    int unk0c;
    int* state;
    NodeLink current;
    NodeLink pending;
    bool ProcessNodeChain(int, int);
    void AddRace(SyncNode*);
    void FUN_00529000();
    bool AdvanceState(int, int);
};
bool __cdecl FUN_004491c0(int*, int, int);
// Loops while ProcessNodeChain holds, compares pending/current state values via FUN_004491c0, updates the controller and returns whether a step succeeded.
// @fnv 0x00666080
bool Worker::AdvanceState(int aiArg1, int aiArg2)
{
    bool result = false;
    while (true)
    {
        if (!ProcessNodeChain(aiArg1, aiArg2))
        {
            result = false;
            break;
        }
        StateValue after;
        after.FUN_006ecba0(false, pending.ClearLowBit());
        StateValue now;
        now.FUN_006ecba0(true, pending.ClearLowBit());
        if (!FUN_004491c0(&current.FUN_0044df00()->state, now.FUN_00559450(), after.FUN_00559450()))
            continue;
        StateValue before;
        before.FUN_006ecba0(false, current.ClearLowBit());
        if (FUN_004491c0(state, after.FUN_00559450(), before.FUN_00559450()))
            AddRace(current.ClearLowBit());
        else
            ProcessNodeChain(aiArg1, aiArg2);
        controller->Update();
        result = true;
        break;
    }
    FUN_00529000();
    return result;
}

struct FUN_006ec830_target
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
    virtual int Call(int a, int b, int c);
};

struct FUN_006ec830_cls
{
    FUN_006ec830_target* m_00;
    int FUN_006ec9b0(int p);
    int InvokeWithArgs(int a1, int a2);
};

// Calls the virtual Call method on m_00 with a1 twice and a2, then passes the result to FUN_006ec9b0 and returns it.
// @fnv 0x006ec830
int FUN_006ec830_cls::InvokeWithArgs(int aiArg1, int aiArg2)
{
    return FUN_006ec9b0(m_00->Call(aiArg1, aiArg1, aiArg2));
}

namespace fnv_00906af0 {
struct QH_0092c820
{
    void FUN_0044dd60();
    void FUN_0092c870();
};
struct NP_0092c820
{
    QH_0092c820* m_pObject;
    NP_0092c820& FUN_0092c820(const NP_0092c820& ptr);
};

void FUN_0040fbe0();

struct IntegerMapEntry
{
    int key;
    NP_0092c820 value;
    bool IsOccupied();
};

struct TaggedEntry
{
    int m_bits;
    int GetPixelBitData();
    int Raw() const;
    IntegerMapEntry* GetEntry();
};

struct EntryRef
{
    int m_uiFilterValue;
    int Get() const;
};

struct LocalRef
{
    void* m_p;
    void* Init(bool b, void* p);
    int Get() const;
};

struct QueueOwner
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
    virtual void Process(int key, int arg);
    TaggedEntry* Lookup(int index);
};

struct QueueWalker
{
    QueueOwner* m_pOwnerObject;
    int unk04;
    int* m_out;
    int unk0c;
    TaggedEntry* m_ref;
    TaggedEntry m_entry;
    void Finish();
    bool ProcessEntry(int index, int arg, NP_0092c820* dest);
};

// @fnv 0x00906af0
bool QueueWalker::ProcessEntry(int index, int arg, NP_0092c820* dest)
{
    bool result = false;
    while (1)
    {
        LocalRef local;
        TaggedEntry* entry = m_pOwnerObject->Lookup(index);
        m_ref = entry;
        m_entry = *m_ref;
        *m_out = m_entry.GetPixelBitData();
        FUN_0040fbe0();
        local.Init(false, (void*)m_entry.GetPixelBitData());
        if (m_ref->Raw() != local.Get())
            continue;
        if (!m_entry.GetPixelBitData())
        {
            result = false;
            break;
        }
        m_pOwnerObject->Process(m_entry.GetEntry()->key, arg);
        dest->FUN_0092c820(m_entry.GetEntry()->value);
        result = true;
        FUN_0040fbe0();
        if (m_entry.GetEntry()->IsOccupied())
            continue;
        break;
    }
    Finish();
    return result;
}
}  // namespace fnv_00906af0

extern "C" int __cdecl FUN_00aa1a20(unsigned int, unsigned int, unsigned int);
extern "C" void __cdecl NormalizePathSeparators(void*);
extern "C" void __cdecl FUN_00ec65a6(void*, unsigned int, unsigned int);

class SpawnedObject
{
  public:
    virtual int vfn_00(int);
};

class FUN_00c3a8a0_cls
{
  public:
    void** m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    bool FUN_00a63330(unsigned int);
    bool FUN_00c3a8a0(unsigned int, unsigned int);
};

// @fnv 0x00c3a8a0
bool FUN_00c3a8a0_cls::FUN_00c3a8a0(unsigned int a1, unsigned int a2)
{
    if (a2 == 0)
    {
        a2 = FUN_00aa1a20(a1, 0, 0x2800);
    }
    bool result = false;
    if (a2 != 0)
    {
        void* e = &m_e0;
        FUN_00ec65a6(e, 0x104, a1);
        NormalizePathSeparators(&m_e0);
        result = FUN_00a63330(a2);
        SpawnedObject* p1 = (SpawnedObject*)a2;
        SpawnedObject* p2 = p1;
        (p2 != 0) ? p2->vfn_00(1) : 0;
    }
    return result;
}

// FUN_0043ace0 worker2 a2run3 A1: NiSortAdjustNode drop m_a8 (pack NiMemObject is 1B, +4 align -> 42 fields = 0xac alloc like ORIG)
struct MLx;
int __cdecl FUN_0044a670(const char*);
void* __cdecl FormHeap_Allocate(unsigned int);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
int __fastcall GetRefAt21C(const char*);
void __fastcall FUN_00c3b370(void*);
void* __fastcall FUN_00413f40(void*);
void* __fastcall FUN_0043b1b0(void*);
bool __cdecl FUN_00af3bd0(int, const char*);
void* __cdecl FUN_00aa13e0(unsigned int);
void __cdecl FUN_004b5d10(void*);
void* __fastcall FUN_0043b230(void*);
void* __cdecl FUN_00653270(void*, void*);
void* __fastcall GetStringAtOffset(void*);
void __cdecl FUN_0043b2b0(bool);
unsigned int __cdecl FUN_0043b290();
void* __cdecl FUN_0043b2a0();
unsigned int __cdecl FUN_00702440();
void* __cdecl FUN_0043b250();
int __cdecl FUN_005b5e40(const char*, ...);
bool __cdecl FUN_004b5bf0(void*);
void __cdecl FUN_00b57e30(void*, unsigned char, unsigned char);
extern char DAT_0101667c[];
extern char DAT_0101666c[];
extern char DAT_01016618[];
extern char DAT_010165c8[];
extern unsigned char DAT_01185520;
extern int DAT_011f36ac;

struct SubRef
{
    void FUN_0066b0d0(void*);
};
struct SortObj
{
    SortObj* FUN_00a5ecb0(unsigned int);
};
class NiSortAdjustNode : public NiMemObject
{
  public:
    NiSortAdjustNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
};
struct PropObj
{
    void* FUN_00a59d30(unsigned int);
    void FUN_00a5b230(unsigned int);
};
struct Cls260
{
    bool FUN_0043b260(unsigned short*);
};
struct ElemV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual int v0c();
    virtual void d04();
    virtual void d05();
    virtual int v18();
};
struct Arg1V
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual bool v60(const char*, int);
};
struct BigV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void vF8(int, void*);
};
struct CtrlV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void v90(void*, int);
};
struct MLx;
struct ThisS
{
    char* m_buf;
    int m_04;
    int m_08;
    SubRef m_sub;
    void FUN_0043ace0(const char* a0, MLx* a1, unsigned char a2, unsigned char a3);
};

// Copies a0 into m_buf, builds m_sub from a1's elements (wrapping in a NiSortAdjustNode when needed), and applies property/control updates.
// @fnv 0x0043ace0
void ThisS::FUN_0043ace0(const char* apName, MLx* apSource, unsigned char a2, unsigned char a3)
{
    bool q;
    {
        unsigned long count;
        {
            ElemV* elem;
            {
                void* x1;
                {
                    int iDynIndex;
                    {
                        int iElemIndex;
                        {
                            ElemV* pForm;
                            {
                                bool flagB;
                                {
                                    void* tmp;
                                    {
                                        void* z;
                                        {
                                            void* ctrlObj;
                                            {
                                                void* prop;
                                                {
                                                    void* pPropA;
                                                    {
                                                        void* pPropB;
                                                        {
                                                            bool flagC;
                                                            {
                                                                char* c;
                                                                {
                                                                    m_04 = 0;
                                                                    m_08 = 0;
                                                                    count = FUN_0044a670(apName) + 1;
                                                                    c = (char*)FormHeap_Allocate(count);
                                                                    m_buf = c;
                                                                    FUN_00406d30(m_buf, count, apName);
                                                                    if (GetRefAt21C((const char*)apSource) == 0)
                                                                    {
                                                                        FUN_00c3b370(apSource);
                                                                        if (!((Arg1V*)apSource)->v60(DAT_0101667c, 0))
                                                                        {
                                                                            m_buf = 0;
                                                                            return;
                                                                        }
                                                                    }
                                                                    elem = (ElemV*)apSource->GetStringAt(0);
                                                                    q = false;
                                                                    if (elem != 0 && elem->v0c() != 0)
                                                                    {
                                                                        x1 = FUN_0043b1b0(FUN_00413f40(elem));
                                                                        if (x1 != 0 &&
                                                                            FUN_00af3bd0((int)x1, DAT_0101666c))
                                                                        {
                                                                            m_sub.FUN_0066b0d0(
                                                                                (SortObj*)new NiSortAdjustNode(0));
                                                                            ((BigV*)FUN_00559450((int*)&m_sub))
                                                                                ->vF8(0, elem);
                                                                        }
                                                                        else
                                                                        {
                                                                            m_sub.FUN_0066b0d0(elem);
                                                                        }
                                                                        q = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        iDynIndex = 0;
                                                                        for (iElemIndex = 0;
                                                                             iElemIndex < (unsigned int)GetRefAt21C(
                                                                                              (const char*)apSource);
                                                                             ++iElemIndex)
                                                                        {
                                                                            elem = (ElemV*)apSource->GetStringAt(
                                                                                iElemIndex);
                                                                            if (elem != 0)
                                                                            {
                                                                                if (elem->v0c() != 0 ||
                                                                                    elem->v18() != 0)
                                                                                {
                                                                                    pForm = elem;
                                                                                    if (FUN_00559450((int*)&m_sub) == 0)
                                                                                    {
                                                                                        m_sub.FUN_0066b0d0(
                                                                                            (SortObj*)new NiSortAdjustNode(
                                                                                                0));
                                                                                    }
                                                                                    ((BigV*)FUN_00559450((int*)&m_sub))
                                                                                        ->vF8(iDynIndex++, pForm);
                                                                                    q = true;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    if (q)
                                                                    {
                                                                        FUN_004b5d10((void*)FUN_00559450((int*)&m_sub));
                                                                        if (DAT_01185520)
                                                                        {
                                                                            z = FUN_0043b230(
                                                                                (void*)FUN_00559450((int*)&m_sub));
                                                                            ctrlObj = FUN_00653270(&DAT_011f36ac, z);
                                                                            if (ctrlObj != 0)
                                                                            {
                                                                                prop = GetStringAtOffset(ctrlObj);
                                                                                if (prop != 0)
                                                                                {
                                                                                    if (FUN_0043b1b0(FUN_00413f40(
                                                                                            (void*)FUN_00559450(
                                                                                                (int*)&m_sub))) != 0)
                                                                                    {
                                                                                        ((CtrlV*)prop)
                                                                                            ->v90(
                                                                                                FUN_00413f40(
                                                                                                    (void*)FUN_00559450(
                                                                                                        (int*)&m_sub)),
                                                                                                0);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        flagB = false;
                                                                        FUN_0043b2b0(true);
                                                                        tmp = ((PropObj*)FUN_00559450((int*)&m_sub))
                                                                                  ->FUN_00a59d30(FUN_0043b290());
                                                                        if (tmp != 0)
                                                                        {
                                                                            pPropA = tmp;
                                                                            if (((Cls260*)pPropA)
                                                                                    ->FUN_0043b260((
                                                                                        unsigned short*)FUN_0043b2a0()))
                                                                            {
                                                                                ((PropObj*)FUN_00559450((int*)&m_sub))
                                                                                    ->FUN_00a5b230(FUN_0043b290());
                                                                                flagB = true;
                                                                            }
                                                                        }
                                                                        tmp = ((PropObj*)FUN_00559450((int*)&m_sub))
                                                                                  ->FUN_00a59d30(FUN_00702440());
                                                                        if (0 != tmp)
                                                                        {
                                                                            pPropB = tmp;
                                                                            if (((Cls260*)pPropB)
                                                                                    ->FUN_0043b260((
                                                                                        unsigned short*)FUN_0043b250()))
                                                                            {
                                                                                ((PropObj*)FUN_00559450((int*)&m_sub))
                                                                                    ->FUN_00a5b230(FUN_00702440());
                                                                                flagB = true;
                                                                            }
                                                                        }
                                                                        if (flagB)
                                                                        {
                                                                            if (((char*)apSource)[8])
                                                                            {
                                                                                FUN_005b5e40(DAT_01016618,
                                                                                             (char*)apSource + 8,
                                                                                             apName);
                                                                            }
                                                                            else
                                                                            {
                                                                                FUN_005b5e40(DAT_010165c8, apName);
                                                                            }
                                                                        }
                                                                        FUN_0043b2b0(false);
                                                                        if (a2)
                                                                        {
                                                                            flagC = false;
                                                                            if (a3 || FUN_004b5bf0((void*)FUN_00559450(
                                                                                          (int*)&m_sub)))
                                                                            {
                                                                                flagC = true;
                                                                            }
                                                                            FUN_00b57e30(
                                                                                (void*)FUN_00559450((int*)&m_sub), a3,
                                                                                flagC);
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
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern int DAT_010169d4;

struct FUN_0043d8f0_Class : public FUN_0043c830
{
    void FUN_0043d8f0();
};

// @fnv 0x0043d8f0
void FUN_0043d8f0_Class::FUN_0043d8f0()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010169d4);
    this->FUN_0043c830::~FUN_0043c830();
}

namespace ModelResources {
struct Main;
struct Form;
struct Entry;
struct Model
{
    unsigned int value;
    unsigned int FUN_0048cee0();
};
struct Prefix18
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
};
struct Source : Prefix18, Model
{
    bool FUN_00408a20();
    void FUN_00408970();
};
struct Link
{
    unsigned int value;
    bool FUN_008256d0();
    Entry** FUN_006815c0();
    Link* FUN_00726070();
};
struct Prefix4
{
    unsigned int value;
};
struct Iterator : Prefix4, Link
{
};
struct PrefixC
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};
struct ListOwner : PrefixC, Iterator
{
};
struct List
{
    void FUN_00470470();
    ~List();
};
struct Form
{
    int FUN_00401170();
};
struct WeaponPrefix : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
};
struct Weapon : WeaponPrefix, Model
{
};
struct ModelPair
{
    Model* GetBipedModel(int);
};
struct Armor : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    ModelPair models;
};
struct Misc : Form
{
    List* CollectModelPaths(int, int);
};
struct CreaturePrefix : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
};
struct Creature : CreaturePrefix, Model
{
};
struct Reference
{
    bool IsArchetypeFlagSet();
    bool FUN_004088a0();
    Form* FUN_005f5f80();
    bool FUN_00403e60(unsigned int);
    bool FUN_00408880();
    void FUN_00408790();
};
struct Entry
{
    Reference* FUN_00825c00();
};
struct Manager
{
    void FUN_00443d30(Model*, void*, Main*, void*, int, int, int);
    void QueueKFPathsFromList(List*, int, void*, Main*, int);
    void QueueModelAnimations(Model*, void*, Main*, int, int, int);
};
extern Manager* DAT_011c3b3c;
void* FUN_0045c6b0(Form*);
void FUN_0040ab50();
struct Main
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void Complete();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    ListOwner* owner;
    Source* source;
    void* FUN_0043cc60();
    void SetFieldCToFive();
    void UpdateModels();
};
// Loads the source model if needed, then walks the owner's entries and dispatches weapon, armor, misc and creature models to the manager before completing.
// @fnv 0x0043dc70
void Main::UpdateModels()
{
    bool loaded = false;
    if (source->FUN_0048cee0() > 0 && !source->FUN_00408a20())
    {
        DAT_011c3b3c->FUN_00443d30(static_cast<Model*>(source), FUN_0043cc60(), this, 0, 1, 0, 0);
        loaded = true;
    }
    source->FUN_00408970();
    Iterator* iterator = static_cast<Iterator*>(owner);
    if (!iterator->FUN_008256d0())
        while (iterator)
        {
            Entry* entry = *iterator->FUN_006815c0();
            Reference* reference = entry->FUN_00825c00();
            if (reference->IsArchetypeFlagSet() && (!loaded || !reference->FUN_004088a0()))
            {
                Form* form = reference->FUN_005f5f80();
                if (form)
                {
                    if (reference->FUN_00403e60(0x10000))
                    {
                        if (form->FUN_00401170() == 40)
                        {
                            Weapon* weapon = (Weapon*)form;
                            if (weapon->FUN_0048cee0() > 0)
                                DAT_011c3b3c->FUN_00443d30(static_cast<Model*>(weapon), FUN_0043cc60(), this,
                                                           FUN_0045c6b0(weapon), 1, 0, 0);
                        }
                    }
                    else if (reference->FUN_00403e60(0x20000))
                    {
                        if (form->FUN_00401170() == 24)
                        {
                            Armor* armor = (Armor*)form;
                            DAT_011c3b3c->FUN_00443d30(armor->models.GetBipedModel(0), FUN_0043cc60(), this,
                                                       FUN_0045c6b0(armor), 1, 0, 0);
                            DAT_011c3b3c->FUN_00443d30(armor->models.GetBipedModel(1), FUN_0043cc60(), this,
                                                       FUN_0045c6b0(armor), 1, 0, 0);
                        }
                    }
                    else if (reference->FUN_00403e60(0x40000))
                    {
                        if (form->FUN_00401170() == 42)
                        {
                            Misc* miscSlot0 = (Misc*)form;
                            List* listSlot0 = miscSlot0->CollectModelPaths(1, 1);
                            DAT_011c3b3c->QueueKFPathsFromList(listSlot0, 0, FUN_0043cc60(), this, 0);
                            listSlot0->FUN_00470470();
                            delete listSlot0;
                        }
                        else if (form->FUN_00401170() == 43)
                        {
                            Creature* creature = (Creature*)form;
                            DAT_011c3b3c->QueueModelAnimations(static_cast<Model*>(creature), FUN_0043cc60(), this, 0,
                                                               1, 1);
                            DAT_011c3b3c->FUN_00443d30(static_cast<Model*>(creature), FUN_0043cc60(), this,
                                                       FUN_0045c6b0(creature), 1, 0, 0);
                        }
                    }
                }
                if (!reference->FUN_00408880() && !reference->FUN_004088a0() && reference->FUN_00403e60(0x40000))
                    FUN_0040ab50();
                reference->FUN_00408790();
            }
            iterator = static_cast<Iterator*>(iterator->FUN_00726070());
        }
    SetFieldCToFive();
    Complete();
}
}

class ModelBase43E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class Model43E
{
  public:
    int m_iLoaded;
};

class AnimObject43E : public ModelBase43E, public Model43E
{
};

class AnimData43E
{
  public:
    AnimObject43E* ComputePositionAtTime(int iIndex);
};

class Handle43E
{
  public:
    AnimData43E* Get() const;

    AnimData43E* m_pPointer;
};

class Task43E;

class ModelLoader43E
{
  public:
    void ProcessModelRequest(Model43E* pkModel, int iPriority, Task43E* pkTask, int iFlags, bool bForce, int iArg1,
                             int iArg2);
};

extern ModelLoader43E* g_pkModelLoader43E;

class Task43E
{
  public:
    int GetPriority();
    void Finish();
    void LoadModelsAndFinish();

    void* m_ppVirtualMethodTable;
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
    Handle43E m_kData;
};

// @fnv 0x0043e690
void Task43E::LoadModelsAndFinish()
{
    if (m_kData.Get())
    {
        for (int i = 0; i < 2; i++)
        {
            if (m_kData.Get()->ComputePositionAtTime(i))
                g_pkModelLoader43E->ProcessModelRequest(m_kData.Get()->ComputePositionAtTime(i), GetPriority(), this, 2,
                                                        true, 0, 0);
        }
    }
    Finish();
}

struct FUN_0043e840_shell : public ModelLoader
{
    void FUN_00c3cb70(int, int);
    void FUN_0043e840(int param_2, int param_3);
};
// Calls FUN_00c3cb70 with the two arguments, then passes the queued file at this+0x3c to g_modelLoader->DispatchAnimIdle.
// @fnv 0x0043e840
void FUN_0043e840_shell::FUN_0043e840(int aiArg1, int aiArg2)
{
    FUN_00c3cb70(aiArg1, aiArg2);
    g_modelLoader->DispatchAnimIdle((QueuedFile*)FUN_00559450((int*)((char*)this + 0x3c)));
}

struct FUN_0043eac0_class
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

    void __thiscall FUN_00c3cb70(int param_1, int param_2);
    void __thiscall ForwardToHolder(int param_1, int param_2);
};

extern Holder14* DAT_011c3b3c;

// Calls FUN_00c3cb70 with the two arguments, then calls ForwardToInner on DAT_011c3b3c passing unk28.
// @fnv 0x0043eac0
void __thiscall FUN_0043eac0_class::ForwardToHolder(int param_1, int param_2)
{
    FUN_00c3cb70(param_1, param_2);
    DAT_011c3b3c->ForwardToInner(unk28);
}

namespace fnv_0043ed90 {
struct RefActor;
struct LoadedNode
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
    RefActor* owner;
};
struct NodePointer
{
    LoadedNode* node;
    LoadedNode* FUN_00559450();
};
struct AnimationManager
{
    void AttachHeadModels(RefActor*, int, LoadedNode*, LoadedNode*);
};
struct RefActor
{
    AnimationManager* FUN_007af430();
    const char* FUN_0084e3a0();
};
extern RefActor* DAT_011dea3c;
void __cdecl FUN_004b6dc0(LoadedNode*, const char*);
struct AttachTask
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
    NodePointer first;
    NodePointer second;
    void FUN_0043ed90(RefActor* actor, int arg);
};
// @fnv 0x0043ed90
void AttachTask::FUN_0043ed90(RefActor* actor, int arg)
{
    AutoMemContext_1 manager((MEM_CONTEXT)0x37, true,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x613);
    AnimationManager* scope = actor->FUN_007af430();
    scope->AttachHeadModels(actor, arg, first.FUN_00559450(), second.FUN_00559450());
    if (actor != DAT_011dea3c)
    {
        FUN_004b6dc0(first.FUN_00559450(), actor->FUN_0084e3a0());
        if (second.FUN_00559450())
            FUN_004b6dc0(second.FUN_00559450(), actor->FUN_0084e3a0());
    }
    if (second.FUN_00559450())
        second.FUN_00559450()->owner = actor;
    if (first.FUN_00559450())
        first.FUN_00559450()->owner = actor;
}
}  // namespace fnv_0043ed90

struct SaveItem
{
    unsigned int unk00;
    unsigned int m_04;
};

struct SaveSub
{
    bool FUN_004ae8a0(int index);
    SaveItem* GetEntryAt(int index);
};

struct SaveHolder
{
    void LoadMesh(unsigned int value, int result, int owner, int flag);
};

extern QueueModelHolder* g_QueueHolder;

class FUN_0043f120_cls
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    SaveSub* m_28;
    unsigned int m_2c[20];
    int FUN_0043cc60();
    void FUN_0043f1f0(int flag);
    void FUN_0043f120();
};

// @fnv 0x0043f120
void FUN_0043f120_cls::FUN_0043f120()
{
    for (int i = 0; i < 20; i++)
    {
        if (m_28->FUN_004ae8a0(i))
        {
            unsigned int v = m_28->GetEntryAt(i)->m_04;
            g_QueueHolder->FUN_00443dc0(v, (QueueObj*)&m_2c[i], FUN_0043cc60(), (int)this, 3, true, true, true, 0.0f);
            reinterpret_cast<SaveHolder*>(g_QueueHolder)->LoadMesh(v, FUN_0043cc60(), (int)this, -1);
        }
    }
    FUN_0043f1f0(1);
    vfn_28();
}

struct FnvSceneNode
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual int vfn18();
    FnvSceneNode* FUN_004a8a90();
    FnvSceneNode* FUN_0043b230();
    FnvSceneNode* FUN_0043fad0();
    FnvSceneNode* FUN_005495f0();
    FnvSceneNode* FUN_005495f0(void*);
    void FUN_00a5d510();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4c();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5c();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6c();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7c();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8c();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9c();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual void vfnD0();
    virtual void vfnD4();
    virtual void vfnD8();
    virtual void vfnDC();
    virtual void vfnE0();
    virtual void vfnE4(void*);
    void FUN_0043fa80(void*);
    FnvSceneNode* FUN_006a9540(void*, void*);
    bool ApplyMorphs(void*, FnvSceneNode*, int);
    void FUN_00603ad0(void*);
};
struct FnvRenderSelector
{
    FnvRenderSelector* FUN_007af430();
    int FUN_00401170();
    void FUN_00603ad0(void*);
};
struct FnvMaster
{
    FnvRenderSelector* FUN_0043f010();
    FnvSceneNode* FUN_004a8a90();
    FnvSceneNode* FUN_004ae790(int);
    FnvSceneNode* LoadSlotObject();
};
struct FnvRefPtr
{
    FnvSceneNode* value;
    FnvSceneNode* FUN_00559450();
    void FUN_0066b0d0(FnvSceneNode*);
    void FUN_0066b0d0(FnvSceneNode*, FnvSceneNode*, FnvSceneNode*, int);
};
struct FnvList
{
    unsigned int FUN_0043b480();
    FnvSceneNode* FUN_0043b4a0(unsigned int);
};
struct FnvLink
{
    FnvSceneNode* FUN_0043b230();
};
struct FnvGuard
{
    int lock;
    FnvGuard(int, bool, const char*, int);
    ~FnvGuard();
};
struct FnvHandle
{
    FnvSceneNode* object;
    FnvHandle(FnvSceneNode*);
    ~FnvHandle();
    FnvSceneNode* FUN_00559450();
    void FUN_0066b0d0(FnvSceneNode*);
};
struct FnvVec3
{
    float x, y, z;
    void FUN_006815c0();
    void FUN_0043f850(float);
};
struct FnvMatrix3
{
    float row0x, row0y, row0z, row1x, row1y, row1z, row2x, row2y, row2z;
    void FUN_006815c0();
    void FUN_0043f850(float);
};
struct FnvEntry
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18, field1c;
    FnvEntry();
    ~FnvEntry();
};
struct FnvGeometry
{
    FnvGeometry* FUN_006a9540(FnvMatrix3*, FnvMatrix3*);
    FnvGeometry* FUN_0043f8d0();
};
extern "C" const char DAT_01016840[];
extern "C" float DAT_01016b78;

extern "C" void __cdecl FUN_00ec782f(FnvEntry*, unsigned, unsigned, void*, void*);
extern "C" void __cdecl FUN_00ec5fce(FnvEntry*, unsigned, unsigned, void*);

struct FnvQueueManager
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48(void*);
};

struct FnvRoot
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FnvMaster* master28;
    FnvRefPtr references[20];
    FnvRefPtr attachments[20];
    FnvRefPtr children[20];
    int p11c;
    bool FUN_0043fab0();
    bool FUN_0043caa0();
    bool IsFieldCZero();
    void NotifyParents();
    bool FUN_00449110();
    bool FUN_00449130();
    void FUN_0043f2f0();
};

// @fnv 0x0043f2f0
void FnvRoot::FUN_0043f2f0()
{
    if (!FUN_0043fab0())
    {
        NotifyParents();
        return;
    }
    if (FUN_0043caa0() && IsFieldCZero())
    {
        DAT_01202d98->vfn_48((IOTask*)this);
        return;
    }

    FnvGuard fileAccess(0x32, true, DAT_01016840, 0x690);
    {
        FnvHandle current(0);
        if (FUN_00449110() && FUN_0043caa0() && !FUN_00449130() && (void*)p11c != DAT_011dea3c)
        {
            for (int index = 0; index < 20; ++index)
            {
                if (references[index].FUN_00559450() && references[index].FUN_00559450()->FUN_004a8a90() &&
                    references[index].FUN_00559450()->FUN_004a8a90()->FUN_0043b230())
                {
                    children[index].FUN_0066b0d0(master28->LoadSlotObject(), attachments[index].FUN_00559450(),
                                                 references[index].FUN_00559450()->FUN_004a8a90()->FUN_0043b230(),
                                                 index);
                    if (children[index].FUN_00559450())
                    {
                        bool found = false;
                        for (unsigned int i = 0; i < ((FnvList*)children[index].FUN_00559450())->FUN_0043b480(); ++i)
                        {
                            FnvSceneNode* linkedNode;
                            {
                                FnvSceneNode* node = ((FnvList*)children[index].FUN_00559450())->FUN_0043b4a0(i);
                                if (!node || !node->vfn18())
                                    continue;
                                {
                                    FnvSceneNode* selectedNode = node;
                                    linkedNode = selectedNode->FUN_0043fad0();
                                    if (linkedNode)
                                    {
                                        found = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (!found)
                        {
                            FnvSceneNode* fallback = attachments[index].FUN_00559450()
                                                         ? attachments[index].FUN_00559450()
                                                         : master28->FUN_004ae790(index);
                            if (fallback)
                            {
                                for (unsigned int j = 0; j < ((FnvList*)children[index].FUN_00559450())->FUN_0043b480();
                                     ++j)
                                {
                                    FnvSceneNode* node = ((FnvList*)children[index].FUN_00559450())->FUN_0043b4a0(j);
                                    {
                                        FnvSceneNode* geometry = node;
                                        if (geometry && geometry->FUN_005495f0() && master28->FUN_0043f010() &&
                                            master28->FUN_0043f010()->FUN_007af430() &&
                                            master28->FUN_0043f010()->FUN_007af430()->FUN_00401170() == 42)
                                        {
                                            FnvRenderSelector* a = master28->FUN_0043f010()->FUN_007af430();
                                            FnvEntry p[4];   // Resource entries for the selected geometry.
                                            FnvHandle h(0);  // Retains the active scene object.
                                            geometry->FUN_005495f0(&current.object)->FUN_00a5d510();
                                            h.FUN_0066b0d0(current.FUN_00559450());
                                            geometry->vfnE4(h.FUN_00559450());
                                            a->FUN_00603ad0(p);
                                            if (!FUN_0043faf0() || fallback->ApplyMorphs(p, geometry, 0))
                                            {
                                                FnvMatrix3 matForward;
                                                matForward.FUN_006815c0();
                                                matForward.FUN_0043f850(DAT_01016b78);
                                                FnvMatrix3 matTransform;
                                                geometry->FUN_0043fa80(((FnvGeometry*)geometry)
                                                                           ->FUN_006a9540(&matTransform, &matForward)
                                                                           ->FUN_0043f8d0());
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
        NotifyParents();
    }
}

struct V3;
struct M3
{
    float m[3][3];
    M3();
};
struct AttachNode
{
    void FUN_00440460(const V3* pkPos);
    void FUN_0043fa80(const M3& kRot);
    void FUN_00440490(float fScale);
};
struct ActorV_S
{
    float GetScale();
};
class BSOcclusionPlane
{
  public:
    int GetCullResult() const;
};
struct AttachRef
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
    virtual void v056();
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
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const V3* GetPos();
    M3 FUN_0056fa00();
    void FUN_00570f70(AttachNode* pkNode);
    void FUN_00565210(bool bArg);
};
struct OSGlobals;
extern OSGlobals* g_osGlobals;
unsigned int __fastcall FUN_0044edb0(OSGlobals* pkGlobals);
unsigned int gm_GetCurrentThreadId();
extern int g_TES;
struct AttachTES
{
    void FUN_00451ef0(AttachRef* pkRef, int iCell, int a, int b);
};
struct AttachLoader
{
    void DispatchToQueue(QueuedFile* pkTask);
};
struct FUN_00440310_shell : QueuedReference
{
    char pad00[0x28];
    AttachRef* m_pkRef;
    char pad2c[0xc];
    NiPointer<QueuedFile> m_spTask;
    void FUN_00440310(AttachNode* pkNode);
};
// @fnv 0x00440310
void FUN_00440310_shell::FUN_00440310(AttachNode* pkNode)
{
    pkNode->FUN_00440460(m_pkRef->GetPos());
    pkNode->FUN_0043fa80(m_pkRef->FUN_0056fa00());
    pkNode->FUN_00440490(((ActorV_S*)m_pkRef)->GetScale());
    if (FUN_0044edb0(g_osGlobals) == gm_GetCurrentThreadId())
    {
        m_pkRef->FUN_00570f70(pkNode);
        ((AttachTES*)g_TES)->FUN_00451ef0(m_pkRef, ((BSOcclusionPlane*)m_pkRef)->GetCullResult(), 0, 0);
        m_pkRef->FUN_00565210(true);
    }
    else
    {
        m_spTask = (QueuedFile*)new FUN_004404c0(m_pkRef, (int)pkNode);
        ((AttachLoader*)g_modelLoader)->DispatchToQueue(m_spTask);
    }
}

namespace fnv_004408f0 {
class SLNode;
class SLObj28
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
    virtual void v0e0();
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
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc(int, int);
    void Callee2(int);
    SLNode* Get();
    unsigned char Check2();
};

class SLNode
{
  public:
    void Callee3(int);
};

class SLHelper
{
  public:
    void Callee();
    void Callee4(SLObj28*);
};

extern SLHelper* DAT_011c3b3c;

class FUN_004408f0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    SLObj28* m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    void FUN_004408f0(int a1, int a2);
    void Mid(int a1, int a2);
};

// @fnv 0x004408f0
void FUN_004408f0_cls::FUN_004408f0(int a1, int a2)
{
    if (FUN_00559450((int*)&m_38) != 0)
    {
        ((SLHelper*)FUN_00559450((int*)&m_38))->Callee();
    }
    Mid(a1, a2);
    if (FUN_00559450((int*)&m_34) != 0)
    {
        m_28->Callee2(FUN_00559450((int*)&m_34));
        ((SLNode*)&m_34)->Callee3(0);
        m_28->v1cc(0, 0);
    }
    DAT_011c3b3c->Callee4(m_28);
    if (m_28->Get() != 0)
    {
        FinishScriptRunLockAndReset((char*)m_28->Get());
        if (m_28->Check2())
        {
            FinishScriptRun((char*)m_28->Get());
        }
    }
}
}  // namespace fnv_004408f0

class B440ED0Form;

class B440ED0Reference
{
  public:
    B440ED0Form* GetObjectReference();
    bool FUN_00564e60();
    bool FUN_00564f00();
};

int __cdecl FUN_0045c6b0(B440ED0Form* pkForm);

class B440ED0Task;

class B440ED0ModelLoader
{
  public:
    void DispatchWithScope(B440ED0Reference* pkReference, B440ED0Form* pkForm, int ePriority, B440ED0Task* pkTask,
                           int iType);
};

extern B440ED0ModelLoader* g_pkB440ED0ModelLoader;

class B440ED0Task
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_iMemContext;
    int unk1C;
    int unk20;
    int unk24;
    B440ED0Reference* m_pkReference;

    int GetPriority();
    void FUN_00440ed0();
};

// Resolves the task's reference to a form, derives a load type from it, and submits the reference to the model loader with the task's priority.
// @fnv 0x00440ed0
void B440ED0Task::FUN_00440ed0()
{
    AutoMemHelper kMemHelper8(m_iMemContext, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x847);
    B440ED0Form* pkObject = m_pkReference->GetObjectReference();
    B440ED0Form* pkForm = pkObject;
    int iType = FUN_0045c6b0(pkObject);
    if (m_pkReference && m_pkReference->FUN_00564e60())
        iType = 6;
    if (m_pkReference && m_pkReference->FUN_00564f00())
        iType = 10;
    g_pkB440ED0ModelLoader->DispatchWithScope(m_pkReference, pkForm, GetPriority(), this, iType);
}

class B441420Info;

class B441420Array
{
  public:
    B441420Info*& GetAt(int iIndex);
};

class B441420Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B441420Array m_kInfos;

    B441420Info* GetInfoAt(int iIndex);
};

// @fnv 0x00441420
B441420Info* B441420Owner::GetInfoAt(int iIndex)
{
    return m_kInfos.GetAt(iIndex);
}

struct MLPackage
{
    bool GetForceUnequipWeapon();
};

struct MLActor
{
    struct MLParentCell* GetParentCell();
    MLPackage* GetCurrentPackage();
};

struct MLCellBase
{
    int unk00;
};

struct MLAttachTarget
{
    int unk00;
};

struct MLParentCell : MLCellBase
{
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    bool FUN_005f1590(MLActor* apActor);
    void FUN_005fa0a0(MLActor* apActor);
    void FUN_005f9e00(MLActor* apActor, bool abFlag1, bool abFlag2, bool abFlag3);
};

struct MLParentCellEx : MLParentCell, MLAttachTarget
{
};

struct MLLoadTask;

struct MLModelLoader
{
    void QueueModelAnimations(MLAttachTarget* apTarget, int aiPriority, MLLoadTask* apTask, MLActor* apActor,
                              bool abFlag1, bool abFlag2);
    void FUN_004457d0(MLAttachTarget* apTarget, int aiPriority, MLLoadTask* apTask, MLActor* apActor);
};

extern MLModelLoader* g_pMLModelLoader;

struct MLLoadTask
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MEM_CONTEXT eMemContext;
    int unk1C;
    int unk20;
    int unk24;
    MLActor* pActor;

    int GetPriority();
    void QueueDismemberedLimbLoads();
    void ProcessLoadTask();
};

// @fnv 0x004419a0
void MLLoadTask::ProcessLoadTask()
{
    AutoMemContext_1 kMemContext5(eMemContext, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x925);
    MLParentCellEx* pCell4 = (MLParentCellEx*)pActor->GetParentCell();
    MLActor* pTaskActor = pActor;
    bool bUnequipB = true;
    MLPackage* pPackage9 = pTaskActor->GetCurrentPackage();
    if (pPackage9 && pPackage9->GetForceUnequipWeapon())
        bUnequipB = false;

    bool m_bHeaderParsed = pCell4->FUN_005f1590(pActor);
    if (!m_bHeaderParsed)
        pCell4->FUN_005fa0a0(pActor);
    else
        pCell4->FUN_005f9e00(pActor, true, bUnequipB, false);

    MLAttachTarget* pTarget5 = pCell4;
    g_pMLModelLoader->QueueModelAnimations(pTarget5, GetPriority(), this, pActor, true, false);
    g_pMLModelLoader->FUN_004457d0(pTarget5, GetPriority(), this, pActor);
    QueueDismemberedLimbLoads();
}

struct Cls492c0
{
    Cls492c0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls496a0
{
    Cls496a0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4b750
{
    Cls4b750(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4ba10
{
    Cls4ba10(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4bbe0
{
    Cls4bbe0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4be80
{
    Cls4be80(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4b500
{
    Cls4b500(int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4c760
{
    Cls4c760(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls497c0
{
    Cls497c0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct ShellTask28
{
    void FUN_00c42f50();
};
struct IOShell442650
{
    void FUN_0057bd60(void*);
    void FUN_004febb0(void*);
    void FUN_00442a80(void*);
    void FUN_004fbf00(void*);
    void FUN_004febd0(void*);
    void SetWaterForm(void*);
};
void FUN_00446e30();
void FUN_00446ea0();
void FUN_00446f00();
void FUN_00446f10();
void FUN_00446f90();
struct Mgr442650
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    FUN_004421d0* m_28;
    char m_2c;
    Mgr442650* FUN_00442650();
};
// @fnv 0x00442650
Mgr442650* Mgr442650::FUN_00442650()
{
    m_00 = new Cls492c0(10, 1009, 12);
    m_04 = new Cls496a0(10, 1009, 12);
    m_08 = new Cls4b750(10, 5039, 12);
    m_0c = new Cls4b750(10, 5039, 12);
    m_10 = new Cls4ba10(10, 251, 12);
    m_14 = new Cls4bbe0(10, 251, 12);
    m_18 = new Cls4be80(10, 251, 12);
    m_1c = new Cls4b500(10, 8);
    m_20 = new Cls4c760(10, 1009, 12);
    m_24 = new Cls497c0(10, 1009, 12);
    m_28 = new FUN_004421d0(10);
    ((ShellTask28*)m_28)->FUN_00c42f50();
    m_2c = 0;
    if (DAT_01202d98)
    {
        ((IOShell442650*)DAT_01202d98)->FUN_0057bd60((void*)FUN_00446e30);
        ((IOShell442650*)DAT_01202d98)->FUN_004febb0((void*)FUN_00446e40);
        ((IOShell442650*)DAT_01202d98)->FUN_00442a80((void*)FUN_00446ea0);
        ((IOShell442650*)DAT_01202d98)->FUN_004fbf00((void*)FUN_00446f00);
        ((IOShell442650*)DAT_01202d98)->FUN_004febd0((void*)FUN_00446f10);
        ((IOShell442650*)DAT_01202d98)->SetWaterForm((void*)FUN_00446f90);
    }
    return this;
}

struct QEntry444;

struct QTask444
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void Queue8();
    virtual void v009();
    virtual void QueueA();
    void FUN_00443aa0(QueuedFile* pkParent);
    void FUN_00443ff0(bool bValue);
};

struct FUN_0043c960
{
    char pad[0x48];
    FUN_0043c960(QEntry444* pkEntry, int iPriority);
};

struct FUN_0043c6e0
{
    char pad[0x48];
    FUN_0043c6e0(int iKey, int iPriority, int iExtra, bool bFlagA, bool bFlagB);
};

struct QPtr444
{
    QTask444* FUN_00559450() const;
};

struct QOut444
{
    void FUN_0092c820(const GlobalObject_00528cb0& kPtr);
    void FUN_006f74f0(QueuedFile* pkFile);
};

struct QEntry444
{
    void FUN_0092c870();
};

struct QMap444
{
    virtual void v0();
    virtual void v1();
    virtual bool GetAt(int iKey, QEntry444** ppkEntry);
};

struct FUN_004440d0_shell
{
    QMap444* m_pTaskMap;

    void QueueTaskByKey(int iKey, QOut444& kOut, int iPriority, QueuedFile* pkParent, int iExtra, bool bFlagA,
                        bool bFlagB, bool bFlagC);
};

// @fnv 0x004440d0
void FUN_004440d0_shell::QueueTaskByKey(int iKey, QOut444& kOut, int iPriority, QueuedFile* pkParent, int iExtra,
                                        bool bFlagA, bool bFlagB, bool bFlagC)
{
    QEntry444* pkEntry = 0;
    if (m_pTaskMap->GetAt(iKey, &pkEntry))
    {
        if (bFlagB)
            pkEntry->FUN_0092c870();
        if (pkParent)
        {
            GlobalObject_00528cb0 kTask((int)new FUN_0043c960(pkEntry, iPriority));
            ((QPtr444*)&kTask)->FUN_00559450()->FUN_00443aa0(pkParent);
            ((QPtr444*)&kTask)->FUN_00559450()->QueueA();
            kOut.FUN_0092c820(kTask);
            return;
        }
        kOut.FUN_006f74f0(0);
        return;
    }
    GlobalObject_00528cb0 kNewTask((int)new FUN_0043c6e0(iKey, iPriority, iExtra, bFlagA, bFlagB));
    ((QPtr444*)&kNewTask)->FUN_00559450()->FUN_00443ff0(bFlagC);
    ((QPtr444*)&kNewTask)->FUN_00559450()->FUN_00443aa0(pkParent);
    ((QPtr444*)&kNewTask)->FUN_00559450()->Queue8();
    kOut.FUN_0092c820(kNewTask);
}

namespace fnv_00444350 {
struct QFile444
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
    virtual void Start();
    virtual void v11();
    virtual void SetPriority(int);
    void SetParent(QFile444*);
    void SetFlag(bool);
};
struct QHead444 : public QFile444
{
    QHead444(void* apKey, int aePriority, void* apNPC, bool abA, bool abB);
    QHead444(void* apEntry, int aePriority);
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
};
struct QPtr444
{
    QPtr444(QHead444*);
    ~QPtr444();
    operator QHead444*() const;
    QHead444* operator->() const;
    QPtr444& operator=(const QPtr444&);
    QPtr444& operator=(QHead444*);
    int p;
};
struct QEntry444
{
    void AddRef();
};
struct QMap444
{
    virtual void v0();
    virtual void v1();
    virtual bool GetAt(void* apKey, QEntry444** appOut);
};
struct HeadLoader444
{
    QMap444* pMap;
    void FUN_00444350(void* apKey, int aiArg2, QPtr444* apOut, int aePriority, QFile444* apParent, void* apNPC,
                      bool abA, bool abB, bool abFlag);
};

// @fnv 0x00444350
void HeadLoader444::FUN_00444350(void* apKey, int aiArg2, QPtr444* apOut, int aePriority, QFile444* apParent,
                                 void* apNPC, bool abA, bool abB, bool abFlag)
{
    QEntry444* pEntry = 0;
    if (pMap->GetAt(apKey, &pEntry))
    {
        if (abB)
            pEntry->AddRef();
        if (apParent)
        {
            QPtr444 spHead(new QHead444(pEntry, aePriority));
            spHead->SetParent(apParent);
            spHead->Start();
            *apOut = spHead;
            return;
        }
        *apOut = 0;
        return;
    }
    QPtr444 spNew(new QHead444(apKey, aePriority, apNPC, abA, abB));
    spNew->SetFlag(abFlag);
    spNew->SetParent(apParent);
    spNew->SetPriority(aiArg2);
    *apOut = spNew;
}
}  // namespace fnv_00444350

struct S_00444d40_Class
{
    void QueueModelForObject(int param1, GlobalObject_00528cb0* param2, int param3, int param4, int param5);

    void FUN_00444d40(int param1, int param2, int param3, int param4);
};

// @fnv 0x00444d40
void S_00444d40_Class::FUN_00444d40(int param1, int param2, int param3, int param4)
{
    GlobalObject_00528cb0 local(0);

    QueueModelForObject(param1, &local, param2, param3, param4);
}

struct QueuedHelmetLocal;

struct QHelmetPtr
{
    void* p;
    QHelmetPtr(QueuedHelmetLocal* = 0);
    ~QHelmetPtr();
    QueuedHelmetLocal* operator->() const;
    QHelmetPtr& operator=(QueuedHelmetLocal*);
};

struct QueuedHelmetLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    void SetParent(QueuedFile*);
    QueuedHelmetLocal(FUN_0043f010* a1, int a2, int a3);
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
};

struct QHelmetQueue
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(NiRenderer* ref, QHelmetPtr* ptr);
    virtual void v3();
    virtual bool Add(NiRenderer* ref, QHelmetPtr* ptr, bool flag);
};

struct QHelmetDest
{
    void Assign(const QHelmetPtr&);
};

struct FUN_004450c0_holder : public ModelLoader
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    QHelmetQueue* m_pPrimaryTaskProcessor;

    void FUN_004450c0(FUN_0043f010* a1, QHelmetDest* a2, int a3, QueuedFile* a4, int a5);
};

// Looks up a queued helmet for a1's renderer, creates and adds one if missing, then assigns it to a2.
// @fnv 0x004450c0
void FUN_004450c0_holder::FUN_004450c0(FUN_0043f010* a1, QHelmetDest* a2, int a3, QueuedFile* a4, int a5)
{
    QHelmetPtr ptr(0);
    if (!this->m_pPrimaryTaskProcessor->Lookup(a1->Get(), &ptr))
    {
        ptr = new QueuedHelmetLocal(a1, a3, a5);
        if (this->m_pPrimaryTaskProcessor->Add(a1->Get(), &ptr, false))
        {
            ptr->SetParent(a4);
            ptr->vfn_20();
        }
        else
        {
            ptr = 0;
        }
    }
    a2->Assign(ptr);
}

struct FUN_00445430_obj
{
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int a1, void* pGuard);
};

struct LoadScopeGuard : public S_0042f730
{
    LoadScopeGuard(AC_0042f730* p)
    {
        FUN_00528cb0(p);
    }
    int FUN_00559450(int a1);
    ~LoadScopeGuard();
};

struct FUN_00445430_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00445430_obj* m_14;
    void FUN_00445430(unsigned int a1);
};

struct FUN_0044ac40_s
{
    void FUN_0044ac40(int a1);
};

LoadScopeGuard::~LoadScopeGuard()
{
    FUN_0044cbf0((void**)this);
}

// @fnv 0x00445430
void FUN_00445430_cls::FUN_00445430(unsigned int a1)
{
    LoadScopeGuard guard(0);
    if (m_14->v2(a1, &guard))
    {
        ((FUN_0044ac40_s*)DAT_01202d98)->FUN_0044ac40(guard.FUN_00559450(0));
    }
}

namespace fnv_00445570 {
struct FUN_00445570_obj
{
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int a1, void* pGuard);
};

struct FUN_00445570_obj2
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned int a1);
};

struct LoadScopeGuard : public S_0042f730
{
    LoadScopeGuard(AC_0042f730* p)
    {
        FUN_00528cb0(p);
    }
    int FUN_00559450(int a1);
    ~LoadScopeGuard();
};

struct FUN_00445570_cls
{
    int unk00;
    int unk04;
    FUN_00445570_obj* m_08;
    FUN_00445570_obj2* m_0c;
    int unk10;
    int unk14;
    FUN_00445570_obj* m_18;
    void FUN_00445570(unsigned int a1);
};

struct FUN_0044ac40_s
{
    void FUN_0044ac40(int a1);
};

LoadScopeGuard::~LoadScopeGuard()
{
    FUN_0044cbf0((void**)this);
}

// @fnv 0x00445570
void FUN_00445570_cls::FUN_00445570(unsigned int a1)
{
    LoadScopeGuard guardA(0);
    if (m_08->v2(a1, &guardA))
    {
        ((FUN_0044ac40_s*)DAT_01202d98)->FUN_0044ac40(guardA.FUN_00559450(0));
        m_0c->v5(a1);
    }
    LoadScopeGuard guardB(0);
    if (m_18->v2(a1, &guardB))
    {
        ((FUN_0044ac40_s*)DAT_01202d98)->FUN_0044ac40(guardB.FUN_00559450(0));
    }
}
}  // namespace fnv_00445570

int strcpy_s(char*, unsigned int, const char*);
int strcat_s(char*, unsigned int, const char*);
int _strnicmp(const char*, const char*, unsigned int);
int sprintf(char*, const char*, ...);
char* FUN_0040ab30(char*, int);
unsigned int BSStringLength(const char*);
struct AnimList
{
    char* item;
    AnimList* next;
    AnimList();
    ~AnimList();
    void AddHead(char*&);
};
struct AnimNode
{
    char*& GetItem();
    AnimNode* GetNext();
};
struct Weapon445
{
    int GetType();
};
struct Actor445
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
    virtual bool IsActor();
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
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual bool IsChild(int);
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual bool IsCharacter();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual bool IsSpecial(int);
    Weapon445* GetLoadedForm();
    int GetSex();
    void* GetRace();
};
extern int weaponAnimTypes[];
extern const char* DAT_011977a4[];
struct AnimManager445
{
    void* Load(char*, int, AnimList*);
};
extern AnimManager445* DAT_011cb6a0;
struct GlobalLoader445
{
    void Register(void*);
};

struct AnimLoader445
{
    AnimList* MakeList(char*, char*, int);
    AnimList* MakeRaceList(char*, int, int, void*);
    void QueueList(AnimList*, int, int, char*);
    void QueueModelAnimations(TESModel*, int, int, Actor445*, bool, bool);
};
// @fnv 0x00445a10
void AnimLoader445::QueueModelAnimations(TESModel* model, int priority, int queued, Actor445* actor, bool useSkeleton,
                                         bool forceSkeleton)
{
    char idleSlash[260];
    strcpy_s(idleSlash, 260, model->GetModelPath());
    {
        Actor445* actorCast;
        char* skeletonSlash = FUN_0040ab30(idleSlash, 92);
        if (actor && actor->IsSpecial(1))
        {
            if (skeletonSlash && !_strnicmp(skeletonSlash + 1, "Skeleton", 8))
            {
                char a[260];
                strcpy_s(a, 260, "Data\\");
                if (_strnicmp(idleSlash, "Meshes\\", 7))
                    strcat_s(a, 260, "Meshes\\");
                strcat_s(a, 260, idleSlash);
                char* extraList;
                extraList = FUN_0040ab30(a, 92);
                strcpy_s(extraList, 260 - (extraList - a), "\\MTIdle.KF");
                AnimList* i;
                i = MakeList(a, idleSlash, 0);
                QueueList(i, priority, queued, 0);
                delete i;
                actorCast = actor->IsActor() ? actor : 0;
                if (actorCast && actorCast->GetLoadedForm())
                {
                    const char* p;
                    p = DAT_011977a4[weaponAnimTypes[actorCast->GetLoadedForm()->GetType()]];
                    if (p && *p)
                    {
                        sprintf(extraList, "\\%sHolster.KF", p);
                        i = MakeList(a, idleSlash, 0);
                        QueueList(i, priority, queued, 0);
                        delete i;
                        sprintf(extraList, "\\PA%sHolster.KF", p);
                        i = MakeList(a, idleSlash, 0);
                        QueueList(i, priority, queued, 0);
                        delete i;
                    }
                }
                strcpy_s(extraList, 260 - (extraList - a), "\\Death.KF");
                i = MakeList(a, idleSlash, 0);
                QueueList(i, priority, queued, 0);
                delete i;
            }
        }
        else
        {
            char* weaponName;
            TESAnimation* n;
            weaponName = FUN_0040ab30(idleSlash, 92);
            const int loadFlags = 0;
            if (((weaponName && !_strnicmp(1 + weaponName, "Skeleton", 8)) || forceSkeleton) && useSkeleton)
            {
                void* raceContext;
                raceContext = 0;
                if (actor && actor->IsActor())
                {
                    Actor445* filename = actor;
                    raceContext = filename->GetRace();
                }
                AnimList* skeletonAnimations;
                skeletonAnimations = MakeRaceList(idleSlash, 1, 1, raceContext);
                QueueList(skeletonAnimations, priority, queued, 0);
                delete skeletonAnimations;
            }
            else if (actor->IsCharacter())
            {
                char b[260];
                strcpy_s(b, 260, idleSlash);
                char* directorySlash;
                directorySlash = FUN_0040ab30(b, 92);
                if (actor->IsChild(1))
                    strcpy_s(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Child\\IdleAnims");
                else if (actor->GetSex() == 1)
                    strcpy_s(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Female\\IdleAnims");
                else
                    strcpy_s(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Male\\IdleAnims");
                AnimList* idleAnimations;
                idleAnimations = new AnimList;
                ((GlobalLoader445*)g_modelLoader)->Register(DAT_011cb6a0->Load(b, loadFlags, idleAnimations));
                QueueList(idleAnimations, priority, queued, 0);
                delete idleAnimations;
            }
            n = dynamic_cast<TESAnimation*>(model);
            if (n && n->HasSpecialAnimations())
            {
                AnimList* pObj;
                pObj = new AnimList;
                AnimNode* race;
                race = (AnimNode*)n->GetKFFileList();
                while (race)
                {
                    unsigned long ptr;
                    const char* animationFile;
                    animationFile = race->GetItem();
                    ptr = BSStringLength(animationFile) + 1;
                    char* copy;
                    copy = new char[ptr];
                    strcpy_s(copy, ptr, animationFile);
                    pObj->AddHead(copy);
                    race = race->GetNext();
                }
                char prefix[260];
                strcpy_s(prefix, 260, model->GetModelPath());
                char* idx;
                idx = FUN_0040ab30(prefix, 92);
                if (idx)
                    strcpy_s(idx, 260 - (idx - prefix), "\\SpecialAnims\\");
                QueueList(pObj, priority, queued, prefix);
                delete pObj;
            }
        }
    }
}

namespace P516 {
struct Task
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Queue();
    virtual void v24();
    virtual void Finish();
    void FUN_00443aa0(Task*);
    void SetFieldCToFive();
    unsigned int GetObjectFlags();
};
struct Group : Task
{
    Group(void*, int);
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
};
struct File : Task
{
    File(const char*, int, void*, Task*);
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
};
struct Ptr
{
    Task* p;
    Ptr(Task*);
    ~Ptr();
    Task* Get();
    void Set(Task*);
};
struct Paths
{
    const char** FUN_006815c0();
    Paths* FUN_00726070();
    void FUN_0063f7b0();
};
struct Owner
{
    void FUN_00490fa0(Task*);
};
struct FileMap
{
    virtual void v0();
    virtual void v4();
    virtual bool Lookup(const char*, Task**);
};
struct GroupMap
{
    virtual void v0();
    virtual void v4();
    virtual bool Lookup(Owner*, Ptr*);
    virtual void vc();
    virtual void Insert(Owner*, Ptr*, int);
};
struct Loader
{
    int unk00;
    FileMap* files;
    int unk08;
    int unk0c;
    int unk10;
    GroupMap* groups;
    void LoadFiles(Paths*, Owner*, int, Task*, const char*);
};
// @fnv 0x004465f0
void Loader::LoadFiles(Paths* apPaths, Owner* owner, int priority, Task* parent, const char* prefix)
{
    if (!apPaths || !owner)
        return;
    Paths* node = apPaths;
    if (node && *node->FUN_006815c0())
    {
        AutoMemContext_1 memory((MEM_CONTEXT)0x33, true,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xe9f);
        Ptr group(0);
        while (node)
        {
            const char* entry = *node->FUN_006815c0();
            if (entry)
            {
                const char* h = entry;
                char p[260];
                if (prefix)
                {
                    strcpy_s(p, 260, prefix);
                    strcat_s(p, 260, entry);
                    h = p;
                }
                Task* a = 0;
                if (files->Lookup(h, &a))
                    owner->FUN_00490fa0(a);
                else
                {
                    if (!group.Get() && !groups->Lookup(owner, &group))
                    {
                        group.Set(new Group(owner, priority));
                    }
                    Ptr i(new File(h, priority, owner, group.Get()));
                    i.Get()->FUN_00443aa0(group.Get());
                    i.Get()->Queue();
                }
                delete entry;
                node->FUN_0063f7b0();
            }
            else
                node = node->FUN_00726070();
        }
        if (group.Get() && group.Get()->GetObjectFlags() > 0)
        {
            group.Get()->FUN_00443aa0(parent);
            groups->Insert(owner, &group, 1);
            group.Get()->SetFieldCToFive();
            group.Get()->Finish();
        }
        else
            group.Set(0);
    }
}
}

namespace fnv_00447330 {
struct FUN_00447300_shell : public ModelLoader
{
    void* FUN_00447300(char*, char*, void*);
};
struct KFGlobal447330
{
    void* FUN_00600700(char*, int);
    void FUN_00600170(char*, void*, int);
};
extern KFGlobal447330* DAT_011cb6a0;
struct KFList447330
{
    ~KFList447330();
    bool _ref_008256d0();
    char** _ref_006815c0();
    void _ref_0063f7b0();
};
char* __cdecl FUN_0040ab30(char*, int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
void __cdecl _Deallocate(void*);

struct FUN_00447330_shell : public ModelLoader
{
    void* FUN_00447330(char* arg0, bool arg1, bool arg2, int arg3);
};

// @fnv 0x00447330
void* FUN_00447330_shell::FUN_00447330(char* apPath, bool abLoadLocomotion, bool arg2, int aiIndex)
{
    AutoMemHelper helper2(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                          0x108e);
    void* retVal_2;
    char buf6[260];
    char* p;
    void* res3;
    if (DAT_011cb6a0 != 0 && DAT_011cb6a0->FUN_00600700(apPath, 0) != 0)
    {
        retVal_2 = 0;
        if (aiIndex == 12)
        {
            int i5;
            for (i5 = 0; (unsigned int)i5 < 12; i5++)
            {
                if (retVal_2 != 0)
                {
                    ((FUN_00447850_shell*)this)->FUN_00447850(DAT_011cb6a0->FUN_00600700(apPath, i5), retVal_2);
                }
                else
                {
                    retVal_2 = ((FUN_00447850_shell*)this)->FUN_00447850(DAT_011cb6a0->FUN_00600700(apPath, i5), 0);
                }
            }
        }
        else if (aiIndex != 0 && arg2)
        {
            retVal_2 = ((FUN_00447850_shell*)this)->FUN_00447850(DAT_011cb6a0->FUN_00600700(apPath, 0), 0);
            ((FUN_00447850_shell*)this)->FUN_00447850(DAT_011cb6a0->FUN_00600700(apPath, aiIndex), retVal_2);
        }
        else
        {
            retVal_2 = ((FUN_00447850_shell*)this)->FUN_00447850(DAT_011cb6a0->FUN_00600700(apPath, aiIndex), 0);
        }
        return retVal_2;
    }
    strcpy_s(buf6, 260, "Data\\Meshes\\");
    strcat_s(buf6, 260, apPath);
    p = FUN_0040ab30(buf6, '\\');
    if (p == 0)
    {
        return 0;
    }
    strcpy_s(p, 260 - (p - buf6), "\\*.KF");
    res3 = ((FUN_00447300_shell*)this)->FUN_00447300(buf6, apPath, 0);
    if (abLoadLocomotion && BSStringLength(apPath))
    {
        char buf3[260];
        char* pA;
        KFList447330* res4;
        strcpy_s(buf3, 260, apPath);
        pA = FUN_0040ab30(buf3, '\\');
        if (pA != 0)
        {
            *pA = 0;
            strcat_s(pA, 260 - (pA - buf3), "\\Locomotion\\");
            strcpy_s(p, 260 - (p - buf6), "\\Locomotion\\*.KF");
            if (res3 == 0)
            {
                res3 = ((FUN_00447300_shell*)this)->FUN_00447300(buf6, buf3, 0);
            }
            else
            {
                ((FUN_00447300_shell*)this)->FUN_00447300(buf6, buf3, res3);
            }
            strcat_s(pA, 260 - (pA - buf3), "Hurt\\");
            strcat_s(pA, 260 - (pA - buf3), "IdleAnims");
            strcpy_s(p, 260 - (p - buf6), "\\Locomotion\\Hurt\\*.KF");
            res4 = (KFList447330*)((FUN_00447300_shell*)this)->FUN_00447300(buf6, buf3, 0);
            if (res4 != 0)
            {
                DAT_011cb6a0->FUN_00600170(buf3, res4, 1);
                while (!res4->_ref_008256d0())
                {
                    char* head = *res4->_ref_006815c0();
                    delete head;
                    res4->_ref_0063f7b0();
                }
                delete res4;
            }
        }
    }
    DAT_011cb6a0->FUN_00600170(apPath, res3, 0);
    return res3;
}
}  // namespace fnv_00447330

struct MeshSource
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual const char* Path();
};
struct CacheNode
{
};
struct CacheData
{
    int unk00;
    int unk04;
    int ready;
};
struct NodeHandle
{
    CacheNode* value;
    NodeHandle(CacheNode*);
    ~NodeHandle();
    operator CacheNode*() const;
};
struct DataHandle
{
    CacheData* value;
    DataHandle(CacheData*);
    ~DataHandle();
    operator CacheData*() const;
    CacheData* operator->() const;
};
struct MeshName
{
    char* data;
    short length;
    short capacity;
    MeshName();
    ~MeshName();
    operator const char*() const;
};
struct MeshCache
{
    bool LookupModelAndGetFlags(const char*, NodeHandle*, DataHandle*);
};
MeshCache* FUN_00652110();
void BuildEgmFilename(MeshName*, const char*, int);
struct MeshTask
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void Queue();
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
    MeshTask(CacheNode*, CacheData*);
    void SetParent(void*);
};
struct TaskHandle
{
    MeshTask* value;
    TaskHandle(MeshTask*);
    ~TaskHandle();
    operator MeshTask*() const;
    MeshTask* operator->() const;
};
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
void* operator new(unsigned int);
struct MeshLoader
{
    void FUN_00447a40(const char*, int, void*, int);
    void LoadMesh(MeshSource*, int, void*, int);
};
// Builds a Meshes\ path from source->Path(), looks up cached mesh data for each variant and queues a MeshTask, otherwise loads it via FUN_00447a40.
// @fnv 0x00447bf0
void MeshLoader::LoadMesh(MeshSource* source, int priority, void* parent, int kind)
{
    NodeHandle node2(0);
    DataHandle data7(0);
    char path2[260];
    FUN_00406d30(path2, 260, "Meshes\\");
    FUN_00406d50(path2, 260, source->Path());
    if (kind == 9)
    {
        for (int index = 0; index < 2; index++)
        {
            MeshName name;
            BuildEgmFilename(&name, path2, index);
            if (FUN_00652110() && FUN_00652110()->LookupModelAndGetFlags(name, &node2, &data7) && node2 && data7 &&
                ((CacheData*)data7)->ready)
            {
                if (parent)
                {
                    TaskHandle task(new MeshTask(node2, data7));
                    ((MeshTask*)task)->SetParent(parent);
                    ((MeshTask*)task)->Queue();
                }
                continue;
            }
            FUN_00447a40(name, priority, parent, 1);
        }
    }
    else
    {
        MeshName other5;
        BuildEgmFilename(&other5, path2, -1);
        if (FUN_00652110() && FUN_00652110()->LookupModelAndGetFlags(other5, &node2, &data7) && node2 && data7 &&
            ((CacheData*)data7)->ready)
        {
            if (parent)
            {
                TaskHandle taskOther4(new MeshTask(node2, data7));
                ((MeshTask*)taskOther4)->SetParent(parent);
                ((MeshTask*)taskOther4)->Queue();
            }
            return;
        }
        FUN_00447a40(other5, priority, parent, 1);
    }
}

struct RecursiveModelNode;
struct RecursiveModelChild
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual RecursiveModelNode* GetNode();
};
struct RecursiveModelNode
{
    unsigned int GetFormID();
    unsigned int GetChildCount();
    RecursiveModelChild* GetChild(unsigned int index);
};
struct ModelPathComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* GetPath();
};
struct ModelForm
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    ModelPathComponent model;
    bool Skip();
};
struct ModelFormLookup
{
    ModelForm* Find(unsigned int id);
};
extern ModelFormLookup* DAT_011c3f2c;
extern int DAT_01202de8;
bool __cdecl FUN_0043b300(const void* type, const RecursiveModelNode* node);

struct RecursiveModelLoader
{
    ModelMapStub* models;
    ModelStub* Load(const char* path, bool a, bool b, int c, int d, int e);
    void LoadModelTree(RecursiveModelNode* node);
};

// Recursively loads models for a node and its children: looks up the node's form, loads its model path if missing, then recurses into child nodes.
// @fnv 0x00448a90
void RecursiveModelLoader::LoadModelTree(RecursiveModelNode* node)
{
    if (!node)
        return;
    if (FUN_0043b300(&DAT_01202de8, node))
    {
        RecursiveModelNode* object = node;
        ModelForm* form = DAT_011c3f2c->Find(object->GetFormID());
        if (form && !form->Skip())
        {
            ModelStub* model = 0;
            if (!models->Lookup(form->model.GetPath(), &model))
            {
                if (Load(form->model.GetPath(), false, true, 0, 0, 0))
                {
                    if (models->Lookup(form->model.GetPath(), &model))
                        model->ReleaseScriptRunLock();
                }
            }
        }
    }
    for (unsigned int index = 0; index < node->GetChildCount(); ++index)
    {
        RecursiveModelChild* child = node->GetChild(index);
        if (child)
        {
            RecursiveModelNode* nested = child->GetNode();
            if (nested)
                LoadModelTree(nested);
        }
    }
}

struct R449_b
{
    bool TryInsertAndFinish();
};

struct Q449_b
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RecursiveSpinLock lock;
    R449_b* FUN_00449f80(void* a1, int* a2);
    bool FUN_00449700(void* a1, int a2);
};

// Locks the lock, calls FUN_00449f80 with a1 and a2, invokes TryInsertAndFinish on the result, unlocks, and returns that bool.
// @fnv 0x00449700
bool Q449_b::FUN_00449700(void* a1, int iValue)
{
    lock.Lock(0);
    bool res = FUN_00449f80(a1, &iValue)->TryInsertAndFinish();
    lock.Unlock();
    return res;
}

class C44D510Object;

class C44D510Pointer
{
  public:
    C44D510Pointer& operator=(const C44D510Pointer& kOther);

    C44D510Object* m_pPointer;
};

class C44D510Entry
{
  public:
    bool IsPendingRemoval();

    int unk00;
    C44D510Pointer m_spValue;
};

class C44D510Iterator
{
  public:
    C44D510Entry* Get();
};

void __cdecl C44D510Yield();

class C44D510Cache
{
  public:
    bool Find(unsigned int uiKey, unsigned int uiHash);
    void Unlock();

    bool LookupAndUnlock(unsigned int uiKey, unsigned int uiHash, C44D510Pointer& spResult);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C44D510Iterator m_kIterator;
};

// Finds the entry for uiKey/uiHash, copies its value into spResult, yields, and unlocks; returns false if the entry is pending removal.
// @fnv 0x0044d510
bool C44D510Cache::LookupAndUnlock(unsigned int uiKey, unsigned int uiHash, C44D510Pointer& spResult)
{
    bool bFound = Find(uiKey, uiHash);
    if (bFound)
    {
        spResult = m_kIterator.Get()->m_spValue;
        C44D510Yield();
        if (m_kIterator.Get()->IsPendingRemoval())
            bFound = false;
    }
    Unlock();
    return bFound;
}

void __cdecl FUN_0040fbe0();
struct Traversal : Worker
{
    bool FindKeyInTraversal(int index, const int* key);
};
// Walks the traversal's linked nodes, syncing state, and returns true when a node's observed value equals *key.
// @fnv 0x0044e820
bool Traversal::FindKeyInTraversal(int index, const int* key)
{
    int* head = reinterpret_cast<int*>(reinterpret_cast<FUN_0044ee20_class*>(controller)->GetElementAddress(index));
    while (true)
    {
        bool initial = false;
        state = head;
        current = *reinterpret_cast<NodeLink*>(state);
        *reinterpret_cast<SyncNode**>(unk08) = current.ClearLowBit();
        FUN_0040fbe0();
        StateValue retry;
        retry.FUN_006ecba0(false, current.ClearLowBit());
        if (FUN_00559450(state) != retry.FUN_00559450())
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *reinterpret_cast<NodeLink*>(&current.FUN_0044df00()->state);
            *reinterpret_cast<SyncNode**>(unk04) = pending.ClearLowBit();
            FUN_0040fbe0();
            if (FUN_00559450(reinterpret_cast<int*>(&pending)) != FUN_00559450(&current.FUN_0044df00()->state))
            {
                initial = true;
                break;
            }
            int observed = current.ClearLowBit()->unk04;
            StateValue value;
            value.FUN_006ecba0(false, current.ClearLowBit());
            if (FUN_00559450(state) != value.FUN_00559450())
            {
                initial = true;
                break;
            }
            if (!FUN_0044dff0(reinterpret_cast<int*>(&pending)))
            {
                if (observed == *key)
                    return true;
                state = &current.FUN_0044df00()->state;
                *reinterpret_cast<SyncNode**>(unk0c) = current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                StateValue next;
                next.FUN_006ecba0(false, pending.ClearLowBit());
                if (FUN_004491c0(state, next.FUN_00559450(), value.FUN_00559450()))
                {
                    AddRace(current.ClearLowBit());
                }
                else
                {
                    initial = true;
                    break;
                }
            }
            current = pending;
            *reinterpret_cast<SyncNode**>(unk08) = pending.ClearLowBit();
            FUN_0040fbe0();
        }
        if (initial)
            continue;
    }
}

class B44F890Setting
{
  public:
    void FUN_00c33280(int iArg);
};

class B44F890Node
{
  public:
    B44F890Setting** GetItem();
};

class B44F890Collection
{
  public:
    B44F890Node* GetFirstNode();
    B44F890Node* GetNextNode(B44F890Node* pkNode);
    int FUN_0044f890(int iArg);
};

// @fnv 0x0044f890
int B44F890Collection::FUN_0044f890(int iArg)
{
    AutoMemHelper kMemHelper(9, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\Setting.h", 0x326);
    B44F890Node* pkNode = GetFirstNode();
    int iCount = 0;
    while (pkNode)
    {
        (*pkNode->GetItem())->FUN_00c33280(iArg);
        pkNode = GetNextNode(pkNode);
        iCount++;
    }
    return iCount;
}

struct FUN_00490fa0_lk
{
    FUN_00490fa0_lk(int v);
    ~FUN_00490fa0_lk();
    int v;
};

struct FUN_00490fa0_src
{
    int FUN_005585e0();
};

struct FUN_00490fa0_dst
{
    void FUN_00905820(FUN_00490fa0_src** pp);
};

class FUN_00490fa0_cls
{
  public:
    void FUN_00490fa0(FUN_00490fa0_src* p);
};

// @fnv 0x00490fa0
void FUN_00490fa0_cls::FUN_00490fa0(FUN_00490fa0_src* pSource)
{
    FUN_00490fa0_lk lk(pSource->FUN_005585e0());
    if (FUN_00559450((int*)&lk) == 0)
        return;
    FUN_0043be10((char*)pSource);
    FUN_0043be10((char*)pSource);
    reinterpret_cast<FUN_00490fa0_dst*>((char*)this + 0x104)->FUN_00905820(&pSource);
}

struct SearchController
{
    int GetElementAddress(int);
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual bool Accept(int, int);
    virtual bool Finish(int, int);
};
void __cdecl FUN_0040fbe0();
struct SearchWorker
{
    SearchController* controller;
    SyncNode** pendingGuard;
    SyncNode** currentGuard;
    SyncNode** removedGuard;
    int* state;
    NodeLink current;
    NodeLink pending;
    void FUN_005292a0(SyncNode*);
    bool ProcessNode(int key, int output);
};
// Walks the node chain from controller->GetElementAddress(key), validating links and calling controller->Accept/Finish or FUN_005292a0 on each node.
// @fnv 0x00529030
bool SearchWorker::ProcessNode(int key, int output)
{
    int* head = (int*)controller->GetElementAddress(key);
    while (true)
    {
        bool p = false;
        state = head;
        current = *(NodeLink*)state;
        *currentGuard = current.ClearLowBit();
        FUN_0040fbe0();
        StateValue j;
        j.FUN_006ecba0(false, current.ClearLowBit());
        if (FUN_00559450(state) != j.FUN_00559450())
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *(NodeLink*)&current.FUN_0044df00()->state;
            *pendingGuard = pending.ClearLowBit();
            FUN_0040fbe0();
            if (FUN_00559450((int*)&pending) != FUN_00559450(&current.FUN_0044df00()->state))
            {
                p = true;
                break;
            }
            int e = current.ClearLowBit()->unk00;
            StateValue h;
            h.FUN_006ecba0(false, current.ClearLowBit());
            if (FUN_00559450(state) != h.FUN_00559450())
            {
                p = true;
                break;
            }
            if (!FUN_0044dff0((int*)&pending))
            {
                if (controller->Accept(e, output))
                    return controller->Finish(e, output);
                state = &current.FUN_0044df00()->state;
                *removedGuard = current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                StateValue desired;
                desired.FUN_006ecba0(false, pending.ClearLowBit());
                if (FUN_004491c0(state, desired.FUN_00559450(), h.FUN_00559450()))
                    FUN_005292a0(current.ClearLowBit());
                else
                {
                    p = true;
                    break;
                }
            }
            current = pending;
            *currentGuard = pending.ClearLowBit();
            FUN_0040fbe0();
        }
        if (p)
            continue;
    }
}

struct Form3;
struct Cell3;
struct Render3;
struct Other3;
struct Position3;
struct Radio3;
struct Ref3;
struct Obj3;
struct Proc3;
struct Vec3s
{
    float x, y, z;
};
struct Mat3s
{
    float a, b, c, d, e, f, g, h, i;
    Mat3s();
};
struct Fixed3
{
    operator const char*() const;
};
struct Ptr3
{
    Obj3* p;
    Ptr3(Obj3*);
    ~Ptr3();
    operator Obj3*() const;
    Ptr3& operator=(Obj3*);
};
struct Text3
{
    char* p;
    Text3();
    operator char*() const;
    void SaveHavok(Ref3*);
    void SaveAnim(Ref3*);
};
struct Flags3
{
    int bits;
    Flags3(int);
    Flags3(const Flags3&);
};
struct Extra3
{
    void* Primitive();
    float Modifier();
    void SetSavedHavokData(char*);
    void SetSavedAnimation(char*);
};
struct Prim3
{
    void Clear();
};
struct Update3
{
    float time;
    bool a, b;
    int flags;
    Update3(float, bool, bool);
};
struct Obj3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual Obj3* AsNode();
    virtual Obj3* AsOther();
    Obj3* Parent();
    Fixed3& GetName();
    Vec3s& Position();
    Mat3s& Rotation();
    float Scale();
    bool HasCollision();
    void AssignReference(Ref3*);
    bool Cleanup();
    void Clear();
    void SetPos(const Vec3s&);
    void SetRot(const Mat3s*);
    void SetScale(float);
    void Post();
    void Update(Update3&);
};
struct Proc3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual void unused15c();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual void unused1d0();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void unused1f0();
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual void unused224();
    virtual void unused228();
    virtual void unused22c();
    virtual void unused230();
    virtual void unused234();
    virtual void unused238();
    virtual void unused23c();
    virtual void unused240();
    virtual void unused244();
    virtual void unused248();
    virtual void unused24c();
    virtual void unused250();
    virtual void unused254();
    virtual void unused258();
    virtual void unused25c();
    virtual void unused260();
    virtual void unused264();
    virtual void unused268();
    virtual void unused26c();
    virtual void unused270();
    virtual void unused274();
    virtual void unused278();
    virtual void unused27c();
    virtual void unused280();
    virtual void unused284();
    virtual void unused288();
    virtual void unused28c();
    virtual void unused290();
    virtual void unused294();
    virtual void unused298();
    virtual void unused29c();
    virtual void unused2a0();
    virtual void unused2a4();
    virtual void unused2a8();
    virtual void unused2ac();
    virtual void unused2b0();
    virtual void unused2b4();
    virtual void unused2b8();
    virtual void unused2bc();
    virtual void unused2c0();
    virtual void unused2c4();
    virtual void unused2c8();
    virtual void unused2cc();
    virtual void unused2d0();
    virtual void unused2d4();
    virtual void unused2d8();
    virtual void unused2dc();
    virtual void unused2e0();
    virtual void unused2e4();
    virtual void unused2e8();
    virtual void unused2ec();
    virtual void unused2f0();
    virtual void unused2f4();
    virtual void unused2f8();
    virtual void unused2fc();
    virtual void unused300();
    virtual void unused304();
    virtual void unused308();
    virtual void unused30c();
    virtual void unused310();
    virtual void unused314();
    virtual void unused318();
    virtual void unused31c();
    virtual void unused320();
    virtual void unused324();
    virtual void unused328();
    virtual void unused32c();
    virtual void unused330();
    virtual void unused334();
    virtual void unused338();
    virtual void unused33c();
    virtual void unused340();
    virtual void unused344();
    virtual void unused348();
    virtual void unused34c();
    virtual void unused350();
    virtual void unused354();
    virtual void unused358();
    virtual void unused35c();
    virtual void unused360();
    virtual void unused364();
    virtual void unused368();
    virtual void unused36c();
    virtual void unused370();
    virtual void unused374();
    virtual void unused378();
    virtual void unused37c();
    virtual void unused380();
    virtual void unused384();
    virtual void unused388();
    virtual void unused38c();
    virtual void unused390();
    virtual void unused394();
    virtual void unused398();
    virtual void unused39c();
    virtual void unused3a0();
    virtual void unused3a4();
    virtual void unused3a8();
    virtual void unused3ac();
    virtual void unused3b0();
    virtual void unused3b4();
    virtual void unused3b8();
    virtual void unused3bc();
    virtual void unused3c0();
    virtual void unused3c4();
    virtual void unused3c8();
    virtual void unused3cc();
    virtual void unused3d0();
    virtual void unused3d4();
    virtual void unused3d8();
    virtual void unused3dc();
    virtual void unused3e0();
    virtual void unused3e4();
    virtual void unused3e8();
    virtual void unused3ec();
    virtual void unused3f0();
    virtual void unused3f4();
    virtual void unused3f8();
    virtual void unused3fc();
    virtual void unused400();
    virtual void unused404();
    virtual void unused408();
    virtual void unused40c();
    virtual void unused410();
    virtual void unused414();
    virtual void unused418();
    virtual void unused41c();
    virtual void unused420();
    virtual void unused424();
    virtual void unused428();
    virtual void unused42c();
    virtual void unused430();
    virtual void unused434();
    virtual void unused438();
    virtual void unused43c();
    virtual void unused440();
    virtual void unused444();
    virtual void unused448();
    virtual void unused44c();
    virtual void unused450();
    virtual void unused454();
    virtual void unused458();
    virtual void unused45c();
    virtual void unused460();
    virtual void unused464();
    virtual void unused468();
    virtual void unused46c();
    virtual void unused470();
    virtual void unused474();
    virtual void unused478();
    virtual void unused47c();
    virtual void unused480();
    virtual void unused484();
    virtual void unused488();
    virtual void unused48c();
    virtual void unused490();
    virtual void unused494();
    virtual void unused498();
    virtual void unused49c();
    virtual void unused4a0();
    virtual void unused4a4();
    virtual void unused4a8();
    virtual void unused4ac();
    virtual void unused4b0();
    virtual void unused4b4();
    virtual void unused4b8();
    virtual void unused4bc();
    virtual void unused4c0();
    virtual void unused4c4();
    virtual void unused4c8();
    virtual void unused4cc();
    virtual void unused4d0();
    virtual void unused4d4();
    virtual void unused4d8();
    virtual void unused4dc();
    virtual void unused4e0();
    virtual void unused4e4();
    virtual void unused4e8();
    virtual void unused4ec();
    virtual void unused4f0();
    virtual void unused4f4();
    virtual void unused4f8();
    virtual void ClearE(int);
    virtual void unused500();
    virtual void unused504();
    virtual void unused508();
    virtual void unused50c();
    virtual void unused510();
    virtual void unused514();
    virtual void unused518();
    virtual void unused51c();
    virtual void unused520();
    virtual void unused524();
    virtual void unused528();
    virtual void unused52c();
    virtual void unused530();
    virtual void unused534();
    virtual void unused538();
    virtual void unused53c();
    virtual void unused540();
    virtual void unused544();
    virtual void unused548();
    virtual void unused54c();
    virtual void unused550();
    virtual void unused554();
    virtual void unused558();
    virtual void unused55c();
    virtual void unused560();
    virtual void unused564();
    virtual void unused568();
    virtual void unused56c();
    virtual void unused570();
    virtual void unused574();
    virtual void unused578();
    virtual void unused57c();
    virtual void unused580();
    virtual void unused584();
    virtual void unused588();
    virtual void unused58c();
    virtual void unused590();
    virtual void unused594();
    virtual void unused598();
    virtual void unused59c();
    virtual void unused5a0();
    virtual void unused5a4();
    virtual void unused5a8();
    virtual void unused5ac();
    virtual void unused5b0();
    virtual void unused5b4();
    virtual void unused5b8();
    virtual void unused5bc();
    virtual void unused5c0();
    virtual void unused5c4();
    virtual void unused5c8();
    virtual void unused5cc();
    virtual void unused5d0();
    virtual void unused5d4();
    virtual void unused5d8();
    virtual void unused5dc();
    virtual void unused5e0();
    virtual void unused5e4();
    virtual void unused5e8();
    virtual void unused5ec();
    virtual void unused5f0();
    virtual void ClearD(int);
    virtual void unused5f8();
    virtual void unused5fc();
    virtual void unused600();
    virtual void unused604();
    virtual void unused608();
    virtual void unused60c();
    virtual void unused610();
    virtual void unused614();
    virtual void unused618();
    virtual void unused61c();
    virtual void unused620();
    virtual void unused624();
    virtual void unused628();
    virtual void unused62c();
    virtual void unused630();
    virtual void unused634();
    virtual void unused638();
    virtual void unused63c();
    virtual void unused640();
    virtual void unused644();
    virtual void unused648();
    virtual void unused64c();
    virtual void unused650();
    virtual void unused654();
    virtual void unused658();
    virtual void unused65c();
    virtual void unused660();
    virtual void unused664();
    virtual void unused668();
    virtual void unused66c();
    virtual void unused670();
    virtual void unused674();
    virtual void unused678();
    virtual void unused67c();
    virtual void unused680();
    virtual void unused684();
    virtual void unused688();
    virtual void unused68c();
    virtual void unused690();
    virtual void unused694();
    virtual void unused698();
    virtual void unused69c();
    virtual void unused6a0();
    virtual void unused6a4();
    virtual void unused6a8();
    virtual void unused6ac();
    virtual void unused6b0();
    virtual void unused6b4();
    virtual void unused6b8();
    virtual void unused6bc();
    virtual void unused6c0();
    virtual void unused6c4();
    virtual void unused6c8();
    virtual void unused6cc();
    virtual void unused6d0();
    virtual void unused6d4();
    virtual void unused6d8();
    virtual void unused6dc();
    virtual void unused6e0();
    virtual void unused6e4();
    virtual void unused6e8();
    virtual void unused6ec();
    virtual void unused6f0();
    virtual void unused6f4();
    virtual void unused6f8();
    virtual void unused6fc();
    virtual void unused700();
    virtual void unused704();
    virtual void unused708();
    virtual void unused70c();
    virtual void unused710();
    virtual void unused714();
    virtual void unused718();
    virtual void unused71c();
    virtual void unused720();
    virtual void unused724();
    virtual void unused728();
    virtual void unused72c();
    virtual void unused730();
    virtual void unused734();
    virtual void unused738();
    virtual void unused73c();
    virtual void unused740();
    virtual void unused744();
    virtual void unused748();
    virtual void unused74c();
    virtual void unused750();
    virtual void unused754();
    virtual void unused758();
    virtual void unused75c();
    virtual void unused760();
    virtual void unused764();
    virtual void unused768();
    virtual void unused76c();
    virtual void unused770();
    virtual void unused774();
    virtual void unused778();
    virtual void unused77c();
    virtual void unused780();
    virtual void unused784();
    virtual void unused788();
    virtual void unused78c();
    virtual void unused790();
    virtual void ClearB(int);
    virtual void unused798();
    virtual void ClearA(int);
    virtual void unused7a0();
    virtual void ClearC(int);
    void Reset();
    int Level();
};
struct Parent3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void Attach(Obj3*, bool);
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void Detach(Obj3*);
};
struct Delete3
{
    virtual ~Delete3();
};
struct Ref3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void Mark(int);
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual bool IsSpecial();
    virtual bool IsActor();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual bool IsObstacle();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual Obj3* SoundObject();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void ClearSlot(int);
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual bool HasSound();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    Form3* base;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    Cell3* cell;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    Render3* render;
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
    Delete3* owned;
    Other3* other;
    void Set3D(Obj3*, bool);
    Obj3* Get3DSimple();
    Proc3* Process();
    int ProcessLevel();
    Extra3* Extras();
    void UpdateReferenceTransform();
    Position3* Transform();
    float GetScale();
    bool HasModifier();
    Form3* GetBase();
    bool Temporary();
    bool IsDeleted();
    void CleanupState();
    bool SaveAnimation();
    void ClearX(int);
    void ClearY(int);
    void ActorCleanup();
    void ActorZero(int);
    void EmptyA();
    void EmptyB();
    void SetFlag(unsigned int, bool);
    Other3* Physics();
    void Changed(bool);
    bool Flag(unsigned int);
    void Set3D(Obj3*);
    bool NeedsReload();
    void SetLoaded(bool);
    Radio3* Radio();
};
struct Form3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void Notify(Ref3*);
    int Type();
};
struct Cell3
{
    bool Active();
};
struct Render3
{
    int a, b, c, d, e;
    Ptr3 object;
};
struct Other3
{
    void Clear(int);
    void Reset();
};
struct Position3
{
    int a, b, c, d;
    Vec3s position;
};
struct Radio3
{
    Radio3* Cell();
    void Clear(int);
};
struct Loader3
{
    void Remove(Ref3*);
};
struct Queue3
{
    void Detach(Obj3*);
};
struct Scene3
{
    void RemoveObject(Obj3*);
    void RemoveSpecial(Obj3*);
};
struct World3
{
    void Remove(Ref3*);
};
struct Vats3
{
    void Remove(Ref3*);
};
struct Save3
{
    bool GetAllowChanges();
    bool Has(Ref3*, Flags3);
};
struct Load3
{
    bool GetLoading();
};
struct Audio3
{
    void Remove(Obj3*, float, bool);
};
struct Nav3
{
    void Add(Ref3*);
    void Remove(Ref3*);
    void Update(Ref3*);
};
struct BaseState3
{
    void Off();
    void On(Form3*);
};

extern Save3* g_BGSSaveLoadGame;
extern Load3* g_TESSaveLoadGame;
extern World3 DAT_011e0e80;
extern Vats3 DAT_011f2250;
extern Ref3* _g_thePlayer;
void FNV_Warning(const char*, ...);
bool FUN_008c7aa0();
Queue3* FUN_004537b0();
Scene3* FUN_00450b80(int);
BaseState3* FUN_00475400(Form3*);
void FUN_00578250(Obj3*);
bool FUN_005784b0(Obj3*);
void FUN_00578300(Obj3*);
int FUN_00570f60();
void FUN_008cddd0(Ref3*, bool);
void FUN_00868660(Obj3*);
void FUN_00c45830(Obj3*);
void FUN_00c6bd00(Obj3*, bool);
Audio3* FUN_00453a70();
Nav3* GetNav3();
void baseNotify3(Form3*, Ref3*);
// Swaps the reference's 3D object for replacement, detaching and cleaning up the old one and attaching the new one with its saved transform.
// @fnv 0x005702e0
void Ref3::Set3D(Obj3* replacement, bool warn)
{
    if (Get3DSimple() == replacement)
    {
        if (!replacement)
        {
            ((Loader3*)g_modelLoader)->Remove(this);
            SetLoaded(false);
        }
        return;
    }
    if (Get3DSimple() && !Get3DSimple()->Parent())
        ((Loader3*)g_modelLoader)->Remove(this);
    if (render && (Obj3*)render->object && !replacement && IsActor() && Process() && ProcessLevel() <= 1)
    {
        if (warn)
            FNV_Warning("AI: Unloading art for a high or middle high process actor (%s).",
                        ((Obj3*)render->object)->GetName().operator const char*());
        Proc3* process = Process();
        process->ClearA(0);
        process->ClearB(0);
        process->ClearC(0);
        process->Reset();
    }
    if (render)
        render->b = 0;
    Prim3* c = (Prim3*)Extras()->Primitive();
    if (!replacement && c)
        c->Clear();
    if (!replacement)
        UpdateReferenceTransform();
    Vec3s e = Transform()->position;
    Mat3s rotation4;
    float scale4 = GetScale();
    Parent3* parentTmp = 0;
    Ref3* actor17 = 0;
    if (IsActor())
        actor17 = this;
    if (Get3DSimple() && replacement && base && base->Type() == 0x25)
        return;
    if (HasModifier() && Extras()->Modifier() != 0.0)
    {
        if (Get3DSimple() && !replacement)
            FUN_00475400(GetBase())->Off();
        else if (replacement && !Get3DSimple())
            FUN_00475400(GetBase())->On(GetBase());
    }
    Ptr3 oldVar(Get3DSimple());
    if ((Obj3*)oldVar)
    {
        parentTmp = (Parent3*)((Obj3*)oldVar)->Parent();
        if (parentTmp)
        {
            if (!(Temporary() && base && base->Type() == 0x25))
            {
                if (FUN_008c7aa0())
                    FUN_004537b0()->Detach(oldVar);
                else
                    parentTmp->Detach(oldVar);
            }
            e = ((Obj3*)oldVar)->Position();
            rotation4 = ((Obj3*)oldVar)->Rotation();
            scale4 = ((Obj3*)oldVar)->Scale();
        }
        FUN_00450b80(0)->RemoveObject(oldVar);
        if (IsSpecial())
            FUN_00450b80(0)->RemoveSpecial(oldVar);
        if (!replacement)
        {
            bool cleaned = false;
            Obj3* otherObj = ((Obj3*)oldVar)->AsOther();
            if (otherObj)
            {
                otherObj->AssignReference(0);
                cleaned = otherObj->Cleanup();
            }
            if (((Obj3*)oldVar)->HasCollision())
                FUN_00578250(((Obj3*)oldVar)->AsNode());
            CleanupState();
            DAT_011f2250.Remove(this);
            if (!IsDeleted() && g_BGSSaveLoadGame->GetAllowChanges())
            {
                if (g_BGSSaveLoadGame->Has(this, Flags3(4)))
                {
                    Text3 data;
                    data.SaveHavok(this);
                    Extras()->SetSavedHavokData(data);
                }
                if (g_BGSSaveLoadGame->Has(this, Flags3(0x10000000)))
                {
                    bool save = false;
                    if (!IsActor())
                        save = SaveAnimation();
                    if (save)
                    {
                        Text3 data;
                        data.SaveAnim(this);
                        Extras()->SetSavedAnimation(data);
                    }
                    else
                        Mark(0x10000000);
                }
            }
            ClearX(0);
            ClearY(0);
            if (actor17)
            {
                ActorCleanup();
                ActorZero(0);
                EmptyA();
                EmptyB();
            }
            ClearSlot(0);
            bool collision9 = FUN_005784b0(((Obj3*)oldVar)->AsNode());
            SetFlag(2, collision9);
            if (collision9)
                FUN_00578300(oldVar);
            if (actor17)
            {
                Ref3* ref = this;
                if (ref)
                {
                    Other3* physics = ref->Physics();
                    if (physics)
                        physics->Clear(0);
                    if (ref->Process())
                        ref->Process()->ClearD(0);
                }
                if (actor17->owned)
                {
                    delete actor17->owned;
                    actor17->owned = 0;
                }
                if (actor17->other)
                    actor17->other->Reset();
            }
            if (cleaned || HasSound() || IsSpecial())
                FUN_00453a70()->Remove(SoundObject(), 0.0f, false);
            Changed(true);
        }
        if (!cell || !cell->Active())
        {
            DAT_011e0e80.Remove(this);
            if (FUN_00570f60() > 0)
                FUN_008cddd0(this, true);
        }
        if (actor17 && actor17 != _g_thePlayer)
        {
            Proc3* process = actor17->Process();
            if (process && process->Level() <= 1)
            {
                Proc3* high = process;
                high->ClearE(0);
            }
            FUN_00868660(oldVar);
        }
        else
            FUN_00c45830(oldVar);
        bool flag = Flag(4);
        oldVar = 0;
        Set3D(0);
        if (!replacement && base)
        {
            if (!NeedsReload())
            {
                if (!flag)
                    base->Notify(this);
            }
            else
                ((Loader3*)g_modelLoader)->Remove(this);
        }
    }
    else if (!replacement)
        ((Loader3*)g_modelLoader)->Remove(this);
    if (!replacement)
        SetLoaded(false);
    Set3D(replacement);
    if (replacement && parentTmp)
    {
        replacement->SetPos(e);
        replacement->SetRot(&rotation4);
        replacement->SetScale(scale4);
        parentTmp->Attach(replacement, true);
        FUN_00c6bd00(replacement, true);
        replacement->Post();
        Update3 update(0.0f, false, false);
        replacement->Update(update);
    }
    if (replacement && base && base->Type() != 0x25)
        replacement->AssignReference(this);
    if (!g_TESSaveLoadGame->GetLoading() && !replacement && Radio() && Radio()->Cell())
        Radio()->Cell()->Clear(0);
    if (IsObstacle())
    {
        if (replacement)
            GetNav3()->Add(this);
        else
            GetNav3()->Remove(this);
    }
    if (!replacement && GetBase() && GetBase()->Type() == 0x1c)
        GetNav3()->Update(this);
}

struct ControllerV
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual bool Call34(int, int);
    virtual bool Call38(int, int);
};
void FUN_0040fbe0();

// @fnv 0x006662a0
bool Worker::ProcessNodeChain(int a1, int a2)
{
    int head7;
    bool flag_;
    StateValue svA2;
    StateValue svB;
    int nodeVal;
    StateValue svC2;
    head7 = ((FUN_0044ee20_class*)controller)->GetElementAddress(a1);
    while (1)
    {
        flag_ = 0;
        state = (int*)head7;
        current = *(NodeLink*)state;
        *(int*)unk08 = (int)current.ClearLowBit();
        FUN_0040fbe0();
        svA2.FUN_006ecba0(0, current.ClearLowBit());
        if (((StateValue*)state)->FUN_00559450() != svA2.FUN_00559450())
            continue;
        while (1)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *(NodeLink*)((char*)current.FUN_0044df00() + 8);
            *(int*)unk04 = (int)pending.ClearLowBit();
            FUN_0040fbe0();
            if (((StateValue*)&pending)->FUN_00559450() !=
                ((StateValue*)((char*)current.FUN_0044df00() + 8))->FUN_00559450())
            {
                flag_ = 1;
                break;
            }
            nodeVal = *(int*)current.ClearLowBit();
            svB.FUN_006ecba0(0, current.ClearLowBit());
            if (((StateValue*)state)->FUN_00559450() != svB.FUN_00559450())
            {
                flag_ = 1;
                break;
            }
            if (!FUN_0044dff0((int*)&pending))
            {
                if (((ControllerV*)controller)->Call34(nodeVal, a2))
                    return ((ControllerV*)controller)->Call38(nodeVal, a2);
                state = (int*)((char*)current.FUN_0044df00() + 8);
                *(int*)unk0c = (int)current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                svC2.FUN_006ecba0(0, pending.ClearLowBit());
                if (FUN_004491c0(state, svC2.FUN_00559450(), svB.FUN_00559450()))
                {
                    AddRace(current.ClearLowBit());
                }
                else
                {
                    flag_ = 1;
                    break;
                }
            }
            current = pending;
            *(int*)unk08 = (int)pending.ClearLowBit();
            FUN_0040fbe0();
        }
        if (flag_)
            continue;
    }
}

struct MatchNode;
struct FUN_006ecba0
{
    MatchNode* value;
    MatchNode* ClearLowBit();
    MatchNode* FUN_0044df00();
    unsigned int FUN_00559450();
    bool FUN_0044dff0();
    FUN_006ecba0(bool, MatchNode*);
};
struct FUN_0044e370
{
    void* value;
    FUN_0044e370(void*);
    ~FUN_0044e370();
    bool FUN_004b0460(void*);
};
struct MatchNode
{
    MatchNode* value;
    void* payload;
    FUN_006ecba0 next;
};
struct MatchMap
{
    FUN_006ecba0* GetElementAddress(unsigned int);
};
void __cdecl FUN_0040fbe0();
bool __cdecl FUN_004491c0(FUN_006ecba0*, unsigned int, unsigned int);
struct MatchOwner
{
    MatchMap* map;
    MatchNode** hazardNext;
    MatchNode** hazardCurrent;
    MatchNode** hazardRemoved;
    FUN_006ecba0* cursor;
    FUN_006ecba0 current;
    FUN_006ecba0 next;
    void FUN_005292a0(MatchNode*);
    bool FUN_00906820(unsigned int key, void* output);
};
// @fnv 0x00906820
bool MatchOwner::FUN_00906820(unsigned int key, void* output)
{
    FUN_006ecba0* bucket = map->GetElementAddress(key);
    while (true)
    {
        bool first = false;
        cursor = bucket;
        current = *cursor;
        *hazardCurrent = current.ClearLowBit();
        FUN_0040fbe0();
        FUN_006ecba0 retry(false, current.ClearLowBit());
        if (cursor->FUN_00559450() != retry.FUN_00559450())
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            next = current.FUN_0044df00()->next;
            *hazardNext = next.ClearLowBit();
            FUN_0040fbe0();
            if (next.FUN_00559450() != current.FUN_0044df00()->next.FUN_00559450())
            {
                first = true;
                break;
            }
            FUN_0044e370 observed(&current.ClearLowBit()->payload);
            FUN_006ecba0 ref(false, current.ClearLowBit());
            if (cursor->FUN_00559450() != ref.FUN_00559450())
            {
                first = true;
                break;
            }
            if (!next.FUN_0044dff0())
            {
                if (observed.FUN_004b0460(output))
                    return true;
                cursor = &current.FUN_0044df00()->next;
                *hazardRemoved = current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                FUN_006ecba0 replacement(false, next.ClearLowBit());
                if (FUN_004491c0(cursor, replacement.FUN_00559450(), ref.FUN_00559450()))
                {
                    FUN_005292a0(current.ClearLowBit());
                }
                else
                {
                    first = true;
                    break;
                }
            }
            current = next;
            *hazardCurrent = next.ClearLowBit();
            FUN_0040fbe0();
        }
        if (first)
            continue;
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long* lAddend);

struct FUN_00ae78e0_Class
{
    struct SUB
    {
        long unk30;
        void* unk34;
    };
    char pad0[0x30];
    SUB sub;
    char pad38[0x10];
    unsigned char unk48;
    void __thiscall ReleaseSemaphoreAndIncrement();
};

// If unk48 is set, releases one count on the semaphore at sub.unk34 and increments sub.unk30.
// @fnv 0x00ae78e0
void FUN_00ae78e0_Class::ReleaseSemaphoreAndIncrement()
{
    if (unk48 != 0)
    {
        SUB* v = &sub;
        ReleaseSemaphore(v->unk34, 1, 0);
        InterlockedIncrement(&v->unk30);
    }
}

namespace fnv_0043fc40 {
class NiAVObject;
struct FUN_0043fcd0_t
{
    NiAVObject* FUN_0043fcd0();
};
class BSOcclusionPlane
{
  public:
    int GetCullResult() const;
};
template <class C> class BSStringT
{
  public:
    operator const C*() const;
};
template <> class NiPointer<NiNode*>
{
  public:
    NiPointer<NiNode>& operator=(NiNode*);
};
class FUN_00565210_shell
{
  public:
    void FUN_00565210(bool);
};
struct FUN_00570f70_t
{
    void FUN_00570f70(const char*);
};
struct FUN_00451ef0_t
{
    void FUN_00451ef0(TESObjectREFR*, int, int, int);
};
extern int g_TES;
bool __fastcall FUN_00449130(int*);

class FUN_0043fc40_t
{
  public:
    char _pad[0x18];
    TESObjectREFR* m_pReference;
    BSStringT<char> m_kName;
    void FUN_0043fc40();
};

// @fnv 0x0043fc40
void FUN_0043fc40_t::FUN_0043fc40()
{
    if (!FUN_00449130((int*)this) && m_pReference && !((FUN_0043fcd0_t*)m_pReference)->FUN_0043fcd0())
    {
        ((FUN_00570f70_t*)m_pReference)->FUN_00570f70(m_kName);
        ((FUN_00451ef0_t*)g_TES)->FUN_00451ef0(m_pReference, ((BSOcclusionPlane*)m_pReference)->GetCullResult(), 0, 0);
        ((FUN_00565210_shell*)m_pReference)->FUN_00565210(true);
    }
    else
    {
        *(NiPointer<NiNode*>*)&m_kName = 0;
    }
}
}  // namespace fnv_0043fc40

// DestroyAllStreams
struct MyAVObject : NiAVObject
{
    bool FUN_005f26c0();
};

struct ModelEntry
{
    int unk04;
    int unk08;
    int GetCombinedValue();
    ~ModelEntry();
};

struct KFModelEntry
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int FUN_004431b0();
    MyAVObject* GetNode();
    ~KFModelEntry();
};

__declspec(align(4)) struct IterA
{
    int f00, f01, f02, f03, f04, f05, f06, f07, f08, f09;
    int f10, f11, f12, f13, f14, f15, f16, f17, f18, f19;
    int f20, f21, f22, f23, f24, f25, f26, f27, f28, f29;
    int f30, f31, f32, f33, f34, f35, f36, f37, f38, f39;
    int f40, f41, f42, f43, f44, f45, f46, f47, f48, f49;
    int f50, f51, f52, f53, f54, f55, f56, f57, f58, f59;
    int f60, f61, f62, f63, f64, f65, f66, f67, f68;
    IterA();
    ~IterA();
    bool FUN_006ebde0();
};

__declspec(align(4)) struct IterB
{
    void* vtable;
    int unk04;
    char* pathPtr;
    int unk0c;
    char path[260];
    IterB();
    ~IterB();
    bool FUN_006ebde0();
};

struct StreamObj
{
    virtual ~StreamObj();
    virtual void reservedA();
    virtual void reservedB();
    virtual void reservedC();
    virtual void reservedD();
    virtual void* processEntry(int);
    virtual void reservedE();
    virtual void reservedF();
    virtual void reservedG();
    virtual void reservedH();
    virtual void reservedI();
    virtual void reservedJ();
    virtual void reservedK();
    virtual void reservedL();
    virtual void reservedM();
    virtual void reservedN();
    virtual void reservedO();
    virtual int queryGate();
    bool TryGetNextEntry(void*, int*, void*, int);
};

void __cdecl _FNV_Warning(const char*, ...);
extern const char DAT_01016ea0[];
extern const char DAT_01016e70[];

struct Self
{
    StreamObj* m_00;
    StreamObj* m_04;
    StreamObj* m_08;
    StreamObj* m_0c;
    StreamObj* m_10;
    StreamObj* m_14;
    StreamObj* m_18;
    StreamObj* m_1c;
    StreamObj* m_20;
    StreamObj* m_24;
    StreamObj* m_28;
    void FUN_00443270(int, int);
    void DestroyAllStreams();
};

// Clears both stream tables, warns about leftover entries, then deletes all stream objects held by the Self.
// @fnv 0x00442aa0
void Self::DestroyAllStreams()
{
    FUN_00443270(0, 0);
    if (m_00->queryGate())
    {
        unsigned int a_count = 0;
        IterA m_iter;
        while (!m_iter.FUN_006ebde0())
        {
            int o = 0;
            ModelEntry* e = 0;
            if (m_00->TryGetNextEntry(&m_iter, &o, &e, 1))
            {
                if (e->GetCombinedValue() > 0)
                    a_count++;
                delete e;
            }
        }
        if (a_count > 0)
            _FNV_Warning(DAT_01016ea0, a_count);
    }

    IterB iterB;
    while (!iterB.FUN_006ebde0())
    {
        int c = 0;
        KFModelEntry* t = 0;
        if (m_04->TryGetNextEntry(&iterB, &c, &t, 1) && t)
        {
            if (!t->GetNode() || t->GetNode()->FUN_005f26c0())
            {
                m_04->processEntry(c);
                delete t;
            }
        }
    }

    if (m_04->queryGate())
    {
        unsigned int countC = 0;
        IterB iterC;
        while (!iterC.FUN_006ebde0())
        {
            int c1 = 0;
            KFModelEntry* c2 = 0;
            if (m_04->TryGetNextEntry(&iterC, &c1, &c2, 1))
            {
                if (c2->FUN_004431b0() > 0)
                    countC++;
                delete c2;
            }
        }
        if (countC > 0)
            _FNV_Warning(DAT_01016e70, countC);
    }

    delete m_00;
    delete m_04;
    delete m_1c;
    delete m_18;
    delete m_14;
    delete m_10;
    delete m_08;
    delete m_0c;
    delete m_28;
    delete m_20;
    delete m_24;
}

namespace fnv_0043d180 {
extern "C" char DAT_01016840;
extern "C" char DAT_011c63cc;
extern "C" char DAT_011c3be4;
extern "C" char DAT_011c3bb8;
extern "C" char DAT_011c3b3c;
struct Guard43
{
    int x;
    Guard43(int, bool, char*, int);
    ~Guard43();
};
struct Update43
{
    int data[3];
    void FUN_0043d410(float, bool, bool);
};
struct Bound43
{
    float FUN_0084d030();
};
struct Fade43
{
    void FUN_00a59c60(const Update43&);
    Bound43& FUN_0043d450();
    void FUN_00b4dfd0(float, float);
    void FUN_00b4dec0(int);
};
struct Obj43
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Fade43* v4();
};
struct Model43
{
    void FUN_0092c870();
    Obj43* FUN_0043b230();
};
struct Ptr43
{
    Model43* FUN_00559450();
};
struct SettingI43
{
    unsigned int* FUN_0043d4d0();
};
struct SettingF43
{
    float* FUN_00403e20();
};
struct Vec43
{
    float x, y, z;
};
Vec43* __cdecl FUN_0056fc30(Vec43*, Obj43*);
struct Loader43
{
    unsigned char CallFoo(int, Model43*);
    void FUN_004472a0(int, Ptr43&);
};
struct C43
{
    char pad[24];
    int field18;
    char pad1[20];
    Ptr43 ptr;
    int field34;
    int field38;
    bool FUN_0043d490();
    bool FUN_0043d4b0();
    float FUN_00792760();
    int FUN_0045cd60();
    void RunVirtualMethod28();
    void FUN_0043d180();
};
// Updates the fade node of the model's object: recomputes range from settings and radius, applies fade and field38, and reloads the model if needed.
// @fnv 0x0043d180
void C43::FUN_0043d180()
{
    Guard43 guard(field18, true, &DAT_01016840, 997);
    if (ptr.FUN_00559450())
    {
        if (FUN_0043d490())
            ptr.FUN_00559450()->FUN_0092c870();
        if (!FUN_0043d4b0() && ptr.FUN_00559450()->FUN_0043b230())
        {
            Fade43* node2 = ptr.FUN_00559450()->FUN_0043b230()->v4();
            if (node2)
            {
                Update43 update4;
                update4.FUN_0043d410(0.0f, false, false);
                node2->FUN_00a59c60(update4);
                float radius = node2->FUN_0043d450().FUN_0084d030();
                Vec43 vec3;
                if (radius < 0.0010000000474974513)
                    radius = FUN_0056fc30(&vec3, ptr.FUN_00559450()->FUN_0043b230())->z * 0.5;
                float maximum = 3.402823466e+38f;
                maximum = (*((SettingI43*)&DAT_011c63cc)->FUN_0043d4d0() << 12) * 0.5 - (radius + 2048.0);
                float scaled5 = radius * *((SettingF43*)&DAT_011c3be4)->FUN_00403e20();
                float range = radius != 0.0 && scaled5 < maximum ? scaled5 : maximum;
                if (FUN_00792760() != 0.0)
                    range = FUN_00792760();
                node2->FUN_00b4dfd0(range * *((SettingF43*)&DAT_011c3bb8)->FUN_00403e20(), range);
                node2->FUN_00b4dec0(field38);
            }
            if (!(*(Loader43**)&DAT_011c3b3c)->CallFoo(FUN_0045cd60(), ptr.FUN_00559450()))
                (*(Loader43**)&DAT_011c3b3c)->FUN_004472a0(FUN_0045cd60(), ptr);
        }
    }
    RunVirtualMethod28();
}
}  // namespace fnv_0043d180

class NodePointer
{
    NiNode* node;

  public:
    NodePointer(NiNode*);
    operator NiNode*() const;
    ~NodePointer();
};
class TextureTask : public IOTask
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    NiNode* model;
    bool loaded;
    TextureTask(BSFileEntry*, int);
    TextureTask(NiNode*, int);
    void SetParent(QueuedFile*);
};
class TextureTaskPointer
{
    TextureTask* task;

  public:
    TextureTaskPointer(TextureTask*);
    ~TextureTaskPointer();
    TextureTask* operator->() const;
};
class TextureNodeInfo
{
  public:
    int FUN_0043c430();
};
void __cdecl GetNodePointer(BSFileEntry*, NodePointer&);
void* __cdecl operator new(unsigned int);
class TextureLoader
{
  public:
    bool IsLoadTexturesDegraded();
    bool FUN_00443540(BSFileEntry*, int, QueuedFile*);
    bool QueueTextureLoad(BSFileEntry*, int, QueuedFile*);
};
// Loads the file's node; if it is a usable model it queues a TextureTask for the node, otherwise falls back to FUN_00443540 or queues a TextureTask for the file.
// @fnv 0x00443af0
bool TextureLoader::QueueTextureLoad(BSFileEntry* file, int priority, QueuedFile* parent)
{
    NodePointer node(0);
    GetNodePointer(file, node);
    if ((NiNode*)node)
    {
        bool skip = false;
        if (((TextureNodeInfo*)(NiNode*)node)->FUN_0043c430() == 3 && !IsLoadTexturesDegraded())
            skip = true;
        if (!skip)
        {
            if (parent)
            {
                TextureTaskPointer request(new TextureTask((NiNode*)node, priority));
                request->SetParent(parent);
                request->vfn_28();
                return true;
            }
            return false;
        }
    }
    if (FUN_00443540(file, priority, parent))
        return true;
    TextureTaskPointer request(new TextureTask(file, priority));
    request->SetParent(parent);
    request->vfn_20();
    return true;
}

namespace fnv_00443dc0 {
class QHeadLocal
{
  public:
    void FUN_0044bbc0();
};

class QNewFile;

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    NiPtr(T* p);
    operator T*() const;
    NiPtr<T>& operator=(T* p);
    ~NiPtr();
};

class QueueObj
{
  public:
    virtual void d0();
    virtual void d4();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void* d14(QHeadLocal** out);
    void FUN_0092c820(NiPtr<QNewFile>& p);
    void FUN_006f74f0(QNewFile* p);
};

class QHolderObj
{
  public:
    virtual void h0();
    virtual void h4();
    virtual bool h8(void* arg);
};

class QNewFile
{
  public:
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
    QNewFile(QHeadLocal* p, int a);
    QNewFile(void* p, int a, int b, bool c, bool d);
    void FUN_00444020(float f);
    void SetParent(QNewFile* p);
    void FUN_00443ff0(unsigned char b);
    char pad[0x44];
};

class QueueModelHolder
{
  public:
    QHolderObj* m_pHolder;
    void FUN_00443dc0(int a1, QueueObj* a2, int a3, int a4, int a5, bool a6, bool a7, bool a8, float a9);
};

// @fnv 0x00443dc0
void QueueModelHolder::FUN_00443dc0(int pQueueObj, QueueObj* a2, int a3, int pParent, int a5, bool bFlag1, bool bFlag2,
                                    bool bFlag3, float fValue)
{
    QHeadLocal* pHead = 0;
    if (m_pHolder->h8(((QueueObj*)pQueueObj)->d14(&pHead)))
    {
        if (bFlag2)
        {
            pHead->FUN_0044bbc0();
        }
        if (pParent)
        {
            NiPtr<QNewFile> sp(new QNewFile(pHead, a3));
            ((QNewFile*)sp)->FUN_00444020(fValue);
            ((QNewFile*)sp)->SetParent((QNewFile*)pParent);
            ((QNewFile*)sp)->v28();
            a2->FUN_0092c820(sp);
            return;
        }
        a2->FUN_006f74f0(0);
        return;
    }
    NiPtr<QNewFile> sp(new QNewFile((void*)pQueueObj, a3, a5, bFlag1, bFlag2));
    ((QNewFile*)sp)->FUN_00444020(fValue);
    ((QNewFile*)sp)->SetParent((QNewFile*)pParent);
    ((QNewFile*)sp)->FUN_00443ff0(bFlag3);
    ((QNewFile*)sp)->v20();
    a2->FUN_0092c820(sp);
}
}  // namespace fnv_00443dc0

namespace fnv_00448080 {
extern "C" char DAT_01016fac;
struct Task448
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    void FUN_00443aa0(void*);
    Task448(void*, void*);
    char data[60];
};
struct Ref448
{
    void* p;
    Ref448(int);
    ~Ref448();
    void* FUN_00559450();
};
struct RefB448
{
    void* p;
    RefB448(int);
    ~RefB448();
    void* FUN_00559450();
};
struct String448
{
    void* p;
    int n;
    String448();
    ~String448();
    void* FUN_00559450();
};
struct Head448
{
    void* p;
    Head448(Task448*);
    ~Head448();
    Task448* FUN_00559450();
};
struct Manager448
{
    bool LookupModelAndGetFlags(void*, Ref448*, RefB448*);
};
Manager448* FUN_00652110();
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
void BuildEgmFilename(String448*, char*, int);
void BuildTriPathAndSet(String448*, char*, int);
struct Owner448
{
    void FUN_00447a40(void*, int, void*, int);
    void LoadTaskFromPath(Task448*, int, void*, int);
};
// @fnv 0x00448080
void Owner448::LoadTaskFromPath(Task448* pTask, int x, void* parent, int unused)
{
    Ref448 a(0);
    RefB448 b(0);
    char pathX[260];
    FUN_00406d30(pathX, 260, &DAT_01016fac);
    FUN_00406d50(pathX, 260, pTask->v5());
    String448 s3;
    BuildEgmFilename(&s3, pathX, -1);
    if (FUN_00652110() && FUN_00652110()->LookupModelAndGetFlags(s3.FUN_00559450(), &a, &b) && a.FUN_00559450() &&
        b.FUN_00559450())
    {
        if (parent)
        {
            Head448 h3(new Task448(a.FUN_00559450(), b.FUN_00559450()));
            h3.FUN_00559450()->FUN_00443aa0(parent);
            h3.FUN_00559450()->v10();
        }
        return;
    }
    String448 t2;
    BuildTriPathAndSet(&t2, pathX, -1);
    FUN_00447a40(t2.FUN_00559450(), x, parent, 1);
}
}  // namespace fnv_00448080

namespace fnv_00448620 {
struct FUN_0045585e0_t;
struct FUN_004498e0_t;
struct FUN_00449960_t;

struct FUN_00443190_t
{
    ~FUN_00443190_t();
    int GetCombinedValue();
};
struct FUN_004431b0_t
{
    ~FUN_004431b0_t();
    int FUN_004431b0();
    FUN_0045585e0_t* GetSkinData();
};
struct FUN_0045585e0_t
{
    int GetType();
};

struct FUN_0044c640_host
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    bool TryGetNextEntry(FUN_004498e0_t*, int*, FUN_00443190_t**, int);
    bool TryGetNextEntry(FUN_00449960_t*, int*, FUN_004431b0_t**, int);
};

struct FUN_0042ce10_t
{
    bool FUN_0042ce10();
};

struct FUN_004498e0_t
{
    FUN_004498e0_t();
    ~FUN_004498e0_t();
    bool FUN_006ebde0();
    char pad[0x10c];
};

struct FUN_00449960_t
{
    FUN_00449960_t();
    ~FUN_00449960_t();
    bool FUN_006ebde0();
    char pad[0x110];
};

extern "C" FUN_0042ce10_t* DAT_011ddf38;

struct FUN_00448620_cls
{
    FUN_0044c640_host* p0;
    FUN_0044c640_host* p4;
    char pad[0x24];
    bool b2c;
    void FUN_00448620(bool);
};

// @fnv 0x00448620
void FUN_00448620_cls::FUN_00448620(bool b)
{
    if (!b && DAT_011ddf38 != 0 && DAT_011ddf38->FUN_0042ce10())
    {
        b2c = true;
        return;
    }
    if (p0 != 0)
    {
        FUN_004498e0_t entryA;
        while (!entryA.FUN_006ebde0())
        {
            FUN_00443190_t* v12c = 0;
            int v128 = 0;
            if (p0->TryGetNextEntry(&entryA, &v128, &v12c, 1) && v12c != 0 && !v12c->GetCombinedValue())
            {
                p0->v5(v128);
                delete v12c;
            }
        }
    }
    if (p4 != 0)
    {
        FUN_00449960_t entryB;
        while (!entryB.FUN_006ebde0())
        {
            FUN_004431b0_t* pEntryB = 0;
            int iIndexB = 0;
            if (p4->TryGetNextEntry(&entryB, &iIndexB, &pEntryB, 1) && pEntryB != 0 && !pEntryB->FUN_004431b0())
            {
                bool bRemovable = true;
                if (pEntryB->GetSkinData() != 0 && pEntryB->GetSkinData()->GetType() >= 0x5c &&
                    pEntryB->GetSkinData()->GetType() < 0x66)
                    bRemovable = false;
                if (bRemovable)
                {
                    p4->v5(iIndexB);
                    delete pEntryB;
                }
            }
        }
    }
    b2c = false;
}
}  // namespace fnv_00448620

namespace fnv_004436c0 {
struct NiObjQ
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
    void FUN_00443aa0(void* p);
    void FUN_00c3cee0(char* s);
    int FUN_0043c430();
};
struct SPBaseQ
{
    NiObjQ* m_p;
    NiObjQ* FUN_00559450();
};
struct FUN_00633c90 : SPBaseQ
{
    FUN_00633c90(NiObjQ* p);
    ~FUN_00633c90();
};
struct FUN_00528cb0 : SPBaseQ
{
    FUN_00528cb0(NiObjQ* p);
    ~FUN_00528cb0();
    FUN_00528cb0& FUN_006f74f0(NiObjQ* p);
};
struct FUN_0043bef0 : NiObjQ
{
    char pad[0x34];
    FUN_0043bef0(NiObjQ* p, void* q);
};
struct FUN_0043be60 : NiObjQ
{
    char pad[0x34];
    FUN_0043be60(void* p, void* q);
};
struct FUN_0043bd10 : NiObjQ
{
    char pad[0x34];
    FUN_0043bd10(const char* p, void* q);
};
struct FUN_006815c0
{
    int m0, m4;
    FUN_006815c0();
};
void __cdecl FindTextureByPath(const char* s, FUN_00633c90* p);
void __cdecl FUN_00af4200(const char* s, char* buf, unsigned int n);
void __cdecl HashPathComponents(char* buf, FUN_006815c0* a, FUN_006815c0* b);
void* __cdecl FindFileEntryInArchives(int n, FUN_006815c0* a, FUN_006815c0* b, char* buf);
class FUN_004436c0_Class
{
  public:
    bool IsLoadTexturesDegraded();
    bool FUN_00443540(void* p, void* q, void* r);
    bool LoadTexture(const char* pcName, void* p2, void* p3);
};
// Looks up pcName, then either configures a found object or searches archives and constructs another object.
// @fnv 0x004436c0
bool FUN_004436c0_Class::LoadTexture(const char* pcName, void* p2, void* p3)
{
    FUN_00633c90 spA5(0);
    FindTextureByPath(pcName, &spA5);
    if (spA5.FUN_00559450())
    {
        bool bSkip = false;
        if (spA5.FUN_00559450()->FUN_0043c430() == 3 && !IsLoadTexturesDegraded())
            bSkip = true;
        if (!bSkip)
        {
            if (p3)
            {
                FUN_00528cb0 spB4(new FUN_0043bef0(spA5.FUN_00559450(), p2));
                spB4.FUN_00559450()->FUN_00443aa0(p3);
                spB4.FUN_00559450()->v28();
                return true;
            }
            return false;
        }
    }
    char acPath7[0x104];
    FUN_00af4200(pcName, acPath7, 0x104);
    FUN_006815c0 kA;
    FUN_006815c0 kB;
    HashPathComponents(acPath7, &kA, &kB);
    void* pRes_ = FindFileEntryInArchives(1, &kA, &kB, acPath7);
    if (pRes_ && FUN_00443540(pRes_, p2, p3))
        return true;
    FUN_00528cb0 spC4(0);
    if (pRes_)
    {
        spC4.FUN_006f74f0(new FUN_0043be60(pRes_, p2));
        spC4.FUN_00559450()->FUN_00c3cee0(acPath7);
    }
    else
    {
        spC4.FUN_006f74f0(new FUN_0043bd10(pcName, p2));
    }
    spC4.FUN_00559450()->FUN_00443aa0(p3);
    spC4.FUN_00559450()->v20();
    return true;
}
}  // namespace fnv_004436c0

namespace fnv_00447980 {
struct QIdle
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Run();
};
class QIdlePtr
{
  public:
    QIdlePtr(QIdle* p);
    ~QIdlePtr();
    operator QIdle*() const;
    QIdle* m_p;
};
class FUN_0043d540 : public QIdle
{
  public:
    FUN_0043d540(int a, int b, int c);
    void* operator new(unsigned int);
    unsigned int unk[15];
};
class OwnerX
{
  public:
    void RunIdleTask(int a, int c);
};
// Creates a FUN_0043d540 idle task with the given parameters and immediately runs it via QIdle::Run.
// @fnv 0x00447980
void OwnerX::RunIdleTask(int aiParam1, int aiParam3)
{
    QIdlePtr spIdle(new FUN_0043d540(aiParam1, 4, aiParam3));
    ((QIdle*)spIdle)->Run();
}
}  // namespace fnv_00447980

namespace fnv_004492f0 {
enum MEM_CONTEXT
{
    MC_6 = 6
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
    int iData;
};
template <class T> unsigned int BSStringLength(const T* p);
extern "C" int __cdecl tolower(int);
class StrMapX
{
  public:
    char* GetLowercaseKey(const char* pKey);
};
// Allocates and returns a lowercase copy of pKey while an AutoMemContext is active.
// @fnv 0x004492f0
char* StrMapX::GetLowercaseKey(const char* pKey)
{
    AutoMemContext kContext(MC_6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h",
                            0x1fd);
    char* pCopy = new char[BSStringLength(pKey) + 1];
    char* pDst = pCopy;
    while (*pKey)
    {
        *pDst++ = tolower(*pKey++);
    }
    *pDst = 0;
    return pCopy;
}
}  // namespace fnv_004492f0

struct NodeX;
struct PtrX
{
    void FUN_006f74f0(void* p);
    void FUN_0092c820(PtrX* p);
};
struct NodeX
{
    NodeX* m_pkNext;
    PtrX m_kData;
};
struct ListX
{
    virtual void v0(), v4(), v8();
    virtual void Vc();
    NodeX* m_pkHead;
    NodeX* m_pkTail;
};
bool FUN_004491c0(NodeX** ppkDest, NodeX* pkNew, NodeX* pkCmp);
struct QueueX
{
    ListX* m_pkList;
    NodeX** m_ppkHazard0;
    NodeX** m_ppkHazard1;
    void FUN_0044e4f0(NodeX* pkNode);
    bool Pop(PtrX& kOut);
};
// Atomically removes the head node from the lock-free list, copies its data into kOut, and returns false when the queue is empty.
// @fnv 0x0044cec0
bool QueueX::Pop(PtrX& kOut)
{
    NodeX* volatile pkHead = 0;
    while (true)
    {
        pkHead = m_pkList->m_pkHead;
        *m_ppkHazard0 = pkHead;
        if (pkHead != m_pkList->m_pkHead)
            continue;
        NodeX* pkTail = m_pkList->m_pkTail;
        NodeX* volatile pkNext = pkHead->m_pkNext;
        *m_ppkHazard1 = pkNext;
        if (pkHead != m_pkList->m_pkHead)
            continue;
        if (!pkNext)
        {
            *m_ppkHazard0 = 0;
            kOut.FUN_006f74f0(0);
            return false;
        }
        if (pkHead == pkTail)
        {
            FUN_004491c0(&m_pkList->m_pkTail, pkNext, pkTail);
            continue;
        }
        kOut.FUN_0092c820(&pkNext->m_kData);
        if (FUN_004491c0(&m_pkList->m_pkHead, pkNext, pkHead))
        {
            m_pkList->Vc();
            pkNext->m_kData.FUN_006f74f0(0);
            break;
        }
    }
    *m_ppkHazard0 = 0;
    *m_ppkHazard1 = 0;
    FUN_0044e4f0(pkHead);
    return true;
}

struct Item44F950;
struct Node44F950
{
    Item44F950* m_item;
    Node44F950* m_pkNext;
    Item44F950*& GetItem();
};
class Owner44F950
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool CheckItem(Item44F950* pkItem);
    bool BaseCheck();
    Node44F950* GetHead();
    Node44F950* GetNext(Node44F950* pkNode);
    bool CheckAllItems();
};

// Returns true if BaseCheck passes and every item in the linked list of nodes passes CheckItem.
// @fnv 0x0044f950
bool Owner44F950::CheckAllItems()
{
    bool bResult = BaseCheck();
    if (bResult)
    {
        Node44F950* pkNode = GetHead();
        while (pkNode)
        {
            bResult &= CheckItem(pkNode->GetItem());
            pkNode = GetNext(pkNode);
        }
    }
    return bResult;
}

class QIdle;

class QIdleRef
{
  public:
    QIdle* m_pObject;
    QIdleRef(QIdle* object);
    ~QIdleRef();
};

class QIdleBase
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    char pad[0x34];
    QIdleBase(void* first, int second);
    ~QIdleBase();
};

struct FUN_0043e580 : QIdleBase
{
    virtual void v00();
    virtual void v04();
    void* m_38;
    QIdleRef m_3c;

    FUN_0043e580(void* first, int second, QIdle* third, void* fourth);
};

// Initializes QIdleBase from first and second, then m_38 from fourth and m_3c from third.
// @fnv 0x0043e580
FUN_0043e580::FUN_0043e580(void* apBase, int second, QIdle* apIdle, void* fourth)
    : QIdleBase(apBase, second), m_38(fourth), m_3c(apIdle)
{}

class BaseTaskMgr
{
  public:
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
    ~BaseTaskMgr();
};

struct ElemA
{
    int unk00;
    ~ElemA();
};

struct ElemB
{
    int unk00;
    ~ElemB();
};

class LoaderMgr : public BaseTaskMgr
{
  public:
    ElemA unk2C[20];
    ElemB unk7C[20];
    ElemB unkCC[20];
    ~LoaderMgr();
};

// @fnv 0x0043f080
LoaderMgr::~LoaderMgr()
{}

namespace fnv_00440640 {
struct FUN_00449a20_cls
{
    void FUN_004490e0();
    void FUN_00440640();
};

void FUN_00449a20_cls::FUN_004490e0()
{}

// @fnv 0x00440640
void FUN_00449a20_cls::FUN_00440640()
{
    FUN_004490e0();
}
}  // namespace fnv_00440640

#include <ctype.h>
struct LockFreeCaseInsensitiveStringMap_t
{
    void FUN_00449530(const char* apKey, void* apValue);
    void FUN_004493d0(const char* apKey, void* apValue);
};
// Lowercases apKey into acLowerKey and calls FUN_00449530 with the lowercased key and apValue.
// @fnv 0x004493d0
void LockFreeCaseInsensitiveStringMap_t::FUN_004493d0(const char* apKey, void* apValue)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    FUN_00449530(acLowerKey, apValue);
}

namespace fnv_00449460 {
struct LockFreeCaseInsensitiveStringMap_t
{
    void FUN_00449580(const char* apKey, void* apValue, bool abFlag);
    void FUN_00449460(const char* apKey, void* apValue, bool abFlag);
};
// Lowercases apKey into a 1000-byte buffer and forwards it with apValue and abFlag to FUN_00449580.
// @fnv 0x00449460
void LockFreeCaseInsensitiveStringMap_t::FUN_00449460(const char* apKey, void* apValue, bool abFlag)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    FUN_00449580(acLowerKey, apValue, abFlag);
}
}  // namespace fnv_00449460

namespace fnv_00449750 {
struct LockFreeCaseInsensitiveStringMap_t
{
    unsigned int FUN_0044ddc0();
    unsigned int GetBucketIndex(const char* apKey);
};
// Computes a case-insensitive hash of apKey and returns it modulo the table size from FUN_0044ddc0.
// @fnv 0x00449750
unsigned int LockFreeCaseInsensitiveStringMap_t::GetBucketIndex(const char* apKey)
{
    unsigned int uiHash = 0;
    while (*apKey)
    {
        uiHash = (uiHash << 5) + uiHash + tolower(*apKey++);
    }
    return uiHash % FUN_0044ddc0();
}
}  // namespace fnv_00449750

namespace fnv_004497f0 {
struct LockFreeCaseInsensitiveStringMap_t
{
    void FUN_004495d0(const char* apKey);
    void FUN_004497f0(const char* apKey);
};
// Lowercases apKey into acLowerKey and calls FUN_004495d0 with the lowercased key.
// @fnv 0x004497f0
void LockFreeCaseInsensitiveStringMap_t::FUN_004497f0(const char* apKey)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    FUN_004495d0(acLowerKey);
}
}  // namespace fnv_004497f0

namespace reference_queue_types {
namespace FUN_00528cb0 {
struct FUN_0044cbf0
{
    void* p;
    FUN_0044cbf0(void*);
    ~FUN_0044cbf0();
};
}
}

struct FUN_00445750_map
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(void* r, reference_queue_types::FUN_00528cb0::FUN_0044cbf0* out);
};

struct FUN_00445750_arg
{
    void* r;
};

// @fnv 0x00445750
// @fnv 0x00445750
bool __fastcall FUN_00445750(char* this_ptr, FUN_00445750_arg a)
{
    reference_queue_types::FUN_00528cb0::FUN_0044cbf0 g(0);
    return (*(FUN_00445750_map**)(this_ptr + 8))->Lookup(a.r, &g);
}

// HighProcess_MLd model-file loader
extern "C" unsigned int __BSStringLength(const char*);
extern "C" void ref_005b5e40(const char*, ...);
extern "C" int DAT_011f94c0;
extern "C" const char DAT_01016840[];
extern "C" const char DAT_010168c4[];
extern "C" const char DAT_010168ec[];
extern "C" const char DAT_010168f4[];

class AutoMemHelper_MLd
{
  public:
    void* m_buffer;
    AutoMemHelper_MLd(int, bool, const char*, int);
    ~AutoMemHelper_MLd();
};

class NiPointerShell_MLd
{
  public:
    unsigned int _ref_00726070();
};

class NiStream_MLd
{
  public:
    bool FUN_00c3a8a0(const char*, void*);
};

struct Blob16
{
    int a, b, c, d;
};
struct Blob64
{
    Blob16 a, b, c, d;
};
struct Blob256
{
    Blob64 a, b, c, d;
};
struct Blob1024
{
    Blob256 a, b, c, d;
};
struct Blob1488
{
    Blob1024 a;
    Blob256 b;
    Blob64 c, d, e;
    Blob16 f;
};

class BSStream_MLd
{
  public:
    BSStream_MLd();
    virtual ~BSStream_MLd();
    char pad[0x5c8];
};

class HighProcess_MLd
{
  public:
    int GetProcessLevel();
};

class SetterHelper_MLd
{
  public:
    void FUN_0044aed0(void*);
};

class ModelLoaderX
{
  public:
    void LoadModel(const char*, NiPointer<Model>&);
};
extern ModelLoaderX* g_pModelLoader;

class FUN_0043ccf0_shell
{
  public:
    void FUN_0043ccf0();
    char m_uiStandInValue[0x18];
    int m_field18;
    char m_iValueAfterStandIn[0x14];
    int m_model30;
};

// Loads the named model, checks the pointer at offset 0x30, then tries stream loading and may assign a new Model.
// @fnv 0x0043ccf0
void FUN_0043ccf0_shell::FUN_0043ccf0()
{
    AutoMemHelper_MLd mem5(m_field18, 1, DAT_01016840, 0x3b8);

    if (__BSStringLength((const char*)((HighProcess_MLd*)this)->GetProcessLevel()) > 0)
    {
        g_pModelLoader->LoadModel((const char*)((HighProcess_MLd*)this)->GetProcessLevel(),
                                  *(NiPointer<Model>*)&m_model30);
        if (((NiPointerShell_MLd*)((char*)this + 0x30))->_ref_00726070() != 0)
        {
            ((FUN_0043cf60_shell*)this)->FUN_0043cf60(true);
            return;
        }

        void* pFile5 = ((FUN_00c3cff0_shell*)this)->FUN_00c3cff0(0, true);
        BSStream_MLd stream;

        DAT_011f94c0 = ((HighProcess_MLd*)this)->GetProcessLevel();

        if ((pFile5 != 0 && ((NiStream_MLd*)&stream)
                                ->FUN_00c3a8a0((const char*)((HighProcess_MLd*)this)->GetProcessLevel(), pFile5)) ||
            ((FUN_0043cf90_shell*)this)->FUN_0043cf90())
        {
            ((SetterHelper_MLd*)((char*)this + 0x30))
                ->FUN_0044aed0(new Model((const char*)((HighProcess_MLd*)this)->GetProcessLevel(), (BSStream*)&stream,
                                         ((FUN_0043cf40_shell*)this)->FUN_0043cf40(),
                                         ((FUN_0043cfb0_shell*)this)->FUN_0043cfb0()));
        }
        else
        {
            ref_005b5e40(DAT_010168c4, pFile5 ? DAT_010168f4 : DAT_010168ec,
                         (const char*)((HighProcess_MLd*)this)->GetProcessLevel());
        }

        DAT_011f94c0 = 0;
    }
}

__if_not_exists(WaitForSingleObject)
{
    extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
}

__if_not_exists(FinishScriptRunLock)
{
    void FinishScriptRunLock(void*);
}

class SemaphoreFields
{
  public:
    void* unk00;
    void* m_pSemaphore;
};

struct SemaphoreWaitReceiver
{
    void FUN_004424e0();
};

// Blocks indefinitely on m_pSemaphore via WaitForSingleObject, then releases the script run lock with FinishScriptRunLock.
// @fnv 0x004424e0
void SemaphoreWaitReceiver::FUN_004424e0()
{
    WaitForSingleObject(((SemaphoreFields*)this)->m_pSemaphore, 0xffffffffUL);
    FinishScriptRunLock(this);
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

class FUN_00c3b970_cls
{
  public:
    NiRefObject* m_pReferencedObject;

    FUN_00c3b970_cls& FUN_00c3b970(NiRefObject* obj);
};

// Swaps the referenced object, releasing the old reference and acquiring a new one when the pointer changes.
// @fnv 0x00c3b970
FUN_00c3b970_cls& FUN_00c3b970_cls::FUN_00c3b970(NiRefObject* apRefObject)
{
    NiRefObject* pOldRefObject;
    NiRefObject* pNewRefObject;
    if (m_pReferencedObject != apRefObject)
    {
        if (m_pReferencedObject != 0)
        {
            pOldRefObject = m_pReferencedObject;
            if (InterlockedDecrement((volatile long*)&pOldRefObject->m_uiRefCount) == 0)
            {
                pOldRefObject->DeleteThis();
            }
        }
        m_pReferencedObject = apRefObject;
        if (m_pReferencedObject != 0)
        {
            pNewRefObject = m_pReferencedObject;
            InterlockedIncrement((long*)&pNewRefObject->m_uiRefCount);
        }
    }
    return *this;
}

struct NiPoint3
{

  public:
    int FUN_0043c470();
};

NiNode* __fastcall FUN_0059bb30(NiAVObject* object);

struct ParentByteQuery : NiAVObject
{

    int FUN_0043c430();
};

// Returns FUN_0043c470() on the parent returned by FUN_0059bb30, or 0 if no parent exists.
// @fnv 0x0043c430
int ParentByteQuery::FUN_0043c430()

{

    return FUN_0059bb30(this) ? FUN_0059bb30(this)->FUN_0043c490().FUN_0043c470() : 0;
}

struct CharacterClone : public QueuedCharacter
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int m_uiMemoryContext;
    int unk1c, unk20, unk24;
    void* cloneTarget;
    bool FUN_004416c0();
};

namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}
struct CloneObjectAccessor
{
    void* FUN_005d8710();
};
void __fastcall AttachHeadAndFaceParts(void*);
struct Helper_00440a90
{
    bool FUN_00440a90();
};
void __cdecl FUN_00441780(void*, void*);
void __cdecl FUN_004417c0();

// Creates an AutoMemContext, checks a helper and clone accessor, then calls FUN_00441780, FUN_004418b0 and FUN_004417c0 when both checks pass.
// @fnv 0x004416c0
bool CharacterClone::FUN_004416c0()
{
    lc1::AutoMemContext tempMemContext(
        m_uiMemoryContext, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8e4);
    bool bresult = ((Helper_00440a90*)this)->FUN_00440a90();
    if (bresult && ((CloneObjectAccessor*)this)->FUN_005d8710())
    {
        FUN_00441780(cloneTarget, ((CloneObjectAccessor*)this)->FUN_005d8710());
        AttachHeadAndFaceParts(this);
        FUN_004417c0();
    }
    return bresult;
}

struct LockedResult
{
    void Enqueue();
};

struct ReceiverLock
{
    unsigned int ownerThread;
    unsigned int lockCount;
    void Lock(const char*);
    void Unlock();
};

struct LockedReceiver
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ReceiverLock lock;
    LockedResult* FUN_00449f80(void*);
};

struct ReceiverArgument
{
    void* value;
};

// Locks the receiver, calls FUN_0044cd40 on the result of FUN_00449f80 with argument.value, then unlocks the receiver.
// @fnv 0x00449240
void __fastcall FUN_00449240(LockedReceiver* receiver, ReceiverArgument argument)
{
    receiver->lock.Lock(0);
    receiver->FUN_00449f80(argument.value)->Enqueue();
    receiver->lock.Unlock();
}

void _Deallocate(void*);

struct ModelLoaderDeleteEntry449 : public ModelLoader
{
    void* FUN_00449b40(unsigned int flags);
};

// Calls FUN_00443220, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00449b40
void* ModelLoaderDeleteEntry449::FUN_00449b40(unsigned int flags)
{
    this->FUN_00443220();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
    unsigned int state;
};
struct CleanupReceiver
{
    void FUN_0065f240();
};
struct FUN_0044a040 : public FUN_0065cfb0
{
    ~FUN_0044a040();
};
// Calls FUN_0065f240 on the current object.
// @fnv 0x0044a040
FUN_0044a040::~FUN_0044a040()
{
    ((CleanupReceiver*)this)->FUN_0065f240();
}
