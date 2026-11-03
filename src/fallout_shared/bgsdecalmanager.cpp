// fallout_shared/bgsdecalmanager.cpp: BGSDecalManager, BSA_, PD_, M3_ and more (61 functions)

#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"

// @fnv 0x004a0030
void BGSDecalManager::RenderDecals()
{
    if (reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&m_kSimpleDecalList)->GetSize() > 0)
    {
        FUN_0043c4b0()->StartScene();
        struct IteratorState
        {
            unsigned int previous;
            unsigned int position;
        } iterator;
        iterator.position = reinterpret_cast<unsigned int>(static_cast<BSFaceGenAnimationData*>(
            *reinterpret_cast<NiPointer<BSFaceGenAnimationData>*>(&m_kSimpleDecalList)));
        while (iterator.position != 0)
        {
            iterator.previous = iterator.position;
            BSTempEffectSimpleDecal* decal = reinterpret_cast<BSTempEffectSimpleDecal*>(
                static_cast<BSFaceGenAnimationData*>(reinterpret_cast<NiPointer<BSFaceGenAnimationData>&>(
                    reinterpret_cast<NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->GetNext(reinterpret_cast<void*&>(iterator.position)))));
            if (decal != 0)
            {
                if (decal->m_bNeedsManagerUpdate)
                {
                    RemoveDecal(decal);
                    decal->m_bNeedsManagerUpdate = false;
                }

                if (decal->m_pRenderQuery != 0)
                {
                    if (decal->ReleaseTextureObject())
                    {
                        if (decal->m_uiTextureReferenceCount > 0)
                        {
                            if (*DAT_011c5904.GetLifeStateControlFlag())
                                Warning(DAT_0101e1c8, decal->FUN_004a0330()->GetLinkToList()->FUN_0043b1b0());
                            reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                        }
                        else
                        {
                            if (*DAT_011c5904.GetLifeStateControlFlag())
                                Warning(DAT_0101e19c, decal->FUN_004a0330()->GetLinkToList()->FUN_0043b1b0());
                            decal->bWasPlaying = true;
                        }
                    }
                }
                else
                {
                    reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                }

                if (decal->m_bTextureDirty && !decal->bWasPlaying)
                    decal->CreateDecalTexture();

                if (decal->bWasPlaying)
                {
                    if (decal->GetByteAt2D())
                    {
                        ++DAT_011c57ec;
                        if (*DAT_011c5904.GetLifeStateControlFlag())
                            Warning(DAT_0101e174, DAT_011c57ec, decal->FUN_004a0330()->GetLinkToList()->FUN_0043b1b0());

                        if (DAT_011c57f4 & 1)
                        {
                            ImageSpaceEffectParam color(0.0f, 1.0f, 0.0f, 1.0f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            ImageSpaceEffectParam color(0.0f, 1.0f, 0.0f, 0.25f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), false);
                        }
                    }
                    else if (DAT_011c57f4 & 0x10)
                    {
                        if (DAT_011c57f4 & 1)
                        {
                            ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 1.0f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 0.25f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), false);
                        }
                    }
                    reinterpret_cast<NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->RemovePos(reinterpret_cast<void*&>(iterator.previous));
                }
            }
        }
        FUN_0043c4b0()->FinishScene();
    }
}

// @fnv 0x00460140
int __fastcall FUN_00460140(int apBase)
{
    return apBase + 0x10;
}

struct NiStream;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];
struct FUN_004769c0_shell : public ThreeByThreeMatrix
{
    void FUN_004769c0(unsigned int, float*);
};

// @fnv 0x004769c0
void FUN_004769c0_shell::FUN_004769c0(unsigned int uiCol, float* col)
{
    ((float(*)[3])m_afEntries)[0][uiCol] = col[0];
    ((float(*)[3])m_afEntries)[1][uiCol] = col[1];
    ((float(*)[3])m_afEntries)[2][uiCol] = col[2];
}

class Date
{
  public:
    ~Date();
};

void __fastcall FUN_0082f1b0(void*);
int __fastcall CallNestedAtOffset80(void*);

// @fnv 0x004a0370
void __fastcall FUN_004a0370(char* pThis)
{
    FUN_0082f1b0(pThis + 0x80);
    if (CallNestedAtOffset80(pThis) == 1)
    {
        ((Date*)pThis)->Date::~Date();
    }
}

namespace fnv_004a03c0 {
struct RecursiveLock
{
    void Leave();
};
struct Date
{
    ~Date();
};
struct DD : Date
{
    int CallNestedAtOffset80();
    void FUN_004a03c0();
};
// @fnv 0x004a03c0
void DD::FUN_004a03c0()
{
    if (CallNestedAtOffset80() == 1)
        Date::~Date();
    ((RecursiveLock*)((char*)this + 0x80))->Leave();
}
}  // namespace fnv_004a03c0

struct P3
{
    float x, y, z;
    void Set(float, float, float);
    P3* FUN_004a0bd0(P3*);
};
// Writes the negated x, y and z components into out and returns out.
// @fnv 0x004a0bd0
P3* P3::FUN_004a0bd0(P3* out)
{
    out->Set(-x, -y, -z);
    return out;
}

// @fnv 0x004a0d10
void* __fastcall FUN_004a0d10(char* pThis)
{
    return pThis + 0x100;
}

template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer<NiNode>& operator=(NiNode*);
};

struct FUN_004a0fd0_shell
{
    char pad[0xc4];
    NiPointer<NiNode> m_pController;
    void FUN_004a0fd0(NiNode* apNode);
};

// @fnv 0x004a0fd0
void FUN_004a0fd0_shell::FUN_004a0fd0(NiNode* apNode)
{
    m_pController = apNode;
}

struct BSA_
{
    void FUN_004a1020(void*);
};
// @fnv 0x004a1020
void BSA_::FUN_004a1020(void* p)
{
    *(void**)((char*)this + 0x194) = p;
}

struct FUN_004a1040_Helper
{
    char pad[0x19c];
    int field_19c;
    void Set(int val);
};

// @fnv 0x004a1040
void FUN_004a1040_Helper::Set(int val)
{
    field_19c = val;
}

struct Fake_FUN_004a2020
{
    char pad[0x20];
    unsigned int ulFlags[2];
    bool GetFlag(unsigned int aiFlag) const;
};

static bool (Fake_FUN_004a2020::*pfn_FUN_004a2020)(unsigned int) const = &Fake_FUN_004a2020::GetFlag;

// Tests whether the bit for aiFlag is set in the ulFlags bit array, indexing by aiFlag>>5 and masking with 1<<(aiFlag%32).
// @fnv 0x004a2020
bool Fake_FUN_004a2020::GetFlag(unsigned int aiFlag) const
{
    unsigned int uiindex = aiFlag >> 5;
    unsigned int uibit = aiFlag % 32;
    unsigned int uimask = 1 << uibit;
    return (ulFlags[uiindex] & uimask) > 0;
}

class BGSTerrainManager
{
  public:
    unsigned int GetMinLevel();
};

// Returns 0 for a null pointer, otherwise returns whether GetMinLevel() is between 1 and 12.
// @fnv 0x004a2c20
int __cdecl FUN_004a2c20(BGSTerrainManager* apShaderProp)
{
    if (!apShaderProp)
    {
        return 0;
    }
    int itp = apShaderProp->GetMinLevel();
    return itp >= 1 && itp <= 12;
}

struct __declspec(align(16)) VectorComponentValue
{
    char pad[16];
    float FUN_004586d0(void) const;
};

struct hkVector4
{
    VectorComponentValue& FUN_00458700(VectorComponentValue&, int) const;
};

struct NiPoint3_local
{
    float x, y, z;
};

// Reads components 0, 1 and 2 of arhkV into arNiP.x, arNiP.y and arNiP.z and returns arNiP.
// @fnv 0x004a3970
NiPoint3_local& __cdecl FUN_004a3970(NiPoint3_local& arNiPoint, const hkVector4& arHkVector)
{
    VectorComponentValue t0, t1, t2;
    arNiPoint.x = arHkVector.FUN_00458700(t0, 0).FUN_004586d0();
    arNiPoint.y = arHkVector.FUN_00458700(t1, 1).FUN_004586d0();
    arNiPoint.z = arHkVector.FUN_00458700(t2, 2).FUN_004586d0();
    return arNiPoint;
}

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
struct FUN_004a39f0_shell : public CFilter
{
    void FUN_004a39f0(int);
};

// Clears the low 7 bits of iFilter and stores the low 7 bits of aeLayer into them.
// @fnv 0x004a39f0
void FUN_004a39f0_shell::FUN_004a39f0(int aeLayer)
{
    iFilter &= ~0x7f;
    iFilter |= (aeLayer & 0x7f);
}

namespace fnv_004a3a20 {
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
struct FUN_004a3a20_shell : public CFilter
{
    unsigned int FUN_004a3a20();
};

// @fnv 0x004a3a20
unsigned int FUN_004a3a20_shell::FUN_004a3a20()
{
    return (iFilter >> 16) & 0xFFFF;
}
}  // namespace fnv_004a3a20

class TESObjectREFR
{
  public:
    unsigned int GetFlags();
};

// Returns the flags of apRef, or 0 when apRef is null.
// @fnv 0x004a3a40
unsigned int __cdecl FUN_004a3a40(TESObjectREFR* apRef)
{
    return apRef ? apRef->GetFlags() : 0;
}

void __fastcall FUN_004a3b70(void*);

struct Base_004a3b30
{
    int pad[3];
    Base_004a3b30();
    virtual ~Base_004a3b30();
};

struct Member_004a4730
{
    Member_004a4730(int);
    ~Member_004a4730();
};

struct FUN_004a3a70 : Base_004a3b30
{
    Member_004a4730 m;
    FUN_004a3a70();
    virtual ~FUN_004a3a70();
};

// Initializes the base subobject, constructs member m with 0, then calls FUN_004a3b70 on this.
// @fnv 0x004a3a70
FUN_004a3a70::FUN_004a3a70() : m(0)
{
    FUN_004a3b70(this);
}

namespace fnv_004a3da0 {
struct NiAVObject;
struct FourComponentNumericValue;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_004a3da0_shell : public BhkPickData
{
    void FUN_004a3da0(void*);
};

struct __declspec(align(16)) hkVector4
{
    char m_vComponents[16];
    void _ref_006815c0();
};

struct FUN_0056d340_helper
{
    void FUN_0056d340(hkVector4&);
};

hkVector4& __cdecl FUN_004a3e00(hkVector4&, NiPoint3 const&);

// Converts the NiPoint3 at arFrom into a hkVector4 and passes it to FUN_0056d340 on this object.
// @fnv 0x004a3da0
void FUN_004a3da0_shell::FUN_004a3da0(void* arFrom)
{
    hkVector4 hkv;
    hkv._ref_006815c0();
    ((FUN_0056d340_helper*)this)->FUN_0056d340(FUN_004a3e00(hkv, *(const NiPoint3*)arFrom));
}
}  // namespace fnv_004a3da0

void* FUN_00458b20();
struct T_
{
    void FUN_004a3f10(void*);
};
struct PD_
{
    void ForwardToSubObject(void*);
    void FUN_004a3f40(void*);
};
// Calls ForwardToSubObject with the result of FUN_00458b20, then forwards p to FUN_004a3f10 on the object at this+0x10.
// @fnv 0x004a3f40
void PD_::FUN_004a3f40(void* p)
{
    ForwardToSubObject(FUN_00458b20());
    ((T_*)((char*)this + 0x10))->FUN_004a3f10(p);
}

struct Flt
{
    int v;
    operator unsigned int() const;
};
// @fnv 0x004a3f70
void __fastcall FUN_004a3f70(char* self, Flt f)
{
    *(unsigned int*)(self + 0x24) = (unsigned int)f;
}

struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_004a3fb0_shell : public BhkPickData
{
    void FUN_004a3fb0(hkpAllRayHitCollector*);
};

// @fnv 0x004a3fb0
void FUN_004a3fb0_shell::FUN_004a3fb0(hkpAllRayHitCollector* apCollector)
{
    m_pAllCollector = apCollector;
    m_pClosestCollector = 0;
}

struct NiSourceTexture;
struct ScriptCompiler;
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    static void Release();
    ScriptCompiler* QConsoleCompiler();
    void Init();
    void DoThis(char*);
    bool Idle(int);
    void PrintFormatted(char*, ...);
    void PrintFormatted(char*, char*);
    void ScrollBy(int);
    void ResetOutputState();
    bool GetLastMenuMode();
    int GetConsoleLineSpacing();
    void SetOutputFilename(char*);
    void WriteToOutputFile(char*);
    bool IsOutputFileEnabled();
    bool IsVisible();
    void SetVisible(char);
    void OnEnterMenuMode();
    void OnLeaveMenuMode();
    void DumpTextureList();
    bool ShouldDumpTexture(NiSourceTexture*);
    void* __vecDelDtor(unsigned int);
    ScriptCompiler* m_pScriptCompiler;
    char m_kOutputLines[12];
    char m_kCommandHistory[12];
    int m_iCommandHistoryPosition;
    int m_iScrollPosition;
    int m_iOutputLineCount;
    bool m_bVisible;
    char _pad_29[3];
    int iConsoleLineSpacing;
    int m_iConsoleX;
    int m_iConsoleY;
    char cVisible;
    bool bIsActive;
    bool m_bRecordingBatch;
    char _pad_3b[1];
    int m_iBatchCommandCount;
    char m_aacCommandHistory[2000];
    char m_acOutputFilename[260];
};
typedef char _sizecheck_MenuConsole[sizeof(ConsoleManager) == 2324 ? 1 : -1];
struct FUN_004a4020_shell : public ConsoleManager
{
    bool IsConsoleOpen();
};

// @fnv 0x004a4020
bool FUN_004a4020_shell::IsConsoleOpen()
{
    return cVisible > 0;
}

struct M3_
{
    void FUN_004b4660(unsigned int, float, float, float);
};
// @fnv 0x004b4660
void M3_::FUN_004b4660(unsigned int uiIndex, float afValue0, float afValue1, float afValue2)
{
    *(float*)((char*)this + uiIndex * 4) = afValue0;
    *(float*)((char*)this + uiIndex * 4 + 12) = afValue1;
    *(float*)((char*)this + uiIndex * 4 + 24) = afValue2;
}

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_0056d340(unsigned int f);
};
// @fnv 0x0056d340
bool S3e60::FUN_0056d340(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

namespace fnv_008cdd90 {
struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_008cdd90_shell : public BhkPickData
{
    hkpAllRayHitCollector* FUN_008cdd90();
};

// @fnv 0x008cdd90
hkpAllRayHitCollector* FUN_008cdd90_shell::FUN_008cdd90()
{
    return m_pAllCollector;
}
}  // namespace fnv_008cdd90

struct BSCompoundFrustum;
struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct NiAVObject;
struct NiAccumulator;
struct NiCullingProcess;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct NiVisibleArray;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;

struct GO
{
    GO(int);
};
struct FUN_00a69400
{
    FUN_00a69400(NiVisibleArray*);
    virtual ~FUN_00a69400();
    char pad04[0x8c];
};
class FUN_004a0eb0 : public FUN_00a69400
{
  public:
    int i90;
    char pad94[0x28];
    int ibc;
    int ic0;
    GO go;
    FUN_004a0eb0(NiVisibleArray* apVisibleSet);
    virtual ~FUN_004a0eb0();
};
// @fnv 0x004a0eb0
FUN_004a0eb0::FUN_004a0eb0(NiVisibleArray* apVisibleSet) : FUN_00a69400(apVisibleSet), i90(0), ibc(0), ic0(0), go(0)
{}

struct FUN_004a4440
{
    ~FUN_004a4440();
};
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    char pad04[0xc];
};
class FUN_004a3bc0 : public FUN_004a3ae0
{
  public:
    FUN_004a4440 hits;
    virtual ~FUN_004a3bc0();
};
// @fnv 0x004a3bc0
FUN_004a3bc0::~FUN_004a3bc0()
{}

extern int g_012030a8;

struct FUN_004a0f50_shell
{
    int* __thiscall GetGlobalIntPtr();
};

// @fnv 0x004a0f50
int* FUN_004a0f50_shell::GetGlobalIntPtr()
{
    return &g_012030a8;
}

struct GlobalObject_0044f440
{
    float FUN_00450410(void);
};

GlobalObject_0044f440 g_011c77a8;

// @fnv 0x004a19f0
float FUN_004a19f0()
{
    return g_011c77a8.FUN_00450410();
}

namespace fnv_004a1a00 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};

GlobalObject_0044f440 g_011c7588;

// @fnv 0x004a1a00
void __cdecl FUN_004a1a00()
{
    g_011c7588.FUN_00450410();
}
}  // namespace fnv_004a1a00

void __fastcall FUN_004a47b0(int __this);

// @fnv 0x004a1a30
void __fastcall FUN_004a1a30(int __this)
{
    FUN_004a47b0(__this);
}

// @fnv 0x004a3b50
void __fastcall FUN_004a3b50(void* thisPtr)
{
    ((float*)thisPtr)[1] = 1.0f;
}

struct FUN_00acbb70_shell
{
    void FUN_00acbb70();
};

void FUN_00acbb70_shell::FUN_00acbb70()
{}

struct FUN_004a03a0_shell
{
    void CallNestedAtOffset80();
};

// @fnv 0x004a03a0
void FUN_004a03a0_shell::CallNestedAtOffset80()
{
    ((FUN_00acbb70_shell*)((char*)this + 0x80))->FUN_00acbb70();
}

struct FUN_004a0d30_shell
{
    char m_auiShapeKeys[0x34];
    NiPoint3 m_kPoint;
    NiPoint3& FUN_004a0d30(NiPoint3& akDest);
};

// Copies the stored NiPoint3 into akDest and returns akDest.
// @fnv 0x004a0d30
NiPoint3& FUN_004a0d30_shell::FUN_004a0d30(NiPoint3& akDest)
{
    akDest = m_kPoint;
    return akDest;
}

struct NiPoint3_Set
{
    void Set(float x, float y, float z);
};

// Multiplies pA and pB component-wise, stores the result into pDest via Set, and returns pDest.
// @fnv 0x004a1f90
NiPoint3* MultiplyComponents(NiPoint3* pResult, const NiPoint3* pLeft, const NiPoint3* pRight)
{
    ((NiPoint3_Set*)pResult)->Set(pLeft->x * pRight->x, pLeft->y * pRight->y, pLeft->z * pRight->z);
    return pResult;
}

extern int DAT_0101e594;

struct FUN_004a3ae0_shell
{
    void FUN_004a3ae0();
};

// @fnv 0x004a3ae0
void FUN_004a3ae0_shell::FUN_004a3ae0()
{
    *(int*)this = (int)&DAT_0101e594;
}

extern int DAT_0101e594;
void __fastcall FUN_004a3b50(void*);

struct FUN_004a3b30_shell
{
    int* m_vftable;
    void* InitializeVftable();
};

// @fnv 0x004a3b30
void* __thiscall FUN_004a3b30_shell::InitializeVftable()
{
    m_vftable = &DAT_0101e594;
    FUN_004a3b50(this);
    return this;
}

void __fastcall FUN_00626870(void* p);
void __fastcall FUN_004a3b50(void* p);

// @fnv 0x004a3b70
void __fastcall FUN_004a3b70(void* p)
{
    FUN_00626870((char*)p + 0x10);
    FUN_004a3b50(p);
}

namespace fnv_004a3f90 {
struct T_
{
    void FUN_004a3f10(void*);
    void ForwardToSubObject(void*);
};

// @fnv 0x004a3f90
void __thiscall T_::ForwardToSubObject(void* apParam)
{
    ((T_*)((char*)this + 0x90))->FUN_004a3f10(apParam);
}
}  // namespace fnv_004a3f90

namespace bsrandom_singleton {
struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator(void);
    void __thiscall AddGeometryDecal(void* a, int b, char c);
};
}

struct FUN_004a3fe0_shell
{
    void __thiscall FUN_004a3fe0(void* a, int b, char c);
};

// @fnv 0x004a3fe0
void __thiscall FUN_004a3fe0_shell::FUN_004a3fe0(void* pObject, int b, char c)
{
    if (*(int*)((char*)pObject + 0x48) == 0)
    {
        *(int*)((char*)pObject + 0x48) = (int)this;
    }
    bsrandom_singleton::MersenneTwister::GetRandomGenerator()->AddGeometryDecal(pObject, b, c);
}

void __cdecl FUN_00ec6f20(int, int, int, int);
struct FUN_0049f560_Holder
{
    int _00;
    int _04;
    int _08;
    void CallWithTwelve(int);
};
// Calls FUN_00ec6f20 with the holder's _04 and _08 fields, the constant 12, and a1.
// @fnv 0x0049f560
void FUN_0049f560_Holder::CallWithTwelve(int a1)
{
    FUN_00ec6f20(_04, _08, 12, a1);
}

void __cdecl FUN_004a0010();
struct S004a03f0
{
    void CleanupDecalEmitters();
};
// @fnv 0x0049fff0
void __fastcall FUN_0049fff0(BGSDecalManager* p)
{
    FUN_004a0010();
    p->RenderDecals();
    ((S004a03f0*)p)->CleanupDecalEmitters();
}

void _Deallocate(void*);
struct StandIn
{
    void FUN_004a2cf0();
    void* FUN_004a0490(unsigned int);
};
// Calls FUN_004a2cf0, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x004a0490
void* StandIn::FUN_004a0490(unsigned int flags)
{
    FUN_004a2cf0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BSCullingProcess
{
    void FUN_004a0f60();
    void* FUN_004a0ff0(unsigned int flags);
};
void _Deallocate(void*);
// Calls FUN_004a0f60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004a0ff0
void* BSCullingProcess::FUN_004a0ff0(unsigned int flags)
{
    FUN_004a0f60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl SetSelectionMask(int, int, int);
struct Unk
{
    void __thiscall FUN_004a1a10(int, unsigned char);
};
// @fnv 0x004a1a10
void __thiscall Unk::FUN_004a1a10(int aiArg, unsigned char b)
{
    SetSelectionMask(0x27, aiArg, b);
}

namespace fnv_004a3b00 {
void _Deallocate(void*);
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    void* DestroyAndFree(unsigned int);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x004a3b00
void* FUN_004a3ae0::DestroyAndFree(unsigned int flags)
{
    this->FUN_004a3ae0::~FUN_004a3ae0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004a3b00

namespace fnv_004a3b90 {
void __cdecl _Deallocate(void*);
struct FUN_004a3bc0
{
    virtual ~FUN_004a3bc0();
};
struct XHolder : FUN_004a3bc0
{
    void* DestroyAndMaybeDeallocate(unsigned int);
};
// Runs the base destructor, then frees this object via _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x004a3b90
void* XHolder::DestroyAndMaybeDeallocate(unsigned int flags)
{
    this->FUN_004a3bc0::~FUN_004a3bc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004a3b90

struct FUN_004a0350_shell
{
    char bUnk2d;
    char GetByteAt2D();
};

// @fnv 0x004a0350
char FUN_004a0350_shell::GetByteAt2D()
{
    return *(char*)((char*)this + 0x2d);
}

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
};

struct FUN_004a19d0_shell
{
    void FUN_004a19d0();
};

// @fnv 0x004a19d0
void FUN_004a19d0_shell::FUN_004a19d0()
{
    reinterpret_cast<FUN_00456630_helper*>(this)->FUN_00456630(0x400);
}

namespace fnv_004a1a50 {
struct M788
{
    void FUN_004ed8c0(void*);
};
struct bsrandom_singleton
{
    struct MersenneTwister
    {
        static bsrandom_singleton::MersenneTwister* GetRandomGenerator();
    };
};
// @fnv 0x004a1a50
void __cdecl FUN_004a1a50(void* apEmitter)
{
    if (apEmitter)
        ((M788*)((char*)bsrandom_singleton::MersenneTwister::GetRandomGenerator() + 0x14))->FUN_004ed8c0(&apEmitter);
}
}  // namespace fnv_004a1a50

namespace fnv_004a0330 {
struct Flt
{
    operator unsigned int() const;
};

struct FUN_004a0330_shell
{
    char pad[0x10c];
    Flt f;
    unsigned int FUN_004a0330();
};

// @fnv 0x004a0330
unsigned int FUN_004a0330_shell::FUN_004a0330()
{
    return static_cast<unsigned int>(f);
}
}  // namespace fnv_004a0330

struct NiGeometryData
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
};
struct NiGeometry
{
    NiGeometryData* FUN_005495f0();
    void FUN_004a1ff0();
};
// Calls FUN_005495f0 to get the geometry data and then invokes its v42 method.
// @fnv 0x004a1ff0
void NiGeometry::FUN_004a1ff0()
{
    FUN_005495f0()->v42();
}

namespace fnv_004a2c00 {
struct GO
{
    GO& operator=(void*);
};

struct FUN_004a2c00_shell
{
    char pad[0x34];
    GO m_go;
    void AssignGo(void* arg);
};

// @fnv 0x004a2c00
void FUN_004a2c00_shell::AssignGo(void* arg)
{
    m_go = arg;
}
}  // namespace fnv_004a2c00

struct FUN_004a3cc0_Class
{
    FUN_004a3cc0_Class* FUN_004a3cc0(void);
};

struct Holder
{
    void FUN_004a3c90(Holder*);
};

void* __fastcall FUN_004a3d00(void*);
void* __cdecl FUN_00458b20(void);

struct FUN_004a3c20
{
    FUN_004a3c20();
    ~FUN_004a3c20();
};

// Constructor: initializes subobjects at offsets 0x00, 0x30 and 0x90, then zeroes fields at 0xa0, 0xa4, 0xa8 and 0xac.
// @fnv 0x004a3c20
FUN_004a3c20::FUN_004a3c20()
{
    ((FUN_004a3cc0_Class*)((char*)this + 0x00))->FUN_004a3cc0();
    FUN_004a3d00((char*)this + 0x30);
    ((Holder*)((char*)this + 0x90))->FUN_004a3c90((Holder*)FUN_00458b20());
    *(int*)((char*)this + 0xa0) = 0;
    *(int*)((char*)this + 0xa4) = 0;
    *(int*)((char*)this + 0xa8) = 0;
    *(char*)((char*)this + 0xac) = 0;
}

struct StatefulObject
{
    void FUN_004a2d50();
    bool FUN_004f1540();
    ~StatefulObject();
};

struct DecalEmitterNode
{
    StatefulObject* emitter;
    DecalEmitterNode* next;
};

struct BGSDecalEmitterList
{
    DecalEmitterNode* head;
    DecalEmitterNode* tail;
    unsigned int count;
    DecalEmitterNode* FUN_00559450();
    StatefulObject** FUN_0057cbe0(DecalEmitterNode** cursor);
    void FUN_0049f590(DecalEmitterNode** cursor);
};

struct PendingDecalList
{
    void* head;
    void* tail;
    unsigned int count;
};

struct DecalCleanupOwner
{
    void* queryTexture;
    unsigned int clearQueryTexture;
    PendingDecalList pendingSimpleDecals;
    BGSDecalEmitterList decalEmitters;
    void CleanupDecalEmitters();
};

// Walks the decal emitter list, calls FUN_004a2d50 on each emitter, and deletes those for which FUN_004f1540 returns true.
// @fnv 0x004a03f0
void DecalCleanupOwner::CleanupDecalEmitters()
{
    DecalEmitterNode* cursor = decalEmitters.FUN_00559450();
    while (cursor != 0)
    {
        DecalEmitterNode* previous = cursor;
        StatefulObject* emitter = *decalEmitters.FUN_0057cbe0(&cursor);
        if (emitter != 0)
        {
            emitter->FUN_004a2d50();
            if (emitter->FUN_004f1540())
            {
                decalEmitters.FUN_0049f590(&previous);
                delete emitter;
                emitter = 0;
            }
        }
    }
}

class FUN_004a0f60_sub
{
  public:
    ~FUN_004a0f60_sub();
};

class FUN_004a0f60_base
{
  public:
    virtual void Update();
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
    virtual ~FUN_004a0f60_base();
};

class FUN_004a0f60_cls : public FUN_004a0f60_base
{
  public:
    FUN_004a0f60_sub m_c4;
    virtual ~FUN_004a0f60_cls();
};

// Destructor of the class; destroys the embedded m_c4 sub-object and the base.
// @fnv 0x004a0f60
FUN_004a0f60_cls::~FUN_004a0f60_cls()
{}

namespace CameraPass {
struct Vec
{
    float x, y, z;
    void FUN_006815c0();
    void FUN_004a0c10();
    void FUN_00439180(float);
    Vec FUN_00439e90(const Vec&);
    Vec FUN_004a0bd0();
    Vec ApplyScaled(float);
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void FUN_006815c0();
    void FUN_004a0c90(float);
    Matrix FUN_0043f8d0(const Matrix&);
    void FUN_00476930(int, Vec&);
    void FUN_004769c0(int, const Vec&);
};
void FUN_00c4b600(Matrix*, Vec);
struct Frustum
{
    float left, right, top, bottom, nearValue, farValue;
    bool ortho;
    Frustum(int);
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
};
struct Name
{
    const char* FUN_0043b1b0();
};
struct Ref
{
    float FUN_008d01e0();
    Name* FUN_00413f40();
};
struct Query
{
    unsigned int unk0;
    Query();
    void FUN_00c4ed70();
    void FUN_00c4edb0();
};
struct Input
{
    unsigned int unk0, unk4, unk8, unkc, unk10, unk14;
    char unk18, unk19, unk1a;
    bool alternate;
    Query* query;
    Vec FUN_004a0d60();
    Vec FUN_004a0d30();
    float FUN_004e3d00();
    float FUN_00507b20();
    float GetField11C();
    float GetFloatAt120();
    Ref* FUN_004a0330();
};
struct Scene
{
    void FUN_00440460(const Vec&);
    void FUN_0043fa80(const Matrix&);
    void FUN_00a6faf0(const Frustum&);
    void FUN_00a59c60(Update*);
    Vec FUN_0045bba0();
    void* FUN_004a0d10();
};
struct ScenePtr
{
    Scene* ptr;
    Scene* FUN_00559450();
};
struct Node
{
    void FUN_004a1020(void*);
    void FUN_004a1040(int);
};
struct NodePtr
{
    Node* ptr;
    Node* FUN_00559450();
};
struct Render
{
    void* FUN_00b6b260();
};
struct RenderPtr
{
    Render* ptr;
    Render* FUN_00559450();
    void FUN_0066b0d0(Render*);
};
struct Factory
{
    Render* FUN_00b6e110();
};
int __stdcall FUN_004a0e90(int);
Factory* __stdcall FUN_004a0ea0(int, int, int, int);
void FUN_00b6b8d0(int, void*);
struct Resource
{
    void FUN_004a0dd0();
};
Resource* __stdcall FUN_0043c4b0(void*);
void* FUN_00450b80(int);
struct Cull
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
    Cull(int);
    ~Cull();
    void FUN_004a0fd0(Node*);
};
void FUN_00b6bee0(Scene*, Ref*, Cull*);
void FUN_00b6c0d0(Scene*, Node*, int);
void FUN_00b6b790();
struct Setting
{
    bool* FUN_00408d60();
};
extern Setting DAT_011c5904;
extern unsigned int DAT_011c57f4;
extern float DAT_0101b268, DAT_0101e2bc, DAT_01018f5c;
extern double DAT_01011590, DAT_0101e2c0;
extern char DAT_0101e298, DAT_0101e274, DAT_0101e24c, DAT_0101e1f8;
void FUN_005b5e40(const char*, ...);
void* FUN_004b3890(const Vec&, const Color&, const Vec&, const Color&, int);
struct World
{
    void FUN_00458e20(void*, float);
};
extern World* DAT_011dea10;
struct Camera
{
    RenderPtr render;
    unsigned int unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    NodePtr node;
    ScenePtr scene;
    void UpdateCamera(Input*);
};
// @fnv 0x004a04c0
void Camera::UpdateCamera(Input* input)
{
    Vec directionSlot1Slot0 = input->FUN_004a0d60();
    directionSlot1Slot0.FUN_004a0c10();
    directionSlot1Slot0.FUN_00439180(DAT_0101b268);
    Vec originSlot13 = input->FUN_004a0d30().FUN_00439e90(directionSlot1Slot0);
    Matrix rotationSlot17Slot12;
    FUN_00c4b600(&rotationSlot17Slot12, directionSlot1Slot0.FUN_004a0bd0());
    Matrix scaleSlot22Slot0Slot10;
    scaleSlot22Slot0Slot10.FUN_006815c0();
    scaleSlot22Slot0Slot10.FUN_004a0c90(input->FUN_004e3d00());
    rotationSlot17Slot12 = scaleSlot22Slot0Slot10.FUN_0043f8d0(rotationSlot17Slot12);
    Vec column0Slot30Slot0;
    column0Slot30Slot0.FUN_006815c0();
    Vec column1Slot41Slot18;
    column1Slot41Slot18.FUN_006815c0();
    rotationSlot17Slot12.FUN_00476930(0, column0Slot30Slot0);
    rotationSlot17Slot12.FUN_00476930(1, column1Slot41Slot18);
    rotationSlot17Slot12.FUN_00476930(2, directionSlot1Slot0);
    Matrix basisSlot28Slot36;
    basisSlot28Slot36.FUN_006815c0();
    basisSlot28Slot36.FUN_004769c0(0, directionSlot1Slot0);
    basisSlot28Slot36.FUN_004769c0(1, column0Slot30Slot0);
    basisSlot28Slot36.FUN_004769c0(2, column1Slot41Slot18);
    Vec startSlot14Slot30;
    startSlot14Slot30.FUN_006815c0();
    Vec endSlot11;
    endSlot11.FUN_006815c0();
    float widthSlot15Slot25 = (input->FUN_00507b20() / DAT_01011590) * (1.0f / input->FUN_004a0330()->FUN_008d01e0());
    float heightSlot21 = (input->GetField11C() / DAT_01011590) * (1.0f / input->FUN_004a0330()->FUN_008d01e0());
    float farPlaneSlot12Slot43 = input->GetFloatAt120() + DAT_0101e2c0;
    Frustum frustumSlot18Slot39(0);
    frustumSlot18Slot39.ortho = true;
    frustumSlot18Slot39.nearValue = DAT_0101e2bc;
    frustumSlot18Slot39.left = -widthSlot15Slot25;
    frustumSlot18Slot39.right = widthSlot15Slot25;
    frustumSlot18Slot39.top = heightSlot21;
    frustumSlot18Slot39.bottom = -heightSlot21;
    frustumSlot18Slot39.farValue = farPlaneSlot12Slot43;
    scene.FUN_00559450()->FUN_00440460(originSlot13);
    scene.FUN_00559450()->FUN_0043fa80(basisSlot28Slot36);
    scene.FUN_00559450()->FUN_00a6faf0(frustumSlot18Slot39);
    Update updateSlot12(0.0f, 0, 0);
    scene.FUN_00559450()->FUN_00a59c60(&updateSlot12);
    void* lineSlot0Slot21;
    if (DAT_011c57f4 & 4)
    {
        startSlot14Slot30 = originSlot13;
        endSlot11 = originSlot13.FUN_00439e90(scene.FUN_00559450()->FUN_0045bba0().ApplyScaled(farPlaneSlot12Slot43));
        lineSlot0Slot21 =
            FUN_004b3890(startSlot14Slot30, Color(0.0f, 0.0f, 1.0f, 1.0f), endSlot11, Color(1.0f, 0.0f, 0.0f, 1.0f), 1);
        DAT_011dea10->FUN_00458e20(lineSlot0Slot21, DAT_01018f5c);
    }
    if (*DAT_011c5904.FUN_00408d60())
    {
        Vec look = scene.FUN_00559450()->FUN_0045bba0();
        FUN_005b5e40(&DAT_0101e298, input->FUN_004a0330()->FUN_00413f40()->FUN_0043b1b0());
        FUN_005b5e40(&DAT_0101e274, originSlot13.x, originSlot13.y, originSlot13.z);
        FUN_005b5e40(&DAT_0101e24c, look.x, look.y, look.z);
        FUN_005b5e40(&DAT_0101e1f8, farPlaneSlot12Slot43, -widthSlot15Slot25, widthSlot15Slot25, heightSlot21,
                     -heightSlot21);
    }
    if (!render.FUN_00559450())
        render.FUN_0066b0d0(FUN_004a0ea0(FUN_004a0e90(0x33), 0, 0, 0)->FUN_00b6e110());
    if (input->alternate)
        FUN_00b6b8d0(7, render.FUN_00559450()->FUN_00b6b260());
    else
        FUN_00b6b8d0(0, render.FUN_00559450()->FUN_00b6b260());
    input->query = new Query;
    input->query->FUN_00c4ed70();
    FUN_0043c4b0(scene.FUN_00559450()->FUN_004a0d10())->FUN_004a0dd0();
    Cull cullSlot18Slot33(0);
    cullSlot18Slot33.FUN_004a0fd0(node.FUN_00559450());
    node.FUN_00559450()->FUN_004a1020(FUN_00450b80(0));
    node.FUN_00559450()->FUN_004a1040(15);
    FUN_00b6bee0(scene.FUN_00559450(), input->FUN_004a0330(), &cullSlot18Slot33);
    FUN_00b6c0d0(scene.FUN_00559450(), node.FUN_00559450(), 0);
    cullSlot18Slot33.FUN_004a0fd0(0);
    input->query->FUN_00c4edb0();
    FUN_00b6b790();
}
}

struct TESForm
{
    unsigned int GetFormType();
};
class Refr_C
{
  public:
    TESForm* GetAcousticSpace();
};

// Returns false when the reference's acoustic space form type is 35, 42, 43 or 51; otherwise returns true.
// @fnv 0x004a1060
bool __cdecl IsAcousticSpaceFormTypeAllowed(Refr_C* apRef, int aiArg)
{
    int iUnused = aiArg;
    switch (apRef->GetAcousticSpace()->GetFormType())
    {
    case 35:
    case 42:
    case 43:
    case 51:
        return false;
    }
    return true;
}

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* apFrequency);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* apCounter);

namespace DecalAdd {

struct DecalPoint
{
    float x, y, z;
    void FUN_006815c0();
    DecalPoint FUN_00439ef0(const DecalPoint& arOther) const;
    DecalPoint FUN_00439e90(const DecalPoint& arOther) const;
    float FUN_00457990() const;
    void FUN_004a0c10();
    DecalPoint ApplyScaled(float afScale) const;
};

union DecalTicks
{
    struct
    {
        unsigned int LowPart;
        int HighPart;
    };
    __int64 QuadPart;
};

struct DecalRotation
{
    DecalPoint FUN_004a0bd0() const;
};

struct DecalBound
{
    float fData[4];
    DecalPoint* FUN_006815c0();
    float FUN_0084d030();
};

struct DecalNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual DecalNode* GetNode();
    bool FUN_004a19d0();
    DecalBound* FUN_0043d450();
    void* FUN_004543c0();
};

struct DecalHolder
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
    virtual void v68();
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
    virtual DecalNode* Get3D();
};

struct DecalPlayer
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
    virtual void v68();
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
    virtual DecalPoint* GetPos();
};

struct DecalRequest
{
    DecalPoint kPos;
    DecalPoint kWorldPosition;
    char pad18[0xc];
    DecalHolder* pHolder;
    DecalNode* pTarget;
    char pad2c[0xc];
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    char pad40[8];
    DecalNode* pParent;
    char pad4c[0x25];
    unsigned char bRefresh;
    char pad72[5];
    unsigned char bForce;
};

struct DecalHitList
{
    int iData[3];
    DecalHitList();
    ~DecalHitList();
    int FUN_0049c680(DecalNode** appNode, int aiFlags);
    void FUN_0076b660(DecalNode** appNode);
    void FUN_004ed900();
};

struct DecalEmitter
{
    void FUN_004a1a10(int aiFlag, int aiValue);
    void FUN_006231a0(void* apNode);
    int FUN_00622f80(DecalRequest* apRequest, const DecalPoint& arPos, float afRange);
    DecalNode* GetCollisionFlags(int aiIndex);
    void SetTileSetValues(int aiIndex, DecalPoint* apPos, DecalPoint* apNormal);
};

struct DecalMemContext
{
    int iOldContext;
    DecalMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~DecalMemContext();
};

struct DecalBoolSetting
{
    unsigned char* FUN_00408d60();
};
struct DecalIntSetting
{
    unsigned int* FUN_0043d4d0();
};

extern DecalPlayer* DAT_011dea3c;
extern DecalBoolSetting DAT_011c5834;
extern DecalBoolSetting DAT_011c5884;
extern DecalBoolSetting DAT_011c58bc;
extern DecalBoolSetting DAT_011c5904;
extern DecalIntSetting DAT_011c58e4;
extern unsigned int DAT_011c57f0;
extern DecalEmitter* DAT_011c57e0;
extern DecalRotation DAT_011a9484;

float __cdecl FUN_004a19f0();
float __cdecl FUN_004a1a00();
int __cdecl FUN_005b5e40(const char* apFormat, ...);
int __cdecl FUN_00406d00(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);
void __cdecl FUN_0040fbe0(const char* apText, int aiFlags);
float __cdecl FUN_00404010(float a, float b);
DecalEmitter* __cdecl FUN_00622a70(float afSize, int aiFlags);
void* __cdecl FUN_0056f930(DecalNode* apNode);
bool __cdecl IsAcousticSpaceFormTypeAllowed(void* apGeometry, int aiFlags);

static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSDecalManager.cpp";
static const char s_szSimpleDecal[] = "DECAL: Simple Decal Instantiated";
static const char s_szTiming[] = "AddGeometryDecalRecurse: Ticks: %I64d, Microseconds: %f";
static const char s_szSkinLimit[] = "DECAL: Reached Max Skin Decal Limit! : %d";

struct DecalManager
{
    int iPad00;
    bool m_bDecalsEnabled;

    void FUN_004a1a70(DecalRequest* apRequest);
    void FUN_004a2070(DecalRequest* apRequest);
    void AddGeometryDecal(DecalRequest* apRequest, int aiType, bool abForce);
};

// Handles decal requests by type, checking distance and force flags in some cases and processing collision hits in another.
// @fnv 0x004a10d0
void DecalManager::AddGeometryDecal(DecalRequest* apRequest, int aiType, bool abForce)
{
    __int64 llEnd;
    DecalPoint kCameraIn;
    float fDistance;
    __int64 llFrequencyCount;
    int iUnused;
    DecalTicks kStartNext;
    double dFrequency;
    DecalMemContext kMemContextRef(7, true, s_szSourceFile, 0x1b8);
    m_bDecalsEnabled = true;
    switch (aiType)
    {
    case 1:
        if (*DAT_011c5834.FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->FUN_004a19d0())
        {
            kCameraIn = *DAT_011dea3c->GetPos();
            fDistance = apRequest->kPos.FUN_00439ef0(kCameraIn).FUN_00457990();
            dFrequency = 1000.0;
            iUnused = 0;
            kStartNext.LowPart = 0;
            char acBuffer[256];
            __int64 llTicks;
            if (*DAT_011c5884.FUN_00408d60())
            {
                QueryPerformanceFrequency(&llFrequencyCount);
                dFrequency = llFrequencyCount * 1e-06;
                QueryPerformanceCounter(&kStartNext.QuadPart);
            }
            if (FUN_004a19f0() >= fDistance || apRequest->bForce || abForce)
            {
                if (*DAT_011c5904.FUN_00408d60())
                    FUN_005b5e40(s_szSimpleDecal);
                FUN_004a1a70(apRequest);
            }
            if (*DAT_011c5884.FUN_00408d60())
            {
                QueryPerformanceCounter(&llEnd);
                llTicks = llEnd - kStartNext.QuadPart;
                FUN_00406d00(acBuffer, 0xff, s_szTiming, llTicks, llTicks / dFrequency);
                FUN_0040fbe0(acBuffer, 0);
            }
        }
        break;
    case 4:
        if (*DAT_011c5834.FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->FUN_004a19d0())
        {
            apRequest->bRefresh = 1;
            FUN_004a1a70(apRequest);
        }
        break;
    case 2:
        if (*DAT_011c58bc.FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->FUN_004a19d0())
        {
            DecalPoint kEyeOut = *DAT_011dea3c->GetPos();
            DecalBound kBound = *apRequest->pTarget->FUN_0043d450();
            float fBoundDistance = kBound.FUN_006815c0()->FUN_00439ef0(kEyeOut).FUN_00457990() - kBound.FUN_0084d030();
            if ((FUN_004a1a00() >= fBoundDistance && DAT_011c57f0 < *DAT_011c58e4.FUN_0043d4d0()) || abForce)
                FUN_004a2070(apRequest);
            else if (DAT_011c57f0 >= *DAT_011c58e4.FUN_0043d4d0() && *DAT_011c5904.FUN_00408d60())
                FUN_005b5e40(s_szSkinLimit, *DAT_011c58e4.FUN_0043d4d0());
        }
        else if (*DAT_011c58bc.FUN_00408d60() && apRequest->pHolder)
        {
            DecalPoint kViewerNew = *DAT_011dea3c->GetPos();
            DecalBound kHolderBoundCur = *apRequest->pHolder->Get3D()->FUN_0043d450();
            float fHolderDistance = kHolderBoundCur.FUN_006815c0()->FUN_00439ef0(kViewerNew).FUN_00457990() -
                                    kHolderBoundCur.FUN_0084d030();
            DecalNode* pObject = apRequest->pHolder->Get3D();
            DecalNode* pNode = pObject ? pObject->GetNode() : 0;
            if (pNode && !pObject->FUN_004a19d0())
            {
                apRequest->pTarget = pNode;
                if ((FUN_004a1a00() >= fHolderDistance && DAT_011c57f0 < *DAT_011c58e4.FUN_0043d4d0()) || abForce)
                    FUN_004a2070(apRequest);
                else if (DAT_011c57f0 >= *DAT_011c58e4.FUN_0043d4d0() && *DAT_011c5904.FUN_00408d60())
                    FUN_005b5e40(s_szSkinLimit, *DAT_011c58e4.FUN_0043d4d0());
            }
        }
        else if (*DAT_011c5834.FUN_00408d60())
        {
            apRequest->kWorldPosition.FUN_004a0c10();
            if (!DAT_011c57e0)
                DAT_011c57e0 = FUN_00622a70(FUN_00404010(apRequest->m_fGlyphExtent, apRequest->m_fGlyphWidthInPixels), 1);
            DAT_011c57e0->FUN_004a1a10(8, 0);
            DAT_011c57e0->FUN_004a1a10(0x1d, 0);
            DAT_011c57e0->FUN_006231a0(apRequest->pParent->FUN_004543c0());
            int iCount = DAT_011c57e0->FUN_00622f80(
                apRequest, apRequest->kPos.FUN_00439e90(apRequest->kWorldPosition.ApplyScaled(80.0f)), 32.0f);
            if (iCount == 0)
            {
                DecalPoint kNewDir =
                    apRequest->kWorldPosition.FUN_00439e90(DAT_011a9484.FUN_004a0bd0().ApplyScaled(2.0f));
                kNewDir.FUN_004a0c10();
                apRequest->kWorldPosition = kNewDir;
                iCount = DAT_011c57e0->FUN_00622f80(apRequest, apRequest->kPos.FUN_00439e90(kNewDir.ApplyScaled(80.0f)),
                                                    32.0f);
            }
            DecalHitList kHits;
            for (int i = 0; i < iCount; i++)
            {
                DecalPoint kHitPos;
                DecalPoint kHitNormal;
                kHitPos.FUN_006815c0();
                kHitNormal.FUN_006815c0();
                DecalNode* pHitTmp = DAT_011c57e0->GetCollisionFlags(i);
                if (pHitTmp)
                {
                    DAT_011c57e0->SetTileSetValues(i, &kHitPos, &kHitNormal);
                    kHitNormal.FUN_004a0c10();
                    void* m_pShaderGeometry = FUN_0056f930(pHitTmp);
                    if (pHitTmp->FUN_004a19d0() || !m_pShaderGeometry ||
                        !IsAcousticSpaceFormTypeAllowed(m_pShaderGeometry, 1))
                        continue;
                    if (!kHits.FUN_0049c680(&pHitTmp, 0))
                    {
                        apRequest->kPos = kHitPos;
                        apRequest->kWorldPosition = kHitNormal;
                        apRequest->pTarget = pHitTmp;
                        FUN_004a1a70(apRequest);
                        kHits.FUN_0076b660(&pHitTmp);
                    }
                }
            }
            kHits.FUN_004ed900();
        }
        break;
    }
}

}

// 0x004a1a70   /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), bool return.
extern "C" int DAT_011c57e4;
extern "C" char DAT_011c5874;
extern "C" char DAT_011c5890;
extern "C" char DAT_011c58a8;
extern "C" char DAT_011c5904x;
extern "C" char DAT_011f4a20;
extern "C" char DAT_011c7d34[];
extern "C" double DAT_01012060;
extern "C" char DAT_0101e420[];
extern "C" char DAT_0101e450[];
extern "C" char DAT_0101e460[];
extern "C" char DAT_0101e468[];
extern "C" char DAT_0101e474[];
extern "C" char DAT_0101e47c[];
extern "C" char DAT_0101e484[];
extern "C" char DAT_0101e490[];

int FUN_005b5e40(const char* fmt, ...);
int FUN_00ec8a19(const char* text, const char* prefix, int len);

struct XObj
{
    NiPoint3& FUN_004a0d30(NiPoint3& out);
    float FUN_00507b20();
};
struct XItem
{
    XObj* FUN_00559450();
};
struct XList
{
    bool IsEmpty();
    void* FUN_0043b1b0();
    XItem* FUN_006815c0();
    XList* FUN_00726070();
};
struct XObj3D
{
    bool GetFlag(unsigned int flag);
};
struct XNet
{
    XObj3D* GetObject3D();
};
struct XNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    bool FUN_00456610();
    XNet* FUN_0050d100();
    unsigned int FUN_0043b480();
    XNode* GetAt(unsigned int idx);
    unsigned short FUN_004a1ff0();
    XList* GetTESPackageList();
    char pad4[0xac - 4];
    XList* m_ac;
};
struct XTopicInfo
{
    unsigned int FUN_0043b480();
    XNode* GetAt(unsigned int idx);
};
struct XMenuTopic
{
    XTopicInfo* GetTopicInfo();
};
struct XSetting
{
    int* Int();
    unsigned char* Bool();
};
struct XGA
{
    float FUN_00450410();
};

struct XRef
{
    char pad00[0x28];
    XNode* m28;
    char pad2c[0x0c];
    float m38;
    float m3c;
    char pad40[8];
    void* m48;
    char pad4c[0x10];
    float m5c;
    char pad60[0x12];
    unsigned char m72;
    char pad73[0x39];
    XList* m_ac;
    NiPoint3 PtOp(const NiPoint3& p) const;
};

struct XDoor;
struct XLoc
{
    XLoc(XDoor* d);
    ~XLoc();
    char pad[4];
};
struct XDoor
{
    XDoor(XObj* p, float f, XRef* r);
    static void* operator new(unsigned int sz);
    static void operator delete(void*, unsigned int);
    char pad0[0x1a];
    unsigned char m1a;
    unsigned char m1b;
    char pad2[0x144 - 0x1c];
};
struct XNL
{
    void FUN_0057c590(const XLoc& o);
};
struct XMgr
{
    char pad0[4];
    unsigned char m4;
    char pad5[3];
    XNL m8;
    bool FUN_004a1a70(XRef* ref);
};

bool FUN_0043b300(const void* rtti, XNode* obj);
bool FUN_0045bad0(const void* name, XNode* obj);
struct NiPoint3Sq : NiPoint3
{
};
NiPoint3Sq MultiplyComponents(const NiPoint3& a, const NiPoint3& b);

// Checks conditions on ref and related nodes, may construct an XDoor, and calls FUN_0057c590 when ref->m48 is non-null.
// @fnv 0x004a1a70
bool XMgr::FUN_004a1a70(XRef* ref)
{
    const char* pName4;
    XNode* p9;
    XObj3D* objVal;
    XTopicInfo* info2;
    unsigned int i5;
    XNode* av_;
    XList* list;
    XObj* a5;
    XObj* b_;
    XNode* p4;
    XDoor* door3;
    XNode* hit2;
    bool foundVal;

    if (DAT_011c57e4 >= *((XSetting*)&DAT_011c5890)->Int())
    {
        if (((XSetting*)&DAT_011c5904x)->Bool()[0])
            FUN_005b5e40(DAT_0101e490);
        return false;
    }
    if (ref->m28)
    {
        pName4 = (const char*)ref->m28->GetTESPackageList()->FUN_0043b1b0();
        if (pName4 != 0 && (FUN_00ec8a19(pName4, DAT_0101e484, 10) == 0 || FUN_00ec8a19(pName4, DAT_0101e47c, 5) == 0 ||
                            FUN_00ec8a19(pName4, DAT_0101e474, 7) == 0 || FUN_00ec8a19(pName4, DAT_0101e468, 9) == 0 ||
                            FUN_00ec8a19(pName4, DAT_0101e460, 5) == 0 || FUN_00ec8a19(pName4, DAT_0101e450, 15) == 0))
            return true;
        if (FUN_0043b300(&DAT_011f4a20, ref->m28) && !ref->m28->FUN_00456610())
        {
            p9 = ref->m28;
            if (p9 != 0)
            {
                objVal = p9->FUN_0050d100()->GetObject3D();
                if (objVal != 0 && objVal->GetFlag(0x1a))
                    return true;
            }
            info2 = ((XMenuTopic*)ref->m28)->GetTopicInfo();
            hit2 = 0;
            foundVal = false;
            if (info2 != 0)
            {
                for (i5 = 0; i5 < info2->FUN_0043b480(); i5++)
                {
                    av_ = info2->GetAt(i5);
                    if (av_ != 0)
                    {
                        if (FUN_0045bad0(&DAT_011c7d34, av_))
                        {
                            foundVal = true;
                            hit2 = av_;
                            break;
                        }
                    }
                }
            }
            else
            {
                return false;
            }
            if (foundVal && ref->m5c > DAT_01012060)
            {
                list = hit2->m_ac;
                while (list != 0 && !list->IsEmpty())
                {
                    a5 = list->FUN_006815c0()->FUN_00559450();
                    b_ = a5;
                    list = list->FUN_00726070();
                    NiPoint3 pt9;
                    b_->FUN_004a0d30(pt9);
                    float f9 = b_->FUN_00507b20();
                    NiPoint3 v7 = ref->PtOp(pt9);
                    v7 = MultiplyComponents(v7, v7);
                    float qA;
                    if (ref->m38 > ref->m3c)
                        qA = ref->m38;
                    else
                        qA = ref->m3c;
                    double d = qA + f9;
                    d = d * d;
                    if (v7.x + v7.y + v7.z <= d / ref->m5c)
                        return false;
                }
            }
            DAT_011c57e4++;
            if (((XSetting*)&DAT_011c5904x)->Bool()[0])
                FUN_005b5e40(DAT_0101e420, DAT_011c57e4);
            door3 = new XDoor((XObj*)hit2, ((XGA*)&DAT_011c5874)->FUN_00450410(), ref);
            p4 = ref->m28;
            if (p4->FUN_004a1ff0() > 0x3e8 && ((XSetting*)&DAT_011c58a8)->Bool()[0] && ref->m72)
            {
                door3->m1a = 1;
                door3->m1b = m4;
                m4 = 0;
            }
            if (ref->m48)
                m8.FUN_0057c590(door3);
        }
        else if (ref->m28->v3())
        {
            XNode* n2 = ref->m28;
            unsigned int _i2;
            XNode* child8;
            if (n2 != 0 && n2->FUN_00456610())
                return true;
            _i2 = 0;
            while (_i2 < n2->FUN_0043b480())
            {
                child8 = n2->GetAt(_i2);
                if (child8 != 0)
                {
                    ref->m28 = child8;
                    FUN_004a1a70(ref);
                }
                _i2++;
            }
        }
    }
    return true;
}

#include <string.h>
namespace fnv_004a2070 {
struct DObj;
struct DArg;
struct DPtr;
struct DProp;
struct DArray;
struct CStringProvider;
struct DVec
{
    float x, y, z;
    DVec FUN_004a0bd0() const;
};
struct DUpdate
{
    float time;
    bool updateControllers, multithreaded;
    unsigned unk08;
    DUpdate(float, bool, bool);
};
struct DObj
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual DObj* IsSceneNode();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual DObj* IsGeometry();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Virtual8c();
    virtual void Unk24();
    virtual void Unk25();
    virtual DObj* Virtual98(bool);
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Virtualdc(DObj*, bool);
    CStringProvider* FUN_00413f40();
    bool FUN_00456610();
    DProp* FUN_00a59d30(unsigned);
    void* FUN_004030b0();
    void* FUN_0043fad0();
    DArray* FUN_009611e0();
    unsigned FUN_00453470();
    int FUN_0059e300();
    void AssignGo(DObj*);
    void AssignFixedString(CStringProvider*);
    void FUN_00a59c60(DUpdate&);
};
struct CStringProvider
{
    const char* FUN_0043b1b0();
};
struct DPtr
{
    DObj* ptr;
    DPtr(DObj*);
    ~DPtr();
    DObj* FUN_00559450();
    DPtr& FUN_0066b0d0(DObj*);
};
struct DArray
{
    unsigned FUN_0043b480();
    DObj* FUN_0043b4a0(unsigned);
};
struct DProp
{
};
struct DList
{
    void FUN_00631540(const DPtr&);
};
struct DNode : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
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
    DList* effects;
    unsigned unkb0;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DNode(DArray*, bool);
};
struct DOneArg
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Virtualdc(DObj*);
    void AssignFixedString(CStringProvider*);
};
struct DSkin : DOneArg
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
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
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DSkin(unsigned);
};
struct DEffect : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
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
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DEffect(unsigned, float, DArg*, DObj*, DVec, DVec, float, float, unsigned);
};
struct DParentInterface
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Get(unsigned, DPtr&);
};
struct DParent
{
    unsigned unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    DParentInterface interface30;
};
struct DArg
{
    DVec origin, normal;
    unsigned unk18, unk1c, unk20, unk24;
    DObj* object;
    DArray* children;
    DParent* parent;
    int tries;
    float scale;
    unsigned unk3c, unk40;
    float rotation;
    unsigned flags, unk4c;
    DOneArg* skin;
    unsigned unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
struct DSetting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
    bool* FUN_00408d60();
    float FUN_00450410();
};
extern DSetting DAT_011c5874, DAT_011c5858, DAT_011c589c;
extern int DAT_011c57e8, DAT_011c57f0;
extern unsigned DAT_011f444c, DAT_011c7d34;
struct DManager
{
    void FUN_00973fd0(DObj*);
};
extern DManager DAT_011e0e80;
bool FUN_0043b300(const void*, DObj*);
bool FUN_0045bad0(const void*, DObj*);
void FUN_005b5e40(const char*, ...);
CStringProvider* FUN_004a2c60();
int FUN_004a2c20(DProp*);
struct DWork
{
    bool FUN_004a2070(DArg*);
};
// Checks limits and object conditions, may create decal effects, and returns a status.
// @fnv 0x004a2070
bool DWork::FUN_004a2070(DArg* arg)
{
    if (*DAT_011c5874.FUN_00403e20() <= 0.0)
        return false;
    if (DAT_011c57e8 >= *DAT_011c5858.FUN_0043d4d0())
    {
        if (*DAT_011c5904.GetLifeStateControlFlag())
            FUN_005b5e40("DECAL: Reached max skinned decals per frame. Ignoring decal.");
        return true;
    }
    DPtr original(0);
    if (arg->parent)
    {
        DPtr p(0);
        arg->parent->interface30.Get(0, p);
        DObj* parent = p.FUN_00559450();
        if (FUN_0043b300(&DAT_011f444c, parent))
            original.FUN_0066b0d0(parent);
    }
    if (!original.FUN_00559450())
        return false;
    if (arg->object)
    {
        const char* name = arg->object->FUN_00413f40()->FUN_0043b1b0();
        if (name)
        {
            if (!strncmp(name, "Decal", 5) || !strncmp(name, "FaceGen", 7) || !strncmp(name, "Bip01", 5) ||
                !strncmp(name, "BSFaceGen", 9) || !strncmp(name, "Hair", 4))
                return true;
        }
        if (arg->object->FUN_00456610())
            return true;
        if (arg->object->IsGeometry())
        {
            DObj* geometry = arg->object;
            if (arg->tries <= 0)
            {
                DProp* data = geometry->FUN_00a59d30(3);
                void* prop = geometry->FUN_004030b0();
                if (data && prop)
                {
                    DPtr effect(0);
                    if (geometry->FUN_0043fad0())
                    {
                        DArray* array = arg->object->FUN_009611e0();
                        DNode* selected = 0;
                        for (unsigned i = 0; i < array->FUN_0043b480(); ++i)
                        {
                            DObj* child = array->FUN_0043b4a0(i);
                            if (child && FUN_0045bad0(&DAT_011c7d34, child))
                            {
                                selected = (DNode*)child;
                                break;
                            }
                        }
                        if (!selected)
                            selected = new DNode(array, true);
                        else
                        {
                            if (selected->FUN_00453470() >= (unsigned)*DAT_011c589c.FUN_0043d4d0())
                                return true;
                        }
                        ++DAT_011c57e8;
                        if (*DAT_011c5904.GetLifeStateControlFlag())
                            FUN_005b5e40("DECAL: Skinned decal count this frame: #%d", DAT_011c57e8);
                        DPtr decal(new DEffect(arg->flags, DAT_011c5874.FUN_00450410(), arg, geometry, arg->origin,
                                               arg->normal, arg->scale, arg->rotation, arg->unk6c));
                        bool accepted = false;
                        decal.FUN_00559450()->Virtual8c();
                        if (decal.FUN_00559450()->FUN_0059e300() > 0)
                        {
                            if (!arg->skin)
                            {
                                arg->skin = new DSkin(0);
                                arg->skin->AssignFixedString(FUN_004a2c60());
                                selected->Virtualdc((DObj*)arg->skin, true);
                                ++DAT_011c57f0;
                                if (*DAT_011c5904.GetLifeStateControlFlag())
                                    FUN_005b5e40("DECAL: Placing Skin Decal #%d", DAT_011c57f0);
                            }
                            arg->skin->Virtualdc(decal.FUN_00559450()->Virtual98(true));
                            decal.FUN_00559450()->AssignGo((DObj*)arg->skin);
                            selected->effects->FUN_00631540(decal.FUN_00559450());
                            DUpdate update(0.0f, false, false);
                            selected->FUN_00a59c60(update);
                            DAT_011e0e80.FUN_00973fd0(decal.FUN_00559450());
                            effect.FUN_0066b0d0(decal.FUN_00559450());
                        }
                        else
                            return true;
                    }
                    if (arg->children)
                    {
                        DObj* a = 0;
                        unsigned found = 0;
                        while (found < arg->children->FUN_0043b480() && !a)
                        {
                            DObj* child = arg->children->FUN_0043b4a0(found);
                            if (child)
                            {
                                if (child->IsGeometry())
                                    a = child;
                                else if (child->IsSceneNode())
                                {
                                    DArray* uiIndex = (DArray*)child;
                                    unsigned pArray = 0;
                                    while (pArray < uiIndex->FUN_0043b480() && !a)
                                    {
                                        DObj* candidate = uiIndex->FUN_0043b4a0(pArray);
                                        if (candidate && candidate->IsGeometry())
                                            a = candidate;
                                        ++pArray;
                                    }
                                }
                            }
                            ++found;
                        }
                        if (a)
                        {
                            DProp* data2 = a->FUN_00a59d30(3);
                            void* prop2 = a->FUN_004030b0();
                            if (data2 && prop2)
                            {
                                DProp* shader = FUN_004a2c20(data2) ? data2 : 0;
                                if (shader)
                                {
                                    DPtr additional(0);
                                    if (geometry->FUN_0043fad0())
                                    {
                                        DEffect* pRawEffect =
                                            new DEffect(arg->flags, DAT_011c5874.FUN_00450410(), arg, a, arg->origin,
                                                        arg->normal.FUN_004a0bd0(), 1.0f, arg->rotation, arg->unk6c);
                                        additional.FUN_0066b0d0(pRawEffect);
                                        pRawEffect->Virtual8c();
                                    }
                                    if (additional.FUN_00559450())
                                        DAT_011e0e80.FUN_00973fd0(additional.FUN_00559450());
                                }
                            }
                        }
                    }
                }
                if (arg->tries >= 0)
                    return false;
                else
                    return true;
            }
            else
            {
                --arg->tries;
                return true;
            }
        }
        else if (arg->object->IsSceneNode())
        {
            DArray* pArray = (DArray*)arg->object;
            unsigned uiIndex = 0;
            while (uiIndex < pArray->FUN_0043b480())
            {
                DObj* child = pArray->FUN_0043b4a0(uiIndex);
                if (child)
                {
                    arg->object = child;
                    bool result = FUN_004a2070(arg);
                    if (!result && arg->object)
                    {
                        if (arg->skin)
                        {
                            DArray* array = arg->object->FUN_009611e0();
                            DNode* selected = 0;
                            for (unsigned d = 0; d < array->FUN_0043b480(); ++d)
                            {
                                DObj* entry = array->FUN_0043b4a0(d);
                                if (entry && FUN_0045bad0(&DAT_011c7d34, entry))
                                {
                                    selected = (DNode*)entry;
                                    break;
                                }
                            }
                            if (selected)
                                selected->Virtualdc((DObj*)arg->skin, true);
                        }
                        return false;
                    }
                }
                ++uiIndex;
            }
        }
    }
    return true;
}
}  // namespace fnv_004a2070
