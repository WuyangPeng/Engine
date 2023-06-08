///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:43)

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
