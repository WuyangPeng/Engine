///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 14:35)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_IMPL_DETAIL_H

#include "Polygon2Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Polygon2Impl<Real>::Polygon2Impl(const VerticesType& vertices)
    : m_Vertices{}
{
    if (vertices.size() <= sm_MinSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数量不足于构建Polygon2。"s));
    }

    m_Vertices = vertices;

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polygon2Impl<Real>::IsValid() const noexcept
{
    if (sm_MinSize <= m_Vertices.size())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polygon2Impl<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Vertices.size());
}

template <typename Real>
const typename Mathematics::Polygon2Impl<Real>::VerticesType& Mathematics::Polygon2Impl<Real>::GetVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Vertices;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::Polygon2Impl<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Vertices.at(index);
}

template <typename Real>
void Mathematics::Polygon2Impl<Real>::SetVertex(int index, const Vector2D& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Vertices.at(index) = vertex;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Polygon2Impl<Real>::ComputeVertexAverage() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector2D average{};
    for (const auto& vertex : m_Vertices)
    {
        average += vertex;
    }
    average /= static_cast<Real>(m_Vertices.size());

    return average;
}

template <typename Real>
Real Mathematics::Polygon2Impl<Real>::ComputePerimeterLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto numVertices = m_Vertices.size();
    const auto last = m_Vertices.size() - 1;

    auto perimeterLength = Vector2DTools::VectorMagnitude(m_Vertices.at(0) - m_Vertices.at(last));
    for (auto i = 1u; i < numVertices; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        auto edge = m_Vertices[i] - m_Vertices[i - 1];
#include STSTEM_WARNING_POP

        perimeterLength += Vector2DTools::VectorMagnitude(edge);
    }

    return perimeterLength;
}

template <typename Real>
Real Mathematics::Polygon2Impl<Real>::ComputeArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto last = m_Vertices.size() - 1;
    auto area = m_Vertices.at(0).GetX() * (m_Vertices.at(1).GetY() - m_Vertices.at(last).GetY()) +
                m_Vertices.at(last).GetX() * (m_Vertices.at(0).GetY() - m_Vertices.at(last - 1).GetY());

    for (size_t i{ 1u }; i < last; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        area += m_Vertices[i].GetX() * (m_Vertices[i + 1].GetY() - m_Vertices[i - 1].GetY());
#include STSTEM_WARNING_POP
    }

    area *= Math::GetRational(1, 2);

    return area;
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_IMPL_DETAIL_H
