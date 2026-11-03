// fallout_shared/bgscamerashot.cpp: BGSCameraShot, CameraShot, ShotThis, Shot (16 functions)

#include "bgscamerashot_decls.h"
#include "bgscamerashot_types_BGSCameraShot.h"

// @fnv 0x0058bf50
void BGSCameraShot::ResetFormData()
{
    Data.m_eAction = BGSCameraShot__CAM_ACTION_CA_HIT;
    Data.pInputFile = BGSCameraShot__CAM_OBJECT_CO_TARGET;
    Data.m_eAttacker = BGSCameraShot__CAM_OBJECT_CO_ATTACKER;
    Data.m_fTimeMultiplier = 1.0f;
    Data.m_fMinTime = 0.0f;
    Data.m_fTargetPercent = 0.0f;
    Data.iFlags = 3;
    Data.fMaxTime = 0.0f;
    Data.m_fCameraValue1 = 0.0f;
    Data.m_fCameraValue2 = 0.0f;
}

// @fnv 0x0058c550
void BGSCameraShot::InitItem()
{
    if (GetInitialized())
        return;
    TESImageSpaceModifiableForm::InitItem(this);
    if (Data.m_fTimeMultiplier < *reinterpret_cast<const double*>(0x01032980))
    {
        Warning(reinterpret_cast<const char*>(0x01032930), GetName());
        Data.m_fTimeMultiplier = *reinterpret_cast<const float*>(0x0101e2bc);
    }
    SetInitializationState(true);
}

// @fnv 0x009c6ba0
void BGSCameraShot::ResetCameraShot()
{
    ((VATS*)this)->ProcessVATSCommands();
    if (((CameraTargetResetFields*)this)->node)
        ((CameraTargetResetFields*)this)->node->ResetCameraState();
    ((CameraTargetResetFields*)this)->field0c = 0;
    ((CameraTargetResetFields*)this)->node = 0;
    ((CameraTargetResetFields*)this)->f14 = 0.0f;
    ((CameraTargetResetFields*)this)->f18 = 0.0f;
    if (((CameraTargetResetFields*)this)->a)
    {
        FUN_005293f0(((CameraTargetResetFields*)this)->a);
        ((CameraTargetResetFields*)this)->a = 0;
    }
    if (((CameraTargetResetFields*)this)->b)
    {
        FUN_005293f0(((CameraTargetResetFields*)this)->b);
        ((CameraTargetResetFields*)this)->b = 0;
    }
}

// Reads a BGSCameraShot record from a TESFile: validates the form type, then parses EDID, OBND, MODL/MODT, MNAM and DATA chunks into the shot's data.
// @fnv 0x0058c090
bool BGSCameraShot::Load(TESFile* file)
{
    if (((TESFileFormInt*)file)->GetTESForm() != 0x5b)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4d414e4d: {
            unsigned int modifier = 0;
            file->GetChunkData(&modifier);
            ((CombatProcedure*)((char*)this + 0x30))->Initialize((CombatController*)modifier);
            break;
        }
        case 0x41544144:
            if (file->GetChunkSize() == 32)
            {
                CameraShotLegacyData legacyData;
                memset(&legacyData, 0, 32);
                ((BGSImpactData*)this)->ReadTypedData(file, &legacyData, 32);
                if (file->IsEndianConversionRequired())
                    legacyData.FUN_0058c2e0();
                Data.m_eAction = (BGSCameraShot__CAM_ACTION)legacyData.action;
                Data.pInputFile = (BGSCameraShot__CAM_OBJECT)legacyData.location;
                Data.m_eAttacker = (BGSCameraShot__CAM_OBJECT)legacyData.target;
                Data.iFlags = legacyData.flags;
                Data.m_fMinTime = legacyData.playerMult;
                Data.m_fTimeMultiplier = legacyData.globalMult;
                Data.fMaxTime = legacyData.maxTime;
                Data.m_fCameraValue1 = legacyData.minTime;
            }
            else
            {
                memset(&Data, 0, 40);
                file->GetChunkData(&Data, 40);
                if (file->IsEndianConversionRequired())
                    Data.FUN_0058c3c0();
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct FUN_0058c2e0_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    void FUN_0058c2e0();
};

// Byte-swaps all eight 32-bit fields of the object via BSEndian, in the order 0x10, 0x14, 0x00, 0x04, 0x08, 0x0c, 0x18, 0x1c.
// @fnv 0x0058c2e0
void FUN_0058c2e0_shell::FUN_0058c2e0()
{
    BSEndian(&field_0x10, EndianSizeTag<3>());
    BSEndian(&field_0x14, EndianSizeTag<3>());
    BSEndian(&field_0x00, EndianSizeTag<3>());
    BSEndian(&field_0x04, EndianSizeTag<3>());
    BSEndian(&field_0x08, EndianSizeTag<3>());
    BSEndian(&field_0x0c, EndianSizeTag<3>());
    BSEndian(&field_0x18, EndianSizeTag<3>());
    BSEndian(&field_0x1c, EndianSizeTag<3>());
}

void _Deallocate(void*);
struct FUN_0058be60_host
{
    void FUN_0058be90();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_0058be90, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0058be60
void* FUN_0058be60_host::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_0058be90();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct FUN_0058bfc0_shell
{
    void CopyFromCameraShot(TESForm*);
};
// Casts apCopy to BGSCameraShot, returns if it fails, then copies the base form and 0x28 bytes from offset 0x38 into this.
// @fnv 0x0058bfc0
void FUN_0058bfc0_shell::CopyFromCameraShot(TESForm* apCopy)
{
    BGSCameraShot* pcopy;
    pcopy = dynamic_cast<BGSCameraShot*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->FUN_004851b0((TESForm*)pcopy);
    __memcpy((char*)this + 0x38, (char*)pcopy + 0x38, 0x28);
}

struct Flt
{
    operator unsigned int() const;
};
struct FUN_0048cee0_shell
{
    char data[0x18];
    int FUN_0048cee0();
};
struct FUN_0058d630_shell
{
    char pad0[0x18];
    FUN_0048cee0_shell model;
    char pad1[8];
    int field_38;
    char pad2[0x30];
    Flt flt;
    bool FUN_0058d630();
};
// @fnv 0x0058d630
bool FUN_0058d630_shell::FUN_0058d630()
{
    if (field_38 == 3)
        return false;
    if (model.FUN_0048cee0() == 0)
        return true;
    if ((unsigned int)flt != 0)
        return true;
    return false;
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};
struct FUN_0058c020_shell
{
    bool FUN_0058c020(TESForm*);
};
int _memcmp(const void*, const void*, unsigned int);
// @fnv 0x0058c020
bool FUN_0058c020_shell::FUN_0058c020(TESForm* apCompare)
{
    BGSCameraShot* pCameraShot = dynamic_cast<BGSCameraShot*>(apCompare);
    if (!pCameraShot)
        return true;
    if (reinterpret_cast<FUN_005e79a0_t*>(this)->FUN_00485270(pCameraShot))
        return true;
    if (_memcmp(reinterpret_cast<char*>(this) + 0x38, reinterpret_cast<char*>(pCameraShot) + 0x38, 0x28))
        return true;
    return false;
}

struct FUN_004855a0
{
    void M();
};
struct FUN_004891d0_obj
{
    void WriteToBuffer(unsigned int, unsigned int);
};
struct FUN_00487450_shell
{
    void FUN_00487450();
};
struct FUN_00485680
{
    void M();
};
struct FUN_00485e00_shell
{
    void FUN_00485e20(int, int);
};
bool __cdecl FUN_00401500();

struct FUN_0058c4d0_shell
{
    void FUN_0058c4d0();
};

// @fnv 0x0058c4d0
void FUN_0058c4d0_shell::FUN_0058c4d0()
{
    ((FUN_004855a0*)this)->M();
    ((FUN_004891d0_obj*)((char*)this + 0x18))->WriteToBuffer(0x4C444F4D, 0x54444F4D);
    if (FUN_00401500())
        ((BGSCameraShot__CAMERA_SHOT_DATA*)((char*)this + 0x38))->FUN_0058c3c0();
    ((FUN_00485e00_shell*)this)->FUN_00485e20((int)((char*)this + 0x38), 0x28);
    if (FUN_00401500())
        ((BGSCameraShot__CAMERA_SHOT_DATA*)((char*)this + 0x38))->FUN_0058c3c0();
    ((FUN_00487450_shell*)((char*)this + 0x30))->FUN_00487450();
    ((FUN_00485680*)this)->M();
}

struct FUN_0058c3c0_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    int field_0x24;

    void FUN_0058c3c0();
};

// Byte-swaps each of the ten 32-bit fields of the object via BSEndian.
// @fnv 0x0058c3c0
void FUN_0058c3c0_shell::FUN_0058c3c0()
{
    BSEndian(&field_0x10, EndianSizeTag<3>());
    BSEndian(&field_0x14, EndianSizeTag<3>());
    BSEndian(&field_0x18, EndianSizeTag<3>());
    BSEndian(&field_0x00, EndianSizeTag<3>());
    BSEndian(&field_0x04, EndianSizeTag<3>());
    BSEndian(&field_0x08, EndianSizeTag<3>());
    BSEndian(&field_0x0c, EndianSizeTag<3>());
    BSEndian(&field_0x1c, EndianSizeTag<3>());
    BSEndian(&field_0x20, EndianSizeTag<3>());
    BSEndian(&field_0x24, EndianSizeTag<3>());
}

struct BaseA_b4203
{
    virtual ~BaseA_b4203();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct BaseB_b4203
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~BaseB_b4203();
};

struct BaseC_b4203
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct MemberA_b4203
{
    unsigned int unk00;
    ~MemberA_b4203();
};

struct MemberB_b4203
{
    unsigned int unk00;
    unsigned int unk04;
    ~MemberB_b4203();
};

class FUN_0058be90 : public BaseA_b4203, public BaseB_b4203, public BaseC_b4203
{
  public:
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    MemberA_b4203 m_60;
    MemberB_b4203 m_64;
    MemberA_b4203 m_6c;
    MemberA_b4203 m_70;
    virtual ~FUN_0058be90();
    void Cleanup();
};

// @fnv 0x0058be90
FUN_0058be90::~FUN_0058be90()
{
    Cleanup();
}

// Stand-in owner class for IsNotFlag4Set.
// The original reads a 32-bit flag field at this+0x44 and returns a bool.
struct FUN_0058d4f0_cls
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    bool IsNotFlag4Set();
};

// @fnv 0x0058d4f0
bool FUN_0058d4f0_cls::IsNotFlag4Set()
{
    return (unk44 & 4) == 0 ? true : false;
}

// NiPoint3: the canonical class (include/NiPoint3.h, via TESObjectREFR.h)
extern NiPoint3 NiPoint3_ZERO;
extern float DAT_011ca738, DAT_011ca73c, DAT_011ca740;
struct Rotation
{
    void DecomposeToEulerAngles(float*, float*, float*);
};
struct CameraNode
{
    const NiPoint3& FUN_0045bb80();
    Rotation* FUN_006a9540();
};
struct NodePointer
{
    CameraNode* FUN_00559450();
};
struct VATSLocation
{
    NiPoint3 FUN_009c9fe0(float);
};
extern VATSLocation DAT_011f2250;
struct CameraShot : BGSCameraShot
{
    float FUN_00639b20();
    NiPoint3 GetCameraPosition();
};
// @fnv 0x0058d510
NiPoint3 CameraShot::GetCameraPosition()
{
    NiPoint3 position = NiPoint3_ZERO;
    if (FUN_00639b20() > 0.0)
    {
        position = DAT_011f2250.FUN_009c9fe0(FUN_00639b20());
    }
    else if (((NodePointer*)&m_pTargetNode)->FUN_00559450())
    {
        position = ((NodePointer*)&m_pTargetNode)->FUN_00559450()->FUN_0045bb80();
    }
    if (m_bUpdateNodePosition == 1 && ((NodePointer*)&m_spPositionNode)->FUN_00559450())
    {
        ((NodePointer*)&m_spPositionNode)
            ->FUN_00559450()
            ->FUN_006a9540()
            ->DecomposeToEulerAngles(&DAT_011ca738, &DAT_011ca73c, &DAT_011ca740);
    }
    else
    {
        DAT_011ca738 = 0.0f;
        DAT_011ca73c = 0.0f;
        DAT_011ca740 = 0.0f;
    }
    return position;
}

// SetupCamera v01 - worker10 one-pass transcription (history draw, fnvrec v1.1)
extern NiPoint3 NiPoint3_ZERO;
extern float DAT_011f21d4;
extern unsigned char DAT_011ca728;
extern unsigned char DAT_011ca729;
extern unsigned char DAT_011e07c3;
extern float DAT_011ca72c;
extern float DAT_011ca730;
extern float DAT_011ca734;
extern NiPoint3 DAT_011ca7a8;
extern NiPoint3 DAT_011ca75c;
extern int DAT_011f4a18;
extern int DAT_011f3714;
extern int DAT_011f3e50;
extern int DAT_011f3e48;

int __cdecl FUN_005b5e40(const char*, const char*);
void* __cdecl FUN_00653270(void*, void*);
void __cdecl FUN_004b70f0(void*, float);

struct SubObj390c0
{
    bool FUN_004390c0(const NiPoint3&);
};
struct CamNodeX
{
    void* FUN_00a5c570(void*);
    void FUN_00a59c60(void*);
    SubObj390c0* FUN_0043c490();
    int FUN_0045bc00(int);
};
struct NodePtrObj
{
    void* m_pObject;
    CamNodeX* FUN_00559450();
    void FUN_0066b0d0(void*);
};
struct ModelLoader
{
    int LoadModel(const char*, int, int, int, int, int);
    int FUN_0045a5e0(const char*);
};
extern ModelLoader* g_modelLoader;
struct ModelSub
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual const char* vfn_14();
    unsigned int FUN_0048cee0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct LookupObj
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual int vfn_c4(int);
};
struct Lookup2
{
    int FUN_0058cb00(int*, int*, unsigned char*);
    bool FUN_0058cae0();
};
struct St28
{
    int f00;
    float f04;
    float f08;
    int f0c;
    int f10;
    int f14;
    int f18;
};
struct FoundObj
{
    St28* FUN_0045bbe0();
};
struct Obj20
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_0043d410(float, int, int);
};
struct BSSoundHandleEx
{
    int m_00;
    int m_04;
    int m_08;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct BSAudio
{
    static BSAudio* FUN_00453a70();
    BSSoundHandleEx FUN_00ad7550(const char*, unsigned int);
};
struct Glob79c
{
    float* FUN_00403e20();
};
extern Glob79c DAT_011ca79c;
struct VatsSub
{
    bool FUN_0058cba0(int);
};
struct VatsState
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    VatsSub* sub14;
};
struct VATSObj
{
    VatsState* FUN_009c71c0();
};
struct PlayerObj
{
    void SyncHolderValue();
};
extern PlayerObj* DAT_011dea3c;

struct ShotThis
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ModelSub model;
    int unk30;
    int unk34;
    int dataAction;
    int dataLocation;
    int dataTarget;
    unsigned int dataFlags;
    float dataPlayerMult;
    float dataTargetMult;
    float dataGlobalMult;
    float dataMaxTime;
    float dataMinTime;
    float dataTargetPct;
    NodePtrObj m_pLocationNode;
    NodePtrObj m_pTargetNode;
    void* m_pReference;
    NodePtrObj m_spPositionNode;
    NodePtrObj m_pSceneObject;
    signed char m_bUpdateNodePosition;
    unsigned char m_bFlag74;
    unsigned char m_bFlag75;
    unsigned char pad77;
    bool IsFlag20Set();
    void SetupCamera(void*, int);
};

// Loads the VATS camera model, validates its NiCamera child and FOV, stores param1, and updates camera globals and sounds based on param2 and dataAction.
// @fnv 0x0058c5d0
void ShotThis::SetupCamera(void* param1, int iMode)
{
    void* myFoundPtr;
    if (model.FUN_0048cee0())
    {
        m_spPositionNode.FUN_0066b0d0((void*)g_modelLoader->LoadModel(model.vfn_14(), 0, 1, 1, 0, 0));
    }
    myFoundPtr = m_spPositionNode.FUN_00559450()
                     ? FUN_00653270(&DAT_011f4a18, (void*)m_spPositionNode.FUN_00559450()->FUN_0045bc00(0))
                     : 0;
    if (!myFoundPtr)
    {
        FUN_005b5e40(
            "DEFAULT: VATS Camera '%s' doesn't have an NiCamera as the first child. This camera will not be used.",
            model.vfn_14());
        m_spPositionNode.FUN_0066b0d0(0);
        g_modelLoader->FUN_0045a5e0(model.vfn_14());
    }
    if (m_spPositionNode.FUN_00559450())
    {
        Obj20 auxPtr;
        auxPtr.FUN_0043d410(DAT_011f21d4, 1, 0);
        if (IsFlag20Set())
        {
            FUN_004b70f0(m_spPositionNode.FUN_00559450(), -DAT_011f21d4);
        }
        m_spPositionNode.FUN_00559450()->FUN_00a59c60(&auxPtr);
        if ((signed char)m_bUpdateNodePosition == -1 && !m_bFlag75)
        {
            void* queriedVal = m_spPositionNode.FUN_00559450()->FUN_00a5c570(&DAT_011f3714);
            if (queriedVal)
            {
                void* clonePtr = queriedVal;
                int held2 = ((LookupObj*)clonePtr)->vfn_c4(0);
                void* altObj2Val = FUN_00653270(&DAT_011f3e50, (void*)held2);
                void* myAltPtr = 0;
                if (altObj2Val)
                {
                    int resA;
                    int chkBPtr;
                    unsigned char flagCX;
                    int answer = ((Lookup2*)altObj2Val)->FUN_0058cb00(&resA, &chkBPtr, &flagCX);
                    (void)answer;
                    if (resA)
                    {
                        m_bUpdateNodePosition = 1;
                    }
                }
                else
                {
                    myAltPtr = FUN_00653270(&DAT_011f3e48, (void*)held2);
                }
                if (myAltPtr && ((Lookup2*)myAltPtr)->FUN_0058cae0())
                {
                    m_bUpdateNodePosition = 1;
                }
                if ((signed char)m_bUpdateNodePosition == -1)
                {
                    m_bUpdateNodePosition = 0;
                }
            }
        }
        if (m_spPositionNode.FUN_00559450()->FUN_0043c490()->FUN_004390c0(NiPoint3_ZERO))
        {
            FUN_005b5e40("DEFAULT: VATS Camera '%s' doesn't have any position data.", model.vfn_14());
        }
        St28 attrs2;
        attrs2 = *((FoundObj*)myFoundPtr)->FUN_0045bbe0();
        if (attrs2.f08 / attrs2.f04 < (double)0.74f)
        {
            FUN_005b5e40("DEFAULT: VATS Camera '%s' has a bad FOV that was not created for a 4x3 aspect ratio.",
                         model.vfn_14());
        }
    }
    m_pReference = param1;
    DAT_011e07c3 = 1;
    switch (iMode)
    {
    case 0:
        DAT_011ca728 = 1;
        DAT_011ca734 = *DAT_011ca79c.FUN_00403e20();
        break;
    case 1:
        DAT_011ca728 = 0;
        break;
    case 2:
        if (dataAction == 3)
        {
            DAT_011ca728 = 1;
            if (dataMinTime > 0.0f)
            {
                DAT_011ca734 = dataMinTime;
            }
            else
            {
                DAT_011ca734 = *DAT_011ca79c.FUN_00403e20();
            }
        }
        break;
    }
    DAT_011ca72c = 0.0f;
    DAT_011ca730 = 0.0f;
    DAT_011ca7a8 = NiPoint3_ZERO;
    DAT_011ca75c = NiPoint3_ZERO;
    VatsState* vatsPtr2 = ((VATSObj*)&DAT_011f2250)->FUN_009c71c0();
    if (vatsPtr2 && !DAT_011ca729 &&
        (vatsPtr2->sub14->FUN_0058cba0(4) || vatsPtr2->sub14->FUN_0058cba0(8) || vatsPtr2->sub14->FUN_0058cba0(0x10)))
    {
        if (dataAction == 2)
        {
            DAT_011ca729 = 1;
            BSSoundHandleEx camIn2 = BSAudio::FUN_00453a70()->FUN_00ad7550("UIVATSCameraIn", 0x121);
            camIn2.Play(false);
        }
    }
    else
    {
        if (DAT_011ca729 && dataAction != 2)
        {
            DAT_011ca729 = 0;
            BSSoundHandleEx bannerOutPtr = BSAudio::FUN_00453a70()->FUN_00ad7550("UIVATSCameraOut", 0x121);
            bannerOutPtr.Play(false);
        }
    }
    DAT_011dea3c->SyncHolderValue();
}

struct NiPoint3Ex;
struct NiPoint3;
struct M3
{
    float m[9];
};
struct Frus
{
    float left;
    float right;
    float top;
    float bottom;
    float nearPlane;
    float farPlane;
    bool orthographic;
};
struct NiUpdateData
{
    float a;
    int b;
    int c;
    NiUpdateData(float, bool, bool);
};
struct Host56
{
    M3 FUN_0056fa00();
};
struct Rot56
{
};
struct Node60
{
    const NiPoint3& FUN_0045bb80();
    Host56* FUN_006a9540();
};
struct Prop
{
    const Frus& FUN_0045bbe0();
};
struct Anim
{
    const Frus& FUN_0045bbe0();
    void FUN_00a6faf0(Frus*);
};
struct MidX
{
    Anim* FUN_006629f0();
};
struct Node6c
{
    void FUN_00a59c60(const NiUpdateData&);
    const NiPoint3& FUN_0043c490();
    Prop* FUN_0045bc00(int);
};
struct NiPtr60
{
    Node60* object;
    Node60* FUN_00559450();
};
struct NiPtr6c
{
    Node6c* object;
    Node6c* FUN_00559450();
};
struct Rend
{
    unsigned int FUN_004dee10();
    unsigned int FUN_004dee70();
};
Rend* __cdecl FUN_0043c4b0();
MidX* __cdecl FUN_0045c670();
struct GObj
{
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w030();
    virtual void w031();
    virtual void w032();
    virtual void w033();
    virtual void w034();
    virtual void w035();
    virtual void w036();
    virtual void w037();
    virtual void w038();
    virtual void w039();
    virtual void w040();
    virtual void w041();
    virtual void w042();
    virtual void w043();
    virtual void w044();
    virtual void w045();
    virtual void w046();
    virtual void w047();
    virtual void w048();
    virtual void w049();
    virtual void w050();
    virtual void w051();
    virtual void w052();
    virtual void w053();
    virtual void w054();
    virtual void w055();
    virtual void w056();
    virtual void w057();
    virtual void w058();
    virtual void w059();
    virtual void w060();
    virtual void w061();
    virtual void w062();
    virtual void w063();
    virtual void w064();
    virtual void w065();
    virtual void w066();
    virtual void w067();
    virtual void w068();
    virtual void w069();
    virtual void w070();
    virtual void w071();
    virtual void w072();
    virtual void w073();
    virtual void w074();
    virtual void w075();
    virtual void w076();
    virtual void w077();
    virtual void w078();
    virtual void w079();
    virtual void w080();
    virtual void w081();
    virtual void w082();
    virtual void w083();
    virtual void w084();
    virtual void w085();
    virtual void w086();
    virtual void w087();
    virtual void w088();
    virtual void w089();
    virtual void w090();
    virtual void w091();
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
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
    virtual void w137();
    virtual void w138();
    virtual bool Check22c(int);
    void ToggleFirstPerson(int);
    void FUN_0094a0c0(NiPoint3*, NiPoint3*, int);
};
class LenShell;
class PtOp
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3&) const;
    LenShell* FUN_00439ef0();
};

class NiPoint3_helper
{
  public:
    NiPoint3Ex operator*(float) const;
};
class PtSub
{
  public:
    NiPoint3& operator-=(const NiPoint3&);
};
class PtTest
{
  public:
    bool FUN_004390c0(const NiPoint3&);
};
class LenShell
{
  public:
    float FUN_00457990();
};
float* __fastcall FUN_00403e20(void*);
void __cdecl FUN_00a582f0(const M3&, void*, int, NiPoint3&, NiPoint3&);
void __cdecl FUN_00a582f0(Host56*, void*, int, NiPoint3&, NiPoint3&);
extern NiPoint3 DAT_011ca77c;
extern NiPoint3 DAT_011ca75c;
extern NiPoint3 DAT_011e0808;
extern NiPoint3 DAT_011ca7a8;
extern NiPoint3 DAT_011f426c;
extern float DAT_011ca72c;
extern float DAT_011ca730;
extern float DAT_011ca734;
extern unsigned char DAT_011ca728;
extern unsigned char DAT_011ca729;
extern Host56* DAT_011f21f0;
extern float DAT_011ca76c;
extern float DAT_011ca7d0;
struct NiPoint3Ex
{
    float x;
    float y;
    float z;
    NiPoint3Ex operator-(const NiPoint3&) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
    float Length() const;
};
struct Shot
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
    int f38;
    int f3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    NiPtr60 m60;
    int f64;
    Host56* f68;
    NiPtr6c m6c;
    int f70;
    char c74;
    unsigned char c75;
    char c76;
    char c77;
    bool IsFlagSet();
    bool IsNotFlag4Set();
    NiPoint3Ex GetCameraPosition();
    void UpdateCamera(float);
};
// Updates the camera node with NiUpdateData, adjusts its position and frustum, and tracks camera-in transition progress.
// @fnv 0x0058cf60
void Shot::UpdateCamera(float afTime)
{
    if (!m6c.FUN_00559450())
        return;
    NiUpdateData upd(afTime, true, false);
    m6c.FUN_00559450()->FUN_00a59c60(upd);
    DAT_011ca77c = m6c.FUN_00559450()->FUN_0043c490();
    NiPoint3 pt = DAT_011ca77c;
    if (c75 && !reinterpret_cast<GObj*>(DAT_011dea3c)->Check22c(0))
        reinterpret_cast<GObj*>(DAT_011dea3c)->ToggleFirstPerson(1);
    else
    {
        if (IsFlagSet())
        {
            if (!IsNotFlag4Set() || f68 == 0 || f3c != 2)
            {
                NiPoint3 tmpA = pt;
                FUN_00a582f0(DAT_011f21f0->FUN_0056fa00(), &DAT_011f426c, 1, tmpA, pt);
            }
            else
            {
                NiPoint3 tmpB = pt;
                FUN_00a582f0(f68->FUN_0056fa00(), &DAT_011f426c, 1, tmpB, pt);
            }
        }
        else if (m60.FUN_00559450())
        {
            NiPoint3 tmpC = pt;
            FUN_00a582f0(m60.FUN_00559450()->FUN_006a9540(), &DAT_011f426c, 1, tmpC, pt);
        }
        if (m60.FUN_00559450())
        {
            bool bReset = false;
            if (((PtTest*)&DAT_011ca75c)->FUN_004390c0(DAT_011f426c))
            {
                DAT_011ca75c = DAT_011e0808;
                bReset = true;
            }
            NiPoint3 kPos = m60.FUN_00559450()->FUN_0045bb80();
            ((PtSub*)&pt)->operator-=(kPos);
            reinterpret_cast<GObj*>(DAT_011dea3c)->FUN_0094a0c0(&pt, &kPos, 0);
            DAT_011e0808 = pt;
            if (DAT_011ca728)
            {
                *(NiPoint3Ex*)&DAT_011ca7a8 = *(NiPoint3Ex*)&DAT_011e0808 - DAT_011ca75c;
                if (((NiPoint3Ex*)&DAT_011ca7a8)->Length() <= *FUN_00403e20(&DAT_011ca76c))
                {
                    DAT_011ca728 = 0;
                    DAT_011ca72c = 0.0f;
                }
                else if (f38 == 0)
                {
                    DAT_011ca728 = 0;
                    DAT_011ca72c = 0.0f;
                }
                else
                {
                    if (bReset && !DAT_011ca729)
                    {
                        BSSoundHandleEx snd = BSAudio::FUN_00453a70()->FUN_00ad7550("UIVATSCameraIn", 0x121);
                        snd.Play(false);
                    }
                    DAT_011ca730 = (1.0f / DAT_011ca734) * (afTime - DAT_011ca72c);
                    if (DAT_011ca730 >= 1.0)
                    {
                        DAT_011ca728 = 0;
                        DAT_011ca72c = 0.0f;
                    }
                    else
                        *(NiPoint3Ex*)&DAT_011e0808 =
                            *(NiPoint3Ex*)&DAT_011ca75c + ((NiPoint3_helper*)&DAT_011ca7a8)->operator*(DAT_011ca730);
                }
            }
            Prop* pCam = m6c.FUN_00559450()->FUN_0045bc00(0);
            if (pCam)
            {
                Frus kOrigFrustum = pCam->FUN_0045bbe0();
                Anim* pMainCamera = FUN_0045c670()->FUN_006629f0();
                Frus kFrustum = pMainCamera->FUN_0045bbe0();
                float scale =
                    (double)FUN_0043c4b0()->FUN_004dee10() / (double)FUN_0043c4b0()->FUN_004dee70() / 1.3333334f;
                kFrustum.left = kOrigFrustum.left * scale;
                kFrustum.right = kOrigFrustum.right * scale;
                kFrustum.top = kOrigFrustum.top;
                kFrustum.bottom = kOrigFrustum.bottom;
                pMainCamera->FUN_00a6faf0(&kFrustum);
            }
        }
    }
    if ((GetCameraPosition() - pt).Length() <= *FUN_00403e20(&DAT_011ca7d0))
        c75 = 1;
}
