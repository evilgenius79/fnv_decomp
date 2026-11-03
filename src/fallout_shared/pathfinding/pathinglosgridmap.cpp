
// src/fallout_shared/pathfinding/pathinglosgridmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathinglosgridmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_006e0590_shell
{
    void FUN_006e0590();
};

struct FUN_006e10a0_shell
{
    void FUN_006e10a0();
};

// @fnv 0x006e0590
void FUN_006e0590_shell::FUN_006e0590()
{
    ((FUN_006e10a0_shell*)(reinterpret_cast<char*>(this) + 4))->FUN_006e10a0();
}

struct FUN_006a62f0_shell
{
    void __thiscall AddOffset(void*);
};

void __thiscall FUN_006a62f0_shell::AddOffset(void* arg)
{}

struct FUN_006e0ed0_shell
{
    void __thiscall FUN_006e0ed0(void*);
};

// @fnv 0x006e0ed0
void __thiscall FUN_006e0ed0_shell::FUN_006e0ed0(void* arg)
{
    reinterpret_cast<FUN_006a62f0_shell*>(this)->AddOffset(arg);
}

typedef void* NavMeshPtr;

struct NavMeshInfo
{
    bool ResolveNavMesh(NavMeshPtr&);
};

struct FUN_006e08f0_shell
{
    NavMeshInfo* m_pNavMeshInfo;
    bool FUN_006e08f0(NavMeshPtr& aArg);
};

// Checks whether the object at offset 16 is non-null and, if so, delegates to its NavMeshInfo method with aArg.
// @fnv 0x006e08f0
bool FUN_006e08f0_shell::FUN_006e08f0(NavMeshPtr& aArg)
{
    if (reinterpret_cast<void**>(this)[4] == 0)
        return false;
    return reinterpret_cast<NavMeshInfo*>(reinterpret_cast<void**>(this)[4])->ResolveNavMesh(aArg);
}

struct PathingLOSGridMap
{
    void __thiscall FUN_006e02a0();
    void* __thiscall FUN_006e0270(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_006e02a0, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006e0270
void* __thiscall PathingLOSGridMap::FUN_006e0270(unsigned int flags)
{
    this->FUN_006e02a0();
    if (flags & 1)
        _delete(this, 0x54);
    return this;
}

namespace fnv_006e0480 {
void __cdecl operator delete(void*);
struct PathingLOSGridMap
{
    void FUN_006e04b0();
    void* __thiscall FUN_006e0480(unsigned int flags);
};
// Calls FUN_006e04b0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e0480
void* __thiscall PathingLOSGridMap::FUN_006e0480(unsigned int flags)
{
    FUN_006e04b0();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_006e0480

struct FUN_006e0560_shell : FUN_006e0590_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// @fnv 0x006e0560
void* __thiscall FUN_006e0560_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_006e0590();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct BSAudio
{
    void* GetAudioBackendData();
};
struct Flt
{
    operator unsigned int();
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};
struct FUN_006df760_shell
{
    unsigned short GetShortValueAtOffset24();
};
struct FUN_006dfe90_shell
{
    bool __thiscall FUN_006dfe90(BSAudio*, bool);
};
struct FUN_006e0bc0_shell
{
    bool __thiscall FUN_006e0bc0(BSAudio* aArg, bool aFlag);
};
// @fnv 0x006e0bc0
bool __thiscall FUN_006e0bc0_shell::FUN_006e0bc0(BSAudio* aArg, bool aFlag)
{
    void* pTopic = aArg->GetAudioBackendData();
    if (!pTopic || ((FUN_006df760_shell*)aArg)->GetShortValueAtOffset24() == 0xFFFF)
        return false;
    unsigned int key = 0;
    if (((DummyPointerMap*)((char*)this + 8))->GetAt(*(Flt*)pTopic, key))
        return ((FUN_006dfe90_shell*)key)->FUN_006dfe90(aArg, aFlag);
    return false;
}

extern "C"
{
    void __declspec(dllimport) __stdcall vprintf(const char*, void*);
}
extern int DAT_0106cef8;
struct AX
{
    void __thiscall FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_006e1020_shell : AX
{
    FUN_006e1020_shell* __thiscall FUN_006e1020();
};
// Sets the object's vtable pointer to DAT_0106cef8, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x006e1020
FUN_006e1020_shell* __thiscall FUN_006e1020_shell::FUN_006e1020()
{
    *reinterpret_cast<unsigned int**>(this) = reinterpret_cast<unsigned int*>(&DAT_0106cef8);
    FUN_006b3eb0(0, 0);
    return this;
}

struct H_006e1070
{
    void __thiscall FUN_006e1070();
    char data[16];
};
struct FUN_006e0190
{
    unsigned char b0;
    char pad[3];
    H_006e1070 m;
    int i14;
    int i18;
    FUN_006e0190();
};
// Initializes the embedded object, sets b0 and i14 to 0 and i18 to -1.
// @fnv 0x006e0190
FUN_006e0190::FUN_006e0190()
{
    m.FUN_006e1070();
    b0 = 0;
    i14 = 0;
    i18 = -1;
}

namespace fnv_006e05b0 {
struct PathingLOSGridMap
{
    unsigned char _pad0[0x18];
    float m_fCellSize;
    int m_1C;
    unsigned char _pad1[0x24];
    float fRadius;
    void __thiscall ClearMap();
    void __thiscall FUN_006e0320(void* p, float f);
    void __thiscall Reset();
};
// @fnv 0x006e05b0
void __thiscall PathingLOSGridMap::Reset()
{
    m_fCellSize = 0.0f;
    ClearMap();
    FUN_006e0320(&m_1C, fRadius);
}
}  // namespace fnv_006e05b0

void* __cdecl operator new(unsigned int);
struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
};
struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};
struct FUN_006e0e80
{
    char d[0x14];
    FUN_006e0e80();
};
struct FUN_006e0480
{
    ~FUN_006e0480();
    void FUN_006e0070(BGSLoadFormBuffer*);
};
struct LocX
{
    virtual void v0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_006e0d20_t
{
    void FUN_006e0d20(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x006e0d20
void FUN_006e0d20_t::FUN_006e0d20(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
    for (unsigned int iloop = 0; iloop < isaveGameCount; iloop++)
    {
        bool bremove = false;
        FUN_006e0480* ppathingLOSGrid = (FUN_006e0480*)new FUN_006e0e80;
        unsigned int inavmeshID;
        apLoadGameBuffer->ReadFormIdentifier(&inavmeshID);
        ppathingLOSGrid->FUN_006e0070(apLoadGameBuffer);
        if (inavmeshID == 0)
            bremove = true;
        if (!bremove)
            ((SetAtHelper*)((char*)this + 8))->SetAt(inavmeshID, (unsigned int)ppathingLOSGrid);
        else
            delete ppathingLOSGrid;
    }
    apLoadGameBuffer->ReadTypedData((char*)this + 0x18, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x44, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x48, 4);
    ((LocX*)((char*)this + 0x1c))->LoadGame(apLoadGameBuffer);
}

struct FUN_00aa6060_shell
{
    void __thiscall AcquireLock();
};
struct MapX
{
    void* __thiscall GetFirstPos();
};
struct NiTMap
{
    void __thiscall GetNext(void*&, unsigned int&, void*&);
};
struct MyMap
{
    void __thiscall RemoveAll();
};
struct FUN_00aa62e0_shell
{
    void __thiscall FUN_00aa62e0();
};
struct FUN_006e03e0_shell
{
    void ClearMap();
};
// Calls AcquireLock on the object at offset 0x4c, deletes every value in the map at offset 8, then calls RemoveAll and FUN_00aa62e0.
// @fnv 0x006e03e0
void FUN_006e03e0_shell::ClearMap()
{
    ((FUN_00aa6060_shell*)((char*)this + 0x4c))->AcquireLock();
    void* position = ((MapX*)((char*)this + 8))->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        FUN_006e0480* value = 0;
        ((NiTMap*)((char*)this + 8))->GetNext(position, key, (void*&)value);
        delete value;
    }
    ((MyMap*)((char*)this + 8))->RemoveAll();
    ((FUN_00aa62e0_shell*)((char*)this + 0x4c))->FUN_00aa62e0();
}

struct ArrSI
{
    unsigned char pad[0x13];
    unsigned int GetFlags();
    void* __thiscall FUN_006e0ed0(unsigned int);
};

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, int, int);
};

struct BGSSaveGameBuffer : BGSSaveFormBuffer
{
    void __thiscall FUN_00865f60(unsigned int);
};

struct FUN_006df9c0_shell
{
    unsigned char m_byte;
    unsigned char pad[3];
    ArrSI m_aiIndexedValues;
    unsigned char pad2[0x14];

    void __thiscall FUN_006df9c0(BGSSaveGameBuffer*);
};

// Saves the byte, a 4-byte value at offset 0x18, and, when m_byte is zero, the count and each element returned by FUN_006e0ed0.
// @fnv 0x006df9c0
void __thiscall FUN_006df9c0_shell::FUN_006df9c0(BGSSaveGameBuffer* buffer)
{
    buffer->SaveData(this, 1, 0);
    buffer->SaveData((void*)((char*)this + 0x18), 4, 0);

    if (!m_byte)
    {
        unsigned int count;

        count = ((char*)this + 4) ? m_aiIndexedValues.GetFlags() : 0;
        buffer->FUN_00865f60(count);

        for (unsigned int i = 0; i < count; ++i)
        {
            void* data = m_aiIndexedValues.FUN_006e0ed0(i);
            buffer->SaveData(data, 1, 0);
        }
    }
}

struct FUN_006e10c0_shell
{
    void __thiscall FUN_006e10c0(unsigned int, int);
};

struct FUN_006dfa70_index_shell
{
    char* __thiscall FUN_006e0ed0(void*);
};

struct FormLoadEntry
{
    bool m_bIsLoaded;
    unsigned char pad0[3];
    FUN_006dfa70_index_shell index;
    unsigned char pad1[0x10];

    void __thiscall LoadForm(BGSLoadFormBuffer*);
};

// Reads a byte and four bytes into the object, then, if the flag is unset, reads a count and that many single bytes into indexed entries.
// @fnv 0x006dfa70
void __thiscall FormLoadEntry::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(this, 1);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<char*>(this) + 0x18, 4);

    if (!m_bIsLoaded)
    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();

        reinterpret_cast<FUN_006e10c0_shell*>(reinterpret_cast<char*>(this) + 4)->FUN_006e10c0(isaveGameCount, 1);

        for (unsigned int i = 0; i < isaveGameCount; ++i)
        {
            char* cindex = reinterpret_cast<FUN_006dfa70_index_shell*>(reinterpret_cast<char*>(this) + 4)
                               ->FUN_006e0ed0(reinterpret_cast<void*>(i));

            apLoadGameBuffer->ReadTypedData(cindex, 1);
        }
    }
}

namespace fnv_006e10c0 {
struct BSSimpleArrayActor
{
    virtual void v0();
    virtual void* v1(unsigned int);

    void Clear(bool);
};

struct FUN_006e12c0_shell
{
    void __thiscall SetData(unsigned int, unsigned int);
};

struct FUN_006e1280_Class
{
    void __thiscall FUN_006e1280(char*, unsigned int);
};

struct FUN_0072ba80_shell
{
    void __thiscall FUN_0072ba80(char*, unsigned int);
};

struct FUN_006e10c0_shell : BSSimpleArrayActor
{
    void* data;
    unsigned int size;
    unsigned int capacity;

    void __thiscall FUN_006e10c0(unsigned int, bool);
};

// @fnv 0x006e10c0
void __thiscall FUN_006e10c0_shell::FUN_006e10c0(unsigned int uiNewSize, bool abShrinkCapacity)
{
    if (uiNewSize == 0)
    {
        Clear(abShrinkCapacity);
    }
    else if (uiNewSize > capacity)
    {
        if (capacity == 0)
        {
            data = v1(uiNewSize);
            capacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<FUN_006e12c0_shell*>(this)->SetData(uiNewSize, size);
            capacity = uiNewSize;
        }

        reinterpret_cast<FUN_006e1280_Class*>(this)->FUN_006e1280(reinterpret_cast<char*>(data) + size,
                                                                  uiNewSize - size);
        size = uiNewSize;
    }
    else if (uiNewSize < size)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(data) + uiNewSize,
                                                                  size - uiNewSize);
        size = uiNewSize;

        if (abShrinkCapacity && uiNewSize <= (capacity >> 2))
        {
            reinterpret_cast<FUN_006e12c0_shell*>(this)->SetData(uiNewSize, uiNewSize);
            capacity = uiNewSize;
        }
    }
    else
    {
        reinterpret_cast<FUN_006e1280_Class*>(this)->FUN_006e1280(reinterpret_cast<char*>(data) + size,
                                                                  uiNewSize - size);
        size = uiNewSize;
    }
}
}  // namespace fnv_006e10c0

struct GO
{
    operator unsigned int();
};

struct NavMesh
{
    unsigned int __thiscall _ref_0084e3a0();
};

template <class T> struct NiPointer : public GO
{
    T* ptr;
    NiPointer(T*);
    ~NiPointer();
};

struct Arr
{
    unsigned int* GetAt(int);
};

struct Lock
{
    void Enter();
    void Leave();
};

struct FUN_006e0730
{
    unsigned char data[20];
    FUN_006e0730(NiPointer<NavMesh>*);
};

struct FUN_006dfba0_shell
{
    void __thiscall RebuildFromNavMesh(NiPointer<NavMesh>*);
};

struct FUN_006e05f0_shell
{
    bool __thiscall AddNavMeshes(ArrSI*);
};

// @fnv 0x006e05f0
bool FUN_006e05f0_shell::AddNavMeshes(ArrSI* aArg)
{
    reinterpret_cast<Lock*>(reinterpret_cast<unsigned char*>(this) + 0x4c)->Enter();

    for (unsigned int index = 0; index < aArg->GetFlags(); ++index)
    {
        NiPointer<NavMesh> ptrNavMesh2(reinterpret_cast<NavMesh*>(reinterpret_cast<Arr*>(aArg)->GetAt(index)));
        unsigned int navMeshID = 0;

        if (!reinterpret_cast<DummyPointerMap*>(reinterpret_cast<unsigned char*>(this) + 8)
                 ->GetAt(reinterpret_cast<NavMesh*>(static_cast<unsigned int>(ptrNavMesh2))->_ref_0084e3a0(),
                         navMeshID))
        {
            navMeshID = reinterpret_cast<unsigned int>(new FUN_006e0730(&ptrNavMesh2));

            reinterpret_cast<SetAtHelper*>(reinterpret_cast<unsigned char*>(this) + 8)
                ->SetAt(reinterpret_cast<NavMesh*>(static_cast<unsigned int>(ptrNavMesh2))->_ref_0084e3a0(), navMeshID);
        }
        else
        {
            reinterpret_cast<FUN_006dfba0_shell*>(navMeshID)->RebuildFromNavMesh(&ptrNavMesh2);
        }
    }

    reinterpret_cast<Lock*>(reinterpret_cast<unsigned char*>(this) + 0x4c)->Leave();
    return true;
}

struct IndexList
{
    unsigned int __thiscall FUN_0044ddc0();
    unsigned short* __thiscall FUN_0069dec0(unsigned int index);
};

struct NavMeshKey;

struct NavMeshLookup
{
    NavMeshLookup* __thiscall FUN_00559450();
    unsigned char* __thiscall GetTriangleScore(NavMeshLookup* rhs);
    bool __thiscall FUN_0069ad00(NavMeshKey* key);
    IndexList* __thiscall FUN_006911f0(unsigned int identifier);
};

struct NavMeshKey
{
    NavMeshLookup* pointer;
    NavMeshKey();
    ~NavMeshKey();
    NavMeshLookup* __thiscall FUN_00559450();
};

struct NavMeshResults
{
    unsigned char* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int flags;
    void __thiscall FUN_008454f0(unsigned int value);
    void __thiscall FUN_006e10c0(unsigned int size, int mode);
    signed char* __thiscall AddOffset(unsigned int index);
};

struct FUN_006df440_owner
{
    union
    {
        bool valid;
        unsigned int state;
    };
    NavMeshResults results;
    NavMeshLookup* lookup;
    unsigned int identifier;
    bool __thiscall InitFromLookup(NavMeshLookup* value);
};

// Copies bytes indexed by the lookup's index list into results, clears valid if any byte is <=0 or 0x7f, and returns false on missing data.
// @fnv 0x006df440
bool FUN_006df440_owner::InitFromLookup(NavMeshLookup* apLookup)
{
    unsigned char* const bytes = apLookup->FUN_00559450()->GetTriangleScore(lookup->FUN_00559450());
    if (!bytes)
        return false;

    NavMeshKey key;
    if (!lookup->FUN_0069ad00(&key))
        return false;

    IndexList* const indices = key.FUN_00559450()->FUN_006911f0(identifier);
    if (!indices)
        return false;

    results.FUN_008454f0(0);
    results.FUN_006e10c0(indices->FUN_0044ddc0(), 1);
    valid = true;

    for (unsigned int index = 0; index < indices->FUN_0044ddc0(); ++index)
    {
        *results.AddOffset(index) = bytes[*indices->FUN_0069dec0(index)];
        if (*results.AddOffset(index) <= 0 || *results.AddOffset(index) == 0x7f)
            valid = false;
    }

    if (valid)
        results.FUN_008454f0(1);

    return true;
}

class B6E01D0SolutionBase
{
  public:
    B6E01D0SolutionBase();
    virtual ~B6E01D0SolutionBase();

    int unk04;
};

class B6E01D0Array
{
  public:
    B6E01D0Array(int iGrowBy);
    ~B6E01D0Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacity;
    int m_iGrowBy;
};

class B6E01D0Location
{
  public:
    B6E01D0Location();
    ~B6E01D0Location();

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
};

class B6E01D0Matrix
{
  public:
    B6E01D0Matrix();

    float m_afEntry0;
    float m_afEntry1;
    float m_afEntry2;
};

class FUN_006e01d0_cls : public B6E01D0SolutionBase
{
  public:
    FUN_006e01d0_cls();
    virtual ~FUN_006e01d0_cls();

    B6E01D0Array m_kNodeArray;
    float m_fCost;
    B6E01D0Location m_kGoal;
    float m_fHitDistance;
    float m_fTime;
    B6E01D0Matrix m_kTransform;
};

// Constructs the solution object, initializing its array with grow-by 0x25 and zeroing cost, time and related floats.
// @fnv 0x006e01d0
FUN_006e01d0_cls::FUN_006e01d0_cls() : m_kNodeArray(0x25), m_fCost(0.0f), m_fHitDistance(0.0f), m_fTime(0.0f)
{}

struct Loc14
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Loc14();
    ~Loc14();
};

struct Sub1c
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
    void FUN_006dcce0(unsigned int aArg);
};

struct Sub4c
{
    int unk00;
    void AcquireLock();
    void FUN_00aa62e0();
};

unsigned char __cdecl FUN_006d8a20(void* aP, float aF, Loc14* aOut);

struct FUN_006e0320_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Sub1c m_1c;
    float m_44;
    int unk48;
    Sub4c m_4c;
    void AddNavMeshes(Loc14* aOut);
    void FUN_006e0320(unsigned int aArg, float aF);
};

// @fnv 0x006e0320
void FUN_006e0320_cls::FUN_006e0320(unsigned int aArg, float aF)
{
    m_4c.AcquireLock();
    m_1c.FUN_006dcce0(aArg);
    m_44 = aF;
    Loc14 locResult;
    if (FUN_006d8a20(&m_1c, aF, &locResult) != 0)
    {
        AddNavMeshes(&locResult);
    }
    else
    {
        m_44 = 0.0f;
    }
    m_4c.FUN_00aa62e0();
}

struct NavMeshRef
{
    void* m_pObject;
    NavMeshRef();
    ~NavMeshRef();
};

struct NavMeshRefArray
{
    void* m_pBuffer;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;
    NavMeshRefArray();
    ~NavMeshRefArray();
    unsigned int Add(const NavMeshRef& arRef);
};

struct LOSTarget;

struct LOSTargetPtr
{
    LOSTarget* m_pObject;
    operator LOSTarget*() const;
};

struct LOSTarget
{
    void CollectNavMeshes(NavMeshRefArray& arArray);
};

struct LOSNavMeshInfo
{
    bool GetNavMeshRef(NavMeshRef& arRef);
    void Update(LOSTargetPtr& arTarget);
};

struct LOSInfoMap
{
    void* GetFirstPos();
    void GetNext(void*& arPos, unsigned int& arKey, LOSNavMeshInfo*& arVal);
};

struct LOSLock
{
    void Lock();
    void Unlock();
};

struct LOSGridOwner
{
    int unk00;
    int unk04;
    LOSInfoMap kMap;
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
    int unk48;
    LOSLock kLock;

    bool UpdateNavMeshes(LOSTargetPtr& arTarget);
};

// @fnv 0x006e07a0
bool LOSGridOwner::UpdateNavMeshes(LOSTargetPtr& arTarget)
{
    kLock.Lock();
    NavMeshRefArray kArray2;
    void* pPos3;
    for (pPos3 = kMap.GetFirstPos(); pPos3;)
    {
        LOSNavMeshInfo* pInfo;
        unsigned int uiKey;
        kMap.GetNext(pPos3, uiKey, pInfo);
        NavMeshRef kRef9;
        if (pInfo->GetNavMeshRef(kRef9))
            kArray2.Add(kRef9);
    }
    ((LOSTarget*)arTarget)->CollectNavMeshes(kArray2);
    for (pPos3 = kMap.GetFirstPos(); pPos3;)
    {
        LOSNavMeshInfo* pInfo2;
        unsigned int uiKey2;
        kMap.GetNext(pPos3, uiKey2, pInfo2);
        NavMeshRef kRefX;
        if (pInfo2->GetNavMeshRef(kRefX))
            pInfo2->Update(arTarget);
    }
    kLock.Unlock();
    return true;
}

struct NavMeshInfoX;

struct NavMeshX
{
    unsigned int GetFormID();
    NavMeshInfoX* GetNavMeshInfo();
};

template <class T> struct NiPtr
{
    T* m_pObject;
    NiPtr(T* apObject);
    ~NiPtr();
    T* operator->() const;
};

struct NavMeshArrayX
{
    unsigned int GetCount();
    NavMeshX* GetAt(unsigned int auiIndex);
    float GetValue();
};

struct GridEntryX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    GridEntryX(NavMeshInfoX* apInfo);
    bool Update(const NiPtr<NavMeshArrayX>& arArray);
};

struct EntryMapX
{
    bool GetAt(unsigned int auiKey, GridEntryX*& arVal) const;
    void SetAt(unsigned int auiKey, GridEntryX* apVal);
};

struct LockX
{
    void Lock();
    void Unlock();
};

void* __cdecl operator new(unsigned int);

struct PathingLOSGridMapX
{
    int unk00;
    int unk04;
    EntryMapX kMap;
    int unk0C;
    int unk10;
    int unk14;
    float fValue;
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
    LockX kLock;

    bool UpdateFromNavMeshArray(const NiPtr<NavMeshArrayX>& arArray);
};

// Locks the map, creates or finds a GridEntryX per nav mesh and updates it, then stores the array value in fValue and unlocks.
// @fnv 0x006e0920
bool PathingLOSGridMapX::UpdateFromNavMeshArray(const NiPtr<NavMeshArrayX>& arNavMeshArray)
{
    kLock.Lock();
    for (unsigned int i6 = 0; i6 < arNavMeshArray->GetCount(); i6++)
    {
        NiPtr<NavMeshX> spNavMesh2(arNavMeshArray->GetAt(i6));
        GridEntryX* pEntry = 0;
        if (!kMap.GetAt(spNavMesh2->GetFormID(), pEntry))
        {
            pEntry = new GridEntryX(spNavMesh2->GetNavMeshInfo());
            kMap.SetAt(spNavMesh2->GetFormID(), pEntry);
        }
        pEntry->Update(arNavMeshArray);
    }
    fValue = arNavMeshArray->GetValue();
    kLock.Unlock();
    return true;
}

class C6E0A90List
{
  public:
    C6E0A90List();
    ~C6E0A90List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006e0a90 : public C6E0A90List
{
  public:
    FUN_006e0a90(const FUN_006e0a90& kOther);

    void CopyFrom(const FUN_006e0a90& kOther);

    int m_iArrayLength;
};

// @fnv 0x006e0a90
FUN_006e0a90::FUN_006e0a90(const FUN_006e0a90& kOther)
{
    m_iArrayLength = 0;
    CopyFrom(kOther);
}

struct FUN_006e0b00_cls
{
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
    unsigned int m_i30;
    unsigned int m_i34;
    float GetRatio();
};

// Returns m_i30 divided by the sum of m_i30 and m_i34, or 1.0 when that sum is zero.
// @fnv 0x006e0b00
float FUN_006e0b00_cls::GetRatio()
{
    unsigned int total = m_i30 + m_i34;
    if (total != 0)
    {
        return (float)((double)m_i30 / (double)total);
    }
    else
    {
        return 1.0f;
    }
}

struct FUN_0044edb0_shell
{
    void* __thiscall FUN_0044edb0();
};
struct FUN_00559450_shell
{
    void* __thiscall FUN_00559450(unsigned int*);
};
struct FUN_00853130_shell
{
    bool __thiscall GetAt(void*);
};
struct FUN_006dfdc0_shell
{
    bool __thiscall FUN_006dfdc0(void*);
};

struct FUN_006e0b50_cls
{
    unsigned char m_00[8];
    unsigned char m_08[0x10];

    bool __thiscall FUN_006e0b50(void* aArg);
};

// @fnv 0x006e0b50
bool __thiscall FUN_006e0b50_cls::FUN_006e0b50(void* aArg)
{
    unsigned int value;
    void* pHolder = ((FUN_0044edb0_shell*)aArg)->FUN_0044edb0();
    if (pHolder == 0 || ((FUN_006df760_shell*)aArg)->GetShortValueAtOffset24() == 0xffff)
    {
        return false;
    }
    value = 0;
    if (((FUN_00853130_shell*)((char*)this + 8))->GetAt(((FUN_00559450_shell*)pHolder)->FUN_00559450(&value)))
    {
        return ((FUN_006dfdc0_shell*)value)->FUN_006dfdc0(aArg);
    }
    return false;
}

struct LoadBufferEx
{
    unsigned int __thiscall FUN_00865f20();
    void __thiscall FUN_00865db0(unsigned int key, unsigned int flags);
    void __thiscall FUN_00865ff0(unsigned int writtenCount, unsigned int offset);
    void __thiscall FUN_00865e50(void* value, unsigned int size, unsigned int flags);
};
struct PathingCell
{
    void __thiscall WriteToBuffer(LoadBufferEx* buffer);
};
struct CellMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* __thiscall FUN_004b9ba0();
    void __thiscall FUN_006b7f20(void*& position, unsigned int& key, PathingCell*& value);
};
struct CellData
{
    virtual void LoadGame(LoadBufferEx* buffer);
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24;
};
struct PathingGrid
{
    unsigned int unk00;
    unsigned int unk04;
    CellMap cells;
    unsigned int unk18;
    CellData metadata;
    unsigned int unk44;
    unsigned int unk48;

    void SaveGame(LoadBufferEx* buffer);
};
// @fnv 0x006e0c40
void PathingGrid::SaveGame(LoadBufferEx* buffer)
{
    unsigned int writtenCount = 0;
    unsigned int startOffset = buffer->FUN_00865f20();
    void* position = cells.FUN_004b9ba0();
    while (position != 0)
    {
        PathingCell* cell = 0;
        unsigned int key;
        cells.FUN_006b7f20(position, key, cell);
        if (cell != 0)
        {
            buffer->FUN_00865db0(key, 0);
            cell->WriteToBuffer(buffer);
            writtenCount++;
        }
    }
    buffer->FUN_00865ff0(writtenCount, startOffset);
    buffer->FUN_00865e50(&unk18, 4, 0);
    buffer->FUN_00865e50(&unk44, 4, 0);
    buffer->FUN_00865e50(&unk48, 4, 0);
    metadata.LoadGame(buffer);
}

struct Owner6df780
{
    bool valid;
    NavMeshResults results;
    NavMeshLookup* lookup;
    unsigned int identifier;
    bool __thiscall UpdateNavMeshResults(FUN_006df760_shell* a1, unsigned char a2);
};
// @fnv 0x006df780
bool __thiscall Owner6df780::UpdateNavMeshResults(FUN_006df760_shell* a1, unsigned char a2)
{
    NavMeshKey key;
    if (!lookup->FUN_0069ad00(&key))
        return false;
    IndexList* list3 = key.FUN_00559450()->FUN_006911f0(identifier);
    if (valid)
    {
        if (a2)
            return true;
        else
        {
            valid = false;
            results.FUN_006e10c0(list3->FUN_0044ddc0(), 1);
            for (unsigned int i = 0; i < list3->FUN_0044ddc0(); ++i)
            {
                unsigned short w = *list3->FUN_0069dec0(i);
                if (w == a1->GetShortValueAtOffset24())
                    *results.AddOffset(i) = -1;
                else
                    *results.AddOffset(i) = 1;
            }
            return true;
        }
    }
    else
    {
        if (list3->FUN_0044ddc0() != ((IndexList*)&results)->FUN_0044ddc0())
            return false;
        for (unsigned int i = 0; i < list3->FUN_0044ddc0(); ++i)
        {
            unsigned short w = *list3->FUN_0069dec0(i);
            if (w == a1->GetShortValueAtOffset24())
            {
                *results.AddOffset(i) = a2 ? 1 : -1;
                return true;
            }
        }
    }
    return false;
}

// Destructor of an owning array: delete every element, then the base array frees its storage.

class E04B0Element
{
  public:
    ~E04B0Element();

    int unk00;
};

class E04B0Array
{
  public:
    ~E04B0Array();
    unsigned int GetSize();
    E04B0Element*& GetAt(unsigned int uiIndex) const;

    void* m_pBuffer;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
};

class FUN_006e04b0 : public E04B0Array
{
  public:
    ~FUN_006e04b0();
};

// Destructor that iterates over the array and deletes each element pointer returned by GetAt.
// @fnv 0x006e04b0
FUN_006e04b0::~FUN_006e04b0()
{
    for (unsigned int i = 0; i < GetSize(); i++)
        delete GetAt(i);
}

namespace fnv_006e0730 {
class C6E0730List
{
  public:
    C6E0730List();
    ~C6E0730List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006e0730 : public C6E0730List
{
  public:
    FUN_006e0730(const FUN_006e0730& kOther);

    void CopyFrom(const FUN_006e0730& kOther);

    int m_iArrayLength;
};

// @fnv 0x006e0730
FUN_006e0730::FUN_006e0730(const FUN_006e0730& kOther)
{
    m_iArrayLength = 0;
    CopyFrom(kOther);
}
}  // namespace fnv_006e0730

struct FUN_006a62f0_Class
{
    int __thiscall AddOffset(void*);
};

// @fnv 0x006a62f0
int __thiscall FUN_006a62f0_Class::AddOffset(void* arg)
{
    return reinterpret_cast<int*>(this)[1] + reinterpret_cast<int>(arg);
}

struct Pathing;
struct FormLoadEntry;
struct BGSLoadFormBuffer;
struct TESConditionItem;
struct TES;
struct _Mem_20a4;
struct BSSimpleArray;

struct Pathing
{
    NavMeshInfo* FindReferenceByFormId();
};

struct TES
{
    Pathing* GetActiveCell(unsigned int);
};

struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};

struct BSSimpleArray : public _Mem_20a4
{
    FormLoadEntry*& GetAt(int);
};

struct TESConditionItem
{
    void SetObjectType(int);
};

unsigned int _data_011c16bc;
int g_TES;

// @fnv 0x006e0070
void FUN_006e0480::FUN_006e0070(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned int inavmeshID;

    inavmeshID = 0;
    apLoadGameBuffer->ReadFormIdentifier(&inavmeshID);

    ((NavMeshInfo**)((char*)this + 0x10))[0] =
        ((Pathing*)((TES*)g_TES)->GetActiveCell(inavmeshID))->FindReferenceByFormId();

    {
        unsigned int isaveGameCount;

        isaveGameCount = apLoadGameBuffer->ReadElementCount();
        ((_Mem_20a4*)this)->SetSize(isaveGameCount, true);

        {
            unsigned int i;

            for (i = 0; i < isaveGameCount; ++i)
            {
                FormLoadEntry** ppFormLoadEntry;

                ppFormLoadEntry = &((BSSimpleArray*)this)->GetAt(i);
                *ppFormLoadEntry = (FormLoadEntry*)new FUN_006e0190();

                (*ppFormLoadEntry)->LoadForm(apLoadGameBuffer);
                ((TESConditionItem*)*ppFormLoadEntry)->SetObjectType((int)((NavMeshInfo**)((char*)this + 0x10))[0]);
            }
        }
    }
}

struct LOSGridBase
{
    virtual ~LOSGridBase();
    int unk04;
};
struct LOSGridMap08
{
    ~LOSGridMap08();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct LOSGridLock1C
{
    ~LOSGridLock1C();
    int unk00;
};
struct LOSGridMapReal : LOSGridBase
{
    LOSGridMap08 kMap;
    LOSGridLock1C kLock;
    virtual ~LOSGridMapReal();
    void ClearMap();
};
// @fnv 0x006e02a0
LOSGridMapReal::~LOSGridMapReal()
{
    ClearMap();
}
