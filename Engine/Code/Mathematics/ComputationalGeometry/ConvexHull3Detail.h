// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:52)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_DETAIL_H

#include "ConvexHull3.h"
#include "Mathematics/Query/Query3Filtered.h"
#include "Mathematics/Query/Query3Int64.h"
#include "Mathematics/Query/Query3Integer.h"
#include "Mathematics/Query/Query3Rational.h"


#include <stack>

template <typename Real>
Mathematics::ConvexHull3<Real>
	::ConvexHull3 (const std::vector<Vector3D<Real> >& vertices, Real epsilon,bool bOwner, QueryType eQueryType)
	:ConvexHull<Real>{ vertices.size(), epsilon, bOwner, eQueryType },mLineOrigin{ Vector3D<Real>::sm_Zero },
	 mLineDirection{ Vector3D<Real>::sm_Zero }, mPlaneOrigin{ Vector3D<Real>::sm_Zero }
{
    mVertices = vertices;
    mPlaneDirection[0] = Vector3D<Real>::sm_Zero;
    mPlaneDirection[1] = Vector3D<Real>::sm_Zero;

    mQuery = 0;

	Vector3DInformation<Real> info{ mVertices, epsilon };
    if (info.GetDimension() == 0)
    {
        // The values of mDimension and mIndices were already initialized by
        // the ConvexHull base class.
        return;
    }

    if (info.GetDimension() == 1)
    {
        // The set is (nearly) collinear.  The caller is responsible for
        // creating a ConvexHull1 object.
        mDimension = 1;
        mLineOrigin = info.GetOrigin();
        mLineDirection = info.GetDirectionX();
        return;
    }

    if (info.GetDimension() == 2)
    {
        // The set is (nearly) coplanar.  The caller is responsible for
        // creating a ConvexHull2 object.
        mDimension = 2;
        mPlaneOrigin = info.GetOrigin();
        mPlaneDirection[0] = info.GetDirectionX();
        mPlaneDirection[1] = info.GetDirectionY();
        return;
    }

    mDimension = 3;

    auto i0 = info.GetMinExtremeIndex();
	auto i1 = info.GetPerpendicularExtremeIndex();
	auto i2 = info.GetTetrahedronExtremeIndex();
	auto i3 = info.GetMaxExtremeIndex();

    mSVertices.resize(mNumVertices);
    int i;

    if (eQueryType != QueryType::Rational && eQueryType != QueryType::Filtered)
    {
        // Transform the vertices to the cube [0,1]^3.
		auto minValue = info.GetMinExtreme();
		auto scale = (static_cast<Real>(1))/info.GetMaxRange();
        for (i = 0; i < mNumVertices; ++i)
        {
            mSVertices[i] = (mVertices[i] - minValue)*scale;
        }

        Real expand;
        if (eQueryType == QueryType::Int64)
        {
            // Scale the vertices to the square [0,2^{20}]^2 to allow use of
            // 64-bit integers.
            expand = (Real)(1 << 20);
            mQuery = NEW0 Query3Int64<Real>(mSVertices);
        }
        else if (eQueryType == QueryType::Interger)
        {
            // Scale the vertices to the square [0,2^{24}]^2 to allow use of
            // Integer.
            expand = (Real)(1 << 24);
            mQuery = NEW0 Query3Integer<Real>(mSVertices);
        }
        else  // eQueryType == Query::QT_REAL
        {
            // No scaling for floating point.
            expand = static_cast<Real>(1);
            mQuery = NEW0 Query3<Real>(mSVertices);
        }

        for (i = 0; i < mNumVertices; ++i)
        {
            mSVertices[i] *= expand;
        }
    }
    else
    {
        // No transformation needed for exact rational arithmetic or filtered
        // predicates.
        memcpy(&mSVertices[0], &mVertices[0], mNumVertices*sizeof(Vector3D<Real>));

        if (eQueryType == QueryType::Rational)
        {
            mQuery = NEW0 Query3Rational<Real>(mSVertices);
        }
        else // eQueryType == Query::QT_FILTERED
        {
            mQuery = NEW0 Query3Filtered<Real>(mSVertices, mEpsilon);
        }
    }

    Triangle* tri0;
    Triangle* tri1;
    Triangle* tri2;
    Triangle* tri3;

    if (info.IsExtremeCCW())
    {
        tri0 = NEW0 Triangle(i0, i1, i3);
        tri1 = NEW0 Triangle(i0, i2, i1);
        tri2 = NEW0 Triangle(i0, i3, i2);
        tri3 = NEW0 Triangle(i1, i2, i3);
        tri0->AttachTo(tri1, tri3, tri2);
        tri1->AttachTo(tri2, tri3, tri0);
        tri2->AttachTo(tri0, tri3, tri1);
        tri3->AttachTo(tri1, tri2, tri0);
    }
    else
    {
        tri0 = NEW0 Triangle(i0, i3, i1);
        tri1 = NEW0 Triangle(i0, i1, i2);
        tri2 = NEW0 Triangle(i0, i2, i3);
        tri3 = NEW0 Triangle(i1, i3, i2);
        tri0->AttachTo(tri2, tri3, tri1);
        tri1->AttachTo(tri0, tri3, tri2);
        tri2->AttachTo(tri1, tri3, tri0);
        tri3->AttachTo(tri0, tri2, tri1);
    }

    mHull.clear();
    mHull.insert(tri0);
    mHull.insert(tri1);
    mHull.insert(tri2);
    mHull.insert(tri3);

    for (i = 0; i < mNumVertices; ++i)
    {
        if (!Update(i))
        {
            DeleteHull();
            return;
        }
    }

    ExtractIndices();
}

template <typename Real>
Mathematics::ConvexHull3<Real>
	::~ConvexHull3 ()
{
    DELETE0(mQuery);
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::ConvexHull3<Real>
	::GetLineOrigin () const
{
    return mLineOrigin;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::ConvexHull3<Real>
	::GetLineDirection () const
{
    return mLineDirection;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::ConvexHull3<Real>
	::GetPlaneOrigin () const
{
    return mPlaneOrigin;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::ConvexHull3<Real>
	::GetPlaneDirection (int i) const
{
    return mPlaneDirection[i];
}

template <typename Real>
Mathematics::ConvexHull1<Real>* Mathematics::ConvexHull3<Real>
	::GetConvexHull1 () const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return 0;
    }

	auto projection = NEW1<Real>(mNumVertices);
    for (int i = 0; i < mNumVertices; ++i)
    {
		auto diff = mVertices[i] - mLineOrigin;
        projection[i] = Vector3DTools<Real>::DotProduct(mLineDirection,diff);
    }

    return NEW0 ConvexHull1<Real>(mNumVertices, projection, mEpsilon, true,mQueryType);
}

template <typename Real>
Mathematics::ConvexHull2<Real>* Mathematics::ConvexHull3<Real>
	::GetConvexHull2 () const
{
    MATHEMATICS_ASSERTION_0(mDimension == 2, "The dimension must be 2\n");
    if (mDimension != 2)
    {
        return 0;
    }

    std::vector<Vector2D<Real> > projection(mNumVertices);
    for (auto i = 0; i < mNumVertices; ++i)
    {
		auto diff = mVertices[i] - mPlaneOrigin;
        projection[i][0] = Vector3DTools<Real>::DotProduct(mPlaneDirection[0],diff);
        projection[i][1] = Vector3DTools<Real>::DotProduct(mPlaneDirection[1],diff);
    }

    return NEW0 ConvexHull2<Real>(projection, mEpsilon, true, mQueryType);
}

template <typename Real>
Mathematics::ConvexHull3<Real>
	::ConvexHull3 (const System::TChar* filename)
	:ConvexHull<Real>{ 0, Math<Real>::GetValue(0), false, QueryType::Real }, mVertices{}, mSVertices{}, mQuery{ 0 }
{
    bool loaded = Load(filename);
    MATHEMATICS_ASSERTION_0(loaded, "Cannot open file %s\n", filename);
    
}

template <typename Real>
bool Mathematics::ConvexHull3<Real>
	::Load (const System::TChar* filename)
{
	CoreTools::ReadFileManager inFile{ filename };

    ConvexHull<Real>::Load(inFile);

    DELETE0(mQuery);
 
    mOwner = true;
    mVertices.resize(mNumVertices);
    mSVertices.resize(mNumVertices);

    inFile.Read(sizeof(Real), 3*mNumVertices, &mVertices[0]);
    inFile.Read(sizeof(Real), 3*mNumVertices, &mSVertices[0]);
    inFile.Read(sizeof(Real), 3, &mLineOrigin);
    inFile.Read(sizeof(Real), 3, &mLineDirection);
    inFile.Read(sizeof(Real), 3, &mPlaneOrigin);
    inFile.Read(sizeof(Real), 6, mPlaneDirection); 

    switch (mQueryType)
    {
    case QueryType::Int64:
    {
        mQuery = NEW0 Query3Int64<Real>(mSVertices);
        break;
    }
    case QueryType::Interger:
    {
        mQuery = NEW0 Query3Integer<Real>(mSVertices);
        break;
    }
    case QueryType::Rational:
    {
        mQuery = NEW0 Query3Rational<Real>(mSVertices);
        break;
    }
    case QueryType::Real:
    {
        mQuery = NEW0 Query3<Real>(mSVertices);
        break;
    }
    case QueryType::Filtered:
    {
        mQuery = NEW0 Query3Filtered<Real>(mSVertices,
            mEpsilon);
        break;
    }
    }

    return true;
}

template <typename Real>
bool Mathematics::ConvexHull3<Real>
	::Save (const System::TChar* filename) const
{
	CoreTools::WriteFileManager outFile{ filename };
    ConvexHull<Real>::Save(outFile);

    outFile.Write(sizeof(Real), 3*mNumVertices, &mVertices[0]);
    outFile.Write(sizeof(Real), 3*mNumVertices, &mSVertices[0]);
    outFile.Write(sizeof(Real), 3, &mLineOrigin);
    outFile.Write(sizeof(Real), 3, &mLineDirection);
    outFile.Write(sizeof(Real), 3, &mPlaneOrigin);
    outFile.Write(sizeof(Real), 6, mPlaneDirection);
 
    return true;
}

template <typename Real>
bool Mathematics::ConvexHull3<Real>
	::Update (int i)
{
    // Locate a triangle visible to the input point (if possible).
    Triangle* visible = 0;
    Triangle* tri;
    auto iter = mHull.begin();
	auto end = mHull.end();
    for (; iter != end; ++iter)
    {
        tri = *iter;
        if (tri->GetSign(i, mQuery) > 0)
        {
            visible = tri;
            break;
        }
    }

    if (!visible)
    {
        // The point is inside the current hull; nothing to do.
        return true;
    }

    // Locate and remove the visible triangles.
    std::stack<Triangle*> visibleSet;
    std::map<int,TerminatorData> terminator;
    visibleSet.push(visible);
    visible->OnStack = true;
    int j, v0, v1;
    while (!visibleSet.empty())
    {
        tri = visibleSet.top();
        visibleSet.pop();
        tri->OnStack = false;
        for (j = 0; j < 3; ++j)
        {
            Triangle* adj = tri->Adj[j];
            if (adj)
            {
                // Detach triangle and adjacent triangle from each other.
                int nullIndex = tri->DetachFrom(j, adj);

                if (adj->GetSign(i, mQuery) > 0)
                {
                    if (!adj->OnStack)
                    {
                        // Adjacent triangle is visible.
                        visibleSet.push(adj);
                        adj->OnStack = true;
                    }
                }
                else
                {
                    // Adjacent triangle is invisible.
                    v0 = tri->V[j];
                    v1 = tri->V[(j+1)%3];
                    terminator[v0] = TerminatorData(v0, v1, nullIndex, adj);
                }
            }
        }
        mHull.erase(tri);
        DELETE0(tri);
    }

    // Insert the new edges formed by the input point and the terminator
    // between visible and invisible triangles.
    int size = (int)terminator.size();
    MATHEMATICS_ASSERTION_0(size >= 3, "Terminator must be at least a triangle\n");
	auto edge = terminator.begin();
    v0 = edge->second.V[0];
    v1 = edge->second.V[1];
    tri = NEW0 Triangle(i, v0, v1);
    mHull.insert(tri);

    // Save information for linking first/last inserted new triangles.
	auto saveV0 = edge->second.V[0];
    Triangle* saveTri = tri;

    // Establish adjacency links across terminator edge.
    tri->Adj[1] = edge->second.T;
    edge->second.T->Adj[edge->second.NullIndex] = tri;
    for (j = 1; j < size; ++j)
    {
        edge = terminator.find(v1);
        MATHEMATICS_ASSERTION_0(edge != terminator.end(), "Unexpected condition\n");
        v0 = v1;
        v1 = edge->second.V[1];
        Triangle* next = NEW0 Triangle(i, v0, v1);
        mHull.insert(next);

        // Establish adjacency links across terminator edge.
        next->Adj[1] = edge->second.T;
        edge->second.T->Adj[edge->second.NullIndex] = next;

        // Establish adjacency links with previously inserted triangle.
        next->Adj[0] = tri;
        tri->Adj[2] = next;

        tri = next;
    }
    MATHEMATICS_ASSERTION_0(v1 == saveV0, "Expecting initial vertex\n");
    

    // Establish adjacency links between first/last triangles.
    saveTri->Adj[0] = tri;
    tri->Adj[2] = saveTri;
    return true;
}

template <typename Real>
void Mathematics::ConvexHull3<Real>
	::ExtractIndices ()
{
    mNumSimplices = (int)mHull.size();
    mIndices = NEW1<int>(3*mNumSimplices);

	auto iter = mHull.begin();
	auto end = mHull.end();
    for (auto i = 0; iter != end; ++iter)
    {
		auto tri = *iter;
        for (int j = 0; j < 3; ++j, ++i)
        {
            mIndices[i] = tri->V[j];
        }
        DELETE0(tri);
    }
    mHull.clear();
}

template <typename Real>
void Mathematics::ConvexHull3<Real>
	::DeleteHull ()
{
	auto iter = mHull.begin();
	auto end = mHull.end();
    for (/**/; iter != end; ++iter)
    {
        Triangle* tri = *iter;
        DELETE0(tri);
    }
    mHull.clear();
}

// ConvexHull3::Triangle

template <typename Real>
Mathematics::ConvexHull3<Real>::Triangle
	::Triangle (int v0, int v1, int v2)
	:Sign{ 0 }, Time{ -1 }, OnStack{ false }
{
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    Adj[0] = 0;
    Adj[1] = 0;
    Adj[2] = 0;
}

template <typename Real>
int Mathematics::ConvexHull3<Real>::Triangle
	::GetSign (int i, const Query3<Real>* query)
{
    if (i != Time)
    {
        Time = i;
        Sign = query->ToPlane(i, V[0], V[1], V[2]);
    }

    return Sign;
}

template <typename Real>
void Mathematics::ConvexHull3<Real>::Triangle
	::AttachTo (Triangle* adj0, Triangle* adj1, Triangle* adj2)
{
    // assert:  The input adjacent triangles are correctly ordered.
    Adj[0] = adj0;
    Adj[1] = adj1;
    Adj[2] = adj2;
}

template <typename Real>
int Mathematics::ConvexHull3<Real>::Triangle
	::DetachFrom (int adjIndex, Triangle* adj)
{
    MATHEMATICS_ASSERTION_0(0 <= adjIndex && adjIndex < 3 && Adj[adjIndex] == adj,    "Invalid inputs\n");

    Adj[adjIndex] = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (adj->Adj[i] == this)
        {
            adj->Adj[i] = 0;
            return i;
        }
    }
    return -1;
}

// ConvexHull3::TerminatorData

template <typename Real>
Mathematics::ConvexHull3<Real>::TerminatorData
	::TerminatorData (int v0, int v1,int nullIndex, Triangle* tri)
	: NullIndex{ nullIndex }, T{ tri }
{
    V[0] = v0;
    V[1] = v1;
} 

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_DETAIL_H