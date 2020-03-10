// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:57)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_DETAIL_H

#include "Delaunay2.h"
#include "System/Helper/UnusedMacro.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"
#include "Mathematics/Algebra/BarycentricCoordinates.h"

template <typename Real>
const int Mathematics::Delaunay2<Real>
	::msIndex[3][2]{{0,1},{1,2},{2,0}};

template <typename Real>
Mathematics::Delaunay2<Real>
	::Delaunay2 (const std::vector<Vector2D<Real> >& vertices,Real epsilon, bool owner, QueryType queryType)
	:Delaunay<Real>{ vertices.size(), epsilon, owner, queryType },mVertices{ vertices },
	 mNumUniqueVertices{ 0 },mSVertices{},mQuery{ 0 },mLineOrigin{ Vector2D<Real>::sm_Zero },
	 mLineDirection{ Vector2D<Real>::sm_Zero },mPathLast{ -1 },mPath{ 0 },mLastEdgeV0{ -1 },
	 mLastEdgeV1{ -1 },mLastEdgeOpposite{ -1 },mLastEdgeOppositeIndex{ -1 }
{
    Vector2DInformation<Real> info(mVertices, epsilon);
    if (info.GetDimension() == 0)
    {
        // The values of mDimension, mIndices, and mAdjacencies were
        // already initialized by the Delaunay base class.
        return;
    }

    if (info.GetDimension() == 1)
    {
        // The set is (nearly) collinear.  The caller is responsible for
        // creating a Delaunay1 object.
        mDimension = 1;
        mLineOrigin = info.GetOrigin();
        mLineDirection = info.GetDirectionX();
        return;
    }

    mDimension = 2;

    // Allocate storage for the input vertices and the supertriangle
    // vertices.
    mSVertices.resize(mNumVertices);
    int i;

    if (queryType != QueryType::Rational && queryType != QueryType::Filtered)
    {
        // Transform the vertices to the square [0,1]^2.
        mMin = info.GetMinExtreme();
        mScale = ((Real)1)/info.GetMaxRange();
        for (i = 0; i < mNumVertices; ++i)
        {
            mSVertices[i] = (mVertices[i] - mMin)*mScale;
        }

        Real expand;
        if (queryType == QueryType::Int64)
        {
            // Scale the vertices to the square [0,2^{16}]^2 to allow use of
            // 64-bit integers for triangulation.
            expand = (Real)(1 << 16);
            mQuery = NEW0 Query2Int64<Real>(mSVertices);
        }
        else if (queryType == QueryType::Interger)
        {
            // Scale the vertices to the square [0,2^{20}]^2 to get more
            // precision for TInteger than for 64-bit integers for
            // triangulation.
            expand = (Real)(1 << 20);
            mQuery = NEW0 Query2Integer<Real>(mSVertices);
        }
        else // queryType == Query::QT_REAL
        {
            // No scaling for floating point.
            expand = (Real)1;
            mQuery = NEW0 Query2<Real>(mSVertices);
        }

        mScale *= expand;
        for (i = 0; i < mNumVertices; ++i)
        {
            mSVertices[i] *= expand;
        }
    }
    else
    {
        // No transformation needed for exact rational arithmetic.
        mMin = Vector2D<Real>::sm_Zero;
        mScale = (Real)1;
        memcpy(&mSVertices[0], &mVertices[0], mNumVertices*sizeof(Vector2D<Real>));

        if (queryType == QueryType::Rational)
        {
            mQuery = NEW0 Query2Rational<Real>(mSVertices);
        }
        else // queryType == Query::QT_FILTERED
        {
            mQuery = NEW0 Query2Filtered<Real>(mSVertices,mEpsilon);
        }
    }

    // Insert the (nondegenerate) triangle constructed by the call to
    // GetInformation. This is necessary for the circumcircle-visibility
    // algorithm to work correctly.
	int mExtreme[3]{info.GetMinExtremeIndex(),info.GetPerpendicularExtremeIndex(),info.GetMaxExtremeIndex()};

    if (!info.IsExtremeCCW())
    {
        std::swap(mExtreme[1], mExtreme[2]);
    }
    mTriMesh.InsertTriangle(mExtreme[0], mExtreme[1], mExtreme[2]);

    // Incrementally update the triangulation.  The set of processed points
    // is maintained to eliminate duplicates, either in the original input
    // points or in the points obtained by snap rounding.
    std::set<Vector2D<Real> > processed;
    for (i = 0; i < 3; ++i)
    {
        processed.insert(mSVertices[mExtreme[i]]);
    }
    for (i = 0; i < mNumVertices; ++i)
    {
        if (processed.find(mSVertices[i]) == processed.end())
        {
            Update(i);
            processed.insert(mSVertices[i]);
        }
    }
    mNumUniqueVertices = boost::numeric_cast<int>(processed.size());

    // Assign integer values to the triangles for use by the caller.
    std::map<Triangle*,int> permute;
    i = -1;
    permute[(Triangle*)0] = i++;
    const auto& tmap = mTriMesh.GetTriangles();
    ETManifoldMesh::TMapCIterator element;
    for (element = tmap.begin(); element != tmap.end(); ++element)
    {
        permute[element->second] = i++;
    }

    // Put Delaunay triangles into an array (vertices and adjacency info).
    mNumSimplices = (int)mTriMesh.GetTriangles().size();
    if (mNumSimplices > 0)
    {
        mIndices = NEW1<int>(3*mNumSimplices);
        mAdjacencies = NEW1<int>(3*mNumSimplices);
        i = 0;
        for (element = tmap.begin(); element != tmap.end(); ++element)
        {
            const ETManifoldMesh::Triangle* tri = element->second;
            for (int j = 0; j < 3; ++j, ++i)
            {
                mIndices[i] = tri->V[j];
                mAdjacencies[i] = permute[tri->T[j]];
            }
        }
        MATHEMATICS_ASSERTION_0(i == 3*mNumSimplices, "Unexpected mismatch\n");

        mPathLast = -1;
        mPath = NEW1<int>(mNumSimplices + 1);
        memset(mPath, 0, (mNumSimplices + 1)*sizeof(int));
    }
}

template <typename Real>
Mathematics::Delaunay2<Real>
	::~Delaunay2 ()
{
    DELETE0(mQuery);
    DELETE1(mPath);
}

template <typename Real>
const Mathematics::Vector2D<Real>* Mathematics::Delaunay2<Real>
	::GetVertices () const
{
    return &mVertices[0];
}

template <typename Real>
int Mathematics::Delaunay2<Real>
	::GetNumUniqueVertices () const
{
    return mNumUniqueVertices;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::Delaunay2<Real>
	::GetLineOrigin () const
{
    return mLineOrigin;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::Delaunay2<Real>
	::GetLineDirection () const
{
    return mLineDirection;
}

template <typename Real>
Mathematics::Delaunay1<Real>* Mathematics::Delaunay2<Real>
	::GetDelaunay1 () const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return 0;
    }

    Real* projection = NEW1<Real>(mNumVertices);
    for (int i = 0; i < mNumVertices; ++i)
    {
        Vector2D<Real> diff = mVertices[i] - mLineOrigin;
        projection[i] = Vector2DTools<Real>::DotProduct(mLineDirection,diff);
    }

    return NEW0 Delaunay1<Real>(mNumVertices, projection, mEpsilon, true,mQueryType);
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::GetHull (int& numEdges, int*& indices)
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return false;
    }

    numEdges = 0;
    indices = 0;

    // Count the number of edges that are not shared by two triangles.
    int i, numAdjacent = 3*mNumSimplices;
    for (i = 0; i < numAdjacent; ++i)
    {
        if (mAdjacencies[i] == -1)
        {
            numEdges++;
        }
    }
    MATHEMATICS_ASSERTION_0(numEdges > 0, "There must be at least one triangle\n");
    if (numEdges == 0)
    {
        return false;
    }

    // Enumerate the edges.
    indices = NEW1<int>(2*numEdges);
    int* currentIndex = indices;
    for (i = 0; i < numAdjacent; ++i)
    {
        if (mAdjacencies[i] == -1)
        {
            int tri = i/3, j = i%3;
            *currentIndex++ = mIndices[3*tri + j];
            *currentIndex++ = mIndices[3*tri + ((j+1)%3)];
        }
    }

    return true;
}

template <typename Real>
int Mathematics::Delaunay2<Real>
	::GetContainingTriangle (const Vector2D<Real>& p) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return -1;
    }

    // Convert to scaled coordinates.
	auto scP = (p - mMin)*mScale;

    // Start at first triangle in mesh.
    auto index = (mPathLast >= 0 ? mPath[mPathLast] : 0);
    mPathLast = -1;
    mLastEdgeV0 = -1;
    mLastEdgeV1 = -1;
    mLastEdgeOpposite = -1;
    mLastEdgeOppositeIndex = -1;

    // Use triangle edges as binary separating lines.
    for (auto i = 0; i < mNumSimplices; ++i)
    {
        mPath[++mPathLast] = index;

        int* vertices = &mIndices[3*index];

        if (mQuery->ToLine(scP, vertices[0], vertices[1]) > 0)
        {
            index = mAdjacencies[3*index];
            if (index == -1)
            {
                mLastEdgeV0 = vertices[0];
                mLastEdgeV1 = vertices[1];
                mLastEdgeOpposite = vertices[2];
                mLastEdgeOppositeIndex = 2;
                return -1;
            }
            continue;
        }

        if (mQuery->ToLine(scP, vertices[1], vertices[2]) > 0)
        {
            index = mAdjacencies[3*index + 1];
            if (index == -1)
            {
                mLastEdgeV0 = vertices[1];
                mLastEdgeV1 = vertices[2];
                mLastEdgeOpposite = vertices[0];
                mLastEdgeOppositeIndex = 0;
                return -1;
            }
            continue;
        }

        if (mQuery->ToLine(scP, vertices[2], vertices[0]) > 0)
        {
            index = mAdjacencies[3*index + 2];
            if (index == -1)
            {
                mLastEdgeV0 = vertices[2];
                mLastEdgeV1 = vertices[0];
                mLastEdgeOpposite = vertices[1];
                mLastEdgeOppositeIndex = 1;
                return -1;
            }
            continue;
        }

        mLastEdgeV0 = -1;
        mLastEdgeV1 = -1;
        mLastEdgeOpposite = -1;
        mLastEdgeOppositeIndex = -1;
        return index;
    }

    return -1;
}

template <typename Real>
int Mathematics::Delaunay2<Real>
	::GetPathLast () const
{
    return mPathLast;
}

template <typename Real>
const int* Mathematics::Delaunay2<Real>
	::GetPath () const
{
    return mPath;
}

template <typename Real>
int Mathematics::Delaunay2<Real>
	::GetLastEdge (int& v0, int& v1, int& v2) const
{
    v0 = mLastEdgeV0;
    v1 = mLastEdgeV1;
    v2 = mLastEdgeOpposite;
    return mLastEdgeOppositeIndex;
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::GetVertexSet (int i, Vector2D<Real> vertices[3]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        vertices[0] = mVertices[mIndices[3*i  ]];
        vertices[1] = mVertices[mIndices[3*i + 1]];
        vertices[2] = mVertices[mIndices[3*i + 2]];
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::GetIndexSet (int i, int indices[3]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        indices[0] = mIndices[3*i  ];
        indices[1] = mIndices[3*i + 1];
        indices[2] = mIndices[3*i + 2];
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::GetAdjacentSet (int i, int adjacencies[3]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        adjacencies[0] = mAdjacencies[3*i  ];
        adjacencies[1] = mAdjacencies[3*i + 1];
        adjacencies[2] = mAdjacencies[3*i + 2];
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::GetBarycentricSet (int i, const Vector2D<Real>& p,Real bary[3]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
		auto v0 = mVertices[mIndices[3*i  ]];
		auto v1 = mVertices[mIndices[3*i + 1]];
		auto v2 = mVertices[mIndices[3*i + 2]];
		auto coordinates = p.GetBarycentrics(v0, v1, v2);
       bary[0] = coordinates[0];
	   bary[1] = coordinates[1];
	   bary[2] = coordinates[2];
        return true;
    }

    return false;
}

template <typename Real>
Mathematics::Delaunay2<Real>
	::Delaunay2 (const System::TChar* filename)
	:Delaunay<Real>{ 0, Real{}, false, QueryType::Real }, mVertices{ 0 }, mSVertices{ 0 }, mQuery{ 0 }, mPath{ 0 }
{
    bool loaded = Load(filename);
    MATHEMATICS_ASSERTION_0(loaded, "Cannot open file %s\n", filename);
    SYSTEM_UNUSED_ARG(loaded);
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::Load (const System::TChar* filename)
{
	CoreTools::ReadFileManager inFile{ filename };
 
	Delaunay<Real>::Load(inFile);

    DELETE0(mQuery);
    DELETE1(mPath);
   
    mOwner = true;
    mVertices.resize(mNumVertices);
    mSVertices.resize(mNumVertices);
    mPath = NEW1<int>(mNumSimplices + 1);

    inFile.Read(sizeof(int), &mNumUniqueVertices);
    inFile.Read(sizeof(int), &mPathLast);
    inFile.Read(sizeof(int), &mLastEdgeV0);
    inFile.Read(sizeof(int), &mLastEdgeV1);
    inFile.Read(sizeof(int), &mLastEdgeOpposite);
    inFile.Read(sizeof(int), &mLastEdgeOppositeIndex);
    inFile.Read(sizeof(int), mNumSimplices + 1, mPath);

    inFile.Read(sizeof(Real), 2*mNumVertices, &mVertices[0]);
    inFile.Read(sizeof(Real), 2*mNumVertices, &mSVertices[0]);
    inFile.Read(sizeof(Real), 2, &mMin);
    inFile.Read(sizeof(Real), 2, &mScale);
    inFile.Read(sizeof(Real), 2, &mLineOrigin);
    inFile.Read(sizeof(Real), 2, &mLineDirection); 

    switch (mQueryType)
    {
    case QueryType::Int64:
    {
        mQuery = NEW0 Query2Int64<Real>(mSVertices);
        break;
    }
    case QueryType::Interger:
    {
        mQuery = NEW0 Query2Integer<Real>(mSVertices);
        break;
    }
    case QueryType::Rational:
    {
        mQuery = NEW0 Query2Rational<Real>(mSVertices);
        break;
    }
    case QueryType::Real:
    {
        mQuery = NEW0 Query2<Real>(mSVertices);
        break;
    }
    case QueryType::Filtered:
    {
        mQuery = NEW0 Query2Filtered<Real>(mSVertices, mEpsilon);
        break;
    }
    }

    return true;
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::Save (const System::TChar* filename) const
{
	CoreTools::WriteFileManager outFile{ filename };

    Delaunay<Real>::Save(outFile);

    outFile.Write(sizeof(int), &mNumUniqueVertices);
    outFile.Write(sizeof(int), &mPathLast);
    outFile.Write(sizeof(int), &mLastEdgeV0);
    outFile.Write(sizeof(int), &mLastEdgeV1);
    outFile.Write(sizeof(int), &mLastEdgeOpposite);
    outFile.Write(sizeof(int), &mLastEdgeOppositeIndex);
    outFile.Write(sizeof(int), mNumSimplices + 1, mPath);

    outFile.Write(sizeof(Real), 2*mNumVertices, &mVertices[0]);
    outFile.Write(sizeof(Real), 2*mNumVertices, &mVertices[0]);
    outFile.Write(sizeof(Real), 2, &mMin);
    outFile.Write(sizeof(Real), 2, &mScale);
    outFile.Write(sizeof(Real), 2, &mLineOrigin);
    outFile.Write(sizeof(Real), 2, &mLineDirection);
 
    return true;
}

template <typename Real>
bool Mathematics::Delaunay2<Real>
	::GetContainingTriangle (int i, Triangle*& tri) const
{
	const auto numTriangles = mTriMesh.GetTriangles().size();
    for (auto t = 0u; t < numTriangles; ++t)
    {
        int j;
        for (j = 0; j < 3; ++j)
        {
            const int edge[2] = { msIndex[j][0], msIndex[j][1] };
            if (mQuery->ToLine(i, tri->V[edge[0]], tri->V[edge[1]]) > 0)
            {
                // Point i sees edge <v0,v1> from outside the triangle.
                if (tri->T[j])
                {
                    // Traverse to the triangle sharing the face.
                    tri = tri->T[j];
                    break;
                }
                else
                {
                    // We reached a hull edge, so the point is outside the
                    // hull.  TODO (for WM6):  Once a hull data structure is
                    // in place, return tri->T[j] as the candidate for
                    // starting a search for visible hull edges.
                    return false;
                }
            }

        }

        if (j == 3)
        {
            // The point is inside all four edges, so the point is inside
            // a triangle.
            return true;
        }
    }

    MATHEMATICS_ASSERTION_0(false, "Unexpected termination of GetContainingTriangle\n");
    return false;
}

template <typename Real>
void Mathematics::Delaunay2<Real>
	::GetAndRemoveInsertionPolygon (int i, std::set<Triangle*>& candidates, std::set<OrderedEdgeKey>& boundary)
{
    // Locate the triangles that make up the insertion polygon.
    ETManifoldMesh polygon;
    while (candidates.size() > 0)
    {
        Triangle* tri = *candidates.begin();
        candidates.erase(candidates.begin());

        for (int j = 0; j < 3; ++j)
        {
            Triangle* adj = tri->T[j];
            if (adj && candidates.find(adj) == candidates.end())
            {
                if (mQuery->ToCircumcircle(i, adj->V[0], adj->V[1],  adj->V[2]) <= 0)
                {
                    // Point i is in the circumcircle.
                    candidates.insert(adj);
                }
            }
        }

        polygon.InsertTriangle(tri->V[0], tri->V[1], tri->V[2]);
        mTriMesh.RemoveTriangle(tri->V[0], tri->V[1], tri->V[2]);
    }

    // Get the boundary edges of the insertion polygon.
    const ETManifoldMesh::TMap& tmap = polygon.GetTriangles();
    ETManifoldMesh::TMapCIterator element;
    for (element = tmap.begin(); element != tmap.end(); ++element)
    {
        const ETManifoldMesh::Triangle* tri = element->second;
        for (int j = 0; j < 3; ++j)
        {
            if (!tri->T[j])
            {
                const int edge[2] = { msIndex[j][0], msIndex[j][1] };
                boundary.insert(OrderedEdgeKey(tri->V[edge[0]], tri->V[edge[1]]));
            }
        }
    }
}

template <typename Real>
void Mathematics::Delaunay2<Real>
	::Update (int i)
{
    const ETManifoldMesh::TMap& tmap = mTriMesh.GetTriangles();
    ETManifoldMesh::Triangle* tri = tmap.begin()->second;
    if (GetContainingTriangle(i, tri))
    {
        // The point is inside the convex hull.  The insertion polygon
        // contains only triangles in the current triangulation; the
        // hull does not change.

        // Use a depth-first search for those triangles whose circumcircles
        // contain point i.
        std::set<Triangle*> candidates;
        candidates.insert(tri);

        // Get the boundary of the insertion polygon C that contains the
        // triangles whose circumcircles contain point i.  C contains the
        // point i.
        std::set<OrderedEdgeKey> boundary;
        GetAndRemoveInsertionPolygon(i, candidates, boundary);

        // The insertion polygon consists of the triangles formed by
        // point i and the faces of C.
        std::set<OrderedEdgeKey>::const_iterator key = boundary.begin();
        for (key = boundary.begin(); key != boundary.end(); ++key)
        {
            mTriMesh.InsertTriangle(i, key->GetKey(0), key->GetKey(1));
        }
    }
    else
    {
        // The point is outside the convex hull.  The insertion polygon
        // is formed by point i and any triangles in the current
        // triangulation whose circumcircles contain point i.

        // Locate the convex hull of the triangles.  TODO:  In WM6, maintain
        // a hull data structure that is updated incrementally.
        std::set<OrderedEdgeKey> hull;
        const ETManifoldMesh::TMap& tmap = mTriMesh.GetTriangles();
        ETManifoldMesh::TMapCIterator element;
        for (element = tmap.begin(); element != tmap.end(); ++element)
        {
            const ETManifoldMesh::Triangle* tri = element->second;
            for (int j = 0; j < 3; ++j)
            {
                if (!tri->T[j])
                {
                    const int edge[2] = { msIndex[j][0], msIndex[j][1] };
                    hull.insert(OrderedEdgeKey(tri->V[edge[0]], tri->V[edge[1]]));
                }
            }
        }

        // TODO:  Until the hull change in WM6, for now just iterate over all
        // the hull edges and use the ones visible to point i to locate the
        // insertion polygon.
        const ETManifoldMesh::EMap& edgemap = mTriMesh.GetEdges();
        std::set<Triangle*> candidates;
        std::set<OrderedEdgeKey> visible;
        std::set<OrderedEdgeKey>::const_iterator key;
        for (key = hull.begin(); key != hull.end(); ++key)
        {
            if (mQuery->ToLine(i, key->GetKey(0), key->GetKey(1)) > 0)
            {
                auto iter = edgemap.find(EdgeKey(key->GetKey(0), key->GetKey(1)));
                MATHEMATICS_ASSERTION_0(iter != edgemap.end(), "Unexpected condition\n");
                MATHEMATICS_ASSERTION_0(iter->second->T[1] == 0, "Unexpected condition\n");
                Triangle* adj = iter->second->T[0];
                if (adj && candidates.find(adj) == candidates.end())
                {
                    if (mQuery->ToCircumcircle(i, adj->V[0], adj->V[1], adj->V[2]) <= 0)
                    {
                        // Point i is in the circumcircle.
                        candidates.insert(adj);
                    }
                    else
                    {
                        // Point i is not in the circumcircle but the hull edge
                        // is visible.
                        visible.insert(*key);
                    }
                }
            }
        }

        // Get the boundary of the insertion subpolygon C that contains the
        // triangles whose circumcircles contain point i.
        std::set<OrderedEdgeKey> boundary;
        GetAndRemoveInsertionPolygon(i, candidates, boundary);

        // The insertion polygon P consists of the triangles formed by
        // point i and the back edges of C *and* the visible edges of
        // mTriMesh-C.
        for (key = boundary.begin(); key != boundary.end(); ++key)
        {
            if (mQuery->ToLine(i, key->GetKey(0), key->GetKey(1)) < 0)
            {
                // This is a back edge of the boundary.
                mTriMesh.InsertTriangle(i, key->GetKey(0), key->GetKey(1));
            }
        }
        for (key = visible.begin(); key != visible.end(); ++key)
        {
            mTriMesh.InsertTriangle(i, key->GetKey(1), key->GetKey(0));
        }
    }
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_DETAIL_H