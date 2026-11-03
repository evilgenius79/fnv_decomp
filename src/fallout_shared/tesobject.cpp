// fallout_shared/tesobject.cpp: TESObject, TESBoundObject, SceneObjectLookup, TESFormList and more (81 functions)

#include "tesobject_decls.h"

// @fnv 0x0050fbe0
NiNode* TESObject::_CreateNiNode(TESObjectREFR* reference, bool arg1)
{
    return 0;
}

// @fnv 0x0050edd0
void TESBoundObject::LoadBoundData(TESFile* file)
{
    if (file && file->GetChunkID() == 0x444e424f)
    {
        file->GetChunkData(&bounds, 12);
        if (file->IsEndianConversionRequired())
            bounds.FUN_0050ed30();
    }
}

// @fnv 0x0050e820
TESBoundObject::TESBoundObject()
{
    bounds.FUN_0050e9c0();
    bounds.min.FUN_0050e8b0(GetActorValueShortVector());
    bounds.max.FUN_0050e8b0(GetActorValueShortVector());
}

// @fnv 0x005101e0
TESObject* TESFormList::InsertObjectAfter(TESObject* after, TESObject* object)
{
    if (this == (TESFormList*)g_dataHandler->GetNext())
        ((TESBoundObject*)object)->GetFormType();
    ((BGSDehydrationStage*)object)->FUN_0050f9a0((SpellItem*)after);
    if (after)
    {
        ((TESResponse*)object)->SetSpeakerIdle((TESIdleForm*)((TESObjectREFR*)after)->GetObjectReference());
        if (((TESObjectREFR*)after)->GetObjectReference())
            ((BGSDehydrationStage*)((TESObjectREFR*)after)->GetObjectReference())->FUN_0050f9a0((SpellItem*)object);
        ((TESResponse*)after)->SetSpeakerIdle((TESIdleForm*)object);
    }
    else
    {
        ((TESResponse*)object)->SetSpeakerIdle(0);
    }
    if (!FUN_00510360(object))
        m_pSecondObject = object;
    if (!GetTerrainMinLevel(object))
        m_pFirstObject = object;
    ++m_uiObjectCount;
    ((InterfaceManager*)object)->FUN_00984f60((unsigned int)this);
    return object;
}

// @fnv 0x0050f9e0
bool TESObject::HasLoaded3D()
{
    if (!this)
        return false;
    switch (GetFormType())
    {
    case 28:
        if ((TESObject*)DAT_011ca258 == this)
            return true;
        break;
    case 32:
        if ((TESObject*)DAT_011ca220 == this || (TESObject*)DAT_011ca250 == this || (TESObject*)DAT_011ca25c == this ||
            (TESObject*)DAT_011ca260 == this || (TESObject*)DAT_011ca254 == this || (TESObject*)DAT_011ca224 == this ||
            (TESObject*)DAT_011ca26c == this || (TESObject*)DAT_011ca244 == this || (TESObject*)DAT_011ca248 == this ||
            (TESObject*)DAT_011ca24c == this || (TESObject*)DAT_011ca230 == this || (TESObject*)DAT_011ca264 == this ||
            (TESObject*)DAT_011ca228 == this || (TESObject*)DAT_011ca22c == this)
            return true;
        break;
    case 21:
        if (!FUN_00404dc0(TESModel::GetModelFilePath(this), "EditorMarker.NIF"))
            return true;
        break;
    case 30:
        if (!TESModel::GetModelLength(this))
            return true;
        break;
    case 4:
    case 48:
        return true;
    }
    switch (((TESForm*)this)->GetFormID())
    {
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
        return true;
    }
    return false;
}

// @fnv 0x00605410
NiNode* TESCreature::Create3DModel(TESObjectREFR* reference)
{
    if (actorData.GetUsesLeveledTemplate() && reference && !reference->HasLeveledCreatureCalced())
    {
        actorData.SetTemplateReference(reference);
        return reference->GetObjectReference()->Create3DModel(reference);
    }
    NiNode* node = 0;
    if (reference)
    {
        BipedAnim* biped = reference->GetBipedAnim();
        node = Get3DObject(reference, false);
        if (biped)
        {
            if (SceneObjectLookup::GetObjectByName(node, "Bip01"))
            {
                biped->InitBoneSlots(node);
                node->UpdateSceneObject();
                NiUpdateData update(0.0f, false, false);
                node->Update(update);
            }
        }
        else if (SceneObjectLookup::GetObjectByName(node, "Bip01"))
        {
            biped = new BipedAnim(reference, node);
            reference->SetBipedAnim(biped);
            node->UpdateSceneObject();
            NiUpdateData update(0.0f, false, false);
            node->Update(update);
        }
    }
    return node;
}

// @fnv 0x00519040
NiNode* TESObjectDOOR::Create3DModel(TESObjectREFR* reference)
{
    NiNode* node = TESBoundObject::Create3DModel(reference);
    if (((TESChallenge*)this)->GetFormTwo() && !BSAudio::GetSingleton()->FUN_005bb4d0())
        BSAudio::GetSingleton()->Precache(((TESSound*)((TESChallenge*)this)->GetFormTwo())->FUN_00511840(), 0x121,
                                          ((TESChallenge*)this)->GetFormTwo());
    if (node)
    {
        NiTimeController* controller = node->GetController((const NiRTTI*)&g_011dfeac);
        if (FUN_00517fa0() && (!reference || !reference->FUN_00477ba0()))
        {
            if (!controller)
            {
                TESObjectDoorController* doorController = new TESObjectDoorController;
                doorController->FUN_00929240(
                    ((SettingT_GameSettingCollection_*)&originalRuntimeFloatSetting35)->Float()->f);
                ((BGSAcousticSpace*)doorController)->SetNoonSound((TESSound*)&TESObjectDOOR::UpdateDoorNode);
                doorController->SetTarget(node);
            }
            NiExtraData* extra = node->GetExtraData(FUN_00448a80());
            if (!extra)
            {
                extra = new NiExtraData;
                node->AddExtraData(FUN_00448a80(), extra);
            }
            extra->FUN_00519230(true, true);
        }
        else if (controller)
        {
            ((NiObjectNET*)node)->ReplaceControllers(controller);
        }
    }
    return node;
}

// Builds a NiNode from the reference's model, names it with the editor ID, applies scale, and returns the node or null.
// @fnv 0x0050d250
NiNode* TESObjectLIGH::Create3DModel(TESObjectREFR* reference)
{
    NiNode* node = 0;
    NiPointer<NiAVObject> empty(0);
    NiPointer<NiAVObject> source(CreateNiNode(reference));
    if (((NiPointer<NiNode>*)&source)->operator->())
    {
        unsigned int size = ((BGSCameraPath*)this)->HasNameForWarning() + 16;
        void* buffer = _alloca(size);
        if (!model.GetModelLength())
        {
            node = ((NiPointer<NiNode>*)&source)->operator->()->GetAsNiNode();
            if (node)
                node->SetName(NiFixedString(GetEditorID()));
        }
        if (((PlayerCharacter*)this)->FUN_0050d4a0() && reference)
            reference->FUN_00693ef0(true);
        float scale = 1.0f;
        if (reference)
            scale = ((PlayerCharacter*)reference)->GetScale();
        {
            CloningProcess process(scale);
            if (model.GetModelLength())
            {
                node = (NiNode*)((NiPointer<NiNode>*)&source)->operator->()->CloneObject(process);
            }
            else if (!node)
            {
                node = new BSFadeNode;
            }
            CreateLight(reference, node, false);
            node->UpdateSceneObject();
            return node;
        }
    }
    return 0;
}

namespace std {
template <class _Elem> struct char_traits;
template <class _Ty> class allocator;
template <class _Elem, class _Traits, class _Ax> class basic_string
{
  public:
    void _Tidy(bool, unsigned int);
};
}

// @fnv 0x0044a540
void __fastcall FUN_0044a540(std::basic_string<char, std::char_traits<char>, std::allocator<char> >* apString)
{
    apString->_Tidy(true, 0);
}

namespace fnv_0044a580 {
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
};
template <class C, class T, class A> class basic_string
{
  public:
    int pad0;
    char* Ptr;
    int pad1[4];
    unsigned int Res;
    void _Eos(unsigned int);
    bool _Grow(unsigned int, bool);
    char* _Myptr();
    void EraseRange(unsigned int, unsigned int);
};
}
struct AnimIdle
{
    int GetSection();
};
void FUN_00ec30e8();
extern unsigned int DAT_010173f0;
void __cdecl FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > Str;
struct FUN_0044a580_cls : public Str
{
    FUN_0044a580_cls* AssignSubstring(Str& _Right, unsigned int _Roff, unsigned int _Count);
};
// Copies up to _Count characters starting at _Roff from _Right into this string, handling self-assignment by shifting in place.
// @fnv 0x0044a580
FUN_0044a580_cls* FUN_0044a580_cls::AssignSubstring(Str& _Right, unsigned int _Roff, unsigned int _Count)
{
    if (((AnimIdle*)&_Right)->GetSection() < _Roff)
        FUN_00ec30e8();
    unsigned int _Num = ((AnimIdle*)&_Right)->GetSection() - _Roff;
    if (_Count < _Num)
        _Num = _Count;
    if (this == &_Right)
    {
        EraseRange(_Roff + _Num, DAT_010173f0);
        EraseRange(0, _Roff);
    }
    else if (_Grow(_Num, false))
    {
        FUN_0044ccd0(_Myptr(), Res, _Right._Myptr() + _Roff, _Num);
        _Eos(_Num);
    }
    return this;
}
}  // namespace fnv_0044a580

namespace fnv_0044a730 {
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
};
template <class C, class T, class A> class basic_string
{
  public:
    int pad0;
    char* Ptr;
    int pad1[4];
    unsigned int Res;
    void _Eos(unsigned int);
    void FUN_0064df10(char*, unsigned int);
};
}
void __cdecl FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
struct FUN_0044a730_cls : public std::basic_string<char, std::char_traits<char>, std::allocator<char> >
{
    void FUN_0044a730(bool, unsigned int);
};
// @fnv 0x0044a730
void FUN_0044a730_cls::FUN_0044a730(bool _Built, unsigned int _Newsize)
{
    if (!_Built)
    {
    }
    else if (Res >= 16)
    {
        char* _Ptr = this->Ptr;
        if (_Newsize > 0)
            FUN_0044ccd0((char*)&this->Ptr, 16, _Ptr, _Newsize);
        FUN_0064df10(_Ptr, Res + 1);
    }
    Res = 15;
    _Eos(_Newsize);
}
}  // namespace fnv_0044a730

namespace fnv_0044a880 {
namespace std {
template <class _Elem> struct char_traits;
template <class _Ty> class allocator;
template <class _Elem, class _Traits, class _Ax> class basic_string
{
  public:
    char* _Myptr();
    void ResizeString(unsigned int _Newsize);
};
}

void __cdecl FUN_0044a8c0(char&, const char&);

// Sets the string's size field to _Newsize and writes a null terminator at the new end of the buffer.
// @fnv 0x0044a880
template <>
void std::basic_string<char, std::char_traits<char>, std::allocator<char> >::ResizeString(unsigned int _Newsize)
{
    char c = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x14) = _Newsize;
    FUN_0044a8c0(_Myptr()[_Newsize], c);
}
}  // namespace fnv_0044a880

struct _DummyTag
{
};
_DummyTag __cdecl FUN_0065e750();
char* __cdecl FUN_0044e420(char*, unsigned int, const char*, unsigned int, _DummyTag);

// @fnv 0x0044ccd0
char* __cdecl FUN_0044ccd0(char* _First1, unsigned int _Size_in_bytes, const char* _First2, unsigned int _Count)
{
    return FUN_0044e420(_First1, _Size_in_bytes, _First2, _Count, FUN_0065e750());
}

struct NiStream;
struct blob6
{
    char b[6];
};
struct ShortPoint3
{
    static struct blob6 ComponentProduct(void*, void*);
    float Length();
    short SqrLength();
    short Dot(void*);
    struct blob6 Cross(void*);
    float GetFloatX();
    float GetFloatY();
    float GetFloatZ();
    void SetFloatX(float);
    void SetFloatY(float);
    void SetFloatZ(float);
    static void* GetZERO();
    static void* GetUNIT_X();
    static void* GetUNIT_Y();
    static void* GetUNIT_Z();
    static void* GetUNIT_ALL();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    short x;
    short y;
    short z;
};
typedef char _sizecheck_NiNPShortPoint3[sizeof(ShortPoint3) == 6 ? 1 : -1];
struct FUN_0050e8b0_shell : public ShortPoint3
{
    ShortPoint3* FUN_0050e8b0(void*);
};

// Copies the x, y and z components from arPt into this point and returns this.
// @fnv 0x0050e8b0
ShortPoint3* FUN_0050e8b0_shell::FUN_0050e8b0(void* apPoint)
{
    x = ((ShortPoint3*)apPoint)->x;
    y = ((ShortPoint3*)apPoint)->y;
    z = ((ShortPoint3*)apPoint)->z;
    return this;
}

struct ActorValueShortVector : public TESBoundPoint
{
    ActorValueShortVector(int, int, int);
};
// Returns a reference to a static ActorValueShortVector constructed with (0, 0, 0).
// @fnv 0x0050e8f0
const TESBoundPoint& GetActorValueShortVector()
{
    static ActorValueShortVector DAT_011c9124(0, 0, 0);
    return DAT_011c9124;
}

void __fastcall _ref_006815c0(void* pThis);

// Calls _ref_006815c0 on pThis and on pThis + 6, then returns pThis.
// @fnv 0x0050e9c0
void* __fastcall FUN_0050e9c0(char* pThis)
{
    _ref_006815c0(pThis);
    _ref_006815c0(pThis + 6);
    return pThis;
}

struct FUN_0050e9f0_shell : public TESBoundObject
{
    void FUN_0050e9f0();
};

extern const void* const vftable_TESBoundObject[];
void __fastcall FUN_0050f930(void*);

// @fnv 0x0050e9f0
void FUN_0050e9f0_shell::FUN_0050e9f0()
{
    *reinterpret_cast<const void* const**>(this) = vftable_TESBoundObject;
    FUN_0050f930(this);
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& pt) const;
};

struct FUN_0050ea10_class
{
    char pad[0xc];
    NiPoint3 m_kCenter;
    NiPoint3 m_kExtents;
    // Computes the box minimum corner by subtracting m_kExtents from m_kCenter and stores it in arPoint.
// @fnv 0x0050ea10
    void FUN_0050ea10(NiPoint3& arMinCorner) const
    {
        arMinCorner = m_kCenter - m_kExtents;
    }
};

static void (__thiscall FUN_0050ea10_class::*volatile p)(NiPoint3&) const = &FUN_0050ea10_class::FUN_0050ea10;

struct FUN_0050eaa0_shell : public TESBoundObject
{
    void FUN_0050eaa0(TESBoundObject*);
};

void* __cdecl memcpy(void*, const void*, unsigned int);

// Copies 0xc bytes from offset 0x24 of apCopy into offset 0x24 of this object.
// @fnv 0x0050eaa0
void FUN_0050eaa0_shell::FUN_0050eaa0(TESBoundObject* apCopy)
{
    memcpy((char*)this + 0x24, (char*)apCopy + 0x24, 0xc);
}

namespace fnv_0050ebf0 {
struct FUN_0050ebf0_shell : public TESBoundObject
{
    float FUN_0050ebf0();
};

struct ActorValueShortVector
{
    short x, y, z;
    ActorValueShortVector operator-(const ActorValueShortVector& rhs) const
    {
        return Subtract(rhs);
    }
    ActorValueShortVector Subtract(const ActorValueShortVector&) const;
};

extern double DAT_01011588;
double __fastcall FUN_0050ec80(const ActorValueShortVector*);

// Subtracts the ActorValueShortVector at offset 0x2a from the one at 0x24, passes the result to FUN_0050ec80, and scales it by DAT_01011588.
// @fnv 0x0050ebf0
float FUN_0050ebf0_shell::FUN_0050ebf0()
{
    return FUN_0050ec80(&(((ActorValueShortVector*)((char*)this + 0x24))
                              ->Subtract(*(const ActorValueShortVector*)((char*)this + 0x2a)))) *
           DAT_01011588;
}
}  // namespace fnv_0050ebf0

struct BGSDebris;
struct BGSDestructibleObjectForm;
struct BGSExplosion;
struct BGSMenuIcon;
struct BGSMessageIcon;
struct BGSTextureSet;
struct CollisionComponent;
struct DestructionStageData;
struct IDebugText;
struct QueuedFile;
struct Script;
struct TESIcon;
struct TESModelTextureSwap;
struct TESTexture;
struct DistantTreeTextureInfo;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FUN_0050ee20_shell : public TESBoundAnimObject
{
    bool FUN_0050ee20(char*);
};

// Calls the virtual function at vtable offset 0x14c with pfilename and 0, returning its bool result.
// @fnv 0x0050ee20
bool FUN_0050ee20_shell::FUN_0050ee20(char* pfilename)
{
    return (this->*(*(bool(FUN_0050ee20_shell::***)(char*, int))this)[0x14c / 4])(pfilename, 0);
}

void __fastcall FUN_006c8df0(void*);
extern int DAT_0106c92c;

// @fnv 0x0050f6f0
void* __fastcall FUN_0050f6f0(void* pThis)
{
    FUN_006c8df0(pThis);
    *(int**)pThis = &DAT_0106c92c;
    return pThis;
}

struct FUN_0050f740_shell : public TESBoundAnimObject
{
    void FUN_0050f740();
};

extern void* vftable_TESBoundAnimObject;
void __fastcall FUN_0050e9f0(void*);

// @fnv 0x0050f740
void FUN_0050f740_shell::FUN_0050f740()
{
    *(void**)this = &vftable_TESBoundAnimObject;
    FUN_0050e9f0(this);
}

namespace fnv_0050f7a0 {
void __fastcall FUN_006c8df0(void*);
extern int DAT_0106c92c;

// @fnv 0x0050f7a0
void* __fastcall FUN_0050f7a0(void* pThis)
{
    FUN_006c8df0(pThis);
    *(int**)pThis = &DAT_0106c92c;
    return pThis;
}
}  // namespace fnv_0050f7a0

extern int DAT_01029b1c;
void __fastcall FUN_00483370(void*);

// @fnv 0x0050f8c0
TESObject* __fastcall FUN_0050f8c0(TESObject* apObject)
{
    FUN_00483370(apObject);
    *reinterpret_cast<int**>(apObject) = &DAT_01029b1c;
    reinterpret_cast<int*>(apObject)[7] = 0;
    reinterpret_cast<int*>(apObject)[8] = 0;
    reinterpret_cast<int*>(apObject)[6] = 0;
    return apObject;
}

struct TESObjectREFR_s
{
    const char* GetModelFilePath();
};
const char* __cdecl FUN_00480e60(void*, TESObject*);
struct FUN_0050fd90_cls
{
    const char* FUN_0050fd90(TESObject* apObject);
};
// @fnv 0x0050fd90
const char* FUN_0050fd90_cls::FUN_0050fd90(TESObject* apObject)
{
    const char* result = 0;
    if (apObject)
        result = ((TESObjectREFR_s*)apObject)->GetModelFilePath();
    if (!result)
        result = FUN_00480e60(this, apObject);
    if (!result)
        result = TESModel::GetModelFilePath((TESObject*)this);
    return result;
}

struct FUN_0050fd90_stub
{
    const char* FUN_0050fd90(PlayerCharacter*);
};
extern double g_d100;
int __cdecl TruncateFloatToInt(float);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct FUN_0050fdf0_cls
{
    void FormatScaledName(PlayerCharacter* apPlayer, char* apBuffer);
};
// @fnv 0x0050fdf0
void FUN_0050fdf0_cls::FormatScaledName(PlayerCharacter* apPlayer, char* apBuffer)
{
    const char* name = ((FUN_0050fd90_stub*)this)->FUN_0050fd90(apPlayer);
    sprintf_s(apBuffer, 260, "%s%i", name, TruncateFloatToInt((float)(apPlayer->GetScale() * g_d100)));
}

struct FUN_005100d0_s
{
    int a;
    int b;
    int c;
    int d;
    FUN_005100d0_s* FUN_005100d0(int);
};

// Sets all four integer fields of the object to zero and returns the object pointer.
// @fnv 0x005100d0
FUN_005100d0_s* FUN_005100d0_s::FUN_005100d0(int)
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return this;
}

struct FUN_005102b0_shell : public TESFormList
{
    TESObject* FUN_005102b0(TESObject*);
};

// Calls a helper with the object and returns the resulting TESObject pointer.
// @fnv 0x005102b0
TESObject* FUN_005102b0_shell::FUN_005102b0(TESObject* lpNew)
{
    lpNew = InsertObjectAfter(m_pSecondObject, lpNew);
    return lpNew;
}

struct FUN_0064df10_helper
{
    void deallocate(void* _Ptr, unsigned int __formal);
};

// @fnv 0x0064df10
void FUN_0064df10_helper::deallocate(void* _Ptr, unsigned int uiUnused)
{
    ::operator delete(_Ptr);
}

namespace fnv_0044d580 {
struct FUN_0065e750_struct
{
    char FUN_0065e750();
};
extern char __cdecl FUN_0065e750();
extern void __cdecl FUN_0044e460(void*, void*, void*, void*, char);

// Calls FUN_0065e750 and passes its returned char as the fifth argument to FUN_0044e460 along with a, b, c and d.
// @fnv 0x0044d580
void __cdecl FUN_0044d580(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    char v = FUN_0065e750();
    FUN_0044e460(apArg1, apArg2, apArg3, apArg4, v);
}
}  // namespace fnv_0044d580

void __fastcall FUN_0050e9f0(void*);
void __cdecl _Deallocate(void*);

struct FUN_0050e990
{
    void* DeleteThis(unsigned int flags);
};

// @fnv 0x0050e990
void* FUN_0050e990::DeleteThis(unsigned int flags)
{
    FUN_0050e9f0(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_012031e4;

// @fnv 0x0050ea90
int FUN_0050ea90()
{
    return DAT_012031e4;
}

struct FUN_0050f5a0_struct
{
    void FUN_0050f5a0();
};

// @fnv 0x0050f5a0
void FUN_0050f5a0_struct::FUN_0050f5a0()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = 0;
}

extern NiFixedString* DAT_011c6218;

// @fnv 0x0050f5c0
NiFixedString* FUN_0050f5c0()
{
    return DAT_011c6218;
}

struct BaseProcess;

class FUN_008d0560_class
{
  public:
    NiNode* FUN_008d0560(BipedAnim* apBiped);
};

// @fnv 0x008d0560
NiNode* FUN_008d0560_class::FUN_008d0560(BipedAnim* apBiped)
{
    return 0;
}

struct FUN_00933790Class
{
    int GetZero(const char*);
};

// @fnv 0x00933790
int FUN_00933790Class::GetZero(const char* arg)
{
    int result = 0;
    return result;
}

namespace fnv_0050f710 {
struct FUN_0050f740_shell
{
    void FUN_0050f740(void);
    void* FUN_0050f710(unsigned int flags);
};

void* _Deallocate(void* p);

// Calls FUN_0050f740, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0050f710
void* FUN_0050f740_shell::FUN_0050f710(unsigned int flags)
{
    FUN_0050f740();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0050f710

void __fastcall FUN_0050f930(void* obj);
void _Deallocate(void* obj);

struct FUN_0050f900_Class
{
    void* __thiscall FUN_0050f900(unsigned int flags);
};

// Calls FUN_0050f930 on this, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0050f900
void* __thiscall FUN_0050f900_Class::FUN_0050f900(unsigned int flags)
{
    FUN_0050f930(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0050eb30_class
{
    float FUN_0050eb30();
};

// @fnv 0x0050eb30
float FUN_0050eb30_class::FUN_0050eb30()
{
    return (float)(short)*(short*)this;
}

struct FUN_0050eb70_Class
{
    float GetShortValueAsFloat();
};

// @fnv 0x0050eb70
float FUN_0050eb70_Class::GetShortValueAsFloat()
{
    return (float)*(short*)((char*)this + 4);
}

struct FUN_0059b820_class : TESBoundObject
{
    NiNode* FUN_0059b820(TESObjectREFR* reference, bool flag);
};

// @fnv 0x0059b820
NiNode* FUN_0059b820_class::FUN_0059b820(TESObjectREFR* reference, bool flag)
{
    NiAVObject* result = Get3DObject(reference, flag);
    return static_cast<NiNode*>(result);
}

struct FUN_006055d0_class
{
    void FUN_0050fbf0(int);
    void FUN_006055d0(int a);
};
// @fnv 0x006055d0
void FUN_006055d0_class::FUN_006055d0(int a)
{
    FUN_0050fbf0(a);
}

extern "C" void __cdecl FUN_00ec3205(int);
extern void* DAT_010a2f9c;
extern void* DAT_010a2fa4;

struct FUN_00aca4b0_class
{
    void* vtbl;
    void __thiscall FUN_00aca4b0();
};

// @fnv 0x00aca4b0
void __thiscall FUN_00aca4b0_class::FUN_00aca4b0()
{
    vtbl = &DAT_010a2fa4;
    vtbl = &DAT_010a2f9c;
    FUN_00ec3205((int)this);
}

struct S_4029f0
{
    void __thiscall FUN_00402a20(int, bool);
    void __thiscall FUN_004029f0(bool);
};
// Calls FUN_00402a20 with index 1 and the inverse of b.
// @fnv 0x004029f0
void __thiscall S_4029f0::FUN_004029f0(bool b)
{
    FUN_00402a20(1, !b);
}

struct FUN_00409aa0_shell
{
    void FUN_00409aa0(unsigned int, bool);
    void FUN_00409a70(bool);
};
// Calls FUN_00409aa0 with 1 and the inverse of b.
// @fnv 0x00409a70
void FUN_00409aa0_shell::FUN_00409a70(bool b)
{
    FUN_00409aa0(1, !b);
}

struct Holder
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void vt(const char*) = 0;
    void FUN_0050f5d0();
};
// @fnv 0x0050f5d0
void Holder::FUN_0050f5d0()
{
    vt(TESModel::GetModelFilePath((TESObject*)this));
}

struct FUN_0044a9d0_Class
{
    unsigned int FUN_0044a9d0();
};
extern void __cdecl FUN_00ec30b0();
struct FUN_0044a8d0_Class : FUN_0044a9d0_Class
{
    unsigned int ResizeBuffer(unsigned int, unsigned int);
    void _Tidy(bool, unsigned int);
    void _Eos(unsigned int);
    bool FUN_0044a8d0(unsigned int, bool);
};
// @fnv 0x0044a8d0
bool FUN_0044a8d0_Class::FUN_0044a8d0(unsigned int uiNewSize, bool bTrim)
{
    if (FUN_0044a9d0() < uiNewSize)
        FUN_00ec30b0();
    if (*(unsigned int*)((char*)this + 0x18) < uiNewSize)
        ResizeBuffer(uiNewSize, *(unsigned int*)((char*)this + 0x14));
    else if (bTrim && uiNewSize < 16)
        _Tidy(true,
              uiNewSize < *(unsigned int*)((char*)this + 0x14) ? uiNewSize : *(unsigned int*)((char*)this + 0x14));
    else if (uiNewSize == 0)
        _Eos(0);
    return 0 < uiNewSize;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<10>);

struct FUN_0050ed30_class
{
    void FUN_0050ed30();
};

// @fnv 0x0050ed30
void FUN_0050ed30_class::FUN_0050ed30()
{
    BSEndian((unsigned char*)this + 6, EndianSizeTag<10>());
    BSEndian((unsigned char*)this + 8, EndianSizeTag<10>());
    BSEndian((unsigned char*)this + 10, EndianSizeTag<10>());
    BSEndian((unsigned char*)this, EndianSizeTag<10>());
    BSEndian((unsigned char*)this + 2, EndianSizeTag<10>());
    BSEndian((unsigned char*)this + 4, EndianSizeTag<10>());
}

struct FNStub
{
    const char* GetFullName();
};
int BSStringLength(const char* s);
struct FUN_005f6ed0_Class
{
    unsigned short FUN_005f6ed0();
};
// Computes a size starting at 30, adding the length of the full names of the FNStub objects at offsets 24 and 44 when present.
// @fnv 0x005f6ed0
unsigned short FUN_005f6ed0_Class::FUN_005f6ed0()
{
    unsigned short size = 0;
    size += 28;
    size += 1;
    if (((FNStub*)((char*)this + 24))->GetFullName())
        size += BSStringLength(((FNStub*)((char*)this + 24))->GetFullName());
    size += 1;
    if (((FNStub*)((char*)this + 44))->GetFullName())
        size += BSStringLength(((FNStub*)((char*)this + 44))->GetFullName());
    return size;
}

struct FUN_0050ece0_class
{
    char p[0x24];
    TESObjectBound bound;
    void FUN_0050ece0();
};
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(char*, char*, int);
// Calls FUN_00401500 twice around a AppendChunk call on the bound member with 0xc, invoking bound.FUN_0050ed30 when it returns true.
// @fnv 0x0050ece0
void FUN_0050ece0_class::FUN_0050ece0()
{
    if (FUN_00401500())
        bound.FUN_0050ed30();
    AppendChunk((char*)0x444e424f, (char*)&bound, 0xc);
    if (FUN_00401500())
        bound.FUN_0050ed30();
}

namespace fnv_0050ea50 {
class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    NiPoint3 operator+(NiPoint3 const& rhs) const;
};

class Target_0050ea50
{
  public:
    unsigned char pad[0x0c];
    NiPoint3 point1;
    NiPoint3 point2;

    void FUN_0050ea50(NiPoint3& result);
};

// Adds point1 and point2 and stores the sum in result.
// @fnv 0x0050ea50
void Target_0050ea50::FUN_0050ea50(NiPoint3& result)
{
    result = point1 + point2;
}
}  // namespace fnv_0050ea50

struct FUN_0050f7c0_Class
{
    void FUN_0050f7f0();
    void* DestroyIfFlagged(unsigned int flags);
};

void __cdecl _Deallocate(void* p);

// Calls FUN_0050f7f0, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0050f7c0
void* FUN_0050f7c0_Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_0050f7f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005e7f90_class : public NiAVObject
{
  public:
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

    virtual const char* GetModelName();

    NiAVObject* CreateFadeNode(const char* pfilename);
};

// Creates a new BSFadeNode, sets its name from this object's model name, and returns it.
// @fnv 0x005e7f90
NiAVObject* FUN_005e7f90_class::CreateFadeNode(const char* pfilename)
{
    NiAVObject* pData3D = 0;
    pData3D = new BSFadeNode;
    pData3D->SetName(NiFixedString(this->GetModelName()));
    return pData3D;
}

extern int DAT_01082cb8;
int _fopen(const char*, const char*);
int _fclose(int);

// Builds a path from arg's string (inline or heap) and checks it can be opened with _fopen, closing the handle; returns whether opening succeeded.
// @fnv 0x00ac6e10
bool CanOpenFile(void* apPathHolder)
{
    const char* name;
    if (*(unsigned int*)((char*)apPathHolder + 0x18) >= 0x10)
        name = *(const char**)((char*)apPathHolder + 4);
    else
        name = (const char*)apPathHolder + 4;
    int fp = _fopen(name, (const char*)&DAT_01082cb8);
    if (fp == 0)
        return false;
    else
        _fclose(fp);
    return true;
}

class Fb990Arg
{
  public:
    bool IsReady();
};

class Fb990Embedded
{
  public:
    virtual void Slot00()
    {}
    virtual void Slot01()
    {}
    virtual void Slot02()
    {}
    virtual void Slot03()
    {}
    virtual void Slot04()
    {}
    virtual int Slot05()
    {
        return 0;
    }
};

struct Fb990Holder
{
    char unk00[0x3c];
    Fb990Embedded m_3c;
};

class Fb990Target
{
  public:
    void Apply(int v);
};

extern Fb990Holder* DAT_011ca284;
extern Fb990Target* DAT_011c3b3c;

class FUN_004fb990_cls
{
  public:
    void Fallback(Fb990Arg* a);
    void ApplyIfReady(Fb990Arg* a);
};

// If the argument is ready, reads Slot05 from DAT_011ca284->m_3c and passes it to DAT_011c3b3c->Apply; otherwise calls Fallback.
// @fnv 0x004fb990
void FUN_004fb990_cls::ApplyIfReady(Fb990Arg* a)
{
    Fb990Arg* p = a;
    if (!p->IsReady())
    {
        this->Fallback(a);
    }
    else
    {
        int r = DAT_011ca284->m_3c.Slot05();
        DAT_011c3b3c->Apply(r);
    }
}

template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    operator const T*() const;
};
int FUN_00406f60(BSStringT<char>*, const char*, ...);
struct Extra503
{
    short FUN_00418770();
};
struct Ref503
{
    Extra503* FUN_005d43c0();
};
struct Setting503
{
    int* FUN_0043d4d0();
};
extern Setting503 g_011c846c;
struct Parent503;
struct Child503
{
    Parent503* FUN_009611e0();
};
struct Parent503
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
    virtual void remove(Child503*);
};
struct Root503
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
    virtual Child503* get(const NiFixedString&);
};
const NiFixedString& FUN_005039e0();
void FUN_00c8ecf0(Root503*);
struct Shell503
{
    Root503* FUN_0050ee50(Ref503*, bool);
    Root503* GetRootAndRemoveChildren(Ref503*, bool);
};
// @fnv 0x00503820
Root503* Shell503::GetRootAndRemoveChildren(Ref503* ref, bool flag)
{
    Root503* count = FUN_0050ee50(ref, flag);
    int root = ref ? ref->FUN_005d43c0()->FUN_00418770() : 1;
    if (count && root < *g_011c846c.FUN_0043d4d0())
    {
        Child503* child;
        if (root == 1)
        {
            child = count->get(FUN_005039e0());
            if (child)
                child->FUN_009611e0()->remove(child);
            FUN_00c8ecf0(count);
        }
        else
        {
            for (int i = root; i < *g_011c846c.FUN_0043d4d0(); i++)
            {
                BSStringT<char> name;
                FUN_00406f60(&name, "Arrow%d", i);
                child = count->get(NiFixedString(name));
                if (child)
                    child->FUN_009611e0()->remove(child);
            }
        }
    }
    return count;
}

namespace fnv_0050d600 {
struct FUN_0048cee0_class
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual int Slot05();
    int __thiscall FUN_0048cee0();
};

struct FUN_0045a5e0_class
{
    void __thiscall FUN_0045a5e0(int value);
};

extern FUN_0045a5e0_class* DAT_011c3b3c;

struct FUN_0050d600_shell
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
    FUN_0048cee0_class unk3c;

    void __thiscall FUN_0050d600(int value);
};

// @fnv 0x0050d600
void __thiscall FUN_0050d600_shell::FUN_0050d600(int value)
{
    if (unk3c.FUN_0048cee0())
    {
        DAT_011c3b3c->FUN_0045a5e0(unk3c.Slot05());
    }
}
}  // namespace fnv_0050d600

struct FUN_0050e960_cls
{
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
    FUN_0050e960_cls* FUN_0050e960(unsigned short a, unsigned short b, unsigned short c);
};

// Stores the three unsigned short arguments into m_00, m_02 and m_04 and returns this.
// @fnv 0x0050e960
FUN_0050e960_cls* FUN_0050e960_cls::FUN_0050e960(unsigned short ausFirst, unsigned short ausSecond,
                                                 unsigned short ausThird)
{
    m_00 = ausFirst;
    m_02 = ausSecond;
    m_04 = ausThird;
    return this;
}

struct Vec3Ret
{
    float x;
    float y;
    float z;
    Vec3Ret(float a, float b, float c);
};

class Bound24
{
  public:
    float GetA();
    float GetB();
    float GetC();
};

class FUN_0050ead0_cls
{
  public:
    Vec3Ret FUN_0050ead0();
};

// Returns a Vec3Ret built from the A, B and C values of the Bound24 at offset 0x24 of this object.
// @fnv 0x0050ead0
Vec3Ret FUN_0050ead0_cls::FUN_0050ead0()
{
    Vec3Ret r(((Bound24*)((char*)this + 0x24))->GetA(), ((Bound24*)((char*)this + 0x24))->GetB(),
              ((Bound24*)((char*)this + 0x24))->GetC());
    return r;
}

// FUN_0050eb50 : returns a float computed from a signed 16-bit field at offset +2.
struct FUN_0050eb50_cls
{
    char m_b00;
    char m_b01;
    short m_s02;

    float FUN_0050eb50();
};

// @fnv 0x0050eb50
float FUN_0050eb50_cls::FUN_0050eb50()
{
    return (float)(int)this->m_s02;
}

extern char DAT_01029994;
extern void __fastcall FUN_0050e9f0(void*);

struct FUN_0050f7f0_shell
{
    void FUN_0050f7f0();
};

// @fnv 0x0050f7f0
void FUN_0050f7f0_shell::FUN_0050f7f0()
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_01029994);
    FUN_0050e9f0(this);
}

struct Owner;
struct Param;
struct Effect
{
    void* FUN_008d6f30();
};
struct Record
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual Effect* GetSecondary();
};
struct Param
{
    void FUN_00569350(void*);
};
struct FUN_00664f50_class
{
    Record* CreateTreeInstance(Param*, Owner*);
};
struct Owner
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148();
    virtual void slot_14c();
    virtual void slot_150();
    virtual void slot_154();
    virtual void slot_158();
    virtual void slot_15c();
    virtual void slot_160();
    virtual void slot_164();
    virtual void slot_168();
    virtual void slot_16c();
    virtual void slot_170();
    virtual void slot_174();
    virtual void slot_178();
    virtual void slot_17c();
    virtual void Notify(Record*);
    int FUN_00401170();
    Record* CreateRecord(Param* target, int unused);
};
void* __cdecl FUN_00664840(unsigned int);
// If FUN_00401170 returns 0x25, creates a Record via CreateTreeInstance, notifies it, and passes its secondary effect's FUN_008d6f30 result to target.
// @fnv 0x0050f810
Record* Owner::CreateRecord(Param* target, int unused)
{
    Record* created = 0;
    if (FUN_00401170() != 0x25)
        return 0;
    if (FUN_00664840(1))
    {
        created = static_cast<FUN_00664f50_class*>(FUN_00664840(1))->CreateTreeInstance(target, this);
    }
    Notify(created);
    if (created && created->GetSecondary() && target)
        target->FUN_00569350(created->GetSecondary()->FUN_008d6f30());
    return created;
}

struct S_0050f930_Base
{
    virtual void vfn_00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~S_0050f930_Base();
};
struct S_0050f930_Item
{
    int unk00;
    void RemoveNode(void* owner);
};
struct FUN_0050f930 : S_0050f930_Base
{
    S_0050f930_Item* unk18;
    ~FUN_0050f930();
};

// Destructor that, if unk18 is set, calls RemoveNode on it passing this.
// @fnv 0x0050f930
FUN_0050f930::~FUN_0050f930()
{
    if (unk18)
        unk18->RemoveNode(this);
}

namespace fnv_0050fe50 {
struct ModelBaseType
{
    unsigned int FUN_00401170();
};
struct ModelReference
{
    bool FUN_00444ed0();
    ModelBaseType* FUN_007af430();
    float FUN_00567400();
};
struct CachedModel
{
    void FUN_0092c870();
    NiNode* FUN_0043b230();
};
struct CachedModelPointer
{
    CachedModel* value;
    CachedModelPointer(CachedModel*);
    ~CachedModelPointer();
    CachedModel* FUN_00559450();
};
struct ModelCache
{
    void FUN_004472a0(const char*, CachedModelPointer*);
    NiNode* LoadModel(const char*, unsigned int, bool, bool, bool, bool);
};
extern ModelCache* DAT_011c3b3c;
extern unsigned int DAT_011c90ac;
struct ModelOwner
{
    const char* FUN_0050fd90(ModelReference*);
    void FormatScaledName(ModelReference*, char*);
    NiNode* GetModelNode(ModelReference*);
};
unsigned int FUN_0045c6b0(ModelOwner*);
// @fnv 0x0050fe50
NiNode* ModelOwner::GetModelNode(ModelReference* reference)
{
    const char* pModelName = FUN_0050fd90(reference);
    NiNode* pNode = 0;
    if (reference && reference->FUN_00444ed0() && reference->FUN_007af430()->FUN_00401170() != 30)
    {
        CachedModelPointer cachedModel(0);
        DAT_011c3b3c->FUN_004472a0(pModelName, &cachedModel);
        if (cachedModel.FUN_00559450())
            cachedModel.FUN_00559450()->FUN_0092c870();
        pNode = new BSFadeNode;
    }
    else
    {
        unsigned int flags = FUN_0045c6b0(this);
        if (reference && reference->FUN_00567400() != 1.0)
        {
            char scaledName[260];
            FormatScaledName(reference, scaledName);
            CachedModelPointer cachedScaled(0);
            DAT_011c3b3c->FUN_004472a0(scaledName, &cachedScaled);
            if (cachedScaled.FUN_00559450())
            {
                cachedScaled.FUN_00559450()->FUN_0092c870();
                pNode = cachedScaled.FUN_00559450()->FUN_0043b230();
                ++DAT_011c90ac;
            }
        }
        if (!pNode)
            pNode = DAT_011c3b3c->LoadModel(pModelName, flags, true, false, false, false);
    }
    return pNode;
}
}  // namespace fnv_0050fe50

struct Ev510Node
{
    void FUN_00a5a040();
    void FUN_00a59c60(NiUpdateData& data);
};

struct Ev510Obj : TESObject
{
    bool FUN_00510080();
};

// @fnv 0x00510080
bool Ev510Obj::FUN_00510080()
{
    Ev510Node* p = (Ev510Node*)CreateNiNode(0);
    p->FUN_00a5a040();
    NiUpdateData data(0.0f, false, false);
    p->FUN_00a59c60(data);
    return true;
}

class FUN_005f0d30_sub
{
  public:
    void Apply(int a, unsigned char b, int c);
};

class FUN_005f0d30_cls
{
  public:
    int Probe();
    void ApplyFlagIfProbeMatches(unsigned char flag);
};

// If Probe() returns 0x2a, calls Apply(0x10, flag, 1) on the sub-object at offset 0x30.
// @fnv 0x005f0d30
void FUN_005f0d30_cls::ApplyFlagIfProbeMatches(unsigned char flag)
{
    if (Probe() == 0x2a)
    {
        reinterpret_cast<FUN_005f0d30_sub*>(reinterpret_cast<char*>(this) + 0x30)->Apply(0x10, flag, 1);
    }
}

struct FUN_0050ee50_obj
{
    void FUN_0050ee50(TESObjectREFR* a1, int a2);
};

struct FUN_007af430_ref
{
    TESForm* FUN_007af430();
};

struct FUN_005f8bf0_form
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94(TESObjectREFR* reference);
};

struct FUN_005f8bf0_shell : public TESCreature
{
    void CalcLeveledCreature(TESObjectREFR* pRef);
};

// @fnv 0x005f8bf0
void FUN_005f8bf0_shell::CalcLeveledCreature(TESObjectREFR* pRef)
{
    if (actorData.GetUsesLeveledTemplate() && pRef && !pRef->HasLeveledCreatureCalced())
    {
        actorData.SetTemplateReference(pRef);
        reinterpret_cast<FUN_005f8bf0_form*>(reinterpret_cast<FUN_007af430_ref*>(pRef)->FUN_007af430())->slot94(pRef);
    }
    else
    {
        reinterpret_cast<FUN_0050ee50_obj*>(this)->FUN_0050ee50(pRef, 0);
    }
}

namespace fnv_005f8c70 {
class SubObj
{
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
};
class NodeLike
{
  public:
    bool FUN_008256d0();
    int* FUN_006815c0();
    NodeLike* FUN_00726070();
};
class MgrLike
{
  public:
    void FUN_0045a5e0(char*);
};
extern MgrLike* DAT_011c3b3c;
int FUN_00406d30(char*, unsigned int, int);
char* FUN_0040ab30(char*, int);

class FUN_005f8c70_cls
{
  public:
    char unk00[0xdc];
    SubObj m_dc;
    char unkE0[0x118 - 0xe0];
    void FUN_0050fbf0(int);
    void FUN_005f8c70(int arg);
};

// @fnv 0x005f8c70
void FUN_005f8c70_cls::FUN_005f8c70(int arg)
{
    char acBuffer[0x104];
    char* pcInsert;
    NodeLike* p = (NodeLike*)((char*)this + 0x118);
    while (p != 0 && !p->FUN_008256d0())
    {
        FUN_00406d30(acBuffer, 0x104, m_dc.s5());
        pcInsert = FUN_0040ab30(acBuffer, 0x5c);
        FUN_00406d30(pcInsert + 1, 0x104 - (pcInsert - acBuffer) - 1, *p->FUN_006815c0());
        DAT_011c3b3c->FUN_0045a5e0(acBuffer);
        p = p->FUN_00726070();
    }
    FUN_0050fbf0(arg);
}
}  // namespace fnv_005f8c70

struct FUN_0065de30
{
    void* value;
    explicit FUN_0065de30(void* source);
    FUN_0065de30(const FUN_0065de30& other);
};
struct FUN_007ab050_Class
{
    void FUN_0044a7b0(FUN_0065de30 value);
    void FUN_0044a730(unsigned int a, unsigned int b);
    void AssignSubstring(unsigned int a, unsigned int b, unsigned int c);
    FUN_007ab050_Class* FUN_007ab050(unsigned int a, unsigned int b, unsigned int c, void* source);
};
// @fnv 0x007ab050
FUN_007ab050_Class* FUN_007ab050_Class::FUN_007ab050(unsigned int uiFirst, unsigned int uiSecond, unsigned int uiThird,
                                                     void* source)
{
    FUN_0044a7b0(FUN_0065de30(source));
    FUN_0044a730(0, 0);
    AssignSubstring(uiFirst, uiSecond, uiThird);
    return this;
}

// Thiscall with one stack arg (ret 4): copies a dword and a 12-byte value from
// the argument into this, then initialises a sub-object at this+0x10 with two
// calls and returns this.

extern unsigned int DAT_010173f0;

struct FUN_00ac04c0_tri
{
    unsigned int a, b, c;
};

struct FUN_00ac04c0_src
{
    unsigned int m_00;
    FUN_00ac04c0_tri m_04;
};

class FUN_00ac04c0_sub
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;

    void Reset(unsigned int a, unsigned int b);
    void Attach(const void* p, unsigned int b, unsigned int c);
};

class FUN_00ac04c0_cls
{
  public:
    unsigned int m_00;
    FUN_00ac04c0_tri m_04;
    FUN_00ac04c0_sub m_10;

    FUN_00ac04c0_cls* CopyFromSource(const FUN_00ac04c0_src* src);
};

// Copies m_00 and m_04 from src, resets the m_10 sub-object and attaches it to src+0x10, then returns this.
// @fnv 0x00ac04c0
FUN_00ac04c0_cls* FUN_00ac04c0_cls::CopyFromSource(const FUN_00ac04c0_src* pSource)
{
    m_00 = pSource->m_00;
    m_04 = pSource->m_04;
    unsigned int pz;
    unsigned int pz2;
    FUN_00ac04c0_sub* node = &m_10;
    FUN_00ac04c0_tri tri0;
    FUN_00ac04c0_tri tri1;
    FUN_00ac04c0_tri tri2;
    FUN_00ac04c0_tri tri3;
    FUN_00ac04c0_tri tri4;
    FUN_00ac04c0_tri tri5;
    FUN_00ac04c0_tri tri6;
    FUN_00ac04c0_tri tri7;
    node->Reset(0, 0);
    node->Attach((const char*)pSource + 0x10, 0, DAT_010173f0);
    return this;
}

extern int DAT_01011584;
void __cdecl FUN_00ec9907(void* p);
unsigned int __cdecl FUN_00ec6130(const void* p);

struct FUN_0044a7f0_sub
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
    void FUN_0044a7f0(const void* a, unsigned int b);
};

struct Scratch44
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
};

struct FUN_00ac5430_cls
{
    unsigned int unk00;
    FUN_0044a7f0_sub m_04;
    void* m_3c;
    void FUN_00ac5430();
};

// @fnv 0x00ac5430
void FUN_00ac5430_cls::FUN_00ac5430()
{
    if (m_3c != 0)
    {
        FUN_00ec9907(m_3c);
    }
    Scratch44 tmp;
    unsigned int h = FUN_00ec6130(&DAT_01011584);
    m_04.FUN_0044a7f0(&DAT_01011584, h);
    m_3c = 0;
}

extern unsigned int g_aca270Data;

class ThisBase_aca270
{
  public:
    virtual ~ThisBase_aca270();
    unsigned int m_04;
    unsigned int m_08;
    ThisBase_aca270(ThisBase_aca270* aArg);
};

class ThisMember_aca270
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    void Init(unsigned int aValue, unsigned int aFlag);
    void Method(ThisMember_aca270* aOther, unsigned int aZero, unsigned int aData);
};

class ThisLocal_aca270
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
};

class FUN_00aca270 : public ThisBase_aca270
{
  public:
    ThisMember_aca270 m_0c;

    FUN_00aca270(ThisBase_aca270* aArg);
    virtual ~FUN_00aca270();
};

// Initializes m_0c with Init(0, 0), then calls Method on the argument's m_0c with 0 and g_aca270Data.
// @fnv 0x00aca270
FUN_00aca270::FUN_00aca270(ThisBase_aca270* aArg) : ThisBase_aca270(aArg)
{
    ThisLocal_aca270 aBuf;
    ThisMember_aca270* pMember = &m_0c;
    pMember->Init(0, 0);
    pMember->Method(&((FUN_00aca270*)aArg)->m_0c, 0, g_aca270Data);
}

namespace fnv_0050ee50 {
class Model;
struct RefOps
{
    bool FUN_00444ed0();
    TESBoundObject* FUN_007af430();
    void FUN_00693ef0(bool);
    float FUN_00567400();
    const char* FUN_0055d520();
};
struct ObjectOps
{
    bool FUN_0050d4a0();
    unsigned int FUN_00401170();
    void FormatScaledName(TESObjectREFR*, char*);
};
struct NodeOps
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* asNode();
    int FUN_00726070();
    float GetFloatAt64();
    NiAVObject* FUN_00a5d2c0(CloningProcess&);
    void* FUN_00a5bdd0(void*);
    void FUN_00440490(float);
    void FUN_00450f90(int);
    void FUN_0043fa80(void*);
    void FUN_00440460(void*);
    int FUN_009611e0();
    void FUN_0050f5a0();
};
struct ChildOps
{
    void* FUN_0045bc00(unsigned int);
    Model* FUN_0043b4a0(unsigned int);
};
class Model
{
  public:
    unsigned int a, b, c, d;
    Model(const char*, NiAVObject*);
    ~Model();
    NiAVObject* FUN_0043b230();
    void FUN_0092c870();
    void* FUN_004431f0(unsigned int);
};
struct ModelPointerOps
{
    Model* FUN_00559450();
    void FUN_0044aed0(Model*);
};
struct ControllerOps
{
    bool FUN_00448a40();
};
struct NamedObjectOps
{
    void* FUN_0047a520(NiFixedString*);
};
struct LoaderOps
{
    void FUN_004472a0(const char*, NiPointer<Model>&);
    bool CallFoo(const char*, Model*);
};
struct CacheOps
{
    NodeOps* FUN_00457ba0(NiNode*, CloningProcess&);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a5ecb0 : NiMemObject
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
    FUN_00a5ecb0(unsigned int);
};
struct AttachNodeOps
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
    virtual void attach(NodeOps*, bool);
};
extern CacheOps* DAT_011dea10;
extern LoaderOps* DAT_011c3b3c;
extern unsigned int DAT_011c90a8;
extern char DAT_011f36ac;
extern char DAT_011a9448;
extern char DAT_011f426c;
bool FUN_004b5bf0(NiNode*);
bool FUN_0062c3c0(TESObjectREFR*, NiNode*);
bool FUN_0048b310(TESBoundObject*, TESObjectREFR*);
bool FUN_00569410(NiNode*);
void* FUN_00653270(void*, NiAVObject*);
void FUN_005b5e40(const char*, ...);
struct CloneObject17 : TESBoundObject
{
    NiAVObject* FUN_0050ee50(TESObjectREFR*, bool);
};
// @fnv 0x0050ee50
NiAVObject* CloneObject17::FUN_0050ee50(TESObjectREFR* reference, bool forceClone)
{
    NiAVObject* p = 0;
    if (this == (TESBoundObject*)DAT_011ca220 || this == (TESBoundObject*)DAT_011ca250)
        reference = 0;
    NiNode* h = CreateNiNode(reference);
    if (reference && ((RefOps*)reference)->FUN_00444ed0() &&
        ((ObjectOps*)((RefOps*)reference)->FUN_007af430())->FUN_00401170() != 30)
        return h;
    if (h)
    {
        if (((ObjectOps*)this)->FUN_0050d4a0() && reference)
            ((RefOps*)reference)->FUN_00693ef0(true);
        if (!forceClone && ((NodeOps*)h)->FUN_00726070() == 1)
        {
            bool canReuse = false;
            switch (((ObjectOps*)this)->FUN_00401170())
            {
            case 21:
            case 43:
                if (FUN_004b5bf0(h))
                    forceClone = true;
            case 40:
            case 41:
            case 42:
            case 51:
                break;
            case 35:
            case 81:
                break;
            case 28: {
                canReuse = true;
                NiNode* node = ((NodeOps*)h)->asNode();
                if (node && ((ChildOps*)node)->FUN_0045bc00(0) && ((ChildOps*)node)->FUN_0043b4a0(0)->FUN_0043b230())
                {
                    NiAVObject* p = ((ChildOps*)node)->FUN_0043b4a0(0)->FUN_0043b230();
                    NamedObjectOps* h = (NamedObjectOps*)FUN_00653270(&DAT_011f36ac, p);
                    if (h && h->FUN_0047a520(FUN_0050f5c0()))
                        canReuse = false;
                }
                break;
            }
            default:
                canReuse = !FUN_0062c3c0(reference, h);
                break;
            }
            if (canReuse)
            {
                ControllerOps* controller = (ControllerOps*)((NodeOps*)h)->FUN_00a5bdd0((void*)&FUN_00448a80());
                if (controller)
                {
                    ControllerOps* testController = controller;
                    if (testController->FUN_00448a40())
                        canReuse = false;
                }
            }
            if (canReuse && FUN_0048b310(this, reference))
                canReuse = false;
            if (canReuse && FUN_00569410(h))
                canReuse = false;
            if (canReuse)
            {
                if (!reference || ((RefOps*)reference)->FUN_00567400() == ((NodeOps*)h)->GetFloatAt64())
                    p = h;
            }
        }
        if (!p)
        {
            float scale = 1.0f;
            if (reference)
                scale = ((RefOps*)reference)->FUN_00567400();
            if (scale == ((NodeOps*)h)->GetFloatAt64())
                scale = 1.0f;
            if (scale == 0.0)
            {
                FUN_005b5e40("MODELS: %s has a scale of 0.  Change it in the editor.",
                             ((RefOps*)reference)->FUN_0055d520());
                scale = 1.0f;
            }
            CloningProcess process(scale);
            if (forceClone)
            {
                NodeOps* pCachedNode = DAT_011dea10->FUN_00457ba0(h, process);
                if (pCachedNode && pCachedNode->asNode())
                    p = pCachedNode->asNode();
                else
                {
                    NodeOps* node = (NodeOps*)new FUN_00a5ecb0(0);
                    ((AttachNodeOps*)node)->attach(pCachedNode, true);
                    p = (NiAVObject*)node;
                }
            }
            else
                p = ((NodeOps*)h)->FUN_00a5d2c0(process);
            if (scale != 1.0 && ((NodeOps*)h)->GetFloatAt64() == 1.0)
            {
                ((NodeOps*)p)->FUN_00440490(scale);
                char filename[260];
                ((ObjectOps*)this)->FormatScaledName(reference, filename);
                NiPointer<Model> model(0);
                DAT_011c3b3c->FUN_004472a0(filename, model);
                if (!((ModelPointerOps*)&model)->FUN_00559450())
                {
                    ((ModelPointerOps*)&model)->FUN_0044aed0(new Model(filename, p));
                    ((ModelPointerOps*)&model)->FUN_00559450()->FUN_0092c870();
                    if (!DAT_011c3b3c->CallFoo(filename, ((ModelPointerOps*)&model)->FUN_00559450()))
                    {
                        Model* pFailedModel = ((ModelPointerOps*)&model)->FUN_00559450();
                        ((ModelPointerOps*)&model)->FUN_0044aed0(0);
                        delete pFailedModel;
                    }
                    else
                        ++DAT_011c90a8;
                    CloningProcess unscaled(1.0f);
                    p = ((NodeOps*)p)->FUN_00a5d2c0(unscaled);
                }
                else
                {
                    if (((ModelPointerOps*)&model)->FUN_00559450()->FUN_0043b230() &&
                        ((NodeOps*)((ModelPointerOps*)&model)->FUN_00559450()->FUN_0043b230())->GetFloatAt64() ==
                            ((RefOps*)reference)->FUN_00567400())
                    {
                        NiAVObject* replacement = _CreateNiNode(reference, forceClone);
                        return replacement;
                    }
                    else
                        FUN_005b5e40("Invalid scale found on ModelLoader copy of file '%s'", filename);
                }
            }
        }
        if (p)
        {
            ((NodeOps*)p)->FUN_00440490(1.0f);
            ((NodeOps*)p)->FUN_00450f90(0);
            ((NodeOps*)p)->FUN_0043fa80(&DAT_011a9448);
            ((NodeOps*)p)->FUN_00440460(&DAT_011f426c);
            if (((NodeOps*)p)->FUN_009611e0())
                ((NodeOps*)p)->FUN_0050f5a0();
        }
    }
    return p;
}
}  // namespace fnv_0050ee50

struct LoadedModel0050fbf0
{
    int GetRefCount();
};

struct ModelPtr0050fbf0
{
    LoadedModel0050fbf0* m_pObject;
    ModelPtr0050fbf0(LoadedModel0050fbf0* apObject);
    ~ModelPtr0050fbf0();
    operator LoadedModel0050fbf0*() const;
};

struct ModelLoader0050fbf0
{
    void QueueModelLoad(const char* apPath);
    bool GetModelFilePath(const char* apPath, ModelPtr0050fbf0& arModel);
};

class ModelForm0050fbf0
{
  public:
    const char* GetModelPath(PlayerCharacter* apPlayer);
    void GetScaledModelPath(PlayerCharacter* apPlayer, char* apBuffer);
    int GetFormType();
    void FUN_00603bb0();
    void FUN_0050fbf0(PlayerCharacter* apPlayer);
};

extern ModelForm0050fbf0* g_pSkipModelFormA;
extern ModelForm0050fbf0* g_pSkipModelFormB;
extern ModelLoader0050fbf0* g_pModelLoader0050fbf0;
extern int g_iReleasedModelCount;
extern int g_iKeptModelCount;

// @fnv 0x0050fbf0
void ModelForm0050fbf0::FUN_0050fbf0(PlayerCharacter* apPlayer)
{
    if (this == g_pSkipModelFormA || this == g_pSkipModelFormB)
        apPlayer = 0;

    const char* pModelPath = GetModelPath(apPlayer);
    if (pModelPath && *pModelPath)
    {
        if (apPlayer && apPlayer->GetScale() != 1.0)
        {
            char acScaledPath5[260];
            GetScaledModelPath(apPlayer, acScaledPath5);
            g_pModelLoader0050fbf0->QueueModelLoad(acScaledPath5);
            bool bRelease = true;
            ModelPtr0050fbf0 modelPtr(0);
            if (g_pModelLoader0050fbf0->GetModelFilePath(acScaledPath5, modelPtr) &&
                ((LoadedModel0050fbf0*)modelPtr)->GetRefCount() > 0)
                bRelease = false;
            if (bRelease)
            {
                g_pModelLoader0050fbf0->QueueModelLoad(pModelPath);
                g_iReleasedModelCount--;
            }
            else
                g_iKeptModelCount--;
        }
        else
            g_pModelLoader0050fbf0->QueueModelLoad(pModelPath);
    }

    if (GetFormType() == 0x2a)
        FUN_00603bb0();
}

void __cdecl StrMoveS(char* apDest, unsigned int auiDestSize, const char* apSrc, unsigned int auiCount);
void __cdecl StrCopyS(char* apDest, unsigned int auiDestSize, const char* apSrc, unsigned int auiCount);
void __cdecl StrXran();
void __cdecl StrXlen();

struct StdString
{
    int unk00;
    char _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;

    static const unsigned int npos;

    unsigned int size() const;
    char* _Myptr();
    bool _Grow(unsigned int auiNewsize, bool abTrim);
    void _Eos(unsigned int auiNewsize);
    StdString& Replace(unsigned int _Off, unsigned int _N0, StdString& _Right, unsigned int _Roff, unsigned int _Count);
};

// Replaces _N0 characters at _Off with _Count characters from _Right at _Roff, growing the buffer and shifting the tail as needed.
// @fnv 0x007ab250
StdString& StdString::Replace(unsigned int _Off, unsigned int _N0, StdString& _Right, unsigned int _Roff,
                              unsigned int _Count)
{
    if (_Mysize < _Off || _Right.size() < _Roff)
        StrXran();
    if (_Mysize - _Off < _N0)
        _N0 = _Mysize - _Off;
    unsigned int _Num = _Right.size() - _Roff;
    if (_Num < _Count)
        _Count = _Num;
    if (npos - _Count <= _Mysize - _N0)
        StrXlen();

    unsigned int _Nm = _Mysize - _N0 - _Off;
    unsigned int _Newsize = _Mysize + _Count - _N0;
    if (_Mysize < _Newsize)
        _Grow(_Newsize, false);

    if (this != &_Right)
    {
        StrMoveS(_Myptr() + _Off + _Count, _Myres - _Off - _Count, _Myptr() + _Off + _N0, _Nm);
        StrCopyS(_Myptr() + _Off, _Myres - _Off, _Right._Myptr() + _Roff, _Count);
    }
    else if (_Count <= _N0)
    {
        StrMoveS(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Roff, _Count);
        StrMoveS(_Myptr() + _Off + _Count, _Myres - _Off - _Count, _Myptr() + _Off + _N0, _Nm);
    }
    else if (_Roff <= _Off)
    {
        StrMoveS(_Myptr() + _Off + _Count, _Myres - _Off - _Count, _Myptr() + _Off + _N0, _Nm);
        StrMoveS(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Roff, _Count);
    }
    else if (_Off + _N0 <= _Roff)
    {
        StrMoveS(_Myptr() + _Off + _Count, _Myres - _Off - _Count, _Myptr() + _Off + _N0, _Nm);
        StrMoveS(_Myptr() + _Off, _Myres - _Off, _Myptr() + (_Roff + _Count - _N0), _Count);
    }
    else
    {
        StrMoveS(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Roff, _N0);
        StrMoveS(_Myptr() + _Off + _Count, _Myres - _Off - _Count, _Myptr() + _Off + _N0, _Nm);
        StrMoveS(_Myptr() + _Off + _N0, _Myres - _Off - _N0, _Myptr() + _Roff + _Count, _Count - _N0);
    }

    _Eos(_Newsize);
    return *this;
}

struct FUN_0050eb90_Point3
{
    float x, y, z;
    void FUN_00416870(float x, float y, float z);
};
struct FUN_0050eb90_Component
{
    float FUN_0050eb30();
    float FUN_0050eb50();
    float GetShortValueAsFloat();
};
struct FUN_0050eb90_Class
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24;
    unsigned short unk28;
    FUN_0050eb90_Component component;
    FUN_0050eb90_Point3 FUN_0050eb90();
};
// Builds a Point3 from the component's three float accessors and returns it.
// @fnv 0x0050eb90
FUN_0050eb90_Point3 FUN_0050eb90_Class::FUN_0050eb90()
{
    FUN_0050eb90_Point3 result;
    result.FUN_00416870(component.FUN_0050eb30(), component.FUN_0050eb50(), component.GetShortValueAsFloat());
    return result;
}

struct InsertValue
{
    unsigned int x, y, z, w;
};
struct InsertIterator
{
    void* container;
    InsertValue* pointer;
};
struct InsertAllocator
{
    unsigned int state;
    void FUN_0064df10(InsertValue*, unsigned int);
    InsertValue* FUN_0064df30(unsigned int);
};
void __cdecl ThrowVectorTooLong();
void __cdecl FUN_0064e4b0(InsertValue*, InsertValue*, const InsertValue&);
void __cdecl FUN_0064e4e0(InsertValue*, InsertValue*, InsertValue*);
struct InsertVector
{
    unsigned int control;
    unsigned int proxy;
    InsertAllocator allocator;
    InsertValue* first;
    InsertValue* last;
    InsertValue* end;
    unsigned int FUN_0064e300();
    unsigned int FUN_0064dc30();
    unsigned int FUN_0064de90();
    InsertValue* FUN_0064e480(InsertValue*, InsertValue*, InsertValue*);
    InsertValue* FUN_0064e340(InsertValue*, unsigned int, const InsertValue&);
    void ForwardToHelper(InsertValue*, InsertValue*);
    void Insert(InsertIterator _Where, unsigned int _Count, const InsertValue& _Val);
};
// Inserts _Count copies of _Val at _Where, growing or reallocating the vector's storage when capacity is insufficient.
// @fnv 0x0064df50
void InsertVector::Insert(InsertIterator _Where, unsigned int _Count, const InsertValue& _Val)
{
    unsigned int _Capacity = FUN_0064e300();
    if (_Count == 0)
        ;
    else if (FUN_0064de90() - FUN_0064dc30() < _Count)
        ThrowVectorTooLong();
    else if (_Capacity < FUN_0064dc30() + _Count)
    {
        _Capacity = FUN_0064de90() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < FUN_0064dc30() + _Count)
            _Capacity = FUN_0064dc30() + _Count;
        InsertValue* _Newvec = allocator.FUN_0064df30(_Capacity);
        InsertValue* _Ptr = _Newvec;
        try
        {
            _Ptr = FUN_0064e480(first, _Where.pointer, _Newvec);
            _Ptr = FUN_0064e340(_Ptr, _Count, _Val);
            FUN_0064e480(_Where.pointer, last, _Ptr);
        }
        catch (...)
        {
            ForwardToHelper(_Newvec, _Ptr);
            allocator.FUN_0064df10(_Newvec, _Capacity);
            throw;
        }
        _Count += FUN_0064dc30();
        if (first != 0)
        {
            ForwardToHelper(first, last);
            allocator.FUN_0064df10(first, end - first);
        }
        end = _Newvec + _Capacity;
        last = _Newvec + _Count;
        first = _Newvec;
    }
    else if ((unsigned int)(last - _Where.pointer) < _Count)
    {
        InsertValue _Tmp = _Val;
        FUN_0064e480(_Where.pointer, last, _Where.pointer + _Count);
        try
        {
            FUN_0064e340(last, _Count - (last - _Where.pointer), _Tmp);
        }
        catch (...)
        {
            ForwardToHelper(_Where.pointer + _Count, last + _Count);
            throw;
        }
        last += _Count;
        FUN_0064e4b0(_Where.pointer, last - _Count, _Tmp);
    }
    else
    {
        InsertValue _Tmp = _Val;
        InsertValue* _Oldend = last;
        last = FUN_0064e480(_Oldend - _Count, _Oldend, last);
        FUN_0064e4e0(_Where.pointer, _Oldend - _Count, _Oldend);
        FUN_0064e4b0(_Where.pointer, _Where.pointer + _Count, _Tmp);
    }
}

struct GrowString
{
    unsigned int unk00;
    char* data;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int size;
    unsigned int capacity;
    unsigned int FUN_0044a9d0();
    char* FUN_0065f7a0(unsigned int);
    void FUN_0044a730(bool, unsigned int);
    char* FUN_0044a970();
    void ResizeString(unsigned int);
    void ResizeBuffer(unsigned int requested, unsigned int oldSize);
};
// Grows the string buffer to at least requested bytes, copies oldSize bytes from the old data, and updates data and capacity.
// @fnv 0x0044aa10
void GrowString::ResizeBuffer(unsigned int requested, unsigned int oldSize)
{
    unsigned int uiNewCapacity = requested | 15;
    if (FUN_0044a9d0() < uiNewCapacity)
        uiNewCapacity = requested;
    else if (uiNewCapacity / 3 < capacity / 2 && capacity <= FUN_0044a9d0() - capacity / 2)
        uiNewCapacity = capacity + capacity / 2;
    char* pNewData = 0;
    try
    {
        pNewData = FUN_0065f7a0(uiNewCapacity + 1);
    }
    catch (...)
    {
        uiNewCapacity = requested;
        try
        {
            pNewData = FUN_0065f7a0(uiNewCapacity + 1);
        }
        catch (...)
        {
            FUN_0044a730(true, 0);
            throw;
        }
    }
    if (oldSize > 0)
        FUN_0044ccd0(pNewData, uiNewCapacity + 1, FUN_0044a970(), oldSize);
    FUN_0044a730(true, 0);
    data = pNewData;
    capacity = uiNewCapacity;
    ResizeString(oldSize);
}

namespace fnv_004fd440 {
struct NiModelData
{
    const char* FUN_0050fd90(int a);
};
struct BaseModelForm
{
    NiModelData* FUN_0044ddc0();
};
struct RefTarget
{
    BaseModelForm* FUN_009d9f00();
};
struct ModelLoaderMgr
{
    void FUN_0045a5e0(const char* name);
};
extern ModelLoaderMgr* DAT_011c3b3c;
struct ProjectileShell
{
    int FUN_004fd4f0();
    void FUN_0050fbf0(RefTarget* arg);
    void LoadModel(RefTarget* arg);
};
// For a non-null reference, passes its model name to the loader or calls FUN_0050fbf0 on selected paths.
// @fnv 0x004fd440
void ProjectileShell::LoadModel(RefTarget* apRef)
{
    if (apRef)
    {
        switch (FUN_004fd4f0())
        {
        case 0x40000:
        case 0x100000:
            FUN_0050fbf0(apRef);
            break;
        default:
            RefTarget* ref = apRef;
            if (ref && ref->FUN_009d9f00() && ref->FUN_009d9f00()->FUN_0044ddc0())
            {
                const char* name = ref->FUN_009d9f00()->FUN_0044ddc0()->FUN_0050fd90(0);
                DAT_011c3b3c->FUN_0045a5e0(name);
            }
            else
            {
                FUN_0050fbf0(apRef);
            }
            break;
        }
    }
}
}  // namespace fnv_004fd440

namespace fnv_007ab0a0 {
namespace std {
template <class _Elem> struct char_traits
{
};
template <class _Ty> class allocator
{
};
template <class _Elem, class _Traits, class _Ax> class basic_string;
template <> class basic_string<char, char_traits<char>, allocator<char> >
{
  public:
    void* m_pContainerProxy;

    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    char* _Myptr();
    bool _Inside(const char*);
    bool _Grow(unsigned int, bool);
    void _Eos(unsigned int);
    void _Tidy(bool, unsigned int);
    basic_string* Replace(unsigned int, unsigned int, basic_string*, unsigned int, unsigned int);
    basic_string* FUN_007ab0a0(unsigned int, unsigned int, const char*, unsigned int);
};
}
extern unsigned int DAT_010173f0;
extern void __cdecl FUN_00ec30e8();
extern void __cdecl FUN_00ec30b0();
extern void __cdecl FUN_0044d580(char*, unsigned int, const char*, unsigned int);
extern void __cdecl FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);

// Replaces a substring at pos with src, handling internal pointers, bounds checks, and buffer growth.
// @fnv 0x007ab0a0
std::basic_string<char, std::char_traits<char>, std::allocator<char> >* std::basic_string<
    char, std::char_traits<char>, std::allocator<char> >::FUN_007ab0a0(unsigned int pos, unsigned int count,
                                                                       const char* src, unsigned int srcCount)
{
    if (_Inside(src))
    {
        return Replace(pos, count, this, (unsigned int)(src - _Myptr()), srcCount);
    }
    if (_Mysize < pos)
        FUN_00ec30e8();
    if (_Mysize - pos < count)
        count = _Mysize - pos;
    if (DAT_010173f0 - srcCount <= _Mysize - count)
        FUN_00ec30b0();
    unsigned int tail = _Mysize - count - pos;
    if (srcCount < count)
        FUN_0044d580(_Myptr() + pos + srcCount, _Myres - pos - srcCount, _Myptr() + pos + count, tail);
    if (srcCount > 0 || count > 0)
    {
        unsigned int newSize = (_Mysize + srcCount) - count;
        if (_Grow(newSize, false))
        {
            if (count < srcCount)
                FUN_0044d580(_Myptr() + pos + srcCount, _Myres - pos - srcCount, _Myptr() + pos + count, tail);
            FUN_0044ccd0(_Myptr() + pos, _Myres - pos, src, srcCount);
            _Eos(newSize);
        }
    }
    return this;
}
}  // namespace fnv_007ab0a0
