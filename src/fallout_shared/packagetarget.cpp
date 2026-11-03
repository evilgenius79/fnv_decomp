// fallout_shared/packagetarget.cpp: PackageTargetRecord, LocationDescriptor, Script, SaveDataStub (21 functions)

#include "Script.h"
#include "packagetarget_decls.h"
#include "packagetarget_types_PackageLocation.h"
#include "packagetarget_types_PACK_TARG_TYPE.h"
#include "packagetarget_types_PackageTarget.h"

// @fnv 0x00519b00
int PackageTargetRecord::GetTargetKind()
{
    return (PACK_TARG_TYPE)m_uiTargetType;
}

// @fnv 0x006800b0
void PackageTargetRecord::SetTargetKind(PACK_TARG_TYPE aeTargetType)
{
    if (m_uiTargetType != aeTargetType)
    {
        m_uiTargetType = (unsigned char)aeTargetType;
        switch (m_uiTargetType)
        {
        case PACK_TARG_TYPE_PTT_REFERENCE:
            m_pWorldReferenceInfo = 0;
            break;
        case PACK_TARG_TYPE_PTT_OBJECT:
            m_pWorldReferenceInfo = 0;
            break;
        case PACK_TARG_TYPE_PTT_TYPE:
            m_pWorldReferenceInfo = 0;
            break;
        }
    }
}

// Returns the target reference if the target type is PACK_TARG_TYPE_PTT_REFERENCE, otherwise returns null.
// @fnv 0x00680020
TESObjectREFR* PackageTargetRecord::GetReferenceTarget()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_REFERENCE)
        return m_pWorldReferenceInfo;
    else
        return 0;
}

// If the package target type is PACK_TARG_TYPE_PTT_REFERENCE, stores the given reference as the target.
// @fnv 0x00680110
void PackageTargetRecord::SetTargetObjectReference(TESObjectREFR* reference)
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_REFERENCE)
        m_pWorldReferenceInfo = reference;
}

// Returns pObject when the target type is PACK_TARG_TYPE_PTT_OBJECT, otherwise returns null.
// @fnv 0x00680050
TESForm* PackageTargetRecord::GetTargetForm()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_OBJECT)
        return pObject;
    else
        return 0;
}

// @fnv 0x00680080
PACKAGE_OBJECT_TYPE PackageTargetRecord::GetTargetObjectType()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_TYPE)
        return eObjType;
    else
        return (PACKAGE_OBJECT_TYPE)0;
}

// Copies location data from source into this object when copy is set or source's location type is valid, dispatching on the location type.
// @fnv 0x0067f4d0
void LocationDescriptor::Copy(LocationDescriptor* source, bool copy)
{
    if (source != 0)
    {
        if (copy || source->GetLocType() != PACK_LOC_TYPE_INVALID)
        {
            SetLocationType(source->GetLocType());
            switch (m_ucLocationType)
            {
            case 0:
                SetRadius(source->FUN_0067f1c0());
                FUN_0067f3c0(source->GetLocationReference());
                break;
            case 1:
                FUN_0067f410(source->GetLocationCellReference());
                break;
            case 4:
                SetRadius(source->FUN_0067f1c0());
                SetValue((TESForm*)source->FUN_0067f430());
                break;
            case 5:
                SetRadius(source->FUN_0067f1c0());
                FUN_0067f4b0(source->GetObjectType());
                break;
            case 2:
            case 3:
            case 7:
                SetRadius(source->FUN_0067f1c0());
                break;
            case 6:
                SetRadius(source->FUN_0067f1c0());
                break;
            }
        }
    }
}

// @fnv 0x00671d10
char* Script::GetData()
{
    return m_data;
}

// Resolves the stored form ID against the owner's file and looks up the package target reference or object, warning if it is missing.
// @fnv 0x006803b0
void PackageTargetRecord::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)pTargetForm;
    TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
    switch (m_uiTargetType)
    {
    case 0:
        m_pWorldReferenceInfo = dynamic_cast<TESObjectREFR*>(GetFormByID(formID));
        if (!m_pWorldReferenceInfo)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find Package Target Reference (%08X) on owner object \"%s\".",
                            formID, owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find Package Target Reference (%08X) on owner object (%08X).",
                            formID, owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find Package Target Reference (%08X) on unknown owner.", formID);
        }
        break;
    case 1:
        pObject = GetFormByID(formID);
        if (!pObject)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find Package Target Object (%08X) on owner object \"%s\".", formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find Package Target Object (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find Package Target Object (%08X) on unknown owner.", formID);
        }
        break;
    }
}

// Sets the byte at pThis to 2 and zeroes the int, int and float fields at offsets 4, 8 and 12, then returns pThis.
// @fnv 0x0067ff70
void* __fastcall FUN_0067ff70(void* pThis)
{
    *(unsigned char*)pThis = 2;
    *((int*)pThis + 1) = 0;
    *((int*)pThis + 2) = 0;
    *((float*)pThis + 3) = 0.0f;
    return pThis;
}

struct PTFile
{
    unsigned char m_uiTargetType;
    char pad[3];
    unsigned int iFormID;
    int iValue;
    float m_fTargetValue;
};
struct FUN_0067ffa0_cls
{
    unsigned char m_uiTargetType;
    char pad[3];
    unsigned int ref;
    void SetTargetKind(int t);
    void SetFlags(unsigned int v);
    void FUN_0063f790(float f);
    FUN_0067ffa0_cls* LoadFromPTFile(PTFile* f);
};
// @fnv 0x0067ffa0
FUN_0067ffa0_cls* FUN_0067ffa0_cls::LoadFromPTFile(PTFile* apFile)
{
    SetTargetKind(apFile->m_uiTargetType);
    SetFlags(apFile->iValue);
    FUN_0063f790(apFile->m_fTargetValue);
    switch (m_uiTargetType)
    {
    case 0:
    case 1:
        ref = apFile->iFormID;
        break;
    case 2:
        ref = apFile->iFormID;
        break;
    }
    return this;
}

struct FUN_00680140_shell : public PackageTargetRecord
{
    void SetObjectTarget(TESForm*);
};

// If the package target type is PTT_OBJECT, stores apObj in pObject.
// @fnv 0x00680140
void FUN_00680140_shell::SetObjectTarget(TESForm* apObj)
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_OBJECT)
        pObject = apObj;
}

struct ArrSI
{
    unsigned int GetFlags(void);
};

struct Twin_0084d030
{
    float GetStoredFloatValue(void);
};

struct FUN_00680220_shell : PackageTargetRecord
{
    bool Compare(PackageTargetRecord* apCompare);
};

// Returns true if apCompare is null or any of the compared values differ; returns false when all compared values match.
// @fnv 0x00680220
bool FUN_00680220_shell::Compare(PackageTargetRecord* apCompare)
{
    if (apCompare == 0)
        return true;
    if (this->GetTargetKind() != apCompare->GetTargetKind())
        return true;
    if (this->GetReferenceTarget() != apCompare->GetReferenceTarget())
        return true;
    if (this->GetTargetForm() != apCompare->GetTargetForm())
        return true;
    if (this->GetTargetObjectType() != apCompare->GetTargetObjectType())
        return true;
    if (((ArrSI*)this)->GetFlags() != ((ArrSI*)apCompare)->GetFlags())
        return true;
    if (((Twin_0084d030*)this)->GetStoredFloatValue() != ((Twin_0084d030*)apCompare)->GetStoredFloatValue())
        return true;
    return false;
}

struct ChunkPayload16
{
    void FUN_0067ff10();
};
struct FormValueEntry
{
    unsigned char m_uiTargetType;
    unsigned int iFormID;
    int iValue;
    float m_fTargetValue;
};
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
extern "C" bool __cdecl FUN_00401500();
extern "C" void __cdecl AppendChunk(int id, FormValueEntry* data, unsigned int size);

struct FUN_006802f0_shell : PackageTargetRecord
{
    void FUN_006802f0(int chunk);
};

// @fnv 0x006802f0
void FUN_006802f0_shell::FUN_006802f0(int chunk)
{
    FormValueEntry record;
    memset(&record, 0, 16);
    record.iValue = this->iValue;
    record.m_fTargetValue = this->m_fTargetValue;
    record.m_uiTargetType = this->m_uiTargetType;
    switch (this->m_uiTargetType)
    {
    case 2:
        record.iFormID = this->GetTargetObjectType();
        break;
    case 0:
    case 1:
        if (this->pObject)
            record.iFormID = this->pObject->GetFormID();
        break;
    }
    if (FUN_00401500())
        ((ChunkPayload16*)&record)->FUN_0067ff10();
    AppendChunk(chunk, &record, 16);
    if (FUN_00401500())
        ((ChunkPayload16*)&record)->FUN_0067ff10();
}

struct FUN_00680520_cls : public PackageTargetRecord
{
    unsigned short FUN_00680520();
};

// @fnv 0x00680520
unsigned short FUN_00680520_cls::FUN_00680520()
{
    unsigned short usSize = 0;
    usSize += 1;
    usSize += 4;
    usSize += 4;
    switch (m_uiTargetType)
    {
    case 3:
        break;
    case 0:
    case 1:
        usSize += 4;
        break;
    case 2:
        usSize += 4;
        break;
    default:;
    }
    return usSize;
}

// Save-game write of a target record: type byte, two values, then the type-specific target.

class C80720Form;

class C80720SaveBuffer
{
  public:
    void SaveData(void* pvData, int iSize, int iFlags);
    void SerializeFormData(C80720Form* pkForm, int iFlags);
};

class C80720Target
{
  public:
    unsigned char m_ucType;
    union
    {
        C80720Form* m_pkForm;
        int m_iValue;
    };
    int m_iData1;
    int m_iData2;

    void SaveToBuffer(C80720SaveBuffer* pkBuffer);
};

// Writes the type byte, m_iData1 and m_iData2 to the buffer, then saves the form, value or nothing depending on m_ucType.
// @fnv 0x00680720
void C80720Target::SaveToBuffer(C80720SaveBuffer* pkBuffer)
{
    pkBuffer->SaveData(this, 1, 0);
    pkBuffer->SaveData(&m_iData1, 4, 0);
    pkBuffer->SaveData(&m_iData2, 4, 0);
    switch (m_ucType)
    {
        break;
    case 0:
    case 1:
        pkBuffer->SerializeFormData(m_pkForm, 0);
        break;
    case 2:
        pkBuffer->SaveData(&m_iValue, 4, 0);
        break;
    }
}

struct S_006807b0_Stream
{
    void FUN_00864980(void* data, unsigned int size);
    void FUN_008648e0(void* data);
};
struct S_006807b0_Target : PackageTargetRecord
{
    void FUN_006807b0(S_006807b0_Stream* s);
};
// @fnv 0x006807b0
void S_006807b0_Target::FUN_006807b0(S_006807b0_Stream* pStream)
{
    pStream->FUN_00864980(this, 1);
    pStream->FUN_00864980(&iValue, 4);
    pStream->FUN_00864980(&m_fTargetValue, 4);
    switch (m_uiTargetType)
    {
        break;
    case 0:
    case 1:
        pStream->FUN_008648e0(&pTargetForm);
        break;
    case 2:
        pStream->FUN_00864980(&pTargetForm, 4);
        break;
    }
}

struct FUN_00680830_shell : PackageTargetRecord
{
    void FUN_00680830(void* unused);
};

// @fnv 0x00680830
void FUN_00680830_shell::FUN_00680830(void* unused)
{
    switch (m_uiTargetType)
    {
    case PACK_TARG_TYPE_PTT_REFERENCE:
    case PACK_TARG_TYPE_PTT_OBJECT:
        pTargetForm = pTargetForm ? TESForm::GetFormByID((unsigned int)pTargetForm) : 0;
        break;
    }
}

struct C680590Form
{
    unsigned int Deallocate();
};

struct TESSaveLoadGame
{
    void FUN_008579b0(void* pvData, unsigned int uiSize);
    void FUN_00857a10(int iData, int iSize);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct C680590Target
{
    unsigned char m_ucType;
    union
    {
        C680590Form* m_pkForm;
        int m_iValue;
    };
    int m_iData1;
    int m_iData2;

    void SaveLoad();
};

// @fnv 0x00680590
void C680590Target::SaveLoad()
{
    g_TESSaveLoadGame->FUN_008579b0(&m_ucType, 1);
    g_TESSaveLoadGame->FUN_008579b0(&m_iData1, 4);
    g_TESSaveLoadGame->FUN_008579b0(&m_iData2, 4);

    switch (m_ucType)
    {
        break;
    case 0:
    case 1: {
        unsigned int uiResult = 0;
        if (m_pkForm)
        {
            uiResult = m_pkForm->Deallocate();
        }
        g_TESSaveLoadGame->FUN_00857a10((int)&uiResult, 4);
    }
    break;
    case 2:
        g_TESSaveLoadGame->FUN_008579b0(&m_iValue, 4);
        break;
    }
}

TESForm* LookupFormByID(unsigned int formID);

struct FUN_006806e0_target : PackageTargetRecord
{
    void ResolveTargetForm();
};

// For reference or object target types, replaces pTargetForm with the TESForm resolved from its formID via LookupFormByID.
// @fnv 0x006806e0
void FUN_006806e0_target::ResolveTargetForm()
{
    switch (m_uiTargetType)
    {
    case PACK_TARG_TYPE_PTT_REFERENCE:
    case PACK_TARG_TYPE_PTT_OBJECT:
        unsigned int formID = reinterpret_cast<unsigned int>(pTargetForm);
        pTargetForm = LookupFormByID(formID);
    }
}

struct SaveLoadStub
{
    void FUN_008579e0(void* data, int size);
    void FUN_00857aa0(void* data, int size);
};
extern SaveLoadStub* g_saveLoad_011de45c;
struct SaveDataStub
{
    unsigned char type;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00680640();
};
// @fnv 0x00680640
void SaveDataStub::FUN_00680640()
{
    g_saveLoad_011de45c->FUN_008579e0(this, 1);
    g_saveLoad_011de45c->FUN_008579e0(&unk08, 4);
    g_saveLoad_011de45c->FUN_008579e0(&unk0C, 4);
    switch (type)
    {
        break;
    case 0:
    case 1: {
        int value;
        g_saveLoad_011de45c->FUN_00857aa0(&value, 4);
        unk04 = value;
    }
    break;
    case 2:
        g_saveLoad_011de45c->FUN_008579e0(&unk04, 4);
        break;
    }
}
