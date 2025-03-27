/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/22 09:44)

#ifndef MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_DETAIL_H

#include "Polygon2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector/Vector2Detail.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorSegment2Segment2Detail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Algebra::Polygon2<Real>::Polygon2(const VertexPoolSharedPtr& vertexPool, int numIndices, const IndicesType& indices, bool counterClockwise)
    : vertexPool{ vertexPool },
      vertices{},
      indices{ indices },
      counterClockwise{ counterClockwise }
{
    if (numIndices < 3 && vertexPool == nullptr && indices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Polygon2构造函数的输入无效。"))
    }

    for (auto i = 0; i < numIndices; ++i)
    {
        vertices.emplace(indices.at(i));
    }

    if (numIndices != boost::numeric_cast<int>(vertices.size()))
    {
        /// 至少遇到了一个重复的顶点，所以很简单。构造函数调用失败。
        THROW_EXCEPTION(SYSTEM_TEXT("Polygon2构造函数的输入存在重复顶点。"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Polygon2<Real>::IsValid() const noexcept
{
    if (3 <= vertices.size() && !indices.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Algebra::Polygon2<Real>::VertexPoolSharedPtr Mathematics::Algebra::Polygon2<Real>::GetVertexPool() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto result = vertexPool.lock();

    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("vertexPool已。"))
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Algebra::Polygon2<Real>::VerticesType Mathematics::Algebra::Polygon2<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Algebra::Polygon2<Real>::IndicesType Mathematics::Algebra::Polygon2<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indices;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Polygon2<Real>::CounterClockwise() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return counterClockwise;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Algebra::Polygon2<Real>::Vector2 Mathematics::Algebra::Polygon2<Real>::ComputeVertexAverage() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto vertexPoolSharedPtr = GetVertexPool();

    Vector2 average{};

    for (const auto index : vertices)
    {
        average += vertexPoolSharedPtr->at(index);
    }

    average /= boost::numeric_cast<Real>(vertices.size());

    return average;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Algebra::Polygon2<Real>::ComputePerimeterLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto vertexPoolSharedPtr = GetVertexPool();

    auto v0 = vertexPoolSharedPtr->at(indices.back());

    Real length{};

    for (const auto index : indices)
    {
        const auto& v1 = vertexPoolSharedPtr->at(index);
        length += Length(v1 - v0);
        v0 = v1;
    }

    return length;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Algebra::Polygon2<Real>::ComputeArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto vertexPoolSharedPtr = GetVertexPool();

    Real area{};

    const auto numIndices = indices.size();
    auto v0 = vertexPoolSharedPtr->at(indices.at(numIndices - 2));
    auto v1 = vertexPoolSharedPtr->at(indices.at(numIndices - 1));
    for (const auto index : indices)
    {
        const auto& v2 = vertexPoolSharedPtr->at(index);
        area += v1[0] * (v2[1] - v0[1]);
        v0 = v1;
        v1 = v2;
    }
    area *= MathType::GetRational(1, 2);

    return MathType::FAbs(area);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Polygon2<Real>::IsSimple() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 保证索引的数量至少为3。
    if (indices.size() == 3u)
    {
        /// 多边形是一个三角形。
        return true;
    }

    return IsSimpleInternal();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Polygon2<Real>::IsConvex() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 保证索引的数量至少为3。
    if (indices.size() == 3u)
    {
        /// 多边形是一个三角形。
        return true;
    }

    return IsSimpleInternal() && IsConvexInternal();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Polygon2<Real>::IsSimpleInternal() const
{
    const auto vertexPoolSharedPtr = GetVertexPool();

    const auto numIndices = boost::numeric_cast<int>(indices.size());
    for (auto i0 = 0; i0 < numIndices; ++i0)
    {
        const auto i0Plus1 = (i0 + 1) % numIndices;
        const Segment2 segment0{ vertexPoolSharedPtr->at(indices.at(i0)),
                                 vertexPoolSharedPtr->at(indices.at(i0Plus1)) };

        const auto i1Min = (i0 + 2) % numIndices;
        const auto i1Max = (i0 - 2 + numIndices) % numIndices;
        for (auto i1 = i1Min; i1 <= i1Max; ++i1)
        {
            const auto i1Plus1 = (i1 + 1) % numIndices;
            const Segment2 segment1{ vertexPoolSharedPtr->at(indices.at(i1)),
                                     vertexPoolSharedPtr->at(indices.at(i1Plus1)) };

            if (const StaticTestIntersector query{ segment0, segment1 };
                query.IsIntersection())
            {
                return false;
            }
        }
    }
    return true;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Polygon2<Real>::IsConvexInternal() const
{
    const auto vertexPoolSharedPtr = GetVertexPool();

    const auto sign = counterClockwise ? MathType::GetValue(1) : MathType::GetValue(-1);
    const auto numIndices = boost::numeric_cast<int>(indices.size());
    for (auto index = 0; index < numIndices; ++index)
    {
        const auto indexPrev = (index + numIndices - 1) % numIndices;
        const auto indexNext = (index + 1) % numIndices;
        const auto& vertexPrev = vertexPoolSharedPtr->at(indices.at(indexPrev));
        const auto& vertexCurr = vertexPoolSharedPtr->at(indices.at(index));
        const auto& vertexNext = vertexPoolSharedPtr->at(indices.at(indexNext));
        const auto edge0 = vertexCurr - vertexPrev;
        const auto edge1 = vertexNext - vertexCurr;
        const auto test = sign * DotPerp(edge0, edge1);
        if (test < Real{})
        {
            return false;
        }
    }
    return true;
}

#endif  // MATHEMATICS_OBJECTS_2D_POLYGON2_DETAIL_H
