// bgsimpactdataset.cpp: BGSImpactDataSet, SomeClass, ImpactDataSetCopy, BGSImpactDataSet_Cmp and more (25 functions)

#include "bgsimpactdataset_decls.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x0058e810
BGSImpactDataSet::BGSImpactDataSet()
{
    SetFormType((ENUM_FORM_ID)0x5f);
    ResetFormData();
}

// @fnv 0x0058eb10
void BGSImpactDataSet::ResetFormData()
{
    memset(m_apImpactData, 0, sizeof(m_apImpactData));
}

#include "bgsimpactdataset_TESFile.h"
#include <malloc.h>
void* __cdecl operator new(unsigned int);
class DataHandler
{
  public:
    bool DoAddForm(TESForm*);
};
extern DataHandler* g_dataHandler;
int __cdecl Warning(const char*, ...);
class TESModel : public BaseFormComponent
{
  public:
    unsigned int GetModelLength() const;
};
class BGSTextureSet
{
  public:
    void LoadTextures(int priority, QueuedFile* file, bool noCache);
};
class BGSImpactData : public TESForm, public TESModel
{
  public:
    BGSTextureSet* GetDecalTextureSet() const;
};
class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int priority, QueuedFile*, bool, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(float*, EndianSizeTag<4>);

// Looks up the form with ref ID 0x276; if missing, creates a BGSImpactDataSet, sets its ref ID and editor ID, and adds it to the data handler.
// @fnv 0x0058ea10
void BGSImpactDataSet::CacheImpactDataSet()
{
    ms_pImpactDataSet = dynamic_cast<BGSImpactDataSet*>(TESForm::GetFormByID(0x276));
    if (!ms_pImpactDataSet)
    {
        ms_pImpactDataSet = new BGSImpactDataSet;
        ms_pImpactDataSet->SetRefID(0x276, true);
        ms_pImpactDataSet->SetEditorID_AtRuntime("DefaultImpactDataSet");
        g_dataHandler->DoAddForm(ms_pImpactDataSet);
    }
}

// Validates the TESForm type is 0x5f, loads the record header, then reads EDID, OBND and DATA chunks until no chunk remains.
// @fnv 0x0058ec00
bool BGSImpactDataSet::Load(TESFile* file)
{
    if (file->GetTESForm() != 0x5f)
        return false;
    LoadRecordHeader(file);
    unsigned int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            file->GetChunkData(m_apImpactData, sizeof(m_apImpactData));
            if (file->GetChunkData())
            {
                for (int i = 0; i < 12; ++i)
                    BSEndian((float*)&m_apImpactData[i], EndianSizeTag<4>());
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0058edd0
void BGSImpactDataSet::InitItem()
{
    if (IsFormInitialized())
        return;
    for (int i = 0; i < 12; ++i)
    {
        unsigned int formID = (unsigned int)m_apImpactData[i];
        if (formID)
        {
            RemapFormIDForFile(formID, GetFile(-1));
            m_apImpactData[i] = dynamic_cast<BGSImpactData*>(GetFormByID(formID));
            if (m_apImpactData[i])
            {
            }
            else
                Warning("MASTERFILE: Unable to find impact data (%08X) on impact data set %s (%08X).", formID,
                        GetName(), GetFormID());
        }
    }
    SetInitializationState(true);
}

// @fnv 0x0058ef10
void BGSImpactDataSet::QueueResourceLoad(int priority, QueuedFile* pQueuedFile)
{
    for (int i = 0; i < 12; ++i)
    {
        BGSImpactData* data = GetImpactDataForMaterial(i);
        if (data)
        {
            if (data->GetModelLength())
                g_modelLoader->ProcessModelRequest(data, priority, pQueuedFile, true, true, false, false);
            BGSTextureSet* textureSet = data->GetDecalTextureSet();
            if (textureSet)
                textureSet->LoadTextures(priority, pQueuedFile, false);
        }
    }
}

// @fnv 0x0058e9d0
BGSImpactData* BGSImpactDataSet::GetImpactDataForMaterial(int material)
{
    if (DAT_011ca834)
        return DAT_011ca834->GetSwappedImpactData(material, m_apImpactData[material]);
    return m_apImpactData[material];
}

// Stores swap in DAT_011ca834, then for each of 10 indices passes the swap's alt footstep material name (or 0) to SetGlobalPointerAtOffset and calls FUN_00837500.
// @fnv 0x0058eeb0
void BGSImpactDataSet::RefreshImpactData(ImpactSwap* swap)
{
    DAT_011ca834 = swap;
    for (int i = 0; i < 10; ++i)
    {
        if (swap)
            SetGlobalPointerAtOffset(i, swap->GetAltFootstepMaterialName(i));
        else
            SetGlobalPointerAtOffset(i, 0);
    }
    FUN_00837500();
}

struct FUN_0040f2a0
{
    void FUN_0058f010();
    void* DeleteThis(unsigned int flags);
};
// Calls FUN_0058f010, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0040f2a0
void* FUN_0040f2a0::DeleteThis(unsigned int flags)
{
    FUN_0058f010();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0058e890
{
    void FUN_0058e8c0();
    void* DeleteThis(unsigned int flags);
};
// Calls the object's cleanup routine, frees the object when bit 0 of flags is set, and returns the object pointer.
// @fnv 0x0058e890
void* FUN_0058e890::DeleteThis(unsigned int flags)
{
    FUN_0058e8c0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Base5a
{
    virtual ~Base5a();
    char d[0x14];
};
struct Preload
{
    virtual void f();
};
struct FUN_0058e8c0 : Base5a, Preload
{
    ~FUN_0058e8c0();
};
// Destructor for the Preload-derived object; empty body, only the base destructors run.
// @fnv 0x0058e8c0
FUN_0058e8c0::~FUN_0058e8c0()
{}

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
void __cdecl FUN_00485710(unsigned int, unsigned int*, unsigned int);
struct FUN_0058ed50
{
    void Save();
};
// @fnv 0x0058ed50
void FUN_0058ed50::Save()
{
    int iIndex;
    unsigned int auiFormIDs[12];
    ((FUN_004855a0*)this)->M();
    for (iIndex = 0; iIndex < 12; iIndex++)
    {
        if (((TESForm**)((char*)this + 0x1c))[iIndex])
            auiFormIDs[iIndex] = ((TESForm**)((char*)this + 0x1c))[iIndex]->GetFormID();
        else
            auiFormIDs[iIndex] = 0;
    }
    FUN_00485710(0x41544144, auiFormIDs, 12);
    ((FUN_00485680*)this)->M();
}

struct FUN_0058efd0
{
    char a[0x30];
    char b[0x12c];
    FUN_0058efd0();
};
// Zero-initializes the two embedded buffers a and b of the object.
// @fnv 0x0058efd0
FUN_0058efd0::FUN_0058efd0()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
}

struct FUN_0058f010_Item
{
    virtual ~FUN_0058f010_Item();
};
// Deletes each of the 12 item pointers in the array and sets them to null.
// @fnv 0x0058f010
void __fastcall FUN_0058f010(FUN_0058f010_Item** apItems)
{
    for (int i = 0; i < 12; i++)
    {
        delete apItems[i];
        apItems[i] = 0;
    }
}

struct ContainerItemExtraFileData
{
    void Endian();
};
struct ImpactDataSwapExtraData : ContainerItemExtraFileData
{
    unsigned int type;
    BGSImpactData* orig;
    BGSImpactData* repl;
};
struct MapX
{
    void* GetFirstPos();
    void GetNext(void*&, BGSImpactData*&, BGSImpactData*&);
};
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_0058f080
{
    MapX* m_pData[12];
    void Save();
};
// @fnv 0x0058f080
void FUN_0058f080::Save()
{
    void* cur;
    int i;
    ImpactDataSwapExtraData data;
    for (i = 0; i < 12; i++)
    {
        if (m_pData[i])
        {
            cur = m_pData[i]->GetFirstPos();
            while (cur)
            {
                data.type = i;
                m_pData[i]->GetNext(cur, data.orig, data.repl);
                if (data.orig)
                    data.orig = (BGSImpactData*)data.orig->GetFormID();
                if (data.repl)
                    data.repl = (BGSImpactData*)data.repl->GetFormID();
                if (FUN_00401500())
                    data.Endian();
                AppendChunk(0x53504d49, &data, 12);
                if (FUN_00401500())
                    data.Endian();
            }
        }
    }
    FUN_004856f0(0x46504d49, (char*)this + 0x30, 300);
}

namespace fnv_0058f180 {
struct ContainerItemExtraFileData
{
    void Endian();
};
struct ImpactDataSwapExtraData : ContainerItemExtraFileData
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct FUN_0058f740
{
    void Add(unsigned int, unsigned int, unsigned int);
};
struct FUN_0058f180
{
    void Load(TESFile* apFile);
};
// Reads an IMPS chunk into a ContainerItemExtraFileData, byte-swaps it, and adds its three values; an IMPF chunk is read directly into the object at offset 0x30.
// @fnv 0x0058f180
void FUN_0058f180::Load(TESFile* apFile)
{
    ImpactDataSwapExtraData data;
    switch (apFile->GetChunkID())
    {
    case 0x53504d49:
        memset(&data, 0, 12);
        apFile->GetChunkData(&data, 12);
        if (apFile->GetChunkData())
            data.Endian();
        ((FUN_0058f740*)this)->Add(data.a, data.b, data.c);
        break;
    case 0x46504d49:
        apFile->GetChunkData((char*)this + 0x30, 300);
        break;
    }
}
}  // namespace fnv_0058f180

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FUN_0058f6f0
{
    DummyPointerMap* m[1];
    unsigned int Get(unsigned int idx, unsigned int def);
};
// Looks up idx in the pointer map and returns the stored value for def, or def itself when the slot is null.
// @fnv 0x0058f6f0
unsigned int FUN_0058f6f0::Get(unsigned int auiIndex, unsigned int auiDefault)
{
    unsigned int result = 0;
    if (m[auiIndex])
        m[auiIndex]->GetAt(auiDefault, result);
    else
        result = auiDefault;
    return result;
}

struct FUN_0058f820
{
    int m0, m1, m2, m3;
    FUN_0058f820(int);
    void SetAt(BGSImpactData*, BGSImpactData*);
};
struct FUN_0058f740
{
    FUN_0058f820* m_pData[12];
    void Add(unsigned int aeType, BGSImpactData* apOrig, BGSImpactData* apNew);
};
// If apOrig differs from apNew, lazily creates the slot for aeType and records the replacement via SetAt.
// @fnv 0x0058f740
void FUN_0058f740::Add(unsigned int aeType, BGSImpactData* apOrig, BGSImpactData* apNew)
{
    if (apOrig != apNew)
    {
        if (!m_pData[aeType])
            m_pData[aeType] = new FUN_0058f820(0x25);
        m_pData[aeType]->SetAt(apOrig, apNew);
    }
}

struct ShadowLightData
{
    static void SetTargetMaskForSelection(unsigned int, unsigned __int64);
};
struct FUN_006233c0
{
    void GetImpactDataForMaterial(int aeType);
};
// @fnv 0x006233c0
void FUN_006233c0::GetImpactDataForMaterial(int aeType)
{
    switch (aeType)
    {
    case 0: {
        unsigned __int64 a = 0x26636;
        ShadowLightData::SetTargetMaskForSelection(0x27, a);
        break;
    }
    case 1: {
        unsigned __int64 b = 0x20000100;
        ShadowLightData::SetTargetMaskForSelection(0x27, b);
        break;
    }
    }
}

struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};

int __cdecl _memcmp(const void*, const void*, unsigned int);

struct FUN_0058f5c0_shell
{
    bool IsImpactSwapDifferent(ImpactSwap* apSwap);
};

// Compares 12 map entries and their impact data against apSwap, returning true if any entry, form ID, mapped data or trailing 0x12c bytes differ.
// @fnv 0x0058f5c0
bool FUN_0058f5c0_shell::IsImpactSwapDifferent(ImpactSwap* apSwap)
{
    int i;

    if (!apSwap)
        return true;

    for (i = 0; i < 12; ++i)
    {
        if (reinterpret_cast<MapX**>(this)[i] && reinterpret_cast<MapX**>(apSwap)[i])
        {
            void* iter;

            if (reinterpret_cast<TESForm*>(reinterpret_cast<MapX**>(this)[i])->GetFormID() !=
                reinterpret_cast<TESForm*>(reinterpret_cast<MapX**>(apSwap)[i])->GetFormID())
                return true;

            iter = reinterpret_cast<MapX**>(this)[i]->GetFirstPos();
            while (iter)
            {
                BGSImpactData* pnewdata;
                {
                    BGSImpactData* polddata;

                    pnewdata = 0;
                    polddata = 0;
                    reinterpret_cast<NiTMap*>(reinterpret_cast<MapX**>(this)[i])
                        ->GetNext(iter, reinterpret_cast<unsigned int&>(pnewdata), reinterpret_cast<void*&>(polddata));

                    if (apSwap->GetSwappedImpactData(i, pnewdata) != polddata)
                        return true;
                }
            }
        }
        else if (reinterpret_cast<MapX**>(this)[i] || reinterpret_cast<MapX**>(apSwap)[i])
        {
            return true;
        }
    }

    if (_memcmp(reinterpret_cast<const void*>(reinterpret_cast<const char*>(this) + 0x30),
                reinterpret_cast<const void*>(reinterpret_cast<const char*>(apSwap) + 0x30), 0x12c) != 0)
        return true;

    return false;
}

void __cdecl operator delete(void*);

struct RefObj
{
    unsigned int _ref_0084e3a0();
};

struct ImpactMap
{
    virtual ~ImpactMap();
};

struct SomeClass
{
    FUN_0058f820* m_pData[12];
    void RemapImpactData(TESForm* apForm);
};

struct Entry
{
    unsigned int unk00;
    BGSImpactData* oldImpact;
    BGSImpactData* newImpact;
};

void __cdecl ResolveFormID(unsigned int*, TESFile*);
TESForm* __cdecl LookupFormByID(unsigned int);

// For each of the 12 maps, collects old/new impact pairs, resolves their form IDs against apForm's file, warns on missing impacts, and reinserts them.
// @fnv 0x0058f210
void SomeClass::RemapImpactData(TESForm* apForm)
{
    int i6;
    void* posVal;
    Entry* entries3;
    unsigned int j_;
    unsigned int count4;
    BGSImpactData* oldImpact6;
    BGSImpactData* newImpact;
    unsigned int oldFormID;
    unsigned int newFormID4;

    for (i6 = 0; i6 < 12; i6++)
    {
        if (m_pData[i6])
        {
            j_ = 0;
            count4 = ((RefObj*)m_pData[i6])->_ref_0084e3a0();
            entries3 = new Entry[count4];
            posVal = ((MapX*)m_pData[i6])->GetFirstPos();
            while (posVal)
            {
                ((MapX*)m_pData[i6])->GetNext(posVal, entries3[j_].oldImpact, entries3[j_].newImpact);
                j_++;
            }
            ((NiTPointerMap<unsigned int, unsigned int>*)m_pData[i6])->RemoveAll();

            for (j_ = 0; j_ < count4; j_++)
            {
                oldImpact6 = 0;
                if (entries3[j_].oldImpact)
                {
                    oldFormID = (unsigned int)entries3[j_].oldImpact;
                    ResolveFormID(&oldFormID, apForm->GetFile(-1));
                    oldImpact6 = dynamic_cast<BGSImpactData*>(LookupFormByID(oldFormID));
                    if (!oldImpact6)
                    {
                        Warning("Could not find old ImpactData (%08X) for ImpactSwap on '%s' (%08X).", oldFormID,
                                apForm->GetName(), apForm->GetFormID());
                    }
                }

                newImpact = 0;
                if (entries3[j_].newImpact)
                {
                    newFormID4 = (unsigned int)entries3[j_].newImpact;
                    ResolveFormID(&newFormID4, apForm->GetFile(-1));
                    newImpact = dynamic_cast<BGSImpactData*>(LookupFormByID(newFormID4));
                    if (!newImpact)
                    {
                        Warning("Could not find new ImpactData (%08X) for ImpactSwap on '%s' (%08X).", newFormID4,
                                apForm->GetName(), apForm->GetFormID());
                    }
                }

                if (oldImpact6 || newImpact)
                {
                    m_pData[i6]->SetAt(oldImpact6, newImpact);
                }
            }

            delete[] entries3;

            if (((RefObj*)m_pData[i6])->_ref_0084e3a0() == 0)
            {
                delete ((ImpactMap*)m_pData[i6]);
                m_pData[i6] = 0;
            }
        }
    }
}

// Maps selected integer values to integers 0–9; returns 4 for all other values.
// @fnv 0x0058e8f0
int FUN_0058e8f0(int value)
{
    int result = 4;
    switch (value)
    {
    case 0:
    case 10:
    case 19:
        result = 0;
        break;
    case 2:
    case 18:
        result = 1;
        break;
    case 4:
        result = 2;
        break;
    case 3:
    case 24:
        result = 3;
        break;
    case 5:
    case 11:
    case 13:
    case 14:
    case 15:
    case 20:
    case 21:
    case 26:
    case 27:
        result = 4;
        break;
    case 16:
    case 17:
    case 22:
    case 23:
    case 25:
    case 28:
    case 29:
        result = 9;
        break;
    case 9:
    case 12:
    case 30:
    case 31:
        result = 5;
        break;
    case 6:
    case 7:
        result = 6;
        break;
    case 8:
        result = 8;
        break;
    case 1:
        result = 7;
        break;
    }
    return result;
}

#include <string.h>
struct S004851b0
{
    void FUN_004851b0(TESForm*);
};
struct ImpactDataSetCopy : BGSImpactDataSet
{
    void FUN_0058eb30(TESForm* apCopy);
};
// Copies impact data from apCopy into this ImpactDataSetCopy after casting it to BGSImpactDataSet.
// @fnv 0x0058eb30
void ImpactDataSetCopy::FUN_0058eb30(TESForm* apCopy)
{
    BGSImpactDataSet* pSource = dynamic_cast<BGSImpactDataSet*>(apCopy);
    if (!pSource)
        return;
    reinterpret_cast<S004851b0*>(this)->FUN_004851b0(pSource);
    memcpy(m_apImpactData, pSource->m_apImpactData, sizeof(m_apImpactData));
}

struct BGSImpactDataSet_Cmp
{
    bool FUN_0058eb90(TESForm* apCompare);
};
// Returns true if apCompare is not a BGSImpactDataSet, TESForm::Compare returns true, or the impact-data arrays differ.
// @fnv 0x0058eb90
bool BGSImpactDataSet_Cmp::FUN_0058eb90(TESForm* apCompare)
{
    BGSImpactDataSet* pcomp = dynamic_cast<BGSImpactDataSet*>(apCompare);
    if (!pcomp)
        return true;
    if (((TESForm*)this)->TESForm::Compare(pcomp))
        return true;
    if (memcmp(((BGSImpactDataSet*)this)->m_apImpactData, pcomp->m_apImpactData, sizeof(pcomp->m_apImpactData)))
        return true;
    return false;
}

extern "C" void* __cdecl memcpy(void*, const void*, size_t);
struct ImpactSwapMaps
{
    MapX* m_pData[12];
    void FUN_0058f4c0(ImpactSwapMaps* apSwap);
};
// Deletes this object's 12 map entries, adds entries from apSwap's maps, then copies 300 bytes from offset 0x30.
// @fnv 0x0058f4c0
void ImpactSwapMaps::FUN_0058f4c0(ImpactSwapMaps* apSwap)
{
    for (int i = 0; i < 12; i++)
    {
        delete (ImpactMap*)m_pData[i];
        m_pData[i] = 0;
    }
    for (int i = 0; i < 12; i++)
    {
        if (apSwap->m_pData[i])
        {
            void* iter = apSwap->m_pData[i]->GetFirstPos();
            while (iter)
            {
                BGSImpactData* pnewdata;
                BGSImpactData* polddata = 0;
                pnewdata = 0;
                apSwap->m_pData[i]->GetNext(iter, polddata, pnewdata);
                ((FUN_0058f740*)this)->Add(i, polddata, pnewdata);
            }
        }
    }
    memcpy((char*)this + 0x30, (char*)apSwap + 0x30, 300);
}
