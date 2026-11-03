
// src/fallout_shared/pathfinding/navmeshsearchflee.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchflee.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void _Deallocate(void*);

struct FUN_006a9290_shell
{
    void FUN_006a92c0();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_006a92c0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006a9290
void* FUN_006a9290_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_006a92c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0106b87c;
struct NavMeshSearch
{
    NavMeshSearch();
    void* m_vtbl;
    float fFleeTime;
    bool bFleeActive;
};
struct FUN_006ab410 : NavMeshSearch
{
    FUN_006ab410();
};
// Initializes the vtable pointer and clears the flee time and flee-active flag at offsets 0x20a4 and 0x20a8.
// @fnv 0x006ab410
FUN_006ab410::FUN_006ab410()
{
    m_vtbl = (void*)&DAT_0106b87c;
    *(float*)((char*)this + 0x20a4) = 0.0f;
    *(char*)((char*)this + 0x20a8) = 0;
}

class NavMesh;
class NavMeshTriangleEdgeReference;
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float GetSquaredXYLength() const;
    float FUN_004a7290() const;
};
class NavMeshPtr
{
  public:
    NavMesh* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
};
class Flt
{
  public:
    operator unsigned int();
};
class NavMeshTriangleReference
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    NiPoint3 FUN_006a6eb0() const;
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int unk0, unk4;
    N kNode;
    const N& FUN_00413f40() const;
};
class PathingLocation
{
  public:
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
    NiPoint3 FUN_005c3420() const;
};
class PathingAvoidNodeArray
{
  public:
    float GetAvoidanceAtPoint(NiPoint3&);
};
class PathingRequest
{
  public:
    PathingLocation* FUN_006a9540();
    PathingLocation* GetOrigin();
    float GetFloatAtOffsetB0() const;
    PathingAvoidNodeArray* GetString() const;
};
extern double _gModifierZero;

class NavMeshSearchFlee
{
  public:
    unsigned int pad0[0x2058 / 4];
    PathingRequest* pRequest;
    unsigned int pad205c[9];
    bool bHasDestination;
    NiPoint3 kDestination;
    const AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* GetFieldAt2050();
    bool IsNodeValid(const AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode);
};

// @fnv 0x006a9a70
bool NavMeshSearchFlee::IsNodeValid(const AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode)
{
    PathingLocation* pdest = pRequest->FUN_006a9540();
    float fscore;
    if (bHasDestination)
    {
        NavMeshPtr spmeshPtr;
        unsigned short sgoalTri;
        if (pdest->FindNavMeshTriangle(spmeshPtr, sgoalTri))
        {
            const NavMeshTriangleReference* thisNode = &apNode->FUN_00413f40();
            if ((unsigned int)thisNode->m_pLocationNavMesh == *(Flt*)&spmeshPtr &&
                thisNode->m_usTriangleIdentifier == sgoalTri)
                return true;
        }
    }
    if (apNode == GetFieldAt2050())
        return false;
    NiPoint3 nodeCenter = apNode->kNode.FUN_006a6eb0();
    float fsqrLength = (pRequest->GetOrigin()->FUN_005c3420() - nodeCenter).GetSquaredXYLength();
    if (fsqrLength < pRequest->GetFloatAtOffsetB0() * pRequest->GetFloatAtOffsetB0())
        return false;
    if (bHasDestination)
    {
        NiPoint3 destinationVec = kDestination - nodeCenter;
        NiPoint3 originDestinationVec = pRequest->GetOrigin()->FUN_005c3420() - kDestination;
        if (originDestinationVec.FUN_004a7290() < destinationVec.FUN_004a7290())
            return false;
    }
    fscore = 0.0f;
    if (pRequest->GetString())
        fscore = pRequest->GetString()->GetAvoidanceAtPoint(nodeCenter);
    return fscore <= _gModifierZero;
}

struct Pt
{
    float Length() const;
};

struct P3 : public Pt
{
    float x, y, z;
    P3 operator-(const P3&) const;
};

class NavMesh
{
  public:
    P3 GetNavMeshData(unsigned short);
};

void FUN_005330e0(float&, float, float);

struct FUN_006a9580_NodeLayout
{
    unsigned int unk0;
    float fcost;
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    float GetCenterX;
    float m_fCenterY;
    float m_fCenterZ;
};

struct FUN_006a9580_shell
{
    unsigned int pad0[0x2058 / 4];
    void* pRequest;
    unsigned int pad205c[5];
    P3 kAvoidVector;
    float fFleeRange;

    void SetNodeFleeCost(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode, NavMesh* apNavMesh,
                         unsigned short aiTriangle);
};

// Stores the navmesh and triangle on the node, computes the triangle center, and sets the node cost from the flee range minus the distance to the avoid vector.
// @fnv 0x006a9580
void FUN_006a9580_shell::SetNodeFleeCost(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode,
                                         NavMesh* apNavMesh, unsigned short aiTriangle)
{
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_pLocationNavMesh = apNavMesh;
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_usTriangleIdentifier = aiTriangle;

    P3 center = apNavMesh->GetNavMeshData(aiTriangle);

    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->GetCenterX = center.x;
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_fCenterY = center.y;
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_fCenterZ = center.z;

    P3 avoidVector = center - kAvoidVector;
    float fcost = fFleeRange - avoidVector.Length();

    FUN_005330e0(fcost, 0.0f, fFleeRange);

    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->fcost = fcost;
}

// NavMeshSearchFlee's destructor.
//
// The compiler-generated destructor of a class with a base class first restores
// the class vtable pointer into the object and then runs the base class
// destructor on the same object.
struct AStarSearchBase
{
    AStarSearchBase();
    virtual void v00();
    virtual ~AStarSearchBase();
};

struct FUN_006a92c0_cls : public AStarSearchBase
{
    virtual void v01();
    virtual ~FUN_006a92c0_cls();
};

// @fnv 0x006a92c0
FUN_006a92c0_cls::~FUN_006a92c0_cls()
{}

struct FleeStartNode : NavMeshTriangleReference
{
    NiPoint3 position;
};
struct FleePath
{
    bool FUN_0076b610();
    const NavMeshTriangleReference* GetLastElement();
};
struct FleeLocation : PathingLocation
{
    bool FUN_006a9520();
};
struct FleeRequest : PathingRequest
{
    bool GetByteAtOffset9B();
};
struct FleeAvoidNodes : PathingAvoidNodeArray
{
    float FUN_006dc9f0(NiPoint3&, P3&);
};
extern const NiPoint3 NiPoint3_ZERO;
float FUN_0040ebd0(float, float);
struct FleeSearch : FUN_006a9580_shell
{
    bool bHasDestination;
    NiPoint3 kDestination;
    unsigned int FUN_006a94f0(NavMesh*, unsigned short);
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* FUN_006a7c90(unsigned int, const FleeStartNode*,
                                                                                    float);
    bool FUN_006a7d60(FleePath*, unsigned int, bool);
    bool StartFleeSearch(FleeRequest*, const FleeStartNode*, FleePath*, unsigned int);
};
// @fnv 0x006a92e0
bool FleeSearch::StartFleeSearch(FleeRequest* request, const FleeStartNode* start, FleePath* path, unsigned int limit)
{
    pRequest = request;
    reinterpret_cast<FleeStartNode&>(pad205c) = *start;
    NiPoint3 a = request->GetOrigin()->FUN_005c3420();
    reinterpret_cast<NiPoint3&>(kAvoidVector) = NiPoint3_ZERO;
    fFleeRange = request->GetFloatAtOffsetB0();
    if (static_cast<FleeRequest*>(pRequest)->GetString())
        static_cast<FleeAvoidNodes*>(static_cast<FleeRequest*>(pRequest)->GetString())->FUN_006dc9f0(a, kAvoidVector);
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* p =
        FUN_006a7c90(FUN_006a94f0(start->m_pLocationNavMesh, start->m_usTriangleIdentifier), start, 0.0f);
    SetNodeFleeCost(p, start->m_pLocationNavMesh, start->m_usTriangleIdentifier);
    if (!static_cast<FleeLocation*>(request->FUN_006a9540())->FUN_006a9520())
    {
        bHasDestination = true;
        kDestination = static_cast<FleeRequest*>(pRequest)->FUN_006a9540()->FUN_005c3420();
    }
    bool h = FUN_006a7d60(path, limit, static_cast<FleeRequest*>(pRequest)->GetByteAtOffset9B());
    if (!h && !path->FUN_0076b610())
    {
        const NavMeshTriangleReference* f = path->GetLastElement();
        NiPoint3 eb = f->FUN_006a6eb0();
        float s = static_cast<FleeRequest*>(pRequest)->GetFloatAtOffsetB0() * 0.5;
        s = FUN_0040ebd0(s, 256.0f);
        NiPoint3 i = a - eb;
        if (i.FUN_004a7290() > s * s)
            h = true;
    }
    return h;
}

#include <float.h>
struct Vector3
{
    float x, y, z;
    Vector3 operator-(const Vector3&) const;
    void Normalize();
    float Length() const;
    float Dot(const Vector3&) const;
};
extern const NiPoint3 pathingrequestZero;
extern float g_doorCost;
extern double g_positionWeight;
extern double g_destinationWeight;
struct Threshold
{
    float* Float();
};
extern Threshold g_threshold;
float __cdecl FUN_00404010(float, float);
struct Mesh;
struct MeshTriangle
{
    bool FUN_00691140(unsigned int);
};
struct EdgeInfo
{
    int type;
};
struct DoorBase
{
    bool FUN_00518000();
};
struct Door
{
    DoorBase* FUN_007af430();
};
struct DoorLockX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorLockX(Door*);
    ~DoorLockX();
    bool FUN_00502450(void*, Door*, bool*);
};
struct Mesh
{
    bool FindAdjacentEdge(unsigned short, int, Mesh**, unsigned short*, int*);
    EdgeInfo* FUN_0068f230(unsigned short, int);
    MeshTriangle* FUN_005582f0(unsigned short);
    unsigned int* FUN_00699af0(unsigned short);
    Vector3 FUN_00558220(unsigned short);
};
Door* __cdecl LookupFormByID(unsigned int);
struct AvoidPoints
{
    float SumNodeValues(Vector3&);
};
struct Request
{
    AvoidPoints* GetString() const;
    bool FUN_0073cb80() const;
    void* FUN_006c9900();
    float GetFloatAtOffset68() const;
};
struct Node
{
    float cost;
    int unk04;
    Mesh* edgeData;
    unsigned short triangle;
    unsigned short unk0e;
    int unk10, unk14, unk18;
    Mesh* parentMesh;
    unsigned short parentTriangle;
    unsigned short unk22;
    int parentEdge;
};
struct NodeGeometry
{
    Mesh* edgeData;
    unsigned short triangle;
    Vector3 FUN_006a6eb0() const;
};
struct NodeArray
{
    void FUN_007cb2e0(Node*&);
};
enum SearchResult
{
    Added,
    Updated,
    Unchanged
};
struct Search : FUN_006a9580_shell
{
    bool hasDestination;
    Vector3 destination;
    unsigned int FUN_006a94f0();
    SearchResult FUN_006a7e00(unsigned int, Mesh*, unsigned short, float, Node**);
    void SetNodeFleeCost(Node*, Mesh*, unsigned short);
    bool ExpandNode(Node*, NodeArray*);
};
// @fnv 0x006a9620
bool Search::ExpandNode(Node* node, NodeArray* output)
{
    // Local names preserve the required compiler stack layout.
    Vector3 position;  // Normalized avoidance direction.
    Vector3 direction = ((NodeGeometry*)&node->edgeData)->FUN_006a6eb0();
    AvoidPoints* avoid = ((Request*)pRequest)->GetString();
    position = *(const Vector3*)&pathingrequestZero;
    if (avoid)
    {
        position = *(Vector3*)&kAvoidVector - direction;
        position.Normalize();
    }
    if (!_finite(node->cost))
    {
        float& initial = node->cost;
        initial = 0.0f;
    }
    for (int edge = 0; edge < 3; ++edge)
    {
        Mesh* edgeData;
        unsigned short triangle;
        int mesh;
        if (node->edgeData->FindAdjacentEdge(node->triangle, edge, &edgeData, &triangle, &mesh))
        {
            EdgeInfo* next = node->edgeData->FUN_0068f230(node->triangle, edge);
            if (next && next->type == 1)
                continue;
            float delta = 1.0f;
            if (edgeData->FUN_005582f0(triangle)->FUN_00691140(0x1000))
            {
                if (((Request*)pRequest)->FUN_0073cb80())
                    continue;
                else
                {
                    unsigned int door = *edgeData->FUN_00699af0(triangle);
                    Door* id = LookupFormByID(door);
                    if (id)
                    {
                        DoorLockX result(id);
                        void* lock = ((Request*)pRequest)->FUN_006c9900();
                        bool actor;
                        if (!result.FUN_00502450(lock, id, &actor))
                            continue;
                        if (id->FUN_007af430()->FUN_00518000())
                            delta = 100.0f;
                    }
                }
            }
            if (((Request*)pRequest)->GetFloatAtOffset68() > *g_threshold.Float() &&
                edgeData->FUN_005582f0(triangle)->FUN_00691140(0x10))
                continue;
            Node* neighbour;
            // Adjacent triangle centre and displacement from the current node.
            Vector3 multiplier = edgeData->FUN_00558220(triangle);
            Vector3 cost = multiplier - direction;
            // Accumulated path cost.
            float extra = cost.Length() * delta + node->cost;
            if (avoid)
            {
                extra += ((Request*)pRequest)->GetString()->SumNodeValues(multiplier);
                Vector3 penalty = cost;
                penalty.Normalize();
                float travel = FUN_00404010(0.0f, penalty.Dot(position));
                extra += travel * g_positionWeight;
            }
            if (hasDestination)
            {
                float distance = (multiplier - destination).Length();
                extra += distance * 10.0;
            }
            switch (FUN_006a7e00(FUN_006a94f0(), edgeData, triangle, extra, &neighbour))
            {
            case 0:
                SetNodeFleeCost(neighbour, edgeData, triangle);
            case 1:
                neighbour->parentMesh = node->edgeData;
                neighbour->parentTriangle = node->triangle;
                neighbour->parentEdge = edge;
                output->FUN_007cb2e0(neighbour);
                break;
            }
        }
    }
    return true;
}
