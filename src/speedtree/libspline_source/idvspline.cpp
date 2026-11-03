// speedtree/libspline_source/idvspline.cpp: Script, SplineSampler (12 functions)

#include "idvspline_decls.h"

// @fnv 0x00593DB0
double ExpressionEvaluator::Eval(const char* data, TESObjectREFR* reference, TESObjectREFR* container, Script* script,
                         ScriptLocals* locals, int length, bool skip)
{
    IdvSplineInputCursor input;
    input.data = data;
    IdvSplineToken token;
    token.type = EXPRESSION_OPERATORS_EXP_COUNT;
    char cNegate = 0;
    ExpressionValue Value;
    // The right operand is popped first, followed by the left operand.
    ExpressionValue eoOperand2, Value1;
    Value.Type = 0;
    Value.m_dFloatingPointValue = 0.0;
    if (!length || m_eExpressionError)
        return 0.0;
    m_kOperandStack.ResetField();
    if (length > 512)
    {
        SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_OUTOFMEMORY);
        return 0.0;
    }
    char Buffer[513];
    char Token[64];
    memcpy(Buffer, data, length);
    Buffer[length] = 0;
    char* pToken = Buffer;
    token.text = Token;
    input.consumed = ParseToken(&pToken, token.text, &token.type, skip, &input.data);
    if (!input.consumed)
        token.text = 0;
    while (input.consumed)
    {
        if (token.type < EXPRESSION_OPERATORS_EXP_COUNT && token.type > EXPRESSION_OPERATORS_EXP_RIGHTPAREN)
        {
            if (!m_kOperandStack.FUN_00594d20())
            {
                Value1 = m_kOperandStack.PopEntry();
                if (token.type == EXPRESSION_OPERATORS_EXP_UNARYMINUS)
                {
                    if (!Value1.Type)
                        Value.m_lIntegerValue = -Value1.m_lIntegerValue;
                    else
                        Value.m_dFloatingPointValue = -Value1.m_dFloatingPointValue;
                    Value.Type = Value1.Type;
                    m_kOperandStack.AddEntry(Value);
                }
                else
                {
                    if (!m_kOperandStack.FUN_00594d20())
                    {
                        eoOperand2 = m_kOperandStack.PopEntry();
                        switch (token.type)
                        {
                        case EXPRESSION_OPERATORS_EXP_AND:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue && Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue && Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue && Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue && Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_OR:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue || Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue || Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue || Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue || Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_GREATER:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue > Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue > Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue > Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue > Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_GREATEREQUAL:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue >= Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue >= Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue >= Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue >= Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_LESS:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue < Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue < Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue < Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue < Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_LESSEQUAL:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue <= Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue <= Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue <= Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue <= Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_EQUAL:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue == Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue == Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue == Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue == Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_NOTEQUAL:
                            Value.Type = 0;
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue != Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue != Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.m_lIntegerValue = eoOperand2.m_dFloatingPointValue != Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.m_lIntegerValue =
                                        eoOperand2.m_dFloatingPointValue != Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_SUBTRACT:
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.Type = 0;
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue - Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_lIntegerValue - Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_dFloatingPointValue - Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_dFloatingPointValue - Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_ADD:
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.Type = 0;
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue + Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_lIntegerValue + Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_dFloatingPointValue + Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_dFloatingPointValue + Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_MULTIPLY:
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    Value.Type = 0;
                                    Value.m_lIntegerValue = eoOperand2.m_lIntegerValue * Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_lIntegerValue * Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_dFloatingPointValue * Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    Value.Type = 1;
                                    Value.m_dFloatingPointValue =
                                        eoOperand2.m_dFloatingPointValue * Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        case EXPRESSION_OPERATORS_EXP_DIVIDE:
                        case EXPRESSION_OPERATORS_EXP_MODULUS:
                            if (!eoOperand2.Type)
                            {
                                if (!Value1.Type)
                                {
                                    if (Value1.m_lIntegerValue == 0)
                                    {
                                        if (skip)
                                            Value1.m_dFloatingPointValue = 1.0;
                                        else
                                        {
                                            SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_DIVIDEBYZERO);
                                            goto failure;
                                        }
                                    }
                                    Value.Type = 0;
                                    if (token.type == EXPRESSION_OPERATORS_EXP_DIVIDE)
                                        Value.m_lIntegerValue = eoOperand2.m_lIntegerValue / Value1.m_lIntegerValue;
                                    else
                                        Value.m_lIntegerValue = eoOperand2.m_lIntegerValue % Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    if (Value1.m_dFloatingPointValue == 0)
                                    {
                                        if (skip)
                                            Value1.m_dFloatingPointValue = 1.0;
                                        else
                                        {
                                            SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_DIVIDEBYZERO);
                                            goto failure;
                                        }
                                    }
                                    Value.Type = 1;
                                    if (token.type == EXPRESSION_OPERATORS_EXP_DIVIDE)
                                        Value.m_dFloatingPointValue =
                                            eoOperand2.m_lIntegerValue / Value1.m_dFloatingPointValue;
                                    else
                                        Value.m_dFloatingPointValue =
                                            eoOperand2.m_lIntegerValue % (long)Value1.m_dFloatingPointValue;
                                }
                            }
                            else
                            {
                                if (!Value1.Type)
                                {
                                    if (Value1.m_lIntegerValue == 0)
                                    {
                                        if (skip)
                                            Value1.m_dFloatingPointValue = 1.0;
                                        else
                                        {
                                            SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_DIVIDEBYZERO);
                                            goto failure;
                                        }
                                    }
                                    Value.Type = 1;
                                    if (token.type == EXPRESSION_OPERATORS_EXP_DIVIDE)
                                        Value.m_dFloatingPointValue =
                                            eoOperand2.m_dFloatingPointValue / Value1.m_lIntegerValue;
                                    else
                                        Value.m_dFloatingPointValue =
                                            (long)eoOperand2.m_dFloatingPointValue % Value1.m_lIntegerValue;
                                }
                                else
                                {
                                    if (Value1.m_dFloatingPointValue == 0)
                                    {
                                        if (skip)
                                            Value1.m_dFloatingPointValue = 1.0;
                                        else
                                        {
                                            SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_DIVIDEBYZERO);
                                            goto failure;
                                        }
                                    }
                                    Value.Type = 1;
                                    if (token.type == EXPRESSION_OPERATORS_EXP_DIVIDE)
                                        Value.m_dFloatingPointValue =
                                            eoOperand2.m_dFloatingPointValue / Value1.m_dFloatingPointValue;
                                    else
                                        Value.m_dFloatingPointValue =
                                            (long)eoOperand2.m_dFloatingPointValue % (long)Value1.m_dFloatingPointValue;
                                }
                            }
                            break;
                        default:
                            Warning("SCRIPTS: Unhandled operator '%s' in Expression::Eval()", token.text);
                            Value.Type = 0;
                            Value.m_lIntegerValue = 0;
                        }
                        m_kOperandStack.AddEntry(Value);
                    }
                    else
                    {
                        SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_STACKUNDERFLOW);
                        goto failure;
                    }
                }
            }
            else
            {
                SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_STACKUNDERFLOW);
                goto failure;
            }
        }
        else
        {
            if (IsIntegerString(token.text))
            {
                Value.Type = 0;
                Value.m_lIntegerValue = atol(token.text);
            }
            else if (IsFloatString(token.text))
            {
                Value.Type = 1;
                Value.m_dFloatingPointValue = atof(token.text);
            }
            else
            {
                unsigned int iOffset = 0;
                Value.Type = 1;
                if (skip)
                    Script::GetValue(Value.m_dFloatingPointValue, input.data, iOffset, reference, container, script,
                                     locals, skip);
                else if (!Script::GetValue(Value.m_dFloatingPointValue, token.text, iOffset, reference, container,
                                           script, locals, false))
                {
                    SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_SYNTAX);
                    goto failure;
                }
            }
            if (!cNegate)
                m_kOperandStack.AddEntry(Value);
            else
                cNegate = 0;
        }
        if (input.consumed)
        {
            input.data += input.consumed;
            input.consumed = ParseToken(&pToken, token.text, &token.type, skip, &input.data);
            if (!input.consumed)
                token.text = 0;
        }
    }
    if (!m_kOperandStack.FUN_00594d20())
    {
        Value = m_kOperandStack.PopEntry();
        if (m_kOperandStack.FUN_00594d20())
        {
            if (!Value.Type)
                return Value.m_lIntegerValue;
            else
                return Value.m_dFloatingPointValue;
        }
        else
            SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_SYNTAX);
    }
    else
        SetError(EXPRESSION_ERROR_ERROR_EXPRESSION_SYNTAX);
failure:
    return 0.0;
}

extern "C" int __cdecl _strlen(const char*);
extern "C" int __cdecl _sscanf(const char*, const char*, ...);
int __cdecl FUN_00ec8965(int);
extern const char* const DAT_01019f08;

// @fnv 0x00b37f50
const char* __cdecl FUN_00b37f50(const char* pInput, char* pToken)
{
    while (FUN_00ec8965((int)*pInput))
        pInput++;
    _sscanf(pInput, "%s", pToken);
    return pInput + _strlen(pToken);
}

unsigned int __cdecl FUN_00ec7c56(void);
struct Host00b3b050
{
    int m0;
    int m1;
    Host00b3b050* FUN_00b3b050(int a, int* b);
};
// Sets m0 to 0 and m1 to a, calls FUN_00ec7c56 if b is null, then stores *b into m0 and returns this.
// @fnv 0x00b3b050
Host00b3b050* Host00b3b050::FUN_00b3b050(int aiValue, int* piValue)
{
    m0 = 0;
    m1 = aiValue;
    if (piValue == 0)
        FUN_00ec7c56();
    m0 = *piValue;
    return this;
}

struct FUN_00b3c500
{
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    int i14;
    FUN_00b3c500(float a, float b);
};
// Initializes the object from two floats: stores them in f00 and f04, zeroes f08, f0C and f10, and sets i14 to 2.
// @fnv 0x00b3c500
FUN_00b3c500::FUN_00b3c500(float afFirst, float afSecond)
{
    f00 = afFirst;
    f04 = afSecond;
    f10 = 0.0f;
    f0C = 0.0f;
    f08 = 0.0f;
    i14 = 2;
}

struct Node0394
{
    Node0394* f0;
    Node0394* f1;
    Node0394* f2;
};
struct Holder0394
{
    char _pad[0x18];
    Node0394* f18;
    int f1c;
    void FUN_00b3a050(Node0394*);
    void ResetList();
};
// Calls FUN_00b3a050 on f18->f1, then points f18's f1, f0 and f2 links back to f18 and clears f1c.
// @fnv 0x00b39400
void Holder0394::ResetList()
{
    int padA;
    int padB;
    FUN_00b3a050(f18->f1);
    f18->f1 = f18;
    f1c = 0;
    {
        Node0394* pNode = f18;
        pNode->f0 = f18;
        f18->f2 = f18;
    }
}

struct NodeB
{
    NodeB* f0;
    NodeB* f4;
    NodeB* f8;
    unsigned char f2d;
};
struct FUN_00b3b810_shell
{
    char _pad[0x18];
    NodeB* f18;
    int f1c;
    NodeB* FUN_00b3b880();
    void InitNode();
};
// Gets a node via FUN_00b3b880, sets its byte at 0x2d to 1, points its f0/f4/f8 links at itself, and clears f1c.
// @fnv 0x00b3b810
void FUN_00b3b810_shell::InitNode()
{
    f18 = FUN_00b3b880();
    ((unsigned char*)f18)[0x2d] = 1;
    f18->f4 = f18;
    NodeB* p = f18;
    p->f0 = f18;
    f18->f8 = f18;
    f1c = 0;
}

struct FUN_00b3b1d0_shell
{
    char _pad[0x18];
    NodeB* f18;
    int f1c;
    void FUN_00b3b1d0(NodeB*);
};

// @fnv 0x00b3b1d0
void FUN_00b3b1d0_shell::FUN_00b3b1d0(NodeB* apNode)
{
    NodeB* pNode = apNode->f8;

    apNode->f8 = pNode->f0;
    if (*(signed char*)((char*)pNode->f0 + 0x2D) == 0)
        pNode->f0->f4 = apNode;

    pNode->f4 = apNode->f4;

    if (apNode == f18->f4)
    {
        f18->f4 = pNode;
    }
    else
    {
        NodeB* pPrev = apNode->f4;
        if (apNode == pPrev->f0)
        {
            NodeB* pTarget = apNode->f4;
            pTarget->f0 = pNode;
        }
        else
        {
            apNode->f4->f8 = pNode;
        }
    }

    pNode->f0 = apNode;
    apNode->f4 = pNode;
}

struct FUN_00b3b280_owner : FUN_00b3b810_shell
{
    void FUN_00b3b280(NodeB* pArg);
};

// @fnv 0x00b3b280
void FUN_00b3b280_owner::FUN_00b3b280(NodeB* pNode)
{
    NodeB* pOld = pNode->f0;
    NodeB* pPrev;

    pNode->f0 = pOld->f8;
    if (reinterpret_cast<char*>(pOld->f8)[0x2d] == 0)
        pOld->f8->f4 = pNode;
    pOld->f4 = pNode->f4;

    if (pNode == f18->f4)
        f18->f4 = pOld;
    else if (pNode == pNode->f4->f8)
        pNode->f4->f8 = pOld;
    else
    {
        pPrev = pNode->f4;
        pPrev->f0 = pOld;
    }

    pOld->f8 = pNode;
    pNode->f4 = pOld;
}

void __cdecl FUN_00b3b540(int, int);

struct FUN_00b3b9d0_shell
{
    void FUN_00b3b9d0(int);
};

// @fnv 0x00b3b9d0
void FUN_00b3b9d0_shell::FUN_00b3b9d0(int aiValue)
{
    int local1;
    int local2;
    int local3;
    int local4;
    FUN_00b3b540(aiValue, 0);
}

extern "C" char DAT_010a57e8;
int __cdecl FUN_00ec6da0(const char*, const char*);
long __cdecl FUN_00eca6d3(const char*);
struct InputB37
{
    int pad;
    union
    {
        char text[16];
        char* ptr;
    } data;
    unsigned int length;
    unsigned int capacity;
};
struct VecB37
{
    float x, y;
};
struct HostB37
{
    float x, y, z;
    void FUN_00b380e0(VecB37*, VecB37*, float);
    void FUN_00b37cc0(InputB37*);
};
// Parses x, y, z and an optional list of VecB37 pairs with a float from input, then applies each via FUN_00b380e0.
// @fnv 0x00b37cc0
void HostB37::FUN_00b37cc0(InputB37* input)
{
    const char* _cursor = input->capacity >= 16 ? input->data.ptr : input->data.text;
    char token[256];
    _cursor = FUN_00b37f50(_cursor, token);
    if (FUN_00ec6da0(token, &DAT_010a57e8) == 0)
    {
        _cursor = FUN_00b37f50(_cursor, token);
        x = (float)atof(token);
        _cursor = FUN_00b37f50(_cursor, token);
        y = (float)atof(token);
        _cursor = FUN_00b37f50(_cursor, token);
        z = (float)atof(token);
        _cursor = FUN_00b37f50(_cursor, token);
        if (token[0] == '{')
        {
            _cursor = FUN_00b37f50(_cursor, token);
            int count8 = FUN_00eca6d3(token);
            for (int i5 = 0; i5 < count8; i5++)
            {
                VecB37 second3, first4;
                float value2;
                _cursor = FUN_00b37f50(_cursor, token);
                second3.x = (float)atof(token);
                _cursor = FUN_00b37f50(_cursor, token);
                second3.y = (float)atof(token);
                _cursor = FUN_00b37f50(_cursor, token);
                first4.x = (float)atof(token);
                _cursor = FUN_00b37f50(_cursor, token);
                first4.y = (float)atof(token);
                _cursor = FUN_00b37f50(_cursor, token);
                value2 = (float)atof(token);
                FUN_00b380e0(&second3, &first4, value2);
            }
        }
    }
}

struct FUN_0044d6c0_class
{
    int m0;
    int m1;
    int m2;
    void* FUN_00ec78f1(void*** ppArg);
};
extern "C" __declspec(noreturn) void __stdcall __CxxThrowException(void* pException, void* apThrowInfo);
extern void* DAT_010176f8;
extern const char* const DAT_01140ef8;
// Throws an exception if a*0x30 would overflow an unsigned int, otherwise calls operator new with a*0x30 bytes.
// @fnv 0x00b3b540
void __cdecl FUN_00b3b540(int aiCount, int aiUnused)
{
    if ((unsigned int)aiCount <= 0)
        aiCount = 0;
    else if (-1u / (unsigned int)aiCount < 0x30)
    {
        void** p = 0;
        FUN_0044d6c0_class e5;
        e5.FUN_00ec78f1(&p);
        e5.m0 = (int)&DAT_010176f8;
        __CxxThrowException(&e5, (void*)&DAT_01140ef8);
    }
    operator new(aiCount * 0x30);
}

struct FUN_00b31270
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00b31270();
    ~FUN_00b31270();
};
struct FUN_00449fd0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00449fd0();
    ~FUN_00449fd0();
};
struct FUN_00b377c0
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00b31270 m0;
    FUN_00b31270 m1;
    FUN_00449fd0 m2;
    FUN_00b31270 m3;
    FUN_00b31270 m4;
    FUN_00b377c0(int a0);
    void FUN_00b1c7a0(int a0);
};
// @fnv 0x00b377c0
FUN_00b377c0::FUN_00b377c0(int a0) : m0(), m1(), m2(), m3(), m4()
{
    char buf[0x108];
    int u1;
    FUN_00b1c7a0(a0);
}

unsigned int __cdecl FUN_00ec7c56(void);

struct FUN_00b3f130_shell
{
    float FUN_00b3f130(float, float);
};

struct GlobalObject_00b3f100 : public FUN_00b3f130_shell
{
    GlobalObject_00b3f100();
    ~GlobalObject_00b3f100();
};

struct VecElem
{
    int unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct Sub54
{
    int unk00;
    int unk04;
    int unk08;
    VecElem* m_pHeadNode;
    VecElem* m_last;
    int unk14;
};

struct SplineSampler
{
    int unk00;
    int unk04;
    float unk08;
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
    Sub54 m_vec;

    float Sample(float a1);
};

// With 500 entries in m_vec, returns a random value within +/- unk08 times the unk04 of entry round(a1*499); otherwise returns 0.
// @fnv 0x00b37fa0
float SplineSampler::Sample(float a1)
{
    float val4 = 0.0f;
    int idxTmp;
    Sub54& v1 = m_vec;
    if (v1.m_last - v1.m_pHeadNode == 500)
    {
        idxTmp = (int)(a1 * 499.0 + 0.5);
        Sub54& v2 = m_vec;
        if ((unsigned int)idxTmp >= (unsigned int)(v2.m_last - v2.m_pHeadNode))
        {
            FUN_00ec7c56();
        }
        VecElem& elem9 = v2.m_pHeadNode[idxTmp];
        val4 = elem9.unk04;
        static GlobalObject_00b3f100 s_rand;
        val4 = s_rand.FUN_00b3f130(-unk08 * val4, unk08 * val4);
    }
    return val4;
}
