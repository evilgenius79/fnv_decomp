// fallout_shared/pathfinding/navmesh_util.cpp: NavMesh, std, CircularArc, ASC and more (100 functions)

#include "navmesh_util_decls.h"

// @fnv 0x006971e0
NiPoint3 NavMesh::GetPlaneNormal(unsigned short triangleIndex)
{
    NavMeshTriangle* triangle = GetTriangle(triangleIndex);
    struct LineSegment
    {
        NiPoint3 first, second;
    } edges = {FUN_0068f0a0(triangle->FUN_005582d0(1)) - FUN_0068f0a0(triangle->FUN_005582d0(0)),
               FUN_0068f0a0(triangle->FUN_005582d0(2)) - FUN_0068f0a0(triangle->FUN_005582d0(0))};
    return edges.first.CrossProduct(edges.second);
}

// Wraps a NavMesh pointer in a NiPointer<NavMesh> and returns it.
// @fnv 0x00464fc0
NiPointer<NavMesh> MakeNavMeshPointer(NavMesh* mesh)
{
    return NiPointer<NavMesh>(mesh);
}

// Scans the closed-door info list for an entry whose triangle index matches triangleIndex and returns a pointer to it, or null if none matches.
// @fnv 0x00699af0
NavMeshClosedDoorInfo* NavMesh::GetClosedDoorInfo(unsigned short triangleIndex)
{
    for (unsigned int i = 0; i < m_kClosedDoorInfo.GetSize(); i++)
    {
        if (m_kClosedDoorInfo.GetElement(i).m_usTriangleID == triangleIndex)
            return &m_kClosedDoorInfo.GetElement(i);
    }
    return 0;
}

// Computes the arc length from the angle between Start and End, wrapping negative angles by 2*pi and inverting when Dir is nonzero, scaled by radius.
// @fnv 0x006a07a0
float CircularArc::GetLength(float radius)
{
    SineCosine difference = End - Start;
    float angle = difference.FUN_006a0840();
    if (Dir == 0)
    {
        if (angle < 0.0)
            return (angle + 6.2831854820251465) * radius;
        else
            return angle * radius;
    }
    else
    {
        if (angle < 0.0)
            return -angle * radius;
        else
            return (6.2831854820251465 - angle) * radius;
    }
}

// Gets the triangle's three vertices, converts them, and tests the point against them to compute height within the above/below range.
// @fnv 0x00697730
bool NavMesh::FindHeightOnTriangle(unsigned short triangleIndex, const NiPoint3& point, float& height, float above,
                                   float below)
{
    NiPoint3 first, second, third;
    NavMeshTriangle* pNavTriangle;
    pNavTriangle = GetTriangle(triangleIndex);
    first = FUN_0068f0a0(pNavTriangle->FUN_005582d0(0));
    second = FUN_0068f0a0(pNavTriangle->FUN_005582d0(1));
    third = FUN_0068f0a0(pNavTriangle->FUN_005582d0(2));
    return FUN_006b9cf0(first, second, third, point, height, above, below);
}

// Computes an offset from the obstacle extent, gathers triangles via FUN_006987d0, and marks each triangle closed for the given door unless already recorded.
// @fnv 0x006997e0
bool NavMesh::AddDoorObstacle(unsigned int doorID, ObstacleData* obstacle)
{
    struct DoorBounds
    {
        NiPoint3 extent, offset;
    } geometry = {obstacle->m_kBoundsMax - obstacle->m_kBoundsMin, NiPoint3::ZERO};
    if (std::abs(geometry.extent.x) < std::abs(geometry.extent.y))
    {
        if (std::abs(geometry.extent.x) < std::abs(geometry.extent.z))
            geometry.offset.x = -std::abs(geometry.extent.x) * 0.49000000953674316;
        else
            geometry.offset.z = -std::abs(geometry.extent.z) * 0.49000000953674316;
    }
    else
    {
        if (std::abs(geometry.extent.y) < std::abs(geometry.extent.z))
            geometry.offset.y = -std::abs(geometry.extent.y) * 0.49000000953674316;
        else
            geometry.offset.z = -std::abs(geometry.extent.z) * 0.49000000953674316;
    }
    BSSimpleArray<unsigned short> triangles;
    FUN_006987d0(obstacle, geometry.offset, &triangles);
    for (unsigned int i = 0; i < triangles.GetSize(); i++)
    {
        NavMeshClosedDoorInfo* existing = GetClosedDoorInfo(triangles.GetBufferEntry(i));
        if (!existing || existing->iDoorID != doorID)
        {
            GetTriangle(triangles.GetBufferEntry(i))->FUN_00691570(0x1000);
            NavMeshClosedDoorInfo entry;
            entry.iDoorID = doorID;
            entry.m_usTriangleID = triangles.GetBufferEntry(i);
            m_kClosedDoorInfo.Append(entry);
        }
    }
    return true;
}

void __fastcall FUN_004a3d40(void* pThis);
void __fastcall FUN_004a3d80(void* pThis);

// @fnv 0x004a3d20
void* __fastcall FUN_004a3d20(void* pThis)
{
    FUN_004a3d40(pThis);
    FUN_004a3d80(pThis);
    return pThis;
}

struct FUN_005eeda0_this
{
    int pad0;
    unsigned short* pBuffer;
    unsigned short& GetBufferEntry(unsigned int aiIndex);
};

// @fnv 0x005eeda0
unsigned short& FUN_005eeda0_this::GetBufferEntry(unsigned int aiIndex)
{
    return pBuffer[aiIndex];
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x006917d0
void* __fastcall FUN_006917d0(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}

struct FUN_006969e0_shell : public NavMesh
{
    bool FUN_006969e0(NiPoint3*, NiPoint3*);
};

struct DummyA8
{
    void GetVectors(NiPoint3*, NiPoint3*);
};

// @fnv 0x006969e0
bool FUN_006969e0_shell::FUN_006969e0(NiPoint3* aRetMin, NiPoint3* aRetMax)
{
    reinterpret_cast<DummyA8*>(reinterpret_cast<char*>(this) + 0xa8)->GetVectors(aRetMin, aRetMax);
    return true;
}

struct V3
{
    float x, y, z;
};
struct FUN_00698580_S
{
    V3 a;
    V3 b;
    FUN_00698580_S* FUN_00698580(const V3* p, const V3* q);
};
// @fnv 0x00698580
FUN_00698580_S* FUN_00698580_S::FUN_00698580(const V3* p, const V3* q)
{
    a = *p;
    b = *q;
    return this;
}

void __stdcall compiler_vector_constructor_iterator(void*, unsigned int, int, void*);
void FUN_006d5320();

// @fnv 0x006985c0
void* __fastcall ConstructWithVector(void* apObject)
{
    compiler_vector_constructor_iterator((char*)apObject + 4, 0x10, 2, &FUN_006d5320);
    return apObject;
}

struct FUN_006985f0_shell : public SineCosine
{
    SineCosine* CopyFloatPair(void*);
};

// Copies the first two floats from p into this object and returns this.
// @fnv 0x006985f0
SineCosine* FUN_006985f0_shell::CopyFloatPair(void* apSource)
{
    reinterpret_cast<float*>(this)[0] = static_cast<const float*>(apSource)[0];
    reinterpret_cast<float*>(this)[1] = static_cast<const float*>(apSource)[1];
    return this;
}

struct ASC
{
    float s, c;
    void _ref_006815c0();
    ASC& operator=(const ASC&);
    ASC* Multiply(ASC* out, const ASC* o);
};
// Computes the product of this ASC and another ASC into out, combining s and c with the given formulas, and returns out.
// @fnv 0x00698620
ASC* ASC::Multiply(ASC* out, const ASC* apOther)
{
    ASC ret;
    ret._ref_006815c0();
    ret.s = s * apOther->s + c * apOther->c;
    ret.c = c * apOther->s - s * apOther->c;
    out->operator=(ret);
    return out;
}

// @fnv 0x00698680
int __fastcall GetSignFlags(float* afValues)
{
    int res = 0;
    if (afValues[1] < 0.0)
        res ^= 3;
    if (afValues[0] < 0.0)
        res ^= 1;
    return res;
}

struct Sub
{
    int z[4];
    Sub();
    ~Sub();
};
struct FUN_00699450_S
{
    Sub a;
    Sub b;
    FUN_00699450_S();
};
// Constructs the object by default-constructing its two Sub members.
// @fnv 0x00699450
FUN_00699450_S::FUN_00699450_S()
{}

struct FUN_0069af60
{
    int pad[4];
    ~FUN_0069af60();
};

struct FUN_006994b0
{
    FUN_0069af60 a;
    FUN_0069af60 b;
    ~FUN_006994b0();
};

// @fnv 0x006994b0
FUN_006994b0::~FUN_006994b0()
{}

struct Dummy_0069a660
{
    int a;
    short b;
    Dummy_0069a660* SetValues(int p1, short p2);
};

// Stores the two arguments into the object's fields and returns the object.
// @fnv 0x0069a660
Dummy_0069a660* Dummy_0069a660::SetValues(int aiValue, short asValue)
{
    a = aiValue;
    b = asValue;
    return this;
}

struct FUN_0069a6c0_S
{
    void* nav;
    unsigned short tri;
    int edge;
    void _ref_006815c0();
    FUN_0069a6c0_S* FUN_0069a6c0(void* n, unsigned short t, int e);
};
// Calls _ref_006815c0, then stores the nav pointer, triangle index and edge value into this object and returns it.
// @fnv 0x0069a6c0
FUN_0069a6c0_S* FUN_0069a6c0_S::FUN_0069a6c0(void* apNav, unsigned short ausTri, int aiEdge)
{
    _ref_006815c0();
    nav = apNav;
    tri = ausTri;
    edge = aiEdge;
    return this;
}

struct FUN_0069a700_shell : public NavMeshTriangleHandle
{
    void FUN_0069a700(void*);
};

// Builds a 16-bit value from bits 0-13 of the word at aEdge+4 and bits 0-1 of the word at aEdge+8 shifted left 14, storing it at this.
// @fnv 0x0069a700
void FUN_0069a700_shell::FUN_0069a700(void* aEdge)
{
    *(unsigned short*)this =
        ((*(unsigned short*)((char*)aEdge + 4) & 0x3fff) | ((*(unsigned short*)((char*)aEdge + 8) & 3) << 14));
}

extern int DAT_0106b1b8;

struct Dummy_0069af30
{
    void* vtable;
    void ResetAndWrite(int, int);
};

// Sets the vtable pointer and calls ResetAndWrite with 0, 0, then returns pThis.
// @fnv 0x0069af30
Dummy_0069af30* __fastcall FUN_0069af30(Dummy_0069af30* pThis)
{
    pThis->vtable = &DAT_0106b1b8;
    pThis->ResetAndWrite(0, 0);
    return pThis;
}

extern int DAT_0106b1b8;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x0069af60
void __fastcall FUN_0069af60(GlobalObject_00869f00* apObject)
{
    *(int**)apObject = &DAT_0106b1b8;
    apObject->Clear(true);
}

struct VH
{
    int a[2];
    void TwoIntRecord(const VH&);
};
struct FUN_0069b030_S
{
    int pad;
    VH* data;
    unsigned int FUN_00845460();
    void ConstructPairCells(VH*, int);
    unsigned int Append(const VH* v);
};
// @fnv 0x0069b030
unsigned int FUN_0069b030_S::Append(const VH* apValue)
{
    unsigned int i = FUN_00845460();
    ConstructPairCells(&data[i], 1);
    data[i].TwoIntRecord(*apValue);
    return i;
}

struct EH
{
    char b[12];
    EH& operator=(const EH&);
};
struct FUN_0069b310_S
{
    int pad;
    EH* data;
    unsigned int FUN_00978bc0();
    void ConstructBounds(EH*, int);
    unsigned int AppendElement(const EH* v);
};
// Gets the current count, grows the data array by one element, copies the given element into the new slot, and returns its index.
// @fnv 0x0069b310
unsigned int FUN_0069b310_S::AppendElement(const EH* apElement)
{
    unsigned int i = FUN_00978bc0();
    ConstructBounds(&data[i], 1);
    data[i] = *apElement;
    return i;
}

float __cdecl cos(float);
float __cdecl FUN_004e44b0(float);

struct FUN_006a04e0_helper : public SineCosine
{
    void* SetFromAngle(float afAngle);
};

// Stores cos(afAngle) and FUN_004e44b0(afAngle) into the first two floats of this object and returns this.
// @fnv 0x006a04e0
void* FUN_006a04e0_helper::SetFromAngle(float afAngle)
{
    ((float*)this)[0] = cos(afAngle);
    ((float*)this)[1] = FUN_004e44b0(afAngle);
    return this;
}

struct FUN_006bc870_shell : public NavMeshEdgeData
{
    NavMeshEdgeData* CopyFromNavMeshEdge(void*);
};

// Copies an int, a short and an int from aNavMeshEdgeHandle into this object at offsets 0, 4 and 8, then returns this.
// @fnv 0x006bc870
NavMeshEdgeData* FUN_006bc870_shell::CopyFromNavMeshEdge(void* aNavMeshEdgeHandle)
{
    *(int*)((char*)this + 0) = *(int*)((char*)aNavMeshEdgeHandle + 0);
    *(short*)((char*)this + 4) = *(short*)((char*)aNavMeshEdgeHandle + 4);
    *(int*)((char*)this + 8) = *(int*)((char*)aNavMeshEdgeHandle + 8);
    return this;
}

struct NiP2
{
    float x, y;
    NiP2();
};
struct USW
{
    unsigned short v;
};
struct IW
{
    int v;
};
bool __cdecl FUN_006b9e90(NiP2*, NiP2*, int, int, int);
// Builds the triangle's three 2D vertices and returns the first edge index (skipping edge) for which FUN_006b9e90 succeeds, else -1.
// @fnv 0x00698060
int __fastcall FindTriangleEdge(NavMesh* self, USW usTri, IW iSkipEdge, IW a3, IW a4, IW a5)
{
    NiP2 verts[3];
    NiPoint3 pt;
    for (int i = 0; i < 3; i++)
    {
        pt = self->FUN_0068f0a0(self->GetTriangle(usTri.v)->FUN_005582d0(i));
        verts[i].x = pt.x;
        verts[i].y = pt.y;
    }
    for (int j = 0; j < 3; j++)
    {
        if (j == iSkipEdge.v)
            continue;
        int k = j + 1;
        if (k == 3)
            k = 0;
        if (FUN_006b9e90(&verts[j], &verts[k], a3.v, a4.v, a5.v))
            return j;
    }
    return -1;
}

struct S0069a690
{
    int a;
    unsigned short b;
    S0069a690* FUN_0069a690(const S0069a690* o);
};
// Copies the int and unsigned short members from another S0069a690 into this one and returns this.
// @fnv 0x0069a690
S0069a690* S0069a690::FUN_0069a690(const S0069a690* apOther)
{
    a = apOther->a;
    b = apOther->b;
    return this;
}

extern unsigned int _data_011c16bc;
struct B006815c0
{
    char p[8];
    B006815c0();
};
struct FUN_0069b2c0
{
    char p[0x10];
    FUN_0069b2c0();
    ~FUN_0069b2c0();
};
struct FUN_0069a730 : public B006815c0
{
    FUN_0069b2c0 a;
    FUN_0069b2c0 b;
    FUN_0069a730();
};
// Default constructor for FUN_0069a730 that initializes its two FUN_0069b2c0 members and base B006815c0.
// @fnv 0x0069a730
FUN_0069a730::FUN_0069a730()
{}

struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    virtual void SetValue(IT*, TwoIntRecord, void*);
    virtual void v4();
    virtual IT* NewItem();
    unsigned int cnt;
    IT** table;
    unsigned int count;
};
struct VW
{
    void* p;
};
// Looks up key in the hash table; if found, overwrites its value, otherwise allocates a new item, inserts it at the bucket head and increments count.
// @fnv 0x0069b3d0
void __fastcall SetKeyValue(MP* self, TwoIntRecord key, VW val)
{
    IT* pkItem;
    unsigned int uiIndex;
    unsigned int uiDepth;
    uiIndex = self->KeyToHashIndex(key);
    pkItem = self->table[uiIndex];
    uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (self->IsKeyEqual(key, pkItem->key))
        {
            pkItem->val = val.p;
            return;
        }
        pkItem = pkItem->next;
    }
    pkItem = self->NewItem();
    self->SetValue(pkItem, key, val.p);
    pkItem->next = self->table[uiIndex];
    self->table[uiIndex] = pkItem;
    self->count++;
}

namespace fnv_0069b4d0 {
struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    unsigned int cnt;
    IT** table;
};
struct VW
{
    void** p;
};
// Looks up key in the hash table and, if an equal entry is found, stores its value through val.p and returns true; otherwise returns false.
// @fnv 0x0069b4d0
bool __fastcall FUN_0069b4d0(MP* self, TwoIntRecord key, VW aOutValue)
{
    IT* pkItem;
    unsigned int uiIndex = self->KeyToHashIndex(key);
    pkItem = self->table[uiIndex];
    while (pkItem)
    {
        if (self->IsKeyEqual(key, pkItem->key))
        {
            *aOutValue.p = pkItem->val;
            return true;
        }
        pkItem = pkItem->next;
    }
    return false;
}
}  // namespace fnv_0069b4d0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0069a7a0(unsigned int flags);
};
// Calls the destructor on this object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0069a7a0
void* DelStandIn::FUN_0069a7a0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float afX, float afY, float afZ);
    NiPoint3 operator+(const NiPoint3& arPt) const;
};

struct ObstacleDataEx : public ObstacleData
{
    NiPoint3Ex WorldMin;
    NiPoint3Ex WorldMax;
};

struct ObstacleDataPtr
{
    ObstacleDataEx* object;
    ObstacleDataEx* operator->() const;
};

bool __cdecl AreWideCharsEqual(const unsigned short& a, const unsigned short& b);

struct NavMeshTriList : public BSSimpleArray<unsigned short>
{
    unsigned int GetSize() const;
    const unsigned short& FUN_0069dec0(unsigned int auiIndex) const;
    int FindMatchingIndex(const unsigned short& arItem, unsigned int auiStart,
                          bool(__cdecl* apCompare)(const unsigned short&, const unsigned short&));
};

struct NavMeshGrid
{
    void GetCellCoords(const NiPoint3& arPos, unsigned int& arRow, unsigned int& arCol);
    NavMeshTriList* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
};

struct NavMeshTriangleEx : public NavMeshTriangle
{
    bool GetFlag(int aiFlag);
};

float __cdecl FUN_0040ebd0(float a, float b);
float __cdecl FUN_00404010(float a, float b);
NiPoint3 __cdecl FUN_004b3ae0(const NiPoint3& arPt, const float* apRot);
bool __cdecl DoBoundsOverlap(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
bool __cdecl FUN_006c3570(const NiPoint3& arCenter, const ObstacleDataPtr& arObstacle, float afHeight, float afFudge);
bool __cdecl FUN_00696540(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
extern const float DAT_01015f5c;

struct NavMeshOverlap : public NavMesh
{
    NavMeshGrid Grid;
    NiPoint3 GetNavMeshData(unsigned short ausTriangle);
    void FUN_006987d0(const ObstacleDataPtr& apObstacle, const NiPoint3& afFudge, NavMeshTriList* apRetTriangles);
};

// @fnv 0x006987d0
void NavMeshOverlap::FUN_006987d0(const ObstacleDataPtr& apObstacle, const NiPoint3& afFudge,
                                  NavMeshTriList* apRetTriangles)
{
    unsigned int istartRow = 0;
    unsigned int istartCol = 0;
    unsigned int iendRow = 0;
    unsigned int iendCol = 0;

    Grid.GetCellCoords(apObstacle->WorldMin, istartRow, istartCol);
    Grid.GetCellCoords(apObstacle->WorldMax, iendRow, iendCol);

    NiPoint3 cornersLocalSpace[4];
    cornersLocalSpace[0] = NiPoint3Ex(apObstacle->m_kBoundsMin.x - afFudge.x, apObstacle->m_kBoundsMin.y - afFudge.y,
                                      apObstacle->m_kBoundsMin.z);
    cornersLocalSpace[1] = NiPoint3Ex(apObstacle->m_kBoundsMin.x - afFudge.x, apObstacle->m_kBoundsMax.y + afFudge.y,
                                      apObstacle->m_kBoundsMin.z);
    cornersLocalSpace[2] = NiPoint3Ex(apObstacle->m_kBoundsMax.x + afFudge.x, apObstacle->m_kBoundsMax.y + afFudge.y,
                                      apObstacle->m_kBoundsMin.z);
    cornersLocalSpace[3] = NiPoint3Ex(apObstacle->m_kBoundsMax.x + afFudge.x, apObstacle->m_kBoundsMin.y - afFudge.y,
                                      apObstacle->m_kBoundsMin.z);

    float fzheight = apObstacle->WorldMax.z - apObstacle->WorldMin.z;

    for (unsigned int r = istartRow; r <= iendRow; r++)
    {
        for (unsigned int c = istartCol; c <= iendCol; c++)
        {
            NavMeshTriList* parray = Grid.FUN_006967c0(c, r);
            if (parray)
            {
                for (unsigned int i = 0; i < parray->GetSize(); i++)
                {
                    if (apRetTriangles->FindMatchingIndex(parray->FUN_0069dec0(i), 0, AreWideCharsEqual) != -1)
                        continue;
                    NavMeshTriangleEx* ptri = (NavMeshTriangleEx*)GetTriangle(parray->FUN_0069dec0(i));
                    if (ptri->GetFlag(0x20))
                        continue;

                    NiPoint3Ex wtriMin(3.402823466e+38f, 3.402823466e+38f, 3.402823466e+38f);
                    NiPoint3Ex wtriMax(DAT_01015f5c, DAT_01015f5c, DAT_01015f5c);
                    for (int v = 0; v < 3; v++)
                    {
                        const NiPoint3* vertLocation = &FUN_0068f0a0(ptri->FUN_005582d0(v));
                        wtriMin.x = FUN_0040ebd0(wtriMin.x, vertLocation->x);
                        wtriMin.y = FUN_0040ebd0(wtriMin.y, vertLocation->y);
                        wtriMin.z = FUN_0040ebd0(wtriMin.z, vertLocation->z);
                        wtriMax.x = FUN_00404010(wtriMax.x, vertLocation->x);
                        wtriMax.y = FUN_00404010(wtriMax.y, vertLocation->y);
                        wtriMax.z = FUN_00404010(wtriMax.z, vertLocation->z);
                    }
                    wtriMax.z += 128.0;

                    if (!DoBoundsOverlap(apObstacle->WorldMin - afFudge, apObstacle->WorldMax + afFudge, wtriMin,
                                         wtriMax))
                        continue;

                    bool bOverlap = false;
                    float fdontCare;
                    if (FUN_006c3570(GetNavMeshData(parray->FUN_0069dec0(i)), apObstacle, fzheight, 128.0f))
                    {
                        bOverlap = true;
                    }
                    else if (FindHeightOnTriangle(parray->FUN_0069dec0(i),
                                                  *(const NiPoint3*)(apObstacle->prefix + 0x10), fdontCare, fzheight,
                                                  128.0f))
                    {
                        bOverlap = true;
                    }
                    else
                    {
                        for (unsigned int triv = 0; triv < 3; triv++)
                        {
                            unsigned int triw = triv + 1;
                            if (triw == 3)
                                triw = 0;
                            NiPoint3 vert1 = FUN_004b3ae0(FUN_0068f0a0(ptri->FUN_005582d0(triv)) -
                                                              *(const NiPoint3*)(apObstacle->prefix + 0x10),
                                                          (const float*)(apObstacle->prefix + 0x1c));
                            NiPoint3 vert2 = FUN_004b3ae0(FUN_0068f0a0(ptri->FUN_005582d0(triw)) -
                                                              *(const NiPoint3*)(apObstacle->prefix + 0x10),
                                                          (const float*)(apObstacle->prefix + 0x1c));
                            for (unsigned int boxv = 0; boxv < 4; boxv++)
                            {
                                unsigned int boxw = boxv + 1;
                                if (boxw == 4)
                                    boxw = 0;
                                NiPoint3 box1 = cornersLocalSpace[boxv];
                                NiPoint3 box2 = cornersLocalSpace[boxw];
                                if (FUN_00696540(vert1, vert2, box1, box2))
                                {
                                    bOverlap = true;
                                    break;
                                }
                            }
                            if (bOverlap)
                                break;
                        }
                    }
                    if (bOverlap)
                        apRetTriangles->ReserveIndex(parray->FUN_0069dec0(i));
                }
            }
        }
    }
}

struct NavMeshVertexEdgeData;

struct VertMapItem
{
    VertMapItem* m_pkNext;
    TwoIntRecord m_key;
    NavMeshVertexEdgeData* m_val;
};

struct VertMap
{
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(TwoIntRecord key) const;
    unsigned int m_uiHashSize;
    VertMapItem** m_ppkHashTable;
    void GetNextEntry(void*& pos, TwoIntRecord& key, NavMeshVertexEdgeData*& val) const;
};

// Reads the key and value from the item at pos, then advances pos to the next item in the chain or the next non-empty hash bucket, or null.
// @fnv 0x0069b560
void VertMap::GetNextEntry(void*& pos, TwoIntRecord& arKey, NavMeshVertexEdgeData*& val) const
{
    VertMapItem* pkItem = (VertMapItem*)pos;
    arKey = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    unsigned int i = KeyToHashIndex(pkItem->m_key);
    for (++i; i < m_uiHashSize; ++i)
    {
        pkItem = m_ppkHashTable[i];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}

struct FUN_0069b120_stub
{
    void FUN_0069b120(int a, int b);
};

struct FUN_00699590_shell
{
    void ForwardToStub(int arg);
};

// Calls FUN_0069b120 on the stub at this+0xd0 with arg and 1.
// @fnv 0x00699590
void FUN_00699590_shell::ForwardToStub(int arg)
{
    ((FUN_0069b120_stub*)((char*)this + 0xd0))->FUN_0069b120(arg, 1);
}

struct Flt
{
    operator unsigned int() const;
};

struct Arr
{
    Flt* GetAt(int);
};

struct FUN_00699630_shell
{
    int FindEntryIndex(int);
    Arr arr;
    int FUN_00699630(int param1, unsigned int* out);
};

// @fnv 0x00699630
int FUN_00699630_shell::FUN_00699630(int param1, unsigned int* apuiValue)
{
    int idx = this->FindEntryIndex(param1);
    if (idx != -1)
    {
        *apuiValue = ((Arr*)((char*)this + 0xd0))->GetAt(idx)->operator unsigned int();
        return idx;
    }
    *apuiValue = 0;
    return -1;
}

struct FUN_00699790_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    unsigned int m_iFourthElementInteger;  // offset 0xc
    int GetBits13To15();
};

// @fnv 0x00699790
int FUN_00699790_shell::GetBits13To15()
{
    return (m_iFourthElementInteger & 0xe000) >> 13;
}

struct FUN_0069af80_shell
{
    void* __thiscall FUN_0069af80(int count);
};
// Allocates a new byte array of count * 12 bytes and returns a pointer to it.
// @fnv 0x0069af80
void* __thiscall FUN_0069af80_shell::FUN_0069af80(int count)
{
    return new unsigned char[count * 12];
}

struct FUN_00699b60_shell : public NavMesh
{
    void BuildPortalPOVs();
};

namespace std {
float __cdecl abs(float);
}

extern double _gModifierZero;

// Builds per-vertex edge lists from triangle edges, pairs edges into portals, and assigns each triangle the nearest portal vertex within a radius.
// @fnv 0x00699b60
void FUN_00699b60_shell::BuildPortalPOVs()
{
    POVPointerArray.RemoveAll();
    m_kAdditionalIndexList.Clear(true);
    NavMeshVertexMap kNavMeshVertexLookup(37);
    unsigned int itriCount = FUN_00558200();
    void* it;
    for (unsigned int i = 0; i < itriCount; ++i)
    {
        NavMeshTriangle* ptri = GetTriangle(i);
        for (int e = 0; e < 3; ++e)
        {
            if (ptri->FUN_0068f2c0(e) == 0xFFFF)
            {
                NavMeshEdgeData hedge(this, i, e);
                TwoIntRecord hvert1(this, ptri->FUN_005582d0(e));
                NavMeshVertexEdgeData* pdata1;
                if (!kNavMeshVertexLookup.FUN_0069b4d0(hvert1, pdata1))
                {
                    pdata1 = new NavMeshVertexEdgeData;
                    pdata1->m_kVertexKey = hvert1;
                    kNavMeshVertexLookup.SetKeyValue(hvert1, pdata1);
                }
                pdata1->Edges.AppendElement(hedge);
                TwoIntRecord hvert2(this, ptri->FUN_005582d0((e + 1) % 3));
                NavMeshVertexEdgeData* pdata2;
                if (!kNavMeshVertexLookup.FUN_0069b4d0(hvert2, pdata2))
                {
                    pdata2 = new NavMeshVertexEdgeData;
                    pdata2->m_kVertexKey = hvert2;
                    kNavMeshVertexLookup.SetKeyValue(hvert2, pdata2);
                }
                pdata2->Edges.AppendElement(hedge);
            }
            else if (ptri->IsEdgeFlagSet(e))
            {
                NavMeshEdgeData hedge(this, i, e);
                TwoIntRecord hvert1(this, ptri->FUN_005582d0(e));
                NavMeshVertexEdgeData* pdata1;
                if (!kNavMeshVertexLookup.FUN_0069b4d0(hvert1, pdata1))
                {
                    pdata1 = new NavMeshVertexEdgeData;
                    pdata1->m_kVertexKey = hvert1;
                    kNavMeshVertexLookup.SetKeyValue(hvert1, pdata1);
                }
                pdata1->m_kOutgoingEdges.AppendElement(hedge);
                TwoIntRecord hvert2(this, ptri->FUN_005582d0((e + 1) % 3));
                NavMeshVertexEdgeData* pdata2;
                if (!kNavMeshVertexLookup.FUN_0069b4d0(hvert2, pdata2))
                {
                    pdata2 = new NavMeshVertexEdgeData;
                    pdata2->m_kVertexKey = hvert2;
                    kNavMeshVertexLookup.SetKeyValue(hvert2, pdata2);
                }
                pdata2->m_kOutgoingEdges.AppendElement(hedge);
            }
        }
    }

    it = kNavMeshVertexLookup.GetFirstPos();
    while (it)
    {
        TwoIntRecord hvert;
        NavMeshVertexEdgeData* pdata;
        kNavMeshVertexLookup.GetNextEntry(it, hvert, pdata);
        unsigned int iedgeCount = pdata->Edges.GetSize();
        unsigned int iportalEdgeCount = pdata->m_kOutgoingEdges.GetSize();
        if (iedgeCount + iportalEdgeCount == 2)
        {
            NavMeshEdgeData hdataEdge0;
            NavMeshEdgeData hdataEdge1;
            if (iedgeCount == 2)
            {
                hdataEdge0 = pdata->Edges.FUN_006a1440(0);
                hdataEdge1 = pdata->Edges.FUN_006a1440(1);
            }
            else if (iedgeCount == 1)
            {
                hdataEdge0 = pdata->Edges.FUN_006a1440(0);
                hdataEdge1 = pdata->m_kOutgoingEdges.FUN_006a1440(0);
            }
            else
            {
                continue;
            }
            NavMeshEdgeData hedge1;
            NavMeshEdgeData hedge2;
            const NiPoint3* pverts[3];
            NavMeshEdgeVertexPair verts1 = FUN_0068f040(hdataEdge0.m_usTriangleID, hdataEdge0.m_iEdgeIndex);
            NavMeshEdgeVertexPair verts2 = FUN_0068f040(hdataEdge1.m_usTriangleID, hdataEdge1.m_iEdgeIndex);
            if (verts1.first == verts2.second)
            {
                hedge1 = hdataEdge0;
                hedge2 = hdataEdge1;
                pverts[0] = verts1.second;
                pverts[1] = verts1.first;
                pverts[2] = verts2.first;
            }
            else if (verts1.second == verts2.first)
            {
                hedge1 = hdataEdge1;
                hedge2 = hdataEdge0;
                pverts[0] = verts2.second;
                pverts[1] = verts2.first;
                pverts[2] = verts1.first;
            }
            else
            {
                continue;
            }
            NiPoint3 edge1 = *pverts[0] - *pverts[1];
            NiPoint3 edge2 = *pverts[2] - *pverts[1];
            edge1.z = 0;
            edge2.z = 0;
            edge1.ComputeMagnitude();
            edge2.ComputeMagnitude();
            NiPoint3 cross = edge1.Cross(edge2);
            float fdot = edge1.DotProduct(edge2);
            bool badd = false;
            if (fdot > _gModifierZero)
            {
                if (cross.z < (double)0.1f)
                {
                    badd = true;
                    if (cross.z > _gModifierZero)
                    {
                        NiPoint3 temp = edge1;
                        edge1 = edge2;
                        edge2 = temp;
                    }
                }
            }
            else if (cross.z < -(double)0.1f)
            {
                badd = true;
            }
            if (badd || iedgeCount == 1)
            {
                NavMeshPOVData pov;
                pov.m_kFirstEdge.Set(hedge1);
                pov.m_kSecondEdge.Set(hedge2);
                POVPointerArray.InsertOrUpdate(hvert.m_usVertexId, pov);
            }
        }
    }

    it = kNavMeshVertexLookup.GetFirstPos();
    while (it)
    {
        TwoIntRecord hvert;
        NavMeshVertexEdgeData* pdata;
        kNavMeshVertexLookup.GetNextEntry(it, hvert, pdata);
        delete pdata;
    }

    const float afValueAfterThirdFloat = 128.0f;
    for (unsigned int i = 0; i < itriCount; ++i)
    {
        NiPoint3 circumCenter = FUN_00697290(i);
        NiPoint3 vertLoc = FUN_0068f0a0(GetTriangle(i)->FUN_005582d0(0));
        float fradius = (vertLoc - circumCenter).FUN_00589850();
        float fmaxRadius = fradius + afValueAfterThirdFloat;
        float fmaxRadiusSqr = fmaxRadius * fmaxRadius;
        unsigned short iClosestPOV = 0xFFFF;
        float fclosestPOVSqrDist = fmaxRadiusSqr * fmaxRadiusSqr;
        void* it = POVPointerArray.GetFirstPos();
        while (it)
        {
            unsigned short usCurrentVertexIndex;
            NavMeshPOVData data;
            POVPointerArray.FUN_00694d30(it, usCurrentVertexIndex, data);
            NiPoint3 delta = FUN_0068f0a0(usCurrentVertexIndex) - circumCenter;
            float fsqrDist = delta.GetSquaredXYLength();
            if (fsqrDist < fclosestPOVSqrDist && std::abs(delta.z) < 180.0)
            {
                fclosestPOVSqrDist = fsqrDist;
                iClosestPOV = usCurrentVertexIndex;
            }
        }
        m_kAdditionalIndexList.ReserveIndex(iClosestPOV);
    }
}

struct NiPoint2
{
    float x;
    float y;
    NiPoint2(float fx, float fy);
};

extern "C" void __cdecl FUN_006ba010(const NiPoint2& a, const NiPoint2& b, const NiPoint2& c, const NiPoint2& d);

// @fnv 0x00696540
void FUN_00696540(const NiPoint3* aSegment1Start, const NiPoint3* aSegment2Start, const NiPoint3* aSegment1End,
                  const NiPoint3* aSegment2End)
{
    FUN_006ba010(NiPoint2(aSegment1Start->x, aSegment1Start->y), NiPoint2(aSegment2Start->x, aSegment2Start->y),
                 NiPoint2(aSegment1End->x, aSegment1End->y), NiPoint2(aSegment2End->x, aSegment2End->y));
}

struct FUN_006967c0_shell
{
    int f0;
    char pad[32];
    int f24;
    int FUN_006967c0(int a, int b);
};
// @fnv 0x006967c0
int FUN_006967c0_shell::FUN_006967c0(int a, int b)
{
    int t = b * f0 + a;
    return (t << 4) + f24;
}

struct Vec00696a10
{
    int v0;
    int v1;
    int v2;
};
struct Obj00696a10
{
    char pad[12];
    Vec00696a10 m1;
    Vec00696a10 m2;
    void GetVectors(Vec00696a10*, Vec00696a10*);
};
// Copies the object's two Vec00696a10 members into the caller-supplied output vectors.
// @fnv 0x00696a10
void Obj00696a10::GetVectors(Vec00696a10* pVec1, Vec00696a10* pVec2)
{
    *pVec1 = m1;
    *pVec2 = m2;
}

struct Holder
{
    void FUN_004a3c90(Holder*);
    Holder* FUN_00696ca0(Holder*);
};
// Copies the float at offset 0x10, the int at 0x14 and the 64-bit value at 0x18 from p into this after calling FUN_004a3c90, then returns this.
// @fnv 0x00696ca0
Holder* Holder::FUN_00696ca0(Holder* apSource)
{
    this->FUN_004a3c90(apSource);
    *(float*)((char*)this + 0x10) = *(float*)((char*)apSource + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)((char*)apSource + 0x14);
    *(__int64*)((char*)this + 0x18) = *(__int64*)((char*)apSource + 0x18);
    return this;
}

struct FindTriangleForLocationFilter;
struct FUN_00697670_StandIn : NavMesh
{
    unsigned short FindTriangleForLocation(const NiPoint3&, FindTriangleForLocationFilter*);
    bool IsLocationOnNavMesh(const NiPoint3&, FindTriangleForLocationFilter*);
};
// Returns true if FindTriangleForLocation finds a triangle (result not 0xFFFF) for the given position and filter.
// @fnv 0x00697670
bool FUN_00697670_StandIn::IsLocationOnNavMesh(const NiPoint3& aPos, FindTriangleForLocationFilter* apFilter)
{
    if (FindTriangleForLocation(aPos, apFilter) != 0xFFFF)
        return true;
    else
        return false;
}

struct Dummy698030
{
    int _p[3];
    unsigned int f12;
    unsigned int FUN_00698030(unsigned short a1);
};
// Shifts f12 right by a1*6+0x10 and returns the low 4 bits of the result.
// @fnv 0x00698030
unsigned int Dummy698030::FUN_00698030(unsigned short ausIndex)
{
    unsigned int result;
    {
        unsigned int shift = ausIndex * 6 + 0x10;
        result = f12 >> shift;
    }
    return result & 0xF;
}

struct FUN_00698300_shell
{
    void _ref_006815c0();
    FUN_00698300_shell* FUN_00698300();
};
// @fnv 0x00698300
FUN_00698300_shell* FUN_00698300_shell::FUN_00698300()
{
    ((FUN_00698300_shell*)((char*)this + 8))->_ref_006815c0();
    return this;
}

namespace fnv_00698fc0 {
struct FUN_00699630_shell
{
    int FUN_00699630(int, unsigned int*);
};
struct FUN_00698fc0_shell : public FUN_00699630_shell
{
    bool UndoToPosition(int, int);
    bool FUN_00698fc0(int, int);
};
// Looks up an index for a via FUN_00699630 and, if found, forwards it with b to UndoToPosition and returns the result.
// @fnv 0x00698fc0
bool FUN_00698fc0_shell::FUN_00698fc0(int a, int b)
{
    int idx;
    {
        unsigned int tmp;
        idx = FUN_00699630(a, &tmp);
    }
    if (idx == -1)
        return false;
    return UndoToPosition(idx, b);
}
}  // namespace fnv_00698fc0

// Returns the larger of the two unsigned arguments.
// @fnv 0x00699760
unsigned int MaxUnsigned(unsigned int auiValue, unsigned short ausValue)
{
    unsigned int c;
    if (auiValue > ausValue)
        c = auiValue;
    else
        c = ausValue;
    return c;
}

struct S0069afb0
{
    int FUN_0069afb0(unsigned short, int);
};
struct S006997b0
{
    char _pad[0xE0];
    S0069afb0* p;
    int FUN_006997b0(unsigned short, int);
};
// @fnv 0x006997b0
int S006997b0::FUN_006997b0(unsigned short a, int b)
{
    return p->FUN_0069afb0(a, b);
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct ActorAvoidanceDataArray
{
    void FUN_00983720(unsigned int, unsigned int);
};
struct BSXFlags_shell
{
    void ClearFlags(unsigned int);
};
struct S006950d0
{
    NavMeshClosedDoorInfo* GetElement(unsigned int);
};

struct FUN_00699a30_shell
{
    bool FUN_00699a30(unsigned int doorID);
};

// @fnv 0x00699a30
bool FUN_00699a30_shell::FUN_00699a30(unsigned int doorID)
{
    unsigned int i = 0;
    for (; i < ((ArrSI*)((char*)this + 0x68))->GetFlags(); ++i)
    {
        if (((S006950d0*)((char*)this + 0x68))->GetElement(i)->iDoorID == doorID)
        {
            if (((S006950d0*)((char*)this + 0x68))->GetElement(i)->m_usTriangleID < ((NavMesh*)this)->FUN_00558200())
            {
                ((BSXFlags_shell*)((NavMesh*)this)
                     ->GetTriangle(((S006950d0*)((char*)this + 0x68))->GetElement(i)->m_usTriangleID))
                    ->ClearFlags(0x1000);
            }
            ((ActorAvoidanceDataArray*)((char*)this + 0x68))->FUN_00983720(i, 1);
            --i;
        }
    }
    return true;
}

struct FUN_0069b2f0
{
    int _d[4];
    ~FUN_0069b2f0();
};
struct FUN_0069a7d0
{
    int _pad[2];
    FUN_0069b2f0 m1;
    FUN_0069b2f0 m2;
    ~FUN_0069a7d0();
};
// Destructor for the object; it destroys the two embedded members and returns.
// @fnv 0x0069a7d0
FUN_0069a7d0::~FUN_0069a7d0()
{}

namespace fnv_0069a940 {
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);

struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};

struct GlobalObject_00869f00
{
    void Clear(bool);
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;
};

struct FUN_0069a940_shell : NavMesh
{
    unsigned int FUN_0069a940(unsigned short, GlobalObject_00869f00*);
};

// Clears object, then for each of the triangle's three vertices appends it to object's array if found in the tri list, returning the count.
// @fnv 0x0069a940
unsigned int FUN_0069a940_shell::FUN_0069a940(unsigned short triangle, GlobalObject_00869f00* object)
{
    object->Clear(false);
    unsigned int count4 = 0;
    NavMeshTriangle* navMeshTriangle = GetTriangle(triangle);
    for (int i3 = 0; i3 < 3; ++i3)
    {
        unsigned short vertex3 = navMeshTriangle->FUN_005582d0(i3);
        if (((NavMeshTriList*)((char*)this + 0xe4))->FindMatchingIndex(vertex3, 0, AreWideCharsEqual) != -1)
        {
            object->m_kAdditionalIndexList.ReserveIndex(vertex3);
            ++count4;
        }
    }
    return count4;
}
}  // namespace fnv_0069a940

class SoundPlaybackHandle;
template <> class NiTPointerMap<unsigned int, SoundPlaybackHandle*>
{
  public:
    bool IsEmpty();
};
struct FUN_0069b0a0_shell
{
    void LookupValue(unsigned short, unsigned int);
};
struct FUN_0069a9d0_shell : NavMesh
{
    void FUN_0069a9d0(unsigned short, unsigned int);
};
// @fnv 0x0069a9d0
void FUN_0069a9d0_shell::FUN_0069a9d0(unsigned short a1, unsigned int a2)
{
    if (((NiTPointerMap<unsigned int, SoundPlaybackHandle*>*)((char*)this + 0x88))->IsEmpty())
        InitializeNavMeshData();
    ((FUN_0069b0a0_shell*)((char*)this + 0x88))->LookupValue(a1, a2);
}

struct FUN_0069b240_Holder
{
    int field_0;
    unsigned short* field_4;
    unsigned int field_8;
    int FindMatchingIndex(int, unsigned int, bool(__cdecl*)(unsigned short*, int));
};
// Scans field_4 from start to field_8, calling func on each element with a, and returns the first matching index or -1.
// @fnv 0x0069b240
int FUN_0069b240_Holder::FindMatchingIndex(int aiValue, unsigned int start, bool(__cdecl* func)(unsigned short*, int))
{
    unsigned int i;
    for (i = start; i < field_8; ++i)
    {
        if (field_4 && func(field_4 + i, aiValue))
            return (int)i;
    }
    return -1;
}

namespace fnv_006b39a0 {
struct EH
{
    int a;
    int b;
    int c;
    EH& operator=(EH const&);
};
struct C006b39a0
{
    C006b39a0& FUN_006b39a0(C006b39a0 const&);
};
// Copies the first field, an EH at offset 8, and three ints at offsets 0x14, 0x18 and 0x1c from rhs into this, returning *this.
// @fnv 0x006b39a0
C006b39a0& C006b39a0::FUN_006b39a0(C006b39a0 const& rhs)
{
    *(TwoIntRecord*)this = *(TwoIntRecord*)&rhs;
    *(EH*)((char*)this + 8) = *(EH*)((char*)&rhs + 8);
    *(int*)((char*)this + 0x14) = *(int*)((char*)&rhs + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)((char*)&rhs + 0x18);
    *(int*)((char*)this + 0x1c) = *(int*)((char*)&rhs + 0x1c);
    return *this;
}
}  // namespace fnv_006b39a0

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct FindTriangleForLocationFilter;
struct NavMeshPtr;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    bool GetAllMeshesReachable();
    void* __vecDelDtor(unsigned int);
    NiPoint3 Location;
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];
struct FUN_006dcee0_shell : public NavMesh
{
    bool FUN_006dcee0(void*, FindTriangleForLocationFilter*);
};

extern int DAT_0102583c;
struct Sub6815c0
{
    void _ref_006815c0();
};
struct FUN_006dcee0_t
{
    int* vfptr;
    Sub6815c0 s;
    FUN_006dcee0_t* FUN_006dcee0(void*, TESObjectCELL*, TESWorldSpace*);
};
// @fnv 0x006dcee0
FUN_006dcee0_t* FUN_006dcee0_t::FUN_006dcee0(void* a1, TESObjectCELL* apCell, TESWorldSpace* apWorldspace)
{
    vfptr = &DAT_0102583c;
    s._ref_006815c0();
    ((PathingLocation*)this)->SetLocationData(a1, apCell, apWorldspace);
    return this;
}

struct S696500
{
    int m0;
    char _pad[32];
    BSSimpleArray<unsigned short, 1024>* m24;
    void FUN_00696500(unsigned short, int, int);
};
// Computes index as c * m0 + b and calls the array element's method with a.
// @fnv 0x00696500
void S696500::FUN_00696500(unsigned short ausValue, int b, int c)
{
    int index = c * m0 + b;
    m24[index].ReserveIndex(ausValue);
}

struct Sub0069d4b0
{
    void __thiscall FUN_0069d4b0(int a, int b, int c);
};
struct Obj00696c00
{
    char _pad[0xA8];
    Sub0069d4b0 sub;
    void __thiscall ForwardToSub(int a, int b, int c);
};
// Calls FUN_0069d4b0 on the sub object at offset 0xA8, passing the three arguments through.
// @fnv 0x00696c00
void __thiscall Obj00696c00::ForwardToSub(int aiArg1, int aiArg2, int aiArg3)
{
    sub.FUN_0069d4b0(aiArg1, aiArg2, aiArg3);
}

struct S50
{
    char _pad[0x50];
    int f50;
    void AssignFrom(S50* p);
    S50* FUN_00696c30(S50* p);
};
// Calls AssignFrom on p, copies p->f50 into this->f50, and returns this.
// @fnv 0x00696c30
S50* S50::FUN_00696c30(S50* apSource)
{
    AssignFrom(apSource);
    f50 = apSource->f50;
    return this;
}

struct MidCopy
{
    char _pad[32];
    struct Inner
    {
        unsigned int d[8];
    } inner;
    unsigned int tail;
    MidCopy& FUN_00696ca0(const MidCopy&);
    MidCopy& AssignFrom(const MidCopy&);
};
// @fnv 0x00696c60
MidCopy& MidCopy::AssignFrom(const MidCopy& other)
{
    FUN_00696ca0(other);
    inner = other.inner;
    tail = other.tail;
    return *this;
}

extern void* DAT_0106b1f4;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_0069b360_shell
{
    void* __thiscall ConstructBuffer(unsigned int a);
};

// @fnv 0x0069b360
void* __thiscall FUN_0069b360_shell::ConstructBuffer(unsigned int a)
{
    *(void**)this = &DAT_0106b1f4;
    *(unsigned int*)((char*)this + 4) = a;
    *(unsigned int*)((char*)this + 0xc) = 0;
    unsigned int uiSize = *(unsigned int*)((char*)this + 4) * 4;
    *(void**)((char*)this + 8) = _NiMalloc(uiSize);
    memset(*(void**)((char*)this + 8), 0, *(unsigned int*)((char*)this + 4) * 4);
    return this;
}

namespace fnv_00697810 {
struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct FUN_00697810_t;
struct NavCallback_00697810
{
    virtual bool Test(const NiPoint3&, NavMesh*, unsigned short, B006815c0&);
};
struct FUN_00697810_t : public NavMesh
{
    bool TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                             NavCallback_00697810* apCallback);
};
// Tests arPoint against triangle ausTri, computes arZ, and if a callback is given calls its Test with the point raised by arZ.
// @fnv 0x00697810
bool FUN_00697810_t::TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                                         NavCallback_00697810* apCallback)
{
    if (!apCallback)
        return FindHeightOnTriangle(ausTri, arPoint, arZ, 3.4028234663852886e+38f, 3.4028234663852886e+38f);
    B006815c0 v1;
    bool bResult;
    {
        B006815c0 v0;
        B006815c0 v2;
        NavMeshTriangle* ptri = GetTriangle(ausTri);
        v1 = *(const B006815c0*)&FUN_0068f0a0(ptri->FUN_005582d0(0));
        v0 = *(const B006815c0*)&FUN_0068f0a0(ptri->FUN_005582d0(1));
        v2 = *(const B006815c0*)&FUN_0068f0a0(ptri->FUN_005582d0(2));
        bResult = FUN_006b9cf0(*(const NiPoint3*)&v1, *(const NiPoint3*)&v0, *(const NiPoint3*)&v2, arPoint, arZ,
                               3.4028234663852886e+38f, 3.4028234663852886e+38f);
    }
    if (bResult && apCallback)
    {
        B006815c0 p = *(const B006815c0*)&arPoint;
        p.z += arZ;
        return apCallback->Test(arPoint, this, ausTri, p);
    }
    else
    {
        return bResult;
    }
}
}  // namespace fnv_00697810

struct FUN_00697980_t : public NavMesh
{
    bool GetTriangleHeightAtPoint(unsigned short ausTriangle, const NiPoint3& arPoint, float afAbove, float afBelow,
                                  float* apfZ);
};

// Tests whether arPoint lies inside triangle ausTriangle in XY, writes the interpolated Z to apfZ, and checks the Z offset against afAbove/afBelow.
// @fnv 0x00697980
bool FUN_00697980_t::GetTriangleHeightAtPoint(unsigned short ausTriangle, const NiPoint3& arPoint, float afAbove,
                                              float afBelow, float* apfHeight)
{
    float fY0;
    {
        float fY2;
        {
            const NiPoint3* pVertex0;
            {
                float fWeight0;
                {
                    float fInvDet;
                    {
                        float fWeight1;
                        {
                            float fDZ;
                            {
                                float fC;
                                {
                                    float fDet;
                                    {
                                        float fX0;
                                        {
                                            const NiPoint3* pVertex2;
                                            {
                                                float fX2;
                                                {
                                                    float fX1;
                                                    {
                                                        float fY1;
                                                        {
                                                            NavMeshTriangle* pTri;
                                                            {
                                                                const NiPoint3* pVertex1;
                                                                pTri = GetTriangle(ausTriangle);
                                                                pVertex0 = &FUN_0068f0a0(pTri->FUN_005582d0(0));
                                                                pVertex1 = &FUN_0068f0a0(pTri->FUN_005582d0(1));
                                                                pVertex2 = &FUN_0068f0a0(pTri->FUN_005582d0(2));
                                                                fDet = (pVertex1->x - pVertex0->x) *
                                                                           (pVertex2->y - pVertex0->y) -
                                                                       (pVertex2->x - pVertex0->x) *
                                                                           (pVertex1->y - pVertex0->y);
                                                                if (fDet == 0.0)
                                                                    return false;
                                                                fX1 = pVertex1->x - arPoint.x;
                                                                fX2 = pVertex2->x - arPoint.x;
                                                                fY1 = pVertex1->y - arPoint.y;
                                                                fY2 = pVertex2->y - arPoint.y;
                                                                fInvDet = 1.0f / fDet;
                                                                fWeight0 = (fX1 * fY2 - fX2 * fY1) * fInvDet;
                                                                if (fWeight0 < 0.0)
                                                                    return false;
                                                                fX0 = pVertex0->x - arPoint.x;
                                                                fY0 = pVertex0->y - arPoint.y;
                                                                fWeight1 = (fX2 * fY0 - fX0 * fY2) * fInvDet;
                                                                if (fWeight1 < 0.0)
                                                                    return false;
                                                                fC = (fX0 * fY1 - fX1 * fY0) * fInvDet;
                                                                if (fC < 0.0)
                                                                    return false;
                                                                *apfHeight = fWeight0 * pVertex0->z +
                                                                             fWeight1 * pVertex1->z + fC * pVertex2->z;
                                                                fDZ = arPoint.z - *apfHeight;
                                                                if (fDZ > afAbove)
                                                                    return false;
                                                                else if (-afBelow > fDZ)
                                                                    return false;
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern double DAT_01011588;
namespace NavCircum {
struct NiPoint3
{
    float x, y, z;
    void Set(float, float, float);
};
}
// Computes the circumcenter of the triangle's three vertices in the XY plane and returns it with Z set to the highest vertex Z.
// @fnv 0x00697290
NiPoint3 NavMesh::FUN_00697290(unsigned short apTriangle)
{
    float xdo;
    float a2;
    NavCircum::NiPoint3 circumcenter;
    NavCircum::NiPoint3 p1;
    float denominator;
    NavCircum::NiPoint3 p2;
    float ydo;
    float xao;
    float b2;
    NavCircum::NiPoint3 p0;
    float yao;
    float numerator;
    float Z;
    p0 = *(const NavCircum::NiPoint3*)&FUN_0068f0a0(GetTriangle(apTriangle)->FUN_005582d0(0));
    p1 = *(const NavCircum::NiPoint3*)&FUN_0068f0a0(GetTriangle(apTriangle)->FUN_005582d0(1));
    p2 = *(const NavCircum::NiPoint3*)&FUN_0068f0a0(GetTriangle(apTriangle)->FUN_005582d0(2));
    xdo = p1.x - p0.x;
    ydo = p1.y - p0.y;
    xao = p2.x - p0.x;
    yao = p2.y - p0.y;
    a2 = xdo * xdo + ydo * ydo;
    b2 = xao * xao + yao * yao;
    numerator = xdo * yao - xao * ydo;
    denominator = DAT_01011588 / numerator;
    Z = p2.z;
    if (p0.z >= p1.z && p0.z >= p2.z)
        Z = p0.z;
    else if (p1.z >= p2.z)
        Z = p1.z;
    circumcenter.Set(p0.x - (ydo * b2 - yao * a2) * denominator, (xdo * b2 - xao * a2) * denominator + p0.y, Z);
    return *(NiPoint3*)&circumcenter;
}

struct FUN_00698320_t : public NavMesh
{
    int FindCrossedEdge(unsigned short, int, const NiPoint3*, const NiPoint3*);
};

// Tests each triangle edge except aIgnoreEdge for intersection with the segment aStartPoint-aEndPoint and returns the first crossing edge index, or -1.
// @fnv 0x00698320
int FUN_00698320_t::FindCrossedEdge(unsigned short ausTri, int aIgnoreEdge, const NiPoint3* aStartPoint,
                                    const NiPoint3* aEndPoint)
{
    NiPoint3 edgeVerts[3];
    NavMeshTriangle* ptri = GetTriangle(ausTri);
    edgeVerts[0] = FUN_0068f0a0(ptri->FUN_005582d0(0));
    edgeVerts[1] = FUN_0068f0a0(ptri->FUN_005582d0(1));
    edgeVerts[2] = FUN_0068f0a0(ptri->FUN_005582d0(2));
    for (int i = 0; i < 3; i++)
    {
        if (i == aIgnoreEdge)
            continue;
        int j = i + 1;
        if (j == 3)
            j = 0;
        float fa1 = (edgeVerts[i].x - aEndPoint->x) * (edgeVerts[j].y - aEndPoint->y) -
                    (edgeVerts[i].y - aEndPoint->y) * (edgeVerts[j].x - aEndPoint->x);
        float fa2 = (edgeVerts[i].x - aStartPoint->x) * (edgeVerts[j].y - aStartPoint->y) -
                    (edgeVerts[i].y - aStartPoint->y) * (edgeVerts[j].x - aStartPoint->x);
        float fa3 = (aStartPoint->x - edgeVerts[i].x) * (aEndPoint->y - edgeVerts[i].y) -
                    (aStartPoint->y - edgeVerts[i].y) * (aEndPoint->x - edgeVerts[i].x);
        float fa4 = (aStartPoint->x - edgeVerts[j].x) * (aEndPoint->y - edgeVerts[j].y) -
                    (aStartPoint->y - edgeVerts[j].y) * (aEndPoint->x - edgeVerts[j].x);
        if (fa1 * fa2 <= 0.0 && fa3 * fa4 <= 0.0)
        {
            if (fa1 == 0.0)
                continue;
            if (fa4 == 0.0)
                continue;
            return i;
        }
    }
    return -1;
}

namespace fnv_0069a830 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int);
};
struct FUN_0069b0a0_shell
{
    bool LookupValue(unsigned short, unsigned int);
};
namespace S {
struct NiTPointerMap
{
    bool IsEmpty();
};
}
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0069a830_shell : NavMesh
{
    int CollectTrianglePOVs(unsigned short triangle, BSSimpleArray<unsigned short, 1024>* povs);
};

// @fnv 0x0069a830
int FUN_0069a830_shell::CollectTrianglePOVs(unsigned short triangle, BSSimpleArray<unsigned short, 1024>* povs)
{
    if (((S::NiTPointerMap*)&POVPointerArray)->IsEmpty())
        InitializeNavMeshData();
    ((GlobalObject_00869f00*)povs)->Clear(false);
    int iAddedCount = 0;
    NavMeshTriangle* pNavTriangle = GetTriangle(triangle);
    for (int i = 0; i < 3; i++)
    {
        unsigned short m_usVertexId = pNavTriangle->FUN_005582d0(i);
        unsigned int uiPOV;
        if (((FUN_0069b0a0_shell*)&POVPointerArray)->LookupValue(m_usVertexId, (unsigned int)&uiPOV))
        {
            povs->ReserveIndex(m_usVertexId);
            iAddedCount++;
        }
    }
    if (triangle < ((ArrSI*)&m_kAdditionalIndexList)->GetFlags() &&
        ((DA00694f80*)&m_kAdditionalIndexList)->GetAt(triangle) != 0xFFFF)
    {
        povs->ReserveIndex(((DA00694f80*)&m_kAdditionalIndexList)->GetAt(triangle));
        iAddedCount++;
    }
    return iAddedCount;
}
}  // namespace fnv_0069a830

struct Helper62d0
{
    void* operator=(const void*);
};

struct FUN_0069afb0_shell
{
    virtual void v0();
    virtual void* v1(unsigned short a);
    virtual bool v2(unsigned short a, unsigned short b);
    void* p;
    void** list;
    bool FUN_0069afb0(unsigned short a, Helper62d0& out);
};

// @fnv 0x0069afb0
bool FUN_0069afb0_shell::FUN_0069afb0(unsigned short a, Helper62d0& out)
{
    void* item = v1(a);
    void* node = list[*(unsigned int*)&item];
    while (node)
    {
        if (v2(a, *(unsigned short*)((char*)node + 4)))
        {
            out = (const char*)node + 8;
            return true;
        }
        node = *(void**)node;
    }
    return false;
}

namespace fnv_006be6f0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int i);
};
struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
    void FUN_0069add0(int, bool);
};
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);
struct FUN_006be6f0_shell
{
    void MarkNavMeshTriangles();
};
// @fnv 0x006be6f0
void FUN_006be6f0_shell::MarkNavMeshTriangles()
{
    for (unsigned int i = 0; i < ((ArrSI*)((char*)*(unsigned int**)((char*)this + 8) + 0x60))->GetFlags(); i++)
    {
        int idx = ((NavMeshTriList*)((char*)*(unsigned int**)((char*)this + 0) + 0xe4))
                      ->FindMatchingIndex(((DA00694f80*)((char*)*(unsigned int**)((char*)this + 8) + 0x60))->GetAt(i),
                                          0, AreWideCharsEqual);
        if (idx != -1)
            ((NavMeshTriList*)((char*)*(unsigned int**)((char*)this + 0) + 0xe4))->FUN_0069add0(idx, true);
    }
}
}  // namespace fnv_006be6f0

namespace fnv_00697590 {
class ArrSI
{
  public:
    unsigned int GetFlags(void);
};

struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};

struct HArr
{
    void GrowCapacity(unsigned int);
};

struct BSSimpleArrayActor
{
    unsigned int Add(void*&);
};

struct FUN_00690e10_shell
{
    bool FUN_00690e10(void);
};

struct FUN_00693d30_shell
{
    char* GetEdge(unsigned short);
};

struct FUN_00697590_shell
{
    bool CollectTrianglesForDoor(unsigned int, BSSimpleArrayActor*);
};

// Clears the array, then adds each triangle index that has an edge whose linked door ID equals doorID, and returns whether any were added.
// @fnv 0x00697590
bool FUN_00697590_shell::CollectTrianglesForDoor(unsigned int doorID, BSSimpleArrayActor* array)
{
    reinterpret_cast<_Mem_20a4*>(array)->SetSize(0, true);
    reinterpret_cast<HArr*>(array)->GrowCapacity(100);

    for (unsigned int triangleIndex = 0;
         triangleIndex < reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetFlags();
         ++triangleIndex)
    {
        NavMeshTriangle* triangle =
            reinterpret_cast<NavMesh*>(this)->GetTriangle(static_cast<unsigned short>(triangleIndex));

        if (reinterpret_cast<FUN_00690e10_shell*>(triangle)->FUN_00690e10())
        {
            for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex)
            {
                if (triangle->IsEdgeFlagSet(edgeIndex))
                {
                    if (reinterpret_cast<unsigned int*>(reinterpret_cast<FUN_00693d30_shell*>(this)->GetEdge(
                            triangle->FUN_0068f2c0(edgeIndex)))[1] == doorID)
                    {
                        void* value;
                        value = reinterpret_cast<void*>(triangleIndex);
                        array->Add(value);
                        break;
                    }
                }
            }
        }
    }

    return 0 < reinterpret_cast<ArrSI*>(array)->GetFlags();
}
}  // namespace fnv_00697590

namespace fnv_006995c0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GO
{
    operator unsigned int() const;
};
struct NiPointerStandIn
{
    bool operator==(void*) const;
};

struct FUN_006995c0_shell
{
    int FindEntryIndex(void* arg);
};

// Scans the array at offset 0xd0 and returns the index whose entry pointer at offset 0xc equals arg, or -1 if none matches.
// @fnv 0x006995c0
int FUN_006995c0_shell::FindEntryIndex(void* apTarget)
{
    unsigned int i = 0;
    for (; i < ((ArrSI*)((char*)this + 0xd0))->GetFlags(); ++i)
    {
        if (((NiPointerStandIn*)(((GO*)((char*)((Arr*)((char*)this + 0xd0))->GetAt(i)))->operator unsigned int() + 0xc))
                ->
                operator==(apTarget))
            return i;
    }
    return -1;
}
}  // namespace fnv_006995c0

namespace fnv_006bbb80 {
extern int _data_011c16bc;

struct GO
{
    int value;

    GO(int);
    ~GO();
};

struct FUN_006bbc30
{
    int padding[4];

    FUN_006bbc30();
    ~FUN_006bbc30();

    int _ref_006815c0();
};

struct FUN_006bf7d0
{
    int padding[5];

    FUN_006bf7d0(int, int, int);
    ~FUN_006bf7d0();
};

struct FUN_006bfa10
{
    int padding[5];

    FUN_006bfa10(int, int, int);
};

struct FUN_006bbb80
{
    int base;
    GO go;
    int gap;
    FUN_006bbc30 memberC;
    FUN_006bf7d0 member1C;
    FUN_006bfa10 member30;

    FUN_006bbb80();
};

// Initializes the object's members, constructing go with 0 and member1C and member30 with 0x100, 0, and the result of memberC._ref_006815c0().
// @fnv 0x006bbb80
FUN_006bbb80::FUN_006bbb80()
    : go(0), memberC(), member1C(0x100, 0, memberC._ref_006815c0()), member30(0x100, 0, memberC._ref_006815c0())
{}
}  // namespace fnv_006bbb80

struct SwapTriangle : NavMeshTriangle
{
    void SetArrayElement(int edge, unsigned short vertex);
    void SetSlotValue(int edge, unsigned short neighbor);
    void SetArrayValue(int edge, unsigned short neighbor);
    bool FUN_006957d0();
    void GetPackedFlags(int edge, unsigned short*, unsigned char*, unsigned char*);
    void SetPackedField(int edge, unsigned short, unsigned char, unsigned char);
};

struct SwapMesh
{
    SwapTriangle* FUN_005582f0(unsigned short triangle);
    void SwapTriangleEdges(unsigned short triangle);
};

// @fnv 0x00695660
void SwapMesh::SwapTriangleEdges(unsigned short triangle)
{
    SwapTriangle* tri5 = FUN_005582f0(triangle);
    unsigned short vertex8 = tri5->FUN_005582d0(1);
    tri5->SetArrayElement(1, tri5->FUN_005582d0(0));
    tri5->SetArrayElement(0, vertex8);
    bool firstExternal3 = tri5->IsEdgeFlagSet(0);
    bool secondExternalX = tri5->IsEdgeFlagSet(1);
    unsigned short neighbor;
    if (secondExternalX)
        neighbor = tri5->FUN_0068f2c0(1);
    else
        neighbor = tri5->FUN_0068f2c0(1);
    if (firstExternal3)
        tri5->SetSlotValue(1, tri5->FUN_0068f2c0(0));
    else
        tri5->SetArrayValue(1, tri5->FUN_0068f2c0(0));
    if (secondExternalX)
        tri5->SetSlotValue(0, neighbor);
    else
        tri5->SetArrayValue(0, neighbor);
    if (tri5->FUN_006957d0())
    {
        unsigned short aFirstLink;
        unsigned short secondLinkB;
        unsigned char firstEdge8;
        unsigned char secondEdge9;
        unsigned char firstFlags;
        unsigned char secondFlags;
        tri5->GetPackedFlags(0, &aFirstLink, &firstEdge8, &firstFlags);
        tri5->GetPackedFlags(1, &secondLinkB, &secondEdge9, &secondFlags);
        tri5->SetPackedField(0, secondLinkB, secondFlags, secondEdge9);
        tri5->SetPackedField(1, aFirstLink, firstFlags, firstEdge8);
    }
}

struct FUN_006957d0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    bool FUN_006957d0();
};

// @fnv 0x006957d0
bool FUN_006957d0_Class::FUN_006957d0()
{
    return 0u < (unk0C & 0xFFF0000);
}

struct TriangleArrayLocal
{
    bool FUN_0076b610();
};
struct Candidate
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    TriangleArrayLocal triangles;
    NavMeshTriangle* FUN_005582f0(unsigned short);
    const NiPoint3& FUN_0068f0a0(unsigned short);
    unsigned int FUN_00558200();
    void ComputeBounds(NiPoint3& outMin, NiPoint3& outMax);
};
// @fnv 0x006957f0
void Candidate::ComputeBounds(NiPoint3& outMin, NiPoint3& outMax)
{
    if (triangles.FUN_0076b610())
        return;
    NiPoint3 kMinimum;
    NiPoint3 _maximum;
    NiPoint3 _point;
    NavMeshTriangle* triangle5 = FUN_005582f0(0);
    _maximum = FUN_0068f0a0(triangle5->FUN_005582d0(0));
    kMinimum = _maximum;
    for (unsigned int i = 0; i < FUN_00558200(); ++i)
    {
        triangle5 = FUN_005582f0(static_cast<unsigned short>(i));
        for (int j = 0; j < 3; ++j)
        {
            _point = FUN_0068f0a0(triangle5->FUN_005582d0(j));
            if (_point.x < kMinimum.x)
                kMinimum.x = _point.x;
            else if (_point.x > _maximum.x)
                _maximum.x = _point.x;
            if (_point.y < kMinimum.y)
                kMinimum.y = _point.y;
            else if (_point.y > _maximum.y)
                _maximum.y = _point.y;
            if (_point.z < kMinimum.z)
                kMinimum.z = _point.z;
            else if (_point.z > _maximum.z)
                _maximum.z = _point.z;
        }
    }
    outMin = kMinimum;
    outMax = _maximum;
}

class Pt3
{
  public:
    float x, y, z;
    Pt3 operator+(const Pt3&) const;
    Pt3 operator*(float) const;
    Pt3 operator-(const Pt3&) const;
    float GetSquaredXYLength() const;
};

struct NavEdgeVerts
{
    const Pt3* first;
    const Pt3* second;
};

class NavTri
{
  public:
    bool IsEdgeSet(int aiEdge);
};

class NavTriArray
{
  public:
    unsigned int GetFlags();
};

class NavMeshA
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
    NavTriArray Triangles;
    NavTri* GetTriangle(unsigned short);
    NavEdgeVerts FUN_0068f040(unsigned short, int);
    bool FUN_00697010(const Pt3& arPoint, float afRadius, unsigned short* apTri, int* apEdge, bool abFlip);
};

// @fnv 0x00697010
bool NavMeshA::FUN_00697010(const Pt3& arPoint, float afRadius, unsigned short* apTri, int* apEdge, bool abFlip)
{
    unsigned short usBestTri5 = 0;
    int iBestEdge = -1;
    float fBest2 = 3.402823466e+38f;
    float fRadiusSq2 = afRadius * afRadius;
    float fMinZ8 = arPoint.z - 64.0;
    float fMaxZ7 = arPoint.z + 180.0;
    if (abFlip)
    {
        fMinZ8 = arPoint.z - 180.0;
        fMaxZ7 = arPoint.z + 64.0;
    }
    unsigned int uiCount5 = Triangles.GetFlags();
    for (unsigned int i5 = 0; i5 < uiCount5; i5++)
    {
        NavTri* pTri_ = GetTriangle((unsigned short)i5);
        for (int jTmp = 0; jTmp < 3; jTmp++)
        {
            if (!pTri_->IsEdgeSet(jTmp))
            {
                NavEdgeVerts verts8 = FUN_0068f040((unsigned short)i5, jTmp);
                Pt3 mid3 = (*verts8.first + *verts8.second) * 0.5f;
                Pt3 diff = mid3 - arPoint;
                float fDist2D = diff.GetSquaredXYLength();
                float fDZ = diff.z * diff.z;
                float fDist_2 = fDist2D + fDZ;
                if (fDist2D < fBest2 && ((mid3.z < fMaxZ7 && mid3.z > fMinZ8) || fDist_2 <= fRadiusSq2 - fDZ))
                {
                    usBestTri5 = (unsigned short)i5;
                    iBestEdge = jTmp;
                    fBest2 = fDist_2;
                }
            }
        }
    }
    if (iBestEdge == -1)
        return false;
    *apTri = usBestTri5;
    *apEdge = iBestEdge;
    return true;
}

struct FUN_00697440_t : public NavMesh
{
    void FUN_00697440(unsigned short ausTriangle, NiPoint3* apCenter);
};

// Computes the 2D circumcenter of the triangle's three vertices and writes it into apCenter with z set to 0.
// @fnv 0x00697440
void FUN_00697440_t::FUN_00697440(unsigned short ausTriangle, NiPoint3* apCenter)
{
    NiPoint3 kA = FUN_0068f0a0(GetTriangle(ausTriangle)->FUN_005582d0(0));
    NiPoint3 kB9 = FUN_0068f0a0(GetTriangle(ausTriangle)->FUN_005582d0(1));
    NiPoint3 kC2 = FUN_0068f0a0(GetTriangle(ausTriangle)->FUN_005582d0(2));
    float fDX = kB9.x - kA.x;
    float fB8 = kB9.y - kA.y;
    float fC = kC2.x - kA.x;
    float fCy3 = kC2.y - kA.y;
    float fLenB = fDX * fDX + fB8 * fB8;
    float fLen8 = fC * fC + fCy3 * fCy3;
    float fDenom = fDX * fCy3 - fC * fB8;
    float fScale = 0.5 / fDenom;
    apCenter->x = kA.x - (fB8 * fLen8 - fCy3 * fLenB) * fScale;
    apCenter->y = (fDX * fLen8 - fC * fLenB) * fScale + kA.y;
    apCenter->z = 0.0f;
}

// NavMesh: get the extra info for a triangle edge, creating and linking a fresh record when missing,
// then reset its link fields.

struct D76A0EdgeExtraInfo
{
    int m_iType;
    void* m_pkPortal;
    unsigned short m_usLinkedTriangle;
    D76A0EdgeExtraInfo();
};

struct D76A0Triangle
{
    void SetEdgeExtraInfo(int m_iEdgeNumber, unsigned short usIndex);
};

struct D76A0TriangleArray
{
    D76A0Triangle& GetAt(int iIndex) const;
};

class D76A0NavMesh
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
    D76A0TriangleArray m_kTriangles;

    D76A0EdgeExtraInfo* GetEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber);
    unsigned short AddEdgeInfo(const D76A0EdgeExtraInfo& kInfo);
    D76A0EdgeExtraInfo* GetOrCreateEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber);
};

// Returns the edge extra info for a triangle edge, creating it if missing, then clears its portal and linked triangle.
// @fnv 0x006976a0
D76A0EdgeExtraInfo* D76A0NavMesh::GetOrCreateEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber)
{
    D76A0EdgeExtraInfo* pkInfo = GetEdgeInfo(m_usTriangleID, m_iEdgeNumber);
    if (!pkInfo)
    {
        D76A0EdgeExtraInfo kNewInfo;
        m_kTriangles.GetAt(m_usTriangleID).SetEdgeExtraInfo(m_iEdgeNumber, AddEdgeInfo(kNewInfo));
        pkInfo = GetEdgeInfo(m_usTriangleID, m_iEdgeNumber);
    }
    pkInfo->m_pkPortal = 0;
    pkInfo->m_usLinkedTriangle = 0xffff;
    return pkInfo;
}

struct TriangleList
{
    unsigned int FUN_0044ddc0();
    const unsigned short& FUN_0069dec0(unsigned int index);
};
struct TriangleGrid
{
    void GetTriListAtPosition(const NiPoint3& point, TriangleList*& triangles);
};
struct Target : NavMesh
{
    TriangleGrid grid;
    bool GetTriangleHeightAtPoint(unsigned short triangle, const NiPoint3& point, float above, float below, float* z);
    bool FindTriangleZ(const NiPoint3& point, float above, float below, float* z);
};
// Looks up the triangle list at point, tests each triangle with GetTriangleHeightAtPoint, and returns true on the first hit, writing z.
// @fnv 0x00697b70
bool Target::FindTriangleZ(const NiPoint3& point, float above, float below, float* z)
{
    TriangleList* triangles = 0;
    grid.GetTriListAtPosition(point, triangles);
    if (!triangles)
        return false;
    unsigned int count = triangles->FUN_0044ddc0();
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned short triangle = triangles->FUN_0069dec0(index);
        if (GetTriangleHeightAtPoint(triangle, point, above, below, z))
            return true;
    }
    return false;
}

struct FUN_006986d0_cls;

void* __cdecl FormHeap_Allocate(unsigned int size);

struct b9_big
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58;
    static void* operator new(unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
    static void operator delete(void*, unsigned int);
    b9_big();
    void InitializeFromMeshSource(FUN_006986d0_cls* o);
    void SetField54(FUN_006986d0_cls* o);
};

struct b9_nav
{
    b9_nav* FUN_00693d70();
    void InitializeFromMeshSource(FUN_006986d0_cls* o);
    void RegisterNavMeshInfo();
};

struct b9_tab
{
    b9_nav* FUN_0045af00(void* p);
};

extern int DAT_011dea10;

struct FUN_006986d0_cls
{
    void* FUN_0084e3a0();
    int FUN_0068efb0();
    void FUN_006d3100(b9_big* p);
    bool FUN_006986d0();
};

// @fnv 0x006986d0
bool FUN_006986d0_cls::FUN_006986d0()
{
    b9_nav* r = ((b9_tab*)DAT_011dea10)->FUN_0045af00(this->FUN_0084e3a0())->FUN_00693d70();
    if (this->FUN_0068efb0() == 0)
    {
        b9_big* q = new b9_big();
        q->InitializeFromMeshSource(this);
        this->FUN_006d3100(q);
        q->SetField54(this);
        ((b9_tab*)DAT_011dea10)->FUN_0045af00(q)->RegisterNavMeshInfo();
        return true;
    }
    else
    {
        r->InitializeFromMeshSource(this);
        return false;
    }
}

struct SearchContext
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
    SearchContext();
    ~SearchContext();
    bool FUN_006bbd30(void* owner, int first, int second);
};
struct NavMeshSearch
{
    bool Search(int first, int second);
};
// Builds a SearchContext and forwards the two ints and this to SearchContext::FUN_006bbd30, returning its result.
// @fnv 0x00698f40
bool NavMeshSearch::Search(int first, int second)
{
    SearchContext searchContext;
    bool result = searchContext.FUN_006bbd30(this, first, second);
    return result;
}

struct FUN_006993c0_sub
{
    int unk00, unk04, unk08, unk0c;
    ~FUN_006993c0_sub();
};

struct FUN_006993c0_local
{
    FUN_006993c0_sub a;
    FUN_006993c0_sub b;
    FUN_006993c0_local();
    ~FUN_006993c0_local();
};

struct Dummy0044ddc0_sub
{
    int FUN_0044ddc0();
};

struct FUN_006993c0_cls
{
    unsigned char unk00[0xd0];
    Dummy0044ddc0_sub unkD0;

    void UndoToPosition(int aiIndex, FUN_006993c0_local* apLocal);
    void FUN_006993c0();
};

// Iterates indices from unkD0.FUN_0044ddc0() - 1 down to 0, calling UndoToPosition with each index and a local object.
// @fnv 0x006993c0
void FUN_006993c0_cls::FUN_006993c0()
{
    FUN_006993c0_local local;
    for (int i = unkD0.FUN_0044ddc0() - 1; i != -1; i--)
    {
        UndoToPosition(i, &local);
    }
}

unsigned int __cdecl MaxUnsigned(unsigned int uiHash, unsigned short usValue);

class B99690Triangle
{
  public:
    unsigned short GetBits13To15();
};

class B99690IndexArray
{
  public:
    unsigned int GetSize();
    unsigned short& GetAt(int iIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Edge
{
    unsigned short m_usTriangle;
};

class B99690EdgeArray
{
  public:
    unsigned int GetSize();
    B99690Edge* GetAt(unsigned int uiIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B99690IndexArray m_kTriangles;
    B99690EdgeArray m_kEdges;
};

class B99690NavMesh
{
  public:
    B99690Triangle* GetTriangle(unsigned short usIndex);
    unsigned int ComputeTriangleHash(B99690Info* pkInfo);
};

// Hashes the triangle values of all triangles and edge triangles referenced by pkInfo and returns the accumulated hash.
// @fnv 0x00699690
unsigned int B99690NavMesh::ComputeTriangleHash(B99690Info* pkInfo)
{
    unsigned int uiHash = 0;
    for (unsigned int i = 0; i < pkInfo->m_kTriangles.GetSize(); i++)
        uiHash = MaxUnsigned(uiHash, GetTriangle(pkInfo->m_kTriangles.GetAt(i))->GetBits13To15());
    for (unsigned int j = 0; j < pkInfo->m_kEdges.GetSize(); j++)
        uiHash = MaxUnsigned(uiHash, GetTriangle(pkInfo->m_kEdges.GetAt(j)->m_usTriangle)->GetBits13To15());
    return uiHash;
}

struct FUN_0069b0a0_item
{
    FUN_0069b0a0_item* next;
    unsigned short key;
    unsigned char pad[2];
    unsigned int val;
};
struct U4v
{
    unsigned int v;
};
class FUN_0069b0a0_cls
{
  public:
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeyEqual(unsigned short a, unsigned short b);
    unsigned int m_uiHashSize;
    FUN_0069b0a0_item** m_ppkHashTable;
    unsigned int m_uiCount;
    bool LookupValue(unsigned short key, unsigned int* out);
};
// Hashes key, walks the bucket chain comparing keys, and on a match copies the item's value to out and returns true; otherwise returns false.
// @fnv 0x0069b0a0
bool FUN_0069b0a0_cls::LookupValue(unsigned short key, unsigned int* puiOut)
{
    unsigned int uiBucketIndex = KeyToHashIndex(key);
    FUN_0069b0a0_item* pItem = m_ppkHashTable[uiBucketIndex];
    while (pItem != 0)
    {
        if (IsKeyEqual(key, pItem->key))
        {
            *(U4v*)puiOut = *(U4v*)((char*)pItem + 6);
            return true;
        }
        pItem = pItem->next;
    }
    return false;
}

struct ItemResource
{
    void FUN_00401970();
};

struct ResourceHolder
{
    ItemResource* FUN_00559450();
};

struct Item
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    ResourceHolder resource;
};

struct ItemPointer
{
    Item* item;
};

struct FUN_0045cec0
{
    int first;
    int second;
    ~FUN_0045cec0();
};

struct FUN_00982610
{
    int first;
    int second;
    int third;
    int fourth;
    ~FUN_00982610();
};

struct FUN_006bf890
{
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    ~FUN_006bf890();
};

struct FUN_006bfad0
{
    ItemPointer* entries;
    unsigned int count;
    unsigned int capacity;
    unsigned int flags;

    unsigned int FUN_0044ddc0();
    ItemPointer* FUN_00877a30(unsigned int index);
    ~FUN_006bfad0();
};

struct FUN_006bbc50
{
    int identifier;
    FUN_0045cec0 first;
    FUN_00982610 second;
    FUN_006bf890 third;
    FUN_006bfad0 fourth;
    ~FUN_006bbc50();
};

// Iterates the fourth container's entries and calls FUN_00401970 on each item's resource when FUN_00559450 returns non-null.
// @fnv 0x006bbc50
FUN_006bbc50::~FUN_006bbc50()
{
    for (unsigned int i = 0; i < fourth.FUN_0044ddc0(); ++i)
    {
        if (fourth.FUN_00877a30(i)->item->resource.FUN_00559450())
        {
            fourth.FUN_00877a30(i)->item->resource.FUN_00559450()->FUN_00401970();
        }
    }
}

extern const float DAT_0106b158;

struct FUN_006bf220_owner
{
    bool FUN_00697730(unsigned short usIndex, void* apParam, float& afOut, float afX, float afY);
};

struct FUN_006bf220_sub
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    BSSimpleArray<unsigned short> Items;
};

struct FUN_006bf220_cls
{
    FUN_006bf220_owner* m_00;
    int unk04;
    FUN_006bf220_sub* m_08;
    bool FUN_006bf220(void* a1);
};

// @fnv 0x006bf220
bool FUN_006bf220_cls::FUN_006bf220(void* a1)
{
    float local;
    for (unsigned int i = 0; i < m_08->Items.GetSize(); i++)
    {
        if (m_00->FUN_00697730(m_08->Items.GetBufferEntry(i), a1, local, DAT_0106b158, DAT_0106b158))
        {
            return true;
        }
    }
    return false;
}

class TESForm
{
  public:
    virtual void v0();
};
TESForm* __cdecl LookupFormByID(unsigned int);
struct P507Array
{
    void* table;
    void* data;
    unsigned int size, capacity;
    unsigned int FUN_0044ddc0();
    void** FUN_00877a30(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
};
class SA0 : public P507Array
{
  public:
    SA0();
    ~SA0();
};
struct P507Info
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    P507Array first, second;
    unsigned int FUN_00559450();
    bool FUN_00690860(NavMeshPtr&);
};
struct P507Manager
{
    void FUN_006b7910();
};
struct P507Global
{
    P507Manager* FUN_0045af00(SA0*);
};

struct P507Edge
{
    int unk00;
    unsigned int owner;
};
struct P507Mesh
{
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
    virtual void SetChanged(bool);
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
    P507Array edges;
    P507Edge* GetEdge(unsigned short);
    void UpdateTriangleExtraInfo(unsigned short);
};
struct NavMeshPtr
{
    NavMesh* object;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NiPointer<NavMesh>&);
    void* FUN_00458b50();
    P507Mesh* FUN_00559450();
};
// @fnv 0x006953b0
void __cdecl RemoveNavMeshId(unsigned int id)
{
    if (!id)
        return;
    SA0 infos;
    ((P507Global*)DAT_011dea10)->FUN_0045af00(&infos)->FUN_006b7910();
    for (unsigned int i = 0; i < infos.FUN_0044ddc0(); ++i)
    {
        P507Info* firstCount = (P507Info*)*infos.FUN_00877a30(i);
        int info = firstCount->first.FUN_0044ddc0();
        int secondCount = firstCount->second.FUN_0044ddc0();
        for (int j = 0; j < info + secondCount; ++j)
        {
            unsigned int entry;
            if (j < info)
                entry = (unsigned int)*firstCount->first.FUN_00877a30(j);
            else
                entry = (unsigned int)*firstCount->second.FUN_00877a30(j - info);
            if (entry == id)
            {
                NavMeshPtr mesh;
                if (!firstCount->FUN_00690860(mesh))
                {
                    TESForm* nav = LookupFormByID(firstCount->FUN_00559450());
                    NavMesh* form = dynamic_cast<NavMesh*>(nav);
                    mesh = MakeNavMeshPointer(form);
                }
                if (mesh.FUN_00458b50())
                {
                    mesh.FUN_00559450()->SetChanged(true);
                    for (unsigned int k = 0; k < mesh.FUN_00559450()->edges.FUN_0044ddc0(); ++k)
                    {
                        P507Edge* edge = mesh.FUN_00559450()->GetEdge((unsigned short)k);
                        if (edge->owner == id)
                        {
                            mesh.FUN_00559450()->UpdateTriangleExtraInfo((unsigned short)k);
                            --k;
                        }
                    }
                }
                if (j < info)
                {
                    firstCount->first.FUN_006bf8f0(j, true);
                    --info;
                }
                else
                {
                    firstCount->second.FUN_006bf8f0(j - info, true);
                    --secondCount;
                }
                --j;
            }
        }
    }
}

extern const float DAT_01016970;
extern const float DAT_01015f5c;

struct NavMeshTriListAdd
{
    unsigned int Add(const unsigned short& arItem);
};
struct NavMeshGridR
{
    void GetCellCoords(const NiPoint3& arPos, unsigned int& arRow, unsigned int& arCol);
    NavMeshTriListAdd* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
};
struct NiPoint3R : public NiPoint3
{
    NiPoint3R(float afX, float afY, float afZ);
};
struct NavMeshGridOwner : public NavMesh
{
    NavMeshGridR Grid;
    bool AddTrianglesToGrid(unsigned short ausStart, unsigned short ausEnd);
};

// For each triangle index in [ausStart, ausEnd], computes its XY bounds, maps them to grid rows/columns and adds the index to every overlapping cell list.
// @fnv 0x006965d0
bool NavMeshGridOwner::AddTrianglesToGrid(unsigned short ausStart, unsigned short ausEnd)
{
    for (unsigned int i = ausStart; i <= ausEnd; i++)
    {
        NavMeshTriangle* pTri_ = GetTriangle((unsigned short)i);
        NiPoint3R kMinBoundsCur(DAT_01016970, DAT_01016970, 0.0f);
        NiPoint3R kMaxB(DAT_01015f5c, DAT_01015f5c, 0.0f);
        for (int jVal = 0; jVal < 3; jVal++)
        {
            const NiPoint3& _kPt = FUN_0068f0a0(pTri_->FUN_005582d0(jVal));
            if (_kPt.x < kMinBoundsCur.x)
                kMinBoundsCur.x = _kPt.x;
            if (_kPt.x > kMaxB.x)
                kMaxB.x = _kPt.x;
            if (_kPt.y < kMinBoundsCur.y)
                kMinBoundsCur.y = _kPt.y;
            if (_kPt.y > kMaxB.y)
                kMaxB.y = _kPt.y;
        }
        unsigned int uiMinRow = 0;
        unsigned int kUiMinCol = 0;
        unsigned int uiMaxRow = 0;
        unsigned int uiMaxCol3 = 0;
        Grid.GetCellCoords(kMinBoundsCur, uiMinRow, kUiMinCol);
        Grid.GetCellCoords(kMaxB, uiMaxRow, uiMaxCol3);
        for (unsigned int uiRow = uiMinRow; uiRow <= uiMaxRow; uiRow++)
        {
            for (unsigned int uiCol9 = kUiMinCol; uiCol9 <= uiMaxCol3; uiCol9++)
            {
                NavMeshTriListAdd* pList5 = Grid.FUN_006967c0(uiCol9, uiRow);
                if (!pList5)
                    continue;
                pList5->Add((unsigned short)i);
            }
        }
    }
    return true;
}

struct TriList2 : public NavMeshTriList
{
    void FUN_0069add0(int idx, int n);
};
bool __cdecl FUN_0069b2a0(const unsigned short& a, const unsigned short& b);
extern const float DAT_01016970;
struct Ov2 : public NavMeshOverlap
{
    bool FUN_006967f0(unsigned short ausStart, unsigned short ausEnd);
};
// For each triangle index from ausStart to ausEnd, computes its XY bounds, finds the grid cells it spans and marks the triangle in each cell's list.
// @fnv 0x006967f0
bool Ov2::FUN_006967f0(unsigned short ausStart, unsigned short ausEnd)
{
    unsigned int i;
    for (i = ausStart; i <= ausEnd; i++)
    {
        NavMeshTriangle* pTri = GetTriangle((unsigned short)i);
        NiPoint3Ex fStack_14(DAT_01016970, DAT_01016970, 0.0f);
        NiPoint3Ex f(DAT_01015f5c, DAT_01015f5c, 0.0f);
        for (int j = 0; j < 3; j++)
        {
            const NiPoint3* pV = &FUN_0068f0a0(pTri->FUN_005582d0(j));
            if (pV->x < fStack_14.x)
                fStack_14.x = pV->x;
            if (pV->x > f.x)
                f.x = pV->x;
            if (pV->y < fStack_14.y)
                fStack_14.y = pV->y;
            if (pV->y > f.y)
                f.y = pV->y;
        }
        unsigned int j = 0, cf = 0, b = 0, p = 0;
        Grid.GetCellCoords(fStack_14, j, cf);
        Grid.GetCellCoords(f, b, p);
        for (unsigned int r = j; r <= b; r++)
        {
            for (unsigned int c = cf; c <= p; c++)
            {
                int idx;
                TriList2* pList = (TriList2*)Grid.FUN_006967c0(c, r);
                idx = pList->FindMatchingIndex(*(unsigned short*)&i, 0, FUN_0069b2a0);
                pList->FUN_0069add0(idx, 1);
            }
        }
    }
    return true;
}

namespace fnv_00696a50 {
extern float DAT_01016970;
extern const double DAT_010240c0;
struct S006949d0
{
    void* GetAt(int aiIndex);
};
struct FUN_00696a50_Grid
{
    void GetTriListAtPosition(const NiPoint3* apPos, NavMeshTriList** appList);
};
struct FUN_00696a50_HeightSource
{
    void CheckWaterHeight(const NiPoint3* apPos, float* apfHeight);
};
struct FUN_00696a50_View
{
    char pad00[0x24];
    FUN_00696a50_HeightSource* pHeightSource;
    char pad28[0x10];
    S006949d0 kTriangles;
};
struct FUN_00696a50_shell : public NavMesh
{
    FUN_00696a50_Grid kGrid;
    bool TestPointOnTriangle(unsigned short ausTriangle, const NiPoint3* apPos, float* apfDistance, int aiArg);
    unsigned short FUN_00696a50(const NiPoint3* apPos, int aiArg);
};
// @fnv 0x00696a50
unsigned short FUN_00696a50_shell::FUN_00696a50(const NiPoint3* apPos, int aiArg)
{
    NavMeshTriList* pCell = 0;
    kGrid.GetTriListAtPosition(apPos, &pCell);
    unsigned short usBestTmp = 0xffff;
    if (!pCell)
        return 0xffff;
    unsigned int uiEntries = pCell->GetSize();
    float fPointHeight = DAT_01016970;
    float m_fGlyphExtent = DAT_01015f5c;
    if (((FUN_00696a50_View*)this)->pHeightSource)
        ((FUN_00696a50_View*)this)->pHeightSource->CheckWaterHeight(apPos, &m_fGlyphExtent);
    bool bBelowGround = apPos->z < (float)(m_fGlyphExtent + 50.0);
    for (unsigned int i = 0; i < uiEntries; i++)
    {
        unsigned short usTri = pCell->FUN_0069dec0(i);
        if (((NavMeshTriangleEx*)((FUN_00696a50_View*)this)->kTriangles.GetAt(usTri))->GetFlag(0x20))
            continue;
        float fDistance;
        if (TestPointOnTriangle(usTri, apPos, &fDistance, aiArg))
        {
            if (!bBelowGround && fDistance < -180.0)
                continue;
            if (fDistance > DAT_010240c0)
                continue;
            fDistance = std::abs(fDistance);
            if (fDistance < fPointHeight)
            {
                if (fDistance < 40.0)
                    return usTri;
                usBestTmp = usTri;
                fPointHeight = fDistance;
            }
        }
    }
    return usBestTmp;
}
}  // namespace fnv_00696a50

namespace fnv_00696cf0 {
extern float DAT_01016970;
struct TriArr696
{
    void* m_00;
    void* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    NavMeshTriangleEx* FUN_00558dd0(int idx);
    unsigned int FUN_0044ddc0();
};
struct Len696 : public NiPoint3
{
    float FUN_004a7290() const;
};
struct Host696
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34;
    TriArr696 m_38;
    int m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64;
    int m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84;
    int m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    TriangleGrid m_a8;
    bool FUN_00697730(unsigned short tri, void* p, float& out, float afX, float afY);
    NiPoint3 FUN_00558220(unsigned short tri);
    bool FUN_00696cf0(const NiPoint3& point, unsigned short* outTri, bool* outFlag);
};

// @fnv 0x00696cf0
bool Host696::FUN_00696cf0(const NiPoint3& point, unsigned short* outTri, bool* outFlag)
{
    unsigned short d2;
    unsigned short i;
    {
        float bestSq;
        TriangleList* q;
        bestSq = DAT_01016970;
        d2 = 0xffff;
        i = 0xffff;
        q = 0;
        m_a8.GetTriListAtPosition(point, q);
        if (q)
        {
            unsigned int triSq = q->FUN_0044ddc0();
            float bestD = DAT_01016970;
            float f;
            unsigned int e;
            for (e = 0; e < (int)triSq; e++)
            {
                unsigned short pObj = q->FUN_0069dec0(e);
                if (m_38.FUN_00558dd0(pObj)->GetFlag(0x20))
                    continue;
                if (FUN_00697730(pObj, (void*)&point, f, 180.0f, 64.0f))
                {
                    f = std::abs(f);
                    if (f < bestD)
                    {
                        if (f < 40.0)
                        {
                            *outTri = pObj;
                            *outFlag = true;
                            return true;
                        }
                        i = pObj;
                        bestD = f;
                    }
                }
                else
                {
                    NiPoint3 bestD2 = FUN_00558220(pObj) - point;
                    float list = ((Len696*)&bestD2)->FUN_004a7290();
                    if (list < bestSq)
                    {
                        d2 = pObj;
                        bestSq = list;
                    }
                }
            }
            if (i != 0xffff)
            {
                *outTri = i;
                *outFlag = true;
                return true;
            }
        }
        else
        {
            unsigned int nn = m_38.FUN_0044ddc0();
            unsigned int t;
            float n = DAT_01016970;
            float s;
            for (t = 0; t < (int)nn; t++)
            {
                if (FUN_00697730((unsigned short)t, (void*)&point, s, 180.0f, 64.0f))
                {
                    s = std::abs(s);
                    if (s < n)
                    {
                        if (s < 40.0)
                        {
                            *outTri = (unsigned short)t;
                            *outFlag = true;
                            return true;
                        }
                        i = (unsigned short)t;
                        n = s;
                    }
                }
                else
                {
                    NiPoint3 count2 = FUN_00558220((unsigned short)t) - point;
                    float sq2;
                    sq2 = ((Len696*)&count2)->FUN_004a7290();
                    if (sq2 < bestSq)
                    {
                        d2 = (unsigned short)t;
                        bestSq = sq2;
                    }
                }
            }
        }
        if (i != 0xffff)
        {
            *outTri = i;
            *outFlag = true;
            return true;
        }
    }
    if (d2 == 0xffff)
    {
        *outTri = 0xffff;
        *outFlag = false;
        return false;
    }
    *outTri = d2;
    *outFlag = false;
    return true;
}
}  // namespace fnv_00696cf0

struct AdjustPointOps : NiPoint3
{
    void FUN_004a0c10();
    NiPoint3 ApplyScaled(float scale) const;
    NiPoint3& FUN_0063c8a0(const NiPoint3& offset);
};
float __cdecl FUN_006b9940(const NiPoint3& point, const NiPoint3& first, const NiPoint3& second);
struct NavMeshAdjust : FUN_00697670_StandIn
{
    NiPoint3 FUN_006971e0(unsigned short triangle);
    NiPoint3 AdjustPointToNavMesh(const NiPoint3& point, float radius);
};
// @fnv 0x00697d40
NiPoint3 NavMeshAdjust::AdjustPointToNavMesh(const NiPoint3& point, float radius)
{
    NiPoint3 adjusted = point;
    unsigned short triangle = FindTriangleForLocation(point, 0);
    if (triangle != 0xffff)
    {
        unsigned short neighbours[3];
        NavMeshTriangle* triangleData;
        {
            unsigned short count = 0;
            triangleData = GetTriangle(triangle);
            for (int edge = 0; edge < 3; ++edge)
            {
                unsigned short neighbour = 0xffff;
                if (!triangleData->IsEdgeFlagSet(edge))
                    neighbour = triangleData->FUN_0068f2c0(edge);
                if (neighbour != 0xffff)
                {
                    neighbours[count] = neighbour;
                    ++count;
                }
                else
                {
                    NavMeshEdgeVertexPair vertices = FUN_0068f040(triangle, edge);
                    float distance = FUN_006b9940(point, *vertices.first, *vertices.second);
                    if (distance < radius)
                    {
                        NiPoint3 normal = FUN_006971e0(triangle);
                        NiPoint3 direction = normal.Cross(*vertices.first - *vertices.second);
                        ((AdjustPointOps&)direction).FUN_004a0c10();
                        ((AdjustPointOps&)adjusted)
                            .FUN_0063c8a0(((AdjustPointOps&)direction).ApplyScaled(radius - distance));
                    }
                }
            }
            for (unsigned int index = 0; index < count; ++index)
            {
                NavMeshTriangle* triangleData = GetTriangle(neighbours[index]);
                for (int edge = 0; edge < 3; ++edge)
                {
                    if (!triangleData->IsEdgeFlagSet(edge) && triangleData->FUN_0068f2c0(edge) == 0xffff)
                    {
                        NavMeshEdgeVertexPair vertices = FUN_0068f040(neighbours[index], edge);
                        float distance = FUN_006b9940(point, *vertices.first, *vertices.second);
                        if (distance < radius)
                        {
                            NiPoint3 normal = FUN_006971e0(neighbours[index]);
                            NiPoint3 direction = normal.Cross(*vertices.first - *vertices.second);
                            ((AdjustPointOps&)direction).FUN_004a0c10();
                            ((AdjustPointOps&)adjusted)
                                .FUN_0063c8a0(((AdjustPointOps&)direction).ApplyScaled(radius - distance));
                        }
                    }
                }
            }
        }
    }
    return adjusted;
}

struct NiPoint3Cmp : public NiPoint3
{
    bool FUN_004390c0(const NiPoint3& other) const;
};

struct NavEdgeHit
{
    int iType;
    int m_iEdgeNumber;
    NiPoint3 kPoint;
    NavEdgeHit();
};

bool __cdecl FUN_006ba240(const NiPoint3& start, const NiPoint3& end, const NiPoint3& from, const NiPoint3& to,
                          NiPoint3* out);

struct FUN_00698160_t : public NavMesh
{
    NavEdgeHit FindEdgeIntersection(unsigned short ausTriangle, int aiSkipEdge, const NiPoint3& arFrom,
                                    const NiPoint3& arTo);
};

// Tests the triangle's edges (skipping aiSkipEdge) for an intersection with the segment arFrom-arTo and returns the hit edge index and point, or a type-0 miss.
// @fnv 0x00698160
NavEdgeHit FUN_00698160_t::FindEdgeIntersection(unsigned short ausTriangle, int aiSkipEdge, const NiPoint3& arFrom,
                                                const NiPoint3& arTo)
{
    NiPoint3 verts[3];
    NiPoint3 flat = arTo;
    flat.z = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        verts[i] = FUN_0068f0a0(GetTriangle(ausTriangle)->FUN_005582d0(i));
    }
    for (int j = 0; j < 3; j++)
    {
        if (j == aiSkipEdge)
            continue;
        int next = j + 1;
        if (next == 3)
            next = 0;
        if (((NiPoint3Cmp&)verts[j]).FUN_004390c0(verts[next]))
            continue;
        NavEdgeHit hit;
        if (FUN_006ba240(verts[j], verts[next], arFrom, arTo, &hit.kPoint))
        {
            hit.iType = 3;
            hit.m_iEdgeNumber = j;
            return hit;
        }
    }
    NavEdgeHit none;
    none.iType = 0;
    none.m_iEdgeNumber = -1;
    return none;
}

struct UndoOwner;
struct SavedMesh
{
    void* object;
    SavedMesh();
    ~SavedMesh();
    SavedMesh& operator=(const SavedMesh&);
};
struct UndoEntry
{
    int unk00, unk04;
    int type;
    SavedMesh mesh;
};
struct UndoPtr
{
    UndoEntry* Get();
};
struct UndoArray
{
    UndoPtr& At(unsigned int);
    unsigned int Size();
};
struct UndoContext
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
    UndoContext();
    ~UndoContext();
    void Restore(UndoOwner*, UndoEntry*, void*);
    void Remove(UndoOwner*, UndoEntry*);
    void Add(UndoOwner*, const SavedMesh&, void*);
};
struct UndoOwner
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
    UndoArray entries;
    void Erase(int);
    unsigned int Find(UndoEntry*);
    bool UndoToPosition(unsigned int position, void* output);
};
// @fnv 0x00699000
bool UndoOwner::UndoToPosition(unsigned int position, void* output)
{
    UndoEntry* entry7 = entries.At(position).Get();
    if (position == entries.Size() - 1)
    {
        UndoContext context;
        if (entry7->type == 1)
            context.Restore(this, entry7, output);
        context.Remove(this, entry7);
        Erase(position);
    }
    else if (!Find(entry7))
    {
        UndoContext context;
        if (entry7->type == 1)
            context.Restore(this, entry7, output);
    }
    else
    {
        SavedMesh saved2[100];
        unsigned int count3 = 0;
        UndoContext context;
        unsigned int index2;
        for (index2 = entries.Size() - 1; index2 != position - 1; --index2)
        {
            if (entries.At(index2).Get()->type == 1)
            {
                context.Restore(this, entries.At(index2).Get(), output);
                if (index2 > position)
                {
                    saved2[count3] = entries.At(index2).Get()->mesh;
                    ++count3;
                }
            }
            context.Remove(this, entries.At(index2).Get());
            Erase(index2);
        }
        for (; index2 != -1; --index2)
        {
            if (entries.At(index2).Get()->type == 3)
            {
                context.Remove(this, entries.At(index2).Get());
                Erase(index2);
            }
            else
                break;
        }
        for (unsigned int next3 = 0; next3 < count3; ++next3)
            context.Add(this, saved2[next3], output);
    }
    return true;
}

class ObstacleRegistry
{
  public:
    unsigned int FUN_006c61b0(const NiPointer<ObstacleData>& m_spRegisteredObstacle);
};

class ObstacleOwner
{
  public:
    int unk00[0x34];
    ObstacleRegistry m_kRegistry;  // +0xd0

    unsigned int FUN_00699510(ObstacleData* pkObstacle);
};

// @fnv 0x00699510
unsigned int ObstacleOwner::FUN_00699510(ObstacleData* pkObstacle)
{
    unsigned int uiResult;
    {
        NiPointer<ObstacleData> m_spRegisteredObstacle(pkObstacle);
        uiResult = m_kRegistry.FUN_006c61b0(m_spRegisteredObstacle);
    }
    return uiResult;
}

namespace fnv_0069aa20 {
class EdgePoint
{
  public:
    float x, y, z;
    EdgePoint();
    EdgePoint operator-(const EdgePoint&) const;
    float FUN_004a7290() const;
};
struct LinkedMesh;
struct NavMeshPtr
{
    LinkedMesh* mesh;
    NavMeshPtr();
    ~NavMeshPtr();
    LinkedMesh* FUN_00559450();
};
struct MeshInfo
{
    bool FUN_0069ad00(NavMeshPtr&);
};
struct LinkInfo
{
    int type;
    MeshInfo* mesh;
    unsigned short triangle;
};
struct LinkedTriangle : NavMeshTriangle
{
    bool FUN_00690e10();
};
struct LinkedMesh
{
    unsigned int FUN_00558200();
    LinkedTriangle* FUN_005582f0(unsigned short);
    LinkInfo* GetEdge(unsigned short);
    void FUN_0068f0c0(unsigned short, int, EdgePoint&, EdgePoint&);
    LinkInfo* GetOrCreateEdgeInfo(unsigned short, int);
    MeshInfo* FUN_0068efb0();
    bool LinkMatchingEdges();
};
// @fnv 0x0069aa20
bool LinkedMesh::LinkMatchingEdges()
{
    for (unsigned int triangleIndex = 0; triangleIndex < FUN_00558200(); ++triangleIndex)
    {
        LinkedTriangle* triangle = FUN_005582f0((unsigned short)triangleIndex);
        if (!triangle || !triangle->FUN_00690e10())
            continue;
        for (int edge = 0; edge < 3; ++edge)
        {
            if (!triangle->IsEdgeFlagSet(edge))
                continue;
            int edgeCount;
            int matchingEdge;
            {
                LinkInfo* link = GetEdge(triangle->FUN_0068f2c0(edge));
                {
                    NavMeshPtr otherMesh;
                    if (!link->mesh->FUN_0069ad00(otherMesh))
                        continue;
                    LinkedTriangle* otherTriangle = otherMesh.FUN_00559450()->FUN_005582f0(link->triangle);
                    if (!otherTriangle)
                        continue;
                    edgeCount = 0;
                    matchingEdge = -1;
                    for (int otherEdge = 0; otherEdge < 3; ++otherEdge)
                    {
                        if (otherTriangle->IsEdgeFlagSet(otherEdge))
                        {
                            ++edgeCount;
                            matchingEdge = otherEdge;
                        }
                    }
                    if (edgeCount != 0)
                    {
                        EdgePoint edgeStart;
                        {
                            EdgePoint edgeEnd;
                            FUN_0068f0c0((unsigned short)triangleIndex, edge, edgeStart, edgeEnd);
                            for (int candidateEdge = 0; candidateEdge < 3; ++candidateEdge)
                            {
                                EdgePoint start, end;
                                otherMesh.FUN_00559450()->FUN_0068f0c0(link->triangle, candidateEdge, start, end);
                                if ((edgeStart - end).FUN_004a7290() < 400.0 &&
                                    (edgeEnd - start).FUN_004a7290() < 400.0)
                                {
                                    matchingEdge = candidateEdge;
                                    edgeCount = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (edgeCount == 1)
                    {
                        LinkInfo* reverse = otherMesh.FUN_00559450()->GetOrCreateEdgeInfo(link->triangle, matchingEdge);
                        reverse->mesh = FUN_0068efb0();
                        reverse->triangle = (unsigned short)triangleIndex;
                        reverse->type = 3;
                    }
                }
            }
        }
    }
    return true;
}
}  // namespace fnv_0069aa20

struct NavMeshTriList;
float FUN_00406ce0(float afValue);

struct NavMeshGridView
{
    unsigned int uiCellCount;
    float fCellWidth;
    float fCellHeight;
    float m_fGridOriginX;
    float afWorldOriginY;
    float fMinZ;
    float kPointArrayBench;
    float m_fWorldTransformCoefficient4;
    NavMeshTriList* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList);
};

// If arPos lies inside the grid bounds, computes the cell column and row from the cell size and stores the cell's tri list in *appList; otherwise stores null.
// @fnv 0x0069d370
void NavMeshGridView::GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList)
{
    if (arPos.x < m_fGridOriginX || arPos.x > kPointArrayBench || arPos.y < afWorldOriginY ||
        arPos.y > m_fWorldTransformCoefficient4)
    {
        *appList = 0;
    }
    else
    {
        float fDX2 = arPos.x - m_fGridOriginX;
        float fDYVal = arPos.y - afWorldOriginY;
        float fCol = fDX2 / fCellWidth;
        float fRow = fDYVal / fCellHeight;
        unsigned int uiCol = (unsigned int)FUN_00406ce0(fCol);
        unsigned int uiRowA = (unsigned int)FUN_00406ce0(fRow);
        if (uiCol >= uiCellCount)
        {
            uiCol = uiCellCount - 1;
        }
        if (uiRowA >= uiCellCount)
        {
            uiRowA = uiCellCount - 1;
        }
        *appList = FUN_006967c0(uiCol, uiRowA);
    }
}

// Projects a point onto a triangle in the XY plane via barycentric coordinates; if it lies inside,
// interpolates the triangle height there and accepts it when the height difference to the point
// is within [-fBelow, fAbove], returning the difference.
// @fnv 0x006b9cf0
bool FUN_006b9cf0(const NiPoint3& kP0, const NiPoint3& kP1, const NiPoint3& kP2, const NiPoint3& akPoint,
                  float& fHeightDiff, float fAbove, float fBelow)
{
    float fInvDenom;
    float fBary0;
    float fY2;
    float fDeltaY0;
    {
        float fY1;
        float fX1;
        float fX2Off;
        float fDeltaX0;
        float m_fGlyphExtent;
        float fDenom;
        float fW;
        float fProjectionAlongAim;
        float fV;

        fDenom = (kP1.x - kP0.x) * (kP2.y - kP0.y) - (kP2.x - kP0.x) * (kP1.y - kP0.y);
        if (fDenom == 0.0)
            return false;

        fX1 = kP1.x - akPoint.x;
        fX2Off = kP2.x - akPoint.x;
        fY1 = kP1.y - akPoint.y;
        fY2 = kP2.y - akPoint.y;
        fInvDenom = 1.0f / fDenom;

        fBary0 = (fX1 * fY2 - fX2Off * fY1) * fInvDenom;
        if (fBary0 < 0.0)
            return false;

        fDeltaX0 = kP0.x - akPoint.x;
        fDeltaY0 = kP0.y - akPoint.y;
        fV = (fX2Off * fDeltaY0 - fDeltaX0 * fY2) * fInvDenom;
        if (fV < 0.0)
            return false;

        fW = (fDeltaX0 * fY1 - fX1 * fDeltaY0) * fInvDenom;
        if (fW < 0.0)
            return false;

        m_fGlyphExtent = fBary0 * kP0.z + fV * kP1.z + fW * kP2.z;
        fProjectionAlongAim = m_fGlyphExtent - akPoint.z;
        if (fProjectionAlongAim > fAbove)
            return false;
        else if (fProjectionAlongAim < -fBelow)
            return false;

        fHeightDiff = fProjectionAlongAim;
        return true;
    }
}

struct NavObstacleObject
{
    void FUN_00401970();
};
struct NavObstaclePtr
{
    NavObstacleObject* object;
    NavObstaclePtr(int);
    NavObstaclePtr(const NavObstaclePtr&);
    ~NavObstaclePtr();
    void FUN_006e5cc0(const NavObstaclePtr&);
    NavObstacleObject* FUN_00559450();
};
struct NavMap
{
    unsigned int unk00, unk04, unk08, unk0C;
    bool FUN_0069afb0(unsigned short, NavObstaclePtr&);
    void FUN_006946a0(unsigned short, NavObstaclePtr);
    void FUN_0049c250(unsigned short);
};
struct NavIndexArray
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int FUN_0044ddc0();
    unsigned short& GetBufferEntry(unsigned int);
    bool FUN_0076b610();
};
struct NavResetVertices
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_00694890(unsigned int, bool);
};
struct NavResetTriangles
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_006949d0(unsigned int, bool);
};
struct NavTolerance
{
    float x, y, z;
    NavTolerance(float, float, float);
};
struct NavChange;
struct NavMeshOwner
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
    NavResetVertices vertices;
    NavResetTriangles triangles;
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
    NavMap* obstacles;
    void FUN_006987d0(const NavObstaclePtr&, const NavTolerance&, NavIndexArray*);
    unsigned int GetArrFlags();
    unsigned int FUN_00558200();
    NavMeshTriangle* FUN_005582f0(unsigned short);
    void FUN_00699510(NavChange*);
};
struct NavChange
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    virtual ~NavChange();
    unsigned int unk04, state;
    NavObstaclePtr obstacle;
    unsigned int oldVertices, newVertices, oldTriangles, newTriangles;
    NavIndexArray affected;
    float centerX, centerY, centerZ;
    unsigned int unk3C;
    NavMap obstacleMap;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    NavChange();
};
struct NavItem
{
    unsigned int unk00;
    unsigned short unk04;
    bool enabled;
    char unk07;
    unsigned int unk08, unk0C, unk10, unk14, unk18;
    NavObstaclePtr obstacle;
};
struct NavItemArray
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    void FUN_008454f0(unsigned int);
    unsigned int FUN_0044ddc0();
    NavItem*& FUN_00877a30(unsigned int);
};
struct NavChangeBuilder
{
    NavMeshOwner* mesh;
    NavObstaclePtr obstacle;
    NavChange* change;
    unsigned int unk0C, unk10, unk14, unk18;
    NavItemArray items, previousItems;
    unsigned int count;
    unsigned int FUN_006bc940();
    void CollectLinkedTriangles(float*);
    void BuildNavMeshEdges();
    void BuildQuad();
    void SplitCrossingEdges();
    bool FUN_006bf2a0(NavItem*);
    void FUN_006bdcb0();
    void FUN_006bde50();
    bool BuildTrianglesFromEdgePairs();
    void JoinAdjacentEdges();
    void ApplyEdgeSplits();
    void UpdateEdgeRecords(int);
    void FUN_006be770();
    void FUN_006beb80();
    void FUN_006bec20();
    void FUN_006be660();
    bool FUN_006bbd30(NavMeshOwner*, const NavObstaclePtr&, int);
};
// @fnv 0x006bbd30
bool NavChangeBuilder::FUN_006bbd30(NavMeshOwner* apMesh, const NavObstaclePtr& apObstacle, int flags)
{
    mesh = apMesh;
    obstacle.FUN_006e5cc0(apObstacle);
    items.FUN_008454f0(0);
    for (unsigned int i = 0; i < previousItems.FUN_0044ddc0(); ++i)
    {
        if (previousItems.FUN_00877a30(i)->obstacle.FUN_00559450())
            previousItems.FUN_00877a30(i)->obstacle.FUN_00559450()->FUN_00401970();
    }
    previousItems.FUN_008454f0(0);
    change = new NavChange;
    mesh->FUN_006987d0(apObstacle, NavTolerance(5.0f, 5.0f, 5.0f), &change->affected);
    if (change->affected.FUN_0076b610())
    {
        delete change;
        return false;
    }
    change->state = 1;
    change->obstacle.FUN_006e5cc0(apObstacle);
    change->oldVertices = mesh->GetArrFlags();
    change->oldTriangles = mesh->FUN_00558200();
    count = FUN_006bc940();
    CollectLinkedTriangles(&change->centerX);
    for (unsigned int j = 0; j < change->affected.FUN_0044ddc0(); ++j)
        mesh->FUN_005582f0(change->affected.GetBufferEntry(j))->FUN_00691570(0x20);
    BuildNavMeshEdges();
    for (unsigned int k = 0; k < change->affected.FUN_0044ddc0(); ++k)
    {
        unsigned short index = change->affected.GetBufferEntry(k);
        NavObstaclePtr entry(0);
        if (mesh->obstacles->FUN_0069afb0(index, entry))
        {
            change->obstacleMap.FUN_006946a0(index, entry);
            mesh->obstacles->FUN_0049c250(index);
        }
    }
    BuildQuad();
    SplitCrossingEdges();
    for (unsigned int n = 0; n < items.FUN_0044ddc0(); ++n)
    {
        if (FUN_006bf2a0(items.FUN_00877a30(n)))
            items.FUN_00877a30(n)->enabled = true;
    }
    FUN_006bdcb0();
    FUN_006bde50();
    if (!BuildTrianglesFromEdgePairs())
    {
        mesh->vertices.FUN_00694890(change->oldVertices, true);
        mesh->triangles.FUN_006949d0(change->oldTriangles, true);
        delete change;
        return false;
    }
    JoinAdjacentEdges();
    BuildTrianglesFromEdgePairs();
    ApplyEdgeSplits();
    UpdateEdgeRecords(flags);
    change->newVertices = mesh->GetArrFlags() - change->oldVertices;
    change->newTriangles = mesh->FUN_00558200() - change->oldTriangles;
    FUN_006be770();
    for (unsigned int t = change->oldTriangles; t < change->oldTriangles + change->newTriangles; ++t)
        mesh->obstacles->FUN_006946a0((unsigned short)t, obstacle);
    FUN_006beb80();
    FUN_006bec20();
    FUN_006be660();
    mesh->FUN_00699510(change);
    return true;
}

struct FindTriangleForLocationFilter;
float __cdecl RandomFloat(float fMin, float fScaledValue);
float __cdecl FUN_004019b0(float fValue);
extern const float runtimeFloatSettingDefault1020;

struct NiPoint3Ops697
{
    NiPoint3 FUN_00439e90(const NiPoint3& kPoint) const;
    NiPoint3Ops697& FUN_0063c8a0(const NiPoint3& kPoint);
};

struct NavFinder697
{
    bool IsLocationOnNavMesh(const NiPoint3& kPoint, FindTriangleForLocationFilter* pkFilter);
    NiPoint3 AdjustPointToNavMesh(const NiPoint3& kPoint, float fDistance);
    bool FUN_00697c10(const NiPoint3& kTargetCenter, float fRadius, NiPoint3* pkOut);
};

// @fnv 0x00697c10
bool NavFinder697::FUN_00697c10(const NiPoint3& aPosition, float aRadius, NiPoint3* pkOut)
{
    bool bFound = false;
    NiPoint3 kIntersectionOffset = NiPoint3::ZERO;
    for (unsigned int i = 0; i < 8 && !bFound; i++)
    {
        float fX = RandomFloat(-aRadius, aRadius);
        float fY = FUN_004019b0(aRadius * aRadius - fX * fX);
        fY = RandomFloat(-fY, fY);
        kIntersectionOffset.x = fX;
        kIntersectionOffset.y = fY;
        bFound = IsLocationOnNavMesh(((NiPoint3Ops697*)&kIntersectionOffset)->FUN_00439e90(aPosition), 0);
    }
    if (!bFound)
    {
        pkOut = 0;
        return false;
    }
    ((NiPoint3Ops697*)&kIntersectionOffset)->FUN_0063c8a0(aPosition);
    *pkOut = AdjustPointToNavMesh(kIntersectionOffset, runtimeFloatSettingDefault1020);
    return true;
}

extern const float DAT_01016970;
extern const float DAT_01015f5c;
float __cdecl FUN_00406ce0(float);
bool __cdecl FUN_00696540(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);

struct TriangleGridBuildReceiver
{
    unsigned int dimensionB_;
    float width8, heightSquared9;
    void FUN_0069d2d0();
    void InitFromPoints(const NiPoint3&, const NiPoint3&, unsigned int);
    unsigned int FUN_00559450();
    void FUN_00696500(unsigned short, unsigned int, unsigned int);
    NiPoint3 FUN_0069d790(unsigned int, unsigned int);
};
struct GridCell
{
    unsigned int x, y;
};
struct GridMesh : NavMesh
{
    TriangleGridBuildReceiver Grid;
    void ComputeBounds(NiPoint3&, NiPoint3&);
    bool FUN_00697730(unsigned short, const NiPoint3&, float&, float, float);
    void FUN_006959b0();
};

// Adds each triangle to grid cells containing its vertices, containing cell corners, or intersecting its edges.
// @fnv 0x006959b0
void GridMesh::FUN_006959b0()
{
    int count2 = FUN_00558200();
    Grid.FUN_0069d2d0();
    if (count2 == 0)
        return;
    NiPoint3 boundsMin5, boundsMaxX;
    ComputeBounds(boundsMin5, boundsMaxX);
    Grid.InitFromPoints(boundsMin5, boundsMaxX, count2);
    unsigned int dimensionB_ = Grid.FUN_00559450();
    float width8 = Grid.width8;
    float heightSquared9 = Grid.heightSquared9;
    NiPoint3 corner1, right3, upper3, upperRight4, point12;
    NiPoint3 verticesCheck6[3];
    int triangle;
    NavMeshTriangle* triA4;
    float minX7, minYA, maxx6, maxy3;
    GridCell cellsVal[3];
    unsigned int maxX2, minCellX4, maxCellYVal, minY2;
    bool addedX;
    for (triangle = 0; triangle < count2; triangle++)
    {
        triA4 = GetTriangle((unsigned short)triangle);
        minX7 = minYA = DAT_01016970;
        maxx6 = maxy3 = DAT_01015f5c;
        for (int vertex = 0; vertex < 3; vertex++)
        {
            point12 = FUN_0068f0a0(triA4->FUN_005582d0(vertex));
            verticesCheck6[vertex] = point12;
            if (point12.x < minX7)
                minX7 = point12.x;
            if (point12.x > maxx6)
                maxx6 = point12.x;
            if (point12.y < minYA)
                minYA = point12.y;
            if (point12.y > maxy3)
                maxy3 = point12.y;
            cellsVal[vertex].x = (unsigned int)FUN_00406ce0((point12.x - boundsMin5.x) / width8);
            cellsVal[vertex].y = (unsigned int)FUN_00406ce0((point12.y - boundsMin5.y) / heightSquared9);
            if (cellsVal[vertex].x >= dimensionB_)
                cellsVal[vertex].x = dimensionB_ - 1;
            if (cellsVal[vertex].y >= dimensionB_)
                cellsVal[vertex].y = dimensionB_ - 1;
        }
        minCellX4 = maxX2 = cellsVal[0].x;
        minY2 = maxCellYVal = cellsVal[0].y;
        for (int vertex2 = 1; vertex2 < 3; vertex2++)
        {
            if (cellsVal[vertex2].x < minCellX4)
                minCellX4 = cellsVal[vertex2].x;
            if (cellsVal[vertex2].x > maxX2)
                maxX2 = cellsVal[vertex2].x;
            if (cellsVal[vertex2].y < minY2)
                minY2 = cellsVal[vertex2].y;
            if (cellsVal[vertex2].y > maxCellYVal)
                maxCellYVal = cellsVal[vertex2].y;
        }
        addedX = false;
        if (minCellX4 == maxX2 && minY2 == maxCellYVal)
        {
            Grid.FUN_00696500((unsigned short)triangle, minCellX4, minY2);
            addedX = true;
        }
        else
        {
            for (unsigned int x = minCellX4; x <= maxX2; x++)
            {
                for (unsigned int y = minY2; y <= maxCellYVal; y++)
                {
                    if ((cellsVal[0].x == x && cellsVal[0].y == y) || (cellsVal[1].x == x && cellsVal[1].y == y) ||
                        (cellsVal[2].x == x && cellsVal[2].y == y))
                    {
                        Grid.FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    corner1 = Grid.FUN_0069d790(x, y);
                    right3 = Grid.FUN_0069d790(x + 1, y);
                    upper3 = Grid.FUN_0069d790(x, y + 1);
                    upperRight4 = Grid.FUN_0069d790(x + 1, y + 1);
                    if ((verticesCheck6[0].x <= upperRight4.x && verticesCheck6[0].y <= upperRight4.y &&
                         verticesCheck6[0].x >= corner1.x && verticesCheck6[0].y >= corner1.y) ||
                        (verticesCheck6[1].x <= upperRight4.x && verticesCheck6[1].y <= upperRight4.y &&
                         verticesCheck6[1].x >= corner1.x && verticesCheck6[2].y >= corner1.y) ||
                        (verticesCheck6[2].x <= upperRight4.x && verticesCheck6[2].y <= upperRight4.y &&
                         verticesCheck6[2].x >= corner1.x && verticesCheck6[2].y >= corner1.y))
                    {
                        Grid.FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    float zl;
                    if (FUN_00697730((unsigned short)triangle, corner1, zl, DAT_01016970, 180.0f) ||
                        FUN_00697730((unsigned short)triangle, right3, zl, DAT_01016970, 180.0f) ||
                        FUN_00697730((unsigned short)triangle, upper3, zl, DAT_01016970, 180.0f) ||
                        FUN_00697730((unsigned short)triangle, upperRight4, zl, DAT_01016970, 180.0f))
                    {
                        Grid.FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    NiPoint3 cellStart3, cellEnd5, triStart6, triEndX;
                    bool intersects3 = false;
                    for (int edge = 0; edge < 4 && !intersects3; edge++)
                    {
                        switch (edge)
                        {
                        case 0:
                            cellStart3 = corner1;
                            cellEnd5 = right3;
                            break;
                        case 1:
                            cellStart3 = right3;
                            cellEnd5 = upperRight4;
                            break;
                        case 2:
                            cellStart3 = upperRight4;
                            cellEnd5 = upper3;
                            break;
                        case 3:
                            cellStart3 = upper3;
                            cellEnd5 = corner1;
                            break;
                        }
                        for (int triEdge = 0; triEdge < 3; triEdge++)
                        {
                            switch (triEdge)
                            {
                            case 0:
                                triStart6 = verticesCheck6[0];
                                triEndX = verticesCheck6[1];
                                break;
                            case 1:
                                triStart6 = verticesCheck6[1];
                                triEndX = verticesCheck6[2];
                                break;
                            case 2:
                                triStart6 = verticesCheck6[2];
                                triEndX = verticesCheck6[0];
                                break;
                            }
                            if (FUN_00696540(cellStart3, cellEnd5, triStart6, triEndX))
                            {
                                intersects3 = true;
                                break;
                            }
                        }
                    }
                    if (intersects3)
                    {
                        Grid.FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                    }
                }
            }
        }
    }
}
