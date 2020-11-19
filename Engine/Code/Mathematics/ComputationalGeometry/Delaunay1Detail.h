// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:56)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_DETAIL_H

#include "Delaunay1.h"
#include "CoreTools/Helper/MemoryMacro.h"


template <typename Real>
Mathematics::Delaunay1<Real>
	::Delaunay1(int numVertices, Real* vertices, Real epsilon,bool owner, QueryType queryType)
	:Delaunay<Real>{ numVertices, epsilon, owner, queryType }, mVertices{ vertices }
{
    std::vector<SortedVertex> sorted(mNumVertices);
    int i;
    for (i = 0; i < mNumVertices; ++i)
    {
        sorted[i].Value = mVertices[i];
        sorted[i].Index = i;
    }
    std::sort(sorted.begin(), sorted.end());

	auto range = sorted[mNumVertices - 1].Value - sorted[0].Value;
    if (range >= mEpsilon)
    {
        mDimension = 1;
        mNumSimplices = mNumVertices - 1;
        mIndices = NEW1<int>(2*mNumSimplices);
        for (i = 0; i < mNumSimplices; ++i)
        {
            mIndices[2*i] = sorted[i].Index;
            mIndices[2*i + 1] = sorted[i + 1].Index;
        }

        mAdjacencies = NEW1<int>(2*mNumSimplices);
        for (i = 0; i < mNumSimplices; ++i)
        {
            mAdjacencies[2*i] = i - 1;
            mAdjacencies[2*i + 1] = i + 1;
        }
        mAdjacencies[2*mNumSimplices - 1] = -1;
    }
}

template <typename Real>
Mathematics::Delaunay1<Real>
	::~Delaunay1()
{
    if (mOwner)
    {
        DELETE1(mVertices);
    }
}

template <typename Real>
const Real* Mathematics::Delaunay1<Real>
	::GetVertices() const
{
    return mVertices;
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::GetHull(int hull[2])
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return false;
    }

    hull[0] = mIndices[0];
    hull[1] = mIndices[2*mNumSimplices - 1];
    return true;
}

template <typename Real>
int Mathematics::Delaunay1<Real>
	::GetContainingSegment(const Real p) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return -1;
    }

    if (p < mVertices[mIndices[0]])
    {
        return -1;
    }

    if (p > mVertices[mIndices[2*mNumSimplices - 1]])
    {
        return -1;
    }

    int i;
    for (i = 0; i < mNumSimplices; ++i)
    {
        if (p <= mVertices[mIndices[2*i + 1]])
        {
            break;
        }
    }

    MATHEMATICS_ASSERTION_0(i < mNumSimplices, "Input not in hull\n");
    return i;
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::GetVertexSet(int i, Real vertices[2]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        vertices[0] = mVertices[mIndices[2*i]];
        vertices[1] = mVertices[mIndices[2*i + 1]];
        return true;
    }
    return false;
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::GetIndexSet(int i, int indices[2]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        indices[0] = mIndices[2*i];
        indices[1] = mIndices[2*i + 1];
        return true;
    }
    return false;
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::GetAdjacentSet(int i, int adjacencies[2]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
        adjacencies[0] = mAdjacencies[2*i];
        adjacencies[1] = mAdjacencies[2*i + 1];
        return true;
    }
    return false;
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::GetBarycentricSet(int i, const Real p, Real bary[2]) const
{
    MATHEMATICS_ASSERTION_0(mDimension == 1, "The dimension must be 1\n");
    if (mDimension != 1)
    {
        return false;
    }

    if (0 <= i && i < mNumSimplices)
    {
		auto v0 = mVertices[mIndices[2*i]];
		auto v1 = mVertices[mIndices[2*i + 1]];
		auto denom = v1 - v0;
        if (denom > mEpsilon)
        {
            bary[0] = (v1 - p)/denom;
        }
        else
        {
            bary[0] = Math::GetValue(1);
        }

        bary[1] = Math::GetValue(1) - bary[0];
        return true;
    }
    return false;
}

template <typename Real>
Mathematics::Delaunay1<Real>
	::Delaunay1(const System::TChar* filename)
	:Delaunay<Real>{ 0, Math<Real>::GetValue(0), false, QueryType::Real }
{
    mVertices = 0;
	auto loaded = Load(filename);
    MATHEMATICS_ASSERTION_0(loaded, "Cannot open file %s\n", filename);
	
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::Load(const System::TChar* filename)
{
	CoreTools::ReadFileManager inFile{ filename };
 
    Delaunay<Real>::Load(inFile);

    if (mOwner)
    {
        DELETE1(mVertices);
    }

    mOwner = true;
    mVertices = NEW1<Real>(mNumVertices);
    inFile.Read(sizeof(Real), mNumVertices, mVertices);
 
    return true;
}

template <typename Real>
bool Mathematics::Delaunay1<Real>
	::Save(const System::TChar* filename) const
{
	CoreTools::WriteFileManager outFile{ filename };

    Delaunay<Real>::Save(outFile);

    outFile.Write(sizeof(Real), mNumVertices, mVertices);
	 
    return true;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_DETAIL_H