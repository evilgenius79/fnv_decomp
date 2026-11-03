// fallout/interface/menus/mapmenu.cpp: MapMenu, Interface, InsertBox, TileImage and more (116 functions)

#include "mapmenu_decls.h"

// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    SetSelectedTile(0, notify);
}

// @fnv 0x00a20610
void TileImage::SetTexture(NiAVObject* image)
{
    int unused1, unused2;
    Set(0xfcc, "", true);
    texture = image;
    SetImageFlags(0x30);
}

// @fnv 0x0079f640
void MapMenu::SetMapPositionToPlayer()
{
    if (DAT_011da368 && g_thePlayer->FUN_00798400())
    {
        TESObjectREFR* ref = g_thePlayer->FUN_00798400();
        DAT_011da368->m_kPlayerWorldPosition = *ref->GetPos();
        DAT_011da368->m_pCurrentMapSpace = g_thePlayer->FUN_00798400()->GetParentWorldSpace();
        if (!DAT_011da368->m_pCurrentMapSpace)
            DAT_011da368->m_pCurrentMapSpace = g_thePlayer->FUN_00798400()->GetParentCell();
    }
}

// @fnv 0x00798bf0
void MapMenu::StopMapMenuSounds()
{
    if (DAT_011da368)
    {
        if (DAT_011da368->m_pkActiveSoundList && DAT_011da368->m_pkActiveSoundList->GetItem().IsPlaying())
            DAT_011da368->m_pkActiveSoundList->GetItem().Stop();
        DAT_011da368->m_kSoundList.RemoveAll();
        DAT_011da368->SubtitlesToShow.Clear(true);
        DAT_011da368->m_pkActiveSoundList = 0;
        DAT_011da368->m_fMapZoom = 0.0f;
        DAT_011da368->m_iMapSelectionIndex = 0;
        DAT_011da368->m_bMapListUpdatePending = false;
    }
}

// @fnv 0x007a1670
void MapMenu::OpenMap()
{
    if (Interface::GetSelectedTargetIndex(Interface::Map) && DAT_011da368->m_iMapDisplayMode == 33)
        return;
    if (DAT_011da368)
    {
        NiAVObject* node =
            DAT_011da368->m_pTiles[4]->FUN_0056c7f0() ? DAT_011da368->m_pTiles[4]->FUN_0056c7f0()->FUN_0045bc00(0) : 0;
        TileShaderProperty* property =
            node ? reinterpret_cast<TileShaderProperty*>(node->GetProperty(FUN_00438220())) : 0;
        if (property && property->FUN_009c8640())
        {
            property->SetTextureImage(0);
            DAT_011da368->m_pTiles[4]->Set(0xfcc, "", true);
            DAT_011da36c = true;
        }
    }
}

// @fnv 0x007a1490
void MapMenu::UpdateMapPosition()
{
    if (DAT_011da368)
    {
        NiNode* localNode = DAT_011da368->m_pTiles[2]->FUN_0056c7f0();
        if (!localNode)
            return;
        for (unsigned int i = 0; i < localNode->FUN_0043b480(); ++i)
        {
            NiAVObject* child = localNode->GetAt(i);
            if (child)
                localNode->RemoveObject(child);
        }
        DAT_011da368->m_pTiles[2]->ResetImage();
        DAT_011da368->m_pTiles[2]->Set(0xfa3, 0);
        DAT_011da368->m_pTiles[3]->Set(0xfa3, 0);
        DAT_011da368->m_pTiles[3]->UpdateTrait(0xff5);
        DAT_011da368->LocalMapMarkerList.RemoveAll();
        DAT_011da368->m_pTiles[4]->ResetImage();
        DAT_011da368->m_pTiles[5]->UpdateTrait(0xff5);
        DAT_011da368->m_kMapMarkerList.RemoveAll();
        DAT_011da368->m_kMapMarkerTiles.Clear(true);
        DAT_011da368->m_uiMapMarkerCount = 0;
        DAT_011da368->m_pMapTile = 0;
        NiAVObject* node = DAT_011da368->m_pTiles[16]->FUN_0056c7f0()
                               ? DAT_011da368->m_pTiles[16]->FUN_0056c7f0()->FUN_0045bc00(0)
                               : 0;
        TileShaderProperty* property =
            node ? reinterpret_cast<TileShaderProperty*>(node->GetProperty(FUN_00438220())) : 0;
        if (property && property->FUN_009c8640())
        {
            property->SetTextureImage(0);
            DAT_011da368->m_pTiles[16]->Set(0xfcc, "", true);
        }
        DAT_011da368->FUN_0079c090();
    }
}

// Initializes the MapMenu by caching tile IDs for its UI elements and resetting its member fields to default values.
// @fnv 0x00796740
MapMenu::MapMenu()
{
    DAT_011da354 = Tile::GetTraitID("_Title");
    DAT_011da358 = Tile::GetTraitID("_Value");
    DAT_011da360 = Tile::GetTraitID("_CurrentTab");
    DAT_011da348 = Tile::GetTraitID("_selected");
    DAT_011da344 = Tile::GetTraitID("_TextAlpha");
    DAT_011da350 = Tile::GetTraitID("_x");
    DAT_011da34c = Tile::GetTraitID("_y");
    DAT_011da35c = Tile::GetTraitID("_Magnification");
    m_fMapRotation = 0.0f;
    m_bMapMenuActive = true;
    m_pkActiveSoundList = 0;
    m_bMapListUpdatePending = false;
    m_pSecondMapReference = 0;
    m_iMapDisplayMode = 36;
    m_kPlayerWorldPosition = NiPoint3::ZERO;
    m_pCurrentMapSpace = 0;
    m_pCurrentMapForm = 0;
    m_pMapTile = 0;
    m_pSelectedQuest = 0;
    m_pSelectedNote = 0;
    pAdjustNorthRotationCell = 0;
    m_pSelectedMarkerTile = 0;
    m_uiMapState = 0;
    m_fSavedMusicVolume = BSAudio::GetSingleton()->GetMusicVolume();
    m_pSelectedMapMarkerInfo = 0;
    m_uiMapMarkerCount = 0;
    m_pFirstMapReference = 0;
    m_bNeedsMapUpdate = true;
    m_pCurrentWorldspace = 0;
    m_bLocalMapMode = false;
}

// @fnv 0x00796a40
int MapMenu::GetClass()
{
    return 0x3FF;
}

struct FUN_00796f40_shell : public Tile
{
    void SetFlag8000(bool);
};

// Sets or clears bit 0x8000 in the flags field at offset 0x30 of this Tile based on abOn.
// @fnv 0x00796f40
void FUN_00796f40_shell::SetFlag8000(bool abOn)
{
    abOn ? *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) |= 0x8000
         : *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) &= ~0x8000;
}

struct FUN_00798400_shell : public PlayerCharacter
{
    TESObjectREFR* FUN_00798400();
};

// @fnv 0x00798400
TESObjectREFR* FUN_00798400_shell::FUN_00798400()
{
    return *(TESObjectREFR**)((char*)this + 0x6f4);
}

struct FUN_0079c090_shell : public MapMenu
{
    void FUN_0079c090();
};

// Clears the float at offset 0x88 and sets the tile at offset 0x68 to value 0xfa3 with 0.
// @fnv 0x0079c090
void FUN_0079c090_shell::FUN_0079c090()
{
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x88) = 0.0f;
    (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x68))->Set(0xfa3, 0);
}

// If DAT_011da368 is set, calls Set on the Tile at offset 0x30 with DAT_011da35c and afMagnification.
// @fnv 0x007a1820
void __cdecl FUN_007a1820(float afMagnification)
{
    if (DAT_011da368)
    {
        (*(Tile**)((char*)DAT_011da368 + 0x30))->Set(DAT_011da35c, afMagnification, true);
    }
}

// If DAT_011da368 is set, calls Set on the Tile at offset 0x38 with DAT_011da35c and afMagnification.
// @fnv 0x007a1850
void __cdecl FUN_007a1850(float afMagnification)
{
    if (DAT_011da368)
    {
        (*(Tile**)((char*)DAT_011da368 + 0x38))->Set(DAT_011da35c, afMagnification, true);
    }
}

extern int DAT_01075530;

struct Dummy_007a1a70
{
    void* vtable;
    void FUN_007a63f0(int, int);
};

// Sets the object's vtable to DAT_01075530 and calls FUN_007a63f0 with 0, 0, returning the object.
// @fnv 0x007a1a70
Dummy_007a1a70* __fastcall FUN_007a1a70(Dummy_007a1a70* pThis)
{
    pThis->vtable = &DAT_01075530;
    pThis->FUN_007a63f0(0, 0);
    return pThis;
}

struct NiTexture;
struct FUN_009c8640_shell : public TileShaderProperty
{
    NiTexture* FUN_009c8640();
};

// @fnv 0x009c8640
NiTexture* FUN_009c8640_shell::FUN_009c8640()
{
    return (NiTexture*)(const char*)(*(BSStringT<char>*)((char*)this + 0x60));
}

void __fastcall FUN_00ad88b0(SoundPlaybackHandle*);
void __fastcall UpdateWaveAnimation(MapMenu*);
void __fastcall UpdateHolotapePlayback(MapMenu*);
struct A7d
{
    float GetTotalFloat();
};
struct C7d
{
    float GetAccumulatedFloat();
};
struct NoteReadState
{
    void SetRead(bool);
};
extern double _gModifierZero;

// Updates the map menu: toggles the playing item, handles map input modes, moves the highlight, marks notes read, and refreshes the menu.
// @fnv 0x0079a130
void __fastcall UpdateMapMenu(MapMenu* menu)
{
    unsigned int i;
    Tile* pcurrTile;
    float fhighlightX;
    float fhighlightY;
    BGSNote* pcurrNote;

    if (Interface::GetSelectedTargetIndex((Interface::enumMenus)0x3f5) && menu->m_pkActiveSoundList &&
        menu->m_pkActiveSoundList->GetItem().IsPlaying())
    {
        FUN_00ad88b0(&menu->m_pkActiveSoundList->GetItem());
        DAT_011da36f = true;
        DAT_011da40c = g_timeGlobal.GetTimeStamp();
    }
    else if (!Interface::GetSelectedTargetIndex((Interface::enumMenus)0x3f5) &&
             !Interface::GetSelectedTargetIndex((Interface::enumMenus)0x3e9) && menu->m_pkActiveSoundList &&
             DAT_011da36f)
    {
        menu->m_pkActiveSoundList->GetItem().Play(false);
        DAT_011da36f = false;
        menu->m_iMapSelectionIndex += g_timeGlobal.GetTimeStamp() - DAT_011da40c;
    }

    if (!Interface::GetPipboyManagerInstance()->IsUnk28Set())
        return;

    if (Interface::GetSelectedTargetIndex(Interface::Map))
    {
        switch (DAT_011da368->m_iMapDisplayMode)
        {
        case 0x20:
            if (DAT_011da3b8.Bool()->b && Interface::GetPipboyManagerInstance()->GetByteAtOffsetB9())
            {
                DAT_011da368->m_uiMapMarkerCount = 0;
                for (i = 0; i < 25; i++)
                    FUN_0079ffb0(false);
            }
        case 0x21:
            if (!FUN_004b71d0())
            {
                fhighlightX = FUN_004b7210()->FUN_007697f0() - ((A7d*)menu->m_pTiles[6]->GetParent())->GetTotalFloat();
                fhighlightY =
                    FUN_004b7210()->GetScaledValue() - ((C7d*)menu->m_pTiles[6]->GetParent())->GetAccumulatedFloat();
                if (fhighlightX < _gModifierZero || fhighlightY < _gModifierZero || fhighlightX > DAT_01074f68 ||
                    fhighlightY > 500.0)
                {
                    FUN_004b7210()->GetParent()->Set(0xfa9, 255.0f, true);
                }
                else
                {
                    FUN_004b7210()->GetParent()->Set(0xfa9, 0.0f, true);
                    if (g_osGlobals->FUN_00877720()->FUN_00a23a50(1, 1) &&
                        !g_osGlobals->FUN_00877720()->FUN_00a24660(0xe, 1))
                        menu->HandleSelection(0xc, 0);
                }
                fhighlightX -= menu->m_pTiles[6]->GetFloat(0xfb1) / 2.0;
                fhighlightY -= menu->m_pTiles[6]->GetFloat(0xfb0) / 2.0;
                menu->m_pTiles[6]->Set(0xfa1, fhighlightX, true);
                menu->m_pTiles[6]->Set(0xfa2, fhighlightY, true);
                menu->UpdateMapHighlight();
            }
            break;
        case 0x23:
            if (menu->m_uiMapState)
            {
                if (g_timeGlobal.GetTimeStamp() - menu->m_uiMapState >= DAT_011d47bc.Float()->f * 1000.0)
                {
                    pcurrNote = menu->m_pSelectedNote;
                    pcurrTile = 0;
                    if (FUN_004b71d0() || !menu->m_pSelectedNote)
                        pcurrNote = menu->m_kNoteListBox.GetSelectedData();
                    pcurrTile = menu->m_kNoteListBox.GetTileForData(pcurrNote);
                    if (pcurrNote && pcurrTile)
                    {
                        pcurrTile->Set(DAT_011da344, 128.0f, true);
                        ((NoteReadState*)pcurrNote)->SetRead(true);
                        menu->m_uiMapState = 0;
                    }
                }
            }
            break;
        case 0x24:
            if (FUN_00798440())
                UpdateWaveAnimation(menu);
            else
                menu->FUN_0079c090();
            break;
        }
        DAT_011da408 = false;
    }
    else if (!DAT_011da408 && !FUN_004b71d0() && menu->m_iMapDisplayMode <= 0x21)
    {
        FUN_004b7210()->GetParent()->Set(0xfa9, 255.0f, true);
        DAT_011da408 = true;
    }

    if (menu->m_bMapListUpdatePending || menu->m_pkActiveSoundList)
        UpdateHolotapePlayback(menu);
}

struct FUN_007240c0
{
    FUN_007240c0();
    virtual void vfn();
};
struct SL
{
    SL();
    ~SL();
    int a, b;
};
void __cdecl AddToHeadList(void*);
struct FUN_007a1c90 : public FUN_007240c0, public SL
{
    int f0c, f10, f14, f18;
    short f1c;
    float f20, f24, f28;
    short f2c;
    FUN_007a1c90();
    virtual void vfn();
};
// Zeroes the list box fields, clears the selected tile, and calls AddToHeadList on this.
// @fnv 0x007a1c90
FUN_007a1c90::FUN_007a1c90()
{
    f14 = 0;
    f10 = 0;
    f0c = 0;
    f18 = 0;
    f2c = 0;
    f1c = 0;
    f28 = 0.0f;
    f24 = 0.0f;
    f20 = 0.0f;
    reinterpret_cast<ListBox<TESQuest*>*>(this)->SetSelectedTile(0, true);
    AddToHeadList(this);
}

extern bool DAT_011da36d;
extern int DAT_011da344;
extern int DAT_011da348;
extern int DAT_011da360;
extern SettingT_GameSettingCollection_* DAT_011a03e4[];
extern SettingT_GameSettingCollection_ g_011d33a8;
extern SettingT_GameSettingCollection_ g_011d34f8;
extern SettingT_GameSettingCollection_ g_011d3684;
extern SettingT_GameSettingCollection_ g_011d3a2c;
extern SettingT_GameSettingCollection_ g_011d4438;
extern SettingT_GameSettingCollection_ g_011d48e8;
extern SettingT_GameSettingCollection_ g_011d4960;
extern SettingT_GameSettingCollection_ g_011d4a38;
extern SettingT_GameSettingCollection_ g_011d4f54;
extern SettingT_GameSettingCollection_ g_011db37c;
extern SettingT_GameSettingCollection_ g_011db458;
extern PlayerCharacter* g_thePlayer;
int sprintf_s(char*, unsigned int, const char*, ...);
int _stricmp(const char*, const char*);
void FUN_00832240(TESObjectREFR*, bool);
bool FUN_0079b390(BGSNote*);
bool FUN_0079b720(TESChallenge*);
void FUN_0079be80(Tile*, TESObjectREFR*);
void FUN_00798840();
void FUN_00798710();

struct FUN_0053d280_shell
{
    NiPoint3 FUN_0053d280(float) const;
};
struct FUN_0083b9a0_shell
{
    void FUN_0083b9a0();
};
struct FUN_007a19a0_shell
{
    void FUN_007a19a0(const SoundPlaybackHandle&);
};
struct FUN_007a1ac0_shell
{
    void FUN_007a1ac0(BSStringT<char>&);
};
struct FUN_007a2e30_shell
{
    void ApplyNoteFilter(bool (*)(BGSNote*));
};
struct FUN_007a5730_shell
{
    void FUN_007a5730(bool (*)(TESChallenge*));
};

struct MapMenuClick : public MapMenu
{
    void FUN_00796fd0(int, Tile*);
};

// @fnv 0x00796fd0
void MapMenuClick::FUN_00796fd0(int aiID, Tile* apTarget)
{
    if (apTarget == 0 && aiID >= 0 && aiID < 22)
        apTarget = m_pTiles[aiID];

    switch (aiID)
    {
    case 23:
        if (m_kQuestListBox.GetSelectedData() && !m_kQuestListBox.GetSelectedData()->GetCompleted())
        {
            g_thePlayer->FUN_009529d0(m_kQuestListBox.GetSelectedData());
            Interface::PlayUISound(3);
            UpdateSelectedQuestMarkers();
        }
        break;
    case 24:
        if (!DAT_011da36d)
        {
            SoundPlaybackHandle hsndHandle;
            BGSNote* pnote = m_kNoteListBox.GetSelectedData(apTarget);
            bool bisSoundNote = pnote->GetNoteType() == 0 || pnote->GetNoteType() == 3;
            if (pnote && (!FUN_004b71d0() || bisSoundNote))
            {
                bool bnoteMatch = pnote == m_pSelectedNote;
                Tile* poldSelectedTile;
                bool bsoundStopped = false;
                poldSelectedTile = m_kNoteListBox.GetTileForData(m_pSelectedNote);
                if (poldSelectedTile)
                    poldSelectedTile->Set(DAT_011da348, 0);
                if (!bnoteMatch || (bisSoundNote && !m_pkActiveSoundList))
                {
                    SelectNote(pnote);
                    apTarget->Set(DAT_011da348, 1);
                    m_pSelectedNote = pnote;
                    m_pTiles[13]->Set(0x1004, 1);
                }
                else
                {
                    m_pSelectedNote = 0;
                    m_pTiles[13]->Set(0x1004, 0);
                }
                if (m_pkActiveSoundList)
                {
                    RefreshMapData();
                    bsoundStopped = true;
                }
                if (bisSoundNote && !pnote->GetUnk7d())
                {
                    apTarget->Set(DAT_011da344, 128.0f, true);
                    pnote->SetSoundNotePlayed(true);
                }
                if (bisSoundNote && (!bnoteMatch || !bsoundStopped))
                {
                    if (pnote->GetNoteType() == 0 && pnote->FUN_005e9100())
                    {
                        ((FUN_007a19a0_shell*)&m_kSoundList)
                            ->FUN_007a19a0(BSAudio::GetSingleton()->GetSoundHandleByFormID(
                                pnote->FUN_005e9100()->GetFormID(), 0x101));
                        m_bMapListUpdatePending = true;
                    }
                    else if (pnote->GetNoteType() == 3 && pnote->FUN_005e9240() && pnote->FUN_005e92a0())
                    {
                        Character* pVoiceNoteNPC = new Character(false);
                        pVoiceNoteNPC->NotifySaveLoadGameOfFormChange();
                        Conversation* pVoiceNoteConvo = 0;
                        pVoiceNoteNPC->ClearReferenceState(pnote->FUN_005e92a0());
                        pVoiceNoteConvo = new Conversation(pVoiceNoteNPC, g_thePlayer, pnote->FUN_005e9240());
                        ((FUN_0083b9a0_shell*)pVoiceNoteConvo)->FUN_0083b9a0();
                        if (pVoiceNoteConvo->GetCurrentItem() &&
                            pVoiceNoteConvo->GetCurrentItem()->SelectDefaultResponseList())
                        {
                            do
                            {
                                ((FUN_007a1ac0_shell*)&SubtitlesToShow)
                                    ->FUN_007a1ac0(
                                        pVoiceNoteConvo->GetCurrentItem()->GetActiveResponse()->GetDialogueText());
                                pVoiceNoteConvo->GetCurrentItem()->GetInfo()->RunResultScript(0, pVoiceNoteNPC);
                                hsndHandle = BSAudio::GetSingleton()->GetSoundHandleByFilePath(
                                    *pVoiceNoteConvo->GetCurrentItem()->GetActiveResponse()->GetVoiceFilePath(), 0x105,
                                    0);
                                hsndHandle.SetVolume(0.9f);
                                ((FUN_007a19a0_shell*)&m_kSoundList)->FUN_007a19a0(hsndHandle);
                                pVoiceNoteConvo->GetCurrentItem()->GetInfo()->RunResultScript(1, pVoiceNoteNPC);
                                m_bMapListUpdatePending = true;
                            } while (pVoiceNoteConvo->GetCurrentItem()->NextResponse());
                        }
                        delete pVoiceNoteConvo;
                        delete pVoiceNoteNPC;
                    }
                    if (m_bMapListUpdatePending)
                    {
                        BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPipBoyHolotapeStart", 0x121).Play(false);
                        BSAudio::EnableAudio();
                        BSAudio::GetSingleton()->FUN_00ad85a0();
                    }
                }
            }
        }
        break;
    case 25: {
        Tile* pcurrTile = m_kMapMarkerListBox.GetSelectedTile();
        if (pcurrTile->GetFloat(DAT_011da344) == 255.0)
        {
            bool bunselected = !pcurrTile->ContainsTrait(DAT_011da348);
            FUN_0079c090();
            m_kMapMarkerListBox.Traverse(FUN_0079be80, 0, 0x7fffffff);
            if (FUN_00798440())
                FalloutRadio::SetRadioEnabled(false);
            if (bunselected)
            {
                FalloutRadio::SetRadioEnabled(true);
                FUN_00832240(m_kMapMarkerListBox.GetSelectedData(), false);
                pcurrTile->Set(DAT_011da348, 1);
            }
            UpdateSelectedQuestMarkers();
        }
    }
    break;
        break;
    case 18:
        if (m_iMapDisplayMode == 0x23)
            SetMapDisplayMode(true);
        break;
    case 12:
        switch (m_iMapDisplayMode)
        {
        case 0x23:
            if (!DAT_011da36d)
            {
                m_bMapMenuActive = !m_bMapMenuActive;
                ((FUN_007a2e30_shell*)&m_kNoteListBox)->ApplyNoteFilter(FUN_0079b390);
                m_pTiles[13]->Set(0xfa3, 0);
                m_pTiles[12]->Set(Tile::GetTraitID("_ShowingAllNotes"), m_bMapMenuActive);
            }
            else
            {
                if (++DAT_011da36e > 2)
                    DAT_011da36e = 0;
                ((FUN_007a5730_shell*)&m_kChallengeListBox)->FUN_007a5730(FUN_0079b720);
                m_pTiles[21]->Set(0xfc4, DAT_011a03e4[DAT_011da36e]->String(), true);
                m_pTiles[20]->Set(0xfa3, 0);
                m_pTiles[13]->Set(0xfa3, 0);
            }
            break;
        case 0x20:
        case 0x21:
            if (m_pMapTile)
            {
                if (FUN_004b71d0())
                {
                    m_kPlayerWorldPosition =
                        NiPoint3(m_pMapTile->GetParent()->GetFloat(0xfb1) / 2.0 - m_pMapTile->GetFloat(0xfa1),
                                 m_pMapTile->GetParent()->GetFloat(0xfb0) / 2.0 - m_pMapTile->GetFloat(0xfa2), 0.0f);
                }
                else
                {
                    m_kPlayerWorldPosition =
                        NiPoint3(FUN_004b7210()->FUN_007697f0(), FUN_004b7210()->GetScaledValue(), 0.0f);
                    m_kPlayerWorldPosition.x -= m_pMapTile->GetScreenX();
                    m_kPlayerWorldPosition.y -= m_pMapTile->GetScreenY();
                }
                if (m_iMapDisplayMode == 0x20)
                {
                    m_pCurrentMapSpace = m_pCurrentMapForm;
                    m_kPlayerWorldPosition = MapToWorldPosition(
                        ((const FUN_0053d280_shell*)&m_kPlayerWorldPosition)->FUN_0053d280(m_pMapTile->GetFloat(0xfb1)),
                        m_pCurrentMapSpace->GetFormType() == kWorldSpace ? (TESWorldSpace*)m_pCurrentMapSpace : 0);
                    m_kPlayerWorldPosition = m_kPlayerWorldPosition;
                }
                else
                {
                    m_kPlayerWorldPosition = MapToWorldPosition(
                        ((const FUN_0053d280_shell*)&m_kPlayerWorldPosition)->FUN_0053d280(m_pMapTile->GetFloat(0xfb1)),
                        0);
                    m_pCurrentMapSpace = FUN_007984d0(m_kPlayerWorldPosition);
                    if (m_pCurrentMapSpace)
                        ((TESWorldSpace*)m_pCurrentMapSpace)->GetCellAtPosition(m_kPlayerWorldPosition, true);
                }
                if (pAdjustNorthRotationCell)
                    pAdjustNorthRotationCell->FUN_00555b10(m_kPlayerWorldPosition, m_kPlayerWorldPosition, false);
                m_pTiles[6]->Set(0xfa3, 0);
                BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPopUpMapMarkerAdded ", 0x121).Play(false);
                if (g_thePlayer->FUN_00798400())
                    Interface::ShowButtonDialog(g_011d4438.String(), 0, 0, FUN_00798840, 0, 0x17, 0.0f, 0.0f,
                                                g_011d4960.String(), g_011d33a8.String(), g_011d4f54.String(), 0);
                else
                    Interface::ShowButtonDialog(g_011d3a2c.String(), 0, 0, FUN_00798840, 3, 0x17, 0.0f, 0.0f,
                                                g_011d34f8.String(), g_011d3684.String(), 0);
            }
            break;
        case 0x22:
            if (m_pSelectedMapMarkerInfo)
            {
                HandleSelection(0x21, 0);
                TESObjectREFR* ptargetRef = GetTeleportDestination(m_pSelectedMapMarkerInfo->GetReference(true),
                                                                   m_pSelectedMapMarkerInfo->GetTeleportPath());
                if (ptargetRef && m_pMapTile)
                {
                    NiPoint3 centerPoint = WorldToMapPosition(*ptargetRef->GetPos(), ptargetRef->GetParentWorldSpace());
                    m_pMapTile->Set(0xfa1,
                                    m_pMapTile->GetParent()->GetFloat(0xfb1) / 2.0 -
                                        m_pMapTile->GetFloat(0xfb1) * centerPoint.x,
                                    false);
                    m_pMapTile->Set(0xfa2,
                                    m_pMapTile->GetParent()->GetFloat(0xfb0) / 2.0 -
                                        m_pMapTile->GetFloat(0xfb0) * centerPoint.y,
                                    false);
                }
            }
            break;
        }
        break;
    case 26:
        if (m_iMapDisplayMode == 0x21 &&
            (FUN_004b71d0() || (m_pMapTile && m_kMapOffset.x == m_pMapTile->GetFloat(0xfa1) &&
                                m_kMapOffset.y == m_pMapTile->GetFloat(0xfa2))) &&
            m_pTiles[11]->ContainsTrait(0xfaf) && g_thePlayer->IsFastTravelAllowed())
        {
            int imarkerCt = 0;
            BSSimpleList<TESObjectREFR*>* pcurrMarker;
            for (pcurrMarker = &m_kMapMarkerList; pcurrMarker && pcurrMarker->GetItem() &&
                                                  imarkerCt <= apTarget->GetFloat(GetTileValueID("_MarkerIndex", -1));
                 pcurrMarker = pcurrMarker->GetNext())
            {
                m_pSecondMapReference = pcurrMarker->GetItem();
                imarkerCt++;
            }
            if (m_pSecondMapReference->GetMapMarkerData()->IsTravelLocation())
            {
                char strtemp[256];
                HandleMouseDown(aiID, apTarget);
                sprintf_s(strtemp, 256, "%s %s?", g_011d4a38.String(),
                          m_pSecondMapReference->GetMapMarkerData()->GetMapLabel());
                m_pTiles[6]->Set(0xfa3, 0);
                Interface::ShowButtonDialog(strtemp, 0, 0, FUN_00798710, 0, 0x17, 0.0f, 0.0f, g_011d34f8.String(),
                                            g_011d3684.String(), 0);
            }
            else
            {
                m_pSecondMapReference = 0;
            }
        }
        else if (m_iMapDisplayMode == 0x21 && !m_pTiles[11]->ContainsTrait(0xfaf) &&
                 _stricmp(apTarget->GetString(GetTileValueID("_LocationName", -1)), "Companion"))
        {
            Interface::ShowMessage(g_011d48e8.String(), 2, 0, 0, 2.0f, false);
        }
        break;
    case 2:
    case 4:
        if (m_pSelectedMarkerTile)
            HandleSelection(0x1a, m_pSelectedMarkerTile);
        break;
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        m_pTiles[17]->Set(DAT_011da360, aiID - 0x20);
        m_iMapDisplayMode = aiID;
        ((Interface*)FUN_004b7210())
            ->GetPipboyManager()
            ->StartBurst(g_011db458.Float()->f, g_011db37c.Float()->f, 0.5f);
        if (!FUN_00709d40() && aiID != 0x20 && aiID != 0x21)
            FUN_004b7210()->GetParent()->Set(0xfa9, 255.0f, true);
        m_pTiles[13]->Set(0xfa3, 0);
        m_pTiles[12]->Set(0xfaf, 1);
        MenuDepthController();
        if (((Interface*)FUN_004b7210())->GetPipboyManager()->IsUnk28Set())
            FUN_0079c340(true);
        break;
    }
}

extern bool DAT_011dd434;

// @fnv 0x00798440
bool FUN_00798440()
{
    return DAT_011dd434;
}

extern MapMenu* DAT_011da368;

// If the global MapMenu exists and its field at offset 0x90 equals a1, resets that field to 0.
// @fnv 0x0079b430
void __cdecl FUN_0079b430(int aiValue)
{
    if (DAT_011da368 && *(int*)((char*)DAT_011da368 + 0x90) == aiValue)
    {
        *(int*)((char*)DAT_011da368 + 0x90) = 0;
    }
}

extern int DAT_011da348;

// @fnv 0x0079be80
void FUN_0079be80(Tile* pThis)
{
    pThis->Set(DAT_011da348, 0);
}

extern "C" unsigned int DAT_011dd42c;

// @fnv 0x0079c070
unsigned int __cdecl FUN_0079c070()
{
    return DAT_011dd42c;
}

extern BSSimpleList<unsigned int> DAT_011dd59c;

// @fnv 0x0079c080
BSSimpleList<unsigned int>* __cdecl FUN_0079c080()
{
    return &DAT_011dd59c;
}

extern int DAT_011da35c;
extern MapMenu* DAT_011da368;

// Returns the float setting at DAT_011da35c from DAT_011da368's tile, or 1.0f when DAT_011da368 is null.
// @fnv 0x007a17a0
float __cdecl GetMapMenuFloatSetting()
{
    float result;
    if (DAT_011da368)
        result = ((Tile*)*(void**)((void**)DAT_011da368 + 0x30 / 4))->GetFloat(DAT_011da35c);
    else
        result = 1.0f;
    return result;
}

struct FUN_00798420_shell
{
    char bUnk7d;
    char GetUnk7d();
};

// @fnv 0x00798420
char FUN_00798420_shell::GetUnk7d()
{
    return ((char*)this)[0x7d];
}

extern float DAT_01074f70;
extern float DAT_01074f74;

struct FUN_0079a610_shell
{
    void* fields[16];
    void* m_tile;
    void UpdateControllerTiles(bool abHas360Controller);
};

// When a 360 controller is present, sets tiles 0xFA1 and 0xFA2 on m_tile to the two global float values.
// @fnv 0x0079a610
void FUN_0079a610_shell::UpdateControllerTiles(bool abHas360Controller)
{
    if (abHas360Controller)
    {
        reinterpret_cast<Tile*>(m_tile)->Set(0xFA1, DAT_01074f74, true);
        reinterpret_cast<Tile*>(m_tile)->Set(0xFA2, DAT_01074f70, true);
    }
}

struct FUN_0079bc30_shell
{
    void* GetOffset6BC();
};

// @fnv 0x0079bc30
void* FUN_0079bc30_shell::GetOffset6BC()
{
    return reinterpret_cast<char*>(this) + 0x6BC;
}

struct FUN_0079f620_shell
{
    void* GetOffsetPointer();
};

// @fnv 0x0079f620
void* FUN_0079f620_shell::GetOffsetPointer()
{
    return reinterpret_cast<char*>(this) + 0x6F8;
}

struct FUN_00796a50_shell
{
    void FUN_00796a80();
    void* FUN_00796a50(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00796a80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00796a50
void* FUN_00796a50_shell::FUN_00796a50(unsigned int flags)
{
    FUN_00796a80();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Unk00796f90
{
    char _pad[0x28];
    int _arr[0x16];
    bool HasNoZeroEntries();
};
// Returns false if any of the 0x16 ints in _arr is zero, otherwise returns true.
// @fnv 0x00796f90
bool Unk00796f90::HasNoZeroEntries()
{
    int i;
    for (i = 0; i < 0x16; ++i)
    {
        if (_arr[i] == 0)
            return false;
    }
    return true;
}

extern double const DAT_0106e7f8;
int __cdecl FUN_004dc200();
struct S
{
    float GetScaledValue();
};
// Returns the float at offset 0x4B0 multiplied by DAT_0106e7f8 and divided by the result of FUN_004dc200().
// @fnv 0x007983c0
float S::GetScaledValue()
{
    return (float)(*(float*)((char*)this + 0x4B0) * DAT_0106e7f8 / FUN_004dc200());
}

struct FUN_00798480_This
{
    void FUN_00798480(int aiID, Tile* apTarget);
};
// For ID 4, reads floats 4001 and 4002 from the Tile at offset 0x38 and stores them at offsets 0x120 and 0x124.
// @fnv 0x00798480
void FUN_00798480_This::FUN_00798480(int aiID, Tile* apTarget)
{
    if (aiID == 4)
    {
        *(float*)((char*)this + 0x120) = (*(Tile**)((char*)this + 0x38))->GetFloat(4001);
        *(float*)((char*)this + 0x124) = (*(Tile**)((char*)this + 0x38))->GetFloat(4002);
    }
}

struct MagicTarget;
struct MagicCaster_shell
{
    MagicTarget* FUN_0044edb0();
};
// Returns true if a1 is non-null and the MagicTarget at DAT_011da368+0xCC differs from a1's FUN_0044edb0() result.
// @fnv 0x0079bc50
bool FUN_0079bc50(MagicCaster_shell* pMagicCaster)
{
    return pMagicCaster && *(MagicTarget**)((char*)DAT_011da368 + 0xCC) != pMagicCaster->FUN_0044edb0();
}

struct RefH
{
    bool GetDisabled();
};
void* __fastcall _FNV_GetObjectReference(RefH*);
bool __cdecl IsRadioStationTalkingActivator(void*, int);
// Returns true if p is null, disabled, or its object reference passes IsRadioStationTalkingActivator with 0.
// @fnv 0x0079be30
bool FUN_0079be30(RefH* apRef)
{
    return apRef == 0 || apRef->GetDisabled() || IsRadioStationTalkingActivator(_FNV_GetObjectReference(apRef), 0);
}

struct Helper007fa0f0
{
    void SetValue(int, bool);
};
// If DAT_011da368 is set, calls SetValue on the PipboyManager with the value at DAT_011da368+0x80 minus 0x20 and a.
// @fnv 0x0079c340
void FUN_0079c340(bool a)
{
    if (DAT_011da368)
        ((Helper007fa0f0*)((Interface*)FUN_004b7210())->GetPipboyManager())
            ->SetValue(*(int*)((char*)DAT_011da368 + 0x80) - 0x20, a);
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011c63cc;
struct DAT_011da368_tag
{
    char _pad[0x128];
    unsigned int f;
};
extern DAT_011da368_tag* _DAT_011da368;
// @fnv 0x007a1750
bool FUN_007a1750()
{
    return _DAT_011da368 != 0 && _DAT_011da368->f < *g_011c63cc.Int() * *g_011c63cc.Int();
}

namespace fnv_007a17e0 {
struct S011da368
{
    char pad[56];
    Tile* tile;
};
extern S011da368* _DAT_011da368;
// Returns the tile's float value for DAT_011da35c when _DAT_011da368 is set, otherwise returns 1.0f.
// @fnv 0x007a17e0
float GetTileFloatOrDefault()
{
    float fValue;
    if (_DAT_011da368)
        fValue = _DAT_011da368->tile->GetFloat(DAT_011da35c);
    else
        fValue = 1.0f;
    return fValue;
}
}  // namespace fnv_007a17e0

struct FUN_007a5a30_Host
{
    char _pad[12];
    Tile* tileAtC;
    void FUN_007a5a30(bool);
};
// Calls Set on tileAtC with value 0xFA3 and the given bool.
// @fnv 0x007a5a30
void FUN_007a5a30_Host::FUN_007a5a30(bool a1)
{
    tileAtC->Set(0xFA3, a1);
}

struct S007a6280
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5(int);
    int FUN_007a7830(int);
    unsigned int FUN_007a6280();
};
// Returns v5 called with the result of FUN_007a7830(0) minus one.
// @fnv 0x007a6280
unsigned int S007a6280::FUN_007a6280()
{
    return v5(FUN_007a7830(0) - 1);
}

struct FUN_007312e0_shell : Tile
{
    void FUN_007312e0();
};

// @fnv 0x007312e0
void FUN_007312e0_shell::FUN_007312e0()
{
    *(float*)((char*)this + 0x24) = *(TileListBoxCalls**)((char*)this + 0x10)
                                        ? ((TileListBoxCalls**)((char*)this + 0x10))[0]->GetFloat(0xfac)
                                        : -1.0f;
    *(float*)((char*)this + 0x28) =
        *(TileListBoxCalls**)((char*)this + 0x14)
            ? ((TileListBoxCalls**)((char*)this + 0x14))[0]->GetFloat(Tile::GetTraitID("_current_value"))
            : -1.0f;
}

struct FUN_0079b800_shell
{
    bool IsFlagSet();
};

// @fnv 0x0079b800
bool FUN_0079b800_shell::IsFlagSet()
{
    return *(const unsigned short*)((const char*)this + 0x5c) & 4;
}

extern int DAT_01075530;

struct FUN_007a1aa0_shell : public BSSimpleArray<BSStringT<char>, 1024>
{
    void FUN_007a1aa0();
};

// @fnv 0x007a1aa0
void FUN_007a1aa0_shell::FUN_007a1aa0()
{
    *reinterpret_cast<int**>(this) = &DAT_01075530;
    Clear(true);
}

struct VATSMenu
{
    int GetSelectedTargetIndex();
    int FUN_007a7830();
    void* fields[13];
};
extern int DAT_011da4a8;
extern int DAT_011da4ac;
extern const char $SG7947[];
// @fnv 0x007a7830
int VATSMenu::FUN_007a7830()
{
    static int numFiltered = GetTileValueID($SG7947, -1);
    return GetSelectedTargetIndex() - (unsigned int)((Tile*)fields[3])->GetFloat(numFiltered);
}

namespace fnv_006f49c0 {
struct PathingPath
{
    void Clear();
    float CalculatePathDistance();
    void* __vecDelDtor(unsigned int);
    char Spaces[16];
    char Doors[16];
    NiPoint3 Start;
    NiPoint3 End;
};
typedef char _sizecheck_TeleportPath[sizeof(PathingPath) == 56 ? 1 : -1];
struct FUN_006f49c0_shell : public PathingPath
{
    float GetPathLength();
};

struct Pt
{
    float x, y, z;
    float Length() const;
};
struct NiPoint3Ex : Pt
{
    NiPoint3Ex operator-(const NiPoint3&) const;
};
struct DoorRef
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
    virtual const NiPoint3Ex* GetPos();
};
struct DoorEntry
{
    DoorRef* door;
    NiPoint3 pos;
};
struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct S006949d0
{
    DoorEntry* GetAt(int);
    DoorEntry* GetFirst();
    DoorEntry* FUN_006cedb0();
};

// @fnv 0x006f49c0
float FUN_006f49c0_shell::GetPathLength()
{
    float ftotalLength = 0.0f;
    unsigned int i;
    if (((ArrHelper*)Spaces)->FUN_0076b610())
        return -1.0f;
    if (((ArrHelper*)Doors)->FUN_0076b610())
        return (((const NiPoint3Ex&)End) - Start).Length();
    ftotalLength += (*((S006949d0*)Doors)->GetFirst()->door->GetPos() - Start).Length();
    for (i = 1; i < ((ArrSI*)Doors)->GetFlags(); i++)
        ftotalLength +=
            (*((S006949d0*)Doors)->GetAt(i)->door->GetPos() - ((S006949d0*)Doors)->GetAt(i - 1)->pos).Length();
    ftotalLength += (((const NiPoint3Ex&)End) - ((S006949d0*)Doors)->FUN_006cedb0()->pos).Length();
    return ftotalLength;
}
}  // namespace fnv_006f49c0

namespace fnv_00798a00 {
struct PlayerTargetLocation
{
    char data[0x34];
};
struct FUN_00456540_shell : public PlayerTargetLocation
{
    FUN_00456540_shell();
};
struct FUN_0093be30_shell
{
    void FUN_0093be30(PlayerTargetLocation*);
};
struct DAT_011da368_shell
{
    char data[0x118];
    PlayerTargetLocation* ms_pInventoryMenu;
};
extern DAT_011da368_shell* _DAT_011da368;
extern FUN_0093be30_shell* _g_thePlayer;
// @fnv 0x00798a00
void FUN_00798a00()
{
    if (_DAT_011da368 && _DAT_011da368->ms_pInventoryMenu)
    {
        FUN_00456540_shell* loc = new FUN_00456540_shell;
        *(PlayerTargetLocation**)(loc->data + 0x30) = _DAT_011da368->ms_pInventoryMenu;
        _g_thePlayer->FUN_0093be30(loc);
        _DAT_011da368->ms_pInventoryMenu = 0;
    }
}
}  // namespace fnv_00798a00

struct DialogMenuAudioCalls
{
    void DeactivateAudio();
};
struct BSAudioStatics
{
    static void DeactivateAudio();
};
struct FUN_00798ad0_shell : public MapMenu
{
    void StopHolotapeAudio();
};
// @fnv 0x00798ad0
void FUN_00798ad0_shell::StopHolotapeAudio()
{
    if (m_pkActiveSoundList && m_pkActiveSoundList->GetItem().IsPlaying())
        m_pkActiveSoundList->GetItem().Stop();
    m_kSoundList.RemoveAll();
    SubtitlesToShow.Clear(true);
    m_pkActiveSoundList = 0;
    m_fMapZoom = 0.0f;
    m_iMapSelectionIndex = 0;
    m_bMapListUpdatePending = false;
    BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPipBoyHolotapeStop", 0x121).Play(false);
    reinterpret_cast<DialogMenuAudioCalls*>(BSAudio::GetSingleton())->DeactivateAudio();
    BSAudioStatics::DeactivateAudio();
}

namespace fnv_0079b8e0 {
namespace S {
struct BSSimpleList
{
    BSSimpleList* GetNext();
    bool _ref_008256d0();
};
struct RegionObjectEntry
{
    int* GetReference();
};
struct BSAudio
{
    void* GetAudioBackendData();
};
}
struct BGSQuestObjective
{
    bool GetCompleted() const;
    bool GetDisplayed() const;
    const char* GetDisplayText();
};
struct FNStub
{
    void* GetFullName();
};
struct FUN_006317a0_struct
{
    int AddEight(int);
};
struct FUN_0079bc30_shell
{
    void* GetOffset6BC();
};
struct IMStandIn
{
    void FUN_00715860(int, int, int);
};
struct MagicCaster_shell;
struct InterfaceManager;
extern float DAT_01074ffc;
extern void* _g_thePlayer;
bool _FUN_004b71d0();
InterfaceManager* FUN_004b7210();
int __fastcall FUN_005cbb50(char*);
bool __cdecl FUN_0079bc50(MagicCaster_shell*);
bool __cdecl FUN_0079bc90(void*);
struct ListBoxS
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void V4();
    virtual void A5();
    virtual void A6();
    virtual void V7();
    virtual void V8(bool(__cdecl*)(void*));
    Tile* FUN_007a44e0(BGSQuestObjective*, const char*, int, int);
    Tile* InsertTileFromTemplate(TESQuest*, const char*, int, int);
    void FUN_007a2350(bool);
    void ApplyObjectiveFilter(bool(__cdecl*)(MagicCaster_shell*));
};
struct FUN_0079b8e0_shell
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void V4(int, Tile*);
    void UpdateQuestObjectiveList();
};

// @fnv 0x0079b8e0
void FUN_0079b8e0_shell::UpdateQuestObjectiveList()
{
    ((ListBoxS*)((char*)this + 0x130))->V7();
    ((ListBoxS*)((char*)this + 0x1c0))->V7();
    S::BSSimpleList* pobjectiveList;
    for (pobjectiveList = (S::BSSimpleList*)((FUN_0079bc30_shell*)_g_thePlayer)->GetOffset6BC();
         pobjectiveList && !pobjectiveList->_ref_008256d0(); pobjectiveList = pobjectiveList->GetNext())
    {
        TESQuest* pQuest =
            (TESQuest*)((S::BSAudio*)*((S::RegionObjectEntry*)pobjectiveList)->GetReference())->GetAudioBackendData();
        if (((BGSQuestObjective*)*((S::RegionObjectEntry*)pobjectiveList)->GetReference())->GetDisplayed())
        {
            Tile* pTile =
                ((ListBoxS*)((char*)this + 0x1c0))
                    ->FUN_007a44e0(
                        (BGSQuestObjective*)*((S::RegionObjectEntry*)pobjectiveList)->GetReference(),
                        ((BGSQuestObjective*)*((S::RegionObjectEntry*)pobjectiveList)->GetReference())->GetDisplayText(),
                        0, 0);
            (*(Tile**)((FUN_006317a0_struct*)((char*)pTile + 4))
                  ->AddEight((int)((S::BSSimpleList*)((char*)pTile + 4))->GetNext()))
                ->Set(0xfba, DAT_01074ffc, true);
            pTile->Set(Tile::GetTraitID("_ShowEmptyMarker"), 1);
            pTile->Set(Tile::GetTraitID("_enabled"), 0);
            if (((BGSQuestObjective*)*((S::RegionObjectEntry*)pobjectiveList)->GetReference())->GetCompleted())
            {
                pTile->Set(DAT_011da344, 128.0f, true);
                pTile->Set(DAT_011da348, 1);
            }
            else if (pQuest->GetCompleted())
            {
                pTile->Set(DAT_011da344, 128.0f, true);
            }
            else
            {
                pTile->Set(DAT_011da344, 255.0f, true);
            }
            if (!((ListBox<BGSNote*>*)((char*)this + 0x130))->GetTileForData((BGSNote*&)pQuest))
            {
                Tile* pTile = ((ListBoxS*)((char*)this + 0x130))
                                  ->InsertTileFromTemplate(
                                      pQuest, (const char*)((FNStub*)((char*)pQuest + 0x30))->GetFullName(), 0, 0);
                pTile->Set(0xfaa, 0x17);
                pTile->Set(DAT_011da344, pQuest->GetCompleted() ? 128.0f : 255.0f, true);
                if (pQuest == (TESQuest*)FUN_005cbb50((char*)_g_thePlayer))
                    pTile->Set(DAT_011da348, 1);
            }
        }
    }
    ((ListBoxS*)((char*)this + 0x1c0))->V8(FUN_0079bc90);
    ((ListBoxS*)((char*)this + 0x130))->V8(FUN_0079bc90);
    ((ListBoxS*)((char*)this + 0x130))->FUN_007a2350(true);
    if (FUN_005cbb50((char*)_g_thePlayer))
    {
        Tile* pactiveQuestTile;
        {
            BGSNote* pactive = (BGSNote*)FUN_005cbb50((char*)_g_thePlayer);
            pactiveQuestTile = ((ListBox<BGSNote*>*)((char*)this + 0x130))->GetTileForData(pactive);
        }
        V4(0x17, pactiveQuestTile);
        if (_FUN_004b71d0())
        {
            ((IMStandIn*)FUN_004b7210())->FUN_00715860((int)pactiveQuestTile, 0xfc3, 1);
            ((ListBoxS*)((char*)this + 0x130))->V4();
        }
    }
    else
    {
        ((ListBoxS*)((char*)this + 0x1c0))->ApplyObjectiveFilter(FUN_0079bc50);
    }
}
}  // namespace fnv_0079b8e0

struct FUN_004a0c90_shell
{
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    unsigned int field4;
    unsigned int field5;
    unsigned int field6;
    unsigned int field7;
    unsigned int field8;
    void FUN_004a0c90(float);
};

struct TESObjectCELL_Ext
{
    float FUN_00555ad0();
    void FUN_00555b10(NiPoint3 const& source, NiPoint3& destination, bool invert);
};

extern FUN_004a0c90_shell DAT_011a9448;
extern double _DAT_01012060;

NiPoint3 __cdecl FUN_004b3ae0(NiPoint3 const&, float const*);

// @fnv 0x00555b10
void TESObjectCELL_Ext::FUN_00555b10(NiPoint3 const& source, NiPoint3& destination, bool invert)
{
    FUN_004a0c90_shell shell;
    float f = this->FUN_00555ad0() * (invert ? -1.0f : 1.0f);

    if (f != 0.0)
    {
        shell = DAT_011a9448;
        shell.FUN_004a0c90(f);
        destination = FUN_004b3ae0(source, reinterpret_cast<float const*>(&shell));
    }
    else
    {
        destination = source;
    }
}

class TESReputation
{
  public:
    int GetReputationRank(int);
    const char* FUN_00616710();
};

extern SettingT_GameSettingCollection_ g_011cba0c;
extern SettingT_GameSettingCollection_ g_011cba88;
extern SettingT_GameSettingCollection_ g_011cbb04;
extern SettingT_GameSettingCollection_ g_011cbb2c;
extern SettingT_GameSettingCollection_ g_011cbb58;
extern SettingT_GameSettingCollection_ g_011cbbb0;
extern SettingT_GameSettingCollection_ g_011cbbd8;
extern SettingT_GameSettingCollection_ g_011cbbf0;
extern SettingT_GameSettingCollection_ g_011cbc08;
extern SettingT_GameSettingCollection_ g_011cbc40;
extern SettingT_GameSettingCollection_ g_011cbc60;
extern SettingT_GameSettingCollection_ g_011cbce4;
extern SettingT_GameSettingCollection_ g_011cbcfc;
extern SettingT_GameSettingCollection_ g_011cbd28;
extern SettingT_GameSettingCollection_ g_011cbd74;
extern SettingT_GameSettingCollection_ g_011cbd84;

// Looks up the positive and negative reputation indices and returns the title string from the 4x4 table of game settings.
// @fnv 0x00616710
const char* TESReputation::FUN_00616710()
{
    char cPosIndex;
    char cNegIndex;
    SettingT_GameSettingCollection_* pRepTitles[4][4] = {{&g_011cbce4, &g_011cbd28, &g_011cbbb0, &g_011cbc08},
                                                         {&g_011cbd74, &g_011cbbf0, &g_011cbc60, &g_011cbb2c},
                                                         {&g_011cbc40, &g_011cba88, &g_011cbb58, &g_011cbbd8},
                                                         {&g_011cbcfc, &g_011cbd84, &g_011cbb04, &g_011cba0c}};

    cPosIndex = 0;
    cNegIndex = 0;
    cPosIndex = this->GetReputationRank(1);
    cNegIndex = this->GetReputationRank(0);
    return pRepTitles[cNegIndex][cPosIndex]->String();
}

struct S006949d0
{
    void* GetAt(int);
    char pad[8];
    int count;  // +0x8
    void FUN_006cedb0();
};

// @fnv 0x006cedb0
void S006949d0::FUN_006cedb0()
{
    GetAt(count - 1);
}

namespace fnv_0079b460 {
struct FUN_007a59a0_Host
{
    void FUN_007a59a0(bool);
};

struct FUN_007a30e0_Host
{
    void FUN_007a30e0(bool);
};

struct FUN_007a5a30_Host
{
    void FUN_007a5a30(bool);
};

struct FUN_0079b460_shell : public MapMenu
{
    void FUN_0079b460(bool);
};

extern const char $SG3295[];
extern SettingT_GameSettingCollection_ g_011d2a78;
extern SettingT_GameSettingCollection_ g_011d2d18;
extern MapMenu* _DAT_011da368;
extern signed char DAT_011da36e;

// @fnv 0x0079b460
void FUN_0079b460_shell::FUN_0079b460(bool abToggle)
{
    Tile* pchallengeText;

    if (abToggle)
        DAT_011da36d = !DAT_011da36d;

    reinterpret_cast<FUN_007a59a0_Host*>(reinterpret_cast<char*>(this) + 0x1f0)->FUN_007a59a0(DAT_011da36d);
    reinterpret_cast<FUN_007a5a30_Host*>(reinterpret_cast<char*>(this) + 0x1f0)->FUN_007a5a30(DAT_011da36d);

    reinterpret_cast<FUN_007a30e0_Host*>(reinterpret_cast<char*>(this) + 0x160)->FUN_007a30e0(!DAT_011da36d);
    reinterpret_cast<FUN_007a5a30_Host*>(reinterpret_cast<char*>(this) + 0x160)->FUN_007a5a30(!DAT_011da36d);

    (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x5c))->Set(0xfa3, 1);

    if (abToggle)
    {
        pchallengeText =
            (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x5c))->GetNamedChild("MM_DataText");
        pchallengeText->Set(0xfc4, $SG3295, true);
    }

    if (DAT_011da36d)
    {
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(_DAT_011da368) + 0x70))
            ->Set(0xfc4, g_011d2d18.String(), true);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(_DAT_011da368) + 0x7c))->Set(0xfa3, 1);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x7c))
            ->Set(0xfc4, DAT_011a03e4[DAT_011da36e]->String(), true);
    }
    else
    {
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(_DAT_011da368) + 0x70))
            ->Set(0xfc4, g_011d2a78.String(), true);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(_DAT_011da368) + 0x58))->Set(0xfaf, 1);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(_DAT_011da368) + 0x7c))->Set(0xfa3, 0);
    }

    if (abToggle)
        UpdateSelectedQuestMarkers();
}
}  // namespace fnv_0079b460

namespace fnv_0079b720 {
struct TESChallenge
{
    int GetUnlocked();
    int GetChallengeType();
    TESObjectREFR* GetProgressValue();
};

struct FUN_0079b800_shell
{
    bool IsFlagSet();
};

struct FUN_005def70_Class
{
    int FUN_005def70();
};

extern int _DAT_011da368;
extern signed char DAT_011da36e;

// @fnv 0x0079b720
bool __cdecl FUN_0079b720(TESChallenge* challenge)
{
    bool result = true;
    {
        int challengeType;

        if (_DAT_011da368 != 0)
        {
            if (challenge->GetUnlocked() != 0)
                result = true;
        }

        challengeType = challenge->GetChallengeType();

        if ((int)challenge->GetProgressValue() <= 0)
        {
            if (!((FUN_0079b800_shell*)challenge)->IsFlagSet())
            {
                if (((FUN_005def70_Class*)challenge)->FUN_005def70() == 0)
                    return true;
            }
        }

        if (DAT_011da36e == 0)
        {
            if (challengeType == 2 || challengeType == 0 || challengeType == 1)
                return false;
        }

        if (DAT_011da36e == 1)
        {
            if (challengeType == 3 || challengeType == 8)
                return false;
        }

        if (DAT_011da36e == 2)
        {
            if (challengeType == 11 || challengeType == 10 || challengeType == 9 || challengeType == 6 ||
                challengeType == 5 || challengeType == 4 || challengeType == 12 || challengeType == 13)
                return false;
        }

        return result;
    }
}
}  // namespace fnv_0079b720

struct MobileObject
{
    const char* GetFullName();
};

struct FUN_0079bd70_data
{
    Tile* pTile;
    MobileObject* pMobileObject;
};

int __cdecl FUN_00408b20(char const*, char const*);

// @fnv 0x0079bd70
int __cdecl CompareMobileObjects(FUN_0079bd70_data* pFirst, FUN_0079bd70_data* pSecond)
{
    int result = 0;

    if (pFirst->pTile->GetFloat(DAT_011da344) == 255.0 && pFirst->pTile->GetFloat(DAT_011da344) != 255.0)
    {
        result = -1;
    }
    else if (pFirst->pTile->GetFloat(DAT_011da344) != 255.0 && pFirst->pTile->GetFloat(DAT_011da344) == 255.0)
    {
        result = 1;
    }
    else
    {
        result = FUN_00408b20(pFirst->pMobileObject->GetFullName(), pSecond->pMobileObject->GetFullName());
    }

    return result;
}

extern double DAT_01075008;
extern double DAT_01075010;

struct FUN_0079c380_shell : TESObjectREFR
{
    NiPoint3* GetMarkerPosition(NiPoint3* result, NiPoint3 position, TESWorldSpace* worldSpace);
};

// @fnv 0x0079c380
NiPoint3* FUN_0079c380_shell::GetMarkerPosition(NiPoint3* result, NiPoint3 position, TESWorldSpace* worldSpace)
{
    NiPoint3 markerPosition;

    if (worldSpace != 0 && *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x80) == 0x21)
    {
        worldSpace->GetCellAtPosition(position, false);
    }

    markerPosition.x = (position.x - *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xe8)) /
                       (*reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xf0) -
                        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xe8));

    markerPosition.y = (position.y - *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xec)) /
                       (*reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xf4) -
                        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xec));

    markerPosition.z = 0.0f;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x80) == 0x21)
    {
        markerPosition.x = markerPosition.x * DAT_01075010 + DAT_01075008;
        markerPosition.y = markerPosition.y * DAT_01075010 + DAT_01075008;
    }

    *result = markerPosition;
    return result;
}

struct FUN_007a86b0_Item
{
    char data[8];
};

struct FUN_007a63b0_holder
{
    void FUN_007a63b0(FUN_007a86b0_Item*, unsigned int);
};

struct FUN_006f3170_Class
{
    bool FUN_006f3170(void);
};

struct FUN_00869600_Class
{
    unsigned int FUN_00869600(void);
};

struct FUN_006c8a30_Class
{
    void FUN_006a8500(void);
};

struct FUN_00692480
{
    virtual void FUN_00692480_dummy(void);
    virtual FUN_007a86b0_Item* FUN_00692480_alloc(unsigned int);

    void Method(char*, char*, unsigned int);
};

struct FUN_007a1b10_shell
{
    virtual void FUN_007a1b10_dummy(void);
    virtual FUN_007a86b0_Item* FUN_007a1b10_alloc(unsigned int);

    FUN_007a86b0_Item* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void RemoveAt(unsigned int, bool);
};

// @fnv 0x007a1b10
void FUN_007a1b10_shell::RemoveAt(unsigned int aiIndex, bool abShrink)
{
    unsigned int inewSize;
    FUN_007a86b0_Item* pnewBuffer;

    if (abShrink && reinterpret_cast<FUN_006f3170_Class*>(this)->FUN_006f3170())
    {
        inewSize = reinterpret_cast<FUN_00869600_Class*>(this)->FUN_00869600();
        pnewBuffer = this->FUN_007a1b10_alloc(inewSize);

        reinterpret_cast<FUN_00692480*>(this)->Method(reinterpret_cast<char*>(pnewBuffer),
                                                      reinterpret_cast<char*>(this->pBuffer), aiIndex);

        reinterpret_cast<FUN_007a63b0_holder*>(this)->FUN_007a63b0(this->pBuffer + aiIndex, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(reinterpret_cast<char*>(pnewBuffer + aiIndex),
                                                      reinterpret_cast<char*>(this->pBuffer + aiIndex + 1),
                                                      this->iSize - 1);

        reinterpret_cast<FUN_006c8a30_Class*>(this)->FUN_006a8500();
        this->pBuffer = pnewBuffer;
        this->SimpleArrayStorage = inewSize;
    }
    else
    {
        reinterpret_cast<FUN_007a63b0_holder*>(this)->FUN_007a63b0(this->pBuffer + aiIndex, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(reinterpret_cast<char*>(this->pBuffer + aiIndex),
                                                      reinterpret_cast<char*>(this->pBuffer + aiIndex + 1),
                                                      this->iSize - aiIndex - 1);
    }

    this->iSize = this->iSize - 1;
}

struct FUN_007a4c50_shell
{
    void* fields[3];
    Tile* m_pListTile;
    void SetEnabledTrait(bool);
};

// Sets the _enabled trait on the Tile to abVal using the cached trait index.
// @fnv 0x007a4c50
void FUN_007a4c50_shell::SetEnabledTrait(bool abVal)
{
    static int enabledTrait = GetTileValueID("_enabled", -1);
    m_pListTile->Set(enabledTrait, abVal);
}

namespace fnv_007a6a50 {
class VATSMenu
{
  public:
    int GetSelectedTargetIndex();
};

class FUN_007a6a50_shell : public VATSMenu
{
  public:
    void* vptr;
    char padding[8];
    Tile* m_pListTile;

    unsigned int GetUnfilteredCount();
};

// @fnv 0x007a6a50
unsigned int FUN_007a6a50_shell::GetUnfilteredCount()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);

    return GetSelectedTargetIndex() - (unsigned int)m_pListTile->GetFloat(numFiltered);
}
}  // namespace fnv_007a6a50

struct FNVEmitter;
struct FNVLinkedNode
{
    FNVEmitter** FUN_006815c0();
    FNVLinkedNode* FUN_00726070();
};
struct FNVLinkedList
{
    FNVLinkedNode* FUN_00460140();
};
extern FNVLinkedList* DAT_011c3f2c;
struct FNVElement
{
    int data0;
    int data4;
    FNVElement();
};
struct FNVEmitter
{
    FNVEmitter* FUN_00586390(int type);
    void FUN_005884e0(FNVElement* element);
    FNVElement* GetOrCreateElement(bool createNew);
};

// Returns an existing element from the type-2 emitter when not creating new, otherwise allocates one, registers it, and propagates it to linked emitters.
// @fnv 0x005882a0
FNVElement* FNVEmitter::GetOrCreateElement(bool createNew)
{
    FNVElement* result = 0;
    if (FUN_00586390(2) && !createNew)
    {
        result = FUN_00586390(2)->GetOrCreateElement(false);
    }
    else
    {
        result = new FNVElement;
        FUN_005884e0(result);
        if (!createNew)
        {
            FNVLinkedNode* node = DAT_011c3f2c->FUN_00460140();
            while (node)
            {
                FNVEmitter* emitter = *node->FUN_006815c0();
                if (emitter && emitter->FUN_00586390(2) == this)
                {
                    emitter->FUN_005884e0(result);
                }
                node = node->FUN_00726070();
            }
        }
    }
    return result;
}

struct HandlerRegistration
{
    unsigned int id;
    unsigned int status;
    void* handler;
    HandlerRegistration* next;
    ~HandlerRegistration();
};
struct HandlerArgument
{
    unsigned int type;
    unsigned int data;
    unsigned int flags;
    HandlerArgument(int value);
    ~HandlerArgument();
};
struct QueueOwner
{
    unsigned int state;
    unsigned int capacity;
    unsigned int flags;
    HandlerRegistration* first;
    void __thiscall FUN_00418900(const HandlerArgument& argument);
    void __thiscall ClearQueue();
};
// Deletes every node in the linked list, nulling each node's next pointer, then calls FUN_00418900 with a HandlerArgument(0).
// @fnv 0x0076b7a0
void QueueOwner::ClearQueue()
{
    while (first != 0)
    {
        HandlerRegistration* next = first->next;
        first->next = 0;
        delete first;
        first = next;
    }
    FUN_00418900(HandlerArgument(0));
}

struct MenuBase0
{
    virtual ~MenuBase0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct Snd98
{
    ~Snd98();
    int a0;
    int a4;
    int a8;
    int ac;
};
struct SubA8
{
    ~SubA8();
    int a0;
    int a4;
    int a8;
    int ac;
};
struct RefList
{
    ~RefList();
    int a0;
    int a4;
};
struct LB130
{
    ~LB130();
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
struct LB160
{
    ~LB160();
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
struct LB190
{
    ~LB190();
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
struct LB1C0
{
    ~LB1C0();
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
struct LB1F0
{
    ~LB1F0();
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
struct Dbg220
{
    ~Dbg220();
    int a0;
    int a4;
    int a8;
    int ac;
};
struct FUN_00796a80 : MenuBase0
{
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
    Snd98 m98;
    SubA8 mA8;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    RefList mD8;
    RefList mE0;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    LB130 m130;
    LB160 m160;
    LB190 m190;
    LB1C0 m1C0;
    LB1F0 m1F0;
    Dbg220 m220;
    virtual ~FUN_00796a80();
};

// Clears the global DAT_011da368 to zero when this menu object is destroyed.
// @fnv 0x00796a80
FUN_00796a80::~FUN_00796a80()
{
    DAT_011da368 = 0;
}

class B799100SpellList
{
  public:
    bool FUN_00680c30(void* pvSpell);
};

class B799100ActiveEffect
{
  public:
    void* GetSpell(int iUnk1, int iUnk2);
    B799100SpellList* GetSpellList();
};

class B799100EffectNode
{
  public:
    B799100ActiveEffect** GetItem();
    B799100EffectNode* GetNext();
};

class B799100MagicTarget
{
  public:
    bool FUN_005a5dc0();
    B799100EffectNode* GetActiveEffectList();
};

class B799100State
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    B799100ActiveEffect* m_pkFoundEffect;
};

extern B799100State* g_pkB799100State;

// @fnv 0x00799100
void __cdecl FUN_00799100(void* pvUnused, B799100MagicTarget* pkTarget)
{
    if (!g_pkB799100State->m_pkFoundEffect && pkTarget && !pkTarget->FUN_005a5dc0())
    {
        for (B799100EffectNode* pkIter = pkTarget->GetActiveEffectList();
             !g_pkB799100State->m_pkFoundEffect && pkIter && *pkIter->GetItem(); pkIter = pkIter->GetNext())
        {
            B799100ActiveEffect* pkEffect = *pkIter->GetItem();
            if (pkEffect->GetSpellList()->FUN_00680c30(pkEffect->GetSpell(0, 0)))
                g_pkB799100State->m_pkFoundEffect = pkEffect;
        }
    }
}

class B79B820Tile
{
  public:
    float GetFloat(int m_iValueId);
};

class B79B820SoundFile
{
  public:
    const char* GetSoundFile() const;
};

struct B79B820Form
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B79B820SoundFile m_kSoundFile;
};

struct B79B820Item
{
    B79B820Tile* m_pkTile;
    B79B820Form* m_pkForm;
};

extern int g_iB79B820ValueTrait;

int __cdecl FUN_00408b20(const char* pcA, const char* pcB);

// Compares two items by a tile float value (128/255 ordering) or, otherwise, by their sound file names via FUN_00408b20.
// @fnv 0x0079b820
int __cdecl CompareItems(B79B820Item* pkA, B79B820Item* pkB)
{
    int iResult = 0;
    float fA5 = pkA->m_pkTile->GetFloat(g_iB79B820ValueTrait);
    float fB5 = pkB->m_pkTile->GetFloat(g_iB79B820ValueTrait);
    if (fA5 == 128.0 && fB5 == 255.0)
        iResult = 1;
    else if (fA5 == 255.0 && fB5 == 128.0)
        iResult = -1;
    else
        iResult = FUN_00408b20(pkA->m_pkForm->m_kSoundFile.GetSoundFile(), pkB->m_pkForm->m_kSoundFile.GetSoundFile());
    return iResult;
}

class FUN_00a011b0_owner_b9258
{
  public:
    float FUN_00a011b0(int);
};

extern double DAT_0102e430;
extern double DAT_0101e568;

// Compares two objects by a value at DAT_011da344, falling back to the value at 0xfac, returning -1, 0 or 1.
// @fnv 0x0079bc90
int __cdecl FUN_0079bc90(FUN_00a011b0_owner_b9258** apFirst, FUN_00a011b0_owner_b9258** apSecond)
{
    int result2 = 0;
    float f3 = (*apFirst)->FUN_00a011b0(DAT_011da344);
    float f2 = (*apSecond)->FUN_00a011b0(DAT_011da344);
    if (f3 == DAT_0102e430 && f2 == DAT_0101e568)
    {
        result2 = 1;
    }
    else if (f3 == DAT_0101e568 && f2 == DAT_0102e430)
    {
        result2 = -1;
    }
    else
    {
        float g1 = (*apFirst)->FUN_00a011b0(0xfac);
        float g3 = (*apSecond)->FUN_00a011b0(0xfac);
        if (g1 < g3)
        {
            result2 = -1;
        }
        else if (g1 > g3)
        {
            result2 = 1;
        }
    }
    return result2;
}

extern const double DAT_01075020;
extern const double DAT_01075018;

struct FUN_0079c450_shell : public MapMenu
{
    NiPoint3 FUN_0079c450(NiPoint3 position, TESWorldSpace* worldSpace);
};

// @fnv 0x0079c450
NiPoint3 FUN_0079c450_shell::FUN_0079c450(NiPoint3 position, TESWorldSpace* worldSpace)
{
    NiPoint3 pos = position;
    NiPoint3 result;

    if (*(int*)((char*)this + 0x80) == 0x21)
    {
        pos.x = (float)(pos.x * DAT_01075020 - DAT_01075018);
        pos.y = (float)(pos.y * DAT_01075020 - DAT_01075018);
    }

    result.x = (m_kMapMaximumPoint.x - m_kMapMinimumPoint.x) * pos.x + m_kMapMinimumPoint.x;
    result.y = (m_kMapMaximumPoint.y - m_kMapMinimumPoint.y) * pos.y + m_kMapMinimumPoint.y;
    result.z = 0.0f;

    if (worldSpace != 0 && *(int*)((char*)this + 0x80) == 0x21)
    {
        worldSpace->GetCellAtPosition(result, true);
    }

    return result;
}

struct FUN_007a1ac0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    void CallAndReturnSelf(BSStringT<char>& s);
};

struct FUN_007a1ac0_cls
{
    unsigned int unk00;
    FUN_007a1ac0_Entry* m_04;
    unsigned int FUN_00845460();
    void ConstructElements(FUN_007a1ac0_Entry* p, int flag);
    unsigned int FUN_007a1ac0(BSStringT<char>& s);
};

// Gets an index, marks the entry at m_04[idx] with flag 1, stores s into that entry, and returns the index.
// @fnv 0x007a1ac0
unsigned int FUN_007a1ac0_cls::FUN_007a1ac0(BSStringT<char>& aString)
{
    unsigned int uiIndex = FUN_00845460();
    ConstructElements(&m_04[uiIndex], 1);
    m_04[uiIndex].CallAndReturnSelf(aString);
    return uiIndex;
}

struct SpawnedSub
{
    ~SpawnedSub();
};

void __cdecl SpawnedFree(void* p);

struct FUN_007a1d60_cls
{
    virtual ~FUN_007a1d60_cls();
    void Cleanup();
    SpawnedSub m_04;
};

// Runs Cleanup, then frees the object with SpawnedFree.
// @fnv 0x007a1d60
FUN_007a1d60_cls::~FUN_007a1d60_cls()
{
    Cleanup();
    SpawnedFree(this);
}

struct LBValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Refresh(int);
};

struct LBTile
{
    Menu* GetMenu();
    LBValue* FindTraitValue(int);
    float FUN_00a011b0(int);
};

struct LBMenu
{
    Tile* AddTileFromTemplate(LBTile*, const char*, int);
};

int __cdecl TraitNameToIDAdd(const char*, int);
extern const char _kListBoxNumFiltered[];
extern double _gModifierZero;

struct LBItem
{
    Tile* tile;
    int object;
    char isFilteredOut;
    LBItem(Tile* t, int* o);
};

struct LBList
{
    LBItem* item;
    LBList* next;
    void FUN_007a7eb0(LBItem*, int (*)(LBItem*, LBItem*));
    void AddTail(LBItem* const&);
};

struct LBox
{
    virtual void vfn_00();
    LBList list;
    LBTile* parentTile;
    Tile* selected;
    Tile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int);
    int* InitSceneNodes();
    void AccumulateTileHeight(Tile*);
    void FUN_007a8580();
    int GetRaceCount();
    Tile* AddItem(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate);
};

// @fnv 0x007a5230
Tile* LBox::AddItem(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate)
{
    if (parentTile && (templateName || altTemplate))
    {
        Tile* newTile =
            ((LBMenu*)parentTile->GetMenu())->AddTileFromTemplate(parentTile, altTemplate ? altTemplate : templateName, 0);
        if (!newTile->GetValue(0xfaa))
            newTile->Set(0xfaa, -1);
        if (text)
            newTile->Set(0xfc4, text, true);
        if (sortFunc)
        {
            list.FUN_007a7eb0(new LBItem(newTile, &item), sortFunc);
            if (FUN_007242c0(0))
                InitSceneNodes();
        }
        else
        {
            list.AddTail(new LBItem(newTile, &item));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(newTile);
                FUN_007a8580();
            }
            newTile->Set(0xfac, itemCount++);
        }
        if (GetRaceCount() == 1)
        {
            if (parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)) > _gModifierZero)
            {
                LBValue* value = parentTile->FindTraitValue(0xfb0);
                value->RemoveFromReactions();
                value->FUN_00a09130(0x7d0, newTile, 0xfb0);
                value->AppendFloatAction(0x7d3, parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)));
                value->Refresh(0);
            }
        }
        return newTile;
    }
    else
    {
        return 0;
    }
}

int __cdecl TraitNameToIDAdd(const char* pcName, int iDefault);

struct HighlightValue
{
    void FUN_00a09130(int a1, Tile* a2, int a3);
    void Refresh(int a1);
};

struct HighlightTile : public Tile
{
    HighlightTile* FUN_00a03da0(const char* pcName);
    void FUN_0071aa60(bool abVisible);
    void FUN_00a07530(int a1);
    bool GetSpeechChallengeFailure();
};

HighlightTile* __cdecl FUN_00a08b20(Tile* apParent, const char* pcName);

struct FUN_007a6c80_shell
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0C;
    HighlightTile* unk10;
    void UpdateHighlightBox();
};

// Sets the highlight_y and selected_height values on unk0C and shows or hides the lb_highlight_box tile edges depending on unk10's speech challenge failure state.
// @fnv 0x007a6c80
void FUN_007a6c80_shell::UpdateHighlightBox()
{
    static int iHighlightY = TraitNameToIDAdd("_highlight_y", -1);
    static int iSelectedHeight = TraitNameToIDAdd("_selected_height", -1);

    if (unk0C)
    {
        if (unk10)
        {
            HighlightValue* pHighlightY = (HighlightValue*)unk0C->GetValue(iHighlightY);
            HighlightValue* pSelectedHeight = (HighlightValue*)unk0C->GetValue(iSelectedHeight);
            pHighlightY->FUN_00a09130(2000, unk10, 0xfa2);
            pHighlightY->Refresh(0);
            pSelectedHeight->FUN_00a09130(2000, unk10, 0xfb0);
            pSelectedHeight->Refresh(0);
            if (unk10->GetSpeechChallengeFailure())
            {
                HighlightTile* pBox = FUN_00a08b20(unk0C, "lb_highlight_box");
                if (pBox)
                {
                    HighlightTile* pSide = pBox->FUN_00a03da0("top");
                    if (pSide)
                    {
                        pSide->FUN_0071aa60(true);
                        pSide->FUN_00a07530(8);
                        pSide = pBox->FUN_00a03da0("bottom");
                        pSide->FUN_0071aa60(true);
                        pSide->FUN_00a07530(8);
                        pSide = pBox->FUN_00a03da0("left");
                        pSide->FUN_0071aa60(true);
                        pSide->FUN_00a07530(8);
                        pSide = pBox->FUN_00a03da0("right");
                        pSide->FUN_0071aa60(true);
                        pSide->FUN_00a07530(8);
                    }
                    pBox->FUN_0071aa60(true);
                    pBox->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* pBox = FUN_00a08b20(unk0C, "lb_highlight_box");
                if (pBox)
                {
                    HighlightTile* pSide = pBox->FUN_00a03da0("top");
                    if (pSide)
                    {
                        pSide->FUN_0071aa60(false);
                        pSide->FUN_00a07530(8);
                        pSide = pBox->FUN_00a03da0("bottom");
                        pSide->FUN_0071aa60(false);
                        pSide->FUN_00a07530(8);
                        pSide = pBox->FUN_00a03da0("left");
                        pSide->FUN_0071aa60(false);
                        pSide->FUN_00a07530(8);
                        pSide = pBox->FUN_00a03da0("right");
                        pSide->FUN_0071aa60(false);
                        pSide->FUN_00a07530(8);
                    }
                    pBox->FUN_0071aa60(false);
                    pBox->FUN_00a07530(8);
                }
            }
        }
        else
        {
            unk0C->Set(iHighlightY, -1);
            unk0C->Set(iSelectedHeight, 0);
        }
    }
}

float FUN_004e4430(float);
int FUN_00647b70(int, int);

struct ScrollListHost
{
    int unk00;
    int unk04;
    int unk08;
    Tile* pListTile;
    int unk10;
    Tile* pCountTile;
    int unk18;
    int unk1c;
    float fTotalHeight;
    unsigned int GetItemCount();
    void FUN_007a7080();
};

// Computes a scroll count from the list tile's float value and total height, sets _scroll_delta on the list tile and _number_of_items on the count tile.
// @fnv 0x007a7080
void ScrollListHost::FUN_007a7080()
{
    if (pListTile)
    {
        float m_fGlyphExtent = pListTile->GetFloat(0xfb0);
        int iCount = 1;
        if (fTotalHeight > 0.0 && m_fGlyphExtent > 0.0)
        {
            if (fTotalHeight > m_fGlyphExtent)
            {
                iCount =
                    FUN_00647b70((int)FUN_004e4430(GetItemCount() * (fTotalHeight - m_fGlyphExtent) / fTotalHeight) + 1, 2);
            }
            if (iCount > 1)
            {
                pListTile->Set(Tile::GetTraitID("_scroll_delta"), (fTotalHeight - m_fGlyphExtent) / (iCount - 1), true);
            }
        }
        if (pCountTile)
        {
            pCountTile->Set(Tile::GetTraitID("_number_of_items"), iCount);
        }
    }
}

struct EntryTarget
{
    void Notify(int id, unsigned int value);
};

struct EntryItem
{
    EntryTarget* target;
    unsigned int unk04;
    unsigned char flag;
};

struct EntryNode
{
    EntryItem* item;
    EntryNode* next;

    EntryItem*& GetItem();
    EntryNode* GetNext();
};

struct FUN_007a78e0_cls
{
    int unk00;
    EntryNode m_kNode;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short m_1c;
    float m_20;

    void Notify2(EntryTarget* target);
    void Finish1();
    void Finish2();
    void ProcessEntries();
};

// Resets m_1c and m_20, then for each entry with flag 0 notifies its target with 0xfac and an incrementing count, calls Notify2, then Finish1 and Finish2.
// @fnv 0x007a78e0
void FUN_007a78e0_cls::ProcessEntries()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (EntryNode* pNode = this ? &m_kNode : 0; pNode != 0 && pNode->GetItem() != 0; pNode = pNode->GetNext())
    {
        if (pNode->GetItem()->flag == 0)
        {
            pNode->GetItem()->target->Notify(0xfac, m_1c++);
            Notify2(pNode->GetItem()->target);
        }
    }
    Finish1();
    Finish2();
}

extern double _DAT_01012060;
float __cdecl FUN_004e4430(float);
int __cdecl FUN_00647b70(int, int);

struct ListScrollHost
{
    int unk00;
    int unk04;
    int unk08;
    Tile* scrollBar;
    int unk10;
    Tile* itemCountTile;
    int unk18;
    int unk1c;
    float visibleHeight;
    unsigned int GetItemCount();
    void FUN_007a8580();
};

// @fnv 0x007a8580
void ListScrollHost::FUN_007a8580()
{
    if (scrollBar)
    {
        float fValue = scrollBar->GetFloat(0xfb0);
        int iVisibleItemCount = 1;
        if (visibleHeight > _DAT_01012060 && fValue > _DAT_01012060)
        {
            if (visibleHeight > fValue)
            {
                iVisibleItemCount =
                    FUN_00647b70((int)FUN_004e4430(GetItemCount() * (visibleHeight - fValue) / visibleHeight) + 1, 2);
            }
            if (iVisibleItemCount > 1)
            {
                scrollBar->Set(Tile::GetTraitID("_scroll_delta"), (visibleHeight - fValue) / (iVisibleItemCount - 1),
                               true);
            }
        }
        if (itemCountTile)
        {
            itemCountTile->Set(Tile::GetTraitID("_number_of_items"), iVisibleItemCount);
        }
    }
}

void __cdecl FUN_007a1490();

template <> void ListBox<BGSQuestObjective*>::ClearSelection(bool);
template <> void ListBox<BGSNote*>::ClearSelection(bool);

// Loads map_menu.xml, stores the resulting MapMenu in DAT_011da368, initializes its marker lists and tiles, and returns the menu tile or 0 on failure.
// @fnv 0x00796b90
Tile* __cdecl FUN_00796b90()
{
    InterfaceManager* interfaceManager = FUN_004b7210();
    Menu* oldMenu = Tile::FindMenuById(0x3ff);
    if (oldMenu)
    {
        delete oldMenu;
    }
    Tile* menuTile = interfaceManager->FUN_00586150()->ReadFile("Data\\Menus\\Main\\map_menu.xml");
    DAT_011da368 = (MapMenu*)menuTile->GetMenu();
    Menu::ReadMenuDefinition("Data\\Menus\\Main\\map_menu.xml", DAT_011da368);
    if (DAT_011da368 && DAT_011da368->GetID() == 0x3ff)
    {
        DAT_011da368->FUN_00867a20();
        DAT_011da368->Menu::SetTileMenu((TileMenu*)menuTile, false);
        DAT_011da368 = DAT_011da368;
        if (!DAT_011da368->HasNoZeroEntries())
        {
            Warning("MENUS: Map Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (menuTile->GetFloat(0xfa7) == 6006.0 || menuTile->GetFloat(0xfa7) == 102.0)
            menuTile->Set(0xfad, Tile::GetInterfaceScale(), true);
        FUN_004b7210()->tutorials.ShowMessage(0x1a, FUN_00720df0(), 0x200);
        Interface::SetTileFormattedText(DAT_011da368->m_pTiles[17], 0x20, DAT_011d38ac.String(), DAT_011d204c.String(),
                                        DAT_011d5020.String(), DAT_011d28a4.String(), DAT_011d4aec.String(), 0);
        DAT_011da368->m_kQuestListBox.Initialize(DAT_011da368->m_pTiles[7], "MM_ListMarkerTemplate");
        DAT_011da368->m_kQuestListBox.ClearSelection(false);
        DAT_011da368->m_kObjectiveListBox.Initialize(DAT_011da368->m_pTiles[15], "MM_ListMarkerTemplate");
        DAT_011da368->m_kObjectiveListBox.ClearSelection(false);
        DAT_011da368->m_kNoteListBox.Initialize(DAT_011da368->m_pTiles[8], "MM_ListMarkerTemplate");
        DAT_011da368->m_kNoteListBox.ClearSelection(false);
        DAT_011da368->m_kChallengeListBox.Initialize(DAT_011da368->m_pTiles[19], "MM_ListMarkerTemplate");
        DAT_011da368->m_kMapMarkerListBox.Initialize(DAT_011da368->m_pTiles[10], "MM_ListMarkerTemplate");
        NiAVObject* object = DAT_011da368->m_pTiles[16]->FUN_0056c7f0()
                                 ? DAT_011da368->m_pTiles[16]->FUN_0056c7f0()->FUN_0045bc00(0)
                                 : 0;
        TileShaderProperty* property = object ? (TileShaderProperty*)object->GetProperty(FUN_00438220()) : 0;
        if (property)
            property->FUN_007700d0(true);
        DAT_011da368->m_pTiles[6]->Set(TraitNameToIDAdd("_Title", -1), "", true);
        DAT_011da368->m_pTiles[5]->SetFlag8000(true);
        DAT_011da368->m_pTiles[3]->SetFlag8000(true);
        FUN_007a1490();
        DAT_011da368->Menu::SetMenuVisibility(true);
        return menuTile;
    }
    else if (DAT_011da368 && DAT_011da368->FUN_00726070())
    {
        delete DAT_011da368;
    }
    return 0;
}

char __cdecl ConsumeByteAtE4();
void __cdecl FUN_00798a00();
struct MenuInterfaceCalls
{
    void HandleCallbackOrStore(void(__cdecl*)());
    float FUN_007697f0(bool);
    float GetScaledValue(bool);
};
struct MapTileCalls
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float);
};
// @fnv 0x00798710
void __cdecl FUN_00798710()
{
    if (!ConsumeByteAtE4())
    {
        ((MenuInterfaceCalls*)FUN_004b7210())->HandleCallbackOrStore(FUN_00798a00);
    }
    else
    {
        DAT_011da368->m_pSecondMapReference = 0;
    }
    if (!FUN_004b71d0())
    {
        ((MapTileCalls*)DAT_011da368->m_pTiles[6])
            ->FUN_00a012d0(4001, ((MenuInterfaceCalls*)FUN_004b7210())->FUN_007697f0(true) -
                                     ((A7d*)DAT_011da368->m_pTiles[6]->GetParent())->GetTotalFloat() -
                                     ((MapTileCalls*)DAT_011da368->m_pTiles[6])->FUN_00a011b0(4017) / 2.0);
        ((MapTileCalls*)DAT_011da368->m_pTiles[6])
            ->FUN_00a012d0(4002, ((MenuInterfaceCalls*)FUN_004b7210())->GetScaledValue(true) -
                                     ((C7d*)DAT_011da368->m_pTiles[6]->GetParent())->GetAccumulatedFloat() -
                                     ((MapTileCalls*)DAT_011da368->m_pTiles[6])->FUN_00a011b0(4016) / 2.0);
    }
    DAT_011da368->m_pTiles[6]->Set(4003, 1);
}

char ConsumeByteAtE4();

struct MapMenuMarkerCalls : public MapMenu
{
    void FUN_0079f6f0();
    void UpdateQuestMarker();
};

struct PlayerMarkerCalls : public PlayerCharacter
{
    void PlaceMarker(NiPoint3 pos, TESForm* space);
    void ClearHelper();
};

// Reads a mode, updates the player/map marker accordingly, resets the marker position, and repositions the marker element unless a condition holds.
// @fnv 0x00798840
void FUN_00798840()
{
    char cMode = ConsumeByteAtE4();
    switch (cMode)
    {
    case 0:
    case 3:
        ((PlayerMarkerCalls*)g_thePlayer)
            ->PlaceMarker(DAT_011da368->m_kPlayerWorldPosition, DAT_011da368->m_pCurrentMapSpace);
        if (cMode == 0)
            ((MapMenuMarkerCalls*)DAT_011da368)->FUN_0079f6f0();
        ((MapMenuMarkerCalls*)DAT_011da368)->UpdateQuestMarker();
        break;
    case 1:
        ((PlayerMarkerCalls*)g_thePlayer)->ClearHelper();
        ((MapMenuMarkerCalls*)DAT_011da368)->FUN_0079f6f0();
        break;
    }
    DAT_011da368->m_kPlayerWorldPosition = NiPoint3::ZERO;
    DAT_011da368->m_pCurrentMapSpace = 0;
    if (!FUN_004b71d0())
    {
        DAT_011da368->m_pTiles[6]->Set(0xfa1,
                                       (float)(FUN_004b7210()->FUN_007697f0() -
                                               DAT_011da368->m_pTiles[6]->GetParent()->GetScreenX() -
                                               DAT_011da368->m_pTiles[6]->GetFloat(0xfb1) / 2.0),
                                       true);
        DAT_011da368->m_pTiles[6]->Set(0xfa2,
                                       (float)(FUN_004b7210()->GetScaledValue() -
                                               DAT_011da368->m_pTiles[6]->GetParent()->GetScreenY() -
                                               DAT_011da368->m_pTiles[6]->GetFloat(0xfb0) / 2.0),
                                       true);
    }
    DAT_011da368->m_pTiles[6]->Set(0xfa3, 1);
}

class TESDescription
{
  public:
    virtual ~TESDescription();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual const char* GetDescription(TESForm* apParent = 0, unsigned int auiChunkID = 0x43534544);
};

class TESFullName
{
  public:
    virtual ~TESFullName();
    virtual void vfn_04();
    virtual void vfn_08();
    int unk04;
    int unk08;
    const char* GetFullName();
};

class TESChallengePrimary : public TESForm
{
  public:
    int unk10;
    int unk14;
};

class TESChallenge : public TESChallengePrimary, public TESFullName, public TESDescription
{
  public:
    int GetThreshold();
    int GetProgressValue();
};

class FontManager
{
  public:
    static FontManager* Instance();
    NiPoint3 GetStringDimensions(const char* apText, int aiFontID, float afWrapWidth, int aiUnk);
};

struct FUN_00a01290_shell
{
    void SetTraitAndReset(int, float);
};

int __cdecl MinInt(int, int);
float __cdecl FUN_00404010(float, float);
int __cdecl TraitNameToID(const char*);

struct MapMenu_Shell : public MapMenu
{
    void UpdateChallengeText(TESChallenge* apChallenge);
};

// Fills the MM_DataText tile with the challenge's name, progress/threshold and description, then sizes the MM_TextScrollbar from the text height.
// @fnv 0x007991b0
void MapMenu_Shell::UpdateChallengeText(TESChallenge* apChallenge)
{
    float height8;
    char buffer_[512];
    float kScrollDelta;
    Tile* scrollbarTile7;
    Tile* dataTextTile_2;
    float fUnk218;

    dataTextTile_2 = m_pTiles[13]->GetNamedChild("MM_DataText");
    scrollbarTile7 = m_pTiles[13]->GetNamedChild("MM_TextScrollbar");
    kScrollDelta = scrollbarTile7->GetFloat(TraitNameToID("_ScrollDelta"));
    fUnk218 = 0.0f;
    m_pTiles[13]->Set(TraitNameToID("_ItemType"), 1);

    sprintf_s(buffer_, 0x200, "%s\n%d\\%d\n\n%s", apChallenge->GetFullName(),
              MinInt(apChallenge->GetProgressValue(), apChallenge->GetThreshold()), apChallenge->GetThreshold(),
              apChallenge->GetDescription(0, 0x43534544));

    dataTextTile_2->Set(0xfc4, buffer_, true);

    height8 = FontManager::Instance()->GetStringDimensions(buffer_, 1, 400.0f, 0).y;
    fUnk218 = height8 - dataTextTile_2->GetParent()->GetFloat(0xfb0);
    fUnk218 = FUN_00404010(0.0f, fUnk218);

    scrollbarTile7->Set(TraitNameToID("_number_of_items"), FUN_004e4430(fUnk218 / kScrollDelta) + 1.0, true);
    scrollbarTile7->Set(TraitNameToID("_current_value"), 0.0f, false);
    ((FUN_00a01290_shell*)scrollbarTile7)->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
}

struct WidgetTile
{
    int GetAxisState();
    void FUN_00a012d0(int before, float value, int flag);
    void SetTraitAndReset(int before, float value);
    void SetTraitAndReset(int before);
    double FUN_00a011b0(int before);
    bool IsTraitNonZero(int before);
};
struct WidgetSource
{
    WidgetTile* FUN_00a03da0(const char* name);
};
struct WorldInput
{
    WidgetTile* FUN_00877720();
    WidgetTile* FUN_00877720(int type, int id);
};
struct UIManager
{
    bool IsUnk28Set();
};
struct Clock
{
    int FUN_00825c00();
};
struct Metrics
{
    float* FUN_00403e20();
};
struct ElementList
{
    int FUN_00559450();
    int* FUN_0057cbe0(int* cursor);
};
struct CollectionHolder
{
    int unk0;
    ElementList list;
};
struct Controller
{
    virtual void FUN_V0();
    virtual void FUN_V4();
    virtual void FUN_V8();
    virtual void FUN_HandleState(int mode, int arg);
    int unknown_4;
    int unknown_8;
    int unknown_c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    CollectionHolder* history;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    WidgetSource* source;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int mode;
    WidgetTile* current;
    int unknown_88;
    int unknown_8c;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    int unknown_a0;
    int unknown_a4;
    int unknown_a8;
    int unknown_ac;
    int unknown_b0;
    int unknown_b4;
    int unknown_b8;
    int unknown_bc;
    int unknown_c0;
    int unknown_c4;
    int unknown_c8;
    int unknown_cc;
    int unknown_d0;
    int unknown_d4;
    int unknown_d8;
    int unknown_dc;
    int unknown_e0;
    int unknown_e4;
    int unknown_e8;
    int unknown_ec;
    int unknown_f0;
    int unknown_f4;
    int unknown_f8;
    int unknown_fc;
    int unknown_100;
    int unknown_104;
    int unknown_108;
    int unknown_10c;
    int unknown_110;
    int unknown_114;
    int unknown_118;
    int unknown_11c;
    int unknown_120;
    int unknown_124;
    int unknown_128;
    int unknown_12c;
    int unknown_130;
    int unknown_134;
    int unknown_138;
    int unknown_13c;
    int unknown_140;
    int unknown_144;
    int unknown_148;
    int unknown_14c;
    int unknown_150;
    int unknown_154;
    int unknown_158;
    int unknown_15c;
    int unknown_160;
    int unknown_164;
    int unknown_168;
    int unknown_16c;
    int unknown_170;
    int unknown_174;
    int unknown_178;
    int unknown_17c;
    int unknown_180;
    int unknown_184;
    int unknown_188;
    int unknown_18c;
    int unknown_190;
    int unknown_194;
    int unknown_198;
    int unknown_19c;
    int unknown_1a0;
    int unknown_1a4;
    int unknown_1a8;
    int unknown_1ac;
    int unknown_1b0;
    int unknown_1b4;
    int unknown_1b8;
    int unknown_1bc;
    Clock clock;
    bool HandleInputCommand(int command, int ignored);
    void FUN_0079c5a0(bool positive, float amount);
    void UpdateMapHighlight();
};

bool __cdecl FUN_00702450(int code);
UIManager* __cdecl FUN_00705990();
bool __cdecl FUN_00709d40();
double __cdecl FUN_00408820(float value);
int __cdecl TraitNameToID(const void* key);
int __cdecl TraitNameToID(const void* key, float value);
int __cdecl FUN_00ec62c0();
void __cdecl FUN_00717280(int);
void __cdecl FUN_007048f0(int, int, int);
void __cdecl ShowStatsMenu(int, int);

extern WorldInput* DAT_011dea0c;
extern const double DAT_010718f0;
extern const double DAT_010745f8;
extern const double DAT_01074f38;
extern const double DAT_01074f30;
extern const double DAT_0102fc70;
extern const double DAT_01029790;
extern const double DAT_01012060;
extern const float DAT_01012054;
extern const float DAT_01018204;
extern Clock DAT_011f6394;
extern Metrics DAT_011d8b88;
extern int DAT_011da404;
extern int DAT_011da348;
extern const char DAT_01074ec8[];
extern const char DAT_010702d8[];
extern const char DAT_01070250[];

// Handles a UI input command: updates property widgets from world input, adjusts the current tile, and dispatches mode changes and history actions.
// @fnv 0x00799790
bool Controller::HandleInputCommand(int command, int ignored)
{
    if (!FUN_00702450(0x3ff) || !FUN_00705990()->IsUnk28Set())
        return false;
    bool changed = false;
    if (FUN_00702450(0x3ff))
    {

        if (FUN_00709d40())
        {
            WidgetTile* selectedProperty = DAT_011dea0c->FUN_00877720();
            int valueY = 0x7fff;
            int valueX = 0;
            int selected = 0;
            if (mode == 0x20 || mode == 0x21)
            {
                float value = 0.0f;
                selected = DAT_011dea0c->FUN_00877720(0, 8)->GetAxisState();
                if (FUN_00408820((float)selected) <= DAT_010718f0)
                    selected = 0;
                if (selected != 0)
                {
                    value = (float)FUN_00408820((float)((double)selected / DAT_01029790));
                    FUN_0079c5a0(selected > 0, (float)(1.0 + (double)value * DAT_01074f38));
                    changed = true;
                }
            }
            valueX = DAT_011dea0c->FUN_00877720(0, 9)->GetAxisState();
            selected = DAT_011dea0c->FUN_00877720(0, 10)->GetAxisState();
            if (FUN_00408820((float)valueX) <= DAT_010745f8)
                valueX = 0;
            if (FUN_00408820((float)selected) <= DAT_010745f8)
                selected = 0;
            switch (mode)
            {
            case 0x20:
            case 0x21:
                if (current)
                {
                    if (valueX || selected)
                    {
                        current->FUN_00a012d0(0xfea, 1.0f, 1);
                        current->FUN_00a012d0(0xfeb, 1.0f, 1);
                        current->SetTraitAndReset(0xfee, (float)((double)valueX * DAT_01074f30 / DAT_01029790));
                        current->SetTraitAndReset(0xfef, (float)((double)selected * DAT_0102fc70 / DAT_01029790));
                        changed = true;
                    }
                    else
                    {
                        current->FUN_00a012d0(0xfea, DAT_01012054, 1);
                        current->FUN_00a012d0(0xfeb, DAT_01012054, 1);
                    }
                    UpdateMapHighlight();
                }
                break;
            case 0x22:
            case 0x23: {
                WidgetTile* item =
                    mode == 0x22 ? (WidgetTile*)clock.FUN_00825c00() : source->FUN_00a03da0(DAT_01074ec8);
                if (item && item->FUN_00a011b0(0xfa3) != DAT_01012060)
                {
                    int direction = 0;
                    if (selected)
                        direction = (selected < 0) ? 1 : -1;
                    if (direction)
                    {
                        if (!DAT_011da404 || (double)(unsigned)(DAT_011f6394.FUN_00825c00() - DAT_011da404) >
                                                 (double)*DAT_011d8b88.FUN_00403e20())
                        {
                            int before = TraitNameToID(DAT_010702d8);
                            int property = (int)item->FUN_00a011b0(before);
                            item->FUN_00a012d0(before, (float)(property + direction), 0);
                            if ((double)property != item->FUN_00a011b0(before))
                            {
                                item->SetTraitAndReset(TraitNameToID(DAT_01070250), 1.0f);
                            }
                            DAT_011da404 = DAT_011f6394.FUN_00825c00();
                            changed = true;
                        }
                    }
                }
                break;
            }
            }
        }
        switch (command)
        {
        case 0xd:
            FUN_00717280(0x24);
            FUN_007048f0(1, 0, 1);
            changed = true;
            break;
        case 0xe:
            FUN_00717280(0x24);
            ShowStatsMenu(1, 0);
            changed = true;
            break;
        case 9:
            if (mode == 0x21)
            {
                int cursor = history->list.FUN_00559450();
                while (cursor != 0)
                {
                    int value = *history->list.FUN_0057cbe0(&cursor);
                    if (((WidgetTile*)value)->IsTraitNonZero(DAT_011da348))
                    {
                        FUN_HandleState(0x1a, value);
                        changed = true;
                        cursor = 0;
                    }
                }
            }
            break;
        case 0xf:
        case 0x10:
            if (mode == 0x20 || mode == 0x21)
            {
                FUN_0079c5a0(command == 0x10, DAT_01018204);
                changed = true;
            }
            break;
        case 3:
        case 4: {
            mode += (command == 4) ? -1 : 1;
            mode = mode > 0x24 ? 0x20 : mode;
            mode = mode < 0x20 ? 0x24 : mode;
            FUN_HandleState(mode, 0);
            changed = true;
            break;
        }
        }
    }
    return changed;
}

struct DateCalendar
{
    float GetGameTime();
    BSStringT<char> FormatDate();
};
extern DateCalendar calendarState;
struct RenderState
{
    bool IsReady();
};
RenderState* GetRenderState();
struct MenuRefresh : MapMenu
{
    void Refresh();
};
extern SettingT_GameSettingCollection_ localeSetting;
extern SettingT_GameSettingCollection_ g_011d4aec;
int TraitID(const char*);
// @fnv 0x0079aba0
void FUN_0079aba0()
{
    if (DAT_011da368 && GetRenderState()->IsReady())
    {
        BSStringT<char> text;
        float hour = calendarState.GetGameTime();
        int minutes = (hour - (int)hour) * 60.0;
        text.PrintfString("%s, %d:%02d", (const char*)calendarState.FormatDate(), (int)hour, minutes);
        DAT_011da368->m_pTiles[1]->Set(0xfc4, (const char*)text, true);
        g_thePlayer->SetDateTimeText(text);
        DAT_011da368->m_pTiles[0]->Set(0xfc4, (const char*)text, true);
        if (FUN_00408b20(localeSetting.String(), "ENGLISH"))
        {
            DAT_011da368->m_pTiles[11]->Set(TraitID("_Title_1"), DAT_011d1da8.String(), true);
            DAT_011da368->m_pTiles[11]->Set(TraitID("_Title_2"), DAT_011d3f64.String(), true);
            DAT_011da368->m_pTiles[11]->Set(TraitID("_Title_3"), DAT_011d45f4.String(), true);
            DAT_011da368->m_pTiles[11]->Set(TraitID("_Title_4"), DAT_011d3414.String(), true);
            DAT_011da368->m_pTiles[11]->Set(TraitID("_Title_5"), DAT_011d2f10.String(), true);
            DAT_011da368->m_pTiles[11]->GetValue(DAT_011da354)->SetBooleanValue(true);
            DAT_011da368->m_pTiles[12]->Set(TraitID("_Title_1"), DAT_011d3180.String(), true);
            DAT_011da368->m_pTiles[12]->Set(TraitID("_Title_2"), DAT_011d4cfc.String(), true);
            DAT_011da368->m_pTiles[12]->Set(TraitID("_Title_3"), DAT_011d27a8.String(), true);
            DAT_011da368->m_pTiles[12]->Set(TraitID("_Title_4"), DAT_011d3798.String(), true);
            DAT_011da368->m_pTiles[12]->Set(TraitID("_Title_5"), DAT_011d3210.String(), true);
            DAT_011da368->m_pTiles[12]->GetValue(DAT_011da354)->SetBooleanValue(true);
            DAT_011da368->m_pTiles[17]->GetChildById(0x24)->Set(0xfc4, g_011d4aec.String(), true);
            DAT_011da368->FUN_00726070()->GetNamedChild("MM_Headline_Title")->Set(0xfc4, DAT_011d21e4.String(), true);
        }
        ((MenuRefresh*)DAT_011da368)->Refresh();
    }
}

class NoteName
{
  public:
    const char* FUN_00408da0();  // TESFullName::GetFullName
};
class NoteData : public BGSNote
{
  public:
    int unk00[18];
    NoteName m_kName;  // +0x48
};
class NoteTile
{
  public:
    void FUN_00700320(int m_uiSoundID, int iValue);
    void FUN_00a012d0(int m_uiSoundID, float fValue, bool bPropagate);
};
class NotesListBox
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void FreeAllTiles();  // +0x1c
    NoteTile* CreateListItem(BGSNote* pkNote, const char* pcText, int iUnk1, int iUnk2);
    void FUN_007a30e0(bool bUnk);
    void ApplyNoteFilter(bool (*pfnFilter)(BGSNote*));
};
class NoteSource
{
  public:
    int FUN_00966a50();
    NoteData* GetItemAt(int iIndex);
    void* FUN_005cbb50();
};
extern NoteSource* DAT_011dea3c;
int __cdecl TraitNameToID(const char* pcTrait);

class NotesMapMenu
{
  public:
    int unk00[22];
    NoteTile* m_pkNotesTile;  // +0x58
    int unk5c[12];
    bool m_bShowingAllNotes;  // +0x8c
    char unk8d[0xd3];
    NotesListBox m_kNotesList;  // +0x160

    void RefreshNotesList();
};

// @fnv 0x0079b240
void NotesMapMenu::RefreshNotesList()
{
    if (DAT_011da368)
    {
        int iUnusedCount = 0;
        m_kNotesList.FreeAllTiles();
        for (int i = 0; i < DAT_011dea3c->FUN_00966a50(); i++)
        {
            NoteData* pkNote = DAT_011dea3c->GetItemAt(i);
            NoteTile* pkTile2 = m_kNotesList.CreateListItem(pkNote, pkNote->m_kName.FUN_00408da0(), 0, 0);
            pkTile2->FUN_00700320(0xfaa, 0x18);
            pkTile2->FUN_00a012d0(DAT_011da344, pkNote->GetUnk7d() ? 128.0f : 255.0f, true);
        }
        m_kNotesList.FUN_007a30e0(true);
        m_kNotesList.ApplyNoteFilter(FUN_0079b390);
        m_pkNotesTile->FUN_00700320(TraitNameToID("_ShowingAllNotes"), m_bShowingAllNotes);
        m_pkNotesTile->FUN_00700320(0xfaf, DAT_011dea3c->FUN_005cbb50() != 0);
    }
}

class Quest79B;

class QuestNode79B
{
  public:
    Quest79B** GetItem();
    QuestNode79B* GetNext();
};

class Target79B
{
  public:
    QuestNode79B* GetQuestList();
};

class Player79B
{
  public:
    Quest79B* GetActiveQuest();
};

extern Player79B* g_pkPlayer79B;

class Menu79B
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
    bool m_bHidden;
};

extern Menu79B* g_pkMenu79B;

// Returns false if the menu is hidden or if the target's quest list contains the player's active quest; otherwise returns true.
// @fnv 0x0079b390
bool __cdecl FUN_0079b390(Target79B* pkTarget)
{
    bool bResult = true;
    if (g_pkMenu79B && !g_pkMenu79B->m_bHidden)
    {
        for (QuestNode79B* pkNode = pkTarget->GetQuestList(); pkNode && *pkNode->GetItem(); pkNode = pkNode->GetNext())
        {
            if (*pkNode->GetItem() == g_pkPlayer79B->GetActiveQuest())
                bResult = false;
        }
    }
    else if (g_pkMenu79B && g_pkMenu79B->m_bHidden)
    {
        bResult = false;
    }
    return bResult;
}

struct FullName600
{
    const char* FUN_00408da0();
};
struct Challenge600
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FullName600 name;
    int FUN_005f5930();
    int FUN_005a60d0();
    int FUN_005a6150();
};
struct Node600
{
    Challenge600*& FUN_006815c0();
    Node600* FUN_00726070();
};
struct Handler600
{
    Node600* FUN_00461150();
};
extern Handler600* g_dataHandler;
struct Tile600
{
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, bool);
};
bool __cdecl FUN_0079b720(TESChallenge*);
int __cdecl CompareItems(Challenge600*, Challenge600*);
struct List600
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void Clear();
    virtual void Sort(int(__cdecl*)(Challenge600*, Challenge600*));
    Tile600* AddItem(Challenge600*, const char*, int, int);
    void FUN_007a5730(bool(__cdecl*)(TESChallenge*));
};
struct Target600
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
    int unk10c;
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
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    List600 list;
    void RefreshChallengeList();
};
// @fnv 0x0079b600
void Target600::RefreshChallengeList()
{
    list.Clear();
    Node600* node = g_dataHandler->FUN_00461150();
    Challenge600* item = 0;
    while (node)
    {
        item = node->FUN_006815c0();
        if (item && (!item->FUN_005f5930() || item->FUN_005a60d0()))
        {
            Tile600* tile = list.AddItem(item, item->name.FUN_00408da0(), 0, 0);
            tile->FUN_00700320(0xfaa, 0x18);
            tile->FUN_00a012d0(DAT_011da344, item->FUN_005a6150() ? 128.0f : 255.0f, true);
        }
        node = node->FUN_00726070();
    }
    list.FUN_007a5730(FUN_0079b720);
    list.Sort(CompareItems);
}

namespace fnv_0079bea0 {
extern "C" int DAT_011dea3c;
extern "C" int DAT_011da348;
extern "C" int DAT_011da344;
extern "C" float DAT_0101e704;
extern "C" float DAT_01023cd8;

extern "C" void __cdecl FUN_004ff1a0(int, void*, int);
extern unsigned int __cdecl FUN_0079c070();
extern BSSimpleList<unsigned int>* __cdecl FUN_0079c080();
extern bool FUN_0079be30(RefH*);
extern int __cdecl CompareMobileObjects(FUN_0079bd70_data*, FUN_0079bd70_data*);

struct RadioEntry
{
    unsigned int FUN_0055d520();
};
struct RadioTile : Tile
{
    void FUN_00707e10(unsigned int);
};
struct UIRecord : BSStringT<char>
{
    bool FUN_005f65d0(unsigned int*);
    void FUN_00470470();
};
struct RadioList
{
    void** vtable;
    void* FUN_007a3820(RadioEntry*, unsigned int, int, int);
    void FUN_007a3d20(bool (*)(RefH*));
};
typedef void(__thiscall* RadioMethod)(RadioList*);
typedef void(__thiscall* RadioCallback)(RadioList*, void*);
struct FUN_0079bea0_Shell : MapMenu
{
    void RefreshRadioList();
};
// @fnv 0x0079bea0
void FUN_0079bea0_Shell::RefreshRadioList()
{
    UIRecord record;
    FUN_004ff1a0(DAT_011dea3c, &record, 0);
    ((RadioMethod)((RadioList*)&m_kMapMarkerListBox)->vtable[7])((RadioList*)&m_kMapMarkerListBox);
    for (BSSimpleList<unsigned int>* node = FUN_0079c080(); node && node->GetItem(); node = node->GetNext())
    {
        RadioTile* tile =
            (RadioTile*)((RadioList*)&m_kMapMarkerListBox)
                ->FUN_007a3820((RadioEntry*)node->GetItem(), ((RadioEntry*)node->GetItem())->FUN_0055d520(), 0, 0);
        tile->Set(0xfaa, 0x19);
        tile->FUN_00707e10(((RadioEntry*)node->GetItem())->FUN_0055d520());
        tile->Set(DAT_011da348, FUN_0079c070() && node->GetItem() == *(unsigned int*)FUN_0079c070());
        tile->Set(DAT_011da344, record.FUN_005f65d0(&node->GetItem()) ? DAT_01023cd8 : DAT_0101e704, true);
    }
    ((RadioList*)&m_kMapMarkerListBox)->FUN_007a3d20(&FUN_0079be30);
    ((RadioCallback)((RadioList*)&m_kMapMarkerListBox)->vtable[8])((RadioList*)&m_kMapMarkerListBox,
                                                                   (void*)&CompareMobileObjects);
    record.FUN_00470470();
}
}  // namespace fnv_0079bea0

struct AnimationRef
{
    void* ptr;
    AnimationRef(void*);
    ~AnimationRef();
};
struct WaveProperty
{
    void SetFloats(float, float);
};
struct WaveMenu : MapMenu
{
    void UpdateWaveAnimation();
};
extern MapMenu* DAT_011da368;
extern float DAT_011da414;
extern unsigned int DAT_011da418;
extern SettingT_GameSettingCollection_ g_011d505c;
unsigned int gm_GetTickCount();
unsigned int DialogueRandom();
int formatText(char*, unsigned int, const char*, ...);
int strcpy_s(char*, unsigned int, const char*);
// Drives a wave property's animation over 750ms, stepping DAT_011da414 every 10ms and picking a random direction label when done.
// @fnv 0x0079c0c0
void WaveMenu::UpdateWaveAnimation()
{
    const int duration9 = 750;
    const int interval5 = 10;
    char buffer_[64];
    NiAVObject* object =
        DAT_011da368->m_pTiles[16]->FUN_0056c7f0() ? DAT_011da368->m_pTiles[16]->FUN_0056c7f0()->FUN_0045bc00(0) : 0;
    WaveProperty* property = object ? (WaveProperty*)object->GetProperty(FUN_00438220()) : 0;
    if (!property)
        return;
    if (m_fMapRotation == 0.0)
    {
        AnimationRef reference2(0);
        formatText(buffer_, 64, g_011d505c.String(), m_pTiles[16]->GetString(0xfd2));
        DAT_011da368->m_pTiles[16]->Set(0xfcc, buffer_, true);
        m_fMapRotation = (float)gm_GetTickCount();
        m_pTiles[16]->Set(0xfa3, 1);
    }
    if (gm_GetTickCount() - DAT_011da418 >= interval5)
    {
        property->SetFloats(DAT_011da414, 0.0f);
        DAT_011da414 = DAT_011da414 + 0.1f;
        if (DAT_011da414 > 1.0)
            DAT_011da414 = DAT_011da414 - 1.0;
        DAT_011da418 = gm_GetTickCount();
    }
    if ((float)gm_GetTickCount() - m_fMapRotation >= duration9)
    {
        unsigned int directionTmp = DialogueRandom() % 3;
        if (directionTmp == 0)
            strcpy_s(buffer_, 64, "Forward");
        else if (directionTmp == 1)
            strcpy_s(buffer_, 64, "Backward");
        else
            strcpy_s(buffer_, 64, "Left");
        m_pTiles[16]->Set(0xfd2, buffer_, true);
        m_fMapRotation = 0.0f;
    }
}

struct ZoomPoint
{
    float x, y;
    ZoomPoint(float, float);
    ZoomPoint& Scale(float);
};
struct ZoomUpdate
{
    float time;
    bool a, b;
    int flags;
    ZoomUpdate(float, bool, bool);
};
struct ZoomData
{
    void Mark(int);
};
struct ZoomObject
{
    void Scale(float);
    void Position(float, float, float);
    void Update(ZoomUpdate&);
    ZoomData* Data();
};
struct ZoomNode
{
    ZoomObject* Child(unsigned int);
};

struct ZoomSetting
{
    float* Float();
};
struct ZoomInt
{
    int* Int();
};
struct ZoomTES
{
    void* Interior();
};
struct ZoomPip
{
    void Animate(int, float, float, bool);
};
struct ZoomInterface
{
    ZoomPip* Pip();
};
ZoomInterface* GetInterface();
extern ZoomTES* zoomTES;
extern ZoomInt zoomGrid;
extern ZoomSetting zoomSound, zoomSpeed;
extern int DAT_011da35c;
bool FUN_007a1750();
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
extern ZoomSetting originalRuntimeFloatSetting1242;
extern ZoomSetting originalRuntimeFloatSetting1243;
extern ZoomSetting originalRuntimeFloatSetting1244;
extern ZoomSetting originalRuntimeFloatSetting1245;
extern ZoomSetting originalRuntimeFloatSetting1246;
extern ZoomSetting originalRuntimeFloatSetting1247;
extern ZoomSetting originalRuntimeFloatSetting1248;
extern ZoomSetting originalRuntimeFloatSetting1249;
extern ZoomSetting originalRuntimeFloatSetting1250;
extern ZoomSetting originalRuntimeFloatSetting1251;
extern ZoomSetting originalRuntimeFloatSetting1252;
extern ZoomSetting originalRuntimeFloatSetting1253;
extern ZoomSetting originalRuntimeFloatSetting1254;
extern ZoomSetting originalRuntimeFloatSetting1255;
extern ZoomSetting originalRuntimeFloatSetting1256;
extern ZoomSetting originalRuntimeFloatSetting1257;
struct ZoomMenu
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
    int page;
    Tile* tile;
    void Finish();
    void FUN_0079c5a0(bool, float);
};
// Zooms the map tile by a factor, updates its scale and position, rescales grid children on page 32, plays the zoom sound and finishes the menu.
// @fnv 0x0079c5a0
void ZoomMenu::FUN_0079c5a0(bool inward, float factor)
{
    if (!tile || (page == 32 && FUN_007a1750()))
        return;
    bool _changed = true;
    float scale2 = (inward ? factor : 1.0 / factor) * tile->GetFloat(DAT_011da35c);
    ZoomPoint centerVal(tile->GetParent()->GetFloat(0xfb1) / 2.0 - tile->GetFloat(0xfa1),
                        tile->GetParent()->GetFloat(0xfb0) / 2.0 - tile->GetFloat(0xfa2));
    if (page == 32)
    {
        float fraction7 = 0.0f;
        scale2 = FUN_00404010(FUN_0040ebd0(scale2, *originalRuntimeFloatSetting1251.Float()),
                              *originalRuntimeFloatSetting1250.Float());
        fraction7 = (scale2 - *originalRuntimeFloatSetting1250.Float()) /
                    (*originalRuntimeFloatSetting1251.Float() - *originalRuntimeFloatSetting1250.Float());
        tile->Set(4100,
                  (double)*originalRuntimeFloatSetting1252.Float() +
                      ((double)*originalRuntimeFloatSetting1253.Float() - *originalRuntimeFloatSetting1252.Float()) *
                          fraction7,
                  true);
        tile->Set(4101,
                  (double)*originalRuntimeFloatSetting1254.Float() +
                      ((double)*originalRuntimeFloatSetting1255.Float() - *originalRuntimeFloatSetting1254.Float()) *
                          fraction7,
                  true);
        tile->Set(4102,
                  (double)*originalRuntimeFloatSetting1256.Float() +
                      ((double)*originalRuntimeFloatSetting1257.Float() - *originalRuntimeFloatSetting1256.Float()) *
                          fraction7,
                  true);
    }
    else
    {
        float unusedDimension = 0.0f;
        scale2 = FUN_00404010(FUN_0040ebd0(scale2, *originalRuntimeFloatSetting1243.Float()),
                              *originalRuntimeFloatSetting1242.Float());
        unusedDimension = (scale2 - *originalRuntimeFloatSetting1242.Float()) /
                          (*originalRuntimeFloatSetting1243.Float() - *originalRuntimeFloatSetting1242.Float());
        tile->Set(4100,
                  (double)*originalRuntimeFloatSetting1244.Float() +
                      ((double)*originalRuntimeFloatSetting1245.Float() - *originalRuntimeFloatSetting1244.Float()) *
                          unusedDimension,
                  true);
        tile->Set(4101,
                  (double)*originalRuntimeFloatSetting1246.Float() +
                      ((double)*originalRuntimeFloatSetting1247.Float() - *originalRuntimeFloatSetting1246.Float()) *
                          unusedDimension,
                  true);
        tile->Set(4102,
                  (double)*originalRuntimeFloatSetting1248.Float() +
                      ((double)*originalRuntimeFloatSetting1249.Float() - *originalRuntimeFloatSetting1248.Float()) *
                          unusedDimension,
                  true);
    }
    _changed = scale2 != tile->GetFloat(DAT_011da35c);
    centerVal.Scale(tile->GetFloat(0xfcd) * scale2 / tile->GetFloat(0xfb1));
    tile->Set(DAT_011da35c, scale2, true);
    if (page == 32)
    {
        ZoomNode* nodeB = reinterpret_cast<ZoomNode*>(tile->FUN_0056c7f0());
        unsigned int gridA = *zoomGrid.Int();
        for (unsigned int index_ = 0; nodeB && index_ < gridA * gridA; index_++)
        {
            ZoomObject* child4 = nodeB->Child(index_);
            if (child4)
            {
                float dimensionB = (zoomTES->Interior() ? 2048 : 1024) * scale2;
                float otherFraction6 = dimensionB / 16.0;
                child4->Scale(scale2);
                child4->Position((index_ % gridA) * dimensionB + dimensionB / 2.0, 0.0f,
                                 (index_ / gridA) * dimensionB + dimensionB / 2.0 - gridA * dimensionB);
                ZoomUpdate updateB(0.0f, false, false);
                child4->Update(updateB);
                child4->Data()->Mark(0x4000);
            }
        }
    }
    tile->Set(0xfa1, tile->GetParent()->GetFloat(0xfb1) / 2.0 - centerVal.x - tile->GetFloat(0xfee), false);
    tile->Set(0xfa2, tile->GetParent()->GetFloat(0xfb0) / 2.0 - centerVal.y - tile->GetFloat(0xfef), false);
    if (_changed)
    {
        float amount5 = (factor - 1.0) / 0.14300000667572021;
        GetInterface()->Pip()->Animate(0, inward ? -*zoomSound.Float() * amount5 : *zoomSound.Float() * amount5,
                                       *zoomSpeed.Float() * 2, true);
    }
    Finish();
}

struct PlayerMapView : PlayerCharacter
{
    TESWorldSpace* FUN_00575d70();
    bool FUN_00575d10();
};
struct DoorBaseView
{
    int GetFormType();
    bool IsFlag4Set();
};
struct DoorInfoView
{
    void SetString(BSStringT<char>&);
};
struct MarkerRefView : TESObjectREFR
{
    DoorBaseView* FUN_007af430();
    bool FUN_00477ba0();
    bool FUN_0057b4b0();
    DoorInfoView* FUN_00568e50();
};
struct NiPoint2_helper
{
    float x, y;
    NiPoint2_helper(float, float);
};
int __cdecl TruncateFloatToInt(float);
int __cdecl FUN_00556870(NiPoint3&);
int __cdecl TraitNameToIDAdd(const char*, int);
struct MarkerChildren
{
    bool FUN_0076b610();
};
struct MarkerTileView
{
    int unk00;
    MarkerChildren children;
};
struct MapView : MapMenu
{
    void UpdateLocalMap();
    void FUN_0079c5a0(bool, float);
    NiPoint3 GetMarkerPosition(NiPoint3, TESWorldSpace*);
    Tile* AddTileFromTemplate(Tile*, const char*, bool);
    void FUN_0079dbb0();
};
// Computes the local map's world bounds from the player position or parent cell, updates the map view, and places door markers on the map tile.
// @fnv 0x0079d410
void MapView::UpdateLocalMap()
{
    TESWorldSpace* b = ((PlayerMapView*)g_thePlayer)->FUN_00575d70();
    TESObjectCELL* a = g_thePlayer->GetParentCell();
    NiPoint3 c = *g_thePlayer->GetPos();
    pAdjustNorthRotationCell = ((PlayerMapView*)g_thePlayer)->FUN_00575d10() ? a : 0;
    if (pAdjustNorthRotationCell)
    {
        NiPoint3 b = c;
        ((TESObjectCELL_Ext*)pAdjustNorthRotationCell)->FUN_00555b10(c, b, true);
        int e = ((TruncateFloatToInt(b.x) - 2048) >> 12) - (*g_011c63cc.Int() >> 1);
        int d = ((TruncateFloatToInt(b.y) - 2048) >> 12) - (*g_011c63cc.Int() >> 1);
        NiPoint3 a((float)((e << 12) + 2048), (float)(((d + *g_011c63cc.Int() - 1) << 12) + 2048), 0.0f);
        NiPoint3 c((float)(((e + *g_011c63cc.Int() - 1) << 12) + 2048), (float)((d << 12) + 2048), 0.0f);
        m_kMapMinimumPoint = (const NiPoint2&)NiPoint2_helper(a.x, a.y + 4096.0);
        m_kMapMaximumPoint = (const NiPoint2&)NiPoint2_helper(c.x + 4096.0, c.y);
    }
    else
    {
        int e = ((TruncateFloatToInt(c.x)) >> 12) - (*g_011c63cc.Int() >> 1);
        int d = ((TruncateFloatToInt(c.y)) >> 12) - (*g_011c63cc.Int() >> 1);
        NiPoint3 a((float)(e << 12), (float)((d + *g_011c63cc.Int() - 1) << 12), 0.0f);
        NiPoint3 b((float)((e + *g_011c63cc.Int() - 1) << 12), (float)(d << 12), 0.0f);
        m_kMapMinimumPoint = (const NiPoint2&)NiPoint2_helper(a.x, a.y + 4096.0);
        m_kMapMaximumPoint = (const NiPoint2&)NiPoint2_helper(b.x + 4096.0, b.y);
    }
    FUN_0079c5a0(true, 1.0f);
    if (b)
        m_pCurrentMapForm = b;
    else
        m_pCurrentMapForm = a;
    if (m_pCurrentMapForm)
    {
        if (((MarkerTileView*)m_pTiles[2])->children.FUN_0076b610())
        {
            for (BSSimpleList<TESObjectREFR*>* node = &LocalMapMarkerList; node && node->GetItem();
                 node = node->GetNext())
            {
                MarkerRefView* e = (MarkerRefView*)node->GetItem();
                DoorBaseView* a = e->FUN_007af430()->GetFormType() == 28 ? e->FUN_007af430() : 0;
                NiPoint3 d = *e->GetPos();
                if (e->FUN_00477ba0() || e->FUN_0057b4b0() || (!a || a->IsFlag4Set()))
                    continue;
                if (pAdjustNorthRotationCell)
                    ((TESObjectCELL_Ext*)pAdjustNorthRotationCell)->FUN_00555b10(d, d, true);
                float c = 255.0f;
                NiPoint3 b = GetMarkerPosition(d, 0);
                if (m_bNeedsMapUpdate)
                    c = (float)(FUN_00556870(d) / 4.0 * c);
                if (c > 0.0 && b.x >= 0.0 && b.x <= 1.0 && b.y >= 0.0 && b.y <= 1.0)
                {
                    Tile* g = ((MapView*)DAT_011da368)->AddTileFromTemplate(m_pTiles[2], "MapMarkerTemplate", false);
                    DoorInfoView* f = e->FUN_00568e50();
                    g->Set(4010, 26);
                    g->Set(DAT_011da350, b.x, true);
                    g->Set(DAT_011da34c, b.y, true);
                    g->Set(4009, c, true);
                    g->Set(4044, "Interface\\Icons\\Local Map\\icon_local_door.dds", true);
                    if (f)
                    {
                        BSStringT<char> locationName;
                        f->SetString(locationName);
                        g->Set(TraitNameToIDAdd("_LocationName", -1), (const char*)locationName, true);
                    }
                }
            }
        }
        FUN_0079dbb0();
    }
    m_pTiles[2]->Set(4003, 1);
    m_pTiles[3]->Set(4003, 1);
}

namespace MapMarkerUpdate {
struct Point
{
    float x, y, z;
    Point()
    {}
    Point(float, float, float);
};
struct Reference;
struct TargetPtr
{
    Reference* FUN_00559450();
};
struct SearchHit
{
    TargetPtr* FUN_00568e50();
};
struct HitList
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
    unsigned int FUN_0044ddc0();
    SearchHit** FUN_006cedb0();
};
struct SearchResults
{
    int unk00, unk04, unk08, unk0c;
    HitList hits;
    SearchResults();
    ~SearchResults();
};
struct Origin
{
    float x, y, z;
    Origin(Reference*);
};
struct Query
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
    Query();
    Query(Reference*);
    ~Query();
};
bool FUN_006d4d20(const Query&, const Query&, SearchResults*, int, float, const Origin*, int);
struct World
{
    void FUN_00555b10(Point&, const Point&, int);
    float FUN_00555ad0();
};
struct Reference
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
    virtual const Point& Position();
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
    virtual float Heading(int);
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
    int unk10c;
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
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    Reference* marker;
    bool FUN_00575d10();
    void* FUN_00575d70();
    World* FUN_008d6f30();
    Reference* FUN_00798400();
};
extern Reference* DAT_011dea3c;
struct Tile
{
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, int);
    bool FUN_00a07ed0(int);
    void StartFade(int, float, float, float, int);
    Tile* FUN_0045cd60();
    double FUN_00a011b0(int);
};
extern int DAT_011da350, DAT_011da34c;
extern const float DAT_01016248, DAT_01023cd8, DAT_0101e704;
extern const double DAT_010290d0, DAT_01011590;
struct Menu
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
    Tile* localMarker;
    int unk038;
    Tile* worldMarker;
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
    int mode;
    Tile* map;
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
    int unk10c;
    int unk110;
    Reference* target;
    int unk118;
    World* world;
    Point GetMarkerPosition(Point, void*);
    void FUN_0079e0a0();
    void UpdateMapMarkers();
    void FUN_0079f6f0();
    void UpdateQuestMarker();
    void FUN_0079dbb0();
};
// @fnv 0x0079dbb0
void Menu::FUN_0079dbb0()
{
    Tile* tile = mode == 33 ? worldMarker : localMarker;
    {
        Point point(DAT_01016248, DAT_01016248, 0.0f);
        if (mode == 33 && DAT_011dea3c->FUN_00575d10())
        {
            target = DAT_011dea3c->marker;
            if (!target)
            {
                SearchResults results;
                Origin origin(DAT_011dea3c);
                if (FUN_006d4d20(Query(DAT_011dea3c), Query(), &results, 3, 0.0f, &origin, 2))
                {
                    if (results.hits.FUN_0044ddc0() > 0)
                        target = (*results.hits.FUN_006cedb0())->FUN_00568e50()->FUN_00559450();
                    if (!target)
                        target = DAT_011dea3c;
                }
            }
        }
        else
            target = DAT_011dea3c;
        if (target)
        {
            Point position = target->Position();
            if (world)
                world->FUN_00555b10(position, position, 1);
            point = GetMarkerPosition(position, target->FUN_00575d70());
            tile->FUN_00700320(4003, 1);
            tile->FUN_00a012d0(DAT_011da350, point.x, 1);
            tile->FUN_00a012d0(DAT_011da34c, point.y, 1);
            float angle = -DAT_011dea3c->Heading(0) - DAT_010290d0;
            angle -= DAT_011dea3c->FUN_00575d10() ? DAT_011dea3c->FUN_008d6f30()->FUN_00555ad0() : 0.0f;
            tile->FUN_00a012d0(4090, angle, 1);
        }
        else
            tile->FUN_00700320(4003, 0);
        if (!tile->FUN_00a07ed0(4085))
            tile->StartFade(4085, DAT_0101e704, DAT_01023cd8, 1.0f, 1);
        map->FUN_00a012d0(
            4001, map->FUN_0045cd60()->FUN_00a011b0(4017) / DAT_01011590 - map->FUN_00a011b0(4017) * point.x, 0);
        map->FUN_00a012d0(
            4002, map->FUN_0045cd60()->FUN_00a011b0(4016) / DAT_01011590 - map->FUN_00a011b0(4016) * point.y, 0);
        FUN_0079e0a0();
        UpdateMapMarkers();
        if (DAT_011dea3c->FUN_00798400())
        {
            FUN_0079f6f0();
            UpdateQuestMarker();
        }
    }
}
}

namespace fnv_0079e0a0 {
struct MarkerTile;
struct MarkerChildren
{
    MarkerTile* FUN_0057c730(MarkerTile*&);
};
struct MarkerTile
{
    virtual ~MarkerTile();
    MarkerChildren children;
    MarkerTile* FUN_00a03eb0(int);
    void FUN_009ff690();
};
struct QuestTargetOps
{
    TESObjectREFR* FUN_006101b0(bool);
    PathingPath* FUN_00460140();
    TESObjectREFR* FUN_005cbb70();
};
struct QuestNode
{
    QuestTargetOps** FUN_006815c0();
    QuestNode* FUN_00726070();
};
struct PlayerQuestOps
{
    QuestNode* GetCurrentQuestTargets();
};
struct RefMapOps
{
    bool FUN_00575d10();
    TESWorldSpace* FUN_00575d70();
};
struct SettingQuestOps
{
    SETTING_VALUE* FUN_00408d60();
};
extern SettingQuestOps g_011e07f0;
extern const char markerWorld[], markerLocal[], markerTexture[];
struct MarkerValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int, Tile*, int);
    void Refresh(int);
};
struct MarkerTileOps
{
    void FUN_00700320(int, int);
    MarkerValue* FUN_00a00f30(int);
};
struct MarkerMap : MapMenu
{
    TESObjectREFR* SelectTarget(TESObjectREFR*, PathingPath*);
    void FUN_0079f8d0(TESObjectREFR*, TESObjectREFR*, PathingPath*, int);
    NiPoint3 GetMarkerPosition(NiPoint3, TESWorldSpace*);
    Tile* AddTileFromTemplate(Tile*, const char*, int);
    void FUN_0079e0a0();
};
// @fnv 0x0079e0a0
void MarkerMap::FUN_0079e0a0()
{
    MarkerTile* tile = ((MarkerTile*)m_pMapTile)->FUN_00a03eb0(27);
    while (tile)
    {
        ((MarkerTile*)m_pMapTile)->children.FUN_0057c730(tile);
        tile->FUN_009ff690();
        delete tile;
        tile = ((MarkerTile*)m_pMapTile)->FUN_00a03eb0(27);
    }
    tile = ((MarkerTile*)m_pMapTile)->FUN_00a03eb0(29);
    while (tile)
    {
        ((MarkerTile*)m_pMapTile)->children.FUN_0057c730(tile);
        tile->FUN_009ff690();
        delete tile;
        tile = ((MarkerTile*)m_pMapTile)->FUN_00a03eb0(29);
    }
    for (QuestNode* node = ((PlayerQuestOps*)g_thePlayer)->GetCurrentQuestTargets();
         g_011e07f0.FUN_00408d60()->b && node && *node->FUN_006815c0(); node = node->FUN_00726070())
    {
        TESObjectREFR* reference = (*node->FUN_006815c0())->FUN_006101b0(true);
        TESObjectREFR* target = m_iMapDisplayMode == 33
                                    ? SelectTarget(reference, (*node->FUN_006815c0())->FUN_00460140())
                                    : (*node->FUN_006815c0())->FUN_005cbb70();
        if (target)
        {
            if (m_iMapDisplayMode == 33)
                FUN_0079f8d0(m_pFirstMapReference, target, (*node->FUN_006815c0())->FUN_00460140(), 29);
        }
        else if (reference && ((m_iMapDisplayMode == 33 && !((RefMapOps*)reference)->FUN_00575d10()) ||
                               (m_iMapDisplayMode == 32 && reference->GetParentCell() == g_thePlayer->GetParentCell())))
        {
            target = (*node->FUN_006815c0())->FUN_006101b0(true);
        }
        if (target)
        {
            NiPoint3 position = *target->GetPos();
            NiPoint3 mapPosition;
            if (pAdjustNorthRotationCell)
                pAdjustNorthRotationCell->FUN_00555b10(position, position, true);
            mapPosition = GetMarkerPosition(position, ((RefMapOps*)target)->FUN_00575d70());
            {
                Tile* value = 0;
                if (m_iMapDisplayMode == 33)
                    value = ((MarkerMap*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, markerWorld, 0);
                else
                    value = ((MarkerMap*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, markerLocal, 0);
                value->Set(DAT_011da350, mapPosition.x, true);
                value->Set(DAT_011da34c, mapPosition.y, true);
                value->Set(0xfcc, markerTexture, true);
                ((MarkerTileOps*)value)->FUN_00700320(0xfaa, 27);
                MarkerValue* marker = ((MarkerTileOps*)value)->FUN_00a00f30(0xff5);
                marker->RemoveFromReactions();
                marker->FUN_00a09130(2000, m_iMapDisplayMode == 33 ? m_pTiles[5] : m_pTiles[3], 0xff5);
                marker->Refresh(0);
            }
        }
    }
}
}  // namespace fnv_0079e0a0

#include <stdio.h>

struct TeleportPathHelper
{
    BSSimpleArray<TESObjectREFR*> references;
    BSSimpleArray<TESObjectCELL*> cells;
    NiPoint3 start, end;
    TeleportPathHelper();
    ~TeleportPathHelper();
};
struct QuestMarkerNode
{
    TESObjectREFR*& GetItem();
    QuestMarkerNode* GetNext();
};
struct MarkerPlayer
{
    QuestMarkerNode* FUN_005eb7e0();
    void FUN_00952d60(TESObjectREFR*, TeleportPathHelper*, int);
};
struct MarkerReference : TESObjectREFR
{
    const char* GetFullName();
    TESWorldSpace* FUN_00575d70();
};
struct MarkerTile : Tile
{
    float FUN_00a011b0(int);
    MarkerTile* FUN_00a03da0(const char*);
    void FUN_00a07530(int);
};
struct MarkerMenu : MapMenu
{
    TESObjectREFR* SelectTarget(TESObjectREFR*, TeleportPathHelper*);
    NiPoint3 GetMarkerPosition(NiPoint3, TESWorldSpace*);
    void UpdateQuestMarkers();
};
int FUN_00404dc0(const char*, const char*);
// Iterates quest marker nodes, creates a map tile per reference, positions and configures it, and links a name tile when the marker name differs.
// @fnv 0x0079e470
void MarkerMenu::UpdateQuestMarkers()
{
    QuestMarkerNode* p = ((MarkerPlayer*)g_thePlayer)->FUN_005eb7e0();
    MarkerTile* a;
    while (p)
    {
        MarkerReference* aMap = (MarkerReference*)p->GetItem();
        TeleportPathHelper aArea;
        if (m_iMapDisplayMode == 33)
            ((MarkerPlayer*)g_thePlayer)->FUN_00952d60(aMap, &aArea, 1);
        MarkerReference* aFirst = m_iMapDisplayMode == 33 ? (MarkerReference*)SelectTarget(aMap, &aArea) : aMap;
        a = aFirst ? ((MarkerTile*)m_pMapTile)->FUN_00a03da0(aFirst->GetFullName()) : 0;
        if (a && a->GetString(0xfc4) && !FUN_00404dc0(aMap->GetFullName(), a->GetString(0xfc4)))
        {
            char markerName[64];
            sprintf(markerName, "%s Marker", aFirst ? aFirst->GetFullName() : 0);
            MarkerTile* aB = aFirst ? ((MarkerTile*)m_pMapTile)->FUN_00a03da0(markerName) : 0;
            NiPoint3 _point2 = *aFirst->GetPos();
            NiPoint3 _pos2 = _point2;
            if (m_iMapDisplayMode == 33)
                _pos2.y -= 1024.0;
            else
                _pos2.y -= 128.0;
            NiPoint3 aCollision;
            NiPoint3 aOffset;
            if (pAdjustNorthRotationCell)
                pAdjustNorthRotationCell->FUN_00555b10(_point2, _point2, true);
            aCollision = GetMarkerPosition(_point2, aFirst->FUN_00575d70());
            aOffset = GetMarkerPosition(_pos2, aFirst->FUN_00575d70());
            float _target = ((MarkerTile*)m_pMapTile)->FUN_00a011b0(0xfb1);
            float _scale = ((MarkerTile*)m_pMapTile)->FUN_00a011b0(0xfb0);
            _target *= aOffset.x;
            _scale *= aOffset.y;
            float fX7 = _target;
            float fY3 = _scale;
            a->Set(DAT_011da350, aOffset.x, true);
            a->Set(DAT_011da34c, aOffset.y, true);
            a->Set(0xfa1, fX7, true);
            a->Set(0xfa2, fY3, true);
            a->Set(0xfc4, aMap->GetFullName(), true);
            a->Set(0xfba, 200.0f, true);
            a->Set(0xfaa, 38);
            a->Set(0xfad, 2.0f, true);
            a->Set(0xfa3, 1);
            a->Set(0xfae, 1);
            a->Set(0xfb7, 2);
            a->Set(0xfb9, 2);
            a->Set(0xfb0, 60.0f, true);
            if (aB)
            {
                LBValue* aCreated = (LBValue*)a->GetValue(0xfa1);
                LBValue* aCacheObject = (LBValue*)a->GetValue(0xfa2);
                aCreated->RemoveFromReactions();
                aCreated->FUN_00a09130(0x7d0, aB, 0xfa1);
                aCreated->Refresh(0);
                aCacheObject->RemoveFromReactions();
                aCacheObject->FUN_00a09130(0x7d0, aB, 0xfa2);
                aCacheObject->AppendFloatAction(0x7d1, 60.0f);
                aCacheObject->Refresh(0);
            }
            a->FUN_00a07530(0x3ff);
        }
        p = p->GetNext();
    }
}

namespace fnv_0079ea30 {
extern const double DAT_01016968;
extern "C" int sprintf(char*, const char*, ...);
Tile* __cdecl FUN_00a00c20(int);
TESWorldSpace* __fastcall FUN_00575d70(TESObjectREFR*);

class TeleportPathHelper
{
  public:
    TeleportPathHelper();
    ~TeleportPathHelper();
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28;
    int unk2c, unk30, unk34;
};

class TESObjectREFRExt : public TESObjectREFR
{
  public:
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
    virtual bool ShouldHide(int reason);
    bool FUN_00575d10();
    const char* GetFullName();
    float FUN_005723b0(TESObjectREFR*, int, int);
};

struct PlayerCharacterExt : public PlayerCharacter
{
    BSSimpleList<TESObjectREFR*>* GetMapMarkers();
    void FUN_00952d60(TESObjectREFR*, TeleportPathHelper*, int);
};

struct TileEx;
struct TileChildrenList
{
    void FUN_0057c730(TileEx**);
};

struct TileEx
{
    virtual ~TileEx();
    TileChildrenList children;
    void Release();
    TileEx* GetChildById(int);
    void SetName(const char*);
    void FUN_00a07530(int);
};

struct MapMenuExt : public MapMenu
{
    Tile* AddTileFromTemplate(Tile*, const char*, int);
    void UpdateMapMarkers();
};

// Clears the map marker tiles, then iterates the player's map markers and creates quest marker tiles for each visible destination.
// @fnv 0x0079ea30
void MapMenuExt::UpdateMapMarkers()
{
    BSSimpleList<TESObjectREFR*>* headX;
    TileEx* element = ((TileEx*)m_pMapTile)->GetChildById(0x25);
    while (element)
    {
        ((TileEx*)m_pMapTile)->children.FUN_0057c730(&element);
        element->Release();
        delete element;
        element = ((TileEx*)m_pMapTile)->GetChildById(0x25);
    }

    element = ((TileEx*)m_pMapTile)->GetChildById(0x26);
    while (element)
    {
        ((TileEx*)m_pMapTile)->children.FUN_0057c730(&element);
        element->Release();
        delete element;
        element = ((TileEx*)m_pMapTile)->GetChildById(0x26);
    }

    headX = ((PlayerCharacterExt*)g_thePlayer)->GetMapMarkers();
    while (headX)
    {
        TESObjectREFR* kPRef = headX->GetItem();
        TeleportPathHelper pathX;

        if (m_iMapDisplayMode == 0x21)
        {
            ((PlayerCharacterExt*)g_thePlayer)->FUN_00952d60(kPRef, &pathX, 1);
        }

        TESObjectREFR* dest = (m_iMapDisplayMode == 0x21) ? GetTeleportDestination(kPRef, (PathingPath*)&pathX) : kPRef;

        if ((dest == 0 || ((TESObjectREFRExt*)dest)->ShouldHide(0)) ||
            (m_iMapDisplayMode == 0x20 && kPRef->GetParentCell() != g_thePlayer->GetParentCell() &&
             FUN_00575d70(kPRef) != FUN_00575d70(g_thePlayer)))
        {
            headX = headX->GetNext();
            continue;
        }

        float deltaA = ((TESObjectREFRExt*)kPRef)->FUN_005723b0(g_thePlayer, 0, 0);
        if (deltaA < DAT_01016968 && m_iMapDisplayMode == 0x21)
        {
            headX = headX->GetNext();
            continue;
        }

        if (kPRef != 0)
        {
            if ((m_iMapDisplayMode == 0x21 && !((TESObjectREFRExt*)kPRef)->FUN_00575d10()) ||
                (m_iMapDisplayMode == 0x20 && kPRef->GetParentCell() == g_thePlayer->GetParentCell()))
            {
                dest = kPRef;
            }
        }

        if (dest != 0)
        {
            NiPoint3 kPos12 = *dest->GetPos();
            NiPoint3 pos2B = kPos12;
            if (m_iMapDisplayMode == 0x21)
            {
                pos2B.y -= 1024.0;
            }
            else
            {
                pos2B.y -= 128.0;
            }

            NiPoint3 pt1A;
            NiPoint3 kPt22;

            if (pAdjustNorthRotationCell)
            {
                pAdjustNorthRotationCell->FUN_00555b10(kPos12, kPos12, true);
            }

            pt1A = WorldToMapPosition(kPos12, dest->GetParentWorldSpace());
            kPt22 = WorldToMapPosition(pos2B, dest->GetParentWorldSpace());

            Tile* pStyleVal = (m_iMapDisplayMode == 0x21) ? m_pTiles[5] : m_pTiles[3];
            Tile* ui_ = 0;
            Tile* newTile = 0;

            if (m_iMapDisplayMode == 0x21)
            {
                ui_ = ((MapMenuExt*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, "WorldMapQuestMarkerTemplate", 0);
            }
            else
            {
                ui_ = ((MapMenuExt*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, "LocalMapQuestMarkerTemplate", 0);
            }

            ui_->Set(DAT_011da350, pt1A.x, true);
            ui_->Set(DAT_011da34c, pt1A.y, true);

            char buf[64];
            sprintf(buf, "%s Marker", ((TESObjectREFRExt*)dest)->GetFullName());
            ((TileEx*)ui_)->SetName(buf);

            ui_->Set(0xfcc, "glow_hud_compass_landmark.dds", true);
            ui_->Set(0xfaa, 0x1a);
            ui_->Set(0xfad, 5.0f, true);

            ui_->Set(TraitNameToIDAdd("_LocationName", -1), "Companion", true);

            LBValue* val_ec = (LBValue*)ui_->GetValue(0xff5);
            val_ec->RemoveFromReactions();
            val_ec->FUN_00a09130(0x7d0, pStyleVal, 0xff5);
            val_ec->Refresh(0);

            float fadeXX = m_pMapTile->GetFloat(0xfb1);
            float kScaleY = m_pMapTile->GetFloat(0xfb0);
            fadeXX *= kPt22.x;
            kScaleY *= kPt22.y;

            newTile = FUN_00a00c20(0x387);
            newTile->Init(m_pMapTile, ((TESObjectREFRExt*)kPRef)->GetFullName(), 0);
            newTile->Set(DAT_011da350, kPt22.x, true);
            newTile->Set(DAT_011da34c, kPt22.y, true);
            ((TileEx*)newTile)->SetName(((TESObjectREFRExt*)dest)->GetFullName());

            newTile->Set(0xfa1, fadeXX, true);
            newTile->Set(0xfa2, kScaleY, true);
            newTile->Set(0xfc4, ((TESObjectREFRExt*)kPRef)->GetFullName(), true);
            newTile->Set(0xfba, 200.0f, true);
            newTile->Set(0xfaa, 0x26);
            newTile->Set(0xfad, 2.0f, true);
            newTile->Set(0xfa3, 1);
            newTile->Set(0xfb7, 2);
            newTile->Set(0xfb9, 2);
            newTile->Set(0xfb0, 60.0f, true);
            ((TileEx*)newTile)->FUN_00a07530(2);

            LBValue* xVal = (LBValue*)newTile->GetValue(0xfa1);
            LBValue* valY = (LBValue*)newTile->GetValue(0xfa2);
            xVal->RemoveFromReactions();
            xVal->FUN_00a09130(0x7d0, ui_, 0xfa1);
            xVal->Refresh(0);

            valY->RemoveFromReactions();
            valY->FUN_00a09130(0x7d0, ui_, 0xfa2);
            valY->AppendFloatAction(0x7d1, 60.0f);
            valY->Refresh(0);

            val_ec = (LBValue*)newTile->GetValue(0xff5);
            val_ec->RemoveFromReactions();
            val_ec->FUN_00a09130(0x7d0, pStyleVal, 0xff5);
            val_ec->Refresh(0);
        }

        headX = headX->GetNext();
    }
}
}  // namespace fnv_0079ea30

struct QuestMapPlayer : PlayerCharacter
{
    TESObjectREFR* GetFirstOrFallback();
    void* FUN_008d6f30();
    TESWorldSpace* FUN_00575d70();
};
struct QuestMapReference : TESObjectREFR
{
    bool FUN_00575d10();
    void* FUN_008d6f30();
    TESWorldSpace* FUN_00575d70();
};
struct QuestMapMenu : MapMenu
{
    void FUN_0079f8d0(TESObjectREFR*, TESObjectREFR*, void*, int);
    TESObjectREFR* SelectTarget(TESObjectREFR*, PathingPath*);
    NiPoint3 GetMarkerPosition(NiPoint3, TESWorldSpace*);
    void UpdateQuestMarker();
};
// @fnv 0x0079f360
void QuestMapMenu::UpdateQuestMarker()
{
    TESObjectREFR* reference = m_iMapDisplayMode == 33
                                   ? SelectTarget(g_thePlayer->FUN_00798400(),
                                                  (PathingPath*)((FUN_0079f620_shell*)g_thePlayer)->GetOffsetPointer())
                                   : ((QuestMapPlayer*)g_thePlayer)->GetFirstOrFallback();
    if (reference)
    {
        if (m_iMapDisplayMode == 33)
            FUN_0079f8d0(m_pFirstMapReference, reference, ((FUN_0079f620_shell*)g_thePlayer)->GetOffsetPointer(), 30);
    }
    else if (g_thePlayer->FUN_00798400())
    {
        if ((m_iMapDisplayMode == 33 && !((QuestMapReference*)g_thePlayer->FUN_00798400())->FUN_00575d10()) ||
            (m_iMapDisplayMode == 32 && ((QuestMapReference*)g_thePlayer->FUN_00798400())->FUN_008d6f30() ==
                                            ((QuestMapPlayer*)g_thePlayer)->FUN_008d6f30()))
            reference = g_thePlayer->FUN_00798400();
    }
    if (reference)
    {
        NiPoint3 position;
        NiPoint3 mapPosition;
        position = *reference->GetPos();
        if (pAdjustNorthRotationCell)
            pAdjustNorthRotationCell->FUN_00555b10(position, position, true);
        mapPosition = GetMarkerPosition(position, ((QuestMapReference*)reference)->FUN_00575d70());
        {
            Tile* parent = m_iMapDisplayMode == 33 ? m_pTiles[5] : m_pTiles[3];
            {
                Tile* marker = 0;
                if (m_iMapDisplayMode == 33)
                    marker =
                        ((LBMenu*)DAT_011da368)->AddTileFromTemplate((LBTile*)m_pMapTile, "WorldMapQuestMarkerTemplate", 0);
                else
                    marker =
                        ((LBMenu*)DAT_011da368)->AddTileFromTemplate((LBTile*)m_pMapTile, "LocalMapQuestMarkerTemplate", 0);
                marker->Set(DAT_011da350, mapPosition.x, true);
                marker->Set(DAT_011da34c, mapPosition.y, true);
                marker->Set(0xfcc, "glow_hud_compass_pc_marker.dds", true);
                marker->Set(0xfaa, 28);
                marker->Set(0xfad, 5.0f, true);
                {
                    LBValue* value = (LBValue*)marker->GetValue(0xff5);
                    value->RemoveFromReactions();
                    value->FUN_00a09130(2000, parent, 0xff5);
                    value->Refresh(0);
                }
            }
        }
    }
}

// Pick the target for a reference: the last enabled entry's target, the default target, or the reference itself.

class F7E0Ref
{
  public:
    bool IsPersistent();
};

struct F7E0Flag
{
    bool m_bEnableState;
};

class F7E0FlagList
{
  public:
    unsigned int GetSize();
    F7E0Flag* GetAt(int iIndex);
};

class F7E0TargetList
{
  public:
    unsigned int GetSize();
    F7E0Ref*& GetAt(int iIndex) const;
};

class F7E0Data : public F7E0FlagList
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F7E0TargetList m_kTargets;
};

class F7E0Picker
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
    F7E0Ref* m_pkDefault;

    F7E0Ref* SelectTarget(F7E0Ref* pkRef, F7E0Data* pkData);
};

// Returns the last flagged target from pkData's target list when pkRef is persistent, else m_pkDefault or pkRef; returns 0 for empty data.
// @fnv 0x0079f7e0
F7E0Ref* F7E0Picker::SelectTarget(F7E0Ref* pkRef, F7E0Data* pkData)
{
    F7E0Ref* pkResult = 0;
    if (!pkData || (!pkData->GetSize() && !pkData->m_kTargets.GetSize()))
    {
        pkResult = 0;
    }
    else if (pkRef && pkRef->IsPersistent())
    {
        bool bFound = false;
        for (int i = pkData->GetSize() - 1; !bFound && i >= 0; i--)
        {
            if (pkData->GetAt(i)->m_bEnableState && (unsigned int)i < pkData->m_kTargets.GetSize())
            {
                pkResult = pkData->m_kTargets.GetAt(i);
                bFound = true;
            }
        }
        if (!bFound)
            pkResult = m_pkDefault;
    }
    else
    {
        pkResult = pkRef;
    }
    return pkResult;
}

namespace fnv_0079f8d0 {
struct RefHandle053
{
    TESObjectREFR* FUN_00559450();
};
struct Ref053 : TESObjectREFR
{
    RefHandle053* FUN_00568e50();
    bool FUN_00575d10();
};
struct PathArray053
{
    TESObjectREFR** data;
    unsigned int size, capacity, grow;
    unsigned int FUN_0044ddc0();
    TESObjectREFR*& FUN_00558dd0(unsigned int);
};
class PathingPath
{
  public:
    int unk00, unk04, unk08, unk0c;
    PathArray053 refs;
};
struct Menu053
{
    Tile* AddTileFromTemplate(Tile*, const char*, int);
};
struct Value053
{
    bool IsTraitNonZero();
};
struct Tile053 : Tile
{
    Value053* FUN_0045cd60(int);
};
struct NiPoint2_helper
{
    float x, y;
    NiPoint2_helper(float, float);
};
double __cdecl ForwardFloatAndInt(float, int);
float __cdecl FUN_004579e0(float);
float __cdecl FUN_004b5550(float, float);
struct Map053 : MapMenu
{
    void FUN_0079f8d0(TESObjectREFR*, TESObjectREFR*, PathingPath*, int);
};
// @fnv 0x0079f8d0
void Map053::FUN_0079f8d0(TESObjectREFR* start, TESObjectREFR* end, PathingPath* path, int id)
{
    if (!start || !end || !path)
        return;
    BSSimpleList<Tile*> first;
    NiPoint3 endPos = WorldToMapPosition(*start->GetPos(), start->GetParentWorldSpace());
    Tile* width;
    NiPoint3 height = WorldToMapPosition(*end->GetPos(), end->GetParentWorldSpace());
    Tile* startPos = 0;
    width = 0;
    startPos = ((Menu053*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, "WaypointTemplate", 0);
    startPos->Set(DAT_011da350, endPos.x, true);
    startPos->Set(DAT_011da34c, endPos.y, true);
    startPos->Set(0xfaa, id);
    startPos->Set(0xfa9, 0.0f, true);
    if (((TESForm*)_FNV_GetObjectReference((RefH*)start))->GetFormType() == 0x1c &&
        ((Ref053*)((Ref053*)start)->FUN_00568e50()->FUN_00559450())->FUN_00575d10())
        startPos->Set(0x1004, 1);
    first.AddTail(startPos);
    int waypoints = 0;
    float last;
    int begin = path->refs.FUN_0044ddc0() - 1;
    for (unsigned int i = 0; i < path->refs.FUN_0044ddc0(); i++)
    {
        if (path->refs.FUN_00558dd0(i) == start ||
            ((Ref053*)path->refs.FUN_00558dd0(i))->FUN_00568e50()->FUN_00559450() == start)
            waypoints = i + 1;
        if (path->refs.FUN_00558dd0(i) == end ||
            ((Ref053*)path->refs.FUN_00558dd0(i))->FUN_00568e50()->FUN_00559450() == end)
            begin = i - 1;
    }
    for (int j = waypoints; j <= begin; j++)
    {
        TESObjectREFR* ref = !((Ref053*)path->refs.FUN_00558dd0(j))->FUN_00575d10() ? path->refs.FUN_00558dd0(j) : 0;
        if (!ref)
            ref = ((Ref053*)path->refs.FUN_00558dd0(j))->FUN_00568e50()->FUN_00559450();
        if (ref && !((Ref053*)ref)->FUN_00575d10())
        {
            Tile* middle = ((Menu053*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, "WaypointTemplate", 0);
            NiPoint3 middlePos = WorldToMapPosition(*ref->GetPos(), ref->GetParentWorldSpace());
            middle->Set(DAT_011da350, middlePos.x, true);
            middle->Set(DAT_011da34c, middlePos.y, true);
            middle->Set(0xfaa, id);
            if (((Ref053*)((Ref053*)path->refs.FUN_00558dd0(j))->FUN_00568e50()->FUN_00559450())->FUN_00575d10())
                middle->Set(0x1004, 1);
            first.AddTail(middle);
        }
    }
    width = ((Menu053*)DAT_011da368)->AddTileFromTemplate(m_pMapTile, "WaypointTemplate", 0);
    width->Set(DAT_011da350, height.x, true);
    width->Set(DAT_011da34c, height.y, true);
    width->Set(0xfaa, id);
    width->Set(0xfa9, 0.0f, true);
    first.AddTail(width);
    last = m_pMapTile ? m_pMapTile->GetFloat(0xfcd) : 0.0f;
    float finish = m_pMapTile ? m_pMapTile->GetFloat(0xfce) : 0.0f;
    for (BSSimpleList<Tile*>* node = &first; node && node->GetItem() && node->GetNext(); node = node->GetNext())
    {
        Tile* line = ((Menu053*)DAT_011da368)->AddTileFromTemplate(node->GetItem(), "PathLineTemplate", 0);
        NiPoint2_helper b(node->GetItem()->GetFloat(DAT_011da350), node->GetItem()->GetFloat(DAT_011da34c));
        NiPoint2_helper a(node->GetNext()->GetItem()->GetFloat(DAT_011da350),
                          node->GetNext()->GetItem()->GetFloat(DAT_011da34c));
        line->Set(0xfaa, id);
        line->Set(0x1004,
                  FUN_004579e0(ForwardFloatAndInt((a.x - b.x) * last, 2) + ForwardFloatAndInt((a.y - b.y) * finish, 2)),
                  true);
        line->Set(0xffa, -FUN_004b5550(a.y - b.y, a.x - b.x), true);
        if (((Tile053*)line)->FUN_0045cd60(0x1004)->IsTraitNonZero())
            line->Set(0xfcc, "Interface\\Worldmap\\waypoint_path_interior.dds", true);
    }
}
}  // namespace fnv_0079f8d0

struct InsertTile;
struct InsertAction
{
    void RemoveFromReactions();
    void FUN_00a09130(int, InsertTile*, int);
    void AppendFloatAction(int, float);
    void Refresh(int);
};
struct CloneTile
{
    InsertTile* AddTileFromTemplate();
};
struct InsertTile
{
    CloneTile* FUN_00a03c90(InsertTile*, const char*, int);
    void* FUN_00a00f30(int);
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
    float FUN_00a011b0(int);
    InsertAction* FindTraitValue(int);
};
struct FUN_007a62e0
{
    InsertTile* tile;
    void* data;
    unsigned int flags;
    FUN_007a62e0(InsertTile*, void* const&);
};
typedef int(__cdecl* InsertCompare)(FUN_007a62e0*, FUN_007a62e0*);
struct InsertList
{
    unsigned int first, last;
    void FUN_007a7eb0(FUN_007a62e0*, InsertCompare);
    void FUN_00905820(FUN_007a62e0* const&);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern const char DAT_0106f860[];
extern int __cdecl TraitNameToIDAdd(const char*, int);
struct ListInserter
{
    unsigned int unk00;
    InsertList items;
    InsertTile* root;
    unsigned int unk10, unk14;
    const char* templateName;
    unsigned short nextID, unk1e;
    bool FUN_007242c0(unsigned int);
    void FUN_007a6480();
    void AccumulateTileHeight(InsertTile*);
    void FUN_007a6920();
    int GetRaceCount();
    InsertTile* InsertTileFromTemplate(void*, const char*, InsertCompare, const char*);
};
// @fnv 0x007a1dd0
InsertTile* ListInserter::InsertTileFromTemplate(void* data, const char* text, InsertCompare compare,
                                                 const char* source)
{
    if (root && (templateName || source))
    {
        InsertTile* pTile = root->FUN_00a03c90(root, source ? source : templateName, 0)->AddTileFromTemplate();
        InsertAction* action;
        if (!pTile->FUN_00a00f30(0xfaa))
            pTile->FUN_00700320(0xfaa, -1);
        if (text)
            pTile->FUN_00a01350(0xfc4, text, true);
        if (compare)
        {
            items.FUN_007a7eb0(new FUN_007a62e0(pTile, data), compare);
            if (FUN_007242c0(0))
                FUN_007a6480();
        }
        else
        {
            items.FUN_00905820(new FUN_007a62e0(pTile, data));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(pTile);
                FUN_007a6920();
            }
            pTile->FUN_00700320(0xfac, nextID++);
        }
        if (GetRaceCount() == 1 && root->FUN_00a011b0(TraitNameToIDAdd(DAT_0106f860, -1)) > 0.0)
        {
            action = root->FindTraitValue(0xfb0);
            action->RemoveFromReactions();
            action->FUN_00a09130(2000, pTile, 0xfb0);
            action->AppendFloatAction(2003, root->FUN_00a011b0(TraitNameToIDAdd(DAT_0106f860, -1)));
            action->Refresh(0);
        }
        return pTile;
    }
    else
        return 0;
}

struct MyTile;
struct MyValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int, MyTile*, int);
    void AppendFloatAction(int, float);
    void Refresh(int);
};
struct MyTile
{
    int FUN_00a00f30(int);
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, int);
};
struct MyMaker
{
    MyTile* AddTileFromTemplate();
};
struct MyParent
{
    MyMaker* FUN_00a03c90(MyParent*, const char*, int);
    MyValue* FindTraitValue(int);
    float FUN_00a011b0(int);
};
struct MyItem
{
    MyTile* tile;
    int object;
    char isFilteredOut;
    MyItem(MyTile* t, int* o);
};
struct MyList
{
    MyItem* item;
    MyList* next;
    void FUN_007a7eb0(MyItem*, int (*)(MyItem*, MyItem*));
    void AddTail(MyItem* const&);
};
int __cdecl TraitNameToIDAdd(const char*, int);
extern const char _kListBoxNumFiltered[];
extern double _DAT_01012060;

struct MyBox
{
    virtual void vfn_00();
    MyList list;
    MyParent* parentTile;
    MyTile* selected;
    MyTile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int);
    void AccumulateTileHeight(MyTile*);
    void AssignTileIndices();
    void FUN_007a7080();
    int GetRaceCount();
    MyTile* CreateListItem(int item, const char* text, int (*sortFunc)(MyItem*, MyItem*), const char* altTemplate);
};

// @fnv 0x007a2930
MyTile* MyBox::CreateListItem(int item, const char* text, int (*sortFunc)(MyItem*, MyItem*), const char* altTemplate)
{
    if (parentTile && (templateName || altTemplate))
    {
        MyTile* tile_2 =
            parentTile->FUN_00a03c90(parentTile, altTemplate ? altTemplate : templateName, 0)->AddTileFromTemplate();
        if (!tile_2->FUN_00a00f30(4010))
            tile_2->FUN_00700320(4010, -1);
        if (text)
            tile_2->FUN_00a01350(4036, text, 1);
        if (sortFunc)
        {
            list.FUN_007a7eb0(new MyItem(tile_2, &item), sortFunc);
            if (FUN_007242c0(0))
                AssignTileIndices();
        }
        else
        {
            list.AddTail(new MyItem(tile_2, &item));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(tile_2);
                FUN_007a7080();
            }
            tile_2->FUN_00700320(4012, itemCount++);
        }
        if (GetRaceCount() == 1 && parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)) > _DAT_01012060)
        {
            MyValue* value = parentTile->FindTraitValue(4016);
            value->RemoveFromReactions();
            value->FUN_00a09130(2000, tile_2, 4016);
            value->AppendFloatAction(2003, parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)));
            value->Refresh(0);
        }
        return tile_2;
    }
    else
    {
        return 0;
    }
}

struct NoteFilterTile : Tile
{
    float FUN_00a011b0(int);
    void FUN_00715c60(int, int);
};
struct NoteFilterItem
{
    NoteFilterTile* tile;
    BGSNote* note;
    bool filtered;
};
struct NoteFilterList
{
    NoteFilterItem* item;
    NoteFilterList* next;
    NoteFilterItem*& FUN_006815c0();
    NoteFilterList* FUN_00726070();
};
struct NoteFilterBox : NoteFilterList
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual NoteFilterTile* GetTile(int, bool);
    NoteFilterTile* parent;
    NoteFilterTile* selected;
    Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    float height;
    void AccumulateTileHeight(NoteFilterTile*);
    void FUN_007a7080();
    NoteFilterTile* FUN_007a6220();
    void UpdateHighlightBox();
    void ApplyNoteFilter(bool (*filter)(BGSNote*));
};
// @fnv 0x007a2e30
void NoteFilterBox::ApplyNoteFilter(bool (*filter)(BGSNote*))
{
    int filteredCount = 0;
    int selectedIndex = -1;
    static int numFiltered = TraitNameToIDAdd("_num_filtered", -1);
    count = 0;
    height = 0.0f;
    for (NoteFilterList* node = this; node && node->FUN_006815c0(); node = node->FUN_00726070())
    {
        node->FUN_006815c0()->filtered = filter && filter(node->FUN_006815c0()->note);
        if (node->FUN_006815c0()->filtered)
        {
            if (node->FUN_006815c0()->tile == selected)
            {
                selectedIndex = (int)node->FUN_006815c0()->tile->FUN_00a011b0(0xfac);
                selected = 0;
            }
            node->FUN_006815c0()->tile->Set(0xfac, -1);
            ++filteredCount;
        }
        else
        {
            if (selectedIndex >= 0 && count == selectedIndex)
                selected = node->FUN_006815c0()->tile;
            node->FUN_006815c0()->tile->Set(0xfac, count++);
            AccumulateTileHeight(node->FUN_006815c0()->tile);
        }
    }
    parent->FUN_00715c60(numFiltered, filteredCount);
    FUN_007a7080();
    if (!selected && selectedIndex >= 0)
        selected = GetTile(selectedIndex, false);
    if (!selected && selectedIndex >= 0)
        selected = FUN_007a6220();
    UpdateHighlightBox();
}

int __cdecl TraitNameToIDAdd(const char* pcName, int iDefault);

class Tile7A3
{
  public:
    void SetInt(int m_iValueId, int iValue);
};

class MenuItem7A3
{
  public:
    void FUN_007a30e0(bool bEnabled);

    int unk00;
    int unk04;
    int unk08;
    Tile7A3* m_pkTile;
};

// Sets the _enabled trait on the menu item's tile to the given boolean value.
// @fnv 0x007a30e0
void MenuItem7A3::FUN_007a30e0(bool bEnabled)
{
    static int s_iEnabledTrait = TraitNameToIDAdd("_enabled", -1);
    m_pkTile->SetInt(s_iEnabledTrait, bEnabled);
}

int TraitNameToID(const char* apName);
float FUN_0040ebd0(float a, float b);

struct ScrollTile_7a3580
{
    void Set(int aiTrait, float afValue, bool abFlag);
    void SetFloat(int aiTrait, float afValue);
    float GetFloatTrait(int aiTrait, ScrollTile_7a3580* apTile);
};

struct MenuStandIn_7a3580
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int aiValue);
};

struct TileStandIn_7a3580
{
    TileStandIn_7a3580* GetMenuTile();
    MenuStandIn_7a3580* GetMenu();
};

struct IMStandIn_7a3580
{
    void Notify(ScrollTile_7a3580* apTile, int aiID, int aiArg);
};

IMStandIn_7a3580* GetInterfaceManager_7a3580();
bool IsMenuMode_7a3580();

struct ListBoxStandIn_7a3580
{
    virtual void SetSelected(ScrollTile_7a3580* apTile);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual ScrollTile_7a3580* GetTileAt(unsigned int auiIndex);

    int unk04;
    int unk08;
    TileStandIn_7a3580* pListTile;
    int unk10;
    ScrollTile_7a3580* m_pHighlightedTile;
    int unk18;
    int unk1c;
    int unk20;
    float fScrollPos;
    float fScrollValue;

    unsigned int GetCount(int aiArg);
    void UpdateScrollSelection(bool abArg);
};

// @fnv 0x007a3580
void ListBoxStandIn_7a3580::UpdateScrollSelection(bool abArg)
{
    ScrollTile_7a3580* pTile = 0;
    if (pListTile && m_pHighlightedTile)
    {
        m_pHighlightedTile->Set(TraitNameToID("_current_value"), fScrollValue, false);
        m_pHighlightedTile->SetFloat(TraitNameToID("_SetInCode"), 1.0f);
        pTile = GetTileAt((unsigned int)FUN_0040ebd0(fScrollPos, GetCount(0) - 1.0));
        GetInterfaceManager_7a3580()->Notify(pTile, 0xfc3, abArg);
        SetSelected(pTile);
        if (!IsMenuMode_7a3580())
        {
            if (pTile)
            {
                pListTile->GetMenuTile()->GetMenu()->v14(pTile->GetFloatTrait(0xfaa, pTile));
            }
            SetSelected(0);
        }
    }
}

struct InsertBox
{
    virtual void vfn_00();
    LBList list;
    LBTile* parentTile;
    Tile* selected;
    Tile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int);
    void AccumulateTileHeight(Tile*);
    int GetRaceCount();
    void FUN_007a7260();
    void FUN_007a7700();
    Tile* FUN_007a3820(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate);
};
// Creates a tile for an item via the parent menu, sets its text and value, adds it to the list (sorted or appended), and updates the filtered-count value.
// @fnv 0x007a3820
Tile* InsertBox::FUN_007a3820(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate)
{
    if (parentTile && (templateName || altTemplate))
    {
        Tile* tile =
            ((LBMenu*)parentTile->GetMenu())->AddTileFromTemplate(parentTile, altTemplate ? altTemplate : templateName, 0);
        if (!tile->GetValue(0xfaa))
            tile->Set(0xfaa, -1);
        if (text)
            tile->Set(0xfc4, text, true);
        if (sortFunc)
        {
            list.FUN_007a7eb0(new LBItem(tile, &item), sortFunc);
            if (FUN_007242c0(0))
                FUN_007a7260();
        }
        else
        {
            list.AddTail(new LBItem(tile, &item));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(tile);
                FUN_007a7700();
            }
            tile->Set(0xfac, itemCount++);
        }
        if (GetRaceCount() == 1 && parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)) > _DAT_01012060)
        {
            LBValue* value = parentTile->FindTraitValue(0xfb0);
            value->RemoveFromReactions();
            value->FUN_00a09130(0x7d0, tile, 0xfb0);
            value->AppendFloatAction(0x7d3, parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)));
            value->Refresh(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}

namespace fnv_007a44e0 {
struct InsertBox : LBox
{
    void ProcessEntries();
    void FUN_007a7d80();
    Tile* FUN_007a44e0(int object, const char* text, int (*sort)(LBItem*, LBItem*), const char* alt);
};
// @fnv 0x007a44e0
Tile* InsertBox::FUN_007a44e0(int object, const char* text, int (*sort)(LBItem*, LBItem*), const char* alt)
{
    if (parentTile && (templateName || alt))
    {
        Tile* tile_2 = ((LBMenu*)parentTile->GetMenu())->AddTileFromTemplate(parentTile, alt ? alt : templateName, 0);
        LBValue* value;
        if (!tile_2->GetValue(0xfaa))
            tile_2->Set(0xfaa, -1);
        if (text)
            tile_2->Set(0xfc4, text, true);
        if (sort)
        {
            list.FUN_007a7eb0(new LBItem(tile_2, &object), sort);
            if (FUN_007242c0(0))
                ProcessEntries();
        }
        else
        {
            {
                list.AddTail(new LBItem(tile_2, &object));
                if (FUN_007242c0(0))
                {
                    AccumulateTileHeight(tile_2);
                    FUN_007a7d80();
                }
                tile_2->Set(0xfac, itemCount++);
            }
        }
        if (GetRaceCount() == 1 && parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)) > 0.0)
        {
            value = parentTile->FindTraitValue(0xfb0);
            value->RemoveFromReactions();
            value->FUN_00a09130(0x7d0, tile_2, 0xfb0);
            value->AppendFloatAction(0x7d3, parentTile->FUN_00a011b0(TraitNameToIDAdd(_kListBoxNumFiltered, -1)));
            value->Refresh(0);
        }
        return tile_2;
    }
    else
        return 0;
}
}  // namespace fnv_007a44e0

struct FilterItem
{
    LBTile* tile;
    BGSQuestObjective* object;
    bool filtered;
};
struct FilterNode
{
    FilterItem* item;
    FilterNode* next;
    FilterItem*& FUN_006815c0();
    FilterNode* FUN_00726070();
};
struct FilterVirtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual LBTile* v5(int, bool);
};
struct FilterTile
{
    void FUN_00715c60(int, int);
};
struct FilterHost : FilterVirtual, FilterNode
{
    FilterTile* parent;
    LBTile* selected;
    LBTile* scroll;
    const char* templateName;
    unsigned short count;
    float height;
    void AccumulateTileHeight(LBTile*);
    void FUN_007a7d80();
    LBTile* FUN_007a6280();
    void UpdateSelectionState();
    void ApplyObjectiveFilter(bool (*predicate)(BGSQuestObjective*));
};
struct FilterItemTile
{
    void FUN_00700320(int, int);
};
// Marks each item filtered by predicate, hides filtered tiles, renumbers visible ones, updates the filtered count and reselects a tile.
// @fnv 0x007a49e0
void FilterHost::ApplyObjectiveFilter(bool (*predicate)(BGSQuestObjective*))
{
    int filteredCount = 0;
    int selectedIndex = -1;
    static int numFilteredTrait = TraitNameToIDAdd("_num_filtered", -1);
    count = 0;
    height = 0.0f;
    for (FilterNode* node = this; node && node->FUN_006815c0(); node = node->FUN_00726070())
    {
        node->FUN_006815c0()->filtered = predicate && predicate(node->FUN_006815c0()->object);
        if (node->FUN_006815c0()->filtered)
        {
            if (node->FUN_006815c0()->tile == selected)
            {
                selectedIndex = (int)node->FUN_006815c0()->tile->FUN_00a011b0(0xfac);
                selected = 0;
            }
            ((FilterItemTile*)node->FUN_006815c0()->tile)->FUN_00700320(0xfac, -1);
            filteredCount++;
        }
        else
        {
            if (selectedIndex >= 0 && count == selectedIndex)
                selected = node->FUN_006815c0()->tile;
            ((FilterItemTile*)node->FUN_006815c0()->tile)->FUN_00700320(0xfac, count++);
            AccumulateTileHeight(node->FUN_006815c0()->tile);
        }
    }
    parent->FUN_00715c60(numFilteredTrait, filteredCount);
    FUN_007a7d80();
    if (!selected && selectedIndex >= 0)
        selected = v5(selectedIndex, false);
    if (!selected && selectedIndex >= 0)
        selected = FUN_007a6280();
    UpdateSelectionState();
}

struct FUN_007a5730_node
{
    FNVEmitter** Slot();
    FUN_007a5730_node* Next();
};

struct FUN_007a5730_tile
{
    void Probe(int);
    void FUN_00700320(int, int);
};

struct FUN_007a5730_item
{
    FUN_007a5730_tile* tile;
    int object;
    unsigned char filtered;
};

struct FUN_007a5730_parent
{
    void Add(int, int);
};

struct FUN_007a5730_self
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual FUN_007a5730_tile* vfn_14(int, bool);
    void* headItem;
    void* headNext;
    FUN_007a5730_parent* parentTile;
    FUN_007a5730_tile* selected;
    int selIdx;
    int unk18;
    unsigned short count;
    float scroll;
    FUN_007a5730_tile* Pick();
    void Refresh();
    void Finish();
    void Relink(FUN_007a5730_tile*);
};

int __cdecl Stamp();
int __cdecl LookupSetting(const char*, int);

// Applies filter to each item, marks filtered items, updates selection and counts, then refreshes and finishes the list.
// @fnv 0x007a5730
void FUN_007a5730_shell::FUN_007a5730(bool (*filter)(TESChallenge*))
{
    int filteredCount = 0;
    int selIdx = -1;
    static int numFiltered = LookupSetting("_num_filtered", -1);
    ((FUN_007a5730_self*)this)->count = 0;
    ((FUN_007a5730_self*)this)->scroll = 0.0f;
    FUN_007a5730_node* node = this ? (FUN_007a5730_node*)((char*)this + 4) : 0;
    for (; node && *node->Slot(); node = node->Next())
    {
        ((FUN_007a5730_item*)*node->Slot())->filtered =
            (filter && filter((TESChallenge*)((FUN_007a5730_item*)*node->Slot())->object)) ? 1 : 0;
        if (((FUN_007a5730_item*)*node->Slot())->filtered)
        {
            if (((FUN_007a5730_item*)*node->Slot())->tile == ((FUN_007a5730_self*)this)->selected)
            {
                ((FUN_007a5730_item*)*node->Slot())->tile->Probe(0xfac);
                selIdx = Stamp();
                ((FUN_007a5730_self*)this)->selected = 0;
            }
            ((FUN_007a5730_item*)*node->Slot())->tile->FUN_00700320(0xfac, -1);
            filteredCount++;
        }
        else
        {
            if (selIdx >= 0 && ((FUN_007a5730_self*)this)->count == selIdx)
                ((FUN_007a5730_self*)this)->selected = ((FUN_007a5730_item*)*node->Slot())->tile;
            ((FUN_007a5730_item*)*node->Slot())->tile->FUN_00700320(0xfac, ((FUN_007a5730_self*)this)->count++);
            ((FUN_007a5730_self*)this)->Relink(((FUN_007a5730_item*)*node->Slot())->tile);
        }
    }
    ((FUN_007a5730_self*)this)->parentTile->Add(numFiltered, filteredCount);
    ((FUN_007a5730_self*)this)->Refresh();
    if (((FUN_007a5730_self*)this)->selected == 0 && selIdx >= 0)
        ((FUN_007a5730_self*)this)->selected = ((FUN_007a5730_self*)this)->vfn_14(selIdx, false);
    if (((FUN_007a5730_self*)this)->selected == 0 && selIdx >= 0)
        ((FUN_007a5730_self*)this)->selected = ((FUN_007a5730_self*)this)->Pick();
    ((FUN_007a5730_self*)this)->Finish();
}

struct FUN_007a6b00_item
{
    Tile* displayTile;
    unsigned int metadata04;
    unsigned char inactive;
};
struct FUN_007a6b00_listNode : SL
{
    FUN_007a6b00_item** FUN_006815c0();
    FUN_007a6b00_listNode* FUN_00726070();
};
struct FUN_007a6b00_shell : FUN_007a1c90
{
    void AssignTileIndices();
    void AccumulateTileHeight(Tile*);
    void FUN_007a7080();
    void UpdateHighlightBox();
};
// Resets f1c and f20, assigns sequential indices to active display tiles via Set(0xfac, ...), then calls FUN_007a7080 and UpdateHighlightBox.
// @fnv 0x007a6b00
void FUN_007a6b00_shell::AssignTileIndices()
{
    f1c = 0;
    f20 = 0.0f;
    for (FUN_007a6b00_listNode* node = reinterpret_cast<FUN_007a6b00_listNode*>(static_cast<SL*>(this));
         node != 0 && *node->FUN_006815c0() != 0; node = node->FUN_00726070())
    {
        if ((*node->FUN_006815c0())->inactive == 0)
        {
            (*node->FUN_006815c0())->displayTile->Set(0xfac, static_cast<unsigned short>(f1c++));
            AccumulateTileHeight((*node->FUN_006815c0())->displayTile);
        }
    }
    FUN_007a7080();
    UpdateHighlightBox();
}

struct Tile_00a011b0 : Tile
{
    float FUN_00a011b0(int m_iValueId);  // the tile's float value for a trait
};
float FUN_004e4430(float fValue);
int FUN_00647b70(int iA, int iB);
struct FUN_007a7700_Menu
{
    char pad00[0xc];
    Tile_00a011b0* m_pHighlightedTile;
    char pad10[4];
    Tile* pItemCount;
    char pad18[8];
    float fScrollRange;
    unsigned int FUN_007a71b0();
    void FUN_007a7700();
};
// Computes the scroll page count from fScrollRange and the tile's page size, then stores _scroll_delta and _number_of_items on the tiles.
// @fnv 0x007a7700
void FUN_007a7700_Menu::FUN_007a7700()
{
    if (m_pHighlightedTile)
    {
        float fPageSize = m_pHighlightedTile->FUN_00a011b0(0xfb0);
        int iCount = 1;
        if (fScrollRange > 0.0 && fPageSize > 0.0)
        {
            if (fScrollRange > fPageSize)
                iCount =
                    FUN_00647b70((int)FUN_004e4430(FUN_007a71b0() * (fScrollRange - fPageSize) / fScrollRange) + 1, 2);
            if (iCount > 1)
                m_pHighlightedTile->Set(Tile::GetTraitID("_scroll_delta"), (fScrollRange - fPageSize) / (iCount - 1),
                                        true);
        }
        if (pItemCount)
            pItemCount->Set(Tile::GetTraitID("_number_of_items"), iCount);
    }
}

struct SelectTile;
struct SelectAction
{
    void FUN_00a09130(int, SelectTile*, int);
    void Refresh(int);
};
struct SelectTile
{
    SelectAction* FUN_00a00f30(int);
    bool FUN_0071aa80();
    void FUN_0071aa60(bool);
    void FUN_00a07530(int);
    SelectTile* FUN_00a03da0(const char*);
    void FUN_00700320(int, int);
};
extern const char DAT_0106f8c0[], DAT_0106f8ac[], DAT_0106f898[], DAT_0106f894[], DAT_0106f88c[], DAT_0106f884[],
    DAT_0106f87c[];
extern int __cdecl TraitNameToIDAdd(const char*, int);
extern SelectTile* __cdecl FUN_00a08b20(SelectTile*, const char*);
struct SelectionList
{
    unsigned int unk00, unk04, unk08;
    SelectTile* root;
    SelectTile* selected;
    void UpdateSelectionState();
};
// Updates the root tile's actions and child tiles based on whether a selected tile exists and whether it is enabled.
// @fnv 0x007a7a60
void SelectionList::UpdateSelectionState()
{
    static int DAT_011da4bc = TraitNameToIDAdd(DAT_0106f8c0, -1);
    static int DAT_011da4b8 = TraitNameToIDAdd(DAT_0106f8ac, -1);
    if (root)
    {
        if (selected)
        {
            SelectAction* first = root->FUN_00a00f30(DAT_011da4bc);
            SelectAction* second6 = root->FUN_00a00f30(DAT_011da4b8);
            first->FUN_00a09130(2000, selected, 0xfa2);
            first->Refresh(0);
            second6->FUN_00a09130(2000, selected, 0xfb0);
            second6->Refresh(0);
            if (selected->FUN_0071aa80())
            {
                SelectTile* container = FUN_00a08b20(root, DAT_0106f898);
                if (container)
                {
                    SelectTile* part = container->FUN_00a03da0(DAT_0106f894);
                    if (part)
                    {
                        part->FUN_0071aa60(true);
                        part->FUN_00a07530(8);
                        part = container->FUN_00a03da0(DAT_0106f88c);
                        part->FUN_0071aa60(true);
                        part->FUN_00a07530(8);
                        part = container->FUN_00a03da0(DAT_0106f884);
                        part->FUN_0071aa60(true);
                        part->FUN_00a07530(8);
                        part = container->FUN_00a03da0(DAT_0106f87c);
                        part->FUN_0071aa60(true);
                        part->FUN_00a07530(8);
                    }
                    container->FUN_0071aa60(true);
                    container->FUN_00a07530(8);
                }
            }
            else
            {
                SelectTile* containerOff4 = FUN_00a08b20(root, DAT_0106f898);
                if (containerOff4)
                {
                    SelectTile* partOff3 = containerOff4->FUN_00a03da0(DAT_0106f894);
                    if (partOff3)
                    {
                        partOff3->FUN_0071aa60(false);
                        partOff3->FUN_00a07530(8);
                        partOff3 = containerOff4->FUN_00a03da0(DAT_0106f88c);
                        partOff3->FUN_0071aa60(false);
                        partOff3->FUN_00a07530(8);
                        partOff3 = containerOff4->FUN_00a03da0(DAT_0106f884);
                        partOff3->FUN_0071aa60(false);
                        partOff3->FUN_00a07530(8);
                        partOff3 = containerOff4->FUN_00a03da0(DAT_0106f87c);
                        partOff3->FUN_0071aa60(false);
                        partOff3->FUN_00a07530(8);
                    }
                    containerOff4->FUN_0071aa60(false);
                    containerOff4->FUN_00a07530(8);
                }
            }
        }
        else
        {
            root->FUN_00700320(DAT_011da4bc, -1);
            root->FUN_00700320(DAT_011da4b8, 0);
        }
    }
}

extern double _gModifierZero;
float __cdecl FUN_004e4430(float);
int __cdecl FUN_00647b70(int, int);

struct ScrollTile : public Tile
{
    float GetFloat(int);
};

struct ScrollList
{
    int unk00;
    int unk04;
    int unk08;
    ScrollTile* m_pHighlightedTile;
    int unk10;
    Tile* pItemCount;
    int unk18;
    int unk1c;
    float fTotalHeight;
    unsigned int GetVisibleCount();
    void FUN_007a7d80();
};

// Computes a scroll delta from the tile's float value and total height, stores it on the tile, and sets the item count on pItemCount.
// @fnv 0x007a7d80
void ScrollList::FUN_007a7d80()
{
    if (m_pHighlightedTile)
    {
        float m_fGlyphExtent = m_pHighlightedTile->GetFloat(0xfb0);
        int iCount = 1;
        if (fTotalHeight > _gModifierZero && m_fGlyphExtent > _gModifierZero)
        {
            if (fTotalHeight > m_fGlyphExtent)
            {
                iCount =
                    FUN_00647b70((int)FUN_004e4430(GetVisibleCount() * (fTotalHeight - m_fGlyphExtent) / fTotalHeight) + 1, 2);
            }
            if (iCount > 1)
            {
                m_pHighlightedTile->Set(Tile::GetTraitID("_scroll_delta"), (fTotalHeight - m_fGlyphExtent) / (iCount - 1),
                                        true);
            }
        }
        if (pItemCount)
        {
            pItemCount->Set(Tile::GetTraitID("_number_of_items"), iCount);
        }
    }
}

struct FUN_006f48b0
{
    int d[14];
    FUN_006f48b0();
    ~FUN_006f48b0();
    float GetPathLength();
};
typedef FUN_006f48b0 D6200Obj;
bool __cdecl BuildPathWithDoors(void* a, void* b, D6200Obj* o, int c, int d);
// Builds a D6200Obj via BuildPathWithDoors; on success writes o.GetPathLength() to out and returns true, otherwise writes 0.0f and returns false.
// @fnv 0x006d6200
bool __cdecl GetObjectFloat(void* apFirst, void* apSecond, float* pfResult)
{
    D6200Obj o;
    if (BuildPathWithDoors(apFirst, apSecond, &o, 0, 1))
    {
        *pfResult = o.GetPathLength();
        return true;
    }
    else
    {
        *pfResult = 0.0f;
        return false;
    }
}

namespace n79 {
struct Item
{
    virtual ~Item();
    void FUN_009ff690();
};
struct ItemList
{
    void FUN_0057c730(Item** pp);
};
struct Mgr
{
    int m_iWordAt00;
    ItemList m_kNode;
    Item* FUN_00a03eb0(int type);
};
}
class Owner79
{
  public:
    char pad[0x84];
    n79::Mgr* m_84;
    void FUN_0079f6f0();
};
// @fnv 0x0079f6f0
void Owner79::FUN_0079f6f0()
{
    n79::Item* p = m_84->FUN_00a03eb0(0x1c);
    if (p)
    {
        m_84->m_kNode.FUN_0057c730(&p);
        p->FUN_009ff690();
        delete p;
    }
    p = m_84->FUN_00a03eb0(0x1e);
    while (p)
    {
        m_84->m_kNode.FUN_0057c730(&p);
        p->FUN_009ff690();
        delete p;
        p = m_84->FUN_00a03eb0(0x1e);
    }
}

struct ListBoxEnable
{
    virtual void vfn_00();
    int unk04;
    int unk08;
    Tile* pParentTile;
    void FUN_007a2350(bool bEnabled);
};

// Stores bEnabled into pParentTile under the _enabled trait key.
// @fnv 0x007a2350
void ListBoxEnable::FUN_007a2350(bool bEnabled)
{
    static int kListBoxEnabled = GetTileValueID("_enabled", -1);
    pParentTile->Set(kListBoxEnabled, bEnabled);
}

struct FUN_007a3d20_tile;

struct FUN_007a3d20_item
{
    FUN_007a3d20_tile* tile;
    int object;
    unsigned char isFilteredOut;
};

struct FUN_007a3d20_node
{
    FUN_007a3d20_item** FUN_006815c0();
    FUN_007a3d20_node* FUN_00726070();
    FUN_007a3d20_item* item;
    FUN_007a3d20_node* next;
};

struct FUN_007a3d20_tile
{
    void FUN_00700320(int, int);
    void FUN_00a011b0(int);
};

struct FUN_007a3d20_parent
{
    void FUN_00715c60(int, int);
};

int __cdecl FUN_00ec62c0();
int __cdecl TraitNameToIDAdd(const char*, int);

struct FUN_007a3d20_cls
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual FUN_007a3d20_tile* vfn14(int, int);

    FUN_007a3d20_node list;
    FUN_007a3d20_parent* parentTile;
    FUN_007a3d20_tile* selected;
    FUN_007a3d20_tile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    float unk20;

    void FUN_007a3d20(bool (*pfnFilter)(int));
    void FUN_007a7700();
    FUN_007a3d20_tile* FUN_007a6250();
    void FUN_007a73e0();
    void AccumulateTileHeight(FUN_007a3d20_tile*);
};

// @fnv 0x007a3d20
void FUN_007a3d20_cls::FUN_007a3d20(bool (*pfnFilter)(int))
{
    int count = 0;
    int selIdx = -1;
    static int numFiltered = TraitNameToIDAdd("_num_filtered", -1);

    this->itemCount = 0;
    this->unk20 = 0.0f;

    for (FUN_007a3d20_node* node = this ? &this->list : 0; node != 0 && *node->FUN_006815c0() != 0;
         node = node->FUN_00726070())
    {
        (*node->FUN_006815c0())->isFilteredOut = (pfnFilter != 0 && pfnFilter((*node->FUN_006815c0())->object)) ? 1 : 0;

        if ((*node->FUN_006815c0())->isFilteredOut)
        {
            if ((*node->FUN_006815c0())->tile == this->selected)
            {
                (*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac);
                selIdx = FUN_00ec62c0();
                this->selected = 0;
            }
            (*node->FUN_006815c0())->tile->FUN_00700320(0xfac, -1);
            count++;
        }
        else
        {
            if (selIdx >= 0 && this->itemCount == selIdx)
                this->selected = (*node->FUN_006815c0())->tile;
            (*node->FUN_006815c0())->tile->FUN_00700320(0xfac, this->itemCount++);
            this->AccumulateTileHeight((*node->FUN_006815c0())->tile);
        }
    }

    this->parentTile->FUN_00715c60(numFiltered, count);
    this->FUN_007a7700();
    if (this->selected == 0 && selIdx >= 0)
        this->selected = this->vfn14(selIdx, 0);
    if (this->selected == 0 && selIdx >= 0)
        this->selected = this->FUN_007a6250();
    this->FUN_007a73e0();
}

int TraitNameToIDAdd(const char* pszName, int iIndex);

class TileOwnerW
{
  public:
    void FUN_007a59a0(bool bValue);

    char m_pad00[0xc];
    Tile* m_pkTile;
};

// Caches the trait index for "_enabled" and sets that trait on m_pkTile to bValue.
// @fnv 0x007a59a0
void TileOwnerW::FUN_007a59a0(bool abEnabled)
{
    static int s_iTrait = TraitNameToIDAdd("_enabled", -1);
    m_pkTile->Set(s_iTrait, abEnabled);
}

struct AQ
{
    void FUN_007a30e0(int);
};
struct BQ
{
    void FUN_007a2350(int);
};
struct CQ
{
    void SetEnabledTrait(int);
    int FUN_00825c00();
};
struct RQ
{
    int FUN_0045cd60();
};
bool FUN_004b71d0();
struct OwnQ
{
    virtual void v0(), v1(), v2(), v3(), v4();
    virtual void Notify(int a, int b);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80,
        unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0,
        unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100,
        unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    BQ kB130;
    int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    AQ kA160;
    int unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198,
        unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    CQ kC1c0;
    void HandleEvent(int iEvent, RQ* pRef);
};
// Dispatches iEvent to call member methods, update fields, or notify when pRef and kC1c0 return equal values.
// @fnv 0x00799690
void OwnQ::HandleEvent(int iEvent, RQ* pRef)
{
    switch (iEvent)
    {
    case 14:
        kA160.FUN_007a30e0(1);
        break;
    case 15:
        kB130.FUN_007a2350(1);
        kC1c0.SetEnabledTrait(0);
        break;
        break;
    case 24:
        if (FUN_004b71d0() || !unk90)
            unk94 = 0;
        break;
    case -1:
        if (pRef && pRef->FUN_0045cd60() == kC1c0.FUN_00825c00())
            Notify(0xf, 0);
        break;
    }
}

namespace fnv_0079a660 {
struct AMPoint
{
    float x, y, z;
};

class AMSoundHandle
{
  public:
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    AMSoundHandle(const AMSoundHandle& kOther);
    ~AMSoundHandle();
    bool FUN_00ad8ce0();            // IsPlaying
    int FUN_00ad8b30();             // duration in ms
    bool Play(bool bLoop);  // Play
};

struct AMSoundNode
{
    AMSoundHandle* FUN_006815c0();  // GetItem
    AMSoundNode* FUN_0084e3a0();    // GetNext
};

class AMPlayer
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
    virtual const AMPoint& GetPosition();  // +0x1f4
};
extern AMPlayer* DAT_011dea3c;

class AMAudio
{
  public:
    static AMAudio* GetSingleton();
    void FUN_00ad7c00(float fFadeAmount);
};

void FUN_00705210(const char* pcSubtitle, AMSoundHandle kHandle, AMPoint kPos, AMPlayer* pkSpeaker, int iFlag);
int TraitNameToID(const char* pcTrait);
int FUN_00406d00(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);
float FUN_0040ebd0(float fA, float fB);

struct AMTimer
{
    unsigned int FUN_00825c00();
};
extern AMTimer DAT_011f6394;
extern unsigned int DAT_011da410;
struct AMStringSetting
{
    const char* FUN_00403df0();
};
extern AMStringSetting DAT_011d3960;

class AMTile
{
  public:
    void FUN_00a01350(int m_iValueId, const char* pcValue, int iFlag);
    void FUN_00a012d0(int m_iValueId, float fValue, int iFlag);
    void FUN_00700320(int m_iValueId, int iValue);
};

struct AMSubtitleText
{
    const char* FUN_00559450();
};
struct AMSubtitles
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AMSubtitleText* GetElement(int iIndex);
    void RemoveAt(int iA, int iB);
};

class AMMenuView
{
  public:
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
    AMTile* m_pkInfoTile;  // +0x5c
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
    AMSoundNode m_kSounds;  // +0x98
    int unk09c;
    int unk0a0;
    int unk0a4;
    AMSubtitles m_kSubtitles;  // +0xa8
    AMSoundNode* m_pkCurrent;  // +0xb8
    bool m_bLoading;           // +0xbc
    unsigned char unk0bd;
    unsigned short unk0be;
    float m_fSoundVolume;        // +0xc0
    unsigned int m_uiStartTime;  // +0xc4
    float m_fFadeDuration;       // +0xc8

    void StopHolotapeAudio();
    void UpdateHolotapePlayback();
};

// Updates holotape playback state, displays remaining time on the info tile, and advances to the next subtitle when the current audio node finishes.
// @fnv 0x0079a660
void AMMenuView::UpdateHolotapePlayback()
{
    char acText[64];
    if (m_bLoading)
    {
        bool bAllReady = true;
        bool bNonePlayingOld = true;
        int iTotalLoc = 0;
        int iCount = 0;
        for (AMSoundNode* pkNode = &m_kSounds; pkNode; pkNode = pkNode->FUN_0084e3a0())
        {
            if (pkNode->FUN_006815c0()->FUN_00ad8ce0())
            {
                bNonePlayingOld = false;
                if (!m_pkCurrent)
                    m_pkCurrent = pkNode;
                if (!pkNode->FUN_006815c0()->FUN_00ad8b30())
                    bAllReady = false;
                else
                {
                    iTotalLoc += pkNode->FUN_006815c0()->FUN_00ad8b30();
                    iCount++;
                }
            }
        }
        if (bNonePlayingOld)
        {
            StopHolotapeAudio();
            AMAudio::GetSingleton()->FUN_00ad7c00(m_fFadeDuration);
        }
        else if (bAllReady)
        {
            m_bLoading = false;
            m_fSoundVolume = (iCount - 1) * 500 + iTotalLoc;
            m_pkCurrent->FUN_006815c0()->Play(false);
            m_uiStartTime = DAT_011f6394.FUN_00825c00();
            FUN_00705210(m_kSubtitles.GetElement(0)->FUN_00559450(), *m_pkCurrent->FUN_006815c0(),
                         DAT_011dea3c->GetPosition(), DAT_011dea3c, 0);
            m_kSubtitles.RemoveAt(0, 1);
        }
    }
    else if (m_fSoundVolume > 0.0)
    {
        float fTimeOffset = DAT_011f6394.FUN_00825c00() - m_uiStartTime;
        int iRemaining = 0;
        fTimeOffset = FUN_0040ebd0(fTimeOffset, m_fSoundVolume);
        iRemaining = (int)(m_fSoundVolume - fTimeOffset);
        FUN_00406d00(acText, 0x40, "%02d:%02d:%01d %s", iRemaining / 60000, iRemaining % 60000 / 1000,
                     iRemaining % 1000 / 100, DAT_011d3960.FUN_00403df0());
        m_pkInfoTile->FUN_00a01350(TraitNameToID("_ItemStringInfo"), acText, 1);
        m_pkInfoTile->FUN_00a012d0(TraitNameToID("_AudioFileCompletion"), fTimeOffset / m_fSoundVolume, 1);
    }
    if (m_pkCurrent && !m_pkCurrent->FUN_006815c0()->FUN_00ad8ce0())
    {
        if (!DAT_011da410)
            DAT_011da410 = DAT_011f6394.FUN_00825c00();
        if (m_pkCurrent->FUN_0084e3a0() && DAT_011f6394.FUN_00825c00() - DAT_011da410 > 500)
        {
            m_pkCurrent = m_pkCurrent->FUN_0084e3a0();
            m_pkCurrent->FUN_006815c0()->Play(false);
            DAT_011da410 = 0;
            FUN_00705210(m_kSubtitles.GetElement(0)->FUN_00559450(), *m_pkCurrent->FUN_006815c0(),
                         DAT_011dea3c->GetPosition(), DAT_011dea3c, 1);
            m_kSubtitles.RemoveAt(0, 1);
        }
        else if (!m_pkCurrent->FUN_0084e3a0())
        {
            FUN_00406d00(acText, 0x40, "00:00:0 %s", DAT_011d3960.FUN_00403df0());
            m_pkInfoTile->FUN_00a01350(TraitNameToID("_ItemStringInfo"), acText, 1);
            m_pkInfoTile->FUN_00a012d0(TraitNameToID("_AudioFileCompletion"), 1.0f, 1);
            m_pkInfoTile->FUN_00700320(0x1004, 0);
            StopHolotapeAudio();
        }
    }
}
}  // namespace fnv_0079a660

extern const double DAT_01012060;
extern float DAT_01056528;

struct PipboyLookup_host
{
    int Query();
};

struct FUN_0079c5a0_host
{
    void Push(unsigned char flag, float f);
};

struct FUN_0079c530_cls
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
    int m_i80;
    void FUN_0079c530(int a1, int a2);
};

// If m_i80 is 0x20 or 0x21, pushes a flag based on PipboyLookup Query divided by 0x78 compared to DAT_01012060, with value DAT_01056528.
// @fnv 0x0079c530
void FUN_0079c530_cls::FUN_0079c530(int aiUnused, int a2)
{
    if (m_i80 == 0x21 || m_i80 == 0x20)
    {
        reinterpret_cast<FUN_0079c5a0_host*>(this)->Push(
            (double)(reinterpret_cast<PipboyLookup_host*>(FUN_004b7210())->Query() / 0x78) > DAT_01012060,
            DAT_01056528);
    }
}

namespace fnv_0079cdb0 {
struct MMMapData
{
    int iWidth;   // +0x00
    int iHeight;  // +0x04
    short sMinX;  // +0x08
    short sMinY;  // +0x0a
    short sMaxX;  // +0x0c
    short sMaxY;  // +0x0e
};

class MMTile
{
  public:
    void FUN_00a01350(int m_iValueId, const char* pcValue, int iFlag);
    void FUN_00715c60(int m_iValueId, int iValue);
    void FUN_00a012d0(int m_iValueId, float fValue, int iFlag);
    void FUN_00700320(int m_iValueId, int iValue);
    void FUN_00707e10(const char* pcName);
    MMTile* FUN_00a03eb0(int iIndex);
};

struct MMRefNode;
class MMWorld : public TESWorldSpace
{
  public:
    MMMapData* FUN_00586400();
    const char* FUN_00586440();
    MMRefNode* GetOrCreateElement(int iFlag);
};

struct MMWorldNode
{
    MMWorld** FUN_006815c0();
};
struct MMWorldList
{
    MMWorldNode* FUN_00460140();
};
extern MMWorldList* DAT_011c3f2c;

class MMRef;
struct MMRefNode
{
    MMRef** FUN_006815c0();
    MMRefNode* FUN_00726070();
    void FUN_00470470();
    ~MMRefNode();
};

struct MMParent
{
    MMParent* FUN_004fd380();
};
struct MMLocationName
{
    const char* FUN_00616710();
};
struct MMMarkerData
{
    bool FUN_00438ed0();
    const char* FUN_00438eb0();
    MMLocationName* FUN_0044edb0();
    bool FUN_00438ef0();
    int FUN_00438f30();
};

class MMRef
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const NiPoint3& GetPos();  // +0x1f4
    MMParent* FUN_00575d70();
    MMMarkerData* FUN_00569060();
    bool FUN_00440da0();
};

struct MMRefList
{
    void FUN_00905820(MMRef** ppkRef);
};

class MMMenu
{
  public:
    int unk000[14];
    MMTile* m_pkMapTile;  // +0x38
    int unk03c[39];
    MMRefList m_kMarkers;  // +0xd8
    int unk0dc[3];
    NiPoint2 m_kNWCorner;  // +0xe8
    NiPoint2 m_kSECorner;  // +0xf0
    int unk0f8[4];
    MMWorld* m_pkMapSpace;     // +0x108
    MMWorld* m_pkRootSpace;    // +0x10c
    bool m_bRootSpaceChanged;  // +0x110
    char unk111[3];
    int unk114;
    int unk118;
    void* m_pkNorthCell;  // +0x11c

    MMTile* AddTileFromTemplate(MMTile* pkParent, const char* pcTemplate, int iFlag);
    void FUN_0079c5a0(int iA, float fScale);
    NiPoint3 GetMarkerPosition(NiPoint3 kPos, MMParent* pkSpace);
    void FUN_0079dbb0();
    void RefreshMap();
};

struct MMPoint2
{
    float x, y;
    MMPoint2(float fX, float fY);
};

TESForm* LookupFormByID(unsigned int auiFormId);
int FUN_00406d00(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);
int TraitNameToIDAdd(const char* pcTrait, int iIndex);
extern unsigned int DAT_011da370;
extern const char* DAT_011a0404[];

// Ensures root space and map data, updates tile dimensions, and populates marker list from root space references.
// @fnv 0x0079cdb0
void MMMenu::RefreshMap()
{
    MMMapData* pkData = m_pkRootSpace ? m_pkRootSpace->FUN_00586400() : 0;
    if (!m_pkRootSpace || !pkData || !pkData->iWidth || !pkData->iHeight)
    {
        m_pkRootSpace = (MMWorld*)dynamic_cast<TESWorldSpace*>(LookupFormByID(0x3c));
        pkData = m_pkRootSpace ? m_pkRootSpace->FUN_00586400() : 0;
        m_bRootSpaceChanged = true;
    }
    if (!m_pkRootSpace || !pkData || !pkData->iWidth || !pkData->iHeight)
    {
        m_pkRootSpace = *DAT_011c3f2c->FUN_00460140()->FUN_006815c0();
        pkData = m_pkRootSpace ? m_pkRootSpace->FUN_00586400() : 0;
        m_bRootSpaceChanged = true;
    }
    m_pkMapSpace = m_pkRootSpace;
    m_pkNorthCell = 0;
    if (m_pkRootSpace && pkData)
    {
        if (DAT_011da36c || m_bRootSpaceChanged)
        {
            m_pkMapTile->FUN_00a01350(0xfcc, m_pkRootSpace->FUN_00586440(), 1);
            m_pkMapTile->FUN_00715c60(0xfcd, pkData->iWidth);
            m_pkMapTile->FUN_00715c60(0xfce, pkData->iHeight);
            DAT_011da36c = false;
            m_bRootSpaceChanged = false;
        }
        FUN_0079c5a0(1, 1.0f);
        *(MMPoint2*)&m_kNWCorner = MMPoint2(pkData->sMinX << 12, (pkData->sMinY << 12) + 0x1000);
        *(MMPoint2*)&m_kSECorner = MMPoint2((pkData->sMaxX << 12) + 0x1000, pkData->sMaxY << 12);
        if (!m_pkMapTile->FUN_00a03eb0(0x1a))
        {
            MMRefNode* pkList = m_pkRootSpace->GetOrCreateElement(0);
            DAT_011da370 = 0;
            for (MMRefNode* pkIter = pkList; pkIter && *pkIter->FUN_006815c0(); pkIter = pkIter->FUN_00726070())
            {
                MMRef* pkRef = *pkIter->FUN_006815c0();
                NiPoint3 kPos = pkRef->GetPos();
                MMParent* pkSpace = pkRef->FUN_00575d70();
                while (pkSpace && pkSpace->FUN_004fd380())
                    pkSpace = pkSpace->FUN_004fd380();
                if (!pkRef->FUN_00569060()->FUN_00438ed0() || pkRef->FUN_00440da0())
                    continue;
                if (pkSpace != (MMParent*)m_pkRootSpace)
                    continue;
                MMTile* pkMarkerEntry = ((MMMenu*)DAT_011da368)->AddTileFromTemplate(m_pkMapTile, "MapMarkerTemplate", 0);
                if (pkMarkerEntry)
                {
                    char acText[256];
                    NiPoint3 kMapPos = GetMarkerPosition(kPos, pkRef->FUN_00575d70());
                    MMLocationName* pkName = pkRef->FUN_00569060()->FUN_0044edb0();
                    if (pkName)
                    {
                        FUN_00406d00(acText, 0x100, "%s\n(%s)", pkRef->FUN_00569060()->FUN_00438eb0(),
                                     pkName->FUN_00616710());
                        pkMarkerEntry->FUN_00a01350(TraitNameToIDAdd("_LocationName", -1), acText, 1);
                    }
                    else
                        pkMarkerEntry->FUN_00a01350(TraitNameToIDAdd("_LocationName", -1),
                                                    pkRef->FUN_00569060()->FUN_00438eb0(), 1);
                    pkMarkerEntry->FUN_00707e10(pkRef->FUN_00569060()->FUN_00438eb0());
                    pkMarkerEntry->FUN_00700320(0xfaa, 0x1a);
                    pkMarkerEntry->FUN_00a012d0(DAT_011da350, kMapPos.x, 1);
                    pkMarkerEntry->FUN_00a012d0(DAT_011da34c, kMapPos.y, 1);
                    if (pkRef->FUN_00569060()->FUN_00438ef0())
                        pkMarkerEntry->FUN_00a01350(0xfcc, DAT_011a0404[pkRef->FUN_00569060()->FUN_00438f30()], 1);
                    else
                    {
                        pkMarkerEntry->FUN_00a01350(0xfcc, "Interface\\Icons\\World Map\\icon_map_undiscovered.dds", 1);
                        pkMarkerEntry->FUN_00700320(0x1004, 0);
                    }
                    pkMarkerEntry->FUN_00700320(TraitNameToIDAdd("_MarkerIndex", -1), DAT_011da370);
                    m_kMarkers.FUN_00905820(&pkRef);
                    DAT_011da370++;
                }
            }
            pkList->FUN_00470470();
            delete pkList;
        }
        FUN_0079dbb0();
    }
}
}  // namespace fnv_0079cdb0

namespace fnv_007993d0 {
struct NoteTextSource
{
    virtual void unused00();
    virtual void unused04();
    virtual void unused08();
    virtual void unused0c();
    virtual const char* GetText(BGSNote*, unsigned int);
};
struct NoteTexture
{
    const char* FUN_00408da0();
};
struct NoteInput
{
    int GetNoteType();
    NoteTextSource* FUN_005e91d0();
    NoteTexture* GetNoteTexture();
};
struct NoteTile
{
    NoteTile* FUN_00a03da0(const char*);
    float FUN_00a011b0(int);
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00a012d0(int, float, bool);
    void SetTraitAndReset(int, float);
    NoteTile* FUN_0045cd60();
};
struct NoteExtent
{
    float x, y, z;
};
struct NoteFont
{
    NoteExtent* GetStringDimensions(NoteExtent*, const char*, int, float, int);
};
NoteFont* FUN_005bd5b0();
int TraitNameToID(const char*);
float FUN_00404010(float, float);
float FUN_004e4430(float);
struct NoteSetting
{
    const char* FUN_00403df0();
};
extern NoteSetting g_011d3960;
struct NoteMenu
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
    NoteTile* noteTile;
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
    void SetNote(NoteInput*);
};
// Populates the note menu's data tile with text, image, or time-string content based on the note type, and configures the scrollbar for text overflow.
// @fnv 0x007993d0
void NoteMenu::SetNote(NoteInput* note)
{
    float textHeight2;
    NoteTile* textTile2;
    float scrollDelta;
    NoteTile* scrollbar2;
    float overflow3;
    NoteExtent extent4;
    char timeText2[64];
    switch (note->GetNoteType())
    {
    case 1:
        textTile2 = noteTile->FUN_00a03da0("MM_DataText");
        scrollbar2 = noteTile->FUN_00a03da0("MM_TextScrollbar");
        scrollDelta = scrollbar2->FUN_00a011b0(TraitNameToID("_ScrollDelta"));
        overflow3 = 0.0f;
        noteTile->FUN_00700320(TraitNameToID("_ItemType"), 1);
        textTile2->FUN_00a01350(0xfc4, note->FUN_005e91d0()->GetText((BGSNote*)note, 0x4d414e54), true);
        textHeight2 =
            FUN_005bd5b0()
                ->GetStringDimensions(&extent4, note->FUN_005e91d0()->GetText((BGSNote*)note, 0x4d414e54), 1, 400.0f, 0)
                ->y;
        overflow3 = textHeight2 - textTile2->FUN_0045cd60()->FUN_00a011b0(0xfb0);
        overflow3 = FUN_00404010(0.0f, overflow3);
        scrollbar2->FUN_00a012d0(TraitNameToID("_number_of_items"), FUN_004e4430(overflow3 / scrollDelta) + 1.0, true);
        scrollbar2->FUN_00a012d0(TraitNameToID("_current_value"), 0.0f, false);
        scrollbar2->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
        break;
    case 2:
        noteTile->FUN_00a03da0("MM_DataImage")->FUN_00a01350(0xfcc, note->GetNoteTexture()->FUN_00408da0(), true);
        noteTile->FUN_00700320(TraitNameToID("_ItemType"), 2);
        break;
    case 0:
    case 3:
        noteTile->FUN_00700320(TraitNameToID("_ItemType"), 3);
        if (!unkb8)
        {
            sprintf_s(timeText2, 64, "--:--:- %s", g_011d3960.FUN_00403df0());
            noteTile->FUN_00a01350(TraitNameToID("_ItemStringInfo"), timeText2, true);
            noteTile->FUN_00a012d0(TraitNameToID("_AudioFileCompletion"), 0.0f, true);
        }
        break;
    }
    noteTile->FUN_00700320(0xfa3, 1);
}
}  // namespace fnv_007993d0

int __cdecl TraitNameToIDAdd(const char*, int);
struct TraitValue
{
    void FUN_00a09130(int, Tile*, int);
    void Refresh(bool);
};

HighlightTile* __cdecl FUN_00a08b20(Tile*, const char*);
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0c;
    HighlightTile* unk10;
    void UpdateHighlight();
};
// Sets two traits on unk0c and applies the speech challenge failure flag to the named highlight box and its edges.
// @fnv 0x007a8260
void HighlightList::UpdateHighlight()
{
    static int highlightY = TraitNameToIDAdd("_highlight_y", -1);
    static int selectedHeight = TraitNameToIDAdd("_selected_height", -1);
    if (unk0c)
    {
        if (unk10)
        {
            TraitValue* valueHeight = (TraitValue*)unk0c->GetValue(highlightY);
            TraitValue* valueY = (TraitValue*)unk0c->GetValue(selectedHeight);
            valueHeight->FUN_00a09130(2000, unk10, 4002);
            valueHeight->Refresh(false);
            valueY->FUN_00a09130(2000, unk10, 4016);
            valueY->Refresh(false);
            if (unk10->GetSpeechChallengeFailure())
            {
                HighlightTile* box = FUN_00a08b20(unk0c, "lb_highlight_box");
                if (box)
                {
                    HighlightTile* edge = box->FUN_00a03da0("top");
                    if (edge)
                    {
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("bottom");
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("left");
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("right");
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                    }
                    box->FUN_0071aa60(true);
                    box->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box = FUN_00a08b20(unk0c, "lb_highlight_box");
                if (box)
                {
                    HighlightTile* edge = box->FUN_00a03da0("top");
                    if (edge)
                    {
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("bottom");
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("left");
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("right");
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                    }
                    box->FUN_0071aa60(false);
                    box->FUN_00a07530(8);
                }
            }
        }
        else
        {
            unk0c->Set(highlightY, -1);
            unk0c->Set(selectedHeight, 0);
        }
    }
}

namespace fnv_00798cb0 {
extern int DAT_011da400;
extern char str_010739a0[];
extern SettingT_GameSettingCollection_ DAT_011db2f0, DAT_011db358;
extern void FUN_0079bc50(Tile*, BGSQuestObjective*);
extern void FUN_00799100(Tile*, BGSQuestObjective*);
extern int TraitNameToID(const char*);
extern void FUN_00706f30(int);
struct SelectedIndex
{
    int GetProcessLevel();
};
struct QuestSelection
{
    void FUN_007a2350(bool);
};
struct MapEnterNoteSelection : ListBox<BGSNote*>
{
    void FUN_007a30e0(bool);
};
struct MapEnterObjectiveSelection : ListBox<BGSQuestObjective*>
{
    void SetEnabledTrait(bool);
};
struct Burst
{
    void FUN_007f8610(int, float, float, int);
};
struct Proxy
{
    Burst* FUN_00704370();
};
struct ClickVtable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(int, Tile*);
};
struct Reconstruction798cb0 : MapMenu
{
    void FUN_00798cb0(int, Tile*);
    void SetNote(BGSNote*);
    void UpdateChallengeText(TESChallenge*);
};
// Handles codes 23–25 for list selections and updates the selected index, with additional handling for codes 14, 15, and -1.
// @fnv 0x00798cb0
void Reconstruction798cb0::FUN_00798cb0(int aiEventCode, Tile* tile)
{
    int index = 0;
    BGSNote* challenge;
    TESChallenge* note;
    switch (aiEventCode)
    {
    case 23:
        if (tile)
        {
            m_pSelectedQuest = m_kQuestListBox.GetSelectedData(tile);
            m_kObjectiveListBox.Filter((bool (*)(BGSQuestObjective*))FUN_0079bc50);
            index = tile ? (int)tile->GetFloat(0xfac) : 0;
            m_pTiles[13]->Set(Tile::GetTraitID(str_010739a0), 4);
            m_pTiles[13]->Set(0xfa3, 1);
            m_pSelectedMapMarkerInfo = 0;
            m_kObjectiveListBox.Traverse(FUN_00799100, 0, 0x7fffffff);
            m_pTiles[12]->Set(0xfaf, m_pSelectedMapMarkerInfo != 0);
            m_pTiles[11]->Set(0xfaf, m_pSelectedQuest && !m_pSelectedQuest->GetCompleted() ? 1 : 0);
        }
        break;
    case 24:
        if (!DAT_011da36d)
        {
            challenge = m_kNoteListBox.GetSelectedData(tile);
            index = m_kNoteListBox.GetSelectedTile() ? (int)m_kNoteListBox.GetSelectedTile()->GetFloat(0xfac) : 0;
            if (FUN_004b71d0() || (challenge && !m_pSelectedNote))
                SetNote(challenge);
            if (!challenge->GetNoteType() || challenge->GetNoteType() == 3)
            {
                m_pTiles[13]->Set(0x1004, challenge == m_pSelectedNote && m_pkActiveSoundList ? 1 : 0);
            }
            else if (!challenge->GetUnk7d())
            {
                m_uiMapState = g_timeGlobal.GetTimeStamp();
            }
        }
        else
        {
            note = m_kChallengeListBox.GetSelectedData(tile);
            if (FUN_004b71d0() || note)
                UpdateChallengeText(note);
            m_pTiles[13]->Set(0xfa3, 1);
            FUN_00706f30(4);
        }
        break;
    case 25:
        index = m_kMapMarkerListBox.GetSelectedTile() ? (int)m_kMapMarkerListBox.GetSelectedTile()->GetFloat(0xfac) : 0;
        break;
    case 14:
        ((MapEnterNoteSelection*)&m_kNoteListBox)->FUN_007a30e0(false);
        break;
    case 15:
        ((QuestSelection*)&m_kQuestListBox)->FUN_007a2350(false);
        ((MapEnterObjectiveSelection*)&m_kObjectiveListBox)->SetEnabledTrait(true);
        break;
    case -1:
        if (tile && ((SelectedIndex*)tile)->GetProcessLevel() == ((TimeGlobal*)&m_kObjectiveListBox)->GetTimeStamp())
            ((ClickVtable*)this)->v10(15, 0);
        break;
    }
    if (DAT_011da400 != index && (aiEventCode == 23 || aiEventCode == 24 || aiEventCode == 25))
    {
        ((Proxy*)FUN_004b7210())
            ->FUN_00704370()
            ->FUN_007f8610(0, DAT_011da400 < index ? DAT_011db2f0.Float()->f : -DAT_011db2f0.Float()->f,
                           DAT_011db358.Float()->f, 1);
        DAT_011da400 = index;
    }
}
}  // namespace fnv_00798cb0
