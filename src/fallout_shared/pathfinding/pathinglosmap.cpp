
// src/fallout_shared/pathfinding/pathinglosmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathinglosmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct PathingLOSMap
{
    virtual ~PathingLOSMap();
    void* DestroyAndFree(unsigned int flags);
};

extern "C" void __cdecl operator delete(void* p, unsigned int size);

// Runs the destructor and, when flags has bit 0 set, frees the object with operator delete, then returns this.
// @fnv 0x006e1440
void* PathingLOSMap::DestroyAndFree(unsigned int flags)
{
    this->PathingLOSMap::~PathingLOSMap();
    if (flags & 1)
        operator delete(this, 0x50);
    return this;
}

namespace fnv_006e1610 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};

struct PathingLOSMap
{
    char* pTriangleScores;
    char* GetTriangleScore(unsigned int aNavMeshID);
};

// Looks up aNavMeshID in the map at this+8 and returns a pointer into the buffer at this+0x18 offset by the stored offset, or null if not found.
// @fnv 0x006e1610
char* PathingLOSMap::GetTriangleScore(unsigned int aNavMeshID)
{
    unsigned int ioffset;
    if (((DummyPointerMap*)((char*)this + 8))->GetAt(aNavMeshID, ioffset))
        return ((char**)((char*)this + 0x18))[0] + ioffset;
    else
        return 0;
}
}  // namespace fnv_006e1610

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};

struct FUN_006e1650_shell
{
    DummyPointerMap m_map;  // at offset 8
    void GetMapValue(unsigned int a, unsigned int& b);
};

// Calls GetAt on the DummyPointerMap at offset 8 of this object, passing a and b through.
// @fnv 0x006e1650
void FUN_006e1650_shell::GetMapValue(unsigned int uiKey, unsigned int& ruiValue)
{
    ((DummyPointerMap*)((char*)this + 8))->GetAt(uiKey, ruiValue);
}

// Returns the smaller of the two char arguments.
// @fnv 0x006e1f80
char MinChar(char a, char b)
{
    char result;
    if (a < b)
        result = a;
    else
        result = b;
    return result;
}

// Returns the larger of the two char arguments.
// @fnv 0x006e1fb0
char MaxChar(char acFirst, char acSecond)
{
    char c;
    if (acFirst > acSecond)
        c = acFirst;
    else
        c = acSecond;
    return c;
}

struct NiTArray
{
    void SetSize(unsigned int);
};

struct FUN_006e1fe0_shell
{
    void SetArraySize(unsigned int aSize);
};

// @fnv 0x006e1fe0
void FUN_006e1fe0_shell::SetArraySize(unsigned int aSize)
{
    ((NiTArray*)(this + 0x9c))->SetSize(aSize);
}

namespace fnv_006e2050 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};

struct PathingLOSMap
{
    DummyPointerMap m_map;
    bool HasNavMeshEntry(unsigned int aiNavMeshID);
};

// Looks up aiNavMeshID in the map at offset 8 and returns whether GetAt found an entry.
// @fnv 0x006e2050
bool PathingLOSMap::HasNavMeshEntry(unsigned int aiNavMeshID)
{
    unsigned int idummy;
    return ((DummyPointerMap*)((char*)this + 8))->GetAt(aiNavMeshID, idummy);
}
}  // namespace fnv_006e2050

struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct Script
{
    int GetText();
    char GetByteAt(unsigned int i);
    char FUN_006e1670(unsigned int i, unsigned int a, unsigned int b);
};
struct FUN_006e1770_shell
{
    bool FUN_006e1770(unsigned int a, unsigned int b);
};
// Returns false if the helper at offset 0x1c reports true; otherwise scans text entries and returns true on the first non-positive char whose lookup succeeds.
// @fnv 0x006e1770
bool FUN_006e1770_shell::FUN_006e1770(unsigned int a, unsigned int b)
{
    if (((const ArrHelper*)((char*)this + 0x1c))->FUN_0076b610())
        return false;
    for (unsigned int i = 0; i < ((Script*)this)->GetText(); ++i)
    {
        char cChar = ((Script*)this)->GetByteAt(i);
        if (cChar > 0)
            continue;
        unsigned char d = ((Script*)this)->FUN_006e1670(i, a, b);
        if (d)
            return true;
    }
    return false;
}

namespace fnv_006e2000 {
struct Script
{
    int GetText();
};
struct FUN_006d7ee0_shell
{
    char GetByteAt(unsigned int a);
};
struct FUN_006d8970_shell
{
    void SetByteAt(int, int);
};
struct FUN_006e2000_shell
{
    void ClampNonPositiveTextChars();
};
// Iterates over the text characters and sets each character whose value is <= 0 to 0x7f.
// @fnv 0x006e2000
void FUN_006e2000_shell::ClampNonPositiveTextChars()
{
    for (unsigned int i = 0; i < ((Script*)this)->GetText(); ++i)
    {
        if (((FUN_006d7ee0_shell*)this)->GetByteAt(i) <= 0)
            ((FUN_006d8970_shell*)this)->SetByteAt((int)i, 0x7f);
    }
}
}  // namespace fnv_006e2000

struct PathingLOSBase
{
    virtual ~PathingLOSBase();
    unsigned int unk04;
};

struct LOSSub08
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~LOSSub08();
};

struct LOSHeap
{
    unsigned int unk00;
    static void operator delete(void* apMemory);
};

struct LOSMember1C
{
    unsigned int unk00;
    void ReleaseMember();
};

struct FUN_006e1470 : PathingLOSBase
{
    LOSSub08 m_08;
    LOSHeap* m_18;
    LOSMember1C m_1c;

    virtual ~FUN_006e1470();
};

// Destructor that deletes m_18 if non-null, then calls ReleaseMember on m_1c.
// @fnv 0x006e1470
FUN_006e1470::~FUN_006e1470()
{
    if (m_18 != 0)
    {
        delete m_18;
    }
    m_1c.ReleaseMember();
}

struct NavMesh;

struct NavMeshPtr
{
    NavMesh* FUN_00559450();
};

struct NavMesh
{
    unsigned int FUN_0084e3a0();
    unsigned int FUN_00558200();
};

struct NavMeshCollection
{
    unsigned int FUN_0044ddc0();
    NavMeshPtr& FUN_00877a30(unsigned int i);
};

struct MapHelper
{
    void FUN_00844700(unsigned int key, unsigned int val);
};

struct Shell1c
{
    void AppendValue(NavMeshPtr& ptr);
};

struct FUN_006e1500_class
{
    void* vtable;
    char pad_04[4];
    MapHelper m_map;
    char pad_0c[0x0c];
    char* m_pData;
    Shell1c m_shell1c;
    char pad_20[0x0c];
    unsigned int m_uTotalCount;

    bool BuildNavMeshMap(NavMeshCollection* pArray);
};

// Clears the total count, maps each array entry's navmesh id to a running offset, sums sizes, then allocates and fills m_pData with 0x7f.
// @fnv 0x006e1500
bool FUN_006e1500_class::BuildNavMeshMap(NavMeshCollection* pNavMeshArray)
{
    unsigned int i;
    unsigned int j2;
    m_uTotalCount = 0;
    for (i = 0; i < pNavMeshArray->FUN_0044ddc0(); i++)
    {
        m_map.FUN_00844700(pNavMeshArray->FUN_00877a30(i).FUN_00559450()->FUN_0084e3a0(), m_uTotalCount);
        m_uTotalCount += pNavMeshArray->FUN_00877a30(i).FUN_00559450()->FUN_00558200();
        m_shell1c.AppendValue(pNavMeshArray->FUN_00877a30(i));
    }
    if (m_pData)
    {
        delete m_pData;
    }
    m_pData = new char[m_uTotalCount];
    for (j2 = 0; j2 < m_uTotalCount; j2++)
    {
        m_pData[j2] = 0x7f;
    }
    return true;
}

struct SeqEntry
{
    SeqEntry* FUN_00559450();
    Script* FUN_0084e3a0();
};

struct SeqList
{
    unsigned int FUN_0044ddc0();
    SeqEntry* FUN_00877a30(unsigned int index);
};

struct SubMatcher
{
    bool GetAt(Script* script, unsigned int* outLen);
};

struct SpawnedTarget
{
    void FUN_0042f4c0(SeqEntry* entry);
};

struct FUN_006e1670_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    char FUN_006e1670(unsigned int limit, SpawnedTarget* target, unsigned short* outOffset);
};

// Scans the sequence list, measuring each entry's script length; when a length exceeds limit, stores the remaining offset and passes the previous entry to target.
// @fnv 0x006e1670
char FUN_006e1670_cls::FUN_006e1670(unsigned int limit, SpawnedTarget* target, unsigned short* outOffset)
{
    unsigned int i;
    unsigned int accum;
    if (((ArrHelper*)((char*)this + 0x1c))->FUN_0076b610())
    {
        return 0;
    }

    i = 0;
    for (accum = 0; accum < ((SeqList*)((char*)this + 0x1c))->FUN_0044ddc0(); accum++)
    {
        unsigned int len;
        Script* script = ((SeqList*)((char*)this + 0x1c))->FUN_00877a30(accum)->FUN_00559450()->FUN_0084e3a0();
        if (!((SubMatcher*)((char*)this + 8))->GetAt(script, &len))
        {
            return 0;
        }
        if (len > limit)
        {
            *outOffset = (unsigned short)(limit - i);
            target->FUN_0042f4c0(((SeqList*)((char*)this + 0x1c))->FUN_00877a30(accum - 1));
            return 1;
        }
        else
        {
            i = len;
        }
    }
    *outOffset = (unsigned short)(limit - i);
    target->FUN_0042f4c0(((SeqList*)((char*)this + 0x1c))->FUN_00877a30(accum - 1));
    return 1;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
    NiPoint3(float x, float y, float z);
};

struct NiColor
{
    float r;
    float g;
    float b;
};

struct ImageSpaceEffectParam
{
    float m0;
    float m1;
    float m2;
    float m3;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int size);
};

class NiObject : public NiMemObject
{
  public:
    virtual ~NiObject();
};

class NiAVObject : public NiObject
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    void AttachProperty(NiObject* property);
};

class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool unk05;
    int unk08;
    NiUpdateData(float time = 0.0f, bool updateControllers = false, bool unk05 = false);
};

class NiNode : public NiAVObject
{
  public:
    virtual unsigned int AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail = false);
    void Update(const NiUpdateData& data);
};

class NiSortAdjustNode : public NiNode
{
  public:
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
    NiSortAdjustNode(int mode = 0);
    void FUN_00440460(const NiPoint3& pt);
    void FUN_00a5a040();
    void SetArraySize(unsigned int size);
};

class NiProperty : public NiObject
{
  public:
    void FUN_004bc450(const NiColor* color);
    void FUN_0068c9f0(float alpha);
};

class NiAlphaProperty : public NiProperty
{
  public:
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiAlphaProperty();
    void FUN_0049ed90(bool enable);
};

class NiMaterialProperty : public NiProperty
{
  public:
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
    NiMaterialProperty();
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
};

struct NavMeshTriangle
{
    bool GetFlag(int flag);
    unsigned short FUN_005582d0(int index);
};

struct NavMeshEx : NavMesh
{
    NavMeshTriangle* GetTriangle(unsigned short id);
    NiPoint3* FUN_0068f0a0(unsigned short index);
};

class NavMeshLocalPtr
{
  public:
    void* m_ptr;
    NavMeshLocalPtr();
    ~NavMeshLocalPtr();
    operator NavMeshEx*() const;
    NavMeshEx* operator->() const;
};

struct FUN_004bc1f0_S
{
    void FUN_004bc1f0(float a, float b, float c);
};

void* __cdecl FUN_00c58f00(float, int, void*);
void* __cdecl FUN_00c58d30(float, float, float, int, int, void*);
void __cdecl AttachLightingPropertyRecursive(void*);
void __cdecl FUN_00b57e30(void*, int, int);
NiAVObject* __cdecl FUN_004b3570(NiPoint3, NiPoint3, NiPoint3, const ImageSpaceEffectParam*, int);

struct ScriptClass : Script
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
    float f3c;
    float f40;
    float f44;
    float f48;

    NiSortAdjustNode* CreateSortAdjustNode();
};

// @fnv 0x006e1800
NiSortAdjustNode* ScriptClass::CreateSortAdjustNode()
{
    NiSortAdjustNode* rootNode = new NiSortAdjustNode(0);
    NiPointer<NiAlphaProperty> spA(new NiAlphaProperty());
    spA->FUN_0049ed90(true);
    NiPointer<NiMaterialProperty> spB(new NiMaterialProperty());
    spB->FUN_004bc450((const NiColor*)&NiPoint3(1.0f, 1.0f, 1.0f));
    spB->FUN_0068c9f0(0.75f);
    rootNode->AttachProperty(spA);
    rootNode->AttachProperty(spB);

    char highest = (char)0x81;
    char low = (char)0x7f;
    for (unsigned int i = 0; i < (unsigned int)this->GetText(); ++i)
    {
        char c = this->GetByteAt(i);
        if (c == 0x7f)
            continue;
        highest = MaxChar(highest, c);
        low = MinChar(low, c);
    }

    rootNode->SetArraySize((unsigned int)this->GetText() + 10);

    for (unsigned int j = 0; j < (unsigned int)this->GetText(); ++j)
    {
        NavMeshLocalPtr p2;
        unsigned short p0;
        if (!(unsigned char)this->FUN_006e1670(j, (unsigned int)&p2, (unsigned int)&p0))
            continue;
        char a = this->GetByteAt(j);
        if (a == 0x7f)
            continue;
        float p = (a < 0) ? ((float)a / low * 0.5 + 0.5) : 0.0;
        float h1 = (a > 0) ? ((float)a / highest * 0.5 + 0.5) : 0.0;
        ImageSpaceEffectParam h0(p, h1, 0.0f, 0.75f);
        NiPoint3 cf[3];
        NavMeshTriangle* h = p2->GetTriangle(p0);
        if (!h->GetFlag(0x20))
        {
            for (unsigned int k = 0; k < 3; ++k)
            {
                cf[k] = *p2->FUN_0068f0a0(h->FUN_005582d0(k));
                cf[k].z += 5.0;
            }
            NiPointer<NiAVObject> spC(FUN_004b3570(cf[0], cf[1], cf[2], &h0, 1));
            rootNode->AttachChildInAvailableSlot(spC, 1);
        }
    }

    if (this->f48 != 0.0)
    {
        NiSortAdjustNode* p4 = new NiSortAdjustNode(0);
        ImageSpaceEffectParam vec(1.0f, 1.0f, 0.0f, 0.5f);
        for (unsigned int m = 0; m < 5; ++m)
        {
            void* ac = FUN_00c58f00(this->f48, 0x24, &vec);
            ((FUN_004bc1f0_S*)ac)->FUN_004bc1f0(this->f3c, this->f40, (float)((double)m * 25.0 + this->f44));
            p4->AttachChildInAvailableSlot((NiAVObject*)ac, 1);
        }
        void* ac1 = FUN_00c58d30(16.0f, 16.0f, 400.0f, 10, 10, &vec);
        ((NiSortAdjustNode*)ac1)->FUN_00440460(*(const NiPoint3*)&this->f3c);
        p4->AttachChildInAvailableSlot((NiAVObject*)ac1, 1);
        AttachLightingPropertyRecursive(p4);
        FUN_00b57e30(p4, 0, 0);
        rootNode->AttachChildInAvailableSlot(p4, 1);
    }

    rootNode->FUN_00a5a040();
    NiUpdateData updateData(0.0f, false, false);
    rootNode->Update(updateData);
    return rootNode;
}
