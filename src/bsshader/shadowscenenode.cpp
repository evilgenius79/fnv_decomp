// bsshader/shadowscenenode.cpp: ShadowSceneNode, Base, Self, BlendOwner and more (63 functions)

#include "shadowscenenode_local.h"

// @fnv 0x00b5eeb0
void ShadowSceneNode::AddObject(NiAVObject* apObject)
{
    if (!apObject)
        return;
    if (apObject->m_uiObjectFlags & 1)
        return;
    RemoveSceneObject(apObject, false);
}

// Releases each shadow light's texture, clears the shadow light list, and resets the shadow counts to zero.
// @fnv 0x00b5c3c0
void ShadowSceneNode::UpdateShadowLights()
{
    ShadowListItem* item = shadowLights.head;
    while (item)
    {
        ShadowSceneLight*& lightRef = item->light;
        item = item->next;
        ShadowSceneLight* light = lightRef;
        if (light)
        {
            DAT_011f91a8->RemoveRenderedTexture(light->texture);
            BSRenderedTexture* old = light->texture;
            if (old)
            {
                if (!InterlockedDecrement(&old->refs))
                    old->DeleteThis();
                light->texture = 0;
            }
        }
    }
    shadowLights.RemoveAll();
    shadowCount = 0;
    shadowCount2 = 0;
}

// @fnv 0x00b5b4d0
float ShadowSceneNode::CalculateLightingAtPoint(NiPoint3 point, int& count, float& ambient, float& diffuse,
                                                NiLight* ignore)
{
    float total = 0.0f;
    ShadowListItem* item = lights.head;
    while (item)
    {
        ShadowSceneLight*& ref = item->light;
        item = item->next;
        ShadowSceneLight* light = ref;
        if (light)
        {
            total += light->ComputeLightAttenuation(point, ignore);
            if (total > 0.0f)
                ++count;
        }
    }
    ShadowLightFlags* data = ambientLight->lightData;
    NiPoint3 color = data->ambient;
    ambient = ShadowMax(color.x, ShadowMax(color.y, color.z));
    color = data->diffuse;
    diffuse = ShadowMax(color.x, ShadowMax(color.y, color.z));
    return total;
}

struct Node_00b5ac20
{
    Node_00b5ac20* pNext;
    Node_00b5ac20* pPrev;
    void* pItem;
};

struct List_00b5ac20
{
    Node_00b5ac20* pHead;
    Node_00b5ac20* pTail;
    unsigned int ItemUpdateArray;

    void* GetNext(Node_00b5ac20*& pos) const
    {
        if (!pos)
            return 0;
        void* item = pos->pItem;
        pos = pos->pNext;
        return item;
    }

    void* GetNextNoCheck(Node_00b5ac20*& pos) const
    {
        void** pItem = &pos->pItem;
        pos = pos->pNext;
        return *pItem;
    }
};

// Returns the item at the given index from the list at pThis+0xb4, or null if the index is out of range.
// @fnv 0x00b5ac20
void* __fastcall GetListItemAt(char* pThis, int, unsigned int index)
{
    List_00b5ac20* list = (List_00b5ac20*)(pThis + 0xb4);
    if (index >= list->ItemUpdateArray)
        return 0;

    Node_00b5ac20* pos = list->pHead;
    void* item = list->GetNextNoCheck(pos);

    for (unsigned int i = 0; i < index; ++i)
    {
        item = list->GetNextNoCheck(pos);
    }

    return item;
}

// Assigns pObj to the reference-counted pointer at pThis+0x10c, releasing the old object and retaining the new one.
// @fnv 0x00b5aee0
void __fastcall AssignRefObject(char* pThis, int, NiRefObject* pObj)
{
    NiRefObject*& spField = *(NiRefObject**)(pThis + 0x10c);
    if (spField != pObj)
    {
        if (spField)
            spField->DecRefCount();

        spField = pObj;

        if (spField)
            spField->IncRefCount();
    }
}

// Assigns pObj to the reference-counted pointer at pThis+0x128, releasing the old object and retaining the new one.
// @fnv 0x00b5af30
void __fastcall FUN_00b5af30(char* pThis, int, NiRefObject* pObj)
{
    NiRefObject*& pRef = *(NiRefObject**)(pThis + 0x128);
    if (pRef != pObj)
    {
        if (pRef)
            pRef->DecRefCount();

        pRef = pObj;

        if (pRef)
            pRef->IncRefCount();
    }
}

void __fastcall ClearShaderPropRefs(void* pThis);

struct ShadowLightNode
{
    ShadowLightNode* m_pkNext;
    ShadowLightNode* m_pkPrev;
    char* m_val;
};

static inline char*& GetNextLight(ShadowLightNode*& pkIter)
{
    char*& rVal = pkIter->m_val;
    pkIter = pkIter->m_pkNext;
    return rVal;
}

// @fnv 0x00b5b060
void __fastcall FUN_00b5b060(char* pThis, int)
{
    ShadowLightNode* pkIter = *(ShadowLightNode**)(pThis + 0xC0);
    while (pkIter)
    {
        char* pkLight = GetNextLight(pkIter);
        if (pkLight && *(void**)(pkLight + 0xF8))
        {
            DAT_011f91a8->RemoveRenderedTexture(*(BSRenderedTexture**)(pkLight + 0x10C));
            BSRenderedTexture* pkTex = *(BSRenderedTexture**)(pkLight + 0x10C);
            if (pkTex)
            {
                if (InterlockedDecrement(&pkTex->refs) == 0)
                    pkTex->DeleteThis();
                *(BSRenderedTexture**)(pkLight + 0x10C) = 0;
            }
            *(unsigned int*)(*(char**)(pkLight + 0xF8) + 0x30) |= 1;
            ClearShaderPropRefs(pkLight);
        }
    }
}

struct VTableStub_00b5b150
{
    void* f0;
    void* f1;
    void* f2;
    void*(__thiscall* GetAsNode)(void*);
    void* f4;
    void* f5;
    void* f6;
    int(__thiscall* GetAsGeometry)(void*);
};

void __cdecl FUN_00b5b0e0(void* pObj);

// Iterates the children of pNode, calling FUN_00b5b0e0 on geometry children and recursing into node children.
// @fnv 0x00b5b150
void __fastcall ProcessNodeChildren(void* pThis, int, void* pNode)
{
    for (unsigned int i = 0; i < *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pNode) + 0xa6); ++i)
    {
        void* pChild = (*reinterpret_cast<void***>(reinterpret_cast<char*>(pNode) + 0xa0))[i];
        if (pChild)
        {
            if ((*reinterpret_cast<VTableStub_00b5b150**>(pChild))->GetAsGeometry(pChild))
            {
                FUN_00b5b0e0(pChild);
            }
            else
            {
                void* pChildNode = (*reinterpret_cast<VTableStub_00b5b150**>(pChild))->GetAsNode(pChild);
                if (pChildNode)
                {
                    reinterpret_cast<void(__thiscall*)(void*, void*)>(&ProcessNodeChildren)(pThis, pChildNode);
                }
            }
        }
    }
}

void __fastcall FUN_00cb9ce0(void* pThis);

struct ArrayLike
{
    virtual ~ArrayLike();
    virtual void* Allocate(unsigned int);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    void Realloc(unsigned int a, unsigned int b)
    {
        ((void(__thiscall*)(ArrayLike*, unsigned int, unsigned int))FUN_00cb9ce0)(this, a, b);
    }
};

// Grows the array's capacity if it is full, then increments m_uiSize and returns the index of the newly appended slot.
// @fnv 0x00b5c360
unsigned int __fastcall FUN_00b5c360(ArrayLike* pThis)
{
    if (pThis->m_uiSize == pThis->m_uiCapacity)
    {
        if (pThis->m_uiCapacity == 0)
        {
            pThis->m_pData = pThis->Allocate(4);
            pThis->m_uiCapacity = 4;
        }
        else
        {
            unsigned int uiNewCapacity =
                (pThis->m_uiCapacity > 0x400) ? (pThis->m_uiCapacity + 0x400) : (pThis->m_uiCapacity * 2);
            pThis->Realloc(uiNewCapacity, pThis->m_uiSize);
            pThis->m_uiCapacity = uiNewCapacity;
        }
    }
    pThis->m_uiSize++;
    return pThis->m_uiSize - 1;
}

struct FUN_00b5aa40_self
{
    unsigned char pad0[0xa0];
    void** items;
    unsigned char pad1[2];
    unsigned short count;
    unsigned char pad2[8];
    int index;
};

// Returns the item at self->index if it is within [0, self->count), otherwise returns null.
// @fnv 0x00b5aa40
void* __fastcall FUN_00b5aa40(FUN_00b5aa40_self* self, int unused)
{
    if (self->index >= 0 && self->index < self->count)
        return self->items[self->index];
    return 0;
}

struct FUN_00b5ac60_item
{
    unsigned char pad[0x110];
    unsigned short id;
};
struct FUN_00b5ac60_node
{
    FUN_00b5ac60_node* next;
    int unk;
    FUN_00b5ac60_item* item;
};
struct FUN_00b5ac60_self
{
    unsigned char pad[0xb4];
    FUN_00b5ac60_node* head;
};

// Walks the linked list from self->head and counts nodes whose item is non-null and whose id is not 0xff.
// @fnv 0x00b5ac60
int __fastcall FUN_00b5ac60(FUN_00b5ac60_self* self, int unused)
{
    int count = 0;
    FUN_00b5ac60_node* n = self->head;
    while (n)
    {
        FUN_00b5ac60_item* const* pp = &n->item;
        n = n->next;
        FUN_00b5ac60_item* it = *pp;
        if (it && it->id != 0xff)
            ++count;
    }
    return count;
}

struct ArrOps
{
    void FUN_00cb9930(unsigned* dst, unsigned* src, unsigned n);
};
struct FUN_00b5ade0_arr
{
    virtual void* vfn_00();
    virtual void* Alloc(unsigned n);
    virtual void Free(void* p);
    unsigned* data;
    unsigned count;
    unsigned capacity;
};
// Removes the element at index, shifting the tail down, or reallocates a smaller buffer when shrinking and the count is low enough.
// @fnv 0x00b5ade0
void __fastcall FUN_00b5ade0(FUN_00b5ade0_arr* self, int, unsigned index, bool shrink)
{
    if (shrink)
    {
        unsigned cap = self->capacity;
        if (cap > 0x400)
        {
            if (self->count <= cap - 0x800)
                goto resize;
        }
        else
        {
            if (!(self->count > (cap >> 2)))
                goto resize;
        }
    }
    {
        unsigned* p = self->data + index;
        ((ArrOps*)self)->FUN_00cb9930(p, p + 1, self->count - index - 1);
        self->count--;
        return;
    }
resize:
    unsigned newCap = self->capacity > 0x800 ? self->capacity - 0x400 : self->capacity >> 1;
    unsigned* puiNewData = (unsigned*)self->Alloc(newCap);
    ((ArrOps*)self)->FUN_00cb9930(puiNewData, self->data, index);
    ((ArrOps*)self)->FUN_00cb9930(puiNewData + index, self->data + index + 1, self->count - 1);
    self->Free(self->data);
    self->count--;
    self->data = puiNewData;
    self->capacity = newCap;
}

struct FUN_00b5aea0_self
{
    int pad0;
    int* data;
    unsigned int count;
    void FUN_00cb9930(int* dst, int* src, unsigned int n);
    void RemoveRange(unsigned int start, unsigned int n);
};

// Copies up to n elements from the end of the buffer into the gap at start, then reduces count by n.
// @fnv 0x00b5aea0
void FUN_00b5aea0_self::RemoveRange(unsigned int start, unsigned int n)
{
    unsigned int m = count - start - n;
    if (m >= n)
        m = n;
    FUN_00cb9930(data + start, data + (count - m), m);
    count -= n;
}

struct FUN_00b5af80_self
{
    virtual void v0();
    virtual void v1();
    virtual void Release(void* obj);
    void* obj;
    int a;
    int b;
    void FUN_00b5af80(bool destroy);
};

// If obj is set, releases it when destroy is true (clearing obj and b), then resets a to 0.
// @fnv 0x00b5af80
void FUN_00b5af80_self::FUN_00b5af80(bool destroy)
{
    if (obj)
    {
        if (destroy)
        {
            Release(obj);
            obj = 0;
            b = 0;
        }
        a = 0;
    }
}

struct NiAVObjectVirt
{
    virtual ~NiAVObjectVirt();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual NiNode* vfunc3();
};

struct FUN_00b5b150_Struct
{
    void __thiscall ProcessNodeChildren(NiNode*);
};

// If apObject is non-null, gets its node via vfunc3 and, when that node exists, passes it to ProcessNodeChildren on thisptr.
// @fnv 0x00b5b1c0
void __fastcall FUN_00b5b1c0(ShadowSceneNode* thisptr, int, NiAVObject* apObject)
{
    if (apObject)
    {
        NiNode* pnode = ((NiAVObjectVirt*)apObject)->vfunc3();
        if (pnode)
            ((FUN_00b5b150_Struct*)thisptr)->ProcessNodeChildren(pnode);
    }
}

struct FUN_00b5b4a0_item
{
    unsigned char pad[0xf8];
    int key;
};
struct FUN_00b5b4a0_node
{
    FUN_00b5b4a0_node* next;
    int unk;
    FUN_00b5b4a0_item* item;
};
struct FUN_00b5b4a0_self
{
    unsigned char pad[0xb4];
    FUN_00b5b4a0_node* head;
};

// Walks the linked list from self->head and returns the first item whose key equals key, or null if none matches.
// @fnv 0x00b5b4a0
FUN_00b5b4a0_item* __fastcall FUN_00b5b4a0(FUN_00b5b4a0_self* self, int unused, int key)
{
    FUN_00b5b4a0_node* n = self->head;
    while (n)
    {
        FUN_00b5b4a0_item* const* pp = &n->item;
        n = n->next;
        FUN_00b5b4a0_item* it = *pp;
        if (it && it->key == key)
            return it;
    }
    return 0;
}

struct FUN_00b9dcb0_stub;
struct FUN_00b5c450_item
{
    unsigned char pad[0xf8];
    int key;
    void SetShadowEnabled(int v);
};
struct FUN_00b5c450_node
{
    FUN_00b5c450_node* next;
    int unk;
    FUN_00b5c450_item* item;
};
struct FUN_00b5c450_self
{
    unsigned char pad[0xb4];
    FUN_00b5c450_node* head;
};

// Walks the linked list from self->head and, for the first item whose key matches, calls SetShadowEnabled with flag.
// @fnv 0x00b5c450
void __fastcall CallItemMethodByKey(FUN_00b5c450_self* self, int unused, int key, int flag)
{
    FUN_00b5c450_node* n = self->head;
    while (n)
    {
        FUN_00b5c450_item* const* pp = &n->item;
        n = n->next;
        FUN_00b5c450_item* it = *pp;
        if (it && it->key == key)
        {
            it->SetShadowEnabled(flag);
            return;
        }
    }
}

struct V3D
{
    float x, y, z;
};
struct LightDataD
{
    char pad[0x30];
    unsigned flags;
    char pad2[0x58];
    V3D pos;
};
struct LightD
{
    char pad[0xec];
    char f_ec;
    char pad2[7];
    char f_f4;
    char pad3[3];
    LightDataD* data;
    char f_fc;
    char pad4[3];
    V3D v100;
    int pad5;
    short s110;
    void FUN_00b9ef30();
    void SetTripleInts(V3D);
};
struct OwnerD
{
    void FUN_00b5d300(LightD*);
};
struct PosD
{
    bool _Call_439090(const V3D*);
};
// @fnv 0x00b5d930
void __fastcall FUN_00b5d930(OwnerD* self, int, LightD* l)
{
    if (l->f_f4 && l->f_fc && !l->f_ec)
    {
        LightDataD* d = l->data;
        if (d->flags & 1)
        {
            l->FUN_00b9ef30();
            return;
        }
        V3D p = l->v100;
        if (((PosD*)&p)->_Call_439090(&d->pos) && l->s110 != 0xff)
        {
            l->SetTripleInts(d->pos);
            self->FUN_00b5d300(l);
        }
    }
}

struct FUN_00b5ddb0_item;
struct FUN_00b5ddb0_node
{
    FUN_00b5ddb0_node* next;
    int unk;
    FUN_00b5ddb0_item* item;
};
struct FUN_00b5ddb0_self
{
    unsigned char pad[0xb4];
    FUN_00b5ddb0_node* head;
    void FUN_00b5d270(FUN_00b5ddb0_item* it);
    void FUN_00b5d180();
    void FUN_00b5ddb0(bool a, bool b);
};

// @fnv 0x00b5ddb0
void FUN_00b5ddb0_self::FUN_00b5ddb0(bool a, bool b)
{
    if (a)
    {
        FUN_00b5ddb0_node* n = head;
        while (n)
        {
            FUN_00b5ddb0_item* const* pp = &n->item;
            n = n->next;
            FUN_00b5ddb0_item* it = *pp;
            if (it)
                FUN_00b5d270(it);
        }
        if (!b)
            FUN_00b5d180();
    }
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
GlobalObjectO2_00a7b610 g_011f9e80;

// @fnv 0x00b5e590
GlobalObjectO2_00a7b610* FUN_00b5e590()
{
    return &g_011f9e80;
}

void* __cdecl FUN_00ec7230(void*, const void*, unsigned int);
// @fnv 0x00cb9930
void __fastcall FUN_00cb9930(void* self, int, unsigned* dst, unsigned* src, unsigned count)
{
    if (count > 0)
    {
        if (dst < src)
        {
            for (unsigned i = 0; i < count; i++)
                FUN_00ec7230(&dst[i], &src[i], 4);
        }
        else if (dst > src)
        {
            for (int i = count - 1; i >= 0; i--)
                FUN_00ec7230(&dst[i], &src[i], 4);
        }
    }
}

struct CloningProcess;
struct NiDirectionalLight;
struct NiDynamicEffect;
struct NiLight;
struct NiNode;
struct NiStream;
struct NiUpdateData;
struct FUN_00b5aac0_shell : public ShadowSceneNode
{
    void FUN_00b5aac0(NiDirectionalLight*);
};

struct NiColor
{
    float r;
    float g;
    float b;
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct NiDirectionalLight : public BSFadeNode
{
    NiDirectionalLight();
    char pad0[0xa8];
    unsigned int m_uiRevID;
    char padac[0x1c];
    NiColor m_kAmb;
    NiColor m_kDiff;
    char pade0[0x1c];
    void SetAmbientColor(const NiColor& kColor)
    {
        m_kAmb = kColor;
        m_uiRevID++;
    }
    void SetDiffuseColor(const NiColor& kColor)
    {
        m_kDiff = kColor;
        m_uiRevID++;
    }
};

struct GlobalObjectO2_00b9fda0 : public BSFadeNode
{
    GlobalObjectO2_00b9fda0();
    virtual ~GlobalObjectO2_00b9fda0();
    void FUN_00b9dda0(NiDirectionalLight*);
    char pad[0x24c];
};
extern NiColor DAT_011f4998;

// @fnv 0x00b5aac0
void FUN_00b5aac0_shell::FUN_00b5aac0(NiDirectionalLight* apLight)
{
    if (*(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0))
    {
        delete *(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0);
        *(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0) = 0;
    }
    if (apLight)
    {
        *(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0) = new GlobalObjectO2_00b9fda0;
        (*(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0))->FUN_00b9dda0(apLight);
    }
    else
    {
        NiDirectionalLight* pdefaultsun = new NiDirectionalLight;
        pdefaultsun->SetAmbientColor(DAT_011f4998);
        pdefaultsun->SetDiffuseColor(DAT_011f4998);
        *(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0) = new GlobalObjectO2_00b9fda0;
        (*(GlobalObjectO2_00b9fda0**)((char*)this + 0xe0))->FUN_00b9dda0(pdefaultsun);
    }
}

struct NiPlane
{
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
    NiPlane();
};
struct SSFrustumPlanes
{
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
    SSFrustumPlanes()
    {
        m_uiActivePlaneMask = 0x3f;
    }
};
struct SSCullData
{
    unsigned int aData[25];
    SSFrustumPlanes g_kFrustumPlanes;
};
struct SSCamera
{
    char pad0[0x8c];
    NiPoint3 m_kWorldTranslate;
    char pad1[0xdc - 0x98];
    char m_kViewFrustum[0x1c];
};
struct FUN_00a693e0
{
    unsigned int pad0[3];
    SSCamera* m_pkAccumulationCamera;
    unsigned int pad1[7];
    ~FUN_00a693e0();
};
struct FUN_00a69400 : FUN_00a693e0
{
    FUN_00a69400(void* pkVisibleSet);
    void FUN_00a694a0(void* pkFrustum);
};
struct SSNode
{
    char pad[0x40];
    int iState;
    bool FUN_00c33cf0(void* pkData, int iFlags, NiPoint3 kIntersectionOffset);
    bool FUN_00c358a0(NiPoint3 kPoint);
};
struct SSListNode
{
    SSListNode* m_pkNext;
    SSListNode* m_pkPrev;
    SSNode* m_element;
};
struct SSListOwner
{
    char pad[8];
    SSListNode* m_pkHead;
    SSListNode* GetHeadPos() const
    {
        return m_pkHead;
    }
    SSNode* const& GetNext(SSListNode*& kPos) const
    {
        SSNode* const& kElement = kPos->m_element;
        kPos = kPos->m_pkNext;
        return kElement;
    }
};
struct FUN_00b5ac90_t
{
    char pad[0x1e0];
    SSListOwner* pOwner;
    void FUN_00b5ac90(SSCamera* pkCamera);
};
// @fnv 0x00b5ac90
void FUN_00b5ac90_t::FUN_00b5ac90(SSCamera* pkCamera)
{
    if (pOwner)
    {
        FUN_00a69400 kCuller(0);
        kCuller.m_pkAccumulationCamera = pkCamera;
        kCuller.FUN_00a694a0(&pkCamera->m_kViewFrustum);
        SSListNode* pkPos = pOwner->GetHeadPos();
        SSCullData kData;
        while (pkPos)
        {
            SSNode* pkNode = pOwner->GetNext(pkPos);
            if (pkNode)
            {
                bool bA = pkNode->FUN_00c33cf0(&kData, 0, NiPoint3::ZERO);
                bA &= pkNode->FUN_00c358a0(pkCamera->m_kWorldTranslate);
                pkNode->iState = bA ? 1 : 2;
            }
        }
    }
}

namespace fnv_00b5c490 {
struct NiRTTI_b5c490
{
    const char* m_pcName;
};
extern NiRTTI_b5c490 g_011f5f1c_arg1;
struct Bound_b5c490
{
    float m_kCenter[3];
    float fRadius;
};
struct AVObj_b5c490
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual AVObj_b5c490* IsSceneNode();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual AVObj_b5c490* IsGeometry();
    char pad04[0x1c];
    Bound_b5c490* m_pBound;
    char pad24[0xc];
    unsigned int m_uiObjectFlags;
    char pad34[0x6c];
    AVObj_b5c490** m_ppObjects;
    unsigned short m_usMax;
    unsigned short m_usElementCount;
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*);
};
struct FUN_00b5aa40_self
{
    AVObj_b5c490* FUN_00b5aa40();
};
bool FUN_00b5b260(AVObj_b5c490*, void*, void*, void*, void*);

// Recursively tests pObj and its children for a non-zero bound and no flag bit 1, calling FUN_00b5b260 on geometry children; returns false on early failure.
// @fnv 0x00b5c490
bool FUN_00b5c490(AVObj_b5c490* pObj, void* apArg2, void* apArg3, void* apArg4, void* apArg5)
{
    if (!pObj)
        return true;
    if (!pObj->m_pBound || pObj->m_pBound->fRadius == 0.0f || (pObj->m_uiObjectFlags & 1) || !pObj->IsSceneNode())
        return false;
    AVObj_b5c490* pNode = pObj->IsSceneNode();
    bool bResult = true;
    unsigned int i = 0;
    FUN_00b5aa40_self* pSwitch = pNode ? (FUN_00b5aa40_self*)((DynCastHelper*)pNode)->DynamicCast(&g_011f5f1c_arg1) : 0;
    if (pSwitch)
    {
        AVObj_b5c490* pChild = pSwitch->FUN_00b5aa40();
        if (pChild)
            bResult &= FUN_00b5c490(pChild, apArg2, apArg3, apArg4, apArg5);
    }
    else
    {
        for (; i < pNode->m_usElementCount; i++)
        {
            AVObj_b5c490* pChild = pNode->m_ppObjects[i];
            if (pChild)
            {
                if (pChild->IsGeometry())
                    bResult &= FUN_00b5b260(pChild, apArg2, apArg3, apArg4, apArg5);
                else
                    bResult &= FUN_00b5c490(pChild, apArg2, apArg3, apArg4, apArg5);
            }
        }
    }
    return bResult;
}
}  // namespace fnv_00b5c490

struct BndS5
{
    float x, y, z, r;
};
struct Nd5;
struct AV5
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Nd5* IsSceneNode();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* IsGeom();
    char pad04[0x1c];
    BndS5* pBound;
    char pad24[0xc];
    unsigned int flags;
};
struct Nd5 : AV5
{
    char pad34[0x6c];
    AV5** children;
    unsigned short maxSize;
    unsigned short count;
};
struct SW5
{
    AV5* FUN_00b5aa40();
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*);
};
extern const char* const g_011f5f1c_arg1;
bool FUN_00b5b410(AV5*, void*, void*, bool);
bool CheckBoundAndChildren(AV5* obj, void* a, void* b, bool c);

// @fnv 0x00b5c5c0
bool CheckBoundAndChildren(AV5* apObject, void* apArg1, void* apArg2, bool c)
{
    if (!apObject)
        return true;
    if (apObject->pBound && apObject->pBound->r != 0.0f && !(apObject->flags & 1) && apObject->IsSceneNode())
    {
        Nd5* node = apObject->IsSceneNode();
        bool result = true;
        unsigned int i = 0;
        SW5* sw;
        if (node && (sw = (SW5*)((DynCastHelper*)node)->DynamicCast(&g_011f5f1c_arg1)) != 0)
        {
            AV5* child = sw->FUN_00b5aa40();
            if (child)
                result &= CheckBoundAndChildren(child, apArg1, apArg2, c);
        }
        else
        {
            for (; i < node->count; i++)
            {
                AV5* pChild = node->children[i];
                if (pChild)
                {
                    if (pChild->IsGeom())
                        result &= FUN_00b5b410(pChild, apArg1, apArg2, c);
                    else
                        result &= CheckBoundAndChildren(pChild, apArg1, apArg2, c);
                }
            }
        }
        return result;
    }
    return false;
}

namespace fnv_00b5c7d0 {
struct StrArr
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};
struct FUN_00c51570_Class
{
    void* FUN_00a5ea70(void*);
};
char* FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d490(const char*, unsigned short);
char* __cdecl FUN_00a7d4d0(const char*, int);
extern const char* g_011f9e80;

struct LightNode
{
    LightNode* next;
    LightNode* prev;
    char* light;
};

struct ShadowSceneNodeS : FUN_00c51570_Class
{
    unsigned int InitializeTESResources() const
    {
        return *(unsigned int*)((char*)this + 0xbc);
    }
    static char* const& Next(LightNode*& pos)
    {
        char* const& e = pos->light;
        pos = pos->next;
        return e;
    }
    char* GetLightAt(unsigned short usIndex) const
    {
        if (usIndex >= *(unsigned int*)((char*)this + 0xbc))
            return 0;
        LightNode* pos = *(LightNode**)((char*)this + 0xb4);
        char* light = Next(pos);
        for (unsigned int i = 0; i < usIndex; i++)
            light = Next(pos);
        return light;
    }
    void AppendLightStats(StrArr* pkStrings);
};

// @fnv 0x00b5c7d0
void ShadowSceneNodeS::AppendLightStats(StrArr* pkStrings)
{
    FUN_00c51570_Class::FUN_00a5ea70(pkStrings);
    char* s = FUN_00a7d330(g_011f9e80);
    pkStrings->Add(s);
    s = FUN_00a7d490("light count", InitializeTESResources());
    pkStrings->Add(s);
    int iShadowLightCount = 0;
    unsigned int ItemUpdateArray = InitializeTESResources();
    for (int i = 0; i < (unsigned short)ItemUpdateArray; i++)
    {
        if (GetLightAt((unsigned short)i)[0xec])
            iShadowLightCount++;
    }
    s = FUN_00a7d4d0("shadow light count", iShadowLightCount);
    pkStrings->Add(s);
}
}  // namespace fnv_00b5c7d0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern int _fnv_particle_shader_renderer_level;
extern char DAT_011f91d8;

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

struct AutoMemContext
{
    int oldContext;
    AutoMemContext(int newContext)
    {
        oldContext = g_tlsData.memContext;
        g_tlsData.memContext = newContext;
    }
    ~AutoMemContext()
    {
        g_tlsData.memContext = oldContext;
    }
};

struct BSRenderedTextureHelper : BSRenderedTexture
{
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};

struct TexturePtr
{
    BSRenderedTextureHelper* m_pObject;
    void operator=(BSRenderedTextureHelper* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
        }
    }
    operator BSRenderedTexture*() const
    {
        return m_pObject;
    }
};

struct FUN_00b9dcb0_Class
{
    char pad_00[0xec];
    bool m_bFlagEC;
    char pad_ed[0x1f];
    TexturePtr m_spShadowTexture;

    void SetShadowEnabled(bool bEnable);
};

// @fnv 0x00b9dcb0
void FUN_00b9dcb0_Class::SetShadowEnabled(bool bEnable)
{
    AutoMemContext memContext(0x20);

    int bShadows = 0;
    if ((!m_bFlagEC || bEnable) && _fnv_particle_shader_renderer_level >= 3)
        bShadows = (DAT_011f91d8 & 0x10) > 0;

    if (!(char)bShadows)
    {
        if (m_spShadowTexture)
        {
            DAT_011f91a8->RemoveRenderedTexture(m_spShadowTexture);
            m_spShadowTexture = 0;
        }
    }
    m_bFlagEC = bEnable;
}

namespace fnv_00b9dda0 {
extern "C"
{
    __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
}

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

extern const NiRTTI g_011f5ec4_arg1;
extern const NiRTTI g_011f5f6c;

struct NiLight
{
    virtual void vfn_00();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    long m_uiRefCount;
    char pad_08[0x8c - 8];
    NiPoint3 m_kPoint8C;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }

    bool IsKindOfType(const NiRTTI* pkRTTI) const
    {
        for (const NiRTTI* pkType = GetRTTI(); pkType; pkType = pkType->m_pBaseRTTI)
        {
            if (pkType == pkRTTI)
                return true;
        }
        return false;
    }
};

struct FUN_00b9dda0_Class
{
    char pad_00[0xd0];
    float m_fFloatD0;
    char pad_d4[0x20];
    bool m_bFlagF4;
    bool m_bFlagF5;
    char pad_f6[2];
    NiPointer<NiLight> m_spLight;
    bool m_bFlagFC;
    char pad_fd[3];
    NiPoint3 m_kPoint100;

    void FUN_00b9dda0(NiLight* apTargetLight);
};

// @fnv 0x00b9dda0
void FUN_00b9dda0_Class::FUN_00b9dda0(NiLight* apLight)
{
    m_spLight = apLight;

    bool bKind1 = apLight && apLight->IsKindOfType(&g_011f5ec4_arg1);
    m_bFlagF4 = bKind1;
    if (bKind1)
    {
        if (m_bFlagFC)
            m_kPoint100 = apLight->m_kPoint8C;
    }
    else
    {
        m_fFloatD0 = 1.0f;
    }

    bool bKind2 = apLight && apLight->IsKindOfType(&g_011f5f6c);
    m_bFlagF5 = bKind2;
}
}  // namespace fnv_00b9dda0

typedef bool(__cdecl* FUN_00b5a930_pred)(void** item, void* ctx);

class FUN_00b5a930_cls
{
  public:
    unsigned int unk00;
    void** m_ppItems;
    unsigned int m_uiCount;
    int FindFirstMatch(void* ctx, unsigned int start, FUN_00b5a930_pred pred);
};

// Scans m_ppItems from start to m_uiCount, returning the first index whose item satisfies pred, or -1 if none match.
// @fnv 0x00b5a930
int FUN_00b5a930_cls::FindFirstMatch(void* apContext, unsigned int start, FUN_00b5a930_pred apPredicate)
{
    if (start < m_uiCount)
    {
        do
        {
            if (m_ppItems != 0)
            {
                if (apPredicate(&m_ppItems[start], apContext))
                {
                    return (int)start;
                }
            }
            ++start;
        } while (start < m_uiCount);
    }
    return -1;
}

struct S_Item
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int m_f8;
};
struct S_Node
{
    S_Node* m_pNext;
    int unk04;
    S_Item* m_pInventoryEntryData;
};
struct S_Cls
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    S_Node* m_pHead;
    int unkC4;
    int unkC8;
    S_Node* volatile m_pCur;
    S_Item* FUN_00b5afc0();
};
// @fnv 0x00b5afc0
S_Item* S_Cls::FUN_00b5afc0()
{
    S_Node* node = m_pHead;
    m_pCur = node;
    if (!node)
        return 0;
    S_Node* next = node->m_pNext;
    m_pCur = next;
    S_Item* it = node->m_pInventoryEntryData;
    while (next)
    {
        if (it && it->m_f8)
            break;
        node = m_pCur;
        next = node->m_pNext;
        m_pCur = next;
        it = node->m_pInventoryEntryData;
    }
    return it;
}

struct FUN_00b5b010_item;
struct FreeListNode
{
    FreeListNode* m_pNext;
    unsigned int unk04;
    FUN_00b5b010_item* m_pInventoryEntryData;
};
struct FUN_00b5b010_item
{
    unsigned int unk00;
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
    unsigned int m_uiF8;
};
class FUN_00b5b010_cls
{
  public:
    unsigned int unk00;
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
    FreeListNode* m_pHead;
    FUN_00b5b010_item* FUN_00b5b010();
};
// Pops nodes from the m_pHead list and returns the first item whose m_uiF8 is nonzero, or the last popped item.
// @fnv 0x00b5b010
FUN_00b5b010_item* FUN_00b5b010_cls::FUN_00b5b010()
{
    FUN_00b5b010_item* item = 0;
    if (m_pHead != 0)
    {
        FreeListNode* node = *(FreeListNode* volatile*)&m_pHead;
        m_pHead = node->m_pNext;
        item = node->m_pInventoryEntryData;
        while (m_pHead != 0)
        {
            if (item != 0 && item->m_uiF8 != 0)
                return item;
            node = *(FreeListNode* volatile*)&m_pHead;
            m_pHead = node->m_pNext;
            item = node->m_pInventoryEntryData;
        }
    }
    return item;
}

struct TexMgrStandIn
{
    void FUN_00b6d4c0(BSRenderedTexture* pTileTexture);
    void ReleaseCounted();
};

struct LightNodeStandIn
{
    LightNodeStandIn* m_pkNext;
    LightNodeStandIn* m_pkPrev;
    ShadowSceneLight* m_val;
};

static inline ShadowSceneLight*& GetNextLightStandIn(LightNodeStandIn*& pkIter)
{
    ShadowSceneLight*& kVal = pkIter->m_val;
    pkIter = pkIter->m_pkNext;
    return kVal;
}

// @fnv 0x00b5b1f0
void __fastcall FUN_00b5b1f0(ShadowSceneNode* pThis, int)
{
    LightNodeStandIn* pLightNode = (LightNodeStandIn*)pThis->shadowLights.head;
    while (pLightNode)
    {
        ShadowSceneLight* light = GetNextLightStandIn(pLightNode);
        if (light)
        {
            ((TexMgrStandIn*)DAT_011f91a8)->FUN_00b6d4c0(light->texture);
            BSRenderedTexture* pTexture = light->texture;
            if (pTexture)
            {
                if (InterlockedDecrement(&pTexture->refs) == 0)
                    pTexture->DeleteThis();
                light->texture = 0;
            }
        }
    }
    ((TexMgrStandIn*)DAT_011f91a8)->ReleaseCounted();
}

struct SearchNode
{
    SearchNode* next;
    SearchNode* previous;
    char* item;
};
struct SearchList
{
    void* unused00;
    void* unused04;
    SearchNode* first;
};
struct ProcessArgs
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct SearchObject
{
    unsigned char CheckProcStateAndPlane(ProcessArgs args, char* target, char* item);
};
struct ShadowProcessor
{
    void ProcessTargetIfEligible(SearchObject* source, ProcessArgs args, char* target);
};
typedef unsigned char(__thiscall* TestCallback)(void*, char*);
// @fnv 0x00b5bbe0
void ShadowProcessor::ProcessTargetIfEligible(SearchObject* source, ProcessArgs args, char* target)
{
    char* subobject = *(char**)((char*)source + 0xac);
    void* object = *(void**)(subobject + 0xc);
    unsigned int type = *(unsigned int*)(target + 0x90);
    unsigned int state = *(unsigned int*)((char*)object + 8);
    if (type != 1 && type != 3 && state == 0 && *(unsigned short*)((char*)source + 0xa8) > (unsigned short)state)
    {
        unsigned char accepted = (*(TestCallback*)((char*)*(void**)object + 0x9c))(object, target + 0x2c);
        *(unsigned int*)(*(char**)(*(char**)((char*)source + 0xac) + 0xc) + 8) = (accepted == 0) + 1;
        if (accepted)
        {
            SearchList* list = *(SearchList**)((char*)this + 0x1e0);
            if (list)
            {
                SearchNode* position = list->first;
                while (position)
                {
                    char** ppItem = &position->item;
                    position = position->next;
                    char* item = *ppItem;
                    if (item && *(unsigned int*)(item + 0x40) == 1)
                    {
                        if (!source->CheckProcStateAndPlane(args, target, item))
                            break;
                    }
                }
            }
        }
    }
}

struct NiRTTI_b5
{
    const char* m_pcName;
    const NiRTTI_b5* m_pBaseRTTI;
};

extern NiRTTI_b5 DAT_011f4a28;
extern NiRTTI_b5 DAT_011f4a98;

struct Pt3_b5
{
    float x, y, z;
    Pt3_b5(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};

struct UpdData_b5
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bFlag;
    UpdData_b5()
    {
        m_fTime = 0.0f;
        m_bUpdate = false;
        m_bIsMultiThreaded = false;
        m_bUpdateGeomorphs = false;
        m_bUpdateShadowSceneNode = false;
        m_bFlag = false;
    }
};

struct Node_b5;

struct AV_b5
{
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI_b5* GetRTTI();
    virtual Node_b5* IsSceneNode();
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
    void Update(UpdData_b5& data);
    struct Cast_b5* DynamicCast(const NiRTTI_b5* rtti);
};

struct Cast_b5
{
    int unkPlaceholder;
};

struct Node_b5 : AV_b5
{
    AV_b5** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short GetArrayCount() const
    {
        return m_usSize;
    }
};

struct Geom_b5 : AV_b5
{
    int unka0;
    int unka4;
    unsigned int m_uiRevID;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Pt3_b5 m_kVec;
};

inline bool IsKindOf_b5(const NiRTTI_b5* pkRTTI, AV_b5* pkObj)
{
    const NiRTTI_b5* r = pkObj->GetRTTI();
    while (r)
    {
        if (r == pkRTTI)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}

struct SSN_b5
{
    void FUN_00b5c940(AV_b5* obj, bool flag);
    int FUN_00b5ca70(Node_b5* node, float time);
};

// @fnv 0x00b5ca70
int SSN_b5::FUN_00b5ca70(Node_b5* node, float time)
{
    int count = 0;
    for (unsigned int i = 0; i < node->GetArrayCount(); i++)
    {
        AV_b5* child = node->m_pBase[i];
        if (!child)
            continue;
        Node_b5* sub = child->IsSceneNode();
        if (sub)
        {
            count += FUN_00b5ca70(sub, time);
            continue;
        }
        AV_b5* obj = IsKindOf_b5(&DAT_011f4a28, child) ? child : 0;
        if (!obj)
            continue;
        FUN_00b5c940(obj, true);
        UpdData_b5 data;
        obj->Update(data);
        Geom_b5* g = (Geom_b5*)obj->DynamicCast(&DAT_011f4a98);
        if (g)
        {
            g->m_uiRevID++;
            g->m_kVec = Pt3_b5(time, 0.0f, 0.0f);
        }
        count++;
    }
    return count;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_refs;
    void AcquireReference()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_refs) == 0)
            DeleteThis();
    }
};

template <class T> struct RefPtr
{
    T* m_p;
    RefPtr& operator=(T* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRef();
            m_p = p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
    operator T*() const
    {
        return m_p;
    }
    T* operator->() const
    {
        return m_p;
    }
};

struct ShadowRenderTarget : RefObj
{
    ShadowRenderTarget(int a);
    static void* operator new(unsigned int);
    static void operator delete(void*);
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
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
    RefPtr<RefObj> sp130;
    int unk134;
    int unk138;
    int unk13c;
};

struct UpdateData
{
    float fTime;
    bool b4;
    bool b5;
    bool b6;
    bool b7;
    bool b8;
    UpdateData(float t = 0.0f, bool a = false, bool b = false, bool c = false, bool d = false, bool e = false)
        : fTime(t), b4(a), b5(b), b6(c), b7(d), b8(e)
    {}
};

struct AVObj
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
    unsigned int m_uiObjectFlags;
    void Update(UpdateData& data);
};

struct ShadowLight
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    AVObj* m_pLight;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    unsigned short m_usIndex;
    void Deactivate();
    void Render(int arg, int idx);
};

struct LightNode
{
    LightNode* m_pNext;
    LightNode* m_pListObject;
    ShadowLight* m_pInventoryEntryData;
};

inline ShadowLight* const& GetNext(LightNode*& pos)
{
    ShadowLight* const& item = pos->m_pInventoryEntryData;
    pos = pos->m_pNext;
    return item;
}

struct RenderHelper
{
    int unk00;
    void SetTarget(int a, int b);
};
extern RenderHelper g_renderHelper;
extern ShadowLight* g_pCurrentShadowLight;

struct ShadowSceneNodeX
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
    LightNode* m_pShadowHead;
    LightNode* m_pShadowTail;
    unsigned int m_uiShadowCount;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
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
    RefPtr<ShadowRenderTarget> m_spReferencedObject;
    void FUN_00b5b880(int arg);
};

// @fnv 0x00b5b880
void ShadowSceneNodeX::FUN_00b5b880(int arg)
{
    AutoMemContext ctx(0x20);
    if (!m_spReferencedObject)
    {
        m_spReferencedObject = new ShadowRenderTarget(0);
    }
    m_spReferencedObject->unk114 = 0;
    if (m_uiShadowCount)
    {
        int n = 0;
        LightNode* pos = m_pShadowHead;
        while (pos)
        {
            ShadowLight* light = GetNext(pos);
            if (light && light->m_pLight)
            {
                if (!(light->m_pLight->m_uiObjectFlags & 1))
                {
                    UpdateData data;
                    light->m_pLight->Update(data);
                    if (light->m_usIndex != 0xff)
                    {
                        g_pCurrentShadowLight = light;
                        light->Render(arg, n);
                        n++;
                    }
                }
                else
                {
                    light->Deactivate();
                }
            }
        }
        for (int i = n + 0x11; i < 0x15; i++)
            g_renderHelper.SetTarget(1, i);
    }
    m_spReferencedObject->sp130 = 0;
}

struct SPData
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
    int iCount;
};

struct SPPropData
{
    int unk00;
    int unk04;
    int iType;
};

struct SPProperty
{
    int unk00;
    int unk04;
    int unk08;
    SPPropData* pData;
};

struct SPRenderer
{
    void Begin(int aiPass);
    void BeginPair();
    void EndPair();
    void AddData(SPData* apData);
    void Flush();
    void End();
};

struct SPGeometry
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
    SPProperty* pProperty;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    SPData* m_pSPData;
};

struct SPOwnerGeom
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
    SPRenderer* pRenderer;
};

struct SPPass
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
    SPGeometry* pGeomA;
    SPGeometry* pGeomB;
    SPOwnerGeom* pOwner;
};

struct SPShader
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
    SPData kDefaultData;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    bool bDefaultEnabled;

    void FUN_00b5ba80(int aiPass, SPPass* apPass);
};

// @fnv 0x00b5ba80
void SPShader::FUN_00b5ba80(int aiPass, SPPass* apPass)
{
    SPRenderer* pRenderer = apPass->pOwner->pRenderer;
    SPGeometry* pGeomA = apPass->pGeomA;
    SPGeometry* pGeomB = apPass->pGeomB;

    bool bEnabledA = pGeomA ? pGeomA->pProperty->pData->iType == 1 : bDefaultEnabled;
    bool bEnabledB = pGeomB ? pGeomB->pProperty->pData->iType == 1 : bDefaultEnabled;
    bool bUseA = pGeomA ? (bEnabledA && pGeomA->m_pSPData) : kDefaultData.iCount == 0;
    bool bUseB = pGeomB ? (bEnabledB && pGeomB->m_pSPData) : kDefaultData.iCount == 0;
    SPData* pDataA = pGeomA ? pGeomA->m_pSPData : &kDefaultData;
    SPData* pDataB = pGeomB ? pGeomB->m_pSPData : &kDefaultData;

    pRenderer->Begin(aiPass);
    if (bEnabledA && !pDataA->iCount)
        return;
    if (bEnabledB && !pDataB->iCount)
        return;

    if (bUseA && !bUseB)
    {
        pRenderer->AddData(pDataA);
    }
    else if (!bUseA && bUseB)
    {
        pRenderer->AddData(pDataB);
    }
    else if (bUseA && bUseB)
    {
        pRenderer->BeginPair();
        pRenderer->AddData(pDataA);
        pRenderer->AddData(pDataB);
        pRenderer->EndPair();
    }
    pRenderer->Flush();
    pRenderer->End();
}

struct BoundRef_t
{
    void* m_pObject;
};

struct BoundList_t
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void AddTail(const BoundRef_t& kBound);
};

struct GlobalLock_t
{
    unsigned int m_uiThread;
    unsigned int m_uiCount;
    void Lock(const char* pcName);
    void Unlock()
    {
        if (--m_uiCount == 0)
            m_uiThread = 0;
    }
};
extern GlobalLock_t DAT_011f9ea0;

struct BoundOwner_t
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    BoundList_t m_kBounds;
    int unkFC;
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
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    unsigned char m_b1FC;

    void AddBound(BoundRef_t* pkBound);
};

// If pkBound has an object and m_b1FC is set, locks DAT_011f9ea0, appends pkBound to m_kBounds, then unlocks.
// @fnv 0x00b5cff0
void BoundOwner_t::AddBound(BoundRef_t* pkBound)
{
    if (!pkBound->m_pObject)
        return;
    if (!m_b1FC)
        return;
    DAT_011f9ea0.Lock(0);
    m_kBounds.AddTail(*pkBound);
    DAT_011f9ea0.Unlock();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class BSMultiBoundB5D
{
  public:
    virtual ~BSMultiBoundB5D();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class NiPointerB5D
{
  public:
    NiPointerB5D(T* pObject) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointerB5D(const NiPointerB5D& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerB5D()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

template <class T> struct NiTListItemB5D
{
    NiTListItemB5D* m_pkNext;
    NiTListItemB5D* m_pkPrev;
    T m_element;
};

NiTListItemB5D<NiPointerB5D<BSMultiBoundB5D> >* __cdecl NewListItemB5D(BSMultiBoundB5D* pkObject);

template <class T> class NiTPointerListB5D
{
  public:
    T& GetNext(NiTListItemB5D<T>*& pkPos)
    {
        T& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return element;
    }

    __declspec(noinline) void AddTail(const T& element)
    {
        NiTListItemB5D<T>* pkItem = NewListItemB5D(element.m_pObject);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        m_uiCount++;
    }

    void RemoveAll();

    NiTListItemB5D<T>* m_pkHead;
    NiTListItemB5D<T>* m_pkTail;
    unsigned int m_uiCount;
};

class CriticalLockB5D
{
  public:
    void Lock(const char* pcName);
    void Unlock()
    {
        if (--m_uiLockCount == 0)
            m_uiOwner = 0;
    }

    unsigned int m_uiOwner;
    unsigned int m_uiLockCount;
};

extern CriticalLockB5D g_kMultiBoundLockB5D;

class MultiBoundManagerB5D
{
  public:
    void Refresh();
    void FUN_00b5d180();

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
    NiTPointerListB5D<NiPointerB5D<BSMultiBoundB5D> > m_kBounds;
    NiTPointerListB5D<NiPointerB5D<BSMultiBoundB5D> > m_kVisible;
    int unkCC;
    int m_iVisibleFirst;
    int m_iVisibleLast;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    NiTPointerListB5D<NiPointerB5D<BSMultiBoundB5D> > m_kPending;
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
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    bool m_bDeferUpdates;
};

// @fnv 0x00b5d180
void MultiBoundManagerB5D::FUN_00b5d180()
{
    NiTListItemB5D<NiPointerB5D<BSMultiBoundB5D> >* pkPos = m_kBounds.m_pkHead;
    while (pkPos)
    {
        BSMultiBoundB5D* pkBound = m_kBounds.GetNext(pkPos).m_pObject;
        if (pkBound)
        {
            NiPointerB5D<BSMultiBoundB5D> pMultiBound(pkBound);
            if (m_bDeferUpdates)
            {
                g_kMultiBoundLockB5D.Lock(0);
                m_kPending.AddTail(pMultiBound);
                g_kMultiBoundLockB5D.Unlock();
            }
        }
    }
    Refresh();
    m_kVisible.RemoveAll();
    m_iVisibleFirst = 0;
    m_iVisibleLast = 0;
    Refresh();
}

struct Obj_b5d270
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void v39(void* apOwner);
    long m_lRefCount;
    unsigned int unkValue;
    unsigned int m_uiKey;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};

struct ObjPtr_b5d270
{
    Obj_b5d270* m_pObject;
    ObjPtr_b5d270(Obj_b5d270* pObject)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ObjPtr_b5d270()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ObjPtr_b5d270& operator=(const ObjPtr_b5d270& kPtr)
    {
        if (m_pObject != kPtr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = kPtr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    Obj_b5d270* operator->() const
    {
        return m_pObject;
    }
};

struct Node_b5d270
{
    Node_b5d270* m_pkNext;
    Node_b5d270* m_pkPrev;
    ObjPtr_b5d270 m_element;
};

struct Alloc_b5d270
{
    unsigned int m_uiCount;
    void* FUN_0043a010();
};

struct List_b5d270
{
    Node_b5d270* m_pkHead;
    Node_b5d270* m_pkTail;
    Alloc_b5d270 m_kItemCount;

    void FUN_00a5a310(const ObjPtr_b5d270& element)
    {
        Node_b5d270* pkNode = (Node_b5d270*)m_kItemCount.FUN_0043a010();
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_kItemCount.m_uiCount++;
        m_pkTail = pkNode;
    }
};

struct Shell_b5d270
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
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
    int unka;
    int unkaCur;
    int unkaValue;
    int unkac;
    int unkb;
    int unkbCur;
    int unkbValue;
    int unkbc;
    int unkc;
    int unkcCur;
    int unkcValue;
    int unkcc;
    int unkd;
    int unkdCur;
    int unkdValue;
    int unkdc;
    int unke;
    int unkeCur;
    int unkeValue;
    int unkec;
    int unkf;
    int unkfCur;
    int unkfValue;
    List_b5d270 m_kList;

    void FUN_00b5d270(Obj_b5d270* pObj);
};

// If pObj is non-null, appends it to m_kList via FUN_00a5a310.
// @fnv 0x00b5d270
void Shell_b5d270::FUN_00b5d270(Obj_b5d270* pObj)
{
    if (pObj)
        m_kList.FUN_00a5a310(pObj);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Vec
{
    float x, y, z;
    Vec()
    {}
    Vec(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
extern Vec DAT_011f426c;

struct Ref
{
    virtual void first();
    virtual void DeleteThis();
    long refs;
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <class T> struct Ptr
{
    T* p;
    Ptr() : p(0)
    {}
    ~Ptr()
    {
        if (p)
            p->Dec();
    }
    void operator=(T* q)
    {
        if (p != q)
        {
            if (p)
                p->Dec();
            p = q;
            if (q)
                InterlockedIncrement(&q->refs);
        }
    }
    T* operator->()
    {
        return p;
    }
};
struct List
{
    void* head;
    void* tail;
    unsigned count;
    List()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    ~List();
    void FUN_00e74d40();
};
struct Frustum
{
    Frustum();
    ~Frustum();
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
};
struct Bound;
struct Base
{
    Bound* EnsureBound();
    void SetRadius(float);
    Base(unsigned);
    virtual ~Base();
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
    virtual void SetObjectBound(void*);
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    struct Bound* bound;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned flags;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    void AssignFixedString(const struct Fixed&);
};
struct StringTable
{
    static char* AddString(const char*);
};
extern char* DAT_0109b220;
struct Fixed
{
    char* text;
    Fixed(const char* s) : text(StringTable::AddString(s))
    {}
    __forceinline ~Fixed()
    {
        if (text != DAT_0109b220)
            InterlockedDecrement((volatile long*)(text - 8));
    }
};
struct Alloc
{
    static void* operator new(unsigned);
    static void operator delete(void*);
};
struct Light : Ref, Alloc
{
    Light();
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned revision;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    NiColor ambient, diffuse;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    void SetAmbient(const NiColor& c)
    {
        ambient = c;
        revision++;
    }
    void SetDiffuse(const NiColor& c)
    {
        diffuse = c;
        revision++;
    }
};
struct SceneLight : Ref, Alloc
{
    SceneLight();
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    void SetLight(Light*);
};
struct Fog : Ref, Alloc
{
    Fog();
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    Vec color;
    float near1, far1, near2, far2;
    void SetRange1(float v)
    {
        near1 = v;
        far1 = v;
    }
    void SetRange2(float v)
    {
        near2 = v;
        far2 = v;
    }
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    Vec color2;
    unsigned unk060;
};
struct Bound
{
    Vec center;
    float radius;
};
struct Manager
{
    void* Allocate(unsigned);
};
extern Manager _g_memoryManager;
inline Bound* Base::EnsureBound()
{
    if (!bound)
    {
        void* allocation = _g_memoryManager.Allocate(16);
        SetObjectBound(allocation);
        Bound* b = bound;
        b->center = DAT_011f426c;
        b->radius = 0;
    }
    return bound;
}
inline void Base::SetRadius(float r)
{
    bound->radius = r;
}
struct FUN_00b5e0f0 : Base
{
    List lights, shadowLights;
    unsigned unknownCC, count, count2;
    Ptr<SceneLight> light1, light2;
    SceneLight* directional;
    List listE4, listF0, listFC, list108, list114;
    unsigned unknown120;
    Ptr<Ref> ref124, ref128;
    unsigned unknown12C;
    bool flag130, flag131;
    unsigned short unknown132;
    Ptr<Fog> fog;
    Frustum frustum;
    bool flag1DC;
    unsigned unknown1E0;
    Vec position, offset;
    bool flag1FC;
    virtual ~FUN_00b5e0f0();
    FUN_00b5e0f0();
};
// @fnv 0x00b5e0f0
FUN_00b5e0f0::FUN_00b5e0f0() : Base(0)
{
    AssignFixedString(Fixed("shadow scene node"));
    lights.FUN_00e74d40();
    shadowLights.FUN_00e74d40();
    ref124 = (Ref*)0;
    unknown12C = 0;
    flag130 = false;
    flag1DC = true;
    offset = DAT_011f426c;
    unknown1E0 = 0;
    light1 = new SceneLight;
    light2 = new SceneLight;
    count = 0;
    count2 = 0;
    Light* light = new Light;
    light->SetAmbient(DAT_011f4998);
    light->SetDiffuse(DAT_011f4998);
    directional = new SceneLight;
    directional->SetLight(light);
    flags |= 0x800;
    EnsureBound()->radius = 1;
    flags |= 0x2000;
    flag131 = false;
    position = DAT_011f426c;
    flag1FC = true;
    fog = new Fog;
    fog->SetRange1(500000.0f);
    fog->SetRange2(500000.0f);
    fog->color = Vec(0.5f, 0.5f, 0.5f);
    fog->color2 = Vec(0.5f, 0.5f, 0.5f);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class BSMultiBoundB5E
{
  public:
    virtual ~BSMultiBoundB5E();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
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
    void* m_pvOwner;
};

template <class T> class NiPointerB5E
{
  public:
    NiPointerB5E(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerB5E()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

template <class T> struct NiTListItemB5E
{
    NiTListItemB5E* m_pkNext;
    NiTListItemB5E* m_pkPrev;
    T m_element;
};

typedef NiTListItemB5E<NiPointerB5E<BSMultiBoundB5E> > BoundItemB5E;

template <class T> class NiTPointerListB5E
{
  public:
    T& GetNext(NiTListItemB5E<T>*& pkPos)
    {
        T& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return element;
    }

    NiTListItemB5E<T>* m_pkHead;
    NiTListItemB5E<T>* m_pkTail;
    unsigned int m_uiCount;
};

void __cdecl ReleaseBoundB5E(BSMultiBoundB5E* pkBound);

class MultiBoundManagerB5E
{
  public:
    __declspec(noinline) void RemoveBound(const NiPointerB5E<BSMultiBoundB5E>& pMultiBound)
    {
        ReleaseBoundB5E(pMultiBound.m_pObject);
        m_uiRemoved++;
    }

    void RemoveBoundByOwner(void* pvOwner);

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
    NiTPointerListB5E<NiPointerB5E<BSMultiBoundB5E> > m_kBounds;
    unsigned int m_uiRemoved;
};

// Scans m_kBounds for a bound whose m_pvOwner equals pvOwner and removes the first match via RemoveBound.
// @fnv 0x00b5edf0
void MultiBoundManagerB5E::RemoveBoundByOwner(void* pvOwner)
{
    if (!pvOwner)
        return;
    BoundItemB5E* pkPos = m_kBounds.m_pkHead;
    while (pkPos)
    {
        BSMultiBoundB5E* pkBound = m_kBounds.GetNext(pkPos).m_pObject;
        if (pkBound && pkBound->m_pvOwner == pvOwner)
        {
            RemoveBound(pkBound);
            return;
        }
    }
}

struct Allocator
{
    virtual ~Allocator();
    virtual void* allocate(int);
    virtual void f2();
    virtual void f3();
    virtual void release(void*, int);
};
struct Router
{
    int unk00, unk04, unk08, unk0c;
    Allocator* heapPtr;
    __forceinline Allocator& heap()
    {
        return *heapPtr;
    }
};
Router& FUN_00c85750();
struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    unsigned short bytes, refs;
    static __forceinline void* operator new(unsigned int amount)
    {
        void* result = FUN_00c85750().heap().allocate(amount);
        ((hkReferencedObject*)result)->bytes = (unsigned short)amount;
        return result;
    }
    static void operator delete(void*);
    void removeReference();
};
struct InterfacePart
{
    virtual void f0();
};
struct InterfaceArray;
void ResizeAudioStream(void*, void*, int);
struct InterfaceArray
{
    InterfacePart** data;
    int size;
    int capacity;
    __forceinline InterfaceArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~InterfaceArray()
    {
        Allocator* heap = &FUN_00c85750().heap();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap->release(data, (capacity & 0x3fffffff) * 4);
    }
    __forceinline void AddBack(InterfacePart* value)
    {
        Allocator* heap = &FUN_00c85750().heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(heap, this, 4);
        data[size++] = value;
    }
};
struct WorldContext : hkReferencedObject, InterfacePart
{
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
    WorldContext();
    void SetWorld(void*);
};
struct Process : hkReferencedObject
{
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
    Process(InterfaceArray&, int);
    void SetValue(int);
};
void FUN_00cd1ed0();
struct Root
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void* GetWorld();
    int unk04, unk08, unk0c;
    Process* process;
    void SetProcessEnabled(bool);
};
// Creates and stores a Process with a WorldContext when enable is true, or releases and clears process when false.
// @fnv 0x00c6a640
void Root::SetProcessEnabled(bool enable)
{
    AutoMemContext context(16);
    if (enable)
    {
        if (!process)
        {
            InterfaceArray array;
            FUN_00cd1ed0();
            WorldContext* item = new WorldContext;
            item->SetWorld(GetWorld());
            array.AddBack(item);
            process = new Process(array, 0);
            process->SetValue(0x61a9);
        }
    }
    else
    {
        if (process)
        {
            GetWorld();
            process->removeReference();
            process = 0;
        }
    }
}

struct FUN_00b5b0e0_Node
{
    FUN_00b5b0e0_Node* unk00;
    FUN_00b5b0e0_Node* unk04;
    void* unk08;
};

class LightingElem;

class FUN_00b5b0e0_Prop
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiShaderType;
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
    FUN_00b5b0e0_Node* m_pkHead;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    LightingElem* GetNext(void** pos);
};

class LightingElem
{
  public:
    void FUN_00ba01a0(void* arg1, int arg2);
};

struct FUN_00b5b0e0_Inner
{
    int unk9C;
    int unkA0;
    int unkA4;
    FUN_00b5b0e0_Prop* m_pProp;
};

struct FUN_00b5b0e0_Scene
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
    FUN_00b5b0e0_Inner m_kInner;
};

// Validates the prop's shader type and iterates its lighting elements, calling FUN_00ba01a0 on each with pv and 0.
// @fnv 0x00b5b0e0
void __cdecl FUN_00b5b0e0(void* pv)
{
    FUN_00b5b0e0_Scene* pObj = (FUN_00b5b0e0_Scene*)pv;
    if (!pObj)
        return;
    FUN_00b5b0e0_Inner* pInner = &pObj->m_kInner;
    FUN_00b5b0e0_Prop* pProp = pInner ? pInner->m_pProp : 0;
    if (!pProp)
        pProp = pObj->m_kInner.m_pProp;
    int bValidShader = pProp == 0 ? 0 : (int)((unsigned int)(pProp->m_uiShaderType - 1) <= 11);
    FUN_00b5b0e0_Prop* pValidProp = bValidShader ? pProp : 0;
    if (pValidProp)
    {
        void* pos;
        LightingElem* pElem;
        while ((pElem = pValidProp->GetNext(&pos)) != 0)
            pElem->FUN_00ba01a0(pv, 0);
    }
}

namespace fnv_00b5d040 {
struct RefPtr_b9fcc0
{
    NiObject* m_pObject;
    ~RefPtr_b9fcc0()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

struct List_b9fcc0
{
    int head;
    int tail;
    unsigned int count;
    RefPtr_b9fcc0 Remove(void* object);
};

int __cdecl FUN_00b5a980(int*, int*);

struct Container_b5a
{
    void* vtable;
    void** data;
    unsigned int count;
    unsigned int capacity;
    int Find(void* object, int zero, int(__cdecl* callback)(int*, int*));
    void RemoveAt(unsigned int index, bool a2);
};

struct Item1
{
    int item1_00;
    int item1_04;
    int item1_08;
    int item1_0C;
    int item1_10;
    int item1_14;
    int item1_18;
    int item1_1C;
    int item1_20;
    int item1_24;
    int item1_28;
    int item1_2C;
    int item1_30;
    int item1_34;
    int item1_38;
    int item1_3C;
    int item1_40;
    int item1_44;
    int item1_48;
    int item1_4C;
    int item1_50;
    int item1_54;
    int item1_58;
    int item1_5C;
    int item1_60;
    int item1_64;
    int item1_68;
    int item1_6C;
    int item1_70;
    int item1_74;
    int item1_78;
    int item1_7C;
    int item1_80;
    int item1_84;
    int item1_88;
    int item1_8C;
    int item1_90;
    int item1_94;
    int item1_98;
    int item1_9C;
    int item1_A0;
    int item1_A4;
    int item1_A8;
    int item1_AC;
    int item1_B0;
    int item1_B4;
    int item1_B8;
    int item1_BC;
    int item1_C0;
    int item1_C4;
    int item1_C8;
    int item1_CC;
    int item1_D0;
    int item1_D4;
    int item1_D8;
    Container_b5a container;
};

struct SubItem
{
    int sub_00;
    int sub_04;
    int sub_08;
    int sub_0C;
    int sub_10;
    int sub_14;
    int sub_18;
    int sub_1C;
    int sub_20;
    int sub_24;
    int sub_28;
    int sub_2C;
    int sub_30;
    int sub_34;
    int sub_38;
    int sub_3C;
    int sub_40;
    int sub_44;
    int sub_48;
    int sub_4C;
    int sub_50;
    int sub_54;
    int sub_58;
    int sub_5C;
    int sub_60;
    int sub_64;
    int sub_68;
    int sub_6C;
    int sub_70;
    int sub_74;
    int sub_78;
    int sub_7C;
    int sub_80;
    int sub_84;
    int sub_88;
    int sub_8C;
    int sub_90;
    int sub_94;
    int sub_98;
    int sub_9C;
    int sub_A0;
    int sub_A4;
    int sub_A8;
    int sub_AC;
    Container_b5a container;
};

struct Item2
{
    int item2_00;
    int item2_04;
    int item2_08;
    int item2_0C;
    int item2_10;
    int item2_14;
    int item2_18;
    int item2_1C;
    int item2_20;
    int item2_24;
    int item2_28;
    int item2_2C;
    int item2_30;
    int item2_34;
    int item2_38;
    int item2_3C;
    int item2_40;
    int item2_44;
    int item2_48;
    int item2_4C;
    int item2_50;
    int item2_54;
    int item2_58;
    int item2_5C;
    int item2_60;
    int item2_64;
    int item2_68;
    int item2_6C;
    int item2_70;
    int item2_74;
    int item2_78;
    int item2_7C;
    int item2_80;
    int item2_84;
    int item2_88;
    int item2_8C;
    int item2_90;
    int item2_94;
    int item2_98;
    int item2_9C;
    int item2_A0;
    int item2_A4;
    int item2_A8;
    int item2_AC;
    int item2_B0;
    int item2_B4;
    int item2_B8;
    int item2_BC;
    int item2_C0;
    int item2_C4;
    int item2_C8;
    int item2_CC;
    int item2_D0;
    int item2_D4;
    int item2_D8;
    int item2_DC;
    int item2_E0;
    int item2_E4;
    int item2_E8;
    int item2_EC;
    int item2_F0;
    int item2_F4;
    int item2_F8;
    int item2_FC;
    int item2_100;
    SubItem* subItem;
};

struct LightNode
{
    int light_00;
    int light_04;
    int light_08;
    int light_0C;
    int light_10;
    int light_14;
    int light_18;
    int light_1C;
    int light_20;
    int light_24;
    int light_28;
    int light_2C;
    int light_30;
    int light_34;
    int light_38;
    int light_3C;
    int light_40;
    int light_44;
    int light_48;
    int light_4C;
    int light_50;
    int light_54;
    int light_58;
    int light_5C;
    int light_60;
    int light_64;
    int light_68;
    int light_6C;
    int light_70;
    int light_74;
    int light_78;
    int light_7C;
    int light_80;
    int light_84;
    int light_88;
    int light_8C;
    int light_90;
    int light_94;
    int light_98;
    int light_9C;
    int light_A0;
    int light_A4;
    int light_A8;
    int light_AC;
    int light_B0;
    int light_B4;
    int light_B8;
    int light_BC;
    int light_C0;
    int light_C4;
    int light_C8;
    int light_CC;
    int light_D0;
    int light_D4;
    int light_D8;
    int light_DC;
    int light_E0;
    int light_E4;
    int light_E8;
    unsigned char unkEC;
    unsigned char unkED;
    unsigned char unkEE;
    unsigned char unkEF;
    int light_F0;
    int light_F4;
    int light_F8;
    int light_FC;
    int light_100;
    int light_104;
    int light_108;
    int light_10C;
    int light_110;
    int light_114;
    int light_118;
    int light_11C;
    int light_120;
    int light_124;
    int light_128;
    int light_12C;
    int light_130;
    int light_134;
    int light_138;
    int light_13C;
    int light_140;
    int light_144;
    int light_148;
    int light_14C;
    int light_150;
    int light_154;
    int light_158;
    int light_15C;
    int light_160;
    int light_164;
    int light_168;
    int light_16C;
    int light_170;
    int light_174;
    int light_178;
    int light_17C;
    int light_180;
    int light_184;
    int light_188;
    int light_18C;
    int light_190;
    int light_194;
    int light_198;
    int light_19C;
    int light_1A0;
    int light_1A4;
    int light_1A8;
    int light_1AC;
    int light_1B0;
    int light_1B4;
    int light_1B8;
    int light_1BC;
    int light_1C0;
    int light_1C4;
    int light_1C8;
    int light_1CC;
    int light_1D0;
    int light_1D4;
    int light_1D8;
    int light_1DC;
    int light_1E0;
    int light_1E4;
    int light_1E8;
    int light_1EC;
    int light_1F0;
    int light_1F4;
    int light_1F8;
    int light_1FC;
    int light_200;
    int light_204;
    int light_208;
    int light_20C;
    int light_210;
    Item1** items1;
    unsigned int count1;
    int unk21C;
    int unk220;
    Item2** items2;
    unsigned int count2;
};

struct AmbientLight
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
};

struct NodeTarget
{
    int node_00;
    int node_04;
    int node_08;
    int node_0C;
    int node_10;
    int node_14;
    int node_18;
    int node_1C;
    int node_20;
    int node_24;
    int node_28;
    int node_2C;
    int node_30;
    int node_34;
    int node_38;
    int node_3C;
    int node_40;
    int node_44;
    int node_48;
    int node_4C;
    int node_50;
    int node_54;
    int node_58;
    int node_5C;
    int node_60;
    int node_64;
    int node_68;
    int node_6C;
    int node_70;
    int node_74;
    int node_78;
    int node_7C;
    int node_80;
    int node_84;
    int node_88;
    int node_8C;
    int node_90;
    int node_94;
    int node_98;
    int node_9C;
    int node_A0;
    int node_A4;
    int node_A8;
    int node_AC;
    int node_B0;
    List_b9fcc0 lights;
    List_b9fcc0 shadowLights;
    int node_CC;
    int node_D0;
    int node_D4;
    int node_D8;
    int node_DC;
    int node_E0;
    int node_E4;
    int node_E8;
    int node_EC;
    int node_F0;
    int node_F4;
    int node_F8;
    int node_FC;
    int node_100;
    int node_104;
    int node_108;
    int node_10C;
    int node_110;
    int node_114;
    int node_118;
    int node_11C;
    int node_120;
    int node_124;
    int node_128;
    int node_12C;
    int node_130;
    int node_134;
    int node_138;
    int node_13C;
    int node_140;
    int node_144;
    int node_148;
    int node_14C;
    int node_150;
    int node_154;
    int node_158;
    int node_15C;
    int node_160;
    int node_164;
    int node_168;
    int node_16C;
    int node_170;
    int node_174;
    int node_178;
    int node_17C;
    int node_180;
    int node_184;
    int node_188;
    int node_18C;
    int node_190;
    int node_194;
    int node_198;
    int node_19C;
    int node_1A0;
    int node_1A4;
    int node_1A8;
    int node_1AC;
    int node_1B0;
    int node_1B4;
    int node_1B8;
    int node_1BC;
    int node_1C0;
    int node_1C4;
    int node_1C8;
    int node_1CC;
    int node_1D0;
    int node_1D4;
    int node_1D8;
    int node_1DC;
    AmbientLight* ambientLight;

    void RemoveLightFromNode(void** object, void* RemoveAmbientLight);
};

// @fnv 0x00b5d040
void NodeTarget::RemoveLightFromNode(void** object, void* apLight)
{

    if (ambientLight && ambientLight->unk28)
    {
        LightNode* node = (LightNode*)*object;
        for (unsigned int i = 0; i < node->count1; ++i)
        {
            Item1* item = node->items1[i];
            if (item && item->container.count)
            {
                int index = item->container.Find(object, 0, &FUN_00b5a980);
                if (index != -1)
                    item->container.RemoveAt(index, true);
            }
            node = (LightNode*)*object;
        }
        node = (LightNode*)*object;
        for (unsigned int i = 0; i < node->count2; ++i)
        {
            Item2* item = node->items2[i];
            if (item)
            {
                SubItem* sub = item->subItem;
                if (sub->container.count)
                {
                    Container_b5a* c = &sub->container;
                    unsigned int count = c->count;
                    int index = -1;
                    for (unsigned int j = 0; j < count; ++j)
                    {
                        if (c->data && c->data[j] == (void*)node)
                        {
                            index = j;
                            break;
                        }
                    }
                    if (index != -1)
                        c->RemoveAt(index, true);
                }
            }
            node = (LightNode*)*object;
        }
    }
    LightNode* node = (LightNode*)*object;
    if (node->unkEC)
        shadowLights.Remove(apLight);
    else
        lights.Remove(apLight);
}
}  // namespace fnv_00b5d040

void FUN_00e74d40();

// @fnv 0x00b5c7c0
void FUN_00b5c7c0()
{
    FUN_00e74d40();
}

struct Bnd5
{
    float x;
    float y;
    float z;
    float r;
};

extern unsigned int DAT_010a2720;
struct FUN_00aa54a0_s
{
    void* Allocate(unsigned int size, unsigned int extra);
    void* Allocate(unsigned int size)
    {
        return Allocate(size, DAT_010a2720);
    }
    void Deallocate(void* p);
};
struct MemMgr5
{
    FUN_00aa54a0_s* GetCtx();
};
extern "C" char DAT_011f6238;
extern "C" char DAT_011f4288;
extern "C" char DAT_01202828;
extern "C" char DAT_012030b8;
int __cdecl CompareFloatAtOffsetC(const void* a, const void* b);
void __cdecl FUN_00ec6f20(void* base, int count, int size, int(__cdecl* cmp)(const void*, const void*));

struct Obj5;
template <class T> struct S5_LArr
{
    void** m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int GetAllocatedSize() const
    {
        return m_uiMaxSize;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};
template <class T> struct S5_Item
{
    S5_Item* m_pkNext;
    S5_Item* m_pkPrev;
    T m_element;
};
template <class T> struct S5_List
{
    S5_Item<T>* m_pkHead;
    S5_Item<T>* m_pkTail;
    unsigned int m_uiCount;
    unsigned int GetSize() const
    {
        return m_uiCount;
    }
    S5_Item<T>* GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(S5_Item<T>*& pos) const
    {
        T& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
};

struct Obj5
{
    virtual void v0();
    virtual void v1();
    virtual const void* GetRtti();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int Predicate();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Obj5* child;
    int unk1c;
    Bnd5* bound;
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int key;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    unsigned short id;
    int GetKey() const
    {
        return key;
    }
    bool TestBound(Bnd5* b, int k, float f);
    float Accum(Bnd5* b);
};
struct S5_A
{
    void** vt;
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    S5_LArr<Obj5*> children;
};
struct S5_B
{
    void** vt;
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
    S5_LArr<Obj5*> children;
};
struct S5_C
{
    void** vt;
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
    S5_List<Obj5*> list;
};
void __cdecl FUN_00b5b260(Obj5* obj, S5_C* a2, bool a3, S5_A* pA, S5_B* pB);
void __cdecl FUN_00b5c490(Obj5* obj, S5_C* a2, bool a3, S5_A* pA, S5_B* pB);
bool __cdecl CheckBoundAndChildren(Obj5* obj, S5_C* a2, Obj5** b, bool c);

// With flag set, filters child candidates by the object's bound, sorts matches, and calls CheckBoundAndChildren; otherwise dispatches based on Predicate().
// @fnv 0x00b5dac0
bool __cdecl FUN_00b5dac0(Obj5* obj, S5_C* apList, bool a3, bool abTestBound)
{
    if (obj == 0)
        return true;
    S5_A* pA = 0;
    S5_B* pB = 0;
    Obj5* a = obj->child;
    if (a != 0)
    {
        bool bIsTypeA = a->GetRtti() == (const void*)&DAT_01202828;
        if (bIsTypeA)
        {
            pA = (S5_A*)a;
        }
        bool bIsTypeB = false;
        if (!bIsTypeA)
        {
            bIsTypeB = a->GetRtti() == (const void*)&DAT_012030b8;
        }
        if (bIsTypeB)
        {
            pB = (S5_B*)a;
        }
    }
    if (abTestBound)
    {
        FUN_00aa54a0_s* ctx = ((MemMgr5*)&DAT_011f6238)->GetCtx();
        int count = 0;
        Bnd5* pBound = obj->bound;
        Bnd5 bound = *(pBound ? pBound : (Bnd5*)&DAT_011f4288);
        Obj5** out;
        if (pA != 0)
        {
            out = (Obj5**)ctx->Allocate((pA->children.GetAllocatedSize() + 1) * sizeof(Obj5*));
            for (unsigned int i = 0; i < pA->children.GetAllocatedSize(); i++)
            {
                Obj5* it = pA->children.GetAt(i);
                if (it == 0)
                    continue;
                if (a3 && it->id == 0xff)
                    continue;
                if (it->TestBound(&bound, it->GetKey(), 1.0f))
                {
                    out[count] = it;
                    count++;
                    it->Accum(&bound);
                }
            }
        }
        else if (pB != 0)
        {
            out = (Obj5**)ctx->Allocate((pB->children.GetAllocatedSize() + 1) * sizeof(Obj5*));
            for (unsigned int i = 0; i < pB->children.GetAllocatedSize(); i++)
            {
                Obj5* it = pB->children.GetAt(i);
                if (it == 0)
                    continue;
                if (a3 && it->id == 0xff)
                    continue;
                if (it->TestBound(&bound, it->GetKey(), 1.0f))
                {
                    out[count] = it;
                    count++;
                    it->Accum(&bound);
                }
            }
        }
        else
        {
            out = (Obj5**)ctx->Allocate((apList->list.GetSize() + 1) * sizeof(Obj5*));
            S5_Item<Obj5*>* pos = apList->list.GetHeadPos();
            while (pos)
            {
                Obj5* it = apList->list.GetNext(pos);
                if (it == 0)
                    continue;
                if (a3 && it->id == 0xff)
                    continue;
                if (it->TestBound(&bound, it->GetKey(), 1.0f))
                {
                    out[count] = it;
                    count++;
                    it->Accum(&bound);
                }
            }
        }
        if (count > 0)
            FUN_00ec6f20(out, count, 4, CompareFloatAtOffsetC);
        out[count] = 0;
        CheckBoundAndChildren(obj, apList, out, a3);
        ctx->Deallocate(out);
        return true;
    }
    else
    {
        if (obj->Predicate())
            FUN_00b5b260(obj, apList, a3, pA, pB);
        else
            FUN_00b5c490(obj, apList, a3, pA, pB);
        return true;
    }
}

namespace fnv_00b5ddf0 {
extern "C" void _ReadWriteBarrier();
struct ArrOps
{
    void FUN_00cb9930(unsigned*, unsigned*, unsigned);
};
struct FUN_00b5ddb0_self
{
    void FUN_00b5d180();
};
struct LocalLock
{
    unsigned owner, count;
    void Lock(char*);
    void unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern "C" LocalLock DAT_011f9ea0, DAT_011f9ec0;
struct LocalArray
{
    virtual void v0();
    virtual void** Allocate(unsigned);
    virtual void Free(void**);
    void** data;
    unsigned count, capacity;
    void FUN_00b5ade0(unsigned, bool);
    void clear()
    {
        if (data)
        {
            Free(data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
    unsigned find(void* p)
    {
        for (unsigned i = 0; i < count; i++)
            if (data && data[i] == p)
                return i;
        return ~0u;
    }
    __forceinline void remove(unsigned i)
    {
        if (i == ~0u)
            return;
        unsigned n = count;
        if (capacity > 1024)
        {
            if (n <= capacity - 2048)
                goto slow;
        }
        else
        {
            if (n <= capacity / 4)
                goto slow;
        }
        _ReadWriteBarrier();
        ((ArrOps*)this)->FUN_00cb9930((unsigned*)(data + i), (unsigned*)(data + i + 1), n - i - 1);
    done:
        --count;
        return;
    slow:
        unsigned cap = capacity > 2048 ? capacity - 1024 : capacity / 2;
        void** fresh = Allocate(cap);
        ((ArrOps*)this)->FUN_00cb9930((unsigned*)fresh, (unsigned*)data, i);
        ((ArrOps*)this)->FUN_00cb9930((unsigned*)(fresh + i), (unsigned*)(data + i + 1), count - 1);
        Free(data);
        data = fresh;
        capacity = cap;
        goto done;
    }
};
template <class T> struct LocalLink
{
    LocalLink* next;
    LocalLink* prev;
    T* item;
};
template <class T> T* const& nextItem(LocalLink<T>*& p)
{
    T* const& item = p->item;
    p = p->next;
    return item;
}
struct LocalObject
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    LocalArray geometryLinks;
    LocalArray lightLinks;
};
struct LocalLightData
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    LocalArray objects;
};
struct LocalLight
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    LocalLightData* data;
};
struct LocalGeometry
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    LocalLink<LocalLight>* lights;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    LocalArray objects;
};
struct LocalContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    LocalLink<LocalGeometry>* geometries;
};
struct LocalTarget
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > listA, listB, listC, listD, listE;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    LocalContext* context;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    bool dirty;
    void FUN_00b5ddf0(LocalContext*);
};
// When the context changes, clears five lists, removes geometry and light references from old-context objects, then stores the new context.
// @fnv 0x00b5ddf0
void LocalTarget::FUN_00b5ddf0(LocalContext* apContext)
{
    if (apContext != context)
    {
        DAT_011f9ea0.Lock(0);
        DAT_011f9ec0.Lock(0);
        dirty = false;
        listA.RemoveAll();
        listB.RemoveAll();
        listC.RemoveAll();
        listD.RemoveAll();
        listE.RemoveAll();
        if (context)
        {
            LocalLink<LocalGeometry>* geometryPos = context->geometries;
            while (geometryPos)
            {
                LocalGeometry* geometry = nextItem(geometryPos);
                if (geometry)
                {
                    for (unsigned i = 0; i < geometry->objects.count; i++)
                    {
                        LocalObject* obj = (LocalObject*)geometry->objects.data[i];
                        unsigned index = obj->geometryLinks.find(geometry);
                        if (index != ~0u)
                            obj->geometryLinks.FUN_00b5ade0(index, true);
                    }
                    geometry->objects.clear();
                    LocalLink<LocalLight>* lightPos = geometry->lights;
                    while (lightPos)
                    {
                        LocalLight* light = nextItem(lightPos);
                        if (light)
                        {
                            int n = (int)light->data->objects.count;
                            for (int j = 0; j < n; j++)
                            {
                                LocalArray* links = &((LocalObject*)light->data->objects.data[j])->lightLinks;
                                unsigned index = links->find(light);
                                if (index != ~0u)
                                    links->remove(index);
                            }
                            light->data->objects.clear();
                        }
                    }
                }
            }
        }
        dirty = true;
        DAT_011f9ea0.unlock();
        DAT_011f9ec0.unlock();
        ((FUN_00b5ddb0_self*)this)->FUN_00b5d180();
    }
    context = apContext;
}
}  // namespace fnv_00b5ddf0

namespace fnv_00b5b260 {
class FourComponentFloatVector
{
  public:
    NiPoint3 center;
    float radius;
};

extern FourComponentFloatVector DAT_011f4288;
struct S00b5b260_Geom;
struct S00b5b260_Light : public ShadowSceneLight
{
    bool FUN_00b9dae0(FourComponentFloatVector*, ShadowLightFlags*, float);
    void AddGeometry(S00b5b260_Geom*);
};

class BSShaderProperty : public NiProperty
{
  public:
    unsigned short unk18, unk1a;

    unsigned int shaderType;
};

class BSShaderLightingProperty : public BSShaderProperty
{
  public:
    void FUN_00b718b0();

    void RemoveItemsAfterPos(S00b5b260_Geom*);
};

struct S00b5b260_Geom
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    FourComponentFloatVector* worldBound;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int flags;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    BSShaderProperty* shader;
};

struct LightOwnerA
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    unsigned int unk088;

    unsigned int unk08c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    unsigned int unk0b8;

    unsigned int unk0bc;

    unsigned int unk0c0;

    unsigned int unk0c4;

    unsigned int unk0c8;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned int unk0d8;

    unsigned int unk0dc;

    S00b5b260_Light** lights;
    unsigned int count;
};

struct LightOwnerB
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    unsigned int unk088;

    unsigned int unk08c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    S00b5b260_Light** lights;
    unsigned int count;
};

struct SceneGraph
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    unsigned int unk088;

    unsigned int unk08c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    unsigned int unk0b8;

    unsigned int unk0bc;

    unsigned int unk0c0;

    unsigned int unk0c4;

    unsigned int unk0c8;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned int unk0d8;

    unsigned int unk0dc;

    unsigned int unk0e0;

    unsigned int unk0e4;

    unsigned int unk0e8;

    unsigned int unk0ec;

    unsigned int unk0f0;

    unsigned int unk0f4;

    unsigned int unk0f8;

    unsigned int unk0fc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    unsigned int unk13c;

    unsigned int unk140;

    unsigned int unk144;

    unsigned int unk148;

    unsigned int unk14c;

    unsigned int unk150;

    unsigned int unk154;

    unsigned int unk158;

    unsigned int unk15c;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16c;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17c;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18c;

    unsigned int unk190;

    ShadowSceneNode* scene;
};

SceneGraph* FUN_00b4f5c0();

extern ShadowSceneNode* DAT_011f91c8;

static inline BSShaderProperty* AsShader(BSShaderProperty* p)
{
    return p->shaderType != ~0u ? p : 0;
}
static inline int IsLightingType(BSShaderProperty* p)
{
    unsigned int t = p->shaderType;
    return t >= 1 && t <= 12;
}
static inline BSShaderLightingProperty* AsLighting(BSShaderProperty* p)
{
    return IsLightingType(p) ? static_cast<BSShaderLightingProperty*>(p) : 0;
}
static inline ShadowSceneLight* GetNext(ShadowListItem*& pos)
{
    ShadowSceneLight*& result = pos->light;
    pos = pos->next;
    return result;
}
static inline void S00b5b260_Apply(S00b5b260_Light* light, FourComponentFloatVector* bound, S00b5b260_Geom* geom)
{
    if (light)
    {
        ShadowLightFlags* data = light->lightData;
        if (light->FUN_00b9dae0(bound, data, 1.0f))
            light->AddGeometry(geom);
    }
}
// @fnv 0x00b5b260
bool FUN_00b5b260(S00b5b260_Geom* geom, ShadowSceneNode* scene, void* unused, LightOwnerA* ownerA, LightOwnerB* ownerB)
{
    BSShaderProperty* pShader = geom->shader;
    if (pShader)
    {
        BSShaderProperty* shader = AsShader(pShader);
        BSShaderLightingProperty* lighting = 0;
        if (shader)
            lighting = AsLighting(shader);
        if (!lighting)
            return false;
        if (!scene)
        {
            scene = FUN_00b4f5c0()->scene;
            if (!scene)
                scene = DAT_011f91c8;
        }
        lighting->FUN_00b718b0();
        FourComponentFloatVector* bound = geom->worldBound;
        if (!bound)
            bound = &DAT_011f4288;
        FourComponentFloatVector boundCopy = *bound;
        if (ownerA)
        {
            for (unsigned int i = 0; i < ownerA->count; ++i)
            {
                S00b5b260_Apply(ownerA->lights[i], &boundCopy, geom);
            }
        }
        else if (ownerB)
        {
            for (unsigned int i = 0; i < ownerB->count; ++i)
            {
                S00b5b260_Apply(ownerB->lights[i], &boundCopy, geom);
            }
        }
        else
        {
            ShadowListItem* pos = scene->lights.head;
            while (pos)
            {
                S00b5b260_Apply((S00b5b260_Light*)GetNext(pos), &boundCopy, geom);
            }
        }
        lighting->RemoveItemsAfterPos(geom);
        geom->flags |= 0x400000;
        return true;
    }
    return true;
}
}  // namespace fnv_00b5b260

extern const double _gModifierZero;
inline float maximum(float a, float b)
{
    return a > b ? a : b;
}
struct WeightVec
{
    float x, y, z;
    __declspec(noalias) void FUN_004a0c10();
    WeightVec operator*(float s) const
    {
        WeightVec r;
        r.x = x * s;
        r.y = y * s;
        r.z = z * s;
        return r;
    }
    float Dot(const WeightVec& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
};
struct WeightLight
{
    float Evaluate(WeightVec, WeightVec, int);
};
struct WeightLink
{
    WeightLink* next;
    int previous;
    WeightLight* item;
};
struct WeightData
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
    int unkc0;
    int unkc4;
    WeightVec ambient;
    WeightVec diffuse;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    WeightVec direction;
};
struct WeightOwner
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    WeightData* data;
};
struct WeightScene
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
    WeightLink* head;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    WeightOwner* owner;
    float FUN_00b5b610(WeightVec position, int* count, float* ambient, float* diffuse, WeightVec target, int flags);
};
// Sums light contributions, adds ambient and diffuse terms, and returns the total weighted lighting value at a position.
// @fnv 0x00b5b610
float WeightScene::FUN_00b5b610(WeightVec position, int* count, float* ambient, float* diffuse, WeightVec target,
                                int flags)
{
    float total = 0.0f;
    float previous = 0.0f;
    *count = 0;
    WeightLink* node = head;
    while (node)
    {
        WeightLight*& light = node->item;
        node = node->next;
        if (light)
        {
            total += light->Evaluate(position, target, flags);
            if (total > previous)
            {
                ++*count;
                previous = total;
            }
        }
    }
    WeightData* data = owner->data;
    WeightVec* __restrict pAmbient = &data->ambient;
    WeightVec color = *pAmbient;
    float value = maximum(color.x, maximum(color.y, color.z));
    *ambient = value;
    total += value * 0.25;
    WeightVec direction = data->direction;
    WeightVec* __restrict pDiffuse = &data->diffuse;
    color = *pDiffuse;
    value = maximum(color.x, maximum(color.y, color.z));
    *diffuse = value;
    color.x = target.x - position.x;
    color.y = target.y - position.y;
    color.z = target.z - position.z;
    color.FUN_004a0c10();
    direction.FUN_004a0c10();
    target = color * 0.75f;
    float factor = target.Dot(direction);
    factor += 0.25;
    float clamped = 1.0f < factor ? 1.0f : factor;
    factor = clamped < _gModifierZero ? 0.0 : clamped;
    factor = 1.0 - factor;
    return factor * value + total;
}

// Reference-taking argument wrapper: the constructor adds a reference; the caller drops it after the call.
template <class T> class S5c6e0_RefArg
{
  public:
    S5c6e0_RefArg(T* p) : m_p(p)
    {
        if (p)
            p->IncRefCount();
    }
    ~S5c6e0_RefArg()
    {
        m_p = m_p;
    }
    T* m_p;
};

template <class T> class S5c6e0_PointerList
{
  public:
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;

    const T& GetNext(void*& pos) const
    {
        NiTListItem<T>* pkItem = static_cast<NiTListItem<T>*>(pos);
        const T& element = pkItem->m_element;
        pos = pkItem->m_pkNext;
        return element;
    }

    void* FindPos(const T& element, void* pos = 0) const
    {
        if (pos == 0)
            pos = m_pkHead;
        while (pos)
        {
            void* savePos = pos;
            if (element == GetNext(pos))
                return savePos;
        }
        return 0;
    }

    void FUN_00a5a310(const S5c6e0_RefArg<NiRefObject>& element);  // AddTail
};

class S5c6e0_Owner
{
  public:
    unsigned int unk00;
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
    S5c6e0_PointerList<NiPointer<NiRefObject> > m_kList;

    void FUN_00b5c6e0(NiRefObject* pkObject);
};

// @fnv 0x00b5c6e0
void S5c6e0_Owner::FUN_00b5c6e0(NiRefObject* pkObject)
{
    if (!m_kList.FindPos(pkObject))
    {
        m_kList.FUN_00a5a310(pkObject);
        if (pkObject)
            pkObject->DecRefCount();
    }
}

namespace fnv_00b5c940 {
class NiRTTIStub
{
  public:
    const char* m_pcName;
    const NiRTTIStub* m_pBaseRTTI;
};

extern NiRTTIStub g_kDirLightRTTI;    // 0x011f4a68
extern NiRTTIStub g_kPointLightRTTI;  // 0x011f4a98

class NiLightObj : public NiObject
{
  public:
    virtual const NiRTTIStub* GetRTTI() const;

    bool IsExactKindOf(const NiRTTIStub* pkRTTI) const
    {
        return GetRTTI() == pkRTTI;
    }
    static bool IsExactKindOf(const NiRTTIStub* pkRTTI, const NiLightObj* pkObject)
    {
        if (!pkObject)
            return false;
        return pkObject->IsExactKindOf(pkRTTI);
    }
};

class LightCS
{
  public:
    unsigned int m_uiThreadID;
    unsigned int m_uiEnterCount;
    void Enter(const char* pcName);
    void Leave()
    {
        if (--m_uiEnterCount == 0)
            m_uiThreadID = 0;
    }
};

extern LightCS g_kShadowLightCS;  // 0x011f9ea0

void* AllocObject(unsigned int uiSize);

class SSLight : public NiObject
{
  public:
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
    unsigned int m_uiUnkF8;
    bool m_bFlagFC;
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
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    unsigned int m_uiUnk240;
    int unk244;
    int unk248;
    int unk24C;

    static void* operator new(unsigned int uiSize)
    {
        return AllocObject(uiSize);
    }
    static void operator delete(void*, unsigned int);
    SSLight();
    void SetLight(NiLightObj* pkLight);
};

template <class T> class SSListItem
{
  public:
    SSListItem* m_pkNext;
    SSListItem* m_pkPrev;
    T m_element;
};

template <class T> class SSPointerList
{
  public:
    __declspec(noinline) void FUN_00a5a310(const T& element)
    {
        SSListItem<T>* pkNode = new SSListItem<T>;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_uiCount++;
    }
    SSListItem<T>* m_pkHead;
    SSListItem<T>* m_pkTail;
    unsigned int m_uiCount;
};

class SSNode
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
    SSPointerList<NiPointer<SSLight> > m_kLights;
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
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    unsigned int m_uiUnk1E0;

    SSLight* FUN_00b5c940(NiLightObj* pkLight, bool bFlag);
};

// Validates pkLight is a directional or point light, creates an SSLight, stores bFlag, adds it to m_kLights, and returns the new SSLight.
// @fnv 0x00b5c940
SSLight* SSNode::FUN_00b5c940(NiLightObj* pkLight, bool bFlag)
{
    if (!NiLightObj::IsExactKindOf(&g_kDirLightRTTI, pkLight) &&
        !NiLightObj::IsExactKindOf(&g_kPointLightRTTI, pkLight))
        return 0;

    g_kShadowLightCS.Enter(0);
    SSLight* pkSSLight = new SSLight;
    pkSSLight->SetLight(pkLight);
    pkSSLight->m_bFlagFC = bFlag;
    m_kLights.FUN_00a5a310(pkSSLight);
    pkSSLight->m_uiUnk240 = m_uiUnk1E0;
    g_kShadowLightCS.Leave();
    return pkSSLight;
}
}  // namespace fnv_00b5c940

namespace fnv_00b5cbd0 {
struct GlobalObject_0096a2d0
{
    unsigned int m_pOwnerObject;
    unsigned int m_uiItemCount;
    void Lock(const char* = 0);
    void Unlock()
    {
        if (--m_uiItemCount == 0)
            m_pOwnerObject = 0;
    }
};
extern "C" GlobalObject_0096a2d0 DAT_011f9ea0;
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
struct LightEx;

struct LightEx : public NiRefObject
{
    char body[0x250 - 8];
    LightEx();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    void FUN_00b9bb10(float, int);
    void FUN_00b5af30(void* key);
    void SetShadowEnabled(bool);
};

struct ActiveLightList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiRefObject> >
{
    NiTListItem<NiPointer<NiRefObject> >* NewItem();
    void FUN_00a5a310(const NiPointer<NiRefObject>& element);
};

void ActiveLightList::FUN_00a5a310(const NiPointer<NiRefObject>& element)
{
    NiTListItem<NiPointer<NiRefObject> >* node = NewItem();
    node->m_element = element;
    node->m_pkNext = 0;
    node->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = node;
    else
        m_pkHead = node;
    m_pkTail = node;
    m_kItemCount.m_uiCount++;
}

struct ShadowSceneNode_Self : public ShadowSceneNode
{
    ActiveLightList m_activeLights;  // at offset 0xe4
    LightEx* FUN_00b5cbd0(void* key);
};

// Finds a shadow light matching key in shadowLights, clears its flag and returns it, or creates a new LightEx, adds it to m_activeLights, and returns it.
// @fnv 0x00b5cbd0
LightEx* ShadowSceneNode_Self::FUN_00b5cbd0(void* key)
{
    ShadowListItem* pos = shadowLights.head;
    while (pos)
    {
        ShadowSceneLight* const& ref = pos->light;
        pos = pos->next;
        LightEx* light = (LightEx*)ref;
        if (light && *(void**)((char*)light + 0x128) == key)
        {
            ShadowLightFlags* flags = *(ShadowLightFlags**)((char*)light + 0xf8);
            flags->flags &= 0xfffffffe;
            light->FUN_00b9bb10(1.0f, 0);
            return light;
        }
    }

    DAT_011f9ea0.Lock(0);
    LightEx* light = new LightEx;
    light->FUN_00b5af30(key);
    light->SetShadowEnabled(true);
    m_activeLights.FUN_00a5a310(NiPointer<NiRefObject>(light));
    DAT_011f9ea0.Unlock();
    return light;
}
}  // namespace fnv_00b5cbd0

extern unsigned int DAT_011c16bc;
void* __cdecl FUN_00aa13e0(unsigned int size);
void __cdecl FUN_00aa1460(void* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

class S00b5cd00_Light
{
  public:
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa1460(p);
    }
    S00b5cd00_Light();

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
    unsigned int m_flags;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
};

class S00b5cd00_Param
{
  public:
    virtual void vf00();
    virtual void DeleteThis();

    long m_iObjectReferenceCount;

    void FUN_00b9dda0(S00b5cd00_Light* light);
    void SetShadowEnabled(bool value);
};

// Reference-taking argument wrapper: the constructor adds a reference; the caller drops it after the call.
template <class T> class S00b5cd00_Ptr
{
  public:
    S00b5cd00_Ptr(T* p) : m_p(p)
    {
        InterlockedIncrement(&p->m_iObjectReferenceCount);
    }
    ~S00b5cd00_Ptr()
    {
        m_p = m_p;
    }
    T* m_p;
};

class S00b5cd00_List
{
  public:
    void FUN_00a5a310(const S00b5cd00_Ptr<S00b5cd00_Param>& item);
};

class S00b5cd00_Owner
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
    S00b5cd00_List m_kNode;
    S00b5cd00_Param* FUN_00b5cd00(S00b5cd00_Param* param);
};

// @fnv 0x00b5cd00
S00b5cd00_Param* S00b5cd00_Owner::FUN_00b5cd00(S00b5cd00_Param* param)
{
    reinterpret_cast<unsigned char*>(param)[0xFC] = 1;
    S00b5cd00_Light* light = new S00b5cd00_Light;
    light->m_flags &= ~1u;
    param->FUN_00b9dda0(light);
    param->SetShadowEnabled(true);
    reinterpret_cast<unsigned char*>(param)[0xED] = 0;
    m_kNode.FUN_00a5a310(param);
    if (InterlockedDecrement(&param->m_iObjectReferenceCount) == 0)
        param->DeleteThis();
    return param;
}

extern float DAT_011ad834;

struct MyShadowSceneLight
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
    float m_fD8;
    float m_fDC;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    ShadowLightFlags* lightData;
};

struct MyShadowListItem
{
    MyShadowListItem* next;
    MyShadowListItem* prev;
    MyShadowSceneLight* light;
};

struct MyShadowList
{
    MyShadowListItem* head;
    MyShadowListItem* tail;
    unsigned int count;
    void FUN_00c1b4a0(void* pRef);
    void MoveNodeBefore(MyShadowListItem* a, MyShadowListItem* b);
    void MoveBefore(MyShadowListItem* a, MyShadowListItem* b);
};

struct SSN_cand
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
    MyShadowList shadowLights;
    unsigned int unknownCC;
    MyShadowListItem* m_pD0;
    MyShadowListItem* m_pD4;
    void* m_spD8;
    void* m_spDC;

    void FUN_00b5cde0(MyShadowSceneLight* a2);
};

// Reorders shadow light list nodes by comparing m_fD8 and m_fDC against thresholds and DAT_011ad834, moving nodes before m_pD0 or m_pD4.
// @fnv 0x00b5cde0
void SSN_cand::FUN_00b5cde0(MyShadowSceneLight* apLight)
{
    MyShadowList* pShadowList = &shadowLights;

    if (!m_pD4)
    {
        pShadowList->FUN_00c1b4a0(&m_spDC);
        m_pD4 = pShadowList->head;
    }
    else
    {
        pShadowList->MoveNodeBefore(m_pD4, pShadowList->head);
    }

    if (!m_pD0)
    {
        pShadowList->FUN_00c1b4a0(&m_spD8);
        m_pD0 = pShadowList->head;
    }
    else
    {
        pShadowList->MoveNodeBefore(m_pD0, pShadowList->head);
    }

    if (!m_pD4)
        return;

    MyShadowListItem* cur = m_pD4->next;
    while (cur)
    {
        MyShadowListItem* node = cur;
        MyShadowSceneLight*& light = cur->light;
        cur = cur->next;

        if (!light)
            continue;

        if (light->m_fD8 <= 0.100000001490116119384765625 && light->m_fDC < DAT_011ad834)
        {
            MyShadowListItem* d0 = m_pD0;
            if (node != d0)
            {
                if (pShadowList->head == node)
                    pShadowList->head = node->next;
                if (pShadowList->head == d0)
                    pShadowList->head = node;
                if (pShadowList->tail == node)
                    pShadowList->tail = node->prev;
                if (node->next)
                    node->next->prev = node->prev;
                if (node->prev)
                    node->prev->next = node->next;
                node->prev = d0->prev;
                node->next = d0;
                if (node->prev)
                    node->prev->next = node;
                d0->prev = node;
            }
            continue;
        }

        if (light->m_fD8 >= 0.89999997615814208984375 && light->m_fDC < DAT_011ad834)
        {
            float val = (light->m_fD8 > 0.0f) ? light->m_fDC / DAT_011ad834 : 1.0f - light->m_fDC / DAT_011ad834;
            if (val > 0.100000001490116119384765625)
            {
                pShadowList->MoveBefore(node, m_pD0);
                continue;
            }
        }

        if (!(light->lightData->flags & 1))
        {
            if (!(light->m_fD8 >= 0.89999997615814208984375 && light->m_fDC < DAT_011ad834))
            {
                if (light == apLight)
                {
                    pShadowList->MoveNodeBefore(node, m_pD4);
                }
                else
                {
                    pShadowList->MoveBefore(node, m_pD4);
                }
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);

extern unsigned int DAT_011c16bc;

struct S00b5d9f0_Lock
{
    unsigned int m_pOwnerObject;
    int m_uiItemCount;

    void __thiscall Lock(int spin);
};

extern S00b5d9f0_Lock DAT_011f9ec0;
extern int DAT_011f9ec4;

class S00b5d9f0_Obj
{
  public:
    virtual void vf00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

struct S00b5d9f0_Temp
{
    S00b5d9f0_Obj* m_p;

    S00b5d9f0_Temp(S00b5d9f0_Obj* p) : m_p(p)
    {
        InterlockedIncrement(&p->m_iObjectReferenceCount);
    }

    ~S00b5d9f0_Temp()
    {
        m_p = m_p;
    }
};

struct S00b5d9f0_List
{
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_00a5a310(const S00b5d9f0_Temp& item);
};

struct S00b5d9f0_Owner
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    S00b5d9f0_List m_list108;
    S00b5d9f0_List m_list114;

    void FUN_00b5d9f0(S00b5d9f0_Obj* obj, unsigned char flag);
};

// Adds obj to m_list108 or m_list114 based on flag, then decrements obj's reference count and deletes it if zero.
// @fnv 0x00b5d9f0
void S00b5d9f0_Owner::FUN_00b5d9f0(S00b5d9f0_Obj* obj, unsigned char flag)
{
    if (obj == 0)
        return;

    DAT_011f9ec0.Lock(0);

    switch (!flag)
    {
    default:
        m_list108.FUN_00a5a310(S00b5d9f0_Temp(obj));
        break;
    case 0:
        m_list114.FUN_00a5a310(S00b5d9f0_Temp(obj));
        break;
    }

    if (InterlockedDecrement(&obj->m_iObjectReferenceCount) == 0)
        obj->DeleteThis();

    --DAT_011f9ec4;
    if (DAT_011f9ec4 == 0)
        DAT_011f9ec0.m_pOwnerObject = 0;
}

namespace fnv_00b5e870 {
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();

void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* Addend);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);

class NiCullingProcess;

struct Obj4
{

    int m_00;

    int m_04;
};

class Item : public NiRefObject
{

  public:
    float m_reserve08_0;
    float m_reserve08_1;
    float m_reserve08_2;
    float m_reserve08_3;
    float m_reserve08_4;
    float m_reserve08_5;
    float m_reserve08_6;
    float m_reserve08_7;

    float m_reserve08_8;
    float m_reserve08_9;
    float m_reserve08_10;
    float m_reserve08_11;
    float m_reserve08_12;
    float m_reserve08_13;
    float m_reserve08_14;
    float m_reserve08_15;

    float m_reserve08_16;
    float m_reserve08_17;
    float m_reserve08_18;
    float m_reserve08_19;
    float m_reserve08_20;
    float m_reserve08_21;
    float m_reserve08_22;
    float m_reserve08_23;

    float m_reserve08_24;
    float m_reserve08_25;
    float m_reserve08_26;
    float m_reserve08_27;
    float m_reserve08_28;
    float m_reserve08_29;
    float m_reserve08_30;
    float m_reserve08_31;

    float m_reserve08_32;
    float m_reserve08_33;
    float m_reserve08_34;
    float m_reserve08_35;
    float m_reserve08_36;
    float m_reserve08_37;
    float m_reserve08_38;
    float m_reserve08_39;

    float m_reserve08_40;
    float m_reserve08_41;
    float m_reserve08_42;
    float m_reserve08_43;
    float m_reserve08_44;
    float m_reserve08_45;
    float m_reserve08_46;
    float m_reserve08_47;

    float m_reserve08_48;
    float m_reserve08_49;
    float m_reserve08_50;
    float m_reserve08_51;
    float m_reserve08_52;
    float m_reserve08_53;
    float m_reserve08_54;
    float m_reserve08_55;

    float m_reserve08_56;

    char m_flagEC;

    char m_reserveED_0;
    char m_reserveED_1;
    char m_reserveED_2;
    char m_reserveED_3;
    char m_reserveED_4;
    char m_reserveED_5;
    char m_reserveED_6;
    char m_reserveED_7;

    char m_reserveED_8;
    char m_reserveED_9;
    char m_reserveED_10;

    Obj4* m_f8;

    char m_flagFC;

    char unkFD, unkFE, unkFF;
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
    unsigned int unk20C;
    unsigned int unk210;
    struct GeometryLinks** objects;
    unsigned int objectCount;
    unsigned int unk21C;
    unsigned int unk220;
    struct LinkedLight** linkedLights;
    unsigned int linkedLightCount;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;

    int m_240;

    void FUN_00b9e970(void* arg);
};

typedef NiPointer<Item> RefPtr_b9fcc0;
struct FirstOwner
{
    Item* m_pObject;
    FirstOwner(Item* p) : m_pObject(p)
    {
        if (p)
            p->IncRefCount();
    }
    ~FirstOwner()
    {
        Item* p = m_pObject;
        _ReadWriteBarrier();
        if (p)
            p->DecRefCount();
    }
};

struct Node
{

    Node* m_next;

    Node* m_pSecondNode;

    RefPtr_b9fcc0 m_light;
};

class List_b9fcc0
{

  public:
    Node* m_pFirstNode;

    Node* m_pTail;

    unsigned int m_uiItemCount;
    RefPtr_b9fcc0& GetNext(void*& pos)
    {
        RefPtr_b9fcc0& result = static_cast<Node*>(pos)->m_light;
        pos = static_cast<Node*>(pos)->m_next;
        return result;
    }

    RefPtr_b9fcc0 FUN_00b9fcc0(const FirstOwner& r);

    __declspec(noinline) RefPtr_b9fcc0 FUN_00b9efa0(void*& p);
    RefPtr_b9fcc0 PopFront();
    RefPtr_b9fcc0 PopBack();
    void ReleaseRefCountedNode(Node* node);
};

struct Vec3f
{
    float x, y, z;
};

struct MatObj
{

    float m_reserve00_0;
    float m_reserve00_1;
    float m_reserve00_2;
    float m_reserve00_3;
    float m_reserve00_4;
    float m_reserve00_5;
    float m_reserve00_6;
    float m_reserve00_7;

    float m_reserve00_8;
    float m_reserve00_9;
    float m_reserve00_10;
    float m_reserve00_11;
    float m_reserve00_12;
    float m_reserve00_13;
    float m_reserve00_14;
    float m_reserve00_15;

    float m_reserve00_16;
    float m_reserve00_17;
    float m_reserve00_18;
    float m_reserve00_19;
    float m_reserve00_20;
    float m_reserve00_21;
    float m_reserve00_22;
    float m_reserve00_23;

    float m_reserve00_24;
    float m_reserve00_25;

    float m_68;

    float m_6c;

    float m_70;

    float m_74;

    float m_78;

    float m_7c;

    float m_80;

    float m_84;

    float m_88;

    Vec3f m_vContactPosition;
};

class ParamObj
{

  public:
    void FUN_00c4f360();

    int m_00;

    int m_04;

    int m_08;

    MatObj* m_0c;
};

struct Obj134
{

    float m_reserve00_0;
    float m_reserve00_1;
    float m_reserve00_2;
    float m_reserve00_3;
    float m_reserve00_4;
    float m_reserve00_5;
    float m_reserve00_6;
    float m_reserve00_7;

    Vec3f m_kDiffuseColor;

    float m_2c;

    float m_30;

    float m_reserve34_0;
    float m_reserve34_1;
    float m_reserve34_2;
    float m_reserve34_3;
    float m_reserve34_4;
    float m_reserve34_5;
    float m_reserve34_6;
    float m_reserve34_7;

    float m_reserve34_8;
    float m_reserve34_9;
    float m_reserve34_10;

    float m_60;
};

char __cdecl FUN_005bf7b0();

struct Vec4f
{

    float x, y, z;
    union
    {
        float w;
        unsigned bitsW;
    };
    Vec4f()
    {}
    void Set(const Vec3f& v, float fourth)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = fourth;
    }
};

extern int DAT_011f91c0;

extern unsigned char DAT_011f91c4;

extern void* DAT_011f917c;

extern unsigned char DAT_011f91a7;

extern int DAT_011ad868;

extern int DAT_011f91d8;

extern float DAT_011ad824;

extern Vec4f DAT_011fa2a0;

extern Vec4f DAT_011fa2b0;

extern Vec4f DAT_011fa2c0;

extern Vec4f DAT_011fa280;

extern Vec4f DAT_011fa290;

extern float DAT_01200504;

extern float DAT_01200500;

extern float DAT_01200558;

struct LinkArray
{
    virtual void v0();
    unsigned int* data;
    unsigned int count, capacity;
    unsigned int FindFirstMatch(const RefPtr_b9fcc0*, unsigned int, int(__cdecl*)(int*, int*));
    void FUN_00b5ade0(unsigned int, bool);
};
struct GeometryLinks
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    LinkArray objects;
};
struct LinkedLightData
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    LinkArray links;
};
struct LinkedLight
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    LinkedLightData* data;
};
struct LightContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int count;
};
extern int __cdecl FUN_00b5a980(int*, int*);

class Self
{

  public:
    char m_reserve00_0;
    char m_reserve00_1;
    char m_reserve00_2;
    char m_reserve00_3;
    char m_reserve00_4;
    char m_reserve00_5;
    char m_reserve00_6;
    char m_reserve00_7;

    char m_reserve00_8;
    char m_reserve00_9;
    char m_reserve00_10;
    char m_reserve00_11;
    char m_reserve00_12;
    char m_reserve00_13;
    char m_reserve00_14;
    char m_reserve00_15;

    char m_reserve00_16;
    char m_reserve00_17;
    char m_reserve00_18;
    char m_reserve00_19;
    char m_reserve00_20;
    char m_reserve00_21;
    char m_reserve00_22;
    char m_reserve00_23;

    char m_reserve00_24;
    char m_reserve00_25;
    char m_reserve00_26;
    char m_reserve00_27;
    char m_reserve00_28;
    char m_reserve00_29;
    char m_reserve00_30;
    char m_reserve00_31;

    char m_reserve00_32;
    char m_reserve00_33;
    char m_reserve00_34;
    char m_reserve00_35;
    char m_reserve00_36;
    char m_reserve00_37;
    char m_reserve00_38;
    char m_reserve00_39;

    char m_reserve00_40;
    char m_reserve00_41;
    char m_reserve00_42;
    char m_reserve00_43;
    char m_reserve00_44;
    char m_reserve00_45;
    char m_reserve00_46;
    char m_reserve00_47;

    char m_reserve00_48;
    char m_reserve00_49;
    char m_reserve00_50;
    char m_reserve00_51;
    char m_reserve00_52;
    char m_reserve00_53;
    char m_reserve00_54;
    char m_reserve00_55;

    char m_reserve00_56;
    char m_reserve00_57;
    char m_reserve00_58;
    char m_reserve00_59;
    char m_reserve00_60;
    char m_reserve00_61;
    char m_reserve00_62;
    char m_reserve00_63;

    char m_reserve00_64;
    char m_reserve00_65;
    char m_reserve00_66;
    char m_reserve00_67;
    char m_reserve00_68;
    char m_reserve00_69;
    char m_reserve00_70;
    char m_reserve00_71;

    char m_reserve00_72;
    char m_reserve00_73;
    char m_reserve00_74;
    char m_reserve00_75;
    char m_reserve00_76;
    char m_reserve00_77;
    char m_reserve00_78;
    char m_reserve00_79;

    char m_reserve00_80;
    char m_reserve00_81;
    char m_reserve00_82;
    char m_reserve00_83;
    char m_reserve00_84;
    char m_reserve00_85;
    char m_reserve00_86;
    char m_reserve00_87;

    char m_reserve00_88;
    char m_reserve00_89;
    char m_reserve00_90;
    char m_reserve00_91;
    char m_reserve00_92;
    char m_reserve00_93;
    char m_reserve00_94;
    char m_reserve00_95;

    char m_reserve00_96;
    char m_reserve00_97;
    char m_reserve00_98;
    char m_reserve00_99;
    char m_reserve00_100;
    char m_reserve00_101;
    char m_reserve00_102;
    char m_reserve00_103;

    char m_reserve00_104;
    char m_reserve00_105;
    char m_reserve00_106;
    char m_reserve00_107;
    char m_reserve00_108;
    char m_reserve00_109;
    char m_reserve00_110;
    char m_reserve00_111;

    char m_reserve00_112;
    char m_reserve00_113;
    char m_reserve00_114;
    char m_reserve00_115;
    char m_reserve00_116;
    char m_reserve00_117;
    char m_reserve00_118;
    char m_reserve00_119;

    char m_reserve00_120;
    char m_reserve00_121;
    char m_reserve00_122;
    char m_reserve00_123;
    char m_reserve00_124;
    char m_reserve00_125;
    char m_reserve00_126;
    char m_reserve00_127;

    char m_reserve00_128;
    char m_reserve00_129;
    char m_reserve00_130;
    char m_reserve00_131;
    char m_reserve00_132;
    char m_reserve00_133;
    char m_reserve00_134;
    char m_reserve00_135;

    char m_reserve00_136;
    char m_reserve00_137;
    char m_reserve00_138;
    char m_reserve00_139;
    char m_reserve00_140;
    char m_reserve00_141;
    char m_reserve00_142;
    char m_reserve00_143;

    char m_reserve00_144;
    char m_reserve00_145;
    char m_reserve00_146;
    char m_reserve00_147;
    char m_reserve00_148;
    char m_reserve00_149;
    char m_reserve00_150;
    char m_reserve00_151;

    char m_reserve00_152;
    char m_reserve00_153;
    char m_reserve00_154;
    char m_reserve00_155;
    char m_reserve00_156;
    char m_reserve00_157;
    char m_reserve00_158;
    char m_reserve00_159;

    char m_reserve00_160;
    char m_reserve00_161;
    char m_reserve00_162;
    char m_reserve00_163;
    char m_reserve00_164;
    char m_reserve00_165;
    char m_reserve00_166;
    char m_reserve00_167;

    char m_reserve00_168;
    char m_reserve00_169;
    char m_reserve00_170;
    char m_reserve00_171;
    char m_reserve00_172;
    char m_reserve00_173;
    char m_reserve00_174;
    char m_reserve00_175;

    char m_reserve00_176;
    char m_reserve00_177;
    char m_reserve00_178;
    char m_reserve00_179;

    List_b9fcc0 m_listB4;

    List_b9fcc0 m_listC0;

    char m_reserveCC_0;
    char m_reserveCC_1;
    char m_reserveCC_2;
    char m_reserveCC_3;
    char m_reserveCC_4;
    char m_reserveCC_5;
    char m_reserveCC_6;
    char m_reserveCC_7;

    char m_reserveCC_8;
    char m_reserveCC_9;
    char m_reserveCC_10;
    char m_reserveCC_11;
    char m_reserveCC_12;
    char m_reserveCC_13;
    char m_reserveCC_14;
    char m_reserveCC_15;

    char m_reserveCC_16;
    char m_reserveCC_17;
    char m_reserveCC_18;
    char m_reserveCC_19;
    char m_reserveCC_20;
    char m_reserveCC_21;
    char m_reserveCC_22;
    char m_reserveCC_23;

    char m_reserveCC_24;
    char m_reserveCC_25;
    char m_reserveCC_26;
    char m_reserveCC_27;
    char m_reserveCC_28;
    char m_reserveCC_29;
    char m_reserveCC_30;
    char m_reserveCC_31;

    char m_reserveCC_32;
    char m_reserveCC_33;
    char m_reserveCC_34;
    char m_reserveCC_35;
    char m_reserveCC_36;
    char m_reserveCC_37;
    char m_reserveCC_38;
    char m_reserveCC_39;

    char m_reserveCC_40;
    char m_reserveCC_41;
    char m_reserveCC_42;
    char m_reserveCC_43;
    char m_reserveCC_44;
    char m_reserveCC_45;
    char m_reserveCC_46;
    char m_reserveCC_47;

    char m_reserveCC_48;
    char m_reserveCC_49;
    char m_reserveCC_50;
    char m_reserveCC_51;
    char m_reserveCC_52;
    char m_reserveCC_53;
    char m_reserveCC_54;
    char m_reserveCC_55;

    char m_reserveCC_56;
    char m_reserveCC_57;
    char m_reserveCC_58;
    char m_reserveCC_59;
    char m_reserveCC_60;
    char m_reserveCC_61;
    char m_reserveCC_62;
    char m_reserveCC_63;

    char m_reserveCC_64;
    char m_reserveCC_65;
    char m_reserveCC_66;
    char m_reserveCC_67;
    char m_reserveCC_68;
    char m_reserveCC_69;
    char m_reserveCC_70;
    char m_reserveCC_71;

    char m_reserveCC_72;
    char m_reserveCC_73;
    char m_reserveCC_74;
    char m_reserveCC_75;
    char m_reserveCC_76;
    char m_reserveCC_77;
    char m_reserveCC_78;
    char m_reserveCC_79;

    char m_reserveCC_80;
    char m_reserveCC_81;
    char m_reserveCC_82;
    char m_reserveCC_83;

    char m_120;

    char m_reserve121_0;
    char m_reserve121_1;
    char m_reserve121_2;
    char m_reserve121_3;
    char m_reserve121_4;
    char m_reserve121_5;
    char m_reserve121_6;
    char m_reserve121_7;

    char m_reserve121_8;
    char m_reserve121_9;
    char m_reserve121_10;
    char m_reserve121_11;
    char m_reserve121_12;
    char m_reserve121_13;
    char m_reserve121_14;

    char m_130;

    char m_reserve131_0;
    char m_reserve131_1;
    char m_reserve131_2;

    Obj134* m_134;

    char m_reserve138_0;
    char m_reserve138_1;
    char m_reserve138_2;
    char m_reserve138_3;
    char m_reserve138_4;
    char m_reserve138_5;
    char m_reserve138_6;
    char m_reserve138_7;

    char m_reserve138_8;
    char m_reserve138_9;
    char m_reserve138_10;
    char m_reserve138_11;
    char m_reserve138_12;
    char m_reserve138_13;
    char m_reserve138_14;
    char m_reserve138_15;

    char m_reserve138_16;
    char m_reserve138_17;
    char m_reserve138_18;
    char m_reserve138_19;
    char m_reserve138_20;
    char m_reserve138_21;
    char m_reserve138_22;
    char m_reserve138_23;

    char m_reserve138_24;
    char m_reserve138_25;
    char m_reserve138_26;
    char m_reserve138_27;
    char m_reserve138_28;
    char m_reserve138_29;
    char m_reserve138_30;
    char m_reserve138_31;

    char m_reserve138_32;
    char m_reserve138_33;
    char m_reserve138_34;
    char m_reserve138_35;
    char m_reserve138_36;
    char m_reserve138_37;
    char m_reserve138_38;
    char m_reserve138_39;

    char m_reserve138_40;
    char m_reserve138_41;
    char m_reserve138_42;
    char m_reserve138_43;
    char m_reserve138_44;
    char m_reserve138_45;
    char m_reserve138_46;
    char m_reserve138_47;

    char m_reserve138_48;
    char m_reserve138_49;
    char m_reserve138_50;
    char m_reserve138_51;
    char m_reserve138_52;
    char m_reserve138_53;
    char m_reserve138_54;
    char m_reserve138_55;

    char m_reserve138_56;
    char m_reserve138_57;
    char m_reserve138_58;
    char m_reserve138_59;
    char m_reserve138_60;
    char m_reserve138_61;
    char m_reserve138_62;
    char m_reserve138_63;

    char m_reserve138_64;
    char m_reserve138_65;
    char m_reserve138_66;
    char m_reserve138_67;
    char m_reserve138_68;
    char m_reserve138_69;
    char m_reserve138_70;
    char m_reserve138_71;

    char m_reserve138_72;
    char m_reserve138_73;
    char m_reserve138_74;
    char m_reserve138_75;
    char m_reserve138_76;
    char m_reserve138_77;
    char m_reserve138_78;
    char m_reserve138_79;

    char m_reserve138_80;
    char m_reserve138_81;
    char m_reserve138_82;
    char m_reserve138_83;
    char m_reserve138_84;
    char m_reserve138_85;
    char m_reserve138_86;
    char m_reserve138_87;

    char m_reserve138_88;
    char m_reserve138_89;
    char m_reserve138_90;
    char m_reserve138_91;
    char m_reserve138_92;
    char m_reserve138_93;
    char m_reserve138_94;
    char m_reserve138_95;

    char m_reserve138_96;
    char m_reserve138_97;
    char m_reserve138_98;
    char m_reserve138_99;
    char m_reserve138_100;
    char m_reserve138_101;
    char m_reserve138_102;
    char m_reserve138_103;

    char m_reserve138_104;
    char m_reserve138_105;
    char m_reserve138_106;
    char m_reserve138_107;
    char m_reserve138_108;
    char m_reserve138_109;
    char m_reserve138_110;
    char m_reserve138_111;

    char m_reserve138_112;
    char m_reserve138_113;
    char m_reserve138_114;
    char m_reserve138_115;
    char m_reserve138_116;
    char m_reserve138_117;
    char m_reserve138_118;
    char m_reserve138_119;

    char m_reserve138_120;
    char m_reserve138_121;
    char m_reserve138_122;
    char m_reserve138_123;
    char m_reserve138_124;
    char m_reserve138_125;
    char m_reserve138_126;
    char m_reserve138_127;

    char m_reserve138_128;
    char m_reserve138_129;
    char m_reserve138_130;
    char m_reserve138_131;
    char m_reserve138_132;
    char m_reserve138_133;
    char m_reserve138_134;
    char m_reserve138_135;

    char m_reserve138_136;
    char m_reserve138_137;
    char m_reserve138_138;
    char m_reserve138_139;
    char m_reserve138_140;
    char m_reserve138_141;
    char m_reserve138_142;
    char m_reserve138_143;

    char m_reserve138_144;
    char m_reserve138_145;
    char m_reserve138_146;
    char m_reserve138_147;
    char m_reserve138_148;
    char m_reserve138_149;
    char m_reserve138_150;
    char m_reserve138_151;

    char m_reserve138_152;
    char m_reserve138_153;
    char m_reserve138_154;
    char m_reserve138_155;
    char m_reserve138_156;
    char m_reserve138_157;
    char m_reserve138_158;
    char m_reserve138_159;

    char m_reserve138_160;
    char m_reserve138_161;
    char m_reserve138_162;
    char m_reserve138_163;
    char m_reserve138_164;
    char m_reserve138_165;
    char m_reserve138_166;
    char m_reserve138_167;

    int m_1e0;

    __declspec(noinline) void RemoveLightFromNode(RefPtr_b9fcc0& a, void*& b);

    void FUN_00b5d270(Item* item);

    unsigned int FUN_00a5dbe0(void* p);

    unsigned int FUN_00b5e870(ParamObj* arg);
};

__declspec(noinline) RefPtr_b9fcc0 List_b9fcc0::FUN_00b9efa0(void*& p)
{
    Node* node = static_cast<Node*>(p);
    if (node == m_pFirstNode)
    {
        p = node->m_next;
        return PopFront();
    }
    if (node == m_pTail)
    {
        p = 0;
        return PopBack();
    }
    Node* previous = node->m_pSecondNode;
    Node* next = node->m_next;
    p = next;
    if (previous)
        previous->m_next = next;
    if (next)
        next->m_pSecondNode = previous;
    RefPtr_b9fcc0 item = node->m_light;
    ReleaseRefCountedNode(node);
    --m_uiItemCount;
    return item;
}

__declspec(noinline) void Self::RemoveLightFromNode(RefPtr_b9fcc0& value, void*& position)
{
    LightContext* context = reinterpret_cast<LightContext*>(m_1e0);
    Item* item = value;
    if (context && context->count)
    {
        for (unsigned int i = 0; i < item->objectCount; ++i)
        {
            GeometryLinks* geometry = item->objects[i];
            if (geometry && geometry->objects.count)
            {
                unsigned int index = geometry->objects.FindFirstMatch(&value, 0, FUN_00b5a980);
                if (index != ~0u)
                    geometry->objects.FUN_00b5ade0(index, true);
            }
            item = value;
        }
        for (unsigned int i = 0; i < item->linkedLightCount; ++i)
        {
            LinkedLight* light = item->linkedLights[i];
            if (light && light->data->links.count)
            {
                LinkedLightData* data = light->data;
                unsigned int index = ~0u;
                for (unsigned int j = 0; j < data->links.count; ++j)
                {
                    if (data->links.data && data->links.data[j] == reinterpret_cast<unsigned int>(item))
                    {
                        index = j;
                        break;
                    }
                }
                if (index != ~0u)
                    data->links.FUN_00b5ade0(index, true);
            }
            item = value;
        }
    }
    if (item->m_flagEC)
        m_listC0.FUN_00b9efa0(position);
    else
        m_listB4.FUN_00b9efa0(position);
}

// Processes entries in m_listB4, updates globals from arg and m_134, and returns a value derived from m_134 or FUN_00a5dbe0.
// @fnv 0x00b5e870
unsigned int Self::FUN_00b5e870(ParamObj* arg)

{

    arg->FUN_00c4f360();

    MatObj& own = *arg->m_0c;

    if (!m_130)
    {
        void* y = m_listB4.m_pFirstNode;
        while (y)
        {
            void* v = y;
            Item* idx = m_listB4.GetNext(y);
            if (idx)
            {
                if (idx->m_f8 && idx->m_f8->m_04 != 1)
                {
                    if (idx->m_flagFC)
                        FUN_00b5d270(idx);
                    if (!idx->m_flagEC || !FUN_005bf7b0())
                        idx->FUN_00b9e970(arg);
                }
                else
                {
                    int id = idx->m_240;
                    int c;
                    c = m_1e0;
                    if (id != c)
                    {
                        if (idx->m_flagEC)
                        {
                            FirstOwner q(idx);
                            m_listC0.FUN_00b9fcc0(q);
                        }
                        else
                        {
                            m_listB4.FUN_00b9efa0(v);
                        }
                    }
                    else
                    {
                        RefPtr_b9fcc0 q(idx);
                        RemoveLightFromNode(q, v);
                    }
                }
            }
        }
    }
    DAT_011f91c4 = (unsigned char)m_120;

    DAT_011f917c = &own;

    if (DAT_011f91c0 == 0)
    {

        return FUN_00a5dbe0(arg);
    }

    if (1 == DAT_011f91a7)
    {

        if (DAT_011ad868 == -1)

            DAT_011ad868 = DAT_011f91d8;

        DAT_011f91d8 = 4;
    }
    else
    {

        unsigned long pForm;

        pForm = DAT_011ad868;

        if (pForm != -1)
        {

            DAT_011f91d8 = pForm;

            DAT_011ad868 = -1;
        }
    }

    Vec3f ptr;
    ptr = own.m_vContactPosition;
    Vec4f n;
    n.Set(ptr, 0.0f);
    DAT_011fa2a0 = n;

    ptr.x = own.m_68;
    ptr.y = own.m_74;
    ptr.z = own.m_80;
    n.Set(ptr, 0.0f);
    DAT_011fa2b0 = n;

    ptr.x = own.m_70;
    ptr.y = own.m_7c;
    ptr.z = own.m_88;
    n.Set(ptr, 0.0f);
    DAT_011fa2c0 = n;

    Obj134* val;
    val = m_134;
    unsigned result = reinterpret_cast<unsigned>(val);
    if (val)
    {
        ptr = val->m_kDiffuseColor;
        float pObj;
        pObj = val->m_30;
        n.x = pObj;
        n.y = pObj - val->m_2c;
        n.z = val->m_60;
        n.w = 0.0f;
        DAT_011fa280 = n;
        n.Set(ptr, 0.0f);
        DAT_011fa290 = n;
        result = n.bitsW;
    }
    DAT_01200558 = DAT_01200500 + (DAT_01200504 - DAT_01200500) * DAT_011ad824;

    return result;
}
}  // namespace fnv_00b5e870

struct S00b5eca0_Ref
{
    virtual void vfn00();
    virtual void DeleteThis();
    long m_lRefCount;
};
struct S00b5eca0_Ptr
{
    ShadowSceneLight* const m_pObject;
    S00b5eca0_Ptr(ShadowSceneLight* p) : m_pObject(p)
    {
        InterlockedIncrement(&((S00b5eca0_Ref*)p)->m_lRefCount);
    }
    operator ShadowSceneLight*() const
    {
        return m_pObject;
    }
    ~S00b5eca0_Ptr()
    {
        if (InterlockedDecrement(&((S00b5eca0_Ref*)m_pObject)->m_lRefCount) == 0)
            ((S00b5eca0_Ref*)m_pObject)->DeleteThis();
    }
};
struct S00b5eca0_List
{
    ShadowListItem* head;
    ShadowListItem* tail;
    unsigned count;
    void FUN_00a5a310(const S00b5eca0_Ptr& sp);
};
ShadowListItem* S00b5eca0_NewItem();
__declspec(noinline) void S00b5eca0_List::FUN_00a5a310(const S00b5eca0_Ptr& sp)
{
    ShadowListItem* pkItem = S00b5eca0_NewItem();
    pkItem->light = sp.m_pObject;
    pkItem->next = 0;
    pkItem->prev = tail;
    if (tail)
        tail->next = pkItem;
    else
        head = pkItem;
    tail = pkItem;
    count++;
}
struct S00b5eca0_Group
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void SetBuffer(void* pkBuffer);
};
struct S00b5eca0_Tex
{
    S00b5eca0_Group* FUN_00b6b260();
};
struct S00b5eca0_Mgr
{
    S00b5eca0_Tex* FUN_00b6e110(void* pkRenderer, int iType, int a, int b, int c);
    void* FUN_00b6d120();
    S00b5eca0_Tex* ActivatePending();
};
class NiRenderer;
extern NiRenderer* DAT_011f9508;
struct S00b5eca0_Settings
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    char unkec;
    bool m_bUseRenderedShadows;
};
struct S00b5eca0_Light
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    bool m_bCastShadows;
    char unked;
    short unkee;
    int unkf0;
    int unkf4;
    ShadowLightFlags* lightData;
    char m_cFC;
    void AssignRefObject(S00b5eca0_Tex* pkTexture);
};
struct S00b5eca0_Node : public ShadowSceneNode
{
    void FUN_00b5d300(ShadowSceneLight*);
    ShadowSceneLight* FUN_00b5eca0(ShadowSceneLight* pkLight);
};

// Adds pkLight to the lights list, assigning a shadow texture if it casts shadows, and returns an existing light with the same lightData or null.
// @fnv 0x00b5eca0
ShadowSceneLight* S00b5eca0_Node::FUN_00b5eca0(ShadowSceneLight* pkLight)
{
    S00b5eca0_Light* pkL = (S00b5eca0_Light*)pkLight;
    ShadowListItem* pkIter = lights.head;
    ShadowLightFlags* pkData = pkLight->lightData;
    while (pkIter)
    {
        ShadowSceneLight*& rkExisting = pkIter->light;
        pkIter = pkIter->next;
        ShadowSceneLight* pkExisting = rkExisting;
        if (pkExisting && pkExisting->lightData == pkData)
        {
            ((S00b5eca0_Light*)pkExisting)->m_cFC = pkL->m_cFC;
            FUN_00b5d300(pkExisting);
            return pkExisting;
        }
    }
    ((S00b5eca0_List*)&lights)->FUN_00a5a310(pkLight);

    if (pkL->m_bCastShadows)
    {
        S00b5eca0_Tex* pkTexture;
        if (((S00b5eca0_Settings*)0)->m_bUseRenderedShadows)
        {
            pkTexture = ((S00b5eca0_Mgr*)DAT_011f91a8)->FUN_00b6e110(DAT_011f9508, 0x2a, 0, 0, 0);
            pkTexture->FUN_00b6b260()->SetBuffer(((S00b5eca0_Mgr*)DAT_011f91a8)->FUN_00b6d120());
        }
        else
        {
            pkTexture = ((S00b5eca0_Mgr*)DAT_011f91a8)->ActivatePending();
        }
        pkL->AssignRefObject(pkTexture);
    }
    FUN_00b5d300(pkLight);
    return 0;
}

namespace fnv_00b5f9b0 {
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct CullProcess;
struct CullObject;
struct CullObject
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
    virtual void Cull(CullProcess*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int flags;
    void FUN_00a59e00(CullProcess*);
};
struct CullEntry;
struct CullLightNode
{
    CullLightNode* next;
    CullLightNode* prev;
    CullEntry* item;
};
struct CullLightList
{
    CullLightNode* head;
    CullLightNode* tail;
    unsigned count;
    CullEntry*& GetNext(CullLightNode*& pos)
    {
        CullEntry*& item = pos->item;
        pos = pos->next;
        return item;
    }
};
struct CullEntry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    CullObject* object;
};
struct CullGroupNode
{
    CullGroupNode* next;
    CullGroupNode* prev;
    struct CullGroup* item;
};
struct CullGroupList
{
    CullGroupNode* head;
    CullGroupNode* tail;
    unsigned count;
    unsigned unknown;
    CullGroup*& GetNext(CullGroupNode*& pos)
    {
        CullGroup*& item = pos->item;
        pos = pos->next;
        return item;
    }
};
struct CullGroup : CullObject
{
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    CullLightList lights;
};
struct CullProcess
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* camera;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    int mode;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int state;
    bool FUN_00c4f320(CullObject*);
};
struct CullManager
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    CullLightList lights;
    CullGroupList groups20;
    CullGroupList groups30;
    unsigned int unk40, unk44, unk48;
    CullObject* extra;
    unsigned int FUN_00c5b5d0();
    CullObject* FUN_00c5b5a0(unsigned int);
};
struct CullScratch
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    void FUN_00c47660();
    void FUN_00c47770();
    CullScratch()
    {
        FUN_00c47660();
    }
    ~CullScratch()
    {
        FUN_00c47770();
    }
};
struct CullHeap
{
    void* FUN_00aa54a0(unsigned int, unsigned int);
    void FUN_00aa5610(void*);
};
struct CullMemoryManager
{
    CullHeap* FUN_00aa42e0();
};
extern CullMemoryManager DAT_011f6238;
extern unsigned int DAT_010a2720;
NiRefObject* FUN_00b4f5c0();
struct SceneCull
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    CullObject** children;
    unsigned short capacity, count;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    bool special;
    CullManager* manager;
    void FUN_00b5e870(CullProcess*);
    void FUN_00a5dbe0(CullProcess*);
    void FUN_00b5ba80(void*, CullEntry*);
    void FUN_00b5f9b0(CullProcess* process);
};
// Culls scene objects and lights by iterating group lists and calling Cull on visible entries, using a saved flags buffer to track state changes.
// @fnv 0x00b5f9b0
void SceneCull::FUN_00b5f9b0(CullProcess* process)
{
    FUN_00b5e870(process);
    NiPointer<NiRefObject> context(FUN_00b4f5c0());
    unsigned int rc = context->m_uiRefCount;
    if (rc == 1)
        context->IncRefCount();
    if (manager)
    {
        CullHeap* heap = DAT_011f6238.FUN_00aa42e0();
        bool* pSavedFlags = 0;
        if (manager->FUN_00c5b5d0() > 0)
        {
            pSavedFlags = (bool*)heap->FUN_00aa54a0(manager->FUN_00c5b5d0(), DAT_010a2720);
            FUN_00ec61c0(pSavedFlags, 0, manager->FUN_00c5b5d0());
        }
        for (unsigned int i = 0; i < manager->FUN_00c5b5d0(); ++i)
        {
            CullObject* object = manager->FUN_00c5b5a0(i);
            if (object)
            {
                pSavedFlags[i] = (bool)(object->flags & 1);
                object->flags |= 1;
            }
        }
        {
            CullObject* extra = manager->extra;
            if (extra)
                extra->flags |= 1;
        }
        if (!special && process->mode != 1 && process->mode != 3)
        {
            CullGroupNode* pos = manager->groups30.head;
            while (pos)
            {
                CullGroup* group = manager->groups30.GetNext(pos);
                if (group)
                {
                    group->Cull(process);
                    if (group->lights.count)
                    {
                        CullLightNode* pLightNode = group->lights.head;
                        while (pLightNode)
                        {
                            CullEntry* entry = group->lights.GetNext(pLightNode);
                            if (entry)
                            {
                                CullObject* object = entry->object;
                                if (process->FUN_00c4f320(object))
                                {
                                    void* camera = process->camera;
                                    FUN_00b5ba80(camera, entry);
                                    entry->object->Cull(process);
                                }
                            }
                        }
                    }
                    process->state = 0;
                }
            }
            for (unsigned int i = 4; i < count; ++i)
            {
                CullObject* object = children[i];
                if (object)
                    object->FUN_00a59e00(process);
            }
        }
        else
        {
            FUN_00a5dbe0(process);
            CullGroupList* list = &manager->groups30;
            if (process->mode == 1 || process->mode == 3)
                list = &manager->groups20;
            CullGroupNode* pos = list->head;
            CullScratch scratch;
            while (pos)
            {
                CullGroup* group = list->GetNext(pos);
                CullLightList* lights = group ? &group->lights : &manager->lights;
                if (lights->count)
                {
                    CullLightNode* pLightNode = lights->head;
                    while (pLightNode)
                    {
                        CullEntry* entry = lights->GetNext(pLightNode);
                        if (entry)
                        {
                            CullObject* object = entry->object;
                            if (process->FUN_00c4f320(object))
                                entry->object->Cull(process);
                        }
                    }
                }
                process->state = 0;
            }
        }
        for (unsigned int i = 0; i < manager->FUN_00c5b5d0(); ++i)
        {
            CullObject* object = manager->FUN_00c5b5a0(i);
            if (object && !pSavedFlags[i])
            {
                object->flags &= ~1;
                object->FUN_00a59e00(process);
            }
        }
        {
            CullObject* extra = manager->extra;
            if (extra)
                extra->flags &= ~1;
        }
        heap->FUN_00aa5610(pSavedFlags);
    }
    else
    {
        FUN_00a5dbe0(process);
    }
}
}  // namespace fnv_00b5f9b0

#include <math.h>
struct LightObj
{
    virtual void v0();
    virtual void v1();
    virtual void* GetRTTI();
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    NiPoint3 pos;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    float radius;
};
struct Globals
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    void* unk1B0;
    void* unk1B4;
    void* unk1B8;
    void* unk1BC;
    void* unk1C0;
    void* unk1C4;
    void* unk1C8;
    void* unk1CC;
    void* unk1D0;
    void* unk1D4;
    void* unk1D8;
    void* unk1DC;
    void* unk1E0;
    NiPoint3 g;
};
extern Globals* DAT_011f91c8;
extern char DAT_011f4a68[];
struct FUN_00b9dae0_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    LightObj* defLight;
    bool FUN_00b9dae0(NiPoint3* p, LightObj* l, float scale);
};
// Uses defLight when l is null, returns true for matching RTTI, otherwise compares an adjusted distance with l->radius.
// @fnv 0x00b9dae0
bool FUN_00b9dae0_cls::FUN_00b9dae0(NiPoint3* apPoint, LightObj* apLight, float scale)
{
    if (!apLight)
        apLight = defLight;
    if (apLight->GetRTTI() == (void*)DAT_011f4a68)
        return true;
    NiPoint3 d;
    d.x = apLight->pos.x - apPoint->x;
    d.y = apLight->pos.y - apPoint->y;
    d.z = apLight->pos.z - apPoint->z;
    NiPoint3 g = DAT_011f91c8->g;
    NiPoint3 s;
    s.x = g.x + d.x;
    s.y = g.y + d.y;
    s.z = g.z + d.z;
    float len = (float)sqrt((double)s.Dot(s));
    float v = len - apPoint[1].x * scale;
    if (v < apLight->radius)
        return true;
    return false;
}

namespace fnv_00b5b410 {
struct Sub2
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    int unk1c;
    void FUN_00b718b0();
    void RemoveItemsAfterPos(void*);
};

struct Sub1
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    Sub2* unk0c;
};

struct Obj
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned int flags;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    Sub1 sub1;
};

struct Light
{
    void AddGeometry(void*);
};

inline int valid(Sub2* q)
{
    switch (q->unk1c)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return 1;
    default:
        return 0;
    }
}

// @fnv 0x00b5b410
bool __cdecl FUN_00b5b410(Obj* pObj, void* apUnused, Light** apLights, bool abUnused)
{
    Sub1* pSub1 = &pObj->sub1;
    if (pSub1)
    {
        Sub2* pSub2 = pSub1->unk0c;
        if (pSub2)
        {
            Sub2* p = (pSub2->unk1c != -1) ? pSub2 : 0;
            if (!p)
                goto fail;
            p = valid(p) ? p : 0;
            if (!p)
                goto fail;

            p->FUN_00b718b0();
            for (int i = 0; apLights[i]; ++i)
            {
                if (apLights[i])
                {
                    apLights[i]->AddGeometry(pObj);
                }
            }
            p->RemoveItemsAfterPos(pObj);
            pObj->flags |= 0x400000;
            return true;

        fail:
            return false;
        }
    }
    return true;
}
}  // namespace fnv_00b5b410

namespace fnv_00b5d300 {
struct Pt3
{
    int x, y, z;
};
struct Pt4
{
    Pt3 pt;
    float w;
    __forceinline Pt4(const Pt3& a_pt, float a_w)
    {
        pt = a_pt;
        w = a_w;
    }
};

int __cdecl FUN_00b5a980(int*, int*);

template <class T> struct ArrayLikeT
{
    void* vptr;
    T* data;
    unsigned int count;
    int f0c;
    int FindFirstMatch(const T* key, int zero, int(__cdecl* cb)(int*, int*));
    unsigned int FUN_00b5c360();
    unsigned int FUN_00761540();

    __forceinline int Find(const T& key)
    {
        return FindFirstMatch(&key, 0, FUN_00b5a980);
    }

    __forceinline void Clear()
    {
        if (data)
        {
            void** vt = *(void***)this;
            void(__thiscall * fn)(void*, void*) = (void(__thiscall*)(void*, void*))vt[2];
            fn(this, data);
            data = 0;
            f0c = 0;
            count = 0;
        }
    }

    __forceinline unsigned int FindIdx(T val)
    {
        unsigned int i = 0;
        if (count > 0)
        {
            T* d = data;
            do
            {
                if (d && d[i] == val)
                    return i;
                i++;
            } while (i < count);
        }
        return (unsigned int)-1;
    }

    __forceinline void Add(const T& val)
    {
        unsigned int ni = FUN_00b5c360();
        data[ni] = val;
    }

    __forceinline void Add76(T val)
    {
        unsigned int ni = FUN_00761540();
        data[ni] = val;
    }
};

class FUN_00b5aea0_self
{
  public:
    void RemoveRange(unsigned int, unsigned int);
};
class FUN_00b9fba0_s
{
  public:
    void FUN_00b9fba0();
};
class FUN_00c5b5d0_class
{
  public:
    unsigned int FUN_00c5b5d0();
};
class FUN_00c5b5a0_cls
{
  public:
    int FUN_00c5b5a0(int);
};

struct LightData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    char flag30;
    char unk31, unk32, unk33;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    Pt3 pt;
    int unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    float f_c4;
    int unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    float f_e0;
};

struct OwnerD;
struct Coll;
struct ItemObj;
struct OwnerObj;
struct LightD
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4;
    LightData* m_f8;
    int unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c;
    ArrayLikeT<ItemObj*> arr210;
    ArrayLikeT<ItemObj*> arr220;
    ArrayLikeT<OwnerObj*> arr230;
    Coll* m_240;
    void FUN_00b9ef30();
    void FUN_00ba0110(void* p);
    void FUN_00ba02b0();
};

struct OwnerObj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    ArrayLikeT<LightD*> arr;
};

struct Node
{
    Node* next;
    int f04;
    ItemObj* data;
};

struct PtrList
{
    Node* head;
    Node* tail;
    int count;
    inline ItemObj*& GetNext(Node*& pos) const
    {
        ItemObj*& elt = pos->data;
        pos = pos->next;
        return elt;
    }
};

struct VirtObj
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual char v45(Pt3*);
};
struct Holder
{
    int unk00, unk04, unk08;
    VirtObj* m_0c;
};

struct ItemObj
{
    virtual void vfn00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual int v68(Pt4*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    Holder* m_ac;
    int f_b0;
    PtrList listB4;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    ArrayLikeT<LightD*> mapDc;
    int unkec, unkf0, unkf4, unkf8, unkfc, unk100;
    OwnerObj* m_104;
};

struct Coll
{
    int unk00, unk04, unk08, unk0c, unk10;
    PtrList list14;
    PtrList list20;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    void** arr6c;
    unsigned int count70;
};

class ElemObj
{
  public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void* vfn3();
};
struct GetterObj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int f_18;
};

class OwnerD
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    ElemObj** m_a0;
    short padA4;
    unsigned short m_a6;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    Coll* m_1e0;
    void FUN_00b5d300(LightD* p);
};

extern OwnerD* DAT_011f91c8;

// Updates p's arrays using entries from m_1e0 or m_a0, adding or removing entries based on virtual checks.
// @fnv 0x00b5d300
void OwnerD::FUN_00b5d300(LightD* apLight)
{
    LightData* ld = apLight->m_f8;
    if ((ld->flag30 & 1) || ld->f_c4 < (double)0.05f)
    {
        apLight->FUN_00b9ef30();
        return;
    }
    apLight->m_240 = m_1e0;
    ((FUN_00b9fba0_s*)apLight)->FUN_00b9fba0();
    unsigned int uiIndex = 0;
    if (m_1e0 && m_1e0->list20.count)
    {
        apLight->arr210.Clear();
        apLight->arr220.Clear();
        apLight->arr230.Clear();
        LightData* pLightData2 = apLight->m_f8;
        Pt3 ptPos;
        ptPos.x = pLightData2->pt.x;
        ptPos.y = pLightData2->pt.y;
        ptPos.z = pLightData2->pt.z;
        Pt4 pt4Pos(ptPos, apLight->m_f8->f_e0);
        Node* node = m_1e0->list20.head;
        while (node)
        {
            ItemObj* item = m_1e0->list20.GetNext(node);
            if (!item)
                continue;
            int idx = item->mapDc.Find(apLight);
            if (!item->m_ac->m_0c->v45(&ptPos) && !item->v68(&pt4Pos))
            {
                if (idx != -1)
                {
                    ((FUN_00b5aea0_self*)&item->mapDc)->RemoveRange(idx, 1);
                    Node* pSubNode = item->listB4.head;
                    while (pSubNode)
                    {
                        ItemObj* pSubItem = item->listB4.GetNext(pSubNode);
                        if (pSubItem && apLight->arr220.Find(pSubItem) == -1)
                        {
                            OwnerObj* pOwner = pSubItem->m_104;
                            int iOwnerIndex = pOwner->arr.Find(apLight);
                            if (iOwnerIndex != -1)
                            {
                                ((FUN_00b5aea0_self*)&pSubItem->m_104->arr)->RemoveRange(iOwnerIndex, 1);
                            }
                        }
                    }
                }
            }
            else
            {
                if (idx == -1)
                {
                    item->mapDc.Add(apLight);
                }
                Node* fn = item->listB4.head;
                while (fn)
                {
                    ItemObj* pSubItem = item->listB4.GetNext(fn);
                    if (pSubItem)
                    {
                        if (pSubItem->m_104->arr.FindIdx(apLight) == (unsigned int)-1)
                        {
                            pSubItem->m_104->arr.Add(apLight);
                        }
                        OwnerObj* pOwner = pSubItem->m_104;
                        if (apLight->arr230.FindIdx(pOwner) == (unsigned int)-1)
                        {
                            apLight->FUN_00ba0110(pOwner);
                            apLight->arr230.Add76(pSubItem->m_104);
                        }
                        if (apLight->arr220.FindIdx(pSubItem) == (unsigned int)-1)
                        {
                            apLight->arr220.Add(pSubItem);
                        }
                    }
                }
                apLight->FUN_00ba0110(item);
                apLight->arr210.Add(item);
            }
        }
        for (unsigned int i = 0; i < m_1e0->count70; i++)
        {
            apLight->FUN_00ba0110(m_1e0->arr6c[i]);
        }
        Node* fn = m_1e0->list14.head;
        while (fn)
        {
            ItemObj* pSubItem = m_1e0->list14.GetNext(fn);
            if (pSubItem)
            {
                if (pSubItem->m_104->arr.FindIdx(apLight) == (unsigned int)-1)
                {
                    pSubItem->m_104->arr.Add(apLight);
                }
                OwnerObj* pOwner = pSubItem->m_104;
                if (apLight->arr230.FindIdx(pOwner) == (unsigned int)-1)
                {
                    apLight->FUN_00ba0110(pOwner);
                    apLight->arr230.Add76(pSubItem->m_104);
                }
                if (apLight->arr220.FindIdx(pSubItem) == (unsigned int)-1)
                {
                    apLight->arr220.Add(pSubItem);
                }
            }
        }
        for (unsigned int i = 0; i < ((FUN_00c5b5d0_class*)m_1e0)->FUN_00c5b5d0(); i++)
        {
            void* pElement = (void*)((FUN_00c5b5a0_cls*)m_1e0)->FUN_00c5b5a0(i);
            if (pElement)
                apLight->FUN_00ba0110(pElement);
        }
    }
    else
    {
        if (this != DAT_011f91c8)
        {
            for (; uiIndex < m_a6; uiIndex++)
            {
                ElemObj* e = m_a0[uiIndex];
                if (e)
                {
                    void* r = e->vfn3();
                    if (r)
                        apLight->FUN_00ba0110(r);
                }
            }
        }
        else
        {
            if (m_a6 > 3)
            {
                ElemObj* e = m_a0[3];
                if (e)
                {
                    void* r = e->vfn3();
                    if (r)
                        apLight->FUN_00ba0110(r);
                }
            }
            if (m_a6 > 6)
            {
                ElemObj* e = m_a0[6];
                if (e)
                {
                    void* r = e->vfn3();
                    if (r)
                        apLight->FUN_00ba0110(r);
                }
            }
        }
        if (m_1e0)
        {
            for (unsigned int i = 0; i < ((FUN_00c5b5d0_class*)m_1e0)->FUN_00c5b5d0(); i++)
            {
                GetterObj* pElement = (GetterObj*)((FUN_00c5b5a0_cls*)m_1e0)->FUN_00c5b5a0(i);
                if (pElement && pElement->f_18 == 0)
                    apLight->FUN_00ba0110(pElement);
            }
        }
    }
    apLight->FUN_00ba02b0();
}
}  // namespace fnv_00b5d300

inline float Larger(float a, float b)
{
    return a > b ? a : b;
}

inline NiPoint3 NiPoint3::operator*(float f) const
{
    NiPoint3 r = {x * f, y * f, z * f};
    return r;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 r = {x - p.x, y - p.y, z - p.z};
    return r;
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    NiPoint3 r = {x + p.x, y + p.y, z + p.z};
    return r;
}
struct Product
{
    float x, y, z;
    Product(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};
inline Product ScaleProduct(const NiPoint3& p, float f)
{
    return Product(p.x * f, p.y * f, p.z * f);
}
inline void AddBlend(NiPoint3& a, const Product& b)
{
    a.x = b.x + a.x;
    a.y = a.y + b.y;
    a.z = a.z + b.z;
}
struct Factor
{
    float f;
};
struct BlendColor
{
    float x, y, z;
    BlendColor& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    __forceinline BlendColor operator*(float f) const
    {
        BlendColor r = *this;
        r.x *= f;
        r.y *= f;
        r.z *= f;
        return r;
    }
};
struct BlendData
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
    unsigned flags;
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
    NiPoint3 position;
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
    int unkc0;
    float scale;
    int unkc8;
    int unkcc;
    int unkd0;
    BlendColor diffuse;
    float radius;
    int unke4;
    int unke8;
    int unkec;
    NiPoint3 direction;
    float Dimmer() const
    {
        return scale;
    }
    const BlendColor& Diffuse() const
    {
        return diffuse;
    }
    __forceinline float Brightness() const
    {
        BlendColor c = diffuse * scale;
        return (c.x + c.y + c.z) / 3.0;
    }
};
struct BlendLight
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    BlendData* data;
};
struct BlendNode
{
    BlendNode* next;
    BlendNode* prev;
    BlendLight* light;
};
extern float DAT_011f9838[100];
extern float DAT_011f96a8[100];
struct BlendDirection : NiPoint3
{
    BlendDirection()
    {}
};
extern const double DAT_010228a0;
extern const double DAT_01012060;
inline BlendLight* const& NextLight(BlendNode*& pos)
{
    BlendLight* const& item = pos->light;
    pos = pos->next;
    return item;
}
extern unsigned DAT_011f9e78;
extern BlendDirection DAT_011f99c8[100];
struct BlendOwner
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
    BlendNode* head;
    BlendNode* tail;
    unsigned count;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    BlendLight* mainLight;
    __declspec(noinline) BlendLight* GetListItemAt(unsigned index);
    unsigned FUN_00b5bca0(const NiPoint3& point, const NiPoint3& normal, NiPoint3& result);
};
__declspec(noinline) BlendLight* BlendOwner::GetListItemAt(unsigned index)
{
    if (index >= count)
        return 0;
    BlendNode* node = head;
    BlendLight* light = NextLight(node);
    while (index > 0)
    {
        --index;
        light = NextLight(node);
    }
    return light;
}
// Computes a blended light position from point and normal, storing the result and returning whether any lights were used.
// @fnv 0x00b5bca0
unsigned BlendOwner::FUN_00b5bca0(const NiPoint3& point, const NiPoint3& normal, NiPoint3& result)
{
    BlendData* mainData = mainLight->data;
    unsigned used = 0;
    NiPoint3 direction = NiPoint3::ZERO;
    if (mainData->Brightness() > DAT_010228a0)
    {
        NiPoint3 tmp;
        tmp.x = -mainData->direction.x;
        tmp.y = -mainData->direction.y;
        tmp.z = -mainData->direction.z;
        tmp.Unitize();
        direction = tmp * 1000.0;
        used = 1;
    }
    else
    {
        if (!(DAT_011f9e78 & 1))
            DAT_011f9e78 |= 1;
        NiPoint3 zero = NiPoint3::ZERO;
        float maximum = Larger(Larger(zero.x, zero.y), zero.z);
        int positive = 0;
        float total = 0.0f;
        unsigned index = 0;
        BlendLight* light = GetListItemAt(0);
        while (light)
        {
            if (used >= 100)
                break;
            BlendData* data = light->data;
            if (!(data->flags & 1))
            {
                NiPoint3 delta = data->position - point;
                NiPoint3 unit = delta;
                unit.Unitize();
                float dot = normal.x * unit.x + normal.y * unit.y + normal.z * unit.z;
                if (dot < 0.0f)
                    dot = 0.0f;
                float luminance = light->data->Brightness();
                float lengthSquared = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
                float distance = sqrt(lengthSquared);
                float attenuation = 1.0f - (distance - maximum) / data->radius;
                float lower = attenuation < DAT_01012060 ? 0.0f : attenuation;
                float upper = 1.0 < lower ? 1.0f : lower;
                float weight = upper * dot * luminance;
                DAT_011f96a8[used] = DAT_011f9838[used] = weight;
                if (weight > 0.01f)
                    ++positive;
                total += weight;
                static_cast<NiPoint3&>(DAT_011f99c8[used]) = delta;
                ++used;
            }
            ++index;
            unsigned idx = (unsigned short)index;
            if (idx >= count)
                break;
            BlendNode* node = head;
            unsigned remaining = idx;
            BlendLight* item = NextLight(node);
            while (remaining > 0)
            {
                --remaining;
                item = NextLight(node);
            }
            light = item;
        }
        if (positive > 0)
        {
            for (unsigned i = 0; i < used; ++i)
            {
                float fraction = DAT_011f96a8[i] / total;
                if (fraction > 0.0f)
                    AddBlend(direction, ScaleProduct(DAT_011f99c8[i], fraction));
            }
        }
        else
        {
            const NiPoint3& source = mainLight->data->direction;
            NiPoint3 tmp;
            tmp.x = -source.x;
            tmp.y = -source.y;
            tmp.z = -source.z;
            tmp.Unitize();
            direction = tmp * 1000.0;
            used = 1;
        }
    }
    result = point + direction;
    return used > 0;
}

class ShadowDtorTextureManager
{
  public:
    void FUN_00b6da10(BSRenderedTexture*);
};

extern void __cdecl FUN_00b4f2f0(int, ShadowSceneNode*);

struct ShadowDtorContext
{
    int unkCtx_000;
    int unkCtx_004;
    int unkCtx_008;
    int unkCtx_00c;
    int unkCtx_010;
    int unkCtx_014;
    int unkCtx_018;
    int unkCtx_01c;
    int unkCtx_020;
    int unkCtx_024;
    int unkCtx_028;
    int unkCtx_02c;
    int unkCtx_030;
    int unkCtx_034;
    int unkCtx_038;
    int unkCtx_03c;
    int unkCtx_040;
    int unkCtx_044;
    int unkCtx_048;
    int unkCtx_04c;
    int unkCtx_050;
    int unkCtx_054;
    int unkCtx_058;
    int unkCtx_05c;
    int unkCtx_060;
    int unkCtx_064;
    int unkCtx_068;
    int unkCtx_06c;
    int unkCtx_070;
    int unkCtx_074;
    int unkCtx_078;
    int unkCtx_07c;
    int unkCtx_080;
    int unkCtx_084;
    int unkCtx_088;
    int unkCtx_08c;
    int unkCtx_090;
    int unkCtx_094;
    int unkCtx_098;
    int unkCtx_09c;
    int unkCtx_0a0;
    int unkCtx_0a4;
    int unkCtx_0a8;
    int unkCtx_0ac;
    int unkCtx_0b0;
    int unkCtx_0b4;
    int unkCtx_0b8;
    int unkCtx_0bc;
    int unkCtx_0c0;
    int unkCtx_0c4;
    int unkCtx_0c8;
    int unkCtx_0cc;
    int unkCtx_0d0;
    int unkCtx_0d4;
    int unkCtx_0d8;
    int unkCtx_0dc;
    int unkCtx_0e0;
    int unkCtx_0e4;
    int unkCtx_0e8;
    int unkCtx_0ec;
    int unkCtx_0f0;
    int unkCtx_0f4;
    int unkCtx_0f8;
    int unkCtx_0fc;
    int unkCtx_100;
    int unkCtx_104;
    int unkCtx_108;
    int unkCtx_10c;
    int unkCtx_110;
    int unkCtx_114;
    int unkCtx_118;
    int unkCtx_11c;
    int unkCtx_120;
    int unkCtx_124;
    int unkCtx_128;
    int unkCtx_12c;
    int unkCtx_130;
    int unkCtx_134;
    int unkCtx_138;
    int unkCtx_13c;
    int unkCtx_140;
    int unkCtx_144;
    int unkCtx_148;
    int unkCtx_14c;
    int unkCtx_150;
    int unkCtx_154;
    int unkCtx_158;
    int unkCtx_15c;
    int unkCtx_160;
    int unkCtx_164;
    int unkCtx_168;
    int unkCtx_16c;
    int unkCtx_170;
    int unkCtx_174;
    int unkCtx_178;
    int unkCtx_17c;
    int unkCtx_180;
    int unkCtx_184;
    int unkCtx_188;
    int unkCtx_18c;
    int unkCtx_190;
    void* unk194;
};
extern ShadowDtorContext* __cdecl FUN_00b4f5c0();

class ShadowDtorFrustum
{
  public:
    int unk00;
    void FUN_00c47770();
    ~ShadowDtorFrustum()
    {
        FUN_00c47770();
    }
};

class ShadowDtorCleanup
{
  public:
    void FUN_00b5d180();
};

struct ShadowDtorList : public ShadowList
{
    ~ShadowDtorList()
    {
        RemoveAll();
    }
};

class ShadowDtorTexture : public BSRenderedTexture
{
  public:
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};

class ShadowDtorLight : public ShadowSceneLight
{
  public:
    virtual ~ShadowDtorLight();
};

class FUN_00a5e930
{
  public:
    virtual ~FUN_00a5e930();
    int unkBase_004;
    int unkBase_008;
    int unkBase_00c;
    int unkBase_010;
    int unkBase_014;
    int unkBase_018;
    int unkBase_01c;
    int unkBase_020;
    int unkBase_024;
    int unkBase_028;
    int unkBase_02c;
    int unkBase_030;
    int unkBase_034;
    int unkBase_038;
    int unkBase_03c;
    int unkBase_040;
    int unkBase_044;
    int unkBase_048;
    int unkBase_04c;
    int unkBase_050;
    int unkBase_054;
    int unkBase_058;
    int unkBase_05c;
    int unkBase_060;
    int unkBase_064;
    int unkBase_068;
    int unkBase_06c;
    int unkBase_070;
    int unkBase_074;
    int unkBase_078;
    int unkBase_07c;
    int unkBase_080;
    int unkBase_084;
    int unkBase_088;
    int unkBase_08c;
    int unkBase_090;
    int unkBase_094;
    int unkBase_098;
    int unkBase_09c;
    int unkBase_0a0;
    int unkBase_0a4;
    int unkBase_0a8;
    int unkBase_0ac;
    int unkBase_0b0;
};

class FUN_00b5e5a0 : public FUN_00a5e930
{
  public:
    virtual ~FUN_00b5e5a0();

    ShadowDtorList unkB4;
    ShadowDtorList unkC0;
    int unkCC;
    int unkD0;
    int unkD4;
    NiPointer<NiRefObject> unkD8;
    NiPointer<NiRefObject> unkDC;
    ShadowDtorLight* unkE0;
    ShadowDtorList unkE4;
    ShadowDtorList unkF0;
    ShadowDtorList unkFC;
    ShadowDtorList unk108;
    ShadowDtorList unk114;
    unsigned char unk120;
    char unk121;
    char unk122;
    char unk123;
    NiPointer<ShadowDtorTexture> unk124;
    NiPointer<NiRefObject> unk128;
    int unk12C;
    int unk130;
    NiPointer<NiRefObject> unk134;
    ShadowDtorFrustum unk138;
    int unkPost_13c;
    int unkPost_140;
    int unkPost_144;
    int unkPost_148;
    int unkPost_14c;
    int unkPost_150;
    int unkPost_154;
    int unkPost_158;
    int unkPost_15c;
    int unkPost_160;
    int unkPost_164;
    int unkPost_168;
    int unkPost_16c;
    int unkPost_170;
    int unkPost_174;
    int unkPost_178;
    int unkPost_17c;
    int unkPost_180;
    int unkPost_184;
    int unkPost_188;
    int unkPost_18c;
    int unkPost_190;
    int unkPost_194;
    int unkPost_198;
    int unkPost_19c;
    int unkPost_1a0;
    int unkPost_1a4;
    int unkPost_1a8;
    int unkPost_1ac;
    int unkPost_1b0;
    int unkPost_1b4;
    int unkPost_1b8;
    int unkPost_1bc;
    int unkPost_1c0;
    int unkPost_1c4;
    int unkPost_1c8;
    int unkPost_1cc;
    int unkPost_1d0;
    int unkPost_1d4;
    int unkPost_1d8;
    int unkPost_1dc;
    int unk1E0;
};

FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkB4) == 0xb4);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkC0) == 0xc0);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkD8) == 0xd8);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkDC) == 0xdc);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkE0) == 0xe0);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkE4) == 0xe4);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkF0) == 0xf0);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unkFC) == 0xfc);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk108) == 0x108);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk114) == 0x114);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk120) == 0x120);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk124) == 0x124);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk128) == 0x128);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk134) == 0x134);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk138) == 0x138);
FNV_STATIC_ASSERT(offsetof(FUN_00b5e5a0, unk1E0) == 0x1e0);

// Destroys the shadow scene object, clearing its node, light, texture, and list references.
// @fnv 0x00b5e5a0
FUN_00b5e5a0::~FUN_00b5e5a0()
{
    ShadowSceneNode* node = ((ShadowSceneNode**)&DAT_011f91c8)[unk120];
    if (node == (ShadowSceneNode*)this)
    {
        FUN_00b4f2f0(unk120, 0);
    }
    if (FUN_00b4f5c0() && FUN_00b4f5c0()->unk194 == this)
    {
        FUN_00b4f5c0()->unk194 = 0;
    }
    ((ShadowDtorCleanup*)this)->FUN_00b5d180();
    unkD8 = 0;
    unkDC = 0;
    delete unkE0;
    if (unk124)
    {
        reinterpret_cast<ShadowDtorTextureManager*>(DAT_011f91a8)->FUN_00b6da10(unk124);
    }
    unk124 = 0;
    unkE4.RemoveAll();
    unkF0.RemoveAll();
    unkFC.RemoveAll();
    unk1E0 = 0;
    unk128 = 0;
}
