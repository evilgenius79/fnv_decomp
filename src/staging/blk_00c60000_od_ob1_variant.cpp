
// src/staging/blk_00c60000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void* g_01204388;
struct FUN_00c600f0_Class
{
    void* __thiscall FUN_00c600f0();
};
struct NiStream;
struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
};
struct BSPSysSimpleColorModifier : public NiPSysModifier
{
    void FUN_00c60910(NiStream& stream);
};
struct FUN_00c60930_class
{
    void FUN_00c31670(void*);
    void FUN_00c60930(void* a);
};
extern "C" void* g_01204390;
struct FUN_00c60d40_Class
{
    void* __thiscall FUN_00c60d40();
};
struct FUN_00c61420_Class
{
    void* __thiscall FUN_00c61420(void* p);
};
struct FUN_00a99870_Class
{
    void __thiscall FUN_00a99870(int, int);
};
void __thiscall FUN_00a99870_Class::FUN_00a99870(int, int)
{}
struct FUN_00c61430_Class
{
    void __thiscall FUN_00c61430(int, int);
};
struct FUN_00c61450_Class
{
    void FUN_00a99a90(int);
    void FUN_00c61450(int a);
};
struct FUN_00a9af00_class
{
    void FUN_00a9af00(int a);
};
struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};
struct FUN_00c61490_Class
{
    bool FUN_00a89ae0(const void* arg);
    bool IsNot(const void* arg);
};
struct FUN_00c614c0_Class
{
    void __thiscall FUN_00a89210(void*);
    void __thiscall FUN_00c614c0(void* ap);
};
struct FUN_00c614e0_Class
{
    char FUN_00a998e0(int arg);
    char FUN_00c614e0(int arg);
};
struct NiFixedString;
struct NiAVObject
{
    void SetName(NiFixedString const&);
    void FUN_00c61610();
};
extern NiFixedString* DAT_012043a0;
extern "C" void* g_012043a4;
struct FUN_00c61810_class
{
    void* FUN_00c61810();
};
struct FUN_00c61820_class
{
    void* FUN_00c61820(int);
};
struct NiStream;
struct NiPSysVolumeEmitter
{
    void LoadBinary(NiStream&);
    void LoadBinaryFromStream(NiStream* stream);
};
struct NiStream;
struct NiObject
{
    void FUN_00c62140();
    void LinkObject(NiStream&);
    void FUN_00c61f30(NiStream& stream);
};
struct FUN_00c61f60_class
{
    void __thiscall FUN_00c2f4f0(int);
    void __thiscall FUN_00c61f60(int);
};
struct FUN_00c61f80_cls
{
    void FUN_00c31b60(void* apParam);
    void FUN_00c61f80(void* apParam);
};
struct NiAVObject;
struct NiPSysCylinderEmitter
{
    bool FUN_00c31b80(NiAVObject*);
    bool FUN_00c61fa0(NiAVObject*);
};
struct FUN_00c627e0_Class
{
    void __thiscall FUN_00c62140();
    void __thiscall FUN_00c627e0(void* p);
};
extern "C" void* g_012043b8;
struct FUN_00c632e0_Class
{
    void* __thiscall FUN_00c632e0();
};
struct FUN_00c31670_class
{
    void __thiscall FUN_00c31670(int a);
};
struct FUN_00c63950_class
{
    void __thiscall ForwardToOther(int a);
};
struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_012043c8;
struct FUN_00c63aa0_class
{
    GlobalObject_00a7b610* FUN_00c63aa0();
};
void __cdecl FUN_00c63c30(int, int);
void __cdecl CallWithSameArgumentTwice(int a);
struct NiBinaryExtraData
{
    void LinkObject(void*);
};
struct BSDecalPlacementVectorExtraData : NiBinaryExtraData
{
    void LinkToObject(void*);
};
struct FUN_00c644d0_Class
{
    unsigned char Equals(const char*);
    unsigned char FUN_00c644d0(const char*);
};
extern "C" void* g_012043d4;
struct FUN_00c64600_Class
{
    void* __thiscall GetGlobalPointer();
};
struct NiStream;
struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct FUN_00c64b70 : NiObjectBase
{
    bool RegisterStreamables(NiStream& stream);
};
struct FUN_00c64fc0_class
{
    int __thiscall GetThisAddress(int);
};
struct NiStream;
struct NiExtraData
{
    void LinkObject(NiStream& stream);
    void FUN_00c65160(NiStream& stream);
};
struct C00c541e0
{
    bool FUN_00a7b3d0(int);
    bool FUN_00c65290(int a);
};
extern "C" void* DAT_012043f0;
struct FUN_00c657e0_class
{
    void* GetGlobalDataPtr();
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c377c;
struct NiTPointerList_00c62890
{
    void* m_pObjectItem;
    void* m_pNext;
    void FUN_00c62890();
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c3a08;
struct FUN_00c65680_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall FUN_00c65680();
};
struct FUN_00c600c0_class
{
    void* __thiscall FUN_00c5fd50();
    void* __thiscall FUN_00c600c0(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};
struct FUN_00c613a0_Class
{
    void __thiscall FUN_00c613a0();
    void* __thiscall FUN_00c617e0(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
extern "C" void NiFree(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00c63210_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall FUN_00c63210(int flag);
};
struct FUN_00a7b300_shell
{
    void __thiscall FUN_00a7b300();
};
struct FUN_00c632f0_class
{
    void* __thiscall FUN_00c632f0(unsigned int flags);
};
void __cdecl operator delete(void*, int);
struct CloningProcess;
struct NiPSysModifierCopy : NiPSysModifier
{
    void CopyMemberData(NiPSysModifier* dst, CloningProcess& proc);
};
struct FUN_00c63840_Class : NiPSysModifier
{
    void __thiscall CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc);
};
struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct NiPSysModifier_00c31950
{
    void __thiscall FUN_00c31950(void*);
};
struct FUN_00c63970_class : NiPSysModifier_00c31950
{
    void __thiscall FUN_00c63970(void* stream);
};
void __cdecl FUN_00c63b40(void* p);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64610_Class
{
    void __thiscall FUN_00c63b40();
    void* __thiscall FUN_00c64610(unsigned int flags);
};
struct FUN_00c64930_Class
{
    void FUN_00c64930(int a);
};
struct FUN_00c64940_Class
{
    bool FUN_00c64940(int a);
};
struct FUN_00c64c30_Class
{
    bool __thiscall FUN_00c64c30(int a);
};
extern int DAT_010c3384;
struct NiPSysPositionModifier
{
    NiPSysPositionModifier();
    ~NiPSysPositionModifier();
};
struct FUN_00c60240 : NiPSysPositionModifier
{
    int m_vt;
    float m_f[4];
    float m_v[4];
    float m_w[4];
    FUN_00c60240();
};
struct NiStream;
struct RgbaColor
{
    void SaveBinary(NiStream&);
};
struct FUN_00c60950_class : NiPSysModifier_00c31950
{
    void FUN_00c60950(NiStream* stream);
};
int _sprintf_s(char*, unsigned int, const char*, ...);
size_t _strlen(const char*);
struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
struct FUN_00c62090_Class
{
    char* __thiscall BuildAttachTypeString(const char* name, int type);
};
extern GlobalObject_00a7b610 g_012043b0;
struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* __thiscall FUN_00c63320();
};
struct NiStream
{
    void SerializeString(const char* s);
};
struct NiExtraDataSaveHelper
{
    void SaveBinary(NiStream& s);
};
struct FUN_00c65210_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    unsigned short m_18;
    void __thiscall FUN_00c65210(NiStream& stream);
};
void __cdecl FUN_0044adf0(NiStream& stream, const unsigned int& count);
extern "C" void* __cdecl NiMalloc(unsigned int size);
struct FUN_00c65760_Class
{
    int* m_pVtbl;
    void* m_pData;
    unsigned short m_iArrayLength;
    unsigned short m_iFlags;
    unsigned short m_iPad;
    unsigned short m_iType;
    void* __thiscall InitArray(unsigned short count, unsigned short type);
};
struct FUN_00c61b10
{
    char m_iWordAt00[0x6c];
    FUN_00c61b10();
    ~FUN_00c61b10();
    static void* operator new(unsigned int size);
};
FUN_00c61b10* FUN_00c61e70();
extern "C" void* __cdecl NiMalloc(unsigned int);
struct FUN_00c63260_class
{
    int* m_ppVirtualMethodTable;
    void* m_data;
    unsigned short m_uiX;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_uiY;
    FUN_00c63260_class(unsigned short x, unsigned short y);
};
struct NiPoint3_ZERO
{
    int x;
    int y;
    int z;
};
extern NiPoint3_ZERO _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
extern int DAT_010c37fc;
struct FUN_00c63330 : NiPSysPositionModifier
{
    FUN_00c63330();
};
int strcpy_s(char* dst, unsigned int size, const char* src);
size_t strlen(const char*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
struct FUN_00c64780_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00c64780(const char* apName);
};
struct FUN_00c65710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall FUN_00c65710(unsigned int flags);
};
struct IsEqualHelper
{
    bool __thiscall IsEqual(NiObject* arg);
};
struct FUN_00c60000_Class
{
    bool __thiscall IsEqualWithFloat(void* arg);
};
struct FUN_00c60700_Group
{
    unsigned int value00;
    unsigned int value04;
    unsigned int value08;
    unsigned int value0c;
};
struct FUN_00c60700_Data
{
    unsigned char padding[0x18];
    FUN_00c60700_Group group00;
    FUN_00c60700_Group group10;
    FUN_00c60700_Group group20;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
};
struct FUN_00c60700_Class : NiPSysModifierCopy
{
    void FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc);
};
template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);
struct NiPSysModifierLoadBinary_StandIn
{
    void LoadBinary(NiStream& stream);
};
struct NiColorALoadBinary_StandIn
{
    void LoadBinary(NiStream& stream);
};
struct FUN_00c60850_Class : public NiPSysModifier
{
    void FUN_00c60850(NiStream& stream);
};
struct MyIsEqual
{
    bool __thiscall FUN_00c31830(NiObject*);
};
struct FUN_004a4cc0_shell
{
    bool __thiscall FUN_004a4cc0(void*);
};
struct FUN_00c60a10_Class
{
    unsigned char m_00[0x48];
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;

    bool __thiscall FUN_00c60a10(NiObject*);
};
void __cdecl FUN_00c31750(void);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c60d10_Class
{
    void FUN_00c31750();
    void* __thiscall FUN_00c60d10(unsigned int flags);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct FUN_00c612b0_Class : NiAVObject, A51BF0Base
{
    unsigned char m_data[19];

    FUN_00c612b0_Class();
};
extern NiFixedString DAT_011f49e0;
NiAVObject* __cdecl FUN_00c61510();
struct FUN_00a7b330_shell
{
    void FUN_00a7b330(void* a, void* b);
};
struct FUN_00c61830_class
{
    void FUN_00c61830(void* a, void* b);
};
struct FUN_00c62390_class
{
    void FUN_00c62390(void*, void*);
};
struct FUN_00c61ba0_class : FUN_00c62390_class
{
    void ForwardToBase(void* a, void* b, void* c);
};
template <class T> void ReadBinaryValue(NiStream&, T&);
struct NiPSysModifierStub
{
    virtual void LoadBinary(NiStream&);
};
struct FUN_00c63900_class : NiPSysModifierStub
{
    void LoadModifierData(NiStream& stream);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c31750_Class
{
    void __thiscall FUN_00c31750();
};
struct FUN_00c63a70_Class
{
    void* __thiscall FUN_00c63a70(unsigned int flags);
};
struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool FUN_00c64500(const void* arg);
};
struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};
int __cdecl __stricmp(const char*, const char*);
struct FUN_00c64980_Class : A46BB0Object
{
    bool FUN_00c64980(A46BB0Object* arg);
};
struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(unsigned int);
};
struct FUN_00c64dc0_Class
{
    char m_iWordAt00;
    char m_cByteAtOffset1;
    char m_cByteAtOffset2;
    char m_cByteAtOffset3;
    FUN_0043ba10_shell m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_0043ba10_shell* FUN_00c64dc0(unsigned int a);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64e70_Class
{
    void __thiscall FUN_00c64e70();
    void* __thiscall FUN_00c65650(unsigned int flags);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
SpawnedObject_b9118* FUN_00c607d0();
class C61330Base
{
  public:
    C61330Base(int iA, int iB);
    virtual ~C61330Base();

    int unk04;
};
class FUN_00c61330 : public C61330Base
{
  public:
    void Initialize();

    FUN_00c61330(int iA, int iB);
    virtual ~FUN_00c61330();
};
struct FUN_00c61c50_sub
{
    void FUN_00c628c0(unsigned int n);
    void FUN_00c62b90(unsigned int n, unsigned int* p);
};
struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void FUN_00c31b10(unsigned int a, unsigned int b);
    void FUN_00c61c50(unsigned int x, unsigned int y);
};
struct FUN_00c62140_Elem;
struct FUN_00c62140_Item;
struct FUN_00c62140_Val
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};
struct FUN_00c62140_Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    void FUN_00a59c60(FUN_00c62140_Val* pVal);
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
    FUN_00c62140_Elem** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct FUN_00c62140_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c62140_Item* v03();
};
struct FUN_00c62140_Pad
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct FUN_00c62140_Pad5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
struct FUN_00c62140_Sub
{
    void FUN_00c62f40();
};
struct FUN_00c62140_cls
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
    FUN_00c62140_Obj* m_54;
    int unk58;
    FUN_00c62140_Sub m_5c;

    void FUN_00c62140();
    void FUN_00c62200(FUN_00c62140_Elem* pElem);
};
struct S_00c62cc0_Class
{
    void* unk0;
    void* unk4;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short unk_c;
    unsigned short m_usTrailingValue;

    void FUN_00c628c0(unsigned int arg);
    void FUN_00c62b90(unsigned int arg1, unsigned int arg2);
    unsigned int FUN_00c62cc0(unsigned int arg);
};
struct S_00c62cc0_Locals
{
    unsigned int value;
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
};
// FUN_00c634b0: thiscall (this in ecx), 2 stack params (a1 pointer, unsigned short index).
class XVec12
{
  public:
    float m_00;
    float m_04;
    float m_08;
};
class XSub30
{
  public:
    unsigned int unk00;
    unsigned int Call0045bb20(XVec12* out);
};
class XItem12
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Call004578c0(unsigned int r, float f);
};
class XItem28
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    void Call0063c8a0(XSub30* arg);
};
class XObj70
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    XItem12* m_20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68, unk6c;
    XItem28* m_70;
};
class FUN_00c634b0_cls
{
  public:
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    XSub30 m_30;
    void FUN_00c634b0(XObj70* a1, unsigned short idx);
};
struct NiPoint3_c
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
extern NiPoint3_c NiPoint3_ZERO;
struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3_c v;
    void ResetVector();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
PositionModifierObject_b9439* CreatePositionModifierObject();
struct Pad32
{
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7;
};
struct ArgObj
{
    void FUN_0096a610(void* p);
};
struct FUN_00c63a00_cls
{
    void FUN_00c319e0(void* a);
    void FUN_00c63a00(ArgObj* a1);
};
unsigned int __cdecl FUN_00a7d330(unsigned int v);
unsigned int __cdecl FUN_00a7d550(const char* name, float f);
struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void __thiscall FUN_00a9a4e0(int arg);
    void __thiscall FUN_00c643d0(int arg);
};
extern "C" void __cdecl FUN_00a303a0(int arg, void* object);
extern "C" void __cdecl FUN_00a417b0(int arg, void* data, int count);
class FUN_00c64b90_target;
class FUN_00c64b90_item
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};
class FUN_00c64b90_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(unsigned int value);
};
class FUN_00c64b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00c64b90_item** m_0c;
    int unk10;
    unsigned short m_14;
    void FUN_00c64b90(FUN_00c64b90_target* a1);
    void FUN_00a89af0(FUN_00c64b90_target* a1);
};
void __cdecl FUN_0044adf0(FUN_00c64b90_target* a1, unsigned int* p);
struct FUN_00c64da0_cls
{
    int unk00;
    void Callee0043ba10(int a);
    void FUN_00c64da0(int a);
};
struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(int a8, int cc);
};
struct ItemCallee_c64
{
    void FUN_00c65490(int a1, int a2);
};
struct FUN_00c65180_VTable
{
    virtual void FUN_00c65180_v0();
    virtual void FUN_00c65180_v1();
    virtual void FUN_00c65180_v2();
    virtual void FUN_00c65180_v3();
    virtual void FUN_00c65180_v4();
    virtual void FUN_00c65180_v5();
    virtual void FUN_00c65180_v6();
    virtual void FUN_00c65180_v7();
    virtual void FUN_00c65180_v8(void* p);
};
struct FUN_00c65180_Class
{
    unsigned char __thiscall FUN_00a7b290(FUN_00c65180_VTable* p);

    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char __thiscall VisitEntries(FUN_00c65180_VTable* p);
};

extern char* DAT_0109b220;
extern int DAT_010c3384;
struct NiGlobalStringTable
{
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* handle;
    __forceinline NiFixedString(const char* value)
    {
        if (!value)
            handle = DAT_0109b220;
        else
            handle = NiGlobalStringTable::AddString(value);
    }
    __forceinline ~NiFixedString()
    {
        if (handle == DAT_0109b220)
            return;
        long* count = reinterpret_cast<long*>(handle - 8);
        InterlockedDecrement(count);
    }
};
struct Color316
{
    float r, g, b, a;
};
struct Base316
{
    virtual void vf0();
    int unk04, unk08, unk0c, unk10, unk14;
    Base316(const NiFixedString&, unsigned int);
};
struct FUN_00c60100 : Base316
{
    Color316 first, second, third;
    float f48, f4c, f50, f54, f58, f5c;
    FUN_00c60100(const char*, const Color316&, const Color316&, const Color316&, float, float, float, float, float,
                 float);
};
// @fnv 0x00c60100
FUN_00c60100::FUN_00c60100(const char* name, const Color316& c1, const Color316& c2, const Color316& c3, float a,
                           float b, float c, float d, float e, float f)
    : Base316(NiFixedString(name), 3000), first(c1), second(c2), third(c3), f48(a), f4c(b), f50(c), f54(d), f58(e),
      f5c(f)
{}

struct EmitBaseB10
{
    virtual ~EmitBaseB10();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50, unk54;
    EmitBaseB10();
};
struct PrimArrayBaseB10
{
    virtual ~PrimArrayBaseB10();
    void* m_data;
    unsigned short m_pRayCursor, m_iElementCount, m_uiItemCount, m_growBy;
    PrimArrayBaseB10(unsigned short initial, unsigned short grow)
    {
        m_pRayCursor = initial;
        m_growBy = grow;
        m_iElementCount = 0;
        m_uiItemCount = 0;
        if (m_pRayCursor > 0)
        {
            unsigned int uiBytes = m_pRayCursor * 4;
            m_data = NiMalloc(uiBytes);
        }
        else
            m_data = 0;
    }
};
template <class T> struct PrimArrayB10 : PrimArrayBaseB10
{
    PrimArrayB10(unsigned short capacity = 0, unsigned short grow = 1) : PrimArrayBaseB10(capacity, grow)
    {}
};
namespace emitB10 {
struct FUN_00c61b10 : EmitBaseB10
{
    unsigned int unk58;
    PrimArrayB10<void*> m_kThirdFollowingStreamField;
    virtual ~FUN_00c61b10();
    FUN_00c61b10();
};
// @fnv 0x00c61b10
FUN_00c61b10::FUN_00c61b10() : unk58(2), m_kThirdFollowingStreamField(0, 1)
{}
}

extern char* g_pcEmptyString;

class NiPSysPositionModifierBase
{
  public:
    NiPSysPositionModifierBase(const NiFixedString& kName, unsigned int uiOrder);
    virtual void v00();
    unsigned int m_04;
    char* m_pcName;
    unsigned int m_uiUpdateOrder;
    unsigned int m_uiValue1;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
};
class FUN_00c633b0 : public NiPSysPositionModifierBase
{
  public:
    FUN_00c633b0(const char* pcName);
    float m_f18;
    int m_1c;
    float m_f20;
    NiPoint3_c m_kPoint24;
    NiPoint3_c m_kPoint30;
};
// @fnv 0x00c633b0
FUN_00c633b0::FUN_00c633b0(const char* pcName) : NiPSysPositionModifierBase(NiFixedString(pcName), 0xbb8)
{
    m_kPoint24 = NiPoint3_ZERO;
    m_kPoint30 = NiPoint3_ZERO;
    m_f20 = 0.0f;
    m_f18 = 0.0f;
}

struct NiRTTI645
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern NiRTTI645 DAT_011f4428;

char* __cdecl FUN_00a7d330(const char* pcText);
void* NiMalloc645(unsigned int uiSize);
void NiFree645(void* p);

template <class T> struct PrimArray645
{
    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc645(sizeof(T) * auiCount);
    }
    void SetSize(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned int i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != T(0))
                {
                    m_pBase[i] = T(0);
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        T* pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = Allocate(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = T(0);
        }
        else
        {
            m_pBase = 0;
        }
        NiFree645(pSaveBase);
    }
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int FUN_0096a610(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef PrimArray645<char*> ViewerStrings645;

struct Parent645
{
    void FUN_00a99d70(ViewerStrings645* pkStrings);
};

struct Obj645 : Parent645
{
    void FUN_00c645c0(ViewerStrings645* pkStrings);
};

// @fnv 0x00c645c0
void Obj645::FUN_00c645c0(ViewerStrings645* pkStrings)
{
    Parent645::FUN_00a99d70(pkStrings);
    pkStrings->FUN_0096a610(FUN_00a7d330(DAT_011f4428.GetName()));
}

extern const char* DAT_012043ec;
void* NiMalloc64d(unsigned int uiSize);

struct ModBase64d
{
    virtual void V00();
    int m_04;
    int m_08;
    ModBase64d(const char* pcName);
    ~ModBase64d();
};

struct ArrBase64d
{
    virtual void V00();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    static void* Allocate(unsigned int auiCount)
    {
        return NiMalloc64d(4 * auiCount);
    }
    ArrBase64d(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
        {
            m_pBase = Allocate(m_usMaxSize);
        }
        else
        {
            m_pBase = 0;
        }
    }
};

struct Arr64d : ArrBase64d
{
    Arr64d(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : ArrBase64d(uiMaxSize, uiGrowBy)
    {}
    virtual void V00();
};

inline const char* GetDefaultName64d()
{
    return DAT_012043ec;
}

struct FUN_00c64de0 : ModBase64d
{
    Arr64d m_kArray;
    FUN_00c64de0();
    virtual void V00();
};

// @fnv 0x00c64de0
FUN_00c64de0::FUN_00c64de0() : ModBase64d(GetDefaultName64d())
{}

namespace fnv_00c60b20 {
extern const char str_010c3494[];
extern const char str_010c3480[];
extern const char str_010c3470[];
extern const char str_010c345c[];
extern const char str_010c3450[];
extern const char str_010c3440[];
extern const char str_010c3438[];
extern const char str_010c3430[];
extern const char str_010c3428[];

struct ViewerStrings
{
    void FUN_0096a610(const unsigned int& s);
};

struct RTTI_Stub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};

char* __cdecl FUN_00a7d330(const char* name);

unsigned int __cdecl strlen(const char*);
void* __cdecl FUN_00aa1070(unsigned int);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
extern const char str_0109dcec[];
extern const char str_0109c360[];
inline unsigned int __cdecl FUN_00a7d550(const char* label, float value)
{
    unsigned int length = strlen(label) + 20;
    char* result = static_cast<char*>(FUN_00aa1070(length));
    FUN_00a305b0(result, length, str_0109dcec, value);
    return reinterpret_cast<unsigned int>(result);
}

extern const char str_0109dca0[];
inline char* __cdecl FUN_00a7d330(const char* name)
{
    char* result = static_cast<char*>(FUN_00aa1070(strlen(name) + 9));
    FUN_00a305b0(result, strlen(name) + 9, str_0109dca0, name);
    return result;
}

struct ColorA_Stub
{
    float r;
    float g;
    float b;
    float a;
    char* ToString(const char* label)
    {
        unsigned int length = strlen(label) + 36;
        char* result = static_cast<char*>(FUN_00aa1070(length));
        FUN_00a305b0(result, length, str_0109c360, r, g, b, a);
        return result;
    }
};

struct ModifierBase_Stub
{
    void FUN_00c319e0(ViewerStrings* strings);
};

struct SimpleColorModifier_Stub : ModifierBase_Stub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ColorA_Stub color1;
    ColorA_Stub color2;
    ColorA_Stub color3;
    float fadeIn;
    float fadeOut;
    float color1End;
    float color2Start;
    float color2End;
    float color3Start;

    void FUN_00c60b20(ViewerStrings* strings);
};

// @fnv 0x00c60b20
void SimpleColorModifier_Stub::FUN_00c60b20(ViewerStrings* strings)
{
    ModifierBase_Stub::FUN_00c319e0(strings);
    strings->FUN_0096a610((unsigned int)FUN_00a7d330(reinterpret_cast<RTTI_Stub*>(&g_01204390)->GetName()));
    strings->FUN_0096a610((unsigned int)FUN_00a7d550(str_010c3494, color1End * 100.0));
    strings->FUN_0096a610((unsigned int)FUN_00a7d550(str_010c3480, color2Start * 100.0));
    strings->FUN_0096a610((unsigned int)FUN_00a7d550(str_010c3470, color2End * 100.0));
    strings->FUN_0096a610((unsigned int)FUN_00a7d550(str_010c345c, color3Start * 100.0));
    strings->FUN_0096a610((unsigned int)FUN_00a7d550(str_010c3450, fadeIn * 100.0));
    strings->FUN_0096a610((unsigned int)FUN_00a7d550(str_010c3440, fadeOut * 100.0));
    strings->FUN_0096a610((unsigned int)color1.ToString(str_010c3438));
    strings->FUN_0096a610((unsigned int)color2.ToString(str_010c3430));
    strings->FUN_0096a610((unsigned int)color3.ToString(str_010c3428));
}
}  // namespace fnv_00c60b20

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct CmpRefObject
{
    virtual ~CmpRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct CmpPtr
{
    CmpRefObject* m_pObject;
    CmpPtr(CmpRefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~CmpPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    CmpPtr& operator=(const CmpPtr& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const CmpPtr& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

struct CmpPtrArray
{
    virtual ~CmpPtrArray();
    CmpPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    static CmpPtr* Allocate(unsigned int auiCount)
    {
        return (CmpPtr*)NiMalloc(sizeof(CmpPtr) * auiCount);
    }
    void FUN_00c63030();
};

// @fnv 0x00c63030
void CmpPtrArray::FUN_00c63030()
{
    if (m_usESize == m_usSize)
        return;

    if (m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] != CmpPtr(0))
            {
                if (m_pBase[j] != m_pBase[i])
                    m_pBase[j] = m_pBase[i];
                j++;
            }
        }
    }

    CmpPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = Allocate(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}

class NiPoint3
{
  public:
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& b) const
    {
        return NiPoint3(x - b.x, y - b.y, z - b.z);
    }
    NiPoint3 operator/(float f) const
    {
        float reciprocal = 1.0f / f;
        return NiPoint3(x * reciprocal, y * reciprocal, z * reciprocal);
    }
    NiPoint3& operator+=(const NiPoint3& b);
    bool operator!=(const NiPoint3& b);
    __forceinline bool operator==(const NiPoint3& b) const
    {
        return x == b.x && y == b.y && z == b.z;
    }
};

inline NiPoint3 operator*(float f, const NiPoint3& b)
{
    return NiPoint3(f * b.x, f * b.y, f * b.z);
}
extern unsigned char DAT_011f426c;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;
struct MovingObject
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
    NiPoint3 position;
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MovingObject* object;
    inline MovingObject* GetObject() const
    {
        const Owner* source = this;
        return source->object;
    }
};
struct Particle
{
    NiPoint3 position;
    int unk0c, unk10, unk14, unk18;
};
struct System
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
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle* particles;
    __forceinline unsigned short GetCount() const
    {
        return count;
    }
};
struct Modifier
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
    virtual void Reset();
    int unk04, unk08, unk0c;
    Owner* owner;
    int unk14;
    float elapsed, lastTime, scale;
    NiPoint3 previous, offset;
    void FUN_00c63520(float time, System* system);
};
// @fnv 0x00c63520
void Modifier::FUN_00c63520(float time, System* system)
{
    if (!system->GetCount())
        return;
    MovingObject* object5 = owner->GetObject();
    if (!object5)
    {
        Reset();
        return;
    }
    if (previous == (*reinterpret_cast<const NiPoint3*>(&DAT_011f426c)))
    {
        offset = (*reinterpret_cast<const NiPoint3*>(&DAT_011f426c));
        lastTime = time;
        previous = object5->position;
    }
    unsigned int count2 = system->GetCount();
    NiPoint3 position = object5->position;
    float delta8 = time - lastTime;
    if (delta8 != 0.0)
    {
        NiPoint3 movement = (scale * (position - previous)) / delta8;
        NiPoint3 difference2 = movement - offset;
        if (difference2 != (*reinterpret_cast<const NiPoint3*>(&DAT_011f426c)))
        {
            Particle* particle = system->particles;
            while (count2--)
            {
                particle->position += difference2;
                ++particle;
            }
        }
        offset = movement;
    }
    elapsed = delta8;
    lastTime = time;
    previous = position;
}

struct PoolX
{
    void* FUN_00aa3e40(unsigned n);
};
extern PoolX DAT_011f6238;
struct V3
{
    float x, y, z;
};
struct FUN_00c64640
{
    unsigned short m_usPassCountLocal;
    short pad;
    V3 a[8];
    V3 b[8];
    FUN_00c64640();
    static void* operator new(unsigned n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
};
struct BaseX
{
    void FUN_00a99c40(BaseX* p, int a);
};
struct ObjX : BaseX
{
    int pad[4];
    unsigned short m10;
    FUN_00c64640* m14[1];
    void FUN_00c640f0(ObjX* p, int a);
};
inline void DbgX()
{
    const char* a;
    const char* b;
    const char* c;
    const char* d;
    const char* e;
}
// @fnv 0x00c640f0
void ObjX::FUN_00c640f0(ObjX* p, int a)
{
    FUN_00a99c40(p, a);
    p->m10 = m10;
    for (int i = 0; i < m10; i++)
    {
        p->m14[i] = new FUN_00c64640;
        p->m14[i]->m_usPassCountLocal = m14[i]->m_usPassCountLocal;
        for (int j = 0; j < m14[i]->m_usPassCountLocal; j++)
        {
            p->m14[i]->a[j] = m14[i]->a[j];
            p->m14[i]->b[j] = m14[i]->b[j];
        }
    }
    DbgX();
}

namespace fnv_00c64270 {
struct StreamY;
struct MemMgrY
{
    void* FUN_00aa3e40(unsigned int uiSize);
};
extern MemMgrY DAT_011f6238;
struct Pt3Y
{
    float x, y, z;
};
void FUN_00a30370(StreamY& kStream, unsigned short* pusVal);
void ReadElements(StreamY& kStream, float* pfVals, unsigned int ItemUpdateArray);
inline void ReadPointsFromFile(StreamY& kStream, Pt3Y* pkPts, unsigned int uiElementCount)
{
    ReadElements(kStream, &pkPts->x, uiElementCount * 3);
}
struct FUN_00c64640
{
    unsigned short m_usNum;
    Pt3Y m_akA[8];
    Pt3Y m_akB[8];
    FUN_00c64640();
    static void* operator new(unsigned int uiSize)
    {
        int aiD[5];
        return DAT_011f6238.FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* pv);
};
struct BaseY
{
    void FUN_00a99d30(StreamY& kStream);
    int m_ai[4];
};
struct ObjY : BaseY
{
    unsigned short m_usElementCount;
    FUN_00c64640* m_apRecs[1];
    void FUN_00c64270(StreamY& kStream);
};
// @fnv 0x00c64270
void ObjY::FUN_00c64270(StreamY& kStream)
{
    FUN_00a99d30(kStream);
    FUN_00a30370(kStream, &m_usElementCount);
    for (int i = 0; i < m_usElementCount; i++)
    {
        m_apRecs[i] = new FUN_00c64640;
        FUN_00a30370(kStream, &m_apRecs[i]->m_usNum);
        ReadPointsFromFile(kStream, m_apRecs[i]->m_akA, m_apRecs[i]->m_usNum);
        ReadPointsFromFile(kStream, m_apRecs[i]->m_akB, m_apRecs[i]->m_usNum);
    }
}
}  // namespace fnv_00c64270

namespace fnv_00c65040 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pl);
extern char* DAT_0109b220;
struct FStrX
{
    char* m_kHandle;
    FStrX()
    {
        m_kHandle = DAT_0109b220;
    }
    ~FStrX()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        long* plRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(plRef);
    }
};
struct StreamX
{
    void FUN_00a64df0(FStrX& kStr);
};
void FUN_00a26df0(StreamX& kStream, unsigned int& uiVal);
struct MapX
{
    void FUN_00c4c920(unsigned int uiSize);
};
struct BaseX
{
    void FUN_00a7b4a0(StreamX& kStream);
};
struct ObjM : BaseX
{
    int m_i0, m_i4, m_i8;
    MapX m_kFormatEntries;
    void FUN_00c65490(FStrX& kKey, FStrX& kVal);
    void Insert(FStrX& kKey, FStrX& kVal)
    {
        int aiD[3];
        FUN_00c65490(kKey, kVal);
    }
    void FUN_00c65040(StreamX& kStream);
};
// @fnv 0x00c65040
void ObjM::FUN_00c65040(StreamX& kStream)
{
    FUN_00a7b4a0(kStream);
    unsigned int ItemUpdateArray = 0;
    FUN_00a26df0(kStream, ItemUpdateArray);
    m_kFormatEntries.FUN_00c4c920(ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        FStrX kKey;
        FStrX kVal;
        kStream.FUN_00a64df0(kKey);
        kStream.FUN_00a64df0(kVal);
        Insert(kKey, kVal);
    }
}
}  // namespace fnv_00c65040

// BSWArray derives from NiIntegersExtraData, which owns a count and int buffer.
struct ExtraData244
{
    virtual ~ExtraData244();
    int references;
    void* name;
    ExtraData244();
};
struct IntegerExtraData244 : ExtraData244
{
    unsigned int count;
    int* values;
    virtual ~IntegerExtraData244();
    IntegerExtraData244()
    {
        values = 0;
        count = 0;
    }
};
struct FUN_00c612b0 : IntegerExtraData244
{
    virtual ~FUN_00c612b0();
    void FUN_00c61610();
    FUN_00c612b0();
};
// @fnv 0x00c612b0
FUN_00c612b0::FUN_00c612b0()
{
    FUN_00c61610();
}

struct C616Node
{
    int m_unk00;
    C616Node* m_pNext;
};

struct C616Obj
{
    virtual void* v0();
    virtual void* v1();
    virtual C616Node* GetList();
};

struct C616Host
{
    C616Obj* FUN_00a5bdd0(NiFixedString* key);
};

extern NiFixedString* DAT_012043a0;
extern "C" void* g_012043a4;

inline bool C616Contains(C616Node* node)
{
    while (node != 0)
    {
        if ((void*)node == (void*)&g_012043a4)
            return true;
        node = node->m_pNext;
    }
    return false;
}

// @fnv 0x00c61630
void* FUN_00c61630(C616Host* host)
{
    void* result2 = 0;
    if (host != 0)
    {
        NiFixedString* key = DAT_012043a0;
        C616Obj* obj2 = host->FUN_00a5bdd0(key);
        if (obj2 == 0)
        {
            result2 = 0;
        }
        else
        {
            result2 = C616Contains(obj2->GetList()) ? (void*)obj2 : 0;
        }
    }
    return result2;
}

namespace fnv_00c616c0 {
struct MemMgr
{
    void* FUN_00aa3e40(int size);
};

extern MemMgr DAT_011f6238;
extern char str_010c3610[];
extern "C" void* g_0109b220;

char* __cdecl FUN_00a5b690(const char* arg);

struct NiFixedString
{
    char* m_pData;
    __forceinline void* operator new(unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
    __forceinline NiFixedString(const char* s)
    {
        if (s == 0)
            m_pData = (char*)g_0109b220;
        else
            m_pData = FUN_00a5b690(s);
    }
};

extern "C" void* g_012043a0;

// @fnv 0x00c616c0
void __cdecl FUN_00c616c0()
{
    g_012043a0 = new NiFixedString(str_010c3610);
}
}  // namespace fnv_00c616c0

struct Quad16
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};

struct SubBase
{
    SubBase(unsigned short x, unsigned short y);
    virtual ~SubBase();
    int m_data;
    unsigned short m_uiX;
    unsigned short m_uiY;
};

struct SubObj : SubBase
{
    SubObj() : SubBase(0, 1)
    {}
    virtual ~SubObj();
};

struct BaseObj
{
    BaseObj(int a, int b, float f0, float f1, float f2, float f3, float f4, float f5, Quad16 q, float g0, float g1,
            float g2, float g3);
    virtual ~BaseObj();
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
    void FUN_00c62140();
};

struct FUN_00c61a10 : BaseObj
{
    int m_58;
    SubObj m_5c;
    FUN_00c61a10(int p1, int p2, int p3, float f0, float f1, float f2, float f3, float f4, float f5, Quad16 q, float g0,
                 float g1, float g2, float g3);
    virtual ~FUN_00c61a10();
};

// @fnv 0x00c61a10
FUN_00c61a10::FUN_00c61a10(int p1, int p2, int p3, float f0, float f1, float f2, float f3, float f4, float f5, Quad16 q,
                           float g0, float g1, float g2, float g3)
    : BaseObj(p1, p2, f0, f1, f2, f3, f4, f5, q, g0, g1, g2, g3), m_58(p3)
{
    SubObj* sub;
    FUN_00c62140();
}

struct RefObj62
{
    virtual void V0();
    virtual void DeleteThis();
    int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct FixedStr62
{
    const char* m_kHandle;
    const char* GetHandle() const
    {
        return m_kHandle;
    }
};
struct Node62;
struct AVObj62 : RefObj62
{
    virtual void V8();
    virtual Node62* IsNode62();
    virtual void V10();
    virtual void V14();
    virtual AVObj62* V18();
    void* GetExtraData(const char* kKey);
};
struct Node62
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
    NiPointer<AVObj62>* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    NiPointer<AVObj62>& GetAt(unsigned int index)
    {
        return m_pBase[index];
    }
};
extern FixedStr62 g_kExtraName62;
struct Item62
{
    Item62* m_pkNext;
    Item62* m_pkPrev;
    NiPointer<AVObj62> m_element;
    void SetElement(const NiPointer<AVObj62>& p);
};
struct List62
{
    Item62* m_pkHead;
    Item62* m_pkTail;
    unsigned int m_uiCount;
    Item62* NewItem();
    void* Add62(const NiPointer<AVObj62>& p)
    {
        Item62* pkItem = NewItem();
        pkItem->SetElement(p);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        ++m_uiCount;
        return pkItem;
    }
};
struct Collector62
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
    AVObj62* unk54;
    int unk58;
    List62 unk5c;
    int GetMode() const
    {
        return unk58;
    }
    void FUN_00c62200(AVObj62* pkObj);
};

// @fnv 0x00c62200
void Collector62::FUN_00c62200(AVObj62* pkObj)
{
    if (pkObj)
    {
        Node62* pkNode2 = pkObj->IsNode62();
        AVObj62* pkExcl = unk54;
        if (pkObj == pkExcl)
            return;
        bool bAdd2;
        switch (GetMode())
        {
        case 0:
            bAdd2 = bool(pkObj->V18());
            break;
        case 1:
            bAdd2 = pkObj->GetExtraData(g_kExtraName62.GetHandle()) != 0;
            break;
        default:
            bAdd2 = pkNode2 != 0;
            break;
        }
        if (bAdd2)
        {
            unk5c.Add62(pkObj);
        }
        if (pkNode2)
        {
            unsigned int i2 = pkNode2->GetSize();
            while (i2--)
                FUN_00c62200(pkNode2->GetAt(i2));
        }
    }
}

extern double DAT_01029790;
int __cdecl FUN_00ecadb8();

inline float UnitRandom()
{
    return (float)(FUN_00ecadb8() / DAT_01029790);
}

class FUN_00c62390_cls
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
    int m_58;
    int unk5C;
    void** m_60;
    unsigned short unk64;
    unsigned short m_66;

    int GetMode() const
    {
        return m_58;
    }
    void* GetAt(unsigned int i)
    {
        void*& r = m_60[i];
        return r;
    }
    void FUN_00c625f0(void* a, void* b, void* c);
    void FUN_00c62470(void* a, void* b, void* c);
    void FUN_00c62390(void* a1, void* a2);
};

// @fnv 0x00c62390
void FUN_00c62390_cls::FUN_00c62390(void* a1, void* a2)
{
    void* pick;
    unsigned int n = m_66;
    if (n != 0)
    {
        unsigned int idx = (unsigned int)((double)n * UnitRandom());
        if (idx == n)
        {
            idx--;
        }
        pick = GetAt(idx);
    }
    else
    {
        pick = 0;
    }
    switch (GetMode())
    {
    case 0:
        FUN_00c625f0(pick, a1, a2);
        break;
    default:
        FUN_00c62470(pick, a1, a2);
        break;
    }
}

namespace fnv_00c625f0 {
extern int __cdecl FUN_00ecadb8(void);
extern double DAT_01029790;
float FUN_004579e0(float);

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3& operator*=(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }
    NiPoint3 operator*(float scale) const
    {
        return NiPoint3(scale * x, scale * y, scale * z);
    }
    float Length() const
    {
        float squared = x * x + y * y + z * z;
        return FUN_004579e0(squared);
    }
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

struct Matrix9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 FUN_004b4500(const NiPoint3& point)
    {
        return NiPoint3(m00 * point.x + m01 * point.y + m02 * point.z, m10 * point.x + m11 * point.y + m12 * point.z,
                        m20 * point.x + m21 * point.y + m22 * point.z);
    }
};

struct GeometryData
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
    virtual unsigned short GetVertexCount();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* vertices;
    NiPoint3* normals;
};

struct Geometry
{
    void** vtable;
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
    struct DataPtr
    {
        GeometryData* object;
        GeometryData* operator->() const
        {
            return object;
        }
    } modelData;
    NiPoint3* GetVertices() const
    {
        return modelData->vertices;
    }
    NiPoint3* GetNormals() const
    {
        return modelData->normals;
    }
};

struct EmitterObject
{
    void** vtable;
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
    Matrix9 rotation;
    int unk8c;
    int unk90;
    int unk94;
    float scale;
    float GetScale() const
    {
        return scale;
    }
};

typedef Geometry*(__thiscall* GetGeometryFunction)(EmitterObject*);
typedef unsigned short(__thiscall* GetVertexCountFunction)(GeometryData*);

struct EmitterSampler
{
    void FUN_00c625f0(EmitterObject* object, NiPoint3& position, NiPoint3& direction);
};

// @fnv 0x00c625f0
void EmitterSampler::FUN_00c625f0(EmitterObject* object, NiPoint3& position, NiPoint3& direction)
{
    Geometry* geometry = object ? ((GetGeometryFunction)object->vtable[6])(object) : 0;
    if (geometry)
    {
        unsigned short count = geometry->modelData->GetVertexCount();
        int index = (unsigned int)((double)count * (float)(FUN_00ecadb8() / DAT_01029790));
        if (index == count)
            index--;
        position = geometry->GetVertices()[index];
        position *= object->GetScale();
        if (geometry->GetNormals())
        {
            NiPoint3 normal = geometry->GetNormals()[index];
            normal = object->rotation.FUN_004b4500(normal);
            direction = normal * direction.Length();
        }
    }
    else
    {
        position = *(NiPoint3*)&_NiPoint3_ZERO;
    }
}
}  // namespace fnv_00c625f0

void __cdecl FUN_00aa10f0(void* p);

struct S00c62800_Arr
{
    int vptr;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline ~S00c62800_Arr();
};

__forceinline S00c62800_Arr::~S00c62800_Arr()
{
    *(int*)this = (int)&DAT_010c377c;
    void* data = m_data;
    FUN_00aa10f0(data);
}

struct S00c62800_Base
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
    __forceinline ~S00c62800_Base();
};

__forceinline S00c62800_Base::~S00c62800_Base()
{
    ((FUN_00c31750_Class*)this)->FUN_00c31750();
}

struct S00c62800_Obj : S00c62800_Base
{
    S00c62800_Arr m_aiIndexedValues;
    __forceinline ~S00c62800_Obj();
    void* __thiscall FUN_00c62800(unsigned int flags);
};

__forceinline S00c62800_Obj::~S00c62800_Obj()
{}

// @fnv 0x00c62800
void* __thiscall S00c62800_Obj::FUN_00c62800(unsigned int flags)
{
    this->S00c62800_Obj::~S00c62800_Obj();
    if (flags & 1)
        operator delete(this, 0x6c);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void __cdecl NiFree(void* p);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    __forceinline NiPtr(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPtr<T>& operator=(const NiPtr<T>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    __forceinline bool operator!=(const NiPtr<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

template <class T> struct MallocIf
{
    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc(sizeof(T) * auiCount);
    }
};

template <class T> class PtrArray
{
  public:
    virtual ~PtrArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00c628c0(unsigned int uiMaxSize);
};

// @fnv 0x00c628c0
template <class T> void PtrArray<T>::FUN_00c628c0(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                m_pBase[i] = T(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    T* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = MallocIf<T>::Allocate(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = T(0);
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}

template class PtrArray<NiPtr<RefObj> >;

struct RefC62
{
    virtual void v00();
    virtual void v04();
    volatile long m_04;
    void Inc()
    {
        InterlockedIncrement(&m_04);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&m_04))
            v04();
    }
};
struct PtrC62
{
    RefC62* m_00;
    PtrC62(RefC62* p = 0)
    {
        m_00 = p;
        if (m_00)
            m_00->Inc();
    }
    PtrC62(const PtrC62& p)
    {
        m_00 = p.m_00;
        if (m_00)
            m_00->Inc();
    }
    ~PtrC62()
    {
        if (m_00)
            m_00->Dec();
    }
    PtrC62& operator=(const PtrC62&);
    bool operator!=(const PtrC62& p) const
    {
        return m_00 != p.m_00;
    }
};
struct ArrayC62
{
    void* m_00;
    PtrC62* m_04;
    unsigned short m_08, m_0a, m_0c, m_0e;
    PtrC62 FUN_00c62d10(unsigned int i);
};
inline void FrameC62()
{
    struct Slots
    {
        unsigned int m_00, m_04;
    } slots;
    (void)&slots;
}
// @fnv 0x00c62d10
PtrC62 ArrayC62::FUN_00c62d10(unsigned int i)
{
    if (i >= m_0a)
        return PtrC62();
    PtrC62 result = m_04[i];
    m_04[i] = PtrC62(), FrameC62();
    if (result != PtrC62())
        --m_0c;
    if (i == (unsigned short)(m_0a - 1))
        --m_0a;
    return result;
}

namespace fnv_00c63c30 {
struct NiAllocator630
{
    virtual void v0();
    virtual void* Allocate(unsigned&, unsigned&, int, bool, bool, int, const char*);
};
struct NiManager630
{
    NiAllocator630* allocator;
};
extern NiManager630* DAT_011f6080;
extern const double DAT_01017cf8;
float FUN_004579e0(float);
extern int DAT_012043d0;
extern int DAT_0109b220;

struct MM630
{
    void* Allocate(unsigned int);
};
extern MM630 g_mm630;

char* __cdecl FUN_00a5b690(const char* s);
int __cdecl FUN_004b75a0(void* p, const char* name);
long __cdecl FUN_00eca6d3(const char* s);

struct StrMem
{
    char* m_pChar;
    unsigned short m_usLen;
    unsigned short m_usMax;
    StrMem(const char* s);
    bool Set(const char* p, unsigned int n);
    char* GetText() const
    {
        return m_pChar;
    }
    unsigned int GetLength() const
    {
        return m_usLen == 0xffff ? (unsigned int)_strlen(GetText()) : (unsigned int)m_usLen;
    }
    ~StrMem()
    {
        Set(0, 0);
    }
};

struct NameHolder
{
    const char* m_pChar;
    __forceinline NameHolder(const char* s)
    {
        if (!s)
            m_pChar = (const char*)DAT_0109b220;
        else
            m_pChar = FUN_00a5b690(s);
    }
    __forceinline static void* operator new(unsigned int n)
    {
        return g_mm630.Allocate(n);
    }
};

struct Vec3
{
    float f[3];

    float Length() const
    {
        float squared = f[0] * f[0] + f[1] * f[1] + f[2] * f[2];
        return FUN_004579e0(squared);
    }
    void FUN_004a0c10()
    {
        float length = Length();
        if (length > DAT_01017cf8)
        {
            float reciprocal = 1.0f / length;
            f[0] *= reciprocal;
            f[1] *= reciprocal;
            f[2] *= reciprocal;
        }
        else
        {
            f[0] = 0;
            f[1] = 0;
            f[2] = 0;
        }
    }
};
struct Mat3
{
    Vec3 r0, r1, r2;
    void GetColumn(unsigned int col, Vec3& out) const
    {
        out.f[0] = r0.f[col];
        out.f[1] = r1.f[col];
        out.f[2] = r2.f[col];
    }
};
struct Child
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
    Mat3 m34;
    Vec3 m58;
};

struct ExtraX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m10;
    unsigned short pad12;
    void* m14[8];
};

extern const Vec3 ZERO;
struct VecGroup
{
    unsigned short m0;
    unsigned short pad2;
    Vec3 m4[8];
    Vec3 m64[8];
    VecGroup()
    {
        Vec3* position = m4;
        Vec3* normal = m64;
        m0 = 0;
        for (int i = 0; i < 8; i++)
        {
            position[i].f[0] = ZERO.f[0];
            position[i].f[1] = ZERO.f[1];
            position[i].f[2] = ZERO.f[2];
            normal[i].f[0] = ZERO.f[0];
            normal[i].f[1] = ZERO.f[1];
            normal[i].f[2] = ZERO.f[2];
        }
    }
    __forceinline static void* operator new(unsigned int n)
    {
        return g_mm630.Allocate(n);
    }
};

extern int DAT_010a0d24, DAT_010c38ac;
struct ExtraRoot
{
    int* vfptr;
    int references;
    void* name;
    ExtraRoot();
};
struct ExtraBinary : ExtraRoot
{
    int value;
    ExtraBinary(int v)
    {
        vfptr = &DAT_010a0d24;
        value = v;
    }
};
struct ExtraList
{
    void* head;
    void* tail;
    unsigned size;
    ExtraList()
    {
        size = 0;
        head = 0;
        tail = 0;
    }
};
struct TESObjectDoorController : ExtraBinary
{
    unsigned short count, unk12;
    void* groups[8];
    ExtraList list;
    TESObjectDoorController(int v) : ExtraBinary(v)
    {
        vfptr = &DAT_010c38ac;
        count = 0;
        for (int i = 0; i < 8; i++)
            groups[i] = 0;
    }
    static void* operator new(unsigned n)
    {
        unsigned size = n ? n : 1;
        unsigned alignment = 4;
        return DAT_011f6080->allocator->Allocate(size, alignment, 1, true, false, -1, 0);
    }
};

struct ChildPtr
{
    Child* object;
    operator Child*() const
    {
        Child* element = object;
        return element;
    }
};
struct ChildArray
{
    ChildPtr* data;
    unsigned short capacity, size, used, grow;
    ChildPtr& GetAt(unsigned int i) const
    {
        return data[i];
    }
};
struct ObjC63
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    int m4;
    char* m8;
    void* GetMesh()
    {
        void* name = m8;
        return name;
    }
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
    ChildArray children;
    ExtraX* GetExtraData(int key);
    bool AddExtraData(int key, ExtraX* p);
};

// @fnv 0x00c63c30
bool __cdecl FUN_00c63c30(ObjC63* obj, ObjC63* root)
{
    if (obj->v0c())
    {
        if (!DAT_012043d0)
            DAT_012043d0 = (int)new NameHolder("DVPG");
        ExtraX* extra = root->GetExtraData(DAT_012043d0);
        ObjC63* p = obj;
        if (p->GetMesh() && FUN_004b75a0(p->GetMesh(), "DecalPlacementVectorGroup"))
        {
            if (!extra)
            {
                extra = (ExtraX*)new TESObjectDoorController(0);
                root->AddExtraData(DAT_012043d0, extra);
            }
            StrMem str4("DecalPlacementVectorGroup");
            const char* suffix3 = (const char*)p->GetMesh();
            suffix3 += str4.GetLength();
            int idx = (int)FUN_00eca6d3(suffix3);
            if ((int)extra->m10 < 8 && idx < 8 && extra->m14[idx] == 0)
            {
                VecGroup* pv = new VecGroup();
                for (int i = 0; i < (int)p->children.used; i++)
                {
                    if (i < 8)
                    {
                        Child* child = (Child*)p->children.GetAt(i);
                        Mat3 m = child->m34;
                        Vec3 v5;
                        m.GetColumn(2, v5);
                        v5.FUN_004a0c10();
                        pv->m4[pv->m0] = child->m58;
                        pv->m64[pv->m0] = v5;
                        pv->m0++;
                    }
                }
                extra->m14[idx] = pv;
                extra->m10++;
            }
            return true;
        }
        else
        {
            unsigned i = 0;
            while (i < p->children.size)
            {
                Child* c = (Child*)p->children.GetAt(i);
                if (c)
                {
                    if (FUN_00c63c30((ObjC63*)c, root))
                        c = 0;
                }
                i++;
            }
        }
    }
    return false;
}
}  // namespace fnv_00c63c30

extern int DAT_010c1364;
class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int);
};
class FUN_00a5d3a0 : public BSFaceGenMorphData
{
  public:
    FUN_00a5d3a0();
    int* vfptr;
    int references;
};
class FactoryObject : public FUN_00a5d3a0
{
  public:
    FactoryObject()
    {
        vfptr = &DAT_010c1364;
        value = 0;
    }
    int value;
};
// @fnv 0x00c64810
FactoryObject* __cdecl FUN_00c64810()
{
    return new FactoryObject;
}

namespace fnv_00c649f0 {
extern int DAT_010c13f4;
extern int DAT_01069d84;
class FUN_00a5d3a0
{
  public:
    virtual void vf00();
    int m_04;
    FUN_00a5d3a0();
    ~FUN_00a5d3a0();
};
class C649F0_SubBase
{
  public:
    void FUN_0068ac40(unsigned int a, unsigned int b);
};
class C649F0_Sub : public C649F0_SubBase
{
  public:
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    __forceinline C649F0_Sub()
    {
        int unused;
        (void)unused;
        FUN_0068ac40(0, 1);
        m_00 = &DAT_01069d84;
    }
};
class C649F0_Object : public FUN_00a5d3a0
{
  public:
    C649F0_Sub m_08;
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    virtual void vf00();
};
// @fnv 0x00c649f0
C649F0_Object* __cdecl FUN_00c649f0()
{
    return new C649F0_Object;
}
}  // namespace fnv_00c649f0

extern int DAT_011f4280;

class FNVListObj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};

class FNVSubHelper
{
  public:
    void __thiscall FUN_00c4c8d0(void* p);
};

class FNVCtxHelper
{
  public:
    void __thiscall GetAt(void* a, void* b);
};

inline bool InList(void*& p)
{
    while (p != 0)
    {
        if (p == (void*)&DAT_011f4280)
            return true;
        p = *(void**)((char*)p + 4);
    }
    return false;
}

class FUN_00c64c40_cls
{
  public:
    bool __thiscall FUN_00c64c40(void* a1, FNVListObj* a2);
};

// @fnv 0x00c64c40
bool FUN_00c64c40_cls::FUN_00c64c40(void* a1, FNVListObj* a2)
{
    void* local2;
    void* m18;
    void* p3;
    bool found2;
    void* r9;
    void* m9;
    {
        void* out;
        {
            unsigned int pad[6];
        }

        if (a2 == 0)
        {
            r9 = 0;
        }
        else
        {
            p3 = a2->v2();
            found2 = InList(p3);
            r9 = (void*)((found2 ? -1 : 0) & (int)a2);
        }

        local2 = r9;
        if (local2 != 0)
        {
            m18 = *(void**)((char*)local2 + 0x18);
            if (m18 != 0)
            {
                m9 = *(void**)((char*)m18 + 8);
                out = 0;
                if (*(void**)((char*)a1 + 0x5c4) != 0 && m9 != 0)
                {
                    static_cast<FNVCtxHelper*>(*(void**)((char*)a1 + 0x5c4))->GetAt(m9, &out);
                }
                if (out != 0)
                {
                    static_cast<FNVSubHelper*>((void*)((char*)this + 8))->FUN_00c4c8d0(&local2);
                    return true;
                }
            }
        }
    }
    return false;
}

namespace fnv_00c64d10 {
struct C64D10_Handle
{
    int m_uiFilterValue;
    C64D10_Handle(const C64D10_Handle& other) : m_uiFilterValue(other.m_uiFilterValue)
    {}
    ~C64D10_Handle();
};
extern C64D10_Handle DAT_0109b220;
struct FUN_00c64d10
{
    C64D10_Handle m_pHeadNode;
    C64D10_Handle m_iSecondInteger;
    FUN_00c64d10(int first, int second);
    void FUN_00c64da0(int value);
    void FUN_00c64dc0(int value);
};
// @fnv 0x00c64d10
FUN_00c64d10::FUN_00c64d10(int first, int second) : m_pHeadNode(DAT_0109b220), m_iSecondInteger(DAT_0109b220)
{
    FUN_00c64da0(first);
    FUN_00c64dc0(second);
}
}  // namespace fnv_00c64d10

extern const char* g_c64e70Empty;
struct C64e70Str
{
    const char* m_kHandle;
    ~C64e70Str()
    {
        if (m_kHandle == g_c64e70Empty)
        {
        }
        else
        {
            long* p = (long*)(m_kHandle - 8);
            InterlockedDecrement(p);
        }
    }
};
struct C64e70Elem
{
    C64e70Str m_name;
    C64e70Str m_target;
    ~C64e70Elem()
    {}
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct C64e70Array
{
    static void Free(C64e70Elem** p)
    {
        NiFree(p);
    }
    virtual ~C64e70Array()
    {
        Free(m_pBase);
    }
    C64e70Elem** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct C64e70Base
{
    virtual ~C64e70Base();
    int unk04;
    int unk08;
};

struct FUN_00c64e70 : C64e70Base
{
    C64e70Array m_ppData;
    virtual ~FUN_00c64e70();
};

// @fnv 0x00c64e70
FUN_00c64e70::~FUN_00c64e70()
{
    unsigned int count = m_ppData.m_usESize;
    for (unsigned int i = 0; i < count; i++)
    {
        delete m_ppData.m_pBase[i];
    }
    m_ppData.RemoveAll();
}

namespace fnv_00c65490 {
struct C65490_Pool
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern C65490_Pool DAT_011f6238;
struct FUN_00c64d10
{
    int m_pHeadNode;
    int m_iSecondInteger;
    FUN_00c64d10(int first, int second);
    static void* operator new(unsigned int size)
    {
        int unused[4];
        (void)unused;
        return DAT_011f6238.FUN_00aa3e40(size);
    }
    static void operator delete(void* p);
};
struct C65490_List
{
    void FUN_00c4c8d0(FUN_00c64d10* const& item);
};
struct C65490_Owner
{
    int unk00;
    int unk04;
    int unk08;
    C65490_List m_kNode;
    void FUN_00c65490(int first, int second);
};
// @fnv 0x00c65490
void C65490_Owner::FUN_00c65490(int first, int second)
{
    FUN_00c64d10* item = new FUN_00c64d10(first, second);
    m_kNode.FUN_00c4c8d0(item);
}
}  // namespace fnv_00c65490

namespace fnv_00c65530 {
struct DynamicMemoryAllocator
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern DynamicMemoryAllocator DAT_011f6238;
extern int DAT_0109b220;
int __cdecl FUN_00a5b690(const char* s);

struct AtpRef
{
    int m_uiFilterValue;
    AtpRef(const char* s)
    {
        if (s == 0)
            m_uiFilterValue = DAT_0109b220;
        else
            m_uiFilterValue = FUN_00a5b690(s);
    }
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
    static void operator delete(void* p)
    {}
};

extern AtpRef* DAT_012043ec;

// @fnv 0x00c65530
void __cdecl FUN_00c65530()
{
    DAT_012043ec = new AtpRef("ATP");
}
}  // namespace fnv_00c65530

namespace fnv_00c655d0 {
extern const char* DAT_0109b220;
struct FixedStringAllocator
{
    void FUN_00aa4060(void*);
};
extern FixedStringAllocator DAT_011f6238;
class NiFixedString
{
  public:
    const char* m_pcString;
    inline ~NiFixedString()
    {
        if (m_pcString == DAT_0109b220)
            return;
        char* block = (char*)m_pcString - 8;
        InterlockedDecrement((long*)block);
    }
    void operator delete(void* p)
    {
        DAT_011f6238.FUN_00aa4060(p);
    }
};
extern NiFixedString* DAT_012043ec;
// @fnv 0x00c655d0
void FUN_00c655d0()
{
    delete DAT_012043ec;
    DAT_012043ec = 0;
}
}  // namespace fnv_00c655d0

void __cdecl FUN_00aa10f0(void* p);
struct FUN_00a7b300
{
    virtual void vf00();
    int m_04;
    int m_08;
    int m_0C;
    ~FUN_00a7b300();
};
struct C613A0_StringsData : FUN_00a7b300
{
    void* m_pData;
    ~C613A0_StringsData()
    {
        FUN_00aa10f0(m_pData);
        m_pData = 0;
    }
};
struct C613A0_Extra : C613A0_StringsData
{
    ~C613A0_Extra();
};
// @fnv 0x00c613a0
C613A0_Extra::~C613A0_Extra()
{}

struct SetAtRefObject
{
    virtual ~SetAtRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

typedef NiPointer<SetAtRefObject> SetAtPointer;

struct SetAtArray
{
    void* m_ppVirtualMethodTable;
    SetAtPointer* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00c62b90(unsigned int uiIndex, const SetAtPointer& element);
};

// @fnv 0x00c62b90
void SetAtArray::FUN_00c62b90(unsigned int uiIndex, const SetAtPointer& element)
{
    static SetAtPointer kNull(0);
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != kNull)
            m_usESize++;
    }
    else
    {
        if (element != kNull)
        {
            if (m_pBase[uiIndex] == kNull)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != kNull)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

extern unsigned int DAT_011c16bc;

extern "C" int(__stdcall* DAT_00fdf1c0)(void*);
extern "C" int(__stdcall* DAT_00fdf1c4)(void*);

class S00c62f40_RefObject
{
  public:
    virtual void vf00();
    virtual void vf04();

    int m_uiRefCount;

    void IncRefCount()
    {
        DAT_00fdf1c0(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (DAT_00fdf1c4(&m_uiRefCount) == 0)
            vf04();
    }
};

class S00c62f40_Pointer
{
  public:
    __forceinline S00c62f40_Pointer(S00c62f40_RefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }

    __forceinline ~S00c62f40_Pointer()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }

    S00c62f40_Pointer& __thiscall FUN_006e5cc0(const S00c62f40_Pointer& source)
    {
        if (m_pObject != source.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = source.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    S00c62f40_RefObject* m_pObject;
};

class S00c62f40_Array
{
  public:
    void* m_ppVirtualMethodTable;
    S00c62f40_Pointer* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00c62f40();
};

// @fnv 0x00c62f40
void S00c62f40_Array::FUN_00c62f40()
{
    unsigned short index;

    for (index = 0; index < m_usSize; ++index)
    {
        {
            m_pBase[index].FUN_006e5cc0(S00c62f40_Pointer());
        }
    }

    m_usSize = 0;
    m_usESize = 0;
}

namespace fnv_00c63b40 {
struct BaseB3
{
    virtual ~BaseB3();
    int unk04, unk08, unk0c, unk10;
};
struct MidB3 : BaseB3
{
    __forceinline virtual ~MidB3()
    {}
};
struct ListBaseB3
{
    __forceinline ~ListBaseB3()
    {}
};
struct ListB3 : ListBaseB3
{
    int unk00, unk04, unk08;
    void FUN_00c64710();
    __forceinline ~ListB3()
    {
        int a, b, c;
        FUN_00c64710();
    }
};
struct MMB3
{
    void Deallocate(void*) throw();
};
extern MMB3 DAT_011f6238;
struct FUN_00c63b40 : MidB3
{
    void* unk14[8];
    ListB3 unk34;
    virtual ~FUN_00c63b40();
};
// @fnv 0x00c63b40
FUN_00c63b40::~FUN_00c63b40()
{
    for (int i = 0; i < 8; i++)
    {
        if (unk14[i])
        {
            void* p = unk14[i];
            DAT_011f6238.Deallocate(p);
        }
        unk14[i] = 0;
    }
}
}  // namespace fnv_00c63b40

extern "C" int __cdecl rand();
struct V3Op : V3
{
    V3Op FUN_00439ef0(const V3Op& o) const;
    V3Op FUN_00439e90(const V3Op& o) const;
    V3Op ApplyScaled(float f) const;
    void FUN_00439180(float f);
    void Scale(float f)
    {
        FUN_00439180(f);
    }
};
struct M68Q
{
    V3Op FUN_004b4500(const V3Op& v) const;
};
struct NodeQ
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
    M68Q k68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    V3Op kPos;
};
struct CamQ
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
    float f98;
};
inline void Dead3()
{
    int d1;
    int d2;
    int d3;
}
inline void Dead6()
{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
}
inline float Rand01()
{
    return rand() / 32767.0;
}
// @fnv 0x00c62470
void FUN_00c62390_cls::FUN_00c62470(void* a, void* b, void* c)
{
    if (a)
    {
        NodeQ* pParent = *(NodeQ**)((char*)a + 0x18);
        if (GetMode() != 1 && pParent)
        {
            *(V3Op*)b = ((NodeQ*)a)->kPos.FUN_00439ef0(pParent->kPos);
            Dead3();
            *(V3Op*)b = pParent->kPos.FUN_00439e90(((V3Op*)b)->ApplyScaled(Rand01()));
            Dead6();
            if (unk10)
            {
                float fScale = ((CamQ*)unk10)->f98;
                if (fScale != 1.0 && fScale != 0.0)
                    ((V3Op*)b)->Scale(1.0f / fScale);
            }
        }
        else
        {
            *(V3Op*)b = ((NodeQ*)a)->kPos;
            if (GetMode() == 1)
                *(V3Op*)c = ((NodeQ*)a)->k68.FUN_004b4500(*(V3Op*)c);
            Dead3();
        }
    }
    else
    {
        *(V3*)b = *(V3*)&DAT_011f426c;
    }
}

extern NiFixedString* DAT_012043ac;
struct ExtraDataBase850
{
    virtual ~ExtraDataBase850();
    void* m_pcName;
    void* m_pNext;
    ExtraDataBase850(const NiFixedString& kName);
    void SetName(const NiFixedString& kName);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct ExtraData850 : ExtraDataBase850
{
    ExtraData850(const NiFixedString& kName) : ExtraDataBase850(kName)
    {}
    virtual ~ExtraData850();
};
// @fnv 0x00c61850
ExtraData850* __cdecl FUN_00c61850()
{
    ExtraData850* pkData = new ExtraData850(*DAT_012043ac);
    pkData->SetName(DAT_011f49e0);
    return pkData;
}

struct FUN_00c656b0
{
    NiFixedString m_kName;
    NiFixedString m_kValue;
    ~FUN_00c656b0();
};

// @fnv 0x00c656b0
FUN_00c656b0::~FUN_00c656b0()
{}

namespace fnv_00c618f0 {
struct Pool_11f6238
{
    void* __thiscall FUN_00aa3e40(unsigned int bytes);
};
extern Pool_11f6238 DAT_011f6238;

extern char* DAT_0109b220;
extern const char str_010c36b0[];
char* __cdecl FUN_00a5b690(const char* text);
void __cdecl FormHeap_Free(void* buffer);

struct NiFixedString
{
    char* m_handle;

    NiFixedString(const char* text)
    {
        if (!text)
            m_handle = DAT_0109b220;
        else
            m_handle = FUN_00a5b690(text);
    }

    static void* operator new(unsigned int bytes)
    {
        return DAT_011f6238.FUN_00aa3e40(bytes);
    }

    static void operator delete(void* p)
    {
        FormHeap_Free(p);
    }

    static void operator delete(void* p, unsigned int size)
    {
        FormHeap_Free(p);
    }
};

extern NiFixedString* DAT_012043ac;

// @fnv 0x00c618f0
void FUN_00c618f0()
{
    DAT_012043ac = new NiFixedString(str_010c36b0);
}
}  // namespace fnv_00c618f0

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
inline void S61_Pad1()
{
    int a;
}
inline void S61_Pad2()
{
    int a;
    int b;
}
inline void S61_Pad12()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
}
struct RefObjV61
{
    virtual void Unk00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> class NiPointer61
{
  public:
    T* m_pObject;
    NiPointer61(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer61()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
};
typedef NiPointer61<RefObjV61> Ptr61;
struct CloneMap61
{
    bool FUN_00a53c30(void* key, void*& out);
};
struct Cloning61
{
    CloneMap61* m_pCloneMap;
};
struct PtrArray61
{
    void* vtbl;
    Ptr61* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    Ptr61& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    void FUN_00c62b90(unsigned int i, Ptr61& p);
    Ptr61 FUN_00c62d10(unsigned int i);
    void FUN_00c63030();
};
struct Base61
{
    void FUN_00c31c90(Cloning61& c);
};
struct Emitter61 : Base61
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
    PtrArray61 m_kArray;
    void FUN_00c61cc0(Cloning61& kCloning);
};

// @fnv 0x00c61cc0
void Emitter61::FUN_00c61cc0(Cloning61& kCloning)
{
    Base61::FUN_00c31c90(kCloning);
    void* pkClone4;
    Emitter61* pkDest9;
    bool bCloned3 = kCloning.m_pCloneMap->FUN_00a53c30(this, pkClone4);
    if (bCloned3)
    {
        pkDest9 = (Emitter61*)pkClone4;
        unsigned int uiCount4 = pkDest9->m_kArray.GetSize();
        unsigned int uiFound2 = 0;
        while (uiCount4--)
        {
            void* pkNew;
            S61_Pad2();
            bool bNewA = kCloning.m_pCloneMap->FUN_00a53c30(pkDest9->m_kArray.GetAt(uiCount4), pkNew);
            if (bNewA)
            {
                uiFound2++;
                S61_Pad2();
                Ptr61 spNew3 = (RefObjV61*)pkNew;
                S61_Pad1();
                pkDest9->m_kArray.FUN_00c62b90(uiCount4, spNew3);
            }
            else
            {
                pkDest9->m_kArray.FUN_00c62d10(uiCount4);
            }
        }
        S61_Pad12();
        if (uiFound2 != pkDest9->m_kArray.GetSize())
            pkDest9->m_kArray.FUN_00c63030();
    }
}
