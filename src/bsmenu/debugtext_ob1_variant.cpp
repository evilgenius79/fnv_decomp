// bsmenu/debugtext_ob1_variant.cpp: MgrQ, TextList, AudioManager, A0F8Self and more (21 functions)

#include "fnv_asm_helpers.h"
// src/bsmenu/debugtext_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bsmenu/debugtext.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsmenu/debugtext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/debugtext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct DebugText {
    int GetEntry(int);
};
struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_011f33d4;
struct FUN_00a11b70_shell {
    GlobalObject_00a7b610* __thiscall GetGlobalObject();
};
struct DebugText_00a0e430 {
    void __thiscall AddScaledValue(int a, int b);
};
struct VCall_00a0e470 {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4(int, int, int, const char*, char*, int);
};
int __cdecl FUN_00a0e470(DebugText* a1, int aiX, const char* apFormatString, ...);
struct FakeV_00a0e4b0 {
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual int f4(int, int, int, int, char*, int) { return 0; }
};
int __cdecl InvokeVirtualWithArgs(FakeV_00a0e4b0* p, int a, int b, int c, int d, int e);
struct FUN_00a0e580_VTab {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4();
    virtual int m5();
    virtual int __thiscall m6(int, int, const char*, char*, int);
};
int __cdecl FUN_00a0e580(FUN_00a0e580_VTab* pThis, int aeLocation, int aeJustify, const char* apFormatString, ...);
struct RgbaColor { float r; float g; float b; float a; };
struct FakeCall {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int, int, int, const char*, char*, const RgbaColor&);
};
int FUN_00a0e690(DebugText* aObj, int aiX, const RgbaColor& apTextColor, const char* apFormatString, ...);
struct FUN_00a0e6d0_this {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int VFunc(int, int, int, const char*, char*, void*);
};
int __cdecl InvokeVFuncWithVarArgs(FUN_00a0e6d0_this* p0, int p1, void* p2, int p3, int p4, const char* p5, ...);
extern "C" unsigned char __cdecl FUN_00702fc0();
extern int DAT_011f33dc;
extern void (__stdcall *DAT_00fdf05c)(int*);
void __cdecl FUN_00a11820();
struct NiTMapItem {
    unsigned int key;
    void* data;
    void* extra;
};
struct NiTPointerMap {
    void NewItem(NiTMapItem* item);
};
struct P03MM {
    void* __thiscall Allocate(unsigned int size);
};
extern P03MM g_memoryManager;
struct ChangeData;
struct FUN_00a11c00_shell {
    void FUN_00a11c00(NiTMapItem* item);
};
struct BSSimpleArray {
    int _pad;
    void** m_data;
    unsigned int __thiscall FUN_00a11ee0();
    unsigned int __thiscall FUN_00a11d20(void* &aValue);
};
struct PendingObj {
    void FUN_00a0dcc0();
};
struct PendingOwner {
    void FUN_00aa4060(PendingObj* p);
};
extern PendingOwner g_011f6238;
extern PendingObj* g_011f33a8;
void __cdecl ClearPendingObject();
struct Setting { int unk00; int value; };
extern Setting DAT_011f33c8,DAT_011debac,DAT_011deec0;
extern int DAT_01202800;
struct Record { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34; float* unk38; };
extern Record** DAT_011f33f8;
bool FUN_00703150();
struct LayoutObject {
 int unk0000,unk0004,unk0008,unk000c,unk0010,unk0014,unk0018,unk001c,unk0020,unk0024;
 int unk0028,unk002c,unk0030,unk0034,unk0038,unk003c,unk0040,unk0044,unk0048,unk004c;
 int unk0050,unk0054,unk0058,unk005c,unk0060,unk0064,unk0068,unk006c,unk0070,unk0074;
 int unk0078,unk007c,unk0080,unk0084,unk0088,unk008c,unk0090,unk0094,unk0098,unk009c;
 int unk00a0,unk00a4,unk00a8,unk00ac,unk00b0,unk00b4,unk00b8,unk00bc,unk00c0,unk00c4;
 int unk00c8,unk00cc,unk00d0,unk00d4,unk00d8,unk00dc,unk00e0,unk00e4,unk00e8,unk00ec;
 int unk00f0,unk00f4,unk00f8,unk00fc,unk0100,unk0104,unk0108,unk010c,unk0110,unk0114;
 int unk0118,unk011c,unk0120,unk0124,unk0128,unk012c,unk0130,unk0134,unk0138,unk013c;
 int unk0140,unk0144,unk0148,unk014c,unk0150,unk0154,unk0158,unk015c,unk0160,unk0164;
 int unk0168,unk016c,unk0170,unk0174,unk0178,unk017c,unk0180,unk0184,unk0188,unk018c;
 int unk0190,unk0194,unk0198,unk019c,unk01a0,unk01a4,unk01a8,unk01ac,unk01b0,unk01b4;
 int unk01b8,unk01bc,unk01c0,unk01c4,unk01c8,unk01cc,unk01d0,unk01d4,unk01d8,unk01dc;
 int unk01e0,unk01e4,unk01e8,unk01ec,unk01f0,unk01f4,unk01f8,unk01fc,unk0200,unk0204;
 int unk0208,unk020c,unk0210,unk0214,unk0218,unk021c,unk0220,unk0224,unk0228,unk022c;
 int unk0230,unk0234,unk0238,unk023c,unk0240,unk0244,unk0248,unk024c,unk0250,unk0254;
 int unk0258,unk025c,unk0260,unk0264,unk0268,unk026c,unk0270,unk0274,unk0278,unk027c;
 int unk0280,unk0284,unk0288,unk028c,unk0290,unk0294,unk0298,unk029c,unk02a0,unk02a4;
 int unk02a8,unk02ac,unk02b0,unk02b4,unk02b8,unk02bc,unk02c0,unk02c4,unk02c8,unk02cc;
 int unk02d0,unk02d4,unk02d8,unk02dc,unk02e0,unk02e4,unk02e8,unk02ec,unk02f0,unk02f4;
 int unk02f8,unk02fc,unk0300,unk0304,unk0308,unk030c,unk0310,unk0314,unk0318,unk031c;
 int unk0320,unk0324,unk0328,unk032c,unk0330,unk0334,unk0338,unk033c,unk0340,unk0344;
 int unk0348,unk034c,unk0350,unk0354,unk0358,unk035c,unk0360,unk0364,unk0368,unk036c;
 int unk0370,unk0374,unk0378,unk037c,unk0380,unk0384,unk0388,unk038c,unk0390,unk0394;
 int unk0398,unk039c,unk03a0,unk03a4,unk03a8,unk03ac,unk03b0,unk03b4,unk03b8,unk03bc;
 int unk03c0,unk03c4,unk03c8,unk03cc,unk03d0,unk03d4,unk03d8,unk03dc,unk03e0,unk03e4;
 int unk03e8,unk03ec,unk03f0,unk03f4,unk03f8,unk03fc,unk0400,unk0404,unk0408,unk040c;
 int unk0410,unk0414,unk0418,unk041c,unk0420,unk0424,unk0428,unk042c,unk0430,unk0434;
 int unk0438,unk043c,unk0440,unk0444,unk0448,unk044c,unk0450,unk0454,unk0458,unk045c;
 int unk0460,unk0464,unk0468,unk046c,unk0470,unk0474,unk0478,unk047c,unk0480,unk0484;
 int unk0488,unk048c,unk0490,unk0494,unk0498,unk049c,unk04a0,unk04a4,unk04a8,unk04ac;
 int unk04b0,unk04b4,unk04b8,unk04bc,unk04c0,unk04c4,unk04c8,unk04cc,unk04d0,unk04d4;
 int unk04d8,unk04dc,unk04e0,unk04e4,unk04e8,unk04ec,unk04f0,unk04f4,unk04f8,unk04fc;
 int unk0500,unk0504,unk0508,unk050c,unk0510,unk0514,unk0518,unk051c,unk0520,unk0524;
 int unk0528,unk052c,unk0530,unk0534,unk0538,unk053c,unk0540,unk0544,unk0548,unk054c;
 int unk0550,unk0554,unk0558,unk055c,unk0560,unk0564,unk0568,unk056c,unk0570,unk0574;
 int unk0578,unk057c,unk0580,unk0584,unk0588,unk058c,unk0590,unk0594,unk0598,unk059c;
 int unk05a0,unk05a4,unk05a8,unk05ac,unk05b0,unk05b4,unk05b8,unk05bc,unk05c0,unk05c4;
 int unk05c8,unk05cc,unk05d0,unk05d4,unk05d8,unk05dc,unk05e0,unk05e4,unk05e8,unk05ec;
 int unk05f0,unk05f4,unk05f8,unk05fc,unk0600,unk0604,unk0608,unk060c,unk0610,unk0614;
 int unk0618,unk061c,unk0620,unk0624,unk0628,unk062c,unk0630,unk0634,unk0638,unk063c;
 int unk0640,unk0644,unk0648,unk064c,unk0650,unk0654,unk0658,unk065c,unk0660,unk0664;
 int unk0668,unk066c,unk0670,unk0674,unk0678,unk067c,unk0680,unk0684,unk0688,unk068c;
 int unk0690,unk0694,unk0698,unk069c,unk06a0,unk06a4,unk06a8,unk06ac,unk06b0,unk06b4;
 int unk06b8,unk06bc,unk06c0,unk06c4,unk06c8,unk06cc,unk06d0,unk06d4,unk06d8,unk06dc;
 int unk06e0,unk06e4,unk06e8,unk06ec,unk06f0,unk06f4,unk06f8,unk06fc,unk0700,unk0704;
 int unk0708,unk070c,unk0710,unk0714,unk0718,unk071c,unk0720,unk0724,unk0728,unk072c;
 int unk0730,unk0734,unk0738,unk073c,unk0740,unk0744,unk0748,unk074c,unk0750,unk0754;
 int unk0758,unk075c,unk0760,unk0764,unk0768,unk076c,unk0770,unk0774,unk0778,unk077c;
 int unk0780,unk0784,unk0788,unk078c,unk0790,unk0794,unk0798,unk079c,unk07a0,unk07a4;
 int unk07a8,unk07ac,unk07b0,unk07b4,unk07b8,unk07bc,unk07c0,unk07c4,unk07c8,unk07cc;
 int unk07d0,unk07d4,unk07d8,unk07dc,unk07e0,unk07e4,unk07e8,unk07ec,unk07f0,unk07f4;
 int unk07f8,unk07fc,unk0800,unk0804,unk0808,unk080c,unk0810,unk0814,unk0818,unk081c;
 int unk0820,unk0824,unk0828,unk082c,unk0830,unk0834,unk0838,unk083c,unk0840,unk0844;
 int unk0848,unk084c,unk0850,unk0854,unk0858,unk085c,unk0860,unk0864,unk0868,unk086c;
 int unk0870,unk0874,unk0878,unk087c,unk0880,unk0884,unk0888,unk088c,unk0890,unk0894;
 int unk0898,unk089c,unk08a0,unk08a4,unk08a8,unk08ac,unk08b0,unk08b4,unk08b8,unk08bc;
 int unk08c0,unk08c4,unk08c8,unk08cc,unk08d0,unk08d4,unk08d8,unk08dc,unk08e0,unk08e4;
 int unk08e8,unk08ec,unk08f0,unk08f4,unk08f8,unk08fc,unk0900,unk0904,unk0908,unk090c;
 int unk0910,unk0914,unk0918,unk091c,unk0920,unk0924,unk0928,unk092c,unk0930,unk0934;
 int unk0938,unk093c,unk0940,unk0944,unk0948,unk094c,unk0950,unk0954,unk0958,unk095c;
 int unk0960,unk0964,unk0968,unk096c,unk0970,unk0974,unk0978,unk097c,unk0980,unk0984;
 int unk0988,unk098c,unk0990,unk0994,unk0998,unk099c,unk09a0,unk09a4,unk09a8,unk09ac;
 int unk09b0,unk09b4,unk09b8,unk09bc,unk09c0,unk09c4,unk09c8,unk09cc,unk09d0,unk09d4;
 int unk09d8,unk09dc,unk09e0,unk09e4,unk09e8,unk09ec,unk09f0,unk09f4,unk09f8,unk09fc;
 int unk0a00,unk0a04,unk0a08,unk0a0c,unk0a10,unk0a14,unk0a18,unk0a1c,unk0a20,unk0a24;
 int unk0a28,unk0a2c,unk0a30,unk0a34,unk0a38,unk0a3c,unk0a40,unk0a44,unk0a48,unk0a4c;
 int unk0a50,unk0a54,unk0a58,unk0a5c,unk0a60,unk0a64,unk0a68,unk0a6c,unk0a70,unk0a74;
 int unk0a78,unk0a7c,unk0a80,unk0a84,unk0a88,unk0a8c,unk0a90,unk0a94,unk0a98,unk0a9c;
 int unk0aa0,unk0aa4,unk0aa8,unk0aac,unk0ab0,unk0ab4,unk0ab8,unk0abc,unk0ac0,unk0ac4;
 int unk0ac8,unk0acc,unk0ad0,unk0ad4,unk0ad8,unk0adc,unk0ae0,unk0ae4,unk0ae8,unk0aec;
 int unk0af0,unk0af4,unk0af8,unk0afc,unk0b00,unk0b04,unk0b08,unk0b0c,unk0b10,unk0b14;
 int unk0b18,unk0b1c,unk0b20,unk0b24,unk0b28,unk0b2c,unk0b30,unk0b34,unk0b38,unk0b3c;
 int unk0b40,unk0b44,unk0b48,unk0b4c,unk0b50,unk0b54,unk0b58,unk0b5c,unk0b60,unk0b64;
 int unk0b68,unk0b6c,unk0b70,unk0b74,unk0b78,unk0b7c,unk0b80,unk0b84,unk0b88,unk0b8c;
 int unk0b90,unk0b94,unk0b98,unk0b9c,unk0ba0,unk0ba4,unk0ba8,unk0bac,unk0bb0,unk0bb4;
 int unk0bb8,unk0bbc,unk0bc0,unk0bc4,unk0bc8,unk0bcc,unk0bd0,unk0bd4,unk0bd8,unk0bdc;
 int unk0be0,unk0be4,unk0be8,unk0bec,unk0bf0,unk0bf4,unk0bf8,unk0bfc,unk0c00,unk0c04;
 int unk0c08,unk0c0c,unk0c10,unk0c14,unk0c18,unk0c1c,unk0c20,unk0c24,unk0c28,unk0c2c;
 int unk0c30,unk0c34,unk0c38,unk0c3c,unk0c40,unk0c44,unk0c48,unk0c4c,unk0c50,unk0c54;
 int unk0c58,unk0c5c,unk0c60,unk0c64,unk0c68,unk0c6c,unk0c70,unk0c74,unk0c78,unk0c7c;
 int unk0c80,unk0c84,unk0c88,unk0c8c,unk0c90,unk0c94,unk0c98,unk0c9c,unk0ca0,unk0ca4;
 int unk0ca8,unk0cac,unk0cb0,unk0cb4,unk0cb8,unk0cbc,unk0cc0,unk0cc4,unk0cc8,unk0ccc;
 int unk0cd0,unk0cd4,unk0cd8,unk0cdc,unk0ce0,unk0ce4,unk0ce8,unk0cec,unk0cf0,unk0cf4;
 int unk0cf8,unk0cfc,unk0d00,unk0d04,unk0d08,unk0d0c,unk0d10,unk0d14,unk0d18,unk0d1c;
 int unk0d20,unk0d24,unk0d28,unk0d2c,unk0d30,unk0d34,unk0d38,unk0d3c,unk0d40,unk0d44;
 int unk0d48,unk0d4c,unk0d50,unk0d54,unk0d58,unk0d5c,unk0d60,unk0d64,unk0d68,unk0d6c;
 int unk0d70,unk0d74,unk0d78,unk0d7c,unk0d80,unk0d84,unk0d88,unk0d8c,unk0d90,unk0d94;
 int unk0d98,unk0d9c,unk0da0,unk0da4,unk0da8,unk0dac,unk0db0,unk0db4,unk0db8,unk0dbc;
 int unk0dc0,unk0dc4,unk0dc8,unk0dcc,unk0dd0,unk0dd4,unk0dd8,unk0ddc,unk0de0,unk0de4;
 int unk0de8,unk0dec,unk0df0,unk0df4,unk0df8,unk0dfc,unk0e00,unk0e04,unk0e08,unk0e0c;
 int unk0e10,unk0e14,unk0e18,unk0e1c,unk0e20,unk0e24,unk0e28,unk0e2c,unk0e30,unk0e34;
 int unk0e38,unk0e3c,unk0e40,unk0e44,unk0e48,unk0e4c,unk0e50,unk0e54,unk0e58,unk0e5c;
 int unk0e60,unk0e64,unk0e68,unk0e6c,unk0e70,unk0e74,unk0e78,unk0e7c,unk0e80,unk0e84;
 int unk0e88,unk0e8c,unk0e90,unk0e94,unk0e98,unk0e9c,unk0ea0,unk0ea4,unk0ea8,unk0eac;
 int unk0eb0,unk0eb4,unk0eb8,unk0ebc,unk0ec0,unk0ec4,unk0ec8,unk0ecc,unk0ed0,unk0ed4;
 int unk0ed8,unk0edc,unk0ee0,unk0ee4,unk0ee8,unk0eec,unk0ef0,unk0ef4,unk0ef8,unk0efc;
 int unk0f00,unk0f04,unk0f08,unk0f0c,unk0f10,unk0f14,unk0f18,unk0f1c,unk0f20,unk0f24;
 int unk0f28,unk0f2c,unk0f30,unk0f34,unk0f38,unk0f3c,unk0f40,unk0f44,unk0f48,unk0f4c;
 int unk0f50,unk0f54,unk0f58,unk0f5c,unk0f60,unk0f64,unk0f68,unk0f6c,unk0f70,unk0f74;
 int unk0f78,unk0f7c,unk0f80,unk0f84,unk0f88,unk0f8c,unk0f90,unk0f94,unk0f98,unk0f9c;
 int unk0fa0,unk0fa4,unk0fa8,unk0fac,unk0fb0,unk0fb4,unk0fb8,unk0fbc,unk0fc0,unk0fc4;
 int unk0fc8,unk0fcc,unk0fd0,unk0fd4,unk0fd8,unk0fdc,unk0fe0,unk0fe4,unk0fe8,unk0fec;
 int unk0ff0,unk0ff4,unk0ff8,unk0ffc,unk1000,unk1004,unk1008,unk100c,unk1010,unk1014;
 int unk1018,unk101c,unk1020,unk1024,unk1028,unk102c,unk1030,unk1034,unk1038,unk103c;
 int unk1040,unk1044,unk1048,unk104c,unk1050,unk1054,unk1058,unk105c,unk1060,unk1064;
 int unk1068,unk106c,unk1070,unk1074,unk1078,unk107c,unk1080,unk1084,unk1088,unk108c;
 int unk1090,unk1094,unk1098,unk109c,unk10a0,unk10a4,unk10a8,unk10ac,unk10b0,unk10b4;
 int unk10b8,unk10bc,unk10c0,unk10c4,unk10c8,unk10cc,unk10d0,unk10d4,unk10d8,unk10dc;
 int unk10e0,unk10e4,unk10e8,unk10ec,unk10f0,unk10f4,unk10f8,unk10fc,unk1100,unk1104;
 int unk1108,unk110c,unk1110,unk1114,unk1118,unk111c,unk1120,unk1124,unk1128,unk112c;
 int unk1130,unk1134,unk1138,unk113c,unk1140,unk1144,unk1148,unk114c,unk1150,unk1154;
 int unk1158,unk115c,unk1160,unk1164,unk1168,unk116c,unk1170,unk1174,unk1178,unk117c;
 int unk1180,unk1184,unk1188,unk118c,unk1190,unk1194,unk1198,unk119c,unk11a0,unk11a4;
 int unk11a8,unk11ac,unk11b0,unk11b4,unk11b8,unk11bc,unk11c0,unk11c4,unk11c8,unk11cc;
 int unk11d0,unk11d4,unk11d8,unk11dc,unk11e0,unk11e4,unk11e8,unk11ec,unk11f0,unk11f4;
 int unk11f8,unk11fc,unk1200,unk1204,unk1208,unk120c,unk1210,unk1214,unk1218,unk121c;
 int unk1220,unk1224,unk1228,unk122c,unk1230,unk1234,unk1238,unk123c,unk1240,unk1244;
 int unk1248,unk124c,unk1250,unk1254,unk1258,unk125c,unk1260,unk1264,unk1268,unk126c;
 int unk1270,unk1274,unk1278,unk127c,unk1280,unk1284,unk1288,unk128c,unk1290,unk1294;
 int unk1298,unk129c,unk12a0,unk12a4,unk12a8,unk12ac,unk12b0,unk12b4,unk12b8,unk12bc;
 int unk12c0,unk12c4,unk12c8,unk12cc,unk12d0,unk12d4,unk12d8,unk12dc,unk12e0,unk12e4;
 int unk12e8,unk12ec,unk12f0,unk12f4,unk12f8,unk12fc,unk1300,unk1304,unk1308,unk130c;
 int unk1310,unk1314,unk1318,unk131c,unk1320,unk1324,unk1328,unk132c,unk1330,unk1334;
 int unk1338,unk133c,unk1340,unk1344,unk1348,unk134c,unk1350,unk1354,unk1358,unk135c;
 int unk1360,unk1364,unk1368,unk136c,unk1370,unk1374,unk1378,unk137c,unk1380,unk1384;
 int unk1388,unk138c,unk1390,unk1394,unk1398,unk139c,unk13a0,unk13a4,unk13a8,unk13ac;
 int unk13b0,unk13b4,unk13b8,unk13bc,unk13c0,unk13c4,unk13c8,unk13cc,unk13d0,unk13d4;
 int unk13d8,unk13dc,unk13e0,unk13e4,unk13e8,unk13ec,unk13f0,unk13f4,unk13f8,unk13fc;
 int unk1400,unk1404,unk1408,unk140c,unk1410,unk1414,unk1418,unk141c,unk1420,unk1424;
 int unk1428,unk142c,unk1430,unk1434,unk1438,unk143c,unk1440,unk1444,unk1448,unk144c;
 int unk1450,unk1454,unk1458,unk145c,unk1460,unk1464,unk1468,unk146c,unk1470,unk1474;
 int unk1478,unk147c,unk1480,unk1484,unk1488,unk148c,unk1490,unk1494,unk1498,unk149c;
 int unk14a0,unk14a4,unk14a8,unk14ac,unk14b0,unk14b4,unk14b8,unk14bc,unk14c0,unk14c4;
 int unk14c8,unk14cc,unk14d0,unk14d4,unk14d8,unk14dc,unk14e0,unk14e4,unk14e8,unk14ec;
 int unk14f0,unk14f4,unk14f8,unk14fc,unk1500,unk1504,unk1508,unk150c,unk1510,unk1514;
 int unk1518,unk151c,unk1520,unk1524,unk1528,unk152c,unk1530,unk1534,unk1538,unk153c;
 int unk1540,unk1544,unk1548,unk154c,unk1550,unk1554,unk1558,unk155c,unk1560,unk1564;
 int unk1568,unk156c,unk1570,unk1574,unk1578,unk157c,unk1580,unk1584,unk1588,unk158c;
 int unk1590,unk1594,unk1598,unk159c,unk15a0,unk15a4,unk15a8,unk15ac,unk15b0,unk15b4;
 int unk15b8,unk15bc,unk15c0,unk15c4,unk15c8,unk15cc,unk15d0,unk15d4,unk15d8,unk15dc;
 int unk15e0,unk15e4,unk15e8,unk15ec,unk15f0,unk15f4,unk15f8,unk15fc,unk1600,unk1604;
 int unk1608,unk160c,unk1610,unk1614,unk1618,unk161c,unk1620,unk1624,unk1628,unk162c;
 int unk1630,unk1634,unk1638,unk163c,unk1640,unk1644,unk1648,unk164c,unk1650,unk1654;
 int unk1658,unk165c,unk1660,unk1664,unk1668,unk166c,unk1670,unk1674,unk1678,unk167c;
 int unk1680,unk1684,unk1688,unk168c,unk1690,unk1694,unk1698,unk169c,unk16a0,unk16a4;
 int unk16a8,unk16ac,unk16b0,unk16b4,unk16b8,unk16bc,unk16c0,unk16c4,unk16c8,unk16cc;
 int unk16d0,unk16d4,unk16d8,unk16dc,unk16e0,unk16e4,unk16e8,unk16ec,unk16f0,unk16f4;
 int unk16f8,unk16fc,unk1700,unk1704,unk1708,unk170c,unk1710,unk1714,unk1718,unk171c;
 int unk1720,unk1724,unk1728,unk172c,unk1730,unk1734,unk1738,unk173c,unk1740,unk1744;
 int unk1748,unk174c,unk1750,unk1754,unk1758,unk175c,unk1760,unk1764,unk1768,unk176c;
 int unk1770,unk1774,unk1778,unk177c,unk1780,unk1784,unk1788,unk178c,unk1790,unk1794;
 int unk1798,unk179c,unk17a0,unk17a4,unk17a8,unk17ac,unk17b0,unk17b4,unk17b8,unk17bc;
 int unk17c0,unk17c4,unk17c8,unk17cc,unk17d0,unk17d4,unk17d8,unk17dc,unk17e0,unk17e4;
 int unk17e8,unk17ec,unk17f0,unk17f4,unk17f8,unk17fc,unk1800,unk1804,unk1808,unk180c;
 int unk1810,unk1814,unk1818,unk181c,unk1820,unk1824,unk1828,unk182c,unk1830,unk1834;
 int unk1838,unk183c,unk1840,unk1844,unk1848,unk184c,unk1850,unk1854,unk1858,unk185c;
 int unk1860,unk1864,unk1868,unk186c,unk1870,unk1874,unk1878,unk187c,unk1880,unk1884;
 int unk1888,unk188c,unk1890,unk1894,unk1898,unk189c,unk18a0,unk18a4,unk18a8,unk18ac;
 int unk18b0,unk18b4,unk18b8,unk18bc,unk18c0,unk18c4,unk18c8,unk18cc,unk18d0,unk18d4;
 int unk18d8,unk18dc,unk18e0,unk18e4,unk18e8,unk18ec,unk18f0,unk18f4,unk18f8,unk18fc;
 int unk1900,unk1904,unk1908,unk190c,unk1910,unk1914,unk1918,unk191c,unk1920,unk1924;
 int unk1928,unk192c,unk1930,unk1934,unk1938,unk193c,unk1940,unk1944,unk1948,unk194c;
 int unk1950,unk1954,unk1958,unk195c,unk1960,unk1964,unk1968,unk196c,unk1970,unk1974;
 int unk1978,unk197c,unk1980,unk1984,unk1988,unk198c,unk1990,unk1994,unk1998,unk199c;
 int unk19a0,unk19a4,unk19a8,unk19ac,unk19b0,unk19b4,unk19b8,unk19bc,unk19c0,unk19c4;
 int unk19c8,unk19cc,unk19d0,unk19d4,unk19d8,unk19dc,unk19e0,unk19e4,unk19e8,unk19ec;
 int unk19f0,unk19f4,unk19f8,unk19fc,unk1a00,unk1a04,unk1a08,unk1a0c,unk1a10,unk1a14;
 int unk1a18,unk1a1c,unk1a20,unk1a24,unk1a28,unk1a2c,unk1a30,unk1a34,unk1a38,unk1a3c;
 int unk1a40,unk1a44,unk1a48,unk1a4c,unk1a50,unk1a54,unk1a58,unk1a5c,unk1a60,unk1a64;
 int unk1a68,unk1a6c,unk1a70,unk1a74,unk1a78,unk1a7c,unk1a80,unk1a84,unk1a88,unk1a8c;
 int unk1a90,unk1a94,unk1a98,unk1a9c,unk1aa0,unk1aa4,unk1aa8,unk1aac,unk1ab0,unk1ab4;
 int unk1ab8,unk1abc,unk1ac0,unk1ac4,unk1ac8,unk1acc,unk1ad0,unk1ad4,unk1ad8,unk1adc;
 int unk1ae0,unk1ae4,unk1ae8,unk1aec,unk1af0,unk1af4,unk1af8,unk1afc,unk1b00,unk1b04;
 int unk1b08,unk1b0c,unk1b10,unk1b14,unk1b18,unk1b1c,unk1b20,unk1b24,unk1b28,unk1b2c;
 int unk1b30,unk1b34,unk1b38,unk1b3c,unk1b40,unk1b44,unk1b48,unk1b4c,unk1b50,unk1b54;
 int unk1b58,unk1b5c,unk1b60,unk1b64,unk1b68,unk1b6c,unk1b70,unk1b74,unk1b78,unk1b7c;
 int unk1b80,unk1b84,unk1b88,unk1b8c,unk1b90,unk1b94,unk1b98,unk1b9c,unk1ba0,unk1ba4;
 int unk1ba8,unk1bac,unk1bb0,unk1bb4,unk1bb8,unk1bbc,unk1bc0,unk1bc4,unk1bc8,unk1bcc;
 int unk1bd0,unk1bd4,unk1bd8,unk1bdc,unk1be0,unk1be4,unk1be8,unk1bec,unk1bf0,unk1bf4;
 int unk1bf8,unk1bfc,unk1c00,unk1c04,unk1c08,unk1c0c,unk1c10,unk1c14,unk1c18,unk1c1c;
 int unk1c20,unk1c24,unk1c28,unk1c2c,unk1c30,unk1c34,unk1c38,unk1c3c,unk1c40,unk1c44;
 int unk1c48,unk1c4c,unk1c50,unk1c54,unk1c58,unk1c5c,unk1c60,unk1c64,unk1c68,unk1c6c;
 int unk1c70,unk1c74,unk1c78,unk1c7c,unk1c80,unk1c84,unk1c88,unk1c8c,unk1c90,unk1c94;
 int unk1c98,unk1c9c,unk1ca0,unk1ca4,unk1ca8,unk1cac,unk1cb0,unk1cb4,unk1cb8,unk1cbc;
 int unk1cc0,unk1cc4,unk1cc8,unk1ccc,unk1cd0,unk1cd4,unk1cd8,unk1cdc,unk1ce0,unk1ce4;
 int unk1ce8,unk1cec,unk1cf0,unk1cf4,unk1cf8,unk1cfc,unk1d00,unk1d04,unk1d08,unk1d0c;
 int unk1d10,unk1d14,unk1d18,unk1d1c,unk1d20,unk1d24,unk1d28,unk1d2c,unk1d30,unk1d34;
 int unk1d38,unk1d3c,unk1d40,unk1d44,unk1d48,unk1d4c,unk1d50,unk1d54,unk1d58,unk1d5c;
 int unk1d60,unk1d64,unk1d68,unk1d6c,unk1d70,unk1d74,unk1d78,unk1d7c,unk1d80,unk1d84;
 int unk1d88,unk1d8c,unk1d90,unk1d94,unk1d98,unk1d9c,unk1da0,unk1da4,unk1da8,unk1dac;
 int unk1db0,unk1db4,unk1db8,unk1dbc,unk1dc0,unk1dc4,unk1dc8,unk1dcc,unk1dd0,unk1dd4;
 int unk1dd8,unk1ddc,unk1de0,unk1de4,unk1de8,unk1dec,unk1df0,unk1df4,unk1df8,unk1dfc;
 int unk1e00,unk1e04,unk1e08,unk1e0c,unk1e10,unk1e14,unk1e18,unk1e1c,unk1e20,unk1e24;
 int unk1e28,unk1e2c,unk1e30,unk1e34,unk1e38,unk1e3c,unk1e40,unk1e44,unk1e48,unk1e4c;
 int unk1e50,unk1e54,unk1e58,unk1e5c,unk1e60,unk1e64,unk1e68,unk1e6c,unk1e70,unk1e74;
 int unk1e78,unk1e7c,unk1e80,unk1e84,unk1e88,unk1e8c,unk1e90,unk1e94,unk1e98,unk1e9c;
 int unk1ea0,unk1ea4,unk1ea8,unk1eac,unk1eb0,unk1eb4,unk1eb8,unk1ebc,unk1ec0,unk1ec4;
 int unk1ec8,unk1ecc,unk1ed0,unk1ed4,unk1ed8,unk1edc,unk1ee0,unk1ee4,unk1ee8,unk1eec;
 int unk1ef0,unk1ef4,unk1ef8,unk1efc,unk1f00,unk1f04,unk1f08,unk1f0c,unk1f10,unk1f14;
 int unk1f18,unk1f1c,unk1f20,unk1f24,unk1f28,unk1f2c,unk1f30,unk1f34,unk1f38,unk1f3c;
 int unk1f40,unk1f44,unk1f48,unk1f4c,unk1f50,unk1f54,unk1f58,unk1f5c,unk1f60,unk1f64;
 int unk1f68,unk1f6c,unk1f70,unk1f74,unk1f78,unk1f7c,unk1f80,unk1f84,unk1f88,unk1f8c;
 int unk1f90,unk1f94,unk1f98,unk1f9c,unk1fa0,unk1fa4,unk1fa8,unk1fac,unk1fb0,unk1fb4;
 int unk1fb8,unk1fbc,unk1fc0,unk1fc4,unk1fc8,unk1fcc,unk1fd0,unk1fd4,unk1fd8,unk1fdc;
 int unk1fe0,unk1fe4,unk1fe8,unk1fec,unk1ff0,unk1ff4,unk1ff8,unk1ffc,unk2000,unk2004;
 int unk2008,unk200c,unk2010,unk2014,unk2018,unk201c,unk2020,unk2024,unk2028,unk202c;
 int unk2030,unk2034,unk2038,unk203c,unk2040,unk2044,unk2048,unk204c,unk2050,unk2054;
 int unk2058,unk205c,unk2060,unk2064,unk2068,unk206c,unk2070,unk2074,unk2078,unk207c;
 int unk2080,unk2084,unk2088,unk208c,unk2090,unk2094,unk2098,unk209c,unk20a0,unk20a4;
 int unk20a8,unk20ac,unk20b0,unk20b4,unk20b8,unk20bc,unk20c0,unk20c4,unk20c8,unk20cc;
 int unk20d0,unk20d4,unk20d8,unk20dc,unk20e0,unk20e4,unk20e8,unk20ec,unk20f0,unk20f4;
 int unk20f8,unk20fc,unk2100,unk2104,unk2108,unk210c,unk2110,unk2114,unk2118,unk211c;
 int unk2120,unk2124,unk2128,unk212c,unk2130,unk2134,unk2138,unk213c,unk2140,unk2144;
 int unk2148,unk214c,unk2150,unk2154,unk2158,unk215c,unk2160,unk2164,unk2168,unk216c;
 int unk2170,unk2174,unk2178,unk217c,unk2180,unk2184,unk2188,unk218c,unk2190,unk2194;
 int unk2198,unk219c,unk21a0,unk21a4,unk21a8,unk21ac,unk21b0,unk21b4,unk21b8,unk21bc;
 int unk21c0,unk21c4,unk21c8,unk21cc,unk21d0,unk21d4,unk21d8,unk21dc,unk21e0,unk21e4;
 int unk21e8,unk21ec,unk21f0,unk21f4,unk21f8,unk21fc,unk2200,unk2204,unk2208,unk220c;
 int unk2210,unk2214,unk2218,unk221c,unk2220,unk2224,unk2228,unk222c,unk2230,unk2234;
 int unk2238,unk223c,unk2240,unk2244,unk2248,unk224c,unk2250,unk2254,unk2258,unk225c;
 int unk2260,unk2264,unk2268,unk226c,unk2270,unk2274,unk2278,unk227c;
 int height;
 int positions[3];
 int left,right,center;
 void UpdateLayoutPositions();
};
struct E4F0Block256 {
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
};
struct RgbaColor;
extern "C" int __cdecl FUN_00ecddf1(char* buf, unsigned int n, const char* fmt, char* args);
struct E4F0DebugText {
    E4F0Block256 m_block00;
    E4F0Block256 m_block01;
    E4F0Block256 m_block02;
    E4F0Block256 m_block03;
    E4F0Block256 m_block04;
    E4F0Block256 m_block05;
    E4F0Block256 m_block06;
    E4F0Block256 m_block07;
    E4F0Block256 m_block08;
    E4F0Block256 m_block09;
    E4F0Block256 m_block10;
    E4F0Block256 m_block11;
    E4F0Block256 m_block12;
    E4F0Block256 m_block13;
    E4F0Block256 m_block14;
    E4F0Block256 m_block15;
    E4F0Block256 m_block16;
    E4F0Block256 m_block17;
    E4F0Block256 m_block18;
    E4F0Block256 m_block19;
    E4F0Block256 m_block20;
    E4F0Block256 m_block21;
    E4F0Block256 m_block22;
    E4F0Block256 m_block23;
    E4F0Block256 m_block24;
    E4F0Block256 m_block25;
    E4F0Block256 m_block26;
    E4F0Block256 m_block27;
    E4F0Block256 m_block28;
    E4F0Block256 m_block29;
    E4F0Block256 m_block30;
    E4F0Block256 m_block31;
    E4F0Block256 m_block32;
    E4F0Block256 m_block33;
    int unk2200;
    int unk2204;
    int unk2208;
    int unk220C;
    int unk2210;
    int unk2214;
    int unk2218;
    int unk221C;
    int unk2220;
    int unk2224;
    int unk2228;
    int unk222C;
    int unk2230;
    int unk2234;
    int unk2238;
    int unk223C;
    int unk2240;
    int unk2244;
    int unk2248;
    int unk224C;
    int unk2250;
    int unk2254;
    int unk2258;
    int unk225C;
    int unk2260;
    int unk2264;
    int unk2268;
    int unk226C;
    int unk2270;
    int unk2274;
    int unk2278;
    int unk227C;
    int unk2280;
    int m_aiLineY[32];

    int Print(const char* pcText, float fX, float fY, int iFlags, int m_iPayloadInteger, float fScale, int iUnused, const RgbaColor* pkColor);
    int PrintFormattedLine(int iX, int iLine, int iFlags, const char* pcFormat, char* pArgs, const RgbaColor* pkColor);
};
// 256-byte span of not-yet-identified fields.
struct A0E5C0Block {
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
};
int FUN_00ecddf1(char* pcBuffer, unsigned int uiSize, const char* pcFormat, char* pArgs);
class A0E5C0DebugText {
public:
    A0E5C0Block m_kBlock00;
    A0E5C0Block m_kBlock01;
    A0E5C0Block m_kBlock02;
    A0E5C0Block m_kBlock03;
    A0E5C0Block m_kBlock04;
    A0E5C0Block m_kBlock05;
    A0E5C0Block m_kBlock06;
    A0E5C0Block m_kBlock07;
    A0E5C0Block m_kBlock08;
    A0E5C0Block m_kBlock09;
    A0E5C0Block m_kBlock10;
    A0E5C0Block m_kBlock11;
    A0E5C0Block m_kBlock12;
    A0E5C0Block m_kBlock13;
    A0E5C0Block m_kBlock14;
    A0E5C0Block m_kBlock15;
    A0E5C0Block m_kBlock16;
    A0E5C0Block m_kBlock17;
    A0E5C0Block m_kBlock18;
    A0E5C0Block m_kBlock19;
    A0E5C0Block m_kBlock20;
    A0E5C0Block m_kBlock21;
    A0E5C0Block m_kBlock22;
    A0E5C0Block m_kBlock23;
    A0E5C0Block m_kBlock24;
    A0E5C0Block m_kBlock25;
    A0E5C0Block m_kBlock26;
    A0E5C0Block m_kBlock27;
    A0E5C0Block m_kBlock28;
    A0E5C0Block m_kBlock29;
    A0E5C0Block m_kBlock30;
    A0E5C0Block m_kBlock31;
    A0E5C0Block m_kBlock32;
    A0E5C0Block m_kBlock33;
    int unk2200;
    int unk2204;
    int unk2208;
    int unk220C;
    int unk2210;
    int unk2214;
    int unk2218;
    int unk221C;
    int unk2220;
    int unk2224;
    int unk2228;
    int unk222C;
    int unk2230;
    int unk2234;
    int unk2238;
    int unk223C;
    int unk2240;
    int unk2244;
    int unk2248;
    int unk224C;
    int unk2250;
    int unk2254;
    int unk2258;
    int unk225C;
    int unk2260;
    int unk2264;
    int unk2268;
    int unk226C;
    int unk2270;
    int unk2274;
    int unk2278;
    int unk227C;
    int m_iLineHeight;
    int m_aiY[3];
    int m_aiX[3];

    int Print(const char* pcText, float fX, float fY, int m_iPayloadInteger, int iAlign, float fScale, int iFlags, const RgbaColor* pkColor);
    int PrintFormattedAtSlot(int iSlot, int m_iPayloadInteger, const char* pcFormat, char* pArgs, const RgbaColor* pkColor);
};
struct ListNode_b5742 {
    ListNode_b5742* m_00;
    ListNode_b5742* m_04;
    unsigned int m_08;
};
struct FUN_00aa4060_shell {
    void __thiscall FUN_00aa4060(void* p);
};
extern FUN_00aa4060_shell DAT_011f6238;
struct FUN_00a1c080_shell {
    unsigned int __thiscall PopFront();
};
struct FUN_00a11fa0_shell {
    unsigned int __thiscall RemoveNextNode();
};
struct FUN_00a11e10_cls {
    ListNode_b5742* m_00;
    ListNode_b5742* m_04;
    unsigned int m_08;

    unsigned int RemoveNode(ListNode_b5742** pNode);
};
struct FUN_00a11ee0_cls {
    virtual void* Slot0();
    virtual void* Alloc(unsigned int count);
    void** m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    void Grow(unsigned int newCap, unsigned int oldSize);
    unsigned int FUN_00a11ee0();
};
struct Point2DResult {
    float fX;
    float fY;
    int iFlags;
    int iUnk0C;
    int iResult;
};
struct DebugTextItem { Point2DResult* pData; };
struct DebugTextEntry {
    float fX;
    float fY;
    int iFlags;
    int iUnk0C;
    int iResult;
    char pad[0x2c - 0x14];
};
struct FUN_00a10630_shell {
    int unk0000;
    DebugTextEntry m_aEntries[200];
    char pad2264[0x2270 - 0x2264];
    void* m_pVtbl;
    DebugTextItem** m_ppItems;
    unsigned int m_uiItemCount;
    int FindDebugTextResult(float fX, float fY, int iFlags);
};

struct ThreadDataD9 {
    unsigned m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    unsigned m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    unsigned m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    unsigned m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    unsigned m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    unsigned m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    unsigned m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    unsigned m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    unsigned m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    unsigned m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    unsigned m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    unsigned m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    unsigned m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    unsigned m_1a0, m_1a4, m_1a8, m_1ac, m_1b0, m_1b4, m_1b8, m_1bc;
    unsigned m_1c0, m_1c4, m_1c8, m_1cc, m_1d0, m_1d4, m_1d8, m_1dc;
    unsigned m_1e0, m_1e4, m_1e8, m_1ec, m_1f0, m_1f4, m_1f8, m_1fc;
    unsigned m_200, m_204, m_208, m_20c, m_210, m_214, m_218, m_21c;
    unsigned m_220, m_224, m_228, m_22c, m_230, m_234, m_238, m_23c;
    unsigned m_240, m_244, m_248, m_24c, m_250, m_254, m_258, m_25c;
    unsigned m_260, m_264, m_268, m_26c, m_270, m_274, m_278, m_27c;
    unsigned m_280, m_284, m_288, m_28c, m_290, m_294, m_298, m_29c;
    unsigned m_2a0, m_2a4, m_2a8, m_2ac, m_2b0;
    unsigned m_uiMemoryContext;
};
__declspec(thread) ThreadDataD9 threadDataD9;
inline unsigned GetCtxD9() { return threadDataD9.m_uiMemoryContext; }
inline void SetCtxD9(unsigned v) { threadDataD9.m_uiMemoryContext = v; }
struct ScopedCtxD9 {
    unsigned previous;
    ScopedCtxD9(unsigned value) { previous = GetCtxD9(); SetCtxD9(value); }
    ~ScopedCtxD9() { SetCtxD9(previous); }
};
struct K16D9 { int a, b, c, d; };
struct K256D9 { K16D9 k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, ka, kb, kc, kd, ke, kf; };
struct K4096D9 { K256D9 k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, ka, kb, kc, kd, ke, kf; };
struct PendingD9 {
    K4096D9 m_kPointA, m_kPointB;
    K256D9 m_iThirdValue, m_iFourthElementInteger;
    K16D9 m_e0, m_e1, m_e2, m_e3, m_e4, m_e5, m_e6, m_e7, m_e8;
    int m_f0, m_f1, m_f2;
    PendingD9();
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { g_011f6238.FUN_00aa4060((PendingObj*)p); }
};
extern PendingD9* DAT_011f33a8;
// @fnv 0x00a0d9e0
PendingD9* FUN_00a0d9e0(bool bCreate)
{
    if (!DAT_011f33a8 && bCreate)
    {
        ScopedCtxD9 kCtx(13);
        DAT_011f33a8 = new PendingD9;
    }
    return DAT_011f33a8;
}

bool FUN_00702360();
void FUN_00a11820();
void ReleaseLock();
extern float DAT_011f63a0;
inline float GetElapsed() { float value=DAT_011f63a0; return value; }
struct SceneNode;
extern int (__stdcall* LocalDecrement)(void*);
extern int (__stdcall* LocalIncrement)(void*);
inline int DecrementRef(void* value) { return LocalDecrement(value); }
inline int IncrementRef(void* value) { return LocalIncrement(value); }
struct Owner {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
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
 virtual void Remove(SceneNode*);
};
struct SceneNode {
 virtual void slot0();
 virtual void DeleteThis();
 unsigned refs; int unk08; int unk0c; int unk10; int unk14; Owner* parent;
 unsigned GetRefs() const { return refs; }
 Owner* GetParent() const { return parent; }
 void AcquireReference() { IncrementRef(&refs); }
 void DecRef() { if (!DecrementRef(&refs)) DeleteThis(); }
};
struct NodePtr {
 SceneNode* ptr;
 NodePtr& FUN_0066b0d0(SceneNode* value) {
  if (ptr != value) {
   if (ptr) ptr->DecRef();
   ptr=value;
   if (ptr) ptr->AcquireReference();
  }
  return *this;
 }
 ~NodePtr() { SceneNode* object=ptr; if(object) object->DecRef(); }
 __forceinline operator SceneNode*() const { return ptr; }
};
unsigned LocalStringLength(const char*);
void* LocalCopy(void*,const void*,unsigned);
struct TextString {
 char* text; unsigned short length, capacity;
 unsigned MaxLength() const { return capacity; }
 void SetMaxLength(unsigned size) { capacity=static_cast<unsigned short>(size<=65535?size:65535); }
 void SetLength(unsigned size) { length=static_cast<unsigned short>(size<=65535?size:65535); }
 bool FUN_004037f0(const char* source,unsigned size) {
  unsigned len=source?LocalStringLength(source):0;
  unsigned cap=len>size?len:size;
  if (cap<=MaxLength()) {
   if (cap) {
    if (source) LocalCopy(text,source,len+1);
    else *text=0;
   } else {
    if (text) delete[] text;
    text=0; cap=0; SetMaxLength(cap);
   }
  } else {
   char* old=text;
   text=new char[cap+1];
   if (source) LocalCopy(text,source,len+1);
   else *text=0;
   if (old) delete[] old;
   SetMaxLength(cap);
  }
  SetLength(len);
  return len!=0;
 }
 ~TextString() { TextString* value=this; value->FUN_004037f0(0,0); }
 __forceinline void Clear() { TextString* target=this; target->FUN_004037f0(0,0); }
};
struct Entry {
 float x,y; int active; NodePtr node; TextString text; float lifetime; int unk1c,unk20,unk24,unk28;
};
struct DynamicEntry {
 int unk00,unk04,unk08; NodePtr node; TextString text; float lifetime;
 ~DynamicEntry() { text.Clear(); }
 static void operator delete(void* p) { DAT_011f6238.FUN_00aa4060(p); }
};
struct Link { Link* next; Link* prev; DynamicEntry* data; static void operator delete(void* value) { DAT_011f6238.FUN_00aa4060(value); } };
struct TextList {
 Link* first; Link* last; unsigned count;
 __forceinline Link* GetFirst() { return first; }
 __forceinline DynamicEntry*& Next(Link*& iter) { DynamicEntry** value = &iter->data; iter=iter->next; return *value; }
 Link* Find(DynamicEntry*& entry,Link* iter=0) {
  if (!iter) iter=first;
  while(iter) {
   Link* current=iter;
   iter=iter->next;
   if(entry==current->data) return current;
  }
  return 0;
 }
 DynamicEntry* RemoveFirst();
 DynamicEntry* RemoveLast();
 DynamicEntry* RemoveNode(Link*& position) {
  Link* current=position;
  bool isFirst=current==first;
  if(isFirst) { position=current->next; return RemoveFirst(); }
  bool isLast=current==last;
  if(isLast) { position=0; return RemoveLast(); }
  Link* previous=current->prev;
  Link* next=current->next;
  position=next;
  if(previous) previous->next=next;
  if(next) next->prev=previous;
  DynamicEntry* data=current->data;
  current->data=0;
  delete current;
  --count;
  return data;
 }
 DynamicEntry* FUN_00a11c40(DynamicEntry*& entry) {
  Link* position=Find(entry);
  return position?RemoveNode(position):entry;
 }
};
struct DebugState {
 int unk00;
 Entry entries[200];
 TextList list;
 static DebugState* FUN_00a0d9e0(bool);
};
Owner* FUN_00706d10();
// @fnv 0x00a0df80
void FUN_00a0df80() {
 if (FUN_00702360()) return;
 DebugState* _debug = DebugState::FUN_00a0d9e0(true);
 for (int index=0; index<200; ++index) {
  if (_debug->entries[index].lifetime > 0.0) {
   _debug->entries[index].lifetime -= GetElapsed();
   if (_debug->entries[index].lifetime <= 0.0) {
    if (_debug->entries[index].node) {
     FUN_00a11820();
     FUN_00706d10()->Remove(_debug->entries[index].node);
     _debug->entries[index].node.FUN_0066b0d0(0);
     _debug->entries[index].active=0;
     _debug->entries[index].x=0.0f;
     _debug->entries[index].y=0.0f;
     _debug->entries[index].text.Clear();
     _debug->entries[index].lifetime=-1.0f;
     ReleaseLock();
    }
   }
  }
 }
 Link* iter=_debug->list.GetFirst();
 while (iter) {
  DynamicEntry* entry2=_debug->list.Next(iter);
  if (((SceneNode*)entry2->node)->GetRefs()<2) {
   delete _debug->list.FUN_00a11c40(entry2);
  } else if (entry2->lifetime>0.0) {
   entry2->lifetime-=GetElapsed();
   if (entry2->lifetime<0.0) {
    FUN_00a11820();
    ((SceneNode*)entry2->node)->GetParent()->Remove(entry2->node);
    entry2->node.FUN_0066b0d0(0);
    ReleaseLock();
    delete _debug->list.FUN_00a11c40(entry2);
   }
  }
 }
}

namespace fnv_00a0fe20 {
// ---- extra declarations for 0x00a0fe20 ----
extern "C" unsigned char DAT_011c70eb;
extern Setting DAT_011f33bc;
extern "C" __declspec(thread) int DAT_00a0fe20_tlsstate;
extern "C" unsigned long __readfsdword(unsigned long);

unsigned char __cdecl FUN_00703d50();
float __cdecl FUN_00706df0();
int __cdecl FUN_00706d10();
void __cdecl ReleaseLock();

inline int A0FE20GetState() { return DAT_00a0fe20_tlsstate; }
inline void A0FE20SetState(int s) { DAT_00a0fe20_tlsstate = s; }

inline int A0FE20Bit() { return 1; }

inline int& A0FE20DefColorRef() {
    int& r = *(&DAT_011f33bc ? &DAT_011f33bc.value : (DAT_01202800 = 0, &DAT_01202800));
    return r;
}
inline int& A0FE20DefSlotRef() {
    int& r = *(&DAT_011f33c8 ? &DAT_011f33c8.value : (DAT_01202800 = 0, &DAT_01202800));
    return r;
}

inline void A0FE20UnpackColor(unsigned int packed, unsigned int& r, unsigned int& g, unsigned int& b, unsigned int& a) {
    r = (packed >> 24) & 0xff;
    g = (packed >> 16) & 0xff;
    b = (packed >> 8) & 0xff;
    a = packed & 0xff;
}

struct A0FE20StateGuard {
    int m_old;
    A0FE20StateGuard(int s) { m_old = A0FE20GetState(); A0FE20SetState(s); }
    ~A0FE20StateGuard() { A0FE20SetState(m_old); }
};

struct A0FE20NiP3 {
    float x, y, z;
    A0FE20NiP3(float fx, float fy, float afDepth) { x = fx; y = fy; z = afDepth; }
};
struct A0FE20Col {
    float r, g, b, a;
    A0FE20Col() {}
    A0FE20Col(float fr, float fg, float fb, float fa) { r = fr; g = fg; b = fb; a = fa; }
};
struct A0FE20Upd {
    float fTime;
    bool b0, b1, b2, b3, b4;
};
struct A0FE20Str {
    void* p0;
    unsigned int u4;
    A0FE20Str(char*);
    bool FUN_004037f0(const char*, unsigned int);
    ~A0FE20Str() { FUN_004037f0(0, 0); }
};
struct A0FE20VT55 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(void*, int);
};
struct A0FE20Res {
    
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    A0FE20NiP3 m_pos;
    void SetPosition(float x, float y, float z) { m_pos = A0FE20NiP3(x, y, z); }
    void* FUN_00a59d30(int);
};
struct A0FE20Property {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    A0FE20Col color;
};
struct A0FE20Rec {
    A0FE20Res* FUN_00a12460(float, float, float, A0FE20Str*, int*, int, A0FE20Col*, int, int);
};
class NiMemObjectBase {
public:
    static void* operator new(unsigned int);
};
struct A0FE20MemoryFree { void Deallocate(void*); };
struct A0FE20PropertyState {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    A0FE20PropertyState();
    ~A0FE20PropertyState();
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((A0FE20MemoryFree*)&g_memoryManager)->Deallocate(p); }
};
unsigned int FUN_0040fc90();
int FUN_0043b460(volatile long*, long, long);
void FUN_0040fca0(unsigned long);
void FUN_0040fbe0();
struct A0FE20Lock {
    volatile long owner;
    unsigned int depth;
    void Lock(const char*) {
        unsigned int threadId = FUN_0040fc90();
        if (owner == threadId) ++depth;
        else {
            unsigned int spins = 0;
            while (FUN_0043b460(&owner, 0, threadId)) {
                ++spins;
                if (spins > 10000) FUN_0040fca0(1);
                else FUN_0040fca0(0);
            }
            FUN_0040fbe0();
            depth = 1;
        }
    }
};
extern A0FE20Lock DAT_011f42a0;
extern unsigned int DAT_011f42a4;
struct A0FE20ScopedLock {
    A0FE20Lock& lock;
    A0FE20ScopedLock(A0FE20Lock& l) : lock(l) { lock.Lock(0); }
    ~A0FE20ScopedLock() { if (--DAT_011f42a4 == 0) lock.owner = 0; }
};
struct A0FE20PropertyParent { void FUN_00a5e3a0(A0FE20PropertyState*&); };
struct A0FE20PropertyDispatch {
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
    virtual void UpdatePropertiesDownwardPass(A0FE20PropertyState*);
};
class TESObjectDoorController : public NiMemObjectBase {
public:
    TESObjectDoorController(unsigned int);
    void Update(A0FE20Upd const&);
    void FUN_00a5a040() {
        A0FE20PropertyState* state = 0;
        A0FE20ScopedLock guard(DAT_011f42a0);
        A0FE20PropertyParent* parent = (A0FE20PropertyParent*)unk18;
        if (parent) parent->FUN_00a5e3a0(state);
        else state = new A0FE20PropertyState;
        A0FE20PropertyDispatch* object = (A0FE20PropertyDispatch*)this;
        object->UpdatePropertiesDownwardPass(state);
        delete state;
    }
    void* m_pVtbl;          // 0x00
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;        // 0x04..0x2f
    int m_flags;            // 0x30
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;         // 0x34..0x57
    A0FE20NiP3 m_pos;
    void SetPosition(float x, float y, float z) { m_pos = A0FE20NiP3(x, y, z); }       // 0x58
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;        // 0x64..0xab
};
inline A0FE20Rec** A0FE20RecTable() { A0FE20Rec** p = (A0FE20Rec**)DAT_011f33f8; return p; }
inline A0FE20Rec* A0FE20RecAt(int i) { return A0FE20RecTable()[i - 1]; }
struct A0FE20Cls {
    TESObjectDoorController* FUN_00a0fe20(char*, float, float, int, int, A0FE20Col*);
};

// @fnv 0x00a0fe20
TESObjectDoorController* A0FE20Cls::FUN_00a0fe20(char* pcText, float fX, float fY, int iMode, int iSlot, A0FE20Col* pkColor)
{
    A0FE20StateGuard ao(13);

    if (!*pcText) return 0;
    if (!FUN_00703d50() && !FUN_00702fc0()) return 0;

    float aj = 1.0f;
    if (DAT_011c70eb) aj = 1.33333f;
    fX = (fX - 640.0) * aj;
    fY = (FUN_00706df0() - fY) - FUN_00706df0() / 2.0;

    int ad = 1;
    if (iMode == 3) ad = 4;
    else if (iMode == 2) ad = 2;

    TESObjectDoorController* aw = 0;
    int ae = 0;
    unsigned int ac, ap, bq, bi;
    aw = new TESObjectDoorController(0);

    A0FE20Col aa;
    aa.r = 0.0f; aa.g = 0.0f; aa.b = 0.0f; aa.a = 0.0f;
    if (pkColor) {
        aa = *pkColor;
    } else {
        A0FE20UnpackColor(A0FE20DefColorRef(), ac, ap, bq, bi);
        aa = A0FE20Col((double)ac / 255.0, (double)ap / 255.0,
                      (double)bq / 255.0, (double)bi / 255.0);
    }

    A0FE20Str an(pcText);

    int ak = iSlot;
    if (!ak) ak = A0FE20DefSlotRef();
    A0FE20Res* ab = A0FE20RecAt(ak)->FUN_00a12460(0.0f, 0.0f, 0.0f, &an, &ae, ad, &aa, 1, 1);
    ab->SetPosition(0.0f, 0.0f, 0.0f);
    ((A0FE20VT55*)aw)->v55(ab, 1);

    void* af = ab->FUN_00a59d30(3);
    if (af) ((A0FE20Property*)af)->color = aa;

    if (0) aw->m_flags |= A0FE20Bit();
    else aw->m_flags &= ~A0FE20Bit();

    FUN_00a11820();
    if (FUN_00706d10()) {
        ((A0FE20VT55*)FUN_00706d10())->v55(aw, 1);
    }
    aw->SetPosition(fX, -50.0f, fY);
    aw->FUN_00a5a040();

    A0FE20Upd ah;
    ah.fTime = 0.0f;
    ah.b0 = 0; ah.b1 = 0; ah.b2 = 0; ah.b3 = 0; ah.b4 = 0;
    aw->Update(ah);

    ReleaseLock();
    return aw;
}
}  // namespace fnv_00a0fe20

struct FUN_00a1c800_A {
    int unk00;
    void* FUN_00a0be10(unsigned int flags);
};
struct FUN_00a1c800_B {
    int unk00;
    ~FUN_00a1c800_B();
    static void operator delete(void* p) { DAT_011f6238.FUN_00aa4060(p); }
};
struct FUN_00a1c800_MapA {
    void* vtbl;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    void* GetFirstPos() {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i]) return m_ppkHashTable[i];
        }
        return 0;
    }
    void FUN_00a0c850(void*& pos, unsigned int& key, FUN_00a1c800_A*& val);
// @fnv 0x00a1c800
    void GetNext(void*& pos, unsigned int& key, FUN_00a1c800_A*& val) {
        int u1; int u2; int u3; int u4; int u5;
        FUN_00a0c850(pos, key, val);
    }
    void ClearAll();
};
struct FUN_00a1c800_MapB {
    void* vtbl;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    void* GetFirstPos() {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i]) return m_ppkHashTable[i];
        }
        return 0;
    }
    void FUN_00a0c850(void*& pos, unsigned int& key, FUN_00a1c800_B*& val);
    void GetNext(void*& pos, unsigned int& key, FUN_00a1c800_B*& val) {
        int w1; int w2; int w3; int w4;
        FUN_00a0c850(pos, key, val);
    }
    void ClearAll();
};
extern FUN_00a1c800_MapA DAT_011f34e0;
extern FUN_00a1c800_MapB DAT_011f34f4;
void FUN_00a1c800()
{
    void* pos2;
    void* iter;
    FUN_00a1c800_A* v1;
    unsigned int key;
    FUN_00a1c800_B* val2;
    unsigned int k2;
    FUN_00a1c800_A* t;
    FUN_00a1c800_A* node;
    iter = DAT_011f34e0.GetFirstPos();
    while (iter) {
        DAT_011f34e0.GetNext(iter, key, v1);
        if (v1) {
            node = v1;
            t = node;
            t ? t->FUN_00a0be10(1) : 0;
        }
    }
    DAT_011f34e0.ClearAll();
    pos2 = DAT_011f34f4.GetFirstPos();
    while (pos2) {
        DAT_011f34f4.GetNext(pos2, k2, val2);
        if (val2) delete val2;
    }
    DAT_011f34f4.ClearAll();
}

extern const float DAT_01012054;
void* __cdecl FUN_00ec61c0(void*,int,unsigned);
extern long (__stdcall* DecrementD)(void*);
extern long (__stdcall* IncrementD)(void*);
inline long DecD(void* p) { return DecrementD(p); }
inline long IncD(void* p) { return IncrementD(p); }
struct SceneNodeD {
 virtual void slot0();
 virtual void DeleteThis();
 unsigned refs;
 void DecRef() { if(!DecD(&refs)) DeleteThis(); }
 void AcquireReference() { IncD(&refs); }
};
struct NodePtrD {
 SceneNodeD* ptr;
 NodePtrD& operator=(SceneNodeD* p) {
  if(ptr!=p) {
   if(ptr) ptr->DecRef();
   ptr=p;
   if(ptr) ptr->AcquireReference();
  }
  return *this;
 }
};
unsigned StringLengthD(const char*);
void* CopyTextD(void*,const void*,unsigned);
inline unsigned CapacityMaximumD(unsigned a,unsigned b) { return a>b?a:b; }
struct TextStringD {
 char* text; unsigned short length,capacity;
 unsigned MaxLength() const { return capacity; }
 void SetMaxLength(unsigned n) { capacity=static_cast<unsigned short>(n<=65535?n:65535); }
 void SetLength(unsigned n) { length=static_cast<unsigned short>(n<=65535?n:65535); }
 bool FUN_004037f0(const char* source,unsigned size) {
  unsigned len=source?StringLengthD(source):0;
  unsigned cap=CapacityMaximumD(len,size);
  unsigned available=MaxLength();
  if(cap<=available) {
   if(cap) {
    if(source) CopyTextD(text,source,len+1);
    else *text=0;
   } else {
    if(text) delete[] text;
    text=0; cap=0; SetMaxLength(cap);
   }
  } else {
   char* old=text;
   unsigned allocationSize=cap+1;
   text=new char[allocationSize];
   if(source) CopyTextD(text,source,len+1);
   else *text=0;
   if(old) delete[] old;
   SetMaxLength(cap);
  }
  SetLength(len);
  return len!=0;
 }
 TextStringD& operator=(const char* source) { FUN_004037f0(source,0); return *this; }
};
struct LineD {
 float x,y; int active; NodePtrD node; TextStringD text; float lifetime;
 int unk1c,unk20,unk24,unk28;
 LineD(); ~LineD();
};
struct TextListD {
 void* first; void* last; unsigned count;
 TextListD() { count=0; first=0; last=0; }
 ~TextListD();
};
inline void* operator new(unsigned size,void* p) { return p; }
struct ArrayD {
 virtual void slot0();
 virtual void** Allocate(unsigned);
 virtual void Free(void*);
 void** data; unsigned size,capacity;
 void Initialize(unsigned reserved,unsigned count) {
  data=0; size=0; capacity=0;
  if(count>reserved) reserved=count;
  if(reserved>0) { data=Allocate(reserved); capacity=reserved; }
  if(count>0) {
   for(unsigned i=0;i<count;++i) new (&data[i]) void*;
   size=count;
  }
 }
 ArrayD() { Initialize(0,0); }
 void Clear(bool release) {
  if(data) {
   typedef void* Element;
   for(unsigned i=0;i<size;++i) data[i].~Element();
   if(release) { Free(data); data=0; data=0; capacity=0; }
   size=0;
  }
 }
 ~ArrayD() { Clear(true); }
};
struct DebugBaseD {
 DebugBaseD() {}
 virtual void f();
};
struct FUN_00a0db40 : DebugBaseD {
 LineD lines[200];
 TextListD list;
 ArrayD array;
 int unk2280;
 int first[3]; int second[3];
 virtual void f();
 FUN_00a0db40();
};
// @fnv 0x00a0db40
FUN_00a0db40::FUN_00a0db40() {
 for (int i=0;i<200;++i) {
  lines[i].x=0.0f;
  lines[i].y=0.0f;
  lines[i].active=0;
  lines[i].node=0;
  lines[i].text=0;
  lines[i].lifetime=DAT_01012054;
 }
 unk2280=0;
 FUN_00ec61c0(first,0,12);
 FUN_00ec61c0(second,0,12);
}

inline void DeadQ3(){int a[3];}
inline void DeadQ15(){int a[15];}
struct BSStrQ { char* m_data; unsigned short m_len; unsigned short m_kMaximumCorner; bool Set(const char* s, unsigned int n); BSStrQ& operator=(const char* s) { Set(s, 0); return *this; } };
struct FUN_00a11880 {
    float f0; float f4; int i8; void* m_ptr; BSStrQ m_str; float f18; float c[4];
    FUN_00a11880();
    void* operator new(unsigned int sz) { return g_memoryManager.Allocate(sz); }
    void SetName(const char* s) { m_str.Set(s, 0); }
};
struct NodeQ {
    FUN_00a11880* ent; int unk4; int key; int unk0c; int unk10; int unk14;
    void* operator new(unsigned int sz) { return g_memoryManager.Allocate(sz); }
};
struct ArrQ : BSSimpleArray {
    unsigned int m_iElementCount;
    unsigned int Count() { return m_iElementCount; }
};
struct MgrQ {
    int unk[0x2270 / 4];
    ArrQ m_kNode;
    int FUN_00a0f730(const char* name, int key);
};
// @fnv 0x00a0f730
int MgrQ::FUN_00a0f730(const char* name, int key)
{
    bool found = false;
    for (unsigned int i = 0; !found && i < m_kNode.Count(); i++) {
        if (((NodeQ*)m_kNode.m_data[i])->key == key) {
            ((NodeQ*)m_kNode.m_data[i])->ent->m_str = name;
            ((NodeQ*)m_kNode.m_data[i])->unk4 = 0;
            found = true;
        }
    }
    if (!found) {
        FUN_00a11880* e = new FUN_00a11880;
 DeadQ15();         e->m_str = name;
        NodeQ* n = new NodeQ;
        n->key = key;
        n->ent = e;
        n->unk4 = 0;
        m_kNode.FUN_00a11d20((void*&)n);
    }
 DeadQ3();     return key;
}

struct NiRTTI {
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

struct NiObject {
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI* GetRTTI() const;
    int unk04, unk08, unk0c, unk10, unk14;
    NiObject* m_pParentNode;
};

extern NiRTTI DAT_011f4428;
unsigned char __cdecl FUN_00a10c00(NiObject* pkObject, int a, int b, float c);

__forceinline bool KindOfRTTI(const NiRTTI& kRTTI, const NiObject* pkObject)
{
    const NiRTTI* pkRTTI = pkObject->GetRTTI();
    while (pkRTTI) {
        if (pkRTTI == &kRTTI)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

template <class T>
inline T* CastIfKind(const NiRTTI& kRTTI, NiObject* pkObject)
{
    if (!pkObject)
        return 0;
    return KindOfRTTI(kRTTI, pkObject) ? (T*)pkObject : 0;
}

template <class T>
__forceinline T* CastParentIfKind(const NiRTTI& kRTTI, NiObject* pkObject)
{
    NiObject* pkParent = pkObject->m_pParentNode;
    if (!pkParent)
        return 0;
    return KindOfRTTI(kRTTI, pkParent) ? (T*)pkParent : 0;
}

// @fnv 0x00a11470
unsigned char __cdecl FUN_00a11470(NiObject* pkObject, int a, int b, float c)
{
    NiObject* pkCast = CastIfKind<NiObject>(DAT_011f4428, pkObject);
    if (pkCast == 0 && pkObject != 0)
        pkCast = CastParentIfKind<NiObject>(DAT_011f4428, pkObject);
    if (pkCast != 0)
        return FUN_00a10c00(pkCast, a, b, c);
    else
        return 0;
}

namespace fnv_00a11560 {
struct NiRTTI {
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

extern NiRTTI DAT_011f4428;

struct A11560Obj {
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI* GetRTTI() const;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    A11560Obj* unk18;

    inline bool IsKindOfType(const NiRTTI* pkRTTI) const {
        const NiRTTI* pkParent = GetRTTI();
        while (pkParent) {
            if (pkParent == pkRTTI)
                return true;
            pkParent = pkParent->m_pBaseRTTI;
        }
        return false;
    }
};

void __cdecl FUN_00a11640(A11560Obj* a, int b);

__forceinline A11560Obj* A11560ParentKind(A11560Obj* a) {
    A11560Obj* p = a->unk18;
    if (p == 0)
        return 0;
    return p->IsKindOfType(&DAT_011f4428) ? p : 0;
}

// @fnv 0x00a11560
void __cdecl FUN_00a11560(A11560Obj* a1, int a2) {
    A11560Obj* r;
    if (a1 == 0)
        r = 0;
    else
        r = a1->IsKindOfType(&DAT_011f4428) ? a1 : 0;
    if (r == 0 && a1 != 0)
        r = A11560ParentKind(a1);
    if (r)
        FUN_00a11640(r, a2);
}
}  // namespace fnv_00a11560

struct A11740Node {
    int unk00;
    A11740Node* next;
};

struct A11740Item {
    virtual void f0();
    virtual void f1();
    virtual A11740Node* f2();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct A11740Input {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    A11740Item** items;
    unsigned short count;
};

struct A11740Words {
    unsigned short s;
    unsigned short i;
};

inline unsigned char A11740HasMarker(A11740Node*& p)
{
    while (p != 0) {
        if (p == (A11740Node*)&g_011f33d4)
            return 1;
        p = p->next;
    }
    return 0;
}

// @fnv 0x00a11740
A11740Item* __cdecl FUN_00a11740(A11740Input* input, int unused, int expected, int* outValue)
{
    A11740Item* res;
    unsigned int indexB;
    A11740Item* slot8;
    A11740Node* cur;
    unsigned char tmp;
    unsigned char kk;
    A11740Words n;

    if (input == 0)
        return 0;
    res = 0;
    indexB = 0;
    while (indexB < (n.i = input->count)) {
        n.s = (unsigned short)indexB;
        slot8 = input->items[n.s];
        ++indexB;
        if (slot8 == 0) {
            kk = 0;
        } else {
            cur = slot8->f2();
            tmp = A11740HasMarker(cur);
            kk = tmp;
        }
        if (kk != 0) {
            res = slot8;
            if (res != 0) {
                *outValue = res->unk1c;
                if (expected == res->unk18)
                    break;
            }
            res = 0;
        }
    }
    return res;
}

namespace fnv_00a11880 {
inline void DeadQ1(){int a[1];}
inline void DeadQ9(){int a[9];}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct RefQ { void* vt; long m_uiRefCount; void IncRefCount() { InterlockedIncrement(&m_uiRefCount); } };
struct NP {
    RefQ* m_pObject;
    NP(RefQ* p = 0) { m_pObject = p; if (m_pObject) m_pObject->IncRefCount(); }
    ~NP();
    NP& operator=(void*);
};
struct BSStr {
    char* m_data; unsigned short m_len; unsigned short m_kMaximumCorner;
    BSStr(unsigned int a = 0, unsigned int b = 0) {
        m_data = 0;
        m_len = a <= 0xffff ? (unsigned short)a : 0xffff;
        m_kMaximumCorner = b <= 0xffff ? (unsigned short)b : 0xffff;
    }
    ~BSStr();
    bool Set(const char* s, unsigned int n);
    BSStr& operator=(const char* s) { Set(s, 0); return *this; }
};
inline void ClearS(BSStr& s) { s.Set(0, 0); }
struct NiColorQ { float r, g, b, a; NiColorQ() { r = 0; g = 0; b = 0; a = 0; } };
struct FUN_00a11880 {
    float f0; float f4; int i8; NP m_ptr; BSStr m_str; float f18; NiColorQ m_col;
    
    FUN_00a11880();
};
// @fnv 0x00a11880
FUN_00a11880::FUN_00a11880()
{
 DeadQ9();     f0 = 0; f4 = 0; i8 = 0;
    m_ptr = 0;
 DeadQ1();     m_str = (const char*)0;
    f18 = -1.0f;
}
}  // namespace fnv_00a11880

extern long (__stdcall *DAT_00fdf1c4)(long* value);
unsigned int __cdecl FUN_0044a670(const char* text);
unsigned int __cdecl FUN_00403940(unsigned int a, unsigned int b);
void* __cdecl FormHeap_Allocate(unsigned int size);
void __cdecl FormHeap_Free(void* p);
void* __cdecl FUN_00401460(void* dst, const void* src, unsigned int size);

struct NiRefObject_a119 {
    virtual ~NiRefObject_a119();
    virtual void DeleteThis();
    inline void DecRefCount() { if (DAT_00fdf1c4(&m_uiRefCount) == 0) DeleteThis(); }
    long m_uiRefCount;
};

template <class T> struct NiPointer_a119 {
    inline ~NiPointer_a119()
    {
        if (m_pObject) {
            m_pObject->DecRefCount();
        }
    }
    T* m_pObject;
};

template <class T> class BSStringT {
public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;

    inline ~BSStringT() { Set(0, 0); }
    inline BSStringT& Clear() { Set(0, 0); return *this; }
    unsigned int MaxLength();
    void SetLength(unsigned int length);
    void SetMaxLength(unsigned int length);
    inline bool Set(const T* text, unsigned int length)
    {
        unsigned int srcLen = text ? FUN_0044a670(text) : 0;
        unsigned int newLen = FUN_00403940(srcLen, length);
        unsigned int maxLen = MaxLength();
        if (newLen > maxLen) {
            T* oldString = pString;
            T* newString = (T*)FormHeap_Allocate(newLen + 1);
            pString = newString;
            if (text)
                FUN_00401460(pString, text, srcLen + 1);
            else
                *pString = 0;
            if (oldString) {
                T* p = oldString;
                FormHeap_Free(p);
            }
            SetMaxLength(newLen);
        } else if (newLen) {
            if (text)
                FUN_00401460(pString, text, srcLen + 1);
            else
                *pString = 0;
        } else {
            if (pString) {
                T* p = pString;
                FormHeap_Free(p);
            }
            pString = 0;
            newLen = 0;
            SetMaxLength(newLen);
        }
        SetLength(srcLen);
        bool result = srcLen != 0;
        return result;
    }
};

class FUN_00a119d0 {
public:
    ~FUN_00a119d0();
    int unk00;
    int unk04;
    int unk08;
    NiPointer_a119<NiRefObject_a119> m_pReferencedObject;
    BSStringT<char> m_kString;
};

// @fnv 0x00a119d0
FUN_00a119d0::~FUN_00a119d0()
{
    m_kString.Clear();
}

namespace fnv_00a11a80 {
struct FUN_00a7b2e0 {
    virtual ~FUN_00a7b2e0();
    FUN_00a7b2e0();
    int unk04;
    int unk08;
};

struct BSStringT {
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;

    BSStringT() {
        m_data = 0;
        SetLength(0);
        SetMaxLength(0);
    }
    ~BSStringT();
    void SetLength(unsigned int n) {
        m_dataLen = (unsigned short)(n <= 0xffff ? (unsigned int)(unsigned short)n : 0xffffu);
    }
    void SetMaxLength(unsigned int n) {
        m_bufLen = (unsigned short)(n <= 0xffff ? (unsigned int)(unsigned short)n : 0xffffu);
    }
    bool Set(const char* src, unsigned int maxLen);

    struct Hold {
        BSStringT* ptr;
        int slot1;
        int slot2;
        int slot3;
        int slot4;
        int slot5;
        int slot6;
        int slot7;
        int slot8;
    };

    __forceinline void Apply(const char* name) {
        Hold h;
        h.ptr = this;
        h.ptr->Set(name, 0);
    }
};

struct FUN_00a11a80 : FUN_00a7b2e0 {
    int unk0c;
    BSStringT str;
    int unk18;
    int unk1c;
    FUN_00a11a80(int a, const char* name, int x, int y);
    virtual ~FUN_00a11a80();
};

// @fnv 0x00a11a80
FUN_00a11a80::FUN_00a11a80(int a, const char* name, int x, int y)
{
    unk0c = a;
    str.Apply(name);
    unk18 = x;
    unk1c = y;
}
}  // namespace fnv_00a11a80

struct NiMemObject {
    static void operator delete(void* memory, unsigned int size);
};

struct NiExtraData : NiMemObject {
    unsigned int m_uiRefCount;
    unsigned int m_pcName;
    virtual ~NiExtraData();
};

struct BSStr {
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    bool Set(const char* text, unsigned int length);
    inline ~BSStr() {
        int a0, a1, a2, a3, a4, a5, a6, a7;
        Set(0, 0);
    }
};

struct FUN_00a11b80 : NiExtraData {
    int unk0C;
    BSStr str;
    int unk18;
    int unk1C;
    FUN_00a11b80();
    virtual void Anchor();
};

// @fnv 0x00a11b80
FUN_00a11b80::FUN_00a11b80() {}
void FUN_00a11b80::Anchor() {}

struct A11Node { A11Node* next; A11Node* prev; unsigned int key; };
struct A11MM { void Deallocate(void*); };
extern A11MM g_a11mm;

struct A11List {
    A11Node* head;
    A11Node* tail;
    unsigned int count;

    inline A11Node* Find(unsigned int* aKey);
    inline unsigned int RemoveHead();
    inline unsigned int RemoveTail();
    inline unsigned int RemovePos(A11Node** p);
    unsigned int __thiscall FUN_00a11c40(unsigned int* aKey);
};

inline A11Node* A11List::Find(unsigned int* aKey) {
    A11Node* p5 = 0;
    A11Node* head4;
    A11Node* cur;
    unsigned int* pKey;
    if (p5 == 0) {
        head4 = head;
        p5 = head4;
    }
    while (p5 != 0) {
        cur = p5;
        pKey = &p5->key;
        p5 = p5->next;
        if (*aKey == *pKey)
            return cur;
    }
    return 0;
}

inline unsigned int A11List::RemoveHead() {
    A11Node* item = head;
    A11Node* elementHolder;
    unsigned int element;
    head = item->next;
    if (head)
        head->prev = 0;
    else
        tail = 0;
    element = item->key;
    elementHolder = item;
    g_a11mm.Deallocate(elementHolder);
    count = count - 1;
    return element;
}

inline unsigned int A11List::RemoveTail() {
    A11Node* item = tail;
    A11Node* elementHolder;
    unsigned int element;
    tail = item->prev;
    if (tail)
        tail->next = 0;
    else
        head = 0;
    element = item->key;
    elementHolder = item;
    g_a11mm.Deallocate(elementHolder);
    count = count - 1;
    return element;
}

inline unsigned int A11List::RemovePos(A11Node** p) {
    A11Node* item = *p;
    A11Node* prev;
    A11Node* next;
    unsigned int element;
    A11Node* tmp;
    if (item == head) {
        *p = item->next;
        return RemoveHead();
    }
    if (item == tail) {
        *p = 0;
        return RemoveTail();
    }
    prev = item->prev;
    next = item->next;
    *p = next;
    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    element = item->key;
    item->key = 0;
    tmp = item;
    g_a11mm.Deallocate(tmp);
    count = count - 1;
    return element;
}

// @fnv 0x00a11c40
unsigned int A11List::FUN_00a11c40(unsigned int* aKey) {
    A11Node* r7;
    r7 = Find(aKey);
    return r7 != 0 ? RemovePos(&r7) : *aKey;
}

namespace fnv_00a0dcc0 {
void __cdecl ReleaseLock();

extern int (__stdcall* LocalDecrement)(void*);
extern int (__stdcall* LocalIncrement)(void*);
inline int DecrementRef(void* value) { return LocalDecrement(value); }
inline int IncrementRef(void* value) { return LocalIncrement(value); }

struct SceneNode;

struct Owner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void Remove(SceneNode*);
};

struct SceneNode {
    virtual void slot0();
    virtual void DeleteThis();
    unsigned refs;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Owner* parent;
    unsigned GetRefs() const { return refs; }
    Owner* GetParent() const { return parent; }
    void AcquireReference() { IncrementRef(&refs); }
    void DecRef() { if (!DecrementRef(&refs)) DeleteThis(); }
};

struct NodePtr {
    SceneNode* ptr;
    NodePtr& FUN_0066b0d0(SceneNode* value);
    inline SceneNode* operator->() const { return ptr; }
    inline operator SceneNode*() const { return ptr; }
};

struct TextString {
    char* text;
    unsigned short length;
    unsigned short capacity;
};

struct Link {
    Link* next;
    Link* prev;
    struct DebugItem* data;
};

struct DebugItem {
    float x;
    float y;
    int active;
    NodePtr node;
    TextString text;
    float lifetime;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    ~DebugItem();
    static void operator delete(void* p) { g_011f6238.FUN_00aa4060((PendingObj*)p); }
};

struct ListGuard {
    ~ListGuard() {}
};

struct TextList {
    Link* first;
    Link* last;
    unsigned count;
    inline Link* GetFirst() { return first; }
    inline DebugItem*& Next(Link*& iter) {
        DebugItem** value = &iter->data;
        iter = iter->next;
        return *value;
    }
    inline DebugItem* FUN_00a11c40(DebugItem*& entry);
    void FUN_00a1c2d0();
    ~TextList() {
        TextList* self = this;
        ListGuard guard;
        self->FUN_00a1c2d0();
    }
};

inline DebugItem* TextList::FUN_00a11c40(DebugItem*& entry) {
    unsigned s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16;
    s0 = s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = s10 = s11 = s12 = s13 = s14 = s15 = s16 = 0;
    if (s0 == 1) return FUN_00a11c40(entry);
    return entry;
}

struct Helper2270 {
    virtual ~Helper2270();
};

struct FUN_00a0dcc0 {
    DebugItem items[200];
    TextList list;
    Helper2270 tail;
    void FUN_00a0de80();
    virtual ~FUN_00a0dcc0();
};

// @fnv 0x00a0dcc0
FUN_00a0dcc0::~FUN_00a0dcc0()
{
    FUN_00a0de80();
    Link* pos = list.GetFirst();
    FUN_00a11820();
    while (pos) {
        DebugItem* item = list.Next(pos);
        if (item->node->GetRefs() > 2) {
            item->node->GetParent()->Remove(item->node);
            item->node.FUN_0066b0d0(0);
        }
        delete list.FUN_00a11c40(item);
    }
    ReleaseLock();
}
}  // namespace fnv_00a0dcc0

namespace fnv_00a0de80 {
struct ObjVT {
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
    virtual void v58(void* aItem);
};

ObjVT* __cdecl FUN_00706d10();
void __cdecl ReleaseLock();

struct ItemSub {
    unsigned int m_00;
    unsigned int m_04;
    void Init(int a, int b);
};

struct ItemHolder {
    void* m_p;
    void Free(int a);
};

struct ArrayItem {
    unsigned int m_00;
    float m_04;
    float m_08;
    int m_0c;
    ItemHolder m_10;
    ItemSub m_14;
    float m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
};

struct FUN_00a0de80_cls {
    ArrayItem m_items[200];
    void FUN_00a0de80();
};

extern float DAT_01012054;

struct Scratch10 {
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24;
};

__forceinline void* Store(void*& out, ItemHolder& h) { return out = h.m_p; }

// @fnv 0x00a0de80
void FUN_00a0de80_cls::FUN_00a0de80() {
    FUN_00a11820();
    for (int i = 0; i < 200; i++) {
        void* item = m_items[i].m_10.m_p;
        if (item != 0) {
            Scratch10 buf;
            void* elem;
            FUN_00706d10()->v58(Store(elem, m_items[i].m_10));
            m_items[i].m_10.Free(0);
            m_items[i].m_0c = 0;
            m_items[i].m_04 = 0.0f;
            m_items[i].m_08 = 0.0f;
            ItemSub* sub = &m_items[i].m_14;
            sub->Init(0, 0);
            m_items[i].m_1c = DAT_01012054;
        }
    }
    ReleaseLock();
}
}  // namespace fnv_00a0de80

struct GlobalObject_00a7b610
{
    const char* m_pcName;
    const GlobalObject_00a7b610* m_pBaseRTTI;
    const GlobalObject_00a7b610* GetBaseRTTI() const { return m_pBaseRTTI; }
};

struct ListObject_a11640
{
    virtual void v0();
    virtual void v1();
    virtual const GlobalObject_00a7b610* GetRTTI() const;

    bool IsKindOfType(const GlobalObject_00a7b610* pkRTTI) const
    {
        const GlobalObject_00a7b610* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->GetBaseRTTI();
        }
        return false;
    }
};

inline bool ListIsKindOf_a11640(const GlobalObject_00a7b610* pkRTTI, ListObject_a11640* pkObject)
{
    if (!pkObject)
        return false;
    return pkObject->IsKindOfType(pkRTTI);
}

struct ListItem : ListObject_a11640
{
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};

template <class T> struct NiTArray
{
    int m_00;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short GetAllocatedSize() const { return m_usMaxSize; }
    T& GetAt(unsigned short usIndex) const { return m_pBase[usIndex]; }
};

struct ListOwner
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
    virtual void RemoveEntry(int iEntry);
    int m_04;
    int m_08;
    NiTArray<ListObject_a11640*> m_kUnsortedGeometryList;
};

// @fnv 0x00a11640
void __cdecl FUN_00a11640(ListOwner* pkOwner, int iEntry)
{
    ListItem* pkHit = 0;
    unsigned int i = 0;
    while (i < pkOwner->m_kUnsortedGeometryList.GetAllocatedSize())
    {
        ListObject_a11640* pkObject = pkOwner->m_kUnsortedGeometryList.GetAt(i++);
        if (ListIsKindOf_a11640(&g_011f33d4, pkObject) && (pkHit = (ListItem*)pkObject) != 0)
        {
            if (iEntry < 0)
            {
                pkOwner->RemoveEntry(pkHit->m_0c);
            }
            else if (iEntry == pkHit->m_18)
            {
                pkOwner->RemoveEntry(pkHit->m_0c);
                return;
            }
        }
    }
}

#include <string.h>
extern double DAT_01094f90;
extern unsigned char DAT_011c70eb;
extern __declspec(thread) unsigned int DAT_012722b4;
extern const char* DAT_0109b220;
int CompareInsensitive(const char*,const char*);
int CompareSensitive(const char*,const char*);
inline unsigned GetState() { return DAT_012722b4; }
inline void SetState(unsigned value) { DAT_012722b4=value; }
inline int& DefaultVoice() {
    int& r=*(&DAT_011f33c8 ? &DAT_011f33c8.value : (DAT_01202800=0,&DAT_01202800));
    return r;
}
struct ScopedThreadState {
    unsigned previous;
    ScopedThreadState(unsigned value) { previous=GetState(); SetState(value); }
    ~ScopedThreadState() { SetState(previous); }
};
struct AudioText : TextStringD {
    void SetTextLength(unsigned n) { length=n<=65535?(unsigned short)n:65535; }
    void SetTextCapacity(unsigned n) { capacity=n<=65535?(unsigned short)n:65535; }
    AudioText() { text=0; SetTextLength(0); SetTextCapacity(0); }
    ~AudioText() { FUN_004037f0(0,0); }
    AudioText& FUN_00438470(const AudioText&);
    int FUN_00408a80(const char* rhs,bool insensitive) const {
        int result;
        if(rhs && (const char*)*this)
            result=insensitive?CompareInsensitive((const char*)*this,rhs):CompareSensitive((const char*)*this,rhs);
        else if(!rhs && !(const char*)*this) result=0;
        else result=(rhs==0)*2-1;
        return result;
    }
    operator const char*() const { return text; }
    unsigned size() const { return length==65535 ? strlen((const char*)*this) : length; }
    char& operator[](unsigned i) { return text[text ? i:0]; }
    void CopyCharacter(unsigned out,unsigned pos) {
        unsigned outputIndex=out;
        char* output=text+(text?outputIndex:0);
        *output=text[text?pos:0];
    }
    char operator[](unsigned i) const { return text[text ? i:0]; }
    void clear() { FUN_004037f0(0,0); }
    bool equals(const char* rhs) const { return !FUN_00408a80(rhs,true); }
    AudioText& operator=(const AudioText& other) { FUN_00438470(other); return *this; }
};
struct FixedText {
    const char* text;
    FixedText(const char* p) {
        if(!p) text=DAT_0109b220;
        else text=FUN_00a5b690(p);
    }
    ~FixedText() {
        if(text==DAT_0109b220) return;
        DecrementRef((void*)(text-8));
    }
    static const char* __cdecl FUN_00a5b690(const char*);
};
struct Playback : SceneNode {
    void AssignFixedString(const FixedText&);
};
struct Color {
    float r,g,b,a;
    bool operator==(const Color& rhs) const { return r==rhs.r && g==rhs.g && b==rhs.b && a==rhs.a; }
};
struct AudioSource {
    float x,y;
    int identifier,flags;
    AudioText filename;
    int priority;
    Color color;
    ~AudioSource();
    static void operator delete(void* p) { DAT_011f6238.FUN_00aa4060(p); }
};
struct AudioRequest {
    AudioSource* source;
    unsigned kind,slot;
    int line;
    float duration;
    int voice;
    static void operator delete(void* p) { DAT_011f6238.FUN_00aa4060(p); }
};
struct RequestQueue {
    virtual void slot0();
    virtual void** Allocate(unsigned);
    virtual void Free(void*);
    AudioRequest** data;
    unsigned count,capacity;
    unsigned size() const { return count; }
    AudioRequest*& operator[](unsigned i) { return data[i]; }
    void FUN_00a1bfa0(bool release) {
        AudioRequest** oldData=data;
        if(oldData) {
            unsigned oldCount=count;
            typedef AudioRequest* Element;
            for(unsigned i=0;i<oldCount;++i) oldData[i].~Element();
            if(release) {
                void* allocation=oldData;
                Free(allocation); data=0; data=0; capacity=0;
            }
            count=0;
        }
    }
};
struct AudioSlot {
    float x,y;
    int identifier;
    NodePtr playback;
    AudioText filename;
    float duration;
    Color color;
};
struct AudioManager {
    void* vtable;
    AudioSlot slots[200];
    int unk2264,unk2268,unk226c;
    RequestQueue pending;
    Playback* FUN_00a0fe20(const char*,float,float,int,int,const Color*);
    void FUN_00a0e770();
};
struct TextRecord {
    void FUN_00a160c0(AudioText*,int*,int*,int,int);
};
inline TextRecord** Records() { TextRecord** p=(TextRecord**)DAT_011f33f8; return p; }
inline TextRecord* RecordAt(int i) { return Records()[i-1]; }
void __cdecl FUN_005b5e40(const char*);
extern char DAT_01094f60;
// @fnv 0x00a0e770
void AudioManager::FUN_00a0e770() {
    for(unsigned i=0;i<pending.size();++i) {
        switch(pending[i]->kind) {
        case 0:
            {
                if(slots[pending[i]->slot].playback) {
                    FUN_00a11820();
                    FUN_00706d10()->Remove(slots[pending[i]->slot].playback);
                    slots[pending[i]->slot].playback.FUN_0066b0d0(0);
                    slots[pending[i]->slot].identifier=0;
                    slots[pending[i]->slot].x=0.0f;
                    slots[pending[i]->slot].y=0.0f;
                    slots[pending[i]->slot].filename.clear();
                    slots[pending[i]->slot].duration=DAT_01012054;
                    ReleaseLock();
                }
                bool changed=false;
                if(slots[pending[i]->slot].playback) {
                    if(!strcmp(slots[pending[i]->slot].filename,pending[i]->source->filename)) changed=true;
                }
                if(!changed) {
                    FUN_00a11820();
                    slots[pending[i]->slot].playback.FUN_0066b0d0(FUN_00a0fe20(pending[i]->source->filename,
                        slots[pending[i]->slot].x,slots[pending[i]->slot].y,slots[pending[i]->slot].identifier,0,0));
                    ReleaseLock();
                }
            }
            break;
        case 1:
            {
                ScopedThreadState state3(13);
                if(!FUN_00706d10()) return;
                bool reuse=false;
                unsigned end3=0;
                bool failed4=false;
                int voice=pending[i]->voice;
                if(!voice) voice=DefaultVoice();
                AudioText text4;
                if((const char*)pending[i]->source->filename && pending[i]->source->filename.size()) {
                    text4=pending[i]->source->filename;
                    int style=1200;
                    int option=0;
                    if(DAT_011c70eb) style=(int)(style*DAT_01094f90);
                    RecordAt(voice)->FUN_00a160c0(&text4,&style,&option,0,10);
                } else {
                    failed4=true;
                    pending[i]->line=0;
                }
                if(pending[i]->line>0) {
                    int line=0;
                    unsigned length=text4.size();
                    unsigned pos2=0;
                    for(pos2=0;pos2<length && line<pending[i]->line-1;++pos2) {
                        if(text4[pos2]=='\n') ++line;
                    }
                    if(pos2==length) return;
                    unsigned out=0;
                    for(;text4[pos2]!='\n' && text4[pos2];++pos2) {
                        text4.CopyCharacter(out,pos2);
                        ++out;
                    }
                    if(text4[pos2]) {
                        for(end3=out;text4[end3];++end3) {}
                    }
                    text4.text[text4.text?out:0]=0;
                }
                int slotX;
                for(slotX=0;slotX<200;++slotX) {
                    if(slots[slotX].x==pending[i]->source->x && slots[slotX].y==pending[i]->source->y &&
                        slots[slotX].identifier==pending[i]->source->identifier) break;
                }
                if(slotX==200) {
                    for(slotX=0;slotX<200;++slotX) {
                        if(!slots[slotX].identifier) break;
                    }
                    if(slotX==200) { FUN_005b5e40(&DAT_01094f60); return; }
                } else {
                    if(!failed4) {
                        if(slots[slotX].playback && slots[slotX].filename.equals(text4)) {
                            if(slots[slotX].color==pending[i]->source->color) reuse=true;
                        }
                    } else reuse=false;
                    if(!reuse) {
                        if(slots[slotX].playback) {
                            FUN_00a11820();
                            FUN_00706d10()->Remove(slots[slotX].playback);
                            slots[slotX].playback.FUN_0066b0d0(0);
                            ReleaseLock();
                        }
                    }
                }
                if(!reuse) {
                    FUN_00a11820();
                    if(!failed4) {
                        slots[slotX].playback.FUN_0066b0d0(FUN_00a0fe20(text4,pending[i]->source->x,pending[i]->source->y,
                            pending[i]->source->identifier,voice,&pending[i]->source->color));
                    } else slots[slotX].playback.FUN_0066b0d0(0);
                    if(slots[slotX].playback) {
                        slots[slotX].filename=text4;
                        static_cast<Playback*>((SceneNode*)slots[slotX].playback)->AssignFixedString(FixedText(text4));
                        slots[slotX].x=pending[i]->source->x;
                        slots[slotX].y=pending[i]->source->y;
                        slots[slotX].identifier=pending[i]->source->identifier;
                        slots[slotX].duration=pending[i]->duration;
                        slots[slotX].color=pending[i]->source->color;
                    } else {
                        slots[slotX].identifier=0;
                        slots[slotX].x=0.0f;
                        slots[slotX].y=0.0f;
                        slots[slotX].duration=DAT_01012054;
                    }
                    ReleaseLock();
                }
            }
            break;
        }
    }
    for(unsigned j=0;j<pending.size();++j) {
        delete pending[j]->source;
        delete pending[j];
    }
    pending.FUN_00a1bfa0(true);
}

struct A0F8Str {
    void* m_pData;
    unsigned short m_04;
    unsigned short m_06;
    bool __thiscall FUN_004037f0(const char* pcText, unsigned int uiFlags);
    bool SetText(const char* pcText) { return FUN_004037f0(pcText,0); }
};

struct A0F8Color {
    float f0;
    float f1;
    float f2;
    float f3;
    A0F8Color() {}
    A0F8Color(float r,float g,float b,float a) : f0(r),f1(g),f2(b),f3(a) {}
};

struct A0F8Data {
    float fX;
    float fY;
    int   iFlags;
    int   m_0C;
    A0F8Str str;
    float m_18;
    A0F8Color color;
};

struct A0F8Item {
    A0F8Data* pData2;
    int    m_04;
    int    m_08;
    int    m_0C;
    float  m_10;
    int    m_14;
};

struct A0F8List {
    int m_00;
    A0F8Item** m_04;
    unsigned int m_08;
    unsigned int FUN_00a11d20(A0F8Item*& aValue);
    unsigned int GetCount() { return m_08; }
};

struct A0F8Self {
int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014; int unk0018; int unk001C; int unk0020; int unk0024; int unk0028; int unk002C; int unk0030; int unk0034; int unk0038; int unk003C; int unk0040; int unk0044; int unk0048; int unk004C; int unk0050; int unk0054; int unk0058; int unk005C; int unk0060; int unk0064; int unk0068; int unk006C; int unk0070; int unk0074; int unk0078; int unk007C; int unk0080; int unk0084; int unk0088; int unk008C; int unk0090; int unk0094; int unk0098; int unk009C; int unk00A0; int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4; int unk00B8; int unk00BC; int unk00C0; int unk00C4; int unk00C8; int unk00CC; int unk00D0; int unk00D4; int unk00D8; int unk00DC; int unk00E0; int unk00E4; int unk00E8; int unk00EC; int unk00F0; int unk00F4; int unk00F8; int unk00FC; int unk0100; int unk0104; int unk0108; int unk010C; int unk0110; int unk0114; int unk0118; int unk011C; int unk0120; int unk0124; int unk0128; int unk012C; int unk0130; int unk0134; int unk0138; int unk013C; int unk0140; int unk0144; int unk0148; int unk014C; int unk0150; int unk0154; int unk0158; int unk015C; int unk0160; int unk0164; int unk0168; int unk016C; int unk0170; int unk0174; int unk0178; int unk017C; int unk0180; int unk0184; int unk0188; int unk018C; int unk0190; int unk0194; int unk0198; int unk019C; int unk01A0; int unk01A4; int unk01A8; int unk01AC; int unk01B0; int unk01B4; int unk01B8; int unk01BC; int unk01C0; int unk01C4; int unk01C8; int unk01CC; int unk01D0; int unk01D4; int unk01D8; int unk01DC; int unk01E0; int unk01E4; int unk01E8; int unk01EC; int unk01F0; int unk01F4; int unk01F8; int unk01FC; int unk0200; int unk0204; int unk0208; int unk020C; int unk0210; int unk0214; int unk0218; int unk021C; int unk0220; int unk0224; int unk0228; int unk022C; int unk0230; int unk0234; int unk0238; int unk023C; int unk0240; int unk0244; int unk0248; int unk024C; int unk0250; int unk0254; int unk0258; int unk025C; int unk0260; int unk0264; int unk0268; int unk026C; int unk0270; int unk0274; int unk0278; int unk027C; int unk0280; int unk0284; int unk0288; int unk028C; int unk0290; int unk0294; int unk0298; int unk029C; int unk02A0; int unk02A4; int unk02A8; int unk02AC; int unk02B0; int unk02B4; int unk02B8; int unk02BC; int unk02C0; int unk02C4; int unk02C8; int unk02CC; int unk02D0; int unk02D4; int unk02D8; int unk02DC; int unk02E0; int unk02E4; int unk02E8; int unk02EC; int unk02F0; int unk02F4; int unk02F8; int unk02FC; int unk0300; int unk0304; int unk0308; int unk030C; int unk0310; int unk0314; int unk0318; int unk031C; int unk0320; int unk0324; int unk0328; int unk032C; int unk0330; int unk0334; int unk0338; int unk033C; int unk0340; int unk0344; int unk0348; int unk034C; int unk0350; int unk0354; int unk0358; int unk035C; int unk0360; int unk0364; int unk0368; int unk036C; int unk0370; int unk0374; int unk0378; int unk037C; int unk0380; int unk0384; int unk0388; int unk038C; int unk0390; int unk0394; int unk0398; int unk039C; int unk03A0; int unk03A4; int unk03A8; int unk03AC; int unk03B0; int unk03B4; int unk03B8; int unk03BC; int unk03C0; int unk03C4; int unk03C8; int unk03CC; int unk03D0; int unk03D4; int unk03D8; int unk03DC; int unk03E0; int unk03E4; int unk03E8; int unk03EC; int unk03F0; int unk03F4; int unk03F8; int unk03FC; int unk0400; int unk0404; int unk0408; int unk040C; int unk0410; int unk0414; int unk0418; int unk041C; int unk0420; int unk0424; int unk0428; int unk042C; int unk0430; int unk0434; int unk0438; int unk043C; int unk0440; int unk0444; int unk0448; int unk044C; int unk0450; int unk0454; int unk0458; int unk045C; int unk0460; int unk0464; int unk0468; int unk046C; int unk0470; int unk0474; int unk0478; int unk047C; int unk0480; int unk0484; int unk0488; int unk048C; int unk0490; int unk0494; int unk0498; int unk049C; int unk04A0; int unk04A4; int unk04A8; int unk04AC; int unk04B0; int unk04B4; int unk04B8; int unk04BC; int unk04C0; int unk04C4; int unk04C8; int unk04CC; int unk04D0; int unk04D4; int unk04D8; int unk04DC; int unk04E0; int unk04E4; int unk04E8; int unk04EC; int unk04F0; int unk04F4; int unk04F8; int unk04FC; int unk0500; int unk0504; int unk0508; int unk050C; int unk0510; int unk0514; int unk0518; int unk051C; int unk0520; int unk0524; int unk0528; int unk052C; int unk0530; int unk0534; int unk0538; int unk053C; int unk0540; int unk0544; int unk0548; int unk054C; int unk0550; int unk0554; int unk0558; int unk055C; int unk0560; int unk0564; int unk0568; int unk056C; int unk0570; int unk0574; int unk0578; int unk057C; int unk0580; int unk0584; int unk0588; int unk058C; int unk0590; int unk0594; int unk0598; int unk059C; int unk05A0; int unk05A4; int unk05A8; int unk05AC; int unk05B0; int unk05B4; int unk05B8; int unk05BC; int unk05C0; int unk05C4; int unk05C8; int unk05CC; int unk05D0; int unk05D4; int unk05D8; int unk05DC; int unk05E0; int unk05E4; int unk05E8; int unk05EC; int unk05F0; int unk05F4; int unk05F8; int unk05FC; int unk0600; int unk0604; int unk0608; int unk060C; int unk0610; int unk0614; int unk0618; int unk061C; int unk0620; int unk0624; int unk0628; int unk062C; int unk0630; int unk0634; int unk0638; int unk063C; int unk0640; int unk0644; int unk0648; int unk064C; int unk0650; int unk0654; int unk0658; int unk065C; int unk0660; int unk0664; int unk0668; int unk066C; int unk0670; int unk0674; int unk0678; int unk067C; int unk0680; int unk0684; int unk0688; int unk068C; int unk0690; int unk0694; int unk0698; int unk069C; int unk06A0; int unk06A4; int unk06A8; int unk06AC; int unk06B0; int unk06B4; int unk06B8; int unk06BC; int unk06C0; int unk06C4; int unk06C8; int unk06CC; int unk06D0; int unk06D4; int unk06D8; int unk06DC; int unk06E0; int unk06E4; int unk06E8; int unk06EC; int unk06F0; int unk06F4; int unk06F8; int unk06FC; int unk0700; int unk0704; int unk0708; int unk070C; int unk0710; int unk0714; int unk0718; int unk071C; int unk0720; int unk0724; int unk0728; int unk072C; int unk0730; int unk0734; int unk0738; int unk073C; int unk0740; int unk0744; int unk0748; int unk074C; int unk0750; int unk0754; int unk0758; int unk075C; int unk0760; int unk0764; int unk0768; int unk076C; int unk0770; int unk0774; int unk0778; int unk077C; int unk0780; int unk0784; int unk0788; int unk078C; int unk0790; int unk0794; int unk0798; int unk079C; int unk07A0; int unk07A4; int unk07A8; int unk07AC; int unk07B0; int unk07B4; int unk07B8; int unk07BC; int unk07C0; int unk07C4; int unk07C8; int unk07CC; int unk07D0; int unk07D4; int unk07D8; int unk07DC; int unk07E0; int unk07E4; int unk07E8; int unk07EC; int unk07F0; int unk07F4; int unk07F8; int unk07FC; int unk0800; int unk0804; int unk0808; int unk080C; int unk0810; int unk0814; int unk0818; int unk081C; int unk0820; int unk0824; int unk0828; int unk082C; int unk0830; int unk0834; int unk0838; int unk083C; int unk0840; int unk0844; int unk0848; int unk084C; int unk0850; int unk0854; int unk0858; int unk085C; int unk0860; int unk0864; int unk0868; int unk086C; int unk0870; int unk0874; int unk0878; int unk087C; int unk0880; int unk0884; int unk0888; int unk088C; int unk0890; int unk0894; int unk0898; int unk089C; int unk08A0; int unk08A4; int unk08A8; int unk08AC; int unk08B0; int unk08B4; int unk08B8; int unk08BC; int unk08C0; int unk08C4; int unk08C8; int unk08CC; int unk08D0; int unk08D4; int unk08D8; int unk08DC; int unk08E0; int unk08E4; int unk08E8; int unk08EC; int unk08F0; int unk08F4; int unk08F8; int unk08FC; int unk0900; int unk0904; int unk0908; int unk090C; int unk0910; int unk0914; int unk0918; int unk091C; int unk0920; int unk0924; int unk0928; int unk092C; int unk0930; int unk0934; int unk0938; int unk093C; int unk0940; int unk0944; int unk0948; int unk094C; int unk0950; int unk0954; int unk0958; int unk095C; int unk0960; int unk0964; int unk0968; int unk096C; int unk0970; int unk0974; int unk0978; int unk097C; int unk0980; int unk0984; int unk0988; int unk098C; int unk0990; int unk0994; int unk0998; int unk099C; int unk09A0; int unk09A4; int unk09A8; int unk09AC; int unk09B0; int unk09B4; int unk09B8; int unk09BC; int unk09C0; int unk09C4; int unk09C8; int unk09CC; int unk09D0; int unk09D4; int unk09D8; int unk09DC; int unk09E0; int unk09E4; int unk09E8; int unk09EC; int unk09F0; int unk09F4; int unk09F8; int unk09FC; int unk0A00; int unk0A04; int unk0A08; int unk0A0C; int unk0A10; int unk0A14; int unk0A18; int unk0A1C; int unk0A20; int unk0A24; int unk0A28; int unk0A2C; int unk0A30; int unk0A34; int unk0A38; int unk0A3C; int unk0A40; int unk0A44; int unk0A48; int unk0A4C; int unk0A50; int unk0A54; int unk0A58; int unk0A5C; int unk0A60; int unk0A64; int unk0A68; int unk0A6C; int unk0A70; int unk0A74; int unk0A78; int unk0A7C; int unk0A80; int unk0A84; int unk0A88; int unk0A8C; int unk0A90; int unk0A94; int unk0A98; int unk0A9C; int unk0AA0; int unk0AA4; int unk0AA8; int unk0AAC; int unk0AB0; int unk0AB4; int unk0AB8; int unk0ABC; int unk0AC0; int unk0AC4; int unk0AC8; int unk0ACC; int unk0AD0; int unk0AD4; int unk0AD8; int unk0ADC; int unk0AE0; int unk0AE4; int unk0AE8; int unk0AEC; int unk0AF0; int unk0AF4; int unk0AF8; int unk0AFC; int unk0B00; int unk0B04; int unk0B08; int unk0B0C; int unk0B10; int unk0B14; int unk0B18; int unk0B1C; int unk0B20; int unk0B24; int unk0B28; int unk0B2C; int unk0B30; int unk0B34; int unk0B38; int unk0B3C; int unk0B40; int unk0B44; int unk0B48; int unk0B4C; int unk0B50; int unk0B54; int unk0B58; int unk0B5C; int unk0B60; int unk0B64; int unk0B68; int unk0B6C; int unk0B70; int unk0B74; int unk0B78; int unk0B7C; int unk0B80; int unk0B84; int unk0B88; int unk0B8C; int unk0B90; int unk0B94; int unk0B98; int unk0B9C; int unk0BA0; int unk0BA4; int unk0BA8; int unk0BAC; int unk0BB0; int unk0BB4; int unk0BB8; int unk0BBC; int unk0BC0; int unk0BC4; int unk0BC8; int unk0BCC; int unk0BD0; int unk0BD4; int unk0BD8; int unk0BDC; int unk0BE0; int unk0BE4; int unk0BE8; int unk0BEC; int unk0BF0; int unk0BF4; int unk0BF8; int unk0BFC; int unk0C00; int unk0C04; int unk0C08; int unk0C0C; int unk0C10; int unk0C14; int unk0C18; int unk0C1C; int unk0C20; int unk0C24; int unk0C28; int unk0C2C; int unk0C30; int unk0C34; int unk0C38; int unk0C3C; int unk0C40; int unk0C44; int unk0C48; int unk0C4C; int unk0C50; int unk0C54; int unk0C58; int unk0C5C; int unk0C60; int unk0C64; int unk0C68; int unk0C6C; int unk0C70; int unk0C74; int unk0C78; int unk0C7C; int unk0C80; int unk0C84; int unk0C88; int unk0C8C; int unk0C90; int unk0C94; int unk0C98; int unk0C9C; int unk0CA0; int unk0CA4; int unk0CA8; int unk0CAC; int unk0CB0; int unk0CB4; int unk0CB8; int unk0CBC; int unk0CC0; int unk0CC4; int unk0CC8; int unk0CCC; int unk0CD0; int unk0CD4; int unk0CD8; int unk0CDC; int unk0CE0; int unk0CE4; int unk0CE8; int unk0CEC; int unk0CF0; int unk0CF4; int unk0CF8; int unk0CFC; int unk0D00; int unk0D04; int unk0D08; int unk0D0C; int unk0D10; int unk0D14; int unk0D18; int unk0D1C; int unk0D20; int unk0D24; int unk0D28; int unk0D2C; int unk0D30; int unk0D34; int unk0D38; int unk0D3C; int unk0D40; int unk0D44; int unk0D48; int unk0D4C; int unk0D50; int unk0D54; int unk0D58; int unk0D5C; int unk0D60; int unk0D64; int unk0D68; int unk0D6C; int unk0D70; int unk0D74; int unk0D78; int unk0D7C; int unk0D80; int unk0D84; int unk0D88; int unk0D8C; int unk0D90; int unk0D94; int unk0D98; int unk0D9C; int unk0DA0; int unk0DA4; int unk0DA8; int unk0DAC; int unk0DB0; int unk0DB4; int unk0DB8; int unk0DBC; int unk0DC0; int unk0DC4; int unk0DC8; int unk0DCC; int unk0DD0; int unk0DD4; int unk0DD8; int unk0DDC; int unk0DE0; int unk0DE4; int unk0DE8; int unk0DEC; int unk0DF0; int unk0DF4; int unk0DF8; int unk0DFC; int unk0E00; int unk0E04; int unk0E08; int unk0E0C; int unk0E10; int unk0E14; int unk0E18; int unk0E1C; int unk0E20; int unk0E24; int unk0E28; int unk0E2C; int unk0E30; int unk0E34; int unk0E38; int unk0E3C; int unk0E40; int unk0E44; int unk0E48; int unk0E4C; int unk0E50; int unk0E54; int unk0E58; int unk0E5C; int unk0E60; int unk0E64; int unk0E68; int unk0E6C; int unk0E70; int unk0E74; int unk0E78; int unk0E7C; int unk0E80; int unk0E84; int unk0E88; int unk0E8C; int unk0E90; int unk0E94; int unk0E98; int unk0E9C; int unk0EA0; int unk0EA4; int unk0EA8; int unk0EAC; int unk0EB0; int unk0EB4; int unk0EB8; int unk0EBC; int unk0EC0; int unk0EC4; int unk0EC8; int unk0ECC; int unk0ED0; int unk0ED4; int unk0ED8; int unk0EDC; int unk0EE0; int unk0EE4; int unk0EE8; int unk0EEC; int unk0EF0; int unk0EF4; int unk0EF8; int unk0EFC; int unk0F00; int unk0F04; int unk0F08; int unk0F0C; int unk0F10; int unk0F14; int unk0F18; int unk0F1C; int unk0F20; int unk0F24; int unk0F28; int unk0F2C; int unk0F30; int unk0F34; int unk0F38; int unk0F3C; int unk0F40; int unk0F44; int unk0F48; int unk0F4C; int unk0F50; int unk0F54; int unk0F58; int unk0F5C; int unk0F60; int unk0F64; int unk0F68; int unk0F6C; int unk0F70; int unk0F74; int unk0F78; int unk0F7C; int unk0F80; int unk0F84; int unk0F88; int unk0F8C; int unk0F90; int unk0F94; int unk0F98; int unk0F9C; int unk0FA0; int unk0FA4; int unk0FA8; int unk0FAC; int unk0FB0; int unk0FB4; int unk0FB8; int unk0FBC; int unk0FC0; int unk0FC4; int unk0FC8; int unk0FCC; int unk0FD0; int unk0FD4; int unk0FD8; int unk0FDC; int unk0FE0; int unk0FE4; int unk0FE8; int unk0FEC; int unk0FF0; int unk0FF4; int unk0FF8; int unk0FFC; int unk1000; int unk1004; int unk1008; int unk100C; int unk1010; int unk1014; int unk1018; int unk101C; int unk1020; int unk1024; int unk1028; int unk102C; int unk1030; int unk1034; int unk1038; int unk103C; int unk1040; int unk1044; int unk1048; int unk104C; int unk1050; int unk1054; int unk1058; int unk105C; int unk1060; int unk1064; int unk1068; int unk106C; int unk1070; int unk1074; int unk1078; int unk107C; int unk1080; int unk1084; int unk1088; int unk108C; int unk1090; int unk1094; int unk1098; int unk109C; int unk10A0; int unk10A4; int unk10A8; int unk10AC; int unk10B0; int unk10B4; int unk10B8; int unk10BC; int unk10C0; int unk10C4; int unk10C8; int unk10CC; int unk10D0; int unk10D4; int unk10D8; int unk10DC; int unk10E0; int unk10E4; int unk10E8; int unk10EC; int unk10F0; int unk10F4; int unk10F8; int unk10FC; int unk1100; int unk1104; int unk1108; int unk110C; int unk1110; int unk1114; int unk1118; int unk111C; int unk1120; int unk1124; int unk1128; int unk112C; int unk1130; int unk1134; int unk1138; int unk113C; int unk1140; int unk1144; int unk1148; int unk114C; int unk1150; int unk1154; int unk1158; int unk115C; int unk1160; int unk1164; int unk1168; int unk116C; int unk1170; int unk1174; int unk1178; int unk117C; int unk1180; int unk1184; int unk1188; int unk118C; int unk1190; int unk1194; int unk1198; int unk119C; int unk11A0; int unk11A4; int unk11A8; int unk11AC; int unk11B0; int unk11B4; int unk11B8; int unk11BC; int unk11C0; int unk11C4; int unk11C8; int unk11CC; int unk11D0; int unk11D4; int unk11D8; int unk11DC; int unk11E0; int unk11E4; int unk11E8; int unk11EC; int unk11F0; int unk11F4; int unk11F8; int unk11FC; int unk1200; int unk1204; int unk1208; int unk120C; int unk1210; int unk1214; int unk1218; int unk121C; int unk1220; int unk1224; int unk1228; int unk122C; int unk1230; int unk1234; int unk1238; int unk123C; int unk1240; int unk1244; int unk1248; int unk124C; int unk1250; int unk1254; int unk1258; int unk125C; int unk1260; int unk1264; int unk1268; int unk126C; int unk1270; int unk1274; int unk1278; int unk127C; int unk1280; int unk1284; int unk1288; int unk128C; int unk1290; int unk1294; int unk1298; int unk129C; int unk12A0; int unk12A4; int unk12A8; int unk12AC; int unk12B0; int unk12B4; int unk12B8; int unk12BC; int unk12C0; int unk12C4; int unk12C8; int unk12CC; int unk12D0; int unk12D4; int unk12D8; int unk12DC; int unk12E0; int unk12E4; int unk12E8; int unk12EC; int unk12F0; int unk12F4; int unk12F8; int unk12FC; int unk1300; int unk1304; int unk1308; int unk130C; int unk1310; int unk1314; int unk1318; int unk131C; int unk1320; int unk1324; int unk1328; int unk132C; int unk1330; int unk1334; int unk1338; int unk133C; int unk1340; int unk1344; int unk1348; int unk134C; int unk1350; int unk1354; int unk1358; int unk135C; int unk1360; int unk1364; int unk1368; int unk136C; int unk1370; int unk1374; int unk1378; int unk137C; int unk1380; int unk1384; int unk1388; int unk138C; int unk1390; int unk1394; int unk1398; int unk139C; int unk13A0; int unk13A4; int unk13A8; int unk13AC; int unk13B0; int unk13B4; int unk13B8; int unk13BC; int unk13C0; int unk13C4; int unk13C8; int unk13CC; int unk13D0; int unk13D4; int unk13D8; int unk13DC; int unk13E0; int unk13E4; int unk13E8; int unk13EC; int unk13F0; int unk13F4; int unk13F8; int unk13FC; int unk1400; int unk1404; int unk1408; int unk140C; int unk1410; int unk1414; int unk1418; int unk141C; int unk1420; int unk1424; int unk1428; int unk142C; int unk1430; int unk1434; int unk1438; int unk143C; int unk1440; int unk1444; int unk1448; int unk144C; int unk1450; int unk1454; int unk1458; int unk145C; int unk1460; int unk1464; int unk1468; int unk146C; int unk1470; int unk1474; int unk1478; int unk147C; int unk1480; int unk1484; int unk1488; int unk148C; int unk1490; int unk1494; int unk1498; int unk149C; int unk14A0; int unk14A4; int unk14A8; int unk14AC; int unk14B0; int unk14B4; int unk14B8; int unk14BC; int unk14C0; int unk14C4; int unk14C8; int unk14CC; int unk14D0; int unk14D4; int unk14D8; int unk14DC; int unk14E0; int unk14E4; int unk14E8; int unk14EC; int unk14F0; int unk14F4; int unk14F8; int unk14FC; int unk1500; int unk1504; int unk1508; int unk150C; int unk1510; int unk1514; int unk1518; int unk151C; int unk1520; int unk1524; int unk1528; int unk152C; int unk1530; int unk1534; int unk1538; int unk153C; int unk1540; int unk1544; int unk1548; int unk154C; int unk1550; int unk1554; int unk1558; int unk155C; int unk1560; int unk1564; int unk1568; int unk156C; int unk1570; int unk1574; int unk1578; int unk157C; int unk1580; int unk1584; int unk1588; int unk158C; int unk1590; int unk1594; int unk1598; int unk159C; int unk15A0; int unk15A4; int unk15A8; int unk15AC; int unk15B0; int unk15B4; int unk15B8; int unk15BC; int unk15C0; int unk15C4; int unk15C8; int unk15CC; int unk15D0; int unk15D4; int unk15D8; int unk15DC; int unk15E0; int unk15E4; int unk15E8; int unk15EC; int unk15F0; int unk15F4; int unk15F8; int unk15FC; int unk1600; int unk1604; int unk1608; int unk160C; int unk1610; int unk1614; int unk1618; int unk161C; int unk1620; int unk1624; int unk1628; int unk162C; int unk1630; int unk1634; int unk1638; int unk163C; int unk1640; int unk1644; int unk1648; int unk164C; int unk1650; int unk1654; int unk1658; int unk165C; int unk1660; int unk1664; int unk1668; int unk166C; int unk1670; int unk1674; int unk1678; int unk167C; int unk1680; int unk1684; int unk1688; int unk168C; int unk1690; int unk1694; int unk1698; int unk169C; int unk16A0; int unk16A4; int unk16A8; int unk16AC; int unk16B0; int unk16B4; int unk16B8; int unk16BC; int unk16C0; int unk16C4; int unk16C8; int unk16CC; int unk16D0; int unk16D4; int unk16D8; int unk16DC; int unk16E0; int unk16E4; int unk16E8; int unk16EC; int unk16F0; int unk16F4; int unk16F8; int unk16FC; int unk1700; int unk1704; int unk1708; int unk170C; int unk1710; int unk1714; int unk1718; int unk171C; int unk1720; int unk1724; int unk1728; int unk172C; int unk1730; int unk1734; int unk1738; int unk173C; int unk1740; int unk1744; int unk1748; int unk174C; int unk1750; int unk1754; int unk1758; int unk175C; int unk1760; int unk1764; int unk1768; int unk176C; int unk1770; int unk1774; int unk1778; int unk177C; int unk1780; int unk1784; int unk1788; int unk178C; int unk1790; int unk1794; int unk1798; int unk179C; int unk17A0; int unk17A4; int unk17A8; int unk17AC; int unk17B0; int unk17B4; int unk17B8; int unk17BC; int unk17C0; int unk17C4; int unk17C8; int unk17CC; int unk17D0; int unk17D4; int unk17D8; int unk17DC; int unk17E0; int unk17E4; int unk17E8; int unk17EC; int unk17F0; int unk17F4; int unk17F8; int unk17FC; int unk1800; int unk1804; int unk1808; int unk180C; int unk1810; int unk1814; int unk1818; int unk181C; int unk1820; int unk1824; int unk1828; int unk182C; int unk1830; int unk1834; int unk1838; int unk183C; int unk1840; int unk1844; int unk1848; int unk184C; int unk1850; int unk1854; int unk1858; int unk185C; int unk1860; int unk1864; int unk1868; int unk186C; int unk1870; int unk1874; int unk1878; int unk187C; int unk1880; int unk1884; int unk1888; int unk188C; int unk1890; int unk1894; int unk1898; int unk189C; int unk18A0; int unk18A4; int unk18A8; int unk18AC; int unk18B0; int unk18B4; int unk18B8; int unk18BC; int unk18C0; int unk18C4; int unk18C8; int unk18CC; int unk18D0; int unk18D4; int unk18D8; int unk18DC; int unk18E0; int unk18E4; int unk18E8; int unk18EC; int unk18F0; int unk18F4; int unk18F8; int unk18FC; int unk1900; int unk1904; int unk1908; int unk190C; int unk1910; int unk1914; int unk1918; int unk191C; int unk1920; int unk1924; int unk1928; int unk192C; int unk1930; int unk1934; int unk1938; int unk193C; int unk1940; int unk1944; int unk1948; int unk194C; int unk1950; int unk1954; int unk1958; int unk195C; int unk1960; int unk1964; int unk1968; int unk196C; int unk1970; int unk1974; int unk1978; int unk197C; int unk1980; int unk1984; int unk1988; int unk198C; int unk1990; int unk1994; int unk1998; int unk199C; int unk19A0; int unk19A4; int unk19A8; int unk19AC; int unk19B0; int unk19B4; int unk19B8; int unk19BC; int unk19C0; int unk19C4; int unk19C8; int unk19CC; int unk19D0; int unk19D4; int unk19D8; int unk19DC; int unk19E0; int unk19E4; int unk19E8; int unk19EC; int unk19F0; int unk19F4; int unk19F8; int unk19FC; int unk1A00; int unk1A04; int unk1A08; int unk1A0C; int unk1A10; int unk1A14; int unk1A18; int unk1A1C; int unk1A20; int unk1A24; int unk1A28; int unk1A2C; int unk1A30; int unk1A34; int unk1A38; int unk1A3C; int unk1A40; int unk1A44; int unk1A48; int unk1A4C; int unk1A50; int unk1A54; int unk1A58; int unk1A5C; int unk1A60; int unk1A64; int unk1A68; int unk1A6C; int unk1A70; int unk1A74; int unk1A78; int unk1A7C; int unk1A80; int unk1A84; int unk1A88; int unk1A8C; int unk1A90; int unk1A94; int unk1A98; int unk1A9C; int unk1AA0; int unk1AA4; int unk1AA8; int unk1AAC; int unk1AB0; int unk1AB4; int unk1AB8; int unk1ABC; int unk1AC0; int unk1AC4; int unk1AC8; int unk1ACC; int unk1AD0; int unk1AD4; int unk1AD8; int unk1ADC; int unk1AE0; int unk1AE4; int unk1AE8; int unk1AEC; int unk1AF0; int unk1AF4; int unk1AF8; int unk1AFC; int unk1B00; int unk1B04; int unk1B08; int unk1B0C; int unk1B10; int unk1B14; int unk1B18; int unk1B1C; int unk1B20; int unk1B24; int unk1B28; int unk1B2C; int unk1B30; int unk1B34; int unk1B38; int unk1B3C; int unk1B40; int unk1B44; int unk1B48; int unk1B4C; int unk1B50; int unk1B54; int unk1B58; int unk1B5C; int unk1B60; int unk1B64; int unk1B68; int unk1B6C; int unk1B70; int unk1B74; int unk1B78; int unk1B7C; int unk1B80; int unk1B84; int unk1B88; int unk1B8C; int unk1B90; int unk1B94; int unk1B98; int unk1B9C; int unk1BA0; int unk1BA4; int unk1BA8; int unk1BAC; int unk1BB0; int unk1BB4; int unk1BB8; int unk1BBC; int unk1BC0; int unk1BC4; int unk1BC8; int unk1BCC; int unk1BD0; int unk1BD4; int unk1BD8; int unk1BDC; int unk1BE0; int unk1BE4; int unk1BE8; int unk1BEC; int unk1BF0; int unk1BF4; int unk1BF8; int unk1BFC; int unk1C00; int unk1C04; int unk1C08; int unk1C0C; int unk1C10; int unk1C14; int unk1C18; int unk1C1C; int unk1C20; int unk1C24; int unk1C28; int unk1C2C; int unk1C30; int unk1C34; int unk1C38; int unk1C3C; int unk1C40; int unk1C44; int unk1C48; int unk1C4C; int unk1C50; int unk1C54; int unk1C58; int unk1C5C; int unk1C60; int unk1C64; int unk1C68; int unk1C6C; int unk1C70; int unk1C74; int unk1C78; int unk1C7C; int unk1C80; int unk1C84; int unk1C88; int unk1C8C; int unk1C90; int unk1C94; int unk1C98; int unk1C9C; int unk1CA0; int unk1CA4; int unk1CA8; int unk1CAC; int unk1CB0; int unk1CB4; int unk1CB8; int unk1CBC; int unk1CC0; int unk1CC4; int unk1CC8; int unk1CCC; int unk1CD0; int unk1CD4; int unk1CD8; int unk1CDC; int unk1CE0; int unk1CE4; int unk1CE8; int unk1CEC; int unk1CF0; int unk1CF4; int unk1CF8; int unk1CFC; int unk1D00; int unk1D04; int unk1D08; int unk1D0C; int unk1D10; int unk1D14; int unk1D18; int unk1D1C; int unk1D20; int unk1D24; int unk1D28; int unk1D2C; int unk1D30; int unk1D34; int unk1D38; int unk1D3C; int unk1D40; int unk1D44; int unk1D48; int unk1D4C; int unk1D50; int unk1D54; int unk1D58; int unk1D5C; int unk1D60; int unk1D64; int unk1D68; int unk1D6C; int unk1D70; int unk1D74; int unk1D78; int unk1D7C; int unk1D80; int unk1D84; int unk1D88; int unk1D8C; int unk1D90; int unk1D94; int unk1D98; int unk1D9C; int unk1DA0; int unk1DA4; int unk1DA8; int unk1DAC; int unk1DB0; int unk1DB4; int unk1DB8; int unk1DBC; int unk1DC0; int unk1DC4; int unk1DC8; int unk1DCC; int unk1DD0; int unk1DD4; int unk1DD8; int unk1DDC; int unk1DE0; int unk1DE4; int unk1DE8; int unk1DEC; int unk1DF0; int unk1DF4; int unk1DF8; int unk1DFC; int unk1E00; int unk1E04; int unk1E08; int unk1E0C; int unk1E10; int unk1E14; int unk1E18; int unk1E1C; int unk1E20; int unk1E24; int unk1E28; int unk1E2C; int unk1E30; int unk1E34; int unk1E38; int unk1E3C; int unk1E40; int unk1E44; int unk1E48; int unk1E4C; int unk1E50; int unk1E54; int unk1E58; int unk1E5C; int unk1E60; int unk1E64; int unk1E68; int unk1E6C; int unk1E70; int unk1E74; int unk1E78; int unk1E7C; int unk1E80; int unk1E84; int unk1E88; int unk1E8C; int unk1E90; int unk1E94; int unk1E98; int unk1E9C; int unk1EA0; int unk1EA4; int unk1EA8; int unk1EAC; int unk1EB0; int unk1EB4; int unk1EB8; int unk1EBC; int unk1EC0; int unk1EC4; int unk1EC8; int unk1ECC; int unk1ED0; int unk1ED4; int unk1ED8; int unk1EDC; int unk1EE0; int unk1EE4; int unk1EE8; int unk1EEC; int unk1EF0; int unk1EF4; int unk1EF8; int unk1EFC; int unk1F00; int unk1F04; int unk1F08; int unk1F0C; int unk1F10; int unk1F14; int unk1F18; int unk1F1C; int unk1F20; int unk1F24; int unk1F28; int unk1F2C; int unk1F30; int unk1F34; int unk1F38; int unk1F3C; int unk1F40; int unk1F44; int unk1F48; int unk1F4C; int unk1F50; int unk1F54; int unk1F58; int unk1F5C; int unk1F60; int unk1F64; int unk1F68; int unk1F6C; int unk1F70; int unk1F74; int unk1F78; int unk1F7C; int unk1F80; int unk1F84; int unk1F88; int unk1F8C; int unk1F90; int unk1F94; int unk1F98; int unk1F9C; int unk1FA0; int unk1FA4; int unk1FA8; int unk1FAC; int unk1FB0; int unk1FB4; int unk1FB8; int unk1FBC; int unk1FC0; int unk1FC4; int unk1FC8; int unk1FCC; int unk1FD0; int unk1FD4; int unk1FD8; int unk1FDC; int unk1FE0; int unk1FE4; int unk1FE8; int unk1FEC; int unk1FF0; int unk1FF4; int unk1FF8; int unk1FFC; int unk2000; int unk2004; int unk2008; int unk200C; int unk2010; int unk2014; int unk2018; int unk201C; int unk2020; int unk2024; int unk2028; int unk202C; int unk2030; int unk2034; int unk2038; int unk203C; int unk2040; int unk2044; int unk2048; int unk204C; int unk2050; int unk2054; int unk2058; int unk205C; int unk2060; int unk2064; int unk2068; int unk206C; int unk2070; int unk2074; int unk2078; int unk207C; int unk2080; int unk2084; int unk2088; int unk208C; int unk2090; int unk2094; int unk2098; int unk209C; int unk20A0; int unk20A4; int unk20A8; int unk20AC; int unk20B0; int unk20B4; int unk20B8; int unk20BC; int unk20C0; int unk20C4; int unk20C8; int unk20CC; int unk20D0; int unk20D4; int unk20D8; int unk20DC; int unk20E0; int unk20E4; int unk20E8; int unk20EC; int unk20F0; int unk20F4; int unk20F8; int unk20FC; int unk2100; int unk2104; int unk2108; int unk210C; int unk2110; int unk2114; int unk2118; int unk211C; int unk2120; int unk2124; int unk2128; int unk212C; int unk2130; int unk2134; int unk2138; int unk213C; int unk2140; int unk2144; int unk2148; int unk214C; int unk2150; int unk2154; int unk2158; int unk215C; int unk2160; int unk2164; int unk2168; int unk216C; int unk2170; int unk2174; int unk2178; int unk217C; int unk2180; int unk2184; int unk2188; int unk218C; int unk2190; int unk2194; int unk2198; int unk219C; int unk21A0; int unk21A4; int unk21A8; int unk21AC; int unk21B0; int unk21B4; int unk21B8; int unk21BC; int unk21C0; int unk21C4; int unk21C8; int unk21CC; int unk21D0; int unk21D4; int unk21D8; int unk21DC; int unk21E0; int unk21E4; int unk21E8; int unk21EC; int unk21F0; int unk21F4; int unk21F8; int unk21FC; int unk2200; int unk2204; int unk2208; int unk220C; int unk2210; int unk2214; int unk2218; int unk221C; int unk2220; int unk2224; int unk2228; int unk222C; int unk2230; int unk2234; int unk2238; int unk223C; int unk2240; int unk2244; int unk2248; int unk224C; int unk2250; int unk2254; int unk2258; int unk225C; int unk2260; int unk2264; int unk2268; int unk226C;     A0F8List m_kNode;

    int CreateLine(const char* pcText, float fX, float fY, int iFlags,
                     int m_iPayloadInteger, float fScale, int iUnused, A0F8Color* pkColor);
};

extern int DAT_011f33bc;
extern int DAT_011f33c0;
extern int DAT_01202800;

inline void* operator new(unsigned int n) { return g_memoryManager.Allocate(n); }

__forceinline A0F8Color MakeColor(const unsigned int& r,const unsigned int& g,const unsigned int& b,const unsigned int& a) {
 float red4=(double)r/255.0,green=(double)g/255.0,blue9=(double)b/255.0,alpha=(double)a/255.0;
 int shift; int state; int pos;
 return A0F8Color(red4,green,blue9,alpha);
}

inline int* DefaultColor() { return &DAT_011f33bc ? &DAT_011f33c0 : (DAT_01202800=0,&DAT_01202800); }
inline void UnpackColor(unsigned int& red5,unsigned int& green7,unsigned int& blue9,unsigned int& alpha7) {
 int* pDefault=DefaultColor(); unsigned int c=*pDefault;
 red5=(c>>24)&255; green7=(c>>16)&255; blue9=(c>>8)&255; alpha7=c&255;
}

inline bool SetNewStr(A0F8Str& rStr,const char* pcText) { int len; int end; A0F8Str* string=&rStr; return string->FUN_004037f0(pcText,0); }

inline bool SetStr(A0F8Str& rStr, const char* pcText) { return rStr.FUN_004037f0(pcText, 0); }

// @fnv 0x00a0f8b0
int A0F8Self::CreateLine(const char* pcText, float fX, float fY, int iFlags,
                           int m_iPayloadInteger, float fScale, int iUnused, A0F8Color* pkColor)
{
    bool found = false;
    unsigned int i;

    for (i = 0; !found && i < this->m_kNode.GetCount(); i++)
    {
        if (this->m_kNode.m_04[i]->pData2->fX == fX
            && this->m_kNode.m_04[i]->pData2->fY == fY
            && this->m_kNode.m_04[i]->pData2->iFlags == iFlags)
        {
            this->m_kNode.m_04[i]->pData2->str.SetText(pcText);
            this->m_kNode.m_04[i]->m_04 = 1;
            this->m_kNode.m_04[i]->m_0C = m_iPayloadInteger;
            this->m_kNode.m_04[i]->m_10 = fScale;
            this->m_kNode.m_04[i]->m_14 = iUnused;
            if (pkColor)
            {
                this->m_kNode.m_04[i]->pData2->color = *pkColor;
            }
            else
            {
                unsigned int red5,green7,blue9,alpha7;
                UnpackColor(red5,green7,blue9,alpha7);
                this->m_kNode.m_04[i]->pData2->color = MakeColor(red5,green7,blue9,alpha7);
            }
            found = true;
        }
    }

    if (!found)
    {
        A0F8Data* pData2 = (A0F8Data*)new FUN_00a11880;
        SetNewStr(pData2->str,pcText);
        pData2->fX = fX;
        pData2->fY = fY;
        pData2->iFlags = iFlags;
        if (pkColor)
        {
            pData2->color = *pkColor;
        }
        else
        {
            unsigned int red5,green7,blue9,alpha7;
                UnpackColor(red5,green7,blue9,alpha7);
            pData2->color = MakeColor(red5,green7,blue9,alpha7);
        }
        A0F8Item* pItem = new A0F8Item;
        pItem->pData2 = pData2;
        pItem->m_04 = 1;
        pItem->m_0C = m_iPayloadInteger;
        pItem->m_10 = fScale;
        pItem->m_14 = iUnused;
        this->m_kNode.FUN_00a11d20(pItem);
    }
    return 0;
}

#include <math.h>
namespace fnv_00a10770 {
extern "C" char DAT_01094f9c;
extern "C" char* DAT_0109b220;
extern "C" float DAT_0101ff38;
extern "C" float DAT_01016b78;
extern "C" float DAT_0102b3c8;
char* __cdecl FUN_00a5b690(const char*);
void __cdecl FUN_004381d0(void*);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
extern "C" double __cdecl fabs(double);
struct S107 {
    char* data;
    __forceinline S107(const char* p) { if (!p) data=DAT_0109b220; else data=FUN_00a5b690(p); }
    __forceinline ~S107() { FUN_004381d0(this); }
};
struct B107 {
    int a,b;
    B107(const char*);
    ~B107() { ((Str107*)this)->FUN_004037f0(0,0); }
    struct Str107 { bool FUN_004037f0(const char*,unsigned); };
};
struct M107 {
    float a,b,c,d,e,f,g,h,i;
    M107 FUN_0043f8d0_External(const M107&) const;
    M107() {}
    M107 FUN_0043f8d0(const M107& rhs) const {
        M107 result;
        result.a=a*rhs.a+b*rhs.d+c*rhs.g;
        result.d=d*rhs.a+e*rhs.d+f*rhs.g;
        result.g=g*rhs.a+h*rhs.d+i*rhs.g;
        result.b=a*rhs.b+b*rhs.e+c*rhs.h;
        result.e=d*rhs.b+e*rhs.e+f*rhs.h;
        result.h=g*rhs.b+h*rhs.e+i*rhs.h;
        result.c=a*rhs.c+b*rhs.f+c*rhs.i;
        result.f=d*rhs.c+e*rhs.f+f*rhs.i;
        result.i=g*rhs.c+h*rhs.f+i*rhs.i;
        return result;
    }
    __forceinline void RotateX(float angle) {
        float s,c;
        fnv_SinCos(angle,s,c);
        a=1.0f; b=0.0f; this->c=0.0f; d=0.0f; e=c; f=s; g=0.0f; h=-s; i=c;
    }
    __forceinline void RotateY(float angle) {
        float s,c;
        fnv_SinCos(angle,s,c);
        a=c; b=0.0f; this->c=-s; d=0.0f; e=1.0f; f=0.0f; g=s; h=0.0f; i=c;
    }
};
struct P107 { float x,y,z; };
struct U107 {
    float time; bool a,b; int unused;
    void FUN_0043d410(float,bool,bool);
};
struct State107 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
    State107(); ~State107();
    static State107* Create();
    static void Destroy(State107*);
    static void* operator new(unsigned size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void*);
};
State107* State107::Create() { return new State107; }
void State107::Destroy(State107* state) { delete state; }
struct Lock107 { unsigned owner; void Lock(const char*); };
extern Lock107 DAT_011f42a0;
extern unsigned DAT_011f42a4;
struct Parent107 { void FUN_00a5e3a0(State107*&); };
struct FUN_0051cf00 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void UpdatePropertiesDown(State107*); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54();
    virtual void attach(FUN_0051cf00*,bool);
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    M107 rotation; P107 position; float scale;
    int unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0;
    static void* operator new(unsigned);
    static void operator delete(void*);
    FUN_0051cf00();
    void AssignFixedString(const S107&);
    void FUN_00439410(void*);
    void FUN_00a5a040() {
        State107* state=0;
        DAT_011f42a0.Lock(0);
        if(unk18) ((Parent107*)unk18)->FUN_00a5e3a0(state);
        else state=State107::Create();
        UpdatePropertiesDown(state);
        State107::Destroy(state);
        if(--DAT_011f42a4==0) DAT_011f42a0.owner=0;
    }
    void FUN_00a59c60(const U107&);
    __forceinline void SetRotation(const M107& value) { rotation=value; }
    __forceinline void SetScale(float value) { scale=value; }
    __forceinline void SetZeroPosition() {
        P107 zero; zero.x=0.0f; zero.y=0.0f; zero.z=0.0f;
        position=zero;
    }
};
struct FUN_004391c0 {
    int a,b,c,d,e,f,g;
    static void* operator new(unsigned);
    static void operator delete(void*);
    FUN_004391c0();
    void FUN_00633ba0(bool,unsigned);
};
struct Maker107 {
    static __forceinline Maker107* Get(int idx) {
        Maker107** fonts=(Maker107**)DAT_011f33f8;
        Maker107* selected=fonts[idx]; return selected;
    }
    FUN_0051cf00* FUN_00a12460(float,float,float,B107*,int*,int,int,int,bool);
};
// @fnv 0x00a10770
FUN_0051cf00* __cdecl FUN_00a10770(const char* text,float x,float y,float scale,int idx,int p1,int p2,bool flag) {
    FUN_0051cf00* a;
    { a = new FUN_0051cf00; }
    a->AssignFixedString(S107(&DAT_01094f9c));
    int eb=10000;
    B107 s(text);
    FUN_0051cf00* h;
    {
        h=Maker107::Get(idx)->FUN_00a12460(x,y,0.0f,&s,&eb,p1,p2,0,flag);
    }
    if (!h) return 0;
    a->attach(h,true);
    M107 i,cf;
    i.RotateX(DAT_0101ff38);
    h->SetRotation(i.FUN_0043f8d0(h->rotation));
    a->SetZeroPosition();
    i.RotateX(DAT_01016b78);
    cf.RotateY(DAT_0102b3c8);
    a->SetRotation(i.FUN_0043f8d0_External(cf).FUN_0043f8d0_External(a->rotation));
    a->scale=(double)(float)fabs(scale);
    FUN_004391c0* p=new FUN_004391c0;
    p->FUN_00633ba0(true,1);
    p->FUN_00633ba0(false,0x2000);
    a->FUN_00439410(p);
    a->FUN_00a5a040();
    U107 f;
    f.FUN_0043d410(0.0f,false,false);
    a->FUN_00a59c60(f);
    return a;
}
}  // namespace fnv_00a10770

#include <math.h>

struct NiAlphaProperty;
struct NiBound { float x,y,z,r; };
extern NiBound DAT_011f4288;
extern "C" char DAT_01094f9c;
extern float DAT_01016248;
extern "C" int DAT_011a9be0;
struct BSStringTChar {
 char* data; unsigned short length,capacity;
 inline BSStringTChar(const char* p) { Init(); Set(p,0); }
 inline void Init() { data=0; SetLength(0); SetCapacity(0); }
 inline void SetLength(unsigned n) { unsigned clamped=n<=65535?n:65535; length=(unsigned short)clamped; }
 inline void SetCapacity(unsigned n) { unsigned clamped=n<=65535?n:65535; capacity=(unsigned short)clamped; }
 bool Set(const char*,unsigned int);
 inline BSStringTChar& operator=(const char* p) { Set(p,0); return *this; }
 inline ~BSStringTChar() { Set(0,0); }
};
struct ThreeByThreeMatrix {
 float m[3][3];
 ThreeByThreeMatrix() {}
 ThreeByThreeMatrix Multiply(const ThreeByThreeMatrix& r) const;

 inline ThreeByThreeMatrix operator*(const ThreeByThreeMatrix& r) const { ThreeByThreeMatrix result; result.m[0][0]=m[0][0]*r.m[0][0]+m[0][1]*r.m[1][0]+m[0][2]*r.m[2][0]; result.m[1][0]=m[1][0]*r.m[0][0]+m[1][1]*r.m[1][0]+m[1][2]*r.m[2][0]; result.m[2][0]=m[2][0]*r.m[0][0]+m[2][1]*r.m[1][0]+m[2][2]*r.m[2][0]; result.m[0][1]=m[0][0]*r.m[0][1]+m[0][1]*r.m[1][1]+m[0][2]*r.m[2][1]; result.m[1][1]=m[1][0]*r.m[0][1]+m[1][1]*r.m[1][1]+m[1][2]*r.m[2][1]; result.m[2][1]=m[2][0]*r.m[0][1]+m[2][1]*r.m[1][1]+m[2][2]*r.m[2][1]; result.m[0][2]=m[0][0]*r.m[0][2]+m[0][1]*r.m[1][2]+m[0][2]*r.m[2][2]; result.m[1][2]=m[1][0]*r.m[0][2]+m[1][1]*r.m[1][2]+m[1][2]*r.m[2][2]; result.m[2][2]=m[2][0]*r.m[0][2]+m[2][1]*r.m[1][2]+m[2][2]*r.m[2][2]; return result; }
 __forceinline void MakeX(float a) { float s,c; fnv_SinCos(a,s,c); m[0][0]=1; m[0][1]=0; m[0][2]=0; m[1][0]=0; m[1][1]=c; m[1][2]=s; m[2][0]=0; m[2][1]=-s; m[2][2]=c; }
 __forceinline void MakeY(float a) { float s,c; fnv_SinCos(a,s,c); m[0][0]=c; m[0][1]=0; m[0][2]=-s; m[1][0]=0; m[1][1]=1; m[1][2]=0; m[2][0]=s; m[2][1]=0; m[2][2]=c; }
};
struct NiPoint3 { float x,y,z; inline NiPoint3(float a,float b,float c):x(a),y(b),z(c) {} };
struct NiUpdateData { float time; bool a,b; int unk08; NiUpdateData(float,bool,bool); };
inline float NiAbs(float value) { return (float)fabs((double)value); }
struct TextEntryAllocator { inline void* Allocate(unsigned int n) const { return g_memoryManager.Allocate(n); } };
struct NiAVObject;
struct NiAVObject : NiObject {
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
 virtual void Attach(NiAVObject*,bool);
 virtual void vf56(); virtual void vf57(); virtual void Detach(NiAVObject*);
 static void* operator new(unsigned int);
 static void operator delete(void*);
 int unk1c; NiBound* bound; int unk24,unk28,unk2c,unk30;
 ThreeByThreeMatrix rotation; NiPoint3 translation; float scale;
 ThreeByThreeMatrix worldRotation; NiPoint3 worldTranslation; float worldScale;
 int unk9c,unka0,unka4,unka8,unkac,unkb0;
 void SetName(const FixedText&);
 void AttachProperty(NiAlphaProperty*);
 bool AddExtraData(void*);

 void Update(NiUpdateData&);
 inline const NiBound& GetBound() { return bound ? *bound : DAT_011f4288; }
 inline void SetRotation(const ThreeByThreeMatrix& r) { rotation=r; }
 inline BSStringTChar& GetTextUnused();
 inline void SetPosition(float x,float y,float z) { translation=NiPoint3(x,y,z); }
 inline void SetScale(float a) { scale=(double)(float)fabs((double)a); }
};
struct NiBillboardNode : NiAVObject { NiBillboardNode(); };
struct NiAlphaProperty {
 static void* operator new(unsigned int);
 static void operator delete(void*);
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
 NiAlphaProperty(); void FUN_00633ba0(bool,unsigned short);
};
struct ExtraData {
 static void* operator new(unsigned int);
 static void operator delete(void*);
 int unk00,unk04,unk08; NiAVObject* node; BSStringTChar text; int unk18; int height;
 inline BSStringTChar& GetText() { return text; }
};
struct DebugTextExtraData : ExtraData { DebugTextExtraData(NiAVObject*,const char*,int,int); };
struct NodePointer { NiAVObject* ptr; NodePointer& FUN_0066b0d0(NiAVObject*); inline bool operator==(NiAVObject* p) const { return ptr==p; } };
struct TextEntry { float x,y; int unk08; NodePointer node; BSStringTChar text; float duration; int unk1c,unk20,unk24,unk28;
 inline BSStringTChar& GetText() { return text; }
 static inline void* operator new(unsigned int n) { TextEntryAllocator allocator; return allocator.Allocate(n); }
 static void operator delete(void*);
};
struct FontFace { NiAVObject* FUN_00a12460(float,float,float,BSStringTChar*,int*,int,int*,int,int); };
struct FontSystem { FontFace* faces[2]; inline FontFace* GetFont(int i) { return faces[i]; } inline static FontSystem* GetSingleton(); };
extern "C" FontSystem* g_FontSystem;
inline FontSystem* FontSystem::GetSingleton() { return g_FontSystem; }
extern "C" void __cdecl FUN_00b57e30(NiAVObject*,int,int);
extern "C" void __cdecl FUN_00633ba0();
extern "C" void __cdecl SetExtraDataName();
typedef void (__thiscall *AlphaFlag)(NiAlphaProperty*,bool,unsigned short);
typedef bool (__thiscall *ExtraAttach)(NiObject*,ExtraData*);
// @fnv 0x00a10c00
unsigned char __cdecl FUN_00a10c00(NiObject* root,int text,int height,float duration) {
 if(!root) return false;
 bool found=false;
 int zt=(int)static_cast<NiAVObject*>(root)->GetBound().z;
 ExtraData* extra34=(ExtraData*)FUN_00a11740((A11740Input*)root,text,height,&zt);
 NiAVObject* nodeB;
 if(extra34) {
  Link* pos=DebugState::FUN_00a0d9e0(true)->list.GetFirst();
  while(pos) {
   DynamicEntry* existing=DebugState::FUN_00a0d9e0(true)->list.Next(pos);
   if((bool)(int)(existing->node.ptr==(SceneNode*)extra34->node)) { existing->lifetime=duration; return true; }
  }
  static_cast<NiAVObject*>(root)->Detach(extra34->node);
  nodeB=new NiBillboardNode;
  nodeB->SetName(FixedText(&DAT_01094f9c));
  found=true;
 } else {
  nodeB=new NiBillboardNode;
  nodeB->SetName(FixedText(&DAT_01094f9c));
  extra34=new DebugTextExtraData(nodeB,(const char*)text,height,zt);
 }
 int total2=extra34->height+height;
 int limit3=10000;
 BSStringTChar str1((const char*)text);
 NiAVObject* mesh6=FontSystem::GetSingleton()->GetFont(1)->FUN_00a12460(0,0,0,&str1,&limit3,2,&DAT_011a9be0,0,1);
 if(!mesh6) return false;
 nodeB->Attach(mesh6,true);
 extra34->text=(const char*)text;
 ThreeByThreeMatrix mx1;
 mx1.MakeX(1.5707963705062866f);
 mesh6->SetRotation(mx1*mesh6->rotation);
 nodeB->SetPosition(0,0,(float)total2);
 mx1.MakeX(-1.5707963705062866f);
 ThreeByThreeMatrix local1448;
 local1448.MakeY(3.1415927410125732f);
 nodeB->SetRotation((mx1*local1448).Multiply(nodeB->rotation));
 nodeB->SetScale(0.5f);
 extra34->node=nodeB;
 NiAlphaProperty* alphaB=new NiAlphaProperty;
 reinterpret_cast<AlphaFlag>(FUN_00633ba0)(alphaB,true,1);
 reinterpret_cast<AlphaFlag>(FUN_00633ba0)(alphaB,false,0x2000);
 nodeB->AttachProperty(alphaB);
 FUN_00b57e30(mesh6,0,0);
 if(!found) reinterpret_cast<ExtraAttach>(SetExtraDataName)(root,extra34);
 static_cast<NiAVObject*>(root)->Attach(nodeB,true);
 reinterpret_cast<fnv_00a10770::FUN_0051cf00*>(nodeB)->FUN_00a5a040();
 NiUpdateData updateD3(0,false,false);
 nodeB->Update(updateD3);
 TextEntry* entry7=(TextEntry*)new FUN_00a11880;
 entry7->x=(float)total2;
 entry7->y=(float)total2;
 entry7->duration=duration;
 entry7->text=(const char*)text;
 entry7->node.FUN_0066b0d0(nodeB);
 reinterpret_cast<FUN_00a11c00_shell*>(&DebugState::FUN_00a0d9e0(true)->list)->FUN_00a11c00(reinterpret_cast<NiTMapItem*>(&entry7));
 return true;
}
