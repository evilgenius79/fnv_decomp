// fallout/audio/falloutradio.cpp: FalloutRadio, RadioConvTask, FalloutAudioMedia, Interface and more (61 functions)

#include "falloutradio_private_decls.h"

// Toggles the radio on or off: starts playback when enabling, stops and releases streams when disabling, and stores the new state.
// @fnv 0x008324e0
bool FalloutRadio::SetRadioEnabled(bool enable)
{
    if (DAT_011dd436)
        return false;

    if (enable)
    {
        if (!DAT_011dd437)
        {
            FalloutAudioMedia::BeginMediaUpdate();
            FUN_008325a0(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_RADIO, 0, 1000, false, false, 0.0f, 0);
            FalloutAudioMedia::EndMediaUpdate();
        }
    }
    else
    {
        if (FalloutAudioMedia::IsRadioPlaying())
        {
            FalloutAudioMedia::BeginMediaUpdate();
            FUN_008325a0(false);
        }

        DAT_011dd5bc.Stop();
        DAT_011dd5bc.Release();
        DAT_011dd42c = 0;
        DAT_011dd638.Stop();
        DAT_011dd638.Release();
    }

    DAT_011dd434 = enable;
    return DAT_011dd434;
}

// Iterates the receiver list, removing inactive receivers (or all when force is set) and detaching them from every station's receiver list.
// @fnv 0x008329a0
void FalloutRadio::RefreshRadioReceivers(bool force)
{
    struct Locals
    {
        void* result;
        RadioReceiver* deletion;
        RadioReceiver* copy;
        RadioStationState* station;
        BSSimpleList<RadioStationState*>* stationNode;
        RadioReceiver* receiver;
        BSSimpleList<RadioReceiver*>* node;
    } locals;
    locals.node = &DAT_011dd58c;
    locals.receiver = 0;
    while (locals.node && !locals.node->IsEmpty())
    {
        if (!locals.node->GetItem()->active || force)
        {
            locals.receiver = locals.node->GetItem();
            DAT_011dd58c.Remove(locals.node->GetItem());
            locals.node = &DAT_011dd58c;
            locals.stationNode = &DAT_011dd554;
            while (locals.stationNode && !locals.stationNode->IsEmpty())
            {
                locals.station = locals.stationNode->GetItem();
                if (locals.station)
                {
                    while (locals.station->receivers.IsInList(locals.receiver))
                    {
                        locals.receiver->sound.Stop();
                        locals.receiver->sound.Release();
                        locals.station->receivers.Remove(locals.receiver);
                    }
                }
                locals.stationNode = locals.stationNode->GetNext();
            }
            locals.deletion = locals.receiver;
            locals.copy = locals.deletion;
            if (locals.copy)
                locals.result = locals.copy->FUN_00832190(true);
            else
                locals.result = 0;
        }
        else
            locals.node = locals.node->GetNext();
    }
}

// @fnv 0x00832ad0
bool FalloutRadio::Update(bool force)
{
    bool update = false;

    if (DAT_011dd424 == 0)
        DAT_011dd424 = g_timeGlobal.GetTimeStamp();

    if (g_timeGlobal.GetTimeStamp() - DAT_011dd424 > DAT_011dd5cc.Int()->value && !Interface::IsGamePaused())
    {
        update = true;
        DAT_011dd424 = g_timeGlobal.GetTimeStamp();
    }

    if (g_thePlayer != 0)
    {
        if (reinterpret_cast<LowProcess*>(g_thePlayer)->GetTarget() != 0)
        {
            if (reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(g_thePlayer)->GetTarget())
                    ->IsCellInterior())
            {
                if (DAT_011dd435 == 0)
                    update = true;
                else
                    update = false;
                DAT_011dd435 = 1;
            }
        }
    }

    if (force)
        update = true;

    if (DAT_011dd438 & 1)
    {
        DAT_011dd43c &= ~2;
        DAT_011dd43c |= 1;
    }
    else if (DAT_011dd438 & 2)
    {
        DAT_011dd43c &= ~1;
        DAT_011dd43c |= 2;
    }
    DAT_011dd438 = 0;

    FalloutRadio::RefreshRadioReceivers(false);
    if (DAT_011dd440 == 0)
        DAT_011dd440 = g_dataHandler->GetSoundByEditorID(DAT_0107ce14);
    FalloutRadio::UpdateRadioConversations(update);
    FalloutRadio::RefreshRadioReceivers(false);
    DAT_011dd43c = 0;
    return true;
}

// Loads game state into the radio's station, receiver and ID lists, removing entries whose form or reference no longer resolves.
// @fnv 0x00836af0
void FalloutRadio::InitLoadGame(BGSLoadGameBuffer* buffer)
{
#pragma pack(push, 1)
    struct LoadLocals
    {
        void* receiverResult;
        void* stationResult;
        RadioReceiver* receiverDeletion;
        RadioReceiver* receiverCopy;
        RadioStationState* stationDeletion;
        RadioStationState* stationCopy;
        unsigned int id;
        unsigned char padID1, padID2, padID3;
        bool removeID;
        BSSimpleList<unsigned int>* idNode;
        BSSimpleList<unsigned int>* idPrevious;
        RadioReceiver* receiver;
        unsigned char padReceiver1, padReceiver2, padReceiver3;
        bool removeReceiver;
        BSSimpleList<RadioReceiver*>* receiverNode;
        BSSimpleList<RadioReceiver*>* receiverPrevious;
        RadioStationState* station;
        unsigned char padStation1, padStation2, padStation3;
        bool removeStation;
        BSSimpleList<RadioStationState*>* stationNode;
        BSSimpleList<RadioStationState*>* stationPrevious;
        RadioReceiver* firstReceiver;
        BSSimpleList<RadioReceiver*>* firstNode;
    } locals;
#pragma pack(pop)
    void* pRefr;
    locals.firstNode = &DAT_011dd58c;
    while (locals.firstNode)
    {
        locals.firstReceiver = locals.firstNode->GetItem();
        if (locals.firstReceiver)
            reinterpret_cast<TeleportableReference*>(locals.firstReceiver)->InitLoadGame(buffer);
        locals.firstNode = locals.firstNode->GetNext();
    }
    locals.stationNode = &DAT_011dd554;
    locals.stationPrevious = 0;
    while (locals.stationNode && !locals.stationNode->IsEmpty())
    {
        locals.station = locals.stationNode->GetItem();
        locals.removeStation = false;
        if (locals.station)
        {
            locals.station->InitLoadGame(buffer);
            if (!locals.station->form)
            {
                locals.stationDeletion = locals.station;
                locals.stationCopy = locals.stationDeletion;
                if (locals.stationCopy)
                    locals.stationResult = locals.stationCopy->FUN_00832160(true);
                else
                    locals.stationResult = 0;
                locals.station = 0;
                locals.removeStation = true;
            }
        }
        else
            locals.removeStation = true;
        if (locals.removeStation)
        {
            if (locals.stationPrevious)
            {
                locals.stationPrevious->Remove(locals.stationNode->GetItem());
                locals.stationNode = locals.stationPrevious->GetNext();
            }
            else
                locals.stationNode->RemoveHead();
        }
        else
        {
            locals.stationPrevious = locals.stationNode;
            locals.stationNode = locals.stationNode->GetNext();
        }
    }
    locals.receiverNode = &DAT_011dd58c;
    locals.receiverPrevious = 0;
    while (locals.receiverNode && !locals.receiverNode->IsEmpty())
    {
        locals.receiver = locals.receiverNode->GetItem();
        locals.removeReceiver = false;
        if (locals.receiver)
        {
            if (!locals.receiver->form)
            {
                locals.receiverDeletion = locals.receiver;
                locals.receiverCopy = locals.receiverDeletion;
                if (locals.receiverCopy)
                    locals.receiverResult = locals.receiverCopy->FUN_00832190(true);
                else
                    locals.receiverResult = 0;
                locals.receiver = 0;
                locals.removeReceiver = true;
            }
        }
        else
            locals.removeReceiver = true;
        if (locals.removeReceiver)
        {
            if (locals.receiverPrevious)
            {
                locals.receiverPrevious->Remove(locals.receiverNode->GetItem());
                locals.receiverNode = locals.receiverPrevious->GetNext();
            }
            else
                locals.receiverNode->RemoveHead();
        }
        else
        {
            locals.receiverPrevious = locals.receiverNode;
            locals.receiverNode = locals.receiverNode->GetNext();
        }
    }
    if (DAT_011dd42c)
        DAT_011dd42c =
            reinterpret_cast<unsigned int>(GetRadioConversation(reinterpret_cast<BGSTalkingActivator*>(DAT_011dd42c)));
    if (DAT_011dd430)
        DAT_011dd430 =
            reinterpret_cast<unsigned int>(GetRadioConversation(reinterpret_cast<BGSTalkingActivator*>(DAT_011dd430)));
    if (buffer->vfn_0() >= 10)
    {
        locals.idNode = &DAT_011dd59c;
        locals.idPrevious = 0;
        while (locals.idNode && !locals.idNode->IsEmpty())
        {
            locals.id = locals.idNode->GetItem();
            locals.removeID = false;
            if (locals.id)
            {
                if (locals.id)
                    pRefr = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(locals.id));
                else
                    pRefr = 0;
                locals.id = reinterpret_cast<unsigned int>(pRefr);
                if (locals.id)
                    locals.idNode->SetItem(locals.id);
                else
                    locals.removeID = true;
            }
            else
                locals.removeID = true;
            if (locals.removeID)
            {
                if (locals.idPrevious)
                {
                    locals.idPrevious->Remove(locals.idNode->GetItem());
                    locals.idNode = locals.idPrevious->GetNext();
                }
                else
                    locals.idNode->RemoveHead();
            }
            else
            {
                locals.idPrevious = locals.idNode;
                locals.idNode = locals.idNode->GetNext();
            }
        }
    }
}

// Clears bit 0 and sets bit 1 of the radio state flags.
// @fnv 0x00832c80
void FalloutRadio::RadioSynchUnPaused()
{
    ms_uiRadioSyncFlags &= ~1;
    ms_uiRadioSyncFlags |= 2;
}

bool __fastcall _ref_008256d0(void*);
FalloutRadio::RadioReceiver** __fastcall _ref_006815c0(void*);
BSSimpleList<FalloutRadio::RadioReceiver*>* __fastcall _ref_00726070(void*);

// Walks the DAT_011dd58c list until an entry whose first int equals param_1 is found, returning that entry or null.
// @fnv 0x00832930
FalloutRadio::RadioReceiver* __cdecl FUN_00832930(int param_1)
{
    FalloutRadio::RadioReceiver* result = 0;
    BSSimpleList<FalloutRadio::RadioReceiver*>* node = &DAT_011dd58c;
    {
        bool found = false;
        while (node && !_ref_008256d0(node) && !found)
        {
            if (param_1 == *(int*)*_ref_006815c0(node))
            {
                result = *_ref_006815c0(node);
                found = true;
            }
            node = _ref_00726070(node);
        }
    }
    return result;
}

struct FORadioReceiver_Stub
{
    void* pRef;
    SoundPlaybackHandle sound;
    char pad[0x1c - 0x4 - sizeof(SoundPlaybackHandle)];
    bool bFlag;
};

struct TESObjectREFR_Stub
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
    virtual bool v64();
};

FORadioReceiver_Stub* __cdecl FUN_00832930(TESObjectREFR_Stub*);

// If the reference has a radio emitter, stops and releases its sound, clears the flag and reference pointer.
// @fnv 0x00835980
void __cdecl FUN_00835980(TESObjectREFR_Stub* apNPCRadio)
{
    if (!apNPCRadio->v64())
        return;

    FORadioReceiver_Stub* pemitter = FUN_00832930(apNPCRadio);
    if (pemitter)
    {
        pemitter->sound.Stop();
        pemitter->sound.Release();
        pemitter->bFlag = false;
        pemitter->pRef = 0;
    }
}

struct FUN_008373d0_struct
{
    float f;
    void* p;
};

// @fnv 0x008373d0
FUN_008373d0_struct* __fastcall ClearStruct(FUN_008373d0_struct* pThis)
{
    pThis->f = 0.0f;
    pThis->p = 0;
    return pThis;
}

void __fastcall FUN_00837410(void* pThis);

// @fnv 0x008373f0
void __fastcall FUN_008373f0(void* pThis)
{
    FUN_00837410(pThis);
}

template <class T> class BSSimpleListEx : public BSSimpleList<T>
{
  public:
    BSSimpleListEx();
    ~BSSimpleListEx();
    void RemoveAll();
    void AddHead(T& item);
};

template <class T> class BSStringT
{
  public:
    T* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    BSStringT();
    ~BSStringT();
    int PrintfString(const char* fmt, ...);
    operator const T*() const;
};

class BSSoundHandleEx
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int eState;
    ~BSSoundHandleEx();
    bool Play(bool abUnk);
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

class RadioStationRef : public TESObjectREFR
{
  public:
    bool GetDisabled();
    const char* GetFullName();
    float GetRadioStationRange();
    float GetRadioStationStaticPercent();
    int GetRadioRangeType();
};

class BGSTalkingActivator
{
  public:
    static void FindRadioStations(TESObjectREFR* apRef, BSSimpleList<RadioStationRef*>* apStations,
                                  BSSimpleList<float>* apDistances);
};

class RadioSignal
{
  public:
    void FUN_00834210(bool abLost);
    void SetByteAtOffset17(unsigned char aucPower);
};

class SettingString
{
  public:
    const char* GetString();
};

class SettingFloat
{
  public:
    float* Float();
};

bool __cdecl QueueUIMessage(const char* apText, int aiUnk, const char* apIcon, const char* apSound, float afTime,
                            bool abUnk);
bool __cdecl FUN_005aa680(RadioStationRef* apRef);
void __cdecl FUN_00832240(void* apForm, bool abUnk);
void __cdecl FUN_00834260(FalloutRadio::RadioStationState* apStation);
extern unsigned char DAT_011a179c;
extern SettingString g_011d4348;
extern SettingFloat g_011dd580;

// Updates radio station signal strength and static from player distances, queues a UI alert for newly found stations, and clears the temporary station lists.
// @fnv 0x00833d00
void UpdateRadioSignals(bool abUpdateSignals)
{
    bool bmatch;
    BSSimpleList<FalloutRadio::RadioStationState*>* pactStations;
    unsigned char isignalPower;
    float fradioRadius;
    float fstaticRatio;
    float fstaticDistance;
    BSSimpleListEx<RadioStationRef*> stationlist;
    float fdistance;
    BSSimpleList<RadioStationRef*>* stations;
    BSSimpleList<float>* pdistances;
    BSSimpleListEx<float> stationDistances;

    if (DAT_011dd436)
        return;

    if (abUpdateSignals)
    {
        BGSTalkingActivator::FindRadioStations((TESObjectREFR*)g_thePlayer, &stationlist, &stationDistances);
        for (BSSimpleList<RadioStationRef*>* pstationObj = &stationlist; pstationObj && pstationObj->GetItem();
             pstationObj = pstationObj->GetNext())
        {
            if (!pstationObj->GetItem()->GetDisabled() || FUN_005aa680(pstationObj->GetItem()))
            {
                if (!DAT_011dd59c.IsInList((unsigned int&)pstationObj->GetItem()))
                {
                    if (!DAT_011a179c)
                    {
                        BSStringT<char> strtemp;
                        BSSoundHandleEx alertSound =
                            BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIRadioSignalFound", 0x100121);
                        alertSound.Play(false);
                        strtemp.PrintfString(g_011d4348.GetString(), pstationObj->GetItem()->GetFullName());
                        QueueUIMessage(strtemp, 0, "Interface\\Icons\\Message Icons\\glow_message_radio_tower.dds", 0,
                                       2.0f, false);
                    }
                    static_cast<BSSimpleListEx<unsigned int>&>(DAT_011dd59c)
                        .AddHead((unsigned int&)pstationObj->GetItem());
                }
            }
        }
        DAT_011a179c = 0;
    }

    stations = 0;
    pdistances = 0;
    bmatch = false;
    fdistance = 3.402823466e+38f;
    fradioRadius = 0.0f;
    fstaticRatio = 0.0f;
    isignalPower = 0;
    fstaticDistance = 1.0f - *g_011dd580.Float();
    pactStations = &DAT_011dd554;
    while (pactStations && !pactStations->IsEmpty())
    {
        stations = &stationlist;
        pdistances = &stationDistances;
        bmatch = false;
        fdistance = 3.402823466e+38f;
        FalloutRadio::RadioStationState* pstation = pactStations->GetItem();
        if (pstation)
        {
            while (abUpdateSignals && stations && pdistances)
            {
                if (stations->GetItem() == pstation->form)
                {
                    bmatch = true;
                    isignalPower = 100;
                    ((RadioSignal*)((char*)pstation + 4))->FUN_00834210(false);
                    fdistance = pdistances->GetItem();
                    fradioRadius = ((RadioStationRef*)pstation->form)->GetRadioStationRange();
                    if (((RadioStationRef*)pstation->form)->GetRadioStationStaticPercent() != 0.0)
                        fstaticDistance =
                            1.0 - ((RadioStationRef*)pstation->form)->GetRadioStationStaticPercent() / 100.0;
                    if (((RadioStationRef*)pstation->form)->GetRadioRangeType() == 0 && fradioRadius > 0.0 &&
                        fdistance > 0.0)
                    {
                        fstaticRatio = fdistance / fradioRadius;
                        if (fstaticRatio > fstaticDistance)
                            isignalPower = 100 - (unsigned char)((fstaticRatio - fstaticDistance) /
                                                                 (1.0f - fstaticDistance) * 100.0);
                    }
                    ((RadioSignal*)((char*)pstation + 4))->SetByteAtOffset17(isignalPower);
                    stations = 0;
                    pdistances = 0;
                }
                else
                {
                    stations = stations->GetNext();
                    pdistances = pdistances->GetNext();
                }
            }
            if (abUpdateSignals && !bmatch)
            {
                ((RadioSignal*)((char*)pstation + 4))->FUN_00834210(true);
                ((RadioSignal*)((char*)pstation + 4))->SetByteAtOffset17(0);
            }
            if (bmatch && DAT_011dd430 == (unsigned int)pstation)
            {
                BSStringT<char> strtemp;
                BSSoundHandleEx alertSound =
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIRadioSignalFound", 0x100121);
                alertSound.Play(false);
                strtemp.PrintfString(g_011d4348.GetString(), ((RadioStationRef*)pstation->form)->GetFullName());
                QueueUIMessage(strtemp, 0, "Interface\\Icons\\Message Icons\\glow_message_radio_tower.dds", 0, 2.0f,
                               false);
                FalloutRadio::SetRadioEnabled(true);
                FUN_00832240(pstation->form, false);
                DAT_011dd430 = 0;
            }
            FUN_00834260(pstation);
        }
        pactStations = pactStations->GetNext();
    }
    stationDistances.RemoveAll();
    stationlist.RemoveAll();
}

extern unsigned char DAT_011dd313;

// @fnv 0x008325a0
void FUN_008325a0(unsigned char value)
{
    DAT_011dd313 = value;
}

void __cdecl FUN_00834260(FalloutRadio::RadioStationState* apStation);

// Clears bit 1 of DAT_011dd438, sets bit 0, and if DAT_011dd42c is non-null passes it to FUN_00834260.
// @fnv 0x00832c40
void __cdecl FUN_00832c40()
{
    DAT_011dd438 &= 0xfffffffd;
    DAT_011dd438 |= 1;
    if (DAT_011dd42c != 0)
        FUN_00834260((FalloutRadio::RadioStationState*)DAT_011dd42c);
}

struct FUN_00833040_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    bool __thiscall IsFlag20Set();
};

// @fnv 0x00833040
bool __thiscall FUN_00833040_shell::IsFlag20Set()
{
    return ((m_14 & 0x20) != 0);
}

struct FUN_008330b0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void SetFlag(bool a2);
};

// Sets or clears bit 0x10 in m_14 according to a2.
// @fnv 0x008330b0
void FUN_008330b0_shell::SetFlag(bool a2)
{
    a2 ? m_14 |= 0x10 : m_14 &= ~0x10;
}

struct FUN_00833bc0_shell
{
    int mFlags;  // +0x14
    bool IsFlagSet();
};

// @fnv 0x00833bc0
bool FUN_00833bc0_shell::IsFlagSet()
{
    return (*(int*)((char*)this + 0x14) & 4) != 0;
}

// @fnv 0x00833c00
bool __fastcall IsFlag80Set(void* thisPtr)
{
    return (((int*)thisPtr)[5] & 0x80) != 0;
}

// @fnv 0x00833ce0
unsigned char FUN_00833ce0()
{
    return DAT_011dd437;
}

extern unsigned char _DAT_011dcfa4;

// @fnv 0x00833cf0
unsigned char __cdecl FUN_00833cf0()
{
    return _DAT_011dcfa4;
}

struct FUN_00835650_shell
{
    int m_uiSoundFlags;
    bool FUN_00835650();
};

// @fnv 0x00835650
bool FUN_00835650_shell::FUN_00835650()
{
    return (*(int*)((char*)this + 0x14) & 1) != 0;
}

struct FUN_00835670_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    bool IsFlag8Set();
};

// @fnv 0x00835670
bool FUN_00835670_shell::IsFlag8Set()
{
    return (m_f & 8) != 0;
}

extern char* __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct RadioConvTask
{
    bool __thiscall GetDescription(char* apDescription, unsigned int aiBufferSize);
};

// Writes the string "Radio conversation task" into apDescription using the given buffer size and returns true.
// @fnv 0x008373a0
bool __thiscall RadioConvTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Radio conversation task");
    return true;
}

struct FUN_00832440_shell
{
    unsigned int pad0_0;
    unsigned int pad1_4;
    unsigned int pad2_8;
    unsigned int pad3_c;
    unsigned int pad4_10;
    unsigned int flags;
    void FUN_00832440(bool enabled);
};

// Sets or clears bit 0 of the flags field according to enabled.
// @fnv 0x00832440
void FUN_00832440_shell::FUN_00832440(bool enabled)
{
    enabled ? flags |= 1 : flags &= ~1;
}

struct FUN_00833060_shell
{
    int m_auiShapeKeys;               // +0x00
    int m_pAuxiliaryObject;  // +0x04
    int m_pad3;              // +0x08
    int m_pad4;              // +0x0c
    int m_pad5;              // +0x10
    int m_flags;             // +0x14
    void FUN_00833060(bool enabled);
};

// @fnv 0x00833060
void FUN_00833060_shell::FUN_00833060(bool enabled)
{
    enabled ? m_flags |= 2 : m_flags &= ~2;
}

struct FUN_00833100_shell
{
    int m_kPointA;                // +0x00
    int m_kPointB;                // +0x04
    int m_iThirdValue;                // +0x08
    int m_iFourthElementInteger;                // +0x0c
    int m_usTrailingValue;  // +0x10
    int m_flags;            // +0x14
    void FUN_00833100(bool enabled);
};

// Sets or clears bit 0x20 in m_flags according to enabled.
// @fnv 0x00833100
void FUN_00833100_shell::FUN_00833100(bool enabled)
{
    enabled ? m_flags |= 0x20 : m_flags &= ~0x20;
}

struct FUN_00833be0_shell
{
    int FUN_00833be0();
};

// @fnv 0x00833be0
int FUN_00833be0_shell::FUN_00833be0()
{
    return (reinterpret_cast<int*>(this)[5] & 0x10) != 0;
}

struct FUN_00833c20_shell
{
// @fnv 0x00833c20
    virtual ~FUN_00833c20_shell()
    {}
    unsigned char FUN_00833c20();
};

unsigned char FUN_00833c20_shell::FUN_00833c20()
{
    return ((char*)this)[0x10];
}

struct FUN_00834210_shell
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    void FUN_00834210(bool enabled);
};

// @fnv 0x00834210
void FUN_00834210_shell::FUN_00834210(bool enabled)
{
    enabled ? m_14 |= 4 : m_14 &= ~4;
}

struct FUN_00835690_shell
{
    unsigned int a;      // +0x00
    unsigned int b;      // +0x04
    unsigned int c;      // +0x08
    unsigned int d;      // +0x0c
    unsigned int e;      // +0x10
    unsigned int flags;  // +0x14
    void SetFlag80(bool value);
};

// Sets or clears bit 0x80 in flags according to value.
// @fnv 0x00835690
void FUN_00835690_shell::SetFlag80(bool abSet)
{
    abSet ? flags |= 0x80 : flags &= ~0x80;
}

void _Deallocate(void*);
struct Holder00832160
{
    void FUN_008321c0();
    void* FUN_00832160(unsigned int);
};
// Calls FUN_008321c0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00832160
void* Holder00832160::FUN_00832160(unsigned int flags)
{
    this->FUN_008321c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void _Deallocate(void*);
struct FUN_00832190_shell
{
    void FUN_008321e0();
    void* FUN_00832190(unsigned int);
};
// Calls FUN_008321e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00832190
void* FUN_00832190_shell::FUN_00832190(unsigned int flags)
{
    FUN_008321e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00832490_shell
{
    int _pad[5];
    int _f14;
    void SetFlag100(bool);
};
// Sets or clears bit 0x100 in the field at offset 0x14 according to the enabled argument.
// @fnv 0x00832490
void FUN_00832490_shell::SetFlag100(bool enabled)
{
    enabled ? _f14 |= 0x100 : _f14 &= ~0x100;
}

struct GlobalObject_0041a250
{
    int _00;
    int _04;
    int _08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
struct FUN_008327d0
{
    int _00;
    GlobalObject_0041a250 _04;
    GlobalObject_0041a250 _10;
    FUN_008327d0();
};
// Default constructor for a structure holding two GlobalObject_0041a250 members; the member constructors run implicitly.
// @fnv 0x008327d0
FUN_008327d0::FUN_008327d0()
{}

struct SL
{
    SL();
};
struct FUN_00833170
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    SL m6;
    FUN_00833170();
};
// Initializes the object's fields m0 through m3 and m5 to zero.
// @fnv 0x00833170
FUN_00833170::FUN_00833170()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m5 = 0;
}

// If flag is false and p is non-null, writes 1 to p[4].
// @fnv 0x008357e0
void FUN_008357e0(int* p, bool abSkip)
{
    if (!abSkip && p != 0)
    {
        int* q = p;
        q[4] = 1;
    }
}

namespace fnv_00835b90 {
struct FNVHelper00835b90
{
    BGSTalkingActivator* _FNV_GetObjectReference();
};
struct FUN_00833040_shell
{
    bool IsFlag20Set();
};
// Returns false if DAT_011dd436 is set; otherwise resolves the target's object reference to a station and returns whether IsFlag20Set on it succeeds.
// @fnv 0x00835b90
bool FUN_00835b90(TESObjectREFR* apTargetStation)
{
    FalloutRadio::RadioConversation* pstation;
    bool bretValue;
    if (DAT_011dd436)
        return false;
    bretValue = false;
    pstation = FalloutRadio::GetRadioConversation(((FNVHelper00835b90*)apTargetStation)->_FNV_GetObjectReference());
    if (pstation)
        bretValue = ((FUN_00833040_shell*)((char*)pstation + 4))->IsFlag20Set();
    return bretValue;
}
}  // namespace fnv_00835b90

TESForm* __cdecl GetFormByID(unsigned int);
struct ListStandIn
{
    void FUN_008363a0(void*);
};
struct StateStandIn
{
    TESObjectREFR* f0;
    ListStandIn f4;
    void FUN_00836660(void*);
};
// @fnv 0x00836660
void StateStandIn::FUN_00836660(void* apLoadGameBuffer)
{
    f0 = f0 ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)f0)) : 0;
    f4.FUN_008363a0(apLoadGameBuffer);
}

namespace fnv_00837290 {
struct RadioConvTask
{
    void FUN_008372c0();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_008372c0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00837290
void* RadioConvTask::DestroyIfFlagged(unsigned int flags)
{
    FUN_008372c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00837290

struct FUN_0083b9f0_node
{
    FUN_0083b9f0_node* _ref_00726070();
    int* _ref_006815c0();
};
struct FUN_0083b9f0_shell
{
    int _pad0;
    int _pad4;
    FUN_0083b9f0_node* _f8;
    bool FUN_0083b9f0();
};
// If _f8 is set, replaces it with the result of _ref_00726070, then returns whether _f8 is non-null and its _ref_006815c0 value is non-zero.
// @fnv 0x0083b9f0
bool FUN_0083b9f0_shell::FUN_0083b9f0()
{
    if (_f8)
        _f8 = _f8->_ref_00726070();
    return _f8 && *_f8->_ref_006815c0();
}

namespace fnv_0083c470 {
bool __fastcall _ref_008256d0(void*);
void** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
void __fastcall ProcessNodeChain(void*);
struct FUN_0083c470_holder
{
    void FUN_0083c470();
};
// @fnv 0x0083c470
void FUN_0083c470_holder::FUN_0083c470()
{
    void* pNode = this;
    while (pNode && !_ref_008256d0(pNode))
    {
        if (pNode && *_ref_006815c0(pNode))
            ProcessNodeChain(*_ref_006815c0(pNode));
        pNode = _ref_00726070(pNode);
    }
}
}  // namespace fnv_0083c470

namespace fnv_00833150 {
struct FUN_00833170
{
    FUN_00833170();
    void Call();
};

struct FUN_00833150_shell
{
    int a;
    FUN_00833170 b;
    int c;
    FUN_00833150_shell* FUN_00833150();
};

FUN_00833170::FUN_00833170()
{}

void FUN_00833170::Call()
{}

// @fnv 0x00833150
FUN_00833150_shell* FUN_00833150_shell::FUN_00833150()
{
    b.Call();
    return this;
}
}  // namespace fnv_00833150

struct FUN_00836470_shell
{
    void __thiscall UpdateSoundItems(int a);
};

struct FUN_008366c0_shell
{
    void __thiscall FUN_008366c0(int a);
};

// @fnv 0x008366c0
void __thiscall FUN_008366c0_shell::FUN_008366c0(int a)
{
    ((FUN_00836470_shell*)((char*)this + 4))->UpdateSoundItems(a);
}

struct FUN_00832420_shell
{
    char _pad[0x14];
    unsigned int mFlags;
    bool IsFlag100Set();
};

// @fnv 0x00832420
bool FUN_00832420_shell::IsFlag100Set()
{
    return (mFlags & 0x100) != 0;
}

struct FUN_00833c40_shell
{
    char _pad[0x14];
    unsigned int kData;
    void FUN_00833c40(bool enabled);
};

// @fnv 0x00833c40
void FUN_00833c40_shell::FUN_00833c40(bool enabled)
{
    enabled ? (this->kData |= 8) : (this->kData &= ~8);
}

struct FUN_00833c90_shell
{
    unsigned int pad0[5];  // +0x00 .. +0x13
    unsigned int flags;    // +0x14
    void SetFlag40(bool enabled);
};

// Sets or clears bit 0x40 in flags according to enabled.
// @fnv 0x00833c90
void FUN_00833c90_shell::SetFlag40(bool enabled)
{
    enabled ? flags |= 0x40 : flags &= ~0x40;
}

namespace fnv_008372e0 {
struct TESTopic
{
    static TESTopic* GetAudioBackendData(int, int);
};
struct Character;
struct PlayerCharacter;
struct Conversation
{
    Conversation(Character*, Character*, TESTopic*);
    char m_data[12];
};
struct RadioConversation
{
    Character* pCharacter;
    Character* pCharacter2;
    Conversation* m_pkConversation;
};
struct QueuedFileEntry
{
    char m_data[0x30];
    RadioConversation* pCurrentRadioStation;
};
struct RadioConvTask : QueuedFileEntry
{
    void FUN_008372e0();
};

// @fnv 0x008372e0
void RadioConvTask::FUN_008372e0()
{
    if (pCurrentRadioStation && !pCurrentRadioStation->m_pkConversation)
        pCurrentRadioStation->m_pkConversation = new Conversation(
            pCurrentRadioStation->pCharacter, pCurrentRadioStation->pCharacter, TESTopic::GetAudioBackendData(7, 0));
}
}  // namespace fnv_008372e0

class TESActorBase : public TESForm
{
  public:
};

TESForm* LookupFormByID(unsigned int auiID);

class LoadBuffer
{
  public:
    unsigned int ReadCount();
    unsigned int ReadFormID();
    void Read(void* apDest, unsigned int auiSize);
    void ReadRefID(unsigned int* apID);
};

class SaveRef
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Unk55();
    virtual void Unk56();
    virtual void Unk57();
    virtual void Unk58();
    virtual void Unk59();
    virtual void Unk60();
    virtual void Unk61();
    virtual void Unk62();
    virtual void Unk63();
    virtual void Unk64();
    virtual void Unk65();
    virtual void Unk66();
    virtual void Unk67();
    virtual void Unk68();
    virtual void Unk69();
    virtual void Unk70();
    virtual void Unk71();
    virtual void Unk72();
    virtual void Unk73();
    virtual void Restore(unsigned int auiID, bool abFlag);
    unsigned int GetModIndex();
};

struct GridCellStub
{
    SaveRef* pRef;
};

class GridCellArray
{
  public:
    GridCellStub* Get(unsigned int x, unsigned int y);
};

class DataHandlerStub
{
  public:
    bool IsModLoaded(unsigned int auiIndex);
};

class SaveLoadStub
{
  public:
    void MarkRefID(unsigned int auiID);
};

extern DataHandlerStub* g_pDataHandlerStub;
extern SaveLoadStub* g_BGSSaveLoadGame;

struct ActorEntry
{
    TESActorBase* pActor;
    unsigned short usValue;
};

template <class T> class SimpleList
{
  public:
    T m_item;
    SimpleList<T>* m_pkNext;
    void AddHead(T& item);
};

class GridHolder
{
  public:
    int unk00;
    int unk04;
    GridCellArray* pGrid;
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
    SimpleList<ActorEntry*> kEntries;
    void Load(LoadBuffer* apBuffer);
};

// @fnv 0x004595e0
void GridHolder::Load(LoadBuffer* apBuffer)
{
    unsigned int uiActorCount = apBuffer->ReadCount();
    for (unsigned int i = 0; i < uiActorCount; i++)
    {
        ActorEntry* pEntry = new ActorEntry;
        pEntry->pActor = dynamic_cast<TESActorBase*>(LookupFormByID(apBuffer->ReadFormID()));
        apBuffer->Read(&pEntry->usValue, 2);
        kEntries.AddHead(pEntry);
    }
    unsigned int uiSize = 0;
    apBuffer->Read(&uiSize, 4);
    for (unsigned int x = 0; x < uiSize; x++)
    {
        for (unsigned int y = 0; y < uiSize; y++)
        {
            SaveRef* pRef = pGrid->Get(x, y)->pRef;
            unsigned int uiRefID = 0;
            apBuffer->ReadRefID(&uiRefID);
            if (pRef && uiRefID && g_pDataHandlerStub->IsModLoaded(pRef->GetModIndex()))
            {
                g_BGSSaveLoadGame->MarkRefID(uiRefID);
                pRef->Restore(uiRefID, true);
            }
        }
    }
}

unsigned int __fastcall FUN_007af430(void* pForm);
bool __fastcall FUN_00440da0(void* pForm);
unsigned int __fastcall FUN_0056b210(void* pForm);

// @fnv 0x00832830
FalloutRadio::RadioReceiver* __cdecl FUN_00832830(unsigned int aiFormID)
{
    BSSimpleList<FalloutRadio::RadioReceiver*>* pNode;
    FalloutRadio::RadioReceiver* pFound2 = 0;
    pNode = (BSSimpleList<FalloutRadio::RadioReceiver*>*)&DAT_011dd554;
    unsigned int iFoundState = 0;

    if (DAT_011dd436)
        return 0;

    while (pNode != 0 && !pNode->IsEmpty())
    {
        if (aiFormID == FUN_007af430(pNode->GetItem()->form))
        {
            if (pFound2 == 0 || (FUN_00440da0(pFound2->form) && !FUN_00440da0(pNode->GetItem()->form)) ||
                (iFoundState == 0 && FUN_0056b210(pNode->GetItem()->form)) ||
                (iFoundState != 1 && FUN_0056b210(pNode->GetItem()->form) == 1))
            {
                pFound2 = pNode->GetItem();
                iFoundState = FUN_0056b210(pFound2->form);
            }
        }
        pNode = pNode->GetNext();
    }
    return pFound2;
}

class Character;
class TESTopic;
class Conversation
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    Conversation(Character*, PlayerCharacter*, TESTopic*);
    ~Conversation();
    void* FUN_00798450(unsigned int);
};
struct RadioState
{
    Character* character;
    Conversation* current;
    Conversation* next;
};
struct FUN_00837250
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
    FUN_00837250(RadioState*);
};
struct IOManagerView
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18(FUN_00837250*);
};
extern IOManagerView* DAT_01202d98;
TESTopic* GetTopicSubTypeName(int, int);
// @fnv 0x00837060
bool AdvanceConversation(RadioState* state, TESTopic* apSuppliedTopic)
{
    bool queued = false;
    TESTopic* pTopic = apSuppliedTopic == 0 ? GetTopicSubTypeName(7, 0) : apSuppliedTopic;
    FUN_00837250* pTopicTask;
    if (state->next)
    {
        if (state->current)
        {
            Conversation* previous = state->current;
            Conversation* deleting = previous;
            deleting ? deleting->FUN_00798450(1) : 0;
            state->current = 0;
        }
        state->current = state->next;
        {
            Conversation* following = state->next;
            Conversation* deletingNext = following;
            deletingNext ? deletingNext->FUN_00798450(1) : 0;
            state->next = 0;
        }
        {
            pTopicTask = new FUN_00837250(state);
        }
        DAT_01202d98->vfn18(pTopicTask);
        queued = true;
    }
    else
    {
        if (state->current)
        {
            delete state->current;
            state->current = 0;
        }
        state->current = new Conversation(state->character, (PlayerCharacter*)state->character, pTopic);
        queued = false;
    }
    return queued;
}

struct FUN_008372c0_Base
{
    virtual void vf0();
    ~FUN_008372c0_Base();
};
struct FUN_008372c0 : FUN_008372c0_Base
{
// @fnv 0x008372c0
    FUN_008372c0(int)
    {}
    virtual ~FUN_008372c0();
};
FUN_008372c0::~FUN_008372c0()
{}

namespace fnv_00832240 {
struct RefView
{
    void* FUN_007af430();
};
struct AudioClock
{
    unsigned int FUN_0063d040();
};
AudioClock* FUN_00453a70();
void FUN_00403d30(void*, int, unsigned int);
extern char DAT_011dd448[260];
struct RadioSub
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, flags;
    bool IsFlag100Set();
    void SetFlag100(bool);
    void FUN_00832440(bool);
};
struct RadioState
{
    RefView* form;
    RadioSub sub;
};
extern RadioState* g_011dd42c;
RadioState* FUN_00832830(void*);
RadioState* CreateRadioStationState(RefView*, int);
void FUN_008324e0(int);
// Clears DAT_011dd448, resolves a radio station from the player or the given form, stores it in g_011dd42c and updates its sub-state timers and flags.
// @fnv 0x00832240
bool FUN_00832240(RefView* form, bool flag)
{
    if (!DAT_011dd434 || DAT_011dd436)
        return false;
    FUN_00403d30(DAT_011dd448, 0, 260);
    int state = 0;
    if (!form)
    {
        BSSimpleListEx<RadioStationRef*> item;
        BGSTalkingActivator::FindRadioStations((TESObjectREFR*)g_thePlayer, &item, 0);
        BSSimpleList<RadioStationRef*>* list = &item;
        if (list && list->GetItem() && ((RefView*)list->GetItem())->FUN_007af430())
            form = (RefView*)list->GetItem();
    }
    else if (flag)
    {
        DAT_011dd430 = 0;
        UpdateRadioSignals(true);
    }
    g_011dd42c = FUN_00832830(form->FUN_007af430());
    if (!g_011dd42c)
    {
        g_011dd42c = CreateRadioStationState(form, 0);
        if (!g_011dd42c)
            FUN_008324e0(0);
        if (!flag)
            UpdateRadioSignals(true);
    }
    else if (g_011dd42c->form->FUN_007af430() == form->FUN_007af430())
    {
        g_011dd42c->form = form;
    }
    if (g_011dd42c->sub.IsFlag100Set())
    {
        g_011dd42c->sub.unk08 = FUN_00453a70()->FUN_0063d040() + 50;
        g_011dd42c->sub.SetFlag100(false);
    }
    g_011dd42c->sub.FUN_00832440(true);
    DAT_011dd430 = 0;
    return true;
}
}  // namespace fnv_00832240

namespace RadioUpdate {
extern const double DAT_01017a40, DAT_0101ffa0;
extern const float DAT_010162c0, DAT_01016264;
extern const char DAT_0107ce80[], DAT_0107ce44[], DAT_0107ce34[], DAT_0107ce2c[], DAT_0107ce20[], DAT_0101996c[];
struct Station;
struct Player;
struct Vec3
{
    float x, y, z;
};
struct Sound
{
    unsigned int id;
    bool success;
    char unk05, unk06, unk07;
    int state;
    Sound(const Sound&);
    ~Sound();
    Sound& operator=(const Sound&);
    void Play(int);
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    bool FUN_00ad8ce0();
    bool FUN_00ad8930();
    int FUN_00ad8b30();
    void FUN_00ad89e0(float);
    void FUN_00ad8e60(void (*)(Station*), Station*);
    void FUN_00ad8fd0(unsigned int);
    void FUN_004f15a0(int);
};
extern Sound DAT_011dd638, DAT_011dd5bc;
struct String
{
    char* text;
    unsigned short length, capacity;
    String();
    String(const char*);
    ~String();
    const char* FUN_00559450();
    const char* FUN_00403df0();
};
extern String DAT_011d25f8;
struct Activator
{
    const char* FUN_0055d520();
};
struct SoundForm
{
    const char* FUN_00511840();
};
struct Info
{
    bool FUN_00700270(int);
    const char* FUN_00559450();
};
struct Entry
{
    SoundForm* FUN_007af430();
    String* FUN_006815c0();
    Info* FUN_00460140();
};
struct Track
{
    Entry* FUN_0083c820();
    void FUN_0083c7b0();
};
struct Node
{
    Track* FUN_0083c820();
};
struct State
{
    Node* node;
    int unk04;
    unsigned int elapsed;
    int duration;
    unsigned char FUN_00833c20();
    bool FUN_00833bc0();
    bool IsFlag20Set();
    bool IsFlag80Set();
    bool FUN_00833be0();
    void FUN_00833c40(bool);
    void SetFlag40(bool);
};
struct Station
{
    Activator* form;
    State state;
};
extern Station* DAT_011dd42c;
extern Station* DAT_011dd430;
struct Manager
{
    Sound FUN_00ad7550(const char*, unsigned int);
    Sound FUN_00ad7480(const char*, unsigned int, SoundForm*);
    unsigned int FUN_0063d040();
    float FUN_00ad7ae0();
};
Manager* FUN_00453a70();
struct UI
{
    void AddMessage(const char*, int, const char*, int, float, int);
};
extern UI* DAT_011d96c0;
struct Player
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
    virtual const Vec3& Position();
};
extern Player* DAT_011dea3c;
void FUN_00406f60(String*, const char*, ...);
void FUN_008324e0(int);
float FUN_004dd150(float, float);
bool FUN_00830750(int, int);
bool FUN_00833ce0();
bool FUN_00833cf0();
unsigned int FUN_0044a670(const char*);
int FUN_00ec7750(const char*, const char*);
void FUN_008357e0(Station*);
void FUN_00705210(const char*, Sound, Vec3, Player*, bool);
void FUN_00406d00(char*, unsigned int, const char*, ...);
void FUN_00406d30(char*, unsigned int, const char*);
void PlayAudioMedia(int, const char*, int, int, int, float, unsigned int);
unsigned int FUN_008308c0(int);
extern char DAT_011dd448[260];
// Updates the radio station state: plays or stops sounds, sets volume, handles voice tracks and resets the current sound when idle.
// @fnv 0x008331c0
void UpdateRadio(bool force)
{
    float volume = DAT_011dd42c ? DAT_011dd42c->state.FUN_00833c20() / DAT_01017a40 : 0.0;
    bool volumeSet = false;
    if (DAT_011dd42c && DAT_011dd42c->state.FUN_00833bc0())
    {
        String message3;
        Sound sound = FUN_00453a70()->FUN_00ad7550(DAT_0107ce80, 0x100121);
        sound.Play(0);
        FUN_00406f60(&message3, DAT_011d25f8.FUN_00403df0(), DAT_011dd42c->form->FUN_0055d520());
        DAT_011dd430 = DAT_011dd42c;
        FUN_008324e0(0);
        DAT_011dd638.FUN_00ad88f0();
        DAT_011dd638.FUN_00ad8d10();
        DAT_011d96c0->AddMessage(message3.FUN_00559450(), 0, DAT_0107ce44, 0, DAT_010162c0, 0);
        return;
    }
    else if (DAT_011dd42c && DAT_011dd42c->state.FUN_00833c20() < 100)
    {
        if (!DAT_011dd638.FUN_00ad8ce0())
        {
            DAT_011dd638.FUN_00ad88f0();
            DAT_011dd638.FUN_00ad8d10();
            DAT_011dd638 = FUN_00453a70()->FUN_00ad7550(DAT_0107ce34, 0x100031);
            DAT_011dd638.Play(0);
        }
        DAT_011dd638.FUN_00ad89e0(
            FUN_004dd150((100 - DAT_011dd42c->state.FUN_00833c20()) / DAT_01017a40, DAT_01016264));
    }
    else if (DAT_011dd42c && DAT_011dd42c->state.FUN_00833c20() == 100 && DAT_011dd638.FUN_00ad8ce0())
    {
        DAT_011dd638.FUN_00ad88f0();
        DAT_011dd638.FUN_00ad8d10();
    }
    if (DAT_011dd42c && DAT_011dd42c->state.duration <= 0 && DAT_011dd5bc.FUN_00ad8ce0() && DAT_011dd5bc.FUN_00ad8b30())
        DAT_011dd42c->state.duration = DAT_011dd5bc.FUN_00ad8b30();
    if (DAT_011dd42c && DAT_011dd42c->state.node && ((!FUN_00830750(7, 1) && !DAT_011dd5bc.FUN_00ad8ce0()) || force))
    {
        Track* track = DAT_011dd42c->state.node->FUN_0083c820();
        if (!track)
            return;
        bool hasVoice_ = false;
        bool FlushUsageData = false;
        bool hasSound3 = false;
        unsigned int kindB = 0;
        if (!track->FUN_0083c820())
            track->FUN_0083c7b0();
        if (track->FUN_0083c820() && track->FUN_0083c820()->FUN_007af430() && !FUN_00833ce0())
        {
            hasVoice_ = true;
            if (DAT_011dd42c)
                DAT_011dd42c->state.FUN_00833c40(true);
        }
        else
        {
            if (DAT_011dd42c)
                DAT_011dd42c->state.FUN_00833c40(false);
        }
        if (track->FUN_0083c820() && track->FUN_0083c820()->FUN_006815c0()->FUN_00559450())
        {
            kindB = FUN_0044a670(track->FUN_0083c820()->FUN_006815c0()->FUN_00559450());
            hasSound3 = kindB > 2 && track->FUN_0083c820()->FUN_00460140()->FUN_00700270(0);
            if (!hasSound3 && track->FUN_0083c820()->FUN_007af430() &&
                FUN_00ec7750(track->FUN_0083c820()->FUN_007af430()->FUN_00511840(), DAT_0107ce2c))
                hasSound3 = true;
        }
        unsigned int age = FUN_00453a70()->FUN_0063d040() - DAT_011dd42c->state.elapsed;
        if (hasSound3)
        {
            bool formSound = track->FUN_0083c820()->FUN_007af430() != 0;
            DAT_011dd5bc.FUN_00ad88f0();
            DAT_011dd5bc.FUN_00ad8d10();
            if (formSound)
                DAT_011dd5bc = FUN_00453a70()->FUN_00ad7480(track->FUN_0083c820()->FUN_007af430()->FUN_00511840(),
                                                            0x100101, track->FUN_0083c820()->FUN_007af430());
            else
                DAT_011dd5bc =
                    FUN_00453a70()->FUN_00ad7480(track->FUN_0083c820()->FUN_00460140()->FUN_00559450(), 0x100101, 0);
            DAT_011dd5bc.FUN_00ad8e60(FUN_008357e0, DAT_011dd42c);
            DAT_011dd5bc.FUN_00ad8fd0(DAT_011dd42c->state.elapsed);
            if (FUN_00833cf0())
                DAT_011dd5bc.FUN_00ad89e0(volume * DAT_0101ffa0);
            else
                DAT_011dd5bc.FUN_00ad89e0(FUN_00453a70()->FUN_00ad7ae0() * volume);
            volumeSet = true;
            DAT_011dd5bc.Play(0);
            if (!DAT_011dd5bc.FUN_00ad8ce0())
                FUN_00705210(track->FUN_0083c820()->FUN_006815c0()->FUN_00559450(), DAT_011dd5bc,
                             DAT_011dea3c->Position(), DAT_011dea3c, false);
        }
        if (hasVoice_ && !FUN_00833ce0())
        {
            char path2[260];
            FUN_00406d00(path2, 260, DAT_0101996c, DAT_0107ce20, track->FUN_0083c820()->FUN_007af430()->FUN_00511840());
            String filename(path2);
            PlayAudioMedia(7, path2, 500, 0, 1, 0.0f, DAT_011dd42c->state.elapsed);
            FUN_00406d30(DAT_011dd448, 260, path2);
            DAT_011dd42c->state.FUN_00833c40(true);
            if (DAT_011dd42c->state.duration <= 0 && FUN_008308c0(7) > 0)
                DAT_011dd42c->state.duration = FUN_008308c0(7);
        }
        else
            DAT_011dd42c->state.FUN_00833c40(false);
        if (!hasVoice_ && !hasSound3)
            DAT_011dd42c->state.duration = 1;
    }
    else if (!DAT_011dd42c->state.IsFlag20Set() && !DAT_011dd42c->state.IsFlag80Set() &&
             !DAT_011dd42c->state.FUN_00833be0() && !DAT_011dd5bc.FUN_00ad8930())
    {
        DAT_011dd5bc.FUN_00ad88f0();
        DAT_011dd5bc.FUN_00ad8d10();
        DAT_011dd5bc = FUN_00453a70()->FUN_00ad7550(DAT_0107ce34, 0x100031);
        DAT_011dd5bc.FUN_004f15a0(1);
        DAT_011dd5bc.Play(0);
        DAT_011dd42c->state.SetFlag40(true);
        DAT_011dd42c->state.FUN_00833c40(false);
    }
    if (!volumeSet)
    {
        if (FUN_00833cf0())
            DAT_011dd5bc.FUN_00ad89e0(volume * DAT_0101ffa0);
        else
            DAT_011dd5bc.FUN_00ad89e0(FUN_00453a70()->FUN_00ad7ae0() * volume);
    }
}
}

struct S_008356e0_Item
{
    int FUN_007af430();
};
struct S_008356e0_Node
{
    S_008356e0_Item** FUN_006815c0();
    S_008356e0_Node* FUN_00726070();
};
struct S_008356e0_Ref;
extern S_008356e0_Ref* DAT_011dea3c;
void __cdecl FUN_004ff1a0(S_008356e0_Ref* ref, BSSimpleListEx<S_008356e0_Item*>* list, int flags);

// Builds a list via FUN_004ff1a0 from b or DAT_011dea3c, walks it, and returns the first item whose FUN_007af430 equals a.
// @fnv 0x008356e0
S_008356e0_Item* __cdecl FUN_008356e0(int a, S_008356e0_Ref* apRef)
{
    S_008356e0_Item* result = 0;
    BSSimpleListEx<S_008356e0_Item*> _list;
    if (apRef == 0)
    {
        FUN_004ff1a0(DAT_011dea3c, &_list, 0);
    }
    else
    {
        FUN_004ff1a0(apRef, &_list, 0);
    }
    S_008356e0_Node* node = (S_008356e0_Node*)&_list;
    bool foundTmp = false;
    while (!foundTmp && node && *node->FUN_006815c0() && (*node->FUN_006815c0())->FUN_007af430())
    {
        if (a == (*node->FUN_006815c0())->FUN_007af430())
        {
            result = *node->FUN_006815c0();
            foundTmp = true;
        }
        node = node->FUN_00726070();
    }
    return result;
}

#include <windows.h>

namespace radio_detail {
struct FUN_008327d0
{
    void* form;
    SoundPlaybackHandle sound;
    int unk10;
    int unk14;
    int unk18;
    unsigned char active;
    unsigned char playing;
    unsigned char unk1e;
    unsigned char changed;
    FUN_008327d0();
};
}
struct ReceiverList
{
    void FUN_005ae3d0(radio_detail::FUN_008327d0**);
};
struct StationView
{
    void* form;
    FUN_00832440_shell state;
    ReceiverList receivers;
};
struct ReferenceView
{
    void* FUN_007af430();
};
struct AudioView
{
    unsigned int FUN_0063d040();
};
AudioView* FUN_00453a70();
StationView* FUN_00832830(void*);
StationView* CreateRadioStationState(void*, ReferenceView*);
// Creates or finds the radio station for ref, marks it active/playing/changed, registers it with the receiver list and enables the receiver state.
// @fnv 0x00835810
void FUN_00835810(TESObjectREFR_Stub* ref, ReferenceView* source)
{
    int elapsed = 0;
    radio_detail::FUN_008327d0* station = (radio_detail::FUN_008327d0*)FUN_00832930(ref);
    unsigned int soundTime = 0;
    bool created = false;
    if (DAT_011dd436)
        return;
    StationView* receiver = FUN_00832830(source->FUN_007af430());
    if (receiver)
        soundTime = FUN_00453a70()->FUN_0063d040() - receiver->state.pad2_8;
    else
    {
        receiver = CreateRadioStationState(ref, source);
        if (receiver && !receiver->form)
            DebugBreak();
        if (!receiver)
            return;
    }
    if (!station)
    {
        station = new radio_detail::FUN_008327d0;
        created = true;
    }
    station->form = ref;
    station->active = 1;
    station->playing = 1;
    station->changed = 1;
    if (created)
        ((ReceiverList*)&DAT_011dd58c)->FUN_005ae3d0(&station);
    receiver->receivers.FUN_005ae3d0(&station);
    receiver->state.FUN_00832440(true);
}

namespace fnv_008359e0 {
struct Conversation
{
    ~Conversation();
};
struct RadioStateData
{
    Conversation* conversation;
    unsigned int unk04, unk08, unk0c, unk10, flags;
    bool IsFlag20Set();
    void SetFlag(bool);
    void FUN_00833100(bool);
};
struct RadioStation
{
    void* form;
    RadioStateData data;
    BSSimpleList<FalloutRadio::RadioReceiver*> receivers;
};
struct RadioRef
{
    void SetRefFlag40000000(bool);
};
struct RadioSource
{
    RadioRef* FUN_007af430();
};
struct SoundHandleHelper : SoundPlaybackHandle
{
    bool IsValid();
};
RadioStation* FUN_00832830(RadioRef*);
struct GlobalObject_0044fae0
{
    void FUN_004538a0(const char*);
    void FUN_004538c0();
};
extern GlobalObject_0044fae0 g_011dd5e8;
void FUN_008304a0();
void FUN_008304c0();
void PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
// @fnv 0x008359e0
void FUN_008359e0(RadioSource* source, bool enabled)
{
    if (DAT_011dd436)
        return;
    RadioStation* station = FUN_00832830(source->FUN_007af430());
    g_011dd5e8.FUN_004538a0("FalloutRadio::SetBroadcastState");
    source->FUN_007af430()->SetRefFlag40000000(enabled);
    if (station)
    {
        if (station->data.IsFlag20Set() && !enabled)
        {
            BSSimpleList<FalloutRadio::RadioReceiver*>* node = &station->receivers;
            while (node && !_ref_008256d0(node))
            {
                if (((SoundHandleHelper*)&(*_ref_006815c0(node))->sound)->IsValid())
                {
                    (*_ref_006815c0(node))->sound.Stop();
                    (*_ref_006815c0(node))->sound.Release();
                }
                node = _ref_00726070(node);
            }
            if (DAT_011dd42c == (unsigned int)station && DAT_011dd434)
            {
                DAT_011dd5bc.Stop();
                DAT_011dd5bc.Release();
                if (!FUN_00833ce0())
                {
                    FUN_008304a0();
                    FUN_008325a0(true);
                    PlayAudioMedia(7, 0, 1000, false, false, 0.0f, 0);
                    FUN_008304c0();
                }
            }
            station->data.SetFlag(false);
            delete station->data.conversation;
            station->data.conversation = 0;
        }
        station->data.FUN_00833100(enabled);
    }
    g_011dd5e8.FUN_004538c0();
}
}  // namespace fnv_008359e0

void __cdecl FUN_008324e0(bool enabled);
void __cdecl UpdateRadio(bool enabled);
// Iterates the radio receiver list, calls FUN_008366c0 on each receiver, removes null entries, then calls FUN_008324e0 and UpdateRadio.
// @fnv 0x00836e20
void __cdecl UpdateRadioReceivers(int updateMode)
{
    BSSimpleList<FalloutRadio::RadioStationState*>* current = &DAT_011dd554;
    BSSimpleList<FalloutRadio::RadioStationState*>* previous = 0;
    while (current != 0 && !current->IsEmpty())
    {
        FalloutRadio::RadioStationState* receiver = current->GetItem();
        bool remove = false;
        if (receiver != 0)
            reinterpret_cast<FUN_008366c0_shell*>(receiver)->FUN_008366c0(updateMode);
        else
            remove = true;
        if (remove)
        {
            if (previous != 0)
            {
                previous->Remove(current->GetItem());
                current = previous->GetNext();
            }
            else
                current->RemoveHead();
        }
        else
        {
            previous = current;
            current = current->GetNext();
        }
    }
    FUN_008324e0(DAT_011dd434);
    if (DAT_011dd42c != 0)
        UpdateRadio(true);
}

extern unsigned int DAT_011dd428;
extern bool DAT_011dd448;
struct FUN_00832160
{
    ~FUN_00832160();
};
struct SoundCleanup
{
    bool FUN_00ad8ce0();
    bool FUN_00ad88f0();
    bool FUN_00ad8d10();
};
struct FUN_00832190
{
    void* form;
    SoundCleanup sound;
    ~FUN_00832190();
};
struct RadioListCleanup
{
    void FUN_00470470();
};
// Resets radio globals, deletes all queued items from two lists, and stops the sound objects in the radio lists.
// @fnv 0x00836ef0
void ResetRadioGlobals()
{
    DAT_011dd42c = 0;
    DAT_011dd430 = 0;
    DAT_011dd424 = 1;
    DAT_011dd428 = 0;
    DAT_011dd434 = false;
    DAT_011a179c = 1;
    DAT_011dd448 = false;
    while (!DAT_011dd554.IsEmpty())
    {
        delete reinterpret_cast<FUN_00832160*>(DAT_011dd554.GetItem());
        DAT_011dd554.RemoveHead();
    }
    while (!DAT_011dd58c.IsEmpty())
    {
        FUN_00832190* receiver = reinterpret_cast<FUN_00832190*>(DAT_011dd58c.GetItem());
        if (receiver->sound.FUN_00ad8ce0())
        {
            receiver->sound.FUN_00ad88f0();
            receiver->sound.FUN_00ad8d10();
        }
        delete receiver;
        DAT_011dd58c.RemoveHead();
    }
    reinterpret_cast<RadioListCleanup&>(DAT_011dd59c).FUN_00470470();
    if (reinterpret_cast<SoundCleanup&>(DAT_011dd5bc).FUN_00ad8ce0())
    {
        reinterpret_cast<SoundCleanup&>(DAT_011dd5bc).FUN_00ad88f0();
        reinterpret_cast<SoundCleanup&>(DAT_011dd5bc).FUN_00ad8d10();
    }
    if (reinterpret_cast<SoundCleanup&>(DAT_011dd638).FUN_00ad8ce0())
    {
        reinterpret_cast<SoundCleanup&>(DAT_011dd638).FUN_00ad88f0();
        reinterpret_cast<SoundCleanup&>(DAT_011dd638).FUN_00ad8d10();
    }
}

// 0x008325b0  /MT /Od /Oy- /GS /EHsc /Gy

class Rec;

struct SndH
{
    unsigned int m_uiSoundResourceID;
    unsigned char m_bLooping;
    unsigned char pad[3];
    unsigned int eState;
    void FUN_00832440(bool);
    bool IsFlag100Set();
    void SetFlag100(bool);
    bool Stop();
    bool Release();
};

class Rec
{
  public:
    Rec();
    void* form;
    SndH snd;
    SndH snd2;
    unsigned char active;
    unsigned char f1d;
    unsigned char f1e;
    unsigned char f1f;
};

struct RecList
{
    void SetItem(Rec*& r);
};

struct Sta
{
    void* form;
    SndH sound;
    int pad[3];
    RecList receivers;
};

class Form2
{
  public:
    int GetFormType();
};

class Ref
{
  public:
    Form2* GetObjectReference();
};

class EffSetting : public Form2
{
  public:
    TESSound* GetBoltSound();
};

class BSAud
{
  public:
    static BSAud* GetSingleton();
    unsigned int GetSynchTime();
};

Rec* __cdecl FUN_00832930(Ref*);
Sta* __cdecl FUN_00832830(TESSound*);
Sta* __cdecl CreateRadioStationState(Ref*, bool);
void __cdecl FUN_008329a0(bool);

class Shell
{
  public:
    static void FUN_008325b0(Ref* ref, bool bArg);
};

// Enables or disables the bolt sound for a reference, creating or releasing its sound record and updating the sound state.
// @fnv 0x008325b0
void Shell::FUN_008325b0(Ref* ref, bool abEnable)
{
    if (DAT_011dd436)
    {
        return;
    }
    TESSound* pSound8 = 0;
    Rec* rec = FUN_00832930(ref);
    int iUnused = 0;
    bool bNewRec = false;
    if (rec != 0 && ((abEnable && rec->active) || (!abEnable && !rec->active)))
    {
        return;
    }
    if (ref != 0 && ref->GetObjectReference()->GetFormType() == 0x15)
    {
        pSound8 = ((EffSetting*)ref->GetObjectReference())->GetBoltSound();
    }
    if (pSound8 == 0)
    {
        return;
    }
    Sta* sta = FUN_00832830(pSound8);
    if (abEnable)
    {
        if (sta == 0)
        {
            sta = CreateRadioStationState(ref, 0);
            if (sta == 0)
            {
                return;
            }
        }
        if (rec == 0)
        {
            rec = new Rec();
            bNewRec = true;
        }
        rec->form = ref;
        rec->active = 1;
        rec->f1d = 1;
        rec->f1f = 0;
        if (bNewRec)
        {
            ((RecList*)&DAT_011dd58c)->SetItem(rec);
        }
        sta->receivers.SetItem(rec);
        sta->sound.FUN_00832440(1);
        if (sta->sound.IsFlag100Set())
        {
            sta->sound.eState = BSAud::GetSingleton()->GetSynchTime() + 0x32;
            sta->sound.SetFlag100(0);
        }
    }
    else
    {
        if (rec != 0)
        {
            rec->snd.Stop();
            rec->snd.Release();
            rec->snd2.Stop();
            rec->snd2.Release();
            rec->active = 0;
            FUN_008329a0(0);
        }
    }
}

namespace fnv_00832cb0 {
class P01ObjA
{
  public:
    TESForm* GetNext();
};

class FUN_00475120_shell
{
  public:
    int GetFormType();
};

class EffectSetting
{
  public:
    TESSound* GetBoltSound();
};

class FUN_00832160
{
  public:
    ~FUN_00832160();
};

class FUN_00833100_shell
{
  public:
    void FUN_00833100(bool);
};

class FUN_00833040_shell
{
  public:
    bool IsFlag20Set();
};

class FUN_008330b0_shell
{
  public:
    void SetFlag(bool);
};

class FUN_00833060_shell
{
  public:
    void FUN_00833060(bool);
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    unsigned int GetSynchTime();
};

extern "C" unsigned int __cdecl GetRandomNumberInRange(int, int);

class G2
{
  public:
    void AddHead(int*&);
};

extern "C" void* __cdecl FUN_008356e0(void*, TESObjectREFR*);

class FUN_00833150 : public FalloutRadio::RadioStationState
{
  public:
    FUN_00833150();
};

class MyForm : public TESForm
{
  public:
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual bool vfn_b4();
};

class MyREFR : public TESObjectREFR
{
  public:
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool vfn_100();
};

struct StationData
{
    void* form;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char unk14;
    unsigned char unk15;
};

// Builds a new radio station state from a1 (and a2), resolving the station form via sound or activator, initialising timing fields and adding it to the list.
// @fnv 0x00832cb0
FalloutRadio::RadioStationState* CreateRadioStationState(TESObjectREFR* a1, TESObjectREFR* a2)
{
    FalloutRadio::RadioStationState* state3;
    bool isTalkingActivator;
    bool isStation3;
    void* stationForm3;
    TESSound* sound;
    void* space5;

    if (!a1)
        return 0;

    isStation3 = false;
    isTalkingActivator = false;
    stationForm3 = 0;

    state3 = new FUN_00833150();

    if (((FUN_00475120_shell*)((P01ObjA*)a1)->GetNext())->GetFormType() == 0x15 ||
        ((FUN_00475120_shell*)((P01ObjA*)a1)->GetNext())->GetFormType() == 0x2a ||
        ((FUN_00475120_shell*)((P01ObjA*)a1)->GetNext())->GetFormType() == 0x2b ||
        ((FUN_00475120_shell*)((P01ObjA*)a1)->GetNext())->GetFormType() == 0x2c ||
        ((FUN_00475120_shell*)((P01ObjA*)a1)->GetNext())->GetFormType() == 0x2d)
    {
        isStation3 = true;
    }

    if (((FUN_00475120_shell*)((P01ObjA*)a1)->GetNext())->GetFormType() == 0x16)
    {
        isTalkingActivator = true;
    }

    if (isStation3 && !((MyREFR*)a1)->vfn_100())
    {
        sound = ((EffectSetting*)((P01ObjA*)a1)->GetNext())->GetBoltSound();
        if (!sound)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
        stationForm3 = FUN_008356e0(sound, a1);
        if (!stationForm3)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
    }
    else if (isStation3 && ((MyREFR*)a1)->vfn_100() && a2)
    {
        space5 = ((P01ObjA*)a2)->GetNext();
        if (!space5)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
        stationForm3 = FUN_008356e0(space5, a1);
        if (!stationForm3)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
    }
    else if (isTalkingActivator)
    {
        stationForm3 = a1;
    }

    if (!stationForm3)
    {
        delete ((FUN_00832160*)state3);
        return 0;
    }

    ((StationData*)state3)->form = stationForm3;
    ((StationData*)state3)->unk04 = 0;
    ((StationData*)state3)->unk08 = 0;

    ((StationData*)state3)->unk0C = BSAudio::GetSingleton()->GetSynchTime() - GetRandomNumberInRange(0, 30000);
    ((StationData*)state3)->unk10 = 1;

    ((FUN_00833100_shell*)((char*)state3 + 4))
        ->FUN_00833100(((MyForm*)((P01ObjA*)((StationData*)state3)->form)->GetNext())->vfn_b4());
    ((FUN_008330b0_shell*)((char*)state3 + 4))->SetFlag(((FUN_00833040_shell*)((char*)state3 + 4))->IsFlag20Set());
    ((FUN_00833060_shell*)((char*)state3 + 4))->FUN_00833060(true);

    ((StationData*)state3)->unk14 = 0x64;
    ((StationData*)state3)->unk15 = 0x64;

    ((G2*)&DAT_011dd554)->AddHead((int*&)state3);

    return state3;
}
}  // namespace fnv_00832cb0

namespace fnv_008366e0 {
extern unsigned int DAT_011dd428;

extern unsigned int DAT_011dd448;

struct LoadBuffer : BGSLoadGameBuffer
{

    void __thiscall FUN_00865e50(void*, unsigned int, unsigned int);

    void __thiscall FUN_00865e70(void*, unsigned int);

    unsigned int __thiscall FUN_00865f20();

    void __thiscall FUN_00865ff0(unsigned int, unsigned int);

    void __thiscall FUN_00865df0(unsigned int, unsigned int);
};

struct RadioStationSaveView : FalloutRadio::RadioStationState
{
    void __thiscall FUN_00836600(BGSLoadGameBuffer*);
};

struct RadioForm
{

    unsigned int __thiscall FUN_007af430();
};

// Reads radio receiver, station, and form data from a load buffer, initializing each item and writing back the counts.
// @fnv 0x008366e0
void __cdecl FUN_008366e0(LoadBuffer* buffer)

{

    unsigned int secondID5;

    unsigned int receiverNode4;

    FalloutRadio::RadioReceiver* formID;

    unsigned int formCount;

    BSSimpleList<FalloutRadio::RadioReceiver*>* stationPosition4;

    unsigned int firstID2;

    unsigned int receiverCount;

    unsigned int stationCount;

    BSSimpleList<FalloutRadio::RadioStationState*>* formNode2;

    FalloutRadio::RadioStationState* receiverPosition;

    unsigned int station_2;

    unsigned int formPosition4;

    BSSimpleList<unsigned int>* stationNode;

    unsigned int receiver5;

    buffer->FUN_00865e50(&DAT_011dd428, 4, 0);

    buffer->FUN_00865e50(&DAT_011dd434, 1, 0);

    buffer->FUN_00865e70(&DAT_011dd448, 0);

    firstID2 = 0;

    formCount = buffer->FUN_00865f20();

    stationPosition4 = &DAT_011dd58c;

    while (stationPosition4)
    {

        formID = stationPosition4->GetItem();

        if (formID)
        {

            formID->InitLoadGame(buffer);

            ++firstID2;
        }

        stationPosition4 = stationPosition4->GetNext();
    }

    buffer->FUN_00865ff0(firstID2, formCount);

    stationCount = 0;

    receiverCount = buffer->FUN_00865f20();

    formNode2 = &DAT_011dd554;

    while (formNode2)
    {

        receiverPosition = formNode2->GetItem();

        if (receiverPosition)
        {

            ((RadioStationSaveView*)receiverPosition)->FUN_00836600(buffer);

            ++stationCount;
        }

        formNode2 = formNode2->GetNext();
    }

    buffer->FUN_00865ff0(stationCount, receiverCount);

    secondID5 = 0;

    if (DAT_011dd42c)

        secondID5 = (*(RadioForm**)DAT_011dd42c)->FUN_007af430();

    buffer->FUN_00865df0(secondID5, 0);

    receiverNode4 = 0;

    if (DAT_011dd430)

        receiverNode4 = (*(RadioForm**)DAT_011dd430)->FUN_007af430();

    buffer->FUN_00865df0(receiverNode4, 0);

    station_2 = 0;

    formPosition4 = buffer->FUN_00865f20();

    stationNode = &DAT_011dd59c;

    while (stationNode)
    {

        receiver5 = stationNode->GetItem();

        if (receiver5)
        {

            buffer->FUN_00865df0(receiver5, 0);

            ++station_2;
        }

        stationNode = stationNode->GetNext();
    }

    buffer->FUN_00865ff0(station_2, formPosition4);
}
}  // namespace fnv_008366e0

static const char radioUpdateProfile[] = "FalloutRadio::UpdateStation";
static const char radioUpdateStaticSound[] = "UIRadioStaticLP";
static const char radioUpdateMonoSuffix[] = "_mono.";

struct RadioUpdateVec3
{
    float x, y, z;
    RadioUpdateVec3 operator-(const RadioUpdateVec3& o) const;
    float FUN_00457990() const;
};

class RadioUpdateSndHandle
{
  public:
    unsigned int id;
    unsigned char b;
    unsigned int st;
    ~RadioUpdateSndHandle();
    RadioUpdateSndHandle& operator=(const RadioUpdateSndHandle&);
    bool FUN_00ad8ce0();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    void FUN_00ad88b0();
    void Play(int);
    int FUN_00ad8b30();
    void FUN_00ad89e0(float);
    void SetPos(float, float, float);
    void FUN_004f15a0(int);
    void FUN_00ad8be0(float, float);
    void FUN_00ad8e60(void (*)(void*), void*);
    void FUN_00ad8fd0(unsigned int);
};

class RadioUpdateSnd
{
  public:
    unsigned char GetField45();
};

class RadioUpdateCell
{
  public:
    bool FUN_00425fd0();
};

class TESBoundObject : public TESForm
{
};

class RadioUpdateBoundName
{
  public:
    const char* FUN_00511840();
};

class TESObjectACTI : public TESBoundObject
{
  public:
};

class RadioUpdateActivator
{
  public:
    RadioUpdateSnd* FUN_00407840();
};

class RadioUpdateObj
{
  public:
    RadioUpdateObj* FUN_0083c820();
    TESBoundObject* FUN_007af430();
    RadioUpdateObj* FUN_0084e3a0();
    bool FUN_00579200();
    void RunResultScript(int, RadioUpdateObj*);
    bool FUN_0083c7b0();
    bool FUN_0083c7e0();
    bool FUN_0083b9f0();
    void FUN_0083c470();
    void FUN_0083b9a0();
    bool FUN_00440da0();
    RadioUpdateSnd* FUN_00407840();
    RadioUpdateObj* FUN_006815c0();
    RadioUpdateObj* FUN_00460140();
    const char* FUN_00511840();
    const char* FUN_00559450();
    void* FUN_00575d70();
    RadioUpdateCell* FUN_008d6f30();
    int FUN_004181e0();
    int FUN_00639b40();
    void* FUN_00441110();
    void* FUN_009611e0();
    void* FUN_0044ddc0();
    ~RadioUpdateObj();
};

class RadioUpdateRefObj
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual bool v100();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual RadioUpdateVec3* v1f4();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual bool v21c();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual float v284(char*, RadioUpdateSndHandle*, void*, RadioUpdateObj*, int, void*, void*, RadioUpdateRefObj*, int,
                       int, int, int, int);
    void* FUN_00575d70();
    RadioUpdateCell* FUN_008d6f30();
    int FUN_004181e0();
};

struct RadioUpdateReceiver
{
    RadioUpdateRefObj* ref;
    RadioUpdateSndHandle snd4;
    RadioUpdateSndHandle snd10;
    unsigned char active;
    unsigned char b1d;
};

class RadioUpdateRList
{
  public:
    RadioUpdateReceiver* m_item;
    RadioUpdateRList* m_next;
    bool FUN_008256d0();
    RadioUpdateReceiver** FUN_006815c0();
    RadioUpdateRList* FUN_00726070();
};

class RadioUpdateSub4
{
  public:
    RadioUpdateObj* ptr;
    void SetFlag100(int);
    bool IsFlag80Set();
    void SetFlag80(int);
    bool IsFlag20Set();
    void FUN_008330b0(int);
    bool GetByteAtOffset17();
    void FUN_00632d20(bool);
    unsigned char FUN_00833c20();
    bool FUN_00835650();
    bool IsFlag8Set();
    void FUN_00833c40(int);
};

struct RadioUpdateState
{
    RadioUpdateObj* form;
    RadioUpdateSub4 sub;
    int f8;
    unsigned int fc;
    int f10;
    int f14;
    int f18;
    RadioUpdateRList list;
};

class RadioUpdateTimer
{
  public:
    unsigned int FUN_0063d040();
};

class RadioUpdateAudio
{
  public:
    void FUN_00ad78e0(RadioUpdateVec3*);
    unsigned int FUN_0063d040();
    RadioUpdateSndHandle FUN_00ad7550(const char*, unsigned int);
    RadioUpdateSndHandle FUN_00ad7480(const char*, unsigned int, RadioUpdateSnd*);
};

class RadioUpdateProf
{
  public:
    void FUN_004538a0(const char*);
    void FUN_004538c0();
};

class RadioUpdateFSetting
{
  public:
    float* FUN_00403e20();
};

int __cdecl FUN_008308c0(int);
void __cdecl FUN_008324e0(int);
void __cdecl FUN_008305e0();
void __cdecl ResetThreadFlags();
unsigned char __cdecl FUN_00833ce0();
void __cdecl FUN_008304a0();
void __cdecl FUN_008325a0(int);
void __cdecl PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
void __cdecl FUN_008304c0();
void __cdecl AdvanceConversation(RadioUpdateState*, int);
void __cdecl UpdateRadio(int);
float __cdecl FUN_004dd150(float, float);
unsigned int __cdecl FUN_0044a670(RadioUpdateObj*);
void __cdecl FUN_00406d30(char*, unsigned int, const char*);
void __cdecl FUN_00406d50(char*, unsigned int, const char*);
int __cdecl FUN_004812f0(const char*, const char*);
char* __cdecl FUN_0043b9d0(const char*, int);
void* __cdecl DynCast(void*, int, void*, void*, int);
void Callback57e0(void*);

extern RadioUpdateProf DAT_011dd5e8;
extern RadioUpdateVec3 DAT_011f426c;
extern RadioUpdateFSetting DAT_011dd62c;
extern RadioUpdateFSetting DAT_011dd5b0;
extern char DAT_01183108;
extern char DAT_01186584;

// @fnv 0x00834260
void __cdecl FUN_00834260(FalloutRadio::RadioStationState* apState)
{
    bool aEnabled = false;
    bool aFlag = false;
    bool aSame = false;
    bool bFound = false;
    unsigned int aCont = 0;
    unsigned char aTmp = 100;
    bool aState = false;
    bool aCur = false;

    if (!((RadioUpdateState*)apState) || !((RadioUpdateState*)apState)->form)
        return;

    bool aDone = ((RadioUpdateState*)apState)->form->FUN_00440da0();
    bool aTag = (DAT_011dd43c & 1) != 0;
    bool bVal = (DAT_011dd43c & 2) != 0;
    bool bCurrentVal = ((RadioUpdateState*)apState) == ((RadioUpdateState*)DAT_011dd42c);
    float aBound = 3000.0f;
    RadioUpdateVec3 aLight;
    ((RadioUpdateAudio*)::FUN_00453a70())->FUN_00ad78e0(&aLight);
    DAT_011dd5e8.FUN_004538a0(radioUpdateProfile);
    RadioUpdateObj* aActor =
        ((RadioUpdateState*)apState)->sub.ptr ? ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820() : 0;
    RadioUpdateRList* aNext = &((RadioUpdateState*)apState)->list;

    if (DAT_011dd436)
        return;

    if (!bCurrentVal && ((RadioUpdateState*)apState)->list.FUN_008256d0())
    {
        DAT_011dd5e8.FUN_004538c0();
        return;
    }

    RadioUpdateSnd* aData = ((RadioUpdateSnd*)DAT_011dd440);
    if (((RadioUpdateState*)apState) && ((RadioUpdateState*)apState)->form)
    {
        TESObjectACTI* act = dynamic_cast<TESObjectACTI*>(((RadioUpdateState*)apState)->form->FUN_007af430());
        if (act && ((RadioUpdateActivator*)act)->FUN_00407840())
            aData = ((RadioUpdateActivator*)act)->FUN_00407840();
    }

    if (aDone || aTag || bVal)
    {
        RadioUpdateRList* it = &((RadioUpdateState*)apState)->list;
        while (it && !it->FUN_008256d0())
        {
            if ((*it->FUN_006815c0())->snd4.FUN_00ad8ce0())
            {
                if (aDone)
                {
                    (*it->FUN_006815c0())->snd4.FUN_00ad88f0();
                    (*it->FUN_006815c0())->snd4.FUN_00ad8d10();
                    (*it->FUN_006815c0())->snd10.FUN_00ad88f0();
                    (*it->FUN_006815c0())->snd10.FUN_00ad8d10();
                }
                else if (aTag)
                {
                    (*it->FUN_006815c0())->snd4.FUN_00ad88b0();
                    (*it->FUN_006815c0())->snd10.FUN_00ad88b0();
                }
                else if (bVal && (*it->FUN_006815c0())->active)
                {
                    (*it->FUN_006815c0())->snd4.Play(0);
                    (*it->FUN_006815c0())->snd10.Play(0);
                }
            }
            it = it->FUN_00726070();
        }
        if (bCurrentVal)
        {
            if (aDone)
                FUN_008324e0(0);
            if (((RadioUpdateState*)DAT_011dd42c) && ((RadioUpdateState*)DAT_011dd42c)->sub.IsFlag8Set())
            {
                if (aTag)
                {
                    (*(RadioUpdateSndHandle*)&DAT_011dd638).FUN_00ad88b0();
                    FUN_008305e0();
                }
                else if (bVal)
                {
                    (*(RadioUpdateSndHandle*)&DAT_011dd638).Play(0);
                    ResetThreadFlags();
                }
            }
            else if (aTag)
            {
                (*(RadioUpdateSndHandle*)&DAT_011dd638).FUN_00ad88b0();
                (*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad88b0();
            }
            else if (bVal)
            {
                (*(RadioUpdateSndHandle*)&DAT_011dd638).Play(0);
                (*(RadioUpdateSndHandle*)&DAT_011dd5bc).Play(0);
            }
        }
        DAT_011dd5e8.FUN_004538c0();
        return;
    }

    if (((RadioUpdateState*)apState)->f10 <= 0 && ((RadioUpdateState*)apState) == ((RadioUpdateState*)DAT_011dd42c))
    {
        if ((*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad8ce0())
            ((RadioUpdateState*)apState)->f10 = (*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad8b30();
        else if (aActor && aActor->FUN_0083c820()->FUN_007af430() && FUN_008308c0(7))
            ((RadioUpdateState*)apState)->f10 = FUN_008308c0(7);
    }

    unsigned int aIndex = ((RadioUpdateAudio*)::FUN_00453a70())->FUN_0063d040();
    if (((RadioUpdateState*)apState)->fc > aIndex + 100)
        ((RadioUpdateState*)apState)->fc = aIndex;

    if (((RadioUpdateState*)apState) && ((RadioUpdateState*)apState)->f10 > 0 &&
        ((RadioUpdateState*)apState)->fc + ((RadioUpdateState*)apState)->f10 < aIndex)
    {
        bool b4d = false;
        if (((RadioUpdateState*)apState)->sub.ptr && ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820())
        {
            if (((RadioUpdateState*)apState)->sub.ptr->FUN_0083b9f0())
            {
                b4d = true;
                if (((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820()->FUN_0084e3a0() &&
                    !((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820()->FUN_0084e3a0()->FUN_00579200())
                    ((RadioUpdateState*)apState)
                        ->sub.ptr->FUN_0083c820()
                        ->FUN_0084e3a0()
                        ->RunResultScript(0, ((RadioUpdateState*)apState)->form);
                ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820()->FUN_0083c7b0();
                ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)::FUN_00453a70())->FUN_0063d040() + 50;
                ((RadioUpdateState*)apState)->f10 = 0;
                if (((RadioUpdateState*)apState)->list.FUN_008256d0() && !((RadioUpdateState*)DAT_011dd42c))
                    ((RadioUpdateState*)apState)->sub.SetFlag100(1);
            }
            else
            {
                delete ((RadioUpdateState*)apState)->sub.ptr;
                ((RadioUpdateState*)apState)->sub.ptr = 0;
                aActor = 0;
                ((RadioUpdateState*)apState)->fc = 0;
                ((RadioUpdateState*)apState)->f10 = 0;
                if (((RadioUpdateState*)apState)->sub.IsFlag80Set())
                    ((RadioUpdateState*)apState)->sub.SetFlag80(0);
            }
            aNext = &((RadioUpdateState*)apState)->list;
            while (aNext && !aNext->FUN_008256d0())
            {
                (*aNext->FUN_006815c0())->snd4.FUN_00ad88f0();
                (*aNext->FUN_006815c0())->snd4.FUN_00ad8d10();
                aNext = aNext->FUN_00726070();
            }
            if (((RadioUpdateState*)apState) == ((RadioUpdateState*)DAT_011dd42c))
            {
                (*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad88f0();
                (*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad8d10();
                if (!FUN_00833ce0())
                {
                    FUN_008304a0();
                    FUN_008325a0(1);
                    PlayAudioMedia(7, 0, 1000, 0, 0, 0.0f, 0);
                    FUN_008304c0();
                }
            }
        }
        if (!((RadioUpdateState*)apState)->sub.ptr || !((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820())
        {
            if (((RadioUpdateState*)apState)->sub.IsFlag20Set())
            {
                ((RadioUpdateState*)apState)->sub.FUN_008330b0(1);
                AdvanceConversation(((RadioUpdateState*)apState), 0);
                ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c470();
                ((RadioUpdateState*)apState)->sub.ptr->FUN_0083b9a0();
                if (((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820())
                {
                    aActor = ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820();
                    if (((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820()->FUN_0084e3a0() &&
                        !((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820()->FUN_0084e3a0()->FUN_00579200())
                        ((RadioUpdateState*)apState)
                            ->sub.ptr->FUN_0083c820()
                            ->FUN_0084e3a0()
                            ->RunResultScript(0, ((RadioUpdateState*)apState)->form);
                    ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820()->FUN_0083c7b0();
                    ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)::FUN_00453a70())->FUN_0063d040() + 50;
                    ((RadioUpdateState*)apState)->f10 = 0;
                    aNext = &((RadioUpdateState*)apState)->list;
                    while (aNext && !aNext->FUN_008256d0())
                    {
                        (*aNext->FUN_006815c0())->snd4.FUN_00ad88f0();
                        (*aNext->FUN_006815c0())->snd4.FUN_00ad8d10();
                        aNext = aNext->FUN_00726070();
                    }
                    if (((RadioUpdateState*)apState) == ((RadioUpdateState*)DAT_011dd42c))
                    {
                        (*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad88f0();
                        (*(RadioUpdateSndHandle*)&DAT_011dd5bc).FUN_00ad8d10();
                    }
                }
            }
            else
            {
                ((RadioUpdateState*)apState)->sub.FUN_008330b0(0);
            }
        }
    }

    if (((RadioUpdateState*)apState)->sub.ptr && ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820())
    {
        aActor = ((RadioUpdateState*)apState)->sub.ptr->FUN_0083c820();
        if (!aActor->FUN_0083c820() && !aActor->FUN_0083c7e0())
        {
            ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)::FUN_00453a70())->FUN_0063d040() + 50;
            ((RadioUpdateState*)apState)->f10 = 1;
        }
    }

    ((RadioUpdateState*)apState)->sub.FUN_00632d20(((RadioUpdateState*)apState)->sub.GetByteAtOffset17());
    aTmp = ((RadioUpdateState*)apState)->sub.FUN_00833c20();
    if (aTmp < 100)
        bFound = true;

    aNext = &((RadioUpdateState*)apState)->list;
    while (aNext && !aNext->FUN_008256d0())
    {
        if (!(*aNext->FUN_006815c0())->active)
        {
            aNext = aNext->FUN_00726070();
            continue;
        }
        if (((RadioUpdateState*)apState)->f10 <= 0 && (*aNext->FUN_006815c0())->snd4.FUN_00ad8ce0() &&
            (*aNext->FUN_006815c0())->snd4.FUN_00ad8b30())
            ((RadioUpdateState*)apState)->f10 = (*aNext->FUN_006815c0())->snd4.FUN_00ad8b30();

        RadioUpdateVec3 pos = DAT_011f426c;
        pos.x = 3.402823466e+38F;
        pos.y = 3.402823466e+38F;
        pos.z = 3.402823466e+38F;
        if (*aNext->FUN_006815c0() && (*aNext->FUN_006815c0())->ref)
        {
            pos = *(*aNext->FUN_006815c0())->ref->v1f4();
        }
        else if (*aNext->FUN_006815c0() && !(*aNext->FUN_006815c0())->ref)
        {
            (*aNext->FUN_006815c0())->active = 0;
            aNext = aNext->FUN_00726070();
            continue;
        }

        if ((((RadioUpdateObj*)::DAT_011dea3c)->FUN_00575d70() &&
             ((RadioUpdateObj*)::DAT_011dea3c)->FUN_00575d70() != (*aNext->FUN_006815c0())->ref->FUN_00575d70()) ||
            (((RadioUpdateObj*)::DAT_011dea3c)->FUN_008d6f30()->FUN_00425fd0() &&
             (*aNext->FUN_006815c0())->ref->FUN_008d6f30() != ((RadioUpdateObj*)::DAT_011dea3c)->FUN_008d6f30()))
        {
            (*aNext->FUN_006815c0())->snd4.FUN_00ad89e0(0.0f);
            (*aNext->FUN_006815c0())->active = 0;
        }

        if (*aNext->FUN_006815c0() && (*aNext->FUN_006815c0())->snd4.FUN_00ad8ce0())
            (*aNext->FUN_006815c0())->snd4.SetPos(pos.x, pos.y, pos.z);

        if (bFound && !(*aNext->FUN_006815c0())->snd10.FUN_00ad8ce0())
        {
            (*aNext->FUN_006815c0())->snd10.FUN_00ad88f0();
            (*aNext->FUN_006815c0())->snd10.FUN_00ad8d10();
            (*aNext->FUN_006815c0())->snd10 =
                ((RadioUpdateAudio*)::FUN_00453a70())->FUN_00ad7550(radioUpdateStaticSound, 0x100012);
            (*aNext->FUN_006815c0())->snd10.FUN_004f15a0(1);
            (*aNext->FUN_006815c0())->snd10.SetPos(pos.x, pos.y, pos.z);
            (*aNext->FUN_006815c0())->snd10.FUN_00ad89e0(FUN_004dd150((float)(100 - aTmp) / 100.0, 0.75f));
            (*aNext->FUN_006815c0())->snd10.Play(0);
        }
        else if (bFound)
        {
            (*aNext->FUN_006815c0())->snd10.FUN_00ad89e0(FUN_004dd150((float)(100 - aTmp) / 100.0, 0.75f));
            (*aNext->FUN_006815c0())->snd10.SetPos(pos.x, pos.y, pos.z);
        }
        else if (!bFound && (*aNext->FUN_006815c0())->snd10.FUN_00ad8ce0())
        {
            (*aNext->FUN_006815c0())->snd10.FUN_00ad88f0();
            (*aNext->FUN_006815c0())->snd10.FUN_00ad8d10();
        }

        if (aActor && !(*aNext->FUN_006815c0())->snd4.FUN_00ad8ce0() &&
            ((RadioUpdateState*)apState)->sub.FUN_00835650() && (*aNext->FUN_006815c0())->active &&
            (*aNext->FUN_006815c0())->ref)
        {
            if (aActor && aActor->FUN_0083c820())
            {
                char buf[0x104];
                if (aActor->FUN_0083c820()->FUN_007af430())
                    aEnabled = true;
                if (aActor->FUN_0083c820() && aActor->FUN_0083c820()->FUN_006815c0()->FUN_00559450())
                {
                    aCont = FUN_0044a670((RadioUpdateObj*)aActor->FUN_0083c820()->FUN_006815c0()->FUN_00559450());
                    aSame = aCont > 1 && aActor->FUN_0083c820()->FUN_00460140()->FUN_00559450();
                }
                if (aEnabled)
                {
                    FUN_00406d30(buf, 0x104,
                                 ((RadioUpdateBoundName*)aActor->FUN_0083c820()->FUN_007af430())->FUN_00511840());
                    if (!FUN_004812f0(buf, radioUpdateMonoSuffix))
                    {
                        char* dot = FUN_0043b9d0(buf, '.');
                        if (dot)
                        {
                            char ext[4];
                            FUN_00406d30(ext, 4, dot + 1);
                            *dot = 0;
                            FUN_00406d50(buf, 0x104, radioUpdateMonoSuffix);
                            FUN_00406d50(buf, 0x104, ext);
                        }
                    }
                    ((RadioUpdateState*)apState)->sub.FUN_00833c40(1);
                }
                else if (aSame)
                {
                    FUN_00406d30(buf, 0x104, aActor->FUN_0083c820()->FUN_00460140()->FUN_00559450());
                    ((RadioUpdateState*)apState)->sub.FUN_00833c40(0);
                }
                else
                {
                    ((RadioUpdateState*)apState)->f10 = 1;
                    aNext = aNext->FUN_00726070();
                    ((RadioUpdateState*)apState)->sub.FUN_00833c40(0);
                    continue;
                }

                bool bSame = false;
                bool bNpcVal = false;
                RadioUpdateRefObj* aRec = 0;
                if ((*aNext->FUN_006815c0())->ref && (*aNext->FUN_006815c0())->ref->v100())
                {
                    aRec = (*aNext->FUN_006815c0())->ref;
                    if (aActor->FUN_0084e3a0() && aRec->FUN_004181e0() == aActor->FUN_0084e3a0()->FUN_00639b40())
                        bSame = true;
                    if (aRec->v21c())
                        bNpcVal = true;
                }
                if (aData && !bNpcVal)
                    aBound = aData->GetField45() * 110.0;
                else if (bNpcVal)
                    aBound = *DAT_011dd62c.FUN_00403e20() * 1.100000023841858;

                if (aBound < (aLight - pos).FUN_00457990())
                {
                    aNext = aNext->FUN_00726070();
                    continue;
                }
                int elapsed = ((RadioUpdateAudio*)::FUN_00453a70())->FUN_0063d040() - ((RadioUpdateState*)apState)->fc;
                if (aRec && bSame)
                {
                    aRec->v284(buf, &(*aNext->FUN_006815c0())->snd4, aActor->FUN_0083c820()->FUN_0044ddc0(),
                               aActor->FUN_0083c820()->FUN_0084e3a0(), 0x96, aActor->FUN_0083c820()->FUN_009611e0(),
                               aActor->FUN_0083c820()->FUN_00441110(), (*aNext->FUN_006815c0())->ref, 0, 0, 0, 1, 1);
                }
                else
                {
                    unsigned int flags = 0;
                    if (bNpcVal)
                    {
                        (*aNext->FUN_006815c0())->snd4 =
                            ((RadioUpdateAudio*)::FUN_00453a70())->FUN_00ad7480(buf, flags | 0x500102, 0);
                        (*aNext->FUN_006815c0())
                            ->snd4.FUN_00ad8be0(*DAT_011dd5b0.FUN_00403e20(), *DAT_011dd62c.FUN_00403e20());
                    }
                    else
                    {
                        (*aNext->FUN_006815c0())->snd4 =
                            ((RadioUpdateAudio*)::FUN_00453a70())->FUN_00ad7480(buf, flags | 0x500102, aData);
                    }
                    (*aNext->FUN_006815c0())->snd4.FUN_00ad8e60(Callback57e0, ((RadioUpdateState*)apState));
                    (*aNext->FUN_006815c0())->snd4.FUN_00ad8fd0(((RadioUpdateState*)apState)->fc);
                    (*aNext->FUN_006815c0())->snd4.SetPos(pos.x, pos.y, pos.z);
                    (*aNext->FUN_006815c0())->snd4.FUN_00ad89e0((float)aTmp / 100.0);
                    (*aNext->FUN_006815c0())->snd4.Play(0);
                }
                if (bCurrentVal && !(*aNext->FUN_006815c0())->b1d && !aState)
                {
                    aState = true;
                    UpdateRadio(1);
                }
                if ((*aNext->FUN_006815c0())->b1d)
                    (*aNext->FUN_006815c0())->b1d = 0;
            }
            else if (aActor && !aActor->FUN_0083c7e0() && !aActor->FUN_0083c7b0())
            {
                ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)::FUN_00453a70())->FUN_0063d040() + 50;
                ((RadioUpdateState*)apState)->f10 = 1;
            }
        }
        else if (!(*aNext->FUN_006815c0())->ref)
        {
            (*aNext->FUN_006815c0())->active = 0;
        }
        aNext = aNext->FUN_00726070();
    }

    if (((RadioUpdateState*)apState) == ((RadioUpdateState*)DAT_011dd42c) && !aState)
        UpdateRadio(0);
    DAT_011dd5e8.FUN_004538c0();
}

class RadioLoadBufferView : public BGSLoadGameBuffer
{
  public:
    void FUN_00864980(void* apDest, unsigned int auiSize);
    char* FUN_008649a0(char* apDest);
    unsigned int FUN_00864a60();
    unsigned int FUN_008648a0();
    void FUN_008648e0(unsigned int* apID);
};

struct RadioLoadReceiverEntry : public ::radio_detail::FUN_008327d0
{
    __forceinline RadioLoadReceiverEntry() : ::radio_detail::FUN_008327d0()
    {}
};

template <class T> struct RadioLoadListView : public BSSimpleList<T>
{
    void FUN_005ae3d0(T* item);
};

TESForm* __cdecl FUN_004839c0(unsigned int);

struct RadioLoadStationEntry : public ::fnv_00832cb0::FUN_00833150
{
    __forceinline RadioLoadStationEntry() : ::fnv_00832cb0::FUN_00833150()
    {}
};

struct RadioLoadReceiverView : public FalloutRadio::RadioReceiver
{
    void FUN_00835f80(BGSLoadGameBuffer* buffer);
};

struct RadioLoadStationView : public FalloutRadio::RadioStationState
{
    void FUN_00836630(BGSLoadGameBuffer* buffer);
};

// @fnv 0x008368b0
void FUN_008368b0(BGSLoadGameBuffer* apBuffer)
{
    ::TESBoundObject* f;
    ::TESBoundObject* eb;
    unsigned int cf;
    unsigned int q;
    FalloutRadio::RadioReceiver* b;
    unsigned int ba;
    unsigned int k;
    FalloutRadio::RadioStationState* l;
    unsigned int c;
    unsigned int e;
    unsigned int j;

    ((RadioLoadBufferView*)apBuffer)->FUN_00864980(&::fnv_008366e0::DAT_011dd428, 4);
    ((RadioLoadBufferView*)apBuffer)->FUN_00864980(&DAT_011dd434, 1);
    ((RadioLoadBufferView*)apBuffer)->FUN_008649a0(::fnv_00832240::DAT_011dd448);

    cf = ((RadioLoadBufferView*)apBuffer)->FUN_00864a60();
    for (q = 0; q < cf; ++q)
    {
        b = (FalloutRadio::RadioReceiver*)new RadioLoadReceiverEntry();
        ((RadioLoadReceiverView*)b)->FUN_00835f80(apBuffer);
        ((RadioLoadListView<FalloutRadio::RadioReceiver*>*)&DAT_011dd58c)->FUN_005ae3d0(&b);
    }

    ba = ((RadioLoadBufferView*)apBuffer)->FUN_00864a60();
    for (k = 0; k < ba; ++k)
    {
        l = (FalloutRadio::RadioStationState*)new RadioLoadStationEntry();
        ((RadioLoadStationView*)l)->FUN_00836630(apBuffer);
        ((RadioLoadListView<FalloutRadio::RadioStationState*>*)&DAT_011dd554)->FUN_005ae3d0(&l);
    }

    f = 0;
    f = dynamic_cast< ::TESBoundObject*>(FUN_004839c0(((RadioLoadBufferView*)apBuffer)->FUN_008648a0()));
    DAT_011dd42c = (unsigned int)f;

    eb = 0;
    eb = dynamic_cast< ::TESBoundObject*>(FUN_004839c0(((RadioLoadBufferView*)apBuffer)->FUN_008648a0()));
    DAT_011dd430 = (unsigned int)eb;

    if (apBuffer->vfn_0() >= 10)
    {
        c = ((RadioLoadBufferView*)apBuffer)->FUN_00864a60();
        for (e = 0; e < c; ++e)
        {
            j = 0;
            ((RadioLoadBufferView*)apBuffer)->FUN_008648e0(&j);
            ((RadioLoadListView<unsigned int>*)&DAT_011dd59c)->FUN_005ae3d0(&j);
        }
    }
}
