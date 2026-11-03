
// src/fallout_shared/bgsammoform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsammoform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct BGSAmmoForm : BaseFormComponent
{
    void* m_pAmmo;
    bool FUN_00474b70(BaseFormComponent* apCompareFC);
};

// @fnv 0x00474b70
bool BGSAmmoForm::FUN_00474b70(BaseFormComponent* apCompareFC)
{
    BGSAmmoForm* pcompare = dynamic_cast<BGSAmmoForm*>(apCompareFC);
    if (!pcompare)
        return true;
    if (m_pAmmo != pcompare->m_pAmmo)
        return true;
    return false;
}

void __cdecl _FUN_00485910(unsigned int, unsigned int);
struct DeallocHolder
{
    unsigned int __thiscall _ref_0084e3a0();
};
struct Shell474af0 : BGSAmmoForm
{
    void FUN_00474af0();
};
// @fnv 0x00474af0
void Shell474af0::FUN_00474af0()
{
    if (m_pAmmo != 0)
    {
        unsigned int uiRet = ((DeallocHolder*)m_pAmmo)->_ref_0084e3a0();
        _FUN_00485910(0x304D414E, uiRet);
    }
}

struct FUN_00474b30_Holder : BaseFormComponent
{
    void* ammo;
    void CopyAmmoFrom(BaseFormComponent* apCopyFC);
};
// @fnv 0x00474b30
void FUN_00474b30_Holder::CopyAmmoFrom(BaseFormComponent* apCopyFC)
{
    BGSAmmoForm* pcopy = dynamic_cast<BGSAmmoForm*>(apCopyFC);
    if (!pcopy)
        return;
    ammo = pcopy->m_pAmmo;
}

extern char DAT_01183028;
extern char DAT_011840c4;
extern int __cdecl FUN_00ec43fb(int target, int zero, const char* first, const char* second, int finalValue);
struct RangeHolder
{
    int* FUN_006815c0();
};
struct GroupHolder
{
    RangeHolder* FUN_00500940();
};
struct FUN_00474a80_Class
{
    GroupHolder* FUN_00474a40();
    bool FUN_00474a80();
};
// @fnv 0x00474a80
bool FUN_00474a80_Class::FUN_00474a80()
{
    if (FUN_00474a40())
    {
        int value = *FUN_00474a40()->FUN_00500940()->FUN_006815c0();
        if (value != 0)
        {
            int result = FUN_00ec43fb(value, 0, &DAT_01183028, &DAT_011840c4, 0);
            if (result == 0)
                return true;
        }
    }
    return false;
}

struct AmmoRecord
{
    int __thiscall FUN_00401170();
};
struct ComparisonInfo
{
    int __thiscall FUN_00484e60(int);
    int __thiscall FUN_00474cb0();
    unsigned int __thiscall FUN_0084e3a0();
};
void __cdecl ResolveFormID(void**, int);
void* __cdecl LookupFormByID(void*);
void __cdecl FUN_005b5e40(const char*, ...);
extern const char str_0101a3c8[];
extern const char str_0101a404[];
extern const char str_0101a444[];

struct FUN_00474bc0_shell : BaseFormComponent
{
    void* m_pAmmo;
    void __thiscall CompareAmmo(BaseFormComponent*);
};
// @fnv 0x00474bc0
void __thiscall FUN_00474bc0_shell::CompareAmmo(BaseFormComponent* apCompareFC)
{
    if (m_pAmmo)
    {
        void* oldAmmo = m_pAmmo;
        ResolveFormID(&oldAmmo, reinterpret_cast<ComparisonInfo*>(apCompareFC)->FUN_00484e60(-1));
        m_pAmmo = LookupFormByID(oldAmmo);
        if (m_pAmmo && reinterpret_cast<AmmoRecord*>(m_pAmmo)->FUN_00401170() != 0x29 &&
            reinterpret_cast<AmmoRecord*>(m_pAmmo)->FUN_00401170() != 0x55)
        {
            m_pAmmo = 0;
        }
        if (!m_pAmmo)
        {
            if (apCompareFC)
            {
                if (reinterpret_cast<ComparisonInfo*>(apCompareFC)->FUN_00474cb0())
                {
                    FUN_005b5e40(str_0101a444, oldAmmo,
                                 (reinterpret_cast<int(__thiscall*)(BaseFormComponent*)>(
                                     (*reinterpret_cast<void***>(apCompareFC))[0x130 / 4]))(apCompareFC));
                }
                else
                {
                    FUN_005b5e40(str_0101a404, oldAmmo, reinterpret_cast<DeallocHolder*>(apCompareFC)->_ref_0084e3a0());
                }
            }
            else
            {
                FUN_005b5e40(str_0101a3c8, oldAmmo);
            }
        }
    }
}
