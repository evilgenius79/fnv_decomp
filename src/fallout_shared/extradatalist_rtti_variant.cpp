
// src/fallout_shared/extradatalist_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BSExtraData, TESPackage). The skeleton of src/fallout_shared/extradatalist.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "extradatalist_packet_rtti_extradatalist.h"
#include "ExtraDataList.h"
#include "ExtraContainerChanges_rtti_extradatalist.h"
#include "InventoryChanges.h"
#include "game_constants.h"

struct P3Q
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
    virtual bool IsX();
};
struct MTQ
{
    virtual void m0();
    virtual void m1();
    virtual int GetCaster();
};
class NonActorMagicTarget : public BSExtraData
{
  public:
    MTQ kMT;
};
struct ResQ
{
    void FUN_00483710();
};
void __cdecl FUN_00806130(int a, int b);
struct OwnQ
{
    ResQ* FUN_00418460();
    BSExtraData* GetExtraData(int iType);
    void FUN_00426720(unsigned int uiFlags, int a2, P3Q* p3);
};
// @fnv 0x00426720
void OwnQ::FUN_00426720(unsigned int uiFlags, int a2, P3Q* p3)
{
    bool bSkip = false;
    if (p3 && p3->IsX())
        bSkip = true;
    if (!bSkip)
    {
        if (uiFlags & 0x20000)
        {
            ResQ* pRes = FUN_00418460();
            pRes->FUN_00483710();
        }
        if (uiFlags & 0)
        {
            NonActorMagicTarget* pTarget = dynamic_cast<NonActorMagicTarget*>(GetExtraData(0x33));
            if (pTarget)
                FUN_00806130(pTarget->kMT.GetCaster(), 0);
        }
    }
}

void* __cdecl memset(void* dst, int value, unsigned int size);
class type_info;
// ExtraDataList::LoadGame (FUN_00428150)
class TESGlobal : public TESForm
{
};
class ScriptEventList;
class Script : public TESForm
{
  public:
    ScriptEventList* CreateEventList();
};
class TESAmmo : public TESForm
{
};
class BGSEncounterZone : public TESForm
{
};
class TESKey : public TESForm
{
};
class TESFaction : public TESForm
{
};
class TESTopic : public TESForm
{
};
class TESTopicInfo : public TESForm
{
};
class TESBoundObject : public TESForm
{
};
class ActorBaseData
{
  public:
    bool IsValid();  // 0x47cdb0
};
class TESActorBase : public TESForm
{
  public:
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ActorBaseData kBaseData;
};
class MagicItem
{
  public:
    virtual ~MagicItem();
};
class AlchemyItem : public MagicItem
{
};
struct ExtraSpecialRenderFlags
{
  public:
    virtual ~ExtraSpecialRenderFlags();
    unsigned int GetFlags();            // 0x84e3a0
    void SetFlags(unsigned int flags);  // 0x41fd00
};
extern "C" void* __cdecl __RTDynamicCast(void* inptr, long vfdelta, void* srcType, void* targetType, int isReference);
struct LoadFlags
{
    unsigned int uiFlags;
    LoadFlags(unsigned int flags);  // 0x8c71b0
    bool IsSet(unsigned int mask);  // 0x4280f0
};
class LoadBuffer
{
  public:
    virtual unsigned char GetVersion();
    virtual void v01();
    virtual class LoadRef* GetRef();
    virtual class LoadRef* GetActor();
    void Read(void* dst, unsigned int size);  // 0x864980
    void ReadRefID(void* dst);                // 0x8648e0
    unsigned int GetRefID();                  // 0x8648a0
    unsigned int ReadCount();                 // 0x864a60
    void ReadString(char* dst);               // 0x8649a0
    LoadFlags GetFlags();                     // 0x428110
    void SetFlags(LoadFlags flags);           // 0x428130
    LoadFlags GetFlags2();                    // 0x42ce30
    void SetFlags2(LoadFlags flags);          // 0x86cf00
    unsigned char GetFlagByte();              // 0x42ce90
    void SetFlagByte(unsigned char b);        // 0x42ce50
    void SetForm(void* form);                 // 0x7037c0
};
class RefSub
{
  public:
    void Reset();  // 0x41aeb0
};
class RefProc
{
  public:
    void Reset1();  // 0x4d1440
    void Reset2();  // 0x4d1610
    void Reset3();  // 0x4d1960
    bool Check();   // 0x42cde0
};
class LoadRef
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
    virtual const char* GetName();
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
    virtual void v115(int a, int b);
    virtual int v116();
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
    virtual bool v134();
    unsigned int GetFormID();        // 0x84e3a0
    void Fn8b6820();                 // 0x8b6820
    void Fn8b6ae0();                 // 0x8b6ae0
    RefSub* GetSub();                // 0x5d43c0
    void Fn8adc50();                 // 0x8adc50
    class DelObj* GetObj();          // 0x4181e0
    void SetObj(class DelObj* obj);  // 0x575690
};
class ObjData30
{
  public:
    void Set(int v);  // 0x47e340
};
class DelObj
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~DelObj();
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
    virtual void LoadGame(LoadBuffer* buf);
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
    ObjData30 kData30;
    unsigned int GetFormID();  // 0x84e3a0
};
class DelObj20C : public DelObj
{
  public:
    DelObj20C();
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
};
class DelObj160 : public DelObj
{
  public:
    DelObj160();
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
};
class LoadObj70
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void LoadGame(LoadBuffer* buf);
};
class LoadForm
{
  public:
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
    virtual void LoadGame(LoadBuffer* buf);
    unsigned int GetFormID();  // 0x84e3a0
};
class ScriptEventList
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ScriptEventList();               // 0x5a8b80
    ~ScriptEventList();              // 0x5a8bc0
    void LoadGame(LoadBuffer* buf);  // 0x5a9f20
};
class FormList
{
  public:
    void AddHead(void* const& item);  // 0x5ae3d0
    void AddHead(struct XPackEntry* const& item);
    void AddHead(struct XTopicEntry* const& item);
    void AddHead(struct XEntry24* const& item);
    void** GetItem();              // 0x6815c0
    bool IsEmpty();                // 0x8256d0
    void RemoveNext(void** item);  // 0x905330
    FormList* GetNext();           // 0x726070
    void RemoveHead();             // 0x63f7b0
};
class FormArray
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void Resize(unsigned int count, int flag);   // 0x6f2290
    void Resize2(unsigned int count, int flag);  // 0x42f5f0
    void** GetAt(unsigned int i);                // 0x6a7ad0
    unsigned int GetCount();                     // 0x44ddc0
    void RemoveAt(unsigned int i, int n);        // 0x9a4320
};
class AnimItem
{
  public:
    void LoadGame(LoadBuffer* buf);  // 0x9a5ff0
};
class IdList
{
  public:
    void Add(void* item);  // 0x42f780
    int Count();           // 0x559450
};
class ExtraData110 : public BSExtraData
{
  public:
    unsigned char GetType();  // 0x4f1540
    ExtraData110* GetNext();  // 0x44ddc0
};
class XSub2C
{
  public:
    void Set(unsigned char b);  // 0x42e680
};
class XObj20
{
  public:
    XObj20();  // 0x43a160
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    void LoadGame(LoadBuffer* buf);  // 0x43aaa0
};
class XScriptState
{
  public:
    void LoadGame(LoadBuffer* buf);  // 0x83fbe0
};
struct XKeyData
{
    unsigned char b00;
    TESForm* pKey;
    unsigned char b08;
    unsigned int u0C;
    unsigned int u10;
};
struct XPackEntry
{
    void* pForm;
    unsigned char b04;
};
struct XTopicEntry
{
    TESForm* pInfo;
    unsigned int u04;
    unsigned int u08;
    XTopicEntry();  // 0x42cc10
};
struct XListEntry
{
    unsigned char b00;
    unsigned char b01;
    unsigned char b02;
    unsigned char b03;
    FormArray kItems;
    XListEntry();  // 0x42c470
};
struct XEntry24
{
    unsigned int f00[3];
    unsigned int u0C;
    unsigned int f10[3];
    unsigned int u1C;
    unsigned char b20;
    XEntry24();  // 0x437c10
};
class CrimeList
{
  public:
    void* Find(int type, int id);  // 0x9724e0
};
class DataHandler
{
  public:
    void SetMapping(int id, unsigned int formID);  // 0x84aa30
    bool IsBusy();                                 // 0x42ce10
};
class ProcMgr
{
  public:
    bool Check(unsigned int formID);  // 0x469860
};
extern unsigned int DAT_01183d30[];
extern DataHandler* DAT_011ddf38;
extern ProcMgr* DAT_011c3f2c;
extern CrimeList DAT_011e0e80;
TESForm* __cdecl LookupFormByID(unsigned int id);                 // 0x4839c0
void __cdecl LogMessage(const char* fmt, ...);                    // 0x845cc0
void* __cdecl FindVoiceEntry(LoadRef* ref, float f);              // 0x477bc0
void __cdecl ApplyVoiceEntry(LoadRef* ref, void* entry);          // 0x477ce0
TESForm* __cdecl CreateFormForSlot(TESForm* form, int value);     // 0x4759a0
void* __cdecl GetScriptOwner();                                   // 0x42ce00
LoadForm* __cdecl CreateFormForType(int type);                    // 0x670b90
MagicItem* __cdecl GetMagicItem(void* form);                      // 0x40a250
void* __cdecl LookupIdItem(int id);                               // 0x66e330
LoadObj70* __cdecl CreateObj70(int c);                            // 0x8c6ca0
void __cdecl LoadExtra33(LoadBuffer* buf, void* dst);             // 0x806a90
DelObj* __cdecl CreateBaseObj(TESActorBase* a, TESActorBase* b);  // 0x47d130
RefProc* __cdecl GetRefProc(LoadRef* ref);                        // 0x4bf220
class X24 : public ExtraData110
{
  public:
    X24();
    unsigned short u0C;
};
class X25 : public ExtraData110
{
  public:
    X25();
    unsigned int u0C;
};
class X8D : public ExtraData110
{
  public:
    X8D();
    unsigned char b0C;
};
class X30 : public ExtraData110
{
  public:
    X30();
    unsigned int u0C;
};
class X21 : public ExtraData110
{
  public:
    X21();
    TESForm* pForm;
};
class X23 : public ExtraData110
{
  public:
    X23();
    unsigned int u0C;
};
class X22 : public ExtraData110
{
  public:
    X22();
    TESForm* pForm;
};
class X1C : public ExtraData110
{
  public:
    X1C();
    unsigned int u0C;
};
class X49 : public ExtraData110
{
  public:
    X49();
    TESForm* pForm;
};
class X56 : public ExtraData110
{
  public:
    X56();
    float f0C;
};
class X0D : public ExtraData110
{
  public:
    X0D();
    Script* pScript;
    ScriptEventList* pEventList;
};
class X5B : public ExtraData110
{
  public:
    X5B();
    TESForm* pItem;
    TESForm* pForm;
};
class X19 : public ExtraData110
{
  public:
    X19();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
};
class X18 : public ExtraData110
{
  public:
    X18();
    TESForm* pForm;
    float pos[3];
    unsigned int u1C;
};
class X1B : public ExtraData110
{
  public:
    X1B();
    FormList* pList;
};
class X1D : public ExtraData110
{
  public:
    X1D();
    FormList* pList;
};
class X6C : public ExtraData110
{
  public:
    X6C();
    unsigned int u0C;
};
class X73 : public ExtraData110
{
  public:
    X73();
    FormList* pList;
};
class X75 : public ExtraData110
{
  public:
    X75();
    TESForm* pInfo;
    TESForm* pTopic;
    unsigned int u14;
    unsigned char b18;
};
class X4A : public ExtraData110
{
  public:
    X4A();
    unsigned char b0C;
};
class X35 : public ExtraData110
{
  public:
    X35();
    FormList* pList;
};
class X45 : public ExtraData110
{
  public:
    X45();
    FormArray kArray;
};
class X5E : public ExtraData110
{
  public:
    X5E();
    FormList* pList;
};
class X70 : public ExtraData110
{
  public:
    X70();
    LoadObj70* pObj;
};
class X2C : public ExtraData110
{
  public:
    XSub2C* pSub;
};
class X7C : public ExtraData110
{
  public:
    X7C();
    FormArray kArray;
};
class X74 : public ExtraData110
{
  public:
    X74();
    TESForm* m_pEncounterZone;
};
class X5C : public ExtraData110
{
  public:
    X5C();
    unsigned int u0C;
};
class X5D : public ExtraData110
{
  public:
    X5D();
    unsigned int u0C;
};
class X6E : public ExtraData110
{
  public:
    X6E();
    TESForm* pAmmo;
    unsigned int u10;
};
class X1E : public ExtraData110
{
  public:
    X1E();
    unsigned int u0C;
};
class X1A : public ExtraData110
{
  public:
    X1A();
    LoadForm* pForm;
};
class X26 : public ExtraData110
{
  public:
    X26();
    unsigned char b0C;
};
class X27 : public ExtraData110
{
  public:
    X27();
    unsigned int u0C;
};
class X28 : public ExtraData110
{
  public:
    X28();
    unsigned int u0C;
};
class X2A : public ExtraData110
{
  public:
    X2A();
    XKeyData* pData;
};
class X2F : public ExtraData110
{
  public:
    X2F();
    unsigned int u0C;
    unsigned char b10;
};
class X32 : public ExtraData110
{
  public:
    X32();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1C;
    unsigned int u20;
};
class X33 : public ExtraData110
{
  public:
    X33();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1C;
    unsigned int u20;
    unsigned int u24;
};
class X39 : public ExtraData110
{
  public:
    X39();
    unsigned int u0C;
};
class X3F : public ExtraData110
{
  public:
    X3F();
    void* pItem;
};
class X46 : public ExtraData110
{
  public:
    X46();
    unsigned int u0C;
};
class X4D : public ExtraData110
{
  public:
    X4D();
    XScriptState* pState;
};
class X4E : public ExtraData110
{
  public:
    X4E();
    unsigned char b0C;
};
class X5F : public ExtraData110
{
  public:
    X5F();
    unsigned short u0C;
    unsigned short pad0E;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned char b1C;
    FormArray kArray;
    bool Merge(X5F* other);  // 0x430660
};
class X55 : public ExtraData110
{
  public:
    X55();
    unsigned int u0C;
};
class X60 : public ExtraData110
{
  public:
    X60();
    IdList kList;
};
class X2B : public ExtraData110
{
  public:
    X2B();
    XObj20* pObj;
};
class X3C : public ExtraData110
{
  public:
    X3C();
    unsigned int u0C;
};
class X2E : public ExtraData110
{
  public:
    X2E();
    TESActorBase* pBase;
    TESActorBase* pBase2;
};
class X54 : public ExtraData110
{
  public:
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
};
class X50 : public ExtraData110
{
  public:
    X50();
    unsigned char b0C;
    unsigned char b0D;
};
class X89 : public ExtraData110
{
  public:
    X89();
    unsigned int u0C;
};
class X8B : public ExtraData110
{
  public:
    X8B();
    unsigned int u0C;
    unsigned int u10[3];
    unsigned int u1C;
    FormList kList;
    unsigned int u24;
};
class X8F : public ExtraData110
{
  public:
    X8F();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    void SetName(const char* s);  // 0x438260
    void SetText(const char* s);  // 0x438280
};
class X92 : public ExtraData110
{
  public:
    X92();
    unsigned int u0C;
    unsigned int u10;
    void SetFlags(unsigned int v);
};
class ExtraDataLoader : public ExtraDataList
{
  public:
    BSExtraData* GetByType(unsigned char type);    // 0x410220
    ExtraData110* AddData(ExtraData110* data);     // 0x40ff60
    void RemoveByType(unsigned char type);         // 0x410140
    void RemoveData(ExtraData110* data, int del);  // 0x410020
    void ResetA(bool a, bool b);                   // 0x41aa20
    void ResetB(bool a);                           // 0x41ab70
    void ResetC(bool a);                           // 0x41a960
    void ResetD();                                 // 0x422670
    void FUN_00428150(LoadBuffer* buf);
};
// @fnv 0x00428150
void ExtraDataLoader::FUN_00428150(LoadBuffer* buf)
{
    LoadRef* pRef = buf->GetRef();
    LoadRef* actor = buf->GetActor();
    {
        bool abHas[0x93];
        memset(abHas, 0, 0x93);
        ExtraData110* iter6 = (ExtraData110*)pHead;
        while (iter6 != 0)
        {
            unsigned char cIterType = iter6->GetType();
            if (DAT_01183d30[cIterType] != 0 && buf->GetFlags().IsSet(DAT_01183d30[cIterType]))
            {
                abHas[cIterType] = 1;
            }
            iter6 = iter6->GetNext();
        }
        unsigned int ItemUpdateArray = buf->ReadCount();
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            unsigned char cType = 0;
            buf->Read(&cType, 1);
            switch (cType)
            {
            case 0x16:
                ResetA(1, 0);
                break;
            case 0x3e:
                ResetB(1);
                break;
            case 0x24: {
                X24* p24 = (X24*)(abHas[cType] ? GetByType(cType) : AddData(new X24));
                buf->Read(&p24->u0C, 2);
                break;
            }
            case 0x25: {
                X25* p25 = (X25*)(abHas[cType] ? GetByType(cType) : AddData(new X25));
                buf->Read(&p25->u0C, 4);
                break;
            }
            case 0x8d: {
                X8D* p8D = (X8D*)(abHas[cType] ? GetByType(cType) : AddData(new X8D));
                buf->Read(&p8D->b0C, 1);
                break;
            }
            case 0x30: {
                X30* p30 = (X30*)(abHas[cType] ? GetByType(cType) : AddData(new X30));
                buf->Read(&p30->u0C, 4);
                break;
            }
            case 0x21: {
                X21* p21 = (X21*)(abHas[cType] ? GetByType(cType) : AddData(new X21));
                p21->pForm = LookupFormByID(buf->GetRefID());
                break;
            }
            case 0x23: {
                X23* p23 = (X23*)(abHas[cType] ? GetByType(cType) : AddData(new X23));
                buf->Read(&p23->u0C, 4);
                break;
            }
            case 0x22: {
                X22* p22 = (X22*)(abHas[cType] ? GetByType(cType) : AddData(new X22));
                p22->pForm = dynamic_cast<TESGlobal*>(LookupFormByID(buf->GetRefID()));
                break;
            }
            case 0x1c: {
                X1C* p1C = (X1C*)(abHas[cType] ? GetByType(cType) : AddData(new X1C));
                buf->ReadRefID(&p1C->u0C);
                break;
            }
            case 0x49: {
                X49* p49 = (X49*)(abHas[cType] ? GetByType(cType) : AddData(new X49));
                p49->pForm = LookupFormByID(buf->GetRefID());
                break;
            }
            case 0x56: {
                X56* p56 = (X56*)(abHas[cType] ? GetByType(cType) : AddData(new X56));
                buf->Read(&p56->f0C, 4);
                void* value = FindVoiceEntry(pRef, p56->f0C);
                if (value != 0)
                {
                    ApplyVoiceEntry(pRef, value);
                }
                break;
            }
            case 0x0d: {
                X0D* p0D = (X0D*)(abHas[cType] ? GetByType(cType) : AddData(new X0D));
                p0D->pScript = dynamic_cast<Script*>(LookupFormByID(buf->GetRefID()));
                if (p0D->pEventList == 0)
                {
                    p0D->pEventList = p0D->pScript ? p0D->pScript->CreateEventList() : 0;
                }
                if (pRef == 0)
                {
                    buf->SetForm(GetScriptOwner());
                }
                if (p0D->pEventList == 0)
                {
                    ScriptEventList kTemp;
                    kTemp.LoadGame(buf);
                }
                else
                {
                    p0D->pEventList->LoadGame(buf);
                }
                if (pRef == 0)
                {
                    buf->SetForm(0);
                }
                break;
            }
            case 0x5b: {
                X5B* p5B = (X5B*)(abHas[cType] ? GetByType(cType) : AddData(new X5B));
                p5B->pForm = LookupFormByID(buf->GetRefID());
                int iValue = -1;
                buf->Read(&iValue, 4);
                if (p5B->pForm != 0)
                {
                    p5B->pItem = CreateFormForSlot(p5B->pForm, iValue);
                }
                if (p5B->pForm != 0 && p5B->pItem != 0)
                {
                    if (pRef != 0)
                    {
                        pRef->v115(0, 1);
                    }
                }
                else
                {
                    RemoveByType(0x5b);
                }
                break;
            }
            case 0x19: {
                X19* p19 = (X19*)(abHas[cType] ? GetByType(cType) : AddData(new X19));
                buf->ReadRefID(&p19->u0C);
                buf->ReadRefID(&p19->u14);
                buf->Read(&p19->u10, 4);
                buf->Read(&p19->b18, 1);
                buf->Read(&p19->b19, 1);
                buf->Read(&p19->b1A, 1);
                break;
            }
            case 0x18: {
                X18* p18 = (X18*)(abHas[cType] ? GetByType(cType) : AddData(new X18));
                p18->pForm = LookupFormByID(buf->GetRefID());
                buf->Read(p18->pos, 0xc);
                buf->Read(&p18->u1C, 4);
                break;
            }
            case 0x1b: {
                X1B* extra_ = (X1B*)(abHas[cType] ? GetByType(cType) : AddData(new X1B));
                unsigned int uiPkgCount = buf->ReadCount();
                for (unsigned int j = 0; j < uiPkgCount; j++)
                {
                    XPackEntry* pEntry = new XPackEntry;
                    pEntry->pForm = dynamic_cast<TESPackage*>(LookupFormByID(buf->GetRefID()));
                    buf->Read(&pEntry->b04, 1);
                    extra_->pList->AddHead(pEntry);
                }
                break;
            }
            case 0x1d: {
                X1D* p1D = (X1D*)(abHas[cType] ? GetByType(cType) : AddData(new X1D));
                unsigned int uiIdCount = buf->ReadCount();
                for (unsigned int j = 0; j < uiIdCount; j++)
                {
                    void* pId = 0;
                    buf->ReadRefID(&pId);
                    p1D->pList->AddHead(pId);
                }
                break;
            }
            case 0x6c: {
                X6C* p6C = (X6C*)(abHas[cType] ? GetByType(cType) : AddData(new X6C));
                buf->ReadRefID(&p6C->u0C);
                break;
            }
            case 0x73: {
                X73* extra_ = (X73*)(abHas[cType] ? GetByType(cType) : AddData(new X73));
                unsigned int uiTopicCount = buf->ReadCount();
                for (unsigned int j = 0; j < uiTopicCount; j++)
                {
                    XTopicEntry* pTopic = new XTopicEntry;
                    pTopic->pInfo = dynamic_cast<TESTopicInfo*>(LookupFormByID(buf->GetRefID()));
                    buf->Read(&pTopic->u04, 4);
                    buf->Read(&pTopic->u08, 4);
                    extra_->pList->AddHead(pTopic);
                }
                break;
            }
            case 0x75: {
                X75* p75 = (X75*)(abHas[cType] ? GetByType(cType) : AddData(new X75));
                p75->pTopic = dynamic_cast<TESTopic*>(LookupFormByID(buf->GetRefID()));
                p75->pInfo = dynamic_cast<TESTopicInfo*>(LookupFormByID(buf->GetRefID()));
                buf->Read(&p75->b18, 1);
                break;
            }
            case 0x4a: {
                X4A* p4A = (X4A*)(abHas[cType] ? GetByType(cType) : AddData(new X4A));
                buf->Read(&p4A->b0C, 1);
                break;
            }
            case 0x35: {
                X35* extra_ = (X35*)(abHas[cType] ? GetByType(cType) : AddData(new X35));
                unsigned int uiCrimeCount = buf->ReadCount();
                for (unsigned int j = 0; j < uiCrimeCount; j++)
                {
                    int iCrimeID = 0;
                    int iCrimeType = -1;
                    buf->Read(&iCrimeID, 4);
                    buf->Read(&iCrimeType, 4);
                    void* pInventoryObject = DAT_011e0e80.Find(iCrimeType, iCrimeID);
                    if (pInventoryObject != 0)
                    {
                        extra_->pList->AddHead(pInventoryObject);
                    }
                    else
                    {
                        LogMessage(
                            "Could not find crime %i with crime type %i in the global crime list for ref %s (%08X)",
                            iCrimeID, iCrimeType, pRef ? pRef->GetName() : "UNKNOWN", pRef ? pRef->GetFormID() : 0);
                    }
                }
                if (*extra_->pList->GetItem() == 0)
                {
                    RemoveByType(0x35);
                }
                break;
            }
            case 0x45: {
                X45* extra_ = (X45*)(abHas[cType] ? GetByType(cType) : AddData(new X45));
                unsigned int uiAnimCount = buf->ReadCount();
                extra_->kArray.Resize2(uiAnimCount, 1);
                for (unsigned int j = 0; j < uiAnimCount; j++)
                {
                    AnimItem* pAnim = (AnimItem*)extra_->kArray.GetAt(j);
                    pAnim->LoadGame(buf);
                }
                if (extra_->kArray.GetCount() == 0)
                {
                    ResetD();
                }
                break;
            }
            case 0x5e: {
                X5E* extra_ = (X5E*)(abHas[cType] ? GetByType(cType) : AddData(new X5E));
                unsigned int uiFactionCount = buf->ReadCount();
                for (unsigned int j = 0; j < uiFactionCount; j++)
                {
                    XPackEntry* pRank = new XPackEntry;
                    pRank->pForm = dynamic_cast<TESFaction*>(LookupFormByID(buf->GetRefID()));
                    buf->Read(&pRank->b04, 1);
                    extra_->pList->AddHead(pRank);
                }
                {
                    FormList* pNode = extra_->pList;
                    FormList* pPrev = 0;
                    while (pNode != 0 && !pNode->IsEmpty())
                    {
                        XPackEntry* data5 = (XPackEntry*)*pNode->GetItem();
                        bool bRemove = false;
                        if (data5 != 0)
                        {
                            if (data5->pForm == 0)
                            {
                                delete data5;
                                bRemove = true;
                            }
                        }
                        else
                        {
                            bRemove = true;
                        }
                        if (bRemove)
                        {
                            if (pPrev != 0)
                            {
                                pPrev->RemoveNext(pNode->GetItem());
                                pNode = pPrev->GetNext();
                            }
                            else
                            {
                                pNode->RemoveHead();
                            }
                        }
                        else
                        {
                            pPrev = pNode;
                            pNode = pNode->GetNext();
                        }
                    }
                }
                break;
            }
            case 0x70: {
                X70* p70 = (X70*)(abHas[cType] ? GetByType(cType) : AddData(new X70));
                char cObj = -1;
                buf->Read(&cObj, 1);
                if (cObj != -1)
                {
                    p70->pObj = CreateObj70(cObj);
                    p70->pObj->LoadGame(buf);
                }
                break;
            }
            case 0x2c: {
                unsigned char cValue = 0;
                buf->Read(&cValue, 1);
                X2C* extra_ = (X2C*)(abHas[cType] ? GetByType(cType) : 0);
                if (extra_ != 0 && extra_->pSub != 0)
                {
                    extra_->pSub->Set(cValue);
                }
                break;
            }
            case 0x90:
            case 0x91:
                break;
            case 0x7c: {
                X7C* extra_ = (X7C*)(abHas[cType] ? GetByType(cType) : AddData(new X7C));
                unsigned int count = buf->ReadCount();
                extra_->kArray.Resize(count, 1);
                for (unsigned int j = 0; j < count; j++)
                {
                    void** ppRef = extra_->kArray.GetAt(j);
                    buf->ReadRefID(ppRef);
                }
                break;
            }
            case 0x74: {
                X74* p74 = (X74*)(abHas[cType] ? GetByType(cType) : AddData(new X74));
                p74->m_pEncounterZone = dynamic_cast<BGSEncounterZone*>(LookupFormByID(buf->GetRefID()));
                break;
            }
            case 0x5c: {
                X5C* p5C = (X5C*)(abHas[cType] ? GetByType(cType) : AddData(new X5C));
                buf->Read(&p5C->u0C, 4);
                break;
            }
            case 0x5d: {
                X5D* p5D = (X5D*)(abHas[cType] ? GetByType(cType) : AddData(new X5D));
                buf->Read(&p5D->u0C, 4);
                break;
            }
            case 0x6e: {
                X6E* p6E = (X6E*)(abHas[cType] ? GetByType(cType) : AddData(new X6E));
                p6E->pAmmo = dynamic_cast<TESAmmo*>(LookupFormByID(buf->GetRefID()));
                buf->Read(&p6E->u10, 4);
                break;
            }
            case 0x1e: {
                X1E* p1E = (X1E*)(abHas[cType] ? GetByType(cType) : AddData(new X1E));
                buf->Read(&p1E->u0C, 4);
                break;
            }
            case 0x1a: {
                X1A* p1A = (X1A*)(abHas[cType] ? GetByType(cType) : AddData(new X1A));
                int iMapID = 0;
                buf->ReadRefID(&iMapID);
                if (iMapID != 0)
                {
                    p1A->pForm = CreateFormForType(0x17);
                    DAT_011ddf38->SetMapping(iMapID, p1A->pForm->GetFormID());
                    p1A->pForm->LoadGame(buf);
                }
                break;
            }
            case 0x1f:
                ResetC(1);
                break;
            case 0x26: {
                X26* p26 = (X26*)(abHas[cType] ? GetByType(cType) : AddData(new X26));
                buf->Read(&p26->b0C, 1);
                break;
            }
            case 0x27: {
                X27* p27 = (X27*)(abHas[cType] ? GetByType(cType) : AddData(new X27));
                buf->Read(&p27->u0C, 4);
                break;
            }
            case 0x28: {
                X28* p28 = (X28*)(abHas[cType] ? GetByType(cType) : AddData(new X28));
                buf->Read(&p28->u0C, 4);
                break;
            }
            case 0x2a: {
                X2A* p2A = (X2A*)(abHas[cType] ? GetByType(cType) : AddData(new X2A));
                buf->Read(&p2A->pData->b00, 1);
                buf->Read(&p2A->pData->b08, 1);
                p2A->pData->pKey = dynamic_cast<TESKey*>(LookupFormByID(buf->GetRefID()));
                if (buf->GetVersion() >= 0x10)
                {
                    buf->Read(&p2A->pData->u0C, 4);
                    buf->Read(&p2A->pData->u10, 4);
                }
                break;
            }
            case 0x2f: {
                X2F* p2F = (X2F*)(abHas[cType] ? GetByType(cType) : AddData(new X2F));
                buf->Read(&p2F->u0C, 4);
                buf->Read(&p2F->b10, 1);
                break;
            }
            case 0x32: {
                X32* p32 = (X32*)(abHas[cType] ? GetByType(cType) : AddData(new X32));
                buf->ReadRefID(&p32->u18);
                buf->ReadRefID(&p32->u1C);
                buf->ReadRefID(&p32->u20);
                break;
            }
            case 0x33: {
                X33* p33 = (X33*)(abHas[cType] ? GetByType(cType) : AddData(new X33));
                buf->ReadRefID(&p33->u1C);
                LoadExtra33(buf, &p33->u20);
                break;
            }
            case 0x39: {
                X39* p39 = (X39*)(abHas[cType] ? GetByType(cType) : AddData(new X39));
                buf->ReadRefID(&p39->u0C);
                break;
            }
            case 0x3f: {
                X3F* p3F = (X3F*)(abHas[cType] ? GetByType(cType) : AddData(new X3F));
                buf->ReadRefID(&p3F->pItem);
                p3F->pItem = dynamic_cast<AlchemyItem*>(GetMagicItem(p3F->pItem));
                break;
            }
            case 0x46: {
                X46* p46 = (X46*)(abHas[cType] ? GetByType(cType) : AddData(new X46));
                buf->ReadRefID(&p46->u0C);
                break;
            }
            case 0x4d: {
                X4D* p4D = (X4D*)(abHas[cType] ? GetByType(cType) : AddData(new X4D));
                p4D->pState->LoadGame(buf);
                break;
            }
            case 0x4e: {
                X4E* p4E = (X4E*)(abHas[cType] ? GetByType(cType) : AddData(new X4E));
                buf->Read(&p4E->b0C, 1);
                break;
            }
            case 0x5f: {
                X5F* pOld5F = (X5F*)(abHas[cType] ? GetByType(cType) : 0);
                if (pOld5F != 0)
                {
                    RemoveData(pOld5F, 0);
                }
                else if (buf->GetFlags2().IsSet(0x20000))
                {
                    if (actor->v116())
                    {
                        actor->Fn8b6820();
                    }
                }
                X5F* extra_ = new X5F;
                buf->Read(&extra_->u0C, 2);
                buf->Read(&extra_->u10, 4);
                buf->Read(&extra_->u18, 4);
                buf->Read(&extra_->b1C, 1);
                buf->ReadRefID(&extra_->u14);
                unsigned int count_ = buf->ReadCount();
                extra_->kArray.Resize(count_, 1);
                for (unsigned int j = 0; j < count_; j++)
                {
                    XListEntry** ppList = (XListEntry**)extra_->kArray.GetAt(j);
                    *ppList = new XListEntry;
                    buf->Read(&(*ppList)->b00, 1);
                    buf->Read(&(*ppList)->b01, 1);
                    buf->Read(&(*ppList)->b02, 1);
                    if (buf->GetVersion() >= 0x10)
                    {
                        buf->Read(&(*ppList)->b03, 1);
                    }
                    unsigned int uCount = buf->ReadCount();
                    (*ppList)->kItems.Resize(uCount, 1);
                    for (unsigned int k = 0; k < uCount; k++)
                    {
                        void** ppItem = (*ppList)->kItems.GetAt(k);
                        buf->ReadRefID(ppItem);
                    }
                    {
                        unsigned int uiValid = (*ppList)->kItems.GetCount();
                        for (unsigned int m = 0; m < uiValid; m++)
                        {
                            bool bBad = false;
                            TESForm** ppForm = (TESForm**)(*ppList)->kItems.GetAt(m);
                            *ppForm =
                                *ppForm ? dynamic_cast<TESBoundObject*>(LookupFormByID((unsigned int)*ppForm)) : 0;
                            if (*ppForm == 0)
                            {
                                bBad = true;
                            }
                            if (bBad)
                            {
                                (*ppList)->kItems.RemoveAt(m, 1);
                                m--;
                                uiValid--;
                            }
                        }
                    }
                }
                bool bAny = false;
                if (pOld5F != 0)
                {
                    if (pOld5F->Merge(extra_))
                    {
                        bAny = true;
                    }
                    else
                    {
                        actor->Fn8b6820();
                    }
                    delete pOld5F;
                }
                AddData(extra_);
                if (!bAny)
                {
                    actor->Fn8b6ae0();
                }
                break;
            }
            case 0x55: {
                X55* p55 = (X55*)(abHas[cType] ? GetByType(cType) : AddData(new X55));
                buf->ReadRefID(&p55->u0C);
                break;
            }
            case 0x60: {
                X60* extra8 = (X60*)(abHas[cType] ? GetByType(cType) : AddData(new X60));
                int iItemID = -1;
                buf->Read(&iItemID, 4);
                extra8->kList.Add(LookupIdItem(iItemID));
                if (!extra8->kList.Count())
                {
                    RemoveByType(0x60);
                }
                break;
            }
            case 0x2b: {
                X2B* p2B = (X2B*)(abHas[cType] ? GetByType(cType) : AddData(new X2B));
                if (p2B->pObj == 0)
                {
                    p2B->pObj = new XObj20;
                }
                p2B->pObj->LoadGame(buf);
                break;
            }
            case 0x3c: {
                X3C* p3C = (X3C*)(abHas[cType] ? GetByType(cType) : AddData(new X3C));
                buf->ReadRefID(&p3C->u0C);
                break;
            }
            case 0x2e: {
                X2E* _extra = (X2E*)(abHas[cType] ? GetByType(cType) : AddData(new X2E));
                TESActorBase* base8 = _extra->pBase;
                TESActorBase* fBase = _extra->pBase2;
                _extra->pBase = dynamic_cast<TESActorBase*>(LookupFormByID(buf->GetRefID()));
                _extra->pBase2 = dynamic_cast<TESActorBase*>(LookupFormByID(buf->GetRefID()));
                int iFlags = 0;
                buf->Read(&iFlags, 4);
                if (actor != 0 && actor->v116() && fBase != 0 && _extra->pBase2 != fBase)
                {
                    actor->v115(0, 0);
                }
                else if (!DAT_011ddf38->IsBusy())
                {
                    actor->v115(0, 0);
                }
                DelObj* kObj = 0;
                bool bActive3 = false;
                bool bFound0 = false;
                if (fBase != _extra->pBase2 && !buf->GetFlags().IsSet(0x8000020))
                {
                    bFound0 = true;
                }
                if (bFound0)
                {
                    actor->GetSub()->Reset();
                    actor->Fn8adc50();
                }
                if (actor != 0 && _extra->pBase != 0 && _extra->pBase2 != 0 && _extra->pBase->kBaseData.IsValid())
                {
                    kObj = CreateBaseObj(_extra->pBase, _extra->pBase2);
                    DelObj* pCur = actor->GetObj();
                    if (DAT_011c3f2c->Check(pCur->GetFormID()))
                    {
                        delete pCur;
                    }
                    actor->SetObj(kObj);
                }
                else if (base8 != 0 && fBase != 0)
                {
                    _extra->pBase = base8;
                    _extra->pBase2 = fBase;
                }
                else
                {
                    RemoveByType(0x2e);
                }
                if (bFound0)
                {
                    RefProc* pProc = GetRefProc(actor);
                    pProc->Reset1();
                    pProc->Reset2();
                    pProc->Reset3();
                    if (pProc->Check())
                    {
                        actor->GetSub()->Reset();
                    }
                }
                if (kObj == 0)
                {
                    kObj = actor->v134() ? (DelObj*)new DelObj20C : (DelObj*)new DelObj160;
                    bActive3 = true;
                }
                LoadFlags saved = buf->GetFlags();
                LoadFlags saved_ = buf->GetFlags2();
                unsigned char _saved = buf->GetFlagByte();
                buf->SetFlags(iFlags);
                buf->SetFlags2(0);
                buf->SetFlagByte(0);
                kObj->LoadGame(buf);
                kObj->kData30.Set(iFlags);
                buf->SetFlags(saved);
                buf->SetFlags2(saved_);
                buf->SetFlagByte(_saved);
                if (bActive3)
                {
                    delete kObj;
                }
                break;
            }
            case 0x54: {
                X54* p54 = (X54*)(abHas[cType] ? GetByType(cType) : 0);
                if (p54 != 0)
                {
                    buf->Read(&p54->u14, 4);
                }
                else
                {
                    int iDummy;
                    buf->Read(&iDummy, 4);
                }
                break;
            }
            case 0x50: {
                X50* p50 = (X50*)(abHas[cType] ? GetByType(cType) : AddData(new X50));
                buf->Read(&p50->b0C, 1);
                buf->Read(&p50->b0D, 1);
                break;
            }
            case 0x89: {
                X89* p89 = (X89*)(abHas[cType] ? GetByType(cType) : AddData(new X89));
                buf->ReadRefID(&p89->u0C);
                break;
            }
            case 0x8b: {
                X8B* p8B = (X8B*)(abHas[cType] ? GetByType(cType) : AddData(new X8B));
                buf->Read(p8B->u10, 0xc);
                if (buf->GetVersion() >= 0x12)
                {
                    buf->ReadRefID(&p8B->u1C);
                }
                else
                {
                    buf->Read(&p8B->u1C, 4);
                }
                buf->Read(&p8B->u0C, 4);
                unsigned int uiEntryCount = buf->ReadCount();
                for (unsigned int j = 0; j < uiEntryCount; j++)
                {
                    XEntry24* pE = new XEntry24;
                    buf->Read(pE, 0xc);
                    if (buf->GetVersion() >= 0x12)
                    {
                        buf->ReadRefID(&pE->u0C);
                    }
                    else
                    {
                        buf->Read(&pE->u0C, 4);
                    }
                    buf->Read(pE->f10, 0xc);
                    if (buf->GetVersion() >= 0x12)
                    {
                        buf->ReadRefID(&pE->u1C);
                    }
                    else
                    {
                        buf->Read(&pE->u1C, 4);
                    }
                    buf->Read(&pE->b20, 1);
                    p8B->kList.AddHead(pE);
                }
                break;
            }
            case 0x8f: {
                X8F* p8F = (X8F*)(abHas[cType] ? GetByType(cType) : AddData(new X8F));
                char acName[0x100];
                buf->ReadString(acName);
                p8F->SetName(acName);
                buf->ReadString(acName);
                p8F->SetText(acName);
                break;
            }
            case 0x92: {
                X92* p92 = (X92*)(abHas[cType] ? GetByType(cType) : AddData(new X92));
                unsigned int uiRender;
                buf->Read(&uiRender, 4);
                buf->Read(&p92->u10, 4);
                p92->SetFlags(uiRender);
                break;
            }
            default:
                LogMessage("Unknown extra data type %i found in ExtraDataList::LoadGame", cType);
                break;
            }
            abHas[cType] = 0;
        }
        for (unsigned int uiType = 0; uiType < 0x93; uiType++)
        {
            bool bRemove = abHas[uiType];
            if (bRemove)
            {
                switch (uiType)
                {
                case 0x2e:
                    bRemove = false;
                    break;
                case 0x92: {
                    ExtraSpecialRenderFlags* pFlags = dynamic_cast<ExtraSpecialRenderFlags*>(GetByType(0x92));
                    if (pFlags != 0)
                    {
                        pFlags->SetFlags(pFlags->GetFlags() & 7);
                    }
                    bRemove = false;
                    break;
                }
                }
            }
            if (bRemove)
            {
                RemoveByType((unsigned char)uiType);
            }
        }
    }
}
