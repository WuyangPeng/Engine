///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 15:26)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_DETAIL_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_DETAIL_H

#include "IntervalDistanceDetail.h"
#include "IntervalDistanceSquared.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::IntervalDistanceSquared<Real, Vector>::IntervalDistanceSquared(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity)
    : ParentType{ distance, tMin, tMax, lhsVelocity, rhsVelocity }
{
    ParentType::Solve();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceSquared<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

// private
template <typename Real, typename Vector>
const typename Mathematics::IntervalDistanceSquared<Real, Vector>::DistanceResult Mathematics::IntervalDistanceSquared<Real, Vector>::Get(Real t) const
{
    return ParentType::GetDistanceResultSquared(t);
}

template <typename Real, typename Vector>
Real Mathematics::IntervalDistanceSquared<Real, Vector>::GetDerivative(Real t) const
{
    return ParentType::GetDerivativeDistanceResultSquared(t);
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_DETAIL_H
