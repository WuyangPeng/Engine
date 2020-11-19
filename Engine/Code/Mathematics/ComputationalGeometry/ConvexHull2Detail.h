// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:47)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_DETAIL_H

#include "ConvexHull2.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"


template <typename Real>
Mathematics::ConvexHull2<Real>
	::ConvexHull2(const std::vector<Vector2D<Real> >& vertices,Real epsilon, bool owner, QueryType queryType)
	:ConvexHull<Real>{ vertices.size(), epsilon, owner, queryType }, mVertices{ vertices }, mSVertices{}, mQuery{ 0 },
	 mLineOrigin{ Vector2D<Real>::sm_Zero }, mLineDirection{ Vector2D<Real>::sm_Zero }
{ 
	Vector2DInformation<Real> info{ mVertices, epsilon };
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

    mDimension = 2;

    auto i0 = info.GetMinExtremeIndex();
	auto i1 = info.GetPerpendicularExtremeIndex();
	auto i2 = info.GetMaxExtremeIndex();

    mSVertices.resize(mNumVertices);
    int i;

	if (queryType != QueryType::Rational && queryType != QueryType::Filtered)
    {
        // Transform the vertices to the square [0,1]^2.
		auto minValue = info.GetMinExtreme();
		auto scale = (Math::GetValue(1))/info.GetMaxRange();
        for (i = 0; i < mNumVertices; ++i)
        {
            mSVertices[i] = (mVertices[i] - minValue)*scale;
        }

        Real expand;
		if (queryType == QueryType::Int64)
        {
            // Scale the vertices to the square [0,2^{20}]^2 to allow use of
            // 64-bit integers.
            expand = (Real)(1 << 20);
            mQuery = NEW0 Query2Int64<Real>(mSVertices);
        }
		else if (queryType == QueryType::Interger)
        {
            // Scale the vertices to the square [0,2^{24}]^2 to allow use of
            // Integer.
            expand = (Real)(1 << 24);
			mQuery = NEW0 Query2Integer<Real>(mSVertices);
        }
        else  // queryType == Query::QT_REAL
        {
            // No scaling for floating point.
            expand = Math::GetValue(1);
			mQuery = NEW0 Query2<Real>(mSVertices);
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

    Edge* edge0;
    Edge* edge1;
    Edge* edge2;

    if (info.IsExtremeCCW())
    {
        edge0 = NEW0 Edge(i0, i1);
		edge1 = NEW0 Edge(i1, i2);
		edge2 = NEW0 Edge(i2, i0);
    }
    else
    {
		edge0 = NEW0 Edge(i0, i2);
		edge1 = NEW0 Edge(i2, i1);
		edge2 = NEW0 Edge(i1, i0);
    }

    edge0->Insert(edge2, edge1);
    edge1->Insert(edge0, edge2);
    edge2->Insert(edge1, edge0);

    Edge* hull = edge0;
    for (i = 0; i < mNumVertices; ++i)
    {
        if (!Update(hull, i))
        {
            hull->DeleteAll();
            return;
        }
    }

    hull->GetIndices(mNumSimplices, mIndices);
    hull->DeleteAll();
}

template <typename Real>
Mathematics::ConvexHull2<Real>
	::~ConvexHull2()
{
   	DELETE0(mQuery);
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::ConvexHull2<Real>
	::GetLineOrigin() const
{
    return mLineOrigin;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::ConvexHull2<Real>
	::GetLineDirection() const
{
    return mLineDirection;
}

template <typename Real>
Mathematics::ConvexHull1<Real>* Mathematics::ConvexHull2<Real>
	::GetConvexHull1() const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return 0;
    }

    auto projection = NEW1<Real>(mNumVertices);
    for (auto i = 0; i < mNumVertices; ++i)
    {
		auto diff = mVertices[i] - mLineOrigin;
		projection[i] = Vector2DTools<Real>::DotProduct(mLineDirection,diff);
    }

    return NEW0 ConvexHull1<Real>(mNumVertices, projection, mEpsilon, true,  mQueryType);
}

template <typename Real>
Mathematics::ConvexHull2<Real>
	::ConvexHull2(const System::TChar* filename)
	:ConvexHull <Real>{ Real{ 0}, Math<Real>::GetValue(0), false, QueryType::Real }, mVertices{ 0 }, mSVertices{}, mQuery{ 0 }
{
	auto loaded = Load(filename);
    MATHEMATICS_ASSERTION_0(loaded, "Cannot open file %s\n", filename);
	
}

template <typename Real>
bool Mathematics::ConvexHull2<Real>
	::Load(const System::TChar* filename)
{
	CoreTools::ReadFileManager inFile{ filename };
  
    ConvexHull<Real>::Load(inFile);

	DELETE0(mQuery);
	mSVertices.resize(0);
  
    mOwner = true;
	mVertices.resize(mNumVertices);
	mSVertices.resize(mNumVertices);

	inFile.Read(sizeof(Real), 2 * mNumVertices, &mVertices[0]);
    inFile.Read(sizeof(Real), 2*mNumVertices, &mSVertices[0]);
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
		mQuery = NEW0 Query2Filtered<Real>(mSVertices,mEpsilon);
        break;
    }
    }

    return true;
}

template <typename Real>
bool Mathematics::ConvexHull2<Real>
	::Save (const System::TChar* filename) const
{
	CoreTools::WriteFileManager outFile{ filename };

    ConvexHull<Real>::Save(outFile);

    outFile.Write(sizeof(Real), 2*mNumVertices, &mVertices[0]);
    outFile.Write(sizeof(Real), 2*mNumVertices, &mSVertices[0]);
    outFile.Write(sizeof(Real), 2, &mLineOrigin);
    outFile.Write(sizeof(Real), 2, &mLineDirection);

    return true;
}

template <typename Real>
bool Mathematics::ConvexHull2<Real>
	::Update(Edge*& hull, int i)
{
    // Locate an edge visible to the input point (if possible).
    Edge* visible = 0;
    Edge* current = hull;
    do
    {
        if (current->GetSign(i, mQuery) > 0)
        {
            visible = current;
            break;
        }

        current = current->E[1];
    }
    while (current != hull);

    if (!visible)
    {
        // The point is inside the current hull; nothing to do.
        return true;
    }

    // Remove the visible edges.
    Edge* adj0 = visible->E[0];
    MATHEMATICS_ASSERTION_0(adj0 != 0, "Expecting nonnull adjacent\n");
    if (!adj0)
    {
        return false;
    }

    Edge* adj1 = visible->E[1];
    MATHEMATICS_ASSERTION_0(adj1 != 0, "Expecting nonnull adjacent\n");
    if (!adj1)
    {
        return false;
    }

    visible->DeleteSelf();

    while (adj0->GetSign(i, mQuery) > 0)
    {
        hull = adj0;
        adj0 = adj0->E[0];
        MATHEMATICS_ASSERTION_0(adj0 != 0, "Expecting nonnull adjacent\n");
        if (!adj0)
        {
            return false;
        }

        adj0->E[1]->DeleteSelf();
    }

    while (adj1->GetSign(i,mQuery) > 0)
    {
        hull = adj1;
        adj1 = adj1->E[1];
        MATHEMATICS_ASSERTION_0(adj1 != 0, "Expecting nonnull adjacent\n");
        if (!adj1)
        {
            return false;
        }

        adj1->E[0]->DeleteSelf();
    }

    // Insert the new edges formed by the input point and the end points of
    // the polyline of invisible edges.
	Edge* edge0 = NEW0 Edge(adj0->V[1], i);
    Edge* edge1 = NEW0 Edge(i, adj1->V[0]);
    edge0->Insert(adj0, edge1);
    edge1->Insert(edge0, adj1);
    hull = edge0;

    return true;
}

// ConvexHull2::Edge

template <typename Real>
Mathematics::ConvexHull2<Real>::Edge
	::Edge(int v0, int v1)
	:Sign{ 0 }, Time{ -1 }
{
    V[0] = v0;
    V[1] = v1;
    E[0] = 0;
    E[1] = 0;
}

template <typename Real>
int Mathematics::ConvexHull2<Real>::Edge
	::GetSign(int i, const Query2<Real>* query)
{
    if (i != Time)
    {
        Time = i;
        Sign = query->ToLine(i, V[0], V[1]);
    }

    return Sign;
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge
	::Insert(Edge* adj0, Edge* adj1)
{
    adj0->E[1] = this;
    adj1->E[0] = this;
    E[0] = adj0;
    E[1] = adj1;
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge
	::DeleteSelf()
{
    if (E[0])
    {
        E[0]->E[1] = 0;
    }

    if (E[1])
    {
        E[1]->E[0] = 0;
    }

    Edge* tmpThis = this;
    DELETE0(tmpThis);
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge
	::DeleteAll()
{
    Edge* adj = E[1];
    while (adj && adj != this)
    {
        Edge* save = adj->E[1];
		DELETE0(adj);
        adj = save;
    }

    MATHEMATICS_ASSERTION_0(adj == this, "Unexpected condition\n");
    Edge* tmpThis = this;
	DELETE0(tmpThis);
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge
	::GetIndices(int& numIndices, int*& indices)
{
    // Count the number of edge vertices and allocate the index array.
    numIndices = 0;
    Edge* current = this;
    do
    {
        ++numIndices;
        current = current->E[1];
    }
    while (current != this);
    indices = NEW1<int>(numIndices);

    // Fill the index array.
    numIndices = 0;
    current = this;
    do
    {
        indices[numIndices] = current->V[0];
        ++numIndices;
        current = current->E[1];
    }
    while (current != this);
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_DETAIL_H