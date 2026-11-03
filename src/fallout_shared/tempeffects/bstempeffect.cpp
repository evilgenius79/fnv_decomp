// fallout_shared/tempeffects/bstempeffect.cpp: SandBoxActorPackageData, BSTempEffect (14 functions)

#include "bstempeffect_decls.h"

// @fnv 0x009f3a30
PTYPE SandBoxActorPackageData::GetPackageType()
{
    return PTYPE_SANDBOX;
}

// @fnv 0x006827b0
BSTempEffect::BSTempEffect(TESObjectCELL* cell, float lifetime)
{
    pCell = cell;
    m_fParticleParameter5 = lifetime;
    m_fFirstFloatValue = 0.0f;
    bInitialized = false;
}

struct FUN_00682860_shell : public BSTempEffect
{
    void FUN_00682860();
};

extern const void* vftable_BSTempEffect;
void __fastcall FUN_00a5d3d0(void*);

// Resets the vtable pointer and fields at offsets 0x8, 0xc, 0x10 and 0x14, then calls FUN_00a5d3d0 on this.
// @fnv 0x00682860
void FUN_00682860_shell::FUN_00682860()
{
    *(const void**)this = &vftable_BSTempEffect;
    *(int*)((char*)this + 0xc) = 0;
    *(float*)((char*)this + 0x8) = 0.0f;
    *(float*)((char*)this + 0x10) = 0.0f;
    *(char*)((char*)this + 0x14) = 0;
    FUN_00a5d3d0(this);
}

struct BGSEntryPointFunctionData;
struct TESFile;
struct TESForm;
struct TESLevItem;
struct FUN_009cbb10_shell : public BSTempEffect
{
    int FUN_009cbb10();
};

// @fnv 0x009cbb10
int FUN_009cbb10_shell::FUN_009cbb10()
{
    return 3;
}

extern const char* const g_011d6a90_arg1;

struct FUN_00682800_shell
{
    const char* const* GetRTTI() const;
};

// @fnv 0x00682800
const char* const* FUN_00682800_shell::GetRTTI() const
{
    return &g_011d6a90_arg1;
}

struct FUN_006828e0_shell
{
    unsigned short __thiscall FUN_006828e0();
};

// @fnv 0x006828e0
unsigned short __thiscall FUN_006828e0_shell::FUN_006828e0()
{
    unsigned short usSize = 0;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    return usSize;
}

struct BGSLoadFormBuffer
{
    void __thiscall ReadTypedData(void* pData, unsigned int cbData);
};

struct FUN_00682a80_shell
{
    void FUN_00682a80(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x00682a80
void FUN_00682a80_shell::FUN_00682a80(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 8), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x10), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x14), 1);
}

struct FUN_00682810_shell
{
    void FUN_00682810();
};

// @fnv 0x00682810
void FUN_00682810_shell::FUN_00682810()
{
    *(char*)((char*)this + 0x14) = 1;
}

namespace fnv_00682830 {
struct FUN_00682860_shell
{
    void FUN_00682860();
};
void _delete(void*, unsigned int);
struct FUN_00682830_shell : BSTempEffect
{
    void* FUN_00682830(unsigned int);
};
// @fnv 0x00682830
void* FUN_00682830_shell::FUN_00682830(unsigned int flags)
{
    reinterpret_cast<FUN_00682860_shell*>(this)->FUN_00682860();
    if (flags & 1)
        _delete(this, 0x18);
    return this;
}
}  // namespace fnv_00682830

struct FUN_006828a0_shell
{
    char _00[8];
    float m_fParticleParameter5;
    char _0c[4];
    float m_fFirstFloatValue;
    bool FUN_006828a0(float afTimeDelta);
};
// @fnv 0x006828a0
bool FUN_006828a0_shell::FUN_006828a0(float afTimeDelta)
{
    m_fFirstFloatValue += afTimeDelta;
    if (m_fFirstFloatValue > m_fParticleParameter5)
        return false;
    return true;
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct Holder00682a30
{
    void FUN_00682a30(BGSSaveFormBuffer*);
};
// Writes the 4-byte fields at offsets 8 and 16 and the 1-byte field at offset 20 of this object into apSaveGameBuffer.
// @fnv 0x00682a30
void Holder00682a30::FUN_00682a30(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((void*)((char*)this + 8), 4, 0);
    apSaveGameBuffer->SaveData((void*)((char*)this + 16), 4, 0);
    apSaveGameBuffer->SaveData((void*)((char*)this + 20), 1, 0);
}

struct SoundH
{
    void* pBase;
    unsigned int m_uiReadOffset;
    void* pCell;
    void* Deallocate();
};

struct TESSaveLoadGame
{
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int, int);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00682920_shell
{
    void FUN_00682920();
};

// @fnv 0x00682920
void FUN_00682920_shell::FUN_00682920()
{
    g_TESSaveLoadGame->FUN_008579b0((char*)this + 8, 4);
    g_TESSaveLoadGame->FUN_008579b0((char*)this + 0x10, 4);
    SoundH* apSaveGameBuffer = 0;
    if (*(void**)((char*)this + 0xc))
    {
        apSaveGameBuffer = (SoundH*)((SoundH*)*(void**)((char*)this + 0xc))->Deallocate();
    }
    g_TESSaveLoadGame->FUN_00857a10((int)&apSaveGameBuffer, 4);
}

class NiNode;

class TESForm
{
  public:
    virtual ~TESForm()
    {}
};

class TESObjectCELL : public TESForm
{
  public:
    NiNode* FUN_00545cb0();
};

struct FUN_00682990_LoadShim
{
    void FUN_008579e0(void*, unsigned int);
};

struct FUN_00682990_SGLShim
{
    void FUN_00857aa0(unsigned int*, int);
};

extern void* DAT_011de45c;
TESForm* LookupFormByID(unsigned int);

struct FUN_00682990_shell
{
    bool FUN_00682990();
};

// @fnv 0x00682990
// @fnv 0x00682990
bool FUN_00682990_shell::FUN_00682990()
{
    bool result = true;
    unsigned int formID;

    reinterpret_cast<FUN_00682990_LoadShim*>(DAT_011de45c)
        ->FUN_008579e0(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 8), 4);
    reinterpret_cast<FUN_00682990_LoadShim*>(DAT_011de45c)
        ->FUN_008579e0(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4);
    reinterpret_cast<FUN_00682990_SGLShim*>(DAT_011de45c)->FUN_00857aa0(&formID, 4);

    *reinterpret_cast<TESObjectCELL**>(reinterpret_cast<char*>(this) + 0x0c) =
        dynamic_cast<TESObjectCELL*>(LookupFormByID(formID));

    if (!*reinterpret_cast<TESObjectCELL**>(reinterpret_cast<char*>(this) + 0x0c) ||
        !(*reinterpret_cast<TESObjectCELL**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_00545cb0())
        result = false;

    return result;
}
