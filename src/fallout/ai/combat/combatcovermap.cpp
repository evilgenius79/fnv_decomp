
// src/fallout/ai/combat/combatcovermap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatcovermap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CombatCoverMap
{
    void* __thiscall FUN_00983100(unsigned int flags);
    void __thiscall FUN_00983130();
};

// Calls FUN_00983130, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00983100
void* CombatCoverMap::FUN_00983100(unsigned int flags)
{
    FUN_00983130();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00983400_shell
{
    unsigned char m_auc_16[0x17];
    void SetByteAtOffset(unsigned char param);
};

// @fnv 0x00983400
void FUN_00983400_shell::SetByteAtOffset(unsigned char param)
{
    m_auc_16[0x16] = param;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00983250_shell
{
    void __thiscall FUN_00982d10();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x00983250
void* __thiscall FUN_00983250_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00982d10();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct StageHolder
{
    bool __thiscall GetDone();
};
struct Calendar
{
    unsigned int __thiscall GetDaysPassed();
};
struct TESWorldSpace;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;
struct FUN_00983280_holder
{
    void __thiscall FUN_00983280(int, StageHolder*);
};
struct FUN_009a0510_shell
{
    char _pad[0x1c4];
    int m_1c4;
    void __thiscall FUN_009a0510(StageHolder*);
};
// If a1 is non-null and not done, calls FUN_00983280 with m_1c4 and a1 on the object returned by GetDaysPassed.
// @fnv 0x009a0510
void __thiscall FUN_009a0510_shell::FUN_009a0510(StageHolder* pStage)
{
    if (pStage && !pStage->GetDone())
        ((FUN_00983280_holder*)((Calendar*)BGSSaveLoadGlobalDataWorldspacePtr)->GetDaysPassed())
            ->FUN_00983280(m_1c4, pStage);
}

namespace fnv_009a0560 {
struct StageHolder
{
    bool __thiscall GetDone();
};
struct Calendar
{
    unsigned int __thiscall GetDaysPassed();
};
struct FUN_00983420_shell
{
    bool __thiscall GetOrCreateCoverItem(int, StageHolder*);
};
struct TESWorldSpace;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;
struct FUN_009a0560_shell
{
    bool __thiscall FUN_009a0560(StageHolder*);
};
// Returns true if the stage holder is null or done, otherwise delegates to GetOrCreateCoverItem with the days passed and the holder.
// @fnv 0x009a0560
bool __thiscall FUN_009a0560_shell::FUN_009a0560(StageHolder* pStageHolder)
{
    if (pStageHolder && !pStageHolder->GetDone())
        return ((FUN_00983420_shell*)((Calendar*)BGSSaveLoadGlobalDataWorldspacePtr)->GetDaysPassed())
            ->GetOrCreateCoverItem(*(int*)((char*)this + 0x1C4), pStageHolder);
    return true;
}
}  // namespace fnv_009a0560

namespace fnv_009a05b0 {
struct StageHolder
{
    bool GetDone();
};
struct FUN_00983520_obj
{
    void __thiscall FUN_00983520(int, StageHolder*);
};
struct Calendar
{
    FUN_00983520_obj* GetDaysPassed();
};
extern Calendar* BGSSaveLoadGlobalDataWorldspacePtr;
struct FUN_009a05b0_shell
{
    unsigned char pad[0x1c4];
    int fld1c4;
    void __thiscall FUN_009a05b0(StageHolder*);
};
// If a1 is non-null and done, passes fld1c4 and a1 to FUN_00983520 via the worldspace save-load global's days-passed object.
// @fnv 0x009a05b0
void __thiscall FUN_009a05b0_shell::FUN_009a05b0(StageHolder* pStage)
{
    if (pStage && pStage->GetDone())
    {
        BGSSaveLoadGlobalDataWorldspacePtr->GetDaysPassed()->FUN_00983520(fld1c4, pStage);
    }
}
}  // namespace fnv_009a05b0

struct StageHolder;
struct MapMember
{
    void AcquireLock();
    void FUN_00aa62e0();
};
struct HolderLookup
{
    bool GetAt(unsigned int key, void** value);
    void FUN_00844700(unsigned int key, void* value);
};
struct CreatedShell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    CreatedShell();
    void SetByteAtOffset(unsigned char value);
    void AddItem(int value, StageHolder* holder);
};
struct HolderStatus
{
    bool GetDone();
    void FUN_0067fdb0(unsigned char value);
};
// @fnv 0x00983280
void FUN_00983280_holder::FUN_00983280(int value, StageHolder* pStageHolder)
{
    ((MapMember*)((char*)this + 0x14))->AcquireLock();
    void* pCreatedShell = 0;
    if (!((HolderLookup*)this)->GetAt(*(unsigned int*)((char*)pStageHolder + 0x68), &pCreatedShell))
    {
        pCreatedShell = new CreatedShell();
        ((CreatedShell*)pCreatedShell)->SetByteAtOffset(((HolderStatus*)pStageHolder)->GetDone());
        ((HolderLookup*)this)->FUN_00844700(*(unsigned int*)((char*)pStageHolder + 0x68), pCreatedShell);
    }
    ((CreatedShell*)pCreatedShell)->AddItem(value, pStageHolder);
    ((HolderStatus*)pStageHolder)->FUN_0067fdb0(1);
    ((MapMember*)((char*)this + 0x14))->FUN_00aa62e0();
}

struct FUN_009836d0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_009836d0_class* __thiscall FUN_009836d0();
    FUN_009836d0_class()
    {
        FUN_009836d0();
    }
    ~FUN_009836d0_class()
    {}
};

struct GlobalObject_00633c90
{
    int unk00;
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90()
    {}
};

struct FUN_00983380 : FUN_009836d0_class
{
    int unk10;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    GlobalObject_00633c90 unk18;
    FUN_00983380();
};

// @fnv 0x00983380
FUN_00983380::FUN_00983380() : unk10(0), unk14(0), unk15(0), unk16(0), unk18(0)
{}

struct Arg2
{
    char pad[0x68];
    void* unk68;

    bool FUN_00678ce0();
    void FUN_0067fdb0(bool);
};

struct Lock
{
    void Enter();
    void Leave();
};

struct CoverItem : FUN_00983400_shell
{
    char unk17[5];
    CoverItem();
    bool RegisterEvent(void* arg1, Arg2* arg2);
};

struct FUN_00983420_class
{
    char pad[0x14];
    Lock lock;

    bool GetAt(void* key, CoverItem** out);
    void FUN_00844700(void* key, CoverItem* val);

    bool GetOrCreateCoverItem(void* arg1, Arg2* arg2);
};

// Locks, looks up or creates a CoverItem for arg2->unk68, runs RegisterEvent on it, stores the result via arg2->FUN_0067fdb0, and returns it.
// @fnv 0x00983420
bool FUN_00983420_class::GetOrCreateCoverItem(void* arg1, Arg2* arg2)
{
    lock.Enter();
    CoverItem* pItem = 0;
    if (!GetAt(arg2->unk68, &pItem))
    {
        pItem = new CoverItem();
        pItem->SetByteAtOffset(arg2->FUN_00678ce0());
        FUN_00844700(arg2->unk68, pItem);
    }
    bool kRet = pItem->RegisterEvent(arg1, arg2);
    arg2->FUN_0067fdb0(kRet);
    lock.Leave();
    return kRet;
}

struct Chain
{
    int GetFlaggedValue(bool flag);
};
struct Pair3Pool
{
    int FUN_00726070();
};
struct SrcNode
{
    Chain* FUN_0044ddc0();
    bool HasEffect(int which);
};
struct MemberVt
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
    virtual void* GetB();
    virtual void* GetA();
};
struct FUN_008a88f0_cls
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    MemberVt* m68;
    float FUN_008a88f0();
};
extern const double DAT_01012060;
// Gets two values from m68's members and returns their ratio, or 1.0 when either member is null or the divisor equals DAT_01012060.
// @fnv 0x008a88f0
float FUN_008a88f0_cls::FUN_008a88f0()
{
    Pair3Pool* ywqVal = (Pair3Pool*)m68->GetA();
    if (ywqVal != 0)
    {
        SrcNode* qzxVal = (SrcNode*)m68->GetB();
        if (qzxVal != 0)
        {
            Chain* ccq4 = qzxVal->FUN_0044ddc0();
            float ofq = (float)ccq4->GetFlaggedValue(qzxVal->HasEffect(2));
            float fc = (float)ywqVal->FUN_00726070();
            if ((double)ofq == DAT_01012060)
            {
                return 1.0f;
            }
            return fc / ofq;
        }
    }
    return 1.0f;
}

struct CoverMapValue
{
    ~CoverMapValue();
};

struct CoverMapTarget
{
    virtual void unk00();
};

struct CoverMapOwner
{
    CoverMapTarget* GetTarget();
};

template <class T> struct CoverMapPointer
{
    T* m_pObject;
    ~CoverMapPointer();
    operator T*() const;
};

struct CoverMapBase
{
    virtual void Unk00();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    ~CoverMapBase();
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& uiKey, CoverMapValue*& pValue);
    void RemoveAll();
};

struct CoverMapVirtualTarget
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
    virtual void Detach(CoverMapOwner* owner);
};

struct CoverMapOwnerEx
{
    CoverMapVirtualTarget* GetTarget();
};

struct FUN_00983130 : CoverMapBase
{
    CoverMapPointer<CoverMapOwnerEx> m_spOwner;
    virtual void Unk00();
    ~FUN_00983130();
};

// Deletes every value in the hash table, clears it, then detaches the owner's target if one is set.
// @fnv 0x00983130
FUN_00983130::~FUN_00983130()
{
    void* pos = GetFirstPos();
    while (pos)
    {
        unsigned int uiKey = 0;
        CoverMapValue* pValue = 0;
        GetNext(pos, uiKey, pValue);
        delete pValue;
    }
    RemoveAll();
    if (m_spOwner && ((CoverMapOwnerEx*)m_spOwner)->GetTarget())
    {
        ((CoverMapOwnerEx*)m_spOwner)->GetTarget()->Detach((CoverMapOwner*)(CoverMapOwnerEx*)m_spOwner);
    }
}

struct CoverItemCalls
{
    bool FUN_00982df0(unsigned int value);
};

struct CoverTargetCalls
{
    bool FUN_009827c0(unsigned int a, unsigned int b, float c, CoverItem* item, unsigned char d, unsigned char e);
};

struct CoverLockCalls
{
    void FUN_00aa5ff0();
    void FUN_00aa62c0();
};

struct FUN_009835d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    CoverLockCalls lock;

    bool GetAt(void* key, CoverItem** out);
    bool TryUseCoverItem(unsigned int key, unsigned int p2, unsigned int p3, float x, void* target, unsigned char d,
                         unsigned char e);
};

// @fnv 0x009835d0
bool FUN_009835d0_cls::TryUseCoverItem(unsigned int key, unsigned int p2, unsigned int p3, float fValue, void* target,
                                       unsigned char d, unsigned char e)
{
    bool ok = true;
    CoverItem* item;

    lock.FUN_00aa5ff0();
    item = 0;
    if (GetAt((void*)key, &item))
    {
        if (!((CoverItemCalls*)item)->FUN_00982df0(p3))
        {
            ok = false;
        }
    }
    if (ok)
    {
        ok = ((CoverTargetCalls*)target)->FUN_009827c0(p2, p3, fValue, item, d, e);
    }
    lock.FUN_00aa62c0();
    return ok;
}

struct CoverReservationUnreserveCalls
{
    bool FUN_00982ff0(void* owner, Arg2* location);
};

struct CoverMapUnreserveReceiver : FUN_00983420_class
{
    void RemoveKey(void* value);
    void FUN_00983520(void* arg1, Arg2* arg2);
};

// Looks up the item at arg2->unk68, calls its callback, and on success calls DestroyIfFlagged and removes the keyed entry.
// @fnv 0x00983520
void CoverMapUnreserveReceiver::FUN_00983520(void* apOwner, Arg2* apLocation)
{
    if (apLocation->unk68 == 0)
    {
    }
    else
    {
        this->lock.Enter();
        CoverItem* item = 0;
        if (this->GetAt(apLocation->unk68, &item))
        {
            if (((CoverReservationUnreserveCalls*)item)->FUN_00982ff0(apOwner, apLocation))
            {
                CoverItem* b = item;
                CoverItem* a = b;
                a != 0 ? ((FUN_00983250_shell*)a)->DestroyIfFlagged(1) : 0;
                this->RemoveKey(apLocation->unk68);
            }
            apLocation->FUN_0067fdb0(false);
        }
        this->lock.Leave();
    }
}
