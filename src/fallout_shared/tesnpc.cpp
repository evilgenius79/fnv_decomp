// fallout_shared/tesnpc.cpp: TESNPC, ActorValue, TESActorBaseData, FR2MatrixVTCData and more (114 functions)

#include "tesnpc_pc_decls.h"

// @fnv 0x00601170
TESNPC::TESNPC() : m_pkPrimaryFaceGenNode(0), m_pkSecondaryFaceGenNode(0), m_pkFaceGenTexture(0), undoStates(0, true)
{
    SetFormType(ENUM_FORM_ID_NPC__ID);
    ResetFormData();
    TESAIForm::FUN_0047ef50(50, false);
    TESAIForm::FUN_0047ee00(0, false);
    TESAIForm::FUN_0047eed0(2, false);
    TESAIForm::FUN_0047ef00(50, false);
    m_ulTopicFlags = 0;
}

// @fnv 0x00601570
void TESNPC::ResetFormData()
{
    fWeight = 0.0f;
    m_fGlyphExtent = 0.0f;
    m_pHair = 0;
    m_fHairLength = 0.0f;
    m_pEyes = 0;
    if (!g_TESSaveLoadGame->GetLoading())
    {
        m_pkPrimaryFaceGenNode = m_pkSecondaryFaceGenNode = 0;
        m_pkFaceGenTexture = 0;
    }
    m_usLastRace = 255;
    m_pClass = 0;
    m_pCombatStyle = 0;
    iHairColor = 0x19324b;
    m_pOffsetFaceCoordinates = 0;
    BSFaceGenManager::CopyFaceGenCoordinates(
        reinterpret_cast<FaceGenMatrix<float>(*)[2]>(BSFaceGenManager::GetFaceGenCoordinates()), GetOffsetFaceCoord(),
        0, 0);
    for (int r = 0; r < 2; ++r)
        for (int c = 0; c < 2; ++c)
            if (m_kFaceGenCoordinates[r][c].FUN_009611e0())
                m_kFaceGenCoordinates[r][c].FUN_0060b3b0();
    for (int i = 0; i < 14; ++i)
    {
        data.skills[i] = 5;
        data.skillOffsets[i] = 0;
    }
    m_eImpactMaterial = 6;
    m_pAssignedRace = 0;
    m_pTemplateNPC = 0;
    TESActorBaseData::UpdateFlagBit(1, false);
    TESHealthForm::FUN_006ecd40(50);
}

// @fnv 0x00601750
void TESNPC::ClearData()
{
    if (!g_TESSaveLoadGame->GetLoading())
    {
        m_pkSecondaryFaceGenNode = m_pkPrimaryFaceGenNode = 0;
        m_pkFaceGenTexture = 0;
    }
    m_usLastRace = 255;
    m_kHeadPartList.RemoveAll();
    delete[] m_pOffsetFaceCoordinates;
    m_pOffsetFaceCoordinates = 0;
}

// @fnv 0x00602190
bool TESNPC::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 42)
        return false;
    m_ulTopicFlags = static_cast<TESNPCFileAccess*>(file)->GetOffset();
    LoadRecordHeader(file);
    SetInitializationState(false);
    bool validRecord;
    bool bTextureWarning = false;
    while (int chunk = file->GetChunkID())
    {
        bool chunkAdvanced;
        {
            struct FaceCoordReadCursor
            {
                int column, row;
                float* values;
            } cursor;
            cursor.row = -1;
            cursor.column = -1;
            validRecord = true;
            chunkAdvanced = false;
            switch (chunk)
            {
            case 'DIDE': {
                char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
                file->GetChunkData(editorID, 512);
                SetEditorID_AtRuntime(editorID);
                break;
            }
            case 'DNBO':
                readOBNDSubRecord(file);
                break;
            case 'LLUF':
                TESFullNameLoader::LoadFullNameChunk(static_cast<TESFullName*>(this), file);
                break;
            case 'LDOM':
            case 'TDOM':
                TESModel::LoadModelData(static_cast<TESModel*>(this), file);
                break;
            case 'IRCS': {
                unsigned int scriptID = 0;
                file->GetChunkData(&scriptID);
                TESScriptableForm::Initialize(scriptID);
                TESScriptableForm::InitItem(this);
                break;
            }
            case 'OTNC':
            case 'DEOC':
                switch (file->GetChunkID())
                {
                case 'OTNC': {
                    ContainerItem item;
                    memset(&item, 0, 8);
                    file->GetChunkData(&item, 8);
                    if (file->IsEndianConversionRequired())
                        item.FUN_00462230();
                    DAT_011cb7d8 = TESContainer::AddContainerObject(&item);
                    break;
                }
                case 'DEOC':
                    if (DAT_011cb7d8)
                    {
                        DAT_011cb7d8->pExtra = new ContainerItemExtra;
                        DAT_011cb7d8->pExtra->Load(file);
                        DAT_011cb7d8 = 0;
                    }
                    break;
                }
                break;
            case 'OLPS': {
                unsigned int spell = 0;
                file->GetChunkData(&spell);
                TESSpellList::FUN_0048d290(spell);
                break;
            }
            case 'MTIE': {
                unsigned int spell = 0;
                file->GetChunkData(&spell);
                BGSTouchSpellForm::Initialize(spell);
                break;
            }
            case 'TMAE': {
                unsigned short value = 0;
                static_cast<TESFileChunkData16*>(file)->GetChunkData(&value);
                BGSTouchSpellForm::FUN_00483170(value);
                break;
            }
            case 'TDIA': {
                PackedRecordData ai;
                memset(&ai, 0, 20);
                file->GetChunkData(&ai, 20);
                if (file->IsEndianConversionRequired())
                    ai.SwapEndianFields();
                if (static_cast<TESFileFormVersion*>(file)->GetFormVersion() < 4 && ai.m_ucField00 > 1)
                    ++ai.m_ucField00;
                if (static_cast<TESFileFormVersion*>(file)->GetFormVersion() < 6)
                    switch (ai.m_ucField00)
                    {
                    case 0:
                        ai.m_ucField0E = 0;
                        break;
                    case 1:
                        ai.m_ucField00 = 0;
                        ai.m_ucField0E = 1;
                        break;
                    case 2:
                        ai.m_ucField00 = 1;
                        ai.m_ucField0E = 1;
                        break;
                    case 3:
                        ai.m_ucField00 = 1;
                        ai.m_ucField0E = 2;
                        break;
                    case 4:
                        ai.m_ucField00 = 2;
                        ai.m_ucField0E = 2;
                        break;
                    case 5:
                        ai.m_ucField00 = 3;
                        ai.m_ucField0E = 0;
                        break;
                    }
                if (static_cast<TESFileFormVersion*>(file)->GetFormVersion() < 7)
                    ai.m_ucField01 = 4 - ai.m_ucField01;
                TESAIForm::FUN_0047f0b0(&ai);
                break;
            }
            case 'DIKP': {
                unsigned int package = 0;
                file->GetChunkData(&package);
                TESAIForm::FUN_0047f500(package);
                break;
            }
            case 'MANS': {
                FactionReaction rank;
                memset(&rank, 0, 8);
                file->GetChunkData(&rank, 8);
                if (file->IsEndianConversionRequired())
                    rank.Endian();
                SetFactionRank(rank.pFaction, rank.m_ucRank);
                break;
            }
            case 'MANI': {
                unsigned int deathItem = 0;
                file->GetChunkData(&deathItem);
                m_pBaseTemplateForm = reinterpret_cast<TESForm*>(deathItem);
                break;
            }
            case 'KCTV': {
                unsigned int voice;
                file->GetChunkData(&voice);
                m_kFactionList = reinterpret_cast<TESForm*>(voice);
                break;
            }
            case 'TLPT': {
                unsigned int templateID;
                file->GetChunkData(&templateID);
                m_ppTemplateForms = reinterpret_cast<TESForm*>(templateID);
                break;
            }
            case 'SBCA':
                file->GetChunkData(&actorData, 24);
                if (file->IsEndianConversionRequired())
                    actorData.SwapEndianness();
                if (static_cast<TESFileFormVersion*>(file)->GetFormVersion() < 8)
                    actorData.m_usField16 = 0;
                actorData.m_usField06 = 0;
                break;
            case 'MANR': {
                unsigned int race = 0;
                file->GetChunkData(&race);
                TESRaceForm::Initialize(race);
                break;
            }
            case 'ZFFK':
                TESAnimation::BaseFormRecord(static_cast<TESAnimation*>(this), file);
                break;
            case 'TSED':
            case 'DTSD':
                BGSDestructibleObjectForm::LoadDestructibleData(static_cast<BGSDestructibleObjectForm*>(this), file);
                break;
            case 'ATAD': {
                unsigned int added = file->GetChunkSize() - GetDataSizeAdjustment();
                if (added)
                {
                    if (added != 28 && added * 2 != 28)
                        Warning("NPC '%s' (%08X) has invalid data format.", GetName(), GetFormID());
                    ReadTypedData(file, &data, (unsigned short)added);
                }
                else
                    ReadTypedData(file, 0, 0);
                break;
            }
            case 'MAND':
                file->GetChunkData(&data, 28);
                break;
            case 'SGGF':
                if (cursor.row == -1)
                {
                    cursor.row = 0;
                    cursor.column = 0;
                }
            case 'AGGF':
                if (cursor.row == -1)
                {
                    cursor.row = 0;
                    cursor.column = 1;
                }
            case 'STGF': {
                if (cursor.row == -1)
                {
                    cursor.row = 1;
                    cursor.column = 0;
                }
                struct FaceCoordReadCounts
                {
                    unsigned int floatCount, byteCount;
                } counts;
                counts.byteCount = file->GetChunkSize();
                counts.floatCount = counts.byteCount >> 2;
                m_kFaceGenCoordinates[cursor.row][cursor.column].SetDimensions(counts.floatCount, 1);
                cursor.values = static_cast<float*>(_alloca(counts.byteCount));
                memset(cursor.values, 0, counts.byteCount);
                file->GetChunkData(cursor.values, counts.byteCount);
                for (unsigned int index = 0; index < counts.floatCount; ++index)
                {
                    if (file->IsEndianConversionRequired())
                        BSEndian(&cursor.values[index], EndianSizeTag<4>());
                    *const_cast<float*>(
                        m_kFaceGenCoordinates[cursor.row][cursor.column].FUN_0060b370(index, 0).FUN_00629ab0()) =
                        cursor.values[index];
                }
                break;
            }
            case 'MANP': {
                struct FormResolution
                {
                    unsigned int formID;
                    BGSHeadPart* part;
                } resolved;
                file->GetChunkData(&resolved.formID);
                RemapFormIDForFile(resolved.formID, file);
                resolved.part = dynamic_cast<BGSHeadPart*>(TESForm::GetFormByID(resolved.formID));
                if (resolved.part)
                    FUN_00602170()->AddHead(resolved.part);
                else
                    Warning("MASTERFILE: Could not find headpart (%08X) on NPC '%s' (%08X).", resolved.formID,
                            GetName(), GetFormID());
                break;
            }
            case 'MANH': {
                struct FormResolution
                {
                    unsigned int formID;
                    TESHair* hair;
                } resolved;
                file->GetChunkData(&resolved.formID);
                RemapFormIDForFile(resolved.formID, file);
                resolved.hair = dynamic_cast<TESHair*>(TESForm::GetFormByID(resolved.formID));
                if (resolved.hair)
                    SetHair(resolved.hair);
                else
                    Warning("MASTERFILE: Could not find hair (%08X) on NPC '%s' (%08X).", resolved.formID, GetName(),
                            GetFormID());
                break;
            }
            case 'MANL': {
                float length;
                file->GetChunkData(reinterpret_cast<unsigned int*>(&length));
                if (length < 0.0)
                    length = 0.0f;
                if (length > 1.0)
                    length = 1.0f;
                FUN_00601c10(length);
                break;
            }
            case 'MANE': {
                struct FormResolution
                {
                    unsigned int formID;
                    TESEyes* eyes;
                } resolved;
                file->GetChunkData(&resolved.formID);
                RemapFormIDForFile(resolved.formID, file);
                resolved.eyes = dynamic_cast<TESEyes*>(TESForm::GetFormByID(resolved.formID));
                if (resolved.eyes)
                    SetEyes(resolved.eyes);
                else
                    Warning("MASTERFILE: Could not find eyes (%08X) on NPC '%s' (%08X).", resolved.formID, GetName(),
                            GetFormID());
                break;
            }
            case 'RLCH':
            case '9MAN':
                file->GetChunkData(&iHairColor);
                break;
            case 'MANC': {
                unsigned int classID = 0;
                file->GetChunkData(&classID);
                m_pClass = reinterpret_cast<TESClass*>(classID);
                break;
            }
            case 'MANZ': {
                unsigned int combatStyle;
                file->GetChunkData(&combatStyle);
                SetCombatStyle(reinterpret_cast<TESCombatStyle*>(combatStyle));
                break;
            }
            case 'MANF':
                if (file->GetChunkSize() >= 2)
                {
                    static_cast<TESFileChunkData16*>(file)->GetChunkData(&m_usLastRace);
                    if (file->IsEndianConversionRequired())
                        BSEndian(&m_usLastRace, EndianSizeTag<2>());
                }
                break;
            case '0MAN':
            case '1MAN':
            case '2MAN':
            case '3MAN':
                if (!bTextureWarning)
                {
                    Warning("MASTERFILE: Found face texture for NPC '%s' (%08X) in file '%s'", GetName(), GetFormID(),
                            static_cast<TESNPCFileAccess*>(file)->GetFilename());
                    bTextureWarning = true;
                }
                break;
            case '4MAN': {
                unsigned int race;
                file->GetChunkData(&race);
                m_eImpactMaterial = (int)race;
                break;
            }
            case '6MAN':
                file->GetChunkData(reinterpret_cast<unsigned int*>(&m_fGlyphExtent));
                break;
            case '7MAN':
                file->GetChunkData(reinterpret_cast<unsigned int*>(&fWeight));
                break;
            default:
                break;
            }
            if (!validRecord)
                break;
            if (!chunkAdvanced && !file->NextChunk())
                break;
        }
    }
    if (GetFormID() == 7 && g_thePlayer && !g_thePlayer->GetObjectReference())
        g_thePlayer->ClearReferenceState(this);
    if (!TESActorBaseData::GetShortAtOffset12())
        Warning("MASTERFILE: Speed multiplier is zero on NPC '%s' (%08X).", GetName(), GetFormID());
    return true;
}

// @fnv 0x00603370
void TESNPC::InitItem()
{
    unsigned int classID, combatID;
    if (IsFormInitialized())
        return;
    if (TESActorBaseData::GetFlag(4))
    {
        TESNPC* npc = this;
        DAT_011cb764.AddHead(npc);
    }
    TESScriptableForm::InitItem(this);
    TESContainer::InitItem(this);
    TESAIForm::InitItem(this);
    TESRaceForm::InitItem(this);
    TESActorBaseData::InitItem(this);
    TESSpellList::InitItem(this);
    BGSTouchSpellForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    if (m_pClass)
    {
        classID = reinterpret_cast<unsigned int>(m_pClass);
        RemapFormIDForFile(classID, GetFile(-1));
        m_pClass = dynamic_cast<TESClass*>(TESForm::GetFormByID(classID));
    }
    if (vfn_144())
        UpdateActorBaseData(false);
    if (m_pCombatStyle)
    {
        combatID = reinterpret_cast<unsigned int>(GetCombatStyle());
        if (combatID)
        {
            RemapFormIDForFile(combatID, GetFile(-1));
            m_pCombatStyle = dynamic_cast<TESCombatStyle*>(TESForm::GetFormByID(combatID));
            if (!m_pCombatStyle)
                Warning("MASTERFILE: Combat Style (%08X) not found in InitItem for NPC (%08X) '%s'.", combatID,
                        GetFormID(), GetName());
        }
    }
    if (!GetCombatStyle())
        SetCombatStyle(FUN_00505000());
    if (TESHealthForm::FUN_00726070() <= 0)
        SetEssentialState(true);
    if (m_fGlyphExtent == 0.0)
        m_fGlyphExtent = GetDefaultHeight();
    SetInitializationState(true);
}

// @fnv 0x006035e0
void TESNPC::Copy(TESForm* form)
{
    if (form->GetFormType() != ENUM_FORM_ID_NPC__ID)
        return;
    TESNPC* npc = static_cast<TESNPC*>(form);
    TESAIForm::BaseFormRecord(form);
    TESSpellList::BaseFormRecord(form);
    BGSTouchSpellForm::BaseFormRecord(form);
    TESRaceForm::BaseFormRecord(form);
    TESActorBaseData::BaseFormRecord(form);
    TESHealthForm::BaseFormRecord(form);
    TESAttributes::BaseFormRecord(form);
    TESFullName::BaseFormRecord(form);
    TESModel::BaseFormRecord(form);
    TESScriptableForm::BaseFormRecord(form);
    TESContainer::BaseFormRecord(form);
    TESAnimation::BaseFormRecord(form);
    BGSDestructibleObjectForm::BaseFormRecord(form);
    memcpy(&data, npc->GetTextureManager(), 28);
    m_pClass = npc->GetClass();
    SetCombatStyle(npc->GetCombatStyle());
    vfn_5c(npc->vfn_58());
    CopyActorBaseData(npc);
    m_fGlyphExtent = npc->m_fGlyphExtent;
    fWeight = npc->fWeight;
}

// @fnv 0x00603790
void TESNPC::CopyActorBaseData(TESNPC* source)
{
    FUN_00602170()->RemoveAll();
    m_pHair = source->GetHair();
    m_fHairLength = source->FUN_00602130();
    m_pEyes = source->FUN_00602150();
    iHairColor = source->FUN_004169d0();
    BSSimpleList<BGSHeadPart*>* node = source->FUN_00602170();
    while (node && !node->IsEmpty())
    {
        FUN_00602170()->AddTail(node->GetItem());
        node = node->GetNext();
    }
    BSFaceGenManager::CopyFaceGenCoordinates(source->GetOffsetFaceCoord(), GetOffsetFaceCoord(), 0, 0);
    if (!g_thePlayer || this != g_thePlayer->GetObjectReference())
        SetField1F0(source);
}

// Fills coords with the mean face coordinates for the NPC's race and sex, or with the default face coordinates when no race is set.
// @fnv 0x00603ad0
void TESNPC::GetFaceGenCoords(FaceGenMatrix<float> (&coords)[2][2])
{
    BSFaceGenManager::InitializeFaceGenCoordinates(coords);
    if (!GetFormRace())
        BSFaceGenManager::CopyFaceGenCoordinates(
            reinterpret_cast<FaceGenMatrix<float>(*)[2]>(BSFaceGenManager::GetFaceGenCoordinates()), coords, 0, 0);
    else
        BSFaceGenManager::BlendFaceGenCoordinates(GetFormRace()->GetMeanFaceCoord(GetSex()), GetOffsetFaceCoord(),
                                                  coords, false, 0.0f);
}

// Returns the NPC's hair form, using the race's hair for the current sex unless this is the player's object reference.
// @fnv 0x00603b50
TESHair* TESNPC::GetHair()
{
    TESHair* hair = m_pHair;
    if (m_pAssignedRace && this != g_thePlayer->GetObjectReference())
        hair = GetFormRace()->FUN_00613870(GetSex());
    return hair;
}

// @fnv 0x00603be0
void TESNPC::UpdateActorBaseData(bool menu)
{
    float fValue = 0.0f;
    if (!TESRaceForm::GetFormRace() || !m_pClass)
        return;
    bool m_bFaceGenDataValid = false;
    if (GetFormID() == 7)
        m_bFaceGenDataValid = true;
    bool bUseDefaults = true;
    if (m_bFaceGenDataValid && DAT_011d0e7c.Int()->i == GetClass()->GetFormID())
        bUseDefaults = false;
    if (vfn_144())
    {
        int iLevel;
        {
            unsigned char luck;
            {
                struct SkillInitializationBudget
                {
                    float fPointsPerSkill;
                    int iSkillPoints;
                    int iRemainingTagSkills;
                    float overflow;
                } budget;
                for (int iIndex = 0; iIndex < 7; ++iIndex)
                {
                    ActorValue::Index eAttribute =
                        ActorValue::GetActorValueForSectionIndex(ActorValue::Attributes, (unsigned char)iIndex);
                    if (bUseDefaults)
                        fValue = GetClass()->classAttributes.GetAttributeValue(iIndex + 5);
                    if (fValue > 10.0)
                        fValue = 10.0f;
                    TESAttributes::SetAttributeValue(eAttribute, (unsigned char)TruncateFloatToInt(fValue), false);
                }
                luck = TESAttributes::GetAttributeValue(11);
                budget.iSkillPoints = ComputeIntelligenceResult(TESAttributes::GetAttributeValue(9), true);
                iLevel = TESActorBaseData::FUN_0047ded0();
                budget.iSkillPoints = (iLevel - 1) * budget.iSkillPoints;
                budget.iRemainingTagSkills = (menu ? 1 : 0) + 3;
                budget.fPointsPerSkill =
                    FUN_00404040((float)budget.iSkillPoints / budget.iRemainingTagSkills) * DAT_011cd6c0.Int()->i;
                budget.overflow = 0.0f;
                --budget.iRemainingTagSkills;
                for (int iIndex = 0; iIndex < 14; ++iIndex)
                {
                    ActorValue::Index eAttribute =
                        ActorValue::GetActorValueForSectionIndex(ActorValue::Skills, (unsigned char)iIndex);
                    if (!ActorValue::GetFlag(eAttribute, 0x2000) && ActorValue::IsSkill(eAttribute))
                    {
                        fValue = 0.0f;
                        int iAttribute = -1;
                        GetSkillAttributeAndBase(eAttribute, &iAttribute, &fValue);
                        fValue =
                            AIFormulas::CalculateSkillValue(fValue, (float)attributes[iAttribute - 5], (float)luck);
                        if (bUseDefaults && m_pClass && m_pClass->IsTagSkill(eAttribute))
                        {
                            fValue = fValue + (budget.fPointsPerSkill + budget.overflow +
                                               originalRuntimeFloatSetting327.Float()->f);
                            budget.overflow = 0.0f;
                            if (fValue > 100.0)
                            {
                                budget.overflow = (float)(fValue - 100.0);
                                if (budget.iRemainingTagSkills)
                                    budget.overflow /= budget.iRemainingTagSkills;
                            }
                            --budget.iRemainingTagSkills;
                        }
                        if (fValue > 100.0)
                            fValue = 100.0f;
                        data.skills[iIndex] = (unsigned char)TruncateFloatToInt(fValue);
                    }
                }
                if (m_pClass)
                {
                    if (vfn_30())
                        TESAIForm::SetServiceFlags(m_pClass->FUN_006286d0(), false);
                }
                else
                    TESAIForm::SetServiceFlags(0, false);
                MarkAsModified(0x20c);
            }
        }
    }
}

// @fnv 0x006041d0
float TESNPC::GetDefaultHeight()
{
    if (reinterpret_cast<TESHairCanBeNPCData*>(this)->FUN_004ac110())
        return reinterpret_cast<TESHairCanBeNPCData*>(this)->FUN_004ac110()->FUN_00604210(GetSex());
    return 0.0f;
}

// Removes worn items, equips best armor and weapon for the given refr, and updates the actor's process state.
// @fnv 0x006047c0
void TESNPC::UpdateModel3D(TESObjectREFR* refr, bool armor, bool weapon, bool update, bool allowChanges)
{
    struct DefaultEquipmentState
    {
        InventoryStackRecord* pArmorItem;
        ExtraDataList* pExtraData;
        Actor* pActorRefr;
        TESBipedModelForm* pBodyModel;
    } equipment;
    bool bPreviousChanges = true;
    if (!allowChanges)
        bPreviousChanges = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    if (refr->IsActor())
        refr->FUN_00571b50();
    InventoryChanges* inventory = InventoryChanges::GetOrAddInventoryChanges(refr);
    inventory->RemoveWornItems(true, refr);
    equipment.pActorRefr = static_cast<Actor*>(refr);
    if (equipment.pActorRefr->GetProcess())
    {
        equipment.pActorRefr->GetProcess()->SetCurrentAmmunition(0);
        equipment.pActorRefr->GetProcess()->SetCurrentShield(0);
        equipment.pActorRefr->GetProcess()->SetCurrentTorch(0);
        equipment.pActorRefr->GetProcess()->SetCurrentArmor(0, 0, false);
    }
    equipment.pBodyModel = 0;
    equipment.pExtraData = 0;
    for (int iBipedObject = 0; iBipedObject < 20; ++iBipedObject)
    {
        equipment.pArmorItem = inventory->FindBestArmor(this, iBipedObject, true);
        if (equipment.pArmorItem)
        {
            bool bShouldEquip = true;
            TESBoundObject* pItemObject = equipment.pArmorItem->FUN_0044ddc0();
            if ((!equipment.pBodyModel || !equipment.pBodyModel->HasBipedModel(iBipedObject, false, 0)) &&
                !refr->FUN_00575400(pItemObject))
            {
                if (equipment.pArmorItem->FUN_00559450())
                    equipment.pExtraData = equipment.pArmorItem->FUN_00559450()->GetItem();
                else
                    equipment.pExtraData = 0;
                if (iBipedObject == 2)
                    equipment.pBodyModel = dynamic_cast<TESBipedModelForm*>(pItemObject);
                else
                {
                    TESBipedModelForm* pBipedModel = TESBipedModelForm::GetFormAsBipedModel(pItemObject);
                    if (pBipedModel->HasBipedModel(2, false, 0))
                        bShouldEquip = false;
                }
                if (bShouldEquip)
                    refr->EquipItem(pItemObject, 1, equipment.pExtraData, false);
            }
            delete equipment.pArmorItem;
            equipment.pArmorItem = 0;
        }
    }
    if (weapon && !refr->HasHealth(false))
    {
        float fValue = 0.0f;
        InventoryStackRecord* pArmorItem = inventory->GetBestWeapon(this, &fValue, 6, true);
        if (pArmorItem)
        {
            bool bDeleteItem = true;
            if (!refr->FUN_00575400(pArmorItem->FUN_0044ddc0()))
            {
                ExtraDataList* pExtraData = 0;
                if (pArmorItem->FUN_00559450())
                {
                    pExtraData = pArmorItem->FUN_00559450()->GetItem();
                    bDeleteItem = false;
                }
                else
                    pExtraData = 0;
                Actor* pActorRefr = static_cast<Actor*>(refr);
                pActorRefr->EquipObject(pArmorItem->FUN_0044ddc0(), pArmorItem->FUN_00726070(), pExtraData, true, false,
                                        true);
                if (bDeleteItem)
                    delete pArmorItem;
            }
            else if (static_cast<Actor*>(refr)->GetProcess() &&
                     pArmorItem->FUN_0044ddc0() != static_cast<Actor*>(refr)->GetActiveWeapon())
                static_cast<Actor*>(refr)->GetProcess()->SetCurrentArmor(pArmorItem, refr->GetNiNode(), false);
        }
    }
    if (!allowChanges)
        g_BGSSaveLoadGame->SetThreadAllowChanges(bPreviousChanges);
    if (equipment.pActorRefr->GetProcess())
        equipment.pActorRefr->UpdateSpells(true);
}

// @fnv 0x006055f0
BipedAnim* TESNPC::GetBipedAnimationForReference(TESObjectREFR* refr)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESNPC.cpp", 5585);
    BipedAnim* biped = refr->GetBipedAnim();
    if (biped)
        Warning("ANIMATION: This npc \"%s\" has already been used.\r\nOnly the first reference will be used.\n",
                GetName());
    else
    {
        biped = new BipedAnim(refr, false);
        refr->SetBipedAnim(biped);
    }
    return biped;
}

// @fnv 0x006061b0
bool TESNPC::InitWornObject(TESObjectREFR* refr, BipedAnim* biped, TESBoundObject* object)
{
    bool bReturnValue = true;
    {
        struct BipedModelSources
        {
            BGSBipedModelList* list;
            TESBipedModelForm* model;
        } models;
        models.model = TESBipedModelForm::GetFormAsBipedModel(object);
        if (object->GetFormType() == ENUM_FORM_ID_WEAP_ID)
        {
            TESObjectWEAP* weapon = static_cast<TESObjectWEAP*>(object);
            biped->AddBipedWeapon(weapon, 0);
        }
        else if (models.model)
            models.model->SetBipedModel(biped, (SEX)((actorData.m_uiActorFlags & 1) != 0), -1);
        else
            Warning("MODELS: Bad part '%s' in TESNPC::InitWornObject.", TESFullName::GetFullName(object));
        models.list = BGSBipedModelList::GetBipedModelList(object);
        if (models.list && models.list->GetList())
        {
            BSSimpleList<TESForm*>* node = models.list->GetList()->GetList();
            while (node && !node->IsEmpty())
            {
                TESBoundObject* part = static_cast<TESBoundObject*>(node->GetItem());
                models.model = TESBipedModelForm::GetFormAsBipedModel(part);
                if (models.model)
                    models.model->SetBipedModel(biped, (SEX)((actorData.m_uiActorFlags & 1) != 0), -1);
                node = node->GetNext();
            }
        }
    }
    return bReturnValue;
}

// @fnv 0x006062e0
void TESNPC::AttachHeadParts(TESObjectREFR* refr, NiNode* node)
{
    if (!node)
        node = reinterpret_cast<NiNode*>(refr->Get3DSimple());
    if (!node)
        return;
    struct HeadDisplayContext
    {
        NiAVObject* hair;
        InventoryChanges* inventory;
        InventoryStackRecord* wornItem;
        NiAVObject* biped;
        NiAVObject* skinned;
    } context;
    context.biped = SceneObjectLookup::GetObjectByName(node, "BSFaceGenNiNodeBiped");
    context.skinned = SceneObjectLookup::GetObjectByName(node, "BSFaceGenNiNodeSkinned");
    if (!context.biped || !context.skinned)
        return;
    context.inventory = InventoryChanges::GetOrAddInventoryChanges(refr);
    context.wornItem = context.inventory->GetInventoryEntryData(0, false);
    if (context.wornItem)
    {
        context.biped->FUN_00450f90(true);
        context.skinned->FUN_00450f90(true);
        delete context.wornItem;
        context.wornItem = 0;
        return;
    }
    context.biped->FUN_00450f90(false);
    context.skinned->FUN_00450f90(false);
    context.hair = SceneObjectLookup::GetObjectByName(node, FUN_00605d40(true));
    {
        char hairName[32];
        NiAVObject* hair[2];
        for (int i = 0; i < 2; ++i)
            hair[i] = SceneObjectLookup::GetObjectByName(node, BSFaceGenManager::BuildFaceGenPartPath(hairName, i));
        bool bHairHidden = false;
        bool bHatVisible = true;
        context.wornItem = context.inventory->GetInventoryEntryData(1, false);
        if (context.wornItem)
        {
            delete context.wornItem;
            context.wornItem = 0;
            bHairHidden = true;
        }
        if (hair[1])
        {
            context.wornItem = context.inventory->GetInventoryEntryData(10, false);
            if (context.wornItem)
            {
                delete context.wornItem;
                context.wornItem = 0;
                bHatVisible = false;
                bHairHidden = true;
            }
        }
        if (context.hair)
            context.hair->FUN_00450f90(bHairHidden);
        for (int i = 0; i < 2; ++i)
            if (hair[i])
            {
                if (i == 0)
                    hair[i]->FUN_00450f90(bHairHidden);
                else
                    hair[i]->FUN_00450f90(bHatVisible);
            }
    }
}

// @fnv 0x00606540
void TESNPC::RebuildHeadModel(TESObjectREFR* refr, BipedAnim* biped, bool rebuild)
{
    Actor* pActorRefr;
    {
        bool bFixHead;
        if (biped)
        {
            if (!rebuild)
                for (unsigned int i = 0; i < 20; ++i)
                    if (biped->FUN_00606800()[i].pObject)
                        return;
            biped->UpdateRaceSex(TESRaceForm::GetFormRace(), (SEX)((actorData.m_uiActorFlags & 1) != 0));
        }
        pActorRefr = dynamic_cast<Actor*>(refr);
        if (pActorRefr && pActorRefr->GetProcess())
        {
            bool intact = true;
            ExtraDismemberedLimbs* limbs = pActorRefr->GetExtraData()->GetDismemberedLimbs();
            if (limbs && limbs->parts.GetSize() && limbs->GetInfoAt(0))
            {
                for (unsigned int i = 0; i < limbs->parts.GetSize(); ++i)
                {
                    DismembermentPart* part = limbs->GetInfoAt(i);
                    if (!part->bIsBody && part->bDismembered)
                        intact = false;
                }
            }
            if (intact)
                pActorRefr->GetProcess()->ResetActorModel(1);
        }
        if (!refr->Get3DSimple() || rebuild)
        {
            bool defaults = ShouldUseDefaultAppearance(refr) | rebuild;
            if (this == g_thePlayer->GetObjectReference())
            {
                InventoryChanges* inventory = InventoryChanges::GetOrAddInventoryChanges(refr);
                if (inventory)
                    for (int i = 0; i < 20; ++i)
                    {
                        InventoryStackRecord* item = inventory->GetInventoryEntryData(i, false);
                        if (item)
                        {
                            defaults = false;
                            delete item;
                            item = 0;
                            break;
                        }
                    }
            }
            if (defaults)
            {
                bool bShouldEquipWeapon = true;
                TESPackage* pActorPackage = pActorRefr->GetCurrentPackage();
                if (pActorPackage && pActorPackage->FUN_00441b00())
                    bShouldEquipWeapon = false;
                UpdateModel3D(refr, true, bShouldEquipWeapon, false, false);
            }
        }
        if (!FUN_004abfa0())
            UpdateBodyModel(refr, biped);
        UpdateHeadParts(refr, biped);
        bFixHead = true;
        if (biped == g_thePlayer->GetBipedAnim(true))
            bFixHead = false;
        if (bFixHead)
            AttachHeadParts(refr, 0);
    }
}

// @fnv 0x00607370
void TESNPC::GetFaceGenNodes(BSFaceGenNiNode*& headBiped, BSFaceGenNiNode*& headSkinned)
{
    m_pkPrimaryFaceGenNode = 0;
    m_pkSecondaryFaceGenNode = 0;
    if (!m_pkPrimaryFaceGenNode && !m_pkSecondaryFaceGenNode && GetFormRace())
    {
        GetFormRace()->BuildFaceGenHead(headBiped, headSkinned, this, true, false, (SEX)0);
        m_usLastRace = GetFormRace()->FUN_00607350();
    }
}

// @fnv 0x00607420
void TESNPC::UpdateActorFaceGen(TESObjectREFR* refr, BipedAnim* biped, BSFaceGenNiNode* head, BSFaceGenNiNode* skinned)
{
    BSFaceGenAnimationData* pAnimationData = 0;
    NiNode* pNode;
    {
        NiAVObject* p3D = refr->Get3DSimple();
        pNode = 0;
        if (p3D)
            pNode = p3D->IsSceneNode();
    }
    NiNode* pHeadBone = biped->GetBoneNode(BIPED_BONE_HEAD);
    ThreeByThreeMatrix kRotationBasis;
    NiDefaultAVObjectPalette* pObjectPalette = 0;
    if (refr->GetAnimData() && refr->GetAnimData()->FUN_00496940())
        pObjectPalette =
            reinterpret_cast<NiDefaultAVObjectPalette*>(refr->GetAnimData()->FUN_00496940()->GetStringAtOffset());
    {
        NiDefaultAVObjectPalette* objectPalette = pObjectPalette;
        if (pHeadBone && pNode)
        {
            if (head)
            {
                if (head->GetFaceGenAnimationData() && refr->GetHealth() <= 0.0)
                {
                    head->GetFaceGenAnimationData()->vfn_d8(true, true);
                    head->GetFaceGenAnimationData()->vfn_d0(true);
                }
                head->vfn_114(true);
                head->vfn_11c(true);
                head->FUN_00440460(NiPoint3_ZERO);
                head->SetLocalRotation(reinterpret_cast<const ThreeByThreeMatrix&>(DAT_011a9448));
                pHeadBone->AttachChildInAvailableSlot(head, true);
                AddObjectToPalette(head, objectPalette);
            }
            if (skinned)
            {
                kRotationBasis = reinterpret_cast<const ThreeByThreeMatrix&>(DAT_011a9448);
                skinned->vfn_114(head == 0);
                skinned->vfn_11c(head == 0);
                skinned->FUN_00440460(NiPoint3_ZERO);
                pNode->AttachChildInAvailableSlot(skinned, true);
                AddObjectToPalette(skinned, objectPalette);
                skinned->vfn_128(pNode, true);
            }
            pAnimationData = head ? head->GetFaceGenAnimationData() : 0;
            if (!pAnimationData)
                pAnimationData = skinned ? skinned->GetFaceGenAnimationData() : 0;
            if (pAnimationData)
            {
                pAnimationData->vfn_b4(0.0f, true, true, true, true, false);
                if (refr->IsActor())
                {
                    Actor* pActor = static_cast<Actor*>(refr);
                    if (pActor->pFaceGenAnimationData)
                    {
                        struct AnimationSample
                        {
                            float value, time;
                        } sample;
                        float fDuration;
                        ComputeAngleRange(&sample.value, &sample.time);
                        ClampMinMaxFromSetting(&sample.value, &fDuration);
                        pActor->pFaceGenAnimationData->FUN_00607830(fDuration);
                        pActor->pFaceGenAnimationData->SetBoneMaxAngle(0, sample.time);
                        FUN_00649fe0(&sample.value, &sample.time);
                        GetEyeAngleLimits(&sample.value, &fDuration);
                        pActor->pFaceGenAnimationData->SetSlotFloats(0, sample.time, fDuration);
                    }
                }
            }
            m_pkPrimaryFaceGenNode = head;
            m_pkSecondaryFaceGenNode = skinned;
            pNode->UpdateSceneObject();
            NiUpdateData kUpdateData(0.0f, 0, false);
            pNode->Update(kUpdateData);
        }
        else
            Warning("MODELS: Cannot create a head for an NPC (%d) that does not have a biped-head node.", GetFormID());
    }
    AttachHeadParts(refr, 0);
}

// @fnv 0x00607950
TESCombatStyle* TESNPC::GetCombatStyle()
{
    return m_pCombatStyle;
}

// @fnv 0x00607970
void TESNPC::SetCombatStyle(TESCombatStyle* style)
{
    m_pCombatStyle = style;
}

// @fnv 0x006099f0
void TESNPC::Revert(BGSLoadFormBuffer* buffer)
{
    TESActorBase::Revert(buffer);
    unsigned char modified = 0;
    bool keepHeight = false;
    if (m_fGlyphExtent == GetDefaultHeight())
        keepHeight = true;
    if (buffer->GetOldChangeFlags(0x2000000) && !buffer->GetChangeFlags(0x2000000) && m_pAssignedRace)
    {
        TESRaceForm::SetFormRace(m_pAssignedRace);
        m_pAssignedRace = 0;
        modified |= 0x1b;
    }
    if (keepHeight)
        m_fGlyphExtent = GetDefaultHeight();
    if (buffer->GetOldChangeFlags(0x800) && !buffer->GetChangeFlags(0x800))
    {
        delete[] m_pOffsetFaceCoordinates;
        m_pOffsetFaceCoordinates = 0;
        modified |= 8;
        m_kHeadPartList.RemoveAll();
    }
    if (buffer->GetOldChangeFlags(0x1000000) && !buffer->GetChangeFlags(0x1000000))
    {
        TESActorBaseData::UpdateFlagBit(1, !TESActorBaseData::GetFlag(1), true);
        modified |= 0x1b;
    }
    if (modified & 8)
        ResetFaceGen();
    if (modified)
        FUN_005f20a0(modified);
}

struct FUN_004169d0_shell : public TESNPC
{
    unsigned int FUN_004169d0();
};

// @fnv 0x004169d0
unsigned int FUN_004169d0_shell::FUN_004169d0()
{
    return *(unsigned int*)((char*)this + 0x1d8);
}

struct FUN_004a0c90_shell : public ThreeByThreeMatrix
{
    void FUN_004a0c90(float);
};

void __cdecl FUN_004169a0(float, float&, float&);

// Computes the sine and cosine of the angle and writes a 3x3 rotation matrix about Z into the object's fields.
// @fnv 0x004a0c90
void FUN_004a0c90_shell::FUN_004a0c90(float afAngle)
{
    float fSin, fCos;
    FUN_004169a0(afAngle, fSin, fCos);

    *(float*)((char*)this + 0x00) = fCos;
    *(float*)((char*)this + 0x04) = fSin;
    *(float*)((char*)this + 0x08) = 0.0f;

    *(float*)((char*)this + 0x0c) = -fSin;
    *(float*)((char*)this + 0x10) = fCos;
    *(float*)((char*)this + 0x14) = 0.0f;

    *(float*)((char*)this + 0x18) = 0.0f;
    *(float*)((char*)this + 0x1c) = 0.0f;
    *(float*)((char*)this + 0x20) = 1.0f;
}

struct FUN_00601570_shell : public TESNPC
{
    void ResetCharacterData();
};

struct Calendar_DaysPassed_Helper : public Calendar
{
    unsigned int GetDaysPassed();
};

// Resets face, hair color, skill values and related character fields, clears them when not loading, and reinitializes face coordinates and skills.
// @fnv 0x00601570
void FUN_00601570_shell::ResetCharacterData()
{
    fWeight = 0.0f;
    m_fGlyphExtent = 0.0f;
    m_pHair = 0;
    m_fHairLength = 0.0f;
    m_pEyes = 0;
    if (!g_TESSaveLoadGame->GetLoading())
    {
        m_pkPrimaryFaceGenNode = (m_pkSecondaryFaceGenNode = 0);
        m_pkFaceGenTexture = 0;
    }
    m_usLastRace = 0xff;
    m_pClass = 0;
    m_pCombatStyle = 0;
    iHairColor = 0x19324b;
    m_pOffsetFaceCoordinates = 0;
    BSFaceGenManager::CopyFaceGenCoordinates((FaceGenMatrix<float>(*)[2])BSFaceGenManager::GetFaceGenCoordinates(),
                                             GetOffsetFaceCoord(), false, false);
    for (int etype = 0; etype < 2; ++etype)
    {
        for (int esymm = 0; esymm < 2; ++esymm)
        {
            if (((Calendar_DaysPassed_Helper*)&m_kFaceGenCoordinates[etype][esymm])->GetDaysPassed())
                m_kFaceGenCoordinates[etype][esymm].FUN_0060b3b0();
        }
    }
    for (int iSkillIndex = 0; iSkillIndex < 14; ++iSkillIndex)
    {
        data.skills[iSkillIndex] = 5;
        data.skillOffsets[iSkillIndex] = 0;
    }
    m_eImpactMaterial = 6;
    m_pAssignedRace = 0;
    m_pTemplateNPC = 0;
    UpdateFlagBit(1, false);
    FUN_006ecd40(50);
}

struct FUN_00601800_shell : public TESNPC
{
    void* FUN_00601800();
};

// Returns the pointer stored at offset 0x1b4 if non-null, otherwise returns this plus 0x134.
// @fnv 0x00601800
void* FUN_00601800_shell::FUN_00601800()
{
    if (*(void**)((char*)this + 0x1b4))
    {
        return *(void**)((char*)this + 0x1b4);
    }
    else
    {
        return (char*)this + 0x134;
    }
}

struct FUN_00601c10_shell : public TESNPC
{
    void FUN_00601c10(float);
};

// @fnv 0x00601c10
void FUN_00601c10_shell::FUN_00601c10(float afHairLength)
{
    *(float*)((char*)this + 0x1bc) = afHairLength;
}

struct FUN_00602130_shell : public TESNPC
{
    float FUN_00602130();
};

// @fnv 0x00602130
float FUN_00602130_shell::FUN_00602130()
{
    return *(float*)((char*)this + 0x1bc);
}

struct FUN_00602170_shell : public TESNPC
{
    void* FUN_00602170();
};

// @fnv 0x00602170
void* FUN_00602170_shell::FUN_00602170()
{
    return reinterpret_cast<char*>(this) + 0x1DC;
}

struct FUN_006031e0_shell : public TESNPC
{
    void SetHair(TESHair*);
};

// @fnv 0x006031e0
void FUN_006031e0_shell::SetHair(TESHair* apHair)
{
    *(TESHair**)((char*)this + 0x1b8) = apHair;
}

struct FUN_00603200_shell : public TESNPC
{
    void SetEyes(TESEyes*);
};

// @fnv 0x00603200
void FUN_00603200_shell::SetEyes(TESEyes* apEyes)
{
    *(TESEyes**)((char*)this + 0x1c0) = apEyes;
}

struct FUN_006035e0_shell : public TESNPC
{
    void CopyFromNPC(TESForm*);
};

// Copies an NPC form's components and fields into this actor base after checking the form type is 0x2a.
// @fnv 0x006035e0
void FUN_006035e0_shell::CopyFromNPC(TESForm* apCopy)
{
    if (apCopy->GetFormType() != 0x2a)
        return;

    TESNPC* npc = (TESNPC*)apCopy;

    TESAIForm::BaseFormRecord((BaseFormComponent*)apCopy);
    TESSpellList::BaseFormRecord((BaseFormComponent*)apCopy);
    BGSTouchSpellForm::BaseFormRecord((BaseFormComponent*)apCopy);
    TESRaceForm::BaseFormRecord((BaseFormComponent*)apCopy);
    TESActorBaseData::BaseFormRecord((BaseFormComponent*)apCopy);
    TESHealthForm::BaseFormRecord((BaseFormComponent*)apCopy);
    TESAttributes::BaseFormRecord((BaseFormComponent*)apCopy);
    TESFullName::BaseFormRecord((BaseFormComponent*)apCopy);
    TESModel::BaseFormRecord((BaseFormComponent*)apCopy);
    TESScriptableForm::BaseFormRecord((BaseFormComponent*)apCopy);
    TESContainer::BaseFormRecord((BaseFormComponent*)apCopy);
    TESAnimation::BaseFormRecord((BaseFormComponent*)apCopy);
    BGSDestructibleObjectForm::BaseFormRecord((BaseFormComponent*)apCopy);

    memcpy(&data, npc->GetTextureManager(), sizeof(ActorSkillData));
    m_pClass = npc->GetClass();
    ((TESActorBase*)this)->SetCombatStyle(((TESActorBase*)npc)->GetCombatStyle());
    vfn_5c(npc->vfn_58());
    CopyActorBaseData(npc);
    m_fGlyphExtent = npc->m_fGlyphExtent;
    fWeight = npc->fWeight;
}

struct FUN_00604210_shell : public TESRace
{
    float FUN_00604210(int);
};

// @fnv 0x00604210
float FUN_00604210_shell::FUN_00604210(int aeSex)
{
    return (aeSex >= 0 && aeSex < 2) ? reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x60)[aeSex]
                                     : 0.0f;
}

struct FUN_006044c0_shell : public TESNPC
{
    TESNPC* FUN_006044c0();
};

// @fnv 0x006044c0
TESNPC* FUN_006044c0_shell::FUN_006044c0()
{
    return *(TESNPC**)((char*)this + 0x1f0);
}

struct FUN_006047a0_shell : public PlayerCharacter
{
    bool FUN_006047a0();
};

// @fnv 0x006047a0
bool FUN_006047a0_shell::FUN_006047a0()
{
    return *((bool*)((char*)this + 0x7c5));
}

struct VR_00605d70
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
    virtual BipedAnim* v122();
};
struct VN_00605d70
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
    virtual void* v47();
};
struct PC_00605d70 : PlayerCharacter
{
    bool FUN_004eaf60();
    NiNode* GetNode(bool);
};
struct NN_00605d70 : NiNode
{
    void Update(const NiUpdateData&);
};
void FUN_004ac1e0_x();
struct BA_00605d70
{
    void UpdateBipedObjects(int);
};
struct T_00605d70 : TESNPC
{
    void FUN_00605d70(TESObjectREFR* apRef);
};
// @fnv 0x00605d70
void T_00605d70::FUN_00605d70(TESObjectREFR* apRef)
{
    int iPasses;
    BipedAnim* pbiped;
    NiAVObject* pobj;
    pbiped = ((VR_00605d70*)apRef)->v122();
    pobj = apRef->Get3DSimple();
    iPasses = 1;
    if (apRef == g_thePlayer)
        iPasses = 2;
    while (iPasses != 0)
    {
        if (apRef == g_thePlayer && iPasses == 1)
        {
            pbiped = g_thePlayer->GetBipedAnim(((PC_00605d70*)g_thePlayer)->FUN_004eaf60());
            pobj = ((PC_00605d70*)g_thePlayer)->GetNode(true);
        }
        RebuildHeadModel(apRef, pbiped, false);
        ((BA_00605d70*)pbiped)->UpdateBipedObjects(0);
        if (pobj)
        {
            pobj->UpdateSceneObject();
            ((VN_00605d70*)pobj)->v47();
            NiUpdateData UpdateData(0.0f, false, false);
            ((NN_00605d70*)pobj)->Update(UpdateData);
        }
        iPasses--;
    }
}

struct FUN_00606050_shell : public TESNPC
{
    void InitWornObjects(TESObjectREFR*, BipedAnim*);
};

bool __fastcall FUN_006061b0(TESNPC*, int, TESObjectREFR*, BipedAnim*, TESBoundObject*);

struct FUN_006061b0_caller
{
    bool FUN_006061b0_call(TESObjectREFR*, BipedAnim*, TESBoundObject*);
};

// @fnv 0x00606050
void FUN_00606050_shell::InitWornObjects(TESObjectREFR* apRef, BipedAnim* apBipedAnim)
{
    InventoryChanges* pinv = InventoryChanges::GetOrAddInventoryChanges(apRef);
    InventoryStackRecord* pitem;
    InventoryStackRecord* pshield;
    InventoryStackRecord* ptorch = 0;
    pshield = 0;
    TESBoundObject* pobj;
    Actor* apactor = dynamic_cast<Actor*>(apRef);
    if (!apRef || !apBipedAnim)
        return;

    for (int i = 0; i <= 21; ++i)
    {
        if (i == 3 || i == 5)
        {
            ++i;
        }
        else if (i == 20)
        {
            i = 3;
        }
        else if (i == 21)
        {
            i = 5;
        }

        pitem = pinv->GetInventoryEntryData(i, false);
        if (pitem)
        {
            pobj = pitem->FUN_0044ddc0();
            delete pitem;
            if (pobj)
            {
                if (!((bool(__thiscall*)(TESNPC*, TESObjectREFR*, BipedAnim*, TESBoundObject*))FUN_006061b0)(
                        this, apRef, apBipedAnim, pobj))
                {
                    Warning(
                        "MODELS: Need to add support for BipedObject '%s' object name '%s' in TESNPC::InitWornObject.",
                        DAT_01188b98[i], TESFullName::GetFullName(pobj));
                }
            }
        }

        if (i == 3)
        {
            i = 20;
        }
        else if (i == 5)
        {
            i = 21;
        }
    }
}

struct FUN_006061b0_shell : public TESNPC
{
    bool FUN_006061b0(TESObjectREFR*, BipedAnim*, TESBoundObject*);
};

bool __fastcall _ref_008256d0(BSSimpleList<TESForm*>*);
TESForm** __fastcall _ref_006815c0(BSSimpleList<TESForm*>*);

// Attaches the given object's biped model (or weapon) to the biped anim, then attaches models from the object's race form list.
// @fnv 0x006061b0
bool FUN_006061b0_shell::FUN_006061b0(TESObjectREFR* apRef, BipedAnim* apBipedAnim, TESBoundObject* apObject)
{
    bool bresult = true;
    TESBipedModelForm* pbipedModel = TESBipedModelForm::GetFormAsBipedModel(apObject);
    if (apObject->GetFormType() == 0x28)
    {
        TESObjectWEAP* pweap = reinterpret_cast<TESObjectWEAP*>(apObject);
        apBipedAnim->AddBipedWeapon(pweap, 0);
    }
    else if (pbipedModel)
    {
        pbipedModel->SetBipedModel(
            apBipedAnim,
            static_cast<SEX>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x34) & 1) != 0), -1);
    }
    else
    {
        Warning("MODELS: Bad part '%s' in TESNPC::InitWornObject.", TESFullName::GetFullName(apObject));
    }

    BGSBipedModelList* pformList = BGSBipedModelList::GetBipedModelList(apObject);
    if (pformList && reinterpret_cast<TESRaceForm*>(pformList)->GetFormRace())
    {
        BSSimpleList<TESForm*>* pCurrentElementNext =
            reinterpret_cast<BGSListForm*>(reinterpret_cast<TESRaceForm*>(pformList)->GetFormRace())->GetList();
        while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
        {
            TESForm* plistItem = *_ref_006815c0(pCurrentElementNext);
            pbipedModel = TESBipedModelForm::GetFormAsBipedModel(plistItem);
            if (pbipedModel)
            {
                pbipedModel->SetBipedModel(
                    apBipedAnim,
                    static_cast<SEX>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x34) & 1) != 0),
                    -1);
            }
            pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<TESRaceForm*>(pCurrentElementNext)->GetFormRace());
        }
    }
    return bresult;
}

struct BipedAnimObject;
struct FUN_00606800_shell : public BipedAnim
{
    BipedAnimObject* FUN_00606800();
};

// @fnv 0x00606800
BipedAnimObject* FUN_00606800_shell::FUN_00606800()
{
    return reinterpret_cast<BipedAnimObject*>(reinterpret_cast<char*>(this) + 0x16c);
}

struct FourComponentFloatVector;
struct NiAdditionalGeometryData;
struct NiBound;
struct CloningProcess;
struct RgbaColor;
struct NiCullingProcess;
struct NiGeometryData;
struct NiObject;
struct NiPoint2;
struct NiPropertyState;
struct NiRenderer;
struct NiShader;
struct NiSkinInstance;
struct NiStream;
struct NiGeometry : public NiAVObject
{
    virtual void __vslot_0();
    virtual void RenderImmediate(NiRenderer*);
    virtual void RenderWithRenderer(NiRenderer*);
    virtual void ReplaceModelData(NiGeometryData*);
    virtual void CalculateNormals();
    virtual void CalculateConsistency(bool);
    virtual void* GetRTTI();
    void CopyMemberData(NiGeometry*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    unsigned short GetVertexCount();
    NiPoint3* GetVertices();
    void SetActiveVertexQuantity(unsigned short);
    unsigned short GetActiveVertexQuantity();
    void SetDynamicData(bool);
    NiPoint3* GetNormals();
    int GetNormalBinormalTangentMethod();
    void StoreNormalBinormalTangent(int);
    void SetModelBound(void*);
    NiBound* GetModelBound();
    void CreateColors(bool);
    RgbaColor* GetColors();
    void CreateTextures(bool, unsigned short);
    unsigned short GetTextureSets();
    NiPoint2* GetTextures();
    NiPoint2* GetTextureSet(unsigned short);
    void AppendTextureSet(NiPoint2*);
    NiSkinInstance* GetSkinInstance();
    void SetSkinInstance(NiSkinInstance*);
    NiAdditionalGeometryData* GetAdditionalGeometryData();
    void AssignAdditionalGeometryData(NiAdditionalGeometryData*);
    void SetSortObject(bool);
    bool GetSortObject();
    NiPropertyState* GetPropertyStateP();
    virtual NiGeometry* IsGeometry();
    virtual void SetObjectBound(FourComponentFloatVector*);
    NiShader* GetGeometryShaderObject();
    NiShader* GetShaderFromMaterial();
    void SetShader(NiShader*);
    NiGeometryData* GetModelData();
    bool HasGeometryProperty(int);
    virtual void OnVisible(NiCullingProcess*);
    virtual void ApplyTransform(void*, void*, bool);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    int GetConsistency();
    void SetDataConsistency(int);
    virtual void ProcessClone(CloningProcess*);
    virtual void PostLinkObject(NiStream*);
    virtual void SetSelectiveUpdateFlags(bool*, bool, bool*);
    virtual void PurgeRendererData(NiRenderer*);
    unsigned int QMemContext();
    virtual void UpdateWorldBound();
    void __local_vftable_ctor_closure();
    char _pad_4[188];
    char m_kPropertyState[28];
    char m_spGeometryData[4];
    char m_spSkinningInstance[4];
    NiShader* m_pGeometryShader;
    unsigned int m_uiGeometryShaderFlags;
    char _pad_ec[4];
};
typedef char _sizecheck_NiGeometry[sizeof(NiGeometry) == 240 ? 1 : -1];
struct NiTriBasedGeom : public NiGeometry
{
    virtual void __vslot_0();
    virtual void GetTrianglePoints(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
    virtual void* GetRTTI();
    void CopyMemberData(NiTriBasedGeom*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    virtual void ReplaceModelData(NiGeometryData*);
    unsigned short GetTriangleCount();
    void SetNumberOfVertices(unsigned short);
    unsigned short GetNumberOfVertices();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    void GetTriangleVertexIndices(unsigned short, unsigned short*, unsigned short*, unsigned short*);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_NiTriBasedGeom[sizeof(NiTriBasedGeom) == 240 ? 1 : -1];

class NiExtraData;
class NiFixedString;

const NiFixedString& __cdecl FUN_00607340();

struct NiAVObjectCall : public NiAVObject
{
    NiExtraData* GetExtraData(const NiFixedString&);
};

// Returns the extra data named by FUN_00607340 from apGeom, or null if apGeom is null.
// @fnv 0x00607310
NiExtraData* __cdecl GetGeomExtraData(NiTriBasedGeom* apGeom)
{
    return apGeom ? reinterpret_cast<NiAVObjectCall*>(apGeom)->GetExtraData(FUN_00607340()) : 0;
}

struct FUN_00607350_shell : public TESRace
{
    unsigned short FUN_00607350();
};

// @fnv 0x00607350
unsigned short FUN_00607350_shell::FUN_00607350()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x4f8);
}

struct Dummy_00607810
{
    void SetBoneMaxAngle(int aeBone, float afMaxAngle);
};

struct Elem_00607810
{
    char pad[0x50];
};

struct Layout_00607810
{
    char pad[0xf8];
    Elem_00607810 arr[1];
};

// Stores afMaxAngle into the per-bone entry of the array at offset 0xf8 indexed by aeBone.
// @fnv 0x00607810
void Dummy_00607810::SetBoneMaxAngle(int aeBone, float afMaxAngle)
{
    *(float*)&((Layout_00607810*)this)->arr[aeBone] = afMaxAngle;
}

struct FUN_00607830_helper
{
    char pad[0x1a8];
    float f1A8;
    void set(float afAngle);
};

// @fnv 0x00607830
void FUN_00607830_helper::set(float afAngle)
{
    f1A8 = afAngle;
}

struct FUN_00608d80_shell : public Actor
{
    bool FUN_00608d80();
};

struct GameSettingCollection
{
    TESFile* FUN_004f8960();
};

// @fnv 0x00608d80
bool FUN_00608d80_shell::FUN_00608d80()
{
    return (int)((GameSettingCollection*)this)->FUN_004f8960() == 4 ? true : false;
}

struct FUN_006099f0_shell : public TESNPC
{
    void LoadGamePostProcess(BGSLoadFormBuffer*);
};

// @fnv 0x006099f0
void FUN_006099f0_shell::LoadGamePostProcess(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Revert(apLoadGameBuffer);
    unsigned char cresetFlags = 0;
    bool bfixHeight = false;
    if (m_fGlyphExtent == GetDefaultHeight())
        bfixHeight = true;
    if (apLoadGameBuffer->GetOldChangeFlags(0x2000000) && !apLoadGameBuffer->GetChangeFlags(0x2000000) &&
        m_pAssignedRace)
    {
        TESRaceForm::Initialize(reinterpret_cast<unsigned int>(m_pAssignedRace));
        m_pAssignedRace = 0;
        cresetFlags |= 0x1b;
    }
    if (bfixHeight)
        m_fGlyphExtent = GetDefaultHeight();
    if (apLoadGameBuffer->GetOldChangeFlags(0x800) && !apLoadGameBuffer->GetChangeFlags(0x800))
    {
        delete[] m_pOffsetFaceCoordinates;
        m_pOffsetFaceCoordinates = 0;
        cresetFlags |= 8;
        reinterpret_cast<BSSimpleList<int>*>(&m_kHeadPartList)->RemoveAll();
    }
    if (apLoadGameBuffer->GetOldChangeFlags(0x1000000) && !apLoadGameBuffer->GetChangeFlags(0x1000000))
    {
        UpdateFlagBit(1, !GetFlag(1), true);
        cresetFlags |= 0x1b;
    }
    if (cresetFlags & 8)
        ResetFaceGen();
    if (cresetFlags)
        FUN_005f20a0(cresetFlags);
}

struct S_0060af60
{
    void SetMaskedBits(unsigned short, int, int);
    void FUN_0060af60(unsigned short a);
};
// Calls SetMaskedBits with the given unsigned short, 0xf00 and 8.
// @fnv 0x0060af60
void S_0060af60::FUN_0060af60(unsigned short ausValue)
{
    SetMaskedBits(ausValue, 0xf00, 8);
}

struct FR2MatrixVTCData
{
    void SetElementCount(unsigned int);
    void SetDimensions(int nr, int nc);
};

// @fnv 0x0060b340
void FR2MatrixVTCData::SetDimensions(int aiRows, int aiCols)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = aiRows;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1c) = aiCols;
    SetElementCount(aiRows * aiCols);
}

struct H_0060b3b0
{
    char pad[0x18];
    unsigned int a;
    unsigned int b;
    float* FUN_006578b0(unsigned int) const;
    void FUN_0060b3b0();
};
// Zeroes the buffer returned by FUN_006578b0(0), clearing a*b*4 bytes.
// @fnv 0x0060b3b0
void H_0060b3b0::FUN_0060b3b0()
{
    memset(FUN_006578b0(0), 0, a * b * 4);
}

struct S_0060b3f0
{
    void FUN_0060b410(unsigned int, float);
    void FUN_0060b3f0(unsigned int a);
};
// @fnv 0x0060b3f0
void S_0060b3f0::FUN_0060b3f0(unsigned int auiValue)
{
    FUN_0060b410(auiValue, 0.0f);
}

struct S_0060ba10
{
    char pad[0xa];
    unsigned short s;
    void FUN_0060bd90(unsigned short, int);
    void FUN_0060ba10(int a);
};
// Forwards the stored short s and the given int to FUN_0060bd90.
// @fnv 0x0060ba10
void S_0060ba10::FUN_0060ba10(int aiValue)
{
    FUN_0060bd90(s, aiValue);
}

struct FUN_00629ab0_shell
{
    float* p;
    float& FUN_00629ab0(unsigned int i);
};

// @fnv 0x00629ab0
float& FUN_00629ab0_shell::FUN_00629ab0(unsigned int uiIndex)
{
    return p[uiIndex];
}

struct GlobalObject_00528cb0
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    int v;
};
struct QueueHelper
{
    void QueueTaskByKey(int, GlobalObject_00528cb0*, int, int, int, bool, bool, bool);
    void FUN_00444040(int, int, int, int, bool, bool, bool);
};
// Constructs a GlobalObject_00528cb0 with 0 and forwards it with the remaining arguments to QueueTaskByKey.
// @fnv 0x00444040
void QueueHelper::FUN_00444040(int aiArg1, int aiArg2, int aiArg3, int aiArg4, bool abFlag1, bool abFlag2, bool abFlag3)
{
    GlobalObject_00528cb0 obj(0);
    QueueTaskByKey(aiArg1, &obj, aiArg2, aiArg3, aiArg4, abFlag1, abFlag2, abFlag3);
}

struct BSFaceGenManager;
struct NP
{
    NP(int);
    ~NP();
    int FUN_00559450() const;
    int* p;
};
extern BSFaceGenManager* DAT_011d59e8;
// Returns FUN_00559450() of the NP at offset 0x119c of DAT_011d59e8, or of a default NP(0) when DAT_011d59e8 is null.
// @fnv 0x006045f0
int __cdecl GetFaceGenManagerValue()
{
    return (DAT_011d59e8 ? *(NP*)((char*)DAT_011d59e8 + 0x119c) : NP(0)).FUN_00559450();
}

struct FUN_006055f0_shell : public TESNPC
{
    BipedAnim* GetOrCreateBipedAnim(TESObjectREFR*);
};

int __cdecl Warning(const char*, ...);
// Returns the reference's existing BipedAnim, warning if already set, otherwise creates one and assigns it to the reference.
// @fnv 0x006055f0
BipedAnim* FUN_006055f0_shell::GetOrCreateBipedAnim(TESObjectREFR* apRef)
{
    BipedAnim* pExistingBipedAnim;
    AutoMemContext tempMemContext((MEM_CONTEXT)0x33, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESNPC.cpp", 0x15d1);
    pExistingBipedAnim = apRef->GetBipedAnim();
    if (pExistingBipedAnim)
    {
        Warning("ANIMATION: This npc \"%s\" has already been used.\r\nOnly the first reference will be used.\r\n",
                ((TESForm*)this)->GetName());
    }
    else
    {
        pExistingBipedAnim = new BipedAnim(apRef, false);
        apRef->SetBipedAnim(pExistingBipedAnim);
    }
    return pExistingBipedAnim;
}

struct FUN_005d9f70_shell
{
    void SetField1B4(int value);
};

// @fnv 0x005d9f70
void FUN_005d9f70_shell::SetField1B4(int value)
{
    *(int*)((char*)this + 0x1b4) = value;
}

struct FUN_005f1230_shell : TESAttributes
{
    unsigned char GetAttributeValue7();
};

// @fnv 0x005f1230
unsigned char FUN_005f1230_shell::GetAttributeValue7()
{
    return GetAttributeValue(7);
}

struct FUN_00601c70_shell
{
    void __thiscall FUN_00601c70(int param);
};

// Stores param at offset 0x130 of this and calls the virtual function at vtable offset 0x48 with 0x400.
// @fnv 0x00601c70
void __thiscall FUN_00601c70_shell::FUN_00601c70(int aiValue)
{
    *(int*)((char*)this + 0x130) = aiValue;
    ((void(__thiscall*)(void*, int)) * (int**)(*(int*)this + 0x48))(this, 0x400);
}

struct FUN_00603f90_shell : TESRaceForm
{
    TESRace* GetRaceOrNull();
};

// Returns GetFormRace(), replacing a negative result with null.
// @fnv 0x00603f90
TESRace* FUN_00603f90_shell::GetRaceOrNull()
{
    TESRace* race = GetFormRace();
    if ((long)race < 0)
        race = 0;
    return race;
}

extern NiFixedString* DAT_011c6210;

// @fnv 0x006041c0
NiFixedString* __cdecl FUN_006041c0()
{
    return DAT_011c6210;
}

struct FUN_00604780_shell
{
    int __thiscall FUN_00604780(int index);
};

// @fnv 0x00604780
int __thiscall FUN_00604780_shell::FUN_00604780(int index)
{
    return *(int*)((char*)this + 0x4FC + index * 4);
}

namespace fnv_00607340 {
class BSFadeNode;
extern BSFadeNode* DAT_011d5b50;

// @fnv 0x00607340
BSFadeNode* __cdecl FUN_00607340()
{
    return DAT_011d5b50;
}
}  // namespace fnv_00607340

extern unsigned char DAT_011871f8;
struct FileH
{
    bool OpenTESFile(int, bool);
    bool SetOffset(unsigned int);
    unsigned int GetFormID();
};
struct FUN_00472660_shell
{
    int FUN_00472660();
};
struct FUN_00609bf0_s : TESNPC
{
    bool FUN_00609bf0(TESFile* apFile);
};
// Checks apFile and the offset at this+0x1e8, seeks there, compares the read value to DAT_011871f8 and the form ID to GetFormID.
// @fnv 0x00609bf0
bool FUN_00609bf0_s::FUN_00609bf0(TESFile* apFile)
{
    if (apFile && *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x1e8) &&
        reinterpret_cast<FileH*>(apFile)->OpenTESFile(0, false) &&
        reinterpret_cast<FileH*>(apFile)->SetOffset(
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x1e8)) &&
        reinterpret_cast<FUN_00472660_shell*>(apFile)->FUN_00472660() == DAT_011871f8 &&
        reinterpret_cast<FileH*>(apFile)->GetFormID() == GetFormID())
        return true;
    return false;
}

struct FUN_0060b1d0_shell : TESActorBaseData
{
    bool FUN_0060b1d0();
};

// @fnv 0x0060b1d0
bool FUN_0060b1d0_shell::FUN_0060b1d0()
{
    return GetFlag(0x800);
}

struct FUN_0060b1f0_shell : TESActorBaseData
{
    bool FUN_0060b1f0();
};

// @fnv 0x0060b1f0
bool FUN_0060b1f0_shell::FUN_0060b1f0()
{
    return GetFlag(0x1000);
}

struct FUN_0060b210_shell : TESActorBaseData
{
    void FUN_0060b210(bool bArg);
};

// @fnv 0x0060b210
void FUN_0060b210_shell::FUN_0060b210(bool bArg)
{
    UpdateFlagBit(0x1000, bArg, true);
}

struct BGSSaveFormBuffer;
struct Crime;
struct FUN_009dace0_shell : public TESActorBase
{
    void FUN_009dace0(BGSLoadFormBuffer*);
};

// @fnv 0x009dace0
void FUN_009dace0_shell::FUN_009dace0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
}

struct FUN_005f16f0_shell
{
    unsigned short __thiscall FUN_005f16f0(unsigned int);
};

struct TESNPC;

struct FUN_00608da0_shell : TESNPC
{
    unsigned short __thiscall FUN_00608da0(unsigned int aiFlags);
};

// Accumulates the base size from FUN_005f16f0 and adds 0xe when aiFlags has 0x200 set, returning the total.
// @fnv 0x00608da0
unsigned short __thiscall FUN_00608da0_shell::FUN_00608da0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_005f16f0_shell*)this)->FUN_005f16f0(aiFlags);
    if (aiFlags & 0x200)
        isize += 0xe;
    if (aiFlags & 0)
        isize += 4;
    return isize;
}

struct FUN_00601370_shell
{
    void FUN_006013c0();
    void* FUN_00601370(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_006013c0, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00601370
void* FUN_00601370_shell::FUN_00601370(unsigned int flags)
{
    this->FUN_006013c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006013a0_shell
{
    void __thiscall FUN_0060b9b0();
    void __thiscall FUN_006013a0();
};

// @fnv 0x006013a0
void __thiscall FUN_006013a0_shell::FUN_006013a0()
{
    FUN_0060b9b0();
}

extern SettingT_GameSettingCollection_ g_011d2718;
extern SettingT_GameSettingCollection_ g_011d3e44;
struct Struct00601c30
{
    const char* GetSexBasedString();
};
// Returns the string from one of two game setting collections depending on whether the actor base at this-0xDC has sex 1.
// @fnv 0x00601c30
const char* Struct00601c30::GetSexBasedString()
{
    if (((TESActorBase*)((char*)this - 0xDC))->GetSex() == 1)
        return g_011d2718.String();
    return g_011d3e44.String();
}

struct GO
{
    void* p;
    GO& operator=(void*);
};
struct FUN_00603bb0_Owner
{
    char pad[0x1C4];
    GO a;
    GO b;
    void FUN_00603bb0();
};
// @fnv 0x00603bb0
void FUN_00603bb0_Owner::FUN_00603bb0()
{
    a = 0;
    b = 0;
}

namespace fnv_006072c0 {
struct NiSkinInstance;
struct NiTriBasedGeom
{
    NiSkinInstance* FUN_0043fad0();
};
int __fastcall FUN_00559450(int*);
struct Inner6072
{
    char _c[16];
    int _v;
};
struct Outer6072
{
    char _pad[8];
    Inner6072* p;
    NiSkinInstance* FUN_006072c0();
};
// @fnv 0x006072c0
NiSkinInstance* Outer6072::FUN_006072c0()
{
    return (p && FUN_00559450(&p->_v)) ? ((NiTriBasedGeom*)FUN_00559450(&p->_v))->FUN_0043fad0() : 0;
}
}  // namespace fnv_006072c0

struct FUN_008b78c0_shell
{
    void UpdateHurtReaction(int);
};
struct FUN_0060b240_shell : public TESNPC
{
    void SetRace(TESRace* race, FUN_008b78c0_shell* actor);
};
// @fnv 0x0060b240
void FUN_0060b240_shell::SetRace(TESRace* race, FUN_008b78c0_shell* actor)
{
    TESRace* current = TESRaceForm::GetFormRace();
    if (race != current)
    {
        bool fixHeight = false;
        if (GetDefaultHeight() == m_fGlyphExtent)
            fixHeight = true;
        if (m_pAssignedRace == race)
        {
            TESRaceForm::Initialize((unsigned int)race);
            m_pAssignedRace = 0;
            MarkAsUnmodified(0x2000000);
        }
        else
        {
            TESRaceForm::Initialize((unsigned int)race);
            MarkAsModified(0x2000000);
            if (m_pAssignedRace == 0)
                m_pAssignedRace = current;
        }
        if (fixHeight)
            m_fGlyphExtent = GetDefaultHeight();
        if (actor)
            actor->UpdateHurtReaction(0);
    }
}

struct S8
{
    int v0;
    int v1;
    S8* FUN_0060b8e0(int);
    S8* FUN_0060b820(S8*, int);
};
// @fnv 0x0060b820
S8* S8::FUN_0060b820(S8* out, int arg)
{
    S8 tmp = *this;
    *out = *tmp.FUN_0060b8e0(arg);
    return out;
}

void __cdecl FillRange(int, int, int, void*);
struct Unk060b8a0
{
    int FUN_0060b8a0(int, int, int);
};
// Calls FillRange with the three arguments and this+8, then returns a + b*4.
// @fnv 0x0060b8a0
int Unk060b8a0::FUN_0060b8a0(int aiFirst, int aiSecond, int aiThird)
{
    FillRange(aiFirst, aiSecond, aiThird, (char*)this + 8);
    return aiFirst + aiSecond * 4;
}

struct FUN_0060b8e0_shell
{
    void Advance(int);
    void* FUN_0060b8e0(int);
};

// @fnv 0x0060b8e0
void* FUN_0060b8e0_shell::FUN_0060b8e0(int a)
{
    Advance(a);
    return this;
}

int __fastcall FUN_00559450(int*);
struct S_0060b980
{
    int* p;
    int FUN_0060b980();
};
// Returns the result of FUN_00559450 on the stored pointer, or 0 when the pointer is null.
// @fnv 0x0060b980
int S_0060b980::FUN_0060b980()
{
    return p ? FUN_00559450(p) : 0;
}

extern int DAT_0104aae0;
void __cdecl FUN_004ede70(void*);
struct Holder_FUN_0060b9b0
{
    void* vfptr;
    void* m_data;
    void FUN_0060b9b0();
};
// Sets the vtable pointer to DAT_0104aae0 and calls FUN_004ede70 on m_data.
// @fnv 0x0060b9b0
void Holder_FUN_0060b9b0::FUN_0060b9b0()
{
    vfptr = (void*)&DAT_0104aae0;
    FUN_004ede70(m_data);
}

struct FUN_006042d0_Owner
{
    char _pad[0x68];
    float _arr[2];
    float GetArrValue(int);
};
// Returns the element of _arr at index a1 when a1 is in [0,2), otherwise returns 0.0f.
// @fnv 0x006042d0
float FUN_006042d0_Owner::GetArrValue(int aiIndex)
{
    return (aiIndex >= 0 && aiIndex < 2) ? _arr[aiIndex] : 0.0f;
}

struct FUN_0060b860_Cls
{
    char _pad0[12];
    int _c;
    char _pad1[4];
    int _t;
    int FUN_0060b860();
};
// @fnv 0x0060b860
int FUN_0060b860_Cls::FUN_0060b860()
{
    return _c == 0 ? 0 : (_t - _c) >> 2;
}

struct STR_0060b9e0
{
    void FUN_0060bd20(unsigned int, unsigned int);
    void* FUN_0060b9e0(unsigned int, unsigned int);
};
extern int DAT_0104aae8;
// @fnv 0x0060b9e0
void* STR_0060b9e0::FUN_0060b9e0(unsigned int arg1, unsigned int arg2)
{
    FUN_0060bd20(arg1, arg2);
    *(void**)this = &DAT_0104aae8;
    return this;
}

namespace fnv_006013c0 {
struct GO
{
    void* p;
    ~GO();
};
struct ListX
{
    void* a;
    void* b;
    ~ListX();
};
struct FUN_006013a0
{
    unsigned char d[0x10];
    ~FUN_006013a0();
};
struct NpcList_t
{
    void FUN_00905330(TESNPC* const&);
};

struct FUN_006013c0 : public TESActorBase, public TESRaceForm
{
    ActorSkillData data;
    TESClass* m_pClass;
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    void* m_pOffsetFaceCoordinates;
    TESHair* m_pHair;
    float m_fHairLength;
    TESEyes* m_pEyes;
    GO m_pkPrimaryFaceGenNode, m_pkSecondaryFaceGenNode, m_pkFaceGenTexture;
    unsigned short m_usLastRace;
    unsigned short lastRacePadding;
    TESCombatStyle* m_pCombatStyle;
    unsigned int iHairColor;
    ListX m_kHeadPartList;
    int m_eImpactMaterial;
    unsigned int m_ulTopicFlags;
    TESRace* m_pAssignedRace;
    TESNPC* m_pTemplateNPC;
    float m_fGlyphExtent, fWeight;
    FUN_006013a0 undoStates;
    ~FUN_006013c0();
};

// @fnv 0x006013c0
FUN_006013c0::~FUN_006013c0()
{
    ((TESNPC*)this)->TESNPC::ClearData();
    if (GetFlag(4))
    {
        ((NpcList_t*)&DAT_011cb764)->FUN_00905330((TESNPC*)this);
    }
}
}  // namespace fnv_006013c0

namespace fnv_006044e0 {
struct FUN_006044e0_shell : public TESNPC
{
    void CreatePartTexture(int, void*);
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011d5adc;
struct TESObject
{
    unsigned int GetNext();
};
struct GO
{
    GO(int);
    ~GO();
    void operator=(void*);
    void* ptr;
};
struct Helper62d0
{
    void* operator=(void const*);
};
struct TES
{
    void CreateTextureImage(char const*, GO&, bool, bool);
};
extern TES* g_TES;
struct FUN_00604310_shell
{
    bool FUN_00604310(int, char*, unsigned int);
};
void* GetFaceGenManagerValue();

// @fnv 0x006044e0
void FUN_006044e0_shell::CreatePartTexture(int aePart, void* aspTexture)
{
    if (*g_011d5adc.Bool() || (unsigned int)this == ((TESObject*)g_thePlayer)->GetNext())
    {
        *(GO*)aspTexture = 0;
        return;
    }
    if (aePart >= 1)
    {
        *(GO*)aspTexture = GetFaceGenManagerValue();
        return;
    }
    char filename[260];
    if (!((FUN_00604310_shell*)this)->FUN_00604310(aePart, filename, 0x104))
    {
        *(GO*)aspTexture = 0;
        return;
    }
    GO sTexture(0);
    g_TES->CreateTextureImage(filename, sTexture, true, false);
    *(Helper62d0*)aspTexture = &sTexture;
}
}  // namespace fnv_006044e0

int __cdecl FUN_00408b20(char const*, char const*);

// @fnv 0x00603220
int FUN_00603220(char** apFirst, char** apSecond)
{
    char** localA = apFirst;
    char** localB = apSecond;
    if (!localA || !*localA || !localB || !*localB)
        return 0;
    return FUN_00408b20(reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(*localA) + 0xd0)->GetFullName(),
                        reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(*localB) + 0xd0)->GetFullName());
}

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};
struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(int*, int);
};
struct FUN_00608e00_shell
{
    void FUN_005f18c0(unsigned int);
    void FUN_00608e00(unsigned int aiFlags);
};

// @fnv 0x00608e00
void FUN_00608e00_shell::FUN_00608e00(unsigned int aiFlags)
{
    FUN_005f18c0(aiFlags);
    if (aiFlags & 0x200)
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
            reinterpret_cast<unsigned int>(reinterpret_cast<char*>(this) + 0x114), 0xe);
    if (aiFlags & 0)
    {
        int icombatstyleID = 0;
        if (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x1d4))
            icombatstyleID =
                reinterpret_cast<TESForm*>(*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x1d4))
                    ->GetFormID();
        reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(&icombatstyleID, 4);
    }
}

struct TESCombatStyle;
struct TESForm;
TESForm* __cdecl GetFormByID(unsigned int);
struct STR00
{
    void FUN_00484d00(void*, unsigned int);
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct FUN_00608e80_shell
{
    void FUN_005f1b30(unsigned int, unsigned int);
    void FUN_00608e80(unsigned int aiFlags, unsigned int aiCurrentFlags);
};
// @fnv 0x00608e80
void FUN_00608e80_shell::FUN_00608e80(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    FUN_005f1b30(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x200)
        ((STR00*)this)->FUN_00484d00((char*)this + 0x114, 0xe);
    if (aiFlags & 0)
    {
        unsigned int icombatstyleID;
        ((FUN_00484d40_Host*)this)->FUN_00484d40(&icombatstyleID, 4);
        *(TESCombatStyle**)((char*)this + 0x1d4) =
            (TESCombatStyle*)dynamic_cast<TESCombatStyle*>(GetFormByID(icombatstyleID));
    }
}

namespace fnv_006046a0 {
struct TESObject
{
    unsigned int GetNext();
};

struct FUN_006047a0_shell : public TESObject
{
    bool FUN_006047a0();
};

struct FUN_00604780_shell
{
    int FUN_00604780(int);
};

struct BGSDefaultObjectManager
{
    static TESForm* __cdecl GetDefaultObjectByIndex(int);
};

struct FUN_006046a0_shell
{
    TESForm* GetHeadPartForm();
};

extern FUN_006047a0_shell* _g_thePlayer;

// For the player actor, picks a default head part form by sex and FUN_006047a0 state, then returns the stored form or resolves one from the list at +0xdc.
// @fnv 0x006046a0
TESForm* FUN_006046a0_shell::GetHeadPartForm()
{
    if (reinterpret_cast<unsigned int>(reinterpret_cast<char*>(this) - 0x30) == _g_thePlayer->GetNext())
    {
        if (reinterpret_cast<TESActorBase*>(reinterpret_cast<char*>(this) - 0x30)->GetSex() == 0)
        {
            if (!_g_thePlayer->FUN_006047a0())
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    BGSDefaultObjectManager::GetDefaultObjectByIndex(0x0e);
            else
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    BGSDefaultObjectManager::GetDefaultObjectByIndex(0x0f);
        }
        else
        {
            if (!_g_thePlayer->FUN_006047a0())
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    BGSDefaultObjectManager::GetDefaultObjectByIndex(0x10);
            else
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    BGSDefaultObjectManager::GetDefaultObjectByIndex(0x11);
        }
    }

    if (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20))
        return *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20);

    BSSimpleList<BGSHeadPart*>* list =
        reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(reinterpret_cast<char*>(this) + 0xdc)->GetNext();

    if (list)
        return reinterpret_cast<TESForm*>(reinterpret_cast<FUN_00604780_shell*>(list)->FUN_00604780(
            reinterpret_cast<TESActorBase*>(reinterpret_cast<char*>(this) - 0x30)->GetSex()));

    return 0;
}
}  // namespace fnv_006046a0

struct FUN_006062e0_shell : public TESNPC
{
    void UpdateFaceGenHairVisibility(TESObjectREFR*, NiNode*);
};

// @fnv 0x006062e0
void FUN_006062e0_shell::UpdateFaceGenHairVisibility(TESObjectREFR* apRef, NiNode* apNode)
{
    NiAVObject* pheadSkinned;
    NiAVObject* pheadBiped5;
    InventoryStackRecord* pitem7;
    InventoryChanges* pinv5;
    NiAVObject* pearsObj9;

    if (apNode == 0)
        apNode = reinterpret_cast<NiNode*>(apRef->Get3DSimple());

    if (apNode == 0)
        return;

    pheadBiped5 = SceneObjectLookup::GetObjectByName(apNode, "BSFaceGenNiNodeBiped");
    pheadSkinned = SceneObjectLookup::GetObjectByName(apNode, "BSFaceGenNiNodeSkinned");

    if (pheadBiped5 == 0 || pheadSkinned == 0)
        return;

    {
        bool bhideHair9;
        bool bhideHatHair7;
        NiAVObject* phairObjX[2];
        char tempHairName4[32];

        pinv5 = InventoryChanges::GetOrAddInventoryChanges(apRef);
        pitem7 = pinv5->GetInventoryEntryData(0, false);

        if (pitem7 != 0)
        {
            pheadBiped5->FUN_00450f90(true);
            pheadSkinned->FUN_00450f90(true);
            delete pitem7;
            pitem7 = 0;
            return;
        }

        pheadBiped5->FUN_00450f90(false);
        pheadSkinned->FUN_00450f90(false);

        pearsObj9 = SceneObjectLookup::GetObjectByName(apNode, FUN_00605d40(true));

        for (int i = 0; i < 2; ++i)
            phairObjX[i] =
                SceneObjectLookup::GetObjectByName(apNode, BSFaceGenManager::BuildFaceGenPartPath(tempHairName4, i));

        bhideHair9 = false;
        bhideHatHair7 = true;

        pitem7 = pinv5->GetInventoryEntryData(1, false);
        if (pitem7 != 0)
        {
            delete pitem7;
            pitem7 = 0;
            bhideHair9 = true;
        }

        if (phairObjX[1] != 0)
        {
            pitem7 = pinv5->GetInventoryEntryData(10, false);
            if (pitem7 != 0)
            {
                delete pitem7;
                pitem7 = 0;
                bhideHatHair7 = false;
                bhideHair9 = true;
            }
        }

        if (pearsObj9 != 0)
            pearsObj9->FUN_00450f90(bhideHair9);

        for (int i = 0; i < 2; ++i)
        {
            if (phairObjX[i] != 0)
            {
                if (i == 0)
                    phairObjX[i]->FUN_00450f90(bhideHair9);
                else
                    phairObjX[i]->FUN_00450f90(bhideHatHair7);
            }
        }
    }
}

struct SaveField
{
    void FUN_00487010();
    void WriteToBuffer(unsigned int, unsigned int);
    void DestroySoundHandles();
    void ReleaseSound();
    void FUN_0048d330();
    void FUN_0047bd70();
    void FUN_00477f20();
    void FUN_00483710();
    unsigned int FUN_009611e0();
};
struct FaceValue
{
    float* data;
    unsigned int offset;
    const float* FUN_00629ab0();
};
struct FaceMatrix
{
    unsigned int FUN_009611e0();
    FaceValue FUN_0060b370(unsigned int index, unsigned int column);
};
struct GameForm
{
    unsigned int FUN_0084e3a0();
};
struct HeadPartNode
{
    bool FUN_008256d0();
    GameForm** FUN_006815c0();
    HeadPartNode* FUN_00726070();
};
extern void __cdecl FUN_00485910(unsigned int tag, unsigned int data);
extern void __cdecl FUN_00485910(unsigned int tag, float value);
extern void __cdecl FUN_00485950(unsigned int tag, unsigned int value);
extern void __cdecl AppendChunk(unsigned int tag, void* ptr, unsigned int length);
extern void __cdecl FUN_00485710(unsigned int tag, const void* ptr, unsigned int length);
extern void __cdecl FUN_00403d30(void*, int, unsigned int);
extern void* __cdecl FormHeap_Allocate(unsigned int size);
extern void __cdecl FormHeap_Free(void*);
extern bool __cdecl FUN_00401500();

struct NPCSerializer
{
    void FUN_004855a0();
    void FUN_00485e00();
    HeadPartNode* FUN_00602170();
    GameForm* FUN_00603b50();
    float FUN_00602130();
    GameForm* FUN_00602150();
    void FUN_00485680();
    void WriteToStream();
};

// Serializes the NPC record: writes sub-records, head parts, face morph values and extra fields to the save stream.
// @fnv 0x00601ca0
void NPCSerializer::WriteToStream()
{
    unsigned int count;
    FUN_004855a0();
    ((SaveField*)((char*)this + 0xd0))->FUN_00487010();
    ((SaveField*)((char*)this + 0xdc))->WriteToBuffer(0x4c444f4d, 0x54444f4d);
    ((SaveField*)((char*)this + 0x30))->DestroySoundHandles();
    ((SaveField*)((char*)this + 0x10c))->ReleaseSound();
    ((SaveField*)((char*)this + 0x7c))->FUN_0048d330();
    ((SaveField*)((char*)this + 0x70))->FUN_0047bd70();
    ((SaveField*)((char*)this + 0x104))->FUN_00477f20();

    if (*(GameForm**)((char*)this + 0x130))
    {
        count = (*(GameForm**)((char*)this + 0x130))->FUN_0084e3a0();
        FUN_00485910(0x4d414e43, count);
    }
    FUN_00485e00();
    if (FUN_00401500())
        ((SaveField*)((char*)this + 0x114))->FUN_00483710();
    AppendChunk(0x4d414e44, (char*)this + 0x114, 0x1c);
    if (FUN_00401500())
        ((SaveField*)((char*)this + 0x114))->FUN_00483710();

    HeadPartNode* head = FUN_00602170();
    while (head && !head->FUN_008256d0())
    {
        GameForm* item = *head->FUN_006815c0();
        FUN_00485910(0x4d414e50, item->FUN_0084e3a0());
        head = head->FUN_00726070();
    }

    if (FUN_00603b50())
    {
        FUN_00485910(0x4d414e48, FUN_00603b50()->FUN_0084e3a0());
        FUN_00485910(0x4d414e4c, FUN_00602130());
    }
    if (FUN_00602150())
    {
        FUN_00485910(0x4d414e45, FUN_00602150()->FUN_0084e3a0());
    }
    FUN_00485910(0x524c4348, *(unsigned int*)((char*)this + 0x1d8));

    typedef GameForm*(__thiscall * GetExtraFace)(NPCSerializer*);
    if (((GetExtraFace)((*(void***)this)[0x188 / 4]))(this))
    {
        FUN_00485910(0x4d414e5a, ((GetExtraFace)((*(void***)this)[0x188 / 4]))(this)->FUN_0084e3a0());
    }
    FUN_00485910(0x344d414e, *(unsigned int*)((char*)this + 0x1e4));

    unsigned int formID = ((FaceMatrix*)((char*)this + 0x134))->FUN_009611e0();
    if (formID != 0)
    {
        unsigned int values = formID * 4;
        float* bytes = (float*)FormHeap_Allocate(values);
        FUN_00403d30(bytes, 0, values);
        for (unsigned int index = 0; index < formID; ++index)
        {
            bytes[index] = *((FaceMatrix*)((char*)this + 0x134))->FUN_0060b370(index, 0).FUN_00629ab0();
        }
        FUN_00485710(0x53474746, bytes, formID);
        FormHeap_Free(bytes);
        bytes = 0;
    }
    formID = ((FaceMatrix*)((char*)this + 0x154))->FUN_009611e0();
    if (formID != 0)
    {
        unsigned int bytesSecond = formID * 4;
        float* valuesSecond = (float*)FormHeap_Allocate(bytesSecond);
        FUN_00403d30(valuesSecond, 0, bytesSecond);
        for (unsigned int indexSecond = 0; indexSecond < formID; ++indexSecond)
        {
            valuesSecond[indexSecond] =
                *((FaceMatrix*)((char*)this + 0x154))->FUN_0060b370(indexSecond, 0).FUN_00629ab0();
        }
        FUN_00485710(0x41474746, valuesSecond, formID);
        FormHeap_Free(valuesSecond);
        valuesSecond = 0;
    }
    formID = ((FaceMatrix*)((char*)this + 0x174))->FUN_009611e0();
    if (formID != 0)
    {
        unsigned int bytesThird = formID * 4;
        float* valuesThird = (float*)FormHeap_Allocate(bytesThird);
        FUN_00403d30(valuesThird, 0, bytesThird);
        for (unsigned int indexThird = 0; indexThird < formID; ++indexThird)
        {
            valuesThird[indexThird] = *((FaceMatrix*)((char*)this + 0x174))->FUN_0060b370(indexThird, 0).FUN_00629ab0();
        }
        FUN_00485710(0x53544746, valuesThird, formID);
        FormHeap_Free(valuesThird);
        valuesThird = 0;
    }

    FUN_00485950(0x354d414e, *(unsigned short*)((char*)this + 0x1d0));
    FUN_00485910(0x364d414e, *(float*)((char*)this + 0x1f4));
    FUN_00485910(0x374d414e, *(float*)((char*)this + 0x1f8));
    FUN_00485680();
}

void __cdecl LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
void __cdecl MasterFileWarning(const char* apFormat, ...);

struct NpcFaceGenQueue
{
    int HasQueuedTextures();
    void QueueNPC(TESNPC* apNPC);
};
extern NpcFaceGenQueue* DAT_011dea3c;

class NpcLoadShell : public TESNPC
{
  public:
    bool FUN_00602190(TESFile* apFile);
};

// @fnv 0x00602190
bool NpcLoadShell::FUN_00602190(TESFile* apFile)
{
    unsigned char _type;
    bool _found;
    int iD5;
    int iRow_2;
    int aType;
    bool bContinue;
    bool next9;
    float* buf3;
    char* pEditorID;

    _type = apFile->GetTESForm();
    if (_type != 0x2A)
        return false;

    m_ulTopicFlags = ((TESNPCFileAccess*)apFile)->GetOffset();
    LoadRecordHeader(apFile);
    SetInitializationState(false);

    _found = false;
    while ((iD5 = apFile->GetChunkID()) != 0)
    {
        iRow_2 = -1;
        aType = -1;
        bContinue = true;
        next9 = false;

        switch (iD5)
        {
        case 0x44494445 /* EDID */:
            pEditorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        case 0x444E424F /* OBND */:
            readOBNDSubRecord(apFile);
            break;
        case 0x4C4C5546 /* FULL */:
            LoadFullNameChunk(this, apFile);
            break;
        case 0x4C444F4D /* MODL */:
        case 0x54444F4D /* MODT */:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x49524353 /* SCRI */: {
            unsigned int uiScript = 0;
            apFile->GetChunkData(&uiScript);
            TESScriptableForm::Initialize(uiScript);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x44454F43 /* COED */:
        case 0x4F544E43 /* CNTO */:
            switch (apFile->GetChunkID())
            {
            case 0x4F544E43 /* CNTO */: {
                ContainerItem kItem;
                memset(&kItem, 0, sizeof(kItem));
                apFile->GetChunkData(&kItem, sizeof(kItem));
                if (apFile->IsEndianConversionRequired())
                    kItem.FUN_00462230();
                DAT_011cb7d8 = TESContainer::AddContainerObject(&kItem);
                break;
            }
            case 0x44454F43 /* COED */:
                if (DAT_011cb7d8)
                {
                    DAT_011cb7d8->pExtra = new ContainerItemExtra;
                    DAT_011cb7d8->pExtra->Load(apFile);
                    DAT_011cb7d8 = 0;
                }
                break;
            }
            break;
        case 0x4F4C5053 /* SPLO */: {
            unsigned int uiSpell = 0;
            apFile->GetChunkData(&uiSpell);
            TESSpellList::FUN_0048d290(uiSpell);
            break;
        }
        case 0x4D544945 /* EITM */: {
            unsigned int uiEnchant = 0;
            apFile->GetChunkData(&uiEnchant);
            BGSTouchSpellForm::Initialize(uiEnchant);
            break;
        }
        case 0x544D4145 /* EAMT */: {
            unsigned short usAmount = 0;
            ((TESFileChunkData16*)apFile)->GetChunkData(&usAmount);
            BGSTouchSpellForm::FUN_00483170(usAmount);
            break;
        }
        case 0x54444941 /* AIDT */: {
            PackedRecordData kAIData;
            memset(&kAIData, 0, sizeof(kAIData));
            apFile->GetChunkData(&kAIData, sizeof(kAIData));
            if (apFile->IsEndianConversionRequired())
                kAIData.SwapEndianFields();
            if (((TESFileFormVersion*)apFile)->GetFormVersion() < 4)
            {
                if (kAIData.m_ucField00 > 1)
                    kAIData.m_ucField00++;
            }
            if (((TESFileFormVersion*)apFile)->GetFormVersion() < 6)
            {
                switch (kAIData.m_ucField00)
                {
                case 0:
                    kAIData.m_ucField0E = 0;
                    break;
                case 1:
                    kAIData.m_ucField00 = 0;
                    kAIData.m_ucField0E = 1;
                    break;
                case 2:
                    kAIData.m_ucField00 = 1;
                    kAIData.m_ucField0E = 1;
                    break;
                case 3:
                    kAIData.m_ucField00 = 1;
                    kAIData.m_ucField0E = 2;
                    break;
                case 4:
                    kAIData.m_ucField00 = 2;
                    kAIData.m_ucField0E = 2;
                    break;
                case 5:
                    kAIData.m_ucField00 = 3;
                    kAIData.m_ucField0E = 0;
                    break;
                }
            }
            if (((TESFileFormVersion*)apFile)->GetFormVersion() < 7)
                kAIData.m_ucField01 = 4 - kAIData.m_ucField01;
            TESAIForm::FUN_0047f0b0(&kAIData);
            break;
        }
        case 0x44494B50 /* PKID */: {
            unsigned int uiPackage = 0;
            apFile->GetChunkData(&uiPackage);
            TESAIForm::FUN_0047f500(uiPackage);
            break;
        }
        case 0x4D414E53 /* SNAM */: {
            FactionReaction kRank;
            memset(&kRank, 0, sizeof(kRank));
            apFile->GetChunkData(&kRank, sizeof(kRank));
            if (apFile->IsEndianConversionRequired())
                kRank.Endian();
            SetFactionRank(kRank.pFaction, kRank.m_ucRank);
            break;
        }
        case 0x4D414E49 /* INAM */: {
            unsigned int uiDeathItem = 0;
            apFile->GetChunkData(&uiDeathItem);
            m_pBaseTemplateForm = (TESForm*)uiDeathItem;
            break;
        }
        case 0x4B435456 /* VTCK */: {
            unsigned int uiVoice;
            apFile->GetChunkData(&uiVoice);
            m_kFactionList = (TESForm*)uiVoice;
            break;
        }
        case 0x544C5054 /* TPLT */: {
            unsigned int uiTemplate;
            apFile->GetChunkData(&uiTemplate);
            m_ppTemplateForms = (TESForm*)uiTemplate;
            break;
        }
        case 0x53424341 /* ACBS */:
            apFile->GetChunkData(&actorData, sizeof(actorData));
            if (apFile->IsEndianConversionRequired())
                actorData.SwapEndianness();
            if (((TESFileFormVersion*)apFile)->GetFormVersion() < 8)
                actorData.m_usField16 = 0;
            actorData.m_usField06 = 0;
            break;
        case 0x4D414E52 /* RNAM */: {
            unsigned int uiRace = 0;
            apFile->GetChunkData(&uiRace);
            TESRaceForm::Initialize(uiRace);
            break;
        }
        case 0x5A46464B /* KFFZ */:
            TESAnimation::BaseFormRecord(this, apFile);
            break;
        case 0x54534544 /* DEST */:
        case 0x44545344 /* DSTD */:
            BGSDestructibleObjectForm::LoadDestructibleData(this, apFile);
            break;
        case 0x41544144 /* DATA */: {
            unsigned int uiExtra = apFile->GetChunkSize() - GetDataSizeAdjustment();
            if (uiExtra)
            {
                if (uiExtra != 0x1C && uiExtra * 2 != 0x1C)
                    MasterFileWarning("NPC '%s' (%08X) has invalid data format.", GetName(), GetFormID());
                ReadTypedData(apFile, &data, (unsigned short)uiExtra);
            }
            else
            {
                ReadTypedData(apFile, 0, 0);
            }
            break;
        }
        case 0x4D414E44 /* DNAM */:
            apFile->GetChunkData(&data, 0x1C);
            break;
        case 0x53474746 /* FGGS */:
            if (iRow_2 == -1)
            {
                iRow_2 = 0;
                aType = 0;
            }
        case 0x41474746 /* FGGA */:
            if (iRow_2 == -1)
            {
                iRow_2 = 0;
                aType = 1;
            }
        case 0x53544746 /* FGTS */: {
            if (iRow_2 == -1)
            {
                iRow_2 = 1;
                aType = 0;
            }
            unsigned int uiSize = apFile->GetChunkSize();
            unsigned int ItemUpdateArray = uiSize >> 2;
            m_kFaceGenCoordinates[iRow_2][aType].SetDimensions(ItemUpdateArray, 1);
            buf3 = (float*)_alloca(uiSize);
            memset(buf3, 0, uiSize);
            apFile->GetChunkData(buf3, uiSize);
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                if (apFile->IsEndianConversionRequired())
                    BSEndian(&buf3[i], EndianSizeTag<4>());
                *(float*)m_kFaceGenCoordinates[iRow_2][aType].FUN_0060b370(i, 0).FUN_00629ab0() = buf3[i];
            }
            break;
        }
        case 0x4D414E50 /* PNAM */: {
            unsigned int uiPartID;
            apFile->GetChunkData(&uiPartID);
            TESForm::RemapFormIDForFile(uiPartID, apFile);
            BGSHeadPart* pHeadPart = dynamic_cast<BGSHeadPart*>(GetFormByID(uiPartID));
            if (pHeadPart)
                FUN_00602170()->AddHead(pHeadPart);
            else
                MasterFileWarning("MASTERFILE: Could not find headpart (%08X) on NPC '%s' (%08X).", uiPartID, GetName(),
                                  GetFormID());
            break;
        }
        case 0x4D414E48 /* HNAM */: {
            unsigned int _id;
            apFile->GetChunkData(&_id);
            TESForm::RemapFormIDForFile(_id, apFile);
            TESHair* pHairForm = dynamic_cast<TESHair*>(GetFormByID(_id));
            if (pHairForm)
                SetHair(pHairForm);
            else
                MasterFileWarning("MASTERFILE: Could not find hair (%08X) on NPC '%s' (%08X).", _id, GetName(),
                                  GetFormID());
            break;
        }
        case 0x4D414E4C /* LNAM */: {
            float fScaleMultiplier;
            apFile->GetChunkData((unsigned int*)&fScaleMultiplier);
            if (fScaleMultiplier < 0.0)
                fScaleMultiplier = 0.0f;
            if (fScaleMultiplier > 1.0)
                fScaleMultiplier = 1.0f;
            FUN_00601c10(fScaleMultiplier);
            break;
        }
        case 0x4D414E45 /* ENAM */: {
            unsigned int uiEyesID;
            apFile->GetChunkData(&uiEyesID);
            TESForm::RemapFormIDForFile(uiEyesID, apFile);
            TESEyes* pEyes = dynamic_cast<TESEyes*>(GetFormByID(uiEyesID));
            if (pEyes)
                SetEyes(pEyes);
            else
                MasterFileWarning("MASTERFILE: Could not find eyes (%08X) on NPC '%s' (%08X).", uiEyesID, GetName(),
                                  GetFormID());
            break;
        }
        case 0x524C4348 /* HCLR */:
        case 0x394D414E /* NAM9 */:
            apFile->GetChunkData(&iHairColor);
            break;
        case 0x4D414E43 /* CNAM */: {
            unsigned int uiClass = 0;
            apFile->GetChunkData(&uiClass);
            m_pClass = (TESClass*)uiClass;
            break;
        }
        case 0x4D414E5A /* ZNAM */: {
            unsigned int uiCombatStyle;
            apFile->GetChunkData(&uiCombatStyle);
            ((TESActorBase*)this)->SetCombatStyle((TESCombatStyle*)uiCombatStyle);
            break;
        }
        case 0x4D414E46 /* FNAM */:
            if (apFile->GetChunkSize() >= 2)
            {
                ((TESFileChunkData16*)apFile)->GetChunkData(&m_usLastRace);
                if (apFile->IsEndianConversionRequired())
                    BSEndian(&m_usLastRace, EndianSizeTag<2>());
            }
            break;
        case 0x304D414E /* NAM0 */:
        case 0x314D414E /* NAM1 */:
        case 0x324D414E /* NAM2 */:
        case 0x334D414E /* NAM3 */:
            if (!_found)
            {
                MasterFileWarning("MASTERFILE: Found face texture for NPC '%s' (%08X) in file '%s'", GetName(),
                                  GetFormID(), apFile->GetFilename());
                _found = true;
            }
            break;
        case 0x344D414E /* NAM4 */: {
            unsigned int uiImpactMaterial;
            apFile->GetChunkData(&uiImpactMaterial);
            m_eImpactMaterial = uiImpactMaterial;
            break;
        }
        case 0x364D414E /* NAM6 */:
            apFile->GetChunkData((unsigned int*)&m_fGlyphExtent);
            break;
        case 0x374D414E /* NAM7 */:
            apFile->GetChunkData((unsigned int*)&fWeight);
            break;
        }

        if (!bContinue)
            break;
        if (!next9 && !apFile->NextChunk())
            break;
    }

    if (GetFormID() == 7 && DAT_011dea3c && !DAT_011dea3c->HasQueuedTextures())
        DAT_011dea3c->QueueNPC(this);

    if (!GetShortAtOffset12())
        MasterFileWarning("MASTERFILE: Speed multiplier is zero on NPC '%s' (%08X).", GetName(), GetFormID());

    return true;
}

namespace fnv_00603280 {
struct FUN_00603280_Api
{
    int FUN_00726070();
    int FUN_00401170();
    int FUN_004ac110();
    int FUN_005f0cc0();
    bool FUN_00461580(int);
    int FUN_007af430();
    void FUN_007cb2e0(int*);
    bool FUN_0076b610();
    void FUN_00729970(int (*)(char**, char**));
};

extern int DAT_011c3f2c;
extern int DAT_011dea3c;
int FUN_00603220(char** a, char** b);

// @fnv 0x00603280
void FUN_00603280(int aiFirstValue, int aiSecondValue, int pCollector)
{
    if (pCollector == 0)
    {
        return;
    }
    bool flag = true;
    while (1)
    {
        int pEntry = ((FUN_00603280_Api*)((FUN_00603280_Api*)DAT_011c3f2c)->FUN_00726070())->FUN_00726070();
        while (pEntry != 0)
        {
            if (((FUN_00603280_Api*)pEntry)->FUN_00401170() == 0x2a)
            {
                int item = pEntry;
                if (((FUN_00603280_Api*)item)->FUN_004ac110() == aiFirstValue &&
                    ((FUN_00603280_Api*)item)->FUN_005f0cc0() == aiSecondValue)
                {
                    if (!flag || ((FUN_00603280_Api*)(item + 0x30))->FUN_00461580(4))
                    {
                        if (item != ((FUN_00603280_Api*)DAT_011dea3c)->FUN_007af430())
                        {
                            ((FUN_00603280_Api*)pCollector)->FUN_007cb2e0(&item);
                        }
                    }
                }
            }
            pEntry = ((FUN_00603280_Api*)pEntry)->FUN_007af430();
        }
        if (((FUN_00603280_Api*)pCollector)->FUN_0076b610() && flag)
        {
            flag = false;
        }
        else
        {
            break;
        }
    }
    ((FUN_00603280_Api*)pCollector)->FUN_00729970(FUN_00603220);
}
}  // namespace fnv_00603280

struct LevelProxy
{
    unsigned int data;
    unsigned short FUN_0047ded0();
};
struct CountProxy
{
    void* items;
    unsigned int count;
    unsigned int FUN_00726070();
};
struct AttributeProxy
{
    unsigned char GetAttributeValue7();
};
struct SettingProxy
{
    float* FUN_00403e20();
};
extern SettingProxy DAT_011cd27c, DAT_011cd544, DAT_011cd908;
struct Context
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    LevelProxy level;
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    CountProxy count;
    AttributeProxy attributes;
    int ComputeAttributeValue(bool includeCount);
};
// Computes a value from level, count and attribute settings, clamping the level to at least 1 and the result to at least 0.
// @fnv 0x00603fc0
int Context::ComputeAttributeValue(bool includeCount)
{
    int a = level.FUN_0047ded0();
    if (a < 1)
        a = 1;
    int j =
        count.FUN_00726070()
            ? (int)((includeCount ? count.FUN_00726070() : 0) +
                    (attributes.GetAttributeValue7() + *DAT_011cd27c.FUN_00403e20()) * *DAT_011cd544.FUN_00403e20() +
                    (a - 1) * *DAT_011cd908.FUN_00403e20())
            : 0;
    if (j < 0)
        j = 0;
    return j;
}

class B6040D0Setting
{
  public:
    float* Float();
};

extern B6040D0Setting g_kB6040D0BaseSetting;
extern B6040D0Setting g_kB6040D0AttributeMult;
extern B6040D0Setting g_kB6040D0LevelMult;

class B6040D0ActorBase
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual unsigned short GetBaseValue();

    unsigned short GetLevel();
};

class B6040D0Attributes
{
  public:
    unsigned char GetAttribute();
};

class B6040D0NPC
{
  public:
    int ComputeDerivedValue(bool bUseBase);

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
    B6040D0ActorBase m_kBaseData;
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
    B6040D0Attributes m_kAttributes;
};

// @fnv 0x006040d0
int B6040D0NPC::ComputeDerivedValue(bool bUseBase)
{
    int iLevel = m_kBaseData.GetLevel();
    if (iLevel < 1)
        iLevel = 1;
    int iResult = m_kBaseData.GetBaseValue()
                      ? (int)((bUseBase ? (float)m_kBaseData.GetBaseValue() : *g_kB6040D0BaseSetting.Float()) +
                              m_kAttributes.GetAttribute() * *g_kB6040D0AttributeMult.Float() +
                              iLevel * *g_kB6040D0LevelMult.Float())
                      : 0;
    if (iResult < 0)
        iResult = 0;
    return iResult;
}

extern const double DAT_01012060;
struct WeightAccessor
{
    float GetArrValue();
};
struct FUN_00604250_shell : TESNPC
{
    int FUN_0084e3a0();
    WeightAccessor* FUN_004ac110();
    WeightAccessor* FUN_004ac110(void*);
    void* FUN_005f0cc0();
    float FUN_00944300();
    float GetWeight();
};
// @fnv 0x00604250
float FUN_00604250_shell::GetWeight()
{
    if (FUN_0084e3a0() == 7)
    {
        return fWeight == DAT_01012060 && FUN_004ac110() ? FUN_004ac110(FUN_005f0cc0())->GetArrValue() : fWeight;
    }
    return FUN_00944300();
}

struct FUN_00605fc0_obj
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
    virtual bool vE4();
};

struct FUN_00605fc0_owner
{
    FUN_00605fc0_obj** GetSlot(unsigned int i);
};

struct FUN_00605fc0_disp
{
    bool Process(FUN_00605fc0_obj** p);
    void Release(FUN_00605fc0_obj** p);
};

struct FUN_00605fc0_cls
{
    int unk00;
    void ProcessSlots(int unk08, FUN_00605fc0_owner* a2, FUN_00605fc0_disp* a3);
};

// Iterates 20 slots from a2, and for each non-null slot whose vE4() is true, calls a3->Process and a3->Release if Process returns false.
// @fnv 0x00605fc0
void FUN_00605fc0_cls::ProcessSlots(int aiUnused, FUN_00605fc0_owner* pOwner, FUN_00605fc0_disp* pDisp)
{
    for (unsigned int i = 0; i < 20; i++)
    {
        FUN_00605fc0_obj** slot = pOwner->GetSlot(i);
        if (*slot != 0 && (*slot)->vE4())
        {
            FUN_00605fc0_obj* obj = *slot;
            if (!pDisp->Process(&obj))
            {
                pDisp->Release(&obj);
            }
        }
    }
}

// Save-size computation: four 2x2 tracked lists (count * element size each) plus fixed fields.

class SaveTrackedList
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

    unsigned int GetCount();
    unsigned int GetElementSize();
};

class SaveTrackedOwner
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    SaveTrackedList m_aakLists[2][2];

    unsigned short GetSaveSize(int iVersion);
};

// Sums count times element size times 4 over the 2x2 m_aakLists, adds 21 bytes of fixed fields, and returns the total as unsigned short.
// @fnv 0x00609c70
unsigned short SaveTrackedOwner::GetSaveSize(int iVersion)
{
    unsigned short usSize = 0;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            unsigned int ItemUpdateArray = m_aakLists[i][j].GetCount();
            unsigned int uiElementSize = m_aakLists[i][j].GetElementSize();
            usSize += ItemUpdateArray * uiElementSize * 4;
        }
    }
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 1;
    return usSize;
}

namespace fnv_0060a890 {
struct CopyBlob9
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

struct OutBuf
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

extern unsigned char DAT_011c5cb4;
extern int DAT_011dea3c;
extern unsigned char DAT_011a9448;

struct VirtHolder
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_00a();
    virtual void vfn_00b();
    virtual void vfn_00c();
    virtual void vfn_00d();
    virtual void vfn_00e();
    virtual void vfn_00f();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_01a();
    virtual void vfn_01b();
    virtual void vfn_01c();
    virtual void vfn_01d();
    virtual void vfn_01e();
    virtual void vfn_01f();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_02a();
    virtual void vfn_02b();
    virtual void vfn_02c();
    virtual void vfn_02d();
    virtual void vfn_02e();
    virtual void vfn_02f();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_03a();
    virtual void vfn_03b();
    virtual void vfn_03c();
    virtual void vfn_03d();
    virtual void vfn_03e();
    virtual void vfn_03f();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_04a();
    virtual void vfn_04b();
    virtual void vfn_04c();
    virtual void vfn_04d();
    virtual void vfn_04e();
    virtual void vfn_04f();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_05a();
    virtual void vfn_05b();
    virtual void vfn_05c();
    virtual void vfn_05d();
    virtual void vfn_05e();
    virtual void vfn_05f();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_06a();
    virtual void vfn_06b();
    virtual void vfn_06c();
    virtual void vfn_06d();
    virtual void vfn_06e();
    virtual void vfn_06f();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_07a();
    virtual void vfn_07b();
    virtual void vfn_07c();
    virtual void vfn_07d();
    virtual void vfn_07e();
    virtual void vfn_07f();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_08a();
    virtual void vfn_08b();
    virtual void vfn_08c();
    virtual void vfn_08d();
    virtual void vfn_08e();
    virtual void vfn_08f();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_09a();
    virtual void vfn_09b();
    virtual void vfn_09c();
    virtual void vfn_09d();
    virtual void vfn_09e();
    virtual void vfn_09f();
    virtual void vfn_0a0();
    virtual void vfn_0a1();
    virtual void vfn_0a2();
    virtual void vfn_0a3();
    virtual void vfn_0a4();
    virtual void vfn_0a5();
    virtual void vfn_0a6();
    virtual void vfn_0a7();
    virtual void vfn_0a8();
    virtual void vfn_0a9();
    virtual void vfn_0aa();
    virtual void vfn_0ab();
    virtual void vfn_0ac();
    virtual void vfn_0ad();
    virtual void vfn_0ae();
    virtual void vfn_0af();
    virtual void vfn_0b0();
    virtual void vfn_0b1();
    virtual void vfn_0b2();
    virtual void vfn_0b3();
    virtual void vfn_0b4();
    virtual void vfn_0b5();
    virtual void vfn_0b6();
    virtual void vfn_0b7();
    virtual void vfn_0b8();
    virtual void vfn_0b9();
    virtual void vfn_0ba();
    virtual void vfn_0bb();
    virtual void vfn_0bc();
    virtual void vfn_0bd();
    virtual void vfn_0be();
    virtual void vfn_0bf();
    virtual void vfn_0c0();
    virtual void vfn_0c1();
    virtual void vfn_0c2();
    virtual void vfn_0c3();
    virtual void vfn_0c4();
    virtual void vfn_0c5();
    virtual void vfn_0c6();
    virtual void vfn_0c7();
    virtual void vfn_0c8();
    virtual void vfn_0c9();
    virtual void vfn_0ca();
    virtual void vfn_0cb();
    virtual void vfn_0cc();
    virtual void vfn_0cd();
    virtual void vfn_0ce();
    virtual void vfn_0cf();
    virtual void vfn_0d0();
    virtual void vfn_0d1();
    virtual void vfn_0d2();
    virtual void vfn_0d3();
    virtual void vfn_0d4();
    virtual void vfn_0d5();
    virtual void vfn_0d6();
    virtual void vfn_0d7();
    virtual void vfn_0d8();
    virtual void vfn_0d9();
    virtual void vfn_0da();
    virtual void vfn_0db();
    virtual void vfn_0dc();
    virtual void vfn_0dd();
    virtual void vfn_0de();
    virtual void vfn_0df();
    virtual void vfn_0e0();
    virtual void vfn_0e1();
    virtual void vfn_0e2();
    virtual void vfn_0e3();
    virtual void vfn_0e4();
    virtual void vfn_0e5();
    virtual void vfn_0e6();
    virtual void vfn_0e7();
    virtual void vfn_0e8();
    virtual void vfn_0e9();
    virtual void vfn_0ea();
    virtual void vfn_0eb();
    virtual void vfn_0ec();
    virtual void vfn_0ed();
    virtual void vfn_0ee();
    virtual void vfn_0ef();
    virtual void vfn_0f0();
    virtual void vfn_0f1();
    virtual void vfn_0f2();
    virtual void vfn_0f3();
    virtual void vfn_0f4();
    virtual void vfn_0f5();
    virtual void vfn_0f6();
    virtual void vfn_0f7();
    virtual void vfn_0f8();
    virtual void vfn_0f9();
    virtual void vfn_0fa();
    virtual void vfn_0fb();
    virtual void vfn_0fc();
    virtual void vfn_0fd();
    virtual void vfn_0fe();
    virtual void vfn_0ff();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_10a();
    virtual void vfn_10b();
    virtual void vfn_10c();
    virtual void vfn_10d();
    virtual void vfn_10e();
    virtual void vfn_10f();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119(int a);
};

struct ProcessHost
{
    void* FUN_008d8520();
    void* FUN_00950bb0(int a);
    void* FUN_0045bc00(int a);
    void* FUN_0056fac0(OutBuf* out, CopyBlob9* blob);
    void FUN_0043fa80(void* a);
    void FUN_0060a890(int a1);
};

// @fnv 0x0060a890
void ProcessHost::FUN_0060a890(int pObject)
{
    CopyBlob9 blob;
    DAT_011c5cb4 = 1;
    ((VirtHolder*)((ProcessHost*)pObject)->FUN_008d8520())->vfn_119(pObject);
    DAT_011c5cb4 = 0;
    if (pObject == DAT_011dea3c)
    {
        OutBuf out;
        int x;
        int y;
        int p;
        x = (int)((ProcessHost*)DAT_011dea3c)->FUN_00950bb0(1);
        y = x != 0 ? x : 0;
        p = y != 0 ? (int)((ProcessHost*)y)->FUN_0045bc00(0) : 0;
        blob = *(CopyBlob9*)&DAT_011a9448;
        if (p != 0)
        {
            ((ProcessHost*)p)->FUN_0043fa80(((ProcessHost*)DAT_011dea3c)->FUN_0056fac0(&out, &blob));
        }
    }
}
}  // namespace fnv_0060a890

void __cdecl FUN_00ec7c56();

struct FaceCoordinateRange
{
    int referenceCount;
    int allocationCount;
    int stride;
    int* begin;
    int* end;
};

struct FaceCoordinateCursor
{
    int owner;
    int* current;
    bool FUN_005ca4f0();
    FaceCoordinateRange* FUN_0060b980();
    FaceCoordinateCursor* Advance(int count);
};

// Checks the cursor is valid and that advancing by count stays within the range, then advances current by count and returns this.
// @fnv 0x0060b900
FaceCoordinateCursor* FaceCoordinateCursor::Advance(int count)
{
    if (!FUN_005ca4f0())
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (false);

    if (current + count > FUN_0060b980()->end || current + count < FUN_0060b980()->begin)
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (false);

    current += count;
    return this;
}

struct FaceSetting
{
    float* FUN_00403e20();
};
extern FaceSetting DAT_011cb7a0;
struct FaceRace;
struct RaceLink
{
    FaceRace* FUN_00726070();
};
struct FaceRace
{
    void* FUN_005d9fb0(int);
};
void FUN_006521f0(void*);
void FUN_00652fc0(float, void*, void*);
float FUN_00652440(void*, int, int);
void FUN_00652470(void*, int, int, float);
float FUN_005c5420();
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
void FUN_00652e00(void*, void*, void*, int);
bool FUN_00652900(void*, void*);
void FUN_006529a0(void*, void*, int, int);
struct FaceMatrixLocal
{
    FaceMatrixLocal();
    ~FaceMatrixLocal();
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
};
struct HeadPointer
{
    HeadPointer& operator=(void*);
};
struct FaceNpc
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    RaceLink race;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    HeadPointer head;
    int FUN_005f0cc0();
    void FUN_00601c10(float);
    void* FUN_00601800();
    void RandomizeFace(bool, bool, bool);
};
// Builds a face matrix from the race data, randomizes age/shape/other values unless kept, clamps them, and applies the result to the head if it differs.
// @fnv 0x00601830
void FaceNpc::RandomizeFace(bool keepAge, bool keepShape, bool keepOther)
{
    FaceMatrixLocal source9[2][2];
    FaceMatrixLocal _result[2][2];
    float first2, second, value, other7;
    FUN_006521f0(_result);
    FUN_00652fc0(*DAT_011cb7a0.FUN_00403e20(), race.FUN_00726070()->FUN_005d9fb0(FUN_005f0cc0()), source9);
    first2 = FUN_00652440(source9, 0, 0);
    second = FUN_00652440(source9, 0, 1);
    if (keepAge)
        value = first2;
    else
        value = FUN_005c5420() * 50.0 + 15.0;
    other7 = second - (first2 - value);
    value = FUN_0040ebd0(FUN_00404010(value, 15.0f), 65.0f);
    other7 = FUN_0040ebd0(FUN_00404010(other7, 15.0f), 65.0f);
    FUN_00652470(source9, 0, 0, value);
    FUN_00652470(source9, 0, 1, other7);
    first2 = FUN_00652440(source9, 1, 0);
    second = FUN_00652440(source9, 1, 1);
    if (keepShape)
    {
        value = first2;
        other7 = second;
    }
    else
    {
        value = FUN_005c5420() * 4.0 - 2.0;
        other7 = second - (first2 - value);
    }
    value = FUN_0040ebd0(FUN_00404010(value, -2.0f), 2.0f);
    other7 = FUN_0040ebd0(FUN_00404010(other7, -2.0f), 2.0f);
    FUN_00652470(source9, 1, 0, value);
    FUN_00652470(source9, 1, 1, other7);
    if (!keepOther)
        FUN_00601c10(FUN_005c5420());
    FUN_00652e00(race.FUN_00726070()->FUN_005d9fb0(FUN_005f0cc0()), source9, _result, 0);
    if (FUN_00652900(_result, FUN_00601800()))
    {
        FUN_006529a0(_result, FUN_00601800(), 0, 0);
        head = 0;
    }
}

#include <string.h>

struct NPCCompare : TESNPC
{
    bool FUN_00485270(TESForm*);
    bool IsDifferentFrom(TESForm* form);
};
struct HeadPartCompare : HeadPartNode
{
    unsigned int FUN_005ae380();
    bool FUN_005f65d0(GameForm*&);
};
bool __cdecl FUN_00652900(void*, void*);

// Compares this NPC against another TESNPC, returning true if any class, hair, head part, combat style or related field differs.
// @fnv 0x00603880
bool NPCCompare::IsDifferentFrom(TESForm* form)
{
    TESNPC* npc = dynamic_cast<TESNPC*>(form);
    if (!npc)
        return true;
    if (FUN_00485270(npc))
        return true;
    if (memcmp(&data, npc->GetTextureManager(), sizeof(data)))
        return true;
    if (m_pClass != npc->GetClass())
        return true;
    if (m_pHair != npc->GetHair())
        return true;
    if (m_fHairLength != npc->FUN_00602130())
        return true;
    if (m_pEyes != npc->FUN_00602150())
        return true;
    if (iHairColor != npc->FUN_004169d0())
        return true;
    if (FUN_00652900(reinterpret_cast<FUN_00601800_shell*>(this)->FUN_00601800(),
                     static_cast<FUN_00601800_shell*>(npc)->FUN_00601800()))
        return true;
    if (GetCombatStyle() != npc->GetCombatStyle())
        return true;
    if (vfn_58() != npc->vfn_58())
        return true;
    if (reinterpret_cast<HeadPartCompare*>(FUN_00602170())->FUN_005ae380() !=
        reinterpret_cast<HeadPartCompare*>(npc->FUN_00602170())->FUN_005ae380())
        return true;
    HeadPartNode* node = reinterpret_cast<HeadPartNode*>(FUN_00602170());
    while (node && !node->FUN_008256d0())
    {
        if (!reinterpret_cast<HeadPartCompare*>(npc->FUN_00602170())->FUN_005f65d0(*node->FUN_006815c0()))
            return true;
        node = node->FUN_00726070();
    }
    if (m_fGlyphExtent != npc->m_fGlyphExtent)
        return true;
    if (fWeight != npc->fWeight)
        return true;
    return false;
}

extern const char str_0104a714[], str_0104a704[], str_0104a6cc[], str_0104a694[], str_0104a660[];
int __cdecl FUN_004564f0(const char*, const char*, unsigned int);
int __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
struct FileName
{
    const char* FUN_00891170();
};
struct RaceID
{
    unsigned int FUN_0084e3a0();
};
struct GenderQuery
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
    virtual bool v2c();
};
struct Target
{
    unsigned int unknown_000;
    unsigned int unknown_004;
    unsigned int unknown_008;
    unsigned int unknown_00c;
    unsigned int unknown_010;
    unsigned int unknown_014;
    unsigned int unknown_018;
    unsigned int unknown_01c;
    unsigned int unknown_020;
    unsigned int unknown_024;
    unsigned int unknown_028;
    unsigned int unknown_02c;
    GenderQuery actorData;
    unsigned int unknown_034;
    unsigned int unknown_038;
    unsigned int unknown_03c;
    unsigned int unknown_040;
    unsigned int unknown_044;
    unsigned int unknown_048;
    unsigned int unknown_04c;
    unsigned int unknown_050;
    unsigned int unknown_054;
    unsigned int unknown_058;
    unsigned int unknown_05c;
    unsigned int unknown_060;
    unsigned int unknown_064;
    unsigned int unknown_068;
    unsigned int unknown_06c;
    unsigned int unknown_070;
    unsigned int unknown_074;
    unsigned int unknown_078;
    unsigned int unknown_07c;
    unsigned int unknown_080;
    unsigned int unknown_084;
    unsigned int unknown_088;
    unsigned int unknown_08c;
    unsigned int unknown_090;
    unsigned int unknown_094;
    unsigned int unknown_098;
    unsigned int unknown_09c;
    unsigned int unknown_0a0;
    unsigned int unknown_0a4;
    unsigned int unknown_0a8;
    unsigned int unknown_0ac;
    unsigned int unknown_0b0;
    unsigned int unknown_0b4;
    unsigned int unknown_0b8;
    unsigned int unknown_0bc;
    unsigned int unknown_0c0;
    unsigned int unknown_0c4;
    unsigned int unknown_0c8;
    unsigned int unknown_0cc;
    unsigned int unknown_0d0;
    unsigned int unknown_0d4;
    unsigned int unknown_0d8;
    unsigned int unknown_0dc;
    unsigned int unknown_0e0;
    unsigned int unknown_0e4;
    unsigned int unknown_0e8;
    unsigned int unknown_0ec;
    unsigned int unknown_0f0;
    unsigned int unknown_0f4;
    unsigned int unknown_0f8;
    unsigned int unknown_0fc;
    unsigned int unknown_100;
    unsigned int unknown_104;
    unsigned int unknown_108;
    unsigned int unknown_10c;
    unsigned int unknown_110;
    unsigned int unknown_114;
    unsigned int unknown_118;
    unsigned int unknown_11c;
    unsigned int unknown_120;
    unsigned int unknown_124;
    unsigned int unknown_128;
    unsigned int unknown_12c;
    unsigned int unknown_130;
    unsigned int unknown_134;
    unsigned int unknown_138;
    unsigned int unknown_13c;
    unsigned int unknown_140;
    unsigned int unknown_144;
    unsigned int unknown_148;
    unsigned int unknown_14c;
    unsigned int unknown_150;
    unsigned int unknown_154;
    unsigned int unknown_158;
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
    unsigned int unknown_17c;
    unsigned int unknown_180;
    unsigned int unknown_184;
    unsigned int unknown_188;
    unsigned int unknown_18c;
    unsigned int unknown_190;
    unsigned int unknown_194;
    unsigned int unknown_198;
    unsigned int unknown_19c;
    unsigned int unknown_1a0;
    unsigned int unknown_1a4;
    unsigned int unknown_1a8;
    unsigned int unknown_1ac;
    unsigned int unknown_1b0;
    unsigned int unknown_1b4;
    unsigned int unknown_1b8;
    unsigned int unknown_1bc;
    unsigned int unknown_1c0;
    unsigned int unknown_1c4;
    unsigned int unknown_1c8;
    unsigned int unknown_1cc;
    unsigned int unknown_1d0;
    unsigned int unknown_1d4;
    unsigned int unknown_1d8;
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;
    unsigned int unknown_1e4;
    unsigned int unknown_1e8;
    unsigned int unknown_1ec;
    Target* m_pTemplateNPC;

    bool FUN_00604310(const char*, char*, unsigned int);
    Target* FUN_006044c0();
    FileName* FUN_00484ee0();
    unsigned int FUN_0084e3a0();
    RaceID* FUN_004ac110();
    int FUN_005f0cc0();
};
// @fnv 0x00604310
bool Target::FUN_00604310(const char* extension, char* output, unsigned int length)
{
    if (m_pTemplateNPC)
    {
        Target* face = static_cast<Target*>(m_pTemplateNPC);
        while (face && face->FUN_006044c0())
            face = face->FUN_006044c0();
        return face->FUN_00604310(extension, output, length);
    }
    FileName* file = FUN_00484ee0();
    if (!file)
        return false;
    unsigned int npcID = FUN_0084e3a0() & 0x00ffffffu;
    unsigned int raceID6 = FUN_004ac110()->FUN_0084e3a0() & 0x00ffffffu;
    bool master = false;
    if (!FUN_004564f0(file->FUN_00891170(), str_0104a714, 6))
        master = true;
    if (actorData.v2c())
    {
        if (FUN_005f0cc0() == 1)
        {
            FUN_00406d00(output, length, str_0104a6cc, !master ? file->FUN_00891170() : str_0104a704, raceID6, npcID,
                         extension);
        }
        else
        {
            FUN_00406d00(output, length, str_0104a694, !master ? file->FUN_00891170() : str_0104a704, raceID6, npcID,
                         extension);
        }
    }
    else
    {
        FUN_00406d00(output, length, str_0104a660, !master ? file->FUN_00891170() : str_0104a704, npcID, extension);
    }
    return true;
}

struct CopyNpc;

struct BaseFormRecord
{
    int tag;
    void CopyFromScriptableForm(BaseFormRecord*);
    void FUN_00481c80(BaseFormRecord*);
    void CopyFullNameFrom(BaseFormRecord*);
    void FUN_0047fb50(BaseFormRecord*);
    void FUN_004786e0(BaseFormRecord*);
    void CopyAttributesFromComponent(BaseFormRecord*);
    void CopyHealthForm(BaseFormRecord*);
    void FUN_0048d630(BaseFormRecord*);
    void FUN_0047bdd0(BaseFormRecord*);
    void FUN_0047f1e0(BaseFormRecord*);
    void FUN_0047f2d0(BaseFormRecord*);
    void FUN_006ecd40(int);
    int FUN_00726070();
};

struct CopyPrefix
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

    virtual void slot76();

    virtual void slot77();

    virtual void slot78();

    virtual void slot79();

    virtual void slot80();

    virtual bool GetFemale();

    virtual void SetFemale(bool);

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void slot89();

    virtual void slot90();

    virtual void slot91();

    virtual void slot92();

    virtual void slot93();

    virtual void slot94();

    virtual void slot95();

    virtual void slot96();

    virtual void slot97();

    virtual void* GetStyle();

    virtual void SetStyle(void*);
    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    int FUN_00401170();
};

struct CopyData
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void Reset(int);

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

    virtual unsigned int GetValue();

    virtual void SetValue(unsigned int);

    virtual unsigned short GetStat();

    virtual float GetFactor();

    virtual int GetData();
    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    int unk030;

    BaseFormRecord container;

    int unk038;

    int unk03c;

    BaseFormRecord touch;

    int unk044;

    int unk048;

    BaseFormRecord spell;

    int unk050;

    int unk054;

    int unk058;

    int unk05c;

    BaseFormRecord ai;

    int unk064;

    int unk068;

    int unk06c;

    int unk070;

    int unk074;

    int unk078;

    int unk07c;

    BaseFormRecord health;

    int unk084;

    BaseFormRecord attributes;

    int unk08c;

    int unk090;

    BaseFormRecord animation;

    int unk098;

    int unk09c;

    BaseFormRecord fullName;

    int unk0a4;

    int unk0a8;

    int unk0ac;

    int unk0b0;

    int unk0b4;

    int unk0b8;

    int unk0bc;

    int unk0c0;

    BaseFormRecord model;

    int unk0c8;

    int unk0cc;

    int unk0d0;

    BaseFormRecord destructible;

    int unk0d8;

    BaseFormRecord race;

    int unk0e0;

    unsigned char skills[14];
    unsigned char skillOffsets[14];

    void FUN_00604ba0(CopyPrefix*);

    CopyNpc* FUN_0059bb30();
    bool FUN_0047cdd0();
    bool FUN_0047cca0();
    bool FUN_0047cd40(int);
    unsigned int* FUN_00717e50();
    void FUN_0047dd30(unsigned int);
    int FUN_00441110();
    void FUN_0050f9a0(int);
    void FUN_0050f9c0(int);
    bool FUN_00461580(bool, bool);
    void FUN_0047dd50(bool, bool);
    void SetClampedValue(float);
    unsigned short FUN_0047d3d0();
    void FUN_0047dea0(unsigned short);
    unsigned short FUN_0047d370();
    void FUN_0047dfe0(unsigned short);
    bool FUN_00461560();
    void FUN_005d1070(bool);
    unsigned short FUN_0047d390();
    void FUN_0047de40(unsigned short);
    unsigned short FUN_0047d3b0();
    void FUN_0047de70(unsigned short);
    unsigned short GetShortAtOffset12();
    void SetSpeedMult(unsigned short);
    void FUN_0047e010(unsigned short);
    void CopyFactionRanks(CopyData*);
    void FUN_007037c0(CopyNpc*);
    void FUN_0047cd90(unsigned short);
    void FUN_0047ccc0(bool);
};

struct CopyNpc : public CopyPrefix, public CopyData
{

    void FUN_0050eaa0(CopyNpc*);
    void FUN_00603790(CopyNpc*);
    void FUN_00601c70(int);
    float FUN_00944300();
    void FUN_009442e0(float);
    float GetWeight();
    void FUN_006053f0(float);
    int FUN_00502430();
    void InitAttributesAndSkills(int);
};

struct DefaultNpcValue
{
    int* FUN_006815c0();
};

struct DefaultNpcManager
{
    DefaultNpcValue* FUN_004ea950();
    DefaultNpcValue* FUN_006130e0();
};

extern DefaultNpcManager* DAT_011c3f2c;

void FUN_00401460(void*, const void*, unsigned int);

CopyNpc* FindFirstNonActorBaseTemplate(CopyNpc*, unsigned short*);

// Copies selected fields from a source NPC (or a default fallback) into this record according to the active copy flags, then applies the template form.
// @fnv 0x00604ba0
void CopyData::FUN_00604ba0(CopyPrefix* apSource)
{

    CopyNpc* source9;
    CopyNpc* templateForm;

    {
        unsigned short flags;

        if (!FUN_0059bb30() && !apSource)
            return;

        {

            TESNPC fallback;

            source9 = 0;

            if (!FUN_0047cdd0())
                source9 = FUN_0059bb30();

            if (apSource && apSource->FUN_00401170() == 42)
                source9 = static_cast<CopyNpc*>(apSource);

            if (!source9)
            {

                source9 = reinterpret_cast<CopyNpc*>(&fallback);

                source9->race.FUN_006ecd40(*DAT_011c3f2c->FUN_004ea950()->FUN_006815c0());

                source9->FUN_00601c70(*DAT_011c3f2c->FUN_006130e0()->FUN_006815c0());
            }
            else if (source9->FUN_0059bb30() && !source9->FUN_0047cca0())
                source9->Reset(0);

            if (FUN_0047cd40(9))
                model.CopyFromScriptableForm(source9 ? &source9->model : 0);

            if (FUN_0047cd40(8))
                container.FUN_00481c80(source9 ? &source9->container : 0);

            if (FUN_0047cd40(7))
            {

                fullName.CopyFullNameFrom(source9 ? &source9->fullName : 0);

                unsigned int ownFlags = *FUN_00717e50();
                ownFlags &= 0xef9f5df5;

                unsigned int sourceFlags4 = *source9->FUN_00717e50();
                sourceFlags4 &= 0x1060a20a;

                FUN_0047dd30(sourceFlags4 | ownFlags);
            }

            if (FUN_0047cd40(6))
            {

                animation.FUN_0047fb50(source9 ? &source9->animation : 0);

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))->FUN_0050eaa0(source9);

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->SetValue(source9->GetValue());

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))->FUN_00603790(source9);

                destructible.FUN_004786e0(source9 ? &source9->destructible : 0);
            }

            if (FUN_0047cd40(0))
            {

                FUN_0050f9a0(source9->FUN_00441110());

                FUN_0050f9c0(source9->GetData());

                FUN_0047dd50(true, source9->FUN_00461580(true, true));

                race.FUN_006ecd40(source9->race.FUN_00726070());

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->FUN_009442e0(source9->FUN_00944300());

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->FUN_006053f0(source9->GetWeight());

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->FUN_00601c70(source9->FUN_00502430());

                SetClampedValue(source9->GetFactor());

                FUN_0047dea0(FUN_0047d3d0());

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->SetStyle(source9->GetStyle());
            }

            if (FUN_0047cd40(1))
            {

                FUN_0047dfe0(source9->FUN_0047d370());

                FUN_005d1070(source9->FUN_00461560());

                FUN_0047de40(source9->FUN_0047d390());

                FUN_0047de70(source9->FUN_0047d3b0());

                attributes.CopyAttributesFromComponent(source9 ? &source9->attributes : 0);

                health.CopyHealthForm(source9 ? &source9->health : 0);

                SetSpeedMult(source9->GetShortAtOffset12());

                FUN_0047e010(source9->GetStat());

                FUN_00401460(skills, source9->skills, 14);

                FUN_00401460(skillOffsets, source9->skillOffsets, 14);

                if (FUN_00461560())
                    reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))->SetFemale(true);

                else
                    reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                        ->SetFemale(source9->GetFemale());
            }

            if (FUN_0047cd40(2))
                CopyFactionRanks(source9);

            if (FUN_0047cd40(3))
            {

                spell.FUN_0048d630(source9 ? &source9->spell : 0);

                touch.FUN_0047bdd0(source9 ? &source9->touch : 0);
            }

            if (FUN_0047cd40(4))
                ai.FUN_0047f1e0(source9 ? &source9->ai : 0);

            if (FUN_0047cd40(5))
                ai.FUN_0047f2d0(source9 ? &source9->ai : 0);

            if (reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))->GetFemale())
                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->InitAttributesAndSkills(0);

            flags = 0;

            templateForm = FindFirstNonActorBaseTemplate(
                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix)), &flags);

            if (templateForm)
            {
                FUN_007037c0(templateForm);
                FUN_0047cd90(flags);
            }

            FUN_0047ccc0(true);
        }
    }
}

struct EqProcess
{
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
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void SetPaused(bool abPaused);
    virtual void v46C();
    virtual void Resume();
};
struct EqNode
{
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
    virtual void vBC();
    void FUN_00a5a040();
    void FUN_00a59c60(const struct EqUpdateData& kData);
};
struct EqUpdateData
{
    float fTime;
    int iUnk04;
    int iUnk08;
    EqUpdateData(float afTime, int aiUnk04, int aiUnk08);
};
struct EqRef
{
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
    virtual EqNode* Get3D();
};
struct EqActor : EqRef
{
    EqProcess* FUN_008d8520();
};
struct EqInventory
{
    void FUN_004ab250(int aiCount, bool abFlag);
    void UpdateBipedObjects(int aiFlag);
};
struct EqItemList
{
    unsigned int FUN_0044ddc0();
    int* FUN_006a7ad0(unsigned int auiIndex);
};
struct EqSimpleList
{
    int FUN_00726070();
};

struct FUN_00605e70_Owner
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
    int iFlags;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    EqSimpleList kList;

    void FUN_006061b0(EqRef* apRef, EqInventory* apInventory, int aiItem);
    void UpdateFaceGenHairVisibility(EqRef* apRef, int aiUnk);
    void ProcessInventoryItems(EqRef* apRef, EqInventory* apInventory, EqItemList* apItems);
};

// Applies the list count to the inventory, pauses the actor's process, processes each item, resumes the process, and updates the 3D node.
// @fnv 0x00605e70
void FUN_00605e70_Owner::ProcessInventoryItems(EqRef* apRef, EqInventory* apInventory, EqItemList* apItems)
{
    EqNode* pNode;
    EqActor* pActor6;
    unsigned int i4;
    int iItem7;

    apInventory->FUN_004ab250(kList.FUN_00726070(), (iFlags & 1) ? 1 : 0);
    pActor6 = static_cast<EqActor*>(apRef);
    if (pActor6 && pActor6->FUN_008d8520())
        pActor6->FUN_008d8520()->SetPaused(true);

    for (i4 = 0; i4 < apItems->FUN_0044ddc0(); i4++)
    {
        iItem7 = *apItems->FUN_006a7ad0(i4);
        FUN_006061b0(apRef, apInventory, iItem7);
    }

    UpdateFaceGenHairVisibility(apRef, 0);
    if (pActor6 && pActor6->FUN_008d8520())
        pActor6->FUN_008d8520()->Resume();

    apInventory->UpdateBipedObjects(1);
    pNode = apRef->Get3D();
    if (pNode)
    {
        pNode->FUN_00a5a040();
        pNode->vBC();
        EqUpdateData kData(0.0f, 0, 0);
        pNode->FUN_00a59c60(kData);
    }
}

// Additional call contracts and named object fields used by this routine.
struct FaceObject;
struct FaceCloneProcess
{
    void* cloneMap;
    void* processMap;
    void* stringMap;
    unsigned int copyType;
    float scale;
    unsigned int flags;
    void* context;
    FaceCloneProcess(float);
    ~FaceCloneProcess();
};
struct FaceGeometryData
{
    void FUN_00a5d510(NiPointer<NiAVObject>&);
};
struct FaceSkinData
{
    unsigned int FUN_008041a0();
};
class NiSkinInstance
{
  public:
    FaceObject* GetControllers() const;
    void SetBone(unsigned int, FaceObject*);
    void FUN_004addc0(NiSkinInstance*);
    FaceObject** FUN_00825c00();
    FaceSkinData* GetSkinData();
};
struct FaceExtraModel
{
    NiSkinInstance* FUN_006072c0();
};
struct FaceExtraData
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual FaceExtraModel* GetModelFilePath();
};
struct FaceObject
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual FaceObject* IsSceneNode();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual FaceObject* IsTriBasedGeom();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual FaceExtraModel* GetModelFilePath();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void UpdateAnimation(float, bool, bool, bool, bool, bool);
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void SetActive(bool);
    virtual void slot0d4();
    virtual void SetEnabled(bool, bool);
    virtual void AttachChildInAvailableSlot(FaceObject*, bool);
    virtual void slot0e0();
    virtual void SetGeometryData(NiAVObject*);
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual FaceObject* GetFaceAnimation();
    virtual void SetFaceAnimation(FaceObject*);
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void SetFlag114(bool);
    virtual void slot118();
    virtual void SetFlag11c(bool);
    virtual void slot120();
    virtual void slot124();
    virtual void AttachTo(FaceObject*, bool);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    TESObjectREFR* owner;
    unsigned int FUN_0043b480();
    FaceObject* GetAt(unsigned int);
    unsigned int FUN_00726070();
    FaceObject* FUN_00a5d2c0(FaceCloneProcess&);
    FaceGeometryData* FUN_005495f0();
    NiSkinInstance* FUN_0043fad0();
    FaceObject* FUN_0064c5a0();
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(const void*);
    void Update(const NiUpdateData&);
};
struct FacePointerCompare
{
    bool FUN_0052aa80(FaceObject*) const;
};
struct HeadBipedLookup
{
    FaceObject* FUN_004ab230(int);
};
struct HeadPlayerCheck
{
    bool FUN_00950b30(NiPointer<BipedAnim>*);
};
struct HeadRefCalls
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual int HasNodeA(FaceObject*);
    virtual int HasNodeB(FaceObject*);
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual ActorAnimData* GetAnimData();
};
struct HeadRaceCalls
{
    void CreateFaceGenNodes(FaceObject*&, FaceObject*&, TESNPC*, bool, bool, bool);
};
struct HeadMatrix
{
    float m[3][3];
    HeadMatrix();
};
int __cdecl FUN_00651b30();
bool __cdecl FUN_0043faf0();
void __cdecl AddObjectToPaletteRecursive(FaceObject*, NiControllerManager*);
struct HeadNPC : TESNPC
{
    void FUN_00606820(TESObjectREFR* ref, NiPointer<BipedAnim>* biped);
};

// Creates and attaches the NPC head and duplicate head face geometry to the biped head node, cloning face data and updating the face animation.
// @fnv 0x00606820
void HeadNPC::FUN_00606820(TESObjectREFR* ref, NiPointer<BipedAnim>* biped)
{
    NiPointer<NiAVObject> copiedData(0);
    if (FUN_00651b30() && (BipedAnim*)*biped && FUN_0043faf0() &&
        (ref != (TESObjectREFR*)DAT_011dea3c || !((HeadPlayerCheck*)DAT_011dea3c)->FUN_00950b30(biped)))
    {
        FaceObject* node1_2 = (FaceObject*)ref->Get3DSimple();
        FaceObject* aNode2 = 0;
        if (node1_2)
            aNode2 = node1_2->IsSceneNode();
        FaceObject* bipedNodeB = ((HeadBipedLookup*)biped)->FUN_004ab230(0);
        HeadMatrix a;
        NiControllerManager* p = 0;
        if (((HeadRefCalls*)ref)->GetAnimData() && ((HeadRefCalls*)ref)->GetAnimData()->FUN_00496940())
            p = ((HeadRefCalls*)ref)->GetAnimData()->FUN_00496940()->GetStringAtOffset();
        NiControllerManager* f = p;
        if (bipedNodeB && aNode2)
        {
            if (!((HeadRefCalls*)ref)->HasNodeA(bipedNodeB) && !((HeadRefCalls*)ref)->HasNodeB(bipedNodeB))
            {
                FaceObject* node9 = 0;
                FaceObject* bipedNodeVal = 0;
                FaceObject* nodeB = 0;
                NiPointer<NiAVObject> bipedNode_2(0);
                NiPointer<NiAVObject> aBipedNode(0);
                unsigned int count_2;
                unsigned int index4;
                FaceObject* node7_2;
                FaceObject* aNode5;
                if ((BSFaceGenNiNode*)m_pkPrimaryFaceGenNode)
                {
                    if ((BSFaceGenNiNode*)m_pkSecondaryFaceGenNode &&
                        ((FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)->FUN_00726070() <= 1)
                        node9 = (FaceObject*)(BSFaceGenNiNode*)m_pkPrimaryFaceGenNode;
                    else
                    {
                        FaceCloneProcess cloning(1.0f);
                        node9 = ((FaceObject*)(BSFaceGenNiNode*)m_pkPrimaryFaceGenNode)->FUN_00a5d2c0(cloning);
                    }
                    count_2 = node9->FUN_0043b480();
                    for (index4 = 0; index4 < count_2; index4++)
                    {
                        node7_2 = node9->GetAt(index4);
                        aNode5 = node7_2 ? node7_2->IsTriBasedGeom() : 0;
                        if (aNode5 && ((FacePointerCompare*)&m_pkPrimaryFaceGenNode)->FUN_0052aa80(node9))
                        {
                            aNode5->FUN_005495f0()->FUN_00a5d510(copiedData);
                            bipedNode_2 = (NiAVObject*)copiedData;
                            if ((NiAVObject*)bipedNode_2)
                                aNode5->SetGeometryData((NiAVObject*)bipedNode_2);
                        }
                    }
                    if (((FacePointerCompare*)&m_pkPrimaryFaceGenNode)->FUN_0052aa80(node9))
                    {
                        nodeB = node9->GetFaceAnimation()->FUN_0064c5a0();
                        if (nodeB)
                            node9->SetFaceAnimation(nodeB);
                    }
                }
                if ((BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)
                {
                    if (((FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)->FUN_00726070() <= 1)
                        bipedNodeVal = (FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode;
                    else
                    {
                        FaceCloneProcess cloning(1.0f);
                        bipedNodeVal = ((FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)->FUN_00a5d2c0(cloning);
                    }
                    count_2 = bipedNodeVal->FUN_0043b480();
                    for (index4 = 0; index4 < count_2; index4++)
                    {
                        node7_2 = bipedNodeVal->GetAt(index4);
                        aNode5 = node7_2 ? node7_2->IsTriBasedGeom() : 0;
                        if (aNode5)
                        {
                            if (((FacePointerCompare*)&m_pkSecondaryFaceGenNode)->FUN_0052aa80(bipedNodeVal))
                            {
                                aNode5->FUN_005495f0()->FUN_00a5d510(copiedData);
                                bipedNode_2 = (NiAVObject*)copiedData;
                                if ((NiAVObject*)bipedNode_2)
                                    aNode5->SetGeometryData((NiAVObject*)bipedNode_2);
                            }
                            if (aNode5->FUN_0043fad0() && aNode5->FUN_0043fad0()->GetControllers())
                            {
                                FaceExtraData* extra = (FaceExtraData*)GetGeomExtraData((NiTriBasedGeom*)aNode5);
                                if (extra && extra->GetModelFilePath() && extra->GetModelFilePath()->FUN_006072c0())
                                {
                                    NiSkinInstance* l = extra->GetModelFilePath()->FUN_006072c0();
                                    NiSkinInstance* k = aNode5->FUN_0043fad0();
                                    FaceObject** ba = l->FUN_00825c00();
                                    unsigned int b = l->GetSkinData()->FUN_008041a0();
                                    for (unsigned int j = 0; j < b; j++)
                                        k->SetBone(j, ba[j]);
                                }
                                else
                                {
                                    Warning(
                                        "MODELS: Could not correctly handle skinning for duplicate NPC \"%s\" (%08X).",
                                        GetName(), GetFormID());
                                }
                                ((FaceGeometryData*)aNode5->FUN_0043fad0()->GetControllers())->FUN_00a5d510(copiedData);
                                aBipedNode = (NiAVObject*)copiedData;
                                if ((NiAVObject*)aBipedNode)
                                    aNode5->FUN_0043fad0()->FUN_004addc0((NiSkinInstance*)(NiAVObject*)aBipedNode);
                            }
                        }
                    }
                    if (((FacePointerCompare*)&m_pkSecondaryFaceGenNode)->FUN_0052aa80(bipedNodeVal))
                    {
                        if (!nodeB)
                        {
                            nodeB = bipedNodeVal->GetFaceAnimation()->FUN_0064c5a0();
                            if (nodeB)
                                bipedNodeVal->SetFaceAnimation(nodeB);
                        }
                        else
                            bipedNodeVal->SetFaceAnimation(nodeB);
                    }
                }
                if (!(BSFaceGenNiNode*)m_pkPrimaryFaceGenNode && !(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode &&
                    GetFormRace())
                {
                    bool female = false;
                    ((HeadRaceCalls*)GetFormRace())
                        ->CreateFaceGenNodes(node9, bipedNodeVal, this, female, false, false);
                    m_usLastRace = GetFormRace()->FUN_00607350();
                    m_pkPrimaryFaceGenNode = (BSFaceGenNiNode*)node9;
                    m_pkSecondaryFaceGenNode = (BSFaceGenNiNode*)bipedNodeVal;
                }
                if (!node9 && !bipedNodeVal)
                    Warning("MODELS: Cannot create a head for an NPC (%d) (no race or bad race data).", GetFormID());
                if (node9)
                {
                    if (node9->GetFaceAnimation() && ref->GetHealth() <= 0.0)
                    {
                        node9->GetFaceAnimation()->SetEnabled(true, true);
                        node9->GetFaceAnimation()->SetActive(true);
                    }
                    node9->SetFlag114(true);
                    node9->SetFlag11c(true);
                    node9->FUN_00440460(NiPoint3_ZERO);
                    node9->FUN_0043fa80(&DAT_011a9448);
                    bipedNodeB->AttachChildInAvailableSlot(node9, true);
                    node9->owner = ref;
                    AddObjectToPaletteRecursive(node9, f);
                }
                if (bipedNodeVal)
                {
                    a = *(HeadMatrix*)&DAT_011a9448;
                    bipedNodeVal->SetFlag114(node9 == 0);
                    bipedNodeVal->SetFlag11c(node9 == 0);
                    bipedNodeVal->FUN_00440460(NiPoint3_ZERO);
                    aNode2->AttachChildInAvailableSlot(bipedNodeVal, true);
                    bipedNodeVal->owner = ref;
                    AddObjectToPaletteRecursive(bipedNodeVal, f);
                    bipedNodeVal->AttachTo(aNode2, true);
                }
                nodeB = node9 ? node9->GetFaceAnimation() : 0;
                if (!nodeB)
                    nodeB = bipedNodeVal ? bipedNodeVal->GetFaceAnimation() : 0;
                if (nodeB)
                    nodeB->UpdateAnimation(0.0f, true, true, true, true, false);
            }
            NiUpdateData update(0.0f, false, false);
            aNode2->Update(update);
        }
        else
            Warning("MODELS: Cannot create a head for an NPC (%d) that does not have a biped-head node.", GetFormID());
    }
}

struct FUN_00609d60_shell : public TESNPC
{
    void SerializeFaceGenData(int);
};

// @fnv 0x00609d60
void FUN_00609d60_shell::SerializeFaceGenData(int unused)
{
    unsigned int i2 = 0;
    for (; i2 < 2; ++i2)
    {
        unsigned int j = 0;
        for (; j < 2; ++j)
        {
            unsigned int rows = this->m_kFaceGenCoordinates[i2][j].FUN_009611e0();
            unsigned int cols = this->m_kFaceGenCoordinates[i2][j].FUN_00441110();
            unsigned int row = 0;
            for (; row < rows; ++row)
            {
                unsigned int col = 0;
                for (; col < cols; ++col)
                {
                    float value = *this->m_kFaceGenCoordinates[i2][j].FUN_0060b370(row, col).FUN_00629ab0();
                    ((PC7d*)this)->FUN_00484ce0((unsigned int)&value, 4);
                }
            }
        }
    }
    int hairID = 0;
    if (this->GetFormRace() != 0)
    {
        hairID = (int)this->GetFormRace()->GetFormID();
    }
    ((FUN_00484d20_Class*)this)->ForwardToSaveLoadGame(&hairID, 4);
    int raceID = 0;
    if (this->m_pHair != 0)
    {
        raceID = (int)this->m_pHair->GetFormID();
    }
    ((FUN_00484d20_Class*)this)->ForwardToSaveLoadGame(&raceID, 4);
    int eyeID = 0;
    if (this->m_pEyes != 0)
    {
        eyeID = (int)this->m_pEyes->GetFormID();
    }
    ((FUN_00484d20_Class*)this)->ForwardToSaveLoadGame(&eyeID, 4);
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&this->m_fHairLength, 4);
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&this->iHairColor, 4);
    unsigned char sex = 0;
    if (this->GetSex() == 1)
    {
        sex = 1;
    }
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&sex, 1);
}

struct BipedModelView : TESBipedModelForm
{
    const char* FUN_004811e0(int sex);
};
struct EnchantmentComponent : BaseFormComponent
{
    TESForm* enchantment;
    unsigned short charge;
    unsigned short castingType;
    unsigned int enchantmentFlags;
};
struct ValueComponent : BaseFormComponent
{
    int value;
};
struct WeightComponent : BaseFormComponent
{
    float weight;
};
struct ArmorModelView : TESObjectARMO
{
    TESFullName fullName;
    TESScriptableForm script;
    EnchantmentComponent enchantment;
    ValueComponent value;
    WeightComponent weight;
    TESHealthForm health;
    BipedModelView biped;
};
struct ModelPathView : TESModel
{
    virtual void vfn_10();
    virtual const char* GetModelPath();
};
struct WeaponModelView : TESObjectWEAP
{
    TESFullName fullName;
    ModelPathView model;
};
struct ContainerModelView : TESContainer
{
    ArmorModelView* FindBestArmorForSlot(TESActorBase*, int);
    WeaponModelView* FindBestRecord(TESActorBase*);
};
struct NPCModelView : TESBoundObject, TESActorBaseData, ContainerModelView
{
    BSSimpleList<const char*>* CollectModelPaths(bool armorModels, bool weaponModels);
};
// @fnv 0x0060af90
BSSimpleList<const char*>* NPCModelView::CollectModelPaths(bool armorModels, bool weaponModels)
{
    BSSimpleList<const char*>* models = new BSSimpleList<const char*>;
    if (armorModels)
    {
        BipedModelView* pBodyModel = 0;
        {
            int sex = reinterpret_cast<TESActorBase*>(this)->GetSex();
            {
                BipedModelView* apSlotModels[20];
                memset(apSlotModels, 0, sizeof(apSlotModels));
                for (int slot = 0; slot < 20; slot++)
                {
                    TESObjectARMO* unusedArmor = 0;
                    {
                        ArmorModelView* armor = FindBestArmorForSlot(reinterpret_cast<TESActorBase*>(this), slot);
                        if (armor && (!pBodyModel || !pBodyModel->HasBipedModel(slot, false, 0)) && !apSlotModels[slot])
                        {
                            apSlotModels[slot] = armor ? &armor->biped : 0;
                            if (apSlotModels[slot])
                            {
                                const char* pModelPath = apSlotModels[slot]->FUN_004811e0(sex);
                                if (pModelPath)
                                    models->AddHead(pModelPath);
                            }
                            if (slot == 2)
                                pBodyModel = apSlotModels[slot];
                        }
                    }
                }
            }
        }
    }
    if (weaponModels)
    {
        WeaponModelView* weapon = FindBestRecord(reinterpret_cast<TESActorBase*>(this));
        if (weapon)
        {
            ModelPathView* model = weapon ? &weapon->model : 0;
            if (model)
            {
                const char* pModelPath = model->GetModelPath();
                if (pModelPath)
                    models->AddHead(pModelPath);
            }
        }
    }
    return models;
}

struct IterPair
{
    unsigned int v0;
    unsigned int v1;
};

struct FoundPair
{
    unsigned int v0;
    unsigned int v1;
};

struct Facade410
{
    unsigned int v0;
    unsigned int v1;
    FoundPair FUN_0060b820(int index);
};

struct Vec410
{
    unsigned int FUN_00662820() const;
    IterPair& CallWithSelf(IterPair* out);
    void Insert(unsigned int, unsigned int, unsigned int, float const&);
    Facade410 FUN_0044a170();
    FoundPair FUN_0044a1a0(int, int, int, int);
    void FUN_0060b410(unsigned int level, float value);
};

// @fnv 0x0060b410
void Vec410::FUN_0060b410(unsigned int level, float value)
{
    if (FUN_00662820() < level)
    {
        IterPair beg;
        IterPair it = CallWithSelf(&beg);
        Insert(it.v0, it.v1, level - FUN_00662820(), value);
    }
    else if (level < FUN_00662820())
    {
        IterPair seek;
        IterPair res = CallWithSelf(&seek);
        FoundPair target;
        target = FUN_0044a170().FUN_0060b820(level);
        FUN_0044a1a0(target.v0, target.v1, res.v0, res.v1);
    }
}

extern "C" char DAT_011CB764;
extern "C" char DAT_01186424;
extern "C" char DAT_01183028;
extern "C" char DAT_0118627c;
extern "C" char DAT_0104a600;
struct H3370
{
    bool FUN_004013e0();
    bool FUN_00461580(int);
    void FUN_005ae3d0(void*);
    void FUN_0048cd90(void*);
    void FUN_00481bb0(void*);
    void FUN_0047f4c0(void*);
    void FUN_0048b920(void*);
    void FUN_0047d8b0(void*);
    void FUN_0048d400(void*);
    void FUN_0047beb0(void*);
    void FUN_00478be0(void*);
    void* FUN_00484e60(int);
    void InitAttributesAndSkills(bool);
    void* FUN_0084e3a0();
    unsigned FUN_00726070();
    void FUN_00565210(bool);
    float FUN_006041d0();
    void FUN_00484ab0(bool);
};
void __cdecl ResolveFormID(void*, void*);
TESForm* __cdecl LookupFormByID(void*);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
void __cdecl FUN_005b5e40(void*, void*, void*, void*);
struct C3370
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
    virtual void* v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual bool v81();
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
    virtual void* v98();
    virtual void v99(void*);
    char pad[0x12c];
    void* field130;
    char pad134[0xa0];
    void* field1d4;
    char pad1d8[0x1c];
    float field1f4;
    void FUN_00603370();
};
// @fnv 0x00603370
void C3370::FUN_00603370()
{
    C3370* c;
    void* a;
    void* b;
    if (((H3370*)this)->FUN_004013e0())
        return;
    if (((H3370*)((char*)this + 0x30))->FUN_00461580(4))
    {
        c = this;
        ((H3370*)&DAT_011CB764)->FUN_005ae3d0(&c);
    }
    ((H3370*)((char*)this + 0xf4))->FUN_0048cd90(this);
    ((H3370*)((char*)this + 0x64))->FUN_00481bb0(this);
    ((H3370*)((char*)this + 0x90))->FUN_0047f4c0(this);
    ((H3370*)((char*)this + 0x10c))->FUN_0048b920(this);
    ((H3370*)((char*)this + 0x30))->FUN_0047d8b0(this);
    ((H3370*)((char*)this + 0x7c))->FUN_0048d400(this);
    ((H3370*)((char*)this + 0x70))->FUN_0047beb0(this);
    ((H3370*)((char*)this + 0x104))->FUN_00478be0(this);
    if (field130)
    {
        a = field130;
        ResolveFormID(&a, ((H3370*)this)->FUN_00484e60(-1));
        field130 = dynamic_cast<TESClass*>(LookupFormByID(a));
    }
    if (v81())
        ((H3370*)this)->InitAttributesAndSkills(false);
    if (field1d4)
    {
        b = v98();
        if (b)
        {
            ResolveFormID(&b, ((H3370*)this)->FUN_00484e60(-1));
            field1d4 = dynamic_cast<TESCombatStyle*>(LookupFormByID(b));
            if (!field1d4)
                FUN_005b5e40(&DAT_0104a600, b, ((H3370*)this)->FUN_0084e3a0(), v76());
        }
    }
    if (!v98())
        v99(FUN_00505000());
    if (((H3370*)((char*)this + 0xb0))->FUN_00726070() <= 0)
        ((H3370*)this)->FUN_00565210(true);
    if (field1f4 == 0.0)
        field1f4 = ((H3370*)this)->FUN_006041d0();
    ((H3370*)this)->FUN_00484ab0(true);
}

class NPC_Helper : public TESNPC
{
  public:
    void InitAttributesAndSkills(bool arg1);
};

// @fnv 0x00603be0
void NPC_Helper::InitAttributesAndSkills(bool arg1)
{
    float level;
    level = 0.0f;
    if (!GetFormRace() || !m_pClass)
        return;

    bool i;
    i = false;
    if (GetFormID() == 7)
        i = true;

    bool s;
    s = true;
    if (i)
    {
        if (DAT_011d0e7c.Int()->i == GetClass()->GetFormID())
            s = false;
    }

    if (vfn_144())
    {
        ActorValue::Index luck;
        int z;
        for (z = 0; z < 7; ++z)
        {
            luck = ActorValue::GetActorValueForSectionIndex(ActorValue::Attributes, (unsigned char)z);
            if (s)
            {
                level = (float)GetClass()->classAttributes.GetAttributeValue(5 + z);
            }
            if (level > 10.0)
            {
                level = 10.0f;
            }
            SetAttributeValue(luck, (unsigned char)TruncateFloatToInt(level), false);
        }

        unsigned char res;
        res = GetAttributeValue(11);
        long tmp;
        tmp = ComputeIntelligenceResult(GetAttributeValue(9), true);
        long fRemainder;
        fRemainder = FUN_0047ded0();
        tmp = (fRemainder - 1) * tmp;
        int kIter;
        kIter = (arg1 ? 1 : 0) + 3;
        float q;
        q = (float)(FUN_00404040((float)tmp / kIter) * DAT_011cd6c0.Int()->i);
        float y;
        y = 0.0f;
        --kIter;

        long pObj;
        ActorValue::Index fPointsPerSkill;
        int j;
        for (pObj = 0; pObj < 14; ++pObj)
        {
            fPointsPerSkill = ActorValue::GetActorValueForSectionIndex(ActorValue::Skills, (unsigned char)pObj);
            if (!ActorValue::GetFlag(fPointsPerSkill, 0x2000))
            {
                if (ActorValue::IsSkill(fPointsPerSkill))
                {
                    level = 0.0f;
                    j = -1;
                    GetSkillAttributeAndBase(fPointsPerSkill, &j, &level);

                    level = AIFormulas::CalculateSkillValue(level, (float)attributes[j - 5], (float)res);

                    if (s && m_pClass)
                    {
                        if (m_pClass->IsTagSkill(fPointsPerSkill))
                        {
                            level += (q + y) + originalRuntimeFloatSetting327.Float()->f;
                            y = 0.0f;
                            if (level > 100.0)
                            {
                                y = level - 100.0;
                                if (!!kIter)
                                {
                                    y /= kIter;
                                }
                            }
                            --kIter;
                        }
                    }

                    if (level > 100.0)
                    {
                        level = 100.0f;
                    }
                    data.skills[pObj] = (unsigned char)TruncateFloatToInt(level);
                }
            }
        }

        if (m_pClass)
        {
            if (vfn_30())
            {
                SetServiceFlags(m_pClass->FUN_006286d0(), false);
            }
        }
        else
        {
            SetServiceFlags(0, false);
        }

        MarkAsModified(0x20c);
    }
}

namespace fnv_00606540 {
extern "C" char DAT_011846d4, DAT_011841cc, DAT_011dea3c;
struct Part
{
    bool a, b;
};
struct Count
{
    unsigned FUN_0044ddc0();
};
struct Extra
{
    char pad[32];
    Count count;
    Part* GetInfoAt(unsigned);
};
struct Extras
{
    Extra* FUN_0042e8c0();
};
template <int N> struct Slots : Slots<N - 1>
{
    virtual void slot(Slots<N>*);
};
template <> struct Slots<0>
{
};
struct Process : Slots<282>
{
    virtual void FUN_00606540_slot(bool);
};
struct Package
{
    bool FUN_00441b00();
};
struct Ref
{
    Process* FUN_008d8520();
    Extras* FUN_005d43c0();
    void* FUN_0043fcd0();
    Package* FUN_009344a0();
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
typedef FUN_004459e0 Item;
struct Inventory
{
    Item* FUN_004c8c10(int, int);
};
struct BipedData
{
    void* p;
    char pad[12];
};
struct Biped
{
    BipedData* FUN_00606800();
    void FUN_004ab250(void*);
};
struct Field
{
    void* FUN_00726070(int);
};
struct Player
{
    void* FUN_007af430();
    Biped* FUN_00950b00(bool);
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
Inventory* __cdecl FUN_004bf220(Ref*);
bool __cdecl FUN_004abfa0();
struct Shell
{
    char pad[52];
    unsigned flags;
    char pad2[212];
    Field field;
    bool FUN_005f1590(Ref*);
    void FUN_006047c0(Ref*, bool, bool, int, int);
    void FUN_00606820(Ref*, Biped*);
    void InitWornObjects(Ref*, Biped*);
    void UpdateFaceGenHairVisibility(Ref*, int);
    void FUN_00606540(Ref* ref, Biped* biped, bool force);
};
// @fnv 0x00606540
void Shell::FUN_00606540(Ref* ref, Biped* biped, bool force)
{
    if (biped)
    {
        if (!force)
        {
            for (unsigned i = 0; i < 20; ++i)
            {
                if (biped->FUN_00606800()[i].p)
                    return;
            }
        }
        biped->FUN_004ab250(field.FUN_00726070((flags & 1) ? 1 : 0));
    }
    Ref* actor = (Ref*)FUN_00ec43fb(ref, 0, &DAT_011841cc, &DAT_011846d4, 0);
    if (actor && actor->FUN_008d8520())
    {
        bool valid = true;
        Extra* extra = actor->FUN_005d43c0()->FUN_0042e8c0();
        if (extra && extra->count.FUN_0044ddc0() && extra->GetInfoAt(0))
        {
            for (unsigned j = 0; j < extra->count.FUN_0044ddc0(); ++j)
            {
                Part* part = extra->GetInfoAt(j);
                if (!part->a && part->b)
                    valid = false;
            }
        }
        if (valid)
        {
            actor->FUN_008d8520()->FUN_00606540_slot(true);
        }
    }
    if (!ref->FUN_0043fcd0() || force)
    {
        bool update = FUN_005f1590(ref) | force;
        if (this == (*(Player**)&DAT_011dea3c)->FUN_007af430())
        {
            Inventory* inv = FUN_004bf220(ref);
            if (inv)
            {
                for (int k = 0; k < 20; ++k)
                {
                    Item* item = inv->FUN_004c8c10(k, 0);
                    if (item)
                    {
                        update = false;
                        delete item;
                        item = 0;
                        break;
                    }
                }
            }
        }
        if (update)
        {
            bool package = true;
            Package* equip = actor->FUN_009344a0();
            if (equip && equip->FUN_00441b00())
                package = false;
            FUN_006047c0(ref, true, package, 0, 0);
        }
    }
    if (!FUN_004abfa0())
        FUN_00606820(ref, biped);
    InitWornObjects(ref, biped);
    bool other = true;
    if (biped == (*(Player**)&DAT_011dea3c)->FUN_00950b00(true))
        other = false;
    if (other)
        UpdateFaceGenHairVisibility(ref, 0);
}
}  // namespace fnv_00606540

struct TESNPC_Sub : public TESNPC
{
    void AttachHeadModels(TESObjectREFR* apRefr, BipedAnim* apBiped, BSFaceGenNiNode* apHeadBiped,
                          BSFaceGenNiNode* apHeadSkinned);
};

// @fnv 0x00607420
void TESNPC_Sub::AttachHeadModels(TESObjectREFR* apRefr, BipedAnim* apBiped, BSFaceGenNiNode* apHeadBiped,
                                  BSFaceGenNiNode* apHeadSkinned)
{
    BSFaceGenAnimationData* animData;
    NiAVObject* palette;
    animData = NULL;
    palette = apRefr->Get3DSimple();
    NiNode* a;
    a = NULL;
    if (palette)
    {
        a = palette->IsSceneNode();
    }
    NiNode* idx;
    idx = apBiped->GetBoneNode(BIPED_BONE_HEAD);
    NiControllerManager* f54;
    ThreeByThreeMatrix ptr;
    f54 = NULL;
    if (apRefr->GetAnimData() && apRefr->GetAnimData()->FUN_00496940())
    {
        f54 = apRefr->GetAnimData()->FUN_00496940()->GetStringAtOffset();
    }
    NiDefaultAVObjectPalette* val;
    val = (NiDefaultAVObjectPalette*)f54;

    if (idx && a)
    {
        if (apHeadBiped)
        {
            if (apHeadBiped->GetFaceGenAnimationData())
            {
                if (apRefr->GetHealth() <= 0.0)
                {
                    apHeadBiped->GetFaceGenAnimationData()->vfn_d8(true, true);
                    apHeadBiped->GetFaceGenAnimationData()->vfn_d0(true);
                }
            }
            apHeadBiped->vfn_114(true);
            apHeadBiped->vfn_11c(true);
            apHeadBiped->FUN_00440460(NiPoint3_ZERO);
            apHeadBiped->SetLocalRotation(*(const ThreeByThreeMatrix*)&DAT_011a9448);
            idx->AttachChildInAvailableSlot(apHeadBiped, true);
            AddObjectToPalette(apHeadBiped, val);
        }

        if (apHeadSkinned)
        {
            ptr = *(const ThreeByThreeMatrix*)&DAT_011a9448;
            apHeadSkinned->vfn_114(0 == apHeadBiped);
            apHeadSkinned->vfn_11c(apHeadBiped == 0);
            apHeadSkinned->FUN_00440460(NiPoint3_ZERO);
            a->AttachChildInAvailableSlot(apHeadSkinned, true);
            AddObjectToPalette(apHeadSkinned, val);
            apHeadSkinned->vfn_128(a, true);
        }

        animData = apHeadBiped ? apHeadBiped->GetFaceGenAnimationData() : NULL;
        if (0 == animData)
        {
            animData = apHeadSkinned ? apHeadSkinned->GetFaceGenAnimationData() : NULL;
        }

        if (animData)
        {
            animData->vfn_b4(0.0f, true, true, true, true, false);
            if (apRefr->IsActor())
            {
                Actor* pObj;
                pObj = (Actor*)apRefr;
                if (pObj->pFaceGenAnimationData)
                {
                    float v;
                    float obj3D;
                    float res;
                    ComputeAngleRange(&obj3D, &v);
                    ClampMinMaxFromSetting(&obj3D, &res);
                    pObj->pFaceGenAnimationData->FUN_00607830(res);
                    pObj->pFaceGenAnimationData->SetBoneMaxAngle(0, v);
                    FUN_00649fe0(&obj3D, &v);
                    GetEyeAngleLimits(&obj3D, &res);
                    pObj->pFaceGenAnimationData->SetSlotFloats(0, v, res);
                }
            }
        }

        this->m_pkPrimaryFaceGenNode = apHeadBiped;
        this->m_pkSecondaryFaceGenNode = apHeadSkinned;
        a->UpdateSceneObject();
        NiUpdateData updateData(0.0f, false, false);
        a->Update(updateData);
    }
    else
    {
        Warning("MODELS: Cannot create a head for an NPC (%d) that does not have a biped-head node.",
                this->GetFormID());
    }

    this->AttachHeadParts(apRefr, 0);
}

struct FloatInsertIterator
{
    void* owner;
    float* current;
};
struct FloatInsertAllocator
{
    unsigned int state;
    float* FUN_0044abd0(unsigned int count);
    void FUN_0064df10(float* first, unsigned int count);
};
struct FloatInsertVector
{
    unsigned int unk00;
    unsigned int unk04;
    FloatInsertAllocator allocator;
    float* first;
    float* last;
    float* end;
    unsigned int FUN_0060b860() const;
    unsigned int FUN_00662820() const;
    unsigned int FUN_0044a2c0() const;
    float* FUN_0060bb40(float*, float*, float*);
    float* FUN_0060b8a0(float*, unsigned int, const float&);
    void FUN_0065f2b0(float*, float*);
    void Insert(FloatInsertIterator where, unsigned int count, const float& value);
};
void __cdecl ThrowVectorTooLong();
void __cdecl FUN_0060bb70(float*, float*, const float&);
float* __cdecl FUN_0060bba0(float*, float*, float*);

// Inserts count copies of value at where, growing or reallocating the buffer when capacity is insufficient.
// @fnv 0x0060b4d0
void FloatInsertVector::Insert(FloatInsertIterator where, unsigned int count, const float& value)
{
    unsigned int capacity = FUN_0060b860();
    if (count == 0)
        ;
    else if (FUN_0044a2c0() - FUN_00662820() < count)
        ThrowVectorTooLong();
    else if (capacity < FUN_00662820() + count)
    {
        capacity = FUN_0044a2c0() - capacity / 2 < capacity ? 0 : capacity + capacity / 2;
        if (capacity < FUN_00662820() + count)
            capacity = FUN_00662820() + count;
        float* ptr = allocator.FUN_0044abd0(capacity);
        float* pWritePos = ptr;
        try
        {
            pWritePos = FUN_0060bb40(first, where.current, ptr);
            pWritePos = FUN_0060b8a0(pWritePos, count, value);
            FUN_0060bb40(where.current, last, pWritePos);
        }
        catch (...)
        {
            FUN_0065f2b0(ptr, pWritePos);
            allocator.FUN_0064df10(ptr, capacity);
            throw;
        }
        count += FUN_00662820();
        if (first != 0)
        {
            FUN_0065f2b0(first, last);
            allocator.FUN_0064df10(first, end - first);
        }
        end = ptr + capacity;
        last = ptr + count;
        first = ptr;
    }
    else if ((unsigned int)(last - where.current) < count)
    {
        float tmp = value;
        FUN_0060bb40(where.current, last, where.current + count);
        try
        {
            FUN_0060b8a0(last, count - (last - where.current), tmp);
        }
        catch (...)
        {
            FUN_0065f2b0(where.current + count, last + count);
            throw;
        }
        last += count;
        FUN_0060bb70(where.current, last - count, tmp);
    }
    else
    {
        float tmp = value;
        float* oldend = last;
        last = FUN_0060bb40(oldend - count, oldend, last);
        FUN_0060bba0(where.current, oldend - count, oldend);
        FUN_0060bb70(where.current, where.current + count, tmp);
    }
}

struct Flag75
{
    unsigned int value;
    bool FUN_004280f0();
};

struct Buffer75
{
    virtual unsigned char Version();
    Flag75 FUN_00428110(unsigned int);
    void FUN_00864980(void*, unsigned int);
    unsigned int FUN_008648a0();
    unsigned int FUN_00864a60();
    bool FUN_0042ce90();
};

TESForm* LookupFormByID(unsigned int);

struct Cell75
{
    int unk00, unk04;
    float* FUN_00629ab0();
};

struct Matrix75
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Matrix75();
    ~Matrix75();
    unsigned int FUN_009611e0();
    unsigned int FUN_00441110();
    Cell75 FUN_0060b370(unsigned int, unsigned int);
};

void FUN_006521f0(Matrix75 (*)[2]);

struct Race75
{
    int unk00, unk04;
    TESRace* FUN_00726070();
    void FUN_006ecd40(TESRace*);
};

struct Node75
{
    BGSHeadPart* item;
    Node75* next;
    BGSHeadPart*& FUN_006815c0();
    Node75* FUN_00726070();
    void FUN_00470470();
    void FUN_005ae3d0(BGSHeadPart* const&);
};

struct Saved75
{
    int unk00, unk04, unk08, unk0c, unk10;
    Saved75();
    ~Saved75();
    void FUN_007cb2e0(BGSHeadPart* const&);
    int FUN_00719b20(BGSHeadPart*&, int, bool (*)(BGSHeadPart*&, BGSHeadPart*&));
    void FUN_009a4320(int, int);
    unsigned int FUN_0044ddc0();
};

struct ActorData75
{
    int unk00;
    bool FUN_00461580(int);
    void FUN_0047dd50(int, bool, int);
};

struct NPC75
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

    ActorData75 actorData;

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

    int unkac;

    int unkb0;

    int unkb4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    int unkc8;

    int unkcc;

    int unkd0;

    int unkd4;

    int unkd8;

    int unkdc;

    int unke0;

    int unke4;

    int unke8;

    int unkec;

    int unkf0;

    int unkf4;

    int unkf8;

    int unkfc;

    int unk100;

    int unk104;

    int unk108;

    Race75 race;

    ActorSkillData skills;

    TESClass* npcClass;

    Matrix75 face[2][2];

    Matrix75 (*alternate)[2];

    TESHair* hair;

    float hairLength;

    TESEyes* eyes;

    int unk1c4;

    int unk1c8;

    int unk1cc;

    int unk1d0;

    int unk1d4;

    unsigned int hairColor;

    Node75 parts;

    int unk1e4;

    int unk1e8;

    TESRace* originalRace;

    int unk1f0;

    float height;

    void FUN_005f1fd0(Buffer75*);
    float FUN_006041d0();
    void FUN_005dd560();
    void FUN_005f20a0(unsigned char);
    void FUN_00609220(Buffer75*);
};

// Reads actor data, race, face matrices, hair, eyes, head parts, and sex from a save buffer, updating fields and marking changes.
// @fnv 0x00609220
void NPC75::FUN_00609220(Buffer75* buffer)
{

    FUN_005f1fd0(buffer);

    if (buffer->FUN_00428110(0x200).FUN_004280f0())
        buffer->FUN_00864980(&skills, 28);

    if (buffer->FUN_00428110(0x400).FUN_004280f0())
        npcClass = dynamic_cast<TESClass*>(LookupFormByID(buffer->FUN_008648a0()));

    unsigned char changed1 = 0;

    if (buffer->FUN_0042ce90())
        changed1 |= 0x1b;

    bool updateHeight27 = false;

    if (height == FUN_006041d0())
        updateHeight27 = true;

    if (buffer->FUN_00428110(0x2000000).FUN_004280f0())
    {

        TESRace* newRace = 0;

        newRace = dynamic_cast<TESRace*>(LookupFormByID(buffer->FUN_008648a0()));

        if (newRace != race.FUN_00726070())
        {
            race.FUN_006ecd40(newRace);
            changed1 |= 0x1b;
        }

        originalRace = dynamic_cast<TESRace*>(LookupFormByID(buffer->FUN_008648a0()));
    }

    if (updateHeight27)
        height = FUN_006041d0();

    if (buffer->FUN_00428110(0x800).FUN_004280f0())
    {

        bool useAlternate7 = false;

        buffer->FUN_00864980(&useAlternate7, 1);

        Matrix75(*coordinates20)[2] = face;

        if (useAlternate7)
        {
            if (!alternate)
            {
                alternate = (Matrix75(*)[2]) new Matrix75[4];
                FUN_006521f0(alternate);
            }
            coordinates20 = alternate;
        }

        for (unsigned int set = 0; set < 2; ++set)
        {

            for (unsigned int group = 0; group < 2; ++group)
            {

                unsigned int rows7 = coordinates20[set][group].FUN_009611e0();

                unsigned int cols2 = coordinates20[set][group].FUN_00441110();

                for (unsigned int row = 0; row < rows7; ++row)
                {

                    for (unsigned int col = 0; col < cols2; ++col)
                    {

                        float value = 0.0f;
                        buffer->FUN_00864980(&value, 4);

                        if (*coordinates20[set][group].FUN_0060b370(row, col).FUN_00629ab0() != value)
                        {

                            *coordinates20[set][group].FUN_0060b370(row, col).FUN_00629ab0() = value;
                            changed1 |= 8;
                        }
                    }
                }
            }
        }

        TESHair* oldHair4 = hair;
        TESEyes* oldEyes3 = eyes;
        float oldLength23 = hairLength;
        float oldColor22 = (float)hairColor;

        hair = dynamic_cast<TESHair*>(LookupFormByID(buffer->FUN_008648a0()));
        eyes = dynamic_cast<TESEyes*>(LookupFormByID(buffer->FUN_008648a0()));

        buffer->FUN_00864980(&hairLength, 4);
        buffer->FUN_00864980(&hairColor, 4);

        bool partsChanged41 = false;

        if (buffer->Version() >= 14)
        {

            Saved75 saved14;

            Node75* node17 = &parts;

            while (node17)
            {
                BGSHeadPart* part = node17->FUN_006815c0();
                if (part)
                    saved14.FUN_007cb2e0(part);
                node17 = node17->FUN_00726070();
            }

            parts.FUN_00470470();

            {

                unsigned int count33 = buffer->FUN_00864a60();

                for (unsigned int index = 0; index < count33; ++index)
                {
                    BGSHeadPart* part = 0;
                    part = dynamic_cast<BGSHeadPart*>(LookupFormByID(buffer->FUN_008648a0()));
                    if (part)
                        parts.FUN_005ae3d0(part);
                }

                node17 = &parts;

                while (node17)
                {

                    BGSHeadPart* part = node17->FUN_006815c0();

                    if (part)
                    {
                        int found = saved14.FUN_00719b20(part, 0, FUN_009a3830);
                        if (found == -1)
                        {
                            partsChanged41 = true;
                            break;
                        }
                        else
                            saved14.FUN_009a4320(found, 1);
                    }

                    node17 = node17->FUN_00726070();
                }

                if (saved14.FUN_0044ddc0())
                    partsChanged41 = true;
            }
        }

        if (partsChanged41 || oldHair4 != hair || oldEyes3 != eyes || oldLength23 != hairLength ||
            oldColor22 != hairColor)
            changed1 |= 8;
    }

    if (buffer->FUN_00428110(0x1000000).FUN_004280f0())
    {

        bool sex = false;
        buffer->FUN_00864980(&sex, 1);

        if (actorData.FUN_00461580(1) != sex)
        {
            actorData.FUN_0047dd50(1, sex, 1);
            changed1 |= 0x1b;
        }
    }

    if (changed1 & 8)
        FUN_005dd560();

    if (changed1)
        FUN_005f20a0(changed1);
}

class Shell_00608f00_Flags
{
  public:
    unsigned int flags;
    Shell_00608f00_Flags();
    bool Test(unsigned int);
};
class BGSSaveFormBuffer
{
  public:
    Shell_00608f00_Flags FUN_00428110();
    void FUN_00865e50(void*, unsigned int, int);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
class Shell_00608f00_Buf
{
  public:
    void FUN_00865df0(void*, int);
};
class Shell_00608f00_Base
{
  public:
    void FUN_005f1f30(unsigned int);
};
class Shell_00608f00_Row
{
  public:
    float& FUN_00629ab0(unsigned int);
};
struct Shell_00608f00_RowVal : public Shell_00608f00_Row
{
    unsigned int a, b;
    Shell_00608f00_RowVal();
};
class Shell_00608f00_Mat
{
  public:
    Shell_00608f00_RowVal FUN_0060b370(int);
};
class Shell_00608f00_Item
{
  public:
    Shell_00608f00_Item();
};
struct Shell_00608f00_Node;
Shell_00608f00_Node* __fastcall FUN_00726070(Shell_00608f00_Node*);
class Shell_00608f00_Flag
{
  public:
    bool GetFlag(unsigned int) const;
};

class Shell_00608f00_NPC : public TESNPC
{
  public:
    void FUN_00608f00(BGSSaveFormBuffer* apFile);
};

// Writes NPC data to the buffer, including face coordinates, hair, eyes, head parts, and selected flag state.
// @fnv 0x00608f00
void Shell_00608f00_NPC::FUN_00608f00(BGSSaveFormBuffer* apFile)
{
    ((Shell_00608f00_Base*)this)->FUN_005f1f30((unsigned int)apFile);
    if (apFile->FUN_00428110().Test(0x200))
        apFile->FUN_00865e50(&data, 0x1c, 0);
    if (apFile->FUN_00428110().Test(0x400))
        ((Shell_00608f00_Buf*)apFile)->FUN_00865df0(m_pClass, 0);
    if (apFile->FUN_00428110().Test(0x2000000))
    {
        Shell_00608f00_Node* pRace = ::FUN_00726070((Shell_00608f00_Node*)((char*)this + 0x10c));
        ((Shell_00608f00_Buf*)apFile)->FUN_00865df0(pRace, 0);
        ((Shell_00608f00_Buf*)apFile)->FUN_00865df0(m_pAssignedRace, 0);
    }
    if (apFile->FUN_00428110().Test(0x800))
    {
        bool a = false;
        FaceGenMatrix<float>(*pCoord)[2] = m_kFaceGenCoordinates;
        if (m_pOffsetFaceCoordinates)
        {
            pCoord = m_pOffsetFaceCoordinates;
            a = true;
        }
        apFile->FUN_00865e50(&a, 1, 0);
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                unsigned int uiRows = pCoord[i][j].FUN_009611e0();
                unsigned int cols = pCoord[i][j].FUN_00441110();
                for (unsigned int k = 0; k < uiRows; k++)
                {
                    for (unsigned int l = 0; l < cols; l++)
                    {
                        float fValue = ((Shell_00608f00_Mat*)&pCoord[i][j])->FUN_0060b370(k).FUN_00629ab0(l);
                        apFile->FUN_00865e50(&fValue, 4, 0);
                    }
                }
            }
        }
        ((Shell_00608f00_Buf*)apFile)->FUN_00865df0(m_pHair, 0);
        ((Shell_00608f00_Buf*)apFile)->FUN_00865df0(m_pEyes, 0);
        apFile->FUN_00865e50(&m_fHairLength, 4, 0);
        apFile->FUN_00865e50(&iHairColor, 4, 0);
        {
            int iNumParts = 0;
            unsigned int uiElapsedMilliseconds = apFile->FUN_00865f20();
            Shell_00608f00_Node* pIter = (Shell_00608f00_Node*)&m_kHeadPartList;
            while (pIter)
            {
                BGSHeadPart* pHeadPart =
                    *(BGSHeadPart**)&((Shell_00608f00_Item*)pIter)->Shell_00608f00_Item::Shell_00608f00_Item();
                if (pHeadPart)
                {
                    ((Shell_00608f00_Buf*)apFile)->FUN_00865df0(pHeadPart, 0);
                    iNumParts++;
                }
                pIter = ::FUN_00726070(pIter);
            }
            apFile->FUN_00865ff0(iNumParts, uiElapsedMilliseconds);
        }
    }
    if (apFile->FUN_00428110().Test(0x1000000))
    {
        bool bFlag = ((Shell_00608f00_Flag*)((char*)this + 0x30))->GetFlag(1);
        apFile->FUN_00865e50(&bFlag, 1, 0);
    }
}

// Furniture marker entry returned by BaseProcess::GetFurnitureMarkerData().
class FurnitureMark
{
  public:
    float fX, fY, fZ;
    unsigned short usHeading;
    unsigned char cMarkerType;
};

// Dialogue package (RTTI .?AUDialoguePackage@@); its topic lives at TESPackage::pTopic.
struct DialoguePackage : public TESPackage
{
};

// Actor queries the pack does not declare.
class ActorQueries : public Actor
{
  public:
    bool IsFleeingFrom(bool abCheck);
    bool IsInCombat();
};
class PlayerActivationQueries : public PlayerCharacter
{
  public:
    bool FUN_00894d60();
};

int __fastcall GetActorKnockState(Actor* apActor);
unsigned char __fastcall GetCalendarDay(Calendar* apCalendar);
void __fastcall SetProcessLastTimeProcessed(BaseProcess* apProcess, float afHour);
BSSimpleList<Actor*>* __fastcall GetScheduleListNext(BSSimpleList<Actor*>* apList);
bool __fastcall GetPackageDialogueNoHeadtrack(TESPackage* apPackage);

// TESNPC::Activate (vtable slot 73).
class TESNPCActivate : public TESNPC
{
  public:
    bool FUN_00607990(TESObjectREFR* apTargetRef, TESObjectREFR* apActivatorRef, bool abIsItem,
                      TESBoundObject* apObjectToGet, int aiCount);
};

// Handles NPC activation by checking combat, health, and dialogue conditions, then opening menus or transferring items between actors.
// @fnv 0x00607990
bool TESNPCActivate::FUN_00607990(TESObjectREFR* apTargetRef, TESObjectREFR* apActivatorRef, bool abIsItem,
                                  TESBoundObject* apObjectToGet, int aiCount)
{
    Actor* pActivator = dynamic_cast<Actor*>(apActivatorRef);
    Actor* pTarget = dynamic_cast<Actor*>(apTargetRef);
    if (!pTarget || pTarget->GetIsDying())
        return false;

    BaseProcess* pProcess = pTarget->GetProcess();
    if (!pProcess)
        return false;
    if (pProcess && pProcess->GetCurrentTalkTarget() && !pTarget->HasHealth(false))
        return false;
    if (pProcess && pProcess->GetCurrentFadeState())
        return false;

    TESPackage* pActivatorPackage = pActivator->GetProcess()->GetOneTimePackage();
    TESPackage* pTargetCurrentPackage = pProcess->GetOneTimePackage();
    char szLine[300];

    if (pTarget == g_thePlayer && g_thePlayer->bPreventActivation)
    {
        if (pTarget->IsGuard() && pTarget->IsInDeadState())
            SetProcessLastTimeProcessed(pProcess, g_calendar.GetGameTime() - 1.0);
        return false;
    }

    if (!pTarget->HasHealth(false) || GetActorKnockState(pTarget) == 6)
    {
        if (pTarget->FUN_00437bd0() || pTarget->GetHasKnockedState() || GetActorKnockState(pTarget) == 6)
        {
            sprintf(szLine, "%s %s", pTarget->GetFullName(), DAT_011d210c.IsContentAvailable());
            ShowMessage(szLine, 0, "Interfac\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds", 0, 2.0f,
                        false);
            return false;
        }
        else if (static_cast<ActorQueries*>(pTarget)->IsFleeingFrom(false))
        {
            CombatController* m_pCombatController = pTarget->GetCombatController();
            if (!m_pCombatController || !m_pCombatController->SetActive(g_thePlayer) ||
                static_cast<PlayerActivationQueries*>(g_thePlayer)->FUN_00894d60())
            {
                sprintf(szLine, "%s %s", pTarget->GetFullName(), DAT_011d2538.IsContentAvailable());
                ShowMessage(szLine, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0, 2.0f,
                            false);
                return false;
            }
        }
    }

    if (pTarget->IsPlayerTeammate() && apActivatorRef == g_thePlayer)
    {
        if (FUN_00754d90(pTarget))
            OpenDialogueMenu(8, apTargetRef, 0, 0, 0, false);
        return false;
    }

    if (pActivator)
    {
        TESPackage* pPackage = pActivator->GetExtraData()->GetPackageOverride();
        if (pActivator != g_thePlayer && pPackage && pPackage->GetPackType() == 15)
        {
            ExtraDataList* pTargetExtra = pTarget->GetExtraData();
            pActivator->GetExtraData()->SetPackageOverride(pPackage, 4, pTargetExtra->GetTalkingActor(), true, true,
                                                           false);
            if (pPackage->IsMustReachLocation())
                pActivator->SetExtraRunOncePacks(pPackage, GetCalendarDay(&g_calendar));
            pTarget->GetProcess()->OnPackageEnd(pActivator, pPackage);
            pTarget->MarkAsModified(0x80000000);
        }
        if (pActivator != g_thePlayer && pActivator->GetProcess())
            pActivator->GetProcess()->SetProcessConditionMet(true);

        if (static_cast<ActorQueries*>(pTarget)->IsInCombat() && pActivator == g_thePlayer &&
            pTarget->IsPlayerTeammate())
        {
            DAT_011f2250.SetEquipmentState(0, 0);
            OpenDialogueMenu(4, pTarget, 0, 0, 1, false);
        }
        else if (pTarget && (!static_cast<ActorQueries*>(pTarget)->IsInCombat() || pTarget->GetHasKnockedState()) &&
                 (pActivator != g_thePlayer || !pTarget->GetSitSleepState() || pTarget->GetSitSleepState() == 9 ||
                  pTarget->GetSitSleepState() == 4 ||
                  (pTarget->GetProcess()->GetFurnitureMarkerData() &&
                   pTarget->GetProcess()->GetFurnitureMarkerData()->cMarkerType > 19)))
        {
            if (pTarget->FUN_00608d80())
                return false;

            if (!pTarget->HasHealth(false))
            {
                int iAttackReason = 0;
                if (!pTarget->FUN_00437bf0() && !pTarget->GetIsParalyzed())
                {
                    if (pActivator != g_thePlayer && pActivator->IsHostileToActor(pTarget, 0, &iAttackReason, false))
                    {
                        if (pActivator->GetProcess()->ShouldAttackTarget(pActivator, pTarget, false, true, 0, false,
                                                                         false, true, 0, false, false, true, 0))
                            return true;
                    }
                    else if (!pTarget->IsGuard() && pTarget->IsHostileToActor(pActivator, 0, &iAttackReason, false) &&
                             !pActivator->IsSneaking())
                    {
                        if (pTarget->GetProcess()->ShouldAttackTarget(pTarget, pActivator, true, true, 0, false, false,
                                                                      true, 0, false, false, true, 0))
                            return true;
                    }
                }

                if (pActivator == g_thePlayer && pTarget->GetHasKnockedState() && pTarget->IsEssentialActor())
                {
                    return false;
                }
                else if (pActivator == g_thePlayer ||
                         (pTarget == g_thePlayer && (pActivator->GetCurrentPackage()->IsPackageBlockingGreeting() ||
                                                     !pActivator->GetCurrentPackage()->GetPackType() ||
                                                     pActivator->GetCurrentPackage()->GetPackType() == 9)))
                {
                    if (pActivator == g_thePlayer &&
                        (pTarget->GetHasKnockedState() ||
                         (g_thePlayer->IsSneaking() && !pTarget->IsPlayerTeammate())) &&
                        !pTarget->GetGhost())
                    {
                        if (!pTarget->GetHasKnockedState() && pTarget->GetProcess()->HasCaughtPlayerPickpocketing())
                        {
                            sprintf(szLine, "%s %s", pTarget->GetFullName(), DAT_011d2394.IsContentAvailable());
                            ShowMessage(szLine, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                                        2.0f, false);
                            return false;
                        }
                        else
                        {
                            OpenDialogueMenu(1, apTargetRef, 0, 0, 2, false);
                        }
                    }
                    else
                    {
                        TESTopic* pTopic = 0;
                        if (pActivator == g_thePlayer || pActivator->GetProcess()->IsCurrentlyDetected())
                            pTopic = TESTopic::GetAudioBackendData(0, 0);
                        DialogueItem* pDialogueItem = 0;
                        if (pTopic)
                        {
                            if (pActivator == g_thePlayer)
                                pDialogueItem = pTopic->CreateDialogueItem(pTarget, g_thePlayer, 0, 0, false);
                            else if (pActivator->GetProcess()->IsCurrentlyDetected())
                                pDialogueItem = pTopic->CreateDialogueItem(pActivator, g_thePlayer, 0, 0, false);
                        }
                        if (pDialogueItem && pDialogueItem->Deallocate()->IsRemappedRumors() &&
                            pDialogueItem->SelectDefaultResponseList() && !pDialogueItem->NextResponse())
                        {
                            if (pTarget->GetSitSleepState() == 9)
                            {
                                pTarget->GetProcess()->SetCombatState(true);
                                pTarget->InitGetUpPackage();
                                return true;
                            }
                            else if (pTarget == g_thePlayer)
                            {
                                pActivator->SetReferenceState(pTopic, false, false);
                            }
                            else
                            {
                                pTarget->SetReferenceState(pTopic, false, false);
                            }
                        }
                        else
                        {
                            if (pTarget->GetProcess()->GetFurnitureMarkerData() &&
                                pTarget->GetProcess()->GetFurnitureMarkerData()->cMarkerType > 19)
                                pTarget->GetProcess()->AddPostAnimAction(0x200);
                            if (!pTarget->GetSitSleepState())
                                pTarget->SetReferenceHeading(*pActivator->GetPos(), false);

                            TESTopic* pMenuTopic = 0;
                            TESObjectREFR* pDialogueReference = 0;
                            if (pActivator == g_thePlayer)
                            {
                                if (!pTarget->HasEssentialStatus() && !pTarget->IsMovementActive())
                                    pTarget->GetProcess()->StopActorMovement(pTarget);
                                pActivator->FUN_008a8e50();
                                pTarget->FUN_008a8e50();
                                DialoguePackage* pDialoguePackage =
                                    dynamic_cast<DialoguePackage*>(pActivator->GetCurrentPackage());
                                if (pDialoguePackage)
                                    pMenuTopic = pDialoguePackage->pTopic;
                                pDialogueReference = apTargetRef;
                                if (pTarget->GetCurrentTarget() == g_thePlayer && pTargetCurrentPackage &&
                                    !pTargetCurrentPackage->GetPackType())
                                {
                                    if (pTargetCurrentPackage->FUN_0041d8a0() &&
                                        !GetScheduleListNext(pTargetCurrentPackage->FUN_0041d8a0()))
                                        pProcess->SetProcessTarget(pActivator, 2);
                                    else
                                        pProcess->SetProcessTarget(pTarget, 1);
                                }
                                BSAudio::GetSingleton()->SetAudioState(4);
                                pTarget->RemoveCastingArt();
                                if (pTarget->GetSitSleepState() != 9)
                                {
                                    TESObjectREFR* pMenuOwner = pActivator;
                                    if (pMenuOwner == g_thePlayer)
                                        pMenuOwner = pTarget;
                                    DAT_011f2250.SetEquipmentState(0, 0);
                                    OpenDialogueMenu(4, pMenuOwner, pMenuTopic, 0, 1, false);
                                }
                                else
                                {
                                    pTarget->GetProcess()->SetCombatState(true);
                                    pTarget->InitGetUpPackage();
                                }
                            }
                            else if (FUN_00702640() != 0x3f1)
                            {
                                if (!g_thePlayer->GetProcess()->IsAimingAtActor(pActivator))
                                    return false;
                                BSAudio::GetSingleton()->SetAudioState(4);
                                pActivator->FUN_008a8e50();
                                pTarget->FUN_008a8e50();
                                pDialogueReference = pActivator;
                                if (!static_cast<ActorQueries*>(pActivator)->IsInCombat())
                                {
                                    DialoguePackage* pActivatorDialogue =
                                        dynamic_cast<DialoguePackage*>(pActivator->GetCurrentPackage());
                                    if (pActivatorDialogue)
                                        pMenuTopic = pActivatorDialogue->pTopic;
                                }
                                if (pActivatorPackage->FUN_0041d8a0() &&
                                    !GetScheduleListNext(pActivatorPackage->FUN_0041d8a0()))
                                    pActivator->GetProcess()->SetProcessTarget(pActivator, 2);
                                else
                                    pActivator->GetProcess()->SetProcessTarget(pActivator, 1);
                                pTarget->RemoveCastingArt();
                                if (pTarget == g_thePlayer)
                                    pTarget->FUN_008a7a90();
                                else
                                    pTarget->GetProcess()->AddPostAnimAction(0x400);
                                if (pActivator == g_thePlayer)
                                    pActivator->FUN_008a7a90();
                                else
                                    pActivator->GetProcess()->AddPostAnimAction(0x400);
                                DAT_011f2250.SetEquipmentState(0, 0);
                                TESObjectREFR* m_pDialogueSpeaker = pActivator;
                                if (m_pDialogueSpeaker == g_thePlayer)
                                    m_pDialogueSpeaker = pTarget;
                                OpenDialogueMenu(4, m_pDialogueSpeaker, pMenuTopic, 0, 1, false);
                            }
                        }
                        delete pDialogueItem;
                    }
                }
                else
                {
                    if (apObjectToGet)
                    {
                        TESNPC* pNPC = dynamic_cast<TESNPC*>(apObjectToGet);
                        if (!pNPC)
                        {
                            pTarget->RemoveItem(apObjectToGet, 0, aiCount, true, 0, pActivator, 0, 0, true, false);
                            pActivator->InitializeReference(pTarget, apObjectToGet, aiCount);
                            return true;
                        }
                    }
                    if (pActivator->GetCurrentPackage()->GetPackType() == 2)
                    {
                        pActivator->GetProcess()->SetProcessTarget(pActivator, 2);
                    }
                    else
                    {
                        if (pActivator->GetCurrentPackage() && pActivator->GetCurrentPackage()->GetPackType() != 1)
                            pActivator->GetProcess()->SetProcessTarget(pActivator, 1);
                        if (pTarget != g_thePlayer)
                        {
                            if (pTarget != pActivator && pTarget->GetCurrentPackage() &&
                                pTarget->GetCurrentPackage()->GetPackType() != 1 &&
                                pTarget->GetCurrentPackage()->GetPackType() != 2)
                                pProcess->SetProcessTarget(pTarget, 1);
                            if (pTarget != pActivator && !pTarget->GetSitSleepState())
                            {
                                if (pActivator->IsCombatStateActive())
                                {
                                    TESPackage* pDialoguePkg = pActivator->GetCurrentPackage();
                                    if (!GetPackageDialogueNoHeadtrack(pDialoguePkg) && !pDialoguePkg->FUN_006727b0())
                                        pTarget->SetReferenceHeading(*pActivator->GetPos(), false);
                                }
                                else
                                {
                                    pTarget->SetReferenceHeading(*pActivator->GetPos(), false);
                                }
                            }
                            if (!pActivator->IsCombatStateActive() && pActivator->IsCharacter() && pTarget->IsCharacter())
                            {
                                pActivator->GetProcess()->SetProcessTarget(pActivator, 1);
                                if (pActivator->vfn_280(pTarget, 0, 0, 1, 0, 0, 0, 0, 0))
                                {
                                    pActivator->GetProcess()->SetProcessTarget(pActivator, 2);
                                    pProcess->SetProcessTarget(pTarget, 2);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (pActivator == g_thePlayer)
                {
                    OpenDialogueMenu(1, apTargetRef, 0, 0, 1, false);
                }
                else if (apObjectToGet)
                {
                    TESNPC* pObjectNPC = dynamic_cast<TESNPC*>(apObjectToGet);
                    if (!pObjectNPC)
                        apTargetRef->RemoveItem(apObjectToGet, 0, aiCount, false, 0, pActivator, 0, 0, true, false);
                }
            }
        }
        else if (pTarget && pTarget->GetCombatController() && pActivator == g_thePlayer &&
                 pTarget->GetCombatController()->GetLoading())
        {
            char szMessage[200];
            sprintf(szMessage, "%s %s", TESFullName::GetFullName(), DAT_011cf594.IsContentAvailable());
            ShowMessage(szMessage, 0, 0, 0, 2.0f, false);
            return false;
        }
        return true;
    }
    return false;
}
