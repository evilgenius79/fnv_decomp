// fallout_shared/packagelocation.cpp: LocationDescriptor, TESPackage, BGSMessageInitAccess, OwnQ (31 functions)

#include "packagelocation_decls.h"
#include "packagelocation_runtime.h"

// @fnv 0x0067f390
TESObjectREFR* LocationDescriptor::GetLocationReference()
{
    if (m_ucLocationType == 0)
        return pRef;
    else
        return 0;
}

// @fnv 0x0067f3e0
TESObjectCELL* LocationDescriptor::GetLocationCellReference()
{
    if (m_ucLocationType == 1)
        return pCell;
    else
        return 0;
}

// @fnv 0x0067f3c0
void LocationDescriptor::FUN_0067f3c0(TESObjectREFR* reference)
{
    m_ucLocationType = PLT_REFERENCE;
    pRef = reference;
}

// Resolves the stored form ID to a cell, object or reference by location type and stores it, warning if the form is missing.
// @fnv 0x0067f760
void LocationDescriptor::InitItem(TESForm* owner)
{
    if (GetLocType() == PLT_TYPE)
        return;

    unsigned int formID = reinterpret_cast<unsigned int>(m_pLocationObject);
    TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
    switch (m_ucLocationType)
    {
    case PLT_CELL: {
        TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(TESForm::GetFormByID(formID));
        if (cell)
            FUN_0067f410(cell);
        else
        {
            if (static_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                Warning("MASTERFILE: Unable to find Package Location Cell (%08X) on owner object \"%s\".", formID,
                        owner->GetName());
            else
                Warning("MASTERFILE: Unable to find Package Location Cell (%08X) on owner object (%08X).", formID,
                        owner->GetFormID());
            FUN_0067f410(0);
        }
    }
    break;
    case PLT_OBJECT: {
        TESForm* object = TESForm::GetFormByID(formID);
        if (object)
            SetValue(object);
        else
        {
            if (static_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                Warning("MASTERFILE: Unable to find Package Location Object (%08X) on owner object \"%s\".", formID,
                        owner->GetName());
            else
                Warning("MASTERFILE: Unable to find Package Location Object (%08X) on owner object (%08X).", formID,
                        owner->GetFormID());
            SetValue(0);
        }
    }
    break;
    case PLT_REFERENCE: {
        TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(formID));
        if (reference)
            FUN_0067f3c0(reference);
        else
        {
            if (static_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                Warning("MASTERFILE: Unable to find Package Location Reference (%08X) on owner object \"%s\".", formID,
                        owner->GetName());
            else
                Warning("MASTERFILE: Unable to find Package Location Reference (%08X) on owner object (%08X).", formID,
                        owner->GetFormID());
            FUN_0067f3c0(0);
        }
    }
    break;
    }
}

// Returns a TESObjectREFR based on the location type: the object itself, its linked ref, a stored reference, or a process reference.
// @fnv 0x0067f2a0
TESObjectREFR* LocationDescriptor::ResolveLocationReference(MobileObject* object)
{
    TESObjectREFR* reference = 0;
    TESObjectREFR* processReference;
    if (GetLocType() != PLT_CURRLOC)
    {
        switch (GetLocType())
        {
        case PLT_CELL:
        case PLT_CURRLOC:
            break;
        case PLT_REFERENCE:
            if (GetLocationReference())
                reference = GetLocationReference();
            break;
        case PLT_LINKEDREF:
            if (object && object->GetLinkedRef())
                reference = object->GetLinkedRef();
            break;
        case PLT_EDITORLOC:
            if (object)
                reference = object;
            break;
        case PLT_OBJECT:
        case PLT_TYPE: {
            processReference = reinterpret_cast<TESObjectREFR*>(
                reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(object)->GetLogDate())->GetUnk044());
            if (processReference)
                reference = processReference;
            else
                reference = object;
        }
        break;
        }
    }
    else if (object)
        reference = object;
    return reference;
}

// @fnv 0x00826b40
void TESPackage::SetMustReachLocation(bool enabled)
{
    enabled ? kData.uiPackageFlags |= 2 : kData.uiPackageFlags &= ~2;
}

// @fnv 0x00826b90
void TESPackage::SetMustComplete(bool enabled)
{
    enabled ? kData.uiPackageFlags |= 4 : kData.uiPackageFlags &= ~4;
}

// @fnv 0x00984f60
void TESPackage::SetProcedureType(PACKAGE_PROCEDURE_TYPE procedure)
{
    eProcedureType = procedure;
}

// @fnv 0x0055b980
unsigned int BGSMessageInitAccess::GetIconFormID()
{
    return iconFormID;
}

// Sets the first byte of the object to 3 and zeroes the two 32-bit fields at offsets 4 and 8, then returns the object.
// @fnv 0x0067f030
LocationDescriptor* __fastcall FUN_0067f030(LocationDescriptor* pObject)
{
    *(char*)pObject = 3;
    *(unsigned int*)((char*)pObject + 4) = 0;
    *(unsigned int*)((char*)pObject + 8) = 0;
    return pObject;
}

struct FUN_0067f110_shell : public LocationDescriptor
{
    void FUN_0067f110();
};

// @fnv 0x0067f110
void FUN_0067f110_shell::FUN_0067f110()
{
    m_ucLocationType = -1;
    m_pLocationData = 0;
    pObject = 0;
}

struct FUN_0067f140_shell : public LocationDescriptor
{
    void FUN_0067f140(int);
};

// @fnv 0x0067f140
void FUN_0067f140_shell::FUN_0067f140(int aeLoctype)
{
    if (aeLoctype != m_ucLocationType)
    {
        m_ucLocationType = aeLoctype;
        switch (m_ucLocationType)
        {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            pObject = 0;
            break;
        case 1:
            pObject = 0;
            m_pLocationData = 0;
            break;
        }
    }
}

struct FUN_0067f1c0_shell : public LocationDescriptor
{
    unsigned int FUN_0067f1c0();
};

// @fnv 0x0067f1c0
unsigned int FUN_0067f1c0_shell::FUN_0067f1c0()
{
    switch (m_ucLocationType)
    {
    case -1:
    case 1:
        return 0;
    default:
        return m_pLocationData;
    }
}

struct FUN_0067f1f0_shell : public LocationDescriptor
{
    void FUN_0067f1f0(unsigned int);
};

// Stores aiRad at offset 4 unless the byte at offset 0 is -1 or 1.
// @fnv 0x0067f1f0
void FUN_0067f1f0_shell::FUN_0067f1f0(unsigned int aiRad)
{
    switch (*reinterpret_cast<char*>(this))
    {
    case -1:
    case 1:
        break;
    default:
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) = aiRad;
        break;
    }
}

struct FUN_0067f410_shell : public LocationDescriptor
{
    void FUN_0067f410(TESObjectCELL*);
};

// @fnv 0x0067f410
void FUN_0067f410_shell::FUN_0067f410(TESObjectCELL* apCell)
{
    m_ucLocationType = 1;
    pCell = apCell;
}

struct FUN_0067f970_shell : public LocationDescriptor
{
    bool FUN_0067f970();
};

// @fnv 0x0067f970
bool FUN_0067f970_shell::FUN_0067f970()
{
    if (GetLocType() > PLT_EDITORLOC)
        return true;
    else
        return false;
}

class NiAVObject;
class NiQuaternion;
class TESEyes;
class BSAnimGroupSequence;
enum ACTION_FLAGS
{
};
enum ANIM_GROUP_SECTION
{
};
class Animation
{
  public:
    BSAnimGroupSequence* PlayGroup(unsigned short, ACTION_FLAGS, int, ANIM_GROUP_SECTION);
};
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_004a3e90(float);
float __cdecl FUN_004b5550(float, float);
void __cdecl FUN_00561500(void*, const NiQuaternion*);
void __cdecl FUN_00c9bdf0(NiAVObject*, float);
extern const double DAT_01020998;
extern float runtimeInitializationFloat3452;
extern TESEyes* DAT_011cb600;

union __declspec(align(16)) hkQuadReal
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) FUN_005dbf20
{
    FUN_005dbf20(float);
    hkQuadReal m_vValue;
};
struct __declspec(align(16)) hkVector4
{
    hkVector4();
    void FUN_005dbf70(const hkVector4&, const hkVector4&, const FUN_005dbf20&);
    hkQuadReal m_vComponents;
};
class bhkCharacterController
{
  public:
    float& GetVectorElement(int);
};
hkVector4& __cdecl FUN_004a3e00(hkVector4&, const NiPoint3&);
struct hkRotation
{
    hkRotation();
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
struct ThreeByThreeMatrix
{
    ThreeByThreeMatrix();
    void FUN_00a59780(float, float, float);
    float m_afEntries[3][3];
};
hkRotation& __cdecl VisitAndFetchThree(hkRotation&, const ThreeByThreeMatrix&);
struct __declspec(align(16)) hkQuaternion
{
    hkQuaternion();
    hkQuaternion(const hkRotation&);
    void FUN_00cb2850(const hkQuaternion&, const hkQuaternion&, float);
    hkVector4 m_vec;
};
struct B006815c0 : public NiPoint3
{
    B006815c0();
};
struct NiPoint3_sub : public NiPoint3
{
    NiPoint3 operator-(const NiPoint3&) const;
};
struct ExtraDataList_helper : public ExtraDataList
{
    void CallExtraDataListMethod36(TESObjectREFR*);
};
class bhkRigidBody
{
  public:
    void FUN_00560bc0(NiPoint3&);
    void FUN_00c8de20(const hkVector4&, const hkQuaternion&, float, float);
};
class Creature
{
  public:
    static void __cdecl SetNodeFlagsRecursive(NiAVObject*, int, bool, bool, bool);
};
class TESBoundObject : public TESForm
{
};
class TESNPC : public TESBoundObject
{
  public:
    void FUN_0060a950(TESEyes*);
};
class P01ObjA
{
  public:
    TESForm* GetNext();
};
class BSThread
{
  public:
    unsigned int GetThreadID();
};
class TESResponse
{
  public:
    int GetNext();
};

class AIProcess
{
  public:
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual void Unk_AF();
    virtual void Unk_B0();
    virtual void Unk_B1();
    virtual void Unk_B2();
    virtual void Unk_B3();
    virtual void Unk_B4();
    virtual void Unk_B5();
    virtual void Unk_B6();
    virtual void Unk_B7();
    virtual void Unk_B8();
    virtual void Unk_B9();
    virtual void Unk_BA();
    virtual void Unk_BB();
    virtual void Unk_BC();
    virtual void Unk_BD();
    virtual void Unk_BE();
    virtual void Unk_BF();
    virtual void Unk_C0();
    virtual void Unk_C1();
    virtual void Unk_C2();
    virtual void Unk_C3();
    virtual void Unk_C4();
    virtual void Unk_C5();
    virtual void Unk_C6();
    virtual void Unk_C7();
    virtual void Unk_C8();
    virtual void Unk_C9();
    virtual void Unk_CA();
    virtual void Unk_CB();
    virtual void Unk_CC();
    virtual void Unk_CD();
    virtual void Unk_CE();
    virtual void Unk_CF();
    virtual void Unk_D0();
    virtual void Unk_D1();
    virtual void Unk_D2();
    virtual void Unk_D3();
    virtual void Unk_D4();
    virtual void Unk_D5();
    virtual void Unk_D6();
    virtual void Unk_D7();
    virtual void Unk_D8();
    virtual void Unk_D9();
    virtual void Unk_DA();
    virtual void Unk_DB();
    virtual void Unk_DC();
    virtual void Unk_DD();
    virtual void Unk_DE();
    virtual void Unk_DF();
    virtual void Unk_E0();
    virtual void Unk_E1();
    virtual void Unk_E2();
    virtual void Unk_E3();
    virtual void Unk_E4();
    virtual void Unk_E5();
    virtual void Unk_E6();
    virtual void Unk_E7();
    virtual void Unk_E8();
    virtual void Unk_E9();
    virtual void Unk_EA();
    virtual void Unk_EB();
    virtual void Unk_EC();
    virtual void Unk_ED();
    virtual void Unk_EE();
    virtual void Unk_EF();
    virtual void Unk_F0();
    virtual void Unk_F1();
    virtual void Unk_F2();
    virtual void Unk_F3();
    virtual void Unk_F4();
    virtual void Unk_F5();
    virtual void Unk_F6();
    virtual void Unk_F7();
    virtual void Unk_F8();
    virtual void Unk_F9();
    virtual void Unk_FA();
    virtual void Unk_FB();
    virtual void Unk_FC();
    virtual void Unk_FD();
    virtual void Unk_FE();
    virtual void Unk_FF();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_10A();
    virtual void Unk_10B();
    virtual void Unk_10C();
    virtual void Unk_10D();
    virtual void Unk_10E();
    virtual void Unk_10F();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_11A();
    virtual void Unk_11B();
    virtual void Unk_11C();
    virtual void Unk_11D();
    virtual void Unk_11E();
    virtual void Unk_11F();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_12A();
    virtual void Unk_12B();
    virtual void Unk_12C();
    virtual void Unk_12D();
    virtual void Unk_12E();
    virtual void Unk_12F();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual void Unk_133();
    virtual void Unk_134();
    virtual void Unk_135();
    virtual void Unk_136();
    virtual void Unk_137();
    virtual void Unk_138();
    virtual void Unk_139();
    virtual void Unk_13A();
    virtual void Unk_13B();
    virtual void Unk_13C();
    virtual void Unk_13D();
    virtual void Unk_13E();
    virtual void Unk_13F();
    virtual void Unk_140();
    virtual void Unk_141();
    virtual void Unk_142();
    virtual void Unk_143();
    virtual void Unk_144();
    virtual void Unk_145();
    virtual void Unk_146();
    virtual void Unk_147();
    virtual void Unk_148();
    virtual void Unk_149();
    virtual void Unk_14A();
    virtual void Unk_14B();
    virtual void Unk_14C();
    virtual void Unk_14D();
    virtual void Unk_14E();
    virtual void Unk_14F();
    virtual void Unk_150();
    virtual void Unk_151();
    virtual void Unk_152();
    virtual void Unk_153();
    virtual void Unk_154();
    virtual void Unk_155();
    virtual void Unk_156();
    virtual void Unk_157();
    virtual void Unk_158();
    virtual void Unk_159();
    virtual void Unk_15A();
    virtual void Unk_15B();
    virtual void Unk_15C();
    virtual void Unk_15D();
    virtual void Unk_15E();
    virtual void Unk_15F();
    virtual void Unk_160();
    virtual void Unk_161();
    virtual void Unk_162();
    virtual void Unk_163();
    virtual void Unk_164();
    virtual void Unk_165();
    virtual void Unk_166();
    virtual void Unk_167();
    virtual void Unk_168();
    virtual void Unk_169();
    virtual void Unk_16A();
    virtual void Unk_16B();
    virtual void Unk_16C();
    virtual void Unk_16D();
    virtual void Unk_16E();
    virtual void Unk_16F();
    virtual void Unk_170();
    virtual void Unk_171();
    virtual void Unk_172();
    virtual void Unk_173();
    virtual void Unk_174();
    virtual void Unk_175();
    virtual void Unk_176();
    virtual void Unk_177();
    virtual void Unk_178();
    virtual void Unk_179();
    virtual void Unk_17A();
    virtual void Unk_17B();
    virtual void Unk_17C();
    virtual void Unk_17D();
    virtual void Unk_17E();
    virtual void Unk_17F();
    virtual void Unk_180();
    virtual void Unk_181();
    virtual void Unk_182();
    virtual void Unk_183();
    virtual void Unk_184();
    virtual void Unk_185();
    virtual void Unk_186();
    virtual void Unk_187();
    virtual void Unk_188();
    virtual void Unk_189();
    virtual void Unk_18A();
    virtual void Unk_18B();
    virtual void Unk_18C();
    virtual void Unk_18D();
    virtual void Unk_18E();
    virtual void Unk_18F();
    virtual void Unk_190();
    virtual void Unk_191(bool);
    virtual void Unk_192();
    virtual void Unk_193();
    virtual void Unk_194();
    virtual void Unk_195();
    virtual void Unk_196();
    virtual void Unk_197();
    virtual void Unk_198();
    virtual void Unk_199();
    virtual void Unk_19A();
    virtual void Unk_19B();
    virtual void Unk_19C();
    virtual void Unk_19D();
    virtual void Unk_19E();
    virtual void Unk_19F();
    virtual void Unk_1A0();
    virtual void Unk_1A1();
    virtual void Unk_1A2();
    virtual void Unk_1A3();
    virtual void Unk_1A4();
    virtual void Unk_1A5();
    virtual void Unk_1A6();
    virtual void Unk_1A7();
    virtual void Unk_1A8();
    virtual void Unk_1A9();
    virtual void Unk_1AA();
    virtual void Unk_1AB();
    virtual void Unk_1AC();
    virtual void Unk_1AD();
    virtual void Unk_1AE();
    virtual void Unk_1AF();
    virtual void Unk_1B0();
    virtual void Unk_1B1();
    virtual void Unk_1B2();
    virtual void Unk_1B3();
    virtual void Unk_1B4();
    virtual void Unk_1B5();
    virtual void Unk_1B6();
    virtual void Unk_1B7();
    virtual void Unk_1B8();
    virtual void Unk_1B9();
    virtual void Unk_1BA();
    virtual void Unk_1BB();
    virtual void Unk_1BC();
    virtual void Unk_1BD();
    virtual void Unk_1BE(bool);
};
class BSFaceGenAnimationData
{
  public:
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36(bool, bool);
};
class Actor;
class MagicCaster
{
  public:
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
    virtual void Unk_0A();
    virtual void* Unk_0B();
    Actor* GetCasterActor();
};
class MagicTarget
{
  public:
    Actor* GetOwnerActor() const;
};
class Actor
{
  public:
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual NiAVObject* GetNiNode();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual Animation* GetAnimData();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos() const;
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual bool Unk_8B(bool);
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual void Unk_AF();
    virtual void Unk_B0(void*);
    void SetReloadState(bool);
    void SetAnimationGroupAction(int);
    void FUN_008acf10(bool);
    BSFaceGenAnimationData* GetActorFaceGenData();
};
void __cdecl StartHostilityAndCombat(Actor*, Actor*);
void __cdecl FUN_0080b8f0(Actor*, Actor*);
class ActiveEffect
{
  public:
    void Dispel(bool);
};
struct FUN_00826be0_shell : public ActiveEffect
{
    void FUN_00826be0(float);
};

// @fnv 0x00826be0
void FUN_00826be0_shell::FUN_00826be0(float afSecondsElapsed)
{
    Actor* ptarget =
        ((BSThread*)this)->GetThreadID() ? ((MagicTarget*)((BSThread*)this)->GetThreadID())->GetOwnerActor() : 0;
    Actor* pcaster =
        ((TESResponse*)this)->GetNext() ? ((MagicCaster*)((TESResponse*)this)->GetNext())->GetCasterActor() : 0;
    if (!pcaster)
    {
        Dispel(true);
    }
    else if (*(bhkRigidBody**)((char*)this + 0x48) && ptarget)
    {
        if (ptarget->Unk_8B(false))
        {
            Dispel(false);
            return;
        }
        if (*(int*)((char*)this + 0x4c) == 0)
        {
            *(float*)((char*)this + 0x50) = 0.0f;
            *(int*)((char*)this + 0x4c) = 10;
        }
        if (*(int*)((char*)this + 0x4c) == 10)
        {
            BaseProcess* pprocess = (BaseProcess*)((PlayerQuestData*)ptarget)->GetLogDate();
            if (!((TESResponse*)pprocess)->GetNext())
                ((AIProcess*)pprocess)->Unk_1BE(true);
            if (*(float*)((char*)this + 4) - *(float*)((char*)this + 0x50) > DAT_01020998)
                *(int*)((char*)this + 0x4c) = 20;
            float fLerp = FUN_0040ebd0(1.0f, (*(float*)((char*)this + 4) - *(float*)((char*)this + 0x50)) / 4.0);
            hkVector4 endPos;
            hkVector4 startPos;
            FUN_004a3e00(endPos, *(NiPoint3*)((char*)this + 0x54));
            FUN_004a3e00(startPos, *(NiPoint3*)((char*)this + 0x54));
            ((bhkCharacterController*)&endPos)->GetVectorElement(2) += FUN_004a3e90(100.0f);
            hkVector4 hkpos;
            hkpos.FUN_005dbf70(startPos, endPos, fLerp);
            B006815c0 currentPos;
            (*(bhkRigidBody**)((char*)this + 0x48))->FUN_00560bc0(currentPos);
            NiPoint3 dirToCaster = *(const NiPoint3_sub*)pcaster->GetPos() - currentPos;
            dirToCaster.z = 0.0f;
            float fx = -FUN_004b5550(dirToCaster.y, dirToCaster.x);
            float afDepth = runtimeInitializationFloat3452;
            float fy = 0.5f;
            ThreeByThreeMatrix matrix;
            matrix.FUN_00a59780(fx, fy, afDepth);
            hkRotation kHkRotation;
            VisitAndFetchThree(kHkRotation, matrix);
            hkQuaternion startRot;
            FUN_00561500(&startRot, (const NiQuaternion*)((char*)this + 0x60));
            hkQuaternion endRot(kHkRotation);
            hkQuaternion hkquat;
            hkquat.FUN_00cb2850(startRot, endRot, fLerp);
            (*(bhkRigidBody**)((char*)this + 0x48))->FUN_00c8de20(hkpos, hkquat, 1.0f / afSecondsElapsed, 1.0f);
            ptarget->Unk_B0(((MagicCaster*)((TESResponse*)this)->GetNext())->Unk_0B());
        }
        else if (*(int*)((char*)this + 0x4c) == 20)
        {
            Animation* panim = ptarget->GetAnimData();
            NiAVObject* pNode = ptarget->GetNiNode();
            if (pNode && panim)
            {
                *(int*)((char*)this + 0x4c) = 30;
                ptarget->SetReloadState(true);
                panim->PlayGroup(0, (ACTION_FLAGS)0, -1, (ANIM_GROUP_SECTION)-1);
                FUN_00c9bdf0(pNode, 0.0f);
                BaseProcess* pprocess = (BaseProcess*)((PlayerQuestData*)ptarget)->GetLogDate();
                if (!((TESResponse*)pprocess)->GetNext())
                    ((AIProcess*)pprocess)->Unk_1BE(false);
                ((ExtraDataList_helper*)((TESObjectREFR*)ptarget)->GetExtraData())->CallExtraDataListMethod36(0);
                *(float*)((char*)this + 0x50) = *(float*)((char*)this + 4);
            }
        }
        else if (*(int*)((char*)this + 0x4c) == 30)
        {
            if (*(float*)((char*)this + 4) - *(float*)((char*)this + 0x50) > 2.0)
            {
                *(float*)((char*)this + 0x50) = *(float*)((char*)this + 4);
                *(int*)((char*)this + 0x4c) = 40;
                NiAVObject* pNode = ptarget->GetNiNode();
                if (pNode)
                    Creature::SetNodeFlagsRecursive(pNode, 4, true, false, true);
                TESNPC* pnpc = dynamic_cast<TESNPC*>((TESBoundObject*)((P01ObjA*)ptarget)->GetNext());
                if (pnpc)
                    pnpc->FUN_0060a950(DAT_011cb600);
                BSFaceGenAnimationData* pFaceGenAnimData = ptarget->GetActorFaceGenData();
                if (pFaceGenAnimData)
                    pFaceGenAnimData->Unk_36(false, false);
            }
        }
        else if (*(int*)((char*)this + 0x4c) == 40)
        {
            if (*(float*)((char*)this + 4) - *(float*)((char*)this + 0x50) > 1.0)
            {
                *(int*)((char*)this + 0x4c) = 50;
                ptarget->SetAnimationGroupAction(4);
                ptarget->FUN_008acf10(false);
                StartHostilityAndCombat(ptarget, pcaster);
            }
        }
        else if (*(int*)((char*)this + 0x4c) == 50)
        {
            ((AIProcess*)((PlayerQuestData*)ptarget)->GetLogDate())->Unk_191(false);
            FUN_0080b8f0(ptarget, pcaster);
        }
    }
}

struct FUN_0067f430_shell
{
    char m_ucLocationType;
    char pad0[7];
    TESForm* m_pLocationObject;

    TESForm* GetLocationObject();
};

// Returns the stored TESForm pointer if the leading byte equals 4, otherwise returns null.
// @fnv 0x0067f430
TESForm* FUN_0067f430_shell::GetLocationObject()
{
    if (m_ucLocationType == 4)
        return m_pLocationObject;
    else
        return 0;
}

struct FUN_0067f460_shell
{
    char b[8];
    int v;
    void SetValue(int a);
};

// @fnv 0x0067f460
void FUN_0067f460_shell::SetValue(int aiValue)
{
    *(char*)this = 4;
    v = aiValue;
}

namespace fnv_0067f600 {
struct FUN_0067f430_shell : public LocationDescriptor
{
    TESForm* GetLocationObject();
};

struct FUN_0067f600_shell : public LocationDescriptor
{
    bool IsDifferentFrom(LocationDescriptor* other);
    unsigned int FUN_0067f1c0();
    int GetObjectType();
};

// @fnv 0x0067f600
bool FUN_0067f600_shell::IsDifferentFrom(LocationDescriptor* other)
{
    if (!other)
        return true;
    if (GetLocType() != other->GetLocType())
        return true;
    if (FUN_0067f1c0() != reinterpret_cast<FUN_0067f600_shell*>(other)->FUN_0067f1c0())
        return true;
    if (GetLocationReference() != other->GetLocationReference())
        return true;
    if (GetLocationCellReference() != other->GetLocationCellReference())
        return true;
    if (reinterpret_cast<FUN_0067f430_shell*>(this)->GetLocationObject() !=
        reinterpret_cast<FUN_0067f430_shell*>(other)->GetLocationObject())
        return true;
    if (GetObjectType() != reinterpret_cast<FUN_0067f600_shell*>(other)->GetObjectType())
        return true;
    return false;
}
}  // namespace fnv_0067f600

typedef int PACKAGE_OBJECT_TYPE;

struct FUN_0067f480_shell
{
    char m_ucLocationType;
    char pad1[3];
    char pad2[4];
    PACKAGE_OBJECT_TYPE eObjType;
    PACKAGE_OBJECT_TYPE GetObjectType();
};

// Returns eObjType when the leading byte equals 5, otherwise returns 0.
// @fnv 0x0067f480
PACKAGE_OBJECT_TYPE FUN_0067f480_shell::GetObjectType()
{
    if (m_ucLocationType == 5)
        return eObjType;
    else
        return (PACKAGE_OBJECT_TYPE)0;
}

namespace fnv_0067f6c0 {
struct FUN_0067eff0_Class
{
    char m_ucLocationType;
    unsigned int m_pLocationData;
    unsigned int m_iSearchRadius;

    void FUN_0067eff0();
};

typedef FUN_0067eff0_Class ChunkPayloadHandler;

struct FUN_0067f480_shell
{
    int GetObjectType();
};

struct FUN_0067f1c0_shell
{
    unsigned int FUN_0067f1c0();
};

void* __cdecl memset(void* buffer, int value, unsigned int count);
unsigned char __cdecl _FUN_00401500();
void __cdecl _FUN_00485990(unsigned int chunkId, ChunkPayloadHandler* location, unsigned int size);

struct FUN_0067f6c0_shell : public LocationDescriptor
{
    void FUN_0067f6c0(unsigned int chunkId);
};

// @fnv 0x0067f6c0
void FUN_0067f6c0_shell::FUN_0067f6c0(unsigned int chunkId)
{
    ChunkPayloadHandler locStruct;
    memset(&locStruct, 0, sizeof(locStruct));

    locStruct.m_ucLocationType = (char)GetLocType();

    if (GetLocType() == PLT_TYPE)
        locStruct.m_pLocationData = reinterpret_cast<FUN_0067f480_shell*>(this)->GetObjectType();
    else if (pObject != 0)
        locStruct.m_pLocationData = pObject->GetFormID();

    locStruct.m_iSearchRadius = reinterpret_cast<FUN_0067f1c0_shell*>(this)->FUN_0067f1c0();

    if (_FUN_00401500())
        locStruct.FUN_0067eff0();

    _FUN_00485990(chunkId, &locStruct, 0xc);

    if (_FUN_00401500())
        locStruct.FUN_0067eff0();
}
}  // namespace fnv_0067f6c0

struct FUN_0067f060_Source
{
    char unk00;
    int unk04;
    int unk08;
};

struct FUN_0067f060_Class
{
    char unk00;
    int unk04;
    int unk08;

    FUN_0067f060_Class* __thiscall CopyFromSource(FUN_0067f060_Source* source);
};

// Copies the source's type byte and value into this object, then sets the remaining fields based on the type byte.
// @fnv 0x0067f060
FUN_0067f060_Class* __thiscall FUN_0067f060_Class::CopyFromSource(FUN_0067f060_Source* source)
{
    this->unk00 = source->unk00;
    this->unk04 = source->unk08;

    switch (this->unk00)
    {
    case 1:
        this->unk08 = source->unk04;
        this->unk04 = 0;
        break;
    case 0:
        this->unk08 = source->unk04;
        break;
    case 4:
        this->unk08 = source->unk04;
        break;
    case 5:
        this->unk08 = source->unk04;
        break;
    case 2:
    case 3:
        this->unk08 = 0;
        break;
    }

    return this;
}

class PkgLocNode;
class PkgLocChild;
class PkgLocSink;

class FUN_0067f220_cls
{
  public:
    unsigned int m_00;
    PkgLocNode* Lookup(int a1);
    bool LookupAndStore(int a1, int a2, unsigned char* out);
};

class PkgLocNode
{
  public:
    PkgLocChild* Resolve();
};

class PkgLocChild
{
  public:
    int Kind();
};

class PkgLocSink
{
  public:
    unsigned char Store(int a2, PkgLocNode* p);
};

PkgLocSink* PkgLocFind(PkgLocNode* p);

// @fnv 0x0067f220
bool FUN_0067f220_cls::LookupAndStore(int a1, int a2, unsigned char* pucOut)
{
    *pucOut = 0;
    PkgLocNode* p = Lookup(a1);
    if (p == 0)
    {
        return false;
    }
    if (p->Resolve()->Kind() != 0x15)
    {
        return false;
    }
    PkgLocSink* pSink = PkgLocFind(p);
    if (pSink == 0)
    {
        return true;
    }
    *pucOut = pSink->Store(a2, p);
    return true;
}

class TESSaveLoadGame
{
  public:
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int, int);
};
extern TESSaveLoadGame* DAT_011de45c;
struct FUN_0067fa00_shell : public LocationDescriptor
{
    void FUN_0067fa00();
};
// Serializes a form ID and object reference through the save/load game, writing the object's form ID for cases 0-4 and the pointer for case 5.
// @fnv 0x0067fa00
void FUN_0067fa00_shell::FUN_0067fa00()
{
    DAT_011de45c->FUN_008579b0(this, 1);
    DAT_011de45c->FUN_008579b0(&m_pLocationData, 4);
    switch (m_ucLocationType)
    {
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4: {
        unsigned int id = 0;
        if (pObject)
            id = pObject->GetFormID();
        DAT_011de45c->FUN_00857a10((int)&id, 4);
        break;
    }
    case 5:
        DAT_011de45c->FUN_008579b0(&pObject, 4);
        break;
    }
}

int __cdecl LookupFormByID(int value);

struct FUN_0067fb20_holder
{
    signed char status;
    unsigned char flags1;
    unsigned short flags2;
    unsigned int metadata;
    int storedValue;
    void UpdateStoredValue();
};

// For status 0-4, replaces storedValue with the result of LookupFormByID(storedValue); other statuses do nothing.
// @fnv 0x0067fb20
void FUN_0067fb20_holder::UpdateStoredValue()
{
    switch (status)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4: {
        int originalValue = storedValue;
        storedValue = LookupFormByID(originalValue);
        break;
    }
    default:
        break;
    }
}

class LocationDescriptor;
class TESForm;
struct LocationInputStream
{
    void FUN_00865e50(void* destination, unsigned int byteCount, int flags);
    void FUN_00865df0(TESForm* form, int flags);
};
struct FUN_0067fb60_shell : LocationDescriptor
{
    void FUN_0067fb60(LocationInputStream* input);
};
// Reads a one-byte type tag and a 4-byte value from the stream, then loads pObject as a form reference or a raw 4-byte value depending on the tag.
// @fnv 0x0067fb60
void FUN_0067fb60_shell::FUN_0067fb60(LocationInputStream* pStream)
{
    pStream->FUN_00865e50(&m_ucLocationType, 1, 0);
    pStream->FUN_00865e50(&m_pLocationData, 4, 0);
    switch (m_ucLocationType)
    {
    case -1:
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        pStream->FUN_00865df0(pObject, 0);
        break;
    case 5:
        pStream->FUN_00865e50(&pObject, 4, 0);
        break;
    }
}

class PackageLoadStream
{
  public:
    void ReadBytes(void* apData, unsigned int auiSize);
    void ReadPtr(void* apData);
};

class FUN_0067fbe0_cls : public LocationDescriptor
{
  public:
    void FUN_0067fbe0(PackageLoadStream* apStream);
};

// Reads a type byte and a 4-byte value from the stream, then reads pObject as a pointer for types 0-4 or as 4 raw bytes for type 5.
// @fnv 0x0067fbe0
void FUN_0067fbe0_cls::FUN_0067fbe0(PackageLoadStream* apStream)
{
    apStream->ReadBytes(&m_ucLocationType, 1);
    apStream->ReadBytes(&m_pLocationData, 4);
    switch (m_ucLocationType)
    {
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        apStream->ReadPtr(&pObject);
        break;
    case 5:
        apStream->ReadBytes(&pObject, 4);
        break;
    }
}

class FUN_0067f990_C
{
  public:
    char m_eRequestType;

    unsigned short FUN_0067f990();
};

// Returns 5 plus 4 when m_eRequestType is between 0 and 5 inclusive.
// @fnv 0x0067f990
unsigned short FUN_0067f990_C::FUN_0067f990()
{
    unsigned short usSize = 0;
    usSize += 1;
    usSize += 4;
    switch (m_eRequestType)
    {
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        usSize += 4;
        break;
    case 5:
        usSize += 4;
        break;
    }
    return usSize;
}

namespace fnv_0067faa0 {
struct FileQ
{
    void FUN_008579e0(void* p, int n);
    void FUN_00857aa0(void* p, int n);
};
extern FileQ* DAT_011de45c;
struct OwnQ
{
    char cType;
    char pad[3];
    int iVal;
    int iData;
    void FUN_0067faa0();
};
// @fnv 0x0067faa0
void OwnQ::FUN_0067faa0()
{
    int iTmp;
    DAT_011de45c->FUN_008579e0(this, 1);
    DAT_011de45c->FUN_008579e0(&iVal, 4);
    switch (cType)
    {
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        DAT_011de45c->FUN_00857aa0(&iTmp, 4);
        iData = iTmp;
        break;
    case 5:
        DAT_011de45c->FUN_008579e0(&iData, 4);
        break;
    }
}
}  // namespace fnv_0067faa0

TESForm* LookupFormByID(unsigned int formID);

struct FUN_0067fc50_shell : LocationDescriptor
{
    void ResolveObject(int unused);
};

// For PLT_REFERENCE, PLT_CELL, PLT_CURRLOC, PLT_EDITORLOC, or PLT_OBJECT, resolves non-null pObject through LookupFormByID.
// @fnv 0x0067fc50
void FUN_0067fc50_shell::ResolveObject(int unused)
{
    switch (m_ucLocationType)
    {
    case PLT_REFERENCE:
    case PLT_CELL:
    case PLT_CURRLOC:
    case PLT_EDITORLOC:
    case PLT_OBJECT:
        pObject = pObject ? LookupFormByID(reinterpret_cast<unsigned int>(pObject)) : 0;
    }
}
