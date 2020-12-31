///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 14:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_IMPL_DETAIL_H

#include "StaticFindIntersectorArc2Arc2Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::StaticFindIntersectorArc2Arc2Impl(const Arc2& lhsArc, const Arc2& rhsArc) noexcept
    : m_LhsArc{ lhsArc }, m_RhsArc{ rhsArc }, m_Point{}, m_IntersectionArc{ lhsArc }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::GetLhsArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_LhsArc;
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::GetRhsArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_RhsArc;
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point.at(index);
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::GetIntersectionArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntersectionArc;
}
template <typename Real>
void Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::SetIntersection(const Arc2& intersectionArc) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_IntersectionArc = intersectionArc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::SetIntersection(const Intersection& points)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Point = points;
}

template <typename Real>
void Mathematics::StaticFindIntersectorArc2Arc2Impl<Real>::AddIntersection(const Vector2D& point)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Point.emplace_back(point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_IMPL_DETAIL_H
