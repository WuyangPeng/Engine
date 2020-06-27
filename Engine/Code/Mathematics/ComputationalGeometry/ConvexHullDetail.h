// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:55)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_DETAIL_H

#include "ConvexHull.h"
#include "CoreTools/Helper/MemoryMacro.h"

template <typename Real>
Mathematics::ConvexHull<Real>
	::ConvexHull(int numVertices, Real epsilon, bool owner, QueryType queryType)
	:mQueryType{ queryType }, mNumVertices{ numVertices }, mDimension{ 0 }, mNumSimplices{ 0 }, mIndices{ 0 }, mEpsilon{ epsilon }, mOwner{ owner }
{
    MATHEMATICS_ASSERTION_0(mNumVertices > 0 && mEpsilon >= Math<Real>::sm_Zero, "Invalid inputs\n");
}

template <typename Real>
Mathematics::ConvexHull<Real>
	::~ConvexHull()
{
    DELETE1(mIndices);
}

template <typename Real>
int Mathematics::ConvexHull<Real>
	::GetQueryType() const
{
    return mQueryType;
}

template <typename Real>
int Mathematics::ConvexHull<Real>
	::GetNumVertices() const
{
    return mNumVertices;
}

template <typename Real>
Real Mathematics::ConvexHull<Real>
	::GetEpsilon() const
{
    return mEpsilon;
}

template <typename Real>
bool Mathematics::ConvexHull<Real>
	::GetOwner() const
{
    return mOwner;
}

template <typename Real>
int Mathematics::ConvexHull<Real>
	::GetDimension() const
{
    return mDimension;
}

template <typename Real>
int Mathematics::ConvexHull<Real>
	::GetNumSimplices() const
{
    return mNumSimplices;
}

template <typename Real>
const int* Mathematics::ConvexHull<Real>
	::GetIndices() const
{
    return mIndices;
}

template <typename Real>
bool Mathematics::ConvexHull<Real>
	::Load(CoreTools::ReadFileManager& inFile)
{
    DELETE1(mIndices);

    // Fixed-size members.
    int type;
    inFile.Read(sizeof(int), &type);
	mQueryType = (QueryType)type;

    inFile.Read(sizeof(int), &mNumVertices);
    inFile.Read(sizeof(int), &mDimension);
    inFile.Read(sizeof(int), &mNumSimplices);
    inFile.Read(sizeof(Real), &mEpsilon);

    // Variable-size members.
    int numIndices;
    inFile.Read(sizeof(int), &numIndices);
    if (1 <= mDimension && mDimension <= 3)
    {
        MATHEMATICS_ASSERTION_0(numIndices == (mDimension+1)*mNumSimplices,"Inconsistent index count\n");
        mIndices = NEW1<int>(numIndices);
        inFile.Read(sizeof(int), numIndices, mIndices);
        return true;
    }

    mIndices = 0;
    return mDimension == 0;
}

template <typename Real>
bool Mathematics::ConvexHull<Real>	
	::Save(CoreTools::WriteFileManager& outFile) const
{
    // Fixed-size members.
    int type = (int)mQueryType;
    outFile.Write(sizeof(int), &type);

    outFile.Write(sizeof(int), &mNumVertices);
    outFile.Write(sizeof(int), &mDimension);
    outFile.Write(sizeof(int), &mNumSimplices);
    outFile.Write(sizeof(Real), &mEpsilon);

    // The member mOwner is not streamed because on a Load call, this
    // object will allocate the vertices and own this memory.

    // Variable-size members.
    int numIndices;
    if (1 <= mDimension && mDimension <= 3)
    {
        numIndices = (mDimension+1)*mNumSimplices;
        outFile.Write(sizeof(int), &numIndices);
        outFile.Write(sizeof(int), numIndices, mIndices);
        return true;
    }

    numIndices = 0;
    outFile.Write(sizeof(int), &numIndices);
    return mDimension == 0;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_DETAIL_H