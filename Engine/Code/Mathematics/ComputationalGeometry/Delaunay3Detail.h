// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 15:01)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_DETAIL_H

#include "Delaunay3.h"
#include "Delaunay2.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"  
#include "System/Helper/UnusedMacro.h"

template <typename Real>
Mathematics::Delaunay3<Real>
	::Delaunay3 (const std::vector<Vector3D<Real> >& vertices,Real epsilon, bool owner, QueryType queryType)
	:Delaunay<Real>{ vertices.size(), epsilon, owner, queryType }, mVertices{ vertices }, mNumUniqueVertices{ 0 },
	 mSVertices{}, mQuery{ 0 }, mLineOrigin{ Vector3D<Real>::sm_Zero }, mLineDirection{ Vector3D<Real>::sm_Zero },
	 mPlaneOrigin{ Vector3D<Real>::sm_Zero }, mPathLast{ -1 }, mPath{ 0 }, mLastFaceV0{ -1 },
     mLastFaceV1{ -1 },  mLastFaceV2{ -1 }, mLastFaceOpposite{ -1 }, mLastFaceOppositeIndex{ -1 }
{
    mPlaneDirection[0] = Vector3D<Real>::sm_Zero;
    mPlaneDirection[1] = Vector3D<Real>::sm_Zero;

	Vector3DInformation<Real> info{ mVertices, mEpsilon };
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

    if (info.GetDimension() == 2)
    {
        // The set is (nearly) coplanar.  The caller is responsible for
        // creating a Delaunay2 object.
        mDimension = 2;
        mPlaneOrigin = info.GetOrigin();
        mPlaneDirection[0] = info.GetDirectionX();
        mPlaneDirection[1] = info.GetDirectionY();
        return;
    }

    mDimension = 3;

    // Allocate storage for the input vertices.
    mSVertices.resize(mNumVertices);
    int i;

    if (queryType != QueryType::Rational && queryType != QueryType::Filtered)
    {
        // Transform the vertices to the cube [0,1]^3.
        mMin = info.GetMinExtreme();
        mScale = ((Real)1)/info.GetMaxRange();
        for (i = 0; i < mNumVertices; ++i)
        {
            mSVertices[i] = (mVertices[i] - mMin)*mScale;
        }

        Real expand;
        if (queryType == QueryType::Int64)
        {
            // Scale the vertices to the cube [0,2^{10}]^3 to allow use of
            // 64-bit integers for tetrahedralization.
            expand = (Real)(1 << 10);
            mQuery = NEW0 Query3Int64<Real>(mSVertices);
        }
        else if (queryType == QueryType::Interger)
        {
            // Scale the vertices to the cube [0,2^{20}]^3 to get more
            // precision for TInteger than for 64-bit integers for
            // tetrahedralization.
            expand = (Real)(1 << 20);
            mQuery = NEW0 Query3Integer<Real>(mSVertices);
        }
        else // queryType == Query::QT_REAL
        {
            // No scaling for floating point.
            expand = (Real)1;
            mQuery = NEW0 Query3<Real>(mSVertices);
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
        mMin = Vector3D<Real>::sm_Zero;
        mScale = (Real)1;
        memcpy(&mSVertices[0], &mVertices[0], mNumVertices*sizeof(Vector3D<Real>));

        if (queryType == QueryType::Rational)
        {
            mQuery = NEW0 Query3Rational<Real>(mSVertices);
        }
        else // queryType == Query::QT_FILTERED
        {
            mQuery = NEW0 Query3Filtered<Real>(mSVertices,mEpsilon);
        }
    }

    // Insert the (nondegenerate) tetrahedron constructed by the call to
    // GetInformation. This is necessary for the circumsphere-visibility
    // algorithm to work correctly.
	int mExtreme[4] {info.GetMinExtremeIndex(),info.GetPerpendicularExtremeIndex(),info.GetTetrahedronExtremeIndex(),info.GetMaxExtremeIndex()};
	
    if (!info.IsExtremeCCW())
    {
        std::swap(mExtreme[2], mExtreme[3]);
    }
    mTetraMesh.Insert(mExtreme[0], mExtreme[1], mExtreme[2],mExtreme[3]);

    // Incrementally update the tetrahedralization.  The set of processed
    // points is maintained to eliminate duplicates, either in the original
    // input points or in the points obtained by snap rounding.
    std::set<Vector3D<Real> > processed;
    for (i = 0; i < 4; ++i)
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

    // Assign integer values to the tetrahedra for use by the caller.
    std::map<Tetrahedron*,int> permute;
    i = -1;
    permute[(Tetrahedron*)0] = i++;
    const TSManifoldMesh::SMap& smap = mTetraMesh.GetTetrahedra();
    TSManifoldMesh::SMapCIterator element;
    for (element = smap.begin(); element != smap.end(); ++element)
    {
        permute[element->second] = i++;
    }

    // Put Delaunay tetrahedra into an array (vertices and adjacency info).
    mNumSimplices = boost::numeric_cast<int>(mTetraMesh.GetTetrahedra().size());
    if (mNumSimplices > 0)
    {
        mIndices = NEW1<int>(4*mNumSimplices);
        mAdjacencies = NEW1<int>(4*mNumSimplices);
        i = 0;
        for (element = smap.begin(); element != smap.end(); ++element)
        {
            const TSManifoldMesh::Tetrahedron* tetra = element->second;
            for (int j = 0; j < 4; ++j, ++i)
            {
                mIndices[i] = tetra->V[j];
                mAdjacencies[i] = permute[tetra->S[j]];
            }
        }
        MATHEMATICS_ASSERTION_0(i == 4*mNumSimplices, "Unexpected mismatch\n");

        mPathLast = -1;
        mPath = NEW1<int>(mNumSimplices + 1);
        memset(mPath, 0, (mNumSimplices + 1)*sizeof(int));
    }
}

template <typename Real>
Mathematics::Delaunay3<Real>
	::~Delaunay3 ()
{
    DELETE0(mQuery);
    DELETE1(mPath);   
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::Delaunay3<Real>
	::GetVertices () const
{
    return &mVertices[0];
}

template <typename Real>
int Mathematics::Delaunay3<Real>
	::GetNumUniqueVertices () const
{
    return mNumUniqueVertices;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::Delaunay3<Real>
	::GetLineOrigin () const
{
    return mLineOrigin;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::Delaunay3<Real>
	::GetLineDirection () const
{
    return mLineDirection;
}

template <typename Real>
Mathematics::Delaunay1<Real>* Mathematics::Delaunay3<Real>
	::GetDelaunay1 () const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return 0;
    }

    Real* projection = NEW1<Real>(mNumVertices);
    for (auto i = 0; i < mNumVertices; ++i)
    {
		auto diff = mVertices[i] - mLineOrigin;
        projection[i] = Vector3DTools<Real>::DotProduct(mLineDirection,diff);
    }

    return NEW0 Delaunay1<Real>(mNumVertices, projection, mEpsilon, true,mQueryType);
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::Delaunay3<Real>
	::GetPlaneOrigin () const
{
    return mPlaneOrigin;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::Delaunay3<Real>
	::GetPlaneDirection (int i) const
{
    return mPlaneDirection[i];
}

template <typename Real>
Mathematics::Delaunay2<Real>* Mathematics::Delaunay3<Real>
	::GetDelaunay2 () const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return 0;
    }

   std::vector<Vector2D<Real> > projection(mNumVertices);
    for (int i = 0; i < mNumVertices; ++i)
    {
		auto diff = mVertices[i] - mPlaneOrigin;
        projection[i][0] = Vector3DTools<Real>::DotProduct(mPlaneDirection[0],diff);
        projection[i][1] = Vector3DTools<Real>::DotProduct(mPlaneDirection[1],diff);
    }

    return NEW0 Delaunay2<Real>(projection, mEpsilon, true, mQueryType);
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::GetHull (int& numTriangles, int*& indices) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 3, "The dimension must be 3\n");
    if (mDimension != 3)
    {
        return false;
    }

    numTriangles = 0;
    indices = 0;

    // Count the number of triangles that are not shared by two tetrahedra.
    int i, numAdjacent = 4*mNumSimplices;
    for (i = 0; i < numAdjacent; ++i)
    {
        if (mAdjacencies[i] == -1)
        {
            numTriangles++;
        }
    }
    MATHEMATICS_ASSERTION_0(numTriangles > 0, "There must be at least one tetrahedron\n");
    if (numTriangles == 0)
    {
        return false;
    }

    // Enumerate the triangles.  The prototypical case is the single
    // tetrahedron V[0] = (0,0,0), V[1] = (1,0,0), V[2] = (0,1,0), and
    // V[3] = (0,0,1) with no adjacent tetrahedra.  The mIndices[] array
    // is <0,1,2,3>.
    //   i = 0, face = 0:
    //     skip index 0, <x,1,2,3>, no swap, triangle = <1,2,3>
    //   i = 1, face = 1:
    //     skip index 1, <0,x,2,3>, swap,    triangle = <0,3,2>
    //   i = 2, face = 2:
    //     skip index 2, <0,1,x,3>, no swap, triangle = <0,1,3>
    //   i = 3, face = 3:
    //     skip index 3, <0,1,2,x>, swap,    triangle = <0,2,1>
    // To guarantee counterclockwise order of triangles when viewed outside
    // the tetrahedron, the swap of the last two indices occurs when
    // iFace is an odd number:  (iFace % 2) != 0
    indices = NEW1<int>(3*numTriangles);
	auto currentIndex = indices;
    for (i = 0; i < numAdjacent; ++i)
    {
        if (mAdjacencies[i] == -1)
        {
            int tetra = i/4, face = i%4;
            for (auto j = 0; j < 4; ++j)
            {
                if (j != face)
                {
                    *currentIndex++ = mIndices[4*tetra + j];
                }
            }
            if ((face % 2) != 0)
            {
                int save = *(currentIndex-1);
                *(currentIndex-1) = *(currentIndex-2);
                *(currentIndex-2) = save;
            }
        }
    }

    return true;
}

template <typename Real>
int Mathematics::Delaunay3<Real>
	::GetContainingTetrahedron (const Vector3D<Real>& p) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 3, "The dimension must be 3\n");
    if (mDimension != 3)
    {
        return -1;
    }

    // Convert to scaled coordinates.
	auto scP = (p - mMin)*mScale;

    // Start at first tetrahedron in mesh.
	auto index = (mPathLast >= 0 ? mPath[mPathLast] : 0);
    mPathLast = -1;
    mLastFaceV0 = -1;
    mLastFaceV1 = -1;
    mLastFaceV2 = -1;
    mLastFaceOpposite = -1;
    mLastFaceOppositeIndex = -1;

    // Use tetrahedron faces as binary separating planes.
    for (auto i = 0; i < mNumSimplices; ++i)
    {
        mPath[++mPathLast] = index;

        int* vertices = &mIndices[4*index];

        // <V1,V2,V3> counterclockwise when viewed outside tetrahedron.
        if (mQuery->ToPlane(scP, vertices[1], vertices[2], vertices[3]) > 0)
        {
            index = mAdjacencies[4*index];
            if (index == -1)
            {
                mLastFaceV0 = vertices[1];
                mLastFaceV1 = vertices[2];
                mLastFaceV2 = vertices[3];
                mLastFaceOpposite = vertices[0];
                mLastFaceOppositeIndex = 0;
                return -1;
            }
            continue;
        }

        // <V0,V3,V2> counterclockwise when viewed outside tetrahedron.
        if (mQuery->ToPlane(scP, vertices[0], vertices[2], vertices[3]) < 0)
        {
            index = mAdjacencies[4*index + 1];
            if (index == -1)
            {
                mLastFaceV0 = vertices[0];
                mLastFaceV1 = vertices[2];
                mLastFaceV2 = vertices[3];
                mLastFaceOpposite = vertices[1];
                mLastFaceOppositeIndex = 1;
                return -1;
            }
            continue;
        }

        // <V0,V1,V3> counterclockwise when viewed outside tetrahedron.
        if (mQuery->ToPlane(scP, vertices[0], vertices[1], vertices[3]) > 0)
        {
            index = mAdjacencies[4*index + 2];
            if (index == -1)
            {
                mLastFaceV0 = vertices[0];
                mLastFaceV1 = vertices[1];
                mLastFaceV2 = vertices[3];
                mLastFaceOpposite = vertices[2];
                mLastFaceOppositeIndex = 2;
                return -1;
            }
            continue;
        }

        // <V0,V2,V1> counterclockwise when viewed outside tetrahedron.
        if (mQuery->ToPlane(scP, vertices[0], vertices[1], vertices[2]) < 0)
        {
            index = mAdjacencies[4*index + 3];
            if (index == -1)
            {
                mLastFaceV0 = vertices[0];
                mLastFaceV1 = vertices[1];
                mLastFaceV2 = vertices[2];
                mLastFaceOpposite = vertices[3];
                mLastFaceOppositeIndex = 3;
                return -1;
            }
            continue;
        }

        mLastFaceV0 = -1;
        mLastFaceV1 = -1;
        mLastFaceV2 = -1;
        mLastFaceOppositeIndex = -1;
        return index;
    }

    return -1;
}

template <typename Real>
int Mathematics::Delaunay3<Real>
	::GetPathLast () const
{
    return mPathLast;
}

template <typename Real>
const int* Mathematics::Delaunay3<Real>
	::GetPath () const
{
    return mPath;
}

template <typename Real>
int Mathematics::Delaunay3<Real>
	::GetLastFace (int& v0, int& v1, int& v2, int& v3) const
{
    v0 = mLastFaceV0;
    v1 = mLastFaceV1;
    v2 = mLastFaceV2;
    v3 = mLastFaceOpposite;
    return mLastFaceOppositeIndex;
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::GetVertexSet (int i, Vector3D<Real> vertices[4]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 3, "The dimension must be 3\n");
    if (mDimension != 3)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        vertices[0] = mVertices[mIndices[4*i  ]];
        vertices[1] = mVertices[mIndices[4*i + 1]];
        vertices[2] = mVertices[mIndices[4*i + 2]];
        vertices[3] = mVertices[mIndices[4*i + 3]];
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::GetIndexSet (int i, int indices[4]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 3, "The dimension must be 3\n");
    if (mDimension != 3)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        indices[0] = mIndices[4*i  ];
        indices[1] = mIndices[4*i + 1];
        indices[2] = mIndices[4*i + 2];
        indices[3] = mIndices[4*i + 3];
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::GetAdjacentSet (int i, int adjacencies[4]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 3, "The dimension must be 3\n");
    if (mDimension != 3)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        adjacencies[0] = mAdjacencies[4*i  ];
        adjacencies[1] = mAdjacencies[4*i + 1];
        adjacencies[2] = mAdjacencies[4*i + 2];
        adjacencies[3] = mAdjacencies[4*i + 3];
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::GetBarycentricSet (int i, const Vector3D<Real>& p, Real bary[4]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 3, "The dimension must be 3\n");
    if (mDimension != 3)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
		auto v0 = mVertices[mIndices[4*i  ]];
		auto v1 = mVertices[mIndices[4*i + 1]];
		auto v2 = mVertices[mIndices[4*i + 2]];
		auto v3 = mVertices[mIndices[4*i + 3]];
		auto barycentricCoordinates = p.GetBarycentrics(v0, v1, v2, v3);
		for (int i = 0;i < 4;++i)
		{
			bary[i] = barycentricCoordinates[i];
		}
		
        return true;
    }

    return false;
}

template <typename Real>
Mathematics::Delaunay3<Real>
	::Delaunay3 (const System::TChar* filename)
	:Delaunay<Real>{ 0, Real{}, false, QueryType::Real }, mVertices{ 0 }, mSVertices{ 0 }, mQuery{ 0 }, mPath{ 0 }
{
    bool loaded = Load(filename);
    MATHEMATICS_ASSERTION_0(loaded, "Cannot open file %s\n", filename);
    SYSTEM_UNUSED_ARG(loaded);
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
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
    inFile.Read(sizeof(int), &mLastFaceV0);
    inFile.Read(sizeof(int), &mLastFaceV1);
    inFile.Read(sizeof(int), &mLastFaceV2);
    inFile.Read(sizeof(int), &mLastFaceOpposite);
    inFile.Read(sizeof(int), &mLastFaceOppositeIndex);
    inFile.Read(sizeof(int), mNumSimplices + 1, mPath);

    inFile.Read(sizeof(Real), 3*mNumVertices, &mVertices[0]);
    inFile.Read(sizeof(Real), 3*mNumVertices, &mSVertices[0]);
    inFile.Read(sizeof(Real), 3, &mMin);
    inFile.Read(sizeof(Real), 3, &mScale);
    inFile.Read(sizeof(Real), 3, &mLineOrigin);
    inFile.Read(sizeof(Real), 3, &mLineDirection);
    inFile.Read(sizeof(Real), 3, &mPlaneOrigin);
    inFile.Read(sizeof(Real), 6, mPlaneDirection);

    switch (mQueryType)
    {
    case QueryType::Int64:
    {
        mQuery = NEW0 Query3Int64<Real>( mSVertices);
        break;
    }
    case QueryType::Interger:
    {
        mQuery = NEW0 Query3Integer<Real>( mSVertices);
        break;
    }
    case QueryType::Rational:
    {
        mQuery = NEW0 Query3Rational<Real>( mSVertices);
        break;
    }
    case QueryType::Real:
    {
        mQuery = NEW0 Query3<Real>( mSVertices);
        break;
    }
    case QueryType::Filtered:
    {
        mQuery = NEW0 Query3Filtered<Real>( mSVertices,
            mEpsilon);
        break;
    }
    }

    return true;
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::Save (const System::TChar* filename) const
{
	CoreTools::WriteFileManager outFile{ filename };

    Delaunay<Real>::Save(outFile);

    outFile.Write(sizeof(int), &mNumUniqueVertices);
    outFile.Write(sizeof(int), &mPathLast);
    outFile.Write(sizeof(int), &mLastFaceV0);
    outFile.Write(sizeof(int), &mLastFaceV1);
    outFile.Write(sizeof(int), &mLastFaceV2);
    outFile.Write(sizeof(int), &mLastFaceOpposite);
    outFile.Write(sizeof(int), &mLastFaceOpposite);
    outFile.Write(sizeof(int), mNumSimplices + 1 ,mPath);

    outFile.Write(sizeof(Real), 3*mNumVertices, &mVertices[0]);
    outFile.Write(sizeof(Real), 3*mNumVertices, &mSVertices[0]);
    outFile.Write(sizeof(Real), 3, &mMin);
    outFile.Write(sizeof(Real), 3, &mScale);
    outFile.Write(sizeof(Real), 3, &mLineOrigin);
    outFile.Write(sizeof(Real), 3, &mLineDirection);
    outFile.Write(sizeof(Real), 3, &mPlaneOrigin);
    outFile.Write(sizeof(Real), 6, mPlaneDirection);

    return true;
}

template <typename Real>
bool Mathematics::Delaunay3<Real>
	::GetContainingTetrahedron (int i, Tetrahedron*& tetra) const
{
	const auto  numTetra = mTetraMesh.GetTetrahedra().size();
    for (auto t = 0u; t < numTetra; ++t)
    {
        int j;
        for (j = 0; j < 4; ++j)
        {
            const int face[3]{ TetrahedronKey::oppositeFace[j][0], TetrahedronKey::oppositeFace[j][1], TetrahedronKey::oppositeFace[j][2] };
            if (mQuery->ToPlane(i, tetra->V[face[0]], tetra->V[face[1]],tetra->V[face[2]]) > 0)
            {
                // Point i sees face <v0,v1,v2> from outside the tetrahedron.
                if (tetra->S[j])
                {
                    // Traverse to the tetrahedron sharing the face.
                    tetra = tetra->S[j];
                    break;
                }
                else
                {
                    // We reached a hull face, so the point is outside the
                    // hull.  TODO (for WM6):  Once a hull data structure is
                    // in place, return tetra->S[j] as the candidate for
                    // starting a search for visible hull faces.
                    return false;
                }
            }

        }

        if (j == 4)
        {
            // The point is inside all four faces, so the point is inside
            // a tetrahedron.
            return true;
        }
    }

    MATHEMATICS_ASSERTION_0(false, "Unexpected termination of GetContainingTetrahedron\n");
    return false;
}

template <typename Real>
void Mathematics::Delaunay3<Real>
	::GetAndRemoveInsertionPolyhedron (int i, std::set<Tetrahedron*>& candidates, std::set<TriangleKey>& boundary)
{
    // Locate the tetrahedra that make up the insertion polyhedron.
    TSManifoldMesh polyhedron;
    while (candidates.size() > 0)
    {
		auto tetra = *candidates.begin();
        candidates.erase(candidates.begin());

        for (auto j = 0; j < 4; ++j)
        {
			auto adj = tetra->S[j];
            if (adj && candidates.find(adj) == candidates.end())
            {
                if (mQuery->ToCircumsphere(i, adj->V[0], adj->V[1], adj->V[2],  adj->V[3]) <= 0)
                {
                    // Point i is in the circumsphere.
                    candidates.insert(adj);
                }
            }
        }

        polyhedron.Insert(tetra->V[0], tetra->V[1], tetra->V[2], tetra->V[3]);
        mTetraMesh.Remove(tetra->V[0], tetra->V[1], tetra->V[2], tetra->V[3]);
    }

    // Get the boundary triangles of the insertion polyhedron.
	const auto& smap = polyhedron.GetTetrahedra();
    TSManifoldMesh::SMapCIterator element;
	for (element = smap.begin(); element != smap.end(); ++element)
    {
        const auto* tetra = element->second;
        for (int j = 0; j < 4; ++j)
        {
            if (!tetra->S[j])
            {
                const int face[3]{ TetrahedronKey::oppositeFace[j][0],TetrahedronKey::oppositeFace[j][1],TetrahedronKey::oppositeFace[j][2] };
                boundary.insert(TriangleKey(tetra->V[face[0]],tetra->V[face[1]], tetra->V[face[2]]));
            }
        }
    }
}

template <typename Real>
void Mathematics::Delaunay3<Real>
	::Update (int i)
{
    const auto& smap = mTetraMesh.GetTetrahedra();
	auto* tetra = smap.begin()->second;
    if (GetContainingTetrahedron(i, tetra))
    {
        // The point is inside the convex hull.  The insertion polyhedron
        // contains only tetrahedra in the current tetrahedralization; the
        // hull does not change.

        // Use a depth-first search for those tetrahedra whose circumspheres
        // contain point i.
        std::set<Tetrahedron*> candidates;
        candidates.insert(tetra);

        // Get the boundary of the insertion polyhedron C that contains the
        // tetrahedra whose circumspheres contain point i.  C contains the
        // point i.
        std::set<TriangleKey> boundary;
        GetAndRemoveInsertionPolyhedron(i, candidates, boundary);

        // The insertion polyhedron consists of the tetrahedra formed by
        // point i and the faces of C.
        std::set<TriangleKey>::const_iterator key;
        for (key = boundary.begin(); key != boundary.end(); ++key)
        {
            mTetraMesh.Insert(i, key->GetKey(0), key->GetKey(1), key->GetKey(2));
        }
    }
    else
    {
        // The point is outside the convex hull.  The insertion polyhedron
        // is formed by point i and any tetrahedra in the current
        // tetrahedralization whose circumspheres contain point i.

        // Locate the convex hull of the tetrahedra.  TODO:  In WM6, maintain
        // a hull data structure that is updated incrementally.
        std::set<TriangleKey> hull;
        const auto& smap = mTetraMesh.GetTetrahedra();
        TSManifoldMesh::SMapCIterator element;
        for (element = smap.begin(); element != smap.end(); ++element)
        {
            const auto* tetra = element->second;
            for (int j = 0; j < 4; ++j)
            {
                if (!tetra->S[j])
                {
                    const int face[3]{ TetrahedronKey::oppositeFace[j][0],TetrahedronKey::oppositeFace[j][1], TetrahedronKey::oppositeFace[j][2] };
                    hull.insert(TriangleKey(tetra->V[face[0]],tetra->V[face[1]], tetra->V[face[2]]));
                }
            }
        }

        // TODO:  Until the hull change in WM6, for now just iterate over all
        // the hull faces and use the ones visible to point i to locate the
        // insertion polyhedron.
        const auto& trimap = mTetraMesh.GetTriangles();
        std::set<Tetrahedron*> candidates;
        std::set<TriangleKey> visible;
        std::set<TriangleKey>::const_iterator key;
        for (key = hull.begin(); key != hull.end(); ++key)
        {
            if (mQuery->ToPlane(i,key->GetKey(0), key->GetKey(1), key->GetKey(2)) > 0)
            {
				auto iter = trimap.find(UnorderedTriangleKey(key->GetKey(0),key->GetKey(1), key->GetKey(2)));
                MATHEMATICS_ASSERTION_0(iter != trimap.end(), "Unexpected condition\n");
                MATHEMATICS_ASSERTION_0(iter->second->T[1] == 0, "Unexpected condition\n");
				auto adj = iter->second->T[0];
                if (adj && candidates.find(adj) == candidates.end())
                {
                    if (mQuery->ToCircumsphere(i, adj->V[0], adj->V[1],adj->V[2], adj->V[3]) <= 0)
                    {
                        // Point i is in the circumsphere.
                        candidates.insert(adj);
                    }
                    else
                    {
                        // Point i is not in the circumsphere but the hull face
                        // is visible.
                        visible.insert(*key);
                    }
                }
            }
        }

        // Get the boundary of the insertion subpolyhedron C that contains the
        // tetrahedra whose circumspheres contain point i.
        std::set<TriangleKey> boundary;
        GetAndRemoveInsertionPolyhedron(i, candidates, boundary);

        // The insertion polyhedron P consists of the tetrahedra formed by
        // point i and the back faces of C *and* the visible faces of
        // mTetraMesh-C.
        for (key = boundary.begin(); key != boundary.end(); ++key)
        {
            if (mQuery->ToPlane(i, key->GetKey(0), key->GetKey(1), key->GetKey(2)) < 0)
            {
                // This is a back face of the boundary.
                mTetraMesh.Insert(i, key->GetKey(0), key->GetKey(1), key->GetKey(2));
            }
        }
        for (key = visible.begin(); key != visible.end(); ++key)
        {
            mTetraMesh.Insert(i, key->GetKey(0),key->GetKey(2),key->GetKey(1));
        }
    }
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_DETAIL_H