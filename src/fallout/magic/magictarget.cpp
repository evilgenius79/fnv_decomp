// fallout/magic/magictarget.cpp: MagicTarget, TESSpellList, MagicCaster, MagicSystem and more (39 functions)

#include <stddef.h>
#include "magictarget_decls.h"

class Actor;
class MagicCaster;
class MagicItem;
class ActiveEffect;
class TESObjectREFR;

template <class T> class BSSimpleList;

class MagicTarget
{
  public:
    virtual bool AddEffectToTarget(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool abImmediate);
    virtual TESObjectREFR* GetMagicTargetReference() const;
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() const;
    virtual bool MagicTargetIsActor() const;
    virtual bool CanReceiveMagicEffects() const;
    virtual void OnEffectStarted(ActiveEffect* apEffect);
    virtual void OnEffectFinished(ActiveEffect* apEffect);
    virtual void OnEffectAdded(MagicCaster* apCaster, ActiveEffect* apEffect);
    virtual void OnEffectRemoved(MagicCaster* apCaster, ActiveEffect* apEffect);
    virtual float GetEffectiveness(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);
    virtual bool IsImmuneToEffect(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool abUnknown);
    virtual bool ExecuteEffect(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);

    bool FUN_00822f70(ActorValue::Index);
    bool HasSpell(MagicItem*, bool);
    void DispelAllEffects();
    bool m_bLeadingFlag;
    bool m_bSecondFlag;
    unsigned short layoutPadding6;
    BSSimpleList<void*> m_kActiveEffectList;
    void UpdateActiveEffects(float);
    bool HasEffect(const EffectSetting*);
    static MagicTarget* GetMagicTargetByID(unsigned int);
    void ClearActiveEffects();
    void AddWeatherEntry(MagicItem*, MagicCaster*, ActiveEffect*);
    void RemoveEffect(ActiveEffect*, bool);
    bool FUN_00822c30(MagicItem*, ActiveEffect*);
    Actor* GetOwnerActor() const;
    bool AddActiveEffect(MagicCaster*, MagicItem*, ActiveEffect*);
    void Dispel(MagicItem*, MagicCaster*, ActiveEffect*);
    bool CanAddEffect(MagicItem*, MagicCaster*, ActiveEffect*);
    bool ContainsSpell(MagicItem*, bool);
    static int CompareActiveEffects(ActiveEffect*, ActiveEffect*);
    bool CanAcceptEffect(MagicItem*, MagicCaster*, ActiveEffect*);
};

// Returns the owning Actor when MagicTargetIsActor() is true, otherwise NULL.
// @fnv 0x00822b40
Actor* MagicTarget::GetOwnerActor() const
{
    return MagicTargetIsActor() ? (this ? (Actor*)((char*)this - 0x94) : NULL) : NULL;
}

// Validates a spell effect against the target, applies perk modifiers, dispels or clones the effect, and inserts the new ActiveEffect into the active effect list.
// @fnv 0x00823210
bool MagicTarget::AddActiveEffect(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect)
{
    // These short local names preserve MSVC9's name-dependent stack ordering.
    TESObjectREFR* i = GetMagicTargetReference();  // target reference
    if (i)
        Script::GetLocalData((TESForm*)EFFECT_ITEM(effect)->GetEffectSetting(), i->GetExtraData(), 0x2000);
    bool permanent = EFFECT_ITEM(effect)->FUN_008231f0() ? spell->Unk_07() : false;
    // Resistance scales the cloned effect unless it came from an ingredient.
    float a = spell->GetType() != 4 && !permanent ? GetEffectiveness(caster, spell, effect) : 1.0f;
    if (a <= 0.0)
    {
        if (caster == (g_thePlayer ? (MagicCaster*)((char*)g_thePlayer + 0x88) : 0) &&
            this == (g_thePlayer ? (MagicTarget*)((char*)g_thePlayer + 0x94) : 0))
        {
        }
        if (GetLimbConditionEffectInitialized())
            DebugLog("Target: %s FULLY RESISTED Spell: %s Effect: %s",
                     GetMagicTargetReference() ? GetMagicTargetReference()->GetFullName() : "{NULL}",
                     ((TESSoundFile*)spell)->GetSoundFile(), EFFECT_ITEM(effect)->GetEffectName().String(), a);
        return false;
    }
    if (CanReceiveMagicEffects() && EFFECT_ITEM(effect)->IsHostile())
        return false;
    if (!effect->IsEffectValid(this))
    {
        if (GetLimbConditionEffectInitialized())
            DebugLog("Invalid Target: Target: %s Spell: %s Effect: %s",
                     GetMagicTargetReference() ? GetMagicTargetReference()->GetFullName() : "{NULL}",
                     ((TESSoundFile*)spell)->GetSoundFile(), EFFECT_ITEM(effect)->GetEffectName().String());
        return false;
    }
    EffectItem* usageMonitor = spell->effectList.GetScriptEffect();
    if (EFFECT_ITEM(effect) == usageMonitor)
    {
        if (!ContainsSpell(spell, true))
        {
            BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
            bool found = false;
            while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty() && !found)
            {
                ActiveEffect* current = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
                if (current && EFFECT_ITEM(current) == usageMonitor)
                {
                    current->FUN_00804cb0(current->GetFloatAtOffset1C() + effect->GetFloatAtOffset1C());
                    current->FUN_004f5d90(0.0f);
                    found = true;
                }
                node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
            }
            if (found)
                return true;
        }
        else
            return false;
    }
    if (spell->GetType() == 10)
    {
        Actor* actor = MagicTargetIsActor() ? (this ? (Actor*)((char*)this - 0x94) : 0) : 0;
        if (actor)
        {
            float duration = effect->FUN_007df1f0();
            ApplyPerkModifiers(24, actor, &duration);
            effect->FUN_00693d50(duration);
        }
    }
    else if (spell->GetType() == 7)
    {
        AlchemyItem* potion = dynamic_cast<AlchemyItem*>(spell);
        if (potion && !EFFECT_ITEM(effect)->IsHostile())
        {
            Actor* actor = MagicTargetIsActor() ? (this ? (Actor*)((char*)this - 0x94) : 0) : 0;
            if (actor)
            {
                float duration = effect->FUN_007df1f0();
                ApplyPerkModifiers(25, actor, &duration);
                effect->FUN_00693d50(duration);
            }
        }
    }
    if (effect->GetEffectSetting()->GetArchetype() == 34)
    {
        ValueAndConditionsEffect* parts = dynamic_cast<ValueAndConditionsEffect*>(effect);
        if (parts)
            ((BGSImpactData*)parts)->SetSound1((TESSound*)GetStatusResult());
    }
    else if (effect->GetEffectSetting()->GetArchetype() == 35)
    {
        LimbConditionEffect* limb = dynamic_cast<LimbConditionEffect*>(effect);
        if (limb)
            ((BGSImpactData*)limb)->SetSound1((TESSound*)GetStatusResult());
    }
    bool e = true;   // dispel an existing matching effect
    bool c = false;  // stack its duration
    bool d = false;  // reset its elapsed time
    if (effect->IsFlagged())
    {
        e = false;
        if (effect->GetEffectSetting()->GetFlag(0x30000))
        {
            BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
            while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
            {
                ActiveEffect* current = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
                if (current && FUN_0040dfa0(EFFECT_ITEM(effect), EFFECT_ITEM(current)))
                {
                    Dispel(EFFECT_SPELL(current), 0, current);
                    e = false;
                }
                node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
            }
        }
    }
    else
    {
        switch (spell->GetType())
        {
        case 5:
        case 7:
            c = effect->FUN_007df1f0() > 0.0 ? true : false;
            e = false;
            break;
        case 8:
            e = false;
            break;
        case 6: {
            SpellItem* source = spell ? (SpellItem*)((char*)spell - 0x18) : 0;
            if (source->FUN_00823c20())
            {
                e = false;
                d = true;
            }
            TESForm* f = (TESForm*)((TESTopicInfo*)effect)->GetSpeaker();
            if (f && f->GetFormType() == 25)
                e = false;
            break;
        }
        }
    }
    if (e)
        Dispel(spell, caster, effect);
    else if (c)
    {
        if (CanAcceptEffect(spell, caster, effect))
            return true;
    }
    else if (d)
    {
        if (CanAddEffect(spell, caster, effect))
            return true;
    }
    ActiveEffect* h = effect->Clone();  // new effect owned by the target list
    if (!h)
        return false;
    ((TESRecipe*)h)->SetSkill((int)this);
    IngredientItem* f = dynamic_cast<IngredientItem*>(spell);  // ingredient source
    if (!f)
        h->SetEffectiveness(a);
    if (GetActiveEffectList())
    {
        GetActiveEffectList()->Insert(h, CompareActiveEffects);
        OnEffectStarted(h);
        h->Unk_02();
        if (GetLimbConditionEffectInitialized())
            DebugLog("Effect %s from spell %s added to %s. Mag: %.2f/%d Dur: %.2f/%d",
                     EFFECT_ITEM(h)->GetEffectName().String(), ((TESSoundFile*)spell)->GetSoundFile(),
                     i ? i->GetFullName() : "{NULL}", h->GetFloatAtOffset1C(), EFFECT_ITEM(h)->GetMagnitude(),
                     h->FUN_007df1f0(), EFFECT_ITEM(h)->GetDuration());
        return true;
    }
    else
    {
        delete h;
        return false;
    }
}

// Iterates the active effect list, updating each effect and removing finished ones, with wear-off messages for the player.
// @fnv 0x00823c40
void MagicTarget::UpdateActiveEffects(float delta)
{
    BSSimpleList<ActiveEffect*>* list = GetActiveEffectList();
    BSSimpleList<ActiveEffect*>* node = list;
    if (MagicTargetIsActor())
    {
        TESObjectREFR* target = GetMagicTargetReference();
        Actor* actor = this ? (Actor*)((char*)this - 0x94) : 0;
        if (!actor)
            return;
        if (!((PlayerQuestData*)actor)->GetLogDate())
            return;
    }
    m_bSecondFlag = true;
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        BSSimpleList<ActiveEffect*>* nextNode =
            (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
        ActiveEffect* pEffect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (pEffect)
        {
            bool done = pEffect->FUN_008240f0();
            bool bShouldUpdate = !done;
            if (bShouldUpdate && TESSpellList::RemoveSpell(((LocationDescriptor*)pEffect)->SetLocRef()) &&
                pEffect->GetEffectSetting()->FUN_00403e60(2) && pEffect->GetByteAtOffset17())
            {
                bShouldUpdate = pEffect->FUN_007df210() || ((LowProcess*)pEffect)->GetActiveCombatTarget();
            }
            if (bShouldUpdate)
                pEffect->UpdateEffect(delta);
            if (!done && pEffect->FUN_00705cf0())
            {
                MagicItem* spell = EFFECT_SPELL(pEffect);
                MagicTarget* target = (MagicTarget*)((ActorMover*)pEffect)->GetCurrentMoveModeType();
                pEffect->SetFlag(true);
                if (pEffect->FUN_00833c20() && !pEffect->IsFlag200Set() &&
                    target == (g_thePlayer ? (MagicTarget*)((char*)g_thePlayer + 0x94) : 0) && spell->GetType() == 7 &&
                    target->FUN_00822c30(spell, pEffect))
                {
                    bool show = true;
                    char message[260];
                    if (target->ContainsSpell(spell, true))
                    {
                        if (!g_thePlayer->actorValues.GetActorValue(72))
                            sprintf_s(message, sizeof(message), DAT_011d1fc8.GetMenuTitle(),
                                      ((TESSoundFile*)spell)->GetSoundFile());
                        else
                            show = false;
                    }
                    else
                    {
                        sprintf_s(message, sizeof(message), DAT_011d3c04.GetMenuTitle(),
                                  ((TESSoundFile*)spell)->GetSoundFile());
                    }
                    if (show)
                    {
                        Interface::ShowMessage(message, 0, 0, "UIHealthChemsWearOff", 2.0f, false);
                        AlchemyItem* potion = dynamic_cast<AlchemyItem*>(spell);
                        if (potion && potion->FUN_004030b0())
                        {
                            TESImageSpaceModifier* modifier = dynamic_cast<TESImageSpaceModifier*>(
                                BGSDefaultObjectManager::GetDefaultObjectByIndex(20));
                            if (modifier)
                                ImageSpaceModifierInstanceForm::ApplyImageSpaceModifier(modifier, 1.0f, 0);
                        }
                    }
                }
            }
            if (pEffect->FUN_008240f0())
            {
                if (node == list)
                    nextNode = node;
                RemoveEffect(pEffect, true);
            }
        }
        node = nextNode;
    }
    m_bSecondFlag = false;
    ClearActiveEffects();
}

// @fnv 0x00825270
int MagicTarget::CompareActiveEffects(ActiveEffect* first, ActiveEffect* second)
{
    char buffer1[256];
    char buffer2[256];
    EffectItem* pEffect = EFFECT_ITEM(first);
    sprintf(buffer1, "%c%.30s%.1f%.1f", 'A', pEffect->GetEffectName().String(),
            pEffect->GetEffectSetting()->FUN_00403e60(0x100) ? 1000.0f : first->GetFloatAtOffset1C(),
            pEffect->GetEffectSetting()->FUN_00403e60(0x80) ? 1000.0f : first->FUN_007df1f0());
    pEffect = EFFECT_ITEM(second);
    sprintf(buffer2, "%c%.30s%.1f%.1f", 'A', pEffect->GetEffectName().String(),
            pEffect->GetEffectSetting()->FUN_00403e60(0x100) ? 1000.0f : second->GetFloatAtOffset1C(),
            pEffect->GetEffectSetting()->FUN_00403e60(0x80) ? 1000.0f : second->FUN_007df1f0());
    return _mbsicmp((const unsigned char*)buffer1, (const unsigned char*)buffer2);
}

// @fnv 0x00824400
void MagicTarget::Dispel(MagicItem* spell, MagicCaster* caster, ActiveEffect* effect)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        ActiveEffect* current = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        BSSimpleList<ActiveEffect*>* nextNode =
            (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
        if (current && !current->FUN_00705cf0() && EFFECT_SPELL(current) == spell &&
            (caster ? (MagicCaster*)((TESResponse*)current)->GetNext() == caster : true) &&
            (effect ? ((TESTopicInfo*)effect)->GetSpeaker() == ((TESTopicInfo*)current)->GetSpeaker() : true))
        {
            if (effect)
            {
                if (!EFFECT_ITEM(current)->Compare(EFFECT_ITEM(effect)))
                {
                    if (m_bSecondFlag)
                        AddWeatherEntry(spell, caster, current);
                    else
                        current->Dispel(true);
                    break;
                }
            }
            else
            {
                if (m_bSecondFlag)
                    AddWeatherEntry(spell, caster, current);
                else
                    current->Dispel(true);
            }
        }
        node = nextNode;
    }
}

// @fnv 0x008230f0
bool MagicTarget::AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate)
{
    if (((TESForm*)EFFECT_ITEM(effect))->GetFormID())
    {
        bool permanent = EFFECT_ITEM(effect)->FUN_008231f0() ? spell->Unk_07() : false;
        if (!permanent && !spell->Unk_08())
        {
            if (ExecuteEffect(caster, spell, effect))
            {
                OnEffectAdded(caster, effect);
                return false;
            }
            if (IsImmuneToEffect(caster, spell, effect, false))
            {
                OnEffectRemoved(caster, effect);
                return false;
            }
        }
    }
    return AddActiveEffect(caster, spell, effect);
}

// Walks the active effect list and returns true if any ActiveEffect's EffectSetting matches setting.
// @fnv 0x00822d80
bool MagicTarget::HasEffect(const EffectSetting* setting)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    bool found = false;
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty() && !found)
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (effect && effect->GetEffectSetting() == setting)
            found = true;
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
    return found;
}

// Looks up the TESForm for id and, if it is a reference, returns that reference's magic target; otherwise returns null.
// @fnv 0x00825550
MagicTarget* MagicTarget::GetMagicTargetByID(unsigned int id)
{
    TESForm* form = TESForm::GetFormByID(id);
    if (form && ((MagicTargetFormDispatch*)form)->GetIsReference())
    {
        TESObjectREFR* reference = (TESObjectREFR*)form;
        return ((MagicTargetFormDispatch*)reference)->GetMagicTarget();
    }
    return 0;
}

// The coverage entry labels this MagicTarget, but the PC vtable and both
// NonActorMagicCaster constructors identify the receiving class as MagicCaster.
// @fnv 0x00815300
MagicCaster::MagicCaster()
{
    SetSelectedMagicItem(0);
    SetMagicTarget(0);
    eState = 0;
    apTargetLight = 0;
}

// PC initialization assigns the "spPipBoyLight" form to this static member.
// @fnv 0x0093ccd0
SpellItem* MagicSystem::GetPipBoyLightSpell()
{
    return ms_pPipBoyLightSpell;
}

// @fnv 0x00822f70
bool MagicTarget::FUN_00822f70(ActorValue::Index aeActorValue)
{
    // Short local names retain the original MSVC9 stack layout.
    bool b = false;  // found a hostile effect
    Actor* a = MagicTargetIsActor() ? (this ? (Actor*)((char*)this - 0x94) : NULL) : NULL;
    if (!a || aeActorValue == -1 || aeActorValue == 77)
        return false;
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !b && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (effect && EFFECT_ITEM(effect)->GetAffectedActorValue() == aeActorValue)
        {
            bool permanent = (int)((LocationDescriptor*)effect)->SetLocRef() == 4 && !effect->FUN_007df210() ? 1 : 0;
            if (((MagicTargetActorDispatch*)a)->IsPlayerRef() && permanent &&
                effect->GetEffectSetting()->FUN_00403e60(2))
            {
                // Permanent player effects do not count here.
            }
            else if (effect->GetEffectSetting()->FUN_00403e60(2))
                b = true;
        }
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
    return b;
}
// @fnv 0x00822b90
bool MagicTarget::HasSpell(MagicItem* spell, bool includeInactive)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    bool found = false;
    while (node && !found)
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (effect && EFFECT_SPELL(effect) == spell && (includeInactive || effect->FUN_00833c20()) &&
            !EFFECT_ITEM(effect)->IsScriptBasedEffect())
            found = true;
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
    return found;
}
// Walks the active effect list and dispels each ActiveEffect with true, advancing to the next node.
// @fnv 0x00824970
void MagicTarget::DispelAllEffects()
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
        if (effect)
            effect->Dispel(true);
    }
}
// @fnv 0x008231f0
bool EffectItem::FUN_008231f0()
{
    return setting->FUN_007df1b0();
}

struct FUN_004f5d90_shell : public ActiveEffect
{
    void FUN_004f5d90(float);
};

// @fnv 0x004f5d90
void FUN_004f5d90_shell::FUN_004f5d90(float afValue)
{
    *(float*)((char*)this + 4) = afValue;
}

struct FUN_008240f0_shell : public ActiveEffect
{
    bool FUN_008240f0();
};

// @fnv 0x008240f0
bool FUN_008240f0_shell::FUN_008240f0()
{
    return (*(unsigned int*)((char*)this + 0x18) & 0x80000000) != 0;
}

struct FUN_00822a70_shell : MagicTarget
{
    float GetEffectiveness(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);
};

// @fnv 0x00822a70
float FUN_00822a70_shell::GetEffectiveness(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect)
{
    return 1.0f;
}

struct FlaggedData
{
    int ContainsAnyFlag(unsigned int);
};

struct FUN_00823c20_shell : FlaggedData
{
    int FUN_00823c20();
};

// @fnv 0x00823c20
int FUN_00823c20_shell::FUN_00823c20()
{
    return ContainsAnyFlag(2);
}

struct FUN_008240a0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void SetFlag(bool abSet);
};

// Sets or clears bit 31 of m_18 according to abSet.
// @fnv 0x008240a0
void FUN_008240a0_shell::SetFlag(bool abSet)
{
    abSet ? m_18 |= 0x80000000 : m_18 &= 0x7fffffff;
}

struct FUN_00822cf0_shell : public MagicTarget
{
    bool HasActiveEffectOfArchetype(int archetype, bool include);
};

// @fnv 0x00822cf0
bool FUN_00822cf0_shell::HasActiveEffectOfArchetype(int archetype, bool include)
{
    BSSimpleList<ActiveEffect*>* list = GetActiveEffectList();
    bool found = false;
    while (list && !found)
    {
        ActiveEffect* effect = list->GetItem();
        if (effect && effect->GetEffectSetting()->GetArchetype() == archetype && (include || effect->FUN_00833c20()))
            found = true;
        list = list->GetNext();
    }
    return found;
}

struct MagicEffectContext
{
    MagicItem* pSpell;
    MagicCaster* m_pEffectInstance;
    ActiveEffect* m_pLinkedEffect;
};
typedef char _sizecheck_SpellDispelData[sizeof(MagicEffectContext) == 12 ? 1 : -1];
struct FUN_00824370_shell : public MagicTarget
{
    void FUN_00824370();
};

void __cdecl Deallocate(void*);
struct List_009e03e0
{
    void RemoveAll();
};

// Iterates the spell dispel list, dispels each entry's spell via its caster and active effect, deallocates the entry, then clears the list.
// @fnv 0x00824370
void FUN_00824370_shell::FUN_00824370()
{
    BSSimpleList<MagicEffectContext*>* list = (BSSimpleList<MagicEffectContext*>*)&m_kActiveEffectList;
    while (list && !list->IsEmpty())
    {
        MagicEffectContext* data = list->GetItem();
        if (data)
        {
            Dispel(data->pSpell, data->m_pEffectInstance, data->m_pLinkedEffect);
            MagicEffectContext* pEntry = data;
            Deallocate(pEntry);
        }
        list = list->GetNext();
    }
    ((List_009e03e0*)&m_kActiveEffectList)->RemoveAll();
}

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00824570_shell : MagicTarget
{
    void DispelMatchingActiveEffects(unsigned int formID, unsigned int flags, TESResponse* caster);
};

// Walks the active effect list and dispels each effect whose flags and form ID match, optionally restricted to a given caster.
// @fnv 0x00824570
void FUN_00824570_shell::DispelMatchingActiveEffects(unsigned int formID, unsigned int flags, TESResponse* caster)
{
    BSSimpleList<ActiveEffect*>* effect = GetActiveEffectList();
    while (effect && !effect->IsEmpty())
    {
        ActiveEffect* active = (ActiveEffect*)effect->GetItem();
        BSSimpleList<ActiveEffect*>* next = effect->GetNext();
        if (active && !active->FUN_00705cf0() && ((ArrSI*)active)->GetFlags() == flags &&
            ((caster ? ((TESResponse*)active)->GetNext() == caster : true) &&
             ((TESForm*)active)->GetFormID() == formID))
            active->Dispel(true);
        effect = next;
    }
}

struct FUN_008248e0_shell : public MagicTarget
{
    void StopEffect(MagicItem* apItem, bool abImmediate);
};

// @fnv 0x008248e0
void FUN_008248e0_shell::StopEffect(MagicItem* apItem, bool abImmediate)
{
    if (!apItem)
        return;

    BSSimpleList<ActiveEffect*>* apList = GetActiveEffectList();
    while (apList && !apList->IsEmpty())
    {
        ActiveEffect* effect = apList->GetItem();
        apList = apList->GetNext();
        if (effect)
        {
            if (!effect->FUN_00705cf0() &&
                reinterpret_cast<TESTopicInfo*>(effect)->GetSpeaker() == reinterpret_cast<TESActorBase*>(apItem))
                effect->Dispel(abImmediate);
        }
    }
}

struct EvalShell : MagicTarget
{
    void FUN_008255a0();
};
struct ActiveEffectEx : ActiveEffect
{
    void AdvanceEffect(float, bool);
};
// @fnv 0x008255a0
void EvalShell::FUN_008255a0()
{
    BSSimpleList<ActiveEffect*>* current = GetActiveEffectList();
    while (current)
    {
        ActiveEffect* effect = (ActiveEffect*)current->GetItem();
        current = (BSSimpleList<ActiveEffect*>*)current->GetNext();
        if (effect && (effect->FUN_007df210() || ((LowProcess*)effect)->GetActiveCombatTarget()))
            ((ActiveEffectEx*)effect)->AdvanceEffect(0.0f, true);
    }
}

float __fastcall GetFloatAtOffset1C(char*);
struct EffectNode
{
    TESForm* form;
    EffectNode* next;
};
struct EffectListNode
{
    EffectNode* item;
    EffectListNode* next;
    bool _ref_008256d0();
    EffectNode* GetItem();
    EffectListNode* GetNext();
};
struct FUN_00822eb0_shell : MagicTarget
{
    float FUN_00822eb0(MagicItem* apSpell);
};
// @fnv 0x00822eb0
float FUN_00822eb0_shell::FUN_00822eb0(MagicItem* apSpell)
{
    float fresult = 0.0f;
    EffectItem* pmonitorEffect = apSpell ? ((EffectItemList*)((char*)apSpell + 0xc))->GetScriptEffect() : 0;
    if (pmonitorEffect && HasSpell(apSpell, true))
    {
        EffectListNode* pEffectNode = (EffectListNode*)GetActiveEffectList();
        while (pEffectNode && !pEffectNode->_ref_008256d0())
        {
            TESForm* pForm = pEffectNode->GetItem()->form;
            if (pForm && pForm->GetFormID() == (unsigned int)pmonitorEffect)
                fresult += GetFloatAtOffset1C((char*)pForm);
            pEffectNode = pEffectNode->GetNext();
        }
    }
    return fresult;
}

class S3c60
{
  public:
    bool HasFlag2();
};

struct FUN_00822e00_shell : public MagicTarget
{
    bool FUN_00822e00();
};

// @fnv 0x00822e00
bool FUN_00822e00_shell::FUN_00822e00()
{
    BSSimpleList<ActiveEffect*>* list = GetActiveEffectList();
    bool found = false;

    while (list != 0 && !list->IsEmpty() && !found)
    {
        ActiveEffect* effect = list->GetItem();

        if (effect != 0 && reinterpret_cast<S3c60*>(effect->GetEffectSetting())->HasFlag2() &&
            reinterpret_cast<EffectItem*>(reinterpret_cast<TESForm*>(effect)->GetFormID())->GetAffectedActorValue() ==
                0x10 &&
            effect->GetEffectSetting()->FUN_00403e60(4))
        {
            found = true;
        }

        list = list->GetNext();
    }

    return found;
}

class B22C30Info
{
  public:
    bool IsDeleted();
};

class B22C30Form
{
  public:
    B22C30Info* GetInfo();
    int GetType();
    bool IsEnabled();
};

class B22C30Node
{
  public:
    B22C30Form** GetItem();
    B22C30Node* GetNext();
};

class B22C30Owner
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual B22C30Node* GetList();

    bool FUN_00822c30(int iType, B22C30Form* pkForm);
};

// Returns false if pkForm is deleted, otherwise counts enabled, non-deleted forms of iType in the list excluding pkForm and returns whether that count is zero.
// @fnv 0x00822c30
bool B22C30Owner::FUN_00822c30(int iType, B22C30Form* pkForm)
{
    if (pkForm->GetInfo()->IsDeleted())
        return false;

    B22C30Node* pkNode = GetList();
    bool bFound = false;
    int iCount6 = 0;
    while (pkNode)
    {
        B22C30Form* pkItem6 = *pkNode->GetItem();
        if (pkItem6 && pkItem6->GetType() == iType && pkItem6->IsEnabled() && !pkItem6->GetInfo()->IsDeleted() &&
            pkItem6 != pkForm)
            iCount6++;
        pkNode = pkNode->GetNext();
    }
    return iCount6 == 0;
}

class Actor;
class MagicCaster;
class MagicItem;
class ActiveEffect;
class TESObjectREFR;
template <class T> class BSSimpleList;
struct ActorPrefixS
{
    virtual void vfn_0();
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
};
class BaseProcess;
class NiNode;
class CellS
{
  public:
    NiNode* FUN_00545cb0();
};
struct ActorS : public ActorPrefixS, public MagicTarget
{
    BaseProcess* GetCurrentProcess() const;
};
class RefS
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* Get3D();
    CellS* GetParentCell();
};
struct ActiveEffectS : public ActiveEffect
{
    virtual void Unk_14();
    virtual void Unk_15();
    unsigned int GetFlagsS();
};
struct MagicTargetUpd : public MagicTarget
{
    void UpdateEffectsByFlags(unsigned int auiFlags);
};

// @fnv 0x00824110
void MagicTargetUpd::UpdateEffectsByFlags(unsigned int auiFlags)
{
    BSSimpleList<ActiveEffect*>* pIter = GetActiveEffectList();
    if (MagicTargetIsActor())
    {
        ActorS* pActor = (ActorS*)(MagicTarget*)this;
        if ((pActor && !pActor->GetCurrentProcess()) || !((RefS*)GetMagicTargetReference())->Get3D() ||
            !((RefS*)GetMagicTargetReference())->GetParentCell() ||
            !((RefS*)GetMagicTargetReference())->GetParentCell()->FUN_00545cb0())
            return;
    }
    while (pIter && !pIter->IsEmpty())
    {
        BSSimpleList<ActiveEffect*>* pNextEntry = pIter->GetNext();
        ActiveEffect* pEffect = pIter->GetItem();
        if (pEffect && ((ActiveEffectS*)pEffect)->GetFlagsS() == auiFlags)
        {
            if (!pEffect->GetByteAtOffset17())
            {
                pEffect->UpdateEffect(0.1f);
                pNextEntry = pIter->GetNext();
            }
            else
            {
                ((ActiveEffectS*)pEffect)->Unk_15();
            }
            if (pEffect->FUN_00705cf0())
                RemoveEffect(pEffect, false);
        }
        pIter = pNextEntry;
    }
}

class B824800EffectSetting
{
  public:
    int GetArchetype();
};

class B824800ActiveEffect
{
  public:
    int GetProcessLevel();
    bool IsDone() const;
    B824800EffectSetting* GetEffectSetting();
    void Dispel(bool bForce);
};

class B824800EffectNode
{
  public:
    bool IsEmpty();
    B824800ActiveEffect** GetItem();
    B824800EffectNode* GetNext();
};

class B824800MagicTarget
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual B824800EffectNode* GetActiveEffectList();

    void RemoveEffect(B824800ActiveEffect* pkEffect, bool bFlag);
    void RemoveEffectsByArchetype(int m_eEffectTypeItem, int iProcessLevel);
};

// Walks the active effect list and dispels/removes each effect whose archetype matches the given id and whose process level matches when nonzero.
// @fnv 0x00824800
void B824800MagicTarget::RemoveEffectsByArchetype(int aiArchetype, int iProcessLevel)
{
    B824800EffectNode* pkPrevious = GetActiveEffectList();
    B824800EffectNode* pkEntry = pkPrevious;
    while (pkEntry && !pkEntry->IsEmpty())
    {
        B824800ActiveEffect* pkEffectA = *pkEntry->GetItem();
        bool bLevelMatch = iProcessLevel ? iProcessLevel == pkEffectA->GetProcessLevel() : true;
        if (pkEffectA && !pkEffectA->IsDone() && pkEffectA->GetEffectSetting()->GetArchetype() == aiArchetype &&
            bLevelMatch)
        {
            pkEffectA->Dispel(true);
            RemoveEffect(pkEffectA, false);
        }
        else
        {
            pkPrevious = pkEntry;
            pkEntry = pkEntry->GetNext();
        }
    }
}

class EnchantmentItem : public MagicItem
{
  public:
    unsigned int GetEnchantmentType();
};
struct ActiveEffectSpell : ActiveEffect
{
    MagicItem* FUN_0044ddc0();
};
struct MagicTargetDispel : MagicTarget
{
    void FUN_008249d0(bool immediate);
};

// Iterates the active effect list and dispels each effect whose spell type is 0, 2, 3, 7 or 8, or is an enchantment of type 0.
// @fnv 0x008249d0
void MagicTargetDispel::FUN_008249d0(bool immediate)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !node->IsEmpty())
    {
        ActiveEffect* effect = node->GetItem();
        node = node->GetNext();
        if (effect)
        {
            MagicItem* spell = static_cast<ActiveEffectSpell*>(effect)->FUN_0044ddc0();
            if (spell->GetType() == 0 || spell->GetType() == 2 || spell->GetType() == 3 || spell->GetType() == 7 ||
                spell->GetType() == 8)
            {
                effect->Dispel(immediate);
            }
            else
            {
                EnchantmentItem* enchantment = dynamic_cast<EnchantmentItem*>(spell);
                if (enchantment && enchantment->GetEnchantmentType() == 0)
                    effect->Dispel(immediate);
            }
        }
    }
}

struct MTShell : public MagicTarget
{
    bool FUN_00824af0(unsigned int auiFormID, MagicCaster* apCaster, ActiveEffect* apEffect);
};

struct ActiveEffectAcc : public ActiveEffect
{
    unsigned int GetSpellID();
    MagicCaster* GetCaster();
    EffectItem* GetEffectItem();
};

// @fnv 0x00824af0
bool MTShell::FUN_00824af0(unsigned int auiFormID, MagicCaster* apCaster, ActiveEffect* apEffect)
{
    bool bFound4 = false;
    BSSimpleList<ActiveEffect*>* pNode2 = GetActiveEffectList();
    while (!bFound4 && pNode2 && !pNode2->IsEmpty())
    {
        ActiveEffectAcc* pEff = (ActiveEffectAcc*)pNode2->GetItem();
        BSSimpleList<ActiveEffect*>* pNext3 = pNode2->GetNext();
        if (pEff && !pEff->FUN_00705cf0() && pEff->GetSpellID() == auiFormID &&
            (apCaster ? pEff->GetCaster() == apCaster : true) &&
            (apEffect ? !pEff->GetEffectItem()->Compare(((ActiveEffectAcc*)apEffect)->GetEffectItem()) : true))
        {
            pEff->FUN_004f5d90(0.0f);
            bFound4 = true;
        }
        pNode2 = pNext3;
    }
    return bFound4;
}

class ListObj;
class ListItem
{
  public:
    ListObj* m_pEntryObject;
};

class ListNodeCls
{
  public:
    bool IsDone();
    ListItem* GetItem();
    ListNodeCls* Next();
};

class ListObj
{
  public:
    int GetKind();
    void SetOwner(void* owner);
    void SetValue(float f, int v);
};

class FUN_00824df0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual ListNodeCls* GetFirst();

    void FUN_00824df0(void* a1, int a2);
};

// Walks the list nodes and, for each item whose object has kind a2, sets its owner to a1 and its value to 0.0f with flag 1.
// @fnv 0x00824df0
void FUN_00824df0_cls::FUN_00824df0(void* pOwner, int iKind)
{
    ListNodeCls* node = GetFirst();
    while (node != 0 && !node->IsDone())
    {
        ListObj* obj = node->GetItem()->m_pEntryObject;
        node = node->Next();
        if (obj != 0 && obj->GetKind() == iKind)
        {
            obj->SetOwner(pOwner);
            obj->SetValue(0.0f, 1);
        }
    }
}

struct FUN_008251c0_obj
{
    virtual void* Release(bool);
};
extern int DAT_011c3ea4;
int* __fastcall FUN_0043d4d0(int*);
bool FUN_00713d90();
void* __stdcall FUN_004537b0(ActiveEffect*);
void __fastcall FUN_00905330(void*);
void __fastcall QueueTaskWithValue(void*);

class FUN_008251c0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void* vfn_8(ActiveEffect** pp);
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18(ActiveEffect* a);
    void FUN_008251c0(ActiveEffect* a, bool b);
};

// @fnv 0x008251c0
void FUN_008251c0_cls::FUN_008251c0(ActiveEffect* pEffect, bool b)
{
    if (!b)
    {
        pEffect->SetFlag(true);
        return;
    }
    FUN_00905330(vfn_8(&pEffect));
    vfn_18(pEffect);
    if (*FUN_0043d4d0(&DAT_011c3ea4) > 1 && FUN_00713d90())
    {
        QueueTaskWithValue(FUN_004537b0(pEffect));
        return;
    }
    ActiveEffect* t = pEffect;
    ActiveEffect* p = t;
    (void)(p ? ((FUN_008251c0_obj*)p)->Release(true) : 0);
}

struct FUN_0095e5f0_cls
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual int vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4(int);
    void FUN_0095e5f0();
};
void* __fastcall FUN_00717e50(void*);
void* __fastcall FUN_006815c0(void*);
struct FUN_0095e5f0_node
{
    FUN_0095e5f0_node* FUN_00726070();
};
// If vfn_37c() is non-zero, walks the node list from its +0x2c member and calls vfn_3e4 with each node's value from FUN_006815c0.
// @fnv 0x0095e5f0
void FUN_0095e5f0_cls::FUN_0095e5f0()
{
    if (vfn_37c())
    {
        void* node = FUN_00717e50((char*)vfn_37c() + 0x2c);
        while (node != 0 && *(int*)FUN_006815c0(node) != 0)
        {
            vfn_3e4(*(int*)FUN_006815c0(node));
            node = ((FUN_0095e5f0_node*)node)->FUN_00726070();
        }
    }
}

struct Setting_Float
{
    float* Float();
};
extern Setting_Float setting_011d1878;

struct Setting_String
{
    const char* String();
};
extern Setting_String setting_011d4cf0;

void __cdecl ApplyPerkModifiers(int, class Actor*, ...);
unsigned int __cdecl DialogueRandom();
void __cdecl FUN_004d5c60(int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);

struct StandinISModForm
{
    static void Trigger(TESImageSpaceModifier*, float, void*);
};

struct StandinForm
{
    virtual ~StandinForm();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct StandinSpellItem : public StandinForm, public MagicItem
{
};

struct StandinBoundObject
{
    virtual ~StandinBoundObject();
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
};

struct StandinMagicItem : public MagicItem
{
    const char* GetFullName();
};

struct StandinAlchemyItem : public StandinBoundObject, public StandinMagicItem
{
    float FUN_00644a50();
    StandinSpellItem* FUN_004030b0();
};

struct ActorPrimaryBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool v216();
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
};

struct StandinMagicCaster
{
    virtual void CastSpellOnCaster(SpellItem*, bool);
    virtual void CastSpellOnSelf(StandinSpellItem*, bool);
    int unk04;
    int unk08;
};

class Actor : public ActorPrimaryBase, public StandinMagicCaster, public MagicTarget
{
  public:
    virtual ~Actor();  // polymorphic: its RTTI is used (rtti_fix.py)
};

struct MT : public MagicTarget
{
    void FUN_008255a0();
};

struct FUN_00824e70_shell : public MagicTarget
{
    float FUN_00822eb0(MagicItem*);
    void DispelMatchingActiveEffects(EffectItem*, MagicItem*, void*);
    void FUN_00824df0(MagicItem*, MagicItem*);
    bool ApplyAddiction(StandinAlchemyItem* apItem);
};

// @fnv 0x00824e70
bool FUN_00824e70_shell::ApplyAddiction(StandinAlchemyItem* apItem)
{
    float fAddictionChance2 = apItem ? apItem->FUN_00644a50() : 0.0f;
    if (!apItem || !apItem->FUN_004030b0() || fAddictionChance2 == 0.0)
    {
        return false;
    }
    Actor* pActor2 = GetOwnerActor();
    if (!pActor2)
    {
        return false;
    }
    EffectItem* pEffectItem = apItem->effectList.GetScriptEffect();
    if (pEffectItem)
    {
        float fResistance = FUN_00822eb0(apItem);
        if (fResistance <= *setting_011d1878.Float())
        {
            return false;
        }
        else
        {
            fAddictionChance2 = (fResistance - *setting_011d1878.Float()) / 100.0;
        }
    }
    ApplyPerkModifiers(0x17, pActor2, &fAddictionChance2);
    int roll2 = DialogueRandom() % 100;
    if (fAddictionChance2 * 100.0 <= roll2)
    {
        ((MT*)this)->FUN_008255a0();
        return false;
    }
    bool bShowMsg = pActor2->v216() && !pActor2->ContainsSpell(apItem, true);
    if (pEffectItem)
    {
        DispelMatchingActiveEffects(pEffectItem, apItem, NULL);
    }
    pActor2->CastSpellOnSelf(apItem->FUN_004030b0(), false);
    FUN_00824df0(apItem, apItem->FUN_004030b0());
    if (bShowMsg)
    {
        FUN_004d5c60(10);
        TESImageSpaceModifier* pMod2 = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(0x19482));
        char szBuffer3[260];
        sprintf_s(szBuffer3, sizeof(szBuffer3), setting_011d4cf0.String(), apItem->GetFullName());
        Interface::ShowMessage(szBuffer3, 1, NULL, "UIHealthChemsAddicted", 2.0f, false);
        StandinISModForm::Trigger(pMod2, 1.0f, NULL);
        return true;
    }
    return false;
}

class TESForm825
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual int GetFormType();
};

class MediaSet825
{
  public:
    TESForm825* GetForm();
    int GetType();
    bool IsActive();
};

class Node825
{
  public:
    MediaSet825*& GetItem();
    Node825* GetNext();
};

class MediaLocation825
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual Node825* GetMediaSets();

    bool HasMediaSetOfType(int iType, bool bAny);
};

// Walks the media set list and returns true if a set holds a form of type 0xa matching iType (unless 0) and is active (unless bAny).
// @fnv 0x00825610
bool MediaLocation825::HasMediaSetOfType(int iType, bool bAny)
{
    Node825* pkNode = GetMediaSets();
    bool bFound = false;
    while (pkNode && !bFound)
    {
        MediaSet825* pkSet = pkNode->GetItem();
        TESForm825* pkForm = pkSet ? pkSet->GetForm() : 0;
        if (pkForm && pkForm->GetFormType() == 0xa && (!iType || pkSet->GetType() == iType) &&
            (bAny || pkSet->IsActive()))
            bFound = true;
        pkNode = pkNode->GetNext();
    }
    return bFound;
}

unsigned int __fastcall FUN_0044ddc0(void* apEffect);
class CombatNode
{
  public:
    unsigned int FUN_00726070();
};
class MagicCaster;
class FUN_0045cd60_shell
{
  public:
    MagicCaster* FUN_0045cd60();
};

class FUN_00824c00_cls : public MagicTarget
{
  public:
    bool StackActiveEffect(MagicItem* apItem, MagicCaster* apCaster, ActiveEffect* apEffect);
};

// Scans the active effect list for a matching effect and, if found, adds apEffect's magnitude to it and returns whether stacking occurred.
// @fnv 0x00824c00
bool FUN_00824c00_cls::StackActiveEffect(MagicItem* apItem, MagicCaster* apCaster, ActiveEffect* apEffect)
{
    bool bStackedValue = false;
    BSSimpleList<ActiveEffect*>* pNode = GetActiveEffectList();
    bool bAddictionValue = false;
    if (apItem->GetType() == 7)
    {
        AlchemyItem* pAlchemy = dynamic_cast<AlchemyItem*>(apItem);
        if (pAlchemy && ((CombatNode*)((char*)pAlchemy + 0x9c))->FUN_00726070() == 0xd)
            bAddictionValue = true;
    }
    while (!bStackedValue && pNode && !pNode->IsEmpty())
    {
        ActiveEffect* pActive_2 = pNode->GetItem();
        BSSimpleList<ActiveEffect*>* pTmpNext = pNode->GetNext();
        bool bTmpSame = pActive_2 && (MagicItem*)FUN_0044ddc0(pActive_2) == apItem;
        if (bAddictionValue)
        {
            AlchemyItem* pOther = dynamic_cast<AlchemyItem*>(apItem);
            if (pOther)
                bTmpSame = ((CombatNode*)((char*)pOther + 0x9c))->FUN_00726070() == 0xd;
        }
        if (pActive_2 && !pActive_2->FUN_00705cf0() && bTmpSame &&
            (apCaster ? ((FUN_0045cd60_shell*)pActive_2)->FUN_0045cd60() == apCaster : true) &&
            (apEffect ? !EFFECT_ITEM(pActive_2)->Compare(EFFECT_ITEM(apEffect)) : true))
        {
            pActive_2->FUN_00693d50(pActive_2->FUN_007df1f0() + apEffect->FUN_007df1f0());
            bStackedValue = true;
        }
        pNode = pTmpNext;
    }
    return bStackedValue;
}

struct EffectNode;
struct EffectList
{
    EffectNode* item;
    EffectList* next;
    bool FUN_008256d0();
    EffectNode*& FUN_006815c0();
    EffectList* FUN_00726070();
    void FUN_00470470();
    ~EffectList();
};

class MagicTargetImpl
{
  public:
    virtual ~MagicTargetImpl();
    bool m_bLeadingFlag;
    bool m_bSecondFlag;
    unsigned short layoutPadding6;
    EffectList m_kActiveEffectList;
};
// Deletes each non-null EffectNode returned while traversing the list, then calls FUN_00470470 on the list.
// @fnv 0x00822a80
MagicTargetImpl::~MagicTargetImpl()
{
    EffectList* iter = &m_kActiveEffectList;
    while (iter && !iter->FUN_008256d0())
    {
        EffectNode* effect = iter->FUN_006815c0();
        if (effect)
        {
            delete effect;
        }
        iter = iter->FUN_00726070();
    }
    m_kActiveEffectList.FUN_00470470();
}

struct SpellFormBase
{
    virtual void v000();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct ListedSpell : SpellFormBase, MagicItem
{
};

struct AlchEffectList
{
    bool CheckFlag();
};

struct AlchemyItemRecord : AlchemyItem
{
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
    AlchEffectList alchEffectList;
};

struct ActorSpellList
{
    BSSimpleList<ListedSpell*>* GetHead();
};

class TESActorBase
{
  public:
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
    ActorSpellList spellList;
};

class ActorView
{
  public:
    TESActorBase* GetActorBase();
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void RemoveSpell(ListedSpell*);
};

struct MagicTargetTypedDispel : MagicTarget
{
    void FUN_00824630(int aiType);
};

// For aiType 1, removes type-1 spells; otherwise, dispels matching active effects or flagged alchemy effects when aiType is 5.
// @fnv 0x00824630
void MagicTargetTypedDispel::FUN_00824630(int aiType)
{
    BSSimpleList<ActiveEffect*>* pIter;
    if (aiType == 1)
    {
        ActorView* pActor =
            reinterpret_cast<ActorView*>(dynamic_cast<Actor*>((TESObjectREFR*)GetMagicTargetReference()));
        if (pActor)
        {
            bool bRemoved = false;
            do
            {
                BSSimpleList<ListedSpell*>* pNode = pActor->GetActorBase()->spellList.GetHead();
                bRemoved = false;
                while (pNode && !pNode->IsEmpty())
                {
                    BSSimpleList<ListedSpell*>* pNext = pNode->GetNext();
                    ListedSpell* pSpell = pNode->GetItem();
                    if (pSpell && pSpell->GetType() == 1)
                    {
                        pActor->RemoveSpell(pSpell);
                        bRemoved = true;
                        break;
                    }
                    pNode = pNext;
                }
            } while (bRemoved);
        }
    }
    else
    {
        pIter = GetActiveEffectList();
        while (pIter && !pIter->IsEmpty())
        {
            ActiveEffectSpell* pEffect = (ActiveEffectSpell*)pIter->GetItem();
            BSSimpleList<ActiveEffect*>* pNextEffect = pIter->GetNext();
            if (pEffect && !pEffect->FUN_00705cf0())
            {
                AlchemyItem* pAlch = dynamic_cast<AlchemyItem*>(pEffect->FUN_0044ddc0());
                bool bFlag = pAlch ? ((AlchemyItemRecord*)pAlch)->alchEffectList.CheckFlag() : false;
                if (pEffect->FUN_0044ddc0()->GetType() == aiType || (bFlag && aiType == 5))
                {
                    pEffect->Dispel(false);
                }
            }
            pIter = pNextEffect;
        }
    }
}
