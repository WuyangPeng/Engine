///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 15:43)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_IMPL_DETAIL_H

#include "StaticFindIntersectorArc2Circle2Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::StaticFindIntersectorArc2Circle2Impl(const Arc2& arc, const Circle2& circle) noexcept
    : m_Arc{ arc }, m_Circle{ circle }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::GetArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Arc;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Circle;
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::Arc2 Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::GetIntersectionArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Arc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorArc2Circle2Impl<Real>::AddIntersection(const Vector2D& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point.emplace_back(point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_IMPL_DETAIL_H
