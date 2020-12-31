///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 15:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_IMPL_DETAIL_H

#include "StaticFindIntersector1Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersector1Impl<Real>::StaticFindIntersector1Impl(const IntersectionsType& intersections)
    : m_Intersections{ intersections }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersector1Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersector1Impl<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return !m_Intersections.empty();
}

template <typename Real>
int Mathematics::StaticFindIntersector1Impl<Real>::GetNumIntersections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Intersections.size());
}

template <typename Real>
Real Mathematics::StaticFindIntersector1Impl<Real>::GetIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Intersections.at(index);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_IMPL_DETAIL_H
