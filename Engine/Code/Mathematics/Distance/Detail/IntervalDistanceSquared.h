///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:43)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H

#include "IntervalDistance.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class IntervalDistanceSquared : public IntervalDistanceBase<Real, Vector>
    {
    public:
        using ClassType = IntervalDistanceSquared<Real, Vector>;
        using ParentType = IntervalDistanceBase<Real, Vector>;
        using DistanceBase = DistanceBase<Real, Vector>;
        using DistanceResult = DistanceResult<Real, Vector>;

    public:
        IntervalDistanceSquared(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD DistanceResult Get(Real t) const final;
        NODISCARD Real GetDerivative(Real t) const final;
    };
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H
