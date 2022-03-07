///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/20 16:33)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H

#include "IntervalDistanceBase.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class IntervalDistance : public IntervalDistanceBase<Real, Vector>
    {
    public:
        using ClassType = IntervalDistance<Real, Vector>;
        using ParentType = IntervalDistanceBase<Real, Vector>;
        using DistanceBase = DistanceBase<Real, Vector>;
        using DistanceResult = DistanceResult<Real, Vector>;

    public:
        IntervalDistance(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD DistanceResult Get(Real t) const final;
        NODISCARD Real GetDerivative(Real t) const final;
    };
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H
