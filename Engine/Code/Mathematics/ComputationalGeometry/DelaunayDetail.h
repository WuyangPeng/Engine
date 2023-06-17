///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:35)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_DETAIL_H

#include "Delaunay.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Delaunay<Real>::Delaunay(int numVertices, Real epsilon, QueryType queryType)
    : queryType{ queryType }, numVertices{ numVertices }, dimension{ 0 }, numSimplices{ 0 }, indices{}, adjacencies{}, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_0(0 < numVertices && Math<Real>::GetValue(0) <= epsilon, "无效输入\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Delaunay<Real>::IsValid() const noexcept
{
    if (0 < numVertices && Math<Real>::GetValue(0) <= epsilon)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Delaunay<Real>::GetQueryType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return queryType;
}

template <typename Real>
int Mathematics::Delaunay<Real>::GetNumVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numVertices;
}

template <typename Real>
Real Mathematics::Delaunay<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename Real>
int Mathematics::Delaunay<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}

template <typename Real>
int Mathematics::Delaunay<Real>::GetNumSimplices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numSimplices;
}

template <typename Real>
typename Mathematics::Delaunay<Real>::IndicesType Mathematics::Delaunay<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indices;
}

template <typename Real>
int32_t Mathematics::Delaunay<Real>::GetIndex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indices.at(index);
}

template <typename Real>
int32_t Mathematics::Delaunay<Real>::GetAdjacency(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return adjacencies.at(index);
}

template <typename Real>
typename Mathematics::Delaunay<Real>::IndicesType Mathematics::Delaunay<Real>::GetAdjacencies() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return adjacencies;
}

template <typename Real>
bool Mathematics::Delaunay<Real>::Load(CoreTools::ReadFileManager& inFile)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    indices.clear();
    adjacencies.clear();

    inFile.Read(sizeof(QueryType), &queryType);
    inFile.Read(sizeof(int32_t), &numVertices);
    inFile.Read(sizeof(int32_t), &dimension);
    inFile.Read(sizeof(int32_t), &numSimplices);
    inFile.Read(sizeof(Real), &epsilon);

    auto numIndices = 0;
    inFile.Read(sizeof(int32_t), &numIndices);
    if (1 <= dimension && dimension <= 3)
    {
        MATHEMATICS_ASSERTION_0(numIndices == (dimension + 1) * numSimplices, "不一致的索引计数。\n");

        indices.resize(numIndices);
        adjacencies.resize(numIndices);
        inFile.Read(sizeof(int32_t), numIndices, indices.data());
        inFile.Read(sizeof(int32_t), numIndices, adjacencies.data());

        return true;
    }

    indices.clear();
    adjacencies.clear();

    return dimension == 0;
}

template <typename Real>
bool Mathematics::Delaunay<Real>::Save(CoreTools::WriteFileManager& outFile) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    outFile.Write(sizeof(QueryType), &queryType);

    outFile.Write(sizeof(int32_t), &numVertices);
    outFile.Write(sizeof(int32_t), &dimension);
    outFile.Write(sizeof(int32_t), &numSimplices);
    outFile.Write(sizeof(Real), &epsilon);

    if (1 <= dimension && dimension <= 3)
    {
        const auto numIndices = (dimension + 1) * numSimplices;
        outFile.Write(sizeof(int32_t), &numIndices);
        outFile.Write(sizeof(int32_t), numIndices, indices.data());
        outFile.Write(sizeof(int32_t), numIndices, adjacencies.data());

        return true;
    }

    constexpr auto numIndices = 0;
    outFile.Write(sizeof(int32_t), &numIndices);

    return dimension == 0;
}

template <typename Real>
void Mathematics::Delaunay<Real>::SetDimension(int32_t newDimension) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    dimension = newDimension;
}

template <typename Real>
void Mathematics::Delaunay<Real>::SetNumSimplices(int32_t newNumSimplices) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numSimplices = newNumSimplices;
}

template <typename Real>
void Mathematics::Delaunay<Real>::AddIndex(int32_t index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    indices.emplace_back(index);
}

template <typename Real>
void Mathematics::Delaunay<Real>::SetIndex(IndicesType indicesType)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    indices = indicesType;
}

template <typename Real>
void Mathematics::Delaunay<Real>::SetAdjacencies(IndicesType indicesType)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    adjacencies = indicesType;
}

template <typename Real>
void Mathematics::Delaunay<Real>::AddAdjacency(int32_t index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    adjacencies.emplace_back(index);
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_DETAIL_H
