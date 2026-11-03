// fallout/interface/menus/surgerymenu.cpp: SurgeryMenu, AnimOwner, MenuX, PainMenu and more (31 functions)

#include "surgerymenu_decls.h"
// @fnv 0x007e5890
void SurgeryMenu::UpdatePerkEntries()
{
    if (DAT_011dada4)
    {
        BSSimpleList<BGSPerkEntry*>* limb = (BSSimpleList<BGSPerkEntry*>*)&g_011dae48;
        while (limb && !((BSSimpleList<const char*>*)limb)->IsEmpty())
        {
            ((PerkEntryHandler*)limb->GetItem())->RefreshPerkState();
            limb = limb->GetNext();
        }
    }
}

struct FUN_007e4fc0_shell
{
    int FUN_007e4fc0(int arg);
};

// @fnv 0x007e4fc0
int __thiscall FUN_007e4fc0_shell::FUN_007e4fc0(int aiIndex)
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) + aiIndex * 0x14;
}

struct S
{
    virtual void a()
    {}
    virtual void b()
    {}
    virtual void c()
    {}
    virtual void d(int, int)
    {}
    bool HandleKey(int);
};
// Handles key codes 0x57/0x77 and 0x53/0x73 by calling d with 6 or 5 and returning true, otherwise returns false.
// @fnv 0x007e4260
bool S::HandleKey(int aiKey)
{
    if (aiKey == 0x57 || aiKey == 0x77)
    {
        this->d(6, 0);
        return true;
        goto L_retfalse;
    }
    if (aiKey == 0x53 || aiKey == 0x73)
    {
        d(5, 0);
        return true;
    }
L_retfalse:
    return false;
}

struct FUN_007e5540_shell
{
    int GetTierFromPercent(int);
};
// Maps a percentage to a tier: 0 for 100+, 1 for 75+, 2 for 50+, 3 for 25+, otherwise 4.
// @fnv 0x007e5540
int FUN_007e5540_shell::GetTierFromPercent(int aiPercent)
{
    if (aiPercent >= 100)
        return 0;
    else if (aiPercent >= 75)
        return 1;
    else if (aiPercent >= 50)
        return 2;
    else if (aiPercent >= 25)
        return 3;
    else
        return 4;
}

struct WoundFake
{
    int _00;
    int _04;
};
struct MenuFake
{
    char _pad[192];
    int _C0;
};
struct FakeList
{
    bool _ref_008256d0();
    WoundFake** _ref_006815c0();
    FakeList* _ref_00726070();
};
struct FUN_007e5720_struct
{
    WoundFake* FUN_007e5720();
};
// Walks the limb wound list and returns the first wound whose _04 matches the menu's _C0, or null if none is found.
// @fnv 0x007e5720
WoundFake* FUN_007e5720_struct::FUN_007e5720()
{
    FakeList* pWoundList = (FakeList*)&g_011dae48;
    while (pWoundList != 0 && !pWoundList->_ref_008256d0())
    {
        if ((*pWoundList->_ref_006815c0())->_04 == ((MenuFake*)DAT_011dada4)->_C0)
            return *pWoundList->_ref_006815c0();
        pWoundList = pWoundList->_ref_00726070();
    }
    return 0;
}

// Tests whether point lies inside the polygon by counting edge crossings of a horizontal ray and returns the inside flag.
// @fnv 0x007e5420
int PointInPolygon(double pgon[][2], int numverts, double point[2])
{
    int j, yflag0, yflag1, inside_flag;
    double tx, ty, *vtx0, *vtx1;

    tx = point[0];
    ty = point[1];

    vtx0 = pgon[numverts - 1];
    yflag0 = (vtx0[1] >= ty);
    vtx1 = pgon[0];

    inside_flag = 0;
    for (j = numverts + 1; --j;)
    {
        yflag1 = (vtx1[1] >= ty);
        if (yflag0 != yflag1)
        {
            if (((vtx1[1] - ty) * (vtx0[0] - vtx1[0]) >= (vtx1[0] - tx) * (vtx0[1] - vtx1[1])) == yflag1)
            {
                inside_flag = !inside_flag;
            }
        }
        yflag0 = yflag1;
        vtx0 = vtx1;
        vtx1 += 2;
    }
    return inside_flag;
}

struct GO
{
    operator unsigned int() const;
    void operator=(void*);
};

template <class T> struct NiPointer : public GO
{
    using GO::operator=;
};

struct NiAdditionalGeometryData
{
    static void* __cdecl GetShadowSceneNodeForIndex(int);
};

struct NiAVObject
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58(unsigned int)
    {}

    void RemoveProperty(unsigned int);
    void UpdateSceneObject();
};

struct NiNode : public NiAVObject
{
};

struct FUN_00b5ddb0_self : public NiAVObject
{
    void FUN_00b5d180();
};

struct NiGeometry : public FUN_00b5ddb0_self
{
};

struct FUN_00950c20_self
{
    int FUN_00950c20(int);
};

int __cdecl FUN_005d9660(void);

NiPointer<NiNode> g_011dadb4;
NiPointer<NiNode> g_011dade8;
NiPointer<NiNode> g_011dae5c;
FUN_00950c20_self* _g_thePlayer;

// @fnv 0x007e5170
void FUN_007e5170()
{
    NiGeometry* pSourceGeometry = static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1));
    pSourceGeometry->v58(g_011dade8.operator unsigned int());

    NiGeometry* pScar2 = static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3));
    pScar2->v58(g_011dae5c.operator unsigned int());

    static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->FUN_00b5d180();
    static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))->FUN_00b5d180();

    _g_thePlayer->FUN_00950c20(0);

    reinterpret_cast<NiAVObject*>(g_011dae5c.operator unsigned int())->RemoveProperty(FUN_005d9660());
    reinterpret_cast<NiAVObject*>(g_011dae5c.operator unsigned int())->UpdateSceneObject();

    g_011dadb4.operator=(static_cast<void*>(0));
    g_011dade8.operator=(static_cast<void*>(0));
    g_011dae5c.operator=(static_cast<void*>(0));
}

extern int __cdecl FUN_004dc200();
extern int __cdecl FUN_004dc1f0();
extern void __cdecl FUN_00703080(float, float);

// If DAT_011dada4 is set and its byte at offset 0x90 is zero, calls FUN_00703080 with arg0 and arg1 divided by FUN_004dc1f0() and FUN_004dc200().
// @fnv 0x007e41f0
void __cdecl FUN_007e41f0(int arg0, int arg1)
{
    if (DAT_011dada4 != 0 && *((unsigned char*)DAT_011dada4 + 0x90) == 0)
    {
        FUN_00703080((float)((double)arg0 / (double)FUN_004dc1f0()), (float)((double)arg1 / (double)FUN_004dc200()));
    }
}

struct SurgeryRenderer
{
    void FUN_007148c0(int, int);
};
SurgeryRenderer* __cdecl FUN_0043c4b0();
struct SurgeryContext
{
    void FUN_00c4f270(bool);
    void FUN_004a0fd0(NiNode*);
    void FUN_00c4f2d0();
};
struct SurgeryObject
{
    SurgeryContext* FUN_008d80e0();
};
SurgeryObject* __cdecl FUN_0045c670();
NiNode* __cdecl FUN_00450b80(int);
void __cdecl UpdateCameraFrustum(NiNode*, float);
struct SurgeryInterface
{
    NiNode* FUN_007fd640();
};
SurgeryInterface* __cdecl FUN_004b7210();
struct SurgeryHolder
{
    NiNode* ptr;
    SurgeryHolder(NiNode*);
    ~SurgeryHolder();
    NiNode* FUN_00559450();
    void FUN_0066b0d0(NiNode*);
};
void __cdecl FUN_00b6bee0(NiNode*, NiNode*, SurgeryContext*);
void __cdecl FUN_00b6c0d0(NiNode*, NiNode*, int);
struct SurgeryCull
{
    void FUN_00450f90(bool);
};
// @fnv 0x007e47a0
void __cdecl UpdateSurgeryScene()
{
    if (!(unsigned)g_011dade8 || !(unsigned)g_011dae5c)
        return;
    FUN_0043c4b0()->FUN_007148c0(0, 4);
    SurgeryObject* b = FUN_0045c670();
    SurgeryContext* d = b->FUN_008d80e0();
    d->FUN_00c4f270(true);
    NiNode* c = (NiNode*)(unsigned)g_011dadb4;
    UpdateCameraFrustum(c, 0.15f);
    NiNode* a = FUN_00450b80(1);
    SurgeryHolder e(FUN_004b7210()->FUN_007fd640());
    d->FUN_004a0fd0(e.FUN_00559450());
    FUN_00b6bee0(c, a, d);
    FUN_00b6c0d0(c, e.FUN_00559450(), 0);
    ((SurgeryCull*)(unsigned)g_011dae5c)->FUN_00450f90(false);
    FUN_00b6bee0(c, FUN_00450b80(3), d);
    FUN_00b6c0d0(c, e.FUN_00559450(), 0);
    d->FUN_004a0fd0(0);
    e.FUN_0066b0d0(0);
    d->FUN_00c4f2d0();
}

struct FUN_00470470_Obj
{
    void FUN_00470470();
};

struct Item_006815c0
{
    int unk00;
    FUN_00470470_Obj* pTarget;
};

struct FUN_007e5780_node : FUN_00470470_Obj
{
    bool FUN_008256d0();
    Item_006815c0** FUN_006815c0();
    FUN_007e5780_node* FUN_00726070();
};

struct Player_a4
{
    virtual void v0();
    virtual void v4();
    virtual int v8();
};

struct Player_shell
{
    char pad[0xa4];
    Player_a4 sub;
};

struct Helper_011dada4
{
    int GetTierFromPercent(int arg1, void* arg2);
};

struct FUN_007e5780_shell
{
    FUN_007e5780_node* pNode;
    void* pArg4;
    int res08;
    bool b0C;
    void ProcessNodeChain();
};

// @fnv 0x007e5780
void FUN_007e5780_shell::ProcessNodeChain()
{
    b0C = true;
    FUN_007e5780_node* p = pNode;
    while (p && !p->FUN_008256d0())
    {
        (*p->FUN_006815c0())->pTarget->FUN_00470470();
        p = p->FUN_00726070();
    }
    pNode->FUN_00470470();
    res08 = ((Helper_011dada4*)DAT_011dada4)->GetTierFromPercent(((Player_shell*)_g_thePlayer)->sub.v8(), pArg4);
}

struct NiFixedStringS
{
    NiFixedStringS(const char* s);
    ~NiFixedStringS();
    int str;
};
struct NiUpdateDataS
{
    NiUpdateDataS(float t, bool a, bool b);
    float time;
    bool b1;
    bool b2;
    int flags;
};
struct NiRTTIS
{
    int name;
    int base;
};
struct NiControllerSequenceS
{
    void Update(float t, bool b);
};
struct NiTimeControllerS
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
    virtual void Update(NiUpdateDataS& data);
    NiTimeControllerS* GetNext() const;
};
struct NiControllerManagerS : NiTimeControllerS
{
    NiControllerSequenceS* FindSequenceByName(const NiFixedStringS& name);
};
struct NiNodeS
{
    NiTimeControllerS* GetControllers() const;
    void Update(NiUpdateDataS& data);
};
struct TimeGlobalS
{
    float GetMovementDelta();
};
extern TimeGlobalS g_timeGlobal;
extern NiRTTIS DAT_011f36bc;
void* NiDynamicCastS(const NiRTTIS* rtti, NiTimeControllerS* obj);

struct AnimOwner
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
    int direction;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    NiNodeS* node;
    int unkE4;
    int unkE8;
    float time;
    void UpdateAnimation();
};

// Advances time by the global delta, updates the direction-matched controller sequence, then updates the node with a zero-time update.
// @fnv 0x007e5a90
void AnimOwner::UpdateAnimation()
{
    NiTimeControllerS* ctrl = node->GetControllers();
    if (ctrl)
    {
        NiControllerManagerS* mgr = (NiControllerManagerS*)ctrl;
        NiControllerSequenceS* seq = 0;
        switch (direction)
        {
        case 1:
            seq = mgr->FindSequenceByName(NiFixedStringS("Forward"));
            break;
        case 2:
            seq = mgr->FindSequenceByName(NiFixedStringS("Right"));
            break;
        case 3:
            seq = mgr->FindSequenceByName(NiFixedStringS("Left"));
            break;
        }
        time += g_timeGlobal.GetMovementDelta();
        if (seq)
        {
            seq->Update(time, true);
            for (; ctrl; ctrl = ctrl->GetNext())
            {
                void* match = NiDynamicCastS(&DAT_011f36bc, ctrl);
                if (match)
                {
                    NiUpdateDataS data(time, false, false);
                    ctrl->Update(data);
                    break;
                }
            }
        }
    }
    NiUpdateDataS updateData(0.0f, false, false);
    node->Update(updateData);
}

class Tile
{
  public:
    void SetInt(int trait, int val);
};

int __cdecl FUN_007e1970();
Tile* __cdecl FUN_00a09030(int);

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    bool Play(bool);
    void Copy(const void*);
};

struct BSAudio
{
    static BSAudio* __cdecl GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* name, unsigned int flags);
};

struct SndX
{
    int unk00;
    int unk04;
    int unk08;
    void Stop();
    void Release();
};

struct SurgeryMenuType
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
    int unk90;
    SndX sound94;
    SndX soundA0;
    void FUN_00a1d910();
};

void __cdecl RefreshEntryByID(int);

class InterfaceManager
{
  public:
    Tile* GetParent();
};

// Closes the surgery menu: plays the UISurgeryExit sound, sets tile traits, stops and releases the menu's two sounds, and updates the parent tile.
// @fnv 0x007e1980
void CloseSurgeryMenu()
{
    Tile* pTile = FUN_00a09030(FUN_007e1970());
    if (!pTile)
        return;

    if (DAT_011dada4)
    {
        BSSoundHandleEx sound7;
        sound7.Copy(&BSAudio::GetSingleton()->GetSoundHandleByEditorID("UISurgeryExit", 0x121));
        sound7.Play(false);
        pTile->SetInt(0x1772, 1);
        ((SurgeryMenuType*)DAT_011dada4)->FUN_00a1d910();
        FakeList* iter = (FakeList*)&g_011dae48;
        while (iter && !iter->_ref_008256d0())
        {
            RefreshEntryByID((*iter->_ref_006815c0())->_04);
            iter = iter->_ref_00726070();
        }
        ((InterfaceManager*)FUN_004b7210())->GetParent()->SetInt(0xfa9, 0xff);
    }

    FUN_007e5170();
    ((SurgeryMenuType*)DAT_011dada4)->sound94.Stop();
    ((SurgeryMenuType*)DAT_011dada4)->soundA0.Stop();
    ((SurgeryMenuType*)DAT_011dada4)->sound94.Release();
    ((SurgeryMenuType*)DAT_011dada4)->soundA0.Release();
}

struct UiTile
{
    void SetInt(int, int);
    float Read(int);
    void SetFloat(int, float, bool);
    void SetText(int, const char*, bool);
};
struct InputX
{
    int Key(int, int);
};
struct OsX
{
    InputX* Controls();
};
extern OsX* g_osGlobals;
struct InterfaceX
{
    bool Mode();
    int MouseX();
    int MouseY();
    UiTile* Root();
};
InterfaceX* GetInterfaceX();
bool FUN_004b71d0();
bool IsMenu(int);
int TraitNameToID(const char*);
int Button(int, int);
float ScaleByConstant(float);
float ScaleLimbWoundPercent(float);
struct ClockX
{
    unsigned int Now();
};
extern ClockX clockX;
extern int DAT_011dad9c;
struct SoundX
{
    int id;
    int unk04;
    int unk08;
    bool Playing();
    void Stop();
};
struct ActorValuesX
{
    virtual void v0();
    virtual void v4();
    virtual int Current(int);
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int Maximum(int);
};
struct PlayerX
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
    int unk98;
    int unk9c;
    int unka0;
    ActorValuesX values;
};
extern PlayerX* playerX;
int PrintText(char*, unsigned int, const char*, ...);
struct MenuX
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
    UiTile* tile44;
    UiTile* tile48;
    int unk4c;
    int unk50;
    UiTile* tile54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    float value74;
    float value78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    char unk90;
    bool dragging;
    short unk92;
    SoundX sound94;
    SoundX sounda0;
    float valueac;
    unsigned int lastTime;

    UiTile* GetTile();
    void Prepare();
    void Active(bool);
    void Drag();
    bool Hit();
    void Update();
    void FUN_007e23c0();
};
// Updates the menu's top-menu flag, drag position, decay of valueac over time, sounds, and the value text from the player's actor value 16.
// @fnv 0x007e23c0
void MenuX::FUN_007e23c0()
{
    char text[256];
    if (!IsMenu(0x41e))
    {
        GetTile()->SetInt(TraitNameToID("_IsTopMenu"), 0);
        return;
    }
    else
    {
        GetTile()->SetInt(TraitNameToID("_IsTopMenu"), 1);
    }
    Prepare();
    bool idle3 = false;
    GetInterfaceX();
    if (FUN_004b71d0())
    {
        if (Button(9, 1) == 2)
        {
            value74 = tile44->Read(0xfa1);
            value78 = tile44->Read(0xfa2);
        }
        if (Button(9, 1) == 0)
        {
            Active(true);
            Drag();
        }
        else
            idle3 = true;
    }
    else
    {
        InputX* input = g_osGlobals->Controls();
        if (input->Key(4, 1))
        {
            InterfaceX* manager3 = GetInterfaceX();
            value74 = (float)manager3->MouseX();
            value78 = (float)manager3->MouseY();
        }
        bool hit = Hit();
        if (hit)
            GetInterfaceX()->Root()->SetInt(0xfa9, 0);
        else
            GetInterfaceX()->Root()->SetInt(0xfa9, 255);
        bool held4 = false;
        if ((input->Key(4, 0) && dragging) || (input->Key(4, 1) && hit))
        {
            held4 = true;
            dragging = true;
        }
        else
        {
            held4 = false;
            dragging = false;
        }
        if (held4)
        {
            Active(true);
            Drag();
        }
        else
            idle3 = true;
    }
    if (idle3 == true)
    {
        float rate = ScaleByConstant(1.0f);
        valueac -= ((clockX.Now() - lastTime) / 1000.0) * rate;
        if (ScaleLimbWoundPercent(GetTile()->Read(DAT_011dad9c) / 100.0) * 100.0 > valueac)
            valueac = ScaleLimbWoundPercent(GetTile()->Read(DAT_011dad9c) / 100.0) * 100.0;
        lastTime = clockX.Now();
        unk8c = lastTime;
        Active(false);
        if (sound94.Playing())
            sound94.Stop();
        if (sounda0.Playing())
            sounda0.Stop();
    }
    Update();
    tile54->SetFloat(0x1004, valueac / 100.0, true);
    PrintText(text, 256, "%i/%i", playerX->values.Current(16), playerX->values.Maximum(16));
    tile48->SetText(TraitNameToID("_Value"), text, true);
}

extern const char DAT_0106ed18[];
extern const char DAT_01077674[];
extern const char DAT_010776a8[];
extern const char DAT_010776b8[];
extern const char DAT_01077698[];
struct PainSound
{
    int id;
    int state;
    int flags;
    PainSound();
    ~PainSound();
    void FUN_00418900(const PainSound&);
    bool Play(bool);
};
struct PainAudio
{
    PainSound FUN_00ad7550(const char*, unsigned int);
};
PainAudio* FUN_00453a70();
struct PainTimer
{
    unsigned int FUN_00825c00();
};
extern PainTimer DAT_011f6394;
struct PainValues
{
    virtual void v00();
    virtual void v04();
    virtual int get(int);
};
struct PainPlayer
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void hurt(int, int, int);
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
    int unk98;
    int unk9c;
    int unka0;
    PainValues values;
    void FUN_0088b740(int, float);
};
extern PainPlayer* g_thePlayer;
struct PainTile
{
    void FUN_00a01350(int, const char*, bool);
};
float ScaleByConstant(float);
unsigned int GetRandomNumberInRange(int, int);
float LinearInterpolate(float, float, float, float, float);
int FUN_00406d00(char*, int, const char*, ...);
int TraitNameToID(const char*);
struct PainMenu
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
    PainTile* tile;
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
    float speed;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    float pain;
    unsigned int last;
    unsigned int lastHurt;
    int unkb8;
    int unkbc;
    int valueId;
    float UpdateWoundInteraction();
    int GetLimbPercentage();
    void FUN_007e28b0();
};
// Advances pain over elapsed time, plays threshold sounds, updates the player's value and hurt state, and refreshes the tile text.
// @fnv 0x007e28b0
void PainMenu::FUN_007e28b0()
{
    float result = UpdateWoundInteraction();
    float value = ScaleByConstant(speed);
    float z = pain;
    pain += (DAT_011f6394.FUN_00825c00() - last) / 1000.0 * 30.0;
    if (pain > 100.0)
        pain = 100.0f;
    unsigned int total = GetRandomNumberInRange(0, 5);
    if (total == 1)
    {
        if (z < 60.0 && pain > 60.0)
        {
            PainSound painSound;
            painSound.FUN_00418900(FUN_00453a70()->FUN_00ad7550(DAT_010776b8, 0x121));
            painSound.Play(false);
        }
        else if (z < 85.0 && pain > 85.0)
        {
            PainSound painSound;
            painSound.FUN_00418900(FUN_00453a70()->FUN_00ad7550(DAT_010776a8, 0x121));
            painSound.Play(false);
        }
        else if (z < 100.0 && pain == 100.0)
        {
            PainSound painSound;
            painSound.FUN_00418900(FUN_00453a70()->FUN_00ad7550(DAT_01077698, 0x121));
            painSound.Play(false);
        }
    }
    last = DAT_011f6394.FUN_00825c00();
    g_thePlayer->FUN_0088b740(valueId, float(GetLimbPercentage() - g_thePlayer->values.get(valueId)));
    if (DAT_011f6394.FUN_00825c00() - lastHurt >
        LinearInterpolate(LinearInterpolate(100.0f, 500.0f, 0.0f, 100.0f, float(g_thePlayer->values.get(37))), 1000.0f,
                          100.0f, 0.0f, pain))
    {
        g_thePlayer->hurt(16, -1, 0);
        lastHurt = DAT_011f6394.FUN_00825c00();
    }
    char time[256];
    FUN_00406d00(time, 256, DAT_01077674, g_thePlayer->values.get(37));
    tile->FUN_00a01350(TraitNameToID(DAT_0106ed18), time, true);
}

struct ScreenPoint
{
    float x, y;
    ScreenPoint();
};
struct Position3
{
    float x, y, z;
};
struct UpdateArgs
{
    float time;
    bool a, b;
    int flags;
    UpdateArgs(float, bool, bool);
};
struct WoundAnim
{
    float FUN_00508120();
    float FUN_00508100();
    float FUN_00759450();
    void FUN_00a328b0(float, bool);
};
struct HitRef
{
    void** FUN_006815c0();
    HitRef* FUN_00726070();
};
struct HitValue
{
    void* FUN_0045bb80();
};
struct WoundEntry
{
    WoundAnim* anim;
    HitRef* bHitDetected;
    float radius;
};
struct WoundNode
{
    WoundEntry** FUN_006815c0();
    WoundNode* FUN_00726070();
    bool FUN_008256d0();
    unsigned FUN_005ae380();
    void SortItems(int(__cdecl*)(WoundEntry*, WoundEntry*));
};
struct WoundData
{
    WoundNode* list;
    int index;
};
int __cdecl compareWounds(WoundEntry*, WoundEntry*);
struct Projection
{
    void ProjectToScreen(void*, float*, float*, float);
};
struct ProjectionPtr
{
    Projection* ptr;
    operator Projection*() const;
    Projection* operator->() const;
};

struct ClockValue
{
    unsigned FUN_00825c00();
};

struct AudioHandle
{
    int id, a, b;
    bool FUN_00ad8930();
    bool Play(bool);
    void FUN_00ad88f0();
};
struct SceneNode
{
    void FUN_00a59c60(UpdateArgs&);
    Position3& FUN_0043c490();
    void FUN_004bc1f0(float, float, float);
};
struct ScenePtr
{
    SceneNode* ptr;
    operator SceneNode*() const;
    SceneNode* operator->() const;
};
struct PlayerValues
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerView
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
    int unk98;
    int unk9c;
    int unka0;
    PlayerValues values;
};

float __cdecl FUN_00715d40();
float __cdecl FUN_00715da0();
float __cdecl LinearInterpolate(float, float, float, float, float);
float __cdecl FUN_00408840(float);
float __cdecl ApplyNoise(float);
void __cdecl ComputeInjuryEffectScalars(float*, float*, float*, float, float, int);
extern int g_011dad9c;
struct SurgeryView
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
    ScreenPoint mouse;
    int unk7c, unk80, unk84;
    unsigned hitTime, lastTime;
    int unk90;
    AudioHandle idleSound, activeSound;
    float amount;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    ScenePtr nodes[8];
    int enabled;
    WoundData* Wounds();
    int GetIndex(int);
    void PlaceSurgeryDecal(ScreenPoint, bool);
    struct ValueOwner
    {
        float FUN_00a011b0(int);
    };
    ValueOwner* FUN_00726070();
    float UpdateWoundInteraction();
};

// Projects wound nodes to screen, tests the cursor against them, updates hit/idle sounds and wound radii, and returns 0 when hit or 100 otherwise.
// @fnv 0x007e2de0
float SurgeryView::UpdateWoundInteraction()
{
    WoundData* p = Wounds();
    if (!((ProjectionPtr&)g_011dadb4) || !p)
        return 0.0f;
    p->list->SortItems(compareWounds);
    bool h = false;
    if (p->list->FUN_005ae380() > 1)
    {
        unsigned a = p->list->FUN_005ae380() * 2;
        ScreenPoint s;
        s = mouse;
        s.x /= FUN_00715d40();
        s.y /= FUN_00715da0();
        double f[2];
        WoundNode* i = p->list;
        while (i && !i->FUN_008256d0())
        {
            ScreenPoint q;
            ScreenPoint ba;
            ((Projection*)((ProjectionPtr&)g_011dadb4))
                ->ProjectToScreen(((HitValue*)*(*i->FUN_006815c0())->bHitDetected->FUN_006815c0())->FUN_0045bb80(),
                                  &q.x, &q.y, 0.00001f);
            ((Projection*)((ProjectionPtr&)g_011dadb4))
                ->ProjectToScreen(
                    ((HitValue*)*(*i->FUN_006815c0())->bHitDetected->FUN_00726070()->FUN_006815c0())->FUN_0045bb80(),
                    &ba.x, &ba.y, 0.00001f);
            q.y = 1.0f - q.y;
            ba.y = 1.0f - ba.y;
            double b[24][2];
            b[0][0] = q.x;
            b[0][1] = q.y;
            b[1][0] = ba.x;
            b[1][1] = ba.y;
            f[0] = s.x;
            f[1] = s.y;
            if (i->FUN_00726070())
            {
                ScreenPoint k;
                ScreenPoint l;
                ((Projection*)((ProjectionPtr&)g_011dadb4))
                    ->ProjectToScreen(((HitValue*)*(*i->FUN_00726070()->FUN_006815c0())->bHitDetected->FUN_006815c0())
                                          ->FUN_0045bb80(),
                                      &k.x, &k.y, 0.00001f);
                ((Projection*)((ProjectionPtr&)g_011dadb4))
                    ->ProjectToScreen(
                        ((HitValue*)*(*i->FUN_00726070()->FUN_006815c0())->bHitDetected->FUN_00726070()->FUN_006815c0())
                            ->FUN_0045bb80(),
                        &l.x, &l.y, 0.00001f);
                k.y = 1.0f - k.y;
                l.y = 1.0f - l.y;
                b[2][0] = k.x;
                b[2][1] = k.y;
                b[3][0] = l.x;
                b[3][1] = l.y;
                if (PointInPolygon(b, 4, f))
                    h = true;
            }
            i = i->FUN_00726070();
        }
        if (h && hitTime == 0)
            hitTime = ((ClockValue&)g_timeGlobal).FUN_00825c00();
        if (h)
        {
            if (!activeSound.FUN_00ad8930())
                activeSound.Play(false);
            if (hitTime > 0)
            {
                if (((ClockValue&)g_timeGlobal).FUN_00825c00() - hitTime >
                    (unsigned)LinearInterpolate(500.0f, 0.0f, 0.0f, 100.0f,
                                                (float)((PlayerView*)_g_thePlayer)->values.Get(37)))
                {
                    WoundAnim* cf[2];
                    cf[0] = (*p->list->FUN_006815c0())->anim;
                    cf[1] = (*p->list->FUN_00726070()->FUN_006815c0())->anim;
                    WoundEntry* j[2];
                    j[0] = *p->list->FUN_006815c0();
                    j[1] = *p->list->FUN_00726070()->FUN_006815c0();
                    float eb[2];
                    eb[0] = cf[0]->FUN_00508120();
                    eb[1] = cf[1]->FUN_00508120();
                    if (lastTime == 0)
                        lastTime = ((ClockValue&)g_timeGlobal).FUN_00825c00();
                    else
                    {
                        eb[0] -= FUN_00408840(cf[0]->FUN_00508100() - cf[0]->FUN_00759450()) * 0.014999999664723873 *
                                 ((((ClockValue&)g_timeGlobal).FUN_00825c00() - lastTime) / 33.0);
                        eb[1] -= FUN_00408840(cf[1]->FUN_00508100() - cf[1]->FUN_00759450()) * 0.006000000052154064 *
                                 ((((ClockValue&)g_timeGlobal).FUN_00825c00() - lastTime) / 33.0);
                    }
                    for (int c = 0; c < 2; c++)
                    {
                        cf[c]->FUN_00a328b0(eb[c], true);
                        j[c]->radius = eb[c];
                    }
                    UpdateArgs e(0.0f, true, false);
                    ((SceneNode*)((SurgeryView*)DAT_011dada4)->nodes[GetIndex(p->index)])->FUN_00a59c60(e);
                    if (((SurgeryView*)DAT_011dada4)->enabled && (eb[0] + eb[1]) / 2.0 < 0.10000000149011612)
                        PlaceSurgeryDecal(s, true);
                }
            }
        }
        else
        {
            PlaceSurgeryDecal(s, false);
            if (!idleSound.FUN_00ad8930())
                idleSound.Play(false);
            if (activeSound.FUN_00ad8930())
                activeSound.FUN_00ad88f0();
            hitTime = 0;
        }
    }
    lastTime = ((ClockValue&)g_timeGlobal).FUN_00825c00();
    if (true)
    {
        float l, e, j;
        ComputeInjuryEffectScalars(&l, &e, &j, FUN_00726070()->FUN_00a011b0(g_011dad9c) / 100.0f, amount / 100.0f,
                                   ((PlayerView*)_g_thePlayer)->values.Get(37));
        ScreenPoint c;
        c.x = ApplyNoise((float)(((ClockValue&)g_timeGlobal).FUN_00825c00() * 0.0002500000118743628));
        c.y = ApplyNoise((float)((((ClockValue&)g_timeGlobal).FUN_00825c00() + 12345) * 0.0002500000118743628));
        Position3 k = ((SceneNode*)nodes[GetIndex(p->index)])->FUN_0043c490();
        ((SceneNode*)nodes[GetIndex(p->index)])->FUN_004bc1f0(c.x, c.y, 1.0f);
        UpdateArgs ba(0.0f, false, false);
        ((SceneNode*)nodes[GetIndex(p->index)])->FUN_00a59c60(ba);
    }
    return h ? 0.0f : 100.0f;
}

struct FaceCtrlS
{
    virtual void c00();
    virtual void c01();
    virtual void c02();
    virtual void c03();
    virtual void c04();
    virtual void c05();
    virtual void c06();
    virtual void c07();
    virtual void c08();
    virtual void c09();
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
    virtual void c64();
    virtual void c65();
    virtual void c66();
    virtual void c67();
    virtual void c68();
    virtual void SetValue(int id, float value);
};
struct FaceNodeS
{
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual void n39();
    virtual void n40();
    virtual void n41();
    virtual void n42();
    virtual void n43();
    virtual void n44();
    virtual void n45();
    virtual void n46();
    virtual void n47();
    virtual void n48();
    virtual void n49();
    virtual void n50();
    virtual void n51();
    virtual void n52();
    virtual void n53();
    virtual void n54();
    virtual void n55();
    virtual void n56();
    virtual void n57();
    virtual void n58();
    virtual void n59();
    virtual void n60();
    virtual void n61();
    virtual void n62();
    virtual void n63();
    virtual FaceCtrlS* GetCtrl();
};
struct FaceRootS
{
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void r04();
    virtual void r05();
    virtual void r06();
    virtual void r07();
    virtual void r08();
    virtual void r09();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual FaceNodeS* GetObjectByName(const NiFixedStringS& name);
};
struct TimeStubS
{
    unsigned int GetTicks();
};
float __cdecl LinearInterpolate(float a, float b, float c, float d, float e);
struct FaceOwnerS
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    float fAC;
    void UpdateFaceGenNode();
};
// If g_011dae5c is set, sets face controller value 13 from fAC and updates the node with the current time.
// @fnv 0x007e3750
void FaceOwnerS::UpdateFaceGenNode()
{
    if (!g_011dae5c)
        return;
    FaceCtrlS* ctrl =
        ((FaceRootS*)(unsigned int)g_011dae5c)->GetObjectByName(NiFixedStringS("BSFaceGenNiNodeSkinned"))->GetCtrl();
    ctrl->SetValue(13, LinearInterpolate(0.0f, 1.0f, 0.0f, 100.0f, fAC));
    NiUpdateDataS data(((TimeStubS*)&g_timeGlobal)->GetTicks() / 1000.0, true, false);
    ((NiNodeS*)(unsigned int)g_011dae5c)->Update(data);
}

class NiFixedString
{
  public:
    NiFixedString(const char* apString);
    ~NiFixedString();
    const char* m_kHandle;
};

class FUN_006815c0
{
  public:
    float x, y;
    FUN_006815c0();
    FUN_006815c0 Subtract(const FUN_006815c0& arPoint) const;
    float FUN_00589850();
};

struct FUN_007e4540_root
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
    virtual void* v039(const NiFixedString& arName);
};

struct FUN_00a6fc50_cam
{
    void ProjectToScreen(void* apPos, float* apfX, float* apfY, float afZeroTolerance);
};
void* __fastcall FUN_0045bb80(void* apNode);

struct FUN_00747d00_im
{
    int FUN_00747d00();
    int FUN_0073b020();
};

bool FUN_004b71d0();
float __cdecl FUN_00715d40();
float __cdecl FUN_00715da0();
extern const char DAT_01077774[];
extern const char DAT_01077768[];

struct FUN_007e4540_shell
{
    char pad[0xe0];
    FUN_007e4540_root* pRoot;
    bool FUN_007e4540();
};

// @fnv 0x007e4540
bool FUN_007e4540_shell::FUN_007e4540()
{
    FUN_004b7210();
    if (FUN_004b71d0())
        return true;

    void* pNewObj = pRoot->v039(NiFixedString(DAT_01077774));
    void* pEdge8 = pRoot->v039(NiFixedString(DAT_01077768));
    int iX;
    int iY;
    int iRadiusTmp;
    if (pNewObj && pEdge8)
    {
        FUN_006815c0 kIntersectionOffset;
        FUN_006815c0 kTmpEdge;
        ((FUN_00a6fc50_cam*)((SurgeryHolder*)&g_011dadb4)->FUN_00559450())
            ->ProjectToScreen(FUN_0045bb80(pNewObj), &kIntersectionOffset.x, &kIntersectionOffset.y, 1e-5f);
        ((FUN_00a6fc50_cam*)((SurgeryHolder*)&g_011dadb4)->FUN_00559450())
            ->ProjectToScreen(FUN_0045bb80(pEdge8), &kTmpEdge.x, &kTmpEdge.y, 1e-5f);
        kIntersectionOffset.x *= FUN_00715d40();
        kIntersectionOffset.y = (1.0 - kIntersectionOffset.y) * FUN_00715da0();
        kTmpEdge.x *= FUN_00715d40();
        kTmpEdge.y = (1.0 - kTmpEdge.y) * FUN_00715da0();
        iX = kIntersectionOffset.x;
        iY = kIntersectionOffset.y;
        iRadiusTmp = kIntersectionOffset.Subtract(kTmpEdge).FUN_00589850();
    }
    else
    {
        iX = 0x320;
        iY = 0x1db;
        iRadiusTmp = 0x145;
    }

    FUN_00747d00_im* pInterface6 = (FUN_00747d00_im*)FUN_004b7210();
    FUN_006815c0 kDeltaCur;
    kDeltaCur.x = pInterface6->FUN_00747d00() - iX;
    kDeltaCur.y = pInterface6->FUN_0073b020() - iY;
    return kDeltaCur.FUN_00589850() <= iRadiusTmp;
}

struct NiPoint3S;
struct NiPoint2S
{
    float x;
    float y;
    NiPoint2S();
    NiPoint2S operator-(const NiPoint2S& rhs) const;
    float Length();
};
struct MenuHolderS
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
    NiPoint2S cursor;
};
struct RefS
{
    NiPoint3S* GetPos();
};
struct ProjNodeS
{
    RefS* item;
};
struct ProjListS
{
    bool IsEmpty();
    ProjNodeS* Data();
    ProjListS* Next();
};
struct ProjOwnerS
{
    int unk00;
    ProjListS* list;
};
struct CameraS
{
    void WorldToScreen(NiPoint3S* pos, float* x, float* y, float eps);
};
float GetScreenWidthS();
float GetScreenHeightS();

// Projects each item of both lists to screen space and compares their distance to the normalized cursor, returning 1, -1 or 0.
// @fnv 0x007e5250
int __cdecl CompareProjectedListsToCursor(ProjOwnerS* a, ProjOwnerS* pOwnerB)
{
    if (!DAT_011dada4)
        return 0;
    float fBestDist = 3.402823466e+38F;
    NiPoint2S screenPos;
    NiPoint2S cursor = ((MenuHolderS*)DAT_011dada4)->cursor;
    cursor.x = cursor.x / GetScreenWidthS();
    cursor.y = cursor.y / GetScreenHeightS();
    ProjListS* pNode = a->list;
    while (g_011dadb4 && pNode && !pNode->IsEmpty())
    {
        ((CameraS*)(unsigned int)g_011dadb4)
            ->WorldToScreen(pNode->Data()->item->GetPos(), &screenPos.x, &screenPos.y, 1e-5f);
        screenPos.y = 1.0f - screenPos.y;
        if ((screenPos - cursor).Length() < fBestDist)
            fBestDist = (screenPos - cursor).Length();
        pNode = pNode->Next();
    }
    pNode = pOwnerB->list;
    while (g_011dadb4 && pNode && !pNode->IsEmpty())
    {
        ((CameraS*)(unsigned int)g_011dadb4)
            ->WorldToScreen(pNode->Data()->item->GetPos(), &screenPos.x, &screenPos.y, 1e-5f);
        screenPos.y = 1.0f - screenPos.y;
        if ((screenPos - cursor).Length() < fBestDist)
            return 1;
        pNode = pNode->Next();
    }
    return -1;
}

// When the interface is up and menu 0x41e is not open, find the queued entry with this id and refresh it.

class E5810Entry
{
  public:
    int unk00;
    int m_iID;

    void Refresh();
};

class E5810Node
{
  public:
    bool IsEmpty();
    E5810Entry** GetItem();
    E5810Node* GetNext();
};

extern void* g_pE5810Interface;
extern E5810Node g_kE5810Queue;

bool __cdecl E5810IsMenuOpen(int iMenuID);

// If the interface exists and menu 0x41e is closed, walks the queue and calls Refresh on the first entry whose m_iID equals the given ID.
// @fnv 0x007e5810
void RefreshEntryByID(int aiEntryID)
{
    if (g_pE5810Interface && !E5810IsMenuOpen(0x41e))
    {
        E5810Node* pkNode = &g_kE5810Queue;
        while (pkNode && !pkNode->IsEmpty())
        {
            if ((*pkNode->GetItem())->m_iID == aiEntryID)
            {
                (*pkNode->GetItem())->Refresh();
                break;
            }
            pkNode = pkNode->GetNext();
        }
    }
}

struct LimbValueSource
{
    float FUN_00493770();
    float FUN_00508100();
    float FUN_00759450();
};
struct LimbEntry
{
    LimbValueSource* source;
};
struct LimbListNode
{
    bool IsEmpty();
    LimbEntry*& GetItem();
    LimbListNode* GetNext();
};
struct LimbWoundData
{
    LimbListNode* list;
};
struct TileS
{
    void Set(int id, float value, bool propagate);
    void Set(int id, const char* value, bool propagate);
};
namespace ActorValue {
enum Index
{
};
const char* GetActorValueName(Index av);
}
int TraitNameToID(const char* name);
extern const double _gModifierZero;

struct SurgeryLimbMenu
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
    TileS* tile4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    TileS* tile70;
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
    int unkBC;
    ActorValue::Index avC0;

    LimbWoundData* FUN_007e5720();
    float FUN_007e58e0();
};

// Sums limb source values and ranges over the wound list, clamps the total, and returns 1 minus the normalized total; sets tiles when no wound data exists.
// @fnv 0x007e58e0
float SurgeryLimbMenu::FUN_007e58e0()
{
    float total = 0;
    float range8 = 0;
    LimbWoundData* wound_ = FUN_007e5720();
    if (!wound_)
    {
        tile70->Set(TraitNameToID("_Value"), 1.0f, true);
        tile4C->Set(0xfc4, ActorValue::GetActorValueName(avC0), true);
        return 0;
    }
    LimbListNode* node3 = wound_->list;
    while (node3 && !node3->IsEmpty())
    {
        LimbValueSource* src = node3->GetItem()->source;
        total += src->FUN_00493770();
        range8 += src->FUN_00508100() - src->FUN_00759450();
        node3 = node3->GetNext();
    }
    if (total < _gModifierZero)
        total = 0;
    total = total / range8;
    return 1.0 - total;
}

namespace fnv_007e5ee0 {
struct NodeV
{
    virtual void virt00();
    virtual void virt01();
    virtual void virt02();
    virtual void virt03();
    virtual void virt04();
    virtual void virt05();
    virtual void virt06();
    virtual void virt07();
    virtual void virt08();
    virtual void virt09();
    virtual void virt10();
    virtual void virt11();
    virtual void virt12();
    virtual void virt13();
    virtual void virt14();
    virtual void virt15();
    virtual void virt16();
    virtual void virt17();
    virtual void virt18();
    virtual void virt19();
    virtual void virt20();
    virtual void virt21();
    virtual void virt22();
    virtual void virt23();
    virtual void virt24();
    virtual void virt25();
    virtual void virt26();
    virtual void virt27();
    virtual void virt28();
    virtual void virt29();
    virtual void virt30();
    virtual void virt31();
    virtual void virt32();
    virtual void virt33();
    virtual void virt34();
    virtual void virt35();
    virtual void virt36();
    virtual void virt37();
    virtual void virt38();
    virtual void* virt39(void*);
    virtual void virt40();
    virtual void virt41();
    virtual void virt42();
    virtual void virt43();
    virtual void virt44();
    virtual void virt45();
    virtual void virt46();
    virtual void virt47();
    virtual void virt48();
    virtual void virt49();
    virtual void virt50();
    virtual void virt51();
    virtual void virt52();
    virtual void virt53();
    virtual void virt54();
    virtual void virt55(void*, int);
    virtual void virt56();
    virtual void virt57();
    virtual void virt58(void*);
};
struct PtrBox
{
    void* m_ptr;
    NodeV* FUN_00559450();
};
struct DataF
{
    void* m_00[50];
    PtrBox m_aiIndexedValues[8];
    void* m_e8;
};
struct NiFixedString
{
    NiFixedString(const char*);
    ~NiFixedString();
    int m_str;
};
struct HostF
{
    int GetIndex(int);
    void FUN_007e5ee0(int a1, int a2);
};
// @fnv 0x007e5ee0
void __thiscall HostF::FUN_007e5ee0(int a1, int a2)
{
    ((PtrBox*)&g_011dade8)
        ->FUN_00559450()
        ->virt58(((DataF*)DAT_011dada4)->m_aiIndexedValues[GetIndex(a1)].FUN_00559450());
    ((PtrBox*)&g_011dade8)
        ->FUN_00559450()
        ->virt55(((DataF*)DAT_011dada4)->m_aiIndexedValues[GetIndex(a2)].FUN_00559450(), 1);
    ((DataF*)DAT_011dada4)->m_e8 = ((PtrBox*)&g_011dade8)->FUN_00559450()->virt39(&NiFixedString("ScarMesh"));
}
}  // namespace fnv_007e5ee0

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class BGSTextureSet : public TESForm
{
};
extern TESForm* __cdecl FUN_00483a00(const char*);
extern const char DAT_010777e0[], DAT_010777d0[];
extern NiPoint3 DAT_011f426c;
struct SceneObject
{
    NiPoint3& FUN_00413f40();
};
struct PickRecord
{
    SceneObject* FUN_00968670();
};
class NiPick
{
  public:
    unsigned int pickType, sortType, intersectType, coordinateType;
    unsigned char frontOnly, returnNormals, returnTextures, returnColors;
    void* root;
    unsigned int resultVtable, resultData, resultCapacity, resultSize, resultGrow, resultCount;
    unsigned char flags30, flags31, flags32, flags33;
    NiPick(int, int);
    ~NiPick();
    void SetByteAtOffset17(int);
    void FUN_00705fc0(void*);
    bool FUN_00e98e20(NiPoint3*, NiPoint3*, int);
    PickRecord* FUN_00500940(unsigned int);
};
struct RayCamera
{
    void MapScreenToRay(int, int, NiPoint3*, NiPoint3*, int);
};
struct CameraHolder
{
    RayCamera* FUN_00559450();
};
extern CameraHolder DAT_011dadb4;
struct SceneHolder
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    unsigned int unknownb4;
    unsigned int unknownb8;
    unsigned int unknownbc;
    unsigned int unknownc0;
    unsigned int unknownc4;
    unsigned int unknownc8;
    unsigned int unknowncc;
    unsigned int unknownd0;
    unsigned int unknownd4;
    unsigned int unknownd8;
    unsigned int unknowndc;
    unsigned int unknowne0;
    unsigned int unknowne4;
    void* scene;
};
struct DecalCell
{
    void* FUN_008d6f30();
};
extern DecalCell* DAT_011dea3c;
extern float __cdecl FUN_004a4240();
struct FUN_004a37b0
{
    NiPoint3 position, direction, unknown18;
    unsigned int unknown24;
    void* scene;
    unsigned int unknown2c;
    BGSTextureSet* texture;
    unsigned int unknown34;
    float width, height, depth, rotation;
    void* cell;
    unsigned int unknown4c, unknown50, unknown54;
    float angle;
    float unknown5c;
    NiPoint3 axis;
    unsigned int unknown6c;
    unsigned char unknown70, unknown71, unknown72, unknown73, unknown74, unknown75, unknown76, unknown77, unknown78,
        unknown79;
    FUN_004a37b0();
};
typedef struct FUN_004a37b0 DecalInfo;
struct DecalManager
{
    void AddGeometryDecal(DecalInfo*, bool, bool);
};
extern DecalManager* __cdecl FUN_0049fef0();
struct SurgeryDecals
{
    void PlaceSurgeryDecal(float, float, bool);
};
// Raycasts from screen coordinates to find a scene position, then submits a decal with a texture chosen by good at that position.
// @fnv 0x007e5ff0
void SurgeryDecals::PlaceSurgeryDecal(float afScreenX, float afScreenY, bool good)
{
    NiPoint3 origin3, direction;
    float kScreenX = FUN_004dc1f0() * afScreenX;
    float screenY_2 = FUN_004dc200() * afScreenY;
    DAT_011dadb4.FUN_00559450()->MapScreenToRay((int)kScreenX, (int)screenY_2, &origin3, &direction, 0);
    NiPoint3 position = DAT_011f426c;
    NiPick pickVal(0, 8);
    pickVal.SetByteAtOffset17(0);
    pickVal.FUN_00705fc0(((SceneHolder*)DAT_011dada4)->scene);
    if (pickVal.FUN_00e98e20(&origin3, &direction, 0))
    {
        unsigned int indexVal = 0;
        SceneObject* object = pickVal.FUN_00500940(indexVal)->FUN_00968670();
        if (object)
        {
            position = object->FUN_00413f40();
            position.z += 10.0;
        }
    }
    BGSTextureSet* textureVal = 0;
    if (good)
        textureVal = dynamic_cast<BGSTextureSet*>(FUN_00483a00(DAT_010777e0));
    else
        textureVal = dynamic_cast<BGSTextureSet*>(FUN_00483a00(DAT_010777d0));
    DecalInfo infoB;
    infoB.position = position;
    infoB.direction = NiPoint3(0, 0, 1);
    infoB.scene = ((SceneHolder*)DAT_011dada4)->scene;
    infoB.rotation = FUN_004a4240();
    infoB.texture = textureVal;
    infoB.unknown72 = 0;
    infoB.cell = DAT_011dea3c->FUN_008d6f30();
    infoB.width = 0.5f;
    infoB.height = 0.5f;
    infoB.depth = 20.0f;
    infoB.unknown5c = 0;
    infoB.axis = NiPoint3(1, 0, 0);
    infoB.angle = 75.0f;
    infoB.unknown74 = 1;
    infoB.unknown75 = 1;
    infoB.unknown77 = 0;
    FUN_0049fef0()->AddGeometryDecal(&infoB, true, true);
}

struct NiPoint2
{
    float x, y;
    NiPoint2();
    float FUN_00589850() const;
    float NormalizeXY();
    NiPoint2& Scale(float);
    NiPoint2 Subtract(const NiPoint2&) const;
};
struct ScenePoint
{
    float x, y, z;
};
struct CursorNode
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
    virtual CursorNode* Find(const NiFixedString&);
    const ScenePoint& FUN_0045bb80();
};
struct CursorCamera
{
    bool ProjectToScreen(const ScenePoint&, float*, float*, float);
};
CursorCamera* __fastcall FUN_00559450(GO*);
float __cdecl FUN_00715d40();
float __cdecl FUN_00715da0();
struct CursorTile
{
    void FUN_00a012d0(int, float, bool);
};
struct CursorMenu
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
    CursorTile* tile;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    CursorNode* node;
    void UpdateTilePositions(int x, int y);
};
// Finds CenterNode and FrameNode, projects them to screen space, clamps the cursor offset to a radius, and moves tiles 4001 and 4002 to the resulting positions.
// @fnv 0x007e42c0
void CursorMenu::UpdateTilePositions(int x, int y)
{
    CursorNode* radius = node->Find(NiFixedString("CenterNode"));
    CursorNode* center = node->Find(NiFixedString("FrameNode"));
    int edge, offset, originX;
    if (radius && center)
    {
        NiPoint2 centerPos;
        NiPoint2 edgePos;
        FUN_00559450(&g_011dadb4)->ProjectToScreen(radius->FUN_0045bb80(), &centerPos.x, &centerPos.y, 0.00001f);
        FUN_00559450(&g_011dadb4)->ProjectToScreen(center->FUN_0045bb80(), &edgePos.x, &edgePos.y, 0.00001f);
        centerPos.x *= FUN_00715d40();
        centerPos.y = (1.0 - centerPos.y) * FUN_00715da0();
        edgePos.x *= FUN_00715d40();
        edgePos.y = (1.0 - edgePos.y) * FUN_00715da0();
        edge = (int)centerPos.x;
        offset = (int)centerPos.y;
        originX = (int)centerPos.Subtract(edgePos).FUN_00589850();
    }
    else
    {
        edge = 800;
        offset = 475;
        originX = 325;
    }
    NiPoint2 originY;
    originY.x = (float)(x - edge);
    originY.y = (float)(y - offset);
    if (originY.FUN_00589850() > originX)
    {
        originY.NormalizeXY();
        originY.Scale((float)originX);
    }
    tile->FUN_00a012d0(4001, edge + originY.x, true);
    tile->FUN_00a012d0(4002, offset + originY.y, true);
}

struct SeqHolder
{
    float FUN_00508100();
    void FUN_00a328b0(float time, bool recurse);
};

struct WoundUpdater
{
    void UpdateWounds(float delta);
};

// @fnv 0x007e59f0
void WoundUpdater::UpdateWounds(float delta)
{
    WoundFake* pHead = ((FUN_007e5720_struct*)DAT_011dada4)->FUN_007e5720();
    FakeList* node2 = (FakeList*)pHead->_00;
    while (node2 != 0 && !node2->_ref_008256d0())
    {
        ((SeqHolder*)(*node2->_ref_006815c0())->_00)
            ->FUN_00a328b0(((SeqHolder*)(*node2->_ref_006815c0())->_00)->FUN_00508100() * delta, true);
        node2 = node2->_ref_00726070();
    }
    NiUpdateDataS data3(0.0f, true, false);
    ((NiNodeS*)((SurgeryHolder&)g_011dade8).FUN_00559450())->Update(data3);
}

extern NiRTTIS DAT_011f36ac;

class DirectionSequence
{
  public:
    void SetNegatedGlobal();
};

class DirectionManager
{
  public:
    DirectionSequence* FUN_0047a520(const NiFixedString& kName);  // FindSequenceByName
    void FUN_0048fef0(float fTime);                               // deactivate all
    void FUN_0047aab0(DirectionSequence* pkSequence, int iPriority, bool bStartOver, float fWeight, float fEaseInTime,
                      DirectionSequence* pkTimeSync);
    void FUN_0047aa40(bool bValue);
};

class DirectionRoot
{
  public:
    DirectionManager* FUN_00a5c570(const NiRTTIS* pkRTTI);  // GetController
};

struct DirectionSceneOwner
{
    char unk00[0xe0];
    DirectionRoot* m_pkTreeNode;  // +0xe0
};

void FUN_00a6d2d0(DirectionRoot* pkRoot);

class DirectionAnimator
{
  public:
    void SetDirection(int iDirection);

    char unk00[0x28];
    int m_iDirection;  // +0x28
    char unk2c[0xc0];
    float m_fDirectionBlend;  // +0xec
};

// @fnv 0x007e5c80
void DirectionAnimator::SetDirection(int iDirection)
{
    m_iDirection = iDirection;
    m_fDirectionBlend = 0.0f;
    DirectionManager* pkController =
        static_cast<DirectionSceneOwner*>(DAT_011dada4)->m_pkTreeNode->FUN_00a5c570(&DAT_011f36ac);
    if (pkController)
    {
        DirectionManager* pkManager = pkController;
        DirectionSequence* pkSequence2 = 0;
        switch (m_iDirection)
        {
        case 1:
            pkSequence2 = pkManager->FUN_0047a520(NiFixedString("Forward"));
            break;
        case 2:
            pkSequence2 = pkManager->FUN_0047a520(NiFixedString("Right"));
            break;
        case 3:
            pkSequence2 = pkManager->FUN_0047a520(NiFixedString("Left"));
            break;
        }
        if (pkSequence2)
        {
            pkManager->FUN_0048fef0(0.0f);
            pkManager->FUN_0047aab0(pkSequence2, 0, true, 1.0f, 0.0f, 0);
            pkManager->FUN_0047aa40(true);
            pkSequence2->SetNegatedGlobal();
        }
    }
    FUN_00a6d2d0(static_cast<DirectionSceneOwner*>(DAT_011dada4)->m_pkTreeNode);
}

namespace LockpickResistance {

struct PickTile
{
    float FUN_00a011b0(int aiTrait);
    double GetAccumulatedFloat();
    double GetTotalFloat(float afValue);
    void FUN_00700320(int aiTrait, int aiValue);
};

struct PickInterface
{
    static bool FUN_004b71d0();
    int FUN_0073b020();
    int FUN_00747d00();
    void UpdateTilePosition(float afValue);
};

struct PickPoint
{
    float x, y;
    PickPoint();
    PickPoint FUN_004a4f40(float afScale);
    float FUN_00589850();
    void Add(const PickPoint* apOther);
};

struct PickInput
{
    int GetAxisState(int aiDevice, int aiAxis);
    int FUN_00a239e0(int aiAxis);
};

struct PickGlobals
{
    PickInput* FUN_00877720();
};

struct PickSetting
{
    float* FUN_00403e20();
};

struct PickTimer
{
    unsigned int FUN_00825c00();
};

struct PickActorValues
{
    virtual void v00();
    virtual void v01();
    virtual int GetActorValue(int aiIndex);
};

struct PickPlayer
{
    char pad00[0xa4];
    PickActorValues kValues;
};

extern PickGlobals* DAT_011dea0c;
extern PickSetting DAT_011d8c5c;
extern PickTimer DAT_011f6394;
extern PickPlayer* DAT_011dea3c;
extern int DAT_011dad9c;

PickInterface* FUN_004b7210();
int __cdecl TraitNameToIDAdd(const char* apTrait, int aiDefault);
void __cdecl ComputeInjuryEffectScalars(float* apResistance, float* apMagnitude, float* apMouse, float afSkill,
                                        float afLockLevel, int aiPerception);
float __cdecl LinearInterpolate(float afMin, float afMax, float afFrom, float afTo, float afValue);
float __cdecl ApplyNoise(float afValue);
PickPoint __cdecl FUN_00532fd0(float afScale, const PickPoint& arPoint);
float __cdecl GetRatio();
int __cdecl FUN_004dc200();
int __cdecl FUN_004dc1f0();

static const char s_szMinResistanceTime[] = "_MinResistanceTime";
static const char s_szMaxResistanceTime[] = "_MaxResistanceTime";
static const char s_szMinMagnitude[] = "_MinMagnitude";
static const char s_szMaxMagnitude[] = "_MaxMagnitude";
static const char s_szMinXBoxMag[] = "_MinXBoxMag";
static const char s_szMaxXBoxMag[] = "_MaxXBoxMag";
static const char s_szMouseMinPercent[] = "_MouseMinPercent";
static const char s_szMouseMaxPercent[] = "_MouseMaxPercent";

struct PickMenu
{
    char pad00[0x44];
    PickTile* pDial;
    char pad48[0x14];
    PickTile* kArgumentPosition;
    char pad60[0x14];
    PickPoint kCursorPos;
    PickPoint kIntersectionOffset;
    float fResistance;
    char pad88[8];
    bool bForcing;
    char pad91[0x1b];
    float fLockLevel;

    PickTile* FUN_00726070();
    void UpdateTilePositions(int aiX, int aiY);
    void UpdateLockpick(bool abForcing);
};

// Updates lockpick cursor position and resistance based on forcing state, input device, and interpolated magnitude and mouse percent values.
// @fnv 0x007e3890
void PickMenu::UpdateLockpick(bool abForcing)
{
    PickInterface* pInterfaceFinal = FUN_004b7210();
    static int iMinResistanceTime = TraitNameToIDAdd(s_szMinResistanceTime, -1);
    static int iMaxResistanceTime = TraitNameToIDAdd(s_szMaxResistanceTime, -1);
    static int iMinMagnitude = TraitNameToIDAdd(s_szMinMagnitude, -1);
    static int iMaxMagnitude = TraitNameToIDAdd(s_szMaxMagnitude, -1);
    static int iMinXBoxMag = TraitNameToIDAdd(s_szMinXBoxMag, -1);
    static int iMaxXBoxMag = TraitNameToIDAdd(s_szMaxXBoxMag, -1);
    static int iMouseMinPercent = TraitNameToIDAdd(s_szMouseMinPercent, -1);
    static int iMouseMaxPercent = TraitNameToIDAdd(s_szMouseMaxPercent, -1);
    float fMinResistance = FUN_00726070()->FUN_00a011b0(iMinResistanceTime);
    float fMaxResistance = FUN_00726070()->FUN_00a011b0(iMaxResistanceTime);
    float fMinMagnitude = FUN_00726070()->FUN_00a011b0(iMinMagnitude);
    float fMaxMagnitude = FUN_00726070()->FUN_00a011b0(iMaxMagnitude);
    float fSampleMinXBoxMag = FUN_00726070()->FUN_00a011b0(iMinXBoxMag);
    float fMaxXBoxMagCount = FUN_00726070()->FUN_00a011b0(iMaxXBoxMag);
    float fMouseMinLocal = FUN_00726070()->FUN_00a011b0(iMouseMinPercent) / 100.0;
    float fMouseMax = FUN_00726070()->FUN_00a011b0(iMouseMaxPercent) / 100.0;
    if (abForcing)
    {
        bForcing = true;
        kArgumentPosition->FUN_00700320(0xfa3, 1);
        float fResistanceTimeLocal;
        float fMagnitudeVal;
        float fMouseNew;
        ComputeInjuryEffectScalars(&fResistanceTimeLocal, &fMagnitudeVal, &fMouseNew,
                                   FUN_00726070()->FUN_00a011b0(DAT_011dad9c) / 100.0, fLockLevel / 100.0,
                                   DAT_011dea3c->kValues.GetActorValue(0x25));
        fResistanceTimeLocal = LinearInterpolate(fMinResistance, fMaxResistance, 0.0f, 1.0f, fResistanceTimeLocal);
        float fShakeXVal = ApplyNoise(DAT_011f6394.FUN_00825c00() * 0.00025f);
        float fShakeY = ApplyNoise((DAT_011f6394.FUN_00825c00() + 0x3039) * 0.00025f);
        fMagnitudeVal = LinearInterpolate(fMinMagnitude, fMaxMagnitude, 0.0f, 1.0f, fMagnitudeVal);
        fShakeXVal = LinearInterpolate(fShakeXVal >= 0.0 ? fMinMagnitude : -fMinMagnitude,
                                       fShakeXVal >= 0.0 ? fMaxMagnitude : -fMaxMagnitude, -0.5f, 0.5f, fShakeXVal) *
                     fMagnitudeVal;
        fShakeY = LinearInterpolate(fShakeY >= 0.0 ? fMinMagnitude : -fMinMagnitude,
                                    fShakeY >= 0.0 ? fMaxMagnitude : -fMaxMagnitude, -0.5f, 0.5f, fShakeY) *
                  fMagnitudeVal;
        fMouseNew = LinearInterpolate(fMouseMinLocal, fMouseMax, 0.0f, 1.0f, fMouseNew);
        if (1)
        {
            kIntersectionOffset.x = fShakeXVal;
            kIntersectionOffset.y = fShakeY;
        }
        kCursorPos.Add(&kIntersectionOffset);
        PickInput* pInputIn = DAT_011dea0c->FUN_00877720();
        PickPoint kInput;
        if (FUN_004b7210()->FUN_004b71d0())
        {
            int iStickX = pInputIn->GetAxisState(0, 7);
            int iStickYTmp = pInputIn->GetAxisState(0, 8);
            kInput.x = (int)(iStickX * *DAT_011d8c5c.FUN_00403e20());
            kInput.y = (int)(-iStickYTmp * *DAT_011d8c5c.FUN_00403e20());
            kCursorPos.Add(&kInput.FUN_004a4f40(LinearInterpolate(0.25f, 0.5f, 0.0f, 1.0f, fMouseNew)));
        }
        else
        {
            kInput.x = pInputIn->FUN_00a239e0(1);
            kInput.y = pInputIn->FUN_00a239e0(2);
            kCursorPos.Add(&FUN_00532fd0(fMouseNew, kInput));
        }
        fResistance = fMagnitudeVal * fMouseNew * kInput.FUN_00589850();
        if (fResistance > 10.0)
            fResistance = 10.0f;
        fResistance = fResistance / 5.0;
        UpdateTilePositions((int)kCursorPos.x, (int)kCursorPos.y);
        float fTimeSinceScaleStart = GetRatio();
        pInterfaceFinal->UpdateTilePosition(
            pDial->GetTotalFloat(pDial->GetAccumulatedFloat() / FUN_004dc200() * fTimeSinceScaleStart) /
            FUN_004dc1f0() * fTimeSinceScaleStart);
    }
    else
    {
        bForcing = false;
        fResistance = 0.0f;
        kArgumentPosition->FUN_00700320(0xfa3, 0);
        if (FUN_004b7210()->FUN_004b71d0())
        {
            PickInput* pPadIn = DAT_011dea0c->FUN_00877720();
            int iPadX = pPadIn->GetAxisState(0, 7);
            int iPadY = pPadIn->GetAxisState(0, 8);
            iPadX = (int)(iPadX * *DAT_011d8c5c.FUN_00403e20());
            iPadY = (int)(-iPadY * *DAT_011d8c5c.FUN_00403e20());
            UpdateTilePositions((int)pDial->FUN_00a011b0(0xfa1) + iPadX, (int)pDial->FUN_00a011b0(0xfa2) + iPadY);
        }
        else
        {
            UpdateTilePositions(pInterfaceFinal->FUN_00747d00(), pInterfaceFinal->FUN_0073b020());
        }
    }
}

}

struct EventExtraNode
{
    void** FUN_006815c0();
};
struct EventEntry
{
    EventExtraNode* FUN_00559450();
    int FUN_00726070();
    void* FUN_0044ddc0();
    ~EventEntry();
};
struct EventTile
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
};
struct EventValues
{
    virtual void v0();
    virtual void v4();
    virtual int Current(int);
    virtual float Damage(int);
};
struct EventMagic
{
};
struct EventFormBase
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
};
struct EventForm : EventFormBase, EventMagic
{
};
struct EventTarget
{
    bool FUN_00822b90(EventMagic*, bool);
};
struct EventPlayer
{
    virtual void pv000();
    virtual void pv004();
    virtual void pv008();
    virtual void pv00c();
    virtual void pv010();
    virtual void pv014();
    virtual void pv018();
    virtual void pv01c();
    virtual void pv020();
    virtual void pv024();
    virtual void pv028();
    virtual void pv02c();
    virtual void pv030();
    virtual void pv034();
    virtual void pv038();
    virtual void pv03c();
    virtual void pv040();
    virtual void pv044();
    virtual void pv048();
    virtual void pv04c();
    virtual void pv050();
    virtual void pv054();
    virtual void pv058();
    virtual void pv05c();
    virtual void pv060();
    virtual void pv064();
    virtual void pv068();
    virtual void pv06c();
    virtual void pv070();
    virtual void pv074();
    virtual void pv078();
    virtual void pv07c();
    virtual void pv080();
    virtual void pv084();
    virtual void pv088();
    virtual void pv08c();
    virtual void pv090();
    virtual void pv094();
    virtual void pv098();
    virtual void pv09c();
    virtual void pv0a0();
    virtual void pv0a4();
    virtual void pv0a8();
    virtual void pv0ac();
    virtual void pv0b0();
    virtual void pv0b4();
    virtual void pv0b8();
    virtual void pv0bc();
    virtual void pv0c0();
    virtual void pv0c4();
    virtual void pv0c8();
    virtual void pv0cc();
    virtual void pv0d0();
    virtual void pv0d4();
    virtual void pv0d8();
    virtual void pv0dc();
    virtual void pv0e0();
    virtual void pv0e4();
    virtual void pv0e8();
    virtual void pv0ec();
    virtual void pv0f0();
    virtual void pv0f4();
    virtual void pv0f8();
    virtual void pv0fc();
    virtual void pv100();
    virtual void pv104();
    virtual void pv108();
    virtual void pv10c();
    virtual void pv110();
    virtual void pv114();
    virtual void pv118();
    virtual void pv11c();
    virtual void pv120();
    virtual void pv124();
    virtual void pv128();
    virtual void pv12c();
    virtual void pv130();
    virtual void pv134();
    virtual void pv138();
    virtual void pv13c();
    virtual void pv140();
    virtual void pv144();
    virtual void pv148();
    virtual void pv14c();
    virtual void pv150();
    virtual void pv154();
    virtual void pv158();
    virtual void pv15c();
    virtual void pv160();
    virtual void pv164();
    virtual void pv168();
    virtual void pv16c();
    virtual void pv170();
    virtual void pv174();
    virtual void pv178();
    virtual void pv17c();
    virtual void pv180();
    virtual void pv184();
    virtual void pv188();
    virtual void pv18c();
    virtual void pv190();
    virtual void pv194();
    virtual void pv198();
    virtual void pv19c();
    virtual void pv1a0();
    virtual void pv1a4();
    virtual void pv1a8();
    virtual void pv1ac();
    virtual void pv1b0();
    virtual void pv1b4();
    virtual void pv1b8();
    virtual void pv1bc();
    virtual void pv1c0();
    virtual void pv1c4();
    virtual void pv1c8();
    virtual void pv1cc();
    virtual void pv1d0();
    virtual void pv1d4();
    virtual void pv1d8();
    virtual void pv1dc();
    virtual void pv1e0();
    virtual void pv1e4();
    virtual void pv1e8();
    virtual void pv1ec();
    virtual void pv1f0();
    virtual void pv1f4();
    virtual void pv1f8();
    virtual void pv1fc();
    virtual void pv200();
    virtual void pv204();
    virtual void pv208();
    virtual void pv20c();
    virtual void pv210();
    virtual void pv214();
    virtual void pv218();
    virtual void pv21c();
    virtual void pv220();
    virtual void pv224();
    virtual void pv228();
    virtual void pv22c();
    virtual void pv230();
    virtual void pv234();
    virtual void pv238();
    virtual void pv23c();
    virtual void pv240();
    virtual void pv244();
    virtual void pv248();
    virtual void pv24c();
    virtual void pv250();
    virtual void pv254();
    virtual void pv258();
    virtual void pv25c();
    virtual void pv260();
    virtual void pv264();
    virtual void pv268();
    virtual void pv26c();
    virtual void pv270();
    virtual void pv274();
    virtual void pv278();
    virtual void pv27c();
    virtual void pv280();
    virtual void pv284();
    virtual void pv288();
    virtual void pv28c();
    virtual void pv290();
    virtual void pv294();
    virtual void pv298();
    virtual void pv29c();
    virtual void pv2a0();
    virtual void pv2a4();
    virtual void pv2a8();
    virtual void pv2ac();
    virtual void pv2b0();
    virtual void pv2b4();
    virtual void pv2b8();
    virtual void pv2bc();
    virtual void pv2c0();
    virtual void pv2c4();
    virtual void pv2c8();
    virtual void pv2cc();
    virtual void pv2d0();
    virtual void pv2d4();
    virtual void pv2d8();
    virtual void pv2dc();
    virtual void pv2e0();
    virtual void pv2e4();
    virtual void pv2e8();
    virtual void pv2ec();
    virtual void pv2f0();
    virtual void pv2f4();
    virtual void pv2f8();
    virtual void pv2fc();
    virtual void pv300();
    virtual void pv304();
    virtual void pv308();
    virtual void pv30c();
    virtual void pv310();
    virtual void pv314();
    virtual void pv318();
    virtual void pv31c();
    virtual void pv320();
    virtual void pv324();
    virtual void pv328();
    virtual void pv32c();
    virtual void pv330();
    virtual void pv334();
    virtual void pv338();
    virtual void pv33c();
    virtual void pv340();
    virtual void pv344();
    virtual void pv348();
    virtual void pv34c();
    virtual void pv350();
    virtual void pv354();
    virtual void pv358();
    virtual void pv35c();
    virtual void pv360();
    virtual void pv364();
    virtual void pv368();
    virtual void pv36c();
    virtual void pv370();
    virtual void pv374();
    virtual void pv378();
    virtual void pv37c();
    virtual void pv380();
    virtual void pv384();
    virtual void pv388();
    virtual void pv38c();
    virtual void pv390();
    virtual void pv394();
    virtual void pv398();
    virtual void pv39c();
    virtual void pv3a0();
    virtual void pv3a4();
    virtual void pv3a8();
    virtual void Mod(int, float, int);
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
    EventTarget target;
    int unk98;
    int unk9c;
    int unka0;
    EventValues values;
    EventEntry* FUN_00576260(EventForm*, int);
    void EquipItem(void*, int, void*, bool, bool, bool);
    void FUN_0088b740(int, float);
};
struct EventScene
{
    void* ptr;
    void* FUN_00559450();
};
struct EventWounds
{
    int unk00, unk04, unk08;
    bool changed;
};
struct EventMenu
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
    EventTile* label;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    EventTile* gauge;
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
    float amount;
    int unkb0;
    int unkb4;
    int unkb8;
    EventEntry* entry;
    int limb;
    int unkc4;
    EventScene nodes[8];
    EventTile* FUN_00726070();
    int FUN_00720010(int);
    void SetDirection(int);
    void FUN_007e5ee0(int, int);
    int GetIndex(int);
    float FUN_007e58e0();
    void UpdateWounds(float);
    int GetLimbPercentage();
    EventWounds* FUN_007e5720();
    void OnButtonClick(int, int);
};
int __cdecl TraitNameToIDAdd(const char*, int);
EventForm* __cdecl FUN_0058db10(int);
void __cdecl ComputeMedicineHealing(float&, float&, int, bool, float);
float __cdecl FUN_0040ebd0(float, float);
void __cdecl UpdateBoneWounds(void*);

// Handles surgery menu button presses to apply stimpak or morphine, cycle the selected limb, or heal the current limb.
// @fnv 0x007e1b10
void EventMenu::OnButtonClick(int button, int arg)
{
    static int stimpak = TraitNameToIDAdd("_StimpacCount", -1);
    static int morphine = TraitNameToIDAdd("_MorphineCount", -1);
    int event = FUN_00720010(button);
    {
        float benefit;
        {
            bool has;
            {
                float cost;
                {
                    float healing;
                    {
                        EventWounds* wounds;
                        switch (event)
                        {
                        case 1:
                            CloseSurgeryMenu();
                            break;
                        case 4:
                            if (((EventMenu*)DAT_011dada4)->entry &&
                                ((EventMenu*)DAT_011dada4)->entry->FUN_00726070() > 0)
                            {
                                FUN_00726070()->FUN_00a012d0(stimpak, FUN_00726070()->FUN_00a011b0(stimpak) - 1.0,
                                                             true);
                                ((EventPlayer*)_g_thePlayer)
                                    ->EquipItem(
                                        ((EventMenu*)DAT_011dada4)->entry->FUN_0044ddc0(),
                                        ((EventMenu*)DAT_011dada4)->entry->FUN_00726070(),
                                        ((EventMenu*)DAT_011dada4)->entry->FUN_00559450()
                                            ? *(((EventMenu*)DAT_011dada4)->entry->FUN_00559450()->FUN_006815c0())
                                            : 0,
                                        false, false, true);
                            }
                            SetDirection(3);
                            break;
                        case 5:
                            if (FUN_00726070()->FUN_00a011b0(morphine) > 0.0)
                            {
                                EventEntry* item = ((EventPlayer*)_g_thePlayer)->FUN_00576260(FUN_0058db10(4), 0);
                                FUN_00726070()->FUN_00a012d0(morphine, FUN_00726070()->FUN_00a011b0(morphine) - 1.0,
                                                             true);
                                ((EventPlayer*)_g_thePlayer)
                                    ->EquipItem(FUN_0058db10(4), item->FUN_00726070(),
                                                   item->FUN_00559450() ? *(item->FUN_00559450()->FUN_006815c0()) : 0,
                                                   false, false, true);
                                delete item;
                                amount -= 25.0;
                                if (FUN_00726070()->FUN_00a011b0(DAT_011dad9c) >= 25.0)
                                    FUN_00726070()->FUN_00a012d0(
                                        DAT_011dad9c, FUN_00726070()->FUN_00a011b0(DAT_011dad9c) - 25.0, true);
                                else
                                    FUN_00726070()->FUN_00700320(DAT_011dad9c, 0);
                            }
                            SetDirection(2);
                            break;
                        case 14: {
                            int iOldLimb = limb;
                            switch (limb)
                            {
                            case 26:
                                limb = 27;
                                break;
                            case 27:
                                limb = 28;
                                break;
                            case 29:
                                limb = 30;
                                break;
                            case 28:
                                limb = 29;
                                break;
                            case 30:
                                limb = 25;
                                break;
                            case 25:
                            case -1:
                                limb = 26;
                                break;
                            }
                            amount = ScaleLimbWoundPercent(((EventPlayer*)_g_thePlayer)->values.Damage(limb));
                            gauge->FUN_00a012d0(TraitNameToID("_Value"),
                                                ((EventPlayer*)_g_thePlayer)->values.Damage(limb) / 100.0, true);
                            label->FUN_00a01350(0xfc4, ActorValue::GetActorValueName((ActorValue::Index)limb), true);
                            FUN_007e5ee0(iOldLimb, limb);
                            UpdateBoneWounds(((EventMenu*)DAT_011dada4)->nodes[GetIndex(limb)].FUN_00559450());
                            break;
                        }
                        case 15: {
                            int old2 = limb;
                            switch (limb)
                            {
                            case 26:
                                limb = 25;
                                break;
                            case 27:
                                limb = 26;
                                break;
                            case 29:
                                limb = 28;
                                break;
                            case 28:
                                limb = 27;
                                break;
                            case 30:
                                limb = 29;
                                break;
                            case 25:
                            case -1:
                                limb = 30;
                                break;
                            }
                            amount = ScaleLimbWoundPercent(((EventPlayer*)_g_thePlayer)->values.Damage(limb));
                            gauge->FUN_00a012d0(TraitNameToID("_Value"),
                                                ((EventPlayer*)_g_thePlayer)->values.Damage(limb) / 100.0, true);
                            label->FUN_00a01350(0xfc4, ActorValue::GetActorValueName((ActorValue::Index)limb), true);
                            FUN_007e5ee0(old2, limb);
                            UpdateBoneWounds(((EventMenu*)DAT_011dada4)->nodes[GetIndex(limb)].FUN_00559450());
                            break;
                        }
                        case 2: {
                            has = ((EventPlayer*)_g_thePlayer)->target.FUN_00822b90(FUN_0058db10(4), true);

                            ComputeMedicineHealing(benefit, cost, ((EventPlayer*)_g_thePlayer)->values.Current(37), has,
                                                   ((EventPlayer*)_g_thePlayer)->values.Damage(limb));
                            healing = FUN_0040ebd0(FUN_007e58e0() * 100.0 + benefit, 100.0f);
                            UpdateWounds(1.0 - healing / 100.0);
                            ((EventPlayer*)_g_thePlayer)
                                ->FUN_0088b740(limb, (float)(GetLimbPercentage() -
                                                             ((EventPlayer*)_g_thePlayer)->values.Current(limb)));
                            ((EventPlayer*)_g_thePlayer)->Mod(16, -cost, 0);
                            wounds = ((EventMenu*)DAT_011dada4)->FUN_007e5720();
                            wounds->changed = true;
                            break;
                        }
                        }
                    }
                }
            }
        }
    }
}

struct BoneText
{
    const char* FUN_0043b1b0() const;
};
struct BoneBlock
{
    BoneText& FUN_006815c0();
};
struct BoneAnim
{
    BoneText& FUN_00413f40();
    unsigned FUN_0084e3a0();
    BoneBlock* FUN_007e4fc0(unsigned);
    int FUN_004937a0(unsigned);
    void FUN_00a32b80(unsigned);
    FUN_007e4540_root* FUN_005f5f80();
    void* FUN_008d6f30();
    void FUN_00a34ba0(float, bool);
    float FUN_00508100();
    void FUN_00a328b0(float, bool);
};
struct BoneManager
{
    unsigned FUN_00495d00();
    BoneAnim* FUN_00495d20(unsigned);
    void FUN_0047aab0(BoneAnim*, int, bool, float, float, void*);
};
struct BoneHost
{
    BoneManager* FUN_00a5c570(const NiRTTIS*);
    void FUN_00a59c60(NiUpdateDataS&);
};
struct BoneEntry;
struct BoneNode
{
    BoneEntry** FUN_006815c0();
    BoneNode* FUN_00726070();
    bool FUN_008256d0();
    void FUN_005ae3d0(BoneEntry*&);
};
struct FUN_0096a2d0
{
    void* item;
    void* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(void* const&);
};
struct BoneEntry
{
    BoneAnim* anim;
    FUN_0096a2d0* objects;
    float radius;
};
struct BoneWound
{
    BoneNode* list;
    int limb;
    int bracket;
    unsigned char dirty;
};
struct BoneValues
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float Get(int);
};
struct BonePlayer
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
    int unk98;
    int unk9c;
    int unka0;
    BoneValues values;
};
struct BoneMenu
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
    int limb;
    int bracket;
    int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    BoneManager* manager;
    BoneWound* FUN_007e5720();
    int GetTierFromPercent(int);
};
struct BoneWoundList
{
    void FUN_005ae3d0(BoneWound*&);
};
extern "C" int sprintf(char*, const char*, ...);
extern "C" int _strnicmp(const char*, const char*, unsigned);

// Updates bone wound animations on the host by matching bone names, computing a blend factor from the limb tier, and applying it to each wound entry.
// @fnv 0x007e4920
void __cdecl UpdateBoneWounds(BoneHost* host)
{
    if (!host)
        return;
    BoneManager* managerLocal3 = host->FUN_00a5c570(&DAT_011f36ac);
    bool cachedX = true;
    if (managerLocal3)
    {
        ((BoneMenu*)DAT_011dada4)->manager = managerLocal3;
        BoneWound* previous_2 = ((BoneMenu*)DAT_011dada4)->FUN_007e5720();
        BoneWound* currentItem = 0;
        if (!previous_2)
        {
            cachedX = false;
            currentItem = new BoneWound;
            currentItem->limb = ((BoneMenu*)DAT_011dada4)->limb;
            currentItem->bracket =
                ((BoneMenu*)DAT_011dada4)
                    ->GetTierFromPercent((int)((BonePlayer*)DAT_011dea3c)->values.Get(currentItem->limb));
            currentItem->list = (BoneNode*)new FUN_0096a2d0;
            currentItem->dirty = 0;
            ((BoneWoundList&)g_011dae48).FUN_005ae3d0(currentItem);
        }
        else
            currentItem = previous_2;
        for (unsigned i = 0; i < ((BoneMenu*)DAT_011dada4)->manager->FUN_00495d00(); i++)
        {
            BoneAnim* sequence5 = ((BoneMenu*)DAT_011dada4)->manager->FUN_00495d20(i);
            char nameSize5[32];
            sprintf(nameSize5, "Bone%s", sequence5->FUN_00413f40().FUN_0043b1b0());
            BoneEntry* entry24 = 0;
            if (!previous_2 || previous_2->dirty == 1)
            {
                entry24 = new BoneEntry;
                entry24->objects = new FUN_0096a2d0;
                entry24->anim = sequence5;
            }
            for (unsigned j = 0; j < sequence5->FUN_0084e3a0(); j++)
            {
                BoneBlock* block = sequence5->FUN_007e4fc0(j);
                if (sequence5->FUN_004937a0(j))
                {
                    if (_strnicmp(nameSize5, block->FUN_006815c0().FUN_0043b1b0(), 6))
                        sequence5->FUN_00a32b80(j);
                    else if (!previous_2 || previous_2->dirty == 1)
                    {
                        entry24->objects->FUN_005ae3d0(
                            sequence5->FUN_005f5f80()->v039((const NiFixedString&)block->FUN_006815c0()));
                    }
                }
            }
            NiPoint2S p;
            NiPoint2S pointB_;
            if (entry24)
                currentItem->list->FUN_005ae3d0(entry24);
        }
    }
    float blendA = 0.0f;
    ((BoneMenu*)DAT_011dada4)->bracket =
        ((BoneMenu*)DAT_011dada4)
            ->GetTierFromPercent((int)((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb));
    switch (((BoneMenu*)DAT_011dada4)->bracket)
    {
    case 1:
        blendA = (25.0 - (((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb) - 75.0)) / 25.0;
        break;
    case 2:
        blendA =
            ((25.0 - (((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb) - 50.0)) + 25.0) / 50.0;
        break;
    case 3:
        blendA =
            ((25.0 - (((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb) - 25.0)) + 50.0) / 75.0;
        break;
    case 4:
        blendA = ((25.0 - ((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb)) + 75.0) / 100.0;
        break;
    }
    BoneWound* wound9 = ((BoneMenu*)DAT_011dada4)->FUN_007e5720();
    if (wound9 && ((BoneMenu*)DAT_011dada4)->bracket)
    {
        BoneNode* node = wound9->list;
        while (node && !node->FUN_008256d0())
        {
            if ((*node->FUN_006815c0())->anim->FUN_008d6f30() == ((BoneMenu*)DAT_011dada4)->manager)
            {
                ((BoneMenu*)DAT_011dada4)->manager->FUN_0047aab0((*node->FUN_006815c0())->anim, 0, true, 1.0f, 0.0f, 0);
            }
            (*node->FUN_006815c0())->anim->FUN_00a34ba0(0.0f, true);
            if (!cachedX || wound9->dirty)
            {
                (*node->FUN_006815c0())
                    ->anim->FUN_00a328b0((*node->FUN_006815c0())->anim->FUN_00508100() * blendA, true);
                (*node->FUN_006815c0())->radius = (*node->FUN_006815c0())->anim->FUN_00508100() * blendA;
            }
            else
                (*node->FUN_006815c0())->anim->FUN_00a328b0((*node->FUN_006815c0())->radius, true);
            node = node->FUN_00726070();
        }
        wound9->dirty = 0;
    }
    NiUpdateDataS update2(0.0f, true, false);
    host->FUN_00a59c60(update2);
}

class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011dae28;
extern GlobalObject_0044f440 g_011dadf0;
extern GlobalObject_0044f440 g_011dadfc;
extern GlobalObject_0044f440 g_011dae6c;

struct BipAVObject
{
    void FUN_004bc1f0(float, float, float);
    void FUN_00440490(float);
};

struct BipRoot
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
    virtual BipAVObject* v039(const NiFixedString& arName);
    void FUN_00a59c60(NiUpdateDataS&);
};

struct BipPointer
{
    BipRoot* FUN_00559450();
};
extern BipPointer DAT_011dae5c;

// Looks up the "Bip01" node, calls two methods with global float values and arguments, then updates the current root.
// @fnv 0x007e4fe0
void __cdecl FUN_007e4fe0(float a, float b, float c)
{
    if (DAT_011dae5c.FUN_00559450())
    {
        DAT_011dae5c.FUN_00559450()
            ->v039(NiFixedString("Bip01"))
            ->FUN_004bc1f0(-*g_011dae6c.Float(), *g_011dadf0.Float() - b, *g_011dae28.Float() - a);
        DAT_011dae5c.FUN_00559450()->v039(NiFixedString("Bip01"))->FUN_00440490(*g_011dadfc.Float() * (double)c);
        NiUpdateDataS kData(0.0f, false, false);
        DAT_011dae5c.FUN_00559450()->FUN_00a59c60(kData);
    }
}

struct LimbPercentageMenu : SurgeryLimbMenu
{
    unsigned int modeC4;
    int GetLimbPercentage();
};

// Computes a limb percentage from a mode and fraction, updates two UI tiles, and returns the integer percentage.
// @fnv 0x007e5590
int LimbPercentageMenu::GetLimbPercentage()
{
    float fraction = 1.0f - FUN_007e58e0();
    float percentage = 0.0f;
    switch (((LimbPercentageMenu*)DAT_011dada4)->modeC4)
    {
    case 4:
        percentage = LinearInterpolate(100.0f, 0.0f, 0.0f, 1.0f, fraction);
        break;
    case 3:
        percentage = LinearInterpolate(100.0f, 25.0f, 0.0f, 1.0f, fraction);
        break;
    case 2:
        percentage = LinearInterpolate(100.0f, 50.0f, 0.0f, 1.0f, fraction);
        break;
    case 1:
        percentage = LinearInterpolate(100.0f, 75.0f, 0.0f, 1.0f, fraction);
        break;
    case 0:
        percentage = 100.0f;
        break;
    }
    int result2 = (int)percentage;
    tile70->Set(TraitNameToID("_Value"), result2 / 100.0, true);
    tile4C->Set(0xfc4, ActorValue::GetActorValueName(avC0), true);
    return result2;
}

struct Thing
{
    int GetIndex(int value);
};

// Maps specific input values to a small index range, returning 0 for unknown inputs.
// @fnv 0x007e5e30
int Thing::GetIndex(int value)
{
    switch (value)
    {
    case 0x1a:
        return 0;
    case 0x1b:
        return 1;
    case 0x1d:
        return 2;
    case 0x1c:
        return 3;
    case 0x1e:
        return 4;
    case 0x19:
        return 5;
    case -1:
        return 6;
    default:
        break;
    }
    return 0;
}
