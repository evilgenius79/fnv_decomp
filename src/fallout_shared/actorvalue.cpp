// fallout_shared/actorvalue.cpp: ActorValue, ActorValueInfo, ActorValueOwner, TESObjectWEAP and more (38 functions)

#include "actorvalue_decls.h"

// Registers all built-in actor values with their flags and callbacks, sets enumerated names for AI attributes, then marks DAT_011d6154 as initialized.
// @fnv 0x0066f260
void ActorValue::LoadActorValueDefinitions()
{
    if (DAT_011d6154)
        return;
    ActorValueInfo* info;
    RegisterActorValue(ActorValue__Index_AGGRESSION, "Aggression", AI_ATTRIBUTE, 0x101, 0x0, 0x0, FUN_008ba140, 0x0);
    info = GetActorValueInfo(ActorValue__Index_AGGRESSION);
    if (info)
        info->SetEnumerated(4, "Unaggressive", "Aggressive", "Very Aggressive", "Frenzied");
    RegisterActorValue(ActorValue__Index_ASSISTANCE, "Assistance", AI_ATTRIBUTE, 0x101, 0x0, 0x0,
                       SetProcessFlagIfActive, 0x0);
    info = GetActorValueInfo(ActorValue__Index_ASSISTANCE);
    if (info)
        info->SetEnumerated(3, "Helps Nobody", "Helps Allies", "Helps Friends and Allies");
    RegisterActorValue(ActorValue__Index_CONFIDENCE, "Confidence", AI_ATTRIBUTE, 0x101, 0x0, 0x0, 0x0, 0x0);
    info = GetActorValueInfo(ActorValue__Index_CONFIDENCE);
    if (info)
        info->SetEnumerated(5, "Cowardly", "Cautious", "Average", "Brave", "Foolhardy");
    RegisterActorValue(ActorValue__Index_ENERGY, "Energy", AI_ATTRIBUTE, 0x1, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_RESPONSIBILITY, "Responsibility", AI_ATTRIBUTE, 0x1, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_MOOD, "Mood", AI_ATTRIBUTE, 0x101, 0x0, 0x0, 0x0, 0x0);
    info = GetActorValueInfo(ActorValue__Index_MOOD);
    if (info)
        info->SetEnumerated(9, "Neutral", "Afraid", "Annoyed", "Cocky", "Drugged", "Pleasant", "Angry", "Sad",
                            "UNDEFINED");
    RegisterActorValue(ActorValue__Index_STRENGTH, "Strength", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0xd, 0x26, 0x11);
    RegisterActorValue(ActorValue__Index_PERCEPTION, "Perception", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0x22, 0x24,
                       0x23);
    RegisterActorValue(ActorValue__Index_ENDURANCE, "Endurance", ATTRIBUTE, 0x8009, 0x0, 0x0, FUN_008b9ea0, 0x7, 0x10,
                       0xf, 0x13, 0x14, 0x21, 0x2d, 0x2c);
    RegisterActorValue(ActorValue__Index_CHARISMA, "Charisma", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x2, 0x20, 0x2b);
    RegisterActorValue(ActorValue__Index_INTELLIGENCE, "Intelligence", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0x28,
                       0x27, 0x25);
    RegisterActorValue(ActorValue__Index_AGILITY, "Agility", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0xc, 0x29, 0x2a);
    RegisterActorValue(ActorValue__Index_LUCK, "Luck", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0xf, 0xe, 0x20, 0x21, 0x22,
                       0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2d, 0x2c);
    RegisterActorValue(ActorValue__Index_ACTION_POINTS, "ActionPoints", DERIVED_ATTRIBUTE, 0x0, FUN_006439d0, 0x0, 0x0,
                       0x0);
    RegisterActorValue(ActorValue__Index_CARRY_WEIGHT, "CarryWeight", DERIVED_ATTRIBUTE, 0x801, FUN_00643a10, 0x0, 0x0,
                       0x0);
    RegisterActorValue(ActorValue__Index_CRITICAL_CHANCE, "CritChance", DERIVED_ATTRIBUTE, 0x800, FUN_00643b10, 0x0,
                       0x0, 0x0);
    RegisterActorValue(ActorValue__Index_HEALING_RATE, "HealRate", DERIVED_ATTRIBUTE, 0x801, FUN_00643a70, 0x0,
                       FUN_008b9db0, 0x0);
    RegisterActorValue(ActorValue__Index_HEALTH, "Health", DERIVED_ATTRIBUTE, 0x10c1, FUN_00643670, 0x0,
                       UpdateActorValueFlag, 0x0);
    RegisterActorValue(ActorValue__Index_MELEE_DAMAGE, "MeleeDamage", DERIVED_ATTRIBUTE, 0x800, FUN_00643b50, 0x0, 0x0,
                       0x0);
    RegisterActorValue(ActorValue__Index_DAMAGE_RESISTANCE, "DamageResist", RESISTANCE, 0x800, FUN_008a0a90, 0x0,
                       FUN_008ba270, 0x0);
    RegisterActorValue(ActorValue__Index_POISON_RESISTANCE, "PoisonResist", RESISTANCE, 0x800, FUN_00643e40, 0x0, 0x0,
                       0x0);
    RegisterActorValue(ActorValue__Index_RADIATION_RESISTANCE, "RadResist", RESISTANCE, 0x800, FUN_00643e40, 0x0,
                       FUN_008ba2b0, 0x0);
    RegisterActorValue(ActorValue__Index_FIRE_RESISTANCE, "FireResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_ELECTRICAL_RESISTANCE, "ElectricResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_FROST_RESISTANCE, "FrostResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_ENERGY_RESISTANCE, "EnergyResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_EMP_RESISTANCE, "EmpResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_SPEED_MULT, "SpeedMult", DERIVED_ATTRIBUTE, 0x801, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_FATIGUE, "Fatigue", DERIVED_ATTRIBUTE, 0x1841, FUN_00643820, 0x0,
                       UpdateActorValueFlag, 0x0);
    RegisterActorValue(ActorValue__Index_PERCEPTION_CONDITION, "PerceptionCondition", SPECIAL, 0x821, FUN_00643a50, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_ENDURANCE_CONDITION, "EnduranceCondition", SPECIAL, 0x821, FUN_00643a50, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_LEFT_ATTACK_CONDITION, "LeftAttackCondition", SPECIAL, 0x821, FUN_00643a50,
                       0x0, Actor::UpdateActorConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_RIGHT_ATTACK_CONDITION, "RightAttackCondition", SPECIAL, 0x821, FUN_00643a50,
                       0x0, Actor::UpdateActorConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_LEFT_MOBILITY_CONDITION, "LeftMobilityCondition", SPECIAL, 0x821, FUN_00643a50,
                       0x0, Actor::UpdateMobilityConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_RIGHT_MOBILITY_CONDITION, "RightMobilityCondition", SPECIAL, 0x821,
                       FUN_00643a50, 0x0, Actor::UpdateMobilityConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_BRAIN_CONDITION, "BrainCondition", SPECIAL, 0x820, FUN_00643a50, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_KARMA, "Karma", DERIVED_ATTRIBUTE, 0x4000, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_EXPERIENCE_POINTS, "XP", DERIVED_ATTRIBUTE, 0x4000, 0x0, 0x0, FUN_008d53f0,
                       0x0);
    RegisterActorValue(ActorValue__Index_UNARMED_DAMAGE, "UnarmedDamage", DERIVED_ATTRIBUTE, 0x800, FUN_00643ed0, 0x0,
                       0x0, 0x0);
    RegisterActorValue(ActorValue__Index_BARTER, "Barter", SKILL, 0x10, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_BIG_GUNS, "BigGuns", SKILL, 0x2000, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_ENERGY_WEAPONS, "EnergyWeapons", SKILL, 0x410, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_EXPLOSIVES, "Explosives", SKILL, 0x410, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_LOCKPICK, "Lockpick", SKILL, 0x10, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_MEDICINE, "Medicine", SKILL, 0x10, FUN_00643bd0, 0x0, FUN_008b9ab0, 0x0);
    RegisterActorValue(ActorValue__Index_MELEE_WEAPONS, "MeleeWeapons", SKILL, 0x410, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_REPAIR, "Repair", SKILL, 0x10, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_SCIENCE, "Science", SKILL, 0x10, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_SMALL_GUNS, "Guns", SKILL, 0x410, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_SNEAK, "Sneak", SKILL, 0x11, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_SPEECH, "Speech", SKILL, 0x10, FUN_00643bd0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_SURVIVAL, "Survival", SKILL, 0x10, FUN_00643bd0, 0x0, FUN_008b9b10, 0x0);
    RegisterActorValue(ActorValue__Index_UNARMED, "Unarmed", SKILL, 0x410, FUN_00643bd0, 0x0, 0x0, 0x1, 0x38);
    RegisterActorValue(ActorValue__Index_INVENTORY_WEIGHT, "InventoryWeight", DERIVED_ATTRIBUTE, 0x1, FUN_008a0cd0, 0x0,
                       Actor::HandleActorValueUpdate, 0x0);
    RegisterActorValue(ActorValue__Index_PARALYSIS, "Paralysis", INT_VALUE, 0x1, 0x0, 0x0, FUN_008b9cc0, 0x0);
    RegisterActorValue(ActorValue__Index_INVISIBILITY, "Invisibility", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_CHAMELEON, "Chameleon", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_NIGHT_EYE_BONUS, "NightEye", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_TURBO, "Turbo", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_WATER_BREATHING, "WaterBreathing", INT_VALUE, 0x1, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_RADIATION_RADS, "RadiationRads", INT_VALUE, 0x220, 0x0, 0x0,
                       Actor::HandleRadiationValueChange, 0x0);
    RegisterActorValue(ActorValue__Index_BLOODY_MESS, "BloodyMess", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_01, "Variable01", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_02, "Variable02", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_03, "Variable03", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_04, "Variable04", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_05, "Variable05", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_06, "Variable06", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_07, "Variable07", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_08, "Variable08", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_09, "Variable09", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_VARIABLE_10, "Variable10", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    RegisterActorValue(ActorValue__Index_IGNORE_CRIPPLED_LIMBS, "IgnoreCrippledLimbs", VARIABLE, 0x1, 0x0, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    RegisterActorValue(ActorValue__Index_DEHYDRATION, "Dehydration", INT_VALUE, 0x221, 0x0, 0x0, UpdateStageChange,
                       0x0);
    RegisterActorValue(ActorValue__Index_HUNGER, "Hunger", INT_VALUE, 0x221, 0x0, 0x0, UpdateStageTransition, 0x0);
    RegisterActorValue(ActorValue__Index_SLEEPDEPREVATION, "SleepDeprevation", INT_VALUE, 0x221, 0x0, 0x0,
                       OnSleepDeprivationStageChanged, 0x0);
    RegisterActorValue(ActorValue__Index_DAMAGE_THRESHOLD, "DamageThreshold", RESISTANCE, 0x800, FUN_008a0ad0, 0x0,
                       FUN_008ba270, 0x0);
    for (int index = 0; index < ActorValue__Index_ACTOR_VALUE_COUNT; ++index)
    {
    }
    DAT_011d6154 = true;
}

// @fnv 0x006701a0
bool ActorValueInfo::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 89)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4d414e41:
            if (file->GetChunkSize())
            {
                char* abbreviation = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(abbreviation, 0);
                m_cAbbreviation = abbreviation;
            }
            else
            {
                m_cAbbreviation = "";
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Clamps value to [0,100] when flag 0x10 is set, or to [0 or 1,10] when flag 8 is set, otherwise returns it unchanged.
// @fnv 0x0066f190
float ActorValue::ClampValue(Index index, float value)
{
    float result = value;
    if (GetFlag(index, 0x10))
    {
        result = FUN_00404010(0.0f, FUN_0040ebd0(result, 100.0f));
    }
    else if (GetFlag(index, 8))
    {
        float minimum = GetFlag(index, 0x8000) ? 1.0f : 0.0f;
        result = FUN_00404010(minimum, FUN_0040ebd0(result, 10.0f));
    }
    return result;
}

// Maps a section and index to an ActorValue::Index by adding a per-section offset, returning 0 for unknown sections.
// @fnv 0x0066ec10
ActorValue::Index ActorValue::GetActorValueForSectionIndex(Section section, char index)
{
    switch (section)
    {
    case ATTRIBUTE:
        return (Index)(index + 5);
    case DERIVED_ATTRIBUTE:
        return (Index)(index + 12);
    case SKILL:
        return (Index)(index + 32);
    case AI_ATTRIBUTE:
        return (Index)index;
    case SPECIAL:
        return (Index)(index + 25);
    case INT_VALUE:
        return (Index)(index + 46);
    default:
        return (Index)0;
    }
}

// Returns the number of entries in the given ActorValue section, or 0 for an unknown section.
// @fnv 0x0066ecf0
unsigned int ActorValue::GetCountForSection(Section section)
{
    switch (section)
    {
    case ATTRIBUTE:
        return 7;
    case DERIVED_ATTRIBUTE:
        return 20;
    case SKILL:
        return 14;
    case AI_ATTRIBUTE:
        return 5;
    case SPECIAL:
        return 7;
    case INT_VALUE:
        return 16;
    default:
        return 0;
    }
}

// @fnv 0x0066e950
const char* ActorValue::GetActorValueName(Index index)
{
    ActorValueInfo* info = GetActorValueInfo(index);
    if (info)
    {
        if (info->GetFullName() && BSStringLength(info->GetFullName()))
        {
            return info->GetFullName();
        }
        else
        {
            return info->m_pName;
        }
    }
    return 0;
}

// Zeroes value, looks up the ActorValueInfo for index, and if it has a getter, stores the getter's result in value and returns true.
// @fnv 0x0066ed60
bool ActorValue::TryGetActorValue(ActorValueOwner* owner, Index index, float& value)
{
    ActorValueInfo* info;
    bool result = false;
    value = 0.0f;
    info = GetActorValueInfo(index);
    if (info && info->m_pDerivedValueFunction)
    {
        value = info->m_pDerivedValueFunction(owner, index);
        result = true;
    }
    return result;
}

// Looks up the ActorValueInfo for index and, if it has a change handler, invokes it with owner, index, oldValue, newValue and source.
// @fnv 0x0066ee50
void ActorValue::NotifyActorValueChanged(ActorValueOwner* owner, Index index, float oldValue, float newValue,
                                         ActorValueOwner* source)
{
    ActorValueInfo* info = GetActorValueInfo(index);
    if (info && info->m_pActorValueChangedCallback)
    {
        info->m_pActorValueChangedCallback(owner, index, oldValue, newValue, source);
    }
}

// Stores item into modItem1, modItem2 or modItem3 depending on slot (1, 2 or 4).
// @fnv 0x00521480
void TESObjectWEAP::SetModItem(unsigned int slot, TESObjectIMOD* item)
{
    if (slot == 1)
    {
        modItem1 = item;
    }
    else if (slot == 2)
    {
        modItem2 = item;
    }
    else if (slot == 4)
    {
        modItem3 = item;
    }
}

// Looks up the ActorValueInfo for index and returns its array pointer and count via count; returns null and zero count if no info exists.
// @fnv 0x0066edc0
ActorValue::Index* ActorValue::GetDependentActorValueIndices(Index index, int& count)
{
    ActorValueInfo* info;
    Index* result = 0;
    count = 0;
    info = GetActorValueInfo(index);
    if (info)
    {
        result = info->m_aiEnumeratedValues;
        count = info->m_iEnumeratedValueCount;
    }
    return result;
}

// @fnv 0x0066ef50
float ActorValueOwner::GetActorValueFloatByIndex(ActorValue::Index index)
{
    float result = GetCurrentActorValue(index);
    result = ActorValue::ClampValue(index, result);
    return result;
}

// @fnv 0x0066ee10
bool ActorValue::HasActorValueChangedCallback(Index index)
{
    ActorValueInfo* info = GetActorValueInfo(index);
    return info && info->m_pActorValueChangedCallback;
}

// @fnv 0x0066ef20
int ActorValueOwner::GetActorValueAsInteger(ActorValue::Index index)
{
    return (int)FUN_00406ce0(GetActorValueFloatByIndex(index));
}

// @fnv 0x0066fe40
ActorValueInfo::ActorValueInfo(int index, const char* name)
{
    SetFormType((ENUM_FORM_ID)0x59);
    if (index != -1)
        SetFormID(GetActorValueFormID((ActorValue::Index)index), false);
    m_pName = (char*)name;
    if (name)
    {
        char buffer[100];
        sprintf_s(buffer, 100, "AV%s", name);
        SetScriptName(buffer);
    }
    m_cAbbreviation = "";
    uFlags = 0;
    m_pDerivedValueFunction = 0;
    m_pActorValueMapping = 0;
    m_pActorValueChangedCallback = 0;
    m_iEnumeratedValueCount = 0;
    for (int i = 0; i < 15; ++i)
        m_aiEnumeratedValues[i] = ActorValue::ActorValue__Index_ACTOR_VALUE_COUNT;
    m_iEnumeratedNameCount = 0;
    for (int jIndex = 0; jIndex < 10; ++jIndex)
        m_apEnumeratedNames[jIndex] = 0;
}

// @fnv 0x0066efe0
void ActorValue::RegisterActorValue(Index index, char* name, Section section, unsigned int flags,
                                    ActorValueDeriveCallback derive, ActorValueMappingCallback mapping,
                                    ActorValueModifiedCallback modified, int count, ...)
{
    if (!g_011d61c8.values[index])
    {
        ActorValueInfo* info = new ActorValueInfo(index, name);
        info->m_iSection = section;
        info->uFlags = flags;
        info->m_pDerivedValueFunction = derive;
        info->m_pActorValueMapping = mapping;
        info->m_pActorValueChangedCallback = modified;
        info->m_iEnumeratedValueCount = MinInt(count, 15);
        if (count > 0)
        {
            va_list args;
            va_start(args, count);
            for (int i = 0; i < info->m_iEnumeratedValueCount; ++i)
            {
                Index dependent = va_arg(args, Index);
                info->m_aiEnumeratedValues[i] = dependent;
            }
            va_end(args);
        }
        g_011d61c8.values[index] = info;
    }
}

// @fnv 0x00670120
void ActorValueInfo::SetEnumerated(int count, ...)
{
    m_iEnumeratedNameCount = MinInt(count, 10);
    va_list args;
    va_start(args, count);
    for (int i = 0; i < m_iEnumeratedNameCount; ++i)
    {
        const char* name = va_arg(args, const char*);
        m_apEnumeratedNames[i] = name;
    }
    va_end(args);
}

// Returns true when index is one of the actor value indices 18-20, 52, or 58-61, otherwise false.
// @fnv 0x0066eba0
bool FUN_0066eba0(ActorValue__Index aeActorValue)
{
    bool result = false;
    switch (aeActorValue)
    {
    case 18:
    case 19:
    case 20:
    case 52:
    case 58:
    case 59:
    case 60:
    case 61:
        result = true;
        break;
    }
    return result;
}

// @fnv 0x0066fd20
ActorValue::Section ActorValue::GetSection(Index index)
{
    if (FUN_005d1260(index))
        return ATTRIBUTE;
    if (IsDerivedAttribute(index))
        return DERIVED_ATTRIBUTE;
    if (IsSkill(index))
        return SKILL;
    if (IsAIAttribute(index))
        return AI_ATTRIBUTE;
    return INT_VALUE;
}

// @fnv 0x0066ec80
unsigned char ActorValue::ToArrayIndex(int section, Index index)
{
    switch (section)
    {
    case 0:
        return index - 5;
    case 1:
        return index - 12;
    case 2:
        return index - 32;
    case 3:
        return (unsigned char)index;
    case 4:
        return index - 25;
    case 5:
        return index - 46;
    default:
        return 0;
    }
}

// @fnv 0x0066fdf0
unsigned int ActorValueInfo::GetActorValueFormID(ActorValue::Index index)
{
    unsigned int auiFormId;
    int m_iSectionIndex = ActorValue::GetSection(index);
    auiFormId = m_iSectionIndex * 100 + 1000;
    auiFormId += (char)ActorValue::ToArrayIndex(m_iSectionIndex, index);
    return auiFormId;
}

// Initializes all 77 entries of the values array to zero.
// @fnv 0x0066ef90
GlobalObject_0066ef90::GlobalObject_0066ef90()
{
    for (int i = 0; i < 77; ++i)
        values[i] = 0;
}

// Returns true when the actor value index falls in the derived-attribute range [12, 32).
// @fnv 0x0066fd90
bool ActorValue::IsDerivedAttribute(Index index)
{
    return index >= 12 && index < 32;
}

// Returns true when the actor value index is in the range 0 to 4, i.e. an AI attribute.
// @fnv 0x0066fdc0
bool ActorValue::IsAIAttribute(Index index)
{
    return index >= 0 && index < 5;
}

// Returns the pointer stored at index aiIndex in the g_011d61c8 array if aiIndex is in [0, 0x4d), otherwise returns null.
// @fnv 0x0066e920
void* __cdecl GetActorValueInfo(int aiIndex)
{
    void* pinfo = 0;
    if (aiIndex >= 0 && aiIndex < 0x4d)
    {
        pinfo = ((void**)&g_011d61c8)[aiIndex];
    }
    return pinfo;
}

// Returns the full name of the ActorValueInfo for the given actor value index, or null if no info exists.
// @fnv 0x0066e9f0
const char* __cdecl FUN_0066e9f0(ActorValue::Index aeActorValue)
{
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aeActorValue);
    if (pinfo)
        return reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(pinfo) + 0x2c)->GetFullName();
    return 0;
}

extern "C"
{
    struct ActorValueInfo;
}

// @fnv 0x0066eac0
const char* __cdecl GetActorValueName(ActorValue::Index index)
{
    char* presult = 0;
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(index);
    if (pinfo)
        presult = pinfo->m_pName;
    return presult;
}

struct Flt
{
    operator unsigned int() const;
};

// @fnv 0x0066eb00
const char* __cdecl FUN_0066eb00(ActorValue::Index aiIndex)
{
    const char* presult = 0;
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aiIndex);
    if (pinfo)
        presult = (const char*)(reinterpret_cast<Flt*>((char*)pinfo + 0x3c))->operator unsigned int();
    return presult;
}

extern "C" void __cdecl ClearActorValueSlots();

// @fnv 0x0066efd0
void __fastcall FUN_0066efd0(int)
{
    ClearActorValueSlots();
}

int _stricmp(const char* a, const char* b);
struct FUN_0066eb40_entry
{
    char pad[0x38];
    const char* name;
};
// Scans up to 0x4D entries in g_011d61c8, comparing each entry's name case-insensitively to str, and returns the matching index or 0x4D if none match.
// @fnv 0x0066eb40
int FindEntryIndexByName(const char* apName)
{
    int result = 0x4D;
    for (int i = 0; i < 0x4D && result == 0x4D; ++i)
    {
        if (!_stricmp(((FUN_0066eb40_entry**)&g_011d61c8)[i]->name, apName))
            result = i;
    }
    return result;
}

void __cdecl _Deallocate(void*);
struct Holder00670050
{
    void FUN_00670080();
    void* FUN_00670050(unsigned int);
};
// Calls FUN_00670080, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00670050
void* Holder00670050::FUN_00670050(unsigned int flags)
{
    FUN_00670080();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Returns the icon texture path for the given weapon skill index, or null if the index has no mapped icon.
// @fnv 0x0066ea20
const char* __cdecl GetWeaponSkillIconPath(int aiSkillIndex)
{
    const char* path = 0;
    switch (aiSkillIndex)
    {
    case 33:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_big_guns.dds";
        break;
    case 34:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_energy.dds";
        break;
    case 35:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_explosives.dds";
        break;
    case 38:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_melee.dds";
        break;
    case 41:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_sm_arms.dds";
        break;
    case 45:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_unarmed.dds";
        break;
    }
    return path;
}

namespace fnv_006703b0 {
struct S_00487010
{
    void FUN_00487010();
};
struct FUN_00482cb0_shell
{
    void FUN_00482cb0();
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct S7010
{
    unsigned int Length();
};
struct Flt
{
    operator unsigned int();
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_006703b0_shell
{
    void FUN_006703b0();
};
// @fnv 0x006703b0
void FUN_006703b0_shell::FUN_006703b0()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    ((FUN_00482cb0_shell*)((char*)this + 0x24))->FUN_00482cb0();
    ((FUN_0048e370_obj*)((char*)this + 0x2c))->FUN_0048e370(0x4e4f4349);
    if (((S7010*)((char*)this + 0x3c))->Length())
        FUN_004856f0(0x4d414e41, (void*)((Flt*)((char*)this + 0x3c))->operator unsigned int(),
                     ((S7010*)((char*)this + 0x3c))->Length() + 1);
    ((FUN_00485680*)this)->M();
}
}  // namespace fnv_006703b0

struct Inner24
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual const char* GetDesc(int, int);
};
struct Overlay24
{
    char pad[36];
    Inner24 inner;
};
// Looks up the ActorValueInfo for aiIndex and returns its description via GetDesc, or null if the info is missing.
// @fnv 0x0066e9b0
const char* GetActorValueDescription(ActorValue::Index aiIndex)
{
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aiIndex);
    if (pinfo)
        return ((Overlay24*)pinfo)->inner.GetDesc(0, 0x43534544);
    return 0;
}

extern double DAT_01012060;
bool __cdecl FUN_00406d70(int, unsigned int);

struct FUN_0066eea0_Object
{
    virtual void vf00();
    virtual double vf04(int);
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual double vf14(int);
};

// @fnv 0x0066eea0
float __cdecl FUN_0066eea0(FUN_0066eea0_Object* object, int index, float value)
{
    float result = value;

    if (value < DAT_01012060)
    {
        if (FUN_00406d70(index, 0x20))
        {
            float total = static_cast<float>(object->vf04(index) + object->vf14(index));
            if (total < -value)
            {
                result = -total;
            }
        }
    }

    return result;
}

class ActorValueSlotObject
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual int Unk_04(int flag);
};

extern ActorValueSlotObject* DAT_011d61c8[0x4d];
extern bool DAT_011d6154;

// Calls Unk_04(1) on each non-null entry of DAT_011d61c8, nulls the entries, and clears DAT_011d6154.
// @fnv 0x0066f110
void ClearActorValueSlots()
{
    for (int i = 0; i < 0x4d; i++)
    {
        if (DAT_011d61c8[i] != 0)
        {
            ActorValueSlotObject* tmp = DAT_011d61c8[i];
            ActorValueSlotObject* objVal = tmp;
            objVal != 0 ? objVal->Unk_04(1) : 0;
            DAT_011d61c8[i] = 0;
        }
    }
    DAT_011d6154 = 0;
}

struct FUN_00670080_Primary
{
    virtual ~FUN_00670080_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_00670080_Base18
{
    virtual ~FUN_00670080_Base18();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00670080_Base24
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_00670080_Base2c
{
    virtual ~FUN_00670080_Base2c();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_00670080_Member
{
    ~FUN_00670080_Member();
    unsigned int unk00;
};

struct FUN_00670080 : FUN_00670080_Primary, FUN_00670080_Base18, FUN_00670080_Base24, FUN_00670080_Base2c
{
    FUN_00670080_Member m_3c;
    virtual ~FUN_00670080();
};

// Empty destructor for FUN_00670080; the compiler-generated member and base destructors run implicitly.
// @fnv 0x00670080
FUN_00670080::~FUN_00670080()
{}

struct BSStringTCharAssign
{
    BSStringTCharAssign& operator=(const BSStringTCharAssign&);
};

struct FormCopyHelper
{
    void CopyBaseForm(TESForm* form);
};

struct ActorValueInfoCopy : ActorValueInfo
{
    void FUN_00670430(TESForm* form);
};

// Clears data, copies fields and up to 15 array entries from a dynamic-cast ActorValueInfo source, pads the rest, then copies the base form.
// @fnv 0x00670430
void ActorValueInfoCopy::FUN_00670430(TESForm* form)
{
    ClearData();
    ActorValueInfo* pSource = dynamic_cast<ActorValueInfo*>(form);
    if (!pSource)
        return;
    m_pName = pSource->m_pName;
    *(BSStringTCharAssign*)&m_cAbbreviation = *(BSStringTCharAssign*)&pSource->m_cAbbreviation;
    uFlags = pSource->uFlags;
    m_pDerivedValueFunction = pSource->m_pDerivedValueFunction;
    m_pActorValueMapping = pSource->m_pActorValueMapping;
    m_pActorValueChangedCallback = pSource->m_pActorValueChangedCallback;
    m_iEnumeratedValueCount = pSource->m_iEnumeratedValueCount;
    int i;
    for (i = 0; i < m_iEnumeratedValueCount && i < 15; i++)
        m_aiEnumeratedValues[i] = pSource->m_aiEnumeratedValues[i];
    for (; i < 15; i++)
        m_aiEnumeratedValues[i] = (ActorValue::Index)0x4d;
    ((FormCopyHelper*)this)->CopyBaseForm(form);
}

extern const int _DAT_01183028;
extern const int typeinfo_BGSPerk;
extern "C" void* __cdecl FNV_DynamicCast(void*, long, const void*, const void*, int);

struct ActorValueStringCompare
{
    bool FUN_00501c30(const BSStringT<char>*);
};

struct ActorValueCompare : ActorValueInfo
{
    bool FUN_00485270(TESForm*);
    bool FUN_00670540(TESForm* form);
};

// Returns true when the cast fails, FUN_00485270 succeeds, or the abbreviation strings compare equal.
// @fnv 0x00670540
bool ActorValueCompare::FUN_00670540(TESForm* form)
{
    ActorValueInfo* other =
        static_cast<ActorValueInfo*>(FNV_DynamicCast(form, 0, &_DAT_01183028, &typeinfo_BGSPerk, 0));
    if (!other)
        return true;
    if (FUN_00485270(other))
        return true;
    if (reinterpret_cast<ActorValueStringCompare*>(&m_cAbbreviation)->FUN_00501c30(&other->m_cAbbreviation))
        return true;
    return false;
}
