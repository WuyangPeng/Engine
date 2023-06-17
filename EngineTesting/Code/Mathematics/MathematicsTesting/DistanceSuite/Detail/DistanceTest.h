///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:30)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_H

#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceTest : public DistanceBase<Real, Vector>
    {
    public:
        using ClassType = DistanceTest<Real, Vector>;
        using ParentType = DistanceBase<Real, Vector>;
        using DistanceResult = DistanceResult<Real, Vector>;

    public:
        DistanceTest(const Vector& lhs, const Vector& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector GetLhs() const noexcept;
        NODISCARD Vector GetRhs() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;
        NODISCARD DistanceResult GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const override;

    private:
        Vector lhs;
        Vector rhs;
    };
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_H