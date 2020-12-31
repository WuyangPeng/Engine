///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 16:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_IMPL_DETAIL_H

#include "StaticFindIntersectorCircle2Circle2Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Objects2D/Circle2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::StaticFindIntersectorCircle2Circle2Impl(const Circle2& lhsCircle, const Circle2& rhsCircle) noexcept
    : m_LhsCircle{ lhsCircle }, m_RhsCircle{ rhsCircle }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::GetLhsCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_LhsCircle;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::GetRhsCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_RhsCircle;
}

template <typename Real>
int Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::GetIntersectionCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_LhsCircle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorCircle2Circle2Impl<Real>::AddIntersection(const Vector2D& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point.emplace_back(point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_IMPL_DETAIL_H
