// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 15:05)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_DETAIL_H

#include "Delaunay.h"
#include "CoreTools/Helper/MemoryMacro.h"

template <typename Real>
Mathematics::Delaunay<Real>
	::Delaunay(int numVertices, Real epsilon, bool owner, QueryType queryType)
	:mQueryType{ queryType }, mNumVertices{ numVertices }, mDimension{ 0 }, mNumSimplices{ 0 }, mIndices{ 0 }, mAdjacencies{ 0 }, mEpsilon{ epsilon }, mOwner{ owner }
{
    MATHEMATICS_ASSERTION_0(mNumVertices >= 0 && mEpsilon >= Real{}, "Invalid inputs\n");
}

template <typename Real>
Mathematics::Delaunay<Real>
	::~Delaunay()
{
    DELETE1(mIndices);
    DELETE1(mAdjacencies);
}

template <typename Real>
Mathematics::QueryType Mathematics::Delaunay<Real>
	::GetQueryType() const
{
    return mQueryType;
}

template <typename Real>
int Mathematics::Delaunay<Real>
	::GetNumVertices() const
{
    return mNumVertices;
}

template <typename Real>
Real Mathematics::Delaunay<Real>
	::GetEpsilon() const
{
    return mEpsilon;
}

template <typename Real>
bool Mathematics::Delaunay<Real>
	::GetOwner() const
{
    return mOwner;
}

template <typename Real>
int Mathematics::Delaunay<Real>
	::GetDimension() const
{
    return mDimension;
}

template <typename Real>
int Mathematics::Delaunay<Real>
	::GetNumSimplices() const
{
    return mNumSimplices;
}

template <typename Real>
const int* Mathematics::Delaunay<Real>
	::GetIndices() const
{
    return mIndices;
}

template <typename Real>
const int* Mathematics::Delaunay<Real>
	::GetAdjacencies() const
{
    return mAdjacencies;
}

template <typename Real>
bool Mathematics::Delaunay<Real>
	::Load(CoreTools::ReadFileManager& inFile)
{
    DELETE1(mIndices);
    DELETE1(mAdjacencies);

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
		mAdjacencies = NEW1<int>(numIndices);
        inFile.Read(sizeof(int), numIndices, mIndices);
        inFile.Read(sizeof(int), numIndices, mAdjacencies);
        return true;
    }

    mIndices = 0;
    mAdjacencies = 0;
    return mDimension == 0;
}

template <typename Real>
bool Mathematics::Delaunay<Real>
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
        outFile.Write(sizeof(int), numIndices, mAdjacencies);
        return true;
    }

    numIndices = 0;
    outFile.Write(sizeof(int), &numIndices);
    return mDimension == 0;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_DETAIL_H
