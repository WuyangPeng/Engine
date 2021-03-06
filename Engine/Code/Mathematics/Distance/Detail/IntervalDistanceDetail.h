///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 15:25)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_DETAIL_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_DETAIL_H

#include "IntervalDistance.h"
#include "IntervalDistanceBaseDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::IntervalDistance<Real, Vector>::IntervalDistance(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity)
    : ParentType{ distance, tMin, tMax, lhsVelocity, rhsVelocity }
{
    ParentType::Solve();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::IntervalDistance<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
const typename Mathematics::IntervalDistance<Real, Vector>::DistanceResult Mathematics::IntervalDistance<Real, Vector>::Get(Real t) const
{
    return ParentType::GetDistanceResult(t);
}

template <typename Real, typename Vector>
Real Mathematics::IntervalDistance<Real, Vector>::GetDerivative(Real t) const
{
    return ParentType::GetDerivativeDistanceResult(t);
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_DETAIL_H
