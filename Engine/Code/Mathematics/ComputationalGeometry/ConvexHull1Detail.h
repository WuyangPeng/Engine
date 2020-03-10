// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:45)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_DETAIL_H

#include "ConvexHull1.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "System/Helper/UnusedMacro.h"

template <typename Real>
Mathematics::ConvexHull1<Real>
	::ConvexHull1(int numVertices, Real* vertices, Real epsilon, bool owner, QueryType queryType)
	:ConvexHull<Real>{ numVertices, epsilon, owner, queryType }, mVertices{ vertices }
{
    MATHEMATICS_ASSERTION_0(mVertices != 0, "Must provide vertices\n");

    std::vector<SortedVertex> sortedArray(mNumVertices);
    int i;
    for (i = 0; i < mNumVertices; ++i)
    {
        sortedArray[i].Value = mVertices[i];
        sortedArray[i].Index = i;
    }
    std::sort(sortedArray.begin(), sortedArray.end());

    auto range = sortedArray[mNumVertices-1].Value - sortedArray[0].Value;
    if (range >= mEpsilon)
    {
        mDimension = 1;
        mNumSimplices = 2;
        mIndices = NEW1<int>(2);
        mIndices[0] = sortedArray[0].Index;
        mIndices[1] = sortedArray[mNumVertices-1].Index;
    }
}

template <typename Real>
Mathematics::ConvexHull1<Real>
	::~ConvexHull1()
{
    if (mOwner)
    {
        DELETE1(mVertices);
    }
}

template <typename Real>
const Real* Mathematics::ConvexHull1<Real>
	::GetVertices() const
{
    return mVertices;
}

template <typename Real>
Mathematics::ConvexHull1<Real>
	::ConvexHull1(const System::TChar* filename)
	:ConvexHull<Real>{ 0, Real{}, false, QueryType::Real }, mVertices{ 0 }
{
    bool loaded = Load(filename);
    MATHEMATICS_ASSERTION_0(loaded, "Failed to load file\n");
	SYSTEM_UNUSED_ARG(loaded);
}

template <typename Real>
bool Mathematics::ConvexHull1<Real>
	::Load(const System::TChar* filename)
{
	CoreTools::ReadFileManager inFile{ filename };

    ConvexHull<Real>::Load(inFile);

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
bool Mathematics::ConvexHull1<Real>
	::Save(const System::TChar* filename) const
{
	CoreTools::WriteFileManager outFile{ filename };
  
    ConvexHull<Real>::Save(outFile);
    outFile.Write(sizeof(Real), mNumVertices, mVertices);

    return true;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_DETAIL_H