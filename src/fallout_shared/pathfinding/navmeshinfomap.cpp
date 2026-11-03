// fallout_shared/pathfinding/navmeshinfomap.cpp: NavMeshInfoMap, WorkerNavMap, std, NavMeshInfo and more (26 functions)

#include "navmeshinfomap_decls.h"

// Scans every outer/inner map entry and returns false if any NavMeshInfoArray with more than one element has fewer than size-1 entries with bounds.
// @fnv 0x006b7cb0
bool NavMeshInfoMap::ValidateNavMeshInfoArrays()
{
    bool bResult = true;
    void* pOuterPos = m_kNavMeshInfoArraysByWorldspace.GetFirstPos();
    while (pOuterPos)
    {
        OuterPair outer;
        m_kNavMeshInfoArraysByWorldspace.GetNext(pOuterPos, outer.uiOuterKey, outer.pInnerMapRaw);
        void* pInnerPos = ((CellKeyMap*)outer.pInnerMapRaw)->GetFirstPos();
        while (pInnerPos)
        {
            unsigned int uiInnerKey;
            void* pArrayRaw;
            ((CellKeyMap*)outer.pInnerMapRaw)->GetNext(pInnerPos, uiInnerKey, pArrayRaw);
            if (((NavMeshInfoArray*)pArrayRaw)->GetSize() > 1)
            {
                InnerCounts counts;
                counts.uiValid = 0;
                for (counts.uiIndex = 0; counts.uiIndex < ((NavMeshInfoArray*)pArrayRaw)->GetSize(); counts.uiIndex++)
                {
                    if (((NavMeshInfoArray*)pArrayRaw)->GetAt((int)counts.uiIndex)->GetBounds())
                        counts.uiValid++;
                }
                if (counts.uiValid < ((NavMeshInfoArray*)pArrayRaw)->GetSize() - 1)
                    bResult = false;
            }
        }
    }
    return bResult;
}

namespace std {
float abs(float value);
}
int Warning(const char* format, ...);

struct NavMeshValidation
{
    unsigned int id;
    void* info;
    TESForm* parent;
};

// Validates each NavMeshInfo entry, warns and deletes entries with missing parent space or bad approx location, otherwise links parent and initializes it.
// @fnv 0x006b63c0
void NavMeshInfoMap::InitItem()
{
    void* pPos;
    {
        NavMeshInfoArray DeleteArray;
        pPos = m_kNavMeshInfosByFormID.GetFirstPos();
        while (pPos)
        {
            bool bDelete;
            {
                NavMeshValidation entry;
                m_kNavMeshInfosByFormID.GetNext(pPos, entry.id, entry.info);
                bDelete = false;
                entry.parent = TESForm::GetFormByID(((NavMeshInfo*)entry.info)->m_uiParentSpaceID);
                if (!entry.parent)
                {
                    Warning("MASTERFILE: Could not find Parent Space with ID %08x for NavmeshInfo %08x",
                            ((NavMeshInfo*)entry.info)->m_uiParentSpaceID, entry.id);
                    bDelete = true;
                }
                if (std::abs(((NavMeshInfo*)entry.info)->approxZ) > 1.0e14f)
                {
                    Warning("MASTERFILE: NavmeshInfo %08x has bad approx location, ignoring", entry.id);
                    bDelete = true;
                }
                if (bDelete)
                {
                    DeleteArray.Add((NavMeshInfo*&)entry.info);
                }
                else
                {
                    ((NavMeshInfo*)entry.info)->m_pParentSpace = entry.parent;
                    InsertNavMeshInfo((NavMeshInfo*)entry.info);
                }
                if (!m_bKeepNavMeshLoaded)
                    ((NavMeshInfo*)entry.info)->ReleaseNavMesh();
            }
        }
        for (unsigned int uiIndex = 0; uiIndex < DeleteArray.GetSize(); uiIndex++)
        {
            m_kNavMeshInfosByFormID.RemoveAt(DeleteArray[uiIndex]->GetNavMeshID());
            delete DeleteArray[uiIndex];
        }
        m_bKeepNavMeshLoaded = true;
        ValidateNavMeshInfoArrays();
    }
}

// Registers info in the per-parent NavMeshInfoArray for its cell key, creating the inner map and array as needed, and skips if already present.
// @fnv 0x006b7980
void NavMeshInfoMap::InsertNavMeshInfo(NavMeshInfo* info)
{
    struct CellKeyLookup
    {
        void* innerMap;
        unsigned int parentID;
        unsigned int cellKey;
    } lookup;
    lookup.cellKey = FUN_006b7b30(info);
    if (info->GetInteriorCell())
        lookup.parentID = 0;
    else
        lookup.parentID = info->m_uiParentSpaceID;
    if (!m_kNavMeshInfoArraysByWorldspace.GetAt(lookup.parentID, lookup.innerMap))
    {
        unsigned int hashSize = 103;
        if (!lookup.parentID)
        {
            hashSize = 1009;
        }
        else
        {
            TESWorldSpace* world = (TESWorldSpace*)TESForm::GetFormByID(lookup.parentID);
            if (world && !world->GetSmallWorld())
                hashSize = 1009;
        }
        lookup.innerMap = new NiTPointerMap<unsigned int, NavMeshInfoArray*>(hashSize);
        m_kNavMeshInfoArraysByWorldspace.SetAt(lookup.parentID, lookup.innerMap);
    }
    NavMeshInfoArray* array;
    if (!((NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap)->GetAt(lookup.cellKey, array))
    {
        array = new NavMeshInfoArray;
        ((NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap)->SetAt(lookup.cellKey, array);
    }
    if (array->Find(info, 0, FUN_009a3830) != (unsigned int)-1)
        return;
    array->Add(info);
}

// @fnv 0x006b46a0
NavMeshInfo::NavMeshInfo()
{
    uiFlags = 0;
    m_uiNavMeshID = 0;
    m_uiParentSpaceID = 0;
    m_pParentSpace = 0;
    m_uiPathingFlags = 0xdeaddead;
    m_kNavMeshPosition = NiPoint3::ZERO;
    pBounds = 0;
    m_pLocationNavMesh = 0;
    m_fStoredValue = 0.0f;
}

// @fnv 0x006b5c30
NavMeshInfoMap::NavMeshInfoMap()
    : m_bNavMeshInfoArraysValid(false), m_kNavMeshInfosByFormID(10009), m_kNavMeshInfoArraysByWorldspace(103),
      m_bKeepNavMeshLoaded(false)
{
    SetFormType(ENUM_FORM_ID_NAVMESHINFOMAP);
}

extern int DAT_01031fac;

struct FUN_006b7d90_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006b7d90_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7d90
int* __fastcall FUN_006b7d90(int* self, FUN_006b7d90_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}

namespace fnv_006b7dc0 {
extern int DAT_01031fac;

struct FUN_006b7dc0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006b7dc0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7dc0
int* __fastcall FUN_006b7dc0(int* self, FUN_006b7dc0_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_006b7dc0

namespace fnv_006b7df0 {
extern int DAT_01031fac;

struct FUN_006b7df0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006b7df0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7df0
int* __fastcall FUN_006b7df0(int* self, FUN_006b7df0_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_006b7df0

struct FUN_006b5d80_shell : public NavMeshInfoMap
{
    bool LoadNavMeshInfoMap(TESFile*);
};

extern "C" void* __cdecl _alloca(unsigned int);
struct NavMeshVertexMap
{
    void* GetFirstPos();
};
struct DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
    bool GetAt(unsigned int, unsigned int&) const;
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct Pathing
{
    NavMeshInfo* FindReferenceByFormId(unsigned int);
};
struct TESRecipe
{
    void SetCategory(unsigned int);
};

// @fnv 0x006b5d80
bool FUN_006b5d80_shell::LoadNavMeshInfoMap(TESFile* apFile)
{
    int ifileVersionNumber;
    AutoMemContext tempMemContext(
        (MEM_CONTEXT)0x2e, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshInfoMap.cpp", 0x5c);
    if (*(bool*)((char*)this + 0x3c))
    {
        void* it = ((NavMeshVertexMap*)((char*)this + 0x1c))->GetFirstPos();
        while (it)
        {
            unsigned int navmeshID;
            NavMeshInfo* pinfo;
            ((NiTPointerMap<unsigned int, void*>*)((char*)this + 0x1c))->GetNext(it, navmeshID, (void*&)pinfo);
            for (unsigned int i = 0; i < ((ArrSI*)&pinfo->doors)->GetFlags(); i++)
                *((Arr*)&pinfo->doors)->GetAt(i) = (*(TESForm**)((Arr*)&pinfo->doors)->GetAt(i))->GetFormID();
        }
        *(bool*)((char*)this + 0x3c) = false;
    }
    int ibuffersize = 0x9b0;
    void* pchunkdata = MemoryManager::Allocate(ibuffersize);
    unsigned char formid = apFile->GetTESForm();
    if (formid != 0x38)
        return false;
    unsigned int thisID = ((TESForm*)this)->GetFormID();
    ((TESForm*)this)->LoadRecordHeader(apFile);
    ifileVersionNumber = 1;
    do
    {
        switch ((int)apFile->GetChunkID())
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            ((TESForm*)this)->SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 0x444e424f:
            ((TESForm*)this)->readOBNDSubRecord(apFile);
            break;
        case 0x5245564e:
            apFile->GetChunkData(&ifileVersionNumber, 0);
            if (apFile->IsEndianConversionRequired())
                BSEndian(&ifileVersionNumber, EndianSizeTag<4>());
            if (ifileVersionNumber < 5)
                *(bool*)((char*)this + 0x18) = true;
            break;
        case 0x494d564e: {
            int ichunksize = apFile->GetChunkSize();
            if (ichunksize > ibuffersize)
            {
                FNV_DeleteBuffer(pchunkdata);
                ibuffersize = ichunksize;
                pchunkdata = MemoryManager::Allocate(ibuffersize);
            }
            apFile->GetChunkData(pchunkdata, ichunksize);
            NavMeshInfo* pnewInfo = new NavMeshInfo;
            pnewInfo->LoadNavMeshInfo((char*)pchunkdata, apFile, ifileVersionNumber);
            NavMeshInfo* poldInfo = ((Pathing*)this)->FindReferenceByFormId(pnewInfo->GetNavMeshID());
            if (poldInfo)
            {
                NavMeshPtr sppreviousNavMesh;
                bool bhasNavMesh = poldInfo->AcquireNavMesh(sppreviousNavMesh);
                BSSimpleArray<NavMeshInfo*, 1024> oldadjacentNavMeshes;
                BSSimpleArray<NavMeshInfo*, 1024> oldpreferredAdjacentNavMeshes;
                BSSimpleArray<TESObjectREFR*, 1024> oldconnectedDoors;
                poldInfo->adjacent.CopyTo(&oldadjacentNavMeshes);
                poldInfo->preferred.CopyTo(&oldpreferredAdjacentNavMeshes);
                poldInfo->doors.CopyTo(&oldconnectedDoors);
                pnewInfo->CopyTo(poldInfo);
                if (bhasNavMesh)
                    ((TESRecipe*)poldInfo)->SetCategory(((NavMeshInfo*)&sppreviousNavMesh)->GetNavMeshID());
                oldadjacentNavMeshes.CopyTo(&poldInfo->adjacent);
                oldpreferredAdjacentNavMeshes.CopyTo(&poldInfo->preferred);
                oldconnectedDoors.CopyTo(&poldInfo->doors);
                delete pnewInfo;
            }
            else
            {
                ((DummyPointerMap*)((char*)this + 0x1c))->SetAt(pnewInfo->GetNavMeshID(), (unsigned int)pnewInfo);
            }
            break;
        }
        case 0x4943564e: {
            int ichunksize = apFile->GetChunkSize();
            if (ichunksize > ibuffersize)
            {
                FNV_DeleteBuffer(pchunkdata);
                ibuffersize = ichunksize;
                pchunkdata = MemoryManager::Allocate(ibuffersize);
            }
            apFile->GetChunkData(pchunkdata, ichunksize);
            char* pchunkPointer = (char*)pchunkdata;
            unsigned int infoID = *(unsigned int*)pchunkPointer;
            if (apFile->IsEndianConversionRequired())
                BSEndian(&infoID, EndianSizeTag<4>());
            TESForm::RemapFormIDForFile(infoID, apFile);
            pchunkPointer += 4;
            NavMeshInfo* pinfo;
            if (!((DummyPointerMap*)((char*)this + 0x1c))->GetAt(infoID, (unsigned int&)pinfo))
                return false;
            if (ifileVersionNumber >= 5)
                pinfo->LoadSerializedData(pchunkPointer, apFile, ifileVersionNumber);
            break;
        }
        }
    } while (apFile->NextChunk());
    FNV_DeleteBuffer(pchunkdata);
    return true;
}

struct NavMeshInfoMapShell
{
    void* __thiscall FUN_006b5d00();
    void* __thiscall FUN_006b5cd0(unsigned int flags);
};

// @fnv 0x006b5cd0
void* __thiscall NavMeshInfoMapShell::FUN_006b5cd0(unsigned int flags)
{
    FUN_006b5d00();
    if (flags & 1)
        FNV_DeleteBuffer(this);
    return this;
}

struct MapX
{
    void* GetFirstPos();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct TESFormCall
{
    void SetAltered(bool);
    void Revert(unsigned int);
};
struct FUN_006b68b0_shell
{
    void SetAlteredAndRevertNavMeshes(bool abVal);
};
// Calls SetAltered with abVal; when abVal is false, iterates the map at offset 0x1c and reverts each NavMeshInfo.
// @fnv 0x006b68b0
void FUN_006b68b0_shell::SetAlteredAndRevertNavMeshes(bool abVal)
{
    ((TESFormCall*)this)->SetAltered(abVal);
    if (!abVal)
    {
        void* it;
        unsigned int navmeshID;
        NavMeshInfo* pinfo;
        it = ((MapX*)((char*)this + 0x1c))->GetFirstPos();
        while (it)
        {
            ((NiTMap*)((char*)this + 0x1c))->GetNext(it, navmeshID, (void*&)pinfo);
            ((TESFormCall*)pinfo)->TESFormCall::Revert(0);
        }
    }
}

int __fastcall _FNV_GetFormType(TESForm* apForm);
struct FUN_00484020_shell
{
    bool IsLessThan(TESForm* apForm);
};
struct FUN_006b6910_shell
{
    bool FUN_006b6910(TESForm* apForm);
};
// Returns true if apForm's form type is 0x43, otherwise delegates to IsLessThan.
// @fnv 0x006b6910
bool FUN_006b6910_shell::FUN_006b6910(TESForm* apForm)
{
    if (_FNV_GetFormType(apForm) == 0x43)
        return true;
    return ((FUN_00484020_shell*)this)->IsLessThan(apForm);
}

namespace fnv_006b7850 {
struct FUN_006b7850_shell : public NavMeshInfoMap
{
    void* FUN_006b7850(TESWorldSpace*, int);
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
unsigned int PrepareScriptMessage(int);
// Looks up the worldspace's map by form ID, then the cell's entry by prepared key, returning the stored info pointer or null.
// @fnv 0x006b7850
void* FUN_006b7850_shell::FUN_006b7850(TESWorldSpace* apWorldSpace, int aiCellKey)
{
    DummyPointerMap* worldspaceMap;
    void* infoarray;
    if (!reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x2C)
             ->GetAt(reinterpret_cast<TESForm*>(apWorldSpace)->GetFormID(),
                     reinterpret_cast<unsigned int&>(worldspaceMap)))
        return 0;
    if (!worldspaceMap->GetAt(PrepareScriptMessage(aiCellKey), reinterpret_cast<unsigned int&>(infoarray)))
        return 0;
    return infoarray;
}
}  // namespace fnv_006b7850

namespace fnv_006b7910 {
struct MapX
{
    void* GetFirstPos();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct HArr
{
    void GrowCapacity(unsigned int);
};
struct FUN_006b7910_shell
{
    void FUN_006b7910(BSSimpleArray<void*, 1024>* arr);
};
// @fnv 0x006b7910
void FUN_006b7910_shell::FUN_006b7910(BSSimpleArray<void*, 1024>* pArray)
{
    ((_Mem_20a4*)pArray)->SetSize(0, false);
    ((HArr*)pArray)->GrowCapacity(0x800);
    void* it = ((MapX*)((char*)this + 0x1c))->GetFirstPos();
    while (it)
    {
        void* pinfo;
        unsigned int navmeshID;
        ((NiTMap*)((char*)this + 0x1c))->GetNext(it, navmeshID, pinfo);
        pArray->Add(pinfo);
    }
}
}  // namespace fnv_006b7910

namespace fnv_006b78b0 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
const char* __cdecl PrepareScriptMessage(const char*);
struct Holder
{
    char _pad[0x2c];
    DummyPointerMap m;
    unsigned int LookupScriptMessageValue(const char*);
};
// Looks up two map entries: one at key 0, then one keyed by PrepareScriptMessage(s), returning the second value or 0 if either lookup fails.
// @fnv 0x006b78b0
unsigned int Holder::LookupScriptMessageValue(const char* pcScriptMessage)
{
    unsigned int uiValue;
    {
        unsigned int uiMapPtr;
        if (!m.GetAt(0, uiMapPtr))
            return 0;
        if (!((DummyPointerMap*)uiMapPtr)->GetAt((unsigned int)PrepareScriptMessage(pcScriptMessage), uiValue))
            return 0;
        return uiValue;
    }
}
}  // namespace fnv_006b78b0

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_006b7fd0_class
{
    FUN_006b7fd0_class();
    ~FUN_006b7fd0_class();
};
struct FUN_006b80d0_Class
{
    FUN_006b80d0_Class();
    ~FUN_006b80d0_Class();
};
struct FUN_006b5d00 : Base5a
{
    char _004[0x18];
    FUN_006b7fd0_class _01c;
    char _024[0xf];
    FUN_006b80d0_Class _02c;
    virtual ~FUN_006b5d00();
    void ClearNavMeshInfoMaps();
};
// Destructor that calls ClearNavMeshInfoMaps before the object is torn down.
// @fnv 0x006b5d00
FUN_006b5d00::~FUN_006b5d00()
{
    ClearNavMeshInfoMaps();
}

namespace fnv_006b77e0 {
struct TESObjectCELL
{
    bool IsInterior();
};
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct DoorH
{
    void* GetParentWorldSpace();
};
int __cdecl BuildCellKey(short, short);
struct FUN_006b77e0_shell
{
    int FUN_006b7850(void*, int);
    int LookupScriptMessageValue(TESObjectCELL*);
    int FUN_006b77e0(TESObjectCELL*);
};
// @fnv 0x006b77e0
int FUN_006b77e0_shell::FUN_006b77e0(TESObjectCELL* cell)
{
    if (!cell)
        return 0;
    if (cell->IsInterior())
        return LookupScriptMessageValue(cell);
    else
        return FUN_006b7850(((DoorH*)cell)->GetParentWorldSpace(),
                            BuildCellKey((short)((CellH*)cell)->GetCellGridX(), (short)((CellH*)cell)->GetCellGridY()));
}
}  // namespace fnv_006b77e0

struct TESWorldSpaceStandIn : public TESWorldSpace
{
    TESObjectCELL* GetCellByKey(unsigned int key);
};

struct NavMeshInfoStandIn : public NavMeshInfo
{
    TESWorldSpace* GetParentWorldSpace();
    TESObjectCELL* FUN_006b7770();
};

// @fnv 0x006b7770
TESObjectCELL* NavMeshInfoStandIn::FUN_006b7770()
{
    TESWorldSpace* worldSpace = GetParentWorldSpace();
    if (worldSpace)
    {
        return static_cast<TESWorldSpaceStandIn*>(worldSpace)
            ->GetCellByKey(static_cast<unsigned int>(m_uiPathingFlags));
    }
    else
    {
        return reinterpret_cast<NavMeshInfo*>(this)->GetInteriorCell();
    }
}

struct FormView
{
    unsigned int FUN_00401170();
};
struct FormArray
{
    unsigned int FUN_0084e3a0();
    FormView** FUN_00877a30(unsigned int);
};
extern FormArray* DAT_011c54c4;
struct InfoView
{
    bool FUN_0047c850();
};
class NavMesh
{
  public:
    bool FUN_00460340();
    bool FUN_00440d80();
    void FUN_006986d0();
};
struct PtrView
{
    NavMesh* FUN_00559450();
};
struct VirtualView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50(int);
};
struct WorkerNavMap : NavMeshInfoMap
{
    bool FUN_00460340();
    void ValidateNavMeshes();
    bool FUN_006b6580();
};
// @fnv 0x006b6580
bool WorkerNavMap::FUN_006b6580()
{
    if (!FUN_00460340())
        return true;
    FormView* formTmp;
    unsigned int i5;
    unsigned int total4 = DAT_011c54c4->FUN_0084e3a0();
    unsigned int count4 = 0;
    for (i5 = 0; i5 < total4; i5++)
    {
        formTmp = *DAT_011c54c4->FUN_00877a30(i5);
        if (formTmp->FUN_00401170() == 0x43)
            count4++;
    }
    if (count4 == 0)
    {
        bool found6 = false;
        void* pos4 = m_kNavMeshInfosByFormID.GetFirstPos();
        while (pos4)
        {
            unsigned int keyTmp;
            void* value5;
            m_kNavMeshInfosByFormID.GetNext(pos4, keyTmp, value5);
            if (((InfoView*)value5)->FUN_0047c850())
            {
                found6 = true;
                break;
            }
        }
        if (!found6)
        {
            ((VirtualView*)this)->f50(0);
            return true;
        }
    }
    void* position = m_kNavMeshInfosByFormID.GetFirstPos();
    while (position)
    {
        unsigned int key3;
        void* valueVal;
        m_kNavMeshInfosByFormID.GetNext(position, key3, valueVal);
        NavMeshPtr mesh8;
        if (((NavMeshInfo*)valueVal)->AcquireNavMesh(mesh8) && ((PtrView*)&mesh8)->FUN_00559450()->FUN_00460340() &&
            !((PtrView*)&mesh8)->FUN_00559450()->FUN_00440d80())
            ((PtrView*)&mesh8)->FUN_00559450()->FUN_006986d0();
    }
    ValidateNavMeshes();
    return true;
}

struct NavigationRequest
{
    int stored;
    bool FUN_00690860(void* output);
    int FUN_006b6390(bool enable);
};
struct BoundNavigationMap
{
    bool GetAt(int entry, NavigationRequest** request);
    void RemoveKey(int entry);
};
struct ScopedNavPointer
{
    void* current;
    void FUN_0042fb00();
    void FUN_0042fa40();
    void* FUN_00559450(int index);
    ScopedNavPointer()
    {
        FUN_0042fb00();
    }
    ~ScopedNavPointer()
    {
        FUN_0042fa40();
    }
};
struct ActiveResolver
{
    void* FUN_00484e60();
};
struct VerifiedPath
{
    bool FUN_00471c20();
};
struct NavigationOwner
{
    virtual void UnknownVirtual00() = 0;
    virtual void UnknownVirtual01() = 0;
    virtual void UnknownVirtual02() = 0;
    virtual void UnknownVirtual03() = 0;
    virtual void UnknownVirtual04() = 0;
    virtual void UnknownVirtual05() = 0;
    virtual void UnknownVirtual06() = 0;
    virtual void UnknownVirtual07() = 0;
    virtual void UnknownVirtual08() = 0;
    virtual void UnknownVirtual09() = 0;
    virtual void UnknownVirtual10() = 0;
    virtual void UnknownVirtual11() = 0;
    virtual void UnknownVirtual12() = 0;
    virtual void UnknownVirtual13() = 0;
    virtual void UnknownVirtual14() = 0;
    virtual void UnknownVirtual15() = 0;
    virtual void UnknownVirtual16() = 0;
    virtual void UnknownVirtual17() = 0;
    virtual void UnknownVirtual18() = 0;
    virtual void UnknownVirtual19() = 0;
    virtual void UnknownVirtual20() = 0;
    virtual void UnknownVirtual21() = 0;
    virtual void UnknownVirtual22() = 0;
    virtual void UnknownVirtual23() = 0;
    virtual void UnknownVirtual24() = 0;
    virtual void UnknownVirtual25() = 0;
    virtual void UnknownVirtual26() = 0;
    virtual void UnknownVirtual27() = 0;
    virtual void UnknownVirtual28() = 0;
    virtual void UnknownVirtual29() = 0;
    virtual void UnknownVirtual30() = 0;
    virtual void UnknownVirtual31() = 0;
    virtual void UnknownVirtual32() = 0;
    virtual void UnknownVirtual33() = 0;
    virtual void UnknownVirtual34() = 0;
    virtual void UnknownVirtual35() = 0;
    virtual void UnknownVirtual36() = 0;
    virtual void UnknownVirtual37() = 0;
    virtual void UnknownVirtual38() = 0;
    virtual void UnknownVirtual39() = 0;
    virtual void UnknownVirtual40() = 0;
    virtual void UnknownVirtual41() = 0;
    virtual void UnknownVirtual42() = 0;
    virtual void UnknownVirtual43() = 0;
    virtual void UnknownVirtual44() = 0;
    virtual void UnknownVirtual45() = 0;
    virtual void UnknownVirtual46() = 0;
    virtual void UnknownVirtual47() = 0;
    virtual void UnknownVirtual48() = 0;
    virtual void UnknownVirtual49() = 0;
    virtual void SetNavigationState(int);
    void FUN_006b7b70(NavigationRequest* request);
    void ActivateNavigationEntry(int identifier);
};
// @fnv 0x006b6a00
void NavigationOwner::ActivateNavigationEntry(int identifier)
{
    NavigationRequest* entry;
    if (reinterpret_cast<BoundNavigationMap*>(reinterpret_cast<char*>(this) + 0x1c)->GetAt(identifier, &entry))
    {
        FUN_006b7b70(entry);
        bool isAccepted = false;
        ScopedNavPointer pointer;
        if (entry->FUN_00690860(&pointer))
        {
            VerifiedPath* active = reinterpret_cast<VerifiedPath*>(
                reinterpret_cast<ActiveResolver*>(pointer.FUN_00559450(0))->FUN_00484e60());
            if (active && active->FUN_00471c20())
                isAccepted = true;
        }
        {
            NavigationRequest* selected = entry;
            NavigationRequest* target = selected;
            target ? target->FUN_006b6390(true) : 0;
        }
        reinterpret_cast<BoundNavigationMap*>(reinterpret_cast<char*>(this) + 0x1c)->RemoveKey(identifier);
        if (isAccepted)
            SetNavigationState(1);
    }
}

unsigned int FUN_006b7b30(NavMeshInfo*);
bool FUN_009a3830(NavMeshInfo*&, NavMeshInfo*&);
struct InfoArray
{
    virtual ~InfoArray();
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool (*)(NavMeshInfo*&, NavMeshInfo*&));
    void FUN_006bf8f0(unsigned int, bool);
    bool FUN_0076b610();
};
struct InnerMap
{
    virtual ~InnerMap();
    bool GetAt(unsigned int, InfoArray*&);
    bool RemoveKey(unsigned int);
    bool IsFieldCZero();
};
struct OuterMap
{
    bool GetAt(unsigned int, InnerMap*&);
    bool RemoveKey(unsigned int);
};
struct MapOwner : NavMeshInfoMap
{
    void FUN_006b7b70(NavMeshInfo*);
};
// @fnv 0x006b7b70
void MapOwner::FUN_006b7b70(NavMeshInfo* info)
{
    unsigned int parent = FUN_006b7b30(info);
    unsigned int map;
    if (info->GetInteriorCell())
        map = 0;
    else
        map = info->m_uiParentSpaceID;
    InnerMap* array;
    if (!reinterpret_cast<OuterMap&>(m_kNavMeshInfoArraysByWorldspace).GetAt(map, array))
        return;
    InfoArray* index;
    if (!array->GetAt(parent, index))
        return;
    unsigned int key = index->FUN_00719b20(info, 0, FUN_009a3830);
    if (key == -1)
        return;
    index->FUN_006bf8f0(key, true);
    if (index->FUN_0076b610())
    {
        array->RemoveKey(parent);
        delete index;
        if (array->IsFieldCZero())
        {
            reinterpret_cast<OuterMap&>(m_kNavMeshInfoArraysByWorldspace).RemoveKey(map);
            delete array;
        }
    }
}

void SaveFormVersion(unsigned int auiChunkID, int aiVersion);
void SaveFormChunk(unsigned int auiChunkID, void* apData, unsigned int auiSize);
bool IsSaveEndianSwapped();

struct NavMeshInfoSaveStandIn : public NavMeshInfo
{
    int GetInfoChunkSize();
    void WriteInfoChunk(char* apBuffer);
    int GetIndexChunkSize();
    void WriteIndexChunk(char* apBuffer);
};

struct NavMeshInfoMapSaveStandIn : public NavMeshInfoMap
{
    void StartSave();
    void EndSave();
    void SaveNavMeshInfoMap();
};

// Starts a save, writes the REVN version, then writes an IMVN info chunk and an ICVN index chunk for each navmesh entry, and ends the save.
// @fnv 0x006b6740
void NavMeshInfoMapSaveStandIn::SaveNavMeshInfoMap()
{
    StartSave();
    SaveFormVersion('REVN', 11);

    void* pos2 = m_kNavMeshInfosByFormID.GetFirstPos();
    while (pos2)
    {
        unsigned int key;
        void* info3;
        m_kNavMeshInfosByFormID.GetNext(pos2, key, info3);
        unsigned int sizeB = ((NavMeshInfoSaveStandIn*)info3)->GetInfoChunkSize();
        char* buffer_ = (char*)operator new(sizeB);
        ((NavMeshInfoSaveStandIn*)info3)->WriteInfoChunk(buffer_);
        SaveFormChunk('IMVN', buffer_, sizeB);
        operator delete(buffer_);
    }

    pos2 = m_kNavMeshInfosByFormID.GetFirstPos();
    while (pos2)
    {
        unsigned int key3;
        void* info6;
        m_kNavMeshInfosByFormID.GetNext(pos2, key3, info6);
        unsigned int size2 = ((NavMeshInfoSaveStandIn*)info6)->GetIndexChunkSize() + 4;
        char* bufferVal = (char*)operator new(size2);
        char* cur3 = bufferVal;
        unsigned int id5 = ((NavMeshInfoSaveStandIn*)info6)->GetNavMeshID();
        if (IsSaveEndianSwapped())
        {
            BSEndian(&id5, EndianSizeTag<4>());
        }
        *(unsigned int*)cur3 = id5;
        cur3 += 4;
        ((NavMeshInfoSaveStandIn*)info6)->WriteIndexChunk(cur3);
        SaveFormChunk('ICVN', bufferVal, size2);
        operator delete(bufferVal);
    }
    EndSave();
}

struct CellKeyStand
{
    bool IsEmpty();
};
struct Dummy_0069b080;
bool __fastcall IsFieldCZero(Dummy_0069b080* p);
struct FUN_006b6990_vslot
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
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8(bool arg);
};
struct FUN_006b6990_shell : public NavMeshInfoMap
{
    void FUN_006b6990(unsigned int id);
    void FUN_006b7b70(unsigned int info);
};
// @fnv 0x006b6990
void FUN_006b6990_shell::FUN_006b6990(unsigned int id)
{
    unsigned int info;
    if (reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(&m_kNavMeshInfosByFormID)->GetAt(id, info))
    {
        reinterpret_cast<CellKeyMap*>(&m_kNavMeshInfosByFormID)->RemoveAt(id);
        if (!IsFieldCZero(reinterpret_cast<Dummy_0069b080*>(&m_kNavMeshInfoArraysByWorldspace)))
        {
            FUN_006b7b70(info);
        }
        reinterpret_cast<FUN_006b6990_vslot*>(this)->vfn_c8(true);
    }
}

template <class V> struct FUN_006b6b20_Map
{
    virtual ~FUN_006b6b20_Map();
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& rpPos, unsigned int& ruiKey, V& rkValue);
    void FUN_00438af0();
};
struct FUN_006b6b20_FormVT
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
    virtual void Unk_32(bool abValue);
};
struct FUN_006b6b20_shell : public NavMeshInfoMap
{
    void ClearNavMeshInfoMaps();
};
struct CellNavMeshInfoArray
{
    virtual ~CellNavMeshInfoArray();
};
typedef FUN_006b6b20_Map<CellNavMeshInfoArray*> CellNavMeshInfoMap;
// Deletes every NavMeshInfo in the first map and every CellNavMeshInfoMap with its arrays in the second, clears both maps, then calls Unk_32(true).
// @fnv 0x006b6b20
void FUN_006b6b20_shell::ClearNavMeshInfoMaps()
{
    void* pPos = ((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)->FUN_004b9ba0();
    while (pPos)
    {
        unsigned int uiKey;
        NavMeshInfo* pInfo;
        ((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)->FUN_006b7f20(pPos, uiKey, pInfo);
        delete pInfo;
    }
    ((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)->FUN_00438af0();
    pPos = ((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)->FUN_004b9ba0();
    while (pPos)
    {
        unsigned int uiCellKey;
        CellNavMeshInfoMap* pCellNavMeshInfoMap;
        ((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)
            ->FUN_006b7f20(pPos, uiCellKey, pCellNavMeshInfoMap);
        void* pInnerPos = pCellNavMeshInfoMap->FUN_004b9ba0();
        while (pInnerPos)
        {
            unsigned int uiInfoKey;
            CellNavMeshInfoArray* pArray;
            pCellNavMeshInfoMap->FUN_006b7f20(pInnerPos, uiInfoKey, pArray);
            delete pArray;
        }
        delete pCellNavMeshInfoMap;
    }
    ((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)->FUN_00438af0();
    ((FUN_006b6b20_FormVT*)this)->Unk_32(true);
}

struct NavMesh;
struct NavMeshInfo;
struct NavMeshPtr;
struct MeshInfoArray;
struct GridArray;
struct CellView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* GetEditorID();
};

struct MeshInfoArray
{
    void* vtable;
    NavMeshInfo** items;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    NavMeshInfo** FUN_00877a30(unsigned int);
    NavMeshInfo** FUN_006a7ad0(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool(__cdecl*)(NavMeshInfo*&, NavMeshInfo*&));
};
struct GridArray
{
    void* vtable;
    void* items;
    unsigned int count;
    unsigned int capacity;
    GridArray();
    ~GridArray();
    unsigned int FUN_0044ddc0();
    void** FUN_00877a30(unsigned int);
    void FUN_007cb2e0(void*);
};
struct InfoNav : NavMeshInfo
{
    int FUN_00690830();
    bool HasNonZeroAtOffset54();
    bool FUN_00690860(NavMeshPtr*);
    int FUN_00690800();

    void InitializeFromMeshSource(NavMesh*);
};

struct DataMatch
{
    unsigned int key;
    NavMeshInfo* info;
    bool FUN_0069e090();
};
struct GridRecord
{
    void* unk00;
    NavMeshInfo* info;
};
struct CleanupMap
{
    void FUN_006b6990(NavMesh*);
};
struct GridLookup
{
    MeshInfoArray* FUN_006b7850(NavMesh*, unsigned int);
};
struct GridMap
{
    GridMap();
    ~GridMap();
    NavMesh* FUN_00559450();
    void* GetEdge(unsigned short);
    void* FUN_0068f6b0(unsigned short);
    unsigned int GetArrFlags();
    unsigned int FUN_006b5a90();
    void CollectTrianglesForDoor(NavMeshInfo*, void*);
};
struct LinkChecker
{
    void* vtable;
    void* buffer;
    unsigned int size;
    unsigned int capacity;
    LinkChecker();
    ~LinkChecker();
    bool FUN_0076b610();
};
struct NavMeshInfoMapData
{
    void* vtable;
    unsigned int hashSize;
    void* hashTable;
    unsigned int count;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void**, unsigned int*, NavMeshInfo**);
};

extern char DAT_01011584[];
extern char DAT_0106c0d8[];
extern char DAT_0106c078[];
extern char DAT_0106c008[];
extern char DAT_0106bfa8[];
extern char DAT_0106bf18[];
extern char DAT_0106be98[];
extern char DAT_0106be20[];
extern char DAT_0106bdb0[];
extern int __cdecl Warning(const char*, ...);
extern bool __cdecl FUN_009a3830(NavMeshInfo*&, NavMeshInfo*&);
extern void __cdecl RemoveNavMeshId(NavMeshInfo*);
extern void __cdecl SplitUInt32(unsigned int, short*, short*);
extern unsigned int __cdecl PackShortPair(unsigned short, unsigned short);
struct LocalList
{
    void* vtable;
    NavMeshInfo** buffer;
    unsigned int size;
    unsigned int cap;
    LocalList();
    ~LocalList();
    unsigned int FUN_0044ddc0();
    NavMeshInfo** FUN_00877a30(unsigned int);
    void FUN_007cb2e0(void*);
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool(__cdecl*)(NavMeshInfo*&, NavMeshInfo*&));
};
struct InfoResolver
{
    unsigned int id;
    NavMeshInfo* info;
    bool FUN_0069e090();
};
struct PointerReference
{
    NavMeshInfo* p;
    NavMeshInfo* FUN_00559450();
    unsigned int FUN_0084e3a0();
    int FUN_006b6390(bool);
};
// Iterates the nav mesh map, warns about and collects invalid meshes, checks adjacency, preferred links and doors, and cleans up the collected meshes.
// @fnv 0x006b6c60
void WorkerNavMap::ValidateNavMeshes()
{
    void* iterator;
    {
        LocalList invalidatedList;
        {
            InfoNav* meshInfo;
            {
                unsigned int identifier;
                iterator = m_kNavMeshInfosByFormID.GetFirstPos();
                while (iterator)
                {
                    m_kNavMeshInfosByFormID.GetNext(iterator, identifier, (void*&)meshInfo);
                    if (!meshInfo->FUN_00690830())
                    {
                        Warning(DAT_0106c0d8, ((PtrView*)meshInfo)->FUN_00559450(),
                                (((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770()
                                     ? ((CellView*)((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770())->GetEditorID()
                                     : DAT_01011584));
                        invalidatedList.FUN_007cb2e0(&meshInfo);
                    }
                    else if (!meshInfo->HasNonZeroAtOffset54())
                    {
                        Warning(DAT_0106c078, ((PtrView*)meshInfo)->FUN_00559450(),
                                (((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770()
                                     ? ((CellView*)((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770())->GetEditorID()
                                     : DAT_01011584));
                        RemoveNavMeshId(meshInfo);
                        invalidatedList.FUN_007cb2e0(&meshInfo);
                    }
                    else
                    {
                        NavMeshPtr activeMesh;
                        {
                            if (!meshInfo->FUN_00690860(&activeMesh))
                            {
                                Warning(
                                    DAT_0106c008, ((PtrView*)meshInfo)->FUN_00559450(),
                                    (((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770()
                                         ? ((CellView*)((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770())->GetEditorID()
                                         : DAT_01011584));
                                invalidatedList.FUN_007cb2e0(&meshInfo);
                                continue;
                            }
                            if (activeMesh.GetPtr()->FUN_00440d80())
                                invalidatedList.FUN_007cb2e0(&meshInfo);
                            for (unsigned int k = 0; k < meshInfo->adjacent.GetSize(); ++k)
                            {
                                bool invalid = false;
                                if (*((MeshInfoArray*)&meshInfo->adjacent)->FUN_00877a30(k))
                                {
                                    if (!FUN_00693d70((unsigned int)((PtrView*)*((MeshInfoArray*)&meshInfo->adjacent)
                                                                         ->FUN_00877a30(k))
                                                          ->FUN_00559450()))
                                        invalid = true;
                                }
                                else
                                    invalid = true;
                                if (invalid)
                                {
                                    Warning(DAT_0106bfa8, ((PtrView*)meshInfo)->FUN_00559450(),
                                            (((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770()
                                                 ? ((CellView*)((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770())
                                                       ->GetEditorID()
                                                 : DAT_01011584));
                                    ((InfoArray*)&meshInfo->adjacent)->FUN_006bf8f0(k, true);
                                    --k;
                                }
                            }
                            for (unsigned int k = 0; k < meshInfo->preferred.GetSize(); ++k)
                            {
                                bool invalid = false;
                                if (*((MeshInfoArray*)&meshInfo->preferred)->FUN_00877a30(k))
                                {
                                    if (!FUN_00693d70((unsigned int)((PtrView*)*((MeshInfoArray*)&meshInfo->preferred)
                                                                         ->FUN_00877a30(k))
                                                          ->FUN_00559450()))
                                        invalid = true;
                                }
                                else
                                    invalid = true;
                                if (invalid)
                                {
                                    Warning(DAT_0106bfa8, ((PtrView*)meshInfo)->FUN_00559450(),
                                            (((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770()
                                                 ? ((CellView*)((NavMeshInfoStandIn*)meshInfo)->FUN_006b7770())
                                                       ->GetEditorID()
                                                 : DAT_01011584));
                                    ((InfoArray*)&meshInfo->preferred)->FUN_006bf8f0(k, true);
                                    --k;
                                }
                            }
                            LocalList neighborList;
                            if (meshInfo->FUN_00690800())
                            {
                                short gridX, gridY;
                                SplitUInt32(meshInfo->m_uiPathingFlags, &gridX, &gridY);
                                for (int x = gridX - 1; x <= gridX + 1; ++x)
                                {
                                    for (int y = gridY - 1; y <= gridY + 1; ++y)
                                    {
                                        if (x == gridX && y == gridY)
                                            continue;
                                        MeshInfoArray* pCellMeshes =
                                            ((GridLookup*)this)
                                                ->FUN_006b7850((NavMesh*)meshInfo->FUN_00690800(),
                                                               PackShortPair((unsigned short)x, (unsigned short)y));
                                        if (pCellMeshes)
                                            for (unsigned int i = 0; i < pCellMeshes->FUN_0044ddc0(); ++i)
                                                neighborList.FUN_007cb2e0(pCellMeshes->FUN_006a7ad0(i));
                                    }
                                }
                            }
                            NavMeshPtr meshPtr;
                            if (meshInfo->FUN_00690860(&meshPtr))
                            {
                                bool corrupt = false;
                                {
                                    for (unsigned int k = 0; k < meshInfo->adjacent.GetSize(); ++k)
                                    {
                                        NavMeshInfo* record = *((MeshInfoArray*)&meshInfo->adjacent)->FUN_00877a30(k);
                                        LinkChecker linkChecker;
                                        ((GridMap*)meshPtr.GetPtr())->CollectTrianglesForDoor(record, &linkChecker);
                                        if (linkChecker.FUN_0076b610())
                                        {
                                            Warning(DAT_0106bf18, ((PtrView*)meshInfo)->FUN_00559450(),
                                                    ((PtrView*)record)->FUN_00559450());
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    for (unsigned int k = 0; k < meshInfo->preferred.GetSize(); ++k)
                                    {
                                        NavMeshInfo* record = *((MeshInfoArray*)&meshInfo->preferred)->FUN_00877a30(k);
                                        LinkChecker linkChecker;
                                        ((GridMap*)meshPtr.GetPtr())->CollectTrianglesForDoor(record, &linkChecker);
                                        if (linkChecker.FUN_0076b610())
                                        {
                                            Warning(DAT_0106bf18, ((PtrView*)meshInfo)->FUN_00559450(),
                                                    ((PtrView*)record)->FUN_00559450());
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    unsigned int count = ((GridMap*)meshPtr.GetPtr())->GetArrFlags();
                                    for (unsigned int k = 0; k < count; ++k)
                                    {
                                        unsigned int size;
                                        if (((DataMatch*)&(
                                                 (GridRecord*)((GridMap*)meshPtr.GetPtr())->GetEdge((unsigned short)k))
                                                 ->info)
                                                ->FUN_0069e090())
                                        {
                                            NavMeshInfo* other =
                                                ((GridRecord*)((GridMap*)meshPtr.GetPtr())->GetEdge((unsigned short)k))
                                                    ->info;
                                            bool missing = true;
                                            size = meshInfo->adjacent.GetSize();
                                            for (unsigned int i = 0; i < size; ++i)
                                                if (*((MeshInfoArray*)&meshInfo->adjacent)->FUN_00877a30(i) == other)
                                                {
                                                    missing = false;
                                                    break;
                                                }
                                            size = meshInfo->preferred.GetSize();
                                            for (unsigned int i = 0; i < size; ++i)
                                                if (*((MeshInfoArray*)&meshInfo->preferred)->FUN_00877a30(i) == other)
                                                {
                                                    missing = false;
                                                    break;
                                                }
                                            if (missing)
                                            {
                                                if (neighborList.FUN_00719b20(other, 0, FUN_009a3830) !=
                                                    (unsigned int)-1)
                                                {
                                                    Warning(DAT_0106be98, ((PtrView*)meshInfo)->FUN_00559450(),
                                                            ((PtrView*)other)->FUN_00559450());
                                                    corrupt = true;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    for (unsigned int k = 0; k < ((GridMap*)meshPtr.GetPtr())->FUN_006b5a90(); ++k)
                                    {
                                        NavMeshInfo** other = (NavMeshInfo**)((GridMap*)meshPtr.GetPtr())
                                                                  ->FUN_0068f6b0((unsigned short)k);
                                        if (((InfoArray*)&meshInfo->doors)->FUN_00719b20(*other, 0, FUN_009a3830) ==
                                            (unsigned int)-1)
                                        {
                                            Warning(DAT_0106be20, ((PtrView*)meshInfo)->FUN_00559450(),
                                                    ((PointerReference*)*other)->FUN_0084e3a0());
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    for (unsigned int k = 0; k < meshInfo->doors.GetSize(); ++k)
                                    {
                                        NavMeshInfo* other = *((MeshInfoArray*)&meshInfo->doors)->FUN_00877a30(k);
                                        {
                                            bool linkChecker = false;
                                            for (unsigned int i = 0; i < ((GridMap*)meshPtr.GetPtr())->FUN_006b5a90();
                                                 ++i)
                                            {
                                                if (*(NavMeshInfo**)((GridMap*)meshPtr.GetPtr())
                                                         ->FUN_0068f6b0((unsigned short)i) == other)
                                                {
                                                    linkChecker = true;
                                                    break;
                                                }
                                            }
                                            if (!linkChecker)
                                            {
                                                Warning(DAT_0106bdb0, ((PtrView*)meshInfo)->FUN_00559450(),
                                                        ((PointerReference*)other)->FUN_0084e3a0());
                                                corrupt = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if (corrupt)
                                    meshInfo->InitializeFromMeshSource(meshPtr.GetPtr());
                            }
                        }
                    }
                }
                for (unsigned int i = 0; i < invalidatedList.FUN_0044ddc0(); ++i)
                {
                    ((CleanupMap*)this)->FUN_006b6990(((PtrView*)*invalidatedList.FUN_00877a30(i))->FUN_00559450());
                    NavMeshInfo* info = *invalidatedList.FUN_00877a30(i);
                    NavMeshInfo* current = info;
                    current ? ((NavigationRequest*)current)->FUN_006b6390(true) : 0;
                }
            }
        }
    }
}

using ::TESObjectCELL;
class TESObjectCELL : public ::TESForm
{
  public:
    virtual ~TESObjectCELL();
};

::TESForm* __fastcall FUN_00690830(const ::NavMeshInfo*);

struct InteriorCellLookup : public ::NavMeshInfo
{
    ::TESObjectCELL* FUN_006b77b0();
};

// Casts the TESForm* returned by FUN_00690830(this) to TESObjectCELL*.
// @fnv 0x006b77b0
::TESObjectCELL* InteriorCellLookup::FUN_006b77b0()
{
    return dynamic_cast< ::TESObjectCELL*>(FUN_00690830(this));
}
