///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 18:20)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_DETAIL_H

#include "DynamicFindIntersector1Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersector1Impl<Real>::DynamicFindIntersector1Impl(Real firstTime, Real lastTime, const IntersectionsType& intersections)
    : m_FirstTime{ firstTime }, m_LastTime{ lastTime }, m_Intersections{ intersections }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DynamicFindIntersector1Impl<Real>::DynamicFindIntersector1Impl() noexcept
    : m_FirstTime{}, m_LastTime{}, m_Intersections{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersector1Impl<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_FirstTime && m_FirstTime <= m_LastTime)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersector1Impl<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return !m_Intersections.empty();
}

template <typename Real>
int Mathematics::DynamicFindIntersector1Impl<Real>::GetNumIntersections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Intersections.size());
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1Impl<Real>::GetIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Intersections.at(index);
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1Impl<Real>::GetFirstTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsIntersection())
    {
        return m_FirstTime;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("区间不相交\n"s));
    }
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1Impl<Real>::GetLastTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsIntersection())
    {
        return m_LastTime;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("区间不相交\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_DETAIL_H
