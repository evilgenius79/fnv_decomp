
// src/havok/physics/utilities/visualdebugger/hkpphysicscontext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/hkpphysicscontext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00d6ad40();
void __cdecl FUN_00d6a850();
void __cdecl RegisterCenterOfMass();
void __cdecl RegisterConstraintsProcessFactory();
void __cdecl RegisterConvexRadius();
void __cdecl RegisterContactPointsActive();
void __cdecl RegisterContactPointsInactive();
void __cdecl DispatchStateHandler();
void __cdecl RegisterToiCounter();
void __cdecl RegisterInertiaTensors();
void __cdecl RegisterMousePicking();
void __cdecl RegisterPhantomsProcess();
void __cdecl RegisterShapesProcess();
void __cdecl FUN_00d651c0();
void __cdecl RegisterSweptTransformsTask();
void __cdecl FUN_00d63da0();
void __cdecl InitWorldMemory();
void __cdecl RegisterSnapshotCommands();
void __cdecl RegisterWeldingViewer();

// @fnv 0x00cd1ed0
void __cdecl FUN_00cd1ed0()
{
    FUN_00d6ad40();
    FUN_00d6a850();
    RegisterCenterOfMass();
    RegisterConstraintsProcessFactory();
    RegisterConvexRadius();
    RegisterContactPointsActive();
    RegisterContactPointsInactive();
    DispatchStateHandler();
    RegisterToiCounter();
    RegisterInertiaTensors();
    RegisterMousePicking();
    RegisterPhantomsProcess();
    RegisterShapesProcess();
    FUN_00d651c0();
    RegisterSweptTransformsTask();
    FUN_00d63da0();
    InitWorldMemory();
    RegisterSnapshotCommands();
    RegisterWeldingViewer();
}

struct Owner
{
    void UntrackObject(int);
};
struct FUN_00cd1f60_cls
{
    void FUN_00cd1f60(int);
};
// @fnv 0x00cd1f60
void FUN_00cd1f60_cls::FUN_00cd1f60(int value)
{
    Owner* owner = *(Owner**)((char*)this - 0x50);
    if (owner)
        owner->UntrackObject(value);
}

struct CD1FA0Target
{
    void UntrackObject(int value);
};

struct CD1FA0Primary
{
    virtual void vfunc00();

    CD1FA0Target* m_target;
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
};

struct CD1FA0Listener
{
    virtual void FUN_00cd1fa0(int value);
};

struct CD1FA0Object : CD1FA0Primary, CD1FA0Listener
{
    virtual void FUN_00cd1fa0(int value);
};

// @fnv 0x00cd1fa0
void CD1FA0Object::FUN_00cd1fa0(int value)
{
    if (m_target)
        m_target->UntrackObject(value);
}

namespace fnv_00cd1ff0 {
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType();
};
struct Event
{
    int a, b, c;
    Obj* obj;
};
struct Owner
{
    void UntrackObject(Event* e);
};
struct Sub
{
    void DispatchEventToOwner(Event* e);
};

// If the event's object exists and its GetType() is not 11, forwards the event to the owner stored before this sub-object.
// @fnv 0x00cd1ff0
void Sub::DispatchEventToOwner(Event* pEvent)
{
    Owner* owner = *(Owner**)((char*)this - 0x58);
    if (owner)
    {
        Obj* o = pEvent->obj;
        if (o && o->GetType() != 11)
            (*(Owner**)((char*)this - 0x58))->UntrackObject(pEvent);
    }
}
}  // namespace fnv_00cd1ff0

namespace fnv_00cd2020 {
struct GlobalObjectO2_00d472a0
{
    int x;
};
extern GlobalObjectO2_00d472a0 g_012690d4;
struct FUN_00cd12b0_cls
{
    void AddElementAndNotify(int value, const void* category, const char* name, int flags);
};
struct Prefix
{
    FUN_00cd12b0_cls* owner;
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
};
struct Context
{
    int contextState;
    void FUN_00cd2020(int value);
};
struct Owner : Prefix, Context
{
};
// Forwards value to the owner object's AddElementAndNotify with the Actions category and zero flags, if an owner exists.
// @fnv 0x00cd2020
void Context::FUN_00cd2020(int value)
{
    Owner* object = reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - sizeof(Prefix));
    FUN_00cd12b0_cls* target = object->owner;
    if (target)
        target->AddElementAndNotify(value, &g_012690d4, "Actions", 0);
}
}  // namespace fnv_00cd2020

struct FUN_00cd10a0_Class
{
    void UntrackObject(int value);
};
struct FUN_00cd2040_Class
{
    void ForwardToTarget(int value);
};
// Reads a pointer stored at this-0x5c and, if non-null, forwards value to its UntrackObject method.
// @fnv 0x00cd2040
void FUN_00cd2040_Class::ForwardToTarget(int value)
{
    FUN_00cd10a0_Class* target = *(FUN_00cd10a0_Class**)((char*)this - 0x5c);
    if (target)
        target->UntrackObject(value);
}

struct Prefix
{
    virtual void slot();
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    int __thiscall FUN_00cd2260(int value);
};
struct FUN_00cd2460_class;
struct Secondary
{
    virtual int FUN_00cd2460(int value);
};
struct FUN_00cd2460_class : Prefix, Secondary
{
};
// @fnv 0x00cd2460
int __thiscall Secondary::FUN_00cd2460(int value)
{
    return reinterpret_cast<Prefix*>(reinterpret_cast<char*>(this) - sizeof(Prefix))->FUN_00cd2260(value);
}

struct AllocatorState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* allocator;
};
extern AllocatorState* __cdecl FUN_00c85750();
extern void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);
struct PointerArray
{
    void** data;
    int count;
    int capacity;
};
struct Candidate
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
    PointerArray items;
    void* FindOrAddPointer(void* value);
};
// Searches items for value and returns its index; if absent, appends value to items and returns the new slot pointer.
// @fnv 0x00cd2470
void* Candidate::FindOrAddPointer(void* value)
{
    PointerArray* array = &items;
    register int index = 0;
    int count = array->count;
    if (count > 0)
    {
        void** ppEntry = array->data;
        do
        {
            if (*ppEntry == value)
                goto found;
            ++index;
            ++ppEntry;
        } while (index < count);
    }
    goto append;
found:
    if (index >= 0)
        return (void*)index;
append:
    AllocatorState* state = FUN_00c85750();
    if (array->count == (array->capacity & 0x3fffffff))
        ResizeAudioStream(state->allocator, array, 4);
    void** slot = array->data + array->count;
    *slot = value;
    ++array->count;
    return slot;
}

namespace fnv_00cd27f0 {
struct Device
{
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0c() = 0;
    virtual void Release(void* handle, unsigned int bytes) = 0;
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Device* device;
};
extern void* __cdecl FUN_00c85750();
struct FUN_00cd27f0
{
    virtual void v0() = 0;
    int unk04;
    int buffer2;
    int unk0c;
    int count2;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int buffer1;
    volatile int unk30;
    int count1;
    virtual ~FUN_00cd27f0();
};
// @fnv 0x00cd27f0
FUN_00cd27f0::~FUN_00cd27f0()
{
    Holder* holder = (Holder*)FUN_00c85750();
    Device* device = holder->device;
    int count = count1;
    unk30 = 0;
    if ((unsigned int)count & 0x80000000)
        goto skipFirstRelease;
    {
        unsigned int bytes = (count & 0x3fffffff) * 4;
        device->Release((void*)buffer1, bytes);
    }
skipFirstRelease:
    buffer1 = 0;
    count1 = 0x80000000;
    holder = (Holder*)FUN_00c85750();
    device = holder->device;
    int secondCount = count2;
    unk0c = 0;
    if ((unsigned int)secondCount & 0x80000000)
        goto skipSecondRelease;
    {
        unsigned int bytes = (secondCount & 0x3fffffff) * 4;
        device->Release((void*)buffer2, bytes);
    }
skipSecondRelease:
    buffer2 = 0;
    count2 = 0x80000000;
}
}  // namespace fnv_00cd27f0

namespace fnv_00cd2900 {
struct DeleteInterface
{
    virtual void first();
    virtual void second();
    virtual void deleteObject(void*, unsigned short);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DeleteInterface* iface;
};
Manager* __cdecl FUN_00c85750();
struct FUN_00cd2900_owner
{
    int unk00;
    unsigned short unk04;
    void FUN_00cd2690();
    void* DestroyIfFlagged(unsigned flags);
};
// Calls FUN_00cd2690, and if bit 0 of flags is set, deletes this via the manager's deleteObject interface, then returns this.
// @fnv 0x00cd2900
void* FUN_00cd2900_owner::DestroyIfFlagged(unsigned flags)
{
    FUN_00cd2690();
    if (flags & 1)
    {
        Manager* manager = FUN_00c85750();
        manager->iface->deleteObject(this, unk04);
    }
    return this;
}
}  // namespace fnv_00cd2900

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_012688c8;
class Handler
{
  public:
    void AddElementAndNotify(void* input, const GlobalObjectO2_00d472a0* global, const char* name, void* payload);
};
struct Receiver
{
    void DispatchEntityPayload(void* input);
};
struct UnknownBlock
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct Container
{
    struct Prefix
    {
        Handler* handler;
        unsigned int unk04, unk08, unk0c;
        UnknownBlock unk10, unk20, unk30, unk40;
    } prefix;
    Receiver receiver;
};
// Recovers the enclosing Container from this, and if its handler is set, forwards input, a global, "Entities" and input+0x10 to the handler.
// @fnv 0x00cd1f30
void Receiver::DispatchEntityPayload(void* input)
{
    Container* owner = reinterpret_cast<Container*>(reinterpret_cast<char*>(this) - sizeof(Container::Prefix));
    Handler* handler = owner->prefix.handler;
    if (handler)
        handler->AddElementAndNotify(input, &g_012688c8, "Entities", reinterpret_cast<char*>(input) + 0x10);
}

struct CD1F70Stats
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_childStats;
};

extern const char g_CD1F70Parent[];

struct CD1F70Collection
{
    void AddStat(CD1F70Stats* stats, const char* parent, const char* name, int* childStats);
};

class CD1F70Primary
{
  public:
    virtual void unk00();

    CD1F70Collection* m_kPhantoms;
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
};

class CD1F70Secondary
{
  public:
    virtual void CollectPhantoms(CD1F70Stats* stats);
};

class CD1F70World : public CD1F70Primary, public CD1F70Secondary
{
  public:
    virtual void CollectPhantoms(CD1F70Stats* stats);
};

// If the collection pointer is set, forwards stats to its child-stats collector under the "Phantoms" name.
// @fnv 0x00cd1f70
void CD1F70World::CollectPhantoms(CD1F70Stats* stats)
{
    if (m_kPhantoms)
        m_kPhantoms->AddStat(stats, g_CD1F70Parent, "Phantoms", &stats->m_childStats);
}

struct CD1FB0Collector
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual int getType();
};

struct CD1FB0Stats
{
    int unk00;
    int unk04;
    int unk08;
    CD1FB0Collector* m_kCollector;
};

extern const char g_CD1FB0Parent[];

struct CD1FB0Collection
{
    void AddStat(CD1FB0Stats* stats, const char* parent, const char* name, int* childStats);
};

class CD1FB0Primary
{
  public:
    virtual void unk00();

    CD1FB0Collection* m_ppConstraints;
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
};

class CD1FB0Secondary
{
  public:
    virtual void CollectConstraints(CD1FB0Stats* stats);
};

class CD1FB0World : public CD1FB0Primary, public CD1FB0Secondary
{
  public:
    virtual void CollectConstraints(CD1FB0Stats* stats);
};

// @fnv 0x00cd1fb0
void CD1FB0World::CollectConstraints(CD1FB0Stats* stats)
{
    if (m_ppConstraints)
    {
        CD1FB0Collector* collector = stats->m_kCollector;
        if (collector && collector->getType() != 11)
            m_ppConstraints->AddStat(stats, g_CD1FB0Parent, "Constraints", 0);
    }
}

struct CD2050World
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
    void** m_kTrackedObjects;
    int m_numObjects;

    int FindObjectIndex(void* object) const;
};

// Searches the object array for the given pointer and returns its index, or -1 if not found.
// @fnv 0x00cd2050
int CD2050World::FindObjectIndex(void* object) const
{
    for (int i = 0; i < m_numObjects; i++)
    {
        if (m_kTrackedObjects[i] == object)
            return i;
    }
    return -1;
}

struct S_00cd2080_Listener
{
    virtual void unk00() throw();
    virtual void unk04() throw();
    virtual void onEvent(void* item) throw();
};

struct S_00cd2080_Quad
{
    int a, b;
};
struct S_00cd2080_Element
{
    virtual ~S_00cd2080_Element() throw();
    int unk04[59];
};

struct S_00cd2080_Lists
{
    int unk00;
    int unk04;
    int* m_08;
    int m_0c;
    int m_10;
    int* m_14;
    int m_18;
    int m_1c;
    int* m_20;
    int m_24;
    int m_28;
    int* m_2c;
    int m_30;
    int m_34;

    void FUN_00c905b0() throw();
};

struct S_00cd2080_Param
{
    void FUN_00c917a0(void* listener) throw();
    void FUN_00c917f0(void* listener) throw();
    void FUN_00c91700(void* listener) throw();
    void FUN_00c91750(void* listener) throw();
    S_00cd2080_Lists* FUN_00c929e0() throw();
};

struct S_00cd2080_Class
{
    int unk00;
    int unk04;
    int unk08;
    CD1FA0Target* m_target;
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
    S_00cd2080_Listener m_listener0;
    S_00cd2080_Listener m_listener1;
    S_00cd2080_Listener m_listener2;
    S_00cd2080_Listener m_listener3;
    S_00cd2080_Param** m_params;
    int m_paramCount;
    int m_paramCapacity;
    S_00cd2080_Element* m_elements;
    int m_elementCount;
    int m_elementCapacity;

    void FUN_00cd2080(S_00cd2080_Param* param) throw();
};

// @fnv 0x00cd2080
void S_00cd2080_Class::FUN_00cd2080(S_00cd2080_Param* param) throw()
{
    if (!this->m_target)
        return;
    if (!param)
        return;

    S_00cd2080_Listener* pListener0;
    S_00cd2080_Listener* pListener1;
    S_00cd2080_Listener* pListener3;
    S_00cd2080_Listener* pListener2;
    param->FUN_00c917a0(pListener0 = &this->m_listener0);
    param->FUN_00c917f0(pListener1 = &this->m_listener1);
    param->FUN_00c91700(pListener3 = &this->m_listener3);
    param->FUN_00c91750(pListener2 = &this->m_listener2);

    int idx;
    int count = this->m_paramCount;
    int i = 0;
    while (i < count)
    {
        if (this->m_params[i] == param)
        {
            idx = i;
            goto done_search;
        }
        i += 1;
    }
    idx = -1;
done_search:

    if (this->m_target && idx != -1)
    {
        this->m_target->UntrackObject((int)&this->m_elements[idx]);
        this->m_elements[idx].~S_00cd2080_Element();
        this->m_elementCount--;
        if (this->m_elementCount != idx)
        {
            S_00cd2080_Quad* src = (S_00cd2080_Quad*)&this->m_elements[this->m_elementCount];
            S_00cd2080_Quad* dst = (S_00cd2080_Quad*)&this->m_elements[idx];
            for (int k = 0; k < 30; k++)
                dst[k] = src[k];
        }
    }

    S_00cd2080_Lists* lists = param->FUN_00c929e0();
    for (int iItem = 0; iItem < lists->m_0c; iItem++)
    {
        pListener0->onEvent((void*)lists->m_08[iItem]);
    }
    for (int iItem = 0; iItem < lists->m_30; iItem++)
    {
        pListener1->onEvent((void*)lists->m_2c[iItem]);
    }
    for (int iItem = 0; iItem < lists->m_24; iItem++)
    {
        pListener3->onEvent((void*)lists->m_20[iItem]);
    }
    for (int iItem = 0; iItem < lists->m_18; iItem++)
    {
        pListener2->onEvent((void*)lists->m_14[iItem]);
    }
    lists->FUN_00c905b0();
}

template <typename T> struct CD2210Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct CD2210Listener;

struct CD2210World
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
    CD2210Array<CD2210Listener*> m_kListeners;

    void RemoveListener(CD2210Listener* listener);
};

// Finds the listener in the array and removes it if present.
// @fnv 0x00cd2210
void CD2210World::RemoveListener(CD2210Listener* listener)
{
    int i = m_kListeners.indexOf(listener);
    if (i >= 0)
        m_kListeners.removeAt(i);
}

struct CD2260Object;

struct CD2260Interface
{
    virtual void vfunc00();
};

struct CD2260Object
{
    void removeOwner(CD2260Interface* owner);
};

struct CD2260Listener
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void objectRemovedCallback(CD2260Object* object);
};

template <typename T> struct CD2260Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

class CD2260Primary
{
  public:
    virtual void vfunc00();

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
};

class CD2260World : public CD2260Primary, public CD2260Interface
{
  public:
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    CD2260Array<CD2260Object*> m_kTrackedObjects;
    int unk78;
    int unk7C;
    int unk80;
    CD2260Array<CD2260Listener*> m_kListeners;

    void removeInternal(CD2260Object* object);
    void FUN_00cd2260(CD2260Object* object);
};

// If object is in the array, removes this as its owner, notifies listeners via objectRemovedCallback, calls removeInternal and removes it from the array.
// @fnv 0x00cd2260
void CD2260World::FUN_00cd2260(CD2260Object* object)
{
    int index = m_kTrackedObjects.indexOf(object);
    if (index >= 0)
    {
        object->removeOwner(this);
        for (int i = 0; i < m_kListeners.m_iElementCount; i++)
            m_kListeners.m_data[i]->objectRemovedCallback(object);
        removeInternal(object);
        m_kTrackedObjects.removeAt(index);
    }
}

struct CD22Listener
{
    virtual void vfunc00();
    virtual void Notify(void* item);
};

struct CD22Elem
{
    void FUN_00c90b80();
};

struct CD22Array
{
    CD22Elem* data;
    int count;
    unsigned int cap;
};

struct CD22Table
{
    int unk00;
    int unk04;
    void** items08;
    int count0C;
    int unk10;
    void** items14;
    int count18;
    int unk1C;
    void** items20;
    int count24;
    int unk28;
    void** items2C;
    int count30;
    void FUN_00c905b0();
};

struct CD22Registry
{
    void IncrementCounter();
    void FUN_00c93820(void* p);
    void FUN_00c93860(void* p);
    void FUN_00c937a0(void* p);
    void FUN_00c937e0(void* p);
    CD22Table* FUN_00c929e0();
    void FUN_00c91c50(CD22Elem* e);
    void FUN_00c91190();
};

struct CD22Owner
{
    void AddElementAndNotify(CD22Elem* e, const char* d, const char* s, int z);
};

extern char DAT_01269104[];
extern char str_010cb20c[];

struct CD22Object
{
    int unk00;
    int unk04;
    int unk08;
    CD22Owner* m_0c;
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
    CD22Listener m_5c;
    CD22Listener m_60;
    CD22Listener m_64;
    CD22Listener m_68;
    int unk6C;
    int unk70;
    int unk74;
    CD22Array m_78;
    void RegisterWithRegistry(CD22Registry* reg);
};

extern AllocatorState* __cdecl FUN_00c85750();
extern void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);

// @fnv 0x00cd22f0
void CD22Object::RegisterWithRegistry(CD22Registry* reg)
{
    if (m_0c == 0)
        return;
    if (reg == 0)
        return;

    reg->IncrementCounter();
    reg->FUN_00c93820(&m_5c);
    reg->FUN_00c93860(&m_60);
    reg->FUN_00c937a0(&m_68);
    reg->FUN_00c937e0(&m_64);

    CD22Array* pArray = &m_78;
    AllocatorState* holder = FUN_00c85750();
    if (pArray->count == (int)(pArray->cap & 0x3fffffff))
    {
        ResizeAudioStream(holder->allocator, pArray, 0xf0);
    }

    CD22Elem* pNewElem = (CD22Elem*)((char*)pArray->data + pArray->count * 0xf0);
    if (pNewElem != 0)
    {
        pNewElem->FUN_00c90b80();
    }

    CD22Elem* e = (CD22Elem*)((char*)pArray->data + pArray->count * 0xf0);
    pArray->count++;
    reg->FUN_00c91c50(e);

    if (m_0c != 0)
    {
        m_0c->AddElementAndNotify(e, DAT_01269104, str_010cb20c, 0);
    }

    CD22Table* tbl = reg->FUN_00c929e0();
    for (int i = 0; i < tbl->count0C; ++i)
    {
        ((CD22Listener*)&m_5c)->Notify(tbl->items08[i]);
    }
    for (int i = 0; i < tbl->count30; ++i)
    {
        ((CD22Listener*)&m_60)->Notify(tbl->items2C[i]);
    }
    for (int i = 0; i < tbl->count24; ++i)
    {
        ((CD22Listener*)&m_68)->Notify(tbl->items20[i]);
    }
    for (int i = 0; i < tbl->count18; ++i)
    {
        ((CD22Listener*)&m_64)->Notify(tbl->items14[i]);
    }
    tbl->FUN_00c905b0();
    reg->FUN_00c91190();
}

struct SpawnedCallee
{
    void FUN_00cd2080(void* item);
    void RegisterWithRegistry(void* item);
};

struct FUN_00cd24d0_cls
{
    int unk00;
    int m_04;
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
    void** m_64;
    int m_68;

    void FUN_00cd24d0(int value);
};

// If m_04 was set, calls FUN_00cd2080 on each of m_68 entries in m_64, stores value in m_04, then calls RegisterWithRegistry on each entry when value is nonzero.
// @fnv 0x00cd24d0
void FUN_00cd24d0_cls::FUN_00cd24d0(int value)
{
    if (m_04 != 0)
    {
        for (int i = 0; i < m_68; ++i)
        {
            ((SpawnedCallee*)((char*)this - 8))->FUN_00cd2080(m_64[i]);
        }
    }

    m_04 = value;

    if (value != 0)
    {
        for (int i = 0; i < m_68; ++i)
        {
            ((SpawnedCallee*)((char*)this - 8))->RegisterWithRegistry(m_64[i]);
        }
    }
}

struct FUN_00c93a60_cls
{
    void FUN_00c93a60(void* param);
};

struct Sink
{
    virtual void vfunc00();
    virtual void vfunc04(int value);
};

struct FUN_00cd2530_cls
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
    PointerArray m_items;
    int unk78;
    int unk7C;
    int unk80;
    Sink** m_sinks;
    int m_sinkCount;

    void RegisterWithRegistry(int value);
    void AddItem(int value);
};

// If value is not already in m_items, appends it, notifies each sink via vfunc04 and calls RegisterWithRegistry.
// @fnv 0x00cd2530
void FUN_00cd2530_cls::AddItem(int pItem)
{
    PointerArray* items = &m_items;
    int count = items->count;
    int idx = 0;
    if (count > 0)
    {
        void** p = items->data;
        do
        {
            if (*p == (void*)pItem)
            {
                goto found;
            }
            ++p;
            ++idx;
        } while (idx < count);
    }
    goto notFound;

found:
    if (idx >= 0)
    {
        return;
    }

notFound:
    FUN_00c93a60_cls* obj = (FUN_00c93a60_cls*)pItem;
    FUN_00cd2530_cls* self = this;
    void* param = self != 0 ? (char*)self + 0x58 : 0;
    obj->FUN_00c93a60(param);

    AllocatorState* holder = FUN_00c85750();
    if (items->count == (items->capacity & 0x3fffffff))
    {
        ResizeAudioStream(holder->allocator, items, 4);
    }
    int n = *(int volatile*)&items->count;
    void** volatile* ppData = &items->data;
    void** slot = (*ppData) + n;
    *slot = (void*)pItem;
    items->count++;

    for (int i = 0; i < m_sinkCount; ++i)
    {
        m_sinks[i]->vfunc04(pItem);
    }

    RegisterWithRegistry(pItem);
}

struct FUN_00cd2870_cls
{
    int unk00;
    int unk04;

    void BaseRelease();

    FUN_00cd2870_cls* FUN_00cd2870(unsigned int aFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00cd2870
FUN_00cd2870_cls* FUN_00cd2870_cls::FUN_00cd2870(unsigned int aFlags)
{
    BaseRelease();
    if (aFlags & 1)
    {
        operator delete(this);
    }
    return this;
}

struct CD2890Class
{
    const char* m_name;
};

extern const CD2890Class g_CD2890WorldClass;

struct CD2890World
{
    virtual const CD2890Class* FUN_00cd2890() const;
};

// @fnv 0x00cd2890
const CD2890Class* CD2890World::FUN_00cd2890() const
{
    return &g_CD2890WorldClass;
}

struct hkBaseObject
{
    virtual void destroy();
    virtual void b04();
    virtual void b08();
};

struct hkReferencedObject : hkBaseObject
{
    unsigned short memSizeAndFlags;
    short refCount;

    hkReferencedObject()
    {
        refCount = 1;
    }
    virtual void r04();
    virtual void r08();
};

struct InplaceArray6
{
    void* data;
    int size;
    unsigned int capacityAndFlags;
    void* buffer0;
    void* buffer1;
    void* buffer2;
    void* buffer3;
    void* buffer4;
    void* buffer5;

    InplaceArray6()
    {
        size = 0;
        data = &buffer0;
        capacityAndFlags = 0x80000006u;
    }
};

struct EmptyArray
{
    void* data;
    int size;
    unsigned int capacityAndFlags;

    EmptyArray()
    {
        data = 0;
        size = 0;
        capacityAndFlags = 0x80000000u;
    }
};

struct hkProcessContext : hkBaseObject
{
    int m_04;
    InplaceArray6 m_08;
    InplaceArray6 m_2c;

    hkProcessContext() : m_04(0)
    {}
    virtual void p04();
    virtual void p08();
};

struct hkpWorldDeletionListener : hkBaseObject
{
    virtual void destroy();
    virtual void w04();
    virtual void w08();
};

struct hkpEntityListener : hkBaseObject
{
    virtual void destroy();
    virtual void e04();
    virtual void e08();
    virtual void e0c();
    virtual void e10();
    virtual void e14();
};

struct hkpPhantomListener : hkBaseObject
{
    virtual void destroy();
    virtual void p04();
    virtual void p08();
    virtual void p0c();
    virtual void p10();
};

struct hkpConstraintListener : hkBaseObject
{
    virtual void destroy();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10();
    virtual void c14();
    virtual void c18();
};

struct hkpActionListener : hkBaseObject
{
    virtual void destroy();
    virtual void a04();
    virtual void a08();
};

struct FUN_00cd25d0 : hkReferencedObject,
                      hkProcessContext,
                      hkpWorldDeletionListener,
                      hkpEntityListener,
                      hkpPhantomListener,
                      hkpConstraintListener,
                      hkpActionListener
{
    EmptyArray m_6c;
    EmptyArray m_78;
    EmptyArray m_84;

    FUN_00cd25d0();
    virtual void d04();
    virtual void d08();
};

// Constructs the object; the base classes and member arrays are initialized by their own constructors.
// @fnv 0x00cd25d0
FUN_00cd25d0::FUN_00cd25d0()
{}

class hkMemoryAllocatorD269
{
  public:
    virtual ~hkMemoryAllocatorD269() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void unk0C() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

inline hkMemoryAllocatorD269& heapD269(AllocatorState* pkState)
{
    return *(hkMemoryAllocatorD269*)pkState->allocator;
}

template <class T> class hkArrayD269
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; i++)
            t[i].~T();
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorD269& alloc)
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline ~hkArrayD269() throw()
    {
        _clearAndDeallocate(heapD269(FUN_00c85750()));
    }
};

class hkReferencedObjectD269
{
  public:
    virtual ~hkReferencedObjectD269() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class BaseD269_08
{
  public:
    virtual ~BaseD269_08() throw();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    int unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
};

class ListenerD269_58
{
  public:
    virtual ~ListenerD269_58() throw()
    {}
};
class ListenerD269_5C
{
  public:
    virtual ~ListenerD269_5C() throw()
    {}
};
class ListenerD269_60
{
  public:
    virtual ~ListenerD269_60() throw()
    {}
};
class ListenerD269_64
{
  public:
    virtual ~ListenerD269_64() throw()
    {}
};
class ListenerD269_68
{
  public:
    virtual ~ListenerD269_68() throw()
    {}
};

class ElementD269
{
  public:
    virtual ~ElementD269() throw();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
};

class FUN_00cd2690 : public hkReferencedObjectD269,
                     public BaseD269_08,
                     public ListenerD269_58,
                     public ListenerD269_5C,
                     public ListenerD269_60,
                     public ListenerD269_64,
                     public ListenerD269_68
{
  public:
    virtual ~FUN_00cd2690() throw();

    void FUN_00cd2260(void* pkObject);

    hkArrayD269<void*> m_kTrackedObjects;
    hkArrayD269<ElementD269> m_elements;
    hkArrayD269<void*> m_kListeners;
};

// Destructor that iterates m_kTrackedObjects in reverse and calls FUN_00cd2260 on each element.
// @fnv 0x00cd2690
FUN_00cd2690::~FUN_00cd2690() throw()
{
    for (int i = m_kTrackedObjects.GetLogicalSize() - 1; i >= 0; i--)
        FUN_00cd2260(m_kTrackedObjects[i]);
}

struct Block8CD2A
{
    int a, b;
};
inline void memMoveCD2A(void* pvDst, const void* pvSrc, int iNumBytes)
{
    const Block8CD2A* s = (const Block8CD2A*)pvSrc;
    Block8CD2A* d = (Block8CD2A*)pvDst;
    int k = 0;
    for (int i = 0; i < iNumBytes; i += 8)
    {
        d[k] = s[k];
        k++;
    }
}

template <typename T> struct hkArrayCD2A
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAtAndCopy(int iIndex)
    {
        m_iElementCount--;
        memMoveCD2A(m_data + iIndex, m_data + iIndex + 1, (m_iElementCount - iIndex) * sizeof(T));
    }
};

struct ValueCD2A
{
    int m_kPointA;
    int m_kPointB;
    ValueCD2A() : m_kPointA(0), m_kPointB(0)
    {}
};

struct EntryCD2A
{
    int m_key;
    int m_unk04;
    ValueCD2A m_uiFilterValue;
};

class OwnerCD2A
{
  public:
    int unk00[0x78 / 4];
    hkArrayCD2A<EntryCD2A> m_entries;

    ValueCD2A FUN_00cd2a50(int iKey);
};

// @fnv 0x00cd2a50
ValueCD2A OwnerCD2A::FUN_00cd2a50(int iKey)
{
    for (int i = 0; i < m_entries.GetLogicalSize(); i++)
    {
        if (m_entries[i].m_key == iKey)
        {
            EntryCD2A kEntry = m_entries[i];
            m_entries.removeAtAndCopy(i);
            return kEntry.m_uiFilterValue;
        }
    }
    return ValueCD2A();
}

struct FUN_00cd1e70
{
    virtual ~FUN_00cd1e70();
};

// @fnv 0x00cd1e70
FUN_00cd1e70::~FUN_00cd1e70()
{}

struct FUN_00cd1e90_cls
{
    int unk04;
    virtual ~FUN_00cd1e90_cls();
};

// @fnv 0x00cd1e90
FUN_00cd1e90_cls::~FUN_00cd1e90_cls()
{}

// sub ecx,0x58; jmp target == MSVC adjustor thunk (second base's vtable slot, this moved back by sizeof(PrimaryBase)=0x58).
struct PrimaryBase
{
    virtual void FUN_00cd28a0();
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
};

struct SecondaryBase
{
    virtual void FUN_00cd28a0();
};

struct ThunkOwner : PrimaryBase, SecondaryBase
{
    ThunkOwner();
// @fnv 0x00cd28a0
    virtual void FUN_00cd28a0();
};

ThunkOwner::ThunkOwner()
{}

// FUN_00cd28b0: MSVC this-adjusting thunk.
//
// The original is 8 bytes:  sub ecx, 0x5c ; jmp 0x00cd2900
// That is the adjustor thunk MSVC emits for a virtual function that a
// derived class overrides for a SECONDARY base: calling through the
// secondary base's vftable passes the base subobject's `this`, so the
// thunk walks it back to the derived object and tail-jumps to the shared
// override.
//
// To make the compiler produce exactly that symbol we need
//   * two bases that both declare the same virtual (so the derived class
//     overrides one function for both of them -> one adjustor per base),
//   * the second base placed at offset 0x5c (the first base is padded to
//     0x5c bytes),
//   * the override DECLARED ONLY, so that the thunk is the single defined
//     function symbol carrying the name FUN_00cd28b0,
//   * a defined key function in the derived class, so that its vftable
//     (which references the thunk) is emitted in this translation unit.
struct AdjBase1
{
    AdjBase1();
    virtual void FUN_00cd28b0();
    char pad[0x58];  // vptr + 0x58 -> size 0x5c, so AdjBase2 lands at +0x5c
};

struct AdjBase2
{
    AdjBase2();
// @fnv 0x00cd28b0
    virtual void FUN_00cd28b0();
};

struct AdjOwner : AdjBase1, AdjBase2
{
    AdjOwner();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00cd28b0();    // the shared override - declared only
};

AdjOwner::AdjOwner()
{}
void AdjOwner::key_fn()
{}

AdjOwner* make_adj_owner()
{
    static AdjOwner o;
    return &o;
}

namespace fnv_00cd28c0 {
// sub ecx,0x60; jmp DestroyIfFlagged == MSVC adjustor thunk (second base's vtable slot, this moved back by sizeof(PrimaryBase)=0x60).
struct PrimaryBase
{
    virtual void FUN_00cd28c0();
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
};

struct SecondaryBase
{
    virtual void FUN_00cd28c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cd28c0
    virtual void FUN_00cd28c0();
};

Derived::Derived()
{}
}  // namespace fnv_00cd28c0

namespace fnv_00cd28d0 {
// sub ecx,0x64; jmp target: MSVC adjustor thunk. PrimaryBase is 0x64 bytes (vptr + 24 ints),
// so the second base sits at +0x64 and the thunk subtracts 0x64 from this.
struct PrimaryBase
{
    virtual void FUN_00cd28d0();
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
};

struct SecondaryBase
{
    virtual void FUN_00cd28d0();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00cd28d0
    virtual void FUN_00cd28d0();
};

SpawnedObject::SpawnedObject()
{}
}  // namespace fnv_00cd28d0

struct CD28E0Primary
{
    virtual void vfunc00();
    virtual void FUN_00cd28e0();

    int unk04;
};

struct CD28E0Secondary
{
    virtual void FUN_00cd28e0();
};

struct CD28E0Object : CD28E0Primary, CD28E0Secondary
{
    CD28E0Object();

// @fnv 0x00cd28e0
    virtual void FUN_00cd28e0();
};

CD28E0Object::CD28E0Object()
{}

// sub ecx,0x68; jmp target == MSVC adjustor thunk for a secondary base slot.
struct CD28F0Primary
{
    virtual void FUN_00cd28f0();
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
    unsigned int unk30;
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
};

struct CD28F0Secondary
{
    virtual void FUN_00cd28f0();
};

struct CD28F0Derived : CD28F0Primary, CD28F0Secondary
{
    CD28F0Derived();
// @fnv 0x00cd28f0
    virtual void FUN_00cd28f0();
};

CD28F0Derived::CD28F0Derived()
{}

struct FUN_00cd1eb0_StandIn
{
    int unk00;
    int __thiscall FUN_00cd1eb0(int param);
};

extern void __cdecl FormHeap_Free(void* ptr);

// @fnv 0x00cd1eb0
int __thiscall FUN_00cd1eb0_StandIn::FUN_00cd1eb0(int aiFlags)
{
    unk00 = 0x010cb1e4;
    if (aiFlags & 1)
    {
        FormHeap_Free(this);
    }
    return (int)this;
}
