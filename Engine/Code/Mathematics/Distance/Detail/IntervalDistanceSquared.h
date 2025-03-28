///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:42)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H

#include "IntervalDistance.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class IntervalDistanceSquared final : public IntervalDistanceBase<Real, Vector>
    {
    public:
        using ClassType = IntervalDistanceSquared<Real, Vector>;
        using ParentType = IntervalDistanceBase<Real, Vector>;

        using DistanceBaseType = DistanceBase<Real, Vector>;
        using DistanceResultType = DistanceResult<Real, Vector>;

    public:
        IntervalDistanceSquared(const DistanceBaseType& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD DistanceResultType Get(Real t) const final;
        NODISCARD Real GetDerivative(Real t) const final;
    };
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H
