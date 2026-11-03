// fallout/ai/lowprocess.cpp: LowProcess, ActorX, DelStandIn, LowProcessProxy and more (123 functions)

#include "lowprocess_decls.h"

// @fnv 0x008d7dc0
void LowProcess::SetCurrentBoundObject(TESBoundObject* apBoundObject)
{
    m_pCurrentWeapon = apBoundObject;
}
// @fnv 0x008d8040
void LowProcess::SetCurrentCombatTarget(TESObjectREFR* apReference)
{
    m_pReference40 = apReference;
}
// @fnv 0x008d6f30
TESObjectREFR* LowProcess::GetTarget()
{
    return pTarget;
}
// @fnv 0x005a8060
void LowProcess::SetPackageObjectType(int aiValue)
{
    m_iValue58 = aiValue;
}
// @fnv 0x006286d0
int LowProcess::GetPackageObjectType()
{
    return m_iValue58;
}
// @fnv 0x008041a0
TESObjectREFR* LowProcess::GetActiveCombatTarget()
{
    return m_pReference40;
}
// @fnv 0x008d7de0
void LowProcess::SetAnimationComplete(bool abSet)
{
    SetFlag(abSet, 0x02);
}
// @fnv 0x008d7e40
bool LowProcess::IsMovementComplete()
{
    return GetFlag(0x02);
}
// @fnv 0x008d7e80
bool LowProcess::IsCurrentProcessComplete()
{
    return GetFlag(0x10);
}
// @fnv 0x008d7ee0
void LowProcess::SetProcessTaskComplete(bool abSet)
{
    SetFlag(abSet, 0x04);
}
// @fnv 0x008d7f60
bool LowProcess::IsProcessConditionMet()
{
    return m_kProcessData38.CheckTimer();
}
// @fnv 0x008d7fe0
void LowProcess::SetProcessConditionMet(bool argument0)
{
    SetFlag(argument0, 0x01);
}
// @fnv 0x008d8000
bool LowProcess::IsProcessActivityActive()
{
    return GetFlag(0x20);
}
// @fnv 0x008d8020
void LowProcess::SetProcessModeEnabled(bool abSet)
{
    SetFlag(abSet, 0x20);
}
// @fnv 0x008d8060
bool LowProcess::IsAnimationStateActive()
{
    return GetFlag(0x80);
}
// @fnv 0x008d8080
void LowProcess::SetAnimationStateActive(bool argument0)
{
    SetFlag(argument0, 0x80);
}
// @fnv 0x008d80a0
bool LowProcess::IsCurrentlyAlerted()
{
    return GetFlag(0x08);
}
// @fnv 0x008d80c0
void LowProcess::SetAlert(bool abEnabled)
{
    SetFlag(abEnabled, 0x08);
}
// @fnv 0x009b88a0
float LowProcess::GetCurrentDetectionAmount()
{
    return m_fValue8C;
}

// Updates the low process for a mobile object: runs the current package's procedure for actors and forwards to the high process update otherwise.
// @fnv 0x0090ad40
void LowProcess::Update(MobileObject* mobile)
{
    reinterpret_cast<TESForm*>(&DAT_011e0361)->IsInCombat();
    if (!mobile)
        return;
    struct UpdateContext
    {
        Actor* actor;
        float hour;
    } update;
    update.hour = g_calendar.GetGameTime();
    update.actor = 0;
    if (mobile->IsActor())
        update.actor = static_cast<Actor*>(mobile);
    if (update.actor)
    {
        if (update.actor->vfn_274(true) && g_thePlayer->IsSleepingOrResting())
            update.actor->vfn_434(false);
        struct PackageState
        {
            TESObjectREFR* location;
            PackageTargetRecord* target;
            TESPackage* current;
        } state;
        TESPackage* package = GetCurrentPackage();
        if (CanProcessActor(update.actor, false))
        {
            UpdateCurrentPackage(update.actor);
            package = GetCurrentPackage();
            update.actor->RefreshCurrentPackage();
            SetGenericLocationsForPackage(update.actor, false);
            state.current = GetCurrentPackage();
            if (state.current)
            {
                state.target = state.current->GetTarget();
                if (state.target && state.target->GetTargetKind() != 0 && state.target->GetTargetKind() != 3)
                    m_iValue58 = state.current->GetPackageTargetType();
            }
        }
        bool bPathingFailed = false;
        if (m_bHasBoundObject && update.actor->IsActorEssential())
            bPathingFailed = true;
        if (GetCurrentPackage() && GetCurrentPackage()->GetProcedureType() != -1 &&
            !GetCurrentPackage()->HasEssentialStatus())
        {
            char message[300];
            UpdateTargetFromPackage();
            state.location = 0;
            switch (DAT_011a3ff0[GetCurrentPackage()->GetProcedureType()][GetProcedureIndex()])
            {
            case 0: {
                state.location = m_pReference40;
                if (!GetCurrentPackage()->IsPackageRunningForActor(update.actor, 0, -1.0f, false))
                {
                    if (update.actor->FUN_008b3bb0())
                    {
                        if (!update.actor->IsAtPosition(GetCurrentPackage()->GetPackageLocationPosition(update.actor),
                                                        GetCurrentPackage()->GetPackageLocationCell(update.actor),
                                                        GetCurrentPackage()->GetPackageWorldSpace(update.actor), -1.0f,
                                                        0))
                            return;
                    }
                    float delta = GetActorTimeDelta(update.actor);
                    if (reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(update.actor)->GetProcess())
                                ->GetProcessLevel() == 3 &&
                        GetCurrentPackage()->IsPackageRunningForActor(update.actor, 0, -1.0f, false))
                    {
                        if (!vfn_1bc())
                        {
                            if (GetCurrentPackage()->FUN_00670f40())
                                g_dataHandler->GetReferencesInArea(
                                    update.actor->GetParentCell(), *update.actor->GetPos(),
                                    runtimeFloatSettingDefault247, *update.actor->GetPos(),
                                    runtimeFloatSettingDefault247, HandlePackageLocationLoaded,
                                    reinterpret_cast<long>(update.actor));
                            vfn_1c0(true);
                        }
                        if (GetCurrentPackage()->FUN_00670f60())
                            g_dataHandler->GetReferencesInArea(update.actor->GetParentCell(), *update.actor->GetPos(),
                                                               runtimeFloatSettingDefault247, *update.actor->GetPos(),
                                                               runtimeFloatSettingDefault247, HandlePackageTargetLoaded,
                                                               reinterpret_cast<long>(update.actor));
                        SetProcessTarget(update.actor, 1);
                        if ((state.location && state.location->GetObjectReference() == DAT_011ca248) ||
                            (reinterpret_cast<LocationDescriptor*>(
                                 reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID()) &&
                             reinterpret_cast<LocationDescriptor*>(
                                 reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID())
                                     ->GetLocType() == 3))
                        {
                            float rotation = 0.0f;
                            if (state.location)
                                rotation = reinterpret_cast<const NiPoint3*>(
                                               reinterpret_cast<TESRecipe*>(state.location)->GetData())
                                               ->z;
                            else
                                rotation = update.actor->vfn_16c().z;
                            update.actor->vfn_2c4(rotation);
                        }
                    }
                }
                else
                {
                    if (!vfn_1bc())
                    {
                        if (GetCurrentPackage()->FUN_00670f40())
                            g_dataHandler->GetReferencesInArea(
                                update.actor->GetParentCell(), *update.actor->GetPos(), runtimeFloatSettingDefault247,
                                *update.actor->GetPos(), runtimeFloatSettingDefault247, HandlePackageLocationLoaded,
                                reinterpret_cast<long>(update.actor));
                        vfn_1c0(true);
                    }
                    if (GetCurrentPackage()->FUN_00670f60())
                        g_dataHandler->GetReferencesInArea(update.actor->GetParentCell(), *update.actor->GetPos(),
                                                           runtimeFloatSettingDefault247, *update.actor->GetPos(),
                                                           runtimeFloatSettingDefault247, HandlePackageTargetLoaded,
                                                           reinterpret_cast<long>(update.actor));
                    if ((state.location && state.location->GetObjectReference() == DAT_011ca248) ||
                        (reinterpret_cast<LocationDescriptor*>(
                             reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID()) &&
                         reinterpret_cast<LocationDescriptor*>(
                             reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID())
                                 ->GetLocType() == 3))
                    {
                        float completedRotation = 0.0f;
                        if (state.location)
                            completedRotation = reinterpret_cast<const NiPoint3*>(
                                                    reinterpret_cast<TESRecipe*>(state.location)->GetData())
                                                    ->z;
                        else
                            completedRotation = update.actor->vfn_16c().z;
                        update.actor->vfn_2c4(completedRotation);
                    }
                    SetProcessTarget(update.actor, 1);
                }
                break;
            }
            case 9:
                break;
            case 33:
                vfn_7e0(update.actor);
                break;
            case 41:
                SetProcessTarget(update.actor, 2);
                break;
            case 10:
                vfn_2a0(update.actor);
                break;
            case 34:
                ProcessFleeNonCombat(update.actor);
                break;
            case 35:
                vfn_c4(update.actor, true);
                break;
            case 26:
                ProcessNotify(update.actor);
                break;
            case 47:
                ProcessGuard(update.actor);
                break;
            case 38:
                vfn_800(update.actor);
                break;
            case 27:
                ProcessAccompany(update.actor);
                break;
            case 28:
                ProcessUseItemAt(update.actor);
                break;
            case 50:
                ProcessUseWeapon(update.actor);
                break;
            case 17:
                if (!pTarget)
                    FindPackageTarget(update.actor);
                if (pTarget && pTarget != g_thePlayer && pTarget->IsActor())
                    vfn_c8(update.actor, GetCurrentPackage(), true);
                SetProcessTarget(update.actor, 1);
                break;
            case 14:
                ProcessActivate(update.actor, false);
                break;
            case 3:
                ProcessAcquire(update.actor);
                break;
            case 12:
                update.actor->SetSpeakingState(false);
                break;
            case 49: {
                Actor* target = 0;
                if (pTarget && pTarget->IsActor())
                    target = static_cast<Actor*>(pTarget);
                if (target && (!GetCurrentPackage()->GetPackageSecondLocation() ||
                               GetCurrentPackage()->IsSecondLocationDone(target, update.actor, 0, -1.0f, true)))
                    ProcessActivate(update.actor, true);
                break;
            }
            case 8:
                ProcessAlarm(update.actor);
                break;
            case 15:
                vfn_29c(update.actor, false, true, 0x101);
                break;
            case 2:
                ProcessActivate(update.actor, true);
                break;
            case 1:
                if (GetCurrentPackage()->GetProcedureType() == 26)
                    SetProcessTarget(update.actor, -1);
                break;
            case 4:
                if (FUN_00703180() == update.actor)
                {
                    sprintf(message, "%s is sleeping with %s", update.actor->GetFullName(),
                            PrepareScriptMessage(g_packageTypeNames[GetCurrentPackage()->GetPackType()], false));
                    DebugLog(message);
                }
                break;
            case 5:
                if (FUN_00703180() == update.actor)
                {
                    sprintf(message, "%s is eating with %s", update.actor->GetFullName(),
                            PrepareScriptMessage(g_packageTypeNames[GetCurrentPackage()->GetPackType()], false));
                    DebugLog(message);
                }
                break;
            case 6:
                vfn_298(update.actor, true, 0x101, false);
                break;
            case 42:
                ProcessSandbox(update.actor);
                break;
            case 51:
                ProcessMovementBlocked(update.actor);
                break;
            case 30:
                ProcessAmbushWait(update.actor);
                break;
            case 13:
                if (!pTarget)
                    FindPackageTarget(update.actor);
                if (!pTarget || pTarget->IsDeleted())
                    SetProcessTarget(update.actor, 1);
                else if (package->HasEssentialStatus())
                {
                    if (!g_thePlayer->IsActorInCombatWithPlayer(update.actor) &&
                        g_thePlayer->GetCharacterLevel() < DAT_011cdad0.Int()->i)
                        GetCurrentPackage()->SetWaiting(false);
                }
                else if (package->GetPackType() != 28 && !package->HasEssentialStatus())
                {
                    if (package->GetPackType() == 1)
                    {
                        float distance = static_cast<float>(static_cast<int>(
                            reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(package->GetTarget())->GetSize()));
                        if (distance >= update.actor->GetDistanceToReference(pTarget, false, false))
                            SetProcessTarget(update.actor, 1);
                    }
                    else
                    {
                        struct FollowDistance
                        {
                            int targetCount;
                            float distanceLimit;
                        } follow;
                        follow.distanceLimit = 0.0f;
                        follow.targetCount = static_cast<int>(
                            reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(package->GetTarget())->GetSize());
                        if (follow.targetCount <= 0)
                            follow.targetCount = 200;
                        if (follow.distanceLimit == 0.0 && update.actor->GetParentCell() &&
                            update.actor->GetParentCell()->IsCellInterior())
                            follow.distanceLimit =
                                reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting173)
                                    .Float()
                                    ->f;
                        else if (follow.distanceLimit == 0.0)
                            follow.distanceLimit =
                                follow.targetCount *
                                reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting172)
                                    .Float()
                                    ->f;
                        SetProcessTarget(update.actor, 1);
                    }
                }
                break;
            case 7:
                switch (GetCurrentPackage()->GetPackType())
                {
                case 1:
                case 2:
                case 7:
                case 22:
                    vfn_7b4(update.actor);
                    break;
                }
                break;
            case 11:
                break;
            case 44:
                ProcessPatrol(update.actor);
                break;
            default:
                break;
            }
            if (update.actor->GetCurrentProcessLevel() == 3 && GetCurrentPackage() &&
                DAT_011a3ff0[GetCurrentPackage()->GetProcedureType()][GetProcedureIndex()] == 54)
            {
                if (!vfn_5a4())
                {
                    Script::GetLocalData(GetCurrentPackage(), update.actor->GetExtraData(), 0x400);
                    OnPackageEnd(update.actor, GetCurrentPackage());
                    vfn_5a8(true);
                }
                vfn_1c8(false);
                if (GetCurrentPackage() && GetCurrentPackage()->GetProcedureType() == 0 &&
                    !GetCurrentPackage()->IsPackageRunningForActor(update.actor, 0, -1.0f, false))
                {
                    SetProcessTarget(update.actor, -1);
                    return;
                }
                if (GetCurrentPackage() && GetCurrentPackage()->IsMustReachLocation())
                    update.actor->vfn_28c(GetCurrentPackage(), static_cast<unsigned char>(g_calendar.GetGameHour()));
                if (GetCurrentPackage() && GetCurrentPackage()->IsMustComplete())
                    update.actor->SetSpeakingState(false);
                if (FUN_00703180() == update.actor)
                {
                    sprintf(message, "%s is done with %s", update.actor->GetFullName(),
                            PrepareScriptMessage(g_packageTypeNames[GetCurrentPackage()->GetPackType()], false));
                    DebugLog(message);
                }
                delete reinterpret_cast<Date*>(m_pDetectionData60);
                m_pDetectionData60 = 0;
                while (!reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).IsEmpty())
                {
                    TargetDoorController* item = reinterpret_cast<TargetDoorController*&>(
                        reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).GetItem());
                    delete reinterpret_cast<Date*>(item);
                    reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
                        .Remove(reinterpret_cast<TESPackage* const&>(item));
                }
                if (GetCurrentPackage() &&
                    !reinterpret_cast<int>(
                        reinterpret_cast<BSSimpleList<TESPackage*>*>(GetCurrentPackage()->FUN_0041d8a0())->GetNext()))
                {
                    TESPackage* previous = GetCurrentPackage();
                    SelectNextPackage(update.actor);
                    package = GetCurrentPackage();
                    if (previous != GetCurrentPackage())
                        SetProcedureIndex(0);
                }
            }
        }
        if (!update.actor->HasBoundObject() || bPathingFailed)
        {
            reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(mobile)->GetProcess())->Update();
            m_bHasBoundObject = false;
        }
        else
            m_bHasBoundObject = true;
    }
    else
        reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(mobile)->GetProcess())->Update();
    reinterpret_cast<TESForm*>(&DAT_011e0361)->IsInCombat();
}

// Checks the actor's current package against time and combat conditions, updates the package and target, and returns whether the package changed.
// @fnv 0x0090a1a0
bool LowProcess::CanProcessActor(Actor* actor, bool force)
{
    struct ScheduleContext
    {
        float hour;
        TESPackage* previous;
        TESPackage* lockPackage;
    } context;
    context.hour = g_calendar.GetGameTime();
    context.previous = GetCurrentPackage();
    if (!force && (actor->IsInDeadState() || reinterpret_cast<PlayerCharacter*>(actor)->HasCombatState()))
        return false;
    context.lockPackage = 0;
    if (GetCurrentPackage() && (GetCurrentPackage()->IsFlag10Set() || GetCurrentPackage()->IsFlag80Set()))
        context.lockPackage = GetCurrentPackage();
    {
        bool changed = false;
        bool sentEnd;
        if (!context.previous)
        {
            changed = true;
            SelectNextPackage(actor);
            if (!GetCurrentPackage())
                changed = false;
            context.previous = GetCurrentPackage();
            SetTarget(0);
            vfn_4ec(false);
        }
        else
        {
            if (reinterpret_cast<int>(
                    reinterpret_cast<BSSimpleList<TESPackage*>*>(context.previous->FUN_0041d8a0())->GetNext()) &&
                context.previous->FUN_0067efd0())
            {
                int ending = 0;
                bool checkTime = false;
                sentEnd = false;
                if (reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(actor)->GetProcess())->vfn_11c() ||
                    DAT_011a3ff0[context.previous->GetProcedureType()][GetProcedureIndex()] == 54)
                    checkTime = true;
                else if (context.previous->GetPackType() == 5 || context.previous->GetPackType() == 4 ||
                         context.previous->GetPackType() == 3 || context.previous->GetPackType() == 12)
                {
                    checkTime = true;
                    sentEnd = true;
                }
                if (checkTime)
                {
                    if (context.previous->FUN_0041d8a0()->FUN_0086a460() == -1)
                        ending = static_cast<int>(m_kProcessData.FUN_00621b00()) +
                                 reinterpret_cast<int>(
                                     reinterpret_cast<BSSimpleList<TESPackage*>*>(context.previous->FUN_0041d8a0())
                                         ->GetNext());
                    else
                        ending = context.previous->FUN_0041d8a0()->FUN_0086a460() +
                                 reinterpret_cast<int>(
                                     reinterpret_cast<BSSimpleList<TESPackage*>*>(context.previous->FUN_0041d8a0())
                                         ->GetNext());
                    if (ending > 23)
                        ending -= 23;
                    else if (context.hour < context.previous->FUN_0041d8a0()->FUN_0086a460())
                        changed = true;
                    if (static_cast<int>(context.hour) >= ending)
                        changed = true;
                    if (!changed && force && !actor->IsInCombat())
                        force = false;
                    if (sentEnd)
                    {
                        Script::GetLocalData(context.previous, actor->GetExtraData(), 0x400);
                        if (context.previous && context.previous->IsMustReachLocation())
                            actor->vfn_28c(context.previous, static_cast<unsigned char>(g_calendar.GetGameHour()));
                    }
                }
            }
            else if (context.previous->FUN_0067efd0())
            {
                if (reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(actor)->GetProcess())->vfn_11c() ||
                    (context.previous->GetProcedureType() != -1 &&
                     DAT_011a3ff0[context.previous->GetProcedureType()][GetProcedureIndex()] == 54))
                {
                    if (context.previous && context.previous->IsMustReachLocation())
                        actor->vfn_28c(context.previous, static_cast<unsigned char>(g_calendar.GetGameHour()));
                    changed = true;
                }
                else
                {
                    changed = false;
                    force = false;
                }
            }
            else if (context.previous->FUN_008b1ff0() && !actor->IsInCombat())
            {
                if (context.previous->GetProcedureType() != -1 &&
                    (context.previous->IsPackageRunningForActor(actor, 0, -1.0f, false) ||
                     DAT_011a3ff0[context.previous->GetProcedureType()][GetProcedureIndex()] == 54))
                {
                    if (DAT_011a3ff0[context.previous->GetProcedureType()][GetProcedureIndex()] == 54 &&
                        context.previous && context.previous->IsMustReachLocation())
                        actor->vfn_28c(context.previous, static_cast<unsigned char>(g_calendar.GetGameHour()));
                    changed = true;
                }
                else
                    force = false;
            }
            else
                changed = true;
            if (changed || (force && !context.previous->UsesPackageAnimation()))
            {
                if (context.previous->IsMustComplete())
                {
                    actor->SetSpeakingState(false);
                    if (GetCurrentPackage() && context.previous == GetCurrentPackage())
                    {
                        UpdateCurrentPackage(actor);
                        vfn_234();
                    }
                    context.previous = 0;
                }
                if (!SelectNextPackage(actor))
                    return false;
                TESPackage* current = GetCurrentPackage();
                if (context.previous && context.previous != current &&
                    (!current || !current->IsPackageBlockingGreeting()))
                {
                    if (context.previous->FUN_008840f0() && g_thePlayer->GetParentCell() == actor->GetParentCell())
                    {
                        if (GetProcedureIndex())
                            vfn_4e4(true);
                        vfn_230(context.previous, actor);
                        return false;
                    }
                }
                else
                    changed = false;
            }
        }
        if (changed)
        {
            if (context.previous && GetCurrentPackage() != context.previous)
            {
                if (context.previous->IsFlag10Set())
                    g_dataHandler->GetReferencesInArea(
                        actor->GetParentCell(), *actor->GetPos(), runtimeFloatSettingDefault247, *actor->GetPos(),
                        runtimeFloatSettingDefault247, HandlePackageLocationLoaded, reinterpret_cast<long>(actor));
                else if (context.previous->IsFlag80Set())
                    g_dataHandler->GetReferencesInArea(
                        actor->GetParentCell(), *actor->GetPos(), runtimeFloatSettingDefault247, *actor->GetPos(),
                        runtimeFloatSettingDefault247, HandlePackageTargetLoaded, reinterpret_cast<long>(actor));
            }
            if (GetCurrentPackage() && GetCurrentPackage() != context.previous)
            {
                if (GetCurrentPackage()->FUN_005394a0())
                    g_dataHandler->GetReferencesInArea(
                        actor->GetParentCell(), *actor->GetPos(), runtimeFloatSettingDefault247, *actor->GetPos(),
                        runtimeFloatSettingDefault247, HandlePackageLocationLoaded, reinterpret_cast<long>(actor));
                else if (GetCurrentPackage()->FUN_00670ed0())
                    g_dataHandler->GetReferencesInArea(
                        actor->GetParentCell(), *actor->GetPos(), runtimeFloatSettingDefault247, *actor->GetPos(),
                        runtimeFloatSettingDefault247, HandlePackageTargetLoaded, reinterpret_cast<long>(actor));
            }
            if (GetCurrentPackage() && (context.previous != GetCurrentPackage() || !actor->vfn_2c8()) &&
                GetCurrentPackage()->HasTargetForActor(actor) && GetCurrentPackage()->GetPackType() != 0)
                SetTarget(GetCurrentPackage()->GetTargetForActor(actor, false));
            actor->RefreshPackageState();
            vfn_1c0(false);
            actor->RelocateTo(actor->GetParentWorldSpace(), actor->GetParentCell(), *actor->GetPos(),
                              reinterpret_cast<const NiPoint3*>(reinterpret_cast<TESRecipe*>(actor)->GetData())->z);
            vfn_4e4(false);
            SetTarget(0);
            TESPackage* interrupt = vfn_20c();
            if (interrupt && interrupt->GetPackType() != 26)
                vfn_214();
            vfn_118(0);
            SetFlag40(0);
            vfn_4ec(false);
            while (!reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).IsEmpty())
            {
                TargetDoorController* item = reinterpret_cast<TargetDoorController*&>(
                    reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).GetItem());
                delete reinterpret_cast<Date*>(item);
                reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
                    .Remove(reinterpret_cast<TESPackage* const&>(item));
            }
        }
        if (changed)
        {
            vfn_598(actor, GetCurrentPackage());
            vfn_5a8(false);
        }
        return changed;
    }
}

// Selects a package for the actor from its package list, applies its location and teleport, fires package events, and updates the high process.
// @fnv 0x0090c3e0
void LowProcess::SetMobileObjectState(MobileObject* mobile, bool runEvents)
{
    Actor* actor = dynamic_cast<Actor*>(mobile);
    TESPackage* previous = GetCurrentPackage();
    if ((actor && !previous) ||
        (!previous->FUN_0067efd0() && !previous->UsesPackageAnimation() && !previous->FUN_008b1ff0()))
    {
        struct MissedPackageState
        {
            TESObjectCELL* cell;
            TESWorldSpace* world;
            BSSimpleList<TESPackage*>* cursor;
            BSSimpleList<TESPackage*>* list;
        } state;
        state.list = reinterpret_cast<BSSimpleList<TESPackage*>*>(new BSSimpleList<TESBoundObject*>);
        actor->GetApplicablePackages(state.list,
                                     static_cast<float>(reinterpret_cast<ActorMover*>(this)->GetCurrentMoveModeType()));
        state.cursor = state.list;
        state.cell = 0;
        state.world = 0;
        bool teleport = false;
        if (!state.cursor->IsEmpty())
        {
            while (state.cursor && !state.cursor->IsEmpty())
            {
                struct PackageContext
                {
                    TESObjectREFR* targetRef;
                    TESPackage* package;
                    PackageTargetRecord* target;
                } context;
                context.package = state.cursor->GetItem();
                context.targetRef = 0;
                context.target = context.package->GetTarget();
                if (context.target)
                    context.targetRef = context.target->GetReferenceTarget();
                vfn_1c0(false);
                if (context.package->GetConditions()->ContainsTrait(actor, context.targetRef))
                {
                    if (runEvents)
                    {
                        Script::GetLocalData(context.package, actor->GetExtraData(), 0x200);
                        Script::GetLocalData(GetCurrentPackage(), actor->GetExtraData(), 0x400);
                    }
                    vfn_230(context.package, actor);
                    actor->RefreshPackageState();
                    SetGenericLocationsForPackage(actor, false);
                    switch (context.package->GetPackType())
                    {
                    case 5:
                    case 6:
                        actor->SetLocationOnReference(context.package->GetPackageLocationPosition(actor));
                        state.cell = context.package->GetPackageLocationCell(actor);
                        state.world = context.package->GetPackageWorldSpace(actor);
                        if (reinterpret_cast<LocationDescriptor*>(
                                reinterpret_cast<BGSMessageInitAccess*>(context.package)->GetIconFormID()) &&
                            reinterpret_cast<LocationDescriptor*>(
                                reinterpret_cast<BGSMessageInitAccess*>(context.package)->GetIconFormID())
                                    ->GetLocType() == 1)
                            teleport = true;
                        else
                            teleport = false;
                        break;
                    case 0:
                        if (!context.package->GetTarget())
                        {
                            actor->SetLocationOnReference(context.package->GetPackageLocationPosition(actor));
                            state.cell = context.package->GetPackageLocationCell(actor);
                            state.world = context.package->GetPackageWorldSpace(actor);
                            teleport = false;
                        }
                        else
                        {
                            TESObjectREFR* reference = context.package->GetTarget()->GetReferenceTarget();
                            if (reference && !reference->IsDeleted())
                            {
                                actor->SetLocationOnReference(*reference->GetPos());
                                teleport = true;
                                if (!reference->IsActor() && !reference->GetDisabled() && !reference->IsDeleted())
                                    reference->Activate(actor, false, 0, 1);
                                state.cell = reference->GetParentCell();
                                state.world = reference->GetParentWorldSpace();
                            }
                            else
                            {
                                actor->SetLocationOnReference(context.package->GetPackageLocationPosition(actor));
                                state.cell = context.package->GetPackageLocationCell(actor);
                                state.world = context.package->GetPackageWorldSpace(actor);
                                teleport = false;
                            }
                        }
                        break;
                    case 3:
                        actor->SetLocationOnReference(context.package->GetPackageLocationPosition(actor));
                        state.cell = context.package->GetPackageLocationCell(actor);
                        state.world = context.package->GetPackageWorldSpace(actor);
                        if (reinterpret_cast<LocationDescriptor*>(
                                reinterpret_cast<BGSMessageInitAccess*>(context.package)->GetIconFormID()) &&
                            reinterpret_cast<LocationDescriptor*>(
                                reinterpret_cast<BGSMessageInitAccess*>(context.package)->GetIconFormID())
                                ->GetLocationReference())
                            teleport = true;
                        else
                            teleport = false;
                        break;
                    case 4:
                        actor->SetLocationOnReference(context.package->GetPackageLocationPosition(actor));
                        state.cell = context.package->GetPackageLocationCell(actor);
                        state.world = context.package->GetPackageWorldSpace(actor);
                        if (reinterpret_cast<LocationDescriptor*>(
                                reinterpret_cast<BGSMessageInitAccess*>(context.package)->GetIconFormID()) &&
                            reinterpret_cast<LocationDescriptor*>(
                                reinterpret_cast<BGSMessageInitAccess*>(context.package)->GetIconFormID())
                                ->GetLocationReference())
                            teleport = true;
                        else
                            teleport = false;
                        break;
                    case 1:
                        if (context.package->GetTarget() && (context.package->GetTarget()->GetReferenceTarget() ||
                                                             context.package->GetTarget()->GetTargetForm() ||
                                                             context.package->GetTarget()->GetTargetObjectType()))
                        {
                            TESObjectREFR* reference = context.package->GetTarget()->GetReferenceTarget();
                            if (reference && !reference->IsDeleted() && reference != g_thePlayer)
                            {
                                actor->SetLocationOnReference(*reference->GetPos());
                                state.cell = reference->GetParentCell();
                                state.world = reference->GetParentWorldSpace();
                                teleport = false;
                            }
                        }
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 14:
                        ProcessGuard(actor);
                        break;
                    default:
                        break;
                    }
                    actor->RefreshPackageState();
                    if (context.package->IsMustReachLocation())
                        actor->vfn_28c(context.package, static_cast<unsigned char>(g_calendar.GetGameHour()));
                    if (context.package->IsFlag10Set())
                        g_dataHandler->GetReferencesInArea(
                            actor->GetParentCell(), *actor->GetPos(), runtimeFloatSettingDefault247, *actor->GetPos(),
                            runtimeFloatSettingDefault247, HandlePackageLocationLoaded, reinterpret_cast<long>(actor));
                    else if (context.package->IsFlag80Set())
                        g_dataHandler->GetReferencesInArea(
                            actor->GetParentCell(), *actor->GetPos(), runtimeFloatSettingDefault247, *actor->GetPos(),
                            runtimeFloatSettingDefault247, HandlePackageTargetLoaded, reinterpret_cast<long>(actor));
                }
                state.cursor = state.cursor->GetNext();
            }
            if (state.list)
                state.list->RemoveAll();
            delete reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(state.list);
            if (state.cell || state.world)
            {
                if (teleport)
                    actor->FUN_00575770(3.402823466e38f);
                TESObjectREFR::SetParentCellAndWorldspace(actor, state.cell, state.world);
                vfn_234();
                UpdateCurrentPackage(actor);
            }
        }
        delete reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(state.cursor);
    }
    reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(actor)->GetProcess())->vfn_1c0(false);
}

// @fnv 0x009082d0
TESObjectREFR* LowProcess::ResolvePackageTarget(Actor* actor, TESPackage* package)
{
    if (!package)
        return 0;
    TESObjectREFR* result = 0;
    bool current = false;
    if (package == GetCurrentPackage())
        current = true;
    if (package->GetTarget())
    {
        PackageTargetRecord* target = package->GetTarget();
        if (target->GetTargetKind() == 0)
        {
            if (!target->GetReferenceTarget())
                return result;
            if (target->GetReferenceTarget()->vfn_22c(true))
            {
                package->AssignTargetReference(target->GetReferenceTarget(), true);
                return result;
            }
            switch (package->GetPackType())
            {
            case 1:
            case 2:
            case 7:
                if (package->HasTargetForActor(actor))
                {
                    result = package->GetTargetForActor(actor, false);
                    break;
                }
            case 13: {
                PatrolActorPackageData* patrol = GetCurrentPackageData();
                if (patrol)
                    result = patrol->GetCurrentPatrolReference();
                if (!pTarget)
                    result = PatrolActorPackageData::GetPatrolReference(actor, package);
                break;
            }
            default:
                result = target->GetReferenceTarget();
                break;
            }
            if (result && result->IsDeleted() && !result->IsActor() && result->GetExtraData())
                result = result->GetExtraData()->GetReplacementReference();
        }
        else if (target->GetTargetKind() == 3)
            result = actor->GetLinkedRef();
        else if (package->FUN_0067efd0())
        {
            if (reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).IsEmpty())
            {
                struct SearchContext
                {
                    PackageTargetRecord* remaining;
                    PackageTargetRecord* searchTarget;
                    TESPackage* search;
                    int type;
                    float radius;
                    TESObjectCELL* cell;
                    NiPoint3 location;
                } context;
                switch (package->GetPackType())
                {
                case 1:
                case 2:
                case 7:
                    if (package->HasTargetForActor(actor))
                    {
                        result = package->GetTargetForActor(actor, false);
                        break;
                    }
                case 13: {
                    PatrolActorPackageData* patrol = 0;
                    if (current)
                    {
                        patrol = GetCurrentPackageData();
                        if (patrol)
                            result = patrol->GetCurrentPatrolReference();
                    }
                    if (!result)
                        result = PatrolActorPackageData::GetPatrolReference(actor, package);
                    break;
                }
                default: {
                    context.cell = actor->GetParentCell();
                    context.location = *actor->GetPos();
                    context.searchTarget = package->GetTarget();
                    context.type = context.searchTarget->GetTargetKind();
                    if (context.type == 1)
                    {
                        TESForm* object = context.searchTarget->GetTargetForm();
                        if (object->GetFormType() == 85)
                        {
                            if (!m_pFormList)
                            {
                                m_pFormList = static_cast<BGSListForm*>(object);
                                m_sFourthValue = 0;
                            }
                            else
                                ++m_sFourthValue;
                            BSSimpleList<TESForm*>* list = m_pFormList->GetList();
                            if (!list->IsEmpty())
                            {
                                int index = 0;
                                while (list && !list->IsEmpty() && m_sFourthValue <= index)
                                {
                                    TESForm* item = list->GetItem();
                                    list = list->GetNext();
                                    ++index;
                                }
                            }
                            if (object)
                                m_pBoundObject74 = reinterpret_cast<TESBoundObject*>(object);
                            m_eReferenceTypeInfo = static_cast<PACKAGE_OBJECT_TYPE>(0);
                        }
                        else if (object->GetFormType() == 8)
                        {
                            PackageFactionTarget = static_cast<TESFaction*>(object);
                            m_eReferenceTypeInfo = static_cast<PACKAGE_OBJECT_TYPE>(28);
                        }
                        else
                        {
                            m_pBoundObject74 = reinterpret_cast<TESBoundObject*>(context.searchTarget->GetTargetForm());
                            m_eReferenceTypeInfo = static_cast<PACKAGE_OBJECT_TYPE>(0);
                        }
                    }
                    else if (context.type == 2)
                    {
                        m_pBoundObject74 = 0;
                        m_eReferenceTypeInfo = context.searchTarget->GetTargetObjectType();
                    }
                    context.radius = 0.0f;
                    context.search = package;
                    if (package->HasSecondLocation())
                    {
                        unsigned int distance = context.search->FUN_006758a0(actor);
                        context.cell = context.search->GetPackageSecondLocationCell(actor);
                        context.location = context.search->GetPackageSecondLocationPosition(actor);
                        context.radius =
                            distance > 0 ? static_cast<float>(distance)
                            : context.cell->IsCellInterior()
                                ? 3.402823466e38f
                                : reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting132)
                                      .Float()
                                      ->f;
                        g_dataHandler->GetReferencesInArea(context.cell, context.location, context.radius,
                                                           context.location, context.radius, CheckPackageMatch,
                                                           reinterpret_cast<long>(actor));
                    }
                    else
                    {
                        if (!package || !package->GetPackageSearchRadius(actor, context.radius))
                            context.radius =
                                reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting132)
                                    .Float()
                                    ->f;
                        g_dataHandler->GetReferencesInArea(context.cell, context.location, context.radius,
                                                           *actor->GetPos(), context.radius, CheckPackageMatch,
                                                           reinterpret_cast<long>(actor));
                    }
                    m_eReferenceTypeInfo = static_cast<PACKAGE_OBJECT_TYPE>(0);
                    m_pBoundObject74 = 0;
                    vfn_818(actor);
                    context.remaining = package->GetTarget();
                    if (context.remaining && context.remaining->GetTargetKind() != 0)
                        m_iValue58 = package->GetPackageTargetType();
                    break;
                }
                }
            }
            if (!reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).IsEmpty())
            {
                m_pDetectionData60 = reinterpret_cast<TargetDoorController*&>(
                    reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).GetItem());
                if (m_pDetectionData60->eType == 2)
                {
                    if (m_pDetectionData60->pObject->IsActor())
                        result = m_pDetectionData60->pObject;
                    else
                    {
                        TESFaction* faction = dynamic_cast<TESFaction*>(m_pDetectionData60->pObject->GetOwner());
                        if (faction)
                            result = DAT_011e0e80.GetValueFromForm(faction, false);
                    }
                }
                else
                    result = m_pDetectionData60->pObject;
                reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
                    .Remove(reinterpret_cast<TESPackage* const&>(m_pDetectionData60));
            }
        }
    }
    if (result && result->IsDeleted() && result->GetExtraData()->GetReplacementReference())
        result = result->GetExtraData()->GetReplacementReference();
    return result;
}

// Resolves the current package's activation target and activates it for the actor, handling acquire vs. non-acquire paths, containers, and the player.
// @fnv 0x0090d620
bool LowProcess::ProcessActivate(Actor* actor, bool acquire)
{
    TESPackage* package = 0;
    package = GetCurrentPackage();
    if (!pTarget || pTarget->IsDeleted())
        FindPackageTarget(actor);
    if (!pTarget)
    {
        if (acquire)
            SetProcessTarget(actor, 2);
        return false;
    }
    else
    {
        struct ActivationTarget
        {
            PackageTargetRecord* m_pTargetRecord;
            float fTimeDelta;
            float fRadius;
            TESObjectREFR* pLocation;
        } context;
        context.m_pTargetRecord = package->GetTarget();
        if (context.m_pTargetRecord->GetTargetKind() == 0 || context.m_pTargetRecord->GetTargetKind() == 3)
            m_iValue58 = 0;
        context.pLocation = package->FUN_00676140(actor);
        if (context.pLocation && context.pLocation->FUN_00568680() &&
            (pTarget->GetObjectReference() == DAT_011ca248 || pTarget->GetObjectReference() == DAT_011ca244))
            return true;
        if (package->GetPackType() == 9 &&
            !package->IsPackageRunningForActor(actor, 0, runtimeFloatSettingDefault7, false))
            SetProcessTarget(actor, -2);
        context.fTimeDelta = GetActorTimeDelta(actor);
        bool bPickResultFound = false;
        context.fRadius = GetCurrentPackage()->GetPackageResult(actor, false);
        if (pTarget && context.fRadius < actor->GetDistanceToReference(pTarget, false, false) && actor->FUN_008b3bb0())
        {
            PROCESS_TYPE eProcessType = actor->GetCurrentProcessLevel();
            if (!actor->DispatchWithObj(pTarget, -1.0f, 0))
                return false;
            if (actor->GetCurrentProcessLevel() != eProcessType)
                return true;
        }
        bPickResultFound = package->vfn_144(actor, false);
        if (bPickResultFound)
        {
            TESObjectREFR* activated = pTarget;
            TESBoundObject* activationItem;
            if (acquire)
            {
                bool bIsContainer;
                int iCount;
                activationItem = 0;
                iCount = 1;
                bIsContainer = false;
                if (m_pDetectionData60)
                {
                    if (!m_pDetectionData60->pObject || m_pDetectionData60->pObject->vfn_22c(false) ||
                        !m_pDetectionData60->pObject->vfn_218())
                    {
                        activationItem = m_pDetectionData60->pItem;
                        iCount = m_pDetectionData60->iCount;
                        m_iValue58 -= iCount;
                        if (m_pDetectionData60->pObject->vfn_22c(false))
                            bIsContainer = true;
                    }
                    if (m_iValue58 <= 0)
                        SetProcessTarget(actor, 2);
                }
                if (!pTarget->IsActor() || bIsContainer)
                {
                    pTarget->Activate(actor, true, activationItem, iCount);
                    delete reinterpret_cast<Date*>(m_pDetectionData60);
                    m_pDetectionData60 = 0;
                    SetTarget(0);
                    SetProcessTarget(actor, 2);
                }
                else if (pTarget->IsActor())
                {
                    if (pTarget == g_thePlayer && g_thePlayer->IsSleepingOrResting() && !g_thePlayer->bResting)
                    {
                        g_thePlayer->FUN_005c1a00(false, 0);
                        return false;
                    }
                    else if (m_pDetectionData60)
                    {
                        if (m_pDetectionData60->m_bUseSpecialAction)
                            vfn_33c(actor, pTarget, 0, 0, 0, 0, true, 0, true, 0, 0, true, 0);
                        else if (m_pDetectionData60->bActivate)
                        {
                            pTarget->Activate(actor, true, m_pDetectionData60->pItem, iCount);
                            delete reinterpret_cast<Date*>(m_pDetectionData60);
                            m_pDetectionData60 = 0;
                            SetTarget(0);
                        }
                    }
                    else if (pTarget != g_thePlayer)
                    {
                        SetProcessTarget(actor, 2);
                        return false;
                    }
                }
            }
            else if (!pTarget->IsActor())
                pTarget->Activate(actor, false, 0, 1);
            else if (package->GetPackType() == 2)
                reinterpret_cast<HighProcess*>(reinterpret_cast<Actor*>(actor)->GetProcess())
                    ->SetProcessTarget(actor, 2);
            else if (pTarget == g_thePlayer && g_thePlayer->IsSleepingOrResting() && !g_thePlayer->bResting)
            {
                g_thePlayer->FUN_005c1a00(false, 1);
                return false;
            }
            else
                return true;
            if (activated)
                activated->FUN_00565870();
            return true;
        }
    }
    return false;
}

// @fnv 0x00908f70
void LowProcess::ProcessAcquire(Actor* actor)
{
    PackageTargetRecord* target = 0;
    if (!pTarget)
        FindPackageTarget(actor);
    if (pTarget)
        target = GetCurrentPackage()->GetTarget();
    if (pTarget && (GetCurrentPackage()->GetPackType() == 8 || GetCurrentPackage()->GetPackType() == 16))
    {
        ENUM_FORM_ID type = pTarget->GetObjectReference()->GetFormType();
        switch (type)
        {
        case 21:
        case 27:
        case 28:
        case 32:
        case 33:
        case 36:
        case 37:
        case 38:
        case 39:
        case 42:
        case 43:
        case 44:
        case 45:
        case 59:
        case 60:
            SetProcessTarget(actor, 1);
            return;
            break;
        case 30: {
            TESObjectLIGH* light = dynamic_cast<TESObjectLIGH*>(pTarget->GetObjectReference());
            if (light && !light->FUN_0046f070())
                SetProcessTarget(actor, 1);
            return;
        }
        }
    }
    if ((target && target->GetReferenceTarget()) || GetCurrentPackage()->FUN_0067efd0())
    {
        int count = 1;
        if (GetCurrentPackage()->GetTarget())
            count = GetCurrentPackage()->GetPackageTargetType();
        if (vfn_80c(actor, count))
        {
            if (!GetCurrentPackage()->IsPackageRunningForActor(actor, 0, -1.0f, false) &&
                GetCurrentPackage()->GetPackType() == 3)
                SetProcedureIndex(0);
            else if (GetCurrentPackage()->GetProcedureType() == 26 &&
                     !reinterpret_cast<int>(
                         reinterpret_cast<BSSimpleList<TESPackage*>*>(GetCurrentPackage()->FUN_0041d8a0())->GetNext()))
                SetProcessTarget(actor, 2);
            else
                SetProcessTarget(actor, 1);
            if (GetCurrentPackage()->GetPackType() == 2)
                vfn_7b4(actor);
            return;
        }
        {
            if (actor->GetCurrentProcessLevel() < 2)
                vfn_74(actor, 3600.0f);
            else
                ProcessActivate(actor, true);
        }
    }
    else
    {
        if (GetCurrentPackage()->GetProcedureType() == 26)
            SetProcessTarget(actor, 2);
        else
            SetProcessTarget(actor, 1);
    }
}

// Moves the actor toward the patrol reference, running or teleporting as needed, and returns the remaining time delta.
// @fnv 0x009125b0
float LowProcess::RunProcessUpdate(Actor* actor, PatrolActorPackageData* patrol, float delta)
{
    bool bSameCell;
    {
        TESObjectREFR* pPatrolRef = patrol->GetCurrentPatrolReference();
        if (!pPatrolRef)
        {
            SetProcedureIndex(-1);
            return 0.0f;
        }
        float fTimeDelta = delta;
        bool teleportActor = false;
        bool bPackageWantsRun;
        {
            bool bRun;
            struct TravelContext
            {
                TESObjectCELL* pActorCell;
                TESObjectCELL* pTargetCell;
                int uiMoveMode;
                TESPackage* pPackage;
            } context;
            context.pActorCell = actor->GetParentCell();
            context.pTargetCell = pPatrolRef->GetParentCell();
            bSameCell = context.pActorCell && context.pActorCell == context.pTargetCell;
            if (g_thePlayer->IsSleepingOrResting())
                teleportActor = true;
            else
                teleportActor = !(context.pActorCell && g_TES->IsCellBuffered(context.pActorCell, false)) &&
                                !(context.pTargetCell && g_TES->IsCellBuffered(context.pTargetCell, false));
            if (!teleportActor && actor->IsActorEssential())
            {
                ProcessPatrolPackage(actor, patrol);
                return fTimeDelta;
            }
            context.uiMoveMode = 0x101;
            context.pPackage = vfn_27c();
            bPackageWantsRun = context.pPackage->FUN_0067a480();
            bRun = false;
            if (bPackageWantsRun)
            {
                float distance = actor->GetDistanceToReference(pPatrolRef, false, false);
                float threshold = 64.0f;
                bRun = distance > threshold;
                if (bRun)
                {
                    float speed = context.pPackage->GetActorMovementSpeed(actor, false);
                    context.uiMoveMode = vfn_34c(actor, distance, speed, speed * 2.0f, false, false);
                }
            }
            vfn_350(actor, context.uiMoveMode, bRun);
            if (teleportActor)
            {
                float speed = FUN_00404010(actor->GetCurrentMovementSpeed(), 1.0f);
                float distance;
                if (bSameCell)
                {
                    const NiPoint3& kPoint = *pPatrolRef->GetPos();
                    NiPoint3 difference = kPoint;
                    difference.Subtract(*actor->GetPos());
                    distance = difference.FUN_00457990();
                }
                else
                {
                    PathingLocation start(actor), end(pPatrolRef);
                    distance = Pathing::FindPathDistance(start, end, 4096.0f, 0, Pathing::kIgnoreLocks);
                }
                fTimeDelta -= distance / speed;
                actor->FUN_008ad910(pPatrolRef, true, false);
                HandlePatrolArrival(actor, patrol);
            }
            else if (actor->HasEssentialStatus())
                HandlePatrolArrival(actor, patrol);
            else
                fTimeDelta = 0.0f;
            return fTimeDelta;
        }
    }
}

// @fnv 0x00912b00
void LowProcess::ProcessGuard(Actor* actor)
{
    struct GuardState
    {
        PackageTargetRecord* m_pTargetRecord;
        TESObjectREFR* m_pWorldReferenceInfo;
        float fRadius;
        TESObjectREFR* pGuardTarget;
        PatrolActorPackageData* pGuardData;
        TESPackage* pPackage;
    } state;
    bool bAtLocation;
    state.pGuardData = GetCurrentPackageData();
    if (vfn_20c() && vfn_20c()->GetPackType() == 14)
        state.pGuardData = vfn_270();
    if (!state.pGuardData)
    {
        SetProcedureIndex(-1);
        return;
    }
    state.pPackage = vfn_27c();
    state.pGuardTarget = state.pPackage->GetResolvedTargetReference(actor);
    state.pGuardTarget = state.pGuardTarget ? state.pGuardTarget : actor;
    state.m_pWorldReferenceInfo = state.pGuardTarget->GetExtraData()->GetReplacementReference();
    state.pGuardTarget = state.m_pWorldReferenceInfo ? state.m_pWorldReferenceInfo : state.pGuardTarget;
    if (vfn_128() != state.pGuardTarget)
    {
        SetTarget(state.pGuardTarget);
        state.pGuardTarget->GetExtraData()->AddGuardingActor(actor);
        state.pGuardTarget->MarkAsModified(0x80000000);
    }
    if (!vfn_35c() && (actor->Unk_85() == 4 || actor->Unk_85() == 9))
    {
        reinterpret_cast<CombatProcedure*>(state.pGuardData)->Initialize(0);
        actor->Unk_106();
        return;
    }
    bAtLocation = true;
    state.fRadius = 0.0f;
    if (!actor->vfn_4b4())
    {
        if (reinterpret_cast<LocationDescriptor*>(
                reinterpret_cast<BGSMessageInitAccess*>(state.pPackage)->GetIconFormID()))
        {
            bAtLocation = state.pPackage->IsPackageRunningForActor(actor, 0, -1.0f, false);
            state.fRadius = static_cast<float>(state.pPackage->FUN_00676280(actor));
        }
        else
        {
            state.m_pTargetRecord = state.pPackage->GetTarget();
            state.fRadius =
                state.m_pTargetRecord
                    ? static_cast<float>(static_cast<int>(
                          reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(state.m_pTargetRecord)->GetSize()))
                    : runtimeFloatSettingDefault51;
            bAtLocation = state.fRadius > actor->GetDistanceToReference(state.pGuardTarget, false, false);
        }
        if ((actor->HasEssentialStatus() && !bAtLocation) || actor->IsActorEssential())
            vfn_7f8(actor, state.pGuardData);
    }
}

// @fnv 0x00909de0
void LowProcess::UpdateActorPackage(Actor* actor, bool flag, int value, bool other)
{
    if (GetCurrentPackage() && GetCurrentPackage()->HasEssentialStatus())
    {
        if (!g_thePlayer->IsActorInCombatWithPlayer(actor))
        {
            if (g_thePlayer->GetCharacterLevel() < DAT_011cdad0.Int()->i)
                GetCurrentPackage()->SetWaiting(false);
            else
                return;
        }
        else
            return;
    }
    if (!pTarget)
        FindPackageTarget(actor);
    if (!pTarget || (reinterpret_cast<LocationDescriptor*>(
                         reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID()) &&
                     GetCurrentPackage()->IsPackageRunningForActor(actor, 0, -1.0f, false) &&
                     GetCurrentPackage()->GetPackType() == 1))
    {
        SetProcessTarget(actor, 1);
        if (GetCurrentPackage()->IsMustComplete())
        {
            UpdateCurrentPackage(actor);
            vfn_234();
            CanProcessActor(actor, false);
        }
        return;
    }
    {
        struct FollowState
        {
            TESWorldSpace* pActorWorld;
            float fRadius;
            TESWorldSpace* pTargetWorld;
        } location;
        float fTimeDelta;
        bool bSameWorldspace;
        fTimeDelta = GetActorTimeDelta(actor);
        location.fRadius = GetCurrentPackage()->GetPackageLocationRadius(actor, false);
        bSameWorldspace = true;
        location.pActorWorld = actor->GetParentWorldSpace();
        location.pTargetWorld = pTarget->GetParentWorldSpace();
        if (location.pActorWorld != location.pTargetWorld)
            bSameWorldspace = false;
        if (actor->HasEssentialStatus() && pTarget &&
            (!bSameWorldspace || location.fRadius < actor->GetDistanceToReference(pTarget, false, false)))
        {
            actor->IsAtPosition(*pTarget->GetPos(), pTarget->GetParentCell(), pTarget->GetParentWorldSpace(),
                                location.fRadius, 0);
        }
    }
}

// @fnv 0x00912340
void LowProcess::ProcessPatrolPackage(Actor* actor, PatrolActorPackageData* patrol)
{
    TESObjectREFR* pPatrolRef = patrol->GetCurrentPatrolReference();
    if (!pPatrolRef)
    {
        SetProcedureIndex(-1);
        return;
    }
    SetTarget(pPatrolRef);
    bool bSkipRequest = false;
    if (g_thePlayer->IsSleepingOrResting())
        bSkipRequest = true;
    else if (!actor->GetNiNode())
    {
        TESObjectCELL* pActorCell = actor->GetParentCell();
        TESObjectCELL* pRefCell = pPatrolRef->GetParentCell();
        bSkipRequest = !(pActorCell && g_TES->IsCellBuffered(pActorCell, false)) &&
                       !(pRefCell && g_TES->IsCellBuffered(pRefCell, false));
    }
    if (!bSkipRequest)
    {
        float fRadius = FUN_006e25d0();
        struct PatrolRequestState
        {
            TESBoundObject* object;
            TESPackage* package;
        } context;
        context.package = vfn_27c();
        if (context.package)
            fRadius = FUN_00404010(fRadius, static_cast<float>(context.package->FUN_00676280(actor)));
        PathingRequest pathRequest;
        actor->InitializePathingRequestFromPosition(&pathRequest, *pPatrolRef->GetPos(), pPatrolRef->GetParentCell(),
                                                    pPatrolRef->GetParentWorldSpace(), fRadius, 0);
        pathRequest.SetUseSoft(false);
        context.object = pPatrolRef->GetObjectReference();
        if (context.object->GetFormType() == 48 || context.object == DAT_011ca248)
            pathRequest.SetTargetAngle(
                reinterpret_cast<const NiPoint3*>(reinterpret_cast<TESRecipe*>(pPatrolRef)->GetData())->z);
        actor->SetPathingRequestAvoidNodes(&pathRequest);
    }
    patrol->eState = PatrolActorPackageData__PATROL_STATE_PATROL_STATE_TRAVELING_TO_NEXT_REF;
}

// Calls BaseProcess::InitLoadGame, resolves pTarget and several reference fields via dynamic_cast, then walks a BSSimpleList removing entries that fail the cast.
// @fnv 0x00910820
void LowProcess::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    BaseProcess::InitLoadGame(buffer);
    struct TargetFixup
    {
        TESObjectREFR** targetAddress;
        TESObjectREFR* reference;
    } targetFixup;
    targetFixup.reference =
        pTarget ? dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(pTarget))) : 0;
    targetFixup.targetAddress = &pTarget;
    *targetFixup.targetAddress = 0;
    SetTarget(targetFixup.reference);
    m_pReference40 =
        m_pReference40
            ? dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(m_pReference40)))
            : 0;
    m_pReference44 =
        m_pReference44
            ? dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(m_pReference44)))
            : 0;
    m_pObjectReference =
        m_pObjectReference
            ? dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(m_pObjectReference)))
            : 0;
    BSSimpleList<TESObjectREFR*>* node = &m_kReferenceList68;
    BSSimpleList<TESObjectREFR*>* m_pPreviousBlock = 0;
    while (node && !node->IsEmpty())
    {
        TESObjectREFR* item = node->GetItem();
        bool remove = false;
        if (item)
        {
            item = item ? dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(item))) : 0;
            if (item)
                node->SetItem(item);
            else
                remove = true;
        }
        else
            remove = true;
        if (remove)
        {
            if (m_pPreviousBlock)
            {
                reinterpret_cast<BSSimpleList<TESPackage*>*>(m_pPreviousBlock)
                    ->Remove(reinterpret_cast<TESPackage* const&>(node->GetItem()));
                node = m_pPreviousBlock->GetNext();
            }
            else
                node->RemoveHead();
        }
        else
        {
            m_pPreviousBlock = node;
            node = node->GetNext();
        }
    }
}

// Loads a LowProcess from a BGSLoadFormBuffer, reading version-gated fields, a bound object, a list form, and a list of items.
// @fnv 0x00910630
void LowProcess::LoadGame(BGSLoadFormBuffer* buffer)
{
    struct ReferenceItemCountEntry
    {
        TESObjectREFR* item;
        unsigned int index;
        unsigned int count;
        int oldCount;
        int oldValue;
    } state;
    BaseProcess::LoadGame(buffer);
    if (buffer->GetVersion() < 6)
    {
        buffer->ReadTypedData(&state.oldValue, 4);
        buffer->ReadTypedData(&state.oldCount, 4);
    }
    buffer->ReadTypedData(&m_uiObjectFlags, 1);
    buffer->ReadTypedData(&m_fValue88, 4);
    m_pCurrentWeapon = dynamic_cast<TESBoundObject*>(
        GetFormByID(reinterpret_cast<BGSLoadGameBuffer*>(buffer)->ReadFormIdentifier()));
    buffer->ReadTypedData(&m_iValue58, 4);
    buffer->ReadTypedData(&m_fValue8C, 4);
    buffer->ReadTypedData(&m_fValue90, 4);
    buffer->ReadTypedData(&m_bHasBoundObject, 1);
    buffer->ReadTypedData(&m_sFourthValue, 2);
    m_kProcessData38.LoadGame(buffer);
    buffer->ReadFormIdentifier(&pTarget);
    buffer->ReadFormIdentifier(&m_pReference40);
    buffer->ReadFormIdentifier(&m_pReference44);
    m_pFormList = dynamic_cast<BGSListForm*>(
        GetFormByID(reinterpret_cast<BGSLoadGameBuffer*>(buffer)->ReadFormIdentifier()));
    buffer->ReadFormIdentifier(&m_pObjectReference);
    state.count = buffer->ReadElementCount();
    for (state.index = 0; state.index < state.count; ++state.index)
    {
        state.item = 0;
        buffer->ReadFormIdentifier(&state.item);
        m_kReferenceList68.AddHead(state.item);
    }
    if (buffer->GetChangeFlags(0x200000))
        m_kActorValueModifiers.LoadGame(buffer);
}

// @fnv 0x009089c0
TESObjectREFR* LowProcess::ResolvePackageLocation(Actor* actor, TESPackage* package, bool abSecondLocation)
{
    TESObjectREFR* result = 0;
    LocationDescriptor* location = 0;
    if (abSecondLocation)
        location = package->GetPackageSecondLocation();
    else
        location =
            reinterpret_cast<LocationDescriptor*>(reinterpret_cast<BGSMessageInitAccess*>(package)->GetIconFormID());
    if (location)
    {
        if (!location->GetLocType())
            result = location->GetLocationReference();
        if (location->GetLocType() == 6)
        {
            result = actor->GetLinkedRef();
        }
        else if (location->FUN_0067f970() && package->FUN_0067efd0())
        {
            if (m_kReferenceList68.IsEmpty())
            {
                struct SearchState
                {
                    BSSimpleList<TESObjectREFR*>* node;
                    int type;
                    float radius;
                    TESObjectCELL* cell;
                } search;
                search.cell = actor->GetParentCell();
                NiPoint3 point = *actor->GetPos();
                search.type = location->GetLocType();
                if (search.type == 4)
                {
                    m_pBoundObject78 = location->FUN_0067f430();
                    m_eReferenceTypeInfo = static_cast<PACKAGE_OBJECT_TYPE>(0);
                }
                else if (search.type == 5)
                {
                    m_pBoundObject78 = 0;
                    m_eReferenceTypeInfo = location->GetObjectType();
                }
                search.radius = 0.0f;
                if (!package || !package->GetPackageSearchRadius(actor, search.radius))
                    search.radius =
                        reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting132).Float()->f;
                g_dataHandler->GetReferencesInArea(search.cell, point, search.radius, *actor->GetPos(), search.radius,
                                                   FUN_0090e660, reinterpret_cast<long>(actor));
                m_eReferenceTypeInfo = static_cast<PACKAGE_OBJECT_TYPE>(0);
                m_pBoundObject78 = 0;
                search.node = &m_kReferenceList70;
                while (search.node && search.node->GetItem())
                {
                    m_kReferenceList68.AddHead(search.node->GetItem());
                    search.node->RemoveHead();
                }
            }
            if (!m_kReferenceList68.IsEmpty())
            {
                result = m_kReferenceList68.GetItem();
                m_kReferenceList68.RemoveHead();
            }
        }
    }
    return result;
}

// @fnv 0x009070a0
void LowProcess::ClearData()
{
    if (m_pDetectionData60)
    {
        if (m_pDetectionData64 == m_pDetectionData60)
            m_pDetectionData64 = 0;
        delete reinterpret_cast<Date*>(m_pDetectionData60);
        m_pDetectionData60 = 0;
    }
    if (m_pDetectionData64)
    {
        delete reinterpret_cast<Date*>(m_pDetectionData64);
        m_pDetectionData64 = 0;
    }
    while (!reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).IsEmpty())
    {
        TargetDoorController* item = reinterpret_cast<TargetDoorController*&>(
            reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).GetItem());
        reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
            .Remove(reinterpret_cast<TESPackage* const&>(item));
        delete reinterpret_cast<Date*>(item);
    }
    reinterpret_cast<BSSimpleList<TESPackage*>&>(m_kReferenceList68).RemoveAll();
    m_pReference40 = 0;
    while (!reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(m_kDetectionDataList).IsEmpty())
    {
        TargetDoorController* item = reinterpret_cast<TargetDoorController*&>(
            reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(m_kDetectionDataList).GetItem());
        reinterpret_cast<BSSimpleList<TESPackage*>&>(m_kDetectionDataList)
            .Remove(reinterpret_cast<TESPackage* const&>(item));
        delete reinterpret_cast<Date*>(item);
    }
    reinterpret_cast<BSSimpleList<TESPackage*>&>(m_kReferenceList70).RemoveAll();
    delete m_pBoundObject74;
    m_pBoundObject74 = 0;
}

// @fnv 0x0090cc10
void LowProcess::ClearReferenceRecords(TESObjectREFR* reference)
{
    if (m_pDetectionData60 && m_pDetectionData60->pObject == reference)
    {
        delete reinterpret_cast<Date*>(m_pDetectionData60);
        m_pDetectionData60 = 0;
    }
    if (m_pDetectionData64 && m_pDetectionData64->pObject == reference)
    {
        delete reinterpret_cast<Date*>(m_pDetectionData64);
        m_pDetectionData64 = 0;
    }
    BSSimpleList<TargetDoorController*>* node = &ReferenceListNode;
    while (node &&
           reinterpret_cast<TargetDoorController*&>(reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(node)->GetItem()))
    {
        TargetDoorController* item =
            reinterpret_cast<TargetDoorController*&>(reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(node)->GetItem());
        if (item->pObject == reference)
        {
            reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
                .Remove(reinterpret_cast<TESPackage* const&>(item));
            delete reinterpret_cast<Date*>(item);
            node = &ReferenceListNode;
        }
        else
            node = reinterpret_cast<BSSimpleList<TargetDoorController*>*>(
                reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(node)->GetNext());
    }
    if (m_pReference40 == reference)
        m_pReference40 = 0;
    BSSimpleList<TESObjectREFR*>* current = &m_kReferenceList68;
    BSSimpleList<TESObjectREFR*>* previous = 0;
    while (current && current->GetItem())
    {
        TESObjectREFR* item = current->GetItem();
        if (item == reference)
        {
            if (previous)
            {
                reinterpret_cast<BSSimpleList<TESPackage*>*>(previous)->Remove(
                    reinterpret_cast<TESPackage* const&>(item));
                current = previous->GetNext();
            }
            else
                current->RemoveHead();
        }
        else
        {
            previous = current;
            current = current->GetNext();
        }
    }
}

// @fnv 0x00910b30
void LowProcess::UpdateCurrentPackage(Actor* actor)
{
    vfn_118(0);
    SetFlag40(0);
    vfn_4ec(false);
    SetTarget(0);
    m_pReference40 = 0;
    if (m_pDetectionData60)
    {
        delete reinterpret_cast<Date*>(m_pDetectionData60);
        m_pDetectionData60 = 0;
    }
    if (m_pDetectionData64)
    {
        reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
            .Remove(reinterpret_cast<TESPackage* const&>(m_pDetectionData64));
        delete reinterpret_cast<Date*>(m_pDetectionData64);
        m_pDetectionData64 = 0;
    }
    while (!reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).IsEmpty())
    {
        TargetDoorController* item = reinterpret_cast<TargetDoorController*&>(
            reinterpret_cast<BSSimpleList<TESObjectREFR*>&>(ReferenceListNode).GetItem());
        delete reinterpret_cast<Date*>(item);
        reinterpret_cast<BSSimpleList<TESPackage*>&>(ReferenceListNode)
            .Remove(reinterpret_cast<TESPackage* const&>(item));
    }
    reinterpret_cast<BSSimpleList<TESPackage*>&>(m_kReferenceList68).RemoveAll();
}

// @fnv 0x00912990
float LowProcess::UpdatePatrolProgress(Actor* actor, PatrolActorPackageData* patrol, float delta)
{
    struct PatrolWait
    {
        TESObjectREFR* reference;
        float remaining;
        float wait;
    } context;
    context.reference = patrol->GetCurrentPatrolReference();
    if (!context.reference)
    {
        SetProcedureIndex(-1);
        return 0.0f;
    }
    context.wait = 0.0f;
    if (reinterpret_cast<ExtraDataListHelper*>(context.reference->GetExtraData())->GetStartingPositionData())
        context.wait = reinterpret_cast<ExtraDataListHelper*>(context.reference->GetExtraData())
                           ->GetStartingPositionData()
                           ->GetX();
    context.wait = FUN_00404010(0.0f, context.wait - patrol->m_fElapsedWaitTime);
    context.remaining = delta - context.wait;
    if (context.remaining > 0.0)
    {
        if (!patrol->AdvanceToNextReference(true))
        {
            SetProcessTarget(actor, 1);
            return 0.0f;
        }
        if (patrol->GetCurrentPatrolReference() == context.reference)
            context.remaining = 0.0f;
        else
        {
            NiPoint3 difference = *patrol->GetCurrentPatrolReference()->GetPos();
            difference.Subtract(*context.reference->GetPos());
            if (difference.FUN_004a7290() < static_cast<double>(0.001f))
                context.remaining = 0.0f;
        }
        ProcessPatrolPackage(actor, patrol);
    }
    else
        patrol->m_fElapsedWaitTime += delta;
    return context.remaining;
}

// @fnv 0x00907700
bool LowProcess::SelectNextPackage(Actor* actor)
{
    struct ScheduleState
    {
        ActorMover* mover;
        TESPackage* package;
    } context;
    context.package = actor->FUN_00881450();
    if (context.package == GetCurrentPackage())
        return false;
    vfn_230(context.package, actor);
    vfn_244();
    actor->FUN_008b3d30();
    if (GetCurrentPackage())
    {
        if (!reinterpret_cast<LocationDescriptor*>(
                reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID()) ||
            reinterpret_cast<LocationDescriptor*>(
                reinterpret_cast<BGSMessageInitAccess*>(GetCurrentPackage())->GetIconFormID())
                    ->GetLocType() == 2)
            actor->RelocateTo(actor->GetParentWorldSpace(), actor->GetParentCell(), *actor->GetPos(),
                              reinterpret_cast<const NiPoint3*>(reinterpret_cast<TESRecipe*>(actor)->GetData())->z);
    }
    context.mover = actor->vfn_428();
    if (context.mover)
        context.mover->SetupPackageTarget(context.package);
    vfn_b0(actor, context.package, false);
    return true;
}

// Advances the current package's procedure index, clamps it to the procedure count, and runs the procedure's script when its type is 54.
// @fnv 0x009119b0
void LowProcess::SetProcessTarget(MobileObject* actor, int increment)
{
    TESPackage* package = GetCurrentPackage();
    vfn_240(increment);
    if (vfn_23c() < 0)
        vfn_238(0);
    if (package)
    {
        int count = FUN_0096a820(package->GetProcedureType());
        if (vfn_23c() >= count)
            vfn_238(count - 1);
        if (DAT_011a3ff0[package->GetProcedureType()][vfn_23c()] == 54 && !vfn_5a4())
        {
            Script::GetLocalData(package, actor->GetExtraData(), 0x400);
            OnPackageEnd(static_cast<Actor*>(actor), package);
            vfn_5a8(true);
        }
    }
}

// @fnv 0x00907510
void LowProcess::HandlePackageChange(LowProcess* other)
{
    reinterpret_cast<ActiveEffect*>(this)->FUN_00693d50(reinterpret_cast<ActiveEffect*>(other)->FUN_007df1f0());
    other->m_kProcessData.MovePackageData(&m_kProcessData);
    m_uiObjectFlags = other->m_uiObjectFlags;
    m_pDetectionData60 = other->m_pDetectionData60;
    other->m_pDetectionData60 = 0;
    m_kProcessData38 = other->m_kProcessData38;
    m_pCurrentWeapon = other->m_pCurrentWeapon;
    if (other->m_pDetectionData64)
    {
        m_pDetectionData64 = other->m_pDetectionData64;
        other->m_pDetectionData64 = 0;
    }
    m_uiStateFlags = reinterpret_cast<ActorMover*>(other)->GetCurrentMoveModeType();
    SetTarget(other->pTarget);
    m_iValue58 = other->m_iValue58;
    m_kActorValueModifiers.CopyModifierListFrom(&other->m_kActorValueModifiers);
    m_fValue88 = other->m_fValue88;
    m_fValue8C = other->m_fValue8C;
    m_fValue90 = other->m_fValue90;
}

// Runs the actor's patrol package state machine, consuming the frame delta across INIT, TRAVELING_TO_NEXT_REF and AT_REF states until it is exhausted.
// @fnv 0x009121e0
void LowProcess::ProcessPatrol(Actor* actor)
{
    struct PatrolState
    {
        PatrolActorPackageData* patrol;
        float delta;
    } context;
    context.patrol = GetCurrentPackageData();
    if (!context.patrol)
    {
        SetProcedureIndex(-1);
        return;
    }
    else if (actor->Unk_85())
    {
        actor->Unk_106();
        return;
    }
    context.delta = GetActorTimeDelta(actor);
    while (context.delta > 0.0)
    {
        switch (context.patrol->eState)
        {
        case PatrolActorPackageData__PATROL_STATE_PATROL_STATE_INIT:
            if (!FindPatrolTarget(actor, context.patrol))
                context.delta = 0.0f;
            break;
        case PatrolActorPackageData__PATROL_STATE_PATROL_STATE_TRAVELING_TO_NEXT_REF:
            context.delta = RunProcessUpdate(actor, context.patrol, context.delta);
            break;
        case PatrolActorPackageData__PATROL_STATE_PATROL_STATE_AT_REF:
            context.delta = UpdatePatrolProgress(actor, context.patrol, context.delta);
            break;
        default:
            context.delta = 0.0f;
        }
    }
}

// @fnv 0x009136b0
void LowProcess::ProcessDialogueTopic(Actor* actor, TESTopic* topic, bool abUnused1, bool abUnused2, bool abUnused3,
                                      bool d)
{
    bool bInvalid;
    TESPackage* pPackage;
    {
        bool bFailedGreeting;
        bFailedGreeting = false;
        bInvalid = false;
        pPackage = GetCurrentPackage();
        TESObjectREFR* m_pReference =
            reinterpret_cast<TESObjectREFR*>(reinterpret_cast<EffectSetting*>(actor)->GetLight());
        reinterpret_cast<EffectSetting*>(actor)->SetLight(0);
        {
            DialogueItem* pDialogueItem = 0;
            if (!m_pReference)
                m_pReference = reinterpret_cast<TESObjectREFR*>(reinterpret_cast<EffectSetting*>(actor)->GetLight());
            if (reinterpret_cast<TESTopicInfo*>(topic)->HasResultScript())
            {
                pDialogueItem = topic->CreateDialogueItem(actor, m_pReference, 0, 0, true);
                if (pDialogueItem)
                {
                    pDialogueItem->SelectDefaultResponseList();
                    DialogueResponse* pResponse = pDialogueItem->GetCurrentItem();
                    if (pResponse)
                    {
                        pDialogueItem->FUN_0083c850(0);
                        if (d)
                        {
                            actor->SetDialogueTopic(topic);
                            actor->FUN_0057ace0(pDialogueItem->GetInfo());
                            HandleMobileObjectResult(actor->GetFormID(), true);
                            actor->vfn_140();
                        }
                    }
                }
            }
        }
    }
}

// @fnv 0x0090d480
bool LowProcess::HandlePackageLocationLoaded(TESObjectREFR* door, long pActor)
{
    Actor* actor = reinterpret_cast<Actor*>(pActor);
    if (actor && !actor->vfn_22c(false) && door && door->GetObjectReference()->GetFormType() == 28)
    {
        bool lock = false;
        ExtraLock* data = reinterpret_cast<ExtraLock*>(door->GetExtraRadioData());
        if (data && (data->FUN_0043a320() || !actor->GetParentCell() || !actor->GetParentCell()->IsCellInterior()))
            lock = true;
        if (door->CanBeUsed(actor, lock) && door->GetLock())
        {
            door->Lock();
            ExtraLock* current = reinterpret_cast<ExtraLock*>(door->GetExtraRadioData());
            if (current)
                current->FUN_0043a210(door, false);
        }
    }
    return false;
}

// @fnv 0x00910a60
void LowProcess::Revert(BGSLoadFormBuffer* buffer)
{
    BaseProcess::Revert(buffer);
    ClearData();
    m_iValue58 = 0;
    SetTarget(0);
    m_fValue88 = 0.0f;
    m_pCurrentWeapon = 0;
    m_kProcessData38.FUN_00910b10();
    m_fValue8C = 0.0f;
    m_uiObjectFlags = 0;
    m_fValue90 = 0.0f;
    if (buffer->GetOldChangeFlags(0x200000))
        m_kActorValueModifiers.Revert();
}

// @fnv 0x0090d570
bool LowProcess::HandlePackageTargetLoaded(TESObjectREFR* door, long aiActorPtr)
{
    Actor* actor = reinterpret_cast<Actor*>(aiActorPtr);
    if (actor && !actor->vfn_22c(false) && door && door->GetObjectReference()->GetFormType() == 28)
    {
        bool lock = false;
        ExtraLock* data = reinterpret_cast<ExtraLock*>(door->GetExtraRadioData());
        if (data)
            lock = true;
        if (door->CanBeUsed(actor, lock) && door->GetLock())
        {
            door->Unlock();
            if (data)
                data->FUN_0043a210(door, true);
        }
    }
    return false;
}

// @fnv 0x009072d0
int LowProcess::GetActorValue(TESActorBase* base, ActorValue__Index value, Actor* actor)
{
    if (ActorValue::GetFlag(value, 0x100))
        return actor->GetBaseActorValue(value);
    float permanent = 0.0f;
    if (actor)
        permanent = actor->m_kFirstActorData.GetActorValueModifierAmount(static_cast<char>(value));
    return static_cast<int>(actor->GetBaseActorValue(value) + permanent +
                            m_kActorValueModifiers.GetActorValueModifierAmount(static_cast<char>(value)));
}

// @fnv 0x00907380
float LowProcess::GetCurrentActorValue(TESActorBase* base, ActorValue__Index value, Actor* actor)
{
    if (ActorValue::GetFlag(value, 0x100))
        return actor->GetBaseActorValueFloat(value);
    float permanent = 0.0f;
    if (actor)
        permanent = actor->m_kFirstActorData.GetActorValueModifierAmount(static_cast<char>(value));
    return actor->GetBaseActorValueFloat(value) + permanent +
           m_kActorValueModifiers.GetActorValueModifierAmount(static_cast<char>(value));
}

// @fnv 0x009135a0
void LowProcess::OnPackageStart(Actor* actor, TESPackage* package)
{
    if (package)
    {
        Script* script = package->GetNextScript();
        if (script && (script->GetData() || reinterpret_cast<BGSMessageInitAccess*>(script)->GetIconFormID()))
            script->Run(actor, actor->GetExtraData()->GetScriptLocalData(), 0, true);
        TESTopic* topic = package->FUN_00903cd0();
        if (topic)
            vfn_2a4(actor, topic, 0, 0, true, false);
    }
}

// @fnv 0x009078d0
bool LowProcess::CanRunPackage(TESPackage* package, bool alerted)
{
    switch (package->GetPackType())
    {
    case 0:
    case 1:
    case 6:
    case 7:
    case 13:
    case 14:
    case 17: {
        unsigned int mask = 0x2000000;
        if (alerted)
            mask |= 0x4000000;
        if ((reinterpret_cast<BGSDehydrationStage*>(package)->FUN_00441110() & mask) &&
            reinterpret_cast<HighProcess*>(this)->GetProcessLevel() <= 1)
            return true;
        else
            return false;
        break;
    }
    default:
        return false;
    }
}

// @fnv 0x00907840
bool LowProcess::EvaluateActorPackage(Actor* actor, TESPackage* package, bool alerted)
{
    if (package && CanRunPackage(package, alerted))
    {
        FindPackageTarget(actor);
        SetGenericLocationsForPackage(actor, false);
        vfn_33c(actor, 0, 0, 0, 0, 0, false, 0, false, 0, 0, false, reinterpret_cast<int>(package));
        return true;
    }
    return false;
}

// @fnv 0x00913510
void LowProcess::OnPackageChanged(Actor* actor, TESPackage* package)
{
    if (package)
    {
        Script* script = package->FUN_00903bd0();
        if (script)
            script->Run(actor, actor->GetExtraData()->GetScriptLocalData(), 0, true);
        TESTopic* topic = package->FUN_00903bb0();
        if (topic)
            vfn_2a4(actor, topic, 0, 0, true, false);
    }
    if (actor)
        actor->FUN_00884f80();
}

// @fnv 0x00913630
void LowProcess::OnPackageEnd(Actor* actor, TESPackage* package)
{
    if (package)
    {
        Script* script = package->FUN_00903e20();
        if (script)
            script->Run(actor, actor->GetExtraData()->GetScriptLocalData(), 0, true);
        TESTopic* topic = package->FUN_00903e00();
        if (topic)
            vfn_2a4(actor, topic, 0, 0, true, false);
    }
}

// @fnv 0x00907260
float LowProcess::GetActorTimeDelta(Actor* actor)
{
    struct TimeState
    {
        float hour;
        TESGlobal* timescale;
    } location;
    location.timescale = reinterpret_cast<TESGlobal*>(GetFormByID(0x3a));
    location.hour = g_calendar.GetGameTime();
    if (location.hour < reinterpret_cast<ActiveEffect*>(this)->FUN_007df1f0())
        location.hour += 24.0;
    float delta = location.hour - reinterpret_cast<ActiveEffect*>(this)->FUN_007df1f0();
    delta *= DAT_01012640 / reinterpret_cast<TESGlobalValueReader*>(location.timescale)->GetValue();
    return delta;
}

// Gets the current package, sets the target from vfn_810(actor, package), and returns whether a target was set.
// @fnv 0x00908bf0
bool LowProcess::FindPackageTarget(Actor* actor)
{
    TESPackage* package = GetCurrentPackage();
    SetTarget(vfn_810(actor, package));
    if (pTarget)
        return true;
    return false;
}

// Initializes the patrol package for the actor and, if successful, runs the follow-up step; otherwise sets the procedure index to -1 and returns false.
// @fnv 0x009122e0
bool LowProcess::FindPatrolTarget(Actor* actor, PatrolActorPackageData* patrol)
{
    if (!patrol->Init(actor, GetCurrentPackage()))
    {
        SetProcedureIndex(-1);
        return false;
    }
    ProcessPatrolPackage(actor, patrol);
    return true;
}

// @fnv 0x00911e80
void LowProcess::SetTarget(TESObjectREFR* target)
{
    if (target)
        reinterpret_cast<TESObjectREFRHelper*>(target)->SetTargetingState(true);
    TESObjectREFR** address = &pTarget;
    *address = target;
    reinterpret_cast<BGSPickupPutdownSounds*>(vfn_278())->SetPutdownSound(reinterpret_cast<TESSound*>(target));
}

// Calls FUN_00693d50 with DAT_011e0358, then sets the recipe skill from DAT_011a39c4, DAT_011e0360 and DAT_011e035c.
// @fnv 0x00907650
void LowProcess::ResetPackageState()
{
    reinterpret_cast<ActiveEffect*>(this)->FUN_00693d50(DAT_011e0358);
    reinterpret_cast<TESRecipe*>(this)->SetSkill((DAT_011a39c4 << 9) | DAT_011e0360 | (DAT_011e035c << 13));
}

// @fnv 0x00912960
void LowProcess::HandlePatrolArrival(Actor* actor, PatrolActorPackageData* patrol)
{
    vfn_244();
    patrol->m_fElapsedWaitTime = 0.0f;
    patrol->eState = PatrolActorPackageData__PATROL_STATE_PATROL_STATE_AT_REF;
}

// @fnv 0x009076c0
int LowProcess::GetPackedStateBits9To12()
{
    return (m_uiStateFlags & 0x1e00) >> 9;
}
// @fnv 0x009076e0
int LowProcess::GetPackedStateBits13To26()
{
    return (m_uiStateFlags & 0x7ffe000) >> 13;
}
// @fnv 0x009076a0
int LowProcess::GetPackedStateBits0To8()
{
    return m_uiStateFlags & 0x1ff;
}

// If the current package has a target reference that is not deleted and differs from pTarget, sets it as the target.
// @fnv 0x0090a070
void LowProcess::UpdateTargetFromPackage()
{
    if (GetCurrentPackage() && GetCurrentPackage()->GetTarget() &&
        GetCurrentPackage()->GetTarget()->GetReferenceTarget())
    {
        TESObjectREFR* reference = GetCurrentPackage()->GetTarget()->GetReferenceTarget();
        if (!reference->IsDeleted() && reference != pTarget)
            SetTarget(reference);
    }
}

// Gets the current package, resolves its reference for the actor, stores it in the first or second slot based on second, and returns it.
// @fnv 0x00908c50
TESObjectREFR* LowProcess::GetPackageLocationReference(Actor* actor, bool second)
{
    struct LocationState
    {
        unsigned int location;
        TESObjectREFR* reference;
        TESPackage* package;
    } state;
    state.package = GetCurrentPackage();
    if (!state.package)
        return 0;
    state.reference = vfn_814(actor, state.package, second);
    state.location = reinterpret_cast<BGSMessageInitAccess*>(state.package)->GetIconFormID();
    if (!second)
        m_pReference40 = state.reference;
    else
        m_pReference44 = state.reference;
    return state.reference;
}

// @fnv 0x0090ac20
void LowProcess::SetFlag40(int value)
{
    SetFlag(reinterpret_cast<bool&>(value), 0x40);
}

struct FUN_00906f60
{
    int a[2];
    FUN_00906f60();
};

struct SpinList
{
    int a;
    int b;
    SpinList();
    ~SpinList();
};

struct FUN_00937000
{
    int a[4];
    FUN_00937000();
    ~FUN_00937000();
};

struct FUN_008d0270
{
    virtual ~FUN_008d0270();
    FUN_008d0270();
    void StopPackage();
    void SetBits(int, int, int);
    void SetSkillLevel(int);

    char pad_04[0x18];
    float m_1c;
    float m_20;
    int m_24;
    char pad_28[0x0c];
    int m_34;
};

struct FUN_00906dc0 : public FUN_008d0270
{
    FUN_00906dc0();
    virtual ~FUN_00906dc0();

    FUN_00906f60 m_38;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    SpinList m_5c;
    int m_64;
    int m_68;
    SpinList m_6c;
    SpinList m_74;
    SpinList m_7c;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    FUN_00937000 m_94;
    float m_a4;
    float m_a8;
    float m_ac;
    bool m_b0;
};

// @fnv 0x00906dc0
FUN_00906dc0::FUN_00906dc0() : m_40(0)
{
    m_20 = -1.0f;
    StopPackage();
    m_1c = 0.0f;
    m_24 = 0;
    m_64 = 0;
    m_68 = 0;
    m_44 = 0;
    m_84 = 0;
    m_88 = 0;
    m_8c = 0;
    m_34 = 0;
    m_58 = 0;
    m_a8 = 0.0f;
    m_54 = 0;
    SetBits(0, 0xff, 0);
    m_48 = 0;
    m_4c = 0;
    m_ac = 0.0f;
    m_90 = 0;
    m_b0 = false;
    SetSkillLevel(3);
}

// @fnv 0x00906f60
float* __fastcall FUN_00906f60(float* pThis)
{
    pThis[0] = 0.0f;
    pThis[1] = 0.0f;
    return pThis;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00906fb0(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00906fb0
void* DelStandIn::FUN_00906fb0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct ListX
{
    int a;
    int b;
    ~ListX();
};
struct M94
{
    ~M94();
};
struct FUN_008d0640_shell
{
    virtual void Dummy();
    char pad[0x58];
    ~FUN_008d0640_shell();
    void StopPackage();
};
struct FUN_00906fe0 : public FUN_008d0640_shell
{
    ListX l1;
    char gap1[8];
    ListX l2;
    ListX l3;
    ListX l4;
    char gap2[0x10];
    M94 m94;
    ~FUN_00906fe0();
    void ClearData();
};
// @fnv 0x00906fe0
FUN_00906fe0::~FUN_00906fe0()
{
    StopPackage();
    ClearData();
}

struct FUN_008d7e00_shell : public LowProcess
{
    void FUN_008d7e00(bool, unsigned char);
};

// Sets or clears the bits of uMask in the byte at offset 0x30 of this object, depending on bVal.
// @fnv 0x008d7e00
void FUN_008d7e00_shell::FUN_008d7e00(bool abSet, unsigned char uMask)
{
    if (abSet)
        ((unsigned char*)this)[0x30] |= uMask;
    else
        ((unsigned char*)this)[0x30] &= ~uMask;
}

struct FUN_008d7e60_shell : public LowProcess
{
    bool FUN_008d7e60(unsigned char);
};

// Returns true if the byte at offset 0x30 of this object has any of the bits in uMask set.
// @fnv 0x008d7e60
bool FUN_008d7e60_shell::FUN_008d7e60(unsigned char uMask)
{
    return (((unsigned char*)this)[0x30] & uMask) != 0;
}

struct FUN_00911ae0_shell : LowProcess
{
    float FUN_00911ae0(Actor* apActor, Actor* apTarget);
};

// @fnv 0x00911ae0
float FUN_00911ae0_shell::FUN_00911ae0(Actor* apActor, Actor* apTarget)
{
    float fPriority = 0.0f;
    return fPriority;
}

struct FUN_008d7f40_shell : public TimeoutTimer
{
    void FUN_008d7f40(float);
};

extern "C" float __cdecl FUN_00435dd0(void);

// Stores the result of FUN_00435dd0 in the first float slot and afTargetTime in the second.
// @fnv 0x008d7f40
void FUN_008d7f40_shell::FUN_008d7f40(float afTargetTime)
{
    ((float*)this)[0] = FUN_00435dd0();
    ((float*)this)[1] = afTargetTime;
}

struct FUN_0090cfa0_shell
{
    virtual void A1() = 0;
    virtual void A2() = 0;
    virtual void A3() = 0;
    virtual void A4() = 0;
    virtual void A5() = 0;
    virtual void A6() = 0;
    virtual void A7() = 0;
    virtual void A8() = 0;
    virtual void A9() = 0;
    virtual void A10() = 0;
    virtual void A11() = 0;
    virtual void A12() = 0;
    virtual void A13() = 0;
    virtual void A14() = 0;
    virtual void A15() = 0;
    virtual void A16() = 0;
    virtual void A17() = 0;
    virtual void A18() = 0;
    virtual void A19() = 0;
    virtual void A20() = 0;
    virtual void A21() = 0;
    virtual void A22() = 0;
    virtual void A23() = 0;
    virtual void A24() = 0;
    virtual void A25() = 0;
    virtual void A26() = 0;
    virtual void A27() = 0;
    virtual void A28() = 0;
    virtual void A29() = 0;
    virtual void A30() = 0;
    virtual void A31() = 0;
    virtual void A32() = 0;
    virtual void A33() = 0;
    virtual void A34() = 0;
    virtual void A35() = 0;
    virtual void A36() = 0;
    virtual void A37() = 0;
    virtual void A38() = 0;
    virtual void A39() = 0;
    virtual void A40() = 0;
    virtual void A41() = 0;
    virtual void A42() = 0;
    virtual void A43() = 0;
    virtual void A44() = 0;
    virtual void A45() = 0;
    virtual void A46() = 0;
    virtual void A47() = 0;
    virtual void A48() = 0;
    virtual void A49() = 0;
    virtual void A50() = 0;
    virtual void A51() = 0;
    virtual void A52() = 0;
    virtual void A53() = 0;
    virtual void A54() = 0;
    virtual void A55() = 0;
    virtual void A56() = 0;
    virtual void A57() = 0;
    virtual void A58() = 0;
    virtual void A59() = 0;
    virtual void A60() = 0;
    virtual void A61() = 0;
    virtual void A62() = 0;
    virtual void A63() = 0;
    virtual void A64() = 0;
    virtual void A65() = 0;
    virtual void A66() = 0;
    virtual void A67() = 0;
    virtual void A68() = 0;
    virtual void A69() = 0;
    virtual void A70() = 0;
    virtual void A71() = 0;
    virtual void A72() = 0;
    virtual void A73() = 0;
    virtual void A74() = 0;
    virtual void A75() = 0;
    virtual void A76() = 0;
    virtual void A77() = 0;
    virtual void A78() = 0;
    virtual void A79() = 0;
    virtual void A80() = 0;
    virtual void A81() = 0;
    virtual void A82() = 0;
    virtual void A83() = 0;
    virtual void A84() = 0;
    virtual void A85() = 0;
    virtual void A86() = 0;
    virtual void A87() = 0;
    virtual void A88() = 0;
    virtual void A89() = 0;
    virtual void A90() = 0;
    virtual void A91() = 0;
    virtual void A92() = 0;
    virtual void A93() = 0;
    virtual void A94() = 0;
    virtual void A95() = 0;
    virtual void A96() = 0;
    virtual void A97() = 0;
    virtual void A98() = 0;
    virtual void A99() = 0;
    virtual void A100() = 0;
    virtual void A101() = 0;
    virtual void A102() = 0;
    virtual void A103() = 0;
    virtual void A104() = 0;
    virtual void A105() = 0;
    virtual void A106() = 0;
    virtual void A107() = 0;
    virtual void A108() = 0;
    virtual void A109() = 0;
    virtual void A110() = 0;
    virtual void A111() = 0;
    virtual void A112() = 0;
    virtual void A113() = 0;
    virtual void A114() = 0;
    virtual void A115() = 0;
    virtual void A116() = 0;
    virtual void A117() = 0;
    virtual void A118() = 0;
    virtual void A119() = 0;
    virtual void A120() = 0;
    virtual void A121() = 0;
    virtual void A122() = 0;
    virtual void A123() = 0;
    virtual void A124() = 0;
    virtual void A125() = 0;
    virtual void A126() = 0;
    virtual void A127() = 0;
    virtual void A128() = 0;
    virtual void A129() = 0;
    virtual void A130() = 0;
    virtual void A131() = 0;
    virtual void A132() = 0;
    virtual void A133() = 0;
    virtual void A134() = 0;
    virtual void A135() = 0;
    virtual void A136() = 0;
    virtual void A137() = 0;
    virtual void A138() = 0;
    virtual void A139() = 0;
    virtual TESPackage* GetAssignedPackage();
    virtual void B1() = 0;
    virtual void B2() = 0;
    virtual void B3() = 0;
    virtual void B4() = 0;
    virtual void B5() = 0;
    virtual void B6() = 0;
    virtual void B7() = 0;
    virtual void B8() = 0;
    virtual void B9() = 0;
    virtual void B10() = 0;
    virtual void B11() = 0;
    virtual void B12() = 0;
    virtual void B13() = 0;
    virtual void B14() = 0;
    virtual void B15() = 0;
    virtual void B16() = 0;
    virtual void B17() = 0;
    virtual void B18() = 0;
    virtual void B19() = 0;
    virtual void B20() = 0;
    virtual int GetIndex();
    bool IsProcedureTypeAllowed();
};
// @fnv 0x0090cfa0
bool FUN_0090cfa0_shell::IsProcedureTypeAllowed()
{
    if (GetAssignedPackage() && DAT_011a3ff0[GetAssignedPackage()->GetProcedureType()][GetIndex()] == 1)
        return true;
    return false;
}

struct ActorProxy
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
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void Foo(void*, void*, bool, bool, bool, int, bool, void*);
};
struct LowProcessProxy
{
    bool FUN_0090dc10(void*, void*, bool, bool, void*, bool, bool, bool, char, bool, bool, bool, void*);
};
// Calls Foo on the actor with the target, group, combat flags and package, then returns true.
// @fnv 0x0090dc10
bool LowProcessProxy::FUN_0090dc10(void* apActor, void* apTarget, bool abCheckForAmbush, bool absendalarm,
                                   void* apGroup, bool abfleeing, bool abForceFlee, bool abIsAggressor, char acTeam,
                                   bool bforcecombat, bool abForceAttack, bool abCastSpell, void* apPackage)
{
    ((ActorProxy*)apActor)->Foo(apTarget, apGroup, bforcecombat, abIsAggressor, abfleeing, 0, abCastSpell, apPackage);
    return true;
}

struct FUN_0090e600
{
    int f0;
    int f4;
    unsigned char f8;
    unsigned char f9;
    int fC;
    int f10;
    int f14;
    int f18;
    FUN_0090e600();
};
// @fnv 0x0090e600
FUN_0090e600::FUN_0090e600()
{
    f0 = 0;
    f4 = 0;
    f8 = 0;
    f9 = 0;
    f18 = -1;
    fC = 0;
    f10 = 0x7fffffff;
    f14 = 0;
}

struct Owner911ed0
{
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void d45() = 0;
    virtual void d46() = 0;
    virtual void d47() = 0;
    virtual void d48() = 0;
    virtual void d49() = 0;
    virtual void d50() = 0;
    virtual void d51() = 0;
    virtual void d52() = 0;
    virtual void d53() = 0;
    virtual void d54() = 0;
    virtual void d55() = 0;
    virtual void d56() = 0;
    virtual void d57() = 0;
    virtual void d58() = 0;
    virtual void d59() = 0;
    virtual void d60() = 0;
    virtual void d61() = 0;
    virtual void d62() = 0;
    virtual void d63() = 0;
    virtual void d64() = 0;
    virtual void d65() = 0;
    virtual void d66() = 0;
    virtual void d67() = 0;
    virtual void d68() = 0;
    virtual void d69() = 0;
    virtual void d70() = 0;
    virtual void d71() = 0;
    virtual void d72() = 0;
    virtual void d73() = 0;
    virtual void d74() = 0;
    virtual void d75() = 0;
    virtual void d76() = 0;
    virtual void d77() = 0;
    virtual void d78() = 0;
    virtual void d79() = 0;
    virtual void d80() = 0;
    virtual void d81() = 0;
    virtual void d82() = 0;
    virtual void d83() = 0;
    virtual void d84() = 0;
    virtual void d85() = 0;
    virtual void d86() = 0;
    virtual void d87() = 0;
    virtual void d88() = 0;
    virtual void d89() = 0;
    virtual void d90() = 0;
    virtual void d91() = 0;
    virtual void d92() = 0;
    virtual void d93() = 0;
    virtual void d94() = 0;
    virtual void d95() = 0;
    virtual void d96() = 0;
    virtual void d97() = 0;
    virtual void d98() = 0;
    virtual void d99() = 0;
    virtual void d100() = 0;
    virtual void d101() = 0;
    virtual void d102() = 0;
    virtual void d103() = 0;
    virtual void d104() = 0;
    virtual void d105() = 0;
    virtual void d106() = 0;
    virtual void d107() = 0;
    virtual void d108() = 0;
    virtual void d109() = 0;
    virtual void d110() = 0;
    virtual void d111() = 0;
    virtual void d112() = 0;
    virtual void d113() = 0;
    virtual void d114() = 0;
    virtual void d115() = 0;
    virtual void d116() = 0;
    virtual void d117() = 0;
    virtual void d118() = 0;
    virtual void d119() = 0;
    virtual void d120() = 0;
    virtual void d121() = 0;
    virtual void d122() = 0;
    virtual void d123() = 0;
    virtual void d124() = 0;
    virtual void d125() = 0;
    virtual void d126() = 0;
    virtual void d127() = 0;
    virtual void d128() = 0;
    virtual void d129() = 0;
    virtual void d130() = 0;
    virtual void d131() = 0;
    virtual void d132() = 0;
    virtual void d133() = 0;
    virtual void d134() = 0;
    virtual void d135() = 0;
    virtual void d136() = 0;
    virtual void d137() = 0;
    virtual void d138() = 0;
    virtual void d139() = 0;
    virtual void d140() = 0;
    virtual void d141() = 0;
    virtual void d142() = 0;
    virtual void d143() = 0;
    virtual void d144() = 0;
    virtual void d145() = 0;
    virtual void d146() = 0;
    virtual void d147() = 0;
    virtual void d148() = 0;
    virtual void d149() = 0;
    virtual void d150() = 0;
    virtual void d151() = 0;
    virtual void d152() = 0;
    virtual void d153() = 0;
    virtual void d154() = 0;
    virtual void d155() = 0;
    virtual void d156() = 0;
    virtual void d157() = 0;
    virtual void d158() = 0;
    virtual void d159() = 0;
    virtual void d160() = 0;
    virtual void d161() = 0;
    virtual void d162() = 0;
    virtual void d163() = 0;
    virtual void d164() = 0;
    virtual void d165() = 0;
    virtual void vf298(void*, int, int, int) = 0;
    void FUN_00911ed0(void*);
};
// Calls the virtual function at offset 298 with the actor, 0, 257 and 0.
// @fnv 0x00911ed0
void Owner911ed0::FUN_00911ed0(void* apActor)
{
    vf298(apActor, 0, 257, 0);
}

struct S913460
{
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
    virtual int f18();
    virtual int f19();
    virtual int f20();
    virtual int f21();
    virtual int f22();
    virtual int f23();
    virtual int f24();
    virtual int f25();
    virtual int f26();
    virtual int f27();
    virtual int f28();
    virtual int f29();
    virtual int f30();
    virtual int f31();
    virtual int f32();
    virtual int f33();
    virtual int f34();
    virtual int f35();
    virtual int f36();
    virtual int f37();
    virtual int f38();
    virtual int f39();
    virtual int f40();
    virtual int f41();
    virtual int f42();
    virtual int f43();
    virtual int f44();
    virtual int f45();
    virtual int f46();
    virtual int f47();
    virtual int f48();
    virtual int f49();
    virtual int f50();
    virtual int f51();
    virtual int f52();
    virtual int f53();
    virtual int f54();
    virtual int f55();
    virtual int f56();
    virtual int f57();
    virtual int f58();
    virtual int f59();
    virtual int f60();
    virtual int f61();
    virtual int f62();
    virtual int f63();
    virtual int f64();
    virtual int f65();
    virtual int f66();
    virtual int f67();
    virtual int f68();
    virtual int f69();
    virtual int f70();
    virtual int f71();
    virtual int f72();
    virtual int f73();
    virtual int f74();
    virtual int f75();
    virtual int f76();
    virtual int f77();
    virtual int f78();
    virtual int f79();
    virtual int f80();
    virtual int f81();
    virtual int f82();
    virtual int f83();
    virtual int f84();
    virtual int f85();
    virtual int f86();
    virtual int f87();
    virtual int f88();
    virtual int f89();
    virtual int f90();
    virtual int f91();
    virtual int f92();
    virtual int f93();
    virtual int f94();
    virtual int f95();
    virtual int f96();
    virtual int f97();
    virtual int f98();
    virtual int f99();
    virtual int f100();
    virtual int f101();
    virtual int f102();
    virtual int f103();
    virtual int f104();
    virtual int f105();
    virtual int f106();
    virtual int f107();
    virtual int f108();
    virtual int f109();
    virtual int f110();
    virtual int f111();
    virtual int f112();
    virtual int f113();
    virtual int f114();
    virtual int f115();
    virtual int f116();
    virtual int f117();
    virtual int f118();
    virtual int f119();
    virtual int f120();
    virtual int f121();
    virtual int f122();
    virtual int f123();
    virtual int f124();
    virtual int f125();
    virtual int f126();
    virtual int f127();
    virtual int f128();
    virtual int f129();
    virtual int f130();
    virtual int f131();
    virtual int f132();
    virtual int f133();
    virtual int f134();
    virtual int f135();
    virtual int f136();
    virtual int f137();
    virtual int f138();
    virtual TESPackage* f139();
    virtual int f140();
    virtual int f141();
    virtual int f142();
    virtual int f143();
    virtual int f144();
    virtual int f145();
    virtual int f146();
    virtual int f147();
    virtual int f148();
    virtual int f149();
    virtual int f150();
    virtual int f151();
    virtual int f152();
    virtual int f153();
    virtual int f154();
    virtual int f155();
    virtual int f156();
    virtual int f157();
    virtual int f158();
    virtual int f159();
    virtual int f160();
    bool IsPackageProcedureAllowed(void* apActor);
};
// @fnv 0x00913460
bool S913460::IsPackageProcedureAllowed(void* apActor)
{
    TESPackage* ppack = f139();
    if (!ppack)
        return true;
    if (DAT_011a3ff0[ppack->GetProcedureType()][f160()] == 0x36)
        return true;
    return false;
}

template <int N> struct VT;
template <> struct VT<0>
{
    virtual void vf(char (*)[1]);
};
template <int N> struct VT : VT<N - 1>
{
    virtual void vf(char (*)[N + 1]);
};
struct Hack : VT<215>
{
    virtual bool F216();
};
struct Host
{
    char _pad[0xAC];
    float m_fValue90;
    void FUN_009134c0(Actor* apAggressor, float afAmount);
};
// @fnv 0x009134c0
void Host::FUN_009134c0(Actor* apAggressor, float afAmount)
{
    if (apAggressor && (((Hack*)apAggressor)->F216() || apAggressor->IsPlayerTeammate()))
    {
        m_fValue90 += afAmount;
    }
}

struct FUN_008675e0_shell : LowProcess
{
    void FUN_008675e0(LowProcess* p);
};

// Copies the float, uint and byte fields at offsets 0x0-0x44 from p into this when p is non-null.
// @fnv 0x008675e0
void FUN_008675e0_shell::FUN_008675e0(LowProcess* apSource)
{
    if (apSource)
    {
        *reinterpret_cast<float*>(this) = *reinterpret_cast<float*>(apSource);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 4) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 4);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 8) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 8);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0xc);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x10) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x10);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x14) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x14);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1c) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x1c);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x20) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x20);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x24) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x24);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x28) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x28);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x2c) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x2c);
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) =
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(apSource) + 0x30);
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x34) =
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(apSource) + 0x34);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x38) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x38);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x3c) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(apSource) + 0x3c);
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x40) =
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(apSource) + 0x40);
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x44) =
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(apSource) + 0x44);
    }
}

struct FUN_00906f80_shell
{
    unsigned char _pad[0x30];
    unsigned char _m30;
    void SetBits(unsigned char, unsigned char, unsigned char);
};
// @fnv 0x00906f80
void FUN_00906f80_shell::SetBits(unsigned char value, unsigned char mask, unsigned char shift)
{
    _m30 = (_m30 & ~mask) | (value << shift);
}

struct FUN_009074f0_shell
{
    unsigned char _pad[0x94];
    ActorValueModifierList m_modifierList;
    float GetModifierValue(char aiWhich);
};

// @fnv 0x009074f0
float FUN_009074f0_shell::GetModifierValue(char aiWhich)
{
    return m_modifierList.GetActorValueModifierAmount(aiWhich);
}

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct GameTimerRecord;
extern GameTimerRecord g_timeGlobal;
struct FUN_00907620_Holder
{
    char _pad[0xA4];
    float m_fValue88;
    void FUN_00907620();
};
// Subtracts the value returned by the global time object's accessor from the holder's float field.
// @fnv 0x00907620
void FUN_00907620_Holder::FUN_00907620()
{
    m_fValue88 -= ((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue();
}

struct Holder908f40
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
    virtual void w(void*, int);
    void FUN_00908f40(void*);
};
// Calls the virtual w with apActor and 1.
// @fnv 0x00908f40
void Holder908f40::FUN_00908f40(void* apActor)
{
    w(apActor, 1);
}

struct Actor;
struct Holder9177a0
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
    virtual void Func298(Actor*, int, int, int);
    void FUN_009177a0(Actor* apActor);
};
// Calls Func298 on apActor with arguments 1, 0x101 and 0.
// @fnv 0x009177a0
void Holder9177a0::FUN_009177a0(Actor* apActor)
{
    Func298(apActor, 1, 0x101, 0);
}

class TESClass
{
  public:
    bool IsGuard();
};
struct PC7d
{
    TESClass* GetClass();
};
struct ActorShell
{
    bool IsHostileToActor(Actor*, int, int*, bool);
};
struct Crime
{
    int FUN_00726070();
    Actor* FUN_0084e3a0();
    TESObjectREFR* GetTarget();
};
struct CrimeList
{
    Crime** FUN_006815c0();
    CrimeList* FUN_00726070();
};
class AlarmPackage : public TESPackage
{
  public:
    CrimeList* GetCrimeList();
};
extern double DAT_01088f48;
struct FUN_0090d240_stand
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
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
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual TESPackage* GetCurrentPackage();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vfn_288(Actor*, int);
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vfn_298(Actor*, int, int, int);
    virtual void vfn_29c(Actor*, int, int, int);
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vfn_33c(Actor*, Actor*, int, int, int, int, int, int, int, int, int, int, int);
    void FUN_0090d240(Actor* apActor);
};
// @fnv 0x0090d240
void FUN_0090d240_stand::FUN_0090d240(Actor* apActor)
{
    AlarmPackage* ppack = dynamic_cast<AlarmPackage*>(GetCurrentPackage());
    Actor* pactor = 0;
    if (ppack)
    {
        if (!((PC7d*)apActor)->GetClass()->IsGuard())
        {
            CrimeList* pCurrentElementNext = ppack->GetCrimeList();
            bool bcombatflag = false;
            while (pCurrentElementNext && *pCurrentElementNext->FUN_006815c0() && !bcombatflag)
            {
                Crime* pcrime = *pCurrentElementNext->FUN_006815c0();
                TESObjectREFR* pcrimeRef = 0;
                Actor* pcrimeAct = 0;
                Actor* pactor = pcrime->FUN_0084e3a0();
                pcrimeRef = pcrime->GetTarget();
                int ereaction = 0;
                if (!bcombatflag)
                {
                    if (pcrime->FUN_00726070() > 2)
                    {
                        if (pcrimeAct && ((ActorShell*)apActor)->IsHostileToActor(pactor, 0, &ereaction, false))
                            bcombatflag = true;
                    }
                    else
                    {
                        if (((ActorShell*)apActor)->IsHostileToActor(pactor, 0, &ereaction, false))
                            bcombatflag = true;
                    }
                }
                pCurrentElementNext = pCurrentElementNext->FUN_00726070();
            }
            if (bcombatflag)
            {
                vfn_298(apActor, 0, 0x101, 0);
                vfn_33c(apActor, pactor, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
                return;
            }
            vfn_288(apActor, 3);
        }
        else
        {
            vfn_288(apActor, 1);
            vfn_29c(apActor, 0, 1, 0x101);
            if (apActor->GetDistanceToReference(g_thePlayer, false, false) > DAT_01088f48 &&
                g_thePlayer->GetParentWorldSpace() && g_thePlayer->GetParentWorldSpace() == apActor->GetParentWorldSpace())
                apActor->SetSpeakingState(false);
        }
    }
}

struct FUN_008a6730_Actor
{
    void FUN_008a6730(Actor* apActor);
};
extern double DAT_010179e0;

struct LowProcessStandIn
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
    virtual void FindTarget(Actor* apActor);
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
    virtual TESPackage* GetCurrentPackage();
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
    virtual void SetMovement(Actor* apActor, int aiType);
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void Pursue(Actor* apActor, bool abFlag, int emovemode, bool abFlag2);
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
    virtual bool ActorVfn304();
    char pad04[0x3c];
    TESObjectREFR* pTarget;  // +0x40
    void UpdateTargetAndMovement(Actor* apActor, bool abNewpackage, bool abInterateIndex, int emovemode);
};

// Ensures pTarget is set, then chooses movement/pursuit based on target process type, distance and package type.
// @fnv 0x0090dc60
void LowProcessStandIn::UpdateTargetAndMovement(Actor* apActor, bool abNewpackage, bool abInterateIndex, int emovemode)
{
    if (!pTarget)
        FindTarget(apActor);
    if (!pTarget)
    {
        SetMovement(apActor, 1);
        return;
    }
    Actor* ptarg = static_cast<Actor*>(pTarget);
    if (ptarg->GetCurrentProcessLevel() < PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH && !apActor->IsInDeadState())
    {
        SetMovement(apActor, 2);
        reinterpret_cast<FUN_008a6730_Actor*>(ptarg)->FUN_008a6730(apActor);
    }
    if (apActor->GetDistanceToReference(pTarget, false, false) > DAT_010179e0)
    {
        Pursue(apActor, false, emovemode, true);
        return;
    }
    if (reinterpret_cast<LowProcessStandIn*>(apActor)->ActorVfn304() && GetCurrentPackage()->GetPackType() != 19)
        return;
    SetMovement(apActor, 1);
}

struct P09AV
{
    static bool __cdecl GetFlag(int, unsigned int);
};

float __cdecl FUN_0066eea0(void*, int, float);

struct ModHack
{
    void ModifyModifier(char, float, int);
};

struct FUN_00907460_shell
{
    void FUN_00907460(Actor* apActor, int aiWhich, float afValue);
};

// If the flag for aiWhich lacks 0x100, computes a value from apActor and afValue and applies it via ModifyModifier for case 0x10.
// @fnv 0x00907460
void FUN_00907460_shell::FUN_00907460(Actor* apActor, int aiWhich, float afValue)
{
    if (P09AV::GetFlag(aiWhich, 0x100))
        return;

    switch (aiWhich)
    {
    case 0x10: {
        float f = FUN_0066eea0(apActor ? (char*)apActor + 0xa4 : 0, aiWhich, afValue);
        ((ModHack*)((char*)this + 0x94))->ModifyModifier((char)aiWhich, f, 0);
        break;
    }
    }
}

typedef int PROCEDURE;

struct FUN_00907960_shell
{
    bool FUN_00907960(TESPackage* apPackage, int aiIndex);
};

// Returns false for package types 0,1,6,7,13,14,17, and for other types when the procedure at aiIndex equals 0x36; otherwise true.
// @fnv 0x00907960
bool FUN_00907960_shell::FUN_00907960(TESPackage* apPackage, int aiIndex)
{
    switch (apPackage->GetPackType())
    {
    case 0:
    case 1:
    case 6:
    case 7:
    case 13:
    case 14:
    case 17:
        return false;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 15:
    case 16:
    default:
        if (apPackage->GetProcedureType() != -1)
        {
            PROCEDURE eprocedure = (PROCEDURE)DAT_011a3ff0[apPackage->GetProcedureType()][aiIndex];
            if (eprocedure == 0x36)
                return false;
        }
        return true;
    }
}

struct FUN_004212b0_shell
{
    PatrolActorPackageData* FUN_004212b0();
};

struct FUN_0041cab0
{
    void ProcessInteger(int);
};

struct FUN_009079f0_shell
{
    bool FUN_009079f0(Actor* apActor, TESPackage* apPackage);
};

// @fnv 0x009079f0
bool FUN_009079f0_shell::FUN_009079f0(Actor* apActor, TESPackage* apPackage)
{
    switch (apPackage->GetPackType())
    {
    case 0xd: {
        PatrolActorPackageData* pdata = ((FUN_004212b0_shell*)apActor->GetExtraData())->FUN_004212b0();
        if (pdata)
        {
            if (!pdata->eState)
            {
                if (pdata->Init(apActor, apPackage))
                {
                    pdata->eState = PatrolActorPackageData__PATROL_STATE_PATROL_STATE_TRAVELING_TO_NEXT_REF;
                    ((FUN_0041cab0*)apActor->GetExtraData())->ProcessInteger((int)pdata->GetCurrentPatrolReference());
                    return true;
                }
            }
            else if (pdata->AdvanceToNextReference(true))
            {
                ((FUN_0041cab0*)apActor->GetExtraData())->ProcessInteger((int)pdata->GetCurrentPatrolReference());
                return true;
            }
        }
        return false;
        break;
    }
    default:
        return false;
    }
}

struct FUN_00908e90_shell
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
    virtual TESPackage* vfn_22c();
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
    virtual void vfn_288(Actor* apActor, int a2);

    bool UpdatePackageState(Actor* apActor);
};

// @fnv 0x00908e90
bool FUN_00908e90_shell::UpdatePackageState(Actor* apActor)
{
    if (vfn_22c() && !vfn_22c()->IsPackageRunningForActor(apActor, 0, -1.0f, false))
    {
        vfn_288(apActor, -1);
    }
    else if (vfn_22c()->FUN_0067efd0())
    {
        vfn_288(apActor, 1);
    }
    return false;
}

struct TESObjectREFR_GetFlags_Helper
{
    int CallGetFlags();
};

struct FUN_00909d00_shell
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
    virtual void vfn_8c(Actor* apActor);
    virtual void vfn_90(Actor* apActor, int a2);
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
    virtual TESPackage* vfn_27c();

    char pad_04[0x3c];
    TESObjectREFR* pTarget;

    void UpdatePackageTarget(Actor* apActor);
};

// @fnv 0x00909d00
void FUN_00909d00_shell::UpdatePackageTarget(Actor* apActor)
{
    TESPackage* ppackage = vfn_27c();
    if (!pTarget)
    {
        vfn_8c(apActor);
    }
    vfn_90(apActor, 0);

    float fradius = 0.0f;
    if (ppackage->GetTarget())
    {
        fradius = (float)((TESObjectREFR_GetFlags_Helper*)ppackage->GetTarget())->CallGetFlags();
    }

    if (pTarget)
    {
        if (apActor->GetDistanceToReference(pTarget, false, false) > fradius)
            return;
    }

    if (!pTarget)
    {
        ppackage->IsPackageRunningForActor(apActor, 0, -1.0f, false);
    }
}

TESForm* GetFormByID(unsigned int);

struct FUN_008d0e60_shell
{
    void FUN_008d0e60(unsigned int, unsigned int, MobileObject*);
};

struct FUN_00910250_shell
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
    virtual void vfn_12c(TESObjectREFR* refr);

    char pad_04[0x3c];
    TESObjectREFR* pTarget;
    TESObjectREFR* m_pReference40;

    void UpdateTargetRefs(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* pmob);
};

// @fnv 0x00910250
void FUN_00910250_shell::UpdateTargetRefs(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* pMobileObject)
{
    ((FUN_008d0e60_shell*)this)->FUN_008d0e60(aiFlags, aiOldFlags, pMobileObject);

    unsigned int uiTargetFormID;
    unsigned int ilocationID;

    uiTargetFormID = (unsigned int)pTarget;
    if (uiTargetFormID)
    {
        vfn_12c(dynamic_cast<TESObjectREFR*>(GetFormByID(uiTargetFormID)));
        if (pTarget)
            ((TESObjectREFRHelper*)pTarget)->SetTargetingState(true);
    }

    ilocationID = (unsigned int)m_pReference40;
    if (ilocationID)
    {
        m_pReference40 = dynamic_cast<TESObjectREFR*>(GetFormByID(ilocationID));
    }
}

namespace std {
float __cdecl abs(float);
}

struct Flt
{
    operator unsigned int();
};

struct FUN_00674d70_shell
{
    void SetFlag800(bool);
};

struct FUN_008b3ab0_shell
{
    void FUN_008b3ab0();
};

struct FUN_00912150_shell
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
    virtual void vfn_288(Actor* apActor, bool abFlag);

    void UpdateActorIfStale(Actor* apActor);
};

// @fnv 0x00912150
void FUN_00912150_shell::UpdateActorIfStale(Actor* apActor)
{
    float fElapsedTime =
        std::abs((float)((double)g_calendar.GetGameTime() - ((ActorPackageContext*)((char*)this + 4))->FUN_00621b00()));
    if (fElapsedTime >= (double)0.1f)
    {
        vfn_288(apActor, true);
        ((FUN_00674d70_shell*)((Flt*)((char*)this + 4))->operator unsigned int())->SetFlag800(true);
    }
    else
    {
        ((FUN_008b3ab0_shell*)apActor)->FUN_008b3ab0();
    }
}

struct BoolVirtuals0
{
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
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
};

struct BoolVirtuals1 : public BoolVirtuals0
{
    virtual bool v071();
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
};

struct BoolVirtuals2 : public BoolVirtuals1
{
    virtual bool v314();
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
    virtual bool v361();
};

struct FUN_0041c930
{
    void __thiscall SetPackageOverride(TESPackage*, int, TESObjectREFR*, bool, bool, bool);
};

struct FUN_004211d0
{
    void __thiscall AttachActorPackageData(ActorPackageData*);
};

struct FUN_008c6060_shell
{
    void FUN_008c6060();
};

struct ActorPackageGetTarget
{
    TESObjectREFR* GetTarget();
};

struct FUN_009130f0_shell : public LowProcess
{
    void FUN_009130f0(MobileObject* apMob);
};

// @fnv 0x009130f0
void FUN_009130f0_shell::FUN_009130f0(MobileObject* apMob)
{
    TESObjectREFR* ptarget;
    ExtraDataList* pextra;
    ActorPackageData* pinstanceData;

    if (GetCurrentPackage() && !GetCurrentPackage()->IsMustComplete())
    {
        pextra = apMob->GetExtraData();

        reinterpret_cast<FUN_0041c930*>(pextra)->SetPackageOverride(
            GetCurrentPackage(), vfn_23c(), *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x40),
            reinterpret_cast<BoolVirtuals2*>(this)->v071(), reinterpret_cast<BoolVirtuals2*>(this)->v314(),
            reinterpret_cast<BoolVirtuals2*>(this)->v361());

        apMob->MarkAsModified(0x80000000);

        pinstanceData = GetCurrentPackageData();
        if (pinstanceData)
        {
            ptarget = 0;

            if (reinterpret_cast<Actor*>(apMob)->GetProcess())
            {
                if (reinterpret_cast<Actor*>(apMob)->GetProcess()->vfn_278())
                {
                    ptarget = reinterpret_cast<ActorPackageGetTarget*>(
                                  reinterpret_cast<Actor*>(apMob)->GetProcess()->vfn_278())
                                  ->GetTarget();
                }
            }

            reinterpret_cast<FUN_004211d0*>(pextra)->AttachActorPackageData(pinstanceData);

            reinterpret_cast<FUN_008c6060_shell*>(reinterpret_cast<char*>(this) + 4)->FUN_008c6060();
        }
    }
}

struct FUN_00924080_shell
{
    char pad[0x44];
    void* m_pReference40;  // +0x44
    void* m_pReference44;  // +0x48
    void* FUN_00924080(void* apActor, bool abSecondLoc);
};

// @fnv 0x00924080
void* FUN_00924080_shell::FUN_00924080(void* apActor, bool abSecondLoc)
{
    LocationDescriptor* pLoc;
    TESObjectREFR* pLocPack2;
    TESPackage* ppack7;

    pLoc = ((LocationDescriptor * (__thiscall*)(void*))(*(void***)this)[0x22c / 4])(this);
    if (!pLoc)
        return 0;
    ppack7 = 0;
    pLocPack2 = ((TESObjectREFR * (__thiscall*)(void*, void*, void*, bool))(*(void***)this)[0x814 / 4])(
        this, apActor, pLoc, abSecondLoc);
    if (!abSecondLoc)
        m_pReference40 = pLocPack2;
    else
        m_pReference44 = pLocPack2;
    return pLocPack2;
}

namespace fnv_00913250 {
struct ExtraDataListPackageExtra
{
    TESPackage* GetPackageOverride();
};

struct ExtraDataListFunctions
{
    int FUN_0041cb40();
    bool FUN_0041cba0();
    bool FUN_0041cc00();
    bool GetByteAtOffset26();
    void FUN_0041cc60();
    void FUN_004212e0();
};

struct FUN_0041cb70_shell
{
    TESObjectREFR* FUN_0041cb70();
};

struct FUN_004212b0_shell
{
    ActorPackageData* FUN_004212b0();
};

struct ActorPackageInit
{
    void SetPackageAndTarget(TESPackage*, TESObjectREFR*);
};

struct TESScriptableForm
{
    void Initialize(unsigned int);
};

struct GO
{
    operator TESPackage*() const;
};

struct FUN_00913250_shell : LowProcess
{
    void InitPackageFromExtraData(MobileObject*);
};

// Reads the mobile object's package extra data and initializes the process's package, target and flags, or resets them when no package is present.
// @fnv 0x00913250
void FUN_00913250_shell::InitPackageFromExtraData(MobileObject* apMob)
{
    ExtraDataList* pextra2;
    int iElementIndex;
    PACKAGE_PROCEDURE_TYPE eprocType;
    ActorPackageData* pactorPackData;

    pextra2 = apMob->GetExtraData();
    if (reinterpret_cast<ExtraDataListPackageExtra*>(pextra2)->GetPackageOverride())
    {
        if (apMob->IsActor())
            UpdateCurrentPackage(reinterpret_cast<Actor*>(apMob));

        reinterpret_cast<ActorPackageInit*>(reinterpret_cast<unsigned char*>(this) + 4)
            ->SetPackageAndTarget(reinterpret_cast<ExtraDataListPackageExtra*>(pextra2)->GetPackageOverride(),
                                  reinterpret_cast<FUN_0041cb70_shell*>(pextra2)->FUN_0041cb70());

        apMob->TESForm::Revert(reinterpret_cast<unsigned int>(GetCurrentPackage()));

        iElementIndex = reinterpret_cast<ExtraDataListFunctions*>(pextra2)->FUN_0041cb40();
        eprocType = static_cast<PACKAGE_PROCEDURE_TYPE>(
            reinterpret_cast<TESPackage*>(
                reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(this) + 4)->operator TESPackage*())
                ->GetProcedureType());
        if (eprocType != static_cast<PACKAGE_PROCEDURE_TYPE>(-1) && iElementIndex >= FUN_0096a820(static_cast<int>(eprocType)))
            iElementIndex = 0;

        vfn_238(iElementIndex);
        SetTarget(reinterpret_cast<FUN_0041cb70_shell*>(pextra2)->FUN_0041cb70());
        vfn_118(reinterpret_cast<ExtraDataListFunctions*>(pextra2)->FUN_0041cba0());
        vfn_5a8(reinterpret_cast<ExtraDataListFunctions*>(pextra2)->GetByteAtOffset26());
        vfn_4ec(reinterpret_cast<ExtraDataListFunctions*>(pextra2)->FUN_0041cc00());

        reinterpret_cast<ExtraDataListFunctions*>(pextra2)->FUN_0041cc60();
        pactorPackData = reinterpret_cast<FUN_004212b0_shell*>(pextra2)->FUN_004212b0();
        if (pactorPackData)
        {
            reinterpret_cast<TESScriptableForm*>(reinterpret_cast<unsigned char*>(this) + 4)
                ->Initialize(reinterpret_cast<unsigned int>(pactorPackData));
            reinterpret_cast<ExtraDataListFunctions*>(pextra2)->FUN_004212e0();
        }
    }
    else
    {
        if (apMob->IsActor())
            UpdateCurrentPackage(reinterpret_cast<Actor*>(apMob));

        vfn_234();
        SetTarget(0);
        vfn_118(0);
        SetFlag40(0);
        vfn_5a8(false);
        vfn_4ec(false);
    }
}
}  // namespace fnv_00913250

struct PkgData
{
    int GetVal();
    void SetVal(int);
    PkgData* GetSub();
    void SetA(int);
    void SetB(Actor*);
    unsigned int GetFlagsX();
    void SetFlagsX(unsigned int);
};

struct PkgObj
{
    PkgData* GetLocationPointer();
    int GetA();
    PkgData* GetObjA();
    void SetLocVal(int);
    void SetLoc2(PkgData*);
    void SetProc(int);
    void SetTargetA(TESObjectREFR*);
    void InitP(int);
    void SetMustReach(bool);
    void SetMustDone(bool);
};
PkgObj* __cdecl MakeStandIn(int);

struct RefArg
{
    int GetSomething();
    PkgData* GetLocationPointer();
};

struct ProcStub
{
    virtual void p_v0();
    virtual void p_v1();
    virtual void p_v2();
    virtual void p_v3();
    virtual void p_v4();
    virtual void p_v5();
    virtual void p_v6();
    virtual void p_v7();
    virtual void p_v8();
    virtual void p_v9();
    virtual void vfn_28();
    virtual void p_v11();
    virtual void p_v12();
    virtual void p_v13();
    virtual void p_v14();
    virtual void p_v15();
    virtual void p_v16();
    virtual void p_v17();
    virtual void p_v18();
    virtual void p_v19();
    virtual void p_v20();
    virtual void p_v21();
    virtual void p_v22();
    virtual void p_v23();
    virtual void p_v24();
    virtual void p_v25();
    virtual void p_v26();
    virtual void p_v27();
    virtual void p_v28();
    virtual void p_v29();
    virtual void p_v30();
    virtual void p_v31();
    virtual void p_v32();
    virtual void p_v33();
    virtual void p_v34();
    virtual void p_v35();
    virtual void p_v36();
    virtual void p_v37();
    virtual void p_v38();
    virtual void p_v39();
    virtual void p_v40();
    virtual void p_v41();
    virtual void p_v42();
    virtual void p_v43();
    virtual void p_v44();
    virtual void p_v45();
    virtual void p_v46();
    virtual void p_v47();
    virtual void p_v48();
    virtual void p_v49();
    virtual void p_v50();
    virtual void p_v51();
    virtual void p_v52();
    virtual void p_v53();
    virtual void p_v54();
    virtual void p_v55();
    virtual void p_v56();
    virtual void p_v57();
    virtual void p_v58();
    virtual void p_v59();
    virtual void p_v60();
    virtual void p_v61();
    virtual void p_v62();
    virtual void p_v63();
    virtual void p_v64();
    virtual void p_v65();
    virtual void p_v66();
    virtual void p_v67();
    virtual void p_v68();
    virtual void p_v69();
    virtual void p_v70();
    virtual void p_v71();
    virtual void p_v72();
    virtual void p_v73();
    virtual void p_v74();
    virtual void vfn_12c(Actor*);
    virtual void p_v76();
    virtual void p_v77();
    virtual void p_v78();
    virtual void p_v79();
    virtual void p_v80();
    virtual void p_v81();
    virtual void p_v82();
    virtual void p_v83();
    virtual void p_v84();
    virtual void p_v85();
    virtual void p_v86();
    virtual void p_v87();
    virtual void p_v88();
    virtual void p_v89();
    virtual void p_v90();
    virtual void p_v91();
    virtual void p_v92();
    virtual void p_v93();
    virtual void p_v94();
    virtual void p_v95();
    virtual void p_v96();
    virtual void p_v97();
    virtual void p_v98();
    virtual void p_v99();
    virtual void p_v100();
    virtual void p_v101();
    virtual void p_v102();
    virtual void p_v103();
    virtual void p_v104();
    virtual void p_v105();
    virtual void p_v106();
    virtual void p_v107();
    virtual void p_v108();
    virtual void p_v109();
    virtual void p_v110();
    virtual void p_v111();
    virtual void p_v112();
    virtual void p_v113();
    virtual void p_v114();
    virtual void p_v115();
    virtual void p_v116();
    virtual void p_v117();
    virtual void p_v118();
    virtual void p_v119();
    virtual void p_v120();
    virtual void p_v121();
    virtual void p_v122();
    virtual void p_v123();
    virtual void p_v124();
    virtual void p_v125();
    virtual void p_v126();
    virtual void p_v127();
    virtual void p_v128();
    virtual void p_v129();
    virtual void p_v130();
    virtual void p_v131();
    virtual void p_v132();
    virtual void p_v133();
    virtual void p_v134();
    virtual void p_v135();
    virtual void p_v136();
    virtual void p_v137();
    virtual void p_v138();
    virtual void p_v139();
    virtual void p_v140();
    virtual void p_v141();
    virtual void p_v142();
    virtual void p_v143();
    virtual void p_v144();
    virtual void p_v145();
    virtual void p_v146();
    virtual void p_v147();
    virtual void p_v148();
    virtual void p_v149();
    virtual void p_v150();
    virtual void p_v151();
    virtual void p_v152();
    virtual void p_v153();
    virtual void p_v154();
    virtual void p_v155();
    virtual void p_v156();
    virtual void p_v157();
    virtual void p_v158();
    virtual void p_v159();
    virtual void p_v160();
    virtual void p_v161();
    virtual void p_v162();
    virtual void p_v163();
    virtual void p_v164();
    virtual void p_v165();
    virtual void p_v166();
    virtual void p_v167();
    virtual void p_v168();
    virtual void p_v169();
    virtual void p_v170();
    virtual void p_v171();
    virtual void p_v172();
    virtual void p_v173();
    virtual void p_v174();
    virtual void p_v175();
    virtual void p_v176();
    virtual void p_v177();
    virtual void p_v178();
    virtual void p_v179();
    virtual void p_v180();
    virtual void p_v181();
    virtual void p_v182();
    virtual void p_v183();
    virtual void p_v184();
    virtual void p_v185();
    virtual void p_v186();
    virtual void p_v187();
    virtual void p_v188();
    virtual void p_v189();
    virtual void p_v190();
    virtual void p_v191();
    virtual void p_v192();
    virtual void p_v193();
    virtual void p_v194();
    virtual void p_v195();
    virtual void p_v196();
    virtual void p_v197();
    virtual void p_v198();
    virtual void p_v199();
    virtual void p_v200();
    virtual void p_v201();
    virtual void p_v202();
    virtual void p_v203();
    virtual void p_v204();
    virtual void p_v205();
    virtual void p_v206();
    virtual void p_v207();
    virtual void p_v208();
    virtual void p_v209();
    virtual void p_v210();
    virtual void p_v211();
    virtual void p_v212();
    virtual void p_v213();
    virtual void p_v214();
    virtual void p_v215();
    virtual void p_v216();
    virtual void p_v217();
    virtual void p_v218();
    virtual void p_v219();
    virtual void p_v220();
    virtual void p_v221();
    virtual void p_v222();
    virtual void p_v223();
    virtual void p_v224();
    virtual void p_v225();
    virtual void p_v226();
    virtual void p_v227();
    virtual void p_v228();
    virtual void p_v229();
    virtual void p_v230();
    virtual void p_v231();
    virtual void p_v232();
    virtual void p_v233();
    virtual void p_v234();
    virtual void p_v235();
    virtual void p_v236();
    virtual void p_v237();
    virtual void p_v238();
    virtual void p_v239();
    virtual void p_v240();
    virtual void p_v241();
    virtual void p_v242();
    virtual void p_v243();
    virtual void p_v244();
    virtual void p_v245();
    virtual void p_v246();
    virtual void p_v247();
    virtual void p_v248();
    virtual void p_v249();
    virtual void p_v250();
    virtual void p_v251();
    virtual void p_v252();
    virtual void p_v253();
    virtual void p_v254();
    virtual void p_v255();
    virtual void p_v256();
    virtual void p_v257();
    virtual void p_v258();
    virtual void p_v259();
    virtual void p_v260();
    virtual void p_v261();
    virtual void p_v262();
    virtual void p_v263();
    virtual void p_v264();
    virtual void p_v265();
    virtual void p_v266();
    virtual void p_v267();
    virtual void p_v268();
    virtual void p_v269();
    virtual void p_v270();
    virtual void p_v271();
    virtual void p_v272();
    virtual void p_v273();
    virtual void p_v274();
    virtual void p_v275();
    virtual void p_v276();
    virtual void p_v277();
    virtual void p_v278();
    virtual void p_v279();
    virtual void p_v280();
    virtual void p_v281();
    virtual void p_v282();
    virtual void p_v283();
    virtual void p_v284();
    virtual void p_v285();
    virtual void p_v286();
    virtual void p_v287();
    virtual void p_v288();
    virtual void p_v289();
    virtual void p_v290();
    virtual void p_v291();
    virtual void p_v292();
    virtual void p_v293();
    virtual void p_v294();
    virtual void p_v295();
    virtual void p_v296();
    virtual void p_v297();
    virtual void p_v298();
    virtual void p_v299();
    virtual void p_v300();
    virtual void p_v301();
    virtual void p_v302();
    virtual void p_v303();
    virtual void p_v304();
    virtual void p_v305();
    virtual void p_v306();
    virtual void p_v307();
    virtual void p_v308();
    virtual void p_v309();
    virtual void p_v310();
    virtual void p_v311();
    virtual void p_v312();
    virtual void p_v313();
    virtual void p_v314();
    virtual void p_v315();
    virtual void p_v316();
    virtual void p_v317();
    virtual void p_v318();
    virtual void p_v319();
    virtual void p_v320();
    virtual void p_v321();
    virtual void p_v322();
    virtual void p_v323();
    virtual void p_v324();
    virtual void p_v325();
    virtual void p_v326();
    virtual void p_v327();
    virtual void p_v328();
    virtual void p_v329();
    virtual void p_v330();
    virtual void p_v331();
    virtual void p_v332();
    virtual void p_v333();
    virtual void p_v334();
    virtual void p_v335();
    virtual void p_v336();
    virtual void p_v337();
    virtual void p_v338();
    virtual void p_v339();
    virtual void p_v340();
    virtual void p_v341();
    virtual void p_v342();
    virtual void p_v343();
    virtual void p_v344();
    virtual void p_v345();
    virtual void p_v346();
    virtual void p_v347();
    virtual void p_v348();
    virtual void p_v349();
    virtual void p_v350();
    virtual void p_v351();
    virtual void p_v352();
    virtual void p_v353();
    virtual void p_v354();
    virtual void p_v355();
    virtual void p_v356();
    virtual void p_v357();
    virtual void p_v358();
    virtual void p_v359();
    virtual void p_v360();
    virtual void p_v361();
    virtual void p_v362();
    virtual void p_v363();
    virtual void p_v364();
    virtual void p_v365();
    virtual void p_v366();
    virtual void p_v367();
    virtual void p_v368();
    virtual void p_v369();
    virtual void p_v370();
    virtual void p_v371();
    virtual void p_v372();
    virtual void p_v373();
    virtual void p_v374();
    virtual void p_v375();
    virtual void p_v376();
    virtual void p_v377();
    virtual void p_v378();
    virtual void p_v379();
    virtual void p_v380();
    virtual void p_v381();
    virtual void p_v382();
    virtual void p_v383();
    virtual void p_v384();
    virtual void p_v385();
    virtual void p_v386();
    virtual void p_v387();
    virtual void p_v388();
    virtual void p_v389();
    virtual void p_v390();
    virtual void p_v391();
    virtual void p_v392();
    virtual void p_v393();
    virtual void p_v394();
    virtual void p_v395();
    virtual void p_v396();
    virtual void p_v397();
    virtual void p_v398();
    virtual void p_v399();
    virtual void p_v400();
    virtual void p_v401();
    virtual void p_v402();
    virtual void p_v403();
    virtual void p_v404();
    virtual void p_v405();
    virtual void p_v406();
    virtual void p_v407();
    virtual void p_v408();
    virtual void p_v409();
    virtual void p_v410();
    virtual void p_v411();
    virtual void p_v412();
    virtual void p_v413();
    virtual void p_v414();
    virtual void p_v415();
    virtual void p_v416();
    virtual void p_v417();
    virtual void p_v418();
    virtual void p_v419();
    virtual void p_v420();
    virtual void p_v421();
    virtual void p_v422();
    virtual void p_v423();
    virtual void p_v424();
    virtual void p_v425();
    virtual void p_v426();
    virtual void p_v427();
    virtual void p_v428();
    virtual void p_v429();
    virtual void p_v430();
    virtual void p_v431();
    virtual void p_v432();
    virtual void p_v433();
    virtual void p_v434();
    virtual void p_v435();
    virtual void p_v436();
    virtual void p_v437();
    virtual void p_v438();
    virtual void p_v439();
    virtual void p_v440();
    virtual void p_v441();
    virtual void p_v442();
    virtual void p_v443();
    virtual void p_v444();
    virtual void p_v445();
    virtual void p_v446();
    virtual void p_v447();
    virtual void p_v448();
    virtual void p_v449();
    virtual void p_v450();
    virtual void p_v451();
    virtual void vfn_710(Actor*);
};

struct ActorStub
{
    virtual void a_v0();
    virtual void a_v1();
    virtual void a_v2();
    virtual void a_v3();
    virtual void a_v4();
    virtual void a_v5();
    virtual void a_v6();
    virtual void a_v7();
    virtual void a_v8();
    virtual void a_v9();
    virtual void a_v10();
    virtual void a_v11();
    virtual void a_v12();
    virtual void a_v13();
    virtual void a_v14();
    virtual void a_v15();
    virtual void a_v16();
    virtual void a_v17();
    virtual void a_v18();
    virtual void a_v19();
    virtual void a_v20();
    virtual void a_v21();
    virtual void a_v22();
    virtual void a_v23();
    virtual void a_v24();
    virtual void a_v25();
    virtual void a_v26();
    virtual void a_v27();
    virtual void a_v28();
    virtual void a_v29();
    virtual void a_v30();
    virtual void a_v31();
    virtual void a_v32();
    virtual void a_v33();
    virtual void a_v34();
    virtual void a_v35();
    virtual void a_v36();
    virtual void a_v37();
    virtual void a_v38();
    virtual void a_v39();
    virtual void a_v40();
    virtual void a_v41();
    virtual void a_v42();
    virtual void a_v43();
    virtual void a_v44();
    virtual void a_v45();
    virtual void a_v46();
    virtual void a_v47();
    virtual void a_v48();
    virtual void a_v49();
    virtual void a_v50();
    virtual void a_v51();
    virtual void a_v52();
    virtual void a_v53();
    virtual void a_v54();
    virtual void a_v55();
    virtual void a_v56();
    virtual void a_v57();
    virtual void a_v58();
    virtual void a_v59();
    virtual void a_v60();
    virtual void a_v61();
    virtual void a_v62();
    virtual void a_v63();
    virtual void a_v64();
    virtual void a_v65();
    virtual void a_v66();
    virtual void a_v67();
    virtual void a_v68();
    virtual void a_v69();
    virtual void a_v70();
    virtual void a_v71();
    virtual void a_v72();
    virtual void a_v73();
    virtual void a_v74();
    virtual void a_v75();
    virtual void a_v76();
    virtual void a_v77();
    virtual void a_v78();
    virtual void a_v79();
    virtual void a_v80();
    virtual void a_v81();
    virtual void a_v82();
    virtual void a_v83();
    virtual void a_v84();
    virtual void a_v85();
    virtual void a_v86();
    virtual void a_v87();
    virtual void a_v88();
    virtual void a_v89();
    virtual void a_v90();
    virtual void a_v91();
    virtual void a_v92();
    virtual void a_v93();
    virtual void a_v94();
    virtual void a_v95();
    virtual void a_v96();
    virtual void a_v97();
    virtual void a_v98();
    virtual void a_v99();
    virtual void a_v100();
    virtual void a_v101();
    virtual void a_v102();
    virtual void a_v103();
    virtual void a_v104();
    virtual void a_v105();
    virtual void a_v106();
    virtual void a_v107();
    virtual void a_v108();
    virtual void a_v109();
    virtual void a_v110();
    virtual void a_v111();
    virtual void a_v112();
    virtual void a_v113();
    virtual void a_v114();
    virtual void a_v115();
    virtual void a_v116();
    virtual void a_v117();
    virtual void a_v118();
    virtual void a_v119();
    virtual void a_v120();
    virtual void a_v121();
    virtual void a_v122();
    virtual void a_v123();
    virtual void a_v124();
    virtual void a_v125();
    virtual void a_v126();
    virtual void a_v127();
    virtual void a_v128();
    virtual void a_v129();
    virtual void a_v130();
    virtual void a_v131();
    virtual void a_v132();
    virtual void a_v133();
    virtual void a_v134();
    virtual void a_v135();
    virtual void a_v136();
    virtual void a_v137();
    virtual void a_v138();
    virtual void a_v139();
    virtual void a_v140();
    virtual void a_v141();
    virtual void a_v142();
    virtual void a_v143();
    virtual void a_v144();
    virtual void a_v145();
    virtual void a_v146();
    virtual void a_v147();
    virtual void a_v148();
    virtual void a_v149();
    virtual void a_v150();
    virtual void a_v151();
    virtual void a_v152();
    virtual void a_v153();
    virtual void a_v154();
    virtual void a_v155();
    virtual void a_v156();
    virtual void a_v157();
    virtual void a_v158();
    virtual void a_v159();
    virtual void a_v160();
    virtual void a_v161();
    virtual void a_v162();
    virtual void a_v163();
    virtual void a_v164();
    virtual void a_v165();
    virtual void a_v166();
    virtual void a_v167();
    virtual void a_v168();
    virtual void a_v169();
    virtual void a_v170();
    virtual void a_v171();
    virtual void a_v172();
    virtual void a_v173();
    virtual void a_v174();
    virtual void a_v175();
    virtual void a_v176();
    virtual void a_v177();
    virtual void a_v178();
    virtual void a_v179();
    virtual void a_v180();
    virtual void a_v181();
    virtual void a_v182();
    virtual void a_v183();
    virtual void a_v184();
    virtual void a_v185();
    virtual void a_v186();
    virtual void a_v187();
    virtual void a_v188();
    virtual void vfn_2f4(PkgObj*, int, int);
    ProcStub* GetProc();
};

struct ArgActor
{
    virtual void g_v0();
    virtual void g_v1();
    virtual void g_v2();
    virtual void g_v3();
    virtual void g_v4();
    virtual void g_v5();
    virtual void g_v6();
    virtual void g_v7();
    virtual void g_v8();
    virtual void g_v9();
    virtual void g_v10();
    virtual void g_v11();
    virtual void g_v12();
    virtual void g_v13();
    virtual void g_v14();
    virtual void g_v15();
    virtual void g_v16();
    virtual void g_v17();
    virtual void g_v18();
    virtual void g_v19();
    virtual void g_v20();
    virtual void g_v21();
    virtual void g_v22();
    virtual void g_v23();
    virtual void g_v24();
    virtual void g_v25();
    virtual void g_v26();
    virtual void g_v27();
    virtual void g_v28();
    virtual void g_v29();
    virtual void g_v30();
    virtual void g_v31();
    virtual void g_v32();
    virtual void g_v33();
    virtual void g_v34();
    virtual void g_v35();
    virtual void g_v36();
    virtual void g_v37();
    virtual void g_v38();
    virtual void g_v39();
    virtual void g_v40();
    virtual void g_v41();
    virtual void g_v42();
    virtual void g_v43();
    virtual void g_v44();
    virtual void g_v45();
    virtual void g_v46();
    virtual void g_v47();
    virtual void g_v48();
    virtual void g_v49();
    virtual void g_v50();
    virtual void g_v51();
    virtual void g_v52();
    virtual void g_v53();
    virtual void g_v54();
    virtual void g_v55();
    virtual void g_v56();
    virtual void g_v57();
    virtual void g_v58();
    virtual void g_v59();
    virtual void g_v60();
    virtual void g_v61();
    virtual void g_v62();
    virtual void g_v63();
    virtual void g_v64();
    virtual void g_v65();
    virtual void g_v66();
    virtual void g_v67();
    virtual void g_v68();
    virtual void g_v69();
    virtual void g_v70();
    virtual void g_v71();
    virtual void g_v72();
    virtual void g_v73();
    virtual void g_v74();
    virtual void g_v75();
    virtual void g_v76();
    virtual void g_v77();
    virtual void g_v78();
    virtual void g_v79();
    virtual void g_v80();
    virtual void g_v81();
    virtual void g_v82();
    virtual void g_v83();
    virtual void g_v84();
    virtual void g_v85();
    virtual void g_v86();
    virtual void g_v87();
    virtual void g_v88();
    virtual void g_v89();
    virtual void g_v90();
    virtual void g_v91();
    virtual void g_v92();
    virtual void g_v93();
    virtual void g_v94();
    virtual void g_v95();
    virtual void g_v96();
    virtual void g_v97();
    virtual void g_v98();
    virtual void g_v99();
    virtual void g_v100();
    virtual void g_v101();
    virtual void g_v102();
    virtual void g_v103();
    virtual void g_v104();
    virtual void g_v105();
    virtual void g_v106();
    virtual void g_v107();
    virtual void g_v108();
    virtual void g_v109();
    virtual void g_v110();
    virtual void g_v111();
    virtual void g_v112();
    virtual void g_v113();
    virtual void g_v114();
    virtual void g_v115();
    virtual void g_v116();
    virtual void g_v117();
    virtual void g_v118();
    virtual void g_v119();
    virtual void g_v120();
    virtual void g_v121();
    virtual void g_v122();
    virtual void g_v123();
    virtual void g_v124();
    virtual void g_v125();
    virtual void g_v126();
    virtual void g_v127();
    virtual void g_v128();
    virtual void g_v129();
    virtual void g_v130();
    virtual void g_v131();
    virtual void g_v132();
    virtual int vfn_214();
    virtual void g_v134();
    virtual void g_v135();
    virtual void g_v136();
    virtual void g_v137();
    virtual void g_v138();
    virtual void g_v139();
    virtual void g_v140();
    virtual void g_v141();
    virtual void g_v142();
    virtual void g_v143();
    virtual void g_v144();
    virtual void g_v145();
    virtual void g_v146();
    virtual void g_v147();
    virtual void g_v148();
    virtual void g_v149();
    virtual void g_v150();
    virtual void g_v151();
    virtual void g_v152();
    virtual void g_v153();
    virtual void g_v154();
    virtual void g_v155();
    virtual void g_v156();
    virtual void g_v157();
    virtual void g_v158();
    virtual void g_v159();
    virtual void g_v160();
    virtual void g_v161();
    virtual void g_v162();
    virtual void g_v163();
    virtual void g_v164();
    virtual void g_v165();
    virtual void g_v166();
    virtual void g_v167();
    virtual void g_v168();
    virtual void g_v169();
    virtual void g_v170();
    virtual void g_v171();
    virtual void g_v172();
    virtual void g_v173();
    virtual void g_v174();
    virtual void g_v175();
    virtual void g_v176();
    virtual void g_v177();
    virtual void g_v178();
    virtual void g_v179();
    virtual void g_v180();
    virtual void g_v181();
    virtual void g_v182();
    virtual void g_v183();
    virtual void g_v184();
    virtual void g_v185();
    virtual void g_v186();
    virtual void g_v187();
    virtual void g_v188();
    virtual void g_v189();
    virtual void g_v190();
    virtual void g_v191();
    virtual void g_v192();
    virtual void g_v193();
    virtual void g_v194();
    virtual void g_v195();
    virtual void g_v196();
    virtual void g_v197();
    virtual void g_v198();
    virtual void g_v199();
    virtual void g_v200();
    virtual void g_v201();
    virtual void g_v202();
    virtual void g_v203();
    virtual void g_v204();
    virtual void g_v205();
    virtual void g_v206();
    virtual void g_v207();
    virtual void g_v208();
    virtual void g_v209();
    virtual void g_v210();
    virtual void g_v211();
    virtual void g_v212();
    virtual void g_v213();
    virtual void g_v214();
    virtual void g_v215();
    virtual void g_v216();
    virtual void g_v217();
    virtual void g_v218();
    virtual void g_v219();
    virtual void g_v220();
    virtual void g_v221();
    virtual void g_v222();
    virtual void g_v223();
    virtual void g_v224();
    virtual void g_v225();
    virtual void g_v226();
    virtual void g_v227();
    virtual void g_v228();
    virtual void g_v229();
    virtual void g_v230();
    virtual void g_v231();
    virtual void g_v232();
    virtual void g_v233();
    virtual void g_v234();
    virtual void g_v235();
    virtual void g_v236();
    virtual void g_v237();
    virtual void g_v238();
    virtual void g_v239();
    virtual void g_v240();
    virtual void g_v241();
    virtual void g_v242();
    virtual void g_v243();
    virtual void g_v244();
    virtual void g_v245();
    virtual void g_v246();
    virtual void g_v247();
    virtual void g_v248();
    virtual void g_v249();
    virtual void g_v250();
    virtual void g_v251();
    virtual void g_v252();
    virtual void g_v253();
    virtual void g_v254();
    virtual void g_v255();
    virtual void g_v256();
    virtual void g_v257();
    virtual void g_v258();
    virtual void g_v259();
    virtual void g_v260();
    virtual void g_v261();
    virtual void vfn_418();
    void Notify(Actor*);
};

struct OwnerBase
{
    virtual void o_v0();
    virtual void o_v1();
    virtual void o_v2();
    virtual void o_v3();
    virtual void o_v4();
    virtual void o_v5();
    virtual void o_v6();
    virtual void o_v7();
    virtual void o_v8();
    virtual void o_v9();
    virtual void o_v10();
    virtual void o_v11();
    virtual void o_v12();
    virtual void o_v13();
    virtual void o_v14();
    virtual void o_v15();
    virtual void o_v16();
    virtual void o_v17();
    virtual void o_v18();
    virtual void o_v19();
    virtual void o_v20();
    virtual void o_v21();
    virtual void o_v22();
    virtual void o_v23();
    virtual void o_v24();
    virtual void o_v25();
    virtual void o_v26();
    virtual void o_v27();
    virtual void o_v28();
    virtual void o_v29();
    virtual void o_v30();
    virtual void o_v31();
    virtual void o_v32();
    virtual void o_v33();
    virtual void o_v34();
    virtual void o_v35();
    virtual void o_v36();
    virtual void o_v37();
    virtual void o_v38();
    virtual void o_v39();
    virtual void o_v40();
    virtual void o_v41();
    virtual void o_v42();
    virtual void o_v43();
    virtual void o_v44();
    virtual void o_v45();
    virtual void o_v46();
    virtual void o_v47();
    virtual void o_v48();
    virtual void o_v49();
    virtual void o_v50();
    virtual void o_v51();
    virtual void o_v52();
    virtual void o_v53();
    virtual void o_v54();
    virtual void o_v55();
    virtual void o_v56();
    virtual void o_v57();
    virtual void o_v58();
    virtual void o_v59();
    virtual void o_v60();
    virtual void o_v61();
    virtual void o_v62();
    virtual void o_v63();
    virtual void o_v64();
    virtual void o_v65();
    virtual void o_v66();
    virtual void o_v67();
    virtual void o_v68();
    virtual void o_v69();
    virtual void o_v70();
    virtual void o_v71();
    virtual void o_v72();
    virtual void o_v73();
    virtual void o_v74();
    virtual void o_v75();
    virtual void o_v76();
    virtual void o_v77();
    virtual void o_v78();
    virtual void o_v79();
    virtual void o_v80();
    virtual void o_v81();
    virtual void o_v82();
    virtual void o_v83();
    virtual void o_v84();
    virtual void o_v85();
    virtual void o_v86();
    virtual void o_v87();
    virtual void o_v88();
    virtual void o_v89();
    virtual void o_v90();
    virtual void o_v91();
    virtual void o_v92();
    virtual void o_v93();
    virtual void o_v94();
    virtual void o_v95();
    virtual void o_v96();
    virtual void o_v97();
    virtual void o_v98();
    virtual void o_v99();
    virtual void o_v100();
    virtual void o_v101();
    virtual void o_v102();
    virtual void o_v103();
    virtual void o_v104();
    virtual void o_v105();
    virtual void o_v106();
    virtual void o_v107();
    virtual void o_v108();
    virtual void o_v109();
    virtual void o_v110();
    virtual void o_v111();
    virtual void o_v112();
    virtual void o_v113();
    virtual void o_v114();
    virtual void o_v115();
    virtual void o_v116();
    virtual void o_v117();
    virtual void o_v118();
    virtual void o_v119();
    virtual void o_v120();
    virtual void o_v121();
    virtual void o_v122();
    virtual void o_v123();
    virtual void o_v124();
    virtual void o_v125();
    virtual void o_v126();
    virtual void o_v127();
    virtual void o_v128();
    virtual void o_v129();
    virtual void o_v130();
    virtual void o_v131();
    virtual void o_v132();
    virtual void o_v133();
    virtual void o_v134();
    virtual void o_v135();
    virtual void o_v136();
    virtual void o_v137();
    virtual void o_v138();
    virtual void* vfn_22c();
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
    TESObjectREFR* pTarget;
    void FUN_00908cd0(Actor* apActor, TESObjectREFR* apRef, int a3);
};

// @fnv 0x00908cd0
void OwnerBase::FUN_00908cd0(Actor* apActor, TESObjectREFR* apRef, int a3)
{
    Actor* pTargetActor2 = dynamic_cast<Actor*>(pTarget);
    if (pTargetActor2 == apActor || !pTargetActor2 || pTargetActor2 == (Actor*)g_thePlayer)
        return;
    if (((ArgActor*)apActor)->vfn_214())
        ((ArgActor*)apActor)->vfn_418();
    PkgObj* pPackage = MakeStandIn(1);
    pPackage->InitP(1);
    pPackage->SetMustReach(true);
    pPackage->SetMustDone(true);
    pPackage->SetLocVal(((PkgObj*)vfn_22c())->GetA());
    pPackage->GetObjA()->SetVal(((RefArg*)apRef)->GetSomething());
    pPackage->SetLoc2(((PkgObj*)vfn_22c())->GetLocationPointer());
    pPackage->SetProc(6);
    pPackage->GetLocationPointer()->SetA(0);
    pPackage->GetLocationPointer()->SetB(apActor);
    pPackage->GetLocationPointer()->SetFlagsX(((RefArg*)apRef)->GetLocationPointer()->GetFlagsX());
    pPackage->SetTargetA(apRef);
    ProcStub* pProcess = ((ActorStub*)pTargetActor2)->GetProc();
    pProcess->vfn_28();
    pProcess->vfn_710(pTargetActor2);
    ((ArgActor*)apActor)->Notify(pTargetActor2);
    ((ActorStub*)pTargetActor2)->vfn_2f4(pPackage, 0, 1);
    pProcess->vfn_12c(apActor);
}

class TESNPC : public TESBoundObject
{
  public:
    void InitWornForm(Actor* apActor, ValidBip01Names* apNames, bool abUpdate);
};

class TESCreature : public TESBoundObject
{
  public:
    void InitWornForm(Actor* apActor, bool abWeapon, bool abArmor, bool abUpdate);
};

class TESPackageEx : public TESPackage
{
  public:
    bool GetForceUnequipWeapon() const;
};

struct BaseProcessShell909320 : public BaseProcess
{
    void InitWornForms(Actor* apActor, bool abAddProcedure);
};

// @fnv 0x00909320
void BaseProcessShell909320::InitWornForms(Actor* apActor, bool abAddProcedure)
{
    TESNPC* pNPC8 = dynamic_cast<TESNPC*>(apActor->GetObjectReference());
    TESCreature* aPCreature = dynamic_cast<TESCreature*>(apActor->GetObjectReference());
    TESPackageEx* pPackage = (TESPackageEx*)GetCurrentPackage();
    bool bArmor_ = true;
    bool bWeapon = true;
    if (pPackage)
    {
        if (pPackage->GetPackType() == 4)
        {
            bArmor_ = false;
            bWeapon = false;
        }
        else if (pPackage->GetForceUnequipWeapon())
        {
            bWeapon = false;
        }
    }
    if (pNPC8)
    {
        pNPC8->InitWornForm(apActor, apActor->GetValidBip01Names(), true);
    }
    else if (aPCreature)
    {
        aPCreature->InitWornForm(apActor, bArmor_, bWeapon, true);
    }
    if (abAddProcedure)
    {
        SetProcessTarget(apActor, 1);
    }
}

class Actor909;

class Process909
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void unkv0BC();
    virtual void unkv0C0();
    virtual void unkv0C4();
    virtual void unkv0C8();
    virtual void unkv0CC();
    virtual void unkv0D0();
    virtual void unkv0D4();
    virtual void unkv0D8();
    virtual void unkv0DC();
    virtual void unkv0E0();
    virtual void unkv0E4();
    virtual void unkv0E8();
    virtual void unkv0EC();
    virtual void unkv0F0();
    virtual void unkv0F4();
    virtual void unkv0F8();
    virtual void unkv0FC();
    virtual void unkv100();
    virtual void unkv104();
    virtual void unkv108();
    virtual void unkv10C();
    virtual void unkv110();
    virtual void unkv114();
    virtual void unkv118();
    virtual void unkv11C();
    virtual void unkv120();
    virtual void unkv124();
    virtual void unkv128();
    virtual void unkv12C();
    virtual void unkv130();
    virtual void unkv134();
    virtual void unkv138();
    virtual bool unkv13C(Actor909* pkTarget, int iUnk, float fUnk, int iUnk2);
};

class Actor909
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void unkv0BC();
    virtual void unkv0C0();
    virtual void unkv0C4();
    virtual void unkv0C8();
    virtual void unkv0CC();
    virtual void unkv0D0();
    virtual void unkv0D4();
    virtual void unkv0D8();
    virtual void unkv0DC();
    virtual void unkv0E0();
    virtual void unkv0E4();
    virtual void unkv0E8();
    virtual void unkv0EC();
    virtual void unkv0F0();
    virtual void unkv0F4();
    virtual void unkv0F8();
    virtual void unkv0FC();
    virtual void unkv100();
    virtual void unkv104();
    virtual void unkv108();
    virtual void unkv10C();
    virtual void unkv110();
    virtual void unkv114();
    virtual void unkv118();
    virtual void unkv11C();
    virtual void unkv120();
    virtual void unkv124();
    virtual void unkv128();
    virtual void unkv12C();
    virtual void unkv130();
    virtual void unkv134();
    virtual void unkv138();
    virtual void unkv13C();
    virtual void unkv140();
    virtual void unkv144();
    virtual void unkv148();
    virtual void unkv14C();
    virtual void unkv150();
    virtual void unkv154();
    virtual void unkv158();
    virtual void unkv15C();
    virtual void unkv160();
    virtual void unkv164();
    virtual void unkv168();
    virtual void unkv16C();
    virtual void unkv170();
    virtual void unkv174();
    virtual void unkv178();
    virtual void unkv17C();
    virtual void unkv180();
    virtual void unkv184();
    virtual void unkv188();
    virtual void unkv18C();
    virtual void unkv190();
    virtual void unkv194();
    virtual void unkv198();
    virtual void unkv19C();
    virtual void unkv1A0();
    virtual void unkv1A4();
    virtual void unkv1A8();
    virtual void unkv1AC();
    virtual void unkv1B0();
    virtual void unkv1B4();
    virtual void unkv1B8();
    virtual void unkv1BC();
    virtual void unkv1C0();
    virtual void unkv1C4();
    virtual void unkv1C8();
    virtual void unkv1CC();
    virtual void unkv1D0();
    virtual void unkv1D4();
    virtual void unkv1D8();
    virtual void unkv1DC();
    virtual void unkv1E0();
    virtual void unkv1E4();
    virtual void unkv1E8();
    virtual void unkv1EC();
    virtual void unkv1F0();
    virtual void unkv1F4();
    virtual void unkv1F8();
    virtual void unkv1FC();
    virtual void unkv200();
    virtual void unkv204();
    virtual void unkv208();
    virtual void unkv20C();
    virtual void unkv210();
    virtual void unkv214();
    virtual void unkv218();
    virtual void unkv21C();
    virtual void unkv220();
    virtual void unkv224();
    virtual void unkv228();
    virtual Process909* GetProcess();

    float GetTargetValue(Actor909* pkTarget);
    void FUN_00881680(int iUnk);
    void FUN_00909c90(Actor909* pkTarget);
};

// @fnv 0x00909c90
void Actor909::FUN_00909c90(Actor909* pkTarget)
{
    if (!GetProcess()->unkv13C(pkTarget, 0, -1.0f, 0))
    {
        float fValue = GetTargetValue(pkTarget);
    }
    else
    {
        pkTarget->FUN_00881680(0);
    }
}

extern "C" void* __cdecl FUN_00ec43fb(int, int, const char*, const char*, int);
extern char DAT_011846d4;
extern char DAT_01184920;
extern const double DAT_01012640;

struct FUN_0090c360_res
{
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
    virtual void v064();
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
    virtual void v151(float);
};

struct FUN_0090c360_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
    void FUN_0090c360(SpellItem* spell, float t);
};

// @fnv 0x0090c360
void FUN_0090c360_cls::FUN_0090c360(SpellItem* spell, float t)
{
    if (spell == 0)
    {
        return;
    }
    {
        FUN_0090c360_res* r = (FUN_0090c360_res*)FUN_00ec43fb((int)spell, 0, &DAT_01184920, &DAT_011846d4, 0);
        if (r)
        {
            if (t > DAT_01012640)
            {
                CastSpellOnCaster(spell, true);
            }
            r->v151(0.0f);
        }
    }
}

struct RefProxy
{
    unsigned int FUN_0084e3a0();
};
struct ItemProxy
{
    RefProxy* ref;
};
struct ItemList
{
    ItemProxy*& FUN_006815c0();
    ItemList* FUN_00726070();
    void FUN_00905330(ItemProxy**);
    int unk00, unk04;
};
struct RefList
{
    RefProxy*& FUN_006815c0();
    RefList* FUN_00726070();
    void FUN_00905330(RefProxy**);
    void FUN_0063f7b0();
    int unk00, unk04;
};
struct OwnerProxy
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
    int unk3c;
    int unk40;
    RefProxy* unk44;
    int unk48, unk4c, unk50, unk54, unk58;
    ItemList list5c;
    ItemProxy* unk64;
    ItemProxy* unk68;
    RefList list6c;
    void RemoveById(unsigned int);
};
// @fnv 0x0090cdc0
void OwnerProxy::RemoveById(unsigned int id)
{
    if (unk64 && unk64->ref->FUN_0084e3a0() == id)
    {
        delete (Date*)unk64;
        unk64 = 0;
    }
    if (unk68 && unk68->ref->FUN_0084e3a0() == id)
    {
        delete (Date*)unk68;
        unk68 = 0;
    }
    ItemList* node = &list5c;
    while (node && node->FUN_006815c0())
    {
        ItemProxy* item = node->FUN_006815c0();
        if (item->ref->FUN_0084e3a0() == id)
        {
            list5c.FUN_00905330(&item);
            delete (Date*)item;
            node = &list5c;
        }
        else
        {
            node = node->FUN_00726070();
        }
    }
    if (unk44 && unk44->FUN_0084e3a0() == id)
        unk44 = 0;
    RefList* next = &list6c;
    RefList* previous = 0;
    while (next && next->FUN_006815c0())
    {
        RefProxy* object = next->FUN_006815c0();
        if (object->FUN_0084e3a0() == id)
        {
            if (previous)
            {
                previous->FUN_00905330(&object);
                next = previous->FUN_00726070();
            }
            else
            {
                next->FUN_0063f7b0();
            }
        }
        else
        {
            previous = next;
            next = next->FUN_00726070();
        }
    }
}

struct NiPoint3_90A130
{
    float x;
    float y;
    float z;

    static const NiPoint3_90A130 ZERO;
};

class C90A130Controller
{
  public:
    NiPoint3_90A130 FUN_00675de0(int iArg);
};

class C90A130Object
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual void VFunc160();
    virtual void VFunc164();
    virtual void VFunc168();
    virtual void VFunc16C();
    virtual void VFunc170();
    virtual void VFunc174();
    virtual void VFunc178();
    virtual void VFunc17C();
    virtual void VFunc180();
    virtual void VFunc184();
    virtual void VFunc188();
    virtual void VFunc18C();
    virtual void VFunc190();
    virtual void VFunc194();
    virtual void VFunc198();
    virtual void VFunc19C();
    virtual void VFunc1A0();
    virtual void VFunc1A4();
    virtual void VFunc1A8();
    virtual void VFunc1AC();
    virtual void VFunc1B0();
    virtual void VFunc1B4();
    virtual void VFunc1B8();
    virtual void VFunc1BC();
    virtual void VFunc1C0();
    virtual void VFunc1C4();
    virtual void VFunc1C8();
    virtual void VFunc1CC();
    virtual void VFunc1D0();
    virtual void VFunc1D4();
    virtual void VFunc1D8();
    virtual void VFunc1DC();
    virtual void VFunc1E0();
    virtual void VFunc1E4();
    virtual void VFunc1E8();
    virtual void VFunc1EC();
    virtual void VFunc1F0();
    virtual void VFunc1F4();
    virtual void VFunc1F8();
    virtual void VFunc1FC();
    virtual void VFunc200();
    virtual void VFunc204();
    virtual void VFunc208();
    virtual void VFunc20C();
    virtual void VFunc210();
    virtual void VFunc214();
    virtual void VFunc218();
    virtual void VFunc21C();
    virtual void VFunc220();
    virtual void VFunc224();
    virtual void VFunc228();
    virtual C90A130Controller* GetController();

    NiPoint3_90A130 GetControllerPoint(int iArg);
};

// Returns the controller's point for iArg via GetController, or NiPoint3_90A130::ZERO when there is no controller.
// @fnv 0x0090a130
NiPoint3_90A130 C90A130Object::GetControllerPoint(int iArg)
{
    if (GetController())
        return GetController()->FUN_00675de0(iArg);
    else
        return NiPoint3_90A130::ZERO;
}

struct WeightForm57
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
};
struct Ref57;
struct Form57;
struct Extra57;
struct Inventory57;
struct FUN_004459e0_Entry57;
struct BaseNode57;
struct Package57;
struct Form57
{
    int FUN_00401170();
    bool FUN_0046f070();
    bool FUN_0073b460();
};
struct Extra57
{
    Form57* FUN_004216f0();
    short FUN_00418770();
    Inventory57* FUN_00418520();
};
struct FUN_0090e600_Record
{
    Ref57* ref;
    Form57* form;
    int unk08, count, unk10;
    Extra57* extra;
    int inventory;
    FUN_0090e600_Record();
};
struct RecordList57
{
    int unk00, unk04;
    void FUN_00905820(FUN_0090e600_Record* const&);
};
struct Package57
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
    RecordList57 list;
    int unk7c, unk80;
    Form57* object;
    int unk88;
    unsigned int category;
    void* condition;
    int FUN_0045cd60();
};
struct Ref57
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
    bool FUN_00440d80();
    bool FUN_004077c0();
    bool FUN_00440da0();
    Form57* FUN_007af430();
    Package57* FUN_008d8520();
    bool FUN_008b8e90(void*);
    Extra57* FUN_005d43c0();
    bool FUN_00493bb0();
    float FUN_00568ad0();
    void* FUN_00575ca0();
    void* FUN_0055d310();
    int FUN_00575590(int, int);
    FUN_004459e0_Entry57* FUN_005754a0(int, int);
};
struct BaseItem57
{
    int count;
    Form57* form;
};
struct BaseNode57
{
    BaseItem57** FUN_006815c0();
    BaseNode57* FUN_00726070();
};
struct BaseList57
{
    BaseNode57* FUN_00717e50();
};
struct ExtraNode57
{
    Extra57** FUN_006815c0();
};
struct FUN_004459e0_Entry57
{
    ~FUN_004459e0_Entry57();
    bool FUN_004bddd0(int);
    float FUN_004bcdb0(int);
    Form57* FUN_0044ddc0();
    ExtraNode57* FUN_00559450();
};
struct Inventory57
{
    BaseList57* FUN_004bffb0();
    FUN_004459e0_Entry57* FUN_004d0650(Form57*, int);
    int FUN_004c8f30(Form57*);
};
bool __cdecl MatchesObjectType(Form57*, unsigned int);
Inventory57* __cdecl FUN_004bf220(Ref57*);
extern Ref57* DAT_011dea3c;
// Checks whether ref matches the target's package by category, object, condition and type, appending matching inventory records to the package list.
// @fnv 0x0090dd80
bool __cdecl CheckPackageMatch(Ref57* ref, long aTargetRef)
{
    Ref57* target20 = (Ref57*)aTargetRef;
    if (!ref || ref == target20 || ref->FUN_00440d80() || ref->FUN_004077c0() || ref->FUN_00440da0())
        return false;
    if (!target20)
        return true;
    FUN_0090e600_Record* record101 = 0;
    bool matches10 = false;
    Package57* package4 = 0;
    bool actor19 = ref->IsActor();
    Form57* form12 = ref->FUN_007af430();
    int type23 = form12->FUN_00401170();
    if (target20->FUN_008d8520())
    {
        switch (target20->FUN_008d8520()->FUN_0045cd60())
        {
        case 0:
        case 1:
        case 2:
        case 3:
            package4 = target20->FUN_008d8520();
            break;
        }
    }
    if (!package4)
        return true;
    if (package4->category && MatchesObjectType(form12, package4->category))
    {
        if (package4->condition && actor19)
        {
            Ref57* actorRef = ref;
            if (actorRef->FUN_008b8e90(package4->condition))
                matches10 = true;
        }
        else
            matches10 = true;
    }
    else if (package4->object)
    {
        if (package4->object == form12)
            matches10 = true;
        else if (actor19)
        {
            if (ref->FUN_005d43c0()->FUN_004216f0() == package4->object)
                matches10 = true;
        }
    }
    else if (!package4->category && !package4->object)
        matches10 = true;
    switch (type23)
    {
    case 30: {
        Form57* actorBase = form12;
        if (!actorBase->FUN_0046f070())
            matches10 = false;
        break;
    }
    case 25: {
        Form57* activator = form12;
        if (activator->FUN_0073b460())
            matches10 = false;
        break;
    }
    }
    void* unused9 = 0;
    bool checkWeight36 = false;
    if (type23 == 40)
    {
        WeightForm57* itemForm = (WeightForm57*)form12;
        void* weightComponent = itemForm ? &itemForm->unk94 : 0;
        if (target20->FUN_00493bb0())
            checkWeight36 = true;
        if (weightComponent && ref->FUN_00568ad0() <= 0.0 && checkWeight36)
            matches10 = false;
    }
    if (matches10)
    {
        record101 = new FUN_0090e600_Record;
        record101->form = ref->FUN_007af430();
        record101->ref = ref;
        record101->count = ref->FUN_005d43c0()->FUN_00418770();
        record101->inventory = 0;
        record101->extra = ref->FUN_005d43c0();
        package4->list.FUN_00905820(record101);
    }
    bool inventoryCategory12 = false;
    switch (package4->category)
    {
    case 0:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 22:
    case 23:
        inventoryCategory12 = true;
        break;
    }
    if ((inventoryCategory12 && actor19 && ref != DAT_011dea3c) || type23 == 27)
    {
        Inventory57* inventory27 = ref->FUN_005d43c0()->FUN_00418520();
        if (inventory27)
        {
            BaseNode57* node = 0;
            if (inventory27->FUN_004bffb0())
                node = inventory27->FUN_004bffb0()->FUN_00717e50();
            while (node && *node->FUN_006815c0())
            {
                bool baseMatch76 = false;
                BaseItem57* base14 = *node->FUN_006815c0();
                if (base14)
                {
                    FUN_004459e0_Entry57* existing = inventory27->FUN_004d0650(base14->form, 0);
                    if (!existing)
                    {
                        if (package4->category && MatchesObjectType(base14->form, package4->category))
                            baseMatch76 = true;
                        else if (package4->object && package4->object == base14->form)
                            baseMatch76 = true;
                        else if (!package4->category && !package4->object)
                            baseMatch76 = true;
                        if (baseMatch76 && ref->FUN_00575ca0() == target20->FUN_00575ca0())
                        {
                            record101 = new FUN_0090e600_Record;
                            record101->form = base14->form;
                            record101->ref = ref;
                            record101->inventory = 1;
                            void* container = ref->FUN_0055d310();
                            if (container)
                            {
                                Inventory57* changes = FUN_004bf220(ref);
                                if (changes)
                                    record101->count = changes->FUN_004c8f30(base14->form);
                            }
                            else
                                record101->count = 1;
                            package4->list.FUN_00905820(record101);
                        }
                    }
                    else
                    {
                        delete existing;
                    }
                }
                node = node->FUN_00726070();
            }
        }
        int numEntries9 = ref->FUN_00575590(0, 1);
        for (int index = 0; index < numEntries9; index++)
        {
            FUN_004459e0_Entry57* entry = ref->FUN_005754a0(index, 0);
            if (entry)
            {
                if (!entry->FUN_004bddd0(0))
                {
                    bool entryMatch = false;
                    if (unused9 && entry->FUN_004bcdb0(0) <= 0.0 && checkWeight36)
                        entryMatch = false;
                    else if (package4->category && MatchesObjectType(entry->FUN_0044ddc0(), package4->category))
                        entryMatch = true;
                    else if (package4->object && package4->object == entry->FUN_0044ddc0())
                        entryMatch = true;
                    else if (!package4->category && !package4->object)
                        entryMatch = true;
                    if (entryMatch && ref->FUN_00575ca0() == target20->FUN_00575ca0())
                    {
                        record101 = new FUN_0090e600_Record;
                        record101->form = entry->FUN_0044ddc0();
                        record101->ref = ref;
                        record101->inventory = 1;
                        void* otherContainer = ref->FUN_0055d310();
                        if (otherContainer)
                        {
                            Inventory57* otherChanges = FUN_004bf220(ref);
                            if (otherChanges)
                                record101->count = otherChanges->FUN_004c8f30(record101->form);
                        }
                        else
                            record101->count = 1;
                        package4->list.FUN_00905820(record101);
                        if (entry->FUN_00559450())
                            record101->extra = *entry->FUN_00559450()->FUN_006815c0();
                    }
                }
                delete entry;
            }
        }
    }
    return false;
}

// LowProcess::GetSaveSize: base size plus version-dependent fields, with an optional debug print
// of the size contribution for the form currently being saved.
struct TESSaveLoadGame
{
    bool FUN_00862110();
    unsigned char FUN_008df040();
    unsigned char* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
TESForm* __cdecl LookupFormByID(unsigned int auiFormID);
void __cdecl FUN_0040fbe0(const char* apFormat, ...);
extern const char DAT_01012c78[];
extern const char DAT_01012cb0[];
extern const char DAT_01088f50[];

struct ModifierListSize
{
    unsigned short FUN_00937ab0();
};

struct FUN_0090f8b0_shell : LowProcess
{
    unsigned short FUN_008d0900(unsigned int auiChangeFlags, unsigned int auiArg);
    unsigned short FUN_0090f8b0(unsigned int auiChangeFlags, unsigned int auiArg);
};

// Computes a save size by adding the base size from FUN_008d0900 plus version-dependent and flag-dependent extras, optionally logging the delta.
// @fnv 0x0090f8b0
unsigned short FUN_0090f8b0_shell::FUN_0090f8b0(unsigned int auiChangeFlags, unsigned int auiArg)
{
    unsigned short uiSaveSize = 0;
    uiSaveSize += FUN_008d0900(auiChangeFlags, auiArg);
    unsigned short uiBaseSize = uiSaveSize;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        uiSaveSize += 4;
        uiSaveSize += 2;
    }
    uiSaveSize += m_uiObjectFlags;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x4b)
        uiSaveSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x4f)
        uiSaveSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x56)
        uiSaveSize += 4;
    uiSaveSize += 8;
    if (auiChangeFlags & 0x200000)
        uiSaveSize += ((ModifierListSize*)&m_kActorValueModifiers)->FUN_00937ab0();
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x74)
        uiSaveSize += 4;
    if (*g_011de4e8.Bool())
    {
        unsigned char* pHeader = g_TESSaveLoadGame->FUN_004fd3e0();
        if (pHeader)
        {
            TESForm* pForm = LookupFormByID(*(unsigned int*)pHeader);
            FUN_0040fbe0(DAT_01012cb0, uiSaveSize - uiBaseSize, *(unsigned int*)pHeader, pForm->GetName(),
                         *(unsigned int*)(pHeader + 5), 0xeda, DAT_01088f50);
        }
        else
        {
            FUN_0040fbe0(DAT_01012c78, uiSaveSize - uiBaseSize, 0xeda, DAT_01088f50);
        }
    }
    return uiSaveSize;
}

namespace fnv_0090fd80 {
struct LoadRecord
{
    unsigned id;
    unsigned char tag;
    unsigned char flags5;
    unsigned char flags6;
    unsigned char flags7;
    unsigned char flags8;
    unsigned char version;
};
struct SaveReader
{
    bool Active();
    void Read(void*, unsigned);
    LoadRecord* Record();
    unsigned Position();
    unsigned char Version();
    void ReadID(unsigned*, unsigned);
    void Skip(unsigned);
};
extern SaveReader* g_TESSaveLoadGame;
extern void __cdecl FNV_Warning(const char*, ...);
extern float __cdecl FUN_004b1500(float, float);
struct FormView
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
    virtual const char* Name();
};
extern FormView* __cdecl LookupFormByID(unsigned);
struct ProcessTail
{
    void Load();
};
struct ProcessState
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
    virtual void Set(unsigned);
    unsigned field04;
    unsigned field08;
    unsigned field0c;
    unsigned field10;
    unsigned field14;
    unsigned field18;
    unsigned field1c;
    unsigned field20;
    unsigned field24;
    unsigned field28;
    unsigned field2c;
    unsigned field30;
    TESBoundObject* object34;
    unsigned field38;
    unsigned field3c;
    unsigned field40;
    unsigned field44;
    unsigned field48;
    unsigned field4c;
    unsigned field50;
    unsigned field54;
    unsigned field58;
    unsigned field5c;
    unsigned field60;
    unsigned field64;
    unsigned field68;
    unsigned field6c;
    unsigned field70;
    unsigned field74;
    unsigned field78;
    unsigned field7c;
    unsigned field80;
    unsigned field84;
    unsigned field88;
    unsigned field8c;
    unsigned field90;
    ProcessTail tail;
    unsigned field98;
    unsigned field9c;
    unsigned fielda0;
    unsigned fielda4;
    unsigned fielda8;
    unsigned fieldac;
    void BaseLoad(unsigned, unsigned, unsigned);
    void FUN_0090fd80(unsigned, unsigned, unsigned);
};
// Loads a process record from the save stream: reads the block header, version-gated fields, form IDs and tail, then warns on block size over/underrun.
// @fnv 0x0090fd80
void ProcessState::FUN_0090fd80(unsigned flags, unsigned arg2, unsigned arg3)
{
    BaseLoad(flags, arg2, arg3);
    unsigned idA;
    unsigned idB;
    unsigned short blockSize = 0;
    {
        unsigned start = 0;
        if (g_TESSaveLoadGame->Active())
        {
            unsigned header;
            g_TESSaveLoadGame->Read(&header, 4);
            if (header != 0x424c4f4b)
            {
                LoadRecord* record = g_TESSaveLoadGame->Record();
                if (record)
                {
                    FormView* form = LookupFormByID(record->id);
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp", 0xf2d, record->id,
                        form->Name(), record->version, *(unsigned*)&record->flags5);
                }
                else
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp", 0xf2d,
                        g_TESSaveLoadGame->Version());
            }
            start = g_TESSaveLoadGame->Position();
            g_TESSaveLoadGame->Read(&blockSize, 2);
        }
        if (g_TESSaveLoadGame->Version() < 0x36)
        {
            float e;
            int c, l, k;
            g_TESSaveLoadGame->Read(&e, 4);
            double j;
            j = FUN_004b1500(e, 100.0f);
            c = (int)j;
            j = FUN_004b1500(e, 10000.0f);
            l = (int)j / 100;
            k = (int)e / 10000;
            field24 = (l << 9) | c | (k << 13);
        }
        g_TESSaveLoadGame->Read(&field30, 1);
        if (g_TESSaveLoadGame->Version() >= 0x4b)
            g_TESSaveLoadGame->Read(&fielda4, 4);
        if (g_TESSaveLoadGame->Version() >= 0x4f)
        {
            unsigned objectID;
            g_TESSaveLoadGame->ReadID(&objectID, 4);
            object34 = dynamic_cast<TESBoundObject*>((TESForm*)LookupFormByID(objectID));
        }
        if (g_TESSaveLoadGame->Version() >= 0x56)
            g_TESSaveLoadGame->Read(&field58, 4);
        g_TESSaveLoadGame->ReadID(&idA, 4);
        Set(idA);
        g_TESSaveLoadGame->ReadID(&idB, 4);
        field44 = idB;
        if (flags & 0x200000)
            tail.Load();
        if (g_TESSaveLoadGame->Version() < 0x33 && (flags & 0x800000))
        {
            unsigned short count;
            g_TESSaveLoadGame->Read(&count, 2);
            if (count)
                g_TESSaveLoadGame->Skip(count << 3);
        }
        if (g_TESSaveLoadGame->Version() >= 0x74)
            g_TESSaveLoadGame->Read(&fielda8, 4);
        g_TESSaveLoadGame->Read(&fieldac, 4);
        if (g_TESSaveLoadGame->Active())
        {
            unsigned end = g_TESSaveLoadGame->Position();
            LoadRecord* record2 = g_TESSaveLoadGame->Record();
            if (record2)
            {
                FormView* form2 = LookupFormByID(record2->id);
                if (end > start + blockSize)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        end - (start + blockSize),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp", 0xf77, record2->id,
                        form2->Name(), record2->version, *(unsigned*)&record2->flags5);
                else if (end < start + blockSize)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        start + blockSize - end, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp",
                        0xf77, record2->id, form2->Name(), record2->version, *(unsigned*)&record2->flags5);
            }
            else
            {
                if (end > start + blockSize)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        end - (start + blockSize),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp", 0xf77,
                        g_TESSaveLoadGame->Version());
                else if (end < start + blockSize)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        start + blockSize - end, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp",
                        0xf77, g_TESSaveLoadGame->Version());
            }
        }
    }
}
}  // namespace fnv_0090fd80

struct BGSChangeFlags_s
{
    unsigned int uiFlags;
    BGSChangeFlags_s(unsigned int auiFlags);
    bool Test(unsigned int auiFlag);
};
struct BGSSaveFormBuffer
{
    void SaveData(void* apData, unsigned int auiSize, int aiArg);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int aiCount, unsigned int auiPosition);
    BGSChangeFlags_s FUN_00428110();
};
struct FUN_00865df0_buf
{
    void FUN_00865df0(void* apForm, int aiArg);
};
struct FUN_008d0f30_shell
{
    void FUN_008d0f30(BGSSaveFormBuffer* apBuffer);
};
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer* apBuffer);
};
struct FUN_00910450_Extra
{
    void FUN_00937b50(BGSSaveFormBuffer* apBuffer);
};
struct FUN_00910450_shell : FUN_008d0f30_shell
{
    char pad00[0x30];
    char cType;
    void* pOwner;
    FUN_009a5eb0_shell kTimer;
    char pad39[7];
    void* pTarget;
    void* pForm44;
    void* pForm48;
    void* pForm4C;
    short sValue;
    void* pForm54;
    int iValue58;
    char pad5C[8];
    void* pOverride;
    char pad68[4];
    BSSimpleList<Actor*> kActors;
    char pad74[0x20];
    FUN_00910450_Extra kExtra;
    char pad95[0xf];
    int iValueA4;
    int iValueA8;
    int iValueAC;
    char cValueB0;
    void FUN_00910450(BGSSaveFormBuffer* apBuffer);
};
// @fnv 0x00910450
void FUN_00910450_shell::FUN_00910450(BGSSaveFormBuffer* apBuffer)
{
    FUN_008d0f30(apBuffer);
    apBuffer->SaveData(&cType, 1, 0);
    apBuffer->SaveData(&iValueA4, 4, 0);
    ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(pOwner, 0);
    apBuffer->SaveData(&iValue58, 4, 0);
    apBuffer->SaveData(&iValueA8, 4, 0);
    apBuffer->SaveData(&iValueAC, 4, 0);
    apBuffer->SaveData(&cValueB0, 1, 0);
    apBuffer->SaveData(&sValue, 2, 0);
    kTimer.FUN_009a5eb0(apBuffer);
    ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(!pOverride ? pTarget : 0, 0);
    ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(pForm44, 0);
    ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(pForm48, 0);
    ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(pForm4C, 0);
    ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(pForm54, 0);
    int iNumActors = 0;
    unsigned int uiPosition = apBuffer->FUN_00865f20();
    BSSimpleList<Actor*>* pNode = &kActors;
    while (pNode)
    {
        Actor* pActor = pNode->GetItem();
        if (pActor)
        {
            ((FUN_00865df0_buf*)apBuffer)->FUN_00865df0(pActor, 0);
            iNumActors++;
        }
        pNode = pNode->GetNext();
    }
    apBuffer->FUN_00865ff0(iNumActors, uiPosition);
    if (apBuffer->FUN_00428110().Test(0x200000))
        kExtra.FUN_00937b50(apBuffer);
}

extern const float DAT_01012054;
extern double DAT_010231b0;

struct PkgTarget910
{
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
    virtual void v064();
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
    virtual bool IsMoving(bool bValue);
    bool FUN_00440da0();
    bool FUN_00440d80();
};

struct PkgActor910
{
    float FUN_005723b0(PkgTarget910* pkTarget, int iA, int iB);
};

struct PkgProc910
{
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
    virtual void v064();
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
    virtual bool MoveTo(PkgActor910* pkActor, int iA, float fRadius, int iB);
    virtual void w080();
    virtual void w081();
    virtual bool IsDone(PkgActor910* pkActor, int iA);
    void FUN_00674e70(PkgTarget910* pkTarget, bool bValue);
};

struct FUN_00910c80_shell
{
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
    virtual void v064();
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
    virtual PkgProc910* GetProcedure();
    virtual void w160();
    virtual void w161();
    virtual void SetResult(PkgActor910* pkActor, int iResult);
    char pad04[0x3c];
    PkgTarget910* m_pkTarget;
    char pad44[0x20];
    int m_iFadeIndex;

    void UpdateMoveToTarget(PkgActor910* pkActor);
};

// Checks the target's state and either sets a result code or moves the actor toward the target, setting a result when done.
// @fnv 0x00910c80
void FUN_00910c80_shell::UpdateMoveToTarget(PkgActor910* pkActor)
{
    PkgProc910* pkProc = 0;
    pkProc = GetProcedure();
    if (!m_pkTarget || m_pkTarget->FUN_00440da0())
    {
        SetResult(pkActor, 2);
    }
    else if (m_pkTarget->FUN_00440d80())
    {
        if (m_pkTarget->FUN_00440d80())
            pkProc->FUN_00674e70(m_pkTarget, true);
        SetResult(pkActor, 2);
        return;
    }
    else if (m_pkTarget->IsMoving(true) && !m_iFadeIndex)
    {
        pkProc->FUN_00674e70(m_pkTarget, true);
        return;
    }
    else if (!pkProc->MoveTo(pkActor, 0, DAT_01012054, 0))
    {
        SetResult(pkActor, -1);
    }
    else
    {
        float fDistance = pkActor->FUN_005723b0(m_pkTarget, 0, 0);
        if (fDistance != DAT_010231b0)
        {
            if (pkProc->IsDone(pkActor, 0))
                SetResult(pkActor, 1);
        }
    }
}

struct P
{
    int FUN_009611e0();
    int FUN_0041ca90();
};
struct E
{
    P* FUN_0041cb10();
    int FUN_0041cb40();
    void FUN_0041cae0(int);
    void SetExtraDataFlag(bool);
    void FUN_0041c930(P*, int, int, bool);
    void FUN_004211d0(int);
};
struct Empty
{
};
template <int N, class B> struct Tag
{
};
template <int N, class B> struct Pads : Pads<N - 1, B>
{
    virtual void pad(Tag<N, B>*);
};
template <class B> struct Pads<0, B> : B
{
};
struct R : Pads<18, Empty>
{
    virtual void v48(unsigned);
    E* FUN_005d43c0();
    P* FUN_00881450();
};
int FUN_0096a820(int);
bool FUN_005ac750(P*, E*, unsigned);
int FUN_008c6ca0(int);
struct C70 : Pads<70, Empty>
{
    virtual void v118(bool);
    virtual bool v11c(bool);
};
struct C202 : Pads<130, C70>
{
    virtual void v328(bool);
};
struct C314 : Pads<111, C202>
{
    virtual bool v4e8(bool);
    virtual void v4ec(bool);
};
struct C358 : Pads<42, C314>
{
    virtual void v598(R*, P*);
    virtual void unused359();
    virtual void v5a0(R*, P*);
    virtual bool v5a4();
    virtual void v5a8(bool);
};
struct C : Pads<153, C358>
{
    virtual int v810(R*, P*);
    virtual int v814(R*, P*, int);
    bool FUN_00907960(P*, int);
    bool FUN_009079f0(R*, P*);
    bool FUN_009078d0(P*, bool);
    bool TrySelectTarget(R*, P**);
};
// @fnv 0x00907ab0
bool C::TrySelectTarget(R* ref, P** ppOut)
{
    P* a = ref->FUN_005d43c0()->FUN_0041cb10();
    if (a)
    {
        int b = ref->FUN_005d43c0()->FUN_0041cb40();
        if (!FUN_00907960(a, b))
        {
            if (!FUN_009079f0(ref, a))
            {
                int c5 = FUN_0096a820(a->FUN_009611e0());
                ref->FUN_005d43c0()->FUN_0041cae0(c5 - 1);
                FUN_005ac750(a, ref->FUN_005d43c0(), 0x400);
                v5a0(ref, a);
                v5a8(true);
                v4ec(true);
                v118(true);
                ref->FUN_005d43c0()->SetExtraDataFlag(true);
                P* d = ref->FUN_00881450();
                if (d && d != a && FUN_009078d0(d, true))
                {
                    int g4 = v810(ref, d);
                    if (!g4)
                        g4 = v814(ref, d, 0);
                    v5a8(false);
                    v4ec(false);
                    v118(false);
                    E* f7 = ref->FUN_005d43c0();
                    f7->FUN_0041c930(d, 0, g4, v11c(v4e8(v5a4())));
                    int e = FUN_008c6ca0(d->FUN_0041ca90());
                    if (e)
                        f7->FUN_004211d0(e);
                    v598(ref, d);
                    FUN_009079f0(ref, d);
                    ref->v48(0x80000000);
                    *ppOut = d;
                    return false;
                }
                else
                {
                    *ppOut = 0;
                    return false;
                }
            }
            else
            {
                *ppOut = a;
                return false;
            }
        }
        else
        {
            v328(true);
            *ppOut = 0;
            return true;
        }
    }
    *ppOut = 0;
    return false;
}

extern SettingT_GameSettingCollection_ DAT_011cd6cc;

class ActorAccess : public Actor
{
  public:
    bool FUN_00493bb0();
    void FUN_00881620(Actor*);
};

class LowProcessAccess : public LowProcess
{
  public:
    void FUN_0090d000(Actor* pActor);
};

// @fnv 0x0090d000
void LowProcessAccess::FUN_0090d000(Actor* pActor)
{
    if (!pTarget)
    {
        FindPackageTarget(pActor);
    }
    if (pTarget)
    {
        if (!GetCurrentPackage()->vfn_144(pActor, false))
        {
            vfn_298(pActor, false, 0x101, false);
            return;
        }
    }
    if (pTarget == g_thePlayer && g_thePlayer->IsSleepingOrResting() && !g_thePlayer->bResting)
    {
        g_thePlayer->FUN_005c1a00(false, 1);
        SetProcessTarget(pActor, -1);
        return;
    }
    else
    {
        int iCount = (int)(DAT_011cd6cc.Float()->f * 4.0);
        Actor* pTargetActor = 0;
        bool bPickResultFound = false;
        while (iCount)
        {
            if (pActor->vfn_22c(false))
            {
                break;
            }
            pActor->Unk_10E();
            if (!static_cast<ActorAccess*>(pActor)->FUN_00493bb0())
            {
                break;
            }
            pTargetActor = dynamic_cast<Actor*>(pTarget);
            if (pTargetActor)
            {
                static_cast<ActorAccess*>(pTargetActor)->FUN_00881620(pActor);
                if (!pTargetActor->vfn_22c(false))
                {
                    if (!static_cast<ActorAccess*>(pTargetActor)->FUN_00493bb0())
                    {
                        pTargetActor->GetProcess()->vfn_33c(pTargetActor, pActor, 0, 0, 0, 0, false, 0, false, 0, 0,
                                                            true, 0);
                    }
                    pTargetActor->Unk_10E();
                    bPickResultFound = true;
                }
            }
            iCount--;
        }
        if (bPickResultFound)
        {
            pTargetActor->GetProcess()->vfn_28();
            bPickResultFound = false;
        }
    }
}

// 0x0090e660  unit_c5661b6602f6.cpp  /MT /Od /Oy- /GS /EHsc /Gy /GF
// cdecl, 2 stack args: form/refr sanity gate, dynamic_cast of the Actor's
// process to LowProcess, two "does this form match the process' target"
// blocks, then a walk of the reference's container list deleting every
// entry that matches.

struct Item9
{
    ~Item9();
    bool FUN_004bddd0(bool);
    unsigned int FUN_0044ddc0();
};

struct RefExt9
{
    int FUN_00575590(int, int);
    Item9* FUN_005754a0(int, int);
};

struct Shell8859e0
{
    bool FUN_008859e0(TESObject*);
};

bool MatchesObjectType(TESForm*, int);

// @fnv 0x0090e660
bool FUN_0090e660(TESObjectREFR* refr, long apActor)
{
    Actor* pActor = (Actor*)apActor;
    if (!refr || refr->IsDeleted() || refr->IsTemporary() || refr->GetDisabled() ||
        (((TESObjectREFR*)pActor)->GetIsChildSize(false) && !((Shell8859e0*)pActor)->FUN_008859e0((TESObject*)refr)))
        return false;
    if (!pActor)
        return true;
    LowProcess* pLowProcess = dynamic_cast<LowProcess*>(pActor->GetProcess());
    if (!pLowProcess)
        return true;
    bool isActor = refr->IsActor();
    TESForm* pBaseForm = refr->GetObjectReference();
    int formType3 = pBaseForm->GetFormType();
    if (pLowProcess->m_eReferenceTypeInfo && MatchesObjectType(refr->GetObjectReference(), pLowProcess->m_eReferenceTypeInfo))
    {
        if (!refr->vfn_22c(false))
        {
            refr->FUN_00564db0(true);
            pLowProcess->m_kReferenceList70.AddTail(refr);
        }
    }
    else if (pLowProcess->m_pBoundObject78 &&
             (TESObjectREFR*)pLowProcess->m_pBoundObject78 == (TESObjectREFR*)refr->GetObjectReference())
    {
        if (!refr->vfn_22c(false))
        {
            refr->FUN_00564db0(true);
            pLowProcess->m_kReferenceList70.AddTail(refr);
        }
    }
    else if (!pLowProcess->m_eReferenceTypeInfo && !pLowProcess->m_pBoundObject78)
    {
        refr->FUN_00564db0(true);
        pLowProcess->m_kReferenceList70.AddTail(refr);
    }
    if ((isActor && refr != g_thePlayer) || formType3 == 0x1b)
    {
        int iItemCount = ((RefExt9*)refr)->FUN_00575590(0, 1);
        for (int iIndex = 0; iIndex < iItemCount; iIndex++)
        {
            Item9* item = ((RefExt9*)refr)->FUN_005754a0(iIndex, 0);
            if (item)
            {
                if (!item->FUN_004bddd0(false))
                {
                    bool bMatch = false;
                    if (pLowProcess->m_eReferenceTypeInfo &&
                        MatchesObjectType((TESForm*)item->FUN_0044ddc0(), pLowProcess->m_eReferenceTypeInfo))
                        bMatch = true;
                    else if ((TESObjectREFR*)pLowProcess->m_pBoundObject78 == (TESObjectREFR*)item->FUN_0044ddc0())
                        bMatch = true;
                    else if (!pLowProcess->m_eReferenceTypeInfo && !pLowProcess->m_pBoundObject74 &&
                             !pLowProcess->m_pBoundObject78)
                        bMatch = true;
                    if (bMatch)
                    {
                        refr->FUN_00564db0(true);
                        pLowProcess->m_kReferenceList70.AddTail(refr);
                    }
                }
                delete item;
            }
        }
    }
    return false;
}

class Cell;
class Ref;
class Pkg;
class Info;

class Ref
{
  public:
    Cell* FUN_008d6f30();
};

class Pkg
{
  public:
    void* FUN_0055b980();
    Cell* FUN_00675c20(Ref*);
    bool IsFlag4Clear();
    int FUN_009611e0();
};

class Info
{
  public:
    Ref* FUN_00639b40();
};

class Proc
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
    virtual Ref* vfn_128();
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
    virtual Pkg* vfn_22c();
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
    virtual int vfn_280();
    char pad_[0x3c];
    Ref* pTarget;
    Info* FUN_008d0430();
    Cell* GetProcedureCell(Ref*);
};

// Selects a Cell for ref based on the procedure's package type and procedure index, falling back to ref's own cell.
// @fnv 0x0090f0e0
Cell* Proc::GetProcedureCell(Ref* ref)
{
    Cell* pCell = 0;
    Info* pInfo;
    Ref* spk;

    if (ref)
        pCell = ref->FUN_008d6f30();
    if (!this->vfn_22c())
        return pCell;
    switch (DAT_011a3ff0[this->vfn_22c()->FUN_009611e0()][this->vfn_280()])
    {
    case 0:
    case 0x32:
        if (this->vfn_22c()->FUN_0055b980())
            pCell = this->vfn_22c()->FUN_00675c20(ref);
        else
            pCell = ref->FUN_008d6f30();
        break;
    case 0x2f:
        if (this->vfn_22c()->IsFlag4Clear() && this->vfn_22c()->FUN_0055b980())
            pCell = this->vfn_22c()->FUN_00675c20(ref);
        else if (this->vfn_128())
            pCell = this->vfn_128()->FUN_008d6f30();
        else
            pCell = ref->FUN_008d6f30();
        break;
    case 0x1b:
        pCell = ref->FUN_008d6f30();
        break;
    case 1:
    case 2:
    case 3:
    case 8:
    case 0xe:
    case 0xf:
        if (this->pTarget)
            pCell = this->pTarget->FUN_008d6f30();
        else
            pCell = ref->FUN_008d6f30();
        break;
    case 4:
    case 5:
        if (this->vfn_22c()->FUN_0055b980())
            pCell = this->vfn_22c()->FUN_00675c20(ref);
        else
            pCell = ref->FUN_008d6f30();
        break;
    case 6:
    case 0xd:
    case 0x1e:
        if (this->pTarget)
            pCell = this->pTarget->FUN_008d6f30();
        else
            pCell = ref->FUN_008d6f30();
        break;
    case 7:
        if (this->vfn_22c()->FUN_0055b980())
            pCell = this->vfn_22c()->FUN_00675c20(ref);
        else
            pCell = ref->FUN_008d6f30();
        break;
    case 0x2a:
        pInfo = this->FUN_008d0430();
        if (pInfo)
        {
            spk = pInfo->FUN_00639b40();
            if (spk)
                pCell = spk->FUN_008d6f30();
        }
        break;
    case 0x36:
        pCell = ref->FUN_008d6f30();
        break;
    }
    return pCell;
}

namespace fnv_0090f3f0 {
struct Ref
{
    void* FUN_00575d70();
};
struct Info
{
    Ref* FUN_00639b40();
};
struct Package
{
    int FUN_009611e0();
    void* FUN_0055b980();
    void* FUN_00675a50(Ref*);
    bool IsFlag4Clear();
};
extern "C" char DAT_011A3FF0;
struct ActorShell
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
    virtual Ref* v74();
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
    virtual Package* v139();
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
    virtual int v160();
    char pad[60];
    Ref* field40;
    Info* FUN_008d0430();
    void* FUN_0090f3f0(Ref* arg);
};
// @fnv 0x0090f3f0
void* ActorShell::FUN_0090f3f0(Ref* apRef)
{
    void* result = 0;
    if (apRef)
        result = apRef->FUN_00575d70();
    Package* package = v139();
    if (!package)
        return result;
    switch (((unsigned int**)&DAT_011A3FF0)[package->FUN_009611e0()][v160()])
    {
    case 0:
    case 50:
        if (package->FUN_0055b980())
            result = package->FUN_00675a50(apRef);
        else
            result = apRef->FUN_00575d70();
        break;
    case 47:
        if (package->IsFlag4Clear() && package->FUN_0055b980())
            result = package->FUN_00675a50(apRef);
        else if (v74())
            result = v74()->FUN_00575d70();
        else
            result = apRef->FUN_00575d70();
        break;
    case 27:
        result = apRef->FUN_00575d70();
        break;
    case 1:
    case 2:
    case 3:
    case 8:
    case 14:
    case 15:
        if (field40)
            result = field40->FUN_00575d70();
        else
            result = apRef->FUN_00575d70();
        break;
    case 4:
    case 5:
        if (package->FUN_0055b980())
            result = package->FUN_00675a50(apRef);
        else
            result = apRef->FUN_00575d70();
        break;
    case 6:
    case 13:
    case 30:
        if (field40)
            result = field40->FUN_00575d70();
        else
            result = apRef->FUN_00575d70();
        break;
    case 7:
        if (package->FUN_0055b980())
            result = package->FUN_00675a50(apRef);
        else
            result = apRef->FUN_00575d70();
        break;
    case 42: {
        Info* info = FUN_008d0430();
        if (info)
        {
            Ref* ref = info->FUN_00639b40();
            if (ref)
                result = ref->FUN_00575d70();
        }
    }
    break;
    case 54:
        result = apRef->FUN_00575d70();
    }
    return result;
}
}  // namespace fnv_0090f3f0

namespace fnv_0090fa70 {
struct TESSaveLoadGame
{
    bool FUN_00862110();
    void FUN_008579b0(void* ptr, unsigned int size);
    void FUN_00857a10(void* ptr, unsigned int size);
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    void* FUN_004fd3e0();
};
extern TESSaveLoadGame* DAT_011de45c;

struct GlobalFlagObj
{
    unsigned char* FUN_00408d60();
};
extern GlobalFlagObj DAT_011de4e8;

struct FormBase
{
    unsigned int FUN_0084e3a0();
};

struct ProcSub94
{
    void CountModifiers();
};

struct Sound
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
Sound* LookupFormByID(unsigned int id);
void FUN_0040fbe0(const char* fmt, ...);
void FUN_005b5e40(const char* fmt, const char* file, int line);

struct LowProcessFA70
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
    unsigned int m_uiObjectFlags;
    FormBase* m_pCurrentWeapon;
    int unk38;
    int unk3C;
    FormBase* pTarget;
    FormBase* m_pReference40;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int m_iValue58;
    int unk5C;
    int unk60;
    void* m_pDetectionData60;
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

    void FUN_008d0a10(unsigned int changedFlags, unsigned int arg2);
    void SaveToStream(unsigned int changedFlags, unsigned int arg2);
};

// Serializes this low-process record to the save game stream, writing fields gated by save version and patching the block size header.
// @fnv 0x0090fa70
void LowProcessFA70::SaveToStream(unsigned int changedFlags, unsigned int arg2)
{
    this->FUN_008d0a10(changedFlags, arg2);
    unsigned short zeroWord = 0;
    unsigned int aBlockStart = 0;
    unsigned int startPos;
    startPos = DAT_011de45c->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
    {
        startPos = DAT_011de45c->FUN_00825c00();
    }
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int blockTag = 0x424c4f4b;
        DAT_011de45c->FUN_008579b0(&blockTag, 4);
        aBlockStart = DAT_011de45c->FUN_00825c00();
        DAT_011de45c->FUN_008579b0(&zeroWord, 2);
    }
    DAT_011de45c->FUN_008579b0(&this->m_uiObjectFlags, 1);
    if (DAT_011de45c->FUN_008df040() >= 0x4b)
    {
        DAT_011de45c->FUN_008579b0(&this->unkA4, 4);
    }
    if (DAT_011de45c->FUN_008df040() >= 0x4f)
    {
        unsigned int pItem = 0;
        if (this->m_pCurrentWeapon != 0)
        {
            pItem = this->m_pCurrentWeapon->FUN_0084e3a0();
        }
        DAT_011de45c->FUN_00857a10(&pItem, 4);
    }
    if (DAT_011de45c->FUN_008df040() >= 0x56)
    {
        DAT_011de45c->FUN_008579b0(&this->m_iValue58, 4);
    }
    unsigned int pTgt5 = 0;
    if (this->pTarget != 0 && this->m_pDetectionData60 == 0)
    {
        pTgt5 = this->pTarget->FUN_0084e3a0();
    }
    DAT_011de45c->FUN_00857a10(&pTgt5, 4);
    unsigned int pGen7 = 0;
    if (this->m_pReference40 != 0)
    {
        pGen7 = this->m_pReference40->FUN_0084e3a0();
    }
    DAT_011de45c->FUN_00857a10(&pGen7, 4);
    if (changedFlags & 0x200000)
    {
        ((ProcSub94*)&this->unk94)->CountModifiers();
    }
    if (DAT_011de45c->FUN_008df040() >= 0x74)
    {
        DAT_011de45c->FUN_008579b0(&this->unkA8, 4);
    }
    DAT_011de45c->FUN_008579b0(&this->unkAC, 4);
    if (*DAT_011de4e8.FUN_00408d60())
    {
        unsigned int endPos = DAT_011de45c->FUN_00825c00();
        char* pRef = (char*)DAT_011de45c->FUN_004fd3e0();
        if (pRef != 0)
        {
            Sound* s = LookupFormByID(*(unsigned int*)pRef);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         endPos - startPos, *(unsigned int*)pRef, s->GetName(), *(unsigned int*)(pRef + 5), 0xf20,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", endPos - startPos, 0xf20,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp");
        }
    }
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int endPos2 = DAT_011de45c->FUN_00825c00();
        unsigned int sz = aBlockStart;
        if (endPos2 > sz + 0xffff)
        {
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\LowProcess.cpp", 0xf20);
        }
        *(unsigned short*)aBlockStart = (unsigned short)(endPos2 - sz);
    }
}
}  // namespace fnv_0090fa70

// Inventory search and fallback spatial search for an actor package.
class TESObjectARMO : public TESBoundObject
{
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    bool IsRanged();
    bool IsMelee();
};
class TESAmmo : public TESBoundObject
{
};
class TESObjectCLOT : public TESBoundObject
{
};
struct SearchEntry
{
    ~SearchEntry();
    TESBoundObject* GetObject();
    int GetCount();
};
struct SearchInventory
{
    int Count(int);
    SearchEntry* Get(int);
};
struct SearchReference
{
    void* GetContainer();
    const char* Name();
    void* Cell();
    virtual void refSlot0();
    virtual void refSlot1();
    virtual void refSlot2();
    virtual void refSlot3();
    virtual void refSlot4();
    virtual void refSlot5();
    virtual void refSlot6();
    virtual void refSlot7();
    virtual void refSlot8();
    virtual void refSlot9();
    virtual void refSlot10();
    virtual void refSlot11();
    virtual void refSlot12();
    virtual void refSlot13();
    virtual void refSlot14();
    virtual void refSlot15();
    virtual void refSlot16();
    virtual void refSlot17();
    virtual void refSlot18();
    virtual void refSlot19();
    virtual void refSlot20();
    virtual void refSlot21();
    virtual void refSlot22();
    virtual void refSlot23();
    virtual void refSlot24();
    virtual void refSlot25();
    virtual void refSlot26();
    virtual void refSlot27();
    virtual void refSlot28();
    virtual void refSlot29();
    virtual void refSlot30();
    virtual void refSlot31();
    virtual void refSlot32();
    virtual void refSlot33();
    virtual void refSlot34();
    virtual void refSlot35();
    virtual void refSlot36();
    virtual void refSlot37();
    virtual void refSlot38();
    virtual void refSlot39();
    virtual void refSlot40();
    virtual void refSlot41();
    virtual void refSlot42();
    virtual void refSlot43();
    virtual void refSlot44();
    virtual void refSlot45();
    virtual void refSlot46();
    virtual void refSlot47();
    virtual void refSlot48();
    virtual void refSlot49();
    virtual void refSlot50();
    virtual void refSlot51();
    virtual void refSlot52();
    virtual void refSlot53();
    virtual void refSlot54();
    virtual void refSlot55();
    virtual void refSlot56();
    virtual void refSlot57();
    virtual void refSlot58();
    virtual void refSlot59();
    virtual void refSlot60();
    virtual void refSlot61();
    virtual void refSlot62();
    virtual void refSlot63();
    virtual void refSlot64();
    virtual void refSlot65();
    virtual void refSlot66();
    virtual void refSlot67();
    virtual void refSlot68();
    virtual void refSlot69();
    virtual void refSlot70();
    virtual void refSlot71();
    virtual void refSlot72();
    virtual void refSlot73();
    virtual void refSlot74();
    virtual void refSlot75();
    virtual void refSlot76();
    virtual void refSlot77();
    virtual void refSlot78();
    virtual void refSlot79();
    virtual void refSlot80();
    virtual void refSlot81();
    virtual void refSlot82();
    virtual void refSlot83();
    virtual void refSlot84();
    virtual void refSlot85();
    virtual void refSlot86();
    virtual void refSlot87();
    virtual void refSlot88();
    virtual void refSlot89();
    virtual void refSlot90();
    virtual void refSlot91();
    virtual void refSlot92();
    virtual void refSlot93();
    virtual void refSlot94();
    virtual void refSlot95();
    virtual void refSlot96();
    virtual void refSlot97();
    virtual void refSlot98();
    virtual void refSlot99();
    virtual void refSlot100();
    virtual void refSlot101();
    virtual void refSlot102();
    virtual void refSlot103();
    virtual void refSlot104();
    virtual void refSlot105();
    virtual void refSlot106();
    virtual void refSlot107();
    virtual void refSlot108();
    virtual void refSlot109();
    virtual void refSlot110();
    virtual void refSlot111();
    virtual void refSlot112();
    virtual void refSlot113();
    virtual void refSlot114();
    virtual void refSlot115();
    virtual void refSlot116();
    virtual void refSlot117();
    virtual void refSlot118();
    virtual void refSlot119();
    virtual void refSlot120();
    virtual void refSlot121();
    virtual void refSlot122();
    virtual void refSlot123();
    virtual void refSlot124();
    virtual const NiPoint3* Position();
};
SearchInventory* __cdecl GetInventory(SearchReference*);
struct SearchResult
{
    SearchResult();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    SearchReference* owner;
    TESBoundObject* object;
    int unknown8;
    int quantity;
    int unknown10;
    int unknown14;
    int enabled;
};
struct SearchList
{
    void Append(SearchResult**);
};
struct SearchPackage
{
    int HasSearchLocation();
    unsigned int Radius(SearchReference*);
    void* Cell(SearchReference*);
    NiPoint3 Coord(SearchReference*);
    bool AcquireRadius(SearchReference*, float&);
};
struct SearchDefault
{
    float* Value();
};
struct SearchCell
{
    bool IsInterior();
};
extern float DAT_01016970;
struct SearchWorld
{
    void Visit(void*, const NiPoint3*, float, const NiPoint3*, float, void (*)(), SearchReference*);
};
extern SearchWorld* DAT_011c3f2c;
void CheckPackageMatch();
void __cdecl SearchLog(const char*, ...);
struct SearchProcess
{
    virtual void procSlot0();
    virtual void procSlot1();
    virtual void procSlot2();
    virtual void procSlot3();
    virtual void procSlot4();
    virtual void procSlot5();
    virtual void procSlot6();
    virtual void procSlot7();
    virtual void procSlot8();
    virtual void procSlot9();
    virtual void procSlot10();
    virtual void procSlot11();
    virtual void procSlot12();
    virtual void procSlot13();
    virtual void procSlot14();
    virtual void procSlot15();
    virtual void procSlot16();
    virtual void procSlot17();
    virtual void procSlot18();
    virtual void procSlot19();
    virtual void procSlot20();
    virtual void procSlot21();
    virtual void procSlot22();
    virtual void procSlot23();
    virtual void procSlot24();
    virtual void procSlot25();
    virtual void procSlot26();
    virtual void procSlot27();
    virtual void procSlot28();
    virtual void procSlot29();
    virtual void procSlot30();
    virtual void procSlot31();
    virtual void procSlot32();
    virtual void procSlot33();
    virtual void procSlot34();
    virtual void procSlot35();
    virtual void procSlot36();
    virtual void procSlot37();
    virtual void procSlot38();
    virtual void procSlot39();
    virtual void procSlot40();
    virtual void procSlot41();
    virtual void procSlot42();
    virtual void procSlot43();
    virtual void procSlot44();
    virtual void procSlot45();
    virtual void procSlot46();
    virtual void procSlot47();
    virtual void procSlot48();
    virtual void procSlot49();
    virtual void procSlot50();
    virtual void procSlot51();
    virtual void procSlot52();
    virtual void procSlot53();
    virtual void procSlot54();
    virtual void procSlot55();
    virtual void procSlot56();
    virtual void procSlot57();
    virtual void procSlot58();
    virtual void procSlot59();
    virtual void procSlot60();
    virtual void procSlot61();
    virtual void procSlot62();
    virtual void procSlot63();
    virtual void procSlot64();
    virtual void procSlot65();
    virtual void procSlot66();
    virtual void procSlot67();
    virtual void procSlot68();
    virtual void procSlot69();
    virtual void procSlot70();
    virtual void procSlot71();
    virtual void procSlot72();
    virtual void procSlot73();
    virtual void procSlot74();
    virtual void procSlot75();
    virtual void procSlot76();
    virtual void procSlot77();
    virtual void procSlot78();
    virtual void procSlot79();
    virtual void procSlot80();
    virtual void procSlot81();
    virtual void procSlot82();
    virtual void procSlot83();
    virtual void procSlot84();
    virtual void procSlot85();
    virtual void procSlot86();
    virtual void procSlot87();
    virtual void procSlot88();
    virtual void procSlot89();
    virtual void procSlot90();
    virtual void procSlot91();
    virtual void procSlot92();
    virtual void procSlot93();
    virtual void procSlot94();
    virtual void procSlot95();
    virtual void procSlot96();
    virtual void procSlot97();
    virtual void procSlot98();
    virtual void procSlot99();
    virtual void procSlot100();
    virtual void procSlot101();
    virtual void procSlot102();
    virtual void procSlot103();
    virtual void procSlot104();
    virtual void procSlot105();
    virtual void procSlot106();
    virtual void procSlot107();
    virtual void procSlot108();
    virtual void procSlot109();
    virtual void procSlot110();
    virtual void procSlot111();
    virtual void procSlot112();
    virtual void procSlot113();
    virtual void procSlot114();
    virtual void procSlot115();
    virtual void procSlot116();
    virtual void procSlot117();
    virtual void procSlot118();
    virtual void procSlot119();
    virtual void procSlot120();
    virtual void procSlot121();
    virtual void procSlot122();
    virtual void procSlot123();
    virtual void procSlot124();
    virtual void procSlot125();
    virtual void procSlot126();
    virtual void procSlot127();
    virtual void procSlot128();
    virtual void procSlot129();
    virtual void procSlot130();
    virtual void procSlot131();
    virtual void procSlot132();
    virtual void procSlot133();
    virtual void procSlot134();
    virtual void procSlot135();
    virtual void procSlot136();
    virtual void procSlot137();
    virtual void procSlot138();
    virtual SearchPackage* m_kProcessData();
    virtual void procSlot140();
    virtual void procSlot141();
    virtual void procSlot142();
    virtual void procSlot143();
    virtual void procSlot144();
    virtual void procSlot145();
    virtual void procSlot146();
    virtual void procSlot147();
    virtual void procSlot148();
    virtual void procSlot149();
    virtual void procSlot150();
    virtual void procSlot151();
    virtual void procSlot152();
    virtual void procSlot153();
    virtual void procSlot154();
    virtual void procSlot155();
    virtual void procSlot156();
    virtual void procSlot157();
    virtual void procSlot158();
    virtual SearchPackage* ActivePackage();
    virtual void procSlot160();
    virtual void procSlot161();
    virtual void procSlot162();
    virtual void procSlot163();
    virtual void procSlot164();
    virtual void procSlot165();
    virtual void procSlot166();
    virtual void procSlot167();
    virtual void procSlot168();
    virtual void procSlot169();
    virtual void procSlot170();
    virtual void procSlot171();
    virtual void procSlot172();
    virtual void procSlot173();
    virtual void procSlot174();
    virtual void procSlot175();
    virtual void procSlot176();
    virtual void procSlot177();
    virtual void procSlot178();
    virtual void procSlot179();
    virtual void procSlot180();
    virtual void procSlot181();
    virtual void procSlot182();
    virtual void procSlot183();
    virtual void procSlot184();
    virtual void procSlot185();
    virtual void procSlot186();
    virtual void procSlot187();
    virtual void procSlot188();
    virtual void procSlot189();
    virtual void procSlot190();
    virtual void procSlot191();
    virtual void procSlot192();
    virtual void procSlot193();
    virtual void procSlot194();
    virtual void procSlot195();
    virtual void procSlot196();
    virtual void procSlot197();
    virtual void procSlot198();
    virtual void procSlot199();
    virtual void procSlot200();
    virtual void procSlot201();
    virtual void procSlot202();
    virtual void procSlot203();
    virtual void procSlot204();
    virtual void procSlot205();
    virtual void procSlot206();
    virtual void procSlot207();
    virtual void procSlot208();
    virtual void procSlot209();
    virtual void procSlot210();
    virtual void procSlot211();
    virtual void procSlot212();
    virtual void procSlot213();
    virtual void procSlot214();
    virtual void procSlot215();
    virtual void procSlot216();
    virtual void procSlot217();
    virtual void procSlot218();
    virtual void procSlot219();
    virtual void procSlot220();
    virtual void procSlot221();
    virtual void procSlot222();
    virtual void procSlot223();
    virtual void procSlot224();
    virtual void procSlot225();
    virtual void procSlot226();
    virtual void procSlot227();
    virtual void procSlot228();
    virtual void procSlot229();
    virtual void procSlot230();
    virtual void procSlot231();
    virtual void procSlot232();
    virtual void procSlot233();
    virtual void procSlot234();
    virtual void procSlot235();
    virtual void procSlot236();
    virtual void procSlot237();
    virtual void procSlot238();
    virtual void procSlot239();
    virtual void procSlot240();
    virtual void procSlot241();
    virtual void procSlot242();
    virtual void procSlot243();
    virtual void procSlot244();
    virtual void procSlot245();
    virtual void procSlot246();
    virtual void procSlot247();
    virtual void procSlot248();
    virtual void procSlot249();
    virtual void procSlot250();
    virtual void procSlot251();
    virtual void procSlot252();
    virtual void procSlot253();
    virtual void procSlot254();
    virtual void procSlot255();
    virtual void procSlot256();
    virtual void procSlot257();
    virtual void procSlot258();
    virtual void procSlot259();
    virtual void procSlot260();
    virtual void procSlot261();
    virtual void procSlot262();
    virtual void procSlot263();
    virtual void procSlot264();
    virtual void procSlot265();
    virtual void procSlot266();
    virtual void procSlot267();
    virtual void procSlot268();
    virtual void procSlot269();
    virtual void procSlot270();
    virtual void procSlot271();
    virtual void procSlot272();
    virtual void procSlot273();
    virtual void procSlot274();
    virtual void procSlot275();
    virtual void procSlot276();
    virtual void procSlot277();
    virtual void procSlot278();
    virtual void procSlot279();
    virtual void procSlot280();
    virtual void procSlot281();
    virtual void procSlot282();
    virtual void procSlot283();
    virtual void procSlot284();
    virtual void procSlot285();
    virtual void procSlot286();
    virtual void procSlot287();
    virtual void procSlot288();
    virtual void procSlot289();
    virtual void procSlot290();
    virtual void procSlot291();
    virtual void procSlot292();
    virtual void procSlot293();
    virtual void procSlot294();
    virtual void procSlot295();
    virtual void procSlot296();
    virtual void procSlot297();
    virtual void procSlot298();
    virtual void procSlot299();
    virtual void procSlot300();
    virtual void procSlot301();
    virtual void procSlot302();
    virtual void procSlot303();
    virtual void procSlot304();
    virtual void procSlot305();
    virtual void procSlot306();
    virtual void procSlot307();
    virtual void procSlot308();
    virtual void procSlot309();
    virtual void procSlot310();
    virtual void procSlot311();
    virtual void procSlot312();
    virtual void procSlot313();
    virtual void procSlot314();
    virtual void procSlot315();
    virtual void procSlot316();
    virtual void procSlot317();
    virtual void procSlot318();
    virtual void procSlot319();
    virtual void procSlot320();
    virtual void procSlot321();
    virtual void procSlot322();
    virtual void procSlot323();
    virtual void procSlot324();
    virtual void procSlot325();
    virtual void procSlot326();
    virtual void procSlot327();
    virtual void procSlot328();
    virtual void procSlot329();
    virtual void procSlot330();
    virtual void procSlot331();
    virtual void procSlot332();
    virtual void procSlot333();
    virtual void procSlot334();
    virtual void procSlot335();
    virtual void procSlot336();
    virtual void procSlot337();
    virtual void procSlot338();
    virtual void procSlot339();
    virtual void procSlot340();
    virtual void procSlot341();
    virtual void procSlot342();
    virtual void procSlot343();
    virtual void procSlot344();
    virtual void procSlot345();
    virtual void procSlot346();
    virtual void procSlot347();
    virtual void procSlot348();
    virtual void procSlot349();
    virtual void procSlot350();
    virtual void procSlot351();
    virtual void procSlot352();
    virtual void procSlot353();
    virtual void procSlot354();
    virtual void procSlot355();
    virtual void procSlot356();
    virtual void procSlot357();
    virtual void procSlot358();
    virtual void procSlot359();
    virtual void procSlot360();
    virtual void procSlot361();
    virtual void procSlot362();
    virtual void procSlot363();
    virtual void procSlot364();
    virtual void procSlot365();
    virtual void procSlot366();
    virtual void procSlot367();
    virtual void procSlot368();
    virtual void procSlot369();
    virtual void procSlot370();
    virtual void procSlot371();
    virtual void procSlot372();
    virtual void procSlot373();
    virtual void procSlot374();
    virtual void procSlot375();
    virtual void procSlot376();
    virtual void procSlot377();
    virtual void procSlot378();
    virtual void procSlot379();
    virtual void procSlot380();
    virtual void procSlot381();
    virtual void procSlot382();
    virtual void procSlot383();
    virtual void procSlot384();
    virtual void procSlot385();
    virtual void procSlot386();
    virtual void procSlot387();
    virtual void procSlot388();
    virtual void procSlot389();
    virtual void procSlot390();
    virtual void procSlot391();
    virtual void procSlot392();
    virtual void procSlot393();
    virtual void procSlot394();
    virtual void procSlot395();
    virtual void procSlot396();
    virtual void procSlot397();
    virtual void procSlot398();
    virtual void procSlot399();
    virtual void procSlot400();
    virtual void procSlot401();
    virtual void procSlot402();
    virtual void procSlot403();
    virtual void procSlot404();
    virtual void procSlot405();
    virtual void procSlot406();
    virtual void procSlot407();
    virtual void procSlot408();
    virtual void procSlot409();
    virtual void procSlot410();
    virtual void procSlot411();
    virtual void procSlot412();
    virtual void procSlot413();
    virtual void procSlot414();
    virtual void procSlot415();
    virtual void procSlot416();
    virtual void procSlot417();
    virtual void procSlot418();
    virtual void procSlot419();
    virtual void procSlot420();
    virtual void procSlot421();
    virtual void procSlot422();
    virtual void procSlot423();
    virtual void procSlot424();
    virtual void procSlot425();
    virtual void procSlot426();
    virtual void procSlot427();
    virtual void procSlot428();
    virtual void procSlot429();
    virtual void procSlot430();
    virtual void procSlot431();
    virtual void procSlot432();
    virtual void procSlot433();
    virtual void procSlot434();
    virtual void procSlot435();
    virtual void procSlot436();
    virtual void procSlot437();
    virtual void procSlot438();
    virtual void procSlot439();
    virtual void procSlot440();
    virtual void procSlot441();
    virtual void procSlot442();
    virtual void procSlot443();
    virtual void procSlot444();
    virtual void procSlot445();
    virtual void procSlot446();
    virtual void procSlot447();
    virtual void procSlot448();
    virtual void procSlot449();
    virtual void procSlot450();
    virtual void procSlot451();
    virtual void procSlot452();
    virtual void procSlot453();
    virtual void procSlot454();
    virtual void procSlot455();
    virtual void procSlot456();
    virtual void procSlot457();
    virtual void procSlot458();
    virtual void procSlot459();
    virtual void procSlot460();
    virtual void procSlot461();
    virtual void procSlot462();
    virtual void procSlot463();
    virtual void procSlot464();
    virtual void procSlot465();
    virtual void procSlot466();
    virtual void procSlot467();
    virtual void procSlot468();
    virtual void procSlot469();
    virtual void procSlot470();
    virtual void procSlot471();
    virtual void procSlot472();
    virtual void procSlot473();
    virtual void procSlot474();
    virtual void procSlot475();
    virtual void procSlot476();
    virtual void procSlot477();
    virtual void procSlot478();
    virtual void procSlot479();
    virtual void procSlot480();
    virtual void procSlot481();
    virtual void procSlot482();
    virtual void procSlot483();
    virtual void procSlot484();
    virtual void procSlot485();
    virtual void procSlot486();
    virtual void procSlot487();
    virtual void procSlot488();
    virtual void procSlot489();
    virtual void procSlot490();
    virtual void procSlot491();
    virtual void procSlot492();
    virtual void procSlot493();
    virtual void procSlot494();
    virtual void procSlot495();
    virtual void procSlot496();
    virtual void procSlot497();
    virtual void procSlot498();
    virtual void procSlot499();
    virtual void procSlot500();
    virtual void procSlot501();
    virtual void procSlot502();
    virtual void procSlot503();
    virtual void procSlot504();
    virtual void procSlot505();
    virtual void procSlot506();
    virtual void procSlot507();
    virtual void procSlot508();
    virtual void procSlot509();
    virtual void procSlot510();
    virtual void procSlot511();
    virtual void procSlot512();
    virtual void procSlot513();
    virtual void procSlot514();
    virtual void procSlot515();
    virtual void procSlot516();
    virtual void procSlot517();
    virtual void CompleteSearch(SearchReference*);
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
    SearchList results;
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
    void CollectSearchResults(SearchReference*, SearchReference*, int);
};
// @fnv 0x00910e20
void SearchProcess::CollectSearchResults(SearchReference* actor, SearchReference* container, int kind)
{
    void* containerData = 0;
    if (container)
        containerData = container->GetContainer();
    SearchInventory* inventory5 = 0;
    if (containerData)
        inventory5 = GetInventory(container);
    if (inventory5)
    {
        switch (kind)
        {
        case 19: {
            int count0 = inventory5->Count(1);
            SearchEntry* entry0 = 0;
            for (int index0 = 0; index0 < count0; ++index0)
            {
                entry0 = inventory5->Get(index0);
                if (entry0)
                {
                    TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(entry0->GetObject());
                    TESObjectWEAP* weapon0 = dynamic_cast<TESObjectWEAP*>(entry0->GetObject());
                    TESAmmo* ammo3 = dynamic_cast<TESAmmo*>(entry0->GetObject());
                    if ((armor || weapon0 || ammo3))
                    {
                        SearchResult* result0 = new SearchResult;
                        result0->object = entry0->GetObject();
                        result0->quantity = entry0->GetCount();
                        result0->owner = container;
                        result0->enabled = 1;
                        results.Append(&result0);
                    }
                    delete entry0;
                    entry0 = 0;
                }
            }
            break;
        }
        case 20: {
            int count1 = inventory5->Count(1);
            SearchEntry* entry5 = 0;
            for (int index1 = 0; index1 < count1; ++index1)
            {
                entry5 = inventory5->Get(index1);
                if (entry5)
                {
                    TESObjectARMO* armor1 = dynamic_cast<TESObjectARMO*>(entry5->GetObject());
                    TESObjectWEAP* weapon6 = dynamic_cast<TESObjectWEAP*>(entry5->GetObject());
                    TESAmmo* ammo1 = dynamic_cast<TESAmmo*>(entry5->GetObject());
                    TESObjectCLOT* clothing1 = dynamic_cast<TESObjectCLOT*>(entry5->GetObject());
                    if ((armor1 || weapon6 || ammo1 || clothing1))
                    {
                        SearchResult* result1 = new SearchResult;
                        result1->object = entry5->GetObject();
                        result1->quantity = entry5->GetCount();
                        result1->owner = container;
                        result1->enabled = 1;
                        results.Append(&result1);
                    }
                    delete entry5;
                    entry5 = 0;
                }
            }
            break;
        }
        case 12: {
            int count2 = inventory5->Count(1);
            SearchEntry* entry7 = 0;
            for (int index2 = 0; index2 < count2; ++index2)
            {
                entry7 = inventory5->Get(index2);
                if (entry7)
                {
                    TESObjectWEAP* weapon2 = dynamic_cast<TESObjectWEAP*>(entry7->GetObject());
                    if ((weapon2))
                    {
                        SearchResult* result2 = new SearchResult;
                        result2->object = entry7->GetObject();
                        result2->quantity = entry7->GetCount();
                        result2->owner = container;
                        result2->enabled = 1;
                        results.Append(&result2);
                    }
                    delete entry7;
                    entry7 = 0;
                }
            }
            break;
        }
        case 22: {
            int count3 = inventory5->Count(1);
            SearchEntry* entry3 = 0;
            for (int index3 = 0; index3 < count3; ++index3)
            {
                entry3 = inventory5->Get(index3);
                if (entry3)
                {
                    TESObjectWEAP* weapon3 = dynamic_cast<TESObjectWEAP*>(entry3->GetObject());
                    if ((weapon3) && weapon3->IsRanged())
                    {
                        SearchResult* result3 = new SearchResult;
                        result3->object = entry3->GetObject();
                        result3->quantity = entry3->GetCount();
                        result3->owner = container;
                        result3->enabled = 1;
                        results.Append(&result3);
                    }
                    delete entry3;
                    entry3 = 0;
                }
            }
            break;
        }
        case 23: {
            int count4 = inventory5->Count(1);
            SearchEntry* entryB = 0;
            for (int index4 = 0; index4 < count4; ++index4)
            {
                entryB = inventory5->Get(index4);
                if (entryB)
                {
                    TESObjectWEAP* weapon4 = dynamic_cast<TESObjectWEAP*>(entryB->GetObject());
                    if ((weapon4) && weapon4->IsMelee())
                    {
                        SearchResult* result4 = new SearchResult;
                        result4->object = entryB->GetObject();
                        result4->quantity = entryB->GetCount();
                        result4->owner = container;
                        result4->enabled = 1;
                        results.Append(&result4);
                    }
                    delete entryB;
                    entryB = 0;
                }
            }
            break;
        }
        }
    }
    else
    {
        void* kCell = actor->Cell();
        NiPoint3 position = *actor->Position();
        field8c = kind;
        float radius7 = 0.0f;
        SearchPackage* package = ActivePackage();
        if (kCell && m_kProcessData()->HasSearchLocation())
        {
            unsigned int range = package->Radius(actor);
            kCell = package->Cell(actor);
            position = package->Coord(actor);
            if (kCell)
            {
                radius7 = range > 0 ? (float)range
                                    : (((SearchCell*)kCell)->IsInterior() ? DAT_01016970
                                                                          : *((SearchDefault*)&DAT_011cdebc)->Value());
            }
            else
            {
                SearchLog("Package on %s is using an invalid Search Location\n", actor->Name());
            }
            DAT_011c3f2c->Visit(kCell, &position, radius7, &position, radius7, CheckPackageMatch, actor);
        }
        else
        {
            if (!m_kProcessData() || !m_kProcessData()->AcquireRadius(actor, radius7))
                radius7 = *((SearchDefault*)&DAT_011cdebc)->Value();
            DAT_011c3f2c->Visit(kCell, &position, radius7, actor->Position(), radius7, CheckPackageMatch, actor);
        }
        field8c = 0;
        field84 = 0;
        field90 = 0;
        CompleteSearch(actor);
    }
}

namespace fnv_00911b00 {
extern "C" TESObjectREFR* DAT_011dea3c;

class List_009e03e0;

struct ExtraFollower
{
    int m0;
    int m4;
    int m8;
    List_009e03e0* m_pkList;
};

class List_009e03e0
{
  public:
    TESObjectREFR* m_item;
    List_009e03e0* m_pkNext;
    List_009e03e0();
    ~List_009e03e0();
    TESObjectREFR** GetItem();
    List_009e03e0* GetNext();
    bool IsEmpty();
    void AddTail(TESObjectREFR*& item);
    void AddHead(TESObjectREFR*& item);
    void RemoveAll();
};

class ExtraDataShell
{
  public:
    ExtraFollower* FUN_00422700();
    void FUN_00422690(TESObjectREFR*);
    void FUN_00422720();
    TESPackage* FUN_0041cb10();
};

class PkgShell
{
  public:
    bool FUN_00678610();
    int get();
};

class RefShell
{
  public:
    void* FUN_00881510();
    void* FUN_00931850();
};

class RefVt
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
    virtual void vfn_25c(float);
};

class Host911b00
{
  public:
    void UpdateFollowerList(TESObjectREFR* pRef, float time);
};

// Rebuilds the follower list of pRef from its ExtraFollower list, moving or updating each follower reference based on package state and disabled flag.
// @fnv 0x00911b00
void Host911b00::UpdateFollowerList(TESObjectREFR* pRef, float time)
{
    bool bFlag = false;

    if (pRef->vfn_22c(0) || pRef->GetDisabled())
        bFlag = true;

    ExtraFollower* pFol = ((ExtraDataShell*)pRef->GetExtraData())->FUN_00422700();
    if (pFol != 0)
    {
        List_009e03e0* pCopiedFollowerList = new List_009e03e0();
        List_009e03e0* pTempX = new List_009e03e0();
        List_009e03e0* pNode6 = pTempX;
        List_009e03e0* pCur_2 = pFol->m_pkList;

        while (pCur_2 != 0 && *pCur_2->GetItem() != 0)
        {
            pTempX->AddTail(*pCur_2->GetItem());
            pCur_2 = pCur_2->GetNext();
        }

        while (pNode6 != 0 && *pNode6->GetItem() != 0)
        {
            TESObjectREFR* pRef2 = *pNode6->GetItem();

            if (bFlag)
            {
                pCopiedFollowerList->AddHead(pRef2);
            }
            else if (pRef2 != 0 && pRef2 != DAT_011dea3c)
            {
                bool bOk4 = false;
                void* pA_2 = ((RefShell*)pRef)->FUN_00881510();
                TESPackage* pPkg7 = ((ExtraDataShell*)pRef->GetExtraData())->FUN_0041cb10();
                if (pA_2 == 0 || ((PkgShell*)pA_2)->FUN_00678610())
                {
                    if (pPkg7 != 0)
                        pA_2 = pPkg7;
                }
                if (pA_2 != 0 && ((PkgShell*)pA_2)->get() == 2)
                    bOk4 = true;

                void* pA8 = ((RefShell*)pRef2)->FUN_00881510();
                TESPackage* pPkg3 = ((ExtraDataShell*)pRef2->GetExtraData())->FUN_0041cb10();
                if (pA8 == 0 || (((PkgShell*)pA8)->FUN_00678610() && pPkg3 != 0))
                    pA8 = pPkg3;

                if (!bOk4 && (pA8 == 0 || (((PkgShell*)pA8)->get() != 1 && ((PkgShell*)pA8)->get() != 7)))
                {
                    pCopiedFollowerList->AddHead(pRef2);
                }
                else
                {
                    void* pR = ((RefShell*)pRef2)->FUN_00931850();
                    if (pR != 0)
                    {
                        ((RefVt*)pRef2)->vfn_25c(time);
                        pRef2->FUN_00565870();
                    }
                }
            }

            pNode6 = pNode6->GetNext();
        }

        pNode6 = pCopiedFollowerList;
        while (pNode6 != 0 && *pNode6->GetItem() != 0)
        {
            TESObjectREFR* pRef3 = *pNode6->GetItem();
            ((ExtraDataShell*)pRef->GetExtraData())->FUN_00422690(pRef3);
            pNode6 = pNode6->GetNext();
        }

        pTempX->RemoveAll();
        delete pTempX;
        pCopiedFollowerList->RemoveAll();
        delete pCopiedFollowerList;

        if (pFol->m_pkList->IsEmpty())
            ((ExtraDataShell*)pRef->GetExtraData())->FUN_00422720();
    }
}
}  // namespace fnv_00911b00

namespace fnv_00912db0 {
// 0x00912db0  unit_c5661b6602f6.cpp  /MT /Od /Oy- /GS /EHsc /Gy /GF
struct Refr;
struct Pkg;
struct IdleForm;
struct SForm;
struct P3
{
    float x, y, z;
    P3();
};
struct IdleForm
{
    char eType;
    char pad[7];
    Refr* pRef;
    int GetType();
    Refr* FUN_0067F390();
};
struct Pkg
{
    char pad[0x2c];
    IdleForm* FUN_0055b980();
    void* FUN_00671d10();
    unsigned FUN_00676280(Refr* mob);
};
struct Flags
{
    int a, b, c;
    int FUN_0044ddc0();
};
struct SForm
{
    void SetScript(void*);
};
struct Obj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
    virtual Refr* vfn_128();
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
    virtual P3* vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void* vfn_20c();
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
    virtual Pkg* vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void* vfn_294();
    virtual void* vfn_298();
    virtual P3 vfn_29c();
    char pad44[0x40];
    Refr* m_pReference40;
    Refr* FUN_00569b80();
    void* FUN_008d6f30();
    void* FUN_00575d70();
    void PathToLocation(PathingRequest*, void const*, unsigned, unsigned, float, unsigned);
    void SetPathingRequestAvoidNodes(PathingRequest*);
    void StartPackagePathing(Refr* actor, SForm* form);
};
// @fnv 0x00912db0
void Obj::StartPackagePathing(Refr* actor, SForm* form)
{
    Refr* pTgt9 = 0;
    P3 pos5;
    unsigned i382 = 0;
    unsigned n1cObj = 0;
    Pkg* pScriptRef = vfn_27c();
    IdleForm* pIdleA = pScriptRef->FUN_0055b980();
    Flags* pX = (Flags*)pScriptRef->FUN_00671d10();
    bool bFlag3 = true;
    if (pIdleA)
    {
        if (pIdleA->GetType() == 3)
        {
            pos5 = ((Obj*)actor)->vfn_29c();
            i382 = (unsigned)((Obj*)actor)->vfn_298();
            n1cObj = (unsigned)((Obj*)actor)->vfn_294();
            bFlag3 = false;
        }
        else if (pIdleA->GetType() == 2)
        {
            pTgt9 = (Refr*)actor;
        }
        else if (pIdleA->GetType() == 6)
        {
            pTgt9 = ((Obj*)actor)->FUN_00569b80();
        }
        else
        {
            pTgt9 = pIdleA->FUN_0067F390();
            if (!pTgt9 && !vfn_20c())
                pTgt9 = m_pReference40;
        }
    }
    if (!pTgt9 && bFlag3)
        pTgt9 = vfn_128();
    float f4 = pIdleA ? (float)pScriptRef->FUN_00676280(actor) : pX ? (float)pX->FUN_0044ddc0() : 30.0f;
    f4 = FUN_00404010(f4 * 0.5, 15.0f);
    if (pTgt9)
    {
        PathingRequest reqA;
        ((Obj*)actor)
            ->PathToLocation(&reqA, ((Obj*)pTgt9)->vfn_1f4(), (unsigned)((Obj*)pTgt9)->FUN_008d6f30(),
                             (unsigned)((Obj*)pTgt9)->FUN_00575d70(), f4, 0);
        reqA.SetUseSoft(false);
        ((Obj*)actor)->SetPathingRequestAvoidNodes(&reqA);
        form->SetScript((void*)1);
    }
    else if (i382 || n1cObj)
    {
        PathingRequest reqB;
        ((Obj*)actor)->PathToLocation(&reqB, &pos5, i382, n1cObj, f4, 0);
        reqB.SetUseSoft(false);
        ((Obj*)actor)->SetPathingRequestAvoidNodes(&reqB);
        form->SetScript((void*)1);
    }
}
}  // namespace fnv_00912db0

// Pickup target: the first extra-data list of an inventory entry.
struct EntryExtendList
{
    ExtraDataList** FUN_006815c0();
};

struct InventoryEntry
{
    EntryExtendList* FUN_00559450();
    void* FUN_0044ddc0(ExtraDataList* xData, TESObjectREFR* location, int countIn, void* ownerTmp);
    void* FUN_0044ddc0(ExtraDataList* xData, int countIn, NiPoint3* posVal, int flags);
    ~InventoryEntry();
};

struct AcquireRef : TESObjectREFR
{
    int FUN_0055d310();
    TESBoundObject* FUN_007af430();
};

struct PackageTargetData
{
    AcquireRef* FUN_0067f390();
};

struct PackageLocationData
{
    int FUN_00680020();
};

struct AcquirePackage : TESPackage
{
    PackageTargetData* FUN_0055b980();
    PackageLocationData* FUN_00671d10();
    int FUN_00672930();
    NiPoint3 FUN_00675de0(Actor* actor);
    TESObjectCELL* FUN_00675c20(Actor* actor);
    TESWorldSpace* FUN_00675a50(Actor* actor);
};

struct AcquireActor : Actor
{
    InventoryEntry* FUN_008a2d40();
    bool FUN_00575450(void* ownerTmp);
    InventoryEntry* FUN_00576260(TESBoundObject* item, int countIn);
    void FUN_00892e90(void* item);
    float FUN_005723b0(TESObjectREFR* ref, int a, int b);
    void FUN_008b3690(const NiPoint3& posVal, TESObjectCELL* cellOld, TESWorldSpace* world, float radius, int flags);
};

// Actor's primary vtable up to slot 0xF3, which takes the picked-up item.
struct ActorSlots
{
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void AddPickedUpItem(void* item);
};

struct PathingLocationAt : PathingLocation
{
    PathingLocationAt(const NiPoint3& posVal, TESObjectCELL* cellOld, TESWorldSpace* world);
};

void __cdecl GetObjectFloat(PathingLocation* from, PathingLocation* to, float* distance);

struct AcquireProcess : LowProcess
{
    float FUN_00907260(Actor* actor);
    void FUN_00909430(AcquireActor* actor);
};

// Resolves an acquire target, may transfer an inventory entry, and may pass a package position to an actor method.
// @fnv 0x00909430
void AcquireProcess::FUN_00909430(AcquireActor* actor)
{
    AcquirePackage* packageNum = (AcquirePackage*)vfn_27c();
    if (pTarget == 0)
        FindPackageTarget(actor);
    int locationIndex = 0;
    InventoryEntry* entry = actor->FUN_008a2d40();
    bool createdEntryIn = false;

    if (entry == 0 &&
        (pTarget == 0 || (!pTarget->IsActor() && !actor->FUN_00575450(((Actor*)pTarget)->FUN_0084e3a0()))))
    {
        FindPackageTarget(actor);
        if (pTarget == 0 || (!pTarget->IsActor() && !actor->FUN_00575450(((Actor*)pTarget)->FUN_0084e3a0())))
        {
            SetProcessTarget(actor, 1);
            return;
        }
    }
    if (entry == 0 && m_pDetectionData60 != 0 && m_pDetectionData60->pObject == actor)
    {
        entry = actor->FUN_00576260(m_pDetectionData60->pItem, 0);
        createdEntryIn = true;
    }
    if (((AcquirePackage*)GetCurrentPackage())->FUN_00671d10())
        locationIndex = ((AcquirePackage*)GetCurrentPackage())->FUN_00672930();
    if ((pTarget == 0 || (!pTarget->IsActor() && !actor->FUN_00575450(((Actor*)pTarget)->FUN_0084e3a0()))) &&
        !vfn_80c(actor, locationIndex))
    {
        SetProcessTarget(actor, 1);
        delete entry;
        return;
    }

    float timeDeltaTmp = FUN_00907260(actor);
    if (GetCurrentPackage()->IsPackageRunningForActor(actor, 0, -1.0f, false))
    {
        if ((pTarget != 0 && !pTarget->IsActor()) || pTarget == 0)
        {
            if (entry != 0)
            {
                ExtraDataList* xData = 0;
                if (entry->FUN_00559450())
                    xData = *entry->FUN_00559450()->FUN_006815c0();
                void* ownerTmp = 0;
                if (xData != 0 && xData->FUN_0041c8d0())
                    ownerTmp = ((Actor*)xData->FUN_0041c8d0())->FUN_0084e3a0();
                AcquireRef* location = packageNum->FUN_0055b980()->FUN_0067f390();
                if (location == 0)
                    location = (AcquireRef*)m_pReference40;
                if (location != 0 && location->FUN_0055d310())
                {
                    actor->FUN_00892e90(entry->FUN_0044ddc0(xData, location, packageNum->FUN_00672930(), ownerTmp));
                }
                else
                {
                    if (entry->FUN_00559450())
                        xData = *entry->FUN_00559450()->FUN_006815c0();
                    NiPoint3* posVal = 0;
                    PackageTargetData* target = packageNum->FUN_0055b980();
                    PackageLocationData* packageLocation = packageNum->FUN_00671d10();
                    if (target != 0)
                    {
                        AcquireRef* container = target->FUN_0067f390();
                        if (container == 0)
                            container = (AcquireRef*)m_pReference40;
                        if (container != 0 &&
                            (container->FUN_007af430() == DAT_011ca244 || container->FUN_007af430() == DAT_011ca248))
                            posVal = container->GetPos();
                    }
                    int countIn = 1;
                    if (!packageLocation->FUN_00680020())
                        countIn = packageNum->FUN_00672930();
                    ((ActorSlots*)actor)->AddPickedUpItem(entry->FUN_0044ddc0(xData, countIn, posVal, 0));
                }
            }
            SetProcessTarget(actor, 1);
        }
        else if (pTarget != 0)
        {
            if (GetCurrentPackage()->IsPackageRunningForActor((Actor*)pTarget, 0, -1.0f, false))
                SetProcessTarget(actor, 1);
        }
        else
        {
            SetProcessTarget(actor, 1);
        }
    }
    else
    {
        int minDistanceRes = (int)GetCurrentPackage()->GetPackageResult(actor, false);
        float actorPathLength = 0.0f;
        float targetPathLength = 0.0f;
        if (pTarget != 0 && pTarget->IsActor())
        {
            NiPoint3 destinationVal = packageNum->FUN_00675de0(actor);
            TESObjectCELL* cellOld = packageNum->FUN_00675c20(actor);
            TESWorldSpace* world = packageNum->FUN_00675a50(actor);
            PathingLocation actorLocation(actor);
            PathingLocationAt destinationLocation(destinationVal, cellOld, world);
            GetObjectFloat(&actorLocation, &destinationLocation, &actorPathLength);
            TESObjectREFR* targetRefCur = pTarget;
            PathingLocation targetLocationCur(targetRefCur);
            GetObjectFloat(&targetLocationCur, &destinationLocation, &targetPathLength);
        }
        if (pTarget == 0 || !pTarget->IsActor() || actor->FUN_005723b0(pTarget, 0, 0) < minDistanceRes ||
            actorPathLength > targetPathLength)
        {
            if (actor->FUN_008b3bb0())
                actor->FUN_008b3690(((AcquirePackage*)GetCurrentPackage())->FUN_00675de0(actor),
                                    ((AcquirePackage*)GetCurrentPackage())->FUN_00675c20(actor),
                                    ((AcquirePackage*)GetCurrentPackage())->FUN_00675a50(actor), -1.0f, 0);
        }
    }
    delete entry;
}

namespace fnv_0090ac40 {
struct RX
{
    bool FUN_00891db0(void* a, void* b);
};
struct ItemX
{
    int FUN_0084e3a0();
    void* FUN_007af430(int a, int b, int c);
};
struct ProcX
{
    int FUN_00519b00();
    void* FUN_00680050(int a, int b, int c);
    void* FUN_00680080(int a, int b, void* c);
};
struct BaseX
{
    ProcX* FUN_00671d10();
};
struct ListX
{
    ItemX* FUN_0044ddc0();
};
class SelfX
{
  public:
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62(), v63(),
        v64(), v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79(),
        v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(), v95(),
        v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109(),
        v110(), v111(), v112(), v113(), v114(), v115(), v116(), v117(), v118(), v119(), v120(), v121(), v122(), v123(),
        v124(), v125(), v126(), v127(), v128(), v129(), v130(), v131(), v132(), v133(), v134(), v135(), v136(), v137(),
        v138();
    virtual BaseX* F22c();
    ListX m4;
    bool FUN_0090ac40(RX* pkR, int iArg);
};
// @fnv 0x0090ac40
bool SelfX::FUN_0090ac40(RX* pkR, int iArg)
{
    BaseX* pkBase = 0;
    pkBase = F22c();
    ProcX* pkProc6 = pkBase->FUN_00671d10();
    if (!pkProc6)
        return false;
    int iType9 = pkProc6->FUN_00519b00();
    bool bResultTmp = false;
    int iData3;
    switch (iType9)
    {
    case 0:
    case 3: {
        ItemX* pkItem = m4.FUN_0044ddc0();
        if (pkItem)
            bResultTmp = pkR->FUN_00891db0(pkItem->FUN_007af430(0, 1, pkItem->FUN_0084e3a0()), &iData3);
        else
            bResultTmp = false;
        break;
    }
    case 1:
        bResultTmp = pkR->FUN_00891db0(pkProc6->FUN_00680050(0, iArg, 0), &iData3);
        break;
    case 2:
        bResultTmp = pkR->FUN_00891db0(0, pkProc6->FUN_00680080(iArg, 0, &iData3));
        break;
    }
    return bResultTmp;
}
}  // namespace fnv_0090ac40

struct CountX
{
    int FUN_0044ddc0();
};
struct ProcX
{
    int FUN_009611e0();
    int FUN_0055b980();
    float FUN_00678670(int i, int j);
    CountX* FUN_00671d10();
    bool IsFlag4Clear();
    unsigned FUN_00676280(int i);
    float GetPackageResult(int i, int j);
};
extern int* DAT_011a3ff0[];
struct ActorX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc(), v1d0(), v1d4(), v1d8(), v1dc(), v1e0(), v1e4(), v1e8(), v1ec(), v1f0(),
        v1f4(), v1f8(), v1fc(), v200(), v204(), v208(), v20c(), v210(), v214(), v218(), v21c(), v220(), v224(), v228();
    virtual ProcX* v22c();
    virtual void v230(), v234(), v238(), v23c(), v240(), v244(), v248(), v24c(), v250(), v254(), v258(), v25c(), v260(),
        v264(), v268(), v26c(), v270(), v274(), v278(), v27c();
    virtual int v280();
    float FUN_0090f670(int iArg);
};
// Returns a float selected by package type, using package results in some cases and otherwise defaulting to 128.0f.
// @fnv 0x0090f670
float ActorX::FUN_0090f670(int iArg)
{
    float fResultTmp = 128.0f;
    if (!v22c())
        return fResultTmp;
    switch (DAT_011a3ff0[v22c()->FUN_009611e0()][v280()])
    {
    case 0:
    case 50:
        if (v22c()->FUN_0055b980())
            fResultTmp = v22c()->FUN_00678670(iArg, 0);
        break;
    case 47: {
        CountX* pkCount = v22c()->FUN_00671d10();
        float fUnused3 = (v22c()->IsFlag4Clear() && v22c()->FUN_0055b980())
                             ? (float)v22c()->FUN_00676280(iArg)
                             : (pkCount ? (float)pkCount->FUN_0044ddc0() : 30.0f);
        break;
        break;
    }
    case 1:
    case 2:
    case 3:
    case 8:
    case 14:
    case 15:
        if (v22c()->FUN_00671d10())
            fResultTmp = v22c()->GetPackageResult(iArg, 0);
        break;
        break;
    case 6:
    case 7:
    case 13:
    case 30:
        if (v22c()->FUN_00671d10())
            fResultTmp = v22c()->GetPackageResult(iArg, 0);
        break;
    }
    return fResultTmp;
}

struct FUN_007b3fa0
{
    ~FUN_007b3fa0();
};
struct ListQ
{
    bool FUN_008256d0();
    FUN_007b3fa0** FUN_006815c0();
    void FUN_00905330(FUN_007b3fa0* const& r);
    int pad[2];
};
struct M6cQ
{
    void FUN_00470470();
    int p[10];
};
struct M94Q
{
    void FUN_00937b30();
    int p[4];
};
struct GQ
{
    bool FUN_0055f5b0();
};
extern GQ* DAT_011de45c;
struct A2Q
{
    bool FUN_00440d80();
};
struct ObjQ
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
    virtual void V75(int);
    int p04[11];
    bool b30;
    char c31[3];
    int i34;
    int p38[3];
    int i44;
    int p48[4];
    int i58;
    ListQ kList;
    int i64;
    int i68;
    M6cQ k6c;
    M94Q k94;
    float fA4;
    float fA8;
    float fAC;
    void FUN_008d0f10(unsigned int a1, A2Q* a2);
    void ResetAndClear(unsigned int a1, A2Q* a2);
};

// Calls FUN_008d0f10, then if DAT_011de45c->FUN_0055f5b0() is true, clears kList elements, resets k6c, zeroes fields, and calls V75(0).
// @fnv 0x00910310
void ObjQ::ResetAndClear(unsigned int auiFlags, A2Q* a2)
{
    FUN_008d0f10(auiFlags, a2);
    if (DAT_011de45c->FUN_0055f5b0())
    {
        i58 = 0;
        while (!kList.FUN_008256d0())
        {
            FUN_007b3fa0* pElem = *kList.FUN_006815c0();
            kList.FUN_00905330(pElem);
            delete pElem;
        }
        k6c.FUN_00470470();
        i64 = 0;
        i68 = 0;
        V75(0);
        i44 = 0;
        fA4 = 0.0f;
        i34 = 0;
        fA8 = 0.0f;
        b30 = false;
        fAC = 0.0f;
    }
    if (!a2->FUN_00440d80())
        DAT_011de45c->FUN_0055f5b0();
    if (0)
    {
    }
    if (0)
    {
    }
    if (auiFlags & 0x200000)
        k94.FUN_00937b30();
}

struct PackageTargetView
{
    TESObjectREFR* FUN_0067f390();
};
struct PackageView
{
    bool FUN_00678610();
    int FUN_009611e0();
    PackageTargetView* FUN_0055b980();
    bool IsFlag4Clear();
};
struct ActorPackageView
{
    PackageView* FUN_0041cb10();
    int FUN_0041cb40();
    TESObjectREFR* FUN_0041cb70();
};
struct TargetProcess
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
    virtual TESObjectREFR* vfn_128();
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
    virtual void vfn_37c();
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
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual TESObjectREFR* vfn_514();
};
struct TargetActor : Actor
{
    ActorPackageView* FUN_005d43c0();
    TargetProcess* FUN_008d8520();
    PackageView* FUN_009344a0();
};
struct TargetPackage : TESPackage
{
    TESObjectREFR* FUN_00676140(MobileObject*);
};
struct LowProcessTarget : LowProcess
{
    TESObjectREFR* FUN_0090e970(TargetActor* actor, bool useCurrent);
};
// Resolves the target reference for a LowProcess package, selecting from the current package, the actor, or a target process based on the procedure index.
// @fnv 0x0090e970
TESObjectREFR* LowProcessTarget::FUN_0090e970(TargetActor* actor, bool useCurrent)
{
    PackageView* package2 = (PackageView*)GetCurrentPackage();
    TESObjectREFR* target2 = pTarget;
    int index = GetProcedureIndex();
    if (!useCurrent && (!package2 || package2->FUN_00678610()))
    {
        package2 = actor->FUN_005d43c0()->FUN_0041cb10();
        index = actor->FUN_005d43c0()->FUN_0041cb40();
        target2 = actor->FUN_005d43c0()->FUN_0041cb70();
    }
    if (!package2)
        return 0;
    if (package2->FUN_009611e0() == -1)
        return 0;
    switch (DAT_011a3ff0[package2->FUN_009611e0()][index])
    {
    case 27:
        if (target2 && target2->IsActor())
        {
            TargetActor* targetActor = (TargetActor*)target2;
            PackageView* targetPackage = targetActor->FUN_009344a0();
            if (targetPackage)
                target2 = ((TargetPackage*)targetPackage)->FUN_00676140(targetActor);
        }
        break;
    case 1:
    case 2:
    case 3:
    case 6:
    case 8:
    case 9:
    case 13:
    case 14:
    case 15:
    case 28:
    case 30:
    case 38:
    case 42:
    case 44:
        if (!target2)
            target2 = actor;
        break;
    case 0:
    case 4:
    case 5:
    case 7:
    case 50:
        target2 = package2->FUN_0055b980() ? package2->FUN_0055b980()->FUN_0067f390() : 0;
        if (!target2)
            target2 = actor->FUN_008d8520() ? actor->FUN_008d8520()->vfn_514() : 0;
        if (!target2)
            target2 = actor;
        break;
    case 47:
        if (package2->IsFlag4Clear() && package2->FUN_0055b980())
            target2 = package2->FUN_0055b980()->FUN_0067f390();
        else
        {
            TargetProcess* aProcess = actor->FUN_008d8520();
            if (aProcess)
            {
                target2 = aProcess->vfn_128();
                if (!target2)
                    target2 = aProcess->vfn_514();
                if (!target2)
                    target2 = actor;
            }
        }
        break;
    case 54:
        if (package2->FUN_0055b980())
            target2 = package2->FUN_0055b980()->FUN_0067f390();
        if (!target2)
            target2 = actor->FUN_008d8520() ? actor->FUN_008d8520()->vfn_514() : 0;
        if (!target2)
            target2 = actor;
        break;
    }
    return target2;
}

class PkgForm;
class ProcHolder;
class PosRef;

class PkgSub
{
  public:
    PosRef* FUN_00680020();
};

class PkgForm
{
  public:
    bool FUN_00678610();
    int FUN_009611e0();
    int FUN_0055b980();
    NiPoint3 FUN_00675de0(PosRef* target);
    bool IsFlag4Clear();
    PkgSub* FUN_00671d10();
    int FUN_0041ca90();
};

class ProcHolder
{
  public:
    PkgForm* FUN_0041cb10();
    int FUN_0041cb40();
    PosRef* FUN_0041cb70();
};

class PosRef
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual bool IsActorLike();
    virtual void vr104();
    virtual void vr108();
    virtual void vr10c();
    virtual void vr110();
    virtual void vr114();
    virtual void vr118();
    virtual void vr11c();
    virtual void vr120();
    virtual void vr124();
    virtual void vr128();
    virtual void vr12c();
    virtual void vr130();
    virtual void vr134();
    virtual void vr138();
    virtual void vr13c();
    virtual void vr140();
    virtual void vr144();
    virtual void vr148();
    virtual void vr14c();
    virtual void vr150();
    virtual void vr154();
    virtual void vr158();
    virtual void vr15c();
    virtual void vr160();
    virtual void vr164();
    virtual void vr168();
    virtual void vr16c();
    virtual void vr170();
    virtual void vr174();
    virtual void vr178();
    virtual void vr17c();
    virtual void vr180();
    virtual void vr184();
    virtual void vr188();
    virtual void vr18c();
    virtual void vr190();
    virtual void vr194();
    virtual void vr198();
    virtual void vr19c();
    virtual void vr1a0();
    virtual void vr1a4();
    virtual void vr1a8();
    virtual void vr1ac();
    virtual void vr1b0();
    virtual void vr1b4();
    virtual void vr1b8();
    virtual void vr1bc();
    virtual void vr1c0();
    virtual void vr1c4();
    virtual void vr1c8();
    virtual void vr1cc();
    virtual void vr1d0();
    virtual void vr1d4();
    virtual void vr1d8();
    virtual void vr1dc();
    virtual void vr1e0();
    virtual void vr1e4();
    virtual void vr1e8();
    virtual void vr1ec();
    virtual void vr1f0();
    virtual NiPoint3* GetPosPtr();
    ProcHolder* FUN_005d43c0();
    NiPoint3* FUN_0056add0();
    PkgForm* FUN_009344a0();
};

class PkgOwner
{
  public:
    virtual void vo000();
    virtual void vo004();
    virtual void vo008();
    virtual void vo00c();
    virtual void vo010();
    virtual void vo014();
    virtual void vo018();
    virtual void vo01c();
    virtual void vo020();
    virtual void vo024();
    virtual void vo028();
    virtual void vo02c();
    virtual void vo030();
    virtual void vo034();
    virtual void vo038();
    virtual void vo03c();
    virtual void vo040();
    virtual void vo044();
    virtual void vo048();
    virtual void vo04c();
    virtual void vo050();
    virtual void vo054();
    virtual void vo058();
    virtual void vo05c();
    virtual void vo060();
    virtual void vo064();
    virtual void vo068();
    virtual void vo06c();
    virtual void vo070();
    virtual void vo074();
    virtual void vo078();
    virtual void vo07c();
    virtual void vo080();
    virtual void vo084();
    virtual void vo088();
    virtual void vo08c();
    virtual void vo090();
    virtual void vo094();
    virtual void vo098();
    virtual void vo09c();
    virtual void vo0a0();
    virtual void vo0a4();
    virtual void vo0a8();
    virtual void vo0ac();
    virtual void vo0b0();
    virtual void vo0b4();
    virtual void vo0b8();
    virtual void vo0bc();
    virtual void vo0c0();
    virtual void vo0c4();
    virtual void vo0c8();
    virtual void vo0cc();
    virtual void vo0d0();
    virtual void vo0d4();
    virtual void vo0d8();
    virtual void vo0dc();
    virtual void vo0e0();
    virtual void vo0e4();
    virtual void vo0e8();
    virtual void vo0ec();
    virtual void vo0f0();
    virtual void vo0f4();
    virtual void vo0f8();
    virtual void vo0fc();
    virtual void vo100();
    virtual void vo104();
    virtual void vo108();
    virtual void vo10c();
    virtual void vo110();
    virtual void vo114();
    virtual void vo118();
    virtual void vo11c();
    virtual void vo120();
    virtual void vo124();
    virtual void vo128();
    virtual void vo12c();
    virtual void vo130();
    virtual void vo134();
    virtual void vo138();
    virtual void vo13c();
    virtual void vo140();
    virtual void vo144();
    virtual void vo148();
    virtual void vo14c();
    virtual void vo150();
    virtual void vo154();
    virtual void vo158();
    virtual void vo15c();
    virtual void vo160();
    virtual void vo164();
    virtual void vo168();
    virtual void vo16c();
    virtual void vo170();
    virtual void vo174();
    virtual void vo178();
    virtual void vo17c();
    virtual void vo180();
    virtual void vo184();
    virtual void vo188();
    virtual void vo18c();
    virtual void vo190();
    virtual void vo194();
    virtual void vo198();
    virtual void vo19c();
    virtual void vo1a0();
    virtual void vo1a4();
    virtual void vo1a8();
    virtual void vo1ac();
    virtual void vo1b0();
    virtual void vo1b4();
    virtual void vo1b8();
    virtual void vo1bc();
    virtual void vo1c0();
    virtual void vo1c4();
    virtual void vo1c8();
    virtual void vo1cc();
    virtual void vo1d0();
    virtual void vo1d4();
    virtual void vo1d8();
    virtual void vo1dc();
    virtual void vo1e0();
    virtual void vo1e4();
    virtual void vo1e8();
    virtual void vo1ec();
    virtual void vo1f0();
    virtual void vo1f4();
    virtual void vo1f8();
    virtual void vo1fc();
    virtual void vo200();
    virtual void vo204();
    virtual void vo208();
    virtual void vo20c();
    virtual void vo210();
    virtual void vo214();
    virtual void vo218();
    virtual void vo21c();
    virtual void vo220();
    virtual void vo224();
    virtual void vo228();
    virtual PkgForm* GetPkgForm();
    virtual void vo230();
    virtual void vo234();
    virtual void vo238();
    virtual void vo23c();
    virtual void vo240();
    virtual void vo244();
    virtual void vo248();
    virtual void vo24c();
    virtual void vo250();
    virtual void vo254();
    virtual void vo258();
    virtual void vo25c();
    virtual void vo260();
    virtual void vo264();
    virtual void vo268();
    virtual void vo26c();
    virtual void vo270();
    virtual void vo274();
    virtual void vo278();
    virtual void vo27c();
    virtual int GetPkgIndex();
    PosRef* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    PosRef* m_40;
    NiPoint3 FUN_0090ec70(PosRef* target, bool skip);
};

extern NiPoint3 DAT_011f426c;

// Returns a position selected from the target, a referenced object, or package-related data.
// @fnv 0x0090ec70
NiPoint3 PkgOwner::FUN_0090ec70(PosRef* target, bool skip)
{
    NiPoint3 result5 = DAT_011f426c;
    PkgForm* form4 = GetPkgForm();
    PosRef* ref = m_40;
    int index = GetPkgIndex();
    if (!skip && form4 && form4->FUN_00678610())
    {
        form4 = target->FUN_005d43c0()->FUN_0041cb10();
        index = target->FUN_005d43c0()->FUN_0041cb40();
        ref = target->FUN_005d43c0()->FUN_0041cb70();
    }
    if (!form4)
        return result5;
    if (form4->FUN_009611e0() == -1)
        return result5;
    switch (DAT_011a3ff0[form4->FUN_009611e0()][index])
    {
    case 27:
        result5 = *target->GetPosPtr();
        if (ref && ref->IsActorLike())
        {
            PosRef* actor = ref;
            PkgForm* sub = actor->FUN_009344a0();
            if (sub)
                result5 = sub->FUN_00675de0(actor);
        }
        break;
    case 1:
    case 2:
    case 3:
    case 6:
    case 8:
    case 9:
    case 13:
    case 14:
    case 15:
    case 28:
    case 30:
    case 38:
    case 42:
    case 44:
        if (ref)
            result5 = *ref->GetPosPtr();
        else
            result5 = *target->GetPosPtr();
        break;
    case 0:
    case 4:
    case 5:
    case 7:
    case 50:
        if (form4->FUN_0055b980())
            result5 = form4->FUN_00675de0(target);
        else
            result5 = *target->GetPosPtr();
        break;
    case 47:
        if (form4->IsFlag4Clear() && form4->FUN_0055b980())
            result5 = form4->FUN_00675de0(target);
        else if (form4->FUN_00671d10() && form4->FUN_00671d10()->FUN_00680020())
            result5 = *form4->FUN_00671d10()->FUN_00680020()->GetPosPtr();
        else
            result5 = *target->GetPosPtr();
        break;
    case 54:
        if (!skip)
        {
            switch (form4->FUN_0041ca90())
            {
            case 6:
                if (form4->FUN_0055b980())
                    result5 = form4->FUN_00675de0(target);
                else
                    result5 = *target->FUN_0056add0();
                break;
            default:
                if (ref)
                    result5 = *ref->GetPosPtr();
                else
                    result5 = *target->GetPosPtr();
            }
        }
        else
        {
            if (ref)
                result5 = *ref->GetPosPtr();
            else
                result5 = *target->GetPosPtr();
        }
        break;
    }
    return result5;
}

namespace fnv_00911f00 {
struct ProcX
{
    int FUN_0055b980();
    unsigned FUN_00676280(struct TargetX* p);
};
struct ObjX;
struct MgrX
{
    bool FUN_004511e0(ObjX* p, int i);
};
extern MgrX* DAT_011dea10;
struct RefX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc(), v1d0(), v1d4(), v1d8(), v1dc(), v1e0(), v1e4(), v1e8(), v1ec(), v1f0();
    virtual int v1f4();
    ObjX* FUN_008d6f30();
    int FUN_00575d70();
};
struct TargetX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc(), v1d0(), v1d4(), v1d8(), v1dc(), v1e0(), v1e4(), v1e8(), v1ec(), v1f0(),
        v1f4(), v1f8(), v1fc(), v200(), v204(), v208(), v20c(), v210(), v214(), v218(), v21c(), v220(), v224(), v228(),
        v22c(), v230(), v234(), v238(), v23c(), v240(), v244(), v248(), v24c(), v250(), v254(), v258(), v25c(), v260(),
        v264(), v268(), v26c(), v270(), v274(), v278(), v27c(), v280(), v284(), v288(), v28c(), v290(), v294(), v298(),
        v29c(), v2a0(), v2a4();
    virtual void v2a8(int i);
    bool FUN_008b3bb0();
    void DispatchWithObj(RefX* p, float f, int i);
};
void __cdecl FUN_00573800(TargetX* p, ObjX* o, int i);
float __cdecl FUN_00404010(float a, float b);
struct DataX
{
    int m0;
    int m4;
    void FUN_009f3af0(TargetX* p, int i);
    RefX* FUN_0044edb0();
    bool FUN_009f3c10();
};
struct ActorX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc(), v1d0(), v1d4(), v1d8(), v1dc(), v1e0(), v1e4(), v1e8(), v1ec(), v1f0(),
        v1f4(), v1f8(), v1fc(), v200(), v204(), v208(), v20c(), v210(), v214(), v218(), v21c(), v220(), v224(), v228(),
        v22c(), v230(), v234(), v238(), v23c(), v240(), v244(), v248(), v24c(), v250(), v254(), v258(), v25c(), v260(),
        v264(), v268(), v26c(), v270(), v274(), v278();
    virtual ProcX* v27c();
    virtual void v280(), v284();
    virtual void v288(TargetX* p, int i);
    DataX* FUN_008d0430();
    void DispatchToTarget(TargetX* pkTarget);
};
// Dispatches to pkTarget based on pkData->m4 state, updating refs and calling DispatchWithObj or FUN_00573800 as needed.
// @fnv 0x00911f00
void ActorX::DispatchToTarget(TargetX* pkTarget)
{
    DataX* pkData = FUN_008d0430();
    if (!pkData)
    {
        v288(pkTarget, 1);
        return;
    }
    switch (pkData->m4)
    {
    case 0: {
        ProcX* pkProc8 = v27c();
        pkData->m4 = 2;
        pkData->FUN_009f3af0(pkTarget, pkProc8->FUN_0055b980());
        break;
    }
    case 1:
    case 2:
        pkData->m4 = 3;
    case 3:
        if (pkTarget->FUN_008b3bb0())
        {
            RefX* pkOld_2 = pkData->FUN_0044edb0();
            if (pkData->FUN_009f3c10())
            {
                RefX* pkNew = pkData->FUN_0044edb0();
                if (!pkNew || pkNew == pkOld_2)
                    return;
                ObjX* pkOldObj = pkOld_2->FUN_008d6f30();
                ObjX* pkNewObj4 = pkNew->FUN_008d6f30();
                bool bFree7 = !((pkOldObj && DAT_011dea10->FUN_004511e0(pkOldObj, 0)) ||
                                (pkNewObj4 && DAT_011dea10->FUN_004511e0(pkNewObj4, 0)));
                bool bSameB = pkOldObj && pkOldObj == pkNewObj4;
                if (bFree7)
                {
                    if (bSameB)
                    {
                        pkTarget->v2a8(pkNew->v1f4());
                    }
                    else
                    {
                        pkTarget->v2a8(pkNew->v1f4());
                        FUN_00573800(pkTarget, pkNewObj4, pkNew->FUN_00575d70());
                    }
                }
                else
                {
                    float fTimeB = (float)v27c()->FUN_00676280(pkTarget);
                    fTimeB = FUN_00404010(fTimeB, 10.0f);
                    pkTarget->DispatchWithObj(pkNew, fTimeB, 0);
                }
            }
        }
        break;
    }
}
}  // namespace fnv_00911f00

// @fnv 0x00910b10
void TimeoutTimer::FUN_00910b10()
{
    m_fTimeout = 0.0f;
}
