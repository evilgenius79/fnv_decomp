
// src/fallout/misc/saveload/bgssaveloadstructs.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssaveloadstructs.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00847db0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    void FUN_00847db0();
};

// @fnv 0x00847db0
void FUN_00847db0_shell::FUN_00847db0()
{
    m_0C = 0;
    m_10 = 0;
}

struct FUN_00853dc0_shell
{
    int GetDifference();
};

// @fnv 0x00853dc0
int __thiscall FUN_00853dc0_shell::GetDifference()
{
    return *(int*)((char*)this + 0xc) - *(int*)((char*)this + 0x10);
}

struct FUN_008547f0_shell
{
    unsigned char m_auiShapeKeys[8];
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int __thiscall GetSum();
};

// @fnv 0x008547f0
int __thiscall FUN_008547f0_shell::GetSum()
{
    return m_kPointA + m_kPointB + m_iThirdValue;
}

struct FUN_00854810_shell
{
    int __thiscall GetSumOfFields();
};

// @fnv 0x00854810
int __thiscall FUN_00854810_shell::GetSumOfFields()
{
    return ((int*)this)[0x41] + ((int*)this)[0x42];
}

struct FUN_00854880_shell
{
    unsigned int m_iElementCount;
    unsigned int m_kMinimumCorner;
    unsigned int m_kMaximumCorner;
    unsigned int m_sum;
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    void AccumulateStats(unsigned int a, unsigned int b, unsigned int c);
};

// Increments a counter, adds a, b and c to three running totals, and tracks the minimum and maximum of their sum.
// @fnv 0x00854880
void __thiscall FUN_00854880_shell::AccumulateStats(unsigned int auiValueA, unsigned int auiValueB,
                                                    unsigned int auiValueC)
{
    this->m_iElementCount = this->m_iElementCount + 1;
    this->m_kMinimumCorner = this->m_kMinimumCorner + auiValueA;
    this->m_kMaximumCorner = this->m_kMaximumCorner + auiValueB;
    this->m_sum = this->m_sum + auiValueC;
    unsigned int uiSum = auiValueA + auiValueB + auiValueC;
    if (uiSum < this->m_ucLowNibble)
        this->m_ucLowNibble = uiSum;
    if (uiSum > this->m_ucHighNibble)
        this->m_ucHighNibble = uiSum;
}

struct FUN_00854900_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int FUN_00854900();
};

// @fnv 0x00854900
int FUN_00854900_shell::FUN_00854900()
{
    return m_04 + m_08 + m_0c;
}

extern int DAT_011a2428[];

// Masks the low 6 bits of the first byte and returns the entry at that index from DAT_011a2428.
// @fnv 0x00853640
int __fastcall FUN_00853640(unsigned char* pData)
{
    unsigned char v = pData[0] & 0x3f;
    return DAT_011a2428[v];
}

extern int DAT_011a11fc[1000];
extern int DAT_011a216c[1000];

// Returns DAT_011a216c[index] when index is below 1000, otherwise DAT_011a11fc[index - 1000].
// @fnv 0x00853de0
int FUN_00853de0(unsigned int index)
{
    int result;
    if (index >= 1000)
        result = DAT_011a11fc[index - 1000];
    else
        result = DAT_011a216c[index];
    return result;
}

struct FUN_00854830_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    FUN_00854830_shell();
};

// @fnv 0x00854830
FUN_00854830_shell::FUN_00854830_shell()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0C = 0;
    m_10 = 0xffffffff;
    m_14 = 0;
}

int __fastcall FUN_00853640(unsigned char* param_1);
struct FUN_00849220_shell
{
    unsigned char* p;
    int __thiscall FUN_00849220();
};
// @fnv 0x00849220
int __thiscall FUN_00849220_shell::FUN_00849220()
{
    return FUN_00853640(p);
}

struct FormIDConverter
{
    unsigned int RegisterFormID(unsigned int);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct BGSSaveLoadGame;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct FUN_00853570_shell
{
    void WriteFormIDBytes(unsigned int numericID);
};
// @fnv 0x00853570
void FUN_00853570_shell::WriteFormIDBytes(unsigned int numericID)
{
    unsigned int iElementIndex = reinterpret_cast<FormIDConverter*>(reinterpret_cast<ArrSI*>(g_BGSSaveLoadGame)->GetFlags())
                              ->RegisterFormID(numericID);
    unsigned int ifileIndex = iElementIndex >> 24;
    if (ifileIndex == 0xFF)
        iElementIndex |= 0x800000;
    ((unsigned char*)this)[0] = (unsigned char)(iElementIndex >> 16);
    ((unsigned char*)this)[1] = (unsigned char)(iElementIndex >> 8);
    ((unsigned char*)this)[2] = (unsigned char)iElementIndex;
}

extern "C" void* memset(void*, int, unsigned int);
extern int DAT_011a2428[];
extern unsigned int DAT_011de3e0;
extern unsigned char DAT_011de360[];
// Fills DAT_011de360 with 255, sets DAT_011de3e0 to 55, then stores each index i at DAT_011de360[DAT_011a2428[i]].
// @fnv 0x008535e0
void FUN_008535e0()
{
    memset(&DAT_011de360, 255, 121);
    DAT_011de3e0 = 55;
    for (unsigned int uiIndex = 0; uiIndex < DAT_011de3e0; ++uiIndex)
        DAT_011de360[DAT_011a2428[uiIndex]] = uiIndex;
}

struct FUN_00853670_shell
{
    unsigned char m0;
    void __thiscall FUN_00853670(int);
};
extern unsigned char DAT_011de360[];
extern unsigned int DAT_011de3e0;
char const* __cdecl GetStringForByte(unsigned char);
void __cdecl _fnv_call_845cc0(char const*, ...);
// @fnv 0x00853670
void __thiscall FUN_00853670_shell::FUN_00853670(int formType)
{
    unsigned char type = DAT_011de360[formType];
    if (type >= DAT_011de3e0)
    {
        _fnv_call_845cc0("Unknown form type %i %s in BGSSaveLoadFormInfo::SetFormType()", formType,
                         GetStringForByte((unsigned char)formType));
    }
    m0 = (m0 & ~0x3F) | type;
}

void __cdecl operator delete(void*);
struct FUN_00853880_shell
{
    void __thiscall FUN_008538b0();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_008538b0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00853880
void* __thiscall FUN_00853880_shell::Destroy(unsigned int flags)
{
    FUN_008538b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Dummy008539e0
{
    virtual int Func(int);
};
struct FUN_008539e0_holder
{
    int _pad[6];
    Dummy008539e0* m_ptr;
    void FUN_008539e0();
};
// Calls Func(1) on m_ptr if it is non-null, then sets m_ptr to 0.
// @fnv 0x008539e0
void FUN_008539e0_holder::FUN_008539e0()
{
    Dummy008539e0* b = m_ptr;
    Dummy008539e0* a = b;
    a ? a->Func(1) : 0;
    m_ptr = 0;
}

struct FUN_00854920_shell : FUN_00854900_shell
{
    float __thiscall GetRatio();
};
// @fnv 0x00854920
float __thiscall FUN_00854920_shell::GetRatio()
{
    return (float)((double)(unsigned int)FUN_00854900() / (double)(unsigned int)m_00);
}

// Compares the values returned by calling GetSum on both objects, returning -1 if the first is greater, 1 if less, else 0.
// @fnv 0x00854960
int FUN_00854960(FUN_008547f0_shell* pFirst, FUN_008547f0_shell* pSecond)
{
    unsigned int x = pFirst->GetSum();
    unsigned int y = pSecond->GetSum();
    {
        int r;
        if (x > y)
            r = -1;
        else
            r = x < y;
        return r;
    }
}

struct TESForm
{
    virtual bool v00() = 0;
    virtual bool v01() = 0;
    virtual bool v02() = 0;
    virtual bool v03() = 0;
    virtual bool v04() = 0;
    virtual bool v05() = 0;
    virtual bool v06() = 0;
    virtual bool v07() = 0;
    virtual bool v08() = 0;
    virtual bool v09() = 0;
    virtual bool v10() = 0;
    virtual bool v11() = 0;
    virtual bool v12() = 0;
    virtual bool v13() = 0;
    virtual bool v14() = 0;
    virtual bool v15() = 0;
    virtual bool v16() = 0;
    virtual bool v17() = 0;
    virtual bool v18() = 0;
    virtual bool v19() = 0;
    virtual bool v20() = 0;
    virtual bool v21() = 0;
    virtual bool v22() = 0;
    virtual bool v23() = 0;
    virtual bool v24() = 0;
    virtual bool v25() = 0;
    virtual bool v26() = 0;
    virtual bool v27() = 0;
    virtual bool v28() = 0;
    virtual bool v29() = 0;
    virtual bool v30() = 0;
    virtual bool v31() = 0;
    virtual bool v32() = 0;
    virtual bool v33() = 0;
    virtual bool v34() = 0;
    virtual bool v35() = 0;
    virtual bool v36() = 0;
    virtual bool v37() = 0;
    virtual bool v38() = 0;
    virtual bool v39() = 0;
    virtual bool v40() = 0;
    virtual bool v41() = 0;
    virtual bool v42() = 0;
    virtual bool v43() = 0;
    virtual bool v44() = 0;
    virtual bool v45() = 0;
    virtual bool v46() = 0;
    virtual bool v47() = 0;
    virtual bool v48() = 0;
    virtual bool v49() = 0;
    virtual bool v50() = 0;
    virtual bool v51() = 0;
    virtual bool v52() = 0;
    virtual bool v53() = 0;
    virtual bool v54() = 0;
    virtual bool v55() = 0;
    virtual bool v56() = 0;
    virtual bool v57() = 0;
    virtual bool v58() = 0;
    virtual bool v59() = 0;
    virtual bool IsMobileObject() = 0;
    virtual bool v61() = 0;
    virtual bool v62() = 0;
    virtual bool v63() = 0;
    virtual bool v64() = 0;
    virtual bool v65() = 0;
    virtual bool v66() = 0;
    virtual bool v67() = 0;
    virtual bool v68() = 0;
    virtual bool v69() = 0;
    virtual bool v70() = 0;
    virtual bool v71() = 0;
    virtual bool v72() = 0;
    virtual bool v73() = 0;
    virtual bool v74() = 0;
    virtual bool v75() = 0;
    virtual char const* GetName() = 0;
    unsigned int FNV_GetFormType() const;
};

struct MobileObject : TESForm
{
    char const* __thiscall GetFullName();
};

struct TESObjectREFR : MobileObject
{
};

struct TESQuest
{
    virtual bool q00() = 0;
    virtual bool q01() = 0;
    virtual bool q02() = 0;
    virtual bool q03() = 0;
    virtual bool q04() = 0;
    virtual bool q05() = 0;
    virtual bool q06() = 0;
    virtual bool q07() = 0;
    virtual bool q08() = 0;
    virtual bool q09() = 0;
    virtual bool q10() = 0;
    virtual bool q11() = 0;
    virtual bool q12() = 0;
    virtual bool q13() = 0;
    virtual bool q14() = 0;
    virtual bool q15() = 0;
    virtual bool q16() = 0;
    virtual bool q17() = 0;
    virtual bool q18() = 0;
    virtual bool q19() = 0;
    virtual bool q20() = 0;
    virtual bool q21() = 0;
    virtual bool q22() = 0;
    virtual bool q23() = 0;
    virtual bool q24() = 0;
    virtual bool q25() = 0;
    virtual bool q26() = 0;
    virtual bool q27() = 0;
    virtual bool q28() = 0;
    virtual bool q29() = 0;
    virtual bool q30() = 0;
    virtual bool q31() = 0;
    virtual bool q32() = 0;
    virtual bool q33() = 0;
    virtual bool q34() = 0;
    virtual bool q35() = 0;
    virtual bool q36() = 0;
    virtual bool q37() = 0;
    virtual bool q38() = 0;
    virtual bool q39() = 0;
    virtual bool q40() = 0;
    virtual bool q41() = 0;
    virtual bool q42() = 0;
    virtual bool q43() = 0;
    virtual bool q44() = 0;
    virtual bool q45() = 0;
    virtual bool q46() = 0;
    virtual bool q47() = 0;
    virtual bool q48() = 0;
    virtual bool q49() = 0;
    virtual bool q50() = 0;
    virtual bool q51() = 0;
    virtual bool q52() = 0;
    virtual bool q53() = 0;
    virtual bool q54() = 0;
    virtual bool q55() = 0;
    virtual bool q56() = 0;
    virtual bool q57() = 0;
    virtual bool q58() = 0;
    virtual bool q59() = 0;
    virtual bool q60() = 0;
    virtual bool q61() = 0;
    virtual bool q62() = 0;
    virtual bool q63() = 0;
    virtual bool q64() = 0;
    virtual bool q65() = 0;
    virtual bool q66() = 0;
    virtual bool q67() = 0;
    virtual bool q68() = 0;
    virtual bool q69() = 0;
    virtual bool q70() = 0;
    virtual bool q71() = 0;
    virtual bool q72() = 0;
    virtual bool q73() = 0;
    virtual bool q74() = 0;
    virtual bool q75() = 0;
    virtual bool q76() = 0;
    virtual bool q77() = 0;
    virtual char const* GetName() = 0;
};

struct TESTopicInfo : TESForm
{
    TESQuest* __thiscall GetParentQuest();
};

struct TESFullName
{
    static char const* __cdecl GetFullName(TESForm*);
};

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

unsigned int __cdecl _BSStringLength(char const*);

struct FormNameEntry
{
    unsigned int iFormID;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    TESForm* pForm;
    unsigned int m_18;

    void __thiscall BuildFormName(char* apName, unsigned int aiNameSize);
};

// @fnv 0x008536d0
void __thiscall FormNameEntry::BuildFormName(char* apName, unsigned int aiNameSize)
{
    TESObjectREFR* pRefr;
    TESTopicInfo* pTopicInfo;

    if (!this->pForm)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, "UNLOADED");
        return;
    }

    pRefr = this->pForm->IsMobileObject() ? static_cast<TESObjectREFR*>(this->pForm) : 0;

    if (pRefr)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, pRefr->GetFullName());
    }
    else
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, TESFullName::GetFullName(this->pForm));
    }

    if (_BSStringLength(apName) == 0)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, this->pForm->GetName());
    }

    if (_BSStringLength(apName) == 0)
    {
        switch (this->pForm->FNV_GetFormType())
        {
        case 0x46:
            pTopicInfo = static_cast<TESTopicInfo*>(this->pForm);
            TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, pTopicInfo->GetParentQuest()->GetName());
            break;
        }
    }
}

void* operator new(unsigned int);

int __cdecl FUN_00854960(FUN_008547f0_shell*, FUN_008547f0_shell*);

struct AEList
{
    void* m_auiShapeKeys[2];

    void Insert(void*, int(__cdecl*)(void*, void*));
};

struct SL : public AEList
{
    SL();
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};

struct FUN_00854af0
{
    unsigned char m_data[25];

    FUN_00854af0();
};

struct FUN_008549b0_shell
{
    void __thiscall FUN_008549b0(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                 unsigned int, unsigned char);
};

// @fnv 0x008549b0
void __thiscall FUN_008549b0_shell::FUN_008549b0(unsigned int p0, unsigned int p1, unsigned int uiKey, unsigned int p3,
                                                 unsigned int p4, unsigned int p5, unsigned int p6, unsigned char p7)
{
    FUN_00854af0* form = new FUN_00854af0();

    reinterpret_cast<unsigned int*>(form)[0] = p0;
    reinterpret_cast<unsigned int*>(form)[5] = p1;
    reinterpret_cast<unsigned int*>(form)[1] = p3;
    reinterpret_cast<unsigned int*>(form)[2] = p4;
    reinterpret_cast<unsigned int*>(form)[3] = p5;
    reinterpret_cast<unsigned int*>(form)[4] = p6;
    form->m_data[0x18] = p7;

    {
        unsigned int list = 0;

        if (!reinterpret_cast<DummyPointerMap*>(this)->GetAt(uiKey, list))
        {
            list = reinterpret_cast<unsigned int>(new SL());
            reinterpret_cast<SetAtHelper*>(this)->SetAt(uiKey, list);
        }

        reinterpret_cast<AEList*>(list)->Insert(form, reinterpret_cast<int(__cdecl*)(void*, void*)>(FUN_00854960));
    }
}

struct FUN_00854c80_shell
{
    virtual ~FUN_00854c80_shell();
    int m_04;
    int m_08;
    int m_0C;
    FUN_00854c80_shell(int formType);
};

struct FUN_0096a2d0_shell
{
    int m_10;
    int m_14;
    FUN_0096a2d0_shell();
};

struct FUN_00853810 : FUN_00854c80_shell
{
    FUN_0096a2d0_shell m_data;
    int m_18;
    FUN_00853810();
    virtual ~FUN_00853810();
};

// Constructs the object with base form type 0x25 and initializes m_18 to 0.
// @fnv 0x00853810
FUN_00853810::FUN_00853810() : FUN_00854c80_shell(0x25)
{
    m_18 = 0;
}

struct ResourceView
{
    virtual ~ResourceView();
};
struct StringListNode
{
    char* item;
    StringListNode* next;
    ~StringListNode();
    char** FUN_006815c0();
    StringListNode* FUN_00726070();
};
struct MapBase
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    ~MapBase();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, StringListNode*&);
};
struct FUN_008538b0 : MapBase
{
    StringListNode owned;
    ResourceView* resource;
    ~FUN_008538b0();
};
// Deletes resource, then frees every stored pointer in the map's buckets and in the owned list, walking each linked list.
// @fnv 0x008538b0
FUN_008538b0::~FUN_008538b0()
{
    delete resource;
    void* position = FUN_004b9ba0();
    while (position)
    {
        unsigned int key = 0;
        StringListNode* list = 0;
        FUN_006b7f20(position, key, list);
        while (list)
        {
            delete *list->FUN_006815c0();
            list = list->FUN_00726070();
        }
    }
    StringListNode* list = &owned;
    while (list)
    {
        delete *list->FUN_006815c0();
        list = list->FUN_00726070();
    }
}

// Prepare a dialogue response for the speaker: reset it, fill it from the speaker/topic, then notify.

class B4B10Response;

class B4B10Speaker
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void OnResponseReady(B4B10Response* pkResponse);

    void* GetVoiceType();
    unsigned int GetFormType();
};

class B4B10DialogueManager
{
  public:
    int GetCurrentID();
};
extern B4B10DialogueManager* g_pkB4B10DialogueManager;

class B4B10Response
{
  public:
    void Reset();
    void Init(void* pvVoiceType, int iTopic, unsigned int uiFormType, int m_uiSoundID);
    void SetSpeaker(B4B10Speaker* pkSpeaker);
};

void __cdecl B4B10SetupResponse(B4B10Response* pkResponse, B4B10Speaker* pkSpeaker, int iTopic);

class B4B10Dialogue
{
  public:
    void SetupResponse(B4B10Speaker* pkSpeaker, int iTopic, B4B10Response* pkResponse);
};

// Resets and initialises the response from the speaker's voice type, form type and current dialogue ID, then sets the speaker and notifies it.
// @fnv 0x00854b10
void B4B10Dialogue::SetupResponse(B4B10Speaker* pkSpeaker, int iTopic, B4B10Response* pkResponse)
{
    pkResponse->Reset();
    pkResponse->Init(pkSpeaker->GetVoiceType(), iTopic, pkSpeaker->GetFormType(),
                     g_pkB4B10DialogueManager->GetCurrentID());
    pkResponse->SetSpeaker(pkSpeaker);
    B4B10SetupResponse(pkResponse, pkSpeaker, iTopic);
    pkSpeaker->OnResponseReady(pkResponse);
}

struct SavedBuffer
{
    void* vtable;
    void* data;
    unsigned int capacity;
    unsigned int position;
    unsigned int size;
    void* references;
    unsigned int referenceCount;
    unsigned char version;
    unsigned int flags;
    SavedBuffer();
    ~SavedBuffer();
    void FUN_00847db0();
    unsigned char GetVersion();
    unsigned int FUN_0044edb0();
    unsigned int GetValuePlusNine();
    int GetDifference();
};
struct SavedDataView
{
    void* data;
    void* FUN_00559450();
    unsigned char FUN_0084b450();
    unsigned int GetAdjustedValue();
    unsigned int FUN_008663e0();
    int FUN_00849220();
};
struct SavedEntry
{
    unsigned int topic;
    SavedDataView buffer;
};
struct SavedEntryMap
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, SavedEntry*&);
};
struct BGSSaveLoadGame
{
    SavedEntryMap* FUN_00559450();
};
TESForm* __cdecl LookupFormByID(unsigned int);
bool __cdecl FUN_0084bcd0(unsigned int, SavedBuffer*);
struct SavedStats
{
    void LoadStats();
    void FUN_008549b0(unsigned int, TESForm*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                      unsigned char);
    void SetupResponse(TESForm*, unsigned int, SavedBuffer*);
    void FUN_00854c10(int, int, unsigned int);
};
// Iterates saved entries, applying each to stats via FUN_008549b0, then processes indices 0-11 and 1000 through FUN_0084bcd0 and FUN_00854c10.
// @fnv 0x00853b90
void SavedStats::LoadStats()
{
    SavedBuffer map;
    SavedEntryMap* buffer = g_BGSSaveLoadGame->FUN_00559450();
    void* position = buffer->FUN_004b9ba0();
    while (position)
    {
        unsigned int entryId = 0;
        SavedEntry* pEntry = 0;
        buffer->FUN_006b7f20(position, entryId, pEntry);
        if (pEntry->buffer.FUN_00559450())
        {
            FUN_008549b0(entryId, 0, pEntry->buffer.FUN_00849220(), pEntry->topic, pEntry->buffer.FUN_008663e0(),
                         pEntry->buffer.GetAdjustedValue(), 0, pEntry->buffer.FUN_0084b450());
        }
        else
        {
            TESForm* form = LookupFormByID(entryId);
            if (form)
            {
                SetupResponse(form, pEntry->topic, &map);
                FUN_008549b0(entryId, form, form->FNV_GetFormType(), pEntry->topic, map.GetDifference(),
                             map.GetValuePlusNine(), map.FUN_0044edb0(), map.GetVersion());
            }
        }
    }
    for (unsigned int index = 0; index < 12; ++index)
    {
        map.FUN_00847db0();
        if (FUN_0084bcd0(index, &map))
            FUN_00854c10(FUN_00853de0(index), map.GetDifference(), map.FUN_0044edb0());
    }
    for (unsigned int index = 1000; index < 1001; ++index)
    {
        map.FUN_00847db0();
        if (FUN_0084bcd0(index, &map))
            FUN_00854c10(FUN_00853de0(index), map.GetDifference(), map.FUN_0044edb0());
    }
}

#include <windows.h>
int GameStrcpy(char* dst, unsigned int size, const char* src);
int GameStrcat(char* dst, unsigned int size, const char* src);
int FUN_00ecbf05(const char* path, int mode);

struct BSFile
{
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
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    BSFile(const char* name, int mode, unsigned int bufferSize, bool textMode);
};

struct TextDumpWriter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TextDumpWriter();
    ~TextDumpWriter();
    void SetFile(BSFile* file);
    void WriteHeader();
    void WriteBody();
    void Close();
};

// Creates a .txt file from baseName, writes its header and body, then calls ShellExecuteA with the open verb.
// @fnv 0x00853a30
void DumpTextAndOpen(const char* baseName)
{
    TextDumpWriter writer;
    char path[260];
    GameStrcpy(path, 260, baseName);
    GameStrcat(path, 260, ".txt");
    if (FUN_00ecbf05(path, 0) != -1)
        DeleteFileA(path);
    writer.SetFile(new BSFile(path, 1, 0x4000, false));
    writer.WriteHeader();
    writer.WriteBody();
    writer.Close();
    ShellExecuteA(0, "open", path, 0, 0, 5);
}

namespace fnv_00853e10 {
void* _fnv_zlib_memset(void*, int, unsigned int);

int xSprintf(char*, unsigned int, const char*, ...);
int xStrcpy(char*, unsigned int, const char*);
int xStrcat(char*, unsigned int, const char*);
int xMbsnicmp(const char*, const char*, unsigned int);
const char* xFlagName(unsigned int, unsigned int, int);
struct xTypeName
{
    const char* m_name;
    int m_kPointA, m_kPointB;
};
extern xTypeName xg_TypeNames[];
struct xSizeArg
{
    xSizeArg(int);
    xSizeArg(const xSizeArg&);
    int m_v;
};
struct xSizer
{
    xSizer();
    ~xSizer();
    int GetSize();
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20;
};
struct xStats
{
    xStats();
    void Add(unsigned int, unsigned int, unsigned int);
    int GetTotal();
    float GetAverage();
    int m_uiItemCount, m_data, m_overhead, m_pDebugAllocator, m_kMinimumCorner, m_kMaximumCorner;
};
struct xLevelHolder
{
    int GetLevel();
};

struct xForm
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
    virtual bool IsActorType();
    virtual void v61();
    virtual void v62();
    virtual bool HasLevel();
    xLevelHolder* GetLevelHolder();
};

struct xChangeFlags
{
    bool Test(unsigned int) const;
    operator unsigned int();
    unsigned int m_v;
};
struct xChange
{
    unsigned int m_formID;
    xChangeFlags m_flags;
    unsigned int m_8, m_iThirdValue, m_10;
    xForm* m_form;
    unsigned char m_ver;
    void Describe(char*, unsigned int);
    int GetSize();
};
struct xNodeL
{
    void** Head();
    xNodeL* Next();
    int m_kPointA, m_kPointB;
};
struct xMisc
{
    char m_name[0x104];
    unsigned int m_104, m_108;
    int GetCount();
};
struct xHistory
{
    const char* GetAt(unsigned int);
};
struct xSaveLoad
{
    xHistory* GetHistory();
};
extern xSaveLoad* xg_SaveLoad;
int __fastcall xHistoryCount(xHistory*);
struct SaveLoadStatsDump
{
    int m_00, m_04, m_08, m_0c;
    xNodeL m_10;
    void FUN_00853e10();
    void Write(const char*);
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, xNodeL*&);
    void Measure(xForm*, xSizeArg, xSizer*);
};

// Writes a formatted dump of save/load form stats, misc stats, and save game history via Write.
// @fnv 0x00853e10
void SaveLoadStatsDump::FUN_00853e10()
{
    void* qfTOqo;
    int qsSDDgz;
    xHistory* qSVM;
    int qpTd;
    xNodeL* qvyWyw;
    xSizer qpqRa;
    xStats qdqWL;
    char qHXYKT[0x3e8];
    xSprintf(qHXYKT, 0x3e8, "  %-8s %-5s %-8s %3s %-40s  %s\r\n\r\n", "Form ID", "Size", "Flags", "Ver", "Name",
             "Changes");
    Write(qHXYKT);
    qfTOqo = GetFirstPos();
    while (qfTOqo)
    {
        unsigned int qxQHW;
        xNodeL* qArxcFu;
        xStats qAhbO;
        qxQHW = 0;
        qArxcFu = 0;
        GetNext(qfTOqo, qxQHW, qArxcFu);
        xSprintf(qHXYKT, 0x3e8, "%ss:\r\n\r\n", xg_TypeNames[qxQHW].m_name);
        Write(qHXYKT);
        while (qArxcFu)
        {
            xChange* qJDuOZ = (xChange*)*qArxcFu->Head();
            if (qJDuOZ)
            {
                char qpia[0x3e8];
                qpia[0] = *"";
                _fnv_zlib_memset(qpia + 1, 0, sizeof(qpia) - 1);
                xForm* qZWI;
                char qQGWBE[0x3e8];
                int qkJsUdT;
                char qIrY[0x3e8];
                char qdbVTq[0x3e8];
                qZWI = 0;
                qkJsUdT = 0;
                if (qJDuOZ->m_form)
                {
                    Measure(qJDuOZ->m_form, xSizeArg(0), &qpqRa);
                    qkJsUdT = qpqRa.GetSize();
                    if (qkJsUdT)
                    {
                        xStrcpy(qQGWBE, 0x3e8, "Base");
                        if (qJDuOZ->m_form->IsActorType())
                        {
                            qZWI = qJDuOZ->m_form;
                            if (qZWI->HasLevel())
                            {
                                xForm* qIpA = qZWI;
                                int qXMUYT = -1;
                                if (qIpA->GetLevelHolder())
                                    qXMUYT = qIpA->GetLevelHolder()->GetLevel();
                                switch (qXMUYT)
                                {
                                case -1:
                                    xStrcpy(qQGWBE, 0x3e8, "None");
                                    break;
                                case 3:
                                    xStrcpy(qQGWBE, 0x3e8, "Low");
                                    break;
                                case 2:
                                    xStrcpy(qQGWBE, 0x3e8, "Mid Low");
                                    break;
                                case 1:
                                    xStrcpy(qQGWBE, 0x3e8, "Mid High");
                                    break;
                                case 0:
                                    xStrcpy(qQGWBE, 0x3e8, "High");
                                    break;
                                }
                            }
                        }
                        xSprintf(qdbVTq, 0x3e8, "%s(%i)", qQGWBE, qkJsUdT);
                        xSprintf(qIrY, 0x3e8, "%-25s", qdbVTq);
                        xStrcat(qpia, 0x3e8, qIrY);
                    }
                }
                for (unsigned int qbfQdhM = 0; qbfQdhM < 0x20; qbfQdhM++)
                {
                    unsigned int qAXSCg = 1 << qbfQdhM;
                    if (qJDuOZ->m_flags.Test(qAXSCg))
                    {
                        xStrcpy(qQGWBE, 0x3e8, xFlagName(qAXSCg, qxQHW, 1));
                        if (qJDuOZ->m_form)
                        {
                            Measure(qJDuOZ->m_form, xSizeArg(qAXSCg), &qpqRa);
                            xSprintf(qdbVTq, 0x3e8, "%s(%i)", qQGWBE, qpqRa.GetSize() - qkJsUdT);
                        }
                        else
                            xSprintf(qdbVTq, 0x3e8, "%s", qQGWBE);
                        xSprintf(qIrY, 0x3e8, "%-25s", qdbVTq);
                        xStrcat(qpia, 0x3e8, qIrY);
                    }
                }
                xStrcpy(qQGWBE, 0x3e8, "");
                qJDuOZ->Describe(qQGWBE, 0x3e8);
                xSprintf(qHXYKT, 0x3e8, "  %08X %5i %08X %3i %-40s- %s\r\n", qJDuOZ->m_formID, qJDuOZ->GetSize(),
                         (unsigned int)qJDuOZ->m_flags, qJDuOZ->m_ver, qQGWBE, qpia);
                Write(qHXYKT);
            }
            qAhbO.Add(qJDuOZ->m_8, qJDuOZ->m_iThirdValue, qJDuOZ->m_10);
            qdqWL.Add(qJDuOZ->m_8, qJDuOZ->m_iThirdValue, qJDuOZ->m_10);
            qArxcFu = qArxcFu->Next();
        }
        xSprintf(
            qHXYKT, 0x3e8,
            "\r\nTotal %s Count: %i  Total %s Size: %i - Data: %i Overhead: %i Debug: %i Min %s Size: %i  Max %s Size: %i  Average %s Size: %.2f\r\n\r\n",
            xg_TypeNames[qxQHW].m_name, qAhbO.m_uiItemCount, xg_TypeNames[qxQHW].m_name, qAhbO.GetTotal(), qAhbO.m_data,
            qAhbO.m_overhead, qAhbO.m_pDebugAllocator, xg_TypeNames[qxQHW].m_name, qAhbO.m_kMinimumCorner,
            xg_TypeNames[qxQHW].m_name, qAhbO.m_kMaximumCorner, xg_TypeNames[qxQHW].m_name, qAhbO.GetAverage());
        Write(qHXYKT);
    }
    xSprintf(
        qHXYKT, 0x3e8,
        "\r\nTotal Form Count: %i  Total Form Size: %i - Data: %i Overhead: %i Debug: %i  Min Form Size: %i  Max Form Size: %i  Average Form Size: %.2f\r\n\r\n",
        qdqWL.m_uiItemCount, qdqWL.GetTotal(), qdqWL.m_data, qdqWL.m_overhead, qdqWL.m_pDebugAllocator,
        qdqWL.m_kMinimumCorner, qdqWL.m_kMaximumCorner, qdqWL.GetAverage());
    Write(qHXYKT);
    xStats qrEZrs;
    Write("\r\nMisc Stats:\r\n\r\n");
    qvyWyw = &m_10;
    while (qvyWyw)
    {
        xMisc* qBLsiu = (xMisc*)*qvyWyw->Head();
        if (qBLsiu)
        {
            xSprintf(qHXYKT, 0x3e8, "  %8i      %s\r\n", qBLsiu->GetCount(), qBLsiu);
            Write(qHXYKT);
            qrEZrs.Add(qBLsiu->m_104, 0, qBLsiu->m_108);
        }
        qvyWyw = qvyWyw->Next();
    }
    xSprintf(
        qHXYKT, 0x3e8,
        "\r\nTotal Misc Count: %i  Total Misc Size: %i - Data: %i Overhead: %i Debug: %i  Min Misc Size: %i  Max Misc Size: %i  Average Misc Size: %.2f\r\n\r\n",
        qrEZrs.m_uiItemCount, qrEZrs.GetTotal(), qrEZrs.m_data, qrEZrs.m_overhead, qrEZrs.m_pDebugAllocator,
        qrEZrs.m_kMinimumCorner, qrEZrs.m_kMaximumCorner, qrEZrs.GetAverage());
    Write(qHXYKT);
    qSVM = xg_SaveLoad->GetHistory();
    qpTd = xHistoryCount(qSVM);
    qsSDDgz = 0;
    if (qpTd)
    {
        Write("\r\n\r\nSave Game History:\r\n\r\n");
        for (unsigned int qrUCJDN = 0; qrUCJDN < (unsigned int)qpTd; qrUCJDN++)
        {
            const char* qpydTG = qSVM->GetAt(qrUCJDN);
            int qyFp = 0;
            if (!xMbsnicmp(qpydTG, "***", 3))
                qyFp = 1;
            else if (!xMbsnicmp(qpydTG, "---", 3))
            {
                qyFp = -1;
                qsSDDgz--;
            }
            for (int qhQRuW = 0; qhQRuW < qsSDDgz; qhQRuW++)
                Write("  ");
            Write(qyFp ? qpydTG + 3 : qpydTG);
            Write("\r\n");
            if (qyFp == 1)
                qsSDDgz++;
        }
    }
}
}  // namespace fnv_00853e10
