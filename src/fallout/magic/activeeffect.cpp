// fallout/magic/activeeffect.cpp: Interface, EffectSetting, Self, EffectSaveShell (47 functions)

#include "activeeffect_local.h"

// @fnv 0x00804090
void ActiveEffect::CopyData(ActiveEffect* pOther)
{
    pOther->m_fEffectMagnitude = m_fEffectMagnitude;
    pOther->pSpell = pSpell;
    pOther->pEffect = pEffect;
    pOther->bActive = bActive;
    pOther->bEffectFlag = bEffectFlag;
    pOther->bWasPlaying = bWasPlaying;
    pOther->bPickResultFound = bPickResultFound;
    pOther->m_bEffectState = m_bEffectState;
    pOther->m_fElapsedTime = m_fElapsedTime;
    pOther->fDuration = fDuration;
    pOther->pTarget = pTarget;
    pOther->m_pEffectInstance = m_pEffectInstance;
    pOther->m_eSpellType = m_eSpellType;
    pOther->pSource = pSource;
    pOther->iFlags = iFlags;
    pOther->pMagicItem = pMagicItem;
}

class ActiveEffectLoadDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* pBuffer);
};

// Iterates the list and calls the load dispatch on each ActiveEffect with the given buffer.
// @fnv 0x00806b50
void ActiveEffect::WriteActiveEffectList(BGSLoadFormBuffer* pBuffer, BSSimpleList<ActiveEffect*>* apEffectList)
{
    BSSimpleList<BGSPerkEntry*>* pNode = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(apEffectList);
    while (pNode)
    {
        ActiveEffect* pEffect = reinterpret_cast<ActiveEffect*>(pNode->GetItem());
        if (pEffect)
        {
            reinterpret_cast<ActiveEffectLoadDispatch*>(pEffect)->ApplyLoadBuffer(pBuffer);
        }
        pNode = pNode->GetNext();
    }
}

class MagicCaster
{
  public:
    MagicItem* GetSelectedMagicItem();
    static MagicCaster* GetCasterByHandle(unsigned int id);
};
class MagicTarget
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual bool IsActor();
    char data[12];
    static int CompareActiveEffects(ActiveEffect*, ActiveEffect*);
    static MagicTarget* GetMagicTargetByID(unsigned int id);
};
class MagicItem
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual MagicSystem__SpellType GetSpellType();
    char prefix[8];
    EffectItemList effects;
    static MagicItem* GetMagicItemByID(unsigned int id);
};

class Actor : public ActorPrimary, public MagicTarget, public ActorValueOwner
{
};
class SpellItem : public MagicItem
{
};
class AlchemyItem : public MagicItem
{
  public:
    void* FUN_004030b0();
};

class MagicHitEffectLoadDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void InitLoadGame(BGSLoadFormBuffer* pBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*);
};

// Resolves the caster, target and item pointers from their stored ids, then forwards InitLoadGame to each MagicHitEffect in the list.
// @fnv 0x008066d0
void ActiveEffect::InitLoadGame(BGSLoadFormBuffer* pBuffer)
{
    BSSimpleList<BGSPerkEntry*>* pNode;
    m_pEffectInstance = m_pEffectInstance ? MagicCaster::GetCasterByHandle(reinterpret_cast<unsigned int>(m_pEffectInstance)) : 0;
    pTarget = pTarget ? MagicTarget::GetMagicTargetByID(reinterpret_cast<unsigned int>(pTarget)) : 0;
    pMagicItem = pMagicItem ? MagicItem::GetMagicItemByID(reinterpret_cast<unsigned int>(pMagicItem)) : 0;
    pNode = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pHitEffectList);
    while (pNode)
    {
        MagicHitEffect* pEffect = reinterpret_cast<MagicHitEffect*>(pNode->GetItem());
        if (pEffect)
        {
            reinterpret_cast<MagicHitEffectLoadDispatch*>(pEffect)->InitLoadGame(pBuffer);
        }
        pNode = pNode->GetNext();
    }
}

// @fnv 0x00810fd0
int EffectSetting::GetArchetype()
{
    return archetype;
}

// @fnv 0x00804160
void ActiveEffect::Finalize()
{
    if (FUN_007df210() || reinterpret_cast<LowProcess*>(this)->GetActiveCombatTarget())
        AdvanceEffect(0.0f, true);
}

// Reads a count from the buffer, then loads that many ActiveEffect objects and inserts each non-null one into the list.
// @fnv 0x00806a90
void ActiveEffect::LoadActiveEffectList(BGSLoadFormBuffer* buffer, BSSimpleList<ActiveEffect*>* list)
{
    FUN_00806ba0(buffer, list);
    unsigned int count = buffer->ReadElementCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        ActiveEffect* effect = ReadActiveEffect(buffer);
        if (effect)
            list->Insert(effect, MagicTarget::CompareActiveEffects);
    }
}

// @fnv 0x008067b0
void ActiveEffect::ApplyLoadBuffer(BGSLoadFormBuffer* buffer)
{
    BSSimpleList<BGSPerkEntry*>* node;
    if (GetEffectSetting()->IsFlagSet(0x400))
        ResetEffectState();
    node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pHitEffectList);
    while (node)
    {
        MagicHitEffect* effect = reinterpret_cast<MagicHitEffect*>(node->GetItem());
        if (effect)
        {
            reinterpret_cast<MagicHitEffectLoadDispatch*>(effect)->ApplyLoadBuffer(buffer);
            g_011e0e80.RegisterTempEffect(reinterpret_cast<BSTempEffect*>(effect));
        }
        node = node->GetNext();
    }
}

// @fnv 0x00804bc0
void ActiveEffect::SetEffectiveness(float effectiveness)
{
    if (reinterpret_cast<EffectItem*>(reinterpret_cast<MagicCaster*>(this)->GetSelectedMagicItem())
            ->GetEffectSetting()
            ->HasAllFlags(0x180))
        return;
    if (effectiveness == 1.0)
        return;
    if (reinterpret_cast<EffectItem*>(reinterpret_cast<MagicCaster*>(this)->GetSelectedMagicItem())
            ->GetEffectSetting()
            ->IsFlagSet(0x100))
    {
        FUN_00693d50(FUN_007df1f0() * effectiveness);
    }
    else
    {
        FUN_00804cb0(FUN_00404040(GetFloatAtOffset1C() * effectiveness) < 1.0
                         ? 1.0f
                         : FUN_00404040(GetFloatAtOffset1C() * effectiveness));
    }
}

class ActiveEffectLoadGameDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void LoadGame(BGSLoadFormBuffer*);
};

// @fnv 0x00806910
ActiveEffect* ActiveEffect::ReadActiveEffect(BGSLoadFormBuffer* buffer)
{
    // These local names preserve the original MSVC9 stack allocation.
    unsigned int archetype;  // saved spell form ID
    unsigned char index;
    MagicItem* spell = 0;
    int formID;  // serialized effect archetype
    buffer->ReadFormIdentifier(&spell);
    archetype = reinterpret_cast<unsigned int>(spell);
    spell = spell ? MagicItem::GetMagicItemByID(reinterpret_cast<unsigned int>(spell)) : 0;
    index = 0;
    buffer->ReadTypedData(&index, 1);
    formID = buffer->ReadElementCount();
    if (spell)
    {
        EffectItem* effect = spell->effects.GetEffectItemAtIndex(index);
        if (effect && effect->GetEffectSetting()->GetArchetype() == formID)
        {
            buffer->ReadElementCount();
            ActiveEffect* active = MagicEffectSystem::Activate(0, spell, effect, 0);
            reinterpret_cast<ActiveEffectLoadGameDispatch*>(active)->LoadGame(buffer);
            return active;
        }
    }
    reinterpret_cast<ActorPackageContext*>(buffer)->AddToProcedureIndex(buffer->ReadElementCount());
    LogWarning(DAT_010794a8, archetype, index, formID);
    return 0;
}

// @fnv 0x00803d30
ActiveEffect::ActiveEffect(MagicCaster* caster, MagicItem* spell, EffectItem* effect)
{
    pSpell = spell;
    m_eSpellType = pSpell->GetSpellType();
    pEffect = effect;
    m_fEffectMagnitude = 0.0f;
    bActive = true;
    bEffectFlag = false;
    bWasPlaying = false;
    bPickResultFound = false;
    m_fElapsedTime = effect->GetMagnitude();
    fDuration = effect->GetDuration();
    pTarget = 0;
    m_pEffectInstance = caster;
    pSource = 0;
    pHitEffectList = 0;
    iFlags = 0;
    pMagicItem = 0;
    BSSimpleList<const char*>* conditions = reinterpret_cast<BSSimpleList<const char*>*>(
        &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(effect->GetConditions())->GetItem());
    if (effect && conditions && !conditions->IsEmpty())
        AddFlags(0x80);
}

// @fnv 0x008043f0
void ActiveEffect::AdvanceEffect(float elapsed, bool force)
{
    if (!FUN_007df210() && !reinterpret_cast<LowProcess*>(this)->GetActiveCombatTarget())
        return;
    ActiveEffectCasterDispatch* caster =
        reinterpret_cast<ActiveEffectCasterDispatch*>(reinterpret_cast<ActorMover*>(this)->GetCurrentMoveModeType());
    if (caster && caster->GetCasterReference())
    {
        float interval = g_011d17dc.Float()->f;
        bool evaluate = force || floor(GetAge() / interval) != floor((GetAge() + elapsed) / interval);
        if (evaluate)
        {
            bool result = reinterpret_cast<EffectItem*>(reinterpret_cast<MagicCaster*>(this)->GetSelectedMagicItem())
                              ->GetConditions()
                              ->ContainsTrait(caster->GetCasterReference(), 0);
            result &= !IsTerminated();
            if (result && !bActive && bWasPlaying && !bPickResultFound)
            {
                bEffectFlag = false;
                bWasPlaying = false;
            }
            bActive = result;
        }
    }
}

// @fnv 0x00803e80
void ActiveEffect::AddFlags(unsigned int flags)
{
    iFlags |= flags;
}

// @fnv 0x00804b60
bool ActiveEffect::IsFlagged()
{
    return (iFlags & 0x100) != 0;
}

// @fnv 0x00804b80
bool ActiveEffect::HasFlag(unsigned int flags)
{
    return (iFlags & flags) != 0;
}

class ActiveEffectInitLoadGameDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void InitLoadGame(Actor*);
};

// Iterates the ActiveEffect list and calls InitLoadGame(pActor) on each non-null effect.
// @fnv 0x00806b00
void InitLoadGameForEffects(Actor* pActor, BSSimpleList<ActiveEffect*>* pEffectList)
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pEffectList);
    while (node)
    {
        ActiveEffect* item = reinterpret_cast<ActiveEffect*>(node->GetItem());
        if (item)
        {
            reinterpret_cast<ActiveEffectInitLoadGameDispatch*>(item)->InitLoadGame(pActor);
        }
        node = node->GetNext();
    }
}

struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_008041c0_shell : public ActiveEffect
{
    void InitFromSource(TESBoundObject*);
};

int __fastcall _FNV_GetFormType(TESBoundObject*);

// Stores apSource and, if its form type is 0x18 or 0x1A, calls AddFlags with 0x100.
// @fnv 0x008041c0
void FUN_008041c0_shell::InitFromSource(TESBoundObject* apSource)
{
    pSource = apSource;
    if (pSource)
    {
        if (_FNV_GetFormType(pSource) == 0x18 || _FNV_GetFormType(pSource) == 0x1A)
            AddFlags(0x100);
    }
}

struct FUN_00804250_shell : public ActiveEffect
{
    bool HasMatchingActiveEffect();
};

struct AVOStub
{
    virtual void s0();
    virtual void s1();
    virtual int s2(int);
};
struct ListNodeStub
{
    virtual void v0();
    virtual void v1();
    virtual ListNodeStub* s2();
};
struct ListNodeFns
{
    ActiveEffect** _ref_006815c0();
    ListNodeFns* _ref_00726070();
};
// Scans the actor's active-effect list for an effect matching the spell or a potion of the same spell, clearing the result if the actor ignores addiction.
// @fnv 0x00804250
bool FUN_00804250_shell::HasMatchingActiveEffect()
{
    bool bresult = false;
    bool bignoreAddiction = false;
    if (pTarget->IsActor())
    {
        Actor* pactor = (Actor*)pTarget;
        if (pactor)
        {
            if (((AVOStub*)((char*)pactor + 0xa4))->s2(0x48) > 0)
            {
                bignoreAddiction = true;
            }
        }
    }
    SpellItem* pspell = dynamic_cast<SpellItem*>(pSpell);
    if (pMagicItem && ((ActorMover*)this)->GetCurrentMoveModeType())
    {
        ListNodeFns* node = (ListNodeFns*)((ListNodeStub*)((ActorMover*)this)->GetCurrentMoveModeType())->s2();
        while (node && !bresult)
        {
            ActiveEffect* pitem = *node->_ref_006815c0();
            if (pitem && pitem->FUN_00833c20())
            {
                if (pitem->pSpell == pMagicItem)
                {
                    bresult = true;
                }
                else if (pitem->pSpell->GetSpellType() == 7)
                {
                    AlchemyItem* ppotion = dynamic_cast<AlchemyItem*>(pitem->pSpell);
                    if (ppotion && ppotion->FUN_004030b0() == pspell)
                    {
                        bresult = true;
                    }
                }
            }
            node = node->_ref_00726070();
        }
    }
    if (bresult && bignoreAddiction)
        bresult = false;
    return bresult;
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
    void FUN_0087aec0(ActiveEffect*);
};
struct Interface
{
    static bool __cdecl IsSaveLoadActive();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct TSL_008c48d0
{
    static bool __cdecl RemoveSpell(int);
};
struct MagicHitEffectSI
{
    static BSSimpleList<MagicHitEffect*>* __cdecl GetEffectsForActiveEffect(ActiveEffect*);
};
struct ActiveEffectFlagsSI
{
    void ClearFlags(unsigned int);
};
bool __cdecl IsConditionMet();
int __cdecl FUN_0040df90(EffectSetting*);
struct PC7d;
extern PC7d* g_thePlayer;
class ActiveEffectUpdateDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Update(float);
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Start();
    virtual void Slot15();
    virtual void Finish();
};
class ActorDeadQuery
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot3A();
    virtual void Slot3B();
    virtual void Slot3C();
    virtual void Slot3D();
    virtual void Slot3E();
    virtual void Slot3F();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot4A();
    virtual void Slot4B();
    virtual void Slot4C();
    virtual void Slot4D();
    virtual void Slot4E();
    virtual void Slot4F();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot5A();
    virtual void Slot5B();
    virtual void Slot5C();
    virtual void Slot5D();
    virtual void Slot5E();
    virtual void Slot5F();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot6A();
    virtual void Slot6B();
    virtual void Slot6C();
    virtual void Slot6D();
    virtual void Slot6E();
    virtual void Slot6F();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot7A();
    virtual void Slot7B();
    virtual void Slot7C();
    virtual void Slot7D();
    virtual void Slot7E();
    virtual void Slot7F();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot8A();
    virtual bool IsDead(bool);
};
class MagicTargetStatsDispatch
{
  public:
    virtual void vfn_00();
    virtual TESObjectREFR* GetMagicTargetReference();
};
class EffectItemListFoodQuery
{
  public:
    virtual void vfn_00();
    virtual bool HasFoodEffect();
};
class BoundObjectPart
{
  public:
    virtual void vfn_00();
    char data[0x2c];
};
class MagicItemObject : public BoundObjectPart, public MagicItem
{
};

struct ActiveEffectUpdateShell : public ActiveEffect
{
    void FUN_00804560(float afSecondsElapsed);
};

// @fnv 0x00804560
void ActiveEffectUpdateShell::FUN_00804560(float afSecondsElapsed)
{
    if (FUN_007df210() || ((LowProcess*)this)->GetActiveCombatTarget())
        AdvanceEffect(afSecondsElapsed, false);
    if (afSecondsElapsed > 0.0 && !bPickResultFound)
    {
        MagicItem* pspell = (MagicItem*)((ArrSI*)this)->GetFlags();
        MagicTarget* ptarget = (MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType();
        TESObjectREFR* ptargetStatsObject = ((MagicTargetStatsDispatch*)ptarget)->GetMagicTargetReference();
        bool bpermanent = TSL_008c48d0::RemoveSpell(m_eSpellType);
        if (!bEffectFlag && !bWasPlaying && bActive)
        {
            if (ptargetStatsObject == (TESObjectREFR*)g_thePlayer && Interface::IsSaveLoadActive())
                AddFlags(0x20);
            else
                ResetEffectState();
            ((ActiveEffectUpdateDispatch*)this)->Start();
            if (!bPickResultFound && !bWasPlaying)
            {
                if (!HasFlag(1) && !GetEffectSetting()->IsFlagSet(0x8000000))
                {
                    if (m_eSpellType != MagicSystem__SpellType_ABILITY ||
                        (FUN_0040df90(GetEffectSetting()) && GetFloatAtOffset1C() < 100.0))
                    {
                        if (m_eSpellType == MagicSystem__SpellType_ABILITY)
                            AddFlags(4);
                        MagicItemObject* pingredient = pspell->GetSpellType() == MagicSystem__SpellType_WORTCRAFT
                                                           ? static_cast<MagicItemObject*>(pspell)
                                                           : 0;
                        MagicItemObject* ppotion = pspell->GetSpellType() == MagicSystem__SpellType_POTION
                                                       ? static_cast<MagicItemObject*>(pspell)
                                                       : 0;
                        bool bisFood =
                            pingredient
                                ? ((EffectItemListFoodQuery*)&pingredient->effects)->HasFoodEffect()
                                : (ppotion ? ((EffectItemListFoodQuery*)&ppotion->effects)->HasFoodEffect() : false);
                        if (!bisFood)
                        {
                            if (ptargetStatsObject == (TESObjectREFR*)g_thePlayer && Interface::IsSaveLoadActive())
                            {
                                AddFlags(0x40);
                            }
                            else
                            {
                                if (pHitEffectList)
                                {
                                    ((List_009e03e0*)pHitEffectList)->RemoveAll();
                                    delete (List_009e03e0*)pHitEffectList;
                                    pHitEffectList = 0;
                                }
                                if (IsConditionMet())
                                    TaskQueueInterface::GetInstance()->FUN_0087aec0(this);
                                else
                                    pHitEffectList = MagicHitEffectSI::GetEffectsForActiveEffect(this);
                            }
                        }
                    }
                }
                bEffectFlag = true;
            }
        }
        if (!bPickResultFound)
        {
            float fupdateTime = afSecondsElapsed;
            if (!bpermanent && !IsFlagged() && GetAge() + fupdateTime > FUN_007df1f0())
            {
                fupdateTime = FUN_007df1f0() - GetAge();
                m_fEffectMagnitude = FUN_007df1f0();
            }
            else
            {
                m_fEffectMagnitude += afSecondsElapsed;
            }
            if (bActive)
            {
                bool bdeferredHitEffect = HasFlag(0x40);
                bool bdeferredSound = HasFlag(0x20);
                if ((bdeferredHitEffect || bdeferredSound) && ptargetStatsObject == (TESObjectREFR*)g_thePlayer &&
                    !Interface::IsSaveLoadActive())
                {
                    if (bdeferredHitEffect)
                    {
                        if (pHitEffectList)
                        {
                            ((List_009e03e0*)pHitEffectList)->RemoveAll();
                            delete (List_009e03e0*)pHitEffectList;
                            pHitEffectList = 0;
                        }
                        pHitEffectList = MagicHitEffectSI::GetEffectsForActiveEffect(this);
                        ((ActiveEffectFlagsSI*)this)->ClearFlags(0x40);
                    }
                    if (bdeferredSound)
                    {
                        ResetEffectState();
                        ((ActiveEffectFlagsSI*)this)->ClearFlags(0x20);
                    }
                }
                ((ActiveEffectUpdateDispatch*)this)->Update(fupdateTime);
            }
            if (!bpermanent && !IsFlagged())
            {
                if (pEffect->GetEffectSetting()->IsFlagSet(0x80))
                    bPickResultFound = true;
                else if (m_fEffectMagnitude >= FUN_007df1f0())
                    bPickResultFound = true;
            }
            if (pTarget->IsActor())
            {
                Actor* pactor = static_cast<Actor*>(pTarget);
                if (pactor && ((ActorDeadQuery*)pactor)->IsDead(true) && !GetEffectSetting()->IsFlagSet(0x10000000))
                    bPickResultFound = true;
            }
        }
    }
    if (bEffectFlag && (bPickResultFound || !bActive) && !bWasPlaying)
    {
        ((ActiveEffectUpdateDispatch*)this)->Finish();
        bWasPlaying = true;
        if (m_kSoundHandle.IsSoundPlaying())
            m_kSoundHandle.Stop();
    }
}

// @fnv 0x00804cb0
void __fastcall FUN_00804cb0(void* thisPtr, float value)
{
    *(float*)((char*)thisPtr + 0x1c) = value;
}

struct FUN_00805650_shell : ActiveEffect
{
    void FUN_00805650();
};

// @fnv 0x00805650
void FUN_00805650_shell::FUN_00805650()
{
    AddFlags(2);
    AddFlags(4);
}

struct FUN_00803fe0_shell : public ActiveEffect
{
    ActiveEffect* FUN_00803fe0();
};

// ActiveEffect::Copy (v04)
// Allocates a new ActiveEffect from the spell and effect, copies data into it, and returns it.
// @fnv 0x00803fe0
ActiveEffect* FUN_00803fe0_shell::FUN_00803fe0()
{
    ActiveEffect* pNewEffect = new ActiveEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pNewEffect);
    return pNewEffect;
}

class TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00805760_shell : public ActiveEffect
{
    void FUN_00805760(Actor* apActor);
};

// ActiveEffect::FinishLoadGameTES (v2C)
// @fnv 0x00805760
void FUN_00805760_shell::FUN_00805760(Actor* apActor)
{
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x2a)
    {
        BSSimpleList<MagicHitEffect*>* pCurrentElementNext = pHitEffectList;
        while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
        {
            MagicHitEffect* phitEffect = pCurrentElementNext->GetItem();
            phitEffect->FinishLoadGameTES(this, reinterpret_cast<TESObjectREFR*>(apActor), 0);
            g_011e0e80.RegisterTempEffect(phitEffect);
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
    }
    if (GetEffectSetting()->IsFlagSet(0x400))
        ResetEffectState();
}

class TESObjectCELL;
class TESObjectREFR;
struct GO
{
    void* m_pObject;
    GO(int);
    ~GO();
    GO& operator=(void*);
};

struct FUN_0081b650
{
    unsigned int m_uiRefCount;
    float m_fParticleParameter5;
    TESObjectCELL* pCell;
    float m_fFirstFloatValue;
    bool bInitialized;
    ActiveEffect* m_pLinkedEffect;
    TESObjectREFR* pTarget;
    float fWaitingTime;
    unsigned char m_ucEntryType;
    FUN_0081b650();
    virtual ~FUN_0081b650();
};

struct CF_0081c630
{
    CF_0081c630();
};

struct FUN_0081c530 : FUN_0081b650
{
    bool bFlag28;
    bool bFlag29;
    int iState;
    GO spNode30;
    GO spNode34;
    CF_0081c630 kData;
    FUN_0081c530();
    virtual ~FUN_0081c530();
};

// Initializes the two node handles to null, clears both flags, and sets iState to 0.
// @fnv 0x0081c530
FUN_0081c530::FUN_0081c530() : spNode30(0), spNode34(0)
{
    spNode30 = 0;
    spNode34 = 0;
    bFlag29 = false;
    iState = 0;
    bFlag28 = false;
}

namespace fnv_0081f220 {
class TESObjectCELL;
class TESObjectREFR;

struct FUN_0081b650
{
    unsigned int m_uiRefCount;
    float m_fParticleParameter5;
    TESObjectCELL* pCell;
    float m_fFirstFloatValue;
    bool bInitialized;
    ActiveEffect* m_pLinkedEffect;
    TESObjectREFR* pTarget;
    float fWaitingTime;
    unsigned char m_ucEntryType;
    FUN_0081b650();
    virtual ~FUN_0081b650();
};

struct GO
{
    void* m_pObject;
    GO(int);
    ~GO();
    GO& operator=(void*);
};

struct FUN_00822530
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
    FUN_00822530();
    ~FUN_00822530();
};

struct FUN_00822580
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    FUN_00822580();
    virtual ~FUN_00822580();
};

struct FUN_0081f220 : FUN_0081b650
{
    bool bFlag28;
    int iState;
    void* m_kModelObjectsItem;
    float m_fPackageValue;
    FUN_00822530 kEffects;
    GO spNode48;
    bool bFlag4C;
    FUN_00822580 kObjects;
    float fScale60;
    float fScale64;
    GO spNode68;
    FUN_0081f220();
    virtual ~FUN_0081f220();
};

// Initializes the object's fields: clears pointers and flags, sets state to 0, and sets both scale fields to 1.0.
// @fnv 0x0081f220
FUN_0081f220::FUN_0081f220() : spNode48(0), spNode68(0)
{
    m_kModelObjectsItem = 0;
    spNode68 = 0;
    m_fPackageValue = 0.0f;
    spNode48 = 0;
    bFlag28 = false;
    iState = 0;
    bFlag4C = false;
    fScale60 = 1.0f;
    fScale64 = 1.0f;
}
}  // namespace fnv_0081f220

namespace fnv_00804210 {
class ActiveEffectUpdateShell
{
  public:
    virtual ~ActiveEffectUpdateShell();
    virtual ActiveEffectUpdateShell* Copy();
    virtual void Finalize();
    virtual void Update(float afElapsedSeconds);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(Actor* apActor);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(Actor* apActor);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
    virtual bool CanApply(MagicCaster* apCaster);
    virtual bool CanFinish();
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
    virtual void CopyData(ActiveEffectUpdateShell* apOther);
    virtual bool CanCast(MagicCaster* apCaster);
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();
    virtual void Continue();
    virtual void Finish();
    ActiveEffectUpdateShell(MagicCaster*, MagicItem*, EffectItem*);
    void AddFlags(unsigned int);
    void UpdateEffect(float);
    void Remove(bool abNow);
    float m_fEffectMagnitude;
    MagicItem* pSpell;
    EffectItem* pEffect;
    bool bActive;
    bool bEffectFlag;
    bool bWasPlaying;
    bool bPickResultFound;
    bool m_bEffectState;
    unsigned char layoutPadding15[3];
    int iFlags;
    float m_fElapsedTime;
    float fDuration;
    MagicTarget* pTarget;
    MagicCaster* m_pEffectInstance;
    MagicSystem__SpellType m_eSpellType;
    SoundPlaybackHandle m_kSoundHandle;
    TESBoundObject* pSource;
    BSSimpleList<MagicHitEffect*>* pHitEffectList;
    MagicItem* pMagicItem;
};

// @fnv 0x00804210
void ActiveEffectUpdateShell::Remove(bool abNow)
{
    bPickResultFound = true;
    AddFlags(0x200);
    if (abNow)
    {
        UpdateEffect(0.0f);
    }
}
}  // namespace fnv_00804210

struct FUN_00804ba0_shell
{
    unsigned int m_auiShapeKeys[6];
    unsigned int m_flags;
    void ClearFlags(unsigned int mask);
};

// @fnv 0x00804ba0
void FUN_00804ba0_shell::ClearFlags(unsigned int mask)
{
    m_flags &= ~mask;
}

struct ListProxy008060e0
{
    bool _ref_008256d0();
    ActiveEffect*& _ref_006815c0();
    BSSimpleList<ActiveEffect*>* _ref_00726070();
};
struct VProxy008060e0
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10(BGSLoadFormBuffer*);
};
// @fnv 0x008060e0
void FUN_008060e0(BSSimpleList<ActiveEffect*>* apActiveEffectList, BGSLoadFormBuffer* apLoadGameBuffer)
{
    ActiveEffect* pEffect;
    while (apActiveEffectList && !((ListProxy008060e0*)apActiveEffectList)->_ref_008256d0())
    {
        pEffect = ((ListProxy008060e0*)apActiveEffectList)->_ref_006815c0();
        ((VProxy008060e0*)pEffect)->f10(apLoadGameBuffer);
        apActiveEffectList = ((ListProxy008060e0*)apActiveEffectList)->_ref_00726070();
    }
}

struct Item008061b0
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13(void* p);
};
struct Node008061b0
{
    bool _ref_008256d0();
    Item008061b0** _ref_006815c0();
    Node008061b0* _ref_00726070();
};
// Walks the node chain from a, calling s13(b) on each node's item until a node satisfies _ref_008256d0 or the chain ends.
// @fnv 0x008061b0
void FUN_008061b0(Node008061b0* pNode, void* b)
{
    while (pNode && !pNode->_ref_008256d0())
    {
        Item008061b0* item = *pNode->_ref_006815c0();
        item->s13(b);
        pNode = pNode->_ref_00726070();
    }
}

struct StandIn00806200
{
    char gap[40];
    MagicCaster* m_pEffectInstance;
    bool ClearCasterIfMatch(MagicCaster* apCaster);
};
// Clears the stored MagicCaster pointer if it equals apCaster and returns whether it matched.
// @fnv 0x00806200
bool StandIn00806200::ClearCasterIfMatch(MagicCaster* apCaster)
{
    bool bMatched = 0;
    if (apCaster == m_pEffectInstance)
    {
        m_pEffectInstance = 0;
        bMatched = 1;
    }
    return bMatched;
}

struct BGSSaveFormBuffer
{
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
void FUN_00806840(BGSSaveFormBuffer*, BGSPerkEntry*);

// @fnv 0x00806a10
void FUN_00806a10(BGSSaveFormBuffer* pBuffer, BSSimpleList<BGSPerkEntry*>* pPerkList)
{
    int count = 0;
    unsigned int size = pBuffer->FUN_00865f20();
    BSSimpleList<BGSPerkEntry*>* pCurrent = pPerkList;
    while (pCurrent)
    {
        BGSPerkEntry* pEntry = pCurrent->GetItem();
        if (pEntry)
        {
            FUN_00806840(pBuffer, pEntry);
            ++count;
        }
        pCurrent = pCurrent->GetNext();
    }
    pBuffer->FUN_00865ff0(count, size);
}

struct SaveManager
{
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;

// @fnv 0x00805810
unsigned short FUN_00805810(void* pObject, void* pArg)
{
    unsigned short result = 0;

    if (DAT_011de45c->FUN_008df040() >= 0x2a)
        result += 2;

    result += 4;
    result += 1;

    result += ((unsigned short(__thiscall*)(void*, void*))((*(void***)pObject)[4]))(pObject, pArg);

    return result;
}

struct ChangeFlagBytes
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
struct SaveChangeHeader
{
    unsigned int formID;
    unsigned char formType;
    ChangeFlagBytes changeFlags;
};
struct SaveLoadGameStub
{
    bool FUN_00862110();
    SaveChangeHeader* GetCurrentChangeHeader();
};
extern SaveLoadGameStub* g_pSaveLoadGameStub;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct SaveSizeForm
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual const char* GetEditorName();
};
SaveSizeForm* LookupFormByNumericID(unsigned int id);
unsigned short FUN_00805810(void* pObject, void* pArg);
void __cdecl DebugSaveSizeOutput(const char* fmt, ...);

struct SaveSizeListNode
{
    bool _ref_008256d0();
    void** _ref_006815c0();
    SaveSizeListNode* _ref_00726070();
};

// Computes a save size by adding fixed header bytes and per-node sizes from FUN_00805810, optionally logging the delta and current form header.
// @fnv 0x00805a00
unsigned short FUN_00805a00(SaveSizeListNode* pNodeList, void* pArg)
{
    unsigned short uiSize = 0;
    unsigned short uiStart = uiSize;
    if (g_pSaveLoadGameStub->FUN_00862110())
    {
        uiSize += 4;
        uiSize += 2;
    }
    uiSize += 2;
    while (pNodeList && !pNodeList->_ref_008256d0())
    {
        uiSize += FUN_00805810(*pNodeList->_ref_006815c0(), pArg);
        pNodeList = pNodeList->_ref_00726070();
    }
    if (*g_011de4e8.Bool())
    {
        SaveChangeHeader* pHeader = g_pSaveLoadGameStub->GetCurrentChangeHeader();
        if (pHeader)
        {
            SaveSizeForm* pForm = LookupFormByNumericID(pHeader->formID);
            DebugSaveSizeOutput("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                                uiSize - uiStart, pHeader->formID, pForm->GetEditorName(),
                                *(unsigned int*)&pHeader->changeFlags, 968,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
        else
        {
            DebugSaveSizeOutput("GetSaveSize(): %-5i ending at line %i in file %s", uiSize - uiStart, 968,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
    }
    return uiSize;
}

template <int N> struct VirtualSlotTag
{
};
template <int N> struct OpaqueVirtualInterface : OpaqueVirtualInterface<N - 1>
{
    virtual void UnresolvedVirtual(VirtualSlotTag<N>*);
};
template <> struct OpaqueVirtualInterface<0>
{
    virtual void UnresolvedVirtual(VirtualSlotTag<0>*);
};
struct DispatchActor : OpaqueVirtualInterface<351>
{
    virtual void Refresh(int, int, int);
};
struct ActorBridge
{
    DispatchActor* FUN_008d8520();
};
struct ActiveEffectListBridge
{
    bool FUN_008256d0();
    ActiveEffect** FUN_006815c0();
    ActiveEffectListBridge* FUN_00726070();
};
// @fnv 0x00806130
void __cdecl FUN_00806130(ActiveEffectListBridge* pEffectList, ActorBridge* pActorBridge)
{
    while (pEffectList != 0 && !pEffectList->FUN_008256d0())
    {
        ActiveEffect* effect = *pEffectList->FUN_006815c0();
        effect->FinishLoadGameTES(reinterpret_cast<Actor*>(pActorBridge));
        pEffectList = pEffectList->FUN_00726070();
    }
    if (pActorBridge != 0)
    {
        if (pActorBridge->FUN_008d8520())
        {
            DispatchActor* dispatcher = pActorBridge->FUN_008d8520();
            dispatcher->Refresh(1, 1, 1);
        }
    }
}

// MagicHitEffect-style constructor (no arguments): calls the BSTempEffect base
// constructor with (null cell, 0.0f), stores the derived vtable, clears the
// target/effect pointers and age, sets lifetime from a global constant and
// clears the finished flag. Returns this.

class TESObjectCELL;
class TESObjectREFR;
class ActiveEffect;

extern float DAT_01016970;

struct BSTempEffectBase_stub
{
    virtual void Slot00();
    unsigned int unk04;
    float m_fParticleParameter5;
    TESObjectCELL* pCell;
    float m_fFirstFloatValue;
    unsigned int unk14;

    BSTempEffectBase_stub(TESObjectCELL* apCell, float afLifetime);
};

struct FUN_0081b650_cls : BSTempEffectBase_stub
{
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    float fAgeDerived;
    unsigned char bWasPlaying;

    FUN_0081b650_cls();
};

// @fnv 0x0081b650
FUN_0081b650_cls::FUN_0081b650_cls() : BSTempEffectBase_stub(0, 0.0f)
{
    pTarget = 0;
    pEffect = 0;
    fAgeDerived = 0.0f;
    m_fParticleParameter5 = DAT_01016970;
    bWasPlaying = 0;
}

struct AudioPlaybackHandle
{
    AudioPlaybackHandle();
    ~AudioPlaybackHandle();
    void __thiscall FUN_00418900(AudioPlaybackHandle* other);
    bool __thiscall SetPos(float x, float y, float z);
    bool __thiscall Play(int b);
    bool __thiscall FUN_00ad8ce0();
    void __thiscall FUN_00ad88f0();
    void __thiscall FUN_00ad8d10();
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char pad5a;
    unsigned char pad5b;
    unsigned char pad5c;
    int eState;
};
struct SoundData36
{
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int f24;
    int f28;
    int f32;
};
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct MidObj
{
    int __thiscall FUN_0084e3a0();
    SoundData36 __thiscall CopyBig();
};
struct EffSetting
{
    MidObj* __thiscall FUN_004fd3e0();
    bool __thiscall FUN_00403e60(unsigned int n);
};
struct Obj14
{
    AudioPlaybackHandle __thiscall PlaySoundByFormID(int a, int b, int c, int d);
};
struct ObjC
{
    virtual void M000();
    virtual void M001();
    virtual void M002();
    virtual void M003();
    virtual void M004();
    virtual void M005();
    virtual void M006();
    virtual void M007();
    virtual void M008();
    virtual void M009();
    virtual void M010();
    virtual void M011();
    virtual void M012();
    virtual void M013();
    virtual void M014();
    virtual void M015();
    virtual void M016();
    virtual void M017();
    virtual void M018();
    virtual void M019();
    virtual void M020();
    virtual void M021();
    virtual void M022();
    virtual void M023();
    virtual void M024();
    virtual void M025();
    virtual void M026();
    virtual void M027();
    virtual void M028();
    virtual void M029();
    virtual void M030();
    virtual void M031();
    virtual void M032();
    virtual void M033();
    virtual void M034();
    virtual void M035();
    virtual void M036();
    virtual void M037();
    virtual void M038();
    virtual void M039();
    virtual void M040();
    virtual void M041();
    virtual void M042();
    virtual void M043();
    virtual void M044();
    virtual void M045();
    virtual void M046();
    virtual void M047();
    virtual void M048();
    virtual void M049();
    virtual void M050();
    virtual void M051();
    virtual void M052();
    virtual void M053();
    virtual void M054();
    virtual void M055();
    virtual void M056();
    virtual void M057();
    virtual void M058();
    virtual void M059();
    virtual void M060();
    virtual void M061();
    virtual void M062();
    virtual void M063();
    virtual void M064();
    virtual void M065();
    virtual void M066();
    virtual void M067();
    virtual void M068();
    virtual void M069();
    virtual void M070();
    virtual void M071();
    virtual void M072();
    virtual void M073();
    virtual void M074();
    virtual void M075();
    virtual void M076();
    virtual void M077();
    virtual void M078();
    virtual void M079();
    virtual void M080();
    virtual void M081();
    virtual void M082();
    virtual void M083();
    virtual void M084();
    virtual void M085();
    virtual void M086();
    virtual void M087();
    virtual void M088();
    virtual void M089();
    virtual void M090();
    virtual void M091();
    virtual void M092();
    virtual void M093();
    virtual void M094();
    virtual void M095();
    virtual void M096();
    virtual void M097();
    virtual void M098();
    virtual void M099();
    virtual void M100();
    virtual void M101();
    virtual void M102();
    virtual void M103();
    virtual void M104();
    virtual void M105();
    virtual void M106();
    virtual void M107();
    virtual void M108();
    virtual void M109();
    virtual void M110();
    virtual void M111();
    virtual void M112();
    virtual void M113();
    virtual void M114();
    virtual void M115();
    virtual void M116();
    virtual void M117();
    virtual void M118();
    virtual void M119();
    virtual void M120();
    virtual void M121();
    virtual void M122();
    virtual void M123();
    virtual void M124();
    virtual NiPoint3* GetPoint1f4();
};
struct ObjB
{
    virtual void FirstVirtual();
    virtual ObjC* GetObjC();
    Obj14* __thiscall FUN_00822b40();
};
struct Obj80
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void A4();
    virtual void A5();
    virtual int GetVal18();
};
struct AudioSys
{
    AudioPlaybackHandle __thiscall FUN_00ad73b0(int a, int b);
};
AudioSys* __cdecl FUN_00453a70();
void* __cdecl GetFlagMask(int v);
struct Self
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    AudioPlaybackHandle sound30;
    EffSetting* __thiscall FUN_007df1d0();
    ObjB* __thiscall FUN_0059bb30();
    Obj80* __thiscall FUN_0044ddc0();
    void __thiscall PlaySoundForEffect();
};

// @fnv 0x00804cd0
void __thiscall Self::PlaySoundForEffect()
{
    int var10_2;
    Obj14* var4;
    bool flag_;
    var10_2 = FUN_007df1d0()->FUN_004fd3e0() ? FUN_007df1d0()->FUN_004fd3e0()->FUN_0084e3a0() : 0;
    if (var10_2 != 0)
    {
        if (FUN_0059bb30())
        {
            if (FUN_0044ddc0()->GetVal18() != 4)
            {
                AudioPlaybackHandle sound8;
                var4 = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
                flag_ = FUN_007df1d0()->FUN_00403e60(0x400);
                if (FUN_007df1d0()->FUN_004fd3e0())
                {
                    flag_ = GetFlagMask(FUN_007df1d0()->FUN_004fd3e0()->CopyBig().f4) ? true : false;
                }
                if (var4)
                {
                    int mode8;
                    mode8 = flag_ ? 0x112 : 0x102;
                    sound8.FUN_00418900(&var4->PlaySoundByFormID(var10_2, flag_, mode8, 0));
                }
                else
                {
                    ObjC* objC2;
                    objC2 = FUN_0059bb30()->GetObjC();
                    if (objC2)
                    {
                        NiPoint3 pt5;
                        AudioPlaybackHandle sound2 = FUN_00453a70()->FUN_00ad73b0(var10_2, 0x102);
                        pt5 = *objC2->GetPoint1f4();
                        sound2.SetPos(pt5.x, pt5.y, pt5.z);
                        sound2.Play(flag_);
                    }
                }
                if (flag_)
                {
                    if (sound30.FUN_00ad8ce0())
                    {
                        sound30.FUN_00ad88f0();
                        sound30.FUN_00ad8d10();
                    }
                    sound30.FUN_00418900(&sound8);
                }
            }
        }
    }
}

class MagicHitEffectSaveDispatch
{
  public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual unsigned short GetSaveSize(ActiveEffect*, Actor*);
};

struct FUN_00804f80_shell : public ActiveEffect
{
    unsigned short FUN_00804f80(Actor* apActor);
};

// @fnv 0x00804f80
unsigned short FUN_00804f80_shell::FUN_00804f80(Actor* apActor)
{
    unsigned short usSize = 0;
    usSize += 4;
    usSize += 1;
    usSize += 1;
    usSize += 1;
    usSize += 1;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 42)
    {
        usSize += 1;
        BSSimpleList<MagicHitEffect*>* pIter = pHitEffectList;
        while (pIter && !pIter->IsEmpty())
        {
            MagicHitEffect* pHit = pIter->GetItem();
            usSize += 1;
            usSize += ((MagicHitEffectSaveDispatch*)pHit)->GetSaveSize(this, apActor);
            pIter = pIter->GetNext();
        }
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 72)
    {
        usSize += 4;
    }
    else if (g_TESSaveLoadGame->FUN_008df040() >= 65)
    {
        char b = 0;
        usSize += 1;
    }
    return usSize;
}

struct EffectSaveStream : SaveManager
{
    void FUN_008579b0(void*, unsigned int);
    void FUN_00857a10(void*, unsigned int);
    unsigned char* FUN_00825c00();
};
struct CasterSaveID
{
    unsigned int FUN_00818be0();
};
struct TargetSaveID
{
    unsigned int RefreshItem();
};
struct SourceSaveID
{
    unsigned int FUN_0084e3a0();
};
struct HitEffectSaveDispatch : OpaqueVirtualInterface<38>
{
    virtual unsigned char GetType();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void SaveGame(ActiveEffect*, Actor*);
};
struct HitEffectSaveNode
{
    bool FUN_008256d0();
    HitEffectSaveDispatch** FUN_006815c0();
    HitEffectSaveNode* FUN_00726070();
};
struct EffectSaveShell : ActiveEffect
{
    void FUN_008050d0(Actor* actor);
};
// @fnv 0x008050d0
void EffectSaveShell::FUN_008050d0(Actor* actor)
{
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&m_fEffectMagnitude, 4);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&bActive, 1);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&bEffectFlag, 1);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&bWasPlaying, 1);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&bPickResultFound, 1);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&m_bEffectState, 1);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&m_fElapsedTime, 4);
    ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&fDuration, 4);
    unsigned int casterID = 0;
    if (m_pEffectInstance)
        casterID = ((CasterSaveID*)m_pEffectInstance)->FUN_00818be0();
    ((EffectSaveStream*)DAT_011de45c)->FUN_00857a10(&casterID, 4);
    unsigned int targetID = 0;
    if (pTarget)
        targetID = ((TargetSaveID*)pTarget)->RefreshItem();
    ((EffectSaveStream*)DAT_011de45c)->FUN_00857a10(&targetID, 4);
    unsigned int sourceID = 0;
    if (pSource)
        sourceID = ((SourceSaveID*)pSource)->FUN_0084e3a0();
    ((EffectSaveStream*)DAT_011de45c)->FUN_00857a10(&sourceID, 4);
    {
        // Local identifiers preserve the original MSVC9 stack allocation.
        unsigned char a;           // hit-effect count
        HitEffectSaveNode* b;      // current list node
        unsigned char c;           // hit-effect type
        HitEffectSaveDispatch* d;  // current hit effect
        bool e;                    // legacy flag
        unsigned char* f;          // saved count position
        if (DAT_011de45c->FUN_008df040() >= 42)
        {
            a = 0;
            f = ((EffectSaveStream*)DAT_011de45c)->FUN_00825c00();
            ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&a, 1);
            b = (HitEffectSaveNode*)pHitEffectList;
            while (b && !b->FUN_008256d0())
            {
                d = *b->FUN_006815c0();
                c = d->GetType();
                ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&c, 1);
                d->SaveGame(this, actor);
                ++a;
                b = b->FUN_00726070();
            }
            *f = a;
        }
        if (DAT_011de45c->FUN_008df040() >= 72)
        {
            ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&iFlags, 4);
        }
        else if (DAT_011de45c->FUN_008df040() >= 65)
        {
            e = HasFlag(1);
            ((EffectSaveStream*)DAT_011de45c)->FUN_008579b0(&e, 1);
        }
    }
}

struct ActiveEffectLoader : FUN_00805650_shell
{
    void FUN_00805330(Actor* actor);
};
struct EffectSaveReader
{
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857aa0(unsigned int*, unsigned int);
    unsigned char FUN_008df040();
};
struct ShaderHitEffect : FUN_0081c530
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ShaderHitEffect();
};
struct ModelHitEffect : MagicHitEffect
{
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ModelHitEffect();
};
struct HitEffectList : BSSimpleList<MagicHitEffect*>
{
    HitEffectList(MagicHitEffect*&);
    void AddHead(MagicHitEffect*&);
};
extern const char hitEffectLoadWarning[];
void __cdecl HitEffectWarning(const char*, ...);
// Reads an active magic effect's fields from the save stream, recreates its hit effects, and reads flags or a version-gated byte.
// @fnv 0x00805330
void ActiveEffectLoader::FUN_00805330(Actor* actor)
{
    // Local identifiers and declaration order preserve MSVC9 stack slots.
    unsigned int b;     // Hit-effect index.
    unsigned int a;     // Serialized caster form ID.
    unsigned char c;    // Saved hit-effect type.
    unsigned char e;    // Legacy flag byte.
    unsigned int f;     // Serialized source form ID.
    MagicHitEffect* d;  // Hit effect being restored.
    unsigned char g;    // Number of saved hit effects.
    unsigned int h;     // Serialized target form ID.
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&m_fEffectMagnitude, 4);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&bActive, 1);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&bEffectFlag, 1);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&bWasPlaying, 1);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&bPickResultFound, 1);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&m_bEffectState, 1);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&m_fElapsedTime, 4);
    ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&fDuration, 4);
    ((EffectSaveReader*)DAT_011de45c)->FUN_00857aa0(&a, 4);
    m_pEffectInstance = (MagicCaster*)a;
    ((EffectSaveReader*)DAT_011de45c)->FUN_00857aa0(&h, 4);
    pTarget = (MagicTarget*)h;
    ((EffectSaveReader*)DAT_011de45c)->FUN_00857aa0(&f, 4);
    pSource = (TESBoundObject*)f;
    if (((EffectSaveReader*)DAT_011de45c)->FUN_008df040() >= 42)
    {
        ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&g, 1);
        for (b = 0; b < g; ++b)
        {
            ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&c, 1);
            d = 0;
            switch (c)
            {
            case 5:
                d = (MagicHitEffect*)new ShaderHitEffect;
                break;
            case 6:
                d = new ModelHitEffect;
                break;
            default:
                HitEffectWarning(hitEffectLoadWarning, c);
                break;
            }
            d->LoadGame(this, (TESObjectREFR*)actor);
            if (!pHitEffectList)
                pHitEffectList = new HitEffectList(d);
            else
                ((HitEffectList*)pHitEffectList)->AddHead(d);
        }
    }
    if (((EffectSaveReader*)DAT_011de45c)->FUN_008df040() >= 72)
        ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&iFlags, 4);
    else if (((EffectSaveReader*)DAT_011de45c)->FUN_008df040() >= 65)
    {
        ((EffectSaveReader*)DAT_011de45c)->FUN_008579e0(&e, 1);
        if (e)
            FUN_00805650();
    }
}

class SaveSub
{
  public:
    unsigned char CheckValue(unsigned int v);
};

class SaveOwner
{
  public:
    unsigned int GetKey();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SaveSub sub;
};

class SaveWriter
{
  public:
    void WriteBytes(const void* pData, unsigned int size);
    void WriteDwordBytes(const void* pData, unsigned int size);
};

class SaveEffectObj
{
  public:
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual unsigned short GetSaveWord(unsigned int arg);
    virtual void vfn05();
    virtual void SaveData(unsigned int arg);
    unsigned int m_04;
    SaveOwner* m_08;
    unsigned int m_0c;
};

// Writes the effect's save word (version >= 0x2a), owner key, a checked flag byte, then calls SaveData.
// @fnv 0x00805880
void SaveEffectData(SaveEffectObj* pEffect, unsigned int arg)
{
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x2a)
    {
        unsigned short usSaveWord = pEffect->GetSaveWord(arg);
        reinterpret_cast<SaveWriter*>(g_TESSaveLoadGame)->WriteBytes(&usSaveWord, 2);
    }
    unsigned int uiOwnerKey = pEffect->m_08->GetKey();
    reinterpret_cast<SaveWriter*>(g_TESSaveLoadGame)->WriteDwordBytes(&uiOwnerKey, 4);
    unsigned char ucCheckFlag = pEffect->m_08->sub.CheckValue(pEffect->m_0c);
    reinterpret_cast<SaveWriter*>(g_TESSaveLoadGame)->WriteBytes(&ucCheckFlag, 1);
    pEffect->SaveData(arg);
}

namespace fnv_00805b40 {
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct FormIDEntry
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flagsLo;
};
class SaveLoadMgr
{
  public:
    char* GetBufferPos();
    bool IsSaving();
    void Write(void* apData, int aiSize);
    FormIDEntry* GetCurrentForm();
};
extern SaveLoadMgr* g_SaveLoadMgr;
struct SaveForm
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual const char* GetName();
};
SaveForm* LookupFormByID(unsigned int id);
void SaveGameLog(const char* fmt, ...);
void SaveGameWarning2(const char* fmt, ...);
struct AENode
{
    bool IsEmpty();
    ActiveEffect*& GetItem();
    AENode* GetNext();
};
void ProcessActiveEffect(ActiveEffect* apEffect, Actor* apActor);

// Serializes the active-effect list for an actor, writing a block marker and size, counting entries, and logging the block size when debug output is enabled.
// @fnv 0x00805b40
void FUN_00805b40(AENode* apList, Actor* apActor)
{
    unsigned short usZero6 = 0;
    char* pSizePos8 = 0;
    char* pStart4 = g_SaveLoadMgr->GetBufferPos();
    if (*g_011de4e8.Bool())
        pStart4 = g_SaveLoadMgr->GetBufferPos();
    if (g_SaveLoadMgr->IsSaving())
    {
        unsigned int uiMarker = 0x424c4f4b;
        g_SaveLoadMgr->Write(&uiMarker, 4);
        pSizePos8 = g_SaveLoadMgr->GetBufferPos();
        g_SaveLoadMgr->Write(&usZero6, 2);
    }
    unsigned short usCount2 = 0;
    char* pCountPos3 = g_SaveLoadMgr->GetBufferPos();
    g_SaveLoadMgr->Write(&usCount2, 2);
    while (apList && !apList->IsEmpty())
    {
        ProcessActiveEffect(apList->GetItem(), apActor);
        usCount2++;
        apList = apList->GetNext();
    }
    *(unsigned short*)pCountPos3 = usCount2;
    if (*g_011de4e8.Bool())
    {
        char* pEnd6 = g_SaveLoadMgr->GetBufferPos();
        FormIDEntry* pHeader2 = g_SaveLoadMgr->GetCurrentForm();
        if (pHeader2)
        {
            SaveForm* pForm = LookupFormByID(pHeader2->formID);
            SaveGameLog("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                        pEnd6 - pStart4, pHeader2->formID, pForm->GetName(), *(unsigned int*)&pHeader2->flagsLo, 992,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
        else
        {
            SaveGameLog("SaveGame(): %-5i ending at line %i in file %s", pEnd6 - pStart4, 992,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
    }
    if (g_SaveLoadMgr->IsSaving())
    {
        char* pCur = g_SaveLoadMgr->GetBufferPos();
        {
            char* pBlockStart = pSizePos8;
            if (pCur > pBlockStart + 0xffff)
                SaveGameWarning2("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 992);
            *(unsigned short*)pSizePos8 = pCur - pBlockStart;
        }
    }
}
}  // namespace fnv_00805b40

struct SaveFormBuf : public BGSSaveFormBuffer
{
    void SaveData(void* apData, unsigned int auiSize, int aiFlags);
    void SerializeFormData(unsigned int auiFormID, unsigned int auiFlags);
    void SaveFormPtr(void* apForm, int aiFlags);
};

struct CasterIDShell : public MagicCaster
{
    unsigned int GetNumericID();
};
struct TargetIDShell : public MagicTarget
{
    unsigned int GetNumericID();
};
struct SpellIDShell : public MagicItem
{
    unsigned int GetNumericID();
};

struct SaveHitEffect
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual int GetType();
    virtual void s28();
    virtual void s29();
    virtual void SaveGame(SaveFormBuf* apBuffer);
};

struct SaveHitNode
{
    SaveHitEffect*& GetItem();
    SaveHitNode* GetNext();
};

struct ActiveEffectSaveShell : public ActiveEffect
{
    void FUN_00806230(SaveFormBuf* apBuffer);
};

// Serializes the active effect's fields, caster/target/spell IDs, source form and hit effects into the save buffer.
// @fnv 0x00806230
void ActiveEffectSaveShell::FUN_00806230(SaveFormBuf* apBuffer)
{
    apBuffer->SaveData(&m_fEffectMagnitude, 4, 0);
    apBuffer->SaveData(&bActive, 1, 0);
    apBuffer->SaveData(&bEffectFlag, 1, 0);
    apBuffer->SaveData(&bWasPlaying, 1, 0);
    apBuffer->SaveData(&bPickResultFound, 1, 0);
    apBuffer->SaveData(&m_bEffectState, 1, 0);
    apBuffer->SaveData(&m_fElapsedTime, 4, 0);
    apBuffer->SaveData(&fDuration, 4, 0);
    apBuffer->SaveData(&iFlags, 4, 0);
    apBuffer->SerializeFormData(m_pEffectInstance ? ((CasterIDShell*)m_pEffectInstance)->GetNumericID() : 0, 0);
    apBuffer->SerializeFormData(pTarget ? ((TargetIDShell*)pTarget)->GetNumericID() : 0, 0);
    apBuffer->SerializeFormData(pMagicItem ? ((SpellIDShell*)pMagicItem)->GetNumericID() : 0, 0);
    apBuffer->SaveFormPtr(pSource, 0);
    int iCount7 = 0;
    unsigned int uiOffset2 = apBuffer->FUN_00865f20();
    SaveHitNode* pNode = (SaveHitNode*)pHitEffectList;
    while (pNode)
    {
        SaveHitEffect* pHit2 = pNode->GetItem();
        if (pHit2)
        {
            char cType = (char)pHit2->GetType();
            apBuffer->SaveData(&cType, 1, 0);
            pHit2->SaveGame(apBuffer);
            iCount7++;
        }
        pNode = pNode->GetNext();
    }
    apBuffer->FUN_00865ff0(iCount7, uiOffset2);
}

class B806840EffectItem;

class B806840EffectSetting
{
  public:
    int GetArchetype();
};

class B806840EffectItem
{
  public:
    B806840EffectSetting* GetEffectSetting();
};

class B806840EffectList
{
  public:
    bool Contains(B806840EffectItem* pkItem);
};

class B806840MagicItem
{
  public:
    unsigned int GetFormID();

    int unk00;
    int unk04;
    int unk08;
    B806840EffectList m_kEffects;
};

class B806840SaveBuffer
{
  public:
    void SerializeFormData(unsigned int auiFormId, unsigned int uiFlags);
    void SaveData(void* pvData, int iSize, int iFlags);
    void SaveInt(unsigned int uiValue);
    unsigned int BeginChunk();
    int GetOffset();
    void EndChunk(int iSize, unsigned int uiChunk);
};

class B806840ActiveEffect
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void SaveGame(B806840SaveBuffer* pkBuffer);

    int unk04;
    B806840MagicItem* m_pkMagicItem;
    B806840EffectItem* m_pkEffectItem;
};

// @fnv 0x00806840
void __cdecl FUN_00806840(B806840SaveBuffer* pkBuffer, B806840ActiveEffect* pkEffect)
{
    pkBuffer->SerializeFormData(pkEffect->m_pkMagicItem ? pkEffect->m_pkMagicItem->GetFormID() : 0, 0);
    bool bInList2 = pkEffect->m_pkMagicItem->m_kEffects.Contains(pkEffect->m_pkEffectItem);
    pkBuffer->SaveData(&bInList2, 1, 0);
    int eArchetype2 = pkEffect->m_pkEffectItem->GetEffectSetting()->GetArchetype();
    pkBuffer->SaveInt(eArchetype2);
    unsigned int uiChunk = pkBuffer->BeginChunk();
    int iStart2 = pkBuffer->GetOffset();
    pkEffect->SaveGame(pkBuffer);
    int iEnd = pkBuffer->GetOffset();
    pkBuffer->EndChunk(iEnd - iStart2, uiChunk);
}

struct FUN_00803ea0
{
    virtual ~FUN_00803ea0();
};
// @fnv 0x00803ea0
FUN_00803ea0::~FUN_00803ea0()
{}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESBoundObject : public TESForm
{
};
TESForm* LookupFormByID(unsigned int id);
MagicCaster* FUN_00818c60(MagicCaster* pkCaster);
MagicTarget* FUN_00825550(MagicTarget* pkTarget);

struct ActiveEffect805670 : ActiveEffect
{
    void FUN_00805670(Actor* apActor);
};
// @fnv 0x00805670
void ActiveEffect805670::FUN_00805670(Actor* apActor)
{
    MagicTarget* pkTarget;
    MagicCaster* pkCaster;
    TESBoundObject* source;
    pkCaster = m_pEffectInstance;
    if (pkCaster)
        m_pEffectInstance = FUN_00818c60(pkCaster);
    pkTarget = pTarget;
    if (pkTarget)
        pTarget = FUN_00825550(pkTarget);
    source = pSource;
    if (pkTarget)
        pSource = dynamic_cast<TESBoundObject*>(LookupFormByID((unsigned int)source));
    if (DAT_011de45c->FUN_008df040() >= 0x2a)
    {
        BSSimpleList<MagicHitEffect*>* it = pHitEffectList;
        while (it && !it->IsEmpty())
        {
            MagicHitEffect* hit = it->GetItem();
            hit->InitLoadGame(this, (TESObjectREFR*)apActor);
            it = it->GetNext();
        }
    }
}

struct BufShell806420
{
    unsigned int FUN_008648a0();
    int FUN_00864a60();
};
struct HitFxShell806420
{
    void FUN_00984f60(ActiveEffect* pEffect);
};
struct Shell81c530 : public FUN_0081c530
{
    static void* operator new(unsigned int size);
    Shell81c530();
};
struct FUN_0081f220 : public MagicHitEffect
{
    static void* operator new(unsigned int size);
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    FUN_0081f220();
};
struct FUN_00470440
{
    MagicHitEffect* m_item;
    FUN_00470440* m_pkNext;
    FUN_00470440(BGSPerkEntry* const& item);
};
TESForm* LookupFormByID(unsigned int id);
void __cdecl FNV_Warning(const char* fmt, ...);

struct FUN_00806420_shell : public ActiveEffect
{
    void FUN_00806420(BGSLoadFormBuffer* a1);
};
// Reads effect fields and tagged hit effects from the buffer, loads each effect, and adds it to pHitEffectList.
// @fnv 0x00806420
void FUN_00806420_shell::FUN_00806420(BGSLoadFormBuffer* apBuffer)
{
    apBuffer->ReadTypedData(&m_fEffectMagnitude, 4);
    apBuffer->ReadTypedData(&bActive, 1);
    apBuffer->ReadTypedData(&bEffectFlag, 1);
    apBuffer->ReadTypedData(&bWasPlaying, 1);
    apBuffer->ReadTypedData(&bPickResultFound, 1);
    apBuffer->ReadTypedData(&m_bEffectState, 1);
    apBuffer->ReadTypedData(&m_fElapsedTime, 4);
    apBuffer->ReadTypedData(&fDuration, 4);
    apBuffer->ReadTypedData(&iFlags, 4);
    apBuffer->ReadFormIdentifier(&m_pEffectInstance);
    apBuffer->ReadFormIdentifier(&pTarget);
    apBuffer->ReadFormIdentifier(&pMagicItem);
    pSource = dynamic_cast<TESBoundObject*>(LookupFormByID(((BufShell806420*)apBuffer)->FUN_008648a0()));
    int count = ((BufShell806420*)apBuffer)->FUN_00864a60();
    for (unsigned int i = 0; i < (unsigned int)count; ++i)
    {
        MagicHitEffect* pHitEffect;
        unsigned char uiTag = 0;
        apBuffer->ReadTypedData(&uiTag, 1);
        pHitEffect = 0;
        switch (uiTag)
        {
        case 5:
            pHitEffect = (MagicHitEffect*)new Shell81c530();
            break;
        case 6:
            pHitEffect = (MagicHitEffect*)new FUN_0081f220();
            break;
        default:
            FNV_Warning("SAVELOAD: Unknown magic hit effect type: %i", uiTag);
            break;
        }
        ((HitFxShell806420*)pHitEffect)->FUN_00984f60(this);
        ((BSTempEffect*)pHitEffect)->LoadGame(apBuffer);
        if (pHitEffectList == 0)
        {
            pHitEffectList =
                (BSSimpleList<MagicHitEffect*>*)new FUN_00470440(reinterpret_cast<BGSPerkEntry*&>(pHitEffect));
        }
        else
        {
            ((BSSimpleList<TESForm*>*)pHitEffectList)->AddHead(reinterpret_cast<TESForm*&>(pHitEffect));
        }
    }
}

struct LoadEffectFlagBytes_5d40
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
struct SaveLoadRecord_5d40
{
    unsigned int formID;
    unsigned char formType;
    LoadEffectFlagBytes_5d40 flags;
    unsigned char version;
};

class SaveReadShell_5d40
{
  public:
    void FUN_008579e0(void*, unsigned int);
};

class TESSaveLoadGame_5d40 : public SaveReadShell_5d40
{
  public:
    bool FUN_00862110();
    void* FUN_004fd3c0();
    unsigned int FUN_00825c00();
    unsigned char FUN_008df040();
};
class TESSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;

class VampirismEffect : public ActiveEffect
{
};

class TESFormStandin_5d40
{
  public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0A();
    virtual void s0B();
    virtual void s0C();
    virtual void s0D();
    virtual void s0E();
    virtual void s0F();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1A();
    virtual void s1B();
    virtual void s1C();
    virtual void s1D();
    virtual void s1E();
    virtual void s1F();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2A();
    virtual void s2B();
    virtual void s2C();
    virtual void s2D();
    virtual void s2E();
    virtual void s2F();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s3A();
    virtual void s3B();
    virtual void s3C();
    virtual void s3D();
    virtual void s3E();
    virtual void s3F();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s4A();
    virtual void s4B();
    virtual const char* GetName();
};

class TESForm;
TESForm* LookupFormByID(unsigned int id);
void __cdecl FNV_Warning(const char* fmt, ...);
ActiveEffect* FUN_00805920(Actor*);

class ActorStandin_5d40 : public Actor
{
  public:
    void* GetCurrentProcess();
};

class ActiveEffectList_5d40 : public BSSimpleList<ActiveEffect*>
{
  public:
    bool IsEmpty();
    ActiveEffect*& GetItem();
    ActiveEffectList_5d40* GetNext();
    void RemoveAll();
};

// @fnv 0x00805d40
void FUN_00805d40(ActiveEffectList_5d40* apList, ActorStandin_5d40* apActor)
{
    float p;
    int h;
    unsigned short a = 0;
    unsigned int i = 0;
    unsigned short s;
    ActiveEffectList_5d40* f;
    unsigned int eb;
    SaveLoadRecord_5d40* cf;
    TESFormStandin_5d40* q;
    VampirismEffect* b;
    ActiveEffect* ba;
    VampirismEffect* k;
    ActiveEffect* l;
    SaveLoadRecord_5d40* c;
    unsigned int e;
    TESFormStandin_5d40* j;

    if (((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_00862110())
    {
        ((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_008579e0(&eb, 4);
        if (eb != 'BLOK')
        {
            cf = (SaveLoadRecord_5d40*)((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_004fd3c0();
            if (cf)
            {
                q = (TESFormStandin_5d40*)LookupFormByID(cf->formID);
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1000, cf->formID,
                    q->GetName(), (int)cf->version, *(unsigned int*)&cf->flags);
            }
            else
            {
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1000,
                    (int)((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_008df040());
            }
        }
        i = ((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_00825c00();
        ((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_008579e0(&a, 2);
    }

    p = 0.0f;
    f = apList;
    while (f && !f->IsEmpty())
    {
        ba = f->GetItem();
        b = dynamic_cast<VampirismEffect*>(ba);
        if (b)
        {
            p = ba->GetFloatAtOffset1C();
        }
        delete ba;
        f = f->GetNext();
    }
    apList->RemoveAll();

    ((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_008579e0(&s, 2);
    for (h = 0; h < (int)s; ++h)
    {
        l = FUN_00805920(apActor);
        k = dynamic_cast<VampirismEffect*>(l);
        if (k && apActor)
        {
            apActor->GetCurrentProcess();
        }
        if (l)
        {
            apList->Insert(l, MagicTarget::CompareActiveEffects);
        }
    }

    if (((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_00862110())
    {
        e = ((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_00825c00();
        c = (SaveLoadRecord_5d40*)((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_004fd3c0();
        if (c)
        {
            j = (TESFormStandin_5d40*)LookupFormByID(c->formID);
            if (e > (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    e - ((unsigned int)a + i),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039, c->formID,
                    j->GetName(), (int)c->version, *(unsigned int*)&c->flags);
            }
            else if (e < (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    ((unsigned int)a + i) - e,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039, c->formID,
                    j->GetName(), (int)c->version, *(unsigned int*)&c->flags);
            }
        }
        else
        {
            if (e > (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    e - ((unsigned int)a + i),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039,
                    (int)((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_008df040());
            }
            else if (e < (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    ((unsigned int)a + i) - e,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039,
                    (int)((TESSaveLoadGame_5d40*)g_TESSaveLoadGame)->FUN_008df040());
            }
        }
    }
}

struct HitEffectNode
{
    bool _ref_008256d0();
    MagicHitEffect** _ref_006815c0();
    HitEffectNode* _ref_00726070();
};

struct ActiveEffectHitAccess : MagicHitEffect
{
    void SetByteAt24(unsigned int);
    void FUN_00984f60(unsigned int);
};

struct FUN_00803ed0
{
    float m_fEffectMagnitude;
    MagicItem* pSpell;
    EffectItem* pEffect;
    bool bActive;
    bool bEffectFlag;
    bool bWasPlaying;
    bool bPickResultFound;
    bool m_bEffectState;
    int iFlags;
    float m_fElapsedTime;
    float fDuration;
    MagicTarget* pTarget;
    MagicCaster* m_pEffectInstance;
    MagicSystem__SpellType m_eSpellType;
    SoundPlaybackHandle m_kSoundHandle;
    TESBoundObject* pSource;
    BSSimpleList<Actor*>* pHitEffectList;
    MagicItem* pMagicItem;
    virtual ~FUN_00803ed0();
};

// @fnv 0x00803ed0
FUN_00803ed0::~FUN_00803ed0()
{
    HitEffectNode* pIter = (HitEffectNode*)pHitEffectList;
    while (pIter && !pIter->_ref_008256d0())
    {
        ActiveEffectHitAccess* pHitEffect = (ActiveEffectHitAccess*)*pIter->_ref_006815c0();
        pHitEffect->SetByteAt24(1);
        pHitEffect->FUN_00984f60(0);
        pIter = pIter->_ref_00726070();
    }
    if (pHitEffectList)
        pHitEffectList->RemoveAll();
    delete pHitEffectList;
    if (m_kSoundHandle.IsSoundPlaying())
    {
        m_kSoundHandle.Stop();
        m_kSoundHandle.PausePlayback();
    }
}
