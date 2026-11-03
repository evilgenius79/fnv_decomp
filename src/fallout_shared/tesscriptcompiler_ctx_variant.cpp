
// tesscriptcompiler_ctx_variant.cpp: context variant of src/fallout_shared/tesscriptcompiler.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesscriptcompiler_packet_decls.h"
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);

int FUN_00404dc0(const char*, const char*);
void* __cdecl operator new(unsigned int);
class TESForm
{
  public:
    virtual ~TESForm();
    int FUN_00401170();
};
class TESObjectREFR : public TESForm
{
  public:
    bool FUN_005653d0();
};
extern TESForm* g_thePlayer;
struct BSStringT_char
{
    char* data;
    unsigned short length, capacity;
    int FUN_00408a80(const char*, bool) const;
    bool Set(const char*, unsigned int);
};
class ScriptReferencedObject
{
  public:
    BSStringT_char name;
    TESForm* form;
    unsigned int variableID;
    ScriptReferencedObject();
    ~ScriptReferencedObject();
};
template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList* next;
    T& FUN_006815c0();
    BSSimpleList* FUN_00726070();
    void FUN_00905820(const T&);
};
struct ScriptInfo
{
    unsigned int variableCount, m_uiReferenceID, dataSize, lastID;
    unsigned short type;
    bool compiled;
    unsigned char unk13;
};
struct ScriptToken
{
    char name[0x200];
    unsigned int refIndex;
    unsigned char type;
    unsigned int opcode;
    unsigned int variableID;
    TESForm* form;
    unsigned int unk214, unk218, paramTextLen;
};
struct CStringArgument
{
    char* scriptText;
    unsigned int textOffset;
    int runtimeMode;
    BSStringT_char scriptName;
    unsigned int errorCode;
    bool partialScript;
    unsigned int curLineNumber;
    unsigned char* scriptData;
    unsigned int dataOffset;
    ScriptInfo info;
    BSSimpleList<void*> vars;
    BSSimpleList<ScriptReferencedObject*> refVars;
    void* currentScript;
    BSSimpleList<void*> lines;
    BSSimpleList<ScriptReferencedObject*>* FUN_005d43c0();
    bool FUN_005afad0(ScriptToken*, bool, bool);
};
TESForm* FUN_00483a00(const char*);
TESForm* LookupFormByID(unsigned int);
unsigned int FUN_005afe10(const char*, char**, int);
void ReportScriptError(CStringArgument*, const char*, ...);
// @fnv 0x005afad0
bool CStringArgument::FUN_005afad0(ScriptToken* token, bool variable, bool allowUnknown)
{
    bool result = false;
    unsigned int index = 1;
    BSSimpleList<ScriptReferencedObject*>* entry = &refVars;
    while (entry && entry->FUN_006815c0())
    {
        if (!entry->FUN_006815c0()->name.FUN_00408a80(token->name, true))
        {
            token->refIndex = index;
            token->form = entry->FUN_006815c0()->form;
            if (variable)
                entry->FUN_006815c0()->variableID = token->variableID;
            else
                token->variableID = entry->FUN_006815c0()->variableID;
            result = true;
            break;
        }
        entry = entry->FUN_00726070();
        index++;
    }
    if (!result)
    {
        ScriptReferencedObject* reference = new ScriptReferencedObject;
        if (variable)
            result = true;
        else
        {
            if (!FUN_00404dc0(token->name, "Player"))
            {
                reference->form = g_thePlayer;
                result = true;
            }
            if (!result)
            {
                reference->form = FUN_00483a00(token->name);
                if (reference->form)
                {
                    if (reference->form->FUN_00401170() == 3)
                        reference->form = 0;
                    else
                        result = true;
                }
            }
            if (!result)
            {
                char* end = 0;
                unsigned int formID = FUN_005afe10(token->name, &end, 16);
                if (formID && end && !*end)
                {
                    reference->form = LookupFormByID(formID);
                    if (reference->form)
                        result = true;
                }
            }
            if (result && runtimeMode != 1)
            {
                TESObjectREFR* refr = dynamic_cast<TESObjectREFR*>(reference->form);
                if (refr && !refr->FUN_005653d0())
                {
                    ReportScriptError(this, "Non-persistent reference '%s' cannot be used in a script.", token->name);
                    result = false;
                }
            }
        }
        if (result || allowUnknown)
        {
            result = true;
            if (variable)
            {
                reference->form = 0;
                reference->variableID = token->variableID;
            }
            else
            {
                token->form = reference->form;
                reference->variableID = 0;
            }
            reference->name.Set(token->name, 0);
            info.m_uiReferenceID++;
            FUN_005d43c0()->FUN_00905820(reference);
            token->refIndex = info.m_uiReferenceID;
        }
        else
            delete reference;
    }
    return result;
}

#include <ctype.h>
extern const char missingSetExpression[];

struct CompileLine;

struct CompileState;

struct CompileWord
{
    char text[512];
    unsigned refIndex;
    char variableType;
    unsigned functionCode;
    unsigned variableID;
    void* form;
    CompileWord();
};

struct CompileString
{
    char* text;
    unsigned short length, capacity;
    void FUN_004037f0(const char*, unsigned);
    const char* FUN_00559450();
};

struct CompileVariable
{
    unsigned id;
    unsigned unk04, unk08, unk0c;
    bool integer;
    unsigned char unk11;
    unsigned short unk12;
    unsigned unk14;
    CompileString name;
    CompileVariable();
};

struct CompileVariables
{
    void FUN_00905820(CompileVariable* const&);
};

struct CompileReference
{
    unsigned unk00, unk04;
    TESForm* form;
    unsigned variableID;
    const char* FUN_00559450();
};

struct CompileScript
{
    signed char FUN_005ac6a0(const char*, CompileVariable*);
};

struct CompileState
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* output;
    unsigned outputSize;
    unsigned unk28, unk2c, unk30;
    unsigned variableCount;
    bool partial;
    CompileVariables* FUN_005a8080();
    bool FUN_005afad0(CompileWord*, bool, bool);
    CompileReference* GetNodeValue(unsigned);
};

struct CompileLine
{
    unsigned lineNumber;
    char input[512];
    unsigned inputSize, inputOffset;
    char output[512];
    unsigned outputSize;
    int kind;
    unsigned refIndex;
    unsigned error;
    CompileLine();
};

typedef bool(__cdecl* CompileCallback)(unsigned short, void*, CompileLine*, CompileState*);

struct CompileCommand
{
    const char* name;
    const char* alias;
    unsigned short opcode, unk0a;
    unsigned unk0c;
    bool requiresReference;
    unsigned char unk11;
    unsigned short parameterCount;
    void* parameters;
    unsigned unk18;
    CompileCallback compile;
    unsigned unk20, unk24;
};

extern CompileCommand DAT_0118e2f0[];

extern unsigned DAT_011cadbc;

extern const char* DAT_0118c594[];

int FUN_005af5f0(CompileState*, CompileWord*, char*, unsigned*, unsigned char, int);

int FUN_00404dc0(const char*, const char*);

void ReportScriptError(CompileState*, const char*, ...);

int FUN_00406d30(char*, unsigned, const char*);

void* FUN_00401460(void*, const void*, unsigned);

void* FUN_00403d30(void*, int, unsigned);

bool FUN_005afeb0(const char*);

bool FUN_005b1a90(const char*, unsigned);

void FUN_005b1b60(const char*, unsigned*);

CompileCommand* FUN_005b1120(int);

struct CompileOperand
{
    unsigned kind, unk04, unk08, unk0c;
};

struct CompileOperators
{
    unsigned values[64];
    int top;
};

struct CompileOperands
{
    CompileOperand values[32];
    int top;
};

struct CompileExpression
{
    int error;
    char output[1024];
    CompileOperators operators;
    CompileOperands operands;
    CompileExpression();
    ~CompileExpression();
    char* ConvertToPostfix(char*, int*);
    int FUN_00559450();
};

struct LineCompiler
{
    int CountLinesInBeginBlock(CompileState*, CompileLine*);
    int ScanBlockLines(CompileState*, CompileLine*);
    int CompileScriptLine(CompileState*, CompileLine*, const char*, char*);
    bool FUN_005aff40(CompileScript*, CompileState*, CompileLine*);
};

// @fnv 0x005aff40
bool LineCompiler::FUN_005aff40(CompileScript* script, CompileState* compiler, CompileLine* line)
{
    CompileWord word6;

    unsigned offset_2 = 0;

    CompileExpression expression5;
    char* expressionCodeVal9;

    line->outputSize = 0;
    line->inputOffset = 0;

    switch (line->kind)
    {
    case 29:
        break;

    case 16:
        if (FUN_005af5f0(compiler, &word6, line->input, &line->inputOffset, 0, 0))
        {
            int i;
            bool found7 = false;

            for (i = 0; i < 38; ++i)
            {
                if (!FUN_00404dc0(DAT_0118e2f0[i].name, word6.text) || !FUN_00404dc0(DAT_0118e2f0[i].alias, word6.text))
                {
                    found7 = true;
                    break;
                }
            }
            if (found7)
            {
                *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(DAT_0118e2f0[i].opcode);
                line->outputSize += 2;

                int length = 0;
                length = CountLinesInBeginBlock(compiler, line);

                if (length == -1)
                {
                    ReportScriptError(compiler, "Mismatched begin/end block.");
                    return false;
                }
                *(unsigned*)(line->output + line->outputSize) = 0x55555555;

                DAT_011cadbc = compiler->outputSize + line->outputSize;

                line->outputSize += 4;

                CompileCommand* command = &DAT_0118e2f0[i];

                if (command)
                {
                    if (command->requiresReference && compiler->partial)
                    {
                        ReportScriptError(compiler, "Invalid block type for quest script.");
                        return false;
                    }
                    if (command && command->parameters)
                    {
                        void* blockParameters0 = command->parameters;

                        CompileCallback blockCallback11 = command->compile;

                        unsigned short count = command->parameterCount;

                        CompileLine parametersLine;

                        FUN_00406d30(parametersLine.input, 512, line->input + line->inputOffset);

                        parametersLine.outputSize = 0;

                        parametersLine.lineNumber = line->lineNumber;

                        if (!blockCallback11(count, blockParameters0, &parametersLine, compiler))
                            return false;

                        FUN_00401460(line->output + line->outputSize, parametersLine.output, parametersLine.outputSize);

                        line->outputSize += parametersLine.outputSize;
                    }
                }
                if (DAT_011cadbc)
                {
                    *(unsigned*)(line->output + (DAT_011cadbc - compiler->outputSize)) =
                        compiler->outputSize + line->outputSize;
                }
            }
            else
            {
                ReportScriptError(compiler, "Syntax Error.  Invalid block type in 'begin' command.");
                return false;
            }
        }
        else
        {
            ReportScriptError(compiler, "Syntax Error.  Missing block type in 'begin' command.");
            return false;
        }
        break;

    case 17:
        if (DAT_011cadbc)
        {
            unsigned start6 = *(unsigned*)(compiler->output + (DAT_011cadbc + 4));

            *(unsigned*)(compiler->output + (DAT_011cadbc + 4)) = compiler->outputSize - start6;
            DAT_011cadbc = 0;
        }
        else
        {
            ReportScriptError(compiler, "Syntax Error.  Failed to store the 'begin' 'end' jump block.");
            return false;
        }
    case 30:
        break;
    case 18:
    case 19:
    case 20:
    case 31:
        if (FUN_005af5f0(compiler, &word6, line->input, &line->inputOffset, 0, 0))
        {
            const char* variableName1 = word6.text;

            if (!FUN_005afeb0(variableName1))
            {
                ReportScriptError(compiler, "Invalid variable name '%s'.\r\nCompiled script not saved!", variableName1);
                return false;
            }
            CompileVariable* variableInfo0 = new CompileVariable;

            variableInfo0->integer = (line->kind != 20 && line->kind != 31) ? 1 : 0;

            variableInfo0->name.FUN_004037f0(variableName1, 0);

            if (script->FUN_005ac6a0(variableInfo0->name.FUN_00559450(), variableInfo0))
            {
            }
            else
            {
                compiler->variableCount++;
                variableInfo0->id = compiler->variableCount;
            }
            compiler->FUN_005a8080()->FUN_00905820(variableInfo0);

            if (line->kind == 31)
            {
                word6.variableID = variableInfo0->id;
                compiler->FUN_005afad0(&word6, true, false);
            }
        }
        else
        {
            ReportScriptError(compiler, "Missing variable name in variable declaration.");
            return false;
        }
        break;

    case 21: {
        if (!FUN_005af5f0(compiler, &word6, line->input, &line->inputOffset, 1, 1))
        {
            ReportScriptError(compiler, "Missing variable name in set command.");
            return false;
        }
        if (!word6.variableType || word6.variableType == 'X')
        {
            ReportScriptError(compiler, "Unknown variable '%s'.", &word6);
            return false;
        }
        CompileWord setWord20;

        FUN_005af5f0(compiler, &setWord20, line->input, &line->inputOffset, 0, 0);

        if (tolower(setWord20.text[0]) != 't' || tolower(setWord20.text[1]) != 'o')
        {
            ReportScriptError(compiler, "Syntax Error.  Missing \"to\" in set command.");
            return false;
        }
        if (word6.refIndex > 0)
        {
            if (word6.variableType == 'G')
            {
                line->output[line->outputSize] = 'G';
                line->outputSize++;
            }
            else
            {
                line->output[line->outputSize] = 'r';
                line->outputSize++;
            }
            *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(word6.refIndex);
            line->outputSize += 2;
        }
        if (word6.variableID > 0)
        {
            line->output[line->outputSize] = word6.variableType;
            line->outputSize++;
            *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(word6.variableID);
            line->outputSize += 2;
        }
        if (!FUN_005b1a90(line->input, line->inputOffset))
        {
            ReportScriptError(compiler, "Syntax Error.  Mismatched parentheses in set command.");
            return false;
        }
        FUN_005b1b60(line->input, &line->inputOffset);

        char setText20[512];
        FUN_00403d30(setText20, 0, 512);

        int setLength1 = 0;
        setLength1 = CompileScriptLine(compiler, line, line->input + line->inputOffset, setText20);

        if (!setLength1)
        {
            ReportScriptError(compiler, missingSetExpression);
            return false;
        }
        expressionCodeVal9 = expression5.ConvertToPostfix(setText20, &setLength1);

        if (expression5.FUN_00559450())
        {
            ReportScriptError(compiler, "InfixToPostfix Error.");
            return false;
        }
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(setLength1);
        line->outputSize += 2;

        FUN_00401460(line->output + line->outputSize, expressionCodeVal9, setLength1);
        line->outputSize += setLength1;
    }
    break;

    case 22:
    case 24: {
        offset_2 = 0;

        if (!FUN_005b1a90(line->input, offset_2))
        {
            ReportScriptError(compiler, "Mismatched parentheses.");
            return false;
        }
        FUN_005b1b60(line->input, &offset_2);

        char branchText7[512];
        FUN_00403d30(branchText7, 0, 512);

        int branchLength10 = 0;
        branchLength10 = CompileScriptLine(compiler, line, line->input + offset_2, branchText7);

        if (!branchLength10)
            return false;

        expressionCodeVal9 = expression5.ConvertToPostfix(branchText7, &branchLength10);

        if (expression5.FUN_00559450())
        {
            ReportScriptError(compiler, DAT_0118c594[expression5.FUN_00559450()]);
            return false;
        }
        int branchJump11 = ScanBlockLines(compiler, line);

        if (branchJump11 == -1)
        {
            ReportScriptError(compiler, "Mismatched if/then/else block.");
            return false;
        }
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(branchJump11);
        line->outputSize += 2;
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(branchLength10);
        line->outputSize += 2;

        FUN_00401460(line->output + line->outputSize, expressionCodeVal9, branchLength10);
        line->outputSize += branchLength10;
    }
    break;

    case 23: {
        int jump = 0;
        jump = ScanBlockLines(compiler, line);

        if (jump == -1)
        {
            ReportScriptError(compiler, "Mismatched if/then/else block.");
            return false;
        }
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(jump);
        line->outputSize += 2;
    }
    break;

    case 28:
        break;

    case 25:
        break;

    default: {
        CompileCommand* command = FUN_005b1120(line->kind);

        if (!command)
        {
            ReportScriptError(compiler, "Unknown function code %d.", line->kind);
            return false;
        }
        if (command)
        {
            if (command->requiresReference && compiler->partial && !line->refIndex)
            {
                ReportScriptError(compiler, "Reference function requires explicit reference in quest script.");
                return false;
            }
            if (command->requiresReference && line->refIndex > 0)
            {
                CompileReference* ref2 = compiler->GetNodeValue(line->refIndex);

                TESObjectREFR* object = dynamic_cast<TESObjectREFR*>(ref2->form);

                if (!object && !ref2->variableID)
                {
                    ReportScriptError(
                        compiler,
                        "Syntax error.  Invalid reference '%s' (only object references and reference variables are allowed in this context).",
                        ref2->FUN_00559450());
                    return false;
                }
            }
            if (command->parameters)
            {
                void* commandParameters0 = command->parameters;

                CompileCallback commandCallback1 = command->compile;

                unsigned short commandCount3 = command->parameterCount;

                if (!commandCallback1(commandCount3, commandParameters0, line, compiler))
                    return false;
            }
        }
    }
    break;
    }
    switch (line->kind)
    {
    case 18:
    case 19:
    case 20:
    case 31:
        break;

    default:
        if (compiler->outputSize + line->outputSize + 10 >= 0x4000)
        {
            ReportScriptError(compiler, "MAX_SCRIPT_SIZE exceeded.\r\nCompiled script not saved!");
            return false;
        }
        if (line->refIndex > 0)
        {
            *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(28);
            compiler->outputSize += 2;
            *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(line->refIndex);
            compiler->outputSize += 2;
        }
        *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(line->kind);
        compiler->outputSize += 2;
        *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(line->outputSize);
        compiler->outputSize += 2;

        FUN_00401460(compiler->output + compiler->outputSize, line->output, line->outputSize);
        compiler->outputSize += line->outputSize;
    }
    return true;
}
