///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/07 15:21)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H

#include "IntervalDistanceBase.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE IntervalDistance : public IntervalDistanceBase<Real, Vector>
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
        [[nodiscard]] const DistanceResult Get(Real t) const final;
        [[nodiscard]] Real GetDerivative(Real t) const final;
    };
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H
