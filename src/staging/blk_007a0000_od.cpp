
// src/staging/blk_007a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_007a1400_class
{
    void FUN_007a1400(int flags);
};

// @fnv 0x007a1400
void FUN_007a1400_class::FUN_007a1400(int flags)
{
    if (*(int*)((char*)this + 0x30) & flags)
        *(int*)((char*)this + 0x30) ^= flags;
}

struct FUN_007a1430_Class
{
    unsigned char m_data[0x92];
    unsigned char m_flag;
    void SetFlag(unsigned char value);
};

// @fnv 0x007a1430
void FUN_007a1430_Class::SetFlag(unsigned char value)
{
    m_flag = value;
}

struct Unk65
{
    void FUN_0065de30(int);
};

struct Unk65a
{
    Unk65* __thiscall FUN_007ab230(Unk65* other);
};

// @fnv 0x007ab230
Unk65* __thiscall Unk65a::FUN_007ab230(Unk65* other)
{
    other->FUN_0065de30((int)this);
    return other;
}

extern "C" void* __cdecl DAT_01075794;

struct NavMeshInfo;

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};

struct FUN_007ab590 : BSSimpleArray<NavMeshInfo*, 1024>
{
    FUN_007ab590* DeserializeFromFile();
};

// Sets the object's vtable pointer to DAT_01075794, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x007ab590
FUN_007ab590* FUN_007ab590::DeserializeFromFile()
{
    *reinterpret_cast<void**>(this) = &DAT_01075794;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_007ab610 {
extern int DAT_010757a8;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_007ab610();
};
// @fnv 0x007ab610
AX* AX::FUN_007ab610()
{
    *(int*)this = (int)&DAT_010757a8;
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_007ab610

extern int DAT_010757a8;

struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
    void __thiscall FUN_007ab670();
};

void __thiscall GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x007ab670
void __thiscall GlobalObject_00869f00::FUN_007ab670()
{
    *(int*)this = (int)&DAT_010757a8;
    Clear(true);
}

struct FUN_007adcc0_class
{
    void SetAllow(bool abAllow);
};

// @fnv 0x007adcc0
void FUN_007adcc0_class::SetAllow(bool abAllow)
{
    ((unsigned char*)this)[0x75d] = abAllow;
}

struct FUN_007b8f10_Class
{
    unsigned int __thiscall GetField630();
};

// @fnv 0x007b8f10
unsigned int __thiscall FUN_007b8f10_Class::GetField630()
{
    return *(unsigned int*)((char*)this + 0x630);
}

struct GlobalObject_007ab590
{
    ~GlobalObject_007ab590();
    void* __thiscall FUN_007ab5c0(unsigned int flags);
};

// Runs the destructor and, if flags has bit 0 set, frees the object with operator delete, then returns this.
// @fnv 0x007ab5c0
void* __thiscall GlobalObject_007ab590::FUN_007ab5c0(unsigned int flags)
{
    GlobalObject_007ab590::~GlobalObject_007ab590();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl FUN_00730490(char*, int);

struct FUN_007b52a0_class
{
    char* m_ptr;
    unsigned short m_uiItemCount;
    void __thiscall FUN_007b52a0();
};

// @fnv 0x007b52a0
void __thiscall FUN_007b52a0_class::FUN_007b52a0()
{
    if (m_ptr)
        FUN_00730490(m_ptr, m_uiItemCount + 1);
}

struct EffectSetting
{
    EffectSetting* GetLight();
};
struct MapMenu_007a1880
{
    unsigned char m_data[0x10c];
    EffectSetting* pEffect;
    bool bEffectChanged;
};
extern MapMenu_007a1880* DAT_011da368;
// @fnv 0x007a1880
void __cdecl FUN_007a1880(EffectSetting* effect)
{
    if (DAT_011da368)
    {
        EffectSetting* previous = DAT_011da368->pEffect;
        DAT_011da368->pEffect = effect;
        while (DAT_011da368->pEffect && DAT_011da368->pEffect->GetLight())
            DAT_011da368->pEffect = DAT_011da368->pEffect->GetLight();
        DAT_011da368->bEffectChanged = previous != DAT_011da368->pEffect;
    }
}

struct NavMeshInfo;
struct NavMeshInfo4
{
    NavMeshInfo* m_pObjectInfo;
    unsigned int m_uiSize;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;
};
struct FUN_007a1450_Class
{
    unsigned char m_data[0x68];
    NavMeshInfo4 m_pMesh;
    void SetNavMeshInfo(NavMeshInfo4& source);
};
// @fnv 0x007a1450
void FUN_007a1450_Class::SetNavMeshInfo(NavMeshInfo4& source)
{
    m_pMesh = source;
}

struct FUN_007a8030_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    unsigned int FUN_007a8030(int);
    virtual void FUN_007a8030_v5(int);
};

struct FUN_007a62b0_Class : FUN_007a8030_Class
{
    void FUN_007a62b0();
};

// Calls FUN_007a8030 with 0, subtracts 1 from the result, and passes it to FUN_007a8030_v5.
// @fnv 0x007a62b0
void FUN_007a62b0_Class::FUN_007a62b0()
{
    FUN_007a8030_v5(FUN_007a8030(0) - 1);
}

struct BSS
{
    ~BSS();
    BSS* FUN_007a86b0(unsigned int flags);
};
// Destructs the object and, if bit 0 of flags is set, frees its memory, then returns the pointer.
// @fnv 0x007a86b0
BSS* BSS::FUN_007a86b0(unsigned int flags)
{
    this->BSS::~BSS();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct BSSimpleArrayActor
{
    void __thiscall Clear(bool);
};
void* __cdecl DAT_01075794;

struct FUN_007ab5f0_class : BSSimpleArrayActor
{
    void* m_data;
    void FUN_007ab5f0();
};

// @fnv 0x007ab5f0
void FUN_007ab5f0_class::FUN_007ab5f0()
{
    m_data = &DAT_01075794;
    Clear(true);
}

struct GlobalObject_007ab610
{
    ~GlobalObject_007ab610();
    void* FUN_007ab640(unsigned int flags);
};
// Destroys the object, optionally frees its memory when flags has bit 0 set, and returns the object pointer.
// @fnv 0x007ab640
void* GlobalObject_007ab610::FUN_007ab640(unsigned int flags)
{
    this->GlobalObject_007ab610::~GlobalObject_007ab610();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_011dea14;

// @fnv 0x007a1480
int __cdecl FUN_007a1480()
{
    return DAT_011dea14;
}

struct NavMeshPayload
{
    bool Equals(int mode);
};
struct NavMeshListNode
{
    void* m_payload;
    unsigned int m_uiEdgeIndex;
    unsigned int m_uiContentCount;
    NavMeshListNode* m_next;
    NavMeshListNode(NavMeshPayload* payload);
    bool IsNotEqual(int mode);
    void FUN_00418900(NavMeshPayload* payload);
    void FUN_007a19a0(NavMeshPayload* payload);
};
// @fnv 0x007a19a0
void NavMeshListNode::FUN_007a19a0(NavMeshPayload* payload)
{
    if (payload->Equals(0))
        return;
    NavMeshListNode* current = this;
    while (current->m_next)
        current = current->m_next;
    if (current->IsNotEqual(0))
        current->m_next = new NavMeshListNode(payload);
    else
        current->FUN_00418900(payload);
}

struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};

struct FUN_007a28c0
{
    virtual ~FUN_007a28c0();
    FUN_0046ffb0 member;
    void ClearEntries();
};

void __cdecl FUN_007211c0(FUN_007a28c0* object);

// Calls ClearEntries, then passes this to FUN_007211c0 as part of destruction.
// @fnv 0x007a28c0
FUN_007a28c0::~FUN_007a28c0()
{
    ClearEntries();
    FUN_007211c0(this);
}

class SubObj
{
  public:
    int unk00;
    ~SubObj();
};

class FUN_007a37b0
{
  public:
    virtual void unk00();
    void Cleanup();
    SubObj m_sub;
    ~FUN_007a37b0();
};

void __cdecl ReleaseObject(FUN_007a37b0* p);

// @fnv 0x007a37b0
FUN_007a37b0::~FUN_007a37b0()
{
    Cleanup();
    ReleaseObject(this);
}

class FUN_007a4470_sub
{
  public:
    ~FUN_007a4470_sub();
    int m_00;
};

class FUN_007a4470_cls
{
  public:
    virtual ~FUN_007a4470_cls();
    void Step();
    FUN_007a4470_sub m_04;
};

void __cdecl FUN_007211c0(FUN_007a4470_cls* p);

// Calls Step, then passes this to FUN_007211c0 during destruction.
// @fnv 0x007a4470
FUN_007a4470_cls::~FUN_007a4470_cls()
{
    Step();
    FUN_007211c0(this);
}

struct FUN_007a51c0_m4
{
    int m_00;
    ~FUN_007a51c0_m4();
};

void __cdecl FUN_007211c0(void* p);

struct FUN_007a51c0_cls
{
    virtual ~FUN_007a51c0_cls();
    FUN_007a51c0_m4 m_04;

    void FUN_007a54d0();
};

// @fnv 0x007a51c0
FUN_007a51c0_cls::~FUN_007a51c0_cls()
{
    FUN_007a54d0();
    FUN_007211c0(this);
}

struct FUN_007a6220_class
{
    virtual void FUN_007a6220_v1();
    virtual void FUN_007a6220_v2();
    virtual void FUN_007a6220_v3();
    virtual void FUN_007a6220_v4();
    virtual void FUN_007a6220_v5();
    virtual void FUN_007a6220_v6(int value);

    int __thiscall GetUnfilteredCount(int value);

    void __thiscall FUN_007a6220();
};

// Calls GetUnfilteredCount with 0, subtracts 1 from the result, and passes it to FUN_007a6220_v6.
// @fnv 0x007a6220
void __thiscall FUN_007a6220_class::FUN_007a6220()
{
    FUN_007a6220_v6(GetUnfilteredCount(0) - 1);
}

// FUN_007a6250 : thiscall member, no stack args.
// this->FUN_007a71b0(0) returns a count; the count-1 is passed to the
// virtual function living in vtable slot 5 (offset 0x14).
struct SpawnedObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int value);

    int FUN_007a71b0(int mode);

    void FUN_007a6250();
};

// Calls FUN_007a71b0 with 0, subtracts 1 from the result, and passes it to v05.
// @fnv 0x007a6250
void SpawnedObject::FUN_007a6250()
{
    this->v05(this->FUN_007a71b0(0) - 1);
}

struct SceneThing
{
    void __thiscall FUN_00700320(unsigned int flags, unsigned int index);
};

struct SceneInner
{
    SceneThing* m_00;
    unsigned int unk04;
    unsigned char m_flag08;
};

struct SceneHolder
{
    SceneInner* m_00;
};

struct SceneNodeRef
{
    SceneHolder* FUN_006815c0();
    SceneNodeRef* FUN_00726070();
};

struct FUN_007a80e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void AccumulateTileHeight(SceneThing* thing);
    void FUN_007a8580();
    void UpdateHighlight();
    void InitSceneNodes();
};

// @fnv 0x007a80e0
void FUN_007a80e0_cls::InitSceneNodes()
{
    this->m_1c = 0;
    this->m_20 = 0.0f;
    for (SceneNodeRef* pNodeRef = this ? (SceneNodeRef*)((char*)this + 4) : 0;
         pNodeRef != 0 && pNodeRef->FUN_006815c0()->m_00 != 0; pNodeRef = pNodeRef->FUN_00726070())
    {
        if (pNodeRef->FUN_006815c0()->m_00->m_flag08 == 0)
        {
            pNodeRef->FUN_006815c0()->m_00->m_00->FUN_00700320(0xfac, this->m_1c++);
            this->AccumulateTileHeight(pNodeRef->FUN_006815c0()->m_00->m_00);
        }
    }
    this->FUN_007a8580();
    this->UpdateHighlight();
}

// Sub-object with an out-of-line destructor (shared by every member below).
class ManagedSubObject
{
  public:
    int unk00;
    ~ManagedSubObject();
};

extern "C" void __cdecl FormHeap_Free(void* p);

class FUN_007a8960_cls : public ManagedSubObject
{
  public:
    int unk04;
    void* m_08;
    ManagedSubObject m_0c;
    int unk10;
    ManagedSubObject m_14;
    int unk18;
    int unk1c;
    ManagedSubObject m_20;
    int unk24;
    int unk28;
    int unk2c;
    ManagedSubObject m_30;
    ~FUN_007a8960_cls();
};

// @fnv 0x007a8960
FUN_007a8960_cls::~FUN_007a8960_cls()
{
    void* p = m_08;
    FormHeap_Free(p);
    m_08 = 0;
}

// FUN_007abda0: returns constant 0x3f8
// @fnv 0x007abda0
int __cdecl FUN_007abda0()
{
    return 0x3f8;
}

struct RefObj7ac9f0
{
    void IncRefCount();
    void DecRefCount();
};

struct Vec3_7ac9f0
{
    float x;
    float y;
    float z;
    Vec3_7ac9f0()
    {}
};

struct Base7ac9f0
{
    Base7ac9f0();
    virtual ~Base7ac9f0();
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
};

struct FUN_007ac9f0 : Base7ac9f0
{
    NiPointer<RefObj7ac9f0> pFirst[4];
    NiPointer<RefObj7ac9f0> pSecond[4];
    NiPointer<RefObj7ac9f0> spObj0;
    NiPointer<RefObj7ac9f0> spObj1;
    NiPointer<RefObj7ac9f0> spObj2;
    NiPointer<RefObj7ac9f0> spObj3;
    NiPointer<RefObj7ac9f0> spObj4;
    NiPointer<RefObj7ac9f0> spObj5;
    Vec3_7ac9f0 kPos0;
    Vec3_7ac9f0 kPos1;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    Vec3_7ac9f0 kPos2;
    FUN_007ac9f0();
    virtual ~FUN_007ac9f0();
};

// @fnv 0x007ac9f0
FUN_007ac9f0::FUN_007ac9f0()
{}

extern "C" const double DAT_01012060;
struct ActiveEffectEntry
{
    float FUN_00a011b0(unsigned int id);
    void FUN_00a012d0(unsigned int id, float value, bool update);
};
struct ActiveEffectCollection
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float rate;
    int FUN_00559450();
    ActiveEffectEntry*** FUN_0057cbe0(int* iterator);
    void FUN_007b4530(int amount);
};
// @fnv 0x007b4530
void ActiveEffectCollection::FUN_007b4530(int amount)
{
    if (rate <= DAT_01012060)
        return;
    int it = FUN_00559450();
    while (it)
    {
        ActiveEffectEntry* pEffect = **FUN_0057cbe0(&it);
        float fAmount = pEffect->FUN_00a011b0(4002);
        fAmount = (float)amount * rate + fAmount;
        pEffect->FUN_00a012d0(4002, fAmount, true);
    }
}

struct FUN_007b52d0_cls
{
    int* DereferenceIfNotNull(int** pParam);
};

// Returns the pointer stored at pParam when pParam is non-null, otherwise returns null.
// @fnv 0x007b52d0
int* FUN_007b52d0_cls::DereferenceIfNotNull(int** pParam)
{
    return pParam != 0 ? *pParam : (int*)0;
}

struct FUN_0049fa80_Result
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_007b5330_Class
{
    FUN_0049fa80_Result* __thiscall FUN_0049fa80();
    void __thiscall InsertBefore(int arg1, FUN_0049fa80_Result* arg2);
    void __thiscall FUN_007b5330(int arg1, int* arg2);
};

// Gets a result object, stores the int pointed to by arg2 into its unk08 field, then passes it with arg1 to InsertBefore.
// @fnv 0x007b5330
void __thiscall FUN_007b5330_Class::FUN_007b5330(int arg1, int* arg2)
{
    FUN_0049fa80_Result* result = this->FUN_0049fa80();
    result->unk08 = *arg2;
    this->InsertBefore(arg1, result);
}

namespace q72 {
struct Target
{
    void FUN_00700320(int id, int idx);
};
struct Item
{
    Target* m_pFlagTarget;
    int u4;
    bool m_bSkip;
};
struct SL
{
    Item* item;
    SL* next;
    Item*& FUN_006815c0();
    SL* FUN_00726070();
};
struct Head
{
    int m_iWordAt00;
};
struct Menu : Head, SL
{
    char pad0c[0x10];
    unsigned short m_usElementCount;
    float m_fValue;
    void AccumulateTileHeight(Target* t);
    void FUN_007a7700();
    void FUN_007a73e0();
    void FUN_007a7260();
};
// @fnv 0x007a7260
void Menu::FUN_007a7260()
{
    m_usElementCount = 0;
    m_fValue = 0.0f;
    for (SL* it = this; it && it->FUN_006815c0(); it = it->FUN_00726070())
    {
        if (!it->FUN_006815c0()->m_bSkip)
        {
            it->FUN_006815c0()->m_pFlagTarget->FUN_00700320(0xfac, m_usElementCount++);
            AccumulateTileHeight(it->FUN_006815c0()->m_pFlagTarget);
        }
    }
    FUN_007a7700();
    FUN_007a73e0();
}
}
