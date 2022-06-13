///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 10:58)

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