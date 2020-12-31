///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/17 16:49)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_IMPL_DETAIL_H

#include "FindIntersectorTriangle2Triangle2Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::FindIntersectorTriangle2Triangle2Impl(const Triangle2& triangle0, const Triangle2& triangle1) noexcept
    : m_Triangle0{ triangle0 }, m_Triangle1{ triangle1 }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle0;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle1;
}

template <typename Real>
int Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point.at(index);
}

template <typename Real>
void Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::SetPoint(const Intersection& point)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Point = point;
}

template <typename Real>
void Mathematics::FindIntersectorTriangle2Triangle2Impl<Real>::AddPoint(const Vector2D& point)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Point.emplace_back(point);
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_IMPL_DETAIL_H