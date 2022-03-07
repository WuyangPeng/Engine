///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 11:02)
///
#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_DETAIL_H

#include "Polygon2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Polygon2<Real>::Polygon2(const VerticesType& vertices)
    : vertices{ vertices }
{
    if (vertices.size() <= minSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数量不足于构建Polygon2。"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Polygon2<Real>::IsValid() const noexcept
{
    if (minSize <= vertices.size())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polygon2<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(vertices.size());
}

template <typename Real>
const typename Mathematics::Polygon2<Real>::VerticesType& Mathematics::Polygon2<Real>::GetVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices;
}

template <typename Real>
const Mathematics::Vector2<Real>& Mathematics::Polygon2<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices.at(index);
}

template <typename Real>
void Mathematics::Polygon2<Real>::SetVertex(int index, const Vector2& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    vertices.at(index) = vertex;
}

template <typename Real>
typename Mathematics::Polygon2<Real>::Vector2 Mathematics::Polygon2<Real>::ComputeVertexAverage() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector2 average{};
    for (const auto& vertex : vertices)
    {
        average += vertex;
    }
    average /= static_cast<Real>(vertices.size());

    return average;
}

template <typename Real>
Real Mathematics::Polygon2<Real>::ComputePerimeterLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto numVertices = vertices.size();
    const auto last = vertices.size() - 1;

    auto perimeterLength = Vector2Tools::GetLength(vertices.at(0) - vertices.at(last));
    for (auto i = 1u; i < numVertices; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        auto edge = vertices[i] - vertices[i - 1];

#include STSTEM_WARNING_POP

        perimeterLength += Vector2Tools::GetLength(edge);
    }

    return perimeterLength;
}

template <typename Real>
Real Mathematics::Polygon2<Real>::ComputeArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto last = vertices.size() - 1;
    auto area = vertices.at(0).GetX() * (vertices.at(1).GetY() - vertices.at(last).GetY()) +
                vertices.at(last).GetX() * (vertices.at(0).GetY() - vertices.at(last - 1).GetY());

    for (auto i = 1u; i < last; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        const auto next = i + 1;
        const auto previous = i - 1;

        area += vertices[i].GetX() * (vertices[next].GetY() - vertices[previous].GetY());

#include STSTEM_WARNING_POP
    }

    area *= Math::GetRational(1, 2);

    return area;
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_DETAIL_H
