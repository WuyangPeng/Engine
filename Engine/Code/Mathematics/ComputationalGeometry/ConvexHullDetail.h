///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/05 14:39)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_DETAIL_H

#include "ConvexHull.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::ConvexHull<Real>::ConvexHull(int numVertices, Real epsilon, QueryType queryType)
    : queryType{ queryType }, numVertices{ numVertices }, dimension{ 0 }, numSimplices{ 0 }, indices{}, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_0(0 < numVertices && Math<Real>::GetValue(0) <= epsilon, "无效输入\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConvexHull<Real>::IsValid() const noexcept
{
    if (0 < numVertices && Math<Real>::GetValue(0) <= epsilon)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::ConvexHull<Real>::GetQueryType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return queryType;
}

template <typename Real>
int32_t Mathematics::ConvexHull<Real>::GetNumVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numVertices;
}

template <typename Real>
Real Mathematics::ConvexHull<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename Real>
int32_t Mathematics::ConvexHull<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}

template <typename Real>
int32_t Mathematics::ConvexHull<Real>::GetNumSimplices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numSimplices;
}

template <typename Real>
typename Mathematics::ConvexHull<Real>::IndicesType Mathematics::ConvexHull<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indices;
}

template <typename Real>
bool Mathematics::ConvexHull<Real>::Load(CoreTools::ReadFileManager& inFile)
{
    indices.clear();

    inFile.Read(sizeof(QueryType), &queryType);
    inFile.Read(sizeof(int32_t), &numVertices);
    inFile.Read(sizeof(int32_t), &dimension);
    inFile.Read(sizeof(int32_t), &numSimplices);
    inFile.Read(sizeof(Real), &epsilon);

    int32_t numIndices{};
    inFile.Read(sizeof(int32_t), &numIndices);
    if (1 <= dimension && dimension <= 3)
    {
        MATHEMATICS_ASSERTION_0(numIndices == (dimension + 1) * numSimplices, "不一致的索引计数。\n");
        indices.resize(numIndices);
        inFile.Read(sizeof(int32_t), numIndices, indices.data());

        return true;
    }

    indices.clear();
    return dimension == 0;
}

template <typename Real>
bool Mathematics::ConvexHull<Real>::Save(CoreTools::WriteFileManager& outFile) const
{
    outFile.Write(sizeof(QueryType), &queryType);
    outFile.Write(sizeof(int32_t), &numVertices);
    outFile.Write(sizeof(int32_t), &dimension);
    outFile.Write(sizeof(int32_t), &numSimplices);
    outFile.Write(sizeof(Real), &epsilon);

    int32_t numIndices{};
    if (1 <= dimension && dimension <= 3)
    {
        numIndices = (dimension + 1) * numSimplices;
        outFile.Write(sizeof(int32_t), &numIndices);
        outFile.Write(sizeof(int32_t), indices.size(), indices.data());
        return true;
    }

    numIndices = 0;
    outFile.Write(sizeof(int32_t), &numIndices);

    return dimension == 0;
}

template <typename Real>
void Mathematics::ConvexHull<Real>::SetDimension(int32_t newDimension) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    dimension = newDimension;
}

template <typename Real>
void Mathematics::ConvexHull<Real>::SetNumSimplices(int32_t newNumSimplices) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numSimplices = newNumSimplices;
}

template <typename Real>
void Mathematics::ConvexHull<Real>::AddIndex(int32_t index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    indices.emplace_back(index);
}

template <typename Real>
void Mathematics::ConvexHull<Real>::SetIndex(IndicesType indicesType)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    indices = indicesType;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_DETAIL_H