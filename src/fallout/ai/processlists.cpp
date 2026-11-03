// fallout/ai/processlists.cpp: ProcessLists, ProcessListsEx, TESObjectREFR, BGSProjectile and more (133 functions)

#include "processlists_private/processlists_ProcessLists.h"
#include "processlists_private/processlists_Actor.h"
#include "processlists_private/processlists_BGSTalkingActivator.h"
#include "processlists_private/processlists_BGSProjectile.h"
#include "processlists_private/processlists_Projectile.h"
#include "processlists_private/processlists_Explosion.h"
#include "processlists_private/processlists_BaseProcess.h"
#include "processlists_private/processlists_PlayerCharacter.h"
#include "processlists_private/processlists_types_TESPackage.h"
#include "processlists_private/processlists_BSTempEffect.h"
#include "processlists_private/processlists_GarbageCollector.h"
#include "processlists_private/processlists_dead_animation_actorbase.h"
#include "processlists_private/processlists_decls.h"
extern PlayerCharacter* pPlayer;

// Returns the extra data of the given type from the reference's extra data list.
// @fnv 0x00527080
BSExtraData* TESObjectREFR::GetExtraData(unsigned char type) const
{
    return GetExtra()->GetExtraData(type);
}

// @fnv 0x00975300
bool BGSProjectile::GetHasExplosionAltTrigger() const
{
    return GetFlag(4);
}

// @fnv 0x0096e290
BSSimpleList<Actor*>* ProcessLists::GetAliveActorList()
{
    BSSimpleList<Actor*>* actors = &m_kAliveActorList;
    return actors;
}

// If actor is non-null and not already in the list, adds it to the head of the list.
// @fnv 0x0096e2b0
void ProcessLists::AddActorToAliveList(Actor* actor)
{
    if (!actor)
        return;
    if (!m_kAliveActorList.IsInList(actor))
        m_kAliveActorList.AddHead(actor);
}

// @fnv 0x0096e2f0
void ProcessLists::RemoveActorFromAliveList(Actor* actor)
{
    m_kAliveActorList.Remove(actor);
}

// Clears the alive actor list, then adds every non-dead Actor from the high-priority process array to it.
// @fnv 0x0096e310
void ProcessLists::CalculateAliveActorList()
{
    m_kAliveActorList.RemoveAll();
    MobileObjectProcessArray* processes = g_kProcessLists.GetProcessArray();
    for (unsigned int i = processes->GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < processes->GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        MobileObject* object = processes->GetItem(i);
        if (object && object->IsActor())
        {
            Actor* actor = static_cast<Actor*>(object);
            if (!actor->IsDead(false))
                m_kAliveActorList.AddHead(actor);
        }
    }
}

// Iterates the high-priority process list, and for each entry that is an actor with a non-null field, calls Update(0.0f).
// @fnv 0x0096c7c0
void ProcessLists::RunActorUpdates()
{
    for (unsigned int i = m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        MobileObject* object = m_kMobileObjectProcessList.GetItem(i);
        if (object && object->IsActor())
        {
            Actor* actor = static_cast<Actor*>(object);
            if (actor->m_bFirstActorFlag)
                actor->Update(0.0f);
        }
    }
}

// Scans the high-process list for a talking activator whose temp ref is the given actor and returns true if one is found.
// @fnv 0x00973d50
bool ProcessLists::IsActorTalkingThroughActivator(Actor* actor)
{
    MobileObject* object = 0;
    for (unsigned int i = 0; i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        object = m_kMobileObjectProcessList.GetItem(i);
        Actor* talkingActor = 0;
        if (object && object->IsTalkingActivator())
        {
            BGSTalkingActivator* activator = static_cast<BGSTalkingActivator*>(object->GetObjectReference());
            if (activator->GetTempRef() == actor)
                return true;
        }
    }
    return false;
}

// @fnv 0x0096e870
void ProcessLists::AddMobileObjectToList(MobileObject* object)
{
    if (!m_kObjectReferenceList.IsInList(object))
    {
        if (!object->IsActor())
        {
            object->SetNeedToChangeProcess(true);
            m_kObjectReferenceList.AddHead(object);
        }
        else
        {
            if (!object->GetCurrentAIProcess())
                return;
            PROCESS_TYPE currentLevel = object->GetCurrentAIProcess()->GetProcessLevel();
            PROCESS_TYPE desiredLevel = object->GetProcessTier();
            if (object->IsDead(false) || currentLevel != desiredLevel ||
                object->GetCurrentAIProcess()->IsCurrentProcessComplete() || object->GetDeleted() ||
                pPlayer->IsSleepingOrResting())
            {
                object->SetNeedToChangeProcess(true);
                m_kObjectReferenceList.AddHead(object);
                if (object)
                    object->m_bSeventhFlag = true;
            }
        }
    }
}

// @fnv 0x0096c240
void ProcessLists::UpdateMagicTempEffects(float timeDelta)
{
    MobileObject* object = 0;
    for (unsigned int i = m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        object = m_kMobileObjectProcessList.GetItem(i);
        if (object && !object->IsStillLoading() && !object->GetDeleted() && !object->GetDisabled())
        {
            if (object->IsProjectile())
            {
                Projectile* projectile = static_cast<Projectile*>(object);
                projectile->ProcessProjectile();
            }
            else if (object->IsExplosion())
            {
                Explosion* explosion = static_cast<Explosion*>(object);
                explosion->ApplyBlastEffects();
            }
        }
    }
}

// @fnv 0x0096e9b0
void ProcessLists::UpdateFollowerTempList()
{
    BSSimpleList<TESObjectREFR*>* list = &m_kObjectReferenceList;
    for (BSSimpleList<TESObjectREFR*>* current = list; current && current->GetItem();)
    {
        Actor* actor = 0;
        if (current->GetItem()->IsActor())
            actor = static_cast<Actor*>(current->GetItem());
        if (actor && !actor->IsStillLoading() && actor->GetCurrentAIProcess() &&
            actor->GetCurrentAIProcess()->GetOneTimePackage())
        {
            TESObjectREFR* target = actor->GetCombatOpponent();
            TESPackage* package = actor->GetCurrentAIProcess()->GetOneTimePackage();
            if (package && package->GetPackType() == _PackageType::ESCORT)
            {
                TESObjectREFR* escortTarget = actor->GetCombatOpponent();
                if (escortTarget && escortTarget->IsActor())
                    actor->GetCurrentAIProcess()->SetPackageForActor(actor, package, false);
            }
            else if (target && target->IsActor() && target != pPlayer)
                actor->SetCombatOpponent(static_cast<Actor*>(target));
        }
        current = current->GetNext();
    }
}

// @fnv 0x00974420
void ProcessLists::UpdateInterfaceTempEffects(float delta)
{
    for (unsigned int i = m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        BaseProcess* process;
        MobileObject* object = m_kMobileObjectProcessList.GetItem(i);
        process = object ? object->GetCurrentAIProcess() : 0;
        if (object->IsActor() && process && process->IsProcessStateInitialized())
            process->RefreshActorProcessState(static_cast<Actor*>(object));
    }
    if (!m_kTemporaryEffectList.IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* current = &m_kTemporaryEffectList;
        bool first = true;
        while (current)
        {
            BSTempEffect* effect = current->GetItem();
            if (!first)
                current = current->GetNext();
            if (effect && !effect->Update(delta))
            {
                effect->Detach();
                GarbageCollector::Add(effect);
                m_kTemporaryEffectList.Remove(effect);
            }
            else if (first)
            {
                current = current->GetNext();
                first = false;
            }
        }
    }
    if (!m_kTemporaryEffectList2.IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* current = &m_kTemporaryEffectList2;
        bool first = true;
        while (current)
        {
            BSTempEffect* effect = current->GetItem();
            if (!first)
                current = current->GetNext();
            if (effect && !effect->Update(delta))
            {
                GarbageCollector::Add(effect);
                m_kTemporaryEffectList2.Remove(effect);
            }
            else if (first)
            {
                current = current->GetNext();
                first = false;
            }
        }
    }
}

// @fnv 0x00972bb0
void ProcessLists::UpdateHighProcess()
{
    MobileObject* object = 0;
    for (unsigned int i = 0; i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        object = m_kMobileObjectProcessList.GetItem(i);
        Actor* actor = 0;
        if (object && object->IsActor())
            actor = static_cast<Actor*>(object);

        if (actor && actor->IsDead(false))
        {
            if (actor->GetActorBase()->GetHealth() > 0 && !actor->GetHavokDeath())
                actor->GetCurrentAIProcess()->IsFurnitureMarkerValid(actor);
        }
        else if (actor && actor->GetFatiguePercentage() <= 0.0 && actor->GetActorBase()->GetFatigue() > 0)
        {
            BaseProcess* process = actor->GetCurrentAIProcess();
            if (process)
                process->ApplyKnockback(actor, *actor->GetPos(), 0.0f);
        }
    }
}

// @fnv 0x00974d90
bool FOPipboyManager::IsUnk28Set()
{
    return bUnk28;
}

// @fnv 0x0096c950
bool Actor::FUN_0096c950()
{
    return m_bThirdBooleanFlagAfterActorBase;
}

// Returns a pointer to this setting's value, or to a static default value set to false when this is null.
// @fnv 0x00408d60
template <> SETTING_VALUE* SettingT<INISettingCollection>::Bool()
{
    SETTING_VALUE* value =
        this ? &this->uValue : (((SETTING_VALUE*)&DAT_01202800)->b = false, (SETTING_VALUE*)&DAT_01202800);
    return value;
}

// @fnv 0x0096f400
void ProcessLists::RemoveMobileObjectFromList(MobileObject* object)
{
    if (object == DAT_011e0e38)
        DAT_011e0e38 = 0;
    m_kObjectReferenceList.Remove(object);
    if (object)
        object->m_bSeventhFlag = false;
}

#pragma optimize("gty", on)
// @fnv 0x00c68f00
void bhkWorld::SetWorldActive(bool arg)
{
    if (unk1C > 0u)
    {
        if (--unk1C == 0)
        {
            ProcessPendingItems();
            ReleaseBodies();
            ClearReferences();
            if (arg)
                FlushEntries();
            else
                ClearEntries();
        }
    }
    else if (unk50 > 0u && !arg)
    {
        ClearEntries();
    }
}
#pragma optimize("", off)

// Stores time in DAT_011e0e2c, resetting it to 0.0f if it exceeds DAT_0108c160 or is NaN/non-finite.
// @fnv 0x0096d4b0
void ProcessLists::AdvanceProcessLists(float time)
{
    DAT_011e0e2c = time;
    if (DAT_011e0e2c > DAT_0108c160)
        DAT_011e0e2c = 0.0f;
    if (FNV_IsNaN(DAT_011e0e2c) || !FNV_Finite(DAT_011e0e2c))
        DAT_011e0e2c = 0.0f;
}

// @fnv 0x00975af0
void ProcessLists::InitLoadGame(BGSLoadGameBuffer* buffer)
{
    for (unsigned int i = 0; i < 5; ++i)
    {
        BSSimpleList<Crime*>* current = m_pkCrimeLists[i];
        while (current)
        {
            Crime* crime = current->GetItem();
            if (crime)
                crime->FUN_009ec400(buffer);
            current = current->GetNext();
        }
    }
    CalculateAliveActorList();
}

// @fnv 0x0096e7d0
bool ProcessLists::CanAddActorToList(Actor* actor, int count)
{
    if (!actor || actor == pPlayer)
        return true;
    m_kActorListLock.Lock(0);
    count = MinInt(count, m_iActorCount);
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (m_apActorCache[i] == actor)
        {
            found = true;
            break;
        }
    }
    m_kActorListLock.Unlock();
    return found;
}

// @fnv 0x00975c50
void ProcessLists::Revert(BGSLoadGameBuffer* buffer)
{
    BSSimpleList<NiPointer<BSTempEffect> >* current = &m_kTemporaryEffectList;
    while (current && !current->IsEmpty())
    {
        BSTempEffect* effect = current->GetItem();
        if (effect)
            effect->Detach();
        current->RemoveHead();
    }
    current = &m_kTemporaryEffectList2;
    while (current && !current->IsEmpty())
        current->RemoveHead();
    NiTMap<TESGlobal*, bool>::NewItem();
    FUN_004ee7d0();
    bsrandom_singleton::MersenneTwister::GetRandomGenerator();
    FUN_004a42a0();
}

// Scans the temp-effect list for a MagicShaderHitEffect matching target with the lowest FUN_00621b00 value and no IsUnk28Set, returning it.
// @fnv 0x00974cb0
MagicShaderHitEffect* ProcessLists::FindMagicShaderHitEffect(TESObjectREFR* target)
{
    float m_fFirstFloatValue;
    MagicShaderHitEffect* result = 0;
    m_fFirstFloatValue = 3.402823466e38f;
    if (!m_kTemporaryEffectList2.IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* current = &m_kTemporaryEffectList2;
        while (current)
        {
            BSTempEffect* effect = current->GetItem();
            if (effect &&
                FUN_0043b300(reinterpret_cast<const NiRTTI*>(&g_011dc804), reinterpret_cast<NiAVObject*>(effect)))
            {
                MagicShaderHitEffect* shader = reinterpret_cast<MagicShaderHitEffect*>(effect);
                if (reinterpret_cast<BGSTerrainManager*>(shader)->GetMinLevel() ==
                        reinterpret_cast<unsigned int>(target) &&
                    m_fFirstFloatValue > reinterpret_cast<ActorPackageContext*>(shader)->FUN_00621b00() &&
                    !reinterpret_cast<FOPipboyManager*>(shader)->IsUnk28Set())
                {
                    result = shader;
                    m_fFirstFloatValue = reinterpret_cast<ActorPackageContext*>(shader)->FUN_00621b00();
                }
            }
            current = current->GetNext();
        }
    }
    return result;
}

struct FUN_00632d20_shell : public Crime
{
    void FUN_00632d20(bool);
};

// @fnv 0x00632d20
void FUN_00632d20_shell::FUN_00632d20(bool abflag)
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x10) = abflag;
}

struct FUN_0096bbc0_list
{
    virtual void v0(MobileObject*);
    int GetFirst();
};
struct FUN_0096bbc0_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void ProcessMobileObjects(FUN_0096bbc0_list* l);
};
// Iterates the process list for the given process type, calling l->v0 on each loaded MobileObject.
// @fnv 0x0096bbc0
void FUN_0096bbc0_cls::ProcessMobileObjects(FUN_0096bbc0_list* apList)
{
    unsigned int end = pa.GetTail((PROCESS_TYPE)apList->GetFirst());
    for (unsigned int i = pa.GetHead((PROCESS_TYPE)apList->GetFirst()); i < end; i++)
    {
        MobileObject* pmob = pa.GetItem(i);
        if (pmob && !((TESForm*)pmob)->IsStillLoading())
            apList->v0(pmob);
    }
}

struct FUN_008f63e0_wrap
{
    void ProcessDetectionStateLists(MobileObject* pActor);
};

// Updates the player's current AI process, then calls ProcessDetectionStateLists on each actor's AI process in the high-process list.
// @fnv 0x0096c710
void __fastcall FUN_0096c710(ProcessLists* pProcessLists)
{
    if (pPlayer->GetCurrentAIProcess())
    {
        ((FUN_008f63e0_wrap*)pPlayer->GetCurrentAIProcess())->ProcessDetectionStateLists(pPlayer);
    }

    for (unsigned int i =
             ((MobileObjectProcessArray*)((char*)pProcessLists + 4))->GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < ((MobileObjectProcessArray*)((char*)pProcessLists + 4))->GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        MobileObject* pObject = ((MobileObjectProcessArray*)((char*)pProcessLists + 4))->GetItem(i);
        if (pObject && pObject->IsActor())
        {
            ((FUN_008f63e0_wrap*)pObject->GetCurrentAIProcess())->ProcessDetectionStateLists(pObject);
        }
    }
}

struct FUN_0096cfa0_proc
{
    void FUN_008ff030(MobileObject*);
};
struct FUN_0096cfa0_virt
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
    virtual bool vlast();
};
struct FUN_0096cfa0_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void FUN_0096cfa0();
};
// Iterates the collection up to its tail count, and for each valid MobileObject whose virtual check passes, calls FUN_008ff030 on its current AI process.
// @fnv 0x0096cfa0
void FUN_0096cfa0_cls::FUN_0096cfa0()
{
    MobileObject* pmob = 0;
    for (unsigned int i = 0; i < pa.GetTail((PROCESS_TYPE)0); i++)
    {
        pmob = pa.GetItem(i);
        if (pmob && ((FUN_0096cfa0_virt*)pmob)->vlast())
            ((FUN_0096cfa0_proc*)pmob->GetCurrentAIProcess())->FUN_008ff030(pmob);
    }
}

struct FUN_0096d490_shell : public ProcessLists
{
    float FUN_0096d490();
};

// @fnv 0x0096d490
float FUN_0096d490_shell::FUN_0096d490()
{
    return DAT_011e0e2c;
}

struct FUN_0096e570_shell : public ProcessLists
{
    void FUN_0096e570();
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011cde2c;
int __cdecl FUN_00970ee0(Actor*, Actor*);

// Locks the list, shell-sorts the Actor pointers at offset 0x88 by FUN_00970ee0, then clears and shrinks the count at 0x150 down to *g_011cde2c.Int().
// @fnv 0x0096e570
void FUN_0096e570_shell::FUN_0096e570()
{
    ((RecursiveSpinLock*)((char*)this + 0x10300))->Lock(0);

    int igap = 0;
    int ileft = 0;
    int iright = *(int*)((char*)this + 0x150) - 1;

    for (igap = 1; igap <= (iright - ileft) / 9; igap = igap * 3 + 1)
    {
    }

    for (; igap > 0; igap /= 3)
    {
        for (int i = ileft + igap; i <= iright; ++i)
        {
            int j = i;
            Actor* pActor = ((Actor**)((char*)this + 0x88))[i];
            while (j >= ileft + igap && FUN_00970ee0(pActor, ((Actor**)((char*)this + 0x88))[j - igap]) < 0)
            {
                ((Actor**)((char*)this + 0x88))[j] = ((Actor**)((char*)this + 0x88))[j - igap];
                j -= igap;
            }
            ((Actor**)((char*)this + 0x88))[j] = pActor;
        }
    }

    while (*(int*)((char*)this + 0x150) > *g_011cde2c.Int())
    {
        ((Actor**)((char*)this + 0x88))[*(int*)((char*)this + 0x150) - 1] = 0;
        *(int*)((char*)this + 0x150) = *(int*)((char*)this + 0x150) - 1;
    }

    ((RecursiveSpinLock*)((char*)this + 0x10300))->Unlock();
}

struct FUN_0096e6f0_shell : public ProcessLists
{
    void RemoveActor(Actor*);
};

void __cdecl FUN_008661e0(void*, unsigned int, const void*, unsigned int);

// @fnv 0x0096e6f0
void FUN_0096e6f0_shell::RemoveActor(Actor* pactor)
{
    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(this) + 0x10300)->Lock(0);
    for (int icurActor = 0; icurActor < *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150); ++icurActor)
    {
        if (reinterpret_cast<Actor**>(reinterpret_cast<char*>(this) + 0x88)[icurActor] == pactor)
        {
            int inumElementsToCopy = 50 - icurActor - 1;
            FUN_008661e0(&reinterpret_cast<Actor**>(reinterpret_cast<char*>(this) + 0x88)[icurActor], 200,
                         &reinterpret_cast<Actor**>(reinterpret_cast<char*>(this) + 0x88)[icurActor + 1],
                         inumElementsToCopy * sizeof(Actor*));
            reinterpret_cast<Actor**>(reinterpret_cast<char*>(this) +
                                      0x88)[*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) - 1] = 0;
            *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) =
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) - 1;
            break;
        }
    }
    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(this) + 0x10300)->Unlock();
}

extern double DAT_0102c188;
struct FUN_00973de0_virt
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
    virtual bool vlast();
};
struct FUN_00973de0_act
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
    virtual bool vlast(int);
    bool IsPlayerTeammate();
    void SetSpeakingState(bool);
    void FUN_008ad910(void*, bool, bool);
};
struct FUN_00973de0_player
{
    bool FUN_009549a0(FUN_00973de0_act*);
    float GetDistanceToReference(void*, bool, bool);
};
struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};
struct FUN_00973de0_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void FUN_00973de0();
};
// @fnv 0x00973de0
void FUN_00973de0_cls::FUN_00973de0()
{
    MobileObject* pmob = 0;
    for (unsigned int i = 0; i < ((BGSMessageInitAccess*)&pa)->GetIconFormID(); i++)
    {
        pmob = pa.GetItem(i);
        FUN_00973de0_act* a = 0;
        if (pmob && ((FUN_00973de0_virt*)pmob)->vlast())
            a = (FUN_00973de0_act*)pmob;
        if (a && !a->vlast(0))
        {
            if ((((FUN_00973de0_player*)pPlayer)->FUN_009549a0(a) &&
                 ((FUN_00973de0_player*)pPlayer)->GetDistanceToReference(a, false, false) > DAT_0102c188) ||
                a->IsPlayerTeammate())
            {
                a->SetSpeakingState(false);
                a->FUN_008ad910(pPlayer, false, false);
            }
        }
    }
}

struct TESFormList
{
    bool _ref_008256d0();
    MobileObject** _ref_006815c0();
    void _ref_00905330(MobileObject**);
    TESFormList* GetFirst();
};
struct MobileObjectStub
{
    bool FUN_009bec50(float);
};
// Walks the list at self+0x70 and removes entries whose Projectile returns true from FUN_009bec50(0.0f).
// @fnv 0x00975080
void __fastcall FUN_00975080(char* self)
{
    if (!((TESFormList*)(self + 0x70))->_ref_008256d0())
    {
        TESFormList* prev = (TESFormList*)(self + 0x70);
        TESFormList* cur = prev;
        bool b;
        while (cur && !cur->_ref_008256d0())
        {
            MobileObject* ref = *cur->_ref_006815c0();
            b = false;
            {
                Projectile* pProjectile = dynamic_cast<Projectile*>(ref);
                if (pProjectile)
                {
                    b = ((MobileObjectStub*)pProjectile)->FUN_009bec50(0.0f);
                }
            }
            if (b)
            {
                ((TESFormList*)(self + 0x70))->_ref_00905330(&ref);
                if (cur != prev)
                    cur = prev->GetFirst();
            }
            else
            {
                prev = cur;
                cur = cur->GetFirst();
            }
        }
    }
}

struct FUN_00975f90_virt
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
    virtual bool vlast();
};
struct FUN_00975f90_act
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
    virtual bool vlast(int);
};
struct FUN_00975f90_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void ClearMobileObjectData();
};
// @fnv 0x00975f90
void FUN_00975f90_cls::ClearMobileObjectData()
{
    MobileObject* pmob = 0;
    for (unsigned int i = 0; i < pa.GetTail((PROCESS_TYPE)0); i++)
    {
        pmob = pa.GetItem(i);
        FUN_00975f90_act* a = 0;
        if (pmob && ((FUN_00975f90_virt*)pmob)->vlast() && !((FUN_00975f90_act*)pmob)->vlast(0))
        {
            a = (FUN_00975f90_act*)pmob;
            if (a)
                ((TESForm*)a)->TESForm::ClearData();
        }
    }
}

struct NiAVObject;
struct TESObjectLIGH;
struct TESObjectWEAP;
struct MuzzleFlash
{
    void Init(TESObjectREFR*);
    void Update(float, TESObjectREFR*);
    void SetParentRef(TESObjectREFR*);
    void Enable();
    void AttachLight();
    void UpdateMagicCaster();
    void DisableMuzzleFlash();
    bool GetEnabled();
    NiAVObject* FindAVObject();
    BGSProjectile* GetProjectileData();
    TESObjectWEAP* GetWeaponSource();
    TESModel* GetMuzzleFlashModel();
    TESObjectLIGH* GetMuzzleFlashLight();
    TESObjectREFR* GetParentRef();
    void SetDurationTimer(float);
    static void TriggerMuzzleFlash(TESObjectREFR*, Projectile*);
    void* __vecDelDtor(unsigned int);
    bool bEnabled;
    bool bMPSEnabled;
    bool bUpdateLight;
    char _pad_3[1];
    float m_fDurationTimer;
    float m_fFlashDuration;
    char pChild[4];
    char m_pMenuLight[4];
    BGSProjectile* pProjectile;
    TESObjectWEAP* m_pFiringWeapon;
    TESObjectREFR* m_pParentRef;
};
typedef char _sizecheck_MuzzleFlash[sizeof(MuzzleFlash) == 32 ? 1 : -1];
struct FUN_00978890_shell : public ProcessLists
{
    void UpdateMuzzleFlashes(float);
};

struct FUN_00978890_m
{
    unsigned char GetKey();
    unsigned int GetMinLevel();
    void FUN_009bb080(float, unsigned int);
};
struct FUN_00978890_list
{
    bool _ref_008256d0();
    MuzzleFlash** _ref_006815c0();
    FUN_00978890_list* GetFirst();
    void _ref_00905330(MuzzleFlash**);
};
struct FUN_00978890_cls
{
    char pad[0x68];
    FUN_00978890_list list;
    void UpdateMuzzleFlashes(float dt);
};
// Iterates the muzzle flash list, updates each flash with dt and its min level, and removes flashes whose key is zero.
// @fnv 0x00978890
void FUN_00978890_cls::UpdateMuzzleFlashes(float dt)
{
    if (!list._ref_008256d0())
    {
        FUN_00978890_list* pCurrentElementNext = &list;
        bool bfirst = true;
        while (pCurrentElementNext)
        {
            MuzzleFlash* pflash = *pCurrentElementNext->_ref_006815c0();
            if (!bfirst)
                pCurrentElementNext = pCurrentElementNext->GetFirst();
            bool bremove = pflash != 0;
            if (pflash)
            {
                bremove = !((FUN_00978890_m*)pflash)->GetKey();
                ((FUN_00978890_m*)pflash)->FUN_009bb080(dt, ((FUN_00978890_m*)pflash)->GetMinLevel());
                if (bremove)
                {
                    list._ref_00905330(&pflash);
                    MuzzleFlash* t1 = pflash;
                    MuzzleFlash* t2 = t1;
                    t2 ? t2->__vecDelDtor(1) : 0;
                }
            }
            if (!bremove && bfirst)
            {
                pCurrentElementNext = pCurrentElementNext->GetFirst();
                bfirst = false;
            }
        }
    }
}

extern int DAT_0108c23c;
class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};

// @fnv 0x00978e70
void* __fastcall FUN_00978e70(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0108c23c;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(pThis)->FUN_006b3eb0(0, false);
    return pThis;
}

struct _LARGE_INTEGER
{
    long HighPart;
    unsigned long LowPart;
};
typedef char _sizecheck__LARGE_INTEGER[sizeof(_LARGE_INTEGER) == 8 ? 1 : -1];
struct FUN_0096b050_shell : public ProcessLists
{
    void UpdateLowProcesses(float, bool);
};

struct MobileObjectExt
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void Update(float afDelta);
    void SetCurrentProcess(BaseProcess* apProcess);
    void FUN_00565870();
};

class LowProcess
{
  public:
    float FUN_007df1f0();
    void ResetPackageState();
};

class Calendar
{
  public:
    float GetGameTime();
};

struct SettingT_GameSettingCollection_
{
    void* vptr_;
    SETTING_VALUE uValue;
    SETTING_VALUE* Int();
};

struct PathfindQueueStorage
{
    void FUN_0096aaf0(MobileObject* apObject, int aeLevel);
};

__declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* apCount);
bool __fastcall FUN_00437bb0(MobileObject* apObject);
int __fastcall FUN_004f8960(void* apActor);
bool __cdecl FUN_005ac740();

extern Calendar g_calendar;
extern SettingT_GameSettingCollection_ g_011e0e64;
extern __int64 DAT_011e0e20;
extern unsigned int DAT_011e0e30;
extern bool DAT_011e0e34;
extern RecursiveSpinLock DAT_011f11a0;
extern const double _gModifierZero;

// @fnv 0x0096b050
void FUN_0096b050_shell::UpdateLowProcesses(float afDelta, bool abSleeping)
{
    bool bstopflag;
    BSSimpleList<MobileObject*>* TempList;
    BaseProcess* pproc;
    BSSimpleList<MobileObject*>* plisttemp;
    unsigned int ihigh;
    unsigned int iProcessIndex;
    MobileObject* pmob;
    __int64 imaxTime;
    float fcurrenthour;
    bool bfirst;

    pmob = 0;
    TempList = new BSSimpleList<MobileObject*>;
    iProcessIndex = 0;
    QueryPerformanceCounter(&imaxTime);
    imaxTime += g_011e0e64.Int()->u * DAT_011e0e20 / 1000;
    bfirst = true;
    ihigh = ((ProcessLists*)this)->m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_LOW);
    if (!DAT_011e0e30 || DAT_011e0e30 >= ihigh)
        DAT_011e0e30 = ((ProcessLists*)this)->m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_LOW);
    iProcessIndex = ihigh;
    if (iProcessIndex > ihigh || abSleeping)
        iProcessIndex = ihigh;
    fcurrenthour = g_calendar.GetGameTime();
    bstopflag = false;
    for (unsigned int i = DAT_011e0e30; i < iProcessIndex && !bstopflag; i++)
    {
        pmob = ((ProcessLists*)this)->m_kMobileObjectProcessList.GetItem(i);
        if (!abSleeping && i % 5 == 0)
        {
            __int64 icurrentTime;
            QueryPerformanceCounter(&icurrentTime);
            if (icurrentTime >= imaxTime)
                bstopflag = true;
        }
        if (pmob)
        {
            pproc = pmob->GetCurrentAIProcess();
            if (pproc && !pmob->IsStillLoading())
            {
                if (pmob->GetDisabled() || pmob->IsDeleted() ||
                    pproc->GetProcessLevel() != PROCESS_TYPE_PROCESS_TYPE_LOW)
                {
                    TempList->AddHead(pmob);
                }
                else if (!DAT_011e0e34)
                {
                    if (FUN_00437bb0(pmob))
                    {
                        float flastprocesstime = ((LowProcess*)pproc)->FUN_007df1f0();
                        if (flastprocesstime == -1.0)
                        {
                            ((LowProcess*)pproc)->ResetPackageState();
                        }
                        else
                        {
                            float fhour = fcurrenthour - flastprocesstime;
                            if (fhour >= 1.0 || fhour < _gModifierZero || afDelta != _gModifierZero)
                            {
                                if (pproc->IsProcessConditionMet())
                                {
                                    ((MobileObjectExt*)pmob)->Update(afDelta);
                                    if (FUN_005ac740())
                                        ((MobileObjectExt*)pmob)->FUN_00565870();
                                    Actor* pact = 0;
                                    if (pmob && pmob->IsActor())
                                        pact = (Actor*)pmob;
                                    if (pact && FUN_004f8960(pact) == 1)
                                        bfirst = false;
                                }
                            }
                        }
                    }
                    else
                    {
                        ((LowProcess*)pproc)->ResetPackageState();
                    }
                }
            }
        }
        DAT_011e0e30 = i + 1;
    }
    plisttemp = TempList;
    while (plisttemp && plisttemp->GetItem())
    {
        pmob = plisttemp->GetItem();
        ((PathfindQueueStorage*)&((ProcessLists*)this)->m_kMobileObjectProcessList)
            ->FUN_0096aaf0(pmob, PROCESS_TYPE_PROCESS_TYPE_LOW);
        if (pmob->GetDisabled())
        {
            DAT_011f11a0.Lock();
            delete pmob->GetCurrentAIProcess();
            ((MobileObjectExt*)pmob)->SetCurrentProcess(0);
            DAT_011f11a0.Unlock();
        }
        plisttemp = plisttemp->GetNext();
    }
    TempList->RemoveAll();
    delete TempList;
}

namespace fnv_0096bcd0 {
namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int aeContext, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}
struct ExtraFollower
{
    void* pVtbl;
    unsigned char m_ucExtraDataType;
    BSExtraData* pNext;
    BSSimpleList<Actor*>* pFollowers;
};
struct ExtraFollowerList
{
    TESPackage* GetPackageOverride();
    void AddFollowerActor(Actor* apActor);
    ExtraFollower* GetExtraFollower();
    void FUN_00422720();
};
struct LivingActor
{
    bool FUN_008b0520();
    TESPackage* GetCurrentAIPackage();
    void RestoreHealth(float afAmount);
    void UpdateLifeState(float afAmount);
};
struct MobileObjectProcess
{
    PROCESS_TYPE GetCurrentProcessLevel();
};
struct BaseProcessUpdate
{
    void FUN_008c8fd0(bool abVal);
    void FUN_00693d50(float afHour);
};
struct ProcessListsUpdate
{
    void FUN_00977130(float afTime);
};
struct MobileObjectHigh : public TESObjectREFR
{
    virtual void StartHighProcess();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void UpdateHigh(float afDelta);
};
struct Calendar
{
    float GetGameTime();
};
struct TimeGlobal
{
    float GetStoredFloatValue();
};
extern Calendar g_calendar;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern bool DAT_011e0e34;
extern float _DAT_010162c0;
void __cdecl FUN_008c8bd0();

struct ProcessListsHigh : public ProcessLists
{
    void FUN_0096bcd0(float afDelta, bool abSleeping);
};

// @fnv 0x0096bcd0
void ProcessListsHigh::FUN_0096bcd0(float afDelta, bool abSleeping)
{
    lc1::AutoMemContext tempMemContext(0x2a, true,
                                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\ProcessLists.cpp", 0x235);
    FUN_008c8bd0();
    int iupdated = 0;
    int inotupdated = 0;
    m_iMobileObjectCount = 0;
    MobileObject* pmob = 0;
    for (unsigned int i = m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); i++)
    {
        pmob = m_kMobileObjectProcessList.GetItem(i);
        if (pmob && !pmob->IsStillLoading())
        {
            if (!pmob->IsDeleted() && !pmob->GetDisabled() && pmob->GetCurrentAIProcess() &&
                ((MobileObjectProcess*)pmob)->GetCurrentProcessLevel() == PROCESS_TYPE_PROCESS_TYPE_HIGH &&
                !DAT_011e0e34)
            {
                Actor* pact = 0;
                bool updatefollower = true;
                if (pmob && pmob->IsActor())
                {
                    pact = (Actor*)pmob;
                    m_iMobileObjectCount++;
                }
                if (pact && ((LivingActor*)pact)->FUN_008b0520())
                {
                    pact->GetCurrentAIProcess()->CheckForNewPackage(pact, false);
                    updatefollower = false;
                    inotupdated++;
                    ((BaseProcessUpdate*)pact->GetCurrentAIProcess())->FUN_008c8fd0(true);
                }
                else
                {
                    ((MobileObjectHigh*)pmob)->UpdateHigh(afDelta);
                    iupdated++;
                }
                if (pact && g_thePlayer->IsSleepingOrResting())
                {
                    ((LivingActor*)pact)->RestoreHealth(_DAT_010162c0);
                    ((LivingActor*)pact)->UpdateLifeState(_DAT_010162c0);
                }
                if (updatefollower)
                {
                    ExtraFollower* pfollow =
                        pmob->GetExtra() ? ((ExtraFollowerList*)pmob->GetExtra())->GetExtraFollower() : 0;
                    if (pfollow)
                    {
                        BSSimpleList<Actor*>* pCurrentElementNext;
                        BSSimpleList<Actor*>* pHead;
                        BSSimpleList<Actor*>* pTempList;
                        BSSimpleList<Actor*>* ptemp;
                        pTempList = new BSSimpleList<Actor*>;
                        pHead = new BSSimpleList<Actor*>;
                        pCurrentElementNext = pHead;
                        ptemp = pfollow->pFollowers;
                        while (ptemp && ptemp->GetItem())
                        {
                            pHead->AddTail(ptemp->GetItem());
                            ptemp = ptemp->GetNext();
                        }
                        while (pCurrentElementNext && pCurrentElementNext->GetItem())
                        {
                            Actor* ptarget = pCurrentElementNext->GetItem();
                            if (ptarget && ptarget != g_thePlayer && ptarget->GetCurrentAIProcess())
                            {
                                TESPackage* pEditorpack;
                                TESPackage* ptargpack = ((LivingActor*)ptarget)->GetCurrentAIPackage();
                                pEditorpack = ((ExtraFollowerList*)ptarget->GetExtra())->GetPackageOverride();
                                if (pEditorpack)
                                    ptargpack = pEditorpack;
                                if (!ptargpack || (ptargpack->GetPackType() != 1 && ptargpack->GetPackType() != 7))
                                {
                                    pTempList->AddHead(ptarget);
                                }
                                else
                                {
                                    PROCESS_TYPE etype = ((MobileObjectProcess*)ptarget)->GetCurrentProcessLevel();
                                    if (etype != PROCESS_TYPE_PROCESS_TYPE_HIGH)
                                    {
                                        float time = afDelta;
                                        if (time <= 0.0)
                                            time = 3600.0f;
                                        ((BaseProcessUpdate*)ptarget->GetCurrentAIProcess())
                                            ->FUN_00693d50(g_calendar.GetGameTime() - 1.0);
                                    }
                                }
                            }
                            pCurrentElementNext = pCurrentElementNext->GetNext();
                        }
                        pCurrentElementNext = pTempList;
                        while (pCurrentElementNext && pCurrentElementNext->GetItem())
                        {
                            Actor* ptarget = pCurrentElementNext->GetItem();
                            ((ExtraFollowerList*)pmob->GetExtra())->AddFollowerActor(ptarget);
                            pCurrentElementNext = pCurrentElementNext->GetNext();
                        }
                        pTempList->RemoveAll();
                        delete pTempList;
                        pHead->RemoveAll();
                        delete pHead;
                        if (pfollow->pFollowers->IsEmpty())
                            ((ExtraFollowerList*)pmob->GetExtra())->FUN_00422720();
                    }
                }
            }
            else if (pmob->GetDisabled())
            {
                AddMobileObjectToList(pmob);
            }
        }
    }
    ((ProcessListsUpdate*)this)->FUN_00977130(g_timeGlobal.GetStoredFloatValue());
}
}  // namespace fnv_0096bcd0

namespace fnv_00977cb0 {
struct FUN_00977cb0_shell : public ProcessLists
{
    void StartActorDialogue(int, TESObjectREFR*, bool);
};

struct Setting_S
{
    float* Float();
};
struct BSSpinLockS
{
    void Lock(const char*);
    void Unlock();
};
struct PCH
{
    bool HasCombatState();
};
struct Ref_S
{
    float GetDistanceToReference(void*, bool, bool);
};
struct RefUse
{
    bool CanBeUsed(Actor*, bool);
};
struct ActorDetect
{
    int CalculateDetectionLevel(int, Actor*, bool*, bool, int, bool, bool*);
    bool UpdateActorPackageState(int);
};
struct FUN_00884480_shell
{
    bool FUN_00884480();
};
struct FUN_008bc3d0_shell
{
    void FUN_008bc3d0(TESTopic*);
};
bool __fastcall FUN_008a67f0(Actor*);
struct ProcStub
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
    virtual bool IsInDialogue();
};
struct PC7d
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual Actor* GetDialogueTarget();
};
extern double _gModifierZero;
extern Setting_S originalRuntimeFloatSetting1062;
extern Setting_S originalRuntimeFloatSetting1060;
extern PC7d* g_thePlayer;

// Picks a nearby actor for the given dialogue action, validates it, and starts a topic on it, resetting the cooldown timer.
// @fnv 0x00977cb0
void FUN_00977cb0_shell::StartActorDialogue(int eaction, TESObjectREFR* apObject, bool abMakecomment)
{
    if (!eaction)
        return;
    int iElementIndex = 0;
    if (*(float*)((char*)this + 0x154) <= _gModifierZero || abMakecomment)
    {
        Actor* pTalk = 0;
        bool blineofsight = false;
        int idistance = 350;
        if (eaction == 9)
        {
            iElementIndex = 8;
            pTalk = g_thePlayer->GetDialogueTarget();
            if (pTalk)
            {
                if (pTalk->Unk_85() == 9 || !((FUN_00884480_shell*)pTalk)->FUN_00884480() || pTalk->IsDead(false) ||
                    ((PCH*)pTalk)->HasCombatState() ||
                    (((ActorDetect*)pTalk)->UpdateActorPackageState(4) && !pTalk->IsPlayerTeammate()) ||
                    ((Ref_S*)pTalk)->GetDistanceToReference(g_thePlayer, false, false) > idistance)
                    pTalk = 0;
                else if (FUN_008a67f0(pTalk) && ((ProcStub*)pTalk->GetCurrentAIProcess())->IsInDialogue() &&
                         ((ActorDetect*)pTalk)
                                 ->CalculateDetectionLevel(0, (Actor*)g_thePlayer, &blineofsight, false, 0, false, 0) <=
                             0)
                    pTalk = 0;
            }
        }
        else
        {
            ((BSSpinLockS*)((char*)this + 0x10300))->Lock(0);
            int icurActor = 0;
            while (icurActor < *(int*)((char*)this + 0x150) && !pTalk)
            {
                Actor* pact = ((Actor**)((char*)this + 0x88))[icurActor];
                bool bsetactor = true;
                bool bisTeammate = pact ? pact->IsPlayerTeammate() : false;
                if (pact && pact->GetCurrentAIProcess() && pact->Unk_85() != 9 &&
                    ((FUN_00884480_shell*)pact)->FUN_00884480() && !FUN_008a67f0(pact) &&
                    !((ProcStub*)pact->GetCurrentAIProcess())->IsInDialogue() &&
                    ((ActorDetect*)pact)
                            ->CalculateDetectionLevel(0, (Actor*)g_thePlayer, &blineofsight, false, 0, false, 0) > 0 &&
                    (!((ActorDetect*)pact)->UpdateActorPackageState(4) || bisTeammate) &&
                    ((Ref_S*)pact)->GetDistanceToReference(g_thePlayer, false, false) < idistance &&
                    !pact->IsDead(false) && !((PCH*)pact)->HasCombatState())
                {
                    if (eaction == 7 || eaction == 5)
                    {
                        if (!apObject || !((RefUse*)apObject)->CanBeUsed(pact, true) ||
                            *(float*)((char*)this + 0x158) > _gModifierZero)
                            bsetactor = false;
                        else
                            *(float*)((char*)this + 0x158) = *originalRuntimeFloatSetting1062.Float();
                    }
                    if (bsetactor)
                        pTalk = pact;
                }
                icurActor++;
                if (icurActor >= *(int*)((char*)this + 0x150) && idistance < 1000 && !pTalk)
                {
                    icurActor = 0;
                    idistance += 200;
                }
            }
            ((BSSpinLockS*)((char*)this + 0x10300))->Unlock();
        }
        switch (eaction)
        {
        case 1:
            iElementIndex = 1;
            if (((PCH*)g_thePlayer)->HasCombatState())
                pTalk = 0;
            break;
        case 2:
            iElementIndex = 2;
            if (((PCH*)g_thePlayer)->HasCombatState())
                pTalk = 0;
            break;
        case 3:
            iElementIndex = 3;
            if (((PCH*)g_thePlayer)->HasCombatState() || (pTalk && pTalk->IsPlayerTeammate()))
                pTalk = 0;
            break;
        case 4:
            iElementIndex = 4;
            break;
        case 5:
            iElementIndex = 5;
            break;
        case 6:
            iElementIndex = 6;
            break;
        case 7:
            iElementIndex = 7;
            break;
        case 10:
            iElementIndex = 9;
            break;
        case 8:
            iElementIndex = 10;
            break;
        case 11:
            iElementIndex = 13;
            break;
        case 12:
            iElementIndex = 14;
            break;
        }
        if (pTalk)
        {
            TESTopic* pTopic = TESTopic::GetAudioBackendData(DIALOGUE_TYPE_DT_TOPIC, iElementIndex);
            ((FUN_008bc3d0_shell*)pTalk)->FUN_008bc3d0(pTopic);
            *(float*)((char*)this + 0x154) = *originalRuntimeFloatSetting1060.Float();
        }
    }
}
}  // namespace fnv_00977cb0

namespace fnv_008661e0 {
extern "C" void* __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);

// @fnv 0x008661e0
void* __cdecl FUN_008661e0(void* apDest, unsigned int aiDestSize, const void* apSrc, unsigned int aiCount)
{
    return FUN_00ec7ce3(apDest, aiDestSize, apSrc, aiCount);
}
}  // namespace fnv_008661e0

struct FUN_0096cc80_shell
{
    char m_00[0x50];
    unsigned char m_50;
    void __thiscall SetByte50(unsigned char value);
};

// @fnv 0x0096cc80
void __thiscall FUN_0096cc80_shell::SetByte50(unsigned char value)
{
    m_50 = value;
}

struct FUN_00973a90_shell
{
    char pad[0x66d];
    unsigned char GetByteAtOffset();
};

// @fnv 0x00973a90
unsigned char FUN_00973a90_shell::GetByteAtOffset()
{
    return pad[0x66c];
}

// @fnv 0x00978400
char __fastcall GetField18Byte(char* thisPtr)
{
    return thisPtr[0x18];
}

struct FUN_0096abc0_stub
{
    int __thiscall FindKeyIndex(int, int);
};

struct FUN_0096aa40_stub
{
    void __thiscall FUN_0096aa40(int);
};

struct FUN_0096aaf0_shell
{
    void FUN_0096aaf0(int arg1, int arg2);
};

// Calls FindKeyIndex with arg1 and arg2, then passes its result to FUN_0096aa40.
// @fnv 0x0096aaf0
void FUN_0096aaf0_shell::FUN_0096aaf0(int arg1, int arg2)
{
    int r = ((FUN_0096abc0_stub*)this)->FindKeyIndex(arg1, arg2);
    ((FUN_0096aa40_stub*)this)->FUN_0096aa40(r);
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct TESAnimGroup;
struct TESIdleForm;
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];
struct IndexedTaskData
{
    static void TaskFunc(void*);
    int* m_pIntegerData;
    void* pData;
    unsigned int iSize;
    unsigned int iIndex;
};
typedef char _sizecheck_BSParallelArrayTask[sizeof(IndexedTaskData) == 16 ? 1 : -1];
struct FUN_0096c970_shell : public ProcessLists
{
    void FUN_0096c970();
};

template <class T, unsigned int N> class BSScrapArray
{
  public:
    BSScrapArray();
    virtual ~BSScrapArray();
    unsigned int Add(T& item);
    unsigned int GetTarget();
    T* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
};
struct GlobalObject_0045cf30
{
    bool* GetLifeStateControlFlag();
};
extern GlobalObject_0045cf30 g_011f1260;
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct AnimUpdateHelper
{
    bool FUN_00493930();
};
struct MobileLightHelper
{
    void SetByteAt14E(bool);
};
void __cdecl FUN_0096cb20(unsigned int, void*);
struct FUN_0087cf10_shell
{
    FUN_0087cf10_shell* Construct(void(__cdecl*)(unsigned int, void*), void*, unsigned int);
};
struct TaskQueueParallelManager
{
    void FUN_00c44c90(void*);
};
extern TaskQueueParallelManager* DAT_01202df4;

// @fnv 0x0096c970
void FUN_0096c970_shell::FUN_0096c970()
{
    unsigned int ifirstActor = m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
    bool buseParallelTask;
    unsigned int ilastActor = m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH);
    unsigned int inumActors = ilastActor - ifirstActor;
    buseParallelTask = *g_011f1260.GetLifeStateControlFlag();
    if (inumActors)
    {
        BSScrapArray<Animation*, 1024> animationArray;
        for (unsigned int i = ifirstActor; i < ilastActor; ++i)
        {
            MobileObject* pMobile = m_kMobileObjectProcessList.GetItem(i);
            if (pMobile && pMobile->IsActor())
            {
                Animation* panim = (Animation*)pMobile->GetAnimData();
                if (panim)
                {
                    bool bupdated = true;
                    if (buseParallelTask)
                        animationArray.Add(panim);
                    else
                        bupdated = ((AnimUpdateHelper*)panim)->FUN_00493930();
                    if (((Actor*)pMobile)->FUN_0096c950() && bupdated)
                    {
                        NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->RemoveSceneObject(
                            (NiAVObject*)pMobile->GetNiNode(), false);
                        ((MobileLightHelper*)pMobile)->SetByteAt14E(false);
                    }
                }
            }
        }
        if (animationArray.GetTarget())
        {
            IndexedTaskData animationArrayTask;
            ((FUN_0087cf10_shell*)&animationArrayTask)
                ->Construct(FUN_0096cb20, &animationArray, animationArray.GetTarget());
            DAT_01202df4->FUN_00c44c90(&animationArrayTask);
        }
    }
}

struct FUN_0096cb50_shell : public ProcessLists
{
    void UpdateHighProcessActors();
};

struct RagH
{
    bool FUN_00552490();
    void SetByte50(unsigned char);
};
struct BSFadeNode
{
    bool FUN_00552470() const;
};
struct ActorDialogueHelper
{
    bool IsInDialogueWithPlayer() const;
    void UpdateRagdollController(unsigned char);
};

// @fnv 0x0096cb50
void FUN_0096cb50_shell::UpdateHighProcessActors()
{
    for (unsigned int i = ((MobileObjectProcessArray*)((char*)this + 4))->GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        MobileObject* pmobile = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(i);
        if (pmobile && pmobile->IsActor())
        {
            Actor* pactor = (Actor*)pmobile;
            bool bhasControllerEnabled =
                *(RagH**)((char*)pactor + 0xac) && (*(RagH**)((char*)pactor + 0xac))->FUN_00552490();
            if (pactor->GetNiNode() && bhasControllerEnabled && !((BSFadeNode*)pactor->GetNiNode())->FUN_00552470() &&
                !((ActorDialogueHelper*)pactor)->IsInDialogueWithPlayer())
            {
                ((ActorDialogueHelper*)pactor)->UpdateRagdollController(1);
            }
            else if (bhasControllerEnabled)
            {
                (*(RagH**)((char*)pactor + 0xac))->SetByte50(1);
            }
        }
    }
}

struct FUN_009707f0_shell
{
    void FUN_009707f0(int value);
};

// @fnv 0x009707f0
void FUN_009707f0_shell::FUN_009707f0(int value)
{
    *(int*)((char*)this + 0xfc) = value;
}

struct ActorAnimHelper
{
    void PickAnimations(float, float);
};
struct FUN_00971ba0_shell
{
    void FUN_00971ba0();
};

// Iterates the list at this+4 and, for each non-null entry cast to Actor, calls Unk_81(1) and PickAnimations(1.0f, 1.0f).
// @fnv 0x00971ba0
void FUN_00971ba0_shell::FUN_00971ba0()
{
    MobileObject* pCurrentObject = 0;
    for (unsigned int i = 0; i < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail((PROCESS_TYPE)0); ++i)
    {
        pCurrentObject = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(i);
        Actor* pactor = 0;
        if (pCurrentObject)
            pactor = (Actor*)pCurrentObject;
        if (pactor)
        {
            pactor->Unk_81(1);
            ((ActorAnimHelper*)pactor)->PickAnimations(1.0f, 1.0f);
        }
    }
}

namespace fnv_009724e0 {
class TESFormList
{
  public:
    MobileObject** _ref_006815c0();
    TESFormList* GetFirst();
};
struct TESResponse
{
    int GetNext();
};
struct FUN_009724e0_shell
{
    MobileObject* FindMobileObjectByValue(int, int);
};

// Scans the list at this+0x44 indexed by iList for a MobileObject whose GetNext() equals iValue, returning the first match or null.
// @fnv 0x009724e0
MobileObject* FUN_009724e0_shell::FindMobileObjectByValue(int iList, int iValue)
{
    if (iList <= -1 || iList > 5)
        return 0;
    MobileObject* pRet;
    TESFormList* pNode = ((TESFormList**)((char*)this + 0x44))[iList];
    TESFormList* pCurrent = pNode;
    pRet = 0;
    while (pCurrent && *pCurrent->_ref_006815c0() && !pRet)
    {
        MobileObject* pObject = *pCurrent->_ref_006815c0();
        pCurrent = pCurrent->GetFirst();
        if (((TESResponse*)pObject)->GetNext() == iValue)
            pRet = pObject;
    }
    return pRet;
}
}  // namespace fnv_009724e0

namespace fnv_00974af0 {
class TESFormList
{
  public:
    NiPointer<BSTempEffect>* _ref_006815c0();
    TESFormList* GetFirst();
};
struct MagicHitEffect
{
    char* GetData();
    void SetByteAt24(unsigned char);
};
struct FUN_00974af0_shell
{
    void FUN_00974af0(char*);
};

// @fnv 0x00974af0
void FUN_00974af0_shell::FUN_00974af0(char* apTarget)
{
    if (!((BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x60))->IsEmpty())
    {
        TESFormList* pIter = (TESFormList*)((char*)this + 0x60);
        while (pIter)
        {
            BSTempEffect* pEffect = *pIter->_ref_006815c0();
            if (pEffect && FUN_0043b300((const NiRTTI*)&g_011dc804, (NiAVObject*)pEffect))
            {
                MagicHitEffect* pHitEffect = (MagicHitEffect*)pEffect;
                if (pHitEffect->GetData() == apTarget)
                    pHitEffect->SetByteAt24(1);
            }
            pIter = pIter->GetFirst();
        }
    }
}
}  // namespace fnv_00974af0

namespace fnv_00977660 {
struct FUN_00977660_shell : public ProcessLists
{
    void FUN_00977660();
};

struct Setting_S
{
    float* Float();
};
struct Ref_S
{
    float GetDistanceToReference(void*, bool, bool);
};
struct FUN_0096e570_shell
{
    void FUN_0096e570();
};
void* __cdecl MemsetWrapper(void*, int, unsigned int);
extern Setting_S originalRuntimeFloatSetting248;
struct ProcessListsInsertHelper
{
    void FUN_0096e3c0(Actor*);
};

// @fnv 0x00977660
void FUN_00977660_shell::FUN_00977660()
{
    ((RecursiveSpinLock*)((char*)this + 0x10300))->Lock(0);
    *(unsigned int*)((char*)this + 0x150) = 0;
    MemsetWrapper((char*)this + 0x88, 0, 200);
    ((RecursiveSpinLock*)((char*)this + 0x10300))->Unlock();
    MobileObject* pCurrentObject = 0;
    Actor* pactor = 0;
    for (unsigned int i = 0;
         i < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        pCurrentObject = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(i);
        if (pCurrentObject && pCurrentObject->IsActor())
            pactor = (Actor*)pCurrentObject;
        if (pactor)
        {
            float fdistancefromplayer = ((Ref_S*)pactor)->GetDistanceToReference(pPlayer, false, false);
            if (fdistancefromplayer < *originalRuntimeFloatSetting248.Float())
                ((ProcessListsInsertHelper*)&g_kProcessLists)->FUN_0096e3c0(pactor);
        }
    }
    ((FUN_0096e570_shell*)&g_kProcessLists)->FUN_0096e570();
}
}  // namespace fnv_00977660

struct ActorMagicHelper
{
    void ConfigureActorState(bool, bool);
};
struct FUN_009784c0_shell
{
    void FUN_009784c0();
};

// @fnv 0x009784c0
void FUN_009784c0_shell::FUN_009784c0()
{
    MobileObject* pObject = 0;
    for (unsigned int i = ((MobileObjectProcessArray*)((char*)this + 4))->GetHead((PROCESS_TYPE)0);
         i < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail((PROCESS_TYPE)0); ++i)
    {
        pObject = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(i);
        if (pObject && pObject->IsActor())
        {
            Actor* pActor = (Actor*)pObject;
            ((ActorMagicHelper*)pActor)->ConfigureActorState(false, false);
        }
    }
}

struct FUN_00973a70_shell
{
    void __thiscall SetByteAt66c(char arg);
};

// @fnv 0x00973a70
void __thiscall FUN_00973a70_shell::SetByteAt66c(char acValue)
{
    ((char*)this)[0x66c] = acValue;
}

namespace fnv_0096cb20 {
struct AnimUpdateHelper
{
    bool FUN_00493930();
};
// Retrieves the element at index from the array, casts it to AnimUpdateHelper, and returns the result of FUN_00493930 on it.
// @fnv 0x0096cb20
bool FUN_0096cb20(BSSimpleArray<unsigned int, 1024>* array, int index)
{
    BSSimpleArray<unsigned int, 1024>* pArray = array;
    AnimUpdateHelper* pHelper = (AnimUpdateHelper*)pArray->GetAt(index);
    return pHelper->FUN_00493930();
}
}  // namespace fnv_0096cb20

struct FakeObj
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
    virtual bool Check(float);
};
struct ParentSpaceNode
{
    FakeObj* unk0;
    float unk4;
    unsigned char unk8;
    unsigned char unk9;
};
// Calls Check on the node's object with the node's float and sets the node's byte at offset 9 to 1 when the check fails.
// @fnv 0x00974960
void MarkNodeIfCheckFails(BSSimpleArray<ParentSpaceNode, 1024>* pArray, int iIndex)
{
    BSSimpleArray<ParentSpaceNode, 1024>* pArr = pArray;
    {
        ParentSpaceNode* pNode = &pArr->GetAt(iIndex);
        if (!pNode->unk0->Check(pNode->unk4))
            pNode->unk9 = 1;
    }
}

extern double DAT_01011598;
struct FUN_009781a0_shell
{
    char _pad[0x154];
    float _154;
    void FUN_009781a0();
};
// Adds the global double DAT_01011598 to the float at offset 0x154.
// @fnv 0x009781a0
void FUN_009781a0_shell::FUN_009781a0()
{
    _154 += DAT_01011598;
}

namespace fnv_0096c860 {
struct C00493930
{
    bool FUN_00493930();
};
struct FUN_00496960_shell
{
    void SetByteAt14E(unsigned char);
};
struct NiAdditionalGeometryData
{
    static NiAVObject* GetShadowSceneNodeForIndex(int);
};
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
struct FUN_0096c860_shell : ProcessLists
{
    void FUN_0096c860();
};
// @fnv 0x0096c860
void FUN_0096c860_shell::FUN_0096c860()
{
    unsigned int i = ((MobileObjectProcessArray*)((char*)this + 4))->GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
    for (; i < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail(PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH); ++i)
    {
        MobileObject* pMobile = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(i);
        if (pMobile && pMobile->IsActor())
        {
            AnimData* panim = pMobile->GetAnimData();
            bool bupdated = false;
            if (panim)
                bupdated = ((C00493930*)panim)->FUN_00493930();
            if (((Actor*)pMobile)->FUN_0096c950() && bupdated)
            {
                ((ShadowSceneNode*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
                    ->RemoveSceneObject((NiAVObject*)pMobile->GetNiNode(), false);
                ((FUN_00496960_shell*)pMobile)->SetByteAt14E(0);
            }
        }
    }
}
}  // namespace fnv_0096c860

struct Flt
{
    operator unsigned int();
};
extern const NiRTTI g_011d6b04;
struct MiddleHighProcess
{
    void FUN_00929260(unsigned char);
};
struct BSTempEffectGeometryDecal
{
    NiPointer<BSTempEffect> operator*();
    void FUN_00929260(unsigned char);
};
struct FUN_00974c30_shell
{
    BSSimpleList<NiPointer<BSTempEffect> > effects;
    void FUN_00974c30();
};
// Iterates the effect list at offset 0x58 and calls FUN_00929260(1) on each decal that passes the RTTI check against g_011d6b04.
// @fnv 0x00974c30
void FUN_00974c30_shell::FUN_00974c30()
{
    if (!((BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x58))->IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* list = (BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x58);
        while (list)
        {
            BSTempEffectGeometryDecal* decal = (BSTempEffectGeometryDecal*)(unsigned int)(*(Flt*)&list->GetItem());
            if (decal && FUN_0043b300(&g_011d6b04, (NiAVObject*)decal))
            {
                MiddleHighProcess* target = (MiddleHighProcess*)decal;
                target->FUN_00929260(1);
            }
            list = list->GetNext();
        }
    }
}

namespace fnv_00978550 {
struct FUN_00978550_shell
{
    void* p;
    MobileObjectProcessArray arr;
    void FUN_00978550();
};

class MobileObjectExt : public MobileObject
{
  public:
    void FUN_00565870();
};

// Iterates the high-process list and calls FUN_00565870 on each entry that is an actor.
// @fnv 0x00978550
void FUN_00978550_shell::FUN_00978550()
{
    MobileObject* actor = 0;
    for (unsigned int index = arr.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         index < arr.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++index)
    {
        actor = arr.GetItem(index);
        if (actor && actor->IsActor())
            reinterpret_cast<MobileObjectExt*>(actor)->FUN_00565870();
    }
}
}  // namespace fnv_00978550

struct Dummy_96cf60
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
    virtual void Exec();
};
// Retrieves the element at index b from the array and calls Exec on it.
// @fnv 0x0096cf60
void ExecElementAt(BSSimpleArray<unsigned int, 0x400>* apArray, int aiIndex)
{
    BSSimpleArray<unsigned int, 0x400>* arr = apArray;
    {
        Dummy_96cf60* obj = reinterpret_cast<Dummy_96cf60*>(arr->GetAt(aiIndex));
        obj->Exec();
    }
}

namespace fnv_00971fd0 {
struct CTSHelper
{
    CTSHelper();
    float GetElapsedTime();
    int m_iPackageData;
};
struct NodeS
{
    bool _ref_008256d0();
    void** _ref_006815c0();
    void _ref_00905330(void* const* item);
};
struct TESFormList
{
    void* GetFirst();
};
struct TESTopicInfoData;
struct TESTopicInfo
{
    TESTopicInfoData* GetConversationData();
    CTSHelper FUN_008bcc60();
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct FUN_009722e0_shell
{
    bool IsActorInOtherList(void* apRef, TESTopicInfo* apInfo);
};
struct FUN_0047eb90_shell
{
    void FUN_0047eb90(int);
};
struct FUN_0041cf00_shell
{
    void* FUN_0041cf00();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void* pItem;
    void* pNext;
};
struct SL : List_009e03e0
{
    SL();
};
struct G2
{
    void AddHead(int*);
};
struct FUN_00971fd0_shell
{
    SL* FUN_00971fd0(float afTime);
};

// @fnv 0x00971fd0
SL* FUN_00971fd0_shell::FUN_00971fd0(float afTime)
{
    SL* pList;
    {
        NodeS* pIter = *(NodeS**)((char*)this + 0x50);
        pList = new SL;
        bool bPickResultFound = false;
        NodeS* pPrev = 0;
        while (pIter && !pIter->_ref_008256d0() && !bPickResultFound)
        {
            TESTopicInfo* pItem = *(TESTopicInfo**)pIter->_ref_006815c0();
            if (pItem->FUN_008bcc60().GetElapsedTime() <= afTime)
            {
                {
                    NodeS* pNode = (NodeS*)pItem->GetConversationData();
                    while (pNode && !pNode->_ref_008256d0())
                    {
                        FUN_0047eb90_shell* pRef = *(FUN_0047eb90_shell**)pNode->_ref_006815c0();
                        if (!((FUN_009722e0_shell*)&g_kProcessLists)->IsActorInOtherList(pRef, pItem))
                            pRef->FUN_0047eb90(0);
                        pNode = (NodeS*)((TESFormList*)pNode)->GetFirst();
                    }
                }
                TESObjectREFR* pTarget = (TESObjectREFR*)((TESObjectREFR_GetFlags_Helper*)pItem)->CallGetFlags();
                if (pTarget && pTarget->IsActor())
                {
                    Actor* pActor = (Actor*)pTarget;
                    NodeS* pActorList = (NodeS*)((FUN_0041cf00_shell*)pActor->GetExtra())->FUN_0041cf00();
                    if (pActorList)
                        pActorList->_ref_00905330((void* const*)&pItem);
                }
                pIter->_ref_00905330((void* const*)&pItem);
                pIter = pPrev;
                if (!pIter)
                    pIter = *(NodeS**)((char*)this + 0x50);
                ((G2*)pList)->AddHead((int*)&pItem);
            }
            else
            {
                pPrev = pIter;
                pIter = (NodeS*)((TESFormList*)pIter)->GetFirst();
            }
        }
    }
    if (((NodeS*)pList)->_ref_008256d0())
    {
        delete (List_009e03e0*)pList;
        pList = 0;
    }
    return pList;
}
}  // namespace fnv_00971fd0

namespace fnv_0096e3c0 {
struct CloningProcess;
struct NiStream;
struct ahkpCharacterProxy;
struct bhkCharacterProxy;
struct BhkPhysicsObject;
struct bhkSerializable;
struct bhkShapePhantom;
struct PhysicsSimulationContext;
struct hkReferencedObject;
struct hkSerializableCinfo;
struct hkStatisticsCollector;
struct hkStepInfo;
struct hkVector4;
struct CharacterProxyConfiguration;
struct Vector4Data;
struct hkpCharacterProxy;
struct hkpCharacterProxyListener;
struct hkpPhantom;
struct hkpShapePhantom;
struct CharacterPhysicsController;
struct hkpSurfaceInfo;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct FUN_0096e3c0_shell : public ProcessLists
{
    void FUN_0096e3c0(Actor*);
};

struct bhkCharacterController_shell
{
    float FUN_008a3b50() const;
};
struct SettingInt
{
    int* Int();
};
extern SettingInt g_011cde2c;
void __cdecl FUN_008661e0(void*, unsigned int, const void*, unsigned int);
struct MobileCharHelper
{
    bhkCharacterController* GetPhysicsCharacterController();
};

// @fnv 0x0096e3c0
void FUN_0096e3c0_shell::FUN_0096e3c0(Actor* apActor)
{
    if (!apActor)
        return;
    float fdist = 3.402823466e+38F;
    bhkCharacterController* pcon = ((MobileCharHelper*)apActor)->GetPhysicsCharacterController();
    if (pcon)
    {
        fdist = ((bhkCharacterController_shell*)pcon)->FUN_008a3b50();
        m_kActorListLock.Lock(0);
        bool ballreadyExists = false;
        for (int icurActor = 0; icurActor < m_iActorCount; ++icurActor)
        {
            if (m_apActorCache[icurActor] == apActor)
            {
                ballreadyExists = true;
                break;
            }
        }
        if (!ballreadyExists)
        {
            int ilocToInsert;
            for (ilocToInsert = 0; ilocToInsert < m_iActorCount; ++ilocToInsert)
            {
                bhkCharacterController* potherCon =
                    ((MobileCharHelper*)m_apActorCache[ilocToInsert])->GetPhysicsCharacterController();
                if (!potherCon)
                    continue;
                if (fdist < ((bhkCharacterController_shell*)potherCon)->FUN_008a3b50())
                    break;
            }
            if (ilocToInsert < 50 && ilocToInsert < *g_011cde2c.Int())
            {
                int inumElementsToCopy = 49 - ilocToInsert;
                ::FUN_008661e0(&m_apActorCache[ilocToInsert + 1], sizeof(m_apActorCache), &m_apActorCache[ilocToInsert],
                               inumElementsToCopy * sizeof(Actor*));
                m_apActorCache[ilocToInsert] = apActor;
                if (m_iActorCount < *g_011cde2c.Int() && m_iActorCount < 50)
                    ++m_iActorCount;
            }
        }
        m_kActorListLock.Unlock();
    }
}
}  // namespace fnv_0096e3c0

namespace fnv_00972570 {
struct TESFormList
{
    TESFormList* GetFirst();
};

Crime** __fastcall _ref_006815c0(void*);

struct Crime_Standin : Crime
{
    TESObjectREFR* GetTarget();
};

struct FUN_00972570_shell
{
    char pad[0x44];
    TESFormList* crimeLists[6];

    Crime* FindCrime(unsigned int formID, TESObjectREFR* target, int crimeType);
};

// Searches the crime list for crimeType for a crime whose form ID and target match, returning it or null.
// @fnv 0x00972570
Crime* FUN_00972570_shell::FindCrime(unsigned int formID, TESObjectREFR* target, int crimeType)
{
    if (!(crimeType > -1 && crimeType <= 5))
        return 0;

    TESFormList* pHead = crimeLists[crimeType];
    TESFormList* pNode = pHead;
    Crime* pInventoryObject = 0;
    while (pNode && *_ref_006815c0(pNode) && !pInventoryObject)
    {
        Crime* pItem = *_ref_006815c0(pNode);
        pNode = pNode->GetFirst();
        if (((TESForm*)pItem)->GetFormID() == formID && ((Crime_Standin*)pItem)->GetTarget() == target)
        {
            pInventoryObject = pItem;
        }
    }
    return pInventoryObject;
}
}  // namespace fnv_00972570

namespace fnv_00974a50 {
struct Flt
{
    operator unsigned int();
};

Flt* __fastcall _ref_006815c0(void*);

struct MagicHitEffect
{
    void SetByteAt24(unsigned int);
};

struct TESFormList
{
    TESFormList* GetFirst();
};

class MagicShaderHitEffect;

struct FUN_00974a50_shell
{
    char pad[0x60];
    BSSimpleList<NiPointer<BSTempEffect> > tempEffects;

    void FUN_00974a50(TESObjectREFR* apEffectTarget, void* apShader);
};

// @fnv 0x00974a50
void FUN_00974a50_shell::FUN_00974a50(TESObjectREFR* apEffectTarget, void* apShader)
{
    if (!tempEffects.IsEmpty())
    {
        TESFormList* pelist = (TESFormList*)&tempEffects;
        while (pelist)
        {
            BSTempEffect* peffect = (BSTempEffect*)_ref_006815c0(pelist)->operator unsigned int();
            if (peffect && FUN_0043b300((const NiRTTI*)&g_011dc804, (NiAVObject*)peffect))
            {
                MagicShaderHitEffect* pshaderEffect = (MagicShaderHitEffect*)peffect;
                if (((BGSTerrainManager*)pshaderEffect)->GetMinLevel() == (unsigned int)apEffectTarget &&
                    ((Script*)pshaderEffect)->GetData() == (char*)apShader)
                {
                    ((MagicHitEffect*)pshaderEffect)->SetByteAt24(1);
                }
            }
            pelist = pelist->GetFirst();
        }
    }
}
}  // namespace fnv_00974a50

namespace fnv_00977130 {
struct ActorPackageData;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct ArrowProjectile;
struct BGSBodyPartData;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct BSBound;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSShaderPPLightingProperty;
struct BipedAnim;
struct ActorCombatGroup;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct FurnitureMark;
struct GuardActorPackageData;
struct HighProcess;
struct BooleanFloatQuery;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct LowProcess;
struct MagicItem;
struct MiddleHighProcess;
struct MiddleLowProcess;
struct DetectionEventData;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiControllerManager;
struct NiNode;
struct TargetDoorController;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PatrolActorPackageData;
struct SpellItem;
struct TESEffectShader;
struct TESFaction;
struct TESIdleForm;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESWorldSpace;
struct bhkCharacterController;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_00977130_shell : public ProcessLists
{
    void FUN_00977130(float);
};

struct ActorQuery_00977130
{
    int FUN_004f8960();
};
bool FUN_00525420();
bool __fastcall FUN_00577de0(Actor*);
extern double _gModifierZero;
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting1023;
extern Setting_S originalRuntimeFloatSetting1024;
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011d08f8;
extern GlobalObject2_0040c150 g_011d0964;
extern GlobalObject2_0040c150 g_011d09a0;
extern GlobalObject2_0040c150 g_011d0cd8;
struct TESResponse
{
    int GetNext();
};
struct Fn56ac90
{
    void* FUN_0056ac90();
};
struct FUN_005722c0_shell
{
    bool FUN_005722c0(int);
};
struct ActorV_S
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual bool IsDisabledOrDeleted();
};
struct HighProcess
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual void V216();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void V233();
    virtual void V234();
    virtual void V235();
    virtual void V236();
    virtual void V237();
    virtual void V238();
    virtual void V239();
    virtual void V240();
    virtual void V241();
    virtual void V242();
    virtual void V243();
    virtual void V244();
    virtual void V245();
    virtual void V246();
    virtual void V247();
    virtual void V248();
    virtual void V249();
    virtual void V250();
    virtual void V251();
    virtual void V252();
    virtual void V253();
    virtual void V254();
    virtual void V255();
    virtual void V256();
    virtual void V257();
    virtual void V258();
    virtual void V259();
    virtual void V260();
    virtual void V261();
    virtual void V262();
    virtual void V263();
    virtual void V264();
    virtual void V265();
    virtual void V266();
    virtual void V267();
    virtual void V268();
    virtual void V269();
    virtual void V270();
    virtual void V271();
    virtual void V272();
    virtual void V273();
    virtual void V274();
    virtual void V275();
    virtual void V276();
    virtual void V277();
    virtual void V278();
    virtual void V279();
    virtual void V280();
    virtual void V281();
    virtual void V282();
    virtual void V283();
    virtual void V284();
    virtual void V285();
    virtual void V286();
    virtual void V287();
    virtual void V288();
    virtual void V289();
    virtual void V290();
    virtual void V291();
    virtual void V292();
    virtual void V293();
    virtual void V294();
    virtual void V295();
    virtual void V296();
    virtual void V297();
    virtual void V298();
    virtual void V299();
    virtual float GetDeadTimer();
    virtual void V301();
    virtual void V302();
    virtual void V303();
    virtual void V304();
    virtual void V305();
    virtual void V306();
    virtual void V307();
    virtual void V308();
    virtual void V309();
    virtual void V310();
    virtual void V311();
    virtual void V312();
    virtual void V313();
    virtual void V314();
    virtual void V315();
    virtual void V316();
    virtual void V317();
    virtual void V318();
    virtual void V319();
    virtual void V320();
    virtual void V321();
    virtual void V322();
    virtual void V323();
    virtual void V324();
    virtual void V325();
    virtual void V326();
    virtual void V327();
    virtual void V328();
    virtual void V329();
    virtual void V330();
    virtual void V331();
    virtual void V332();
    virtual void V333();
    virtual void V334();
    virtual void V335();
    virtual void V336();
    virtual void V337();
    virtual void V338();
    virtual void V339();
    virtual void V340();
    virtual void V341();
    virtual void V342();
    virtual void V343();
    virtual void V344();
    virtual void V345();
    virtual void V346();
    virtual void V347();
    virtual void V348();
    virtual void V349();
    virtual void V350();
    virtual void V351();
    virtual void V352();
    virtual void V353();
    virtual void V354();
    virtual void V355();
    virtual void V356();
    virtual void V357();
    virtual void V358();
    virtual void V359();
    virtual void V360();
    virtual void V361();
    virtual void V362();
    virtual void V363();
    virtual void V364();
    virtual void V365();
    virtual void V366();
    virtual void V367();
    virtual void V368();
    virtual void V369();
    virtual void V370();
    virtual void V371();
    virtual void V372();
    virtual void V373();
    virtual void V374();
    virtual void V375();
    virtual void V376();
    virtual void V377();
    virtual void V378();
    virtual void V379();
    virtual void V380();
    virtual void V381();
    virtual void V382();
    virtual void V383();
    virtual void V384();
    virtual void V385();
    virtual void V386();
    virtual void V387();
    virtual int IsInDialogue();
    void FUN_008feb60(Actor*);
};

// @fnv 0x00977130
void FUN_00977130_shell::FUN_00977130(float afDeltaTime)
{
    *(float*)((char*)this + 0x103bc) -= afDeltaTime;
    if (*(float*)((char*)this + 0x103bc) <= _gModifierZero)
    {
        MobileObject* pCurrentObject;
        bool bcomplex;
        unsigned int ideadCount = 0;
        unsigned int iactorCount = 0;
        int iactorsDead;
        BSSimpleList<Actor*> deadActors;
        int iactorsTotal;
        pCurrentObject = 0;
        for (unsigned int i = 0;
             i < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); i++)
        {
            pCurrentObject = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(i);
            Actor* pactor = 0;
            if (pCurrentObject && pCurrentObject->IsActor() && !pCurrentObject->IsStillLoading())
            {
                iactorCount++;
                Actor* pactor = (Actor*)pCurrentObject;
                if (reinterpret_cast<ActorQuery_00977130*>(pactor)->FUN_004f8960() == 2)
                {
                    BaseProcess* pprocess = pactor->GetCurrentAIProcess();
                    if (pprocess && !((TESResponse*)pprocess)->GetNext())
                    {
                        HighProcess* phigh = (HighProcess*)pprocess;
                        if (!phigh->IsInDialogue() && !((ActorV_S*)pactor)->IsDisabledOrDeleted() &&
                            !FUN_00577de0(pactor) && !((FUN_005722c0_shell*)pactor)->FUN_005722c0(0) &&
                            ((HighProcess*)pprocess)->GetDeadTimer() < _gModifierZero)
                        {
                            if (!((Fn56ac90*)pactor)->FUN_0056ac90() ||
                                ((BSSimpleList<Actor*>*)((Fn56ac90*)pactor)->FUN_0056ac90())->IsEmpty())
                            {
                                ideadCount++;
                                deadActors.AddTail(pactor);
                            }
                        }
                    }
                }
            }
        }
        bcomplex = FUN_00525420();
        if (iactorCount < 25)
            bcomplex = false;
        *(float*)((char*)this + 0x103bc) =
            bcomplex ? *originalRuntimeFloatSetting1024.Float() : *originalRuntimeFloatSetting1023.Float();
        iactorsDead = bcomplex ? *g_011d0964.Int() : *g_011d0cd8.Int();
        iactorsTotal = bcomplex ? *g_011d08f8.Int() : *g_011d09a0.Int();
        if (ideadCount < iactorsDead || iactorCount < iactorsTotal)
        {
            deadActors.RemoveAll();
            return;
        }
        if (bcomplex)
        {
            BSSimpleList<Actor*>* pCurrentElementNext = &deadActors;
            while (pCurrentElementNext && !pCurrentElementNext->IsEmpty() && ideadCount >= iactorsDead)
            {
                Actor* pactor = pCurrentElementNext->GetItem();
                if (pactor)
                {
                    HighProcess* phigh = (HighProcess*)pactor->GetCurrentAIProcess();
                    phigh->FUN_008feb60(pactor);
                    ideadCount--;
                }
                pCurrentElementNext = pCurrentElementNext->GetNext();
            }
        }
        else
        {
            Actor* poldestDeadActor = 0;
            float foldestDeadTime = 3.402823466e+38f;
            BSSimpleList<Actor*>* pCurrentElementNext = &deadActors;
            while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
            {
                Actor* pactor = pCurrentElementNext->GetItem();
                if (pactor)
                {
                    if (!poldestDeadActor ||
                        ((HighProcess*)pactor->GetCurrentAIProcess())->GetDeadTimer() < foldestDeadTime)
                    {
                        poldestDeadActor = pactor;
                        foldestDeadTime = ((HighProcess*)pactor->GetCurrentAIProcess())->GetDeadTimer();
                    }
                }
                pCurrentElementNext = pCurrentElementNext->GetNext();
            }
            if (poldestDeadActor)
            {
                HighProcess* phigh = (HighProcess*)poldestDeadActor->GetCurrentAIProcess();
                phigh->FUN_008feb60(poldestDeadActor);
            }
        }
        deadActors.RemoveAll();
    }
}
}  // namespace fnv_00977130

struct FUN_009785d0_shell
{
    int unk0;
    MobileObjectProcessArray processes;
    void RemoveDetectionEventsFromActors();
};

// Iterates the high-priority process list and, for each actor, removes its current AI process's detection event.
// @fnv 0x009785d0
void FUN_009785d0_shell::RemoveDetectionEventsFromActors()
{
    MobileObject* pObject = 0;
    for (unsigned int i = processes.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         i < processes.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++i)
    {
        pObject = processes.GetItem(i);
        if (pObject && pObject->IsActor())
        {
            pObject->GetCurrentAIProcess()->RemoveDetectionEvent();
        }
    }
}

struct FUN_0096bc50_shell
{
    unsigned int pad0;
    MobileObjectProcessArray processes;
    unsigned int CountHighProcessActors();
};

// Counts the actors among the high-priority processes by iterating the process list and testing each item with IsActor.
// @fnv 0x0096bc50
unsigned int FUN_0096bc50_shell::CountHighProcessActors()
{
    unsigned int count = 0;
    for (unsigned int index = processes.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         index < processes.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++index)
    {
        MobileObject* object = processes.GetItem(index);
        if (object && object->IsActor())
            ++count;
    }
    return count;
}

struct CrimeListNode
{
    bool vfn_008256d0();
    BGSPerk** GetItem();
    CrimeListNode* GetFirst();
};
struct FUN_00972740_shell
{
    unsigned short FUN_00972740(unsigned int aeType, BGSPerk* apCrime);
};
void FNV_Warning(const char*);
// Walks the crime list for aeType, returning the index of apCrime, or warns and returns 0 if not found.
// @fnv 0x00972740
unsigned short FUN_00972740_shell::FUN_00972740(unsigned int aeType, BGSPerk* apCrime)
{
    unsigned short iElementIndex = 0;
    CrimeListNode* pCurrentElementNext = *(CrimeListNode**)((char*)this + aeType * 4 + 0x44);
    while (pCurrentElementNext && !pCurrentElementNext->vfn_008256d0())
    {
        if (apCrime == *pCurrentElementNext->GetItem())
            return iElementIndex;
        iElementIndex++;
        pCurrentElementNext = pCurrentElementNext->GetFirst();
    }
    FNV_Warning("AI: When trying to get a crime index, the crime was not found in the crime lists.");
    return 0;
}

namespace fnv_00974b80 {
struct TESFormList
{
    void* GetFirst();
};
struct GO
{
    operator unsigned int();
};
struct MagicHitEffect
{
    void SetByteAt24(unsigned int);
};
struct ScriptText
{
    char* GetText();
};
int __cdecl FUN_00408b20(char const*, char const*);
extern const NiRTTI g_011dc724;
struct FUN_00974b80_shell
{
    BSSimpleList<NiPointer<BSTempEffect> > listEffects;
    void FUN_00974b80(unsigned int a, char* b);
};
// @fnv 0x00974b80
void FUN_00974b80_shell::FUN_00974b80(unsigned int uiMinLevel, char* pText)
{
    if (!((BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x60))->IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* node = (BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x60);
        while (node)
        {
            unsigned int effect = (unsigned int)(GO*)(void*)(node->GetItem());
            if (effect && FUN_0043b300(&g_011dc724, (NiAVObject*)(void*)effect))
            {
                MagicHitEffect* pEffect = (MagicHitEffect*)(void*)effect;
                if (((BGSTerrainManager*)pEffect)->GetMinLevel() == uiMinLevel &&
                    !FUN_00408b20(((ScriptText*)pEffect)->GetText(), pText))
                    pEffect->SetByteAt24(1);
            }
            node = (BSSimpleList<NiPointer<BSTempEffect> >*)((TESFormList*)node)->GetFirst();
        }
    }
}
}  // namespace fnv_00974b80

struct Modifier
{
    unsigned char GetKey();
};

struct ConsoleManager
{
    static ConsoleManager* __cdecl Instance(bool create);
    bool IsConsoleActive();
    void Print(char const* text, char const* context);
};

Modifier* __cdecl _FUN_004b7210();
unsigned char __cdecl FUN_005b6f70();

// @fnv 0x00703c00
void __cdecl FUN_00703c00(char const* text, char const* context)
{
    if (_FUN_004b7210() && _FUN_004b7210()->GetKey())
    {
        if (ConsoleManager::Instance(false) && ConsoleManager::Instance(true)->IsConsoleActive() || FUN_005b6f70())
        {
            char const* contextPointer = (char const*)&context;
            ConsoleManager::Instance(true)->Print(text, contextPointer);
            contextPointer = 0;
        }
    }
}

namespace fnv_009721f0 {
extern unsigned int _data_011c16bc;

struct MemoryManager
{
    static void* __cdecl Allocate(unsigned int);
};

struct TESFormList
{
    void* GetFirst();
};

struct LH
{
    bool __thiscall IsInList(int& value);
};

struct G2
{
    void __thiscall AddHead(int* value);
};

struct SL
{
    int field0;
    int field4;

    SL();
};

struct FUN_009721f0_layout
{
    unsigned char padding[0x44];
    SL* bItemFound[5];
};

struct FUN_009721f0_shell
{
    void AddObjectToList(TESFormList* objectList);
};

// If objectList's first value is in [0,4], gets or creates the SL at that index, adds objectList to it if not already present, and stores it back.
// @fnv 0x009721f0
void FUN_009721f0_shell::AddObjectToList(TESFormList* objectList)
{
    if (objectList)
    {
        if ((int)objectList->GetFirst() > -1)
        {
            if ((int)objectList->GetFirst() < 5)
            {
                SL* list = reinterpret_cast<FUN_009721f0_layout*>(this)->bItemFound[(int)objectList->GetFirst()];

                if (!list)
                    list = new SL;

                if (!reinterpret_cast<LH*>(list)->IsInList(reinterpret_cast<int&>(objectList)))
                    reinterpret_cast<G2*>(list)->AddHead(reinterpret_cast<int*>(&objectList));

                reinterpret_cast<FUN_009721f0_layout*>(this)->bItemFound[(int)objectList->GetFirst()] = list;
            }
        }
    }
}
}  // namespace fnv_009721f0

namespace fnv_009754f0 {
struct SaveManager;
struct GameTimerRecord
{
    unsigned int* GetTime() const;
};

struct TESSaveLoadGame
{
    void FUN_008579b0(void* data, int type);
};

struct TESFormList
{
    void* GetFirst();
};

struct _ref_008256d0_shell
{
    unsigned char _ref_008256d0();
};

struct FUN_009ebca0_shell
{
    void WriteToSave();
};

extern SaveManager* DAT_011de45c;

struct FUN_009754f0_shell
{
    void* pad[0x11];
    void* lists[5];

    void FUN_009754f0();
};

// @fnv 0x009754f0
void FUN_009754f0_shell::FUN_009754f0()
{
    reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->FUN_008579b0(&DAT_011e0e2c, 4);

    int i;
    unsigned int* time;
    void* list;

    for (i = 0; i < 5; ++i)
    {
        unsigned short count = 0;
        time = reinterpret_cast<GameTimerRecord*>(DAT_011de45c)->GetTime();
        reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->FUN_008579b0(&count, 2);
        list = lists[i];

        while (list != 0 && !reinterpret_cast<_ref_008256d0_shell*>(list)->_ref_008256d0())
        {
            BGSPerk* perk = reinterpret_cast<BSSimpleList<BGSPerk*>*>(list)->GetItem();
            reinterpret_cast<FUN_009ebca0_shell*>(perk)->WriteToSave();
            ++count;
            list = reinterpret_cast<TESFormList*>(list)->GetFirst();
        }

        *reinterpret_cast<unsigned short*>(time) = count;
    }
}
}  // namespace fnv_009754f0

struct FUN_00975ea0_shell
{
    unsigned int m_unused;
    MobileObjectProcessArray m_processArray;
    void FUN_00975ea0();
};

// Iterates the low and middle-low process arrays and, for each living actor, calls its vtable slot at offset 0x208 with argument 1.
// @fnv 0x00975ea0
void FUN_00975ea0_shell::FUN_00975ea0()
{
    for (int i = 0; i < 2; ++i)
    {
        PROCESS_TYPE level = PROCESS_TYPE_PROCESS_TYPE_LOW;
        switch (i)
        {
        case 0:
            level = PROCESS_TYPE_PROCESS_TYPE_LOW;
            break;
        case 1:
            level = PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW;
            break;
        }

        for (unsigned int index = m_processArray.GetHead(level); index < m_processArray.GetTail(level); ++index)
        {
            MobileObject* object = m_processArray.GetItem(index);
            if (object)
            {
                if (object->IsActor())
                {
                    if (!object->IsDead(false))
                    {
                        MobileObject* target = object;
                        (reinterpret_cast<void(__thiscall*)(MobileObject*, int)>(
                            (*reinterpret_cast<void***>(target))[0x208 / sizeof(void*)]))(target, 1);
                    }
                }
            }
        }
    }
}

bool FUN_009336c0(MobileObject* pCurrentObject);

struct FUN_009336c0_shell
{
    bool FUN_009336c0() const;
};

PlayerCharacter* _g_thePlayer;

struct FUN_00974fc0_V178
{
    virtual void f000() = 0;
    virtual void f001() = 0;
    virtual void f002() = 0;
    virtual void f003() = 0;
    virtual void f004() = 0;
    virtual void f005() = 0;
    virtual void f006() = 0;
    virtual void f007() = 0;
    virtual void f008() = 0;
    virtual void f009() = 0;
    virtual void f010() = 0;
    virtual void f011() = 0;
    virtual void f012() = 0;
    virtual void f013() = 0;
    virtual void f014() = 0;
    virtual void f015() = 0;
    virtual void f016() = 0;
    virtual void f017() = 0;
    virtual void f018() = 0;
    virtual void f019() = 0;
    virtual void f020() = 0;
    virtual void f021() = 0;
    virtual void f022() = 0;
    virtual void f023() = 0;
    virtual void f024() = 0;
    virtual void f025() = 0;
    virtual void f026() = 0;
    virtual void f027() = 0;
    virtual void f028() = 0;
    virtual void f029() = 0;
    virtual void f030() = 0;
    virtual void f031() = 0;
    virtual void f032() = 0;
    virtual void f033() = 0;
    virtual void f034() = 0;
    virtual void f035() = 0;
    virtual void f036() = 0;
    virtual void f037() = 0;
    virtual void f038() = 0;
    virtual void f039() = 0;
    virtual void f040() = 0;
    virtual void f041() = 0;
    virtual void f042() = 0;
    virtual void f043() = 0;
    virtual void f044() = 0;
    virtual void f045() = 0;
    virtual void f046() = 0;
    virtual void f047() = 0;
    virtual void f048() = 0;
    virtual void f049() = 0;
    virtual void f050() = 0;
    virtual void f051() = 0;
    virtual void f052() = 0;
    virtual void f053() = 0;
    virtual void f054() = 0;
    virtual void f055() = 0;
    virtual void f056() = 0;
    virtual void f057() = 0;
    virtual void f058() = 0;
    virtual void f059() = 0;
    virtual void f060() = 0;
    virtual void f061() = 0;
    virtual void f062() = 0;
    virtual void f063() = 0;
    virtual void f064() = 0;
    virtual void f065() = 0;
    virtual void f066() = 0;
    virtual void f067() = 0;
    virtual void f068() = 0;
    virtual void f069() = 0;
    virtual void f070() = 0;
    virtual void f071() = 0;
    virtual void f072() = 0;
    virtual void f073() = 0;
    virtual void f074() = 0;
    virtual void f075() = 0;
    virtual void f076() = 0;
    virtual void f077() = 0;
    virtual void f078() = 0;
    virtual void f079() = 0;
    virtual void f080() = 0;
    virtual void f081() = 0;
    virtual void f082() = 0;
    virtual void f083() = 0;
    virtual void f084() = 0;
    virtual void f085() = 0;
    virtual void f086() = 0;
    virtual void f087() = 0;
    virtual void f088() = 0;
    virtual void f089() = 0;
    virtual void f090() = 0;
    virtual void f091() = 0;
    virtual void f092() = 0;
    virtual void f093() = 0;
    virtual void f094() = 0;
    virtual void f095() = 0;
    virtual void f096() = 0;
    virtual void f097() = 0;
    virtual void f098() = 0;
    virtual void f099() = 0;
    virtual void f100() = 0;
    virtual void f101() = 0;
    virtual void f102() = 0;
    virtual void f103() = 0;
    virtual void f104() = 0;
    virtual void f105() = 0;
    virtual void f106() = 0;
    virtual void f107() = 0;
    virtual void f108() = 0;
    virtual void f109() = 0;
    virtual void f110() = 0;
    virtual void f111() = 0;
    virtual void f112() = 0;
    virtual void f113() = 0;
    virtual void f114() = 0;
    virtual void f115() = 0;
    virtual void f116() = 0;
    virtual void f117() = 0;
    virtual void f118() = 0;
    virtual void f119() = 0;
    virtual void f120() = 0;
    virtual void f121() = 0;
    virtual void f122() = 0;
    virtual void f123() = 0;
    virtual void f124() = 0;
    virtual void f125() = 0;
    virtual void f126() = 0;
    virtual void f127() = 0;
    virtual void f128() = 0;
    virtual void f129() = 0;
    virtual void f130() = 0;
    virtual void f131() = 0;
    virtual void f132() = 0;
    virtual void f133() = 0;
    virtual void f134() = 0;
    virtual void f135() = 0;
    virtual void f136() = 0;
    virtual void f137() = 0;
    virtual void f138() = 0;
    virtual void f139() = 0;
    virtual void f140() = 0;
    virtual void f141() = 0;
    virtual void f142() = 0;
    virtual void f143() = 0;
    virtual void f144() = 0;
    virtual void f145() = 0;
    virtual void f146() = 0;
    virtual void f147() = 0;
    virtual void f148() = 0;
    virtual void f149() = 0;
    virtual void f150() = 0;
    virtual void f151() = 0;
    virtual void f152() = 0;
    virtual void f153() = 0;
    virtual void f154() = 0;
    virtual void f155() = 0;
    virtual void f156() = 0;
    virtual void f157() = 0;
    virtual void f158() = 0;
    virtual void f159() = 0;
    virtual void f160() = 0;
    virtual void f161() = 0;
    virtual void f162() = 0;
    virtual void f163() = 0;
    virtual void f164() = 0;
    virtual void f165() = 0;
    virtual void f166() = 0;
    virtual void f167() = 0;
    virtual void f168() = 0;
    virtual void f169() = 0;
    virtual void f170() = 0;
    virtual void f171() = 0;
    virtual void f172() = 0;
    virtual void f173() = 0;
    virtual void f174() = 0;
    virtual void f175() = 0;
    virtual void f176() = 0;
    virtual void f177() = 0;
    virtual PlayerCharacter* Unk_B2() = 0;
};

struct FUN_00974fc0_shell
{
    void FUN_00974fc0();
};

// Iterates the high-process list, and for each actor that passes FUN_009336c0 and is not the player, calls Unk_A2.
// @fnv 0x00974fc0
void FUN_00974fc0_shell::FUN_00974fc0()
{
    MobileObject* i8;
    unsigned int pMob4;
    Actor* pactor;

    i8 = 0;
    pMob4 = 0;
    for (; pMob4 < ((MobileObjectProcessArray*)((char*)this + 4))->GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++pMob4)
    {
        i8 = ((MobileObjectProcessArray*)((char*)this + 4))->GetItem(pMob4);
        pactor = 0;
        if (i8 && i8->IsActor())
            pactor = (Actor*)i8;
        if (pactor && ((FUN_009336c0_shell*)pactor)->FUN_009336c0() &&
            ((FUN_00974fc0_V178*)pactor)->Unk_B2() != _g_thePlayer)
        {
            pactor->Unk_A2();
        }
    }
}

struct FUN_00978420_actor_base
{
    virtual void M0()
    {}
    virtual void M1()
    {}
    virtual void M2()
    {}
    virtual void M3()
    {}
    virtual void M4()
    {}
    virtual void M5()
    {}
    virtual void M6()
    {}
    virtual void M7()
    {}
    virtual void M8()
    {}
    virtual void M9()
    {}
    virtual void M10()
    {}
    virtual void M11()
    {}
    virtual void M12()
    {}
    virtual void M13()
    {}
    virtual void M14()
    {}
    virtual void M15()
    {}
    virtual void M16()
    {}
    virtual void M17()
    {}
    virtual void M18()
    {}
    virtual void M19()
    {}
    virtual void M20()
    {}
    virtual void M21()
    {}
    virtual void M22()
    {}
    virtual void M23()
    {}
    virtual void M24()
    {}
    virtual void M25()
    {}
    virtual void M26()
    {}
    virtual void M27()
    {}
    virtual void M28()
    {}
    virtual void M29()
    {}
    virtual void M30()
    {}
    virtual void M31()
    {}
    virtual void M32()
    {}
    virtual void M33()
    {}
    virtual void M34()
    {}
    virtual void M35()
    {}
    virtual void M36()
    {}
    virtual void M37()
    {}
    virtual void M38()
    {}
    virtual void M39()
    {}
    virtual void M40()
    {}
    virtual void M41()
    {}
    virtual void M42()
    {}
    virtual void M43()
    {}
    virtual void M44()
    {}
    virtual void M45()
    {}
    virtual void M46()
    {}
    virtual void M47()
    {}
    virtual void M48()
    {}
    virtual void M49()
    {}
    virtual void M50()
    {}
    virtual void M51()
    {}
    virtual void M52()
    {}
    virtual void M53()
    {}
    virtual void M54()
    {}
    virtual void M55()
    {}
    virtual void M56()
    {}
    virtual void M57()
    {}
    virtual void M58()
    {}
    virtual void M59()
    {}
    virtual void M60()
    {}
    virtual void M61()
    {}
    virtual void M62()
    {}
    virtual void M63()
    {}
    virtual void M64()
    {}
    virtual void M65()
    {}
    virtual void M66()
    {}
    virtual void M67()
    {}
    virtual void M68()
    {}
    virtual void M69()
    {}
    virtual void M70()
    {}
    virtual void M71()
    {}
    virtual void M72()
    {}
    virtual void M73()
    {}
    virtual void M74()
    {}
    virtual void M75()
    {}
    virtual void M76()
    {}
    virtual void M77()
    {}
    virtual void M78()
    {}
    virtual void M79()
    {}
    virtual void M80()
    {}
    virtual void M81()
    {}
    virtual void M82()
    {}
    virtual void M83()
    {}
    virtual void M84()
    {}
    virtual void M85()
    {}
    virtual void M86()
    {}
    virtual void M87()
    {}
    virtual void M88()
    {}
    virtual void M89()
    {}
    virtual void M90()
    {}
    virtual void M91()
    {}
    virtual void M92()
    {}
    virtual void M93()
    {}
    virtual void M94()
    {}
    virtual void M95()
    {}
    virtual void M96()
    {}
    virtual void M97()
    {}
    virtual void M98()
    {}
    virtual void M99()
    {}
    virtual void M100()
    {}
    virtual void M101()
    {}
    virtual void M102()
    {}
    virtual void M103()
    {}
    virtual void M104()
    {}
    virtual void M105()
    {}
    virtual void M106()
    {}
    virtual void M107()
    {}
    virtual void M108()
    {}
    virtual void M109()
    {}
    virtual void M110()
    {}
    virtual void M111()
    {}
    virtual void M112()
    {}
    virtual void M113()
    {}
    virtual void M114()
    {}
    virtual void M115()
    {}
    virtual void M116()
    {}
    virtual void M117()
    {}
    virtual void M118()
    {}
    virtual void M119()
    {}
    virtual void M120()
    {}
    virtual void M121()
    {}
    virtual void M122()
    {}
    virtual void M123()
    {}
    virtual void M124()
    {}
    virtual void M125()
    {}
    virtual void M126()
    {}
    virtual void M127()
    {}
    virtual void M128()
    {}
    virtual void M129()
    {}
    virtual void M130()
    {}
    virtual void M131()
    {}
    virtual void M132()
    {}
    virtual void M133()
    {}
    virtual void M134()
    {}
    virtual void M135()
    {}
    virtual void M136()
    {}
    virtual void M137()
    {}
    virtual void M138()
    {}
    virtual void M139()
    {}
    virtual void M140()
    {}
    virtual void M141()
    {}
    virtual void M142()
    {}
    virtual void M143()
    {}
    virtual void M144()
    {}
    virtual void M145()
    {}
    virtual void M146()
    {}
    virtual void M147()
    {}
    virtual void M148()
    {}
    virtual void M149()
    {}
    virtual void M150()
    {}
    virtual void M151()
    {}
    virtual void M152()
    {}
    virtual void M153()
    {}
};

struct FUN_00978420_actor : public FUN_00978420_actor_base
{
    virtual void M154(float f)
    {}
};

struct FUN_00978420_shell
{
    unsigned int m_unknown;
    MobileObjectProcessArray m_processArray;

    void FUN_00978420(float f, int unused);
};

// Iterates the high-priority process array and calls M154(f) on each entry that is an actor.
// @fnv 0x00978420
void FUN_00978420_shell::FUN_00978420(float f, int unused)
{
    MobileObject* pObject5 = 0;
    MobileObject* pActor2 = 0;
    unsigned int index;

    for (index = m_processArray.GetHead(PROCESS_TYPE_PROCESS_TYPE_HIGH);
         index < m_processArray.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); ++index)
    {
        pObject5 = m_processArray.GetItem(index);
        if (pObject5 != 0 && pObject5->IsActor())
        {
            pActor2 = pObject5;
            reinterpret_cast<FUN_00978420_actor*>(pActor2)->M154(f);
        }
    }
}

struct LinkedListNode
{
    int FUN_005ae380();
    void** FUN_006815c0();
    void FUN_00726c60(void** item);
    LinkedListNode* FUN_00726070();
    void FUN_007a8790(int(__cdecl* compare)(void*, void*));
};
// @fnv 0x007a8790
void LinkedListNode::FUN_007a8790(int(__cdecl* compare)(void*, void*))
{
    LinkedListNode* current = this;
    LinkedListNode* previous = 0;
    if (current != 0)
    {
        int iterations = current->FUN_005ae380();
        bool swapped = true;
        while (iterations && swapped)
        {
            swapped = false;
            while (current != 0)
            {
                if (previous != 0)
                {
                    void* currentItem = *current->FUN_006815c0();
                    void* previousItem = *previous->FUN_006815c0();
                    if (compare(previousItem, currentItem) > 0)
                    {
                        current->FUN_00726c60(&previousItem);
                        previous->FUN_00726c60(&currentItem);
                        swapped = true;
                    }
                }
                previous = current;
                current = current->FUN_00726070();
            }
            --iterations;
        }
    }
}

class ProcessLoopObject;

class ProcessLoopObject
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual unsigned char v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual unsigned int v116();
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
    virtual void v154(float f);
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
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned char m_bc;
    void* Get8D6F30();
    unsigned char Get440D80();
    unsigned char Get440DA0();
};

class ProcessLoopX
{
  public:
    unsigned char Get450FF0();
};

struct FUN_0096cca0_shell
{
    unsigned int m_unk0;
    MobileObjectProcessArray m_processArray;
    void FUN_0096cca0();
};

// @fnv 0x0096cca0
void FUN_0096cca0_shell::FUN_0096cca0()
{
    unsigned int i;
    for (i = m_processArray.GetHead((PROCESS_TYPE)0); i < m_processArray.GetTail((PROCESS_TYPE)0); i++)
    {
        ProcessLoopObject* pObject = (ProcessLoopObject*)m_processArray.GetItem(i);
        if (pObject != 0 && pObject->v064())
        {
            ProcessLoopObject* ref = pObject;
            ProcessLoopX* pRecord = (ProcessLoopX*)ref->Get8D6F30();
            if (!(ref->v116() && !ref->Get440D80() && !ref->Get440DA0() && pRecord != 0 && pRecord->Get450FF0()))
            {
                continue;
            }
            if (ref->m_bc != 0)
            {
                ref->v154(0.0f);
            }
        }
    }
}

struct ProcActorStub
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
    virtual bool IsActorV();
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
    virtual void* GetProcessV();
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
    virtual void UpdateV();
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
    unsigned char byteBC;
    bool GetDeleted() const;
    bool GetDisabled();
    void* Get3D() const;
};
bool __fastcall FUN_00450ff0(void* apNode);
void __cdecl ProcTaskFunc(unsigned int, void*);
struct ProcParallelTask
{
    void* m_pIntegerData;
    void* pData;
    unsigned int iSize;
    unsigned int iIndex;
    ProcParallelTask* Init(void(__cdecl*)(unsigned int, void*), void*, unsigned int);
};
struct ProcTaskManager
{
    void Queue(ProcParallelTask*);
};
extern ProcTaskManager* DAT_01202df4_mgr;
struct SettingBoolStub
{
    bool* Bool();
};
extern SettingBoolStub g_011f126c;
struct ProcScrapArray
{
    ProcScrapArray();
    ~ProcScrapArray();
    unsigned int Add(ProcActorStub*& item);
    unsigned int GetSize();
    void* vtbl;
    ProcActorStub** pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
};

struct ProcListsExt : public ProcessLists
{
    void FUN_0096cda0();
};

// @fnv 0x0096cda0
void ProcListsExt::FUN_0096cda0()
{
    unsigned int head8 = m_kMobileObjectProcessList.GetHead((PROCESS_TYPE)0);
    unsigned int tailVal = m_kMobileObjectProcessList.GetTail((PROCESS_TYPE)0);
    unsigned int count = tailVal - head8;
    bool bParallel = *g_011f126c.Bool();
    if (count)
    {
        ProcScrapArray actors;
        for (unsigned int i4 = head8; i4 < tailVal; i4++)
        {
            ProcActorStub* obj = (ProcActorStub*)m_kMobileObjectProcessList.GetItem(i4);
            if (obj && obj->IsActorV())
            {
                ProcActorStub* actor6 = obj;
                if (!(actor6->GetProcessV() && !actor6->GetDeleted() && !actor6->GetDisabled() && actor6->Get3D() &&
                      FUN_00450ff0(actor6->Get3D())))
                    continue;
                if (actor6->byteBC)
                {
                    if (bParallel)
                        actors.Add(actor6);
                    else
                        actor6->UpdateV();
                }
            }
        }
        if (actors.GetSize())
        {
            ProcParallelTask kTask;
            kTask.Init(ProcTaskFunc, &actors, actors.GetSize());
            DAT_01202df4_mgr->Queue(&kTask);
        }
    }
}

struct CellProcessState
{
    BSSimpleList<MobileObject*>* currentActors;
    int generation;
    int count;
    BSSimpleList<MobileObject*>* actors;
};

struct CellProcessType
{
    int FUN_0041ca90();
};

struct CellProcessManager
{
    CellProcessState* FUN_00422700();
    void FUN_00422690(MobileObject* actor);
    void FUN_00422720();
    CellProcessType* FUN_0041cb10();
};

struct ActorProcessProxy
{
    CellProcessManager* FUN_005d43c0();
    int FUN_008d8520();
    CellProcessType* FUN_00881510();
    int FUN_00931850();
    void FUN_00881680(int flag);
};

extern float DAT_01084838;

// @fnv 0x0096d520
void __cdecl ProcessPlayerCellActors()
{
    CellProcessState* current = reinterpret_cast<ActorProcessProxy*>(pPlayer)->FUN_005d43c0()->FUN_00422700();
    if (current)
    {
        BSSimpleList<MobileObject*>* removedActors;
        BSSimpleList<MobileObject*>* nextIt;
        BSSimpleList<MobileObject*>* actorsToExamine;
        actorsToExamine = new BSSimpleList<MobileObject*>();
        nextIt = new BSSimpleList<MobileObject*>();

        BSSimpleList<MobileObject*>* firstIt = nextIt;
        removedActors = current->actors;
        while (removedActors && removedActors->GetItem())
        {
            nextIt->AddTail(removedActors->GetItem());
            removedActors = removedActors->GetNext();
        }

        while (firstIt && firstIt->GetItem())
        {
            MobileObject* actor = firstIt->GetItem();
            if (actor && actor != pPlayer)
            {
                if (reinterpret_cast<ActorProcessProxy*>(actor)->FUN_008d8520())
                {
                    CellProcessType* process = reinterpret_cast<ActorProcessProxy*>(actor)->FUN_00881510();
                    CellProcessType* replacement =
                        reinterpret_cast<ActorProcessProxy*>(actor)->FUN_005d43c0()->FUN_0041cb10();
                    if (replacement)
                        process = replacement;
                    if (!process || (process->FUN_0041ca90() != 1 && process->FUN_0041ca90() != 7))
                    {
                        actorsToExamine->AddHead(actor);
                    }
                    else
                    {
                        int result = reinterpret_cast<ActorProcessProxy*>(actor)->FUN_00931850();
                        if (result)
                        {
                            typedef void(__thiscall * VirtualAction)(MobileObject*, int);
                            typedef void(__thiscall * VirtualFloat)(MobileObject*, float);
                            reinterpret_cast<VirtualAction>((*reinterpret_cast<void***>(actor))[0x10D])(actor, 0);
                            reinterpret_cast<ActorProcessProxy*>(actor)->FUN_00881680(0);
                            reinterpret_cast<VirtualFloat>((*reinterpret_cast<void***>(actor))[0x97])(actor,
                                                                                                      DAT_01084838);
                        }
                    }
                }
            }
            firstIt = firstIt->GetNext();
        }

        firstIt = actorsToExamine;
        while (firstIt && firstIt->GetItem())
        {
            MobileObject* actorToRemove = firstIt->GetItem();
            reinterpret_cast<ActorProcessProxy*>(pPlayer)->FUN_005d43c0()->FUN_00422690(actorToRemove);
            firstIt = firstIt->GetNext();
        }

        actorsToExamine->RemoveAll();
        delete actorsToExamine;
        nextIt->RemoveAll();
        delete nextIt;
        if (current->actors->IsEmpty())
            reinterpret_cast<ActorProcessProxy*>(pPlayer)->FUN_005d43c0()->FUN_00422720();
    }
}

struct Settings970d50
{
    float FUN_00867da0();
    int FUN_00867c60();
    int FUN_00867d20();
    bool FUN_00867d60();
};
extern Settings970d50 DAT_011de7b8;
extern float DAT_011e0358;
extern int DAT_011e035c;
extern int DAT_011a39c4;
extern bool DAT_011e0360;
struct Actor970d50 : Actor
{
    void* FUN_005d43c0();
    bool FUN_00440d80();
    int FUN_007af430();
    void FUN_008a1800(int);
    int FUN_008d8520();
    void FUN_00893340(bool);
};
void __cdecl FUN_005ac190(Actor970d50*, void*);
struct ProcessQueue970d50
{
    void FUN_0096aaf0(MobileObject*, int);
};
struct Lists970d50 : ProcessLists
{
    void FUN_00970d50();
};
// @fnv 0x00970d50
void Lists970d50::FUN_00970d50()
{
    MobileObject* object = 0;
    DAT_011e0358 = DAT_011de7b8.FUN_00867da0();
    DAT_011e035c = DAT_011de7b8.FUN_00867c60();
    DAT_011a39c4 = DAT_011de7b8.FUN_00867d20();
    DAT_011e0360 = DAT_011de7b8.FUN_00867d60();
    for (unsigned int index = m_kMobileObjectProcessList.GetHead((PROCESS_TYPE)3);
         index < m_kMobileObjectProcessList.GetTail((PROCESS_TYPE)3); ++index)
    {
        Actor970d50* actor = 0;
        object = m_kMobileObjectProcessList.GetItem(index);
        if (object && object->IsActor())
            actor = (Actor970d50*)object;
        if (actor)
        {
            FUN_005ac190(actor, actor->FUN_005d43c0());
            if (actor->FUN_00440d80() || !actor->FUN_007af430() || actor->GetActorValue((ActorValue::Index)16) <= 0)
            {
                if (!actor->FUN_00440d80() && actor->FUN_007af430() && actor->GetActorValue((ActorValue::Index)16) <= 0)
                {
                    actor->FUN_008a1800(2);
                }
                if (actor->FUN_008d8520())
                    ((ProcessQueue970d50*)&m_kMobileObjectProcessList)->FUN_0096aaf0(object, 3);
            }
            else
            {
                actor->FUN_00893340(false);
            }
        }
    }
}

struct FUN_005723b0_Obj
{
    float FUN_005723b0(void* a1, unsigned char a2, int a3);
};
extern void* DAT_011dea3c;

// Compares the values returned by FUN_005723b0 for pA and pB, returning -1, 0 or 1.
// @fnv 0x00970ee0
int __cdecl FUN_00970ee0(Actor* apActorA, Actor* apActorB)
{
    float fB = ((FUN_005723b0_Obj*)apActorA)->FUN_005723b0(DAT_011dea3c, 0, 0);
    float fA = ((FUN_005723b0_Obj*)apActorB)->FUN_005723b0(DAT_011dea3c, 0, 0);
    int result;
    if (fB < fA)
        result = -1;
    else
        result = (fB > fA) ? 1 : 0;
    return result;
}

struct S_972600_Crime
{
    int FUN_00726070();
    int FUN_0084e3a0();
    int FUN_0044ddc0();
    int FUN_0045cd60();
    bool IsActorInList(int);
};
struct S_972600_Node
{
    S_972600_Crime** FUN_006815c0();
    S_972600_Node* FUN_00726070();
};
struct S_972600_Lists
{
    int unk00;
    int unk04[16];
    S_972600_Node* unk44[6];
    bool HasMatchingCrime(int a, int b, int c, int d, int e, int f);
};
// Scans the crime list at index d for an entry matching the given filters and returns true if one is found.
// @fnv 0x00972600
bool S_972600_Lists::HasMatchingCrime(int a, int b, int c, int aiListIndex, int aiUnused, int f)
{
    if (aiListIndex <= -1 || aiListIndex > 5)
        return false;
    S_972600_Node* pHead = unk44[aiListIndex];
    S_972600_Node* pNode = pHead;
    while (pNode && *pNode->FUN_006815c0())
    {
        S_972600_Crime* crime = *pNode->FUN_006815c0();
        pNode = pNode->FUN_00726070();
        if ((crime->FUN_00726070() == aiListIndex || aiListIndex == -1) && crime->FUN_0084e3a0() == b &&
            (crime->FUN_0044ddc0() == a || a == 0) && (f == -1 || f == crime->FUN_0045cd60()) &&
            (c == 0 || crime->IsActorInList(c)))
            return true;
    }
    return false;
}

struct FUN_009726e0_idx
{
    int FUN_00726070();
};

struct FUN_009726e0_elem
{
    void FUN_00905330(FUN_009726e0_idx** pp);
};

struct FUN_009726e0_cls
{
    char pad[0x44];
    FUN_009726e0_elem* m_44[6];
    void FUN_009726e0(FUN_009726e0_idx* p);
};

// @fnv 0x009726e0
void FUN_009726e0_cls::FUN_009726e0(FUN_009726e0_idx* pIndex)
{
    if (pIndex == 0 || pIndex->FUN_00726070() <= -1 || pIndex->FUN_00726070() > 5)
    {
    }
    else
    {
        FUN_009726e0_elem* e = m_44[pIndex->FUN_00726070()];
        if (e != 0)
        {
            e->FUN_00905330(&pIndex);
        }
    }
}

class ContNode;

struct FUN_009727c0_list
{
    bool _ref_008256d0();
    Crime** FUN_006815c0();
};

ContNode* __fastcall FUN_00726070(ContNode* node);

struct FUN_009727c0_shell : public ProcessLists
{
    Crime* FUN_009727c0(int listIndex, unsigned short crimeIndex);
};

// Walks the crime list at listIndex, returning the crime at crimeIndex, or warns and returns null if the index is out of range.
// @fnv 0x009727c0
Crime* FUN_009727c0_shell::FUN_009727c0(int listIndex, unsigned short crimeIndex)
{
    void FNV_Warning(const char* text, ...);
    unsigned short i = 0;
    FUN_009727c0_list* node = reinterpret_cast<FUN_009727c0_list*>(m_pkCrimeLists[listIndex]);
    while (node != 0 && !node->_ref_008256d0())
    {
        if (i == crimeIndex)
        {
            return *node->FUN_006815c0();
        }
        i++;
        node = reinterpret_cast<FUN_009727c0_list*>(FUN_00726070(reinterpret_cast<ContNode*>(node)));
    }
    FNV_Warning("AI: When trying to get a crime by its index, the index was larger than the size of the crime list.");
    return 0;
}

struct List_973590
{
    bool FUN_005f65d0(Actor*&);
    void FUN_005ae3d0(Actor*&);
};
struct Node_973590
{
    bool FUN_008256d0();
    Actor** FUN_006815c0();
    Node_973590* FUN_00726070();
};
struct Extra_973590
{
    int unk00;
    int unk04;
    int unk08;
    Node_973590* followers;
};
struct ExtraList_973590
{
    Extra_973590* FUN_00422700();
};
struct Actor_973590
{
    ExtraList_973590* FUN_005d43c0();
    TESPackage* FUN_009344a0();
    Actor* FUN_00881650();
};
struct Array_973590
{
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
};
struct FUN_00973590_shell
{
    int unk00;
    Array_973590 processes;
    void FUN_00973590(Actor* target, List_973590* output);
};
// Recursively collects followers and actors whose package targets the given actor into output, skipping already-listed ones.
// @fnv 0x00973590
void FUN_00973590_shell::FUN_00973590(Actor* target, List_973590* output)
{
    Extra_973590* extra = ((Actor_973590*)target)->FUN_005d43c0()->FUN_00422700();
    if (extra)
    {
        Node_973590* node = extra->followers;
        while (node && !node->FUN_008256d0())
        {
            Actor* follower = *node->FUN_006815c0();
            if (!output->FUN_005f65d0(follower))
            {
                output->FUN_005ae3d0(follower);
                FUN_00973590(follower, output);
            }
            node = node->FUN_00726070();
        }
    }
    MobileObject* mobile = 0;
    for (unsigned int index = 0; index < processes.FUN_005be5c0(0); ++index)
    {
        mobile = processes.FUN_00968670(index);
        Actor* actor = 0;
        if (mobile && mobile->IsActor())
        {
            actor = (Actor*)mobile;
            if (((Actor_973590*)actor)->FUN_009344a0() &&
                (((Actor_973590*)actor)->FUN_009344a0()->GetPackType() == 2 ||
                 ((Actor_973590*)actor)->FUN_009344a0()->GetPackType() == 7) &&
                ((Actor_973590*)actor)->FUN_00881650() == target && !output->FUN_005f65d0(actor))
            {
                output->FUN_005ae3d0(actor);
                FUN_00973590(actor, output);
            }
        }
    }
}

struct S973_Process
{
    void* IsReady973();
};

struct S973_Base;

struct S973_Ref;

struct S973_Faction
{
    bool Contains973(S973_Ref* apObj);
};

struct S973_Actor
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
    virtual bool IsValid973();
    S973_Base* GetBase973();
    S973_Process* GetProc973();
};

struct S973_Base
{
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
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    S973_Faction factions;
};

struct S973_Ref
{
    bool CanUse973(S973_Actor* apActor, bool abFlag);
    S973_Ref* GetObj973();
};

struct S973_Node
{
    S973_Actor** GetItem973();
    S973_Node* GetNext973();
};

struct S973_Array
{
    unsigned int GetCount973(int aiLevel);
    S973_Actor* GetAt973(unsigned int auiIndex);
};

struct FUN_00973ab0_shell
{
    int unk00;
    S973_Array kArray;
    S973_Actor* FindUsableActorInArray(S973_Ref* apRef);
};

// Scans kArray for a valid actor that apRef can use and whose base factions contain apRef's object, returning the first match or null.
// @fnv 0x00973ab0
S973_Actor* FUN_00973ab0_shell::FindUsableActorInArray(S973_Ref* apRef)
{
    S973_Actor* pResult5 = 0;
    S973_Actor* pActor2 = 0;
    S973_Actor* pItem_ = 0;
    for (unsigned int i5 = 0; pResult5 == 0 && i5 < kArray.GetCount973(0); i5++)
    {
        pItem_ = kArray.GetAt973(i5);
        pActor2 = 0;
        if (pItem_ && pItem_->IsValid973())
            pActor2 = pItem_;
        S973_Node* pNode = 0;
        while (pActor2)
        {
            if (pActor2 && apRef->CanUse973(pActor2, true) &&
                pActor2->GetBase973()->factions.Contains973(apRef->GetObj973()))
                pResult5 = pActor2;
            if (pNode && *pNode->GetItem973())
            {
                pActor2 = 0;
                if ((*pNode->GetItem973())->IsValid973())
                    pActor2 = *pNode->GetItem973();
                pNode = pNode->GetNext973();
                while (pNode && pActor2 && (!pActor2->GetProc973() || pActor2->GetProc973()->IsReady973()))
                {
                    if (pNode && *pNode->GetItem973() && (*pNode->GetItem973())->IsValid973())
                        pActor2 = *pNode->GetItem973();
                    else
                        pActor2 = 0;
                    if (pNode)
                        pNode = pNode->GetNext973();
                }
            }
            else
            {
                pActor2 = 0;
            }
        }
    }
    return pResult5;
}

struct FUN_00973cb0_cls : public ProcessLists
{
    void FUN_00973cb0(Actor* target);
};
// @fnv 0x00973cb0
void FUN_00973cb0_cls::FUN_00973cb0(Actor* target)
{
    MobileObject* object = 0;
    for (unsigned int i = 0; i < m_kMobileObjectProcessList.GetTail((PROCESS_TYPE)0); ++i)
    {
        object = m_kMobileObjectProcessList.GetItem(i);
        Actor* actor = 0;
        if (object)
        {
            if (object->IsActor())
                actor = (Actor*)object;
        }
        if (actor)
        {
            actor->GetCurrentAIProcess()->SetActorDetectionLevel(target, (BaseProcess::DetectionListType)3);
        }
    }
}

// FUN_00973fd0 candidate (b6121)
class FnvArgObj
{
  public:
    void** m_ppVirtualMethodTable;
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual void Unk_0A(void);
    virtual void Unk_0B(void);
    virtual void Unk_0C(void);
    virtual void Unk_0D(void);
    virtual void Unk_0E(void);
    virtual void Unk_0F(void);
    virtual void Unk_10(void);
    virtual void Unk_11(void);
    virtual void Unk_12(void);
    virtual void Unk_13(void);
    virtual void Unk_14(void);
    virtual void Unk_15(void);
    virtual void Unk_16(void);
    virtual void Unk_17(void);
    virtual void Unk_18(void);
    virtual void Unk_19(void);
    virtual void Unk_1A(void);
    virtual void Unk_1B(void);
    virtual void Unk_1C(void);
    virtual void Unk_1D(void);
    virtual void Unk_1E(void);
    virtual void Unk_1F(void);
    virtual void Unk_20(void);
    virtual void Unk_21(void);
    virtual void Unk_22(void);
    virtual void Unk_23(void);
    virtual void Unk_24(void);
    virtual void Unk_25(void);
    virtual void Unk_26(void);
    virtual int Unk_9C(void);
};

class FnvTemp
{
  public:
    FnvTemp(FnvArgObj* arg);
    ~FnvTemp();
    int unk00;
};

class FnvSubObj
{
  public:
    int unk00;
    int unk04;
    void Process(FnvTemp* t);
};

class FUN_00973fd0_cls
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
    FnvSubObj m_58;
    FnvSubObj m_60;

    void FUN_00973fd0(FnvArgObj* arg);
};

// If arg is non-null, calls Unk_9C and dispatches to m_60.Process or m_58.Process with a temporary FnvTemp built from arg, depending on the returned case.
// @fnv 0x00973fd0
void FUN_00973fd0_cls::FUN_00973fd0(FnvArgObj* arg)
{
    if (arg != 0)
    {
        switch (arg->Unk_9C())
        {
        case 4:
        case 5:
        case 6: {
            FnvTemp a(arg);
            m_60.Process(&a);
            break;
        }
        default: {
            FnvTemp b(arg);
            m_58.Process(&b);
            break;
        }
        }
    }
}

struct ParticleObj
{
    void SetAppCulled(bool abCulled);
};
struct ParticleSource;

class BSTempEffectParticle : public BSTempEffect
{
  public:
    ParticleObj* GetParticleObject();
    ParticleSource* GetSource();
    void SetParentCell(TESObjectCELL* apCell);
};

struct TempEffectListOwner : public ProcessLists
{
    void RemoveParticleEffectsBySource(ParticleSource* apSource);
};

// @fnv 0x00974290
void TempEffectListOwner::RemoveParticleEffectsBySource(ParticleSource* apSource)
{
    if (!apSource)
        return;
    if (!m_kTemporaryEffectList.IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* pPrev;
        BSSimpleList<NiPointer<BSTempEffect> >* pIter6 = &m_kTemporaryEffectList;
        pPrev = 0;
        while (pIter6 && !pIter6->IsEmpty())
        {
            BSTempEffect* pEffect = pIter6->GetItem();
            if (pEffect->GetType() == BSTempEffect::_Type::PARTICLE)
            {
                BSTempEffectParticle* pParticle = dynamic_cast<BSTempEffectParticle*>(pEffect);
                if (pParticle && pParticle->GetSource() == apSource)
                {
                    ParticleObj* pObject4 = pParticle->GetParticleObject();
                    if (pObject4)
                        pObject4->SetAppCulled(true);
                    pParticle->SetParentCell(0);
                    GarbageCollector::Add(pEffect);
                    if (pPrev)
                    {
                        pPrev->Remove(pEffect);
                        pIter6 = pPrev->GetNext();
                    }
                    else
                    {
                        pIter6->RemoveHead();
                    }
                }
                else
                {
                    pPrev = pIter6;
                    pIter6 = pIter6->GetNext();
                }
            }
            else
            {
                pPrev = pIter6;
                pIter6 = pIter6->GetNext();
            }
        }
    }
}

struct TESObjectREFR_9749
{
};
struct ObjV
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
    virtual void Fn();
    int FUN_00441110();
    void SetByteAt24(bool);
};
struct Base9749
{
    void* FUN_006815c0();
};
struct BNode9749
{
    bool FUN_004a4460();
    BNode9749* FUN_00726070();
    void* FUN_006815c0();
};
struct Mid9749
{
    ObjV* FUN_00559450();
};
extern int DAT_011dc6b4;
bool __cdecl FUN_0043b300(const void*, ObjV*);
struct FUN_009749b0_shell
{
    char pad[0x60];
    BNode9749 list;
    void FUN_009749b0(int id);
};
// @fnv 0x009749b0
void FUN_009749b0_shell::FUN_009749b0(int id)
{
    if (!list.FUN_004a4460())
    {
        BNode9749* n = &list;
        while (n)
        {
            ObjV* o = ((Mid9749*)n->FUN_006815c0())->FUN_00559450();
            if (o && FUN_0043b300(&DAT_011dc6b4, o))
            {
                ObjV* r = o;
                if (r->FUN_00441110() == id)
                {
                    r->Fn();
                    r->SetByteAt24(true);
                }
            }
            n = n->FUN_00726070();
        }
    }
}

struct ShaderHitTargetForm
{
    virtual void v00();
    virtual int GetKind();
};
struct ShaderHitTarget
{
    ShaderHitTargetForm* GetForm();
};
class MagicShaderHitEffect : public BSTempEffect
{
  public:
    virtual void v31();
    ShaderHitTarget* GetHitTarget();
    float GetTimeLeft();
    void Finish();
};
bool __cdecl IsValidShaderHitTarget(int aTarget);

struct ProcessListsEx : public ProcessLists
{
    bool FUN_00974e90(int aiKind, int aTarget);
};

// @fnv 0x00974e90
bool ProcessListsEx::FUN_00974e90(int aiKind, int aTarget)
{
    if (!m_kTemporaryEffectList2.IsEmpty())
    {
        MagicShaderHitEffect* pBest2 = 0;
        float fBest2 = 3.402823466e+38F;
        BSSimpleList<NiPointer<BSTempEffect> >* pIter6 = &m_kTemporaryEffectList2;
        while (pIter6)
        {
            BSTempEffect* pEffect = pIter6->GetItem();
            if (pEffect && pEffect->GetType() == BSTempEffect::_Type::MAGIC_SHADER_HIT)
            {
                MagicShaderHitEffect* pShader = (MagicShaderHitEffect*)pEffect;
                ShaderHitTarget* pTarget = pShader->GetHitTarget();
                if (pTarget && pShader->GetTimeLeft() < fBest2 && pTarget->GetForm() &&
                    pTarget->GetForm()->GetKind() == aiKind && IsValidShaderHitTarget(aTarget))
                {
                    pBest2 = pShader;
                    fBest2 = pShader->GetTimeLeft();
                }
            }
            pIter6 = pIter6->GetNext();
        }
        if (pBest2)
        {
            pBest2->v31();
            pBest2->Finish();
            return true;
        }
    }
    return false;
}

struct TESSaveLoadGame
{
    unsigned short* GetSaveCountPtr();
    void SaveData(void* data, int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct PLTempEffectSaver : public ProcessLists
{
    void SaveTempEffects();
};

// @fnv 0x009756c0
void PLTempEffectSaver::SaveTempEffects()
{
    unsigned short count = 0;
    unsigned short* countPtr = g_TESSaveLoadGame->GetSaveCountPtr();
    g_TESSaveLoadGame->SaveData(&count, 2);

    BSSimpleList<NiPointer<BSTempEffect> >* _iter;
    _iter = &m_kTemporaryEffectList;
    while (_iter && !_iter->IsEmpty())
    {
        BSTempEffect* effect8 = _iter->GetItem();
        if (effect8->IsSaveable())
        {
            char type = effect8->GetType();
            g_TESSaveLoadGame->SaveData(&type, 1);
            effect8->SaveGameTES();
            count++;
        }
        _iter = _iter->GetNext();
    }
    _iter = &m_kTemporaryEffectList2;
    while (_iter && !_iter->IsEmpty())
    {
        BSTempEffect* effect4 = _iter->GetItem();
        if (effect4->IsSaveable())
        {
            char type2 = effect4->GetType();
            g_TESSaveLoadGame->SaveData(&type2, 1);
            effect4->SaveGameTES();
            count++;
        }
        _iter = _iter->GetNext();
    }
    *countPtr = count;
}

namespace fnv_00976680 {
struct Obj;
struct Obj
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual bool v100();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual Obj* v128();
    virtual void v12c(int a);
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual int v198();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual Obj* v20c();
    virtual void d132();
    virtual void v214();
    virtual void d134();
    virtual void d135();
    virtual bool v220();
    virtual bool v224();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void v234();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual Obj* v27c();
    virtual void d160();
    virtual void d161();
    virtual void v288();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void v2c4(Obj* a, int b);
    virtual Obj* v2c8();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void v310(int a);
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void d225();
    virtual void d226();
    virtual void d227();
    virtual void d228();
    virtual void d229();
    virtual void d230();
    virtual void d231();
    virtual void d232();
    virtual void d233();
    virtual void d234();
    virtual void d235();
    virtual void d236();
    virtual void d237();
    virtual void d238();
    virtual void d239();
    virtual void d240();
    virtual void d241();
    virtual void d242();
    virtual void d243();
    virtual void d244();
    virtual void d245();
    virtual void d246();
    virtual void d247();
    virtual void d248();
    virtual void d249();
    virtual void d250();
    virtual void d251();
    virtual void d252();
    virtual void d253();
    virtual void d254();
    virtual void d255();
    virtual void d256();
    virtual void d257();
    virtual void d258();
    virtual void d259();
    virtual void d260();
    virtual void d261();
    virtual void d262();
    virtual void d263();
    virtual void d264();
    virtual void d265();
    virtual Obj* v428();
    virtual void d267();
    virtual void d268();
    virtual void d269();
    virtual void d270();
    virtual void d271();
    virtual void d272();
    virtual void d273();
    virtual void d274();
    virtual void d275();
    virtual void d276();
    virtual void d277();
    virtual void d278();
    virtual void d279();
    virtual void d280();
    virtual void d281();
    virtual void d282();
    virtual void d283();
    virtual void d284();
    virtual void d285();
    virtual void d286();
    virtual void v47c(Obj* a);
    virtual void d288();
    virtual void d289();
    virtual void d290();
    virtual void d291();
    virtual void d292();
    virtual void d293();
    virtual void d294();
    virtual void d295();
    virtual void v4a0();
    virtual void d297();
    virtual void d298();
    virtual void d299();
    virtual void d300();
    virtual void d301();
    virtual void d302();
    virtual void d303();
    virtual void d304();
    virtual void d305();
    virtual void d306();
    virtual void d307();
    virtual void d308();
    virtual void d309();
    virtual void d310();
    virtual void d311();
    virtual void d312();
    virtual void d313();
    virtual void d314();
    virtual void d315();
    virtual void d316();
    virtual void d317();
    virtual void d318();
    virtual void d319();
    virtual void d320();
    virtual void d321();
    virtual void d322();
    virtual void d323();
    virtual void d324();
    virtual void d325();
    virtual void d326();
    virtual void d327();
    virtual void d328();
    virtual void d329();
    virtual void d330();
    virtual void d331();
    virtual void d332();
    virtual void d333();
    virtual void d334();
    virtual void d335();
    virtual void d336();
    virtual void d337();
    virtual void d338();
    virtual void d339();
    virtual void d340();
    virtual void d341();
    virtual void d342();
    virtual void d343();
    virtual void d344();
    virtual void d345();
    virtual void d346();
    virtual void d347();
    virtual void d348();
    virtual void d349();
    virtual void d350();
    virtual void d351();
    virtual void d352();
    virtual void d353();
    virtual void d354();
    virtual void d355();
    virtual void d356();
    virtual void d357();
    virtual void d358();
    virtual void d359();
    virtual void d360();
    virtual void d361();
    virtual void d362();
    virtual void d363();
    virtual void d364();
    virtual void d365();
    virtual void d366();
    virtual void d367();
    virtual void d368();
    virtual void d369();
    virtual void d370();
    virtual void d371();
    virtual void d372();
    virtual void d373();
    virtual void d374();
    virtual void d375();
    virtual void d376();
    virtual void d377();
    virtual void d378();
    virtual void d379();
    virtual void d380();
    virtual void d381();
    virtual void d382();
    virtual void d383();
    virtual void d384();
    virtual void d385();
    virtual void d386();
    virtual void d387();
    virtual void d388();
    virtual void d389();
    virtual void d390();
    virtual void d391();
    virtual void d392();
    virtual void d393();
    virtual void d394();
    virtual void d395();
    virtual void d396();
    virtual void d397();
    virtual void d398();
    virtual void d399();
    virtual void d400();
    virtual void d401();
    virtual void d402();
    virtual void d403();
    virtual void d404();
    virtual void d405();
    virtual void d406();
    virtual void d407();
    virtual void d408();
    virtual void v664(Obj* a);
    virtual void d410();
    virtual void d411();
    virtual void d412();
    virtual void d413();
    virtual void d414();
    virtual void d415();
    virtual void d416();
    virtual void d417();
    virtual void d418();
    virtual void d419();
    virtual void d420();
    virtual void d421();
    virtual void d422();
    virtual void d423();
    virtual void d424();
    virtual void d425();
    virtual void d426();
    virtual void d427();
    virtual void d428();
    virtual void d429();
    virtual void d430();
    virtual void d431();
    virtual void d432();
    virtual void d433();
    virtual void d434();
    virtual void d435();
    virtual void d436();
    virtual void d437();
    virtual void d438();
    virtual void d439();
    virtual void d440();
    virtual void d441();
    virtual void d442();
    virtual void d443();
    virtual void d444();
    virtual void d445();
    virtual void d446();
    virtual void d447();
    virtual void d448();
    virtual void d449();
    virtual void d450();
    virtual void d451();
    virtual void d452();
    virtual void d453();
    virtual void d454();
    virtual void d455();
    virtual void d456();
    virtual void d457();
    virtual void d458();
    virtual void d459();
    virtual void d460();
    virtual void d461();
    virtual void d462();
    virtual void d463();
    virtual void d464();
    virtual void d465();
    virtual void d466();
    virtual void d467();
    virtual void d468();
    virtual void d469();
    virtual void d470();
    virtual void d471();
    virtual void d472();
    virtual void d473();
    virtual void d474();
    virtual void d475();
    virtual void d476();
    virtual void d477();
    virtual void d478();
    virtual void d479();
    virtual void d480();
    virtual void d481();
    virtual void d482();
    virtual void d483();
    virtual void d484();
    virtual void d485();
    virtual void d486();
    virtual void d487();
    virtual void d488();
    virtual void d489();
    virtual void d490();
    virtual void d491();
    virtual void v7b0(Obj* a);
    int u04;
    int u08;
    Obj* f0c;
    int u10;
    Obj* f14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    Obj* fc0;
    Obj* FUN_005d43c0();
    Obj* FUN_00422700();
    void FUN_00905330(void* a);
    Obj* FUN_008d8520();
    Obj* FUN_004fd380();
    void FUN_0057bd60(int a);
    bool FUN_00576d30();
    Obj* FUN_00881510();
    bool FUN_00674d40();
    int FUN_0041ca90();
    Obj* FUN_00671d10();
    Obj* FUN_00680020();
    void FUN_00672fc0(int a);
    Obj* FUN_00676140(Obj* a);
    void FUN_00671d30(int a);
    Obj* FUN_00881650();
    bool FUN_009336c0();
    Obj* FUN_009344a0();
    void FUN_00881680(int a);
    void FUN_008c4f10(int a);
    Obj* FUN_00410220(unsigned char a);
    bool FUN_008a6650(int a);
    Obj* FUN_005e3fc0();
    void FUN_00994ef0(int a);
    void FUN_008a6730(Obj* a);
    bool FUN_00493bb0();
    void FUN_0097f9c0(Obj* a);
    Obj* FUN_00422690(Obj* a);
    void FUN_00881620(int a);
    void FUN_009c4c80(Obj* a);
    bool FUN_00440da0();
    void FUN_009b28a0(Obj* a);
    void ProcessCombatTarget(Obj* a);
};
struct ArrObj
{
    int data[16];
    unsigned int FUN_005be5c0(unsigned int a);
    Obj* FUN_00968670(unsigned int a);
};
struct ListNode
{
    bool FUN_008256d0();
    Obj** FUN_006815c0();
    ListNode* FUN_00726070();
};
extern Obj* DAT_011f1958;
extern Obj* DAT_011dea3c;
struct Host
{
    int u00;
    ArrObj arr;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
    int p6c;
    int p70;
    int p74;
    ListNode node78;
    void RemoveActor(Obj* a);
    void FUN_00976680(Obj* param);
};

// Clears references to param across the array and node list, resetting owners, packages and base objects that point at it, then calls RemoveActor.
// @fnv 0x00976680
void Host::FUN_00976680(Obj* apObject)
{
    Obj* tmpParam3;
    Obj* copy2b6;
    Obj* copy1b;
    Obj* unk428b;
    Obj* pkgSel2;
    Obj* pkgTmp2;
    int n198b13;
    Obj* objD7;
    Obj* objC2;
    Obj* extra2;
    Obj* base16;
    Obj* item5;
    int skipCtr22;
    Obj* copy3;
    Obj* copy25;
    Obj* unk428;
    Obj* pkgSel4;
    Obj* pkgTmp8;
    int n198;
    Obj* objD4;
    Obj* objC8;
    Obj* extra;
    Obj* baseB;
    Obj* objB4;
    ListNode* node7;
    Obj* objA6;
    int i8;

    DAT_011f1958->ProcessCombatTarget(apObject);
    if (apObject->v100())
    {
        if (DAT_011dea3c->FUN_005d43c0()->FUN_00422700() != 0)
        {
            if (DAT_011dea3c->FUN_005d43c0()->FUN_00422700()->f0c != 0)
            {
                tmpParam3 = apObject;
                DAT_011dea3c->FUN_005d43c0()->FUN_00422700()->f0c->FUN_00905330(&tmpParam3);
            }
        }
        if (DAT_011dea3c->FUN_008d8520() != 0)
        {
            DAT_011dea3c->FUN_008d8520()->v2c4(apObject, 3);
        }
        if (DAT_011dea3c->FUN_004fd380() == apObject)
        {
            DAT_011dea3c->FUN_0057bd60(0);
        }
    }

    node7 = 0;
    objA6 = 0;
    for (i8 = 0; (unsigned int)i8 < arr.FUN_005be5c0(3); i8++)
    {
        objA6 = arr.FUN_00968670((unsigned int)i8);
        if (objA6 != 0 && !objA6->FUN_00576d30())
        {
            objB4 = 0;
            if (objA6->v100())
                objB4 = objA6;
            if (objB4 != 0)
            {
                baseB = objB4->FUN_008d8520();
                if (objB4->FUN_004fd380() == apObject)
                {
                    objB4->FUN_0057bd60(0);
                    if (baseB != 0)
                    {
                        baseB->v310(0);
                        baseB->v4a0();
                    }
                }
                if (baseB != 0)
                {
                    objD4 = objB4->FUN_008d8520()->v27c();
                    objC8 = objB4->FUN_00881510();
                    if (objD4 != 0)
                    {
                        if (objD4->FUN_00674d40())
                        {
                            if (objD4->FUN_0041ca90() != 0x12)
                            {
                                if (objD4->FUN_00671d10() != 0)
                                {
                                    if (objD4->FUN_00671d10()->FUN_00680020() == apObject)
                                        objD4->FUN_00672fc0(0);
                                }
                                if (objD4->FUN_00676140(objB4) == apObject)
                                    objD4->FUN_00671d30(0);
                            }
                        }
                    }
                    if (objC8 != 0)
                    {
                        if (objC8->FUN_00674d40())
                        {
                            if (objC8->FUN_0041ca90() != 0x12)
                            {
                                if (objC8->FUN_00671d10() != 0)
                                {
                                    if (objC8->FUN_00671d10()->FUN_00680020() == apObject)
                                        objC8->FUN_00672fc0(0);
                                }
                                if (objC8->FUN_00676140(objB4) == apObject)
                                    objC8->FUN_00671d30(0);
                            }
                        }
                    }
                    if ((unsigned int)i8 < arr.FUN_005be5c0(1))
                    {
                        baseB->v2c4(apObject, 3);
                        if (objB4->FUN_00881650() == apObject ||
                            (baseB->v20c() != 0 && baseB->v20c()->FUN_00671d10() != 0 &&
                             baseB->v20c()->FUN_00671d10()->FUN_00680020() == apObject))
                        {
                            if (objB4->FUN_009336c0())
                            {
                                objB4->v288();
                            }
                            else if (objB4->FUN_009344a0() != 0 && objB4->FUN_009344a0()->FUN_00674d40())
                            {
                                objB4->FUN_00881680(0);
                            }
                            else
                            {
                                baseB->v234();
                                baseB->v214();
                            }
                        }
                    after1:
                        n198 = apObject->v198();
                        objB4->FUN_008c4f10(n198);
                        if ((unsigned int)i8 < arr.FUN_005be5c0(0))
                        {
                            baseB->v664(apObject);
                        }
                    }
                    baseB->v47c(apObject);
                    baseB->v7b0(apObject);
                    extra = objB4->FUN_005d43c0()->FUN_00410220(0x19);
                    if (extra != 0)
                    {
                        if (extra->f14 == apObject)
                            extra->f14 = 0;
                    }
                    if (objB4->fc0 == apObject)
                        objB4->fc0 = 0;
                    if (objB4->FUN_008a6650(0))
                    {
                        pkgTmp8 = objB4->FUN_009344a0();
                        pkgSel4 = 0;
                        if (pkgTmp8 != 0)
                        {
                            if (pkgTmp8->FUN_0041ca90() == 0x16)
                                pkgSel4 = pkgTmp8;
                        }
                        if (pkgSel4 != 0)
                        {
                            if (pkgSel4->FUN_005e3fc0() == apObject)
                                pkgSel4->FUN_00994ef0(0);
                        }
                        objB4->FUN_008a6730(apObject);
                    }
                    if (objB4->FUN_00493bb0())
                    {
                        unk428 = objB4->v428();
                        if (unk428 != 0)
                            unk428->FUN_0097f9c0(apObject);
                    }
                    objB4->FUN_005d43c0()->FUN_00422690(apObject);
                    if (baseB->v128() == apObject)
                        baseB->v12c(0);
                    if (objB4->v2c8() == apObject)
                        objB4->FUN_00881620(0);
                }
            }
            else
            {
                if (objA6->v224())
                {
                    copy25 = objA6;
                    copy25->FUN_009c4c80(apObject);
                    if (copy25->FUN_00440da0())
                    {
                        if (arr.FUN_00968670((unsigned int)i8) != copy25)
                            i8 = i8 - 1;
                    }
                }
                else if (objA6->v220())
                {
                    copy3 = objA6;
                    copy3->FUN_009b28a0(apObject);
                }
            }
        }
        else
        {
            skipCtr22 = 0;
            skipCtr22 = skipCtr22 + 1;
        }
    }

    node7 = &node78;
    while (node7 != 0 && !node7->FUN_008256d0())
    {
        item5 = 0;
        if ((*node7->FUN_006815c0())->v100())
            item5 = *node7->FUN_006815c0();
        if (item5 != 0 && !item5->FUN_00576d30())
        {
            base16 = item5->FUN_008d8520();
            if (item5->FUN_004fd380() == apObject)
            {
                item5->FUN_0057bd60(0);
                if (base16 != 0)
                {
                    base16->v310(0);
                    base16->v4a0();
                }
            }
            if (base16 != 0)
            {
                objD7 = item5->FUN_008d8520()->v27c();
                objC2 = item5->FUN_00881510();
                if (objD7 != 0)
                {
                    if (objD7->FUN_00674d40())
                    {
                        if (objD7->FUN_0041ca90() != 0x12)
                        {
                            if (objD7->FUN_00671d10() != 0)
                            {
                                if (objD7->FUN_00671d10()->FUN_00680020() == apObject)
                                    objD7->FUN_00672fc0(0);
                            }
                            if (objD7->FUN_00676140(item5) == apObject)
                                objD7->FUN_00671d30(0);
                        }
                    }
                }
                if (objC2 != 0)
                {
                    if (objC2->FUN_00674d40())
                    {
                        if (objC2->FUN_0041ca90() != 0x12)
                        {
                            if (objC2->FUN_00671d10() != 0)
                            {
                                if (objC2->FUN_00671d10()->FUN_00680020() == apObject)
                                    objC2->FUN_00672fc0(0);
                            }
                            if (objC2->FUN_00676140(item5) == apObject)
                                objC2->FUN_00671d30(0);
                        }
                    }
                }
                if ((unsigned int)i8 < 2)
                {
                    base16->v2c4(apObject, 3);
                    if (item5->FUN_00881650() == apObject ||
                        (base16->v20c() != 0 && base16->v20c()->FUN_00671d10() != 0 &&
                         base16->v20c()->FUN_00671d10()->FUN_00680020() == apObject))
                    {
                        if (item5->FUN_009336c0())
                        {
                            item5->v288();
                        }
                        else if (item5->FUN_009344a0()->FUN_00674d40())
                        {
                            item5->FUN_00881680(0);
                        }
                        else
                        {
                            base16->v234();
                            base16->v214();
                        }
                    }
                after2:
                    n198b13 = apObject->v198();
                    item5->FUN_008c4f10(n198b13);
                    if ((unsigned int)i8 < 1)
                    {
                        base16->v664(apObject);
                    }
                }
                base16->v47c(apObject);
                extra2 = item5->FUN_005d43c0()->FUN_00410220(0x19);
                if (extra2 != 0)
                {
                    if (extra2->f14 == apObject)
                        extra2->f14 = 0;
                }
                if (item5->fc0 == apObject)
                    item5->fc0 = 0;
                if (item5->FUN_008a6650(0))
                {
                    pkgTmp2 = item5->FUN_009344a0();
                    pkgSel2 = 0;
                    if (pkgTmp2 != 0)
                    {
                        if (pkgTmp2->FUN_0041ca90() == 0x16)
                            pkgSel2 = pkgTmp2;
                    }
                    if (pkgSel2 != 0)
                    {
                        if (pkgSel2->FUN_005e3fc0() == apObject)
                            pkgSel2->FUN_00994ef0(0);
                    }
                    item5->FUN_008a6730(apObject);
                }
                if (item5->FUN_00493bb0())
                {
                    unk428b = item5->v428();
                    if (unk428b != 0)
                        unk428b->FUN_0097f9c0(apObject);
                }
                item5->FUN_005d43c0()->FUN_00422690(apObject);
                if (base16->v128() == apObject)
                    base16->v12c(0);
                if (item5->v2c8() == apObject)
                    item5->FUN_00881620(0);
            }
        }
        else
        {
            if (objA6->v224())
            {
                copy1b = objA6;
                copy1b->FUN_009c4c80(apObject);
            }
            else if (objA6->v220())
            {
                copy2b6 = objA6;
                copy2b6->FUN_009b28a0(apObject);
            }
        }
        node7 = node7->FUN_00726070();
    }
    this->RemoveActor(apObject);
}
}  // namespace fnv_00976680

struct ProcStub
{
    virtual void P_v000();
    virtual void P_v001();
    virtual void P_v002();
    virtual void P_v003();
    virtual void P_v004();
    virtual void P_v005();
    virtual void P_v006();
    virtual void P_v007();
    virtual void P_v008();
    virtual void P_v009();
    virtual void P_v010();
    virtual void P_v011();
    virtual void P_v012();
    virtual void P_v013();
    virtual void P_v014();
    virtual void P_v015();
    virtual void P_v016();
    virtual void P_v017();
    virtual void P_v018();
    virtual void P_v019();
    virtual void P_v020();
    virtual void P_v021();
    virtual void P_v022();
    virtual void P_v023();
    virtual void P_v024();
    virtual void P_v025();
    virtual void P_v026();
    virtual void P_v027();
    virtual void P_v028();
    virtual void P_v029();
    virtual void P_v030();
    virtual void P_v031();
    virtual void P_v032();
    virtual void P_v033();
    virtual void P_v034();
    virtual void P_v035();
    virtual void P_v036();
    virtual void P_v037();
    virtual void P_v038();
    virtual void P_v039();
    virtual void P_v040();
    virtual void P_v041();
    virtual void P_v042();
    virtual void P_v043();
    virtual void P_v044();
    virtual void P_v045();
    virtual void P_v046();
    virtual void P_v047();
    virtual void P_v048();
    virtual void P_v049();
    virtual void P_v050();
    virtual void P_v051();
    virtual void P_v052();
    virtual void P_v053();
    virtual void P_v054();
    virtual void P_v055();
    virtual void P_v056();
    virtual void P_v057();
    virtual void P_v058();
    virtual void P_v059();
    virtual void P_v060();
    virtual void P_v061();
    virtual void P_v062();
    virtual void P_v063();
    virtual void P_v064();
    virtual void Upd104();
    virtual void P_v066();
    virtual void P_v067();
    virtual void P_v068();
    virtual void P_v069();
    virtual void P_v070();
    virtual void P_v071();
    virtual void P_v072();
    virtual void P_v073();
    virtual void P_v074();
    virtual void P_v075();
    virtual void P_v076();
    virtual void P_v077();
    virtual void P_v078();
    virtual void P_v079();
    virtual void P_v080();
    virtual void P_v081();
    virtual void P_v082();
    virtual void P_v083();
    virtual void P_v084();
    virtual void P_v085();
    virtual void P_v086();
    virtual void P_v087();
    virtual void P_v088();
    virtual void P_v089();
    virtual void P_v090();
    virtual void P_v091();
    virtual void Add170(void* a);
    virtual void P_v093();
    virtual void P_v094();
    virtual void P_v095();
    virtual void P_v096();
    virtual void P_v097();
    virtual void P_v098();
    virtual void P_v099();
    virtual void P_v100();
    virtual void P_v101();
    virtual void P_v102();
    virtual void P_v103();
    virtual void P_v104();
    virtual void P_v105();
    virtual void P_v106();
    virtual void P_v107();
    virtual void P_v108();
    virtual void P_v109();
    virtual void P_v110();
    virtual void P_v111();
    virtual void P_v112();
    virtual void P_v113();
    virtual void P_v114();
    virtual void P_v115();
    virtual void P_v116();
    virtual void P_v117();
    virtual void Add1d8(void* a);
    virtual void P_v119();
    virtual void P_v120();
    virtual void P_v121();
    virtual void P_v122();
    virtual void P_v123();
    virtual void P_v124();
    virtual void P_v125();
    virtual void P_v126();
    virtual void P_v127();
    virtual void P_v128();
    virtual void P_v129();
    virtual void P_v130();
    virtual void P_v131();
    virtual void P_v132();
    virtual void P_v133();
    virtual void P_v134();
    virtual void P_v135();
    virtual void P_v136();
    virtual void P_v137();
    virtual void P_v138();
    virtual void P_v139();
    virtual void P_v140();
    virtual void P_v141();
    virtual void P_v142();
    virtual void P_v143();
    virtual void P_v144();
    virtual void P_v145();
    virtual void P_v146();
    virtual void P_v147();
    virtual void P_v148();
    virtual void P_v149();
    virtual void P_v150();
    virtual void P_v151();
    virtual void P_v152();
    virtual void P_v153();
    virtual void P_v154();
    virtual void P_v155();
    virtual void P_v156();
    virtual void P_v157();
    virtual void P_v158();
    virtual void P_v159();
    virtual void P_v160();
    virtual void P_v161();
    virtual void P_v162();
    virtual void P_v163();
    virtual void P_v164();
    virtual void P_v165();
    virtual void P_v166();
    virtual void P_v167();
    virtual void P_v168();
    virtual void P_v169();
    virtual void P_v170();
    virtual void P_v171();
    virtual void P_v172();
    virtual void P_v173();
    virtual void P_v174();
    virtual void P_v175();
    virtual void P_v176();
    virtual void P_v177();
    virtual void P_v178();
    virtual void P_v179();
    virtual void P_v180();
    virtual void P_v181();
    virtual void P_v182();
    virtual void P_v183();
    virtual void P_v184();
    virtual void P_v185();
    virtual void P_v186();
    virtual void P_v187();
    virtual void P_v188();
    virtual void P_v189();
    virtual void P_v190();
    virtual void P_v191();
    virtual void P_v192();
    virtual void P_v193();
    virtual void P_v194();
    virtual void P_v195();
    virtual void P_v196();
    virtual void P_v197();
    virtual void P_v198();
    virtual void P_v199();
    virtual void P_v200();
    virtual void P_v201();
    virtual void P_v202();
    virtual void P_v203();
    virtual void P_v204();
    virtual void P_v205();
    virtual void P_v206();
    virtual void P_v207();
    virtual void P_v208();
    virtual void P_v209();
    virtual void P_v210();
    virtual void P_v211();
    virtual void P_v212();
    virtual void P_v213();
    virtual void P_v214();
    virtual void P_v215();
    virtual void P_v216();
    virtual void P_v217();
    virtual void P_v218();
    virtual void P_v219();
    virtual void P_v220();
    virtual void P_v221();
    virtual void P_v222();
    virtual void P_v223();
    virtual void P_v224();
    virtual void P_v225();
    virtual void P_v226();
    virtual void P_v227();
    virtual void P_v228();
    virtual void P_v229();
    virtual void P_v230();
    virtual void P_v231();
    virtual void P_v232();
    virtual void P_v233();
    virtual void P_v234();
    virtual void P_v235();
    virtual void P_v236();
    virtual void P_v237();
    virtual void P_v238();
    virtual void P_v239();
    virtual void P_v240();
    virtual void P_v241();
    virtual void P_v242();
    virtual void P_v243();
    virtual void P_v244();
    virtual void P_v245();
    virtual void P_v246();
    virtual void P_v247();
    virtual void P_v248();
    virtual void P_v249();
    virtual void P_v250();
    virtual void P_v251();
    virtual void P_v252();
    virtual void P_v253();
    virtual void P_v254();
    virtual void P_v255();
    virtual void P_v256();
    virtual void P_v257();
    virtual void P_v258();
    virtual void P_v259();
    virtual void P_v260();
    virtual void P_v261();
    virtual void P_v262();
    virtual void P_v263();
    virtual void P_v264();
    virtual void P_v265();
    virtual void P_v266();
    virtual void P_v267();
    virtual void P_v268();
    virtual void P_v269();
    virtual void P_v270();
    virtual void P_v271();
    virtual void P_v272();
    virtual void P_v273();
    virtual void P_v274();
    virtual void P_v275();
    virtual void P_v276();
    virtual void P_v277();
    virtual void P_v278();
    virtual void P_v279();
    virtual void P_v280();
    virtual void P_v281();
    virtual void P_v282();
    virtual void P_v283();
    virtual void P_v284();
    virtual void P_v285();
    virtual void P_v286();
    virtual void P_v287();
    virtual void P_v288();
    virtual void P_v289();
    virtual void P_v290();
    virtual void P_v291();
    virtual void P_v292();
    virtual void P_v293();
    virtual void P_v294();
    virtual void P_v295();
    virtual void P_v296();
    virtual void P_v297();
    virtual void P_v298();
    virtual void P_v299();
    virtual void P_v300();
    virtual void P_v301();
    virtual void P_v302();
    virtual void P_v303();
    virtual void P_v304();
    virtual void P_v305();
    virtual void P_v306();
    virtual void P_v307();
    virtual void P_v308();
    virtual void P_v309();
    virtual void P_v310();
    virtual void P_v311();
    virtual void P_v312();
    virtual void P_v313();
    virtual void P_v314();
    virtual void P_v315();
    virtual void P_v316();
    virtual void P_v317();
    virtual void P_v318();
    virtual void P_v319();
    virtual void Add500(void* a, int b);
};
struct BodyStub;
struct FilterStub
{
    int F4a3a20();
};
struct BodyStub
{
    void Fca2ad0(int a);
    void Fca1410();
};
struct ActStub
{
    virtual void A_v000();
    virtual void A_v001();
    virtual void A_v002();
    virtual void A_v003();
    virtual void A_v004();
    virtual void A_v005();
    virtual void A_v006();
    virtual void A_v007();
    virtual void A_v008();
    virtual void A_v009();
    virtual void A_v010();
    virtual void A_v011();
    virtual void A_v012();
    virtual void A_v013();
    virtual void A_v014();
    virtual void A_v015();
    virtual void A_v016();
    virtual void A_v017();
    virtual void A_v018();
    virtual void A_v019();
    virtual void A_v020();
    virtual void A_v021();
    virtual void A_v022();
    virtual void A_v023();
    virtual void A_v024();
    virtual void A_v025();
    virtual void A_v026();
    virtual void A_v027();
    virtual void A_v028();
    virtual void A_v029();
    virtual void A_v030();
    virtual void A_v031();
    virtual void A_v032();
    virtual void A_v033();
    virtual void A_v034();
    virtual void A_v035();
    virtual void A_v036();
    virtual void A_v037();
    virtual void A_v038();
    virtual void A_v039();
    virtual void A_v040();
    virtual void A_v041();
    virtual void A_v042();
    virtual void A_v043();
    virtual void A_v044();
    virtual void A_v045();
    virtual void A_v046();
    virtual void A_v047();
    virtual void A_v048();
    virtual void A_v049();
    virtual void A_v050();
    virtual void A_v051();
    virtual void A_v052();
    virtual void A_v053();
    virtual void A_v054();
    virtual void A_v055();
    virtual void A_v056();
    virtual void A_v057();
    virtual void A_v058();
    virtual void A_v059();
    virtual void A_v060();
    virtual void A_v061();
    virtual void A_v062();
    virtual void A_v063();
    virtual bool Is100();
    virtual void A_v065();
    virtual void A_v066();
    virtual void A_v067();
    virtual void A_v068();
    virtual void A_v069();
    virtual void A_v070();
    virtual void A_v071();
    virtual void A_v072();
    virtual void A_v073();
    virtual void A_v074();
    virtual void A_v075();
    virtual void A_v076();
    virtual void A_v077();
    virtual void A_v078();
    virtual void A_v079();
    virtual void A_v080();
    virtual void A_v081();
    virtual void A_v082();
    virtual void A_v083();
    virtual void A_v084();
    virtual void A_v085();
    virtual void A_v086();
    virtual void A_v087();
    virtual void A_v088();
    virtual void A_v089();
    virtual void A_v090();
    virtual void A_v091();
    virtual void A_v092();
    virtual void A_v093();
    virtual void A_v094();
    virtual void A_v095();
    virtual void A_v096();
    virtual void A_v097();
    virtual void A_v098();
    virtual void A_v099();
    virtual void A_v100();
    virtual void A_v101();
    virtual void A_v102();
    virtual void A_v103();
    virtual void A_v104();
    virtual void A_v105();
    virtual void A_v106();
    virtual void A_v107();
    virtual void A_v108();
    virtual void A_v109();
    virtual void A_v110();
    virtual void A_v111();
    virtual void A_v112();
    virtual void A_v113();
    virtual void A_v114();
    virtual void A_v115();
    virtual int Get1d0(int a);
    virtual void A_v117();
    virtual void A_v118();
    virtual void A_v119();
    virtual void A_v120();
    virtual void A_v121();
    virtual void A_v122();
    virtual void A_v123();
    virtual void A_v124();
    virtual void A_v125();
    virtual void A_v126();
    virtual void A_v127();
    virtual void A_v128();
    virtual void A_v129();
    virtual void A_v130();
    virtual void A_v131();
    virtual void A_v132();
    virtual void A_v133();
    virtual void A_v134();
    virtual void A_v135();
    virtual bool Is220();
    virtual void A_v137();
    virtual void A_v138();
    virtual bool Is22c(int a);
    virtual void A_v140();
    virtual void A_v141();
    virtual void A_v142();
    virtual void A_v143();
    virtual void A_v144();
    virtual void A_v145();
    virtual void A_v146();
    virtual void A_v147();
    virtual void A_v148();
    virtual void A_v149();
    virtual void A_v150();
    virtual void A_v151();
    virtual void A_v152();
    virtual void A_v153();
    virtual void A_v154();
    virtual void A_v155();
    virtual void A_v156();
    virtual void A_v157();
    virtual void A_v158();
    virtual void A_v159();
    virtual void A_v160();
    virtual void A_v161();
    virtual void A_v162();
    virtual void A_v163();
    virtual void A_v164();
    virtual void A_v165();
    virtual void A_v166();
    virtual void A_v167();
    virtual void A_v168();
    virtual void A_v169();
    virtual void A_v170();
    virtual void A_v171();
    virtual void A_v172();
    virtual void A_v173();
    virtual void A_v174();
    virtual void A_v175();
    virtual void A_v176();
    virtual void A_v177();
    virtual void A_v178();
    virtual void A_v179();
    virtual void A_v180();
    virtual void A_v181();
    virtual void A_v182();
    virtual void A_v183();
    virtual void A_v184();
    virtual void A_v185();
    virtual void A_v186();
    virtual void A_v187();
    virtual void A_v188();
    virtual void A_v189();
    virtual void A_v190();
    virtual void A_v191();
    virtual void A_v192();
    virtual void A_v193();
    virtual void A_v194();
    virtual void A_v195();
    virtual void A_v196();
    virtual void A_v197();
    virtual void A_v198();
    virtual void A_v199();
    virtual void A_v200();
    virtual void A_v201();
    virtual void A_v202();
    virtual void A_v203();
    virtual void A_v204();
    virtual void A_v205();
    virtual void A_v206();
    virtual void A_v207();
    virtual void A_v208();
    virtual void A_v209();
    virtual void A_v210();
    virtual void Upd34c(float dt, bool b);
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
    BodyStub* unkB0;
    void F8ba600();
    ProcStub* F8d8520();
    bool F576d30();
    FilterStub* F931ed0(int* out);
    void F9b17a0(float dt);
};
struct PlayerStub
{
    ProcStub* F8d8520();
    bool F94df60();
};
extern PlayerStub* g_player;
bool __fastcall GetField18Byte(BodyStub* b);
void __cdecl FUN_0062c430(ActStub* a);
struct PAStub
{
    int unk00;
    unsigned int F5be5c0(int lvl);
    ActStub* F968670(unsigned int i);
};
struct BodyHolder
{
    BodyStub* body;
};
struct PLStub
{
    int unk00;
    PAStub arr;
    void F978890(float dt);
    void FUN_009781d0(float dt);
};

// @fnv 0x009781d0
void PLStub::FUN_009781d0(float dt)
{
    ActStub* actor2 = 0;
    ActStub* pEntry = 0;
    unsigned int i;
    for (i = 0; i < arr.F5be5c0(0); i++)
    {
        ActStub* arrow;
        ProcStub* proc7;
        pEntry = arr.F968670(i);
        actor2 = 0;
        if (pEntry && pEntry->Is100() && !pEntry->F576d30())
        {
            actor2 = pEntry;
            actor2->F8ba600();
            actor2->F8d8520()->Upd104();
            if (GetField18Byte(actor2->unkB0))
            {
                int tmp2;
                actor2->unkB0->Fca2ad0(actor2->Get1d0(actor2->F931ed0(&tmp2)->F4a3a20()));
            }
            actor2->unkB0->Fca1410();
            if (!actor2->Is22c(0))
                FUN_0062c430(actor2);
            actor2->Upd34c(dt, g_player->F94df60());
            proc7 = actor2->F8d8520();
            if (proc7)
            {
                proc7->Add500(actor2, 0);
                proc7->Add170(actor2);
                proc7->Add1d8(actor2);
            }
        }
        else
        {
            if (pEntry && pEntry->Is220())
            {
                arrow = pEntry;
                arrow->F9b17a0(dt);
            }
        }
    }
    F978890(dt);
    if (g_player->F8d8520())
        g_player->F8d8520()->Add170(g_player);
}

namespace fnv_009eb500 {
struct RefObj
{
    void FUN_00564db0(int);
};
struct DispatchMembers
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int unk10;
    unsigned int field14;
    DispatchMembers();
    ~DispatchMembers();
};
struct FloatValue
{
    float v;
    FloatValue();
    FloatValue(float);
};
struct SingletonData
{
    unsigned int FUN_009eb620();
};
struct RandomData
{
    int FUN_00867d20();
    signed char FUN_00867d60();
    int FUN_00867c60();
};
extern "C" SingletonData DAT_011e0e80;
extern "C" RandomData DAT_011de7b8;
float __cdecl FUN_00435dd0();
struct FUN_009eb500
{
    int field00;
    unsigned int field04;
    RefObj* field08;
    unsigned int field0c;
    bool field10;
    unsigned int field14;
    unsigned int field18;
    DispatchMembers members;
    FloatValue point;
    unsigned int field38;
    FUN_009eb500(unsigned int, RefObj*, unsigned int, unsigned int, unsigned int, unsigned int);
};
// Initializes the object's fields from the arguments, sets up members with a singleton value and random bits, and stores a float from FUN_00435dd0.
// @fnv 0x009eb500
FUN_009eb500::FUN_009eb500(unsigned int arg1, RefObj* arg2, unsigned int uiField0c, unsigned int arg4,
                           unsigned int arg5, unsigned int uiMemberField08)
    : members(), point()
{
    field04 = arg1;
    field00 = 0;
    if (arg2)
        arg2->FUN_00564db0(1);
    field08 = arg2;
    field0c = uiField0c;
    field10 = false;
    field14 = arg4;
    field18 = arg5;
    members.field08 = uiMemberField08;
    members.field0c = DAT_011e0e80.FUN_009eb620();
    field38 = 0;
    members.field14 =
        (DAT_011de7b8.FUN_00867d20() << 9) | DAT_011de7b8.FUN_00867d60() | (DAT_011de7b8.FUN_00867c60() << 13);
    FloatValue fInitValue(FUN_00435dd0());
    point = fInitValue;
}
}  // namespace fnv_009eb500

// FUN_00c44c90: TaskQueueParallelManager wrapper that forwards a callback
// and one argument to the task queue base class.
typedef void(__cdecl* FUN_00c44d90_t)(void);

extern "C" void __cdecl RunWorkItems(void);

struct TaskQueueBase
{
    void __thiscall FUN_00c44c40(FUN_00c44d90_t callback, int argument);
};

struct TaskQueueShell : public TaskQueueBase
{
    void FUN_00c44c90(int argument);
};

// @fnv 0x00c44c90
void TaskQueueShell::FUN_00c44c90(int argument)
{
    this->FUN_00c44c40(&RunWorkItems, argument);
}

struct RefStub
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsValidTarget();
    unsigned int GetDetectFlags();
};

extern RefStub* g_thePlayerRef;
float __cdecl CalcLow(float);
float __cdecl CalcHigh(float);

struct OwnerStub
{
    RefStub* GetTarget();
    float GetDistance(RefStub*, int, int);
    bool CanCheck();
    unsigned int UpdateDetectionFlags(unsigned int aFlags, float afValue, int aUnused);
};

// Adjusts detection flags based on target validity, distance versus CalcLow/CalcHigh bounds, and the target's detect flags.
// @fnv 0x008858c0
unsigned int OwnerStub::UpdateDetectionFlags(unsigned int aFlags, float afValue, int aUnused)
{
    unsigned int uiResult6 = aFlags;
    RefStub* pTarget3 = GetTarget();
    if (pTarget3 && pTarget3->IsValidTarget())
    {
        float fDist = GetDistance(pTarget3, 0, 0);
        float fLow = CalcLow(afValue);
        float fHigh3 = CalcHigh(afValue);
        RefStub& rTarget2 = *pTarget3;
        unsigned int uiDetect2 = rTarget2.GetDetectFlags();
        if (fDist < fLow && (uiDetect2 & 0xF) == 0)
        {
            uiResult6 = (uiResult6 & ~0x200) | 0x100;
        }
        else if (CanCheck())
        {
            if ((uiDetect2 & 0x500) == 0x400 || fDist > fHigh3 || (pTarget3 == g_thePlayerRef && (aFlags & 0x800)) ||
                (uiDetect2 & 0x200))
            {
                uiResult6 = (uiResult6 & ~0x100) | 0x200;
            }
        }
    }
    return uiResult6;
}

struct SoundHandleStub
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    SoundHandleStub();
    ~SoundHandleStub();
    SoundHandleStub& operator=(const SoundHandleStub& rhs);
    bool IsPlaying();
    bool Play(bool abUnk);
};

struct AudioStub
{
    static AudioStub* GetSingleton();
    SoundHandleStub GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

struct ActorSoundStub
{
    const char* GetSoundName(int aiType, bool abA, bool abB);
    SoundHandleStub PlaySoundAt(const char* apName, int aiUnk, unsigned int auiFlags, bool abUnk);
    void PlayActorSound(int aiType, bool abA, bool abB);
};

extern ActorSoundStub* _g_thePlayerStub;

// @fnv 0x008aded0
void ActorSoundStub::PlayActorSound(int aiType, bool abA, bool abB)
{
    if (!aiType)
        return;
    SoundHandleStub kSound;
    const char* pName4 = 0;
    pName4 = GetSoundName(aiType, abA, abB);
    if (this == _g_thePlayerStub)
    {
        kSound = AudioStub::GetSingleton()->GetSoundHandleByEditorID(pName4, 0x121);
        if (!kSound.IsPlaying())
            kSound.Play(false);
    }
    else
    {
        kSound = PlaySoundAt(pName4, 0, 0x102, true);
    }
}

struct LowListArray
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
    void FUN_0096aaf0(MobileObject*, int);
};
struct LowListObject : MobileObject
{
    bool FUN_00493bb0();
    void FUN_0092f190();
};
struct LowListProcessLists : ProcessLists
{
    void UpdateLowListProcessLists(float delta, bool);
};
// @fnv 0x0096b470
void LowListProcessLists::UpdateLowListProcessLists(float delta, bool)
{
    MobileObject* tail = 0;
    BSSimpleList<MobileObject*>* nextLevel = new BSSimpleList<MobileObject*>;
    int node = 5;
    unsigned int processed;
    unsigned int allUpdated = 0;
    bool deferred = true;
    unsigned int object = ((LowListArray*)&m_kMobileObjectProcessList)->FUN_005de0f0(2);
    processed = ((LowListArray*)&m_kMobileObjectProcessList)->FUN_005be5c0(2);
    for (unsigned int index = object; index < processed; ++index)
    {
        tail = ((LowListArray*)&m_kMobileObjectProcessList)->FUN_00968670(index);
        LowListObject* actor = 0;
        if (tail && !tail->IsStillLoading())
        {
            if (tail->IsActor())
                actor = (LowListObject*)tail;
            if (tail->GetDisabled() || tail->IsDeleted() || ((ActorProcessProxy*)tail)->FUN_00931850() != 2)
            {
                nextLevel->AddHead(tail);
            }
            else if (!DAT_011e0e34)
            {
                if (!FUN_00437bb0(tail) && actor && !actor->FUN_00493bb0())
                {
                    tail->GetCurrentAIProcess()->ResetPackageState();
                }
                else
                {
                    float lastTime = ((LowProcess*)tail->GetCurrentAIProcess())->FUN_007df1f0();
                    float currentTime = g_calendar.GetGameTime();
                    if (lastTime == -1.0)
                    {
                        ((LowListObject*)tail)->FUN_0092f190();
                    }
                    else if (currentTime - lastTime >= 0.30000001192092896 || lastTime > currentTime || delta != 0.0)
                    {
                        if (tail->GetCurrentAIProcess()->IsProcessConditionMet())
                        {
                            ((MobileObjectExt*)tail)->Update(delta);
                            if (FUN_005ac740())
                                ((MobileObjectExt*)tail)->FUN_00565870();
                            LowListObject* updatedActor = 0;
                            if (tail && tail->IsActor())
                                updatedActor = (LowListObject*)tail;
                            if (updatedActor && FUN_004f8960(updatedActor) == 1)
                                deferred = false;
                        }
                    }
                }
            }
        }
    }
    BSSimpleList<MobileObject*>* head = nextLevel;
    while (head && head->GetItem())
    {
        tail = head->GetItem();
        ((LowListArray*)&m_kMobileObjectProcessList)->FUN_0096aaf0(tail, 2);
        if (tail->GetDisabled())
        {
            DAT_011f11a0.Lock(0);
            delete tail->GetCurrentAIProcess();
            ((MobileObjectExt*)tail)->SetCurrentProcess(0);
            DAT_011f11a0.Unlock();
        }
        head = head->GetNext();
    }
    nextLevel->RemoveAll();
    delete nextLevel;
}

struct Proc96
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual bool ready();
    float FUN_007df1f0();
};
struct Obj96
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
    virtual bool isActor();
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
    virtual void update(float);
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
    virtual bool destroyed();
    bool FUN_00576d30();
    bool FUN_00440da0();
    bool FUN_00440d80();
    int FUN_00931850();
    Proc96* FUN_008d8520();
    void FUN_0092f190();
    void FUN_00565870();
    int FUN_004f8960();
    void FUN_00407800(int);
};
struct Array96
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
    void FUN_0096aaf0(MobileObject*, int);
};
struct Shell96
{
    int unk0;
    Array96 arr;
    void FUN_0096b810(float, int);
};
// @fnv 0x0096b810
void Shell96::FUN_0096b810(float delta, int unused)
{
    MobileObject* h = 0;
    bool p = true;
    int a = 0;
    BSSimpleList<MobileObject*>* eb = new BSSimpleList<MobileObject*>;
    unsigned int f = arr.FUN_005de0f0(1);
    unsigned int i = arr.FUN_005be5c0(1);
    for (unsigned int uiIndex = f; uiIndex < i; uiIndex++)
    {
        h = arr.FUN_00968670(uiIndex);
        if (h && !((Obj96*)h)->FUN_00576d30())
        {
            if (((Obj96*)h)->FUN_00440da0() || ((Obj96*)h)->FUN_00440d80() || ((Obj96*)h)->FUN_00931850() != 1)
                eb->AddHead(h);
            else if (!DAT_011e0e34)
            {
                float last = ((Obj96*)h)->FUN_008d8520()->FUN_007df1f0();
                float actor = g_calendar.GetGameTime();
                Obj96* now = 0;
                if (((Obj96*)h)->isActor())
                    now = (Obj96*)h;
                if (last == -1.0)
                    ((Obj96*)h)->FUN_0092f190();
                else if (actor - last >= 0.15000000596046448 || last > actor || delta != 0.0)
                {
                    if (((Obj96*)h)->FUN_008d8520()->ready())
                    {
                        ((Obj96*)h)->update(delta);
                        if (FUN_005ac740())
                            ((Obj96*)h)->FUN_00565870();
                        Obj96* pUpdatedActor = 0;
                        if (h && ((Obj96*)h)->isActor())
                            pUpdatedActor = (Obj96*)h;
                        if (pUpdatedActor && pUpdatedActor->FUN_004f8960() == 1)
                            p = false;
                    }
                }
            }
        }
    }
    BSSimpleList<MobileObject*>* s = eb;
    while (s && s->GetItem())
    {
        h = s->GetItem();
        arr.FUN_0096aaf0(h, 1);
        if (((Obj96*)h)->destroyed())
        {
            DAT_011f11a0.Lock(0);
            delete h;
            DAT_011f11a0.Unlock();
        }
        else if (((Obj96*)h)->FUN_00440da0())
        {
            DAT_011f11a0.Lock(0);
            delete (BaseProcess*)((Obj96*)h)->FUN_008d8520();
            ((Obj96*)h)->FUN_00407800(0);
            DAT_011f11a0.Unlock();
        }
        s = s->GetNext();
    }
    eb->RemoveAll();
    delete eb;
}

struct ActorEntity;
struct DetectProcess
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
    virtual bool Check(ActorEntity*);
};
struct DetectComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool Check();
};
struct DetectMisc
{
    bool FUN_00705cf0();
};
struct DetectBase
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    DetectComponent component;
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
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    DetectMisc misc;
};
struct ActorEntity
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
    virtual bool IsActor();
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
    virtual int Active();
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
    virtual bool State(int);
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
    virtual void SetTimer(float);
    virtual float Timer();
    virtual void Reset();
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
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
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    unsigned char enabled;
    float FUN_005723b0(ActorEntity*, int, int);
    bool FUN_00437bd0();
    DetectBase* Base();
    DetectProcess* Process();
    unsigned char FUN_00493bb0();
    int FUN_008a0d10(int, ActorEntity*, bool*, unsigned char, int, int, bool*);
    bool IsHostileTo(ActorEntity*, int, int*, int);
    bool FUN_008bc700(ActorEntity*);
    bool FUN_008a78f0(int);
    void FUN_008c8bb0(int);
    void FUN_00966f20(ActorEntity*, bool, int);
    void FUN_00967350(ActorEntity*);
};
struct DetectArray
{
    unsigned int Count(int);
    unsigned int Head(int);
    ActorEntity* Item(unsigned int);
};
struct DetectTime
{
    float Delta();
};
extern DetectTime DAT_011f6394;
struct DetectLoad
{
    bool FUN_0047c850();
};
extern DetectLoad* DAT_011de45c;
struct DetectInterface
{
    float FUN_007014e0(int);
};
extern DetectInterface* DAT_011d8804;
struct DetectSetting
{
    float* Value();
};
extern DetectSetting DAT_011ccf94, DAT_011d13c8;
float __cdecl FUN_0040ebd0(float, float);
float RandomFloat(float, float);
struct DetectionLists
{
    int field00;
    DetectArray actors;
    void FUN_0096e3c0(ActorEntity*);
    void UpdateDetection();
};
extern DetectionLists DAT_011e0e80;
// @fnv 0x0096c330
void DetectionLists::UpdateDetection()
{
    ActorEntity* h = 0;
    ActorEntity* p = 0;
    float a;
    unsigned int i = actors.Count(0);
    a = i * DAT_011f6394.Delta();
    a = FUN_0040ebd0(a, 5.0f);
    if (i == 0)
        ((ActorEntity*)DAT_011dea3c)->FUN_008c8bb0(0);
    for (unsigned int s = actors.Head(0); s < actors.Count(0); ++s)
    {
        p = actors.Item(s);
        if (p && p->IsActor())
        {
            h = p;
            ActorEntity* f = h;
            if (f->enabled && f->Active())
            {
                float eb = f->FUN_005723b0(((ActorEntity*)DAT_011dea3c), 0, 0);
                if (f != ((ActorEntity*)DAT_011dea3c) && !DAT_011de45c->FUN_0047c850())
                {
                    float cf = h->Timer();
                    if (s == 0)
                        ((ActorEntity*)DAT_011dea3c)->FUN_008c8bb0(0);
                    if (cf < 0.0 && !f->FUN_00437bd0() && !h->State(0))
                    {
                        if (DAT_011d8804->FUN_007014e0(1) <= 0.0)
                        {
                            float q = RandomFloat(0.0f, a);
                            h->SetTimer(q);
                            if (!f->Base()->component.Check() && f->Process()->Check(f))
                            {
                                bool k = false;
                                unsigned char e = h->FUN_00493bb0();
                                bool c = false;
                                int b = ((ActorEntity*)DAT_011dea3c)->FUN_008a0d10(1, h, &k, e, 0, 0, &c);
                                int l = 0;
                                bool ba = false;
                                if (h->IsHostileTo(((ActorEntity*)DAT_011dea3c), 0, &l, 0) ||
                                    h->FUN_008bc700(((ActorEntity*)DAT_011dea3c)))
                                    ba = true;
                                else if ((l == 0 || l == 1) && h->Base()->misc.FUN_00705cf0() && !h->FUN_008a78f0(6))
                                    ba = true;
                                if (h && eb < *DAT_011ccf94.Value())
                                    DAT_011e0e80.FUN_0096e3c0(f);
                                if (b > *DAT_011d13c8.Value())
                                    ((ActorEntity*)DAT_011dea3c)->FUN_00966f20(h, ba, 0);
                                else if (c || k)
                                    ((ActorEntity*)DAT_011dea3c)->FUN_00966f20(h, ba, 1);
                                else
                                    ((ActorEntity*)DAT_011dea3c)->FUN_00967350(h);
                            }
                        }
                    }
                    else
                    {
                        if (cf < 0.0)
                            ((ActorEntity*)DAT_011dea3c)->FUN_00967350(h);
                        h->Reset();
                    }
                }
            }
        }
    }
}

namespace fnv_0096d810 {
extern const double DAT_01012060;
extern const double DAT_01011590;

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
    int aiMemoryContext;
};

struct FUN_0084d030_timer
{
    float FUN_0084d030();
};
extern FUN_0084d030_timer DAT_011f6394;

struct FUN_009640b0_player
{
    int FUN_009640b0();
    int GetActionObjectItemId();
};

struct FUN_0040fbf0_lock
{
    bool FUN_0078d200();
    void Lock(char* apName);
    void Unlock();
};

void __cdecl FUN_008d5bc0();
void __cdecl FUN_008d1560();
void __cdecl FUN_004772f0();
unsigned char __cdecl FUN_00525420();
int& __fastcall FUN_0043d4d0(int* apValue);
extern int DAT_011c3ea4;

struct FUN_0096d810_shell : public ProcessLists
{
    float FUN_0096d490();
    void FUN_0096d4b0(float afTime);
    void StartActorDialogue(int a1, int a2, int a3);
    void UpdateLowProcesses(float afTime, bool abFlag);
    void UpdateLowListProcessLists(float afTime, bool abFlag);
    void FUN_0096b810(float afTime, bool abFlag);
    void UpdateCrimeLists();
    void FUN_0096d810();
};

// Advances ProcessLists timers, updates globals, and throttles per-frame processing based on frame rate and pending flags.
// @fnv 0x0096d810
void FUN_0096d810_shell::FUN_0096d810()
{
    AutoMemContext kMemContext((MEM_CONTEXT)0x2a, true,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\ProcessLists.cpp", 0x521);

    if (m_fProcessListValue2 >= DAT_01012060)
        m_fProcessListValue2 -= DAT_011f6394.FUN_0084d030();
    if (m_fProcessUpdateTimer >= DAT_01012060)
        m_fProcessUpdateTimer -= DAT_011f6394.FUN_0084d030();

    DAT_011e0358 = DAT_011de7b8.FUN_00867da0();
    DAT_011e035c = DAT_011de7b8.FUN_00867c60();
    DAT_011a39c4 = DAT_011de7b8.FUN_00867d20();
    DAT_011e0360 = DAT_011de7b8.FUN_00867d60();
    FUN_008d5bc0();
    StartActorDialogue(((FUN_009640b0_player*)DAT_011dea3c)->GetActionObjectItemId(),
                       ((FUN_009640b0_player*)DAT_011dea3c)->FUN_009640b0(), 0);
    FUN_008d1560();
    if (FUN_0043d4d0(&DAT_011c3ea4) == 1)
        FUN_004772f0();

    float fDiff = DAT_011f6394.FUN_0084d030();
    FUN_0096d4b0(fDiff + FUN_0096d490());
    int iFrameRate = 1.0f / fDiff;
    bool bProcess = true;
    m_iMobileObjectCount = ((Array_973590*)&m_kMobileObjectProcessList)->FUN_005be5c0(0);
    m_fProcessListValue1 += fDiff;
    if (iFrameRate < 50)
    {
        if (iFrameRate < 10)
        {
            if (m_fProcessListValue1 < 1.0)
            {
                bProcess = false;
                m_fProcessListValue1 += fDiff;
            }
            else
                m_fProcessListValue1 = 0.0f;
        }
        else
        {
            if (m_fProcessListValue1 < 1.0)
            {
                m_fProcessListValue1 += (1.0f - fDiff) / DAT_01011590;
                bProcess = false;
            }
            else
                m_fProcessListValue1 = 0.0f;
        }
    }

    if (bProcess)
    {
        if (m_bUpdateLowProcesses && !FUN_00525420() && ((FUN_0040fbf0_lock*)&DAT_011f11a0)->FUN_0078d200())
        {
            UpdateLowProcesses(0.0f, false);
            ((FUN_0040fbf0_lock*)&DAT_011f11a0)->Unlock();
        }
        if (m_bUpdateLowListProcessLists && !FUN_00525420())
        {
            ((FUN_0040fbf0_lock*)&DAT_011f11a0)->Lock(0);
            UpdateLowListProcessLists(0.0f, false);
            ((FUN_0040fbf0_lock*)&DAT_011f11a0)->Unlock();
        }
        if (m_bRunSecondProcessUpdate)
        {
            ((FUN_0040fbf0_lock*)&DAT_011f11a0)->Lock(0);
            FUN_0096b810(0.0f, false);
            ((FUN_0040fbf0_lock*)&DAT_011f11a0)->Unlock();
        }
        if (m_fCrimeListUpdateTimer <= DAT_01012060)
            UpdateCrimeLists();
        else
            m_fCrimeListUpdateTimer -= DAT_011f6394.FUN_0084d030();
    }
}
}  // namespace fnv_0096d810

namespace fnv_0096db30 {
struct Obj96;
struct Proc96
{
    float FUN_007df1f0();
    void UpdateSelectionTimer(Obj96*);
};
struct Obj96
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual bool V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual bool V136();
    virtual bool V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210(float, bool);
    bool FUN_00576d30();
    Proc96* FUN_008d8520();
};
struct Array96
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    Obj96* FUN_00968670(unsigned int);
};
struct Global96
{
    Array96* FUN_00717e50();
};
extern Global96 DAT_011e0e80;
struct TimeGlobal
{
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;
struct FUN_009bec10_shell
{
    void FUN_009bec10(float);
};
struct FUN_009ae580_shell
{
    void FUN_009ae580(float);
};
struct Target96
{
    void FUN_0096db30(float delta, bool flag, int level);
};
// @fnv 0x0096db30
void Target96::FUN_0096db30(float delta, bool flag, int level)
{
    Obj96* unused = 0;
    Obj96* array = 0;
    Array96* actor = DAT_011e0e80.FUN_00717e50();
    for (unsigned int i = actor->FUN_005de0f0(level); i < actor->FUN_005be5c0(level); i++)
    {
        Obj96* object = actor->FUN_00968670(i);
        if (object && object->FUN_00576d30())
            continue;
        if (object && object->V64())
        {
            array = object;
            if (level)
                delta = g_timeGlobal.GetTimeStamp() / 1000.0 - array->FUN_008d8520()->FUN_007df1f0();
            array->V210(delta, flag);
            if (!level)
            {
                Proc96* process = array->FUN_008d8520();
                process->UpdateSelectionTimer(array);
            }
        }
        else if (object->V137())
        {
            FUN_009bec10_shell* projectile = (FUN_009bec10_shell*)object;
            projectile->FUN_009bec10(0.0f);
        }
        else if (object->V136())
        {
            FUN_009ae580_shell* explosion = (FUN_009ae580_shell*)object;
            explosion->FUN_009ae580(0.0f);
        }
    }
}
}  // namespace fnv_0096db30

struct Controller96
{
    unsigned int FUN_0084e3a0();
};
struct Actor96
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
    virtual bool IsActor();
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
    virtual Controller96* GetController();
    BaseProcess* FUN_008d8520();
};
struct EntryArray96
{
    unsigned int FUN_0055b980();
    Actor96* FUN_00968670(unsigned int);
};
struct FUN_0096a2d0
{
    Actor96* data;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(Actor* const&);
};
TESObjectREFR* __cdecl LookupFormByID(unsigned int);
struct Target96
{
    int unk00;
    EntryArray96 entries;
    FUN_0096a2d0* FUN_0096f450(unsigned int, Actor96*);
};
// @fnv 0x0096f450
FUN_0096a2d0* Target96::FUN_0096f450(unsigned int uiControllerId, Actor96* pExcludedActor)
{
    FUN_0096a2d0* reference = 0;
    Actor96* actor = 0;
    Actor96* result = 0;
    TESObjectREFR* mobile = LookupFormByID(uiControllerId);
    for (unsigned int i = 0; i < entries.FUN_0055b980(); ++i)
    {
        result = entries.FUN_00968670(i);
        actor = 0;
        if (result && result->IsActor())
            actor = result;
        if (actor)
        {
            BaseProcess* process = actor->FUN_008d8520();
            if (process)
            {
                process->ClearObjectFromAcquireListAlt(uiControllerId);
                if (mobile)
                    process->SetCurrentTargetReference(mobile);
            }
            if (actor->GetController() && actor->GetController()->FUN_0084e3a0() == uiControllerId &&
                pExcludedActor != actor)
            {
                if (!reference)
                    reference = new FUN_0096a2d0;
                reference->FUN_005ae3d0((Actor*)actor);
            }
        }
    }
    return reference;
}

namespace fnv_0096f600 {
struct ExtraFollower
{
    int f0;
    int f4;
    int f8;
    BSSimpleList<TESObjectREFR*>* pNext;
};
struct FUN_00422700_shell
{
    ExtraFollower* FUN_00422700();
};
struct FUN_00422690_shell
{
    void FUN_00422690(Actor*);
};
struct EffectSettingShell
{
    TESObjectLIGH* GetLight();
};
struct EffectSetting
{
    void SetLight(TESObjectLIGH*);
};
struct DetEv18
{
    char pad[0x18];
    Actor* p18;
};
struct TopicInfoArray
{
    unsigned int FUN_005be5c0(int);
    Actor* FUN_00968670(unsigned int);
};
struct TESChallenge
{
    Actor* GetProgressValue();
};
struct InterfaceManager
{
    Actor* FUN_00874480();
};
struct FUN_008b3200_shell
{
    void FUN_008b3200(Actor*);
};
struct FUN_00419ea0_shell
{
    Actor* FUN_00419ea0();
};
struct FUN_00419dc0_shell
{
    void FUN_00419dc0(int);
};
struct FUN_0044ddc0_shell
{
    Actor* FUN_0044ddc0();
};
struct FUN_0041ca90
{
    int get();
};
struct FUN_008d80e0_shell
{
    Actor* FUN_008d80e0();
};
struct FUN_00881680_shell
{
    void FUN_00881680(int);
};
struct Extra19
{
    char pad[0x14];
    Actor* p14;
};
struct Holder00420dd0
{
    Extra19* GetExtraData(unsigned char);
};
struct FUN_008a6650_shell
{
    bool FUN_008a6650(int);
};
struct SandboxTargetInfo;
struct ActorTargetSource
{
    SandboxTargetInfo* GetProcessTarget();
};
struct FUN_005e3fc0_shell
{
    Actor* FUN_005e3fc0();
};
struct FUN_00994ef0_Class
{
    void Set(int);
};
struct FUN_0098420_shell
{
    void FUN_009f8420(Actor*);
};
struct FUN_008a6730_Actor
{
    void FUN_008a6730(Actor*);
};
bool __fastcall IsInPackageType(Actor*);
struct IdleForm67
{
    Actor* FUN_0067f390();
    void FUN_0067f3c0(int);
};
struct ScriptGetText
{
    IdleForm67* GetText();
    char* GetData();
};
struct FUN_00680020_shell
{
    Actor* FUN_00680020();
};
struct FUN_00674d40_shell
{
    bool FUN_00674d40();
};
struct FUN_009336c0_shell
{
    bool FUN_009336c0();
};
struct Host00881620
{
    void FUN_00881620(int);
};
struct FUN_00881650_shell
{
    Actor* FUN_00881650();
};
struct FUN_0097f9c0_shell
{
    void FUN_0097f9c0(Actor*);
};
struct PkgDataVirt
{
    virtual void v0();
    virtual void v1(Actor*);
};
struct FUN_004212b0_shell
{
    PkgDataVirt* FUN_004212b0();
};
struct FUN_0041cb70_shell
{
    Actor* FUN_0041cb70();
};
struct FUN_0041cab0_shell
{
    void FUN_0041cab0(int);
};
struct FurnMarkShell
{
    void FUN_00c54550(float);
    void FUN_00568ab0(int);
    void FUN_0098ddd0(void*);
};
extern int DAT_011f426c;
struct ActorView : public TESObjectREFR
{
    virtual void a144();
    virtual void a145();
    virtual void a146();
    virtual void a147();
    virtual void a148();
    virtual void a149();
    virtual void a150();
    virtual void a151();
    virtual void a152();
    virtual void a153();
    virtual void a154();
    virtual void a155();
    virtual void a156();
    virtual void a157();
    virtual void a158();
    virtual void a159();
    virtual void a160();
    virtual void a161();
    virtual void a162();
    virtual void a163();
    virtual void a164();
    virtual void a165();
    virtual void a166();
    virtual void a167();
    virtual void a168();
    virtual void a169();
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual Actor* v2c8();
    virtual void b171();
    virtual void b172();
    virtual void b173();
    virtual void b174();
    virtual void b175();
    virtual void b176();
    virtual void b177();
    virtual void b178();
    virtual void b179();
    virtual void b180();
    virtual void b181();
    virtual void b182();
    virtual void b183();
    virtual void b184();
    virtual void b185();
    virtual void b186();
    virtual void b187();
    virtual void b188();
    virtual void b189();
    virtual void b190();
    virtual void b191();
    virtual void b192();
    virtual void b193();
    virtual void b194();
    virtual void b195();
    virtual void b196();
    virtual void b197();
    virtual void b198();
    virtual void b199();
    virtual void b200();
    virtual void b201();
    virtual void b202();
    virtual void b203();
    virtual void b204();
    virtual void b205();
    virtual void b206();
    virtual void b207();
    virtual void b208();
    virtual void b209();
    virtual void b210();
    virtual void b211();
    virtual void b212();
    virtual void b213();
    virtual void b214();
    virtual void b215();
    virtual void b216();
    virtual void b217();
    virtual void b218();
    virtual void b219();
    virtual void b220();
    virtual void b221();
    virtual void b222();
    virtual void b223();
    virtual void b224();
    virtual void b225();
    virtual void b226();
    virtual void b227();
    virtual void b228();
    virtual void b229();
    virtual void b230();
    virtual void b231();
    virtual void b232();
    virtual void b233();
    virtual void b234();
    virtual void b235();
    virtual void b236();
    virtual void b237();
    virtual void b238();
    virtual void b239();
    virtual void b240();
    virtual void b241();
    virtual void b242();
    virtual void b243();
    virtual void b244();
    virtual void b245();
    virtual void b246();
    virtual void b247();
    virtual void b248();
    virtual void b249();
    virtual void b250();
    virtual void b251();
    virtual void b252();
    virtual void b253();
    virtual void b254();
    virtual void b255();
    virtual void b256();
    virtual void b257();
    virtual void* v428();
};
struct PlayerView : public MobileObject
{
    virtual void c193();
    virtual void c194();
    virtual void c195();
    virtual void c196();
    virtual void c197();
    virtual void c198();
    virtual void c199();
    virtual void c200();
    virtual void c201();
    virtual void c202();
    virtual void c203();
    virtual void c204();
    virtual void c205();
    virtual void c206();
    virtual void c207();
    virtual void c208();
    virtual void c209();
    virtual void c210();
    virtual void c211();
    virtual void c212();
    virtual void c213();
    virtual void c214();
    virtual void c215();
    virtual void c216();
    virtual void c217();
    virtual void c218();
    virtual void c219();
    virtual void c220();
    virtual void c221();
    virtual void c222();
    virtual void c223();
    virtual void c224();
    virtual void c225();
    virtual void c226();
    virtual void c227();
    virtual void c228();
    virtual void c229();
    virtual void c230();
    virtual void c231();
    virtual void c232();
    virtual void c233();
    virtual void c234();
    virtual void c235();
    virtual void c236();
    virtual void c237();
    virtual void c238();
    virtual void c239();
    virtual void c240();
    virtual void c241();
    virtual void c242();
    virtual void c243();
    virtual void c244();
    virtual void c245();
    virtual void c246();
    virtual void c247();
    virtual void c248();
    virtual void c249();
    virtual void c250();
    virtual void c251();
    virtual void c252();
    virtual void c253();
    virtual void c254();
    virtual void c255();
    virtual void c256();
    virtual void c257();
    virtual void c258();
    virtual void c259();
    virtual void c260();
    virtual void c261();
    virtual void c262();
    virtual void c263();
    virtual void c264();
    virtual void c265();
    virtual void c266();
    virtual void c267();
    virtual void c268();
    virtual void c269();
    virtual void c270();
    virtual void c271();
    virtual void c272();
    virtual void c273();
    virtual void c274();
    virtual void c275();
    virtual void c276();
    virtual void c277();
    virtual void c278();
    virtual void c279();
    virtual void c280();
    virtual void c281();
    virtual void v282(Actor*);
};

struct FUN_0096f600_shell : public ProcessLists
{
    void FUN_0096f600(Actor* arg1, bool arg2);
    void FUN_0096e2f0(Actor*);
};

// Clears references to arg1 from the player and all loaded actors, processes, packages and lists, optionally clearing package targets.
// @fnv 0x0096f600
void FUN_0096f600_shell::FUN_0096f600(Actor* arg1, bool abClearPackageTargets)
{
    Actor* bed1;
    Actor* argCopy0;
    Actor* proc;
    DetEv18* fol2;
    Actor* kIter;
    BSSimpleList<TESObjectREFR*>* cell0;
    int n;
    if (arg1->IsActor())
    {
        if (((FUN_00422700_shell*)pPlayer->GetExtraData())->FUN_00422700() != 0)
        {
            if (((FUN_00422700_shell*)pPlayer->GetExtraData())->FUN_00422700()->pNext != 0)
            {
                ((FUN_00422700_shell*)pPlayer->GetExtraData())->FUN_00422700()->pNext->Remove(arg1);
            }
        }
        if (0 != pPlayer->GetCurrentAIProcess())
        {
            pPlayer->GetCurrentAIProcess()->SetActorDetectionLevel(arg1, (BaseProcess::DetectionListType)3);
        }
        FUN_0096e2f0(arg1);
    }
    if (((EffectSettingShell*)pPlayer)->GetLight() == (TESObjectLIGH*)arg1)
    {
        ((EffectSetting*)pPlayer)->SetLight((TESObjectLIGH*)0);
    }
    if (pPlayer->GetCurrentAIProcess() != 0)
    {
        if (pPlayer->GetCurrentAIProcess()->GetRelatedReference() == (TESObjectREFR*)arg1)
        {
            pPlayer->GetCurrentAIProcess()->ClearCurrentTarget();
        }
        if (pPlayer->GetCurrentAIProcess()->GetPreviousReference() == (TESObjectREFR*)arg1)
        {
            pPlayer->GetCurrentAIProcess()->SetActorTargetReference(0);
        }
        fol2 = (DetEv18*)pPlayer->GetCurrentAIProcess()->FindDetectionEventForActor((Actor*)pPlayer);
        if (fol2 != 0)
        {
            if (fol2->p18 == arg1)
            {
                if (pPlayer->GetCurrentAIProcess() != 0)
                {
                    pPlayer->GetCurrentAIProcess()->RemoveDetectionEvent();
                }
            }
        }
    }
    if (arg1->IsActor())
    {
        argCopy0 = arg1;
        ((PlayerView*)pPlayer)->v282(argCopy0);
    }
    kIter = 0;
    for (n = 0; n < ((TopicInfoArray*)&m_kMobileObjectProcessList)->FUN_005be5c0(3); n++)
    {
        kIter = ((TopicInfoArray*)&m_kMobileObjectProcessList)->FUN_00968670(n);
        bed1 = 0;
        proc = 0;
        if (kIter != 0)
        {
            if (!kIter->IsStillLoading())
            {
                if (kIter->IsActor())
                {
                    bed1 = kIter;
                }
                else if (kIter->IsProjectile())
                {
                    proc = kIter;
                }
                BSSimpleList<TESObjectREFR*>* folNode = 0;
                ExtraFollower* c = 0;
                if (bed1 != 0)
                {
                    c = ((FUN_00422700_shell*)bed1->GetExtraData())->FUN_00422700();
                }
                if (c != 0)
                {
                    folNode = c->pNext;
                }
                if (bed1 != 0)
                {
                    if (((FUN_00422700_shell*)bed1->GetExtraData())->FUN_00422700() != 0)
                    {
                        if (arg1->IsActor())
                        {
                            Actor* ev1 = arg1;
                            ((FUN_00422690_shell*)bed1->GetExtraData())->FUN_00422690(ev1);
                        }
                    }
                }
                if (proc != 0)
                {
                    if (((InterfaceManager*)proc)->FUN_00874480() == arg1)
                    {
                        ((FUN_009707f0_shell*)proc)->FUN_009707f0(0);
                    }
                }
                if (kIter != 0 && bed1 == 0)
                {
                    if (((TESChallenge*)kIter)->GetProgressValue() != 0)
                    {
                        if (arg1 == ((TESChallenge*)kIter)->GetProgressValue())
                        {
                            kIter->Unk_A2();
                        }
                    }
                }
                else
                {
                    while (!!bed1)
                    {
                        ((FUN_008b3200_shell*)bed1)->FUN_008b3200(arg1);
                        if (bed1->GetExtraData() != 0)
                        {
                            if (((FUN_00419ea0_shell*)bed1->GetExtraData())->FUN_00419ea0() == arg1)
                            {
                                ((FUN_00419dc0_shell*)bed1->GetExtraData())->FUN_00419dc0(0);
                            }
                        }
                        BaseProcess* mainProc = bed1->GetCurrentAIProcess();
                        if (((EffectSettingShell*)bed1)->GetLight() == (TESObjectLIGH*)arg1)
                        {
                            ((EffectSetting*)bed1)->SetLight((TESObjectLIGH*)0);
                            if (mainProc != 0)
                            {
                                mainProc->SetCombatAlerted(false);
                                mainProc->ClearMovementStopped();
                            }
                        }
                        if (mainProc != 0)
                        {
                            if (mainProc->GetProcessLevel() < 2)
                            {
                                mainProc->SetActorDetectionLevel(arg1, (BaseProcess::DetectionListType)3);
                                mainProc->SetDetectionTarget((TESObjectREFR*)arg1);
                                mainProc->ClearTargetReference((TESObjectREFR*)arg1);
                                DetEv18* q = (DetEv18*)mainProc->FindDetectionEventForActor((Actor*)pPlayer);
                                if (q != 0)
                                {
                                    if (q->p18 == arg1)
                                    {
                                        mainProc->RemoveDetectionEvent();
                                    }
                                }
                                if (mainProc->GetRelatedReference() == (TESObjectREFR*)arg1)
                                {
                                    mainProc->ClearCurrentTarget();
                                }
                                if (mainProc->GetPreviousReference() == (TESObjectREFR*)arg1)
                                {
                                    mainProc->SetActorTargetReference(0);
                                }
                                if (arg1->IsActor())
                                {
                                    mainProc->EvaluateCurrentPackage(arg1);
                                }
                                TESPackage* ed = mainProc->GetRunOncePackage();
                                if (ed != 0)
                                {
                                    ActorPackageContext* proc2 = mainProc->GetCurrentProcessData();
                                    if (proc2 != 0 && ((FUN_0044ddc0_shell*)proc2)->FUN_0044ddc0() == arg1)
                                    {
                                        ((FUN_00881680_shell*)bed1)->FUN_00881680(0);
                                    }
                                    else if (((FUN_0041ca90*)ed)->get() == 0x1c)
                                    {
                                        FUN_0041ca90* ac2;
                                        ac2 = (FUN_0041ca90*)ed;
                                        if (((FUN_008d80e0_shell*)ac2)->FUN_008d80e0() == arg1)
                                        {
                                            bed1->Unk_A2();
                                        }
                                    }
                                }
                            }
                        ti3:
                            mainProc->ClearReferenceRecords((TESObjectREFR*)arg1);
                            Extra19* unit19 = ((Holder00420dd0*)bed1->GetExtraData())->GetExtraData(0x19);
                            if (unit19 != 0)
                            {
                                if (unit19->p14 == arg1)
                                {
                                    unit19->p14 = 0;
                                }
                            }
                            if (((FUN_008a6650_shell*)bed1)->FUN_008a6650(0))
                            {
                                SandboxTargetInfo* mainInfo;
                                mainInfo = ((ActorTargetSource*)bed1)->GetProcessTarget();
                                FUN_005e3fc0_shell* pkg2b = 0;
                                if (mainInfo != 0)
                                {
                                    if (((FUN_0041ca90*)mainInfo)->get() == 0x16)
                                    {
                                        pkg2b = (FUN_005e3fc0_shell*)mainInfo;
                                    }
                                }
                                if (pkg2b != 0)
                                {
                                    if (pkg2b->FUN_005e3fc0() == arg1)
                                    {
                                        ((FUN_00994ef0_Class*)pkg2b)->Set(0);
                                    }
                                }
                                ((FUN_008a6730_Actor*)bed1)->FUN_008a6730(arg1);
                            }
                            else if (IsInPackageType(bed1))
                            {
                                if (arg1->IsActor())
                                {
                                    SandboxTargetInfo* ti2 = ((ActorTargetSource*)bed1)->GetProcessTarget();
                                    Actor* val = arg1;
                                    FUN_0098420_shell* v428;
                                    v428 = 0;
                                    if (0 != ti2)
                                    {
                                        if (((FUN_0041ca90*)ti2)->get() == 0x18)
                                        {
                                            v428 = (FUN_0098420_shell*)ti2;
                                        }
                                    }
                                    if (0 != v428)
                                    {
                                        v428->FUN_009f8420(val);
                                    }
                                }
                            }
                            mainProc->SetReferenceTarget(arg1);
                            ExtraDataList* b = bed1->GetExtraData();
                            if (b != 0)
                            {
                                PkgDataVirt* pd = ((FUN_004212b0_shell*)b)->FUN_004212b0();
                                if (pd != 0)
                                {
                                    pd->v1(arg1);
                                }
                                Actor* ti5;
                                ti5 = ((FUN_0041cb70_shell*)b)->FUN_0041cb70();
                                if (ti5 == arg1)
                                {
                                    ((FUN_0041cab0_shell*)b)->FUN_0041cab0(0);
                                }
                            }
                            if (arg1->IsActor())
                            {
                                Actor* pForm;
                                pForm = arg1;
                                if (mainProc->GetCurrentMagicTarget() == (MagicTarget*)pForm)
                                {
                                    mainProc->SetMagicTarget(0);
                                }
                            }
                            if (mainProc->GetProcessLevel() == 0)
                            {
                                mainProc->AdvanceProcess();
                            }
                            if (((EffectSettingShell*)bed1)->GetLight() == (TESObjectLIGH*)arg1)
                            {
                                ((EffectSetting*)bed1)->SetLight((TESObjectLIGH*)0);
                            }
                            if (abClearPackageTargets)
                            {
                                SandboxTargetInfo* pkg;
                                pkg = ((ActorTargetSource*)bed1)->GetProcessTarget();
                                if (pkg != 0)
                                {
                                    if (((ScriptGetText*)pkg)->GetText() != 0)
                                    {
                                        if (((ScriptGetText*)pkg)->GetText()->FUN_0067f390() == arg1)
                                        {
                                            ((ScriptGetText*)pkg)->GetText()->FUN_0067f3c0(0);
                                        }
                                    }
                                }
                                TESPackage* pkg2 = mainProc->GetCurrentPackage();
                                if (!!pkg2)
                                {
                                    if (((ScriptGetText*)pkg2)->GetText() != 0)
                                    {
                                        if (((ScriptGetText*)pkg2)->GetText()->FUN_0067f390() == arg1)
                                        {
                                            ((ScriptGetText*)pkg2)->GetText()->FUN_0067f3c0(0);
                                        }
                                    }
                                }
                            }
                            void* i;
                            i = ((ActorView*)bed1)->v428();
                            if (i != 0)
                            {
                                ((FUN_0097f9c0_shell*)i)->FUN_0097f9c0(arg1);
                            }
                            if (mainProc->GetTarget() == (TESObjectREFR*)arg1)
                            {
                                mainProc->SetTarget(0);
                            }
                            if (((ActorView*)bed1)->v2c8() == arg1)
                            {
                                ((Host00881620*)bed1)->FUN_00881620(0);
                            }
                            TESPackage* ac;
                            ac = mainProc->GetRunOncePackage();
                            if (((FUN_00881650_shell*)bed1)->FUN_00881650() == arg1 ||
                                (ac != 0 && ((ScriptGetText*)ac)->GetData() != 0 &&
                                 ((FUN_00680020_shell*)((ScriptGetText*)ac)->GetData())->FUN_00680020() == arg1))
                            {
                                if (((FUN_009336c0_shell*)bed1)->FUN_009336c0())
                                {
                                    bed1->Unk_A2();
                                }
                                else
                                {
                                    if (((FUN_00674d40_shell*)((ActorTargetSource*)bed1)->GetProcessTarget())
                                            ->FUN_00674d40())
                                    {
                                        ((FUN_00881680_shell*)bed1)->FUN_00881680(0);
                                    }
                                    else
                                    {
                                        mainProc->StopPackage();
                                        mainProc->StopRunOncePackage();
                                    }
                                }
                            }
                            mainProc->SetCurrentTargetReference((TESObjectREFR*)arg1);
                            if (mainProc->GetFurnitureReference() == (TESObjectREFR*)arg1)
                            {
                                ((FurnMarkShell*)mainProc->GetFurnitureMarkerData())->FUN_00c54550(0.0f);
                                ((FurnMarkShell*)mainProc->GetFurnitureMarkerData())->FUN_00568ab0(0);
                                ((FurnMarkShell*)mainProc->GetFurnitureMarkerData())->FUN_0098ddd0(&DAT_011f426c);
                                mainProc->SetFurnitureMarkerData(0, 0x7f,
                                                                 bed1->GetCurrentAIProcess()->GetFurnitureMarkerData());
                            }
                            if (folNode != 0 && folNode->GetItem() != 0)
                            {
                                bed1 = 0;
                                if (folNode->GetItem()->IsActor())
                                {
                                    bed1 = (Actor*)folNode->GetItem();
                                }
                                folNode = folNode->GetNext();
                            }
                            else
                            {
                                bed1 = 0;
                            }
                        }
                        else
                        {
                            bed1 = 0;
                        }
                    }
                }
            }
        }
    }
    cell0 = &m_kObjectReferenceList;
    while (cell0 != 0 && !cell0->IsEmpty())
    {
        Actor* ti6 = 0;
        Actor* gren;
        gren = 0;
        Actor* primeObj;
        primeObj = (Actor*)cell0->GetItem();
        if (primeObj != 0)
        {
            if (!primeObj->IsStillLoading())
            {
                if ((cell0->GetItem())->IsActor())
                {
                    ti6 = (Actor*)cell0->GetItem();
                }
                else if ((cell0->GetItem())->IsProjectile())
                {
                    gren = (Actor*)cell0->GetItem();
                }
                BSSimpleList<TESObjectREFR*>* linkX = 0;
                ExtraFollower* blkE = 0;
                if (ti6 != 0)
                {
                    blkE = ((FUN_00422700_shell*)ti6->GetExtraData())->FUN_00422700();
                }
                if (!!blkE)
                {
                    linkX = blkE->pNext;
                }
                if (0 != gren)
                {
                    if (((InterfaceManager*)gren)->FUN_00874480() == arg1)
                    {
                        ((FUN_009707f0_shell*)gren)->FUN_009707f0(0);
                    }
                }
                while (0 != ti6)
                {
                    BaseProcess* s;
                    s = ti6->GetCurrentAIProcess();
                    if (((EffectSettingShell*)ti6)->GetLight() == (TESObjectLIGH*)arg1)
                    {
                        ((EffectSetting*)ti6)->SetLight((TESObjectLIGH*)0);
                        if (0 != s)
                        {
                            s->SetCombatAlerted(false);
                            s->ClearMovementStopped();
                        }
                    }
                    if (0 != s)
                    {
                        if ((unsigned int)n < 2)
                        {
                            s->SetActorDetectionLevel(arg1, (BaseProcess::DetectionListType)3);
                        }
                        s->ClearReferenceRecords((TESObjectREFR*)arg1);
                        Extra19* argCopy;
                        argCopy = ((Holder00420dd0*)ti6->GetExtraData())->GetExtraData(0x19);
                        if (0 != argCopy)
                        {
                            if (argCopy->p14 == arg1)
                            {
                                argCopy->p14 = 0;
                            }
                        }
                        if (((FUN_008a6650_shell*)ti6)->FUN_008a6650(0))
                        {
                            SandboxTargetInfo* copy2;
                            copy2 = ((ActorTargetSource*)ti6)->GetProcessTarget();
                            FUN_005e3fc0_shell* rr;
                            rr = 0;
                            if (copy2 != 0)
                            {
                                if (((FUN_0041ca90*)copy2)->get() == 0x16)
                                {
                                    rr = (FUN_005e3fc0_shell*)copy2;
                                }
                            }
                            if (rr != 0)
                            {
                                if (rr->FUN_005e3fc0() == arg1)
                                {
                                    ((FUN_00994ef0_Class*)rr)->Set(0);
                                }
                            }
                            ((FUN_008a6730_Actor*)ti6)->FUN_008a6730(arg1);
                        }
                        if (arg1->IsActor())
                        {
                            Actor* res = arg1;
                            if (ti6->GetCurrentAIProcess() != 0)
                            {
                                if (ti6->GetCurrentAIProcess()->GetCurrentMagicTarget() == (MagicTarget*)res)
                                {
                                    ti6->GetCurrentAIProcess()->SetMagicTarget(0);
                                }
                            }
                        }
                        if (s->GetProcessLevel() == 0)
                        {
                            s->AdvanceProcess();
                        }
                        if (((EffectSettingShell*)ti6)->GetLight() == (TESObjectLIGH*)arg1)
                        {
                            ((EffectSetting*)ti6)->SetLight((TESObjectLIGH*)0);
                        }
                        SandboxTargetInfo* idx = ((ActorTargetSource*)ti6)->GetProcessTarget();
                        if (idx != 0)
                        {
                            if (((ScriptGetText*)idx)->GetText() != 0)
                            {
                                if (((ScriptGetText*)idx)->GetText()->FUN_0067f390() == arg1)
                                {
                                    ((ScriptGetText*)idx)->GetText()->FUN_0067f3c0(0);
                                }
                            }
                        }
                        TESPackage* sel;
                        sel = s->GetCurrentPackage();
                        if (sel != 0)
                        {
                            if (((ScriptGetText*)sel)->GetText() != 0)
                            {
                                if (((ScriptGetText*)sel)->GetText()->FUN_0067f390() == arg1)
                                {
                                    ((ScriptGetText*)sel)->GetText()->FUN_0067f3c0(0);
                                }
                            }
                        }
                        void* B2 = ((ActorView*)ti6)->v428();
                        if (!!B2)
                        {
                            ((FUN_0097f9c0_shell*)B2)->FUN_0097f9c0(arg1);
                        }
                        if (s->GetTarget() == (TESObjectREFR*)arg1)
                        {
                            s->SetTarget(0);
                        }
                        if (((ActorView*)ti6)->v2c8() == arg1)
                        {
                            ((Host00881620*)ti6)->FUN_00881620(0);
                        }
                        TESPackage* pkgOnce = s->GetRunOncePackage();
                        if (((FUN_00881650_shell*)ti6)->FUN_00881650() == arg1 ||
                            (pkgOnce != 0 && ((ScriptGetText*)pkgOnce)->GetData() != 0 &&
                             ((FUN_00680020_shell*)((ScriptGetText*)pkgOnce)->GetData())->FUN_00680020() == arg1))
                        {
                            if (((FUN_009336c0_shell*)ti6)->FUN_009336c0())
                            {
                                ti6->Unk_A2();
                            }
                            else
                            {
                                if (((FUN_00674d40_shell*)((ActorTargetSource*)ti6)->GetProcessTarget())
                                        ->FUN_00674d40())
                                {
                                    ((FUN_00881680_shell*)ti6)->FUN_00881680(0);
                                }
                                else
                                {
                                    s->StopPackage();
                                    s->StopRunOncePackage();
                                }
                            }
                        }
                        s->SetCurrentTargetReference((TESObjectREFR*)arg1);
                        if (s->GetFurnitureReference() == (TESObjectREFR*)arg1)
                        {
                            ((FurnMarkShell*)s->GetFurnitureMarkerData())->FUN_00c54550(0.0f);
                            ((FurnMarkShell*)s->GetFurnitureMarkerData())->FUN_00568ab0(0);
                            ((FurnMarkShell*)s->GetFurnitureMarkerData())->FUN_0098ddd0(&DAT_011f426c);
                            s->SetFurnitureMarkerData(0, 0x7f, ti6->GetCurrentAIProcess()->GetFurnitureMarkerData());
                        }
                        if (linkX != 0 && linkX->GetItem() != 0)
                        {
                            ti6 = 0;
                            if (linkX->GetItem()->IsActor())
                            {
                                ti6 = (Actor*)linkX->GetItem();
                            }
                            linkX = linkX->GetNext();
                        }
                        else
                        {
                            ti6 = 0;
                        }
                    }
                    else
                    {
                        ti6 = 0;
                    }
                }
            }
        }
        cell0 = cell0->GetNext();
    }
}
}  // namespace fnv_0096f600

namespace fnv_009715c0 {
struct Mob9715
{
    virtual void m0();
};
struct Obj9715;
struct X9715
{
    bool FUN_00425fd0();
};
struct W9715
{
    X9715* FUN_008d6f30();
    int FUN_00575d70();
};
struct Z9715
{
    W9715* FUN_00559450();
};
struct Proc9715
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
    virtual void EnterCombatV(Obj9715*, Obj9715*, bool, bool, void*, bool, bool, bool, bool, bool, bool, bool, void*);
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual int GetNumV();
    virtual void ModNumV(int);
};
struct Obj9715 : Mob9715
{
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
    virtual bool IsActorV();
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
    virtual bool V193();
    X9715* FUN_008d6f30();
    int FUN_00575d70();
    bool FUN_00493bb0();
    float FUN_005723b0(void*, int, int);
    Proc9715* FUN_008d8520();
    Z9715* FUN_00568e50();
};
struct Node9715
{
    Obj9715** FUN_006815c0();
    Node9715* FUN_00726070();
};
struct G9715
{
    int* FUN_0043d4d0();
};
extern G9715 g_011cdbec;
extern Obj9715* DAT_011dea3c;
extern float DAT_01016970;
struct RetCls
{
    RetCls();
    int m_00;
    int m_04;
    void FUN_005ae3d0(Mob9715* const&);
};
struct Cont9715
{
    unsigned int FUN_005be5c0(int);
    Obj9715* FUN_00968670(unsigned int);
};
struct Cls9715
{
    int m_00;
    Cont9715 m_04;
    RetCls* CollectCombatTargets(Obj9715*, Node9715*);
};
// @fnv 0x009715c0
RetCls* Cls9715::CollectCombatTargets(Obj9715* arg1, Node9715* apNodeList)
{
    RetCls* acc = new RetCls();
    Obj9715* q = arg1;
    X9715* e2 = q->FUN_008d6f30();
    int num = q->FUN_00575d70();
    if (!q)
        return acc;
    int cnt = DAT_011dea3c->FUN_008d8520()->GetNumV();
    DAT_011dea3c->FUN_008d8520()->ModNumV((cnt - 1) * -1);
    Obj9715* sel = 0;
    unsigned int z = 0;
    for (; z < m_04.FUN_005be5c0(3); z++)
    {
        sel = m_04.FUN_00968670(z);
        if (sel)
        {
            Obj9715* ptr = 0;
            if (sel && sel->IsActorV())
                ptr = sel;
            float val = 3.402823466e38f;
            Node9715* index = 0;
            while (ptr)
            {
                X9715* cId = ptr->FUN_008d6f30();
                int cSec = ptr->FUN_00575d70();
                if (!ptr->FUN_00493bb0() && ptr->V193())
                {
                    if ((cId && cId->FUN_00425fd0() && cId == e2) ||
                        (num == cSec && ((cId && !cId->FUN_00425fd0()) || (e2 && !e2->FUN_00425fd0()))))
                    {
                        val = ptr->FUN_005723b0(q, 0, 0);
                        if (val <= *g_011cdbec.FUN_0043d4d0())
                        {
                            ptr->FUN_008d8520()->EnterCombatV(ptr, q, false, false, 0, false, false, false, false,
                                                              false, false, true, 0);
                            acc->FUN_005ae3d0(ptr);
                        }
                    }
                    else
                    {
                        Node9715* node = apNodeList;
                        while (node && *node->FUN_006815c0())
                        {
                            Obj9715* nodeVal = *node->FUN_006815c0();
                            if (nodeVal)
                            {
                                Z9715* obj48 = nodeVal->FUN_00568e50();
                                W9715* obj4c = 0;
                                if (obj48)
                                {
                                    obj4c = obj48->FUN_00559450();
                                    if (obj4c->FUN_008d6f30() == cId ||
                                        (obj4c->FUN_008d6f30() == 0 && obj4c->FUN_00575d70() == ptr->FUN_00575d70()))
                                    {
                                        val = ptr->FUN_005723b0(obj4c, 0, 0);
                                        if (val <= *g_011cdbec.FUN_0043d4d0())
                                        {
                                            ptr->FUN_008d8520()->EnterCombatV(ptr, q, false, false, 0, false, false,
                                                                              false, false, false, false, true, 0);
                                            acc->FUN_005ae3d0(ptr);
                                            break;
                                        }
                                    }
                                }
                            }
                            node = node->FUN_00726070();
                        }
                    }
                }
                if (index && *index->FUN_006815c0())
                {
                    ptr = 0;
                    if ((*index->FUN_006815c0())->IsActorV())
                        ptr = *index->FUN_006815c0();
                    index = index->FUN_00726070();
                }
                else
                {
                    ptr = 0;
                }
            }
        }
    }
    return acc;
}
}  // namespace fnv_009715c0

class Actor_ext : public Actor
{
  public:
    TESPackage* GetCurrentPackage();
};

class DialoguePackageStub : public TESPackage
{
  public:
    bool IsSpeakerTarget(TESObjectREFR* apTarget);
    void AddSpeaker(TESObjectREFR* apTarget, Actor* apActor);
};

class ActorRefArrayStub
{
  public:
    unsigned int GetCountOfType(int aiType);
    Actor* GetActorAt(unsigned int auiIndex);
};

class ActorQueryOwner
{
  public:
    int unk00;
    ActorRefArrayStub kActors;

    BSSimpleList<Actor*>* FindDialogueSpeakers(TESObjectREFR* apTarget, bool abAssign);
};

// Scans actors for a dialogue package whose speaker target matches apTarget; optionally adds them as speakers or collects them into a list.
// @fnv 0x009719e0
BSSimpleList<Actor*>* ActorQueryOwner::FindDialogueSpeakers(TESObjectREFR* apTarget, bool abAssign)
{
    BSSimpleList<Actor*>* pList = 0;
    Actor* pRef = 0;
    for (unsigned int i = 0; i < kActors.GetCountOfType(3); i++)
    {
        pRef = kActors.GetActorAt(i);
        if (pRef)
        {
            Actor_ext* pActor = 0;
            if (pRef->IsActor())
                pActor = (Actor_ext*)pRef;
            if (pActor)
            {
                DialoguePackageStub* pDialoguePackage = 0;
                TESPackage* pCurrentPackage = pActor->GetCurrentPackage();
                if (pCurrentPackage && pCurrentPackage->GetPackType() == 0x15)
                    pDialoguePackage = (DialoguePackageStub*)pCurrentPackage;
                if (pDialoguePackage && pDialoguePackage->IsSpeakerTarget(apTarget))
                {
                    if (!pList)
                        pList = new BSSimpleList<Actor*>;
                    if (abAssign)
                        pDialoguePackage->AddSpeaker(apTarget, pActor);
                    else
                        pList->AddHead(pActor);
                }
            }
        }
    }
    if (abAssign)
    {
        delete pList;
        pList = 0;
    }
    return pList;
}

struct FUN_009722e0_member
{
    BSSimpleList<Actor*>* GetActorList();
};

struct FUN_009722e0_shell
{
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
    BSSimpleList<FUN_009722e0_member*>* pList50;
    BSSimpleList<FUN_009722e0_member*>* pList54;
    bool IsActorInOtherList(Actor* pActor, FUN_009722e0_member* apBoundObject);
};

// @fnv 0x009722e0
bool FUN_009722e0_shell::IsActorInOtherList(Actor* pActor, FUN_009722e0_member* pExcludeMember)
{
    BSSimpleList<FUN_009722e0_member*>* pIter = pList50;
    bool bFound = false;
    while (pIter && !pIter->IsEmpty() && !bFound)
    {
        FUN_009722e0_member* pMember = pIter->GetItem();
        if (pMember != pExcludeMember && pMember->GetActorList() && pMember->GetActorList()->IsInList(pActor))
            bFound = true;
        pIter = pIter->GetNext();
    }
    if (!bFound)
    {
        BSSimpleList<FUN_009722e0_member*>* pIter2 = pList54;
        bool bFound2 = false;
        while (pIter2 && !pIter2->IsEmpty() && !bFound2)
        {
            FUN_009722e0_member* pMember2 = pIter2->GetItem();
            if (pMember2 != pExcludeMember && pMember2->GetActorList() && pMember2->GetActorList()->IsInList(pActor))
                bFound2 = true;
            pIter2 = pIter2->GetNext();
        }
    }
    return bFound;
}

namespace fnv_00972aa0 {
struct S_972aa0_Actor
{
    void FUN_0047eb90(int a);
};
struct S_972aa0_ActorNode
{
    bool FUN_008256d0();
    S_972aa0_Actor** FUN_006815c0();
    S_972aa0_ActorNode* FUN_00726070();
};
struct S_972aa0_Crime
{
    unsigned int FUN_0084e3a0();
    S_972aa0_ActorNode* GetField38();
};
struct S_972aa0_Node
{
    S_972aa0_Crime** FUN_006815c0();
    S_972aa0_Node* FUN_00726070();
};
struct S_972aa0_List
{
    void FUN_00905330(S_972aa0_Crime* const& crime);
};
struct S_972aa0_Lists
{
    bool IsActorInOtherList(S_972aa0_Actor* actor, S_972aa0_Crime* crime);
};
extern S_972aa0_Lists DAT_011e0e80;

struct S_972aa0_Owner
{
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
    S_972aa0_List* crimeLists[5];
    void RemoveCrimeById(unsigned int id);
};

// @fnv 0x00972aa0
void S_972aa0_Owner::RemoveCrimeById(unsigned int uiCrimeId)
{
    S_972aa0_List* list = 0;
    S_972aa0_Node* node = 0;
    for (int i = 0; i < 5; i++)
    {
        list = crimeLists[i];
        node = (S_972aa0_Node*)list;
        while (node && *node->FUN_006815c0())
        {
            S_972aa0_Crime* crime = *node->FUN_006815c0();
            if (crime->FUN_0084e3a0() == uiCrimeId)
            {
                S_972aa0_ActorNode* actors = crime->GetField38();
                while (actors && !actors->FUN_008256d0())
                {
                    S_972aa0_Actor* actor = *actors->FUN_006815c0();
                    if (!DAT_011e0e80.IsActorInOtherList(actor, crime))
                        actor->FUN_0047eb90(0);
                    actors = actors->FUN_00726070();
                }
                list->FUN_00905330(crime);
                node = (S_972aa0_Node*)list;
            }
            else
            {
                node = node->FUN_00726070();
            }
        }
    }
}
}  // namespace fnv_00972aa0

struct TempEffectCellAccess : public BSTempEffect
{
    TESObjectCELL* GetParentCell();
    void SetParentCell(TESObjectCELL* apCell);
};

struct ProcessListsCellAccess : public ProcessLists
{
    void FUN_009740a0(TESObjectCELL* apCell);
};

// Drops every temp effect / magic effect that belongs to apCell.
// Removes temp effects whose parent cell matches apCell from both lists, clears their parent cell and adds them to the garbage collector.
// @fnv 0x009740a0
void ProcessListsCellAccess::FUN_009740a0(TESObjectCELL* apCell)
{
    if (!m_kTemporaryEffectList.IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* pIter6 = &m_kTemporaryEffectList;
        BSSimpleList<NiPointer<BSTempEffect> >* pPrev = 0;
        while (pIter6 && !pIter6->IsEmpty())
        {
            TempEffectCellAccess* pEffect = static_cast<TempEffectCellAccess*>((BSTempEffect*)pIter6->GetItem());
            if (pEffect->GetParentCell() == apCell)
            {
                pEffect->SetParentCell(0);
                GarbageCollector::Add(pEffect);
                if (pPrev)
                {
                    pPrev->Remove(pEffect);
                    pIter6 = pPrev->GetNext();
                }
                else
                {
                    pIter6->RemoveHead();
                }
            }
            else
            {
                pPrev = pIter6;
                pIter6 = pIter6->GetNext();
            }
        }
    }
    if (!m_kTemporaryEffectList2.IsEmpty())
    {
        BSSimpleList<NiPointer<BSTempEffect> >* pMIter = &m_kTemporaryEffectList2;
        BSSimpleList<NiPointer<BSTempEffect> >* aPMPrev = 0;
        while (pMIter && !pMIter->IsEmpty())
        {
            TempEffectCellAccess* pMEffect = static_cast<TempEffectCellAccess*>((BSTempEffect*)pMIter->GetItem());
            if (pMEffect->GetParentCell() == apCell)
            {
                pMEffect->SetParentCell(0);
                GarbageCollector::Add(pMEffect);
                if (aPMPrev)
                {
                    aPMPrev->Remove(pMEffect);
                    pMIter = aPMPrev->GetNext();
                }
                else
                {
                    pMIter->RemoveHead();
                }
            }
            else
            {
                aPMPrev = pMIter;
                pMIter = pMIter->GetNext();
            }
        }
    }
}

struct EffectThreadSetting
{
    unsigned char* Bool();
};
extern EffectThreadSetting g_011f127c;
struct EffectListCount
{
    unsigned int CountReferencedNodes();
};
struct EffectUpdate
{
    BSTempEffect* effect;
    float delta;
    unsigned char global;
    unsigned char finished;
};
struct FUN_00978c50
{
    void* vtable;
    EffectUpdate* buffer;
    unsigned int size;
    unsigned int capacity;
    void* allocator;
    FUN_00978c50();
    ~FUN_00978c50();
    unsigned int FUN_00978bc0();
    EffectUpdate& FUN_006a1440(unsigned int);
    unsigned int GetSize();
    EffectUpdate& FUN_006a7af0(int);
};
struct EffectParallelTask
{
    void* function;
    void* data;
    unsigned int size;
    unsigned int index;
    EffectParallelTask(void(__cdecl*)(BSSimpleArray<ParentSpaceNode, 1024>*, int), void*, unsigned int);
};
struct EffectProcessLists : ProcessLists
{
    void FUN_00974420(float);
    void FUN_009746c0(float);
};
// @fnv 0x009746c0
void EffectProcessLists::FUN_009746c0(float delta)
{
    if (!*g_011f127c.Bool())
    {
        FUN_00974420(delta);
        return;
    }
    unsigned int count = ((EffectListCount*)&m_kTemporaryEffectList)->CountReferencedNodes() +
                         ((EffectListCount*)&m_kTemporaryEffectList2)->CountReferencedNodes();
    if (count)
    {
        FUN_00978c50 updateBuffer;
        BSSimpleList<NiPointer<BSTempEffect> >* node = &m_kTemporaryEffectList;
        while (node)
        {
            BSTempEffect* effect = node->GetItem();
            if (effect)
            {
                unsigned int slot = updateBuffer.FUN_00978bc0();
                updateBuffer.FUN_006a1440(slot).effect = effect;
                updateBuffer.FUN_006a1440(slot).delta = delta;
                updateBuffer.FUN_006a1440(slot).global = 1;
                updateBuffer.FUN_006a1440(slot).finished = 0;
            }
            node = node->GetNext();
        }
        node = &m_kTemporaryEffectList2;
        while (node)
        {
            BSTempEffect* effect = node->GetItem();
            if (effect)
            {
                unsigned int slot = updateBuffer.FUN_00978bc0();
                updateBuffer.FUN_006a1440(slot).effect = effect;
                updateBuffer.FUN_006a1440(slot).delta = delta;
                updateBuffer.FUN_006a1440(slot).global = 0;
                updateBuffer.FUN_006a1440(slot).finished = 0;
            }
            node = node->GetNext();
        }
        if (updateBuffer.GetSize())
        {
            EffectParallelTask parallelTask(MarkNodeIfCheckFails, &updateBuffer, updateBuffer.GetSize());
            DAT_01202df4->FUN_00c44c90(&parallelTask);
            for (unsigned int i = 0; i < updateBuffer.GetSize(); i++)
            {
                EffectUpdate& update = updateBuffer.FUN_006a7af0(i);
                if (update.finished)
                {
                    GarbageCollector::Add(update.effect);
                    if (update.global)
                    {
                        NiPointer<BSTempEffect> effectToRemove(update.effect);
                        m_kTemporaryEffectList.Remove(effectToRemove);
                    }
                    else
                    {
                        NiPointer<BSTempEffect> effectToRemove(update.effect);
                        m_kTemporaryEffectList2.Remove(effectToRemove);
                    }
                }
            }
        }
    }
}

class ProjectileBaseStub
{
  public:
    bool GetHasExplosionAltTrigger() const;
    bool GetHasExplosionDetonates() const;
};

class ProjectileExt : public Projectile
{
  public:
    ProjectileBaseStub* GetProjectileBase() const;
    void Detonate();
};

class MagicProjectile : public Projectile
{
};

class ArrowProjectile : public Projectile
{
};

struct ProcessListsShell : public ProcessLists
{
    void FUN_00975160();
};

// @fnv 0x00975160
void ProcessListsShell::FUN_00975160()
{
    MobileObject* pObject = 0;
    for (unsigned int i = 0; i < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_HIGH); i++)
    {
        pObject = m_kMobileObjectProcessList.GetItem(i);
        MagicProjectile* pMagic = dynamic_cast<MagicProjectile*>(pObject);
        if (pMagic)
        {
            pMagic->MarkForDeletion(true);
        }
        else
        {
            ArrowProjectile* pArrow = dynamic_cast<ArrowProjectile*>(pObject);
            if (pArrow)
            {
                pArrow->MarkForDeletion(true);
            }
            else
            {
                ProjectileExt* pProjectile = static_cast<ProjectileExt*>(dynamic_cast<Projectile*>(pObject));
                if (pProjectile)
                {
                    if (!pProjectile->GetProjectileBase() ||
                        (!pProjectile->GetProjectileBase()->GetHasExplosionAltTrigger() &&
                         !pProjectile->GetProjectileBase()->GetHasExplosionDetonates()))
                    {
                        pProjectile->Detonate();
                    }
                }
            }
        }
    }
    for (unsigned int j = m_kMobileObjectProcessList.GetHead(PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH);
         j < m_kMobileObjectProcessList.GetTail(PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH); j++)
    {
        pObject = m_kMobileObjectProcessList.GetItem(j);
        ArrowProjectile* pArrow2 = dynamic_cast<ArrowProjectile*>(pObject);
        if (pArrow2)
        {
            pArrow2->MarkForDeletion(true);
        }
    }
}

struct FUN_008f25e0
{
    ~FUN_008f25e0();
    TESForm* FUN_0084e3a0();
    TESForm* FUN_0044ddc0();
    void FUN_009eba00(Actor*);
};
struct CrimeListView
{
    bool FUN_008256d0();
    FUN_008f25e0** FUN_006815c0();
    CrimeListView* FUN_00726070();
    void FUN_00905330(FUN_008f25e0* const&);
    void FUN_0063f7b0();
};
struct CrimeProcess : ProcessLists
{
    void FUN_00975320(TESForm*);
};
// @fnv 0x00975320
void CrimeProcess::FUN_00975320(TESForm* form)
{
    for (int i = 0; i < 5; ++i)
    {
        CrimeListView* current = reinterpret_cast<CrimeListView*>(m_pkCrimeLists[i]);
        CrimeListView* previous = 0;
        while (current && !current->FUN_008256d0())
        {
            FUN_008f25e0* removed = *current->FUN_006815c0();
            bool crime = false;
            if (removed->FUN_0084e3a0() == form || removed->FUN_0044ddc0() == form)
            {
                if (previous)
                {
                    previous->FUN_00905330(removed);
                    current = previous->FUN_00726070();
                }
                else
                    current->FUN_0063f7b0();
                delete removed;
                crime = true;
            }
            else if (form->IsActor())
            {
                Actor* actor = static_cast<Actor*>(form);
                removed->FUN_009eba00(actor);
            }
            if (!crime)
            {
                previous = current;
                current = current->FUN_00726070();
            }
        }
    }
}

struct SaveProcessLists : ProcessLists
{
    unsigned int FUN_009755b0();
};
// @fnv 0x009755b0
unsigned int SaveProcessLists::FUN_009755b0()
{
    BSSimpleList<NiPointer<BSTempEffect> >* list;
    unsigned int size = 0;
    size += 2;
    list = &m_kTemporaryEffectList;
    while (list && !list->IsEmpty())
    {
        BSTempEffect* effect = list->GetItem();
        if (effect->IsSaveable())
        {
            size += 1;
            size += (unsigned short)effect->GetSaveSize();
        }
        list = list->GetNext();
    }
    list = &m_kTemporaryEffectList2;
    while (list && !list->IsEmpty())
    {
        BSTempEffect* effect = list->GetItem();
        if (effect->IsSaveable())
        {
            size += 1;
            size += (unsigned short)effect->GetSaveSize();
        }
        list = list->GetNext();
    }
    return size;
}

extern bool _s_bAllowDetach;

class TES
{
  public:
    bool FUN_004511e0(TESObjectCELL* pCell, bool bArg);
    void ProcessItemNodes();
};
extern TES* g_TES;

class ModelLoader
{
  public:
    bool FUN_00445750(Actor* pActor);
};
extern ModelLoader* g_modelLoader;

struct TESObjectCELLSub : public TESObjectCELL
{
    void AddReference(TESObjectREFR* pRef, bool bArg);
};

struct ProcessListsSub : public ProcessLists
{
    void FUN_00972d30();
    void UpdateActor3D();
};

// @fnv 0x00975d10
void ProcessListsSub::UpdateActor3D()
{
    if (_s_bAllowDetach)
    {
        return;
    }

    MobileObject* pObj = NULL;
    for (unsigned int i = 0; i < m_kMobileObjectProcessList.GetSize(); i++)
    {
        pObj = m_kMobileObjectProcessList.GetItem(i);
        Actor* pActor = NULL;
        if (pObj && pObj->IsActor())
        {
            pActor = (Actor*)pObj;
        }

        if (pActor)
        {
            if (pActor->GetNiNode() &&
                (!pActor->GetParentCell() || !g_TES->FUN_004511e0(pActor->GetParentCell(), false)))
            {
                pActor->Set3D(NULL, false);
            }
            else if (!pActor->GetNiNode() && !g_modelLoader->FUN_00445750(pActor) && !pActor->GetDisabled() &&
                     !pActor->GetDeleted())
            {
                if (pActor->GetParentCell() && g_TES->FUN_004511e0(pActor->GetParentCell(), true))
                {
                    ((TESObjectCELLSub*)pActor->GetParentCell())->AddReference(pActor, false);
                    i = 0;
                }
            }
        }
    }

    g_TES->ProcessItemNodes();
    FUN_00972d30();
}

struct Actor976030 : Actor
{
    bool FUN_00565450();
    const char* FUN_005715d0();
};
int __cdecl FUN_00404dc0(const char*, const char*);
struct Lists976030
{
    int unk00;
    Array_973590 processes;
    void FUN_00976030(int mode);
};
// @fnv 0x00976030
void Lists976030::FUN_00976030(int mode)
{
    BSSimpleList<Actor*>* i = new BSSimpleList<Actor*>;  // Nearby actors.
    BSSimpleList<Actor*>* h = new BSSimpleList<Actor*>;  // Distant actors.
    Actor976030* p = 0;                                  // Current actor.
    Actor976030* a = 0;                                  // Nearby actor with a potentially matching name.
    MobileObject* s = 0;
    for (unsigned int f = 0; f < processes.FUN_005be5c0(0); f++)
    {
        s = processes.FUN_00968670(f);
        p = 0;
        if (s && s->IsActor())
            p = (Actor976030*)s;
        if (p && !((Actor976030*)p)->FUN_00565450())
        {
            if (mode != 2)
            {
                if (((FUN_005723b0_Obj*)p)->FUN_005723b0(DAT_011dea3c, 0, 0) > 3000.0)
                    h->AddHead((Actor*)p);
                else
                    i->AddHead((Actor*)p);
            }
            else
            {
                DAT_011f11a0.Lock(0);
                delete p;
                DAT_011f11a0.Unlock();
                f = 0;
            }
        }
    }
    if (mode == 1)
    {
        BSSimpleList<Actor*>* q = 0;  // Iterator over nearby actors.
        BSSimpleList<Actor*>* b = 0;  // Selected list.
        bool ba = false;              // Selected the nearby list.
        if (h->IsEmpty())
        {
            b = i;
            ba = true;
        }
        else
            b = h;
        while (b && b->GetItem())
        {
            p = (Actor976030*)b->GetItem();
            if (p->Unk_87() && !ba)
            {
                q = i;
                while (q && q->GetItem())
                {
                    a = (Actor976030*)q->GetItem();
                    if (!FUN_00404dc0(((Actor976030*)a)->FUN_005715d0(), ((Actor976030*)p)->FUN_005715d0()))
                    {
                        i->Remove((Actor*)a);
                        q->Remove((Actor*)a);
                        q = i;
                        DAT_011f11a0.Lock(0);
                        delete a;
                        DAT_011f11a0.Unlock();
                    }
                    else
                        q = q->GetNext();
                }
            }
            b->RemoveHead();
            DAT_011f11a0.Lock(0);
            delete p;
            DAT_011f11a0.Unlock();
        }
    }
    else if (mode == 0)
    {
        while (h && h->GetItem())
        {
            p = (Actor976030*)h->GetItem();
            h->RemoveHead();
            DAT_011f11a0.Lock(0);
            delete p;
            DAT_011f11a0.Unlock();
        }
    }
    h->RemoveAll();
    delete h;
    i->RemoveAll();
}

struct DetectionSetting
{
    SETTING_VALUE* FUN_00403e20();
};
extern DetectionSetting g_011d0bb4;
extern DetectionSetting g_011d04b4;
struct DetectionActor : public MobileObject
{
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
    virtual int FUN_D1(PlayerCharacter*, bool);
    bool FUN_00440da0();
    BaseProcess* FUN_008d8520();
    bool FUN_008bc700(PlayerCharacter*);
    bool IsHostileTo(PlayerCharacter*, bool, unsigned int*, bool);
};
struct DetectionProcessArray
{
    unsigned int FUN_005be5c0(int);
};
struct DetectionList : public ProcessLists
{
    bool HasNearbyDetectedActor(bool differentDistance);
};
// @fnv 0x009764a0
bool DetectionList::HasNearbyDetectedActor(bool differentDistance)
{
    float threshold3 = g_011d0bb4.FUN_00403e20()->f;
    bool found7 = false;
    if (differentDistance)
    {
        threshold3 = g_011d04b4.FUN_00403e20()->f;
    }
    float distance8 = 0.0f;
    DetectionActor* actor = 0;
    unsigned int index2 = 0;
    for (; !found7 && index2 < reinterpret_cast<DetectionProcessArray*>(&m_kMobileObjectProcessList)->FUN_005be5c0(0);
         ++index2)
    {
        actor = reinterpret_cast<DetectionActor*>(m_kMobileObjectProcessList.GetItem(index2));
        DetectionActor* current = 0;
        if (actor && actor->IsActor())
        {
            current = actor;
        }
        if (current && current != reinterpret_cast<DetectionActor*>(pPlayer) && !current->IsDead(false) &&
            !current->FUN_00440da0())
        {
            if (current->FUN_008d8520() && current->FUN_008d8520()->GetCurrentTalkTarget())
            {
                current = reinterpret_cast<DetectionActor*>(current->FUN_008d8520()->GetCurrentTalkTarget());
            }
            distance8 = reinterpret_cast<FUN_00973de0_player*>(pPlayer)->GetDistanceToReference(current, false, false);
            if (distance8 <= threshold3)
            {
                int result = current->FUN_D1(pPlayer, false);
                unsigned int state2 = 0;
                if (current->FUN_008bc700(pPlayer))
                {
                    found7 = true;
                }
                else if (current->IsHostileTo(pPlayer, false, &state2, false))
                {
                    found7 = true;
                }
            }
        }
    }
    return found7;
}

// Remove (and delete) every list entry whose level equals the given level.

class F8660Entry
{
  public:
    ~F8660Entry();
    unsigned int GetLevel();
};

class F8660Node
{
  public:
    bool IsEmpty();
    F8660Entry** GetItem();
    F8660Node* GetNext();
};

class F8660List : public F8660Node
{
  public:
    void Remove(F8660Entry*& rpkEntry);
};

class F8660Owner
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
    F8660List m_kEntries;

    void FUN_00978660(unsigned int uiTreeBlockIndex);
};

// Walks m_kEntries and removes and deletes every entry whose GetLevel() equals the given level.
// @fnv 0x00978660
void F8660Owner::FUN_00978660(unsigned int uiTreeBlockIndex)
{
    if (!m_kEntries.IsEmpty())
    {
        F8660Node* pkNode = &m_kEntries;
        bool bAtHead = true;
        while (pkNode)
        {
            F8660Entry* pkEntry = *pkNode->GetItem();
            if (!bAtHead)
                pkNode = pkNode->GetNext();

            bool bRemoved = false;
            if (pkEntry && pkEntry->GetLevel() == uiTreeBlockIndex)
            {
                m_kEntries.Remove(pkEntry);
                delete pkEntry;
                bRemoved = true;
            }

            if (!bRemoved && bAtHead)
            {
                pkNode = pkNode->GetNext();
                bAtHead = false;
            }
        }
    }
}

struct MuzzleOwnerRef
{
    void* GetFlashSource();
    int GetFlashStamp();
};
struct MuzzleProjectileRef
{
    void SetMuzzleFlashSpawned(bool);
};
struct MuzzleFlashEx : public MuzzleFlash
{
    MuzzleFlashEx(MuzzleOwnerRef* parent, MuzzleProjectileRef* projectile);
    void* GetSource();
    int GetStamp();
    MuzzleProjectileRef* GetProjectileRef();
    void Activate();
};

struct FUN_00978740_shell : public ProcessLists
{
    void ActivateMuzzleFlash(MuzzleOwnerRef* parent, MuzzleProjectileRef* projectile);
};

// Finds an existing muzzle flash matching the parent's source and stamp and the projectile, creates and registers one if none exists, then activates it.
// @fnv 0x00978740
void FUN_00978740_shell::ActivateMuzzleFlash(MuzzleOwnerRef* pOwner, MuzzleProjectileRef* projectile)
{
    if (projectile && pOwner)
    {
        MuzzleFlash* pFlash = 0;
        BSSimpleList<MuzzleFlash*>* pIter = &m_kMuzzleFlashList;
        while (!pFlash && pIter && !pIter->IsEmpty())
        {
            MuzzleFlash* flash = pIter->GetItem();
            if (flash && ((MuzzleFlashEx*)flash)->GetSource() == pOwner->GetFlashSource() &&
                ((MuzzleFlashEx*)flash)->GetStamp() == pOwner->GetFlashStamp() &&
                ((MuzzleFlashEx*)flash)->GetProjectileRef() == projectile)
            {
                pFlash = flash;
            }
            pIter = pIter->GetNext();
        }
        if (!pFlash)
        {
            pFlash = new MuzzleFlashEx(pOwner, projectile);
            projectile->SetMuzzleFlashSpawned(true);
            m_kMuzzleFlashList.AddHead(pFlash);
        }
        if (pFlash)
        {
            ((MuzzleFlashEx*)pFlash)->Activate();
        }
    }
}

namespace fnv_009723f0 {
class CrimeFull
{
  public:
    ~CrimeFull();
    bool FUN_009eb8a0();
    void FUN_009eba30();
};

class ProcessListsEx : public ProcessLists
{
  public:
    void UpdateCrimeLists();
};

// @fnv 0x009723f0
void ProcessListsEx::UpdateCrimeLists()
{
    BSSimpleList<CrimeFull*>* p = 0;
    BSSimpleList<CrimeFull*>* t = 0;
    for (int i = 0; i < 5; i++)
    {
        p = (BSSimpleList<CrimeFull*>*)m_pkCrimeLists[i];
        t = p;
        while (t != 0 && t->GetItem() != 0)
        {
            CrimeFull* x = t->GetItem();
            if (x->FUN_009eb8a0())
            {
                x->FUN_009eba30();
                p->Remove(x);
                delete x;
                t = p;
            }
            else
            {
                t = t->GetNext();
            }
        }
    }
    m_fCrimeListUpdateTimer = (float)m_iMobileObjectCount + 10.0;
}
}  // namespace fnv_009723f0

namespace fnv_0096dcb0 {
extern "C" char DAT_011dea3c;
extern "C" char DAT_011de7b8;
struct State96
{
    int FUN_0041ca90();
};
struct Actor96;
struct Slots64
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
};
struct ProcOwner96 : Slots64
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual Actor96* owner();
};
struct Proc96 : ProcOwner96
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void c56();
    virtual void c57();
    virtual void c58();
    virtual void c59();
    virtual void c60();
    virtual void c61();
    virtual void c62();
    virtual void c63();
    virtual State96* state();
    float FUN_007df1f0();
};
struct ActorValid96 : Slots64
{
    virtual bool valid();
};
struct Actor96 : ActorValid96
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual void b57();
    virtual void b58();
    virtual void b59();
    virtual void b60();
    virtual void b61();
    virtual void b62();
    virtual void b63();
    virtual void b64();
    virtual void b65();
    virtual void b66();
    virtual void b67();
    virtual void b68();
    virtual void b69();
    virtual void b70();
    virtual void b71();
    virtual void b72();
    virtual void b73();
    virtual void b74();
    virtual void b75();
    virtual void b76();
    virtual void b77();
    virtual void b78();
    virtual void b79();
    virtual void b80();
    virtual void b81();
    virtual void b82();
    virtual void b83();
    virtual void b84();
    virtual void b85();
    virtual void update(float);
    Proc96* FUN_008d8520();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_00493bb0();
    bool FUN_008842c0();
};
struct Clock96
{
    float FUN_00867da0();
};
struct FUN_0096a2d0
{
    char data[8];
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    Actor96** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_005ae3d0(Actor96**);
    void FUN_0063f7b0();
    void FUN_00470470();
    void* FUN_004702f0(unsigned);
};
struct Owner96
{
    void UpdateActorsFromList(FUN_0096a2d0*);
};
// Collects valid actors from a linked list, then updates each eligible actor with its elapsed time since the last update.
// @fnv 0x0096dcb0
void Owner96::UpdateActorsFromList(FUN_0096a2d0* pInputList)
{
    FUN_0096a2d0* list3 = new FUN_0096a2d0;
    while (pInputList && *pInputList->FUN_006815c0())
    {
        if ((*pInputList->FUN_006815c0())->valid())
            list3->FUN_005ae3d0(pInputList->FUN_006815c0());
        pInputList = pInputList->FUN_00726070();
    }
    while (list3 && *list3->FUN_006815c0())
    {
        Actor96* actor2 = *list3->FUN_006815c0();
        if (actor2 && actor2 != *(Actor96**)&DAT_011dea3c && actor2->FUN_008d8520() && !actor2->FUN_00440d80() &&
            !actor2->FUN_00440da0() && !actor2->FUN_00493bb0())
        {
            float last = actor2->FUN_008d8520()->FUN_007df1f0();
            float now = ((Clock96*)&DAT_011de7b8)->FUN_00867da0();
            float elapsed3 = now - last;
            if (now < last)
                elapsed3 = now + 24.0 - last;
            bool special2 = false;
            if (elapsed3 < 0.05)
                elapsed3 = 0.0f;
            if (actor2->FUN_008d8520()->state() && actor2->FUN_008d8520()->state()->FUN_0041ca90() == 2)
                special2 = true;
            if ((!special2 && !actor2->FUN_008842c0()) || actor2->FUN_008d8520()->owner() != *(Actor96**)&DAT_011dea3c)
                actor2->update(elapsed3);
        }
        list3->FUN_0063f7b0();
    }
    list3->FUN_00470470();
    delete list3;
}
}  // namespace fnv_0096dcb0

template <int N> struct Slot970
{
};
template <int N> struct ProcessSlots970 : ProcessSlots970<N - 1>
{
    virtual void pad(Slot970<N>*);
};
template <> struct ProcessSlots970<0>
{
};
template <> struct ProcessSlots970<211> : ProcessSlots970<210>
{
    virtual void SetCount(int);
};
struct Process970 : ProcessSlots970<368>
{
    virtual int GetCount();
};
template <int N> struct ActorSlots970 : ActorSlots970<N - 1>
{
    virtual void pad(Slot970<N>*);
};
template <> struct ActorSlots970<0>
{
};
template <> struct ActorSlots970<65> : ActorSlots970<64>
{
    virtual bool IsActor();
};
template <> struct ActorSlots970<140> : ActorSlots970<139>
{
    virtual bool Check(int);
};
struct Actor970 : ActorSlots970<141>
{
    virtual bool Check2();
    bool FUN_00440da0();
    bool FUN_00440d80();
    char FUN_00437bd0();
    Process970* FUN_008d8520();
    int FUN_008a0d10(int, Actor970*, bool*, int, int, int, int);
};
struct Input970
{
    Actor970* FUN_0084e3a0();
};
struct List970
{
    int x[2];
    List970();
    unsigned FUN_005ae380();
    void FUN_005ae3d0(Actor970**);
    void SortItems(void*);
};
struct Array970
{
    unsigned FUN_005be5c0(int);
    Actor970* FUN_00968670(unsigned);
};
extern "C" char DAT_00970ee0;
struct C970
{
    int unused;
    Array970 array;
    List970* CollectActorsByPackage(Actor970*, int, int);
    List970* FUN_00970f60(Input970* input);
};
// @fnv 0x00970f60
List970* C970::FUN_00970f60(Input970* input)
{
    List970* result9 = 0;
    Actor970* actor = input->FUN_0084e3a0();
    if (actor && (actor->FUN_00440da0() || actor->FUN_00440d80() || actor->Check(1)))
        return 0;
    int count4 = 0;
    if (actor)
        count4 = actor->FUN_008d8520()->GetCount();
    if (count4 > 0)
    {
        List970* list = CollectActorsByPackage(actor, 21, 0);
        if (list)
            count4 = list->FUN_005ae380();
        else
            count4 = 0;
        actor->FUN_008d8520()->SetCount(count4);
    }
    Actor970* entry3 = 0;
    for (unsigned index2 = 0; index2 < array.FUN_005be5c0(0); ++index2)
    {
        Actor970* other5 = 0;
        entry3 = array.FUN_00968670(index2);
        if (entry3 && entry3->IsActor())
            other5 = entry3;
        bool flag;
        if (other5 && !(unsigned char)other5->FUN_00437bd0() && !other5->Check2() && other5 != actor &&
            !other5->Check(0) && !other5->FUN_00440da0())
        {
            if (other5->FUN_008a0d10(0, actor, &flag, 0, 0, 0, 0) > 0)
            {
                if (!result9)
                    result9 = new List970;
                result9->FUN_005ae3d0((Actor970**)&(Actor970* const&)(other5 + 0));
            }
        }
    }
    if (result9)
        result9->SortItems(&DAT_00970ee0);
    return result9;
}

struct ZPack
{
    int FUN_0041ca90();
    int FUN_004030b0();
    bool FUN_0097fa10(int);
};
struct ZProc
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
    virtual int Pack();
};
struct ZAct
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
    virtual bool IsActor();
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
    virtual bool Check();
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
    virtual bool Check2();
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void Disable(int);
    bool FUN_00493bb0();
    ZPack* FUN_00881510();
    ZPack* FUN_009344a0();
    ZProc* FUN_008d8520();
    bool FUN_005653d0();
};
struct ZArray
{
    unsigned int FUN_005be5c0(int);
    unsigned int FUN_005de0f0(int);
    ZAct* FUN_00968670(unsigned int);
};
struct ZOwner
{
    int unk00;
    ZArray unk04;
    BSSimpleList<Actor*>* CollectActorsByPackage(int, int, bool);
};
// @fnv 0x00971c30
BSSimpleList<Actor*>* ZOwner::CollectActorsByPackage(int arg1, int arg2, bool arg3)
{
    BSSimpleList<Actor*>* result2 = 0;
    ZAct* obj2 = 0;
    bool special5 = false;
    for (unsigned int index3 = 0; index3 < unk04.FUN_005be5c0(3); index3++)
    {
        obj2 = unk04.FUN_00968670(index3);
        if (obj2 && (!arg3 || index3 < unk04.FUN_005be5c0(0)))
        {
            if (index3 >= unk04.FUN_005de0f0(2) && index3 < unk04.FUN_005be5c0(2))
                special5 = true;
            else
                special5 = false;
            ZAct* actor = 0;
            if (obj2->IsActor())
                actor = obj2;
            if (actor)
            {
                if (actor->FUN_00493bb0() && arg2 == 18)
                {
                    ZPack* package4 = actor->FUN_00881510();
                    ZPack* valid = 0;
                    if (package4 && package4->FUN_0041ca90() == 18)
                        valid = package4;
                    if (arg3 && valid)
                    {
                        if (valid->FUN_004030b0() == arg1)
                        {
                            if (!result2)
                                result2 = new BSSimpleList<Actor*>;
                            if (special5 && (actor->Check() || !actor->FUN_005653d0()))
                                actor->Disable(0);
                            else
                            {
                                result2->AddHead((Actor*)actor);
                            }
                        }
                    }
                    else if (valid && valid->FUN_0097fa10(arg1))
                    {
                        if (!result2)
                            result2 = new BSSimpleList<Actor*>;
                        if (special5 && (actor->Check() || !actor->FUN_005653d0()))
                            actor->Disable(0);
                        else
                        {
                            result2->AddHead((Actor*)actor);
                        }
                    }
                }
                else
                {
                    ZPack* _current = actor->FUN_009344a0();
                    if (_current && (actor->Check2() || arg2 != 21))
                    {
                        if (actor->FUN_008d8520()->Pack() == arg1 && _current->FUN_0041ca90() == arg2)
                        {
                            if (!result2)
                                result2 = new BSSimpleList<Actor*>;
                            result2->AddHead((Actor*)actor);
                        }
                    }
                }
            }
        }
    }
    return result2;
}

struct CombatActor;
struct FactionView;
struct ProcessView
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void Reset(bool);
};
struct TargetData
{
    CombatActor* Target();
};
struct PackageView
{
    TargetData* Data();
};
struct FactionView
{
    bool Enemy() const;
    void SetEnemy(bool);
};
struct FactionChanges
{
    int unk00;
    int unk04;
    int unk08;
    void* list;
};
struct ExtraView
{
    void Clear(CombatActor*);
    FactionChanges* Changes();
};
struct BaseFactionView
{
    void* List();
};
struct ActorBaseView
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
    BaseFactionView factions;
};
struct CombatActor
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
    virtual bool IsActor();
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
    virtual bool HasFactions();
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void StopTarget(CombatActor*);
    bool HasTarget(CombatActor*);
    bool HasPackage();
    PackageView* Package();
    void Stop(int);
    ProcessView* Process();
    void Reset();
    ExtraView* Extra();
    ActorBaseView* Base();
    unsigned Gather(FactionView**, unsigned, void*, void*);
};
struct ActorArrayView
{
    unsigned Begin(int);
    unsigned End(int);
    CombatActor* At(unsigned);
};
struct ListsView
{
    ActorArrayView* Array();
    void FUN_00972840(CombatActor*, bool);
};
extern ListsView combatLists;
extern CombatActor* playerActor;
// @fnv 0x00972840
void ListsView::FUN_00972840(CombatActor* target, bool skip)
{
    ActorArrayView* actorsB = combatLists.Array();
    for (unsigned index4 = actorsB->Begin(0); index4 < actorsB->End(3); ++index4)
    {
        CombatActor* entryB = actorsB->At(index4);
        CombatActor* actor = 0;
        if (entryB && entryB->IsActor())
            actor = entryB;
        if (actor)
        {
            if (actor->HasTarget(target))
                actor->StopTarget(target);
            else if (actor && !skip && actor->HasPackage() && actor->Package()->Data() &&
                     (actor->Package()->Data()->Target() == target || !target))
            {
                actor->Stop(0);
                actor->Process()->Reset(true);
            }
            if (target == playerActor)
            {
                actor->Reset();
                actor->Extra()->Clear(actor);
                if (actor->HasFactions())
                {
                    void* baseListTmp = actor->Base()->factions.List();
                    FactionChanges* changes = actor->Extra()->Changes();
                    FactionView* aFactions[128];
                    unsigned count7 = actor->Gather(aFactions, 128, baseListTmp, changes ? changes->list : 0);
                    for (unsigned factionIndex4 = 0; factionIndex4 < count7; ++factionIndex4)
                    {
                        if (!aFactions[factionIndex4])
                            continue;
                        if (aFactions[factionIndex4]->Enemy())
                            aFactions[factionIndex4]->SetEnemy(false);
                    }
                }
            }
        }
    }
}

struct CombatController9734
{
    Actor* FUN_004030b0();
    bool FUN_009818b0();
};

// Actor's primary vtable seen through MobileObject; slot 266 returns the combat controller
class ActorView9734 : public MobileObject
{
  public:
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual void V216();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void V233();
    virtual void V234();
    virtual void V235();
    virtual void V236();
    virtual void V237();
    virtual void V238();
    virtual void V239();
    virtual void V240();
    virtual void V241();
    virtual void V242();
    virtual void V243();
    virtual void V244();
    virtual void V245();
    virtual void V246();
    virtual void V247();
    virtual void V248();
    virtual void V249();
    virtual void V250();
    virtual void V251();
    virtual void V252();
    virtual void V253();
    virtual void V254();
    virtual void V255();
    virtual void V256();
    virtual void V257();
    virtual void V258();
    virtual void V259();
    virtual void V260();
    virtual void V261();
    virtual void V262();
    virtual void V263();
    virtual void V264();
    virtual void V265();
    virtual CombatController9734* GetCombatController();
};

class Actor9734 : public Actor
{
  public:
    int FUN_008a81e0(Actor* pkTarget);
    bool FUN_00493bb0();
};

struct ActorArray9734
{
    unsigned int FUN_005be5c0(int iUnused);
    TESObjectREFR* FUN_00968670(unsigned int uiIndex);
};

struct ActorGroup9734
{
    int m_iUnk00;
    ActorArray9734 kActors;
    bool FUN_00973460(Actor* pkTarget);
};

// Scans the group's actors and returns true if a character actor targeting pkTarget is not engaged in combat with it.
// @fnv 0x00973460
bool ActorGroup9734::FUN_00973460(Actor* pkTarget)
{
    bool bFound = false;
    TESObjectREFR* pkMember = 0;
    Actor9734* pkActor = 0;
    for (unsigned int i = 0; i < kActors.FUN_005be5c0(0) && !bFound; ++i)
    {
        pkMember = kActors.FUN_00968670(i);
        if (pkMember && pkMember->IsActor())
            pkActor = (Actor9734*)pkMember;
        if (pkActor && pkActor->IsCharacter() && pkActor->FUN_008a81e0(pkTarget) == 3)
        {
            if (!pkActor->FUN_00493bb0() || !((ActorView9734*)pkActor)->GetCombatController() ||
                ((ActorView9734*)pkActor)->GetCombatController()->FUN_004030b0() != pkTarget ||
                !((ActorView9734*)pkActor)->GetCombatController()->FUN_009818b0())
                bFound = true;
        }
    }
    return bFound;
}

namespace fnv_00973710 {
struct ActorX;
struct Process;
struct Combat
{
    ActorX* FUN_004030b0();
    bool FUN_009818b0();
};
struct Process
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
    virtual int detect(ActorX*, int);
};
struct ActorX
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
    virtual bool isActorXor();
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
    virtual bool isDead(int);
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual Combat* combat();
    bool IsPlayerTeammate();
    bool GetDisabled();
    bool FUN_00437bd0();
    void SetByteAt66c(char);
    unsigned char GetByteAtOffset();
    float FUN_005723b0(ActorX*, int, int);
    bool FUN_00493bb0();
    bool FUN_008a61b0();
    ActorX* FUN_00881650();
    Process* FUN_008d8520();
    bool IsHostileTo(ActorX*, int, float*, int);
    void FUN_008c8bb0(int);
};
typedef BSSimpleList<Actor*> List;
struct MyArray
{
    unsigned int FUN_005be5c0(int);
    ActorX* FUN_00968670(unsigned int);
};
struct Setting
{
    int* FUN_0043d4d0();
};
extern Setting DAT_011cd850;
extern ActorX* _g_thePlayer;
struct Shell
{
    int unk00;
    MyArray unk04;
    void FUN_00973590(ActorX*, List*);
    int GetHighestDetectionValue(ActorX*, bool);
};
// Scans the array for live, enabled actors, clamps each one's detect() result to [-100,100], and returns the highest value found (0 if none).
// @fnv 0x00973710
int Shell::GetHighestDetectionValue(ActorX* apObserver, bool abSkipListCheck)
{
    int unused = 0;
    int value = -100;
    int best2 = 0x7fffffff;
    _g_thePlayer->SetByteAt66c(0);
    ActorX* ref2 = 0;
    for (unsigned int i = 0; i < unk04.FUN_005be5c0(0); i++)
    {
        ref2 = unk04.FUN_00968670(i);
        ActorX* actor = 0;
        if (ref2 && ref2->isActorXor())
            actor = ref2;
        bool skip = false;
        if (!abSkipListCheck && actor)
        {
            List list;
            FUN_00973590(apObserver, &list);
            if (list.IsInList((Actor*&)actor) || (apObserver == _g_thePlayer && actor->IsPlayerTeammate()))
                skip = true;
        }
        if (!skip && actor)
        {
            if (actor && !actor->isDead(0) && !actor->GetDisabled() && !actor->FUN_00437bd0())
            {
                if (apObserver == _g_thePlayer && !_g_thePlayer->GetByteAtOffset())
                {
                    float f = apObserver->FUN_005723b0(actor, 0, 0);
                    if (f <= (float)*DAT_011cd850.FUN_0043d4d0())
                        _g_thePlayer->SetByteAt66c(1);
                }
                if (actor->FUN_00493bb0() || actor->FUN_008a61b0())
                {
                    if (actor->FUN_00493bb0() && actor->combat() && actor->combat()->FUN_004030b0() == apObserver &&
                        !actor->combat()->FUN_009818b0())
                        return 100;
                    else if (actor->FUN_008a61b0() && actor->FUN_00881650() == _g_thePlayer)
                        return 100;
                }
                value = actor->FUN_008d8520()->detect(apObserver, 0);
                if (value == 0x7fffffff)
                    value = 0;
                if (value > 100)
                    value = 100;
                else if (value < -100)
                    value = -100;
                float distance;
                if (value > 0 && actor->IsHostileTo(_g_thePlayer, 0, &distance, 0))
                    _g_thePlayer->FUN_008c8bb0(1);
            }
        }
        if (best2 == 0x7fffffff || best2 < value)
            best2 = value;
    }
    if (best2 == 0x7fffffff)
        best2 = 0;
    return best2;
}
}  // namespace fnv_00973710

namespace fnv_00970810 {
// Menu75x::FUN_00970810
struct Vt75
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void v09(void* obj, int flag);
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual bool v40();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void v85();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual int v8b();
    virtual void d140();
    virtual void v8d();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual int v9f();
};

struct Sh008d8520
{
    void* FUN_008d8520();
};
struct Sh0045cd60
{
    int FUN_0045cd60();
};
struct Sh00576d30
{
    bool FUN_00576d30();
};
struct Sh005d43c0
{
    void* FUN_005d43c0();
};
struct Sh0041cb10
{
    void* FUN_0041cb10();
};
struct Sh0041c930
{
    void FUN_0041c930(int a, int b, int c, int d, int e, int f);
};
struct Sh0042ce10
{
    bool FUN_0042ce10();
};
struct Sh005de0f0
{
    int FUN_005de0f0(int a);
};
struct Sh005be5c0
{
    unsigned int FUN_005be5c0(int a);
};
struct Sh00968670
{
    void* FUN_00968670(unsigned int i);
};
struct Sh00717e50
{
    void* FUN_00717e50();
};

extern "C" char DAT_011e0e80;
extern "C" void* DAT_011ddf38;

struct Menu75x
{
    void FUN_00970810(int arg);
};

// @fnv 0x00970810
void Menu75x::FUN_00970810(int arg)
{
    void* list = ((Sh00717e50*)&DAT_011e0e80)->FUN_00717e50();
    for (unsigned int i = ((Sh005de0f0*)list)->FUN_005de0f0(0); i < ((Sh005be5c0*)list)->FUN_005be5c0(3); ++i)
    {
        void* a = ((Sh00968670*)list)->FUN_00968670(i);
        void* p = 0;
        if (a != 0)
        {
            if (((Vt75*)a)->v40())
            {
                if (!((Sh00576d30*)a)->FUN_00576d30())
                {
                    p = a;
                }
            }
        }
        while (p)
        {
            int v = 0;
            if (((Sh008d8520*)p)->FUN_008d8520() != 0)
            {
                v = ((Vt75*)((Sh008d8520*)p)->FUN_008d8520())->v9f();
            }
            if (((Sh008d8520*)p)->FUN_008d8520() != 0)
            {
                if (v != ((Vt75*)((Sh008d8520*)p)->FUN_008d8520())->v8b())
                {
                    void* q = 0;
                    if (((Sh008d8520*)p)->FUN_008d8520() != 0)
                    {
                        switch (((Sh0045cd60*)((Sh008d8520*)p)->FUN_008d8520())->FUN_0045cd60())
                        {
                        case 0:
                        case 1:
                            q = ((Sh008d8520*)p)->FUN_008d8520();
                        }
                    }
                    if (v == arg && q)
                    {
                        ((Vt75*)q)->v85();
                    }
                }
            }
            if (((Sh008d8520*)p)->FUN_008d8520() != 0)
            {
                if (((Vt75*)((Sh008d8520*)p)->FUN_008d8520())->v8b() == arg)
                {
                    ((Vt75*)((Sh008d8520*)p)->FUN_008d8520())->v8d();
                    if (!((Sh0042ce10*)DAT_011ddf38)->FUN_0042ce10())
                    {
                        ((Vt75*)((Sh008d8520*)p)->FUN_008d8520())->v09(p, 1);
                    }
                }
            }
            if (((Sh0041cb10*)((Sh005d43c0*)p)->FUN_005d43c0())->FUN_0041cb10() == (void*)arg)
            {
                ((Sh0041c930*)((Sh005d43c0*)p)->FUN_005d43c0())->FUN_0041c930(0, 0, 0, 0, 0, 0);
            }
            p = 0;
        }
    }
}
}  // namespace fnv_00970810

struct R9711
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
    virtual bool IsValid40();
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
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
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
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
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
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
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
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual void v7D();
    virtual void v7E();
    virtual void v7F();
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
    virtual void v8A();
    virtual bool Check8B(int a);
    R9711* GetObj();
    R9711* GetParentCell();
    R9711* GetWorld();
    void SetFlag(int a);
    bool IsInterior();
    bool Is440da0();
    bool Is440d80();
    R9711* GetExtra();
    unsigned int GetType();
    bool Is9ec810(R9711* a);
    float GetDist(R9711* a, int b, int c);
    int* GetSetting();
    void AddItem(R9711* const& p);
    R9711** GetItem();
    R9711* Next();
    R9711* Get568e50();
    R9711* Get559450();
    void SetCallback(void (*f)());
    unsigned int Count(int a);
    R9711* At(unsigned int a);
};

struct Ref9711 : R9711
{
};

struct Res9711 : R9711
{
    Res9711();
    int unk04;
};

extern R9711 DAT_011cdbec;
extern float DAT_01016970;
void FUN_00970ee0();

struct Lst9711
{
    int unk00;
    int unk04;
    R9711* CollectNearbyRefs(R9711* apObj, R9711* apList);
};

// Iterates a list of refs, filters by cell/world proximity and distance, and adds matching refs to a new result list with a callback.
// @fnv 0x009711e0
R9711* Lst9711::CollectNearbyRefs(R9711* apObj, R9711* apList)
{
    R9711* pResultList = new Res9711();
    R9711* pObj = apObj->GetObj();
    R9711* pCell = pObj->GetParentCell();
    R9711* world = pObj->GetWorld();
    apObj->SetFlag(1);
    if (!pObj)
    {
        return pResultList;
    }
    R9711* entry = 0;
    unsigned int j;
    for (j = 0; j < ((R9711*)&unk04)->Count(3); ++j)
    {
        entry = ((R9711*)&unk04)->At(j);
        Ref9711* ref = 0;
        if (entry && entry->IsValid40())
        {
            ref = (Ref9711*)entry;
        }
        R9711* iter = 0;
        while (ref)
        {
            float dist = DAT_01016970;
            if (ref && !ref->Check8B(0) && !ref->Is440da0() && !ref->Is440d80() && !ref->Check8B(0))
            {
                R9711* pRefCell = ref->GetParentCell();
                R9711* pRefWorld = ref->GetWorld();
                R9711* pLinked = 0;
                R9711* pExtraData = ref->GetExtra();
                if (pExtraData && pExtraData->GetType() == 0x15)
                {
                    pLinked = pExtraData;
                }
                if (!pLinked || !pLinked->Is9ec810(apObj))
                {
                    if ((pRefCell && pRefCell == pCell) ||
                        (world == pRefWorld &&
                         ((pRefCell && !pRefCell->IsInterior()) || (pCell && !pCell->IsInterior()))))
                    {
                        dist = ref->GetDist(pObj, 0, 0);
                        if (dist <= (float)*DAT_011cdbec.GetSetting())
                        {
                            pResultList->AddItem(static_cast<R9711*>(ref));
                        }
                    }
                    else
                    {
                        R9711* node = apList;
                        while (node && *node->GetItem())
                        {
                            R9711* other = *node->GetItem();
                            if (other)
                            {
                                R9711* pBase = other->Get568e50();
                                R9711* pParent = 0;
                                if (pBase)
                                {
                                    pParent = pBase->Get559450();
                                    if (pParent->GetParentCell() == pRefCell ||
                                        (!pParent->GetParentCell() && pParent->GetWorld() == ref->GetWorld()))
                                    {
                                        dist = ref->GetDist(pParent, 0, 0);
                                        if (dist <= (float)*DAT_011cdbec.GetSetting())
                                        {
                                            pResultList->AddItem(static_cast<R9711*>(ref));
                                            break;
                                        }
                                    }
                                }
                            }
                            node = node->Next();
                        }
                    }
                }
            }
            if (iter && *iter->GetItem())
            {
                ref = 0;
                if (static_cast<Ref9711*>(*iter->GetItem())->IsValid40())
                {
                    ref = (Ref9711*)*iter->GetItem();
                }
                iter = iter->Next();
            }
            else
            {
                ref = 0;
            }
        }
    }
    if (pResultList)
    {
        pResultList->SetCallback(&FUN_00970ee0);
    }
    return pResultList;
}

struct ItmQ
{
    unsigned short FUN_009ebb80();
};
struct LstQ
{
    bool FUN_008256d0();
    ItmQ** FUN_006815c0();
    LstQ* FUN_00726070();
};
struct OwnQ
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40;
    LstQ* apLists[5];
    unsigned short GetTotalSize();
};
// Returns the total size by summing 4, 2 per list, and the size of each item in the five apLists.
// @fnv 0x00975450
unsigned short OwnQ::GetTotalSize()
{
    int i;
    unsigned short usTotalSize = 0;
    usTotalSize += 4;
    for (i = 0; i < 5; i++)
    {
        LstQ* pIter = apLists[i];
        usTotalSize += 2;
        while (pIter && !pIter->FUN_008256d0())
        {
            ItmQ* pItem = *pIter->FUN_006815c0();
            usTotalSize += pItem->FUN_009ebb80();
            pIter = pIter->FUN_00726070();
        }
    }
    return usTotalSize;
}

struct CrimeCleanup
{
    ~CrimeCleanup();
};

struct FUN_00975b60_shell : ProcessLists
{
    void CleanupCrimeLists(BGSLoadGameBuffer* buffer);
};

// Resets process timers and crime counter, then deletes all Crime entries and the five CrimeLists, nulling the pointers.
// @fnv 0x00975b60
void FUN_00975b60_shell::CleanupCrimeLists(BGSLoadGameBuffer* buffer)
{
    m_fProcessListValue2 = 0.0f;
    m_fProcessUpdateTimer = 0.0f;
    m_iCrimeNumber = 0;

    for (unsigned int index = 0; index < 5; ++index)
    {
        BSSimpleList<Crime*>* list = m_pkCrimeLists[index];
        while (list && list->GetItem())
        {
            Crime* entry = list->GetItem();
            delete (CrimeCleanup*)entry;
            list->RemoveHead();
        }
        delete list;
        m_pkCrimeLists[index] = 0;
    }
}

struct Buffer652
{
    void FUN_00864980(void*, unsigned int);
    unsigned int FUN_00864a60();
    void FUN_008648e0(TESObjectREFR**);
};
struct Receiver652;
Receiver652* __cdecl FUN_00832930(TESObjectREFR*);
struct ReceiverList652
{
    Receiver652* item;
    ReceiverList652* next;
    void FUN_005ae3d0(Receiver652*&);
};
struct FUN_0083b830
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0083b830();
    void FUN_0083c330(Buffer652*);
};
struct Radio652
{
    FUN_0083b830* conversation;
    int unk04;
    int unk08;
    int unk0c;
    bool unk10;
    bool unk11;
    int unk14;
    ReceiverList652 receivers;
    void FUN_00836240(Buffer652*);
};
// Reads radio fields, receiver list, and optional conversation from a Buffer652 stream.
// @fnv 0x00836240
void Radio652::FUN_00836240(Buffer652* buffer)
{
    buffer->FUN_00864980(&unk08, 4);
    buffer->FUN_00864980(&unk0c, 4);
    buffer->FUN_00864980(&unk10, 1);
    buffer->FUN_00864980(&unk11, 1);
    buffer->FUN_00864980(&unk14, 4);
    unsigned int count = buffer->FUN_00864a60();
    for (unsigned int i = 0; i < count; i++)
    {
        TESObjectREFR* ref = 0;
        buffer->FUN_008648e0(&ref);
        Receiver652* radio = FUN_00832930(ref);
        if (radio)
            receivers.FUN_005ae3d0(radio);
    }
    bool has3 = false;
    buffer->FUN_00864980(&has3, 1);
    if (has3)
    {
        conversation = new FUN_0083b830;
        conversation->FUN_0083c330(buffer);
    }
}

struct ListA
{
    unsigned int FUN_0055b980();
    void* FUN_00968670(unsigned int i);
};
struct ObjA
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    void FUN_00881680(int);
    bool FUN_00566950();
    void FUN_008ad910(int, int, int);
};
struct ActorA : ObjA
{
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w4a();
    virtual void w4b();
    virtual void w4c();
    virtual void w4d();
    virtual void w4e();
    virtual void w4f();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w5a();
    virtual void w5b();
    virtual void w5c();
    virtual void w5d();
    virtual void w5e();
    virtual void w5f();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w6a();
    virtual void w6b();
    virtual void w6c();
    virtual void w6d();
    virtual void w6e();
    virtual void w6f();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w7a();
    virtual void w7b();
    virtual void w7c();
    virtual void w7d();
    virtual void w7e();
    virtual void w7f();
    virtual void w80();
    virtual void w81();
    virtual void w82();
    virtual void w83();
    virtual void w84();
    virtual void w85();
    virtual void w86();
    virtual void w87();
    virtual void w88();
    virtual void w89();
    virtual void w8a();
    virtual bool IsDead(int);
};
struct MgrA
{
    bool IsPlayerTargeted(ActorA*, int);
};
extern MgrA* g_mgrA;
struct StubX
{
    int unk00;
    ListA list;
    void FUN_00973ee0(int a);
};
// Iterates over list, and for each live actor that is player-targeted or matches FUN_00566950, calls FUN_00881680 and FUN_008ad910 with a.
// @fnv 0x00973ee0
void StubX::FUN_00973ee0(int a)
{
    if (!a)
        return;
    ObjA* item = 0;
    for (unsigned int i = 0; i < list.FUN_0055b980(); i++)
    {
        item = (ObjA*)list.FUN_00968670(i);
        ActorA* actor = 0;
        if (item && item->IsActor())
            actor = (ActorA*)item;
        if (actor && !actor->IsDead(0))
        {
            if (g_mgrA->IsPlayerTargeted(actor, 0) || actor->FUN_00566950())
            {
                actor->FUN_00881680(0);
                actor->FUN_008ad910(a, 0, 0);
            }
        }
    }
}

namespace fnv_0096eb40 {
struct Pkg;
struct Ref;
struct Proc;
struct Proc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual Pkg* GetPkg();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual bool Is360();
    virtual void Set364(int);
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual float Get69c();
    int f45cd60();
};
struct Ref
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~Ref();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void HandleInteger(int);
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual bool IsA();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool Is160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool Is224();
    virtual void v228();
    virtual bool Is22c(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void Do260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void Do324(int, int, int);
};

struct Pkg
{
    int f41ca90();
};
struct Inv;
struct Node;
struct Inv
{
    Node* f41df90();
    void f41de40(int);
    void f41dfd0();
};
struct Node
{
    Ref** Item();
    Node* Next();
    bool f8256d0();
    void f63f7b0();
};
struct X567
{
    bool f526320();
};
struct RefEx : Ref
{
    char pad[0x7e];
    bool b82;
    bool f576d30();
    Proc* GetProc();
    bool f574900();
    bool f92f160();
    bool f440d80();
    int f484e60(int);
    bool f440da0();
    int f931850();
    void f931e80();
    int f44ddc0();
    bool f87f3d0();
    bool f87f4a0();
    int f8d6f30(int);
    X567* f567d20();
    Inv* f5d43c0();
    void f572270();
};
struct Mgr94
{
    bool f94df60();
};
struct Mgr10
{
    bool f4511e0(int);
};
struct MgrB8
{
    unsigned int f867e30();
};
struct Lock
{
    void Enter(int);
    void Leave();
    bool TryEnter();
};
struct Q80
{
    void f96d450(RefEx*, int, int, int, int);
};
struct Sub4
{
    void f96aaf0(RefEx*, int);
    void f96a970(RefEx*, int);
};
struct List78
{
    void Remove(Ref* const&);
};
extern Mgr94* g_11dea3c;
extern Mgr10* g_11dea10;
extern MgrB8 g_11de7b8;
extern RefEx* g_ref;
extern Q80 g_11e0e80;
extern Lock g_lock;
unsigned int f526100();
RefEx* f705190();
int f702640();

struct FUN_0096eb40_cls
{
    int unk00;
    Sub4 sub4;
    char pad[0x73];
    List78 list;
    void FUN_0096eb40();
};

// Processes refs in the list, removes or updates some entries, then calls HandleInteger(1) on each remaining ref.
// @fnv 0x0096eb40
void FUN_0096eb40_cls::FUN_0096eb40()
{
    if (!g_11dea3c->f94df60())
    {
        Node* pListHead = (Node*)&list;
        Node* pNode = pListHead;
        while (pNode && *pNode->Item())
        {
            g_ref = 0;
            if ((*pNode->Item())->IsA())
                g_ref = (RefEx*)*pNode->Item();
            if (g_ref)
            {
                RefEx* pActor = 0;
                if (g_ref->IsActor())
                    pActor = g_ref;
                pNode = pNode->Next();
                if (!g_ref->f576d30())
                {
                    if ((g_ref->IsActor() && !g_ref->GetProc()) || (g_ref->f574900() && f705190() != g_ref))
                    {
                        if (g_ref->f574900() && g_ref->f92f160())
                        {
                            g_11e0e80.f96d450(g_ref, 0, 0, 0, 0);
                        }
                        else if ((g_ref->f440d80() && !g_ref->f484e60(-1)) || (g_ref->f574900() && !g_ref->f92f160()))
                        {
                            if (g_ref->GetProc())
                                sub4.f96aaf0(g_ref, g_ref->f931850());
                            g_lock.Enter(0);
                            delete g_ref;
                            g_lock.Leave();
                        }
                        else if ((g_ref->f440d80() || g_ref->f440da0()) && g_ref->GetProc() && g_lock.TryEnter())
                        {
                            sub4.f96aaf0(g_ref, g_ref->f931850());
                            g_ref->f931e80();
                            g_lock.Leave();
                        }
                        list.Remove(g_ref);
                        if (g_ref)
                            g_ref->b82 = 0;
                        pNode = pListHead;
                    }
                    else if (pActor && pActor->Is22c(0) && !pActor->f87f3d0() && pActor->f87f4a0() &&
                             !g_11dea10->f4511e0(pActor->f8d6f30(0)) && pActor->GetProc()->Get69c() != 0.0 &&
                             pActor->GetProc()->Get69c() + f526100() < g_11de7b8.f867e30())
                    {
                        X567* pX567 = pActor->f567d20();
                        if (!pX567 || !pX567->f526320())
                        {
                            pActor->Do324(1, 0, 0);
                            Node* pInvNode = pActor->f5d43c0()->f41df90();
                            if (pInvNode)
                            {
                                while (pInvNode && !pInvNode->f8256d0())
                                {
                                    RefEx* pRef = (RefEx*)*pInvNode->Item();
                                    pRef->f5d43c0()->f41de40(0);
                                    if (!pRef->Is160())
                                        pRef->f572270();
                                    pInvNode->f63f7b0();
                                }
                                pActor->f5d43c0()->f41dfd0();
                            }
                            list.Remove(g_ref);
                            if (g_ref)
                                g_ref->b82 = 0;
                            pNode = pListHead;
                        }
                    }
                    else if (g_ref->f440da0() && g_lock.TryEnter())
                    {
                        if (g_ref->GetProc())
                            sub4.f96aaf0(g_ref, g_ref->f931850());
                        g_ref->f931e80();
                        list.Remove(g_ref);
                        if (g_ref)
                            g_ref->b82 = 0;
                        pNode = pListHead;
                        g_lock.Leave();
                    }
                    else if ((g_ref->f574900() && f702640() != 0x3f1) ||
                             ((g_ref->f44ddc0() & 0x20000) && !g_ref->f574900()))
                    {
                        g_ref->HandleInteger(0);
                        list.Remove(g_ref);
                        if (g_ref)
                            g_ref->b82 = 0;
                        RefEx* r = 0;
                        if (g_ref->Is224())
                            r = g_ref;
                        if (g_ref->f440d80() && !g_ref->f484e60(-1))
                        {
                            if (g_ref->GetProc())
                                sub4.f96aaf0(g_ref, g_ref->f931850());
                            g_lock.Enter(0);
                            delete g_ref;
                            g_lock.Leave();
                        }
                        else if (g_ref->f440d80() || g_ref->f440da0())
                        {
                            if (g_ref->GetProc() && g_lock.TryEnter())
                            {
                                sub4.f96aaf0(g_ref, g_ref->f931850());
                                g_ref->f931e80();
                                g_lock.Leave();
                            }
                        }
                        else if (g_ref->GetProc() && g_ref->GetProc()->Is360())
                        {
                            Pkg* pPkg = g_ref->GetProc()->GetPkg();
                            if (!pPkg || (pPkg->f41ca90() != 1 && pPkg->f41ca90() != 2))
                            {
                                g_ref->GetProc()->Set364(0);
                                sub4.f96a970(g_ref, g_ref->GetProc()->f45cd60());
                            }
                        }
                        else
                        {
                            g_ref->Do260();
                            if (g_ref && (g_ref->f44ddc0() & 0x20000))
                                g_ref->HandleInteger(0);
                        }
                        pNode = pListHead;
                    }
                }
            }
        }
        pNode = pListHead;
        while (pNode && *pNode->Item())
        {
            Ref* r = *pNode->Item();
            r->HandleInteger(1);
            pNode = pNode->Next();
        }
    }
}
}  // namespace fnv_0096eb40

struct WeaponShaderEffectAccess : public ::MagicShaderHitEffect
{
    unsigned int FUN_00441110();
    bool IsUnk28Set();
    unsigned char GetField24();
    char* FUN_00671d10();
    void SetByteAt24(unsigned int);
};
struct WeaponShaderCleanup : public ::ProcessLists
{
    ::MagicShaderHitEffect* FUN_00974db0(::TESObjectREFR*, ::TESEffectShader*);
};
// Searches the temporary effect list, returns the first match, and calls FUN_00461310(1) on later matches.
// @fnv 0x00974db0
::MagicShaderHitEffect* WeaponShaderCleanup::FUN_00974db0(::TESObjectREFR* target, ::TESEffectShader* shader)
{
    ::MagicShaderHitEffect* result = 0;
    if (!m_kTemporaryEffectList2.IsEmpty())
    {
        ::BSSimpleList< ::NiPointer< ::BSTempEffect> >* node = &m_kTemporaryEffectList2;
        while (node)
        {
            ::BSTempEffect* effect = node->GetItem();
            if (effect && ::FUN_0043b300(reinterpret_cast<const ::NiRTTI*>(&::g_011dc804),
                                         reinterpret_cast< ::NiAVObject*>(effect)))
            {
                WeaponShaderEffectAccess* current = reinterpret_cast<WeaponShaderEffectAccess*>(effect);
                if (current->FUN_00441110() == reinterpret_cast<unsigned int>(target) && current->IsUnk28Set() &&
                    !current->GetField24())
                {
                    if (current->FUN_00671d10() == reinterpret_cast<char*>(shader) && !result)
                        result = current;
                    else
                        current->SetByteAt24(1);
                }
            }
            node = node->GetNext();
        }
    }
    return result;
}
