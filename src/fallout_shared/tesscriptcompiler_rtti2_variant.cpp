// src/fallout_shared/tesscriptcompiler_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesscriptcompiler.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesscriptcompiler_packet_decls.h"
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);

#include <stdlib.h>
#include <ctype.h>

struct TESForm
{
    int FUN_00401170();
};

struct ScriptLineBuffer
{
    unsigned int m_uiValueBeforeData;
    char cLine[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char cOutput[0x200];
    unsigned int m_uiValueAfterSecondBuffer;
    int unk410;
    int unk414;
    unsigned int m_uiTrailingValue;
};

extern char DAT_01183028[];
extern char DAT_011841cc[];
extern "C" void* _FNV_DynamicCast(void*, int, void*, void*, int);

struct EncodeFormView : TESForm
{

    virtual void slot00();

    virtual void slot04();

    virtual void slot08();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void slot40();

    virtual void slot44();

    virtual void slot48();

    virtual void slot4c();

    virtual void slot50();

    virtual void slot54();

    virtual void slot58();

    virtual void slot5c();

    virtual void slot60();

    virtual void slot64();

    virtual void slot68();

    virtual void slot6c();

    virtual void slot70();

    virtual void slot74();

    virtual void slot78();

    virtual void slot7c();

    virtual void slot80();

    virtual void slot84();

    virtual void slot88();

    virtual void slot8c();

    virtual void slot90();

    virtual void slot94();

    virtual void slot98();

    virtual void slot9c();

    virtual void slota0();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void slote4();

    virtual bool IsReference();

    virtual void slotec();

    virtual void slotf0();

    virtual void slotf4();

    virtual void slotf8();

    virtual void slotfc();

    virtual bool IsActor();
};

struct BGSNote;

struct BGSListForm;

struct EncodeReferenceView : EncodeFormView
{
    void* FUN_0055d310();
    TESForm* FUN_007af430();
};

struct BGSEncounterZone;

struct TESIdleForm;

struct EncodeCellView
{
    bool FUN_00425fd0();
};

struct TESObject;

struct EffectSetting;

struct TESActorBase;

struct TESPackage;

struct BGSPerk;

struct BGSMenuIcon;

struct TESCombatStyle;

struct TESObjectBOOK;

struct TESWorldSpace;

struct SpellItem;

struct MagicItem;

extern char DAT_01183fb4[];
extern char DAT_01183060[];
extern char DAT_0118a650[];
extern char DAT_011840dc[];
extern char DAT_01186a18[];
extern char DAT_011863d4[];
extern char DAT_011863f0[];
extern char DAT_011861dc[];
extern char DAT_0118640c[];
extern char DAT_01183fd0[];
extern char DAT_01183140[];
extern char DAT_011837c4[];
extern char DAT_01183128[];
extern char DAT_011846e8[];
extern char DAT_011846a0[];
extern char DAT_0118627c[];

struct EncodeWord
{
    char text[512];
    unsigned refIndex;
    char variableType;
    unsigned functionCode;
    unsigned variableID;
    TESForm* form;
    EncodeWord();
};

struct EncodeCompiler
{
    bool FUN_005afad0(EncodeWord*, bool, bool);
};

struct EncodeParameter
{
    const char* name;
    unsigned type;
    bool optional;
};

struct EncodeKind
{
    const char* name;
    unsigned char kind;
    bool isReference;
    unsigned short reserved;
};

extern EncodeKind DAT_0118cdd0[];

extern TESForm* DAT_011ca224;

bool FUN_00481f30(int);

int FUN_005af5f0(EncodeCompiler*, EncodeWord*, char*, unsigned*, unsigned char, int);

void FUN_005aea90(EncodeCompiler*, const char*, ...);

void FUN_005b5e40(const char*, ...);

int FUN_00404dc0(const char*, const char*);

void* FUN_00401460(void*, const void*, unsigned);

int IsFloatString(const char*);

int FUN_004b1230(const char*);

int FUN_0066eb40(const char*);

int FUN_004d5eb0(const char*);

extern const char* DAT_01186cf4[];

extern const char* DAT_0119bbb0[];

extern const char* DAT_011869bc[];

extern const char* DAT_01199e8c;

extern const char* DAT_01199e90;

struct EncodeAnimation
{
    const char* name;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

extern EncodeAnimation DAT_011977d8[];

extern const char* DAT_0118a2d8[];

extern unsigned char DAT_0118a598[];

// @fnv 0x005b1ba0
bool __cdecl Cmd_Default_Parse(unsigned short count, const EncodeParameter* parameters, ScriptLineBuffer* line,
                          EncodeCompiler* compiler)

{

    line->uiElapsedMilliseconds = 0;

    char* countDestinationTmp = &line->cOutput[line->m_uiValueAfterSecondBuffer];

    *(unsigned short*)countDestinationTmp = count;

    line->m_uiValueAfterSecondBuffer += 2;

    short index4;

    for (index4 = 0; index4 < count; ++index4)
    {

        unsigned char kindX = DAT_0118cdd0[parameters[index4].type].kind;

        EncodeWord word7;

        int lengthVal = FUN_005af5f0(compiler, &word7, line->cLine, &line->uiElapsedMilliseconds, kindX, 0);

        if (!lengthVal)
        {

            if (!parameters[index4].optional)
            {
                FUN_005aea90(compiler, "Missing parameter %s.\r\nCompiled script not saved!", parameters[index4].name);
                return false;
            }

            else
            {
                *(unsigned short*)countDestinationTmp = index4;
                return true;
            }
        }

        if (kindX == 0 && (word7.refIndex > 0 || word7.variableType != 0))
        {
            FUN_005aea90(compiler, "Parameter %s may not be a variable.\r\nCompiled script not saved!",
                         parameters[index4].name);
            return false;
        }

        if (DAT_0118cdd0[parameters[index4].type].isReference &&
            (!compiler->FUN_005afad0(&word7, false, false) || !word7.refIndex))
        {
            FUN_005aea90(compiler, "Item '%s' not found for parameter %s.\r\nCompiled script not saved!", &word7,
                         parameters[index4].name);
            return false;
        }

        if (DAT_0118cdd0[parameters[index4].type].isReference)
        {

            switch (parameters[index4].type)
            {

            case 3: {

                if (!word7.variableID && (!word7.form || !FUN_00481f30(word7.form->FUN_00401170())))
                {
                    FUN_005aea90(compiler,
                                 "Invalid inventory object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 50: {

                if (!word7.variableID &&
                    (!word7.form || (!FUN_00481f30(word7.form->FUN_00401170()) && word7.form->FUN_00401170() != 85)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid inventory object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 53: {

                if (!word7.variableID &&
                    (!word7.form || (!reinterpret_cast<EncodeFormView*>(word7.form)->IsReference() &&
                                     word7.form->FUN_00401170() != 85)))
                {
                    FUN_005aea90(compiler, "Invalid object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 4:
            case 6:
            case 24:
            case 26: {

                if (!word7.variableID)
                {
                    EncodeReferenceView* reference =
                        (EncodeReferenceView*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011841cc, 0);

                    if (!reference)
                    {
                        FUN_005aea90(compiler,
                                     "Invalid object reference '%s' for parameter %s.\r\nCompiled script not saved!",
                                     &word7, parameters[index4].name);
                        return false;
                    }

                    switch (parameters[index4].type)
                    {

                    case 26:
                        if (!reference->FUN_0055d310())
                        {
                            FUN_005aea90(
                                compiler,
                                "Invalid container reference '%s' for parameter %s.\r\nCompiled script not saved!",
                                &word7, parameters[index4].name);
                            return false;
                        }
                        break;

                    case 24:
                        if (reference->FUN_007af430() != DAT_011ca224)
                        {
                            FUN_005aea90(compiler,
                                         "Invalid map marker '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        break;

                    case 6:
                        if (!reference->IsActor())
                        {
                            FUN_005aea90(compiler, "Invalid actor '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        break;
                    }
                }
            }
            break;

            case 7: {

                if (!word7.variableID &&
                    (!word7.form || (!(SpellItem*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_01183060, 0) &&
                                     !(TESObjectBOOK*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_0118a650, 0))))
                {
                    FUN_005aea90(compiler, "Invalid spell item '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 9: {

                EncodeCellView* object =
                    (EncodeCellView*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_01183fb4, 0);

                if (!word7.variableID && (!object || !object->FUN_00425fd0()))
                {
                    FUN_005aea90(compiler, "Invalid interior cell '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 47: {

                BGSEncounterZone* object =
                    (BGSEncounterZone*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011840dc, 0);

                if (!word7.variableID && !object)
                {
                    FUN_005aea90(compiler,
                                 "Invalid encounter zone '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 48: {

                TESIdleForm* object = (TESIdleForm*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_01186a18, 0);

                if (!word7.variableID && !object)
                {
                    FUN_005aea90(compiler, "Invalid Idle form'%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 37: {

                BGSListForm* object = (BGSListForm*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011863d4, 0);

                if (!word7.variableID && !object)
                {
                    FUN_005aea90(compiler, "Invalid form list '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 38: {

                BGSMenuIcon* object = (BGSMenuIcon*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011863f0, 0);

                if (!word7.variableID && !object)
                {
                    FUN_005aea90(compiler, "Invalid menu icon '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 39: {

                BGSPerk* object = (BGSPerk*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011861dc, 0);

                if (!word7.variableID && !object)
                {
                    FUN_005aea90(compiler, "Invalid perk '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 40: {

                BGSNote* object = (BGSNote*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_0118640c, 0);

                if (!word7.variableID && !object)
                {
                    FUN_005aea90(compiler, "Invalid note '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 27: {

                if (!word7.variableID &&
                    (!word7.form || !(TESWorldSpace*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_01183fd0, 0)))
                {
                    FUN_005aea90(compiler, "Invalid worldspace '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 11: {

                if (!word7.variableID &&
                    (!word7.form || !(MagicItem*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_01183140, 0)))
                {
                    FUN_005aea90(compiler, "Invalid magic item '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 31: {

                if (!word7.variableID &&
                    (!word7.form || !(EffectSetting*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011837c4, 0)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid effect setting '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 12: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 13)))
                {
                    FUN_005aea90(compiler, "Invalid sound '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 54: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 102)))
                {
                    FUN_005aea90(compiler, "Invalid music type '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 13: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 69)))
                {
                    FUN_005aea90(compiler, "Invalid topic '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 14: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 71)))
                {
                    FUN_005aea90(compiler, "Invalid info '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 15: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 12)))
                {
                    FUN_005aea90(compiler, "Invalid race '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 16: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 7)))
                {
                    FUN_005aea90(compiler, "Invalid class '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 17: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 8)))
                {
                    FUN_005aea90(compiler, "Invalid faction '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 62: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 104)))
                {
                    FUN_005aea90(compiler, "Invalid reputation '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 65: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 113)))
                {
                    FUN_005aea90(compiler, "Invalid challenge '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 63: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 109)))
                {
                    FUN_005aea90(compiler, "Invalid casino '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 64: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 108)))
                {
                    FUN_005aea90(compiler, "Invalid casino chip '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 66: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 116)))
                {
                    FUN_005aea90(compiler, "Invalid caravan money '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 67: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 115)))
                {
                    FUN_005aea90(compiler, "Invalid caravan card '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 68: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 117)))
                {
                    FUN_005aea90(compiler, "Invalid caravan card '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 69: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 55)))
                {
                    FUN_005aea90(compiler, "Invalid region '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 19: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 6)))
                {
                    FUN_005aea90(compiler, "Invalid global '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 20: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 39 && word7.form->FUN_00401170() != 85)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid furniture object/list '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 21: {

                if (!word7.variableID &&
                    (!word7.form || !(TESObject*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_01183128, 0)))
                {
                    FUN_005aea90(compiler, "Invalid object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 25: {

                if (!word7.variableID &&
                    (!word7.form || !(TESActorBase*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011846e8, 0)))
                {
                    FUN_005aea90(compiler, "Invalid actor base '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 29: {

                if (!word7.variableID &&
                    (!word7.form || !(TESPackage*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_011846a0, 0)))
                {
                    FUN_005aea90(compiler, "Invalid package '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 30: {

                if (!word7.variableID &&
                    (!word7.form || !(TESCombatStyle*)_FNV_DynamicCast(word7.form, 0, DAT_01183028, DAT_0118627c, 0)))
                {
                    FUN_005aea90(compiler, "Invalid combat style '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 33: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 53)))
                {
                    FUN_005aea90(compiler, "Invalid weather '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 42: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 84)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid Imagespace Modifier '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 43: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 83)))
                {
                    FUN_005aea90(compiler, "Invalid Imagespace '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 34: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 42)))
                {
                    FUN_005aea90(compiler, "Invalid NPC '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 35: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 42 && word7.form->FUN_00401170() != 8)))
                {
                    FUN_005aea90(compiler, "Invalid owner '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 36: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 79)))
                {
                    FUN_005aea90(compiler, "Invalid Effect Shader '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 49: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 98)))
                {
                    FUN_005aea90(compiler, "Invalid message '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 56: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 42 && word7.form->FUN_00401170() != 45)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid NPC or LeveledCharacter '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 57: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 43 && word7.form->FUN_00401170() != 44)))
                {
                    FUN_005aea90(
                        compiler,
                        "Invalid Creature or LeveledCreature '%s' for parameter %s.\r\nCompiled script not saved!",
                        &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 58: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 45)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid LeveledCharacter '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 59: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 44)))
                {
                    FUN_005aea90(compiler,
                                 "Invalid LeveledCreature '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 60: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 52)))
                {
                    FUN_005aea90(compiler, "Invalid LeveledItem '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 61: {

                if (!word7.variableID && !word7.form)
                {
                    FUN_005aea90(compiler, "Invalid form '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            default:
                FUN_005b5e40(
                    "SCRIPTS: Param type '%d' (referenced object) unimplemented in ScriptCompiler::StandardCompile.",
                    parameters[index4].type);
                return false;
            }

            char* output = line->cOutput;

            output[line->m_uiValueAfterSecondBuffer] = 'r';
            line->m_uiValueAfterSecondBuffer++;

            *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)word7.refIndex;

            line->m_uiValueAfterSecondBuffer += 2;
        }
        else
            switch (parameters[index4].type)
            {

            case 0:

                *(unsigned short*)(line->cOutput + line->m_uiValueAfterSecondBuffer) = (unsigned short)lengthVal;

                line->m_uiValueAfterSecondBuffer += 2;

                FUN_00401460(line->cOutput + line->m_uiValueAfterSecondBuffer, &word7, lengthVal);

                line->m_uiValueAfterSecondBuffer += lengthVal;

                break;

            case 1:
            case 2:
            case 23: {

                char* output = line->cOutput;

                if (word7.refIndex > 0)
                {

                    if (word7.variableType == 'G')
                    {
                        output[line->m_uiValueAfterSecondBuffer] = 'G';
                        line->m_uiValueAfterSecondBuffer++;
                    }
                    else
                    {
                        output[line->m_uiValueAfterSecondBuffer] = 'r';
                        line->m_uiValueAfterSecondBuffer++;
                    }

                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)word7.refIndex;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                if (word7.variableType != 'G')
                {

                    if (word7.variableID > 0)
                    {

                        output[line->m_uiValueAfterSecondBuffer] = word7.variableType;
                        line->m_uiValueAfterSecondBuffer++;

                        *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) =
                            (unsigned short)word7.variableID;
                        line->m_uiValueAfterSecondBuffer += 2;
                    }
                    else if (parameters[index4].type == 1 || parameters[index4].type == 23)
                    {

                        if (!FUN_004b1230(word7.text))
                        {
                            FUN_005aea90(compiler,
                                         "Unknown variable '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        else
                        {

                            output[line->m_uiValueAfterSecondBuffer] = 'n';
                            line->m_uiValueAfterSecondBuffer++;

                            int value = atol(word7.text);

                            *(int*)(output + line->m_uiValueAfterSecondBuffer) = value;
                            line->m_uiValueAfterSecondBuffer += 4;
                        }
                    }
                    else
                    {

                        if (!IsFloatString(word7.text))
                        {
                            FUN_005aea90(compiler,
                                         "Unknown variable '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        else
                        {

                            output[line->m_uiValueAfterSecondBuffer] = 'z';
                            line->m_uiValueAfterSecondBuffer++;

                            double value = atof(word7.text);

                            *(double*)(output + line->m_uiValueAfterSecondBuffer) = value;
                            line->m_uiValueAfterSecondBuffer += 8;
                        }
                    }
                }
            }
            break;

            case 5: {

                int value = FUN_0066eb40(word7.text);

                if (value != 77)
                {

                    char* output = line->cOutput;

                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }
                else
                {
                    FUN_005aea90(compiler, "Invalid actor value '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 51: {

                short value = 0;

                for (value = 0; value < 5; ++value)
                {
                    if (!FUN_00404dc0(DAT_01186cf4[value], word7.text))
                        break;
                }

                if (value != 5)
                {
                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                else
                {
                    FUN_005aea90(compiler, "Invalid alignment '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 55: {

                short value = 0;

                for (value = 0; value < 5; ++value)
                {
                    if (!FUN_00404dc0(DAT_0119bbb0[value], word7.text))
                        break;
                }

                if (value != 5)
                {
                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                else
                {
                    FUN_005aea90(compiler, "Invalid CriticalStage '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 52: {

                short value = 0;

                for (value = 0; value < 14; ++value)
                {
                    if (!FUN_00404dc0(DAT_011869bc[value], word7.text))
                        break;
                }

                if (value != 14)
                {
                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                else
                {
                    FUN_005aea90(compiler, "Invalid EquipType '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 41: {

                int value = FUN_004d5eb0(word7.text);

                if (value == 43)
                {
                    FUN_005aea90(compiler, "Invalid misc stat '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
                else
                {

                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }
            }
            break;

            case 28: {

                if (!FUN_004b1230(word7.text))
                {
                    FUN_005aea90(
                        compiler,
                        "Invalid crime type '%s' for parameter %s.  Crime type must be a numeric value from 0-%d.\r\nCompiled script not saved!",
                        &word7, parameters[index4].name, 4);
                    return false;
                }

                int value = atol(word7.text);

                if (value < 0 || value >= 5)
                {
                    FUN_005aea90(
                        compiler,
                        "Invalid crime type '%s' for parameter %s.  Crime type must be a numeric value from 0-%d.\r\nCompiled script not saved!",
                        &word7, parameters[index4].name, 4);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            case 8: {

                char axis4Probe2 = (char)toupper(word7.text[0]);

                if (axis4Probe2 != 'X' && axis4Probe2 != 'Y' && axis4Probe2 != 'Z')
                {
                    FUN_005aea90(compiler, "Axis (X,Y,Z) required for parameter %s.\r\nCompiled script not saved!",
                                 parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                output[line->m_uiValueAfterSecondBuffer] = axis4Probe2;
                line->m_uiValueAfterSecondBuffer++;
            }
            break;

            case 18: {

                int value = 2;

                if (!FUN_00404dc0(word7.text, DAT_01199e8c))
                    value = 0;

                else if (!FUN_00404dc0(word7.text, DAT_01199e90))
                    value = 1;

                if (value == 2)
                {
                    FUN_005aea90(compiler,
                                 "Sex (Male, Female) required for parameter %s.\r\nCompiled script not saved!",
                                 parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            case 10: {

                int value = 255;

                int jProbe3;

                for (jProbe3 = 0; jProbe3 < 245; ++jProbe3)
                {
                    if (!FUN_00404dc0(word7.text, DAT_011977d8[jProbe3].name))
                    {
                        value = jProbe3;
                        break;
                    }
                }

                if (value == 255)
                {
                    FUN_005aea90(compiler,
                                 "Animation group \"%s\" not found for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            case 32: {

                unsigned char value = 0;

                for (int j = 0; j < 87; ++j)
                {
                    if (!FUN_00404dc0(word7.text, DAT_0118a2d8[j]))
                    {
                        value = DAT_0118a598[j];
                        break;
                    }
                }

                if (!value)
                {
                    FUN_005aea90(compiler, "Form Type \"%s\" not found for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            default:
                FUN_005b5e40("SCRIPTS: Param type '%d' unimplemented in ScriptCompiler::StandardCompile.",
                             parameters[index4].type);
                return false;
            }
    }

    if (line->uiElapsedMilliseconds < line->uiSize)
    {
        FUN_005aea90(compiler, "Expected end of line.\r\nCompiled script not saved!", parameters[index4].name);
        return false;
    }

    return true;
}
