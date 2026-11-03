
// effectitemlist_ctxr_variant.cpp: rename variant for 0x00405760 (integration 2026-10-30): the unit's skeleton with Str renamed, whose names are bound elsewhere.
#include "effectitemlist.h"
ActorPathHandler::PATH_HANDLER_RESULT CallNoPathUpdate(ActorPathHandler* pHandler, float fSeconds)
{
    return pHandler->CompleteNoPathUpdate(fSeconds);
}

extern "C" char DAT_011837c4, DAT_01183028, DAT_010120d8, DAT_010125c0, DAT_01012578, DAT_01012520, DAT_011c33d4;
struct File
{
    int FUN_004726b0();
    void ReadChunkInt(unsigned*);
    void FUN_004726f0();
};
struct Str_r00405760
{
    char data[8];
    ~Str_r00405760();
    const char* FUN_00559450();
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class EffectSetting : public TESForm
{
  public:
    bool HasFlag2();
    int FUN_00586150();
    Str_r00405760 AssignFromSub();
};
struct Item
{
    char data[36];
    Item(EffectSetting*);
    ~Item();
    bool FUN_00404120(File*, const char*);
    bool FUN_00404710();
};
void* __cdecl operator new(unsigned);
void __cdecl operator delete(void*);
void __cdecl ResolveFormID(unsigned*, File*);
TESForm* __cdecl LookupFormByID(unsigned);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
void __cdecl FUN_005b5e40(const char*, ...);
struct List
{
    int pad[3];
    int count;
    void FUN_00405d20(Item*);
    void FUN_00405760(File*, const char*);
};
// @fnv 0x00405760
void List::FUN_00405760(File* file, const char* name)
{
    unsigned id;
    EffectSetting* effect;
    Item* actorValue;
    int item;
    switch (file->FUN_004726b0())
    {
    case 0x44494645:
        file->ReadChunkInt(&id);
        ResolveFormID(&id, file);
        effect = dynamic_cast<EffectSetting*>(LookupFormByID(id));
        if (effect)
        {
            actorValue = new Item(effect);
            file->FUN_004726f0();
            if (effect->HasFlag2() && effect->FUN_00586150() == 0x36)
                item = 0;
            if (actorValue->FUN_00404120(file, name))
                FUN_00405d20(actorValue);
            else
            {
                FUN_005b5e40(&DAT_010125c0, effect->AssignFromSub().FUN_00559450(), name == 0 ? &DAT_010120d8 : name);
                delete actorValue;
                actorValue = 0;
            }
            *(Item**)&DAT_011c33d4 = actorValue;
        }
        else
            FUN_005b5e40(&DAT_01012578, id, name == 0 ? &DAT_010120d8 : name);
        break;
    case 0x41445443:
        if (*(Item**)&DAT_011c33d4)
        {
            (*(Item**)&DAT_011c33d4)->FUN_00404120(file, name);
            if ((*(Item**)&DAT_011c33d4)->FUN_00404710())
                count++;
        }
        else
            FUN_005b5e40(&DAT_01012520, name == 0 ? &DAT_010120d8 : name);
        break;
    }
}
